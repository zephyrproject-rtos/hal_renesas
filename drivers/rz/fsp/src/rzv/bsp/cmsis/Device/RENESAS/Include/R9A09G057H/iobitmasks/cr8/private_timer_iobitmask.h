/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : private_timer_iobitmask.h
 * Version      : 1.00
 * Description  : IO bit mask file for private_timer.
 *********************************************************************************************************************/

#ifndef PRIVATE_TIMER_IOBITMASK_H
#define PRIVATE_TIMER_IOBITMASK_H

#define R_PRIVATE_TIMER_PTLR_Msk                (0xFFFFFFFFUL)
#define R_PRIVATE_TIMER_PTLR_Pos                (0UL)
#define R_PRIVATE_TIMER_PTCR_Msk                (0xFFFFFFFFUL)
#define R_PRIVATE_TIMER_PTCR_Pos                (0UL)
#define R_PRIVATE_TIMER_PTCTLR_TE_Msk           (0x00000001UL)
#define R_PRIVATE_TIMER_PTCTLR_TE_Pos           (0UL)
#define R_PRIVATE_TIMER_PTCTLR_AR_Msk           (0x00000002UL)
#define R_PRIVATE_TIMER_PTCTLR_AR_Pos           (1UL)
#define R_PRIVATE_TIMER_PTCTLR_IRQE_Msk         (0x00000004UL)
#define R_PRIVATE_TIMER_PTCTLR_IRQE_Pos         (2UL)
#define R_PRIVATE_TIMER_PTCTLR_Prescaler_Msk    (0x0000FF00UL)
#define R_PRIVATE_TIMER_PTCTLR_Prescaler_Pos    (8UL)
#define R_PRIVATE_TIMER_PTISR_FLAG_Msk          (0x00000001UL)
#define R_PRIVATE_TIMER_PTISR_FLAG_Pos          (0UL)
#define R_PRIVATE_TIMER_PTISR_CLR_Msk           (0x00000001UL)
#define R_PRIVATE_TIMER_PTISR_CLR_Pos           (0UL)
#define R_PRIVATE_TIMER_WDWLR_Msk               (0xFFFFFFFFUL)
#define R_PRIVATE_TIMER_WDWLR_Pos               (0UL)
#define R_PRIVATE_TIMER_WDWCR_Msk               (0xFFFFFFFFUL)
#define R_PRIVATE_TIMER_WDWCR_Pos               (0UL)
#define R_PRIVATE_TIMER_WDCTLR_WE_Msk           (0x00000001UL)
#define R_PRIVATE_TIMER_WDCTLR_WE_Pos           (0UL)
#define R_PRIVATE_TIMER_WDCTLR_AR_Msk           (0x00000002UL)
#define R_PRIVATE_TIMER_WDCTLR_AR_Pos           (1UL)
#define R_PRIVATE_TIMER_WDCTLR_ITE_Msk          (0x00000004UL)
#define R_PRIVATE_TIMER_WDCTLR_ITE_Pos          (2UL)
#define R_PRIVATE_TIMER_WDCTLR_WM_Msk           (0x00000008UL)
#define R_PRIVATE_TIMER_WDCTLR_WM_Pos           (3UL)
#define R_PRIVATE_TIMER_WDCTLR_Prescaler_Msk    (0x0000FF00UL)
#define R_PRIVATE_TIMER_WDCTLR_Prescaler_Pos    (8UL)
#define R_PRIVATE_TIMER_WDISR_FLAG_Msk          (0x00000001UL)
#define R_PRIVATE_TIMER_WDISR_FLAG_Pos          (0UL)
#define R_PRIVATE_TIMER_WDISR_CLR_Msk           (0x00000001UL)
#define R_PRIVATE_TIMER_WDISR_CLR_Pos           (0UL)
#define R_PRIVATE_TIMER_WDRSR_RESET_Msk         (0x00000001UL)
#define R_PRIVATE_TIMER_WDRSR_RESET_Pos         (0UL)
#define R_PRIVATE_TIMER_WDDR_Msk                (0xFFFFFFFFUL)
#define R_PRIVATE_TIMER_WDDR_Pos                (0UL)

#endif
