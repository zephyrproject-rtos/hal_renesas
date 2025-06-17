/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>

#include <common/debug.h>
#include <arch_helpers.h>
#include <common/desc_image_load.h>
#include <rzg2l_def.h>
#include <platform_def.h>
#include <arch.h>
#include <rza_printf.h>
#include <xspi_api.h>

#if (APPLOAD == RZ_NOFIP)
#define FSP_FROM_XSPI_BASE (FSP_BASE - RZA3_XSPI_MEMORY_BASE)
typedef struct fsp_app_header {
	uint64_t entry_addr;
	uint64_t entry_addr_inv;
	uint64_t dest_addr;
	uint64_t dest_addr_inv;
	uint64_t payload_size;
	uint64_t payload_size_inv;
	uint8_t padding[432];
	uint8_t signature[32];
	uint8_t app_payload_start;
} fsp_app_header_t;
#endif /* (APPLOAD == RZ_NOFIP) */

bl_load_info_t *plat_get_bl_image_load_info(void)
{
	return get_bl_load_info_from_mem_params_desc();
}

bl_params_t *plat_get_next_bl_params(void)
{
	return get_next_bl_params_from_mem_params_desc();
}


void plat_flush_next_bl_params(void)
{
}

#if (APPLOAD == RZ_NOFIP)
int  rz_check_fsp_header(fsp_app_header_t *header)
{
	int ret = 0;

	RZA_PRINTF_VERBOSE("Check Application Header...\n");
	if (~(header->entry_addr) != header->entry_addr_inv) {
		ret = -1;
		ERROR("The value of the entry point address does not match its inverted value\n");
	}

	if (0 == ret) {
		if (~(header->dest_addr) != header->dest_addr_inv) {
			ret = -1;
			ERROR("The address to copy application image does not match its inverted value\n");
		}
	}

	if (0 == ret) {
		if (~(header->payload_size) != header->payload_size_inv)
		{
			ret = -1;
			ERROR("The size of application image does not match its inverted value\n");
		}
	}

	if ((FSP_BASE + RZ_APP_PAYLOAD_OFFSET) != header->dest_addr) {
		if (0 == ret) {
			if ((header->dest_addr < RZG2L_SRAM_BASE) ||
				((header->dest_addr + header->payload_size)> (RZG2L_SRAM_BASE + RZG2L_SRAM_SIZE))) {
				if ((header->dest_addr < RZG2L_SPIROM_BASE) ||
					((header->dest_addr + header->payload_size)> (RZG2L_SPIROM_BASE + RZG2L_SPIROM_SIZE))) {
					if ((header->dest_addr < RZG2L_DDR1_BASE) ||
						((header->dest_addr + header->payload_size) > (RZG2L_DDR1_BASE + RZG2L_DDR1_SIZE + RZG2L_DDR2_SIZE))) {
						ret = -1;
						ERROR("The application image to copy does not fit in memory\n");
					}
				}
			}
		}
	}

	if (0 == ret) {
		RZA_PRINTF_VERBOSE("Success!\n");
	}

	return ret;
}


void rz_update_descs(fsp_app_header_t *header)
{
	bl_params_t *bl2_params;

	bl2_params = plat_get_next_bl_params();

	bl2_params->head->image_info->image_base = (uintptr_t)header->dest_addr;
	bl2_params->head->image_info->image_max_size = header->payload_size;
	bl2_params->head->image_info->h.attr |= IMAGE_ATTRIB_SKIP_LOADING;
	bl2_params->head->ep_info->pc = (uintptr_t)header->entry_addr;
	flush_bl_params_desc();

	return;
}

static fsp_app_header_t header_impl;
void rza_load_fsp(void)
{
	int ret = 0;
	fsp_app_header_t *header;

    header = &header_impl;

	rz_xspi_read(header, FSP_FROM_XSPI_BASE, sizeof(*header));

	ret = rz_check_fsp_header(header);

	if (0 == ret) {
		if ((FSP_BASE + RZ_APP_PAYLOAD_OFFSET) != header->dest_addr) {
			rz_xspi_read((void*)header->dest_addr, RZ_APP_PAYLOAD_OFFSET + FSP_FROM_XSPI_BASE, (size_t)header->payload_size);
			flush_dcache_range((uintptr_t)(header->dest_addr), header->payload_size);
		}
		rz_update_descs(header);
	} else {
		panic();
	}

	return;
}
#endif /* (APPLOAD == RZ_NOFIP) */

void rza_print_descs(void)
{
	bl_params_t *bl2_params;

	bl2_params = plat_get_next_bl_params();

	/* In the case of release build, bl2_params isn't used */
	RZ_UNUSED_PARAM(bl2_params);
	RZA_PRINTF_VERBOSE("Address to copy the application: 0x%08llx\n", (uint64_t)bl2_params->head->image_info->image_base);
	RZA_PRINTF_VERBOSE("Entry Point Address: 0x%08llx\n", (uint64_t)bl2_params->head->ep_info->pc);
	RZA_PRINTF_VERBOSE("Copy Data Size: %dbyte\n", bl2_params->head->image_info->image_max_size);
	RZA_PRINTF_VERBOSE("SPSR_EL3 settings:\n");
	if (MODE_RW_64 == GET_RW(bl2_params->head->ep_info->spsr)) {
		RZA_PRINTF_VERBOSE("AArch64 execution state\n");
	} else {
		RZA_PRINTF_VERBOSE("AArch32 execution state\n");
	}

	if (0 != ((bl2_params->head->ep_info->spsr >> SPSR_DAIF_SHIFT) & DAIF_DBG_BIT)) {
		RZA_PRINTF_VERBOSE("Debug exception enable\n");
	}

	if (0 != ((bl2_params->head->ep_info->spsr >> SPSR_DAIF_SHIFT) & DAIF_ABT_BIT)) {
		RZA_PRINTF_VERBOSE("SError interrupt enable\n");
	}

	if (0 != ((bl2_params->head->ep_info->spsr >> SPSR_DAIF_SHIFT) & DAIF_IRQ_BIT)) {
		RZA_PRINTF_VERBOSE("IRQ interrupt enable\n");
	}

	if (0 != ((bl2_params->head->ep_info->spsr >> SPSR_DAIF_SHIFT) & DAIF_FIQ_BIT)) {
		RZA_PRINTF_VERBOSE("FIQ interrupt enable\n");
	}

	RZA_PRINTF_VERBOSE("EL and stack pointer: ");
	RZA_PRINTF_VERBOSE("EL%d", GET_EL(bl2_params->head->ep_info->spsr));
	if (MODE_SP_EL0 == GET_SP(bl2_params->head->ep_info->spsr)) {
		RZA_PRINTF_VERBOSE("t\n");
	} else {
		RZA_PRINTF_VERBOSE("h\n");
	}

	RZA_PRINTF("Jump to Application\n");

	return;
}
