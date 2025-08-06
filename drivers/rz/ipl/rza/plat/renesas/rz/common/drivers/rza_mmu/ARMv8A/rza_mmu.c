/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdbool.h>

#include <assert.h>
#include <common/debug.h>

#include <arch_helpers.h>
#include <rza_mmu.h>

static int rz_mmu_check_tbl(const rza_mmu_pgtbl_cfg_t *config_table);
static void rz_mmu_write_tbl(const rza_mmu_pgtbl_cfg_t *config_table);
static void rz_mmu_write_ttbr0_el3(const uint64_t addr);
static void rz_mmu_write_mair_el3(const uint64_t mair);
static void rz_mmu_write_tcr_el3(const uint64_t tcr);
static uint32_t rz_mmu_get_current_el(void);

/* MMU allocation area */
uint64_t __attribute__ ((section("base_xlat_table"))) mmu_level1_table[RZA_MMU_LEVEL2_TABLE_INDEX_MAX];
uint64_t __attribute__ ((section("xlat_table"), aligned(0x1000))) mmu_level2_table[RZA_MMU_TABLE_ENTRY * RZA_MMU_LEVEL2_TABLE_INDEX_MAX];
uint64_t level2_table[RZA_MMU_LEVEL2_TABLE_INDEX_MAX];

int plat_mmu_init(const rza_mmu_pgtbl_cfg_t *config_table)
{
	int       ret;
	int       index;
	uint64_t  mair;
	uint64_t  tcr;
	int       t0sz;
	uintptr_t virtual_addr_space_size;

	ret = rz_mmu_check_tbl(config_table);
    
	if (0 == ret) {
		/* get the start address for each Level2 MMU table entry */
		for (index = 0; index < RZA_MMU_LEVEL2_TABLE_INDEX_MAX; index++) {
			level2_table[index] = (uint64_t)&mmu_level2_table[RZA_MMU_TABLE_ENTRY * index];
		}
        
		/* Set the address of the level 2 MMU table in the level 1 MMU table */
		for (index = 0; index < RZA_MMU_LEVEL2_TABLE_INDEX_MAX; index++) {
			*((uint64_t *) &mmu_level1_table[index]) = (level2_table[index] | RZA_MMU_ATTR_NEXT_TBL);
		}
        
		rz_mmu_write_tbl(config_table);
            
		/* create a pattern of attributes to set in the MAIR register */
		mair = RZA_MMU_MAIR_ATTR_SET(RZA_MMU_ATTR_DEVICE, RZA_MMU_ATTR_DEVICE_INDEX);
		mair |= RZA_MMU_MAIR_ATTR_SET(RZA_MMU_ATTR_IWBWA_OWBWA_NTR, RZA_MMU_ATTR_IWBWA_OWBWA_NTR_INDEX);
		mair |= RZA_MMU_MAIR_ATTR_SET(RZA_MMU_ATTR_NON_CACHEABLE, RZA_MMU_ATTR_NON_CACHEABLE_INDEX);
            
		/* create TTB operation settings to set in TCR register */
		tcr = TCR_EL3_RES1;
            
		virtual_addr_space_size = (uintptr_t)RZA_MMU_VIRT_SIZE_MAX;
            
		t0sz = 64 - __builtin_ctzll(virtual_addr_space_size);
    
		tcr |= (uint64_t)t0sz << TCR_T0SZ_SHIFT;
            
		/* TTB cache enable */
		tcr |= (TCR_SH_INNER_SHAREABLE | TCR_RGN_OUTER_WBA | TCR_RGN_INNER_WBA);
                        
		/* address range check */
		if ((RZA_MMU_PHY_ADDR_MAX & ADDR_MASK_40_TO_41) != 0U) {
			tcr |= TCR_PS_BITS_4TB << TCR_EL3_PS_SHIFT; /* 42bit */
		}
		else if ((RZA_MMU_PHY_ADDR_MAX & ADDR_MASK_36_TO_39) != 0U) {
			tcr |= TCR_PS_BITS_1TB << TCR_EL3_PS_SHIFT; /* 40bit */
		}
		/* 36 bits address */
		else if ((RZA_MMU_PHY_ADDR_MAX & ADDR_MASK_32_TO_35) != 0U) {
			tcr|= TCR_PS_BITS_64GB << TCR_EL3_PS_SHIFT; /* 36 bit */
		}
		/* 32bits address */
		else {
			tcr|= TCR_PS_BITS_4GB << TCR_EL3_PS_SHIFT; /* 32 bit */
		}
        
		__asm__ volatile ("tlbi alle3\n");
            
		rz_mmu_write_mair_el3(mair);
            
		rz_mmu_write_tcr_el3(tcr);
        
		rz_mmu_write_ttbr0_el3(((uint64_t)mmu_level1_table | TTBR_CNP_BIT));
	}
    
	return ret;
}

