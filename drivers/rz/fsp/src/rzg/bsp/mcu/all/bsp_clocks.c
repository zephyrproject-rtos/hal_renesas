/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_clocks.h"

#if BSP_TZ_NONSECURE_BUILD
 #include "bsp_guard.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* The number of clocks is used to size the g_clock_freq array. */
#define BSP_PRV_NUM_CLOCKS                   (FSP_PRIV_CLOCK_NUM)
#define BSP_PRV_DIVISION_RATIO_2             (2UL)
#define BSP_PRV_DIVISION_RATIO_8             (8UL)
#define BSP_PRV_DIVISION_RATIO_10            (10UL)
#define BSP_PRV_DIVISION_RATIO_100           (100UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_2       (2UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_3       (3UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_4       (4UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_5       (5UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_6       (6UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_7       (7UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_8       (8UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_10      (10UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_1000    (1000UL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
#if defined(BSP_FEATURE_BSP_SYSTEM_CLOCK_HZ_SET_SUPPORT)
static void bsp_prv_clock_pre_setting(fsp_priv_clock_t clock);
static void bsp_prv_clock_post_setting(fsp_priv_clock_t clock);
void        bsp_prv_system_clock_hz_sel_set(fsp_priv_clock_t clock, uint32_t clock_sel);
void        bsp_prv_system_clock_hz_div_set(fsp_priv_clock_t clock, uint32_t clock_div);

#endif
static void bsp_prv_static_mux_control_pre_setting(fsp_priv_clock_selector_t selector, uint32_t clock_status[]);
static void bsp_prv_static_mux_control_post_setting(fsp_priv_clock_selector_t selector, uint32_t clock_status[]);
static void bsp_prv_static_gear_control_pre_setting(fsp_priv_clock_divider_t divider, uint32_t clock_status[]);
static void bsp_prv_static_gear_control_post_setting(fsp_priv_clock_divider_t divider, uint32_t clock_status[]);
static void bsp_prv_clock_frequency_calculation(fsp_priv_clock_t clock);
void        bsp_prv_clock_selector_set(fsp_priv_clock_selector_t selector, uint32_t clock_sel);
void        bsp_prv_clock_divider_set(fsp_priv_clock_divider_t divider, uint32_t clock_div);

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup RZG_BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RZG_RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

/* This array stores the clock frequency of each bus clock. This section of RAM should not be initialized by the C
 * runtime environment. This is initialized and used in bsp_clock_init, which is called before the C runtime
 * environment is initialized. */
static uint32_t g_clock_freq[BSP_PRV_NUM_CLOCKS]  BSP_PLACE_IN_SECTION(BSP_SECTION_NOINIT);

/*******************************************************************************************************************//**
 * Update SystemCoreClock variable based on current clock settings.
 **********************************************************************************************************************/
void SystemCoreClockUpdate (void)
{
    SystemCoreClock = g_clock_freq[BSP_FEATURE_BSP_SYSTEM_CORE_CLOCK];
}

/*******************************************************************************************************************//**
 * Initializes variable to store system clock frequencies.
 **********************************************************************************************************************/
#if BSP_TZ_CFG_INIT_SECURE_ONLY
void bsp_clock_freq_var_init (void)
#else
static void bsp_clock_freq_var_init (void)
#endif
{
#if defined(BSP_CFG_CLOCK_ICLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ICLK] = BSP_CFG_CLOCK_ICLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_I0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I0CLK] = BSP_CFG_CLOCK_I0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_I1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I1CLK] = BSP_CFG_CLOCK_I1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_I2CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I2CLK] = BSP_CFG_CLOCK_I2CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_I3CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I3CLK] = BSP_CFG_CLOCK_I3CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_I4CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I4CLK] = BSP_CFG_CLOCK_I4CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_I5CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I5CLK] = BSP_CFG_CLOCK_I5CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_I6CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I6CLK] = BSP_CFG_CLOCK_I6CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_I7CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I7CLK] = BSP_CFG_CLOCK_I7CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_IC0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_IC0CLK] = BSP_CFG_CLOCK_IC0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_IC1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_IC1CLK] = BSP_CFG_CLOCK_IC1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_IC2CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_IC2CLK] = BSP_CFG_CLOCK_IC2CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_IC3CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_IC3CLK] = BSP_CFG_CLOCK_IC3CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_GCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_GCLK] = BSP_CFG_CLOCK_GCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_S0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_S0CLK] = BSP_CFG_CLOCK_S0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_SPI0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = BSP_CFG_CLOCK_SPI0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_SPI1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK] = BSP_CFG_CLOCK_SPI1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_OC0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] = BSP_CFG_CLOCK_OC0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_OC1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_OC1CLK] = BSP_CFG_CLOCK_OC1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_SDCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SDCLK] = BSP_CFG_CLOCK_SDCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_SD0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SD0CLK] = BSP_CFG_CLOCK_SD0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_SD1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SD1CLK] = BSP_CFG_CLOCK_SD1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_SD2CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SD2CLK] = BSP_CFG_CLOCK_SD2CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_M0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_M0CLK] = BSP_CFG_CLOCK_M0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_M1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_M1CLK] = BSP_CFG_CLOCK_M1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_M2CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_M2CLK] = BSP_CFG_CLOCK_M2CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_M3CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_M3CLK] = BSP_CFG_CLOCK_M3CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_M4CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_M4CLK] = BSP_CFG_CLOCK_M4CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_M5CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_M5CLK] = BSP_CFG_CLOCK_M5CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_M6CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_M6CLK] = BSP_CFG_CLOCK_M6CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_HPCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_HPCLK] = BSP_CFG_CLOCK_HPCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_TSUCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_TSUCLK] = BSP_CFG_CLOCK_TSUCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ZTCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ZTCLK] = BSP_CFG_CLOCK_ZTCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P0CLK] = BSP_CFG_CLOCK_P0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P1CLK] = BSP_CFG_CLOCK_P1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P2CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P2CLK] = BSP_CFG_CLOCK_P2CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P3CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P3CLK] = BSP_CFG_CLOCK_P3CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P4CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P4CLK] = BSP_CFG_CLOCK_P4CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P5CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P5CLK] = BSP_CFG_CLOCK_P5CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P6CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P6CLK] = BSP_CFG_CLOCK_P6CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P7CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P7CLK] = BSP_CFG_CLOCK_P7CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P8CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P8CLK] = BSP_CFG_CLOCK_P8CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P9CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P9CLK] = BSP_CFG_CLOCK_P9CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P10CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P10CLK] = BSP_CFG_CLOCK_P10CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P11CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P11CLK] = BSP_CFG_CLOCK_P11CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P12CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P12CLK] = BSP_CFG_CLOCK_P12CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P13CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P13CLK] = BSP_CFG_CLOCK_P13CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P14CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P14CLK] = BSP_CFG_CLOCK_P14CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P15CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P15CLK] = BSP_CFG_CLOCK_P15CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P16CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P16CLK] = BSP_CFG_CLOCK_P16CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P17CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P17CLK] = BSP_CFG_CLOCK_P17CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P18CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P18CLK] = BSP_CFG_CLOCK_P18CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P19CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P19CLK] = BSP_CFG_CLOCK_P19CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_P20CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_P20CLK] = BSP_CFG_CLOCK_P20CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ADCCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ADCCLK] = BSP_CFG_CLOCK_ADCCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ATCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ATCLK] = BSP_CFG_CLOCK_ATCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_CANCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_CANCLK] = BSP_CFG_CLOCK_CANCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHTX0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHTX0CLK] = BSP_CFG_CLOCK_ETHTX0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHTX1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHTX1CLK] = BSP_CFG_CLOCK_ETHTX1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHRX0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHRX0CLK] = BSP_CFG_CLOCK_ETHRX0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHRX1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHRX1CLK] = BSP_CFG_CLOCK_ETHRX1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHTX01CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHTX01CLK] = BSP_CFG_CLOCK_ETHTX01CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHRX01CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHRX01CLK] = BSP_CFG_CLOCK_ETHRX01CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHRM0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHRM0CLK] = BSP_CFG_CLOCK_ETHRM0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHTX02CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHTX02CLK] = BSP_CFG_CLOCK_ETHTX02CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHRX02CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHRX02CLK] = BSP_CFG_CLOCK_ETHRX02CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHTX11CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHTX11CLK] = BSP_CFG_CLOCK_ETHTX11CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHRX11CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHRX11CLK] = BSP_CFG_CLOCK_ETHRX11CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHRM1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHRM1CLK] = BSP_CFG_CLOCK_ETHRM1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHTX12CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHTX12CLK] = BSP_CFG_CLOCK_ETHTX12CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ETHRX12CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ETHRX12CLK] = BSP_CFG_CLOCK_ETHRX12CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_GPUCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_GPUCLK] = BSP_CFG_CLOCK_GPUCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ISPCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ISPCLK] = BSP_CFG_CLOCK_ISPCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_ISUCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ISUCLK] = BSP_CFG_CLOCK_ISUCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_LPCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_LPCLK] = BSP_CFG_CLOCK_LPCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_NPUCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_NPUCLK] = BSP_CFG_CLOCK_NPUCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_BCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_BCLK] = BSP_CFG_CLOCK_BCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_OSCCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_OSCCLK] = BSP_CFG_CLOCK_OSCCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_OSC2CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_OSC2CLK] = BSP_CFG_CLOCK_OSC2CLK_HZ;
#endif

    /* The SystemCoreClock needs to be updated before calling R_BSP_SoftwareDelay. */
    SystemCoreClockUpdate();
}

/*******************************************************************************************************************//**
 * Initializes system clocks.  Makes no assumptions about current register settings.
 **********************************************************************************************************************/
void bsp_clock_init (void)
{
    bsp_clock_freq_var_init();
}

/*******************************************************************************************************************//**
 * Clock frequency configuration. According to the information specified in the Clocks tab, the divider and clock selector are initialized.
 **********************************************************************************************************************/
void bsp_clock_freq_init_cfg (void)
{
#if BSP_FEATURE_BSP_CLOCK_FREQ_INIT_CFG_SUPPORT

/* If the operation of the PLL has stopped before the clock setting is changed, start the PLL. */
 #if defined(BSP_CFG_CLOCK_PLL1_HZ)
    uint32_t pll1_mon = (R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                        R_CPG->CPG_PLL1_MON;
    if (!pll1_mon)
    {
        R_CPG->CPG_PLL1_STBY = (uint32_t) (R_CPG_CPG_PLL1_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLL1_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                    R_CPG->CPG_PLL1_MON),
                                   (R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLL4_HZ)
    uint32_t pll4_mon = (R_CPG_CPG_PLL4_MON_PLL4_LOCK_Msk | R_CPG_CPG_PLL4_MON_PLL4_RESETB_Msk) &
                        R_CPG->CPG_PLL4_MON;
    if (!pll4_mon)
    {
        R_CPG->CPG_PLL4_STBY = (uint32_t) (R_CPG_CPG_PLL4_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLL4_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLL4_MON_PLL4_LOCK_Msk | R_CPG_CPG_PLL4_MON_PLL4_RESETB_Msk) &
                                    R_CPG->CPG_PLL4_MON),
                                   (R_CPG_CPG_PLL4_MON_PLL4_LOCK_Msk | R_CPG_CPG_PLL4_MON_PLL4_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLL6_HZ)
    uint32_t pll6_mon = (R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                        R_CPG->CPG_PLL6_MON;
    if (!pll6_mon)
    {
        R_CPG->CPG_PLL6_STBY = (uint32_t) (R_CPG_CPG_PLL6_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLL6_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                    R_CPG->CPG_PLL6_MON),
                                   (R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLL7_HZ)
    uint32_t pll7_mon = (R_CPG_CPG_PLL7_MON_PLL7_LOCK_Msk | R_CPG_CPG_PLL7_MON_PLL7_RESETB_Msk) &
                        R_CPG->CPG_PLL7_MON;
    if (!pll7_mon)
    {
        R_CPG->CPG_PLL7_STBY = (uint32_t) (R_CPG_CPG_PLL7_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLL7_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLL7_MON_PLL7_LOCK_Msk | R_CPG_CPG_PLL7_MON_PLL7_RESETB_Msk) &
                                    R_CPG->CPG_PLL7_MON),
                                   (R_CPG_CPG_PLL7_MON_PLL7_LOCK_Msk | R_CPG_CPG_PLL7_MON_PLL7_RESETB_Msk));
    }
 #endif

 #if defined(BSP_CFG_CLOCK_PLLCLNCLK_HZ)
    uint32_t pllcln_mon = (R_CPG_CPG_PLLCLN_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCLN_MON_PLLn_RESETB_Msk) &
                          R_CPG->CPG_PLLCLN_MON;
    if (!pllcln_mon)
    {
        R_CPG->CPG_PLLCLN_STBY = (uint32_t) (R_CPG_CPG_PLLCLN_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLCLN_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLCLN_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCLN_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLCLN_MON),
                                   (R_CPG_CPG_PLLCLN_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCLN_MON_PLLn_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLDTYCLK_HZ)
    uint32_t plldty_mon = (R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) &
                          R_CPG->CPG_PLLDTY_MON;
    if (!plldty_mon)
    {
        R_CPG->CPG_PLLDTY_STBY = (uint32_t) (R_CPG_CPG_PLLDTY_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLDTY_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDTY_MON),
                                   (R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLCA55CLK_HZ)
    uint32_t pllca55_mon = (R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk) &
                           R_CPG->CPG_PLLCA55_MON;
    if (!pllca55_mon)
    {
        R_CPG->CPG_PLLCA55_STBY =
            (uint32_t) (R_CPG_CPG_PLLCA55_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLCA55_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLCA55_MON),
                                   (R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLVDOCLK_HZ)
    uint32_t pllvdo_mon = (R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) &
                          R_CPG->CPG_PLLVDO_MON;
    if (!pllvdo_mon)
    {
        R_CPG->CPG_PLLVDO_STBY = (uint32_t) (R_CPG_CPG_PLLVDO_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLVDO_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLVDO_MON),
                                   (R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLETHCLK_HZ)
    uint32_t plleth_mon = (R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) &
                          R_CPG->CPG_PLLETH_MON;
    if (!plleth_mon)
    {
        R_CPG->CPG_PLLETH_STBY = (uint32_t) (R_CPG_CPG_PLLETH_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLETH_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLETH_MON),
                                   (R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLDSI0CLK_HZ)
    uint32_t plldsi0_mon = (R_CPG_CPG_PLLDSI0_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI0_MON_PLLn_RESETB_Msk) &
                           R_CPG->CPG_PLLDSI0_MON;
    if (!plldsi0_mon)
    {
        R_CPG->CPG_PLLDSI0_STBY =
            (uint32_t) (R_CPG_CPG_PLLDSI0_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLDSI0_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDSI0_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI0_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDSI0_MON),
                                   (R_CPG_CPG_PLLDSI0_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI0_MON_PLLn_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLDSI1CLK_HZ)
    uint32_t plldsi1_mon = (R_CPG_CPG_PLLDSI1_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI1_MON_PLLn_RESETB_Msk) &
                           R_CPG->CPG_PLLDSI1_MON;
    if (!plldsi1_mon)
    {
        R_CPG->CPG_PLLDSI1_STBY =
            (uint32_t) (R_CPG_CPG_PLLDSI1_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLDSI1_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDSI1_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI1_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDSI1_MON),
                                   (R_CPG_CPG_PLLDSI1_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI1_MON_PLLn_RESETB_Msk));
    }
 #endif

/* Set the divider and selector according to the contents of the Clocks tab. */
 #if defined(BSP_CFG_SELPL4_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_PLL4, BSP_CFG_SELPL4_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_SDHI0_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI0, BSP_CFG_SEL_SDHI0_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_SDHI1_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI1, BSP_CFG_SEL_SDHI1_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_SDHI2_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI2, BSP_CFG_SEL_SDHI2_SET_SOURCE);
 #endif

 #if defined(BSP_CFG_SEL_PLL4_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_PLL4, BSP_CFG_SEL_PLL4_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_BSC_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_BSC, BSP_CFG_SEL_BSC_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_XSPI_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_XSPI, BSP_CFG_SEL_XSPI_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_DSI_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_DSI, BSP_CFG_SEL_DSI_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_GE3D_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_GE3D, BSP_CFG_SEL_GE3D_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH0A_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_TX, BSP_CFG_SEL_ETH0A_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH0B_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RX, BSP_CFG_SEL_ETH0B_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH0C_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RM, BSP_CFG_SEL_ETH0C_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH0D_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_TX_I, BSP_CFG_SEL_ETH0D_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH0E_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_RX_I, BSP_CFG_SEL_ETH0E_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH1A_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_TX, BSP_CFG_SEL_ETH1A_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH1B_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RX, BSP_CFG_SEL_ETH1B_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH1C_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RM, BSP_CFG_SEL_ETH1C_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH1D_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_TX_I, BSP_CFG_SEL_ETH1D_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_ETH1E_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_RX_I, BSP_CFG_SEL_ETH1E_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_RSCI0_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI0, BSP_CFG_SEL_RSCI0_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_RSCI1_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI1, BSP_CFG_SEL_RSCI1_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_RSCI2_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI2, BSP_CFG_SEL_RSCI2_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_RSCI3_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI3, BSP_CFG_SEL_RSCI3_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_RSPI0_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI0, BSP_CFG_SEL_RSPI0_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_RSPI1_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI1, BSP_CFG_SEL_RSPI1_SET_SOURCE);
 #endif
 #if defined(BSP_CFG_SEL_RSPI2_SET_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI2, BSP_CFG_SEL_RSPI2_SET_SOURCE);
 #endif

 #if defined(BSP_CFG_SSEL0_SELCTL0_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK1, BSP_CFG_SSEL0_SELCTL0_SOURCE);
 #endif
 #if defined(BSP_CFG_SSEL0_SELCTL1_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK0, BSP_CFG_SSEL0_SELCTL1_SOURCE);
 #endif
 #if defined(BSP_CFG_SSEL0_SELCTL2_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_TXCLK, BSP_CFG_SSEL0_SELCTL2_SOURCE);
 #endif
 #if defined(BSP_CFG_SSEL0_SELCTL3_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_RXCLK, BSP_CFG_SSEL0_SELCTL3_SOURCE);
 #endif
 #if defined(BSP_CFG_SSEL1_SELCTL0_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_TXCLK, BSP_CFG_SSEL1_SELCTL0_SOURCE);
 #endif
 #if defined(BSP_CFG_SSEL1_SELCTL1_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_RXCLK, BSP_CFG_SSEL1_SELCTL1_SOURCE);
 #endif
 #if defined(BSP_CFG_SSEL1_SELCTL2_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK0, BSP_CFG_SSEL1_SELCTL2_SOURCE);
 #endif
 #if defined(BSP_CFG_SSEL1_SELCTL3_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK1, BSP_CFG_SSEL1_SELCTL3_SOURCE);
 #endif
 #if defined(BSP_CFG_SSEL3_SELCTL0_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI0_CLK, BSP_CFG_SSEL3_SELCTL0_SOURCE);
 #endif
 #if defined(BSP_CFG_SSEL3_SELCTL1_SOURCE)
    R_BSP_ClockSelectorSet(FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI1_CLK, BSP_CFG_SSEL3_SELCTL1_SOURCE);
 #endif

 #if defined(BSP_CFG_DIVPL1_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL1, BSP_CFG_DIVPL1_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIVPL2B_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_100, BSP_CFG_DIVPL2B_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIVPL3A_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_200, BSP_CFG_DIVPL3A_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIVPL3B_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_100, BSP_CFG_DIVPL3B_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIVPL3C_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_200MCPU, BSP_CFG_DIVPL3C_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIVPL6A_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIVPL6A, BSP_CFG_DIVPL6A_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIVPL6B_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIVPL6B, BSP_CFG_DIVPL6B_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIVSDHI0_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI0_SEL, BSP_CFG_DIVSDHI0_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIVSDHI1_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI1_SEL, BSP_CFG_DIVSDHI1_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIVSDHI2_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI2_SEL, BSP_CFG_DIVSDHI2_SET_DIV);
 #endif

 #if defined(BSP_CFG_DIV_PLL2_B_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_100, BSP_CFG_DIV_PLL2_B_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_PLL3_A_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_200, BSP_CFG_DIV_PLL3_A_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_PLL3_B_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_100, BSP_CFG_DIV_PLL3_B_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_PLL1_A_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_CA55, BSP_CFG_DIV_PLL1_A_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_PLL2_A_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_200, BSP_CFG_DIV_PLL2_A_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_PLL2_B_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_QSPI, BSP_CFG_DIV_PLL2_B_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_XSPI_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_XSPI, BSP_CFG_DIV_XSPI_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_GE3D_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_GE3D, BSP_CFG_DIV_GE3D_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_DSI_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_CLK266FIXC_DIV16TO128, BSP_CFG_DIV_DSI_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_PDM_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_CLK24_SEL, BSP_CFG_DIV_PDM_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_BSC_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_BSC, BSP_CFG_DIV_BSC_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_CORE0_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE0, BSP_CFG_DIV_CORE0_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_CORE1_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE1, BSP_CFG_DIV_CORE1_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_CORE2_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE2, BSP_CFG_DIV_CORE2_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_CORE3_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE3, BSP_CFG_DIV_CORE3_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_RSCI0_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI0, BSP_CFG_DIV_RSCI0_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_RSCI1_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI1, BSP_CFG_DIV_RSCI1_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_RSCI2_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI2, BSP_CFG_DIV_RSCI2_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_RSCI3_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI3, BSP_CFG_DIV_RSCI3_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_RSPI0_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI0, BSP_CFG_DIV_RSPI0_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_RSPI1_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI1, BSP_CFG_DIV_RSPI1_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_RSPI2_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI2, BSP_CFG_DIV_RSPI2_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_DSI_A_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO32_VCLK, BSP_CFG_DIV_DSI_A_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_DSI_B_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO16_VCLK, BSP_CFG_DIV_DSI_B_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_DSI_C_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO2_LVDS, BSP_CFG_DIV_DSI_C_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_ETH_A_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_TR, BSP_CFG_DIV_ETH_A_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_ETH_B_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_RM, BSP_CFG_DIV_ETH_B_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_ETH_C_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_TR, BSP_CFG_DIV_ETH_C_SET_DIV);
 #endif
 #if defined(BSP_CFG_DIV_ETH_D_SET_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_RM, BSP_CFG_DIV_ETH_D_SET_DIV);
 #endif

 #if defined(BSP_CFG_CDDIV0_DIVCTL0_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLCM33_CST400, BSP_CFG_CDDIV0_DIVCTL0_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV0_DIVCTL1_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLCM33, BSP_CFG_CDDIV0_DIVCTL1_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV0_DIVCTL2_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLDTY_ACPU, BSP_CFG_CDDIV0_DIVCTL2_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV0_DIVCTL3_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLCA55_SCLK, BSP_CFG_CDDIV0_DIVCTL3_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV1_DIVCTL0_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_0, BSP_CFG_CDDIV1_DIVCTL0_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV1_DIVCTL1_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_1, BSP_CFG_CDDIV1_DIVCTL1_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV1_DIVCTL2_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_2, BSP_CFG_CDDIV1_DIVCTL2_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV1_DIVCTL3_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_3, BSP_CFG_CDDIV1_DIVCTL3_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV2_DIVCTL0_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_CA55PERI, BSP_CFG_CDDIV2_DIVCTL0_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV3_DIVCTL1_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLVDO_GPU, BSP_CFG_CDDIV3_DIVCTL1_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV3_DIVCTL2_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLDTY_RCPU, BSP_CFG_CDDIV3_DIVCTL2_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV3_DIVCTL3_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU0, BSP_CFG_CDDIV3_DIVCTL3_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV4_DIVCTL3_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLETH_NPU, BSP_CFG_CDDIV4_DIVCTL3_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV5_DIVCTL0_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLDTY_NPU, BSP_CFG_CDDIV5_DIVCTL0_DIV);
 #endif
 #if defined(BSP_CFG_CSDIV0_DIVCTL0_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE0, BSP_CFG_CSDIV0_DIVCTL0_DIV);
 #endif
 #if defined(BSP_CFG_CSDIV0_DIVCTL1_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE1, BSP_CFG_CSDIV0_DIVCTL1_DIV);
 #endif
 #if defined(BSP_CFG_CSDIV0_DIVCTL2_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLETH_LPCLK, BSP_CFG_CSDIV0_DIVCTL2_DIV);
 #endif
 #if defined(BSP_CFG_CSDIV0_DIVCTL3_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLCM33_XSPI, BSP_CFG_CSDIV0_DIVCTL3_DIV);
 #endif
 #if defined(BSP_CFG_CSDIV1_DIVCTL0_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_PCLK, BSP_CFG_CSDIV1_DIVCTL0_DIV);
 #endif
 #if defined(BSP_CFG_CSDIV1_DIVCTL1_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_ADCLK, BSP_CFG_CSDIV1_DIVCTL1_DIV);
 #endif
 #if defined(BSP_CFG_CSDIV1_DIVCTL2_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLDSI0, BSP_CFG_CSDIV1_DIVCTL2_DIV);
 #endif
 #if defined(BSP_CFG_CSDIV1_DIVCTL3_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLDSI1, BSP_CFG_CSDIV1_DIVCTL3_DIV);
 #endif

/* Stop the operation of the PLL that was temporarily started before changing the settings. */
 #if defined(BSP_CFG_CLOCK_PLL1_HZ)
    if (!pll1_mon)
    {
        R_CPG->CPG_PLL1_STBY = (uint32_t) R_CPG_CPG_PLL1_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                    R_CPG->CPG_PLL1_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLL4_HZ)
    if (!pll4_mon)
    {
        R_CPG->CPG_PLL4_STBY = (uint32_t) R_CPG_CPG_PLL4_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLL4_MON_PLL4_LOCK_Msk | R_CPG_CPG_PLL4_MON_PLL4_RESETB_Msk) &
                                    R_CPG->CPG_PLL4_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLL6_HZ)
    if (!pll6_mon)
    {
        R_CPG->CPG_PLL6_STBY = (uint32_t) R_CPG_CPG_PLL6_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                    R_CPG->CPG_PLL6_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLL7_HZ)
    if (!pll7_mon)
    {
        R_CPG->CPG_PLL7_STBY = (uint32_t) R_CPG_CPG_PLL7_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLL7_MON_PLL7_LOCK_Msk | R_CPG_CPG_PLL7_MON_PLL7_RESETB_Msk) &
                                    R_CPG->CPG_PLL7_MON),
                                   0U);
    }
 #endif

 #if defined(BSP_CFG_CLOCK_PLLCLNCLK_HZ)
    if (!pllcln_mon)
    {
        R_CPG->CPG_PLLCLN_STBY = (uint32_t) R_CPG_CPG_PLLCLN_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLCLN_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCLN_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLCLN_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLDTYCLK_HZ)
    if (!plldty_mon)
    {
        R_CPG->CPG_PLLDTY_STBY = (uint32_t) R_CPG_CPG_PLLDTY_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDTY_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLCA55CLK_HZ)
    if (!pllca55_mon)
    {
        R_CPG->CPG_PLLCA55_STBY = (uint32_t) R_CPG_CPG_PLLCA55_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLCA55_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLVDOCLK_HZ)
    if (!pllvdo_mon)
    {
        R_CPG->CPG_PLLVDO_STBY = (uint32_t) R_CPG_CPG_PLLVDO_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLVDO_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLETHCLK_HZ)
    if (!plleth_mon)
    {
        R_CPG->CPG_PLLETH_STBY = (uint32_t) R_CPG_CPG_PLLETH_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLETH_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLDSI0CLK_HZ)
    if (!plldsi0_mon)
    {
        R_CPG->CPG_PLLDSI0_STBY = (uint32_t) R_CPG_CPG_PLLDSI0_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDSI0_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI0_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDSI0_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLDSI1CLK_HZ)
    if (!plldsi1_mon)
    {
        R_CPG->CPG_PLLDSI1_STBY = (uint32_t) R_CPG_CPG_PLLDSI1_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDSI1_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI1_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDSI1_MON),
                                   0U);
    }
 #endif
#endif
}

#if defined(BSP_FEATURE_BSP_SYSTEM_CLOCK_HZ_SET_SUPPORT)

/*******************************************************************************************************************//**
 * DEPRECATED Perform any necessary processing before changing the frequency.
 *
 * @param[in] clock                    Desired clock
 **********************************************************************************************************************/
static void bsp_prv_clock_pre_setting (fsp_priv_clock_t clock)
{
    FSP_PARAMETER_NOT_USED(clock);
}

/*******************************************************************************************************************//**
 * DEPRECATED Perform any necessary processing after changing the frequency.
 *
 * @param[in] clock                    Desired clock
 **********************************************************************************************************************/
static void bsp_prv_clock_post_setting (fsp_priv_clock_t clock)
{
    FSP_PARAMETER_NOT_USED(clock);
}

/*******************************************************************************************************************//**
 * DEPRECATED Set the Source Clock Setting register to change the frequency.
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of each clock.
 * @param[in]   clock_sel             Value to set in Source Clock Setting register.
 **********************************************************************************************************************/
void bsp_prv_system_clock_hz_sel_set (fsp_priv_clock_t clock, uint32_t clock_sel)
{
    uint32_t clock_freq = g_clock_freq[clock];

    switch (clock)
    {
 #if defined(BSP_CFG_SEL_SDHI0_SET_SOURCE)

        /* Source Clock setting for SDHI0. */
        case FSP_PRIV_CLOCK_SD0CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI0_STS_Msk & R_CPG->CPG_CLKSELSTATUS) >>
                                       R_CPG_CPG_CLKSELSTATUS_SELSDHI0_STS_Pos,
                                       0U);

            R_CPG->CPG_SDHI_DSEL = (uint32_t) (R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Msk &
                                                (clock_sel << R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Pos)));

            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI0_STS_Msk & R_CPG->CPG_CLKSELSTATUS) >>
                                       R_CPG_CPG_CLKSELSTATUS_SELSDHI0_STS_Pos,
                                       0U);

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_800 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_1600_HZ >> 1;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_1600_HZ / 6;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            break;
        }
 #endif                                /* BSP_CFG_SEL_SDHI0_SET_SOURCE */

 #if defined(BSP_CFG_SEL_SDHI1_SET_SOURCE)

        /* Source Clock setting for SDHI1. */
        case FSP_PRIV_CLOCK_SD1CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Msk & R_CPG->CPG_CLKSELSTATUS) >>
                                       R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Pos,
                                       0U);

            R_CPG->CPG_SDHI_DSEL = (uint32_t) (R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Msk &
                                                (clock_sel << R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Pos)));

            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Msk & R_CPG->CPG_CLKSELSTATUS) >>
                                       R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Pos,
                                       0U);

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_800 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_1600_HZ >> 1;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_1600_HZ / 6;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            break;
        }
 #endif                                /* BSP_CFG_SEL_SDHI1_SET_SOURCE */

 #if defined(BSP_CFG_SEL_SDHI2_SET_SOURCE)

        /* Source Clock setting for SDHI2. */
        case FSP_PRIV_CLOCK_SD2CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI2_STS_Msk & R_CPG->CPG_CLKSELSTATUS) >>
                                       R_CPG_CPG_CLKSELSTATUS_SELSDHI2_STS_Pos,
                                       0U);

            R_CPG->CPG_SDHI_DSEL = (uint32_t) (R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Msk &
                                                (clock_sel << R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Pos)));

            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI2_STS_Msk & R_CPG->CPG_CLKSELSTATUS) >>
                                       R_CPG_CPG_CLKSELSTATUS_SELSDHI2_STS_Pos,
                                       0U);

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_800 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_1600_HZ >> 1;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_1600_HZ / 6;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            break;
        }
 #endif                                /* BSP_CFG_SEL_SDHI2_SET_SOURCE */

 #if defined(BSP_CFG_SELSPI_SET_SOURCE)

        /* Source Clock setting for SPI0. */
        case FSP_PRIV_CLOCK_SPI0CLK:
        {
            uint32_t clock_mon = (uint32_t) ((R_CPG_CPG_CLKMON_SPI_CLK3_MON_Msk & R_CPG->CPG_CLKMON_SPI) >>
                                             R_CPG_CPG_CLKMON_SPI_CLK3_MON_Pos);

            /* If SPI_CLKX2 is supplied, the clock stops before setting the Source Clock Setting Register. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_SPI = R_CPG_CPG_CLKON_SPI_CLK3_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_CLK3_MON_Msk & R_CPG->CPG_CLKMON_SPI) >>
                                           R_CPG_CPG_CLKMON_SPI_CLK3_MON_Pos,
                                           0U);
            }

            R_CPG->CPG_SPI_SSEL = (uint32_t) (R_CPG_CPG_SPI_SSEL_SELSPI_WEN_Msk |
                                              (R_CPG_CPG_SPI_SSEL_SELSPI_SET_Msk &
                                               (clock_sel << R_CPG_CPG_SPI_SSEL_SELSPI_SET_Pos)));

            /* If the clock was stopped before setting the Source Clock Setting Register, the clock supply resumes. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_SPI = (uint32_t) (R_CPG_CPG_CLKON_SPI_CLK3_ONWEN_Msk |
                                                   R_CPG_CPG_CLKON_SPI_CLK3_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_CLK3_MON_Msk & R_CPG->CPG_CLKMON_SPI) >>
                                           R_CPG_CPG_CLKMON_SPI_CLK3_MON_Pos,
                                           1U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ / 6;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ >> 1;
            }
            else
            {
                /* If this condition is met, clock_sel is an invalid value. */
                ;
            }

            uint32_t clock_div = (uint32_t) ((R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Msk & R_CPG->CPG_SPI_DDIV) >>
                                             R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Pos);
            if (BSP_CLOCKS_SPI_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 1);

            /* Changing settings for the SPI0 clock related register, SPI1 clock frequency changes at the same time.
             * So it is updated the variable that stored SPI1 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK] = clock_freq >> 1;
            break;
        }

        /* Source Clock setting for SPI1. */
        case FSP_PRIV_CLOCK_SPI1CLK:
        {
            uint32_t clock_mon = (uint32_t) ((R_CPG_CPG_CLKMON_SPI_CLK2_MON_Msk & R_CPG->CPG_CLKMON_SPI) >>
                                             R_CPG_CPG_CLKMON_SPI_CLK2_MON_Pos);

            /* If SPI_CLK is supplied, the clock stops before setting the Source Clock Setting Register. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_SPI = R_CPG_CPG_CLKON_SPI_CLK2_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_CLK2_MON_Msk & R_CPG->CPG_CLKMON_SPI) >>
                                           R_CPG_CPG_CLKMON_SPI_CLK2_MON_Pos,
                                           0U);
            }

            R_CPG->CPG_SPI_SSEL = (uint32_t) (R_CPG_CPG_SPI_SSEL_SELSPI_WEN_Msk |
                                              (R_CPG_CPG_SPI_SSEL_SELSPI_SET_Msk &
                                               (clock_sel << R_CPG_CPG_SPI_SSEL_SELSPI_SET_Pos)));

            /* If the clock was stopped before setting the Source Clock Setting Register, the clock supply resumes. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_SPI = (uint32_t) (R_CPG_CPG_CLKON_SPI_CLK2_ONWEN_Msk |
                                                   R_CPG_CPG_CLKON_SPI_CLK2_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_CLK2_MON_Msk & R_CPG->CPG_CLKMON_SPI) >>
                                           R_CPG_CPG_CLKMON_SPI_CLK2_MON_Pos,
                                           1U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ / 6;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ >> 1;
            }
            else
            {
                /* If this condition is met, clock_sel is an invalid value. */
                ;
            }

            uint32_t clock_div = (uint32_t) ((R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Msk & R_CPG->CPG_SPI_DDIV) >>
                                             R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Pos);
            if (BSP_CLOCKS_SPI_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 2);

            /* Changing settings for the SPI1 clock related register, SPI0 clock frequency changes at the same time.
             * So it is updated the variable that stored SPI0 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = clock_freq << 1;
            break;
        }
 #endif                                /* BSP_CFG_SELSPI_SET_SOURCE */

 #if defined(BSP_CFG_SELOCTA_SET_SOURCE)

        /* Source Clock setting for OC0. */
        case FSP_PRIV_CLOCK_OC0CLK:
        {
            uint32_t clock_mon = (uint32_t) ((R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                             R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Pos);

            /* If OCTA_MCLK is supplied, the clock stops before setting the Source Clock Setting Register. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_OCTA = R_CPG_CPG_CLKON_OCTA_CLK1_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                           R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Pos,
                                           0U);
            }

            R_CPG->CPG_OCTA_SSEL = (uint32_t) (R_CPG_CPG_OCTA_SSEL_SELOCTA_WEN_Msk |
                                               (R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Msk &
                                                (clock_sel << R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Pos)));

            /* If the clock was stopped before setting the Source Clock Setting Register, the clock supply resumes. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_OCTA = (uint32_t) (R_CPG_CPG_CLKON_OCTA_CLK1_ONWEN_Msk |
                                                    R_CPG_CPG_CLKON_OCTA_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                           R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Pos,
                                           1U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ / 6;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ >> 1;
            }
            else
            {
                /* If this condition is met, clock_sel is an invalid value. */
                ;
            }

            uint32_t clock_div = (uint32_t) ((R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Msk & R_CPG->CPG_OCTA_DDIV) >>
                                             R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Pos);
            if (BSP_CLOCKS_OCTA_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 1);

            /* Changing settings for the OC0 clock related register, OC1 clock frequency changes at the same time.
             * So it is updated the variable that stored OC1 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_OC1CLK] = clock_freq >> 1;
            break;
        }

        /* Source Clock setting for OC1. */
        case FSP_PRIV_CLOCK_OC1CLK:
        {
            uint32_t clock_mon = (uint32_t) ((R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                             R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Pos);

            /* If OCTA_ACLK is supplied, the clock stops before setting the Source Clock Setting Register. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_OCTA = R_CPG_CPG_CLKON_OCTA_CLK0_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                           R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Pos,
                                           0U);
            }

            R_CPG->CPG_OCTA_SSEL = (uint32_t) (R_CPG_CPG_OCTA_SSEL_SELOCTA_WEN_Msk |
                                               (R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Msk &
                                                (clock_sel << R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Pos)));

            /* If the clock was stopped before setting the Source Clock Setting Register, the clock supply resumes. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_OCTA = (uint32_t) (R_CPG_CPG_CLKON_OCTA_CLK0_ONWEN_Msk |
                                                    R_CPG_CPG_CLKON_OCTA_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                           R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Pos,
                                           1U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ / 6;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ >> 1;
            }
            else
            {
                /* If this condition is met, clock_sel is an invalid value. */
                ;
            }

            uint32_t clock_div = (uint32_t) ((R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Msk & R_CPG->CPG_OCTA_DDIV) >>
                                             R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Pos);
            if (BSP_CLOCKS_OCTA_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 2);

            /* Changing settings for the OC1 clock related register, OC0 clock frequency changes at the same time.
             * So it is updated the variable that stored OC0 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] = clock_freq << 1;
            break;
        }
 #endif                                /* BSP_CFG_SELOCTA_SET_SOURCE */

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_sel);
            break;
        }
    }

    g_clock_freq[clock] = clock_freq;
}

