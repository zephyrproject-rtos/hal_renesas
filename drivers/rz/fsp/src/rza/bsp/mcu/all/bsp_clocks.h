/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_CLOCKS_H
#define BSP_CLOCKS_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_clock_cfg.h"
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Start clock supply
 *
 * @param      ip       fsp_ip_t enum value for the clock is supplied.
 * @param      channel  The channel. Use ch 0 for ips without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_CLKON(ip, channel)             {FSP_CRITICAL_SECTION_DEFINE;                                        \
                                                     FSP_CRITICAL_SECTION_ENTER;                                         \
                                                     BSP_CLKON_REG_ ## ip(channel) = 0x00000000U                         \
                                                                                     | (BSP_CLKON_BIT_ ## ip(channel) << \
                                                                                        16U)                             \
                                                                                     | (BSP_CLKON_BIT_ ## ip(channel));  \
                                                     while ((BSP_CLKMON_REG_ ## ip(channel) &                            \
                                                             BSP_CLKMON_BIT_ ## ip(channel)) == 0U)                      \
                                                     { /* wait */};                                                      \
                                                     FSP_CRITICAL_SECTION_EXIT;}

/*******************************************************************************************************************//**
 * Stop clock supply
 *
 * @param      ip       fsp_ip_t enum value for the ip to stop clock.
 * @param      channel  The channel. Use ch 0 for ips without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_CLKOFF(ip, channel)            {FSP_CRITICAL_SECTION_DEFINE;                                        \
                                                     FSP_CRITICAL_SECTION_ENTER;                                         \
                                                     BSP_CLKON_REG_ ## ip(channel) = 0x00000000U                         \
                                                                                     | (BSP_CLKON_BIT_ ## ip(channel) << \
                                                                                        16U);                            \
                                                     while ((BSP_CLKMON_REG_ ## ip(channel) &                            \
                                                             BSP_CLKMON_BIT_ ## ip(channel)) != 0U)                      \
                                                     { /* wait */};                                                      \
                                                     FSP_CRITICAL_SECTION_EXIT;}

/*******************************************************************************************************************//**
 * Reset ip
 *
 * @param      ip       fsp_ip_t enum value for the ip to be reset.
 * @param      channel  The channel. Use ch 0 for ips without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_RSTON(ip, channel)             {FSP_CRITICAL_SECTION_DEFINE;                                    \
                                                     FSP_CRITICAL_SECTION_ENTER;                                     \
                                                     BSP_RST_REG_ ## ip(channel) = 0x00000000U                       \
                                                                                   | (BSP_RST_BIT_ ## ip(channel) << \
                                                                                      16U);                          \
                                                     FSP_CRITICAL_SECTION_EXIT;}

/*******************************************************************************************************************//**
 * Reset ip
 *
 * @param      ip       fsp_ip_t enum value for the ip to be reset.
 * @param      channel  The channel. Use ch 0 for ips without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_RSTOFF(ip, channel)            {FSP_CRITICAL_SECTION_DEFINE;                                    \
                                                     FSP_CRITICAL_SECTION_ENTER;                                     \
                                                     BSP_RST_REG_ ## ip(channel) = 0x00000000U                       \
                                                                                   | (BSP_RST_BIT_ ## ip(channel) << \
                                                                                      16U)                           \
                                                                                   | (BSP_RST_BIT_ ## ip(channel));  \
                                                     while ((BSP_RSTMON_REG_ ## ip(channel) &                        \
                                                             BSP_RSTMON_BIT_ ## ip(channel)) != 0U)                  \
                                                     { /* wait */};                                                  \
                                                     FSP_CRITICAL_SECTION_EXIT;}

/** @} (end addtogroup BSP_MCU) */

