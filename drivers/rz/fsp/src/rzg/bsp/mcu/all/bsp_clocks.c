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
static void bsp_prv_clock_pre_setting(fsp_priv_clock_t clock);
static void bsp_prv_clock_post_setting(fsp_priv_clock_t clock);
void        bsp_prv_clock_selector_set(fsp_priv_clock_t clock, uint32_t clock_sel);
void        bsp_prv_clock_divider_set(fsp_priv_clock_t clock, uint32_t clock_div);

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
    SystemCoreClock = g_clock_freq[FSP_PRIV_CLOCK_I2CLK];
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
#if defined(BSP_CFG_CLOCK_I2CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I2CLK] = BSP_CFG_CLOCK_I2CLK_HZ;
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
#if defined(BSP_CFG_CLOCK_ATCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_ATCLK] = BSP_CFG_CLOCK_ATCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_OSCCLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_OSCCLK] = BSP_CFG_CLOCK_OSCCLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_I3CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_I3CLK] = BSP_CFG_CLOCK_I3CLK_HZ;
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
#if defined(BSP_CFG_CLOCK_SD2CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_SD2CLK] = BSP_CFG_CLOCK_SD2CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_OC0CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_OC0CLK] = BSP_CFG_CLOCK_OC0CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_OC1CLK_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_OC1CLK] = BSP_CFG_CLOCK_OC1CLK_HZ;
#endif
#if defined(BSP_CFG_CLOCK_OSCCLK2_HZ)
    g_clock_freq[FSP_PRIV_CLOCK_OSCCLK2] = BSP_CFG_CLOCK_OSCCLK2_HZ;
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
    uint32_t setting_value = 0;

    /* Set CPG_PL1_DDIV to configure the frequency of ICLK. */
    setting_value = (uint32_t) (BSP_CFG_DIVPL1_SET_DIV << R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Pos);
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
    R_CPG->CPG_PL1_DDIV =
        (uint32_t) (R_CPG_CPG_PL1_DDIV_DIV_PLL1SET_WEN_Msk | (R_CPG_CPG_PL1_DDIV_DIVPL1_SET_Msk & setting_value));
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL1_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

    /* Set CPG_PL2_DDIV to configure the frequency of P0CLK. */
    setting_value = (uint32_t) (BSP_CFG_DIVPL2B_SET_DIV << R_CPG_CPG_PL2_DDIV_DIVPL2B_SET_Pos);
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL2B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);
    R_CPG->CPG_PL2_DDIV =
        (uint32_t) (R_CPG_CPG_PL2_DDIV_DIV_PLL2_B_WEN_Msk | (R_CPG_CPG_PL2_DDIV_DIVPL2B_SET_Msk & setting_value));
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKDIVSTATUS_DIVPL2B_STS_Msk & R_CPG->CPG_CLKDIVSTATUS), 0U);

    /* Set CPG_PL3_DDIV to configure the frequency of P1CLK, P2CLK and P3CLK. */
    setting_value = (uint32_t) ((BSP_CFG_DIVPL3A_SET_DIV << R_CPG_CPG_PL3_DDIV_DIVPL3A_SET_Pos) |
                                (BSP_CFG_DIVPL3B_SET_DIV << R_CPG_CPG_PL3_DDIV_DIVPL3B_SET_Pos) |
                                (BSP_CFG_DIVPL3C_SET_DIV << R_CPG_CPG_PL3_DDIV_DIVPL3C_SET_Pos));
    FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKDIVSTATUS_DIVPL3A_STS_Msk | R_CPG_CPG_CLKDIVSTATUS_DIVPL3B_STS_Msk |
                                 R_CPG_CPG_CLKDIVSTATUS_DIVPL3C_STS_Msk) &
                                R_CPG->CPG_CLKDIVSTATUS),
                               0U);
    R_CPG->CPG_PL3_DDIV =
        (uint32_t) ((R_CPG_CPG_PL3_DDIV_DIV_PLL3_A_WEN_Msk | R_CPG_CPG_PL3_DDIV_DIV_PLL3_B_WEN_Msk |
                     R_CPG_CPG_PL3_DDIV_DIV_PLL3_C_WEN_Msk) |
                    ((R_CPG_CPG_PL3_DDIV_DIVPL3A_SET_Msk | R_CPG_CPG_PL3_DDIV_DIVPL3B_SET_Msk |
                      R_CPG_CPG_PL3_DDIV_DIVPL3C_SET_Msk) &
                     setting_value));
    FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKDIVSTATUS_DIVPL3A_STS_Msk | R_CPG_CPG_CLKDIVSTATUS_DIVPL3B_STS_Msk |
                                 R_CPG_CPG_CLKDIVSTATUS_DIVPL3C_STS_Msk) &
                                R_CPG->CPG_CLKDIVSTATUS),
                               0U);

    /* Set CPG_PL6_DDIV to configure the frequency of I2CLK and I3CLK. */
    setting_value = (uint32_t) ((BSP_CFG_DIVPL6A_SET_DIV << R_CPG_CPG_PL6_DDIV_DIVPL6A_SET_Pos) |
                                (BSP_CFG_DIVPL6B_SET_DIV << R_CPG_CPG_PL6_DDIV_DIVPL6B_SET_Pos));
    FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKDIVSTATUS_DIVPL6A_STS_Msk | R_CPG_CPG_CLKDIVSTATUS_DIVPL6B_STS_Msk) &
                                R_CPG->CPG_CLKDIVSTATUS),
                               0U);
    R_CPG->CPG_PL6_DDIV =
        (uint32_t) ((R_CPG_CPG_PL6_DDIV_DIV_PLL6_A_WEN_Msk | R_CPG_CPG_PL6_DDIV_DIV_PLL6_B_WEN_Msk) |
                    ((R_CPG_CPG_PL6_DDIV_DIVPL6A_SET_Msk | R_CPG_CPG_PL6_DDIV_DIVPL6B_SET_Msk) &
                     setting_value));
    FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKDIVSTATUS_DIVPL6A_STS_Msk | R_CPG_CPG_CLKDIVSTATUS_DIVPL6B_STS_Msk) &
                                R_CPG->CPG_CLKDIVSTATUS),
                               0U);

    /* Set CPG_SDHI_DDIV and CPG_SDHI_DSEL to configure the frequency of SD0CLK, SD1CLK and SD2CLK. */
    setting_value = (uint32_t) ((BSP_CFG_DIVSDHI0_SET_DIV << R_CPG_CPG_SDHI_DDIV_DIVSDHI0_SET_Pos) |
                                (BSP_CFG_DIVSDHI1_SET_DIV << R_CPG_CPG_SDHI_DDIV_DIVSDHI1_SET_Pos) |
                                (BSP_CFG_DIVSDHI2_SET_DIV << R_CPG_CPG_SDHI_DDIV_DIVSDHI2_SET_Pos));
    FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKDIVSTATUS_DIVSDHI0_STS_Msk | R_CPG_CPG_CLKDIVSTATUS_DIVSDHI1_STS_Msk |
                                 R_CPG_CPG_CLKDIVSTATUS_DIVSDHI2_STS_Msk) &
                                R_CPG->CPG_CLKDIVSTATUS),
                               0U);
    R_CPG->CPG_SDHI_DDIV =
        (uint32_t) ((R_CPG_CPG_SDHI_DDIV_DIVSDHI0_WEN_Msk | R_CPG_CPG_SDHI_DDIV_DIVSDHI1_WEN_Msk |
                     R_CPG_CPG_SDHI_DDIV_DIVSDHI2_WEN_Msk) |
                    ((R_CPG_CPG_SDHI_DDIV_DIVSDHI0_SET_Msk | R_CPG_CPG_SDHI_DDIV_DIVSDHI1_SET_Msk |
                      R_CPG_CPG_SDHI_DDIV_DIVSDHI2_SET_Msk) &
                     setting_value));
    FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKDIVSTATUS_DIVSDHI0_STS_Msk | R_CPG_CPG_CLKDIVSTATUS_DIVSDHI1_STS_Msk |
                                 R_CPG_CPG_CLKDIVSTATUS_DIVSDHI2_STS_Msk) &
                                R_CPG->CPG_CLKDIVSTATUS),
                               0U);

    setting_value = (uint32_t) ((BSP_CFG_SEL_SDHI0_SET_SOURCE << R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Pos) |
                                (BSP_CFG_SEL_SDHI1_SET_SOURCE << R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Pos) |
                                (BSP_CFG_SEL_SDHI2_SET_SOURCE << R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Pos));
    FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKSELSTATUS_SELSDHI0_STS_Msk | R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Msk |
                                 R_CPG_CPG_CLKSELSTATUS_SELSDHI2_STS_Msk) &
                                R_CPG->CPG_CLKSELSTATUS),
                               0U);
    R_CPG->CPG_SDHI_DSEL =
        (uint32_t) ((R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_WEN_Msk | R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_WEN_Msk |
                     R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_WEN_Msk) |
                    ((R_CPG_CPG_SDHI_DSEL_SEL_SDHI0_SET_Msk | R_CPG_CPG_SDHI_DSEL_SEL_SDHI1_SET_Msk |
                      R_CPG_CPG_SDHI_DSEL_SEL_SDHI2_SET_Msk) &
                     setting_value));
    FSP_HARDWARE_REGISTER_WAIT(((R_CPG_CPG_CLKSELSTATUS_SELSDHI0_STS_Msk | R_CPG_CPG_CLKSELSTATUS_SELSDHI1_STS_Msk |
                                 R_CPG_CPG_CLKSELSTATUS_SELSDHI2_STS_Msk) &
                                R_CPG->CPG_CLKSELSTATUS),
                               0U);

    /* Set CPG_PLL_DSEL to configure the frequency of S0CLK. */
    setting_value = (uint32_t) (BSP_CFG_SELPL4_SET_SOURCE << R_CPG_CPG_PLL_DSEL_SELPL4_SET_Pos);
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELPL4_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
    R_CPG->CPG_PLL_DSEL =
        (uint32_t) (R_CPG_CPG_PLL_DSEL_SELPL4_WEN_Msk | (R_CPG_CPG_PLL_DSEL_SELPL4_SET_Msk & setting_value));
    FSP_HARDWARE_REGISTER_WAIT((R_CPG_CPG_CLKSELSTATUS_SELPL4_STS_Msk & R_CPG->CPG_CLKSELSTATUS), 0U);
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
void bsp_prv_clock_selector_set (fsp_priv_clock_t clock, uint32_t clock_sel)
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
#endif                                 /* BSP_CFG_SEL_SDHI0_SET_SOURCE */

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
#endif                                 /* BSP_CFG_SEL_SDHI1_SET_SOURCE */

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
#endif                                 /* BSP_CFG_SEL_SDHI2_SET_SOURCE */

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
#endif                                 /* BSP_CFG_SELSPI_SET_SOURCE */

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
#endif                                 /* BSP_CFG_SELOCTA_SET_SOURCE */

        default:
        {
            FSP_PARAMETER_NOT_USED(clock_sel);
            break;
        }
    }

    g_clock_freq[clock] = clock_freq;
}

/*******************************************************************************************************************//**
 * Set the Division Ratio Setting register to change the frequency.
 *
 * @param[in]   clock                 Element number of the array that defines the frequency of each clock.
 * @param[in]   clock_div             Value to set in Division Ratio Setting register.
 **********************************************************************************************************************/
void bsp_prv_clock_divider_set (fsp_priv_clock_t clock, uint32_t clock_div)
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
 * Set a clock frequency.
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

/** @} (end addtogroup BSP_MCU) */