/*******************************************************************************************************************//**
 * DEPRECATED Set the Division Ratio Setting register to change the frequency.
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of each clock.
 * @param[in]   clock_div             Value to set in Division Ratio Setting register.
 **********************************************************************************************************************/
void bsp_prv_system_clock_hz_div_set (fsp_priv_clock_t clock, uint32_t clock_div)
{
    uint32_t clock_freq = g_clock_freq[clock];

    switch (clock)
    {
 #if defined(BSP_CFG_DIVPL1_SET_DIV)

        /* ICLK division ratio setting. */
        case FSP_PRIV_CLOCK_ICLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Pos,
                                       0U);
            R_CPG->CPG_PL1_DDIV = (uint32_t) (R_CPG_CPG_PL1_DDIV_DIV_PLL1SET_WEN_Msk |
                                              (R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Pos,
                                       0U);
            clock_freq = BSP_CFG_CLOCK_PLL1_HZ >> clock_div;
            break;
        }
 #endif

 #if defined(BSP_CFG_DIVSPI_SET_DIV)

        /* SPI0CLK division ratio setting. */
        case FSP_PRIV_CLOCK_SPI0CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Pos,
                                       0U);
            R_CPG->CPG_SPI_DDIV = (uint32_t) (R_CPG_CPG_SPI_DDIV_DIVSPI_WEN_Msk |
                                              (R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Msk &
                                               (clock_div << R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Pos,
                                       0U);

            uint32_t clock_source = (R_CPG_CPG_SPI_SSEL_SELSPI_SET_Msk & R_CPG->CPG_SPI_SSEL) >>
                                    R_CPG_CPG_SPI_SSEL_SELSPI_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ / 6;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ >> 1;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            if (BSP_CLOCKS_SPI_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> clock_div;

            /* Changing settings for the SPI0 clock related register, SPI1 clock frequency changes at the same time.
             * So it is updated the variable that stored SPI1 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK] = clock_freq >> 1;
            break;
        }
 #endif

 #if defined(BSP_CFG_DIVSPI_SET_DIV)

        /* SPI1CLK division ratio setting. */
        case FSP_PRIV_CLOCK_SPI1CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Pos,
                                       0U);
            R_CPG->CPG_SPI_DDIV = (uint32_t) (R_CPG_CPG_SPI_DDIV_DIVSPI_WEN_Msk |
                                              (R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Msk &
                                               (clock_div << R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Pos,
                                       0U);

            uint32_t clock_source = (R_CPG_CPG_SPI_SSEL_SELSPI_SET_Msk & R_CPG->CPG_SPI_SSEL) >>
                                    R_CPG_CPG_SPI_SSEL_SELSPI_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ / 6;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ >> 1;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            if (BSP_CLOCKS_SPI_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 1);

            /* Changing settings for the SPI1 clock related register, SPI0 clock frequency changes at the same time.
             * So it is updated the variable that stored SPI0 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = clock_freq << 1;
            break;
        }
 #endif

 #if defined(BSP_CFG_DIVOCTA_SET_DIV)

        /* OC0CLK division ratio setting. */
        case FSP_PRIV_CLOCK_OC0CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Pos,
                                       0U);
            R_CPG->CPG_OCTA_DDIV = (uint32_t) (R_CPG_CPG_OCTA_DDIV_DIVOCTA_WEN_Msk |
                                               (R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Msk &
                                                (clock_div << R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Pos,
                                       0U);

            uint32_t clock_source = (R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Msk & R_CPG->CPG_OCTA_SSEL) >>
                                    R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ / 6;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ >> 1;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            if (BSP_CLOCKS_OCTA_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> clock_div;

            /* Changing settings for the OC0 clock related register, OC1 clock frequency changes at the same time.
             * So it is updated the variable that stored OC1 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_OC1CLK] = clock_freq >> 1;
            break;
        }
 #endif

 #if defined(BSP_CFG_DIVOCTA_SET_DIV)

        /* OC1CLK division ratio setting. */
        case FSP_PRIV_CLOCK_OC1CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Pos,
                                       0U);
            R_CPG->CPG_OCTA_DDIV = (uint32_t) (R_CPG_CPG_OCTA_DDIV_DIVOCTA_WEN_Msk |
                                               (R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Msk &
                                                (clock_div << R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Msk & R_CPG->CPG_CLKDIVSTATUS) >>
                                       R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Pos,
                                       0U);

            uint32_t clock_source = (R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Msk & R_CPG->CPG_OCTA_SSEL) >>
                                    R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_HZ / 6;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL6_HZ >> 1;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            if (BSP_CLOCKS_OCTA_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 1);

            /* Changing settings for the OC1 clock related register, OC0 clock frequency changes at the same time.
             * So it is updated the variable that stored OC0 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] = clock_freq << 1;
            break;
        }
 #endif

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_div);
            break;
        }
    }

    g_clock_freq[clock] = clock_freq;
}

#endif

/*******************************************************************************************************************//**
 * Before changing the selector setting, stop the clock if it is being clocked to the module connected to the selector.
 *
 * @param[in]   selector              Element number of the array that defines the clock selector.
 * @param[in]   clock_status          A pointer to an array that contains values that indicate whether the module
 *                                    connected to the selector is clocked before the selector setting is changed.
 **********************************************************************************************************************/
static void bsp_prv_static_mux_control_pre_setting (fsp_priv_clock_selector_t selector, uint32_t clock_status[])
{
    switch (selector)
    {
#if defined(BSP_CFG_SELOCTA_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_OCTA:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk & R_CPG->CPG_CLKMON_OCTA;
            clock_status[1] = R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk & R_CPG->CPG_CLKMON_OCTA;

            /* If OCTA_ACLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_OCTA = (uint32_t) R_CPG_CPG_CLKON_OCTA_CLK0_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk & R_CPG->CPG_CLKMON_OCTA), 0U);
            }

            /* If OCTA_MCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_OCTA = (uint32_t) R_CPG_CPG_CLKON_OCTA_CLK1_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk & R_CPG->CPG_CLKMON_OCTA), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SELSPI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SPI:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_SPI_CLK3_MON_Msk & R_CPG->CPG_CLKMON_SPI;
            clock_status[1] = R_CPG_CPG_CLKMON_SPI_CLK2_MON_Msk & R_CPG->CPG_CLKMON_SPI;

            /* If SPI_CLKX2 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_SPI = (uint32_t) R_CPG_CPG_CLKON_SPI_CLK3_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_CLK3_MON_Msk & R_CPG->CPG_CLKMON_SPI), 0U);
            }

            /* If SPI_CLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_SPI = (uint32_t) R_CPG_CPG_CLKON_SPI_CLK2_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_CLK2_MON_Msk & R_CPG->CPG_CLKMON_SPI), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK1:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_0_CLK7_MON_Msk & R_CPG->CPG_CLKMON_0;

            /* If CA55_0_SCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_0 = (uint32_t) R_CPG_CPG_CLKON_0_CLK7_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_0_CLK7_MON_Msk & R_CPG->CPG_CLKMON_0), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK0:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_0_CLK7_MON_Msk & R_CPG->CPG_CLKMON_0;

            /* If CA55_0_SCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_0 = (uint32_t) R_CPG_CPG_CLKON_0_CLK7_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_0_CLK7_MON_Msk & R_CPG->CPG_CLKMON_0), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL2_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_TXCLK:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_5_CLK24_MON_Msk & R_CPG->CPG_CLKMON_5;
            clock_status[1] = R_CPG_CPG_CLKMON_5_CLK26_MON_Msk & R_CPG->CPG_CLKMON_5;

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK8_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK24_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK10_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK26_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL3_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_RXCLK:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_5_CLK25_MON_Msk & R_CPG->CPG_CLKMON_5;
            clock_status[1] = R_CPG_CPG_CLKMON_5_CLK27_MON_Msk & R_CPG->CPG_CLKMON_5;

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK9_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK25_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK11_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK27_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_TXCLK:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_5_CLK30_MON_Msk & R_CPG->CPG_CLKMON_5;
            clock_status[1] = R_CPG_CPG_CLKMON_6_CLK0_MON_Msk & R_CPG->CPG_CLKMON_6;

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK14_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK30_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_12 = (uint32_t) R_CPG_CPG_CLKON_12_CLK0_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_6_CLK0_MON_Msk & R_CPG->CPG_CLKMON_6), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_RXCLK:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_5_CLK31_MON_Msk & R_CPG->CPG_CLKMON_5;
            clock_status[1] = R_CPG_CPG_CLKMON_6_CLK1_MON_Msk & R_CPG->CPG_CLKMON_6;

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK15_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK31_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_12 = (uint32_t) R_CPG_CPG_CLKON_12_CLK1_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_6_CLK1_MON_Msk & R_CPG->CPG_CLKMON_6), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL2_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK0:
        {
            clock_status[0] = (R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk) & R_CPG->CPG_CLKMON_5;

            /* If SPI_clk_spi or SPI_clk_spix2 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_10 = (uint32_t) R_CPG_CPG_CLKON_10_CLK1_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk) &
                                            R_CPG->CPG_CLKMON_5),
                                           0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL3_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK1:
        {
            clock_status[0] = (R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk) & R_CPG->CPG_CLKMON_5;

            /* If SPI_clk_spi or SPI_clk_spix2 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_10 = (uint32_t) R_CPG_CPG_CLKON_10_CLK1_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk) &
                                            R_CPG->CPG_CLKMON_5),
                                           0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL3_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI0_CLK:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_7_CLK10_MON_Msk & R_CPG->CPG_CLKMON_7;
            clock_status[1] = R_CPG_CPG_CLKMON_7_CLK15_MON_Msk & R_CPG->CPG_CLKMON_7;
            clock_status[2] = R_CPG_CPG_CLKMON_10_CLK24_MON_Msk & R_CPG->CPG_CLKMON_10;

            /* If DSI_0_vclk1 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) R_CPG_CPG_CLKON_14_CLK10_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK10_MON_Msk & R_CPG->CPG_CLKMON_7), 0U);
            }

            /* If LCDC_0_clk_d is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) R_CPG_CPG_CLKON_14_CLK15_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK15_MON_Msk & R_CPG->CPG_CLKMON_7), 0U);
            }

            /* If LVDS_TOP_CLK_DOT_CH0 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) R_CPG_CPG_CLKON_26_CLK2_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK24_MON_Msk & R_CPG->CPG_CLKMON_10), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL3_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI1_CLK:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_10_CLK21_MON_Msk & R_CPG->CPG_CLKMON_10;
            clock_status[1] = R_CPG_CPG_CLKMON_11_CLK0_MON_Msk & R_CPG->CPG_CLKMON_11;
            clock_status[2] = R_CPG_CPG_CLKMON_10_CLK25_MON_Msk & R_CPG->CPG_CLKMON_10;

            /* If DSI_0_vclk2 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_25 = (uint32_t) R_CPG_CPG_CLKON_25_CLK0_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK21_MON_Msk & R_CPG->CPG_CLKMON_10), 0U);
            }

            /* If LCDC_1_clk_d is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) R_CPG_CPG_CLKON_26_CLK10_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_11_CLK0_MON_Msk & R_CPG->CPG_CLKMON_11), 0U);
            }

            /* If LVDS_TOP_CLK_DOT_CH1 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) R_CPG_CPG_CLKON_26_CLK3_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK25_MON_Msk & R_CPG->CPG_CLKMON_10), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_XSPI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_XSPI:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_XSPI_CLK3_MON_Msk & R_CPG->CPG_CLKMON_XSPI;
            clock_status[1] = R_CPG_CPG_CLKMON_XSPI_CLK2_MON_Msk & R_CPG->CPG_CLKMON_XSPI;

            /* If XSPI_CLKX2 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_XSPI = (uint32_t) R_CPG_CPG_CLKON_XSPI_CLK3_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_XSPI_CLK3_MON_Msk & R_CPG->CPG_CLKMON_XSPI), 0U);
            }

            /* If XSPI_CLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_XSPI = (uint32_t) R_CPG_CPG_CLKON_XSPI_CLK2_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_XSPI_CLK2_MON_Msk & R_CPG->CPG_CLKMON_XSPI), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_DSI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_DSI:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk & R_CPG->CPG_CLKMON_MIPI_DSI;
            clock_status[1] = R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LVDS;
            clock_status[2] = R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LCDC;

            /* If MIPI_DSI_VCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_MIPI_DSI = (uint32_t) (R_CPG_CPG_CLKON_MIPI_DSI_CLK4_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk & R_CPG->CPG_CLKMON_MIPI_DSI), 0U);
            }

            /* If LVDS_CLK_DOT0 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_LVDS = (uint32_t) (R_CPG_CPG_CLKON_LVDS_CLK1_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LVDS), 0U);
            }

            /* If LCDC_CLK_D is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_LCDC = (uint32_t) (R_CPG_CPG_CLKON_LCDC_CLK1_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LCDC), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_GE3D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_GE3D:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_GE3D_CLK0_MON_Msk & R_CPG->CPG_CLKMON_GE3D;

            /* If GE3D_CLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_GE3D = (uint32_t) R_CPG_CPG_CLKON_GE3D_CLK0_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_GE3D_CLK0_MON_Msk & R_CPG->CPG_CLKMON_GE3D), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0A_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_TX:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH0_TX_I and ETH0_TX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK4_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0B_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RX:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH0_RX_I and ETH0_RX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK6_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0C_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RM:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH;
            clock_status[1] = R_CPG_CPG_CLKMON_ETH_CLK10_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH0_TX_I and ETH0_RX_I (RMII Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK12_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            /* If ETH0_RMII_I is supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK10_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK10_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_TX_I:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH;
            clock_status[1] = R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH0_TX_I and ETH0_RX_I (RMII Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK12_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            /* If ETH0_TX_I and ETH0_TX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK4_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0E_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_RX_I:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH;
            clock_status[1] = R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH0_TX_I and ETH0_RX_I (RMII Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK12_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            /* If ETH0_RX_I and ETH0_RX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK6_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1A_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_TX:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH1_TX_I and ETH1_TX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK5_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1B_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RX:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH1_RX_I and ETH1_RX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK7_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1C_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RM:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH;
            clock_status[1] = R_CPG_CPG_CLKMON_ETH_CLK11_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH1_TX_I and ETH1_RX_I (RMII Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK13_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            /* If ETH1_RMII_I is supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK11_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK11_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_TX_I:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH;
            clock_status[1] = R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH1_TX_I and ETH1_RX_I (RMII Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK13_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            /* If ETH1_TX_I and ETH1_TX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK5_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1E_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_RX_I:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH;
            clock_status[1] = R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH1_TX_I and ETH1_RX_I (RMII Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK13_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            /* If ETH1_RX_I and ETH1_RX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK7_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI0:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_RSCI_CLK8_MON_Msk & R_CPG->CPG_CLKMON_RSCI;

            /* If RSCI0_TCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSCI = (uint32_t) R_CPG_CPG_CLKON_RSCI_CLK8_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSCI_CLK8_MON_Msk & R_CPG->CPG_CLKMON_RSCI), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI1:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_RSCI_CLK9_MON_Msk & R_CPG->CPG_CLKMON_RSCI;

            /* If RSCI1_TCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSCI = (uint32_t) R_CPG_CPG_CLKON_RSCI_CLK9_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSCI_CLK9_MON_Msk & R_CPG->CPG_CLKMON_RSCI), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI2:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_RSCI_CLK10_MON_Msk & R_CPG->CPG_CLKMON_RSCI;

            /* If RSCI2_TCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSCI = (uint32_t) R_CPG_CPG_CLKON_RSCI_CLK10_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSCI_CLK10_MON_Msk & R_CPG->CPG_CLKMON_RSCI), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI3_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI3:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_RSCI_CLK11_MON_Msk & R_CPG->CPG_CLKMON_RSCI;

            /* If RSCI3_TCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSCI = (uint32_t) R_CPG_CPG_CLKON_RSCI_CLK11_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSCI_CLK11_MON_Msk & R_CPG->CPG_CLKMON_RSCI), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI0:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_RSPI_CLK8_MON_Msk & R_CPG->CPG_CLKMON_RSPI;

            /* If RSPI0_TCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSPI = (uint32_t) R_CPG_CPG_CLKON_RSPI_CLK8_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSPI_CLK8_MON_Msk & R_CPG->CPG_CLKMON_RSPI), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI1:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_RSPI_CLK9_MON_Msk & R_CPG->CPG_CLKMON_RSPI;

            /* If RSPI1_TCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSPI = (uint32_t) R_CPG_CPG_CLKON_RSPI_CLK9_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSPI_CLK9_MON_Msk & R_CPG->CPG_CLKMON_RSPI), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI2:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_RSPI_CLK10_MON_Msk & R_CPG->CPG_CLKMON_RSPI;

            /* If RSPI2_TCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSPI = (uint32_t) R_CPG_CPG_CLKON_RSPI_CLK10_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSPI_CLK10_MON_Msk & R_CPG->CPG_CLKMON_RSPI), 0U);
            }

            break;
        }
#endif

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_status);
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * If the clock was stopped before the selector setting was changed, restart the clock to be supplied.
 *
 * @param[in]   selector              Element number of the array that defines the clock selector.
 * @param[in]   clock_status          A pointer to an array that contains values that indicate whether the module
 *                                    connected to the selector is clocked before the selector setting is changed.
 **********************************************************************************************************************/
static void bsp_prv_static_mux_control_post_setting (fsp_priv_clock_selector_t selector, uint32_t clock_status[])
{
    switch (selector)
    {
#if defined(BSP_CFG_SELOCTA_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_OCTA:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_OCTA =
                    (uint32_t) (R_CPG_CPG_CLKON_OCTA_CLK0_ONWEN_Msk | R_CPG_CPG_CLKON_OCTA_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk & R_CPG->CPG_CLKMON_OCTA),
                                           R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_OCTA =
                    (uint32_t) (R_CPG_CPG_CLKON_OCTA_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_OCTA_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk & R_CPG->CPG_CLKMON_OCTA),
                                           R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SELSPI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SPI:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_SPI =
                    (uint32_t) (R_CPG_CPG_CLKON_SPI_CLK3_ONWEN_Msk | R_CPG_CPG_CLKON_SPI_CLK3_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_CLK3_MON_Msk & R_CPG->CPG_CLKMON_SPI),
                                           R_CPG_CPG_CLKMON_SPI_CLK3_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_SPI =
                    (uint32_t) (R_CPG_CPG_CLKON_SPI_CLK2_ONWEN_Msk | R_CPG_CPG_CLKON_SPI_CLK2_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_CLK2_MON_Msk & R_CPG->CPG_CLKMON_SPI),
                                           R_CPG_CPG_CLKMON_SPI_CLK2_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK1:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_0 = (uint32_t) (R_CPG_CPG_CLKON_0_CLK7_ONWEN_Msk | R_CPG_CPG_CLKON_0_CLK7_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_0_CLK7_MON_Msk & R_CPG->CPG_CLKMON_0),
                                           R_CPG_CPG_CLKMON_0_CLK7_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK0:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_0 = (uint32_t) (R_CPG_CPG_CLKON_0_CLK7_ONWEN_Msk | R_CPG_CPG_CLKON_0_CLK7_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_0_CLK7_MON_Msk & R_CPG->CPG_CLKMON_0),
                                           R_CPG_CPG_CLKMON_0_CLK7_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL2_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_TXCLK:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK8_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK8_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK24_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK24_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK10_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK10_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK26_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK26_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL3_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_RXCLK:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK9_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK9_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK25_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK25_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK11_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK11_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK27_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK27_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_TXCLK:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK14_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK14_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK30_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK30_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_12 = (uint32_t) (R_CPG_CPG_CLKON_12_CLK0_ONWEN_Msk | R_CPG_CPG_CLKON_12_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_6_CLK0_MON_Msk & R_CPG->CPG_CLKMON_6),
                                           R_CPG_CPG_CLKMON_6_CLK0_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_RXCLK:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK15_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK15_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK31_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK31_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_12 = (uint32_t) (R_CPG_CPG_CLKON_12_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_12_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_6_CLK1_MON_Msk & R_CPG->CPG_CLKMON_6),
                                           R_CPG_CPG_CLKMON_6_CLK1_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL2_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK0:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_10 = (uint32_t) (R_CPG_CPG_CLKON_10_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_10_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk) &
                                            R_CPG->CPG_CLKMON_5),
                                           (R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk));
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL3_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK1:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_10 = (uint32_t) (R_CPG_CPG_CLKON_10_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_10_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk) &
                                            R_CPG->CPG_CLKMON_5),
                                           (R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk));
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL3_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI0_CLK:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) (R_CPG_CPG_CLKON_14_CLK10_ONWEN_Msk | R_CPG_CPG_CLKON_14_CLK10_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK10_MON_Msk & R_CPG->CPG_CLKMON_7),
                                           R_CPG_CPG_CLKMON_7_CLK10_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) (R_CPG_CPG_CLKON_14_CLK15_ONWEN_Msk | R_CPG_CPG_CLKON_14_CLK15_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK15_MON_Msk & R_CPG->CPG_CLKMON_7),
                                           R_CPG_CPG_CLKMON_7_CLK15_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) (R_CPG_CPG_CLKON_26_CLK2_ONWEN_Msk | R_CPG_CPG_CLKON_26_CLK2_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK24_MON_Msk & R_CPG->CPG_CLKMON_10),
                                           R_CPG_CPG_CLKMON_10_CLK24_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL3_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI1_CLK:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_25 = (uint32_t) (R_CPG_CPG_CLKON_25_CLK0_ONWEN_Msk | R_CPG_CPG_CLKON_25_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK21_MON_Msk & R_CPG->CPG_CLKMON_10),
                                           R_CPG_CPG_CLKMON_10_CLK21_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) (R_CPG_CPG_CLKON_26_CLK10_ONWEN_Msk | R_CPG_CPG_CLKON_26_CLK10_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_11_CLK0_MON_Msk & R_CPG->CPG_CLKMON_11),
                                           R_CPG_CPG_CLKMON_11_CLK0_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) (R_CPG_CPG_CLKON_26_CLK3_ONWEN_Msk | R_CPG_CPG_CLKON_26_CLK3_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK25_MON_Msk & R_CPG->CPG_CLKMON_10),
                                           R_CPG_CPG_CLKMON_10_CLK25_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_XSPI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_XSPI:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_XSPI =
                    (uint32_t) (R_CPG_CPG_CLKON_XSPI_CLK3_ONWEN_Msk | R_CPG_CPG_CLKON_XSPI_CLK3_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_XSPI_CLK3_MON_Msk & R_CPG->CPG_CLKMON_XSPI),
                                           R_CPG_CPG_CLKMON_XSPI_CLK3_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_XSPI =
                    (uint32_t) (R_CPG_CPG_CLKON_XSPI_CLK2_ONWEN_Msk | R_CPG_CPG_CLKON_XSPI_CLK2_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_XSPI_CLK2_MON_Msk & R_CPG->CPG_CLKMON_XSPI),
                                           R_CPG_CPG_CLKMON_XSPI_CLK2_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_DSI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_DSI:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_MIPI_DSI =
                    (uint32_t) (R_CPG_CPG_CLKON_MIPI_DSI_CLK4_ONWEN_Msk | R_CPG_CPG_CLKON_MIPI_DSI_CLK4_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk & R_CPG->CPG_CLKMON_MIPI_DSI),
                                           R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_LVDS =
                    (uint32_t) (R_CPG_CPG_CLKON_LVDS_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_LVDS_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LVDS),
                                           R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_LCDC =
                    (uint32_t) (R_CPG_CPG_CLKON_LCDC_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_LCDC_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LCDC),
                                           R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_GE3D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_GE3D:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_GE3D =
                    (uint32_t) (R_CPG_CPG_CLKON_GE3D_CLK0_ONWEN_Msk | R_CPG_CPG_CLKON_GE3D_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_GE3D_CLK0_MON_Msk & R_CPG->CPG_CLKMON_GE3D),
                                           R_CPG_CPG_CLKMON_GE3D_CLK0_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0A_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_TX:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK4_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK4_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0B_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RX:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK6_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK6_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0C_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RM:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK12_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK12_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK10_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK10_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK10_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK10_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_TX_I:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK12_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK12_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK4_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK4_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0E_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_RX_I:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK12_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK12_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK6_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK6_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1A_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_TX:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK5_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK5_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1B_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RX:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK7_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK7_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1C_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RM:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK13_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK13_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK11_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK11_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK11_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK11_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_TX_I:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK13_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK13_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK5_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK5_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1E_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_RX_I:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK13_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK13_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK7_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK7_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI0:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSCI =
                    (uint32_t) (R_CPG_CPG_CLKON_RSCI_CLK8_ONWEN_Msk | R_CPG_CPG_CLKON_RSCI_CLK8_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSCI_CLK8_MON_Msk & R_CPG->CPG_CLKMON_RSCI),
                                           R_CPG_CPG_CLKMON_RSCI_CLK8_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI1:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSCI =
                    (uint32_t) (R_CPG_CPG_CLKON_RSCI_CLK9_ONWEN_Msk | R_CPG_CPG_CLKON_RSCI_CLK9_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSCI_CLK9_MON_Msk & R_CPG->CPG_CLKMON_RSCI),
                                           R_CPG_CPG_CLKMON_RSCI_CLK9_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI2:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSCI =
                    (uint32_t) (R_CPG_CPG_CLKON_RSCI_CLK10_ONWEN_Msk | R_CPG_CPG_CLKON_RSCI_CLK10_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSCI_CLK10_MON_Msk & R_CPG->CPG_CLKMON_RSCI),
                                           R_CPG_CPG_CLKMON_RSCI_CLK10_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI3_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI3:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSCI =
                    (uint32_t) (R_CPG_CPG_CLKON_RSCI_CLK11_ONWEN_Msk | R_CPG_CPG_CLKON_RSCI_CLK11_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSCI_CLK11_MON_Msk & R_CPG->CPG_CLKMON_RSCI),
                                           R_CPG_CPG_CLKMON_RSCI_CLK11_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI0:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSPI =
                    (uint32_t) (R_CPG_CPG_CLKON_RSPI_CLK8_ONWEN_Msk | R_CPG_CPG_CLKON_RSPI_CLK8_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSPI_CLK8_MON_Msk & R_CPG->CPG_CLKMON_RSPI),
                                           R_CPG_CPG_CLKMON_RSPI_CLK8_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI1:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSPI =
                    (uint32_t) (R_CPG_CPG_CLKON_RSPI_CLK9_ONWEN_Msk | R_CPG_CPG_CLKON_RSPI_CLK9_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSPI_CLK9_MON_Msk & R_CPG->CPG_CLKMON_RSPI),
                                           R_CPG_CPG_CLKMON_RSPI_CLK9_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI2:
        {
            /* If the clock was stopped before setting the Static Mux Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_RSPI =
                    (uint32_t) (R_CPG_CPG_CLKON_RSPI_CLK10_ONWEN_Msk | R_CPG_CPG_CLKON_RSPI_CLK10_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_RSPI_CLK10_MON_Msk & R_CPG->CPG_CLKMON_RSPI),
                                           R_CPG_CPG_CLKMON_RSPI_CLK10_MON_Msk);
            }

            break;
        }
#endif

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_status);
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * Before changing the divider setting, stop the clock if it is being clocked to the module connected to the divider.
 *
 * @param[in]   divider               Element number of the array that defines the clock divider.
 * @param[in]   clock_status          A pointer to an array that contains values that indicate whether the module
 *                                    connected to the divider is clocked before the divider setting is changed.
 **********************************************************************************************************************/
static void bsp_prv_static_gear_control_pre_setting (fsp_priv_clock_divider_t divider, uint32_t clock_status[])
{
    switch (divider)
    {
#if defined(BSP_CFG_CSDIV0_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE0:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_5_CLK24_MON_Msk & R_CPG->CPG_CLKMON_5;
            clock_status[1] = R_CPG_CPG_CLKMON_5_CLK25_MON_Msk & R_CPG->CPG_CLKMON_5;
            clock_status[2] = R_CPG_CPG_CLKMON_5_CLK26_MON_Msk & R_CPG->CPG_CLKMON_5;
            clock_status[3] = R_CPG_CPG_CLKMON_5_CLK27_MON_Msk & R_CPG->CPG_CLKMON_5;

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK8_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK24_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK9_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK25_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK10_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK26_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[3])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK11_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK27_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE1:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_5_CLK30_MON_Msk & R_CPG->CPG_CLKMON_5;
            clock_status[1] = R_CPG_CPG_CLKMON_5_CLK31_MON_Msk & R_CPG->CPG_CLKMON_5;
            clock_status[2] = R_CPG_CPG_CLKMON_6_CLK0_MON_Msk & R_CPG->CPG_CLKMON_6;
            clock_status[3] = R_CPG_CPG_CLKMON_6_CLK1_MON_Msk & R_CPG->CPG_CLKMON_6;

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK14_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK30_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) R_CPG_CPG_CLKON_11_CLK15_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK31_MON_Msk & R_CPG->CPG_CLKMON_5), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_12 = (uint32_t) R_CPG_CPG_CLKON_12_CLK0_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_6_CLK0_MON_Msk & R_CPG->CPG_CLKMON_6), 0U);
            }

            /* If ETHER-related clock is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[3])
            {
                R_CPG->CPG_CLKON_12 = (uint32_t) R_CPG_CPG_CLKON_12_CLK1_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_6_CLK1_MON_Msk & R_CPG->CPG_CLKMON_6), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_LPCLK:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_7_CLK11_MON_Msk & R_CPG->CPG_CLKMON_7;

            /* If DSI_0_lpclk is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) R_CPG_CPG_CLKON_14_CLK11_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK11_MON_Msk & R_CPG->CPG_CLKMON_7), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_XSPI:
        {
            clock_status[0] = (R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk) & R_CPG->CPG_CLKMON_5;

            /* If SPI_clk_spi or SPI_clk_spix2 is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_10 = (uint32_t) R_CPG_CPG_CLKON_10_CLK1_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk) &
                                            R_CPG->CPG_CLKMON_5),
                                           0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_PCLK:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_8_CLK7_MON_Msk & R_CPG->CPG_CLKMON_8;
            clock_status[1] = R_CPG_CPG_CLKMON_8_CLK8_MON_Msk & R_CPG->CPG_CLKMON_8;

            /* If ADC_0_PCLK is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_16 = (uint32_t) R_CPG_CPG_CLKON_16_CLK7_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_8_CLK7_MON_Msk & R_CPG->CPG_CLKMON_8), 0U);
            }

            /* If ADC_0_ADCLK is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_16 = (uint32_t) R_CPG_CPG_CLKON_16_CLK8_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_8_CLK8_MON_Msk & R_CPG->CPG_CLKMON_8), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_ADCLK:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_8_CLK7_MON_Msk & R_CPG->CPG_CLKMON_8;
            clock_status[1] = R_CPG_CPG_CLKMON_8_CLK8_MON_Msk & R_CPG->CPG_CLKMON_8;

            /* If ADC_0_PCLK is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_16 = (uint32_t) R_CPG_CPG_CLKON_16_CLK7_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_8_CLK7_MON_Msk & R_CPG->CPG_CLKMON_8), 0U);
            }

            /* If ADC_0_ADCLK is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_16 = (uint32_t) R_CPG_CPG_CLKON_16_CLK8_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_8_CLK8_MON_Msk & R_CPG->CPG_CLKMON_8), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI0:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_7_CLK10_MON_Msk & R_CPG->CPG_CLKMON_7;
            clock_status[1] = R_CPG_CPG_CLKMON_7_CLK15_MON_Msk & R_CPG->CPG_CLKMON_7;
            clock_status[2] = R_CPG_CPG_CLKMON_10_CLK24_MON_Msk & R_CPG->CPG_CLKMON_10;

            /* If DSI_0_vclk1 is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) R_CPG_CPG_CLKON_14_CLK10_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK10_MON_Msk & R_CPG->CPG_CLKMON_7), 0U);
            }

            /* If LCDC_0_clk_d is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) R_CPG_CPG_CLKON_14_CLK15_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK15_MON_Msk & R_CPG->CPG_CLKMON_7), 0U);
            }

            /* If LVDS_TOP_CLK_DOT_CH0 is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) R_CPG_CPG_CLKON_26_CLK2_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK24_MON_Msk & R_CPG->CPG_CLKMON_10), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI1:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_10_CLK21_MON_Msk & R_CPG->CPG_CLKMON_10;
            clock_status[1] = R_CPG_CPG_CLKMON_11_CLK0_MON_Msk & R_CPG->CPG_CLKMON_11;
            clock_status[2] = R_CPG_CPG_CLKMON_10_CLK25_MON_Msk & R_CPG->CPG_CLKMON_10;

            /* If DSI_0_vclk2 is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_25 = (uint32_t) R_CPG_CPG_CLKON_25_CLK0_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK21_MON_Msk & R_CPG->CPG_CLKMON_10), 0U);
            }

            /* If LCDC_1_clk_d is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) R_CPG_CPG_CLKON_26_CLK10_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_11_CLK0_MON_Msk & R_CPG->CPG_CLKMON_11), 0U);
            }

            /* If LVDS_TOP_CLK_DOT_CH1 is supplied, the clock stops before setting the Static Gear Control Register. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) R_CPG_CPG_CLKON_26_CLK3_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK25_MON_Msk & R_CPG->CPG_CLKMON_10), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO32_VCLK:
#endif
#if defined(BSP_CFG_DIV_DSI_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO16_VCLK:
#endif
#if defined(BSP_CFG_DIV_DSI_A_SET_DIV) || defined(BSP_CFG_DIV_DSI_B_SET_DIV)
        {
            clock_status[0] = R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk & R_CPG->CPG_CLKMON_MIPI_DSI;
            clock_status[1] = R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LVDS;
            clock_status[2] = R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LCDC;

            /* If MIPI_DSI_VCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_MIPI_DSI = (uint32_t) (R_CPG_CPG_CLKON_MIPI_DSI_CLK4_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk & R_CPG->CPG_CLKMON_MIPI_DSI), 0U);
            }

            /* If LVDS_CLK_DOT0 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_LVDS = (uint32_t) (R_CPG_CPG_CLKON_LVDS_CLK1_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LVDS), 0U);
            }

            /* If LCDC_CLK_D is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_LCDC = (uint32_t) (R_CPG_CPG_CLKON_LCDC_CLK1_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LCDC), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO2_LVDS:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk & R_CPG->CPG_CLKMON_MIPI_DSI;
            clock_status[1] = R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LVDS;
            clock_status[2] = R_CPG_CPG_CLKMON_LVDS_CLK0_MON_Msk & R_CPG->CPG_CLKMON_LVDS;
            clock_status[3] = R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LCDC;

            /* If MIPI_DSI_VCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_MIPI_DSI = (uint32_t) (R_CPG_CPG_CLKON_MIPI_DSI_CLK4_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk & R_CPG->CPG_CLKMON_MIPI_DSI), 0U);
            }

            /* If LVDS_CLK_DOT0 is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_LVDS = (uint32_t) (R_CPG_CPG_CLKON_LVDS_CLK1_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LVDS), 0U);
            }

            /* If LVDS_PLLCLK is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_LVDS = (uint32_t) (R_CPG_CPG_CLKON_LVDS_CLK0_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LVDS_CLK0_MON_Msk & R_CPG->CPG_CLKMON_LVDS), 0U);
            }

            /* If LCDC_CLK_D is supplied, the clock stops before setting the Static Mux Control Register. */
            if (clock_status[3])
            {
                R_CPG->CPG_CLKON_LCDC = (uint32_t) (R_CPG_CPG_CLKON_LCDC_CLK1_ONWEN_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LCDC), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_TR:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk & R_CPG->CPG_CLKMON_ETH;
            clock_status[1] = R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH0_RX_I and ETH0_RX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK6_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            /* If ETH0_TX_I and ETH0_TX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK4_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_RM:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH0_TX_I and ETH0_RX_I (RMII Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK12_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_TR:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk & R_CPG->CPG_CLKMON_ETH;
            clock_status[1] = R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH1_RX_I and ETH1_RX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK7_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            /* If ETH1_TX_I and ETH1_TX_180_I (Normal Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK5_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_D_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_RM:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH;

            /* If ETH1_TX_I and ETH1_RX_I (RMII Mode) are supplied, the clocks stop before setting the Static Mux Control Register. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH = (uint32_t) R_CPG_CPG_CLKON_ETH_CLK13_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH), 0U);
            }

            break;
        }
#endif

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_status);
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * If the clock was stopped before the divider setting was changed, restart the clock to be supplied.
 *
 * @param[in]   divider               Element number of the array that defines the clock divider.
 * @param[in]   clock_status          A pointer to an array that contains values that indicate whether the module
 *                                    connected to the divider is clocked before the divider setting is changed.
 **********************************************************************************************************************/
static void bsp_prv_static_gear_control_post_setting (fsp_priv_clock_divider_t divider, uint32_t clock_status[])
{
    switch (divider)
    {
#if defined(BSP_CFG_CSDIV0_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE0:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK8_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK8_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK24_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK24_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK9_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK9_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK25_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK25_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK10_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK10_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK26_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK26_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[3])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK11_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK11_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK27_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK27_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE1:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK14_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK14_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK30_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK30_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_11 = (uint32_t) (R_CPG_CPG_CLKON_11_CLK15_ONWEN_Msk | R_CPG_CPG_CLKON_11_CLK15_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_5_CLK31_MON_Msk & R_CPG->CPG_CLKMON_5),
                                           R_CPG_CPG_CLKMON_5_CLK31_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_12 = (uint32_t) (R_CPG_CPG_CLKON_12_CLK0_ONWEN_Msk | R_CPG_CPG_CLKON_12_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_6_CLK0_MON_Msk & R_CPG->CPG_CLKMON_6),
                                           R_CPG_CPG_CLKMON_6_CLK0_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[3])
            {
                R_CPG->CPG_CLKON_12 = (uint32_t) (R_CPG_CPG_CLKON_12_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_12_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_6_CLK1_MON_Msk & R_CPG->CPG_CLKMON_6),
                                           R_CPG_CPG_CLKMON_6_CLK1_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_LPCLK:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) (R_CPG_CPG_CLKON_14_CLK11_ONWEN_Msk | R_CPG_CPG_CLKON_14_CLK11_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK11_MON_Msk & R_CPG->CPG_CLKMON_7),
                                           R_CPG_CPG_CLKMON_7_CLK11_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_XSPI:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_10 = (uint32_t) (R_CPG_CPG_CLKON_10_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_10_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk) &
                                            R_CPG->CPG_CLKMON_5),
                                           (R_CPG_CPG_CLKMON_5_CLK1_MON_Msk | R_CPG_CPG_CLKMON_5_CLK2_MON_Msk));
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_PCLK:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_16 = (uint32_t) (R_CPG_CPG_CLKON_16_CLK7_ONWEN_Msk | R_CPG_CPG_CLKON_16_CLK7_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_8_CLK7_MON_Msk & R_CPG->CPG_CLKMON_8),
                                           R_CPG_CPG_CLKMON_8_CLK7_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_16 = (uint32_t) (R_CPG_CPG_CLKON_16_CLK8_ONWEN_Msk | R_CPG_CPG_CLKON_16_CLK8_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_8_CLK8_MON_Msk & R_CPG->CPG_CLKMON_8),
                                           R_CPG_CPG_CLKMON_8_CLK8_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_ADCLK:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_16 = (uint32_t) (R_CPG_CPG_CLKON_16_CLK7_ONWEN_Msk | R_CPG_CPG_CLKON_16_CLK7_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_8_CLK7_MON_Msk & R_CPG->CPG_CLKMON_8),
                                           R_CPG_CPG_CLKMON_8_CLK7_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_16 = (uint32_t) (R_CPG_CPG_CLKON_16_CLK8_ONWEN_Msk | R_CPG_CPG_CLKON_16_CLK8_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_8_CLK8_MON_Msk & R_CPG->CPG_CLKMON_8),
                                           R_CPG_CPG_CLKMON_8_CLK8_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI0:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) (R_CPG_CPG_CLKON_14_CLK10_ONWEN_Msk | R_CPG_CPG_CLKON_14_CLK10_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK10_MON_Msk & R_CPG->CPG_CLKMON_7),
                                           R_CPG_CPG_CLKMON_7_CLK10_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_14 = (uint32_t) (R_CPG_CPG_CLKON_14_CLK15_ONWEN_Msk | R_CPG_CPG_CLKON_14_CLK15_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_7_CLK15_MON_Msk & R_CPG->CPG_CLKMON_7),
                                           R_CPG_CPG_CLKMON_7_CLK15_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) (R_CPG_CPG_CLKON_26_CLK2_ONWEN_Msk | R_CPG_CPG_CLKON_26_CLK2_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK24_MON_Msk & R_CPG->CPG_CLKMON_10),
                                           R_CPG_CPG_CLKMON_10_CLK24_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI1:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_25 = (uint32_t) (R_CPG_CPG_CLKON_25_CLK0_ONWEN_Msk | R_CPG_CPG_CLKON_25_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK21_MON_Msk & R_CPG->CPG_CLKMON_10),
                                           R_CPG_CPG_CLKMON_10_CLK21_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) (R_CPG_CPG_CLKON_26_CLK10_ONWEN_Msk | R_CPG_CPG_CLKON_26_CLK10_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_11_CLK0_MON_Msk & R_CPG->CPG_CLKMON_11),
                                           R_CPG_CPG_CLKMON_11_CLK0_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_26 = (uint32_t) (R_CPG_CPG_CLKON_26_CLK3_ONWEN_Msk | R_CPG_CPG_CLKON_26_CLK3_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_10_CLK25_MON_Msk & R_CPG->CPG_CLKMON_10),
                                           R_CPG_CPG_CLKMON_10_CLK25_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO32_VCLK:
