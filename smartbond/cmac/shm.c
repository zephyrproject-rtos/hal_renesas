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
#include <string.h>

#include <DA1469xAB.h>
#include <da1469x_pdc.h>
#include <da1469x_trimv.h>
#include <mbox.h>
#include <rand.h>
#include <shm.h>

extern char _binary_cmac_img_bin_start[];
extern char _binary_cmac_img_bin_end;
extern char _binary_cmac_ram_bin_start[];
extern char _binary_cmac_ram_bin_end;

struct cmac_img_info {
    uint32_t magic;
    uint32_t img_size;
    uint32_t ram_size;
    uint32_t data_offset;
    uint32_t shared_offset;
    uint32_t shared_addr;
};

struct cmac_img_hdr {
    uint32_t isr[32];
    struct cmac_img_info ii;
    struct cmac_shm_config *shm_config;
    struct cmac_shm_ctrl *shm_ctrl;
    struct cmac_shm_mbox *shm_mbox_s2c;
    struct cmac_shm_mbox *shm_mbox_c2s;
    struct cmac_shm_trim *shm_trim;
    struct cmac_shm_rand *shm_rand;
    struct cmac_shm_dcdc *shm_dcdc;
    struct cmac_shm_crashinfo *shm_crashinfo;
    struct cmac_shm_debugdata *shm_debugdata;
};

#define CMAC_IMG_HDR        ((struct cmac_img_hdr *)_binary_cmac_img_bin_start)

#define CMAC_CODE_PTR(_ptr)     ((void *)((uint32_t)(_ptr) + \
                                          0x20000000 + \
                                          MEMCTRL->CMI_CODE_BASE_REG))
#define CMAC_SHARED_PTR(_ptr)   ((void *)((uint32_t)(_ptr) - \
                                          CMAC_IMG_HDR->ii.shared_addr + \
                                          0x20000000 + \
                                          MEMCTRL->CMI_SHARED_BASE_REG))

struct cmac_shm g_cmac_shm;

/* PDC entry for waking up CMAC */
static int8_t g_cmac_host_pdc_sys2cmac;
/* PDC entry for waking up M33 */
static int8_t g_cmac_host_pdc_cmac2sys;

void
cmac_cmac2sys_isr(void)
{
    /* Clear CMAC2SYS interrupt */
    *(volatile uint32_t *)0x40002000 = 2;

    if (cmac_mbox_has_data()) {
        cmac_read_req();
    }

    if (*(volatile uint32_t *)0x40002000 & 0x1c00) {
        return;
    }

    if (cmac_rand_needs_data()) {
        cmac_rng_req();
    }
}

static void
resolve_shm_ptrs(void)
{
    g_cmac_shm.config = CMAC_CODE_PTR(CMAC_IMG_HDR->shm_config);
    g_cmac_shm.ctrl = CMAC_SHARED_PTR(CMAC_IMG_HDR->shm_ctrl);
    g_cmac_shm.mbox_s2c = CMAC_SHARED_PTR(CMAC_IMG_HDR->shm_mbox_s2c);
    g_cmac_shm.mbox_c2s = CMAC_SHARED_PTR(CMAC_IMG_HDR->shm_mbox_c2s);
    g_cmac_shm.trim = CMAC_SHARED_PTR(CMAC_IMG_HDR->shm_trim);
    g_cmac_shm.rand = CMAC_SHARED_PTR(CMAC_IMG_HDR->shm_rand);
    g_cmac_shm.dcdc = CMAC_SHARED_PTR(CMAC_IMG_HDR->shm_dcdc);
    g_cmac_shm.crashinfo = CMAC_SHARED_PTR(CMAC_IMG_HDR->shm_crashinfo);
    g_cmac_shm.debugdata = CMAC_SHARED_PTR(CMAC_IMG_HDR->shm_debugdata);
}

static void
shm_configure_trim(void)
{
    struct cmac_shm_config *config;
    struct cmac_shm_trim *trim;
    uint32_t *trim_data;

    config = g_cmac_shm.config;
    trim = g_cmac_shm.trim;
    trim_data = trim->data;

    trim->rfcu_len =
        da1469x_trimv_group_read(6, trim_data, config->trim_rfcu_size);
    trim_data += config->trim_rfcu_size;
    trim->rfcu_mode1_len =
        da1469x_trimv_group_read(8, trim_data, config->trim_rfcu_mode1_size);
    trim_data += config->trim_rfcu_mode1_size;
    trim->rfcu_mode2_len =
        da1469x_trimv_group_read(10, trim_data, config->trim_rfcu_mode2_size);
    trim_data += config->trim_rfcu_mode2_size;
    trim->synth_len =
        da1469x_trimv_group_read(7, trim_data, config->trim_synth_size);
}

static void
shm_configure_dcdc(void)
{
    struct cmac_shm_dcdc *dcdc;

    dcdc = g_cmac_shm.dcdc;

    dcdc->enabled = !!(DCDC->DCDC_CTRL1_REG & DCDC_DCDC_CTRL1_REG_DCDC_ENABLE_Msk);
    if (dcdc->enabled) {
        dcdc->v18 = DCDC->DCDC_V18_REG;
        dcdc->v18p = DCDC->DCDC_V18P_REG;
        dcdc->vdd = DCDC->DCDC_VDD_REG;
        dcdc->v14 = DCDC->DCDC_V14_REG;
        dcdc->ctrl1 = DCDC->DCDC_CTRL1_REG;
    }
}