#define BSP_CLKON_REG_FSP_IP_ADC(channel)           (R_CPG->CPG_CLKON_ADC)
#define BSP_CLKON_BIT_FSP_IP_ADC(channel)           (3U << (R_CPG_CPG_CLKON_ADC_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_ADC(channel)          (R_CPG->CPG_CLKMON_ADC)
#define BSP_CLKMON_BIT_FSP_IP_ADC(channel)          (3U << (R_CPG_CPG_CLKMON_ADC_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_ADC(channel)             (R_CPG->CPG_RST_ADC)
#define BSP_RST_BIT_FSP_IP_ADC(channel)             (3U << (R_CPG_CPG_RST_ADC_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_ADC(channel)          (R_CPG->CPG_RSTMON_ADC)
#define BSP_RSTMON_BIT_FSP_IP_ADC(channel)          (3U << (R_CPG_CPG_RSTMON_ADC_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_CANFD(channel)         (R_CPG->CPG_CLKON_CANFD)
#define BSP_CLKON_BIT_FSP_IP_CANFD(channel)         (1U << (R_CPG_CPG_CLKON_CANFD_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_CANFD(channel)        (R_CPG->CPG_CLKMON_CANFD)
#define BSP_CLKMON_BIT_FSP_IP_CANFD(channel)        (1U << (R_CPG_CPG_CLKMON_CANFD_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_CANFD(channel)           (R_CPG->CPG_RST_CANFD)
#define BSP_RST_BIT_FSP_IP_CANFD(channel)           (3U << (R_CPG_CPG_RST_CANFD_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_CANFD(channel)        (R_CPG->CPG_RSTMON_CANFD)
#define BSP_RSTMON_BIT_FSP_IP_CANFD(channel)        (3U << (R_CPG_CPG_RSTMON_CANFD_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_CRU(channel)           (R_CPG->CPG_CLKON_CRU)
#define BSP_CLKON_BIT_FSP_IP_CRU(channel)           (0x1FU << (R_CPG_CPG_CLKON_CRU_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_CRU(channel)          (R_CPG->CPG_CLKMON_CRU)
#define BSP_CLKMON_BIT_FSP_IP_CRU(channel)          (0x1FU << (R_CPG_CPG_CLKMON_CRU_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_CRU(channel)             (R_CPG->CPG_RST_CRU)
#define BSP_RST_BIT_FSP_IP_CRU(channel)             (7U << (R_CPG_CPG_RST_CRU_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_CRU(channel)          (R_CPG->CPG_RSTMON_CRU)
#define BSP_RSTMON_BIT_FSP_IP_CRU(channel)          (7U << (R_CPG_CPG_RSTMON_CRU_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_CST(channel)           (R_CPG->CPG_CLKON_CST)
#define BSP_CLKON_BIT_FSP_IP_CST(channel)           (0x6D7U << (R_CPG_CPG_CLKON_CST_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_CST(channel)          (R_CPG->CPG_CLKMON_CST)
#define BSP_CLKMON_BIT_FSP_IP_CST(channel)          (0x6D7U << (R_CPG_CPG_CLKMON_CST_CLK0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_DMAC_NS(channel)       (R_CPG->CPG_CLKON_DMAC_REG)
#define BSP_CLKON_BIT_FSP_IP_DMAC_NS(channel)       (1U << (R_CPG_CPG_CLKON_DMAC_REG_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_DMAC_NS(channel)      (R_CPG->CPG_CLKMON_DMAC_REG)
#define BSP_CLKMON_BIT_FSP_IP_DMAC_NS(channel)      (1U << (R_CPG_CPG_CLKMON_DMAC_REG_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_DMAC_NS(channel)         (R_CPG->CPG_RST_DMAC)
#define BSP_RST_BIT_FSP_IP_DMAC_NS(channel)         (1U << (R_CPG_CPG_RST_DMAC_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_DMAC_NS(channel)      (R_CPG->CPG_RSTMON_DMAC)
#define BSP_RSTMON_BIT_FSP_IP_DMAC_NS(channel)      (1U << (R_CPG_CPG_RSTMON_DMAC_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_DMAC_S(channel)        (R_CPG->CPG_CLKON_DMAC_REG)
#define BSP_CLKON_BIT_FSP_IP_DMAC_S(channel)        (1U << (R_CPG_CPG_CLKON_DMAC_REG_CLK1_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_DMAC_S(channel)       (R_CPG->CPG_CLKMON_DMAC_REG)
#define BSP_CLKMON_BIT_FSP_IP_DMAC_S(channel)       (1U << (R_CPG_CPG_CLKMON_DMAC_REG_CLK1_MON_Pos))
#define BSP_RST_REG_FSP_IP_DMAC_S(channel)          (R_CPG->CPG_RST_DMAC)
#define BSP_RST_BIT_FSP_IP_DMAC_S(channel)          (1U << (R_CPG_CPG_RST_DMAC_UNIT1_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_DMAC_S(channel)       (R_CPG->CPG_RSTMON_DMAC)
#define BSP_RSTMON_BIT_FSP_IP_DMAC_S(channel)       (1U << (R_CPG_CPG_RSTMON_DMAC_RST1_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_DRW(channel)           (R_CPG->CPG_CLKON_DRW)
#define BSP_CLKON_BIT_FSP_IP_DRW(channel)           (1U << (R_CPG_CPG_CLKON_DRW_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_DRW(channel)          (R_CPG->CPG_CLKMON_DRW)
#define BSP_CLKMON_BIT_FSP_IP_DRW(channel)          (1U << (R_CPG_CPG_CLKMON_DRW_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_DRW(channel)             (R_CPG->CPG_RST_DRW)
#define BSP_RST_BIT_FSP_IP_DRW(channel)             (1U << (R_CPG_CPG_RST_DRW_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_DRW(channel)          (R_CPG->CPG_RSTMON_DRW)
#define BSP_RSTMON_BIT_FSP_IP_DRW(channel)          (1U << (R_CPG_CPG_RSTMON_DRW_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_ETHER(channel)         (R_CPG->CPG_CLKON_ETH)
#define BSP_CLKON_BIT_FSP_IP_ETHER(channel)         (1U << (R_CPG_CPG_CLKON_ETH_CLK0_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_ETHER(channel)        (R_CPG->CPG_CLKMON_ETH)
#define BSP_CLKMON_BIT_FSP_IP_ETHER(channel)        (1U << (R_CPG_CPG_CLKMON_ETH_CLK0_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_ETHER(channel)           (R_CPG->CPG_RST_ETH)
#define BSP_RST_BIT_FSP_IP_ETHER(channel)           (1U << (R_CPG_CPG_RST_ETH_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_ETHER(channel)        (R_CPG->CPG_RSTMON_ETH)
#define BSP_RSTMON_BIT_FSP_IP_ETHER(channel)        (1U << (R_CPG_CPG_RSTMON_ETH_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_GIC(channel)           (R_CPG->CPG_CLKON_GIC600)
#define BSP_CLKON_BIT_FSP_IP_GIC(channel)           (1U << (R_CPG_CPG_CLKON_GIC600_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_GIC(channel)          (R_CPG->CPG_CLKMON_GIC600)
#define BSP_CLKMON_BIT_FSP_IP_GIC(channel)          (1U << (R_CPG_CPG_CLKMON_GIC600_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_GIC(channel)             (R_CPG->CPG_RST_GIC600)
#define BSP_RST_BIT_FSP_IP_GIC(channel)             (1U << (R_CPG_CPG_RST_GIC600_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_GIC(channel)          (R_CPG->CPG_RSTMON_GIC600)
#define BSP_RSTMON_BIT_FSP_IP_GIC(channel)          (1U << (R_CPG_CPG_RSTMON_GIC600_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_GTM(channel)           (R_CPG->CPG_CLKON_GTM)
#define BSP_CLKON_BIT_FSP_IP_GTM(channel)           (1U << (R_CPG_CPG_CLKON_GTM_CLK0_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_GTM(channel)          (R_CPG->CPG_CLKMON_GTM)
#define BSP_CLKMON_BIT_FSP_IP_GTM(channel)          (1U << (R_CPG_CPG_CLKMON_GTM_CLK0_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_GTM(channel)             (R_CPG->CPG_RST_GTM)
#define BSP_RST_BIT_FSP_IP_GTM(channel)             (1U << (R_CPG_CPG_RST_GTM_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_GTM(channel)          (R_CPG->CPG_RSTMON_GTM)
#define BSP_RSTMON_BIT_FSP_IP_GTM(channel)          (1U << (R_CPG_CPG_RSTMON_GTM_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_IA55(channel)          (R_CPG->CPG_CLKON_IA55)
#define BSP_CLKON_BIT_FSP_IP_IA55(channel)          (1U << (R_CPG_CPG_CLKON_IA55_CLK0_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_IA55(channel)         (R_CPG->CPG_CLKMON_IA55)
#define BSP_CLKMON_BIT_FSP_IP_IA55(channel)         (1U << (R_CPG_CPG_CLKMON_IA55_CLK0_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_IA55(channel)            (R_CPG->CPG_RST_IA55)
#define BSP_RST_BIT_FSP_IP_IA55(channel)            (1U << (R_CPG_CPG_RST_IA55_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_IA55(channel)         (R_CPG->CPG_RSTMON_IA55)
#define BSP_RSTMON_BIT_FSP_IP_IA55(channel)         (1U << (R_CPG_CPG_RSTMON_IA55_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_IRDA(channel)          (R_CPG->CPG_CLKON_IRDA)
#define BSP_CLKON_BIT_FSP_IP_IRDA(channel)          (1U << (R_CPG_CPG_CLKON_IRDA_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_IRDA(channel)         (R_CPG->CPG_CLKMON_IRDA)
#define BSP_CLKMON_BIT_FSP_IP_IRDA(channel)         (1U << (R_CPG_CPG_CLKMON_IRDA_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_IRDA(channel)            (R_CPG->CPG_RST_IRDA)
#define BSP_RST_BIT_FSP_IP_IRDA(channel)            (1U << (R_CPG_CPG_RST_IRDA_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_IRDA(channel)         (R_CPG->CPG_RSTMON_IRDA)
#define BSP_RSTMON_BIT_FSP_IP_IRDA(channel)         (1U << (R_CPG_CPG_RSTMON_IRDA_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_ISU(channel)           (R_CPG->CPG_CLKON_ISU)
#define BSP_CLKON_BIT_FSP_IP_ISU(channel)           (3U << (R_CPG_CPG_CLKON_ISU_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_ISU(channel)          (R_CPG->CPG_CLKMON_ISU)
#define BSP_CLKMON_BIT_FSP_IP_ISU(channel)          (3U << (R_CPG_CPG_CLKMON_ISU_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_ISU(channel)             (R_CPG->CPG_RST_ISU)
#define BSP_RST_BIT_FSP_IP_ISU(channel)             (3U << (R_CPG_CPG_RST_ISU_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_ISU(channel)          (R_CPG->CPG_RSTMON_ISU)
#define BSP_RSTMON_BIT_FSP_IP_ISU(channel)          (3U << (R_CPG_CPG_RSTMON_ISU_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_LCDC(channel)          (R_CPG->CPG_CLKON_LCDC)
#define BSP_CLKON_BIT_FSP_IP_LCDC(channel)          (3U << (R_CPG_CPG_CLKON_LCDC_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_LCDC(channel)         (R_CPG->CPG_CLKMON_LCDC)
#define BSP_CLKMON_BIT_FSP_IP_LCDC(channel)         (3U << (R_CPG_CPG_CLKMON_LCDC_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_LCDC(channel)            (R_CPG->CPG_RST_LCDC)
#define BSP_RST_BIT_FSP_IP_LCDC(channel)            (1U << (R_CPG_CPG_RST_LCDC_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_LCDC(channel)         (R_CPG->CPG_RSTMON_LCDC)
#define BSP_RSTMON_BIT_FSP_IP_LCDC(channel)         (1U << (R_CPG_CPG_RSTMON_LCDC_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_MIPI_DSI(channel)      (R_CPG->CPG_CLKON_MIPI_DSI)
#define BSP_CLKON_BIT_FSP_IP_MIPI_DSI(channel)      (0x3FU << (R_CPG_CPG_CLKON_MIPI_DSI_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_MIPI_DSI(channel)     (R_CPG->CPG_CLKMON_MIPI_DSI)
#define BSP_CLKMON_BIT_FSP_IP_MIPI_DSI(channel)     (0x3FU << (R_CPG_CPG_CLKMON_MIPI_DSI_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_MIPI_DSI(channel)        (R_CPG->CPG_RST_MIPI_DSI)
#define BSP_RST_BIT_FSP_IP_MIPI_DSI(channel)        (0x7U << (R_CPG_CPG_RST_MIPI_DSI_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_MIPI_DSI(channel)     (R_CPG->CPG_RSTMON_MIPI_DSI)
#define BSP_RSTMON_BIT_FSP_IP_MIPI_DSI(channel)     (0x7U << (R_CPG_CPG_RSTMON_MIPI_DSI_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_MTU3(channel)          (R_CPG->CPG_CLKON_MTU)
#define BSP_CLKON_BIT_FSP_IP_MTU3(channel)          (1U << (R_CPG_CPG_CLKON_MTU_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_MTU3(channel)         (R_CPG->CPG_CLKMON_MTU)
#define BSP_CLKMON_BIT_FSP_IP_MTU3(channel)         (1U << (R_CPG_CPG_CLKMON_MTU_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_MTU3(channel)            (R_CPG->CPG_RST_MTU)
#define BSP_RST_BIT_FSP_IP_MTU3(channel)            (1U << (R_CPG_CPG_RST_MTU_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_MTU3(channel)         (R_CPG->CPG_RSTMON_MTU)
#define BSP_RSTMON_BIT_FSP_IP_MTU3(channel)         (1U << (R_CPG_CPG_RSTMON_MTU_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_OCTA(channel)          (R_CPG->CPG_CLKON_OCTA)
#define BSP_CLKON_BIT_FSP_IP_OCTA(channel)          (3U << (R_CPG_CPG_CLKON_OCTA_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_OCTA(channel)         (R_CPG->CPG_CLKMON_OCTA)
#define BSP_CLKMON_BIT_FSP_IP_OCTA(channel)         (3U << (R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_OCTA(channel)            (R_CPG->CPG_RST_OCTA)
#define BSP_RST_BIT_FSP_IP_OCTA(channel)            (1U << (R_CPG_CPG_RST_OCTA_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_OCTA(channel)         (R_CPG->CPG_RSTMON_OCTA)
#define BSP_RSTMON_BIT_FSP_IP_OCTA(channel)         (1U << (R_CPG_CPG_RSTMON_OCTA_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_POE3(channel)          (R_CPG->CPG_CLKON_POE3)
#define BSP_CLKON_BIT_FSP_IP_POE3(channel)          (1U << (R_CPG_CPG_CLKON_POE3_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_POE3(channel)         (R_CPG->CPG_CLKMON_POE3)
#define BSP_CLKMON_BIT_FSP_IP_POE3(channel)         (1U << (R_CPG_CPG_CLKMON_POE3_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_POE3(channel)            (R_CPG->CPG_RST_POE3)
#define BSP_RST_BIT_FSP_IP_POE3(channel)            (1U << (R_CPG_CPG_RST_POE3_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_POE3(channel)         (R_CPG->CPG_RSTMON_POE3)
#define BSP_RSTMON_BIT_FSP_IP_POE3(channel)         (1U << (R_CPG_CPG_RSTMON_POE3_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_RIIC(channel)          (R_CPG->CPG_CLKON_I2C)
#define BSP_CLKON_BIT_FSP_IP_RIIC(channel)          (1U << (R_CPG_CPG_CLKON_I2C_CLK0_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_RIIC(channel)         (R_CPG->CPG_CLKMON_I2C)
#define BSP_CLKMON_BIT_FSP_IP_RIIC(channel)         (1U << (R_CPG_CPG_CLKMON_I2C_CLK0_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_RIIC(channel)            (R_CPG->CPG_RST_I2C)
#define BSP_RST_BIT_FSP_IP_RIIC(channel)            (1U << (R_CPG_CPG_RST_I2C_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_RIIC(channel)         (R_CPG->CPG_RSTMON_I2C)
#define BSP_RSTMON_BIT_FSP_IP_RIIC(channel)         (1U << (R_CPG_CPG_RSTMON_I2C_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_RSPI(channel)          (R_CPG->CPG_CLKON_RSPI)
#define BSP_CLKON_BIT_FSP_IP_RSPI(channel)          (1U << (R_CPG_CPG_CLKON_RSPI_CLK0_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_RSPI(channel)         (R_CPG->CPG_CLKMON_RSPI)
#define BSP_CLKMON_BIT_FSP_IP_RSPI(channel)         (1U << (R_CPG_CPG_CLKMON_RSPI_CLK0_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_RSPI(channel)            (R_CPG->CPG_RST_RSPI)
#define BSP_RST_BIT_FSP_IP_RSPI(channel)            (1U << (R_CPG_CPG_RST_RSPI_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_RSPI(channel)         (R_CPG->CPG_RSTMON_RSPI)
#define BSP_RSTMON_BIT_FSP_IP_RSPI(channel)         (1U << (R_CPG_CPG_RSTMON_RSPI_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_SCI(channel)           (R_CPG->CPG_CLKON_SCI)
#define BSP_CLKON_BIT_FSP_IP_SCI(channel)           (1U << (R_CPG_CPG_CLKON_SCI_CLK0_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_SCI(channel)          (R_CPG->CPG_CLKMON_SCI)
#define BSP_CLKMON_BIT_FSP_IP_SCI(channel)          (1U << (R_CPG_CPG_CLKMON_SCI_CLK0_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_SCI(channel)             (R_CPG->CPG_RST_SCI)
#define BSP_RST_BIT_FSP_IP_SCI(channel)             (1U << (R_CPG_CPG_RST_SCI_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_SCI(channel)          (R_CPG->CPG_RSTMON_SCI)
#define BSP_RSTMON_BIT_FSP_IP_SCI(channel)          (1U << (R_CPG_CPG_RSTMON_SCI_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_SCIF(channel)          (R_CPG->CPG_CLKON_SCIF)
#define BSP_CLKON_BIT_FSP_IP_SCIF(channel)          (1U << (R_CPG_CPG_CLKON_SCIF_CLK0_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_SCIF(channel)         (R_CPG->CPG_CLKMON_SCIF)
#define BSP_CLKMON_BIT_FSP_IP_SCIF(channel)         (1U << (R_CPG_CPG_CLKMON_SCIF_CLK0_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_SCIF(channel)            (R_CPG->CPG_RST_SCIF)
#define BSP_RST_BIT_FSP_IP_SCIF(channel)            (1U << (R_CPG_CPG_RST_SCIF_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_SCIF(channel)         (R_CPG->CPG_RSTMON_SCIF)
#define BSP_RSTMON_BIT_FSP_IP_SCIF(channel)         (1U << (R_CPG_CPG_RSTMON_SCIF_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_SDHI(channel)          (R_CPG->CPG_CLKON_SDHI)
#define BSP_CLKON_BIT_FSP_IP_SDHI(channel)          (0xFU << (R_CPG_CPG_CLKON_SDHI_CLK0_ON_Pos + (channel * 4)))
#define BSP_CLKMON_REG_FSP_IP_SDHI(channel)         (R_CPG->CPG_CLKMON_SDHI)
#define BSP_CLKMON_BIT_FSP_IP_SDHI(channel)         (0xFU << (R_CPG_CPG_CLKMON_SDHI_CLK0_MON_Pos + (channel * 4)))
#define BSP_RST_REG_FSP_IP_SDHI(channel)            (R_CPG->CPG_RST_SDHI)
#define BSP_RST_BIT_FSP_IP_SDHI(channel)            (1U << (R_CPG_CPG_RST_SDHI_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_SDHI(channel)         (R_CPG->CPG_RSTMON_SDHI)
#define BSP_RSTMON_BIT_FSP_IP_SDHI(channel)         (1U << (R_CPG_CPG_RSTMON_SDHI_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_SPI_MULTI(channel)     (R_CPG->CPG_CLKON_SPI_MULTI)
#define BSP_CLKON_BIT_FSP_IP_SPI_MULTI(channel)     (3U << (R_CPG_CPG_CLKON_SPI_MULTI_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_SPI_MULTI(channel)    (R_CPG->CPG_CLKMON_SPI_MULTI)
#define BSP_CLKMON_BIT_FSP_IP_SPI_MULTI(channel)    (3U << (R_CPG_CPG_CLKMON_SPI_MULTI_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_SPI_MULTI(channel)       (R_CPG->CPG_RST_SPI)
#define BSP_RST_BIT_FSP_IP_SPI_MULTI(channel)       (1U << (R_CPG_CPG_RST_SPI_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_SPI_MULTI(channel)    (R_CPG->CPG_RSTMON_SPI)
#define BSP_RSTMON_BIT_FSP_IP_SPI_MULTI(channel)    (1U << (R_CPG_CPG_RSTMON_SPI_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_SRC(channel)           (R_CPG->CPG_CLKON_SRC)
#define BSP_CLKON_BIT_FSP_IP_SRC(channel)           (1U << (R_CPG_CPG_CLKON_SRC_CLK0_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_SRC(channel)          (R_CPG->CPG_CLKMON_SRC)
#define BSP_CLKMON_BIT_FSP_IP_SRC(channel)          (1U << (R_CPG_CPG_CLKMON_SRC_CLK0_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_SRC(channel)             (R_CPG->CPG_RST_SRC)
#define BSP_RST_BIT_FSP_IP_SRC(channel)             (1U << (R_CPG_CPG_RST_SRC_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_SRC(channel)          (R_CPG->CPG_RSTMON_SRC)
#define BSP_RSTMON_BIT_FSP_IP_SRC(channel)          (1U << (R_CPG_CPG_RSTMON_SRC_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_SSI(channel)           (R_CPG->CPG_CLKON_SSI)
#define BSP_CLKON_BIT_FSP_IP_SSI(channel)           (3U << (R_CPG_CPG_CLKON_SSI_CLK0_ON_Pos + (channel * 2)))
#define BSP_CLKMON_REG_FSP_IP_SSI(channel)          (R_CPG->CPG_CLKMON_SSI)
#define BSP_CLKMON_BIT_FSP_IP_SSI(channel)          (3U << (R_CPG_CPG_CLKMON_SSI_CLK0_MON_Pos + (channel * 2)))
#define BSP_RST_REG_FSP_IP_SSI(channel)             (R_CPG->CPG_RST_SSIF)
#define BSP_RST_BIT_FSP_IP_SSI(channel)             (1U << (R_CPG_CPG_RST_SSIF_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_SSI(channel)          (R_CPG->CPG_RSTMON_SSIF)
#define BSP_RSTMON_BIT_FSP_IP_SSI(channel)          (1U << (R_CPG_CPG_RSTMON_SSIF_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_TSU(channel)           (R_CPG->CPG_CLKON_TSU)
#define BSP_CLKON_BIT_FSP_IP_TSU(channel)           (1U << (R_CPG_CPG_CLKON_TSU_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_TSU(channel)          (R_CPG->CPG_CLKMON_TSU)
#define BSP_CLKMON_BIT_FSP_IP_TSU(channel)          (1U << (R_CPG_CPG_CLKMON_TSU_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_TSU(channel)             (R_CPG->CPG_RST_TSU)
#define BSP_RST_BIT_FSP_IP_TSU(channel)             (1U << (R_CPG_CPG_RST_TSU_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_TSU(channel)          (R_CPG->CPG_RSTMON_TSU)
#define BSP_RSTMON_BIT_FSP_IP_TSU(channel)          (1U << (R_CPG_CPG_RSTMON_TSU_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_USB0(channel)          (R_CPG->CPG_CLKON_USB)
#define BSP_CLKON_BIT_FSP_IP_USB0(channel)          (5U << (R_CPG_CPG_CLKON_USB_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_USB0(channel)         (R_CPG->CPG_CLKMON_USB)
#define BSP_CLKMON_BIT_FSP_IP_USB0(channel)         (5U << (R_CPG_CPG_CLKMON_USB_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_USB0(channel)            (R_CPG->CPG_RST_USB)
#define BSP_RST_BIT_FSP_IP_USB0(channel)            (5U << (R_CPG_CPG_RST_USB_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_USB0(channel)         (R_CPG->CPG_RSTMON_USB)
#define BSP_RSTMON_BIT_FSP_IP_USB0(channel)         (5U << (R_CPG_CPG_RSTMON_USB_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_USB1(channel)          (R_CPG->CPG_CLKON_USB)
#define BSP_CLKON_BIT_FSP_IP_USB1(channel)          (1U << (R_CPG_CPG_CLKON_USB_CLK1_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_USB1(channel)         (R_CPG->CPG_CLKMON_USB)
#define BSP_CLKMON_BIT_FSP_IP_USB1(channel)         (1U << (R_CPG_CPG_CLKMON_USB_CLK1_MON_Pos))
#define BSP_RST_REG_FSP_IP_USB1(channel)            (R_CPG->CPG_RST_USB)
#define BSP_RST_BIT_FSP_IP_USB1(channel)            (1U << (R_CPG_CPG_RST_USB_UNIT1_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_USB1(channel)         (R_CPG->CPG_RSTMON_USB)
#define BSP_RSTMON_BIT_FSP_IP_USB1(channel)         (1U << (R_CPG_CPG_RSTMON_USB_RST1_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_USBPHY(channel)        (R_CPG->CPG_CLKON_USB)
#define BSP_CLKON_BIT_FSP_IP_USBPHY(channel)        (1U << (R_CPG_CPG_CLKON_USB_CLK3_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_USBPHY(channel)       (R_CPG->CPG_CLKMON_USB)
#define BSP_CLKMON_BIT_FSP_IP_USBPHY(channel)       (1U << (R_CPG_CPG_CLKMON_USB_CLK3_MON_Pos))
#define BSP_RST_REG_FSP_IP_USBPHY(channel)          (R_CPG->CPG_RST_USB)
#define BSP_RST_BIT_FSP_IP_USBPHY(channel)          (1U << (R_CPG_CPG_RST_USB_UNIT3_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_USBPHY(channel)       (R_CPG->CPG_RSTMON_USB)
#define BSP_RSTMON_BIT_FSP_IP_USBPHY(channel)       (1U << (R_CPG_CPG_RSTMON_USB_RST3_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_WDT(channel)           (R_CPG->CPG_CLKON_WDT)
#define BSP_CLKON_BIT_FSP_IP_WDT(channel)           (3U << (R_CPG_CPG_CLKON_WDT_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_WDT(channel)          (R_CPG->CPG_CLKMON_WDT)
#define BSP_CLKMON_BIT_FSP_IP_WDT(channel)          (3U << (R_CPG_CPG_CLKMON_WDT_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_WDT(channel)             (R_CPG->CPG_RST_WDT)
#define BSP_RST_BIT_FSP_IP_WDT(channel)             (1U << (R_CPG_CPG_RST_WDT_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_WDT(channel)          (R_CPG->CPG_RSTMON_WDT)
#define BSP_RSTMON_BIT_FSP_IP_WDT(channel)          (1U << (R_CPG_CPG_RSTMON_WDT_RST0_MON_Pos))

