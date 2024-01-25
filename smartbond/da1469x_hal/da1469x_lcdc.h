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

#ifndef __DA1469X_LCDC_H
#define __DA1469X_LCDC_H

#include <stdint.h>
#include <DA1469xAB.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Pixel (output) color formats supported by the display controller */

/** 0 0 R G B R' G' B' */
#define LCDC_SMARTBOND_OCM_8RGB111_1    0x06
/** R G B 0 R' G' B' 0 */
#define LCDC_SMARTBOND_OCM_8RGB111_2    0x07
/** R G B  R' G' B' ... */
#define LCDC_SMARTBOND_OCM_RGB111       0x08
/** D D' D'' ... */
#define LCDC_SMARTBOND_OCM_L1           0x09
/** R[2-0]G[2-0]B[1-0] */
#define LCDC_SMARTBOND_OCM_RGB332       0x10
/** R[3-0]G[3-0] - B[3-0]R'[3-0] - G'[3-0]B'[3-0] */
#define LCDC_SMARTBOND_OCM_RGB444       0x11
/** R[4-0]G[5-3] - G[2-0]B[4-0] */
#define LCDC_SMARTBOND_OCM_RGB565       0x12
/** R[5-0]00 - G[5-0]00 - B[5-0]00 */
#define LCDC_SMARTBOND_OCM_RGB666       0x13
/** R[7-0] - G[7-0] - B[7-0] */
#define LCDC_SMARTBOND_OCM_RGB888       0x14
/* RGB and JDI Parallel Interface */
#define LCDC_SMARTBOND_OCM_RGB222       0x0A

/* Layer (input) color formats supported by the display controller */

/** R[4-0]G[4-0]B[4-0]A0 */
#define LCDC_SMARTBOND_L0_RGBA5551  0x01
/** R[7-0]G[7-0]B[7-0]A[7-0] */
#define LCDC_SMARTBOND_L0_RGBA8888  0x02
/** R[2-0]G[2-0]B[1-0] */
#define LCDC_SMARTBOND_L0_RGB332    0x04
/** R[4-0]G[5-0]B[4-0] */
#define LCDC_SMARTBOND_L0_RGB565    0x05
/** A[7-0]R[7-0]G[7-0]B[7-0] */
#define LCDC_SMARTBOND_L0_ARGB8888  0x06
/** L[7-0] - Grayscale */
#define LCDC_SMARTBOND_L0_L8        0x07
/** L - Black and white, 1 = black, 0 = white */
#define LCDC_SMARTBOND_L0_L1        0x08
/** L[3-0] - Grayscale */
#define LCDC_SMARTBOND_L0_L4        0x09
/** A[7-0]B[7-0]G[7-0]R[7-0] */
#define LCDC_SMARTBOND_L0_ABGR8888  0x0D
/** B[7-0]G[7-0]R[7-0]A[7-0] */
#define LCDC_SMARTBOND_L0_BGRA8888  0x0E

#define LCDC_SMARTBOND_MODE_SPI3 	BIT(0)
#define LCDC_SMARTBOND_MODE_SPI4 	BIT(1)

typedef struct {
	uint16_t vsync_len;
	uint16_t hsync_len;
	uint16_t hfront_porch;
	uint16_t vfront_porch;
	uint16_t vback_porch;
	uint16_t hback_porch;
} lcdc_smartbond_timing_cfg;

typedef struct {
	bool vsync_pol;
	bool hsync_pol;
	bool de_pol;
	bool pixelclk_pol;
} lcdc_smartbond_mode_cfg;

typedef struct {
	bool cpha;
	bool cpol;
	bool cs_active_high;
	uint8_t line_mode;
	uint8_t color_mode;
} lcdc_smartbond_mipi_dbi_cfg;

typedef struct {
	/*
	 * Base address of the frame to be displayed. Should first be translated
	 * to its physical address.
	 */
	uint32_t frame_buf;
	/*
	 * X/Y coordinates of the top-left corner of the layer.
	 * (0, 0) is the top-left corner of the screen.
	 */
	int16_t start_x;
	int16_t start_y;
	/* X/Y resolution of layer in pixels */
	uint16_t size_x;
	uint16_t size_y;
	/* Frame color format */
	uint8_t color_format;
	/* Line to line disctance in bytes of frame in memory */
	int32_t stride;
} lcdc_smartbond_layer_cfg;

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
} lcdc_smartbond_bgcolor_cfg;

/*
 * Min. timing settings required by the timing generator. For the MIPI DBI
 * inferface all timing setting can be safely ignored.
 */
#define LCDC_SMARTBOND_VSYN_MIN_LEN   1
#define LCDC_SMARTBOND_HSYN_MIN_LEN   2

#define LCDC_SMARTBOND_ID   0x87452365

