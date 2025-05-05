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
#define R_CANFD_CFDC_NCFG_NBRP_Pos      (0UL)          /*!< NBRP (Bit 0)                                          */
#define R_CANFD_CFDC_NCFG_NBRP_Msk      (0x3ffUL)      /*!< NBRP (Bitfield-Mask: 0x3ff)                           */
#define R_CANFD_CFDC_NCFG_NSJW_Pos      (10UL)         /*!< NSJW (Bit 10)                                         */
#define R_CANFD_CFDC_NCFG_NSJW_Msk      (0x1fc00UL)    /*!< NSJW (Bitfield-Mask: 0x7f)                            */
#define R_CANFD_CFDC_NCFG_NTSEG1_Pos    (17UL)         /*!< NTSEG1 (Bit 17)                                       */
#define R_CANFD_CFDC_NCFG_NTSEG1_Msk    (0x1fe0000UL)  /*!< NTSEG1 (Bitfield-Mask: 0xff)                          */
#define R_CANFD_CFDC_NCFG_NTSEG2_Pos    (25UL)         /*!< NTSEG2 (Bit 25)                                       */
#define R_CANFD_CFDC_NCFG_NTSEG2_Msk    (0xfe000000UL) /*!< NTSEG2 (Bitfield-Mask: 0x7f)                          */
/* ==========================================================  CTR  ========================================================== */
#define R_CANFD_CFDC_CTR_CHMDC_Pos      (0UL)          /*!< CHMDC (Bit 0)                                         */
#define R_CANFD_CFDC_CTR_CHMDC_Msk      (0x3UL)        /*!< CHMDC (Bitfield-Mask: 0x03)                           */
#define R_CANFD_CFDC_CTR_CSLPR_Pos      (2UL)          /*!< CSLPR (Bit 2)                                         */
#define R_CANFD_CFDC_CTR_CSLPR_Msk      (0x4UL)        /*!< CSLPR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CTR_RTBO_Pos       (3UL)          /*!< RTBO (Bit 3)                                          */
#define R_CANFD_CFDC_CTR_RTBO_Msk       (0x8UL)        /*!< RTBO (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_BEIE_Pos       (8UL)          /*!< BEIE (Bit 8)                                          */
#define R_CANFD_CFDC_CTR_BEIE_Msk       (0x100UL)      /*!< BEIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_EWIE_Pos       (9UL)          /*!< EWIE (Bit 9)                                          */
#define R_CANFD_CFDC_CTR_EWIE_Msk       (0x200UL)      /*!< EWIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_EPIE_Pos       (10UL)         /*!< EPIE (Bit 10)                                         */
#define R_CANFD_CFDC_CTR_EPIE_Msk       (0x400UL)      /*!< EPIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_BOEIE_Pos      (11UL)         /*!< BOEIE (Bit 11)                                        */
#define R_CANFD_CFDC_CTR_BOEIE_Msk      (0x800UL)      /*!< BOEIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CTR_BORIE_Pos      (12UL)         /*!< BORIE (Bit 12)                                        */
#define R_CANFD_CFDC_CTR_BORIE_Msk      (0x1000UL)     /*!< BORIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_CTR_OLIE_Pos       (13UL)         /*!< OLIE (Bit 13)                                         */
#define R_CANFD_CFDC_CTR_OLIE_Msk       (0x2000UL)     /*!< OLIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_BLIE_Pos       (14UL)         /*!< BLIE (Bit 14)                                         */
#define R_CANFD_CFDC_CTR_BLIE_Msk       (0x4000UL)     /*!< BLIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_ALIE_Pos       (15UL)         /*!< ALIE (Bit 15)                                         */
#define R_CANFD_CFDC_CTR_ALIE_Msk       (0x8000UL)     /*!< ALIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_TAIE_Pos       (16UL)         /*!< TAIE (Bit 16)                                         */
#define R_CANFD_CFDC_CTR_TAIE_Msk       (0x10000UL)    /*!< TAIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_EOCOIE_Pos     (17UL)         /*!< EOCOIE (Bit 17)                                       */
#define R_CANFD_CFDC_CTR_EOCOIE_Msk     (0x20000UL)    /*!< EOCOIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC_CTR_SOCOIE_Pos     (18UL)         /*!< SOCOIE (Bit 18)                                       */
#define R_CANFD_CFDC_CTR_SOCOIE_Msk     (0x40000UL)    /*!< SOCOIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC_CTR_TDCVFIE_Pos    (19UL)         /*!< TDCVFIE (Bit 19)                                      */
#define R_CANFD_CFDC_CTR_TDCVFIE_Msk    (0x80000UL)    /*!< TDCVFIE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDC_CTR_BOM_Pos        (21UL)         /*!< BOM (Bit 21)                                          */
#define R_CANFD_CFDC_CTR_BOM_Msk        (0x600000UL)   /*!< BOM (Bitfield-Mask: 0x03)                             */
#define R_CANFD_CFDC_CTR_ERRD_Pos       (23UL)         /*!< ERRD (Bit 23)                                         */
#define R_CANFD_CFDC_CTR_ERRD_Msk       (0x800000UL)   /*!< ERRD (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_CTME_Pos       (24UL)         /*!< CTME (Bit 24)                                         */
#define R_CANFD_CFDC_CTR_CTME_Msk       (0x1000000UL)  /*!< CTME (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_CTMS_Pos       (25UL)         /*!< CTMS (Bit 25)                                         */
#define R_CANFD_CFDC_CTR_CTMS_Msk       (0x6000000UL)  /*!< CTMS (Bitfield-Mask: 0x03)                            */
#define R_CANFD_CFDC_CTR_CRCT_Pos       (30UL)         /*!< CRCT (Bit 30)                                         */
#define R_CANFD_CFDC_CTR_CRCT_Msk       (0x40000000UL) /*!< CRCT (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_CTR_ROM_Pos        (31UL)         /*!< ROM (Bit 31)                                          */
#define R_CANFD_CFDC_CTR_ROM_Msk        (0x80000000UL) /*!< ROM (Bitfield-Mask: 0x01)                             */
/* ==========================================================  STS  ========================================================== */
#define R_CANFD_CFDC_STS_CRSTSTS_Pos    (0UL)          /*!< CRSTSTS (Bit 0)                                       */
#define R_CANFD_CFDC_STS_CRSTSTS_Msk    (0x1UL)        /*!< CRSTSTS (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDC_STS_CHLTSTS_Pos    (1UL)          /*!< CHLTSTS (Bit 1)                                       */
#define R_CANFD_CFDC_STS_CHLTSTS_Msk    (0x2UL)        /*!< CHLTSTS (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDC_STS_CSLPSTS_Pos    (2UL)          /*!< CSLPSTS (Bit 2)                                       */
#define R_CANFD_CFDC_STS_CSLPSTS_Msk    (0x4UL)        /*!< CSLPSTS (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDC_STS_EPSTS_Pos      (3UL)          /*!< EPSTS (Bit 3)                                         */
#define R_CANFD_CFDC_STS_EPSTS_Msk      (0x8UL)        /*!< EPSTS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_STS_BOSTS_Pos      (4UL)          /*!< BOSTS (Bit 4)                                         */
#define R_CANFD_CFDC_STS_BOSTS_Msk      (0x10UL)       /*!< BOSTS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_STS_TRMSTS_Pos     (5UL)          /*!< TRMSTS (Bit 5)                                        */
#define R_CANFD_CFDC_STS_TRMSTS_Msk     (0x20UL)       /*!< TRMSTS (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC_STS_RECSTS_Pos     (6UL)          /*!< RECSTS (Bit 6)                                        */
#define R_CANFD_CFDC_STS_RECSTS_Msk     (0x40UL)       /*!< RECSTS (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC_STS_COMSTS_Pos     (7UL)          /*!< COMSTS (Bit 7)                                        */
#define R_CANFD_CFDC_STS_COMSTS_Msk     (0x80UL)       /*!< COMSTS (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC_STS_ESIF_Pos       (8UL)          /*!< ESIF (Bit 8)                                          */
#define R_CANFD_CFDC_STS_ESIF_Msk       (0x100UL)      /*!< ESIF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_STS_REC_Pos        (16UL)         /*!< REC (Bit 16)                                          */
#define R_CANFD_CFDC_STS_REC_Msk        (0xff0000UL)   /*!< REC (Bitfield-Mask: 0xff)                             */
#define R_CANFD_CFDC_STS_TEC_Pos        (24UL)         /*!< TEC (Bit 24)                                          */
#define R_CANFD_CFDC_STS_TEC_Msk        (0xff000000UL) /*!< TEC (Bitfield-Mask: 0xff)                             */
/* =========================================================  ERFL  ========================================================== */
#define R_CANFD_CFDC_ERFL_BEF_Pos       (0UL)          /*!< BEF (Bit 0)                                           */
#define R_CANFD_CFDC_ERFL_BEF_Msk       (0x1UL)        /*!< BEF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_ERFL_EWF_Pos       (1UL)          /*!< EWF (Bit 1)                                           */
#define R_CANFD_CFDC_ERFL_EWF_Msk       (0x2UL)        /*!< EWF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_ERFL_EPF_Pos       (2UL)          /*!< EPF (Bit 2)                                           */
#define R_CANFD_CFDC_ERFL_EPF_Msk       (0x4UL)        /*!< EPF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_ERFL_BOEF_Pos      (3UL)          /*!< BOEF (Bit 3)                                          */
#define R_CANFD_CFDC_ERFL_BOEF_Msk      (0x8UL)        /*!< BOEF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_ERFL_BORF_Pos      (4UL)          /*!< BORF (Bit 4)                                          */
#define R_CANFD_CFDC_ERFL_BORF_Msk      (0x10UL)       /*!< BORF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_ERFL_OVLF_Pos      (5UL)          /*!< OVLF (Bit 5)                                          */
#define R_CANFD_CFDC_ERFL_OVLF_Msk      (0x20UL)       /*!< OVLF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_ERFL_BLF_Pos       (6UL)          /*!< BLF (Bit 6)                                           */
#define R_CANFD_CFDC_ERFL_BLF_Msk       (0x40UL)       /*!< BLF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_ERFL_ALF_Pos       (7UL)          /*!< ALF (Bit 7)                                           */
#define R_CANFD_CFDC_ERFL_ALF_Msk       (0x80UL)       /*!< ALF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDC_ERFL_SERR_Pos      (8UL)          /*!< SERR (Bit 8)                                          */
#define R_CANFD_CFDC_ERFL_SERR_Msk      (0x100UL)      /*!< SERR (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_ERFL_FERR_Pos      (9UL)          /*!< FERR (Bit 9)                                          */
#define R_CANFD_CFDC_ERFL_FERR_Msk      (0x200UL)      /*!< FERR (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_ERFL_AERR_Pos      (10UL)         /*!< AERR (Bit 10)                                         */
#define R_CANFD_CFDC_ERFL_AERR_Msk      (0x400UL)      /*!< AERR (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_ERFL_CERR_Pos      (11UL)         /*!< CERR (Bit 11)                                         */
#define R_CANFD_CFDC_ERFL_CERR_Msk      (0x800UL)      /*!< CERR (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC_ERFL_B1ERR_Pos     (12UL)         /*!< B1ERR (Bit 12)                                        */
#define R_CANFD_CFDC_ERFL_B1ERR_Msk     (0x1000UL)     /*!< B1ERR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_ERFL_B0ERR_Pos     (13UL)         /*!< B0ERR (Bit 13)                                        */
#define R_CANFD_CFDC_ERFL_B0ERR_Msk     (0x2000UL)     /*!< B0ERR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_ERFL_ADERR_Pos     (14UL)         /*!< ADERR (Bit 14)                                        */
#define R_CANFD_CFDC_ERFL_ADERR_Msk     (0x4000UL)     /*!< ADERR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC_ERFL_CRCREG_Pos    (16UL)         /*!< CRCREG (Bit 16)                                       */
#define R_CANFD_CFDC_ERFL_CRCREG_Msk    (0x7fff0000UL) /*!< CRCREG (Bitfield-Mask: 0x7fff)                        */

/* =========================================================================================================================== */
/* ================                                           CFDC2                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  DCFG  ========================================================== */
#define R_CANFD_CFDC2_DCFG_DBRP_Pos       (0UL)          /*!< DBRP (Bit 0)                                          */
#define R_CANFD_CFDC2_DCFG_DBRP_Msk       (0xffUL)       /*!< DBRP (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFDC2_DCFG_DTSEG1_Pos     (8UL)          /*!< DTSEG1 (Bit 8)                                        */
#define R_CANFD_CFDC2_DCFG_DTSEG1_Msk     (0x1f00UL)     /*!< DTSEG1 (Bitfield-Mask: 0x1f)                          */
#define R_CANFD_CFDC2_DCFG_DTSEG2_Pos     (16UL)         /*!< DTSEG2 (Bit 16)                                       */
#define R_CANFD_CFDC2_DCFG_DTSEG2_Msk     (0xf0000UL)    /*!< DTSEG2 (Bitfield-Mask: 0x0f)                          */
#define R_CANFD_CFDC2_DCFG_DSJW_Pos       (24UL)         /*!< DSJW (Bit 24)                                         */
#define R_CANFD_CFDC2_DCFG_DSJW_Msk       (0xf000000UL)  /*!< DSJW (Bitfield-Mask: 0x0f)                            */
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
#define R_CANFD_CFDC2_FDCFG_TDCO_Msk      (0xff0000UL)   /*!< TDCO (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFDC2_FDCFG_GWEN_Pos      (24UL)         /*!< GWEN (Bit 24)                                         */
#define R_CANFD_CFDC2_FDCFG_GWEN_Msk      (0x1000000UL)  /*!< GWEN (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_GWFDF_Pos     (25UL)         /*!< GWFDF (Bit 25)                                        */
#define R_CANFD_CFDC2_FDCFG_GWFDF_Msk     (0x2000000UL)  /*!< GWFDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC2_FDCFG_GWBRS_Pos     (26UL)         /*!< GWBRS (Bit 26)                                        */
#define R_CANFD_CFDC2_FDCFG_GWBRS_Msk     (0x4000000UL)  /*!< GWBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC2_FDCFG_FDOE_Pos      (28UL)         /*!< FDOE (Bit 28)                                         */
#define R_CANFD_CFDC2_FDCFG_FDOE_Msk      (0x10000000UL) /*!< FDOE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_REFE_Pos      (29UL)         /*!< REFE (Bit 29)                                         */
#define R_CANFD_CFDC2_FDCFG_REFE_Msk      (0x20000000UL) /*!< REFE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_CLOE_Pos      (30UL)         /*!< CLOE (Bit 30)                                         */
#define R_CANFD_CFDC2_FDCFG_CLOE_Msk      (0x40000000UL) /*!< CLOE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDCFG_CFDTE_Pos     (31UL)         /*!< CFDTE (Bit 31)                                        */
#define R_CANFD_CFDC2_FDCFG_CFDTE_Msk     (0x80000000UL) /*!< CFDTE (Bitfield-Mask: 0x01)                           */
/* =========================================================  FDCTR  ========================================================= */
#define R_CANFD_CFDC2_FDCTR_EOCCLR_Pos    (0UL)          /*!< EOCCLR (Bit 0)                                        */
#define R_CANFD_CFDC2_FDCTR_EOCCLR_Msk    (0x1UL)        /*!< EOCCLR (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDC2_FDCTR_SOCCLR_Pos    (1UL)          /*!< SOCCLR (Bit 1)                                        */
#define R_CANFD_CFDC2_FDCTR_SOCCLR_Msk    (0x2UL)        /*!< SOCCLR (Bitfield-Mask: 0x01)                          */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFD_CFDC2_FDSTS_TDCR_Pos      (0UL)          /*!< TDCR (Bit 0)                                          */
#define R_CANFD_CFDC2_FDSTS_TDCR_Msk      (0xffUL)       /*!< TDCR (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFDC2_FDSTS_EOCO_Pos      (8UL)          /*!< EOCO (Bit 8)                                          */
#define R_CANFD_CFDC2_FDSTS_EOCO_Msk      (0x100UL)      /*!< EOCO (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDSTS_SOCO_Pos      (9UL)          /*!< SOCO (Bit 9)                                          */
#define R_CANFD_CFDC2_FDSTS_SOCO_Msk      (0x200UL)      /*!< SOCO (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_FDSTS_TDCVF_Pos     (15UL)         /*!< TDCVF (Bit 15)                                        */
#define R_CANFD_CFDC2_FDSTS_TDCVF_Msk     (0x8000UL)     /*!< TDCVF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDC2_FDSTS_EOC_Pos       (16UL)         /*!< EOC (Bit 16)                                          */
#define R_CANFD_CFDC2_FDSTS_EOC_Msk       (0xff0000UL)   /*!< EOC (Bitfield-Mask: 0xff)                             */
#define R_CANFD_CFDC2_FDSTS_SOC_Pos       (24UL)         /*!< SOC (Bit 24)                                          */
#define R_CANFD_CFDC2_FDSTS_SOC_Msk       (0xff000000UL) /*!< SOC (Bitfield-Mask: 0xff)                             */
/* =========================================================  FDCRC  ========================================================= */
#define R_CANFD_CFDC2_FDCRC_CRCREG_Pos    (0UL)          /*!< CRCREG (Bit 0)                                        */
#define R_CANFD_CFDC2_FDCRC_CRCREG_Msk    (0x1fffffUL)   /*!< CRCREG (Bitfield-Mask: 0x1fffff)                      */
#define R_CANFD_CFDC2_FDCRC_SCNT_Pos      (25UL)         /*!< SCNT (Bit 25)                                         */
#define R_CANFD_CFDC2_FDCRC_SCNT_Msk      (0x1e000000UL) /*!< SCNT (Bitfield-Mask: 0x0f)                            */
/* =========================================================  BLCT  ========================================================== */
#define R_CANFD_CFDC2_BLCT_BLCE_Pos       (0UL)          /*!< BLCE (Bit 0)                                          */
#define R_CANFD_CFDC2_BLCT_BLCE_Msk       (0x1UL)        /*!< BLCE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDC2_BLCT_BLCLD_Pos      (8UL)          /*!< BLCLD (Bit 8)                                         */
#define R_CANFD_CFDC2_BLCT_BLCLD_Msk      (0x100UL)      /*!< BLCLD (Bitfield-Mask: 0x01)                           */
/* =========================================================  BLSTS  ========================================================= */
#define R_CANFD_CFDC2_BLSTS_BLC_Pos       (3UL)          /*!< BLC (Bit 3)                                           */
#define R_CANFD_CFDC2_BLSTS_BLC_Msk       (0xfffffff8UL) /*!< BLC (Bitfield-Mask: 0x1fffffff)                       */

