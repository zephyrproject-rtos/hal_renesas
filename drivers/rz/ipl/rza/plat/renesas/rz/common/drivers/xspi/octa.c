/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#include <assert.h>
#include <common/debug.h>

#include <xspi_api.h>
#include <octa.h>
#include <octa_regs.h>
#include <cpg.h>
#include <cpg_regs.h>
#include <sys_regs.h>
#include <pfc_regs.h>
#include <lib/mmio.h>
#include <drivers/delay_timer.h>

/* Defaults */
#define DEFAULT_SPI_FREQUENCY 66666667
#define RESET_DURATION_US 10
#define DEFAULT_VOLTAGE_IS_1800MV 1
#define DEFAULT_CH0_CALIBRATION_OFFSET 0x1C0
#define DEFAULT_CH1_CALIBRATION_OFFSET 0

/* Static function pre-definition */
static int octa_open(xspi_ctrl_t * ctrl, xspi_cfg_t const * const cfg);
static int octa_close(xspi_ctrl_t * const ctrl);
static int octa_post_init(xspi_ctrl_t * const ctrl);
static int octa_exec_op(xspi_ctrl_t * const ctrl, xspi_op_t const * const op, bool is_write);
static int octa_configure_xip(xspi_ctrl_t * const ctrl, xspi_op_t const * const rop, xspi_op_t const * const wop);
static int octa_start_xip(xspi_ctrl_t * const ctrl);
static int octa_stop_xip(xspi_ctrl_t * const ctrl);
static int octa_run_manual_calibration(xspi_ctrl_t * const ctrl);
static int octa_enable_auto_calibration(xspi_ctrl_t * const ctrl);
static int octa_disable_auto_calibration(xspi_ctrl_t * const ctrl);
static int octa_set_frequency(xspi_ctrl_t * const ctrl, int frequency_hz);
static int octa_clean_mmap(xspi_ctrl_t * const ctrl);
static int octa_inv_mmap(xspi_ctrl_t * const ctrl);
static uintptr_t octa_get_mmap_base(xspi_ctrl_t * const ctrl);
static size_t octa_get_mmap_size(xspi_ctrl_t * const ctrl);
static uint32_t octa_get_features(xspi_ctrl_t * const ctrl);

/* API function table definition */
const xspi_api_t octa_api = {
	.open = octa_open,
	.close = octa_close,
	.post_init = octa_post_init,
	.exec_op = octa_exec_op,
	.configure_xip = octa_configure_xip,
	.start_xip = octa_start_xip,
	.stop_xip = octa_stop_xip,
	.run_manual_calibration = octa_run_manual_calibration,
	.enable_auto_calibration = octa_enable_auto_calibration,
	.disable_auto_calibration = octa_disable_auto_calibration,
	.set_frequency = octa_set_frequency,
	.clean_mmap = octa_clean_mmap,
	.inv_mmap = octa_inv_mmap,
	.get_mmap_base = octa_get_mmap_base,
	.get_mmap_size = octa_get_mmap_size,
	.get_features = octa_get_features,
};

/* Preamble pattern (aligned to 16byte boundary) */
static const uint32_t preamble[4] __aligned(16) = {
	0xFFFF0000,
	0x000800FF,
	0x00FFF700,
	0xF700F708,
};

/* Static variables */
static bool globally_initialised = false;
static bool post_init_done = false;
static int spi_clock = DEFAULT_SPI_FREQUENCY;
static bool initialised[2] = {false, false};
static int freq[2] = {INT_MAX, INT_MAX};
static bool is_calibrated[2] = {false, false};

static const uintptr_t ch0_mmap_base = 0x20000000;
static const size_t ch0_mmap_size = 0x08000000;
static const uintptr_t ch1_mmap_base = 0x28000000;
static const size_t ch1_mmap_size = 0x08000000;

/* !!! DO NOT TOUCH THESE SETTINGS !!! They are used for doing initialize. */
static const uint32_t init_octa_dcr_value = 0;
static const uint32_t init_octa_dar_value = 0;
static const uint32_t init_octa_dcsr_value = 0 |
	0u << OCTA_DCSR_ACDA_POS |
	0u << OCTA_DCSR_DOPI_POS |
	0u << OCTA_DCSR_ADLEN_POS |
	0u << OCTA_DCSR_DAOR_POS |
	0u << OCTA_DCSR_CMDLEN_POS |
	0u << OCTA_DCSR_ACDV_POS |
	0u << OCTA_DCSR_DMLEN_POS |
	0u << OCTA_DCSR_DALEN_POS;
static const uint32_t init_octa_dsr0_value = 0 |
	OCTA_DSR_TYP_NONE >> OCTA_DSR0_DV0TYP_POS |
	0u << OCTA_DSR0_DV0SZ_POS;
static const uint32_t init_octa_dsr1_value = 0 |
	OCTA_DSR_TYP_NONE >> OCTA_DSR1_DV1TYP_POS |
	0u << OCTA_DSR1_DV1SZ_POS;
static const uint32_t init_octa_mdtr_value = 0 |
	6u << OCTA_MDTR_DQSEDOPI_POS |
	0x50u << OCTA_MDTR_DV1DEL_POS |
	9u << OCTA_MDTR_DQSESOPI_POS |
	4u << OCTA_MDTR_DQSERAM_POS |
	0x50u << OCTA_MDTR_DV0DEL_POS;
static const uint32_t init_octa_actr_value = 268435456;
static const uint32_t init_octa_acar0_value = 0x00000000;
static const uint32_t init_octa_acar1_value = 0x00000000;
static const uint32_t init_octa_drcstr_value = 0 |
	0u << OCTA_DRCSTR_DVRDLO1_POS |
	0u << OCTA_DRCSTR_DVRDHI1_POS |
	0u << OCTA_DRCSTR_DVRDCMD1_POS |
#if !RZA3
	0u << OCTA_DRCSTR_CTR1_POS |
	127u << OCTA_DRCSTR_CTRW1_POS |
#endif
	0u << OCTA_DRCSTR_DVRDLO0_POS |
	0u << OCTA_DRCSTR_DVRDHI0_POS |
	0u << OCTA_DRCSTR_DVRDCMD0_POS |
	1u << OCTA_DRCSTR_CTR0_POS |
	127u << OCTA_DRCSTR_CTRW0_POS;
static const uint32_t init_octa_dwcstr_value = 0 |
	0u << OCTA_DWCSTR_DVWLO1_POS |
	0u << OCTA_DWCSTR_DVWHI1_POS |
	0u << OCTA_DWCSTR_DVWCMD1_POS |
	0u << OCTA_DWCSTR_DVWLO0_POS |
	0u << OCTA_DWCSTR_DVWHI0_POS |
	0u << OCTA_DWCSTR_DVWCMD0_POS;
