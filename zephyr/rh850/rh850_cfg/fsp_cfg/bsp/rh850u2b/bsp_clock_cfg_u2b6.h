/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_CLOCK_CFG_U2B6_H_
#define BSP_CLOCK_CFG_U2B6_H_

#include "bsp_clock_cfg.h"

#ifndef BSP_CFG_CLOCKS_SECURE
 #define BSP_CFG_CLOCKS_SECURE                         (0)
#endif

#ifndef BSP_CFG_CLOCKS_OVERRIDE
 #define BSP_CFG_CLOCKS_OVERRIDE                       (0)
#endif

#ifndef BSP_CFG_CLK_MOSC_VALUE
#define BSP_CFG_CLK_MOSC_VALUE \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(mosc))
#endif

#ifndef BSP_CFG_CLK_MOSC_SELECT_STANDBY_MODE
 #if defined(CONFIG_RH850_CLOCK_MOSC_CONTINUE_IN_STANDBY)
  #define BSP_CFG_CLK_MOSC_SELECT_STANDBY_MODE         (1)                         /* MainOSC-STPM: Continue */
 #else
  #define BSP_CFG_CLK_MOSC_SELECT_STANDBY_MODE         (0)                         /* MainOSC-STPM: Stop */
 #endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_PLL_HZ
#define BSP_CFG_CLOCK_CLK_PLL_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(pll))
#endif

#ifndef BSP_CFG_CLK_PLL_SELECT_STANDBY_MODE
 #if defined(CONFIG_RH850_CLOCK_PLL_CONTINUE_IN_STANDBY)
  #define BSP_CFG_CLK_PLL_SELECT_STANDBY_MODE          (1)                         /* PLL-STPM: Continue */
 #else
  #define BSP_CFG_CLK_PLL_SELECT_STANDBY_MODE          (0)                         /* PLL-STPM: Stop */
 #endif
#endif

#ifndef BSP_CFG_CLK_HSOSC_SELECT_STANDBY_MODE
 #if defined(CONFIG_RH850_CLOCK_HSOSC_CONTINUE_IN_STANDBY)
  #define BSP_CFG_CLK_HSOSC_SELECT_STANDBY_MODE        (1)                         /* HSOSC-STPM: Continue */
 #else
  #define BSP_CFG_CLK_HSOSC_SELECT_STANDBY_MODE        (0)                         /* HSOSC-STPM: Stop */
 #endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_CPU_VALUE
#define BSP_CFG_CLOCK_CLK_CPU_VALUE \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_cpu))
#endif

#ifndef BSP_CFG_CLOCK_CLK_SSCG_HZ
#define BSP_CFG_CLOCK_CLK_SSCG_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(sscg0))
#endif

#ifndef BSP_CFG_CLK_SSCG_MODULATION_MODE
#define BSP_CFG_CLK_SSCG_MODULATION_MODE \
	DT_PROP_OR(DT_NODELABEL(clk_sys_sscg0), modulation_enable, 0)
#endif

#ifndef BSP_CFG_CLK_SSCG_MODULATION_VALUE
#define BSP_CFG_CLK_SSCG_MODULATION_VALUE \
	DT_PROP_OR(DT_NODELABEL(clk_sys_sscg0), modulation_value, 30)
#endif

#ifndef BSP_CFG_CLK_SSCG_MODULATION_DITHERED_RANGE
#define BSP_CFG_CLK_SSCG_MODULATION_DITHERED_RANGE \
	DT_PROP_OR(DT_NODELABEL(clk_sys_sscg0), modulation_dithered_range, 0)
#endif

#ifndef BSP_CFG_CLOCK_CLK_HVIOSC_HZ
#define BSP_CFG_CLOCK_CLK_HVIOSC_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(hviosc))
#endif

#ifndef BSP_CFG_CLOCK_CLK_LSIOSC_HZ
#define BSP_CFG_CLOCK_CLK_LSIOSC_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(lsiosc))
#endif

#ifndef BSP_CFG_CLOCK_CLK_HSIOSC_HZ
#define BSP_CFG_CLOCK_CLK_HSIOSC_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(hsiosc))
#endif

#ifndef BSP_CFG_CLOCK_CLK_MOSC_HZ
#define BSP_CFG_CLOCK_CLK_MOSC_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(mosc))
#endif

#ifndef BSP_CFG_CLOCK_CLK_EMG_SRC
#define BSP_CFG_CLOCK_CLK_EMG_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(clk_emg), clock_source, EMG)
#if (BSP_CFG_CLOCK_CLK_EMG_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLK_EMG_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_EMG_HZ
#define BSP_CFG_CLOCK_CLK_EMG_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_emg))
#endif

