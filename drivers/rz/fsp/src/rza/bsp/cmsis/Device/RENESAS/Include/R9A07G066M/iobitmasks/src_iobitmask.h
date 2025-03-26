/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : src_iobitmask.h
 * Version      : 1.00
 * Description  : IO bit mask file for src.
 *********************************************************************************************************************/

#ifndef SRC_IOBITMASK_H
#define SRC_IOBITMASK_H

#define R_SRC_SRCID_H_SRCID_Msk      (0xFFFFUL)
#define R_SRC_SRCID_H_SRCID_Pos      (0UL)
#define R_SRC_SRCID_L_SRCID_Msk      (0xFFFFUL)
#define R_SRC_SRCID_L_SRCID_Pos      (0UL)
#define R_SRC_SRCOD_H_SRCOD_Msk      (0xFFFFUL)
#define R_SRC_SRCOD_H_SRCOD_Pos      (0UL)
#define R_SRC_SRCOD_L_SRCOD_Msk      (0xFFFFUL)
#define R_SRC_SRCOD_L_SRCOD_Pos      (0UL)
#define R_SRC_SRCIDCTRL_IFTRG_Msk    (0x0003UL)
#define R_SRC_SRCIDCTRL_IFTRG_Pos    (0UL)
#define R_SRC_SRCIDCTRL_IEN_Msk      (0x0100UL)
#define R_SRC_SRCIDCTRL_IEN_Pos      (8UL)
#define R_SRC_SRCIDCTRL_IED_Msk      (0x0200UL)
#define R_SRC_SRCIDCTRL_IED_Pos      (9UL)
#define R_SRC_SRCODCTRL_OFTRG_Msk    (0x0003UL)
#define R_SRC_SRCODCTRL_OFTRG_Pos    (0UL)
#define R_SRC_SRCODCTRL_OEN_Msk      (0x0100UL)
#define R_SRC_SRCODCTRL_OEN_Pos      (8UL)
#define R_SRC_SRCODCTRL_OED_Msk      (0x0200UL)
#define R_SRC_SRCODCTRL_OED_Pos      (9UL)
#define R_SRC_SRCODCTRL_OCH_Msk      (0x0400UL)
#define R_SRC_SRCODCTRL_OCH_Pos      (10UL)
#define R_SRC_SRCCTRL_OFS_Msk        (0x0007UL)
#define R_SRC_SRCCTRL_OFS_Pos        (0UL)
#define R_SRC_SRCCTRL_IFS_Msk        (0x00F0UL)
#define R_SRC_SRCCTRL_IFS_Pos        (4UL)
#define R_SRC_SRCCTRL_CL_Msk         (0x0100UL)
#define R_SRC_SRCCTRL_CL_Pos         (8UL)
#define R_SRC_SRCCTRL_FL_Msk         (0x0200UL)
#define R_SRC_SRCCTRL_FL_Pos         (9UL)
#define R_SRC_SRCCTRL_OVEN_Msk       (0x0400UL)
#define R_SRC_SRCCTRL_OVEN_Pos       (10UL)
#define R_SRC_SRCCTRL_UDEN_Msk       (0x0800UL)
#define R_SRC_SRCCTRL_UDEN_Pos       (11UL)
#define R_SRC_SRCCTRL_SRCEN_Msk      (0x1000UL)
#define R_SRC_SRCCTRL_SRCEN_Pos      (12UL)
#define R_SRC_SRCCTRL_CEEN_Msk       (0x2000UL)
#define R_SRC_SRCCTRL_CEEN_Pos       (13UL)
#define R_SRC_SRCCTRL_FICRAE_Msk     (0x8000UL)
#define R_SRC_SRCCTRL_FICRAE_Pos     (15UL)
#define R_SRC_SRCSTAT_OINT_Msk       (0x0001UL)
#define R_SRC_SRCSTAT_OINT_Pos       (0UL)
#define R_SRC_SRCSTAT_IINT_Msk       (0x0002UL)
#define R_SRC_SRCSTAT_IINT_Pos       (1UL)
#define R_SRC_SRCSTAT_OVF_Msk        (0x0004UL)
#define R_SRC_SRCSTAT_OVF_Pos        (2UL)
#define R_SRC_SRCSTAT_UDF_Msk        (0x0008UL)
#define R_SRC_SRCSTAT_UDF_Pos        (3UL)
#define R_SRC_SRCSTAT_FLF_Msk        (0x0010UL)
#define R_SRC_SRCSTAT_FLF_Pos        (4UL)
#define R_SRC_SRCSTAT_CEF_Msk        (0x0020UL)
#define R_SRC_SRCSTAT_CEF_Pos        (5UL)
#define R_SRC_SRCSTAT_IFDN_Msk       (0x0780UL)
#define R_SRC_SRCSTAT_IFDN_Pos       (7UL)
#define R_SRC_SRCSTAT_OFDN_Msk       (0xF800UL)
#define R_SRC_SRCSTAT_OFDN_Pos       (11UL)

#endif
