/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

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

/* ADC_C-Related Definitions */
#define BSP_FEATURE_ADC_NUM_CALIBRATION_DATA                   (2U)
#define BSP_FEATURE_ADC_C_VALID_CHANNEL_MASK                   (0xFF)
#define BSP_FEATURE_ADC_C_NUM_CHANNELS                         (8U)
#define BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MIN               (6U)
#define BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MAX               (2800U)
#define BSP_FEATURE_ADC_C_CONVERSION_TIME                      (14U)
#define BSP_FEATURE_ADC_C_HAS_ADIVC                            (1U)
#define BSP_FEATURE_ADC_C_TSU_CONTROL_AVAILABLE                (0U)

/* BSP Capabilities Definitions */
#define BSP_FEATURE_BSP_ACCESS_CONTROL_SET_SUPPORT             (0U)
#define BSP_FEATURE_BSP_CLOCK_FREQ_INIT_CFG_SUPPORT            (0U)
#define BSP_FEATURE_BSP_DELAY_LOOP_CYCLES                      (100U)
#define BSP_FEATURE_BSP_INT_SIGNAL_VIA_DMAC                    (1U)
#define BSP_FEATURE_BSP_SYSTEM_CORE_CLOCK                      (FSP_PRIV_CLOCK_I2CLK)
#define BSP_FEATURE_BSP_HAS_GPT_CLOCK                          (0U)
#define BSP_FEATURE_BSP_HAS_ELC                                (0U)
#define BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT       (1U)
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
#define BSP_FEATURE_BSP_HAS_GPT_CLOCK                          (0U)
#define BSP_FEATURE_BSP_SUPPORT_STARTING_CR8                   (0U)

/* CANFD-Related Definitions */
#define BSP_FEATURE_CANFD_NUM_CHANNELS                         (2)
#define BSP_FEATURE_CANFD_FD_SUPPORT                           (1)
#define BSP_FEATURE_CANFD_LITE                                 (0U)
#define BSP_FEATURE_CANFD_NUM_INSTANCES                        (1U)
#define BSP_FEATURE_CANFD_HAS_RSCANFD                          (1U)
#define BSP_FEATURE_CANFD_TXMB_OFFSET                          (16U)
#define BSP_FEATURE_CANFD_TXMB_CHANNEL_OFFSET                  (16U)
#define BSP_FEATURE_CANFD_RXMB_MAX                             (32U)
#define BSP_FEATURE_CANFD_ERROR_GLOBAL_CH0_ECC_REG_POS         (28U)
#define BSP_FEATURE_CANFD_NUM_COMMON_FIFOS                     (6U)

/* CPG-Related Definitions */
#define BSP_FEATURE_CPG_HAS_ICLK                               (1U)
#define BSP_FEATURE_CPG_HAS_I2CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_GCLK                               (1U)
#define BSP_FEATURE_CPG_HAS_S0CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_SPI0CLK                            (1U)
#define BSP_FEATURE_CPG_HAS_SPI1CLK                            (1U)
#define BSP_FEATURE_CPG_HAS_SD0CLK                             (1U)
#define BSP_FEATURE_CPG_HAS_SD1CLK                             (1U)
#define BSP_FEATURE_CPG_HAS_M0CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_M1CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_M2CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_M3CLK                              (1U)
#define BSP_FEATURE_CPG_HAS_M4CLK                              (1U)
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
#define BSP_FEATURE_GPT_MAX_CHANNEL                            (8U)
#define BSP_FEATURE_GPT_EVENT_COUNT_CHANNEL_MASK               (BSP_FEATURE_GPT_VALID_CHANNEL_MASK)
#define BSP_FEATURE_GPT_TPCS_SHIFT                             (1U)
#define BSP_FEATURE_GPT_CLOCK_DIVIDER_STEP_SIZE                (4U)
#define BSP_FEATURE_GPT_CLOCK_DIVIDER_VALUE_7_9_VALID          (0U)
#define BSP_FEATURE_GPT_ODC_VALID_CHANNEL_MASK                 (0U)
#define BSP_FEATURE_GPT_32BIT_CHANNEL_MASK                     (0xFFU)
#define BSP_FEATURE_GPT_CLOCK_SOURCE                           (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_GPT_STATUS_REGISTER                        GTST
#define BSP_FEATURE_GPT_OUTPUT_DISABLE_REQUEST_STATUS_MASK     (R_GPT0_GTST_OABLF_Msk | R_GPT0_GTST_OABHF_Msk | \
                                                                R_GPT0_GTST_DTEF_Msk)

/* GTM-Related Definitions */
#define BSP_FEATURE_GTM_MAX_CHANNEL                            (3U)
#define BSP_FEATURE_GTM_VALID_CHANNEL_MASK                     (0x6)
#define BSP_FEATURE_GTM_SOURCE_CLOCK                           (FSP_PRIV_CLOCK_P0CLK)

