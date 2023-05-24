/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <DA1469xAB.h>
#include <da1469x_config.h>
#include <da1469x_clock.h>
#include <da1469x_pd.h>
#include <da1469x_pdc.h>
#include <da1469x_otp.h>

#define XTAL32M_FREQ    32000000
#define RC32M_FREQ      32000000
#define PLL_FREQ        96000000
#define XTAL32K_FREQ       32768

static uint32_t g_mcu_clock_rcx_freq;
static uint32_t g_mcu_clock_rc32k_freq;
static uint32_t g_mcu_clock_rc32m_freq;

uint32_t SystemCoreClock = RC32M_FREQ;

/*
   OTPC is clocked by the system clock. Therefore, its timing settings
   should be adjusted upon system clock update.
 */
static inline void
da1469x_clock_adjust_otp_access_timings(void)
{
    /* Get the high-speed clock divider (AHB bus) */
    uint8_t hclk_div = (CRG_TOP->CLK_AMBA_REG & CRG_TOP_CLK_AMBA_REG_HCLK_DIV_Msk);

    /* Compute the actual core speed */
    uint32_t core_speed = (SystemCoreClock >> ((hclk_div < 4) ? hclk_div : 4/*1xx = divide by 16*/));

    da1469x_otp_set_speed(core_speed);
}

static inline bool
da1469x_clock_is_xtal32m_settled(void)
{
    return !!((CRG_XTAL->XTALRDY_STAT_REG & CRG_XTAL_XTALRDY_STAT_REG_XTALRDY_COUNT_Msk) == 0 &&
              (CRG_XTAL->XTAL32M_STAT1_REG & CRG_XTAL_XTAL32M_STAT1_REG_XTAL32M_STATE_Msk) == 0x8 /*XTAL_RUN state*/);
}

static inline bool
da1469x_clock_sys_pll_switch_check_restrictions(void)
{
    bool ret = 0;

    /* HDIV and PDIV should both be 0 */
    ret |= !((CRG_TOP->CLK_AMBA_REG & CRG_TOP_CLK_AMBA_REG_HCLK_DIV_Msk) == 0 &&
             (CRG_TOP->CLK_AMBA_REG & CRG_TOP_CLK_AMBA_REG_PCLK_DIV_Msk) == 0);


    /* Switch to PLL is only allowed when the current system clock is XTAL32M */
    ret |= !((CRG_TOP->CLK_CTRL_REG & CRG_TOP_CLK_CTRL_REG_RUNNING_AT_XTAL32M_Msk) ||
             (CRG_TOP->CLK_CTRL_REG & CRG_TOP_CLK_CTRL_REG_RUNNING_AT_PLL96M_Msk));

    /* 0 for success and 1 for failure. */
    return ret;
}

static inline bool
da1469x_clock_sys_xtal32m_switch_check_restrictions(void)
{
    bool ret = 0;

    /* XTAL32M should be enabled by PDC */
    ret |= !((CRG_TOP->POWER_CTRL_REG & CRG_TOP_POWER_CTRL_REG_LDO_RADIO_ENABLE_Msk) ||
             ((DCDC->DCDC_CTRL1_REG & DCDC_DCDC_CTRL1_REG_DCDC_ENABLE_Msk) &&
              (DCDC->DCDC_V14_REG & DCDC_DCDC_V14_REG_DCDC_V14_ENABLE_HV_Msk) &&
              (DCDC->DCDC_V14_REG & DCDC_DCDC_V14_REG_DCDC_V14_ENABLE_LV_Msk)));


    /* An attemp to switch to an unsteeled crystal might end up in hanging the system clock */
    ret |= !da1469x_clock_is_xtal32m_settled();

    /* 0 for success and 1 for failure. */
    return ret;
}

void
da1469x_clock_sys_xtal32m_init(void)
{
    uint32_t reg;
    int xtalrdy_cnt;

    /*
     * Number of 256kHz clock cycles (~4.085us) assuming worst case when actual frequency is 244800.
     * RC32M is in range <30.6, 32.6> so 256Khz can ba as low as 30.6MHz / 125 = 244.8kHz.
     */
    xtalrdy_cnt = 1000 * 1000 / 4085;

    reg = CRG_XTAL->XTALRDY_CTRL_REG;
    reg &= ~(CRG_XTAL_XTALRDY_CTRL_REG_XTALRDY_CNT_Msk);
    reg |= CRG_XTAL_XTALRDY_CTRL_REG_XTALRDY_CLK_SEL_Msk;
    reg |= xtalrdy_cnt;
    CRG_XTAL->XTALRDY_CTRL_REG = reg;
}

