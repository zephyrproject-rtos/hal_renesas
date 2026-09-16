/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_XSPI_POSMSK_H
#define R_XSPI_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          CMCFGCS                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  CMCFG0  ========================================================= */
#define R_XSPI0_CMCFGCS_CMCFG0_FFMT_Pos       (0UL)          /*!< FFMT (Bit 0)                                          */
#define R_XSPI0_CMCFGCS_CMCFG0_FFMT_Msk       (0x3UL)        /*!< FFMT (Bitfield-Mask: 0x03)                            */
#define R_XSPI0_CMCFGCS_CMCFG0_ADDSIZE_Pos    (2UL)          /*!< ADDSIZE (Bit 2)                                       */
#define R_XSPI0_CMCFGCS_CMCFG0_ADDSIZE_Msk    (0xcUL)        /*!< ADDSIZE (Bitfield-Mask: 0x03)                         */
#define R_XSPI0_CMCFGCS_CMCFG0_WPBSTMD_Pos    (4UL)          /*!< WPBSTMD (Bit 4)                                       */
#define R_XSPI0_CMCFGCS_CMCFG0_WPBSTMD_Msk    (0x10UL)       /*!< WPBSTMD (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_CMCFGCS_CMCFG0_ARYAMD_Pos     (5UL)          /*!< ARYAMD (Bit 5)                                        */
#define R_XSPI0_CMCFGCS_CMCFG0_ARYAMD_Msk     (0x20UL)       /*!< ARYAMD (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_CMCFGCS_CMCFG0_ADDRPEN_Pos    (16UL)         /*!< ADDRPEN (Bit 16)                                      */
#define R_XSPI0_CMCFGCS_CMCFG0_ADDRPEN_Msk    (0xff0000UL)   /*!< ADDRPEN (Bitfield-Mask: 0xff)                         */
#define R_XSPI0_CMCFGCS_CMCFG0_ADDRPCD_Pos    (24UL)         /*!< ADDRPCD (Bit 24)                                      */
#define R_XSPI0_CMCFGCS_CMCFG0_ADDRPCD_Msk    (0xff000000UL) /*!< ADDRPCD (Bitfield-Mask: 0xff)                         */
/* ========================================================  CMCFG1  ========================================================= */
#define R_XSPI0_CMCFGCS_CMCFG1_RDCMD_Pos      (0UL)          /*!< RDCMD (Bit 0)                                         */
#define R_XSPI0_CMCFGCS_CMCFG1_RDCMD_Msk      (0xffffUL)     /*!< RDCMD (Bitfield-Mask: 0xffff)                         */
#define R_XSPI0_CMCFGCS_CMCFG1_RDLATE_Pos     (16UL)         /*!< RDLATE (Bit 16)                                       */
#define R_XSPI0_CMCFGCS_CMCFG1_RDLATE_Msk     (0x1f0000UL)   /*!< RDLATE (Bitfield-Mask: 0x1f)                          */
/* ========================================================  CMCFG2  ========================================================= */
#define R_XSPI0_CMCFGCS_CMCFG2_WRCMD_Pos      (0UL)          /*!< WRCMD (Bit 0)                                         */
#define R_XSPI0_CMCFGCS_CMCFG2_WRCMD_Msk      (0xffffUL)     /*!< WRCMD (Bitfield-Mask: 0xffff)                         */
#define R_XSPI0_CMCFGCS_CMCFG2_WRLATE_Pos     (16UL)         /*!< WRLATE (Bit 16)                                       */
#define R_XSPI0_CMCFGCS_CMCFG2_WRLATE_Msk     (0x1f0000UL)   /*!< WRLATE (Bitfield-Mask: 0x1f)                          */

/* =========================================================================================================================== */
/* ================                                           CDBUF                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CDT  ========================================================== */
#define R_XSPI0_CDBUF_CDT_CMDSIZE_Pos     (0UL)          /*!< CMDSIZE (Bit 0)                                       */
#define R_XSPI0_CDBUF_CDT_CMDSIZE_Msk     (0x3UL)        /*!< CMDSIZE (Bitfield-Mask: 0x03)                         */
#define R_XSPI0_CDBUF_CDT_ADDSIZE_Pos     (2UL)          /*!< ADDSIZE (Bit 2)                                       */
#define R_XSPI0_CDBUF_CDT_ADDSIZE_Msk     (0x1cUL)       /*!< ADDSIZE (Bitfield-Mask: 0x07)                         */
#define R_XSPI0_CDBUF_CDT_DATASIZE_Pos    (5UL)          /*!< DATASIZE (Bit 5)                                      */
#define R_XSPI0_CDBUF_CDT_DATASIZE_Msk    (0x1e0UL)      /*!< DATASIZE (Bitfield-Mask: 0x0f)                        */
#define R_XSPI0_CDBUF_CDT_LATE_Pos        (9UL)          /*!< LATE (Bit 9)                                          */
#define R_XSPI0_CDBUF_CDT_LATE_Msk        (0x3e00UL)     /*!< LATE (Bitfield-Mask: 0x1f)                            */
#define R_XSPI0_CDBUF_CDT_TRTYPE_Pos      (15UL)         /*!< TRTYPE (Bit 15)                                       */
#define R_XSPI0_CDBUF_CDT_TRTYPE_Msk      (0x8000UL)     /*!< TRTYPE (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_CDBUF_CDT_CMD_Pos         (16UL)         /*!< CMD (Bit 16)                                          */
#define R_XSPI0_CDBUF_CDT_CMD_Msk         (0xffff0000UL) /*!< CMD (Bitfield-Mask: 0xffff)                           */
/* ==========================================================  CDA  ========================================================== */
#define R_XSPI0_CDBUF_CDA_ADD_Pos         (0UL)          /*!< ADD (Bit 0)                                           */
#define R_XSPI0_CDBUF_CDA_ADD_Msk         (0xffffffffUL) /*!< ADD (Bitfield-Mask: 0xffffffff)                       */
/* =========================================================  CDD0  ========================================================== */
#define R_XSPI0_CDBUF_CDD0_DATA_Pos       (0UL)          /*!< DATA (Bit 0)                                          */
#define R_XSPI0_CDBUF_CDD0_DATA_Msk       (0xffffffffUL) /*!< DATA (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  CDD1  ========================================================== */
#define R_XSPI0_CDBUF_CDD1_DATA_Pos       (0UL)          /*!< DATA (Bit 0)                                          */
#define R_XSPI0_CDBUF_CDD1_DATA_Msk       (0xffffffffUL) /*!< DATA (Bitfield-Mask: 0xffffffff)                      */