#endif
#if defined(BSP_CFG_DIV_DSI_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO16_VCLK:
#endif
#if defined(BSP_CFG_DIV_DSI_A_SET_DIV) || defined(BSP_CFG_DIV_DSI_B_SET_DIV)
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_MIPI_DSI =
                    (uint32_t) (R_CPG_CPG_CLKON_MIPI_DSI_CLK4_ONWEN_Msk | R_CPG_CPG_CLKON_MIPI_DSI_CLK4_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk & R_CPG->CPG_CLKMON_MIPI_DSI),
                                           R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_LVDS =
                    (uint32_t) (R_CPG_CPG_CLKON_LVDS_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_LVDS_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LVDS),
                                           R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_LCDC =
                    (uint32_t) (R_CPG_CPG_CLKON_LCDC_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_LCDC_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LCDC),
                                           R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO2_LVDS:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_MIPI_DSI =
                    (uint32_t) (R_CPG_CPG_CLKON_MIPI_DSI_CLK4_ONWEN_Msk | R_CPG_CPG_CLKON_MIPI_DSI_CLK4_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk & R_CPG->CPG_CLKMON_MIPI_DSI),
                                           R_CPG_CPG_CLKMON_MIPI_DSI_CLK4_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_LVDS =
                    (uint32_t) (R_CPG_CPG_CLKON_LVDS_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_LVDS_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LVDS),
                                           R_CPG_CPG_CLKMON_LVDS_CLK1_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[2])
            {
                R_CPG->CPG_CLKON_LVDS =
                    (uint32_t) (R_CPG_CPG_CLKON_LVDS_CLK0_ONWEN_Msk | R_CPG_CPG_CLKON_LVDS_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LVDS_CLK0_MON_Msk & R_CPG->CPG_CLKMON_LVDS),
                                           R_CPG_CPG_CLKMON_LVDS_CLK0_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[3])
            {
                R_CPG->CPG_CLKON_LCDC =
                    (uint32_t) (R_CPG_CPG_CLKON_LCDC_CLK1_ONWEN_Msk | R_CPG_CPG_CLKON_LCDC_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk & R_CPG->CPG_CLKMON_LCDC),
                                           R_CPG_CPG_CLKMON_LCDC_CLK1_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_TR:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK6_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK6_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK6_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK4_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK4_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK4_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_RM:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK12_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK12_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK12_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_TR:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK7_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK7_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK7_MON_Msk);
            }

            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[1])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK5_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK5_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK5_MON_Msk);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_D_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_RM:
        {
            /* If the clock was stopped before setting the Static Gear Control Register, the clock supply resumes. */
            if (clock_status[0])
            {
                R_CPG->CPG_CLKON_ETH =
                    (uint32_t) (R_CPG_CPG_CLKON_ETH_CLK13_ONWEN_Msk | R_CPG_CPG_CLKON_ETH_CLK13_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk & R_CPG->CPG_CLKMON_ETH),
                                           R_CPG_CPG_CLKMON_ETH_CLK13_MON_Msk);
            }

            break;
        }
