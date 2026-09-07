/*
 * Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BSP_CFG_H
#define BSP_CFG_H

#include "bsp_clock_cfg.h"

#ifndef __ASSEMBLER__
void bsp_init(void * p_args);
#endif

#define CONFIG_PLL

#define dg_configXTAL_BASED_CPU40M                  (0)
#define dg_configUSE_PM_STATISTICS                  (1)

#ifndef dg_configSYSTEMVIEW
 #define dg_configSYSTEMVIEW                        (0)
#endif

#if (dg_configSYSTEMVIEW == 1)
 #define dg_configSYSTEMVIEW_MONITOR_QUEUE          (0)
 #define dg_configSYSTEMVIEW_MONITOR_MALLOC         (0)
 #define dg_configSYSTEMVIEW_MONITOR_EVENT_GROUP    (0)
 #define dg_configSYSTEMVIEW_STUCK_UNTIL_ATTACH     (0)
#endif

#ifdef dg_configEXEC_MODE
 #undef dg_configEXEC_MODE
#endif
#define dg_configEXEC_MODE         MODE_IS_CACHED

#ifdef dg_configCODE_LOCATION
 #undef dg_configCODE_LOCATION
#endif
#define dg_configCODE_LOCATION     NON_VOLATILE_IS_FLASH

#ifndef dg_configUSE_ROMCRYPTO
 #define dg_configUSE_ROMCRYPTO    (1)
#endif
#if defined(__clang_analyzer__) && defined(BSP_TZ_SECURE_BUILD) && BSP_TZ_SECURE_BUILD

 #include <stdlib.h>
 #ifndef CMSE_AU_NONSECURE
  #define CMSE_AU_NONSECURE    (1)
 #endif

void * cmse_check_address_range(void *, size_t, int);
void * cmse_check_pointed_object(void *, int);
void * cmse_nsfptr_create(void *);
int    cmse_is_nsfptr(void *);

static struct
{
    uint32_t VTOR;
} * SCB_NS;

static struct
{
    uint32_t CTRL;
} * SAU;

 #ifndef SAU_CTRL_ALLNS_Msk
  #define SAU_CTRL_ALLNS_Msk    (0U)
 #endif
 #ifndef __TZ_set_MSP_NS(x)
  #define __TZ_set_MSP_NS(x)    ((void) x)
 #endif

#endif

#if defined(CONFIG_SOC_SERIES_RA6B1)
 #include "bsp_mcu_family_cfg_ra6b1.h"
 #include "bsp_cfg_ra6b1.h"
#elif defined(CONFIG_SOC_SERIES_RA6W_COMMON)
 #include "bsp_mcu_family_cfg_ra6w1.h"
 #include "bsp_cfg_ra6w1.h"
#endif

#if 0
 #ifndef BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET
  #define BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET        (0)
 #endif
#endif

#ifndef BSP_CLOCK_CFG_MAIN_OSC_POPULATED
 #define BSP_CLOCK_CFG_MAIN_OSC_POPULATED            (1)
#endif

#ifndef BSP_CLOCK_CFG_XTAL32M_STABILIZATION_USEC
 #define BSP_CLOCK_CFG_XTAL32M_STABILIZATION_USEC    (0U)
#endif
#ifndef BSP_CLOCK_CFG_SUBCLOCK_POPULATED
 #if defined(BOARD_RA6B1_PRODK)
  #define BSP_CLOCK_CFG_SUBCLOCK_POPULATED           (0)
 #else
  #define BSP_CLOCK_CFG_SUBCLOCK_POPULATED           (1)
 #endif
#endif
#ifndef BSP_CLOCK_CFG_SUBCLOCK_STABILIZATION_MS
 #define BSP_CLOCK_CFG_SUBCLOCK_STABILIZATION_MS     (600U)
#endif
#ifndef BSP_CFG_C_RUNTIME_INIT
 #define BSP_CFG_C_RUNTIME_INIT                      (1)
#endif
#ifndef BSP_CFG_EARLY_INIT
 #define BSP_CFG_EARLY_INIT                          (0)
#endif
#ifndef BSP_CFG_CMN_TIMING_DEBUG
 #define BSP_CFG_CMN_TIMING_DEBUG                    (0)
#endif

#ifndef BSP_CFG_RADIO_CLOCK_MGR_ENABLE
 #define BSP_CFG_RADIO_CLOCK_MGR_ENABLE               (0)
#endif

#ifndef dg_configUSE_CLOCK_MGR
 #define dg_configUSE_CLOCK_MGR                       (BSP_CFG_RADIO_CLOCK_MGR_ENABLE)
#endif

#ifndef BSP_CFG_SRAM_BUILD
 #define BSP_CFG_SRAM_BUILD                           (0)
#endif

#ifndef BSP_CFG_BOOT_IMAGE
 #if defined(CONFIG_USE_RAFW_SECUREBOOT)
  #define BSP_CFG_BOOT_IMAGE                           (1)
 #else
  #define BSP_CFG_BOOT_IMAGE                           (0)
 #endif
#endif

#ifndef BSP_CFG_TINYCRYPT_HW_ACCELERATION
 #define BSP_CFG_TINYCRYPT_HW_ACCELERATION            (0)
#endif

#ifndef BSP_CFG_MTB_ENABLE
 #define BSP_CFG_MTB_ENABLE                           (1)
#endif

#endif
