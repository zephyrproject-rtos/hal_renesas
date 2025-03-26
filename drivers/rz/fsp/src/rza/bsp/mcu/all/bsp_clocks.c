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
#define BSP_PRV_NUM_CLOCKS    (FSP_PRIV_CLOCK_NUM)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void             bsp_prv_clock_pre_setting(fsp_priv_clock_t clock);
static void             bsp_prv_clock_post_setting(fsp_priv_clock_t clock);
static fsp_priv_clock_t bsp_prv_clock_convert_selector_to_clock(fsp_priv_clock_selector_t selector);
static fsp_priv_clock_t bsp_prv_clock_convert_divider_to_clock(fsp_priv_clock_divider_t divider);
static fsp_err_t        bsp_prv_clock_check_pll(fsp_priv_clock_t clock);

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

/* This array stores the clock frequency of each bus clock. This section of RAM should not be initialized by the C
 * runtime environment. This is initialized and used in bsp_clock_init, which is called before the C runtime
 * environment is initialized. */
static uint32_t g_clock_freq[BSP_PRV_NUM_CLOCKS] =
{
    BSP_CFG_CLOCK_ICLK_HZ,             /* Initial value of Cortex-A55 Clock */
    BSP_CFG_CLOCK_I2CLK_HZ,            /* Initial value of Cortex-M33 Clock */
    BSP_CFG_CLOCK_S0CLK_HZ,            /* Initial value of DDR-PHY Clock */
    BSP_CFG_CLOCK_SPI0CLK_HZ,          /* Initial value of SPI0 Clock */
    BSP_CFG_CLOCK_SPI1CLK_HZ,          /* Initial value of SPI1 Clock */
#if BSP_FEATURE_CPG_HAS_OC0CLK
    BSP_CFG_CLOCK_OC0CLK_HZ,           /* Initial value of OC0 Clock */
#else
    0U,                                /* OC0 Clock is not available on this MPU. */
#endif
#if BSP_FEATURE_CPG_HAS_OC1CLK
    BSP_CFG_CLOCK_OC1CLK_HZ,           /* Initial value of OC1 Clock */
#else
    0U,                                /* OC1 Clock is not available on this MPU. */
#endif
#if BSP_FEATURE_CPG_HAS_SD0CLK
    BSP_CFG_CLOCK_SD0CLK_HZ,           /* Initial value of SDH0 Clock */
#else
    0U,                                /* SDH0 Clock is not available on this MPU. */
#endif
#if BSP_FEATURE_CPG_HAS_SD1CLK
    BSP_CFG_CLOCK_SD1CLK_HZ,           /* Initial value of SDH1 Clock */
#else
    0U,                                /* SDH1 Clock is not available on this MPU. */
#endif
    BSP_CFG_CLOCK_M0CLK_HZ,            /* Initial value of VCP, LCDC Clock */
    BSP_CFG_CLOCK_M2CLK_HZ,            /* Initial value of CRU, MIPI-DSI Clock */
    BSP_CFG_CLOCK_M3CLK_HZ,            /* Initial value of MIPI-DSI, LCDC Clock */
#if BSP_FEATURE_CPG_HAS_HPCLK
    BSP_CFG_CLOCK_HPCLK_HZ,            /* Initial value of Ethernet Clock */
#else
    0U,                                /* Ethernet Clock is not available on this MPU. */
#endif
    BSP_CFG_CLOCK_TSUCLK_HZ,           /* Initial value of TSU Clock */
    BSP_CFG_CLOCK_ZTCLK_HZ,            /* Initial value of JAUTH Clock */
    BSP_CFG_CLOCK_P0CLK_HZ,            /* Initial value of APB-BUS Clock */
    BSP_CFG_CLOCK_P1CLK_HZ,            /* Initial value of AXI-BUS Clock */
    BSP_CFG_CLOCK_P2CLK_HZ,            /* Initial value of P2CLK */
    BSP_CFG_CLOCK_ATCLK_HZ,            /* Initial value of ATCLK */
    BSP_CFG_CLOCK_OSCCLK_HZ,           /* Initial value of OSC Clock */
};

/*******************************************************************************************************************//**
 * Update SystemCoreClock variable based on current clock settings.
 **********************************************************************************************************************/
void SystemCoreClockUpdate (void)
{
    SystemCoreClock = g_clock_freq[FSP_PRIV_CLOCK_ICLK];
}

/*******************************************************************************************************************//**
 * Initializes variable to store system clock frequencies.
 **********************************************************************************************************************/
#if BSP_TZ_CFG_INIT_SECURE_ONLY
void bsp_clock_freq_var_init(void);

void bsp_clock_freq_var_init (void)
#else
static void bsp_clock_freq_var_init (void)
#endif
{
    g_clock_freq[FSP_PRIV_CLOCK_ICLK]    = BSP_CFG_CLOCK_ICLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_I2CLK]   = BSP_CFG_CLOCK_I2CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_S0CLK]   = BSP_CFG_CLOCK_S0CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = BSP_CFG_CLOCK_SPI0CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK] = BSP_CFG_CLOCK_SPI1CLK_HZ;
#if BSP_FEATURE_CPG_HAS_OC0CLK
    g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] = BSP_CFG_CLOCK_OC0CLK_HZ;
#endif
#if BSP_FEATURE_CPG_HAS_OC1CLK
    g_clock_freq[FSP_PRIV_CLOCK_OC1CLK] = BSP_CFG_CLOCK_OC1CLK_HZ;
#endif
#if BSP_FEATURE_CPG_HAS_SD0CLK
    g_clock_freq[FSP_PRIV_CLOCK_SD0CLK] = BSP_CFG_CLOCK_SD0CLK_HZ;
#endif
#if BSP_FEATURE_CPG_HAS_SD1CLK
    g_clock_freq[FSP_PRIV_CLOCK_SD1CLK] = BSP_CFG_CLOCK_SD1CLK_HZ;
