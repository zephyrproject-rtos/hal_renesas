/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_feature.h
 * Version      : 1.00
 * Description  : bsp_feature header
 *********************************************************************************************************************/

#ifndef BSP_FEATURE_H
#define BSP_FEATURE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* ADC-Related Definitions */
#define BSP_FEATURE_ADC_VALID_CHANNEL_MASK                      (0xFFF)
#define BSP_FEATURE_ADC_NUM_CALIBRATION_DATA                    (2U)
#define BSP_FEATURE_ADC_NUM_CHANNELS                            (12U)
#define BSP_FEATURE_ADC_C_VALID_CHANNEL_MASK                    (0xFFF)
#define BSP_FEATURE_ADC_C_NUM_CHANNELS                          (12U)
#define BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MIN                (79U)
#define BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MAX                (255U)
#define BSP_FEATURE_ADC_C_CONVERSION_TIME                       (29U)
#define BSP_FEATURE_ADC_C_HAS_ADIVC                             (0U)
#define BSP_FEATURE_ADC_C_TSU_CONTROL_AVAILABLE                 (1U)
#define BSP_FEATURE_ADC_C_TSU_ENABLE_STABILIZATION_TIME_US      (30U)
#define BSP_FEATURE_ADC_C_TSU_START_STABILIZATION_TIME_MS       (1U)

/* BSP Capabilities Definitions */
#define BSP_FEATURE_BSP_CLOCK_FREQ_INIT_CFG_SUPPORT             (1U)
#define BSP_FEATURE_BSP_HAS_ELC                                 (0U)
#define BSP_FEATURE_BSP_HAS_GPT_CLOCK                           (0U)
#define BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT        (1U)
#define BSP_FEATURE_BSP_SUPPORT_SD_VOLT                         (1U)
#define BSP_FEATURE_BSP_SUPPORT_ETHER_VOLT                      (1U)
#define BSP_FEATURE_BSP_SUPPORT_ETHER_MODE                      (1U)
#define BSP_FEATURE_BSP_SUPPORT_QSPI_VOLT                       (0U)
#define BSP_FEATURE_BSP_SUPPORT_XSPI_VOLT                       (1U)
#define BSP_FEATURE_BSP_SUPPORT_XSPI_OUTPUT                     (0U)
#define BSP_FEATURE_BSP_SUPPORT_I3C                             (1U)
#define BSP_FEATURE_BSP_SUPPORT_BYPASS                          (0U)
#define BSP_FEATURE_BSP_SUPPORT_PFCWE_PROTECT                   (1U)
#define BSP_FEATURE_BSP_SUPPORT_OEN_PROTECT                     (0U)
#define BSP_FEATURE_BSP_HAS_PFC_OEN_REG                         (0U)
#define BSP_FEATURE_BSP_HAS_ETHER_MODE_REG                      (1U)
#define BSP_FEATURE_BSP_HAS_SD_CH_POC_REG                       (1U)
#define BSP_FEATURE_BSP_HAS_ETH_POC_REG                         (1U)

/* CANFD-Related Definitions */
#define BSP_FEATURE_CANFD_NUM_CHANNELS                          (2)
#define BSP_FEATURE_CANFD_FD_SUPPORT                            (1)
#define BSP_FEATURE_CANFD_LITE                                  (0U)
#define BSP_FEATURE_CANFD_NUM_INSTANCES                         (1U)
#define BSP_FEATURE_CANFD_HAS_RSCANFD                           (0U)
#define BSP_FEATURE_CANFD_TXMB_OFFSET                           (32U)
#define BSP_FEATURE_CANFD_TXMB_CHANNEL_OFFSET                   (64U)
#define BSP_FEATURE_CANFD_RXMB_MAX                              (32U)

/* Cortex-M33 Feature Definitions */
#define BSP_FEATURE_MCORE_HAS_DSP                               (0U)
#if BSP_CURRENT_CORE == RZG3S_CORE_CM33
 #define BSP_FEATURE_MCORE_HAS_FPU                              (0U)
 #define BSP_FEATURE_CURRENT_CORE_IS_CM33_FPU                   (0U)
#elif BSP_CURRENT_CORE == RZG3S_CORE_CM33_FPU
 #define BSP_FEATURE_MCORE_HAS_FPU                              (1U)
 #define BSP_FEATURE_CURRENT_CORE_IS_CM33_FPU                   (1U)
#endif

/* CPG-Related Definitions */
#define BSP_FEATURE_CPG_HAS_ICLK                                (1U)
#define BSP_FEATURE_CPG_HAS_I2CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_I3CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_GCLK                                (0U)
#define BSP_FEATURE_CPG_HAS_S0CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_OC0CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_OC1CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_SPI0CLK                             (1U)
#define BSP_FEATURE_CPG_HAS_SPI1CLK                             (1U)
#define BSP_FEATURE_CPG_HAS_SD0CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_SD1CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_SD2CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_M0CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_M1CLK                               (0U)
#define BSP_FEATURE_CPG_HAS_M2CLK                               (0U)
#define BSP_FEATURE_CPG_HAS_M3CLK                               (0U)
#define BSP_FEATURE_CPG_HAS_M4CLK                               (0U)
#define BSP_FEATURE_CPG_HAS_HPCLK                               (1U)
#define BSP_FEATURE_CPG_HAS_TSUCLK                              (1U)
#define BSP_FEATURE_CPG_HAS_ZTCLK                               (1U)
#define BSP_FEATURE_CPG_HAS_P0CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_P1CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_P2CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_P3CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_P4CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_P5CLK                               (1U)
#define BSP_FEATURE_CPG_HAS_ATCLK                               (1U)
#define BSP_FEATURE_CPG_HAS_OSCCLK                              (1U)
#define BSP_FEATURE_CPG_HAS_OSCCLK2                             (1U)

