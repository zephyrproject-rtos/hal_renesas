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
#include <da1469x_trimv.h>

#define XTAL32M_FREQ    32000000
#define RC32M_FREQ      32000000
#define PLL_FREQ        96000000
#define XTAL32K_FREQ       32768

#define ARRAY_COUNT(_arr)  (sizeof(_arr) / sizeof(_arr[0]))

static uint32_t g_mcu_clock_rcx_freq;
static uint32_t g_mcu_clock_rc32k_freq;
static uint32_t g_mcu_clock_rc32m_freq;

uint32_t SystemCoreClock = RC32M_FREQ;

enum {
    XTALRDY_CLK_SEL_32KHz = 0x0,
    XTALRDY_CLK_SEL_256KHz
} XTALRDY_CLK_SEL;

#define CLK_FREQ_TRIM_REG_SET(_field, _val) \
    CRG_XTAL->CLK_FREQ_TRIM_REG = \
    ((CRG_XTAL->CLK_FREQ_TRIM_REG & ~CRG_XTAL_CLK_FREQ_TRIM_REG_ ## _field ## _Msk) | \
    (((_val) << CRG_XTAL_CLK_FREQ_TRIM_REG_ ## _field ## _Pos) & \
    CRG_XTAL_CLK_FREQ_TRIM_REG_ ## _field ## _Msk))

#define CLK_FREQ_TRIM_REG_GET(_field) \
    ((CRG_XTAL->CLK_FREQ_TRIM_REG & CRG_XTAL_CLK_FREQ_TRIM_REG_ ## _field ## _Msk) >> \
    CRG_XTAL_CLK_FREQ_TRIM_REG_ ## _field ## _Pos)

#define XTAL32M_CTRL2_REG_SET(_field, _val) \
    CRG_XTAL->XTAL32M_CTRL2_REG = \
    ((CRG_XTAL->XTAL32M_CTRL2_REG & ~CRG_XTAL_XTAL32M_CTRL2_REG_ ## _field ## _Msk) | \
    (((_val) << CRG_XTAL_XTAL32M_CTRL2_REG_ ## _field ## _Pos) & \
    CRG_XTAL_XTAL32M_CTRL2_REG_ ## _field ## _Msk))

#define XTAL32M_CTRL2_REG_GET(_field) \
    ((CRG_XTAL->XTAL32M_CTRL2_REG & CRG_XTAL_XTAL32M_CTRL2_REG_ ## _field ## _Msk) >> \
    CRG_XTAL_XTAL32M_CTRL2_REG_ ## _field ## _Pos)

#define XTALRDY_CTRL_REG_SET(_field, _val) \
    CRG_XTAL->XTALRDY_CTRL_REG = \
    ((CRG_XTAL->XTALRDY_CTRL_REG & ~CRG_XTAL_XTALRDY_CTRL_REG_ ## _field ## _Msk) | \
    (((_val) << CRG_XTAL_XTALRDY_CTRL_REG_ ## _field ## _Pos) &  \
    CRG_XTAL_XTALRDY_CTRL_REG_ ## _field ## _Msk))

#define XTALRDY_CTRL_REG_GET(_field) \
    ((CRG_XTAL->XTALRDY_CTRL_REG & CRG_XTAL_XTALRDY_CTRL_REG_ ## _field ## _Msk) >> \
    CRG_XTAL_XTALRDY_CTRL_REG_ ## _field ## _Pos)

#define XTALRDY_STAT_REG_GET(_field) \
    ((CRG_XTAL->XTALRDY_STAT_REG & CRG_XTAL_XTALRDY_STAT_REG_ ## _field ## _Msk) >> \
    CRG_XTAL_XTALRDY_STAT_REG_ ## _field ## _Pos)

#define COM_DEV_CHECK_DIV1_CLK(_val, _dev)   ((_val) & CRG_COM_CLK_COM_REG_ ## _dev ## _CLK_SEL_Msk) && \
                                             ((_val) & CRG_COM_CLK_COM_REG_ ## _dev ## _ENABLE_Msk)

#define SYS_DEV_CHECK_DIV1_CLK(_val, _dev)   ((_val) & CRG_SYS_CLK_SYS_REG_ ## _dev ## _CLK_SEL_Msk) && \
                                             ((_val) & CRG_SYS_CLK_SYS_REG_ ## _dev ## _ENABLE_Msk)


bool
da1469x_clock_check_device_div1_clock(void)
{
    uint32_t sys_stat_reg = CRG_TOP->SYS_STAT_REG;

    /*
     * Exercisie if any block instance powered by PD_COM is enabled
     * and clocked by DIV1 path (reflects the system clock);
     */
    if (sys_stat_reg & CRG_TOP_SYS_STAT_REG_COM_IS_UP_Msk) {
        uint32_t clk_com_reg = CRG_COM->CLK_COM_REG;

        if (COM_DEV_CHECK_DIV1_CLK(clk_com_reg, I2C)) {
            return true;
        }

        if (COM_DEV_CHECK_DIV1_CLK(clk_com_reg, I2C2)) {
            return true;
        }

        if (COM_DEV_CHECK_DIV1_CLK(clk_com_reg, SPI)){
            return true;
        }

        if (COM_DEV_CHECK_DIV1_CLK(clk_com_reg, SPI2)) {
            return true;
        }

        if (COM_DEV_CHECK_DIV1_CLK(clk_com_reg, UART2)) {
            return true;
        }

        if (COM_DEV_CHECK_DIV1_CLK(clk_com_reg, UART3)) {
            return true;
        }
    }

    /*
     * Check if GPADC, which is powered by PD_PER, is enabled and
     * clocked by DIV1 path.
     */
    if (sys_stat_reg & CRG_TOP_SYS_STAT_REG_PER_IS_UP_Msk) {
        if ((CRG_PER->CLK_PER_REG & CRG_PER_CLK_PER_REG_GPADC_CLK_SEL_Msk) &&
            (GPADC->GP_ADC_CTRL_REG & GPADC_GP_ADC_CTRL_REG_GP_ADC_EN_Msk)) {
                return true;
            }
    }

    /* Exercise if LCDC is enabled and clocked by DIV1 path */
    if (SYS_DEV_CHECK_DIV1_CLK(CRG_SYS-> CLK_SYS_REG, LCD)) {
        return true;
    }

    return false;
}

/*
 * OTPC is clocked by the system clock. Therefore, its timing settings
 * should be adjusted upon system clock update.
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

static void
da1469x_clock_sys_xtal32m_configure(void)
{
    assert(CRG_TOP->SYS_STAT_REG & CRG_TOP_SYS_STAT_REG_TIM_IS_UP_Msk);

    /* Apply optimum values for XTAL32M registers not defined in CS section in OTP */
    static uint32_t regs_buf[] = {
        (uint32_t)&CRG_XTAL->CLK_FREQ_TRIM_REG
    };

    bool status_buf[ARRAY_COUNT(regs_buf)];

    da1469x_trimv_is_reg_pairs_in_otp(regs_buf, ARRAY_COUNT(regs_buf), status_buf);

    if (!status_buf[0]) {
        CLK_FREQ_TRIM_REG_SET(XTAL32M_TRIM, CLK_FREQ_TRIM_REG__XTAL32M_TRIM__DEFAULT);
    }

    /* Configure OSF BOOST */
    uint8_t cxcomp_phi_trim = 0;
    uint8_t cxcomp_trim_cap = XTAL32M_CTRL2_REG_GET(XTAL32M_CXCOMP_TRIM_CAP);

    if (cxcomp_trim_cap < 37) {
        cxcomp_phi_trim = 3;
    } else {
        if (cxcomp_trim_cap < 123) {
            cxcomp_phi_trim = 2;
        }
        else {
            if (cxcomp_trim_cap < 170) {
                cxcomp_phi_trim = 1;
            }
            else {
                cxcomp_phi_trim = 0;
            }
        }
    }
    XTAL32M_CTRL2_REG_SET(XTAL32M_CXCOMP_PHI_TRIM, cxcomp_phi_trim);
}

static void
da1469x_clock_sys_xtal32m_rdy_cnt_finetune(void)
{
#define XTALRDY_CTRL_REG_XTALRDY_CNT_MIN_LIMIT   ( 4 )
#define XTALRDY_CTRL_REG_XTALRDY_CNT_OFFSET      ( 3 )

    if (XTALRDY_CTRL_REG_GET(XTALRDY_CLK_SEL) == XTALRDY_CLK_SEL_32KHz) {
        if (CRG_XTAL->XTAL32M_STAT1_REG & 0x100UL) {
            int16_t xtalrdy_cnt = XTALRDY_CTRL_REG_GET(XTALRDY_CNT);
            int16_t xtalrdy_stat = XTALRDY_CTRL_REG_XTALRDY_CNT_OFFSET - XTALRDY_STAT_REG_GET(XTALRDY_STAT);
            xtalrdy_cnt += xtalrdy_stat;

            if (xtalrdy_cnt < XTALRDY_CTRL_REG_XTALRDY_CNT_MIN_LIMIT) {
                xtalrdy_cnt = XTALRDY_CTRL_REG_XTALRDY_CNT_MIN_LIMIT;
            }
            XTALRDY_CTRL_REG_SET(XTALRDY_CNT, xtalrdy_cnt);
        }
    }
}

void
da1469x_clock_sys_xtal32m_init(void)
{
    da1469x_clock_sys_xtal32m_configure();

    /* Select normal XTAL32M start-up */
    XTALRDY_CTRL_REG_SET(XTALRDY_CLK_SEL, XTALRDY_CLK_SEL_32KHz);
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
        assert(da1469x_clock_sys_xtal32m_switch_check_restrictions() == 0);
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

    NVIC_ClearPendingIRQ(XTAL32M_RDY_IRQn);

    if (!da1469x_clock_is_xtal32m_settled()) {
        NVIC_EnableIRQ(XTAL32M_RDY_IRQn);
        while (!NVIC_GetPendingIRQ(XTAL32M_RDY_IRQn)) {
            __WFE();
            __SEV();
            __WFE();
        }
        NVIC_DisableIRQ(XTAL32M_RDY_IRQn);
    }

    /* XTALM32M_RDY_IRQn should be fired. The XTAL32M ready counter can be fine tuned. */
    da1469x_clock_sys_xtal32m_rdy_cnt_finetune();

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

    /* Clock reference is hardcoded to DIVN so make sure that XTAL32M is settled. */
    assert(da1469x_clock_is_xtal32m_settled());
    /*
     * Make sure calibration is not employed by multiple calibrations tasks at the same time.
     * Developers are responsible to ensure that two or more calibration tasks do not overlap
     * each other.
     */
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

#define RC32K_TARGET_FREQ   32000
#define RC32K_TRIM_MIN      0
#define RC32K_TRIM_MAX      15

static inline uint32_t
rc32k_trim_get(void)
{
    return (CRG_TOP->CLK_RC32K_REG & CRG_TOP_CLK_RC32K_REG_RC32K_TRIM_Msk) >>
           CRG_TOP_CLK_RC32K_REG_RC32K_TRIM_Pos;
}

static inline void
rc32k_trim_set(uint32_t trim)
{
    CRG_TOP->CLK_RC32K_REG =
        (CRG_TOP->CLK_RC32K_REG & ~CRG_TOP_CLK_RC32K_REG_RC32K_TRIM_Msk) |
        (trim << CRG_TOP_CLK_RC32K_REG_RC32K_TRIM_Pos);
}

void
da1469x_clock_lp_rc32k_calibrate(void)
{
    uint32_t trim;
    uint32_t trim_prev;
    uint32_t freq;
    uint32_t freq_prev;
    uint32_t freq_delta;
    uint32_t freq_delta_prev;
    bool trim_ok;

    if (!(CRG_TOP->CLK_RC32K_REG & CRG_TOP_CLK_RC32K_REG_RC32K_ENABLE_Msk)) {
        return;
    }

    freq = 0;
    freq_delta = INT32_MAX;

    trim = rc32k_trim_get();
    trim_prev = trim;
    trim_ok = false;

    do {
        freq_prev = freq;
        freq_delta_prev = freq_delta;

        freq = da1469x_clock_calibrate(0, 1);

        freq_delta = freq - RC32K_TARGET_FREQ;
        freq_delta = (int32_t)freq_delta < 0 ? -freq_delta : freq_delta;

        if (freq_delta > freq_delta_prev) {
            /* Previous trim value was closer to target frequency, use it */
            freq = freq_prev;
            rc32k_trim_set(trim_prev);
            trim_ok = true;
        } else if (freq > RC32K_TARGET_FREQ) {
            /* Decrease trim value if possible */
            if (trim > RC32K_TRIM_MIN) {
                trim_prev = trim;
                rc32k_trim_set(--trim);
            } else {
                trim_ok = true;
            }
        } else if (freq < RC32K_TARGET_FREQ) {
            /* Increase trim value if possible */
            if (trim < RC32K_TRIM_MAX) {
                trim_prev = trim;
                rc32k_trim_set(++trim);
            } else {
                trim_ok = true;
            }
        } else {
            trim_ok = true;
        }
    } while (!trim_ok);

    g_mcu_clock_rc32k_freq = freq;
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

static void
da1469x_clock_pll_wait_to_lock(void)
{
    uint32_t primask;

    primask = DA1469X_IRQ_DISABLE();

    NVIC_ClearPendingIRQ(PLL_LOCK_IRQn);

    if (!da1469x_clock_is_pll_locked()) {
        NVIC_EnableIRQ(PLL_LOCK_IRQn);
        while (!NVIC_GetPendingIRQ(PLL_LOCK_IRQn)) {
            /*
             * Wait for event and not for interrupt as the PLL lock interrupt
             * might fire right after checking its pending flag.
             * In such a case, and if there are no other interrupts expected
             * the SoC will not exit the idle state.
             */
            __WFE();
            /* Clear ARM's internal event register. */
            __SEV();
            __WFE();
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
    assert(da1469x_clock_sys_pll_switch_check_restrictions() == 0);

    da1469x_clock_pll_wait_to_lock();

    /* CLK_SEL_Msk == 3 means PLL */
    CRG_TOP->CLK_CTRL_REG |= CRG_TOP_CLK_CTRL_REG_SYS_CLK_SEL_Msk;

    while (!(CRG_TOP->CLK_CTRL_REG & CRG_TOP_CLK_CTRL_REG_RUNNING_AT_PLL96M_Msk));

    SystemCoreClock = PLL_FREQ;

    da1469x_clock_adjust_otp_access_timings();
}