#endif

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_status);
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * Calculates and updates the frequency of the specified clock.
 *
 * @param[in] clock                    Element number of the array that defines the frequency of each clock.
 **********************************************************************************************************************/
static void bsp_prv_clock_frequency_calculation (fsp_priv_clock_t clock)
{
    switch (clock)
    {
#if defined(BSP_CFG_DIVPL1_SET_DIV) || defined(BSP_CFG_DIV_PLL1_A_SET_DIV)
        case FSP_PRIV_CLOCK_ICLK:
        {
 #if defined(BSP_CFG_DIVPL1_SET_DIV)
            uint32_t div = (R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Msk & R_CPG->CPG_PL1_DDIV) >>
                           R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Pos;
 #endif
 #if defined(BSP_CFG_DIV_PLL1_A_SET_DIV)
            uint32_t div = (R_CPG_CPG_PL1_DDIV_DIV_PLL1_A_SET_Msk & R_CPG->CPG_PL1_DDIV) >>
                           R_CPG_CPG_PL1_DDIV_DIV_PLL1_A_SET_Pos;
 #endif
            g_clock_freq[FSP_PRIV_CLOCK_ICLK] = BSP_CFG_CLOCK_PLL1_HZ >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL6A_SET_DIV)
        case FSP_PRIV_CLOCK_I2CLK:
        {
            uint32_t div = (R_CPG_CPG_PL6_DDIV_DIVPL6A_SET_Msk & R_CPG->CPG_PL6_DDIV) >>
                           R_CPG_CPG_PL6_DDIV_DIVPL6A_SET_Pos;
            if (BSP_CLOCKS_PL6A_DIV_32 == div)
            {
                div = div + 1;
            }

            g_clock_freq[FSP_PRIV_CLOCK_I2CLK] = (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL6B_SET_DIV)
        case FSP_PRIV_CLOCK_I3CLK:
        {
            uint32_t div = (R_CPG_CPG_PL6_DDIV_DIVPL6B_SET_Msk & R_CPG->CPG_PL6_DDIV) >>
                           R_CPG_CPG_PL6_DDIV_DIVPL6B_SET_Pos;
            if (BSP_CLOCKS_PL6B_DIV_32 == div)
            {
                div = div + 1;
            }

            g_clock_freq[FSP_PRIV_CLOCK_I3CLK] = (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_SELPL4_SET_SOURCE) || defined(BSP_CFG_SEL_PLL4_SET_SOURCE)
        case FSP_PRIV_CLOCK_S0CLK:
        {
 #if defined(BSP_CFG_SELPL4_SET_SOURCE)
            uint32_t sel = (R_CPG_CPG_PLL_DSEL_SELPL4_SET_Msk & R_CPG->CPG_PLL_DSEL) >>
                           R_CPG_CPG_PLL_DSEL_SELPL4_SET_Pos;
 #endif
 #if defined(BSP_CFG_SEL_PLL4_SET_SOURCE)
            uint32_t sel = (R_CPG_CPG_PLL_DSEL_SEL_PLL4_SET_Msk & R_CPG->CPG_PLL_DSEL) >>
                           R_CPG_CPG_PLL_DSEL_SEL_PLL4_SET_Pos;
 #endif
            if (BSP_CLOCKS_SOURCE_CLOCK_OSC_0024 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_S0CLK] = BSP_CFG_CLOCK_OSCCLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_1000 /
                                                     BSP_PRV_FIXED_DIVISION_RATIO_2;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_S0CLK] = BSP_CFG_CLOCK_PLL4_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2;
            }

            break;
        }
#endif

#if defined(BSP_CFG_SELOCTA_SET_SOURCE) && defined(BSP_CFG_DIVOCTA_SET_DIV)
        case FSP_PRIV_CLOCK_OC0CLK:
        case FSP_PRIV_CLOCK_OC1CLK:
        {
            uint32_t sel = (R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Msk & R_CPG->CPG_OCTA_SSEL) >>
                           R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Pos;
            uint32_t div =
                ((R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Msk & R_CPG->CPG_OCTA_DDIV) >> R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Pos);
            if (BSP_CLOCKS_OCTA_DIV_32 == div)
            {
                div = div + 1;
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] =
                    (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] = (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] = (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
            }

            g_clock_freq[FSP_PRIV_CLOCK_OC1CLK] = g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] / BSP_PRV_FIXED_DIVISION_RATIO_2;

            break;
        }
#endif

#if defined(BSP_CFG_SELSPI_SET_SOURCE) && defined(BSP_CFG_DIVSPI_SET_DIV)
        case FSP_PRIV_CLOCK_SPI0CLK:
        case FSP_PRIV_CLOCK_SPI1CLK:
        {
            uint32_t sel = (R_CPG_CPG_SPI_SSEL_SELSPI_SET_Msk & R_CPG->CPG_SPI_SSEL) >>
                           R_CPG_CPG_SPI_SSEL_SELSPI_SET_Pos;
            uint32_t div =
                ((R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Msk & R_CPG->CPG_SPI_DDIV) >> R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Pos);
            if (BSP_CLOCKS_SPI_DIV_32 == div)
            {
                div = div + 1;
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] =
                    (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
            }

            g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK] = g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] /
                                                   BSP_PRV_FIXED_DIVISION_RATIO_2;

            break;
        }
#endif

#if defined(BSP_CFG_SEL_XSPI_SET_SOURCE) && defined(BSP_CFG_DIV_XSPI_SET_DIV)
        case FSP_PRIV_CLOCK_SPI0CLK:
        case FSP_PRIV_CLOCK_SPI1CLK:
        {
            uint32_t sel = (R_CPG_CPG_XSPI_SSEL_SEL_XSPI_SET_Msk & R_CPG->CPG_XSPI_SSEL) >>
                           R_CPG_CPG_XSPI_SSEL_SEL_XSPI_SET_Pos;
            uint32_t div = 2 *
                           (((R_CPG_CPG_XSPI_DDIV_DIV_XSPI_SET_Msk & R_CPG->CPG_XSPI_DDIV) >>
                             R_CPG_CPG_XSPI_DDIV_DIV_XSPI_SET_Pos) +
                            1);

            if (BSP_CLOCKS_SOURCE_CLOCK_XSPI_800 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) / div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_XSPI_600 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = (BSP_CFG_CLOCK_PLL1_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) / div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_XSPI_522 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_3) / div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = BSP_CFG_CLOCK_PLL6_HZ / div;
            }

            g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK] = g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] /
                                                   BSP_PRV_FIXED_DIVISION_RATIO_2;

            break;
        }
#endif

