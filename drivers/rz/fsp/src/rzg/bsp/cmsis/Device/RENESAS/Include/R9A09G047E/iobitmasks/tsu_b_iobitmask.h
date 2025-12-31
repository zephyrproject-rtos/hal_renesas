/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : tsu_b_iobitmask.h
 * Version      : 1.00
 * Description  : IO bit mask file for tsu_b.
 *********************************************************************************************************************/

#ifndef TSU_B_IOBITMASK_H
#define TSU_B_IOBITMASK_H

#define R_TSU_B_SSUSR_EN_TS_Msk         (0x00000001UL)
#define R_TSU_B_SSUSR_EN_TS_Pos         (0UL)
#define R_TSU_B_SSUSR_ADC_PD_TS_Msk     (0x00000002UL)
#define R_TSU_B_SSUSR_ADC_PD_TS_Pos     (1UL)
#define R_TSU_B_SSUSR_SOC_TS_EN_Msk     (0x00000004UL)
#define R_TSU_B_SSUSR_SOC_TS_EN_Pos     (2UL)
#define R_TSU_B_STRGR_ADST_Msk          (0x00000001UL)
#define R_TSU_B_STRGR_ADST_Pos          (0UL)
#define R_TSU_B_SOSR1_ADCT_Msk          (0x00000003UL)
#define R_TSU_B_SOSR1_ADCT_Pos          (0UL)
#define R_TSU_B_SOSR1_TRGE_Msk          (0x00000008UL)
#define R_TSU_B_SOSR1_TRGE_Pos          (3UL)
#define R_TSU_B_SOSR1_ADCS_Msk          (0x00000010UL)
#define R_TSU_B_SOSR1_ADCS_Pos          (4UL)
#define R_TSU_B_SOSR1_OUTSEL_Msk        (0x00000200UL)
#define R_TSU_B_SOSR1_OUTSEL_Pos        (9UL)
#define R_TSU_B_SCRR_OUT12BIT_TS_Msk    (0x00000FFFUL)
#define R_TSU_B_SCRR_OUT12BIT_TS_Pos    (0UL)
#define R_TSU_B_SSR_CONV_Msk            (0x00000001UL)
#define R_TSU_B_SSR_CONV_Pos            (0UL)
#define R_TSU_B_CMSR_CMPEN_Msk          (0x00000001UL)
#define R_TSU_B_CMSR_CMPEN_Pos          (0UL)
#define R_TSU_B_CMSR_CMPCOND_Msk        (0x00000002UL)
#define R_TSU_B_CMSR_CMPCOND_Pos        (1UL)
#define R_TSU_B_LLSR_LLIM_Msk           (0x00000FFFUL)
#define R_TSU_B_LLSR_LLIM_Pos           (0UL)
#define R_TSU_B_ULSR_ULIM_Msk           (0x00000FFFUL)
#define R_TSU_B_ULSR_ULIM_Pos           (0UL)
#define R_TSU_B_SISR_ADF_Msk            (0x00000001UL)
#define R_TSU_B_SISR_ADF_Pos            (0UL)
#define R_TSU_B_SISR_CMPF_Msk           (0x00000002UL)
#define R_TSU_B_SISR_CMPF_Pos           (1UL)
#define R_TSU_B_SIER_ADIE_Msk           (0x00000001UL)
#define R_TSU_B_SIER_ADIE_Pos           (0UL)
#define R_TSU_B_SIER_CMPIE_Msk          (0x00000002UL)
#define R_TSU_B_SIER_CMPIE_Pos          (1UL)
#define R_TSU_B_SICR_ADCLR_Msk          (0x00000001UL)
#define R_TSU_B_SICR_ADCLR_Pos          (0UL)
#define R_TSU_B_SICR_CMPCLR_Msk         (0x00000002UL)
#define R_TSU_B_SICR_CMPCLR_Pos         (1UL)

