/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : canfd_iobitmask.h
 * Version      : 1.00
 * Description  : IO bit mask file for canfd.
 *********************************************************************************************************************/

#ifndef CANFD_IOBITMASK_H
#define CANFD_IOBITMASK_H

/* =========================================================  NCFG  ========================================================== */
#define R_CANFD_CFDC_NCFG_NBRP_Pos      (0UL)          /*!< NBRP (Bit 0)                                            */
#define R_CANFD_CFDC_NCFG_NBRP_Msk      (0x3ffUL)      /*!< NBRP (Bitfield-Mask: 0x3ff)                             */
#define R_CANFD_CFDC_NCFG_NSJW_Pos      (11UL)         /*!< NSJW (Bit 10)                                           */
#define R_CANFD_CFDC_NCFG_NSJW_Msk      (0x1fc00UL)    /*!< NSJW (Bitfield-Mask: 0x7f)                              */
#define R_CANFD_CFDC_NCFG_NTSEG1_Pos    (16UL)         /*!< NTSEG1 (Bit 17)                                         */
#define R_CANFD_CFDC_NCFG_NTSEG1_Msk    (0x1fe0000UL)  /*!< NTSEG1 (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFDC_NCFG_NTSEG2_Pos    (24UL)         /*!< NTSEG2 (Bit 25)                                         */
#define R_CANFD_CFDC_NCFG_NTSEG2_Msk    (0xfe000000UL) /*!< NTSEG2 (Bitfield-Mask: 0x7f)                            */
/* ==========================================================  CTR  ========================================================== */
#define R_CANFD_CFDC_CTR_CHMDC_Pos      (0UL)          /*!< CHMDC (Bit 0)                                           */
#define R_CANFD_CFDC_CTR_CHMDC_Msk      (0x3UL)        /*!< CHMDC (Bitfield-Mask: 0x03)                             */
#define R_CANFD_CFDC_CTR_CSLPR_Pos      (2UL)          /*!< CSLPR (Bit 2)                                           */
#define R_CANFD_CFDC_CTR_CSLPR_Msk      (0x4UL)        /*!< CSLPR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_CTR_RTBO_Pos       (3UL)          /*!< RTBO (Bit 3)                                            */
#define R_CANFD_CFDC_CTR_RTBO_Msk       (0x8UL)        /*!< RTBO (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_BEIE_Pos       (8UL)          /*!< BEIE (Bit 8)                                            */
#define R_CANFD_CFDC_CTR_BEIE_Msk       (0x100UL)      /*!< BEIE (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_EWIE_Pos       (9UL)          /*!< EWIE (Bit 9)                                            */
#define R_CANFD_CFDC_CTR_EWIE_Msk       (0x200UL)      /*!< EWIE (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_EPIE_Pos       (10UL)         /*!< EPIE (Bit 10)                                           */
#define R_CANFD_CFDC_CTR_EPIE_Msk       (0x400UL)      /*!< EPIE (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_BOEIE_Pos      (11UL)         /*!< BOEIE (Bit 11)                                          */
#define R_CANFD_CFDC_CTR_BOEIE_Msk      (0x800UL)      /*!< BOEIE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_CTR_BORIE_Pos      (12UL)         /*!< BORIE (Bit 12)                                          */
#define R_CANFD_CFDC_CTR_BORIE_Msk      (0x1000UL)     /*!< BORIE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_CTR_OLIE_Pos       (13UL)         /*!< OLIE (Bit 13)                                           */
#define R_CANFD_CFDC_CTR_OLIE_Msk       (0x2000UL)     /*!< OLIE (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_BLIE_Pos       (14UL)         /*!< BLIE (Bit 14)                                           */
#define R_CANFD_CFDC_CTR_BLIE_Msk       (0x4000UL)     /*!< BLIE (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_ALIE_Pos       (15UL)         /*!< ALIE (Bit 15)                                           */
#define R_CANFD_CFDC_CTR_ALIE_Msk       (0x8000UL)     /*!< ALIE (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_TAIE_Pos       (16UL)         /*!< TAIE (Bit 16)                                           */
#define R_CANFD_CFDC_CTR_TAIE_Msk       (0x10000UL)    /*!< TAIE (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_EOCOIE_Pos     (17UL)         /*!< EOCOIE (Bit 17)                                         */
#define R_CANFD_CFDC_CTR_EOCOIE_Msk     (0x20000UL)    /*!< EOCOIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_SOCOIE_Pos     (18UL)         /*!< SOCOIE (Bit 18)                                         */
#define R_CANFD_CFDC_CTR_SOCOIE_Msk     (0x40000UL)    /*!< SOCOIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_TDCVFIE_Pos    (19UL)         /*!< TDCVFIE (Bit 19)                                        */
#define R_CANFD_CFDC_CTR_TDCVFIE_Msk    (0x80000UL)    /*!< TDCVFIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CTR_BOM_Pos        (21UL)         /*!< BOM (Bit 21)                                            */
#define R_CANFD_CFDC_CTR_BOM_Msk        (0x600000UL)   /*!< BOM (Bitfield-Mask: 0x03)                               */
#define R_CANFD_CFDC_CTR_ERRD_Pos       (23UL)         /*!< ERRD (Bit 23)                                           */
#define R_CANFD_CFDC_CTR_ERRD_Msk       (0x800000UL)   /*!< ERRD (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_CTME_Pos       (24UL)         /*!< CTME (Bit 24)                                           */
#define R_CANFD_CFDC_CTR_CTME_Msk       (0x1000000UL)  /*!< CTME (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_CTMS_Pos       (25UL)         /*!< CTMS (Bit 25)                                           */
#define R_CANFD_CFDC_CTR_CTMS_Msk       (0x6000000UL)  /*!< CTMS (Bitfield-Mask: 0x03)                              */
#define R_CANFD_CFDC_CTR_CRCT_Pos       (30UL)         /*!< CRCT (Bit 30)                                           */
#define R_CANFD_CFDC_CTR_CRCT_Msk       (0x40000000UL) /*!< CRCT (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_CTR_ROM_Pos        (31UL)         /*!< ROM (Bit 31)                                            */
#define R_CANFD_CFDC_CTR_ROM_Msk        (0x80000000UL) /*!< ROM (Bitfield-Mask: 0x01)                               */
/* ==========================================================  STS  ========================================================== */
#define R_CANFD_CFDC_STS_CRSTSTS_Pos    (0UL)          /*!< CRSTSTS (Bit 0)                                         */
#define R_CANFD_CFDC_STS_CRSTSTS_Msk    (0x1UL)        /*!< CRSTSTS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_STS_CHLTSTS_Pos    (1UL)          /*!< CHLTSTS (Bit 1)                                         */
#define R_CANFD_CFDC_STS_CHLTSTS_Msk    (0x2UL)        /*!< CHLTSTS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_STS_CSLPSTS_Pos    (2UL)          /*!< CSLPSTS (Bit 2)                                         */
#define R_CANFD_CFDC_STS_CSLPSTS_Msk    (0x4UL)        /*!< CSLPSTS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_STS_EPSTS_Pos      (3UL)          /*!< EPSTS (Bit 3)                                           */
#define R_CANFD_CFDC_STS_EPSTS_Msk      (0x8UL)        /*!< EPSTS (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_STS_BOSTS_Pos      (4UL)          /*!< BOSTS (Bit 4)                                           */
#define R_CANFD_CFDC_STS_BOSTS_Msk      (0x10UL)       /*!< BOSTS (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_STS_TRMSTS_Pos     (5UL)          /*!< TRMSTS (Bit 5)                                          */
#define R_CANFD_CFDC_STS_TRMSTS_Msk     (0x20UL)       /*!< TRMSTS (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_STS_RECSTS_Pos     (6UL)          /*!< RECSTS (Bit 6)                                          */
#define R_CANFD_CFDC_STS_RECSTS_Msk     (0x40UL)       /*!< RECSTS (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_STS_COMSTS_Pos     (7UL)          /*!< COMSTS (Bit 7)                                          */
#define R_CANFD_CFDC_STS_COMSTS_Msk     (0x80UL)       /*!< COMSTS (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_STS_ESIF_Pos       (8UL)          /*!< ESIF (Bit 8)                                            */
#define R_CANFD_CFDC_STS_ESIF_Msk       (0x100UL)      /*!< ESIF (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_STS_REC_Pos        (16UL)         /*!< REC (Bit 16)                                            */
#define R_CANFD_CFDC_STS_REC_Msk        (0xff0000UL)   /*!< REC (Bitfield-Mask: 0xff)                               */
#define R_CANFD_CFDC_STS_TEC_Pos        (24UL)         /*!< TEC (Bit 24)                                            */
#define R_CANFD_CFDC_STS_TEC_Msk        (0xff000000UL) /*!< TEC (Bitfield-Mask: 0xff)                               */
/* =========================================================  ERFL  ========================================================== */
#define R_CANFD_CFDC_ERFL_BEF_Pos       (0UL)          /*!< BEF (Bit 0)                                             */
#define R_CANFD_CFDC_ERFL_BEF_Msk       (0x1UL)        /*!< BEF (Bitfield-Mask: 0x01)                               */
#define R_CANFD_CFDC_ERFL_EWF_Pos       (1UL)          /*!< EWF (Bit 1)                                             */
#define R_CANFD_CFDC_ERFL_EWF_Msk       (0x2UL)        /*!< EWF (Bitfield-Mask: 0x01)                               */
#define R_CANFD_CFDC_ERFL_EPF_Pos       (2UL)          /*!< EPF (Bit 2)                                             */
#define R_CANFD_CFDC_ERFL_EPF_Msk       (0x4UL)        /*!< EPF (Bitfield-Mask: 0x01)                               */
#define R_CANFD_CFDC_ERFL_BOEF_Pos      (3UL)          /*!< BOEF (Bit 3)                                            */
#define R_CANFD_CFDC_ERFL_BOEF_Msk      (0x8UL)        /*!< BOEF (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_ERFL_BORF_Pos      (4UL)          /*!< BORF (Bit 4)                                            */
#define R_CANFD_CFDC_ERFL_BORF_Msk      (0x10UL)       /*!< BORF (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_ERFL_OVLF_Pos      (5UL)          /*!< OVLF (Bit 5)                                            */
#define R_CANFD_CFDC_ERFL_OVLF_Msk      (0x20UL)       /*!< OVLF (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_ERFL_BLF_Pos       (6UL)          /*!< BLF (Bit 6)                                             */
#define R_CANFD_CFDC_ERFL_BLF_Msk       (0x40UL)       /*!< BLF (Bitfield-Mask: 0x01)                               */
#define R_CANFD_CFDC_ERFL_ALF_Pos       (7UL)          /*!< ALF (Bit 7)                                             */
#define R_CANFD_CFDC_ERFL_ALF_Msk       (0x80UL)       /*!< ALF (Bitfield-Mask: 0x01)                               */
#define R_CANFD_CFDC_ERFL_SERR_Pos      (8UL)          /*!< SERR (Bit 8)                                            */
#define R_CANFD_CFDC_ERFL_SERR_Msk      (0x100UL)      /*!< SERR (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_ERFL_FERR_Pos      (9UL)          /*!< FERR (Bit 9)                                            */
#define R_CANFD_CFDC_ERFL_FERR_Msk      (0x200UL)      /*!< FERR (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_ERFL_AERR_Pos      (10UL)         /*!< AERR (Bit 10)                                           */
#define R_CANFD_CFDC_ERFL_AERR_Msk      (0x400UL)      /*!< AERR (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_ERFL_CERR_Pos      (11UL)         /*!< CERR (Bit 11)                                           */
#define R_CANFD_CFDC_ERFL_CERR_Msk      (0x800UL)      /*!< CERR (Bitfield-Mask: 0x01)                              */
#define R_CANFD_CFDC_ERFL_B1ERR_Pos     (12UL)         /*!< B1ERR (Bit 12)                                          */
#define R_CANFD_CFDC_ERFL_B1ERR_Msk     (0x1000UL)     /*!< B1ERR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_ERFL_B0ERR_Pos     (13UL)         /*!< B0ERR (Bit 13)                                          */
#define R_CANFD_CFDC_ERFL_B0ERR_Msk     (0x2000UL)     /*!< B0ERR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_ERFL_ADERR_Pos     (14UL)         /*!< ADERR (Bit 14)                                          */
#define R_CANFD_CFDC_ERFL_ADERR_Msk     (0x4000UL)     /*!< ADERR (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_ERFL_CRCREG_Pos    (16UL)         /*!< CRCREG (Bit 16)                                         */
#define R_CANFD_CFDC_ERFL_CRCREG_Msk    (0x7fff0000UL) /*!< CRCREG (Bitfield-Mask: 0x7fff)                          */