/* =========================================================================================================================== */
/* ================                                          CFDGAFL                                          ================ */
/* =========================================================================================================================== */

/* ==========================================================  ID  =========================================================== */
#define R_CANFD_CFDGAFL_ID_GAFLID_Pos      (0UL)          /*!< GAFLID (Bit 0)                                        */
#define R_CANFD_CFDGAFL_ID_GAFLID_Msk      (0x1fffffffUL) /*!< GAFLID (Bitfield-Mask: 0x1fffffff)                    */
#define R_CANFD_CFDGAFL_ID_GAFLLB_Pos      (29UL)         /*!< GAFLLB (Bit 29)                                       */
#define R_CANFD_CFDGAFL_ID_GAFLLB_Msk      (0x20000000UL) /*!< GAFLLB (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGAFL_ID_GAFLRTR_Pos     (30UL)         /*!< GAFLRTR (Bit 30)                                      */
#define R_CANFD_CFDGAFL_ID_GAFLRTR_Msk     (0x40000000UL) /*!< GAFLRTR (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGAFL_ID_GAFLIDE_Pos     (31UL)         /*!< GAFLIDE (Bit 31)                                      */
#define R_CANFD_CFDGAFL_ID_GAFLIDE_Msk     (0x80000000UL) /*!< GAFLIDE (Bitfield-Mask: 0x01)                         */
/* ===========================================================  M  =========================================================== */
#define R_CANFD_CFDGAFL_M_GAFLIDM_Pos      (0UL)          /*!< GAFLIDM (Bit 0)                                       */
#define R_CANFD_CFDGAFL_M_GAFLIDM_Msk      (0x1fffffffUL) /*!< GAFLIDM (Bitfield-Mask: 0x1fffffff)                   */
#define R_CANFD_CFDGAFL_M_GAFLIFL1_Pos     (29UL)         /*!< GAFLIFL1 (Bit 29)                                     */
#define R_CANFD_CFDGAFL_M_GAFLIFL1_Msk     (0x20000000UL) /*!< GAFLIFL1 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDGAFL_M_GAFLRTRM_Pos     (30UL)         /*!< GAFLRTRM (Bit 30)                                     */
#define R_CANFD_CFDGAFL_M_GAFLRTRM_Msk     (0x40000000UL) /*!< GAFLRTRM (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDGAFL_M_GAFLIDEM_Pos     (31UL)         /*!< GAFLIDEM (Bit 31)                                     */
#define R_CANFD_CFDGAFL_M_GAFLIDEM_Msk     (0x80000000UL) /*!< GAFLIDEM (Bitfield-Mask: 0x01)                        */
/* ==========================================================  P0  =========================================================== */
#define R_CANFD_CFDGAFL_P0_GAFLDLC_Pos     (0UL)          /*!< GAFLDLC (Bit 0)                                       */
#define R_CANFD_CFDGAFL_P0_GAFLDLC_Msk     (0xfUL)        /*!< GAFLDLC (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDGAFL_P0_GAFLSRD0_Pos    (4UL)          /*!< GAFLSRD0 (Bit 4)                                      */
#define R_CANFD_CFDGAFL_P0_GAFLSRD0_Msk    (0x10UL)       /*!< GAFLSRD0 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDGAFL_P0_GAFLSRD1_Pos    (5UL)          /*!< GAFLSRD1 (Bit 5)                                      */
#define R_CANFD_CFDGAFL_P0_GAFLSRD1_Msk    (0x20UL)       /*!< GAFLSRD1 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDGAFL_P0_GAFLSRD2_Pos    (6UL)          /*!< GAFLSRD2 (Bit 6)                                      */
#define R_CANFD_CFDGAFL_P0_GAFLSRD2_Msk    (0x40UL)       /*!< GAFLSRD2 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDGAFL_P0_GAFLIFL0_Pos    (7UL)          /*!< GAFLIFL0 (Bit 7)                                      */
#define R_CANFD_CFDGAFL_P0_GAFLIFL0_Msk    (0x80UL)       /*!< GAFLIFL0 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDGAFL_P0_GAFLRMDP_Pos    (8UL)          /*!< GAFLRMDP (Bit 8)                                      */
#define R_CANFD_CFDGAFL_P0_GAFLRMDP_Msk    (0x1f00UL)     /*!< GAFLRMDP (Bitfield-Mask: 0x1f)                        */
#define R_CANFD_CFDGAFL_P0_GAFLRMV_Pos     (15UL)         /*!< GAFLRMV (Bit 15)                                      */
#define R_CANFD_CFDGAFL_P0_GAFLRMV_Msk     (0x8000UL)     /*!< GAFLRMV (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGAFL_P0_GAFLPTR_Pos     (16UL)         /*!< GAFLPTR (Bit 16)                                      */
#define R_CANFD_CFDGAFL_P0_GAFLPTR_Msk     (0xffff0000UL) /*!< GAFLPTR (Bitfield-Mask: 0xffff)                       */
/* ==========================================================  P1  =========================================================== */
#define R_CANFD_CFDGAFL_P1_GAFLFDP_Pos     (0UL)          /*!< GAFLFDP (Bit 0)                                       */
#define R_CANFD_CFDGAFL_P1_GAFLFDP_Msk     (0x3ffffffUL)  /*!< GAFLFDP (Bitfield-Mask: 0x3ffffff)                    */

/* =========================================================================================================================== */
/* ================                                          CFDTHL                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  ACC0  ========================================================== */
#define R_CANFD_CFDTHL_ACC0_BT_Pos      (0UL)          /*!< BT (Bit 0)                                            */
#define R_CANFD_CFDTHL_ACC0_BT_Msk      (0x7UL)        /*!< BT (Bitfield-Mask: 0x07)                              */
#define R_CANFD_CFDTHL_ACC0_BN_Pos      (3UL)          /*!< BN (Bit 3)                                            */
#define R_CANFD_CFDTHL_ACC0_BN_Msk      (0x3f8UL)      /*!< BN (Bitfield-Mask: 0x7f)                              */
#define R_CANFD_CFDTHL_ACC0_TGW_Pos     (15UL)         /*!< TGW (Bit 15)                                          */
#define R_CANFD_CFDTHL_ACC0_TGW_Msk     (0x8000UL)     /*!< TGW (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDTHL_ACC0_TMTS_Pos    (16UL)         /*!< TMTS (Bit 16)                                         */
#define R_CANFD_CFDTHL_ACC0_TMTS_Msk    (0xffff0000UL) /*!< TMTS (Bitfield-Mask: 0xffff)                          */
/* =========================================================  ACC1  ========================================================== */
#define R_CANFD_CFDTHL_ACC1_TID_Pos     (0UL)          /*!< TID (Bit 0)                                           */
#define R_CANFD_CFDTHL_ACC1_TID_Msk     (0xffffUL)     /*!< TID (Bitfield-Mask: 0xffff)                           */
#define R_CANFD_CFDTHL_ACC1_TIFL_Pos    (16UL)         /*!< TIFL (Bit 16)                                         */
#define R_CANFD_CFDTHL_ACC1_TIFL_Msk    (0x30000UL)    /*!< TIFL (Bitfield-Mask: 0x03)                            */

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
#define R_CANFD_CFDRM_PTR_RMDLC_Pos      (28UL)         /*!< RMDLC (Bit 28)                                        */
#define R_CANFD_CFDRM_PTR_RMDLC_Msk      (0xf0000000UL) /*!< RMDLC (Bitfield-Mask: 0x0f)                           */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFD_CFDRM_FDSTS_RMESI_Pos    (0UL)          /*!< RMESI (Bit 0)                                         */
#define R_CANFD_CFDRM_FDSTS_RMESI_Msk    (0x1UL)        /*!< RMESI (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRM_FDSTS_RMBRS_Pos    (1UL)          /*!< RMBRS (Bit 1)                                         */
#define R_CANFD_CFDRM_FDSTS_RMBRS_Msk    (0x2UL)        /*!< RMBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRM_FDSTS_RMFDF_Pos    (2UL)          /*!< RMFDF (Bit 2)                                         */
#define R_CANFD_CFDRM_FDSTS_RMFDF_Msk    (0x4UL)        /*!< RMFDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRM_FDSTS_RMIFL_Pos    (8UL)          /*!< RMIFL (Bit 8)                                         */
#define R_CANFD_CFDRM_FDSTS_RMIFL_Msk    (0x300UL)      /*!< RMIFL (Bitfield-Mask: 0x03)                           */
#define R_CANFD_CFDRM_FDSTS_RMPTR_Pos    (16UL)         /*!< RMPTR (Bit 16)                                        */
#define R_CANFD_CFDRM_FDSTS_RMPTR_Msk    (0xffff0000UL) /*!< RMPTR (Bitfield-Mask: 0xffff)                         */
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
#define R_CANFD_CFDRF_PTR_RFDLC_Pos      (28UL)         /*!< RFDLC (Bit 28)                                        */
#define R_CANFD_CFDRF_PTR_RFDLC_Msk      (0xf0000000UL) /*!< RFDLC (Bitfield-Mask: 0x0f)                           */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFD_CFDRF_FDSTS_RFESI_Pos    (0UL)          /*!< RFESI (Bit 0)                                         */
#define R_CANFD_CFDRF_FDSTS_RFESI_Msk    (0x1UL)        /*!< RFESI (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRF_FDSTS_RFBRS_Pos    (1UL)          /*!< RFBRS (Bit 1)                                         */
#define R_CANFD_CFDRF_FDSTS_RFBRS_Msk    (0x2UL)        /*!< RFBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRF_FDSTS_RFFDF_Pos    (2UL)          /*!< RFFDF (Bit 2)                                         */
#define R_CANFD_CFDRF_FDSTS_RFFDF_Msk    (0x4UL)        /*!< RFFDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRF_FDSTS_RFIFL_Pos    (8UL)          /*!< RFIFL (Bit 8)                                         */
#define R_CANFD_CFDRF_FDSTS_RFIFL_Msk    (0x300UL)      /*!< RFIFL (Bitfield-Mask: 0x03)                           */
#define R_CANFD_CFDRF_FDSTS_RFPTR_Pos    (16UL)         /*!< RFPTR (Bit 16)                                        */
#define R_CANFD_CFDRF_FDSTS_RFPTR_Msk    (0xffff0000UL) /*!< RFPTR (Bitfield-Mask: 0xffff)                         */
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
#define R_CANFD_CFDCF_PTR_CFDLC_Pos      (28UL)         /*!< CFDLC (Bit 28)                                        */
#define R_CANFD_CFDCF_PTR_CFDLC_Msk      (0xf0000000UL) /*!< CFDLC (Bitfield-Mask: 0x0f)                           */
/* =========================================================  FDSTS  ========================================================= */
#define R_CANFD_CFDCF_FDSTS_CFESI_Pos    (0UL)          /*!< CFESI (Bit 0)                                         */
#define R_CANFD_CFDCF_FDSTS_CFESI_Msk    (0x1UL)        /*!< CFESI (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCF_FDSTS_CFBRS_Pos    (1UL)          /*!< CFBRS (Bit 1)                                         */
#define R_CANFD_CFDCF_FDSTS_CFBRS_Msk    (0x2UL)        /*!< CFBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCF_FDSTS_CFFDF_Pos    (2UL)          /*!< CFFDF (Bit 2)                                         */
#define R_CANFD_CFDCF_FDSTS_CFFDF_Msk    (0x4UL)        /*!< CFFDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCF_FDSTS_CFIFL_Pos    (8UL)          /*!< CFIFL (Bit 8)                                         */
#define R_CANFD_CFDCF_FDSTS_CFIFL_Msk    (0x300UL)      /*!< CFIFL (Bitfield-Mask: 0x03)                           */
#define R_CANFD_CFDCF_FDSTS_CFPTR_Pos    (16UL)         /*!< CFPTR (Bit 16)                                        */
#define R_CANFD_CFDCF_FDSTS_CFPTR_Msk    (0xffff0000UL) /*!< CFPTR (Bitfield-Mask: 0xffff)                         */
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
#define R_CANFD_CFDTM_PTR_TMDLC_Pos      (28UL)         /*!< TMDLC (Bit 28)                                        */
#define R_CANFD_CFDTM_PTR_TMDLC_Msk      (0xf0000000UL) /*!< TMDLC (Bitfield-Mask: 0x0f)                           */
/* =========================================================  FDCTR  ========================================================= */
#define R_CANFD_CFDTM_FDCTR_TMESI_Pos    (0UL)          /*!< TMESI (Bit 0)                                         */
#define R_CANFD_CFDTM_FDCTR_TMESI_Msk    (0x1UL)        /*!< TMESI (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTM_FDCTR_TMBRS_Pos    (1UL)          /*!< TMBRS (Bit 1)                                         */
#define R_CANFD_CFDTM_FDCTR_TMBRS_Msk    (0x2UL)        /*!< TMBRS (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTM_FDCTR_TMFDF_Pos    (2UL)          /*!< TMFDF (Bit 2)                                         */
#define R_CANFD_CFDTM_FDCTR_TMFDF_Msk    (0x4UL)        /*!< TMFDF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTM_FDCTR_TMIFL_Pos    (8UL)          /*!< TMIFL (Bit 8)                                         */
#define R_CANFD_CFDTM_FDCTR_TMIFL_Msk    (0x300UL)      /*!< TMIFL (Bitfield-Mask: 0x03)                           */
#define R_CANFD_CFDTM_FDCTR_TMPTR_Pos    (16UL)         /*!< TMPTR (Bit 16)                                        */
#define R_CANFD_CFDTM_FDCTR_TMPTR_Msk    (0xffff0000UL) /*!< TMPTR (Bitfield-Mask: 0xffff)                         */
/* ==========================================================  DF  =========================================================== */
#define R_CANFD_CFDTM_DF_TMDB_Pos        (0UL)          /*!< TMDB (Bit 0)                                          */
#define R_CANFD_CFDTM_DF_TMDB_Msk        (0xffUL)       /*!< TMDB (Bitfield-Mask: 0xff)                            */