#define LCDC_STATUS_REG_GET_FIELD(_field)							 		\
	((LCDC->LCDC_STATUS_REG & LCDC_LCDC_STATUS_REG_ ## _field ## _Msk) >>	\
	LCDC_LCDC_STATUS_REG_ ## _field ## _Pos)

/* Helper macro to setup the later configuration container */
#define LCDC_SMARTBOND_LAYER_CONFIG(_layer, _buf, _x_start, _y_start, _x_size, _y_size, \
				_color, _stride) \
	(_layer)->frame_buf = (uint32_t)_buf; 			\
	(_layer)->start_x = _x_start; 			  		\
	(_layer)->start_y = _y_start; 			  		\
	(_layer)->size_x = _x_size; 					\
	(_layer)->size_y = _y_size; 					\
	(_layer)->color_format = _color; 				\
	(_layer)->stride = _stride;

/**
 * LCDC stride calculation
 *
 * @param lcm    Layer color format supported by LCDC
 * @param x_res  X resolution in pixels
 *
 * @return Stride value in bytes
 */
uint16_t
da1469x_lcdc_stride_calculation(uint8_t lcm, uint16_t x_res);

/**
 * LCDC layer configuration
 *
 * @param layer  Pointer to structure that contains layer settings
 *
 * @return Zero for success or a negative value indicating the reason of failure
 */
int
da1469x_lcdc_layer_configure(lcdc_smartbond_layer_cfg *layer);

/**
 * DBIB interface to send command or data in SPI3/SPI4 serial interface
 *
 * @param cmd  True if data represents a command, false otherwise
 * @param buf  Buffer with the command or data to be sent
 * @param len  Number of command or data in bytes to be sent
 *
 */
void
da1469x_lcdc_send_cmd_data(bool cmd, const uint8_t *buf, size_t len);

/**
 * LCDC background layer configuration
 *
 * @param bgcolor  Pointer to structure that contains background color settings
 *
 */
void
da1469x_lcdc_bgcolor_configure(lcdc_smartbond_bgcolor_cfg *bgcolor);

/**
 * LCDC set status
 *
 * @param enable  True to enable and false to disable clocking LCDC
 * @param div1    If true DIV1 clock path is used (follows system clocking).
 *                Otherwise, DIVN clock paths is used (follows the external
 *                crystal frequency).
 *
 */
void
da1469x_lcdc_set_status(bool enable, bool div1, uint8_t clk_div);

/**
 * LCDC timing generator configuration
 *
 * @param x_res   X resolution in pixels of active window
 * @param y_res   Y resolution in pixels of active window
 * @param timing  Pointer to structure that contains timings settings
 *
 * @return Zero for success or a negative value indicating the reason of failure
 *
 */
int
da1469x_lcdc_timings_configure(uint16_t x_res, uint16_t y_res, lcdc_smartbond_timing_cfg *timing);

/**
 * Tearing effect (TE) set status
 *
 * @param enable    True to enable TE signaling and false to disble it.
 * @param inversion True to invert TE signaling false otherwise.
 *
 */
void
da1469x_lcdc_te_set_status(bool enable, bool inversion);

/**
 * LCDC configure RGB interface
 *
 * Configure the RGB interface without enabling continous mode.
 *
 * @param mode Pointer to structure that contains RGB related settings
 *
 */
void
da1469x_lcdc_parallel_interface_configure(lcdc_smartbond_mode_cfg *mode);

/**
 * LCDC configure serial (MIPI DBI Type-B) interface
 *
 * @param spi Pointer to structure that contains SPI related settings
 *
 * @return Zero for success or a negative value indicating the reason of failure
 *
 */
int
da1469x_lcdc_mipi_dbi_interface_configure(lcdc_smartbond_mipi_dbi_cfg *mipi_dbi);

/**
 * LCDC force #CS line in SPI interface
 *
 * @param force    True to force #CS line to \p cs_level, false otherwise.
 * @param cs_level True to drive #CS to high level, false otherwise. This
 *                 value also defined the active level of #CS line when is
 *                 not drived forcefully.
 *
 */
void
da1469x_lcdc_force_cs_line(bool force, bool cs_level);

/**
 * Check if LCDC is busy
 *
 * @return True if LCDC is busy generating pixel data or sending DBIB commands/data
 *         false otherwise.
 *
 */
static inline bool
da1469x_lcdc_is_busy(void)
{
	bool ret = false;

	ret |= LCDC_STATUS_REG_GET_FIELD(LCDC_FRAMEGEN_BUSY);
	ret |= LCDC_STATUS_REG_GET_FIELD(LCDC_DBIB_CMD_FIFO_EMPTY_N);

	return ret;
}

/**
 * Check if LCDC has the correct ID
 *
 * @return True if LCDC has the correct magic value false otherwise.
 *
 */
static inline bool
da1469x_lcdc_check_id(void)
{
	return (LCDC->LCDC_IDREG_REG == LCDC_SMARTBOND_ID);
}

#ifdef __cplusplus
}
#endif

#endif  /* __DA1469X_LCDC_H */
