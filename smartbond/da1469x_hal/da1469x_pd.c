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

#include <zephyr/arch/common/sys_io.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <DA1469xAB.h>
#include <da1469x_config.h>
#include <da1469x_pd.h>
#include <da1469x_trimv.h>

#define PD_COUNT          (sizeof(g_da1469x_pd_desc) / sizeof(g_da1469x_pd_desc[0]))

#define REG_TO_PTR(_reg)  ((uintptr_t)&(_reg))

struct da1469x_pd_desc {
    uint8_t pmu_sleep_bit;
    uint8_t stat_down_bit; /* up is +1 */
};

static uint32_t trimv_words_buf[16];
static uint32_t trimv_words_idx = 0;

struct da1469x_pd_data {
    uint8_t refcnt;
    uint8_t trimv_count;
    uint32_t *trimv_words;
};

enum chip_variant {
	CHIP_VARIANT_TSMC,
	CHIP_VARIANT_GF,
	CHIP_VARIANT_UNKNOWN
};

static int g_device_id = CHIP_VARIANT_UNKNOWN;

/* Only include controllable power domains here */
static const struct da1469x_pd_desc g_da1469x_pd_desc[] = {
    [MCU_PD_DOMAIN_SYS] = { CRG_TOP_PMU_CTRL_REG_SYS_SLEEP_Pos,
                            CRG_TOP_SYS_STAT_REG_SYS_IS_DOWN_Pos },
    [MCU_PD_DOMAIN_PER] = { CRG_TOP_PMU_CTRL_REG_PERIPH_SLEEP_Pos,
                            CRG_TOP_SYS_STAT_REG_PER_IS_DOWN_Pos },
    [MCU_PD_DOMAIN_TIM] = { CRG_TOP_PMU_CTRL_REG_TIM_SLEEP_Pos,
                            CRG_TOP_SYS_STAT_REG_TIM_IS_DOWN_Pos },
    [MCU_PD_DOMAIN_COM] = { CRG_TOP_PMU_CTRL_REG_COM_SLEEP_Pos,
                            CRG_TOP_SYS_STAT_REG_COM_IS_DOWN_Pos},
};

static struct da1469x_pd_data g_da1469x_pd_data[PD_COUNT];

static inline void
write32_mask(uint32_t mask, uint32_t data, mem_addr_t addr)
{
	uint32_t val = sys_read32(addr);

	sys_write32((val & (~mask)) | (data & mask), addr);
}

static void
da1469x_pd_load_trimv(uint8_t pd, uint8_t group)
{
    struct da1469x_pd_data *pdd;

    assert(pd < PD_COUNT);

    pdd = &g_da1469x_pd_data[pd];
    pdd->trimv_count = da1469x_trimv_group_num_words_get(group);
    if (pdd->trimv_count == 0) {
        return;
    }

    if (trimv_words_idx + pdd->trimv_count <= ARRAY_SIZE(trimv_words_buf)) {
        pdd->trimv_words = &trimv_words_buf[trimv_words_idx];
        trimv_words_idx += pdd->trimv_count;
    } else {
        pdd->trimv_count = 0;
        assert(0);
        return;
    }

    pdd->trimv_count = da1469x_trimv_group_read(group, pdd->trimv_words,
                                                pdd->trimv_count);
    pdd->trimv_count /= 2;
}

static void
da1469x_pd_apply_trimv(uint8_t pd)
{
    struct da1469x_pd_data *pdd;
    volatile uint32_t *reg;
    uint32_t val;
    int idx;

    assert(pd < PD_COUNT);

    pdd = &g_da1469x_pd_data[pd];
    if (pdd->trimv_count == 0) {
        return;
    }

    for (idx = 0; idx < pdd->trimv_count; idx++) {
        reg = (uint32_t *) pdd->trimv_words[idx * 2];
        val = pdd->trimv_words[idx * 2 + 1];
        *reg = val;
    }
}

static int
read_device_id(void)
{
	union {
		uint8_t array[4];
		uint32_t value;
	} chip_id;

	chip_id.array[3] = CHIP_VERSION->CHIP_ID1_REG & CHIP_VERSION_CHIP_ID1_REG_CHIP_ID1_Msk;
	chip_id.array[2] = CHIP_VERSION->CHIP_ID2_REG & CHIP_VERSION_CHIP_ID2_REG_CHIP_ID2_Msk;
	chip_id.array[1] = CHIP_VERSION->CHIP_ID3_REG & CHIP_VERSION_CHIP_ID3_REG_CHIP_ID3_Msk;
	chip_id.array[0] = CHIP_VERSION->CHIP_ID4_REG & CHIP_VERSION_CHIP_ID4_REG_CHIP_ID4_Msk;

	if (chip_id.value == 0x32353232) {
		return CHIP_VARIANT_TSMC;
	} else if (chip_id.value == 0x33303830) {
		return CHIP_VARIANT_GF;
	} else {
		return CHIP_VARIANT_UNKNOWN;
	}
}

