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

#define BSP_FEATURE_BSP_HAS_MMU_SUPPORT                (1)

#define BSP_FEATURE_BSP_HAS_MIPI_DSI                   (1U)

#define BSP_FEATURE_BSP_HAS_SRC                        (1U)

#define BSP_FEATURE_CPG_HAS_ICLK                       (1U)
#define BSP_FEATURE_CPG_HAS_SD0CLK                     (1U)
#define BSP_FEATURE_CPG_HAS_SD1CLK                     (0U)
#define BSP_FEATURE_CPG_HAS_P0CLK                      (1U)
#define BSP_FEATURE_CPG_HAS_P1CLK                      (1U)
#define BSP_FEATURE_CPG_HAS_P2CLK                      (1U)
#define BSP_FEATURE_CPG_HAS_I2CLK                      (1U)
#define BSP_FEATURE_CPG_HAS_M3CLK                      (1U)
#define BSP_FEATURE_CPG_HAS_HPCLK                      (0U)
#define BSP_FEATURE_CPG_HAS_OC0CLK                     (0U)
#define BSP_FEATURE_CPG_HAS_OC1CLK                     (0U)
#define BSP_FEATURE_CPG_HAS_PLL5_SOURCE_FOUTPOSTDIV    (1U)

#define BSP_FEATURE_BSP_HAS_ELC                        (0U)

#define BSP_FEATURE_BSP_SUPPORT_PLL5_CONFIG            (1U)
#define BSP_FEATURE_BSP_SUPPORT_OCTAL_MEMORY           (0U)
#define BSP_FEATURE_BSP_SUPPORT_SD_VOLT                (1U)
#define BSP_FEATURE_BSP_SUPPORT_ETHER_VOLT             (0U)
#define BSP_FEATURE_BSP_SUPPORT_ETHER_MODE             (0U)
#define BSP_FEATURE_BSP_SUPPORT_QSPI_VOLT              (1U)
#define BSP_FEATURE_BSP_SUPPORT_XSPI_VOLT              (0U)
#define BSP_FEATURE_BSP_SUPPORT_XSPI_OUTPUT            (0U)
#define BSP_FEATURE_BSP_SUPPORT_I3C                    (0U)
#define BSP_FEATURE_BSP_SUPPORT_BYPASS                 (0U)
#define BSP_FEATURE_BSP_SUPPORT_PFCWE_PROTECT          (1U)
#define BSP_FEATURE_BSP_SUPPORT_OEN_PROTECT            (0U)
#define BSP_FEATURE_BSP_HAS_PFC_OEN_REG                (0U)
#define BSP_FEATURE_BSP_HAS_ETHER_MODE_REG             (0U)
#define BSP_FEATURE_BSP_HAS_SD_CH_POC_REG              (0U)
#define BSP_FEATURE_BSP_HAS_ETH_POC_REG                (0U)
#define BSP_FEATURE_BSP_SD_REG_SIZE_BY_BIT             (32)

#define BSP_FEATURE_DMAC_MAX_CHANNEL                   (16U)
#define BSP_FEATURE_DMAC_64BIT_SYSTEM                  (1U)

#define BSP_FEATURE_GTM_MAX_CHANNELS                   (3U)
#define BSP_FEATURE_GTM_VALID_CHANNEL_MASK             (0x7)

#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK             (0x03)
#define BSP_FEATURE_IIC_REGISTER_SIZE_BY_BIT           (32)

#define BSP_FEATURE_INTC_IRQ_VALID_CHANNEL_MASK        (0xFFU)
#define BSP_FEATURE_INTC_TINT_VALID_CHANNEL_MASK       (0xFFFFFFFFU)

#define BSP_FEATURE_IOPORT_SUPPORT_SR_REG              (1U)
#define BSP_FEATURE_IOPORT_SUPPORT_PUPD_SP             (1U)
#define BSP_FEATURE_IOPORT_SUPPORT_IEN_GP              (1U)
#define BSP_FEATURE_IOPORT_GP_REG_BASE_NUM             01
#define BSP_FEATURE_IOPORT_REG_POSTFIX_L               _L
#define BSP_FEATURE_IOPORT_SP_REG_BASE_NUM             2
#define BSP_FEATURE_IOPORT_FIL_SP_REG_BASE_NUM         00
#define BSP_FEATURE_IOPORT_IEN_SP_REG_BASE_NUM         02
#define BSP_FEATURE_IOPORT_IEN_GP_REG_BASE_NUM         04
#define BSP_FEATURE_IOPORT_IOLH_SP_REG_BASE_NUM        02
#define BSP_FEATURE_IOPORT_SR_SP_REG_BASE_NUM          02
#define BSP_FEATURE_IOPORT_PUPD_SP_REG_BASE_NUM        05

#define BSP_FEATURE_IRDA_MAX_CHANNELS                  (1U)

#define BSP_FEATURE_LCDC_MAX_CHANNELS                  (1U)

#define BSP_FEATURE_MTU3_VALID_CHANNEL_MASK            (0x01FF)
#define BSP_FEATURE_MTU3_MAX_CHANNELS                  (9U)
#define BSP_FEATURE_MTU3_UVW_MAX_CHANNELS              (3U)

#define BSP_FEATURE_RIIC_MAX_CHANNELS                  (2U)

#define BSP_FEATURE_RSPI_VALID_CHANNELS_MASK           (0x3)
#define BSP_FEATURE_RSPI_CLOCK                         (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_RSPI_MAX_CHANNELS                  (2U)
#define BSP_FEATURE_RSPI_CLK_MAX_DIV                   (4096U)
#define BSP_FEATURE_RSPI_CLK_MIN_DIV                   (4U)

#define BSP_FEATURE_SDHI_VALID_CHANNEL_MASK            (0x1)
#define BSP_FEATURE_SDHI_MAX_CHANNELS                  (1U)
#define BSP_FEATURE_SDHI_MIN_CLOCK_DIVISION_SHIFT      (0U)
#define BSP_FEATURE_SDHI_HAS_CARD_DETECTION            (1U)

#define BSP_FEATURE_SCI_CHANNELS                       (0x03U)
#define BSP_FEATURE_SCI_UART_CSTPEN_CHANNELS           (0U)
#define BSP_FEATURE_SCI_CLOCK                          (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_SCI_MAX_CHANNELS                   (2U)

#define BSP_FEATURE_SCIF_CHANNELS                      (0x1FU)
#define BSP_FEATURE_SCIF_CHANNELS_HAS_RTSCTS           (0x07U)
#define BSP_FEATURE_SCIF_CLOCK                         (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_SCIF_MAX_CHANNELS                  (5U)

#define BSP_FEATURE_SSI_FIFO_NUM_STAGES                (32U)
#define BSP_FEATURE_SSI_VALID_CHANNEL_MASK             (0x01U)
#define BSP_FEATURE_SSI_MAX_CHANNELS                   (1U)

#define BSP_FEATURE_TSU_MAX_CHANNELS                   (1U)

#define BSP_FEATURE_WDT_MAX_CHANNELS                   (1U)

#define BSP_FEATURE_TZ_HAS_TRUSTZONE                   (0U)

#endif                                 /* BSP_FEATURE_H */
