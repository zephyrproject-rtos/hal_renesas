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

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <zephyr/irq.h>
#include <system_DA1469x.h>
#include <da1469x_config.h>
#include <da1469x_lcdc.h>
#include <zephyr/sys/util.h>

#define CLK_SYS_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(CRG_SYS_CLK_SYS_REG_ ## _field ## _Msk)) | 	\
	(((_val) << CRG_SYS_CLK_SYS_REG_ ## _field ## _Pos) & 	\
	CRG_SYS_CLK_SYS_REG_ ## _field ## _Msk)

#define LCDC_BGCOLOR_REG_SET_FIELD(_field, _var, _val) 	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_BGCOLOR_REG_ ## _field ## _Msk)) | 	\
	(((_val) << LCDC_LCDC_BGCOLOR_REG_ ## _field ## _Pos) & 	\
	LCDC_LCDC_BGCOLOR_REG_ ## _field ## _Msk)

#define LCDC_RESXY_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_RESXY_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_RESXY_REG_ ## _field ## _Pos) & 	\
	LCDC_LCDC_RESXY_REG_ ## _field ## _Msk)

#define LCDC_FRONTPORCHXY_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_FRONTPORCHXY_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_FRONTPORCHXY_REG_ ## _field ## _Pos) &	\
	LCDC_LCDC_FRONTPORCHXY_REG_ ## _field ## _Msk)

#define LCDC_BLANKINGXY_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_BLANKINGXY_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_BLANKINGXY_REG_ ## _field ## _Pos) & 	\
	LCDC_LCDC_BLANKINGXY_REG_ ## _field ## _Msk)

#define LCDC_BACKPORCHXY_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_BACKPORCHXY_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_BACKPORCHXY_REG_ ## _field ## _Pos) &		\
	LCDC_LCDC_BACKPORCHXY_REG_ ## _field ## _Msk)

#define LCDC_DBIB_CMD_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_DBIB_CMD_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_DBIB_CMD_REG_ ## _field ## _Pos) &	\
	LCDC_LCDC_DBIB_CMD_REG_ ## _field ## _Msk)

#define LCDC_CLKCTRL_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_CLKCTRL_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_CLKCTRL_REG_ ## _field ## _Pos) &		\
	LCDC_LCDC_CLKCTRL_REG_ ## _field ## _Msk)

#define LCDC_DBIB_CFG_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_DBIB_CFG_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_DBIB_CFG_REG_ ## _field ## _Pos) &	\
	LCDC_LCDC_DBIB_CFG_REG_ ## _field ## _Msk)

#define LCDC_LAYER0_STARTXY_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_LAYER0_STARTXY_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_LAYER0_STARTXY_REG_ ## _field ## _Pos) &	\
	LCDC_LCDC_LAYER0_STARTXY_REG_ ## _field ## _Msk)

#define LCDC_LAYER0_MODE_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_LAYER0_MODE_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_LAYER0_MODE_REG_ ## _field ## _Pos) &		\
	LCDC_LCDC_LAYER0_MODE_REG_ ## _field ## _Msk)

#define LCDC_LAYER0_STRIDE_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_LAYER0_STRIDE_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_LAYER0_STRIDE_REG_ ## _field ## _Pos) &	\
	LCDC_LCDC_LAYER0_STRIDE_REG_ ## _field ## _Msk)

#define LCDC_LAYER0_SIZEXY_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_LAYER0_SIZEXY_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_LAYER0_SIZEXY_REG_ ## _field ## _Pos) &	\
	LCDC_LCDC_LAYER0_SIZEXY_REG_ ## _field ## _Msk)

#define LCDC_LAYER0_RESXY_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_LAYER0_RESXY_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_LAYER0_RESXY_REG_ ## _field ## _Pos) &	\
	LCDC_LCDC_LAYER0_RESXY_REG_ ## _field ## _Msk)

#define LCDC_MODE_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(LCDC_LCDC_MODE_REG_ ## _field ## _Msk)) |	\
	(((_val) << LCDC_LCDC_MODE_REG_ ## _field ## _Pos) & 	\
	LCDC_LCDC_MODE_REG_ ## _field ## _Msk)

#define LCDC_DBIB_CMD_REG_GET_FIELD(_field)	\
	((LCDC->LCDC_DBIB_CMD_REG & LCDC_LCDC_DBIB_CMD_REG_ ## _field ## _Msk) >>	\
	LCDC_LCDC_DBIB_CMD_REG_ ## _field ## _Pos)

#define LCDC_DBIB_CFG_REG_GET_FIELD(_field)	\
	((LCDC->LCDC_DBIB_CFG_REG & LCDC_LCDC_DBIB_CFG_REG_ ## _field ## _Msk) >>	\
	LCDC_LCDC_DBIB_CFG_REG_ ## _field ## _Pos)

/* Min. horizontal frame width, in pixels, required by the host controller */
#define MIPI_DBI_SMARTBOND_MIN_ACTIVE_FRAME_WIDTH    4

/**
 * Write to DBIB configuration register
 *
 * @param value  Value to be written to DBIB configuration register
 *
 */
static inline void
lcdc_dbib_cfg_reg_write(uint32_t value)
{
	while (LCDC_STATUS_REG_GET_FIELD(LCDC_DBIB_CMD_FIFO_FULL));
	LCDC->LCDC_DBIB_CFG_REG = value;
}

uint16_t
da1469x_lcdc_stride_calculation(uint8_t lcm, uint16_t x_res)
{
	uint8_t num_of_bytes = 0;

	switch (lcm) {
	case LCDC_SMARTBOND_L0_RGBA8888:
	case LCDC_SMARTBOND_L0_ARGB8888:
	case LCDC_SMARTBOND_L0_ABGR8888:
	case LCDC_SMARTBOND_L0_BGRA8888:
		num_of_bytes = 4;
		break;
	case LCDC_SMARTBOND_L0_RGBA5551:
	case LCDC_SMARTBOND_L0_RGB565:
		num_of_bytes = 2;
		break;
	case LCDC_SMARTBOND_L0_RGB332:
	case LCDC_SMARTBOND_L0_L8:
		num_of_bytes = 1;
		break;
	case LCDC_SMARTBOND_L0_L1:
		num_of_bytes = DIV_ROUND_UP(x_res, 8);
		break;
	case LCDC_SMARTBOND_L0_L4:
		num_of_bytes = DIV_ROUND_UP(x_res, 4);
		break;
	default:
		assert(0);
		break;
	}

	return (((num_of_bytes * x_res) + 0x3) & ~0x3);
}

void
da1469x_lcdc_force_cs_line(bool force, bool cs_level)
{
	uint32_t lcdc_dbib_cfg_reg = LCDC->LCDC_DBIB_CFG_REG;
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_CSX_FORCE, lcdc_dbib_cfg_reg, force ? 1 : 0);
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_CSX_FORCE_VAL, lcdc_dbib_cfg_reg, cs_level ? 1 : 0);
	lcdc_dbib_cfg_reg_write(lcdc_dbib_cfg_reg);
}

void
da1469x_lcdc_send_cmd_data(bool cmd, const uint8_t *buf, size_t len)
{
	uint32_t lcdc_dbib_cmd_reg = 0;

	for (int i = 0; i < len; i++) {

		/*
		 * Workaround for D/C not aligned correctly with CLK. If SPI4 and not using hold and
		 * type changes wait until DBIB FIFO is empty. In any other case wait until there is
		 * some space empty in FIFO.
		 */
		if (LCDC_DBIB_CFG_REG_GET_FIELD(LCDC_DBIB_SPI4_EN) &&
			!LCDC_DBIB_CFG_REG_GET_FIELD(LCDC_DBIB_SPI_HOLD) &&
				LCDC_DBIB_CMD_REG_GET_FIELD(LCDC_DBIB_CMD_SEND) != cmd) {
			while (LCDC_STATUS_REG_GET_FIELD(LCDC_DBIB_CMD_PENDING));
		} else {
			while (LCDC_STATUS_REG_GET_FIELD(LCDC_DBIB_CMD_FIFO_FULL));
		}

		LCDC_DBIB_CMD_REG_SET_FIELD(LCDC_DBIB_CMD_SEND, lcdc_dbib_cmd_reg, cmd ? 0x1 : 0x0);
		LCDC_DBIB_CMD_REG_SET_FIELD(LCDC_DBIB_CMD_VAL, lcdc_dbib_cmd_reg, buf[i]);
		LCDC->LCDC_DBIB_CMD_REG = lcdc_dbib_cmd_reg;
	}
}

int
da1469x_lcdc_layer_configure(lcdc_smartbond_layer_cfg *layer)
{
	uint32_t reg = 0;

	/* Check against LCDC requirements */
	if (layer->frame_buf & 0x3) {
		assert(0);
		return -EIO;
	}
	if (layer->stride & 0x3) {
		assert(0);
		return -EIO;
	}

	/* Controller's DMA can only handle physical addresses */
	LCDC->LCDC_LAYER0_BASEADDR_REG = black_orca_phy_addr(layer->frame_buf);

	LCDC_LAYER0_STARTXY_REG_SET_FIELD(LCDC_L0_START_X, reg, layer->start_x);
	LCDC_LAYER0_STARTXY_REG_SET_FIELD(LCDC_L0_START_Y, reg, layer->start_y);
	LCDC->LCDC_LAYER0_STARTXY_REG = reg;

	LCDC_LAYER0_SIZEXY_REG_SET_FIELD(LCDC_L0_SIZE_X, reg, layer->size_x);
	LCDC_LAYER0_SIZEXY_REG_SET_FIELD(LCDC_L0_SIZE_Y, reg, layer->size_y);
	LCDC->LCDC_LAYER0_SIZEXY_REG = reg;

	LCDC_LAYER0_RESXY_REG_SET_FIELD(LCDC_L0_RES_X, reg, layer->size_x);
	LCDC_LAYER0_RESXY_REG_SET_FIELD(LCDC_L0_RES_Y, reg, layer->size_y);
	LCDC->LCDC_LAYER0_RESXY_REG = reg;

	/*
	 * Stride should be updated while there is no active frame activity. However, in the
	 * continuous mode (RGB or JDI parallel interfaces) there is no partial update and so
	 * stride is not changed at runtime. For the rest of the layer settings, and while in
	 * continuous mode, there is a protection mechanism that updates layer settings upon
	 * completion of the current active frame.
	 */
	reg = LCDC->LCDC_LAYER0_STRIDE_REG;
	LCDC_LAYER0_STRIDE_REG_SET_FIELD(LCDC_L0_STRIDE, reg, layer->stride);
	LCDC->LCDC_LAYER0_STRIDE_REG = reg;

	LCDC_LAYER0_MODE_REG_SET_FIELD(LCDC_L0_EN, reg, 1);
	LCDC_LAYER0_MODE_REG_SET_FIELD(LCDC_L0_COLOUR_MODE, reg, layer->color_format);
	LCDC->LCDC_LAYER0_MODE_REG = reg;

	return 0;
}

void
da1469x_lcdc_bgcolor_configure(lcdc_smartbond_bgcolor_cfg *bgcolor)
{
	uint32_t lcdc_bgcolor_reg = 0;
	LCDC_BGCOLOR_REG_SET_FIELD(LCDC_BG_RED, lcdc_bgcolor_reg, bgcolor->red);
	LCDC_BGCOLOR_REG_SET_FIELD(LCDC_BG_GREEN, lcdc_bgcolor_reg, bgcolor->green);
	LCDC_BGCOLOR_REG_SET_FIELD(LCDC_BG_BLUE, lcdc_bgcolor_reg, bgcolor->blue);
	LCDC_BGCOLOR_REG_SET_FIELD(LCDC_BG_ALPHA, lcdc_bgcolor_reg, bgcolor->alpha);
	LCDC->LCDC_BGCOLOR_REG = lcdc_bgcolor_reg;
}

void
da1469x_lcdc_set_status(bool enable, bool div1, uint8_t clk_div)
{
	unsigned int key;
	uint32_t clk_sys_reg;

	/* Globally disable interrupts as some registers may also be used by other devices */
	key = DA1469X_IRQ_DISABLE();
	clk_sys_reg = CRG_SYS->CLK_SYS_REG;

	if (enable) {
		CLK_SYS_REG_SET_FIELD(LCD_CLK_SEL, clk_sys_reg, div1);
		CLK_SYS_REG_SET_FIELD(LCD_ENABLE, clk_sys_reg, 1);

		irq_enable(LCD_CONTROLLER_IRQn);
	} else {
		/* Forcefully reset the host controller */
		CRG_SYS->CLK_SYS_REG |= CRG_SYS_CLK_SYS_REG_LCD_RESET_REQ_Msk;
		CLK_SYS_REG_SET_FIELD(LCD_RESET_REQ, clk_sys_reg, 0);
		CLK_SYS_REG_SET_FIELD(LCD_CLK_SEL, clk_sys_reg, 0);
		CLK_SYS_REG_SET_FIELD(LCD_ENABLE, clk_sys_reg, 0);

		irq_disable(LCD_CONTROLLER_IRQn);
	}

	CRG_SYS->CLK_SYS_REG = clk_sys_reg;

	/*
	 * Setup the correct clock divider to achieve the requested pixel speed.
	 * Zero value means division by one.
	 */
	LCDC_CLKCTRL_REG_SET_FIELD(LCDC_CLK_DIV, LCDC->LCDC_CLKCTRL_REG,
						clk_div ? clk_div - 1 : clk_div);
	DA1469X_IRQ_ENABLE(key);
}

int
da1469x_lcdc_timings_configure(uint16_t x_res, uint16_t y_res, lcdc_smartbond_timing_cfg *timing)
{
	uint16_t resx = x_res;
	uint16_t resy = y_res;
	uint32_t lcdc_resxy_reg = 0;

	/* Check if the active frame confronts to host requirements */
	if (resx < MIPI_DBI_SMARTBOND_MIN_ACTIVE_FRAME_WIDTH) {
		assert(0);
		return -EIO;
	}

	LCDC_RESXY_REG_SET_FIELD(LCDC_RES_X, lcdc_resxy_reg, resx);
	LCDC_RESXY_REG_SET_FIELD(LCDC_RES_Y, lcdc_resxy_reg, resy);
	LCDC->LCDC_RESXY_REG = lcdc_resxy_reg;

	/* Bug fix: LCDC will produce minus 1 pixel period so value should be increased by one. */
	resx += (timing->hfront_porch ? timing->hfront_porch + 1 : timing->hfront_porch);
	resy += timing->vfront_porch;

	LCDC_FRONTPORCHXY_REG_SET_FIELD(LCDC_FPORCH_X, lcdc_resxy_reg, resx);
	LCDC_FRONTPORCHXY_REG_SET_FIELD(LCDC_FPORCH_Y, lcdc_resxy_reg, resy);
	LCDC->LCDC_FRONTPORCHXY_REG = lcdc_resxy_reg;

	/* LCDC imposes min values for X and Y blanking window */
	resx += MAX(timing->hsync_len, LCDC_SMARTBOND_HSYN_MIN_LEN);
	resy += MAX(timing->vsync_len, LCDC_SMARTBOND_VSYN_MIN_LEN);

	LCDC_BLANKINGXY_REG_SET_FIELD(LCDC_BLANKING_X, lcdc_resxy_reg, resx);
	LCDC_BLANKINGXY_REG_SET_FIELD(LCDC_BLANKING_Y, lcdc_resxy_reg, resy);
	LCDC->LCDC_BLANKINGXY_REG = lcdc_resxy_reg;

	/* Bug fix: LCDC will produce plus 1 pixel period so value should be decreased by one. */
	resx += (timing->hback_porch ? timing->hback_porch - 1 : timing->hback_porch);
	resy += timing->vback_porch;

	LCDC_BACKPORCHXY_REG_SET_FIELD(LCDC_BPORCH_X, lcdc_resxy_reg, resx);
	LCDC_BACKPORCHXY_REG_SET_FIELD(LCDC_BPORCH_Y, lcdc_resxy_reg, resy);
	LCDC->LCDC_BACKPORCHXY_REG = lcdc_resxy_reg;

	return 0;
}

void
da1469x_lcdc_te_set_status(bool enable, bool inversion)
{
	uint32_t lcdc_dbib_cfg_reg = LCDC->LCDC_DBIB_CFG_REG;

	if (enable) {
		LCDC->LCDC_GPIO_REG |= (inversion ? LCDC_LCDC_GPIO_REG_LCDC_TE_INV_Msk : 0);
		lcdc_dbib_cfg_reg_write(lcdc_dbib_cfg_reg & ~LCDC_LCDC_DBIB_CFG_REG_LCDC_DBIB_TE_DIS_Msk);
		LCDC->LCDC_INTERRUPT_REG |= (LCDC_LCDC_INTERRUPT_REG_LCDC_TE_IRQ_EN_Msk |
							LCDC_LCDC_INTERRUPT_REG_LCDC_VSYNC_IRQ_EN_Msk);
	} else {
		LCDC->LCDC_INTERRUPT_REG &= ~(LCDC_LCDC_INTERRUPT_REG_LCDC_TE_IRQ_EN_Msk |
							LCDC_LCDC_INTERRUPT_REG_LCDC_VSYNC_IRQ_EN_Msk);
		lcdc_dbib_cfg_reg_write(lcdc_dbib_cfg_reg | LCDC_LCDC_DBIB_CFG_REG_LCDC_DBIB_TE_DIS_Msk);
	}
}

int
da1469x_lcdc_mipi_dbi_interface_configure(lcdc_smartbond_mipi_dbi_cfg *mipi_dbi)
{
	uint32_t lcdc_dbib_cfg_reg = LCDC->LCDC_DBIB_CFG_REG;

	switch (mipi_dbi->line_mode) {
	case LCDC_SMARTBOND_MODE_SPI3:
		LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_SPI3_EN, lcdc_dbib_cfg_reg, 1);
		LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_SPI4_EN, lcdc_dbib_cfg_reg, 0);
		break;
	case LCDC_SMARTBOND_MODE_SPI4:
		LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_SPI4_EN, lcdc_dbib_cfg_reg, 1);
		LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_SPI3_EN, lcdc_dbib_cfg_reg, 0);
		break;
	default:
		assert(0);
		return -EIO;
	}

	/* Common settings required for DBIB engine */
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_DMA_EN, lcdc_dbib_cfg_reg, 1);
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_RESX, lcdc_dbib_cfg_reg, 1);

	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_SPI_CPHA, lcdc_dbib_cfg_reg, mipi_dbi->cpha ? 0 : 1);
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_SPI_CPOL, lcdc_dbib_cfg_reg, mipi_dbi->cpol ? 0 : 1);
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_CSX_FORCE_VAL, lcdc_dbib_cfg_reg,
			mipi_dbi->cs_active_high ? 1 : 0);
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_FMT, lcdc_dbib_cfg_reg, mipi_dbi->color_mode);

	lcdc_dbib_cfg_reg_write(lcdc_dbib_cfg_reg);

	return 0;
}

