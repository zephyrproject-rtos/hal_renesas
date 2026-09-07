/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "../all/bsp_clocks.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_IDX_DIGITAL    0
#define XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_IDX_USBPLL     3
#define XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_IDX_SYSPLL     4

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

#if BSP_CLOCK_CFG_MAIN_OSC_POPULATED

void bsp_clock_xtalm_enable (bool enable)
{
    if (enable)
    {
        /* Use manual procedure for enabling XTAL32M. */
        /* 0. XTAL_WAIT_FOR_LDO = 0: */
        /* 1. Set LDOXTAL_EN and EN_XTAL_BIAS */
        /* 2. Min delay of 5us to allow the bias circuit to settle. */
        /* 3. Continue even if XTAL_LDO_OK is still 0. */
        /* 4. Enable the oscillator by setting the EN_XTAL_OSC. */

        XTAL32M->XTAL32M_OSC_REG_b.XTAL_WAIT_FOR_LDO = 0;

        XTAL32M->XTAL32M_SET_ENABLE_REG = XTAL32M_XTAL32M_ENABLE_REG_LDOXTAL_EN_Msk |
                                          XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_BIAS_Msk |
                                          (((1 << XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_IDX_DIGITAL) <<
                                            XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Pos) &
                                           XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Msk);

        for (uint32_t i = 0; i < 80; i++)
        {
            if (XTAL32M->XTAL32M_STATUS_REG_b.XTAL_LDO_OK == 1)
            {
                break;
            }
        }

        XTAL32M->XTAL32M_SET_ENABLE_REG = XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_OSC_Msk;
    }
    else
    {
        XTAL32M->XTAL32M_RESET_ENABLE_REG = XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_OSC_Msk |
                                            XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_BIAS_Msk |
                                            XTAL32M_XTAL32M_ENABLE_REG_LDOXTAL_EN_Msk;
    }
}

void bsp_clock_xtalm_64m_output_enable (bool enable)
{
    XTAL32M->XTAL32M_ENABLE_REG_b.EN_XTAL_CLK_64MHZ = enable;
}

bool bsp_clock_xtalm_64m_output_is_enabled (void)
{
    return XTAL32M->XTAL32M_ENABLE_REG_b.EN_XTAL_CLK_64MHZ;
}

/*******************************************************************************************************************//**
 * Checks if the main oscillator (XTALM) has settled.
 *
 * @return  true if XTALM has settled, false if it hasn't.
 **********************************************************************************************************************/
bool bsp_clock_xtalm_is_settled (void)
{
    return XTAL32M->XTAL32M_STATUS_REG_b.XTAL_OSC_OK;
}

/***********************************************************************************************************************
 * Configures the XTAL32M clock
 **********************************************************************************************************************/
void bsp_clock_xtalm_configure (void)
{
    // Placeholder for possible configuration actions that should be done at startup
}

fsp_err_t bsp_clock_xtalm_preconditions_check (void)
{
    FSP_ERROR_RETURN((1 == PMU_ANA->POWER_CTRL_REG_b.LDO_ANA_ENABLE) &&
                     (0 != PMU_ANA->POWER_CTRL_REG_b.V10_ENABLE),
                     FSP_ERR_INVALID_HW_CONDITION);

    return FSP_SUCCESS;
}

#endif                                 /* BSP_CLOCK_CFG_MAIN_OSC_POPULATED */

#if BSP_FEATURE_CGC_HAS_SOSC
 #if BSP_CLOCK_CFG_SUBCLOCK_POPULATED

/***********************************************************************************************************************
 * Configures the XTAL32K clock. This must be done only once, since the register is retained.
 **********************************************************************************************************************/
void bsp_clock_xtalk_configure (void)
{
    // Placeholder for possible actions needed at startup for Xtalk configuration
}

 #endif                                /* BSP_CLOCK_CFG_SUBCLOCK_POPULATED */
#endif                                 /* BSP_FEATURE_CGC_HAS_SOSC */

#if BSP_PRV_PLL_SUPPORTED
void bsp_clock_pll_enable (bool enable)
{
    if (enable)
    {
        /* Enable the corresponding clock buffer to give 32MHz clock to PLLSYS*/
        XTAL32M->XTAL32M_SET_ENABLE_REG =
            ((1 << XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_IDX_SYSPLL) <<
                XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Pos) & XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Msk;
        PLLSYS->PLL_CFG1_REG_b.ENABLE_PLL = 1;
    }
    else
    {
        XTAL32M->XTAL32M_RESET_ENABLE_REG =
            ((1 << XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_IDX_SYSPLL) <<
                XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Pos) & XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Msk;
        PLLSYS->PLL_CFG1_REG_b.ENABLE_PLL = 0;
    }
}

