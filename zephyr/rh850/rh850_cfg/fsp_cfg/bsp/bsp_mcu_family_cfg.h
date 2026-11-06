/*
 * Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its
 * affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef BSP_MCU_FAMILY_CFG_H_
#define BSP_MCU_FAMILY_CFG_H_

#if defined(CONFIG_SOC_R7F70254XFABG_C) ||                                     \
    defined(CONFIG_SOC_R7F70254XFABA_C) ||                                     \
    defined(CONFIG_SOC_R7F70254XFABB_C) ||                                     \
    defined(CONFIG_SOC_R7F70254XAFABG_C) ||                                    \
    defined(CONFIG_SOC_R7F70254XAFABA_C) ||                                    \
    defined(CONFIG_SOC_R7F70254XAFABB_C)
#include "bsp_mcu_family_cfg_u2b10.h"
#else
#error "Unsupported RH850 SoC"
#endif

#endif /* BSP_MCU_FAMILY_CFG_H_ */
