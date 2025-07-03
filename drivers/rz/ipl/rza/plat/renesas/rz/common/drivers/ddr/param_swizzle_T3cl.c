/*
 * Copyright (c) 2020-2022, Renesas Electronics Corporation. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 * This code was generated with RZ/G2L, G2UL, Five, A3UL DDR config generation tool v3.0.0
 */

#include <stdint.h>
#include <ddr_internal.h>

const uint32_t mc_odt_pins_tbl[4] = {
	0x00000002	,
	0x00000001	,
	0x00000002	,
	0x00000001
};

const uint32_t mc_mr1_tbl[2] = {
	0x00000266	,
	0x00000206
};

const uint32_t mc_mr2_tbl[2] = {
	0x00000600	,
	0x00000200
};

const uint32_t mc_mr5_tbl[2] = {
	0x00000000	,
	0x00000000
};

const uint32_t mc_mr6_tbl[2] = {
	0x00000000	,
	0x00000000
};

const uint32_t mc_phy_settings_tbl[MC_PHYSET_NUM][2] = {
	{DDRMC_R040,	0x4F7F01E8	},
	{DDRMC_R041,	0x00007822	},
	{DDRMC_R042,	0x1E1E3C22	},
	{DDRMC_R043,	0x00000000	}
};

const uint32_t swizzle_mc_tbl[SWIZZLE_MC_NUM][2] = {
	{DDRMC_R030,	0x00000A00	},
	{DDRMC_R031,	0x00001E00	},
	{DDRMC_R032,	0x1D131500	},
	{DDRMC_R033,	0x00001217	},
	{DDRMC_R034,	0x180E2000	},
	{DDRMC_R035,	0x0D1F0B1B	},
	{DDRMC_R036,	0x021A1400	},
	{DDRMC_R037,	0x0C1C0616	},
	{DDRMC_R038,	0x00000000	}
};

const uint32_t swizzle_phy_tbl[SIZZLE_PHY_NUM][2] = {
	{DDRPHY_R29,	0x00000000	},
	{DDRPHY_R11,	0x19081815	},
	{DDRPHY_R29,	0x00000001	},
	{DDRPHY_R11,	0x0702140B	},
	{DDRPHY_R29,	0x00000002	},
	{DDRPHY_R11,	0x170D0309	},
	{DDRPHY_R29,	0x00000003	},
	{DDRPHY_R11,	0x0F00051D	},
	{DDRPHY_R29,	0x00000004	},
	{DDRPHY_R11,	0x13121110	},
	{DDRPHY_R29,	0x00000005	},
	{DDRPHY_R11,	0x0E160106	},
	{DDRPHY_R29,	0x00000006	},
	{DDRPHY_R11,	0x0A1A1B04	},
	{DDRPHY_R29,	0x00000007	},
	{DDRPHY_R11,	0x001E0C1C	}
};
