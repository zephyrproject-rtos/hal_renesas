/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <string.h>
#include <assert.h>
#include <DA1469xAB.h>
#include <da1469x_config.h>
#include <zephyr/sys/util.h>
#include <system_DA1469x.h>

enum REMAP_ADDR0 {
	REMAP_ADDR0_ROM = 0x0,
	REMAP_ADDR0_OTP,
	REMAP_ADDR0_QSPIF_CACHED,
	REMAP_ADDR0_SYSRAM,
	REMAP_ADDR0_MAX,
};

uint32_t black_orca_phy_addr(uint32_t addr)
{
	uint32_t remap_addr0;
	uint32_t phy_addr;

	static const uint32_t remap_bases[] = {
		[REMAP_ADDR0_ROM] = MCU_ROM_BASE,
		[REMAP_ADDR0_OTP] = MCU_OTP_M_BASE,
		[REMAP_ADDR0_QSPIF_CACHED] = MCU_QSPIF_M_CACHED_BASE,
		[REMAP_ADDR0_SYSRAM] = MCU_SYSRAM_M_BASE
	};

	static const uint32_t flash_region_sizes[] = {
		MB(32),
		MB(16),
		MB(8),
		MB(4),
		MB(2),
		MB(1),
		KB(512),
		KB(256)
	};

	remap_addr0 = CRG_TOP->SYS_CTRL_REG & CRG_TOP_SYS_CTRL_REG_REMAP_ADR0_Msk;
	assert(remap_addr0 < REMAP_ADDR0_MAX);

	if (remap_addr0 != REMAP_ADDR0_QSPIF_CACHED) {
		if (IS_REMAPPED_ADDRESS(addr)) {
			phy_addr = addr + remap_bases[remap_addr0];
		} else {
			phy_addr = addr;
		}
	} else {
		/* FLASH_REGION_BASE corresponds to Flash region base address bits [31:16] */
		uint32_t flash_region_base = ((CACHE->CACHE_FLASH_REG & CACHE_CACHE_FLASH_REG_FLASH_REGION_BASE_Msk) >>
																CACHE_CACHE_FLASH_REG_FLASH_REGION_BASE_Pos) << 16;
		/* FLASH_REGION_OFFSET corresponds to Flash region base address bits [13:2]. Offset is expressed in words. */
		flash_region_base += ((CACHE->CACHE_FLASH_REG & CACHE_CACHE_FLASH_REG_FLASH_REGION_OFFSET_Msk) >>
														CACHE_CACHE_FLASH_REG_FLASH_REGION_OFFSET_Pos) << 2;
		__unused uint32_t flash_region_size = flash_region_sizes[CACHE->CACHE_FLASH_REG & CACHE_CACHE_FLASH_REG_FLASH_REGION_SIZE_Msk];

		if (IS_REMAPPED_ADDRESS(addr)) {
			assert(addr < flash_region_size);

			phy_addr = addr + flash_region_base;
		} else if (IS_QSPIF_CACHED_ADDRESS(addr)) {
			assert(addr >= flash_region_base && addr < (flash_region_base + flash_region_size));

			phy_addr = addr;
		} else {
			phy_addr = addr;
		}
	}

	return phy_addr;
}