#if defined(BSP_CFG_SEL_SDHI0_SET_SOURCE) && defined(BSP_CFG_DIVSDHI0_SET_DIV)
        case FSP_PRIV_CLOCK_SD0CLK:
        {
            uint32_t sel = (R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Msk & R_CPG->CPG_SDHI_DSEL) >>
                           R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Pos;
            uint32_t div =
                ((R_CPG_CPG_SDHI_DDIV_DIVSDHI0_SET_Msk & R_CPG->CPG_SDHI_DDIV) >> R_CPG_CPG_SDHI_DDIV_DIVSDHI0_SET_Pos);

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_800 == sel)
            {
 #if defined(BSP_CFG_CLOCK_PLL2_1600_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD0CLK] = (BSP_CFG_CLOCK_PLL2_1600_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >>
                                                      div;
 #endif
 #if defined(BSP_CFG_CLOCK_PLL2_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD0CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
 #endif
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL1_600 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SD0CLK] = (BSP_CFG_CLOCK_PLL1_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >>
                                                      div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SD0CLK] = BSP_CFG_CLOCK_PLL6_HZ >> div;
            }
            else
            {
 #if defined(BSP_CFG_CLOCK_PLL2_1600_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD0CLK] = (BSP_CFG_CLOCK_PLL2_1600_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >>
                                                      div;
 #endif
 #if defined(BSP_CFG_CLOCK_PLL2_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD0CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
 #endif
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_SDHI1_SET_SOURCE) && defined(BSP_CFG_DIVSDHI1_SET_DIV)
        case FSP_PRIV_CLOCK_SD1CLK:
        {
            uint32_t sel = (R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Msk & R_CPG->CPG_SDHI_DSEL) >>
                           R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Pos;
            uint32_t div =
                ((R_CPG_CPG_SDHI_DDIV_DIVSDHI1_SET_Msk & R_CPG->CPG_SDHI_DDIV) >> R_CPG_CPG_SDHI_DDIV_DIVSDHI1_SET_Pos);

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_800 == sel)
            {
 #if defined(BSP_CFG_CLOCK_PLL2_1600_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD1CLK] = (BSP_CFG_CLOCK_PLL2_1600_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >>
                                                      div;
 #endif
 #if defined(BSP_CFG_CLOCK_PLL2_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD1CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
 #endif
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL1_600 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SD1CLK] = (BSP_CFG_CLOCK_PLL1_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >>
                                                      div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SD1CLK] = BSP_CFG_CLOCK_PLL6_HZ >> div;
            }
            else
            {
 #if defined(BSP_CFG_CLOCK_PLL2_1600_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD1CLK] = (BSP_CFG_CLOCK_PLL2_1600_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >>
                                                      div;
 #endif
 #if defined(BSP_CFG_CLOCK_PLL2_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD1CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
 #endif
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_SDHI2_SET_SOURCE) && defined(BSP_CFG_DIVSDHI2_SET_DIV)
        case FSP_PRIV_CLOCK_SD2CLK:
        {
            uint32_t sel = (R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Msk & R_CPG->CPG_SDHI_DSEL) >>
                           R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Pos;
            uint32_t div =
                ((R_CPG_CPG_SDHI_DDIV_DIVSDHI2_SET_Msk & R_CPG->CPG_SDHI_DDIV) >> R_CPG_CPG_SDHI_DDIV_DIVSDHI2_SET_Pos);

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_800 == sel)
            {
 #if defined(BSP_CFG_CLOCK_PLL2_1600_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD2CLK] = (BSP_CFG_CLOCK_PLL2_1600_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >>
                                                      div;
 #endif
 #if defined(BSP_CFG_CLOCK_PLL2_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD2CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
 #endif
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL1_600 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SD2CLK] = (BSP_CFG_CLOCK_PLL1_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >>
                                                      div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_SD2CLK] = BSP_CFG_CLOCK_PLL6_HZ >> div;
            }
            else
            {
 #if defined(BSP_CFG_CLOCK_PLL2_1600_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD2CLK] = (BSP_CFG_CLOCK_PLL2_1600_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >>
                                                      div;
 #endif
 #if defined(BSP_CFG_CLOCK_PLL2_HZ)
                g_clock_freq[FSP_PRIV_CLOCK_SD2CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
 #endif
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL2B_SET_DIV)
        case FSP_PRIV_CLOCK_P0CLK:
        {
            uint32_t div = (R_CPG_CPG_PL2_DDIV_DIVPL2B_SET_Msk & R_CPG->CPG_PL2_DDIV) >>
                           R_CPG_CPG_PL2_DDIV_DIVPL2B_SET_Pos;
            if (BSP_CLOCKS_PL2B_DIV_32 == div)
            {
                div = div + 1;
            }

            g_clock_freq[FSP_PRIV_CLOCK_P0CLK] =
                (BSP_CFG_CLOCK_PLL2_1600_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_8) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_PLL2_B_SET_DIV)
        case FSP_PRIV_CLOCK_P0CLK:
        {
            uint32_t div = ((R_CPG_CPG_PL2_DDIV_DIV_PLL2_B_SET_Msk & R_CPG->CPG_PL2_DDIV) >>
                            R_CPG_CPG_PL2_DDIV_DIV_PLL2_B_SET_Pos);
            if (BSP_CLOCKS_PLL2_100_DIV_256 == div)
            {
                div = div + 2;
            }

            div = div + 3;

            g_clock_freq[FSP_PRIV_CLOCK_P0CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL3A_SET_DIV)
        case FSP_PRIV_CLOCK_P1CLK:
        {
            uint32_t div = (R_CPG_CPG_PL3_DDIV_DIVPL3A_SET_Msk & R_CPG->CPG_PL3_DDIV) >>
                           R_CPG_CPG_PL3_DDIV_DIVPL3A_SET_Pos;
            if (BSP_CLOCKS_PL3A_DIV_32 == div)
            {
                div = div + 1;
            }

            g_clock_freq[FSP_PRIV_CLOCK_P1CLK] =
                (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_PLL3_A_SET_DIV)
        case FSP_PRIV_CLOCK_P1CLK:
        case FSP_PRIV_CLOCK_M6CLK:
        {
            uint32_t div = ((R_CPG_CPG_PL3_DDIV_DIV_PLL3_A_SET_Msk & R_CPG->CPG_PL3_DDIV) >>
                            R_CPG_CPG_PL3_DDIV_DIV_PLL3_A_SET_Pos);
            if (BSP_CLOCKS_PLL3_200_DIV_128 == div)
            {
                div = div + 2;
            }

            div = div + 2;

            g_clock_freq[FSP_PRIV_CLOCK_P1CLK] = (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
            g_clock_freq[FSP_PRIV_CLOCK_M6CLK] = g_clock_freq[FSP_PRIV_CLOCK_P1CLK] / BSP_PRV_FIXED_DIVISION_RATIO_2;

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL3B_SET_DIV)
        case FSP_PRIV_CLOCK_P2CLK:
        {
            uint32_t div = (R_CPG_CPG_PL3_DDIV_DIVPL3B_SET_Msk & R_CPG->CPG_PL3_DDIV) >>
                           R_CPG_CPG_PL3_DDIV_DIVPL3B_SET_Pos;
            if (BSP_CLOCKS_PL3B_DIV_32 == div)
            {
                div = div + 1;
            }

            g_clock_freq[FSP_PRIV_CLOCK_P2CLK] =
                (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_8) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_PLL3_B_SET_DIV)
        case FSP_PRIV_CLOCK_P2CLK:
        {
            uint32_t div = ((R_CPG_CPG_PL3_DDIV_DIV_PLL3_B_SET_Msk & R_CPG->CPG_PL3_DDIV) >>
                            R_CPG_CPG_PL3_DDIV_DIV_PLL3_B_SET_Pos);
            if (BSP_CLOCKS_PLL3_100_DIV_256 == div)
            {
                div = div + 2;
            }

            div = div + 3;

            g_clock_freq[FSP_PRIV_CLOCK_P2CLK] =
                (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL3C_SET_DIV)
        case FSP_PRIV_CLOCK_P3CLK:
        {
            uint32_t div = (R_CPG_CPG_PL3_DDIV_DIVPL3C_SET_Msk & R_CPG->CPG_PL3_DDIV) >>
                           R_CPG_CPG_PL3_DDIV_DIVPL3C_SET_Pos;
            if (BSP_CLOCKS_PL3C_DIV_32 == div)
            {
                div = div + 1;
            }

            g_clock_freq[FSP_PRIV_CLOCK_P3CLK] =
                (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_PLL2_A_SET_DIV)
        case FSP_PRIV_CLOCK_P3CLK:
        {
            uint32_t div = ((R_CPG_CPG_PL2_DDIV_DIV_PLL2_A_SET_Msk & R_CPG->CPG_PL2_DDIV) >>
                            R_CPG_CPG_PL2_DDIV_DIV_PLL2_A_SET_Pos);
            if (BSP_CLOCKS_PLL2_200_DIV_128 == div)
            {
                div = div + 2;
            }

            div = div + 2;

            g_clock_freq[FSP_PRIV_CLOCK_P3CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV1_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_I0CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV1_DIVCTL0_Msk & R_CPG->CPG_CDDIV1) >> R_CPG_CPG_CDDIV1_DIVCTL0_Pos;
            g_clock_freq[FSP_PRIV_CLOCK_I0CLK] = BSP_CFG_CLOCK_PLLCA55CLK_HZ >> div;

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV1_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_I1CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV1_DIVCTL1_Msk & R_CPG->CPG_CDDIV1) >> R_CPG_CPG_CDDIV1_DIVCTL1_Pos;
            g_clock_freq[FSP_PRIV_CLOCK_I1CLK] = BSP_CFG_CLOCK_PLLCA55CLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV1_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_I2CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV1_DIVCTL2_Msk & R_CPG->CPG_CDDIV1) >> R_CPG_CPG_CDDIV1_DIVCTL2_Pos;
            g_clock_freq[FSP_PRIV_CLOCK_I2CLK] = BSP_CFG_CLOCK_PLLCA55CLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV1_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_I3CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV1_DIVCTL3_Msk & R_CPG->CPG_CDDIV1) >> R_CPG_CPG_CDDIV1_DIVCTL3_Pos;
            g_clock_freq[FSP_PRIV_CLOCK_I3CLK] = BSP_CFG_CLOCK_PLLCA55CLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV2_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_I4CLK:
        {
            uint32_t div = ((R_CPG_CPG_CDDIV2_DIVCTL0_Msk & R_CPG->CPG_CDDIV2) >> R_CPG_CPG_CDDIV2_DIVCTL0_Pos) + 1;
            g_clock_freq[FSP_PRIV_CLOCK_I4CLK] = (BSP_CFG_CLOCK_PLLCA55CLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL0_SOURCE) && defined(BSP_CFG_SSEL0_SELCTL1_SOURCE) && \
        defined(BSP_CFG_CDDIV0_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_I5CLK:
        {
            uint32_t sel = (R_CPG_CPG_SSEL0_SELCTL0_Msk & R_CPG->CPG_SSEL0) >> R_CPG_CPG_SSEL0_SELCTL0_Pos;
            uint32_t div = (R_CPG_CPG_CDDIV0_DIVCTL3_Msk & R_CPG->CPG_CDDIV0) >> R_CPG_CPG_CDDIV0_DIVCTL3_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL0_SMUX2_CA55_SCLK0 == sel)
            {
                sel = (R_CPG_CPG_SSEL0_SELCTL1_Msk & R_CPG->CPG_SSEL0) >> R_CPG_CPG_SSEL0_SELCTL1_Pos;
                if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLVDO == sel)
                {
                    g_clock_freq[FSP_PRIV_CLOCK_I5CLK] = BSP_CFG_CLOCK_PLLVDOCLK_HZ >> div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_I5CLK] = BSP_CFG_CLOCK_PLLDTYCLK_HZ >> div;
                }
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_I5CLK] = BSP_CFG_CLOCK_PLLCA55CLK_HZ >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV0_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_I7CLK:
        case FSP_PRIV_CLOCK_P0CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV0_DIVCTL1_Msk & R_CPG->CPG_CDDIV0) >> R_CPG_CPG_CDDIV0_DIVCTL1_Pos;
            if (BSP_CLOCKS_PLLCM33_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_I7CLK] = (BSP_CFG_CLOCK_PLLCM33CLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            g_clock_freq[FSP_PRIV_CLOCK_P0CLK] = g_clock_freq[FSP_PRIV_CLOCK_I7CLK] / BSP_PRV_FIXED_DIVISION_RATIO_2;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV0_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_P7CLK:
        case FSP_PRIV_CLOCK_P8CLK:
        case FSP_PRIV_CLOCK_P9CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV0_DIVCTL2_Msk & R_CPG->CPG_CDDIV0) >> R_CPG_CPG_CDDIV0_DIVCTL2_Pos;
            if (BSP_CLOCKS_PLLDTY_ACPU_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_P7CLK] = (BSP_CFG_CLOCK_PLLDTYCLK_HZ >> div) / BSP_PRV_FIXED_DIVISION_RATIO_2;
            g_clock_freq[FSP_PRIV_CLOCK_P8CLK] = (BSP_CFG_CLOCK_PLLDTYCLK_HZ >> div) / BSP_PRV_FIXED_DIVISION_RATIO_4;
            g_clock_freq[FSP_PRIV_CLOCK_P9CLK] = (BSP_CFG_CLOCK_PLLDTYCLK_HZ >> div) / BSP_PRV_FIXED_DIVISION_RATIO_8;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_P11CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV3_DIVCTL2_Msk & R_CPG->CPG_CDDIV3) >> R_CPG_CPG_CDDIV3_DIVCTL2_Pos;
            if (BSP_CLOCKS_PLLDTY_RCPU_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_P11CLK] = (BSP_CFG_CLOCK_PLLDTYCLK_HZ >> div) / BSP_PRV_FIXED_DIVISION_RATIO_4;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV5_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_P12CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV5_DIVCTL0_Msk & R_CPG->CPG_CDDIV5) >> R_CPG_CPG_CDDIV5_DIVCTL0_Pos;
            if (BSP_CLOCKS_PLLDTY_NPU_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_P12CLK] = (BSP_CFG_CLOCK_PLLDTYCLK_HZ >> div) / BSP_PRV_FIXED_DIVISION_RATIO_2;
            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL0_DIV) && defined(BSP_CFG_CSDIV1_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_ADCCLK:
        {
            uint32_t div1 = (R_CPG_CPG_CSDIV1_DIVCTL0_Msk & R_CPG->CPG_CSDIV1) >> R_CPG_CPG_CSDIV1_DIVCTL0_Pos;
            uint32_t div2 = ((R_CPG_CPG_CSDIV1_DIVCTL1_Msk & R_CPG->CPG_CSDIV1) >> R_CPG_CPG_CSDIV1_DIVCTL1_Pos) + 1;
            if (BSP_CLOCKS_PLLCM33_ADC_PCLK_DIV_8 == div1)
            {
                div1 = BSP_PRV_DIVISION_RATIO_8;
            }
            else
            {
                div1 = BSP_PRV_DIVISION_RATIO_10;
            }

            g_clock_freq[FSP_PRIV_CLOCK_ADCCLK] =
                ((BSP_CFG_CLOCK_PLLCM33CLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) / div1) >> div2;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV0_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_ATCLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV0_DIVCTL0_Msk & R_CPG->CPG_CDDIV0) >> R_CPG_CPG_CDDIV0_DIVCTL0_Pos;
            if (BSP_CLOCKS_PLLCM33_CST400_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_ATCLK] = (BSP_CFG_CLOCK_PLLCM33CLK_HZ >> div) / BSP_PRV_FIXED_DIVISION_RATIO_2;
            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL0_DIV) && defined(BSP_CFG_SSEL0_SELCTL2_SOURCE)
        case FSP_PRIV_CLOCK_ETHTX0CLK:
        {
            uint32_t sel = (R_CPG_CPG_SSEL0_SELCTL2_Msk & R_CPG->CPG_SSEL0) >> R_CPG_CPG_SSEL0_SELCTL2_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL2_CSDIV_PLLETH_GBE0 == sel)
            {
                uint32_t div = (R_CPG_CPG_CSDIV0_DIVCTL0_Msk & R_CPG->CPG_CSDIV0) >> R_CPG_CPG_CSDIV0_DIVCTL0_Pos;
                if (BSP_CLOCKS_PLLETH_GBE0_DIV_2 == div)
                {
                    div = BSP_PRV_DIVISION_RATIO_2;
                }
                else if (BSP_CLOCKS_PLLETH_GBE0_DIV_10 == div)
                {
                    div = BSP_PRV_DIVISION_RATIO_10;
                }
                else
                {
                    div = BSP_PRV_DIVISION_RATIO_100;
                }

                g_clock_freq[FSP_PRIV_CLOCK_ETHTX0CLK] = BSP_CFG_CLOCK_PLLETHCLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_4 /
                                                         div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHTX0CLK] = BSP_CFG_CLOCK_ET0_TXC_TXCLK_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL1_DIV) && defined(BSP_CFG_SSEL1_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_ETHTX1CLK:
        {
            uint32_t sel = (R_CPG_CPG_SSEL1_SELCTL0_Msk & R_CPG->CPG_SSEL1) >> R_CPG_CPG_SSEL1_SELCTL0_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL0_CSDIV_PLLETH_GBE1 == sel)
            {
                uint32_t div = (R_CPG_CPG_CSDIV0_DIVCTL1_Msk & R_CPG->CPG_CSDIV0) >> R_CPG_CPG_CSDIV0_DIVCTL1_Pos;
                if (BSP_CLOCKS_PLLETH_GBE1_DIV_2 == div)
                {
                    div = BSP_PRV_DIVISION_RATIO_2;
                }
                else if (BSP_CLOCKS_PLLETH_GBE1_DIV_10 == div)
                {
                    div = BSP_PRV_DIVISION_RATIO_10;
                }
                else
                {
                    div = BSP_PRV_DIVISION_RATIO_100;
                }

                g_clock_freq[FSP_PRIV_CLOCK_ETHTX1CLK] = BSP_CFG_CLOCK_PLLETHCLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_4 /
                                                         div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHTX1CLK] = BSP_CFG_CLOCK_ET1_TXC_TXCLK_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL0_DIV) && defined(BSP_CFG_SSEL0_SELCTL3_SOURCE)
        case FSP_PRIV_CLOCK_ETHRX0CLK:
        {
            uint32_t sel = (R_CPG_CPG_SSEL0_SELCTL3_Msk & R_CPG->CPG_SSEL0) >> R_CPG_CPG_SSEL0_SELCTL3_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL3_CSDIV_PLLETH_GBE0 == sel)
            {
                uint32_t div = (R_CPG_CPG_CSDIV0_DIVCTL0_Msk & R_CPG->CPG_CSDIV0) >> R_CPG_CPG_CSDIV0_DIVCTL0_Pos;
                if (BSP_CLOCKS_PLLETH_GBE0_DIV_2 == div)
                {
                    div = BSP_PRV_DIVISION_RATIO_2;
                }
                else if (BSP_CLOCKS_PLLETH_GBE0_DIV_10 == div)
                {
                    div = BSP_PRV_DIVISION_RATIO_10;
                }
                else
                {
                    div = BSP_PRV_DIVISION_RATIO_100;
                }

                g_clock_freq[FSP_PRIV_CLOCK_ETHRX0CLK] = BSP_CFG_CLOCK_PLLETHCLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_4 /
                                                         div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHRX0CLK] = BSP_CFG_CLOCK_ET0_RXC_RXCLK_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL1_DIV) && defined(BSP_CFG_SSEL1_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_ETHRX1CLK:
        {
            uint32_t sel = (R_CPG_CPG_SSEL1_SELCTL1_Msk & R_CPG->CPG_SSEL1) >> R_CPG_CPG_SSEL1_SELCTL1_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL1_CSDIV_PLLETH_GBE1 == sel)
            {
                uint32_t div = (R_CPG_CPG_CSDIV0_DIVCTL1_Msk & R_CPG->CPG_CSDIV0) >> R_CPG_CPG_CSDIV0_DIVCTL1_Pos;
                if (BSP_CLOCKS_PLLETH_GBE1_DIV_2 == div)
                {
                    div = BSP_PRV_DIVISION_RATIO_2;
                }
                else if (BSP_CLOCKS_PLLETH_GBE1_DIV_10 == div)
                {
                    div = BSP_PRV_DIVISION_RATIO_10;
                }
                else
                {
                    div = BSP_PRV_DIVISION_RATIO_100;
                }

                g_clock_freq[FSP_PRIV_CLOCK_ETHRX1CLK] = BSP_CFG_CLOCK_PLLETHCLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_4 /
                                                         div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHRX1CLK] = BSP_CFG_CLOCK_ET1_RXC_RXCLK_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_GPUCLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV3_DIVCTL1_Msk & R_CPG->CPG_CDDIV3) >> R_CPG_CPG_CDDIV3_DIVCTL1_Pos;
            if (BSP_CLOCKS_PLLVDO_GPU_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_GPUCLK] = BSP_CFG_CLOCK_PLLVDOCLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV4_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_NPUCLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV4_DIVCTL3_Msk & R_CPG->CPG_CDDIV4) >> R_CPG_CPG_CDDIV4_DIVCTL3_Pos;
            g_clock_freq[FSP_PRIV_CLOCK_NPUCLK] = BSP_CFG_CLOCK_PLLETHCLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_LPCLK:
        {
            uint32_t div = ((R_CPG_CPG_CSDIV0_DIVCTL2_Msk & R_CPG->CPG_CSDIV0) >> R_CPG_CPG_CSDIV0_DIVCTL2_Pos) + 4;
            g_clock_freq[FSP_PRIV_CLOCK_LPCLK] = (BSP_CFG_CLOCK_PLLETHCLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_M0CLK:
        {
            uint32_t div = ((R_CPG_CPG_CDDIV3_DIVCTL3_Msk & R_CPG->CPG_CDDIV3) >> R_CPG_CPG_CDDIV3_DIVCTL3_Pos) + 1;
            g_clock_freq[FSP_PRIV_CLOCK_M0CLK] = BSP_CFG_CLOCK_PLLVDOCLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL2_DIV) && defined(BSP_CFG_SSEL3_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_M4CLK:
        {
            uint32_t sel = (R_CPG_CPG_SSEL3_SELCTL0_Msk & R_CPG->CPG_SSEL3) >> R_CPG_CPG_SSEL3_SELCTL0_Pos;
            uint32_t div;
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL3_SELCTL0_CDIV7_DSI0_CLK == sel)
            {
                div = BSP_PRV_FIXED_DIVISION_RATIO_7;
            }
            else
            {
                div = (((R_CPG_CPG_CSDIV1_DIVCTL2_Msk & R_CPG->CPG_CSDIV1) >> R_CPG_CPG_CSDIV1_DIVCTL2_Pos) + 1) * 2;
            }

            g_clock_freq[FSP_PRIV_CLOCK_M4CLK] = BSP_CFG_CLOCK_PLLDSI0CLK_HZ / div;
            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL3_DIV) && defined(BSP_CFG_SSEL3_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_M5CLK:
        {
            uint32_t sel = (R_CPG_CPG_SSEL3_SELCTL1_Msk & R_CPG->CPG_SSEL3) >> R_CPG_CPG_SSEL3_SELCTL1_Pos;
            uint32_t div;
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL3_SELCTL1_CDIV7_DSI1_CLK == sel)
            {
                div = BSP_PRV_FIXED_DIVISION_RATIO_7;
            }
            else
            {
                div = (((R_CPG_CPG_CSDIV1_DIVCTL3_Msk & R_CPG->CPG_CSDIV1) >> R_CPG_CPG_CSDIV1_DIVCTL3_Pos) + 1) * 2;
            }

            g_clock_freq[FSP_PRIV_CLOCK_M5CLK] = BSP_CFG_CLOCK_PLLDSI1CLK_HZ / div;
            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL2_SOURCE) && defined(BSP_CFG_SSEL1_SELCTL3_SOURCE) && \
        defined(BSP_CFG_CSDIV0_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_SPI0CLK:
        case FSP_PRIV_CLOCK_SPI1CLK:
        {
            uint32_t sel = (R_CPG_CPG_SSEL1_SELCTL3_Msk & R_CPG->CPG_SSEL1) >> R_CPG_CPG_SSEL1_SELCTL3_Pos;
            uint32_t div = ((R_CPG_CPG_CSDIV0_DIVCTL3_Msk & R_CPG->CPG_CSDIV0) >> R_CPG_CPG_CSDIV0_DIVCTL3_Pos) + 1;
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL3_SMUX2_XSPI_CLK0 == sel)
            {
                sel = (R_CPG_CPG_SSEL1_SELCTL2_Msk & R_CPG->CPG_SSEL1) >> R_CPG_CPG_SSEL1_SELCTL2_Pos;
                if (BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL2_CDIV3_CLK533_PLLCM33_FIX == sel)
                {
                    g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] =
                        (BSP_CFG_CLOCK_PLLCM33CLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_3) >> div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] =
                        (BSP_CFG_CLOCK_PLLCM33CLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
                }
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = (BSP_CFG_CLOCK_PLLCM33CLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5) >>
                                                       div;
            }

            g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK] = g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] /
                                                   BSP_PRV_FIXED_DIVISION_RATIO_2;
            break;
        }
#endif

