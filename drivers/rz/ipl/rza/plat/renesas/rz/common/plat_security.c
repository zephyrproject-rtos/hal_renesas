/*
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <drivers/arm/tzc400.h>
#include <lib/mmio.h>
#include <common/debug.h>

#include "rzg2l_def.h"
#include "sys_regs.h"
#include "plat_tzc_def.h"
#include "rza_printf.h"

typedef struct arm_tzc_regions_info {
	unsigned long long base;
	unsigned long long end;
	unsigned int sec_attr;
	unsigned int nsaid_permissions;
} arm_tzc_regions_info_t;


static const struct {
	uint32_t reg;
	uint32_t msk;
	uint32_t val;
} sys_acctl[] = {
	/* Master Access Control Register */
	{SYS_MSTACCCTL0,  0x00BB00BBU, 0x00AAAA88U},
	{SYS_MSTACCCTL1,  0xBBBBBBBBU, 0xAAAAAAAAU},
	{SYS_MSTACCCTL2,  0x00BBBBBBU, 0x00AAAAAAU},
	{SYS_MSTACCCTL3,  0x00BBBBBBU, 0x00AAAAAAU},
	{SYS_MSTACCCTL4,  0x0B0B00BBU, 0x0A0A00AAU},
	{SYS_MSTACCCTL5,  0x00000000U, 0x00000000U},
	/* Slave Access Control Register */
	{SYS_SLVACCCTL0,  0x0000000FU, 0x00000008U},
	{SYS_SLVACCCTL1,  0x3FFF3CFFU, 0x0800C0AAU},
	{SYS_SLVACCCTL2,  0x00FFCFFFU, 0x00000002U},
	{SYS_SLVACCCTL3,  0x3FFF3FFFU, 0x00000000U},
	{SYS_SLVACCCTL4,  0xFFFF0FFFU, 0x00000000U},
	{SYS_SLVACCCTL5,  0x00000033U, 0x00000000U},
	{SYS_SLVACCCTL6,  0x0000000FU, 0x00000000U},
	{SYS_SLVACCCTL7,  0x0000000CU, 0x00000008U},
	{SYS_SLVACCCTL8,  0x0000000FU, 0x00000000U},
	{SYS_SLVACCCTL9,  0x00000000U, 0x00000000U},
	{SYS_SLVACCCTL10, 0x00000003U, 0x00000000U},
	{SYS_SLVACCCTL11, 0x00000000U, 0x00000000U},
	{SYS_SLVACCCTL12, 0x00000003U, 0x00000000U},
	{SYS_SLVACCCTL13, 0x00000003U, 0x00000000U},
	{SYS_SLVACCCTL14, 0x00000003U, 0x00000000U},
	{SYS_SLVACCCTL15, 0x00000000U, 0x00000000U},
};

void plat_access_control_setup(void)
{
	uint32_t i;

	for (i = 0; i < ARRAY_SIZE(sys_acctl); i++)
	{
		uint32_t val = mmio_read_32(sys_acctl[i].reg) & (~sys_acctl[i].msk);
		val |= (sys_acctl[i].val & sys_acctl[i].msk);
		mmio_write_32(sys_acctl[i].reg, val);
	}
}

uint8_t tzc400_get_num_filters(uintptr_t tzc_base)
{
	uint32_t tzc400_build;

	tzc400_build = mmio_read_32(tzc_base + BUILD_CONFIG_OFF);

	return (uint8_t)((tzc400_build >> BUILD_CONFIG_NF_SHIFT) & BUILD_CONFIG_NF_MASK) + 1U;
}

void plat_tzc400_setup(uintptr_t tzc_base, const arm_tzc_regions_info_t *tzc_regions)
{
	uint8_t num_filters;
	unsigned int region_index = 1U;
	const arm_tzc_regions_info_t *p;
	const arm_tzc_regions_info_t init_tzc_regions[] = {
		{0}
	};

	INFO("Configuring TrustZone Controller\n");

	tzc400_init(tzc_base);

	tzc400_disable_filters();

	tzc400_configure_region0(TZC_REGION_S_RDWR, PLAT_TZC_REGION_ACCESS_NS_UNPRIV);

	if (tzc_regions == NULL)
		p = init_tzc_regions;
	else
		p = tzc_regions;

	num_filters = tzc400_get_num_filters(tzc_base);

	for (; p->base != 0UL; p++) {
		tzc400_configure_region((1 << num_filters) - 1, region_index,
			p->base, p->end, p->sec_attr, p->nsaid_permissions);
		region_index++;
	}

	INFO("Total %u regions set.\n", region_index);

	tzc400_set_action(TZC_ACTION_ERR);

	tzc400_enable_filters();
}

#if IMAGE_BL2
static void bl2_security_setup(void)
{
	const arm_tzc_regions_info_t ddr_tzc_regions[] = {
#ifndef RZA3
#if TRUSTED_BOARD_BOOT
		/* security for BL31 and OP-TEE */
		{PLAT_FW_TZC_PROT_DRAM1_BASE, PLAT_FW_TZC_PROT_DRAM1_END,
			TZC_REGION_S_RDWR, PLAT_TZC_REGION_ACCESS_S_UNPRIV},
		{PLAT_TEE_TZC_PROT_DRAM1_BASE, PLAT_TEE_TZC_PROT_DRAM1_END,
			TZC_REGION_S_RDWR,  PLAT_TZC_REGION_ACCESS_S_UNPRIV},
#endif /* TRUSTED_BOARD_BOOT */
		{}
#else
		{0}
#endif
	};

	/* initialize TZC-400 */
	plat_tzc400_setup(RZG2L_TZC_DDR_BASE, &ddr_tzc_regions[0]);
	plat_tzc400_setup(RZG2L_TZC_SPI_BASE, NULL);

	/* setup Master/Slave Access Control */
	plat_access_control_setup();
}
#endif

#if IMAGE_BL31
static void bl31_security_setup(void)
{
	const arm_tzc_regions_info_t msram_tzc_regions[] = {
#if TRUSTED_BOARD_BOOT
		{ PLAT_AP_TZC_PROT_SRAM1_BASE, PLAT_AP_TZC_PROT_SRAM1_END,
			TZC_REGION_S_RDWR, PLAT_TZC_REGION_ACCESS_S_UNPRIV },
#endif /* TRUSTED_BOARD_BOOT */
		{}
	};

	const arm_tzc_regions_info_t asram_tzc_regions[] = {
#if TRUSTED_BOARD_BOOT
		{ PLAT_AP_TZC_PROT_SRAM2_BASE, PLAT_AP_TZC_PROT_SRAM2_END,
			TZC_REGION_S_RDWR, PLAT_TZC_REGION_ACCESS_S_UNPRIV },
#endif /* TRUSTED_BOARD_BOOT */
		{}
	};
	
	/* Additional settings for TZC-400 SRAM */
	plat_tzc400_setup(RZG2L_TZC_MSRAM_BASE, &msram_tzc_regions[0]);
	plat_tzc400_setup(RZG2L_TZC_ASRAM_BASE, &asram_tzc_regions[0]);
}
#endif

void plat_security_setup(void)
{
#if IMAGE_BL2
	bl2_security_setup();
#endif

#if IMAGE_BL31
	bl31_security_setup();
#endif
}
