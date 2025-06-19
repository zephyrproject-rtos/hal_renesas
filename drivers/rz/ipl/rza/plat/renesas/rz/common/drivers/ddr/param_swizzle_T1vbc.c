/*
 * Copyright (c) 2020-2022, Renesas Electronics Corporation. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 * This code was generated with RZ/V2L DDR config generation tool v1.13.0
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
	0x00000706	,
	0x00000100
};

const uint32_t mc_mr2_tbl[2] = {
	0x00000E00	,
	0x00000000
};

const uint32_t mc_mr5_tbl[2] = {
	0x000001C0	,
	0x000001C0
};

const uint32_t mc_mr6_tbl[2] = {
	0x0000007F	,
	0x0000000F
};

const uint32_t mc_phy_settings_tbl[MC_PHYSET_NUM][2] = {
	{DDRMC_R040,	0x57630BB8	},
	{DDRMC_R041,	0x00002828	},
	{DDRMC_R042,	0x00003C22	},
	{DDRMC_R043,	0x00102611	}
};

const uint32_t swizzle_mc_tbl[SWIZZLE_MC_NUM][2] = {
	{DDRMC_R030,	0x00000B02	},
	{DDRMC_R031,	0x00000106	},
	{DDRMC_R032,	0x11131C0D	},
	{DDRMC_R033,	0x12001F15	},
	{DDRMC_R034,	0x1D19140E	},
	{DDRMC_R035,	0x17091B1A	},
	{DDRMC_R036,	0x0A10160C	},
	{DDRMC_R037,	0x0018051E	},
	{DDRMC_R038,	0x00000000	}
};

const uint32_t swizzle_phy_tbl[SIZZLE_PHY_NUM][2] = {
	{DDRPHY_R29,	0x00000000	},
	{DDRPHY_R11,	0x14001816	},
	{DDRPHY_R29,	0x00000001	},
	{DDRPHY_R11,	0x010D0608	},
	{DDRPHY_R29,	0x00000002	},
	{DDRPHY_R11,	0x02190403	},
	{DDRPHY_R29,	0x00000003	},
	{DDRPHY_R11,	0x1705150B	},
	{DDRPHY_R29,	0x00000004	},
	{DDRPHY_R11,	0x13121110	},
	{DDRPHY_R29,	0x00000005	},
	{DDRPHY_R11,	0x07090F0E	},
	{DDRPHY_R29,	0x00000006	},
	{DDRPHY_R11,	0x1A1D0A1B	},
	{DDRPHY_R29,	0x00000007	},
	{DDRPHY_R11,	0x001E1C0C	}
};
