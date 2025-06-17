/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <platform_def.h>

#include <common/debug.h>
#include <lib/psci/psci.h>

static const unsigned char rzg2l_power_domain_tree_desc[] = {
	PLATFORM_SYSTEM_COUNT,
	PLATFORM_CLUSTER_COUNT,
	PLATFORM_CORE_COUNT
};

const unsigned char *plat_get_power_domain_tree_desc(void)
{
	return rzg2l_power_domain_tree_desc;
}

int plat_core_pos_by_mpidr(u_register_t mpidr)
{
	unsigned int cluster_id, cpu_id;

	cluster_id = MPIDR_AFFLVL2_VAL(mpidr);
	cpu_id = MPIDR_AFFLVL1_VAL(mpidr);

	if ((cluster_id >= PLATFORM_CLUSTER_COUNT) || (cpu_id >= PLATFORM_CORE_COUNT))
		return -1;

	return cpu_id;
}