/* DMAC-Related Definitions */
#define BSP_FEATURE_DMAC_MAX_CHANNEL                            (16U)
#define BSP_FEATURE_DMAC_MAX_UNIT                               (2U)

/* GPT-Related Definitions */
#define BSP_FEATURE_GPT_EVENT_COUNT_CHANNEL_MASK                (BSP_FEATURE_GPT_VALID_CHANNEL_MASK)
#define BSP_FEATURE_GPT_VALID_CHANNEL_MASK                      (0xFFU)
#define BSP_FEATURE_GPT_TPCS_SHIFT                              (1U)
#define BSP_FEATURE_GPT_CLOCK_DIVIDER_STEP_SIZE                 (4U)
#define BSP_FEATURE_GPT_CLOCK_DIVIDER_VALUE_7_9_VALID           (0U)

/* GTM-Related Definitions */
#define BSP_FEATURE_GTM_VALID_CHANNEL_MASK                      (0xFFU)

/* IIC-Related Definitions */
#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK                      (0x0F)

/* INTC-Related Definitions */
#define BSP_FEATURE_INTC_IRQ_VALID_CHANNEL_MASK                 (0xFFU)

/* IOPORT-Related Definitions */
#define BSP_FEATURE_IOPORT_SUPPORT_SR_REG                       (0U)
#define BSP_FEATURE_IOPORT_GP_REG_BASE_NUM                      _20
#define BSP_FEATURE_IOPORT_SP_REG_BASE_NUM                      1
#define BSP_FEATURE_IOPORT_FIL_SP_REG_BASE_NUM                  _00
#define BSP_FEATURE_IOPORT_IEN_SP_REG_BASE_NUM                  _01
#define BSP_FEATURE_IOPORT_IOLH_SP_REG_BASE_NUM                 _01
#define BSP_FEATURE_IOPORT_SR_SP_REG_BASE_NUM                   0

/* MHU-Related Definitions */
#if BSP_CURRENT_CORE == RZG3S_CORE_CM33
 #define BSP_FEATURE_MHU_NS_VALID_CHANNEL_MASK                  (0x3AU)
 #define BSP_FEATURE_MHU_NS_SEND_TYPE_RSP_VALID_CHANNEL_MASK    (0x0AU)
 #define BSP_FEATURE_MHU_NS_SWINT_GET_VALID_CHANNEL_MASK        (0x03U)
 #define BSP_FEATURE_MHU_NS_SWINT_SET_VALID_CHANNEL_MASK        (0x0CU)
 #define BSP_FEATURE_MHU_S_VALID_CHANNEL_MASK                   (0x3AU)
 #define BSP_FEATURE_MHU_S_SEND_TYPE_RSP_VALID_CHANNEL_MASK     (0x0AU)
#elif BSP_CURRENT_CORE == RZG3S_CORE_CM33_FPU
 #define BSP_FEATURE_MHU_NS_VALID_CHANNEL_MASK                  (0x2DU)
 #define BSP_FEATURE_MHU_NS_SEND_TYPE_RSP_VALID_CHANNEL_MASK    (0x21U)
 #define BSP_FEATURE_MHU_NS_SWINT_GET_VALID_CHANNEL_MASK        (0x28U)
 #define BSP_FEATURE_MHU_NS_SWINT_SET_VALID_CHANNEL_MASK        (0x12U)
 #define BSP_FEATURE_MHU_S_VALID_CHANNEL_MASK                   (0x2DU)
 #define BSP_FEATURE_MHU_S_SEND_TYPE_RSP_VALID_CHANNEL_MASK     (0x21U)
#endif

/* POEG-Related Definitions */
#define BSP_FEATURE_POEG_CHANNEL_MASK                           (0xFU)

/* RSPI-Related Definitions */
#define BSP_FEATURE_RSPI_VALID_CHANNELS_MASK                    (0x1FU)
#define BSP_FEATURE_RSPI_CLOCK                                  (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_RSPI_CLK_MAX_DIV                            (4096U)
#define BSP_FEATURE_RSPI_CLK_MIN_DIV                            (4U)

/* SCIF-Related Definitions */
#define BSP_FEATURE_SCIF_CHANNELS                               (0x3FU)
#define BSP_FEATURE_SCIF_CHANNELS_HAS_RTSCTS                    (0x07U)
#define BSP_FEATURE_SCIF_CLOCK                                  (FSP_PRIV_CLOCK_P0CLK)

/* SSI-Related Definitions */
#define BSP_FEATURE_SSI_FIFO_NUM_STAGES                         (32U)
#define BSP_FEATURE_SSI_VALID_CHANNEL_MASK                      (0x0FU)

/* TrustZone-Related Definitions */
#define BSP_FEATURE_TZ_HAS_TRUSTZONE                            (1U)

/* WDT-Related Definitions */
#define BSP_FEATURE_WDT_MAX_CHANNELS                            (2U)

#define BSP_FEATURE_XSPI_CHANNELS                               (0x01U)
#define BSP_FEATURE_XSPI_NUM_CHIP_SELECT                        (2U)
#define BSP_FEATURE_XSPI_NUM_UNITS                              (1U)
#define BSP_FEATURE_XSPI_DO_NOT_HAS_CSSCTL                      (1U)
#define BSP_FEATURE_XSPI_START_ADDRESS                          (0x80000000)
#define BSP_FEATURE_XSPI_DEVICE_CS0_1_ADDRESS_DELTA             (0x08000000)

#endif                                 /* BSP_FEATURE_H */