static const uint32_t init_octa_dcstr_value = 0 |
	0u << OCTA_DCSTR_DVSELLO_POS |
	0u << OCTA_DCSTR_DVSELHI_POS |
	0u << OCTA_DCSTR_DVSELCMD_POS;
static const uint32_t init_octa_cdsr_value = 0 |
	1u << OCTA_CDSR_DLFT_POS |
	0u << OCTA_CDSR_ACMEME1_POS |
	0u << OCTA_CDSR_ACMEME0_POS |
	0u << OCTA_CDSR_DV1PC_POS |
	0u << OCTA_CDSR_DV0PC_POS |
	OCTA_CDSR_DVTTYP_SPI << OCTA_CDSR_DV1TTYP_POS |
	OCTA_CDSR_DVTTYP_SPI << OCTA_CDSR_DV0TTYP_POS;
static const uint32_t init_octa_mdlr_value = 0 |
	0u << OCTA_MDLR_DV1WDL_POS |
	0u << OCTA_MDLR_DV1RDL_POS |
	0u << OCTA_MDLR_DV0WDL_POS |
	0u << OCTA_MDLR_DV0RDL_POS;
static const uint32_t init_octa_mrwcr0_value = 0 |
	0u << OCTA_MRWCR0_D0MWCMD1_POS |
	0u << OCTA_MRWCR0_D0MWCMD0_POS |
	0u << OCTA_MRWCR0_D0MRCMD1_POS |
	0u << OCTA_MRWCR0_D0MRCMD0_POS;
static const uint32_t init_octa_mrwcr1_value = 0 |
	0u << OCTA_MRWCR1_D1MWCMD1_POS |
	0u << OCTA_MRWCR1_D1MWCMD0_POS |
	0u << OCTA_MRWCR1_D1MRCMD1_POS |
	0u << OCTA_MRWCR1_D1MRCMD0_POS;
static const uint32_t init_octa_mrwcsr_value = 0 |
	0u << OCTA_MRWCSR_MWO1_POS |
	0u << OCTA_MRWCSR_MWCL1_POS |
	0u << OCTA_MRWCSR_MWAL1_POS |
	0u << OCTA_MRWCSR_MRO1_POS |
	0u << OCTA_MRWCSR_MRCL1_POS |
	0u << OCTA_MRWCSR_MRAL1_POS |
	0u << OCTA_MRWCSR_MWO0_POS |
	0u << OCTA_MRWCSR_MWCL0_POS |
	0u << OCTA_MRWCSR_MWAL0_POS |
	0u << OCTA_MRWCSR_MRO0_POS |
	0u << OCTA_MRWCSR_MRCL0_POS |
	0u << OCTA_MRWCSR_MRAL0_POS;

/* Function definitions */
static void select_octa(octa_ctrl_t *myctrl, xspi_cfg_t const * const cfg)
{
	if (RZ_XSPI_EXCLUSIVE_SELECTOR) {
		/* Check if SPIM selected */
		uint32_t ipcont_spi_octa = mmio_read_32(SYS_IPCONT);
		if ((ipcont_spi_octa & IPCONT_SEL_SPI_OCTA) == IPCONT_SEL_SPI_OCTA_SPI) {
			/* Reset SPIM controller */
			cpg_reset_on(CPG_CLOCK_SPIM);

			/* Stop SPIM clock */
			cpg_clock_off(CPG_CLOCK_SPIM);
		}
		else {
			/* Reset the devices connected, required to change the device mode
			 * from OPI to SPI.
			 * Otherwise, the octa devices can not initialize by the SPI mode.
			 */
			mmio_clrbits_32(myctrl->reg_base + OCTA_RSTCNT, OCTA_RSTCNT_RSTVAL);
		}
	}

	/* Wait for reset SPI device */
	udelay(RESET_DURATION_US);

	if (RZ_XSPI_FORCE_VOLTAGE_SETTING) {
		/* force voltage setting
		 * Note: This is required if the boot mode is neither 3 nor 4.
		 */
		uint8_t voltage = DEFAULT_VOLTAGE_IS_1800MV;
		mmio_write_8(PFC_QSPI, voltage);
		mmio_read_8(PFC_QSPI);
	}

	/* Supply OCTA clock */
	cpg_clock_on(CPG_CLOCK_OCTA);

	/* Resume OCTA controller */
	cpg_reset_off(CPG_CLOCK_OCTA);

	if (RZ_XSPI_EXCLUSIVE_SELECTOR) {
		/* Select OCTA for SPI controller */
		uint32_t ipcont_spi_octa = mmio_read_32(SYS_IPCONT);
		ipcont_spi_octa &= ~IPCONT_SEL_SPI_OCTA;
		ipcont_spi_octa |= IPCONT_SEL_SPI_OCTA_OCTA << IPCONT_SEL_SPI_OCTA_POS;
		mmio_write_32(SYS_IPCONT, ipcont_spi_octa);
		mmio_read_32(SYS_IPCONT);
	}

	/* De-assert reset line */
	mmio_setbits_32(myctrl->reg_base + OCTA_RSTCNT, OCTA_RSTCNT_RSTVAL);
}

static void octa_init(octa_ctrl_t *myctrl)
{
	mmio_write_32(myctrl->reg_base+OCTA_DCR, init_octa_dcr_value);
	mmio_write_32(myctrl->reg_base+OCTA_DAR, init_octa_dar_value);
	mmio_write_32(myctrl->reg_base+OCTA_DCSR, init_octa_dcsr_value);
	mmio_write_32(myctrl->reg_base+OCTA_DSR0, init_octa_dsr0_value);
	mmio_write_32(myctrl->reg_base+OCTA_DSR1, init_octa_dsr1_value);
	mmio_write_32(myctrl->reg_base+OCTA_MDTR, init_octa_mdtr_value);
	mmio_write_32(myctrl->reg_base+OCTA_ACTR, init_octa_actr_value);
	mmio_write_32(myctrl->reg_base+OCTA_ACAR0, init_octa_acar0_value);
	mmio_write_32(myctrl->reg_base+OCTA_ACAR1, init_octa_acar1_value);
	mmio_write_32(myctrl->reg_base+OCTA_DRCSTR, init_octa_drcstr_value);
	mmio_write_32(myctrl->reg_base+OCTA_DWCSTR, init_octa_dwcstr_value);
	mmio_write_32(myctrl->reg_base+OCTA_DCSTR, init_octa_dcstr_value);
	mmio_write_32(myctrl->reg_base+OCTA_CDSR, init_octa_cdsr_value);
	mmio_write_32(myctrl->reg_base+OCTA_MDLR, init_octa_mdlr_value);
	mmio_write_32(myctrl->reg_base+OCTA_MRWCR0, init_octa_mrwcr0_value);
	mmio_write_32(myctrl->reg_base+OCTA_MRWCR1, init_octa_mrwcr1_value);
	mmio_write_32(myctrl->reg_base+OCTA_MRWCSR, init_octa_mrwcsr_value);
}

