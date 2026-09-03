/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_SYSTEM_POSMSK_H
#define R_SYSTEM_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                         R_SYSTEM                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  SYSCR0  ========================================================= */
#define R_SYSTEM_SYSCR0_KEY_Pos                 (8UL)          /*!< KEY (Bit 8)                                           */
#define R_SYSTEM_SYSCR0_KEY_Msk                 (0xff00UL)     /*!< KEY (Bitfield-Mask: 0xff)                             */
#define R_SYSTEM_SYSCR0_ROME_Pos                (0UL)          /*!< ROME (Bit 0)                                          */
#define R_SYSTEM_SYSCR0_ROME_Msk                (0x1UL)        /*!< ROME (Bitfield-Mask: 0x01)                            */
/* =========================================================  MDSAR  ========================================================= */
#define R_SYSTEM_MDSAR_NONSEC8_Pos              (8UL)          /*!< NONSEC8 (Bit 8)                                       */
#define R_SYSTEM_MDSAR_NONSEC8_Msk              (0x100UL)      /*!< NONSEC8 (Bitfield-Mask: 0x01)                         */
/* =========================================================  PRCR  ========================================================== */
#define R_SYSTEM_PRCR_PRKEY_Pos                 (8UL)          /*!< PRKEY (Bit 8)                                         */
#define R_SYSTEM_PRCR_PRKEY_Msk                 (0xff00UL)     /*!< PRKEY (Bitfield-Mask: 0xff)                           */
#define R_SYSTEM_PRCR_PRC5_Pos                  (5UL)          /*!< PRC5 (Bit 5)                                          */
#define R_SYSTEM_PRCR_PRC5_Msk                  (0x20UL)       /*!< PRC5 (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PRCR_PRC4_Pos                  (4UL)          /*!< PRC4 (Bit 4)                                          */
#define R_SYSTEM_PRCR_PRC4_Msk                  (0x10UL)       /*!< PRC4 (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PRCR_PRC3_Pos                  (3UL)          /*!< PRC3 (Bit 3)                                          */
#define R_SYSTEM_PRCR_PRC3_Msk                  (0x8UL)        /*!< PRC3 (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PRCR_PRC1_Pos                  (1UL)          /*!< PRC1 (Bit 1)                                          */
#define R_SYSTEM_PRCR_PRC1_Msk                  (0x2UL)        /*!< PRC1 (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PRCR_PRC0_Pos                  (0UL)          /*!< PRC0 (Bit 0)                                          */
#define R_SYSTEM_PRCR_PRC0_Msk                  (0x1UL)        /*!< PRC0 (Bitfield-Mask: 0x01)                            */
/* ========================================================  PVDSAR  ========================================================= */
#define R_SYSTEM_PVDSAR_NONSEC1_Pos             (1UL)          /*!< NONSEC1 (Bit 1)                                       */
#define R_SYSTEM_PVDSAR_NONSEC1_Msk             (0x2UL)        /*!< NONSEC1 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_PVDSAR_NONSEC0_Pos             (0UL)          /*!< NONSEC0 (Bit 0)                                       */
#define R_SYSTEM_PVDSAR_NONSEC0_Msk             (0x1UL)        /*!< NONSEC0 (Bitfield-Mask: 0x01)                         */
/* =======================================================  PVD1CMPCR  ======================================================= */
#define R_SYSTEM_PVD1CMPCR_PVDE_Pos             (7UL)          /*!< PVDE (Bit 7)                                          */
#define R_SYSTEM_PVD1CMPCR_PVDE_Msk             (0x80UL)       /*!< PVDE (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PVD1CMPCR_PVDLVL_Pos           (0UL)          /*!< PVDLVL (Bit 0)                                        */
#define R_SYSTEM_PVD1CMPCR_PVDLVL_Msk           (0x1fUL)       /*!< PVDLVL (Bitfield-Mask: 0x1f)                          */
/* =======================================================  PVD2CMPCR  ======================================================= */
#define R_SYSTEM_PVD2CMPCR_PVDE_Pos             (7UL)          /*!< PVDE (Bit 7)                                          */
#define R_SYSTEM_PVD2CMPCR_PVDE_Msk             (0x80UL)       /*!< PVDE (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PVD2CMPCR_PVDLVL_Pos           (0UL)          /*!< PVDLVL (Bit 0)                                        */
#define R_SYSTEM_PVD2CMPCR_PVDLVL_Msk           (0x1fUL)       /*!< PVDLVL (Bitfield-Mask: 0x1f)                          */
/* =======================================================  PVD4CMPCR  ======================================================= */
#define R_SYSTEM_PVD4CMPCR_PVDE_Pos             (7UL)          /*!< PVDE (Bit 7)                                          */
#define R_SYSTEM_PVD4CMPCR_PVDE_Msk             (0x80UL)       /*!< PVDE (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PVD4CMPCR_PVDLVL_Pos           (0UL)          /*!< PVDLVL (Bit 0)                                        */
#define R_SYSTEM_PVD4CMPCR_PVDLVL_Msk           (0x1fUL)       /*!< PVDLVL (Bitfield-Mask: 0x1f)                          */
/* =======================================================  PVD5CMPCR  ======================================================= */
#define R_SYSTEM_PVD5CMPCR_PVDE_Pos             (7UL)          /*!< PVDE (Bit 7)                                          */
#define R_SYSTEM_PVD5CMPCR_PVDE_Msk             (0x80UL)       /*!< PVDE (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PVD5CMPCR_PVDLVL_Pos           (0UL)          /*!< PVDLVL (Bit 0)                                        */
#define R_SYSTEM_PVD5CMPCR_PVDLVL_Msk           (0x1fUL)       /*!< PVDLVL (Bitfield-Mask: 0x1f)                          */
/* ========================================================  PVD1CR0  ======================================================== */
#define R_SYSTEM_PVD1CR0_RN_Pos                 (7UL)          /*!< RN (Bit 7)                                            */
#define R_SYSTEM_PVD1CR0_RN_Msk                 (0x80UL)       /*!< RN (Bitfield-Mask: 0x01)                              */
#define R_SYSTEM_PVD1CR0_RI_Pos                 (6UL)          /*!< RI (Bit 6)                                            */
#define R_SYSTEM_PVD1CR0_RI_Msk                 (0x40UL)       /*!< RI (Bitfield-Mask: 0x01)                              */
#define R_SYSTEM_PVD1CR0_FSAMP_Pos              (4UL)          /*!< FSAMP (Bit 4)                                         */
#define R_SYSTEM_PVD1CR0_FSAMP_Msk              (0x30UL)       /*!< FSAMP (Bitfield-Mask: 0x03)                           */
#define R_SYSTEM_PVD1CR0_CMPE_Pos               (2UL)          /*!< CMPE (Bit 2)                                          */
#define R_SYSTEM_PVD1CR0_CMPE_Msk               (0x4UL)        /*!< CMPE (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PVD1CR0_DFDIS_Pos              (1UL)          /*!< DFDIS (Bit 1)                                         */
#define R_SYSTEM_PVD1CR0_DFDIS_Msk              (0x2UL)        /*!< DFDIS (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_PVD1CR0_RIE_Pos                (0UL)          /*!< RIE (Bit 0)                                           */
#define R_SYSTEM_PVD1CR0_RIE_Msk                (0x1UL)        /*!< RIE (Bitfield-Mask: 0x01)                             */
/* ========================================================  PVD2CR0  ======================================================== */
#define R_SYSTEM_PVD2CR0_RN_Pos                 (7UL)          /*!< RN (Bit 7)                                            */
#define R_SYSTEM_PVD2CR0_RN_Msk                 (0x80UL)       /*!< RN (Bitfield-Mask: 0x01)                              */
#define R_SYSTEM_PVD2CR0_RI_Pos                 (6UL)          /*!< RI (Bit 6)                                            */
#define R_SYSTEM_PVD2CR0_RI_Msk                 (0x40UL)       /*!< RI (Bitfield-Mask: 0x01)                              */
#define R_SYSTEM_PVD2CR0_FSAMP_Pos              (4UL)          /*!< FSAMP (Bit 4)                                         */
#define R_SYSTEM_PVD2CR0_FSAMP_Msk              (0x30UL)       /*!< FSAMP (Bitfield-Mask: 0x03)                           */
#define R_SYSTEM_PVD2CR0_CMPE_Pos               (2UL)          /*!< CMPE (Bit 2)                                          */
#define R_SYSTEM_PVD2CR0_CMPE_Msk               (0x4UL)        /*!< CMPE (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PVD2CR0_DFDIS_Pos              (1UL)          /*!< DFDIS (Bit 1)                                         */
#define R_SYSTEM_PVD2CR0_DFDIS_Msk              (0x2UL)        /*!< DFDIS (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_PVD2CR0_RIE_Pos                (0UL)          /*!< RIE (Bit 0)                                           */
#define R_SYSTEM_PVD2CR0_RIE_Msk                (0x1UL)        /*!< RIE (Bitfield-Mask: 0x01)                             */
/* ========================================================  PVD4CR0  ======================================================== */
#define R_SYSTEM_PVD4CR0_FSAMP_Pos              (4UL)          /*!< FSAMP (Bit 4)                                         */
#define R_SYSTEM_PVD4CR0_FSAMP_Msk              (0x30UL)       /*!< FSAMP (Bitfield-Mask: 0x03)                           */
#define R_SYSTEM_PVD4CR0_CMPE_Pos               (2UL)          /*!< CMPE (Bit 2)                                          */
#define R_SYSTEM_PVD4CR0_CMPE_Msk               (0x4UL)        /*!< CMPE (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PVD4CR0_DFDIS_Pos              (1UL)          /*!< DFDIS (Bit 1)                                         */
#define R_SYSTEM_PVD4CR0_DFDIS_Msk              (0x2UL)        /*!< DFDIS (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_PVD4CR0_RE_Pos                 (0UL)          /*!< RE (Bit 0)                                            */
#define R_SYSTEM_PVD4CR0_RE_Msk                 (0x1UL)        /*!< RE (Bitfield-Mask: 0x01)                              */
/* ========================================================  PVD5CR0  ======================================================== */
#define R_SYSTEM_PVD5CR0_FSAMP_Pos              (4UL)          /*!< FSAMP (Bit 4)                                         */
#define R_SYSTEM_PVD5CR0_FSAMP_Msk              (0x30UL)       /*!< FSAMP (Bitfield-Mask: 0x03)                           */
#define R_SYSTEM_PVD5CR0_CMPE_Pos               (2UL)          /*!< CMPE (Bit 2)                                          */
#define R_SYSTEM_PVD5CR0_CMPE_Msk               (0x4UL)        /*!< CMPE (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_PVD5CR0_DFDIS_Pos              (1UL)          /*!< DFDIS (Bit 1)                                         */
#define R_SYSTEM_PVD5CR0_DFDIS_Msk              (0x2UL)        /*!< DFDIS (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_PVD5CR0_RE_Pos                 (0UL)          /*!< RE (Bit 0)                                            */
#define R_SYSTEM_PVD5CR0_RE_Msk                 (0x1UL)        /*!< RE (Bitfield-Mask: 0x01)                              */
/* ========================================================  PVD1CR1  ======================================================== */
#define R_SYSTEM_PVD1CR1_IRQSEL_Pos             (2UL)          /*!< IRQSEL (Bit 2)                                        */
#define R_SYSTEM_PVD1CR1_IRQSEL_Msk             (0x4UL)        /*!< IRQSEL (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PVD1CR1_IDTSEL_Pos             (0UL)          /*!< IDTSEL (Bit 0)                                        */
#define R_SYSTEM_PVD1CR1_IDTSEL_Msk             (0x3UL)        /*!< IDTSEL (Bitfield-Mask: 0x03)                          */
/* ========================================================  PVD2CR1  ======================================================== */
#define R_SYSTEM_PVD2CR1_IRQSEL_Pos             (2UL)          /*!< IRQSEL (Bit 2)                                        */
#define R_SYSTEM_PVD2CR1_IRQSEL_Msk             (0x4UL)        /*!< IRQSEL (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PVD2CR1_IDTSEL_Pos             (0UL)          /*!< IDTSEL (Bit 0)                                        */
#define R_SYSTEM_PVD2CR1_IDTSEL_Msk             (0x3UL)        /*!< IDTSEL (Bitfield-Mask: 0x03)                          */
/* ========================================================  PVD1SR  ========================================================= */
#define R_SYSTEM_PVD1SR_MON_Pos                 (1UL)          /*!< MON (Bit 1)                                           */
#define R_SYSTEM_PVD1SR_MON_Msk                 (0x2UL)        /*!< MON (Bitfield-Mask: 0x01)                             */
#define R_SYSTEM_PVD1SR_DET_Pos                 (0UL)          /*!< DET (Bit 0)                                           */
#define R_SYSTEM_PVD1SR_DET_Msk                 (0x1UL)        /*!< DET (Bitfield-Mask: 0x01)                             */
/* ========================================================  PVD2SR  ========================================================= */
#define R_SYSTEM_PVD2SR_MON_Pos                 (1UL)          /*!< MON (Bit 1)                                           */
#define R_SYSTEM_PVD2SR_MON_Msk                 (0x2UL)        /*!< MON (Bitfield-Mask: 0x01)                             */
#define R_SYSTEM_PVD2SR_DET_Pos                 (0UL)          /*!< DET (Bit 0)                                           */
#define R_SYSTEM_PVD2SR_DET_Msk                 (0x1UL)        /*!< DET (Bitfield-Mask: 0x01)                             */
/* ========================================================  PVD1FCR  ======================================================== */
#define R_SYSTEM_PVD1FCR_RHSEL_Pos              (0UL)          /*!< RHSEL (Bit 0)                                         */
#define R_SYSTEM_PVD1FCR_RHSEL_Msk              (0x1UL)        /*!< RHSEL (Bitfield-Mask: 0x01)                           */
/* ========================================================  PVD2FCR  ======================================================== */
#define R_SYSTEM_PVD2FCR_RHSEL_Pos              (0UL)          /*!< RHSEL (Bit 0)                                         */
#define R_SYSTEM_PVD2FCR_RHSEL_Msk              (0x1UL)        /*!< RHSEL (Bitfield-Mask: 0x01)                           */
/* ========================================================  PVD4FCR  ======================================================== */
#define R_SYSTEM_PVD4FCR_RHSEL_Pos              (0UL)          /*!< RHSEL (Bit 0)                                         */
#define R_SYSTEM_PVD4FCR_RHSEL_Msk              (0x1UL)        /*!< RHSEL (Bitfield-Mask: 0x01)                           */
/* ========================================================  PVD5FCR  ======================================================== */
#define R_SYSTEM_PVD5FCR_RHSEL_Pos              (0UL)          /*!< RHSEL (Bit 0)                                         */
#define R_SYSTEM_PVD5FCR_RHSEL_Msk              (0x1UL)        /*!< RHSEL (Bitfield-Mask: 0x01)                           */
/* =========================================================  PVDLR  ========================================================= */
#define R_SYSTEM_PVDLR_LOCK_Pos                 (0UL)          /*!< LOCK (Bit 0)                                          */
#define R_SYSTEM_PVDLR_LOCK_Msk                 (0x1UL)        /*!< LOCK (Bitfield-Mask: 0x01)                            */
/* ========================================================  RSTSR1  ========================================================= */
#define R_SYSTEM_RSTSR1_CMRF_Pos                (14UL)         /*!< CMRF (Bit 14)                                         */
#define R_SYSTEM_RSTSR1_CMRF_Msk                (0x4000UL)     /*!< CMRF (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_RSTSR1_BUSRF_Pos               (10UL)         /*!< BUSRF (Bit 10)                                        */
#define R_SYSTEM_RSTSR1_BUSRF_Msk               (0x400UL)      /*!< BUSRF (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_RSTSR1_LM0RF_Pos               (5UL)          /*!< LM0RF (Bit 5)                                         */
#define R_SYSTEM_RSTSR1_LM0RF_Msk               (0x20UL)       /*!< LM0RF (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_RSTSR1_SWRF_Pos                (2UL)          /*!< SWRF (Bit 2)                                          */
#define R_SYSTEM_RSTSR1_SWRF_Msk                (0x4UL)        /*!< SWRF (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_RSTSR1_WDT0RF_Pos              (1UL)          /*!< WDT0RF (Bit 1)                                        */
#define R_SYSTEM_RSTSR1_WDT0RF_Msk              (0x2UL)        /*!< WDT0RF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSTSR1_IWDTRF_Pos              (0UL)          /*!< IWDTRF (Bit 0)                                        */
#define R_SYSTEM_RSTSR1_IWDTRF_Msk              (0x1UL)        /*!< IWDTRF (Bitfield-Mask: 0x01)                          */
/* ========================================================  RSTSAR  ========================================================= */
#define R_SYSTEM_RSTSAR_NONSEC5_Pos             (5UL)          /*!< NONSEC5 (Bit 5)                                       */
#define R_SYSTEM_RSTSAR_NONSEC5_Msk             (0x20UL)       /*!< NONSEC5 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_RSTSAR_NONSEC3_Pos             (3UL)          /*!< NONSEC3 (Bit 3)                                       */
#define R_SYSTEM_RSTSAR_NONSEC3_Msk             (0x8UL)        /*!< NONSEC3 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_RSTSAR_NONSEC2_Pos             (2UL)          /*!< NONSEC2 (Bit 2)                                       */
#define R_SYSTEM_RSTSAR_NONSEC2_Msk             (0x4UL)        /*!< NONSEC2 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_RSTSAR_NONSEC1_Pos             (1UL)          /*!< NONSEC1 (Bit 1)                                       */
#define R_SYSTEM_RSTSAR_NONSEC1_Msk             (0x2UL)        /*!< NONSEC1 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_RSTSAR_NONSEC0_Pos             (0UL)          /*!< NONSEC0 (Bit 0)                                       */
#define R_SYSTEM_RSTSAR_NONSEC0_Msk             (0x1UL)        /*!< NONSEC0 (Bitfield-Mask: 0x01)                         */
/* ========================================================  RSTSR0  ========================================================= */
#define R_SYSTEM_RSTSR0_DPSRSTF_Pos             (7UL)          /*!< DPSRSTF (Bit 7)                                       */
#define R_SYSTEM_RSTSR0_DPSRSTF_Msk             (0x80UL)       /*!< DPSRSTF (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_RSTSR0_PVD5RF_Pos              (6UL)          /*!< PVD5RF (Bit 6)                                        */
#define R_SYSTEM_RSTSR0_PVD5RF_Msk              (0x40UL)       /*!< PVD5RF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSTSR0_PVD4RF_Pos              (5UL)          /*!< PVD4RF (Bit 5)                                        */
#define R_SYSTEM_RSTSR0_PVD4RF_Msk              (0x20UL)       /*!< PVD4RF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSTSR0_PVD2RF_Pos              (3UL)          /*!< PVD2RF (Bit 3)                                        */
#define R_SYSTEM_RSTSR0_PVD2RF_Msk              (0x8UL)        /*!< PVD2RF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSTSR0_PVD1RF_Pos              (2UL)          /*!< PVD1RF (Bit 2)                                        */
#define R_SYSTEM_RSTSR0_PVD1RF_Msk              (0x4UL)        /*!< PVD1RF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSTSR0_PVD0RF_Pos              (1UL)          /*!< PVD0RF (Bit 1)                                        */
#define R_SYSTEM_RSTSR0_PVD0RF_Msk              (0x2UL)        /*!< PVD0RF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSTSR0_PORF_Pos                (0UL)          /*!< PORF (Bit 0)                                          */
#define R_SYSTEM_RSTSR0_PORF_Msk                (0x1UL)        /*!< PORF (Bitfield-Mask: 0x01)                            */
/* ========================================================  RSTSR2  ========================================================= */
#define R_SYSTEM_RSTSR2_CWSF_Pos                (0UL)          /*!< CWSF (Bit 0)                                          */
#define R_SYSTEM_RSTSR2_CWSF_Msk                (0x1UL)        /*!< CWSF (Bitfield-Mask: 0x01)                            */
/* ========================================================  RSTSR3  ========================================================= */
#define R_SYSTEM_RSTSR3_TEMPRF_Pos              (7UL)          /*!< TEMPRF (Bit 7)                                        */
#define R_SYSTEM_RSTSR3_TEMPRF_Msk              (0x80UL)       /*!< TEMPRF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSTSR3_CVMRF_Pos               (0UL)          /*!< CVMRF (Bit 0)                                         */
#define R_SYSTEM_RSTSR3_CVMRF_Msk               (0x1UL)        /*!< CVMRF (Bitfield-Mask: 0x01)                           */
/* =======================================================  SYRSTMSK0  ======================================================= */
#define R_SYSTEM_SYRSTMSK0_BUSMASK_Pos          (7UL)          /*!< BUSMASK (Bit 7)                                       */
#define R_SYSTEM_SYRSTMSK0_BUSMASK_Msk          (0x80UL)       /*!< BUSMASK (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_SYRSTMSK0_CMMASK_Pos           (6UL)          /*!< CMMASK (Bit 6)                                        */
#define R_SYSTEM_SYRSTMSK0_CMMASK_Msk           (0x40UL)       /*!< CMMASK (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_SYRSTMSK0_LM0MASK_Pos          (5UL)          /*!< LM0MASK (Bit 5)                                       */
#define R_SYSTEM_SYRSTMSK0_LM0MASK_Msk          (0x20UL)       /*!< LM0MASK (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_SYRSTMSK0_SWMASK_Pos           (2UL)          /*!< SWMASK (Bit 2)                                        */
#define R_SYSTEM_SYRSTMSK0_SWMASK_Msk           (0x4UL)        /*!< SWMASK (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_SYRSTMSK0_WDT0MASK_Pos         (1UL)          /*!< WDT0MASK (Bit 1)                                      */
#define R_SYSTEM_SYRSTMSK0_WDT0MASK_Msk         (0x2UL)        /*!< WDT0MASK (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_SYRSTMSK0_IWDTMASK_Pos         (0UL)          /*!< IWDTMASK (Bit 0)                                      */
#define R_SYSTEM_SYRSTMSK0_IWDTMASK_Msk         (0x1UL)        /*!< IWDTMASK (Bitfield-Mask: 0x01)                        */
/* =======================================================  SYRSTMSK2  ======================================================= */
#define R_SYSTEM_SYRSTMSK2_PVD2MASK_Pos         (1UL)          /*!< PVD2MASK (Bit 1)                                      */
#define R_SYSTEM_SYRSTMSK2_PVD2MASK_Msk         (0x2UL)        /*!< PVD2MASK (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_SYRSTMSK2_PVD1MASK_Pos         (0UL)          /*!< PVD1MASK (Bit 0)                                      */
#define R_SYSTEM_SYRSTMSK2_PVD1MASK_Msk         (0x1UL)        /*!< PVD1MASK (Bitfield-Mask: 0x01)                        */
/* ========================================================  TEMPRCR  ======================================================== */
#define R_SYSTEM_TEMPRCR_TSNKEEP_Pos            (3UL)          /*!< TSNKEEP (Bit 3)                                       */
#define R_SYSTEM_TEMPRCR_TSNKEEP_Msk            (0x8UL)        /*!< TSNKEEP (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_TEMPRCR_CMPEN_Pos              (2UL)          /*!< CMPEN (Bit 2)                                         */
#define R_SYSTEM_TEMPRCR_CMPEN_Msk              (0x4UL)        /*!< CMPEN (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_TEMPRCR_TSNEN_Pos              (1UL)          /*!< TSNEN (Bit 1)                                         */
#define R_SYSTEM_TEMPRCR_TSNEN_Msk              (0x2UL)        /*!< TSNEN (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_TEMPRCR_TEMPREN_Pos            (0UL)          /*!< TEMPREN (Bit 0)                                       */
#define R_SYSTEM_TEMPRCR_TEMPREN_Msk            (0x1UL)        /*!< TEMPREN (Bitfield-Mask: 0x01)                         */
/* ========================================================  TEMPRLR  ======================================================== */
#define R_SYSTEM_TEMPRLR_LOCK_Pos               (0UL)          /*!< LOCK (Bit 0)                                          */
#define R_SYSTEM_TEMPRLR_LOCK_Msk               (0x1UL)        /*!< LOCK (Bitfield-Mask: 0x01)                            */
/* ========================================================  ROUTSR0  ======================================================== */
#define R_SYSTEM_ROUTSR0_ROPVD5RF_Pos           (6UL)          /*!< ROPVD5RF (Bit 6)                                      */
#define R_SYSTEM_ROUTSR0_ROPVD5RF_Msk           (0x40UL)       /*!< ROPVD5RF (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_ROUTSR0_ROPVD4RF_Pos           (5UL)          /*!< ROPVD4RF (Bit 5)                                      */
#define R_SYSTEM_ROUTSR0_ROPVD4RF_Msk           (0x20UL)       /*!< ROPVD4RF (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_ROUTSR0_ROPVD2RF_Pos           (3UL)          /*!< ROPVD2RF (Bit 3)                                      */
#define R_SYSTEM_ROUTSR0_ROPVD2RF_Msk           (0x8UL)        /*!< ROPVD2RF (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_ROUTSR0_ROPVD1RF_Pos           (2UL)          /*!< ROPVD1RF (Bit 2)                                      */
#define R_SYSTEM_ROUTSR0_ROPVD1RF_Msk           (0x4UL)        /*!< ROPVD1RF (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_ROUTSR0_ROPVD0RF_Pos           (1UL)          /*!< ROPVD0RF (Bit 1)                                      */
#define R_SYSTEM_ROUTSR0_ROPVD0RF_Msk           (0x2UL)        /*!< ROPVD0RF (Bitfield-Mask: 0x01)                        */
/* ========================================================  ROUTSR1  ======================================================== */
#define R_SYSTEM_ROUTSR1_ROCMRF_Pos             (14UL)         /*!< ROCMRF (Bit 14)                                       */
#define R_SYSTEM_ROUTSR1_ROCMRF_Msk             (0x4000UL)     /*!< ROCMRF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_ROUTSR1_ROBUSRF_Pos            (10UL)         /*!< ROBUSRF (Bit 10)                                      */
#define R_SYSTEM_ROUTSR1_ROBUSRF_Msk            (0x400UL)      /*!< ROBUSRF (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_ROUTSR1_ROLM0RF_Pos            (5UL)          /*!< ROLM0RF (Bit 5)                                       */
#define R_SYSTEM_ROUTSR1_ROLM0RF_Msk            (0x20UL)       /*!< ROLM0RF (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_ROUTSR1_ROSWRF_Pos             (2UL)          /*!< ROSWRF (Bit 2)                                        */
#define R_SYSTEM_ROUTSR1_ROSWRF_Msk             (0x4UL)        /*!< ROSWRF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_ROUTSR1_ROWDT0RF_Pos           (1UL)          /*!< ROWDT0RF (Bit 1)                                      */
#define R_SYSTEM_ROUTSR1_ROWDT0RF_Msk           (0x2UL)        /*!< ROWDT0RF (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_ROUTSR1_ROIWDTRF_Pos           (0UL)          /*!< ROIWDTRF (Bit 0)                                      */
#define R_SYSTEM_ROUTSR1_ROIWDTRF_Msk           (0x1UL)        /*!< ROIWDTRF (Bitfield-Mask: 0x01)                        */
/* ========================================================  ROUTSR2  ======================================================== */
#define R_SYSTEM_ROUTSR2_ROTEMPRF_Pos           (7UL)          /*!< ROTEMPRF (Bit 7)                                      */
#define R_SYSTEM_ROUTSR2_ROTEMPRF_Msk           (0x80UL)       /*!< ROTEMPRF (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_ROUTSR2_ROCVMRF_Pos            (0UL)          /*!< ROCVMRF (Bit 0)                                       */
#define R_SYSTEM_ROUTSR2_ROCVMRF_Msk            (0x1UL)        /*!< ROCVMRF (Bitfield-Mask: 0x01)                         */
/* =========================================================  SWRR  ========================================================== */
#define R_SYSTEM_SWRR_SWRR_Pos                  (0UL)          /*!< SWRR (Bit 0)                                          */
#define R_SYSTEM_SWRR_SWRR_Msk                  (0xffffUL)     /*!< SWRR (Bitfield-Mask: 0xffff)                          */
/* =======================================================  VBATTMCR  ======================================================== */
#define R_SYSTEM_VBATTMCR_VBATTME_Pos           (0UL)          /*!< VBATTME (Bit 0)                                       */
#define R_SYSTEM_VBATTMCR_VBATTME_Msk           (0x1UL)        /*!< VBATTME (Bitfield-Mask: 0x01)                         */
/* =========================================================  BKRCR  ========================================================= */
#define R_SYSTEM_BKRCR_BKRAE_Pos                (3UL)          /*!< BKRAE (Bit 3)                                         */
#define R_SYSTEM_BKRCR_BKRAE_Msk                (0x8UL)        /*!< BKRAE (Bitfield-Mask: 0x01)                           */
/* =======================================================  VBATTCR1  ======================================================== */
#define R_SYSTEM_VBATTCR1_PSWDIS_Pos            (0UL)          /*!< PSWDIS (Bit 0)                                        */
#define R_SYSTEM_VBATTCR1_PSWDIS_Msk            (0x1UL)        /*!< PSWDIS (Bitfield-Mask: 0x01)                          */
/* =======================================================  VBATTCR2  ======================================================== */
#define R_SYSTEM_VBATTCR2_VDETE_Pos             (4UL)          /*!< VDETE (Bit 4)                                         */
#define R_SYSTEM_VBATTCR2_VDETE_Msk             (0x10UL)       /*!< VDETE (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_VBATTCR2_VDETSEL_Pos           (0UL)          /*!< VDETSEL (Bit 0)                                       */
#define R_SYSTEM_VBATTCR2_VDETSEL_Msk           (0x7UL)        /*!< VDETSEL (Bitfield-Mask: 0x07)                         */
/* =========================================================  BKPSR  ========================================================= */
#define R_SYSTEM_BKPSR_PSMF_Pos                 (5UL)          /*!< PSMF (Bit 5)                                          */
#define R_SYSTEM_BKPSR_PSMF_Msk                 (0x20UL)       /*!< PSMF (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_BKPSR_PDRMF_Pos                (4UL)          /*!< PDRMF (Bit 4)                                         */
#define R_SYSTEM_BKPSR_PDRMF_Msk                (0x10UL)       /*!< PDRMF (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_BKPSR_PDDF_Pos                 (0UL)          /*!< PDDF (Bit 0)                                          */
#define R_SYSTEM_BKPSR_PDDF_Msk                 (0x1UL)        /*!< PDDF (Bitfield-Mask: 0x01)                            */
/* ========================================================  TAMPSR  ========================================================= */
#define R_SYSTEM_TAMPSR_TAMP2F_Pos              (2UL)          /*!< TAMP2F (Bit 2)                                        */
#define R_SYSTEM_TAMPSR_TAMP2F_Msk              (0x4UL)        /*!< TAMP2F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPSR_TAMP1F_Pos              (1UL)          /*!< TAMP1F (Bit 1)                                        */
#define R_SYSTEM_TAMPSR_TAMP1F_Msk              (0x2UL)        /*!< TAMP1F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPSR_TAMP0F_Pos              (0UL)          /*!< TAMP0F (Bit 0)                                        */
#define R_SYSTEM_TAMPSR_TAMP0F_Msk              (0x1UL)        /*!< TAMP0F (Bitfield-Mask: 0x01)                          */
/* ========================================================  TAMPCR  ========================================================= */
#define R_SYSTEM_TAMPCR_TAMP2EE_Pos             (6UL)          /*!< TAMP2EE (Bit 6)                                       */
#define R_SYSTEM_TAMPCR_TAMP2EE_Msk             (0x40UL)       /*!< TAMP2EE (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_TAMPCR_TAMP1EE_Pos             (5UL)          /*!< TAMP1EE (Bit 5)                                       */
#define R_SYSTEM_TAMPCR_TAMP1EE_Msk             (0x20UL)       /*!< TAMP1EE (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_TAMPCR_TAMP0EE_Pos             (4UL)          /*!< TAMP0EE (Bit 4)                                       */
#define R_SYSTEM_TAMPCR_TAMP0EE_Msk             (0x10UL)       /*!< TAMP0EE (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_TAMPCR_TAMP2IE_Pos             (2UL)          /*!< TAMP2IE (Bit 2)                                       */
#define R_SYSTEM_TAMPCR_TAMP2IE_Msk             (0x4UL)        /*!< TAMP2IE (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_TAMPCR_TAMP1IE_Pos             (1UL)          /*!< TAMP1IE (Bit 1)                                       */
#define R_SYSTEM_TAMPCR_TAMP1IE_Msk             (0x2UL)        /*!< TAMP1IE (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_TAMPCR_TAMP0IE_Pos             (0UL)          /*!< TAMP0IE (Bit 0)                                       */
#define R_SYSTEM_TAMPCR_TAMP0IE_Msk             (0x1UL)        /*!< TAMP0IE (Bitfield-Mask: 0x01)                         */
/* =========================================================  TCECR  ========================================================= */
#define R_SYSTEM_TCECR_TCE2S_Pos                (2UL)          /*!< TCE2S (Bit 2)                                         */
#define R_SYSTEM_TCECR_TCE2S_Msk                (0x4UL)        /*!< TCE2S (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_TCECR_TCE1S_Pos                (1UL)          /*!< TCE1S (Bit 1)                                         */
#define R_SYSTEM_TCECR_TCE1S_Msk                (0x2UL)        /*!< TCE1S (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_TCECR_TCE0S_Pos                (0UL)          /*!< TCE0S (Bit 0)                                         */
#define R_SYSTEM_TCECR_TCE0S_Msk                (0x1UL)        /*!< TCE0S (Bitfield-Mask: 0x01)                           */
/* ========================================================  TAMPCR2  ======================================================== */
#define R_SYSTEM_TAMPCR2_ZHUKE2_Pos             (2UL)          /*!< ZHUKE2 (Bit 2)                                        */
#define R_SYSTEM_TAMPCR2_ZHUKE2_Msk             (0x4UL)        /*!< ZHUKE2 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPCR2_ZHUKE1_Pos             (1UL)          /*!< ZHUKE1 (Bit 1)                                        */
#define R_SYSTEM_TAMPCR2_ZHUKE1_Msk             (0x2UL)        /*!< ZHUKE1 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPCR2_ZHUKE0_Pos             (0UL)          /*!< ZHUKE0 (Bit 0)                                        */
#define R_SYSTEM_TAMPCR2_ZHUKE0_Msk             (0x1UL)        /*!< ZHUKE0 (Bitfield-Mask: 0x01)                          */
/* =======================================================  TAMPICR1  ======================================================== */
#define R_SYSTEM_TAMPICR1_CH2EN_Pos             (2UL)          /*!< CH2EN (Bit 2)                                         */
#define R_SYSTEM_TAMPICR1_CH2EN_Msk             (0x4UL)        /*!< CH2EN (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_TAMPICR1_CH1EN_Pos             (1UL)          /*!< CH1EN (Bit 1)                                         */
#define R_SYSTEM_TAMPICR1_CH1EN_Msk             (0x2UL)        /*!< CH1EN (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_TAMPICR1_CH0EN_Pos             (0UL)          /*!< CH0EN (Bit 0)                                         */
#define R_SYSTEM_TAMPICR1_CH0EN_Msk             (0x1UL)        /*!< CH0EN (Bitfield-Mask: 0x01)                           */
/* =======================================================  TAMPICR2  ======================================================== */
#define R_SYSTEM_TAMPICR2_CH2TRG_Pos            (6UL)          /*!< CH2TRG (Bit 6)                                        */
#define R_SYSTEM_TAMPICR2_CH2TRG_Msk            (0x40UL)       /*!< CH2TRG (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPICR2_CH1TRG_Pos            (5UL)          /*!< CH1TRG (Bit 5)                                        */
#define R_SYSTEM_TAMPICR2_CH1TRG_Msk            (0x20UL)       /*!< CH1TRG (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPICR2_CH0TRG_Pos            (4UL)          /*!< CH0TRG (Bit 4)                                        */
#define R_SYSTEM_TAMPICR2_CH0TRG_Msk            (0x10UL)       /*!< CH0TRG (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPICR2_CH2NFE_Pos            (2UL)          /*!< CH2NFE (Bit 2)                                        */
#define R_SYSTEM_TAMPICR2_CH2NFE_Msk            (0x4UL)        /*!< CH2NFE (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPICR2_CH1NFE_Pos            (1UL)          /*!< CH1NFE (Bit 1)                                        */
#define R_SYSTEM_TAMPICR2_CH1NFE_Msk            (0x2UL)        /*!< CH1NFE (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPICR2_CH0NFE_Pos            (0UL)          /*!< CH0NFE (Bit 0)                                        */
#define R_SYSTEM_TAMPICR2_CH0NFE_Msk            (0x1UL)        /*!< CH0NFE (Bitfield-Mask: 0x01)                          */
/* ========================================================  TAMPIMR  ======================================================== */
#define R_SYSTEM_TAMPIMR_CH2LVL_Pos             (2UL)          /*!< CH2LVL (Bit 2)                                        */
#define R_SYSTEM_TAMPIMR_CH2LVL_Msk             (0x4UL)        /*!< CH2LVL (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPIMR_CH1LVL_Pos             (1UL)          /*!< CH1LVL (Bit 1)                                        */
#define R_SYSTEM_TAMPIMR_CH1LVL_Msk             (0x2UL)        /*!< CH1LVL (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_TAMPIMR_CH0LVL_Pos             (0UL)          /*!< CH0LVL (Bit 0)                                        */
#define R_SYSTEM_TAMPIMR_CH0LVL_Msk             (0x1UL)        /*!< CH0LVL (Bitfield-Mask: 0x01)                          */
/* =======================================================  TAMPICR3  ======================================================== */
#define R_SYSTEM_TAMPICR3_NFCS_Pos              (0UL)          /*!< NFCS (Bit 0)                                          */
#define R_SYSTEM_TAMPICR3_NFCS_Msk              (0x7UL)        /*!< NFCS (Bitfield-Mask: 0x07)                            */
/* ==========================================================  BKR  ========================================================== */
/* =========================================================  VBSAR  ========================================================= */
#define R_SYSTEM_VBSAR_SATAMPICR3_Pos           (6UL)          /*!< SATAMPICR3 (Bit 6)                                    */
#define R_SYSTEM_VBSAR_SATAMPICR3_Msk           (0x40UL)       /*!< SATAMPICR3 (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_VBSAR_SATAMPCR2_Pos            (5UL)          /*!< SATAMPCR2 (Bit 5)                                     */
#define R_SYSTEM_VBSAR_SATAMPCR2_Msk            (0x20UL)       /*!< SATAMPCR2 (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_VBSAR_SATAMPD_Pos              (4UL)          /*!< SATAMPD (Bit 4)                                       */
#define R_SYSTEM_VBSAR_SATAMPD_Msk              (0x10UL)       /*!< SATAMPD (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_VBSAR_SAVBATT_Pos              (3UL)          /*!< SAVBATT (Bit 3)                                       */
#define R_SYSTEM_VBSAR_SAVBATT_Msk              (0x8UL)        /*!< SAVBATT (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_VBSAR_SATAMPI_Pos              (2UL)          /*!< SATAMPI (Bit 2)                                       */
#define R_SYSTEM_VBSAR_SATAMPI_Msk              (0x4UL)        /*!< SATAMPI (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_VBSAR_SABKRCR_Pos              (1UL)          /*!< SABKRCR (Bit 1)                                       */
#define R_SYSTEM_VBSAR_SABKRCR_Msk              (0x2UL)        /*!< SABKRCR (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_VBSAR_SAVBATTMCR_Pos           (0UL)          /*!< SAVBATTMCR (Bit 0)                                    */
#define R_SYSTEM_VBSAR_SAVBATTMCR_Msk           (0x1UL)        /*!< SAVBATTMCR (Bitfield-Mask: 0x01)                      */
/* ========================================================  BKRSABR  ======================================================== */
/* =======================================================  SCKDIVCR  ======================================================== */
#define R_SYSTEM_SCKDIVCR_MRPCK_Pos             (28UL)         /*!< MRPCK (Bit 28)                                        */
#define R_SYSTEM_SCKDIVCR_MRPCK_Msk             (0xf0000000UL) /*!< MRPCK (Bitfield-Mask: 0x0f)                           */
#define R_SYSTEM_SCKDIVCR_ICK_Pos               (24UL)         /*!< ICK (Bit 24)                                          */
#define R_SYSTEM_SCKDIVCR_ICK_Msk               (0xf000000UL)  /*!< ICK (Bitfield-Mask: 0x0f)                             */
#define R_SYSTEM_SCKDIVCR_PCKE_Pos              (20UL)         /*!< PCKE (Bit 20)                                         */
#define R_SYSTEM_SCKDIVCR_PCKE_Msk              (0xf00000UL)   /*!< PCKE (Bitfield-Mask: 0x0f)                            */
#define R_SYSTEM_SCKDIVCR_BCK_Pos               (16UL)         /*!< BCK (Bit 16)                                          */
#define R_SYSTEM_SCKDIVCR_BCK_Msk               (0xf0000UL)    /*!< BCK (Bitfield-Mask: 0x0f)                             */
#define R_SYSTEM_SCKDIVCR_PCKA_Pos              (12UL)         /*!< PCKA (Bit 12)                                         */
#define R_SYSTEM_SCKDIVCR_PCKA_Msk              (0xf000UL)     /*!< PCKA (Bitfield-Mask: 0x0f)                            */
#define R_SYSTEM_SCKDIVCR_PCKB_Pos              (8UL)          /*!< PCKB (Bit 8)                                          */
#define R_SYSTEM_SCKDIVCR_PCKB_Msk              (0xf00UL)      /*!< PCKB (Bitfield-Mask: 0x0f)                            */
#define R_SYSTEM_SCKDIVCR_PCKC_Pos              (4UL)          /*!< PCKC (Bit 4)                                          */
#define R_SYSTEM_SCKDIVCR_PCKC_Msk              (0xf0UL)       /*!< PCKC (Bitfield-Mask: 0x0f)                            */
#define R_SYSTEM_SCKDIVCR_PCKD_Pos              (0UL)          /*!< PCKD (Bit 0)                                          */
#define R_SYSTEM_SCKDIVCR_PCKD_Msk              (0xfUL)        /*!< PCKD (Bitfield-Mask: 0x0f)                            */
/* =======================================================  SCKDIVCR2  ======================================================= */
#define R_SYSTEM_SCKDIVCR2_MRICK_Pos            (12UL)         /*!< MRICK (Bit 12)                                        */
#define R_SYSTEM_SCKDIVCR2_MRICK_Msk            (0xf000UL)     /*!< MRICK (Bitfield-Mask: 0x0f)                           */
#define R_SYSTEM_SCKDIVCR2_CPUCK0_Pos           (0UL)          /*!< CPUCK0 (Bit 0)                                        */
#define R_SYSTEM_SCKDIVCR2_CPUCK0_Msk           (0xfUL)        /*!< CPUCK0 (Bitfield-Mask: 0x0f)                          */
/* ========================================================  SCKSCR  ========================================================= */
#define R_SYSTEM_SCKSCR_CKSEL_Pos               (0UL)          /*!< CKSEL (Bit 0)                                         */
#define R_SYSTEM_SCKSCR_CKSEL_Msk               (0x7UL)        /*!< CKSEL (Bitfield-Mask: 0x07)                           */
/* =========================================================  PLLCR  ========================================================= */
#define R_SYSTEM_PLLCR_PLLSTP_Pos               (0UL)          /*!< PLLSTP (Bit 0)                                        */
#define R_SYSTEM_PLLCR_PLLSTP_Msk               (0x1UL)        /*!< PLLSTP (Bitfield-Mask: 0x01)                          */
/* =========================================================  BCKCR  ========================================================= */
#define R_SYSTEM_BCKCR_EBCKASEL_Pos             (7UL)          /*!< EBCKASEL (Bit 7)                                      */
#define R_SYSTEM_BCKCR_EBCKASEL_Msk             (0x80UL)       /*!< EBCKASEL (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_BCKCR_BCLKDIV_Pos              (0UL)          /*!< BCLKDIV (Bit 0)                                       */
#define R_SYSTEM_BCKCR_BCLKDIV_Msk              (0x1UL)        /*!< BCLKDIV (Bitfield-Mask: 0x01)                         */
/* ========================================================  MOSCCR  ========================================================= */
#define R_SYSTEM_MOSCCR_MOSTP_Pos               (0UL)          /*!< MOSTP (Bit 0)                                         */
#define R_SYSTEM_MOSCCR_MOSTP_Msk               (0x1UL)        /*!< MOSTP (Bitfield-Mask: 0x01)                           */
/* ========================================================  HOCOCR  ========================================================= */
#define R_SYSTEM_HOCOCR_HCSTP_Pos               (0UL)          /*!< HCSTP (Bit 0)                                         */
#define R_SYSTEM_HOCOCR_HCSTP_Msk               (0x1UL)        /*!< HCSTP (Bitfield-Mask: 0x01)                           */
/* ========================================================  HOCOCR2  ======================================================== */
#define R_SYSTEM_HOCOCR2_HCFRQ0_Pos             (0UL)          /*!< HCFRQ0 (Bit 0)                                        */
#define R_SYSTEM_HOCOCR2_HCFRQ0_Msk             (0x7UL)        /*!< HCFRQ0 (Bitfield-Mask: 0x07)                          */
/* ========================================================  MOCOCR  ========================================================= */
#define R_SYSTEM_MOCOCR_MCSTP_Pos               (0UL)          /*!< MCSTP (Bit 0)                                         */
#define R_SYSTEM_MOCOCR_MCSTP_Msk               (0x1UL)        /*!< MCSTP (Bitfield-Mask: 0x01)                           */
/* ========================================================  FLLCR1  ========================================================= */
#define R_SYSTEM_FLLCR1_FLLEN_Pos               (0UL)          /*!< FLLEN (Bit 0)                                         */
#define R_SYSTEM_FLLCR1_FLLEN_Msk               (0x1UL)        /*!< FLLEN (Bitfield-Mask: 0x01)                           */
/* ========================================================  FLLCR2  ========================================================= */
#define R_SYSTEM_FLLCR2_FLLCNTL_Pos             (0UL)          /*!< FLLCNTL (Bit 0)                                       */
#define R_SYSTEM_FLLCR2_FLLCNTL_Msk             (0x7ffUL)      /*!< FLLCNTL (Bitfield-Mask: 0x7ff)                        */
/* =========================================================  OSCSF  ========================================================= */
#define R_SYSTEM_OSCSF_PLL2SF_Pos               (6UL)          /*!< PLL2SF (Bit 6)                                        */
#define R_SYSTEM_OSCSF_PLL2SF_Msk               (0x40UL)       /*!< PLL2SF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_OSCSF_PLLSF_Pos                (5UL)          /*!< PLLSF (Bit 5)                                         */
#define R_SYSTEM_OSCSF_PLLSF_Msk                (0x20UL)       /*!< PLLSF (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_OSCSF_MOSCSF_Pos               (3UL)          /*!< MOSCSF (Bit 3)                                        */
#define R_SYSTEM_OSCSF_MOSCSF_Msk               (0x8UL)        /*!< MOSCSF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_OSCSF_HOCOSF_Pos               (0UL)          /*!< HOCOSF (Bit 0)                                        */
#define R_SYSTEM_OSCSF_HOCOSF_Msk               (0x1UL)        /*!< HOCOSF (Bitfield-Mask: 0x01)                          */
/* =========================================================  CKOCR  ========================================================= */
#define R_SYSTEM_CKOCR_CKOEN_Pos                (7UL)          /*!< CKOEN (Bit 7)                                         */
#define R_SYSTEM_CKOCR_CKOEN_Msk                (0x80UL)       /*!< CKOEN (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_CKOCR_CKODIV_Pos               (4UL)          /*!< CKODIV (Bit 4)                                        */
#define R_SYSTEM_CKOCR_CKODIV_Msk               (0x70UL)       /*!< CKODIV (Bitfield-Mask: 0x07)                          */
#define R_SYSTEM_CKOCR_CKOSEL_Pos               (0UL)          /*!< CKOSEL (Bit 0)                                        */
#define R_SYSTEM_CKOCR_CKOSEL_Msk               (0xfUL)        /*!< CKOSEL (Bitfield-Mask: 0x0f)                          */
/* ========================================================  OSTDCR  ========================================================= */
#define R_SYSTEM_OSTDCR_OSTDE_Pos               (7UL)          /*!< OSTDE (Bit 7)                                         */
#define R_SYSTEM_OSTDCR_OSTDE_Msk               (0x80UL)       /*!< OSTDE (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_OSTDCR_OSTDIE_Pos              (0UL)          /*!< OSTDIE (Bit 0)                                        */
#define R_SYSTEM_OSTDCR_OSTDIE_Msk              (0x1UL)        /*!< OSTDIE (Bitfield-Mask: 0x01)                          */
/* ========================================================  OSTDSR  ========================================================= */
#define R_SYSTEM_OSTDSR_OSTDF_Pos               (0UL)          /*!< OSTDF (Bit 0)                                         */
#define R_SYSTEM_OSTDSR_OSTDF_Msk               (0x1UL)        /*!< OSTDF (Bitfield-Mask: 0x01)                           */
/* ========================================================  OSCMONR  ======================================================== */
#define R_SYSTEM_OSCMONR_LOCOMON_Pos            (2UL)          /*!< LOCOMON (Bit 2)                                       */
#define R_SYSTEM_OSCMONR_LOCOMON_Msk            (0x4UL)        /*!< LOCOMON (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_OSCMONR_MOCOMON_Pos            (1UL)          /*!< MOCOMON (Bit 1)                                       */
#define R_SYSTEM_OSCMONR_MOCOMON_Msk            (0x2UL)        /*!< MOCOMON (Bitfield-Mask: 0x01)                         */
/* ========================================================  PLL2CR  ========================================================= */
#define R_SYSTEM_PLL2CR_PLL2STP_Pos             (0UL)          /*!< PLL2STP (Bit 0)                                       */
#define R_SYSTEM_PLL2CR_PLL2STP_Msk             (0x1UL)        /*!< PLL2STP (Bitfield-Mask: 0x01)                         */
/* ========================================================  PLLCCR2  ======================================================== */
#define R_SYSTEM_PLLCCR2_PLODIVR_Pos            (8UL)          /*!< PLODIVR (Bit 8)                                       */
#define R_SYSTEM_PLLCCR2_PLODIVR_Msk            (0xf00UL)      /*!< PLODIVR (Bitfield-Mask: 0x0f)                         */
#define R_SYSTEM_PLLCCR2_PLODIVQ_Pos            (4UL)          /*!< PLODIVQ (Bit 4)                                       */
#define R_SYSTEM_PLLCCR2_PLODIVQ_Msk            (0xf0UL)       /*!< PLODIVQ (Bitfield-Mask: 0x0f)                         */
#define R_SYSTEM_PLLCCR2_PLODIVP_Pos            (0UL)          /*!< PLODIVP (Bit 0)                                       */
#define R_SYSTEM_PLLCCR2_PLODIVP_Msk            (0xfUL)        /*!< PLODIVP (Bitfield-Mask: 0x0f)                         */
/* =======================================================  PLL2CCR2  ======================================================== */
#define R_SYSTEM_PLL2CCR2_PL2ODIVR_Pos          (8UL)          /*!< PL2ODIVR (Bit 8)                                      */
#define R_SYSTEM_PLL2CCR2_PL2ODIVR_Msk          (0xf00UL)      /*!< PL2ODIVR (Bitfield-Mask: 0x0f)                        */
#define R_SYSTEM_PLL2CCR2_PL2ODIVQ_Pos          (4UL)          /*!< PL2ODIVQ (Bit 4)                                      */
#define R_SYSTEM_PLL2CCR2_PL2ODIVQ_Msk          (0xf0UL)       /*!< PL2ODIVQ (Bitfield-Mask: 0x0f)                        */
#define R_SYSTEM_PLL2CCR2_PL2ODIVP_Pos          (0UL)          /*!< PL2ODIVP (Bit 0)                                      */
#define R_SYSTEM_PLL2CCR2_PL2ODIVP_Msk          (0xfUL)        /*!< PL2ODIVP (Bitfield-Mask: 0x0f)                        */
/* ========================================================  EBCKOCR  ======================================================== */
#define R_SYSTEM_EBCKOCR_EBCKOEN_Pos            (0UL)          /*!< EBCKOEN (Bit 0)                                       */
#define R_SYSTEM_EBCKOCR_EBCKOEN_Msk            (0x1UL)        /*!< EBCKOEN (Bitfield-Mask: 0x01)                         */
/* ========================================================  SDCKOCR  ======================================================== */
#define R_SYSTEM_SDCKOCR_SDCKOEN_Pos            (0UL)          /*!< SDCKOEN (Bit 0)                                       */
#define R_SYSTEM_SDCKOCR_SDCKOEN_Msk            (0x1UL)        /*!< SDCKOEN (Bitfield-Mask: 0x01)                         */
/* ======================================================  SCICKDIVCR  ======================================================= */
#define R_SYSTEM_SCICKDIVCR_SCICKDIV_Pos        (0UL)          /*!< SCICKDIV (Bit 0)                                      */
#define R_SYSTEM_SCICKDIVCR_SCICKDIV_Msk        (0xfUL)        /*!< SCICKDIV (Bitfield-Mask: 0x0f)                        */
/* ========================================================  SCICKCR  ======================================================== */
#define R_SYSTEM_SCICKCR_SCICKSRDY_Pos          (7UL)          /*!< SCICKSRDY (Bit 7)                                     */
#define R_SYSTEM_SCICKCR_SCICKSRDY_Msk          (0x80UL)       /*!< SCICKSRDY (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_SCICKCR_SCICKSREQ_Pos          (6UL)          /*!< SCICKSREQ (Bit 6)                                     */
#define R_SYSTEM_SCICKCR_SCICKSREQ_Msk          (0x40UL)       /*!< SCICKSREQ (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_SCICKCR_SCICKSEL_Pos           (0UL)          /*!< SCICKSEL (Bit 0)                                      */
#define R_SYSTEM_SCICKCR_SCICKSEL_Msk           (0xfUL)        /*!< SCICKSEL (Bitfield-Mask: 0x0f)                        */
/* ======================================================  SPICKDIVCR  ======================================================= */
#define R_SYSTEM_SPICKDIVCR_SPICKDIV_Pos        (0UL)          /*!< SPICKDIV (Bit 0)                                      */
#define R_SYSTEM_SPICKDIVCR_SPICKDIV_Msk        (0xfUL)        /*!< SPICKDIV (Bitfield-Mask: 0x0f)                        */
/* ========================================================  SPICKCR  ======================================================== */
#define R_SYSTEM_SPICKCR_SPICKSRDY_Pos          (7UL)          /*!< SPICKSRDY (Bit 7)                                     */
#define R_SYSTEM_SPICKCR_SPICKSRDY_Msk          (0x80UL)       /*!< SPICKSRDY (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_SPICKCR_SPICKSREQ_Pos          (6UL)          /*!< SPICKSREQ (Bit 6)                                     */
#define R_SYSTEM_SPICKCR_SPICKSREQ_Msk          (0x40UL)       /*!< SPICKSREQ (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_SPICKCR_SPICKSEL_Pos           (0UL)          /*!< SPICKSEL (Bit 0)                                      */
#define R_SYSTEM_SPICKCR_SPICKSEL_Msk           (0xfUL)        /*!< SPICKSEL (Bitfield-Mask: 0x0f)                        */
/* ======================================================  ADCCKDIVCR  ======================================================= */
#define R_SYSTEM_ADCCKDIVCR_ADCCKDIV_Pos        (0UL)          /*!< ADCCKDIV (Bit 0)                                      */
#define R_SYSTEM_ADCCKDIVCR_ADCCKDIV_Msk        (0xfUL)        /*!< ADCCKDIV (Bitfield-Mask: 0x0f)                        */
/* ========================================================  ADCCKCR  ======================================================== */
#define R_SYSTEM_ADCCKCR_ADCCKSRDY_Pos          (7UL)          /*!< ADCCKSRDY (Bit 7)                                     */
#define R_SYSTEM_ADCCKCR_ADCCKSRDY_Msk          (0x80UL)       /*!< ADCCKSRDY (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_ADCCKCR_ADCCKSREQ_Pos          (6UL)          /*!< ADCCKSREQ (Bit 6)                                     */
#define R_SYSTEM_ADCCKCR_ADCCKSREQ_Msk          (0x40UL)       /*!< ADCCKSREQ (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_ADCCKCR_ADCCKSEL_Pos           (0UL)          /*!< ADCCKSEL (Bit 0)                                      */
#define R_SYSTEM_ADCCKCR_ADCCKSEL_Msk           (0xfUL)        /*!< ADCCKSEL (Bitfield-Mask: 0x0f)                        */
/* ======================================================  GPTCKDIVCR  ======================================================= */
#define R_SYSTEM_GPTCKDIVCR_GPTCKDIV_Pos        (0UL)          /*!< GPTCKDIV (Bit 0)                                      */
#define R_SYSTEM_GPTCKDIVCR_GPTCKDIV_Msk        (0xfUL)        /*!< GPTCKDIV (Bitfield-Mask: 0x0f)                        */
/* ========================================================  GPTCKCR  ======================================================== */
#define R_SYSTEM_GPTCKCR_GPTCKSRDY_Pos          (7UL)          /*!< GPTCKSRDY (Bit 7)                                     */
#define R_SYSTEM_GPTCKCR_GPTCKSRDY_Msk          (0x80UL)       /*!< GPTCKSRDY (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_GPTCKCR_GPTCKSREQ_Pos          (6UL)          /*!< GPTCKSREQ (Bit 6)                                     */
#define R_SYSTEM_GPTCKCR_GPTCKSREQ_Msk          (0x40UL)       /*!< GPTCKSREQ (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_GPTCKCR_GPTCKSEL_Pos           (0UL)          /*!< GPTCKSEL (Bit 0)                                      */
#define R_SYSTEM_GPTCKCR_GPTCKSEL_Msk           (0xfUL)        /*!< GPTCKSEL (Bitfield-Mask: 0x0f)                        */
/* =======================================================  MOCOUTCR  ======================================================== */
#define R_SYSTEM_MOCOUTCR_MOCOUTRM_Pos          (0UL)          /*!< MOCOUTRM (Bit 0)                                      */
#define R_SYSTEM_MOCOUTCR_MOCOUTRM_Msk          (0xffUL)       /*!< MOCOUTRM (Bitfield-Mask: 0xff)                        */
/* =======================================================  HOCOUTCR  ======================================================== */
#define R_SYSTEM_HOCOUTCR_HOCOUTRM_Pos          (0UL)          /*!< HOCOUTRM (Bit 0)                                      */
#define R_SYSTEM_HOCOUTCR_HOCOUTRM_Msk          (0xffUL)       /*!< HOCOUTRM (Bitfield-Mask: 0xff)                        */
/* ======================================================  USBCKDIVCR  ======================================================= */
#define R_SYSTEM_USBCKDIVCR_USBCKDIV_Pos        (0UL)          /*!< USBCKDIV (Bit 0)                                      */
#define R_SYSTEM_USBCKDIVCR_USBCKDIV_Msk        (0xfUL)        /*!< USBCKDIV (Bitfield-Mask: 0x0f)                        */
/* ======================================================  XSPICKDIVCR  ====================================================== */
#define R_SYSTEM_XSPICKDIVCR_XSPICKDIV_Pos      (0UL)          /*!< XSPICKDIV (Bit 0)                                     */
#define R_SYSTEM_XSPICKDIVCR_XSPICKDIV_Msk      (0xfUL)        /*!< XSPICKDIV (Bitfield-Mask: 0x0f)                       */
/* =====================================================  CANFDCKDIVCR  ====================================================== */
#define R_SYSTEM_CANFDCKDIVCR_CANFDCKDIV_Pos    (0UL)          /*!< CANFDCKDIV (Bit 0)                                    */
#define R_SYSTEM_CANFDCKDIVCR_CANFDCKDIV_Msk    (0xfUL)        /*!< CANFDCKDIV (Bitfield-Mask: 0x0f)                      */
/* =====================================================  USB60CKDIVCR  ====================================================== */
#define R_SYSTEM_USB60CKDIVCR_USB60CKDIV_Pos    (0UL)          /*!< USB60CKDIV (Bit 0)                                    */
#define R_SYSTEM_USB60CKDIVCR_USB60CKDIV_Msk    (0xfUL)        /*!< USB60CKDIV (Bitfield-Mask: 0x0f)                      */
/* ======================================================  I3CCKDIVCR  ======================================================= */
#define R_SYSTEM_I3CCKDIVCR_I3CCKDIV_Pos        (0UL)          /*!< I3CCKDIV (Bit 0)                                      */
#define R_SYSTEM_I3CCKDIVCR_I3CCKDIV_Msk        (0xfUL)        /*!< I3CCKDIV (Bitfield-Mask: 0x0f)                        */
/* ========================================================  USBCKCR  ======================================================== */
#define R_SYSTEM_USBCKCR_USBCKSRDY_Pos          (7UL)          /*!< USBCKSRDY (Bit 7)                                     */
#define R_SYSTEM_USBCKCR_USBCKSRDY_Msk          (0x80UL)       /*!< USBCKSRDY (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_USBCKCR_USBCKSREQ_Pos          (6UL)          /*!< USBCKSREQ (Bit 6)                                     */
#define R_SYSTEM_USBCKCR_USBCKSREQ_Msk          (0x40UL)       /*!< USBCKSREQ (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_USBCKCR_USBCKSEL_Pos           (0UL)          /*!< USBCKSEL (Bit 0)                                      */
#define R_SYSTEM_USBCKCR_USBCKSEL_Msk           (0xfUL)        /*!< USBCKSEL (Bitfield-Mask: 0x0f)                        */
/* =======================================================  XSPICKCR  ======================================================== */
#define R_SYSTEM_XSPICKCR_XSPICKSRDY_Pos        (7UL)          /*!< XSPICKSRDY (Bit 7)                                    */
#define R_SYSTEM_XSPICKCR_XSPICKSRDY_Msk        (0x80UL)       /*!< XSPICKSRDY (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_XSPICKCR_XSPICKSREQ_Pos        (6UL)          /*!< XSPICKSREQ (Bit 6)                                    */
#define R_SYSTEM_XSPICKCR_XSPICKSREQ_Msk        (0x40UL)       /*!< XSPICKSREQ (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_XSPICKCR_XSPICKSEL_Pos         (0UL)          /*!< XSPICKSEL (Bit 0)                                     */
#define R_SYSTEM_XSPICKCR_XSPICKSEL_Msk         (0xfUL)        /*!< XSPICKSEL (Bitfield-Mask: 0x0f)                       */
/* =======================================================  CANFDCKCR  ======================================================= */
#define R_SYSTEM_CANFDCKCR_CANFDCKSRDY_Pos      (7UL)          /*!< CANFDCKSRDY (Bit 7)                                   */
#define R_SYSTEM_CANFDCKCR_CANFDCKSRDY_Msk      (0x80UL)       /*!< CANFDCKSRDY (Bitfield-Mask: 0x01)                     */
#define R_SYSTEM_CANFDCKCR_CANFDCKSREQ_Pos      (6UL)          /*!< CANFDCKSREQ (Bit 6)                                   */
#define R_SYSTEM_CANFDCKCR_CANFDCKSREQ_Msk      (0x40UL)       /*!< CANFDCKSREQ (Bitfield-Mask: 0x01)                     */
#define R_SYSTEM_CANFDCKCR_CANFDCKSEL_Pos       (0UL)          /*!< CANFDCKSEL (Bit 0)                                    */
#define R_SYSTEM_CANFDCKCR_CANFDCKSEL_Msk       (0xfUL)        /*!< CANFDCKSEL (Bitfield-Mask: 0x0f)                      */
/* =======================================================  USB60CKCR  ======================================================= */
#define R_SYSTEM_USB60CKCR_USB60CKSRDY_Pos      (7UL)          /*!< USB60CKSRDY (Bit 7)                                   */
#define R_SYSTEM_USB60CKCR_USB60CKSRDY_Msk      (0x80UL)       /*!< USB60CKSRDY (Bitfield-Mask: 0x01)                     */
#define R_SYSTEM_USB60CKCR_USB60CKSREQ_Pos      (6UL)          /*!< USB60CKSREQ (Bit 6)                                   */
#define R_SYSTEM_USB60CKCR_USB60CKSREQ_Msk      (0x40UL)       /*!< USB60CKSREQ (Bitfield-Mask: 0x01)                     */
#define R_SYSTEM_USB60CKCR_USB60CKSEL_Pos       (0UL)          /*!< USB60CKSEL (Bit 0)                                    */
#define R_SYSTEM_USB60CKCR_USB60CKSEL_Msk       (0xfUL)        /*!< USB60CKSEL (Bitfield-Mask: 0x0f)                      */
/* ========================================================  I3CCKCR  ======================================================== */
#define R_SYSTEM_I3CCKCR_I3CCKSRDY_Pos          (7UL)          /*!< I3CCKSRDY (Bit 7)                                     */
#define R_SYSTEM_I3CCKCR_I3CCKSRDY_Msk          (0x80UL)       /*!< I3CCKSRDY (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_I3CCKCR_I3CCKSREQ_Pos          (6UL)          /*!< I3CCKSREQ (Bit 6)                                     */
#define R_SYSTEM_I3CCKCR_I3CCKSREQ_Msk          (0x40UL)       /*!< I3CCKSREQ (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_I3CCKCR_I3CCKSEL_Pos           (0UL)          /*!< I3CCKSEL (Bit 0)                                      */
#define R_SYSTEM_I3CCKCR_I3CCKSEL_Msk           (0xfUL)        /*!< I3CCKSEL (Bitfield-Mask: 0x0f)                        */
/* ========================================================  MOSCSCR  ======================================================== */
#define R_SYSTEM_MOSCSCR_MOSCSOKP_Pos           (0UL)          /*!< MOSCSOKP (Bit 0)                                      */
#define R_SYSTEM_MOSCSCR_MOSCSOKP_Msk           (0x1UL)        /*!< MOSCSOKP (Bitfield-Mask: 0x01)                        */
/* ========================================================  HOCOSCR  ======================================================== */
#define R_SYSTEM_HOCOSCR_HOCOSOKP_Pos           (0UL)          /*!< HOCOSOKP (Bit 0)                                      */
#define R_SYSTEM_HOCOSCR_HOCOSOKP_Msk           (0x1UL)        /*!< HOCOSOKP (Bitfield-Mask: 0x01)                        */
/* ========================================================  MOCOSCR  ======================================================== */
#define R_SYSTEM_MOCOSCR_MOCOSOKP_Pos           (0UL)          /*!< MOCOSOKP (Bit 0)                                      */
#define R_SYSTEM_MOCOSCR_MOCOSOKP_Msk           (0x1UL)        /*!< MOCOSOKP (Bitfield-Mask: 0x01)                        */
/* =======================================================  MOSCWTCR  ======================================================== */
#define R_SYSTEM_MOSCWTCR_MSTS_Pos              (0UL)          /*!< MSTS (Bit 0)                                          */
#define R_SYSTEM_MOSCWTCR_MSTS_Msk              (0xfUL)        /*!< MSTS (Bitfield-Mask: 0x0f)                            */
/* ========================================================  PLLCCR  ========================================================= */
#define R_SYSTEM_PLLCCR_PLLMUL_Pos              (8UL)          /*!< PLLMUL (Bit 8)                                        */
#define R_SYSTEM_PLLCCR_PLLMUL_Msk              (0x1ff00UL)    /*!< PLLMUL (Bitfield-Mask: 0x1ff)                         */
#define R_SYSTEM_PLLCCR_PLLMULNF_Pos            (6UL)          /*!< PLLMULNF (Bit 6)                                      */
#define R_SYSTEM_PLLCCR_PLLMULNF_Msk            (0xc0UL)       /*!< PLLMULNF (Bitfield-Mask: 0x03)                        */
#define R_SYSTEM_PLLCCR_PLSRCSEL_Pos            (4UL)          /*!< PLSRCSEL (Bit 4)                                      */
#define R_SYSTEM_PLLCCR_PLSRCSEL_Msk            (0x10UL)       /*!< PLSRCSEL (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_PLLCCR_PLIDIV_Pos              (0UL)          /*!< PLIDIV (Bit 0)                                        */
#define R_SYSTEM_PLLCCR_PLIDIV_Msk              (0x3UL)        /*!< PLIDIV (Bitfield-Mask: 0x03)                          */
/* ========================================================  PLL2CCR  ======================================================== */
#define R_SYSTEM_PLL2CCR_PLL2MUL_Pos            (8UL)          /*!< PLL2MUL (Bit 8)                                       */
#define R_SYSTEM_PLL2CCR_PLL2MUL_Msk            (0x1ff00UL)    /*!< PLL2MUL (Bitfield-Mask: 0x1ff)                        */
#define R_SYSTEM_PLL2CCR_PLL2MULNF_Pos          (6UL)          /*!< PLL2MULNF (Bit 6)                                     */
#define R_SYSTEM_PLL2CCR_PLL2MULNF_Msk          (0xc0UL)       /*!< PLL2MULNF (Bitfield-Mask: 0x03)                       */
#define R_SYSTEM_PLL2CCR_PL2SRCSEL_Pos          (4UL)          /*!< PL2SRCSEL (Bit 4)                                     */
#define R_SYSTEM_PLL2CCR_PL2SRCSEL_Msk          (0x10UL)       /*!< PL2SRCSEL (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_PLL2CCR_PL2IDIV_Pos            (0UL)          /*!< PL2IDIV (Bit 0)                                       */
#define R_SYSTEM_PLL2CCR_PL2IDIV_Msk            (0x3UL)        /*!< PL2IDIV (Bitfield-Mask: 0x03)                         */
/* ========================================================  SYRACCR  ======================================================== */
#define R_SYSTEM_SYRACCR_BUSY_Pos               (0UL)          /*!< BUSY (Bit 0)                                          */
#define R_SYSTEM_SYRACCR_BUSY_Msk               (0x1UL)        /*!< BUSY (Bitfield-Mask: 0x01)                            */
/* =======================================================  BCKADIVCR  ======================================================= */
#define R_SYSTEM_BCKADIVCR_BCKACKDIV_Pos        (0UL)          /*!< BCKACKDIV (Bit 0)                                     */
#define R_SYSTEM_BCKADIVCR_BCKACKDIV_Msk        (0xfUL)        /*!< BCKACKDIV (Bitfield-Mask: 0x0f)                       */
/* ======================================================  ESWCKDIVCR  ======================================================= */
#define R_SYSTEM_ESWCKDIVCR_ESWCKDIV_Pos        (0UL)          /*!< ESWCKDIV (Bit 0)                                      */
#define R_SYSTEM_ESWCKDIVCR_ESWCKDIV_Msk        (0xfUL)        /*!< ESWCKDIV (Bitfield-Mask: 0x0f)                        */
/* ======================================================  ESWPCKDIVCR  ====================================================== */
#define R_SYSTEM_ESWPCKDIVCR_ESWPCKDIV_Pos      (0UL)          /*!< ESWPCKDIV (Bit 0)                                     */
#define R_SYSTEM_ESWPCKDIVCR_ESWPCKDIV_Msk      (0xfUL)        /*!< ESWPCKDIV (Bitfield-Mask: 0x0f)                       */
/* ======================================================  ESCCKDIVCR  ======================================================= */
#define R_SYSTEM_ESCCKDIVCR_ESCCKDIV_Pos        (0UL)          /*!< ESCCKDIV (Bit 0)                                      */
#define R_SYSTEM_ESCCKDIVCR_ESCCKDIV_Msk        (0xfUL)        /*!< ESCCKDIV (Bitfield-Mask: 0x0f)                        */
/* ======================================================  ETHPCKDIVCR  ====================================================== */
#define R_SYSTEM_ETHPCKDIVCR_ETHPCKDIV_Pos      (0UL)          /*!< ETHPCKDIV (Bit 0)                                     */
#define R_SYSTEM_ETHPCKDIVCR_ETHPCKDIV_Msk      (0xfUL)        /*!< ETHPCKDIV (Bitfield-Mask: 0x0f)                       */
/* =====================================================  DSMIFCKDIVCR  ====================================================== */
#define R_SYSTEM_DSMIFCKDIVCR_DSMIFCKDIV_Pos    (0UL)          /*!< DSMIFCKDIV (Bit 0)                                    */
#define R_SYSTEM_DSMIFCKDIVCR_DSMIFCKDIV_Msk    (0xfUL)        /*!< DSMIFCKDIV (Bitfield-Mask: 0x0f)                      */
/* ========================================================  BCKACR  ========================================================= */
#define R_SYSTEM_BCKACR_BCKACKSRDY_Pos          (7UL)          /*!< BCKACKSRDY (Bit 7)                                    */
#define R_SYSTEM_BCKACR_BCKACKSRDY_Msk          (0x80UL)       /*!< BCKACKSRDY (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_BCKACR_BCKACKSREQ_Pos          (6UL)          /*!< BCKACKSREQ (Bit 6)                                    */
#define R_SYSTEM_BCKACR_BCKACKSREQ_Msk          (0x40UL)       /*!< BCKACKSREQ (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_BCKACR_BCKACKSEL_Pos           (0UL)          /*!< BCKACKSEL (Bit 0)                                     */
#define R_SYSTEM_BCKACR_BCKACKSEL_Msk           (0xfUL)        /*!< BCKACKSEL (Bitfield-Mask: 0x0f)                       */
/* ========================================================  ESWCKCR  ======================================================== */
#define R_SYSTEM_ESWCKCR_ESWCKSRDY_Pos          (7UL)          /*!< ESWCKSRDY (Bit 7)                                     */
#define R_SYSTEM_ESWCKCR_ESWCKSRDY_Msk          (0x80UL)       /*!< ESWCKSRDY (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_ESWCKCR_ESWCKSREQ_Pos          (6UL)          /*!< ESWCKSREQ (Bit 6)                                     */
#define R_SYSTEM_ESWCKCR_ESWCKSREQ_Msk          (0x40UL)       /*!< ESWCKSREQ (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_ESWCKCR_ESWCKSEL_Pos           (0UL)          /*!< ESWCKSEL (Bit 0)                                      */
#define R_SYSTEM_ESWCKCR_ESWCKSEL_Msk           (0xfUL)        /*!< ESWCKSEL (Bitfield-Mask: 0x0f)                        */
/* =======================================================  ESWPCKCR  ======================================================== */
#define R_SYSTEM_ESWPCKCR_ESWPCKSRDY_Pos        (7UL)          /*!< ESWPCKSRDY (Bit 7)                                    */
#define R_SYSTEM_ESWPCKCR_ESWPCKSRDY_Msk        (0x80UL)       /*!< ESWPCKSRDY (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_ESWPCKCR_ESWPCKSREQ_Pos        (6UL)          /*!< ESWPCKSREQ (Bit 6)                                    */
#define R_SYSTEM_ESWPCKCR_ESWPCKSREQ_Msk        (0x40UL)       /*!< ESWPCKSREQ (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_ESWPCKCR_ESWPCKSEL_Pos         (0UL)          /*!< ESWPCKSEL (Bit 0)                                     */
#define R_SYSTEM_ESWPCKCR_ESWPCKSEL_Msk         (0xfUL)        /*!< ESWPCKSEL (Bitfield-Mask: 0x0f)                       */
/* ========================================================  ESCCKCR  ======================================================== */
#define R_SYSTEM_ESCCKCR_ESCCKSRDY_Pos          (7UL)          /*!< ESCCKSRDY (Bit 7)                                     */
#define R_SYSTEM_ESCCKCR_ESCCKSRDY_Msk          (0x80UL)       /*!< ESCCKSRDY (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_ESCCKCR_ESCCKSREQ_Pos          (6UL)          /*!< ESCCKSREQ (Bit 6)                                     */
#define R_SYSTEM_ESCCKCR_ESCCKSREQ_Msk          (0x40UL)       /*!< ESCCKSREQ (Bitfield-Mask: 0x01)                       */
#define R_SYSTEM_ESCCKCR_ESCCKSEL_Pos           (0UL)          /*!< ESCCKSEL (Bit 0)                                      */
#define R_SYSTEM_ESCCKCR_ESCCKSEL_Msk           (0xfUL)        /*!< ESCCKSEL (Bitfield-Mask: 0x0f)                        */
/* =======================================================  ETHPCKCR  ======================================================== */
#define R_SYSTEM_ETHPCKCR_ETHPCKSRDY_Pos        (7UL)          /*!< ETHPCKSRDY (Bit 7)                                    */
#define R_SYSTEM_ETHPCKCR_ETHPCKSRDY_Msk        (0x80UL)       /*!< ETHPCKSRDY (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_ETHPCKCR_ETHPCKSREQ_Pos        (6UL)          /*!< ETHPCKSREQ (Bit 6)                                    */
#define R_SYSTEM_ETHPCKCR_ETHPCKSREQ_Msk        (0x40UL)       /*!< ETHPCKSREQ (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_ETHPCKCR_ETHPCKSEL_Pos         (0UL)          /*!< ETHPCKSEL (Bit 0)                                     */
#define R_SYSTEM_ETHPCKCR_ETHPCKSEL_Msk         (0xfUL)        /*!< ETHPCKSEL (Bitfield-Mask: 0x0f)                       */
/* =======================================================  DSMIFCKCR  ======================================================= */
#define R_SYSTEM_DSMIFCKCR_DSMIFCKSRDY_Pos      (7UL)          /*!< DSMIFCKSRDY (Bit 7)                                   */
#define R_SYSTEM_DSMIFCKCR_DSMIFCKSRDY_Msk      (0x80UL)       /*!< DSMIFCKSRDY (Bitfield-Mask: 0x01)                     */
#define R_SYSTEM_DSMIFCKCR_DSMIFCKSREQ_Pos      (6UL)          /*!< DSMIFCKSREQ (Bit 6)                                   */
#define R_SYSTEM_DSMIFCKCR_DSMIFCKSREQ_Msk      (0x40UL)       /*!< DSMIFCKSREQ (Bitfield-Mask: 0x01)                     */
#define R_SYSTEM_DSMIFCKCR_DSMIFCKSEL_Pos       (0UL)          /*!< DSMIFCKSEL (Bit 0)                                    */
#define R_SYSTEM_DSMIFCKCR_DSMIFCKSEL_Msk       (0xfUL)        /*!< DSMIFCKSEL (Bitfield-Mask: 0x0f)                      */
/* ========================================================  CGFSAR  ========================================================= */
#define R_SYSTEM_CGFSAR_NONSEC29_Pos            (29UL)         /*!< NONSEC29 (Bit 29)                                     */
#define R_SYSTEM_CGFSAR_NONSEC29_Msk            (0x20000000UL) /*!< NONSEC29 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC28_Pos            (28UL)         /*!< NONSEC28 (Bit 28)                                     */
#define R_SYSTEM_CGFSAR_NONSEC28_Msk            (0x10000000UL) /*!< NONSEC28 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC27_Pos            (27UL)         /*!< NONSEC27 (Bit 27)                                     */
#define R_SYSTEM_CGFSAR_NONSEC27_Msk            (0x8000000UL)  /*!< NONSEC27 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC25_Pos            (25UL)         /*!< NONSEC25 (Bit 25)                                     */
#define R_SYSTEM_CGFSAR_NONSEC25_Msk            (0x2000000UL)  /*!< NONSEC25 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC24_Pos            (24UL)         /*!< NONSEC24 (Bit 24)                                     */
#define R_SYSTEM_CGFSAR_NONSEC24_Msk            (0x1000000UL)  /*!< NONSEC24 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC22_Pos            (22UL)         /*!< NONSEC22 (Bit 22)                                     */
#define R_SYSTEM_CGFSAR_NONSEC22_Msk            (0x400000UL)   /*!< NONSEC22 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC21_Pos            (21UL)         /*!< NONSEC21 (Bit 21)                                     */
#define R_SYSTEM_CGFSAR_NONSEC21_Msk            (0x200000UL)   /*!< NONSEC21 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC20_Pos            (20UL)         /*!< NONSEC20 (Bit 20)                                     */
#define R_SYSTEM_CGFSAR_NONSEC20_Msk            (0x100000UL)   /*!< NONSEC20 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC19_Pos            (19UL)         /*!< NONSEC19 (Bit 19)                                     */
#define R_SYSTEM_CGFSAR_NONSEC19_Msk            (0x80000UL)    /*!< NONSEC19 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC18_Pos            (18UL)         /*!< NONSEC18 (Bit 18)                                     */
#define R_SYSTEM_CGFSAR_NONSEC18_Msk            (0x40000UL)    /*!< NONSEC18 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC17_Pos            (17UL)         /*!< NONSEC17 (Bit 17)                                     */
#define R_SYSTEM_CGFSAR_NONSEC17_Msk            (0x20000UL)    /*!< NONSEC17 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC16_Pos            (16UL)         /*!< NONSEC16 (Bit 16)                                     */
#define R_SYSTEM_CGFSAR_NONSEC16_Msk            (0x10000UL)    /*!< NONSEC16 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC14_Pos            (14UL)         /*!< NONSEC14 (Bit 14)                                     */
#define R_SYSTEM_CGFSAR_NONSEC14_Msk            (0x4000UL)     /*!< NONSEC14 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC13_Pos            (13UL)         /*!< NONSEC13 (Bit 13)                                     */
#define R_SYSTEM_CGFSAR_NONSEC13_Msk            (0x2000UL)     /*!< NONSEC13 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC12_Pos            (12UL)         /*!< NONSEC12 (Bit 12)                                     */
#define R_SYSTEM_CGFSAR_NONSEC12_Msk            (0x1000UL)     /*!< NONSEC12 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC11_Pos            (11UL)         /*!< NONSEC11 (Bit 11)                                     */
#define R_SYSTEM_CGFSAR_NONSEC11_Msk            (0x800UL)      /*!< NONSEC11 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC10_Pos            (10UL)         /*!< NONSEC10 (Bit 10)                                     */
#define R_SYSTEM_CGFSAR_NONSEC10_Msk            (0x400UL)      /*!< NONSEC10 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC09_Pos            (9UL)          /*!< NONSEC09 (Bit 9)                                      */
#define R_SYSTEM_CGFSAR_NONSEC09_Msk            (0x200UL)      /*!< NONSEC09 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC08_Pos            (8UL)          /*!< NONSEC08 (Bit 8)                                      */
#define R_SYSTEM_CGFSAR_NONSEC08_Msk            (0x100UL)      /*!< NONSEC08 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC07_Pos            (7UL)          /*!< NONSEC07 (Bit 7)                                      */
#define R_SYSTEM_CGFSAR_NONSEC07_Msk            (0x80UL)       /*!< NONSEC07 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC06_Pos            (6UL)          /*!< NONSEC06 (Bit 6)                                      */
#define R_SYSTEM_CGFSAR_NONSEC06_Msk            (0x40UL)       /*!< NONSEC06 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC05_Pos            (5UL)          /*!< NONSEC05 (Bit 5)                                      */
#define R_SYSTEM_CGFSAR_NONSEC05_Msk            (0x20UL)       /*!< NONSEC05 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC04_Pos            (4UL)          /*!< NONSEC04 (Bit 4)                                      */
#define R_SYSTEM_CGFSAR_NONSEC04_Msk            (0x10UL)       /*!< NONSEC04 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC03_Pos            (3UL)          /*!< NONSEC03 (Bit 3)                                      */
#define R_SYSTEM_CGFSAR_NONSEC03_Msk            (0x8UL)        /*!< NONSEC03 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC02_Pos            (2UL)          /*!< NONSEC02 (Bit 2)                                      */
#define R_SYSTEM_CGFSAR_NONSEC02_Msk            (0x4UL)        /*!< NONSEC02 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_CGFSAR_NONSEC00_Pos            (0UL)          /*!< NONSEC00 (Bit 0)                                      */
#define R_SYSTEM_CGFSAR_NONSEC00_Msk            (0x1UL)        /*!< NONSEC00 (Bitfield-Mask: 0x01)                        */
/* ========================================================  LOCOCR  ========================================================= */
#define R_SYSTEM_LOCOCR_LCSTP_Pos               (0UL)          /*!< LCSTP (Bit 0)                                         */
#define R_SYSTEM_LOCOCR_LCSTP_Msk               (0x1UL)        /*!< LCSTP (Bitfield-Mask: 0x01)                           */
/* =======================================================  LOCOUTCR  ======================================================== */
#define R_SYSTEM_LOCOUTCR_LOCOUTRM_Pos          (0UL)          /*!< LOCOUTRM (Bit 0)                                      */
#define R_SYSTEM_LOCOUTCR_LOCOUTRM_Msk          (0xffUL)       /*!< LOCOUTRM (Bitfield-Mask: 0xff)                        */
/* =========================================================  MOMCR  ========================================================= */
#define R_SYSTEM_MOMCR_MOSEL_Pos                (6UL)          /*!< MOSEL (Bit 6)                                         */
#define R_SYSTEM_MOMCR_MOSEL_Msk                (0x40UL)       /*!< MOSEL (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_MOMCR_MODRV0_Pos               (1UL)          /*!< MODRV0 (Bit 1)                                        */
#define R_SYSTEM_MOMCR_MODRV0_Msk               (0xeUL)        /*!< MODRV0 (Bitfield-Mask: 0x07)                          */
/* ========================================================  SOSCCR  ========================================================= */
#define R_SYSTEM_SOSCCR_SOSTP_Pos               (0UL)          /*!< SOSTP (Bit 0)                                         */
#define R_SYSTEM_SOSCCR_SOSTP_Msk               (0x1UL)        /*!< SOSTP (Bitfield-Mask: 0x01)                           */
/* =========================================================  SOMCR  ========================================================= */
#define R_SYSTEM_SOMCR_SOSEL_Pos                (6UL)          /*!< SOSEL (Bit 6)                                         */
#define R_SYSTEM_SOMCR_SOSEL_Msk                (0x40UL)       /*!< SOSEL (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_SOMCR_SODRV_Pos                (0UL)          /*!< SODRV (Bit 0)                                         */
#define R_SYSTEM_SOMCR_SODRV_Msk                (0x3UL)        /*!< SODRV (Bitfield-Mask: 0x03)                           */
/* ========================================================  SOSTDCR  ======================================================== */
#define R_SYSTEM_SOSTDCR_SOSTDE_Pos             (7UL)          /*!< SOSTDE (Bit 7)                                        */
#define R_SYSTEM_SOSTDCR_SOSTDE_Msk             (0x80UL)       /*!< SOSTDE (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_SOSTDCR_SOSTDIE_Pos            (0UL)          /*!< SOSTDIE (Bit 0)                                       */
#define R_SYSTEM_SOSTDCR_SOSTDIE_Msk            (0x1UL)        /*!< SOSTDIE (Bitfield-Mask: 0x01)                         */
/* ========================================================  SOSTDSR  ======================================================== */
#define R_SYSTEM_SOSTDSR_SOSTDF_Pos             (0UL)          /*!< SOSTDF (Bit 0)                                        */
#define R_SYSTEM_SOSTDSR_SOSTDF_Msk             (0x1UL)        /*!< SOSTDF (Bitfield-Mask: 0x01)                          */
/* ========================================================  LPMSAR  ========================================================= */
#define R_SYSTEM_LPMSAR_NONSEC21_Pos            (21UL)         /*!< NONSEC21 (Bit 21)                                     */
#define R_SYSTEM_LPMSAR_NONSEC21_Msk            (0x200000UL)   /*!< NONSEC21 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_LPMSAR_NONSEC19_Pos            (19UL)         /*!< NONSEC19 (Bit 19)                                     */
#define R_SYSTEM_LPMSAR_NONSEC19_Msk            (0x80000UL)    /*!< NONSEC19 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_LPMSAR_NONSEC18_Pos            (18UL)         /*!< NONSEC18 (Bit 18)                                     */
#define R_SYSTEM_LPMSAR_NONSEC18_Msk            (0x40000UL)    /*!< NONSEC18 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_LPMSAR_NONSEC17_Pos            (17UL)         /*!< NONSEC17 (Bit 17)                                     */
#define R_SYSTEM_LPMSAR_NONSEC17_Msk            (0x20000UL)    /*!< NONSEC17 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_LPMSAR_NONSEC16_Pos            (16UL)         /*!< NONSEC16 (Bit 16)                                     */
#define R_SYSTEM_LPMSAR_NONSEC16_Msk            (0x10000UL)    /*!< NONSEC16 (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_LPMSAR_NONSEC8_Pos             (8UL)          /*!< NONSEC8 (Bit 8)                                       */
#define R_SYSTEM_LPMSAR_NONSEC8_Msk             (0x100UL)      /*!< NONSEC8 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_LPMSAR_NONSEC4_Pos             (4UL)          /*!< NONSEC4 (Bit 4)                                       */
#define R_SYSTEM_LPMSAR_NONSEC4_Msk             (0x10UL)       /*!< NONSEC4 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_LPMSAR_NONSEC2_Pos             (2UL)          /*!< NONSEC2 (Bit 2)                                       */
#define R_SYSTEM_LPMSAR_NONSEC2_Msk             (0x4UL)        /*!< NONSEC2 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_LPMSAR_NONSEC1_Pos             (1UL)          /*!< NONSEC1 (Bit 1)                                       */
#define R_SYSTEM_LPMSAR_NONSEC1_Msk             (0x2UL)        /*!< NONSEC1 (Bitfield-Mask: 0x01)                         */
/* ========================================================  PGCSAR  ========================================================= */
#define R_SYSTEM_PGCSAR_NONSEC6_Pos             (6UL)          /*!< NONSEC6 (Bit 6)                                       */
#define R_SYSTEM_PGCSAR_NONSEC6_Msk             (0x40UL)       /*!< NONSEC6 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_PGCSAR_NONSEC5_Pos             (5UL)          /*!< NONSEC5 (Bit 5)                                       */
#define R_SYSTEM_PGCSAR_NONSEC5_Msk             (0x20UL)       /*!< NONSEC5 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_PGCSAR_NONSEC3_Pos             (3UL)          /*!< NONSEC3 (Bit 3)                                       */
#define R_SYSTEM_PGCSAR_NONSEC3_Msk             (0x8UL)        /*!< NONSEC3 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_PGCSAR_NONSEC0_Pos             (0UL)          /*!< NONSEC0 (Bit 0)                                       */
#define R_SYSTEM_PGCSAR_NONSEC0_Msk             (0x1UL)        /*!< NONSEC0 (Bitfield-Mask: 0x01)                         */
/* ========================================================  DPFSAR  ========================================================= */
#define R_SYSTEM_DPFSAR_DPFSA31_Pos             (31UL)         /*!< DPFSA31 (Bit 31)                                      */
#define R_SYSTEM_DPFSAR_DPFSA31_Msk             (0x80000000UL) /*!< DPFSA31 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA30_Pos             (30UL)         /*!< DPFSA30 (Bit 30)                                      */
#define R_SYSTEM_DPFSAR_DPFSA30_Msk             (0x40000000UL) /*!< DPFSA30 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA29_Pos             (29UL)         /*!< DPFSA29 (Bit 29)                                      */
#define R_SYSTEM_DPFSAR_DPFSA29_Msk             (0x20000000UL) /*!< DPFSA29 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA25_Pos             (25UL)         /*!< DPFSA25 (Bit 25)                                      */
#define R_SYSTEM_DPFSAR_DPFSA25_Msk             (0x2000000UL)  /*!< DPFSA25 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA24_Pos             (24UL)         /*!< DPFSA24 (Bit 24)                                      */
#define R_SYSTEM_DPFSAR_DPFSA24_Msk             (0x1000000UL)  /*!< DPFSA24 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA20_Pos             (20UL)         /*!< DPFSA20 (Bit 20)                                      */
#define R_SYSTEM_DPFSAR_DPFSA20_Msk             (0x100000UL)   /*!< DPFSA20 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA19_Pos             (19UL)         /*!< DPFSA19 (Bit 19)                                      */
#define R_SYSTEM_DPFSAR_DPFSA19_Msk             (0x80000UL)    /*!< DPFSA19 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA18_Pos             (18UL)         /*!< DPFSA18 (Bit 18)                                      */
#define R_SYSTEM_DPFSAR_DPFSA18_Msk             (0x40000UL)    /*!< DPFSA18 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA17_Pos             (17UL)         /*!< DPFSA17 (Bit 17)                                      */
#define R_SYSTEM_DPFSAR_DPFSA17_Msk             (0x20000UL)    /*!< DPFSA17 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA16_Pos             (16UL)         /*!< DPFSA16 (Bit 16)                                      */
#define R_SYSTEM_DPFSAR_DPFSA16_Msk             (0x10000UL)    /*!< DPFSA16 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA15_Pos             (15UL)         /*!< DPFSA15 (Bit 15)                                      */
#define R_SYSTEM_DPFSAR_DPFSA15_Msk             (0x8000UL)     /*!< DPFSA15 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA14_Pos             (14UL)         /*!< DPFSA14 (Bit 14)                                      */
#define R_SYSTEM_DPFSAR_DPFSA14_Msk             (0x4000UL)     /*!< DPFSA14 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA13_Pos             (13UL)         /*!< DPFSA13 (Bit 13)                                      */
#define R_SYSTEM_DPFSAR_DPFSA13_Msk             (0x2000UL)     /*!< DPFSA13 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA12_Pos             (12UL)         /*!< DPFSA12 (Bit 12)                                      */
#define R_SYSTEM_DPFSAR_DPFSA12_Msk             (0x1000UL)     /*!< DPFSA12 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA11_Pos             (11UL)         /*!< DPFSA11 (Bit 11)                                      */
#define R_SYSTEM_DPFSAR_DPFSA11_Msk             (0x800UL)      /*!< DPFSA11 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA10_Pos             (10UL)         /*!< DPFSA10 (Bit 10)                                      */
#define R_SYSTEM_DPFSAR_DPFSA10_Msk             (0x400UL)      /*!< DPFSA10 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR_DPFSA9_Pos              (9UL)          /*!< DPFSA9 (Bit 9)                                        */
#define R_SYSTEM_DPFSAR_DPFSA9_Msk              (0x200UL)      /*!< DPFSA9 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR_DPFSA8_Pos              (8UL)          /*!< DPFSA8 (Bit 8)                                        */
#define R_SYSTEM_DPFSAR_DPFSA8_Msk              (0x100UL)      /*!< DPFSA8 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR_DPFSA7_Pos              (7UL)          /*!< DPFSA7 (Bit 7)                                        */
#define R_SYSTEM_DPFSAR_DPFSA7_Msk              (0x80UL)       /*!< DPFSA7 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR_DPFSA6_Pos              (6UL)          /*!< DPFSA6 (Bit 6)                                        */
#define R_SYSTEM_DPFSAR_DPFSA6_Msk              (0x40UL)       /*!< DPFSA6 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR_DPFSA5_Pos              (5UL)          /*!< DPFSA5 (Bit 5)                                        */
#define R_SYSTEM_DPFSAR_DPFSA5_Msk              (0x20UL)       /*!< DPFSA5 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR_DPFSA4_Pos              (4UL)          /*!< DPFSA4 (Bit 4)                                        */
#define R_SYSTEM_DPFSAR_DPFSA4_Msk              (0x10UL)       /*!< DPFSA4 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR_DPFSA3_Pos              (3UL)          /*!< DPFSA3 (Bit 3)                                        */
#define R_SYSTEM_DPFSAR_DPFSA3_Msk              (0x8UL)        /*!< DPFSA3 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR_DPFSA2_Pos              (2UL)          /*!< DPFSA2 (Bit 2)                                        */
#define R_SYSTEM_DPFSAR_DPFSA2_Msk              (0x4UL)        /*!< DPFSA2 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR_DPFSA1_Pos              (1UL)          /*!< DPFSA1 (Bit 1)                                        */
#define R_SYSTEM_DPFSAR_DPFSA1_Msk              (0x2UL)        /*!< DPFSA1 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR_DPFSA0_Pos              (0UL)          /*!< DPFSA0 (Bit 0)                                        */
#define R_SYSTEM_DPFSAR_DPFSA0_Msk              (0x1UL)        /*!< DPFSA0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  DPFSAR1  ======================================================== */
#define R_SYSTEM_DPFSAR1_DPFSA15_Pos            (15UL)         /*!< DPFSA15 (Bit 15)                                      */
#define R_SYSTEM_DPFSAR1_DPFSA15_Msk            (0x8000UL)     /*!< DPFSA15 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR1_DPFSA14_Pos            (14UL)         /*!< DPFSA14 (Bit 14)                                      */
#define R_SYSTEM_DPFSAR1_DPFSA14_Msk            (0x4000UL)     /*!< DPFSA14 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR1_DPFSA13_Pos            (13UL)         /*!< DPFSA13 (Bit 13)                                      */
#define R_SYSTEM_DPFSAR1_DPFSA13_Msk            (0x2000UL)     /*!< DPFSA13 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR1_DPFSA12_Pos            (12UL)         /*!< DPFSA12 (Bit 12)                                      */
#define R_SYSTEM_DPFSAR1_DPFSA12_Msk            (0x1000UL)     /*!< DPFSA12 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR1_DPFSA11_Pos            (11UL)         /*!< DPFSA11 (Bit 11)                                      */
#define R_SYSTEM_DPFSAR1_DPFSA11_Msk            (0x800UL)      /*!< DPFSA11 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR1_DPFSA10_Pos            (10UL)         /*!< DPFSA10 (Bit 10)                                      */
#define R_SYSTEM_DPFSAR1_DPFSA10_Msk            (0x400UL)      /*!< DPFSA10 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPFSAR1_DPFSA9_Pos             (9UL)          /*!< DPFSA9 (Bit 9)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA9_Msk             (0x200UL)      /*!< DPFSA9 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR1_DPFSA8_Pos             (8UL)          /*!< DPFSA8 (Bit 8)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA8_Msk             (0x100UL)      /*!< DPFSA8 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR1_DPFSA7_Pos             (7UL)          /*!< DPFSA7 (Bit 7)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA7_Msk             (0x80UL)       /*!< DPFSA7 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR1_DPFSA6_Pos             (6UL)          /*!< DPFSA6 (Bit 6)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA6_Msk             (0x40UL)       /*!< DPFSA6 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR1_DPFSA5_Pos             (5UL)          /*!< DPFSA5 (Bit 5)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA5_Msk             (0x20UL)       /*!< DPFSA5 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR1_DPFSA4_Pos             (4UL)          /*!< DPFSA4 (Bit 4)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA4_Msk             (0x10UL)       /*!< DPFSA4 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR1_DPFSA3_Pos             (3UL)          /*!< DPFSA3 (Bit 3)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA3_Msk             (0x8UL)        /*!< DPFSA3 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR1_DPFSA2_Pos             (2UL)          /*!< DPFSA2 (Bit 2)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA2_Msk             (0x4UL)        /*!< DPFSA2 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR1_DPFSA1_Pos             (1UL)          /*!< DPFSA1 (Bit 1)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA1_Msk             (0x2UL)        /*!< DPFSA1 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPFSAR1_DPFSA0_Pos             (0UL)          /*!< DPFSA0 (Bit 0)                                        */
#define R_SYSTEM_DPFSAR1_DPFSA0_Msk             (0x1UL)        /*!< DPFSA0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  RSCSAR  ========================================================= */
#define R_SYSTEM_RSCSAR_RSCSA24_Pos             (24UL)         /*!< RSCSA24 (Bit 24)                                      */
#define R_SYSTEM_RSCSAR_RSCSA24_Msk             (0x1000000UL)  /*!< RSCSA24 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_RSCSAR_RSCSA11_Pos             (11UL)         /*!< RSCSA11 (Bit 11)                                      */
#define R_SYSTEM_RSCSAR_RSCSA11_Msk             (0x800UL)      /*!< RSCSA11 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_RSCSAR_RSCSA10_Pos             (10UL)         /*!< RSCSA10 (Bit 10)                                      */
#define R_SYSTEM_RSCSAR_RSCSA10_Msk             (0x400UL)      /*!< RSCSA10 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_RSCSAR_RSCSA9_Pos              (9UL)          /*!< RSCSA9 (Bit 9)                                        */
#define R_SYSTEM_RSCSAR_RSCSA9_Msk              (0x200UL)      /*!< RSCSA9 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSCSAR_RSCSA8_Pos              (8UL)          /*!< RSCSA8 (Bit 8)                                        */
#define R_SYSTEM_RSCSAR_RSCSA8_Msk              (0x100UL)      /*!< RSCSA8 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSCSAR_RSCSA7_Pos              (7UL)          /*!< RSCSA7 (Bit 7)                                        */
#define R_SYSTEM_RSCSAR_RSCSA7_Msk              (0x80UL)       /*!< RSCSA7 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSCSAR_RSCSA6_Pos              (6UL)          /*!< RSCSA6 (Bit 6)                                        */
#define R_SYSTEM_RSCSAR_RSCSA6_Msk              (0x40UL)       /*!< RSCSA6 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSCSAR_RSCSA5_Pos              (5UL)          /*!< RSCSA5 (Bit 5)                                        */
#define R_SYSTEM_RSCSAR_RSCSA5_Msk              (0x20UL)       /*!< RSCSA5 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSCSAR_RSCSA4_Pos              (4UL)          /*!< RSCSA4 (Bit 4)                                        */
#define R_SYSTEM_RSCSAR_RSCSA4_Msk              (0x10UL)       /*!< RSCSA4 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSCSAR_RSCSA3_Pos              (3UL)          /*!< RSCSA3 (Bit 3)                                        */
#define R_SYSTEM_RSCSAR_RSCSA3_Msk              (0x8UL)        /*!< RSCSA3 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSCSAR_RSCSA2_Pos              (2UL)          /*!< RSCSA2 (Bit 2)                                        */
#define R_SYSTEM_RSCSAR_RSCSA2_Msk              (0x4UL)        /*!< RSCSA2 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSCSAR_RSCSA1_Pos              (1UL)          /*!< RSCSA1 (Bit 1)                                        */
#define R_SYSTEM_RSCSAR_RSCSA1_Msk              (0x2UL)        /*!< RSCSA1 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_RSCSAR_RSCSA0_Pos              (0UL)          /*!< RSCSA0 (Bit 0)                                        */
#define R_SYSTEM_RSCSAR_RSCSA0_Msk              (0x1UL)        /*!< RSCSA0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  PGSCR  ========================================================= */
#define R_SYSTEM_PGSCR_PGS_Pos                  (0UL)          /*!< PGS (Bit 0)                                           */
#define R_SYSTEM_PGSCR_PGS_Msk                  (0x1UL)        /*!< PGS (Bitfield-Mask: 0x01)                             */
/* ========================================================  PSSTCR2  ======================================================== */
#define R_SYSTEM_PSSTCR2_PSST_Pos               (0UL)          /*!< PSST (Bit 0)                                          */
#define R_SYSTEM_PSSTCR2_PSST_Msk               (0x1fffUL)     /*!< PSST (Bitfield-Mask: 0x1fff)                          */
/* ========================================================  PSSTCR4  ======================================================== */
#define R_SYSTEM_PSSTCR4_PSST_Pos               (0UL)          /*!< PSST (Bit 0)                                          */
#define R_SYSTEM_PSSTCR4_PSST_Msk               (0x1fffUL)     /*!< PSST (Bitfield-Mask: 0x1fff)                          */
/* ========================================================  PSSTCR5  ======================================================== */
#define R_SYSTEM_PSSTCR5_PSST_Pos               (0UL)          /*!< PSST (Bit 0)                                          */
#define R_SYSTEM_PSSTCR5_PSST_Msk               (0x1fffUL)     /*!< PSST (Bitfield-Mask: 0x1fff)                          */
/* =======================================================  PDCTRESWM  ======================================================= */
#define R_SYSTEM_PDCTRESWM_PDPGSF_Pos           (7UL)          /*!< PDPGSF (Bit 7)                                        */
#define R_SYSTEM_PDCTRESWM_PDPGSF_Msk           (0x80UL)       /*!< PDPGSF (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDCTRESWM_PDCSF_Pos            (6UL)          /*!< PDCSF (Bit 6)                                         */
#define R_SYSTEM_PDCTRESWM_PDCSF_Msk            (0x40UL)       /*!< PDCSF (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_PDCTRESWM_PDDE_Pos             (0UL)          /*!< PDDE (Bit 0)                                          */
#define R_SYSTEM_PDCTRESWM_PDDE_Msk             (0x1UL)        /*!< PDDE (Bitfield-Mask: 0x01)                            */
/* =======================================================  PDRAMSCR0  ======================================================= */
#define R_SYSTEM_PDRAMSCR0_RKEEP11_Pos          (11UL)         /*!< RKEEP11 (Bit 11)                                      */
#define R_SYSTEM_PDRAMSCR0_RKEEP11_Msk          (0x800UL)      /*!< RKEEP11 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_PDRAMSCR0_RKEEP10_Pos          (10UL)         /*!< RKEEP10 (Bit 10)                                      */
#define R_SYSTEM_PDRAMSCR0_RKEEP10_Msk          (0x400UL)      /*!< RKEEP10 (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_PDRAMSCR0_RKEEP9_Pos           (9UL)          /*!< RKEEP9 (Bit 9)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP9_Msk           (0x200UL)      /*!< RKEEP9 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDRAMSCR0_RKEEP8_Pos           (8UL)          /*!< RKEEP8 (Bit 8)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP8_Msk           (0x100UL)      /*!< RKEEP8 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDRAMSCR0_RKEEP7_Pos           (7UL)          /*!< RKEEP7 (Bit 7)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP7_Msk           (0x80UL)       /*!< RKEEP7 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDRAMSCR0_RKEEP6_Pos           (6UL)          /*!< RKEEP6 (Bit 6)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP6_Msk           (0x40UL)       /*!< RKEEP6 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDRAMSCR0_RKEEP5_Pos           (5UL)          /*!< RKEEP5 (Bit 5)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP5_Msk           (0x20UL)       /*!< RKEEP5 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDRAMSCR0_RKEEP4_Pos           (4UL)          /*!< RKEEP4 (Bit 4)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP4_Msk           (0x10UL)       /*!< RKEEP4 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDRAMSCR0_RKEEP3_Pos           (3UL)          /*!< RKEEP3 (Bit 3)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP3_Msk           (0x8UL)        /*!< RKEEP3 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDRAMSCR0_RKEEP2_Pos           (2UL)          /*!< RKEEP2 (Bit 2)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP2_Msk           (0x4UL)        /*!< RKEEP2 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDRAMSCR0_RKEEP1_Pos           (1UL)          /*!< RKEEP1 (Bit 1)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP1_Msk           (0x2UL)        /*!< RKEEP1 (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_PDRAMSCR0_RKEEP0_Pos           (0UL)          /*!< RKEEP0 (Bit 0)                                        */
#define R_SYSTEM_PDRAMSCR0_RKEEP0_Msk           (0x1UL)        /*!< RKEEP0 (Bitfield-Mask: 0x01)                          */
/* =======================================================  PDRAMSCR2  ======================================================= */
#define R_SYSTEM_PDRAMSCR2_RKEEP0_Pos           (0UL)          /*!< RKEEP0 (Bit 0)                                        */
#define R_SYSTEM_PDRAMSCR2_RKEEP0_Msk           (0x1UL)        /*!< RKEEP0 (Bitfield-Mask: 0x01)                          */
/* =========================================================  SBYCR  ========================================================= */
#define R_SYSTEM_SBYCR_OPE_Pos                  (6UL)          /*!< OPE (Bit 6)                                           */
#define R_SYSTEM_SBYCR_OPE_Msk                  (0x40UL)       /*!< OPE (Bitfield-Mask: 0x01)                             */
/* =========================================================  SSCR1  ========================================================= */
#define R_SYSTEM_SSCR1_SS2LP_Pos                (2UL)          /*!< SS2LP (Bit 2)                                         */
#define R_SYSTEM_SSCR1_SS2LP_Msk                (0xcUL)        /*!< SS2LP (Bitfield-Mask: 0x03)                           */
#define R_SYSTEM_SSCR1_SS2FR_Pos                (0UL)          /*!< SS2FR (Bit 0)                                         */
#define R_SYSTEM_SSCR1_SS2FR_Msk                (0x1UL)        /*!< SS2FR (Bitfield-Mask: 0x01)                           */
/* =========================================================  LPSCR  ========================================================= */
#define R_SYSTEM_LPSCR_LPMD_Pos                 (0UL)          /*!< LPMD (Bit 0)                                          */
#define R_SYSTEM_LPSCR_LPMD_Msk                 (0xfUL)        /*!< LPMD (Bitfield-Mask: 0x0f)                            */
/* ========================================================  DPSBYCR  ======================================================== */
#define R_SYSTEM_DPSBYCR_IOKEEP_Pos             (6UL)          /*!< IOKEEP (Bit 6)                                        */
#define R_SYSTEM_DPSBYCR_IOKEEP_Msk             (0x40UL)       /*!< IOKEEP (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSBYCR_DCSSMODE_Pos           (2UL)          /*!< DCSSMODE (Bit 2)                                      */
#define R_SYSTEM_DPSBYCR_DCSSMODE_Msk           (0xcUL)        /*!< DCSSMODE (Bitfield-Mask: 0x03)                        */
#define R_SYSTEM_DPSBYCR_LDOSSMODE_Pos          (0UL)          /*!< LDOSSMODE (Bit 0)                                     */
#define R_SYSTEM_DPSBYCR_LDOSSMODE_Msk          (0x3UL)        /*!< LDOSSMODE (Bitfield-Mask: 0x03)                       */
/* ========================================================  DPSIER0  ======================================================== */
#define R_SYSTEM_DPSIER0_DIRQ7E_Pos             (7UL)          /*!< DIRQ7E (Bit 7)                                        */
#define R_SYSTEM_DPSIER0_DIRQ7E_Msk             (0x80UL)       /*!< DIRQ7E (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIER0_DIRQ6E_Pos             (6UL)          /*!< DIRQ6E (Bit 6)                                        */
#define R_SYSTEM_DPSIER0_DIRQ6E_Msk             (0x40UL)       /*!< DIRQ6E (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIER0_DIRQ5E_Pos             (5UL)          /*!< DIRQ5E (Bit 5)                                        */
#define R_SYSTEM_DPSIER0_DIRQ5E_Msk             (0x20UL)       /*!< DIRQ5E (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIER0_DIRQ4E_Pos             (4UL)          /*!< DIRQ4E (Bit 4)                                        */
#define R_SYSTEM_DPSIER0_DIRQ4E_Msk             (0x10UL)       /*!< DIRQ4E (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIER0_DIRQ3E_Pos             (3UL)          /*!< DIRQ3E (Bit 3)                                        */
#define R_SYSTEM_DPSIER0_DIRQ3E_Msk             (0x8UL)        /*!< DIRQ3E (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIER0_DIRQ2E_Pos             (2UL)          /*!< DIRQ2E (Bit 2)                                        */
#define R_SYSTEM_DPSIER0_DIRQ2E_Msk             (0x4UL)        /*!< DIRQ2E (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIER0_DIRQ1E_Pos             (1UL)          /*!< DIRQ1E (Bit 1)                                        */
#define R_SYSTEM_DPSIER0_DIRQ1E_Msk             (0x2UL)        /*!< DIRQ1E (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIER0_DIRQ0E_Pos             (0UL)          /*!< DIRQ0E (Bit 0)                                        */
#define R_SYSTEM_DPSIER0_DIRQ0E_Msk             (0x1UL)        /*!< DIRQ0E (Bitfield-Mask: 0x01)                          */
/* ========================================================  DPSIER1  ======================================================== */
#define R_SYSTEM_DPSIER1_DIRQ15E_Pos            (7UL)          /*!< DIRQ15E (Bit 7)                                       */
#define R_SYSTEM_DPSIER1_DIRQ15E_Msk            (0x80UL)       /*!< DIRQ15E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER1_DIRQ14E_Pos            (6UL)          /*!< DIRQ14E (Bit 6)                                       */
#define R_SYSTEM_DPSIER1_DIRQ14E_Msk            (0x40UL)       /*!< DIRQ14E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER1_DIRQ13E_Pos            (5UL)          /*!< DIRQ13E (Bit 5)                                       */
#define R_SYSTEM_DPSIER1_DIRQ13E_Msk            (0x20UL)       /*!< DIRQ13E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER1_DIRQ12E_Pos            (4UL)          /*!< DIRQ12E (Bit 4)                                       */
#define R_SYSTEM_DPSIER1_DIRQ12E_Msk            (0x10UL)       /*!< DIRQ12E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER1_DIRQ11E_Pos            (3UL)          /*!< DIRQ11E (Bit 3)                                       */
#define R_SYSTEM_DPSIER1_DIRQ11E_Msk            (0x8UL)        /*!< DIRQ11E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER1_DIRQ10E_Pos            (2UL)          /*!< DIRQ10E (Bit 2)                                       */
#define R_SYSTEM_DPSIER1_DIRQ10E_Msk            (0x4UL)        /*!< DIRQ10E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER1_DIRQ9E_Pos             (1UL)          /*!< DIRQ9E (Bit 1)                                        */
#define R_SYSTEM_DPSIER1_DIRQ9E_Msk             (0x2UL)        /*!< DIRQ9E (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIER1_DIRQ8E_Pos             (0UL)          /*!< DIRQ8E (Bit 0)                                        */
#define R_SYSTEM_DPSIER1_DIRQ8E_Msk             (0x1UL)        /*!< DIRQ8E (Bitfield-Mask: 0x01)                          */
/* ========================================================  DPSIER2  ======================================================== */
#define R_SYSTEM_DPSIER2_DNMIE_Pos              (4UL)          /*!< DNMIE (Bit 4)                                         */
#define R_SYSTEM_DPSIER2_DNMIE_Msk              (0x10UL)       /*!< DNMIE (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_DPSIER2_DRTCAIE_Pos            (3UL)          /*!< DRTCAIE (Bit 3)                                       */
#define R_SYSTEM_DPSIER2_DRTCAIE_Msk            (0x8UL)        /*!< DRTCAIE (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER2_DRTCIIE_Pos            (2UL)          /*!< DRTCIIE (Bit 2)                                       */
#define R_SYSTEM_DPSIER2_DRTCIIE_Msk            (0x4UL)        /*!< DRTCIIE (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER2_DPVD2IE_Pos            (1UL)          /*!< DPVD2IE (Bit 1)                                       */
#define R_SYSTEM_DPSIER2_DPVD2IE_Msk            (0x2UL)        /*!< DPVD2IE (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER2_DPVD1IE_Pos            (0UL)          /*!< DPVD1IE (Bit 0)                                       */
#define R_SYSTEM_DPSIER2_DPVD1IE_Msk            (0x1UL)        /*!< DPVD1IE (Bitfield-Mask: 0x01)                         */
/* ========================================================  DPSIER3  ======================================================== */
#define R_SYSTEM_DPSIER3_DVBATTADIE_Pos         (7UL)          /*!< DVBATTADIE (Bit 7)                                    */
#define R_SYSTEM_DPSIER3_DVBATTADIE_Msk         (0x80UL)       /*!< DVBATTADIE (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_DPSIER3_DSOSTDIE_Pos           (6UL)          /*!< DSOSTDIE (Bit 6)                                      */
#define R_SYSTEM_DPSIER3_DSOSTDIE_Msk           (0x40UL)       /*!< DSOSTDIE (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIER3_DIWDTIE_Pos            (5UL)          /*!< DIWDTIE (Bit 5)                                       */
#define R_SYSTEM_DPSIER3_DIWDTIE_Msk            (0x20UL)       /*!< DIWDTIE (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER3_DUSBHSIE_Pos           (1UL)          /*!< DUSBHSIE (Bit 1)                                      */
#define R_SYSTEM_DPSIER3_DUSBHSIE_Msk           (0x2UL)        /*!< DUSBHSIE (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIER3_DUSBFSIE_Pos           (0UL)          /*!< DUSBFSIE (Bit 0)                                      */
#define R_SYSTEM_DPSIER3_DUSBFSIE_Msk           (0x1UL)        /*!< DUSBFSIE (Bitfield-Mask: 0x01)                        */
/* ========================================================  DPSIER4  ======================================================== */
#define R_SYSTEM_DPSIER4_DIRQ23E_Pos            (7UL)          /*!< DIRQ23E (Bit 7)                                       */
#define R_SYSTEM_DPSIER4_DIRQ23E_Msk            (0x80UL)       /*!< DIRQ23E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER4_DIRQ22E_Pos            (6UL)          /*!< DIRQ22E (Bit 6)                                       */
#define R_SYSTEM_DPSIER4_DIRQ22E_Msk            (0x40UL)       /*!< DIRQ22E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER4_DIRQ21E_Pos            (5UL)          /*!< DIRQ21E (Bit 5)                                       */
#define R_SYSTEM_DPSIER4_DIRQ21E_Msk            (0x20UL)       /*!< DIRQ21E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER4_DIRQ20E_Pos            (4UL)          /*!< DIRQ20E (Bit 4)                                       */
#define R_SYSTEM_DPSIER4_DIRQ20E_Msk            (0x10UL)       /*!< DIRQ20E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER4_DIRQ19E_Pos            (3UL)          /*!< DIRQ19E (Bit 3)                                       */
#define R_SYSTEM_DPSIER4_DIRQ19E_Msk            (0x8UL)        /*!< DIRQ19E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER4_DIRQ18E_Pos            (2UL)          /*!< DIRQ18E (Bit 2)                                       */
#define R_SYSTEM_DPSIER4_DIRQ18E_Msk            (0x4UL)        /*!< DIRQ18E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER4_DIRQ17E_Pos            (1UL)          /*!< DIRQ17E (Bit 1)                                       */
#define R_SYSTEM_DPSIER4_DIRQ17E_Msk            (0x2UL)        /*!< DIRQ17E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER4_DIRQ16E_Pos            (0UL)          /*!< DIRQ16E (Bit 0)                                       */
#define R_SYSTEM_DPSIER4_DIRQ16E_Msk            (0x1UL)        /*!< DIRQ16E (Bitfield-Mask: 0x01)                         */
/* ========================================================  DPSIER5  ======================================================== */
#define R_SYSTEM_DPSIER5_DIRQ31E_Pos            (7UL)          /*!< DIRQ31E (Bit 7)                                       */
#define R_SYSTEM_DPSIER5_DIRQ31E_Msk            (0x80UL)       /*!< DIRQ31E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER5_DIRQ30E_Pos            (6UL)          /*!< DIRQ30E (Bit 6)                                       */
#define R_SYSTEM_DPSIER5_DIRQ30E_Msk            (0x40UL)       /*!< DIRQ30E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER5_DIRQ29E_Pos            (5UL)          /*!< DIRQ29E (Bit 5)                                       */
#define R_SYSTEM_DPSIER5_DIRQ29E_Msk            (0x20UL)       /*!< DIRQ29E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER5_DIRQ28E_Pos            (4UL)          /*!< DIRQ28E (Bit 4)                                       */
#define R_SYSTEM_DPSIER5_DIRQ28E_Msk            (0x10UL)       /*!< DIRQ28E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER5_DIRQ27E_Pos            (3UL)          /*!< DIRQ27E (Bit 3)                                       */
#define R_SYSTEM_DPSIER5_DIRQ27E_Msk            (0x8UL)        /*!< DIRQ27E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER5_DIRQ26E_Pos            (2UL)          /*!< DIRQ26E (Bit 2)                                       */
#define R_SYSTEM_DPSIER5_DIRQ26E_Msk            (0x4UL)        /*!< DIRQ26E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER5_DIRQ25E_Pos            (1UL)          /*!< DIRQ25E (Bit 1)                                       */
#define R_SYSTEM_DPSIER5_DIRQ25E_Msk            (0x2UL)        /*!< DIRQ25E (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIER5_DIRQ24E_Pos            (0UL)          /*!< DIRQ24E (Bit 0)                                       */
#define R_SYSTEM_DPSIER5_DIRQ24E_Msk            (0x1UL)        /*!< DIRQ24E (Bitfield-Mask: 0x01)                         */
/* ========================================================  DPSIFR0  ======================================================== */
#define R_SYSTEM_DPSIFR0_DIRQ7F_Pos             (7UL)          /*!< DIRQ7F (Bit 7)                                        */
#define R_SYSTEM_DPSIFR0_DIRQ7F_Msk             (0x80UL)       /*!< DIRQ7F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIFR0_DIRQ6F_Pos             (6UL)          /*!< DIRQ6F (Bit 6)                                        */
#define R_SYSTEM_DPSIFR0_DIRQ6F_Msk             (0x40UL)       /*!< DIRQ6F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIFR0_DIRQ5F_Pos             (5UL)          /*!< DIRQ5F (Bit 5)                                        */
#define R_SYSTEM_DPSIFR0_DIRQ5F_Msk             (0x20UL)       /*!< DIRQ5F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIFR0_DIRQ4F_Pos             (4UL)          /*!< DIRQ4F (Bit 4)                                        */
#define R_SYSTEM_DPSIFR0_DIRQ4F_Msk             (0x10UL)       /*!< DIRQ4F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIFR0_DIRQ3F_Pos             (3UL)          /*!< DIRQ3F (Bit 3)                                        */
#define R_SYSTEM_DPSIFR0_DIRQ3F_Msk             (0x8UL)        /*!< DIRQ3F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIFR0_DIRQ2F_Pos             (2UL)          /*!< DIRQ2F (Bit 2)                                        */
#define R_SYSTEM_DPSIFR0_DIRQ2F_Msk             (0x4UL)        /*!< DIRQ2F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIFR0_DIRQ1F_Pos             (1UL)          /*!< DIRQ1F (Bit 1)                                        */
#define R_SYSTEM_DPSIFR0_DIRQ1F_Msk             (0x2UL)        /*!< DIRQ1F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIFR0_DIRQ0F_Pos             (0UL)          /*!< DIRQ0F (Bit 0)                                        */
#define R_SYSTEM_DPSIFR0_DIRQ0F_Msk             (0x1UL)        /*!< DIRQ0F (Bitfield-Mask: 0x01)                          */
/* ========================================================  DPSIFR1  ======================================================== */
#define R_SYSTEM_DPSIFR1_DIRQ15F_Pos            (7UL)          /*!< DIRQ15F (Bit 7)                                       */
#define R_SYSTEM_DPSIFR1_DIRQ15F_Msk            (0x80UL)       /*!< DIRQ15F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR1_DIRQ14F_Pos            (6UL)          /*!< DIRQ14F (Bit 6)                                       */
#define R_SYSTEM_DPSIFR1_DIRQ14F_Msk            (0x40UL)       /*!< DIRQ14F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR1_DIRQ13F_Pos            (5UL)          /*!< DIRQ13F (Bit 5)                                       */
#define R_SYSTEM_DPSIFR1_DIRQ13F_Msk            (0x20UL)       /*!< DIRQ13F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR1_DIRQ12F_Pos            (4UL)          /*!< DIRQ12F (Bit 4)                                       */
#define R_SYSTEM_DPSIFR1_DIRQ12F_Msk            (0x10UL)       /*!< DIRQ12F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR1_DIRQ11F_Pos            (3UL)          /*!< DIRQ11F (Bit 3)                                       */
#define R_SYSTEM_DPSIFR1_DIRQ11F_Msk            (0x8UL)        /*!< DIRQ11F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR1_DIRQ10F_Pos            (2UL)          /*!< DIRQ10F (Bit 2)                                       */
#define R_SYSTEM_DPSIFR1_DIRQ10F_Msk            (0x4UL)        /*!< DIRQ10F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR1_DIRQ9F_Pos             (1UL)          /*!< DIRQ9F (Bit 1)                                        */
#define R_SYSTEM_DPSIFR1_DIRQ9F_Msk             (0x2UL)        /*!< DIRQ9F (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIFR1_DIRQ8F_Pos             (0UL)          /*!< DIRQ8F (Bit 0)                                        */
#define R_SYSTEM_DPSIFR1_DIRQ8F_Msk             (0x1UL)        /*!< DIRQ8F (Bitfield-Mask: 0x01)                          */
/* ========================================================  DPSIFR2  ======================================================== */
#define R_SYSTEM_DPSIFR2_DNMIF_Pos              (4UL)          /*!< DNMIF (Bit 4)                                         */
#define R_SYSTEM_DPSIFR2_DNMIF_Msk              (0x10UL)       /*!< DNMIF (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_DPSIFR2_DRTCAIF_Pos            (3UL)          /*!< DRTCAIF (Bit 3)                                       */
#define R_SYSTEM_DPSIFR2_DRTCAIF_Msk            (0x8UL)        /*!< DRTCAIF (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR2_DRTCIIF_Pos            (2UL)          /*!< DRTCIIF (Bit 2)                                       */
#define R_SYSTEM_DPSIFR2_DRTCIIF_Msk            (0x4UL)        /*!< DRTCIIF (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR2_DPVD2IF_Pos            (1UL)          /*!< DPVD2IF (Bit 1)                                       */
#define R_SYSTEM_DPSIFR2_DPVD2IF_Msk            (0x2UL)        /*!< DPVD2IF (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR2_DPVD1IF_Pos            (0UL)          /*!< DPVD1IF (Bit 0)                                       */
#define R_SYSTEM_DPSIFR2_DPVD1IF_Msk            (0x1UL)        /*!< DPVD1IF (Bitfield-Mask: 0x01)                         */
/* ========================================================  DPSIFR3  ======================================================== */
#define R_SYSTEM_DPSIFR3_DVBATTADIF_Pos         (7UL)          /*!< DVBATTADIF (Bit 7)                                    */
#define R_SYSTEM_DPSIFR3_DVBATTADIF_Msk         (0x80UL)       /*!< DVBATTADIF (Bitfield-Mask: 0x01)                      */
#define R_SYSTEM_DPSIFR3_DSOSTDIF_Pos           (6UL)          /*!< DSOSTDIF (Bit 6)                                      */
#define R_SYSTEM_DPSIFR3_DSOSTDIF_Msk           (0x40UL)       /*!< DSOSTDIF (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIFR3_DIWDTIF_Pos            (5UL)          /*!< DIWDTIF (Bit 5)                                       */
#define R_SYSTEM_DPSIFR3_DIWDTIF_Msk            (0x20UL)       /*!< DIWDTIF (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR3_DUSBHSIF_Pos           (1UL)          /*!< DUSBHSIF (Bit 1)                                      */
#define R_SYSTEM_DPSIFR3_DUSBHSIF_Msk           (0x2UL)        /*!< DUSBHSIF (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIFR3_DUSBFSIF_Pos           (0UL)          /*!< DUSBFSIF (Bit 0)                                      */
#define R_SYSTEM_DPSIFR3_DUSBFSIF_Msk           (0x1UL)        /*!< DUSBFSIF (Bitfield-Mask: 0x01)                        */
/* ========================================================  DPSIFR4  ======================================================== */
#define R_SYSTEM_DPSIFR4_DIRQ23F_Pos            (7UL)          /*!< DIRQ23F (Bit 7)                                       */
#define R_SYSTEM_DPSIFR4_DIRQ23F_Msk            (0x80UL)       /*!< DIRQ23F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR4_DIRQ22F_Pos            (6UL)          /*!< DIRQ22F (Bit 6)                                       */
#define R_SYSTEM_DPSIFR4_DIRQ22F_Msk            (0x40UL)       /*!< DIRQ22F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR4_DIRQ21F_Pos            (5UL)          /*!< DIRQ21F (Bit 5)                                       */
#define R_SYSTEM_DPSIFR4_DIRQ21F_Msk            (0x20UL)       /*!< DIRQ21F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR4_DIRQ20F_Pos            (4UL)          /*!< DIRQ20F (Bit 4)                                       */
#define R_SYSTEM_DPSIFR4_DIRQ20F_Msk            (0x10UL)       /*!< DIRQ20F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR4_DIRQ19F_Pos            (3UL)          /*!< DIRQ19F (Bit 3)                                       */
#define R_SYSTEM_DPSIFR4_DIRQ19F_Msk            (0x8UL)        /*!< DIRQ19F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR4_DIRQ18F_Pos            (2UL)          /*!< DIRQ18F (Bit 2)                                       */
#define R_SYSTEM_DPSIFR4_DIRQ18F_Msk            (0x4UL)        /*!< DIRQ18F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR4_DIRQ17F_Pos            (1UL)          /*!< DIRQ17F (Bit 1)                                       */
#define R_SYSTEM_DPSIFR4_DIRQ17F_Msk            (0x2UL)        /*!< DIRQ17F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR4_DIRQ16F_Pos            (0UL)          /*!< DIRQ16F (Bit 0)                                       */
#define R_SYSTEM_DPSIFR4_DIRQ16F_Msk            (0x1UL)        /*!< DIRQ16F (Bitfield-Mask: 0x01)                         */
/* ========================================================  DPSIFR5  ======================================================== */
#define R_SYSTEM_DPSIFR5_DIRQ31F_Pos            (7UL)          /*!< DIRQ31F (Bit 7)                                       */
#define R_SYSTEM_DPSIFR5_DIRQ31F_Msk            (0x80UL)       /*!< DIRQ31F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR5_DIRQ30F_Pos            (6UL)          /*!< DIRQ30F (Bit 6)                                       */
#define R_SYSTEM_DPSIFR5_DIRQ30F_Msk            (0x40UL)       /*!< DIRQ30F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR5_DIRQ29F_Pos            (5UL)          /*!< DIRQ29F (Bit 5)                                       */
#define R_SYSTEM_DPSIFR5_DIRQ29F_Msk            (0x20UL)       /*!< DIRQ29F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR5_DIRQ28F_Pos            (4UL)          /*!< DIRQ28F (Bit 4)                                       */
#define R_SYSTEM_DPSIFR5_DIRQ28F_Msk            (0x10UL)       /*!< DIRQ28F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR5_DIRQ27F_Pos            (3UL)          /*!< DIRQ27F (Bit 3)                                       */
#define R_SYSTEM_DPSIFR5_DIRQ27F_Msk            (0x8UL)        /*!< DIRQ27F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR5_DIRQ26F_Pos            (2UL)          /*!< DIRQ26F (Bit 2)                                       */
#define R_SYSTEM_DPSIFR5_DIRQ26F_Msk            (0x4UL)        /*!< DIRQ26F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR5_DIRQ25F_Pos            (1UL)          /*!< DIRQ25F (Bit 1)                                       */
#define R_SYSTEM_DPSIFR5_DIRQ25F_Msk            (0x2UL)        /*!< DIRQ25F (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIFR5_DIRQ24F_Pos            (0UL)          /*!< DIRQ24F (Bit 0)                                       */
#define R_SYSTEM_DPSIFR5_DIRQ24F_Msk            (0x1UL)        /*!< DIRQ24F (Bitfield-Mask: 0x01)                         */
/* =======================================================  DPSIEGR0  ======================================================== */
#define R_SYSTEM_DPSIEGR0_DIRQ7EG_Pos           (7UL)          /*!< DIRQ7EG (Bit 7)                                       */
#define R_SYSTEM_DPSIEGR0_DIRQ7EG_Msk           (0x80UL)       /*!< DIRQ7EG (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIEGR0_DIRQ6EG_Pos           (6UL)          /*!< DIRQ6EG (Bit 6)                                       */
#define R_SYSTEM_DPSIEGR0_DIRQ6EG_Msk           (0x40UL)       /*!< DIRQ6EG (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIEGR0_DIRQ5EG_Pos           (5UL)          /*!< DIRQ5EG (Bit 5)                                       */
#define R_SYSTEM_DPSIEGR0_DIRQ5EG_Msk           (0x20UL)       /*!< DIRQ5EG (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIEGR0_DIRQ4EG_Pos           (4UL)          /*!< DIRQ4EG (Bit 4)                                       */
#define R_SYSTEM_DPSIEGR0_DIRQ4EG_Msk           (0x10UL)       /*!< DIRQ4EG (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIEGR0_DIRQ3EG_Pos           (3UL)          /*!< DIRQ3EG (Bit 3)                                       */
#define R_SYSTEM_DPSIEGR0_DIRQ3EG_Msk           (0x8UL)        /*!< DIRQ3EG (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIEGR0_DIRQ2EG_Pos           (2UL)          /*!< DIRQ2EG (Bit 2)                                       */
#define R_SYSTEM_DPSIEGR0_DIRQ2EG_Msk           (0x4UL)        /*!< DIRQ2EG (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIEGR0_DIRQ1EG_Pos           (1UL)          /*!< DIRQ1EG (Bit 1)                                       */
#define R_SYSTEM_DPSIEGR0_DIRQ1EG_Msk           (0x2UL)        /*!< DIRQ1EG (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIEGR0_DIRQ0EG_Pos           (0UL)          /*!< DIRQ0EG (Bit 0)                                       */
#define R_SYSTEM_DPSIEGR0_DIRQ0EG_Msk           (0x1UL)        /*!< DIRQ0EG (Bitfield-Mask: 0x01)                         */
/* =======================================================  DPSIEGR1  ======================================================== */
#define R_SYSTEM_DPSIEGR1_DIRQ15EG_Pos          (7UL)          /*!< DIRQ15EG (Bit 7)                                      */
#define R_SYSTEM_DPSIEGR1_DIRQ15EG_Msk          (0x80UL)       /*!< DIRQ15EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR1_DIRQ14EG_Pos          (6UL)          /*!< DIRQ14EG (Bit 6)                                      */
#define R_SYSTEM_DPSIEGR1_DIRQ14EG_Msk          (0x40UL)       /*!< DIRQ14EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR1_DIRQ13EG_Pos          (5UL)          /*!< DIRQ13EG (Bit 5)                                      */
#define R_SYSTEM_DPSIEGR1_DIRQ13EG_Msk          (0x20UL)       /*!< DIRQ13EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR1_DIRQ12EG_Pos          (4UL)          /*!< DIRQ12EG (Bit 4)                                      */
#define R_SYSTEM_DPSIEGR1_DIRQ12EG_Msk          (0x10UL)       /*!< DIRQ12EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR1_DIRQ11EG_Pos          (3UL)          /*!< DIRQ11EG (Bit 3)                                      */
#define R_SYSTEM_DPSIEGR1_DIRQ11EG_Msk          (0x8UL)        /*!< DIRQ11EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR1_DIRQ10EG_Pos          (2UL)          /*!< DIRQ10EG (Bit 2)                                      */
#define R_SYSTEM_DPSIEGR1_DIRQ10EG_Msk          (0x4UL)        /*!< DIRQ10EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR1_DIRQ9EG_Pos           (1UL)          /*!< DIRQ9EG (Bit 1)                                       */
#define R_SYSTEM_DPSIEGR1_DIRQ9EG_Msk           (0x2UL)        /*!< DIRQ9EG (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIEGR1_DIRQ8EG_Pos           (0UL)          /*!< DIRQ8EG (Bit 0)                                       */
#define R_SYSTEM_DPSIEGR1_DIRQ8EG_Msk           (0x1UL)        /*!< DIRQ8EG (Bitfield-Mask: 0x01)                         */
/* =======================================================  DPSIEGR2  ======================================================== */
#define R_SYSTEM_DPSIEGR2_DNMIEG_Pos            (4UL)          /*!< DNMIEG (Bit 4)                                        */
#define R_SYSTEM_DPSIEGR2_DNMIEG_Msk            (0x10UL)       /*!< DNMIEG (Bitfield-Mask: 0x01)                          */
#define R_SYSTEM_DPSIEGR2_DPVD2EG_Pos           (1UL)          /*!< DPVD2EG (Bit 1)                                       */
#define R_SYSTEM_DPSIEGR2_DPVD2EG_Msk           (0x2UL)        /*!< DPVD2EG (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_DPSIEGR2_DPVD1EG_Pos           (0UL)          /*!< DPVD1EG (Bit 0)                                       */
#define R_SYSTEM_DPSIEGR2_DPVD1EG_Msk           (0x1UL)        /*!< DPVD1EG (Bitfield-Mask: 0x01)                         */
/* =======================================================  DPSIEGR3  ======================================================== */
#define R_SYSTEM_DPSIEGR3_DIRQ23EG_Pos          (7UL)          /*!< DIRQ23EG (Bit 7)                                      */
#define R_SYSTEM_DPSIEGR3_DIRQ23EG_Msk          (0x80UL)       /*!< DIRQ23EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR3_DIRQ22EG_Pos          (6UL)          /*!< DIRQ22EG (Bit 6)                                      */
#define R_SYSTEM_DPSIEGR3_DIRQ22EG_Msk          (0x40UL)       /*!< DIRQ22EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR3_DIRQ21EG_Pos          (5UL)          /*!< DIRQ21EG (Bit 5)                                      */
#define R_SYSTEM_DPSIEGR3_DIRQ21EG_Msk          (0x20UL)       /*!< DIRQ21EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR3_DIRQ20EG_Pos          (4UL)          /*!< DIRQ20EG (Bit 4)                                      */
#define R_SYSTEM_DPSIEGR3_DIRQ20EG_Msk          (0x10UL)       /*!< DIRQ20EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR3_DIRQ19EG_Pos          (3UL)          /*!< DIRQ19EG (Bit 3)                                      */
#define R_SYSTEM_DPSIEGR3_DIRQ19EG_Msk          (0x8UL)        /*!< DIRQ19EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR3_DIRQ18EG_Pos          (2UL)          /*!< DIRQ18EG (Bit 2)                                      */
#define R_SYSTEM_DPSIEGR3_DIRQ18EG_Msk          (0x4UL)        /*!< DIRQ18EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR3_DIRQ17EG_Pos          (1UL)          /*!< DIRQ17EG (Bit 1)                                      */
#define R_SYSTEM_DPSIEGR3_DIRQ17EG_Msk          (0x2UL)        /*!< DIRQ17EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR3_DIRQ16EG_Pos          (0UL)          /*!< DIRQ16EG (Bit 0)                                      */
#define R_SYSTEM_DPSIEGR3_DIRQ16EG_Msk          (0x1UL)        /*!< DIRQ16EG (Bitfield-Mask: 0x01)                        */
/* =======================================================  DPSIEGR4  ======================================================== */
#define R_SYSTEM_DPSIEGR4_DIRQ31EG_Pos          (7UL)          /*!< DIRQ31EG (Bit 7)                                      */
#define R_SYSTEM_DPSIEGR4_DIRQ31EG_Msk          (0x80UL)       /*!< DIRQ31EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR4_DIRQ30EG_Pos          (6UL)          /*!< DIRQ30EG (Bit 6)                                      */
#define R_SYSTEM_DPSIEGR4_DIRQ30EG_Msk          (0x40UL)       /*!< DIRQ30EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR4_DIRQ29EG_Pos          (5UL)          /*!< DIRQ29EG (Bit 5)                                      */
#define R_SYSTEM_DPSIEGR4_DIRQ29EG_Msk          (0x20UL)       /*!< DIRQ29EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR4_DIRQ28EG_Pos          (4UL)          /*!< DIRQ28EG (Bit 4)                                      */
#define R_SYSTEM_DPSIEGR4_DIRQ28EG_Msk          (0x10UL)       /*!< DIRQ28EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR4_DIRQ27EG_Pos          (3UL)          /*!< DIRQ27EG (Bit 3)                                      */
#define R_SYSTEM_DPSIEGR4_DIRQ27EG_Msk          (0x8UL)        /*!< DIRQ27EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR4_DIRQ26EG_Pos          (2UL)          /*!< DIRQ26EG (Bit 2)                                      */
#define R_SYSTEM_DPSIEGR4_DIRQ26EG_Msk          (0x4UL)        /*!< DIRQ26EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR4_DIRQ25EG_Pos          (1UL)          /*!< DIRQ25EG (Bit 1)                                      */
#define R_SYSTEM_DPSIEGR4_DIRQ25EG_Msk          (0x2UL)        /*!< DIRQ25EG (Bitfield-Mask: 0x01)                        */
#define R_SYSTEM_DPSIEGR4_DIRQ24EG_Pos          (0UL)          /*!< DIRQ24EG (Bit 0)                                      */
#define R_SYSTEM_DPSIEGR4_DIRQ24EG_Msk          (0x1UL)        /*!< DIRQ24EG (Bitfield-Mask: 0x01)                        */
/* =======================================================  PLL1LDOCR  ======================================================= */
#define R_SYSTEM_PLL1LDOCR_SKEEP_Pos            (1UL)          /*!< SKEEP (Bit 1)                                         */
#define R_SYSTEM_PLL1LDOCR_SKEEP_Msk            (0x2UL)        /*!< SKEEP (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_PLL1LDOCR_LDOSTP_Pos           (0UL)          /*!< LDOSTP (Bit 0)                                        */
#define R_SYSTEM_PLL1LDOCR_LDOSTP_Msk           (0x1UL)        /*!< LDOSTP (Bitfield-Mask: 0x01)                          */
/* =======================================================  PLL2LDOCR  ======================================================= */
#define R_SYSTEM_PLL2LDOCR_SKEEP_Pos            (1UL)          /*!< SKEEP (Bit 1)                                         */
#define R_SYSTEM_PLL2LDOCR_SKEEP_Msk            (0x2UL)        /*!< SKEEP (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_PLL2LDOCR_LDOSTP_Pos           (0UL)          /*!< LDOSTP (Bit 0)                                        */
#define R_SYSTEM_PLL2LDOCR_LDOSTP_Msk           (0x1UL)        /*!< LDOSTP (Bitfield-Mask: 0x01)                          */
/* =======================================================  HOCOLDOCR  ======================================================= */
#define R_SYSTEM_HOCOLDOCR_SKEEP_Pos            (1UL)          /*!< SKEEP (Bit 1)                                         */
#define R_SYSTEM_HOCOLDOCR_SKEEP_Msk            (0x2UL)        /*!< SKEEP (Bitfield-Mask: 0x01)                           */
#define R_SYSTEM_HOCOLDOCR_LDOSTP_Pos           (0UL)          /*!< LDOSTP (Bit 0)                                        */
#define R_SYSTEM_HOCOLDOCR_LDOSTP_Msk           (0x1UL)        /*!< LDOSTP (Bitfield-Mask: 0x01)                          */
/* =========================================================  LVOCR  ========================================================= */
#define R_SYSTEM_LVOCR_LVO0E_Pos                (0UL)          /*!< LVO0E (Bit 0)                                         */
#define R_SYSTEM_LVOCR_LVO0E_Msk                (0x1UL)        /*!< LVO0E (Bitfield-Mask: 0x01)                           */
/* =========================================================  VSCR  ========================================================== */
#define R_SYSTEM_VSCR_VSCMTSF_Pos               (4UL)          /*!< VSCMTSF (Bit 4)                                       */
#define R_SYSTEM_VSCR_VSCMTSF_Msk               (0x10UL)       /*!< VSCMTSF (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_VSCR_VSCM_Pos                  (0UL)          /*!< VSCM (Bit 0)                                          */
#define R_SYSTEM_VSCR_VSCM_Msk                  (0x7UL)        /*!< VSCM (Bitfield-Mask: 0x07)                            */
/* =========================================================  SVSCR  ========================================================= */
#define R_SYSTEM_SVSCR_SVSCM_Pos                (0UL)          /*!< SVSCM (Bit 0)                                         */
#define R_SYSTEM_SVSCR_SVSCM_Msk                (0x7UL)        /*!< SVSCM (Bitfield-Mask: 0x07)                           */
/* =========================================================  MWMCR  ========================================================= */
#define R_SYSTEM_MWMCR_MWM_Pos                  (0UL)          /*!< MWM (Bit 0)                                           */
#define R_SYSTEM_MWMCR_MWM_Msk                  (0x3UL)        /*!< MWM (Bitfield-Mask: 0x03)                             */
/* ========================================================  LDOECR  ========================================================= */
#define R_SYSTEM_LDOECR_EFUPTSF_Pos             (7UL)          /*!< EFUPTSF (Bit 7)                                       */
#define R_SYSTEM_LDOECR_EFUPTSF_Msk             (0x80UL)       /*!< EFUPTSF (Bitfield-Mask: 0x01)                         */
#define R_SYSTEM_LDOECR_EFUPE_Pos               (0UL)          /*!< EFUPE (Bit 0)                                         */
#define R_SYSTEM_LDOECR_EFUPE_Msk               (0x1UL)        /*!< EFUPE (Bitfield-Mask: 0x01)                           */
/* =========================================================  DCCR  ========================================================== */
#define R_SYSTEM_DCCR_WCODE_Pos                 (1UL)          /*!< WCODE (Bit 1)                                         */
#define R_SYSTEM_DCCR_WCODE_Msk                 (0xfeUL)       /*!< WCODE (Bitfield-Mask: 0x7f)                           */
#define R_SYSTEM_DCCR_DSTBYCON_Pos              (0UL)          /*!< DSTBYCON (Bit 0)                                      */
#define R_SYSTEM_DCCR_DSTBYCON_Msk              (0x1UL)        /*!< DSTBYCON (Bitfield-Mask: 0x01)                        */