#endif
    g_clock_freq[FSP_PRIV_CLOCK_M0CLK] = BSP_CFG_CLOCK_M0CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_M2CLK] = BSP_CFG_CLOCK_M2CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_M3CLK] = BSP_CFG_CLOCK_M3CLK_HZ;
#if BSP_FEATURE_CPG_HAS_HPCLK
    g_clock_freq[FSP_PRIV_CLOCK_HPCLK] = BSP_CFG_CLOCK_HPCLK_HZ;
#endif
    g_clock_freq[FSP_PRIV_CLOCK_TSUCLK] = BSP_CFG_CLOCK_TSUCLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_ZTCLK]  = BSP_CFG_CLOCK_ZTCLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_P0CLK]  = BSP_CFG_CLOCK_P0CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_P1CLK]  = BSP_CFG_CLOCK_P1CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_P2CLK]  = BSP_CFG_CLOCK_P2CLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_ATCLK]  = BSP_CFG_CLOCK_ATCLK_HZ;
    g_clock_freq[FSP_PRIV_CLOCK_OSCCLK] = BSP_CFG_CLOCK_OSCCLK_HZ;

    /* The SystemCoreClock needs to be updated before calling R_BSP_SoftwareDelay. */
    SystemCoreClockUpdate();
}

/*******************************************************************************************************************//**
 * Initializes system clocks.  Makes no assumptions about current register settings.
 **********************************************************************************************************************/
void bsp_clock_init (void)
{
    bsp_clock_freq_var_init();

    /* Stop unnecessary clocks to reduce power consumption. */
    bsp_clock_off();

#if BSP_FEATURE_CPG_HAS_ICLK

    /* ICLK setting */
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_DIVPL1_STS_Pos,
                               0U);
    R_CPG->CPG_PL1_DDIV = (uint32_t) (R_CPG_CPG_PL1_DDIV_DIV_PLL1SET_WEN_Msk | \
                                      (R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Msk &     \
                                       (BSP_CFG_DIVPL1_SET_DIV << R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Pos)));
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_DIVPL1_STS_Pos,
                               0U);
#endif

#if BSP_FEATURE_CPG_HAS_SD0CLK

    /* SD0CLK setting */
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Pos,
                               0U);
    R_CPG->CPG_PL2SDHI_DSEL = (uint32_t) (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI0_WEN_Msk |  \
                                          (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI0_SET_Msk & \
                                           (BSP_CFG_SEL_SDHI0_SET_SOURCE << R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI0_SET_Pos)));
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Pos,
                               0U);
#endif

#if BSP_FEATURE_CPG_HAS_SD1CLK

    /* SD1CLK setting */
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Pos,
                               0U);
    R_CPG->CPG_PL2SDHI_DSEL = (uint32_t) (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI1_WEN_Msk |  \
                                          (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI1_SET_Msk & \
                                           (BSP_CFG_SEL_SDHI1_SET_SOURCE << R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI1_SET_Pos)));
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Pos,
                               0U);
#endif

#if BSP_FEATURE_CPG_HAS_P0CLK

    /* P0CLK setting */
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL2A_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_DIVPL2A_STS_Pos,
                               0U);
    R_CPG->CPG_PL2_DDIV = (uint32_t) (R_CPG_CPG_PL2_DDIV_DIV_PLL2_A_WEN_Msk | \
                                      (R_CPG_CPG_PL2_DDIV_DIVPL2A_SET_Msk &   \
                                       (BSP_CFG_DIVPL2A_SET_DIV << R_CPG_CPG_PL2_DDIV_DIVPL2A_SET_Pos)));
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL2A_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_DIVPL2A_STS_Pos,
                               0U);
#endif

#if BSP_FEATURE_CPG_HAS_P1CLK

    /* P1CLK setting */
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3B_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_DIVPL3B_STS_Pos,
                               0U);
    R_CPG->CPG_PL3A_DDIV = (uint32_t) (R_CPG_CPG_PL3A_DDIV_DIV_PLL3_B_WEN_Msk | \
                                       (R_CPG_CPG_PL3A_DDIV_DIVPL3B_SET_Msk &   \
                                        (BSP_CFG_DIVPL3B_SET_DIV << R_CPG_CPG_PL3A_DDIV_DIVPL3B_SET_Pos)));
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3B_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_DIVPL3B_STS_Pos,
                               0U);
#endif

#if BSP_FEATURE_CPG_HAS_P2CLK

    /* P2CLK setting */
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3A_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_DIVPL3A_STS_Pos,
                               0U);
    R_CPG->CPG_PL3A_DDIV = (uint32_t) (R_CPG_CPG_PL3A_DDIV_DIV_PLL3_A_WEN_Msk | \
                                       (R_CPG_CPG_PL3A_DDIV_DIVPL3A_SET_Msk &   \
                                        (BSP_CFG_DIVPL3A_SET_DIV << R_CPG_CPG_PL3A_DDIV_DIVPL3A_SET_Pos)));
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3A_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                               R_CPG_CPG_CLKSTATUS_DIVPL3A_STS_Pos,
                               0U);
#endif

