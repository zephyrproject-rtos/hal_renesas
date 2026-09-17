/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ETHOSU_IOBITMASK_H
#define R_ETHOSU_IOBITMASK_H

/* =========================================================================================================================== */
/* ================                                           R_NPU                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  ID  =========================================================== */
#define R_NPU_ID_arch_major_rev_Pos                      (28UL)         /*!< arch_major_rev (Bit 28)                               */
#define R_NPU_ID_arch_major_rev_Msk                      (0xf0000000UL) /*!< arch_major_rev (Bitfield-Mask: 0x0f)                  */
#define R_NPU_ID_arch_minor_rev_Pos                      (20UL)         /*!< arch_minor_rev (Bit 20)                               */
#define R_NPU_ID_arch_minor_rev_Msk                      (0xff00000UL)  /*!< arch_minor_rev (Bitfield-Mask: 0xff)                  */
#define R_NPU_ID_arch_patch_rev_Pos                      (16UL)         /*!< arch_patch_rev (Bit 16)                               */
#define R_NPU_ID_arch_patch_rev_Msk                      (0xf0000UL)    /*!< arch_patch_rev (Bitfield-Mask: 0x0f)                  */
#define R_NPU_ID_product_major_Pos                       (12UL)         /*!< product_major (Bit 12)                                */
#define R_NPU_ID_product_major_Msk                       (0xf000UL)     /*!< product_major (Bitfield-Mask: 0x0f)                   */
#define R_NPU_ID_version_major_Pos                       (8UL)          /*!< version_major (Bit 8)                                 */
#define R_NPU_ID_version_major_Msk                       (0xf00UL)      /*!< version_major (Bitfield-Mask: 0x0f)                   */
#define R_NPU_ID_version_minor_Pos                       (4UL)          /*!< version_minor (Bit 4)                                 */
#define R_NPU_ID_version_minor_Msk                       (0xf0UL)       /*!< version_minor (Bitfield-Mask: 0x0f)                   */
#define R_NPU_ID_version_status_Pos                      (0UL)          /*!< version_status (Bit 0)                                */
#define R_NPU_ID_version_status_Msk                      (0xfUL)        /*!< version_status (Bitfield-Mask: 0x0f)                  */
/* ========================================================  STATUS  ========================================================= */
#define R_NPU_STATUS_irq_history_mask_Pos                (16UL)         /*!< irq_history_mask (Bit 16)                             */
#define R_NPU_STATUS_irq_history_mask_Msk                (0xffff0000UL) /*!< irq_history_mask (Bitfield-Mask: 0xffff)              */
#define R_NPU_STATUS_faulting_channel_Pos                (12UL)         /*!< faulting_channel (Bit 12)                             */
#define R_NPU_STATUS_faulting_channel_Msk                (0xf000UL)     /*!< faulting_channel (Bitfield-Mask: 0x0f)                */
#define R_NPU_STATUS_faulting_interface_Pos              (11UL)         /*!< faulting_interface (Bit 11)                           */
#define R_NPU_STATUS_faulting_interface_Msk              (0x800UL)      /*!< faulting_interface (Bitfield-Mask: 0x01)              */
#define R_NPU_STATUS_ecc_fault_Pos                       (8UL)          /*!< ecc_fault (Bit 8)                                     */
#define R_NPU_STATUS_ecc_fault_Msk                       (0x100UL)      /*!< ecc_fault (Bitfield-Mask: 0x01)                       */
#define R_NPU_STATUS_pmu_irq_raised_Pos                  (6UL)          /*!< pmu_irq_raised (Bit 6)                                */
#define R_NPU_STATUS_pmu_irq_raised_Msk                  (0x40UL)       /*!< pmu_irq_raised (Bitfield-Mask: 0x01)                  */
#define R_NPU_STATUS_cmd_end_reached_Pos                 (5UL)          /*!< cmd_end_reached (Bit 5)                               */
#define R_NPU_STATUS_cmd_end_reached_Msk                 (0x20UL)       /*!< cmd_end_reached (Bitfield-Mask: 0x01)                 */
#define R_NPU_STATUS_cmd_parse_error_Pos                 (4UL)          /*!< cmd_parse_error (Bit 4)                               */
#define R_NPU_STATUS_cmd_parse_error_Msk                 (0x10UL)       /*!< cmd_parse_error (Bitfield-Mask: 0x01)                 */
#define R_NPU_STATUS_reset_status_Pos                    (3UL)          /*!< reset_status (Bit 3)                                  */
#define R_NPU_STATUS_reset_status_Msk                    (0x8UL)        /*!< reset_status (Bitfield-Mask: 0x01)                    */
#define R_NPU_STATUS_bus_status_Pos                      (2UL)          /*!< bus_status (Bit 2)                                    */
#define R_NPU_STATUS_bus_status_Msk                      (0x4UL)        /*!< bus_status (Bitfield-Mask: 0x01)                      */
#define R_NPU_STATUS_irq_raised_Pos                      (1UL)          /*!< irq_raised (Bit 1)                                    */
#define R_NPU_STATUS_irq_raised_Msk                      (0x2UL)        /*!< irq_raised (Bitfield-Mask: 0x01)                      */
#define R_NPU_STATUS_state_Pos                           (0UL)          /*!< state (Bit 0)                                         */
#define R_NPU_STATUS_state_Msk                           (0x1UL)        /*!< state (Bitfield-Mask: 0x01)                           */
/* ==========================================================  CMD  ========================================================== */
#define R_NPU_CMD_clear_irq_history_Pos                  (16UL)         /*!< clear_irq_history (Bit 16)                            */
#define R_NPU_CMD_clear_irq_history_Msk                  (0xffff0000UL) /*!< clear_irq_history (Bitfield-Mask: 0xffff)             */
#define R_NPU_CMD_power_q_enable_Pos                     (3UL)          /*!< power_q_enable (Bit 3)                                */
#define R_NPU_CMD_power_q_enable_Msk                     (0x8UL)        /*!< power_q_enable (Bitfield-Mask: 0x01)                  */
#define R_NPU_CMD_clock_q_enable_Pos                     (2UL)          /*!< clock_q_enable (Bit 2)                                */
#define R_NPU_CMD_clock_q_enable_Msk                     (0x4UL)        /*!< clock_q_enable (Bitfield-Mask: 0x01)                  */
#define R_NPU_CMD_clear_irq_Pos                          (1UL)          /*!< clear_irq (Bit 1)                                     */
#define R_NPU_CMD_clear_irq_Msk                          (0x2UL)        /*!< clear_irq (Bitfield-Mask: 0x01)                       */
#define R_NPU_CMD_transition_to_running_state_Pos        (0UL)          /*!< transition_to_running_state (Bit 0)                   */
#define R_NPU_CMD_transition_to_running_state_Msk        (0x1UL)        /*!< transition_to_running_state (Bitfield-Mask: 0x01)     */
/* =========================================================  RESET  ========================================================= */
#define R_NPU_RESET_pending_CSL_Pos                      (1UL)          /*!< pending_CSL (Bit 1)                                   */
#define R_NPU_RESET_pending_CSL_Msk                      (0x2UL)        /*!< pending_CSL (Bitfield-Mask: 0x01)                     */
#define R_NPU_RESET_pending_CPL_Pos                      (0UL)          /*!< pending_CPL (Bit 0)                                   */
#define R_NPU_RESET_pending_CPL_Msk                      (0x1UL)        /*!< pending_CPL (Bitfield-Mask: 0x01)                     */
/* ========================================================  QBASE0  ========================================================= */
#define R_NPU_QBASE0_QBASE0_Pos                          (0UL)          /*!< QBASE0 (Bit 0)                                        */
#define R_NPU_QBASE0_QBASE0_Msk                          (0xffffffffUL) /*!< QBASE0 (Bitfield-Mask: 0xffffffff)                    */
/* ========================================================  QBASE1  ========================================================= */
#define R_NPU_QBASE1_QBASE1_Pos                          (0UL)          /*!< QBASE1 (Bit 0)                                        */
#define R_NPU_QBASE1_QBASE1_Msk                          (0xffffffffUL) /*!< QBASE1 (Bitfield-Mask: 0xffffffff)                    */
/* =========================================================  QREAD  ========================================================= */
#define R_NPU_QREAD_QREAD_Pos                            (0UL)          /*!< QREAD (Bit 0)                                         */
#define R_NPU_QREAD_QREAD_Msk                            (0xffffffffUL) /*!< QREAD (Bitfield-Mask: 0xffffffff)                     */
/* ========================================================  QCONFIG  ======================================================== */
#define R_NPU_QCONFIG_QCONFIG_Pos                        (0UL)          /*!< QCONFIG (Bit 0)                                       */
#define R_NPU_QCONFIG_QCONFIG_Msk                        (0xffffffffUL) /*!< QCONFIG (Bitfield-Mask: 0xffffffff)                   */
/* =========================================================  QSIZE  ========================================================= */
#define R_NPU_QSIZE_QSIZE_Pos                            (0UL)          /*!< QSIZE (Bit 0)                                         */
#define R_NPU_QSIZE_QSIZE_Msk                            (0xffffffffUL) /*!< QSIZE (Bitfield-Mask: 0xffffffff)                     */
/* =========================================================  PROT  ========================================================== */
#define R_NPU_PROT_active_CSL_Pos                        (1UL)          /*!< active_CSL (Bit 1)                                    */
#define R_NPU_PROT_active_CSL_Msk                        (0x2UL)        /*!< active_CSL (Bitfield-Mask: 0x01)                      */
#define R_NPU_PROT_active_CPL_Pos                        (0UL)          /*!< active_CPL (Bit 0)                                    */
#define R_NPU_PROT_active_CPL_Msk                        (0x1UL)        /*!< active_CPL (Bitfield-Mask: 0x01)                      */
/* ========================================================  CONFIG  ========================================================= */
#define R_NPU_CONFIG_product_Pos                         (28UL)         /*!< product (Bit 28)                                      */
#define R_NPU_CONFIG_product_Msk                         (0xf0000000UL) /*!< product (Bitfield-Mask: 0x0f)                         */
#define R_NPU_CONFIG_custom_dma_Pos                      (27UL)         /*!< custom_dma (Bit 27)                                   */
#define R_NPU_CONFIG_custom_dma_Msk                      (0x8000000UL)  /*!< custom_dma (Bitfield-Mask: 0x01)                      */
#define R_NPU_CONFIG_shram_size_Pos                      (8UL)          /*!< shram_size (Bit 8)                                    */
#define R_NPU_CONFIG_shram_size_Msk                      (0xff00UL)     /*!< shram_size (Bitfield-Mask: 0xff)                      */
#define R_NPU_CONFIG_cmd_stream_version_Pos              (4UL)          /*!< cmd_stream_version (Bit 4)                            */
#define R_NPU_CONFIG_cmd_stream_version_Msk              (0xf0UL)       /*!< cmd_stream_version (Bitfield-Mask: 0x0f)              */
#define R_NPU_CONFIG_macs_per_cc_Pos                     (0UL)          /*!< macs_per_cc (Bit 0)                                   */
#define R_NPU_CONFIG_macs_per_cc_Msk                     (0xfUL)        /*!< macs_per_cc (Bitfield-Mask: 0x0f)                     */
/* =========================================================  LOCK  ========================================================== */
#define R_NPU_LOCK_LOCK_Pos                              (0UL)          /*!< LOCK (Bit 0)                                          */
#define R_NPU_LOCK_LOCK_Msk                              (0xffffffffUL) /*!< LOCK (Bitfield-Mask: 0xffffffff)                      */
/* =======================================================  REGIONCFG  ======================================================= */
#define R_NPU_REGIONCFG_region7_Pos                      (14UL)         /*!< region7 (Bit 14)                                      */
#define R_NPU_REGIONCFG_region7_Msk                      (0xc000UL)     /*!< region7 (Bitfield-Mask: 0x03)                         */
#define R_NPU_REGIONCFG_region6_Pos                      (12UL)         /*!< region6 (Bit 12)                                      */
#define R_NPU_REGIONCFG_region6_Msk                      (0x3000UL)     /*!< region6 (Bitfield-Mask: 0x03)                         */
#define R_NPU_REGIONCFG_region5_Pos                      (10UL)         /*!< region5 (Bit 10)                                      */
#define R_NPU_REGIONCFG_region5_Msk                      (0xc00UL)      /*!< region5 (Bitfield-Mask: 0x03)                         */
#define R_NPU_REGIONCFG_region4_Pos                      (8UL)          /*!< region4 (Bit 8)                                       */
#define R_NPU_REGIONCFG_region4_Msk                      (0x300UL)      /*!< region4 (Bitfield-Mask: 0x03)                         */
#define R_NPU_REGIONCFG_region3_Pos                      (6UL)          /*!< region3 (Bit 6)                                       */
#define R_NPU_REGIONCFG_region3_Msk                      (0xc0UL)       /*!< region3 (Bitfield-Mask: 0x03)                         */
#define R_NPU_REGIONCFG_region2_Pos                      (4UL)          /*!< region2 (Bit 4)                                       */
#define R_NPU_REGIONCFG_region2_Msk                      (0x30UL)       /*!< region2 (Bitfield-Mask: 0x03)                         */
#define R_NPU_REGIONCFG_region1_Pos                      (2UL)          /*!< region1 (Bit 2)                                       */
#define R_NPU_REGIONCFG_region1_Msk                      (0xcUL)        /*!< region1 (Bitfield-Mask: 0x03)                         */
#define R_NPU_REGIONCFG_region0_Pos                      (0UL)          /*!< region0 (Bit 0)                                       */
#define R_NPU_REGIONCFG_region0_Msk                      (0x3UL)        /*!< region0 (Bitfield-Mask: 0x03)                         */
/* ======================================================  AXI_LIMIT0  ======================================================= */
#define R_NPU_AXI_LIMIT0_max_outstanding_write_m1_Pos    (24UL)         /*!< max_outstanding_write_m1 (Bit 24)                     */
#define R_NPU_AXI_LIMIT0_max_outstanding_write_m1_Msk    (0xff000000UL) /*!< max_outstanding_write_m1 (Bitfield-Mask: 0xff)       */
#define R_NPU_AXI_LIMIT0_max_outstanding_read_m1_Pos     (16UL)         /*!< max_outstanding_read_m1 (Bit 16)                      */
#define R_NPU_AXI_LIMIT0_max_outstanding_read_m1_Msk     (0xff0000UL)   /*!< max_outstanding_read_m1 (Bitfield-Mask: 0xff)         */
#define R_NPU_AXI_LIMIT0_memtype_Pos                     (4UL)          /*!< memtype (Bit 4)                                       */
#define R_NPU_AXI_LIMIT0_memtype_Msk                     (0xf0UL)       /*!< memtype (Bitfield-Mask: 0x0f)                         */
#define R_NPU_AXI_LIMIT0_max_beats_Pos                   (0UL)          /*!< max_beats (Bit 0)                                     */
#define R_NPU_AXI_LIMIT0_max_beats_Msk                   (0x3UL)        /*!< max_beats (Bitfield-Mask: 0x03)                       */
/* ======================================================  AXI_LIMIT1  ======================================================= */
#define R_NPU_AXI_LIMIT1_max_outstanding_write_m1_Pos    (24UL)         /*!< max_outstanding_write_m1 (Bit 24)                     */
#define R_NPU_AXI_LIMIT1_max_outstanding_write_m1_Msk    (0xff000000UL) /*!< max_outstanding_write_m1 (Bitfield-Mask: 0xff)       */
#define R_NPU_AXI_LIMIT1_max_outstanding_read_m1_Pos     (16UL)         /*!< max_outstanding_read_m1 (Bit 16)                      */
#define R_NPU_AXI_LIMIT1_max_outstanding_read_m1_Msk     (0xff0000UL)   /*!< max_outstanding_read_m1 (Bitfield-Mask: 0xff)         */
#define R_NPU_AXI_LIMIT1_memtype_Pos                     (4UL)          /*!< memtype (Bit 4)                                       */
#define R_NPU_AXI_LIMIT1_memtype_Msk                     (0xf0UL)       /*!< memtype (Bitfield-Mask: 0x0f)                         */
#define R_NPU_AXI_LIMIT1_max_beats_Pos                   (0UL)          /*!< max_beats (Bit 0)                                     */
#define R_NPU_AXI_LIMIT1_max_beats_Msk                   (0x3UL)        /*!< max_beats (Bitfield-Mask: 0x03)                       */
/* ======================================================  AXI_LIMIT2  ======================================================= */
#define R_NPU_AXI_LIMIT2_max_outstanding_write_m1_Pos    (24UL)         /*!< max_outstanding_write_m1 (Bit 24)                     */
#define R_NPU_AXI_LIMIT2_max_outstanding_write_m1_Msk    (0xff000000UL) /*!< max_outstanding_write_m1 (Bitfield-Mask: 0xff)       */
#define R_NPU_AXI_LIMIT2_max_outstanding_read_m1_Pos     (16UL)         /*!< max_outstanding_read_m1 (Bit 16)                      */
#define R_NPU_AXI_LIMIT2_max_outstanding_read_m1_Msk     (0xff0000UL)   /*!< max_outstanding_read_m1 (Bitfield-Mask: 0xff)         */
#define R_NPU_AXI_LIMIT2_memtype_Pos                     (4UL)          /*!< memtype (Bit 4)                                       */
#define R_NPU_AXI_LIMIT2_memtype_Msk                     (0xf0UL)       /*!< memtype (Bitfield-Mask: 0x0f)                         */
#define R_NPU_AXI_LIMIT2_max_beats_Pos                   (0UL)          /*!< max_beats (Bit 0)                                     */
#define R_NPU_AXI_LIMIT2_max_beats_Msk                   (0x3UL)        /*!< max_beats (Bitfield-Mask: 0x03)                       */
/* ======================================================  AXI_LIMIT3  ======================================================= */
#define R_NPU_AXI_LIMIT3_max_outstanding_write_m1_Pos    (24UL)         /*!< max_outstanding_write_m1 (Bit 24)                     */
#define R_NPU_AXI_LIMIT3_max_outstanding_write_m1_Msk    (0xff000000UL) /*!< max_outstanding_write_m1 (Bitfield-Mask: 0xff)       */
#define R_NPU_AXI_LIMIT3_max_outstanding_read_m1_Pos     (16UL)         /*!< max_outstanding_read_m1 (Bit 16)                      */
#define R_NPU_AXI_LIMIT3_max_outstanding_read_m1_Msk     (0xff0000UL)   /*!< max_outstanding_read_m1 (Bitfield-Mask: 0xff)         */
#define R_NPU_AXI_LIMIT3_memtype_Pos                     (4UL)          /*!< memtype (Bit 4)                                       */
#define R_NPU_AXI_LIMIT3_memtype_Msk                     (0xf0UL)       /*!< memtype (Bitfield-Mask: 0x0f)                         */
#define R_NPU_AXI_LIMIT3_max_beats_Pos                   (0UL)          /*!< max_beats (Bit 0)                                     */
#define R_NPU_AXI_LIMIT3_max_beats_Msk                   (0x3UL)        /*!< max_beats (Bitfield-Mask: 0x03)                       */
/* ========================================================  BASEP0  ========================================================= */
#define R_NPU_BASEP0_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP0_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP1  ========================================================= */
#define R_NPU_BASEP1_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP1_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP2  ========================================================= */
#define R_NPU_BASEP2_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP2_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP3  ========================================================= */
#define R_NPU_BASEP3_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP3_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP4  ========================================================= */
#define R_NPU_BASEP4_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP4_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP5  ========================================================= */
#define R_NPU_BASEP5_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP5_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP6  ========================================================= */
#define R_NPU_BASEP6_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP6_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP7  ========================================================= */
#define R_NPU_BASEP7_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP7_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP8  ========================================================= */
#define R_NPU_BASEP8_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP8_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP9  ========================================================= */
#define R_NPU_BASEP9_addr_word_Pos                       (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP9_addr_word_Msk                       (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP10  ======================================================== */
#define R_NPU_BASEP10_addr_word_Pos                      (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP10_addr_word_Msk                      (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP11  ======================================================== */
#define R_NPU_BASEP11_addr_word_Pos                      (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP11_addr_word_Msk                      (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP12  ======================================================== */
#define R_NPU_BASEP12_addr_word_Pos                      (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP12_addr_word_Msk                      (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP13  ======================================================== */
#define R_NPU_BASEP13_addr_word_Pos                      (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP13_addr_word_Msk                      (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP14  ======================================================== */
#define R_NPU_BASEP14_addr_word_Pos                      (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP14_addr_word_Msk                      (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* ========================================================  BASEP15  ======================================================== */
#define R_NPU_BASEP15_addr_word_Pos                      (0UL)          /*!< addr_word (Bit 0)                                     */
#define R_NPU_BASEP15_addr_word_Msk                      (0xffffffffUL) /*!< addr_word (Bitfield-Mask: 0xffffffff)                 */
/* =========================================================  PID4  ========================================================== */
#define R_NPU_PID4_PID4_Pos                              (0UL)          /*!< PID4 (Bit 0)                                          */
#define R_NPU_PID4_PID4_Msk                              (0xffffffffUL) /*!< PID4 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  PID5  ========================================================== */
#define R_NPU_PID5_PID5_Pos                              (0UL)          /*!< PID5 (Bit 0)                                          */
#define R_NPU_PID5_PID5_Msk                              (0xffffffffUL) /*!< PID5 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  PID6  ========================================================== */
#define R_NPU_PID6_PID6_Pos                              (0UL)          /*!< PID6 (Bit 0)                                          */
#define R_NPU_PID6_PID6_Msk                              (0xffffffffUL) /*!< PID6 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  PID7  ========================================================== */
#define R_NPU_PID7_PID7_Pos                              (0UL)          /*!< PID7 (Bit 0)                                          */
#define R_NPU_PID7_PID7_Msk                              (0xffffffffUL) /*!< PID7 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  PID0  ========================================================== */
#define R_NPU_PID0_PID0_Pos                              (0UL)          /*!< PID0 (Bit 0)                                          */
#define R_NPU_PID0_PID0_Msk                              (0xffffffffUL) /*!< PID0 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  PID1  ========================================================== */
#define R_NPU_PID1_PID1_Pos                              (0UL)          /*!< PID1 (Bit 0)                                          */
#define R_NPU_PID1_PID1_Msk                              (0xffffffffUL) /*!< PID1 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  PID2  ========================================================== */
#define R_NPU_PID2_PID2_Pos                              (0UL)          /*!< PID2 (Bit 0)                                          */
#define R_NPU_PID2_PID2_Msk                              (0xffffffffUL) /*!< PID2 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  PID3  ========================================================== */
#define R_NPU_PID3_PID3_Pos                              (0UL)          /*!< PID3 (Bit 0)                                          */
#define R_NPU_PID3_PID3_Msk                              (0xffffffffUL) /*!< PID3 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  CID0  ========================================================== */
#define R_NPU_CID0_CID0_Pos                              (0UL)          /*!< CID0 (Bit 0)                                          */
#define R_NPU_CID0_CID0_Msk                              (0xffffffffUL) /*!< CID0 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  CID1  ========================================================== */
#define R_NPU_CID1_CID1_Pos                              (0UL)          /*!< CID1 (Bit 0)                                          */
#define R_NPU_CID1_CID1_Msk                              (0xffffffffUL) /*!< CID1 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  CID2  ========================================================== */
#define R_NPU_CID2_CID2_Pos                              (0UL)          /*!< CID2 (Bit 0)                                          */
#define R_NPU_CID2_CID2_Msk                              (0xffffffffUL) /*!< CID2 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  CID3  ========================================================== */
#define R_NPU_CID3_CID3_Pos                              (0UL)          /*!< CID3 (Bit 0)                                          */
#define R_NPU_CID3_CID3_Msk                              (0xffffffffUL) /*!< CID3 (Bitfield-Mask: 0xffffffff)                      */
/* =========================================================  PMCR  ========================================================== */
#define R_NPU_PMCR_num_event_cnt_Pos                     (11UL)         /*!< num_event_cnt (Bit 11)                                */
#define R_NPU_PMCR_num_event_cnt_Msk                     (0xf800UL)     /*!< num_event_cnt (Bitfield-Mask: 0x1f)                   */
#define R_NPU_PMCR_mask_en_Pos                           (3UL)          /*!< mask_en (Bit 3)                                       */
#define R_NPU_PMCR_mask_en_Msk                           (0x8UL)        /*!< mask_en (Bitfield-Mask: 0x01)                         */
#define R_NPU_PMCR_cycle_cnt_rst_Pos                     (2UL)          /*!< cycle_cnt_rst (Bit 2)                                 */
#define R_NPU_PMCR_cycle_cnt_rst_Msk                     (0x4UL)        /*!< cycle_cnt_rst (Bitfield-Mask: 0x01)                   */
#define R_NPU_PMCR_event_cnt_rst_Pos                     (1UL)          /*!< event_cnt_rst (Bit 1)                                 */
#define R_NPU_PMCR_event_cnt_rst_Msk                     (0x2UL)        /*!< event_cnt_rst (Bitfield-Mask: 0x01)                   */
#define R_NPU_PMCR_cnt_en_Pos                            (0UL)          /*!< cnt_en (Bit 0)                                        */
#define R_NPU_PMCR_cnt_en_Msk                            (0x1UL)        /*!< cnt_en (Bitfield-Mask: 0x01)                          */
/* ======================================================  PMCNTENSET  ======================================================= */
#define R_NPU_PMCNTENSET_CYCLE_CNT_Pos                   (31UL)         /*!< CYCLE_CNT (Bit 31)                                    */
#define R_NPU_PMCNTENSET_CYCLE_CNT_Msk                   (0x80000000UL) /*!< CYCLE_CNT (Bitfield-Mask: 0x01)                       */
#define R_NPU_PMCNTENSET_EVENT_CNT_3_Pos                 (3UL)          /*!< EVENT_CNT_3 (Bit 3)                                   */
#define R_NPU_PMCNTENSET_EVENT_CNT_3_Msk                 (0x8UL)        /*!< EVENT_CNT_3 (Bitfield-Mask: 0x01)                     */
#define R_NPU_PMCNTENSET_EVENT_CNT_2_Pos                 (2UL)          /*!< EVENT_CNT_2 (Bit 2)                                   */
#define R_NPU_PMCNTENSET_EVENT_CNT_2_Msk                 (0x4UL)        /*!< EVENT_CNT_2 (Bitfield-Mask: 0x01)                     */
#define R_NPU_PMCNTENSET_EVENT_CNT_1_Pos                 (1UL)          /*!< EVENT_CNT_1 (Bit 1)                                   */
#define R_NPU_PMCNTENSET_EVENT_CNT_1_Msk                 (0x2UL)        /*!< EVENT_CNT_1 (Bitfield-Mask: 0x01)                     */
#define R_NPU_PMCNTENSET_EVENT_CNT_0_Pos                 (0UL)          /*!< EVENT_CNT_0 (Bit 0)                                   */
#define R_NPU_PMCNTENSET_EVENT_CNT_0_Msk                 (0x1UL)        /*!< EVENT_CNT_0 (Bitfield-Mask: 0x01)                     */
/* ======================================================  PMCNTENCLR  ======================================================= */
#define R_NPU_PMCNTENCLR_CYCLE_CNT_Pos                   (31UL)         /*!< CYCLE_CNT (Bit 31)                                    */
#define R_NPU_PMCNTENCLR_CYCLE_CNT_Msk                   (0x80000000UL) /*!< CYCLE_CNT (Bitfield-Mask: 0x01)                       */
#define R_NPU_PMCNTENCLR_EVENT_CNT_3_Pos                 (3UL)          /*!< EVENT_CNT_3 (Bit 3)                                   */
#define R_NPU_PMCNTENCLR_EVENT_CNT_3_Msk                 (0x8UL)        /*!< EVENT_CNT_3 (Bitfield-Mask: 0x01)                     */
#define R_NPU_PMCNTENCLR_EVENT_CNT_2_Pos                 (2UL)          /*!< EVENT_CNT_2 (Bit 2)                                   */
#define R_NPU_PMCNTENCLR_EVENT_CNT_2_Msk                 (0x4UL)        /*!< EVENT_CNT_2 (Bitfield-Mask: 0x01)                     */
#define R_NPU_PMCNTENCLR_EVENT_CNT_1_Pos                 (1UL)          /*!< EVENT_CNT_1 (Bit 1)                                   */
#define R_NPU_PMCNTENCLR_EVENT_CNT_1_Msk                 (0x2UL)        /*!< EVENT_CNT_1 (Bitfield-Mask: 0x01)                     */
#define R_NPU_PMCNTENCLR_EVENT_CNT_0_Pos                 (0UL)          /*!< EVENT_CNT_0 (Bit 0)                                   */
#define R_NPU_PMCNTENCLR_EVENT_CNT_0_Msk                 (0x1UL)        /*!< EVENT_CNT_0 (Bitfield-Mask: 0x01)                     */
/* =======================================================  PMOVSSET  ======================================================== */
#define R_NPU_PMOVSSET_CYCLE_CNT_OVF_Pos                 (31UL)         /*!< CYCLE_CNT_OVF (Bit 31)                                */
#define R_NPU_PMOVSSET_CYCLE_CNT_OVF_Msk                 (0x80000000UL) /*!< CYCLE_CNT_OVF (Bitfield-Mask: 0x01)                   */
#define R_NPU_PMOVSSET_EVENT_CNT_3_OVF_Pos               (3UL)          /*!< EVENT_CNT_3_OVF (Bit 3)                               */
#define R_NPU_PMOVSSET_EVENT_CNT_3_OVF_Msk               (0x8UL)        /*!< EVENT_CNT_3_OVF (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMOVSSET_EVENT_CNT_2_OVF_Pos               (2UL)          /*!< EVENT_CNT_2_OVF (Bit 2)                               */
#define R_NPU_PMOVSSET_EVENT_CNT_2_OVF_Msk               (0x4UL)        /*!< EVENT_CNT_2_OVF (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMOVSSET_EVENT_CNT_1_OVF_Pos               (1UL)          /*!< EVENT_CNT_1_OVF (Bit 1)                               */
#define R_NPU_PMOVSSET_EVENT_CNT_1_OVF_Msk               (0x2UL)        /*!< EVENT_CNT_1_OVF (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMOVSSET_EVENT_CNT_0_OVF_Pos               (0UL)          /*!< EVENT_CNT_0_OVF (Bit 0)                               */
#define R_NPU_PMOVSSET_EVENT_CNT_0_OVF_Msk               (0x1UL)        /*!< EVENT_CNT_0_OVF (Bitfield-Mask: 0x01)                 */
/* =======================================================  PMOVSCLR  ======================================================== */
#define R_NPU_PMOVSCLR_CYCLE_CNT_OVF_Pos                 (31UL)         /*!< CYCLE_CNT_OVF (Bit 31)                                */
#define R_NPU_PMOVSCLR_CYCLE_CNT_OVF_Msk                 (0x80000000UL) /*!< CYCLE_CNT_OVF (Bitfield-Mask: 0x01)                   */
#define R_NPU_PMOVSCLR_EVENT_CNT_3_OVF_Pos               (3UL)          /*!< EVENT_CNT_3_OVF (Bit 3)                               */
#define R_NPU_PMOVSCLR_EVENT_CNT_3_OVF_Msk               (0x8UL)        /*!< EVENT_CNT_3_OVF (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMOVSCLR_EVENT_CNT_2_OVF_Pos               (2UL)          /*!< EVENT_CNT_2_OVF (Bit 2)                               */
#define R_NPU_PMOVSCLR_EVENT_CNT_2_OVF_Msk               (0x4UL)        /*!< EVENT_CNT_2_OVF (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMOVSCLR_EVENT_CNT_1_OVF_Pos               (1UL)          /*!< EVENT_CNT_1_OVF (Bit 1)                               */
#define R_NPU_PMOVSCLR_EVENT_CNT_1_OVF_Msk               (0x2UL)        /*!< EVENT_CNT_1_OVF (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMOVSCLR_EVENT_CNT_0_OVF_Pos               (0UL)          /*!< EVENT_CNT_0_OVF (Bit 0)                               */
#define R_NPU_PMOVSCLR_EVENT_CNT_0_OVF_Msk               (0x1UL)        /*!< EVENT_CNT_0_OVF (Bitfield-Mask: 0x01)                 */
/* =======================================================  PMINTSET  ======================================================== */
#define R_NPU_PMINTSET_CYCLE_CNT_INT_Pos                 (31UL)         /*!< CYCLE_CNT_INT (Bit 31)                                */
#define R_NPU_PMINTSET_CYCLE_CNT_INT_Msk                 (0x80000000UL) /*!< CYCLE_CNT_INT (Bitfield-Mask: 0x01)                   */
#define R_NPU_PMINTSET_EVENT_CNT_3_INT_Pos               (3UL)          /*!< EVENT_CNT_3_INT (Bit 3)                               */
#define R_NPU_PMINTSET_EVENT_CNT_3_INT_Msk               (0x8UL)        /*!< EVENT_CNT_3_INT (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMINTSET_EVENT_CNT_2_INT_Pos               (2UL)          /*!< EVENT_CNT_2_INT (Bit 2)                               */
#define R_NPU_PMINTSET_EVENT_CNT_2_INT_Msk               (0x4UL)        /*!< EVENT_CNT_2_INT (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMINTSET_EVENT_CNT_1_INT_Pos               (1UL)          /*!< EVENT_CNT_1_INT (Bit 1)                               */
#define R_NPU_PMINTSET_EVENT_CNT_1_INT_Msk               (0x2UL)        /*!< EVENT_CNT_1_INT (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMINTSET_EVENT_CNT_0_INT_Pos               (0UL)          /*!< EVENT_CNT_0_INT (Bit 0)                               */
#define R_NPU_PMINTSET_EVENT_CNT_0_INT_Msk               (0x1UL)        /*!< EVENT_CNT_0_INT (Bitfield-Mask: 0x01)                 */
/* =======================================================  PMINTCLR  ======================================================== */
#define R_NPU_PMINTCLR_CYCLE_CNT_INT_Pos                 (31UL)         /*!< CYCLE_CNT_INT (Bit 31)                                */
#define R_NPU_PMINTCLR_CYCLE_CNT_INT_Msk                 (0x80000000UL) /*!< CYCLE_CNT_INT (Bitfield-Mask: 0x01)                   */
#define R_NPU_PMINTCLR_EVENT_CNT_3_INT_Pos               (3UL)          /*!< EVENT_CNT_3_INT (Bit 3)                               */
#define R_NPU_PMINTCLR_EVENT_CNT_3_INT_Msk               (0x8UL)        /*!< EVENT_CNT_3_INT (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMINTCLR_EVENT_CNT_2_INT_Pos               (2UL)          /*!< EVENT_CNT_2_INT (Bit 2)                               */
#define R_NPU_PMINTCLR_EVENT_CNT_2_INT_Msk               (0x4UL)        /*!< EVENT_CNT_2_INT (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMINTCLR_EVENT_CNT_1_INT_Pos               (1UL)          /*!< EVENT_CNT_1_INT (Bit 1)                               */
#define R_NPU_PMINTCLR_EVENT_CNT_1_INT_Msk               (0x2UL)        /*!< EVENT_CNT_1_INT (Bitfield-Mask: 0x01)                 */
#define R_NPU_PMINTCLR_EVENT_CNT_0_INT_Pos               (0UL)          /*!< EVENT_CNT_0_INT (Bit 0)                               */
#define R_NPU_PMINTCLR_EVENT_CNT_0_INT_Msk               (0x1UL)        /*!< EVENT_CNT_0_INT (Bitfield-Mask: 0x01)                 */
/* ======================================================  PMCCNTR_LO  ======================================================= */
#define R_NPU_PMCCNTR_LO_CYCLE_CNT_LO_Pos                (0UL)          /*!< CYCLE_CNT_LO (Bit 0)                                  */
#define R_NPU_PMCCNTR_LO_CYCLE_CNT_LO_Msk                (0xffffffffUL) /*!< CYCLE_CNT_LO (Bitfield-Mask: 0xffffffff)              */
/* ======================================================  PMCCNTR_HI  ======================================================= */
#define R_NPU_PMCCNTR_HI_CYCLE_CNT_HI_Pos                (0UL)          /*!< CYCLE_CNT_HI (Bit 0)                                  */
#define R_NPU_PMCCNTR_HI_CYCLE_CNT_HI_Msk                (0xffffffffUL) /*!< CYCLE_CNT_HI (Bitfield-Mask: 0xffffffff)              */
/* ======================================================  PMCAXI_CHAN  ====================================================== */
#define R_NPU_PMCAXI_CHAN_BW_CH_SEL_EN_Pos               (10UL)         /*!< BW_CH_SEL_EN (Bit 10)                                 */
#define R_NPU_PMCAXI_CHAN_BW_CH_SEL_EN_Msk               (0x400UL)      /*!< BW_CH_SEL_EN (Bitfield-Mask: 0x01)                    */
#define R_NPU_PMCAXI_CHAN_AXI_CNT_SEL_Pos                (8UL)          /*!< AXI_CNT_SEL (Bit 8)                                   */
#define R_NPU_PMCAXI_CHAN_AXI_CNT_SEL_Msk                (0x300UL)      /*!< AXI_CNT_SEL (Bitfield-Mask: 0x03)                     */
#define R_NPU_PMCAXI_CHAN_CH_SEL_Pos                     (0UL)          /*!< CH_SEL (Bit 0)                                        */
#define R_NPU_PMCAXI_CHAN_CH_SEL_Msk                     (0xfUL)        /*!< CH_SEL (Bitfield-Mask: 0x0f)                          */
/* ======================================================  PMU_EVCNTR0  ====================================================== */
#define R_NPU_PMU_EVCNTR0_PMEVCNTR_Pos                   (0UL)          /*!< PMEVCNTR (Bit 0)                                      */
#define R_NPU_PMU_EVCNTR0_PMEVCNTR_Msk                   (0xffffffffUL) /*!< PMEVCNTR (Bitfield-Mask: 0xffffffff)                  */
/* ======================================================  PMU_EVCNTR1  ====================================================== */
#define R_NPU_PMU_EVCNTR1_PMEVCNTR_Pos                   (0UL)          /*!< PMEVCNTR (Bit 0)                                      */
#define R_NPU_PMU_EVCNTR1_PMEVCNTR_Msk                   (0xffffffffUL) /*!< PMEVCNTR (Bitfield-Mask: 0xffffffff)                  */
/* ======================================================  PMU_EVCNTR2  ====================================================== */
#define R_NPU_PMU_EVCNTR2_PMEVCNTR_Pos                   (0UL)          /*!< PMEVCNTR (Bit 0)                                      */
#define R_NPU_PMU_EVCNTR2_PMEVCNTR_Msk                   (0xffffffffUL) /*!< PMEVCNTR (Bitfield-Mask: 0xffffffff)                  */
/* ======================================================  PMU_EVCNTR3  ====================================================== */
#define R_NPU_PMU_EVCNTR3_PMEVCNTR_Pos                   (0UL)          /*!< PMEVCNTR (Bit 0)                                      */
#define R_NPU_PMU_EVCNTR3_PMEVCNTR_Msk                   (0xffffffffUL) /*!< PMEVCNTR (Bitfield-Mask: 0xffffffff)                  */
/* =====================================================  PMU_EVTYPER0  ====================================================== */
#define R_NPU_PMU_EVTYPER0_EV_TYPE_Pos                   (0UL)          /*!< EV_TYPE (Bit 0)                                       */
#define R_NPU_PMU_EVTYPER0_EV_TYPE_Msk                   (0xffffffffUL) /*!< EV_TYPE (Bitfield-Mask: 0xffffffff)                   */
/* =====================================================  PMU_EVTYPER1  ====================================================== */
#define R_NPU_PMU_EVTYPER1_EV_TYPE_Pos                   (0UL)          /*!< EV_TYPE (Bit 0)                                       */
#define R_NPU_PMU_EVTYPER1_EV_TYPE_Msk                   (0xffffffffUL) /*!< EV_TYPE (Bitfield-Mask: 0xffffffff)                   */
/* =====================================================  PMU_EVTYPER2  ====================================================== */
#define R_NPU_PMU_EVTYPER2_EV_TYPE_Pos                   (0UL)          /*!< EV_TYPE (Bit 0)                                       */
#define R_NPU_PMU_EVTYPER2_EV_TYPE_Msk                   (0xffffffffUL) /*!< EV_TYPE (Bitfield-Mask: 0xffffffff)                   */
/* =====================================================  PMU_EVTYPER3  ====================================================== */
#define R_NPU_PMU_EVTYPER3_EV_TYPE_Pos                   (0UL)          /*!< EV_TYPE (Bit 0)                                       */
#define R_NPU_PMU_EVTYPER3_EV_TYPE_Msk                   (0xffffffffUL) /*!< EV_TYPE (Bitfield-Mask: 0xffffffff)                   */

#endif /* R_ETHOSU_IOBITMASK_H */
