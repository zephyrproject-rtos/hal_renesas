/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : wdt_iobitmask.h
 * Version      : 1.00
 * Description  : IO bit mask file for wdt.
 *********************************************************************************************************************/

#ifndef WDT_IOBITMASK_H
#define WDT_IOBITMASK_H

#define R_WDT_WDT0_WDTRR_REFRESH_Msk      (0xFFUL)
#define R_WDT_WDT0_WDTRR_REFRESH_Pos      (0UL)
#define R_WDT_WDT0_WDTCR_TOPS_Msk         (0x0003UL)
#define R_WDT_WDT0_WDTCR_TOPS_Pos         (0UL)
#define R_WDT_WDT0_WDTCR_CKS_Msk          (0x00F0UL)
#define R_WDT_WDT0_WDTCR_CKS_Pos          (4UL)
#define R_WDT_WDT0_WDTCR_RPES_Msk         (0x0300UL)
#define R_WDT_WDT0_WDTCR_RPES_Pos         (8UL)
#define R_WDT_WDT0_WDTCR_RPSS_Msk         (0x3000UL)
#define R_WDT_WDT0_WDTCR_RPSS_Pos         (12UL)
#define R_WDT_WDT0_WDTSR_CNTVAL_Msk       (0x3FFFUL)
#define R_WDT_WDT0_WDTSR_CNTVAL_Pos       (0UL)
#define R_WDT_WDT0_WDTSR_UNDFF_Msk        (0x4000UL)
#define R_WDT_WDT0_WDTSR_UNDFF_Pos        (14UL)
#define R_WDT_WDT0_WDTSR_REFEF_Msk        (0x8000UL)
#define R_WDT_WDT0_WDTSR_REFEF_Pos        (15UL)
#define R_WDT_WDT0_WDTRCR_RSTIRQS_Msk     (0x80UL)
#define R_WDT_WDT0_WDTRCR_RSTIRQS_Pos     (7UL)
#define R_WDT_WDT0_WDTCSTPR_SLCSTP_Msk    (0x80UL)
#define R_WDT_WDT0_WDTCSTPR_SLCSTP_Pos    (7UL)

#endif