#if BSP_FEATURE_CPG_HAS_I2CLK

    /* I2CLK setting */
    if ((BSP_CFG_DIVPL3CLK200FIX_SET_DIV << R_CPG_CPG_PL3B_DDIV_DIVPL3CLK200FIX_SET_Pos) != R_CPG->CPG_PL3B_DDIV)
    {
        FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3CLK200FIX_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                                   R_CPG_CPG_CLKSTATUS_DIVPL3CLK200FIX_STS_Pos,
                                   0U);
        R_CPG->CPG_PL3B_DDIV = (uint32_t) (R_CPG_CPG_PL3B_DDIV_DIV_PLL3_CLK200FIX_WEN_Msk | \
                                           (R_CPG_CPG_PL3B_DDIV_DIVPL3CLK200FIX_SET_Msk &   \
                                            (BSP_CFG_DIVPL3CLK200FIX_SET_DIV <<
                                             R_CPG_CPG_PL3B_DDIV_DIVPL3CLK200FIX_SET_Pos)));
        FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3CLK200FIX_STS_Msk & R_CPG->CPG_CLKSTATUS) >> \
                                   R_CPG_CPG_CLKSTATUS_DIVPL3CLK200FIX_STS_Pos,
                                   0U);
    }
    else
    {
        /* Do nothing when the value which want to set and the value of CPG_PL3B_DDIV register is equal.*/
    }
#endif

#if BSP_FEATURE_CPG_HAS_M3CLK
 #if BSP_FEATURE_BSP_SUPPORT_PLL5_CONFIG

    /*
     * We need to stop the PLL5 before changing the settings.
     * Also, we need to disable the SSCG mode when enabling the PLL5.
     *
     * Refer to the User's Manual at section of "Procedure for Switching Clocks by the Static Switching Frequency
     * Dividers and Selectors" for more details.
     */
    R_CPG->CPG_SIPLL5_STBY = (uint32_t) (R_CPG_CPG_SIPLL5_STBY_SSCG_EN_WEN_Msk | R_CPG_CPG_SIPLL5_STBY_RESETB_WEN_Msk);

    /* Wait for the PLL5 to stop. */
    FSP_HARDWARE_REGISTER_WAIT(R_CPG->CPG_SIPLL5_MON, 0U);

    /* Configure the CPG_SIPLL5_CLK1 register. */
    R_CPG->CPG_SIPLL5_CLK1 = (uint32_t) (R_CPG_CPG_SIPLL5_CLK1_REFDIV_Msk &                                     \
                                         (BSP_CFG_CLOCK_PLL5_REFDIV << R_CPG_CPG_SIPLL5_CLK1_REFDIV_Pos)) |     \
                             (uint32_t) (R_CPG_CPG_SIPLL5_CLK1_POSTDIV1_Msk &                                   \
                                         (BSP_CFG_CLOCK_PLL5_POSTDIV1 << R_CPG_CPG_SIPLL5_CLK1_POSTDIV1_Pos)) | \
                             (uint32_t) (R_CPG_CPG_SIPLL5_CLK1_POSTDIV2_Msk &                                   \
                                         (BSP_CFG_CLOCK_PLL5_POSTDIV2 << R_CPG_CPG_SIPLL5_CLK1_POSTDIV2_Pos));

    /* Configure the CPG_SIPLL5_CLK3 register. */
    const uint32_t divval = R_CPG->CPG_SIPLL5_CLK3_b.DIVVAL;
    R_CPG->CPG_SIPLL5_CLK3 = (uint32_t) (R_CPG_CPG_SIPLL5_CLK3_FRACIN_Msk &                                 \
                                         (BSP_CFG_CLOCK_PLL5_FRACIN << R_CPG_CPG_SIPLL5_CLK3_FRACIN_Pos)) | \
                             (uint32_t) (R_CPG_CPG_SIPLL5_CLK3_DIVVAL_Msk & divval);

    /* Configure the CPG_SIPLL5_CLK4 register. */
    R_CPG->CPG_SIPLL5_CLK4 = (uint32_t) (R_CPG_CPG_SIPLL5_CLK4_INTIN_Msk & \
                                         (BSP_CFG_CLOCK_PLL5_INTIN << R_CPG_CPG_SIPLL5_CLK4_INTIN_Pos));

    /* Disable power down mode of FOUTPOSTDIV and FOUTVCO clocks. */
    R_CPG->CPG_SIPLL5_CLK2 =
        (uint32_t) (R_CPG_CPG_SIPLL5_CLK2_FOUTPOSTDIVPD_WEN_Msk | R_CPG_CPG_SIPLL5_CLK2_FOUTVCOPD_WEN_Msk);

  #if BSP_FEATURE_CPG_HAS_PLL5_SOURCE_FOUTPOSTDIV

    /* Set the clock source of the PLL5. */
    R_CPG->CPG_OTHERFUNC1_REG = (uint32_t) (R_CPG_CPG_OTHERFUNC1_REG_RES0_ON_WEN_Msk | \
                                            (R_CPG_CPG_OTHERFUNC1_REG_RES0_SET_Msk &   \
                                             (BSP_CFG_SEL_PLL5_SET_SOURCE << R_CPG_CPG_OTHERFUNC1_REG_RES0_SET_Pos)));
  #endif
 #endif

    /* M3CLK dividers setting */
    R_CPG->CPG_PL5_SDIV = (uint32_t) (R_CPG_CPG_PL5_SDIV_DIV_DSI_A_WEN_Msk |                              \
                                      R_CPG_CPG_PL5_SDIV_DIV_DSI_B_WEN_Msk |                              \
                                      (R_CPG_CPG_PL5_SDIV_DIVDSIB_SET_Msk &                               \
                                       (BSP_CFG_DIVDSIB_SET_DIV << R_CPG_CPG_PL5_SDIV_DIVDSIB_SET_Pos)) | \
                                      (R_CPG_CPG_PL5_SDIV_DIVDSIA_SET_Msk &                               \
                                       (BSP_CFG_DIVDSIA_SET_DIV << R_CPG_CPG_PL5_SDIV_DIVDSIA_SET_Pos)));

 #if BSP_FEATURE_BSP_SUPPORT_PLL5_CONFIG

    /* Enable the PLL5. */
    R_CPG->CPG_SIPLL5_STBY = (uint32_t) (R_CPG_CPG_SIPLL5_STBY_RESETB_WEN_Msk | R_CPG_CPG_SIPLL5_STBY_RESETB_Msk);

    /* Wait for the PLL5 to lock. */
    FSP_HARDWARE_REGISTER_WAIT(R_CPG->CPG_SIPLL5_MON,
                               (R_CPG_CPG_SIPLL5_MON_PLL5_LOCK_Msk | R_CPG_CPG_SIPLL5_MON_PLL5_RESETB_Msk));
 #endif
