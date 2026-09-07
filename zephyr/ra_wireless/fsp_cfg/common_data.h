/*
* Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef COMMON_DATA_H_
 #define COMMON_DATA_H_

 #include <stdint.h>
 #include "bsp_api.h"
 #ifdef BSP_MCU_GROUP_RA6W1
  #include "r_gpio_w.h"
 #else
  #include "r_ioport.h"
 #endif
 #include "r_ioport_api.h"
 #include "bsp_pin_cfg.h"
 #if CFG_PMGR
  #include "rm_pmgr_w_instance.h"
 #endif                                /* CFG_PMGR */

 #ifdef __cplusplus
extern "C"
{
 #endif

/* IOPORT Instance */

/* IOPORT control structure. */
 #define IOPORT_CFG_NAME    g_bsp_pin_cfg
 #define IOPORT_CFG_OPEN    R_GPIO_W_Open
 #define IOPORT_CFG_CTRL    g_gpio_w_ctrl
extern const ioport_cfg_t      g_bsp_pin_cfg;
extern const ioport_instance_t g_gpio_w;
extern gpio_w_instance_ctrl_t  g_gpio_w_ctrl;

 #ifdef __cplusplus
}                                      /* extern "C" */
 #endif

#endif /* COMMON_DATA_H_ */