void
da1469x_clock_sys_xtal32m_enable(void)
{
    int idx;

    idx = da1469x_pdc_find(MCU_PDC_TRIGGER_SW_TRIGGER, MCU_PDC_MASTER_M33,
                           MCU_PDC_EN_XTAL);
    if (idx < 0) {
        idx = da1469x_pdc_add(MCU_PDC_TRIGGER_SW_TRIGGER, MCU_PDC_MASTER_M33,
                              MCU_PDC_EN_XTAL);
    }
    assert(idx >= 0);

    da1469x_pdc_set(idx);
    da1469x_pdc_ack(idx);

    /* PDC will now take care of XTAL32M. Make sure that PDC is able to turn it off when going to sleep */
    CRG_XTAL->XTAL32M_CTRL1_REG &= ~(CRG_XTAL_XTAL32M_CTRL1_REG_XTAL32M_XTAL_ENABLE_Msk);
}

void
da1469x_clock_sys_xtal32m_switch(void)
{
    if (CRG_TOP->CLK_CTRL_REG & CRG_TOP_CLK_CTRL_REG_RUNNING_AT_RC32M_Msk) {
        assert(da1469x_clock_sys_xtal32m_switch_check_restrictions() != 0);

        CRG_TOP->CLK_SWITCH2XTAL_REG = CRG_TOP_CLK_SWITCH2XTAL_REG_SWITCH2XTAL_Msk;
    } else {
        /* ~CLK_SEL_Msk == 0 means XTAL32M */
        CRG_TOP->CLK_CTRL_REG &= ~CRG_TOP_CLK_CTRL_REG_SYS_CLK_SEL_Msk;
    }

    while (!(CRG_TOP->CLK_CTRL_REG & CRG_TOP_CLK_CTRL_REG_RUNNING_AT_XTAL32M_Msk));

    SystemCoreClock = XTAL32M_FREQ;

    da1469x_clock_adjust_otp_access_timings();
}

void
da1469x_clock_sys_xtal32m_wait_to_settle(void)
{
    uint32_t primask;

    primask = DA1469X_IRQ_DISABLE();
    while (!da1469x_clock_is_xtal32m_settled()) {
        __WFE();
        __SEV();
        __WFE();
    }
    DA1469X_IRQ_ENABLE(primask);
}

void
da1469x_clock_sys_xtal32m_switch_safe(void)
{
    da1469x_clock_sys_xtal32m_wait_to_settle();

    da1469x_clock_sys_xtal32m_switch();
}

void
da1469x_clock_sys_rc32m_disable(void)
{
    CRG_TOP->CLK_RC32M_REG &= ~CRG_TOP_CLK_RC32M_REG_RC32M_ENABLE_Msk;
}

void
da1469x_clock_lp_xtal32k_enable(void)
{
    CRG_TOP->CLK_XTAL32K_REG |= CRG_TOP_CLK_XTAL32K_REG_XTAL32K_ENABLE_Msk;
}

void
da1469x_clock_lp_xtal32k_switch(void)
{
    CRG_TOP->CLK_CTRL_REG = (CRG_TOP->CLK_CTRL_REG &
                             ~CRG_TOP_CLK_CTRL_REG_LP_CLK_SEL_Msk) |
                            (2 << CRG_TOP_CLK_CTRL_REG_LP_CLK_SEL_Pos);
}

void
da1469x_clock_lp_rcx_enable(void)
{
    CRG_TOP->CLK_RCX_REG  |= CRG_TOP_CLK_RCX_REG_RCX_ENABLE_Msk;
}

void
da1469x_clock_lp_rcx_switch(void)
{
    CRG_TOP->CLK_CTRL_REG = (CRG_TOP->CLK_CTRL_REG &
                             ~CRG_TOP_CLK_CTRL_REG_LP_CLK_SEL_Msk) |
                            (1 << CRG_TOP_CLK_CTRL_REG_LP_CLK_SEL_Pos);
}