/* =========================================================================================================================== */
/* ================                                           CFDC2                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  DCFG  ========================================================== */
#define R_CANFD_CFDC2_DCFG_DBRP_Pos       (0UL)          /*!< DBRP (Bit 0)                                          */
#define R_CANFD_CFDC2_DCFG_DBRP_Msk       (0xffUL)       /*!< DBRP (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFDC2_DCFG_DTSEG1_Pos     (16UL)         /*!< DTSEG1 (Bit 8)                                        */
#define R_CANFD_CFDC2_DCFG_DTSEG1_Msk     (0x1f00UL)     /*!< DTSEG1 (Bitfield-Mask: 0x1f)                          */
#define R_CANFD_CFDC2_DCFG_DTSEG2_Pos     (20UL)         /*!< DTSEG2 (Bit 16)                                       */
#define R_CANFD_CFDC2_DCFG_DTSEG2_Msk     (0x70000UL)    /*!< DTSEG2 (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDC2_DCFG_DSJW_Pos       (24UL)         /*!< DSJW (Bit 24)                                         */
#define R_CANFD_CFDC2_DCFG_DSJW_Msk       (0x7000000UL)  /*!< DSJW (Bitfield-Mask: 0x07)                            */
/* =========================================================  FDCFG  ========================================================= */
#define R_CANFD_CFDC2_FDCFG_EOCCFG_Pos    (0UL)          /*!< EOCCFG (Bit 0)                                        */
#define R_CANFD_CFDC2_FDCFG_EOCCFG_Msk    (0x7UL)        /*!< EOCCFG (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDC2_FDCFG_TDCOC_Pos     (8UL)          /*!< TDCOC (Bit 8)                                         */
#define R_CANFD_CFDC2_FDCFG_TDCOC_Msk     (0x100UL)      /*!< TDCOC (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC2_FDCFG_TDCE_Pos      (9UL)          /*!< TDCE (Bit 9)                                          */
#define R_CANFD_CFDC2_FDCFG_TDCE_Msk      (0x200UL)      /*!< TDCE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_ESIC_Pos      (10UL)         /*!< ESIC (Bit 10)                                         */
#define R_CANFD_CFDC2_FDCFG_ESIC_Msk      (0x400UL)      /*!< ESIC (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_TDCO_Pos      (16UL)         /*!< TDCO (Bit 16)                                         */
#define R_CANFD_CFDC2_FDCFG_TDCO_Msk      (0x7f0000UL)   /*!< TDCO (Bitfield-Mask: 0x7f)                            */
#define R_CANFD_CFDC2_FDCFG_GWEN_Pos      (24UL)         /*!< GWEN (Bit 24)                                         */
#define R_CANFD_CFDC2_FDCFG_GWEN_Msk      (0x1000000UL)  /*!< GWEN (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_GWFDF_Pos     (25UL)         /*!< GWFDF (Bit 25)                                        */
#define R_CANFD_CFDC2_FDCFG_GWFDF_Msk     (0x2000000UL)  /*!< GWFDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC2_FDCFG_GWBRS_Pos     (26UL)         /*!< GWBRS (Bit 26)                                        */
#define R_CANFD_CFDC2_FDCFG_GWBRS_Msk     (0x4000000UL)  /*!< GWBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC2_FDCFG_TMME_Pos      (27UL)         /*!< TMME (Bit 27)                                         */
#define R_CANFD_CFDC2_FDCFG_TMME_Msk      (0x8000000UL)  /*!< TMME (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_FDOE_Pos      (28UL)         /*!< FDOE (Bit 28)                                         */
#define R_CANFD_CFDC2_FDCFG_FDOE_Msk      (0x10000000UL) /*!< FDOE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_REFE_Pos      (29UL)         /*!< REFE (Bit 29)                                         */
#define R_CANFD_CFDC2_FDCFG_REFE_Msk      (0x20000000UL) /*!< REFE (Bitfield-Mask: 0x01)                            */
/* =========================================================  FDCTR  ========================================================= */
#define R_CANFD_CFDC2_FDCTR_EOCCLR_Pos    (0UL)          /*!< EOCCLR (Bit 0)                                        */
#define R_CANFD_CFDC2_FDCTR_EOCCLR_Msk    (0x1UL)        /*!< EOCCLR (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC2_FDCTR_SOCCLR_Pos    (1UL)          /*!< SOCCLR (Bit 1)                                        */
#define R_CANFD_CFDC2_FDCTR_SOCCLR_Msk    (0x2UL)        /*!< SOCCLR (Bitfield-Mask: 0x01)                          */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFD_CFDC2_FDSTS_TDCR_Pos      (0UL)          /*!< TDCR (Bit 0)                                          */
#define R_CANFD_CFDC2_FDSTS_TDCR_Msk      (0xffUL)       /*!< TDCR (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFDC2_FDSTS_TDCVF_Pos     (7UL)          /*!< TDCVF (Bit 7)                                         */
#define R_CANFD_CFDC2_FDSTS_TDCVF_Msk     (0x80UL)       /*!< TDCVF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC2_FDSTS_EOCO_Pos      (8UL)          /*!< EOCO (Bit 8)                                          */
#define R_CANFD_CFDC2_FDSTS_EOCO_Msk      (0x100UL)      /*!< EOCO (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDSTS_SOCO_Pos      (9UL)          /*!< SOCO (Bit 9)                                          */
#define R_CANFD_CFDC2_FDSTS_SOCO_Msk      (0x200UL)      /*!< SOCO (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDSTS_EOC_Pos       (16UL)         /*!< EOC (Bit 16)                                          */
#define R_CANFD_CFDC2_FDSTS_EOC_Msk       (0xff0000UL)   /*!< EOC (Bitfield-Mask: 0xff)                             */
#define R_CANFD_CFDC2_FDSTS_SOC_Pos       (24UL)         /*!< SOC (Bit 24)                                          */
#define R_CANFD_CFDC2_FDSTS_SOC_Msk       (0xff000000UL) /*!< SOC (Bitfield-Mask: 0xff)                             */
/* =========================================================  FDCRC  ========================================================= */
#define R_CANFD_CFDC2_FDCRC_CRCREG_Pos    (0UL)          /*!< CRCREG (Bit 0)                                        */
#define R_CANFD_CFDC2_FDCRC_CRCREG_Msk    (0x1fffffUL)   /*!< CRCREG (Bitfield-Mask: 0x1fffff)                      */
#define R_CANFD_CFDC2_FDCRC_SCNT_Pos      (24UL)         /*!< SCNT (Bit 24)                                         */
#define R_CANFD_CFDC2_FDCRC_SCNT_Msk      (0xf000000UL)  /*!< SCNT (Bitfield-Mask: 0x0f)                             */