void plat_mmu_enable(void)
{   
	/* set MMU and data cache enable, Disable the function to forcibly 
	   set the execute-never attribute when setting the writable memory */
	__asm__ volatile (
		".equ SCTLR_C,    (1 << 2)\n"
		".equ SCTLR_M,    (1 << 0)\n"
		".equ SCTLR_WXN,  (1 << 19)\n"
        
		"dsb ish\n"
		"isb\n"
		"mrs x0, SCTLR_EL3\n"
		"mov x1, #(SCTLR_C | SCTLR_M)\n"
		"orr x0, x0, x1\n"
		"bic x0, x0, SCTLR_WXN\n"
		"msr SCTLR_EL3, x0\n"
		"isb\n"
		:
		:
		: "x0", "x1"
	);
    
	return;
}

int rz_mmu_check_tbl(const rza_mmu_pgtbl_cfg_t *config_table)
{
	int ret = 0;
	int index;
	uint32_t current_el;
    
	current_el = rz_mmu_get_current_el();
	if (RZA_MMU_CURRENT_EL3 == current_el) {
		for (index = 0; ((0 == ret) && (RZA_MMU_ATTRIBUTE_CONFIG_END != config_table[index].attribute)); index++) {
			if ((config_table[index].vaddress % RZA_MMU_L2_ENTRY_SIZE) != 0) {
				ret = -1;
			}
			
			if ((config_table[index].paddress %  RZA_MMU_L2_ENTRY_SIZE) != 0) {
				ret = -1;
			}
			
			if ((config_table[index].size % RZA_MMU_L2_ENTRY_SIZE) != 0) {
				ret = -1;
			}
			
			if (RZA_MMU_PHY_SIZE_MAX < (uint64_t)(config_table[index].paddress + config_table[index].size)) {
				ret = -1;
			}
			
			if (RZA_MMU_VIRT_SIZE_MAX < (uint64_t)(config_table[index].vaddress + config_table[index].size)) {
				ret = -1;
			}
		}
	}
	else {
		ret = -1;
	}
    
	return ret;
}