void bsp_clock_usbpll_enable (bool enable)
{
    if (enable)
    {
        /* Enable the corresponding clock buffer to give 32MHz clock to PLLUSB. */
        XTAL32M->XTAL32M_SET_ENABLE_REG =
            ((1 << XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_IDX_USBPLL) <<
                XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Pos) & XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Msk;
        PLLUSB->PLLUSB_CFG1_REG_b.SEL_PLL_AUTO_ISCALE = 1;
        PLLUSB->PLLUSB_CFG1_REG_b.ENABLE_PLL          = 1;
    }
    else
    {
        XTAL32M->XTAL32M_RESET_ENABLE_REG =
            ((1 << XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_IDX_USBPLL) <<
                XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Pos) & XTAL32M_XTAL32M_ENABLE_REG_EN_XTAL_CLK_BUFFER_Msk;
        PLLUSB->PLLUSB_CFG1_REG_b.ENABLE_PLL = 0;
    }
}

bool bsp_clock_pll_is_enabled (void)
{
    return PLLSYS->PLL_CFG1_REG_b.ENABLE_PLL;
}

bool bsp_clock_pll_is_locked (void)
{
    return PLLSYS->PLL_STATUS_REG_b.PLL_PLL_OK;
}

bool bsp_clock_usbpll_is_locked (void)
{
    return PLLUSB->PLLUSB_STATUS_REG_b.PLL_PLL_OK;
}

fsp_err_t bsp_clock_pll_preconditions_check (void)
{
    FSP_ERROR_RETURN((PMU_ANA->POWER_CTRL_REG_b.LDO_ANA_ENABLE == 1) &&
                     (PMU_ANA->POWER_CTRL_REG_b.V18_ENABLE != 0) &&
                     (PMU_ANA->POWER_CTRL_REG_b.V10_ENABLE != 0)
                     ,
                     FSP_ERR_INVALID_HW_CONDITION);

    return FSP_SUCCESS;
}

#endif                                 /* BSP_PRV_PLL_SUPPORTED */

fsp_err_t bsp_clock_rchs_high_speed_preconditions_check (void)
{
    uint32_t vdd_level = PMU_ANA->POWER_LEVEL_REG_b.VDD_LEVEL_ACTIVE;
    FSP_ERROR_RETURN((0xC == vdd_level) || (0xD == vdd_level), FSP_ERR_INVALID_HW_CONDITION);

    return FSP_SUCCESS;
}

uint32_t bsp_clock_measurement (bsp_clock_msr_sel_t target, bsp_clock_msr_sel_t ref, uint32_t cycles)
{
    uint32_t                msr_freq           = 0;
    uint32_t                ref_freq           = 0;
    fsp_priv_source_clock_t source_clock_lut[] =
    {
        [BSP_CLOCK_MSR_SEL_RCLP]     = FSP_PRIV_CLOCK_RCLP,
        [BSP_CLOCK_MSR_SEL_RCHS]     = FSP_PRIV_CLOCK_RCHS,
        [BSP_CLOCK_MSR_SEL_RCX]      = FSP_PRIV_CLOCK_RCX,
        [BSP_CLOCK_MSR_SEL_XTAL32K]  = FSP_PRIV_CLOCK_XTALK,
        [BSP_CLOCK_MSR_SEL_XTAL32M]  = FSP_PRIV_CLOCK_XTALM,
        [BSP_CLOCK_MSR_SEL_XTAL64M]  = FSP_PRIV_CLOCK_XTALM_DBLR,
        [BSP_CLOCK_MSR_SEL_EXTERNAL] = FSP_PRIV_CLOCK_DIGITAL,
    };

    if (BSP_CLOCK_MSR_SEL_DIVN == ref)
    {
        ref_freq = BSP_DIVN_FREQ_HZ;
    }
    else
    {
        ref_freq = R_BSP_SourceClockHzGet(source_clock_lut[ref]);
    }

    bsp_clock_measurement_configure(target, ref, cycles);
    bsp_clock_measurement_start();

    while (0 != ANAMISC->CLK_REF_SEL_REG_b.REF_CAL_START)
    {
        __NOP();
    }

    msr_freq = (ref_freq * cycles) / bsp_clock_measurement_read();

    return msr_freq;
}

void bsp_clock_measurement_configure (bsp_clock_msr_sel_t target, bsp_clock_msr_sel_t ref, uint32_t cycles)
{
    ANAMISC->CLK_REF_CNT_REG = cycles;

    uint32_t meas_clock;
    uint32_t ref_clock;

    meas_clock = (target << ANAMISC_CLK_REF_SEL_REG_REF_CLK_SEL_Pos) & ANAMISC_CLK_REF_SEL_REG_REF_CLK_SEL_Msk;
    ref_clock  = (ref << ANAMISC_CLK_REF_SEL_REG_CAL_CLK_SEL_Pos) & ANAMISC_CLK_REF_SEL_REG_CAL_CLK_SEL_Msk;

    ANAMISC->CLK_REF_SEL_REG = meas_clock | ref_clock;
}

/** @} (end addtogroup BSP_MCU_PRV) */