/* =========================================================================================================================== */
/* ================                                          CCCTLCS                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  CCCTL0  ========================================================= */
#define R_XSPI0_CCCTLCS_CCCTL0_CAEN_Pos          (0UL)          /*!< CAEN (Bit 0)                                          */
#define R_XSPI0_CCCTLCS_CCCTL0_CAEN_Msk          (0x1UL)        /*!< CAEN (Bitfield-Mask: 0x01)                            */
#define R_XSPI0_CCCTLCS_CCCTL0_CANOWR_Pos        (1UL)          /*!< CANOWR (Bit 1)                                        */
#define R_XSPI0_CCCTLCS_CCCTL0_CANOWR_Msk        (0x2UL)        /*!< CANOWR (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_CCCTLCS_CCCTL0_CAITV_Pos         (8UL)          /*!< CAITV (Bit 8)                                         */
#define R_XSPI0_CCCTLCS_CCCTL0_CAITV_Msk         (0x1f00UL)     /*!< CAITV (Bitfield-Mask: 0x1f)                           */
#define R_XSPI0_CCCTLCS_CCCTL0_CASFTSTA_Pos      (16UL)         /*!< CASFTSTA (Bit 16)                                     */
#define R_XSPI0_CCCTLCS_CCCTL0_CASFTSTA_Msk      (0x1f0000UL)   /*!< CASFTSTA (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTLCS_CCCTL0_CASFTEND_Pos      (24UL)         /*!< CASFTEND (Bit 24)                                     */
#define R_XSPI0_CCCTLCS_CCCTL0_CASFTEND_Msk      (0x1f000000UL) /*!< CASFTEND (Bitfield-Mask: 0x1f)                        */
/* ========================================================  CCCTL1  ========================================================= */
#define R_XSPI0_CCCTLCS_CCCTL1_CACMDSIZE_Pos     (0UL)          /*!< CACMDSIZE (Bit 0)                                     */
#define R_XSPI0_CCCTLCS_CCCTL1_CACMDSIZE_Msk     (0x3UL)        /*!< CACMDSIZE (Bitfield-Mask: 0x03)                       */
#define R_XSPI0_CCCTLCS_CCCTL1_CAADDSIZE_Pos     (2UL)          /*!< CAADDSIZE (Bit 2)                                     */
#define R_XSPI0_CCCTLCS_CCCTL1_CAADDSIZE_Msk     (0x1cUL)       /*!< CAADDSIZE (Bitfield-Mask: 0x07)                       */
#define R_XSPI0_CCCTLCS_CCCTL1_CADATASIZE_Pos    (5UL)          /*!< CADATASIZE (Bit 5)                                    */
#define R_XSPI0_CCCTLCS_CCCTL1_CADATASIZE_Msk    (0x1e0UL)      /*!< CADATASIZE (Bitfield-Mask: 0x0f)                      */
#define R_XSPI0_CCCTLCS_CCCTL1_CAWRLATE_Pos      (16UL)         /*!< CAWRLATE (Bit 16)                                     */
#define R_XSPI0_CCCTLCS_CCCTL1_CAWRLATE_Msk      (0x1f0000UL)   /*!< CAWRLATE (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTLCS_CCCTL1_CARDLATE_Pos      (24UL)         /*!< CARDLATE (Bit 24)                                     */
#define R_XSPI0_CCCTLCS_CCCTL1_CARDLATE_Msk      (0x1f000000UL) /*!< CARDLATE (Bitfield-Mask: 0x1f)                        */
/* ========================================================  CCCTL2  ========================================================= */
#define R_XSPI0_CCCTLCS_CCCTL2_CAWRCMD_Pos       (0UL)          /*!< CAWRCMD (Bit 0)                                       */
#define R_XSPI0_CCCTLCS_CCCTL2_CAWRCMD_Msk       (0xffffUL)     /*!< CAWRCMD (Bitfield-Mask: 0xffff)                       */
#define R_XSPI0_CCCTLCS_CCCTL2_CARDCMD_Pos       (16UL)         /*!< CARDCMD (Bit 16)                                      */
#define R_XSPI0_CCCTLCS_CCCTL2_CARDCMD_Msk       (0xffff0000UL) /*!< CARDCMD (Bitfield-Mask: 0xffff)                       */
/* ========================================================  CCCTL3  ========================================================= */
#define R_XSPI0_CCCTLCS_CCCTL3_CAADD_Pos         (0UL)          /*!< CAADD (Bit 0)                                         */
#define R_XSPI0_CCCTLCS_CCCTL3_CAADD_Msk         (0xffffffffUL) /*!< CAADD (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  CCCTL4  ========================================================= */
#define R_XSPI0_CCCTLCS_CCCTL4_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTLCS_CCCTL4_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  CCCTL5  ========================================================= */
#define R_XSPI0_CCCTLCS_CCCTL5_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTLCS_CCCTL5_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  CCCTL6  ========================================================= */
#define R_XSPI0_CCCTLCS_CCCTL6_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTLCS_CCCTL6_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  CCCTL7  ========================================================= */
#define R_XSPI0_CCCTLCS_CCCTL7_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTLCS_CCCTL7_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */

/* =========================================================================================================================== */
/* ================                                          R_XSPI0                                          ================ */
/* =========================================================================================================================== */