/**
 * Measure clock frequency
 *
 * @param clock_sel - clock to measure
 *                  0 - RC32K
 *                  1 - RC32M
 *                  2 - XTAL32K
 *                  3 - RCX
 *                  4 - RCOSC
 * @param ref_cnt - number of cycles used for measurement.
 * @return  clock frequency
 */
static uint32_t
da1469x_clock_calibrate(uint8_t clock_sel, uint16_t ref_cnt)
{
    uint32_t ref_val;

    da1469x_pd_acquire(MCU_PD_DOMAIN_PER);

    assert(CRG_TOP->CLK_CTRL_REG & CRG_TOP_CLK_CTRL_REG_RUNNING_AT_XTAL32M_Msk);
    assert(!(ANAMISC_BIF->CLK_REF_SEL_REG & ANAMISC_BIF_CLK_REF_SEL_REG_REF_CAL_START_Msk));

    ANAMISC_BIF->CLK_REF_CNT_REG = ref_cnt;
    ANAMISC_BIF->CLK_REF_SEL_REG = (clock_sel << ANAMISC_BIF_CLK_REF_SEL_REG_REF_CLK_SEL_Pos) |
                                   ANAMISC_BIF_CLK_REF_SEL_REG_REF_CAL_START_Msk;

    while (ANAMISC_BIF->CLK_REF_SEL_REG & ANAMISC_BIF_CLK_REF_SEL_REG_REF_CAL_START_Msk);

    ref_val = ANAMISC_BIF->CLK_REF_VAL_REG;

    da1469x_pd_release(MCU_PD_DOMAIN_PER);

    return 32000000 * ref_cnt / ref_val;
}

void
da1469x_clock_lp_rcx_calibrate(void)
{
    g_mcu_clock_rcx_freq = da1469x_clock_calibrate(3, MCU_RCX_CAL_REF_CNT);
}

void
da1469x_clock_lp_rc32k_calibrate(void)
{
    g_mcu_clock_rc32k_freq = da1469x_clock_calibrate(0, 100);
}

void
da1469x_clock_lp_rc32m_calibrate(void)
{
    g_mcu_clock_rc32m_freq = da1469x_clock_calibrate(1, 100);
}

uint32_t
da1469x_clock_lp_rcx_freq_get(void)
{
    assert(g_mcu_clock_rcx_freq);

    return g_mcu_clock_rcx_freq;
}

uint32_t
da1469x_clock_lp_rc32k_freq_get(void)
{
    assert(g_mcu_clock_rc32k_freq);

    return g_mcu_clock_rc32k_freq;
}

uint32_t
da1469x_clock_lp_rc32m_freq_get(void)
{
    assert(g_mcu_clock_rc32m_freq);

    return g_mcu_clock_rc32m_freq;
}

void
da1469x_clock_lp_rcx_disable(void)
{
    CRG_TOP->CLK_RCX_REG &= ~CRG_TOP_CLK_RCX_REG_RCX_ENABLE_Msk;
}

