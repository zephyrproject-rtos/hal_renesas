/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stddef.h>
#include <pfc_regs.h>
#include <lib/mmio.h>
#include <common/debug.h>

static PFC_REGS pfc_mux_reg_tbl[] = {
#if (RZG2UL||RZA3)
#if RZA3M
	/* P22(sd0)	*/
	{
		{ PFC_ON,  (uintptr_t)PFC_PMC04,  0x3e },                   /* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC04,  0 },                      /* PFC */
		{ PFC_OFF, (uintptr_t)PFC_IOLH04, 0x0000010101010101 },     /* IOLH */
		{ PFC_OFF, (uintptr_t)PFC_PUPD04, 0x0000000000000000 },     /* PUPD */
		{ PFC_OFF, (uintptr_t)PFC_SR04,   0x0000010101010101 },     /* SR */
		{ PFC_ON,  (uintptr_t)NULL,       0 }                       /* IEN */
	},
#else /* RZA3M */
	/* P0(sd0) & P0(sd1)	*/
	{
		{ PFC_ON,  (uintptr_t)PFC_PMC10,  0x0F },					/* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC10,  0x00001111 },				/* PFC */
		{ PFC_OFF, (uintptr_t)PFC_IOLH10, 0x0000000001010101 },		/* IOLH */
		{ PFC_OFF, (uintptr_t)PFC_PUPD10, 0x0000000000000000 },		/* PUPD */
		{ PFC_OFF, (uintptr_t)PFC_SR10,   0x0000000001010101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
#endif /* RZA3M */
#else
	/* P18(sd0) */
	{
		{ PFC_ON,  (uintptr_t)PFC_PMC22,  0x03 },					/* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC22,  0x00000011 },				/* PFC */
		{ PFC_OFF, (uintptr_t)PFC_IOLH22, 0x0000000000000101 },		/* IOLH */
		{ PFC_OFF, (uintptr_t)PFC_PUPD22, 0x0000000000000000 },		/* PUPD */
		{ PFC_OFF, (uintptr_t)PFC_SR22,   0x0000000000000101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
	/* P19(sd1) */
	{
		{ PFC_ON,  (uintptr_t)PFC_PMC23,  0x03 },					/* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC23,  0x00000011 },				/* PFC */
		{ PFC_OFF, (uintptr_t)PFC_IOLH23, 0x0000000000000101 },		/* IOLH */
		{ PFC_OFF, (uintptr_t)PFC_PUPD23, 0x0000000000000000 },		/* PUPD */
		{ PFC_OFF, (uintptr_t)PFC_SR23,   0x0000000000000101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
#endif
#if (RZG2UL||RZA3)
#if RZA3M
	/* P6(scif0) */
	{
		{ PFC_ON,  (uintptr_t)PFC_PMC16,  0x3 },                    /* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC16,  0x11 },                   /* PFC */
		{ PFC_OFF, (uintptr_t)PFC_IOLH16, 0x0000000000000101 },     /* IOLH */
		{ PFC_OFF, (uintptr_t)PFC_PUPD16, 0x0000000000000000 },     /* PUPD */
		{ PFC_OFF, (uintptr_t)PFC_SR16,   0x0000000000000101 },     /* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }                       /* IEN */
	},
#else /* RZA3M */
#if (DEVICE_TYPE == 1)
	/* P6(scif0) */
	{
		{ PFC_ON,  (uintptr_t)PFC_PMC16,  0x18 },					/* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC16,  0x00066000 },				/* PFC */
		{ PFC_OFF, (uintptr_t)PFC_IOLH16, 0x0000000101000000 },		/* IOLH */
		{ PFC_OFF, (uintptr_t)PFC_PUPD16, 0x0000000000000000 },		/* PUPD */
		{ PFC_OFF, (uintptr_t)PFC_SR16,   0x0000000101000000 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
#else
	/* P13(scif0) */
	{
		{ PFC_ON,  (uintptr_t)PFC_PMC1D,  0x03 },					/* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC1D,  0x00000011 },				/* PFC */
		{ PFC_OFF, (uintptr_t)PFC_IOLH1D, 0x0000000000000101 },		/* IOLH */
		{ PFC_OFF, (uintptr_t)PFC_PUPD1D, 0x0000000000000000 },		/* PUPD */
		{ PFC_OFF, (uintptr_t)PFC_SR1D,   0x0000000000000101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
#endif
#endif /* RZA3M */
#else
	/* P38(scif0) */
	{
		{ PFC_ON,  (uintptr_t)PFC_PMC36,  0x03 },					/* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC36,  0x00000011 },				/* PFC */
		{ PFC_OFF, (uintptr_t)PFC_IOLH36, 0x0000000000000101 },		/* IOLH */
		{ PFC_OFF, (uintptr_t)PFC_PUPD36, 0x0000000000000000 },		/* PUPD */
		{ PFC_OFF, (uintptr_t)PFC_SR36,   0x0000000000000101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
	/* P39(scif0) */
	{
		{ PFC_ON,  (uintptr_t)PFC_PMC37,  0x07 },					/* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC37,  0x00000111 },				/* PFC */
		{ PFC_OFF, (uintptr_t)PFC_IOLH37, 0x0000000000010101 },		/* IOLH */
		{ PFC_OFF, (uintptr_t)PFC_PUPD37, 0x0000000000000000 },		/* PUPD */
		{ PFC_OFF, (uintptr_t)PFC_SR37,   0x0000000000010101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	}
#endif
};

static PFC_REGS  pfc_qspi_reg_tbl[] = {
#if RZA3
#if RZA3M
    /* QSPI0 */
    {
        { PFC_OFF, (uintptr_t)NULL,       0 },                      /* PMC */
        { PFC_OFF, (uintptr_t)NULL,       0 },                      /* PFC */
        { PFC_ON,  (uintptr_t)PFC_IOLH05, 0x0000010101010101 },     /* IOLH */
        { PFC_ON,  (uintptr_t)PFC_PUPD05, 0x0000000000000000 },     /* PUPD */
        { PFC_ON,  (uintptr_t)PFC_SR05,   0x0000010101010101 },     /* SR */
        { PFC_OFF, (uintptr_t)NULL,       0 }                       /* IEN */
    },
#else /* RZA3M */
	/* QSPI0 */
	{
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
		{ PFC_ON,  (uintptr_t)PFC_IOLH0A, 0x0000010101010101 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD0A, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR0A,   0x0000010101010101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
	/* QSPI1 */
	{
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
		{ PFC_ON,  (uintptr_t)PFC_IOLH0B, 0x0000010101010101 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD0B, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR0B,   0x0000010101010101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
	/* QSPIn */
	{
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
		{ PFC_ON,  (uintptr_t)PFC_IOLH0C, 0x0000000000000101 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD0C, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR0C,   0x0000000000000000 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	}
#endif /* RZA3M */
#else
	/* QSPI0 */
	{
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
		{ PFC_ON,  (uintptr_t)PFC_IOLH0A, 0x0000020202020202 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD0A, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR0A,   0x0000010101010101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
	/* QSPI1 */
	{
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
		{ PFC_ON,  (uintptr_t)PFC_IOLH0B, 0x0000020202020202 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD0B, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR0B,   0x0000010101010101 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	},
	/* QSPIn */
	{
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
		{ PFC_ON,  (uintptr_t)PFC_IOLH0C, 0x0000000000020202 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD0C, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR0C,   0x0000000000010000 },		/* SR */
		{ PFC_OFF, (uintptr_t)NULL,       0 }						/* IEN */
	}
#endif
};

#ifndef RZA3
static PFC_REGS  pfc_sd_reg_tbl[] = {
	/* SD0_CLK */
	{
#if RZG2UL
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
#else
		{ PFC_ON,  (uintptr_t)PFC_PMC22,  0x0003 },					/* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC22,  0x00000003 },				/* PFC */
#endif
		{ PFC_ON,  (uintptr_t)PFC_IOLH06, 0x0000000000020202 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD06, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR06,   0x0000000000010101 },		/* SR */
		{ PFC_ON,  (uintptr_t)PFC_IEN06,  0x0000000000000100 }		/* IEN */
	},
	/* SD0_DATA */
	{
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
		{ PFC_ON,  (uintptr_t)PFC_IOLH07, 0x0202020202020202 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD07, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR07,   0x0101010101010101 },		/* SR */
		{ PFC_ON,  (uintptr_t)PFC_IEN07,  0x0101010101010101 }		/* IEN */
	},
	/* SD1_CLK */
	{
#if RZG2UL
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
#else
		{ PFC_ON,  (uintptr_t)PFC_PMC23,  0x0003 },					/* PMC */
		{ PFC_ON,  (uintptr_t)PFC_PFC23,  0x00000003 },				/* PFC */
#endif
		{ PFC_ON,  (uintptr_t)PFC_IOLH08, 0x0000000000000202 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD08, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR08,   0x0000000000000101 },		/* SR */
		{ PFC_ON,  (uintptr_t)PFC_IEN08,  0x0000000000000100 }		/* IEN */
	},
	/* SD1_DATA */
	{
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PMC */
		{ PFC_OFF, (uintptr_t)NULL,       0 },						/* PFC */
		{ PFC_ON,  (uintptr_t)PFC_IOLH09, 0x0000000002020202 },		/* IOLH */
		{ PFC_ON,  (uintptr_t)PFC_PUPD09, 0x0000000000000000 },		/* PUPD */
		{ PFC_ON,  (uintptr_t)PFC_SR09,   0x0000000001010101 },		/* SR */
		{ PFC_ON,  (uintptr_t)PFC_IEN09,  0x0000000001010101 }		/* IEN */
	}
};
#endif

static void pfc_mux_setup(void)
{
	int      cnt;
	int      size = ARRAY_SIZE(pfc_mux_reg_tbl);

	for (cnt = 0; cnt < size; cnt++) {
		/* PMC */
		if (pfc_mux_reg_tbl[cnt].pmc.flg == PFC_ON) {
			mmio_write_8(pfc_mux_reg_tbl[cnt].pmc.reg, pfc_mux_reg_tbl[cnt].pmc.val);
		}
		/* IOLH */
		if (pfc_mux_reg_tbl[cnt].iolh.flg == PFC_ON) {
			mmio_write_64(pfc_mux_reg_tbl[cnt].iolh.reg, pfc_mux_reg_tbl[cnt].iolh.val);
		}
		/* PUPD */
		if (pfc_mux_reg_tbl[cnt].pupd.flg == PFC_ON) {
			mmio_write_64(pfc_mux_reg_tbl[cnt].pupd.reg, pfc_mux_reg_tbl[cnt].pupd.val);
		}
		/* SR */
		if (pfc_mux_reg_tbl[cnt].sr.flg == PFC_ON) {
			mmio_write_64(pfc_mux_reg_tbl[cnt].sr.reg, pfc_mux_reg_tbl[cnt].sr.val);
		}
	}
	/* multiplexer terminal switching */
	mmio_write_32(PFC_PWPR, 0x0);
	mmio_write_32(PFC_PWPR, PWPR_PFCWE);

	for (cnt = 0; cnt < size; cnt++) {
		/* PFC */
		if (pfc_mux_reg_tbl[cnt].pfc.flg == PFC_ON) {
			mmio_write_32(pfc_mux_reg_tbl[cnt].pfc.reg, pfc_mux_reg_tbl[cnt].pfc.val);
		}
	}

	mmio_write_32(PFC_PWPR, 0x0);
	mmio_write_32(PFC_PWPR, PWPR_B0Wl);
}

static void pfc_qspi_setup(void)
{
	int      cnt;
	int      size = ARRAY_SIZE(pfc_qspi_reg_tbl);

	for (cnt = 0; cnt < size; cnt++) {
		/* PMC */
		if (pfc_qspi_reg_tbl[cnt].pmc.flg == PFC_ON) {
			mmio_write_64(pfc_qspi_reg_tbl[cnt].pmc.reg, pfc_qspi_reg_tbl[cnt].pmc.val);
		}
		/* IOLH */
		if (pfc_qspi_reg_tbl[cnt].iolh.flg == PFC_ON) {
			mmio_write_64(pfc_qspi_reg_tbl[cnt].iolh.reg, pfc_qspi_reg_tbl[cnt].iolh.val);
		}
		/* PUPD */
		if (pfc_qspi_reg_tbl[cnt].pupd.flg == PFC_ON) {
			mmio_write_64(pfc_qspi_reg_tbl[cnt].pupd.reg, pfc_qspi_reg_tbl[cnt].pupd.val);
		}
		/* SR */
		if (pfc_qspi_reg_tbl[cnt].sr.flg == PFC_ON) {
			mmio_write_64(pfc_qspi_reg_tbl[cnt].sr.reg, pfc_qspi_reg_tbl[cnt].sr.val);
		}
	}
	/* multiplexer terminal switching */
	mmio_write_32(PFC_PWPR, 0x0);
	mmio_write_32(PFC_PWPR, PWPR_PFCWE);
	for (cnt = 0; cnt < size; cnt++) {
		/* SR */
		if (pfc_qspi_reg_tbl[cnt].pfc.flg == PFC_ON) {
			mmio_write_64(pfc_qspi_reg_tbl[cnt].pfc.reg, pfc_qspi_reg_tbl[cnt].pfc.val);
		}
	}

	mmio_write_32(PFC_PWPR, 0x0);
	mmio_write_32(PFC_PWPR, PWPR_B0Wl);
}

#ifndef RZA3
static void pfc_sd_setup(void)
{
	int      cnt;
	int      size = ARRAY_SIZE(pfc_sd_reg_tbl);

	/* Since SDx is 3.3V, the initial value will be set. */
	mmio_write_32(PFC_SD_ch0, 1);
	mmio_write_32(PFC_SD_ch1, 0);

	for (cnt = 0; cnt < size; cnt++) {
		/* PMC */
		if (pfc_sd_reg_tbl[cnt].pmc.flg == PFC_ON) {
			mmio_write_8(pfc_sd_reg_tbl[cnt].pmc.reg, pfc_sd_reg_tbl[cnt].pmc.val);
		}
		/* PFC */
		if (pfc_sd_reg_tbl[cnt].pfc.flg == PFC_ON) {
			mmio_write_32(pfc_sd_reg_tbl[cnt].pfc.reg, pfc_sd_reg_tbl[cnt].pfc.val);
		}
		/* IOLH */
		if (pfc_sd_reg_tbl[cnt].iolh.flg == PFC_ON) {
			mmio_write_64(pfc_sd_reg_tbl[cnt].iolh.reg, pfc_sd_reg_tbl[cnt].iolh.val);
		}
		/* PUPD */
		if (pfc_sd_reg_tbl[cnt].pupd.flg == PFC_ON) {
			mmio_write_64(pfc_sd_reg_tbl[cnt].pupd.reg, pfc_sd_reg_tbl[cnt].pupd.val);
		}
		/* SR */
		if (pfc_sd_reg_tbl[cnt].sr.flg == PFC_ON) {
			mmio_write_64(pfc_sd_reg_tbl[cnt].sr.reg, pfc_sd_reg_tbl[cnt].sr.val);
		}
		/* IEN */
		if (pfc_sd_reg_tbl[cnt].ien.flg == PFC_ON) {
			mmio_write_64(pfc_sd_reg_tbl[cnt].ien.reg, pfc_sd_reg_tbl[cnt].ien.val);
		}
	}
}
#endif

void pfc_setup(void)
{
	pfc_mux_setup();
	pfc_qspi_setup();
#ifndef RZA3
	pfc_sd_setup();
#endif
}