/* ========================================================  WRAPCFG  ======================================================== */
#define R_XSPI0_WRAPCFG_DSSFTCS1_Pos        (24UL)         /*!< DSSFTCS1 (Bit 24)                                     */
#define R_XSPI0_WRAPCFG_DSSFTCS1_Msk        (0x1f000000UL) /*!< DSSFTCS1 (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_WRAPCFG_DSSFTCS0_Pos        (8UL)          /*!< DSSFTCS0 (Bit 8)                                      */
#define R_XSPI0_WRAPCFG_DSSFTCS0_Msk        (0x1f00UL)     /*!< DSSFTCS0 (Bitfield-Mask: 0x1f)                        */
/* ========================================================  COMCFG  ========================================================= */
#define R_XSPI0_COMCFG_OENEGEX_Pos          (17UL)         /*!< OENEGEX (Bit 17)                                      */
#define R_XSPI0_COMCFG_OENEGEX_Msk          (0x20000UL)    /*!< OENEGEX (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_COMCFG_OEASTEX_Pos          (16UL)         /*!< OEASTEX (Bit 16)                                      */
#define R_XSPI0_COMCFG_OEASTEX_Msk          (0x10000UL)    /*!< OEASTEX (Bitfield-Mask: 0x01)                         */
/* =======================================================  BMCFGCH0  ======================================================== */
#define R_XSPI0_BMCFGCH_CMBTIM_Pos          (24UL)         /*!< CMBTIM (Bit 24)                                       */
#define R_XSPI0_BMCFGCH_CMBTIM_Msk          (0xff000000UL) /*!< CMBTIM (Bitfield-Mask: 0xff)                          */
#define R_XSPI0_BMCFGCH_PREEN_Pos           (16UL)         /*!< PREEN (Bit 16)                                        */
#define R_XSPI0_BMCFGCH_PREEN_Msk           (0x10000UL)    /*!< PREEN (Bitfield-Mask: 0x01)                           */
#define R_XSPI0_BMCFGCH_MWRSIZE_Pos         (8UL)          /*!< MWRSIZE (Bit 8)                                       */
#define R_XSPI0_BMCFGCH_MWRSIZE_Msk         (0xff00UL)     /*!< MWRSIZE (Bitfield-Mask: 0xff)                         */
#define R_XSPI0_BMCFGCH_MWRCOMB_Pos         (7UL)          /*!< MWRCOMB (Bit 7)                                       */
#define R_XSPI0_BMCFGCH_MWRCOMB_Msk         (0x80UL)       /*!< MWRCOMB (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_BMCFGCH_WRMD_Pos            (0UL)          /*!< WRMD (Bit 0)                                          */
#define R_XSPI0_BMCFGCH_WRMD_Msk            (0x1UL)        /*!< WRMD (Bitfield-Mask: 0x01)                            */
/* =======================================================  LIOCFGCS  ======================================================== */
#define R_XSPI0_LIOCFGCS_PRTMD_Pos          (0UL)          /*!< PRTMD (Bit 0)                                         */
#define R_XSPI0_LIOCFGCS_PRTMD_Msk          (0x3ffUL)      /*!< PRTMD (Bitfield-Mask: 0x3ff)                          */
#define R_XSPI0_LIOCFGCS_LATEMD_Pos         (10UL)         /*!< LATEMD (Bit 10)                                       */
#define R_XSPI0_LIOCFGCS_LATEMD_Msk         (0x400UL)      /*!< LATEMD (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_LIOCFGCS_WRMSKMD_Pos        (11UL)         /*!< WRMSKMD (Bit 11)                                      */
#define R_XSPI0_LIOCFGCS_WRMSKMD_Msk        (0x800UL)      /*!< WRMSKMD (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_LIOCFGCS_CSMIN_Pos          (16UL)         /*!< CSMIN (Bit 16)                                        */
#define R_XSPI0_LIOCFGCS_CSMIN_Msk          (0xf0000UL)    /*!< CSMIN (Bitfield-Mask: 0x0f)                           */
#define R_XSPI0_LIOCFGCS_CSASTEX_Pos        (20UL)         /*!< CSASTEX (Bit 20)                                      */
#define R_XSPI0_LIOCFGCS_CSASTEX_Msk        (0x100000UL)   /*!< CSASTEX (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_LIOCFGCS_CSNEGEX_Pos        (21UL)         /*!< CSNEGEX (Bit 21)                                      */
#define R_XSPI0_LIOCFGCS_CSNEGEX_Msk        (0x200000UL)   /*!< CSNEGEX (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_LIOCFGCS_SDRDRV_Pos         (22UL)         /*!< SDRDRV (Bit 22)                                       */
#define R_XSPI0_LIOCFGCS_SDRDRV_Msk         (0x400000UL)   /*!< SDRDRV (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_LIOCFGCS_SDRSMPMD_Pos       (23UL)         /*!< SDRSMPMD (Bit 23)                                     */
#define R_XSPI0_LIOCFGCS_SDRSMPMD_Msk       (0x800000UL)   /*!< SDRSMPMD (Bitfield-Mask: 0x01)                        */
#define R_XSPI0_LIOCFGCS_SDRSMPSFT_Pos      (24UL)         /*!< SDRSMPSFT (Bit 24)                                    */
#define R_XSPI0_LIOCFGCS_SDRSMPSFT_Msk      (0xf000000UL)  /*!< SDRSMPSFT (Bitfield-Mask: 0x0f)                       */
#define R_XSPI0_LIOCFGCS_DDRSMPEX_Pos       (28UL)         /*!< DDRSMPEX (Bit 28)                                     */
#define R_XSPI0_LIOCFGCS_DDRSMPEX_Msk       (0xf0000000UL) /*!< DDRSMPEX (Bitfield-Mask: 0x0f)                        */
                                                           /* =======================================================  MEMEXTCFG  ======================================================= */
