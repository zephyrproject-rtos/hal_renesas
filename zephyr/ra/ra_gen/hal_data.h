/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include "bsp_api.h"

#if CONFIG_INPUT_RENESAS_RA_QE_TOUCH_CFG
#include "rm_touch.h"
#endif

#if CONFIG_LV_USE_DRAW_DAVE2D
#include "dave_base.h"
#include "dave_driver.h"
#include "dave_math.h"
#include "dave_types.h"
#include "r_glcdc.h"
#include <zephyr/devicetree.h>
#include <zephyr/dt-bindings/display/panel.h>
#endif

FSP_HEADER

#if CONFIG_INPUT_RENESAS_RA_QE_TOUCH_CFG
#define CTSU_WRITE_IRQn                                                        \
  (DT_IRQ_BY_NAME(DT_INST(0, renesas_ra_ctsu), ctsuwr, irq))
#define CTSU_READ_IRQn                                                         \
  (DT_IRQ_BY_NAME(DT_INST(0, renesas_ra_ctsu), ctsurd, irq))
#define CTSU_END_IRQn (DT_IRQ_BY_NAME(DT_INST(0, renesas_ra_ctsu), ctsufn, irq))
#endif

FSP_FOOTER
#endif /* HAL_DATA_H_ */