void rz_mmu_write_tbl(const rza_mmu_pgtbl_cfg_t *config_table)
{
	int        desc;
	int        num_of_desc;
	int        ttb_index;
	int        ttb_num;
	int        index;
	uint64_t   *desc_ptr;
	uint64_t   paddress;
	uint64_t   ttb_base_ptr;
	uint64_t   ttb_start_vaddr;
	uint64_t   attribute;
    
	for (index = 0; RZA_MMU_ATTRIBUTE_CONFIG_END != config_table[index].attribute; index++)
	{
		/************** serach TTB address, index, number of desctiptor from config_table parameters **************
		Example of config_table[index].vaddress = 0x0040000, config_table[index].size = 0x00600000
		
                                                                                   TTB
		                                                  | ...                             | +
		                                                  |---------------------------------| | TTB1
		                                                  | Vaddress:0x40200000, ttb_index1 | | 512entry descriptor
		                                                  |---------------------------------| | 1descriptor = 8byte
		ttb_start_vaddr1(0x40000000)----------------------->Vaddress:0x40000000, ttb_index0 | +
		ttb_base_ptr1(=&mmu_level2_table[1])------------->|---------------------------------|
		                                                  | ...                             | +
		                                                  |                                 | |
		                                                  | ...                             | |
		                                                  |---------------------------------| |
		                                                + | Vaddress:0x00800000, ttb_index4 | | TTB0
		                         target descriptor      | |---------------------------------| | 512entry descriptor
		                         num_of_desc (=3entry)  | | Vaddress:0x00600000, ttb_index3 | | 1descriptor = 8byte
		                                                | |---------------------------------| |
		                                                + | Vaddress:0x00400000, ttb_index2 | |
		desc_ptr((=&mmu_level2_table[0]) + (8byte * 2))-->|---------------------------------| |
		                                                  | Vaddress:0x00200000, ttb_index1 | |
		                                                  |---------------------------------| |
		ttb_start_vaddr0(=0x00000000)---------------------->Vaddress:0x00000000, ttb_index0 | +
		ttb_base_ptr0(=&mmu_level2_table[0])------------->|---------------------------------| 
		
		**********************************************************************************************************/
		
		/* get target TTB block number 
		   RZA_MMU_TTB_BLOCK_WIDTH is TTB block width(0x40000000) */
		ttb_num = config_table[index].vaddress / RZA_MMU_TTB_BLOCK_WIDTH;
		/* get target TTB block pointer */
		ttb_base_ptr = (uint64_t)&mmu_level2_table[RZA_MMU_TABLE_ENTRY * ttb_num];
		/* get first virtual address on target TTB block */
		ttb_start_vaddr = RZA_MMU_TTB_BLOCK_WIDTH * ttb_num;
		
		/* get number of descriptor for setting attribute 
		   RZA_MMU_L2_ENTRY_SIZE is virtual address entry size per descriptor */
		num_of_desc = config_table[index].size / RZA_MMU_L2_ENTRY_SIZE;
		/* get index of descriptor for setting attribute */
		ttb_index = (config_table[index].vaddress - ttb_start_vaddr) / RZA_MMU_L2_ENTRY_SIZE;
		/* get pointer of descriptor */
		desc_ptr = (uint64_t *) (ttb_base_ptr + (ttb_index * RZA_MMU_TABLE_DESC_SIZE));

		/* set attribute to descriptor */
		if (RZA_MMU_ATTRIBUTE_ACCESS_FAULT != config_table[index].attribute) {
			attribute = (config_table[index].attribute | RZA_MMU_DESC_BLOCK_ENTRY_L12);
			paddress = config_table[index].paddress;
			for (desc = 0; desc < num_of_desc; desc++) {
				*desc_ptr++ = paddress | attribute;
				paddress += RZA_MMU_L2_ENTRY_SIZE;
			}
		}
		else {
			for (desc = 0; desc < num_of_desc; desc++) {
				*desc_ptr++ = 0;
			}
		}
	}

	return;
}

void rz_mmu_write_ttbr0_el3(const uint64_t addr)
{
	__asm__ volatile (
		"msr TTBR0_EL3, %0\n"
		:
		: "r"(addr)
		:
	);
	
	return;
}

void rz_mmu_write_mair_el3(const uint64_t mair)
{
	__asm__ volatile (
		"msr MAIR_EL3, %0\n"
		:
		: "r"(mair)
		:
	);
	
	return;
}

void rz_mmu_write_tcr_el3(const uint64_t tcr)
{
	__asm__ volatile (
		"msr TCR_EL3, %0\n"
		:
		: "r"(tcr)
		:
	);
	
	return;
}

uint32_t rz_mmu_get_current_el(void)
{
	uint32_t current_el;
	
	__asm__ volatile (
		"mrs %0, CurrentEL\n"
		: "=r"(current_el)
		:
		:
	);
	
	return current_el;
}