#define R_XSPI0_MEMEXTCFG_DSVLDMDCS1_Pos    (12UL)         /*!< DSVLDMDCS1 (Bit 12)                                   */
#define R_XSPI0_MEMEXTCFG_DSVLDMDCS1_Msk    (0x1000UL)     /*!< DSVLDMDCS1 (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_MEMEXTCFG_DSEXTMDCS1_Pos    (8UL)          /*!< DSEXTMDCS1 (Bit 8)                                    */
#define R_XSPI0_MEMEXTCFG_DSEXTMDCS1_Msk    (0x100UL)      /*!< DSEXTMDCS1 (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_MEMEXTCFG_DSVLDMDCS0_Pos    (4UL)          /*!< DSVLDMDCS0 (Bit 4)                                    */
#define R_XSPI0_MEMEXTCFG_DSVLDMDCS0_Msk    (0x10UL)       /*!< DSVLDMDCS0 (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_MEMEXTCFG_DSEXTMDCS0_Pos    (0UL)          /*!< DSEXTMDCS0 (Bit 0)                                    */
#define R_XSPI0_MEMEXTCFG_DSEXTMDCS0_Msk    (0x1UL)        /*!< DSEXTMDCS0 (Bitfield-Mask: 0x01)                      */
/* ========================================================  BMCTL0  ========================================================= */
#define R_XSPI0_BMCTL0_CH0CS1ACC_Pos        (2UL)          /*!< CH0CS1ACC (Bit 2)                                     */
#define R_XSPI0_BMCTL0_CH0CS1ACC_Msk        (0xcUL)        /*!< CH0CS1ACC (Bitfield-Mask: 0x03)                       */
#define R_XSPI0_BMCTL0_CH0CS0ACC_Pos        (0UL)          /*!< CH0CS0ACC (Bit 0)                                     */
#define R_XSPI0_BMCTL0_CH0CS0ACC_Msk        (0x3UL)        /*!< CH0CS0ACC (Bitfield-Mask: 0x03)                       */
/* ========================================================  BMCTL1  ========================================================= */
#define R_XSPI0_BMCTL1_PBUFCLRCH0_Pos       (10UL)         /*!< PBUFCLRCH0 (Bit 10)                                   */
#define R_XSPI0_BMCTL1_PBUFCLRCH0_Msk       (0x400UL)      /*!< PBUFCLRCH0 (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_BMCTL1_MWRPUSHCH0_Pos       (8UL)          /*!< MWRPUSHCH0 (Bit 8)                                    */
#define R_XSPI0_BMCTL1_MWRPUSHCH0_Msk       (0x100UL)      /*!< MWRPUSHCH0 (Bitfield-Mask: 0x01)                      */
/* =======================================================  CMCTLCH  ======================================================== */
#define R_XSPI0_CMCTLCH_XIPEN_Pos           (16UL)         /*!< XIPEN (Bit 16)                                        */
#define R_XSPI0_CMCTLCH_XIPEN_Msk           (0x10000UL)    /*!< XIPEN (Bitfield-Mask: 0x01)                           */
#define R_XSPI0_CMCTLCH_XIPEXCODE_Pos       (8UL)          /*!< XIPEXCODE (Bit 8)                                     */
#define R_XSPI0_CMCTLCH_XIPEXCODE_Msk       (0xff00UL)     /*!< XIPEXCODE (Bitfield-Mask: 0xff)                       */
#define R_XSPI0_CMCTLCH_XIPENCODE_Pos       (0UL)          /*!< XIPENCODE (Bit 0)                                     */
#define R_XSPI0_CMCTLCH_XIPENCODE_Msk       (0xffUL)       /*!< XIPENCODE (Bitfield-Mask: 0xff)                       */
/* ========================================================  CDCTL0  ========================================================= */
#define R_XSPI0_CDCTL0_PERREP_Pos           (24UL)         /*!< PERREP (Bit 24)                                       */
#define R_XSPI0_CDCTL0_PERREP_Msk           (0xf000000UL)  /*!< PERREP (Bitfield-Mask: 0x0f)                          */
#define R_XSPI0_CDCTL0_PERITV_Pos           (16UL)         /*!< PERITV (Bit 16)                                       */
#define R_XSPI0_CDCTL0_PERITV_Msk           (0x1f0000UL)   /*!< PERITV (Bitfield-Mask: 0x1f)                          */
#define R_XSPI0_CDCTL0_THORN_Pos            (4UL)          /*!< THORN (Bit 4)                                         */
#define R_XSPI0_CDCTL0_THORN_Msk            (0x30UL)       /*!< THORN (Bitfield-Mask: 0x03)                           */
#define R_XSPI0_CDCTL0_CSSEL_Pos            (3UL)          /*!< CSSEL (Bit 3)                                         */
#define R_XSPI0_CDCTL0_CSSEL_Msk            (0x8UL)        /*!< CSSEL (Bitfield-Mask: 0x01)                           */
#define R_XSPI0_CDCTL0_PERMD_Pos            (1UL)          /*!< PERMD (Bit 1)                                         */
#define R_XSPI0_CDCTL0_PERMD_Msk            (0x2UL)        /*!< PERMD (Bitfield-Mask: 0x01)                           */
#define R_XSPI0_CDCTL0_TRREQ_Pos            (0UL)          /*!< TRREQ (Bit 0)                                         */
#define R_XSPI0_CDCTL0_TRREQ_Msk            (0x1UL)        /*!< TRREQ (Bitfield-Mask: 0x01)                           */
/* ========================================================  CDCTL1  ========================================================= */
#define R_XSPI0_CDCTL1_PEREXP_Pos           (0UL)          /*!< PEREXP (Bit 0)                                        */
#define R_XSPI0_CDCTL1_PEREXP_Msk           (0xffffffffUL) /*!< PEREXP (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  CDCTL2  ========================================================= */
#define R_XSPI0_CDCTL2_PERMSK_Pos           (0UL)          /*!< PERMSK (Bit 0)                                        */
#define R_XSPI0_CDCTL2_PERMSK_Msk           (0xffffffffUL) /*!< PERMSK (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  LPCTL0  ========================================================= */
#define R_XSPI0_LPCTL0_XD2VAL_Pos           (31UL)         /*!< XD2VAL (Bit 31)                                       */
#define R_XSPI0_LPCTL0_XD2VAL_Msk           (0x80000000UL) /*!< XD2VAL (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_LPCTL0_XD2LEN_Pos           (24UL)         /*!< XD2LEN (Bit 24)                                       */
#define R_XSPI0_LPCTL0_XD2LEN_Msk           (0x1f000000UL) /*!< XD2LEN (Bitfield-Mask: 0x1f)                          */
#define R_XSPI0_LPCTL0_XD1VAL_Pos           (23UL)         /*!< XD1VAL (Bit 23)                                       */
#define R_XSPI0_LPCTL0_XD1VAL_Msk           (0x800000UL)   /*!< XD1VAL (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_LPCTL0_XD1LEN_Pos           (16UL)         /*!< XD1LEN (Bit 16)                                       */
#define R_XSPI0_LPCTL0_XD1LEN_Msk           (0x1f0000UL)   /*!< XD1LEN (Bitfield-Mask: 0x1f)                          */
#define R_XSPI0_LPCTL0_XDPIN_Pos            (4UL)          /*!< XDPIN (Bit 4)                                         */
#define R_XSPI0_LPCTL0_XDPIN_Msk            (0x30UL)       /*!< XDPIN (Bitfield-Mask: 0x03)                           */
#define R_XSPI0_LPCTL0_CSSEL_Pos            (3UL)          /*!< CSSEL (Bit 3)                                         */
#define R_XSPI0_LPCTL0_CSSEL_Msk            (0x8UL)        /*!< CSSEL (Bitfield-Mask: 0x01)                           */
#define R_XSPI0_LPCTL0_PATREQ_Pos           (0UL)          /*!< PATREQ (Bit 0)                                        */
#define R_XSPI0_LPCTL0_PATREQ_Msk           (0x1UL)        /*!< PATREQ (Bitfield-Mask: 0x01)                          */
/* ========================================================  LPCTL1  ========================================================= */
#define R_XSPI0_LPCTL1_RSTSU_Pos            (12UL)         /*!< RSTSU (Bit 12)                                        */
#define R_XSPI0_LPCTL1_RSTSU_Msk            (0x7000UL)     /*!< RSTSU (Bitfield-Mask: 0x07)                           */
#define R_XSPI0_LPCTL1_RSTWID_Pos           (8UL)          /*!< RSTWID (Bit 8)                                        */
#define R_XSPI0_LPCTL1_RSTWID_Msk           (0x700UL)      /*!< RSTWID (Bitfield-Mask: 0x07)                          */
#define R_XSPI0_LPCTL1_RSTREP_Pos           (4UL)          /*!< RSTREP (Bit 4)                                        */
#define R_XSPI0_LPCTL1_RSTREP_Msk           (0x30UL)       /*!< RSTREP (Bitfield-Mask: 0x03)                          */
#define R_XSPI0_LPCTL1_CSSEL_Pos            (3UL)          /*!< CSSEL (Bit 3)                                         */
#define R_XSPI0_LPCTL1_CSSEL_Msk            (0x8UL)        /*!< CSSEL (Bitfield-Mask: 0x01)                           */
#define R_XSPI0_LPCTL1_PATREQ_Pos           (0UL)          /*!< PATREQ (Bit 0)                                        */
#define R_XSPI0_LPCTL1_PATREQ_Msk           (0x3UL)        /*!< PATREQ (Bitfield-Mask: 0x03)                          */
/* ========================================================  LIOCTL  ========================================================= */
#define R_XSPI0_LIOCTL_RSTCS1_Pos           (17UL)         /*!< RSTCS1 (Bit 17)                                       */
#define R_XSPI0_LIOCTL_RSTCS1_Msk           (0x20000UL)    /*!< RSTCS1 (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_LIOCTL_RSTCS0_Pos           (16UL)         /*!< RSTCS0 (Bit 16)                                       */
#define R_XSPI0_LIOCTL_RSTCS0_Msk           (0x10000UL)    /*!< RSTCS0 (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_LIOCTL_WPCS1_Pos            (1UL)          /*!< WPCS1 (Bit 1)                                         */
#define R_XSPI0_LIOCTL_WPCS1_Msk            (0x2UL)        /*!< WPCS1 (Bitfield-Mask: 0x01)                           */
#define R_XSPI0_LIOCTL_WPCS0_Pos            (0UL)          /*!< WPCS0 (Bit 0)                                         */
#define R_XSPI0_LIOCTL_WPCS0_Msk            (0x1UL)        /*!< WPCS0 (Bitfield-Mask: 0x01)                           */
/* =======================================================  CCCTL0CS0  ======================================================= */
#define R_XSPI0_CCCTL0CS0_CASFTEND_Pos      (24UL)         /*!< CASFTEND (Bit 24)                                     */
#define R_XSPI0_CCCTL0CS0_CASFTEND_Msk      (0x1f000000UL) /*!< CASFTEND (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTL0CS0_CASFTSTA_Pos      (16UL)         /*!< CASFTSTA (Bit 16)                                     */
#define R_XSPI0_CCCTL0CS0_CASFTSTA_Msk      (0x1f0000UL)   /*!< CASFTSTA (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTL0CS0_CAITV_Pos         (8UL)          /*!< CAITV (Bit 8)                                         */
#define R_XSPI0_CCCTL0CS0_CAITV_Msk         (0x1f00UL)     /*!< CAITV (Bitfield-Mask: 0x1f)                           */
#define R_XSPI0_CCCTL0CS0_CANOWR_Pos        (1UL)          /*!< CANOWR (Bit 1)                                        */
#define R_XSPI0_CCCTL0CS0_CANOWR_Msk        (0x2UL)        /*!< CANOWR (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_CCCTL0CS0_CAEN_Pos          (0UL)          /*!< CAEN (Bit 0)                                          */
#define R_XSPI0_CCCTL0CS0_CAEN_Msk          (0x1UL)        /*!< CAEN (Bitfield-Mask: 0x01)                            */
/* =======================================================  CCCTL0CS1  ======================================================= */
#define R_XSPI0_CCCTL0CS1_CASFTEND_Pos      (24UL)         /*!< CASFTEND (Bit 24)                                     */
#define R_XSPI0_CCCTL0CS1_CASFTEND_Msk      (0x1f000000UL) /*!< CASFTEND (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTL0CS1_CASFTSTA_Pos      (16UL)         /*!< CASFTSTA (Bit 16)                                     */
#define R_XSPI0_CCCTL0CS1_CASFTSTA_Msk      (0x1f0000UL)   /*!< CASFTSTA (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTL0CS1_CAITV_Pos         (8UL)          /*!< CAITV (Bit 8)                                         */
#define R_XSPI0_CCCTL0CS1_CAITV_Msk         (0x1f00UL)     /*!< CAITV (Bitfield-Mask: 0x1f)                           */
#define R_XSPI0_CCCTL0CS1_CANOWR_Pos        (1UL)          /*!< CANOWR (Bit 1)                                        */
#define R_XSPI0_CCCTL0CS1_CANOWR_Msk        (0x2UL)        /*!< CANOWR (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_CCCTL0CS1_CAEN_Pos          (0UL)          /*!< CAEN (Bit 0)                                          */
#define R_XSPI0_CCCTL0CS1_CAEN_Msk          (0x1UL)        /*!< CAEN (Bitfield-Mask: 0x01)                            */
/* =======================================================  CCCTL1CS0  ======================================================= */
#define R_XSPI0_CCCTL1CS0_CARDLATE_Pos      (24UL)         /*!< CARDLATE (Bit 24)                                     */
#define R_XSPI0_CCCTL1CS0_CARDLATE_Msk      (0x1f000000UL) /*!< CARDLATE (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTL1CS0_CAWRLATE_Pos      (16UL)         /*!< CAWRLATE (Bit 16)                                     */
#define R_XSPI0_CCCTL1CS0_CAWRLATE_Msk      (0x1f0000UL)   /*!< CAWRLATE (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTL1CS0_CADATASIZE_Pos    (5UL)          /*!< CADATASIZE (Bit 5)                                    */
#define R_XSPI0_CCCTL1CS0_CADATASIZE_Msk    (0x1e0UL)      /*!< CADATASIZE (Bitfield-Mask: 0x0f)                      */
#define R_XSPI0_CCCTL1CS0_CAADDSIZE_Pos     (2UL)          /*!< CAADDSIZE (Bit 2)                                     */
#define R_XSPI0_CCCTL1CS0_CAADDSIZE_Msk     (0x1cUL)       /*!< CAADDSIZE (Bitfield-Mask: 0x07)                       */
#define R_XSPI0_CCCTL1CS0_CACMDSIZE_Pos     (0UL)          /*!< CACMDSIZE (Bit 0)                                     */
#define R_XSPI0_CCCTL1CS0_CACMDSIZE_Msk     (0x3UL)        /*!< CACMDSIZE (Bitfield-Mask: 0x03)                       */
/* =======================================================  CCCTL1CS1  ======================================================= */
#define R_XSPI0_CCCTL1CS1_CARDLATE_Pos      (24UL)         /*!< CARDLATE (Bit 24)                                     */
#define R_XSPI0_CCCTL1CS1_CARDLATE_Msk      (0x1f000000UL) /*!< CARDLATE (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTL1CS1_CAWRLATE_Pos      (16UL)         /*!< CAWRLATE (Bit 16)                                     */
#define R_XSPI0_CCCTL1CS1_CAWRLATE_Msk      (0x1f0000UL)   /*!< CAWRLATE (Bitfield-Mask: 0x1f)                        */
#define R_XSPI0_CCCTL1CS1_CADATASIZE_Pos    (5UL)          /*!< CADATASIZE (Bit 5)                                    */
#define R_XSPI0_CCCTL1CS1_CADATASIZE_Msk    (0x1e0UL)      /*!< CADATASIZE (Bitfield-Mask: 0x0f)                      */
#define R_XSPI0_CCCTL1CS1_CAADDSIZE_Pos     (2UL)          /*!< CAADDSIZE (Bit 2)                                     */
#define R_XSPI0_CCCTL1CS1_CAADDSIZE_Msk     (0x1cUL)       /*!< CAADDSIZE (Bitfield-Mask: 0x07)                       */
#define R_XSPI0_CCCTL1CS1_CACMDSIZE_Pos     (0UL)          /*!< CACMDSIZE (Bit 0)                                     */
#define R_XSPI0_CCCTL1CS1_CACMDSIZE_Msk     (0x3UL)        /*!< CACMDSIZE (Bitfield-Mask: 0x03)                       */
/* =======================================================  CCCTL2CS0  ======================================================= */
#define R_XSPI0_CCCTL2CS0_CARDCMD_Pos       (16UL)         /*!< CARDCMD (Bit 16)                                      */
#define R_XSPI0_CCCTL2CS0_CARDCMD_Msk       (0xffff0000UL) /*!< CARDCMD (Bitfield-Mask: 0xffff)                       */
#define R_XSPI0_CCCTL2CS0_CAWRCMD_Pos       (0UL)          /*!< CAWRCMD (Bit 0)                                       */
#define R_XSPI0_CCCTL2CS0_CAWRCMD_Msk       (0xffffUL)     /*!< CAWRCMD (Bitfield-Mask: 0xffff)                       */
/* =======================================================  CCCTL2CS1  ======================================================= */
#define R_XSPI0_CCCTL2CS1_CARDCMD_Pos       (16UL)         /*!< CARDCMD (Bit 16)                                      */
#define R_XSPI0_CCCTL2CS1_CARDCMD_Msk       (0xffff0000UL) /*!< CARDCMD (Bitfield-Mask: 0xffff)                       */
#define R_XSPI0_CCCTL2CS1_CAWRCMD_Pos       (0UL)          /*!< CAWRCMD (Bit 0)                                       */
#define R_XSPI0_CCCTL2CS1_CAWRCMD_Msk       (0xffffUL)     /*!< CAWRCMD (Bitfield-Mask: 0xffff)                       */
/* =======================================================  CCCTL3CS0  ======================================================= */
#define R_XSPI0_CCCTL3CS0_CAADD_Pos         (0UL)          /*!< CAADD (Bit 0)                                         */
#define R_XSPI0_CCCTL3CS0_CAADD_Msk         (0xffffffffUL) /*!< CAADD (Bitfield-Mask: 0xffffffff)                     */
/* =======================================================  CCCTL3CS1  ======================================================= */
#define R_XSPI0_CCCTL3CS1_CAADD_Pos         (0UL)          /*!< CAADD (Bit 0)                                         */
#define R_XSPI0_CCCTL3CS1_CAADD_Msk         (0xffffffffUL) /*!< CAADD (Bitfield-Mask: 0xffffffff)                     */
/* =======================================================  CCCTL4CS0  ======================================================= */
#define R_XSPI0_CCCTL4CS0_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTL4CS0_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  CCCTL4CS1  ======================================================= */
#define R_XSPI0_CCCTL4CS1_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTL4CS1_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  CCCTL5CS0  ======================================================= */
#define R_XSPI0_CCCTL5CS0_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTL5CS0_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  CCCTL5CS1  ======================================================= */
#define R_XSPI0_CCCTL5CS1_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTL5CS1_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  CCCTL6CS0  ======================================================= */
#define R_XSPI0_CCCTL6CS0_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTL6CS0_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  CCCTL6CS1  ======================================================= */
#define R_XSPI0_CCCTL6CS1_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTL6CS1_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  CCCTL7CS0  ======================================================= */
#define R_XSPI0_CCCTL7CS0_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTL7CS0_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* =======================================================  CCCTL7CS1  ======================================================= */
#define R_XSPI0_CCCTL7CS1_CADATA_Pos        (0UL)          /*!< CADATA (Bit 0)                                        */
#define R_XSPI0_CCCTL7CS1_CADATA_Msk        (0xffffffffUL) /*!< CADATA (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  VERSTT  ========================================================= */
#define R_XSPI0_VERSTT_VER_Pos              (0UL)          /*!< VER (Bit 0)                                           */
#define R_XSPI0_VERSTT_VER_Msk              (0xffffffffUL) /*!< VER (Bitfield-Mask: 0xffffffff)                       */
/* ========================================================  COMSTT  ========================================================= */
#define R_XSPI0_COMSTT_RSTOCS1_Pos          (22UL)         /*!< RSTOCS1 (Bit 22)                                      */
#define R_XSPI0_COMSTT_RSTOCS1_Msk          (0x400000UL)   /*!< RSTOCS1 (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_COMSTT_INTCS1_Pos           (21UL)         /*!< INTCS1 (Bit 21)                                       */
#define R_XSPI0_COMSTT_INTCS1_Msk           (0x200000UL)   /*!< INTCS1 (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_COMSTT_ECSCS1_Pos           (20UL)         /*!< ECSCS1 (Bit 20)                                       */
#define R_XSPI0_COMSTT_ECSCS1_Msk           (0x100000UL)   /*!< ECSCS1 (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_COMSTT_RSTOCS0_Pos          (18UL)         /*!< RSTOCS0 (Bit 18)                                      */
#define R_XSPI0_COMSTT_RSTOCS0_Msk          (0x40000UL)    /*!< RSTOCS0 (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_COMSTT_INTCS0_Pos           (17UL)         /*!< INTCS0 (Bit 17)                                       */
#define R_XSPI0_COMSTT_INTCS0_Msk           (0x20000UL)    /*!< INTCS0 (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_COMSTT_ECSCS0_Pos           (16UL)         /*!< ECSCS0 (Bit 16)                                       */
#define R_XSPI0_COMSTT_ECSCS0_Msk           (0x10000UL)    /*!< ECSCS0 (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_COMSTT_WRBUFNECH0_Pos       (6UL)          /*!< WRBUFNECH0 (Bit 6)                                    */
#define R_XSPI0_COMSTT_WRBUFNECH0_Msk       (0x40UL)       /*!< WRBUFNECH0 (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_COMSTT_PBUFNECH0_Pos        (4UL)          /*!< PBUFNECH0 (Bit 4)                                     */
#define R_XSPI0_COMSTT_PBUFNECH0_Msk        (0x10UL)       /*!< PBUFNECH0 (Bitfield-Mask: 0x01)                       */
#define R_XSPI0_COMSTT_MEMACCCH0_Pos        (0UL)          /*!< MEMACCCH0 (Bit 0)                                     */
#define R_XSPI0_COMSTT_MEMACCCH0_Msk        (0x1UL)        /*!< MEMACCCH0 (Bitfield-Mask: 0x01)                       */
/* ========================================================  CASTTCS  ======================================================== */
#define R_XSPI0_CASTTCS_CASUC_Pos           (0UL)          /*!< CASUC (Bit 0)                                         */
#define R_XSPI0_CASTTCS_CASUC_Msk           (0xffffffffUL) /*!< CASUC (Bitfield-Mask: 0xffffffff)                     */
/* =========================================================  INTS  ========================================================== */
#define R_XSPI0_INTS_CASUCCS1_Pos           (31UL)         /*!< CASUCCS1 (Bit 31)                                     */
#define R_XSPI0_INTS_CASUCCS1_Msk           (0x80000000UL) /*!< CASUCCS1 (Bitfield-Mask: 0x01)                        */
#define R_XSPI0_INTS_CASUCCS0_Pos           (30UL)         /*!< CASUCCS0 (Bit 30)                                     */
#define R_XSPI0_INTS_CASUCCS0_Msk           (0x40000000UL) /*!< CASUCCS0 (Bitfield-Mask: 0x01)                        */
#define R_XSPI0_INTS_CAFAILCS1_Pos          (29UL)         /*!< CAFAILCS1 (Bit 29)                                    */
#define R_XSPI0_INTS_CAFAILCS1_Msk          (0x20000000UL) /*!< CAFAILCS1 (Bitfield-Mask: 0x01)                       */
#define R_XSPI0_INTS_CAFAILCS0_Pos          (28UL)         /*!< CAFAILCS0 (Bit 28)                                    */
#define R_XSPI0_INTS_CAFAILCS0_Msk          (0x10000000UL) /*!< CAFAILCS0 (Bitfield-Mask: 0x01)                       */
#define R_XSPI0_INTS_BUSERRCH1_Pos          (21UL)         /*!< BUSERRCH1 (Bit 21)                                    */
#define R_XSPI0_INTS_BUSERRCH1_Msk          (0x200000UL)   /*!< BUSERRCH1 (Bitfield-Mask: 0x01)                       */
#define R_XSPI0_INTS_BUSERRCH0_Pos          (20UL)         /*!< BUSERRCH0 (Bit 20)                                    */
#define R_XSPI0_INTS_BUSERRCH0_Msk          (0x100000UL)   /*!< BUSERRCH0 (Bitfield-Mask: 0x01)                       */
#define R_XSPI0_INTS_INTCS1_Pos             (13UL)         /*!< INTCS1 (Bit 13)                                       */
#define R_XSPI0_INTS_INTCS1_Msk             (0x2000UL)     /*!< INTCS1 (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_INTS_ECSCS1_Pos             (9UL)          /*!< ECSCS1 (Bit 9)                                        */
#define R_XSPI0_INTS_ECSCS1_Msk             (0x200UL)      /*!< ECSCS1 (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_INTS_DSTOCS1_Pos            (5UL)          /*!< DSTOCS1 (Bit 5)                                       */
#define R_XSPI0_INTS_DSTOCS1_Msk            (0x20UL)       /*!< DSTOCS1 (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTS_DSTOCS0_Pos            (4UL)          /*!< DSTOCS0 (Bit 4)                                       */
#define R_XSPI0_INTS_DSTOCS0_Msk            (0x10UL)       /*!< DSTOCS0 (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTS_PERTO_Pos              (3UL)          /*!< PERTO (Bit 3)                                         */
#define R_XSPI0_INTS_PERTO_Msk              (0x8UL)        /*!< PERTO (Bitfield-Mask: 0x01)                           */
#define R_XSPI0_INTS_INICMP_Pos             (2UL)          /*!< INICMP (Bit 2)                                        */
#define R_XSPI0_INTS_INICMP_Msk             (0x4UL)        /*!< INICMP (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_INTS_PATCMP_Pos             (1UL)          /*!< PATCMP (Bit 1)                                        */
#define R_XSPI0_INTS_PATCMP_Msk             (0x2UL)        /*!< PATCMP (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_INTS_CMDCMP_Pos             (0UL)          /*!< CMDCMP (Bit 0)                                        */
#define R_XSPI0_INTS_CMDCMP_Msk             (0x1UL)        /*!< CMDCMP (Bitfield-Mask: 0x01)                          */
/* =========================================================  INTC  ========================================================== */
#define R_XSPI0_INTC_CASUCCS1C_Pos          (31UL)         /*!< CASUCCS1C (Bit 31)                                    */
#define R_XSPI0_INTC_CASUCCS1C_Msk          (0x80000000UL) /*!< CASUCCS1C (Bitfield-Mask: 0x01)                       */
#define R_XSPI0_INTC_CASUCCS0C_Pos          (30UL)         /*!< CASUCCS0C (Bit 30)                                    */
#define R_XSPI0_INTC_CASUCCS0C_Msk          (0x40000000UL) /*!< CASUCCS0C (Bitfield-Mask: 0x01)                       */
#define R_XSPI0_INTC_CAFAILCS1C_Pos         (29UL)         /*!< CAFAILCS1C (Bit 29)                                   */
#define R_XSPI0_INTC_CAFAILCS1C_Msk         (0x20000000UL) /*!< CAFAILCS1C (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_INTC_CAFAILCS0C_Pos         (28UL)         /*!< CAFAILCS0C (Bit 28)                                   */
#define R_XSPI0_INTC_CAFAILCS0C_Msk         (0x10000000UL) /*!< CAFAILCS0C (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_INTC_BUSERRCH1C_Pos         (21UL)         /*!< BUSERRCH1C (Bit 21)                                   */
#define R_XSPI0_INTC_BUSERRCH1C_Msk         (0x200000UL)   /*!< BUSERRCH1C (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_INTC_BUSERRCH0C_Pos         (20UL)         /*!< BUSERRCH0C (Bit 20)                                   */
#define R_XSPI0_INTC_BUSERRCH0C_Msk         (0x100000UL)   /*!< BUSERRCH0C (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_INTC_INTCS1C_Pos            (13UL)         /*!< INTCS1C (Bit 13)                                      */
#define R_XSPI0_INTC_INTCS1C_Msk            (0x2000UL)     /*!< INTCS1C (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTC_ECSCS1C_Pos            (9UL)          /*!< ECSCS1C (Bit 9)                                       */
#define R_XSPI0_INTC_ECSCS1C_Msk            (0x200UL)      /*!< ECSCS1C (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTC_DSTOCS1C_Pos           (5UL)          /*!< DSTOCS1C (Bit 5)                                      */
#define R_XSPI0_INTC_DSTOCS1C_Msk           (0x20UL)       /*!< DSTOCS1C (Bitfield-Mask: 0x01)                        */
#define R_XSPI0_INTC_DSTOCS0C_Pos           (4UL)          /*!< DSTOCS0C (Bit 4)                                      */
#define R_XSPI0_INTC_DSTOCS0C_Msk           (0x10UL)       /*!< DSTOCS0C (Bitfield-Mask: 0x01)                        */
#define R_XSPI0_INTC_PERTOC_Pos             (3UL)          /*!< PERTOC (Bit 3)                                        */
#define R_XSPI0_INTC_PERTOC_Msk             (0x8UL)        /*!< PERTOC (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_INTC_INICMPC_Pos            (2UL)          /*!< INICMPC (Bit 2)                                       */
#define R_XSPI0_INTC_INICMPC_Msk            (0x4UL)        /*!< INICMPC (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTC_PATCMPC_Pos            (1UL)          /*!< PATCMPC (Bit 1)                                       */
#define R_XSPI0_INTC_PATCMPC_Msk            (0x2UL)        /*!< PATCMPC (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTC_CMDCMPC_Pos            (0UL)          /*!< CMDCMPC (Bit 0)                                       */
#define R_XSPI0_INTC_CMDCMPC_Msk            (0x1UL)        /*!< CMDCMPC (Bitfield-Mask: 0x01)                         */
/* =========================================================  INTE  ========================================================== */
#define R_XSPI0_INTE_CASUCCS1E_Pos          (31UL)         /*!< CASUCCS1E (Bit 31)                                    */
#define R_XSPI0_INTE_CASUCCS1E_Msk          (0x80000000UL) /*!< CASUCCS1E (Bitfield-Mask: 0x01)                       */
#define R_XSPI0_INTE_CASUCCS0E_Pos          (30UL)         /*!< CASUCCS0E (Bit 30)                                    */
#define R_XSPI0_INTE_CASUCCS0E_Msk          (0x40000000UL) /*!< CASUCCS0E (Bitfield-Mask: 0x01)                       */
#define R_XSPI0_INTE_CAFAILCS1E_Pos         (29UL)         /*!< CAFAILCS1E (Bit 29)                                   */
#define R_XSPI0_INTE_CAFAILCS1E_Msk         (0x20000000UL) /*!< CAFAILCS1E (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_INTE_CAFAILCS0E_Pos         (28UL)         /*!< CAFAILCS0E (Bit 28)                                   */
#define R_XSPI0_INTE_CAFAILCS0E_Msk         (0x10000000UL) /*!< CAFAILCS0E (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_INTE_BUSERRCH1E_Pos         (21UL)         /*!< BUSERRCH1E (Bit 21)                                   */
#define R_XSPI0_INTE_BUSERRCH1E_Msk         (0x200000UL)   /*!< BUSERRCH1E (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_INTE_BUSERRCH0E_Pos         (20UL)         /*!< BUSERRCH0E (Bit 20)                                   */
#define R_XSPI0_INTE_BUSERRCH0E_Msk         (0x100000UL)   /*!< BUSERRCH0E (Bitfield-Mask: 0x01)                      */
#define R_XSPI0_INTE_INTCS1E_Pos            (13UL)         /*!< INTCS1E (Bit 13)                                      */
#define R_XSPI0_INTE_INTCS1E_Msk            (0x2000UL)     /*!< INTCS1E (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTE_ECSCS1E_Pos            (9UL)          /*!< ECSCS1E (Bit 9)                                       */
#define R_XSPI0_INTE_ECSCS1E_Msk            (0x200UL)      /*!< ECSCS1E (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTE_DSTOCS1E_Pos           (5UL)          /*!< DSTOCS1E (Bit 5)                                      */
#define R_XSPI0_INTE_DSTOCS1E_Msk           (0x20UL)       /*!< DSTOCS1E (Bitfield-Mask: 0x01)                        */
#define R_XSPI0_INTE_DSTOCS0E_Pos           (4UL)          /*!< DSTOCS0E (Bit 4)                                      */
#define R_XSPI0_INTE_DSTOCS0E_Msk           (0x10UL)       /*!< DSTOCS0E (Bitfield-Mask: 0x01)                        */
#define R_XSPI0_INTE_PERTOE_Pos             (3UL)          /*!< PERTOE (Bit 3)                                        */
#define R_XSPI0_INTE_PERTOE_Msk             (0x8UL)        /*!< PERTOE (Bitfield-Mask: 0x01)                          */
#define R_XSPI0_INTE_INICMPE_Pos            (2UL)          /*!< INICMPE (Bit 2)                                       */
#define R_XSPI0_INTE_INICMPE_Msk            (0x4UL)        /*!< INICMPE (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTE_PATCMPE_Pos            (1UL)          /*!< PATCMPE (Bit 1)                                       */
#define R_XSPI0_INTE_PATCMPE_Msk            (0x2UL)        /*!< PATCMPE (Bitfield-Mask: 0x01)                         */
#define R_XSPI0_INTE_CMDCMPE_Pos            (0UL)          /*!< CMDCMPE (Bit 0)                                       */
#define R_XSPI0_INTE_CMDCMPE_Msk            (0x1UL)        /*!< CMDCMPE (Bitfield-Mask: 0x01)                         */

#endif /* R_XSPI0_POSMSK_H */