static int octa_open(xspi_ctrl_t * ctrl, xspi_cfg_t const * const cfg)
{
	int result = -1;
	assert(ctrl);
	assert(cfg);
	assert(cfg->channel == 0 || cfg->channel == 1);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	octa_ext_t * ext = (octa_ext_t*)cfg->extend;
	assert(cfg->base);

	if (myctrl->opened) return -1;

	myctrl->reg_base = cfg->base;
	myctrl->channel = cfg->channel;

	result = 0;

	if (!globally_initialised) {
		/* Initialize IP (once) */
		select_octa(myctrl, cfg);
		octa_init(myctrl);

		globally_initialised = true;
	}

	/* Initialize MMAP base and initial size */
	size_t mmap_size;
	if (myctrl->channel) {
		myctrl->mmap_base = ch1_mmap_base;
		mmap_size = ch1_mmap_size;
	}
	else {
		myctrl->mmap_base = ch0_mmap_base;
		mmap_size = ch0_mmap_size;
	}

	/* Override size if specified and is smaller */
	if (ext && mmap_size > (size_t)ext->device_size) {
		mmap_size = (size_t)ext->device_size;
	}

	/* Store mmap size */
	myctrl->mmap_size = mmap_size;

	/* Set device type and calibrate address */
	uint8_t device_type;
	if (myctrl->channel) {
		device_type = OCTA_DSR_TYP_RAM;
		/* Override calibration base if specified */
		uint32_t ch1_calibration_offset = DEFAULT_CH1_CALIBRATION_OFFSET;
		if (ext && ext->calibration_base != UINT32_MAX) {
			ch1_calibration_offset = ext->calibration_base;
		}
		myctrl->calibration_base = ch1_calibration_offset;
		mmio_write_32(myctrl->reg_base + OCTA_ACAR1, myctrl->calibration_base);
	}
	else {
		device_type = OCTA_DSR_TYP_FLASH;
		/* Override calibration base if specified */
		uint32_t ch0_calibration_offset = DEFAULT_CH0_CALIBRATION_OFFSET;
		if (ext && ext->calibration_base != 0) {
			ch0_calibration_offset = ext->calibration_base;
		}
		myctrl->calibration_base = ch0_calibration_offset;
		mmio_write_32(myctrl->reg_base + OCTA_ACAR0, myctrl->calibration_base);
	}
	myctrl->device_type = device_type;

	/* Sets DVnSZ only first per channel */
	if (!initialised[myctrl->channel]) {
		uint32_t dsr;
		if (ext) {
			dsr = ext->device_size;
		}
		else {
			dsr = mmap_size;
		}

		if (myctrl->channel) {
			uint32_t aer;
			if (dsr <= 8*1024*1024) aer = OCTA_AER_LE64MB;
			else if (dsr <= 16*1024*1024) aer = OCTA_AER_128MB;
			else if (dsr <= 32*1024*1024) aer = OCTA_AER_256MB;
			else aer = OCTA_AER_512MB;
			dsr <<= OCTA_DSR1_DV1SZ_POS;
			dsr |= (uint32_t)device_type << OCTA_DSR1_DV1TYP_POS;
			mmio_write_32(myctrl->reg_base + OCTA_AER, aer);
			mmio_write_32(myctrl->reg_base + OCTA_DSR1, dsr);
		}
		else {
			dsr <<= OCTA_DSR0_DV0SZ_POS;
			dsr |= (uint32_t)device_type << OCTA_DSR0_DV0TYP_POS;
			mmio_write_32(myctrl->reg_base + OCTA_DSR0, dsr);
		}
		initialised[myctrl->channel] = true;
	}

	myctrl->opened = true;

	return result;
}

static int octa_close(xspi_ctrl_t * const ctrl)
{
	int result = -1;
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	if (myctrl->opened) {
		myctrl->opened = false;
		result = 0;
	}
	return result;

}

static bool octa_check_acmode_ready(bool acmeme, bool is_dopi, int channel)
{
	if (!initialised[channel]) return true;		/* Ignore for empty channel */
	if (!is_dopi) return true;			/* Ignore or SPI/SOPI channel */
	if (!is_calibrated[channel]) return true;	/* Ignore if failed the manual calibration */
	return acmeme;	/* On DOPI, Follow acmeme setting */
}

static void octa_set_acmode(uint32_t * cdsr)
{
	if (post_init_done) {
		bool flag_0, flag_1, acmeme0, acmeme1, is_dopi;

		/* Check if CH0 is ready for enabling ACMODE */
		acmeme0 = (*cdsr & OCTA_CDSR_ACMEME0) != 0;
		is_dopi = (*cdsr & OCTA_CDSR_DV0TTYP) == (OCTA_CDSR_DVTTYP_DOPI << OCTA_CDSR_DV0TTYP_POS);
		flag_0 = octa_check_acmode_ready(acmeme0, is_dopi, 0);

		/* Check if CH1 is ready for enabling ACMODE */
		acmeme1 = (*cdsr & OCTA_CDSR_ACMEME1) != 0;
		is_dopi = (*cdsr & OCTA_CDSR_DV1TTYP) == (OCTA_CDSR_DVTTYP_DOPI << OCTA_CDSR_DV1TTYP_POS);
		flag_1 = octa_check_acmode_ready(acmeme1, is_dopi, 1);

		/* mask old value */
		*cdsr &= ~OCTA_CDSR_ACMODE;

		/* When both CH0/CH1 are ready for enabling ACMODE and either ACMEME0 or ACMEME1 is enabled */
		if (flag_0 && flag_1 && (acmeme0 || acmeme1)) {
			*cdsr |= OCTA_CDSR_ACMODE_ENABLE << OCTA_CDSR_ACMODE_POS;
		}
	}
}

static void octa_set_auto_calibration(octa_ctrl_t *myctrl)
{
	uint32_t cdsr = mmio_read_32(myctrl->reg_base + OCTA_CDSR);

	/* Set/reset ACMODE */
	octa_set_acmode(&cdsr);
	mmio_write_32(myctrl->reg_base + OCTA_CDSR, cdsr & ~OCTA_CDSR_ACMODE);
	mmio_write_32(myctrl->reg_base + OCTA_CDSR, cdsr);
}

static int octa_post_init(xspi_ctrl_t * const ctrl)
{
	int result = 0;
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;

	if (!post_init_done) {
		post_init_done = true;
		octa_set_auto_calibration(myctrl);
	}

	return result;
}

static int octa_test_ddr(xspi_op_t const * const op)
{
	if (!(op->op_is_ddr == op->address_is_ddr)) return -1;
	if (!op->op_is_ddr && !op->address_is_ddr && op->transfer_is_ddr) return -1;
	return 0;
}