#endif

#if BSP_FEATURE_CPG_HAS_HPCLK

    /* HPCLK setting  */
    R_CPG->CPG_PL6_ETH_SSEL = (uint32_t) (R_CPG_CPG_PL6_ETH_SSEL_SEL_PLL6_2_WEN_Msk |  \
                                          (R_CPG_CPG_PL6_ETH_SSEL_SEL_PLL6_2_SET_Msk & \
                                           (BSP_CFG_SEL_PLL6_2_SET_SOURCE <<
                                            R_CPG_CPG_PL6_ETH_SSEL_SEL_PLL6_2_SET_Pos)));
#endif
}

/*******************************************************************************************************************//**
 * Perform any necessary processing before changing the frequency.
 *
 * @param[in] clock                    Desired clock
 **********************************************************************************************************************/
static void bsp_prv_clock_pre_setting (fsp_priv_clock_t clock)
{
    FSP_PARAMETER_NOT_USED(clock);
}

/*******************************************************************************************************************//**
 * Perform any necessary processing after changing the frequency.
 *
 * @param[in] clock                    Desired clock
 **********************************************************************************************************************/
static void bsp_prv_clock_post_setting (fsp_priv_clock_t clock)
{
    FSP_PARAMETER_NOT_USED(clock);
}

/*******************************************************************************************************************//**
 * Set the Source Clock Setting register to change the frequency.
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of each clock.
 * @param[in]   clock_sel             Value to set in Source Clock Setting register.
 **********************************************************************************************************************/