#ifndef BSP_CFG_CLOCK_CLK_ECMCNT_HZ
#define BSP_CFG_CLOCK_CLK_ECMCNT_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_ecmcnt))
#endif

#ifndef BSP_CFG_CLOCK_CLK_IOSC_SRC
#define BSP_CFG_CLOCK_CLK_IOSC_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(iosc), clock_source, IOSC)
#if (BSP_CFG_CLOCK_CLK_IOSC_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLK_IOSC_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_IOSC_HZ
#define BSP_CFG_CLOCK_CLK_IOSC_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(iosc))
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK0O_SRC
#define BSP_CFG_CLOCK_EXTCLK0O_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(extclk0), clock_source, EXTCLK)
#if (BSP_CFG_CLOCK_EXTCLK0O_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_EXTCLK0O_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK0O_DIV
#define BSP_CFG_CLOCK_EXTCLK0O_DIV \
	BSP_CLOCK_DT_DIV(DT_NODELABEL(extclk0))
#if (BSP_CFG_CLOCK_EXTCLK0O_DIV) < 0 || (BSP_CFG_CLOCK_EXTCLK0O_DIV) > 0x3ff
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_EXTCLK0O_DIV"
#endif
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK0O_HZ
#define BSP_CFG_CLOCK_EXTCLK0O_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(extclk0))
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK1O_SRC
#define BSP_CFG_CLOCK_EXTCLK1O_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(extclk1), clock_source, EXTCLK)
#if (BSP_CFG_CLOCK_EXTCLK1O_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_EXTCLK1O_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK1O_DIV
#define BSP_CFG_CLOCK_EXTCLK1O_DIV \
	BSP_CLOCK_DT_DIV(DT_NODELABEL(extclk1))
#if (BSP_CFG_CLOCK_EXTCLK1O_DIV) < 0 || (BSP_CFG_CLOCK_EXTCLK1O_DIV) > 0x3ff
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_EXTCLK1O_DIV"
#endif
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK1O_HZ
#define BSP_CFG_CLOCK_EXTCLK1O_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(extclk1))
#endif

#ifndef BSP_CFG_CLOCK_CLK_MSPI_SRC
#define BSP_CFG_CLOCK_CLK_MSPI_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(clk_mspi), clock_source, MSPI)
#if (BSP_CFG_CLOCK_CLK_MSPI_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLK_MSPI_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_MSPI_HZ
#define BSP_CFG_CLOCK_CLK_MSPI_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_mspi))
#endif

#ifndef BSP_CFG_CLOCK_CLK_RLIN3_SRC
#define BSP_CFG_CLOCK_CLK_RLIN3_SRC \
	BSP_CLOCK_DT_RLIN(DT_NODELABEL(clk_rlin3), 0)
#if (BSP_CFG_CLOCK_CLK_RLIN3_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLK_RLIN3_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_RLIN3_HZ
#define BSP_CFG_CLOCK_CLK_RLIN3_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_rlin3))
#endif

#ifndef BSP_CFG_CLOCK_CLK_CH23_RLIN3_SRC
#define BSP_CFG_CLOCK_CLK_CH23_RLIN3_SRC \
	BSP_CLOCK_DT_RLIN(DT_NODELABEL(clk_rlin3_ch23), 0)
#if (BSP_CFG_CLOCK_CLK_CH23_RLIN3_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLK_CH23_RLIN3_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_CH23_RLIN3_HZ
#define BSP_CFG_CLOCK_CLK_CH23_RLIN3_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_rlin3_ch23))
#endif

#ifndef BSP_CFG_CLOCK_CLK_GTM_SRC
#define BSP_CFG_CLOCK_CLK_GTM_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(clk_gtm), clock_source, GTM)
#if (BSP_CFG_CLOCK_CLK_GTM_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLK_GTM_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_GTM_HZ
#define BSP_CFG_CLOCK_CLK_GTM_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_gtm))
#endif

#ifndef BSP_CFG_CLOCK_CLK_WDTB_SRC
#define BSP_CFG_CLOCK_CLK_WDTB_SRC \
	BSP_CLOCK_DT_WDT(DT_NODELABEL(clk_wdtb), 0)
#if (BSP_CFG_CLOCK_CLK_WDTB_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLK_WDTB_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_WDTB_HZ
#define BSP_CFG_CLOCK_CLK_WDTB_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_wdtb))
#endif

