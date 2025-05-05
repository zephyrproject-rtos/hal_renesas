/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : global_timer_iobitmask.h
 * Version      : 1.00
 * Description  : IO bit mask file for global_timer.
 *********************************************************************************************************************/

#ifndef GLOBAL_TIMER_IOBITMASK_H
#define GLOBAL_TIMER_IOBITMASK_H

#define R_GLOBAL_TIMER_GTCR_L_Msk              (0xFFFFFFFFUL)
#define R_GLOBAL_TIMER_GTCR_L_Pos              (0UL)
#define R_GLOBAL_TIMER_GTCR_H_Msk              (0xFFFFFFFFUL)
#define R_GLOBAL_TIMER_GTCR_H_Pos              (0UL)
#define R_GLOBAL_TIMER_GTCTLR_TE_Msk           (0x00000001UL)
#define R_GLOBAL_TIMER_GTCTLR_TE_Pos           (0UL)
#define R_GLOBAL_TIMER_GTCTLR_CE_Msk           (0x00000002UL)
#define R_GLOBAL_TIMER_GTCTLR_CE_Pos           (1UL)
#define R_GLOBAL_TIMER_GTCTLR_IRQE_Msk         (0x00000004UL)
#define R_GLOBAL_TIMER_GTCTLR_IRQE_Pos         (2UL)
#define R_GLOBAL_TIMER_GTCTLR_AI_Msk           (0x00000008UL)
#define R_GLOBAL_TIMER_GTCTLR_AI_Pos           (3UL)
#define R_GLOBAL_TIMER_GTCTLR_Prescaler_Msk    (0x0000FF00UL)
#define R_GLOBAL_TIMER_GTCTLR_Prescaler_Pos    (8UL)
#define R_GLOBAL_TIMER_GTISR_EF_Msk            (0x00000001UL)
#define R_GLOBAL_TIMER_GTISR_EF_Pos            (0UL)
#define R_GLOBAL_TIMER_CVR_L_Msk               (0xFFFFFFFFUL)
#define R_GLOBAL_TIMER_CVR_L_Pos               (0UL)
#define R_GLOBAL_TIMER_CVR_H_Msk               (0xFFFFFFFFUL)
#define R_GLOBAL_TIMER_CVR_H_Pos               (0UL)
#define R_GLOBAL_TIMER_AUTO_INCR_Msk           (0xFFFFFFFFUL)
#define R_GLOBAL_TIMER_AUTO_INCR_Pos           (0UL)

#endif
