/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CAC_POSMSK_H
#define R_CAC_POSMSK_H

/* =========================================================================================================================== */
/* ================                                           R_CAC                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  CACR0  ========================================================= */
#define R_CAC_CACR0_CFME_Pos       (0UL)    /*!< CFME (Bit 0)                                          */
#define R_CAC_CACR0_CFME_Msk       (0x1UL)  /*!< CFME (Bitfield-Mask: 0x01)                            */
/* =========================================================  CACR1  ========================================================= */
#define R_CAC_CACR1_EDGES_Pos      (6UL)    /*!< EDGES (Bit 6)                                         */
#define R_CAC_CACR1_EDGES_Msk      (0xc0UL) /*!< EDGES (Bitfield-Mask: 0x03)                           */
#define R_CAC_CACR1_TCSS_Pos       (4UL)    /*!< TCSS (Bit 4)                                          */
#define R_CAC_CACR1_TCSS_Msk       (0x30UL) /*!< TCSS (Bitfield-Mask: 0x03)                            */
#define R_CAC_CACR1_FMCS_Pos       (1UL)    /*!< FMCS (Bit 1)                                          */
#define R_CAC_CACR1_FMCS_Msk       (0xeUL)  /*!< FMCS (Bitfield-Mask: 0x07)                            */
#define R_CAC_CACR1_CACREFE_Pos    (0UL)    /*!< CACREFE (Bit 0)                                       */
#define R_CAC_CACR1_CACREFE_Msk    (0x1UL)  /*!< CACREFE (Bitfield-Mask: 0x01)                         */
/* =========================================================  CACR2  ========================================================= */
#define R_CAC_CACR2_DFS_Pos        (6UL)    /*!< DFS (Bit 6)                                           */
#define R_CAC_CACR2_DFS_Msk        (0xc0UL) /*!< DFS (Bitfield-Mask: 0x03)                             */
#define R_CAC_CACR2_RCDS_Pos       (4UL)    /*!< RCDS (Bit 4)                                          */
#define R_CAC_CACR2_RCDS_Msk       (0x30UL) /*!< RCDS (Bitfield-Mask: 0x03)                            */
#define R_CAC_CACR2_RSCS_Pos       (1UL)    /*!< RSCS (Bit 1)                                          */
#define R_CAC_CACR2_RSCS_Msk       (0xeUL)  /*!< RSCS (Bitfield-Mask: 0x07)                            */
#define R_CAC_CACR2_RPS_Pos        (0UL)    /*!< RPS (Bit 0)                                           */
#define R_CAC_CACR2_RPS_Msk        (0x1UL)  /*!< RPS (Bitfield-Mask: 0x01)                             */
/* =========================================================  CAICR  ========================================================= */
#define R_CAC_CAICR_OVFFCL_Pos     (6UL)    /*!< OVFFCL (Bit 6)                                        */
#define R_CAC_CAICR_OVFFCL_Msk     (0x40UL) /*!< OVFFCL (Bitfield-Mask: 0x01)                          */
#define R_CAC_CAICR_MENDFCL_Pos    (5UL)    /*!< MENDFCL (Bit 5)                                       */
#define R_CAC_CAICR_MENDFCL_Msk    (0x20UL) /*!< MENDFCL (Bitfield-Mask: 0x01)                         */
#define R_CAC_CAICR_FERRFCL_Pos    (4UL)    /*!< FERRFCL (Bit 4)                                       */
#define R_CAC_CAICR_FERRFCL_Msk    (0x10UL) /*!< FERRFCL (Bitfield-Mask: 0x01)                         */
#define R_CAC_CAICR_OVFIE_Pos      (2UL)    /*!< OVFIE (Bit 2)                                         */
#define R_CAC_CAICR_OVFIE_Msk      (0x4UL)  /*!< OVFIE (Bitfield-Mask: 0x01)                           */
#define R_CAC_CAICR_MENDIE_Pos     (1UL)    /*!< MENDIE (Bit 1)                                        */
#define R_CAC_CAICR_MENDIE_Msk     (0x2UL)  /*!< MENDIE (Bitfield-Mask: 0x01)                          */
#define R_CAC_CAICR_FERRIE_Pos     (0UL)    /*!< FERRIE (Bit 0)                                        */
#define R_CAC_CAICR_FERRIE_Msk     (0x1UL)  /*!< FERRIE (Bitfield-Mask: 0x01)                          */
/* =========================================================  CASTR  ========================================================= */
#define R_CAC_CASTR_OVFF_Pos       (2UL)    /*!< OVFF (Bit 2)                                          */
#define R_CAC_CASTR_OVFF_Msk       (0x4UL)  /*!< OVFF (Bitfield-Mask: 0x01)                            */
#define R_CAC_CASTR_MENDF_Pos      (1UL)    /*!< MENDF (Bit 1)                                         */
#define R_CAC_CASTR_MENDF_Msk      (0x2UL)  /*!< MENDF (Bitfield-Mask: 0x01)                           */
#define R_CAC_CASTR_FERRF_Pos      (0UL)    /*!< FERRF (Bit 0)                                         */
#define R_CAC_CASTR_FERRF_Msk      (0x1UL)  /*!< FERRF (Bitfield-Mask: 0x01)                           */
/* ========================================================  CAULVR  ========================================================= */
/* ========================================================  CALLVR  ========================================================= */
/* ========================================================  CACNTBR  ======================================================== */
#endif /* R_CAC_POSMSK_H */
