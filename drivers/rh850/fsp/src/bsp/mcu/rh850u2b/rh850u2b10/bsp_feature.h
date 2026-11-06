/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU_RH850U2BX
 * @defgroup BSP_MCU_RH850U2B10 BSP MCU U2B10
 * @brief This module provides the macros, data types, and definition constants required for U2B10 feature.
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

#ifndef BSP_FEATURE_H
#define BSP_FEATURE_H

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU_RH850U2B10
 * @defgroup BSP_FEATURE_U2B10 BSP U2B10 Specific Feature
 * @brief This file defines all feature-related macros for the U2B10 device, including module availability and
 * hardware capability constants.
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_PACKAGE_PINS_BGA468                                               (468U) /* PRQA S 1534 # Advisory R-2.5 */                                     ///< Package pin count: BGA468
#define BSP_PACKAGE_PINS_BGA373                                               (373U)                                                                        ///< Package pin count: BGA373
#define BSP_PACKAGE_PINS_BGA292                                               (292U)                                                                        ///< Package pin count: BGA292

/** Barrier Synchronization */
/** PE mask bit that is used in R_BSP_PESyncEnable */
#define BSP_BARRIER_SYNC_CPU0                                                 (1U << 0U) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< PE mask bit for CPU0 in R_BSP_PESyncEnable
#define BSP_BARRIER_SYNC_CPU1                                                 (1U << 1U) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< PE mask bit for CPU1 in R_BSP_PESyncEnable
#define BSP_BARRIER_SYNC_CPU2                                                 (1U << 2U) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< PE mask bit for CPU2 in R_BSP_PESyncEnable

/** PE value that is used in R_BSP_PESyncComplete */
#define BSP_CPU0                                                              (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CPU identifier value for CPU0
#define BSP_CPU1                                                              (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CPU identifier value for CPU1
#define BSP_CPU2                                                              (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CPU identifier value for CPU2

/** BSP FEATURE */
/** U2B10 */
#define BSP_FEATURE_MMCA_IS_AVAILABLE                                         (0x01U)                                                                       ///< MMC-A feature availability (1 = available)
#define BSP_FEATURE_PSI5_IS_AVAILABLE                                         (0x01U)                                                                       ///< PSI5 module availability (1 = available)
#define BSP_FEATURE_PSI5S_IS_AVAILABLE                                        (0x01U)                                                                       ///< PSI5S module availability (1 = available)
#define BSP_FEATURE_RHSIF_IS_AVAILABLE                                        (0x01U)                                                                       ///< RHSIF module availability (1 = available)
#define BSP_FEATURE_RIIC_IS_AVAILABLE                                         (0x01U)                                                                       ///< RIIC (I2C) module availability (1 = available)
#define BSP_FEATURE_EMU_IS_AVAILABLE                                          (0x00U)                                                                       ///< EMU module availability (0 = not available)

#define BSP_FEATURE_DFA_IS_AVAILABLE                                          (0x00U)                                                                       ///< DFA availability (0 = not available)
#define BSP_FEATURE_DFP_IS_AVAILABLE                                          (0x01U)                                                                       ///< DFP module availability (1 = available)
#define BSP_FEATURE_DSMIF_IS_AVAILABLE                                        (0x01U)                                                                       ///< DSMIF feature availability (1 = available)
#define BSP_FEATURE_RDC3AS_IS_AVAILABLE                                       (0x01U)                                                                       ///< RDC3AS feature availability (1 = available)
#define BSP_FEATURE_RDC3AL_IS_AVAILABLE                                       (0x00U)                                                                       ///< RDC3AL feature availability (0 = not available)
#define BSP_FEATURE_ETND_IS_AVAILABLE                                         (0x01U) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< ETND module available

#define BSP_FEATURE_FEINT_CPU0                                                (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< FEINT interrupt feature for CPU0
#define BSP_FEATURE_FEINT_CPU1                                                (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< FEINT interrupt feature for CPU1
#define BSP_FEATURE_FEINT_CPU2                                                (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< FEINT interrupt feature for CPU2
#define BSP_FEATURE_FEINT_CPU3                                                (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< FEINT interrupt feature for CPU3
#define BSP_FEATURE_CLMA_STOP_DETECTION_IS_AVAILABLE                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Clock Stop Detection Mode support
#define BSP_FEATURE_BSP_PRODUCT_NUMBER_POINTER                                (0x08030040U)                                                                 ///< Address of the Product number register.
#define BSP_FEATURE_BSP_PRODUCT_NAME_POINTER                                  (0x080300A0U)                                                                 ///< Address of the Product name register.
#define BSP_FEATURE_BSP_UNIQUE_ID_POINTER                                     (0x08031000U)                                                                 ///< Address of the MCU Unique ID register.
#define BSP_FEATURE_FPU_IMPRECISE_EXCEPTION_IS_AVAILABLE                      (0U)                                                                          ///< FPU imprecise exception is not available
#define BSP_FEATURE_FPEC_REGISTER_IS_AVAILABLE                                (0U)                                                                          ///< FPEC system register is not available
#define BSP_IO_PORT_TYPE_MAX                                                  (3U)                                                                          ///< IO Port Type max value

/** MODULE RESET */
#define BSP_RESET_SOURCE_POWER_OFF_STANDBY_IS_AVAILABLE                       (0x01U)                                                                       ///< Power-off standby reset source support
#define BSP_RESET_ECM_SELECT_RESET_SOURCE_IS_AVAILABLE                        (0x01U)                                                                       ///< ECM-select reset source supported
#define BSP_RESET_MODULE_RSCFD                                                RSCFD /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Module reset name: RSCFD
#define BSP_RESET_MODULE_FLXA                                                 FLXA /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: FLXA
#define BSP_RESET_MODULE_GTM                                                  GTM /* PRQA S 1534 # Advisory R-2.5 */                                        ///< Module reset name: GTM
#define BSP_RESET_MODULE_ETN                                                  ETN /* PRQA S 1534 # Advisory R-2.5 */                                        ///< Module reset name: ETN
#define BSP_RESET_MODULE_RSENT                                                RSENT /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Module reset name: RSENT
#define BSP_RESET_MODULE_MSPI                                                 MSPI /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: MSPI
#define BSP_RESET_MODULE_RLIN3                                                RLIN3 /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Module reset name: RLIN3
#define BSP_RESET_MODULE_ADCK_ISO                                             ADCK_ISO /* PRQA S 1534 # Advisory R-2.5 */                                   ///< Module reset name: ADCK_ISO
#define BSP_RESET_MODULE_MMCA                                                 MMCA /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: MMCA
#define BSP_RESET_MODULE_ENCA                                                 ENCA /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: ENCA
#define BSP_RESET_MODULE_PSI5                                                 PSI5 /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: PSI5
#define BSP_RESET_MODULE_PSI5S                                                PSI5S /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Module reset name: PSI5S
#define BSP_RESET_MODULE_RHSIF                                                RHSIF /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Module reset name: RHSIF
#define BSP_RESET_MODULE_RIIC                                                 RIIC /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: RIIC
#define BSP_RESET_MODULE_SFMA                                                 SFMA /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: SFMA
#define BSP_RESET_MODULE_TAPA                                                 TAPA /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: TAPA
#define BSP_RESET_MODULE_TAUD                                                 TAUD /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: TAUD
#define BSP_RESET_MODULE_TPBA                                                 TPBA /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: TPBA
#define BSP_RESET_MODULE_TSG3                                                 TSG3 /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: TSG3
#define BSP_RESET_MODULE_OSTM                                                 OSTM /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: OSTM
#define BSP_RESET_MODULE_DSADC_CADC                                           DSADC_CADC /* PRQA S 1534 # Advisory R-2.5 */                                 ///< Module reset name: DSADC_CADC
#define BSP_RESET_MODULE_RHSB                                                 RHSB /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Module reset name: RHSB
#define BSP_RESET_MODULE_ATU                                                  ATU /* PRQA S 1534 # Advisory R-2.5 */                                        ///< Module reset name: ATU
#define BSP_RESET_MODULE_PE                                                   PE /* PRQA S 1534 # Advisory R-2.5 */                                         ///< Module reset name: PE
#define BSP_RESET_MODULE_FCOMP                                                FCOMP /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Module reset name: FCOMP
#define BSP_RESET_MODULE_RDC                                                  RDC /* PRQA S 1534 # Advisory R-2.5 */                                        ///< Module reset name: RDC
#define BSP_RESET_MODULE_DFP                                                  DFP /* PRQA S 1534 # Advisory R-2.5 */                                        ///< Module reset name: DFP
#define BSP_RESET_MODULE_DFE                                                  DFE /* PRQA S 1534 # Advisory R-2.5 */                                        ///< Module reset name: DFE
#define BSP_RESET_MODULE_WDTB_ISO                                             WDTB_ISO /* PRQA S 1534 # Advisory R-2.5 */                                   ///< Module reset name: WDTB_ISO
#define BSP_RESET_MODULE_HRPWM                                                HRPWM /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Module reset name: HRPWM
#define BSP_RESET_MODULE_DSMIF                                                DSMIF /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Module reset name: DSMIF

/** STANDBY MODE */
#define BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE                        (0x00U)                                                                       ///< DeepStop mode availability (0 = not supported)
#define BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE                (0x07U)                                                                       ///< Number of DeepStop wake-up sources
#define BSP_FEATURE_CHIP_STANDBY_IOHOLD_REG_NAME                              (0x01U) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< IOHOLD register index for standby state retention

