/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RTC_POSMSK_H
#define R_RTC_POSMSK_H

/* =========================================================================================================================== */
/* ================                                 Pos/Mask Cluster Section                                  ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                           RTCCR                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  RTCCR  ========================================================= */
#define R_RTC_RTCCR_RTCCR_TCCT_Pos    (0UL)    /*!< TCCT (Bit 0)                                          */
#define R_RTC_RTCCR_RTCCR_TCCT_Msk    (0x3UL)  /*!< TCCT (Bitfield-Mask: 0x03)                            */
#define R_RTC_RTCCR_RTCCR_TCST_Pos    (2UL)    /*!< TCST (Bit 2)                                          */
#define R_RTC_RTCCR_RTCCR_TCST_Msk    (0x4UL)  /*!< TCST (Bitfield-Mask: 0x01)                            */
#define R_RTC_RTCCR_RTCCR_TCNF_Pos    (4UL)    /*!< TCNF (Bit 4)                                          */
#define R_RTC_RTCCR_RTCCR_TCNF_Msk    (0x30UL) /*!< TCNF (Bitfield-Mask: 0x03)                            */
#define R_RTC_RTCCR_RTCCR_TCEN_Pos    (7UL)    /*!< TCEN (Bit 7)                                          */
#define R_RTC_RTCCR_RTCCR_TCEN_Msk    (0x80UL) /*!< TCEN (Bitfield-Mask: 0x01)                            */

/* =========================================================================================================================== */
/* ================                                            CP                                             ================ */
/* =========================================================================================================================== */

/* =========================================================  BCNT0  ========================================================= */
#define R_RTC_CP_BCNT0_BCNTCP_Pos    (0UL)    /*!< BCNTCP (Bit 0)                                        */
#define R_RTC_CP_BCNT0_BCNTCP_Msk    (0xffUL) /*!< BCNTCP (Bitfield-Mask: 0xff)                          */
/* =========================================================  RSEC  ========================================================== */
#define R_RTC_CP_RSEC_SEC1_Pos       (0UL)    /*!< SEC1 (Bit 0)                                          */
#define R_RTC_CP_RSEC_SEC1_Msk       (0xfUL)  /*!< SEC1 (Bitfield-Mask: 0x0f)                            */
#define R_RTC_CP_RSEC_SEC10_Pos      (4UL)    /*!< SEC10 (Bit 4)                                         */
#define R_RTC_CP_RSEC_SEC10_Msk      (0x70UL) /*!< SEC10 (Bitfield-Mask: 0x07)                           */
/* =========================================================  BCNT1  ========================================================= */
#define R_RTC_CP_BCNT1_BCNTCP_Pos    (0UL)    /*!< BCNTCP (Bit 0)                                        */
#define R_RTC_CP_BCNT1_BCNTCP_Msk    (0xffUL) /*!< BCNTCP (Bitfield-Mask: 0xff)                          */
/* =========================================================  RMIN  ========================================================== */
#define R_RTC_CP_RMIN_MIN1_Pos       (0UL)    /*!< MIN1 (Bit 0)                                          */
#define R_RTC_CP_RMIN_MIN1_Msk       (0xfUL)  /*!< MIN1 (Bitfield-Mask: 0x0f)                            */
#define R_RTC_CP_RMIN_MIN10_Pos      (4UL)    /*!< MIN10 (Bit 4)                                         */
#define R_RTC_CP_RMIN_MIN10_Msk      (0x70UL) /*!< MIN10 (Bitfield-Mask: 0x07)                           */
/* =========================================================  BCNT2  ========================================================= */
#define R_RTC_CP_BCNT2_BCNTCP_Pos    (0UL)    /*!< BCNTCP (Bit 0)                                        */
#define R_RTC_CP_BCNT2_BCNTCP_Msk    (0xffUL) /*!< BCNTCP (Bitfield-Mask: 0xff)                          */
/* ==========================================================  RHR  ========================================================== */
#define R_RTC_CP_RHR_HR1_Pos         (0UL)    /*!< HR1 (Bit 0)                                           */
#define R_RTC_CP_RHR_HR1_Msk         (0xfUL)  /*!< HR1 (Bitfield-Mask: 0x0f)                             */
#define R_RTC_CP_RHR_HR10_Pos        (4UL)    /*!< HR10 (Bit 4)                                          */
#define R_RTC_CP_RHR_HR10_Msk        (0x30UL) /*!< HR10 (Bitfield-Mask: 0x03)                            */
#define R_RTC_CP_RHR_PM_Pos          (6UL)    /*!< PM (Bit 6)                                            */
#define R_RTC_CP_RHR_PM_Msk          (0x40UL) /*!< PM (Bitfield-Mask: 0x01)                              */
/* =========================================================  BCNT3  ========================================================= */
#define R_RTC_CP_BCNT3_BCNTCP_Pos    (0UL)    /*!< BCNTCP (Bit 0)                                        */
#define R_RTC_CP_BCNT3_BCNTCP_Msk    (0xffUL) /*!< BCNTCP (Bitfield-Mask: 0xff)                          */
/* =========================================================  RDAY  ========================================================== */
#define R_RTC_CP_RDAY_DATE1_Pos      (0UL)    /*!< DATE1 (Bit 0)                                         */
#define R_RTC_CP_RDAY_DATE1_Msk      (0xfUL)  /*!< DATE1 (Bitfield-Mask: 0x0f)                           */
#define R_RTC_CP_RDAY_DATE10_Pos     (4UL)    /*!< DATE10 (Bit 4)                                        */
#define R_RTC_CP_RDAY_DATE10_Msk     (0x30UL) /*!< DATE10 (Bitfield-Mask: 0x03)                          */
/* =========================================================  RMON  ========================================================== */
#define R_RTC_CP_RMON_MON1_Pos       (0UL)    /*!< MON1 (Bit 0)                                          */
#define R_RTC_CP_RMON_MON1_Msk       (0xfUL)  /*!< MON1 (Bitfield-Mask: 0x0f)                            */
#define R_RTC_CP_RMON_MON10_Pos      (4UL)    /*!< MON10 (Bit 4)                                         */
#define R_RTC_CP_RMON_MON10_Msk      (0x10UL) /*!< MON10 (Bitfield-Mask: 0x01)                           */

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                           R_RTC                                           ================ */
/* =========================================================================================================================== */