/* CPG_PL1_DDIV.DIVPL1_SET options. */
#define BSP_CLOCKS_PL1_DIV_1                        (0)  // Divide ICLK source clock by 1
#define BSP_CLOCKS_PL1_DIV_2                        (1)  // Divide ICLK source clock by 2
#define BSP_CLOCKS_PL1_DIV_4                        (2)  // Divide ICLK source clock by 4
#define BSP_CLOCKS_PL1_DIV_8                        (3)  // Divide ICLK source clock by 8

/* CPG_PL2_DDIV.DIVPL2A_SET options. */
#define BSP_CLOCKS_PL2A_DIV_1                       (0)  // Divide P0CLK source clock by 1
#define BSP_CLOCKS_PL2A_DIV_2                       (1)  // Divide P0CLK source clock by 2
#define BSP_CLOCKS_PL2A_DIV_4                       (2)  // Divide P0CLK source clock by 4
#define BSP_CLOCKS_PL2A_DIV_8                       (3)  // Divide P0CLK source clock by 8
#define BSP_CLOCKS_PL2A_DIV_32                      (4)  // Divide P0CLK source clock by 32

/* CPG_PL3A_DDIV.DIVPL3F_SET options. */
#define BSP_CLOCKS_PL3F_DIV_1                       (0)  // Divide OC0CLK source clock by 1
#define BSP_CLOCKS_PL3F_DIV_2                       (1)  // Divide OC0CLK source clock by 2
#define BSP_CLOCKS_PL3F_DIV_4                       (2)  // Divide OC0CLK source clock by 4
#define BSP_CLOCKS_PL3F_DIV_8                       (3)  // Divide OC0CLK source clock by 8
#define BSP_CLOCKS_PL3F_DIV_32                      (4)  // Divide OC0CLK source clock by 32