/* =========================================================================================================================== */
/* ================                                        R_SYSTEM_NS                                        ================ */
/* =========================================================================================================================== */

/* ========================================================  PRCR_NS  ======================================================== */
#define R_SYSTEM_NS_PRCR_NS_PRKEY_Pos    (8UL)      /*!< PRKEY (Bit 8)                                         */
#define R_SYSTEM_NS_PRCR_NS_PRKEY_Msk    (0xff00UL) /*!< PRKEY (Bitfield-Mask: 0xff)                           */
#define R_SYSTEM_NS_PRCR_NS_PRC3_Pos     (3UL)      /*!< PRC3 (Bit 3)                                          */
#define R_SYSTEM_NS_PRCR_NS_PRC3_Msk     (0x8UL)    /*!< PRC3 (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_NS_PRCR_NS_PRC1_Pos     (1UL)      /*!< PRC1 (Bit 1)                                          */
#define R_SYSTEM_NS_PRCR_NS_PRC1_Msk     (0x2UL)    /*!< PRC1 (Bitfield-Mask: 0x01)                            */
#define R_SYSTEM_NS_PRCR_NS_PRC0_Pos     (0UL)      /*!< PRC0 (Bit 0)                                          */
#define R_SYSTEM_NS_PRCR_NS_PRC0_Msk     (0x1UL)    /*!< PRC0 (Bitfield-Mask: 0x01)                            */

