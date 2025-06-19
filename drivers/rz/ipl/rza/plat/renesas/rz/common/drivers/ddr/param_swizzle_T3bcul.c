/*
 * Copyright (c) 2020-2022, Renesas Electronics Corporation. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 * This code was generated with RZ/G2L, G2UL, Five, A3UL DDR config generation tool v3.0.0
 */

#include <stdint.h>
#include <ddr_internal.h>

const uint32_t mc_odt_pins_tbl[4] = {
	0x00000001	,
	0x00000000	,
	0x00000000	,
	0x00000000
};

const uint32_t mc_mr1_tbl[2] = {
	0x00000266	,
	0x00000006
};

const uint32_t mc_mr2_tbl[2] = {
	0x00000600	,
	0x00000000
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
	{DDRMC_R040,	0x4F7F06E8	},
	{DDRMC_R041,	0x00002822	},
	{DDRMC_R042,	0x00003C22	},
	{DDRMC_R043,	0x00000000	}
};

const uint32_t swizzle_mc_tbl[SWIZZLE_MC_NUM][2] = {
	{DDRMC_R030,	0x00000000	},
	{DDRMC_R031,	0x00000000	},
	{DDRMC_R032,	0x151A2100	},
	{DDRMC_R033,	0x00200014	},
	{DDRMC_R034,	0x1F1E1900	},
	{DDRMC_R035,	0x000B120C	},
	{DDRMC_R036,	0x000A1B17	},
	{DDRMC_R037,	0x161D0F13	},
	{DDRMC_R038,	0x0000000D	}
};

const uint32_t swizzle_phy_tbl[SIZZLE_PHY_NUM][2] = {
	{DDRPHY_R29,	0x00000000	},
	{DDRPHY_R11,	0x17140B04	},
	{DDRPHY_R29,	0x00000001	},
	{DDRPHY_R11,	0x0006070E	},
	{DDRPHY_R29,	0x00000002	},
	{DDRPHY_R11,	0x0D0A0818	},
	{DDRPHY_R29,	0x00000003	},
	{DDRPHY_R11,	0x19160201	},
	{DDRPHY_R29,	0x00000004	},
	{DDRPHY_R11,	0x13121110	},
	{DDRPHY_R29,	0x00000005	},
	{DDRPHY_R11,	0x030C150F	},
	{DDRPHY_R29,	0x00000006	},
	{DDRPHY_R11,	0x1B1A0905	},
	{DDRPHY_R29,	0x00000007	},
	{DDRPHY_R11,	0x001E1D1C	}
};