/* CPG_PL3A_DDIV.DIVPL3C_SET options. */
#define BSP_CLOCKS_PL3C_DIV_1                       (0)  // Divide SPI0CLK source clock by 1
#define BSP_CLOCKS_PL3C_DIV_2                       (1)  // Divide SPI0CLK source clock by 2
#define BSP_CLOCKS_PL3C_DIV_4                       (2)  // Divide SPI0CLK source clock by 4
#define BSP_CLOCKS_PL3C_DIV_8                       (3)  // Divide SPI0CLK source clock by 8
#define BSP_CLOCKS_PL3C_DIV_32                      (4)  // Divide SPI0CLK source clock by 32

/* CPG_PL3A_DDIV.DIVPL3B_SET options. */
#define BSP_CLOCKS_PL3B_DIV_1                       (0)  // Divide P1CLK source clock by 1
#define BSP_CLOCKS_PL3B_DIV_2                       (1)  // Divide P1CLK source clock by 2
#define BSP_CLOCKS_PL3B_DIV_4                       (2)  // Divide P1CLK source clock by 4
#define BSP_CLOCKS_PL3B_DIV_8                       (3)  // Divide P1CLK source clock by 8
#define BSP_CLOCKS_PL3B_DIV_32                      (4)  // Divide P1CLK source clock by 32