void
cmac_configure_shm(void)
{
    resolve_shm_ptrs();

    /* TODO: make this configurable */
    g_cmac_shm.ctrl->xtal32m_settle_us = 1000;

    shm_configure_trim();
    shm_configure_dcdc();
}

void
cmac_load_image(void)
{
    struct cmac_img_info *ii;
    uint32_t img_size;
    uint32_t ram_size;

    /* Calculate size of image and RAM area */
    img_size = &_binary_cmac_img_bin_end - &_binary_cmac_img_bin_start[0];
    ram_size = &_binary_cmac_ram_bin_end - &_binary_cmac_ram_bin_start[0];

    ii = &CMAC_IMG_HDR->ii;
    assert(ii->magic == 0xC3AC0001);
    assert(ii->img_size == img_size);
    assert(ii->ram_size <= ram_size);

    /* Setup CMAC memory addresses */
    MEMCTRL->CMI_CODE_BASE_REG = (uint32_t)&_binary_cmac_ram_bin_start;
    MEMCTRL->CMI_DATA_BASE_REG = MEMCTRL->CMI_CODE_BASE_REG + ii->data_offset;
    MEMCTRL->CMI_SHARED_BASE_REG = MEMCTRL->CMI_CODE_BASE_REG + ii->shared_offset;
    MEMCTRL->CMI_END_REG = MEMCTRL->CMI_CODE_BASE_REG + ii->ram_size - 1;

    /* Clear RAM area then copy image */
    memset(&_binary_cmac_ram_bin_start, 0, ram_size);
    memcpy(&_binary_cmac_ram_bin_start, &_binary_cmac_img_bin_start, img_size);
}

void
cmac_configure_pdc(void)
{
    /* Add PDC entry to wake up CMAC from M33 */
    g_cmac_host_pdc_sys2cmac = da1469x_pdc_add(MCU_PDC_TRIGGER_MAC_TIMER,
                                               MCU_PDC_MASTER_CMAC,
                                               MCU_PDC_EN_XTAL);
    da1469x_pdc_set(g_cmac_host_pdc_sys2cmac);
    da1469x_pdc_ack(g_cmac_host_pdc_sys2cmac);

    /* Add PDC entry to wake up M33 from CMAC, if does not exist yet */
    g_cmac_host_pdc_cmac2sys = da1469x_pdc_find(MCU_PDC_TRIGGER_COMBO,
                                                MCU_PDC_MASTER_M33, 0);
    if (g_cmac_host_pdc_cmac2sys < 0) {
        g_cmac_host_pdc_cmac2sys = da1469x_pdc_add(MCU_PDC_TRIGGER_COMBO,
                                                   MCU_PDC_MASTER_M33,
                                                   MCU_PDC_EN_XTAL);
        da1469x_pdc_set(g_cmac_host_pdc_cmac2sys);
        da1469x_pdc_ack(g_cmac_host_pdc_cmac2sys);
    }
}

void
cmac_enable(void)
{
    /* Enable Radio LDO */
    CRG_TOP->POWER_CTRL_REG |= CRG_TOP_POWER_CTRL_REG_LDO_RADIO_ENABLE_Msk;

    /* Enable CMAC, but keep it in reset */
    CRG_TOP->CLK_RADIO_REG = (1 << CRG_TOP_CLK_RADIO_REG_RFCU_ENABLE_Pos) |
                             (1 << CRG_TOP_CLK_RADIO_REG_CMAC_SYNCH_RESET_Pos) |
                             (0 << CRG_TOP_CLK_RADIO_REG_CMAC_CLK_SEL_Pos) |
                             (1 << CRG_TOP_CLK_RADIO_REG_CMAC_CLK_ENABLE_Pos) |
                             (0 << CRG_TOP_CLK_RADIO_REG_CMAC_DIV_Pos);

    /* Release CMAC from reset and sync */
    CRG_TOP->CLK_RADIO_REG &= ~CRG_TOP_CLK_RADIO_REG_CMAC_SYNCH_RESET_Msk;

    while (g_cmac_shm.ctrl->magic != CMAC_SHM_CB_MAGIC) {
        /* Wait for CMAC to initialize */
    };
}

void
cmac_disable(void)
{
    CRG_TOP->CLK_RADIO_REG = CRG_TOP_CLK_RADIO_REG_CMAC_SYNCH_RESET_Msk;
}

void
cmac_signal(void)
{
    da1469x_pdc_set(g_cmac_host_pdc_sys2cmac);
}

void
cmac_request_lp_clock_freq_set(uint32_t freq)
{
    /* No need to wakeup CMAC if LP clock frequency did not change */
    if (g_cmac_shm.ctrl->lp_clock_freq == freq) {
        return;
    }

    cmac_shm_lock();
    g_cmac_shm.ctrl->lp_clock_freq = freq;
    g_cmac_shm.ctrl->pending_ops |= CMAC_SHM_CB_PENDING_OP_LP_CLK;
    cmac_shm_unlock();

    cmac_signal();
}

void
cmac_request_rf_calibrate(void)
{
    cmac_shm_lock();
    g_cmac_shm.ctrl->pending_ops |= CMAC_SHM_CB_PENDING_OP_RF_CAL;
    cmac_shm_unlock();

    cmac_signal();
}
