/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __CPG_H__
#define __CPG_H__
#include "cpg_regs.h"
#include <lib/mmio.h>

typedef enum {
	XSPI_CLOCK_SPIM,
	XSPI_CLOCK_OCTA,
} xspi_clock;

typedef enum clock_id_t {
	CPG_CLOCK_SPIM = 20,
	CPG_CLOCK_OCTA = 61,
} clock_id;

static inline void cpg_clock_onoff(int clkid, uint32_t mask, uint32_t val) {
	val = mask * (val & 1);
	mmio_write_32(CPG_CLKON_CA55 + clkid * 4, (mask << 16) + val);
	while ((mmio_read_32(CPG_CLKMON_CA55 + clkid * 4) & mask) != val);
}

static inline void cpg_reset_onoff(int clkid, uint32_t mask, uint32_t val) {
	val = mask * (val & 1);
	mmio_write_32(CPG_RST_CA55 + clkid * 4, (mask << 16) + (val ^ 0xffff));
	while ((mmio_read_32(CPG_RSTMON_CA55 + clkid * 4) & mask) != val);
}

#define CPG_CLKRSTONOFF_START(id) switch (id) {
#define CPG_CLKRSTONOFF_END(a) }
#define CPG_CLKON_DEF(id, mask) CPG_CLKONOFF_DEF(id, mask, 1)
#define CPG_CLKOFF_DEF(id, mask) CPG_CLKONOFF_DEF(id, mask, 0)
#define CPG_CLKONOFF_DEF(id, mask, value)                                      \
  case id:                                                                     \
    cpg_clock_onoff(id, mask, value);                                          \
    break;
#define CPG_RSTON_DEF(id, mask) CPG_RSTONOFF_DEF(id, mask, 1)
#define CPG_RSTOFF_DEF(id, mask) CPG_RSTONOFF_DEF(id, mask, 0)
#define CPG_RSTONOFF_DEF(id, mask, value)                                      \
  case id:                                                                     \
    cpg_reset_onoff(id, mask, value);                                          \
    break;

static inline void cpg_clock_on(enum clock_id_t clkid) {
	CPG_CLKRSTONOFF_START(clkid);
	CPG_CLKON_DEF(CPG_CLOCK_SPIM, 3);
	CPG_CLKON_DEF(CPG_CLOCK_OCTA, 3);
	CPG_CLKRSTONOFF_END();
}

static inline void cpg_clock_off(enum clock_id_t clkid) {
	CPG_CLKRSTONOFF_START(clkid);
	CPG_CLKOFF_DEF(CPG_CLOCK_SPIM, 3);
	CPG_CLKOFF_DEF(CPG_CLOCK_OCTA, 3);
	CPG_CLKRSTONOFF_END();
}

static inline void cpg_reset_on(enum clock_id_t clkid) {
	CPG_CLKRSTONOFF_START(clkid);
	CPG_RSTON_DEF(CPG_CLOCK_SPIM, 1);
	CPG_RSTON_DEF(CPG_CLOCK_OCTA, 1);
	CPG_CLKRSTONOFF_END();
}

static inline void cpg_reset_off(enum clock_id_t clkid) {
	CPG_CLKRSTONOFF_START(clkid);
	CPG_RSTOFF_DEF(CPG_CLOCK_SPIM, 1);
	CPG_RSTOFF_DEF(CPG_CLOCK_OCTA, 1);
	CPG_CLKRSTONOFF_END();
}

void cpg_early_setup(void);
void cpg_setup(void);
void cpg_active_ddr(void (*disable_phy)(void));
void cpg_reset_ddr_mc(void);
int cpg_set_xspi_clock(xspi_clock spi, int frequency_hz);
int cpg_get_xspi_clock(xspi_clock spi);

#endif /* __CPG_H__ */
