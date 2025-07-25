/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <platform_def.h>

#include <common/interrupt_props.h>
#include <drivers/arm/gicv3.h>
#include <plat/common/platform.h>

#include <rzg2l_def.h>
#include <rz_private.h>

uintptr_t plat_rdistif_base_addrs[PLATFORM_CORE_COUNT];

static unsigned int plat_mpidr_to_core_pos(u_register_t mpidr)
{
	mpidr |= (read_mpidr_el1() & MPIDR_MT_MASK);
	return (unsigned int)plat_core_pos_by_mpidr(mpidr);
}

const gicv3_driver_data_t rzg2l_gic_data = {
	.gicd_base = RZG2L_GICD_BASE,
	.gicr_base = RZG2L_GICR_BASE,
	.rdistif_num = PLATFORM_CORE_COUNT,
	.rdistif_base_addrs = plat_rdistif_base_addrs,
	.mpidr_to_core_pos = plat_mpidr_to_core_pos,
};

void plat_gic_driver_init(void)
{
	gicv3_driver_init(&rzg2l_gic_data);
}

void plat_gic_init(void)
{
	gicv3_distif_init();
	gicv3_rdistif_init(plat_my_core_pos());
	gicv3_cpuif_enable(plat_my_core_pos());
}

void plat_gic_cpuif_enable(void)
{
	gicv3_cpuif_enable(plat_my_core_pos());
}

void plat_gic_cpuif_disable(void)
{
	gicv3_cpuif_disable(plat_my_core_pos());
}

void plat_gic_pcpu_init(void)
{
	gicv3_rdistif_init(plat_my_core_pos());
}
