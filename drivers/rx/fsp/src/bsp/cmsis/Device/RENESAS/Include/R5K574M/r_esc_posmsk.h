/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ESC_POSMSK_H
#define R_ESC_POSMSK_H

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */

/** @addtogroup PosMask_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                           R_ESC                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  TYPE  ========================================================== */
/* =======================================================  REVISION  ======================================================== */
/* =========================================================  BUILD  ========================================================= */
/* ========================================================  FMMUNUM  ======================================================== */
/* =========================================================  SMNUM  ========================================================= */
/* ========================================================  RAMSIZE  ======================================================== */
/* =======================================================  PORTDESC  ======================================================== */
#define R_ESC_PORTDESC_P0_Pos                  (0UL)         /*!< P0 (Bit 0)                                            */
#define R_ESC_PORTDESC_P0_Msk                  (0x3UL)       /*!< P0 (Bitfield-Mask: 0x03)                              */
#define R_ESC_PORTDESC_P1_Pos                  (2UL)         /*!< P1 (Bit 2)                                            */
#define R_ESC_PORTDESC_P1_Msk                  (0xcUL)       /*!< P1 (Bitfield-Mask: 0x03)                              */
#define R_ESC_PORTDESC_P2_Pos                  (4UL)         /*!< P2 (Bit 4)                                            */
#define R_ESC_PORTDESC_P2_Msk                  (0x30UL)      /*!< P2 (Bitfield-Mask: 0x03)                              */
#define R_ESC_PORTDESC_P3_Pos                  (6UL)         /*!< P3 (Bit 6)                                            */
#define R_ESC_PORTDESC_P3_Msk                  (0xc0UL)      /*!< P3 (Bitfield-Mask: 0x03)                              */
/* ========================================================  FEATURE  ======================================================== */
#define R_ESC_FEATURE_FMMU_Pos                 (0UL)         /*!< FMMU (Bit 0)                                          */
#define R_ESC_FEATURE_FMMU_Msk                 (0x1UL)       /*!< FMMU (Bitfield-Mask: 0x01)                            */
#define R_ESC_FEATURE_DC_Pos                   (2UL)         /*!< DC (Bit 2)                                            */
#define R_ESC_FEATURE_DC_Msk                   (0x4UL)       /*!< DC (Bitfield-Mask: 0x01)                              */
#define R_ESC_FEATURE_DCWID_Pos                (3UL)         /*!< DCWID (Bit 3)                                         */
#define R_ESC_FEATURE_DCWID_Msk                (0x8UL)       /*!< DCWID (Bitfield-Mask: 0x01)                           */
#define R_ESC_FEATURE_LINKDETMII_Pos           (6UL)         /*!< LINKDETMII (Bit 6)                                    */
#define R_ESC_FEATURE_LINKDETMII_Msk           (0x40UL)      /*!< LINKDETMII (Bitfield-Mask: 0x01)                      */
#define R_ESC_FEATURE_FCS_Pos                  (7UL)         /*!< FCS (Bit 7)                                           */
#define R_ESC_FEATURE_FCS_Msk                  (0x80UL)      /*!< FCS (Bitfield-Mask: 0x01)                             */
#define R_ESC_FEATURE_DCSYNC_Pos               (8UL)         /*!< DCSYNC (Bit 8)                                        */
#define R_ESC_FEATURE_DCSYNC_Msk               (0x100UL)     /*!< DCSYNC (Bitfield-Mask: 0x01)                          */
#define R_ESC_FEATURE_LRW_Pos                  (9UL)         /*!< LRW (Bit 9)                                           */
#define R_ESC_FEATURE_LRW_Msk                  (0x200UL)     /*!< LRW (Bitfield-Mask: 0x01)                             */
#define R_ESC_FEATURE_RWSUPP_Pos               (10UL)        /*!< RWSUPP (Bit 10)                                       */
#define R_ESC_FEATURE_RWSUPP_Msk               (0x400UL)     /*!< RWSUPP (Bitfield-Mask: 0x01)                          */
#define R_ESC_FEATURE_FSCONFIG_Pos             (11UL)        /*!< FSCONFIG (Bit 11)                                     */
#define R_ESC_FEATURE_FSCONFIG_Msk             (0x800UL)     /*!< FSCONFIG (Bitfield-Mask: 0x01)                        */
/* ======================================================  STATIONADR  ======================================================= */
/* =====================================================  STATIONALIAS  ====================================================== */
/* ======================================================  REGWRENABLE  ====================================================== */
#define R_ESC_REGWRENABLE_ENABLE_Pos           (0UL)         /*!< ENABLE (Bit 0)                                        */
#define R_ESC_REGWRENABLE_ENABLE_Msk           (0x1UL)       /*!< ENABLE (Bitfield-Mask: 0x01)                          */
/* =====================================================  REGWRPROTECT  ====================================================== */
#define R_ESC_REGWRPROTECT_PROTECT_Pos         (0UL)         /*!< PROTECT (Bit 0)                                       */
#define R_ESC_REGWRPROTECT_PROTECT_Msk         (0x1UL)       /*!< PROTECT (Bitfield-Mask: 0x01)                         */
/* ======================================================  ESCWRENABLE  ====================================================== */
#define R_ESC_ESCWRENABLE_ENABLE_Pos           (0UL)         /*!< ENABLE (Bit 0)                                        */
#define R_ESC_ESCWRENABLE_ENABLE_Msk           (0x1UL)       /*!< ENABLE (Bitfield-Mask: 0x01)                          */
/* =====================================================  ESCWRPROTECT  ====================================================== */
#define R_ESC_ESCWRPROTECT_PROTECT_Pos         (0UL)         /*!< PROTECT (Bit 0)                                       */
#define R_ESC_ESCWRPROTECT_PROTECT_Msk         (0x1UL)       /*!< PROTECT (Bitfield-Mask: 0x01)                         */
/* =====================================================  ESCRESETECAT  ====================================================== */
#define R_ESC_ESCRESETECAT_RESETECAT_Pos       (0UL)         /*!< RESETECAT (Bit 0)                                     */
#define R_ESC_ESCRESETECAT_RESETECAT_Msk       (0x3UL)       /*!< RESETECAT (Bitfield-Mask: 0x03)                       */
/* ======================================================  ESCRESETPDI  ====================================================== */
#define R_ESC_ESCRESETPDI_RESETPDI_Pos         (0UL)         /*!< RESETPDI (Bit 0)                                      */
#define R_ESC_ESCRESETPDI_RESETPDI_Msk         (0x3UL)       /*!< RESETPDI (Bitfield-Mask: 0x03)                        */
/* =====================================================  ESCDLCONTROL  ====================================================== */
#define R_ESC_ESCDLCONTROL_FWDRULE_Pos         (0UL)         /*!< FWDRULE (Bit 0)                                       */
#define R_ESC_ESCDLCONTROL_FWDRULE_Msk         (0x1UL)       /*!< FWDRULE (Bitfield-Mask: 0x01)                         */
#define R_ESC_ESCDLCONTROL_TEMPUSE_Pos         (1UL)         /*!< TEMPUSE (Bit 1)                                       */
#define R_ESC_ESCDLCONTROL_TEMPUSE_Msk         (0x2UL)       /*!< TEMPUSE (Bitfield-Mask: 0x01)                         */
#define R_ESC_ESCDLCONTROL_LP0_Pos             (8UL)         /*!< LP0 (Bit 8)                                           */
#define R_ESC_ESCDLCONTROL_LP0_Msk             (0x300UL)     /*!< LP0 (Bitfield-Mask: 0x03)                             */
#define R_ESC_ESCDLCONTROL_LP1_Pos             (10UL)        /*!< LP1 (Bit 10)                                          */
#define R_ESC_ESCDLCONTROL_LP1_Msk             (0xc00UL)     /*!< LP1 (Bitfield-Mask: 0x03)                             */
#define R_ESC_ESCDLCONTROL_LP2_Pos             (12UL)        /*!< LP2 (Bit 12)                                          */
#define R_ESC_ESCDLCONTROL_LP2_Msk             (0x3000UL)    /*!< LP2 (Bitfield-Mask: 0x03)                             */
#define R_ESC_ESCDLCONTROL_LP3_Pos             (14UL)        /*!< LP3 (Bit 14)                                          */
#define R_ESC_ESCDLCONTROL_LP3_Msk             (0xc000UL)    /*!< LP3 (Bitfield-Mask: 0x03)                             */
#define R_ESC_ESCDLCONTROL_RXFIFO_Pos          (16UL)        /*!< RXFIFO (Bit 16)                                       */
#define R_ESC_ESCDLCONTROL_RXFIFO_Msk          (0x70000UL)   /*!< RXFIFO (Bitfield-Mask: 0x07)                          */
#define R_ESC_ESCDLCONTROL_STAALIAS_Pos        (24UL)        /*!< STAALIAS (Bit 24)                                     */
#define R_ESC_ESCDLCONTROL_STAALIAS_Msk        (0x1000000UL) /*!< STAALIAS (Bitfield-Mask: 0x01)                        */
/* ====================================================  PHYSICALRWOFST  ===================================================== */
/* ======================================================  ESCDLSTATUS  ====================================================== */
#define R_ESC_ESCDLSTATUS_PDIOPE_Pos           (0UL)         /*!< PDIOPE (Bit 0)                                        */
#define R_ESC_ESCDLSTATUS_PDIOPE_Msk           (0x1UL)       /*!< PDIOPE (Bitfield-Mask: 0x01)                          */
#define R_ESC_ESCDLSTATUS_PDIWDST_Pos          (1UL)         /*!< PDIWDST (Bit 1)                                       */
#define R_ESC_ESCDLSTATUS_PDIWDST_Msk          (0x2UL)       /*!< PDIWDST (Bitfield-Mask: 0x01)                         */
#define R_ESC_ESCDLSTATUS_ENHLINKD_Pos         (2UL)         /*!< ENHLINKD (Bit 2)                                      */
#define R_ESC_ESCDLSTATUS_ENHLINKD_Msk         (0x4UL)       /*!< ENHLINKD (Bitfield-Mask: 0x01)                        */
#define R_ESC_ESCDLSTATUS_PHYP0_Pos            (4UL)         /*!< PHYP0 (Bit 4)                                         */
#define R_ESC_ESCDLSTATUS_PHYP0_Msk            (0x10UL)      /*!< PHYP0 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCDLSTATUS_PHYP1_Pos            (5UL)         /*!< PHYP1 (Bit 5)                                         */
#define R_ESC_ESCDLSTATUS_PHYP1_Msk            (0x20UL)      /*!< PHYP1 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCDLSTATUS_PHYP2_Pos            (6UL)         /*!< PHYP2 (Bit 6)                                         */
#define R_ESC_ESCDLSTATUS_PHYP2_Msk            (0x40UL)      /*!< PHYP2 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCDLSTATUS_PHYP3_Pos            (7UL)         /*!< PHYP3 (Bit 7)                                         */
#define R_ESC_ESCDLSTATUS_PHYP3_Msk            (0x80UL)      /*!< PHYP3 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCDLSTATUS_LP0_Pos              (8UL)         /*!< LP0 (Bit 8)                                           */
#define R_ESC_ESCDLSTATUS_LP0_Msk              (0x100UL)     /*!< LP0 (Bitfield-Mask: 0x01)                             */
#define R_ESC_ESCDLSTATUS_COMP0_Pos            (9UL)         /*!< COMP0 (Bit 9)                                         */
#define R_ESC_ESCDLSTATUS_COMP0_Msk            (0x200UL)     /*!< COMP0 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCDLSTATUS_LP1_Pos              (10UL)        /*!< LP1 (Bit 10)                                          */
#define R_ESC_ESCDLSTATUS_LP1_Msk              (0x400UL)     /*!< LP1 (Bitfield-Mask: 0x01)                             */
#define R_ESC_ESCDLSTATUS_COMP1_Pos            (11UL)        /*!< COMP1 (Bit 11)                                        */
#define R_ESC_ESCDLSTATUS_COMP1_Msk            (0x800UL)     /*!< COMP1 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCDLSTATUS_LP2_Pos              (12UL)        /*!< LP2 (Bit 12)                                          */
#define R_ESC_ESCDLSTATUS_LP2_Msk              (0x1000UL)    /*!< LP2 (Bitfield-Mask: 0x01)                             */
#define R_ESC_ESCDLSTATUS_COMP2_Pos            (13UL)        /*!< COMP2 (Bit 13)                                        */
#define R_ESC_ESCDLSTATUS_COMP2_Msk            (0x2000UL)    /*!< COMP2 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCDLSTATUS_LP3_Pos              (14UL)        /*!< LP3 (Bit 14)                                          */
#define R_ESC_ESCDLSTATUS_LP3_Msk              (0x4000UL)    /*!< LP3 (Bitfield-Mask: 0x01)                             */
#define R_ESC_ESCDLSTATUS_COMP3_Pos            (15UL)        /*!< COMP3 (Bit 15)                                        */
#define R_ESC_ESCDLSTATUS_COMP3_Msk            (0x8000UL)    /*!< COMP3 (Bitfield-Mask: 0x01)                           */
/* =======================================================  ALCONTROL  ======================================================= */
#define R_ESC_ALCONTROL_INISTATE_Pos           (0UL)         /*!< INISTATE (Bit 0)                                      */
#define R_ESC_ALCONTROL_INISTATE_Msk           (0xfUL)       /*!< INISTATE (Bitfield-Mask: 0x0f)                        */
#define R_ESC_ALCONTROL_ERRINDACK_Pos          (4UL)         /*!< ERRINDACK (Bit 4)                                     */
#define R_ESC_ALCONTROL_ERRINDACK_Msk          (0x10UL)      /*!< ERRINDACK (Bitfield-Mask: 0x01)                       */
#define R_ESC_ALCONTROL_DEVICEID_Pos           (5UL)         /*!< DEVICEID (Bit 5)                                      */
#define R_ESC_ALCONTROL_DEVICEID_Msk           (0x20UL)      /*!< DEVICEID (Bitfield-Mask: 0x01)                        */
/* =======================================================  ALSTATUS  ======================================================== */
#define R_ESC_ALSTATUS_ACTSTATE_Pos            (0UL)         /*!< ACTSTATE (Bit 0)                                      */
#define R_ESC_ALSTATUS_ACTSTATE_Msk            (0xfUL)       /*!< ACTSTATE (Bitfield-Mask: 0x0f)                        */
#define R_ESC_ALSTATUS_ERR_Pos                 (4UL)         /*!< ERR (Bit 4)                                           */
#define R_ESC_ALSTATUS_ERR_Msk                 (0x10UL)      /*!< ERR (Bitfield-Mask: 0x01)                             */
#define R_ESC_ALSTATUS_DEVICEID_Pos            (5UL)         /*!< DEVICEID (Bit 5)                                      */
#define R_ESC_ALSTATUS_DEVICEID_Msk            (0x20UL)      /*!< DEVICEID (Bitfield-Mask: 0x01)                        */
/* =====================================================  ALSTATUSCODE  ====================================================== */
/* ====================================================  RUNLEDOVERRIDE  ===================================================== */
#define R_ESC_RUNLEDOVERRIDE_LEDCODE_Pos       (0UL)         /*!< LEDCODE (Bit 0)                                       */
#define R_ESC_RUNLEDOVERRIDE_LEDCODE_Msk       (0xfUL)       /*!< LEDCODE (Bitfield-Mask: 0x0f)                         */
#define R_ESC_RUNLEDOVERRIDE_OVERRIDEEN_Pos    (4UL)         /*!< OVERRIDEEN (Bit 4)                                    */
#define R_ESC_RUNLEDOVERRIDE_OVERRIDEEN_Msk    (0x10UL)      /*!< OVERRIDEEN (Bitfield-Mask: 0x01)                      */
/* ====================================================  ERRLEDOVERRIDE  ===================================================== */
#define R_ESC_ERRLEDOVERRIDE_LEDCODE_Pos       (0UL)         /*!< LEDCODE (Bit 0)                                       */
#define R_ESC_ERRLEDOVERRIDE_LEDCODE_Msk       (0xfUL)       /*!< LEDCODE (Bitfield-Mask: 0x0f)                         */
#define R_ESC_ERRLEDOVERRIDE_OVERRIDEEN_Pos    (4UL)         /*!< OVERRIDEEN (Bit 4)                                    */
#define R_ESC_ERRLEDOVERRIDE_OVERRIDEEN_Msk    (0x10UL)      /*!< OVERRIDEEN (Bitfield-Mask: 0x01)                      */
/* ======================================================  PDICONTROL  ======================================================= */
/* =======================================================  ESCCONFIG  ======================================================= */
#define R_ESC_ESCCONFIG_DEVEMU_Pos             (0UL)         /*!< DEVEMU (Bit 0)                                        */
#define R_ESC_ESCCONFIG_DEVEMU_Msk             (0x1UL)       /*!< DEVEMU (Bitfield-Mask: 0x01)                          */
#define R_ESC_ESCCONFIG_ENLALLP_Pos            (1UL)         /*!< ENLALLP (Bit 1)                                       */
#define R_ESC_ESCCONFIG_ENLALLP_Msk            (0x2UL)       /*!< ENLALLP (Bitfield-Mask: 0x01)                         */
#define R_ESC_ESCCONFIG_DCSYNC_Pos             (2UL)         /*!< DCSYNC (Bit 2)                                        */
#define R_ESC_ESCCONFIG_DCSYNC_Msk             (0x4UL)       /*!< DCSYNC (Bitfield-Mask: 0x01)                          */
#define R_ESC_ESCCONFIG_DCLATCH_Pos            (3UL)         /*!< DCLATCH (Bit 3)                                       */
#define R_ESC_ESCCONFIG_DCLATCH_Msk            (0x8UL)       /*!< DCLATCH (Bitfield-Mask: 0x01)                         */
#define R_ESC_ESCCONFIG_ENLP0_Pos              (4UL)         /*!< ENLP0 (Bit 4)                                         */
#define R_ESC_ESCCONFIG_ENLP0_Msk              (0x10UL)      /*!< ENLP0 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCCONFIG_ENLP1_Pos              (5UL)         /*!< ENLP1 (Bit 5)                                         */
#define R_ESC_ESCCONFIG_ENLP1_Msk              (0x20UL)      /*!< ENLP1 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCCONFIG_ENLP2_Pos              (6UL)         /*!< ENLP2 (Bit 6)                                         */
#define R_ESC_ESCCONFIG_ENLP2_Msk              (0x40UL)      /*!< ENLP2 (Bitfield-Mask: 0x01)                           */
#define R_ESC_ESCCONFIG_ENLP3_Pos              (7UL)         /*!< ENLP3 (Bit 7)                                         */
#define R_ESC_ESCCONFIG_ENLP3_Msk              (0x80UL)      /*!< ENLP3 (Bitfield-Mask: 0x01)                           */
/* =======================================================  PDICONFIG  ======================================================= */
#define R_ESC_PDICONFIG_ONCHIPBUSCLK_Pos       (0UL)         /*!< ONCHIPBUSCLK (Bit 0)                                  */
#define R_ESC_PDICONFIG_ONCHIPBUSCLK_Msk       (0x1fUL)      /*!< ONCHIPBUSCLK (Bitfield-Mask: 0x1f)                    */
#define R_ESC_PDICONFIG_ONCHIPBUS_Pos          (5UL)         /*!< ONCHIPBUS (Bit 5)                                     */
#define R_ESC_PDICONFIG_ONCHIPBUS_Msk          (0xe0UL)      /*!< ONCHIPBUS (Bitfield-Mask: 0x07)                       */
/* ====================================================  SYNCLATCHCONFIG  ==================================================== */
#define R_ESC_SYNCLATCHCONFIG_SYNC0OUT_Pos     (0UL)         /*!< SYNC0OUT (Bit 0)                                      */
#define R_ESC_SYNCLATCHCONFIG_SYNC0OUT_Msk     (0x3UL)       /*!< SYNC0OUT (Bitfield-Mask: 0x03)                        */
#define R_ESC_SYNCLATCHCONFIG_SYNCLAT0_Pos     (2UL)         /*!< SYNCLAT0 (Bit 2)                                      */
#define R_ESC_SYNCLATCHCONFIG_SYNCLAT0_Msk     (0x4UL)       /*!< SYNCLAT0 (Bitfield-Mask: 0x01)                        */
#define R_ESC_SYNCLATCHCONFIG_SYNC0MAP_Pos     (3UL)         /*!< SYNC0MAP (Bit 3)                                      */
#define R_ESC_SYNCLATCHCONFIG_SYNC0MAP_Msk     (0x8UL)       /*!< SYNC0MAP (Bitfield-Mask: 0x01)                        */
#define R_ESC_SYNCLATCHCONFIG_SYNC1OUT_Pos     (4UL)         /*!< SYNC1OUT (Bit 4)                                      */
#define R_ESC_SYNCLATCHCONFIG_SYNC1OUT_Msk     (0x30UL)      /*!< SYNC1OUT (Bitfield-Mask: 0x03)                        */
#define R_ESC_SYNCLATCHCONFIG_SYNCLAT1_Pos     (6UL)         /*!< SYNCLAT1 (Bit 6)                                      */
#define R_ESC_SYNCLATCHCONFIG_SYNCLAT1_Msk     (0x40UL)      /*!< SYNCLAT1 (Bitfield-Mask: 0x01)                        */
#define R_ESC_SYNCLATCHCONFIG_SYNC1MAP_Pos     (7UL)         /*!< SYNC1MAP (Bit 7)                                      */
#define R_ESC_SYNCLATCHCONFIG_SYNC1MAP_Msk     (0x80UL)      /*!< SYNC1MAP (Bitfield-Mask: 0x01)                        */
/* =====================================================  EXTPDICONFIG  ====================================================== */
#define R_ESC_EXTPDICONFIG_DATABUSWID_Pos      (0UL)         /*!< DATABUSWID (Bit 0)                                    */
#define R_ESC_EXTPDICONFIG_DATABUSWID_Msk      (0x3UL)       /*!< DATABUSWID (Bitfield-Mask: 0x03)                      */
/* =====================================================  ECATEVENTMASK  ===================================================== */
/* ======================================================  ALEVENTMASK  ====================================================== */
/* =====================================================  ECATEVENTREQ  ====================================================== */
#define R_ESC_ECATEVENTREQ_DCLATCH_Pos         (0UL)         /*!< DCLATCH (Bit 0)                                       */
#define R_ESC_ECATEVENTREQ_DCLATCH_Msk         (0x1UL)       /*!< DCLATCH (Bitfield-Mask: 0x01)                         */
#define R_ESC_ECATEVENTREQ_DLSTA_Pos           (2UL)         /*!< DLSTA (Bit 2)                                         */
#define R_ESC_ECATEVENTREQ_DLSTA_Msk           (0x4UL)       /*!< DLSTA (Bitfield-Mask: 0x01)                           */
#define R_ESC_ECATEVENTREQ_ALSTA_Pos           (3UL)         /*!< ALSTA (Bit 3)                                         */
#define R_ESC_ECATEVENTREQ_ALSTA_Msk           (0x8UL)       /*!< ALSTA (Bitfield-Mask: 0x01)                           */
#define R_ESC_ECATEVENTREQ_SMSTA0_Pos          (4UL)         /*!< SMSTA0 (Bit 4)                                        */
#define R_ESC_ECATEVENTREQ_SMSTA0_Msk          (0x10UL)      /*!< SMSTA0 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ECATEVENTREQ_SMSTA1_Pos          (5UL)         /*!< SMSTA1 (Bit 5)                                        */
#define R_ESC_ECATEVENTREQ_SMSTA1_Msk          (0x20UL)      /*!< SMSTA1 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ECATEVENTREQ_SMSTA2_Pos          (6UL)         /*!< SMSTA2 (Bit 6)                                        */
#define R_ESC_ECATEVENTREQ_SMSTA2_Msk          (0x40UL)      /*!< SMSTA2 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ECATEVENTREQ_SMSTA3_Pos          (7UL)         /*!< SMSTA3 (Bit 7)                                        */
#define R_ESC_ECATEVENTREQ_SMSTA3_Msk          (0x80UL)      /*!< SMSTA3 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ECATEVENTREQ_SMSTA4_Pos          (8UL)         /*!< SMSTA4 (Bit 8)                                        */
#define R_ESC_ECATEVENTREQ_SMSTA4_Msk          (0x100UL)     /*!< SMSTA4 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ECATEVENTREQ_SMSTA5_Pos          (9UL)         /*!< SMSTA5 (Bit 9)                                        */
#define R_ESC_ECATEVENTREQ_SMSTA5_Msk          (0x200UL)     /*!< SMSTA5 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ECATEVENTREQ_SMSTA6_Pos          (10UL)        /*!< SMSTA6 (Bit 10)                                       */
#define R_ESC_ECATEVENTREQ_SMSTA6_Msk          (0x400UL)     /*!< SMSTA6 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ECATEVENTREQ_SMSTA7_Pos          (11UL)        /*!< SMSTA7 (Bit 11)                                       */
#define R_ESC_ECATEVENTREQ_SMSTA7_Msk          (0x800UL)     /*!< SMSTA7 (Bitfield-Mask: 0x01)                          */
/* ======================================================  ALEVENTREQ  ======================================================= */
#define R_ESC_ALEVENTREQ_ALCTRL_Pos            (0UL)         /*!< ALCTRL (Bit 0)                                        */
#define R_ESC_ALEVENTREQ_ALCTRL_Msk            (0x1UL)       /*!< ALCTRL (Bitfield-Mask: 0x01)                          */
#define R_ESC_ALEVENTREQ_DCLATCH_Pos           (1UL)         /*!< DCLATCH (Bit 1)                                       */
#define R_ESC_ALEVENTREQ_DCLATCH_Msk           (0x2UL)       /*!< DCLATCH (Bitfield-Mask: 0x01)                         */
#define R_ESC_ALEVENTREQ_DCSYNC0STA_Pos        (2UL)         /*!< DCSYNC0STA (Bit 2)                                    */
#define R_ESC_ALEVENTREQ_DCSYNC0STA_Msk        (0x4UL)       /*!< DCSYNC0STA (Bitfield-Mask: 0x01)                      */
#define R_ESC_ALEVENTREQ_DCSYNC1STA_Pos        (3UL)         /*!< DCSYNC1STA (Bit 3)                                    */
#define R_ESC_ALEVENTREQ_DCSYNC1STA_Msk        (0x8UL)       /*!< DCSYNC1STA (Bitfield-Mask: 0x01)                      */
#define R_ESC_ALEVENTREQ_SYNCACT_Pos           (4UL)         /*!< SYNCACT (Bit 4)                                       */
#define R_ESC_ALEVENTREQ_SYNCACT_Msk           (0x10UL)      /*!< SYNCACT (Bitfield-Mask: 0x01)                         */
#define R_ESC_ALEVENTREQ_WDPD_Pos              (6UL)         /*!< WDPD (Bit 6)                                          */
#define R_ESC_ALEVENTREQ_WDPD_Msk              (0x40UL)      /*!< WDPD (Bitfield-Mask: 0x01)                            */
#define R_ESC_ALEVENTREQ_SMINT0_Pos            (8UL)         /*!< SMINT0 (Bit 8)                                        */
#define R_ESC_ALEVENTREQ_SMINT0_Msk            (0x100UL)     /*!< SMINT0 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ALEVENTREQ_SMINT1_Pos            (9UL)         /*!< SMINT1 (Bit 9)                                        */
#define R_ESC_ALEVENTREQ_SMINT1_Msk            (0x200UL)     /*!< SMINT1 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ALEVENTREQ_SMINT2_Pos            (10UL)        /*!< SMINT2 (Bit 10)                                       */
#define R_ESC_ALEVENTREQ_SMINT2_Msk            (0x400UL)     /*!< SMINT2 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ALEVENTREQ_SMINT3_Pos            (11UL)        /*!< SMINT3 (Bit 11)                                       */
#define R_ESC_ALEVENTREQ_SMINT3_Msk            (0x800UL)     /*!< SMINT3 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ALEVENTREQ_SMINT4_Pos            (12UL)        /*!< SMINT4 (Bit 12)                                       */
#define R_ESC_ALEVENTREQ_SMINT4_Msk            (0x1000UL)    /*!< SMINT4 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ALEVENTREQ_SMINT5_Pos            (13UL)        /*!< SMINT5 (Bit 13)                                       */
#define R_ESC_ALEVENTREQ_SMINT5_Msk            (0x2000UL)    /*!< SMINT5 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ALEVENTREQ_SMINT6_Pos            (14UL)        /*!< SMINT6 (Bit 14)                                       */
#define R_ESC_ALEVENTREQ_SMINT6_Msk            (0x4000UL)    /*!< SMINT6 (Bitfield-Mask: 0x01)                          */
#define R_ESC_ALEVENTREQ_SMINT7_Pos            (15UL)        /*!< SMINT7 (Bit 15)                                       */
#define R_ESC_ALEVENTREQ_SMINT7_Msk            (0x8000UL)    /*!< SMINT7 (Bitfield-Mask: 0x01)                          */
/* ======================================================  RXERRCOUNT0  ====================================================== */
#define R_ESC_RXERRCOUNT0_INVFRMCNT_Pos        (0UL)         /*!< INVFRMCNT (Bit 0)                                     */
#define R_ESC_RXERRCOUNT0_INVFRMCNT_Msk        (0xffUL)      /*!< INVFRMCNT (Bitfield-Mask: 0xff)                       */
#define R_ESC_RXERRCOUNT0_RXERRCNT_Pos         (8UL)         /*!< RXERRCNT (Bit 8)                                      */
#define R_ESC_RXERRCOUNT0_RXERRCNT_Msk         (0xff00UL)    /*!< RXERRCNT (Bitfield-Mask: 0xff)                        */
/* ======================================================  RXERRCOUNT1  ====================================================== */
#define R_ESC_RXERRCOUNT1_INVFRMCNT_Pos        (0UL)         /*!< INVFRMCNT (Bit 0)                                     */
#define R_ESC_RXERRCOUNT1_INVFRMCNT_Msk        (0xffUL)      /*!< INVFRMCNT (Bitfield-Mask: 0xff)                       */
#define R_ESC_RXERRCOUNT1_RXERRCNT_Pos         (8UL)         /*!< RXERRCNT (Bit 8)                                      */
#define R_ESC_RXERRCOUNT1_RXERRCNT_Msk         (0xff00UL)    /*!< RXERRCNT (Bitfield-Mask: 0xff)                        */
/* ====================================================  FWDRXERRCOUNT0  ===================================================== */
/* ====================================================  FWDRXERRCOUNT1  ===================================================== */
/* ======================================================  EPUERRCOUNT  ====================================================== */
/* ======================================================  PDIERRCOUNT  ====================================================== */
/* ====================================================  LOSTLINKCOUNT0  ===================================================== */
/* ====================================================  LOSTLINKCOUNT1  ===================================================== */
/* =======================================================  WDDIVIDE  ======================================================== */
/* ========================================================  WDTPDI  ========================================================= */
/* ========================================================  WDTDATA  ======================================================== */
/* ========================================================  WDSDATA  ======================================================== */
#define R_ESC_WDSDATA_WDSTAPD_Pos             (0UL)          /*!< WDSTAPD (Bit 0)                                       */
#define R_ESC_WDSDATA_WDSTAPD_Msk             (0x1UL)        /*!< WDSTAPD (Bitfield-Mask: 0x01)                         */
/* ========================================================  WDCDATA  ======================================================== */
/* ========================================================  WDCPDI  ========================================================= */
/* ========================================================  EEPCONF  ======================================================== */
#define R_ESC_EEPCONF_CTRLPDI_Pos             (0UL)          /*!< CTRLPDI (Bit 0)                                       */
#define R_ESC_EEPCONF_CTRLPDI_Msk             (0x1UL)        /*!< CTRLPDI (Bitfield-Mask: 0x01)                         */
#define R_ESC_EEPCONF_FORCEECAT_Pos           (1UL)          /*!< FORCEECAT (Bit 1)                                     */
#define R_ESC_EEPCONF_FORCEECAT_Msk           (0x2UL)        /*!< FORCEECAT (Bitfield-Mask: 0x01)                       */
/* =======================================================  EEPSTATE  ======================================================== */
#define R_ESC_EEPSTATE_PDIACCESS_Pos          (0UL)          /*!< PDIACCESS (Bit 0)                                     */
#define R_ESC_EEPSTATE_PDIACCESS_Msk          (0x1UL)        /*!< PDIACCESS (Bitfield-Mask: 0x01)                       */
/* ======================================================  EEPCONTSTAT  ====================================================== */
#define R_ESC_EEPCONTSTAT_ECATWREN_Pos        (0UL)          /*!< ECATWREN (Bit 0)                                      */
#define R_ESC_EEPCONTSTAT_ECATWREN_Msk        (0x1UL)        /*!< ECATWREN (Bitfield-Mask: 0x01)                        */
#define R_ESC_EEPCONTSTAT_READBYTE_Pos        (6UL)          /*!< READBYTE (Bit 6)                                      */
#define R_ESC_EEPCONTSTAT_READBYTE_Msk        (0x40UL)       /*!< READBYTE (Bitfield-Mask: 0x01)                        */
#define R_ESC_EEPCONTSTAT_PROMSIZE_Pos        (7UL)          /*!< PROMSIZE (Bit 7)                                      */
#define R_ESC_EEPCONTSTAT_PROMSIZE_Msk        (0x80UL)       /*!< PROMSIZE (Bitfield-Mask: 0x01)                        */
#define R_ESC_EEPCONTSTAT_COMMAND_Pos         (8UL)          /*!< COMMAND (Bit 8)                                       */
#define R_ESC_EEPCONTSTAT_COMMAND_Msk         (0x700UL)      /*!< COMMAND (Bitfield-Mask: 0x07)                         */
#define R_ESC_EEPCONTSTAT_CKSUMERR_Pos        (11UL)         /*!< CKSUMERR (Bit 11)                                     */
#define R_ESC_EEPCONTSTAT_CKSUMERR_Msk        (0x800UL)      /*!< CKSUMERR (Bitfield-Mask: 0x01)                        */
#define R_ESC_EEPCONTSTAT_LOADSTA_Pos         (12UL)         /*!< LOADSTA (Bit 12)                                      */
#define R_ESC_EEPCONTSTAT_LOADSTA_Msk         (0x1000UL)     /*!< LOADSTA (Bitfield-Mask: 0x01)                         */
#define R_ESC_EEPCONTSTAT_ACKCMDERR_Pos       (13UL)         /*!< ACKCMDERR (Bit 13)                                    */
#define R_ESC_EEPCONTSTAT_ACKCMDERR_Msk       (0x2000UL)     /*!< ACKCMDERR (Bitfield-Mask: 0x01)                       */
#define R_ESC_EEPCONTSTAT_WRENERR_Pos         (14UL)         /*!< WRENERR (Bit 14)                                      */
#define R_ESC_EEPCONTSTAT_WRENERR_Msk         (0x4000UL)     /*!< WRENERR (Bitfield-Mask: 0x01)                         */
#define R_ESC_EEPCONTSTAT_BUSY_Pos            (15UL)         /*!< BUSY (Bit 15)                                         */
#define R_ESC_EEPCONTSTAT_BUSY_Msk            (0x8000UL)     /*!< BUSY (Bitfield-Mask: 0x01)                            */
/* ========================================================  EEPADR  ========================================================= */
/* ========================================================  EEPDATA  ======================================================== */
#define R_ESC_EEPDATA_LODATA_Pos              (0UL)          /*!< LODATA (Bit 0)                                        */
#define R_ESC_EEPDATA_LODATA_Msk              (0xffffUL)     /*!< LODATA (Bitfield-Mask: 0xffff)                        */
#define R_ESC_EEPDATA_HIDATA_Pos              (16UL)         /*!< HIDATA (Bit 16)                                       */
#define R_ESC_EEPDATA_HIDATA_Msk              (0xffff0000UL) /*!< HIDATA (Bitfield-Mask: 0xffff)                        */
/* ======================================================  MIICONTSTAT  ====================================================== */
#define R_ESC_MIICONTSTAT_WREN_Pos            (0UL)          /*!< WREN (Bit 0)                                          */
#define R_ESC_MIICONTSTAT_WREN_Msk            (0x1UL)        /*!< WREN (Bitfield-Mask: 0x01)                            */
#define R_ESC_MIICONTSTAT_PDICTRL_Pos         (1UL)          /*!< PDICTRL (Bit 1)                                       */
#define R_ESC_MIICONTSTAT_PDICTRL_Msk         (0x2UL)        /*!< PDICTRL (Bitfield-Mask: 0x01)                         */
#define R_ESC_MIICONTSTAT_MILINK_Pos          (2UL)          /*!< MILINK (Bit 2)                                        */
#define R_ESC_MIICONTSTAT_MILINK_Msk          (0x4UL)        /*!< MILINK (Bitfield-Mask: 0x01)                          */
#define R_ESC_MIICONTSTAT_PHYOFFSET_Pos       (3UL)          /*!< PHYOFFSET (Bit 3)                                     */
#define R_ESC_MIICONTSTAT_PHYOFFSET_Msk       (0xf8UL)       /*!< PHYOFFSET (Bitfield-Mask: 0x1f)                       */
#define R_ESC_MIICONTSTAT_COMMAND_Pos         (8UL)          /*!< COMMAND (Bit 8)                                       */
#define R_ESC_MIICONTSTAT_COMMAND_Msk         (0x300UL)      /*!< COMMAND (Bitfield-Mask: 0x03)                         */
#define R_ESC_MIICONTSTAT_READERR_Pos         (13UL)         /*!< READERR (Bit 13)                                      */
#define R_ESC_MIICONTSTAT_READERR_Msk         (0x2000UL)     /*!< READERR (Bitfield-Mask: 0x01)                         */
#define R_ESC_MIICONTSTAT_CMDERR_Pos          (14UL)         /*!< CMDERR (Bit 14)                                       */
#define R_ESC_MIICONTSTAT_CMDERR_Msk          (0x4000UL)     /*!< CMDERR (Bitfield-Mask: 0x01)                          */
#define R_ESC_MIICONTSTAT_BUSY_Pos            (15UL)         /*!< BUSY (Bit 15)                                         */
#define R_ESC_MIICONTSTAT_BUSY_Msk            (0x8000UL)     /*!< BUSY (Bitfield-Mask: 0x01)                            */
/* ========================================================  PHYADR  ========================================================= */
#define R_ESC_PHYADR_PHYADDR_Pos              (0UL)          /*!< PHYADDR (Bit 0)                                       */
#define R_ESC_PHYADR_PHYADDR_Msk              (0x1fUL)       /*!< PHYADDR (Bitfield-Mask: 0x1f)                         */
/* =======================================================  PHYREGADR  ======================================================= */
#define R_ESC_PHYREGADR_PHYREGADDR_Pos        (0UL)          /*!< PHYREGADDR (Bit 0)                                    */
#define R_ESC_PHYREGADR_PHYREGADDR_Msk        (0x1fUL)       /*!< PHYREGADDR (Bitfield-Mask: 0x1f)                      */
/* ========================================================  PHYDATA  ======================================================== */
#define R_ESC_PHYDATA_PHYREGDATA_Pos          (0UL)          /*!< PHYREDATA (Bit 0)                                     */
#define R_ESC_PHYDATA_PHYREGDATA_Msk          (0xffffUL)     /*!< PHYREDATA (Bitfield-Mask: 0xffff)                     */
/* ====================================================  MIIECATACSSTAT  ===================================================== */
#define R_ESC_MIIECATACSSTAT_ACSMII_Pos       (0UL)          /*!< ACSMII (Bit 0)                                        */
#define R_ESC_MIIECATACSSTAT_ACSMII_Msk       (0x1UL)        /*!< ACSMII (Bitfield-Mask: 0x01)                          */
/* =====================================================  MIIPDIACSSTAT  ===================================================== */
#define R_ESC_MIIPDIACSSTAT_ACSMII_Pos        (0UL)          /*!< ACSMII (Bit 0)                                        */
#define R_ESC_MIIPDIACSSTAT_ACSMII_Msk        (0x1UL)        /*!< ACSMII (Bitfield-Mask: 0x01)                          */
#define R_ESC_MIIPDIACSSTAT_FORPDI_Pos        (1UL)          /*!< FORPDI (Bit 1)                                        */
#define R_ESC_MIIPDIACSSTAT_FORPDI_Msk        (0x2UL)        /*!< FORPDI (Bitfield-Mask: 0x01)                          */
/* ====================================================  FMMU0LSTARTADR  ===================================================== */
/* =======================================================  FMMU0LEN  ======================================================== */
/* ====================================================  FMMU0LSTARTBIT  ===================================================== */
#define R_ESC_FMMU0LSTARTBIT_LSTABIT_Pos      (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU0LSTARTBIT_LSTABIT_Msk      (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* =====================================================  FMMU0LSTOPBIT  ===================================================== */
#define R_ESC_FMMU0LSTOPBIT_LSTABIT_Pos       (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU0LSTOPBIT_LSTABIT_Msk       (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* ====================================================  FMMU0PSTARTADR  ===================================================== */
/* ====================================================  FMMU0PSTARTBIT  ===================================================== */
#define R_ESC_FMMU0PSTARTBIT_PHYSTABIT_Pos    (0UL)          /*!< PHYSTABIT (Bit 0)                                     */
#define R_ESC_FMMU0PSTARTBIT_PHYSTABIT_Msk    (0x7UL)        /*!< PHYSTABIT (Bitfield-Mask: 0x07)                       */
/* =======================================================  FMMU0TYPE  ======================================================= */
#define R_ESC_FMMU0TYPE_READ_Pos              (0UL)          /*!< READ (Bit 0)                                          */
#define R_ESC_FMMU0TYPE_READ_Msk              (0x1UL)        /*!< READ (Bitfield-Mask: 0x01)                            */
#define R_ESC_FMMU0TYPE_WRITE_Pos             (1UL)          /*!< WRITE (Bit 1)                                         */
#define R_ESC_FMMU0TYPE_WRITE_Msk             (0x2UL)        /*!< WRITE (Bitfield-Mask: 0x01)                           */
/* =======================================================  FMMU0ACT  ======================================================== */
#define R_ESC_FMMU0ACT_ACTIVATE_Pos           (0UL)          /*!< ACTIVATE (Bit 0)                                      */
#define R_ESC_FMMU0ACT_ACTIVATE_Msk           (0x1UL)        /*!< ACTIVATE (Bitfield-Mask: 0x01)                        */
/* ====================================================  FMMU1LSTARTADR  ===================================================== */
/* =======================================================  FMMU1LEN  ======================================================== */
/* ====================================================  FMMU1LSTARTBIT  ===================================================== */
#define R_ESC_FMMU1LSTARTBIT_LSTABIT_Pos      (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU1LSTARTBIT_LSTABIT_Msk      (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* =====================================================  FMMU1LSTOPBIT  ===================================================== */
#define R_ESC_FMMU1LSTOPBIT_LSTABIT_Pos       (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU1LSTOPBIT_LSTABIT_Msk       (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* ====================================================  FMMU1PSTARTADR  ===================================================== */
/* ====================================================  FMMU1PSTARTBIT  ===================================================== */
#define R_ESC_FMMU1PSTARTBIT_PHYSTABIT_Pos    (0UL)          /*!< PHYSTABIT (Bit 0)                                     */
#define R_ESC_FMMU1PSTARTBIT_PHYSTABIT_Msk    (0x7UL)        /*!< PHYSTABIT (Bitfield-Mask: 0x07)                       */
/* =======================================================  FMMU1TYPE  ======================================================= */
#define R_ESC_FMMU1TYPE_READ_Pos              (0UL)          /*!< READ (Bit 0)                                          */
#define R_ESC_FMMU1TYPE_READ_Msk              (0x1UL)        /*!< READ (Bitfield-Mask: 0x01)                            */
#define R_ESC_FMMU1TYPE_WRITE_Pos             (1UL)          /*!< WRITE (Bit 1)                                         */
#define R_ESC_FMMU1TYPE_WRITE_Msk             (0x2UL)        /*!< WRITE (Bitfield-Mask: 0x01)                           */
/* =======================================================  FMMU1ACT  ======================================================== */
#define R_ESC_FMMU1ACT_ACTIVATE_Pos           (0UL)          /*!< ACTIVATE (Bit 0)                                      */
#define R_ESC_FMMU1ACT_ACTIVATE_Msk           (0x1UL)        /*!< ACTIVATE (Bitfield-Mask: 0x01)                        */
/* ====================================================  FMMU2LSTARTADR  ===================================================== */
/* =======================================================  FMMU2LEN  ======================================================== */
/* ====================================================  FMMU2LSTARTBIT  ===================================================== */
#define R_ESC_FMMU2LSTARTBIT_LSTABIT_Pos      (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU2LSTARTBIT_LSTABIT_Msk      (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* =====================================================  FMMU2LSTOPBIT  ===================================================== */
#define R_ESC_FMMU2LSTOPBIT_LSTABIT_Pos       (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU2LSTOPBIT_LSTABIT_Msk       (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* ====================================================  FMMU2PSTARTADR  ===================================================== */
/* ====================================================  FMMU2PSTARTBIT  ===================================================== */
#define R_ESC_FMMU2PSTARTBIT_PHYSTABIT_Pos    (0UL)          /*!< PHYSTABIT (Bit 0)                                     */
#define R_ESC_FMMU2PSTARTBIT_PHYSTABIT_Msk    (0x7UL)        /*!< PHYSTABIT (Bitfield-Mask: 0x07)                       */
/* =======================================================  FMMU2TYPE  ======================================================= */
#define R_ESC_FMMU2TYPE_READ_Pos              (0UL)          /*!< READ (Bit 0)                                          */
#define R_ESC_FMMU2TYPE_READ_Msk              (0x1UL)        /*!< READ (Bitfield-Mask: 0x01)                            */
#define R_ESC_FMMU2TYPE_WRITE_Pos             (1UL)          /*!< WRITE (Bit 1)                                         */
#define R_ESC_FMMU2TYPE_WRITE_Msk             (0x2UL)        /*!< WRITE (Bitfield-Mask: 0x01)                           */
/* =======================================================  FMMU2ACT  ======================================================== */
#define R_ESC_FMMU2ACT_ACTIVATE_Pos           (0UL)          /*!< ACTIVATE (Bit 0)                                      */
#define R_ESC_FMMU2ACT_ACTIVATE_Msk           (0x1UL)        /*!< ACTIVATE (Bitfield-Mask: 0x01)                        */
/* ====================================================  FMMU3LSTARTADR  ===================================================== */
/* =======================================================  FMMU3LEN  ======================================================== */
/* ====================================================  FMMU3LSTARTBIT  ===================================================== */
#define R_ESC_FMMU3LSTARTBIT_LSTABIT_Pos      (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU3LSTARTBIT_LSTABIT_Msk      (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* =====================================================  FMMU3LSTOPBIT  ===================================================== */
#define R_ESC_FMMU3LSTOPBIT_LSTABIT_Pos       (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU3LSTOPBIT_LSTABIT_Msk       (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* ====================================================  FMMU3PSTARTADR  ===================================================== */
/* ====================================================  FMMU3PSTARTBIT  ===================================================== */
#define R_ESC_FMMU3PSTARTBIT_PHYSTABIT_Pos    (0UL)          /*!< PHYSTABIT (Bit 0)                                     */
#define R_ESC_FMMU3PSTARTBIT_PHYSTABIT_Msk    (0x7UL)        /*!< PHYSTABIT (Bitfield-Mask: 0x07)                       */
/* =======================================================  FMMU3TYPE  ======================================================= */
#define R_ESC_FMMU3TYPE_READ_Pos              (0UL)          /*!< READ (Bit 0)                                          */
#define R_ESC_FMMU3TYPE_READ_Msk              (0x1UL)        /*!< READ (Bitfield-Mask: 0x01)                            */
#define R_ESC_FMMU3TYPE_WRITE_Pos             (1UL)          /*!< WRITE (Bit 1)                                         */
#define R_ESC_FMMU3TYPE_WRITE_Msk             (0x2UL)        /*!< WRITE (Bitfield-Mask: 0x01)                           */
/* =======================================================  FMMU3ACT  ======================================================== */
#define R_ESC_FMMU3ACT_ACTIVATE_Pos           (0UL)          /*!< ACTIVATE (Bit 0)                                      */
#define R_ESC_FMMU3ACT_ACTIVATE_Msk           (0x1UL)        /*!< ACTIVATE (Bitfield-Mask: 0x01)                        */
/* ====================================================  FMMU4LSTARTADR  ===================================================== */
/* =======================================================  FMMU4LEN  ======================================================== */
/* ====================================================  FMMU4LSTARTBIT  ===================================================== */
#define R_ESC_FMMU4LSTARTBIT_LSTABIT_Pos      (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU4LSTARTBIT_LSTABIT_Msk      (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* =====================================================  FMMU4LSTOPBIT  ===================================================== */
#define R_ESC_FMMU4LSTOPBIT_LSTABIT_Pos       (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU4LSTOPBIT_LSTABIT_Msk       (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* ====================================================  FMMU4PSTARTADR  ===================================================== */
/* ====================================================  FMMU4PSTARTBIT  ===================================================== */
#define R_ESC_FMMU4PSTARTBIT_PHYSTABIT_Pos    (0UL)          /*!< PHYSTABIT (Bit 0)                                     */
#define R_ESC_FMMU4PSTARTBIT_PHYSTABIT_Msk    (0x7UL)        /*!< PHYSTABIT (Bitfield-Mask: 0x07)                       */
/* =======================================================  FMMU4TYPE  ======================================================= */
#define R_ESC_FMMU4TYPE_READ_Pos              (0UL)          /*!< READ (Bit 0)                                          */
#define R_ESC_FMMU4TYPE_READ_Msk              (0x1UL)        /*!< READ (Bitfield-Mask: 0x01)                            */
#define R_ESC_FMMU4TYPE_WRITE_Pos             (1UL)          /*!< WRITE (Bit 1)                                         */
#define R_ESC_FMMU4TYPE_WRITE_Msk             (0x2UL)        /*!< WRITE (Bitfield-Mask: 0x01)                           */
/* =======================================================  FMMU4ACT  ======================================================== */
#define R_ESC_FMMU4ACT_ACTIVATE_Pos           (0UL)          /*!< ACTIVATE (Bit 0)                                      */
#define R_ESC_FMMU4ACT_ACTIVATE_Msk           (0x1UL)        /*!< ACTIVATE (Bitfield-Mask: 0x01)                        */
/* ====================================================  FMMU5LSTARTADR  ===================================================== */
/* =======================================================  FMMU5LEN  ======================================================== */
/* ====================================================  FMMU5LSTARTBIT  ===================================================== */
#define R_ESC_FMMU5LSTARTBIT_LSTABIT_Pos      (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU5LSTARTBIT_LSTABIT_Msk      (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* =====================================================  FMMU5LSTOPBIT  ===================================================== */
#define R_ESC_FMMU5LSTOPBIT_LSTABIT_Pos       (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU5LSTOPBIT_LSTABIT_Msk       (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* ====================================================  FMMU5PSTARTADR  ===================================================== */
/* ====================================================  FMMU5PSTARTBIT  ===================================================== */
#define R_ESC_FMMU5PSTARTBIT_PHYSTABIT_Pos    (0UL)          /*!< PHYSTABIT (Bit 0)                                     */
#define R_ESC_FMMU5PSTARTBIT_PHYSTABIT_Msk    (0x7UL)        /*!< PHYSTABIT (Bitfield-Mask: 0x07)                       */
/* =======================================================  FMMU5TYPE  ======================================================= */
#define R_ESC_FMMU5TYPE_READ_Pos              (0UL)          /*!< READ (Bit 0)                                          */
#define R_ESC_FMMU5TYPE_READ_Msk              (0x1UL)        /*!< READ (Bitfield-Mask: 0x01)                            */
#define R_ESC_FMMU5TYPE_WRITE_Pos             (1UL)          /*!< WRITE (Bit 1)                                         */
#define R_ESC_FMMU5TYPE_WRITE_Msk             (0x2UL)        /*!< WRITE (Bitfield-Mask: 0x01)                           */
/* =======================================================  FMMU5ACT  ======================================================== */
#define R_ESC_FMMU5ACT_ACTIVATE_Pos           (0UL)          /*!< ACTIVATE (Bit 0)                                      */
#define R_ESC_FMMU5ACT_ACTIVATE_Msk           (0x1UL)        /*!< ACTIVATE (Bitfield-Mask: 0x01)                        */
/* ====================================================  FMMU6LSTARTADR  ===================================================== */
/* =======================================================  FMMU6LEN  ======================================================== */
/* ====================================================  FMMU6LSTARTBIT  ===================================================== */
#define R_ESC_FMMU6LSTARTBIT_LSTABIT_Pos      (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU6LSTARTBIT_LSTABIT_Msk      (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* =====================================================  FMMU6LSTOPBIT  ===================================================== */
#define R_ESC_FMMU6LSTOPBIT_LSTABIT_Pos       (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU6LSTOPBIT_LSTABIT_Msk       (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* ====================================================  FMMU6PSTARTADR  ===================================================== */
/* ====================================================  FMMU6PSTARTBIT  ===================================================== */
#define R_ESC_FMMU6PSTARTBIT_PHYSTABIT_Pos    (0UL)          /*!< PHYSTABIT (Bit 0)                                     */
#define R_ESC_FMMU6PSTARTBIT_PHYSTABIT_Msk    (0x7UL)        /*!< PHYSTABIT (Bitfield-Mask: 0x07)                       */
/* =======================================================  FMMU6TYPE  ======================================================= */
#define R_ESC_FMMU6TYPE_READ_Pos              (0UL)          /*!< READ (Bit 0)                                          */
#define R_ESC_FMMU6TYPE_READ_Msk              (0x1UL)        /*!< READ (Bitfield-Mask: 0x01)                            */
#define R_ESC_FMMU6TYPE_WRITE_Pos             (1UL)          /*!< WRITE (Bit 1)                                         */
#define R_ESC_FMMU6TYPE_WRITE_Msk             (0x2UL)        /*!< WRITE (Bitfield-Mask: 0x01)                           */
/* =======================================================  FMMU6ACT  ======================================================== */
#define R_ESC_FMMU6ACT_ACTIVATE_Pos           (0UL)          /*!< ACTIVATE (Bit 0)                                      */
#define R_ESC_FMMU6ACT_ACTIVATE_Msk           (0x1UL)        /*!< ACTIVATE (Bitfield-Mask: 0x01)                        */
/* ====================================================  FMMU7LSTARTADR  ===================================================== */
/* =======================================================  FMMU7LEN  ======================================================== */
/* ====================================================  FMMU7LSTARTBIT  ===================================================== */
#define R_ESC_FMMU7LSTARTBIT_LSTABIT_Pos      (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU7LSTARTBIT_LSTABIT_Msk      (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* =====================================================  FMMU7LSTOPBIT  ===================================================== */
#define R_ESC_FMMU7LSTOPBIT_LSTABIT_Pos       (0UL)          /*!< LSTABIT (Bit 0)                                       */
#define R_ESC_FMMU7LSTOPBIT_LSTABIT_Msk       (0x7UL)        /*!< LSTABIT (Bitfield-Mask: 0x07)                         */
/* ====================================================  FMMU7PSTARTADR  ===================================================== */
/* ====================================================  FMMU7PSTARTBIT  ===================================================== */
#define R_ESC_FMMU7PSTARTBIT_PHYSTABIT_Pos    (0UL)          /*!< PHYSTABIT (Bit 0)                                     */
#define R_ESC_FMMU7PSTARTBIT_PHYSTABIT_Msk    (0x7UL)        /*!< PHYSTABIT (Bitfield-Mask: 0x07)                       */
/* =======================================================  FMMU7TYPE  ======================================================= */
#define R_ESC_FMMU7TYPE_READ_Pos              (0UL)          /*!< READ (Bit 0)                                          */
#define R_ESC_FMMU7TYPE_READ_Msk              (0x1UL)        /*!< READ (Bitfield-Mask: 0x01)                            */
#define R_ESC_FMMU7TYPE_WRITE_Pos             (1UL)          /*!< WRITE (Bit 1)                                         */
#define R_ESC_FMMU7TYPE_WRITE_Msk             (0x2UL)        /*!< WRITE (Bitfield-Mask: 0x01)                           */
/* =======================================================  FMMU7ACT  ======================================================== */
#define R_ESC_FMMU7ACT_ACTIVATE_Pos           (0UL)          /*!< ACTIVATE (Bit 0)                                      */
#define R_ESC_FMMU7ACT_ACTIVATE_Msk           (0x1UL)        /*!< ACTIVATE (Bitfield-Mask: 0x01)                        */
/* =====================================================  SM0PSTARTADR  ====================================================== */
/* ========================================================  SM0LEN  ========================================================= */
/* ======================================================  SM0CONTROL  ======================================================= */
#define R_ESC_SM0CONTROL_OPEMODE_Pos          (0UL)          /*!< OPEMODE (Bit 0)                                       */
#define R_ESC_SM0CONTROL_OPEMODE_Msk          (0x3UL)        /*!< OPEMODE (Bitfield-Mask: 0x03)                         */
#define R_ESC_SM0CONTROL_DIR_Pos              (2UL)          /*!< DIR (Bit 2)                                           */
#define R_ESC_SM0CONTROL_DIR_Msk              (0xcUL)        /*!< DIR (Bitfield-Mask: 0x03)                             */
#define R_ESC_SM0CONTROL_IRQECAT_Pos          (4UL)          /*!< IRQECAT (Bit 4)                                       */
#define R_ESC_SM0CONTROL_IRQECAT_Msk          (0x10UL)       /*!< IRQECAT (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM0CONTROL_IRQPDI_Pos           (5UL)          /*!< IRQPDI (Bit 5)                                        */
#define R_ESC_SM0CONTROL_IRQPDI_Msk           (0x20UL)       /*!< IRQPDI (Bitfield-Mask: 0x01)                          */
#define R_ESC_SM0CONTROL_WDTRGEN_Pos          (6UL)          /*!< WDTRGEN (Bit 6)                                       */
#define R_ESC_SM0CONTROL_WDTRGEN_Msk          (0x40UL)       /*!< WDTRGEN (Bitfield-Mask: 0x01)                         */
/* =======================================================  SM0STATUS  ======================================================= */
#define R_ESC_SM0STATUS_INTWR_Pos             (0UL)          /*!< INTWR (Bit 0)                                         */
#define R_ESC_SM0STATUS_INTWR_Msk             (0x1UL)        /*!< INTWR (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM0STATUS_INTRD_Pos             (1UL)          /*!< INTRD (Bit 1)                                         */
#define R_ESC_SM0STATUS_INTRD_Msk             (0x2UL)        /*!< INTRD (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM0STATUS_MAILBOX_Pos           (3UL)          /*!< MAILBOX (Bit 3)                                       */
#define R_ESC_SM0STATUS_MAILBOX_Msk           (0x8UL)        /*!< MAILBOX (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM0STATUS_BUFFERED_Pos          (4UL)          /*!< BUFFERED (Bit 4)                                      */
#define R_ESC_SM0STATUS_BUFFERED_Msk          (0x30UL)       /*!< BUFFERED (Bitfield-Mask: 0x03)                        */
#define R_ESC_SM0STATUS_RDBUF_Pos             (6UL)          /*!< RDBUF (Bit 6)                                         */
#define R_ESC_SM0STATUS_RDBUF_Msk             (0x40UL)       /*!< RDBUF (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM0STATUS_WRBUF_Pos             (7UL)          /*!< WRBUF (Bit 7)                                         */
#define R_ESC_SM0STATUS_WRBUF_Msk             (0x80UL)       /*!< WRBUF (Bitfield-Mask: 0x01)                           */
/* ========================================================  SM0ACT  ========================================================= */
#define R_ESC_SM0ACT_SMEN_Pos                 (0UL)          /*!< SMEN (Bit 0)                                          */
#define R_ESC_SM0ACT_SMEN_Msk                 (0x1UL)        /*!< SMEN (Bitfield-Mask: 0x01)                            */
#define R_ESC_SM0ACT_REPEATREQ_Pos            (1UL)          /*!< REPEATREQ (Bit 1)                                     */
#define R_ESC_SM0ACT_REPEATREQ_Msk            (0x2UL)        /*!< REPEATREQ (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM0ACT_LATCHECAT_Pos            (6UL)          /*!< LATCHECAT (Bit 6)                                     */
#define R_ESC_SM0ACT_LATCHECAT_Msk            (0x40UL)       /*!< LATCHECAT (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM0ACT_LATCHPDI_Pos             (7UL)          /*!< LATCHPDI (Bit 7)                                      */
#define R_ESC_SM0ACT_LATCHPDI_Msk             (0x80UL)       /*!< LATCHPDI (Bitfield-Mask: 0x01)                        */
/* ======================================================  SM0PDICONT  ======================================================= */
#define R_ESC_SM0PDICONT_DEACTIVE_Pos         (0UL)          /*!< DEACTIVE (Bit 0)                                      */
#define R_ESC_SM0PDICONT_DEACTIVE_Msk         (0x1UL)        /*!< DEACTIVE (Bitfield-Mask: 0x01)                        */
#define R_ESC_SM0PDICONT_REPEATACK_Pos        (1UL)          /*!< REPEATACK (Bit 1)                                     */
#define R_ESC_SM0PDICONT_REPEATACK_Msk        (0x2UL)        /*!< REPEATACK (Bitfield-Mask: 0x01)                       */
/* =====================================================  SM1PSTARTADR  ====================================================== */
/* ========================================================  SM1LEN  ========================================================= */
/* ======================================================  SM1CONTROL  ======================================================= */
#define R_ESC_SM1CONTROL_OPEMODE_Pos          (0UL)          /*!< OPEMODE (Bit 0)                                       */
#define R_ESC_SM1CONTROL_OPEMODE_Msk          (0x3UL)        /*!< OPEMODE (Bitfield-Mask: 0x03)                         */
#define R_ESC_SM1CONTROL_DIR_Pos              (2UL)          /*!< DIR (Bit 2)                                           */
#define R_ESC_SM1CONTROL_DIR_Msk              (0xcUL)        /*!< DIR (Bitfield-Mask: 0x03)                             */
#define R_ESC_SM1CONTROL_IRQECAT_Pos          (4UL)          /*!< IRQECAT (Bit 4)                                       */
#define R_ESC_SM1CONTROL_IRQECAT_Msk          (0x10UL)       /*!< IRQECAT (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM1CONTROL_IRQPDI_Pos           (5UL)          /*!< IRQPDI (Bit 5)                                        */
#define R_ESC_SM1CONTROL_IRQPDI_Msk           (0x20UL)       /*!< IRQPDI (Bitfield-Mask: 0x01)                          */
#define R_ESC_SM1CONTROL_WDTRGEN_Pos          (6UL)          /*!< WDTRGEN (Bit 6)                                       */
#define R_ESC_SM1CONTROL_WDTRGEN_Msk          (0x40UL)       /*!< WDTRGEN (Bitfield-Mask: 0x01)                         */
/* =======================================================  SM1STATUS  ======================================================= */
#define R_ESC_SM1STATUS_INTWR_Pos             (0UL)          /*!< INTWR (Bit 0)                                         */
#define R_ESC_SM1STATUS_INTWR_Msk             (0x1UL)        /*!< INTWR (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM1STATUS_INTRD_Pos             (1UL)          /*!< INTRD (Bit 1)                                         */
#define R_ESC_SM1STATUS_INTRD_Msk             (0x2UL)        /*!< INTRD (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM1STATUS_MAILBOX_Pos           (3UL)          /*!< MAILBOX (Bit 3)                                       */
#define R_ESC_SM1STATUS_MAILBOX_Msk           (0x8UL)        /*!< MAILBOX (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM1STATUS_BUFFERED_Pos          (4UL)          /*!< BUFFERED (Bit 4)                                      */
#define R_ESC_SM1STATUS_BUFFERED_Msk          (0x30UL)       /*!< BUFFERED (Bitfield-Mask: 0x03)                        */
#define R_ESC_SM1STATUS_RDBUF_Pos             (6UL)          /*!< RDBUF (Bit 6)                                         */
#define R_ESC_SM1STATUS_RDBUF_Msk             (0x40UL)       /*!< RDBUF (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM1STATUS_WRBUF_Pos             (7UL)          /*!< WRBUF (Bit 7)                                         */
#define R_ESC_SM1STATUS_WRBUF_Msk             (0x80UL)       /*!< WRBUF (Bitfield-Mask: 0x01)                           */
/* ========================================================  SM1ACT  ========================================================= */
#define R_ESC_SM1ACT_SMEN_Pos                 (0UL)          /*!< SMEN (Bit 0)                                          */
#define R_ESC_SM1ACT_SMEN_Msk                 (0x1UL)        /*!< SMEN (Bitfield-Mask: 0x01)                            */
#define R_ESC_SM1ACT_REPEATREQ_Pos            (1UL)          /*!< REPEATREQ (Bit 1)                                     */
#define R_ESC_SM1ACT_REPEATREQ_Msk            (0x2UL)        /*!< REPEATREQ (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM1ACT_LATCHECAT_Pos            (6UL)          /*!< LATCHECAT (Bit 6)                                     */
#define R_ESC_SM1ACT_LATCHECAT_Msk            (0x40UL)       /*!< LATCHECAT (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM1ACT_LATCHPDI_Pos             (7UL)          /*!< LATCHPDI (Bit 7)                                      */
#define R_ESC_SM1ACT_LATCHPDI_Msk             (0x80UL)       /*!< LATCHPDI (Bitfield-Mask: 0x01)                        */
/* ======================================================  SM1PDICONT  ======================================================= */
#define R_ESC_SM1PDICONT_DEACTIVE_Pos         (0UL)          /*!< DEACTIVE (Bit 0)                                      */
#define R_ESC_SM1PDICONT_DEACTIVE_Msk         (0x1UL)        /*!< DEACTIVE (Bitfield-Mask: 0x01)                        */
#define R_ESC_SM1PDICONT_REPEATACK_Pos        (1UL)          /*!< REPEATACK (Bit 1)                                     */
#define R_ESC_SM1PDICONT_REPEATACK_Msk        (0x2UL)        /*!< REPEATACK (Bitfield-Mask: 0x01)                       */
/* =====================================================  SM2PSTARTADR  ====================================================== */
/* ========================================================  SM2LEN  ========================================================= */
/* ======================================================  SM2CONTROL  ======================================================= */
#define R_ESC_SM2CONTROL_OPEMODE_Pos          (0UL)          /*!< OPEMODE (Bit 0)                                       */
#define R_ESC_SM2CONTROL_OPEMODE_Msk          (0x3UL)        /*!< OPEMODE (Bitfield-Mask: 0x03)                         */
#define R_ESC_SM2CONTROL_DIR_Pos              (2UL)          /*!< DIR (Bit 2)                                           */
#define R_ESC_SM2CONTROL_DIR_Msk              (0xcUL)        /*!< DIR (Bitfield-Mask: 0x03)                             */
#define R_ESC_SM2CONTROL_IRQECAT_Pos          (4UL)          /*!< IRQECAT (Bit 4)                                       */
#define R_ESC_SM2CONTROL_IRQECAT_Msk          (0x10UL)       /*!< IRQECAT (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM2CONTROL_IRQPDI_Pos           (5UL)          /*!< IRQPDI (Bit 5)                                        */
#define R_ESC_SM2CONTROL_IRQPDI_Msk           (0x20UL)       /*!< IRQPDI (Bitfield-Mask: 0x01)                          */
#define R_ESC_SM2CONTROL_WDTRGEN_Pos          (6UL)          /*!< WDTRGEN (Bit 6)                                       */
#define R_ESC_SM2CONTROL_WDTRGEN_Msk          (0x40UL)       /*!< WDTRGEN (Bitfield-Mask: 0x01)                         */
/* =======================================================  SM2STATUS  ======================================================= */
#define R_ESC_SM2STATUS_INTWR_Pos             (0UL)          /*!< INTWR (Bit 0)                                         */
#define R_ESC_SM2STATUS_INTWR_Msk             (0x1UL)        /*!< INTWR (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM2STATUS_INTRD_Pos             (1UL)          /*!< INTRD (Bit 1)                                         */
#define R_ESC_SM2STATUS_INTRD_Msk             (0x2UL)        /*!< INTRD (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM2STATUS_MAILBOX_Pos           (3UL)          /*!< MAILBOX (Bit 3)                                       */
#define R_ESC_SM2STATUS_MAILBOX_Msk           (0x8UL)        /*!< MAILBOX (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM2STATUS_BUFFERED_Pos          (4UL)          /*!< BUFFERED (Bit 4)                                      */
#define R_ESC_SM2STATUS_BUFFERED_Msk          (0x30UL)       /*!< BUFFERED (Bitfield-Mask: 0x03)                        */
#define R_ESC_SM2STATUS_RDBUF_Pos             (6UL)          /*!< RDBUF (Bit 6)                                         */
#define R_ESC_SM2STATUS_RDBUF_Msk             (0x40UL)       /*!< RDBUF (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM2STATUS_WRBUF_Pos             (7UL)          /*!< WRBUF (Bit 7)                                         */
#define R_ESC_SM2STATUS_WRBUF_Msk             (0x80UL)       /*!< WRBUF (Bitfield-Mask: 0x01)                           */
/* ========================================================  SM2ACT  ========================================================= */
#define R_ESC_SM2ACT_SMEN_Pos                 (0UL)          /*!< SMEN (Bit 0)                                          */
#define R_ESC_SM2ACT_SMEN_Msk                 (0x1UL)        /*!< SMEN (Bitfield-Mask: 0x01)                            */
#define R_ESC_SM2ACT_REPEATREQ_Pos            (1UL)          /*!< REPEATREQ (Bit 1)                                     */
#define R_ESC_SM2ACT_REPEATREQ_Msk            (0x2UL)        /*!< REPEATREQ (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM2ACT_LATCHECAT_Pos            (6UL)          /*!< LATCHECAT (Bit 6)                                     */
#define R_ESC_SM2ACT_LATCHECAT_Msk            (0x40UL)       /*!< LATCHECAT (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM2ACT_LATCHPDI_Pos             (7UL)          /*!< LATCHPDI (Bit 7)                                      */
#define R_ESC_SM2ACT_LATCHPDI_Msk             (0x80UL)       /*!< LATCHPDI (Bitfield-Mask: 0x01)                        */
/* ======================================================  SM2PDICONT  ======================================================= */
#define R_ESC_SM2PDICONT_DEACTIVE_Pos         (0UL)          /*!< DEACTIVE (Bit 0)                                      */
#define R_ESC_SM2PDICONT_DEACTIVE_Msk         (0x1UL)        /*!< DEACTIVE (Bitfield-Mask: 0x01)                        */
#define R_ESC_SM2PDICONT_REPEATACK_Pos        (1UL)          /*!< REPEATACK (Bit 1)                                     */
#define R_ESC_SM2PDICONT_REPEATACK_Msk        (0x2UL)        /*!< REPEATACK (Bitfield-Mask: 0x01)                       */
/* =====================================================  SM3PSTARTADR  ====================================================== */
/* ========================================================  SM3LEN  ========================================================= */
/* ======================================================  SM3CONTROL  ======================================================= */
#define R_ESC_SM3CONTROL_OPEMODE_Pos          (0UL)          /*!< OPEMODE (Bit 0)                                       */
#define R_ESC_SM3CONTROL_OPEMODE_Msk          (0x3UL)        /*!< OPEMODE (Bitfield-Mask: 0x03)                         */
#define R_ESC_SM3CONTROL_DIR_Pos              (2UL)          /*!< DIR (Bit 2)                                           */
#define R_ESC_SM3CONTROL_DIR_Msk              (0xcUL)        /*!< DIR (Bitfield-Mask: 0x03)                             */
#define R_ESC_SM3CONTROL_IRQECAT_Pos          (4UL)          /*!< IRQECAT (Bit 4)                                       */
#define R_ESC_SM3CONTROL_IRQECAT_Msk          (0x10UL)       /*!< IRQECAT (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM3CONTROL_IRQPDI_Pos           (5UL)          /*!< IRQPDI (Bit 5)                                        */
#define R_ESC_SM3CONTROL_IRQPDI_Msk           (0x20UL)       /*!< IRQPDI (Bitfield-Mask: 0x01)                          */
#define R_ESC_SM3CONTROL_WDTRGEN_Pos          (6UL)          /*!< WDTRGEN (Bit 6)                                       */
#define R_ESC_SM3CONTROL_WDTRGEN_Msk          (0x40UL)       /*!< WDTRGEN (Bitfield-Mask: 0x01)                         */
/* =======================================================  SM3STATUS  ======================================================= */
#define R_ESC_SM3STATUS_INTWR_Pos             (0UL)          /*!< INTWR (Bit 0)                                         */
#define R_ESC_SM3STATUS_INTWR_Msk             (0x1UL)        /*!< INTWR (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM3STATUS_INTRD_Pos             (1UL)          /*!< INTRD (Bit 1)                                         */
#define R_ESC_SM3STATUS_INTRD_Msk             (0x2UL)        /*!< INTRD (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM3STATUS_MAILBOX_Pos           (3UL)          /*!< MAILBOX (Bit 3)                                       */
#define R_ESC_SM3STATUS_MAILBOX_Msk           (0x8UL)        /*!< MAILBOX (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM3STATUS_BUFFERED_Pos          (4UL)          /*!< BUFFERED (Bit 4)                                      */
#define R_ESC_SM3STATUS_BUFFERED_Msk          (0x30UL)       /*!< BUFFERED (Bitfield-Mask: 0x03)                        */
#define R_ESC_SM3STATUS_RDBUF_Pos             (6UL)          /*!< RDBUF (Bit 6)                                         */
#define R_ESC_SM3STATUS_RDBUF_Msk             (0x40UL)       /*!< RDBUF (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM3STATUS_WRBUF_Pos             (7UL)          /*!< WRBUF (Bit 7)                                         */
#define R_ESC_SM3STATUS_WRBUF_Msk             (0x80UL)       /*!< WRBUF (Bitfield-Mask: 0x01)                           */
/* ========================================================  SM3ACT  ========================================================= */
#define R_ESC_SM3ACT_SMEN_Pos                 (0UL)          /*!< SMEN (Bit 0)                                          */
#define R_ESC_SM3ACT_SMEN_Msk                 (0x1UL)        /*!< SMEN (Bitfield-Mask: 0x01)                            */
#define R_ESC_SM3ACT_REPEATREQ_Pos            (1UL)          /*!< REPEATREQ (Bit 1)                                     */
#define R_ESC_SM3ACT_REPEATREQ_Msk            (0x2UL)        /*!< REPEATREQ (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM3ACT_LATCHECAT_Pos            (6UL)          /*!< LATCHECAT (Bit 6)                                     */
#define R_ESC_SM3ACT_LATCHECAT_Msk            (0x40UL)       /*!< LATCHECAT (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM3ACT_LATCHPDI_Pos             (7UL)          /*!< LATCHPDI (Bit 7)                                      */
#define R_ESC_SM3ACT_LATCHPDI_Msk             (0x80UL)       /*!< LATCHPDI (Bitfield-Mask: 0x01)                        */
/* ======================================================  SM3PDICONT  ======================================================= */
#define R_ESC_SM3PDICONT_DEACTIVE_Pos         (0UL)          /*!< DEACTIVE (Bit 0)                                      */
#define R_ESC_SM3PDICONT_DEACTIVE_Msk         (0x1UL)        /*!< DEACTIVE (Bitfield-Mask: 0x01)                        */
#define R_ESC_SM3PDICONT_REPEATACK_Pos        (1UL)          /*!< REPEATACK (Bit 1)                                     */
#define R_ESC_SM3PDICONT_REPEATACK_Msk        (0x2UL)        /*!< REPEATACK (Bitfield-Mask: 0x01)                       */
/* =====================================================  SM4PSTARTADR  ====================================================== */
/* ========================================================  SM4LEN  ========================================================= */
/* ======================================================  SM4CONTROL  ======================================================= */
#define R_ESC_SM4CONTROL_OPEMODE_Pos          (0UL)          /*!< OPEMODE (Bit 0)                                       */
#define R_ESC_SM4CONTROL_OPEMODE_Msk          (0x3UL)        /*!< OPEMODE (Bitfield-Mask: 0x03)                         */
#define R_ESC_SM4CONTROL_DIR_Pos              (2UL)          /*!< DIR (Bit 2)                                           */
#define R_ESC_SM4CONTROL_DIR_Msk              (0xcUL)        /*!< DIR (Bitfield-Mask: 0x03)                             */
#define R_ESC_SM4CONTROL_IRQECAT_Pos          (4UL)          /*!< IRQECAT (Bit 4)                                       */
#define R_ESC_SM4CONTROL_IRQECAT_Msk          (0x10UL)       /*!< IRQECAT (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM4CONTROL_IRQPDI_Pos           (5UL)          /*!< IRQPDI (Bit 5)                                        */
#define R_ESC_SM4CONTROL_IRQPDI_Msk           (0x20UL)       /*!< IRQPDI (Bitfield-Mask: 0x01)                          */
#define R_ESC_SM4CONTROL_WDTRGEN_Pos          (6UL)          /*!< WDTRGEN (Bit 6)                                       */
#define R_ESC_SM4CONTROL_WDTRGEN_Msk          (0x40UL)       /*!< WDTRGEN (Bitfield-Mask: 0x01)                         */
/* =======================================================  SM4STATUS  ======================================================= */
#define R_ESC_SM4STATUS_INTWR_Pos             (0UL)          /*!< INTWR (Bit 0)                                         */
#define R_ESC_SM4STATUS_INTWR_Msk             (0x1UL)        /*!< INTWR (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM4STATUS_INTRD_Pos             (1UL)          /*!< INTRD (Bit 1)                                         */
#define R_ESC_SM4STATUS_INTRD_Msk             (0x2UL)        /*!< INTRD (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM4STATUS_MAILBOX_Pos           (3UL)          /*!< MAILBOX (Bit 3)                                       */
#define R_ESC_SM4STATUS_MAILBOX_Msk           (0x8UL)        /*!< MAILBOX (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM4STATUS_BUFFERED_Pos          (4UL)          /*!< BUFFERED (Bit 4)                                      */
#define R_ESC_SM4STATUS_BUFFERED_Msk          (0x30UL)       /*!< BUFFERED (Bitfield-Mask: 0x03)                        */
#define R_ESC_SM4STATUS_RDBUF_Pos             (6UL)          /*!< RDBUF (Bit 6)                                         */
#define R_ESC_SM4STATUS_RDBUF_Msk             (0x40UL)       /*!< RDBUF (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM4STATUS_WRBUF_Pos             (7UL)          /*!< WRBUF (Bit 7)                                         */
#define R_ESC_SM4STATUS_WRBUF_Msk             (0x80UL)       /*!< WRBUF (Bitfield-Mask: 0x01)                           */
/* ========================================================  SM4ACT  ========================================================= */
#define R_ESC_SM4ACT_SMEN_Pos                 (0UL)          /*!< SMEN (Bit 0)                                          */
#define R_ESC_SM4ACT_SMEN_Msk                 (0x1UL)        /*!< SMEN (Bitfield-Mask: 0x01)                            */
#define R_ESC_SM4ACT_REPEATREQ_Pos            (1UL)          /*!< REPEATREQ (Bit 1)                                     */
#define R_ESC_SM4ACT_REPEATREQ_Msk            (0x2UL)        /*!< REPEATREQ (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM4ACT_LATCHECAT_Pos            (6UL)          /*!< LATCHECAT (Bit 6)                                     */
#define R_ESC_SM4ACT_LATCHECAT_Msk            (0x40UL)       /*!< LATCHECAT (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM4ACT_LATCHPDI_Pos             (7UL)          /*!< LATCHPDI (Bit 7)                                      */
#define R_ESC_SM4ACT_LATCHPDI_Msk             (0x80UL)       /*!< LATCHPDI (Bitfield-Mask: 0x01)                        */
/* ======================================================  SM4PDICONT  ======================================================= */
#define R_ESC_SM4PDICONT_DEACTIVE_Pos         (0UL)          /*!< DEACTIVE (Bit 0)                                      */
#define R_ESC_SM4PDICONT_DEACTIVE_Msk         (0x1UL)        /*!< DEACTIVE (Bitfield-Mask: 0x01)                        */
#define R_ESC_SM4PDICONT_REPEATACK_Pos        (1UL)          /*!< REPEATACK (Bit 1)                                     */
#define R_ESC_SM4PDICONT_REPEATACK_Msk        (0x2UL)        /*!< REPEATACK (Bitfield-Mask: 0x01)                       */
/* =====================================================  SM5PSTARTADR  ====================================================== */
/* ========================================================  SM5LEN  ========================================================= */
/* ======================================================  SM5CONTROL  ======================================================= */
#define R_ESC_SM5CONTROL_OPEMODE_Pos          (0UL)          /*!< OPEMODE (Bit 0)                                       */
#define R_ESC_SM5CONTROL_OPEMODE_Msk          (0x3UL)        /*!< OPEMODE (Bitfield-Mask: 0x03)                         */
#define R_ESC_SM5CONTROL_DIR_Pos              (2UL)          /*!< DIR (Bit 2)                                           */
#define R_ESC_SM5CONTROL_DIR_Msk              (0xcUL)        /*!< DIR (Bitfield-Mask: 0x03)                             */
#define R_ESC_SM5CONTROL_IRQECAT_Pos          (4UL)          /*!< IRQECAT (Bit 4)                                       */
#define R_ESC_SM5CONTROL_IRQECAT_Msk          (0x10UL)       /*!< IRQECAT (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM5CONTROL_IRQPDI_Pos           (5UL)          /*!< IRQPDI (Bit 5)                                        */
#define R_ESC_SM5CONTROL_IRQPDI_Msk           (0x20UL)       /*!< IRQPDI (Bitfield-Mask: 0x01)                          */
#define R_ESC_SM5CONTROL_WDTRGEN_Pos          (6UL)          /*!< WDTRGEN (Bit 6)                                       */
#define R_ESC_SM5CONTROL_WDTRGEN_Msk          (0x40UL)       /*!< WDTRGEN (Bitfield-Mask: 0x01)                         */
/* =======================================================  SM5STATUS  ======================================================= */
#define R_ESC_SM5STATUS_INTWR_Pos             (0UL)          /*!< INTWR (Bit 0)                                         */
#define R_ESC_SM5STATUS_INTWR_Msk             (0x1UL)        /*!< INTWR (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM5STATUS_INTRD_Pos             (1UL)          /*!< INTRD (Bit 1)                                         */
#define R_ESC_SM5STATUS_INTRD_Msk             (0x2UL)        /*!< INTRD (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM5STATUS_MAILBOX_Pos           (3UL)          /*!< MAILBOX (Bit 3)                                       */
#define R_ESC_SM5STATUS_MAILBOX_Msk           (0x8UL)        /*!< MAILBOX (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM5STATUS_BUFFERED_Pos          (4UL)          /*!< BUFFERED (Bit 4)                                      */
#define R_ESC_SM5STATUS_BUFFERED_Msk          (0x30UL)       /*!< BUFFERED (Bitfield-Mask: 0x03)                        */
#define R_ESC_SM5STATUS_RDBUF_Pos             (6UL)          /*!< RDBUF (Bit 6)                                         */
#define R_ESC_SM5STATUS_RDBUF_Msk             (0x40UL)       /*!< RDBUF (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM5STATUS_WRBUF_Pos             (7UL)          /*!< WRBUF (Bit 7)                                         */
#define R_ESC_SM5STATUS_WRBUF_Msk             (0x80UL)       /*!< WRBUF (Bitfield-Mask: 0x01)                           */
/* ========================================================  SM5ACT  ========================================================= */
#define R_ESC_SM5ACT_SMEN_Pos                 (0UL)          /*!< SMEN (Bit 0)                                          */
#define R_ESC_SM5ACT_SMEN_Msk                 (0x1UL)        /*!< SMEN (Bitfield-Mask: 0x01)                            */
#define R_ESC_SM5ACT_REPEATREQ_Pos            (1UL)          /*!< REPEATREQ (Bit 1)                                     */
#define R_ESC_SM5ACT_REPEATREQ_Msk            (0x2UL)        /*!< REPEATREQ (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM5ACT_LATCHECAT_Pos            (6UL)          /*!< LATCHECAT (Bit 6)                                     */
#define R_ESC_SM5ACT_LATCHECAT_Msk            (0x40UL)       /*!< LATCHECAT (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM5ACT_LATCHPDI_Pos             (7UL)          /*!< LATCHPDI (Bit 7)                                      */
#define R_ESC_SM5ACT_LATCHPDI_Msk             (0x80UL)       /*!< LATCHPDI (Bitfield-Mask: 0x01)                        */
/* ======================================================  SM5PDICONT  ======================================================= */
#define R_ESC_SM5PDICONT_DEACTIVE_Pos         (0UL)          /*!< DEACTIVE (Bit 0)                                      */
#define R_ESC_SM5PDICONT_DEACTIVE_Msk         (0x1UL)        /*!< DEACTIVE (Bitfield-Mask: 0x01)                        */
#define R_ESC_SM5PDICONT_REPEATACK_Pos        (1UL)          /*!< REPEATACK (Bit 1)                                     */
#define R_ESC_SM5PDICONT_REPEATACK_Msk        (0x2UL)        /*!< REPEATACK (Bitfield-Mask: 0x01)                       */
/* =====================================================  SM6PSTARTADR  ====================================================== */
/* ========================================================  SM6LEN  ========================================================= */
/* ======================================================  SM6CONTROL  ======================================================= */
#define R_ESC_SM6CONTROL_OPEMODE_Pos          (0UL)          /*!< OPEMODE (Bit 0)                                       */
#define R_ESC_SM6CONTROL_OPEMODE_Msk          (0x3UL)        /*!< OPEMODE (Bitfield-Mask: 0x03)                         */
#define R_ESC_SM6CONTROL_DIR_Pos              (2UL)          /*!< DIR (Bit 2)                                           */
#define R_ESC_SM6CONTROL_DIR_Msk              (0xcUL)        /*!< DIR (Bitfield-Mask: 0x03)                             */
#define R_ESC_SM6CONTROL_IRQECAT_Pos          (4UL)          /*!< IRQECAT (Bit 4)                                       */
#define R_ESC_SM6CONTROL_IRQECAT_Msk          (0x10UL)       /*!< IRQECAT (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM6CONTROL_IRQPDI_Pos           (5UL)          /*!< IRQPDI (Bit 5)                                        */
#define R_ESC_SM6CONTROL_IRQPDI_Msk           (0x20UL)       /*!< IRQPDI (Bitfield-Mask: 0x01)                          */
#define R_ESC_SM6CONTROL_WDTRGEN_Pos          (6UL)          /*!< WDTRGEN (Bit 6)                                       */
#define R_ESC_SM6CONTROL_WDTRGEN_Msk          (0x40UL)       /*!< WDTRGEN (Bitfield-Mask: 0x01)                         */
/* =======================================================  SM6STATUS  ======================================================= */
#define R_ESC_SM6STATUS_INTWR_Pos             (0UL)          /*!< INTWR (Bit 0)                                         */
#define R_ESC_SM6STATUS_INTWR_Msk             (0x1UL)        /*!< INTWR (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM6STATUS_INTRD_Pos             (1UL)          /*!< INTRD (Bit 1)                                         */
#define R_ESC_SM6STATUS_INTRD_Msk             (0x2UL)        /*!< INTRD (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM6STATUS_MAILBOX_Pos           (3UL)          /*!< MAILBOX (Bit 3)                                       */
#define R_ESC_SM6STATUS_MAILBOX_Msk           (0x8UL)        /*!< MAILBOX (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM6STATUS_BUFFERED_Pos          (4UL)          /*!< BUFFERED (Bit 4)                                      */
#define R_ESC_SM6STATUS_BUFFERED_Msk          (0x30UL)       /*!< BUFFERED (Bitfield-Mask: 0x03)                        */
#define R_ESC_SM6STATUS_RDBUF_Pos             (6UL)          /*!< RDBUF (Bit 6)                                         */
#define R_ESC_SM6STATUS_RDBUF_Msk             (0x40UL)       /*!< RDBUF (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM6STATUS_WRBUF_Pos             (7UL)          /*!< WRBUF (Bit 7)                                         */
#define R_ESC_SM6STATUS_WRBUF_Msk             (0x80UL)       /*!< WRBUF (Bitfield-Mask: 0x01)                           */
/* ========================================================  SM6ACT  ========================================================= */
#define R_ESC_SM6ACT_SMEN_Pos                 (0UL)          /*!< SMEN (Bit 0)                                          */
#define R_ESC_SM6ACT_SMEN_Msk                 (0x1UL)        /*!< SMEN (Bitfield-Mask: 0x01)                            */
#define R_ESC_SM6ACT_REPEATREQ_Pos            (1UL)          /*!< REPEATREQ (Bit 1)                                     */
#define R_ESC_SM6ACT_REPEATREQ_Msk            (0x2UL)        /*!< REPEATREQ (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM6ACT_LATCHECAT_Pos            (6UL)          /*!< LATCHECAT (Bit 6)                                     */
#define R_ESC_SM6ACT_LATCHECAT_Msk            (0x40UL)       /*!< LATCHECAT (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM6ACT_LATCHPDI_Pos             (7UL)          /*!< LATCHPDI (Bit 7)                                      */
#define R_ESC_SM6ACT_LATCHPDI_Msk             (0x80UL)       /*!< LATCHPDI (Bitfield-Mask: 0x01)                        */
/* ======================================================  SM6PDICONT  ======================================================= */
#define R_ESC_SM6PDICONT_DEACTIVE_Pos         (0UL)          /*!< DEACTIVE (Bit 0)                                      */
#define R_ESC_SM6PDICONT_DEACTIVE_Msk         (0x1UL)        /*!< DEACTIVE (Bitfield-Mask: 0x01)                        */
#define R_ESC_SM6PDICONT_REPEATACK_Pos        (1UL)          /*!< REPEATACK (Bit 1)                                     */
#define R_ESC_SM6PDICONT_REPEATACK_Msk        (0x2UL)        /*!< REPEATACK (Bitfield-Mask: 0x01)                       */
/* =====================================================  SM7PSTARTADR  ====================================================== */
/* ========================================================  SM7LEN  ========================================================= */
/* ======================================================  SM7CONTROL  ======================================================= */
#define R_ESC_SM7CONTROL_OPEMODE_Pos          (0UL)          /*!< OPEMODE (Bit 0)                                       */
#define R_ESC_SM7CONTROL_OPEMODE_Msk          (0x3UL)        /*!< OPEMODE (Bitfield-Mask: 0x03)                         */
#define R_ESC_SM7CONTROL_DIR_Pos              (2UL)          /*!< DIR (Bit 2)                                           */
#define R_ESC_SM7CONTROL_DIR_Msk              (0xcUL)        /*!< DIR (Bitfield-Mask: 0x03)                             */
#define R_ESC_SM7CONTROL_IRQECAT_Pos          (4UL)          /*!< IRQECAT (Bit 4)                                       */
#define R_ESC_SM7CONTROL_IRQECAT_Msk          (0x10UL)       /*!< IRQECAT (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM7CONTROL_IRQPDI_Pos           (5UL)          /*!< IRQPDI (Bit 5)                                        */
#define R_ESC_SM7CONTROL_IRQPDI_Msk           (0x20UL)       /*!< IRQPDI (Bitfield-Mask: 0x01)                          */
#define R_ESC_SM7CONTROL_WDTRGEN_Pos          (6UL)          /*!< WDTRGEN (Bit 6)                                       */
#define R_ESC_SM7CONTROL_WDTRGEN_Msk          (0x40UL)       /*!< WDTRGEN (Bitfield-Mask: 0x01)                         */
/* =======================================================  SM7STATUS  ======================================================= */
#define R_ESC_SM7STATUS_INTWR_Pos             (0UL)          /*!< INTWR (Bit 0)                                         */
#define R_ESC_SM7STATUS_INTWR_Msk             (0x1UL)        /*!< INTWR (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM7STATUS_INTRD_Pos             (1UL)          /*!< INTRD (Bit 1)                                         */
#define R_ESC_SM7STATUS_INTRD_Msk             (0x2UL)        /*!< INTRD (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM7STATUS_MAILBOX_Pos           (3UL)          /*!< MAILBOX (Bit 3)                                       */
#define R_ESC_SM7STATUS_MAILBOX_Msk           (0x8UL)        /*!< MAILBOX (Bitfield-Mask: 0x01)                         */
#define R_ESC_SM7STATUS_BUFFERED_Pos          (4UL)          /*!< BUFFERED (Bit 4)                                      */
#define R_ESC_SM7STATUS_BUFFERED_Msk          (0x30UL)       /*!< BUFFERED (Bitfield-Mask: 0x03)                        */
#define R_ESC_SM7STATUS_RDBUF_Pos             (6UL)          /*!< RDBUF (Bit 6)                                         */
#define R_ESC_SM7STATUS_RDBUF_Msk             (0x40UL)       /*!< RDBUF (Bitfield-Mask: 0x01)                           */
#define R_ESC_SM7STATUS_WRBUF_Pos             (7UL)          /*!< WRBUF (Bit 7)                                         */
#define R_ESC_SM7STATUS_WRBUF_Msk             (0x80UL)       /*!< WRBUF (Bitfield-Mask: 0x01)                           */
/* ========================================================  SM7ACT  ========================================================= */
#define R_ESC_SM7ACT_SMEN_Pos                 (0UL)          /*!< SMEN (Bit 0)                                          */
#define R_ESC_SM7ACT_SMEN_Msk                 (0x1UL)        /*!< SMEN (Bitfield-Mask: 0x01)                            */
#define R_ESC_SM7ACT_REPEATREQ_Pos            (1UL)          /*!< REPEATREQ (Bit 1)                                     */
#define R_ESC_SM7ACT_REPEATREQ_Msk            (0x2UL)        /*!< REPEATREQ (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM7ACT_LATCHECAT_Pos            (6UL)          /*!< LATCHECAT (Bit 6)                                     */
#define R_ESC_SM7ACT_LATCHECAT_Msk            (0x40UL)       /*!< LATCHECAT (Bitfield-Mask: 0x01)                       */
#define R_ESC_SM7ACT_LATCHPDI_Pos             (7UL)          /*!< LATCHPDI (Bit 7)                                      */
#define R_ESC_SM7ACT_LATCHPDI_Msk             (0x80UL)       /*!< LATCHPDI (Bitfield-Mask: 0x01)                        */
/* ======================================================  SM7PDICONT  ======================================================= */
#define R_ESC_SM7PDICONT_DEACTIVE_Pos         (0UL)          /*!< DEACTIVE (Bit 0)                                      */
#define R_ESC_SM7PDICONT_DEACTIVE_Msk         (0x1UL)        /*!< DEACTIVE (Bitfield-Mask: 0x01)                        */
#define R_ESC_SM7PDICONT_REPEATACK_Pos        (1UL)          /*!< REPEATACK (Bit 1)                                     */
#define R_ESC_SM7PDICONT_REPEATACK_Msk        (0x2UL)        /*!< REPEATACK (Bitfield-Mask: 0x01)                       */
/* ====================================================  DCRCVTIMEPORT0  ===================================================== */
/* ====================================================  DCRCVTIMEPORT1  ===================================================== */
/* ======================================================  DCSYSTIME_L  ====================================================== */
/* ======================================================  DCSYSTIME_H  ====================================================== */
/* ====================================================  DCRCVTIMEEPU_L  ===================================================== */
/* ====================================================  DCRCVTIMEEPU_H  ===================================================== */
/* ===================================================  DCSYSTIMEOFFSET_L  =================================================== */
/* ===================================================  DCSYSTIMEOFFSET_H  =================================================== */
/* ====================================================  DCSYSTIMEDELAY  ===================================================== */
/* =====================================================  DCSYSTIMEDIFF  ===================================================== */
#define R_ESC_DCSYSTIMEDIFF_DIFF_Pos         (0UL)          /*!< DIFF (Bit 0)                                          */
#define R_ESC_DCSYSTIMEDIFF_DIFF_Msk         (0x7fffffffUL) /*!< DIFF (Bitfield-Mask: 0x7fffffff)                      */
#define R_ESC_DCSYSTIMEDIFF_LOCALCOPY_Pos    (31UL)         /*!< LOCALCOPY (Bit 31)                                    */
#define R_ESC_DCSYSTIMEDIFF_LOCALCOPY_Msk    (0x80000000UL) /*!< LOCALCOPY (Bitfield-Mask: 0x01)                       */
/* =======================================================  DCSCSTART  ======================================================= */
#define R_ESC_DCSCSTART_SCSTART_Pos          (0UL)          /*!< SCSTART (Bit 0)                                       */
#define R_ESC_DCSCSTART_SCSTART_Msk          (0x7fffUL)     /*!< SCSTART (Bitfield-Mask: 0x7fff)                       */
/* =======================================================  DCSCDIFF  ======================================================== */
/* ====================================================  DCSYSTIMEFILDP  ===================================================== */
#define R_ESC_DCSYSTIMEFILDP_FILDP_Pos       (0UL)          /*!< FILDP (Bit 0)                                         */
#define R_ESC_DCSYSTIMEFILDP_FILDP_Msk       (0xfUL)        /*!< FILDP (Bitfield-Mask: 0x0f)                           */
/* =======================================================  DCSCFILDP  ======================================================= */
#define R_ESC_DCSCFILDP_FILDP_Pos            (0UL)          /*!< FILDP (Bit 0)                                         */
#define R_ESC_DCSCFILDP_FILDP_Msk            (0xfUL)        /*!< FILDP (Bitfield-Mask: 0x0f)                           */
/* =======================================================  DCCYCCONT  ======================================================= */
#define R_ESC_DCCYCCONT_SYNCOUT_Pos          (0UL)          /*!< SYNCOUT (Bit 0)                                       */
#define R_ESC_DCCYCCONT_SYNCOUT_Msk          (0x1UL)        /*!< SYNCOUT (Bitfield-Mask: 0x01)                         */
#define R_ESC_DCCYCCONT_LATCH0_Pos           (4UL)          /*!< LATCH0 (Bit 4)                                        */
#define R_ESC_DCCYCCONT_LATCH0_Msk           (0x10UL)       /*!< LATCH0 (Bitfield-Mask: 0x01)                          */
#define R_ESC_DCCYCCONT_LATCH1_Pos           (5UL)          /*!< LATCH1 (Bit 5)                                        */
#define R_ESC_DCCYCCONT_LATCH1_Msk           (0x20UL)       /*!< LATCH1 (Bitfield-Mask: 0x01)                          */
/* =========================================================  DCACT  ========================================================= */
#define R_ESC_DCACT_SYNCACT_Pos              (0UL)          /*!< SYNCACT (Bit 0)                                       */
#define R_ESC_DCACT_SYNCACT_Msk              (0x1UL)        /*!< SYNCACT (Bitfield-Mask: 0x01)                         */
#define R_ESC_DCACT_SYNC0_Pos                (1UL)          /*!< SYNC0 (Bit 1)                                         */
#define R_ESC_DCACT_SYNC0_Msk                (0x2UL)        /*!< SYNC0 (Bitfield-Mask: 0x01)                           */
#define R_ESC_DCACT_SYNC1_Pos                (2UL)          /*!< SYNC1 (Bit 2)                                         */
#define R_ESC_DCACT_SYNC1_Msk                (0x4UL)        /*!< SYNC1 (Bitfield-Mask: 0x01)                           */
#define R_ESC_DCACT_AUTOACT_Pos              (3UL)          /*!< AUTOACT (Bit 3)                                       */
#define R_ESC_DCACT_AUTOACT_Msk              (0x8UL)        /*!< AUTOACT (Bitfield-Mask: 0x01)                         */
#define R_ESC_DCACT_EXTSTARTTIME_Pos         (4UL)          /*!< EXTSTARTTIME (Bit 4)                                  */
#define R_ESC_DCACT_EXTSTARTTIME_Msk         (0x10UL)       /*!< EXTSTARTTIME (Bitfield-Mask: 0x01)                    */
#define R_ESC_DCACT_STARTTIME_Pos            (5UL)          /*!< STARTTIME (Bit 5)                                     */
#define R_ESC_DCACT_STARTTIME_Msk            (0x20UL)       /*!< STARTTIME (Bitfield-Mask: 0x01)                       */
#define R_ESC_DCACT_NEARFUTURE_Pos           (6UL)          /*!< NEARFUTURE (Bit 6)                                    */
#define R_ESC_DCACT_NEARFUTURE_Msk           (0x40UL)       /*!< NEARFUTURE (Bitfield-Mask: 0x01)                      */
#define R_ESC_DCACT_DBGPULSE_Pos             (7UL)          /*!< DBGPULSE (Bit 7)                                      */
#define R_ESC_DCACT_DBGPULSE_Msk             (0x80UL)       /*!< DBGPULSE (Bitfield-Mask: 0x01)                        */
/* ======================================================  DCPULSELEN  ======================================================= */
/* =======================================================  DCACTSTAT  ======================================================= */
#define R_ESC_DCACTSTAT_SYNC0ACT_Pos         (0UL)          /*!< SYNC0ACT (Bit 0)                                      */
#define R_ESC_DCACTSTAT_SYNC0ACT_Msk         (0x1UL)        /*!< SYNC0ACT (Bitfield-Mask: 0x01)                        */
#define R_ESC_DCACTSTAT_SYNC1ACT_Pos         (1UL)          /*!< SYNC1ACT (Bit 1)                                      */
#define R_ESC_DCACTSTAT_SYNC1ACT_Msk         (0x2UL)        /*!< SYNC1ACT (Bitfield-Mask: 0x01)                        */
#define R_ESC_DCACTSTAT_STARTTIME_Pos        (2UL)          /*!< STARTTIME (Bit 2)                                     */
#define R_ESC_DCACTSTAT_STARTTIME_Msk        (0x4UL)        /*!< STARTTIME (Bitfield-Mask: 0x01)                       */
/* ======================================================  DCSYNC0STAT  ====================================================== */
#define R_ESC_DCSYNC0STAT_SYNC0STA_Pos       (0UL)          /*!< SYNC0STA (Bit 0)                                      */
#define R_ESC_DCSYNC0STAT_SYNC0STA_Msk       (0x1UL)        /*!< SYNC0STA (Bitfield-Mask: 0x01)                        */
/* ======================================================  DCSYNC1STAT  ====================================================== */
#define R_ESC_DCSYNC1STAT_SYNC1STA_Pos       (0UL)          /*!< SYNC1STA (Bit 0)                                      */
#define R_ESC_DCSYNC1STAT_SYNC1STA_Msk       (0x1UL)        /*!< SYNC1STA (Bitfield-Mask: 0x01)                        */
/* ===================================================  DCCYCSTARTTIME_L  ==================================================== */
/* ===================================================  DCCYCSTARTTIME_H  ==================================================== */
/* =====================================================  DCNEXTSYNC1_L  ===================================================== */
/* =====================================================  DCNEXTSYNC1_H  ===================================================== */
/* ====================================================  DCSYNC0CYCTIME  ===================================================== */
/* ====================================================  DCSYNC1CYCTIME  ===================================================== */
/* =====================================================  DCLATCH0CONT  ====================================================== */
#define R_ESC_DCLATCH0CONT_POSEDGE_Pos     (0UL)   /*!< POSEDGE (Bit 0)                                       */
#define R_ESC_DCLATCH0CONT_POSEDGE_Msk     (0x1UL) /*!< POSEDGE (Bitfield-Mask: 0x01)                         */
#define R_ESC_DCLATCH0CONT_NEGEDGE_Pos     (1UL)   /*!< NEGEDGE (Bit 1)                                       */
#define R_ESC_DCLATCH0CONT_NEGEDGE_Msk     (0x2UL) /*!< NEGEDGE (Bitfield-Mask: 0x01)                         */
/* =====================================================  DCLATCH1CONT  ====================================================== */
#define R_ESC_DCLATCH1CONT_POSEDGE_Pos     (0UL)   /*!< POSEDGE (Bit 0)                                       */
#define R_ESC_DCLATCH1CONT_POSEDGE_Msk     (0x1UL) /*!< POSEDGE (Bitfield-Mask: 0x01)                         */
#define R_ESC_DCLATCH1CONT_NEGEDGE_Pos     (1UL)   /*!< NEGEDGE (Bit 1)                                       */
#define R_ESC_DCLATCH1CONT_NEGEDGE_Msk     (0x2UL) /*!< NEGEDGE (Bitfield-Mask: 0x01)                         */
/* =====================================================  DCLATCH0STAT  ====================================================== */
#define R_ESC_DCLATCH0STAT_EVENTPOS_Pos    (0UL)   /*!< EVENTPOS (Bit 0)                                      */
#define R_ESC_DCLATCH0STAT_EVENTPOS_Msk    (0x1UL) /*!< EVENTPOS (Bitfield-Mask: 0x01)                        */
#define R_ESC_DCLATCH0STAT_EVENTNEG_Pos    (1UL)   /*!< EVENTNEG (Bit 1)                                      */
#define R_ESC_DCLATCH0STAT_EVENTNEG_Msk    (0x2UL) /*!< EVENTNEG (Bitfield-Mask: 0x01)                        */
#define R_ESC_DCLATCH0STAT_PINSTATE_Pos    (2UL)   /*!< PINSTATE (Bit 2)                                      */
#define R_ESC_DCLATCH0STAT_PINSTATE_Msk    (0x4UL) /*!< PINSTATE (Bitfield-Mask: 0x01)                        */
/* =====================================================  DCLATCH1STAT  ====================================================== */
#define R_ESC_DCLATCH1STAT_EVENTPOS_Pos    (0UL)   /*!< EVENTPOS (Bit 0)                                      */
#define R_ESC_DCLATCH1STAT_EVENTPOS_Msk    (0x1UL) /*!< EVENTPOS (Bitfield-Mask: 0x01)                        */
#define R_ESC_DCLATCH1STAT_EVENTNEG_Pos    (1UL)   /*!< EVENTNEG (Bit 1)                                      */
#define R_ESC_DCLATCH1STAT_EVENTNEG_Msk    (0x2UL) /*!< EVENTNEG (Bitfield-Mask: 0x01)                        */
#define R_ESC_DCLATCH1STAT_PINSTATE_Pos    (2UL)   /*!< PINSTATE (Bit 2)                                      */
#define R_ESC_DCLATCH1STAT_PINSTATE_Msk    (0x4UL) /*!< PINSTATE (Bitfield-Mask: 0x01)                        */
/* ===================================================  DCLATCH0TIMEPOS_L  =================================================== */
/* ===================================================  DCLATCH0TIMEPOS_H  =================================================== */
/* ===================================================  DCLATCH0TIMENEG_L  =================================================== */
/* ===================================================  DCLATCH0TIMENEG_H  =================================================== */
/* ===================================================  DCLATCH1TIMEPOS_L  =================================================== */
/* ===================================================  DCLATCH1TIMEPOS_H  =================================================== */
/* ===================================================  DCLATCH1TIMENEG_L  =================================================== */
/* ===================================================  DCLATCH1TIMENEG_H  =================================================== */
/* =====================================================  DCECATCHGTIME  ===================================================== */
/* ====================================================  DCPDISTARTTIME  ===================================================== */
/* =====================================================  DCPDICHGTIME  ====================================================== */
/* ======================================================  PRODUCTID_L  ====================================================== */
/* ======================================================  PRODUCTID_H  ====================================================== */
/* ======================================================  VENDORID_L  ======================================================= */
/* ======================================================  VENDORID_H  ======================================================= */
/* ========================================================  USERRAM  ======================================================== */
/* ========================================================  DATARAM  ======================================================== */
/* ========================================================  ESCRST  ========================================================= */
#define R_ESC_ESCRST_ESCRST_Pos       (0UL)    /*!< ESCRST (Bit 0)                                        */
#define R_ESC_ESCRST_ESCRST_Msk       (0x1UL)  /*!< ESCRST (Bitfield-Mask: 0x01)                          */
#define R_ESC_ESCRST_PHYRST_Pos       (1UL)    /*!< PHYRST (Bit 1)                                        */
#define R_ESC_ESCRST_PHYRST_Msk       (0x2UL)  /*!< PHYRST (Bitfield-Mask: 0x01)                          */
#define R_ESC_ESCRST_MIIRST_Pos       (2UL)    /*!< MIIRST (Bit 2)                                        */
#define R_ESC_ESCRST_MIIRST_Msk       (0x4UL)  /*!< MIIRST (Bitfield-Mask: 0x01)                          */
/* ========================================================  MIICR0  ========================================================= */
#define R_ESC_MIICR0_MODE_Pos         (0UL)    /*!< MODE (Bit 0)                                          */
#define R_ESC_MIICR0_MODE_Msk         (0x1fUL) /*!< MODE (Bitfield-Mask: 0x1f)                            */
/* ========================================================  MIICR1  ========================================================= */
#define R_ESC_MIICR1_MODE_Pos         (0UL)    /*!< MODE (Bit 0)                                          */
#define R_ESC_MIICR1_MODE_Msk         (0x1fUL) /*!< MODE (Bitfield-Mask: 0x1f)                            */
/* ========================================================  PHYLINK  ======================================================== */
#define R_ESC_PHYLINK_LINKPOL0_Pos    (0UL)    /*!< LINKPOL0 (Bit 0)                                      */
#define R_ESC_PHYLINK_LINKPOL0_Msk    (0x1UL)  /*!< LINKPOL0 (Bitfield-Mask: 0x01)                        */
#define R_ESC_PHYLINK_LINKPOL1_Pos    (1UL)    /*!< LINKPOL1 (Bit 1)                                      */
#define R_ESC_PHYLINK_LINKPOL1_Msk    (0x2UL)  /*!< LINKPOL1 (Bitfield-Mask: 0x01)                        */
/* ========================================================  ESCICR  ========================================================= */
#define R_ESC_ESCICR_SYNC0C_Pos       (0UL)    /*!< SYNC0C (Bit 0)                                        */
#define R_ESC_ESCICR_SYNC0C_Msk       (0x1UL)  /*!< SYNC0C (Bitfield-Mask: 0x01)                          */
#define R_ESC_ESCICR_SYNC1C_Pos       (1UL)    /*!< SYNC1C (Bit 1)                                        */
#define R_ESC_ESCICR_SYNC1C_Msk       (0x2UL)  /*!< SYNC1C (Bitfield-Mask: 0x01)                          */
#define R_ESC_ESCICR_ESCIC_Pos        (2UL)    /*!< ESCIC (Bit 2)                                         */
#define R_ESC_ESCICR_ESCIC_Msk        (0x4UL)  /*!< ESCIC (Bitfield-Mask: 0x01)                           */
/* ========================================================  PHYOFF  ========================================================= */
#define R_ESC_PHYOFF_OFFSET_Pos       (0UL)    /*!< OFFSET (Bit 0)                                        */
#define R_ESC_PHYOFF_OFFSET_Msk       (0x1fUL) /*!< OFFSET (Bitfield-Mask: 0x1f)                          */
/* =========================================================  ESCMR  ========================================================= */
#define R_ESC_ESCMR_PROMSIZE_Pos      (0UL)    /*!< PROMSIZE (Bit 0)                                      */
#define R_ESC_ESCMR_PROMSIZE_Msk      (0x1UL)  /*!< PROMSIZE (Bitfield-Mask: 0x01)                        */
/* ========================================================  TXSFTR  ========================================================= */
#define R_ESC_TXSFTR_TXSFT0_Pos       (0UL)    /*!< TXSFT0 (Bit 0)                                        */
#define R_ESC_TXSFTR_TXSFT0_Msk       (0x3UL)  /*!< TXSFT0 (Bitfield-Mask: 0x03)                          */
#define R_ESC_TXSFTR_TXSFT1_Pos       (2UL)    /*!< TXSFT1 (Bit 2)                                        */
#define R_ESC_TXSFTR_TXSFT1_Msk       (0xcUL)  /*!< TXSFT1 (Bitfield-Mask: 0x03)                          */

/** @} */ /* End of group PosMask_peripherals */

#endif                                         /* R_ESC_POSMSK_H */
