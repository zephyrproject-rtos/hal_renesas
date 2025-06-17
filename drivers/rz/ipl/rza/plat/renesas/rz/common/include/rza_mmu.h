/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _RZA_MMU_H_
#define _RZA_MMU_H_

#include "platform_def.h"

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* descripter bits define */
#define RZA_MMU_DESC_XN			(1 << 54)
#define RZA_MMU_DESC_PXN			(1 << 53)
#define RZA_MMU_DESC_AF			(1 << 10)
#define RZA_MMU_DESC_SH_NS		(0 <<  8)
#define RZA_MMU_DESC_SH_OS		(2 <<  8)
#define RZA_MMU_DESC_SH_IS		(3 <<  8)
#define RZA_MMU_DESC_AP_RW_NONE		(0 <<  6)
#define RZA_MMU_DESC_AP_RW_RW		(1 <<  6)
#define RZA_MMU_DESC_AP_RO_NONE		(2 <<  6)
#define RZA_MMU_DESC_AP_RO_RO		(3 <<  6)
#define RZA_MMU_DESC_NS			(1 <<  5)

/* descripter index for MAIR register */
#define RZA_MMU_DESC_MAIR_INDEX_0	(0 << 2)
#define RZA_MMU_DESC_MAIR_INDEX_1	(1 << 2)
#define RZA_MMU_DESC_MAIR_INDEX_2	(2 << 2)
#define RZA_MMU_DESC_MAIR_INDEX_3	(3 << 2)
#define RZA_MMU_DESC_MAIR_INDEX_4	(4 << 2)
#define RZA_MMU_DESC_MAIR_INDEX_5	(5 << 2)
#define RZA_MMU_DESC_MAIR_INDEX_6	(6 << 2)
#define RZA_MMU_DESC_MAIR_INDEX_7	(7 << 2)

/* index number each memory type */
/* 0: normal memory, cacheable
   1: device 
   2: normal memory, non-cacheable */
#define RZA_MMU_ATTR_NON_CACHEABLE_INDEX		(2)
#define RZA_MMU_ATTR_DEVICE_INDEX		(1)
#define RZA_MMU_ATTR_IWBWA_OWBWA_NTR_INDEX	(0)

/* Normal Memory, Outer/Inner Non-cacheable */
#define RZA_MMU_ATTR_NON_CACHEABLE		MAKE_MAIR_NORMAL_MEMORY(MAIR_NORM_NC, MAIR_NORM_NC)
/* Device */
#define RZA_MMU_ATTR_DEVICE			MAIR_DEV_nGnRE
/* Normal Memory, Outer/Inner Write-Back */
#define RZA_MMU_ATTR_IWBWA_OWBWA_NTR		MAKE_MAIR_NORMAL_MEMORY(MAIR_NORM_WB_NTR_RWA, MAIR_NORM_WB_NTR_RWA)

#define RZA_MMU_ATTR_FIELD_WIDTH			(8)
#define RZA_MMU_MAIR_ATTR_SET(attr, index)	((attr) << ((index) * RZA_MMU_ATTR_FIELD_WIDTH))

#define RZA_MMU_ATTR_NEXT_TBL			(0x03)

/* descripter entry type */
#define RZA_MMU_DESC_TABLE_DESC			(3 << 0)
#define RZA_MMU_DESC_BLOCK_ENTRY_L12		(1 << 0)
#define RZA_MMU_DESC_BLOCK_ENTRY_L3		(3 << 0)

/* max address */
#define RZA_MMU_PHY_ADDR_MAX			(PLAT_PHY_ADDR_SPACE_SIZE - 1)
#define RZA_MMU_VIRT_ADDR_MAX			(PLAT_VIRT_ADDR_SPACE_SIZE - 1)
#define RZA_MMU_PHY_SIZE_MAX			(PLAT_PHY_ADDR_SPACE_SIZE)
#define RZA_MMU_VIRT_SIZE_MAX			(PLAT_VIRT_ADDR_SPACE_SIZE)

/* exception evel */
#define RZA_MMU_CURRENT_EL0			(0x00)
#define RZA_MMU_CURRENT_EL1			(0x04)
#define RZA_MMU_CURRENT_EL2			(0x08)
#define RZA_MMU_CURRENT_EL3			(0x0C)

/* Virtual space size per entry each level */
#define RZA_MMU_L1_ENTRY_SIZE			(0x40000000) /* 1GB */
#define RZA_MMU_L2_ENTRY_SIZE			(0x00200000) /* 2MB */
#define RZA_MMU_L3_ENTRY_SIZE			(0x00001000) /* 4KB */

/* descripter size (byte) */
#define RZA_MMU_TABLE_DESC_SIZE			(8)

/* start virtual address each blocks */
#define RZA_MMU_N1_TABLE_START_VADDR		(0x00000000)
#define RZA_MMU_N2_TABLE_START_VADDR		(0x40000000)
#define RZA_MMU_N3_TABLE_START_VADDR		(0x80000000)
#define RZA_MMU_N4_TABLE_START_VADDR		(0xC0000000)

/* width of virtual space each blocks */
#define RZA_MMU_TTB_BLOCK_WIDTH			(0x40000000)

#define RZA_MMU_LEVEL2_TABLE_INDEX_MAX		(4)
#define RZA_MMU_TABLE_ENTRY			(512)

/* MMU attribute setting (user setting) */
#define RZA_MMU_ATTRIBUTE_NORMAL_CACHEABLE	(RZA_MMU_DESC_AF | RZA_MMU_DESC_SH_IS | RZA_MMU_DESC_AP_RW_RW | \
						RZA_MMU_DESC_MAIR_INDEX_0)
#define RZA_MMU_ATTRIBUTE_NORMAL_UNCACHE		(RZA_MMU_DESC_AF | RZA_MMU_DESC_SH_IS | RZA_MMU_DESC_AP_RW_RW | \
						RZA_MMU_DESC_MAIR_INDEX_2)
#define RZA_MMU_ATTRIBUTE_DEVICE			(RZA_MMU_DESC_AF | RZA_MMU_DESC_SH_IS | RZA_MMU_DESC_AP_RW_RW | \
						RZA_MMU_DESC_MAIR_INDEX_1)
#define RZA_MMU_ATTRIBUTE_ACCESS_FAULT		(0x00000000)
#define RZA_MMU_ATTRIBUTE_CONFIG_END		(0xFFFFFFFF)

/* xSPI device extended configuration structure */
typedef struct mmu_pagetable_config
{
	uint64_t vaddress;
	uint64_t paddress;
	uint64_t size;
	uint64_t attribute;
} rza_mmu_pgtbl_cfg_t;

/* external functions */
int  plat_mmu_init(const rza_mmu_pgtbl_cfg_t *config_table);
void plat_mmu_enable(void);

#endif  /* _RZA_MMU_H_ */
