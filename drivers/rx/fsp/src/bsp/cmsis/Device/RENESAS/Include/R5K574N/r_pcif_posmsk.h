/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_PCIF_POSMSK_H
#define R_PCIF_POSMSK_H

/* =========================================================================================================================== */
/* ================                                          R_PCIF0                                          ================ */
/* =========================================================================================================================== */

/* =========================================================  CLKER  ========================================================= */
#define R_PCIF0_CLKER_CLKEN_Pos             (0UL)          /*!< CLKEN (Bit 0)                                         */
#define R_PCIF0_CLKER_CLKEN_Msk             (0x1UL)        /*!< CLKEN (Bitfield-Mask: 0x01)                           */
/* =========================================================  CLKSR  ========================================================= */
#define R_PCIF0_CLKSR_CLKS_Pos              (0UL)          /*!< CLKS (Bit 0)                                          */
#define R_PCIF0_CLKSR_CLKS_Msk              (0x1UL)        /*!< CLKS (Bitfield-Mask: 0x01)                            */
/* =========================================================  CLKCR  ========================================================= */
#define R_PCIF0_CLKCR_DIVR_Pos              (8UL)          /*!< DIVR (Bit 8)                                          */
#define R_PCIF0_CLKCR_DIVR_Msk              (0x1f00UL)     /*!< DIVR (Bitfield-Mask: 0x1f)                            */
#define R_PCIF0_CLKCR_CLKSEL_Pos            (0UL)          /*!< CLKSEL (Bit 0)                                        */
#define R_PCIF0_CLKCR_CLKSEL_Msk            (0x1UL)        /*!< CLKSEL (Bitfield-Mask: 0x01)                          */
/* =========================================================  CTLR  ========================================================== */
#define R_PCIF0_CTLR_ZPOL_Pos               (10UL)         /*!< ZPOL (Bit 10)                                         */
#define R_PCIF0_CTLR_ZPOL_Msk               (0x400UL)      /*!< ZPOL (Bitfield-Mask: 0x01)                            */
#define R_PCIF0_CTLR_BPOL_Pos               (9UL)          /*!< BPOL (Bit 9)                                          */
#define R_PCIF0_CTLR_BPOL_Msk               (0x200UL)      /*!< BPOL (Bitfield-Mask: 0x01)                            */
#define R_PCIF0_CTLR_APOL_Pos               (8UL)          /*!< APOL (Bit 8)                                          */
#define R_PCIF0_CTLR_APOL_Msk               (0x100UL)      /*!< APOL (Bitfield-Mask: 0x01)                            */
#define R_PCIF0_CTLR_PCIFMD_Pos             (0UL)          /*!< PCIFMD (Bit 0)                                        */
#define R_PCIF0_CTLR_PCIFMD_Msk             (0x1UL)        /*!< PCIFMD (Bitfield-Mask: 0x01)                          */
/* ========================================================  POSMAXR  ======================================================== */
#define R_PCIF0_POSMAXR_POSMAX_Pos          (0UL)          /*!< POSMAX (Bit 0)                                        */
#define R_PCIF0_POSMAXR_POSMAX_Msk          (0xffffUL)     /*!< POSMAX (Bitfield-Mask: 0xffff)                        */
/* =========================================================  TRGR  ========================================================== */
#define R_PCIF0_TRGR_PHCSTPT_Pos            (24UL)         /*!< PHCSTPT (Bit 24)                                      */
#define R_PCIF0_TRGR_PHCSTPT_Msk            (0x1000000UL)  /*!< PHCSTPT (Bitfield-Mask: 0x01)                         */
#define R_PCIF0_TRGR_PCIFSTPT_Pos           (16UL)         /*!< PCIFSTPT (Bit 16)                                     */
#define R_PCIF0_TRGR_PCIFSTPT_Msk           (0x10000UL)    /*!< PCIFSTPT (Bitfield-Mask: 0x01)                        */
#define R_PCIF0_TRGR_PCIFSTRT_Pos           (0UL)          /*!< PCIFSTRT (Bit 0)                                      */
#define R_PCIF0_TRGR_PCIFSTRT_Msk           (0x1UL)        /*!< PCIFSTRT (Bitfield-Mask: 0x01)                        */
/* ==========================================================  SR  =========================================================== */
#define R_PCIF0_SR_PCIFPS_Pos               (0UL)          /*!< PCIFPS (Bit 0)                                        */
#define R_PCIF0_SR_PCIFPS_Msk               (0x1UL)        /*!< PCIFPS (Bitfield-Mask: 0x01)                          */
/* ========================================================  PHCCTLR  ======================================================== */
#define R_PCIF0_PHCCTLR_PHCECACMD_Pos       (24UL)         /*!< PHCECACMD (Bit 24)                                    */
#define R_PCIF0_PHCCTLR_PHCECACMD_Msk       (0x1000000UL)  /*!< PHCECACMD (Bitfield-Mask: 0x01)                       */
#define R_PCIF0_PHCCTLR_PHCCEDAMD_Pos       (16UL)         /*!< PHCCEDAMD (Bit 16)                                    */
#define R_PCIF0_PHCCTLR_PHCCEDAMD_Msk       (0x10000UL)    /*!< PHCCEDAMD (Bitfield-Mask: 0x01)                       */
#define R_PCIF0_PHCCTLR_PHCZOS_Pos          (3UL)          /*!< PHCZOS (Bit 3)                                        */
#define R_PCIF0_PHCCTLR_PHCZOS_Msk          (0x8UL)        /*!< PHCZOS (Bitfield-Mask: 0x01)                          */
#define R_PCIF0_PHCCTLR_PHCZW_Pos           (0UL)          /*!< PHCZW (Bit 0)                                         */
#define R_PCIF0_PHCCTLR_PHCZW_Msk           (0x7UL)        /*!< PHCZW (Bitfield-Mask: 0x07)                           */
/* =======================================================  PHCCEDTHR  ======================================================= */
#define R_PCIF0_PHCCEDTHR_PHCCEDTH_Pos      (0UL)          /*!< PHCCEDTH (Bit 0)                                      */
#define R_PCIF0_PHCCEDTHR_PHCCEDTH_Msk      (0xffffUL)     /*!< PHCCEDTH (Bitfield-Mask: 0xffff)                      */
/* ======================================================  PHCPERIODR  ======================================================= */
#define R_PCIF0_PHCPERIODR_PHCPERIOD_Pos    (0UL)          /*!< PHCPERIOD (Bit 0)                                     */
#define R_PCIF0_PHCPERIODR_PHCPERIOD_Msk    (0xffffUL)     /*!< PHCPERIOD (Bitfield-Mask: 0xffff)                     */
/* ========================================================  PHCECR  ========================================================= */
#define R_PCIF0_PHCECR_PHCEDGCNT_Pos        (0UL)          /*!< PHCEDGCNT (Bit 0)                                     */
#define R_PCIF0_PHCECR_PHCEDGCNT_Msk        (0xffffUL)     /*!< PHCEDGCNT (Bitfield-Mask: 0xffff)                     */
/* ========================================================  PHCPCMR  ======================================================== */
#define R_PCIF0_PHCPCMR_PHCPOSCNTM_Pos      (0UL)          /*!< PHCPOSCNTM (Bit 0)                                    */
#define R_PCIF0_PHCPCMR_PHCPOSCNTM_Msk      (0xffffUL)     /*!< PHCPOSCNTM (Bitfield-Mask: 0xffff)                    */
/* =======================================================  PHCPCWDR  ======================================================== */
#define R_PCIF0_PHCPCWDR_PHCPOSCNTWD_Pos    (0UL)          /*!< PHCPOSCNTWD (Bit 0)                                   */
#define R_PCIF0_PHCPCWDR_PHCPOSCNTWD_Msk    (0xffffUL)     /*!< PHCPOSCNTWD (Bitfield-Mask: 0xffff)                   */
/* =========================================================  PHCSR  ========================================================= */
#define R_PCIF0_PHCSR_PHCOECUES_Pos         (19UL)         /*!< PHCOECUES (Bit 19)                                    */
#define R_PCIF0_PHCSR_PHCOECUES_Msk         (0x80000UL)    /*!< PHCOECUES (Bitfield-Mask: 0x01)                       */
#define R_PCIF0_PHCSR_PHCIECOES_Pos         (18UL)         /*!< PHCIECOES (Bit 18)                                    */
#define R_PCIF0_PHCSR_PHCIECOES_Msk         (0x40000UL)    /*!< PHCIECOES (Bitfield-Mask: 0x01)                       */
#define R_PCIF0_PHCSR_PHCIECES_Pos          (17UL)         /*!< PHCIECES (Bit 17)                                     */
#define R_PCIF0_PHCSR_PHCIECES_Msk          (0x20000UL)    /*!< PHCIECES (Bitfield-Mask: 0x01)                        */
#define R_PCIF0_PHCSR_PHCCEES_Pos           (16UL)         /*!< PHCCEES (Bit 16)                                      */
#define R_PCIF0_PHCSR_PHCCEES_Msk           (0x10000UL)    /*!< PHCCEES (Bitfield-Mask: 0x01)                         */
#define R_PCIF0_PHCSR_PHCECUS_Pos           (9UL)          /*!< PHCECUS (Bit 9)                                       */
#define R_PCIF0_PHCSR_PHCECUS_Msk           (0x200UL)      /*!< PHCECUS (Bitfield-Mask: 0x01)                         */
#define R_PCIF0_PHCSR_PHCPCUS_Pos           (8UL)          /*!< PHCPCUS (Bit 8)                                       */
#define R_PCIF0_PHCSR_PHCPCUS_Msk           (0x100UL)      /*!< PHCPCUS (Bitfield-Mask: 0x01)                         */
#define R_PCIF0_PHCSR_PHCOENS_Pos           (0UL)          /*!< PHCOENS (Bit 0)                                       */
#define R_PCIF0_PHCSR_PHCOENS_Msk           (0x1UL)        /*!< PHCOENS (Bitfield-Mask: 0x01)                         */
/* ========================================================  PHCSCR  ========================================================= */
#define R_PCIF0_PHCSCR_PHCOECUESC_Pos       (19UL)         /*!< PHCOECUESC (Bit 19)                                   */
#define R_PCIF0_PHCSCR_PHCOECUESC_Msk       (0x80000UL)    /*!< PHCOECUESC (Bitfield-Mask: 0x01)                      */
#define R_PCIF0_PHCSCR_PHCIECOESC_Pos       (18UL)         /*!< PHCIECOESC (Bit 18)                                   */
#define R_PCIF0_PHCSCR_PHCIECOESC_Msk       (0x40000UL)    /*!< PHCIECOESC (Bitfield-Mask: 0x01)                      */
#define R_PCIF0_PHCSCR_PHCIECESC_Pos        (17UL)         /*!< PHCIECESC (Bit 17)                                    */
#define R_PCIF0_PHCSCR_PHCIECESC_Msk        (0x20000UL)    /*!< PHCIECESC (Bitfield-Mask: 0x01)                       */
#define R_PCIF0_PHCSCR_PHCCEESC_Pos         (16UL)         /*!< PHCCEESC (Bit 16)                                     */
#define R_PCIF0_PHCSCR_PHCCEESC_Msk         (0x10000UL)    /*!< PHCCEESC (Bitfield-Mask: 0x01)                        */
/* ========================================================  PHCSER  ========================================================= */
#define R_PCIF0_PHCSER_PHCOECUESE_Pos       (19UL)         /*!< PHCOECUESE (Bit 19)                                   */
#define R_PCIF0_PHCSER_PHCOECUESE_Msk       (0x80000UL)    /*!< PHCOECUESE (Bitfield-Mask: 0x01)                      */
#define R_PCIF0_PHCSER_PHCIECOESE_Pos       (18UL)         /*!< PHCIECOESE (Bit 18)                                   */
#define R_PCIF0_PHCSER_PHCIECOESE_Msk       (0x40000UL)    /*!< PHCIECOESE (Bitfield-Mask: 0x01)                      */
#define R_PCIF0_PHCSER_PHCIECESE_Pos        (17UL)         /*!< PHCIECESE (Bit 17)                                    */
#define R_PCIF0_PHCSER_PHCIECESE_Msk        (0x20000UL)    /*!< PHCIECESE (Bitfield-Mask: 0x01)                       */
#define R_PCIF0_PHCSER_PHCCEESE_Pos         (16UL)         /*!< PHCCEESE (Bit 16)                                     */
#define R_PCIF0_PHCSER_PHCCEESE_Msk         (0x10000UL)    /*!< PHCCEESE (Bitfield-Mask: 0x01)                        */
/* ========================================================  INCCTLR  ======================================================== */
#define R_PCIF0_INCCTLR_INCRSL_Pos          (24UL)         /*!< INCRSL (Bit 24)                                       */
#define R_PCIF0_INCCTLR_INCRSL_Msk          (0x3f000000UL) /*!< INCRSL (Bitfield-Mask: 0x3f)                          */
#define R_PCIF0_INCCTLR_INCZOMIN_Pos        (16UL)         /*!< INCZOMIN (Bit 16)                                     */
#define R_PCIF0_INCCTLR_INCZOMIN_Msk        (0xff0000UL)   /*!< INCZOMIN (Bitfield-Mask: 0xff)                        */
#define R_PCIF0_INCCTLR_INCZOS_Pos          (4UL)          /*!< INCZOS (Bit 4)                                        */
#define R_PCIF0_INCCTLR_INCZOS_Msk          (0x30UL)       /*!< INCZOS (Bitfield-Mask: 0x03)                          */
#define R_PCIF0_INCCTLR_INCOMD_Pos          (2UL)          /*!< INCOMD (Bit 2)                                        */
#define R_PCIF0_INCCTLR_INCOMD_Msk          (0x4UL)        /*!< INCOMD (Bitfield-Mask: 0x01)                          */
#define R_PCIF0_INCCTLR_INCIMD_Pos          (0UL)          /*!< INCIMD (Bit 0)                                        */
#define R_PCIF0_INCCTLR_INCIMD_Msk          (0x3UL)        /*!< INCIMD (Bitfield-Mask: 0x03)                          */
/* =======================================================  INCZGCTLR  ======================================================= */
#define R_PCIF0_INCZGCTLR_INCSWZGE_Pos      (4UL)          /*!< INCSWZGE (Bit 4)                                      */
#define R_PCIF0_INCZGCTLR_INCSWZGE_Msk      (0x10UL)       /*!< INCSWZGE (Bitfield-Mask: 0x01)                        */
#define R_PCIF0_INCZGCTLR_INCVIZGE_Pos      (3UL)          /*!< INCVIZGE (Bit 3)                                      */
#define R_PCIF0_INCZGCTLR_INCVIZGE_Msk      (0x8UL)        /*!< INCVIZGE (Bitfield-Mask: 0x01)                        */
#define R_PCIF0_INCZGCTLR_INCPIZGE_Pos      (2UL)          /*!< INCPIZGE (Bit 2)                                      */
#define R_PCIF0_INCZGCTLR_INCPIZGE_Msk      (0x4UL)        /*!< INCPIZGE (Bitfield-Mask: 0x01)                        */
#define R_PCIF0_INCZGCTLR_INCZIZGE_Pos      (1UL)          /*!< INCZIZGE (Bit 1)                                      */
#define R_PCIF0_INCZGCTLR_INCZIZGE_Msk      (0x2UL)        /*!< INCZIZGE (Bitfield-Mask: 0x01)                        */
#define R_PCIF0_INCZGCTLR_INCZAGE_Pos       (0UL)          /*!< INCZAGE (Bit 0)                                       */
#define R_PCIF0_INCZGCTLR_INCZAGE_Msk       (0x1UL)        /*!< INCZAGE (Bitfield-Mask: 0x01)                         */
/* =======================================================  INCPCCER  ======================================================== */
#define R_PCIF0_INCPCCER_INCSWCLRE_Pos      (4UL)          /*!< INCSWCLRE (Bit 4)                                     */
#define R_PCIF0_INCPCCER_INCSWCLRE_Msk      (0x10UL)       /*!< INCSWCLRE (Bitfield-Mask: 0x01)                       */
#define R_PCIF0_INCPCCER_INCVICLRE_Pos      (3UL)          /*!< INCVICLRE (Bit 3)                                     */
#define R_PCIF0_INCPCCER_INCVICLRE_Msk      (0x8UL)        /*!< INCVICLRE (Bitfield-Mask: 0x01)                       */
#define R_PCIF0_INCPCCER_INCPICLRE_Pos      (2UL)          /*!< INCPICLRE (Bit 2)                                     */
#define R_PCIF0_INCPCCER_INCPICLRE_Msk      (0x4UL)        /*!< INCPICLRE (Bitfield-Mask: 0x01)                       */
#define R_PCIF0_INCPCCER_INCZICLRE_Pos      (1UL)          /*!< INCZICLRE (Bit 1)                                     */
#define R_PCIF0_INCPCCER_INCZICLRE_Msk      (0x2UL)        /*!< INCZICLRE (Bitfield-Mask: 0x01)                       */
/* =======================================================  INCSWTRGR  ======================================================= */
#define R_PCIF0_INCSWTRGR_INCSWT_Pos        (0UL)          /*!< INCSWT (Bit 0)                                        */
#define R_PCIF0_INCSWTRGR_INCSWT_Msk        (0x1UL)        /*!< INCSWT (Bitfield-Mask: 0x01)                          */
/* ========================================================  INCPCMR  ======================================================== */
#define R_PCIF0_INCPCMR_INCROTM_Pos         (31UL)         /*!< INCROTM (Bit 31)                                      */
#define R_PCIF0_INCPCMR_INCROTM_Msk         (0x80000000UL) /*!< INCROTM (Bitfield-Mask: 0x01)                         */
#define R_PCIF0_INCPCMR_INCICNTM_Pos        (24UL)         /*!< INCICNTM (Bit 24)                                     */
#define R_PCIF0_INCPCMR_INCICNTM_Msk        (0x3f000000UL) /*!< INCICNTM (Bitfield-Mask: 0x3f)                        */
#define R_PCIF0_INCPCMR_INCOCNTM_Pos        (0UL)          /*!< INCOCNTM (Bit 0)                                      */
#define R_PCIF0_INCPCMR_INCOCNTM_Msk        (0xffffUL)     /*!< INCOCNTM (Bitfield-Mask: 0xffff)                      */
/* ========================================================  SWRSTR  ========================================================= */
#define R_PCIF0_SWRSTR_SWRST_Pos            (0UL)          /*!< SWRST (Bit 0)                                         */
#define R_PCIF0_SWRSTR_SWRST_Msk            (0x1UL)        /*!< SWRST (Bitfield-Mask: 0x01)                           */

#endif /* R_PCIF_POSMSK_H */