/** OPBT */
#define BSP_FEATURE_OPBT_BVA1_AREA_IS_AVAILABLE                               (0x00U)                                                                       ///< BVA1 Area is not available
#define BSP_FEATURE_OPBT_SWITCHING_CLUSTER_1_AVAILABLE                        (0x01U)                                                                       ///< OPBT Cluster 1 switching is available
#define BSP_FEATURE_OPBT_SWITCHING_CLUSTER_2_AVAILABLE                        (0x00U)                                                                       ///< OPBT Cluster 2 switching is not available
#define BSP_FEATURE_OPBT_SWITCHING_CLUSTER_3_AVAILABLE                        (0x00U)                                                                       ///< OPBT Cluster 3 switching is not available

/** QOS */
#define BSP_FEATURE_QOS_IS_AVAILABLE                                          (1U)                                                                          ///< QoS feature is available on this device
#define BSP_FEATURE_QOS_PE0CL2_UNIT_AVAILABLE                                 (0U)                                                                          ///< QoS feature for CPU4 is not available
#define BSP_FEATURE_QOS_PE1CL2_UNIT_AVAILABLE                                 (0U)                                                                          ///< QoS feature for CPU5 is not available
#define BSP_FEATURE_QOS_ACEU0_UNIT_AVAILABLE                                  (0U)                                                                          ///< QoS feature for ACU0 is not available
#define BSP_FEATURE_QOS_ACEU1_UNIT_AVAILABLE                                  (0U)                                                                          ///< QoS feature for ACU1 is not available
#define BSP_FEATURE_QOS_RHSIF0_UNIT_AVAILABLE                                 (1U)                                                                          ///< QoS feature for RHSIF0 is available
#define BSP_FEATURE_QOS_RHSIF1_UNIT_AVAILABLE                                 (0U)                                                                          ///< QoS feature for RHSIF1 is not available
#define BSP_FEATURE_QOS_ETHER0_UNIT_AVAILABLE                                 (1U)                                                                          ///< QoS feature for ETHER0 is available
#define BSP_FEATURE_QOS_ETHER1_UNIT_AVAILABLE                                 (0U)                                                                          ///< QoS feature for ETHER1 is not available
#define BSP_FEATURE_QOS_R_SWITCH_UNIT_AVAILABLE                               (0U)                                                                          ///< QoS feature for R_SWITCH is not available

/** OSTM */
#define BSP_FEATURE_OSTM_VALID_CHANNEL_MASK                                   (0x0FU) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< Mask of available OSTM channels

/** LTSC */
#define BSP_FEATURE_LTSC_CLOCK_SOURCE                                         (FSP_PRIV_CLOCK_CLKC_HSB) /* PRQA S 1534 # Advisory R-2.5 */                  ///< LTSC uses CLKC_HSB clock as the clock source.

/** ADC */
#define BSP_FEATURE_ADC_VALID_UNIT_MASK                                       (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ADC valid unit mask (units 0 and 1)

/** GUARD */
#define BSP_FEATURE_PEGCAP_M_IS_AVAILABLE                                     (0x01U)                                                                       ///< PEGCAP_M guard availability
#define BSP_FEATURE_PE1_GUARD_IS_AVAILABLE                                    (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PE1 guard enable
#define BSP_FEATURE_PE2_GUARD_IS_AVAILABLE                                    (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PE2 guard enable
#define BSP_FEATURE_PE3_GUARD_IS_AVAILABLE                                    (1U)                                                                          ///< PE3 guard enable
#define BSP_FEATURE_CRAM0_GUARD_IS_AVAILABLE                                  (1U)                                                                          ///< CRAM0 guard enable
#define BSP_FEATURE_CRAM1_GUARD_IS_AVAILABLE                                  (1U)                                                                          ///< CRAM1 guard enable
#define BSP_FEATURE_CRAM_GUARD_STATUS_MAX                                     (8U)                                                                          ///< Maximum CRAM guard region count
#define BSP_FEATURE_PE_GUARD_STATUS_MAX                                       (5U)                                                                          ///< Maximum PE guard region count
#define BSP_FEATURE_IPIR_GUARD_IS_AVAILABLE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IPIR guard availability
#define BSP_FEATURE_BARR_GUARD_IS_AVAILABLE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Barrier guard availability
#define BSP_FEATURE_TPTMn_GUARD_MAX_CHANNEL                                   (4U)                                                                          ///< Max TPTMn guard channels
#define BSP_FEATURE_INTC2_GUARD_MAX_CHANNEL                                   (1023U)                                                                       ///< Max INTC2 guard channels
#define BSP_FEATURE_INTC2_GUARD_MIN_CHANNEL                                   (32U)                                                                         ///< Min INTC2 guard channel index
#define BSP_FEATURE_DTS_GUARD_MAX_CHANNEL                                     (128U)                                                                        ///< Max DTS guard channels
#define BSP_FEATURE_DMAC_GUARD_MAX_CHANNEL                                    (16U)                                                                         ///< Max DMAC guard channels

/** DMAC */
#define BSP_FEATURE_DMAC_MAX_CHANNEL                                          (16U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Maximum DMAC channels
#define BSP_FEATURE_DMAC_MAX_UNIT                                             (2U)                                                                          ///< Maximum DMAC units

/** DTS */
#define BSP_FEATURE_DTS_MAX_CHANNEL                                           (128U) /* PRQA S 1534 # Advisory R-2.5 */                                     ///< Maximum DTS channels

