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

#define R_WDT0_WDTCNT_WDTEN_Msk      (0x00000001UL)
#define R_WDT0_WDTCNT_WDTEN_Pos      (0UL)
#define R_WDT0_WDTSET_WDTTIME_Msk    (0xFFF00000UL)
#define R_WDT0_WDTSET_WDTTIME_Pos    (20UL)
#define R_WDT0_WDTTIM_CRTTIME_Msk    (0xFFFFFFFFUL)
#define R_WDT0_WDTTIM_CRTTIME_Pos    (0UL)
#define R_WDT0_WDTINT_INTDISP_Msk    (0x00000001UL)
#define R_WDT0_WDTINT_INTDISP_Pos    (0UL)
#define R_WDT0_PECR_PECR_Msk         (0xFFFFFFFFUL)
#define R_WDT0_PECR_PECR_Pos         (0UL)
#define R_WDT0_PEEN_PEEN_Msk         (0x00000001UL)
#define R_WDT0_PEEN_PEEN_Pos         (0UL)
#define R_WDT0_PESR_PESR_Msk         (0xFFFFFFFFUL)
#define R_WDT0_PESR_PESR_Pos         (0UL)
#define R_WDT0_PEER_PEER_Msk         (0xFFFFFFFFUL)
#define R_WDT0_PEER_PEER_Pos         (0UL)
#define R_WDT0_PEPO_PEPO_Msk         (0xFFFFFFFFUL)
#define R_WDT0_PEPO_PEPO_Pos         (0UL)

#endif                                 /* WDT_IOBITMASK_H */
