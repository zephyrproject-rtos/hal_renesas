/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_MCU_FAMILY_CFG_U2B10_H_
#define BSP_MCU_FAMILY_CFG_U2B10_H_
#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_mcu_device_core_cfg.h"
#include "bsp_mcu_device_cfg.h"
#include "bsp_mcu_info.h"
#include "bsp_override.h"
#include "bsp_clock_cfg.h"
#ifndef BSP_MCU_GROUP_RH850
 #define BSP_MCU_GROUP_RH850               (1)
#endif

#ifndef BSP_FENMI_VECTOR_TABLE_ENTRIES
 #define BSP_FENMI_VECTOR_TABLE_ENTRIES    (1)
#endif

#ifndef BSP_FE_VECTOR_TABLE_ENTRIES
 #define BSP_FE_VECTOR_TABLE_ENTRIES       (3)
#endif

#ifndef BSP_EIC_VECTOR_TABLE_ENTRIES
 #define BSP_EIC_VECTOR_TABLE_ENTRIES      (1024)
#endif

#ifndef BSP_VECTOR_TABLE_MAX_ENTRIES
 #define BSP_VECTOR_TABLE_MAX_ENTRIES      (BSP_EIC_VECTOR_TABLE_ENTRIES + BSP_FE_VECTOR_TABLE_ENTRIES + \
                                            BSP_FENMI_VECTOR_TABLE_ENTRIES)
#endif
#endif                                 /* BSP_MCU_FAMILY_CFG_H_ */
