/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_GPTP_POSMSK_H
#define R_GPTP_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_GPTP                                           ================ */
/* =========================================================================================================================== */

/* ========================================================  PTPIPV  ========================================================= */
#define R_GPTP_PTPIPV_IPV_Pos           (0UL)          /*!< IPV (Bit 0)                                           */
#define R_GPTP_PTPIPV_IPV_Msk           (0xffffffffUL) /*!< IPV (Bitfield-Mask: 0xffffffff)                       */
/* ========================================================  PTPTMEC  ======================================================== */
#define R_GPTP_PTPTMEC_TE0_Pos          (0UL)          /*!< TE0 (Bit 0)                                           */
#define R_GPTP_PTPTMEC_TE0_Msk          (0x1UL)        /*!< TE0 (Bitfield-Mask: 0x01)                             */
#define R_GPTP_PTPTMEC_TE1_Pos          (1UL)          /*!< TE1 (Bit 1)                                           */
#define R_GPTP_PTPTMEC_TE1_Msk          (0x2UL)        /*!< TE1 (Bitfield-Mask: 0x01)                             */
/* ========================================================  PTPTMDC  ======================================================== */
#define R_GPTP_PTPTMDC_TD0_Pos          (0UL)          /*!< TD0 (Bit 0)                                           */
#define R_GPTP_PTPTMDC_TD0_Msk          (0x1UL)        /*!< TD0 (Bitfield-Mask: 0x01)                             */
#define R_GPTP_PTPTMDC_TD1_Pos          (1UL)          /*!< TD1 (Bit 1)                                           */
#define R_GPTP_PTPTMDC_TD1_Msk          (0x2UL)        /*!< TD1 (Bitfield-Mask: 0x01)                             */
/* =======================================================  PTPTIVC0  ======================================================== */
#define R_GPTP_PTPTIVC0_TIV_Pos         (0UL)          /*!< TIV (Bit 0)                                           */
#define R_GPTP_PTPTIVC0_TIV_Msk         (0xffffffffUL) /*!< TIV (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PTPTOVC0L  ======================================================= */
#define R_GPTP_PTPTOVC0L_TOVPL_Pos      (0UL)          /*!< TOVPL (Bit 0)                                         */
#define R_GPTP_PTPTOVC0L_TOVPL_Msk      (0x3fffffffUL) /*!< TOVPL (Bitfield-Mask: 0x3fffffff)                     */
/* =======================================================  PTPTOVC0M  ======================================================= */
#define R_GPTP_PTPTOVC0M_TOVPM_Pos      (0UL)          /*!< TOVPM (Bit 0)                                         */
#define R_GPTP_PTPTOVC0M_TOVPM_Msk      (0xffffffffUL) /*!< TOVPM (Bitfield-Mask: 0xffffffff)                     */
/* =======================================================  PTPTOVC0U  ======================================================= */
#define R_GPTP_PTPTOVC0U_TOVPU_Pos      (0UL)          /*!< TOVPU (Bit 0)                                         */
#define R_GPTP_PTPTOVC0U_TOVPU_Msk      (0xffffUL)     /*!< TOVPU (Bitfield-Mask: 0xffff)                         */
/* ======================================================  PTPAVTPTM0L  ====================================================== */
#define R_GPTP_PTPAVTPTM0L_AVTPL_Pos    (0UL)          /*!< AVTPL (Bit 0)                                         */
#define R_GPTP_PTPAVTPTM0L_AVTPL_Msk    (0xffffffffUL) /*!< AVTPL (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPAVTPTM0U  ====================================================== */
#define R_GPTP_PTPAVTPTM0U_AVTPU_Pos    (0UL)          /*!< AVTPU (Bit 0)                                         */
#define R_GPTP_PTPAVTPTM0U_AVTPU_Msk    (0xffffffffUL) /*!< AVTPU (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPGPTPTM0L  ====================================================== */
#define R_GPTP_PTPGPTPTM0L_GPTPL_Pos    (0UL)          /*!< GPTPL (Bit 0)                                         */
#define R_GPTP_PTPGPTPTM0L_GPTPL_Msk    (0x3fffffffUL) /*!< GPTPL (Bitfield-Mask: 0x3fffffff)                     */
/* ======================================================  PTPGPTPTM0M  ====================================================== */
#define R_GPTP_PTPGPTPTM0M_GPTPM_Pos    (0UL)          /*!< GPTPM (Bit 0)                                         */
#define R_GPTP_PTPGPTPTM0M_GPTPM_Msk    (0xffffffffUL) /*!< GPTPM (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPGPTPTM0U  ====================================================== */
#define R_GPTP_PTPGPTPTM0U_GPTPU_Pos    (0UL)          /*!< GPTPU (Bit 0)                                         */
#define R_GPTP_PTPGPTPTM0U_GPTPU_Msk    (0xffffUL)     /*!< GPTPU (Bitfield-Mask: 0xffff)                         */
/* =======================================================  PTPTIVC1  ======================================================== */
#define R_GPTP_PTPTIVC1_TIV_Pos         (0UL)          /*!< TIV (Bit 0)                                           */
#define R_GPTP_PTPTIVC1_TIV_Msk         (0xffffffffUL) /*!< TIV (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PTPTOVC1L  ======================================================= */
#define R_GPTP_PTPTOVC1L_TOVPL_Pos      (0UL)          /*!< TOVPL (Bit 0)                                         */
#define R_GPTP_PTPTOVC1L_TOVPL_Msk      (0x3fffffffUL) /*!< TOVPL (Bitfield-Mask: 0x3fffffff)                     */
/* =======================================================  PTPTOVC1M  ======================================================= */
#define R_GPTP_PTPTOVC1M_TOVPM_Pos      (0UL)          /*!< TOVPM (Bit 0)                                         */
#define R_GPTP_PTPTOVC1M_TOVPM_Msk      (0xffffffffUL) /*!< TOVPM (Bitfield-Mask: 0xffffffff)                     */
/* =======================================================  PTPTOVC1U  ======================================================= */
#define R_GPTP_PTPTOVC1U_TOVPU_Pos      (0UL)          /*!< TOVPU (Bit 0)                                         */
#define R_GPTP_PTPTOVC1U_TOVPU_Msk      (0xffffUL)     /*!< TOVPU (Bitfield-Mask: 0xffff)                         */
/* ======================================================  PTPAVTPTM1L  ====================================================== */
#define R_GPTP_PTPAVTPTM1L_AVTPL_Pos    (0UL)          /*!< AVTPL (Bit 0)                                         */
#define R_GPTP_PTPAVTPTM1L_AVTPL_Msk    (0xffffffffUL) /*!< AVTPL (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPAVTPTM1U  ====================================================== */
#define R_GPTP_PTPAVTPTM1U_AVTPU_Pos    (0UL)          /*!< AVTPU (Bit 0)                                         */
#define R_GPTP_PTPAVTPTM1U_AVTPU_Msk    (0xffffffffUL) /*!< AVTPU (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPGPTPTM1L  ====================================================== */
#define R_GPTP_PTPGPTPTM1L_GPTPL_Pos    (0UL)          /*!< GPTPL (Bit 0)                                         */
#define R_GPTP_PTPGPTPTM1L_GPTPL_Msk    (0x3fffffffUL) /*!< GPTPL (Bitfield-Mask: 0x3fffffff)                     */
/* ======================================================  PTPGPTPTM1M  ====================================================== */
#define R_GPTP_PTPGPTPTM1M_GPTPM_Pos    (0UL)          /*!< GPTPM (Bit 0)                                         */
#define R_GPTP_PTPGPTPTM1M_GPTPM_Msk    (0xffffffffUL) /*!< GPTPM (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPGPTPTM1U  ====================================================== */
#define R_GPTP_PTPGPTPTM1U_GPTPU_Pos    (0UL)          /*!< GPTPU (Bit 0)                                         */
#define R_GPTP_PTPGPTPTM1U_GPTPU_Msk    (0xffffUL)     /*!< GPTPU (Bitfield-Mask: 0xffff)                         */
/* =======================================================  PTPMCCC0  ======================================================== */
#define R_GPTP_PTPMCCC0_MCPEE_Pos       (0UL)          /*!< MCPEE (Bit 0)                                         */
#define R_GPTP_PTPMCCC0_MCPEE_Msk       (0x1UL)        /*!< MCPEE (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCC0_MCNEE_Pos       (1UL)          /*!< MCNEE (Bit 1)                                         */
#define R_GPTP_PTPMCCC0_MCNEE_Msk       (0x2UL)        /*!< MCNEE (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCC0_MCTTS_Pos       (2UL)          /*!< MCTTS (Bit 2)                                         */
#define R_GPTP_PTPMCCC0_MCTTS_Msk       (0x4UL)        /*!< MCTTS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCC0_MCTNS_Pos       (3UL)          /*!< MCTNS (Bit 3)                                         */
#define R_GPTP_PTPMCCC0_MCTNS_Msk       (0x8UL)        /*!< MCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCC0_MCCR_Pos        (16UL)         /*!< MCCR (Bit 16)                                         */
#define R_GPTP_PTPMCCC0_MCCR_Msk        (0x10000UL)    /*!< MCCR (Bitfield-Mask: 0x01)                            */
/* =======================================================  PTPMCCM0L  ======================================================= */
#define R_GPTP_PTPMCCM0L_MCCTVP0_Pos    (0UL)          /*!< MCCTVP0 (Bit 0)                                       */
#define R_GPTP_PTPMCCM0L_MCCTVP0_Msk    (0xffffffffUL) /*!< MCCTVP0 (Bitfield-Mask: 0xffffffff)                   */
/* =======================================================  PTPMCCM0M  ======================================================= */
#define R_GPTP_PTPMCCM0M_MCCTVM_Pos     (0UL)          /*!< MCCTVM (Bit 0)                                        */
#define R_GPTP_PTPMCCM0M_MCCTVM_Msk     (0xffffffffUL) /*!< MCCTVM (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  PTPMCCM0U  ======================================================= */
#define R_GPTP_PTPMCCM0U_MCCTVU_Pos     (0UL)          /*!< MCCTVU (Bit 0)                                        */
#define R_GPTP_PTPMCCM0U_MCCTVU_Msk     (0xffffUL)     /*!< MCCTVU (Bitfield-Mask: 0xffff)                        */
#define R_GPTP_PTPMCCM0U_MCPEC_Pos      (16UL)         /*!< MCPEC (Bit 16)                                        */
#define R_GPTP_PTPMCCM0U_MCPEC_Msk      (0x10000UL)    /*!< MCPEC (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCM0U_MCNEC_Pos      (17UL)         /*!< MCNEC (Bit 17)                                        */
#define R_GPTP_PTPMCCM0U_MCNEC_Msk      (0x20000UL)    /*!< MCNEC (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCM0U_MCSWC_Pos      (18UL)         /*!< MCSWC (Bit 18)                                        */
#define R_GPTP_PTPMCCM0U_MCSWC_Msk      (0x40000UL)    /*!< MCSWC (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCM0U_MCCN_Pos       (24UL)         /*!< MCCN (Bit 24)                                         */
#define R_GPTP_PTPMCCM0U_MCCN_Msk       (0x3000000UL)  /*!< MCCN (Bitfield-Mask: 0x03)                            */
/* =======================================================  PTPMCCC1  ======================================================== */
#define R_GPTP_PTPMCCC1_MCPEE_Pos       (0UL)          /*!< MCPEE (Bit 0)                                         */
#define R_GPTP_PTPMCCC1_MCPEE_Msk       (0x1UL)        /*!< MCPEE (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCC1_MCNEE_Pos       (1UL)          /*!< MCNEE (Bit 1)                                         */
#define R_GPTP_PTPMCCC1_MCNEE_Msk       (0x2UL)        /*!< MCNEE (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCC1_MCTTS_Pos       (2UL)          /*!< MCTTS (Bit 2)                                         */
#define R_GPTP_PTPMCCC1_MCTTS_Msk       (0x4UL)        /*!< MCTTS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCC1_MCTNS_Pos       (3UL)          /*!< MCTNS (Bit 3)                                         */
#define R_GPTP_PTPMCCC1_MCTNS_Msk       (0x8UL)        /*!< MCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCC1_MCCR_Pos        (16UL)         /*!< MCCR (Bit 16)                                         */
#define R_GPTP_PTPMCCC1_MCCR_Msk        (0x10000UL)    /*!< MCCR (Bitfield-Mask: 0x01)                            */
/* =======================================================  PTPMCCM1L  ======================================================= */
#define R_GPTP_PTPMCCM1L_MCCTVL_Pos     (0UL)          /*!< MCCTVL (Bit 0)                                        */
#define R_GPTP_PTPMCCM1L_MCCTVL_Msk     (0xffffffffUL) /*!< MCCTVL (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  PTPMCCM1M  ======================================================= */
#define R_GPTP_PTPMCCM1M_MCCTVM_Pos     (0UL)          /*!< MCCTVM (Bit 0)                                        */
#define R_GPTP_PTPMCCM1M_MCCTVM_Msk     (0xffffffffUL) /*!< MCCTVM (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  PTPMCCM1U  ======================================================= */
#define R_GPTP_PTPMCCM1U_MCCTVU_Pos     (0UL)          /*!< MCCTVU (Bit 0)                                        */
#define R_GPTP_PTPMCCM1U_MCCTVU_Msk     (0xffffUL)     /*!< MCCTVU (Bitfield-Mask: 0xffff)                        */
#define R_GPTP_PTPMCCM1U_MCPEC_Pos      (16UL)         /*!< MCPEC (Bit 16)                                        */
#define R_GPTP_PTPMCCM1U_MCPEC_Msk      (0x10000UL)    /*!< MCPEC (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCM1U_MCNEC_Pos      (17UL)         /*!< MCNEC (Bit 17)                                        */
#define R_GPTP_PTPMCCM1U_MCNEC_Msk      (0x20000UL)    /*!< MCNEC (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCM1U_MCSWC_Pos      (18UL)         /*!< MCSWC (Bit 18)                                        */
#define R_GPTP_PTPMCCM1U_MCSWC_Msk      (0x40000UL)    /*!< MCSWC (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCCM1U_MCCN_Pos       (24UL)         /*!< MCCN (Bit 24)                                         */
#define R_GPTP_PTPMCCM1U_MCCN_Msk       (0x3000000UL)  /*!< MCCN (Bitfield-Mask: 0x03)                            */
/* =======================================================  PTPMCRC0  ======================================================== */
#define R_GPTP_PTPMCRC0_MRTTS_Pos       (0UL)          /*!< MRTTS (Bit 0)                                         */
#define R_GPTP_PTPMCRC0_MRTTS_Msk       (0x1UL)        /*!< MRTTS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCRC0_MRAMS_Pos       (1UL)          /*!< MRAMS (Bit 1)                                         */
#define R_GPTP_PTPMCRC0_MRAMS_Msk       (0x2UL)        /*!< MRAMS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCRC0_MRTNS_Pos       (2UL)          /*!< MRTNS (Bit 2)                                         */
#define R_GPTP_PTPMCRC0_MRTNS_Msk       (0x4UL)        /*!< MRTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCRC0_MRPL_Pos        (16UL)         /*!< MRPL (Bit 16)                                         */
#define R_GPTP_PTPMCRC0_MRPL_Msk        (0xffff0000UL) /*!< MRPL (Bitfield-Mask: 0xffff)                          */
/* ======================================================  PTPMCRTC0L  ======================================================= */
#define R_GPTP_PTPMCRTC0L_MRTVL_Pos     (0UL)          /*!< MRTVL (Bit 0)                                         */
#define R_GPTP_PTPMCRTC0L_MRTVL_Msk     (0xffffffffUL) /*!< MRTVL (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPMCRTC0M  ======================================================= */
#define R_GPTP_PTPMCRTC0M_MRTVM_Pos     (0UL)          /*!< MRTVM (Bit 0)                                         */
#define R_GPTP_PTPMCRTC0M_MRTVM_Msk     (0xffffffffUL) /*!< MRTVM (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPMCRTC0U  ======================================================= */
#define R_GPTP_PTPMCRTC0U_MCCTVU_Pos    (0UL)          /*!< MCCTVU (Bit 0)                                        */
#define R_GPTP_PTPMCRTC0U_MCCTVU_Msk    (0xffffUL)     /*!< MCCTVU (Bitfield-Mask: 0xffff)                        */
#define R_GPTP_PTPMCRTC0U_MRTT_Pos      (16UL)         /*!< MRTT (Bit 16)                                         */
#define R_GPTP_PTPMCRTC0U_MRTT_Msk      (0x30000UL)    /*!< MRTT (Bitfield-Mask: 0x03)                            */
#define R_GPTP_PTPMCRTC0U_MCRN_Pos      (18UL)         /*!< MCRN (Bit 18)                                         */
#define R_GPTP_PTPMCRTC0U_MCRN_Msk      (0x1c0000UL)   /*!< MCRN (Bitfield-Mask: 0x07)                            */
#define R_GPTP_PTPMCRTC0U_MRBCR_Pos     (31UL)         /*!< MRBCR (Bit 31)                                        */
#define R_GPTP_PTPMCRTC0U_MRBCR_Msk     (0x80000000UL) /*!< MRBCR (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPMCRC1  ======================================================== */
#define R_GPTP_PTPMCRC1_MRTTS_Pos       (0UL)          /*!< MRTTS (Bit 0)                                         */
#define R_GPTP_PTPMCRC1_MRTTS_Msk       (0x1UL)        /*!< MRTTS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCRC1_MRAMS_Pos       (1UL)          /*!< MRAMS (Bit 1)                                         */
#define R_GPTP_PTPMCRC1_MRAMS_Msk       (0x2UL)        /*!< MRAMS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCRC1_MRTNS_Pos       (2UL)          /*!< MRTNS (Bit 2)                                         */
#define R_GPTP_PTPMCRC1_MRTNS_Msk       (0x4UL)        /*!< MRTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPMCRC1_MRPL_Pos        (16UL)         /*!< MRPL (Bit 16)                                         */
#define R_GPTP_PTPMCRC1_MRPL_Msk        (0xffff0000UL) /*!< MRPL (Bitfield-Mask: 0xffff)                          */
/* ======================================================  PTPMCRTC1L  ======================================================= */
#define R_GPTP_PTPMCRTC1L_MRTVL_Pos     (0UL)          /*!< MRTVL (Bit 0)                                         */
#define R_GPTP_PTPMCRTC1L_MRTVL_Msk     (0xffffffffUL) /*!< MRTVL (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPMCRTC1M  ======================================================= */
#define R_GPTP_PTPMCRTC1M_MRTVM_Pos     (0UL)          /*!< MRTVM (Bit 0)                                         */
#define R_GPTP_PTPMCRTC1M_MRTVM_Msk     (0xffffffffUL) /*!< MRTVM (Bitfield-Mask: 0xffffffff)                     */
/* ======================================================  PTPMCRTC1U  ======================================================= */
#define R_GPTP_PTPMCRTC1U_MCCTVU_Pos    (0UL)          /*!< MCCTVU (Bit 0)                                        */
#define R_GPTP_PTPMCRTC1U_MCCTVU_Msk    (0xffffUL)     /*!< MCCTVU (Bitfield-Mask: 0xffff)                        */
#define R_GPTP_PTPMCRTC1U_MRTT_Pos      (16UL)         /*!< MRTT (Bit 16)                                         */
#define R_GPTP_PTPMCRTC1U_MRTT_Msk      (0x30000UL)    /*!< MRTT (Bitfield-Mask: 0x03)                            */
#define R_GPTP_PTPMCRTC1U_MCRN_Pos      (18UL)         /*!< MCRN (Bit 18)                                         */
#define R_GPTP_PTPMCRTC1U_MCRN_Msk      (0x1c0000UL)   /*!< MCRN (Bitfield-Mask: 0x07)                            */
#define R_GPTP_PTPMCRTC1U_MRBCR_Pos     (31UL)         /*!< MRBCR (Bit 31)                                        */
#define R_GPTP_PTPMCRTC1U_MRBCR_Msk     (0x80000000UL) /*!< MRBCR (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPMCPC0  ======================================================== */
#define R_GPTP_PTPMCPC0_PE_Pos          (0UL)          /*!< PE (Bit 0)                                            */
#define R_GPTP_PTPMCPC0_PE_Msk          (0x1UL)        /*!< PE (Bitfield-Mask: 0x01)                              */
#define R_GPTP_PTPMCPC0_MRS_Pos         (1UL)          /*!< MRS (Bit 1)                                           */
#define R_GPTP_PTPMCPC0_MRS_Msk         (0x2UL)        /*!< MRS (Bitfield-Mask: 0x01)                             */
/* =======================================================  PTPMCPC1  ======================================================== */
#define R_GPTP_PTPMCPC1_PE_Pos          (0UL)          /*!< PE (Bit 0)                                            */
#define R_GPTP_PTPMCPC1_PE_Msk          (0x1UL)        /*!< PE (Bitfield-Mask: 0x01)                              */
#define R_GPTP_PTPMCPC1_MRS_Pos         (1UL)          /*!< MRS (Bit 1)                                           */
#define R_GPTP_PTPMCPC1_MRS_Msk         (0x2UL)        /*!< MRS (Bitfield-Mask: 0x01)                             */
/* =======================================================  PTPCCC00  ======================================================== */
#define R_GPTP_PTPCCC00_CCTNS_Pos       (0UL)          /*!< CCTNS (Bit 0)                                         */
#define R_GPTP_PTPCCC00_CCTNS_Msk       (0x1UL)        /*!< CCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPCCC00_CCOPS_Pos       (4UL)          /*!< CCOPS (Bit 4)                                         */
#define R_GPTP_PTPCCC00_CCOPS_Msk       (0x10UL)       /*!< CCOPS (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPCCC01  ======================================================== */
#define R_GPTP_PTPCCC01_CCV_Pos         (0UL)          /*!< CCV (Bit 0)                                           */
#define R_GPTP_PTPCCC01_CCV_Msk         (0xffffffffUL) /*!< CCV (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PTPCCC10  ======================================================== */
#define R_GPTP_PTPCCC10_CCTNS_Pos       (0UL)          /*!< CCTNS (Bit 0)                                         */
#define R_GPTP_PTPCCC10_CCTNS_Msk       (0x1UL)        /*!< CCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPCCC10_CCOPS_Pos       (4UL)          /*!< CCOPS (Bit 4)                                         */
#define R_GPTP_PTPCCC10_CCOPS_Msk       (0x10UL)       /*!< CCOPS (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPCCC11  ======================================================== */
#define R_GPTP_PTPCCC11_CCV_Pos         (0UL)          /*!< CCV (Bit 0)                                           */
#define R_GPTP_PTPCCC11_CCV_Msk         (0xffffffffUL) /*!< CCV (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PTPCCC20  ======================================================== */
#define R_GPTP_PTPCCC20_CCTNS_Pos       (0UL)          /*!< CCTNS (Bit 0)                                         */
#define R_GPTP_PTPCCC20_CCTNS_Msk       (0x1UL)        /*!< CCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPCCC20_CCOPS_Pos       (4UL)          /*!< CCOPS (Bit 4)                                         */
#define R_GPTP_PTPCCC20_CCOPS_Msk       (0x10UL)       /*!< CCOPS (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPCCC21  ======================================================== */
#define R_GPTP_PTPCCC21_CCV_Pos         (0UL)          /*!< CCV (Bit 0)                                           */
#define R_GPTP_PTPCCC21_CCV_Msk         (0xffffffffUL) /*!< CCV (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PTPCCC30  ======================================================== */
#define R_GPTP_PTPCCC30_CCTNS_Pos       (0UL)          /*!< CCTNS (Bit 0)                                         */
#define R_GPTP_PTPCCC30_CCTNS_Msk       (0x1UL)        /*!< CCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPCCC30_CCOPS_Pos       (4UL)          /*!< CCOPS (Bit 4)                                         */
#define R_GPTP_PTPCCC30_CCOPS_Msk       (0x10UL)       /*!< CCOPS (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPCCC31  ======================================================== */
#define R_GPTP_PTPCCC31_CCV_Pos         (0UL)          /*!< CCV (Bit 0)                                           */
#define R_GPTP_PTPCCC31_CCV_Msk         (0xffffffffUL) /*!< CCV (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PTPCCC40  ======================================================== */
#define R_GPTP_PTPCCC40_CCTNS_Pos       (0UL)          /*!< CCTNS (Bit 0)                                         */
#define R_GPTP_PTPCCC40_CCTNS_Msk       (0x1UL)        /*!< CCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPCCC40_CCOPS_Pos       (4UL)          /*!< CCOPS (Bit 4)                                         */
#define R_GPTP_PTPCCC40_CCOPS_Msk       (0x10UL)       /*!< CCOPS (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPCCC41  ======================================================== */
#define R_GPTP_PTPCCC41_CCV_Pos         (0UL)          /*!< CCV (Bit 0)                                           */
#define R_GPTP_PTPCCC41_CCV_Msk         (0xffffffffUL) /*!< CCV (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PTPCCC50  ======================================================== */
#define R_GPTP_PTPCCC50_CCTNS_Pos       (0UL)          /*!< CCTNS (Bit 0)                                         */
#define R_GPTP_PTPCCC50_CCTNS_Msk       (0x1UL)        /*!< CCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPCCC50_CCOPS_Pos       (4UL)          /*!< CCOPS (Bit 4)                                         */
#define R_GPTP_PTPCCC50_CCOPS_Msk       (0x10UL)       /*!< CCOPS (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPCCC51  ======================================================== */
#define R_GPTP_PTPCCC51_CCV_Pos         (0UL)          /*!< CCV (Bit 0)                                           */
#define R_GPTP_PTPCCC51_CCV_Msk         (0xffffffffUL) /*!< CCV (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PTPCCC60  ======================================================== */
#define R_GPTP_PTPCCC60_CCTNS_Pos       (0UL)          /*!< CCTNS (Bit 0)                                         */
#define R_GPTP_PTPCCC60_CCTNS_Msk       (0x1UL)        /*!< CCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPCCC60_CCOPS_Pos       (4UL)          /*!< CCOPS (Bit 4)                                         */
#define R_GPTP_PTPCCC60_CCOPS_Msk       (0x10UL)       /*!< CCOPS (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPCCC61  ======================================================== */
#define R_GPTP_PTPCCC61_CCV_Pos         (0UL)          /*!< CCV (Bit 0)                                           */
#define R_GPTP_PTPCCC61_CCV_Msk         (0xffffffffUL) /*!< CCV (Bitfield-Mask: 0xffffffff)                       */
/* =======================================================  PTPCCC70  ======================================================== */
#define R_GPTP_PTPCCC70_CCTNS_Pos       (0UL)          /*!< CCTNS (Bit 0)                                         */
#define R_GPTP_PTPCCC70_CCTNS_Msk       (0x1UL)        /*!< CCTNS (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPCCC70_CCOPS_Pos       (4UL)          /*!< CCOPS (Bit 4)                                         */
#define R_GPTP_PTPCCC70_CCOPS_Msk       (0x10UL)       /*!< CCOPS (Bitfield-Mask: 0x01)                           */
/* =======================================================  PTPCCC71  ======================================================== */
#define R_GPTP_PTPCCC71_CCV_Pos         (0UL)          /*!< CCV (Bit 0)                                           */
#define R_GPTP_PTPCCC71_CCV_Msk         (0xffffffffUL) /*!< CCV (Bitfield-Mask: 0xffffffff)                       */
/* ========================================================  PTPIS0  ========================================================= */
#define R_GPTP_PTPIS0_MCCS0_Pos         (0UL)          /*!< MCCS0 (Bit 0)                                         */
#define R_GPTP_PTPIS0_MCCS0_Msk         (0x1UL)        /*!< MCCS0 (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPIS0_MCCS1_Pos         (1UL)          /*!< MCCS1 (Bit 1)                                         */
#define R_GPTP_PTPIS0_MCCS1_Msk         (0x2UL)        /*!< MCCS1 (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPIS0_MCCOES0_Pos       (16UL)         /*!< MCCOES0 (Bit 16)                                      */
#define R_GPTP_PTPIS0_MCCOES0_Msk       (0x10000UL)    /*!< MCCOES0 (Bitfield-Mask: 0x01)                         */
/* ========================================================  PTPIE0  ========================================================= */
#define R_GPTP_PTPIE0_MCCE0_Pos         (0UL)          /*!< MCCE0 (Bit 0)                                         */
#define R_GPTP_PTPIE0_MCCE0_Msk         (0x1UL)        /*!< MCCE0 (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPIE0_MCCE1_Pos         (1UL)          /*!< MCCE1 (Bit 1)                                         */
#define R_GPTP_PTPIE0_MCCE1_Msk         (0x2UL)        /*!< MCCE1 (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPIE0_MCCOEE0_Pos       (16UL)         /*!< MCCOEE0 (Bit 16)                                      */
#define R_GPTP_PTPIE0_MCCOEE0_Msk       (0x10000UL)    /*!< MCCOEE0 (Bitfield-Mask: 0x01)                         */
/* ========================================================  PTPID0  ========================================================= */
#define R_GPTP_PTPID0_MCCD0_Pos         (0UL)          /*!< MCCD0 (Bit 0)                                         */
#define R_GPTP_PTPID0_MCCD0_Msk         (0x1UL)        /*!< MCCD0 (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPID0_MCCD1_Pos         (1UL)          /*!< MCCD1 (Bit 1)                                         */
#define R_GPTP_PTPID0_MCCD1_Msk         (0x2UL)        /*!< MCCD1 (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPID0_MCCOED0_Pos       (16UL)         /*!< MCCOED0 (Bit 16)                                      */
#define R_GPTP_PTPID0_MCCOED0_Msk       (0x10000UL)    /*!< MCCOED0 (Bitfield-Mask: 0x01)                         */
/* ========================================================  PTPIS1  ========================================================= */
#define R_GPTP_PTPIS1_MCRMS0_Pos        (0UL)          /*!< MCRMS0 (Bit 0)                                        */
#define R_GPTP_PTPIS1_MCRMS0_Msk        (0x1UL)        /*!< MCRMS0 (Bitfield-Mask: 0x01)                          */
#define R_GPTP_PTPIS1_MCRMS1_Pos        (1UL)          /*!< MCRMS1 (Bit 1)                                        */
#define R_GPTP_PTPIS1_MCRMS1_Msk        (0x2UL)        /*!< MCRMS1 (Bitfield-Mask: 0x01)                          */
/* ========================================================  PTPIE1  ========================================================= */
#define R_GPTP_PTPIE1_MCRME0_Pos        (0UL)          /*!< MCRME0 (Bit 0)                                        */
#define R_GPTP_PTPIE1_MCRME0_Msk        (0x1UL)        /*!< MCRME0 (Bitfield-Mask: 0x01)                          */
#define R_GPTP_PTPIE1_MCRME1_Pos        (1UL)          /*!< MCRME1 (Bit 1)                                        */
#define R_GPTP_PTPIE1_MCRME1_Msk        (0x2UL)        /*!< MCRME1 (Bitfield-Mask: 0x01)                          */
/* ========================================================  PTPID1  ========================================================= */
#define R_GPTP_PTPID1_MCRMD0_Pos        (0UL)          /*!< MCRMD0 (Bit 0)                                        */
#define R_GPTP_PTPID1_MCRMD0_Msk        (0x1UL)        /*!< MCRMD0 (Bitfield-Mask: 0x01)                          */
#define R_GPTP_PTPID1_MCRMD1_Pos        (1UL)          /*!< MCRMD1 (Bit 1)                                        */
#define R_GPTP_PTPID1_MCRMD1_Msk        (0x2UL)        /*!< MCRMD1 (Bitfield-Mask: 0x01)                          */
/* ========================================================  PTPSCR0  ======================================================== */
#define R_GPTP_PTPSCR0_TRSL0_Pos        (0UL)          /*!< TRSL0 (Bit 0)                                         */
#define R_GPTP_PTPSCR0_TRSL0_Msk        (0x1UL)        /*!< TRSL0 (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPSCR0_TRSL1_Pos        (1UL)          /*!< TRSL1 (Bit 1)                                         */
#define R_GPTP_PTPSCR0_TRSL1_Msk        (0x2UL)        /*!< TRSL1 (Bitfield-Mask: 0x01)                           */
#define R_GPTP_PTPSCR0_MCRSL0_Pos       (16UL)         /*!< MCRSL0 (Bit 16)                                       */
#define R_GPTP_PTPSCR0_MCRSL0_Msk       (0x10000UL)    /*!< MCRSL0 (Bitfield-Mask: 0x01)                          */
#define R_GPTP_PTPSCR0_MCRSL1_Pos       (17UL)         /*!< MCRSL1 (Bit 17)                                       */
#define R_GPTP_PTPSCR0_MCRSL1_Msk       (0x20000UL)    /*!< MCRSL1 (Bitfield-Mask: 0x01)                          */
/* ========================================================  PTPSCR1  ======================================================== */
#define R_GPTP_PTPSCR1_MRRSL0_Pos       (0UL)          /*!< MRRSL0 (Bit 0)                                        */
#define R_GPTP_PTPSCR1_MRRSL0_Msk       (0x1UL)        /*!< MRRSL0 (Bitfield-Mask: 0x01)                          */
#define R_GPTP_PTPSCR1_MRRSL1_Pos       (1UL)          /*!< MRRSL1 (Bit 1)                                        */
#define R_GPTP_PTPSCR1_MRRSL1_Msk       (0x2UL)        /*!< MRRSL1 (Bitfield-Mask: 0x01)                          */
#define R_GPTP_PTPSCR1_MRRRSL0_Pos      (16UL)         /*!< MRRRSL0 (Bit 16)                                      */
#define R_GPTP_PTPSCR1_MRRRSL0_Msk      (0x10000UL)    /*!< MRRRSL0 (Bitfield-Mask: 0x01)                         */
#define R_GPTP_PTPSCR1_MRRRSL1_Pos      (17UL)         /*!< MRRRSL1 (Bit 17)                                      */
#define R_GPTP_PTPSCR1_MRRRSL1_Msk      (0x20000UL)    /*!< MRRRSL1 (Bitfield-Mask: 0x01)                         */
/* ========================================================  PTPSCR2  ======================================================== */
#define R_GPTP_PTPSCR2_CCRSL0_Pos       (0UL)          /*!< CCRSL0 (Bit 0)                                        */
#define R_GPTP_PTPSCR2_CCRSL0_Msk       (0x1UL)        /*!< CCRSL0 (Bitfield-Mask: 0x01)                          */
#define R_GPTP_PTPSCR2_CCRSL1_Pos       (1UL)          /*!< CCRSL1 (Bit 1)                                        */
#define R_GPTP_PTPSCR2_CCRSL1_Msk       (0x2UL)        /*!< CCRSL1 (Bitfield-Mask: 0x01)                          */
#define R_GPTP_PTPSCR2_VRSL_Pos         (16UL)         /*!< VRSL (Bit 16)                                         */
#define R_GPTP_PTPSCR2_VRSL_Msk         (0x10000UL)    /*!< VRSL (Bitfield-Mask: 0x01)                            */
/* ========================================================  POTCFGR  ======================================================== */
#define R_GPTP_POTCFGR_REFSEL_Pos       (0UL)          /*!< REFSEL (Bit 0)                                        */
#define R_GPTP_POTCFGR_REFSEL_Msk       (0x1UL)        /*!< REFSEL (Bitfield-Mask: 0x01)                          */
/* ========================================================  POTCR0  ========================================================= */
#define R_GPTP_POTCR0_START_Pos         (0UL)          /*!< START (Bit 0)                                         */
#define R_GPTP_POTCR0_START_Msk         (0x1UL)        /*!< START (Bitfield-Mask: 0x01)                           */
/* =======================================================  POTSTR0U  ======================================================== */
/* =======================================================  POTSTR0M  ======================================================== */
/* =======================================================  POTSTR0L  ======================================================== */
/* =======================================================  POTPER0U  ======================================================== */
/* =======================================================  POTPER0M  ======================================================== */
/* =======================================================  POTPER0L  ======================================================== */
/* ========================================================  POTPWR0  ======================================================== */
/* =======================================================  POTCPR0U  ======================================================== */
/* =======================================================  POTCPR0M  ======================================================== */
/* =======================================================  POTCPR0L  ======================================================== */
/* ========================================================  POTCR1  ========================================================= */
#define R_GPTP_POTCR1_START_Pos    (0UL)   /*!< START (Bit 0)                                         */
#define R_GPTP_POTCR1_START_Msk    (0x1UL) /*!< START (Bitfield-Mask: 0x01)                           */
/* =======================================================  POTSTR1U  ======================================================== */
/* =======================================================  POTSTR1M  ======================================================== */
/* =======================================================  POTSTR1L  ======================================================== */
/* =======================================================  POTPER1U  ======================================================== */
/* =======================================================  POTPER1M  ======================================================== */
/* =======================================================  POTPER1L  ======================================================== */
/* ========================================================  POTPWR1  ======================================================== */
/* =======================================================  POTCPR1U  ======================================================== */
/* =======================================================  POTCPR1M  ======================================================== */
/* =======================================================  POTCPR1L  ======================================================== */
/* ========================================================  POTCR2  ========================================================= */
#define R_GPTP_POTCR2_START_Pos    (0UL)   /*!< START (Bit 0)                                         */
#define R_GPTP_POTCR2_START_Msk    (0x1UL) /*!< START (Bitfield-Mask: 0x01)                           */
/* =======================================================  POTSTR2U  ======================================================== */
/* =======================================================  POTSTR2M  ======================================================== */
/* =======================================================  POTSTR2L  ======================================================== */
/* =======================================================  POTPER2U  ======================================================== */
/* =======================================================  POTPER2M  ======================================================== */
/* =======================================================  POTPER2L  ======================================================== */
/* ========================================================  POTPWR2  ======================================================== */
/* =======================================================  POTCPR2U  ======================================================== */
/* =======================================================  POTCPR2M  ======================================================== */
/* =======================================================  POTCPR2L  ======================================================== */
/* ========================================================  POTCR3  ========================================================= */
#define R_GPTP_POTCR3_START_Pos    (0UL)   /*!< START (Bit 0)                                         */
#define R_GPTP_POTCR3_START_Msk    (0x1UL) /*!< START (Bitfield-Mask: 0x01)                           */
/* =======================================================  POTSTR3U  ======================================================== */
/* =======================================================  POTSTR3M  ======================================================== */
/* =======================================================  POTSTR3L  ======================================================== */
/* =======================================================  POTPER3U  ======================================================== */
/* =======================================================  POTPER3M  ======================================================== */
/* =======================================================  POTPER3L  ======================================================== */
/* ========================================================  POTPWR3  ======================================================== */
/* =======================================================  POTCPR3U  ======================================================== */
/* =======================================================  POTCPR3M  ======================================================== */
/* =======================================================  POTCPR3L  ======================================================== */

/** @} */ /* End of group PosMask_peripherals */

#endif                                 /* R_GPTP_POSMSK_H */
