/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch_helpers.h>
#include <assert.h>
#include <lib/psci/psci.h>
#include <lib/mmio.h>

#include <cpg_regs.h>
#include <sys_regs.h>
#include <rz_private.h>

uintptr_t	gp_warm_ep;

static int rzg2l_pwr_domain_on(u_register_t mpidr)
{
	const uint32_t rval[2][2] = {
		{ SYS_CA55_CFG_RVAL0, SYS_CA55_CFG_RVAH0 },
		{ SYS_CA55_CFG_RVAL1, SYS_CA55_CFG_RVAH1 }
	};
	const uint32_t pch[2][2] = {
		{ CPG_CORE0_PCHCTL, CPG_CORE0_PCHMON },
		{ CPG_CORE1_PCHCTL, CPG_CORE1_PCHMON }
	};
	uint8_t coreid = MPIDR_AFFLVL1_VAL(mpidr);

	if (coreid > 1)
		return PSCI_E_INVALID_PARAMS;

	mmio_write_32(rval[coreid][0], (uint32_t)(gp_warm_ep & 0xFFFFFFFC));
	mmio_write_32(rval[coreid][1], (uint32_t)((gp_warm_ep >> 32) & 0xFF));

	/* Assert PORESET */
	mmio_write_32(CPG_RST_CA55, (0x00010000 << coreid));
	while ((mmio_read_32(CPG_RSTMON_CA55) & (0x1 << coreid)) == 0x0)
		;

	/* Deassert PORESET */
	mmio_write_32(CPG_RST_CA55, (0x00050005 << coreid));
	while ((mmio_read_32(CPG_RSTMON_CA55) & (0x1 << coreid)) != 0x0)
		;

	mmio_write_32(pch[coreid][0], 0x00080001);
	while ((mmio_read_32(pch[coreid][1]) & 0x1) != 0x1)
		;
	mmio_write_32(pch[coreid][0], 0x00080000);
	while ((mmio_read_32(pch[coreid][1]) & 0x1) != 0x0)
		;

	return PSCI_E_SUCCESS;
}

static void rzg2l_pwr_domain_on_finish(const psci_power_state_t *target_state)
{
#if !DEBUG_RZG2L_FPGA
	plat_gic_pcpu_init();
	plat_gic_cpuif_enable();
#endif
}

const plat_psci_ops_t rzg2l_plat_psci_ops = {
	.pwr_domain_on						= rzg2l_pwr_domain_on,
	.pwr_domain_on_finish				= rzg2l_pwr_domain_on_finish,
};

int plat_setup_psci_ops(uintptr_t sec_entrypoint,
			const plat_psci_ops_t **psci_ops)
{
	gp_warm_ep = sec_entrypoint;
	*psci_ops = &rzg2l_plat_psci_ops;

	return 0;
}