#define R_TSU_B0_SSUSR_EN_TS_Msk         R_TSU_B_SSUSR_EN_TS_Msk
#define R_TSU_B0_SSUSR_EN_TS_Pos         R_TSU_B_SSUSR_EN_TS_Pos
#define R_TSU_B0_SSUSR_ADC_PD_TS_Msk     R_TSU_B_SSUSR_ADC_PD_TS_Msk
#define R_TSU_B0_SSUSR_ADC_PD_TS_Pos     R_TSU_B_SSUSR_ADC_PD_TS_Pos
#define R_TSU_B0_SSUSR_SOC_TS_EN_Msk     R_TSU_B_SSUSR_SOC_TS_EN_Msk
#define R_TSU_B0_SSUSR_SOC_TS_EN_Pos     R_TSU_B_SSUSR_SOC_TS_EN_Pos
#define R_TSU_B0_STRGR_ADST_Msk          R_TSU_B_STRGR_ADST_Msk
#define R_TSU_B0_STRGR_ADST_Pos          R_TSU_B_STRGR_ADST_Pos
#define R_TSU_B0_SOSR1_ADCT_Msk          R_TSU_B_SOSR1_ADCT_Msk
#define R_TSU_B0_SOSR1_ADCT_Pos          R_TSU_B_SOSR1_ADCT_Pos
#define R_TSU_B0_SOSR1_TRGE_Msk          R_TSU_B_SOSR1_TRGE_Msk
#define R_TSU_B0_SOSR1_TRGE_Pos          R_TSU_B_SOSR1_TRGE_Pos
#define R_TSU_B0_SOSR1_ADCS_Msk          R_TSU_B_SOSR1_ADCS_Msk
#define R_TSU_B0_SOSR1_ADCS_Pos          R_TSU_B_SOSR1_ADCS_Pos
#define R_TSU_B0_SOSR1_OUTSEL_Msk        R_TSU_B_SOSR1_OUTSEL_Msk
#define R_TSU_B0_SOSR1_OUTSEL_Pos        R_TSU_B_SOSR1_OUTSEL_Pos
#define R_TSU_B0_SCRR_OUT12BIT_TS_Msk    R_TSU_B_SCRR_OUT12BIT_TS_Msk
#define R_TSU_B0_SCRR_OUT12BIT_TS_Pos    R_TSU_B_SCRR_OUT12BIT_TS_Pos
#define R_TSU_B0_SSR_CONV_Msk            R_TSU_B_SSR_CONV_Msk
#define R_TSU_B0_SSR_CONV_Pos            R_TSU_B_SSR_CONV_Pos
#define R_TSU_B0_CMSR_CMPEN_Msk          R_TSU_B_CMSR_CMPEN_Msk
#define R_TSU_B0_CMSR_CMPEN_Pos          R_TSU_B_CMSR_CMPEN_Pos
#define R_TSU_B0_CMSR_CMPCOND_Msk        R_TSU_B_CMSR_CMPCOND_Msk
#define R_TSU_B0_CMSR_CMPCOND_Pos        R_TSU_B_CMSR_CMPCOND_Pos
#define R_TSU_B0_LLSR_LLIM_Msk           R_TSU_B_LLSR_LLIM_Msk
#define R_TSU_B0_LLSR_LLIM_Pos           R_TSU_B_LLSR_LLIM_Pos
#define R_TSU_B0_ULSR_ULIM_Msk           R_TSU_B_ULSR_ULIM_Msk
#define R_TSU_B0_ULSR_ULIM_Pos           R_TSU_B_ULSR_ULIM_Pos
#define R_TSU_B0_SISR_ADF_Msk            R_TSU_B_SISR_ADF_Msk
#define R_TSU_B0_SISR_ADF_Pos            R_TSU_B_SISR_ADF_Pos
#define R_TSU_B0_SISR_CMPF_Msk           R_TSU_B_SISR_CMPF_Msk
#define R_TSU_B0_SISR_CMPF_Pos           R_TSU_B_SISR_CMPF_Pos
#define R_TSU_B0_SIER_ADIE_Msk           R_TSU_B_SIER_ADIE_Msk
#define R_TSU_B0_SIER_ADIE_Pos           R_TSU_B_SIER_ADIE_Pos
#define R_TSU_B0_SIER_CMPIE_Msk          R_TSU_B_SIER_CMPIE_Msk
#define R_TSU_B0_SIER_CMPIE_Pos          R_TSU_B_SIER_CMPIE_Pos
#define R_TSU_B0_SICR_ADCLR_Msk          R_TSU_B_SICR_ADCLR_Msk
#define R_TSU_B0_SICR_ADCLR_Pos          R_TSU_B_SICR_ADCLR_Pos
#define R_TSU_B0_SICR_CMPCLR_Msk         R_TSU_B_SICR_CMPCLR_Msk
#define R_TSU_B0_SICR_CMPCLR_Pos         R_TSU_B_SICR_CMPCLR_Pos

#endif