fsp_err_t bsp_prv_clock_selector_set (fsp_priv_clock_t clock, uint32_t clock_sel)
{
    uint32_t clock_freq = g_clock_freq[clock];

    switch (clock)
    {
#if BSP_FEATURE_CPG_HAS_SD0CLK

        /* Set the value to bit[1:0] of the CPG_PL2SDHI_DSEL register. */
        case FSP_PRIV_CLOCK_SD0CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Pos,
                                       0U);

            /* Select the 266MHz source once before changing to the desired settings (see section
             * 'Source Clock Setting (SDHI) Register (CPG_PL2SDHI_DSEL)' of the user's manual). */
            R_CPG->CPG_PL2SDHI_DSEL = (uint32_t) (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI0_WEN_Msk |
                                                  (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI0_SET_Msk &
                                                   (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266 <<
                                                    R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI0_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Pos,
                                       0U);
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266 != clock_sel)
            {
                R_CPG->CPG_PL2SDHI_DSEL = (uint32_t) (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI0_WEN_Msk |
                                                      (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI0_SET_Msk &
                                                       (clock_sel << R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI0_SET_Pos)));
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                           R_CPG_CPG_CLKSTATUS_SELSDHI0_STS_Pos,
                                           0U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_533 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_533_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_1600_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_533_HZ >> 1;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            break;
        }
#endif

#if BSP_FEATURE_CPG_HAS_SD1CLK

        /* Set the value to bit[5:4] of the CPG_PL2SDHI_DSEL register. */
        case FSP_PRIV_CLOCK_SD1CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Pos,
                                       0U);

            /* Select the 266MHz source once before changing to the desired settings (see section
             * 'Source Clock Setting (SDHI) Register (CPG_PL2SDHI_DSEL)' of the user's manual). */
            R_CPG->CPG_PL2SDHI_DSEL = (uint32_t) (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI1_WEN_Msk |
                                                  (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI1_SET_Msk &
                                                   (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266 <<
                                                    R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Pos,
                                       0U);
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266 != clock_sel)
            {
                R_CPG->CPG_PL2SDHI_DSEL = (uint32_t) (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI1_WEN_Msk |
                                                      (R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI1_SET_Msk &
                                                       (clock_sel << R_CPG_CPG_PL2SDHI_DSEL_SEL_SDHI1_SET_Pos)));
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                           R_CPG_CPG_CLKSTATUS_SELSDHI1_STS_Pos,
                                           0U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_533 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_533_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_1600_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL2_266 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL2_533_HZ >> 1;
            }
            else
            {
                /* If this condition is met, clock_sel is an invalid value. */
                ;
            }

            break;
        }
#endif

        /* Set the value to bit[8] of the CPG_PL3_SSEL register. */
        case FSP_PRIV_CLOCK_SPI0CLK:
        {
            uint32_t clock_mon = (uint32_t) ((R_CPG_CPG_CLKMON_SPI_MULTI_CLK1_MON_Msk & R_CPG->CPG_CLKMON_SPI_MULTI) >>
                                             R_CPG_CPG_CLKMON_SPI_MULTI_CLK1_MON_Pos);

            /* If SPI_CLK is supplied, the clock stops before setting the CPG_PL3_SSEL register. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_SPI_MULTI = R_CPG_CPG_CLKON_SPI_MULTI_CLK1_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_MULTI_CLK1_MON_Msk & R_CPG->CPG_CLKMON_SPI_MULTI) >>
                                           R_CPG_CPG_CLKMON_SPI_MULTI_CLK1_MON_Pos,
                                           0U);
            }

            R_CPG->CPG_PL3_SSEL = (uint32_t) (R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_WEN_Msk |
                                              (R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_SET_Msk &
                                               (clock_sel << R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_SET_Pos)));

            /* If the clock was stopped before setting the CPG_PL3_SSEL register, the clock supply resumes. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_SPI_MULTI = (uint32_t) (R_CPG_CPG_CLKON_SPI_MULTI_CLK1_ONWEN_Msk |
                                                         R_CPG_CPG_CLKON_SPI_MULTI_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_MULTI_CLK1_MON_Msk & R_CPG->CPG_CLKMON_SPI_MULTI) >>
                                           R_CPG_CPG_CLKMON_SPI_MULTI_CLK1_MON_Pos,
                                           1U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_533 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_533_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_400_HZ;
            }
            else
            {
                /* If this condition is met, clock_sel is an invalid value. */
                ;
            }

            uint32_t clock_div = (uint32_t) ((R_CPG_CPG_PL3A_DDIV_DIVPL3C_SET_Msk & R_CPG->CPG_PL3A_DDIV) >>
                                             R_CPG_CPG_PL3A_DDIV_DIVPL3C_SET_Pos);
            if (BSP_CLOCKS_PL3C_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 1);

            /* Changing settings for the SPI0 clock related register, SPI1 clock frequency changes at the same time.
             * So it is updated the variable that stored SPI1 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK] = clock_freq >> 1;
            break;
        }

        /* Set the value to bit[8] of the CPG_PL3_SSEL register. */
        case FSP_PRIV_CLOCK_SPI1CLK:
        {
            uint32_t clock_mon = (uint32_t) ((R_CPG_CPG_CLKMON_SPI_MULTI_CLK0_MON_Msk & R_CPG->CPG_CLKMON_SPI_MULTI) >>
                                             R_CPG_CPG_CLKMON_SPI_MULTI_CLK0_MON_Pos);

            /* If SPI_CLK is supplied, the clock stops before setting the CPG_PL3_SSEL register. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_SPI_MULTI = R_CPG_CPG_CLKON_SPI_MULTI_CLK0_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_MULTI_CLK0_MON_Msk & R_CPG->CPG_CLKMON_SPI_MULTI) >>
                                           R_CPG_CPG_CLKMON_SPI_MULTI_CLK0_MON_Pos,
                                           0U);
            }

            R_CPG->CPG_PL3_SSEL = (uint32_t) (R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_WEN_Msk |
                                              (R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_SET_Msk &
                                               (clock_sel << R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_SET_Pos)));

            /* If the clock was stopped before setting the CPG_PL3_SSEL register, the clock supply resumes. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_SPI_MULTI = (uint32_t) (R_CPG_CPG_CLKON_SPI_MULTI_CLK0_ONWEN_Msk |
                                                         R_CPG_CPG_CLKON_SPI_MULTI_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_SPI_MULTI_CLK0_MON_Msk & R_CPG->CPG_CLKMON_SPI_MULTI) >>
                                           R_CPG_CPG_CLKMON_SPI_MULTI_CLK0_MON_Pos,
                                           1U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_533 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_533_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_400_HZ;
            }
            else
            {
                /* If this condition is met, clock_sel is an invalid value. */
                ;
            }

            uint32_t clock_div = (uint32_t) ((R_CPG_CPG_PL3A_DDIV_DIVPL3C_SET_Msk & R_CPG->CPG_PL3A_DDIV) >>
                                             R_CPG_CPG_PL3A_DDIV_DIVPL3C_SET_Pos);
            if (BSP_CLOCKS_PL3C_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 2);

            /* Changing settings for the SPI1 clock related register, SPI0 clock frequency changes at the same time.
             * So it is updated the variable that stored SPI0 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = clock_freq << 1;
            break;
        }

#if BSP_FEATURE_CPG_HAS_OC0CLK

        /* Set the value to bit[12] of the CPG_PL3_SSEL register. */
        case FSP_PRIV_CLOCK_OC0CLK:
        {
            uint32_t clock_mon = (uint32_t) ((R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                             R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Pos);

            /* If OCTA_MCLK is supplied, the clock stops before setting the CPG_PL3_SSEL register. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_OCTA = R_CPG_CPG_CLKON_OCTA_CLK1_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                           R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Pos,
                                           0U);
            }

            R_CPG->CPG_PL3_SSEL = (uint32_t) (R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_WEN_Msk |
                                              (R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_SET_Msk &
                                               (clock_sel << R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_SET_Pos)));

            /* If the clock was stopped before setting the CPG_PL3_SSEL register, the clock supply resumes. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_OCTA = (uint32_t) (R_CPG_CPG_CLKON_OCTA_CLK1_ONWEN_Msk |
                                                    R_CPG_CPG_CLKON_OCTA_CLK1_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                           R_CPG_CPG_CLKMON_OCTA_CLK1_MON_Pos,
                                           1U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_533 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_533_HZ >> 1;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_400_HZ >> 1;
            }
            else
            {
                /* If this condition is met, clock_sel is an invalid value. */
                ;
            }

            uint32_t clock_div = (uint32_t) ((R_CPG_CPG_PL3A_DDIV_DIVPL3F_SET_Msk & R_CPG->CPG_PL3A_DDIV) >>
                                             R_CPG_CPG_PL3A_DDIV_DIVPL3F_SET_Pos);
            if (BSP_CLOCKS_PL3F_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div);

            /* Changing settings for the OC0 clock related register, OC1 clock frequency changes at the same time.
             * So it is updated the variable that stored OC1 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_OC1CLK] = clock_freq >> 1;
            break;
        }
#endif

#if BSP_FEATURE_CPG_HAS_OC1CLK

        /* Set the value to bit[12] of the CPG_PL3_SSEL register. */
        case FSP_PRIV_CLOCK_OC1CLK:
        {
            uint32_t clock_mon = (uint32_t) ((R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                             R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Pos);

            /* If OCTA_ACLK is supplied, the clock stops before setting the CPG_PL3_SSEL register. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_OCTA = R_CPG_CPG_CLKON_OCTA_CLK0_ONWEN_Msk;
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                           R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Pos,
                                           0U);
            }

            R_CPG->CPG_PL3_SSEL = (uint32_t) (R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_WEN_Msk |
                                              (R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_SET_Msk &
                                               (clock_sel << R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_SET_Pos)));

            /* If the clock was stopped before setting the CPG_PL3_SSEL register, the clock supply resumes. */
            if (clock_mon)
            {
                R_CPG->CPG_CLKON_OCTA = (uint32_t) (R_CPG_CPG_CLKON_OCTA_CLK0_ONWEN_Msk |
                                                    R_CPG_CPG_CLKON_OCTA_CLK0_ON_Msk);
                FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Msk & R_CPG->CPG_CLKMON_OCTA) >>
                                           R_CPG_CPG_CLKMON_OCTA_CLK0_MON_Pos,
                                           1U);
            }

            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_533 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_533_HZ >> 2;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_sel)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_400_HZ >> 2;
            }
            else
            {
                /* If this condition is met, clock_sel is an invalid value. */
                ;
            }

            uint32_t clock_div = (uint32_t) ((R_CPG_CPG_PL3A_DDIV_DIVPL3F_SET_Msk & R_CPG->CPG_PL3A_DDIV) >>
                                             R_CPG_CPG_PL3A_DDIV_DIVPL3F_SET_Pos);
            if (BSP_CLOCKS_PL3F_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div);

            /* Changing settings for the OC1 clock related register, OC0 clock frequency changes at the same time.
             * So it is updated the variable that stored OC0 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] = clock_freq << 1;
            break;
        }
#endif

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_sel);

            return FSP_ERR_INVALID_ARGUMENT;
            break;
        }
    }

    g_clock_freq[clock] = clock_freq;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set the Division Ratio Setting register to change the frequency.
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of each clock.
 * @param[in]   clock_div             Value to set in Division Ratio Setting register.
 **********************************************************************************************************************/