static void 
da1469x_TSMC_pd_apply_preferred(uint8_t pd)
{
	switch (pd) {
	case MCU_PD_DOMAIN_AON:
	    /* Apply if no user-defined value has been applied */
		if (sys_read32(REG_TO_PTR(CRG_TOP->PMU_TRIM_REG)) == 0x00008800) {
			sys_write32(0x00007700, REG_TO_PTR(CRG_TOP->PMU_TRIM_REG));
		}
		write32_mask(0x00001000, 0x00001020, REG_TO_PTR(CRG_TOP->BANDGAP_REG));
		sys_write32(0x000000ca, REG_TO_PTR(CRG_TOP->BIAS_VREF_SEL_REG));
		write32_mask(0x0003ffff, 0x041e6ef4, REG_TO_PTR(CRG_TOP->BOD_LVL_CTRL0_REG));
		break;
	case MCU_PD_DOMAIN_SYS:
		write32_mask(0x00000c00, 0x003f6a78, REG_TO_PTR(CHARGER->CHARGER_CTRL_REG));
		write32_mask(0x000003ff, 0x00000002, REG_TO_PTR(CHARGER->CHARGER_PWR_UP_TIMER_REG));
		break;
	case MCU_PD_DOMAIN_TIM:
		write32_mask(0x3ff00000, 0x000afd70, REG_TO_PTR(CRG_XTAL->CLK_FREQ_TRIM_REG));
		write32_mask(0x000000c0, 0x00000562, REG_TO_PTR(CRG_XTAL->TRIM_CTRL_REG));
		write32_mask(0x03c38002, 0x0801e6b6, REG_TO_PTR(CRG_XTAL->XTAL32M_CTRL0_REG)); 
		write32_mask(0x007fff00, 0x7500a1a4, REG_TO_PTR(CRG_XTAL->XTAL32M_CTRL1_REG));
		write32_mask(0x00000fff, 0x001e45c4, REG_TO_PTR(CRG_XTAL->XTAL32M_CTRL2_REG));
		write32_mask(0x40000000, 0x40096255, REG_TO_PTR(CRG_XTAL->XTAL32M_CTRL3_REG));
		write32_mask(0x00c00000, 0x00c00000, 0x50010040);
		write32_mask(0x000000ff, 0x00000180, REG_TO_PTR(CRG_XTAL->XTALRDY_CTRL_REG));
		break;
	}
}

static void 
da1469x_GF_pd_apply_preferred(uint8_t pd)
{
	switch (pd) {
	case MCU_PD_DOMAIN_AON:
		write32_mask(0x00001000, 0x00001020, REG_TO_PTR(CRG_TOP->BANDGAP_REG));
		sys_write32(0x000000ca, REG_TO_PTR(CRG_TOP->BIAS_VREF_SEL_REG));
		write32_mask(0x0003ffff, 0x041e6ef4, REG_TO_PTR(CRG_TOP->BOD_LVL_CTRL0_REG));
		write32_mask(0x00000f00, 0x00000dfc, REG_TO_PTR(CRG_TOP->CLK_RCX_REG));
		write32_mask(0x0000007e, 0x00000024, REG_TO_PTR(CRG_TOP->CLK_XTAL32K_REG));
		break;
	case MCU_PD_DOMAIN_SYS:
		write32_mask(0x00000c00, 0x003f6a78, REG_TO_PTR(CHARGER->CHARGER_CTRL_REG));
		write32_mask(0x000003ff, 0x00000002, REG_TO_PTR(CHARGER->CHARGER_PWR_UP_TIMER_REG));
		break;
	case MCU_PD_DOMAIN_TIM:
		write32_mask(0x3ff00000, 0x000afd70, REG_TO_PTR(CRG_XTAL->CLK_FREQ_TRIM_REG));
		write32_mask(0x000000c0, 0x00000562, REG_TO_PTR(CRG_XTAL->TRIM_CTRL_REG));
		write32_mask(0x1fc38002, 0x0c01e6b6, REG_TO_PTR(CRG_XTAL->XTAL32M_CTRL0_REG)); 
		write32_mask(0x707fff00, 0x0500a1a4, REG_TO_PTR(CRG_XTAL->XTAL32M_CTRL1_REG));
		write32_mask(0x00000fff, 0x001e45c4, REG_TO_PTR(CRG_XTAL->XTAL32M_CTRL2_REG));
		write32_mask(0x40000000, 0x40096255, REG_TO_PTR(CRG_XTAL->XTAL32M_CTRL3_REG));
		write32_mask(0x00c00000, 0x00c00000, 0x50010040);
		write32_mask(0x000000ff, 0x00000180, REG_TO_PTR(CRG_XTAL->XTALRDY_CTRL_REG));
		break;
	}
}