static int octa_test_form(octa_ctrl_t const * const myctrl, xspi_op_t const * const op)
{
	if (!(myctrl->device_type!=OCTA_DSR_TYP_NONE)) return -1;
	if (!((myctrl->device_type==OCTA_DSR_TYP_FLASH &&
			(op->form==SPI_FORM_8_8_8 || (op->form==SPI_FORM_1_1_1 && !op->op_is_ddr && !op->address_is_ddr && !op->transfer_is_ddr))) ||
		(myctrl->device_type==OCTA_DSR_TYP_RAM && op->form==SPI_FORM_8_8_8 && op->op_is_ddr && op->address_is_ddr && op->transfer_is_ddr))) return -1;
	return 0;
}

static int octa_exec_op(xspi_ctrl_t * const ctrl, xspi_op_t const * const op, bool is_write)
{
	assert(!!ctrl);
	assert(!!op);
	int res;
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	res = octa_test_ddr(op);
	if (!!res) return res;
	res = octa_test_form(myctrl, op);
	if (!!res) return res;

	assert(	op->transfer_size==0 ||
		op->transfer_size==1 ||
		op->transfer_size==2 ||
		op->transfer_size==4 ||
		(op->transfer_size==3 && op->transfer_is_ddr==false && is_write==false));

	uint32_t dcstr;
	uint32_t dcsr_clear, dcsr_set;
	dcsr_clear = dcsr_set = 0;
	uint32_t cdsr_clear, cdsr_set, save_cdsr;
	cdsr_clear = cdsr_set = 0;
	uint32_t mdtr_clear, mdtr_set, save_mdtr;
	mdtr_clear = mdtr_set = 0;

	/* change write flag if no transfer phase required */
	if (op->transfer_size == 0) is_write = true;

	/* select and check memory type */
	int transfer_type;
	int enable_counter;
	switch (op->form) {
	case SPI_FORM_8_8_8:
		if (op->op_is_ddr) {
			/* DOPI */
			if (myctrl->device_type == OCTA_DSR_TYP_RAM) {
				transfer_type = OCTA_CDSR_DVTTYP_DOPI;
				enable_counter = op->dummy_cycles + 1;
				if (enable_counter > 15) enable_counter = 15;
				mdtr_clear |= OCTA_MDTR_DQSERAM;
				mdtr_set |= enable_counter << OCTA_MDTR_DQSERAM_POS;
			}
			else {
				transfer_type = OCTA_CDSR_DVTTYP_DOPI;
				enable_counter = op->dummy_cycles + 2;
				if (enable_counter > 15) enable_counter = 15;
				mdtr_clear |= OCTA_MDTR_DQSEDOPI;
				mdtr_set |= enable_counter << OCTA_MDTR_DQSEDOPI_POS;
			}
		}
		else {
			/* SOPI */
			transfer_type = OCTA_CDSR_DVTTYP_SOPI;
			enable_counter = op->dummy_cycles + 4;
			if (enable_counter > 15) enable_counter = 15;
			mdtr_clear |= OCTA_MDTR_DQSESOPI;
			mdtr_set |= enable_counter << OCTA_MDTR_DQSESOPI_POS;
		}
		break;
	case SPI_FORM_1_1_1:
		transfer_type = OCTA_CDSR_DVTTYP_SPI;
		break;
	default:
		ERROR("Unsupported transfer form %d\n", op->form);
		return -1;
	}

	/* lock channel (not implemented) */

	/* save shared parameters */
	save_cdsr = mmio_read_32(myctrl->reg_base + OCTA_CDSR);
	save_mdtr = mmio_read_32(myctrl->reg_base + OCTA_MDTR);

	/* set controller operation parameters */
	mmio_write_32(myctrl->reg_base + OCTA_DCR, (uint32_t)op->op);
	mmio_write_32(myctrl->reg_base + OCTA_DAR, op->address);
	dcstr = op->slch_value << OCTA_DCSTR_DVSELLO_POS;
	dcstr |= op->clsh_value << OCTA_DCSTR_DVSELHI_POS;
	dcstr |= op->shsl_value << OCTA_DCSTR_DVSELCMD_POS;
	mmio_write_32(myctrl->reg_base + OCTA_DCSTR, dcstr);
	cdsr_clear |= OCTA_CDSR_ACMODE;
	dcsr_clear |= OCTA_DCSR_ADLEN;
	dcsr_set |= op->address_size << OCTA_DCSR_ADLEN_POS;
	dcsr_clear |= OCTA_DCSR_CMDLEN;
	dcsr_set |= op->op_size << OCTA_DCSR_CMDLEN_POS;
	dcsr_clear |= OCTA_DCSR_DMLEN;
	dcsr_set |= op->dummy_cycles << OCTA_DCSR_DMLEN_POS;
	dcsr_clear |= OCTA_DCSR_DALEN;
	/* For 3-byte transfer, modify as 4byte transfer */
	dcsr_set |= (op->transfer_size == 3 ? 4u : op->transfer_size) << OCTA_DCSR_DALEN_POS;
	/* Force data access method */
	dcsr_clear |= OCTA_DCSR_ACDA;
	if (op->transfer_flag & XSPI_FLAGS_DATA_ACCESS) {
		dcsr_set |= OCTA_DCSR_ACDA;
	}

	/* set channel related parameters */
	dcsr_clear |= OCTA_DCSR_ACDV;
	dcsr_set |= myctrl->channel << OCTA_DCSR_ACDV_POS;
	if (myctrl->channel) {
		/* Channel 1 */
		cdsr_clear |= OCTA_CDSR_DV1PC | OCTA_CDSR_DV1TTYP;
		cdsr_set |= transfer_type << OCTA_CDSR_DV1TTYP_POS;
	}
	else {
		/* Channel 0 */
		cdsr_clear |= OCTA_CDSR_DV0PC | OCTA_CDSR_DV0TTYP;
		cdsr_set |= transfer_type << OCTA_CDSR_DV0TTYP_POS;
	}

	/* change transfer order */
	dcsr_clear |= OCTA_DCSR_DAOR;
	if (~op->transfer_flag & XSPI_FLAGS_SEQUENTIAL_DDR) {
		if (op->transfer_is_ddr) {
			dcsr_set |= OCTA_DCSR_DAOR;
		}
	}
	/* change SDR mode (DOPI mode with SDR transfer) */
	dcsr_clear |= OCTA_DCSR_DOPI;
	if (transfer_type == OCTA_CDSR_DVTTYP_DOPI && !op->transfer_is_ddr) {
		dcsr_set |= OCTA_DCSR_DOPI;
	}

	mmio_clrsetbits_32(myctrl->reg_base + OCTA_DCSR, dcsr_clear, dcsr_set);
	mmio_clrsetbits_32(myctrl->reg_base + OCTA_CDSR, cdsr_clear, cdsr_set);
	mmio_clrsetbits_32(myctrl->reg_base + OCTA_MDTR, mdtr_clear, mdtr_set);

	if (is_write) {
		switch(op->transfer_size) {
		case 0:
			mmio_write_32(myctrl->reg_base + OCTA_CWNDR, 0);
			break;
		case 1:
			mmio_write_8(myctrl->reg_base + OCTA_CWDR, *(uint8_t*)op->transfer_buffer);
			break;
		case 2:
			mmio_write_16(myctrl->reg_base + OCTA_CWDR, *(uint16_t*)op->transfer_buffer);
			break;
		case 4:
			mmio_write_32(myctrl->reg_base + OCTA_CWDR, *(uint32_t*)op->transfer_buffer);
			break;
		}
	}
	else {
		mmio_read_32(myctrl->reg_base + OCTA_CDSR);
		switch(op->transfer_size) {
		case 1:
			*(uint8_t*)op->transfer_buffer = mmio_read_8(myctrl->reg_base + OCTA_CRR);
			break;
		case 2:
			*(uint16_t*)op->transfer_buffer = mmio_read_16(myctrl->reg_base + OCTA_CRR);
			break;
		case 3: {
			uint32_t tmp = mmio_read_32(myctrl->reg_base + OCTA_CRR);
			uint8_t * u8p = (uint8_t*)op->transfer_buffer;
			u8p[0] = tmp & 0xff;
			u8p[1] = tmp & 0xff00 >> 8;
			u8p[2] = tmp & 0xff0000 >> 16;
			break;
		}
		case 4:
			*(uint32_t*)op->transfer_buffer = mmio_read_32(myctrl->reg_base + OCTA_CRR);
			break;
		}
	}

	/* restore shared parameters */
	mmio_write_32(myctrl->reg_base + OCTA_MDTR, save_mdtr);
	mmio_write_32(myctrl->reg_base + OCTA_CDSR, save_cdsr);

	/* unlock channel (not implemented) */

	return 0;
}