#ifndef BSP_CFG_CLOCK_CLK_CANFD_C_SRC
#define BSP_CFG_CLOCK_CLK_CANFD_C_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(clk_canfd_c), clock_source, CANFD)
#if (BSP_CFG_CLOCK_CLK_CANFD_C_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLK_CANFD_C_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_CANFD_C_HZ
#define BSP_CFG_CLOCK_CLK_CANFD_C_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_canfd_c))
#endif

#ifndef BSP_CFG_CLOCK_CLK_CANFD_XIN_SRC
#define BSP_CFG_CLOCK_CLK_CANFD_XIN_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(clk_canfd_xin), clock_source, CAN_XIN)
#if (BSP_CFG_CLOCK_CLK_CANFD_XIN_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLK_CANFD_XIN_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_CANFD_XIN_HZ
#define BSP_CFG_CLOCK_CLK_CANFD_XIN_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_canfd_xin))
#endif

#ifndef BSP_CFG_CLOCK_CKS_CLEANC_SRC
#define BSP_CFG_CLOCK_CKS_CLEANC_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(clk_sys_clean), clock_source, CLEAN)
#if (BSP_CFG_CLOCK_CKS_CLEANC_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CKS_CLEANC_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLKC_CPU_HZ
#define BSP_CFG_CLOCK_CLKC_CPU_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clkc_cpu))
#endif

#ifndef BSP_CFG_CLOCK_CLKC_SBUS_HZ
#define BSP_CFG_CLOCK_CLKC_SBUS_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clkc_sbus))
#endif

#ifndef BSP_CFG_CLOCK_CLKC_HBUS_HZ
#define BSP_CFG_CLOCK_CLKC_HBUS_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clkc_hbus))
#endif

#ifndef BSP_CFG_CLOCK_CLKC_UHSB_HZ
#define BSP_CFG_CLOCK_CLKC_UHSB_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clkc_uhsb))
#endif

#ifndef BSP_CFG_CLOCK_CLKC_SHSB_HZ
#define BSP_CFG_CLOCK_CLKC_SHSB_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clkc_shsb))
#endif

#ifndef BSP_CFG_CLOCK_CLKC_HSB_HZ
#define BSP_CFG_CLOCK_CLKC_HSB_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clkc_hsb))
#endif

#ifndef BSP_CFG_CLOCK_CLKC_LSB_HZ
#define BSP_CFG_CLOCK_CLKC_LSB_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clkc_lsb))
#endif

#ifndef BSP_CFG_CLOCK_CKS_SSCGC_SRC
#define BSP_CFG_CLOCK_CKS_SSCGC_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(clk_sys_sscg0), clock_source, SSCG)
#if (BSP_CFG_CLOCK_CKS_SSCGC_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CKS_SSCGC_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_SYS_SSCG_HZ
#define BSP_CFG_CLOCK_CLK_SYS_SSCG_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_sys_sscg0))
#endif

#ifndef BSP_CFG_CLOCK_CLK_CPU_HZ
#define BSP_CFG_CLOCK_CLK_CPU_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_cpu))
#endif

#ifndef BSP_CFG_CLOCK_CLK_SBUS_HZ
#define BSP_CFG_CLOCK_CLK_SBUS_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_sbus))
#endif

#ifndef BSP_CFG_CLOCK_CLK_HBUS_HZ
#define BSP_CFG_CLOCK_CLK_HBUS_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_hbus))
#endif

#ifndef BSP_CFG_CLOCK_CLK_UHSB_HZ
#define BSP_CFG_CLOCK_CLK_UHSB_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_uhsb))
#endif

#ifndef BSP_CFG_CLOCK_CLK_HSB_HZ
#define BSP_CFG_CLOCK_CLK_HSB_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_hsb))
#endif

#ifndef BSP_CFG_CLOCK_CLK_LSB_HZ
#define BSP_CFG_CLOCK_CLK_LSB_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_lsb))
#endif

#ifndef BSP_CFG_CLOCK_CLKC_SWDT_SRC
#define BSP_CFG_CLOCK_CLKC_SWDT_SRC \
	BSP_CLOCK_DT_SOURCE(DT_NODELABEL(clk_swdt), clock_source, SWDT)
#if (BSP_CFG_CLOCK_CLKC_SWDT_SRC) < 0
#error "Invalid Devicetree clock configuration: BSP_CFG_CLOCK_CLKC_SWDT_SRC"
#endif
#endif

#ifndef BSP_CFG_CLOCK_CLKC_SWDT_HZ
#define BSP_CFG_CLOCK_CLKC_SWDT_HZ \
	BSP_CLOCK_DT_HZ(DT_NODELABEL(clk_swdt))
#endif

#endif /* BSP_CLOCK_CFG_U2B6_H_ */