/* =========================================================================================================================== */
/* ================                                          CFDGAFL                                          ================ */
/* =========================================================================================================================== */

/* ==========================================================  ID  =========================================================== */
#define R_CANFD_CFDGAFL_ID_GAFLID_Pos      (0UL)          /*!< GAFLID (Bit 0)                                       */
#define R_CANFD_CFDGAFL_ID_GAFLID_Msk      (0x1fffffffUL) /*!< GAFLID (Bitfield-Mask: 0x1fffffff)                   */
#define R_CANFD_CFDGAFL_ID_GAFLLB_Pos      (29UL)         /*!< GAFLLB (Bit 29)                                      */
#define R_CANFD_CFDGAFL_ID_GAFLLB_Msk      (0x20000000UL) /*!< GAFLLB (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGAFL_ID_GAFLRTR_Pos     (30UL)         /*!< GAFLRTR (Bit 30)                                     */
#define R_CANFD_CFDGAFL_ID_GAFLRTR_Msk     (0x40000000UL) /*!< GAFLRTR (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDGAFL_ID_GAFLIDE_Pos     (31UL)         /*!< GAFLIDE (Bit 31)                                     */
#define R_CANFD_CFDGAFL_ID_GAFLIDE_Msk     (0x80000000UL) /*!< GAFLIDE (Bitfield-Mask: 0x01)                        */
/* ===========================================================  M  =========================================================== */
#define R_CANFD_CFDGAFL_M_GAFLIDM_Pos      (0UL)          /*!< GAFLIDM (Bit 0)                                      */
#define R_CANFD_CFDGAFL_M_GAFLIDM_Msk      (0x1fffffffUL) /*!< GAFLIDM (Bitfield-Mask: 0x1fffffff)                  */
#define R_CANFD_CFDGAFL_M_GAFLRTRM_Pos     (30UL)         /*!< GAFLRTRM (Bit 30)                                    */
#define R_CANFD_CFDGAFL_M_GAFLRTRM_Msk     (0x40000000UL) /*!< GAFLRTRM (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDGAFL_M_GAFLIDEM_Pos     (31UL)         /*!< GAFLIDEM (Bit 31)                                    */
#define R_CANFD_CFDGAFL_M_GAFLIDEM_Msk     (0x80000000UL) /*!< GAFLIDEM (Bitfield-Mask: 0x01)                       */
/* ==========================================================  P0  =========================================================== */
#define R_CANFD_CFDGAFL_P0_GAFLRMDP_Pos    (8UL)          /*!< GAFLRMDP (Bit 8)                                     */
#define R_CANFD_CFDGAFL_P0_GAFLRMDP_Msk    (0x7f00UL)     /*!< GAFLRMDP (Bitfield-Mask: 0x7f)                       */
#define R_CANFD_CFDGAFL_P0_GAFLRMV_Pos     (15UL)         /*!< GAFLRMV (Bit 15)                                     */
#define R_CANFD_CFDGAFL_P0_GAFLRMV_Msk     (0x8000UL)     /*!< GAFLRMV (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDGAFL_P0_GAFLPTR_Pos     (16UL)         /*!< GAFLPTR (Bit 16)                                     */
#define R_CANFD_CFDGAFL_P0_GAFLPTR_Msk     (0xfff0000UL)  /*!< GAFLPTR (Bitfield-Mask: 0xfff)                       */
#define R_CANFD_CFDGAFL_P0_GAFLDLC_Pos     (28UL)         /*!< GAFLDLC (Bit 28)                                     */
#define R_CANFD_CFDGAFL_P0_GAFLDLC_Msk     (0xf0000000UL) /*!< GAFLDLC (Bitfield-Mask: 0x0f)                        */
/* ==========================================================  P1  =========================================================== */
#define R_CANFD_CFDGAFL_P1_GAFLFDP_Pos     (0UL)          /*!< GAFLFDP (Bit 0)                                      */
#define R_CANFD_CFDGAFL_P1_GAFLFDP_Msk     (0x3fffUL)     /*!< GAFLFDP (Bitfield-Mask: 0x3fff)                      */

/* =========================================================================================================================== */
/* ================                                          CFDTHL                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  ACC0  ========================================================== */
#define R_CANFD_CFDTHL_ACC0_BT_Pos      (0UL)          /*!< BT (Bit 0)                                              */
#define R_CANFD_CFDTHL_ACC0_BT_Msk      (0x7UL)        /*!< BT (Bitfield-Mask: 0x07)                                */
#define R_CANFD_CFDTHL_ACC0_BN_Pos      (3UL)          /*!< BN (Bit 3)                                              */
#define R_CANFD_CFDTHL_ACC0_BN_Msk      (0x78UL)       /*!< BN (Bitfield-Mask: 0x0f)                                */
#define R_CANFD_CFDTHL_ACC0_TID_Pos     (8UL)          /*!< TID (Bit 8)                                             */
#define R_CANFD_CFDTHL_ACC0_TID_Msk     (0xff00UL)     /*!< TID (Bitfield-Mask: 0xff)                               */
#define R_CANFD_CFDTHL_ACC0_TMTS_Pos    (16UL)         /*!< TMTS (Bit 16)                                           */
#define R_CANFD_CFDTHL_ACC0_TMTS_Msk    (0xffff0000UL) /*!< TMTS (Bitfield-Mask: 0xffff)                            */

