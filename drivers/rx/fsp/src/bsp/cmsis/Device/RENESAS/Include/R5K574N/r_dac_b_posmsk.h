/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DAC_B_POSMSK_H
#define R_DAC_B_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          R_DAC_B0                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  DADR  ========================================================== */
/* =========================================================  DACR0  ========================================================= */
#define R_DAC_B0_DACR0_DAOUTDIS_Pos    (31UL)         /*!< DAOUTDIS (Bit 31)                                     */
#define R_DAC_B0_DACR0_DAOUTDIS_Msk    (0x80000000UL) /*!< DAOUTDIS (Bitfield-Mask: 0x01)                        */
#define R_DAC_B0_DACR0_DAOUTEN_Pos     (30UL)         /*!< DAOUTEN (Bit 30)                                      */
#define R_DAC_B0_DACR0_DAOUTEN_Msk     (0x40000000UL) /*!< DAOUTEN (Bitfield-Mask: 0x01)                         */
#define R_DAC_B0_DACR0_DAOE_Pos        (28UL)         /*!< DAOE (Bit 28)                                         */
#define R_DAC_B0_DACR0_DAOE_Msk        (0x10000000UL) /*!< DAOE (Bitfield-Mask: 0x01)                            */
#define R_DAC_B0_DACR0_DAE_Pos         (15UL)         /*!< DAE (Bit 15)                                          */
#define R_DAC_B0_DACR0_DAE_Msk         (0x8000UL)     /*!< DAE (Bitfield-Mask: 0x01)                             */
#define R_DAC_B0_DACR0_DACEN_Pos       (0UL)          /*!< DACEN (Bit 0)                                         */
#define R_DAC_B0_DACR0_DACEN_Msk       (0x1UL)        /*!< DACEN (Bitfield-Mask: 0x01)                           */
/* =========================================================  DACR1  ========================================================= */
#define R_DAC_B0_DACR1_DPSEL_Pos       (16UL)         /*!< DPSEL (Bit 16)                                        */
#define R_DAC_B0_DACR1_DPSEL_Msk       (0x10000UL)    /*!< DPSEL (Bitfield-Mask: 0x01)                           */
/* =========================================================  DACR2  ========================================================= */
#define R_DAC_B0_DACR2_DAAMP_Pos       (31UL)         /*!< DAAMP (Bit 31)                                        */
#define R_DAC_B0_DACR2_DAAMP_Msk       (0x80000000UL) /*!< DAAMP (Bitfield-Mask: 0x01)                           */
#define R_DAC_B0_DACR2_OFSSEL_Pos      (8UL)          /*!< OFSSEL (Bit 8)                                        */
#define R_DAC_B0_DACR2_OFSSEL_Msk      (0x100UL)      /*!< OFSSEL (Bitfield-Mask: 0x01)                          */

#endif /* R_DAC_B_POSMSK_H */
