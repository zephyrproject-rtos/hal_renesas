/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : adc_c_iobitmask.h
 * Version      : 1.00
 * Description  : IO bit mask file for adc_c.
 *********************************************************************************************************************/

#ifndef ADC_C_IOBITMASK_H
#define ADC_C_IOBITMASK_H

#define R_ADC_C_ADM0_ADCE_Msk         (0x00000001UL)
#define R_ADC_C_ADM0_ADCE_Pos         (0UL)
#define R_ADC_C_ADM0_ADBSY_Msk        (0x00000002UL)
#define R_ADC_C_ADM0_ADBSY_Pos        (1UL)
#define R_ADC_C_ADM0_PWDWNB_Msk       (0x00000004UL)
#define R_ADC_C_ADM0_PWDWNB_Pos       (2UL)
#define R_ADC_C_ADM0_SRESB_Msk        (0x00008000UL)
#define R_ADC_C_ADM0_SRESB_Pos        (15UL)
#define R_ADC_C_ADM1_TRG_Msk          (0x00000001UL)
#define R_ADC_C_ADM1_TRG_Pos          (0UL)
#define R_ADC_C_ADM1_TRGIN_Msk        (0x00000002UL)
#define R_ADC_C_ADM1_TRGIN_Pos        (1UL)
#define R_ADC_C_ADM1_MS_Msk           (0x00000004UL)
#define R_ADC_C_ADM1_MS_Pos           (2UL)
#define R_ADC_C_ADM1_RPS_Msk          (0x00000008UL)
#define R_ADC_C_ADM1_RPS_Pos          (3UL)
#define R_ADC_C_ADM1_BS_Msk           (0x00000010UL)
#define R_ADC_C_ADM1_BS_Pos           (4UL)
#define R_ADC_C_ADM1_EGA_Msk          (0x00003000UL)
#define R_ADC_C_ADM1_EGA_Pos          (12UL)
#define R_ADC_C_ADM1_TRGEN_Msk        (0x003F0000UL)
#define R_ADC_C_ADM1_TRGEN_Pos        (16UL)
#define R_ADC_C_ADM2_CHSEL_Msk        (0x000000FFUL)
#define R_ADC_C_ADM2_CHSEL_Pos        (0UL)
#define R_ADC_C_ADM3_ADSMP_Msk        (0x0000FFFFUL)
#define R_ADC_C_ADM3_ADSMP_Pos        (0UL)
#define R_ADC_C_ADM3_ADCMP_Msk        (0x00FF0000UL)
#define R_ADC_C_ADM3_ADCMP_Pos        (16UL)
#define R_ADC_C_ADM3_ADIL_Msk         (0xFF000000UL)
#define R_ADC_C_ADM3_ADIL_Pos         (24UL)
#define R_ADC_C_ADINT_INTEN_Msk       (0x000000FFUL)
#define R_ADC_C_ADINT_INTEN_Pos       (0UL)
#define R_ADC_C_ADINT_CSEEN_Msk       (0x00010000UL)
#define R_ADC_C_ADINT_CSEEN_Pos       (16UL)
#define R_ADC_C_ADINT_INTS_Msk        (0x80000000UL)
#define R_ADC_C_ADINT_INTS_Pos        (31UL)
#define R_ADC_C_ADSTS_INTST_Msk       (0x000000FFUL)
#define R_ADC_C_ADSTS_INTST_Pos       (0UL)
#define R_ADC_C_ADSTS_CSEST_Msk       (0x00010000UL)
#define R_ADC_C_ADSTS_CSEST_Pos       (16UL)
#define R_ADC_C_ADSTS_TRGS_Msk        (0x80000000UL)
#define R_ADC_C_ADSTS_TRGS_Pos        (31UL)
#define R_ADC_C_ADIVC_DIVADC_Msk      (0x000001FFUL)
#define R_ADC_C_ADIVC_DIVADC_Pos      (0UL)
#define R_ADC_C_ADFIL_FILONOFF_Msk    (0x00000001UL)
#define R_ADC_C_ADFIL_FILONOFF_Pos    (0UL)
#define R_ADC_C_ADFIL_FILNUM_Msk      (0x00000030UL)
#define R_ADC_C_ADFIL_FILNUM_Pos      (4UL)
#define R_ADC_C_ADCR0_AD0_Msk         (0x00000001UL)
#define R_ADC_C_ADCR0_AD0_Pos         (0UL)
#define R_ADC_C_ADCR0_AD1_Msk         (0x00000002UL)
#define R_ADC_C_ADCR0_AD1_Pos         (1UL)
#define R_ADC_C_ADCR0_AD2_Msk         (0x00000004UL)
#define R_ADC_C_ADCR0_AD2_Pos         (2UL)
#define R_ADC_C_ADCR0_AD3_Msk         (0x00000008UL)
#define R_ADC_C_ADCR0_AD3_Pos         (3UL)
#define R_ADC_C_ADCR0_AD4_Msk         (0x00000010UL)
#define R_ADC_C_ADCR0_AD4_Pos         (4UL)
#define R_ADC_C_ADCR0_AD5_Msk         (0x00000020UL)
#define R_ADC_C_ADCR0_AD5_Pos         (5UL)
#define R_ADC_C_ADCR0_AD6_Msk         (0x00000040UL)
#define R_ADC_C_ADCR0_AD6_Pos         (6UL)
#define R_ADC_C_ADCR0_AD7_Msk         (0x00000080UL)
#define R_ADC_C_ADCR0_AD7_Pos         (7UL)
#define R_ADC_C_ADCR0_AD8_Msk         (0x00000100UL)
#define R_ADC_C_ADCR0_AD8_Pos         (8UL)
#define R_ADC_C_ADCR0_AD9_Msk         (0x00000200UL)
#define R_ADC_C_ADCR0_AD9_Pos         (9UL)
#define R_ADC_C_ADCR0_AD10_Msk        (0x00000400UL)
#define R_ADC_C_ADCR0_AD10_Pos        (10UL)
#define R_ADC_C_ADCR0_AD11_Msk        (0x00000800UL)
#define R_ADC_C_ADCR0_AD11_Pos        (11UL)
#define R_ADC_C_ADCR1_AD0_Msk         (0x00000001UL)
#define R_ADC_C_ADCR1_AD0_Pos         (0UL)
#define R_ADC_C_ADCR1_AD1_Msk         (0x00000002UL)
#define R_ADC_C_ADCR1_AD1_Pos         (1UL)
#define R_ADC_C_ADCR1_AD2_Msk         (0x00000004UL)
#define R_ADC_C_ADCR1_AD2_Pos         (2UL)
#define R_ADC_C_ADCR1_AD3_Msk         (0x00000008UL)
#define R_ADC_C_ADCR1_AD3_Pos         (3UL)
#define R_ADC_C_ADCR1_AD4_Msk         (0x00000010UL)
#define R_ADC_C_ADCR1_AD4_Pos         (4UL)
#define R_ADC_C_ADCR1_AD5_Msk         (0x00000020UL)
#define R_ADC_C_ADCR1_AD5_Pos         (5UL)
#define R_ADC_C_ADCR1_AD6_Msk         (0x00000040UL)
#define R_ADC_C_ADCR1_AD6_Pos         (6UL)
#define R_ADC_C_ADCR1_AD7_Msk         (0x00000080UL)
#define R_ADC_C_ADCR1_AD7_Pos         (7UL)
#define R_ADC_C_ADCR1_AD8_Msk         (0x00000100UL)
#define R_ADC_C_ADCR1_AD8_Pos         (8UL)
#define R_ADC_C_ADCR1_AD9_Msk         (0x00000200UL)
#define R_ADC_C_ADCR1_AD9_Pos         (9UL)
#define R_ADC_C_ADCR1_AD10_Msk        (0x00000400UL)
#define R_ADC_C_ADCR1_AD10_Pos        (10UL)
#define R_ADC_C_ADCR1_AD11_Msk        (0x00000800UL)
#define R_ADC_C_ADCR1_AD11_Pos        (11UL)
#define R_ADC_C_ADCR2_AD0_Msk         (0x00000001UL)
#define R_ADC_C_ADCR2_AD0_Pos         (0UL)
#define R_ADC_C_ADCR2_AD1_Msk         (0x00000002UL)
#define R_ADC_C_ADCR2_AD1_Pos         (1UL)
#define R_ADC_C_ADCR2_AD2_Msk         (0x00000004UL)
#define R_ADC_C_ADCR2_AD2_Pos         (2UL)
#define R_ADC_C_ADCR2_AD3_Msk         (0x00000008UL)
#define R_ADC_C_ADCR2_AD3_Pos         (3UL)
#define R_ADC_C_ADCR2_AD4_Msk         (0x00000010UL)
#define R_ADC_C_ADCR2_AD4_Pos         (4UL)
#define R_ADC_C_ADCR2_AD5_Msk         (0x00000020UL)
#define R_ADC_C_ADCR2_AD5_Pos         (5UL)
#define R_ADC_C_ADCR2_AD6_Msk         (0x00000040UL)
#define R_ADC_C_ADCR2_AD6_Pos         (6UL)
#define R_ADC_C_ADCR2_AD7_Msk         (0x00000080UL)
#define R_ADC_C_ADCR2_AD7_Pos         (7UL)
#define R_ADC_C_ADCR2_AD8_Msk         (0x00000100UL)
#define R_ADC_C_ADCR2_AD8_Pos         (8UL)
#define R_ADC_C_ADCR2_AD9_Msk         (0x00000200UL)
#define R_ADC_C_ADCR2_AD9_Pos         (9UL)
#define R_ADC_C_ADCR2_AD10_Msk        (0x00000400UL)
#define R_ADC_C_ADCR2_AD10_Pos        (10UL)
#define R_ADC_C_ADCR2_AD11_Msk        (0x00000800UL)
#define R_ADC_C_ADCR2_AD11_Pos        (11UL)
#define R_ADC_C_ADCR3_AD0_Msk         (0x00000001UL)
#define R_ADC_C_ADCR3_AD0_Pos         (0UL)
#define R_ADC_C_ADCR3_AD1_Msk         (0x00000002UL)
#define R_ADC_C_ADCR3_AD1_Pos         (1UL)
#define R_ADC_C_ADCR3_AD2_Msk         (0x00000004UL)
#define R_ADC_C_ADCR3_AD2_Pos         (2UL)
#define R_ADC_C_ADCR3_AD3_Msk         (0x00000008UL)
#define R_ADC_C_ADCR3_AD3_Pos         (3UL)
#define R_ADC_C_ADCR3_AD4_Msk         (0x00000010UL)
#define R_ADC_C_ADCR3_AD4_Pos         (4UL)
#define R_ADC_C_ADCR3_AD5_Msk         (0x00000020UL)
#define R_ADC_C_ADCR3_AD5_Pos         (5UL)
#define R_ADC_C_ADCR3_AD6_Msk         (0x00000040UL)
#define R_ADC_C_ADCR3_AD6_Pos         (6UL)
#define R_ADC_C_ADCR3_AD7_Msk         (0x00000080UL)
#define R_ADC_C_ADCR3_AD7_Pos         (7UL)
#define R_ADC_C_ADCR3_AD8_Msk         (0x00000100UL)
#define R_ADC_C_ADCR3_AD8_Pos         (8UL)
#define R_ADC_C_ADCR3_AD9_Msk         (0x00000200UL)
#define R_ADC_C_ADCR3_AD9_Pos         (9UL)
#define R_ADC_C_ADCR3_AD10_Msk        (0x00000400UL)
#define R_ADC_C_ADCR3_AD10_Pos        (10UL)
#define R_ADC_C_ADCR3_AD11_Msk        (0x00000800UL)
#define R_ADC_C_ADCR3_AD11_Pos        (11UL)
#define R_ADC_C_ADCR4_AD0_Msk         (0x00000001UL)
#define R_ADC_C_ADCR4_AD0_Pos         (0UL)
#define R_ADC_C_ADCR4_AD1_Msk         (0x00000002UL)
#define R_ADC_C_ADCR4_AD1_Pos         (1UL)
#define R_ADC_C_ADCR4_AD2_Msk         (0x00000004UL)
#define R_ADC_C_ADCR4_AD2_Pos         (2UL)
#define R_ADC_C_ADCR4_AD3_Msk         (0x00000008UL)
#define R_ADC_C_ADCR4_AD3_Pos         (3UL)
#define R_ADC_C_ADCR4_AD4_Msk         (0x00000010UL)
#define R_ADC_C_ADCR4_AD4_Pos         (4UL)
#define R_ADC_C_ADCR4_AD5_Msk         (0x00000020UL)
#define R_ADC_C_ADCR4_AD5_Pos         (5UL)
#define R_ADC_C_ADCR4_AD6_Msk         (0x00000040UL)
#define R_ADC_C_ADCR4_AD6_Pos         (6UL)
#define R_ADC_C_ADCR4_AD7_Msk         (0x00000080UL)
#define R_ADC_C_ADCR4_AD7_Pos         (7UL)
#define R_ADC_C_ADCR4_AD8_Msk         (0x00000100UL)
#define R_ADC_C_ADCR4_AD8_Pos         (8UL)
#define R_ADC_C_ADCR4_AD9_Msk         (0x00000200UL)
#define R_ADC_C_ADCR4_AD9_Pos         (9UL)
#define R_ADC_C_ADCR4_AD10_Msk        (0x00000400UL)
#define R_ADC_C_ADCR4_AD10_Pos        (10UL)
#define R_ADC_C_ADCR4_AD11_Msk        (0x00000800UL)
#define R_ADC_C_ADCR4_AD11_Pos        (11UL)
#define R_ADC_C_ADCR5_AD0_Msk         (0x00000001UL)
#define R_ADC_C_ADCR5_AD0_Pos         (0UL)
#define R_ADC_C_ADCR5_AD1_Msk         (0x00000002UL)
#define R_ADC_C_ADCR5_AD1_Pos         (1UL)
#define R_ADC_C_ADCR5_AD2_Msk         (0x00000004UL)
#define R_ADC_C_ADCR5_AD2_Pos         (2UL)
#define R_ADC_C_ADCR5_AD3_Msk         (0x00000008UL)
#define R_ADC_C_ADCR5_AD3_Pos         (3UL)
#define R_ADC_C_ADCR5_AD4_Msk         (0x00000010UL)
#define R_ADC_C_ADCR5_AD4_Pos         (4UL)
#define R_ADC_C_ADCR5_AD5_Msk         (0x00000020UL)
#define R_ADC_C_ADCR5_AD5_Pos         (5UL)
#define R_ADC_C_ADCR5_AD6_Msk         (0x00000040UL)
#define R_ADC_C_ADCR5_AD6_Pos         (6UL)
#define R_ADC_C_ADCR5_AD7_Msk         (0x00000080UL)
#define R_ADC_C_ADCR5_AD7_Pos         (7UL)
#define R_ADC_C_ADCR5_AD8_Msk         (0x00000100UL)
#define R_ADC_C_ADCR5_AD8_Pos         (8UL)
#define R_ADC_C_ADCR5_AD9_Msk         (0x00000200UL)
#define R_ADC_C_ADCR5_AD9_Pos         (9UL)
#define R_ADC_C_ADCR5_AD10_Msk        (0x00000400UL)
#define R_ADC_C_ADCR5_AD10_Pos        (10UL)
#define R_ADC_C_ADCR5_AD11_Msk        (0x00000800UL)
#define R_ADC_C_ADCR5_AD11_Pos        (11UL)
#define R_ADC_C_ADCR6_AD0_Msk         (0x00000001UL)
#define R_ADC_C_ADCR6_AD0_Pos         (0UL)
#define R_ADC_C_ADCR6_AD1_Msk         (0x00000002UL)
#define R_ADC_C_ADCR6_AD1_Pos         (1UL)
#define R_ADC_C_ADCR6_AD2_Msk         (0x00000004UL)
#define R_ADC_C_ADCR6_AD2_Pos         (2UL)
#define R_ADC_C_ADCR6_AD3_Msk         (0x00000008UL)
#define R_ADC_C_ADCR6_AD3_Pos         (3UL)
#define R_ADC_C_ADCR6_AD4_Msk         (0x00000010UL)
#define R_ADC_C_ADCR6_AD4_Pos         (4UL)
#define R_ADC_C_ADCR6_AD5_Msk         (0x00000020UL)
#define R_ADC_C_ADCR6_AD5_Pos         (5UL)
#define R_ADC_C_ADCR6_AD6_Msk         (0x00000040UL)
#define R_ADC_C_ADCR6_AD6_Pos         (6UL)
#define R_ADC_C_ADCR6_AD7_Msk         (0x00000080UL)
#define R_ADC_C_ADCR6_AD7_Pos         (7UL)
#define R_ADC_C_ADCR6_AD8_Msk         (0x00000100UL)
#define R_ADC_C_ADCR6_AD8_Pos         (8UL)
#define R_ADC_C_ADCR6_AD9_Msk         (0x00000200UL)
#define R_ADC_C_ADCR6_AD9_Pos         (9UL)
#define R_ADC_C_ADCR6_AD10_Msk        (0x00000400UL)
#define R_ADC_C_ADCR6_AD10_Pos        (10UL)
#define R_ADC_C_ADCR6_AD11_Msk        (0x00000800UL)
#define R_ADC_C_ADCR6_AD11_Pos        (11UL)
#define R_ADC_C_ADCR7_AD0_Msk         (0x00000001UL)
#define R_ADC_C_ADCR7_AD0_Pos         (0UL)
#define R_ADC_C_ADCR7_AD1_Msk         (0x00000002UL)
#define R_ADC_C_ADCR7_AD1_Pos         (1UL)
#define R_ADC_C_ADCR7_AD2_Msk         (0x00000004UL)
#define R_ADC_C_ADCR7_AD2_Pos         (2UL)
#define R_ADC_C_ADCR7_AD3_Msk         (0x00000008UL)
#define R_ADC_C_ADCR7_AD3_Pos         (3UL)
#define R_ADC_C_ADCR7_AD4_Msk         (0x00000010UL)
#define R_ADC_C_ADCR7_AD4_Pos         (4UL)
#define R_ADC_C_ADCR7_AD5_Msk         (0x00000020UL)
#define R_ADC_C_ADCR7_AD5_Pos         (5UL)
#define R_ADC_C_ADCR7_AD6_Msk         (0x00000040UL)
#define R_ADC_C_ADCR7_AD6_Pos         (6UL)
#define R_ADC_C_ADCR7_AD7_Msk         (0x00000080UL)
#define R_ADC_C_ADCR7_AD7_Pos         (7UL)
#define R_ADC_C_ADCR7_AD8_Msk         (0x00000100UL)
#define R_ADC_C_ADCR7_AD8_Pos         (8UL)
#define R_ADC_C_ADCR7_AD9_Msk         (0x00000200UL)
#define R_ADC_C_ADCR7_AD9_Pos         (9UL)
#define R_ADC_C_ADCR7_AD10_Msk        (0x00000400UL)
#define R_ADC_C_ADCR7_AD10_Pos        (10UL)
#define R_ADC_C_ADCR7_AD11_Msk        (0x00000800UL)
#define R_ADC_C_ADCR7_AD11_Pos        (11UL)

#endif
