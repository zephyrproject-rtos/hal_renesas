/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_COMA_POSMSK_H
#define R_COMA_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_COMA                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  RIPV  ========================================================== */
#define R_COMA_RIPV_TIPV_Pos             (0UL)          /*!< TIPV (Bit 0)                                          */
#define R_COMA_RIPV_TIPV_Msk             (0xfUL)        /*!< TIPV (Bitfield-Mask: 0x0f)                            */
#define R_COMA_RIPV_GWIPV_Pos            (4UL)          /*!< GWIPV (Bit 4)                                         */
#define R_COMA_RIPV_GWIPV_Msk            (0xf0UL)       /*!< GWIPV (Bitfield-Mask: 0x0f)                           */
#define R_COMA_RIPV_FWIPV_Pos            (8UL)          /*!< FWIPV (Bit 8)                                         */
#define R_COMA_RIPV_FWIPV_Msk            (0xf00UL)      /*!< FWIPV (Bitfield-Mask: 0x0f)                           */
#define R_COMA_RIPV_EAIPV_Pos            (12UL)         /*!< EAIPV (Bit 12)                                        */
#define R_COMA_RIPV_EAIPV_Msk            (0xf000UL)     /*!< EAIPV (Bitfield-Mask: 0x0f)                           */
#define R_COMA_RIPV_FBIPV_Pos            (16UL)         /*!< FBIPV (Bit 16)                                        */
#define R_COMA_RIPV_FBIPV_Msk            (0xf0000UL)    /*!< FBIPV (Bitfield-Mask: 0x0f)                           */
#define R_COMA_RIPV_CAIPV_Pos            (21UL)         /*!< CAIPV (Bit 21)                                        */
#define R_COMA_RIPV_CAIPV_Msk            (0xe00000UL)   /*!< CAIPV (Bitfield-Mask: 0x07)                           */
/* ==========================================================  RRC  ========================================================== */
#define R_COMA_RRC_RR_Pos                (0UL)          /*!< RR (Bit 0)                                            */
#define R_COMA_RRC_RR_Msk                (0x1UL)        /*!< RR (Bitfield-Mask: 0x01)                              */
/* =========================================================  RCEC  ========================================================== */
#define R_COMA_RCEC_ACE0_Pos             (0UL)          /*!< ACE0 (Bit 0)                                          */
#define R_COMA_RCEC_ACE0_Msk             (0x1UL)        /*!< ACE0 (Bitfield-Mask: 0x01)                            */
#define R_COMA_RCEC_ACE1_Pos             (1UL)          /*!< ACE1 (Bit 1)                                          */
#define R_COMA_RCEC_ACE1_Msk             (0x2UL)        /*!< ACE1 (Bitfield-Mask: 0x01)                            */
#define R_COMA_RCEC_ACE2_Pos             (2UL)          /*!< ACE2 (Bit 2)                                          */
#define R_COMA_RCEC_ACE2_Msk             (0x4UL)        /*!< ACE2 (Bitfield-Mask: 0x01)                            */
#define R_COMA_RCEC_RCE_Pos              (16UL)         /*!< RCE (Bit 16)                                          */
#define R_COMA_RCEC_RCE_Msk              (0x10000UL)    /*!< RCE (Bitfield-Mask: 0x01)                             */
/* =========================================================  RCDC  ========================================================== */
#define R_COMA_RCDC_ACD0_Pos             (0UL)          /*!< ACD0 (Bit 0)                                          */
#define R_COMA_RCDC_ACD0_Msk             (0x1UL)        /*!< ACD0 (Bitfield-Mask: 0x01)                            */
#define R_COMA_RCDC_ACD1_Pos             (1UL)          /*!< ACD1 (Bit 1)                                          */
#define R_COMA_RCDC_ACD1_Msk             (0x2UL)        /*!< ACD1 (Bitfield-Mask: 0x01)                            */
#define R_COMA_RCDC_ACD2_Pos             (2UL)          /*!< ACD2 (Bit 2)                                          */
#define R_COMA_RCDC_ACD2_Msk             (0x4UL)        /*!< ACD2 (Bitfield-Mask: 0x01)                            */
#define R_COMA_RCDC_RCD_Pos              (16UL)         /*!< RCD (Bit 16)                                          */
#define R_COMA_RCDC_RCD_Msk              (0x10000UL)    /*!< RCD (Bitfield-Mask: 0x01)                             */
/* ======================================================  CABPIBWMC0  ======================================================= */
#define R_COMA_CABPIBWMC0_IBUWMPN_Pos    (0UL)          /*!< IBUWMPN (Bit 0)                                       */
#define R_COMA_CABPIBWMC0_IBUWMPN_Msk    (0x3ffUL)      /*!< IBUWMPN (Bitfield-Mask: 0x3ff)                        */
#define R_COMA_CABPIBWMC0_IBSWMPN_Pos    (16UL)         /*!< IBSWMPN (Bit 16)                                      */
#define R_COMA_CABPIBWMC0_IBSWMPN_Msk    (0x3ff0000UL)  /*!< IBSWMPN (Bitfield-Mask: 0x3ff)                        */
/* ======================================================  CABPIBWMC1  ======================================================= */
#define R_COMA_CABPIBWMC1_IBUWMPN_Pos    (0UL)          /*!< IBUWMPN (Bit 0)                                       */
#define R_COMA_CABPIBWMC1_IBUWMPN_Msk    (0x3ffUL)      /*!< IBUWMPN (Bitfield-Mask: 0x3ff)                        */
#define R_COMA_CABPIBWMC1_IBSWMPN_Pos    (16UL)         /*!< IBSWMPN (Bit 16)                                      */
#define R_COMA_CABPIBWMC1_IBSWMPN_Msk    (0x3ff0000UL)  /*!< IBSWMPN (Bitfield-Mask: 0x3ff)                        */
/* ======================================================  CABPIBWMC2  ======================================================= */
#define R_COMA_CABPIBWMC2_IBUWMPN_Pos    (0UL)          /*!< IBUWMPN (Bit 0)                                       */
#define R_COMA_CABPIBWMC2_IBUWMPN_Msk    (0x3ffUL)      /*!< IBUWMPN (Bitfield-Mask: 0x3ff)                        */
#define R_COMA_CABPIBWMC2_IBSWMPN_Pos    (16UL)         /*!< IBSWMPN (Bit 16)                                      */
#define R_COMA_CABPIBWMC2_IBSWMPN_Msk    (0x3ff0000UL)  /*!< IBSWMPN (Bitfield-Mask: 0x3ff)                        */
/* ======================================================  CABPIBWMC3  ======================================================= */
#define R_COMA_CABPIBWMC3_IBUWMPN_Pos    (0UL)          /*!< IBUWMPN (Bit 0)                                       */
#define R_COMA_CABPIBWMC3_IBUWMPN_Msk    (0x3ffUL)      /*!< IBUWMPN (Bitfield-Mask: 0x3ff)                        */
#define R_COMA_CABPIBWMC3_IBSWMPN_Pos    (16UL)         /*!< IBSWMPN (Bit 16)                                      */
#define R_COMA_CABPIBWMC3_IBSWMPN_Msk    (0x3ff0000UL)  /*!< IBSWMPN (Bitfield-Mask: 0x3ff)                        */
/* ======================================================  CABPIBWMC4  ======================================================= */
#define R_COMA_CABPIBWMC4_IBUWMPN_Pos    (0UL)          /*!< IBUWMPN (Bit 0)                                       */
#define R_COMA_CABPIBWMC4_IBUWMPN_Msk    (0x3ffUL)      /*!< IBUWMPN (Bitfield-Mask: 0x3ff)                        */
#define R_COMA_CABPIBWMC4_IBSWMPN_Pos    (16UL)         /*!< IBSWMPN (Bit 16)                                      */
#define R_COMA_CABPIBWMC4_IBSWMPN_Msk    (0x3ff0000UL)  /*!< IBSWMPN (Bitfield-Mask: 0x3ff)                        */
/* ======================================================  CABPIBWMC5  ======================================================= */
#define R_COMA_CABPIBWMC5_IBUWMPN_Pos    (0UL)          /*!< IBUWMPN (Bit 0)                                       */
#define R_COMA_CABPIBWMC5_IBUWMPN_Msk    (0x3ffUL)      /*!< IBUWMPN (Bitfield-Mask: 0x3ff)                        */
#define R_COMA_CABPIBWMC5_IBSWMPN_Pos    (16UL)         /*!< IBSWMPN (Bit 16)                                      */
#define R_COMA_CABPIBWMC5_IBSWMPN_Msk    (0x3ff0000UL)  /*!< IBSWMPN (Bitfield-Mask: 0x3ff)                        */
/* ======================================================  CABPIBWMC6  ======================================================= */
#define R_COMA_CABPIBWMC6_IBUWMPN_Pos    (0UL)          /*!< IBUWMPN (Bit 0)                                       */
#define R_COMA_CABPIBWMC6_IBUWMPN_Msk    (0x3ffUL)      /*!< IBUWMPN (Bitfield-Mask: 0x3ff)                        */
#define R_COMA_CABPIBWMC6_IBSWMPN_Pos    (16UL)         /*!< IBSWMPN (Bit 16)                                      */
#define R_COMA_CABPIBWMC6_IBSWMPN_Msk    (0x3ff0000UL)  /*!< IBSWMPN (Bitfield-Mask: 0x3ff)                        */
/* ======================================================  CABPIBWMC7  ======================================================= */
#define R_COMA_CABPIBWMC7_IBUWMPN_Pos    (0UL)          /*!< IBUWMPN (Bit 0)                                       */
#define R_COMA_CABPIBWMC7_IBUWMPN_Msk    (0x3ffUL)      /*!< IBUWMPN (Bitfield-Mask: 0x3ff)                        */
#define R_COMA_CABPIBWMC7_IBSWMPN_Pos    (16UL)         /*!< IBSWMPN (Bit 16)                                      */
#define R_COMA_CABPIBWMC7_IBSWMPN_Msk    (0x3ff0000UL)  /*!< IBSWMPN (Bitfield-Mask: 0x3ff)                        */
/* =======================================================  CABPWMLC  ======================================================== */
#define R_COMA_CABPWMLC_WMFL_Pos         (0UL)          /*!< WMFL (Bit 0)                                          */
#define R_COMA_CABPWMLC_WMFL_Msk         (0x3ffUL)      /*!< WMFL (Bitfield-Mask: 0x3ff)                           */
#define R_COMA_CABPWMLC_WMCL_Pos         (16UL)         /*!< WMCL (Bit 16)                                         */
#define R_COMA_CABPWMLC_WMCL_Msk         (0x3ff0000UL)  /*!< WMCL (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  CABPPFLC0  ======================================================= */
#define R_COMA_CABPPFLC0_PDL_Pos         (0UL)          /*!< PDL (Bit 0)                                           */
#define R_COMA_CABPPFLC0_PDL_Msk         (0x3ffUL)      /*!< PDL (Bitfield-Mask: 0x3ff)                            */
#define R_COMA_CABPPFLC0_PAL_Pos         (16UL)         /*!< PAL (Bit 16)                                          */
#define R_COMA_CABPPFLC0_PAL_Msk         (0x3ff0000UL)  /*!< PAL (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  CABPPFLC1  ======================================================= */
#define R_COMA_CABPPFLC1_PDL_Pos         (0UL)          /*!< PDL (Bit 0)                                           */
#define R_COMA_CABPPFLC1_PDL_Msk         (0x3ffUL)      /*!< PDL (Bitfield-Mask: 0x3ff)                            */
#define R_COMA_CABPPFLC1_PAL_Pos         (16UL)         /*!< PAL (Bit 16)                                          */
#define R_COMA_CABPPFLC1_PAL_Msk         (0x3ff0000UL)  /*!< PAL (Bitfield-Mask: 0x3ff)                            */
/* ======================================================  CABPPWMLC0  ======================================================= */
#define R_COMA_CABPPWMLC0_PWMFL_Pos      (0UL)          /*!< PWMFL (Bit 0)                                         */
#define R_COMA_CABPPWMLC0_PWMFL_Msk      (0x3ffUL)      /*!< PWMFL (Bitfield-Mask: 0x3ff)                          */
#define R_COMA_CABPPWMLC0_PWMCL_Pos      (16UL)         /*!< PWMCL (Bit 16)                                        */
#define R_COMA_CABPPWMLC0_PWMCL_Msk      (0x3ff0000UL)  /*!< PWMCL (Bitfield-Mask: 0x3ff)                          */
/* ======================================================  CABPPWMLC1  ======================================================= */
#define R_COMA_CABPPWMLC1_PWMFL_Pos      (0UL)          /*!< PWMFL (Bit 0)                                         */
#define R_COMA_CABPPWMLC1_PWMFL_Msk      (0x3ffUL)      /*!< PWMFL (Bitfield-Mask: 0x3ff)                          */
#define R_COMA_CABPPWMLC1_PWMCL_Pos      (16UL)         /*!< PWMCL (Bit 16)                                        */
#define R_COMA_CABPPWMLC1_PWMCL_Msk      (0x3ff0000UL)  /*!< PWMCL (Bitfield-Mask: 0x3ff)                          */
/* ======================================================  CABPPWMLC2  ======================================================= */
#define R_COMA_CABPPWMLC2_PWMFL_Pos      (0UL)          /*!< PWMFL (Bit 0)                                         */
#define R_COMA_CABPPWMLC2_PWMFL_Msk      (0x3ffUL)      /*!< PWMFL (Bitfield-Mask: 0x3ff)                          */
#define R_COMA_CABPPWMLC2_PWMCL_Pos      (16UL)         /*!< PWMCL (Bit 16)                                        */
#define R_COMA_CABPPWMLC2_PWMCL_Msk      (0x3ff0000UL)  /*!< PWMCL (Bitfield-Mask: 0x3ff)                          */
/* ======================================================  CABPPPFLC00  ====================================================== */
#define R_COMA_CABPPPFLC00_PPDL_Pos      (0UL)          /*!< PPDL (Bit 0)                                          */
#define R_COMA_CABPPPFLC00_PPDL_Msk      (0x3ffUL)      /*!< PPDL (Bitfield-Mask: 0x3ff)                           */
#define R_COMA_CABPPPFLC00_PPAL_Pos      (16UL)         /*!< PPAL (Bit 16)                                         */
#define R_COMA_CABPPPFLC00_PPAL_Msk      (0x3ff0000UL)  /*!< PPAL (Bitfield-Mask: 0x3ff)                           */
/* ======================================================  CABPPPFLC01  ====================================================== */
#define R_COMA_CABPPPFLC01_PPDL_Pos      (0UL)          /*!< PPDL (Bit 0)                                          */
#define R_COMA_CABPPPFLC01_PPDL_Msk      (0x3ffUL)      /*!< PPDL (Bitfield-Mask: 0x3ff)                           */
#define R_COMA_CABPPPFLC01_PPAL_Pos      (16UL)         /*!< PPAL (Bit 16)                                         */
#define R_COMA_CABPPPFLC01_PPAL_Msk      (0x3ff0000UL)  /*!< PPAL (Bitfield-Mask: 0x3ff)                           */
/* ======================================================  CABPPPFLC10  ====================================================== */
#define R_COMA_CABPPPFLC10_PPDL_Pos      (0UL)          /*!< PPDL (Bit 0)                                          */
#define R_COMA_CABPPPFLC10_PPDL_Msk      (0x3ffUL)      /*!< PPDL (Bitfield-Mask: 0x3ff)                           */
#define R_COMA_CABPPPFLC10_PPAL_Pos      (16UL)         /*!< PPAL (Bit 16)                                         */
#define R_COMA_CABPPPFLC10_PPAL_Msk      (0x3ff0000UL)  /*!< PPAL (Bitfield-Mask: 0x3ff)                           */
/* ======================================================  CABPPPFLC11  ====================================================== */
#define R_COMA_CABPPPFLC11_PPDL_Pos      (0UL)          /*!< PPDL (Bit 0)                                          */
#define R_COMA_CABPPPFLC11_PPDL_Msk      (0x3ffUL)      /*!< PPDL (Bitfield-Mask: 0x3ff)                           */
#define R_COMA_CABPPPFLC11_PPAL_Pos      (16UL)         /*!< PPAL (Bit 16)                                         */
#define R_COMA_CABPPPFLC11_PPAL_Msk      (0x3ff0000UL)  /*!< PPAL (Bitfield-Mask: 0x3ff)                           */
/* ======================================================  CABPPPFLC20  ====================================================== */
#define R_COMA_CABPPPFLC20_PPDL_Pos      (0UL)          /*!< PPDL (Bit 0)                                          */
#define R_COMA_CABPPPFLC20_PPDL_Msk      (0x3ffUL)      /*!< PPDL (Bitfield-Mask: 0x3ff)                           */
#define R_COMA_CABPPPFLC20_PPAL_Pos      (16UL)         /*!< PPAL (Bit 16)                                         */
#define R_COMA_CABPPPFLC20_PPAL_Msk      (0x3ff0000UL)  /*!< PPAL (Bitfield-Mask: 0x3ff)                           */
/* ======================================================  CABPPPFLC21  ====================================================== */
#define R_COMA_CABPPPFLC21_PPDL_Pos      (0UL)          /*!< PPDL (Bit 0)                                          */
#define R_COMA_CABPPPFLC21_PPDL_Msk      (0x3ffUL)      /*!< PPDL (Bitfield-Mask: 0x3ff)                           */
#define R_COMA_CABPPPFLC21_PPAL_Pos      (16UL)         /*!< PPAL (Bit 16)                                         */
#define R_COMA_CABPPPFLC21_PPAL_Msk      (0x3ff0000UL)  /*!< PPAL (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  CABPULC0  ======================================================== */
#define R_COMA_CABPULC0_MXNPN_Pos        (0UL)          /*!< MXNPN (Bit 0)                                         */
#define R_COMA_CABPULC0_MXNPN_Msk        (0x3ffUL)      /*!< MXNPN (Bitfield-Mask: 0x3ff)                          */
#define R_COMA_CABPULC0_MNNPN_Pos        (16UL)         /*!< MNNPN (Bit 16)                                        */
#define R_COMA_CABPULC0_MNNPN_Msk        (0x3ff0000UL)  /*!< MNNPN (Bitfield-Mask: 0x3ff)                          */
/* =======================================================  CABPULC1  ======================================================== */
#define R_COMA_CABPULC1_MXNPN_Pos        (0UL)          /*!< MXNPN (Bit 0)                                         */
#define R_COMA_CABPULC1_MXNPN_Msk        (0x3ffUL)      /*!< MXNPN (Bitfield-Mask: 0x3ff)                          */
#define R_COMA_CABPULC1_MNNPN_Pos        (16UL)         /*!< MNNPN (Bit 16)                                        */
#define R_COMA_CABPULC1_MNNPN_Msk        (0x3ff0000UL)  /*!< MNNPN (Bitfield-Mask: 0x3ff)                          */
/* =======================================================  CABPULC2  ======================================================== */
#define R_COMA_CABPULC2_MXNPN_Pos        (0UL)          /*!< MXNPN (Bit 0)                                         */
#define R_COMA_CABPULC2_MXNPN_Msk        (0x3ffUL)      /*!< MXNPN (Bitfield-Mask: 0x3ff)                          */
#define R_COMA_CABPULC2_MNNPN_Pos        (16UL)         /*!< MNNPN (Bit 16)                                        */
#define R_COMA_CABPULC2_MNNPN_Msk        (0x3ff0000UL)  /*!< MNNPN (Bitfield-Mask: 0x3ff)                          */
/* ========================================================  CABPIRM  ======================================================== */
#define R_COMA_CABPIRM_BPIOG_Pos         (0UL)          /*!< BPIOG (Bit 0)                                         */
#define R_COMA_CABPIRM_BPIOG_Msk         (0x1UL)        /*!< BPIOG (Bitfield-Mask: 0x01)                           */
#define R_COMA_CABPIRM_BPR_Pos           (1UL)          /*!< BPR (Bit 1)                                           */
#define R_COMA_CABPIRM_BPR_Msk           (0x2UL)        /*!< BPR (Bitfield-Mask: 0x01)                             */
/* ========================================================  CABPPCM  ======================================================== */
#define R_COMA_CABPPCM_RPC_Pos           (0UL)          /*!< RPC (Bit 0)                                           */
#define R_COMA_CABPPCM_RPC_Msk           (0x3ffUL)      /*!< RPC (Bitfield-Mask: 0x3ff)                            */
#define R_COMA_CABPPCM_TPC_Pos           (16UL)         /*!< TPC (Bit 16)                                          */
#define R_COMA_CABPPCM_TPC_Msk           (0x3ff0000UL)  /*!< TPC (Bitfield-Mask: 0x3ff)                            */
/* ========================================================  CABPLCM  ======================================================== */
#define R_COMA_CABPLCM_LRC_Pos           (0UL)          /*!< LRC (Bit 0)                                           */
#define R_COMA_CABPLCM_LRC_Msk           (0x3ffUL)      /*!< LRC (Bitfield-Mask: 0x3ff)                            */
/* =======================================================  CABPCPM0  ======================================================== */
#define R_COMA_CABPCPM0_RPCP_Pos         (0UL)          /*!< RPCP (Bit 0)                                          */
#define R_COMA_CABPCPM0_RPCP_Msk         (0x3ffUL)      /*!< RPCP (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  CABPCPM1  ======================================================== */
#define R_COMA_CABPCPM1_RPCP_Pos         (0UL)          /*!< RPCP (Bit 0)                                          */
#define R_COMA_CABPCPM1_RPCP_Msk         (0x3ffUL)      /*!< RPCP (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  CABPCPM2  ======================================================== */
#define R_COMA_CABPCPM2_RPCP_Pos         (0UL)          /*!< RPCP (Bit 0)                                          */
#define R_COMA_CABPCPM2_RPCP_Msk         (0x3ffUL)      /*!< RPCP (Bitfield-Mask: 0x3ff)                           */
/* =======================================================  CABPMCPM0  ======================================================= */
#define R_COMA_CABPMCPM0_RPMCP_Pos       (0UL)          /*!< RPMCP (Bit 0)                                         */
#define R_COMA_CABPMCPM0_RPMCP_Msk       (0x3ffUL)      /*!< RPMCP (Bitfield-Mask: 0x3ff)                          */
/* =======================================================  CABPMCPM1  ======================================================= */
#define R_COMA_CABPMCPM1_RPMCP_Pos       (0UL)          /*!< RPMCP (Bit 0)                                         */
#define R_COMA_CABPMCPM1_RPMCP_Msk       (0x3ffUL)      /*!< RPMCP (Bitfield-Mask: 0x3ff)                          */
/* =======================================================  CABPMCPM2  ======================================================= */
#define R_COMA_CABPMCPM2_RPMCP_Pos       (0UL)          /*!< RPMCP (Bit 0)                                         */
#define R_COMA_CABPMCPM2_RPMCP_Msk       (0x3ffUL)      /*!< RPMCP (Bitfield-Mask: 0x3ff)                          */
/* ========================================================  CARDNM  ========================================================= */
#define R_COMA_CARDNM_RDNRR_Pos          (0UL)          /*!< RDNRR (Bit 0)                                         */
#define R_COMA_CARDNM_RDNRR_Msk          (0x3ffUL)      /*!< RDNRR (Bitfield-Mask: 0x3ff)                          */
/* ========================================================  CARDMNM  ======================================================== */
#define R_COMA_CARDMNM_RDMNRR_Pos        (0UL)          /*!< RDMNRR (Bit 0)                                        */
#define R_COMA_CARDMNM_RDMNRR_Msk        (0x3ffUL)      /*!< RDMNRR (Bitfield-Mask: 0x3ff)                         */
/* ========================================================  CARDCN  ========================================================= */
#define R_COMA_CARDCN_RDN_Pos            (0UL)          /*!< RDN (Bit 0)                                           */
#define R_COMA_CARDCN_RDN_Msk            (0xffffffffUL) /*!< RDN (Bitfield-Mask: 0xffffffff)                       */
/* ========================================================  CAEIS0  ========================================================= */
#define R_COMA_CAEIS0_PECCES_Pos         (0UL)          /*!< PECCES (Bit 0)                                        */
#define R_COMA_CAEIS0_PECCES_Msk         (0x1UL)        /*!< PECCES (Bitfield-Mask: 0x01)                          */
#define R_COMA_CAEIS0_DSECCES_Pos        (1UL)          /*!< DSECCES (Bit 1)                                       */
#define R_COMA_CAEIS0_DSECCES_Msk        (0x2UL)        /*!< DSECCES (Bitfield-Mask: 0x01)                         */
#define R_COMA_CAEIS0_BPECCES_Pos        (2UL)          /*!< BPECCES (Bit 2)                                       */
#define R_COMA_CAEIS0_BPECCES_Msk        (0x4UL)        /*!< BPECCES (Bitfield-Mask: 0x01)                         */
#define R_COMA_CAEIS0_BPOPS_Pos          (8UL)          /*!< BPOPS (Bit 8)                                         */
#define R_COMA_CAEIS0_BPOPS_Msk          (0x100UL)      /*!< BPOPS (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAEIS0_WMCLOS_Pos         (9UL)          /*!< WMCLOS (Bit 9)                                        */
#define R_COMA_CAEIS0_WMCLOS_Msk         (0x200UL)      /*!< WMCLOS (Bitfield-Mask: 0x01)                          */
#define R_COMA_CAEIS0_WMFLOS_Pos         (10UL)         /*!< WMFLOS (Bit 10)                                       */
#define R_COMA_CAEIS0_WMFLOS_Msk         (0x400UL)      /*!< WMFLOS (Bitfield-Mask: 0x01)                          */
#define R_COMA_CAEIS0_EEIPLN_Pos         (16UL)         /*!< EEIPLN (Bit 16)                                       */
#define R_COMA_CAEIS0_EEIPLN_Msk         (0xf0000UL)    /*!< EEIPLN (Bitfield-Mask: 0x0f)                          */
/* ========================================================  CAEIE0  ========================================================= */
#define R_COMA_CAEIE0_PECCEE_Pos         (0UL)          /*!< PECCEE (Bit 0)                                        */
#define R_COMA_CAEIE0_PECCEE_Msk         (0x1UL)        /*!< PECCEE (Bitfield-Mask: 0x01)                          */
#define R_COMA_CAEIE0_DSECCEE_Pos        (1UL)          /*!< DSECCEE (Bit 1)                                       */
#define R_COMA_CAEIE0_DSECCEE_Msk        (0x2UL)        /*!< DSECCEE (Bitfield-Mask: 0x01)                         */
#define R_COMA_CAEIE0_BPECCEE_Pos        (2UL)          /*!< BPECCEE (Bit 2)                                       */
#define R_COMA_CAEIE0_BPECCEE_Msk        (0x4UL)        /*!< BPECCEE (Bitfield-Mask: 0x01)                         */
#define R_COMA_CAEIE0_BPOPE_Pos          (8UL)          /*!< BPOPE (Bit 8)                                         */
#define R_COMA_CAEIE0_BPOPE_Msk          (0x100UL)      /*!< BPOPE (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAEIE0_WMCLOE_Pos         (9UL)          /*!< WMCLOE (Bit 9)                                        */
#define R_COMA_CAEIE0_WMCLOE_Msk         (0x200UL)      /*!< WMCLOE (Bitfield-Mask: 0x01)                          */
#define R_COMA_CAEIE0_WMFLOE_Pos         (10UL)         /*!< WMFLOE (Bit 10)                                       */
#define R_COMA_CAEIE0_WMFLOE_Msk         (0x400UL)      /*!< WMFLOE (Bitfield-Mask: 0x01)                          */
/* ========================================================  CAEID0  ========================================================= */
#define R_COMA_CAEID0_PECCED_Pos         (0UL)          /*!< PECCED (Bit 0)                                        */
#define R_COMA_CAEID0_PECCED_Msk         (0x1UL)        /*!< PECCED (Bitfield-Mask: 0x01)                          */
#define R_COMA_CAEID0_DSECCED_Pos        (1UL)          /*!< DSECCED (Bit 1)                                       */
#define R_COMA_CAEID0_DSECCED_Msk        (0x2UL)        /*!< DSECCED (Bitfield-Mask: 0x01)                         */
#define R_COMA_CAEID0_BPECCED_Pos        (2UL)          /*!< BPECCED (Bit 2)                                       */
#define R_COMA_CAEID0_BPECCED_Msk        (0x4UL)        /*!< BPECCED (Bitfield-Mask: 0x01)                         */
#define R_COMA_CAEID0_BPOPD_Pos          (8UL)          /*!< BPOPD (Bit 8)                                         */
#define R_COMA_CAEID0_BPOPD_Msk          (0x100UL)      /*!< BPOPD (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAEID0_WMCLOD_Pos         (9UL)          /*!< WMCLOD (Bit 9)                                        */
#define R_COMA_CAEID0_WMCLOD_Msk         (0x200UL)      /*!< WMCLOD (Bitfield-Mask: 0x01)                          */
#define R_COMA_CAEID0_WMFLOD_Pos         (10UL)         /*!< WMFLOD (Bit 10)                                       */
#define R_COMA_CAEID0_WMFLOD_Msk         (0x400UL)      /*!< WMFLOD (Bitfield-Mask: 0x01)                          */
/* ========================================================  CAEIS1  ========================================================= */
#define R_COMA_CAEIS1_PWMCLOS0_Pos       (0UL)          /*!< PWMCLOS0 (Bit 0)                                      */
#define R_COMA_CAEIS1_PWMCLOS0_Msk       (0x1UL)        /*!< PWMCLOS0 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIS1_PWMCLOS1_Pos       (1UL)          /*!< PWMCLOS1 (Bit 1)                                      */
#define R_COMA_CAEIS1_PWMCLOS1_Msk       (0x2UL)        /*!< PWMCLOS1 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIS1_PWMCLOS2_Pos       (2UL)          /*!< PWMCLOS2 (Bit 2)                                      */
#define R_COMA_CAEIS1_PWMCLOS2_Msk       (0x4UL)        /*!< PWMCLOS2 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIS1_PWMFLOS0_Pos       (16UL)         /*!< PWMFLOS0 (Bit 16)                                     */
#define R_COMA_CAEIS1_PWMFLOS0_Msk       (0x10000UL)    /*!< PWMFLOS0 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIS1_PWMFLOS1_Pos       (17UL)         /*!< PWMFLOS1 (Bit 17)                                     */
#define R_COMA_CAEIS1_PWMFLOS1_Msk       (0x20000UL)    /*!< PWMFLOS1 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIS1_PWMFLOS2_Pos       (18UL)         /*!< PWMFLOS2 (Bit 18)                                     */
#define R_COMA_CAEIS1_PWMFLOS2_Msk       (0x40000UL)    /*!< PWMFLOS2 (Bitfield-Mask: 0x01)                        */
/* ========================================================  CAEIE1  ========================================================= */
#define R_COMA_CAEIE1_PWMCLOE0_Pos       (0UL)          /*!< PWMCLOE0 (Bit 0)                                      */
#define R_COMA_CAEIE1_PWMCLOE0_Msk       (0x1UL)        /*!< PWMCLOE0 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIE1_PWMCLOE1_Pos       (1UL)          /*!< PWMCLOE1 (Bit 1)                                      */
#define R_COMA_CAEIE1_PWMCLOE1_Msk       (0x2UL)        /*!< PWMCLOE1 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIE1_PWMCLOE2_Pos       (2UL)          /*!< PWMCLOE2 (Bit 2)                                      */
#define R_COMA_CAEIE1_PWMCLOE2_Msk       (0x4UL)        /*!< PWMCLOE2 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIE1_PWMFLOE0_Pos       (16UL)         /*!< PWMFLOE0 (Bit 16)                                     */
#define R_COMA_CAEIE1_PWMFLOE0_Msk       (0x10000UL)    /*!< PWMFLOE0 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIE1_PWMFLOE1_Pos       (17UL)         /*!< PWMFLOE1 (Bit 17)                                     */
#define R_COMA_CAEIE1_PWMFLOE1_Msk       (0x20000UL)    /*!< PWMFLOE1 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEIE1_PWMFLOE2_Pos       (18UL)         /*!< PWMFLOE2 (Bit 18)                                     */
#define R_COMA_CAEIE1_PWMFLOE2_Msk       (0x40000UL)    /*!< PWMFLOE2 (Bitfield-Mask: 0x01)                        */
/* ========================================================  CAEID1  ========================================================= */
#define R_COMA_CAEID1_PWMCLOD0_Pos       (0UL)          /*!< PWMCLOD0 (Bit 0)                                      */
#define R_COMA_CAEID1_PWMCLOD0_Msk       (0x1UL)        /*!< PWMCLOD0 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEID1_PWMCLOD1_Pos       (1UL)          /*!< PWMCLOD1 (Bit 1)                                      */
#define R_COMA_CAEID1_PWMCLOD1_Msk       (0x2UL)        /*!< PWMCLOD1 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEID1_PWMCLOD2_Pos       (2UL)          /*!< PWMCLOD2 (Bit 2)                                      */
#define R_COMA_CAEID1_PWMCLOD2_Msk       (0x4UL)        /*!< PWMCLOD2 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEID1_PWMFLOD0_Pos       (16UL)         /*!< PWMFLOD0 (Bit 16)                                     */
#define R_COMA_CAEID1_PWMFLOD0_Msk       (0x10000UL)    /*!< PWMFLOD0 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEID1_PWMFLOD1_Pos       (17UL)         /*!< PWMFLOD1 (Bit 17)                                     */
#define R_COMA_CAEID1_PWMFLOD1_Msk       (0x20000UL)    /*!< PWMFLOD1 (Bitfield-Mask: 0x01)                        */
#define R_COMA_CAEID1_PWMFLOD2_Pos       (18UL)         /*!< PWMFLOD2 (Bit 18)                                     */
#define R_COMA_CAEID1_PWMFLOD2_Msk       (0x40000UL)    /*!< PWMFLOD2 (Bitfield-Mask: 0x01)                        */
/* ========================================================  CAMIS0  ========================================================= */
#define R_COMA_CAMIS0_PFS0_Pos           (0UL)          /*!< PFS0 (Bit 0)                                          */
#define R_COMA_CAMIS0_PFS0_Msk           (0x1UL)        /*!< PFS0 (Bitfield-Mask: 0x01)                            */
#define R_COMA_CAMIS0_PFS1_Pos           (1UL)          /*!< PFS1 (Bit 1)                                          */
#define R_COMA_CAMIS0_PFS1_Msk           (0x2UL)        /*!< PFS1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  CAMIE0  ========================================================= */
#define R_COMA_CAMIE0_PFE0_Pos           (0UL)          /*!< PFE0 (Bit 0)                                          */
#define R_COMA_CAMIE0_PFE0_Msk           (0x1UL)        /*!< PFE0 (Bitfield-Mask: 0x01)                            */
#define R_COMA_CAMIE0_PFE1_Pos           (1UL)          /*!< PFE1 (Bit 1)                                          */
#define R_COMA_CAMIE0_PFE1_Msk           (0x2UL)        /*!< PFE1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  CAMID0  ========================================================= */
#define R_COMA_CAMID0_PFD0_Pos           (0UL)          /*!< PFD0 (Bit 0)                                          */
#define R_COMA_CAMID0_PFD0_Msk           (0x1UL)        /*!< PFD0 (Bitfield-Mask: 0x01)                            */
#define R_COMA_CAMID0_PFD1_Pos           (1UL)          /*!< PFD1 (Bit 1)                                          */
#define R_COMA_CAMID0_PFD1_Msk           (0x2UL)        /*!< PFD1 (Bitfield-Mask: 0x01)                            */
/* ========================================================  CAMIS1  ========================================================= */
#define R_COMA_CAMIS1_PPFS0_Pos          (0UL)          /*!< PPFS0 (Bit 0)                                         */
#define R_COMA_CAMIS1_PPFS0_Msk          (0x1UL)        /*!< PPFS0 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIS1_PPFS1_Pos          (1UL)          /*!< PPFS1 (Bit 1)                                         */
#define R_COMA_CAMIS1_PPFS1_Msk          (0x2UL)        /*!< PPFS1 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIS1_PPFS2_Pos          (2UL)          /*!< PPFS2 (Bit 2)                                         */
#define R_COMA_CAMIS1_PPFS2_Msk          (0x4UL)        /*!< PPFS2 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIS1_PPFS3_Pos          (3UL)          /*!< PPFS3 (Bit 3)                                         */
#define R_COMA_CAMIS1_PPFS3_Msk          (0x8UL)        /*!< PPFS3 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIS1_PPFS4_Pos          (4UL)          /*!< PPFS4 (Bit 4)                                         */
#define R_COMA_CAMIS1_PPFS4_Msk          (0x10UL)       /*!< PPFS4 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIS1_PPFS5_Pos          (5UL)          /*!< PPFS5 (Bit 5)                                         */
#define R_COMA_CAMIS1_PPFS5_Msk          (0x20UL)       /*!< PPFS5 (Bitfield-Mask: 0x01)                           */
/* ========================================================  CAMIE1  ========================================================= */
#define R_COMA_CAMIE1_PPFE0_Pos          (0UL)          /*!< PPFE0 (Bit 0)                                         */
#define R_COMA_CAMIE1_PPFE0_Msk          (0x1UL)        /*!< PPFE0 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIE1_PPFE1_Pos          (1UL)          /*!< PPFE1 (Bit 1)                                         */
#define R_COMA_CAMIE1_PPFE1_Msk          (0x2UL)        /*!< PPFE1 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIE1_PPFE2_Pos          (2UL)          /*!< PPFE2 (Bit 2)                                         */
#define R_COMA_CAMIE1_PPFE2_Msk          (0x4UL)        /*!< PPFE2 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIE1_PPFE3_Pos          (3UL)          /*!< PPFE3 (Bit 3)                                         */
#define R_COMA_CAMIE1_PPFE3_Msk          (0x8UL)        /*!< PPFE3 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIE1_PPFE4_Pos          (4UL)          /*!< PPFE4 (Bit 4)                                         */
#define R_COMA_CAMIE1_PPFE4_Msk          (0x10UL)       /*!< PPFE4 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMIE1_PPFE5_Pos          (5UL)          /*!< PPFE5 (Bit 5)                                         */
#define R_COMA_CAMIE1_PPFE5_Msk          (0x20UL)       /*!< PPFE5 (Bitfield-Mask: 0x01)                           */
/* ========================================================  CAMID1  ========================================================= */
#define R_COMA_CAMID1_PPFD0_Pos          (0UL)          /*!< PPFD0 (Bit 0)                                         */
#define R_COMA_CAMID1_PPFD0_Msk          (0x1UL)        /*!< PPFD0 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMID1_PPFD1_Pos          (1UL)          /*!< PPFD1 (Bit 1)                                         */
#define R_COMA_CAMID1_PPFD1_Msk          (0x2UL)        /*!< PPFD1 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMID1_PPFD2_Pos          (2UL)          /*!< PPFD2 (Bit 2)                                         */
#define R_COMA_CAMID1_PPFD2_Msk          (0x4UL)        /*!< PPFD2 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMID1_PPFD3_Pos          (3UL)          /*!< PPFD3 (Bit 3)                                         */
#define R_COMA_CAMID1_PPFD3_Msk          (0x8UL)        /*!< PPFD3 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMID1_PPFD4_Pos          (4UL)          /*!< PPFD4 (Bit 4)                                         */
#define R_COMA_CAMID1_PPFD4_Msk          (0x10UL)       /*!< PPFD4 (Bitfield-Mask: 0x01)                           */
#define R_COMA_CAMID1_PPFD5_Pos          (5UL)          /*!< PPFD5 (Bit 5)                                         */
#define R_COMA_CAMID1_PPFD5_Msk          (0x20UL)       /*!< PPFD5 (Bitfield-Mask: 0x01)                           */

/** @} */ /* End of group PosMask_peripherals */

#endif                                                  /* R_COMA_POSMSK_H */