static void octa_configure_xip_ch1(octa_ctrl_t * const myctrl, xspi_op_t const * const rop, xspi_op_t const * const wop)
{
	uint32_t mdlr_clear, mdlr_set;
	mdlr_clear = mdlr_set = 0;
	uint32_t mrwcr_clear, mrwcr_set;
	mrwcr_clear = mrwcr_set = 0;
	uint32_t mrwcsr_clear, mrwcsr_set;
	mrwcsr_clear = mrwcsr_set = 0;

	if (rop) {
		uint32_t drcstr_clear, drcstr_set;
		drcstr_clear = drcstr_set = 0;
		drcstr_clear |= OCTA_DRCSTR_DVRDLO1|OCTA_DRCSTR_DVRDHI1|OCTA_DRCSTR_DVRDCMD1;
		drcstr_set |= rop->slch_value << OCTA_DRCSTR_DVRDLO1_POS;
		drcstr_set |= rop->clsh_value << OCTA_DRCSTR_DVRDHI1_POS;
		drcstr_set |= rop->shsl_value << OCTA_DRCSTR_DVRDCMD1_POS;
		mdlr_clear |= OCTA_MDLR_DV1RDL;
		mdlr_set |= rop->dummy_cycles << OCTA_MDLR_DV1RDL_POS;
		mrwcr_clear |= OCTA_MRWCR1_D1MRCMD0 | OCTA_MRWCR1_D1MRCMD1;
		mrwcr_set |= (uint32_t)rop->op << OCTA_MRWCR1_D1MRCMD0_POS;
		mrwcsr_clear |= OCTA_MRWCSR_MRO1 | OCTA_MRWCSR_MRCL1 | OCTA_MRWCSR_MRAL1;
		if (rop->transfer_is_ddr && ~rop->transfer_flag & XSPI_FLAGS_SEQUENTIAL_DDR) {
			mrwcsr_set |= 1u << OCTA_MRWCSR_MRO1_POS;
		}
		mrwcsr_set |= rop->op_size << OCTA_MRWCSR_MRCL1_POS;
		mrwcsr_set |= rop->address_size << OCTA_MRWCSR_MRAL1_POS;
		mmio_clrsetbits_32(myctrl->reg_base + OCTA_DRCSTR, drcstr_clear, drcstr_set);
	}
	if (wop) {
		uint32_t dwcstr_clear, dwcstr_set;
		dwcstr_clear = dwcstr_set = 0;
		dwcstr_clear |= OCTA_DWCSTR_DVWLO1|OCTA_DWCSTR_DVWHI1|OCTA_DWCSTR_DVWCMD1;
		dwcstr_set |= wop->slch_value << OCTA_DWCSTR_DVWLO1_POS;
		dwcstr_set |= wop->clsh_value << OCTA_DWCSTR_DVWHI1_POS;
		dwcstr_set |= wop->shsl_value << OCTA_DWCSTR_DVWCMD1_POS;
		mdlr_clear |= OCTA_MDLR_DV1WDL;
		mdlr_set |= wop->dummy_cycles << OCTA_MDLR_DV1WDL_POS;
		mrwcr_clear |= OCTA_MRWCR1_D1MWCMD0 | OCTA_MRWCR1_D1MWCMD1;
		mrwcr_set |= (uint32_t)wop->op << OCTA_MRWCR1_D1MWCMD0_POS;
		mrwcsr_clear |= OCTA_MRWCSR_MWO1 | OCTA_MRWCSR_MWCL1 | OCTA_MRWCSR_MWAL1;
		if (wop->transfer_is_ddr && ~wop->transfer_flag & XSPI_FLAGS_SEQUENTIAL_DDR) {
			mrwcsr_set |= 1u << OCTA_MRWCSR_MWO1_POS;
		}
		mrwcsr_set |= wop->op_size << OCTA_MRWCSR_MWCL1_POS;
		mrwcsr_set |= wop->address_size << OCTA_MRWCSR_MWAL1_POS;
		mmio_clrsetbits_32(myctrl->reg_base + OCTA_DWCSTR, dwcstr_clear, dwcstr_set);
	}
	mmio_clrsetbits_32(myctrl->reg_base + OCTA_MDLR, mdlr_clear, mdlr_set);
	mmio_clrsetbits_32(myctrl->reg_base + OCTA_MRWCR1, mrwcr_clear, mrwcr_set);
	mmio_clrsetbits_32(myctrl->reg_base + OCTA_MRWCSR, mrwcsr_clear, mrwcsr_set);
}