/* CPG_PL3A_DDIV.DIVPL3A_SET options. */
#define BSP_CLOCKS_PL3A_DIV_1                       (0)  // Divide P2CLK source clock by 1
#define BSP_CLOCKS_PL3A_DIV_2                       (1)  // Divide P2CLK source clock by 2
#define BSP_CLOCKS_PL3A_DIV_4                       (2)  // Divide P2CLK source clock by 4
#define BSP_CLOCKS_PL3A_DIV_8                       (3)  // Divide P2CLK source clock by 8
#define BSP_CLOCKS_PL3A_DIV_32                      (4)  // Divide P2CLK source clock by 32

/* CPG_PL3B_DDIV.DIVPL3CLK200FIX_SET options. */
#define BSP_CLOCKS_PL3CLK200FIX_DIV_1               (0)  // Divide I2CLK source clock by 1
#define BSP_CLOCKS_PL3CLK200FIX_DIV_2               (1)  // Divide I2CLK source clock by 2
#define BSP_CLOCKS_PL3CLK200FIX_DIV_4               (2)  // Divide I2CLK source clock by 4
#define BSP_CLOCKS_PL3CLK200FIX_DIV_8               (3)  // Divide I2CLK source clock by 8
#define BSP_CLOCKS_PL3CLK200FIX_DIV_32              (4)  // Divide I2CLK source clock by 32

