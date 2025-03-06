/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
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
#define BSP_PRV_NUM_CLOCKS                (FSP_PRIV_CLOCK_NUM)
#define BSP_PRV_DIVISION_RATIO_2          (2UL)
#define BSP_PRV_DIVISION_RATIO_8          (8UL)
#define BSP_PRV_DIVISION_RATIO_10         (10UL)
#define BSP_PRV_DIVISION_RATIO_100        (100UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_2    (2UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_3    (3UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_4    (4UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_5    (5UL)
#define BSP_PRV_FIXED_DIVISION_RATIO_8    (8UL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void bsp_prv_static_mux_control_pre_setting(fsp_priv_clock_selector_t selector, uint32_t clock_status[]);
static void bsp_prv_static_mux_control_post_setting(fsp_priv_clock_selector_t selector, uint32_t clock_status[]);
static void bsp_prv_static_gear_control_pre_setting(fsp_priv_clock_divider_t divider, uint32_t clock_status[]);
static void bsp_prv_static_gear_control_post_setting(fsp_priv_clock_divider_t divider, uint32_t clock_status[]);
static void bsp_prv_clock_frequency_calculation(fsp_priv_clock_t clock);

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RENESAS_INTERNAL
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
#if defined(BSP_CFG_CLOCK_SDCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SDCLK] = BSP_CFG_CLOCK_SDCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_SD0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SD0CLK] = BSP_CFG_CLOCK_SD0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_SD1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SD1CLK] = BSP_CFG_CLOCK_SD1CLK_HZ;
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
 #if defined(BSP_CFG_CLOCK_PLLDSICLK_HZ)
    uint32_t plldsi_mon = (R_CPG_CPG_PLLDSI_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI_MON_PLLn_RESETB_Msk) &
                          R_CPG->CPG_PLLDSI_MON;
    if (!plldsi_mon)
    {
        R_CPG->CPG_PLLDSI_STBY = (uint32_t) (R_CPG_CPG_PLLDSI_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLDSI_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDSI_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDSI_MON),
                                   (R_CPG_CPG_PLLDSI_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI_MON_PLLn_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLGPUCLK_HZ)
    uint32_t pllgpu_mon = (R_CPG_CPG_PLLGPU_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLGPU_MON_PLLn_RESETB_Msk) &
                          R_CPG->CPG_PLLGPU_MON;
    if (!pllgpu_mon)
    {
        R_CPG->CPG_PLLGPU_STBY = (uint32_t) (R_CPG_CPG_PLLGPU_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLGPU_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLGPU_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLGPU_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLGPU_MON),
                                   (R_CPG_CPG_PLLGPU_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLGPU_MON_PLLn_RESETB_Msk));
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLDRPCLK_HZ)
    uint32_t plldrp_mon = (R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk) &
                          R_CPG->CPG_PLLDRP_MON;
    if (!plldrp_mon)
    {
        R_CPG->CPG_PLLDRP_STBY = (uint32_t) (R_CPG_CPG_PLLDRP_STBY_RESETB_WEN_Msk | R_CPG_CPG_PLLDRP_STBY_RESETB_Msk);
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDRP_MON),
                                   (R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk));
    }
 #endif

/* Set the divider and selector according to the contents of the Clocks tab. */
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
 #if defined(BSP_CFG_CDDIV2_DIVCTL1_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLDTY_CR8, BSP_CFG_CDDIV2_DIVCTL1_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV2_DIVCTL2_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLDTY_DRP, BSP_CFG_CDDIV2_DIVCTL2_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV2_DIVCTL3_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLVDO_ISP, BSP_CFG_CDDIV2_DIVCTL3_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV3_DIVCTL0_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLVDO_ISU, BSP_CFG_CDDIV3_DIVCTL0_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV3_DIVCTL1_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLGPU, BSP_CFG_CDDIV3_DIVCTL1_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV3_DIVCTL2_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLDTY_RCPU, BSP_CFG_CDDIV3_DIVCTL2_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV3_DIVCTL3_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU0, BSP_CFG_CDDIV3_DIVCTL3_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV4_DIVCTL0_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU1, BSP_CFG_CDDIV4_DIVCTL0_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV4_DIVCTL1_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU2, BSP_CFG_CDDIV4_DIVCTL1_DIV);
 #endif
 #if defined(BSP_CFG_CDDIV4_DIVCTL2_DIV)
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU3, BSP_CFG_CDDIV4_DIVCTL2_DIV);
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
    R_BSP_ClockDividerSet(FSP_PRIV_CLOCK_DIVIDER_PLLDSI, BSP_CFG_CSDIV1_DIVCTL2_DIV);
 #endif