static void octa_configure_xip_ch0(octa_ctrl_t * const myctrl, xspi_op_t const * const rop, xspi_op_t const * const wop)
{
	uint32_t mdlr_clear, mdlr_set;
	mdlr_clear = mdlr_set = 0;
	uint32_t mrwcr_clear, mrwcr_set;
	mrwcr_clear = mrwcr_set = 0;
	uint32_t mrwcsr_clear, mrwcsr_set;
	mrwcsr_clear = mrwcsr_set = 0;

	if (rop) {
		uint32_t drcstr_clear, drcstr_set;
		drcstr_clear = drcstr_set = 0;
		drcstr_clear |= OCTA_DRCSTR_DVRDLO0|OCTA_DRCSTR_DVRDHI0|OCTA_DRCSTR_DVRDCMD0;
		drcstr_set |= rop->slch_value << OCTA_DRCSTR_DVRDLO0_POS;
		drcstr_set |= rop->clsh_value << OCTA_DRCSTR_DVRDHI0_POS;
		drcstr_set |= rop->shsl_value << OCTA_DRCSTR_DVRDCMD0_POS;
		mdlr_clear |= OCTA_MDLR_DV0RDL;
		mdlr_set |= rop->dummy_cycles << OCTA_MDLR_DV0RDL_POS;
		mrwcr_clear |= OCTA_MRWCR0_D0MRCMD0 | OCTA_MRWCR0_D0MRCMD1;
		mrwcr_set |= (uint32_t)rop->op << OCTA_MRWCR0_D0MRCMD0_POS;
		mrwcsr_clear |= OCTA_MRWCSR_MRO0 | OCTA_MRWCSR_MRCL0 | OCTA_MRWCSR_MRAL0;
		if (rop->transfer_is_ddr && ~rop->transfer_flag & XSPI_FLAGS_SEQUENTIAL_DDR) {
			mrwcsr_set |= 1u << OCTA_MRWCSR_MRO0_POS;
		}
		mrwcsr_set |= rop->op_size << OCTA_MRWCSR_MRCL0_POS;
		mrwcsr_set |= rop->address_size << OCTA_MRWCSR_MRAL0_POS;
		mmio_clrsetbits_32(myctrl->reg_base + OCTA_DRCSTR, drcstr_clear, drcstr_set);
	}
	if (wop) {
		uint32_t dwcstr_clear, dwcstr_set;
		dwcstr_clear = dwcstr_set = 0;
		dwcstr_clear |= OCTA_DWCSTR_DVWLO0|OCTA_DWCSTR_DVWHI0|OCTA_DWCSTR_DVWCMD0;
		dwcstr_set |= wop->slch_value << OCTA_DWCSTR_DVWLO0_POS;
		dwcstr_set |= wop->clsh_value << OCTA_DWCSTR_DVWHI0_POS;
		dwcstr_set |= wop->shsl_value << OCTA_DWCSTR_DVWCMD0_POS;
		mdlr_clear |= OCTA_MDLR_DV0WDL;
		mdlr_set |= wop->dummy_cycles << OCTA_MDLR_DV0WDL_POS;
		mrwcr_clear |= OCTA_MRWCR0_D0MWCMD0 | OCTA_MRWCR0_D0MWCMD1;
		mrwcr_set |= (uint32_t)wop->op << OCTA_MRWCR0_D0MWCMD0_POS;
		mrwcsr_clear |= OCTA_MRWCSR_MWO0 | OCTA_MRWCSR_MWCL0 | OCTA_MRWCSR_MWAL0;
		if (wop->transfer_is_ddr && ~wop->transfer_flag & XSPI_FLAGS_SEQUENTIAL_DDR) {
			mrwcsr_set |= 1u << OCTA_MRWCSR_MWO0_POS;
		}
		mrwcsr_set |= wop->op_size << OCTA_MRWCSR_MWCL0_POS;
		mrwcsr_set |= wop->address_size << OCTA_MRWCSR_MWAL0_POS;
		mmio_clrsetbits_32(myctrl->reg_base + OCTA_DWCSTR, dwcstr_clear, dwcstr_set);
	}
	mmio_clrsetbits_32(myctrl->reg_base + OCTA_MDLR, mdlr_clear, mdlr_set);
	mmio_clrsetbits_32(myctrl->reg_base + OCTA_MRWCR0, mrwcr_clear, mrwcr_set);
	mmio_clrsetbits_32(myctrl->reg_base + OCTA_MRWCSR, mrwcsr_clear, mrwcsr_set);
}

static int octa_configure_xip(xspi_ctrl_t * const ctrl, xspi_op_t const * const rop, xspi_op_t const * const wop)
{
	assert(ctrl);
	assert(!!rop||!!wop);
	if (!rop && !wop) return -1;
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	xspi_op_t const * op = NULL;
	if (wop) {
		op = wop;
		octa_test_ddr(wop);
		octa_test_form(myctrl, wop);
	}
	if (rop) {
		op = rop;
		octa_test_ddr(rop);
		octa_test_form(myctrl, rop);
	}
	if (rop && wop) {
		assert(rop->form==wop->form);
		assert(rop->op_is_ddr==wop->op_is_ddr && rop->address_is_ddr==wop->address_is_ddr && rop->transfer_is_ddr==wop->transfer_is_ddr);
	}

	uint32_t cdsr_clear, cdsr_set, mdtr_clear, mdtr_set;
	cdsr_clear = cdsr_set = mdtr_clear = mdtr_set = 0;

	int transfer_type;
	int enable_counter;

	switch (op->form) {
	case SPI_FORM_8_8_8:
		if (op->op_is_ddr) {
			/* DOPI */
			if (myctrl->device_type == OCTA_DSR_TYP_RAM) {
				transfer_type = OCTA_CDSR_DVTTYP_DOPI;
				if (rop) {
					enable_counter = rop->dummy_cycles + 1;
					if (enable_counter > 15) enable_counter = 15;
					mdtr_clear |= OCTA_MDTR_DQSERAM;
					mdtr_set |= enable_counter << OCTA_MDTR_DQSERAM_POS;
				}
				if (myctrl->channel && !RZA3) {
					mmio_clrsetbits_32(myctrl->reg_base + OCTA_DRCSTR, OCTA_DRCSTR_CTR1, 0);
				}
				else if (!myctrl->channel) {
					mmio_clrsetbits_32(myctrl->reg_base + OCTA_DRCSTR, OCTA_DRCSTR_CTR0, 0);
				}
			}
			else {
				transfer_type = OCTA_CDSR_DVTTYP_DOPI;
				if (rop) {
					enable_counter = rop->dummy_cycles + 2;
					if (enable_counter > 15) enable_counter = 15;
					mdtr_clear |= OCTA_MDTR_DQSEDOPI;
					mdtr_set |= enable_counter << OCTA_MDTR_DQSEDOPI_POS;
				}
				if (myctrl->channel && !RZA3) {
					mmio_clrsetbits_32(myctrl->reg_base + OCTA_DRCSTR, OCTA_DRCSTR_CTR1, OCTA_DRCSTR_CTR1);
				}
				else if (!myctrl->channel) {
					mmio_clrsetbits_32(myctrl->reg_base + OCTA_DRCSTR, OCTA_DRCSTR_CTR0, OCTA_DRCSTR_CTR0);
				}
			}
		}
		else {
			/* SOPI */
			transfer_type = OCTA_CDSR_DVTTYP_SOPI;
			if (rop) {
				enable_counter = rop->dummy_cycles + 4;
				if (enable_counter > 15) enable_counter = 15;
				mdtr_clear |= OCTA_MDTR_DQSESOPI;
				mdtr_set |= enable_counter << OCTA_MDTR_DQSESOPI_POS;
			}
			if (myctrl->channel && !RZA3) {
				mmio_clrsetbits_32(myctrl->reg_base + OCTA_DRCSTR, OCTA_DRCSTR_CTR1, 0);
			}
			else if (!myctrl->channel) {
				mmio_clrsetbits_32(myctrl->reg_base + OCTA_DRCSTR, OCTA_DRCSTR_CTR0, 0);
			}
		}
		break;
	case SPI_FORM_1_1_1:
		transfer_type = OCTA_CDSR_DVTTYP_SPI;
		break;
	default:
		ERROR("Unsupported transfer form %d\n", rop->form);
		return -1;
	}

	if (myctrl->channel) {
		octa_configure_xip_ch1(myctrl, rop, wop);
		cdsr_clear |= OCTA_CDSR_DV1TTYP;
		cdsr_set |= transfer_type << OCTA_CDSR_DV1TTYP_POS;
		cdsr_clear |= OCTA_CDSR_DV1PC;
	}
	else {
		octa_configure_xip_ch0(myctrl, rop, wop);
		cdsr_clear |= OCTA_CDSR_DV0TTYP;
		cdsr_set |= transfer_type << OCTA_CDSR_DV0TTYP_POS;
		cdsr_clear |= OCTA_CDSR_DV0PC;
	}

	mmio_clrsetbits_32(myctrl->reg_base + OCTA_MDTR, mdtr_clear, mdtr_set);
	mmio_clrsetbits_32(myctrl->reg_base + OCTA_CDSR, cdsr_clear, cdsr_set);

	return 0;
}