/** MSPI */
#define BSP_FEATURE_MSPI_MAX_NUMBER_CHIP_SELECT                               (12U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Maximum chip selects per MSPI unit
#define BSP_FEATURE_MSPI_TRIG_TPTM_NUMBER_UNIT                                (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of TPTM units usable as an MSPI hardware trigger source
#define BSP_FEATURE_MSPI_DMA_ALT_SPECIAL_MAPPING_SUPPORT                      (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Special DMA ALT mapping is not supported
#define BSP_FEATURE_MSPI_DTS_ALT_SPECIAL_MAPPING_SUPPORT                      (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Special DTS ALT mapping is supported
#define BSP_FEATURE_MSPI_MAX_UNIT                                             (10U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of MSPI units
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_0                            (12U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Chip selects for MSPI unit 0
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_1                            (12U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Chip selects for MSPI unit 1
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_2                            (12U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Chip selects for MSPI unit 2
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_3                            (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Chip selects for MSPI unit 3
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_4                            (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Chip selects for MSPI unit 4
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_5                            (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Chip selects for MSPI unit 5
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_6                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Chip selects for MSPI unit 6
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_7                            (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Chip selects for MSPI unit 7
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_8                            (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Chip selects for MSPI unit 8
#define BSP_FEATURE_MSPI_NUMBER_CHIP_SELECT_UNIT_9                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Chip selects for MSPI unit 9

#define BSP_FEATURE_ATU_GTM_SEL                                               (BSP_OPBT_SETTING_OPBT8 & (1 << 24)) /* PRQA S 1534 # Advisory R-2.5 */       ///< ATU->GTM trigger select bit

#define BSP_FEATURE_MSPI_ALT_DMA_UNIT                                         (0xCCCU) /* PRQA S 1534 # Advisory R-2.5 */                                   ///< ALT-DMA unit mapping bitmask
#define BSP_FEATURE_MSPI_ALT_DTS_UNIT                                         (0xF00U) /* PRQA S 1534 # Advisory R-2.5 */                                   ///< ALT-DTS unit mapping bitmask
#define BSP_FEATURE_MSPI_ALT_DMA_MAX_UNIT                                     (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Max MSPI units supporting ALT DMA
#define BSP_FEATURE_MSPI_ALT_DTS_MAX_UNIT                                     (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Max MSPI units supporting ALT DTS
#define BSP_FEATURE_MSPI_ALT_GAP_CHANNEL                                      (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Gap between ALT channel groups
#define BSP_FEATURE_MSPI_ALT_GAP_UNIT                                         (6U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Gap between ALT-enabled MSPI units
#define BSP_FEATURE_MSPI_ALT_PAIR_CHANNEL                                     (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ALT channel pairing size
#define BSP_FEATURE_MSPI_ALT_MAX_CHANNEL                                      (11U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Maximum ALT-enabled channel index
#define BSP_FEATURE_MSPI_ALT_DMA_MAX_BIT                                      (17U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Highest ALT DMA register bit used
#define BSP_FEATURE_MSPI_ALT_DTS_MAX_BIT                                      (9U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Highest ALT DTS register bit used

#define BSP_FEATURE_DTSAS06                                                   (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ALT DMA unit2 channel3 mapping bit position
#define BSP_FEATURE_DTSAS07                                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ALT DMA unit2 channel1 mapping bit position

/** ENCA */
#define BSP_FEATURE_ENCA_MAX_CHANNEL                                          (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Maximum ENCA channels supported

/** TSG3 */
#define BSP_FEATURE_TSG3_MAX_UNIT                                             (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Maximum TSG3 units
#define BSP_FEATURE_TSG3_COMPARE_MATCH_INTERRUPT_SKIPPING_FUNCTION_SUPPORT    (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Compare-match interrupt skip supported
#define BSP_FEATURE_TSG3_OUTPUT_INACTIVE_FUNCTION_SUPPORT                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Inactive-output function supported
#define BSP_FEATURE_TSG3_OUTPUT_CONTROL_BY_INTPUT_TERMINAL_SUPPORT            (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< No input-terminal output control support
#define BSP_FEATURE_TSG3_EMU3S_IS_AVAILABLE                                   (0U)                                                                          ///< EMU3S not available for TSG3

/** FREERTOS Port */
#define BSP_FEATURE_FREERTOS_PORT_OSTM0_EIC_ADDRESS                           (0xFFF802D0) /* PRQA S 1534 # Advisory R-2.5 */                               ///< OSTM0 EI level interrupt control register address
#define BSP_FEATURE_FREERTOS_PORT_OSTM0_CMP_ADDRESS                           (0xFFBF0000) /* PRQA S 1534 # Advisory R-2.5 */                               ///< OSTM0 compare register address
#define BSP_FEATURE_FREERTOS_PORT_OSTM0_CTL_ADDRESS                           (0xFFBF0020) /* PRQA S 1534 # Advisory R-2.5 */                               ///< OSTM0 control register address
#define BSP_FEATURE_FREERTOS_PORT_OSTM0_TS_ADDRESS                            (0xFFBF0014) /* PRQA S 1534 # Advisory R-2.5 */                               ///< OSTM0 count start trigger register address

/** TAUD */
#define BSP_FEATURE_TAUD_MAX_UNIT                                             (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Maximum TAUD units

/** CANFD */
#define BSP_FEATURE_CANFD_NUM_UNIT                                            (1UL) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of CANFD units
#define BSP_FEATURE_CANFD_NUM_CHANNELS                                        (8UL) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of CANFD channels
#define BSP_FEATURE_CANFD_NUM_CHANNELS_UNIT0                                  (8UL) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of CAN FD Channels in Unit 0
#define BSP_FEATURE_CANFD_NUM_CFIFO_CHANNEL                                   (3UL) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of CFIFO channels
#define BSP_FEATURE_CANFD_NUM_RXFIFO                                          (8UL) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of CANFD RX FIFOs
#define BSP_FEATURE_CANFD_NUM_CFIFO_PER_UNIT                                  (24UL) /* PRQA S 1534 # Advisory R-2.5 */                                     ///< Total CFIFO entries per unit
#define BSP_FEATURE_CANFD_NUM_TXQUEUE_CHANNEL                                 (4UL) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of TX queue channels
#define BSP_FEATURE_CANFD_NUM_RX_FIFO_FFI_VM                                  (8UL) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of RX FIFO for FFI/VM
#define BSP_FEATURE_CANFD_TXMB_SUPPORTED_SLOT                                 (0x0000FFFF0000FFFFULL) /* PRQA S 1534 # Advisory R-2.5 */                    ///< Supported TXMB slots (0-15, 32-47)
#define BSP_FEATURE_CANFD_CLKC_SRC                                            (FSP_PRIV_CLOCK_CLK_CANFD_C) /* PRQA S 1534 # Advisory R-2.5 */               ///< CANFD CLKC source
#define BSP_FEATURE_CANFD_PN_MODE                                             (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Pretended Network Mode supported
#define BSP_FEATURE_CANFD_FFI_MODE                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< FFI Mode supported
#define BSP_FEATURE_CANFD_AFLMRAM_MAX_PAGE                                    (305UL) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< Number of AFL MRAM page
#define BSP_FEATURE_CANFD_AFLMRAM_PER_CHANNEL                                 (9760UL) /* PRQA S 1534 # Advisory R-2.5 */                                   ///< Number of AFL MRAM area size
#define BSP_FEATURE_CANFD_PFLRAM_MAX_PAGE                                     (22UL) /* PRQA S 1534 # Advisory R-2.5 */                                     ///< Number of PFL page
#define BSP_FEATURE_CANFD_PFLRAM_PER_CHANNEL                                  (720UL) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< Number of PFL MRAM area size

/** RIIC */
#define BSP_FEATURE_IIC_HAS_SYS_CLK                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IIC system-clock support unavailable
#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK                                    (0x03U) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< Valid RIIC channels bitmask

/** INTSEL */
#define BSP_FEATURE_DEVICE_HAS_INTSEL_IRQ                                     (1U)                                                                          ///< INTSEL IRQ selection supported

/** INT MASK */
#define BSP_FEATURE_DEVICE_HAS_ORED_IRQ                                       (0U)                                                                          ///< ORed IRQ support is not available

/** RSENT */
#define BSP_FEATURE_RSENT_SENT_NUM_OF_UNIT                                    (30U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of RSENT units
#define BSP_FEATURE_RSENT_SENT_SPCO_SUPPORT                                   (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< RSENT SPCO select function is not supported
#define BSP_FEATURE_RSENT_SENT_UNIT_THRESHOLD                                 (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< RSENT unit index threshold between MSSEL register groups
#define BSP_FEATURE_RSENT_SENT_RSENT_SENT_MSSEL_BITS                          (5U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of bits per unit in the RSENT MSSEL register
#define BSP_FEATURE_RSENT_SENT_HAS_EXTENDED_TSSEL                             (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< RSENT has extended TSSEL2-TSSEL7 registers

/** RLIN3 */
#define BSP_FEATURE_RLIN3_RLIN323_HAS_PBUS_GROUP_8L                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< RLIN323 channel is on PBUS group 8L

/** MSPI */
#define BSP_FEATURE_MSPI_RAM_WORDS_MAX                                        (512U) /* PRQA S 1534 # Advisory R-2.5 */                                     ///< MSPI RAM size

/** TAUD3P */
#define BSP_FEATURE_TAUD_THREE_PHASE_NUMBER_OF_UNIT                           (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD three-phase control units

/** PIC */
#define BSP_FEATURE_PIC_ADC_NUMBER_UNIT                                       (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of PIC ADC units
#define BSP_FEATURE_PIC_ADC_NUMBER_SG                                         (6U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of ADC scan groups
#define BSP_FEATURE_PIC_TAUDTINSEL_NUMBER                                     (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of TAUDTINSEL signals
#define BSP_FEATURE_PIC20_TAUD_NUMBER_UNIT                                    (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD units in PIC20
#define BSP_FEATURE_PIC21_TAUD_NUMBER_UNIT                                    (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD units in PIC21
#define BSP_FEATURE_PIC_TSG3_NUMBER_UNIT                                      (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TSG3 units in PIC
#define BSP_FEATURE_PIC_ADTCFG_NUMBER                                         (10U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< ADTCFG count

#define BSP_FEATURE_PIC_DSADTCFG_NUMBER                                       (14U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< DSADTCFG entries
#define BSP_FEATURE_PIC_DSADTCFG_NUMBER_REG                                   (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< DSADTCFG register
#define BSP_FEATURE_PIC_DFETSEN_NUMBER                                        (22U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< DFETSEN entries
#define BSP_FEATURE_PIC_FCMPISEN_NUMBER_REG                                   (8U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< FCMPISEN registers
#define BSP_FEATURE_PIC_GTMSEN_NUMBER_REG                                     (8U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTMSEN registers
#define BSP_FEATURE_PIC_PSI5S_NUMBER_UNIT                                     (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5S units
#define BSP_FEATURE_PIC_PSI5SEN_NUMBER                                        (7U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5SEN entries
#define BSP_FEATURE_PIC_PSI5EN_NUMBER                                         (6U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5EN entries
#define BSP_FEATURE_PIC_PSI5EN_NUMBER_UNIT                                    (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5EN units
#define BSP_FEATURE_PIC_GTMINEN_NUMBER_GROUP                                  (7U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTMINEN groups
#define BSP_FEATURE_PIC_CANIOSEN_NUMBER                                       (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CANIOSEN entries
#define BSP_FEATURE_PIC_GTMINTIOEN_NUMBER_GROUP                               (8U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTM INTIO enable groups
#define BSP_FEATURE_PIC_GTMMSPI_NUMBER                                        (10U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< GTM MSPI link entries
#define BSP_FEATURE_PIC_ABFGODSEN_NUMBER                                      (14U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< ABFGODSEN entries

/** FLXA */
#define BSP_FEATURE_FLXA_MAX_UNIT                                             (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Maximum FLXA units supported

/** ETHTSN */
#define BSP_FEATURE_ETH_TSN_NUM_CHANNELS                                      (1UL) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< TSN total controller configuration (single)

/** CRC */
#define BSP_FEATURE_CRC_COMMON_GROUP                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CRC common group supported

/** IOPORT */
#define BSP_FEATURE_IOPORT_NF_RLIN30                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RLIN30 signal
#define BSP_FEATURE_IOPORT_NF_RLIN31                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RLIN31 signal
#define BSP_FEATURE_IOPORT_NF_RSCAN                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSCAN signal
#define BSP_FEATURE_IOPORT_NF_FLXA0                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter FLXA0 signal
#define BSP_FEATURE_IOPORT_NF_FLXA1                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter FLXA1 signal
#define BSP_FEATURE_IOPORT_NF_RSENT0                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT0 signal
#define BSP_FEATURE_IOPORT_NF_RSENT1                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT1 signal
#define BSP_FEATURE_IOPORT_NF_RSENT2                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT2 signal
#define BSP_FEATURE_IOPORT_NF_RSENT3                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT3 signal
#define BSP_FEATURE_IOPORT_NF_RSENT4                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT4 signal
#define BSP_FEATURE_IOPORT_NF_RSENT5                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT5 signal
#define BSP_FEATURE_IOPORT_NF_RSENT6                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT6 signal
#define BSP_FEATURE_IOPORT_NF_RSENT7                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT7 signal
#define BSP_FEATURE_IOPORT_NF_RSENT8                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT8 signal
#define BSP_FEATURE_IOPORT_NF_RSENT9                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT9 signal
#define BSP_FEATURE_IOPORT_NF_RSENT10                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT10 signal
#define BSP_FEATURE_IOPORT_NF_RSENT11                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT11 signal
#define BSP_FEATURE_IOPORT_NF_RSENT12                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT12 signal
#define BSP_FEATURE_IOPORT_NF_RSENT13                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT13 signal
#define BSP_FEATURE_IOPORT_NF_RSENT14                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT14 signal
#define BSP_FEATURE_IOPORT_NF_RSENT15                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT15 signal
#define BSP_FEATURE_IOPORT_NF_RSENT16                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT16 signal
#define BSP_FEATURE_IOPORT_NF_RSENT17                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT17 signal
#define BSP_FEATURE_IOPORT_NF_RSENT18                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT18 signal
#define BSP_FEATURE_IOPORT_NF_RSENT19                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT19 signal
#define BSP_FEATURE_IOPORT_NF_RSENT20                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT20 signal
#define BSP_FEATURE_IOPORT_NF_RSENT21                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT21 signal
#define BSP_FEATURE_IOPORT_NF_RSENT22                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT22 signal
#define BSP_FEATURE_IOPORT_NF_RSENT23                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT23 signal
#define BSP_FEATURE_IOPORT_NF_RSENT24                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT24 signal
#define BSP_FEATURE_IOPORT_NF_RSENT25                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT25 signal
#define BSP_FEATURE_IOPORT_NF_RSENT26                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT26 signal
#define BSP_FEATURE_IOPORT_NF_RSENT27                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT27 signal
#define BSP_FEATURE_IOPORT_NF_RSENT28                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT28 signal
#define BSP_FEATURE_IOPORT_NF_RSENT29                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RSENT29 signal
#define BSP_FEATURE_IOPORT_NF_PSI50                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PSI50 signal
#define BSP_FEATURE_IOPORT_NF_PSI51                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PSI51 signal
#define BSP_FEATURE_IOPORT_NF_PSI52                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PSI52 signal
#define BSP_FEATURE_IOPORT_NF_PSI53                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PSI53 signal
#define BSP_FEATURE_IOPORT_NF_PIC_TAPA0                                       (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PIC_TAPA0 signal
#define BSP_FEATURE_IOPORT_NF_PIC_TAPA1                                       (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PIC_TAPA1 signal
#define BSP_FEATURE_IOPORT_NF_PIC_TAPA2                                       (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PIC_TAPA2 signal
#define BSP_FEATURE_IOPORT_NF_PIC_TAPA3                                       (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PIC_TAPA3 signal
#define BSP_FEATURE_IOPORT_NF_PIC_TAPA4                                       (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PIC_TAPA4 signal
#define BSP_FEATURE_IOPORT_NF_PIC_TAPA5                                       (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PIC_TAPA5 signal
#define BSP_FEATURE_IOPORT_NF_ADCJ0                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ADCJ0 signal
#define BSP_FEATURE_IOPORT_NF_ADCJ1                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ADCJ1 signal
#define BSP_FEATURE_IOPORT_NF_ADCJ2                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ADCJ2 signal
#define BSP_FEATURE_IOPORT_NF_ADCK0                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ADCK0 signal
#define BSP_FEATURE_IOPORT_NF_ADCK1                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ADCK1 signal
#define BSP_FEATURE_IOPORT_NF_ADCK2                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ADCK2 signal
#define BSP_FEATURE_IOPORT_NF_ADCK3                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ADCK3 signal
#define BSP_FEATURE_IOPORT_NF_ADCKA                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ADCKA signal
#define BSP_FEATURE_IOPORT_NF_RHSB0                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RHSB0 signal
#define BSP_FEATURE_IOPORT_NF_RHSB1                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RHSB1 signal
#define BSP_FEATURE_IOPORT_NF_RHSB2                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RHSB2 signal
#define BSP_FEATURE_IOPORT_NF_RHSB3                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter RHSB3 signal
#define BSP_FEATURE_IOPORT_NF_ENCA0                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ENCA0 signal
#define BSP_FEATURE_IOPORT_NF_ENCA1                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ENCA1 signal
#define BSP_FEATURE_IOPORT_NF_TAUD0                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TAUD0 signal
#define BSP_FEATURE_IOPORT_NF_TAUD1                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TAUD1 signal
#define BSP_FEATURE_IOPORT_NF_TAUD2                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TAUD2 signal
#define BSP_FEATURE_IOPORT_NF_TAUD3                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TAUD3 signal
#define BSP_FEATURE_IOPORT_NF_TSG30                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TSG30 signal
#define BSP_FEATURE_IOPORT_NF_TSG31                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TSG31 signal
#define BSP_FEATURE_IOPORT_NF_TSG32                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TSG32 signal
#define BSP_FEATURE_IOPORT_NF_IRQ0                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ0 signal
#define BSP_FEATURE_IOPORT_NF_IRQ1                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ1 signal
#define BSP_FEATURE_IOPORT_NF_IRQ2                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ2 signal
#define BSP_FEATURE_IOPORT_NF_IRQ3                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ3 signal
#define BSP_FEATURE_IOPORT_NF_IRQ4                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ4 signal
#define BSP_FEATURE_IOPORT_NF_IRQ5                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ5 signal
#define BSP_FEATURE_IOPORT_NF_IRQ6                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ6 signal
#define BSP_FEATURE_IOPORT_NF_IRQ7                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ7 signal
#define BSP_FEATURE_IOPORT_NF_IRQ8                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ8 signal
#define BSP_FEATURE_IOPORT_NF_IRQ9                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ9 signal
#define BSP_FEATURE_IOPORT_NF_IRQ10                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ10 signal
#define BSP_FEATURE_IOPORT_NF_IRQ11                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ11 signal
#define BSP_FEATURE_IOPORT_NF_IRQ12                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ12 signal
#define BSP_FEATURE_IOPORT_NF_IRQ13                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ13 signal
#define BSP_FEATURE_IOPORT_NF_IRQ14                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ14 signal
#define BSP_FEATURE_IOPORT_NF_IRQ15                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ15 signal
#define BSP_FEATURE_IOPORT_NF_IRQ16                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ16 signal
#define BSP_FEATURE_IOPORT_NF_IRQ17                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ17 signal
#define BSP_FEATURE_IOPORT_NF_IRQ18                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ18 signal
#define BSP_FEATURE_IOPORT_NF_IRQ19                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ19 signal
#define BSP_FEATURE_IOPORT_NF_IRQ20                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ20 signal
#define BSP_FEATURE_IOPORT_NF_IRQ21                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ21 signal
#define BSP_FEATURE_IOPORT_NF_IRQ22                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ22 signal
#define BSP_FEATURE_IOPORT_NF_IRQ23                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ23 signal
#define BSP_FEATURE_IOPORT_NF_IRQ24                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ24 signal
#define BSP_FEATURE_IOPORT_NF_IRQ25                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ25 signal
#define BSP_FEATURE_IOPORT_NF_IRQ26                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ26 signal
#define BSP_FEATURE_IOPORT_NF_IRQ27                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ27 signal
#define BSP_FEATURE_IOPORT_NF_IRQ28                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ28 signal
#define BSP_FEATURE_IOPORT_NF_IRQ29                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ29 signal
#define BSP_FEATURE_IOPORT_NF_IRQ30                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ30 signal
#define BSP_FEATURE_IOPORT_NF_IRQ31                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ31 signal
#define BSP_FEATURE_IOPORT_NF_IRQ32                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ32 signal
#define BSP_FEATURE_IOPORT_NF_IRQ33                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ33 signal
#define BSP_FEATURE_IOPORT_NF_IRQ34                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ34 signal
#define BSP_FEATURE_IOPORT_NF_IRQ35                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ35 signal
#define BSP_FEATURE_IOPORT_NF_IRQ36                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ36 signal
#define BSP_FEATURE_IOPORT_NF_IRQ37                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ37 signal
#define BSP_FEATURE_IOPORT_NF_IRQ38                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ38 signal
#define BSP_FEATURE_IOPORT_NF_IRQ39                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ39 signal
#define BSP_FEATURE_IOPORT_NF_IRQ_NMI                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ_NMI signal
#define BSP_FEATURE_IOPORT_NF_IRQ40                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ40 signal
#define BSP_FEATURE_IOPORT_NF_IRQ41                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ41 signal
#define BSP_FEATURE_IOPORT_NF_IRQ42                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ42 signal
#define BSP_FEATURE_IOPORT_NF_IRQ43                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ43 signal
#define BSP_FEATURE_IOPORT_NF_IRQ44                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ44 signal
#define BSP_FEATURE_IOPORT_NF_IRQ45                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ45 signal
#define BSP_FEATURE_IOPORT_NF_IRQ_ESR                                         (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter IRQ_ESR signal
#define BSP_FEATURE_IOPORT_NF_INTP_NMI                                        (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP_NMI signal
#define BSP_FEATURE_IOPORT_NF_INTP0                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP0 signal
#define BSP_FEATURE_IOPORT_NF_INTP1                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP1 signal
#define BSP_FEATURE_IOPORT_NF_INTP2                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP2 signal
#define BSP_FEATURE_IOPORT_NF_INTP3                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP3 signal
#define BSP_FEATURE_IOPORT_NF_INTP4                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP4 signal
#define BSP_FEATURE_IOPORT_NF_INTP5                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP5 signal
#define BSP_FEATURE_IOPORT_NF_INTP6                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP6 signal
#define BSP_FEATURE_IOPORT_NF_INTP7                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP7 signal
#define BSP_FEATURE_IOPORT_NF_INTP8                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP8 signal
#define BSP_FEATURE_IOPORT_NF_INTP9                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP9 signal
#define BSP_FEATURE_IOPORT_NF_INTP10                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP10 signal
#define BSP_FEATURE_IOPORT_NF_INTP11                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP11 signal
#define BSP_FEATURE_IOPORT_NF_INTP12                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP12 signal
#define BSP_FEATURE_IOPORT_NF_INTP13                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP13 signal
#define BSP_FEATURE_IOPORT_NF_INTP14                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP14 signal
#define BSP_FEATURE_IOPORT_NF_INTP15                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP15 signal
#define BSP_FEATURE_IOPORT_NF_INTP16                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP16 signal
#define BSP_FEATURE_IOPORT_NF_INTP17                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP17 signal
#define BSP_FEATURE_IOPORT_NF_INTP18                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP18 signal
#define BSP_FEATURE_IOPORT_NF_INTP19                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP19 signal
#define BSP_FEATURE_IOPORT_NF_INTP20                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP20 signal
#define BSP_FEATURE_IOPORT_NF_INTP21                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP21 signal
#define BSP_FEATURE_IOPORT_NF_INTP22                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP22 signal
#define BSP_FEATURE_IOPORT_NF_INTP23                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP23 signal
#define BSP_FEATURE_IOPORT_NF_INTP24                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP24 signal
#define BSP_FEATURE_IOPORT_NF_INTP25                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP25 signal
#define BSP_FEATURE_IOPORT_NF_INTP26                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP26 signal
#define BSP_FEATURE_IOPORT_NF_INTP27                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP27 signal
#define BSP_FEATURE_IOPORT_NF_INTP28                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP28 signal
#define BSP_FEATURE_IOPORT_NF_INTP29                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP29 signal
#define BSP_FEATURE_IOPORT_NF_INTP30                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP30 signal
#define BSP_FEATURE_IOPORT_NF_INTP31                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP31 signal
#define BSP_FEATURE_IOPORT_NF_INTP32                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP32 signal
#define BSP_FEATURE_IOPORT_NF_INTP33                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP33 signal
#define BSP_FEATURE_IOPORT_NF_INTP34                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP34 signal
#define BSP_FEATURE_IOPORT_NF_INTP35                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP35 signal
#define BSP_FEATURE_IOPORT_NF_INTP36                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP36 signal
#define BSP_FEATURE_IOPORT_NF_INTP37                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP37 signal
#define BSP_FEATURE_IOPORT_NF_INTP38                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP38 signal
#define BSP_FEATURE_IOPORT_NF_INTP39                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter INTP39 signal
#define BSP_FEATURE_IOPORT_NF_ECM0                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ECM0 signal
#define BSP_FEATURE_IOPORT_NF_ECM1                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ECM1 signal
#define BSP_FEATURE_IOPORT_NF_ECM2                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ECM2 signal
#define BSP_FEATURE_IOPORT_NF_ECM3                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ECM3 signal
#define BSP_FEATURE_IOPORT_NF_ECM4                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ECM4 signal
#define BSP_FEATURE_IOPORT_NF_ECM5                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ECM5 signal
#define BSP_FEATURE_IOPORT_NF_ECM6                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ECM6 signal
#define BSP_FEATURE_IOPORT_NF_ECM7                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter ECM7 signal
#define BSP_FEATURE_IOPORT_NF_TAUJ0                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TAUJ0 signal
#define BSP_FEATURE_IOPORT_NF_TAUJ1                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TAUJ1 signal
#define BSP_FEATURE_IOPORT_NF_TAUJ2                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TAUJ2 signal
#define BSP_FEATURE_IOPORT_NF_TAUJ3                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter TAUJ3 signal
#define BSP_FEATURE_IOPORT_NF_PIC_TSG                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter PIC_TSG signal
#define BSP_FEATURE_IOPORT_NF_EMU0                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter EMU0 signal
#define BSP_FEATURE_IOPORT_NF_EMU1                                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter EMU1 signal
#define BSP_FEATURE_IOPORT_NF_SSIF                                            (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter SSIF signal
#define BSP_FEATURE_IOPORT_NF_OSPI0                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT Noise filter OSPI0 signal

#define BSP_FEATURE_IOPORT_LVDSA                                              (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT enable/disable LVDS feature (0U): Disable/ (1U): Enable
#define BSP_FEATURE_IOPORT_LVDSB                                              (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT enable/disable LVDS feature (0U): Disable/ (1U): Enable
#define BSP_FEATURE_IOPORT_LVDSC                                              (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT enable/disable LVDS feature (0U): Disable/ (1U): Enable
#define BSP_FEATURE_IOPORT_LVDSD                                              (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT enable/disable LVDS feature (0U): Disable/ (1U): Enable
#define BSP_FEATURE_IOPORT_LVDSE                                              (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT enable/disable LVDS feature (0U): Disable/ (1U): Enable
#define BSP_FEATURE_IOPORT_LVDSF                                              (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT enable/disable LVDS feature (0U): Disable/ (1U): Enable
#define BSP_FEATURE_IOPORT_LVDS_CTRLA_CONFIGURATION                           (0x00090000) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLA configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLB_CONFIGURATION                           (0x00090000) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLB configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLC_CONFIGURATION                           (0x00030000) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLC configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLD_CONFIGURATION                           (0x00010000) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLD configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLE_CONFIGURATION                           (0x00090000) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLE configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLF_CONFIGURATION                           (0x00100000) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLF configuration mask register

#define BSP_FEATURE_IOPORT_LVDS_CTRLA_ENABLE                                  (0x00090009) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLA enable and configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLB_ENABLE                                  (0x00090039) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLB enable and configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLC_ENABLE                                  (0x0003001B) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLC enable and configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLD_ENABLE                                  (0x0001000B) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLD enable and configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLE_ENABLE                                  (0x00090009) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLE enable and configuration mask register
#define BSP_FEATURE_IOPORT_LVDS_CTRLF_ENABLE                                  (0x00100038) /* PRQA S 1534 # Advisory R-2.5 */                               ///< IOPORT LVDSCTRLF enable and configuration mask register

#define BSP_FEATURE_IOPORT_PST                                                (7U)                                                                          ///< Number of ECM error trigger
#define BSP_FEATURE_IOPORT_PEIODC                                             (1U)                                                                          ///< IOPORT enable/disable ERRORIN Open-drain feature (0U): Disable/ (1U): Enable
#define BSP_FEATURE_IOPORT_PULVSEL5                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< IOPORT enable/disable PULVSEL5 feature (0U): Disable/ (1U): Enable

/** HRPWM */
#define BSP_FEATURE_HRPWM_VALID_CHANNEL_MASK                                  (0x1U) /* PRQA S 1534 # Advisory R-2.5 */                                     ///< Valid HRPWM channel mask

/** PIC - advanced signals */
#define BSP_FEATURE_PIC_TAUD_INT_SIGNAL_OUT_NUMBER                            (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD interrupt outputs
#define BSP_FEATURE_PIC_TAUD_TRIANGLE_WAVE_NUMBER                             (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of triangle-wave generators
#define BSP_FEATURE_PIC_TAUD_PWM_OUTPUT_NUMBER                                (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD PWM output count
#define BSP_FEATURE_PIC_TAUD_DELAY_PULSE_NUMBER                               (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD delay pulse count
#define BSP_FEATURE_PIC_ENCA_FEATURE_NUMBER_UNIT                              (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCA-capable units

#define BSP_FEATURE_PIC_ADCK_TRIG_SEL                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ADCK trigger select supported
#define BSP_FEATURE_PIC_ADCK_TRIG_SEL_ATU                                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ADCK trigger via ATU supported
#define BSP_FEATURE_PIC_SWITCH_TSG_OUT                                        (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TSG output switch supported
#define BSP_FEATURE_PIC_SWITCH_TSG_OUT_TSG32                                  (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TSG32 output switch supported
#define BSP_FEATURE_PIC_EMU_FEATURE                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< EMU feature not supported on PIC
#define BSP_FEATURE_PIC_TSG_START_TRIG                                        (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TSG start trigger supported
#define BSP_FEATURE_PIC_TSG_START_TRIG_TSG32                                  (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TSG32 start trigger supported
#define BSP_FEATURE_PIC_3PHASE_ENCODER_TSG31                                  (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< 3-phase encoder on TSG31 supported
#define BSP_FEATURE_PIC_2PHASE_SEL_INTENCA1_TO_TSG3                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCA1 -> TSG3 2-phase input supported
#define BSP_FEATURE_PIC_ENC_CAPT_TRIG_ENCA1                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCA1 capture trigger supported
#define BSP_FEATURE_PIC_INT_SIG_OUT_TAUD1                                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD1 interrupt output supported
#define BSP_FEATURE_PIC_INT_SIG_OUT_TAUD2                                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD2 interrupt output supported
#define BSP_FEATURE_PIC_TRIG_PULSE_WIDTH_MEASURE_DT12                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Pulse-width measurement via DT12 supported
#define BSP_FEATURE_PIC_TRIG_PULSE_WIDTH_MEASURE_DT00                         (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< DT00 pulse-width measurement unsupported
#define BSP_FEATURE_PIC_TRIG_PULSE_WIDTH_MEASURE_DT10                         (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< DT10 pulse-width measurement unsupported
#define BSP_FEATURE_PIC_ENCA_INPUT_SEL                                        (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCA input selection supported
#define BSP_FEATURE_PIC_FCMP_FEATURE                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< FCMP feature supported
#define BSP_FEATURE_PIC_HRPWM_FEATURE                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< HRPWM feature supported
#define BSP_FEATURE_PIC_TIMER_INPUT_MONITOR                                   (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Timer input monitor not supported
#define BSP_FEATURE_PIC_TAUD_INPUT_SEL                                        (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD input selection supported
#define BSP_FEATURE_PIC_ENCA_TRIG_SEL                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCA trigger selection supported
#define BSP_FEATURE_PIC_ENCA_ENC_INPUT_SEL                                    (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCA encoder input selection supported
#define BSP_FEATURE_PIC_RDC_FEATURE                                           (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< RDC feature supported
#define BSP_FEATURE_PIC_CAN_GTM_IO_SHARE                                      (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CAN/GTM IO sharing supported
#define BSP_FEATURE_PIC_MSPI_TRIG_SEL                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< MSPI trigger selection supported
#define BSP_FEATURE_PIC_GTM_DTM_INPUT_SEL                                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTM DTM input selection supported
#define BSP_FEATURE_PIC_TSG3_INPUT_GTM                                        (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TSG3 GTM input unsupported
#define BSP_FEATURE_PIC_ADCK_TRIG_SEL_GTM_PIC24                               (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ADCK trigger via GTM PIC24 supported
#define BSP_FEATURE_PIC_ADCK_TRIG_SEL_GTM_PIC2_SELB                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ADCK trigger via GTM PIC2 SELB unsupported
#define BSP_FEATURE_PIC_TSG_SYNC_START_CLEAR_PIC13                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TSG sync/start via PIC13 supported
#define BSP_FEATURE_PIC_TSG_SYNC_START_CLEAR_PIC1_SELB                        (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TSG sync/start via PIC1 SELB unsupported
#define BSP_FEATURE_PIC_TIMER_IN_SEL_B_TAUD2                                  (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TIMER IN SEL B -> TAUD2 unsupported
#define BSP_FEATURE_PIC_TIMER_IN_SEL_B_TAUD_TAUJ                              (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TIMER IN SEL B -> TAUD/TAUJ unsupported
#define BSP_FEATURE_PIC_TIMER_IN_SEL_B                                        (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TIMER IN SEL B unsupported
#define BSP_FEATURE_PIC_TAUD_IN_SEL_PIC13                                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD input via PIC13 supported
#define BSP_FEATURE_PIC_TAUD_IN_SEL_PIC1_SELB                                 (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD input via PIC1 SELB unsupported
#define BSP_FEATURE_PIC_TIMER_OUT_MON_PIC13                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Timer output monitor PIC13 supported
#define BSP_FEATURE_PIC_TIMER_OUT_MON_PIC1_SELB                               (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Timer output monitor PIC1 SELB unsupported
#define BSP_FEATURE_PIC_ENCA_TRIG_SEL_ENCATSEL_PIC22                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCATSEL via PIC22 supported
#define BSP_FEATURE_PIC_ENCA_TRIG_SEL_ENCATCFG_PIC24                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCATCFG via PIC24 supported
#define BSP_FEATURE_PIC_ENCA_TRIG_SEL_ENCATSEL_PIC21                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCATSEL via PIC21 unsupported
#define BSP_FEATURE_PIC_ENCA_TRIG_SEL_ENCATCFG_PIC22                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCATCFG via PIC22 unsupported
#define BSP_FEATURE_PIC_DSADC_TRIG_SEL                                        (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< DSADC trigger select supported
#define BSP_FEATURE_PIC_DSADC_TRIG_SEL_ATU                                    (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< DSADC trigger via ATU supported
#define BSP_FEATURE_PIC_DSADC_READ_GATE                                       (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< DSADC read gate supported
#define BSP_FEATURE_PIC_CADC_TRIG_SEL                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CADC trigger select supported
#define BSP_FEATURE_PIC_CADC_TRIG_SEL_ATU                                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CADC trigger via ATU supported
#define BSP_FEATURE_PIC_DFE_TRIG_SEL                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< DFE input selection supported
#define BSP_FEATURE_PIC_PSI5_TRIG_SEL                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5 trigger selection supported
#define BSP_FEATURE_PIC_PSI5_TRIG_SEL_GTM_PIC24                               (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5 trigger via GTM PIC24 supported
#define BSP_FEATURE_PIC_PSI5_TRIG_SEL_GTM_PIC2_SELB                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5 trigger via GTM PIC2 SELB unsupported
#define BSP_FEATURE_PIC_PSI5S_TRIG_SEL_GTM_PIC24                              (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5S trigger via GTM PIC24 supported
#define BSP_FEATURE_PIC_PSI5S_TRIG_SEL_GTM_PIC2_SELB                          (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5S trigger via GTM PIC2 SELB unsupported
#define BSP_FEATURE_PIC_PSI5S_TRIG_SEL_GTM_PIC22                              (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5S trigger via GTM PIC22 unsupported
#define BSP_FEATURE_PIC_PSI5S_TRIG_SEL                                        (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PSI5S trigger selection supported
#define BSP_FEATURE_PIC_GTM_TIO_INPUT_SEL                                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTM TIO input selection supported
#define BSP_FEATURE_PIC_GTM_TIO_IN_PIC24                                      (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTM TIO input via PIC24 supported
#define BSP_FEATURE_PIC_GTM_TIO_IN_PIC2_SELB                                  (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTM TIO input via PIC2 SELB unsupported
#define BSP_FEATURE_PIC_GTM_TIO_IN_PIC22                                      (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTM TIO input via PIC22 unsupported
#define BSP_FEATURE_PIC_GTM_TIM_IN_PIC24                                      (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTM TIM input via PIC24 supported
#define BSP_FEATURE_PIC_GTM_TIM_IN_PIC2_SELB                                  (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTM TIM input via PIC2 SELB unsupported
#define BSP_FEATURE_PIC_GTM_TIM_IN_PIC22                                      (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< GTM TIM input via PIC22 unsupported
#define BSP_FEATURE_PIC_ENCA_ENC_INPUT_PIC24                                  (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCA encoder input via PIC24 supported
#define BSP_FEATURE_PIC_ENCA_ENC_INPUT_PIC22                                  (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ENCA encoder input via PIC22 unsupported
#define BSP_FEATURE_PIC_HIZ_CTRL_GTM_PIC24                                    (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Hi-Z control via GTM PIC24 supported
#define BSP_FEATURE_PIC_HIZ_CTRL_GTM_PIC2_SELB                                (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Hi-Z via GTM PIC2 SELB unsupported
#define BSP_FEATURE_PIC_HIZ_CTRL_GTM_PIC20                                    (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Hi-Z control via GTM PIC20 unsupported
#define BSP_FEATURE_PIC_RDC_FEATURE_RDC3AL                                    (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< RDC3AL feature supported
#define BSP_FEATURE_PIC_RDC_FEATURE_RDC3AS                                    (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< RDC3AS feature supported
#define BSP_FEATURE_PIC_CAN_GTM_IO_SHARE_PIC24                                (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CAN/GTM IO share via PIC24 supported
#define BSP_FEATURE_PIC_CAN_GTM_IO_SHARE_PIC2_SELB                            (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CAN/GTM IO share via PIC2 SELB unsupported
#define BSP_FEATURE_PIC_MSPI_TRIG_SEL_PIC24                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PIC24 MSPI trigger supported
#define BSP_FEATURE_PIC_MSPI_TRIG_SEL_PIC2_SELB                               (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PIC2 SELB MSPI trigger unsupported
#define BSP_FEATURE_PIC_TAUD_INPUT_SEL_PIC13                                  (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD input select via PIC13 supported
#define BSP_FEATURE_PIC_TAUD_INPUT_SEL_PIC1_SELB                              (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< TAUD input select via PIC1 SELB unsupported
#define BSP_FEATURE_PIC_ADCK_TRIG_SEL_PIC21                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< ADCK trigger select via PIC21
#define BSP_FEATURE_PIC_SST_PIC1_MULTI_UNIT                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Multi-unit SST on PIC1 supported
#define BSP_FEATURE_PIC_HIZ_CTRL_HIZCEN0                                      (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< HIZCEN0 supported
#define BSP_FEATURE_PIC_HIZ_CTRL_HIZCEN1                                      (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< HIZCEN1 supported
#define BSP_FEATURE_PIC_CAN_GTM_IO_SHARE_CAN_NUMBER                           (10U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of CAN/GTM IO share signals
#define BSP_FEATURE_PIC_MSPI_TRIG_SEL_SIGNAL_NUMBER                           (10U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of MSPI trigger signals supported
#define BSP_FEATURE_PIC_FEATURE_U2BX                                          (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< PIC U2Bx feature set supported

/** GTM */
#define BSP_FEATURE_GTM_VALID_CHANNEL_MASK                                    (0x1FU) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< Valid GTM channels bitmask

#define BSP_FEATURE_GTM_ARU_NUMBER_INSTANCE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM ARU instances
#define BSP_FEATURE_GTM_BRC_NUMBER_INSTANCE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM BRC instances
#define BSP_FEATURE_GTM_PSM_NUMBER_INSTANCE                                   (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM PSM instances
#define BSP_FEATURE_GTM_CMU_NUMBER_INSTANCE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM CMU instances
#define BSP_FEATURE_GTM_CCM_NUMBER_INSTANCE                                   (8U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM CCM instances
#define BSP_FEATURE_GTM_TBU_NUMBER_INSTANCE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM TBU instances
#define BSP_FEATURE_GTM_TIM_NUMBER_INSTANCE                                   (7U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM TIM instances
#define BSP_FEATURE_GTM_TOM_NUMBER_INSTANCE                                   (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM TOM instances
#define BSP_FEATURE_GTM_ATOM_NUMBER_INSTANCE                                  (8U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM ATOM instances
#define BSP_FEATURE_GTM_DTM_NUMBER_INSTANCE                                   (20U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of GTM DTM instances
#define BSP_FEATURE_GTM_MCS_NUMBER_INSTANCE                                   (7U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM MCS instances
#define BSP_FEATURE_GTM_MCFG_NUMBER_INSTANCE                                  (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM MCFG instances
#define BSP_FEATURE_GTM_MAP_NUMBER_INSTANCE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM MAP instances
#define BSP_FEATURE_GTM_DPLL_NUMBER_INSTANCE                                  (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM DPLL instances
#define BSP_FEATURE_GTM_SPE_NUMBER_INSTANCE                                   (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM SPE instances
#define BSP_FEATURE_GTM_ICM_NUMBER_INSTANCE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM ICM instances
#define BSP_FEATURE_GTM_CMP_NUMBER_INSTANCE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM CMP instances
#define BSP_FEATURE_GTM_MON_NUMBER_INSTANCE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM MON instances
#define BSP_FEATURE_GTM_TIO_NUMBER_INSTANCE                                   (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM TIO instances
#define BSP_FEATURE_GTM_INTSEL_SUPPORT                                        (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Interconnections of Interrupt Factors Support

/** GTM_MCS */
#define BSP_FEATURE_GTM_MCS_NUMBER_CHANNEL                                    (8U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM MCS channels per instance
#define BSP_FEATURE_GTM_MCS_NUMBER_TRIGGER                                    (24U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Number of GTM MCS trigger sources
#define BSP_FEATURE_GTM_MCS_NUMBER_SINT                                       (8U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM MCS SINT sources
#define BSP_FEATURE_GTM_MCS_NUMBER_HBP                                        (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of GTM MCS HBP units
#define BSP_FEATURE_GTM_MCS_SP_CNT_AVAILABLE                                  (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Stack Pointer Counter support
#define BSP_FEATURE_GTM_MCS_EXT_IRQ_AVAILABLE                                 (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< External Interrupt Selection support

/** TAUD */
#define BSP_FEATURE_TAUD_MAX_UNIT                                             (4U)                                                                          ///< Maximum TAUD units

/** CLMA */
#define BSP_FEATURE_CLMA_MAX_CHANNEL                                          (18U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< Maximum CLMA channels supported

/** VMON */
#define BSP_FEATURE_VMON_VDD2_AVAILABLE                                       (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Group index for VDD2 voltage monitoring
#define BSP_FEATURE_VMON_AWOVDD_AVAILABLE                                     (0U)                                                                          /* PRQA S 1534 # Advisory R-2.5 */
#define BSP_FEATURE_VMON_FC_ENABLE                                            (0xFCU) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< Bit positions for enabling VMON functionality
#define BSP_FEATURE_VMON_DMASK_ENABLE                                         (0xEEU) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< Enable/disable VMONDMASK functionality
#define BSP_FEATURE_VMON_OUT_DMASK_ENABLE                                     (0xE0U) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< Enable/disable VMON_OUT_DMASK functionality
#define BSP_FEATURE_VMON_RESET_DMASK_ENABLE                                   (0x0EU) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< Enable/disable VMON_RESET_DMASK functionality                                 ///< Group index for AWOVDD voltage monitoring

/** RLIN3 */
#define BSP_FEATURE_RLIN3_LIN_CHANNELS_MASK                                   (0x80003FUL) /* PRQA S 1534 # Advisory R-2.5 */                               ///< Bitmask of supported RLIN3 channels
#define BSP_FEATURE_RLIN3_LIN_NUM_OF_CHANNELS                                 (7U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of LIN channels supported

/** DMAC */
#define BSP_FEATURE_DMAC_SWITCHABLE_REDUNDANT_OPERATION                       (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< DMAC redundant operation supported

/** DTSC */
#define BSP_FEATURE_DTSC_TRANSFER_RQ_OVERFLOW_FLAG                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Transfer request overflow flag supported

/** ECM */
#define BSP_FEATURE_ECM_ERROR_SOURCE_CHECK_VALID                              (351U) /* PRQA S 1534 # Advisory R-2.5 */                                     ///< Maximum ECM error source index supported

/** ICU */
#define BSP_FEATURE_FCLA5_IS_AVAILABLE                                        (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< FCLA5 register availability (1 = available)
#define BSP_FEATURE_ICU_SIGNAL_INTP                                           (0U)                                                                          /* PRQA S 1534 # Advisory R-2.5 */

/** RHSIF */
#define BSP_FEATURE_RHSIF_UNIT_SUPPORTED                                      (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Maximum RHSIF channel supported

/** CLMA */
#define BSP_FEATURE_CLMA_BACKUP_CLOCK_IS_AVAILABLE                            (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Backup Clock support
#define BSP_FEATURE_CLMA_SSCG1_UNDIVIDED_REQUIRED                             (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< CLMA CKS_SSCG1C Requirement

/** ECM */
#define BSP_FEATURE_ECM_INSTANCE                                              (10U) /* PRQA S 1534 # Advisory R-2.5 */                                      ///< ECM feature instance

/** PSI5 */
#define BSP_FEATURE_PSI5_MAX_CHANNEL                                          (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Maximum PSI5 unit supported
#define BSP_FEATURE_PSI5_NUM_SLOTS_EACH_UNIT                                  (8U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Maximum PSI5 slot per unit supported
#define BSP_FEATURE_PSI5_WP_IS_AVAILABLE                                      (1U)                                                                          /* Indicates the wrapper function is available in PSI5 */ /* PRQA S 1534 # Advisory R-2.5 */

/** PSI5S */
#define BSP_FEATURE_PSI5S_NUM_UNIT                                            (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Maximum PSI5S unit supported

/** Motor Control Resolver */
#define BSP_FEATURE_MOTOR_CONTROL_RESOLVER_WITHOUT_EMU3S                      (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Motor Control Resolver without EMU3S is not available

/** CGC */
#define BSP_FEATURE_CGC_NUM_OF_SYSTEM_CLOCK                                   (3U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of CPU system clock domains supported
#define BSP_FEATURE_CGC_HAS_CLK_SYS                                           (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< System clock CLK_SYS is not available
#define BSP_FEATURE_CGC_HAS_CLK_SYS_CLEAN                                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< System clock CLK_SYS_CLEAN is available
#define BSP_FEATURE_CGC_HAS_CLK_SYS_SSCG                                      (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< System clock CLK_SYS_SSCG is available
#define BSP_FEATURE_CGC_HAS_CLK_SYS_SSCG1                                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< System clock CLK_SYS_SSCG1 is available
#define BSP_FEATURE_CGC_EXTENDED_PERIPHERAL_CLK_SELECTORS                     (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Peripheral input clock source selectors
#define BSP_FEATURE_CGC_SUB_OSC_IS_AVAILABLE                                  (0U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Sub Oscillator is not available
#define BSP_FEATURE_CGC_HVIOSC_IS_AVAILABLE                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< High Voltage Internal Oscillator is available
#define BSP_FEATURE_CGC_NUM_OF_GEAR_SHIFT_REPETITION_CASE                     (2U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Number of repetition cases for System Clock gear up/down shifting

/** ADCK */
#if (BSP_PACKAGE_PINS_BGA292 == BSP_PACKAGE_PINS)
 #define BSP_FEATURE_ADCK_NUM_OF_UNIT                                         (3U)                                                                          /* ADCK support on this MCU */
#else
 #define BSP_FEATURE_ADCK_NUM_OF_UNIT                                         (4U)                                                                          /* ADCK support on this MCU */ /* PRQA S 1534 # Advisory R-2.5 */
#endif

/** ECM ERRORIN NF */
#define BSP_FEATURE_ECM_ERRORIN_NF_MAX                                        IOPORT_FILTER_SIGNAL_ERRORIN7 /* PRQA S 1534 # Advisory R-2.5 */              ///< ECM ERRORIN NF Max
#define BSP_FEATURE_ECM_ERRORIN_NF_0                                          IOPORT_FILTER_SIGNAL_ERRORIN0 /* PRQA S 1534 # Advisory R-2.5 */              ///< ECM ERRORIN NF0

/** GTM_ATOM */
#define BSP_FEATURE_GTM_ATOM_HRES_MODE_SUPPORT                                (1U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< High-Resolution PWM Support

/** IPI */
#define BSP_FEATURE_IPI_VALID_PE                                              (0x0FU) /* PRQA S 1534 # Advisory R-2.5 */                                    ///< IPI valid PE mask
#define BSP_FEATURE_IPI_VALID_REQ                                             (0x000FU) /* PRQA S 1534 # Advisory R-2.5 */                                  ///< IPI valid interrupt request mask

/** FLASH */
#define BSP_FEATURE_FLASH_CF_WRITE_SIZE                                       (512U) /* PRQA S 1534 # Advisory R-2.5 */                                     ///< Code flash minimum write size in bytes
#define BSP_FEATURE_FLASH_CF_REGION0_BLOCK_SIZE                               (0x4000U) /* PRQA S 1534 # Advisory R-2.5 */                                  ///< Small CF block size: 16 KB
#define BSP_FEATURE_FLASH_CF_REGION1_BLOCK_SIZE                               (0x10000U) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< Large CF block size: 64 KB
#define BSP_FEATURE_FLASH_CF_REGION0_SIZE                                     (0x00020000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Region 0 total size: 128 KB (8 x 16 KB)
#define BSP_FEATURE_FLASH_CF_BLANK_CHECK_AREA_START                           (0x0C000000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Code Flash Blank Check Area base address

#define BSP_FEATURE_FLASH_CF_BANK_A_START                                     (0x00000000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Bank A start address
#define BSP_FEATURE_FLASH_CF_BANK_A_SIZE                                      (0x00300000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Bank A size: 3 MB (U2B10)
#define BSP_FEATURE_FLASH_CF_BANK_B_START                                     (0x00300000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Bank B start address
#define BSP_FEATURE_FLASH_CF_BANK_B_SIZE                                      (0x00300000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Bank B size: 3 MB (U2B10)
#define BSP_FEATURE_FLASH_CF_BANK_C_START                                     (0x00600000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Bank C start address
#define BSP_FEATURE_FLASH_CF_BANK_C_SIZE                                      (0x00200000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Bank C size: 2 MB (U2B10)
#define BSP_FEATURE_FLASH_CF_BANK_D_START                                     (0x00800000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Bank D start address
#define BSP_FEATURE_FLASH_CF_BANK_D_SIZE                                      (0x00200000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Bank D size: 2 MB (U2B10)

#define BSP_FEATURE_FLASH_CODE_FLASH_START                                    (0x00000000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Code flash start address
#define BSP_FEATURE_FLASH_DF_BLOCK_SIZE                                       (0x1000U) /* PRQA S 1534 # Advisory R-2.5 */                                  ///< Data flash block (erase unit): 4 KB
#define BSP_FEATURE_FLASH_DF_WRITE_SIZE                                       (4U) /* PRQA S 1534 # Advisory R-2.5 */                                       ///< Data flash minimum write size in bytes

#define BSP_FEATURE_FLASH_DATA_FLASH_AREA0_START                              (0xFF200000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Data Area 0 start (FPSYS0)
#define BSP_FEATURE_FLASH_DATA_FLASH_AREA0_SIZE                               (0x20000U) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< Data Area 0 size: 128 KB
#define BSP_FEATURE_FLASH_DATA_FLASH_AREA1_START                              (0xFF220000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Data Area 1 start (FPSYS1)
#define BSP_FEATURE_FLASH_DATA_FLASH_AREA1_SIZE                               (0x20000U) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< Data Area 1 size: 128 KB
#define BSP_FEATURE_FLASH_DATA_FLASH_AREA2_START                              (0xFF240000U) /* PRQA S 1534 # Advisory R-2.5 */                              ///< Data Area 2 start (FPSYS2) - ICUMB unit only
#define BSP_FEATURE_FLASH_DATA_FLASH_AREA2_SIZE                               (0x10000U) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< Data Area 2 size: 64 KB - ICUMB unit only
#define BSP_FEATURE_FLASH_DATA_FLASH_START                                    (BSP_FEATURE_FLASH_DATA_FLASH_AREA0_START) /* PRQA S 1534 # Advisory R-2.5 */ ///< DF start address

/* PRQA S 1534 ++ # Advisory R-2.5 */
#define BSP_DATA_FLASH_SIZE_BYTES                                             (BSP_FEATURE_FLASH_DATA_FLASH_AREA0_SIZE + \
                                                                               BSP_FEATURE_FLASH_DATA_FLASH_AREA1_SIZE)                                     ///< CPU-accessible DF: 256 KB

/* PRQA S 1534 -- */

/** SCI3 */
#define BSP_FEATURE_SCI3_CHANNEL_NUM                                          (0U) /* PRQA S 1534 # Advisory R-2.5 */               ///< Number of SCI3 channels available

#define BSP_FEATURE_RHSB_VALID_CHANNEL_MASK                                   (0x00000007UL) /* PRQA S 1534 # Advisory R-2.5 */     ///< RHSB implemented-unit mask: RHSB0, 1, 2

#define BSP_FEATURE_R_ENCA0_TYPE_USED                                         (0U) /* PRQA S 1534 # Advisory R-2.5 */               ///< R_ENCA0_Type is not used

#define BSP_FEATURE_IOPORT_NF_TAUD2_USE_TAUD_REG                              (0U) /* PRQA S 1534 # Advisory R-2.5 */               ///< Indicates whether TAUD2 noise filter uses the TAUD-specific control register.
#define BSP_FEATURE_IOPORT_NF_TAUJ_FCLA_AVAILABLE                             (0U) /* PRQA S 1534 # Advisory R-2.5 */               ///< Indicates whether TAUJ noise filter has the TAUJ-specific FCLACTL edge detector register.

#define BSP_FEATURE_TPTM_COMPARISON_STATUS                                    (1) /* PRQA S 1534 # Advisory R-2.5 */                ///< Comparison status is available

#define BSP_FEATURE_TPTM_INTERRUPT_UP_TIMER                                   (1) /* PRQA S 1534 # Advisory R-2.5 */                ///< Interrupt up timer is  available

#define BSP_FEATURE_ADCJ_HWIP_SUPPORT                                         (0U) /* PRQA S 1534 # Advisory R-2.5 */               ///< ADCJ peripheral support
#define BSP_FEATURE_ADCK_HWIP_SUPPORT                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< ADCK peripheral support

#define BSP_FEATURE_MOTOR_SUPPORTED_VARIANT                                   (0x0010U) /* PRQA S 1534 # Advisory R-2.5 */          ///< Profile for MCU variant, 1 hex present 1 MCU variant using alphabet order
#define BSP_FEATURE_MOTOR_IOPORT_PIN_NUMBER                                   (BSP_PACKAGE_PINS) /* PRQA S 1534 # Advisory R-2.5 */ ///< Pin profile number
#define BSP_FEATURE_MOTOR_TAUD_THREE_PHASE_SUPPORT                            (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< Taud three phase feature support

/** TAPA */
#define BSP_FEATURE_TAPA_SUPPORTED_VARIANT                                    (0x0010U) /* PRQA S 1534 # Advisory R-2.5 */          ///< Profile for MCU variant, 1 bit present 1 MCU variant using alphabet order

/** PWM_DIAG */
#define BSP_FEATURE_PWM_DIAG_SUPPORTED_VARIANT                                (0x0010U) /* PRQA S 1534 # Advisory R-2.5 */          ///< Profile for MCU variant, 1 bit present 1 MCU variant using alphabet order

/** DSADC */
#define BSP_FEATURE_DSADC_SUPPORTED_VARIANT                                   (0x0010U) /* PRQA S 1534 # Advisory R-2.5 */          ///< Profile for MCU variant, 1 bit present 1 MCU variant using alphabet order

/** ADCK */
#define BSP_FEATURE_ADCK_SUPPORTED_VARIANT                                    (0x0010U) /* PRQA S 1534 # Advisory R-2.5 */          ///< Profile for MCU variant, 1 bit present 1 MCU variant using alphabet order

/** OSTM */
#define BSP_FEATURE_OSTM_SIMPLE_CHANNEL_LAYOUT_AVAILABLE                      (0U) /* PRQA S 1534 # Advisory R-2.5 */               ///< OSTM simple channel layout is not available
#define BSP_FEATURE_OSTM_EXTENDED_CHANNEL_LAYOUT_AVAILABLE                    (0U) /* PRQA S 1534 # Advisory R-2.5 */               ///< OSTM extended channel layout is not available

/** PIC */
#define BSP_FEATURE_PIC_SUPPORTED_VARIANT                                     (0x0010U) /* PRQA S 1534 # Advisory R-2.5 */          ///< Profile for MCU variant, 1 bit present 1 MCU variant using alphabet order
#define BSP_FEATURE_PIC_AVAILABLE                                             (0x0010U) /* PRQA S 1534 # Advisory R-2.5 */          ///< Profile for MCU variant, 1 bit present 1 MCU variant using alphabet order

/** LPS */
#define BSP_FEATURE_LPS_SUPPORTED_VARIANT                                     (0x0010U) /* PRQA S 1534 # Advisory R-2.5 */          ///< Profile for MCU variant, 1 bit present 1 MCU variant using alphabet order
#define BSP_FEATURE_LPS_PIN_0_SUPPORT                                         (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< LPS support pin for U2B

/** LPS */
#define BSP_FEATURE_LPS_ANALOG_MODE_SUPPORT                                   (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< LPS analog mode support
#define BSP_FEATURE_LPS_DIGITAL_MODE_SUPPORT                                  (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< LPS digital mode support
#define BSP_FEATURE_LPS_DIGITAL_INPUT_SUPPORT                                 (0U) /* PRQA S 1534 # Advisory R-2.5 */               ///< LPS digital input mode unsupport

/** DSMIF */
#define BSP_FEATURE_DSMIF_PIN_0_SUPPORT                                       (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< DSMIF support pin for U2Bx

/** GTM */
#define BSP_FEATURE_GTM_INTSEL_SUPPORT                                        (1U)                                                  ///< Interconnections of Interrupt Factors for INTC Support
#define BSP_FEATURE_GTM_INTSEL_NUMBER                                         (10U) /* PRQA S 1534 # Advisory R-2.5 */              ///< Number of interrupt selection control for INTC registers
#define BSP_FEATURE_GTM_DMASEL_SUPPORT                                        (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< Interconnections of Interrupt Factors for DMA/DTS Support
#define BSP_FEATURE_GTM_DMASEL_NUMBER                                         (10U) /* PRQA S 1534 # Advisory R-2.5 */              ///< Number of interrupt selection control for DMA/DTS registers
#define BSP_FEATURE_GTM_IP_GEN_3                                              (0U) /* PRQA S 1534 # Advisory R-2.5 */               ///< GTM_IP generation 3 in used
#define BSP_FEATURE_GTM_IP_GEN_4                                              (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< GTM_IP generation 4 in used
#define BSP_FEATURE_GTM_ADCI_RDC3A_SUPPORT                                    (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< Stored RDC3A data in ADC interface support
#define BSP_FEATURE_GTM_ADCI_EMU3S_DFE_SUPPORT                                (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< Stored DFE or EMU3S data in ADC interface support

/** GTM_DTM */
#define BSP_FEATURE_GTM_DTM_HRES_MODE_SUPPORT                                 (1U) /* PRQA S 1534 # Advisory R-2.5 */               ///< High-Resolution PWM Support

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RH850U2B10) */

#endif                                 /* BSP_FEATURE_H */