/* =========================================================================================================================== */
/* ================                                          R_CANFD                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  CFDGIPV  ======================================================== */
#define R_CANFD_CFDGIPV_IPV_Pos                 (0UL)          /*!< IPV (Bit 0)                                           */
#define R_CANFD_CFDGIPV_IPV_Msk                 (0xffUL)       /*!< IPV (Bitfield-Mask: 0xff)                             */
#define R_CANFD_CFDGIPV_IPT_Pos                 (8UL)          /*!< IPT (Bit 8)                                           */
#define R_CANFD_CFDGIPV_IPT_Msk                 (0x300UL)      /*!< IPT (Bitfield-Mask: 0x03)                             */
#define R_CANFD_CFDGIPV_PSI_Pos                 (16UL)         /*!< PSI (Bit 16)                                          */
#define R_CANFD_CFDGIPV_PSI_Msk                 (0x3fff0000UL) /*!< PSI (Bitfield-Mask: 0x3fff)                           */
/* ========================================================  CFDGCFG  ======================================================== */
#define R_CANFD_CFDGCFG_TPRI_Pos                (0UL)          /*!< TPRI (Bit 0)                                          */
#define R_CANFD_CFDGCFG_TPRI_Msk                (0x1UL)        /*!< TPRI (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGCFG_DCE_Pos                 (1UL)          /*!< DCE (Bit 1)                                           */
#define R_CANFD_CFDGCFG_DCE_Msk                 (0x2UL)        /*!< DCE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGCFG_DRE_Pos                 (2UL)          /*!< DRE (Bit 2)                                           */
#define R_CANFD_CFDGCFG_DRE_Msk                 (0x4UL)        /*!< DRE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGCFG_MME_Pos                 (3UL)          /*!< MME (Bit 3)                                           */
#define R_CANFD_CFDGCFG_MME_Msk                 (0x8UL)        /*!< MME (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGCFG_DCS_Pos                 (4UL)          /*!< DCS (Bit 4)                                           */
#define R_CANFD_CFDGCFG_DCS_Msk                 (0x10UL)       /*!< DCS (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGCFG_CMPOC_Pos               (5UL)          /*!< CMPOC (Bit 5)                                         */
#define R_CANFD_CFDGCFG_CMPOC_Msk               (0x20UL)       /*!< CMPOC (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGCFG_TSP_Pos                 (8UL)          /*!< TSP (Bit 8)                                           */
#define R_CANFD_CFDGCFG_TSP_Msk                 (0xf00UL)      /*!< TSP (Bitfield-Mask: 0x0f)                             */
#define R_CANFD_CFDGCFG_TSSS_Pos                (12UL)         /*!< TSSS (Bit 12)                                         */
#define R_CANFD_CFDGCFG_TSSS_Msk                (0x1000UL)     /*!< TSSS (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGCFG_TSBTCS_Pos              (13UL)         /*!< TSBTCS (Bit 13)                                       */
#define R_CANFD_CFDGCFG_TSBTCS_Msk              (0xe000UL)     /*!< TSBTCS (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDGCFG_ITRCP_Pos               (16UL)         /*!< ITRCP (Bit 16)                                        */
#define R_CANFD_CFDGCFG_ITRCP_Msk               (0xffff0000UL) /*!< ITRCP (Bitfield-Mask: 0xffff)                         */
/* ========================================================  CFDGCTR  ======================================================== */
#define R_CANFD_CFDGCTR_GMDC_Pos                (0UL)          /*!< GMDC (Bit 0)                                          */
#define R_CANFD_CFDGCTR_GMDC_Msk                (0x3UL)        /*!< GMDC (Bitfield-Mask: 0x03)                            */
#define R_CANFD_CFDGCTR_GSLPR_Pos               (2UL)          /*!< GSLPR (Bit 2)                                         */
#define R_CANFD_CFDGCTR_GSLPR_Msk               (0x4UL)        /*!< GSLPR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGCTR_DEIE_Pos                (8UL)          /*!< DEIE (Bit 8)                                          */
#define R_CANFD_CFDGCTR_DEIE_Msk                (0x100UL)      /*!< DEIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGCTR_MEIE_Pos                (9UL)          /*!< MEIE (Bit 9)                                          */
#define R_CANFD_CFDGCTR_MEIE_Msk                (0x200UL)      /*!< MEIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGCTR_THLEIE_Pos              (10UL)         /*!< THLEIE (Bit 10)                                       */
#define R_CANFD_CFDGCTR_THLEIE_Msk              (0x400UL)      /*!< THLEIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGCTR_CMPOFIE_Pos             (11UL)         /*!< CMPOFIE (Bit 11)                                      */
#define R_CANFD_CFDGCTR_CMPOFIE_Msk             (0x800UL)      /*!< CMPOFIE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGCTR_QOWEIE_Pos              (12UL)         /*!< QOWEIE (Bit 12)                                        */
#define R_CANFD_CFDGCTR_QOWEIE_Msk              (0x1000UL)     /*!< QOWEIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGCTR_QMEIE_Pos               (14UL)         /*!< QMEIE (Bit 14)                                        */
#define R_CANFD_CFDGCTR_QMEIE_Msk               (0x4000UL)     /*!< QMEIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGCTR_MOWEIE_Pos              (15UL)         /*!< MOWEIE (Bit 15)                                       */
#define R_CANFD_CFDGCTR_MOWEIE_Msk              (0x8000UL)     /*!< MOWEIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGCTR_TSRST_Pos               (16UL)         /*!< TSRST (Bit 16)                                        */
#define R_CANFD_CFDGCTR_TSRST_Msk               (0x10000UL)    /*!< TSRST (Bitfield-Mask: 0x01)                           */
/* ========================================================  CFDGSTS  ======================================================== */
#define R_CANFD_CFDGSTS_GRSTSTS_Pos             (0UL)          /*!< GRSTSTS (Bit 0)                                       */
#define R_CANFD_CFDGSTS_GRSTSTS_Msk             (0x1UL)        /*!< GRSTSTS (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGSTS_GHLTSTS_Pos             (1UL)          /*!< GHLTSTS (Bit 1)                                       */
#define R_CANFD_CFDGSTS_GHLTSTS_Msk             (0x2UL)        /*!< GHLTSTS (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGSTS_GSLPSTS_Pos             (2UL)          /*!< GSLPSTS (Bit 2)                                       */
#define R_CANFD_CFDGSTS_GSLPSTS_Msk             (0x4UL)        /*!< GSLPSTS (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGSTS_GRAMINIT_Pos            (3UL)          /*!< GRAMINIT (Bit 3)                                      */
#define R_CANFD_CFDGSTS_GRAMINIT_Msk            (0x8UL)        /*!< GRAMINIT (Bitfield-Mask: 0x01)                        */
/* =======================================================  CFDGERFL  ======================================================== */
#define R_CANFD_CFDGERFL_DEF_Pos                (0UL)          /*!< DEF (Bit 0)                                           */
#define R_CANFD_CFDGERFL_DEF_Msk                (0x1UL)        /*!< DEF (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGERFL_MES_Pos                (1UL)          /*!< MES (Bit 1)                                           */
#define R_CANFD_CFDGERFL_MES_Msk                (0x2UL)        /*!< MES (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDGERFL_THLES_Pos              (2UL)          /*!< THLES (Bit 2)                                         */
#define R_CANFD_CFDGERFL_THLES_Msk              (0x4UL)        /*!< THLES (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGERFL_CMPOF_Pos              (3UL)          /*!< CMPOF (Bit 3)                                         */
#define R_CANFD_CFDGERFL_CMPOF_Msk              (0x8UL)        /*!< CMPOF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGERFL_QOWES_Pos              (4UL)          /*!< QOWES (Bit 4)                                         */
#define R_CANFD_CFDGERFL_QOWES_Msk              (0x10UL)       /*!< QOWES (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGERFL_QMES_Pos               (6UL)          /*!< QMES (Bit 6)                                          */
#define R_CANFD_CFDGERFL_QMES_Msk               (0x40UL)       /*!< QMES (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGERFL_MOWES_Pos              (7UL)          /*!< MOWES (Bit 7)                                         */
#define R_CANFD_CFDGERFL_MOWES_Msk              (0x80UL)       /*!< MOWES (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGERFL_EEF0_Pos               (16UL)         /*!< EEF0 (Bit 16)                                         */
#define R_CANFD_CFDGERFL_EEF0_Msk               (0x10000UL)    /*!< EEF0 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGERFL_EEF1_Pos               (17UL)         /*!< EEF1 (Bit 17)                                         */
#define R_CANFD_CFDGERFL_EEF1_Msk               (0x20000UL)    /*!< EEF1 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGERFL_EEF2_Pos               (18UL)         /*!< EEF2 (Bit 18)                                         */
#define R_CANFD_CFDGERFL_EEF2_Msk               (0x40000UL)    /*!< EEF2 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGERFL_EEF3_Pos               (19UL)         /*!< EEF3 (Bit 19)                                         */
#define R_CANFD_CFDGERFL_EEF3_Msk               (0x80000UL)    /*!< EEF3 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGERFL_EEF4_Pos               (20UL)         /*!< EEF4 (Bit 20)                                         */
#define R_CANFD_CFDGERFL_EEF4_Msk               (0x100000UL)   /*!< EEF4 (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGERFL_EEF5_Pos               (21UL)         /*!< EEF5 (Bit 21)                                         */
#define R_CANFD_CFDGERFL_EEF5_Msk               (0x200000UL)   /*!< EEF5 (Bitfield-Mask: 0x01)                            */
/* ========================================================  CFDGTSC  ======================================================== */
#define R_CANFD_CFDGTSC_TS_Pos                  (0UL)          /*!< TS (Bit 0)                                            */
#define R_CANFD_CFDGTSC_TS_Msk                  (0xffffUL)     /*!< TS (Bitfield-Mask: 0xffff)                            */
/* ======================================================  CFDGAFLECTR  ====================================================== */
#define R_CANFD_CFDGAFLECTR_AFLPN_Pos           (0UL)          /*!< AFLPN (Bit 0)                                         */
#define R_CANFD_CFDGAFLECTR_AFLPN_Msk           (0x3fUL)       /*!< AFLPN (Bitfield-Mask: 0x03f)                          */
#define R_CANFD_CFDGAFLECTR_AFLDAE_Pos          (8UL)          /*!< AFLDAE (Bit 8)                                        */
#define R_CANFD_CFDGAFLECTR_AFLDAE_Msk          (0x100UL)      /*!< AFLDAE (Bitfield-Mask: 0x01)                          */
/* ======================================================  CFDGAFLCFG0  ====================================================== */
#define R_CANFD_CFDGAFLCFG_RNC1_Pos             (0UL)          /*!< RNC1 (Bit 0)                                          */
#define R_CANFD_CFDGAFLCFG_RNC1_Msk             (0x1ffUL)      /*!< RNC1 (Bitfield-Mask: 0x1ff)                           */
#define R_CANFD_CFDGAFLCFG_RNC0_Pos             (16UL)         /*!< RNC0 (Bit 16)                                         */
#define R_CANFD_CFDGAFLCFG_RNC0_Msk             (0x1ff0000UL)  /*!< RNC0 (Bitfield-Mask: 0x1ff)                           */
/* ========================================================  CFDRMNB  ======================================================== */
#define R_CANFD_CFDRMNB_NRXMB_Pos               (0UL)          /*!< NRXMB (Bit 0)                                         */
#define R_CANFD_CFDRMNB_NRXMB_Msk               (0xffUL)       /*!< NRXMB (Bitfield-Mask: 0xff)                           */
#define R_CANFD_CFDRMNB_RMPLS_Pos               (8UL)          /*!< RMPLS (Bit 8)                                         */
#define R_CANFD_CFDRMNB_RMPLS_Msk               (0x700UL)      /*!< RMPLS (Bitfield-Mask: 0x07)                           */
/* =======================================================  CFDRMND  ======================================================== */
#define R_CANFD_CFDRMND_RMNS_Pos                (0UL)          /*!< RMNS (Bit 0)                                         */
#define R_CANFD_CFDRMND_RMNS_Msk                (0xffffffffUL) /*!< RMNS (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  CFDRFCC  ======================================================== */
#define R_CANFD_CFDRFCC_RFE_Pos                 (0UL)          /*!< RFE (Bit 0)                                           */
#define R_CANFD_CFDRFCC_RFE_Msk                 (0x1UL)        /*!< RFE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDRFCC_RFIE_Pos                (1UL)          /*!< RFIE (Bit 1)                                          */
#define R_CANFD_CFDRFCC_RFIE_Msk                (0x2UL)        /*!< RFIE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDRFCC_RFPLS_Pos               (4UL)          /*!< RFPLS (Bit 4)                                         */
#define R_CANFD_CFDRFCC_RFPLS_Msk               (0x70UL)       /*!< RFPLS (Bitfield-Mask: 0x07)                           */
#define R_CANFD_CFDRFCC_RFDC_Pos                (8UL)          /*!< RFDC (Bit 8)                                          */
#define R_CANFD_CFDRFCC_RFDC_Msk                (0x700UL)      /*!< RFDC (Bitfield-Mask: 0x07)                            */
#define R_CANFD_CFDRFCC_RFIM_Pos                (12UL)         /*!< RFIM (Bit 12)                                         */
#define R_CANFD_CFDRFCC_RFIM_Msk                (0x1000UL)     /*!< RFIM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDRFCC_RFIGCV_Pos              (13UL)         /*!< RFIGCV (Bit 13)                                       */
#define R_CANFD_CFDRFCC_RFIGCV_Msk              (0xe000UL)     /*!< RFIGCV (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDRFCC_RFFIE_Pos               (16UL)         /*!< RFFIE (Bit 16)                                        */
#define R_CANFD_CFDRFCC_RFFIE_Msk               (0x10000UL)    /*!< RFFIE (Bitfield-Mask: 0x01)                           */
/* =======================================================  CFDRFSTS  ======================================================== */
#define R_CANFD_CFDRFSTS_RFEMP_Pos              (0UL)          /*!< RFEMP (Bit 0)                                         */
#define R_CANFD_CFDRFSTS_RFEMP_Msk              (0x1UL)        /*!< RFEMP (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRFSTS_RFFLL_Pos              (1UL)          /*!< RFFLL (Bit 1)                                         */
#define R_CANFD_CFDRFSTS_RFFLL_Msk              (0x2UL)        /*!< RFFLL (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRFSTS_RFMLT_Pos              (2UL)          /*!< RFMLT (Bit 2)                                         */
#define R_CANFD_CFDRFSTS_RFMLT_Msk              (0x4UL)        /*!< RFMLT (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDRFSTS_RFIF_Pos               (3UL)          /*!< RFIF (Bit 3)                                          */
#define R_CANFD_CFDRFSTS_RFIF_Msk               (0x8UL)        /*!< RFIF (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDRFSTS_RFMC_Pos               (8UL)          /*!< RFMC (Bit 8)                                          */
#define R_CANFD_CFDRFSTS_RFMC_Msk               (0xff00UL)     /*!< RFMC (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFDRFSTS_RFFIF_Pos              (16UL)         /*!< RFFIF (Bit 16)                                        */
#define R_CANFD_CFDRFSTS_RFFIF_Msk              (0x10000UL)    /*!< RFFIF (Bitfield-Mask: 0x01)                           */
/* =======================================================  CFDRFPCTR  ======================================================= */
#define R_CANFD_CFDRFPCTR_RFPC_Pos              (0UL)          /*!< RFPC (Bit 0)                                          */
#define R_CANFD_CFDRFPCTR_RFPC_Msk              (0xffUL)       /*!< RFPC (Bitfield-Mask: 0xff)                            */
/* ========================================================  CFDCFCC  ======================================================== */
#define R_CANFD_CFDCFCC_CFE_Pos                 (0UL)          /*!< CFE (Bit 0)                                           */
#define R_CANFD_CFDCFCC_CFE_Msk                 (0x1UL)        /*!< CFE (Bitfield-Mask: 0x01)                             */
#define R_CANFD_CFDCFCC_CFRXIE_Pos              (1UL)          /*!< CFRXIE (Bit 1)                                        */
#define R_CANFD_CFDCFCC_CFRXIE_Msk              (0x2UL)        /*!< CFRXIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFCC_CFTXIE_Pos              (2UL)          /*!< CFTXIE (Bit 2)                                        */
#define R_CANFD_CFDCFCC_CFTXIE_Msk              (0x4UL)        /*!< CFTXIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFCC_CFPLS_Pos               (4UL)          /*!< CFPLS (Bit 4)                                         */
#define R_CANFD_CFDCFCC_CFPLS_Msk               (0x70UL)       /*!< CFPLS (Bitfield-Mask: 0x07)                           */
#define R_CANFD_CFDCFCC_CFM_Pos                 (8UL)          /*!< CFM (Bit 8)                                           */
#define R_CANFD_CFDCFCC_CFM_Msk                 (0x300UL)      /*!< CFM (Bitfield-Mask: 0x03)                             */
#define R_CANFD_CFDCFCC_CFITSS_Pos              (10UL)         /*!< CFITSS (Bit 10)                                       */
#define R_CANFD_CFDCFCC_CFITSS_Msk              (0x400UL)      /*!< CFITSS (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFCC_CFITR_Pos               (11UL)         /*!< CFITR (Bit 11)                                        */
#define R_CANFD_CFDCFCC_CFITR_Msk               (0x800UL)      /*!< CFITR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFCC_CFIM_Pos                (12UL)         /*!< CFIM (Bit 12)                                         */
#define R_CANFD_CFDCFCC_CFIM_Msk                (0x1000UL)     /*!< CFIM (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDCFCC_CFIGCV_Pos              (13UL)         /*!< CFIGCV (Bit 13)                                       */
#define R_CANFD_CFDCFCC_CFIGCV_Msk              (0xe000UL)     /*!< CFIGCV (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDCFCC_CFTML_Pos               (16UL)         /*!< CFTML (Bit 16)                                        */
#define R_CANFD_CFDCFCC_CFTML_Msk               (0x1f0000UL)   /*!< CFTML (Bitfield-Mask: 0x1f)                           */
#define R_CANFD_CFDCFCC_CFDC_Pos                (21UL)         /*!< CFDC (Bit 21)                                         */
#define R_CANFD_CFDCFCC_CFDC_Msk                (0xe00000UL)   /*!< CFDC (Bitfield-Mask: 0x07)                            */
#define R_CANFD_CFDCFCC_CFITT_Pos               (24UL)         /*!< CFITT (Bit 24)                                        */
#define R_CANFD_CFDCFCC_CFITT_Msk               (0xff000000UL) /*!< CFITT (Bitfield-Mask: 0xff)                           */
/* =======================================================  CFDCFCCE  ======================================================== */
#define R_CANFD_CFDCFCCE_CFFIE_Pos              (0UL)          /*!< CFFIE (Bit 0)                                         */
#define R_CANFD_CFDCFCCE_CFFIE_Msk              (0x1UL)        /*!< CFFIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFCCE_CFOFRXIE_Pos           (1UL)          /*!< CFOFRXIE (Bit 1)                                      */
#define R_CANFD_CFDCFCCE_CFOFRXIE_Msk           (0x2UL)        /*!< CFOFRXIE (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCFCCE_CFOFTXIE_Pos           (2UL)          /*!< CFOFTXIE (Bit 2)                                      */
#define R_CANFD_CFDCFCCE_CFOFTXIE_Msk           (0x4UL)        /*!< CFOFTXIE (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCFCCE_CFMOWM_Pos             (8UL)          /*!< CFMOWM (Bit 8)                                        */
#define R_CANFD_CFDCFCCE_CFMOWM_Msk             (0x100UL)      /*!< CFMOWM (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFCCE_CFBME_Pos              (16UL)         /*!< CFBME (Bit 16)                                        */
#define R_CANFD_CFDCFCCE_CFBME_Msk              (0x10000UL)    /*!< CFBME (Bitfield-Mask: 0x01)                           */
/* =======================================================  CFDCFSTS  ======================================================== */
#define R_CANFD_CFDCFSTS_CFEMP_Pos              (0UL)          /*!< CFEMP (Bit 0)                                         */
#define R_CANFD_CFDCFSTS_CFEMP_Msk              (0x1UL)        /*!< CFEMP (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFSTS_CFFLL_Pos              (1UL)          /*!< CFFLL (Bit 1)                                         */
#define R_CANFD_CFDCFSTS_CFFLL_Msk              (0x2UL)        /*!< CFFLL (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFSTS_CFMLT_Pos              (2UL)          /*!< CFMLT (Bit 2)                                         */
#define R_CANFD_CFDCFSTS_CFMLT_Msk              (0x4UL)        /*!< CFMLT (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFSTS_CFRXIF_Pos             (3UL)          /*!< CFRXIF (Bit 3)                                        */
#define R_CANFD_CFDCFSTS_CFRXIF_Msk             (0x8UL)        /*!< CFRXIF (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFSTS_CFTXIF_Pos             (4UL)          /*!< CFTXIF (Bit 4)                                        */
#define R_CANFD_CFDCFSTS_CFTXIF_Msk             (0x10UL)       /*!< CFTXIF (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDCFSTS_CFMC_Pos               (8UL)          /*!< CFMC (Bit 8)                                          */
#define R_CANFD_CFDCFSTS_CFMC_Msk               (0xff00UL)     /*!< CFMC (Bitfield-Mask: 0xff)                            */
#define R_CANFD_CFDCFSTS_CFFIF_Pos              (16UL)         /*!< CFFIF (Bit 16)                                        */
#define R_CANFD_CFDCFSTS_CFFIF_Msk              (0x10000UL)    /*!< CFFIF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDCFSTS_CFOFRXIF_Pos           (17UL)         /*!< CFOFRXIF (Bit 17)                                     */
#define R_CANFD_CFDCFSTS_CFOFRXIF_Msk           (0x20000UL)    /*!< CFOFRXIF (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCFSTS_CFOFTXIF_Pos           (18UL)         /*!< CFOFTXIF (Bit 18)                                     */
#define R_CANFD_CFDCFSTS_CFOFTXIF_Msk           (0x40000UL)    /*!< CFOFTXIF (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCFSTS_CFMOW_Pos              (24UL)         /*!< CFMOW (Bit 24)                                        */
#define R_CANFD_CFDCFSTS_CFMOW_Msk              (0x1000000UL)  /*!< CFMOW (Bitfield-Mask: 0x01)                           */
/* =======================================================  CFDCFPCTR  ======================================================= */
#define R_CANFD_CFDCFPCTR_CFPC_Pos              (0UL)          /*!< CFPC (Bit 0)                                          */
#define R_CANFD_CFDCFPCTR_CFPC_Msk              (0xffUL)       /*!< CFPC (Bitfield-Mask: 0xff)                            */
/* =======================================================  CFDFESTS  ======================================================== */
#define R_CANFD_CFDFESTS_RFXEMP_Pos             (0UL)          /*!< RFXEMP (Bit 0)                                        */
#define R_CANFD_CFDFESTS_RFXEMP_Msk             (0xffUL)       /*!< RFXEMP (Bitfield-Mask: 0xff)                          */
#define R_CANFD_CFDFESTS_CFXEMP_Pos             (8UL)          /*!< CFXEMP (Bit 8)                                        */
#define R_CANFD_CFDFESTS_CFXEMP_Msk             (0x3ffff00UL)  /*!< CFXEMP (Bitfield-Mask: 0x3ffff)                    */
/* =======================================================  CFDFFSTS  ======================================================== */
#define R_CANFD_CFDFFSTS_RFXFLL_Pos             (0UL)          /*!< RFXFLL (Bit 0)                                        */
#define R_CANFD_CFDFFSTS_RFXFLL_Msk             (0xffUL)       /*!< RFXFLL (Bitfield-Mask: 0xff)                          */
#define R_CANFD_CFDFFSTS_CFXFLL_Pos             (8UL)          /*!< CFXFLL (Bit 8)                                        */
#define R_CANFD_CFDFFSTS_CFXFLL_Msk             (0x3ffff00UL)  /*!< CFXFLL (Bitfield-Mask: 0x3ffff)                    */
/* =======================================================  CFDFMSTS  ======================================================== */
#define R_CANFD_CFDFMSTS_RFXMLT_Pos             (0UL)          /*!< RFXMLT (Bit 0)                                        */
#define R_CANFD_CFDFMSTS_RFXMLT_Msk             (0xffUL)       /*!< RFXMLT (Bitfield-Mask: 0xff)                          */
#define R_CANFD_CFDFMSTS_CFXMLT_Pos             (8UL)          /*!< CFXMLT (Bit 8)                                        */
#define R_CANFD_CFDFMSTS_CFXMLT_Msk             (0x3ffff00UL)  /*!< CFXMLT (Bitfield-Mask: 0x3ffff)                          */
/* =======================================================  CFDRFISTS  ======================================================= */
#define R_CANFD_CFDRFISTS_RFXIF_Pos             (0UL)          /*!< RFXIF (Bit 0)                                         */
#define R_CANFD_CFDRFISTS_RFXIF_Msk             (0xffUL)       /*!< RFXIF (Bitfield-Mask: 0xff)                           */
#define R_CANFD_CFDRFISTS_RFXFFLL_Pos           (16UL)         /*!< RFXFFLL (Bit 16)                                      */
#define R_CANFD_CFDRFISTS_RFXFFLL_Msk           (0xff0000UL)   /*!< RFXFFLL (Bitfield-Mask: 0xff)                         */
/* ======================================================  CFDCFRISTS  ======================================================= */
#define R_CANFD_CFDCFRISTS_CFXRXIF_Pos          (0UL)          /*!< CFXRXIF (Bit 0)                                       */
#define R_CANFD_CFDCFRISTS_CFXRXIF_Msk          (0x3ffffUL)    /*!< CFXRXIF (Bitfield-Mask: 0x3ffff)                      */
/* ======================================================  CFDCFTISTS  ======================================================= */
#define R_CANFD_CFDCFTISTS_CFXTXIF_Pos          (0UL)          /*!< CFXTXIF (Bit 0)                                       */
#define R_CANFD_CFDCFTISTS_CFXTXIF_Msk          (0x3ffffUL)    /*!< CFXTXIF (Bitfield-Mask: 0x3ffff)                      */
/* =====================================================  CFDCFOFRISTS  ====================================================== */
#define R_CANFD_CFDCFOFRISTS_CFXOFRXIF_Pos      (0UL)          /*!< CFXOFRXIF (Bit 0)                                     */
#define R_CANFD_CFDCFOFRISTS_CFXOFRXIF_Msk      (0x3ffffUL)    /*!< CFXOFRXIF (Bitfield-Mask: 0x3ffff)                    */
/* =====================================================  CFDCFOFTISTS  ====================================================== */
#define R_CANFD_CFDCFOFTISTS_CFXOFTXIF_Pos      (0UL)          /*!< CFXOFTXIF (Bit 0)                                     */
#define R_CANFD_CFDCFOFTISTS_CFXOFTXIF_Msk      (0x3ffffUL)    /*!< CFXOFTXIF (Bitfield-Mask: 0x3ffff)                    */
/* ======================================================  CFDCFMOWSTS  ====================================================== */
#define R_CANFD_CFDCFMOWSTS_CFXMOW_Pos          (0UL)          /*!< CFXMOW (Bit 0)                                        */
#define R_CANFD_CFDCFMOWSTS_CFXMOW_Msk          (0x3ffffUL)    /*!< CFXMOW (Bitfield-Mask: 0x3ffff)                       */
/* =======================================================  CFDFFFSTS  ======================================================= */
#define R_CANFD_CFDFFFSTS_RFXFFLL_Pos           (0UL)          /*!< RFXFFLL (Bit 0)                                       */
#define R_CANFD_CFDFFFSTS_RFXFFLL_Msk           (0xffUL)       /*!< RFXFFLL (Bitfield-Mask: 0xff)                         */
#define R_CANFD_CFDFFFSTS_CFXFFLL_Pos           (8UL)          /*!< CFXFFLL (Bit 8)                                       */
#define R_CANFD_CFDFFFSTS_CFXFFLL_Msk           (0x3ffff00UL)  /*!< CFXFFLL (Bitfield-Mask: 0x3ffff)                      */
/* ========================================================  CFDTMC  ========================================================= */
#define R_CANFD_CFDTMC_TMTR_Pos                 (0UL)          /*!< TMTR (Bit 0)                                          */
#define R_CANFD_CFDTMC_TMTR_Msk                 (0x1UL)        /*!< TMTR (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDTMC_TMTAR_Pos                (1UL)          /*!< TMTAR (Bit 1)                                         */
#define R_CANFD_CFDTMC_TMTAR_Msk                (0x2UL)        /*!< TMTAR (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTMC_TMOM_Pos                 (2UL)          /*!< TMOM (Bit 2)                                          */
#define R_CANFD_CFDTMC_TMOM_Msk                 (0x4UL)        /*!< TMOM (Bitfield-Mask: 0x01)                            */
/* =======================================================  CFDTMSTS  ======================================================== */
#define R_CANFD_CFDTMSTS_TMTSTS_Pos             (0UL)          /*!< TMTSTS (Bit 0)                                        */
#define R_CANFD_CFDTMSTS_TMTSTS_Msk             (0x1UL)        /*!< TMTSTS (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTMSTS_TMTRF_Pos              (1UL)          /*!< TMTRF (Bit 1)                                         */
#define R_CANFD_CFDTMSTS_TMTRF_Msk              (0x6UL)        /*!< TMTRF (Bitfield-Mask: 0x03)                           */
#define R_CANFD_CFDTMSTS_TMTRM_Pos              (3UL)          /*!< TMTRM (Bit 3)                                         */
#define R_CANFD_CFDTMSTS_TMTRM_Msk              (0x8UL)        /*!< TMTRM (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTMSTS_TMTARM_Pos             (4UL)          /*!< TMTARM (Bit 4)                                        */
#define R_CANFD_CFDTMSTS_TMTARM_Msk             (0x10UL)       /*!< TMTARM (Bitfield-Mask: 0x01)                          */
/* ======================================================  CFDTMTRSTS  ======================================================= */
#define R_CANFD_CFDTMTRSTS_TMTRSTS_Pos          (0UL)          /*!< TMTRSTS (Bit 0)                                       */
#define R_CANFD_CFDTMTRSTS_TMTRSTS_Msk          (0xffffUL)     /*!< TMTRSTS (Bitfield-Mask: 0xffff)                       */
/* ======================================================  CFDTMTARSTS  ====================================================== */
#define R_CANFD_CFDTMTARSTS_TMTARSTS_Pos        (0UL)          /*!< TMTARSTS (Bit 0)                                      */
#define R_CANFD_CFDTMTARSTS_TMTARSTS_Msk        (0xffffUL)     /*!< TMTARSTS (Bitfield-Mask: 0xffff)                      */
/* ======================================================  CFDTMTCSTS  ======================================================= */
#define R_CANFD_CFDTMTCSTS_TMTCSTS_Pos          (0UL)          /*!< TMTCSTS (Bit 0)                                       */
#define R_CANFD_CFDTMTCSTS_TMTCSTS_Msk          (0xffffUL)     /*!< TMTCSTS (Bitfield-Mask: 0xffff)                       */
/* ======================================================  CFDTMTASTS  ======================================================= */
#define R_CANFD_CFDTMTASTS_TMTASTS_Pos          (0UL)          /*!< TMTASTS (Bit 0)                                       */
#define R_CANFD_CFDTMTASTS_TMTASTS_Msk          (0xffffUL)     /*!< TMTASTS (Bitfield-Mask: 0xffff)                       */
/* =======================================================  CFDTMIEC  ======================================================== */
#define R_CANFD_CFDTMIEC_TMIE_Pos               (0UL)          /*!< TMIE (Bit 0)                                          */
#define R_CANFD_CFDTMIEC_TMIE_Msk               (0xffffUL)     /*!< TMIE (Bitfield-Mask: 0xffff)                          */
/* =======================================================  CFDTXQCC0  ======================================================= */
#define R_CANFD_CFDTXQCC0_TXQE_Pos              (0UL)          /*!< TXQE (Bit 0)                                          */
#define R_CANFD_CFDTXQCC0_TXQE_Msk              (0x1UL)        /*!< TXQE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDTXQCC0_TXQGWE_Pos            (1UL)          /*!< TXQGWE (Bit 1)                                        */
#define R_CANFD_CFDTXQCC0_TXQGWE_Msk            (0x2UL)        /*!< TXQGWE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC0_TXQOWE_Pos            (2UL)          /*!< TXQOWE (Bit 2)                                        */
#define R_CANFD_CFDTXQCC0_TXQOWE_Msk            (0x4UL)        /*!< TXQOWE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC0_TXQTXIE_Pos           (5UL)          /*!< TXQTXIE (Bit 5)                                       */
#define R_CANFD_CFDTXQCC0_TXQTXIE_Msk           (0x20UL)       /*!< TXQTXIE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDTXQCC0_TXQIM_Pos             (7UL)          /*!< TXQIM (Bit 7)                                         */
#define R_CANFD_CFDTXQCC0_TXQIM_Msk             (0x80UL)       /*!< TXQIM (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTXQCC0_TXQDC_Pos             (8UL)          /*!< TXQDC (Bit 8)                                         */
#define R_CANFD_CFDTXQCC0_TXQDC_Msk             (0x1f00UL)     /*!< TXQDC (Bitfield-Mask: 0x1f)                           */
#define R_CANFD_CFDTXQCC0_TXQFIE_Pos            (16UL)         /*!< TXQFIE (Bit 16)                                       */
#define R_CANFD_CFDTXQCC0_TXQFIE_Msk            (0x10000UL)    /*!< TXQFIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC0_TXQOFRXIE_Pos         (17UL)         /*!< TXQOFRXIE (Bit 17)                                    */
#define R_CANFD_CFDTXQCC0_TXQOFRXIE_Msk         (0x20000UL)    /*!< TXQOFRXIE (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQCC0_TXQOFTXIE_Pos         (18UL)         /*!< TXQOFTXIE (Bit 18)                                    */
#define R_CANFD_CFDTXQCC0_TXQOFTXIE_Msk         (0x40000UL)    /*!< TXQOFTXIE (Bitfield-Mask: 0x01)                       */
/* ======================================================  CFDTXQSTS0  ======================================================= */
#define R_CANFD_CFDTXQSTS0_TXQEMP_Pos           (0UL)          /*!< TXQEMP (Bit 0)                                        */
#define R_CANFD_CFDTXQSTS0_TXQEMP_Msk           (0x1UL)        /*!< TXQEMP (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS0_TXQFLL_Pos           (1UL)          /*!< TXQFLL (Bit 1)                                        */
#define R_CANFD_CFDTXQSTS0_TXQFLL_Msk           (0x2UL)        /*!< TXQFLL (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS0_TXQTXIF_Pos          (2UL)          /*!< TXQTXIF (Bit 2)                                       */
#define R_CANFD_CFDTXQSTS0_TXQTXIF_Msk          (0x4UL)        /*!< TXQTXIF (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDTXQSTS0_TXQMC_Pos            (8UL)          /*!< TXQMC (Bit 8)                                         */
#define R_CANFD_CFDTXQSTS0_TXQMC_Msk            (0x3f00UL)     /*!< TXQMC (Bitfield-Mask: 0x3f)                           */
#define R_CANFD_CFDTXQSTS0_TXQFIF_Pos           (16UL)         /*!< TXQFIF (Bit 16)                                       */
#define R_CANFD_CFDTXQSTS0_TXQFIF_Msk           (0x10000UL)    /*!< TXQFIF (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS0_TXQOFRXIF_Pos        (17UL)         /*!< TXQOFRXIF (Bit 17)                                    */
#define R_CANFD_CFDTXQSTS0_TXQOFRXIF_Msk        (0x20000UL)    /*!< TXQOFRXIF (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQSTS0_TXQOFTXIF_Pos        (18UL)         /*!< TXQOFTXIF (Bit 18)                                    */
#define R_CANFD_CFDTXQSTS0_TXQOFTXIF_Msk        (0x40000UL)    /*!< TXQOFTXIF (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQSTS0_TXQMLT_Pos           (19UL)         /*!< TXQMLT (Bit 19)                                       */
#define R_CANFD_CFDTXQSTS0_TXQMLT_Msk           (0x80000UL)    /*!< TXQMLT (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS0_TXQMOW_Pos           (20UL)         /*!< TXQMOW (Bit 20)                                       */
#define R_CANFD_CFDTXQSTS0_TXQMOW_Msk           (0x100000UL)   /*!< TXQMOW (Bitfield-Mask: 0x01)                          */
/* ======================================================  CFDTXQPCTR0  ====================================================== */
#define R_CANFD_CFDTXQPCTR0_TXQPC_Pos           (0UL)          /*!< TXQPC (Bit 0)                                         */
#define R_CANFD_CFDTXQPCTR0_TXQPC_Msk           (0xffUL)       /*!< TXQPC (Bitfield-Mask: 0xff)                           */
/* =======================================================  CFDTXQCC1  ======================================================= */
#define R_CANFD_CFDTXQCC1_TXQE_Pos              (0UL)          /*!< TXQE (Bit 0)                                          */
#define R_CANFD_CFDTXQCC1_TXQE_Msk              (0x1UL)        /*!< TXQE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDTXQCC1_TXQGWE_Pos            (1UL)          /*!< TXQGWE (Bit 1)                                        */
#define R_CANFD_CFDTXQCC1_TXQGWE_Msk            (0x2UL)        /*!< TXQGWE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC1_TXQOWE_Pos            (2UL)          /*!< TXQOWE (Bit 2)                                        */
#define R_CANFD_CFDTXQCC1_TXQOWE_Msk            (0x4UL)        /*!< TXQOWE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC1_TXQTXIE_Pos           (5UL)          /*!< TXQTXIE (Bit 5)                                       */
#define R_CANFD_CFDTXQCC1_TXQTXIE_Msk           (0x20UL)       /*!< TXQTXIE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDTXQCC1_TXQIM_Pos             (7UL)          /*!< TXQIM (Bit 7)                                         */
#define R_CANFD_CFDTXQCC1_TXQIM_Msk             (0x80UL)       /*!< TXQIM (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTXQCC1_TXQDC_Pos             (8UL)          /*!< TXQDC (Bit 8)                                         */
#define R_CANFD_CFDTXQCC1_TXQDC_Msk             (0x1f00UL)     /*!< TXQDC (Bitfield-Mask: 0x1f)                           */
#define R_CANFD_CFDTXQCC1_TXQFIE_Pos            (16UL)         /*!< TXQFIE (Bit 16)                                       */
#define R_CANFD_CFDTXQCC1_TXQFIE_Msk            (0x10000UL)    /*!< TXQFIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC1_TXQOFRXIE_Pos         (17UL)         /*!< TXQOFRXIE (Bit 17)                                    */
#define R_CANFD_CFDTXQCC1_TXQOFRXIE_Msk         (0x20000UL)    /*!< TXQOFRXIE (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQCC1_TXQOFTXIE_Pos         (18UL)         /*!< TXQOFTXIE (Bit 18)                                    */
#define R_CANFD_CFDTXQCC1_TXQOFTXIE_Msk         (0x40000UL)    /*!< TXQOFTXIE (Bitfield-Mask: 0x01)                       */
/* ======================================================  CFDTXQSTS1  ======================================================= */
#define R_CANFD_CFDTXQSTS1_TXQEMP_Pos           (0UL)          /*!< TXQEMP (Bit 0)                                        */
#define R_CANFD_CFDTXQSTS1_TXQEMP_Msk           (0x1UL)        /*!< TXQEMP (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS1_TXQFLL_Pos           (1UL)          /*!< TXQFLL (Bit 1)                                        */
#define R_CANFD_CFDTXQSTS1_TXQFLL_Msk           (0x2UL)        /*!< TXQFLL (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS1_TXQTXIF_Pos          (2UL)          /*!< TXQTXIF (Bit 2)                                       */
#define R_CANFD_CFDTXQSTS1_TXQTXIF_Msk          (0x4UL)        /*!< TXQTXIF (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDTXQSTS1_TXQMC_Pos            (8UL)          /*!< TXQMC (Bit 8)                                         */
#define R_CANFD_CFDTXQSTS1_TXQMC_Msk            (0x3f00UL)     /*!< TXQMC (Bitfield-Mask: 0x3f)                           */
#define R_CANFD_CFDTXQSTS1_TXQFIF_Pos           (16UL)         /*!< TXQFIF (Bit 16)                                       */
#define R_CANFD_CFDTXQSTS1_TXQFIF_Msk           (0x10000UL)    /*!< TXQFIF (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS1_TXQOFRXIF_Pos        (17UL)         /*!< TXQOFRXIF (Bit 17)                                    */
#define R_CANFD_CFDTXQSTS1_TXQOFRXIF_Msk        (0x20000UL)    /*!< TXQOFRXIF (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQSTS1_TXQOFTXIF_Pos        (18UL)         /*!< TXQOFTXIF (Bit 18)                                    */
#define R_CANFD_CFDTXQSTS1_TXQOFTXIF_Msk        (0x40000UL)    /*!< TXQOFTXIF (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQSTS1_TXQMLT_Pos           (19UL)         /*!< TXQMLT (Bit 19)                                       */
#define R_CANFD_CFDTXQSTS1_TXQMLT_Msk           (0x80000UL)    /*!< TXQMLT (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS1_TXQMOW_Pos           (20UL)         /*!< TXQMOW (Bit 20)                                       */
#define R_CANFD_CFDTXQSTS1_TXQMOW_Msk           (0x100000UL)   /*!< TXQMOW (Bitfield-Mask: 0x01)                          */
/* ======================================================  CFDTXQPCTR1  ====================================================== */
#define R_CANFD_CFDTXQPCTR1_TXQPC_Pos           (0UL)          /*!< TXQPC (Bit 0)                                         */
#define R_CANFD_CFDTXQPCTR1_TXQPC_Msk           (0xffUL)       /*!< TXQPC (Bitfield-Mask: 0xff)                           */
/* =======================================================  CFDTXQCC2  ======================================================= */
#define R_CANFD_CFDTXQCC2_TXQE_Pos              (0UL)          /*!< TXQE (Bit 0)                                          */
#define R_CANFD_CFDTXQCC2_TXQE_Msk              (0x1UL)        /*!< TXQE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDTXQCC2_TXQGWE_Pos            (1UL)          /*!< TXQGWE (Bit 1)                                        */
#define R_CANFD_CFDTXQCC2_TXQGWE_Msk            (0x2UL)        /*!< TXQGWE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC2_TXQOWE_Pos            (2UL)          /*!< TXQOWE (Bit 2)                                        */
#define R_CANFD_CFDTXQCC2_TXQOWE_Msk            (0x4UL)        /*!< TXQOWE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC2_TXQTXIE_Pos           (5UL)          /*!< TXQTXIE (Bit 5)                                       */
#define R_CANFD_CFDTXQCC2_TXQTXIE_Msk           (0x20UL)       /*!< TXQTXIE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDTXQCC2_TXQIM_Pos             (7UL)          /*!< TXQIM (Bit 7)                                         */
#define R_CANFD_CFDTXQCC2_TXQIM_Msk             (0x80UL)       /*!< TXQIM (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTXQCC2_TXQDC_Pos             (8UL)          /*!< TXQDC (Bit 8)                                         */
#define R_CANFD_CFDTXQCC2_TXQDC_Msk             (0x1f00UL)     /*!< TXQDC (Bitfield-Mask: 0x1f)                           */
#define R_CANFD_CFDTXQCC2_TXQFIE_Pos            (16UL)         /*!< TXQFIE (Bit 16)                                       */
#define R_CANFD_CFDTXQCC2_TXQFIE_Msk            (0x10000UL)    /*!< TXQFIE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC2_TXQOFRXIE_Pos         (17UL)         /*!< TXQOFRXIE (Bit 17)                                    */
#define R_CANFD_CFDTXQCC2_TXQOFRXIE_Msk         (0x20000UL)    /*!< TXQOFRXIE (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQCC2_TXQOFTXIE_Pos         (18UL)         /*!< TXQOFTXIE (Bit 18)                                    */
#define R_CANFD_CFDTXQCC2_TXQOFTXIE_Msk         (0x40000UL)    /*!< TXQOFTXIE (Bitfield-Mask: 0x01)                       */
/* ======================================================  CFDTXQSTS2  ======================================================= */
#define R_CANFD_CFDTXQSTS2_TXQEMP_Pos           (0UL)          /*!< TXQEMP (Bit 0)                                        */
#define R_CANFD_CFDTXQSTS2_TXQEMP_Msk           (0x1UL)        /*!< TXQEMP (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS2_TXQFLL_Pos           (1UL)          /*!< TXQFLL (Bit 1)                                        */
#define R_CANFD_CFDTXQSTS2_TXQFLL_Msk           (0x2UL)        /*!< TXQFLL (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS2_TXQTXIF_Pos          (2UL)          /*!< TXQTXIF (Bit 2)                                       */
#define R_CANFD_CFDTXQSTS2_TXQTXIF_Msk          (0x4UL)        /*!< TXQTXIF (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDTXQSTS2_TXQMC_Pos            (8UL)          /*!< TXQMC (Bit 8)                                         */
#define R_CANFD_CFDTXQSTS2_TXQMC_Msk            (0x3f00UL)     /*!< TXQMC (Bitfield-Mask: 0x3f)                           */
#define R_CANFD_CFDTXQSTS2_TXQFIF_Pos           (16UL)         /*!< TXQFIF (Bit 16)                                       */
#define R_CANFD_CFDTXQSTS2_TXQFIF_Msk           (0x10000UL)    /*!< TXQFIF (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS2_TXQOFRXIF_Pos        (17UL)         /*!< TXQOFRXIF (Bit 17)                                    */
#define R_CANFD_CFDTXQSTS2_TXQOFRXIF_Msk        (0x20000UL)    /*!< TXQOFRXIF (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQSTS2_TXQOFTXIF_Pos        (18UL)         /*!< TXQOFTXIF (Bit 18)                                    */
#define R_CANFD_CFDTXQSTS2_TXQOFTXIF_Msk        (0x40000UL)    /*!< TXQOFTXIF (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQSTS2_TXQMLT_Pos           (19UL)         /*!< TXQMLT (Bit 19)                                       */
#define R_CANFD_CFDTXQSTS2_TXQMLT_Msk           (0x80000UL)    /*!< TXQMLT (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS2_TXQMOW_Pos           (20UL)         /*!< TXQMOW (Bit 20)                                       */
#define R_CANFD_CFDTXQSTS2_TXQMOW_Msk           (0x100000UL)   /*!< TXQMOW (Bitfield-Mask: 0x01)                          */
/* ======================================================  CFDTXQPCTR2  ====================================================== */
#define R_CANFD_CFDTXQPCTR2_TXQPC_Pos           (0UL)          /*!< TXQPC (Bit 0)                                         */
#define R_CANFD_CFDTXQPCTR2_TXQPC_Msk           (0xffUL)       /*!< TXQPC (Bitfield-Mask: 0xff)                           */
/* =======================================================  CFDTXQCC3  ======================================================= */
#define R_CANFD_CFDTXQCC3_TXQE_Pos              (0UL)          /*!< TXQE (Bit 0)                                          */
#define R_CANFD_CFDTXQCC3_TXQE_Msk              (0x1UL)        /*!< TXQE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDTXQCC3_TXQOWE_Pos            (2UL)          /*!< TXQOWE (Bit 2)                                        */
#define R_CANFD_CFDTXQCC3_TXQOWE_Msk            (0x4UL)        /*!< TXQOWE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQCC3_TXQTXIE_Pos           (5UL)          /*!< TXQTXIE (Bit 5)                                       */
#define R_CANFD_CFDTXQCC3_TXQTXIE_Msk           (0x20UL)       /*!< TXQTXIE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDTXQCC3_TXQIM_Pos             (7UL)          /*!< TXQIM (Bit 7)                                         */
#define R_CANFD_CFDTXQCC3_TXQIM_Msk             (0x80UL)       /*!< TXQIM (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTXQCC3_TXQDC_Pos             (8UL)          /*!< TXQDC (Bit 8)                                         */
#define R_CANFD_CFDTXQCC3_TXQDC_Msk             (0x1f00UL)     /*!< TXQDC (Bitfield-Mask: 0x1f)                           */
#define R_CANFD_CFDTXQCC3_TXQOFTXIE_Pos         (18UL)         /*!< TXQOFTXIE (Bit 18)                                    */
#define R_CANFD_CFDTXQCC3_TXQOFTXIE_Msk         (0x40000UL)    /*!< TXQOFTXIE (Bitfield-Mask: 0x01)                       */
/* ======================================================  CFDTXQSTS3  ======================================================= */
#define R_CANFD_CFDTXQSTS3_TXQEMP_Pos           (0UL)          /*!< TXQEMP (Bit 0)                                        */
#define R_CANFD_CFDTXQSTS3_TXQEMP_Msk           (0x1UL)        /*!< TXQEMP (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS3_TXQFLL_Pos           (1UL)          /*!< TXQFLL (Bit 1)                                        */
#define R_CANFD_CFDTXQSTS3_TXQFLL_Msk           (0x2UL)        /*!< TXQFLL (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTXQSTS3_TXQTXIF_Pos          (2UL)          /*!< TXQTXIF (Bit 2)                                       */
#define R_CANFD_CFDTXQSTS3_TXQTXIF_Msk          (0x4UL)        /*!< TXQTXIF (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDTXQSTS3_TXQMC_Pos            (8UL)          /*!< TXQMC (Bit 8)                                         */
#define R_CANFD_CFDTXQSTS3_TXQMC_Msk            (0x3f00UL)     /*!< TXQMC (Bitfield-Mask: 0x3f)                           */
#define R_CANFD_CFDTXQSTS3_TXQOFTXIF_Pos        (18UL)         /*!< TXQOFTXIF (Bit 18)                                    */
#define R_CANFD_CFDTXQSTS3_TXQOFTXIF_Msk        (0x40000UL)    /*!< TXQOFTXIF (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDTXQSTS3_TXQMOW_Pos           (20UL)         /*!< TXQMOW (Bit 20)                                       */
#define R_CANFD_CFDTXQSTS3_TXQMOW_Msk           (0x100000UL)   /*!< TXQMOW (Bitfield-Mask: 0x01)                          */
/* ======================================================  CFDTXQPCTR3  ====================================================== */
#define R_CANFD_CFDTXQPCTR3_TXQPC_Pos           (0UL)          /*!< TXQPC (Bit 0)                                         */
#define R_CANFD_CFDTXQPCTR3_TXQPC_Msk           (0xffUL)       /*!< TXQPC (Bitfield-Mask: 0xff)                           */
/* ======================================================  CFDTXQESTS  ======================================================= */
#define R_CANFD_CFDTXQESTS_TXQxEMP_Pos          (0UL)          /*!< TXQxEMP (Bit 0)                                       */
#define R_CANFD_CFDTXQESTS_TXQxEMP_Msk          (0xffffffUL)   /*!< TXQxEMP (Bitfield-Mask: 0xffffff)                     */
/* ======================================================  CFDTXQFISTS  ====================================================== */
#define R_CANFD_CFDTXQFISTS_TXQ0FULL_Pos        (0UL)          /*!< TXQ0FULL (Bit 0)                                      */
#define R_CANFD_CFDTXQFISTS_TXQ0FULL_Msk        (0x7UL)        /*!< TXQ0FULL (Bitfield-Mask: 0x07)                        */
#define R_CANFD_CFDTXQFISTS_TXQ1FULL_Pos        (4UL)          /*!< TXQ1FULL (Bit 4)                                      */
#define R_CANFD_CFDTXQFISTS_TXQ1FULL_Msk        (0x70UL)       /*!< TXQ1FULL (Bitfield-Mask: 0x07)                        */
#define R_CANFD_CFDTXQFISTS_TXQ2FULL_Pos        (8UL)          /*!< TXQ2FULL (Bit 8)                                      */
#define R_CANFD_CFDTXQFISTS_TXQ2FULL_Msk        (0x700UL)      /*!< TXQ2FULL (Bitfield-Mask: 0x07)                        */
#define R_CANFD_CFDTXQFISTS_TXQ3FULL_Pos        (12UL)         /*!< TXQ3FULL (Bit 12)                                     */
#define R_CANFD_CFDTXQFISTS_TXQ3FULL_Msk        (0x7000UL)     /*!< TXQ3FULL (Bitfield-Mask: 0x07)                        */
#define R_CANFD_CFDTXQFISTS_TXQ4FULL_Pos        (16UL)         /*!< TXQ4FULL (Bit 16)                                     */
#define R_CANFD_CFDTXQFISTS_TXQ4FULL_Msk        (0x70000UL)    /*!< TXQ4FULL (Bitfield-Mask: 0x07)                        */
#define R_CANFD_CFDTXQFISTS_TXQ5FULL_Pos        (20UL)         /*!< TXQ5FULL (Bit 20)                                     */
#define R_CANFD_CFDTXQFISTS_TXQ5FULL_Msk        (0x700000UL)   /*!< TXQ5FULL (Bitfield-Mask: 0x07)                        */
/* ======================================================  CFDTXQMSTS  ======================================================= */
#define R_CANFD_CFDTXQMSTS_TXQ0ML_Pos           (0UL)          /*!< TXQ0ML (Bit 0)                                        */
#define R_CANFD_CFDTXQMSTS_TXQ0ML_Msk           (0x7UL)        /*!< TXQ0ML (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDTXQMSTS_TXQ1ML_Pos           (4UL)          /*!< TXQ1ML (Bit 4)                                        */
#define R_CANFD_CFDTXQMSTS_TXQ1ML_Msk           (0x70UL)       /*!< TXQ1ML (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDTXQMSTS_TXQ2ML_Pos           (8UL)          /*!< TXQ2ML (Bit 8)                                        */
#define R_CANFD_CFDTXQMSTS_TXQ2ML_Msk           (0x700UL)      /*!< TXQ2ML (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDTXQMSTS_TXQ3ML_Pos           (12UL)         /*!< TXQ3ML (Bit 12)                                       */
#define R_CANFD_CFDTXQMSTS_TXQ3ML_Msk           (0x7000UL)     /*!< TXQ3ML (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDTXQMSTS_TXQ4ML_Pos           (16UL)         /*!< TXQ4ML (Bit 16)                                       */
#define R_CANFD_CFDTXQMSTS_TXQ4ML_Msk           (0x70000UL)    /*!< TXQ4ML (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDTXQMSTS_TXQ5ML_Pos           (20UL)         /*!< TXQ5ML (Bit 20)                                       */
#define R_CANFD_CFDTXQMSTS_TXQ5ML_Msk           (0x700000UL)   /*!< TXQ5ML (Bitfield-Mask: 0x07)                          */
/* ======================================================  CFDTXQOWSTS  ======================================================= */
#define R_CANFD_CFDTXQOWSTS_TXQ0OW_Pos          (0UL)          /*!< TXQ0OW (Bit 0)                                        */
#define R_CANFD_CFDTXQOWSTS_TXQ0OW_Msk          (0xfUL)        /*!< TXQ0OW (Bitfield-Mask: 0x0f)                          */
#define R_CANFD_CFDTXQOWSTS_TXQ1OW_Pos          (4UL)          /*!< TXQ1OW (Bit 4)                                        */
#define R_CANFD_CFDTXQOWSTS_TXQ1OW_Msk          (0xf0UL)       /*!< TXQ1OW (Bitfield-Mask: 0x0f)                          */
/* ======================================================  CFDTXQISTS  ======================================================= */
#define R_CANFD_CFDTXQISTS_TXQ0ISF_Pos          (0UL)          /*!< TXQ0ISF (Bit 0)                                       */
#define R_CANFD_CFDTXQISTS_TXQ0ISF_Msk          (0xfUL)        /*!< TXQ0ISF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQISTS_TXQ1ISF_Pos          (4UL)          /*!< TXQ1ISF (Bit 4)                                       */
#define R_CANFD_CFDTXQISTS_TXQ1ISF_Msk          (0xf0UL)       /*!< TXQ1ISF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQISTS_TXQ2ISF_Pos          (8UL)          /*!< TXQ2ISF (Bit 8)                                       */
#define R_CANFD_CFDTXQISTS_TXQ2ISF_Msk          (0xf00UL)      /*!< TXQ2ISF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQISTS_TXQ3ISF_Pos          (12UL)         /*!< TXQ3ISF (Bit 12)                                      */
#define R_CANFD_CFDTXQISTS_TXQ3ISF_Msk          (0xf000UL)     /*!< TXQ3ISF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQISTS_TXQ4ISF_Pos          (16UL)         /*!< TXQ4ISF (Bit 16)                                      */
#define R_CANFD_CFDTXQISTS_TXQ4ISF_Msk          (0xf0000UL)    /*!< TXQ4ISF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQISTS_TXQ5ISF_Pos          (20UL)         /*!< TXQ5ISF (Bit 20)                                      */
#define R_CANFD_CFDTXQISTS_TXQ5ISF_Msk          (0xf00000UL)   /*!< TXQ5ISF (Bitfield-Mask: 0x0f)                         */
/* =====================================================  CFDTXQOFTISTS  ===================================================== */
#define R_CANFD_CFDTXQOFTISTS_TXQ0OFTISF_Pos    (0UL)          /*!< TXQ0OFTISF (Bit 0)                                    */
#define R_CANFD_CFDTXQOFTISTS_TXQ0OFTISF_Msk    (0xfUL)        /*!< TXQ0OFTISF (Bitfield-Mask: 0x0f)                      */
#define R_CANFD_CFDTXQOFTISTS_TXQ1OFTISF_Pos    (4UL)          /*!< TXQ1OFTISF (Bit 4)                                    */
#define R_CANFD_CFDTXQOFTISTS_TXQ1OFTISF_Msk    (0xf0UL)       /*!< TXQ1OFTISF (Bitfield-Mask: 0x0f)                      */
#define R_CANFD_CFDTXQOFTISTS_TXQ2OFTISF_Pos    (8UL)          /*!< TXQ2OFTISF (Bit 8)                                    */
#define R_CANFD_CFDTXQOFTISTS_TXQ2OFTISF_Msk    (0xf00UL)      /*!< TXQ2OFTISF (Bitfield-Mask: 0x0f)                      */
#define R_CANFD_CFDTXQOFTISTS_TXQ3OFTISF_Pos    (12UL)         /*!< TXQ3OFTISF (Bit 12)                                   */
#define R_CANFD_CFDTXQOFTISTS_TXQ3OFTISF_Msk    (0xf000UL)     /*!< TXQ3OFTISF (Bitfield-Mask: 0x0f)                      */
#define R_CANFD_CFDTXQOFTISTS_TXQ4OFTISF_Pos    (16UL)         /*!< TXQ4OFTISF (Bit 16)                                   */
#define R_CANFD_CFDTXQOFTISTS_TXQ4OFTISF_Msk    (0xf0000UL)    /*!< TXQ4OFTISF (Bitfield-Mask: 0x0f)                      */
#define R_CANFD_CFDTXQOFTISTS_TXQ5OFTISF_Pos    (20UL)         /*!< TXQ5OFTISF (Bit 20)                                   */
#define R_CANFD_CFDTXQOFTISTS_TXQ5OFTISF_Msk    (0xf00000UL)   /*!< TXQ5OFTISF (Bitfield-Mask: 0x0f)                      */
/* =====================================================  CFDTXQOFRISTS  ===================================================== */
#define R_CANFD_CFDTXQOFRISTS_TXQ0OFRISF_Pos    (0UL)          /*!< TXQ0OFRISF (Bit 0)                                    */
#define R_CANFD_CFDTXQOFRISTS_TXQ0OFRISF_Msk    (0x7UL)        /*!< TXQ0OFRISF (Bitfield-Mask: 0x07)                      */
#define R_CANFD_CFDTXQOFRISTS_TXQ1OFRISF_Pos    (4UL)          /*!< TXQ1OFRISF (Bit 4)                                    */
#define R_CANFD_CFDTXQOFRISTS_TXQ1OFRISF_Msk    (0x70UL)       /*!< TXQ1OFRISF (Bitfield-Mask: 0x07)                      */
#define R_CANFD_CFDTXQOFRISTS_TXQ2OFRISF_Pos    (8UL)          /*!< TXQ2OFRISF (Bit 8)                                    */
#define R_CANFD_CFDTXQOFRISTS_TXQ2OFRISF_Msk    (0x700UL)      /*!< TXQ2OFRISF (Bitfield-Mask: 0x07)                      */
#define R_CANFD_CFDTXQOFRISTS_TXQ3OFRISF_Pos    (12UL)         /*!< TXQ3OFRISF (Bit 12)                                   */
#define R_CANFD_CFDTXQOFRISTS_TXQ3OFRISF_Msk    (0x7000UL)     /*!< TXQ3OFRISF (Bitfield-Mask: 0x07)                      */
#define R_CANFD_CFDTXQOFRISTS_TXQ4OFRISF_Pos    (16UL)         /*!< TXQ4OFRISF (Bit 16)                                   */
#define R_CANFD_CFDTXQOFRISTS_TXQ4OFRISF_Msk    (0x70000UL)    /*!< TXQ4OFRISF (Bitfield-Mask: 0x07)                      */
#define R_CANFD_CFDTXQOFRISTS_TXQ5OFRISF_Pos    (20UL)         /*!< TXQ5OFRISF (Bit 20)                                   */
#define R_CANFD_CFDTXQOFRISTS_TXQ5OFRISF_Msk    (0x700000UL)   /*!< TXQ5OFRISF (Bitfield-Mask: 0x07)                      */
/* ======================================================  CFDTXQFSTS  ======================================================= */
#define R_CANFD_CFDTXQFSTS_TXQ0FSF_Pos          (0UL)          /*!< TXQ0FSF (Bit 0)                                       */
#define R_CANFD_CFDTXQFSTS_TXQ0FSF_Msk          (0xfUL)        /*!< TXQ0FSF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQFSTS_TXQ1FSF_Pos          (4UL)          /*!< TXQ1FSF (Bit 4)                                       */
#define R_CANFD_CFDTXQFSTS_TXQ1FSF_Msk          (0xf0UL)       /*!< TXQ1FSF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQFSTS_TXQ2FSF_Pos          (8UL)          /*!< TXQ2FSF (Bit 8)                                       */
#define R_CANFD_CFDTXQFSTS_TXQ2FSF_Msk          (0xf00UL)      /*!< TXQ2FSF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQFSTS_TXQ3FSF_Pos          (12UL)         /*!< TXQ3FSF (Bit 12)                                      */
#define R_CANFD_CFDTXQFSTS_TXQ3FSF_Msk          (0xf000UL)     /*!< TXQ3FSF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQFSTS_TXQ4FSF_Pos          (16UL)         /*!< TXQ4FSF (Bit 16)                                      */
#define R_CANFD_CFDTXQFSTS_TXQ4FSF_Msk          (0xf0000UL)    /*!< TXQ4FSF (Bitfield-Mask: 0x0f)                         */
#define R_CANFD_CFDTXQFSTS_TXQ5FSF_Pos          (20UL)         /*!< TXQ5FSF (Bit 20)                                      */
#define R_CANFD_CFDTXQFSTS_TXQ5FSF_Msk          (0xf00000UL)   /*!< TXQ5FSF (Bitfield-Mask: 0x0f)                         */
/* =======================================================  CFDTHLCC  ======================================================== */
#define R_CANFD_CFDTHLCC_THLE_Pos               (0UL)          /*!< THLE (Bit 0)                                          */
#define R_CANFD_CFDTHLCC_THLE_Msk               (0x1UL)        /*!< THLE (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDTHLCC_THLIE_Pos              (8UL)          /*!< THLIE (Bit 8)                                         */
#define R_CANFD_CFDTHLCC_THLIE_Msk              (0x100UL)      /*!< THLIE (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTHLCC_THLIM_Pos              (9UL)          /*!< THLIM (Bit 9)                                         */
#define R_CANFD_CFDTHLCC_THLIM_Msk              (0x200UL)      /*!< THLIM (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTHLCC_THLDTE_Pos             (10UL)         /*!< THLDTE (Bit 10)                                       */
#define R_CANFD_CFDTHLCC_THLDTE_Msk             (0x400UL)      /*!< THLDTE (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTHLCC_THLDGE_Pos             (11UL)         /*!< THLDGE (Bit 11)                                       */
#define R_CANFD_CFDTHLCC_THLDGE_Msk             (0x800UL)      /*!< THLDGE (Bitfield-Mask: 0x01)                          */
/* =======================================================  CFDTHLSTS  ======================================================= */
#define R_CANFD_CFDTHLSTS_THLEMP_Pos            (0UL)          /*!< THLEMP (Bit 0)                                        */
#define R_CANFD_CFDTHLSTS_THLEMP_Msk            (0x1UL)        /*!< THLEMP (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTHLSTS_THLFLL_Pos            (1UL)          /*!< THLFLL (Bit 1)                                        */
#define R_CANFD_CFDTHLSTS_THLFLL_Msk            (0x2UL)        /*!< THLFLL (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTHLSTS_THLELT_Pos            (2UL)          /*!< THLELT (Bit 2)                                        */
#define R_CANFD_CFDTHLSTS_THLELT_Msk            (0x4UL)        /*!< THLELT (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDTHLSTS_THLIF_Pos             (3UL)          /*!< THLIF (Bit 3)                                         */
#define R_CANFD_CFDTHLSTS_THLIF_Msk             (0x8UL)        /*!< THLIF (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDTHLSTS_THLMC_Pos             (8UL)          /*!< THLMC (Bit 8)                                         */
#define R_CANFD_CFDTHLSTS_THLMC_Msk             (0x3f00UL)     /*!< THLMC (Bitfield-Mask: 0x3f)                           */
/* ======================================================  CFDTHLPCTR  ======================================================= */
#define R_CANFD_CFDTHLPCTR_THLPC_Pos            (0UL)          /*!< THLPC (Bit 0)                                         */
#define R_CANFD_CFDTHLPCTR_THLPC_Msk            (0xffUL)       /*!< THLPC (Bitfield-Mask: 0xff)                           */
/* =====================================================  CFDGTINTSTS0  ====================================================== */
#define R_CANFD_CFDGTINTSTS0_TSIF0_Pos          (0UL)          /*!< TSIF0 (Bit 0)                                         */
#define R_CANFD_CFDGTINTSTS0_TSIF0_Msk          (0x1UL)        /*!< TSIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TAIF0_Pos          (1UL)          /*!< TAIF0 (Bit 1)                                         */
#define R_CANFD_CFDGTINTSTS0_TAIF0_Msk          (0x2UL)        /*!< TAIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQIF0_Pos          (2UL)          /*!< TQIF0 (Bit 2)                                         */
#define R_CANFD_CFDGTINTSTS0_TQIF0_Msk          (0x4UL)        /*!< TQIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_CFTIF0_Pos         (3UL)          /*!< CFTIF0 (Bit 3)                                        */
#define R_CANFD_CFDGTINTSTS0_CFTIF0_Msk         (0x8UL)        /*!< CFTIF0 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGTINTSTS0_THIF0_Pos          (4UL)          /*!< THIF0 (Bit 4)                                         */
#define R_CANFD_CFDGTINTSTS0_THIF0_Msk          (0x10UL)       /*!< THIF0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQOFIF0_Pos        (5UL)          /*!< TQOFIF0 (Bit 5)                                       */
#define R_CANFD_CFDGTINTSTS0_TQOFIF0_Msk        (0x20UL)       /*!< TQOFIF0 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS0_CFOTIF0_Pos        (6UL)          /*!< CFOTIF0 (Bit 6)                                       */
#define R_CANFD_CFDGTINTSTS0_CFOTIF0_Msk        (0x40UL)       /*!< CFOTIF0 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS0_TSIF1_Pos          (8UL)          /*!< TSIF1 (Bit 8)                                         */
#define R_CANFD_CFDGTINTSTS0_TSIF1_Msk          (0x100UL)      /*!< TSIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TAIF1_Pos          (9UL)          /*!< TAIF1 (Bit 9)                                         */
#define R_CANFD_CFDGTINTSTS0_TAIF1_Msk          (0x200UL)      /*!< TAIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQIF1_Pos          (10UL)         /*!< TQIF1 (Bit 10)                                        */
#define R_CANFD_CFDGTINTSTS0_TQIF1_Msk          (0x400UL)      /*!< TQIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_CFTIF1_Pos         (11UL)         /*!< CFTIF1 (Bit 11)                                       */
#define R_CANFD_CFDGTINTSTS0_CFTIF1_Msk         (0x800UL)      /*!< CFTIF1 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGTINTSTS0_THIF1_Pos          (12UL)         /*!< THIF1 (Bit 12)                                        */
#define R_CANFD_CFDGTINTSTS0_THIF1_Msk          (0x1000UL)     /*!< THIF1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQOFIF1_Pos        (13UL)         /*!< TQOFIF1 (Bit 13)                                      */
#define R_CANFD_CFDGTINTSTS0_TQOFIF1_Msk        (0x2000UL)     /*!< TQOFIF1 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS0_CFOTIF1_Pos        (14UL)         /*!< CFOTIF1 (Bit 14)                                      */
#define R_CANFD_CFDGTINTSTS0_CFOTIF1_Msk        (0x4000UL)     /*!< CFOTIF1 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS0_TSIF2_Pos          (16UL)         /*!< TSIF2 (Bit 16)                                        */
#define R_CANFD_CFDGTINTSTS0_TSIF2_Msk          (0x10000UL)    /*!< TSIF2 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TAIF2_Pos          (17UL)         /*!< TAIF2 (Bit 17)                                        */
#define R_CANFD_CFDGTINTSTS0_TAIF2_Msk          (0x20000UL)    /*!< TAIF2 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQIF2_Pos          (18UL)         /*!< TQIF2 (Bit 18)                                        */
#define R_CANFD_CFDGTINTSTS0_TQIF2_Msk          (0x40000UL)    /*!< TQIF2 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_CFTIF2_Pos         (19UL)         /*!< CFTIF2 (Bit 19)                                       */
#define R_CANFD_CFDGTINTSTS0_CFTIF2_Msk         (0x80000UL)    /*!< CFTIF2 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGTINTSTS0_THIF2_Pos          (20UL)         /*!< THIF2 (Bit 20)                                        */
#define R_CANFD_CFDGTINTSTS0_THIF2_Msk          (0x100000UL)   /*!< THIF2 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQOFIF2_Pos        (21UL)         /*!< TQOFIF2 (Bit 21)                                      */
#define R_CANFD_CFDGTINTSTS0_TQOFIF2_Msk        (0x200000UL)   /*!< TQOFIF2 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS0_CFOTIF2_Pos        (22UL)         /*!< CFOTIF2 (Bit 22)                                      */
#define R_CANFD_CFDGTINTSTS0_CFOTIF2_Msk        (0x400000UL)   /*!< CFOTIF2 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS0_TSIF3_Pos          (24UL)         /*!< TSIF3 (Bit 24)                                        */
#define R_CANFD_CFDGTINTSTS0_TSIF3_Msk          (0x1000000UL)  /*!< TSIF3 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TAIF3_Pos          (25UL)         /*!< TAIF3 (Bit 25)                                        */
#define R_CANFD_CFDGTINTSTS0_TAIF3_Msk          (0x2000000UL)  /*!< TAIF3 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQIF3_Pos          (26UL)         /*!< TQIF3 (Bit 26)                                        */
#define R_CANFD_CFDGTINTSTS0_TQIF3_Msk          (0x4000000UL)  /*!< TQIF3 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_CFTIF3_Pos         (27UL)         /*!< CFTIF3 (Bit 27)                                       */
#define R_CANFD_CFDGTINTSTS0_CFTIF3_Msk         (0x8000000UL)  /*!< CFTIF3 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGTINTSTS0_THIF3_Pos          (28UL)         /*!< THIF3 (Bit 28)                                        */
#define R_CANFD_CFDGTINTSTS0_THIF3_Msk          (0x10000000UL) /*!< THIF3 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS0_TQOFIF3_Pos        (29UL)         /*!< TQOFIF3 (Bit 29)                                      */
#define R_CANFD_CFDGTINTSTS0_TQOFIF3_Msk        (0x20000000UL) /*!< TQOFIF3 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS0_CFOTIF3_Pos        (30UL)         /*!< CFOTIF3 (Bit 30)                                      */
#define R_CANFD_CFDGTINTSTS0_CFOTIF3_Msk        (0x40000000UL) /*!< CFOTIF3 (Bitfield-Mask: 0x01)                         */
/* =====================================================  CFDGTINTSTS1  ====================================================== */
#define R_CANFD_CFDGTINTSTS1_TSIF4_Pos          (0UL)          /*!< TSIF4 (Bit 0)                                         */
#define R_CANFD_CFDGTINTSTS1_TSIF4_Msk          (0x1UL)        /*!< TSIF4 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS1_TAIF4_Pos          (1UL)          /*!< TAIF4 (Bit 1)                                         */
#define R_CANFD_CFDGTINTSTS1_TAIF4_Msk          (0x2UL)        /*!< TAIF4 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS1_TQIF4_Pos          (2UL)          /*!< TQIF4 (Bit 2)                                         */
#define R_CANFD_CFDGTINTSTS1_TQIF4_Msk          (0x4UL)        /*!< TQIF4 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS1_CFTIF4_Pos         (3UL)          /*!< CFTIF4 (Bit 3)                                        */
#define R_CANFD_CFDGTINTSTS1_CFTIF4_Msk         (0x8UL)        /*!< CFTIF4 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGTINTSTS1_THIF4_Pos          (4UL)          /*!< THIF4 (Bit 4)                                         */
#define R_CANFD_CFDGTINTSTS1_THIF4_Msk          (0x10UL)       /*!< THIF4 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS1_TQOFIF4_Pos        (5UL)          /*!< TQOFIF4 (Bit 5)                                       */
#define R_CANFD_CFDGTINTSTS1_TQOFIF4_Msk        (0x20UL)       /*!< TQOFIF4 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS1_CFOTIF4_Pos        (6UL)          /*!< CFOTIF4 (Bit 6)                                       */
#define R_CANFD_CFDGTINTSTS1_CFOTIF4_Msk        (0x40UL)       /*!< CFOTIF4 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS1_TSIF5_Pos          (8UL)          /*!< TSIF5 (Bit 8)                                         */
#define R_CANFD_CFDGTINTSTS1_TSIF5_Msk          (0x100UL)      /*!< TSIF5 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS1_TAIF5_Pos          (9UL)          /*!< TAIF5 (Bit 9)                                         */
#define R_CANFD_CFDGTINTSTS1_TAIF5_Msk          (0x200UL)      /*!< TAIF5 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS1_TQIF5_Pos          (10UL)         /*!< TQIF5 (Bit 10)                                        */
#define R_CANFD_CFDGTINTSTS1_TQIF5_Msk          (0x400UL)      /*!< TQIF5 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS1_CFTIF5_Pos         (11UL)         /*!< CFTIF5 (Bit 11)                                       */
#define R_CANFD_CFDGTINTSTS1_CFTIF5_Msk         (0x800UL)      /*!< CFTIF5 (Bitfield-Mask: 0x01)                          */
#define R_CANFD_CFDGTINTSTS1_THIF5_Pos          (12UL)         /*!< THIF5 (Bit 12)                                        */
#define R_CANFD_CFDGTINTSTS1_THIF5_Msk          (0x1000UL)     /*!< THIF5 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGTINTSTS1_TQOFIF5_Pos        (13UL)         /*!< TQOFIF5 (Bit 13)                                      */
#define R_CANFD_CFDGTINTSTS1_TQOFIF5_Msk        (0x2000UL)     /*!< TQOFIF5 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTINTSTS1_CFOTIF5_Pos        (14UL)         /*!< CFOTIF5 (Bit 14)                                      */
#define R_CANFD_CFDGTINTSTS1_CFOTIF5_Msk        (0x4000UL)     /*!< CFOTIF5 (Bitfield-Mask: 0x01)                         */
/* ======================================================  CFDGTSTCFG  ======================================================= */
#define R_CANFD_CFDGTSTCFG_C0ICBCE_Pos          (0UL)          /*!< C0ICBCE (Bit 0)                                       */
#define R_CANFD_CFDGTSTCFG_C0ICBCE_Msk          (0x1UL)        /*!< C0ICBCE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCFG_C1ICBCE_Pos          (1UL)          /*!< C1ICBCE (Bit 1)                                       */
#define R_CANFD_CFDGTSTCFG_C1ICBCE_Msk          (0x2UL)        /*!< C1ICBCE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCFG_C2ICBCE_Pos          (2UL)          /*!< C2ICBCE (Bit 2)                                       */
#define R_CANFD_CFDGTSTCFG_C2ICBCE_Msk          (0x4UL)        /*!< C2ICBCE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCFG_C3ICBCE_Pos          (3UL)          /*!< C3ICBCE (Bit 3)                                       */
#define R_CANFD_CFDGTSTCFG_C3ICBCE_Msk          (0x8UL)        /*!< C3ICBCE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCFG_C4ICBCE_Pos          (4UL)          /*!< C4ICBCE (Bit 4)                                       */
#define R_CANFD_CFDGTSTCFG_C4ICBCE_Msk          (0x10UL)       /*!< C4ICBCE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCFG_C5ICBCE_Pos          (5UL)          /*!< C5ICBCE (Bit 5)                                       */
#define R_CANFD_CFDGTSTCFG_C5ICBCE_Msk          (0x20UL)       /*!< C5ICBCE (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCFG_RTMPS_Pos            (16UL)         /*!< RTMPS (Bit 16)                                        */
#define R_CANFD_CFDGTSTCFG_RTMPS_Msk            (0x3ff0000UL)  /*!< RTMPS (Bitfield-Mask: 0x3ff)                          */
/* ======================================================  CFDGTSTCTR  ======================================================= */
#define R_CANFD_CFDGTSTCTR_ICBCTME_Pos          (0UL)          /*!< ICBCTME (Bit 0)                                       */
#define R_CANFD_CFDGTSTCTR_ICBCTME_Msk          (0x1UL)        /*!< ICBCTME (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDGTSTCTR_RTME_Pos             (2UL)          /*!< RTME (Bit 2)                                          */
#define R_CANFD_CFDGTSTCTR_RTME_Msk             (0x4UL)        /*!< RTME (Bitfield-Mask: 0x01)                            */
/* =======================================================  CFDGFDCFG  ======================================================= */
#define R_CANFD_CFDGFDCFG_RPED_Pos              (0UL)          /*!< RPED (Bit 0)                                          */
#define R_CANFD_CFDGFDCFG_RPED_Msk              (0x1UL)        /*!< RPED (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGFDCFG_TSCCFG_Pos            (8UL)          /*!< TSCCFG (Bit 8)                                        */
#define R_CANFD_CFDGFDCFG_TSCCFG_Msk            (0x300UL)      /*!< TSCCFG (Bitfield-Mask: 0x03)                          */
/* =======================================================  CFDGLOCKK  ======================================================= */
#define R_CANFD_CFDGLOCKK_LOCK_Pos              (0UL)          /*!< LOCK (Bit 0)                                          */
#define R_CANFD_CFDGLOCKK_LOCK_Msk              (0xffffUL)     /*!< LOCK (Bitfield-Mask: 0xffff)                          */
/* =======================================================  CFDCDTCT  ======================================================== */
#define R_CANFD_CFDCDTCT_RFDMAE0_Pos            (0UL)          /*!< RFDMAE0 (Bit 0)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE0_Msk            (0x1UL)        /*!< RFDMAE0 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE1_Pos            (1UL)          /*!< RFDMAE1 (Bit 1)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE1_Msk            (0x2UL)        /*!< RFDMAE1 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE2_Pos            (2UL)          /*!< RFDMAE2 (Bit 2)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE2_Msk            (0x4UL)        /*!< RFDMAE2 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE3_Pos            (3UL)          /*!< RFDMAE3 (Bit 3)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE3_Msk            (0x8UL)        /*!< RFDMAE3 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE4_Pos            (4UL)          /*!< RFDMAE4 (Bit 4)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE4_Msk            (0x10UL)       /*!< RFDMAE4 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE5_Pos            (5UL)          /*!< RFDMAE5 (Bit 5)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE5_Msk            (0x20UL)       /*!< RFDMAE5 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE6_Pos            (6UL)          /*!< RFDMAE6 (Bit 6)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE6_Msk            (0x40UL)       /*!< RFDMAE6 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_RFDMAE7_Pos            (7UL)          /*!< RFDMAE7 (Bit 7)                                       */
#define R_CANFD_CFDCDTCT_RFDMAE7_Msk            (0x80UL)       /*!< RFDMAE7 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_CFDMAE0_Pos            (8UL)          /*!< CFDMAE0 (Bit 8)                                       */
#define R_CANFD_CFDCDTCT_CFDMAE0_Msk            (0x100UL)      /*!< CFDMAE0 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_CFDMAE1_Pos            (9UL)          /*!< CFDMAE1 (Bit 9)                                       */
#define R_CANFD_CFDCDTCT_CFDMAE1_Msk            (0x200UL)      /*!< CFDMAE1 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_CFDMAE2_Pos            (10UL)         /*!< CFDMAE2 (Bit 10)                                      */
#define R_CANFD_CFDCDTCT_CFDMAE2_Msk            (0x400UL)      /*!< CFDMAE2 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_CFDMAE3_Pos            (11UL)         /*!< CFDMAE3 (Bit 11)                                      */
#define R_CANFD_CFDCDTCT_CFDMAE3_Msk            (0x800UL)      /*!< CFDMAE3 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_CFDMAE4_Pos            (12UL)         /*!< CFDMAE4 (Bit 12)                                      */
#define R_CANFD_CFDCDTCT_CFDMAE4_Msk            (0x1000UL)     /*!< CFDMAE4 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTCT_CFDMAE5_Pos            (13UL)         /*!< CFDMAE5 (Bit 13)                                      */
#define R_CANFD_CFDCDTCT_CFDMAE5_Msk            (0x2000UL)     /*!< CFDMAE5 (Bitfield-Mask: 0x01)                         */
/* =======================================================  CFDCDTSTS  ======================================================= */
#define R_CANFD_CFDCDTSTS_RFDMASTS0_Pos         (0UL)          /*!< RFDMASTS0 (Bit 0)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS0_Msk         (0x1UL)        /*!< RFDMASTS0 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS1_Pos         (1UL)          /*!< RFDMASTS1 (Bit 1)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS1_Msk         (0x2UL)        /*!< RFDMASTS1 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS2_Pos         (2UL)          /*!< RFDMASTS2 (Bit 2)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS2_Msk         (0x4UL)        /*!< RFDMASTS2 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS3_Pos         (3UL)          /*!< RFDMASTS3 (Bit 3)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS3_Msk         (0x8UL)        /*!< RFDMASTS3 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS4_Pos         (4UL)          /*!< RFDMASTS4 (Bit 4)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS4_Msk         (0x10UL)       /*!< RFDMASTS4 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS5_Pos         (5UL)          /*!< RFDMASTS5 (Bit 5)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS5_Msk         (0x20UL)       /*!< RFDMASTS5 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS6_Pos         (6UL)          /*!< RFDMASTS6 (Bit 6)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS6_Msk         (0x40UL)       /*!< RFDMASTS6 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_RFDMASTS7_Pos         (7UL)          /*!< RFDMASTS7 (Bit 7)                                     */
#define R_CANFD_CFDCDTSTS_RFDMASTS7_Msk         (0x80UL)       /*!< RFDMASTS7 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_CFDMASTS0_Pos         (8UL)          /*!< CFDMASTS0 (Bit 8)                                     */
#define R_CANFD_CFDCDTSTS_CFDMASTS0_Msk         (0x100UL)      /*!< CFDMASTS0 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_CFDMASTS1_Pos         (9UL)          /*!< CFDMASTS1 (Bit 9)                                     */
#define R_CANFD_CFDCDTSTS_CFDMASTS1_Msk         (0x200UL)      /*!< CFDMASTS1 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_CFDMASTS2_Pos         (10UL)         /*!< CFDMASTS2 (Bit 10)                                    */
#define R_CANFD_CFDCDTSTS_CFDMASTS2_Msk         (0x400UL)      /*!< CFDMASTS2 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_CFDMASTS3_Pos         (11UL)         /*!< CFDMASTS3 (Bit 11)                                    */
#define R_CANFD_CFDCDTSTS_CFDMASTS3_Msk         (0x800UL)      /*!< CFDMASTS3 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_CFDMASTS4_Pos         (12UL)         /*!< CFDMASTS4 (Bit 12)                                    */
#define R_CANFD_CFDCDTSTS_CFDMASTS4_Msk         (0x1000UL)     /*!< CFDMASTS4 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTSTS_CFDMASTS5_Pos         (13UL)         /*!< CFDMASTS5 (Bit 13)                                    */
#define R_CANFD_CFDCDTSTS_CFDMASTS5_Msk         (0x2000UL)     /*!< CFDMASTS5 (Bitfield-Mask: 0x01)                       */
/* =======================================================  CFDCDTTCT  ======================================================= */
#define R_CANFD_CFDCDTTCT_TQ0DMAE0_Pos          (0UL)          /*!< TQ0DMAE0 (Bit 0)                                      */
#define R_CANFD_CFDCDTTCT_TQ0DMAE0_Msk          (0x1UL)        /*!< TQ0DMAE0 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ0DMAE1_Pos          (1UL)          /*!< TQ0DMAE1 (Bit 1)                                      */
#define R_CANFD_CFDCDTTCT_TQ0DMAE1_Msk          (0x2UL)        /*!< TQ0DMAE1 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ0DMAE2_Pos          (2UL)          /*!< TQ0DMAE2 (Bit 2)                                      */
#define R_CANFD_CFDCDTTCT_TQ0DMAE2_Msk          (0x4UL)        /*!< TQ0DMAE2 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ0DMAE3_Pos          (3UL)          /*!< TQ0DMAE3 (Bit 3)                                      */
#define R_CANFD_CFDCDTTCT_TQ0DMAE3_Msk          (0x8UL)        /*!< TQ0DMAE3 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ0DMAE4_Pos          (4UL)          /*!< TQ0DMAE4 (Bit 4)                                      */
#define R_CANFD_CFDCDTTCT_TQ0DMAE4_Msk          (0x10UL)       /*!< TQ0DMAE4 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ0DMAE5_Pos          (5UL)          /*!< TQ0DMAE5 (Bit 5)                                      */
#define R_CANFD_CFDCDTTCT_TQ0DMAE5_Msk          (0x20UL)       /*!< TQ0DMAE5 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ3DMAE0_Pos          (8UL)          /*!< TQ3DMAE0 (Bit 8)                                      */
#define R_CANFD_CFDCDTTCT_TQ3DMAE0_Msk          (0x100UL)      /*!< TQ3DMAE0 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ3DMAE1_Pos          (9UL)          /*!< TQ3DMAE1 (Bit 9)                                      */
#define R_CANFD_CFDCDTTCT_TQ3DMAE1_Msk          (0x200UL)      /*!< TQ3DMAE1 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ3DMAE2_Pos          (10UL)         /*!< TQ3DMAE2 (Bit 10)                                     */
#define R_CANFD_CFDCDTTCT_TQ3DMAE2_Msk          (0x400UL)      /*!< TQ3DMAE2 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ3DMAE3_Pos          (11UL)         /*!< TQ3DMAE3 (Bit 11)                                     */
#define R_CANFD_CFDCDTTCT_TQ3DMAE3_Msk          (0x800UL)      /*!< TQ3DMAE3 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ3DMAE4_Pos          (12UL)         /*!< TQ3DMAE4 (Bit 12)                                     */
#define R_CANFD_CFDCDTTCT_TQ3DMAE4_Msk          (0x1000UL)     /*!< TQ3DMAE4 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_TQ3DMAE5_Pos          (13UL)         /*!< TQ3DMAE5 (Bit 13)                                     */
#define R_CANFD_CFDCDTTCT_TQ3DMAE5_Msk          (0x2000UL)     /*!< TQ3DMAE5 (Bitfield-Mask: 0x01)                        */
#define R_CANFD_CFDCDTTCT_CFDMAE0_Pos           (16UL)         /*!< CFDMAE0 (Bit 16)                                      */
#define R_CANFD_CFDCDTTCT_CFDMAE0_Msk           (0x10000UL)    /*!< CFDMAE0 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTTCT_CFDMAE1_Pos           (17UL)         /*!< CFDMAE1 (Bit 17)                                      */
#define R_CANFD_CFDCDTTCT_CFDMAE1_Msk           (0x20000UL)    /*!< CFDMAE1 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTTCT_CFDMAE2_Pos           (18UL)         /*!< CFDMAE2 (Bit 18)                                      */
#define R_CANFD_CFDCDTTCT_CFDMAE2_Msk           (0x40000UL)    /*!< CFDMAE2 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTTCT_CFDMAE3_Pos           (19UL)         /*!< CFDMAE3 (Bit 19)                                      */
#define R_CANFD_CFDCDTTCT_CFDMAE3_Msk           (0x80000UL)    /*!< CFDMAE3 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTTCT_CFDMAE4_Pos           (20UL)         /*!< CFDMAE4 (Bit 20)                                      */
#define R_CANFD_CFDCDTTCT_CFDMAE4_Msk           (0x100000UL)   /*!< CFDMAE4 (Bitfield-Mask: 0x01)                         */
#define R_CANFD_CFDCDTTCT_CFDMAE5_Pos           (21UL)         /*!< CFDMAE5 (Bit 21)                                      */
#define R_CANFD_CFDCDTTCT_CFDMAE5_Msk           (0x200000UL)   /*!< CFDMAE5 (Bitfield-Mask: 0x01)                         */
/* ======================================================  CFDCDTTSTS  ======================================================= */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS0_Pos       (0UL)          /*!< TQ0DMASTS0 (Bit 0)                                    */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS0_Msk       (0x1UL)        /*!< TQ0DMASTS0 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS1_Pos       (1UL)          /*!< TQ0DMASTS1 (Bit 1)                                    */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS1_Msk       (0x2UL)        /*!< TQ0DMASTS1 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS2_Pos       (2UL)          /*!< TQ0DMASTS2 (Bit 2)                                    */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS2_Msk       (0x4UL)        /*!< TQ0DMASTS2 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS3_Pos       (3UL)          /*!< TQ0DMASTS3 (Bit 3)                                    */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS3_Msk       (0x8UL)        /*!< TQ0DMASTS3 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS4_Pos       (4UL)          /*!< TQ0DMASTS4 (Bit 4)                                    */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS4_Msk       (0x10UL)       /*!< TQ0DMASTS4 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS5_Pos       (5UL)          /*!< TQ0DMASTS5 (Bit 5)                                    */
#define R_CANFD_CFDCDTTSTS_TQ0DMASTS5_Msk       (0x20UL)       /*!< TQ0DMASTS5 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS0_Pos       (8UL)          /*!< TQ3DMASTS0 (Bit 8)                                    */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS0_Msk       (0x100UL)      /*!< TQ3DMASTS0 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS1_Pos       (9UL)          /*!< TQ3DMASTS1 (Bit 9)                                    */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS1_Msk       (0x200UL)      /*!< TQ3DMASTS1 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS2_Pos       (10UL)         /*!< TQ3DMASTS2 (Bit 10)                                   */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS2_Msk       (0x400UL)      /*!< TQ3DMASTS2 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS3_Pos       (11UL)         /*!< TQ3DMASTS3 (Bit 11)                                   */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS3_Msk       (0x800UL)      /*!< TQ3DMASTS3 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS4_Pos       (12UL)         /*!< TQ3DMASTS4 (Bit 12)                                   */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS4_Msk       (0x1000UL)     /*!< TQ3DMASTS4 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS5_Pos       (13UL)         /*!< TQ3DMASTS5 (Bit 13)                                   */
#define R_CANFD_CFDCDTTSTS_TQ3DMASTS5_Msk       (0x2000UL)     /*!< TQ3DMASTS5 (Bitfield-Mask: 0x01)                      */
#define R_CANFD_CFDCDTTSTS_CFDMASTS0_Pos        (16UL)         /*!< CFDMASTS0 (Bit 16)                                    */
#define R_CANFD_CFDCDTTSTS_CFDMASTS0_Msk        (0x10000UL)    /*!< CFDMASTS0 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTTSTS_CFDMASTS1_Pos        (17UL)         /*!< CFDMASTS1 (Bit 17)                                    */
#define R_CANFD_CFDCDTTSTS_CFDMASTS1_Msk        (0x20000UL)    /*!< CFDMASTS1 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTTSTS_CFDMASTS2_Pos        (18UL)         /*!< CFDMASTS2 (Bit 18)                                    */
#define R_CANFD_CFDCDTTSTS_CFDMASTS2_Msk        (0x40000UL)    /*!< CFDMASTS2 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTTSTS_CFDMASTS3_Pos        (19UL)         /*!< CFDMASTS3 (Bit 19)                                    */
#define R_CANFD_CFDCDTTSTS_CFDMASTS3_Msk        (0x80000UL)    /*!< CFDMASTS3 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTTSTS_CFDMASTS4_Pos        (20UL)         /*!< CFDMASTS4 (Bit 20)                                    */
#define R_CANFD_CFDCDTTSTS_CFDMASTS4_Msk        (0x100000UL)   /*!< CFDMASTS4 (Bitfield-Mask: 0x01)                       */
#define R_CANFD_CFDCDTTSTS_CFDMASTS5_Pos        (21UL)         /*!< CFDMASTS5 (Bit 21)                                    */
#define R_CANFD_CFDCDTTSTS_CFDMASTS5_Msk        (0x200000UL)   /*!< CFDMASTS5 (Bitfield-Mask: 0x01)                       */
/* ======================================================  CFDGRINTSTS  ====================================================== */
#define R_CANFD_CFDGRINTSTS_QFIF_Pos            (0UL)          /*!< QFIF (Bit 0)                                          */
#define R_CANFD_CFDGRINTSTS_QFIF_Msk            (0x7UL)        /*!< QFIF (Bitfield-Mask: 0x07)                            */
#define R_CANFD_CFDGRINTSTS_BQFIF_Pos           (4UL)          /*!< BQFIF (Bit 4)                                         */
#define R_CANFD_CFDGRINTSTS_BQFIF_Msk           (0x30UL)       /*!< BQFIF (Bitfield-Mask: 0x03)                           */
#define R_CANFD_CFDGRINTSTS_QOFRIF_Pos          (8UL)          /*!< QOFRIF (Bit 8)                                        */
#define R_CANFD_CFDGRINTSTS_QOFRIF_Msk          (0x700UL)      /*!< QOFRIF (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDGRINTSTS_BQOFRIF_Pos         (12UL)         /*!< BQOFRIF (Bit 12)                                      */
#define R_CANFD_CFDGRINTSTS_BQOFRIF_Msk         (0x3000UL)     /*!< BQOFRIF (Bitfield-Mask: 0x03)                         */
#define R_CANFD_CFDGRINTSTS_CFRIF_Pos           (16UL)         /*!< CFRIF (Bit 16)                                        */
#define R_CANFD_CFDGRINTSTS_CFRIF_Msk           (0x70000UL)    /*!< CFRIF (Bitfield-Mask: 0x07)                           */
#define R_CANFD_CFDGRINTSTS_CFRFIF_Pos          (24UL)         /*!< CFRFIF (Bit 24)                                       */
#define R_CANFD_CFDGRINTSTS_CFRFIF_Msk          (0x7000000UL)  /*!< CFRFIF (Bitfield-Mask: 0x07)                          */
#define R_CANFD_CFDGRINTSTS_CFOFRIF_Pos         (28UL)         /*!< CFOFRIF (Bit 28)                                      */
#define R_CANFD_CFDGRINTSTS_CFOFRIF_Msk         (0x70000000UL) /*!< CFOFRIF (Bitfield-Mask: 0x07)                         */
/* =======================================================  CFDGRSTC  ======================================================== */
#define R_CANFD_CFDGRSTC_SRST_Pos               (0UL)          /*!< SRST (Bit 0)                                          */
#define R_CANFD_CFDGRSTC_SRST_Msk               (0x1UL)        /*!< SRST (Bitfield-Mask: 0x01)                            */
#define R_CANFD_CFDGRSTC_KEY_Pos                (8UL)          /*!< KEY (Bit 8)                                           */
#define R_CANFD_CFDGRSTC_KEY_Msk                (0xff00UL)     /*!< KEY (Bitfield-Mask: 0xff)                             */
/* =======================================================  CFDGFCMC  ======================================================= */
#define R_CANFD_CFDGFCMC_FLXC0_Pos              (0UL)          /*!< FLXC0 (Bit 0)                                         */
#define R_CANFD_CFDGFCMC_FLXC0_Msk              (0x1UL)        /*!< FLXC0 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGFCMC_FLXC1_Pos              (1UL)          /*!< FLXC1 (Bit 1)                                         */
#define R_CANFD_CFDGFCMC_FLXC1_Msk              (0x2UL)        /*!< FLXC1 (Bitfield-Mask: 0x01)                           */
#define R_CANFD_CFDGFCMC_FLXC3_Pos              (2UL)          /*!< FLXC3 (Bit 2)                                         */
#define R_CANFD_CFDGFCMC_FLXC3_Msk              (0x4UL)        /*!< FLXC3 (Bitfield-Mask: 0x01)                           */
/* =======================================================  CFDGFTBAC  ======================================================= */
#define R_CANFD_CFDGFTBAC_FLXMB0_Pos            (0UL)          /*!< FLXMB0 (Bit 0)                                        */
#define R_CANFD_CFDGFTBAC_FLXMB0_Msk            (0xfUL)        /*!< FLXMB0 (Bitfield-Mask: 0x0f)                          */
#define R_CANFD_CFDGFTBAC_FLXMB1_Pos            (8UL)          /*!< FLXMB1 (Bit 8)                                        */
#define R_CANFD_CFDGFTBAC_FLXMB1_Msk            (0xf00UL)      /*!< FLXMB1 (Bitfield-Mask: 0x0f)                          */
#define R_CANFD_CFDGFTBAC_FLXMB3_Pos            (16UL)         /*!< FLXMB3 (Bit 16)                                       */
#define R_CANFD_CFDGFTBAC_FLXMB3_Msk            (0xf0000UL)    /*!< FLXMB3 (Bitfield-Mask: 0x0f)                          */
/* =======================================================  CFDRPGACC  ======================================================= */
#define R_CANFD_CFDRPGACC_RDTA_Pos              (0UL)          /*!< RDTA (Bit 0)                                          */
#define R_CANFD_CFDRPGACC_RDTA_Msk              (0xffffffffUL) /*!< RDTA (Bitfield-Mask: 0xffffffff)                      */

#endif