/* Stop the operation of the PLL that was temporarily started before changing the settings. */
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
 #if defined(BSP_CFG_CLOCK_PLLDSICLK_HZ)
    if (!plldsi_mon)
    {
        R_CPG->CPG_PLLDSI_STBY = (uint32_t) R_CPG_CPG_PLLDSI_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDSI_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDSI_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLGPUCLK_HZ)
    if (!pllgpu_mon)
    {
        R_CPG->CPG_PLLGPU_STBY = (uint32_t) R_CPG_CPG_PLLGPU_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLGPU_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLGPU_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLGPU_MON),
                                   0U);
    }
 #endif
 #if defined(BSP_CFG_CLOCK_PLLDRPCLK_HZ)
    if (!plldrp_mon)
    {
        R_CPG->CPG_PLLDRP_STBY = (uint32_t) R_CPG_CPG_PLLDRP_STBY_RESETB_WEN_Msk;
        FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk) &
                                    R_CPG->CPG_PLLDRP_MON),
                                   0U);
    }
 #endif
#endif
}

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
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI:
        {
            clock_status[0] = R_CPG_CPG_CLKMON_7_CLK10_MON_Msk & R_CPG->CPG_CLKMON_7;
            clock_status[1] = R_CPG_CPG_CLKMON_7_CLK15_MON_Msk & R_CPG->CPG_CLKMON_7;

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
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI:
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
                if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLDRP == sel)
                {
                    g_clock_freq[FSP_PRIV_CLOCK_I5CLK] = BSP_CFG_CLOCK_PLLDRPCLK_HZ >> div;
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

#if defined(BSP_CFG_CDDIV2_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_I6CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV2_DIVCTL1_Msk & R_CPG->CPG_CDDIV2) >> R_CPG_CPG_CDDIV2_DIVCTL1_Pos;
            if (BSP_CLOCKS_PLLDTY_CR8_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_I6CLK] = BSP_CFG_CLOCK_PLLDTYCLK_HZ >> div;
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

#if defined(BSP_CFG_CDDIV2_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_P12CLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV2_DIVCTL2_Msk & R_CPG->CPG_CDDIV2) >> R_CPG_CPG_CDDIV2_DIVCTL2_Pos;
            if (BSP_CLOCKS_PLLDTY_DRP_DIV_64 == div)
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
            if (BSP_CLOCKS_PLLGPU_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_GPUCLK] = BSP_CFG_CLOCK_PLLGPUCLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV2_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_ISPCLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV2_DIVCTL3_Msk & R_CPG->CPG_CDDIV2) >> R_CPG_CPG_CDDIV2_DIVCTL3_Pos;
            if (BSP_CLOCKS_PLLVDO_ISP_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_ISPCLK] = BSP_CFG_CLOCK_PLLVDOCLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_ISUCLK:
        {
            uint32_t div = (R_CPG_CPG_CDDIV3_DIVCTL0_Msk & R_CPG->CPG_CDDIV3) >> R_CPG_CPG_CDDIV3_DIVCTL0_Pos;
            if (BSP_CLOCKS_PLLVDO_ISU_DIV_64 == div)
            {
                div = div + 1;
            }

            div = div + 1;

            g_clock_freq[FSP_PRIV_CLOCK_ISUCLK] = BSP_CFG_CLOCK_PLLVDOCLK_HZ >> div;
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

#if defined(BSP_CFG_CDDIV4_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_M1CLK:
        {
            uint32_t div = ((R_CPG_CPG_CDDIV4_DIVCTL0_Msk & R_CPG->CPG_CDDIV4) >> R_CPG_CPG_CDDIV4_DIVCTL0_Pos) + 1;
            g_clock_freq[FSP_PRIV_CLOCK_M1CLK] = BSP_CFG_CLOCK_PLLVDOCLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV4_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_M2CLK:
        {
            uint32_t div = ((R_CPG_CPG_CDDIV4_DIVCTL1_Msk & R_CPG->CPG_CDDIV4) >> R_CPG_CPG_CDDIV4_DIVCTL1_Pos) + 1;
            g_clock_freq[FSP_PRIV_CLOCK_M2CLK] = BSP_CFG_CLOCK_PLLVDOCLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV4_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_M3CLK:
        {
            uint32_t div = ((R_CPG_CPG_CDDIV4_DIVCTL2_Msk & R_CPG->CPG_CDDIV4) >> R_CPG_CPG_CDDIV4_DIVCTL2_Pos) + 1;
            g_clock_freq[FSP_PRIV_CLOCK_M3CLK] = BSP_CFG_CLOCK_PLLVDOCLK_HZ >> div;
            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_M4CLK:
        {
            uint32_t div = (((R_CPG_CPG_CSDIV1_DIVCTL2_Msk & R_CPG->CPG_CSDIV1) >> R_CPG_CPG_CSDIV1_DIVCTL2_Pos) + 1) *
                           2;
            g_clock_freq[FSP_PRIV_CLOCK_M4CLK] = BSP_CFG_CLOCK_PLLDSICLK_HZ / div;
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

#if defined(BSP_CFG_CDDIV2_DIVCTL1_DIV)

        /* Set the value to bit[6:4] the CPG_CDDIV2 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_CR8:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV2CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV2 = (uint32_t) (R_CPG_CPG_CDDIV2_DIVCTL1WEN_Msk |
                                            (R_CPG_CPG_CDDIV2_DIVCTL1_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV2_DIVCTL1_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV2CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_I6CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV2_DIVCTL2_DIV)

        /* Set the value to bit[10:8] the CPG_CDDIV2 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_DRP:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV2CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV2 = (uint32_t) (R_CPG_CPG_CDDIV2_DIVCTL2WEN_Msk |
                                            (R_CPG_CPG_CDDIV2_DIVCTL2_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV2_DIVCTL2_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV2CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_P12CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV2_DIVCTL3_DIV)

        /* Set the value to bit[14:12] the CPG_CDDIV2 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_ISP:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV2CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV2 = (uint32_t) (R_CPG_CPG_CDDIV2_DIVCTL3WEN_Msk |
                                            (R_CPG_CPG_CDDIV2_DIVCTL3_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV2_DIVCTL3_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV2CTL3_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ISPCLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL0_DIV)

        /* Set the value to bit[2:0] the CPG_CDDIV3 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_ISU:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV3CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV3 = (uint32_t) (R_CPG_CPG_CDDIV3_DIVCTL0WEN_Msk |
                                            (R_CPG_CPG_CDDIV3_DIVCTL0_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV3_DIVCTL0_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV3CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_ISUCLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL1_DIV)

        /* Set the value to bit[6:4] the CPG_CDDIV3 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLGPU:
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

#if defined(BSP_CFG_CDDIV4_DIVCTL0_DIV)

        /* Set the value to bit[2:0] the CPG_CDDIV4 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU1:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV4CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV4 = (uint32_t) (R_CPG_CPG_CDDIV4_DIVCTL0WEN_Msk |
                                            (R_CPG_CPG_CDDIV4_DIVCTL0_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV4_DIVCTL0_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV4CTL0_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M1CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV4_DIVCTL1_DIV)

        /* Set the value to bit[6:4] the CPG_CDDIV4 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU2:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV4CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV4 = (uint32_t) (R_CPG_CPG_CDDIV4_DIVCTL1WEN_Msk |
                                            (R_CPG_CPG_CDDIV4_DIVCTL1_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV4_DIVCTL1_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV4CTL1_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M2CLK);

            break;
        }
#endif

#if defined(BSP_CFG_CDDIV4_DIVCTL2_DIV)

        /* Set the value to bit[10:8] the CPG_CDDIV4 register. */
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU3:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV4CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);
            R_CPG->CPG_CDDIV4 = (uint32_t) (R_CPG_CPG_CDDIV4_DIVCTL2WEN_Msk |
                                            (R_CPG_CPG_CDDIV4_DIVCTL2_Msk &
                                             (clock_div << R_CPG_CPG_CDDIV4_DIVCTL2_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS0_DDIV4CTL2_STS_Msk & R_CPG->CPG_CLKSTATUS0), 0U);

            /* Update clock frequency information */
            bsp_prv_clock_frequency_calculation(FSP_PRIV_CLOCK_M3CLK);

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
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI:
        {
            uint32_t clock_status[2];

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
 * @addtogroup BSP_MCU
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
                if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLDRP ==
                    ((R_CPG_CPG_SSEL0_SELCTL1_Msk & R_CPG->CPG_SSEL0) >> R_CPG_CPG_SSEL0_SELCTL1_Pos))
                {
                    FSP_ERROR_RETURN((R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk) ==
                                     ((R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk) &
                                      R_CPG->CPG_PLLDRP_MON),
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
            if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLDRP == clock_sel)
            {
                FSP_ERROR_RETURN((R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk) ==
                                 ((R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk) &
                                  R_CPG->CPG_PLLDRP_MON),
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
#if defined(BSP_CFG_CDDIV2_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_CR8:
#endif
#if defined(BSP_CFG_CDDIV2_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_DRP:
#endif
#if defined(BSP_CFG_CDDIV3_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDTY_RCPU:
#endif
#if defined(BSP_CFG_CDDIV0_DIVCTL2_DIV) || defined(BSP_CFG_CDDIV2_DIVCTL1_DIV) || \
        defined(BSP_CFG_CDDIV2_DIVCTL2_DIV) || defined(BSP_CFG_CDDIV3_DIVCTL2_DIV)
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
                if (BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLDRP ==
                    ((R_CPG_CPG_SSEL0_SELCTL1_Msk & R_CPG->CPG_SSEL0) >> R_CPG_CPG_SSEL0_SELCTL1_Pos))
                {
                    FSP_ERROR_RETURN((R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk) ==
                                     ((R_CPG_CPG_PLLDRP_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDRP_MON_PLLn_RESETB_Msk) &
                                      R_CPG->CPG_PLLDRP_MON),
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

#if defined(BSP_CFG_CDDIV2_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_ISP:
#endif
#if defined(BSP_CFG_CDDIV3_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_ISU:
#endif
#if defined(BSP_CFG_CDDIV3_DIVCTL3_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU0:
#endif
#if defined(BSP_CFG_CDDIV4_DIVCTL0_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU1:
#endif
#if defined(BSP_CFG_CDDIV4_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU2:
#endif
#if defined(BSP_CFG_CDDIV4_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU3:
#endif
#if defined(BSP_CFG_CDDIV2_DIVCTL3_DIV) || defined(BSP_CFG_CDDIV3_DIVCTL0_DIV) ||     \
        defined(BSP_CFG_CDDIV3_DIVCTL3_DIV) || defined(BSP_CFG_CDDIV4_DIVCTL0_DIV) || \
        defined(BSP_CFG_CDDIV4_DIVCTL1_DIV) || defined(BSP_CFG_CDDIV4_DIVCTL2_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLVDO_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLVDO_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLVDO_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_CDDIV3_DIVCTL1_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLGPU:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLGPU_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLGPU_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLGPU_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLGPU_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLGPU_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
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
#if defined(BSP_CFG_CSDIV0_DIVCTL0_DIV) || defined(BSP_CFG_CSDIV0_DIVCTL1_DIV) || \
        defined(BSP_CFG_CSDIV0_DIVCTL2_DIV)
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLETH_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLETH_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLETH_MON),
                             FSP_ERR_PLL_SRC_INACTIVE);
            break;
        }
#endif

#if defined(BSP_CFG_CSDIV1_DIVCTL2_DIV)
        case FSP_PRIV_CLOCK_DIVIDER_PLLDSI:
        {
            FSP_ERROR_RETURN((R_CPG_CPG_PLLDSI_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI_MON_PLLn_RESETB_Msk) ==
                             ((R_CPG_CPG_PLLDSI_MON_PLLn_LOCK_Msk | R_CPG_CPG_PLLDSI_MON_PLLn_RESETB_Msk) &
                              R_CPG->CPG_PLLDSI_MON),
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
