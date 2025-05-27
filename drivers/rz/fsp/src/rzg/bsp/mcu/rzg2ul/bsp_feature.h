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
#define BSP_FEATURE_ADC_NUM_CALIBRATION_DATA                   (2U)
#define BSP_FEATURE_ADC_C_VALID_CHANNEL_MASK                   (0xF)
#define BSP_FEATURE_ADC_C_NUM_CHANNELS                         (2U)
#define BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MIN               (6U)
#define BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MAX               (2800U)
#define BSP_FEATURE_ADC_C_CONVERSION_TIME                      (14U)
#define BSP_FEATURE_ADC_C_HAS_ADIVC                            (1U)
#define BSP_FEATURE_ADC_C_TSU_CONTROL_AVAILABLE                (0U)

/* BSP Capabilities Definitions */
#define BSP_FEATURE_BSP_CLOCK_FREQ_INIT_CFG_SUPPORT            (0U)
#define BSP_FEATURE_BSP_HAS_ELC                                (0U)
#define BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT       (1)
#define BSP_FEATURE_BSP_SUPPORT_SD_VOLT                        (1U)
#define BSP_FEATURE_BSP_SUPPORT_ETHER_VOLT                     (1U)
#define BSP_FEATURE_BSP_SUPPORT_ETHER_MODE                     (1U)
#define BSP_FEATURE_BSP_SUPPORT_QSPI_VOLT                      (1U)
#define BSP_FEATURE_BSP_SUPPORT_XSPI_VOLT                      (0U)
#define BSP_FEATURE_BSP_SUPPORT_XSPI_OUTPUT                    (0U)
#define BSP_FEATURE_BSP_SUPPORT_I3C                            (0U)
#define BSP_FEATURE_BSP_SUPPORT_BYPASS                         (0U)
#define BSP_FEATURE_BSP_SUPPORT_PFCWE_PROTECT                  (1U)
#define BSP_FEATURE_BSP_SUPPORT_OEN_PROTECT                    (0U)
#define BSP_FEATURE_BSP_HAS_PFC_OEN_REG                        (0U)
#define BSP_FEATURE_BSP_HAS_ETHER_MODE_REG                     (0U)
#define BSP_FEATURE_BSP_HAS_SD_CH_POC_REG                      (0U)
#define BSP_FEATURE_BSP_HAS_ETH_POC_REG                        (0U)

/* CANFD-Related Definitions */
#define BSP_FEATURE_CANFD_NUM_CHANNELS                         (2)
#define BSP_FEATURE_CANFD_FD_SUPPORT                           (1)
#define BSP_FEATURE_CANFD_LITE                                 (0U)
#define BSP_FEATURE_CANFD_NUM_INSTANCES                        (1U)
#define BSP_FEATURE_CANFD_HAS_RSCANFD                          (1U)
#define BSP_FEATURE_CANFD_TXMB_OFFSET                          (16U)
#define BSP_FEATURE_CANFD_TXMB_CHANNEL_OFFSET                  (16U)
#define BSP_FEATURE_CANFD_RXMB_MAX                             (32U)

/* CPG-Related Definitions */
#define BSP_FEATURE_CPG_HAS_ICLK                               (1U)
#define BSP_FEATURE_CPG_HAS_I2CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_GCLK                               (0U)
#define BSP_FEATURE_CPG_HAS_S0CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_SPI0CLK                            (1U)
#define BSP_FEATURE_CPG_HAS_SPI1CLK                            (1U)
#define BSP_FEATURE_CPG_HAS_SD0CLK                             (1U)
#define BSP_FEATURE_CPG_HAS_SD1CLK                             (1U)
#define BSP_FEATURE_CPG_HAS_M0CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_M1CLK                              (0U)
#define BSP_FEATURE_CPG_HAS_M2CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_M3CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_M4CLK                              (0U)
#define BSP_FEATURE_CPG_HAS_HPCLK                              (1U)
#define BSP_FEATURE_CPG_HAS_TSUCLK                             (1U)
#define BSP_FEATURE_CPG_HAS_ZTCLK                              (1U)
#define BSP_FEATURE_CPG_HAS_P0CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_P1CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_P2CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_ATCLK                              (1U)
#define BSP_FEATURE_CPG_HAS_OSCCLK                             (1U)

