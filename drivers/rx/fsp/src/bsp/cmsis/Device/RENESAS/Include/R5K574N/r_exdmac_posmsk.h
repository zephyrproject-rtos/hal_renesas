/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_EXDMAC_POSMSK_H
#define R_EXDMAC_POSMSK_H

/* =========================================================================================================================== */
/* ================                                         R_EXDMAC0                                         ================ */
/* =========================================================================================================================== */

/* ========================================================  EDMSAR  ========================================================= */
/* ========================================================  EDMDAR  ========================================================= */
/* ========================================================  EDMCRA  ========================================================= */
#define R_EXDMAC0_EDMCRA_EDMCRAH_Pos    (16UL)         /*!< EDMCRAH (Bit 16)                                      */
#define R_EXDMAC0_EDMCRA_EDMCRAH_Msk    (0x3ff0000UL)  /*!< EDMCRAH (Bitfield-Mask: 0x3ff)                        */
#define R_EXDMAC0_EDMCRA_EDMCRAL_Pos    (0UL)          /*!< EDMCRAL (Bit 0)                                       */
#define R_EXDMAC0_EDMCRA_EDMCRAL_Msk    (0xffffUL)     /*!< EDMCRAL (Bitfield-Mask: 0xffff)                       */
/* ========================================================  EDMCRB  ========================================================= */
#define R_EXDMAC0_EDMCRB_EDMCRBH_Pos    (16UL)         /*!< EDMCRBH (Bit 16)                                      */
#define R_EXDMAC0_EDMCRB_EDMCRBH_Msk    (0xffff0000UL) /*!< EDMCRBH (Bitfield-Mask: 0xffff)                       */
#define R_EXDMAC0_EDMCRB_EDMCRBL_Pos    (0UL)          /*!< EDMCRBL (Bit 0)                                       */
#define R_EXDMAC0_EDMCRB_EDMCRBL_Msk    (0xffffUL)     /*!< EDMCRBL (Bitfield-Mask: 0xffff)                       */
/* ========================================================  EDMTMD  ========================================================= */
#define R_EXDMAC0_EDMTMD_MD_Pos         (14UL)         /*!< MD (Bit 14)                                           */
#define R_EXDMAC0_EDMTMD_MD_Msk         (0xc000UL)     /*!< MD (Bitfield-Mask: 0x03)                              */
#define R_EXDMAC0_EDMTMD_DTS_Pos        (12UL)         /*!< DTS (Bit 12)                                          */
#define R_EXDMAC0_EDMTMD_DTS_Msk        (0x3000UL)     /*!< DTS (Bitfield-Mask: 0x03)                             */
#define R_EXDMAC0_EDMTMD_TKP_Pos        (10UL)         /*!< TKP (Bit 10)                                          */
#define R_EXDMAC0_EDMTMD_TKP_Msk        (0x400UL)      /*!< TKP (Bitfield-Mask: 0x01)                             */
#define R_EXDMAC0_EDMTMD_SZ_Pos         (8UL)          /*!< SZ (Bit 8)                                            */
#define R_EXDMAC0_EDMTMD_SZ_Msk         (0x300UL)      /*!< SZ (Bitfield-Mask: 0x03)                              */
#define R_EXDMAC0_EDMTMD_DCTG_Pos       (0UL)          /*!< DCTG (Bit 0)                                          */
#define R_EXDMAC0_EDMTMD_DCTG_Msk       (0x3UL)        /*!< DCTG (Bitfield-Mask: 0x03)                            */
/* ========================================================  EDMINT  ========================================================= */
#define R_EXDMAC0_EDMINT_DTIE_Pos       (4UL)          /*!< DTIE (Bit 4)                                          */
#define R_EXDMAC0_EDMINT_DTIE_Msk       (0x10UL)       /*!< DTIE (Bitfield-Mask: 0x01)                            */
#define R_EXDMAC0_EDMINT_ESIE_Pos       (3UL)          /*!< ESIE (Bit 3)                                          */
#define R_EXDMAC0_EDMINT_ESIE_Msk       (0x8UL)        /*!< ESIE (Bitfield-Mask: 0x01)                            */
#define R_EXDMAC0_EDMINT_RPTIE_Pos      (2UL)          /*!< RPTIE (Bit 2)                                         */
#define R_EXDMAC0_EDMINT_RPTIE_Msk      (0x4UL)        /*!< RPTIE (Bitfield-Mask: 0x01)                           */
#define R_EXDMAC0_EDMINT_SARIE_Pos      (1UL)          /*!< SARIE (Bit 1)                                         */
#define R_EXDMAC0_EDMINT_SARIE_Msk      (0x2UL)        /*!< SARIE (Bitfield-Mask: 0x01)                           */
#define R_EXDMAC0_EDMINT_DARIE_Pos      (0UL)          /*!< DARIE (Bit 0)                                         */
#define R_EXDMAC0_EDMINT_DARIE_Msk      (0x1UL)        /*!< DARIE (Bitfield-Mask: 0x01)                           */
/* ========================================================  EDMAMD  ========================================================= */
#define R_EXDMAC0_EDMAMD_SM_Pos         (14UL)         /*!< SM (Bit 14)                                           */
#define R_EXDMAC0_EDMAMD_SM_Msk         (0xc000UL)     /*!< SM (Bitfield-Mask: 0x03)                              */
#define R_EXDMAC0_EDMAMD_SADR_Pos       (13UL)         /*!< SADR (Bit 13)                                         */
#define R_EXDMAC0_EDMAMD_SADR_Msk       (0x2000UL)     /*!< SADR (Bitfield-Mask: 0x01)                            */
#define R_EXDMAC0_EDMAMD_SARA_Pos       (8UL)          /*!< SARA (Bit 8)                                          */
#define R_EXDMAC0_EDMAMD_SARA_Msk       (0x1f00UL)     /*!< SARA (Bitfield-Mask: 0x1f)                            */
#define R_EXDMAC0_EDMAMD_DM_Pos         (6UL)          /*!< DM (Bit 6)                                            */
#define R_EXDMAC0_EDMAMD_DM_Msk         (0xc0UL)       /*!< DM (Bitfield-Mask: 0x03)                              */
#define R_EXDMAC0_EDMAMD_DADR_Pos       (5UL)          /*!< DADR (Bit 5)                                          */
#define R_EXDMAC0_EDMAMD_DADR_Msk       (0x20UL)       /*!< DADR (Bitfield-Mask: 0x01)                            */
#define R_EXDMAC0_EDMAMD_DARA_Pos       (0UL)          /*!< DARA (Bit 0)                                          */
#define R_EXDMAC0_EDMAMD_DARA_Msk       (0x1fUL)       /*!< DARA (Bitfield-Mask: 0x1f)                            */
/* ========================================================  EDMOFR  ========================================================= */
/* ========================================================  EDMCNT  ========================================================= */
#define R_EXDMAC0_EDMCNT_DTE_Pos        (0UL)          /*!< DTE (Bit 0)                                           */
#define R_EXDMAC0_EDMCNT_DTE_Msk        (0x1UL)        /*!< DTE (Bitfield-Mask: 0x01)                             */
/* ========================================================  EDMREQ  ========================================================= */
#define R_EXDMAC0_EDMREQ_CLRS_Pos       (4UL)          /*!< CLRS (Bit 4)                                          */
#define R_EXDMAC0_EDMREQ_CLRS_Msk       (0x10UL)       /*!< CLRS (Bitfield-Mask: 0x01)                            */
#define R_EXDMAC0_EDMREQ_SWREQ_Pos      (0UL)          /*!< SWREQ (Bit 0)                                         */
#define R_EXDMAC0_EDMREQ_SWREQ_Msk      (0x1UL)        /*!< SWREQ (Bitfield-Mask: 0x01)                           */
/* ========================================================  EDMSTS  ========================================================= */
#define R_EXDMAC0_EDMSTS_ACT_Pos        (7UL)          /*!< ACT (Bit 7)                                           */
#define R_EXDMAC0_EDMSTS_ACT_Msk        (0x80UL)       /*!< ACT (Bitfield-Mask: 0x01)                             */
#define R_EXDMAC0_EDMSTS_DTIF_Pos       (4UL)          /*!< DTIF (Bit 4)                                          */
#define R_EXDMAC0_EDMSTS_DTIF_Msk       (0x10UL)       /*!< DTIF (Bitfield-Mask: 0x01)                            */
#define R_EXDMAC0_EDMSTS_ESIF_Pos       (0UL)          /*!< ESIF (Bit 0)                                          */
#define R_EXDMAC0_EDMSTS_ESIF_Msk       (0x1UL)        /*!< ESIF (Bitfield-Mask: 0x01)                            */
/* ========================================================  EDMSRR  ========================================================= */
/* ========================================================  EDMDRR  ========================================================= */
/* ========================================================  EDMSBS  ========================================================= */
#define R_EXDMAC0_EDMSBS_EDMSBSH_Pos    (16UL)         /*!< EDMSBSH (Bit 16)                                      */
#define R_EXDMAC0_EDMSBS_EDMSBSH_Msk    (0xffff0000UL) /*!< EDMSBSH (Bitfield-Mask: 0xffff)                       */
#define R_EXDMAC0_EDMSBS_EDMSBSL_Pos    (0UL)          /*!< EDMSBSL (Bit 0)                                       */
#define R_EXDMAC0_EDMSBS_EDMSBSL_Msk    (0xffffUL)     /*!< EDMSBSL (Bitfield-Mask: 0xffff)                       */
/* ========================================================  EDMDBS  ========================================================= */
#define R_EXDMAC0_EDMDBS_EDMDBSH_Pos    (16UL)         /*!< EDMDBSH (Bit 16)                                      */
#define R_EXDMAC0_EDMDBS_EDMDBSH_Msk    (0xffff0000UL) /*!< EDMDBSH (Bitfield-Mask: 0xffff)                       */
#define R_EXDMAC0_EDMDBS_EDMDBSL_Pos    (0UL)          /*!< EDMDBSL (Bit 0)                                       */
#define R_EXDMAC0_EDMDBS_EDMDBSL_Msk    (0xffffUL)     /*!< EDMDBSL (Bitfield-Mask: 0xffff)                       */
/* ========================================================  EDMBWR  ========================================================= */
#define R_EXDMAC0_EDMBWR_BWE_Pos        (0UL)          /*!< BWE (Bit 0)                                           */
#define R_EXDMAC0_EDMBWR_BWE_Msk        (0x1UL)        /*!< BWE (Bitfield-Mask: 0x01)                             */
/* ========================================================  EDMPRF  ========================================================= */
#define R_EXDMAC0_EDMPRF_PREQ_Pos       (0UL)          /*!< PREQ (Bit 0)                                          */
#define R_EXDMAC0_EDMPRF_PREQ_Msk       (0x1UL)        /*!< PREQ (Bitfield-Mask: 0x01)                            */

#endif /* R_EXDMAC_POSMSK_H */