#if defined(BSP_CFG_DIV_CORE0_SET_DIV)
        case FSP_PRIV_CLOCK_IC0CLK:
        {
            uint32_t div =
                ((R_CPG_CPG_CA55CORE_DDIV_DIV_CORE0_SET_Msk & R_CPG->CPG_CA55CORE_DDIV) >>
                 R_CPG_CPG_CA55CORE_DDIV_DIV_CORE0_SET_Pos);
            g_clock_freq[FSP_PRIV_CLOCK_IC0CLK] = BSP_CFG_CLOCK_PLL1_HZ >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_CORE1_SET_DIV)
        case FSP_PRIV_CLOCK_IC1CLK:
        {
            uint32_t div =
                ((R_CPG_CPG_CA55CORE_DDIV_DIV_CORE1_SET_Msk & R_CPG->CPG_CA55CORE_DDIV) >>
                 R_CPG_CPG_CA55CORE_DDIV_DIV_CORE1_SET_Pos);
            g_clock_freq[FSP_PRIV_CLOCK_IC1CLK] = BSP_CFG_CLOCK_PLL1_HZ >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_CORE2_SET_DIV)
        case FSP_PRIV_CLOCK_IC2CLK:
        {
            uint32_t div =
                ((R_CPG_CPG_CA55CORE_DDIV_DIV_CORE2_SET_Msk & R_CPG->CPG_CA55CORE_DDIV) >>
                 R_CPG_CPG_CA55CORE_DDIV_DIV_CORE2_SET_Pos);
            g_clock_freq[FSP_PRIV_CLOCK_IC2CLK] = BSP_CFG_CLOCK_PLL1_HZ >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_CORE3_SET_DIV)
        case FSP_PRIV_CLOCK_IC3CLK:
        {
            uint32_t div =
                ((R_CPG_CPG_CA55CORE_DDIV_DIV_CORE3_SET_Msk & R_CPG->CPG_CA55CORE_DDIV) >>
                 R_CPG_CPG_CA55CORE_DDIV_DIV_CORE3_SET_Pos);
            g_clock_freq[FSP_PRIV_CLOCK_IC3CLK] = BSP_CFG_CLOCK_PLL1_HZ >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_CLKQSPI_SET_DIV)
        case FSP_PRIV_CLOCK_P7CLK:
        {
            uint32_t div = ((R_CPG_CPG_PL2_DDIV_DIV_CLKQSPI_SET_Msk & R_CPG->CPG_PL2_DDIV) >>
                            R_CPG_CPG_PL2_DDIV_DIV_CLKQSPI_SET_Pos);
            if (BSP_CLOCKS_PLL2_CLKQSPI_DIV_128 == div)
            {
                div = div + 2;
            }

            div = div + 2;

            g_clock_freq[FSP_PRIV_CLOCK_P7CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI0_SET_SOURCE) && defined(BSP_CFG_DIV_RSCI0_SET_DIV)
        case FSP_PRIV_CLOCK_P13CLK:
        {
            uint32_t sel = (R_CPG_CPG_RSCI_SSEL_SEL_RSCI0_SET_Msk & R_CPG->CPG_RSCI_SSEL) >>
                           R_CPG_CPG_RSCI_SSEL_SEL_RSCI0_SET_Pos;
            uint32_t div = ((R_CPG_CPG_RSCI_DDIV_DIV_RSCI0_SET_Msk & R_CPG->CPG_RSCI_DDIV) >>
                            R_CPG_CPG_RSCI_DDIV_DIV_RSCI0_SET_Pos) + 1;
            if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_320 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P13CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P13CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_228 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P13CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_7) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_P13CLK] =
                    (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI1_SET_SOURCE) && defined(BSP_CFG_DIV_RSCI1_SET_DIV)
        case FSP_PRIV_CLOCK_P14CLK:
        {
            uint32_t sel = (R_CPG_CPG_RSCI_SSEL_SEL_RSCI1_SET_Msk & R_CPG->CPG_RSCI_SSEL) >>
                           R_CPG_CPG_RSCI_SSEL_SEL_RSCI1_SET_Pos;
            uint32_t div = ((R_CPG_CPG_RSCI_DDIV_DIV_RSCI1_SET_Msk & R_CPG->CPG_RSCI_DDIV) >>
                            R_CPG_CPG_RSCI_DDIV_DIV_RSCI1_SET_Pos) + 1;
            if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_320 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P14CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P14CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_228 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P14CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_7) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_P14CLK] =
                    (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI2_SET_SOURCE) && defined(BSP_CFG_DIV_RSCI2_SET_DIV)
        case FSP_PRIV_CLOCK_P15CLK:
        {
            uint32_t sel = (R_CPG_CPG_RSCI_SSEL_SEL_RSCI2_SET_Msk & R_CPG->CPG_RSCI_SSEL) >>
                           R_CPG_CPG_RSCI_SSEL_SEL_RSCI2_SET_Pos;
            uint32_t div = ((R_CPG_CPG_RSCI_DDIV_DIV_RSCI2_SET_Msk & R_CPG->CPG_RSCI_DDIV) >>
                            R_CPG_CPG_RSCI_DDIV_DIV_RSCI2_SET_Pos) + 1;
            if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_320 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P15CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P15CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_228 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P15CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_7) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_P15CLK] =
                    (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI3_SET_SOURCE) && defined(BSP_CFG_DIV_RSCI3_SET_DIV)
        case FSP_PRIV_CLOCK_P16CLK:
        {
            uint32_t sel = (R_CPG_CPG_RSCI_SSEL_SEL_RSCI3_SET_Msk & R_CPG->CPG_RSCI_SSEL) >>
                           R_CPG_CPG_RSCI_SSEL_SEL_RSCI3_SET_Pos;
            uint32_t div = ((R_CPG_CPG_RSCI_DDIV_DIV_RSCI3_SET_Msk & R_CPG->CPG_RSCI_DDIV) >>
                            R_CPG_CPG_RSCI_DDIV_DIV_RSCI3_SET_Pos) + 1;
            if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_320 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P16CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P16CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSCI_228 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P16CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_7) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_P16CLK] =
                    (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI0_SET_SOURCE) && defined(BSP_CFG_DIV_RSPI0_SET_DIV)
        case FSP_PRIV_CLOCK_P17CLK:
        {
            uint32_t sel = (R_CPG_CPG_RSPI_SSEL_SEL_RSPI0_SET_Msk & R_CPG->CPG_RSPI_SSEL) >>
                           R_CPG_CPG_RSPI_SSEL_SEL_RSPI0_SET_Pos;
            uint32_t div = (R_CPG_CPG_RSPI_DDIV_DIV_RSPI0_SET_Msk & R_CPG->CPG_RSPI_DDIV) >>
                           R_CPG_CPG_RSPI_DDIV_DIV_RSPI0_SET_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_RSPI_320 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P17CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSPI_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P17CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSPI_228 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P17CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_7) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_P17CLK] =
                    (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI1_SET_SOURCE) && defined(BSP_CFG_DIV_RSPI1_SET_DIV)
        case FSP_PRIV_CLOCK_P18CLK:
        {
            uint32_t sel = (R_CPG_CPG_RSPI_SSEL_SEL_RSPI1_SET_Msk & R_CPG->CPG_RSPI_SSEL) >>
                           R_CPG_CPG_RSPI_SSEL_SEL_RSPI1_SET_Pos;
            uint32_t div = (R_CPG_CPG_RSPI_DDIV_DIV_RSPI1_SET_Msk & R_CPG->CPG_RSPI_DDIV) >>
                           R_CPG_CPG_RSPI_DDIV_DIV_RSPI1_SET_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_RSPI_320 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P18CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSPI_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P18CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSPI_228 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P18CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_7) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_P18CLK] =
                    (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI2_SET_SOURCE) && defined(BSP_CFG_DIV_RSPI2_SET_DIV)
        case FSP_PRIV_CLOCK_P19CLK:
        {
            uint32_t sel = (R_CPG_CPG_RSPI_SSEL_SEL_RSPI2_SET_Msk & R_CPG->CPG_RSPI_SSEL) >>
                           R_CPG_CPG_RSPI_SSEL_SEL_RSPI2_SET_Pos;
            uint32_t div = (R_CPG_CPG_RSPI_DDIV_DIV_RSPI2_SET_Msk & R_CPG->CPG_RSPI_DDIV) >>
                           R_CPG_CPG_RSPI_DDIV_DIV_RSPI2_SET_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_RSPI_320 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P19CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSPI_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P19CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_RSPI_228 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_P19CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_7) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_P19CLK] =
                    (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_SET_DIV)
        case FSP_PRIV_CLOCK_M1CLK:
        {
            uint32_t div =
                ((R_CPG_CPG_DSI_DDIV_DIV_DSI_SET_Msk & R_CPG->CPG_DSI_DDIV) >> R_CPG_CPG_DSI_DDIV_DIV_DSI_SET_Pos) + 4;
            g_clock_freq[FSP_PRIV_CLOCK_M1CLK] = (BSP_CFG_CLOCK_PLL2_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_C_SET_DIV)
        case FSP_PRIV_CLOCK_M2CLK:
        {
            uint32_t div =
                ((R_CPG_CPG_DSI_SDIV_DIV_DSI_C_SET_Msk & R_CPG->CPG_DSI_SDIV) >> R_CPG_CPG_DSI_SDIV_DIV_DSI_C_SET_Pos);
            g_clock_freq[FSP_PRIV_CLOCK_M2CLK] = BSP_CFG_CLOCK_PLL7_HZ >> div;

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_A_SET_DIV) && defined(BSP_CFG_DIV_DSI_B_SET_DIV) && defined(BSP_CFG_SEL_DSI_SET_SOURCE)
        case FSP_PRIV_CLOCK_M3CLK:
        {
            uint32_t sel = (R_CPG_CPG_DSI_SSEL_SEL_DSI_SET_Msk & R_CPG->CPG_DSI_SSEL) >>
                           R_CPG_CPG_DSI_SSEL_SEL_DSI_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_DIV_DSI_DIV1TO2_LVDS_DIV_7 == sel)
            {
                uint32_t div =
                    ((R_CPG_CPG_DSI_SDIV_DIV_DSI_C_SET_Msk & R_CPG->CPG_DSI_SDIV) >>
                     R_CPG_CPG_DSI_SDIV_DIV_DSI_C_SET_Pos);
                g_clock_freq[FSP_PRIV_CLOCK_M3CLK] =
                    (uint32_t) ((BSP_CFG_CLOCK_PLL7_HZ >> div) / BSP_PRV_FIXED_DIVISION_RATIO_7);
            }
            else
            {
                uint32_t div_a =
                    ((R_CPG_CPG_DSI_SDIV_DIV_DSI_A_SET_Msk & R_CPG->CPG_DSI_SDIV) >>
                     R_CPG_CPG_DSI_SDIV_DIV_DSI_A_SET_Pos);
                uint32_t div_b =
                    ((R_CPG_CPG_DSI_SDIV_DIV_DSI_B_SET_Msk & R_CPG->CPG_DSI_SDIV) >>
                     R_CPG_CPG_DSI_SDIV_DIV_DSI_B_SET_Pos) +
                    1;
                g_clock_freq[FSP_PRIV_CLOCK_M3CLK] = (uint32_t) ((BSP_CFG_CLOCK_PLL7_HZ >> div_a) / div_b);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_A_SET_DIV) && defined(BSP_CFG_SEL_ETH0A_SET_SOURCE) &&     \
        defined(BSP_CFG_SEL_ETH0C_SET_SOURCE) && defined(BSP_CFG_DIV_ETH_B_SET_DIV) && \
        defined(BSP_CFG_SEL_ETH0D_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHTX01CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH0D_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH0D_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_NORMAL_MODE == sel)
            {
                sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH0A_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                      R_CPG_CPG_ETH_SSEL_SEL_ETH0A_SET_Pos;

                if (BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH0_TR == sel)
                {
                    uint32_t div =
                        ((R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                         R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Pos);
                    if (BSP_CLOCKS_ETH0_TR_DIV_4 == div)
                    {
                        div = 4;
                    }
                    else if (BSP_CLOCKS_ETH0_TR_DIV_20 == div)
                    {
                        div = 20;
                    }
                    else
                    {
                        div = 200;
                    }

                    g_clock_freq[FSP_PRIV_CLOCK_ETHTX01CLK] = BSP_CFG_CLOCK_PLL6_HZ / div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHTX01CLK] = ETH0_TXC_TX_CLK_IN_HZ;
                }
            }
            else
            {
                uint32_t div =
                    ((R_CPG_CPG_ETH_SDIV_DIV_ETH_B_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                     R_CPG_CPG_ETH_SDIV_DIV_ETH_B_SET_Pos);

                if (BSP_CLOCKS_ETH0_RM_DIV_2 == div)
                {
                    div = 2;
                }
                else
                {
                    div = 20;
                }

                sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH0C_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                      R_CPG_CPG_ETH_SSEL_SEL_ETH0C_SET_Pos;

                if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_DIV_10 == sel)
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHTX01CLK] =
                        (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_10) / div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHTX01CLK] = ETH0_RXC_RX_CLK_IN_HZ / div;
                }
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_A_SET_DIV) && defined(BSP_CFG_SEL_ETH0B_SET_SOURCE) &&     \
        defined(BSP_CFG_SEL_ETH0C_SET_SOURCE) && defined(BSP_CFG_DIV_ETH_B_SET_DIV) && \
        defined(BSP_CFG_SEL_ETH0E_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHRX01CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH0E_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH0E_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_NORMAL_MODE == sel)
            {
                sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH0B_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                      R_CPG_CPG_ETH_SSEL_SEL_ETH0B_SET_Pos;

                if (BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH0_TR == sel)
                {
                    uint32_t div =
                        ((R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                         R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Pos);
                    if (BSP_CLOCKS_ETH0_TR_DIV_4 == div)
                    {
                        div = 4;
                    }
                    else if (BSP_CLOCKS_ETH0_TR_DIV_20 == div)
                    {
                        div = 20;
                    }
                    else
                    {
                        div = 200;
                    }

                    g_clock_freq[FSP_PRIV_CLOCK_ETHRX01CLK] = BSP_CFG_CLOCK_PLL6_HZ / div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHRX01CLK] = ETH0_RXC_RX_CLK_IN_HZ;
                }
            }
            else
            {
                uint32_t div =
                    ((R_CPG_CPG_ETH_SDIV_DIV_ETH_B_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                     R_CPG_CPG_ETH_SDIV_DIV_ETH_B_SET_Pos);

                if (BSP_CLOCKS_ETH0_RM_DIV_2 == div)
                {
                    div = 2;
                }
                else
                {
                    div = 20;
                }

                sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH0C_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                      R_CPG_CPG_ETH_SSEL_SEL_ETH0C_SET_Pos;

                if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_DIV_10 == sel)
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHRX01CLK] =
                        (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_10) / div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHRX01CLK] = ETH0_RXC_RX_CLK_IN_HZ / div;
                }
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0C_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHRM0CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH0C_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH0C_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_DIV_10 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHRM0CLK] = (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_10);
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHRM0CLK] = ETH0_RXC_RX_CLK_IN_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_A_SET_DIV) && defined(BSP_CFG_SEL_ETH0A_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHTX02CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH0A_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH0A_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH0_TR == sel)
            {
                uint32_t div =
                    ((R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                     R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Pos);
                if (BSP_CLOCKS_ETH0_TR_DIV_4 == div)
                {
                    div = 4;
                }
                else if (BSP_CLOCKS_ETH0_TR_DIV_20 == div)
                {
                    div = 20;
                }
                else
                {
                    div = 200;
                }

                g_clock_freq[FSP_PRIV_CLOCK_ETHTX02CLK] = BSP_CFG_CLOCK_PLL6_HZ / div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHTX02CLK] = ETH0_TXC_TX_CLK_IN_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_A_SET_DIV) && defined(BSP_CFG_SEL_ETH0B_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHRX02CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH0B_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH0B_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH0_TR == sel)
            {
                uint32_t div =
                    ((R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                     R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Pos);
                if (BSP_CLOCKS_ETH0_TR_DIV_4 == div)
                {
                    div = 4;
                }
                else if (BSP_CLOCKS_ETH0_TR_DIV_20 == div)
                {
                    div = 20;
                }
                else
                {
                    div = 200;
                }

                g_clock_freq[FSP_PRIV_CLOCK_ETHRX02CLK] = BSP_CFG_CLOCK_PLL6_HZ / div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHRX02CLK] = ETH0_RXC_RX_CLK_IN_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_C_SET_DIV) && defined(BSP_CFG_SEL_ETH1A_SET_SOURCE) &&     \
        defined(BSP_CFG_SEL_ETH1C_SET_SOURCE) && defined(BSP_CFG_DIV_ETH_D_SET_DIV) && \
        defined(BSP_CFG_SEL_ETH1D_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHTX11CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH1D_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH1D_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_NORMAL_MODE == sel)
            {
                sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH1A_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                      R_CPG_CPG_ETH_SSEL_SEL_ETH1A_SET_Pos;

                if (BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH1_TR == sel)
                {
                    uint32_t div =
                        ((R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                         R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Pos);
                    if (BSP_CLOCKS_ETH1_TR_DIV_4 == div)
                    {
                        div = 4;
                    }
                    else if (BSP_CLOCKS_ETH1_TR_DIV_20 == div)
                    {
                        div = 20;
                    }
                    else
                    {
                        div = 200;
                    }

                    g_clock_freq[FSP_PRIV_CLOCK_ETHTX11CLK] = BSP_CFG_CLOCK_PLL6_HZ / div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHTX11CLK] = ETH0_TXC_TX_CLK_IN_HZ;
                }
            }
            else
            {
                uint32_t div =
                    ((R_CPG_CPG_ETH_SDIV_DIV_ETH_D_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                     R_CPG_CPG_ETH_SDIV_DIV_ETH_D_SET_Pos);

                if (BSP_CLOCKS_ETH1_RM_DIV_2 == div)
                {
                    div = 2;
                }
                else
                {
                    div = 20;
                }

                sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH1C_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                      R_CPG_CPG_ETH_SSEL_SEL_ETH1C_SET_Pos;

                if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_DIV_10 == sel)
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHTX11CLK] =
                        (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_10) / div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHTX11CLK] = ETH0_RXC_RX_CLK_IN_HZ / div;
                }
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_C_SET_DIV) && defined(BSP_CFG_SEL_ETH1B_SET_SOURCE) &&     \
        defined(BSP_CFG_SEL_ETH1C_SET_SOURCE) && defined(BSP_CFG_DIV_ETH_D_SET_DIV) && \
        defined(BSP_CFG_SEL_ETH1E_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHRX11CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH1E_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH1E_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_NORMAL_MODE == sel)
            {
                sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH1B_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                      R_CPG_CPG_ETH_SSEL_SEL_ETH1B_SET_Pos;

                if (BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH1_TR == sel)
                {
                    uint32_t div =
                        ((R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                         R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Pos);
                    if (BSP_CLOCKS_ETH1_TR_DIV_4 == div)
                    {
                        div = 4;
                    }
                    else if (BSP_CLOCKS_ETH1_TR_DIV_20 == div)
                    {
                        div = 20;
                    }
                    else
                    {
                        div = 200;
                    }

                    g_clock_freq[FSP_PRIV_CLOCK_ETHRX11CLK] = BSP_CFG_CLOCK_PLL6_HZ / div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHRX11CLK] = ETH0_RXC_RX_CLK_IN_HZ;
                }
            }
            else
            {
                uint32_t div =
                    ((R_CPG_CPG_ETH_SDIV_DIV_ETH_D_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                     R_CPG_CPG_ETH_SDIV_DIV_ETH_D_SET_Pos);

                if (BSP_CLOCKS_ETH1_RM_DIV_2 == div)
                {
                    div = 2;
                }
                else
                {
                    div = 20;
                }

                sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH1C_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                      R_CPG_CPG_ETH_SSEL_SEL_ETH1C_SET_Pos;

                if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_DIV_10 == sel)
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHRX11CLK] =
                        (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_10) / div;
                }
                else
                {
                    g_clock_freq[FSP_PRIV_CLOCK_ETHRX11CLK] = ETH0_RXC_RX_CLK_IN_HZ / div;
                }
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1C_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHRM1CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH1C_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH1C_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_DIV_10 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHRM1CLK] = (BSP_CFG_CLOCK_PLL6_HZ / BSP_PRV_FIXED_DIVISION_RATIO_10);
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHRM1CLK] = ETH0_RXC_RX_CLK_IN_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_C_SET_DIV) && defined(BSP_CFG_SEL_ETH1A_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHTX12CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH1A_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH1A_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH1_TR == sel)
            {
                uint32_t div =
                    ((R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                     R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Pos);
                if (BSP_CLOCKS_ETH1_TR_DIV_4 == div)
                {
                    div = 4;
                }
                else if (BSP_CLOCKS_ETH1_TR_DIV_20 == div)
                {
                    div = 20;
                }
                else
                {
                    div = 200;
                }

                g_clock_freq[FSP_PRIV_CLOCK_ETHTX12CLK] = BSP_CFG_CLOCK_PLL6_HZ / div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHTX12CLK] = ETH0_TXC_TX_CLK_IN_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_C_SET_DIV) && defined(BSP_CFG_SEL_ETH1B_SET_SOURCE)
        case FSP_PRIV_CLOCK_ETHRX12CLK:
        {
            uint32_t sel = (R_CPG_CPG_ETH_SSEL_SEL_ETH1B_SET_Msk & R_CPG->CPG_ETH_SSEL) >>
                           R_CPG_CPG_ETH_SSEL_SEL_ETH1B_SET_Pos;

            if (BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH1_TR == sel)
            {
                uint32_t div =
                    ((R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Msk & R_CPG->CPG_ETH_SDIV) >>
                     R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Pos);
                if (BSP_CLOCKS_ETH1_TR_DIV_4 == div)
                {
                    div = 4;
                }
                else if (BSP_CLOCKS_ETH1_TR_DIV_20 == div)
                {
                    div = 20;
                }
                else
                {
                    div = 200;
                }

                g_clock_freq[FSP_PRIV_CLOCK_ETHRX12CLK] = BSP_CFG_CLOCK_PLL6_HZ / div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_ETHRX12CLK] = ETH0_RXC_RX_CLK_IN_HZ;
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_GE3D_SET_SOURCE) && defined(BSP_CFG_DIV_GE3D_SET_DIV)
        case FSP_PRIV_CLOCK_GCLK:
        {
            uint32_t sel = (R_CPG_CPG_GE3D_SSEL_SEL_GE3D_SET_Msk & R_CPG->CPG_GE3D_SSEL) >>
                           R_CPG_CPG_GE3D_SSEL_SEL_GE3D_SET_Pos;
            uint32_t div = ((R_CPG_CPG_GE3D_DDIV_DIV_GE3D_SET_Msk & R_CPG->CPG_GE3D_DDIV) >>
                            R_CPG_CPG_GE3D_DDIV_DIV_GE3D_SET_Pos);

            if (BSP_CLOCKS_GE3D_DIV_32 == div)
            {
                div = div + 1;
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_GE3D_600 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_GCLK] = (BSP_CFG_CLOCK_PLL1_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_GE3D_533 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_GCLK] = (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_3) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_GE3D_500 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_GCLK] = BSP_CFG_CLOCK_PLL6_HZ >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_GCLK] =
                    (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_2) >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_BSC_SET_SOURCE) && defined(BSP_CFG_DIV_BSC_SET_DIV)
        case FSP_PRIV_CLOCK_BCLK:
        {
            uint32_t sel = (R_CPG_CPG_BSC_DSEL_SEL_BSC_SET_Msk & R_CPG->CPG_BSC_DSEL) >>
                           R_CPG_CPG_BSC_DSEL_SEL_BSC_SET_Pos;
            uint32_t div = ((R_CPG_CPG_BSC_DDIV_DIV_BSC_SET_Msk & R_CPG->CPG_BSC_DDIV) >>
                            R_CPG_CPG_BSC_DDIV_DIV_BSC_SET_Pos) + 1;

            if (BSP_CLOCKS_SOURCE_CLOCK_BSC_320 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_BCLK] = (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_BSC_266 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_BCLK] = (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_6) >> div;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_BSC_228 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_BCLK] = (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_7) >> div;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_BCLK] =
                    (BSP_CFG_CLOCK_PLL3_HZ / BSP_PRV_FIXED_DIVISION_RATIO_2 / BSP_PRV_FIXED_DIVISION_RATIO_4) >> div;
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_PDM_SET_DIV)
        case FSP_PRIV_CLOCK_OSCCLK2:
        {
            uint32_t sel = ((R_CPG_CPG_PDM_DDIV_DIV_PDM_SET_Msk & R_CPG->CPG_PDM_DDIV) >>
                            R_CPG_CPG_PDM_DDIV_DIV_PDM_SET_Pos);
            if (BSP_CLOCKS_CLK24_SEL_3 == sel)
            {
                g_clock_freq[FSP_PRIV_CLOCK_OSCCLK2] = BSP_CFG_CLOCK_OSCCLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_3;
            }
            else
            {
                g_clock_freq[FSP_PRIV_CLOCK_OSCCLK2] = BSP_CFG_CLOCK_OSCCLK_HZ / BSP_PRV_FIXED_DIVISION_RATIO_5;
            }

            break;
        }
