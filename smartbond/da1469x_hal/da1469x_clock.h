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

#ifndef __DA1469X_CLOCK_H_
#define __DA1469X_CLOCK_H_

#include <stdint.h>
#include <da1469x_config.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CLK_FREQ_TRIM_REG__XTAL32M_TRIM__DEFAULT
#define CLK_FREQ_TRIM_REG__XTAL32M_TRIM__DEFAULT   0x120
#endif

/**
 * Initialize XTAL32M
 */
void da1469x_clock_sys_xtal32m_init(void);

/**
 * Enable XTAL32M
 */
void da1469x_clock_sys_xtal32m_enable(void);

/**
 * Wait for XTAL32M to settle
 */
void da1469x_clock_sys_xtal32m_wait_to_settle(void);

/**
 * Switch sys_clk to XTAL32M
 *
 * Caller shall ensure that XTAL32M is already settled.
 */
void da1469x_clock_sys_xtal32m_switch(void);

/**
 * Switch sys_clk to XTAL32M
 *
 * Waits for XTAL32M to settle before switching.
 */
void da1469x_clock_sys_xtal32m_switch_safe(void);

/**
 * Disable RC32M
 */
void da1469x_clock_sys_rc32m_disable(void);

/**
 * Enable XTAL32K
 */
void da1469x_clock_lp_xtal32k_enable(void);

/**
 * Switch lp_clk to XTAL32K
 *
 * Caller shall ensure XTAL32K is already settled.
 */
void da1469x_clock_lp_xtal32k_switch(void);

/**
 * Enable RCX
 */
void da1469x_clock_lp_rcx_enable(void);

/**
 * Switch lp_clk to RCX
 *
 * Caller shall ensure RCX is already settled.
 */
void da1469x_clock_lp_rcx_switch(void);

/**
 * Calibrate RCX
 */
void da1469x_clock_lp_rcx_calibrate(void);

/**
 * Calibrate RC32K
 */
void da1469x_clock_lp_rc32k_calibrate(void);

/**
 * Calibrate RC32M
 */
void da1469x_clock_lp_rc32m_calibrate(void);

/**
 * Get calibrated (measured) RCX frequency
 */
uint32_t da1469x_clock_lp_rcx_freq_get(void);

/**
 * Get calibrated (measured) RC32K frequency
 */
uint32_t da1469x_clock_lp_rc32k_freq_get(void);

/**
 * Get calibrated (measured) RC32M frequency
 */
uint32_t da1469x_clock_lp_rc32m_freq_get(void);

/**
 * Disable RCX
 */
void da1469x_clock_lp_rcx_disable(void);

/**
 * Enable AMBA clock(s)
 *
 * @param mask
 */
static inline void
da1469x_clock_amba_enable(uint32_t mask)
{
    uint32_t primask;

    primask = DA1469X_IRQ_DISABLE();
    CRG_TOP->CLK_AMBA_REG |= mask;
    DA1469X_IRQ_ENABLE(primask);
}

/**
 * Disable AMBA clock(s)
 *
 * @param uint32_t mask
 */
static inline void
da1469x_clock_amba_disable(uint32_t mask)
{
    uint32_t primask;

    primask = DA1469X_IRQ_DISABLE();
    CRG_TOP->CLK_AMBA_REG &= ~mask;
    DA1469X_IRQ_ENABLE(primask);
}

/**
 * Enable PLL96
 */
void da1469x_clock_sys_pll_enable(void);

/**
 * Disable PLL96
 *
 * If PLL was used as SYS_CLOCK switches to XTAL32M.
 */
void da1469x_clock_sys_pll_disable(void);

/**
 * Checks whether PLL96 is locked and can be use as system clock or USB clock
 *
 * @return 0 if PLL is off, non-0 it its running
 */
static inline int
da1469x_clock_is_pll_locked(void)
{
    return 0 != (CRG_XTAL->PLL_SYS_STATUS_REG & CRG_XTAL_PLL_SYS_STATUS_REG_PLL_LOCK_FINE_Msk);
}

static inline bool
da1469x_clock_sys_pll_is_enabled(void)
{
#define IS_PLL_ENABLED_BITFIELDS \
    (CRG_XTAL_PLL_SYS_CTRL1_REG_PLL_EN_Msk | CRG_XTAL_PLL_SYS_CTRL1_REG_LDO_PLL_ENABLE_Msk)

    return ((CRG_XTAL->PLL_SYS_CTRL1_REG & IS_PLL_ENABLED_BITFIELDS) == IS_PLL_ENABLED_BITFIELDS);
}

/**
 * Switches system clock to PLL96
 *
 * Caller shall ensure that PLL is already locked.
 */
void da1469x_clock_sys_pll_switch(void);

/**
 * Checks if a peripheral block is clocked by the DIV1 clock path which should
 * reflect the main system clock. This API should be used before updating
 * the main system clock and abort if it's deemed that a peripheral might be affected.
 *
 * @return true if the DIV1 clock path is used by a peripheral block, false otherwise.
 */
bool da1469x_clock_check_device_div1_clock(void);

#ifdef __cplusplus
}
#endif

#endif /* __MCU_DA1469X_CLOCK_H_ */