/* DMAC-Related Definitions */
#define BSP_FEATURE_DMAC_MAX_CHANNEL                           (16U)
#define BSP_FEATURE_DMAC_MAX_UNIT                              (2U)

/* GPT-Related Definitions */
#define BSP_FEATURE_GPT_VALID_CHANNEL_MASK                     (0xFFU)

/* GTM-Related Definitions */
#define BSP_FEATURE_GTM_VALID_CHANNEL_MASK                     (0x6)

/* IIC-Related Definitions */
#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK                     (0x0F)

/* INTC-Related Definitions */
#define BSP_FEATURE_INTC_IRQ_VALID_CHANNEL_MASK                (0xFFU)

/* IOPORT-Related Definitions */
#define BSP_FEATURE_IOPORT_SUPPORT_SR_REG                      (1U)
#define BSP_FEATURE_IOPORT_GP_REG_BASE_NUM                     10
#define BSP_FEATURE_IOPORT_SP_REG_BASE_NUM                     2
#define BSP_FEATURE_IOPORT_FIL_SP_REG_BASE_NUM                 01
#define BSP_FEATURE_IOPORT_IEN_SP_REG_BASE_NUM                 02
#define BSP_FEATURE_IOPORT_IOLH_SP_REG_BASE_NUM                02
#define BSP_FEATURE_IOPORT_SR_SP_REG_BASE_NUM                  02

/* MHU-Related Definitions */
#define BSP_FEATURE_MHU_NS_VALID_CHANNEL_MASK                  (0x12U)
#define BSP_FEATURE_MHU_NS_SEND_TYPE_RSP_VALID_CHANNEL_MASK    (0x02U)
#define BSP_FEATURE_MHU_NS_SWINT_GET_VALID_CHANNEL_MASK        (0x05U)
#define BSP_FEATURE_MHU_NS_SWINT_SET_VALID_CHANNEL_MASK        (0x05U)
#define BSP_FEATURE_MHU_S_VALID_CHANNEL_MASK                   (0x12U)
#define BSP_FEATURE_MHU_S_SEND_TYPE_RSP_VALID_CHANNEL_MASK     (0x02U)

/* MTU-Related Definitions */
#define BSP_FEATURE_MTU3_VALID_CHANNEL_MASK                    (0x01FF)
#define BSP_FEATURE_MTU3_MAX_CHANNELS                          (9U)

/* POEG-Related Definitions */
#define BSP_FEATURE_POEG_CHANNEL_MASK                          (0xFU)

/* RSPI-Related Definitions */
#define BSP_FEATURE_RSPI_VALID_CHANNELS_MASK                   (0x7)
#define BSP_FEATURE_RSPI_CLOCK                                 (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_RSPI_CLK_MAX_DIV                           (4096U)
#define BSP_FEATURE_RSPI_CLK_MIN_DIV                           (4U)

/* SCIF-Related Definitions */
#define BSP_FEATURE_SCIF_CHANNELS                              (0x1FU)
#define BSP_FEATURE_SCIF_CHANNELS_HAS_RTSCTS                   (0x07U)
#define BSP_FEATURE_SCIF_CLOCK                                 (FSP_PRIV_CLOCK_P0CLK)

/* SSI-Related Definitions */
#define BSP_FEATURE_SSI_FIFO_NUM_STAGES                        (32U)
#define BSP_FEATURE_SSI_VALID_CHANNEL_MASK                     (0x0FU)

/* Startup Process-Related Definitions */
#define BSP_FEATURE_REQUIRE_DATA_REGION_COPY                   (1U)

/* TrustZone-Related Definitions */
#define BSP_FEATURE_TZ_HAS_TRUSTZONE                           (1U)

#endif                                 /* BSP_FEATURE_H */