#endif

        default:
        {
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * Set the Mux Control register to change the frequency.
 *
 * @param[in]   selector              Element number of the array that defines the clock selector.
 * @param[in]   clock_sel             Value to set in Mux Control register.
 **********************************************************************************************************************/
void bsp_prv_clock_selector_set (fsp_priv_clock_selector_t selector, uint32_t clock_sel)
{
    switch (selector)
    {
#if defined(BSP_CFG_SELPL4_SET_SOURCE) || defined(BSP_CFG_SEL_PLL4_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_PLL4:
        {
 #if defined(BSP_CFG_SELPL4_SET_SOURCE)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELPL4_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
            R_CPG->CPG_PLL_DSEL = (uint32_t) (R_CPG_CPG_PLL_DSEL_SELPL4_WEN_Msk |
                                              (R_CPG_CPG_PLL_DSEL_SELPL4_SET_Msk &
                                               (clock_sel << R_CPG_CPG_PLL_DSEL_SELPL4_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELPL4_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
 #endif
 #if defined(BSP_CFG_SEL_PLL4_SET_SOURCE)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_PLL4_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
            R_CPG->CPG_PLL_DSEL = (uint32_t) (R_CPG_CPG_PLL_DSEL_SEL_PLL4_WEN_Msk |
                                              (R_CPG_CPG_PLL_DSEL_SEL_PLL4_SET_Msk &
                                               (clock_sel << R_CPG_CPG_PLL_DSEL_SEL_PLL4_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_PLL4_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_S0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_SDHI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI0:
        {
 #if defined(R_CPG_CPG_CLKSELSTATUS_SELSDHI0_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI0_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
            R_CPG->CPG_SDHI_DSEL = (uint32_t) (R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Msk &
                                                (clock_sel << R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI0_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
 #endif
 #if defined(R_CPG_CPG_CLKSELSTATUS_SEL_SDHI0_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_SDHI0_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
            R_CPG->CPG_SDHI_DSEL = (uint32_t) (R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Msk &
                                                (clock_sel << R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_SDHI0_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SD0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_SDHI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI1:
        {
 #if defined(R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
            R_CPG->CPG_SDHI_DSEL = (uint32_t) (R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Msk &
                                                (clock_sel << R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
 #endif
 #if defined(R_CPG_CPG_CLKSELSTATUS_SEL_SDHI1_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_SDHI1_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
            R_CPG->CPG_SDHI_DSEL = (uint32_t) (R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Msk &
                                                (clock_sel << R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_SDHI1_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SD1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_SDHI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI2:
        {
 #if defined(R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI2_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
            R_CPG->CPG_SDHI_DSEL = (uint32_t) (R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Msk &
                                                (clock_sel << R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELSDHI2_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
 #endif
 #if defined(R_CPG_CPG_CLKSELSTATUS_SEL_SDHI2_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_SDHI2_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
            R_CPG->CPG_SDHI_DSEL = (uint32_t) (R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Msk &
                                                (clock_sel << R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_SDHI2_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SD2CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SELOCTA_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_OCTA:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_OCTA_SSEL = (uint32_t) (R_CPG_CPG_OCTA_SSEL_SELOCTA_WEN_Msk |
                                               (R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Msk &
                                                (clock_sel << R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_OC0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SELSPI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SPI:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SPI_SSEL = (uint32_t) (R_CPG_CPG_SPI_SSEL_SELSPI_WEN_Msk |
                                              (R_CPG_CPG_SPI_SSEL_SELSPI_SET_Msk &
                                               (clock_sel << R_CPG_CPG_SPI_SSEL_SELSPI_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SPI0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL0_SOURCE)

        /* Set the value to bit[0] the CPG_SSEL0 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK1:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL0 = (uint32_t) (R_CPG_CPG_SSEL0_SELCTL0WEN_Msk |
                                           (R_CPG_CPG_SSEL0_SELCTL0_Msk &
                                            (clock_sel << R_CPG_CPG_SSEL0_SELCTL0_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I5CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL1_SOURCE)

        /* Set the value to bit[4] the CPG_SSEL0 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK0:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL0 = (uint32_t) (R_CPG_CPG_SSEL0_SELCTL1WEN_Msk |
                                           (R_CPG_CPG_SSEL0_SELCTL1_Msk &
                                            (clock_sel << R_CPG_CPG_SSEL0_SELCTL1_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I5CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL2_SOURCE)

        /* Set the value to bit[8] the CPG_SSEL0 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_TXCLK:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL0 =
                (uint32_t) (R_CPG_CPG_SSEL0_SELCTL2WEN_Msk |
                            (R_CPG_CPG_SSEL0_SELCTL2_Msk & (clock_sel << R_CPG_CPG_SSEL0_SELCTL2_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL3_SOURCE)

        /* Set the value to bit[12] the CPG_SSEL0 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_RXCLK:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL0 =
                (uint32_t) (R_CPG_CPG_SSEL0_SELCTL3WEN_Msk |
                            (R_CPG_CPG_SSEL0_SELCTL3_Msk & (clock_sel << R_CPG_CPG_SSEL0_SELCTL3_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL0_SOURCE)

        /* Set the value to bit[0] the CPG_SSEL1 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_TXCLK:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL1 = (uint32_t) (R_CPG_CPG_SSEL1_SELCTL0WEN_Msk |
                                           (R_CPG_CPG_SSEL1_SELCTL0_Msk &
                                            (clock_sel << R_CPG_CPG_SSEL1_SELCTL0_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL1_SOURCE)

        /* Set the value to bit[4] the CPG_SSEL1 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_RXCLK:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL1 = (uint32_t) (R_CPG_CPG_SSEL1_SELCTL1WEN_Msk |
                                           (R_CPG_CPG_SSEL1_SELCTL1_Msk &
                                            (clock_sel << R_CPG_CPG_SSEL1_SELCTL1_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL2_SOURCE)

        /* Set the value to bit[8] the CPG_SSEL1 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK0:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL1 = (uint32_t) (R_CPG_CPG_SSEL1_SELCTL2WEN_Msk |
                                           (R_CPG_CPG_SSEL1_SELCTL2_Msk &
                                            (clock_sel << R_CPG_CPG_SSEL1_SELCTL2_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SPI0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL3_SOURCE)

        /* Set the value to bit[12] the CPG_SSEL1 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK1:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL1 = (uint32_t) (R_CPG_CPG_SSEL1_SELCTL3WEN_Msk |
                                           (R_CPG_CPG_SSEL1_SELCTL3_Msk &
                                            (clock_sel << R_CPG_CPG_SSEL1_SELCTL3_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SPI0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL3_SELCTL0_SOURCE)

        /* Set the value to bit[0] the CPG_SSEL3 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI0_CLK:
        {
            uint32_t clock_status[3];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL3 = (uint32_t) (R_CPG_CPG_SSEL3_SELCTL0WEN_Msk |
                                           (R_CPG_CPG_SSEL3_SELCTL0_Msk &
                                            (clock_sel << R_CPG_CPG_SSEL3_SELCTL0_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M4CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SSEL3_SELCTL1_SOURCE)

        /* Set the value to bit[4] the CPG_SSEL3 register. */
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI1_CLK:
        {
            uint32_t clock_status[3];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_SSEL3 = (uint32_t) (R_CPG_CPG_SSEL3_SELCTL1WEN_Msk |
                                           (R_CPG_CPG_SSEL3_SELCTL1_Msk &
                                            (clock_sel << R_CPG_CPG_SSEL3_SELCTL1_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M5CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_BSC_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_BSC:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_BSC_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
            R_CPG->CPG_BSC_DSEL = (uint32_t) (R_CPG_CPG_BSC_DSEL_SEL_BSC_WEN_Msk |
                                              (R_CPG_CPG_BSC_DSEL_SEL_BSC_SET_Msk &
                                               (clock_sel << R_CPG_CPG_BSC_DSEL_SEL_BSC_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SEL_BSC_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_BCLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_XSPI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_XSPI:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_XSPI_SSEL = (uint32_t) (R_CPG_CPG_XSPI_SSEL_SEL_XSPI_WEN_Msk |
                                               (R_CPG_CPG_XSPI_SSEL_SEL_XSPI_SET_Msk &
                                                (clock_sel << R_CPG_CPG_XSPI_SSEL_SEL_XSPI_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SPI0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_DSI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_DSI:
        {
            uint32_t clock_status[3];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_DSI_SSEL = (uint32_t) (R_CPG_CPG_DSI_SSEL_SEL_DSI_WEN_Msk |
                                              (R_CPG_CPG_DSI_SSEL_SEL_DSI_SET_Msk &
                                               (clock_sel << R_CPG_CPG_DSI_SSEL_SEL_DSI_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M3CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_GE3D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_GE3D:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_GE3D_SSEL = (uint32_t) (R_CPG_CPG_GE3D_SSEL_SEL_GE3D_WEN_Msk |
                                               (R_CPG_CPG_GE3D_SSEL_SEL_GE3D_SET_Msk &
                                                (clock_sel << R_CPG_CPG_GE3D_SSEL_SEL_GE3D_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_GCLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0A_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_TX:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH0A_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH0A_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH0A_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX01CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX02CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0B_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RX:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH0B_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH0B_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH0B_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX01CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX02CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0C_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RM:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH0C_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH0C_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH0C_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX01CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX01CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRM0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_TX_I:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH0D_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH0D_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH0D_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX01CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0E_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_RX_I:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH0E_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH0E_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH0E_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX01CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1A_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_TX:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH1A_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH1A_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH1A_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX11CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX12CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1B_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RX:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH1B_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH1B_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH1B_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX11CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX12CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1C_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RM:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH1C_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH1C_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH1C_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX11CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX11CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRM1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_TX_I:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH1D_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH1D_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH1D_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX11CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH1E_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_RX_I:
        {
            uint32_t clock_status[2];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_ETH_SSEL = (uint32_t) (R_CPG_CPG_ETH_SSEL_SEL_ETH1E_WEN_Msk |
                                              (R_CPG_CPG_ETH_SSEL_SEL_ETH1E_SET_Msk &
                                               (clock_sel << R_CPG_CPG_ETH_SSEL_SEL_ETH1E_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX11CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI0:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_RSCI_SSEL = (uint32_t) (R_CPG_CPG_RSCI_SSEL_SEL_RSCI0_WEN_Msk |
                                               (R_CPG_CPG_RSCI_SSEL_SEL_RSCI0_SET_Msk &
                                                (clock_sel << R_CPG_CPG_RSCI_SSEL_SEL_RSCI0_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P13CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI1:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_RSCI_SSEL = (uint32_t) (R_CPG_CPG_RSCI_SSEL_SEL_RSCI1_WEN_Msk |
                                               (R_CPG_CPG_RSCI_SSEL_SEL_RSCI1_SET_Msk &
                                                (clock_sel << R_CPG_CPG_RSCI_SSEL_SEL_RSCI1_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P14CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI2:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_RSCI_SSEL = (uint32_t) (R_CPG_CPG_RSCI_SSEL_SEL_RSCI2_WEN_Msk |
                                               (R_CPG_CPG_RSCI_SSEL_SEL_RSCI2_SET_Msk &
                                                (clock_sel << R_CPG_CPG_RSCI_SSEL_SEL_RSCI2_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P15CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI3_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI3:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_RSCI_SSEL = (uint32_t) (R_CPG_CPG_RSCI_SSEL_SEL_RSCI3_WEN_Msk |
                                               (R_CPG_CPG_RSCI_SSEL_SEL_RSCI3_SET_Msk &
                                                (clock_sel << R_CPG_CPG_RSCI_SSEL_SEL_RSCI3_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P16CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI0:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_RSPI_SSEL = (uint32_t) (R_CPG_CPG_RSPI_SSEL_SEL_RSPI0_WEN_Msk |
                                               (R_CPG_CPG_RSPI_SSEL_SEL_RSPI0_SET_Msk &
                                                (clock_sel << R_CPG_CPG_RSPI_SSEL_SEL_RSPI0_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P17CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI1:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_RSPI_SSEL = (uint32_t) (R_CPG_CPG_RSPI_SSEL_SEL_RSPI1_WEN_Msk |
                                               (R_CPG_CPG_RSPI_SSEL_SEL_RSPI1_SET_Msk &
                                                (clock_sel << R_CPG_CPG_RSPI_SSEL_SEL_RSPI1_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P18CLK);

            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSPI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI2:
        {
            uint32_t clock_status[1];

            bsp_prv_static_mux_control_pre_setting(selector, clock_status);

            R_CPG->CPG_RSPI_SSEL = (uint32_t) (R_CPG_CPG_RSPI_SSEL_SEL_RSPI2_WEN_Msk |
                                               (R_CPG_CPG_RSPI_SSEL_SEL_RSPI2_SET_Msk &
                                                (clock_sel << R_CPG_CPG_RSPI_SSEL_SEL_RSPI2_SET_Pos)));

            bsp_prv_static_mux_control_post_setting(selector, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P19CLK);

            break;
        }
#endif

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_sel);
            bsp_prv_static_mux_control_pre_setting(FSP_PRIV_CLOCK_SELECTOR_NUM, NULL);
            bsp_prv_static_mux_control_post_setting(FSP_PRIV_CLOCK_SELECTOR_NUM, NULL);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_NUM);
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * Set the Gear Control register to change the frequency.
 *
 * @param[in]   divider               Element number of the array that defines the clock divider.
 * @param[in]   clock_div             Value to set in Gear Control register.
 **********************************************************************************************************************/
void bsp_prv_clock_divider_set (fsp_priv_clock_divider_t divider, uint32_t clock_div)
{
    switch (divider)
    {
#if defined(BSP_CFG_DIVPL1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL1:
#endif
#if defined(BSP_CFG_DIV_PLL1_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55:
#endif
#if defined(BSP_CFG_DIVPL1_SET_DIV) || defined(BSP_CFG_DIV_PLL1_A_SET_DIV)
        {
 #if defined(BSP_CFG_DIVPL1_SET_DIV)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL1_DDIV = (uint32_t) (R_CPG_CPG_PL1_DDIV_DIV_PLL1SET_WEN_Msk |
                                              (R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif
 #if defined(BSP_CFG_DIV_PLL1_A_SET_DIV)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL1_DDIV = (uint32_t) (R_CPG_CPG_PL1_DDIV_DIV_PLL1_A_WEN_Msk |
                                              (R_CPG_CPG_PL1_DDIV_DIV_PLL1_A_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL1_DDIV_DIV_PLL1_A_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ICLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL2B_SET_DIV) || defined(BSP_CFG_DIV_PLL2_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_100:
        {
 #if defined(BSP_CFG_DIVPL2B_SET_DIV)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL2B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL2_DDIV = (uint32_t) (R_CPG_CPG_PL2_DDIV_DIV_PLL2_B_WEN_Msk |
                                              (R_CPG_CPG_PL2_DDIV_DIVPL2B_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL2_DDIV_DIVPL2B_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL2B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif
 #if defined(BSP_CFG_DIV_PLL2_B_SET_DIV)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL2B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL2_DDIV = (uint32_t) (R_CPG_CPG_PL2_DDIV_DIV_PLL2_B_WEN_Msk |
                                              (R_CPG_CPG_PL2_DDIV_DIV_PLL2_B_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL2_DDIV_DIV_PLL2_B_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL2B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL3A_SET_DIV) || defined(BSP_CFG_DIV_PLL3_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_200:
        {
 #if defined(BSP_CFG_DIVPL3A_SET_DIV)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3A_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL3_DDIV = (uint32_t) (R_CPG_CPG_PL3_DDIV_DIV_PLL3_A_WEN_Msk |
                                              (R_CPG_CPG_PL3_DDIV_DIVPL3A_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL3_DDIV_DIVPL3A_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3A_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif
 #if defined(BSP_CFG_DIV_PLL3_A_SET_DIV)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3A_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL3_DDIV = (uint32_t) (R_CPG_CPG_PL3_DDIV_DIV_PLL3_A_WEN_Msk |
                                              (R_CPG_CPG_PL3_DDIV_DIV_PLL3_A_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL3_DDIV_DIV_PLL3_A_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3A_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P1CLK);
 #if defined(BSP_CFG_CLOCK_M6CLK_HZ)

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M6CLK);
 #endif

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL3B_SET_DIV) || defined(BSP_CFG_DIV_PLL3_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_100:
        {
 #if defined(BSP_CFG_DIVPL3B_SET_DIV)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL3_DDIV = (uint32_t) (R_CPG_CPG_PL3_DDIV_DIV_PLL3_B_WEN_Msk |
                                              (R_CPG_CPG_PL3_DDIV_DIVPL3B_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL3_DDIV_DIVPL3B_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif
 #if defined(BSP_CFG_DIV_PLL3_B_SET_DIV)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL3_DDIV = (uint32_t) (R_CPG_CPG_PL3_DDIV_DIV_PLL3_B_WEN_Msk |
                                              (R_CPG_CPG_PL3_DDIV_DIV_PLL3_B_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL3_DDIV_DIV_PLL3_B_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P2CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL3C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_200MCPU:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3C_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL3_DDIV = (uint32_t) (R_CPG_CPG_PL3_DDIV_DIV_PLL3_C_WEN_Msk |
                                              (R_CPG_CPG_PL3_DDIV_DIVPL3C_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL3_DDIV_DIVPL3C_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL3C_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P3CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL6A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIVPL6A:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL6A_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL6_DDIV = (uint32_t) (R_CPG_CPG_PL6_DDIV_DIV_PLL6_A_WEN_Msk |
                                              (R_CPG_CPG_PL6_DDIV_DIVPL6A_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL6_DDIV_DIVPL6A_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL6A_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I2CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVPL6B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIVPL6B:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL6B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL6_DDIV = (uint32_t) (R_CPG_CPG_PL6_DDIV_DIV_PLL6_B_WEN_Msk |
                                              (R_CPG_CPG_PL6_DDIV_DIVPL6B_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL6_DDIV_DIVPL6B_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL6B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I3CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVSDHI0_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI0_SEL:
        {
 #if defined(R_CPG_CPG_CLKDIVSTATUS_DIVSDHI0_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSDHI0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_SDHI_DDIV = (uint32_t) (R_CPG_CPG_SDHI_DDIV_DIVSDHI0_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DDIV_DIVSDHI0_SET_Msk &
                                                (clock_div << R_CPG_CPG_SDHI_DDIV_DIVSDHI0_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSDHI0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif
 #if defined(R_CPG_CPG_CLKDIVSTATUS_DIV_SDHI0_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_SDHI0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_SDHI_DDIV = (uint32_t) (R_CPG_CPG_SDHI_DDIV_DIVSDHI0_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DDIV_DIVSDHI0_SET_Msk &
                                                (clock_div << R_CPG_CPG_SDHI_DDIV_DIVSDHI0_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_SDHI0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SD0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVSDHI1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI1_SEL:
        {
 #if defined(R_CPG_CPG_CLKDIVSTATUS_DIVSDHI1_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSDHI1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_SDHI_DDIV = (uint32_t) (R_CPG_CPG_SDHI_DDIV_DIVSDHI1_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DDIV_DIVSDHI1_SET_Msk &
                                                (clock_div << R_CPG_CPG_SDHI_DDIV_DIVSDHI1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSDHI1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif
 #if defined(R_CPG_CPG_CLKDIVSTATUS_DIV_SDHI1_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_SDHI1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_SDHI_DDIV = (uint32_t) (R_CPG_CPG_SDHI_DDIV_DIVSDHI1_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DDIV_DIVSDHI1_SET_Msk &
                                                (clock_div << R_CPG_CPG_SDHI_DDIV_DIVSDHI1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_SDHI1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SD1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVSDHI2_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI2_SEL:
        {
 #if defined(R_CPG_CPG_CLKDIVSTATUS_DIVSDHI2_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSDHI2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_SDHI_DDIV = (uint32_t) (R_CPG_CPG_SDHI_DDIV_DIVSDHI2_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DDIV_DIVSDHI2_SET_Msk &
                                                (clock_div << R_CPG_CPG_SDHI_DDIV_DIVSDHI2_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSDHI2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif
 #if defined(R_CPG_CPG_CLKDIVSTATUS_DIV_SDHI2_STS_Msk)
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_SDHI2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_SDHI_DDIV = (uint32_t) (R_CPG_CPG_SDHI_DDIV_DIVSDHI2_WEN_Msk |
                                               (R_CPG_CPG_SDHI_DDIV_DIVSDHI2_SET_Msk &
                                                (clock_div << R_CPG_CPG_SDHI_DDIV_DIVSDHI2_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_SDHI2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
 #endif

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SD2CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVOCTA_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_OCTA:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_OCTA_DDIV = (uint32_t) (R_CPG_CPG_OCTA_DDIV_DIVOCTA_WEN_Msk |
                                               (R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Msk &
                                                (clock_div << R_CPG_CPG_OCTA_DDIV_DIVOCTA_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVOCTA_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_OC0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIVSPI_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_SPI:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_SPI_DDIV = (uint32_t) (R_CPG_CPG_SPI_DDIV_DIVSPI_WEN_Msk |
                                              (R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Msk &
                                               (clock_div << R_CPG_CPG_SPI_DDIV_DIVSPI_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SPI0CLK);

            break;
        }
#endif

        /********* Settings to CPG_CDDIVm ********/
#if defined(BSP_CFG_CDDIV0_DIVCTL0_DIV)

        /* Set the value to bit[2:0] the CPG_CDDIV0 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_CST400:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV0CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV0 = (uint32_t) (R_CPG_CPG_CDDIV0_DIVCTL0WEN_Msk |
                                            (R_CPG_CPG_CDDIV0_DIVCTL0_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV0_DIVCTL0_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV0CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ATCLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV0_DIVCTL1_DIV)

        /* Set the value to bit[6:4] the CPG_CDDIV0 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV0CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV0 = (uint32_t) (R_CPG_CPG_CDDIV0_DIVCTL1WEN_Msk |
                                            (R_CPG_CPG_CDDIV0_DIVCTL1_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV0_DIVCTL1_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV0CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I7CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV0_DIVCTL2_DIV)

        /* Set the value to bit[10:8] the CPG_CDDIV0 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_ACPU:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV0CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV0 = (uint32_t) (R_CPG_CPG_CDDIV0_DIVCTL2WEN_Msk |
                                            (R_CPG_CPG_CDDIV0_DIVCTL2_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV0_DIVCTL2_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV0CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P7CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV0_DIVCTL3_DIV)

        /* Set the value to bit[14:12] the CPG_CDDIV0 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLCA55_SCLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV0CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV0 = (uint32_t) (R_CPG_CPG_CDDIV0_DIVCTL3WEN_Msk |
                                            (R_CPG_CPG_CDDIV0_DIVCTL3_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV0_DIVCTL3_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV0CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I5CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV1_DIVCTL0_DIV)

        /* Set the value to bit[2:0] the CPG_CDDIV1 register. */
        case FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_0:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV1CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV1 = (uint32_t) (R_CPG_CPG_CDDIV1_DIVCTL0WEN_Msk |
                                            (R_CPG_CPG_CDDIV1_DIVCTL0_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV1_DIVCTL0_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV1CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV1_DIVCTL1_DIV)

        /* Set the value to bit[6:4] the CPG_CDDIV1 register. */
        case FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_1:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV1CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV1 = (uint32_t) (R_CPG_CPG_CDDIV1_DIVCTL1WEN_Msk |
                                            (R_CPG_CPG_CDDIV1_DIVCTL1_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV1_DIVCTL1_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV1CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV1_DIVCTL2_DIV)

        /* Set the value to bit[10:8] the CPG_CDDIV1 register. */
        case FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_2:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV1CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV1 = (uint32_t) (R_CPG_CPG_CDDIV1_DIVCTL2WEN_Msk |
                                            (R_CPG_CPG_CDDIV1_DIVCTL2_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV1_DIVCTL2_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV1CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I2CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV1_DIVCTL3_DIV)

        /* Set the value to bit[14:12] the CPG_CDDIV1 register. */
        case FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_3:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV1CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV1 = (uint32_t) (R_CPG_CPG_CDDIV1_DIVCTL3WEN_Msk |
                                            (R_CPG_CPG_CDDIV1_DIVCTL3_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV1_DIVCTL3_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV1CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I3CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV2_DIVCTL0_DIV)

        /* Set the value to bit[2:0] the CPG_CDDIV2 register. */
        case FSP_PRIV_CLOCK_DIVIDER_CA55PERI:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV2CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV2 = (uint32_t) (R_CPG_CPG_CDDIV2_DIVCTL0WEN_Msk |
                                            (R_CPG_CPG_CDDIV2_DIVCTL0_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV2_DIVCTL0_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV2CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I4CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL1_DIV)

        /* Set the value to bit[6:4] the CPG_CDDIV3 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_GPU:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV3CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV3 = (uint32_t) (R_CPG_CPG_CDDIV3_DIVCTL1WEN_Msk |
                                            (R_CPG_CPG_CDDIV3_DIVCTL1_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV3_DIVCTL1_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV3CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_GPUCLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL2_DIV)

        /* Set the value to bit[10:8] the CPG_CDDIV3 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_RCPU:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV3CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV3 = (uint32_t) (R_CPG_CPG_CDDIV3_DIVCTL2WEN_Msk |
                                            (R_CPG_CPG_CDDIV3_DIVCTL2_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV3_DIVCTL2_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV3CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P11CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL3_DIV)

        /* Set the value to bit[14:12] the CPG_CDDIV3 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU0:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV3CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV3 = (uint32_t) (R_CPG_CPG_CDDIV3_DIVCTL3WEN_Msk |
                                            (R_CPG_CPG_CDDIV3_DIVCTL3_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV3_DIVCTL3_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV3CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV4_DIVCTL3_DIV)

        /* Set the value to bit[14:12] the CPG_CDDIV4 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_NPU:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV4CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV4 = (uint32_t) (R_CPG_CPG_CDDIV4_DIVCTL3WEN_Msk |
                                            (R_CPG_CPG_CDDIV4_DIVCTL3_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV4_DIVCTL3_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV4CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_NPUCLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV5_DIVCTL0_DIV)

        /* Set the value to bit[3:0] the CPG_CDDIV5 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_NPU:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV5CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV5 = (uint32_t) (R_CPG_CPG_CDDIV5_DIVCTL0WEN_Msk |
                                            (R_CPG_CPG_CDDIV5_DIVCTL0_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV5_DIVCTL0_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV5CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P12CLK);

            break;
        }
#endif

        /********* Settings to CPG_CSDIVm ********/
#if defined(BSP_CFG_CSDIV0_DIVCTL0_DIV)

        /* Set the value to bit[1:0] the CPG_CSDIV0 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE0:
        {
            uint32_t clock_status[4];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_CSDIV0 =
                (uint32_t) (R_CPG_CPG_CSDIV0_DIVCTL0WEN_Msk |
                            (R_CPG_CPG_CSDIV0_DIVCTL0_Msk & (clock_div << R_CPG_CPG_CSDIV0_DIVCTL0_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX0CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL1_DIV)

        /* Set the value to bit[5:4] the CPG_CSDIV0 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE1:
        {
            uint32_t clock_status[4];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_CSDIV0 =
                (uint32_t) (R_CPG_CPG_CSDIV0_DIVCTL1WEN_Msk |
                            (R_CPG_CPG_CSDIV0_DIVCTL1_Msk & (clock_div << R_CPG_CPG_CSDIV0_DIVCTL1_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX1CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL2_DIV)

        /* Set the value to bit[11:8] the CPG_CSDIV0 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_LPCLK:
        {
            uint32_t clock_status[1];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_CSDIV0 = (uint32_t) (R_CPG_CPG_CSDIV0_DIVCTL2WEN_Msk |
                                            (R_CPG_CPG_CSDIV0_DIVCTL2_Msk &
                                             (clock_div << R_CPG_CPG_CSDIV0_DIVCTL2_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_LPCLK);

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV0_DIVCTL3_DIV)

        /* Set the value to bit[13:12] the CPG_CSDIV0 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_XSPI:
        {
            uint32_t clock_status[1];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_CSDIV0 = (uint32_t) (R_CPG_CPG_CSDIV0_DIVCTL3WEN_Msk |
                                            (R_CPG_CPG_CSDIV0_DIVCTL3_Msk &
                                             (clock_div << R_CPG_CPG_CSDIV0_DIVCTL3_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SPI0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL0_DIV)

        /* Set the value to bit[1:0] the CPG_CSDIV1 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_PCLK:
        {
            uint32_t clock_status[2];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_CSDIV1 = (uint32_t) (R_CPG_CPG_CSDIV1_DIVCTL0WEN_Msk |
                                            (R_CPG_CPG_CSDIV1_DIVCTL0_Msk &
                                             (clock_div << R_CPG_CPG_CSDIV1_DIVCTL0_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ADCCLK);

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL1_DIV)

        /* Set the value to bit[5:4] the CPG_CSDIV1 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_ADCLK:
        {
            uint32_t clock_status[2];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_CSDIV1 = (uint32_t) (R_CPG_CPG_CSDIV1_DIVCTL1WEN_Msk |
                                            (R_CPG_CPG_CSDIV1_DIVCTL1_Msk &
                                             (clock_div << R_CPG_CPG_CSDIV1_DIVCTL1_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ADCCLK);

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL2_DIV)

        /* Set the value to bit[11:8] the CPG_CSDIV1 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI0:
        {
            uint32_t clock_status[3];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_CSDIV1 = (uint32_t) (R_CPG_CPG_CSDIV1_DIVCTL2WEN_Msk |
                                            (R_CPG_CPG_CSDIV1_DIVCTL2_Msk &
                                             (clock_div << R_CPG_CPG_CSDIV1_DIVCTL2_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M4CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL3_DIV)

        /* Set the value to bit[15:12] the CPG_CSDIV1 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI1:
        {
            uint32_t clock_status[3];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_CSDIV1 = (uint32_t) (R_CPG_CPG_CSDIV1_DIVCTL3WEN_Msk |
                                            (R_CPG_CPG_CSDIV1_DIVCTL3_Msk &
                                             (clock_div << R_CPG_CPG_CSDIV1_DIVCTL3_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M4CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_PLL2_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_200:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL2A_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL2_DDIV = (uint32_t) (R_CPG_CPG_PL2_DDIV_DIV_PLL2_A_WEN_Msk |
                                              (R_CPG_CPG_PL2_DDIV_DIV_PLL2_A_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL2_DDIV_DIV_PLL2_A_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL2A_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P3CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_CLKQSPI_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_QSPI:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CLKQSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PL2_DDIV = (uint32_t) (R_CPG_CPG_PL2_DDIV_DIV_CLKQSPI_WEN_Msk |
                                              (R_CPG_CPG_PL2_DDIV_DIV_CLKQSPI_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL2_DDIV_DIV_CLKQSPI_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CLKQSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P7CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_XSPI_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_XSPI:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_XSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_XSPI_DDIV = (uint32_t) (R_CPG_CPG_XSPI_DDIV_DIV_XSPI_WEN_Msk |
                                               (R_CPG_CPG_XSPI_DDIV_DIV_XSPI_SET_Msk &
                                                (clock_div << R_CPG_CPG_XSPI_DDIV_DIV_XSPI_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_XSPI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_SPI0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_GE3D_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_GE3D:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_GE3D_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_GE3D_DDIV = (uint32_t) (R_CPG_CPG_GE3D_DDIV_DIV_GE3D_WEN_Msk |
                                               (R_CPG_CPG_GE3D_DDIV_DIV_GE3D_SET_Msk &
                                                (clock_div << R_CPG_CPG_GE3D_DDIV_DIV_GE3D_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_GE3D_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_GCLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CLK266FIXC_DIV16TO128:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_DSI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_DSI_DDIV = (uint32_t) (R_CPG_CPG_DSI_DDIV_DIV_DSI_WEN_Msk |
                                              (R_CPG_CPG_DSI_DDIV_DIV_DSI_SET_Msk &
                                               (clock_div << R_CPG_CPG_DSI_DDIV_DIV_DSI_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_DSI_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_PDM_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CLK24_SEL:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_PDM_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_PDM_DDIV = (uint32_t) (R_CPG_CPG_PDM_DDIV_DIV_PDM_WEN_Msk |
                                              (R_CPG_CPG_PDM_DDIV_DIV_PDM_SET_Msk &
                                               (clock_div << R_CPG_CPG_PDM_DDIV_DIV_PDM_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_PDM_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_OSCCLK2);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_BSC_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_BSC:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_BSC_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_BSC_DDIV = (uint32_t) (R_CPG_CPG_BSC_DDIV_DIV_BSC_WEN_Msk |
                                              (R_CPG_CPG_BSC_DDIV_DIV_BSC_SET_Msk &
                                               (clock_div << R_CPG_CPG_BSC_DDIV_DIV_BSC_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_BSC_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_BCLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_CORE0_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE0:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CA55CORE0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_CA55CORE_DDIV = (uint32_t) (R_CPG_CPG_CA55CORE_DDIV_DIV_CORE0_WEN_Msk |
                                                   (R_CPG_CPG_CA55CORE_DDIV_DIV_CORE0_SET_Msk &
                                                    (clock_div << R_CPG_CPG_CA55CORE_DDIV_DIV_CORE0_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CA55CORE0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_IC0CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_CORE1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE1:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CA55CORE1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_CA55CORE_DDIV = (uint32_t) (R_CPG_CPG_CA55CORE_DDIV_DIV_CORE1_WEN_Msk |
                                                   (R_CPG_CPG_CA55CORE_DDIV_DIV_CORE1_SET_Msk &
                                                    (clock_div << R_CPG_CPG_CA55CORE_DDIV_DIV_CORE1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CA55CORE1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_IC1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_CORE2_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE2:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CA55CORE2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_CA55CORE_DDIV = (uint32_t) (R_CPG_CPG_CA55CORE_DDIV_DIV_CORE2_WEN_Msk |
                                                   (R_CPG_CPG_CA55CORE_DDIV_DIV_CORE2_SET_Msk &
                                                    (clock_div << R_CPG_CPG_CA55CORE_DDIV_DIV_CORE2_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CA55CORE2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_IC2CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_CORE3_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE3:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CA55CORE3_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_CA55CORE_DDIV = (uint32_t) (R_CPG_CPG_CA55CORE_DDIV_DIV_CORE3_WEN_Msk |
                                                   (R_CPG_CPG_CA55CORE_DDIV_DIV_CORE3_SET_Msk &
                                                    (clock_div << R_CPG_CPG_CA55CORE_DDIV_DIV_CORE3_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_CA55CORE3_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_IC3CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_RSCI0_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI0:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSCI0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_RSCI_DDIV = (uint32_t) (R_CPG_CPG_RSCI_DDIV_DIV_RSCI0_WEN_Msk |
                                               (R_CPG_CPG_RSCI_DDIV_DIV_RSCI0_SET_Msk &
                                                (clock_div << R_CPG_CPG_RSCI_DDIV_DIV_RSCI0_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSCI0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P13CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_RSCI1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI1:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSCI1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_RSCI_DDIV = (uint32_t) (R_CPG_CPG_RSCI_DDIV_DIV_RSCI1_WEN_Msk |
                                               (R_CPG_CPG_RSCI_DDIV_DIV_RSCI1_SET_Msk &
                                                (clock_div << R_CPG_CPG_RSCI_DDIV_DIV_RSCI1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSCI1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P14CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_RSCI2_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI2:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSCI2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_RSCI_DDIV = (uint32_t) (R_CPG_CPG_RSCI_DDIV_DIV_RSCI2_WEN_Msk |
                                               (R_CPG_CPG_RSCI_DDIV_DIV_RSCI2_SET_Msk &
                                                (clock_div << R_CPG_CPG_RSCI_DDIV_DIV_RSCI2_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSCI2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P15CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_RSCI3_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI3:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSCI3_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_RSCI_DDIV = (uint32_t) (R_CPG_CPG_RSCI_DDIV_DIV_RSCI3_WEN_Msk |
                                               (R_CPG_CPG_RSCI_DDIV_DIV_RSCI3_SET_Msk &
                                                (clock_div << R_CPG_CPG_RSCI_DDIV_DIV_RSCI3_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSCI3_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P16CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_RSPI0_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI0:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSPI0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_RSPI_DDIV = (uint32_t) (R_CPG_CPG_RSPI_DDIV_DIV_RSPI0_WEN_Msk |
                                               (R_CPG_CPG_RSPI_DDIV_DIV_RSPI0_SET_Msk &
                                                (clock_div << R_CPG_CPG_RSPI_DDIV_DIV_RSPI0_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSPI0_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P17CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_RSPI1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI1:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSPI1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_RSPI_DDIV = (uint32_t) (R_CPG_CPG_RSPI_DDIV_DIV_RSPI1_WEN_Msk |
                                               (R_CPG_CPG_RSPI_DDIV_DIV_RSPI1_SET_Msk &
                                                (clock_div << R_CPG_CPG_RSPI_DDIV_DIV_RSPI1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSPI1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P18CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_RSPI2_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI2:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSPI2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
            R_CPG->CPG_RSPI_DDIV = (uint32_t) (R_CPG_CPG_RSPI_DDIV_DIV_RSPI2_WEN_Msk |
                                               (R_CPG_CPG_RSPI_DDIV_DIV_RSPI2_SET_Msk &
                                                (clock_div << R_CPG_CPG_RSPI_DDIV_DIV_RSPI2_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIV_RSPI2_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P19CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO32_VCLK:
        {
            uint32_t clock_status[3];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_DSI_SDIV = (uint32_t) (R_CPG_CPG_DSI_SDIV_DIV_DSI_A_WEN_Msk |
                                              (R_CPG_CPG_DSI_SDIV_DIV_DSI_A_SET_Msk &
                                               (clock_div << R_CPG_CPG_DSI_SDIV_DIV_DSI_A_SET_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M3CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO16_VCLK:
        {
            uint32_t clock_status[3];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_DSI_SDIV = (uint32_t) (R_CPG_CPG_DSI_SDIV_DIV_DSI_B_WEN_Msk |
                                              (R_CPG_CPG_DSI_SDIV_DIV_DSI_B_SET_Msk &
                                               (clock_div << R_CPG_CPG_DSI_SDIV_DIV_DSI_B_SET_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M3CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO2_LVDS:
        {
            uint32_t clock_status[4];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_DSI_SDIV = (uint32_t) (R_CPG_CPG_DSI_SDIV_DIV_DSI_C_WEN_Msk |
                                              (R_CPG_CPG_DSI_SDIV_DIV_DSI_C_SET_Msk &
                                               (clock_div << R_CPG_CPG_DSI_SDIV_DIV_DSI_C_SET_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M2CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M3CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_TR:
        {
            uint32_t clock_status[2];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_ETH_SDIV = (uint32_t) (R_CPG_CPG_ETH_SDIV_DIV_ETH_A_WEN_Msk |
                                              (R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Msk &
                                               (clock_div << R_CPG_CPG_ETH_SDIV_DIV_ETH_A_SET_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX01CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX01CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX02CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX02CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_RM:
        {
            uint32_t clock_status[1];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_ETH_SDIV = (uint32_t) (R_CPG_CPG_ETH_SDIV_DIV_ETH_B_WEN_Msk |
                                              (R_CPG_CPG_ETH_SDIV_DIV_ETH_B_SET_Msk &
                                               (clock_div << R_CPG_CPG_ETH_SDIV_DIV_ETH_B_SET_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX01CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX01CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_TR:
        {
            uint32_t clock_status[2];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_ETH_SDIV = (uint32_t) (R_CPG_CPG_ETH_SDIV_DIV_ETH_C_WEN_Msk |
                                              (R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Msk &
                                               (clock_div << R_CPG_CPG_ETH_SDIV_DIV_ETH_C_SET_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX11CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX11CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX12CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX12CLK);

            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_D_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_RM:
        {
            uint32_t clock_status[1];

            bsp_prv_static_gear_control_pre_setting(divider, clock_status);

            R_CPG->CPG_ETH_SDIV = (uint32_t) (R_CPG_CPG_ETH_SDIV_DIV_ETH_D_WEN_Msk |
                                              (R_CPG_CPG_ETH_SDIV_DIV_ETH_D_SET_Msk &
                                               (clock_div << R_CPG_CPG_ETH_SDIV_DIV_ETH_D_SET_Pos)));

            bsp_prv_static_gear_control_post_setting(divider, clock_status);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHTX11CLK);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ETHRX11CLK);

            break;
        }
#endif

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_div);
            bsp_prv_static_gear_control_pre_setting(FSP_PRIV_CLOCK_DIVIDER_NUM, NULL);
            bsp_prv_static_gear_control_post_setting(FSP_PRIV_CLOCK_DIVIDER_NUM, NULL);
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_NUM);
            break;
        }
    }
}

/** @} (end addtogroup BSP_MCU_PRV) */

/*******************************************************************************************************************//**
 * @addtogroup RZG_BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Get the system clock frequency.
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of the bus clock.
 *
 * @retval      g_clock_freq[clock]   System clock frequency.
 **********************************************************************************************************************/
uint32_t R_FSP_SystemClockHzGet (fsp_priv_clock_t clock)
{
    return g_clock_freq[clock];
}

#if defined(BSP_FEATURE_BSP_SYSTEM_CLOCK_HZ_SET_SUPPORT)

/*******************************************************************************************************************//**
 * DEPRECATED Set a clock frequency.
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of each clock.
 * @param[in]   clock_sel             Value to set in Source Clock Setting register.
 * @param[in]   clock_div             Value to set in Division Ratio Setting register.
 **********************************************************************************************************************/
void R_FSP_SystemClockHzSet (fsp_priv_clock_t clock, uint32_t clock_sel, uint32_t clock_div)
{
    bsp_prv_clock_pre_setting(clock);
    bsp_prv_system_clock_hz_sel_set(clock, clock_sel);
    bsp_prv_system_clock_hz_div_set(clock, clock_div);
    bsp_prv_clock_post_setting(clock);
}

#endif

/*******************************************************************************************************************//**
 * Set a clock selector.
 *
 * @param[in]   selector              Element number of the array that defines the clock selector.
 * @param[in]   clock_sel             Value to set in Mux Control register.
 *
 * @retval FSP_SUCCESS                Selector configuration changes completed.
 * @retval FSP_ERR_INVALID_ARGUMENT   Undefined selector specified.
 * @retval FSP_ERR_PLL_SRC_INACTIVE   Clock source PLL is reset state.
 *
 * @note This function assumes that a source clock is supplied.
 * If the source clock is not supplied, the selector setting process cannot be completed successfully.
 **********************************************************************************************************************/
fsp_err_t R_BSP_ClockSelectorSet (fsp_priv_clock_selector_t selector, uint32_t clock_sel)
{
    switch (selector)
    {
#if defined(BSP_CFG_SELPL4_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_PLL4:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL4 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL4_MON_PLL4_LOCK_Msk | R_CPG_CPG_PLL4_MON_PLL4_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL4_MON_PLL4_LOCK_Msk | R_CPG_CPG_PLL4_MON_PLL4_RESETB_Msk) &
                                  R_CPG->CPG_PLL4_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                /* Do nothing. */
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_SDHI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI0:
#endif
#if defined(BSP_CFG_SEL_SDHI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI1:
#endif
#if defined(BSP_CFG_SEL_SDHI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI2:
#endif
#if defined(BSP_CFG_SEL_SDHI0_SET_SOURCE) || defined(BSP_CFG_SEL_SDHI1_SET_SOURCE) || \
        defined(BSP_CFG_SEL_SDHI2_SET_SOURCE)
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL1_600 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                  R_CPG->CPG_PLL1_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                                  R_CPG->CPG_PLL2_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SELOCTA_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_OCTA:
#endif
#if defined(BSP_CFG_SELSPI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_SPI:
#endif
#if defined(BSP_CFG_SELOCTA_SET_SOURCE) || defined(BSP_CFG_SELSPI_SET_SOURCE)
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) &
                                  R_CPG->CPG_PLL3_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK1:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL0_PLLCA55 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk) &
                                  R_CPG->CPG_PLLCA55_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLVDO ==
                    ((R_CPG_CPG_SSEL0_SELCTL1_Msk & R_CPG->CPG_SSEL0) >> R_CPG_CPG_SSEL0_SELCTL1_Pos))
                {
                    FSP_ERROR_RETURN((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) ==
                                     ((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) &
                                      R_CPG->CPG_PLLVDO_MON),
                                     FSP_ERR_PLL_SRC_INACTIVE);
                }
                else
                {
                    FSP_ERROR_RETURN((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) ==
                                     ((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) &
                                      R_CPG->CPG_PLLDTY_MON),
                                     FSP_ERR_PLL_SRC_INACTIVE);
                }
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK0:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLVDO == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) &
                                  R_CPG->CPG_PLLVDO_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) &
                                  R_CPG->CPG_PLLDTY_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL2_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_TXCLK:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL2_CSDIV_PLLETH_GBE0 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) &
                                  R_CPG->CPG_PLLETH_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL0_SELCTL3_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_RXCLK:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL3_CSDIV_PLLETH_GBE0 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) &
                                  R_CPG->CPG_PLLETH_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_TXCLK:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL0_CSDIV_PLLETH_GBE1 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) &
                                  R_CPG->CPG_PLLETH_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_RXCLK:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL1_CSDIV_PLLETH_GBE1 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) &
                                  R_CPG->CPG_PLLETH_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SSEL1_SELCTL2_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK0:
#endif
#if defined(BSP_CFG_SSEL1_SELCTL3_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK1:
#endif
#if defined(BSP_CFG_SSEL1_SELCTL2_SOURCE) || defined(BSP_CFG_SSEL1_SELCTL3_SOURCE)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLCM33_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCM33_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLCM33_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCM33_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLCM33_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_SSEL3_SELCTL0_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI0_CLK:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLDSI0_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI0_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLDSI0_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI0_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLDSI0_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_SSEL3_SELCTL1_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SMUX2_DSI1_CLK:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLDSI1_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI1_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLDSI1_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI1_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLDSI1_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_SEL_BSC_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_BSC:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) &
                              R_CPG->CPG_PLL3_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_SEL_XSPI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_XSPI:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_XSPI_600 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                  R_CPG->CPG_PLL1_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_XSPI_500 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                                  R_CPG->CPG_PLL2_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_DSI_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_DSI:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL7_MON_PLL7_LOCK_Msk | R_CPG_CPG_PLL7_MON_PLL7_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL7_MON_PLL7_LOCK_Msk | R_CPG_CPG_PLL7_MON_PLL7_RESETB_Msk) &
                              R_CPG->CPG_PLL7_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_SEL_GE3D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_GE3D:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_GE3D_600 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                  R_CPG->CPG_PLL1_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_GE3D_500 == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) &
                                  R_CPG->CPG_PLL3_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_SEL_ETH0A_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_TX:
#endif
#if defined(BSP_CFG_SEL_ETH0B_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RX:
#endif
#if defined(BSP_CFG_SEL_ETH0C_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RM:
#endif
#if defined(BSP_CFG_SEL_ETH0D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_TX_I:
#endif
#if defined(BSP_CFG_SEL_ETH0E_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_RX_I:
#endif
#if defined(BSP_CFG_SEL_ETH1A_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_TX:
#endif
#if defined(BSP_CFG_SEL_ETH1B_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RX:
#endif
#if defined(BSP_CFG_SEL_ETH1C_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RM:
#endif
#if defined(BSP_CFG_SEL_ETH1D_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_TX_I:
#endif
#if defined(BSP_CFG_SEL_ETH1E_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_RX_I:
#endif
#if defined(BSP_CFG_SEL_ETH0A_SET_SOURCE) || defined(BSP_CFG_SEL_ETH0B_SET_SOURCE) ||     \
        defined(BSP_CFG_SEL_ETH0C_SET_SOURCE) || defined(BSP_CFG_SEL_ETH0D_SET_SOURCE) || \
        defined(BSP_CFG_SEL_ETH0E_SET_SOURCE) || defined(BSP_CFG_SEL_ETH1A_SET_SOURCE) || \
        defined(BSP_CFG_SEL_ETH1B_SET_SOURCE) || defined(BSP_CFG_SEL_ETH1C_SET_SOURCE) || \
        defined(BSP_CFG_SEL_ETH1D_SET_SOURCE) || defined(BSP_CFG_SEL_ETH1E_SET_SOURCE)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                              R_CPG->CPG_PLL6_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_SEL_RSCI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI0:
#endif
#if defined(BSP_CFG_SEL_RSCI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI1:
#endif
#if defined(BSP_CFG_SEL_RSCI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI2:
#endif
#if defined(BSP_CFG_SEL_RSCI3_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI3:
#endif
#if defined(BSP_CFG_SEL_RSPI0_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI0:
#endif
#if defined(BSP_CFG_SEL_RSPI1_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI1:
#endif
#if defined(BSP_CFG_SEL_RSPI2_SET_SOURCE)
        case FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI2:
#endif
#if defined(BSP_CFG_SEL_RSCI0_SET_SOURCE) || defined(BSP_CFG_SEL_RSCI1_SET_SOURCE) ||     \
        defined(BSP_CFG_SEL_RSCI2_SET_SOURCE) || defined(BSP_CFG_SEL_RSCI3_SET_SOURCE) || \
        defined(BSP_CFG_SEL_RSPI0_SET_SOURCE) || defined(BSP_CFG_SEL_RSPI1_SET_SOURCE) || \
        defined(BSP_CFG_SEL_RSPI2_SET_SOURCE)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                              R_CPG->CPG_PLL2_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

        default:
        {
            FSP_ERROR_RETURN(FSP_PRIV_CLOCK_SELECTOR_NUM > selector, FSP_ERR_INVALID_ARGUMENT);
            break;
        }
    }

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    bsp_prv_clock_selector_set(selector, clock_sel);

    FSP_CRITICAL_SECTION_EXIT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set a clock division ratio.
 *
 * @param[in]   divider               Element number of the array that defines the clock divider.
 * @param[in]   clock_div             Value to set in Gear Control register.
 *
 * @retval FSP_SUCCESS                Divider configuration changes completed.
 * @retval FSP_ERR_INVALID_ARGUMENT   Undefined divider specified.
 * @retval FSP_ERR_PLL_SRC_INACTIVE   Clock source PLL is reset state.
 *
 * @note This function assumes that a source clock is supplied.
 * If the source clock is not supplied, the divider setting process cannot be completed successfully.
 **********************************************************************************************************************/
fsp_err_t R_BSP_ClockDividerSet (fsp_priv_clock_divider_t divider, uint32_t clock_div)
{
    switch (divider)
    {
#if defined(BSP_CFG_DIVPL1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL1:
#endif
#if defined(BSP_CFG_DIV_PLL1_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55:
#endif
#if defined(BSP_CFG_DIVPL1_SET_DIV) || defined(BSP_CFG_DIV_PLL1_A_SET_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                              R_CPG->CPG_PLL1_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIVPL2B_SET_DIV) || defined(BSP_CFG_DIV_PLL2_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_100:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                              R_CPG->CPG_PLL2_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIVPL3A_SET_DIV) || defined(BSP_CFG_DIV_PLL3_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_200:
#endif
#if defined(BSP_CFG_DIVPL3B_SET_DIV) || defined(BSP_CFG_DIV_PLL3_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_100:
#endif
#if defined(BSP_CFG_DIVPL3C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_200MCPU:
#endif
#if defined(BSP_CFG_DIVPL3A_SET_DIV) || defined(BSP_CFG_DIV_PLL3_A_SET_DIV) || defined(BSP_CFG_DIVPL3B_SET_DIV) || \
        defined(BSP_CFG_DIV_PLL3_B_SET_DIV) || defined(BSP_CFG_DIVPL3C_SET_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) &
                              R_CPG->CPG_PLL3_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIVPL6A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIVPL6A:
#endif
#if defined(BSP_CFG_DIVPL6B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIVPL6B:
#endif
#if defined(BSP_CFG_DIVPL6A_SET_DIV) || defined(BSP_CFG_DIVPL6B_SET_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                              R_CPG->CPG_PLL6_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIVSDHI0_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI0_SEL:
        {
            uint32_t sel =
                (uint32_t) ((R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Msk & R_CPG->CPG_SDHI_DSEL) >>
                            R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Pos);

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL1_600 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                  R_CPG->CPG_PLL1_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                                  R_CPG->CPG_PLL2_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIVSDHI1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI1_SEL:
        {
            uint32_t sel =
                (uint32_t) ((R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Msk & R_CPG->CPG_SDHI_DSEL) >>
                            R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Pos);

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL1_600 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                  R_CPG->CPG_PLL1_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                                  R_CPG->CPG_PLL2_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIVSDHI2_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI2_SEL:
        {
            uint32_t sel =
                (uint32_t) ((R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Msk & R_CPG->CPG_SDHI_DSEL) >>
                            R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Pos);

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL1_600 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                  R_CPG->CPG_PLL1_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_500 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                                  R_CPG->CPG_PLL2_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIVOCTA_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_OCTA:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 ==
                ((R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Msk & R_CPG->CPG_OCTA_SSEL) >> R_CPG_CPG_OCTA_SSEL_SELOCTA_SET_Pos))
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) &
                                  R_CPG->CPG_PLL3_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIVSPI_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_SPI:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL6_250 ==
                ((R_CPG_CPG_SPI_SSEL_SELSPI_SET_Msk & R_CPG->CPG_SPI_SSEL) >> R_CPG_CPG_SPI_SSEL_SELSPI_SET_Pos))
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) &
                                  R_CPG->CPG_PLL3_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV0_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_CST400:
#endif
#if defined(BSP_CFG_CDDIV0_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33:
#endif
#if defined(BSP_CFG_CSDIV0_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_XSPI:
#endif
#if defined(BSP_CFG_CSDIV1_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_PCLK:
#endif
#if defined(BSP_CFG_CSDIV1_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_ADCLK:
#endif
#if defined(BSP_CFG_CDDIV0_DIVCTL0_DIV) || defined(BSP_CFG_CDDIV0_DIVCTL1_DIV) ||     \
        defined(BSP_CFG_CSDIV0_DIVCTL3_DIV) || defined(BSP_CFG_CSDIV1_DIVCTL0_DIV) || \
        defined(BSP_CFG_CSDIV1_DIVCTL1_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLCM33_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCM33_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLCM33_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCM33_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLCM33_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV0_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_ACPU:
#endif
#if defined(BSP_CFG_CDDIV3_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_RCPU:
#endif
#if defined(BSP_CFG_CDDIV5_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_NPU:
#endif
#if defined(BSP_CFG_CDDIV0_DIVCTL2_DIV) || defined(BSP_CFG_CDDIV3_DIVCTL2_DIV) || \
        defined(BSP_CFG_CDDIV5_DIVCTL0_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLDTY_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV0_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLCA55_SCLK:
        {
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL0_PLLCA55 ==
                ((R_CPG_CPG_SSEL0_SELCTL0_Msk & R_CPG->CPG_SSEL0) >> R_CPG_CPG_SSEL0_SELCTL0_Pos))
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk) &
                                  R_CPG->CPG_PLLCA55_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLVDO ==
                    ((R_CPG_CPG_SSEL0_SELCTL1_Msk & R_CPG->CPG_SSEL0) >> R_CPG_CPG_SSEL0_SELCTL1_Pos))
                {
                    FSP_ERROR_RETURN((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) ==
                                     ((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) &
                                      R_CPG->CPG_PLLVDO_MON),
                                     FSP_ERR_PLL_SRC_INACTIVE);
                }
                else
                {
                    FSP_ERROR_RETURN((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) ==
                                     ((R_CPG_CPG_PLLDTY_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDTY_MON_PLLn_RESETB_Msk) &
                                      R_CPG->CPG_PLLDTY_MON),
                                     FSP_ERR_PLL_SRC_INACTIVE);
                }
            }

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV1_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_0:
#endif
#if defined(BSP_CFG_CDDIV1_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_1:
#endif
#if defined(BSP_CFG_CDDIV1_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_2:
#endif
#if defined(BSP_CFG_CDDIV1_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_3:
#endif
#if defined(BSP_CFG_CDDIV2_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_CA55PERI:
#endif
#if defined(BSP_CFG_CDDIV1_DIVCTL0_DIV) || defined(BSP_CFG_CDDIV1_DIVCTL1_DIV) ||     \
        defined(BSP_CFG_CDDIV1_DIVCTL2_DIV) || defined(BSP_CFG_CDDIV1_DIVCTL3_DIV) || \
        defined(BSP_CFG_CDDIV2_DIVCTL0_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLCA55_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLCA55_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLCA55_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_GPU:
#endif
#if defined(BSP_CFG_CDDIV3_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU0:
#endif
#if defined(BSP_CFG_CDDIV3_DIVCTL1_DIV) || defined(BSP_CFG_CDDIV3_DIVCTL3_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLVDO_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV4_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_NPU:
#endif
#if defined(BSP_CFG_CSDIV0_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE0:
#endif
#if defined(BSP_CFG_CSDIV0_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE1:
#endif
#if defined(BSP_CFG_CSDIV0_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLETH_LPCLK:
#endif
#if defined(BSP_CFG_CDDIV4_DIVCTL3_DIV) || defined(BSP_CFG_CSDIV0_DIVCTL0_DIV) || \
        defined(BSP_CFG_CSDIV0_DIVCTL1_DIV) || defined(BSP_CFG_CSDIV0_DIVCTL2_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLETH_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI0:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLDSI0_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI0_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLDSI0_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI0_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLDSI0_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI1:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLDSI1_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI1_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLDSI1_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI1_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLDSI1_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIV_PLL2_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_200:
#endif
#if defined(BSP_CFG_DIV_CLKQSPI_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_QSPI:
#endif
#if defined(BSP_CFG_DIV_PLL2_A_SET_DIV) || defined(BSP_CFG_DIV_CLKQSPI_SET_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                              R_CPG->CPG_PLL2_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIV_XSPI_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_XSPI:
        {
            uint32_t sel =
                (uint32_t) ((R_CPG_CPG_XSPI_SSEL_SEL_XSPI_SET_Msk & R_CPG->CPG_XSPI_SSEL) >>
                            R_CPG_CPG_XSPI_SSEL_SEL_XSPI_SET_Pos);

            if (BSP_CLOCKS_SOURCE_CLOCK_XSPI_600 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                  R_CPG->CPG_PLL1_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_XSPI_500 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                                  R_CPG->CPG_PLL2_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_GE3D_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_GE3D:
        {
            uint32_t sel =
                (uint32_t) ((R_CPG_CPG_GE3D_SSEL_SEL_GE3D_SET_Msk & R_CPG->CPG_GE3D_SSEL) >>
                            R_CPG_CPG_GE3D_SSEL_SEL_GE3D_SET_Pos);

            if (BSP_CLOCKS_SOURCE_CLOCK_GE3D_600 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                                  R_CPG->CPG_PLL1_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_GE3D_500 == sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                                  R_CPG->CPG_PLL6_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }
            else
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) &
                                  R_CPG->CPG_PLL3_MON),
                                 FSP_ERR_PLL_SRC_INACTIVE);
            }

            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CLK266FIXC_DIV16TO128:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                              R_CPG->CPG_PLL2_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIV_BSC_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_BSC:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL3_MON_PLL3_LOCK_Msk | R_CPG_CPG_PLL3_MON_PLL3_RESETB_Msk) &
                              R_CPG->CPG_PLL3_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIV_CORE0_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE0:
#endif
#if defined(BSP_CFG_DIV_CORE1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE1:
#endif
#if defined(BSP_CFG_DIV_CORE2_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE2:
#endif
#if defined(BSP_CFG_DIV_CORE3_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE3:
#endif
#if defined(BSP_CFG_DIV_CORE0_SET_DIV) || defined(BSP_CFG_DIV_CORE1_SET_DIV) || defined(BSP_CFG_DIV_CORE2_SET_DIV) || \
        defined(BSP_CFG_DIV_CORE3_SET_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL1_MON_PLL1_LOCK_Msk | R_CPG_CPG_PLL1_MON_PLL1_RESETB_Msk) &
                              R_CPG->CPG_PLL1_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIV_RSCI0_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI0:
#endif
#if defined(BSP_CFG_DIV_RSCI1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI1:
#endif
#if defined(BSP_CFG_DIV_RSCI2_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI2:
#endif
#if defined(BSP_CFG_DIV_RSCI3_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI3:
#endif
#if defined(BSP_CFG_DIV_RSPI0_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI0:
#endif
#if defined(BSP_CFG_DIV_RSPI1_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI1:
#endif
#if defined(BSP_CFG_DIV_RSPI2_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI2:
#endif
#if defined(BSP_CFG_DIV_RSCI0_SET_DIV) || defined(BSP_CFG_DIV_RSCI1_SET_DIV) || defined(BSP_CFG_DIV_RSCI2_SET_DIV) || \
        defined(BSP_CFG_DIV_RSCI3_SET_DIV) || defined(BSP_CFG_DIV_RSPI0_SET_DIV) ||                                   \
        defined(BSP_CFG_DIV_RSPI1_SET_DIV) || defined(BSP_CFG_DIV_RSPI2_SET_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL2_MON_PLL2_LOCK_Msk | R_CPG_CPG_PLL2_MON_PLL2_RESETB_Msk) &
                              R_CPG->CPG_PLL2_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIV_DSI_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO32_VCLK:
#endif
#if defined(BSP_CFG_DIV_DSI_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO16_VCLK:
#endif
#if defined(BSP_CFG_DIV_DSI_C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO2_LVDS:
#endif
#if defined(BSP_CFG_DIV_DSI_A_SET_DIV) || defined(BSP_CFG_DIV_DSI_B_SET_DIV) || defined(BSP_CFG_DIV_DSI_C_SET_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL7_MON_PLL7_LOCK_Msk | R_CPG_CPG_PLL7_MON_PLL7_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL7_MON_PLL7_LOCK_Msk | R_CPG_CPG_PLL7_MON_PLL7_RESETB_Msk) &
                              R_CPG->CPG_PLL7_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_DIV_ETH_A_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_TR:
#endif
#if defined(BSP_CFG_DIV_ETH_B_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_RM:
#endif
#if defined(BSP_CFG_DIV_ETH_C_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_TR:
#endif
#if defined(BSP_CFG_DIV_ETH_D_SET_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_RM:
#endif
#if defined(BSP_CFG_DIV_ETH_A_SET_DIV) || defined(BSP_CFG_DIV_ETH_B_SET_DIV) || defined(BSP_CFG_DIV_ETH_C_SET_DIV) || \
        defined(BSP_CFG_DIV_ETH_D_SET_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) ==
                             ((R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk | R_CPG_CPG_PLL6_MON_PLL6_RESETB_Msk) &
                              R_CPG->CPG_PLL6_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

        default:
        {
            FSP_ERROR_RETURN(FSP_PRIV_CLOCK_DIVIDER_NUM > divider, FSP_ERR_INVALID_ARGUMENT);
            break;
        }
    }

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    bsp_prv_clock_divider_set(divider, clock_div);

    FSP_CRITICAL_SECTION_EXIT;

    return FSP_SUCCESS;
}

/** @} (end addtogroup BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif
