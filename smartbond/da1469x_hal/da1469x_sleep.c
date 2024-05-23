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

#include <stdbool.h>
#include <DA1469xAB.h>
#include <da1469x_config.h>
#include <da1469x_clock.h>
#include <da1469x_pd.h>
#include <da1469x_pdc.h>
#include <da1469x_sleep.h>

static int pdc_idx_combo;
static bool wait_for_jtag;
static struct da1469x_sleep_config sleep_config;
static uint32_t sys_clock_selection;

static bool da1469x_is_wakeup_by_jtag(void)
{
    return (da1469x_pdc_is_pending(pdc_idx_combo) &&
            !(NVIC->ISPR[0] & ((1 << CMAC2SYS_IRQn) | (1 << KEY_WKUP_GPIO_IRQn) |
                               (1 << VBUS_IRQn))));
}

static bool da1469x_is_sleep_allowed(void)
{
    if (wait_for_jtag) {
        if (CRG_TOP->SYS_STAT_REG & CRG_TOP_SYS_STAT_REG_DBG_IS_ACTIVE_Msk) {
            wait_for_jtag = false;
        }
        return false;
    }

    /* We can enter extended sleep only if running from RCX or XTAL32K, debugger is
     * not attached and there are no interrupts pending.
     */
    return (CRG_TOP->CLK_CTRL_REG & CRG_TOP_CLK_CTRL_REG_LP_CLK_SEL_Msk) &&
           !(CRG_TOP->SYS_STAT_REG & CRG_TOP_SYS_STAT_REG_DBG_IS_ACTIVE_Msk) &&
           !((NVIC->ISPR[0] & NVIC->ISER[0]) | (NVIC->ISPR[1] & NVIC->ISER[1]));
}

int da1469x_sleep(void)
{
    int slept = 0;

    if (!da1469x_is_sleep_allowed()) {
        __DMB();
        __WFI();
        return 0;
    }

    /* PD_SYS will not be disabled here until we enter deep sleep - don't wait */
    if (!da1469x_pd_release_nowait(MCU_PD_DOMAIN_SYS)) {
        __DMB();
        __WFI();
    } else {
        da1469x_pdc_ack_all_m33();
        sys_clock_selection = CRG_TOP->CLK_CTRL_REG & CRG_TOP_CLK_CTRL_REG_SYS_CLK_SEL_Msk;
        slept = da1469x_enter_sleep();
        if (slept) {
            /* Watchdog is always resumed when PD_SYS is turned off, need to
             * freeze it again if there's no one to feed it.
             */
            GPREG->SET_FREEZE_REG = GPREG_SET_FREEZE_REG_FRZ_SYS_WDOG_Msk;
            SYS_WDOG->WATCHDOG_REG = SYS_WDOG_WATCHDOG_REG_WDOG_VAL_Msk;

            da1469x_pd_acquire(MCU_PD_DOMAIN_SYS);
            if (da1469x_is_wakeup_by_jtag()) {
                wait_for_jtag = 1;
            }
            if (sys_clock_selection != 1) {
                da1469x_clock_sys_xtal32m_wait_to_settle();
                /* PLL requires that the current system clock be XTAL32M. */
                da1469x_clock_sys_xtal32m_switch();
            }
            if (sys_clock_selection == 3 << CRG_TOP_CLK_CTRL_REG_SYS_CLK_SEL_Pos) {
                da1469x_clock_sys_pll_enable();
                da1469x_clock_sys_pll_switch();
            }
        }
    }

    /*
     * The SoC did not enter the normal sleep state. Acquire PD_SYS without
     * applying preferred settings.
     */
    if (slept == 0) {
        da1469x_pd_acquire_noconf(MCU_PD_DOMAIN_SYS);
    }

    return slept;
}

void da1469x_sleep_config(const struct da1469x_sleep_config *config)
{
    sleep_config = *config;

    pdc_idx_combo = da1469x_pdc_add(MCU_PDC_TRIGGER_COMBO, MCU_PDC_MASTER_M33,
                                    sleep_config.enable_xtal_on_wakeup);
    __ASSERT_NO_MSG(pdc_idx_combo >= 0);
    da1469x_pdc_set(pdc_idx_combo);
    da1469x_pdc_ack(pdc_idx_combo);
}