/* CPG_PL5_SDIV.DIVDSIA_SET options. */
#define BSP_CLOCKS_DSIA_DIV_1                       (0)  // Divide PLL5 clock by 1
#define BSP_CLOCKS_DSIA_DIV_2                       (1)  // Divide PLL5 clock by 2
#define BSP_CLOCKS_DSIA_DIV_4                       (2)  // Divide PLL5 clock by 4
#define BSP_CLOCKS_DSIA_DIV_8                       (3)  // Divide PLL5 clock by 8

/* CPG_PL5_SDIV.DIVDSIB_SET options. */
#define BSP_CLOCKS_DSIB_DIV_1                       (0)  // Divide clock from DSI_A by 1
#define BSP_CLOCKS_DSIB_DIV_2                       (1)  // Divide clock from DSI_A by 2
#define BSP_CLOCKS_DSIB_DIV_3                       (2)  // Divide clock from DSI_A by 3
#define BSP_CLOCKS_DSIB_DIV_4                       (3)  // Divide clock from DSI_A by 4
#define BSP_CLOCKS_DSIB_DIV_5                       (4)  // Divide clock from DSI_A by 5
#define BSP_CLOCKS_DSIB_DIV_6                       (5)  // Divide clock from DSI_A by 6
#define BSP_CLOCKS_DSIB_DIV_7                       (6)  // Divide clock from DSI_A by 7
#define BSP_CLOCKS_DSIB_DIV_8                       (7)  // Divide clock from DSI_A by 8
#define BSP_CLOCKS_DSIB_DIV_9                       (8)  // Divide clock from DSI_A by 9
#define BSP_CLOCKS_DSIB_DIV_10                      (9)  // Divide clock from DSI_A by 10
#define BSP_CLOCKS_DSIB_DIV_11                      (10) // Divide clock from DSI_A by 11
#define BSP_CLOCKS_DSIB_DIV_12                      (11) // Divide clock from DSI_A by 12
#define BSP_CLOCKS_DSIB_DIV_13                      (12) // Divide clock from DSI_A by 13
#define BSP_CLOCKS_DSIB_DIV_14                      (13) // Divide clock from DSI_A by 14
#define BSP_CLOCKS_DSIB_DIV_15                      (14) // Divide clock from DSI_A by 15
#define BSP_CLOCKS_DSIB_DIV_16                      (15) // Divide clock from DSI_A by 16