fsp_err_t bsp_prv_clock_divider_set (fsp_priv_clock_t clock, uint32_t clock_div)
{
    uint32_t clock_freq = g_clock_freq[clock];

    switch (clock)
    {
        /* Set the value to bit[1:0] the CPG_PL1_DDIV register. */
        case FSP_PRIV_CLOCK_ICLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL1_STS_Pos,
                                       0U);
            R_CPG->CPG_PL1_DDIV = (uint32_t) (R_CPG_CPG_PL1_DDIV_DIV_PLL1SET_WEN_Msk |
                                              (R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Msk &
                                               (clock_div << R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL1_STS_Pos,
                                       0U);
            clock_freq = BSP_CFG_CLOCK_PLL1_HZ >> clock_div;
            break;
        }

        /* Set the value to bit[10:8] the CPG_PL3A_DDIV register. */
        case FSP_PRIV_CLOCK_SPI0CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3C_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL3C_STS_Pos,
                                       0U);
            R_CPG->CPG_PL3A_DDIV = (uint32_t) (R_CPG_CPG_PL3A_DDIV_DIV_PLL3_C_WEN_Msk |
                                               (R_CPG_CPG_PL3A_DDIV_DIVPL3C_SET_Msk &
                                                (clock_div << R_CPG_CPG_PL3A_DDIV_DIVPL3C_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3C_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL3C_STS_Pos,
                                       0U);

            uint32_t clock_source = (R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_SET_Msk & R_CPG->CPG_PL3_SSEL) >>
                                    R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_SET_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_533 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_533_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_400_HZ;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            if (BSP_CLOCKS_PL3C_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 1);

            /* Changing settings for the SPI0 clock related register, SPI1 clock frequency changes at the same time.
             * So it is updated the variable that stored SPI1 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_SPI1CLK] = clock_freq >> 1;
            break;
        }

        /* Set the value to bit[10:8] the CPG_PL3A_DDIV register. */
        case FSP_PRIV_CLOCK_SPI1CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3C_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL3C_STS_Pos,
                                       0U);
            R_CPG->CPG_PL3A_DDIV = (uint32_t) (R_CPG_CPG_PL3A_DDIV_DIV_PLL3_C_WEN_Msk |
                                               (R_CPG_CPG_PL3A_DDIV_DIVPL3C_SET_Msk &
                                                (clock_div << R_CPG_CPG_PL3A_DDIV_DIVPL3C_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3C_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL3C_STS_Pos,
                                       0U);

            uint32_t clock_source = (R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_SET_Msk & R_CPG->CPG_PL3_SSEL) >>
                                    R_CPG_CPG_PL3_SSEL_SEL_PLL3_3_SET_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_533 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_533_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_400_HZ;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            if (BSP_CLOCKS_PL3C_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 2);

            /* Changing settings for the SPI1 clock related register, SPI0 clock frequency changes at the same time.
             * So it is updated the variable that stored SPI0 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_SPI0CLK] = clock_freq << 1;
            break;
        }

#if BSP_FEATURE_CPG_HAS_OC0CLK

        /* Set the value to bit[14:12] the CPG_PL3A_DDIV register. */
        case FSP_PRIV_CLOCK_OC0CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3F_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL3F_STS_Pos,
                                       0U);
            R_CPG->CPG_PL3A_DDIV = (uint32_t) (R_CPG_CPG_PL3A_DDIV_DIV_PL3F_WEN_Msk |
                                               (R_CPG_CPG_PL3A_DDIV_DIVPL3F_SET_Msk &
                                                (clock_div << R_CPG_CPG_PL3A_DDIV_DIVPL3F_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3F_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL3F_STS_Pos,
                                       0U);

            uint32_t clock_source = (R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_SET_Msk & R_CPG->CPG_PL3_SSEL) >>
                                    R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_SET_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_533 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_533_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_400_HZ;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            if (BSP_CLOCKS_PL3F_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 1);

            /* Changing settings for the OC0 clock related register, OC1 clock frequency changes at the same time.
             * So it is updated the variable that stored OC1 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_OC1CLK] = clock_freq >> 1;
            break;
        }
#endif

#if BSP_FEATURE_CPG_HAS_OC1CLK

        /* Set the value to bit[14:12] the CPG_PL3A_DDIV register. */
        case FSP_PRIV_CLOCK_OC1CLK:
        {
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3F_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL3F_STS_Pos,
                                       0U);
            R_CPG->CPG_PL3A_DDIV = (uint32_t) (R_CPG_CPG_PL3A_DDIV_DIV_PL3F_WEN_Msk |
                                               (R_CPG_CPG_PL3A_DDIV_DIVPL3F_SET_Msk &
                                                (clock_div << R_CPG_CPG_PL3A_DDIV_DIVPL3F_SET_Pos)));
            FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSTATUS_DIVPL3F_STS_Msk & R_CPG->CPG_CLKSTATUS) >>
                                       R_CPG_CPG_CLKSTATUS_DIVPL3F_STS_Pos,
                                       0U);

            uint32_t clock_source = (R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_SET_Msk & R_CPG->CPG_PL3_SSEL) >>
                                    R_CPG_CPG_PL3_SSEL_SEL_PLL3_5_SET_Pos;
            if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_533 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_533_HZ;
            }
            else if (BSP_CLOCKS_SOURCE_CLOCK_PLL3_400 == clock_source)
            {
                clock_freq = BSP_CFG_CLOCK_PLL3_400_HZ;
            }
            else
            {
                /* If this condition is met, prohibited value was set in the register. */
                ;
            }

            if (BSP_CLOCKS_PL3F_DIV_32 == clock_div)
            {
                clock_div++;
            }

            clock_freq = clock_freq >> (clock_div + 2);

            /* Changing settings for the OC1 clock related register, OC0 clock frequency changes at the same time.
             * So it is updated the variable that stored OC0 clock frequency. */
            g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] = clock_freq << 1;
            break;
        }
