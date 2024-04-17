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

#ifndef __IPC_CMAC_SHM_H_
#define __IPC_CMAC_SHM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MEMCTRL_BSR_SET_REG         (*(volatile uint32_t *)0x50050074)
#define MEMCTRL_BSR_STAT_REG        (*(volatile uint32_t *)0x5005007c)
#define MEMCTRL_BSR_RESET_REG       (*(volatile uint32_t *)0x50050078)

#define CMAC_SHM_LOCK_VAL          0x40000000

#define CMAC_SHM_CB_MAGIC                   0xc3ac

#define CMAC_SHM_CB_PENDING_OP_LP_CLK       0x0001
#define CMAC_SHM_CB_PENDING_OP_RF_CAL       0x0002

#define CMAC_SHM_VECT_MAGIC                 0xc3ac0001
#define CMAC_SHM_VECT_CRASHINFO             0x00000001
#define CMAC_SHM_VECT_DEBUGDATA             0x00000002

struct cmac_shm_config {
    uint16_t mbox_s2c_size;
    uint16_t mbox_c2s_size;
    uint8_t trim_rfcu_size;
    uint8_t trim_rfcu_mode1_size;
    uint8_t trim_rfcu_mode2_size;
    uint8_t trim_synth_size;
    uint16_t rand_size;
};

struct cmac_shm_ctrl {
    volatile uint16_t magic;
    uint16_t pending_ops;
    uint16_t lp_clock_freq;
    uint16_t xtal32m_settle_us;
};

struct cmac_shm_mbox {
    uint16_t rd_off;
    uint16_t wr_off;
    uint8_t data[];
};

struct cmac_shm_trim {
    uint8_t rfcu_len;
    uint8_t rfcu_mode1_len;
    uint8_t rfcu_mode2_len;
    uint8_t synth_len;
    uint32_t data[];
};

struct cmac_shm_rand {
    uint16_t cmr_active;
    uint16_t cmr_in;
    uint16_t cmr_out;
    uint32_t cmr_buf[];
};

struct cmac_shm_dcdc {
    uint8_t enabled;
    uint32_t v18;
    uint32_t v18p;
    uint32_t vdd;
    uint32_t v14;
    uint32_t ctrl1;
};

struct cmac_shm_crashinfo {
    uint32_t lr;
    uint32_t pc;
    uint32_t assert;
    const char *assert_file;
    uint32_t assert_line;

    uint32_t CM_STAT_REG;
    uint32_t CM_LL_TIMER1_36_10_REG;
    uint32_t CM_LL_TIMER1_9_0_REG;
    uint32_t CM_ERROR_REG;
    uint32_t CM_EXC_STAT_REG;
};

struct cmac_shm_debugdata {
    int8_t tx_power_ovr_enable;
    int8_t tx_power_ovr;
    int8_t last_rx_rssi;

    uint32_t cal_res_1;
    uint32_t cal_res_2;
    uint32_t trim_val1_tx_1;
    uint32_t trim_val1_tx_2;
    uint32_t trim_val2_tx;
    uint32_t trim_val2_rx;
};

struct cmac_shm {
    struct cmac_shm_config *config;
    struct cmac_shm_ctrl *ctrl;
    struct cmac_shm_mbox *mbox_s2c;
    struct cmac_shm_mbox *mbox_c2s;
    struct cmac_shm_trim *trim;
    struct cmac_shm_rand *rand;
    struct cmac_shm_dcdc *dcdc;
    struct cmac_shm_crashinfo *crashinfo;
    struct cmac_shm_debugdata *debugdata;
};

extern struct cmac_shm g_cmac_shm;
extern void cmac_read_req(void);
extern void cmac_rng_req(void);

void cmac_cmac2sys_isr(void);

void cmac_configure_shm(void);

void cmac_configure_pdc(void);
void cmac_load_image(void);
void cmac_enable(void);
void cmac_disable(void);

void cmac_request_lp_clock_freq_set(uint32_t freq);

void cmac_signal(void);

static inline void
cmac_shm_lock(void)
{
    while ((MEMCTRL->BUSY_STAT_REG & MEMCTRL_BUSY_RESET_REG_BUSY_SPARE_Msk) != 0x40000000) {
        MEMCTRL->BUSY_SET_REG = 0x40000000;
    }
}

static inline void
cmac_shm_unlock(void)
{
    MEMCTRL->BUSY_RESET_REG = 0x40000000;
}

#ifdef __cplusplus
}
#endif

#endif /* __IPC_CMAC_SHM_H_ */