void
da1469x_lcdc_parallel_interface_configure(lcdc_smartbond_mode_cfg *mode)
{
	uint32_t lcdc_dbib_cfg_reg;
	uint32_t lcdc_mode_reg;

	/* Common settings required for DBIB engine */
	lcdc_dbib_cfg_reg = LCDC->LCDC_DBIB_CFG_REG;
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_DMA_EN, lcdc_dbib_cfg_reg, 1);
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_RESX, lcdc_dbib_cfg_reg, 1);
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_TE_DIS, lcdc_dbib_cfg_reg, 1);

	/* Only RGB222 is supported in RGB parallel interface */
	LCDC_DBIB_CFG_REG_SET_FIELD(LCDC_DBIB_FMT, lcdc_dbib_cfg_reg, LCDC_SMARTBOND_OCM_RGB222);
	lcdc_dbib_cfg_reg_write(lcdc_dbib_cfg_reg);

	/* Configure the mode register */
	lcdc_mode_reg = LCDC->LCDC_MODE_REG;
	LCDC_MODE_REG_SET_FIELD(LCDC_MIPI_OFF, lcdc_mode_reg, 1);
	/* Select RGB interface */
	LCDC_MODE_REG_SET_FIELD(LCDC_OUT_MODE, lcdc_mode_reg, 0);
	LCDC_MODE_REG_SET_FIELD(LCDC_VSYNC_POL, lcdc_mode_reg, mode->vsync_pol);
	LCDC_MODE_REG_SET_FIELD(LCDC_HSYNC_POL, lcdc_mode_reg, mode->hsync_pol);
	LCDC_MODE_REG_SET_FIELD(LCDC_DE_POL, lcdc_mode_reg, mode->de_pol);
	LCDC_MODE_REG_SET_FIELD(LCDC_PIXCLKOUT_POL, lcdc_mode_reg, mode->pixelclk_pol);
	LCDC->LCDC_MODE_REG = lcdc_mode_reg;

	/* Enable RGB parallel interface */
	LCDC->LCDC_GPIO_REG |= LCDC_LCDC_GPIO_REG_LCDC_PARIF_SEL_Msk;
}