/* ========================================================  R64CNT  ========================================================= */
#define R_RTC_R64CNT_F1HZ_Pos       (6UL)      /*!< F1HZ (Bit 6)                                          */
#define R_RTC_R64CNT_F1HZ_Msk       (0x40UL)   /*!< F1HZ (Bitfield-Mask: 0x01)                            */
#define R_RTC_R64CNT_F2HZ_Pos       (5UL)      /*!< F2HZ (Bit 5)                                          */
#define R_RTC_R64CNT_F2HZ_Msk       (0x20UL)   /*!< F2HZ (Bitfield-Mask: 0x01)                            */
#define R_RTC_R64CNT_F4HZ_Pos       (4UL)      /*!< F4HZ (Bit 4)                                          */
#define R_RTC_R64CNT_F4HZ_Msk       (0x10UL)   /*!< F4HZ (Bitfield-Mask: 0x01)                            */
#define R_RTC_R64CNT_F8HZ_Pos       (3UL)      /*!< F8HZ (Bit 3)                                          */
#define R_RTC_R64CNT_F8HZ_Msk       (0x8UL)    /*!< F8HZ (Bitfield-Mask: 0x01)                            */
#define R_RTC_R64CNT_F16HZ_Pos      (2UL)      /*!< F16HZ (Bit 2)                                         */
#define R_RTC_R64CNT_F16HZ_Msk      (0x4UL)    /*!< F16HZ (Bitfield-Mask: 0x01)                           */
#define R_RTC_R64CNT_F32HZ_Pos      (1UL)      /*!< F32HZ (Bit 1)                                         */
#define R_RTC_R64CNT_F32HZ_Msk      (0x2UL)    /*!< F32HZ (Bitfield-Mask: 0x01)                           */
#define R_RTC_R64CNT_F64HZ_Pos      (0UL)      /*!< F64HZ (Bit 0)                                         */
#define R_RTC_R64CNT_F64HZ_Msk      (0x1UL)    /*!< F64HZ (Bitfield-Mask: 0x01)                           */
/* ========================================================  RSECCNT  ======================================================== */
#define R_RTC_RSECCNT_SEC10_Pos     (4UL)      /*!< SEC10 (Bit 4)                                         */
#define R_RTC_RSECCNT_SEC10_Msk     (0x70UL)   /*!< SEC10 (Bitfield-Mask: 0x07)                           */
#define R_RTC_RSECCNT_SEC1_Pos      (0UL)      /*!< SEC1 (Bit 0)                                          */
#define R_RTC_RSECCNT_SEC1_Msk      (0xfUL)    /*!< SEC1 (Bitfield-Mask: 0x0f)                            */
/* =========================================================  BCNT0  ========================================================= */
#define R_RTC_BCNT0_BCNT_Pos        (0UL)      /*!< BCNT (Bit 0)                                          */
#define R_RTC_BCNT0_BCNT_Msk        (0xffUL)   /*!< BCNT (Bitfield-Mask: 0xff)                            */
/* ========================================================  RMINCNT  ======================================================== */
#define R_RTC_RMINCNT_MIN10_Pos     (4UL)      /*!< MIN10 (Bit 4)                                         */
#define R_RTC_RMINCNT_MIN10_Msk     (0x70UL)   /*!< MIN10 (Bitfield-Mask: 0x07)                           */
#define R_RTC_RMINCNT_MIN1_Pos      (0UL)      /*!< MIN1 (Bit 0)                                          */
#define R_RTC_RMINCNT_MIN1_Msk      (0xfUL)    /*!< MIN1 (Bitfield-Mask: 0x0f)                            */
/* =========================================================  BCNT1  ========================================================= */
#define R_RTC_BCNT1_BCNT_Pos        (0UL)      /*!< BCNT (Bit 0)                                          */
#define R_RTC_BCNT1_BCNT_Msk        (0xffUL)   /*!< BCNT (Bitfield-Mask: 0xff)                            */
/* ========================================================  RHRCNT  ========================================================= */
#define R_RTC_RHRCNT_PM_Pos         (6UL)      /*!< PM (Bit 6)                                            */
#define R_RTC_RHRCNT_PM_Msk         (0x40UL)   /*!< PM (Bitfield-Mask: 0x01)                              */
#define R_RTC_RHRCNT_HR10_Pos       (4UL)      /*!< HR10 (Bit 4)                                          */
#define R_RTC_RHRCNT_HR10_Msk       (0x30UL)   /*!< HR10 (Bitfield-Mask: 0x03)                            */
#define R_RTC_RHRCNT_HR1_Pos        (0UL)      /*!< HR1 (Bit 0)                                           */
#define R_RTC_RHRCNT_HR1_Msk        (0xfUL)    /*!< HR1 (Bitfield-Mask: 0x0f)                             */
/* =========================================================  BCNT2  ========================================================= */
#define R_RTC_BCNT2_BCNT_Pos        (0UL)      /*!< BCNT (Bit 0)                                          */
#define R_RTC_BCNT2_BCNT_Msk        (0xffUL)   /*!< BCNT (Bitfield-Mask: 0xff)                            */
/* ========================================================  RWKCNT  ========================================================= */
#define R_RTC_RWKCNT_DAYW_Pos       (0UL)      /*!< DAYW (Bit 0)                                          */
#define R_RTC_RWKCNT_DAYW_Msk       (0x7UL)    /*!< DAYW (Bitfield-Mask: 0x07)                            */
/* =========================================================  BCNT3  ========================================================= */
#define R_RTC_BCNT3_BCNT_Pos        (0UL)      /*!< BCNT (Bit 0)                                          */
#define R_RTC_BCNT3_BCNT_Msk        (0xffUL)   /*!< BCNT (Bitfield-Mask: 0xff)                            */
/* ========================================================  RDAYCNT  ======================================================== */
#define R_RTC_RDAYCNT_DATE10_Pos    (4UL)      /*!< DATE10 (Bit 4)                                        */
#define R_RTC_RDAYCNT_DATE10_Msk    (0x30UL)   /*!< DATE10 (Bitfield-Mask: 0x03)                          */
#define R_RTC_RDAYCNT_DATE1_Pos     (0UL)      /*!< DATE1 (Bit 0)                                         */
#define R_RTC_RDAYCNT_DATE1_Msk     (0xfUL)    /*!< DATE1 (Bitfield-Mask: 0x0f)                           */
/* ========================================================  RMONCNT  ======================================================== */
#define R_RTC_RMONCNT_MON10_Pos     (4UL)      /*!< MON10 (Bit 4)                                         */
#define R_RTC_RMONCNT_MON10_Msk     (0x10UL)   /*!< MON10 (Bitfield-Mask: 0x01)                           */
#define R_RTC_RMONCNT_MON1_Pos      (0UL)      /*!< MON1 (Bit 0)                                          */
#define R_RTC_RMONCNT_MON1_Msk      (0xfUL)    /*!< MON1 (Bitfield-Mask: 0x0f)                            */
/* ========================================================  RYRCNT  ========================================================= */
#define R_RTC_RYRCNT_YR10_Pos       (4UL)      /*!< YR10 (Bit 4)                                          */
#define R_RTC_RYRCNT_YR10_Msk       (0xf0UL)   /*!< YR10 (Bitfield-Mask: 0x0f)                            */
#define R_RTC_RYRCNT_YR1_Pos        (0UL)      /*!< YR1 (Bit 0)                                           */
#define R_RTC_RYRCNT_YR1_Msk        (0xfUL)    /*!< YR1 (Bitfield-Mask: 0x0f)                             */
/* ========================================================  RSECAR  ========================================================= */
#define R_RTC_RSECAR_ENB_Pos        (7UL)      /*!< ENB (Bit 7)                                           */
#define R_RTC_RSECAR_ENB_Msk        (0x80UL)   /*!< ENB (Bitfield-Mask: 0x01)                             */
#define R_RTC_RSECAR_SEC10_Pos      (4UL)      /*!< SEC10 (Bit 4)                                         */
#define R_RTC_RSECAR_SEC10_Msk      (0x70UL)   /*!< SEC10 (Bitfield-Mask: 0x07)                           */
#define R_RTC_RSECAR_SEC1_Pos       (0UL)      /*!< SEC1 (Bit 0)                                          */
#define R_RTC_RSECAR_SEC1_Msk       (0xfUL)    /*!< SEC1 (Bitfield-Mask: 0x0f)                            */
/* ========================================================  BCNT0AR  ======================================================== */
#define R_RTC_BCNT0AR_BCNTAR_Pos    (0UL)      /*!< BCNTAR (Bit 0)                                        */
#define R_RTC_BCNT0AR_BCNTAR_Msk    (0xffUL)   /*!< BCNTAR (Bitfield-Mask: 0xff)                          */
/* ========================================================  RMINAR  ========================================================= */
#define R_RTC_RMINAR_ENB_Pos        (7UL)      /*!< ENB (Bit 7)                                           */
#define R_RTC_RMINAR_ENB_Msk        (0x80UL)   /*!< ENB (Bitfield-Mask: 0x01)                             */
#define R_RTC_RMINAR_MIN10_Pos      (4UL)      /*!< MIN10 (Bit 4)                                         */
#define R_RTC_RMINAR_MIN10_Msk      (0x70UL)   /*!< MIN10 (Bitfield-Mask: 0x07)                           */
#define R_RTC_RMINAR_MIN1_Pos       (0UL)      /*!< MIN1 (Bit 0)                                          */
#define R_RTC_RMINAR_MIN1_Msk       (0xfUL)    /*!< MIN1 (Bitfield-Mask: 0x0f)                            */
/* ========================================================  BCNT1AR  ======================================================== */
#define R_RTC_BCNT1AR_BCNTAR_Pos    (0UL)      /*!< BCNTAR (Bit 0)                                        */
#define R_RTC_BCNT1AR_BCNTAR_Msk    (0xffUL)   /*!< BCNTAR (Bitfield-Mask: 0xff)                          */
/* =========================================================  RHRAR  ========================================================= */
#define R_RTC_RHRAR_ENB_Pos         (7UL)      /*!< ENB (Bit 7)                                           */
#define R_RTC_RHRAR_ENB_Msk         (0x80UL)   /*!< ENB (Bitfield-Mask: 0x01)                             */
#define R_RTC_RHRAR_PM_Pos          (6UL)      /*!< PM (Bit 6)                                            */
#define R_RTC_RHRAR_PM_Msk          (0x40UL)   /*!< PM (Bitfield-Mask: 0x01)                              */
#define R_RTC_RHRAR_HR10_Pos        (4UL)      /*!< HR10 (Bit 4)                                          */
#define R_RTC_RHRAR_HR10_Msk        (0x30UL)   /*!< HR10 (Bitfield-Mask: 0x03)                            */
#define R_RTC_RHRAR_HR1_Pos         (0UL)      /*!< HR1 (Bit 0)                                           */
#define R_RTC_RHRAR_HR1_Msk         (0xfUL)    /*!< HR1 (Bitfield-Mask: 0x0f)                             */
/* ========================================================  BCNT2AR  ======================================================== */
#define R_RTC_BCNT2AR_BCNTAR_Pos    (0UL)      /*!< BCNTAR (Bit 0)                                        */
#define R_RTC_BCNT2AR_BCNTAR_Msk    (0xffUL)   /*!< BCNTAR (Bitfield-Mask: 0xff)                          */
/* =========================================================  RWKAR  ========================================================= */
#define R_RTC_RWKAR_ENB_Pos         (7UL)      /*!< ENB (Bit 7)                                           */
#define R_RTC_RWKAR_ENB_Msk         (0x80UL)   /*!< ENB (Bitfield-Mask: 0x01)                             */
#define R_RTC_RWKAR_DAYW_Pos        (0UL)      /*!< DAYW (Bit 0)                                          */
#define R_RTC_RWKAR_DAYW_Msk        (0x7UL)    /*!< DAYW (Bitfield-Mask: 0x07)                            */
/* ========================================================  BCNT3AR  ======================================================== */
#define R_RTC_BCNT3AR_BCNTAR_Pos    (0UL)      /*!< BCNTAR (Bit 0)                                        */
#define R_RTC_BCNT3AR_BCNTAR_Msk    (0xffUL)   /*!< BCNTAR (Bitfield-Mask: 0xff)                          */
/* ========================================================  RDAYAR  ========================================================= */
#define R_RTC_RDAYAR_ENB_Pos        (7UL)      /*!< ENB (Bit 7)                                           */
#define R_RTC_RDAYAR_ENB_Msk        (0x80UL)   /*!< ENB (Bitfield-Mask: 0x01)                             */
#define R_RTC_RDAYAR_DATE10_Pos     (4UL)      /*!< DATE10 (Bit 4)                                        */
#define R_RTC_RDAYAR_DATE10_Msk     (0x30UL)   /*!< DATE10 (Bitfield-Mask: 0x03)                          */
#define R_RTC_RDAYAR_DATE1_Pos      (0UL)      /*!< DATE1 (Bit 0)                                         */
#define R_RTC_RDAYAR_DATE1_Msk      (0xfUL)    /*!< DATE1 (Bitfield-Mask: 0x0f)                           */
/* =======================================================  BCNT0AER  ======================================================== */
#define R_RTC_BCNT0AER_ENB_Pos      (0UL)      /*!< ENB (Bit 0)                                           */
#define R_RTC_BCNT0AER_ENB_Msk      (0xffUL)   /*!< ENB (Bitfield-Mask: 0xff)                             */
/* ========================================================  RMONAR  ========================================================= */
#define R_RTC_RMONAR_ENB_Pos        (7UL)      /*!< ENB (Bit 7)                                           */
#define R_RTC_RMONAR_ENB_Msk        (0x80UL)   /*!< ENB (Bitfield-Mask: 0x01)                             */
#define R_RTC_RMONAR_MON10_Pos      (4UL)      /*!< MON10 (Bit 4)                                         */
#define R_RTC_RMONAR_MON10_Msk      (0x10UL)   /*!< MON10 (Bitfield-Mask: 0x01)                           */
#define R_RTC_RMONAR_MON1_Pos       (0UL)      /*!< MON1 (Bit 0)                                          */
#define R_RTC_RMONAR_MON1_Msk       (0xfUL)    /*!< MON1 (Bitfield-Mask: 0x0f)                            */
/* =======================================================  BCNT1AER  ======================================================== */
#define R_RTC_BCNT1AER_ENB_Pos      (0UL)      /*!< ENB (Bit 0)                                           */
#define R_RTC_BCNT1AER_ENB_Msk      (0xffUL)   /*!< ENB (Bitfield-Mask: 0xff)                             */
/* =========================================================  RYRAR  ========================================================= */
#define R_RTC_RYRAR_YR10_Pos        (4UL)      /*!< YR10 (Bit 4)                                          */
#define R_RTC_RYRAR_YR10_Msk        (0xf0UL)   /*!< YR10 (Bitfield-Mask: 0x0f)                            */
#define R_RTC_RYRAR_YR1_Pos         (0UL)      /*!< YR1 (Bit 0)                                           */
#define R_RTC_RYRAR_YR1_Msk         (0xfUL)    /*!< YR1 (Bitfield-Mask: 0x0f)                             */
/* =======================================================  BCNT2AER  ======================================================== */
#define R_RTC_BCNT2AER_ENB_Pos      (0UL)      /*!< ENB (Bit 0)                                           */
#define R_RTC_BCNT2AER_ENB_Msk      (0xffUL)   /*!< ENB (Bitfield-Mask: 0xff)                             */
/* ========================================================  RYRAREN  ======================================================== */
#define R_RTC_RYRAREN_ENB_Pos       (7UL)      /*!< ENB (Bit 7)                                           */
#define R_RTC_RYRAREN_ENB_Msk       (0x80UL)   /*!< ENB (Bitfield-Mask: 0x01)                             */
/* =======================================================  BCNT3AER  ======================================================== */
#define R_RTC_BCNT3AER_ENB_Pos      (0UL)      /*!< ENB (Bit 0)                                           */
#define R_RTC_BCNT3AER_ENB_Msk      (0xffUL)   /*!< ENB (Bitfield-Mask: 0xff)                             */
/* =========================================================  RCR1  ========================================================== */
#define R_RTC_RCR1_PES_Pos          (4UL)      /*!< PES (Bit 4)                                           */
#define R_RTC_RCR1_PES_Msk          (0xf0UL)   /*!< PES (Bitfield-Mask: 0x0f)                             */
#define R_RTC_RCR1_RTCOS_Pos        (3UL)      /*!< RTCOS (Bit 3)                                         */
#define R_RTC_RCR1_RTCOS_Msk        (0x8UL)    /*!< RTCOS (Bitfield-Mask: 0x01)                           */
#define R_RTC_RCR1_PIE_Pos          (2UL)      /*!< PIE (Bit 2)                                           */
#define R_RTC_RCR1_PIE_Msk          (0x4UL)    /*!< PIE (Bitfield-Mask: 0x01)                             */
#define R_RTC_RCR1_CIE_Pos          (1UL)      /*!< CIE (Bit 1)                                           */
#define R_RTC_RCR1_CIE_Msk          (0x2UL)    /*!< CIE (Bitfield-Mask: 0x01)                             */
#define R_RTC_RCR1_AIE_Pos          (0UL)      /*!< AIE (Bit 0)                                           */
#define R_RTC_RCR1_AIE_Msk          (0x1UL)    /*!< AIE (Bitfield-Mask: 0x01)                             */
/* =========================================================  RCR2  ========================================================== */
#define R_RTC_RCR2_CNTMD_Pos        (7UL)      /*!< CNTMD (Bit 7)                                         */
#define R_RTC_RCR2_CNTMD_Msk        (0x80UL)   /*!< CNTMD (Bitfield-Mask: 0x01)                           */
#define R_RTC_RCR2_HR24_Pos         (6UL)      /*!< HR24 (Bit 6)                                          */
#define R_RTC_RCR2_HR24_Msk         (0x40UL)   /*!< HR24 (Bitfield-Mask: 0x01)                            */
#define R_RTC_RCR2_AADJP_Pos        (5UL)      /*!< AADJP (Bit 5)                                         */
#define R_RTC_RCR2_AADJP_Msk        (0x20UL)   /*!< AADJP (Bitfield-Mask: 0x01)                           */
#define R_RTC_RCR2_AADJE_Pos        (4UL)      /*!< AADJE (Bit 4)                                         */
#define R_RTC_RCR2_AADJE_Msk        (0x10UL)   /*!< AADJE (Bitfield-Mask: 0x01)                           */
#define R_RTC_RCR2_RTCOE_Pos        (3UL)      /*!< RTCOE (Bit 3)                                         */
#define R_RTC_RCR2_RTCOE_Msk        (0x8UL)    /*!< RTCOE (Bitfield-Mask: 0x01)                           */
#define R_RTC_RCR2_ADJ30_Pos        (2UL)      /*!< ADJ30 (Bit 2)                                         */
#define R_RTC_RCR2_ADJ30_Msk        (0x4UL)    /*!< ADJ30 (Bitfield-Mask: 0x01)                           */
#define R_RTC_RCR2_RESET_Pos        (1UL)      /*!< RESET (Bit 1)                                         */
#define R_RTC_RCR2_RESET_Msk        (0x2UL)    /*!< RESET (Bitfield-Mask: 0x01)                           */
#define R_RTC_RCR2_START_Pos        (0UL)      /*!< START (Bit 0)                                         */
#define R_RTC_RCR2_START_Msk        (0x1UL)    /*!< START (Bitfield-Mask: 0x01)                           */
/* =========================================================  RCR4  ========================================================== */
#define R_RTC_RCR4_RCKSEL_Pos       (0UL)      /*!< RCKSEL (Bit 0)                                        */
#define R_RTC_RCR4_RCKSEL_Msk       (0x1UL)    /*!< RCKSEL (Bitfield-Mask: 0x01)                          */
/* =========================================================  RFRH  ========================================================== */
#define R_RTC_RFRH_RFC_Pos          (0UL)      /*!< RFC (Bit 0)                                           */
#define R_RTC_RFRH_RFC_Msk          (0x1UL)    /*!< RFC (Bitfield-Mask: 0x01)                             */
/* =========================================================  RFRL  ========================================================== */
#define R_RTC_RFRL_RFC_Pos          (0UL)      /*!< RFC (Bit 0)                                           */
#define R_RTC_RFRL_RFC_Msk          (0xffffUL) /*!< RFC (Bitfield-Mask: 0xffff)                           */
/* =========================================================  RADJ  ========================================================== */
#define R_RTC_RADJ_PMADJ_Pos        (6UL)      /*!< PMADJ (Bit 6)                                         */
#define R_RTC_RADJ_PMADJ_Msk        (0xc0UL)   /*!< PMADJ (Bitfield-Mask: 0x03)                           */
#define R_RTC_RADJ_ADJ_Pos          (0UL)      /*!< ADJ (Bit 0)                                           */
#define R_RTC_RADJ_ADJ_Msk          (0x3fUL)   /*!< ADJ (Bitfield-Mask: 0x3f)                             */

#endif /* R_RTC_POSMSK_H */