/* IIC-Related Definitions */
#define BSP_FEATURE_IIC_MAX_CHANNEL                            (4U)
#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK                     (0x0F)
#define BSP_FEATURE_IIC_SOURCE_CLOCK                           (FSP_PRIV_CLOCK_P0CLK)

/* INTC-Related Definitions */
#define BSP_FEATURE_INTC_IRQ_VALID_CHANNEL_MASK                (0xFFU)
#define BSP_FEATURE_INTC_BASE_ADDR                             (R_INTC_IM33)

/* IOPORT-Related Definitions */
#define BSP_FEATURE_IOPORT_PORT_GROUP_NUM                      (0U)
#define BSP_FEATURE_IOPORT_SINGLE_PORT_NUM                     (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_PERIPHERAL_FIL              (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_SR_REG                      (1U)
#define BSP_FEATURE_IOPORT_SUPPORT_NOD_REG                     (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_SMT_REG                     (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_PUPD_SP                     (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_IEN_GP                      (0U)
#define BSP_FEATURE_IOPORT_PFC_REG_BITFIELD                    (7U)
#define BSP_FEATURE_IOPORT_GP_REG_BASE_NUM                     10
#define BSP_FEATURE_IOPORT_REG_POSTFIX_L
#define BSP_FEATURE_IOPORT_SP_REG_BASE_NUM                     2
#define BSP_FEATURE_IOPORT_FIL_SP_REG_BASE_NUM                 01
#define BSP_FEATURE_IOPORT_IEN_SP_REG_BASE_NUM                 2
#define BSP_FEATURE_IOPORT_IEN_SP_REG_BASE_NUM_SYM             02
#define BSP_FEATURE_IOPORT_IEN_GP_REG_BASE_NUM                 (0U)
#define BSP_FEATURE_IOPORT_IEN_GP_REG_BASE_NUM_SYM             (0U)
#define BSP_FEATURE_IOPORT_IOLH_SP_REG_BASE_NUM                02
#define BSP_FEATURE_IOPORT_SR_SP_REG_BASE_NUM                  02
#define BSP_FEATURE_IOPORT_NOD_SP_REG_BASE_NUM                 (0U)
#define BSP_FEATURE_IOPORT_PUPD_SP_REG_BASE_NUM                (0U)
#define BSP_FEATURE_IOPORT_GROUP1_PORT                         (0U)
#define BSP_FEATURE_IOPORT_GROUP2_PORT                         (0U)
#define BSP_FEATURE_IOPORT_FIL_IRQ_FUNC                        (0U)
#define BSP_FEATURE_IOPORT_FIL_DMAC_FUNC                       (0U)
#define BSP_FEATURE_IOPORT_PWPR_PFCWE_OFFSET                   (6U)
#define BSP_FEATURE_IOPORT_PWPR_B0WI_OFFSET                    (7U)

/* MHU-Related Definitions */
#define BSP_FEATURE_MHU_NS_VALID_CHANNEL_MASK                  (0x3AU)
#define BSP_FEATURE_MHU_NS_SEND_TYPE_RSP_VALID_CHANNEL_MASK    (0x0AU)
#define BSP_FEATURE_MHU_NS_SWINT_GET_VALID_CHANNEL_MASK        (0x0FU)
#define BSP_FEATURE_MHU_NS_SWINT_SET_VALID_CHANNEL_MASK        (0x0FU)
#define BSP_FEATURE_MHU_S_VALID_CHANNEL_MASK                   (0x3AU)
#define BSP_FEATURE_MHU_S_SEND_TYPE_RSP_VALID_CHANNEL_MASK     (0x0AU)

/* POEG-Related Definitions */
#define BSP_FEATURE_POEG_CHANNEL_MASK                          (0xFU)

/* RSPI-Related Definitions */
#define BSP_FEATURE_RSPI_VALID_CHANNELS_MASK                   (0x7)
#define BSP_FEATURE_RSPI_CLOCK                                 (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_RSPI_CLK_MAX_DIV                           (4096U)
#define BSP_FEATURE_RSPI_CLK_MIN_DIV                           (4U)

/* SCIF-Related Definitions */
#define BSP_FEATURE_SCIF_MAX_CHANNEL                           (5U)
#define BSP_FEATURE_SCIF_CHANNELS                              (0x1FU)
#define BSP_FEATURE_SCIF_CHANNELS_HAS_RTSCTS                   (0x07U)
#define BSP_FEATURE_SCIF_RTSCTS_SUPPORT                        (1)
#define BSP_FEATURE_SCIF_CLOCK                                 (FSP_PRIV_CLOCK_P0CLK)

/* MTU3-Related Definitions */
#define BSP_FEATURE_MTU3_VALID_CHANNEL_MASK                    (0x01FF)
#define BSP_FEATURE_MTU3_MAX_CHANNELS                          (9U)

/* Startup Process-Related Definitions */
#define BSP_FEATURE_REQUIRE_DATA_REGION_COPY                   (1U)

/* TrustZone-Related Definitions */
#define BSP_FEATURE_TZ_HAS_TRUSTZONE                           (1U)

#endif                                 /* BSP_FEATURE_H */