static int octa_start_xip(xspi_ctrl_t * const ctrl)
{
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	/* Flush write buffer for OCTA controller register space */
	mmio_read_32(myctrl->reg_base + OCTA_DCR);
	/* Invalidate cache */
	inv_dcache_range(myctrl->mmap_base, myctrl->mmap_size);

	return 0;
}

static int octa_stop_xip(xspi_ctrl_t * const ctrl)
{
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	/* Clean cache */
	clean_dcache_range(myctrl->mmap_base, myctrl->mmap_size);

	return 0;
}

#define DELAY_LEVELS 16
static int get_ok_area_start(bool *p_s_ok_ng_result)
{
	int index;             /**< loop counter */
	int index_start = -1;

	/* detect ok area index start */
	for (index = 0; index < DELAY_LEVELS; index++ ) {
		if (p_s_ok_ng_result[index]) {
			index_start = index;
			break;
		}
	}
	return index_start;
}

static int get_ok_area_count(bool *p_s_ok_ng_result, int index_start)
{
	int index;             /**< loop counter */
	int ok_cnt = 0;

	/* count number of ok */
	for (index = index_start; index < DELAY_LEVELS; index++) {
		if (p_s_ok_ng_result[index]) {
			ok_cnt++;
		}
		else
		{
			break;
		}

	}
	return ok_cnt;
}

static int octa_manual_calibration_common(octa_ctrl_t *myctrl)
{
	volatile uint32_t * p_preamble;
	int    judge_result;
	int    i;
	int index;             /**< loop counter */
	int index_start = -1;
	int ok_cnt = 0;
	bool is_ok[DELAY_LEVELS];

	uint32_t mdtr = mmio_read_32(myctrl->reg_base + OCTA_MDTR);
	uint32_t mdtr_save = mdtr;
	int mdtr_pos;
	if (myctrl->channel) {
		mdtr &= ~OCTA_MDTR_DV1DEL;
		mdtr_pos = OCTA_MDTR_DV1DEL_POS;
	}
	else {
		mdtr &= ~OCTA_MDTR_DV0DEL;
		mdtr_pos = OCTA_MDTR_DV0DEL_POS;
	}

	/* detect ok/ng area */
	uintptr_t offset = (uintptr_t)myctrl->calibration_base;
	offset += myctrl->mmap_base;
	p_preamble = (uint32_t*)offset;
	for (index = 0; index < DELAY_LEVELS; index++) {
		/* Set DQS delay value */
		mmio_write_32(myctrl->reg_base + OCTA_MDTR, mdtr | (index * 256 / DELAY_LEVELS) << mdtr_pos);
		mmio_read_32(myctrl->reg_base + OCTA_MDTR);

		/* Read preamble data and test */
		judge_result = 0;

		inv_dcache_range((uintptr_t)p_preamble, 16);
		for (i = 0; i < 4; i++) {
			if (preamble[i] != p_preamble[i]) {
				judge_result = 1;
				break;
			}
		}

		/* Store the judgement result in the table */
		if (0 == judge_result) {
			is_ok[index] = true;
		}
		else { /* Continuous OK region */
			is_ok[index] = false;
		}
	}

	/* Search for the start index of the OK area */
	index_start = get_ok_area_start(is_ok);
	if ((-1) == index_start) {
		/* restore old value */
		mmio_write_32(myctrl->reg_base + OCTA_MDTR, mdtr_save);
		mmio_read_32(myctrl->reg_base + OCTA_MDTR);
		return -1; /* OK area not found */
	}

	/* Find the number of OK areas */
	ok_cnt = get_ok_area_count(is_ok, index_start);

	if (3 < ok_cnt) {
		/* Set DQS delay value */
		uint32_t delay = (index_start + (ok_cnt >> 1)) * (256 / DELAY_LEVELS);
		mmio_write_32(myctrl->reg_base + OCTA_MDTR, mdtr | delay << mdtr_pos);
		mmio_read_32(myctrl->reg_base + OCTA_MDTR);
		return 0;
	}
	else {
		/* restore old value */
		mmio_write_32(myctrl->reg_base + OCTA_MDTR, mdtr_save);
		mmio_read_32(myctrl->reg_base + OCTA_MDTR);
		return -1;
	}
}

static void octa_write_preamble_pattern(octa_ctrl_t *myctrl)
{
	const uint32_t * pattern = &preamble[0];
	uintptr_t wp = myctrl->mmap_base;
	wp += (uintptr_t)myctrl->calibration_base;
	volatile uint32_t * w_pattern = (uint32_t*)wp;
	*w_pattern++ = *pattern++;
	*w_pattern++ = *pattern++;
	*w_pattern++ = *pattern++;
	*w_pattern++ = *pattern++;
	clean_dcache_range(wp, 16);
}

