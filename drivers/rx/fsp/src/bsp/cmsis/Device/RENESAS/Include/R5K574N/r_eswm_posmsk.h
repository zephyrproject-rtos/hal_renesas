/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ESWM_POSMSK_H
#define R_ESWM_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_ESWM                                           ================ */
/* =========================================================================================================================== */

/* =======================================================  TPEMIMC0  ======================================================== */
#define R_ESWM_TPEMIMC0_SEIM_Pos        (0UL)          /*!< SEIM (Bit 0)                                          */
#define R_ESWM_TPEMIMC0_SEIM_Msk        (0x1UL)        /*!< SEIM (Bitfield-Mask: 0x01)                            */
#define R_ESWM_TPEMIMC0_SEIGM_Pos       (1UL)          /*!< SEIGM (Bit 1)                                         */
#define R_ESWM_TPEMIMC0_SEIGM_Msk       (0x2UL)        /*!< SEIGM (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC0_SEICM_Pos       (4UL)          /*!< SEICM (Bit 4)                                         */
#define R_ESWM_TPEMIMC0_SEICM_Msk       (0x70UL)       /*!< SEICM (Bitfield-Mask: 0x07)                           */
#define R_ESWM_TPEMIMC0_SSIM0_Pos       (16UL)         /*!< SSIM0 (Bit 16)                                        */
#define R_ESWM_TPEMIMC0_SSIM0_Msk       (0x10000UL)    /*!< SSIM0 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC0_SSIGM0_Pos      (17UL)         /*!< SSIGM0 (Bit 17)                                       */
#define R_ESWM_TPEMIMC0_SSIGM0_Msk      (0x20000UL)    /*!< SSIGM0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC0_SSICM0_Pos      (20UL)         /*!< SSICM0 (Bit 20)                                       */
#define R_ESWM_TPEMIMC0_SSICM0_Msk      (0x700000UL)   /*!< SSICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC0_SSIM1_Pos       (24UL)         /*!< SSIM1 (Bit 24)                                        */
#define R_ESWM_TPEMIMC0_SSIM1_Msk       (0x1000000UL)  /*!< SSIM1 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC0_SSIGM1_Pos      (25UL)         /*!< SSIGM1 (Bit 25)                                       */
#define R_ESWM_TPEMIMC0_SSIGM1_Msk      (0x2000000UL)  /*!< SSIGM1 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC0_SSICM1_Pos      (28UL)         /*!< SSICM1 (Bit 28)                                       */
#define R_ESWM_TPEMIMC0_SSICM1_Msk      (0x70000000UL) /*!< SSICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC1  ======================================================== */
#define R_ESWM_TPEMIMC1_FEIM_Pos        (0UL)          /*!< FEIM (Bit 0)                                          */
#define R_ESWM_TPEMIMC1_FEIM_Msk        (0x1UL)        /*!< FEIM (Bitfield-Mask: 0x01)                            */
#define R_ESWM_TPEMIMC1_FEIGM_Pos       (1UL)          /*!< FEIGM (Bit 1)                                         */
#define R_ESWM_TPEMIMC1_FEIGM_Msk       (0x2UL)        /*!< FEIGM (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC1_FEICM_Pos       (4UL)          /*!< FEICM (Bit 4)                                         */
#define R_ESWM_TPEMIMC1_FEICM_Msk       (0x70UL)       /*!< FEICM (Bitfield-Mask: 0x07)                           */
#define R_ESWM_TPEMIMC1_FSIM_Pos        (8UL)          /*!< FSIM (Bit 8)                                          */
#define R_ESWM_TPEMIMC1_FSIM_Msk        (0x100UL)      /*!< FSIM (Bitfield-Mask: 0x01)                            */
#define R_ESWM_TPEMIMC1_FSIGM_Pos       (9UL)          /*!< FSIGM (Bit 9)                                         */
#define R_ESWM_TPEMIMC1_FSIGM_Msk       (0x200UL)      /*!< FSIGM (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC1_FSICM_Pos       (12UL)         /*!< FSICM (Bit 12)                                        */
#define R_ESWM_TPEMIMC1_FSICM_Msk       (0x7000UL)     /*!< FSICM (Bitfield-Mask: 0x07)                           */
#define R_ESWM_TPEMIMC1_CEIM_Pos        (16UL)         /*!< CEIM (Bit 16)                                         */
#define R_ESWM_TPEMIMC1_CEIM_Msk        (0x10000UL)    /*!< CEIM (Bitfield-Mask: 0x01)                            */
#define R_ESWM_TPEMIMC1_CEIGM_Pos       (17UL)         /*!< CEIGM (Bit 17)                                        */
#define R_ESWM_TPEMIMC1_CEIGM_Msk       (0x20000UL)    /*!< CEIGM (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC1_CEICM_Pos       (20UL)         /*!< CEICM (Bit 20)                                        */
#define R_ESWM_TPEMIMC1_CEICM_Msk       (0x700000UL)   /*!< CEICM (Bitfield-Mask: 0x07)                           */
#define R_ESWM_TPEMIMC1_CSIM_Pos        (24UL)         /*!< CSIM (Bit 24)                                         */
#define R_ESWM_TPEMIMC1_CSIM_Msk        (0x1000000UL)  /*!< CSIM (Bitfield-Mask: 0x01)                            */
#define R_ESWM_TPEMIMC1_CSIGM_Pos       (25UL)         /*!< CSIGM (Bit 25)                                        */
#define R_ESWM_TPEMIMC1_CSIGM_Msk       (0x2000000UL)  /*!< CSIGM (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC1_CSICM_Pos       (28UL)         /*!< CSICM (Bit 28)                                        */
#define R_ESWM_TPEMIMC1_CSICM_Msk       (0x70000000UL) /*!< CSICM (Bitfield-Mask: 0x07)                           */
/* =======================================================  TPEMIMC2  ======================================================== */
#define R_ESWM_TPEMIMC2_GEIM0_Pos       (0UL)          /*!< GEIM0 (Bit 0)                                         */
#define R_ESWM_TPEMIMC2_GEIM0_Msk       (0x1UL)        /*!< GEIM0 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC2_GEIGM0_Pos      (1UL)          /*!< GEIGM0 (Bit 1)                                        */
#define R_ESWM_TPEMIMC2_GEIGM0_Msk      (0x2UL)        /*!< GEIGM0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC2_GEICM0_Pos      (4UL)          /*!< GEICM0 (Bit 4)                                        */
#define R_ESWM_TPEMIMC2_GEICM0_Msk      (0x70UL)       /*!< GEICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC2_GSIM0_Pos       (8UL)          /*!< GSIM0 (Bit 8)                                         */
#define R_ESWM_TPEMIMC2_GSIM0_Msk       (0x100UL)      /*!< GSIM0 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC2_GSIGM0_Pos      (9UL)          /*!< GSIGM0 (Bit 9)                                        */
#define R_ESWM_TPEMIMC2_GSIGM0_Msk      (0x200UL)      /*!< GSIGM0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC2_GSICM0_Pos      (12UL)         /*!< GSICM0 (Bit 12)                                       */
#define R_ESWM_TPEMIMC2_GSICM0_Msk      (0x7000UL)     /*!< GSICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC2_GEIM1_Pos       (16UL)         /*!< GEIM1 (Bit 16)                                        */
#define R_ESWM_TPEMIMC2_GEIM1_Msk       (0x10000UL)    /*!< GEIM1 (Bitfield-Mask: 0x01)                           */
/* =======================================================  TPEMIMC3  ======================================================== */
#define R_ESWM_TPEMIMC3_EEIM0_Pos       (0UL)          /*!< EEIM0 (Bit 0)                                         */
#define R_ESWM_TPEMIMC3_EEIM0_Msk       (0x1UL)        /*!< EEIM0 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC3_EEIGM0_Pos      (1UL)          /*!< EEIGM0 (Bit 1)                                        */
#define R_ESWM_TPEMIMC3_EEIGM0_Msk      (0x2UL)        /*!< EEIGM0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC3_EEICM0_Pos      (4UL)          /*!< EEICM0 (Bit 4)                                        */
#define R_ESWM_TPEMIMC3_EEICM0_Msk      (0x70UL)       /*!< EEICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC3_ESIM0_Pos       (8UL)          /*!< ESIM0 (Bit 8)                                         */
#define R_ESWM_TPEMIMC3_ESIM0_Msk       (0x100UL)      /*!< ESIM0 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC3_ESIGM0_Pos      (9UL)          /*!< ESIGM0 (Bit 9)                                        */
#define R_ESWM_TPEMIMC3_ESIGM0_Msk      (0x200UL)      /*!< ESIGM0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC3_ESICM0_Pos      (12UL)         /*!< ESICM0 (Bit 12)                                       */
#define R_ESWM_TPEMIMC3_ESICM0_Msk      (0x7000UL)     /*!< ESICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC3_RSIM0_Pos       (16UL)         /*!< RSIM0 (Bit 16)                                        */
#define R_ESWM_TPEMIMC3_RSIM0_Msk       (0x10000UL)    /*!< RSIM0 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC3_RSIGM0_Pos      (17UL)         /*!< RSIGM0 (Bit 17)                                       */
#define R_ESWM_TPEMIMC3_RSIGM0_Msk      (0x20000UL)    /*!< RSIGM0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC3_RSICM0_Pos      (20UL)         /*!< RSICM0 (Bit 20)                                       */
#define R_ESWM_TPEMIMC3_RSICM0_Msk      (0x700000UL)   /*!< RSICM0 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC4  ======================================================== */
#define R_ESWM_TPEMIMC4_EEIM1_Pos       (0UL)          /*!< EEIM1 (Bit 0)                                         */
#define R_ESWM_TPEMIMC4_EEIM1_Msk       (0x1UL)        /*!< EEIM1 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC4_EEIGM1_Pos      (1UL)          /*!< EEIGM1 (Bit 1)                                        */
#define R_ESWM_TPEMIMC4_EEIGM1_Msk      (0x2UL)        /*!< EEIGM1 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC4_EEICM1_Pos      (4UL)          /*!< EEICM1 (Bit 4)                                        */
#define R_ESWM_TPEMIMC4_EEICM1_Msk      (0x70UL)       /*!< EEICM1 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC4_ESIM1_Pos       (8UL)          /*!< ESIM1 (Bit 8)                                         */
#define R_ESWM_TPEMIMC4_ESIM1_Msk       (0x100UL)      /*!< ESIM1 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC4_ESIGM1_Pos      (9UL)          /*!< ESIGM1 (Bit 9)                                        */
#define R_ESWM_TPEMIMC4_ESIGM1_Msk      (0x200UL)      /*!< ESIGM1 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC4_ESICM1_Pos      (12UL)         /*!< ESICM1 (Bit 12)                                       */
#define R_ESWM_TPEMIMC4_ESICM1_Msk      (0x7000UL)     /*!< ESICM1 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC4_RSIM1_Pos       (16UL)         /*!< RSIM1 (Bit 16)                                        */
#define R_ESWM_TPEMIMC4_RSIM1_Msk       (0x10000UL)    /*!< RSIM1 (Bitfield-Mask: 0x01)                           */
#define R_ESWM_TPEMIMC4_RSIGM1_Pos      (17UL)         /*!< RSIGM1 (Bit 17)                                       */
#define R_ESWM_TPEMIMC4_RSIGM1_Msk      (0x20000UL)    /*!< RSIGM1 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC4_RSICM1_Pos      (20UL)         /*!< RSICM1 (Bit 20)                                       */
#define R_ESWM_TPEMIMC4_RSICM1_Msk      (0x700000UL)   /*!< RSICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC60  ======================================================= */
#define R_ESWM_TPEMIMC60_GTSIM0_Pos     (0UL)          /*!< GTSIM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC60_GTSIM0_Msk     (0x1UL)        /*!< GTSIM0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC60_GTSICM0_Pos    (1UL)          /*!< GTSICM0 (Bit 1)                                       */
#define R_ESWM_TPEMIMC60_GTSICM0_Msk    (0xeUL)        /*!< GTSICM0 (Bitfield-Mask: 0x07)                         */
/* =======================================================  TPEMIMC61  ======================================================= */
#define R_ESWM_TPEMIMC61_GTSIM0_Pos     (0UL)          /*!< GTSIM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC61_GTSIM0_Msk     (0x1UL)        /*!< GTSIM0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TPEMIMC61_GTSICM0_Pos    (1UL)          /*!< GTSICM0 (Bit 1)                                       */
#define R_ESWM_TPEMIMC61_GTSICM0_Msk    (0xeUL)        /*!< GTSICM0 (Bitfield-Mask: 0x07)                         */
/* =======================================================  TPEMIMC70  ======================================================= */
#define R_ESWM_TPEMIMC70_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC70_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC70_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC70_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC71  ======================================================= */
#define R_ESWM_TPEMIMC71_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC71_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC71_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC71_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC72  ======================================================= */
#define R_ESWM_TPEMIMC72_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC72_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC72_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC72_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC73  ======================================================= */
#define R_ESWM_TPEMIMC73_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC73_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC73_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC73_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC74  ======================================================= */
#define R_ESWM_TPEMIMC74_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC74_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC74_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC74_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC75  ======================================================= */
#define R_ESWM_TPEMIMC75_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC75_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC75_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC75_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC76  ======================================================= */
#define R_ESWM_TPEMIMC76_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC76_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC76_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC76_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC77  ======================================================= */
#define R_ESWM_TPEMIMC77_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC77_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC77_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC77_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC78  ======================================================= */
#define R_ESWM_TPEMIMC78_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC78_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC78_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC78_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* =======================================================  TPEMIMC79  ======================================================= */
#define R_ESWM_TPEMIMC79_GDICM0_Pos     (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC79_GDICM0_Msk     (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
#define R_ESWM_TPEMIMC79_GDICM1_Pos     (8UL)          /*!< GDICM1 (Bit 8)                                        */
#define R_ESWM_TPEMIMC79_GDICM1_Msk     (0x700UL)      /*!< GDICM1 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC710  ======================================================= */
#define R_ESWM_TPEMIMC710_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC710_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC711  ======================================================= */
#define R_ESWM_TPEMIMC711_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC711_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC712  ======================================================= */
#define R_ESWM_TPEMIMC712_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC712_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC713  ======================================================= */
#define R_ESWM_TPEMIMC713_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC713_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC714  ======================================================= */
#define R_ESWM_TPEMIMC714_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC714_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC715  ======================================================= */
#define R_ESWM_TPEMIMC715_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC715_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC716  ======================================================= */
#define R_ESWM_TPEMIMC716_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC716_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC717  ======================================================= */
#define R_ESWM_TPEMIMC717_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC717_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC718  ======================================================= */
#define R_ESWM_TPEMIMC718_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC718_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC719  ======================================================= */
#define R_ESWM_TPEMIMC719_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC719_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC720  ======================================================= */
#define R_ESWM_TPEMIMC720_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC720_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC721  ======================================================= */
#define R_ESWM_TPEMIMC721_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC721_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC722  ======================================================= */
#define R_ESWM_TPEMIMC722_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC722_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC723  ======================================================= */
#define R_ESWM_TPEMIMC723_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC723_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC724  ======================================================= */
#define R_ESWM_TPEMIMC724_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC724_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC725  ======================================================= */
#define R_ESWM_TPEMIMC725_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC725_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC726  ======================================================= */
#define R_ESWM_TPEMIMC726_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC726_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC727  ======================================================= */
#define R_ESWM_TPEMIMC727_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC727_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC728  ======================================================= */
#define R_ESWM_TPEMIMC728_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC728_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC729  ======================================================= */
#define R_ESWM_TPEMIMC729_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC729_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC730  ======================================================= */
#define R_ESWM_TPEMIMC730_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC730_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC731  ======================================================= */
#define R_ESWM_TPEMIMC731_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC731_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC732  ======================================================= */
#define R_ESWM_TPEMIMC732_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC732_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC733  ======================================================= */
#define R_ESWM_TPEMIMC733_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC733_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC734  ======================================================= */
#define R_ESWM_TPEMIMC734_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC734_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC735  ======================================================= */
#define R_ESWM_TPEMIMC735_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC735_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC736  ======================================================= */
#define R_ESWM_TPEMIMC736_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC736_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC737  ======================================================= */
#define R_ESWM_TPEMIMC737_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC737_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC738  ======================================================= */
#define R_ESWM_TPEMIMC738_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC738_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC739  ======================================================= */
#define R_ESWM_TPEMIMC739_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC739_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC740  ======================================================= */
#define R_ESWM_TPEMIMC740_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC740_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC741  ======================================================= */
#define R_ESWM_TPEMIMC741_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC741_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC742  ======================================================= */
#define R_ESWM_TPEMIMC742_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC742_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC743  ======================================================= */
#define R_ESWM_TPEMIMC743_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC743_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC744  ======================================================= */
#define R_ESWM_TPEMIMC744_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC744_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC745  ======================================================= */
#define R_ESWM_TPEMIMC745_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC745_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC746  ======================================================= */
#define R_ESWM_TPEMIMC746_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC746_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC747  ======================================================= */
#define R_ESWM_TPEMIMC747_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC747_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC748  ======================================================= */
#define R_ESWM_TPEMIMC748_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC748_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC749  ======================================================= */
#define R_ESWM_TPEMIMC749_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC749_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC750  ======================================================= */
#define R_ESWM_TPEMIMC750_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC750_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC751  ======================================================= */
#define R_ESWM_TPEMIMC751_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC751_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC752  ======================================================= */
#define R_ESWM_TPEMIMC752_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC752_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC753  ======================================================= */
#define R_ESWM_TPEMIMC753_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC753_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC754  ======================================================= */
#define R_ESWM_TPEMIMC754_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC754_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC755  ======================================================= */
#define R_ESWM_TPEMIMC755_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC755_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC756  ======================================================= */
#define R_ESWM_TPEMIMC756_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC756_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC757  ======================================================= */
#define R_ESWM_TPEMIMC757_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC757_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC758  ======================================================= */
#define R_ESWM_TPEMIMC758_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC758_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC759  ======================================================= */
#define R_ESWM_TPEMIMC759_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC759_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC760  ======================================================= */
#define R_ESWM_TPEMIMC760_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC760_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC761  ======================================================= */
#define R_ESWM_TPEMIMC761_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC761_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC762  ======================================================= */
#define R_ESWM_TPEMIMC762_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC762_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* ======================================================  TPEMIMC763  ======================================================= */
#define R_ESWM_TPEMIMC763_GDICM0_Pos    (0UL)          /*!< GDICM0 (Bit 0)                                        */
#define R_ESWM_TPEMIMC763_GDICM0_Msk    (0x7UL)        /*!< GDICM0 (Bitfield-Mask: 0x07)                          */
/* =========================================================  TSIM  ========================================================== */
#define R_ESWM_TSIM_FWM_Pos             (0UL)          /*!< FWM (Bit 0)                                           */
#define R_ESWM_TSIM_FWM_Msk             (0x1UL)        /*!< FWM (Bitfield-Mask: 0x01)                             */
#define R_ESWM_TSIM_CIM_Pos             (1UL)          /*!< CIM (Bit 1)                                           */
#define R_ESWM_TSIM_CIM_Msk             (0x2UL)        /*!< CIM (Bitfield-Mask: 0x01)                             */
#define R_ESWM_TSIM_GIM0_Pos            (2UL)          /*!< GIM0 (Bit 2)                                          */
#define R_ESWM_TSIM_GIM0_Msk            (0x4UL)        /*!< GIM0 (Bitfield-Mask: 0x01)                            */
#define R_ESWM_TSIM_EIM0_Pos            (4UL)          /*!< EIM0 (Bit 4)                                          */
#define R_ESWM_TSIM_EIM0_Msk            (0x10UL)       /*!< EIM0 (Bitfield-Mask: 0x01)                            */
#define R_ESWM_TSIM_EIM1_Pos            (5UL)          /*!< EIM1 (Bit 5)                                          */
#define R_ESWM_TSIM_EIM1_Msk            (0x20UL)       /*!< EIM1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  TFIM  ========================================================== */
#define R_ESWM_TFIM_FWEISIM0_Pos        (0UL)          /*!< FWEISIM0 (Bit 0)                                      */
#define R_ESWM_TFIM_FWEISIM0_Msk        (0x1UL)        /*!< FWEISIM0 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TFIM_FWEISIM1_Pos        (1UL)          /*!< FWEISIM1 (Bit 1)                                      */
#define R_ESWM_TFIM_FWEISIM1_Msk        (0x2UL)        /*!< FWEISIM1 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TFIM_FWEISIM2_Pos        (2UL)          /*!< FWEISIM2 (Bit 2)                                      */
#define R_ESWM_TFIM_FWEISIM2_Msk        (0x4UL)        /*!< FWEISIM2 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TFIM_FWEISIM3_Pos        (3UL)          /*!< FWEISIM3 (Bit 3)                                      */
#define R_ESWM_TFIM_FWEISIM3_Msk        (0x8UL)        /*!< FWEISIM3 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TFIM_FWEISIM4_Pos        (4UL)          /*!< FWEISIM4 (Bit 4)                                      */
#define R_ESWM_TFIM_FWEISIM4_Msk        (0x10UL)       /*!< FWEISIM4 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TFIM_FWEISIM5_Pos        (5UL)          /*!< FWEISIM5 (Bit 5)                                      */
#define R_ESWM_TFIM_FWEISIM5_Msk        (0x20UL)       /*!< FWEISIM5 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TFIM_FWEISIM6_Pos        (6UL)          /*!< FWEISIM6 (Bit 6)                                      */
#define R_ESWM_TFIM_FWEISIM6_Msk        (0x40UL)       /*!< FWEISIM6 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TFIM_FWEISIM7_Pos        (7UL)          /*!< FWEISIM7 (Bit 7)                                      */
#define R_ESWM_TFIM_FWEISIM7_Msk        (0x80UL)       /*!< FWEISIM7 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TFIM_FWEISIM8_Pos        (8UL)          /*!< FWEISIM8 (Bit 8)                                      */
#define R_ESWM_TFIM_FWEISIM8_Msk        (0x100UL)      /*!< FWEISIM8 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TFIM_FWMISIM0_Pos        (9UL)          /*!< FWMISIM0 (Bit 9)                                      */
#define R_ESWM_TFIM_FWMISIM0_Msk        (0x200UL)      /*!< FWMISIM0 (Bitfield-Mask: 0x01)                        */
/* =========================================================  TCIM  ========================================================== */
#define R_ESWM_TCIM_RSSISIM_Pos         (0UL)          /*!< RSSISIM (Bit 0)                                       */
#define R_ESWM_TCIM_RSSISIM_Msk         (0x1UL)        /*!< RSSISIM (Bitfield-Mask: 0x01)                         */
#define R_ESWM_TCIM_CAEISIM0_Pos        (1UL)          /*!< CAEISIM0 (Bit 1)                                      */
#define R_ESWM_TCIM_CAEISIM0_Msk        (0x2UL)        /*!< CAEISIM0 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TCIM_CAEISIM1_Pos        (2UL)          /*!< CAEISIM1 (Bit 2)                                      */
#define R_ESWM_TCIM_CAEISIM1_Msk        (0x4UL)        /*!< CAEISIM1 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TCIM_CAMISIM0_Pos        (3UL)          /*!< CAMISIM0 (Bit 3)                                      */
#define R_ESWM_TCIM_CAMISIM0_Msk        (0x8UL)        /*!< CAMISIM0 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TCIM_CAMISIM1_Pos        (4UL)          /*!< CAMISIM1 (Bit 4)                                      */
#define R_ESWM_TCIM_CAMISIM1_Msk        (0x10UL)       /*!< CAMISIM1 (Bitfield-Mask: 0x01)                        */
/* =========================================================  TGIM0  ========================================================= */
#define R_ESWM_TGIM0_GWDISIM_Pos        (0UL)          /*!< GWDISIM (Bit 0)                                       */
#define R_ESWM_TGIM0_GWDISIM_Msk        (0x1UL)        /*!< GWDISIM (Bitfield-Mask: 0x01)                         */
#define R_ESWM_TGIM0_GWTSDISIM_Pos      (1UL)          /*!< GWTSDISIM (Bit 1)                                     */
#define R_ESWM_TGIM0_GWTSDISIM_Msk      (0x2UL)        /*!< GWTSDISIM (Bitfield-Mask: 0x01)                       */
#define R_ESWM_TGIM0_GWEISIM0_Pos       (2UL)          /*!< GWEISIM0 (Bit 2)                                      */
#define R_ESWM_TGIM0_GWEISIM0_Msk       (0x4UL)        /*!< GWEISIM0 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TGIM0_GWEISIM1_Pos       (3UL)          /*!< GWEISIM1 (Bit 3)                                      */
#define R_ESWM_TGIM0_GWEISIM1_Msk       (0x8UL)        /*!< GWEISIM1 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TGIM0_GWEISIM2_Pos       (4UL)          /*!< GWEISIM2 (Bit 4)                                      */
#define R_ESWM_TGIM0_GWEISIM2_Msk       (0x10UL)       /*!< GWEISIM2 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TGIM0_GWEISIM3_Pos       (5UL)          /*!< GWEISIM3 (Bit 5)                                      */
#define R_ESWM_TGIM0_GWEISIM3_Msk       (0x20UL)       /*!< GWEISIM3 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TGIM0_GWEISIM4_Pos       (6UL)          /*!< GWEISIM4 (Bit 6)                                      */
#define R_ESWM_TGIM0_GWEISIM4_Msk       (0x40UL)       /*!< GWEISIM4 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TGIM0_GWEISIM5_Pos       (7UL)          /*!< GWEISIM5 (Bit 7)                                      */
#define R_ESWM_TGIM0_GWEISIM5_Msk       (0x80UL)       /*!< GWEISIM5 (Bitfield-Mask: 0x01)                        */
/* =========================================================  TEIM0  ========================================================= */
#define R_ESWM_TEIM0_EAEISIM0_Pos       (0UL)          /*!< EAEISIM0 (Bit 0)                                      */
#define R_ESWM_TEIM0_EAEISIM0_Msk       (0x1UL)        /*!< EAEISIM0 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TEIM0_EAEISIM1_Pos       (1UL)          /*!< EAEISIM1 (Bit 1)                                      */
#define R_ESWM_TEIM0_EAEISIM1_Msk       (0x2UL)        /*!< EAEISIM1 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TEIM0_EAEISIM2_Pos       (2UL)          /*!< EAEISIM2 (Bit 2)                                      */
#define R_ESWM_TEIM0_EAEISIM2_Msk       (0x4UL)        /*!< EAEISIM2 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TEIM0_MEISIM_Pos         (3UL)          /*!< MEISIM (Bit 3)                                        */
#define R_ESWM_TEIM0_MEISIM_Msk         (0x8UL)        /*!< MEISIM (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TEIM0_MMISIM_Pos         (4UL)          /*!< MMISIM (Bit 4)                                        */
#define R_ESWM_TEIM0_MMISIM_Msk         (0x10UL)       /*!< MMISIM (Bitfield-Mask: 0x01)                          */
/* =========================================================  TEIM1  ========================================================= */
#define R_ESWM_TEIM1_EAEISIM0_Pos       (0UL)          /*!< EAEISIM0 (Bit 0)                                      */
#define R_ESWM_TEIM1_EAEISIM0_Msk       (0x1UL)        /*!< EAEISIM0 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TEIM1_EAEISIM1_Pos       (1UL)          /*!< EAEISIM1 (Bit 1)                                      */
#define R_ESWM_TEIM1_EAEISIM1_Msk       (0x2UL)        /*!< EAEISIM1 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TEIM1_EAEISIM2_Pos       (2UL)          /*!< EAEISIM2 (Bit 2)                                      */
#define R_ESWM_TEIM1_EAEISIM2_Msk       (0x4UL)        /*!< EAEISIM2 (Bitfield-Mask: 0x01)                        */
#define R_ESWM_TEIM1_MEISIM_Pos         (3UL)          /*!< MEISIM (Bit 3)                                        */
#define R_ESWM_TEIM1_MEISIM_Msk         (0x8UL)        /*!< MEISIM (Bitfield-Mask: 0x01)                          */
#define R_ESWM_TEIM1_MMISIM_Pos         (4UL)          /*!< MMISIM (Bit 4)                                        */
#define R_ESWM_TEIM1_MMISIM_Msk         (0x10UL)       /*!< MMISIM (Bitfield-Mask: 0x01)                          */
/* =========================================================  MIIRR  ========================================================= */
#define R_ESWM_MIIRR_RGRST0_Pos         (0UL)          /*!< RGRST0 (Bit 0)                                        */
#define R_ESWM_MIIRR_RGRST0_Msk         (0x1UL)        /*!< RGRST0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_MIIRR_RGRST1_Pos         (1UL)          /*!< RGRST1 (Bit 1)                                        */
#define R_ESWM_MIIRR_RGRST1_Msk         (0x2UL)        /*!< RGRST1 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_MIIRR_RMRST0_Pos         (8UL)          /*!< RMRST0 (Bit 8)                                        */
#define R_ESWM_MIIRR_RMRST0_Msk         (0x100UL)      /*!< RMRST0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_MIIRR_RMRST1_Pos         (9UL)          /*!< RMRST1 (Bit 9)                                        */
#define R_ESWM_MIIRR_RMRST1_Msk         (0x200UL)      /*!< RMRST1 (Bitfield-Mask: 0x01)                          */
/* ========================================================  MIICR0  ========================================================= */
#define R_ESWM_MIICR0_MIISEL_Pos        (0UL)          /*!< MIISEL (Bit 0)                                        */
#define R_ESWM_MIICR0_MIISEL_Msk        (0x3UL)        /*!< MIISEL (Bitfield-Mask: 0x03)                          */
#define R_ESWM_MIICR0_DIVSTP_Pos        (8UL)          /*!< DIVSTP (Bit 8)                                        */
#define R_ESWM_MIICR0_DIVSTP_Msk        (0x100UL)      /*!< DIVSTP (Bitfield-Mask: 0x01)                          */
#define R_ESWM_MIICR0_TXCIDE_Pos        (12UL)         /*!< TXCIDE (Bit 12)                                       */
#define R_ESWM_MIICR0_TXCIDE_Msk        (0x1000UL)     /*!< TXCIDE (Bitfield-Mask: 0x01)                          */
/* ========================================================  MIICR1  ========================================================= */
#define R_ESWM_MIICR1_MIISEL_Pos        (0UL)          /*!< MIISEL (Bit 0)                                        */
#define R_ESWM_MIICR1_MIISEL_Msk        (0x3UL)        /*!< MIISEL (Bitfield-Mask: 0x03)                          */
#define R_ESWM_MIICR1_DIVSTP_Pos        (8UL)          /*!< DIVSTP (Bit 8)                                        */
#define R_ESWM_MIICR1_DIVSTP_Msk        (0x100UL)      /*!< DIVSTP (Bitfield-Mask: 0x01)                          */
#define R_ESWM_MIICR1_TXCIDE_Pos        (12UL)         /*!< TXCIDE (Bit 12)                                       */
#define R_ESWM_MIICR1_TXCIDE_Msk        (0x1000UL)     /*!< TXCIDE (Bitfield-Mask: 0x01)                          */
/* ========================================================  MCCESR  ========================================================= */
#define R_ESWM_MCCESR_MCCES0_Pos        (0UL)          /*!< MCCES0 (Bit 0)                                        */
#define R_ESWM_MCCESR_MCCES0_Msk        (0x1UL)        /*!< MCCES0 (Bitfield-Mask: 0x01)                          */
#define R_ESWM_MCCESR_MCCES1_Pos        (1UL)          /*!< MCCES1 (Bit 1)                                        */
#define R_ESWM_MCCESR_MCCES1_Msk        (0x2UL)        /*!< MCCES1 (Bitfield-Mask: 0x01)                          */
/* ========================================================  TASSTSR  ======================================================== */
#define R_ESWM_TASSTSR_MSS0_Pos         (0UL)          /*!< MSS0 (Bit 0)                                          */
#define R_ESWM_TASSTSR_MSS0_Msk         (0x1fUL)       /*!< MSS0 (Bitfield-Mask: 0x1f)                            */
#define R_ESWM_TASSTSR_MSS1_Pos         (8UL)          /*!< MSS1 (Bit 8)                                          */
#define R_ESWM_TASSTSR_MSS1_Msk         (0x1f00UL)     /*!< MSS1 (Bitfield-Mask: 0x1f)                            */
#define R_ESWM_TASSTSR_MSS2_Pos         (16UL)         /*!< MSS2 (Bit 16)                                         */
#define R_ESWM_TASSTSR_MSS2_Msk         (0x1f0000UL)   /*!< MSS2 (Bitfield-Mask: 0x1f)                            */
#define R_ESWM_TASSTSR_MSS3_Pos         (24UL)         /*!< MSS3 (Bit 24)                                         */
#define R_ESWM_TASSTSR_MSS3_Msk         (0x1f000000UL) /*!< MSS3 (Bitfield-Mask: 0x1f)                            */

/** @} */ /* End of group PosMask_peripherals */

#endif                                                 /* R_ESWM_POSMSK_H */
