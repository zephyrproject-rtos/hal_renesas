/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_CLOCKS_DRIVER_H
#define BSP_CLOCKS_DRIVER_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Key code protection value */
#define BSP_PRV_KEYCODE_DISABLE           0xA5A5A500U                                     ///< Key code protection disable value
#define BSP_PRV_KEYCODE_ENABLE            0xA5A5A501U                                     ///< Key code protection enable value

/** Clock system (Hz) */
#define BSP_CLOCK_SYSTEM_800MHz           (800000000U) /* PRQA S 1534 # Advisory R-2.5 */ ///< System clock 800 MHz
#define BSP_CLOCK_SYSTEM_640MHz           (640000000U) /* PRQA S 1534 # Advisory R-2.5 */ ///< System clock 640 MHz
#define BSP_CLOCK_SYSTEM_480MHz           (480000000U)                                    ///< System clock 480 MHz

/** Clock system divider */
#define BSP_CLOCK_DIVIDED_BY_2_DIV_16     (0x02U) /* PRQA S 1534 # Advisory R-2.5 */      ///< Clock divided by 2 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_3_DIV_16     (0x03U) /* PRQA S 1534 # Advisory R-2.5 */      ///< Clock divided by 3 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_4_DIV_16     (0x04U) /* PRQA S 1534 # Advisory R-2.5 */      ///< Clock divided by 4 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_5_DIV_16     (0x05U) /* PRQA S 1534 # Advisory R-2.5 */      ///< Clock divided by 5 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_6_DIV_16     (0x06U)                                         ///< Clock divided by 6 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_7_DIV_16     (0x07U) /* PRQA S 1534 # Advisory R-2.5 */      ///< Clock divided by 7 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_8_DIV_16     (0x08U)                                         ///< Clock divided by 8 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_9_DIV_16     (0x09U) /* PRQA S 1534 # Advisory R-2.5 */      ///< Clock divided by 9 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_10_DIV_16    (0x0AU)                                         ///< Clock divided by 10 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_11_DIV_16    (0x0BU) /* PRQA S 1534 # Advisory R-2.5 */      ///< Clock divided by 11 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_12_DIV_16    (0x0CU)                                         ///< Clock divided by 12 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_13_DIV_16    (0x0DU) /* PRQA S 1534 # Advisory R-2.5 */      ///< Clock divided by 13 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_14_DIV_16    (0x0EU)                                         ///< Clock divided by 14 (DIV/16)
#define BSP_CLOCK_DIVIDED_BY_15_DIV_16    (0x0FU) /* PRQA S 1534 # Advisory R-2.5 */      ///< Clock divided by 15 (DIV/16)
#define BSP_CLOCK_NO_DIVISION             (0x00U)                                         ///< No division

/** MOSC (Main Oscillator) */ /* PRQA S 2053 # Advisory D-4.4 */
#define BSP_CLKCTL_CLK_MOSC_40MHZ         (40000000U)                                     ///< MOSC 40 MHz
#define BSP_CLKCTL_CLK_MOSC_25MHZ         (25000000U)                                     ///< MOSC 25 MHz
#define BSP_CLKCTL_CLK_MOSC_24MHZ         (24000000U)                                     ///< MOSC 24 MHz
#define BSP_CLKCTL_CLK_MOSC_20MHZ         (20000000U)                                     ///< MOSC 20 MHz
#define BSP_CLKCTL_CLK_MOSC_16MHZ         (16000000U)                                     ///< MOSC 16 MHz
#define BSP_CLKCTL_CLK_MOSC_DISABLE       (0U) /* PRQA S 1534 # Advisory R-2.5 */         ///< MOSC disabled

/** PLLCLK */
#define BSP_CKD_PLLS_PLLCLKDSYNC_MASK     (0x01U)                                         ///< PLL clock divide sync mask