static int octa_manual_calibration_ch0(octa_ctrl_t *myctrl)
{
	int result;
	static bool is_prepared = false;
	uint32_t cdsr = mmio_read_32(myctrl->reg_base + OCTA_CDSR);
	uint32_t ch0_transfer_type = (cdsr & OCTA_CDSR_DV0TTYP) >> OCTA_CDSR_DV0TTYP_POS;
	if (ch0_transfer_type != OCTA_CDSR_DVTTYP_DOPI) return 0;
	if (!is_prepared) {
		uint32_t dsr0 = mmio_read_32(myctrl->reg_base + OCTA_DSR0);
		uint32_t ch0_device_type = (dsr0 & OCTA_DSR0_DV0TYP) >> OCTA_DSR0_DV0TYP_POS;
		if (ch0_device_type == OCTA_DSR_TYP_RAM) {
			octa_write_preamble_pattern(myctrl);
		}
		is_prepared = true;
	}
	if (octa_manual_calibration_common(myctrl) < 0) {
		ERROR("octa.c:%s Fail on manual calibration\n", __func__);
		result = -1;
	}
	else {
		is_calibrated[0] = true;
		result = 0;
	}
	return result;
}

static int octa_manual_calibration_ch1(octa_ctrl_t *myctrl)
{
	int result;
	static bool is_prepared = false;
	uint32_t cdsr = mmio_read_32(myctrl->reg_base + OCTA_CDSR);
	uint32_t ch1_transfer_type = (cdsr & OCTA_CDSR_DV1TTYP) >> OCTA_CDSR_DV1TTYP_POS;
	if (ch1_transfer_type != OCTA_CDSR_DVTTYP_DOPI) return 0;
	if (!is_prepared) {
		uint32_t dsr1 = mmio_read_32(myctrl->reg_base + OCTA_DSR1);
		uint32_t ch1_device_type = (dsr1 & OCTA_DSR1_DV1TYP) >> OCTA_DSR1_DV1TYP_POS;
		if (ch1_device_type == OCTA_DSR_TYP_RAM) {
			octa_write_preamble_pattern(myctrl);
		}
		is_prepared = true;
	}
	if (octa_manual_calibration_common(myctrl) < 0) {
		ERROR("octa.c:%s Fail on manual calibration\n", __func__);
		result = -1;
	}
	else {
		is_calibrated[1] = true;
		result = 0;
	}
	return result;
}

static int octa_run_manual_calibration(xspi_ctrl_t * const ctrl)
{
	assert(ctrl);
	int result;
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	if (myctrl->channel) {
		/* Channel 1 */
		result = octa_manual_calibration_ch1(myctrl);
	}
	else {
		/* Channel 0 */
		result = octa_manual_calibration_ch0(myctrl);
	}

	return result;
}

static int octa_enable_auto_calibration(xspi_ctrl_t * const ctrl)
{
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	uint32_t cdsr = mmio_read_32(myctrl->reg_base + OCTA_CDSR);
	bool en;

	/* Check condition per channel and set/reset ACMEME */
	if (myctrl->channel) {
		en = is_calibrated[1] &&
			(cdsr & OCTA_CDSR_DV1TTYP) == (OCTA_CDSR_DVTTYP_DOPI << OCTA_CDSR_DV1TTYP_POS);
		if (en) cdsr |= OCTA_CDSR_ACMEME1;
		else cdsr &= ~OCTA_CDSR_ACMEME1;
	}
	else {
		en = is_calibrated[0] &&
			(cdsr & OCTA_CDSR_DV0TTYP) == (OCTA_CDSR_DVTTYP_DOPI << OCTA_CDSR_DV0TTYP_POS);
		if (en) cdsr |= OCTA_CDSR_ACMEME0;
		else cdsr &= ~OCTA_CDSR_ACMEME0;
	}

	/* Set/reset ACMODE */
	octa_set_acmode(&cdsr);
	mmio_write_32(myctrl->reg_base + OCTA_CDSR, cdsr & ~OCTA_CDSR_ACMODE);
	mmio_write_32(myctrl->reg_base + OCTA_CDSR, cdsr);

	return 0;
}

static int octa_disable_auto_calibration(xspi_ctrl_t * const ctrl)
{
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	uint32_t cdsr = mmio_read_32(myctrl->reg_base + OCTA_CDSR);

	/* Reset ACMEMEn */
	if (myctrl->channel) {
		cdsr &= ~OCTA_CDSR_ACMEME1;
	}
	else {
		cdsr &= ~OCTA_CDSR_ACMEME0;
	}

	/* Reset ACMODE */
	cdsr &= ~OCTA_CDSR_ACMODE;
	mmio_write_32(myctrl->reg_base + OCTA_CDSR, cdsr);

	return 0;
}

static int octa_set_frequency(xspi_ctrl_t * const ctrl, int frequency_hz)
{
	assert(ctrl);
	assert(frequency_hz > 0);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;

	freq[myctrl->channel] = frequency_hz;
	int freq_request;

	freq_request = freq[0];
	if (freq_request > freq[1]) freq_request = freq[1];

	int result = cpg_set_xspi_clock(XSPI_CLOCK_OCTA, freq_request * 4);
	if (result != 0) return result;
	int actual_freq = cpg_get_xspi_clock(XSPI_CLOCK_OCTA);
	if (actual_freq == -1) return -1;
	spi_clock = actual_freq / 4;

	return 0;
}

static int octa_clean_mmap(xspi_ctrl_t * const ctrl)
{
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	clean_dcache_range(myctrl->mmap_base, myctrl->mmap_size);

	return 0;
}

static int octa_inv_mmap(xspi_ctrl_t * const ctrl)
{
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	inv_dcache_range(myctrl->mmap_base, myctrl->mmap_size);

	return 0;
}

static uintptr_t octa_get_mmap_base(xspi_ctrl_t * const ctrl)
{
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	return myctrl->mmap_base;
}

static size_t octa_get_mmap_size(xspi_ctrl_t * const ctrl)
{
	assert(ctrl);
	octa_ctrl_t * myctrl = (octa_ctrl_t *)ctrl;
	return myctrl->mmap_size;
}

static uint32_t octa_get_features(xspi_ctrl_t * const ctrl)
{
	(void)ctrl;
	uint32_t features = 0;
	features |= XSPI_FEATURE_FORM888;
	features |= XSPI_FEATURE_DDR;
	features |= XSPI_FEATURE_DDROP;
	features |= XSPI_FEATURE_XIP_READ;
	features |= XSPI_FEATURE_XIP_WRITE;

	return features;
}
