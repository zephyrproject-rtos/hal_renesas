/*
 * Copyright (c) 2020-2022, Renesas Electronics Corporation. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 * This code was generated with RZ/V2L DDR config generation tool v1.13.0
 */

#include <stdint.h>
#include <ddr_internal.h>

const uint32_t mc_odt_pins_tbl[4] = {
	0x00000001	,
	0x00000002	,
	0x00000000	,
	0x00000000
};

const uint32_t mc_mr1_tbl[2] = {
	0x00000706	,
	0x00000200
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
	0x0000001C
};

const uint32_t mc_phy_settings_tbl[MC_PHYSET_NUM][2] = {
	{DDRMC_R040,	0x576E08E8	},
	{DDRMC_R041,	0x00003C22	},
	{DDRMC_R042,	0x22227822	},
	{DDRMC_R043,	0x00123312	}
};

const uint32_t swizzle_mc_tbl[SWIZZLE_MC_NUM][2] = {
	{DDRMC_R030,	0x00001502	},
	{DDRMC_R031,	0x00000A06	},
	{DDRMC_R032,	0x170D1112	},
	{DDRMC_R033,	0x1900130B	},
	{DDRMC_R034,	0x1F09180C	},
	{DDRMC_R035,	0x161C0E14	},
	{DDRMC_R036,	0x01101B1A	},
	{DDRMC_R037,	0x001D051E	},
	{DDRMC_R038,	0x00000000	}
};

const uint32_t swizzle_phy_tbl[SIZZLE_PHY_NUM][2] = {
	{DDRPHY_R29,	0x00000000	},
	{DDRPHY_R11,	0x1B03150E	},
	{DDRPHY_R29,	0x00000001	},
	{DDRPHY_R11,	0x16001706	},
	{DDRPHY_R29,	0x00000002	},
	{DDRPHY_R11,	0x0D050807	},
	{DDRPHY_R29,	0x00000003	},
	{DDRPHY_R11,	0x1901020B	},
	{DDRPHY_R29,	0x00000004	},
	{DDRPHY_R11,	0x13121110	},
	{DDRPHY_R29,	0x00000005	},
	{DDRPHY_R11,	0x0F090418	},
	{DDRPHY_R29,	0x00000006	},
	{DDRPHY_R11,	0x1A0A1D14	},
	{DDRPHY_R29,	0x00000007	},
	{DDRPHY_R11,	0x001E1C0C	}
};
