/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>
#include <arch.h>
#include <arch_helpers.h>
#include <assert.h>
#include <common/bl_common.h>
#include <common/desc_image_load.h>
#include <drivers/generic_delay_timer.h>
#include <lib/xlat_tables/xlat_tables_compat.h>
#include <plat/common/common_def.h>
#include <lib/mmio.h>
#include <pfc.h>
#include <cpg.h>
#include <syc.h>
#include <scifa.h>
#include <ddr.h>
#include <sys_regs.h>
#include <plat_tzc_def.h>
#include <rzg2l_def.h>
#include <rza3ul_def.h>
#include <rz_private.h>
#include <rza_printf.h>
#include <rza_ipl_version.h>
#include <rza_mmu.h>

#ifndef RZA3
static const mmap_region_t rzg2l_mmap[] = {
	/* MMU table for non-RZ/A3UL */
#if TRUSTED_BOARD_BOOT
	MAP_REGION_FLAT(RZG2L_BOOT_ROM_BASE, RZG2L_BOOT_ROM_SIZE,
		MT_MEMORY | MT_RO | MT_SECURE),
#endif /*TRUSTED_BOARD_BOOT */
	MAP_REGION_FLAT(RZG2L_SRAM_BASE, RZG2L_SRAM_SIZE,
		MT_MEMORY | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(PARAMS_BASE, PARAMS_SIZE,
		MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(RZG2L_DEVICE_BASE, RZG2L_DEVICE_SIZE,
		MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(RZG2L_SPIROM_BASE, RZG2L_SPIROM_SIZE,
		MT_MEMORY | MT_RO | MT_SECURE),
	MAP_REGION_FLAT(RZG2L_DDR1_BASE, RZG2L_DDR1_SIZE,
		MT_MEMORY | MT_RW | MT_SECURE),
	{0}
};
#endif /* RZA3 */

static console_t rzg2l_bl31_console;

int bl2_plat_handle_pre_image_load(unsigned int image_id)
{
	return 0;
}

int bl2_plat_handle_post_image_load(unsigned int image_id)
{
	static bl2_to_bl31_params_mem_t *params;
	bl_mem_params_node_t *bl_mem_params;

	if (!params) {
		params = (bl2_to_bl31_params_mem_t *) PARAMS_BASE;
		memset((void *)PARAMS_BASE, 0, sizeof(*params));
	}

	bl_mem_params = get_bl_mem_params_node(image_id);

	switch (image_id) {
	case BL32_IMAGE_ID:
		memcpy(&params->bl32_ep_info, &bl_mem_params->ep_info,
			sizeof(entry_point_info_t));
		break;
	case BL33_IMAGE_ID:
		memcpy(&params->bl33_ep_info, &bl_mem_params->ep_info,
			sizeof(entry_point_info_t));
		break;
	default:
		/* Do nothing in default case */
		break;
	}

	return 0;
}


void bl2_el3_early_platform_setup(u_register_t arg1, u_register_t arg2,
								u_register_t arg3, u_register_t arg4)
{
	int ret;

	/* early setup Clock and Reset */
	cpg_early_setup();

	/* initialize SYC */
	syc_init(RZG2L_SYC_INCK_HZ);

	/* initialize Timer */
	generic_delay_timer_init();

	/* setup PFC */
	pfc_setup();

	/* setup Clock and Reset */
	cpg_setup();

	/* initialize console driver */
	ret = console_rzg2l_register(
					RZG2L_SCIF0_BASE,
					RZG2L_UART_INCK_HZ,
					RZG2L_UART_BARDRATE,
					&rzg2l_bl31_console);
	if (!ret)
		panic();

	console_set_scope(&rzg2l_bl31_console,
			CONSOLE_FLAG_BOOT | CONSOLE_FLAG_CRASH);

	RZA_PRINTF("Initial Program Loader %s\n", RZA_IPL_VERSION_STRING);
	RZA_PRINTF("%s\n", build_message);
}

void bl2_el3_plat_arch_setup(void)
{
#if RZA3
	rza_mmu_pgtbl_cfg_t g_mmu_pagetable_array[] = {
		/* vaddress, paddress,   size,       attribute */
		{0x00000000, 0x00000000, 0x00200000, RZA_MMU_ATTRIBUTE_NORMAL_CACHEABLE},
		{0x00200000, 0x00200000, 0x0FE00000, RZA_MMU_ATTRIBUTE_ACCESS_FAULT    },
		{0x10000000, 0x10000000, 0x10000000, RZA_MMU_ATTRIBUTE_DEVICE          },
		{0x20000000, 0x20000000, 0x10000000, RZA_MMU_ATTRIBUTE_NORMAL_CACHEABLE},
		{0x30000000, 0x30000000, 0x10000000, RZA_MMU_ATTRIBUTE_ACCESS_FAULT    },
		{0x40000000, 0x40000000, 0x40000000, RZA_MMU_ATTRIBUTE_NORMAL_CACHEABLE},
		{0x80000000, 0x80000000, 0x40000000, RZA_MMU_ATTRIBUTE_ACCESS_FAULT    },
		{0xC0000000, 0xC0000000, 0x40000000, RZA_MMU_ATTRIBUTE_ACCESS_FAULT    },
		{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, RZA_MMU_ATTRIBUTE_CONFIG_END      }
	};
#else
	const mmap_region_t bl2_regions[] = {
	/* MMU table for non-RZ/A3UL */
	MAP_REGION_FLAT(BL2_BASE, BL2_END - BL2_BASE,
		MT_MEMORY | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(BL_CODE_BASE, BL_CODE_END - BL_CODE_BASE,
		MT_CODE | MT_SECURE),
	MAP_REGION_FLAT(BL_RO_DATA_BASE, BL_RO_DATA_END - BL_RO_DATA_BASE,
		MT_RO_DATA  | MT_SECURE),
	{0}
	};
#endif /* RZA3 */

#if RZA3
	if (0 != plat_mmu_init(g_mmu_pagetable_array)) {
		panic();
	}
	plat_mmu_enable();

#else
	setup_page_tables(bl2_regions, rzg2l_mmap);
	enable_mmu_el3(0);
#endif
}

void bl2_platform_setup(void)
{
	/* Setup TZC-400, Access Control */
	plat_security_setup();

#if USE_SDRAM
	/* initialize DDR */
	ddr_setup();
#endif /* DEBUG_FPGA */

	rz_io_setup();

	RZ_RUN_TESTS();

#if (APPLOAD == RZ_NOFIP)
	rza_load_fsp();
#endif
	rza_print_descs();
}
