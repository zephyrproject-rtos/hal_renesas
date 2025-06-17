/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch.h>
#include <arch_helpers.h>
#include <assert.h>
#include <common/bl_common.h>
#include <lib/xlat_tables/xlat_tables_compat.h>
#include <plat/common/common_def.h>

#include <scifa.h>
#include <plat_tzc_def.h>
#include <rz_private.h>
#include <rzg2l_def.h>

static const mmap_region_t rzg2l_mmap[] = {
	MAP_REGION_FLAT(RZG2L_SRAM_BASE, RZG2L_SRAM_SIZE,
			MT_MEMORY | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(RZG2L_DEVICE_BASE, RZG2L_DEVICE_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(RZG2L_DDR1_BASE, RZG2L_DDR1_SIZE,
			MT_MEMORY | MT_RW | MT_SECURE),
	{0}
};

static console_t rzg2l_bl31_console;
static bl2_to_bl31_params_mem_t from_bl2;

void bl31_early_platform_setup2(u_register_t arg0,
								u_register_t arg1,
								u_register_t arg2,
								u_register_t arg3)
{
	int ret;

	/* initialize console driver */
	ret = console_rzg2l_register(
							RZG2L_SCIF0_BASE,
							RZG2L_UART_INCK_HZ,
							RZG2L_UART_BARDRATE,
							&rzg2l_bl31_console);
	if (!ret)
		panic();

	console_set_scope(&rzg2l_bl31_console,
			CONSOLE_FLAG_BOOT | CONSOLE_FLAG_RUNTIME | CONSOLE_FLAG_CRASH);

	/* copy bl2_to_bl31_params_mem_t*/
	memcpy(&from_bl2, (void *)arg0, sizeof(from_bl2));
}

void bl31_plat_arch_setup(void)
{
	const mmap_region_t bl31_regions[] = {
		MAP_REGION_FLAT(BL31_START, BL31_END - BL31_START,
						MT_MEMORY | MT_RW | MT_SECURE),
		MAP_REGION_FLAT(BL_CODE_BASE, BL_CODE_END - BL_CODE_BASE,
						MT_CODE | MT_SECURE),
		MAP_REGION_FLAT(BL_RO_DATA_BASE, BL_RO_DATA_END - BL_RO_DATA_BASE,
						MT_RO_DATA | MT_SECURE),
		{0}
	};

	setup_page_tables(bl31_regions, rzg2l_mmap);
	enable_mmu_el3(0);
}

void bl31_platform_setup(void)
{
	/* Setup TZC-400 */
	plat_security_setup();

#if !DEBUG_RZG2L_FPGA
	/* initialize GIC-600 */
	plat_gic_driver_init();
	plat_gic_init();
#endif
}

entry_point_info_t *bl31_plat_get_next_image_ep_info(uint32_t type)
{
	entry_point_info_t *next_image_info = NULL;

	next_image_info = (type == NON_SECURE)
			? &from_bl2.bl33_ep_info : &from_bl2.bl32_ep_info;
	
	if (next_image_info->pc)
		return next_image_info;
	else
		return NULL;
}