/** SSCG */
#define BSP_CLKCTL_CLK_SSCG_480MHZ        (480000000U)                                    ///< SSCG 480 MHz
#define BSP_CLKCTL_CLK_SSCG_640MHZ        (640000000U)                                    ///< SSCG 640 MHz
#define BSP_CLKCTL_CLK_SSCG_800MHZ        (800000000U)                                    ///< SSCG 800 MHz

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU_RH850U2BX
 * @defgroup BSP_CLOCK_U2BX BSP Clock
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Enum used in R_FSP_SystemClockHzGet. */
typedef enum e_fsp_priv_clock          /* PRQA S 1536 # Advisory R-2.4 */
{
    FSP_PRIV_CLOCK_CLK_PLL,            ///< CLK_PLL Clock
    FSP_PRIV_CLOCK_CLK_SSCG,           ///< CLK_SSCG Clock
    FSP_PRIV_CLOCK_CLK_SYS_SSCG,       ///< CLK_SSCG Clock
#if BSP_FEATURE_DFP_IS_AVAILABLE
    FSP_PRIV_CLOCK_CLK_SSCG1,          ///< CLK_SSCG1 Clock
    FSP_PRIV_CLOCK_CLK_SYS_SSCG1,      ///< CLK_SSCG1 Clock
#endif /* #if BSP_FEATURE_DFP_IS_AVAILABLE */ /* PRQA S 2053 # Advisory D-4.4 */
    FSP_PRIV_CLOCK_CLK_SYS_CLEAN,      ///< CLK_SYS_CLEAN Clock
    FSP_PRIV_CLOCK_CLK_HVIOSC,         ///< CLK_HVIOSC Clock
    FSP_PRIV_CLOCK_CLK_LSIOSC,         ///< CLK_LSIOSC Clock
    FSP_PRIV_CLOCK_CLK_HSIOSC,         ///< CLK_HSIOSC Clock
    FSP_PRIV_CLOCK_CLK_IOSC,           ///< CLK_IOSC Clock
    FSP_PRIV_CLOCK_CLK_MOSC,           ///< CLK_MOSC Clock
    FSP_PRIV_CLOCK_CLK_EMG,            ///< CLK_EMG Clock
    FSP_PRIV_CLOCK_CLK_ECMCNT,         ///< CLK_ECMCNT Clock
    FSP_PRIV_CLOCK_EXTCLK0O,           ///< EXTCLK0O Clock
    FSP_PRIV_CLOCK_EXTCLK1O,           ///< EXTCLK1O Clock
    FSP_PRIV_CLOCK_CLK_MSPI,           ///< CLK_MSPI Clock
    FSP_PRIV_CLOCK_CLK_RLIN3,          ///< CLK_RLIN3 Clock
    FSP_PRIV_CLOCK_CLK_CH23_RLIN3,     ///< CLK_CH23_RLIN3 Clock
    FSP_PRIV_CLOCK_CLK_GTM,            ///< CLK_GTM Clock
    FSP_PRIV_CLOCK_CLK_WDTB,           ///< CLK_WDTB Clock
    FSP_PRIV_CLOCK_CLK_CANFD_C,        ///< CLK_CANFD_C Clock
    FSP_PRIV_CLOCK_CLK_CANFD_XIN,      ///< CLK_CANFD_XIN Clock
    FSP_PRIV_CLOCK_CLKC_CPU,           ///< CLKC_CPU Clock
    FSP_PRIV_CLOCK_CLKC_SBUS,          ///< CLKC_SBUS Clock
    FSP_PRIV_CLOCK_CLKC_HBUS,          ///< CLKC_HBUS Clock
    FSP_PRIV_CLOCK_CLKC_UHSB,          ///< CLKC_UHSB Clock
    FSP_PRIV_CLOCK_CLKC_SHSB,          ///< CLKC_SHSB Clock
    FSP_PRIV_CLOCK_CLKC_HSB,           ///< CLKC_HSB Clock
    FSP_PRIV_CLOCK_CLKC_LSB,           ///< CLKC_LSB Clock
    FSP_PRIV_CLOCK_CLK_CPU,            ///< CLK_CPU Clock
    FSP_PRIV_CLOCK_CLK_SBUS,           ///< CLK_SBUS Clock
    FSP_PRIV_CLOCK_CLK_HBUS,           ///< CLK_HBUS Clock
    FSP_PRIV_CLOCK_CLK_UHSB,           ///< CLK_UHSB Clock
    FSP_PRIV_CLOCK_CLK_HSB,            ///< CLK_HSB Clock
    FSP_PRIV_CLOCK_CLK_LSB,            ///< CLK_LSB Clock
    FSP_PRIV_CLOCK_CLKC_SWDT,          ///< CLKC_SWDT Clock
#if BSP_FEATURE_DFP_IS_AVAILABLE
    FSP_PRIV_CLOCK_CLK_DFP,            ///< CLK_DFP Clock
    FSP_PRIV_CLOCK_CLK_DFP_DIV_2,      ///< CLK_DFP_DIV_2 Clock
#endif /* #if BSP_FEATURE_DFP_IS_AVAILABLE */ /* PRQA S 2053 # Advisory D-4.4 */
    FSP_PRIV_CLOCK_NUM,
} fsp_priv_clock_t;

/** @} (end addtogroup BSP_MCU_RH850U2BX) */

/** SSCG register */
typedef struct st_systemclock_sscg_ctl /* PRQA S 1536 # Advisory R-2.4 */
{
    /** Selector Control Register */
    volatile uint32_t CKS_SSCGC;

    /** Selector Status Register */
    volatile uint32_t CKS_SSCGS;
    volatile uint32_t Reserved0[6];    /* PRQA S 1710 # Advisory D-4.5 */

    /** Divider Control Register */
    volatile uint32_t CKD_SSCGC;

    /** Divider Status Register */
    volatile uint32_t CKD_SSCGS;
} st_systemclock_sscg_ctl;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern uint32_t g_clock_freq[FSP_PRIV_CLOCK_NUM];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* Public functions defined in bsp.h */
void     bsp_clock_driver_init(void);
void     bsp_clock_gear_down(void);
uint32_t r_bsp_clock_hz_calculate(fsp_priv_clock_t clock); /* PRQA S 4604 # DP_MSR_R-21.2_UC1 */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_CLOCKS_DRIVER_H */