static void
da1469x_delay_us(uint32_t delay_us)
{
    /*
     * SysTick runs on ~32 MHz clock while PLL is not started.
     * so multiplying by 32 to convert from us to SysTicks.
     */
    SysTick->LOAD = delay_us * 32;
    SysTick->VAL = 0UL;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
    while (0 == (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
    SysTick->CTRL = 0;
}

/**
 * Enable PLL96
 */
void
da1469x_clock_sys_pll_enable(void)
{
    /* VDD voltage should be to 1.2V prior to enabling PLL (VDD_LEVEL_Msk means 1.2V) */
    assert((CRG_TOP->POWER_CTRL_REG & CRG_TOP_POWER_CTRL_REG_VDD_LEVEL_Msk)
                                        == CRG_TOP_POWER_CTRL_REG_VDD_LEVEL_Msk);

    /* Start PLL LDO if not done yet */
    if ((CRG_XTAL->PLL_SYS_STATUS_REG & CRG_XTAL_PLL_SYS_STATUS_REG_LDO_PLL_OK_Msk) == 0) {
        CRG_XTAL->PLL_SYS_CTRL1_REG |= CRG_XTAL_PLL_SYS_CTRL1_REG_LDO_PLL_ENABLE_Msk;
        /* Wait for XTAL LDO to settle */
        da1469x_delay_us(20);
    }
    if ((CRG_XTAL->PLL_SYS_STATUS_REG & CRG_XTAL_PLL_SYS_STATUS_REG_PLL_LOCK_FINE_Msk) == 0) {
        /* Enables DXTAL for the system PLL */
        CRG_XTAL->XTAL32M_CTRL0_REG |= CRG_XTAL_XTAL32M_CTRL0_REG_XTAL32M_DXTAL_SYSPLL_ENABLE_Msk;
        /* Use internal VCO current setting to enable precharge */
        CRG_XTAL->PLL_SYS_CTRL1_REG |= CRG_XTAL_PLL_SYS_CTRL1_REG_PLL_SEL_MIN_CUR_INT_Msk;
        /* Enable precharge */
        CRG_XTAL->PLL_SYS_CTRL2_REG |= CRG_XTAL_PLL_SYS_CTRL2_REG_PLL_RECALIB_Msk;
        /* Start the SYSPLL */
        CRG_XTAL->PLL_SYS_CTRL1_REG |= CRG_XTAL_PLL_SYS_CTRL1_REG_PLL_EN_Msk;
        /* Precharge loopfilter (Vtune) */
        da1469x_delay_us(10);
        /* Disable precharge */
        CRG_XTAL->PLL_SYS_CTRL2_REG &= ~CRG_XTAL_PLL_SYS_CTRL2_REG_PLL_RECALIB_Msk;
        /* Extra wait time */
        da1469x_delay_us(5);
        /* Take external VCO current setting */
        CRG_XTAL->PLL_SYS_CTRL1_REG &= ~CRG_XTAL_PLL_SYS_CTRL1_REG_PLL_SEL_MIN_CUR_INT_Msk;
    }
}

void
da1469x_clock_sys_pll_disable(void)
{
    /* Switch from PLL is only allowed when the new system clock is XTAL32M */
    da1469x_clock_sys_xtal32m_switch();

    CRG_XTAL->PLL_SYS_CTRL1_REG &= ~(CRG_XTAL_PLL_SYS_CTRL1_REG_PLL_EN_Msk |
                                     CRG_XTAL_PLL_SYS_CTRL1_REG_LDO_PLL_ENABLE_Msk);

    CRG_XTAL->XTAL32M_CTRL0_REG &= ~(CRG_XTAL_XTAL32M_CTRL0_REG_XTAL32M_DXTAL_SYSPLL_ENABLE_Msk);
}

void
da1469x_clock_pll_wait_to_lock(void)
{
    uint32_t primask;

    primask = DA1469X_IRQ_DISABLE();

    NVIC_ClearPendingIRQ(PLL_LOCK_IRQn);

    if (!da1469x_clock_is_pll_locked()) {
        NVIC_EnableIRQ(PLL_LOCK_IRQn);
        while (!NVIC_GetPendingIRQ(PLL_LOCK_IRQn)) {
            __WFI();
        }
        NVIC_DisableIRQ(PLL_LOCK_IRQn);

        /*
         * Due to a metastability issue, the PLL lock interrupt may be fired earlier
         * and before the PLL is actually locked. Therefore, an attempt to switch to
         * an unlocked PLL might end up hanging the system clock.
         * Make sure that PLL is locked by polling the corresponding status register
         * as the actual time interval between two successive PLL lock interrupts is
         *  uncertain.
         */
       while (!da1469x_clock_is_pll_locked());
    }

    DA1469X_IRQ_ENABLE(primask);
}

void
da1469x_clock_sys_pll_switch(void)
{
    assert(da1469x_clock_sys_pll_switch_check_restrictions() != 0);

    /* CLK_SEL_Msk == 3 means PLL */
    CRG_TOP->CLK_CTRL_REG |= CRG_TOP_CLK_CTRL_REG_SYS_CLK_SEL_Msk;

    while (!(CRG_TOP->CLK_CTRL_REG & CRG_TOP_CLK_CTRL_REG_RUNNING_AT_PLL96M_Msk));

    SystemCoreClock = PLL_FREQ;

    da1469x_clock_adjust_otp_access_timings();
}