/* CPG_PL2SDHI_DSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_PLL2_533            (1)  // Select 533MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL2_400            (2)  // Select 400MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL2_266            (3)  // Select 266MHz

/* CPG_PL3_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_PLL3_533            (0)  // Select 533MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL3_400            (1)  // Select 400MHz

/* CPG_PL4_DSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_OSC_0024            (0)  // Select OSC/1000 clock (0.024MHz)
#define BSP_CLOCKS_SOURCE_CLOCK_PLL4_1600           (1)  // Select PLL4 clock (1600MHz)

/* CPG_PL5_SEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_PLL5_FOUTPOSTDIV    (0)  // Select PLL5 clock (0 ~ 3000MHz)
#define BSP_CLOCKS_SOURCE_CLOCK_PLL5_FOUT1PH0       (1)  // Select PLL5 clock (1/2 FOUTPOSTDIV)

/* CPG_PL6_ETH_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_PLL6_250            (0)  // Select PLL6 clock (250MHz)
#define BSP_CLOCKS_SOURCE_CLOCK_PLL5_250            (1)  // Select PLL5 clock (250MHz)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if BSP_TZ_SECURE_BUILD || BSP_TZ_NONSECURE_BUILD
typedef struct
{
    uint32_t pll_freq;
} bsp_clock_update_callback_args_t;

 #if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * bsp_clock_update_callback_t)(bsp_clock_update_callback_args_t *
                                                                     p_callback_args);
 #elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile bsp_clock_update_callback_t)(bsp_clock_update_callback_args_t *
                                                                             p_callback_args);
 #endif

#endif

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void bsp_clock_off(void);

/* Public functions defined in bsp_clocks.c */
void      bsp_clock_init(void);                                                   // Used internally by BSP
fsp_err_t bsp_prv_clock_selector_set(fsp_priv_clock_t clock, uint32_t clock_sel); // Used internally by BSP
fsp_err_t bsp_prv_clock_divider_set(fsp_priv_clock_t clock, uint32_t clock_div);  // Used internally by BSP

#if BSP_TZ_NONSECURE_BUILD
void bsp_clock_freq_var_init(void);                                               // Used internally by BSP

#endif

#if BSP_TZ_SECURE_BUILD
void r_bsp_clock_update_callback_set(bsp_clock_update_callback_t        p_callback,
                                     bsp_clock_update_callback_args_t * p_callback_memory);

#endif

/* Used internally by CGC */

#if !BSP_CFG_USE_LOW_VOLTAGE_MODE
void bsp_prv_operating_mode_set(uint8_t operating_mode);

#endif

#if BSP_FEATURE_LPM_CHANGE_MSTP_REQUIRED
uint32_t bsp_prv_power_change_mstp_set(void);
void     bsp_prv_power_change_mstp_clear(uint32_t mstp_clear_bitmask);

#endif

void bsp_prv_prepare_pll(uint32_t pll_freq_hz);
void bsp_prv_clock_set(uint32_t clock, uint32_t sckdivcr);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
