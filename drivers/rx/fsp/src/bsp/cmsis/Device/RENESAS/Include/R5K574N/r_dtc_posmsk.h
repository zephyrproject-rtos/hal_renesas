/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DTC_POSMSK_H
#define R_DTC_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_DTC                                           ================ */
/* =========================================================================================================================== */

/* ========================================================  DTCCR_S  ======================================================== */
#define R_DTC_DTCCR_S_RRS_Pos            (4UL)          /*!< RRS (Bit 4)                                           */
#define R_DTC_DTCCR_S_RRS_Msk            (0x10UL)       /*!< RRS (Bitfield-Mask: 0x01)                             */
/* =======================================================  DTCVBR_S  ======================================================== */
#define R_DTC_DTCVBR_S_DTCVBR_S_Pos      (10UL)         /*!< DTCVBR_S (Bit 10)                                     */
#define R_DTC_DTCVBR_S_DTCVBR_S_Msk      (0xfffffc00UL) /*!< DTCVBR_S (Bitfield-Mask: 0x3fffff)                    */
/* =========================================================  DTCST  ========================================================= */
#define R_DTC_DTCST_DTCST_Pos            (0UL)          /*!< DTCST (Bit 0)                                         */
#define R_DTC_DTCST_DTCST_Msk            (0x1UL)        /*!< DTCST (Bitfield-Mask: 0x01)                           */
/* ========================================================  DTCSTS  ========================================================= */
#define R_DTC_DTCSTS_ACT_Pos             (15UL)         /*!< ACT (Bit 15)                                          */
#define R_DTC_DTCSTS_ACT_Msk             (0x8000UL)     /*!< ACT (Bitfield-Mask: 0x01)                             */
#define R_DTC_DTCSTS_VECN_Pos            (0UL)          /*!< VECN (Bit 0)                                          */
#define R_DTC_DTCSTS_VECN_Msk            (0xffUL)       /*!< VECN (Bitfield-Mask: 0xff)                            */
/* ========================================================  DTCDISP  ======================================================== */
#define R_DTC_DTCDISP_DTCDISP_Pos        (0UL)          /*!< DTCDISP (Bit 0)                                       */
#define R_DTC_DTCDISP_DTCDISP_Msk        (0xffffffffUL) /*!< DTCDISP (Bitfield-Mask: 0xffffffff)                   */
/* ========================================================  DTCEVR  ========================================================= */
#define R_DTC_DTCEVR_ERRSTS_Pos          (16UL)         /*!< ERRSTS (Bit 16)                                       */
#define R_DTC_DTCEVR_ERRSTS_Msk          (0x10000UL)    /*!< ERRSTS (Bitfield-Mask: 0x01)                          */
#define R_DTC_DTCEVR_WBCF_Pos            (15UL)         /*!< WBCF (Bit 15)                                         */
#define R_DTC_DTCEVR_WBCF_Msk            (0x8000UL)     /*!< WBCF (Bitfield-Mask: 0x01)                            */
#define R_DTC_DTCEVR_ERRTI_Pos           (12UL)         /*!< ERRTI (Bit 12)                                        */
#define R_DTC_DTCEVR_ERRTI_Msk           (0x7000UL)     /*!< ERRTI (Bitfield-Mask: 0x07)                           */
#define R_DTC_DTCEVR_ERRSAF_Pos          (8UL)          /*!< ERRSAF (Bit 8)                                        */
#define R_DTC_DTCEVR_ERRSAF_Msk          (0x100UL)      /*!< ERRSAF (Bitfield-Mask: 0x01)                          */
#define R_DTC_DTCEVR_ERRVCT_Pos          (0UL)          /*!< ERRVCT (Bit 0)                                        */
#define R_DTC_DTCEVR_ERRVCT_Msk          (0xffUL)       /*!< ERRVCT (Bitfield-Mask: 0xff)                          */
/* ========================================================  DTCIBR  ========================================================= */
#define R_DTC_DTCIBR_DTCIBR_Pos          (10UL)         /*!< DTCIBR (Bit 10)                                       */
#define R_DTC_DTCIBR_DTCIBR_Msk          (0xfffffc00UL) /*!< DTCIBR (Bitfield-Mask: 0x3fffff)                      */
/* =========================================================  DTCOR  ========================================================= */
#define R_DTC_DTCOR_SQTFRL_Pos           (0UL)          /*!< SQTFRL (Bit 0)                                        */
#define R_DTC_DTCOR_SQTFRL_Msk           (0x1UL)        /*!< SQTFRL (Bitfield-Mask: 0x01)                          */
/* ========================================================  DTCSQE  ========================================================= */
#define R_DTC_DTCSQE_ESPSEL_Pos          (15UL)         /*!< ESPSEL (Bit 15)                                       */
#define R_DTC_DTCSQE_ESPSEL_Msk          (0x8000UL)     /*!< ESPSEL (Bitfield-Mask: 0x01)                          */
#define R_DTC_DTCSQE_VECN_Pos            (0UL)          /*!< VECN (Bit 0)                                          */
#define R_DTC_DTCSQE_VECN_Msk            (0xffUL)       /*!< VECN (Bitfield-Mask: 0xff)                            */
/* =======================================================  DTCCR_NS  ======================================================== */
#define R_DTC_DTCCR_NS_RRS_Pos           (4UL)          /*!< RRS (Bit 4)                                           */
#define R_DTC_DTCCR_NS_RRS_Msk           (0x10UL)       /*!< RRS (Bitfield-Mask: 0x01)                             */
/* =======================================================  DTCVBR_NS  ======================================================= */
#define R_DTC_DTCVBR_NS_DTCVBR_NS_Pos    (10UL)         /*!< DTCVBR_NS (Bit 10)                                    */
#define R_DTC_DTCVBR_NS_DTCVBR_NS_Msk    (0xfffffc00UL) /*!< DTCVBR_NS (Bitfield-Mask: 0x3fffff)                   */

/** @} */ /* End of group PosMask_peripherals */

#endif /* R_DTC_POSMSK_H */