/* =========================================================================================================================== */
/* ================                                          R_MSTP                                           ================ */
/* =========================================================================================================================== */

/* ========================================================  MSTPCRA  ======================================================== */
#define R_MSTP_MSTPCRA_MSTPA29_Pos    (29UL)         /*!< MSTPA29 (Bit 29)                                      */
#define R_MSTP_MSTPCRA_MSTPA29_Msk    (0x20000000UL) /*!< MSTPA29 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRA_MSTPA22_Pos    (22UL)         /*!< MSTPA22 (Bit 22)                                      */
#define R_MSTP_MSTPCRA_MSTPA22_Msk    (0x400000UL)   /*!< MSTPA22 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRA_MSTPA1_Pos     (1UL)          /*!< MSTPA1 (Bit 1)                                        */
#define R_MSTP_MSTPCRA_MSTPA1_Msk     (0x2UL)        /*!< MSTPA1 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRA_MSTPA0_Pos     (0UL)          /*!< MSTPA0 (Bit 0)                                        */
#define R_MSTP_MSTPCRA_MSTPA0_Msk     (0x1UL)        /*!< MSTPA0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  MSTPCRB  ======================================================== */
#define R_MSTP_MSTPCRB_MSTPB31_Pos    (31UL)         /*!< MSTPB31 (Bit 31)                                      */
#define R_MSTP_MSTPCRB_MSTPB31_Msk    (0x80000000UL) /*!< MSTPB31 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB30_Pos    (30UL)         /*!< MSTPB30 (Bit 30)                                      */
#define R_MSTP_MSTPCRB_MSTPB30_Msk    (0x40000000UL) /*!< MSTPB30 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB29_Pos    (29UL)         /*!< MSTPB29 (Bit 29)                                      */
#define R_MSTP_MSTPCRB_MSTPB29_Msk    (0x20000000UL) /*!< MSTPB29 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB28_Pos    (28UL)         /*!< MSTPB28 (Bit 28)                                      */
#define R_MSTP_MSTPCRB_MSTPB28_Msk    (0x10000000UL) /*!< MSTPB28 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB27_Pos    (27UL)         /*!< MSTPB27 (Bit 27)                                      */
#define R_MSTP_MSTPCRB_MSTPB27_Msk    (0x8000000UL)  /*!< MSTPB27 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB26_Pos    (26UL)         /*!< MSTPB26 (Bit 26)                                      */
#define R_MSTP_MSTPCRB_MSTPB26_Msk    (0x4000000UL)  /*!< MSTPB26 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB25_Pos    (25UL)         /*!< MSTPB25 (Bit 25)                                      */
#define R_MSTP_MSTPCRB_MSTPB25_Msk    (0x2000000UL)  /*!< MSTPB25 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB24_Pos    (24UL)         /*!< MSTPB24 (Bit 24)                                      */
#define R_MSTP_MSTPCRB_MSTPB24_Msk    (0x1000000UL)  /*!< MSTPB24 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB23_Pos    (23UL)         /*!< MSTPB23 (Bit 23)                                      */
#define R_MSTP_MSTPCRB_MSTPB23_Msk    (0x800000UL)   /*!< MSTPB23 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB22_Pos    (22UL)         /*!< MSTPB22 (Bit 22)                                      */
#define R_MSTP_MSTPCRB_MSTPB22_Msk    (0x400000UL)   /*!< MSTPB22 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB21_Pos    (21UL)         /*!< MSTPB21 (Bit 21)                                      */
#define R_MSTP_MSTPCRB_MSTPB21_Msk    (0x200000UL)   /*!< MSTPB21 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB20_Pos    (20UL)         /*!< MSTPB20 (Bit 20)                                      */
#define R_MSTP_MSTPCRB_MSTPB20_Msk    (0x100000UL)   /*!< MSTPB20 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB19_Pos    (19UL)         /*!< MSTPB19 (Bit 19)                                      */
#define R_MSTP_MSTPCRB_MSTPB19_Msk    (0x80000UL)    /*!< MSTPB19 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB18_Pos    (18UL)         /*!< MSTPB18 (Bit 18)                                      */
#define R_MSTP_MSTPCRB_MSTPB18_Msk    (0x40000UL)    /*!< MSTPB18 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB17_Pos    (17UL)         /*!< MSTPB17 (Bit 17)                                      */
#define R_MSTP_MSTPCRB_MSTPB17_Msk    (0x20000UL)    /*!< MSTPB17 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB16_Pos    (16UL)         /*!< MSTPB16 (Bit 16)                                      */
#define R_MSTP_MSTPCRB_MSTPB16_Msk    (0x10000UL)    /*!< MSTPB16 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB12_Pos    (12UL)         /*!< MSTPB12 (Bit 12)                                      */
#define R_MSTP_MSTPCRB_MSTPB12_Msk    (0x1000UL)     /*!< MSTPB12 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB11_Pos    (11UL)         /*!< MSTPB11 (Bit 11)                                      */
#define R_MSTP_MSTPCRB_MSTPB11_Msk    (0x800UL)      /*!< MSTPB11 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRB_MSTPB8_Pos     (8UL)          /*!< MSTPB8 (Bit 8)                                        */
#define R_MSTP_MSTPCRB_MSTPB8_Msk     (0x100UL)      /*!< MSTPB8 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRB_MSTPB7_Pos     (7UL)          /*!< MSTPB7 (Bit 7)                                        */
#define R_MSTP_MSTPCRB_MSTPB7_Msk     (0x80UL)       /*!< MSTPB7 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRB_MSTPB4_Pos     (4UL)          /*!< MSTPB4 (Bit 4)                                        */
#define R_MSTP_MSTPCRB_MSTPB4_Msk     (0x10UL)       /*!< MSTPB4 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRB_MSTPB0_Pos     (0UL)          /*!< MSTPB0 (Bit 0)                                        */
#define R_MSTP_MSTPCRB_MSTPB0_Msk     (0x1UL)        /*!< MSTPB0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  MSTPCRC  ======================================================== */
#define R_MSTP_MSTPCRC_MSTPC31_Pos    (31UL)         /*!< MSTPC31 (Bit 31)                                      */
#define R_MSTP_MSTPCRC_MSTPC31_Msk    (0x80000000UL) /*!< MSTPC31 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC30_Pos    (30UL)         /*!< MSTPC30 (Bit 30)                                      */
#define R_MSTP_MSTPCRC_MSTPC30_Msk    (0x40000000UL) /*!< MSTPC30 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC29_Pos    (29UL)         /*!< MSTPC29 (Bit 29)                                      */
#define R_MSTP_MSTPCRC_MSTPC29_Msk    (0x20000000UL) /*!< MSTPC29 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC28_Pos    (28UL)         /*!< MSTPC28 (Bit 28)                                      */
#define R_MSTP_MSTPCRC_MSTPC28_Msk    (0x10000000UL) /*!< MSTPC28 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC27_Pos    (27UL)         /*!< MSTPC27 (Bit 27)                                      */
#define R_MSTP_MSTPCRC_MSTPC27_Msk    (0x8000000UL)  /*!< MSTPC27 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC25_Pos    (25UL)         /*!< MSTPC25 (Bit 25)                                      */
#define R_MSTP_MSTPCRC_MSTPC25_Msk    (0x2000000UL)  /*!< MSTPC25 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC24_Pos    (24UL)         /*!< MSTPC24 (Bit 24)                                      */
#define R_MSTP_MSTPCRC_MSTPC24_Msk    (0x1000000UL)  /*!< MSTPC24 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC23_Pos    (23UL)         /*!< MSTPC23 (Bit 23)                                      */
#define R_MSTP_MSTPCRC_MSTPC23_Msk    (0x800000UL)   /*!< MSTPC23 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC14_Pos    (14UL)         /*!< MSTPC14 (Bit 14)                                      */
#define R_MSTP_MSTPCRC_MSTPC14_Msk    (0x4000UL)     /*!< MSTPC14 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC13_Pos    (13UL)         /*!< MSTPC13 (Bit 13)                                      */
#define R_MSTP_MSTPCRC_MSTPC13_Msk    (0x2000UL)     /*!< MSTPC13 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC12_Pos    (12UL)         /*!< MSTPC12 (Bit 12)                                      */
#define R_MSTP_MSTPCRC_MSTPC12_Msk    (0x1000UL)     /*!< MSTPC12 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRC_MSTPC8_Pos     (8UL)          /*!< MSTPC8 (Bit 8)                                        */
#define R_MSTP_MSTPCRC_MSTPC8_Msk     (0x100UL)      /*!< MSTPC8 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRC_MSTPC7_Pos     (7UL)          /*!< MSTPC7 (Bit 7)                                        */
#define R_MSTP_MSTPCRC_MSTPC7_Msk     (0x80UL)       /*!< MSTPC7 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRC_MSTPC2_Pos     (2UL)          /*!< MSTPC2 (Bit 2)                                        */
#define R_MSTP_MSTPCRC_MSTPC2_Msk     (0x4UL)        /*!< MSTPC2 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRC_MSTPC1_Pos     (1UL)          /*!< MSTPC1 (Bit 1)                                        */
#define R_MSTP_MSTPCRC_MSTPC1_Msk     (0x2UL)        /*!< MSTPC1 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRC_MSTPC0_Pos     (0UL)          /*!< MSTPC0 (Bit 0)                                        */
#define R_MSTP_MSTPCRC_MSTPC0_Msk     (0x1UL)        /*!< MSTPC0 (Bitfield-Mask: 0x01)                          */
/* ========================================================  MSTPCRD  ======================================================== */
#define R_MSTP_MSTPCRD_MSTPD22_Pos    (22UL)         /*!< MSTPD22 (Bit 22)                                      */
#define R_MSTP_MSTPCRD_MSTPD22_Msk    (0x400000UL)   /*!< MSTPD22 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRD_MSTPD21_Pos    (21UL)         /*!< MSTPD21 (Bit 21)                                      */
#define R_MSTP_MSTPCRD_MSTPD21_Msk    (0x200000UL)   /*!< MSTPD21 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRD_MSTPD20_Pos    (20UL)         /*!< MSTPD20 (Bit 20)                                      */
#define R_MSTP_MSTPCRD_MSTPD20_Msk    (0x100000UL)   /*!< MSTPD20 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRD_MSTPD19_Pos    (19UL)         /*!< MSTPD19 (Bit 19)                                      */
#define R_MSTP_MSTPCRD_MSTPD19_Msk    (0x80000UL)    /*!< MSTPD19 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRD_MSTPD14_Pos    (14UL)         /*!< MSTPD14 (Bit 14)                                      */
#define R_MSTP_MSTPCRD_MSTPD14_Msk    (0x4000UL)     /*!< MSTPD14 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRD_MSTPD13_Pos    (13UL)         /*!< MSTPD13 (Bit 13)                                      */
#define R_MSTP_MSTPCRD_MSTPD13_Msk    (0x2000UL)     /*!< MSTPD13 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRD_MSTPD12_Pos    (12UL)         /*!< MSTPD12 (Bit 12)                                      */
#define R_MSTP_MSTPCRD_MSTPD12_Msk    (0x1000UL)     /*!< MSTPD12 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRD_MSTPD11_Pos    (11UL)         /*!< MSTPD11 (Bit 11)                                      */
#define R_MSTP_MSTPCRD_MSTPD11_Msk    (0x800UL)      /*!< MSTPD11 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRD_MSTPD9_Pos     (9UL)          /*!< MSTPD9 (Bit 9)                                        */
#define R_MSTP_MSTPCRD_MSTPD9_Msk     (0x200UL)      /*!< MSTPD9 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRD_MSTPD8_Pos     (8UL)          /*!< MSTPD8 (Bit 8)                                        */
#define R_MSTP_MSTPCRD_MSTPD8_Msk     (0x100UL)      /*!< MSTPD8 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRD_MSTPD6_Pos     (6UL)          /*!< MSTPD6 (Bit 6)                                        */
#define R_MSTP_MSTPCRD_MSTPD6_Msk     (0x40UL)       /*!< MSTPD6 (Bitfield-Mask: 0x01)                          */
/* ========================================================  MSTPCRE  ======================================================== */
#define R_MSTP_MSTPCRE_MSTPE31_Pos    (31UL)         /*!< MSTPE31 (Bit 31)                                      */
#define R_MSTP_MSTPCRE_MSTPE31_Msk    (0x80000000UL) /*!< MSTPE31 (Bitfield-Mask: 0x01)                         */
/* ========================================================  MSTPCRF  ======================================================== */
#define R_MSTP_MSTPCRF_MSTPF31_Pos    (31UL)         /*!< MSTPF31 (Bit 31)                                      */
#define R_MSTP_MSTPCRF_MSTPF31_Msk    (0x80000000UL) /*!< MSTPF31 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRF_MSTPF30_Pos    (30UL)         /*!< MSTPF30 (Bit 30)                                      */
#define R_MSTP_MSTPCRF_MSTPF30_Msk    (0x40000000UL) /*!< MSTPF30 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRF_MSTPF16_Pos    (16UL)         /*!< MSTPF16 (Bit 16)                                      */
#define R_MSTP_MSTPCRF_MSTPF16_Msk    (0x10000UL)    /*!< MSTPF16 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRF_MSTPF15_Pos    (15UL)         /*!< MSTPF15 (Bit 15)                                      */
#define R_MSTP_MSTPCRF_MSTPF15_Msk    (0x8000UL)     /*!< MSTPF15 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRF_MSTPF14_Pos    (14UL)         /*!< MSTPF14 (Bit 14)                                      */
#define R_MSTP_MSTPCRF_MSTPF14_Msk    (0x4000UL)     /*!< MSTPF14 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRF_MSTPF13_Pos    (13UL)         /*!< MSTPF13 (Bit 13)                                      */
#define R_MSTP_MSTPCRF_MSTPF13_Msk    (0x2000UL)     /*!< MSTPF13 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRF_MSTPF12_Pos    (12UL)         /*!< MSTPF12 (Bit 12)                                      */
#define R_MSTP_MSTPCRF_MSTPF12_Msk    (0x1000UL)     /*!< MSTPF12 (Bitfield-Mask: 0x01)                         */
#define R_MSTP_MSTPCRF_MSTPF7_Pos     (7UL)          /*!< MSTPF7 (Bit 7)                                        */
#define R_MSTP_MSTPCRF_MSTPF7_Msk     (0x80UL)       /*!< MSTPF7 (Bitfield-Mask: 0x01)                          */
#define R_MSTP_MSTPCRF_MSTPF6_Pos     (6UL)          /*!< MSTPF6 (Bit 6)                                        */
#define R_MSTP_MSTPCRF_MSTPF6_Msk     (0x40UL)       /*!< MSTPF6 (Bitfield-Mask: 0x01)                          */

/** @} */ /* End of group PosMask_peripherals */

#endif /* R_SYSTEM_POSMSK_H */