#endif

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_div);

            return FSP_ERR_INVALID_ARGUMENT;
            break;
        }
    }

    g_clock_freq[clock] = clock_freq;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Convert fsp_priv_clock_divider_t to fsp_priv_clock_t.
 *
 * @param[in]   divider                 Element number of the array that defines the clock divider.
 **********************************************************************************************************************/
static fsp_priv_clock_t bsp_prv_clock_convert_divider_to_clock (fsp_priv_clock_divider_t divider)
{
    fsp_priv_clock_t              ret = FSP_PRIV_CLOCK_NUM;
    static const fsp_priv_clock_t bsp_prv_clock_convert_divider_to_clock_tbl[] =
    {
        FSP_PRIV_CLOCK_ICLK,           /*  FSP_PRIV_CLOCK_DIVIDER_DIV_PLL1,            */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_LPCLK,       */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_A,          */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_A,          */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_B,          */
        FSP_PRIV_CLOCK_SPI0CLK,        /*  FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_C,          */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_CLK200FIX,  */
        FSP_PRIV_CLOCK_OC0CLK,         /*  FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_F,          */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_A,           */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_B,           */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_DIVIDER_DIV_GPU,             */
    };
    if (divider < FSP_PRIV_CLOCK_DIVIDER_NUM)
    {
        ret = bsp_prv_clock_convert_divider_to_clock_tbl[divider];
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Convert fsp_priv_clock_selector_t to fsp_priv_clock_t.
 *
 * @param[in]   selector                Element number of the array that defines the clock selector.
 **********************************************************************************************************************/
static fsp_priv_clock_t bsp_prv_clock_convert_selector_to_clock (fsp_priv_clock_selector_t selector)
{
    fsp_priv_clock_t              ret = FSP_PRIV_CLOCK_NUM;
    static const fsp_priv_clock_t bsp_prv_clock_convert_selector_to_clock_tbl[] =
    {
        FSP_PRIV_CLOCK_SD0CLK,         /*  FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI0,      */
        FSP_PRIV_CLOCK_SD1CLK,         /*  FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI1,      */
        FSP_PRIV_CLOCK_SPI0CLK,        /*  FSP_PRIV_CLOCK_SELECTOR_SEL_PLL3_3,     */
        FSP_PRIV_CLOCK_OC0CLK,         /*  FSP_PRIV_CLOCK_SELECTOR_SEL_PLL3_5,     */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_SELECTOR_SEL_PLL4,       */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_SELECTOR_SEL_PLL6_2,     */
        FSP_PRIV_CLOCK_NUM,            /*  FSP_PRIV_CLOCK_SELECTOR_SEL_PLL_GPU2,   */
    };
    if (selector < FSP_PRIV_CLOCK_SELECTOR_NUM)
    {
        ret = bsp_prv_clock_convert_selector_to_clock_tbl[selector];
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Check the PLL works or not
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of each clock.
 **********************************************************************************************************************/
static fsp_err_t bsp_prv_clock_check_pll (fsp_priv_clock_t clock)
{
    fsp_err_t err = FSP_SUCCESS;

    switch (clock)
    {
#if BSP_FEATURE_CPG_HAS_ICLK

        /* PLL1 */
        case FSP_PRIV_CLOCK_ICLK:
        {
            if (0 == (R_CPG->CPG_SAMPLL1_MON & R_CPG_CPG_SAMPLL1_MON_PLL1_LOCK_Msk))
            {
                err = FSP_ERR_PLL_SRC_INACTIVE;
            }

            break;
        }
#endif

        /* PLL2 */
#if BSP_FEATURE_CPG_HAS_SD0CLK
        case FSP_PRIV_CLOCK_SD0CLK:
#endif
#if BSP_FEATURE_CPG_HAS_SD1CLK
        case FSP_PRIV_CLOCK_SD1CLK:
#endif
#if BSP_FEATURE_CPG_HAS_P0CLK
        case FSP_PRIV_CLOCK_P0CLK:
#endif
        case FSP_PRIV_CLOCK_TSUCLK:
        {
            if (0 == (R_CPG->CPG_SIPLL2_MON & R_CPG_CPG_SIPLL2_MON_PLL2_LOCK_Msk))
            {
                err = FSP_ERR_PLL_SRC_INACTIVE;
            }

            break;
        }

        /* PLL3 */
        case FSP_PRIV_CLOCK_ATCLK:
#if BSP_FEATURE_CPG_HAS_I2CLK
        case FSP_PRIV_CLOCK_I2CLK:
#endif
#if BSP_FEATURE_CPG_HAS_P1CLK
        case FSP_PRIV_CLOCK_P1CLK:
#endif
        case FSP_PRIV_CLOCK_M0CLK:
        case FSP_PRIV_CLOCK_ZTCLK:
#if BSP_FEATURE_CPG_HAS_P2CLK
        case FSP_PRIV_CLOCK_P2CLK:
#endif
        case FSP_PRIV_CLOCK_SPI0CLK:
        case FSP_PRIV_CLOCK_SPI1CLK:
        case FSP_PRIV_CLOCK_M2CLK:
#if BSP_FEATURE_CPG_HAS_OC0CLK
        case FSP_PRIV_CLOCK_OC0CLK:
#endif
#if BSP_FEATURE_CPG_HAS_OC1CLK
        case FSP_PRIV_CLOCK_OC1CLK:
#endif
            {
                if (0 == (R_CPG->CPG_SIPLL3_MON & R_CPG_CPG_SIPLL3_MON_PLL3_LOCK_Msk))
                {
                    err = FSP_ERR_PLL_SRC_INACTIVE;
                }

                break;
            }

        /* PLL4 */
        case FSP_PRIV_CLOCK_S0CLK:
        {
            if (0 == (R_CPG->CPG_SAMPLL4_MON & R_CPG_CPG_SAMPLL4_MON_PLL4_LOCK_Msk))
            {
                err = FSP_ERR_PLL_SRC_INACTIVE;
            }

            break;
        }

#if BSP_FEATURE_CPG_HAS_M3CLK

        /* PLL5 */
        case FSP_PRIV_CLOCK_M3CLK:
        {
            if (0 == (R_CPG->CPG_SIPLL5_MON & R_CPG_CPG_SIPLL5_MON_PLL5_LOCK_Msk))
            {
                err = FSP_ERR_PLL_SRC_INACTIVE;
            }

            break;
        }
#endif

#if BSP_FEATURE_CPG_HAS_HPCLK

        /* PLL5 or PLL6 */
        case FSP_PRIV_CLOCK_HPCLK:
        {
            if (0 != (R_CPG->CPG_PL6_ETH_SSEL & R_CPG_CPG_PL6_ETH_SSEL_SEL_PLL6_2_SET_Msk))
            {
                /* PLL5 */
                if (0 == (R_CPG->CPG_SIPLL5_MON & R_CPG_CPG_SIPLL5_MON_PLL5_LOCK_Msk))
                {
                    err = FSP_ERR_PLL_SRC_INACTIVE;
                }
            }
            else
            {
                /* PLL6 */
                if (0 == (R_CPG->CPG_PLL6_MON & R_CPG_CPG_PLL6_MON_PLL6_LOCK_Msk))
                {
                    err = FSP_ERR_PLL_SRC_INACTIVE;
                }
            }

            break;
        }
#endif

        /* Other */
        default:
        {
            err = FSP_ERR_INVALID_ARGUMENT;
            break;
        }
    }

    return err;
}

/** @} (end addtogroup BSP_MCU_PRV) */

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Get a clock frequency.
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of each clock.
 *
 * @retval      g_clock_freq[clock]   Clock frequency.
 **********************************************************************************************************************/
uint32_t R_FSP_SystemClockHzGet (fsp_priv_clock_t clock)
{
    return g_clock_freq[clock];
}

/*******************************************************************************************************************//**
 * DEPRECATED: Set a clock frequency.
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of each clock.
 * @param[in]   clock_sel             Value to set in Source Clock Setting register.
 * @param[in]   clock_div             Value to set in Division Ratio Setting register.
 **********************************************************************************************************************/
void R_FSP_SystemClockHzSet (fsp_priv_clock_t clock, uint32_t clock_sel, uint32_t clock_div)
{
    bsp_prv_clock_pre_setting(clock);
    bsp_prv_clock_selector_set(clock, clock_sel);
    bsp_prv_clock_divider_set(clock, clock_div);
    bsp_prv_clock_post_setting(clock);
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
    fsp_err_t err = FSP_ERR_INVALID_ARGUMENT;

    fsp_priv_clock_t clock = bsp_prv_clock_convert_selector_to_clock(selector);
    if (clock != FSP_PRIV_CLOCK_NUM)
    {
        err = bsp_prv_clock_check_pll(clock);
        if (err == FSP_SUCCESS)
        {
            bsp_prv_clock_pre_setting(clock);
            err = bsp_prv_clock_selector_set(clock, clock_sel);
            bsp_prv_clock_post_setting(clock);
        }
    }

    return err;
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
    fsp_err_t        err   = FSP_ERR_INVALID_ARGUMENT;
    fsp_priv_clock_t clock = bsp_prv_clock_convert_divider_to_clock(divider);

    if (clock != FSP_PRIV_CLOCK_NUM)
    {
        err = bsp_prv_clock_check_pll(clock);
        if (err == FSP_SUCCESS)
        {
            bsp_prv_clock_pre_setting(clock);
            err = bsp_prv_clock_divider_set(clock, clock_div);
            bsp_prv_clock_post_setting(clock);
        }
    }

    return err;
}

/** @} (end addtogroup BSP_MCU_PRV) */