/* =========================================================================================================================== */
/* ================                                           CFDRM                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  ID  =========================================================== */
#define R_CANFD_CFDRM_ID_RMID_Pos        (0UL)          /*!< RMID (Bit 0)                                          */
#define R_CANFD_CFDRM_ID_RMID_Msk        (0x1fffffffUL) /*!< RMID (Bitfield-Mask: 0x1fffffff)                      */
#define R_CANFD_CFDRM_ID_RMRTR_Pos       (30UL)         /*!< RMRTR (Bit 30)                                        */
#define R_CANFD_CFDRM_ID_RMRTR_Msk       (0x40000000UL) /*!< RMRTR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRM_ID_RMIDE_Pos       (31UL)         /*!< RMIDE (Bit 31)                                        */
#define R_CANFD_CFDRM_ID_RMIDE_Msk       (0x80000000UL) /*!< RMIDE (Bitfield-Mask: 0x01)                           */
/* ==========================================================  PTR  ========================================================== */
#define R_CANFD_CFDRM_PTR_RMTS_Pos       (0UL)          /*!< RMTS (Bit 0)                                          */
#define R_CANFD_CFDRM_PTR_RMTS_Msk       (0xffffUL)     /*!< RMTS (Bitfield-Mask: 0xffff)                          */
#define R_CANFD_CFDRM_PTR_RMPTR_Pos      (16UL)         /*!< RMPTR (Bit 16)                                        */
#define R_CANFD_CFDRM_PTR_RMPTR_Msk      (0xfff0000UL)  /*!< RMPTR (Bitfield-Mask: 0xfff)                          */
#define R_CANFD_CFDRM_PTR_RMDLC_Pos      (28UL)         /*!< RMDLC (Bit 28)                                        */
#define R_CANFD_CFDRM_PTR_RMDLC_Msk      (0xf0000000UL) /*!< RMDLC (Bitfield-Mask: 0x0f)                           */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFD_CFDRM_FDSTS_RMESI_Pos    (0UL)          /*!< RMESI (Bit 0)                                         */
#define R_CANFD_CFDRM_FDSTS_RMESI_Msk    (0x1UL)        /*!< RMESI (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRM_FDSTS_RMBRS_Pos    (1UL)          /*!< RMBRS (Bit 1)                                         */
#define R_CANFD_CFDRM_FDSTS_RMBRS_Msk    (0x2UL)        /*!< RMBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRM_FDSTS_RMFDF_Pos    (2UL)          /*!< RMFDF (Bit 2)                                         */
#define R_CANFD_CFDRM_FDSTS_RMFDF_Msk    (0x4UL)        /*!< RMFDF (Bitfield-Mask: 0x01)                           */
/* ==========================================================  DF  =========================================================== */
#define R_CANFD_CFDRM_DF_RMDB_Pos        (0UL)          /*!< RMDB (Bit 0)                                          */
#define R_CANFD_CFDRM_DF_RMDB_Msk        (0xffUL)       /*!< RMDB (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                           CFDRF                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  ID  =========================================================== */
#define R_CANFD_CFDRF_ID_RFID_Pos        (0UL)          /*!< RFID (Bit 0)                                          */
#define R_CANFD_CFDRF_ID_RFID_Msk        (0x1fffffffUL) /*!< RFID (Bitfield-Mask: 0x1fffffff)                      */
#define R_CANFD_CFDRF_ID_RFRTR_Pos       (30UL)         /*!< RFRTR (Bit 30)                                        */
#define R_CANFD_CFDRF_ID_RFRTR_Msk       (0x40000000UL) /*!< RFRTR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRF_ID_RFIDE_Pos       (31UL)         /*!< RFIDE (Bit 31)                                        */
#define R_CANFD_CFDRF_ID_RFIDE_Msk       (0x80000000UL) /*!< RFIDE (Bitfield-Mask: 0x01)                           */
/* ==========================================================  PTR  ========================================================== */
#define R_CANFD_CFDRF_PTR_RFTS_Pos       (0UL)          /*!< RFTS (Bit 0)                                          */
#define R_CANFD_CFDRF_PTR_RFTS_Msk       (0xffffUL)     /*!< RFTS (Bitfield-Mask: 0xffff)                          */
#define R_CANFD_CFDRF_PTR_RFPTR_Pos      (16UL)         /*!< RFPTR (Bit 16)                                        */
#define R_CANFD_CFDRF_PTR_RFPTR_Msk      (0xfff0000UL)  /*!< RFPTR (Bitfield-Mask: 0xfff)                          */
#define R_CANFD_CFDRF_PTR_RFDLC_Pos      (28UL)         /*!< RFDLC (Bit 28)                                        */
#define R_CANFD_CFDRF_PTR_RFDLC_Msk      (0xf0000000UL) /*!< RFDLC (Bitfield-Mask: 0x0f)                           */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFD_CFDRF_FDSTS_RFESI_Pos    (0UL)          /*!< RFESI (Bit 0)                                         */
#define R_CANFD_CFDRF_FDSTS_RFESI_Msk    (0x1UL)        /*!< RFESI (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRF_FDSTS_RFBRS_Pos    (1UL)          /*!< RFBRS (Bit 1)                                         */
#define R_CANFD_CFDRF_FDSTS_RFBRS_Msk    (0x2UL)        /*!< RFBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRF_FDSTS_RFFDF_Pos    (2UL)          /*!< RFFDF (Bit 2)                                         */
#define R_CANFD_CFDRF_FDSTS_RFFDF_Msk    (0x4UL)        /*!< RFFDF (Bitfield-Mask: 0x01)                           */
/* ==========================================================  DF  =========================================================== */
#define R_CANFD_CFDRF_DF_RFDB_Pos        (0UL)          /*!< RFDB (Bit 0)                                          */
#define R_CANFD_CFDRF_DF_RFDB_Msk        (0xffUL)       /*!< RFDB (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                           CFDCF                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  ID  =========================================================== */
#define R_CANFD_CFDCF_ID_CFID_Pos        (0UL)          /*!< CFID (Bit 0)                                          */
#define R_CANFD_CFDCF_ID_CFID_Msk        (0x1fffffffUL) /*!< CFID (Bitfield-Mask: 0x1fffffff)                      */
#define R_CANFD_CFDCF_ID_THLEN_Pos       (29UL)         /*!< THLEN (Bit 29)                                        */
#define R_CANFD_CFDCF_ID_THLEN_Msk       (0x20000000UL) /*!< THLEN (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCF_ID_CFRTR_Pos       (30UL)         /*!< CFRTR (Bit 30)                                        */
#define R_CANFD_CFDCF_ID_CFRTR_Msk       (0x40000000UL) /*!< CFRTR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCF_ID_CFIDE_Pos       (31UL)         /*!< CFIDE (Bit 31)                                        */
#define R_CANFD_CFDCF_ID_CFIDE_Msk       (0x80000000UL) /*!< CFIDE (Bitfield-Mask: 0x01)                           */
/* ==========================================================  PTR  ========================================================== */
#define R_CANFD_CFDCF_PTR_CFTS_Pos       (0UL)          /*!< CFTS (Bit 0)                                          */
#define R_CANFD_CFDCF_PTR_CFTS_Msk       (0xffffUL)     /*!< CFTS (Bitfield-Mask: 0xffff)                          */
#define R_CANFD_CFDCF_PTR_CFPTR_Pos      (16UL)         /*!< CFPTR (Bit 16)                                        */
#define R_CANFD_CFDCF_PTR_CFPTR_Msk      (0xfff0000UL)  /*!< CFPTR (Bitfield-Mask: 0xfff)                          */
#define R_CANFD_CFDCF_PTR_CFDLC_Pos      (28UL)         /*!< CFDLC (Bit 28)                                        */
#define R_CANFD_CFDCF_PTR_CFDLC_Msk      (0xf0000000UL) /*!< CFDLC (Bitfield-Mask: 0x0f)                           */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFD_CFDCF_FDSTS_CFESI_Pos    (0UL)          /*!< CFESI (Bit 0)                                         */
#define R_CANFD_CFDCF_FDSTS_CFESI_Msk    (0x1UL)        /*!< CFESI (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCF_FDSTS_CFBRS_Pos    (1UL)          /*!< CFBRS (Bit 1)                                         */
#define R_CANFD_CFDCF_FDSTS_CFBRS_Msk    (0x2UL)        /*!< CFBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCF_FDSTS_CFFDF_Pos    (2UL)          /*!< CFFDF (Bit 2)                                         */
#define R_CANFD_CFDCF_FDSTS_CFFDF_Msk    (0x4UL)        /*!< CFFDF (Bitfield-Mask: 0x01)                           */
/* ==========================================================  DF  =========================================================== */
#define R_CANFD_CFDCF_DF_CFDB_Pos        (0UL)          /*!< CFDB (Bit 0)                                          */
#define R_CANFD_CFDCF_DF_CFDB_Msk        (0xffUL)       /*!< CFDB (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                           CFDTM                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  ID  =========================================================== */
#define R_CANFD_CFDTM_ID_TMID_Pos        (0UL)          /*!< TMID (Bit 0)                                          */
#define R_CANFD_CFDTM_ID_TMID_Msk        (0x1fffffffUL) /*!< TMID (Bitfield-Mask: 0x1fffffff)                      */
#define R_CANFD_CFDCF_ID_THLEN_Pos       (29UL)         /*!< THLEN (Bit 29)                                        */
#define R_CANFD_CFDCF_ID_THLEN_Msk       (0x20000000UL) /*!< THLEN (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTM_ID_TMRTR_Pos       (30UL)         /*!< TMRTR (Bit 30)                                        */
#define R_CANFD_CFDTM_ID_TMRTR_Msk       (0x40000000UL) /*!< TMRTR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTM_ID_TMIDE_Pos       (31UL)         /*!< TMIDE (Bit 31)                                        */
#define R_CANFD_CFDTM_ID_TMIDE_Msk       (0x80000000UL) /*!< TMIDE (Bitfield-Mask: 0x01)                           */
/* ==========================================================  PTR  ========================================================== */
#define R_CANFD_CFDTM_PTR_TMPTR_Pos      (16UL)         /*!< TMPTR (Bit 16)                                        */
#define R_CANFD_CFDTM_PTR_TMPTR_Msk      (0xff0000UL)   /*!< TMPTR (Bitfield-Mask: 0xff)                           */
#define R_CANFD_CFDTM_PTR_TMDLC_Pos      (28UL)         /*!< TMDLC (Bit 28)                                        */
#define R_CANFD_CFDTM_PTR_TMDLC_Msk      (0xf0000000UL) /*!< TMDLC (Bitfield-Mask: 0x0f)                           */
/* =========================================================  FDCTR  ========================================================= */
#define R_CANFD_CFDTM_FDCTR_TMESI_Pos    (0UL)          /*!< TMESI (Bit 0)                                         */
#define R_CANFD_CFDTM_FDCTR_TMESI_Msk    (0x1UL)        /*!< TMESI (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTM_FDCTR_TMBRS_Pos    (1UL)          /*!< TMBRS (Bit 1)                                         */
#define R_CANFD_CFDTM_FDCTR_TMBRS_Msk    (0x2UL)        /*!< TMBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTM_FDCTR_TMFDF_Pos    (2UL)          /*!< TMFDF (Bit 2)                                         */
#define R_CANFD_CFDTM_FDCTR_TMFDF_Msk    (0x4UL)        /*!< TMFDF (Bitfield-Mask: 0x01)                           */
/* ==========================================================  DF  =========================================================== */
#define R_CANFD_CFDTM_DF_TMDB_Pos        (0UL)          /*!< TMDB (Bit 0)                                          */
#define R_CANFD_CFDTM_DF_TMDB_Msk        (0xffUL)       /*!< TMDB (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                          R_CANFD                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  CFDGCFG  ======================================================== */
#define R_CANFD_CFDGCFG_TPRI_Pos            (0UL)          /*!< TPRI (Bit 0)                                          */
#define R_CANFD_CFDGCFG_TPRI_Msk            (0x1UL)        /*!< TPRI (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGCFG_DCE_Pos             (1UL)          /*!< DCE (Bit 1)                                           */
#define R_CANFD_CFDGCFG_DCE_Msk             (0x2UL)        /*!< DCE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGCFG_DRE_Pos             (2UL)          /*!< DRE (Bit 2)                                           */
#define R_CANFD_CFDGCFG_DRE_Msk             (0x4UL)        /*!< DRE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGCFG_MME_Pos             (3UL)          /*!< MME (Bit 3)                                           */
#define R_CANFD_CFDGCFG_MME_Msk             (0x8UL)        /*!< MME (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGCFG_DCS_Pos             (4UL)          /*!< DCS (Bit 4)                                           */
#define R_CANFD_CFDGCFG_DCS_Msk             (0x10UL)       /*!< DCS (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGCFG_CMPOC_Pos           (5UL)          /*!< CMPOC (Bit 5)                                         */
#define R_CANFD_CFDGCFG_CMPOC_Msk           (0x20UL)       /*!< CMPOC (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGCFG_TSP_Pos             (8UL)          /*!< TSP (Bit 8)                                           */
#define R_CANFD_CFDGCFG_TSP_Msk             (0xf00UL)      /*!< TSP (Bitfield-Mask: 0x0f)                             */
#define R_CANFD_CFDGCFG_TSSS_Pos            (12UL)         /*!< TSSS (Bit 12)                                         */
#define R_CANFD_CFDGCFG_TSSS_Msk            (0x1000UL)     /*!< TSSS (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGCFG_TSBTCS_Pos          (13UL)         /*!< TSBTCS (Bit 13)                                       */
#define R_CANFD_CFDGCFG_TSBTCS_Msk          (0xe000UL)     /*!< TSBTCS (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDGCFG_ITRCP_Pos           (16UL)         /*!< ITRCP (Bit 16)                                        */
#define R_CANFD_CFDGCFG_ITRCP_Msk           (0xffff0000UL) /*!< ITRCP (Bitfield-Mask: 0xffff)                         */
/* ========================================================  CFDGCTR  ======================================================== */
#define R_CANFD_CFDGCTR_GMDC_Pos            (0UL)          /*!< GMDC (Bit 0)                                          */
#define R_CANFD_CFDGCTR_GMDC_Msk            (0x3UL)        /*!< GMDC (Bitfield-Mask: 0x03)                            */
#define R_CANFD_CFDGCTR_GSLPR_Pos           (2UL)          /*!< GSLPR (Bit 2)                                         */
#define R_CANFD_CFDGCTR_GSLPR_Msk           (0x4UL)        /*!< GSLPR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGCTR_DEIE_Pos            (8UL)          /*!< DEIE (Bit 8)                                          */
#define R_CANFD_CFDGCTR_DEIE_Msk            (0x100UL)      /*!< DEIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGCTR_MEIE_Pos            (9UL)          /*!< MEIE (Bit 9)                                          */
#define R_CANFD_CFDGCTR_MEIE_Msk            (0x200UL)      /*!< MEIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGCTR_THLEIE_Pos          (10UL)         /*!< THLEIE (Bit 10)                                       */
#define R_CANFD_CFDGCTR_THLEIE_Msk          (0x400UL)      /*!< THLEIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGCTR_CMPOFIE_Pos         (11UL)         /*!< CMPOFIE (Bit 11)                                      */
#define R_CANFD_CFDGCTR_CMPOFIE_Msk         (0x800UL)      /*!< CMPOFIE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGCTR_TSRST_Pos           (16UL)         /*!< TSRST (Bit 16)                                        */
#define R_CANFD_CFDGCTR_TSRST_Msk           (0x10000UL)    /*!< TSRST (Bitfield-Mask: 0x01)                           */
/* ========================================================  CFDGSTS  ======================================================== */
#define R_CANFD_CFDGSTS_GRSTSTS_Pos         (0UL)          /*!< GRSTSTS (Bit 0)                                       */
#define R_CANFD_CFDGSTS_GRSTSTS_Msk         (0x1UL)        /*!< GRSTSTS (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGSTS_GHLTSTS_Pos         (1UL)          /*!< GHLTSTS (Bit 1)                                       */
#define R_CANFD_CFDGSTS_GHLTSTS_Msk         (0x2UL)        /*!< GHLTSTS (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGSTS_GSLPSTS_Pos         (2UL)          /*!< GSLPSTS (Bit 2)                                       */
#define R_CANFD_CFDGSTS_GSLPSTS_Msk         (0x4UL)        /*!< GSLPSTS (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGSTS_GRAMINIT_Pos        (3UL)          /*!< GRAMINIT (Bit 3)                                      */
#define R_CANFD_CFDGSTS_GRAMINIT_Msk        (0x8UL)        /*!< GRAMINIT (Bitfield-Mask: 0x01)                        */
/* =======================================================  CFDGERFL  ======================================================== */
#define R_CANFD_CFDGERFL_DEF_Pos            (0UL)          /*!< DEF (Bit 0)                                           */
#define R_CANFD_CFDGERFL_DEF_Msk            (0x1UL)        /*!< DEF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGERFL_MES_Pos            (1UL)          /*!< MES (Bit 1)                                           */
#define R_CANFD_CFDGERFL_MES_Msk            (0x2UL)        /*!< MES (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGERFL_THLES_Pos          (2UL)          /*!< THLES (Bit 2)                                         */
#define R_CANFD_CFDGERFL_THLES_Msk          (0x4UL)        /*!< THLES (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGERFL_CMPOF_Pos          (3UL)          /*!< CMPOF (Bit 3)                                         */
#define R_CANFD_CFDGERFL_CMPOF_Msk          (0x8UL)        /*!< CMPOF (Bitfield-Mask: 0x01)                           */
/* ========================================================  CFDGTSC  ======================================================== */
#define R_CANFD_CFDGTSC_TS_Pos              (0UL)          /*!< TS (Bit 0)                                            */
#define R_CANFD_CFDGTSC_TS_Msk              (0xffffUL)     /*!< TS (Bitfield-Mask: 0xffff)                            */
/* ======================================================  CFDGAFLECTR  ====================================================== */
#define R_CANFD_CFDGAFLECTR_AFLPN_Pos       (0UL)          /*!< AFLPN (Bit 0)                                         */
#define R_CANFD_CFDGAFLECTR_AFLPN_Msk       (0x1fUL)       /*!< AFLPN (Bitfield-Mask: 0x1f)                           */
#define R_CANFD_CFDGAFLECTR_AFLDAE_Pos      (8UL)          /*!< AFLDAE (Bit 8)                                        */
#define R_CANFD_CFDGAFLECTR_AFLDAE_Msk      (0x100UL)      /*!< AFLDAE (Bitfield-Mask: 0x01)                          */
/* ======================================================  CFDGAFLCFG0  ====================================================== */
#define R_CANFD_CFDGAFLCFG0_RNC1_Pos        (16UL)         /*!< RNC1 (Bit 16)                                         */
#define R_CANFD_CFDGAFLCFG0_RNC1_Msk        (0xff0000UL)   /*!< RNC1 (Bitfield-Mask: 0x1ff)                           */
#define R_CANFD_CFDGAFLCFG0_RNC0_Pos        (24UL)         /*!< RNC0 (Bit 24)                                         */
#define R_CANFD_CFDGAFLCFG0_RNC0_Msk        (0xff000000UL) /*!< RNC0 (Bitfield-Mask: 0x1ff)                           */
/* ========================================================  CFDRMNB  ======================================================== */
#define R_CANFD_CFDRMNB_NRXMB_Pos           (0UL)          /*!< NRXMB (Bit 0)                                         */
#define R_CANFD_CFDRMNB_NRXMB_Msk           (0xffUL)       /*!< NRXMB (Bitfield-Mask: 0xff)                           */
#define R_CANFD_CFDRMNB_RMPLS_Pos           (8UL)          /*!< RMPLS (Bit 8)                                         */
#define R_CANFD_CFDRMNB_RMPLS_Msk           (0x700UL)      /*!< RMPLS (Bitfield-Mask: 0x07)                           */
/* =======================================================  CFDRMND0  ======================================================== */
#define R_CANFD_CFDRMND0_RMNS_Pos           (0UL)          /*!< RMNS (Bit 0)                                         */
#define R_CANFD_CFDRMND0_RMNS_Msk           (0xffffffffUL) /*!< RMNS (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  CFDRFCC  ======================================================== */
#define R_CANFD_CFDRFCC_RFE_Pos             (0UL)          /*!< RFE (Bit 0)                                           */
#define R_CANFD_CFDRFCC_RFE_Msk             (0x1UL)        /*!< RFE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDRFCC_RFIE_Pos            (1UL)          /*!< RFIE (Bit 1)                                          */
#define R_CANFD_CFDRFCC_RFIE_Msk            (0x2UL)        /*!< RFIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDRFCC_RFPLS_Pos           (4UL)          /*!< RFPLS (Bit 4)                                         */
#define R_CANFD_CFDRFCC_RFPLS_Msk           (0x70UL)       /*!< RFPLS (Bitfield-Mask: 0x07)                           */
#define R_CANFD_CFDRFCC_RFDC_Pos            (8UL)          /*!< RFDC (Bit 8)                                          */
#define R_CANFD_CFDRFCC_RFDC_Msk            (0x700UL)      /*!< RFDC (Bitfield-Mask: 0x07)                            */
#define R_CANFD_CFDRFCC_RFIM_Pos            (12UL)         /*!< RFIM (Bit 12)                                         */
#define R_CANFD_CFDRFCC_RFIM_Msk            (0x1000UL)     /*!< RFIM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDRFCC_RFIGCV_Pos          (13UL)         /*!< RFIGCV (Bit 13)                                       */
#define R_CANFD_CFDRFCC_RFIGCV_Msk          (0xe000UL)     /*!< RFIGCV (Bitfield-Mask: 0x07)                          */
/* =======================================================  CFDRFSTS  ======================================================== */
#define R_CANFD_CFDRFSTS_RFEMP_Pos          (0UL)          /*!< RFEMP (Bit 0)                                         */
#define R_CANFD_CFDRFSTS_RFEMP_Msk          (0x1UL)        /*!< RFEMP (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRFSTS_RFFLL_Pos          (1UL)          /*!< RFFLL (Bit 1)                                         */
#define R_CANFD_CFDRFSTS_RFFLL_Msk          (0x2UL)        /*!< RFFLL (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRFSTS_RFMLT_Pos          (2UL)          /*!< RFMLT (Bit 2)                                         */
#define R_CANFD_CFDRFSTS_RFMLT_Msk          (0x4UL)        /*!< RFMLT (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRFSTS_RFIF_Pos           (3UL)          /*!< RFIF (Bit 3)                                          */
#define R_CANFD_CFDRFSTS_RFIF_Msk           (0x8UL)        /*!< RFIF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDRFSTS_RFMC_Pos           (8UL)          /*!< RFMC (Bit 8)                                          */
#define R_CANFD_CFDRFSTS_RFMC_Msk           (0xff00UL)     /*!< RFMC (Bitfield-Mask: 0xff)                            */
/* =======================================================  CFDRFPCTR  ======================================================= */
#define R_CANFD_CFDRFPCTR_RFPC_Pos          (0UL)          /*!< RFPC (Bit 0)                                          */
#define R_CANFD_CFDRFPCTR_RFPC_Msk          (0xffUL)       /*!< RFPC (Bitfield-Mask: 0xff)                            */
/* ========================================================  CFDCFCC  ======================================================== */
#define R_CANFD_CFDCFCC_CFE_Pos             (0UL)          /*!< CFE (Bit 0)                                           */
#define R_CANFD_CFDCFCC_CFE_Msk             (0x1UL)        /*!< CFE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDCFCC_CFRXIE_Pos          (1UL)          /*!< CFRXIE (Bit 1)                                        */
#define R_CANFD_CFDCFCC_CFRXIE_Msk          (0x2UL)        /*!< CFRXIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFCC_CFTXIE_Pos          (2UL)          /*!< CFTXIE (Bit 2)                                        */
#define R_CANFD_CFDCFCC_CFTXIE_Msk          (0x4UL)        /*!< CFTXIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFCC_CFPLS_Pos           (4UL)          /*!< CFPLS (Bit 4)                                         */
#define R_CANFD_CFDCFCC_CFPLS_Msk           (0x70UL)       /*!< CFPLS (Bitfield-Mask: 0x07)                           */
#define R_CANFD_CFDCFCC_CFDC_Pos            (8UL)          /*!< CFDC (Bit 8)                                          */
#define R_CANFD_CFDCFCC_CFDC_Msk            (0x700UL)      /*!< CFDC (Bitfield-Mask: 0x07)                            */
#define R_CANFD_CFDCFCC_CFIM_Pos            (12UL)         /*!< CFIM (Bit 12)                                         */
#define R_CANFD_CFDCFCC_CFIM_Msk            (0x1000UL)     /*!< CFIM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDCFCC_CFIGCV_Pos          (13UL)         /*!< CFIGCV (Bit 13)                                       */
#define R_CANFD_CFDCFCC_CFIGCV_Msk          (0xe000UL)     /*!< CFIGCV (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDCFCC_CFM_Pos             (16UL)         /*!< CFM (Bit 16)                                          */
#define R_CANFD_CFDCFCC_CFM_Msk             (0x30000UL)    /*!< CFM (Bitfield-Mask: 0x03)                             */
#define R_CANFD_CFDCFCC_CFITSS_Pos          (18UL)         /*!< CFITSS (Bit 18)                                       */
#define R_CANFD_CFDCFCC_CFITSS_Msk          (0x40000UL)    /*!< CFITSS (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFCC_CFITR_Pos           (19UL)         /*!< CFITR (Bit 19)                                        */
#define R_CANFD_CFDCFCC_CFITR_Msk           (0x80000UL)    /*!< CFITR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFCC_CFTML_Pos           (20UL)         /*!< CFTML (Bit 16)                                        */
#define R_CANFD_CFDCFCC_CFTML_Msk           (0xf00000UL)   /*!< CFTML (Bitfield-Mask: 0x0f)                           */
#define R_CANFD_CFDCFCC_CFITT_Pos           (24UL)         /*!< CFITT (Bit 24)                                        */
#define R_CANFD_CFDCFCC_CFITT_Msk           (0xff000000UL) /*!< CFITT (Bitfield-Mask: 0xff)                           */
/* =======================================================  CFDCFSTS  ======================================================== */
#define R_CANFD_CFDCFSTS_CFEMP_Pos          (0UL)          /*!< CFEMP (Bit 0)                                         */
#define R_CANFD_CFDCFSTS_CFEMP_Msk          (0x1UL)        /*!< CFEMP (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFSTS_CFFLL_Pos          (1UL)          /*!< CFFLL (Bit 1)                                         */
#define R_CANFD_CFDCFSTS_CFFLL_Msk          (0x2UL)        /*!< CFFLL (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFSTS_CFMLT_Pos          (2UL)          /*!< CFMLT (Bit 2)                                         */
#define R_CANFD_CFDCFSTS_CFMLT_Msk          (0x4UL)        /*!< CFMLT (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFSTS_CFRXIF_Pos         (3UL)          /*!< CFRXIF (Bit 3)                                        */
#define R_CANFD_CFDCFSTS_CFRXIF_Msk         (0x8UL)        /*!< CFRXIF (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFSTS_CFTXIF_Pos         (4UL)          /*!< CFTXIF (Bit 4)                                        */
#define R_CANFD_CFDCFSTS_CFTXIF_Msk         (0x10UL)       /*!< CFTXIF (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFSTS_CFMC_Pos           (8UL)          /*!< CFMC (Bit 8)                                          */
#define R_CANFD_CFDCFSTS_CFMC_Msk           (0xff00UL)     /*!< CFMC (Bitfield-Mask: 0xff)                            */
/* =======================================================  CFDCFPCTR  ======================================================= */
#define R_CANFD_CFDCFPCTR_CFPC_Pos          (0UL)          /*!< CFPC (Bit 0)                                          */
#define R_CANFD_CFDCFPCTR_CFPC_Msk          (0xffUL)       /*!< CFPC (Bitfield-Mask: 0xff)                            */
/* =======================================================  CFDFESTS  ======================================================== */
#define R_CANFD_CFDFESTS_RFXEMP_Pos         (0UL)          /*!< RFXEMP (Bit 0)                                        */
#define R_CANFD_CFDFESTS_RFXEMP_Msk         (0xffUL)       /*!< RFXEMP (Bitfield-Mask: 0xff)                          */
#define R_CANFD_CFDFESTS_CFXEMP_Pos         (8UL)          /*!< CFXEMP (Bit 8)                                        */
#define R_CANFD_CFDFESTS_CFXEMP_Msk         (0x3f00UL)     /*!< CFXEMP (Bitfield-Mask: 0x3f)                          */
/* =======================================================  CFDFFSTS  ======================================================== */
#define R_CANFD_CFDFFSTS_RFXFLL_Pos         (0UL)          /*!< RFXFLL (Bit 0)                                        */
#define R_CANFD_CFDFFSTS_RFXFLL_Msk         (0xffUL)       /*!< RFXFLL (Bitfield-Mask: 0xff)                          */
#define R_CANFD_CFDFFSTS_CFXFLL_Pos         (8UL)          /*!< CFXFLL (Bit 8)                                        */
#define R_CANFD_CFDFFSTS_CFXFLL_Msk         (0x3f00UL)     /*!< CFXFLL (Bitfield-Mask: 0x3f)                          */
/* =======================================================  CFDFMSTS  ======================================================== */
#define R_CANFD_CFDFMSTS_RFXMLT_Pos         (0UL)          /*!< RFXMLT (Bit 0)                                        */
#define R_CANFD_CFDFMSTS_RFXMLT_Msk         (0xffUL)       /*!< RFXMLT (Bitfield-Mask: 0xff)                          */
#define R_CANFD_CFDFMSTS_CFXMLT_Pos         (8UL)          /*!< CFXMLT (Bit 8)                                        */
#define R_CANFD_CFDFMSTS_CFXMLT_Msk         (0x3f00UL)     /*!< CFXMLT (Bitfield-Mask: 0x3f)                          */
/* =======================================================  CFDRFISTS  ======================================================= */
#define R_CANFD_CFDRFISTS_RFXIF_Pos         (0UL)          /*!< RFXIF (Bit 0)                                         */
#define R_CANFD_CFDRFISTS_RFXIF_Msk         (0xffUL)       /*!< RFXIF (Bitfield-Mask: 0xff)                           */
#define R_CANFD_CFDRFISTS_RFXFFLL_Pos       (16UL)         /*!< RFXFFLL (Bit 16)                                      */
#define R_CANFD_CFDRFISTS_RFXFFLL_Msk       (0xff0000UL)   /*!< RFXFFLL (Bitfield-Mask: 0xff)                         */
/* ======================================================  CFDCFRISTS  ======================================================= */
#define R_CANFD_CFDCFRISTS_CFXRXIF_Pos      (0UL)          /*!< CFXRXIF (Bit 0)                                       */
#define R_CANFD_CFDCFRISTS_CFXRXIF_Msk      (0x3fUL)       /*!< CFXRXIF (Bitfield-Mask: 0x3f)                         */
/* ======================================================  CFDCFTISTS  ======================================================= */
#define R_CANFD_CFDCFTISTS_CFXTXIF_Pos      (0UL)          /*!< CFXTXIF (Bit 0)                                       */
#define R_CANFD_CFDCFTISTS_CFXTXIF_Msk      (0x3fUL)       /*!< CFXTXIF (Bitfield-Mask: 0x3f)                         */
/* ========================================================  CFDTMC  ========================================================= */
#define R_CANFD_CFDTMC_TMTR_Pos             (0UL)          /*!< TMTR (Bit 0)                                          */
#define R_CANFD_CFDTMC_TMTR_Msk             (0x1UL)        /*!< TMTR (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDTMC_TMTAR_Pos            (1UL)          /*!< TMTAR (Bit 1)                                         */
#define R_CANFD_CFDTMC_TMTAR_Msk            (0x2UL)        /*!< TMTAR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTMC_TMOM_Pos             (2UL)          /*!< TMOM (Bit 2)                                          */
#define R_CANFD_CFDTMC_TMOM_Msk             (0x4UL)        /*!< TMOM (Bitfield-Mask: 0x01)                            */
/* =======================================================  CFDTMSTS  ======================================================== */
#define R_CANFD_CFDTMSTS_TMTSTS_Pos         (0UL)          /*!< TMTSTS (Bit 0)                                        */
#define R_CANFD_CFDTMSTS_TMTSTS_Msk         (0x1UL)        /*!< TMTSTS (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTMSTS_TMTRF_Pos          (1UL)          /*!< TMTRF (Bit 1)                                         */
#define R_CANFD_CFDTMSTS_TMTRF_Msk          (0x6UL)        /*!< TMTRF (Bitfield-Mask: 0x03)                           */
#define R_CANFD_CFDTMSTS_TMTRM_Pos          (3UL)          /*!< TMTRM (Bit 3)                                         */
#define R_CANFD_CFDTMSTS_TMTRM_Msk          (0x8UL)        /*!< TMTRM (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTMSTS_TMTARM_Pos         (4UL)          /*!< TMTARM (Bit 4)                                        */
#define R_CANFD_CFDTMSTS_TMTARM_Msk         (0x10UL)       /*!< TMTARM (Bitfield-Mask: 0x01)                          */
/* ======================================================  CFDTMTRSTS  ======================================================= */
#define R_CANFD_CFDTMTRSTS_TMTRSTS_Pos      (0UL)          /*!< TMTRSTS (Bit 0)                                       */
#define R_CANFD_CFDTMTRSTS_TMTRSTS_Msk      (0xffffffffUL) /*!< TMTRSTS (Bitfield-Mask: 0xffffffff)                   */
/* ======================================================  CFDTMTARSTS  ====================================================== */
#define R_CANFD_CFDTMTARSTS_TMTARSTS_Pos    (0UL)          /*!< TMTARSTS (Bit 0)                                      */
#define R_CANFD_CFDTMTARSTS_TMTARSTS_Msk    (0xffffffffUL) /*!< TMTARSTS (Bitfield-Mask: 0xffffffff)                  */
/* ======================================================  CFDTMTCSTS  ======================================================= */
#define R_CANFD_CFDTMTCSTS_TMTCSTS_Pos      (0UL)          /*!< TMTCSTS (Bit 0)                                       */
#define R_CANFD_CFDTMTCSTS_TMTCSTS_Msk      (0xffffffffUL) /*!< TMTCSTS (Bitfield-Mask: 0xffffffff)                   */
/* ======================================================  CFDTMTASTS  ======================================================= */
#define R_CANFD_CFDTMTASTS_TMTASTS_Pos      (0UL)          /*!< TMTASTS (Bit 0)                                       */
#define R_CANFD_CFDTMTASTS_TMTASTS_Msk      (0xffffffffUL) /*!< TMTASTS (Bitfield-Mask: 0xffffffff)                   */
/* =======================================================  CFDTMIEC  ======================================================== */
#define R_CANFD_CFDTMIEC_TMIE_Pos           (0UL)          /*!< TMIE (Bit 0)                                          */
#define R_CANFD_CFDTMIEC_TMIE_Msk           (0xffffffffUL) /*!< TMIE (Bitfield-Mask: 0xffffffff)                      */
/* =======================================================  CFDTXQCC0  ======================================================= */
#define R_CANFD_CFDTXQCC0_TXQE_Pos          (0UL)          /*!< TXQE (Bit 0)                                          */
#define R_CANFD_CFDTXQCC0_TXQE_Msk          (0x1UL)        /*!< TXQE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDTXQCC0_TXQDC_Pos         (8UL)          /*!< TXQDC (Bit 8)                                         */
#define R_CANFD_CFDTXQCC0_TXQDC_Msk         (0xf00UL)      /*!< TXQDC (Bitfield-Mask: 0x1f)                           */
#define R_CANFD_CFDTXQCC0_TXQIE_Pos         (12UL)         /*!< TXQIE (Bit 12)                                        */
#define R_CANFD_CFDTXQCC0_TXQIE_Msk         (0x20UL)       /*!< TXQIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTXQCC0_TXQIM_Pos         (13UL)         /*!< TXQIM (Bit 13)                                        */
#define R_CANFD_CFDTXQCC0_TXQIM_Msk         (0x80UL)       /*!< TXQIM (Bitfield-Mask: 0x01)                           */
/* ======================================================  CFDTXQSTS0  ======================================================= */
#define R_CANFD_CFDTXQSTS0_TXQEMP_Pos       (0UL)          /*!< TXQEMP (Bit 0)                                        */
#define R_CANFD_CFDTXQSTS0_TXQEMP_Msk       (0x1UL)        /*!< TXQEMP (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS0_TXQFLL_Pos       (1UL)          /*!< TXQFLL (Bit 1)                                        */
#define R_CANFD_CFDTXQSTS0_TXQFLL_Msk       (0x2UL)        /*!< TXQFLL (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS0_TXQIF_Pos        (2UL)          /*!< TXQIF (Bit 2)                                         */
#define R_CANFD_CFDTXQSTS0_TXQIF_Msk        (0x4UL)        /*!< TXQIF (Bitfield-Mask: 0x01)                           */
/* ======================================================  CFDTXQPCTR0  ====================================================== */
#define R_CANFD_CFDTXQPCTR0_TXQPC_Pos       (0UL)          /*!< TXQPC (Bit 0)                                         */
#define R_CANFD_CFDTXQPCTR0_TXQPC_Msk       (0xffUL)       /*!< TXQPC (Bitfield-Mask: 0xff)                           */
/* =======================================================  CFDTHLCC  ======================================================== */
#define R_CANFD_CFDTHLCC_THLE_Pos           (0UL)          /*!< THLE (Bit 0)                                          */
#define R_CANFD_CFDTHLCC_THLE_Msk           (0x1UL)        /*!< THLE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDTHLCC_THLIE_Pos          (8UL)          /*!< THLIE (Bit 8)                                         */
#define R_CANFD_CFDTHLCC_THLIE_Msk          (0x100UL)      /*!< THLIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTHLCC_THLIM_Pos          (9UL)          /*!< THLIM (Bit 9)                                         */
#define R_CANFD_CFDTHLCC_THLIM_Msk          (0x200UL)      /*!< THLIM (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTHLCC_THLDTE_Pos         (10UL)         /*!< THLDTE (Bit 10)                                       */
#define R_CANFD_CFDTHLCC_THLDTE_Msk         (0x400UL)      /*!< THLDTE (Bitfield-Mask: 0x01)                          */
/* =======================================================  CFDTHLSTS  ======================================================= */
#define R_CANFD_CFDTHLSTS_THLEMP_Pos        (0UL)          /*!< THLEMP (Bit 0)                                        */
#define R_CANFD_CFDTHLSTS_THLEMP_Msk        (0x1UL)        /*!< THLEMP (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTHLSTS_THLFLL_Pos        (1UL)          /*!< THLFLL (Bit 1)                                        */
#define R_CANFD_CFDTHLSTS_THLFLL_Msk        (0x2UL)        /*!< THLFLL (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTHLSTS_THLELT_Pos        (2UL)          /*!< THLELT (Bit 2)                                        */
#define R_CANFD_CFDTHLSTS_THLELT_Msk        (0x4UL)        /*!< THLELT (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTHLSTS_THLIF_Pos         (3UL)          /*!< THLIF (Bit 3)                                         */
#define R_CANFD_CFDTHLSTS_THLIF_Msk         (0x8UL)        /*!< THLIF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTHLSTS_THLMC_Pos         (8UL)          /*!< THLMC (Bit 8)                                         */
#define R_CANFD_CFDTHLSTS_THLMC_Msk         (0x1f00UL)     /*!< THLMC (Bitfield-Mask: 0x1f)                           */
/* ======================================================  CFDTHLPCTR  ======================================================= */
#define R_CANFD_CFDTHLPCTR_THLPC_Pos        (0UL)          /*!< THLPC (Bit 0)                                         */
#define R_CANFD_CFDTHLPCTR_THLPC_Msk        (0xffUL)       /*!< THLPC (Bitfield-Mask: 0xff)                           */
/* =====================================================  CFDGTINTSTS0  ====================================================== */
#define R_CANFD_CFDGTINTSTS0_TSIF0_Pos      (0UL)          /*!< TSIF0 (Bit 0)                                         */
#define R_CANFD_CFDGTINTSTS0_TSIF0_Msk      (0x1UL)        /*!< TSIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TAIF0_Pos      (1UL)          /*!< TAIF0 (Bit 1)                                         */
#define R_CANFD_CFDGTINTSTS0_TAIF0_Msk      (0x2UL)        /*!< TAIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQIF0_Pos      (2UL)          /*!< TQIF0 (Bit 2)                                         */
#define R_CANFD_CFDGTINTSTS0_TQIF0_Msk      (0x4UL)        /*!< TQIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_CFTIF0_Pos     (3UL)          /*!< CFTIF0 (Bit 3)                                        */
#define R_CANFD_CFDGTINTSTS0_CFTIF0_Msk     (0x8UL)        /*!< CFTIF0 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGTINTSTS0_THIF0_Pos      (4UL)          /*!< THIF0 (Bit 4)                                         */
#define R_CANFD_CFDGTINTSTS0_THIF0_Msk      (0x10UL)       /*!< THIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TSIF1_Pos      (8UL)          /*!< TSIF1 (Bit 8)                                         */
#define R_CANFD_CFDGTINTSTS0_TSIF1_Msk      (0x100UL)      /*!< TSIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TAIF1_Pos      (9UL)          /*!< TAIF1 (Bit 9)                                         */
#define R_CANFD_CFDGTINTSTS0_TAIF1_Msk      (0x200UL)      /*!< TAIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQIF1_Pos      (10UL)         /*!< TQIF1 (Bit 10)                                        */
#define R_CANFD_CFDGTINTSTS0_TQIF1_Msk      (0x400UL)      /*!< TQIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_CFTIF1_Pos     (11UL)         /*!< CFTIF1 (Bit 11)                                       */
#define R_CANFD_CFDGTINTSTS0_CFTIF1_Msk     (0x800UL)      /*!< CFTIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGTINTSTS0_THIF1_Pos      (12UL)         /*!< THIF1 (Bit 12)                                        */
#define R_CANFD_CFDGTINTSTS0_THIF1_Msk      (0x1000UL)     /*!< THIF1 (Bitfield-Mask: 0x01)                           */
/* ======================================================  CFDGTSTCFG  ======================================================= */
#define R_CANFD_CFDGTSTCFG_C0ICBCE_Pos      (0UL)          /*!< C0ICBCE (Bit 0)                                       */
#define R_CANFD_CFDGTSTCFG_C0ICBCE_Msk      (0x1UL)        /*!< C0ICBCE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCFG_C1ICBCE_Pos      (1UL)          /*!< C1ICBCE (Bit 1)                                       */
#define R_CANFD_CFDGTSTCFG_C1ICBCE_Msk      (0x2UL)        /*!< C1ICBCE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCFG_RTMPS_Pos        (16UL)         /*!< RTMPS (Bit 16)                                        */
#define R_CANFD_CFDGTSTCFG_RTMPS_Msk        (0x3ff0000UL)  /*!< RTMPS (Bitfield-Mask: 0x3f)                           */
/* ======================================================  CFDGTSTCTR  ======================================================= */
#define R_CANFD_CFDGTSTCTR_ICBCTME_Pos      (0UL)          /*!< ICBCTME (Bit 0)                                       */
#define R_CANFD_CFDGTSTCTR_ICBCTME_Msk      (0x1UL)        /*!< ICBCTME (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCTR_RTME_Pos         (2UL)          /*!< RTME (Bit 2)                                          */
#define R_CANFD_CFDGTSTCTR_RTME_Msk         (0x4UL)        /*!< RTME (Bitfield-Mask: 0x01)                            */
/* =======================================================  CFDGFDCFG  ======================================================= */
#define R_CANFD_CFDGFDCFG_RPED_Pos          (0UL)          /*!< RPED (Bit 0)                                          */
#define R_CANFD_CFDGFDCFG_RPED_Msk          (0x1UL)        /*!< RPED (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGFDCFG_TSCCFG_Pos        (8UL)          /*!< TSCCFG (Bit 8)                                        */
#define R_CANFD_CFDGFDCFG_TSCCFG_Msk        (0x300UL)      /*!< TSCCFG (Bitfield-Mask: 0x03)                          */
/* =======================================================  CFDGLOCKK  ======================================================= */
#define R_CANFD_CFDGLOCKK_LOCK_Pos          (0UL)          /*!< LOCK (Bit 0)                                          */
#define R_CANFD_CFDGLOCKK_LOCK_Msk          (0xffffUL)     /*!< LOCK (Bitfield-Mask: 0xffff)                          */
/* =======================================================  CFDCDTCT  ======================================================== */
#define R_CANFD_CFDCDTCT_RFDMAE0_Pos        (0UL)          /*!< RFDMAE0 (Bit 0)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE0_Msk        (0x1UL)        /*!< RFDMAE0 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE1_Pos        (1UL)          /*!< RFDMAE1 (Bit 1)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE1_Msk        (0x2UL)        /*!< RFDMAE1 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE2_Pos        (2UL)          /*!< RFDMAE2 (Bit 2)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE2_Msk        (0x4UL)        /*!< RFDMAE2 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE3_Pos        (3UL)          /*!< RFDMAE3 (Bit 3)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE3_Msk        (0x8UL)        /*!< RFDMAE3 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE4_Pos        (4UL)          /*!< RFDMAE4 (Bit 4)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE4_Msk        (0x10UL)       /*!< RFDMAE4 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE5_Pos        (5UL)          /*!< RFDMAE5 (Bit 5)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE5_Msk        (0x20UL)       /*!< RFDMAE5 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE6_Pos        (6UL)          /*!< RFDMAE6 (Bit 6)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE6_Msk        (0x40UL)       /*!< RFDMAE6 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE7_Pos        (7UL)          /*!< RFDMAE7 (Bit 7)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE7_Msk        (0x80UL)       /*!< RFDMAE7 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_CFDMAE0_Pos        (8UL)          /*!< CFDMAE0 (Bit 8)                                       */
#define R_CANFD_CFDCDTCT_CFDMAE0_Msk        (0x100UL)      /*!< CFDMAE0 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_CFDMAE1_Pos        (9UL)          /*!< CFDMAE1 (Bit 9)                                       */
#define R_CANFD_CFDCDTCT_CFDMAE1_Msk        (0x200UL)      /*!< CFDMAE1 (Bitfield-Mask: 0x01)                         */
/* =======================================================  CFDCDTSTS  ======================================================= */
#define R_CANFD_CFDCDTSTS_RFDMASTS0_Pos     (0UL)          /*!< RFDMASTS0 (Bit 0)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS0_Msk     (0x1UL)        /*!< RFDMASTS0 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS1_Pos     (1UL)          /*!< RFDMASTS1 (Bit 1)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS1_Msk     (0x2UL)        /*!< RFDMASTS1 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS2_Pos     (2UL)          /*!< RFDMASTS2 (Bit 2)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS2_Msk     (0x4UL)        /*!< RFDMASTS2 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS3_Pos     (3UL)          /*!< RFDMASTS3 (Bit 3)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS3_Msk     (0x8UL)        /*!< RFDMASTS3 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS4_Pos     (4UL)          /*!< RFDMASTS4 (Bit 4)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS4_Msk     (0x10UL)       /*!< RFDMASTS4 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS5_Pos     (5UL)          /*!< RFDMASTS5 (Bit 5)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS5_Msk     (0x20UL)       /*!< RFDMASTS5 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS6_Pos     (6UL)          /*!< RFDMASTS6 (Bit 6)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS6_Msk     (0x40UL)       /*!< RFDMASTS6 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS7_Pos     (7UL)          /*!< RFDMASTS7 (Bit 7)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS7_Msk     (0x80UL)       /*!< RFDMASTS7 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_CFDMASTS0_Pos     (8UL)          /*!< CFDMASTS0 (Bit 8)                                     */
#define R_CANFD_CFDCDTSTS_CFDMASTS0_Msk     (0x100UL)      /*!< CFDMASTS0 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_CFDMASTS1_Pos     (9UL)          /*!< CFDMASTS1 (Bit 9)                                     */
#define R_CANFD_CFDCDTSTS_CFDMASTS1_Msk     (0x200UL)      /*!< CFDMASTS1 (Bitfield-Mask: 0x01)                       */
/* =======================================================  CFDRPGACC  ======================================================= */
#define R_CANFD_CFDRPGACC_RDTA_Pos          (0UL)          /*!< RDTA (Bit 0)                                          */
#define R_CANFD_CFDRPGACC_RDTA_Msk          (0xffffffffUL) /*!< RDTA (Bitfield-Mask: 0xffffffff)                      */

#endif