__weak void
da1469x_pd_apply_preferred(uint8_t pd)
{
	if (g_device_id == CHIP_VARIANT_TSMC) {
		da1469x_TSMC_pd_apply_preferred(pd);
	} else {
		da1469x_GF_pd_apply_preferred(pd);
	}
}


int
da1469x_pd_init(void)
{
    /* Get the chip ID before initilizating any PD */
	g_device_id = read_device_id();
	assert(g_device_id != CHIP_VARIANT_UNKNOWN);

    /*
     * Apply now for always-on domain which, as name suggests, is always on so
     * need to do this only once.
     */
    da1469x_pd_apply_preferred(MCU_PD_DOMAIN_AON);

    da1469x_pd_load_trimv(MCU_PD_DOMAIN_SYS, 1);
    da1469x_pd_load_trimv(MCU_PD_DOMAIN_COM, 2);
    da1469x_pd_load_trimv(MCU_PD_DOMAIN_TIM, 4);
    da1469x_pd_load_trimv(MCU_PD_DOMAIN_PER, 5);

    return 0;
}

int
da1469x_pd_get_ref_cnt(uint8_t pd)
{
    struct da1469x_pd_data *pdd;

    assert(pd < PD_COUNT);

    pdd = &g_da1469x_pd_data[pd];

    return pdd->refcnt;
}

static int
da1469x_pd_acquire_internal(uint8_t pd, bool load)
{
    struct da1469x_pd_data *pdd;
    uint32_t primask;
    uint32_t bitmask;
    int ret = 0;

    assert(pd < PD_COUNT);

    pdd = &g_da1469x_pd_data[pd];

    primask = DA1469X_IRQ_DISABLE();

    assert(pdd->refcnt < UINT8_MAX);

    if (pdd->refcnt++ == 0) {
        bitmask = 1 << g_da1469x_pd_desc[pd].pmu_sleep_bit;
        CRG_TOP->PMU_CTRL_REG &= ~bitmask;

        bitmask = 1 << (g_da1469x_pd_desc[pd].stat_down_bit + 1);
        while ((CRG_TOP->SYS_STAT_REG & bitmask) == 0);

        if (load) {
            da1469x_pd_apply_trimv(pd);
            da1469x_pd_apply_preferred(pd);
        }

        ret = 1;
    }

    DA1469X_IRQ_ENABLE(primask);

    return ret;
}

int
da1469x_pd_acquire(uint8_t pd)
{
    return da1469x_pd_acquire_internal(pd, true);
}

int
da1469x_pd_acquire_noconf(uint8_t pd)
{
    return da1469x_pd_acquire_internal(pd, false);
}

static int
da1469x_pd_release_internal(uint8_t pd, bool wait)
{
    struct da1469x_pd_data *pdd;
    uint32_t primask;
    uint32_t bitmask;
    int ret = 0;

    assert(pd < PD_COUNT);

    pdd = &g_da1469x_pd_data[pd];

    primask = DA1469X_IRQ_DISABLE();

    assert(pdd->refcnt > 0);

    if (--pdd->refcnt == 0) {
        bitmask = 1 << g_da1469x_pd_desc[pd].pmu_sleep_bit;
        CRG_TOP->PMU_CTRL_REG |= bitmask;

        if (wait) {
            bitmask = 1 << g_da1469x_pd_desc[pd].stat_down_bit;
            while ((CRG_TOP->SYS_STAT_REG & bitmask) == 0);
        }

        ret = 1;
    }

    DA1469X_IRQ_ENABLE(primask);;

    return ret;
}

int
da1469x_pd_release(uint8_t pd)
{
    return da1469x_pd_release_internal(pd, true);
}

int
da1469x_pd_release_nowait(uint8_t pd)
{
    return da1469x_pd_release_internal(pd, false);
}
