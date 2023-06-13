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

#ifndef __DA1469X_CONFIG_H_
#define __DA1469X_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/irq.h>

#define MCU_REMAPPED_BASE (0x00000000UL)
/* The max. remapped memory size supported. */
#define MCU_REMAPPED_SIZE (0x02000000UL)

/*
 * OTP memory base address; should be used when accessed by
 * peripheral devices (DMA, CRYPTO etc.).
 */
#define MCU_OTP_M_P_BASE   (0x30080000UL)
/* The max. supported OTP region size */
#define MCU_OTP_M_P_SIZE   (0x00010000UL)

/* OTP memory base address (not remapped) */
#define MCU_OTP_M_BASE   (0x10080000UL)
/* The max. supported OTP region size */
#define MCU_OTP_M_SIZE   (0x00010000UL)

#define MCU_ROM_BASE  (0x900000UL)
#define MCU_ROM_SIZE  (0x20000UL)

/* Actual memory size integrated into SoC */
#define MCU_OTPM_SIZE 			(4096)
#define MCU_OTPM_CS_OFFSET		(0x0c00)
#define MCU_OTPM_CS_LENGTH		(0x0400)

/*
 * QSPI Flash memory based address. Accesses are done through the AHB code bus (cached).
 * The region size available is restricted according to CACHE_FLASH_REG (up to 32MB).
 */
#define MCU_QSPIF_M_CACHED_BASE  (0x16000000UL)
#define MCU_QSPIF_M_CACHED_SIZE  (0x2000000UL)

/*
 * QSPIC Flash memory base address. Accesses are done through the AHB system bus (not cached).
 * Using this address space the whole Flash memory can be accesed (up to 32MB).
 */
#define MCU_QSPIF_M_BASE  (0x36000000UL)
#define MCU_QSPIF_M_SIZE  (0x2000000UL)

/* System RAM base address (not cached) */
#define MCU_SYSRAM_M_BASE  (0x20000000UL)
#define MCU_SYSRAM_M_SIZE  (0x80000UL)

/* QSPIC2 RAM memory base address */
#define MCU_QSPIR_M_BASE  (0x32000000UL)
#define MCU_QSPIR_M_SIZE  (0x2000000UL)


#define WITHIN_RANGE(_a, _s, _e) (((uint32_t)(_a) >= (uint32_t)(_s)) && ((uint32_t)(_a) < (uint32_t)(_e)))

/* True if the address provided is within the remapped region. Otherwise, false. */
#define IS_REMAPPED_ADDRESS(_a)  WITHIN_RANGE(_a, MCU_REMAPPED_BASE, MCU_REMAPPED_BASE + MCU_REMAPPED_SIZE)

/* True if the address provided is within the OTP region. Otherwise, false. */
#define IS_OTP_ADDRESS(_a)   WITHIN_RANGE(_a, MCU_OTP_M_BASE, MCU_OTP_M_BASE + MCU_OTP_M_SIZE)

/* True if the address provided is within the remapped OTP region. Otherwise, false. */
#define IS_OTP_P_ADDRESS(_a)  WITHIN_RANGE(_a, MCU_OTP_M_P_BASE, MCU_OTP_M_P_BASE + MCU_OTP_M_P_SIZE)

/* True if the address provided is within the SYSRAM region (no cached). Otherwise, false. */
#define IS_SYSRAM_ADDRESS(_a)  WITHIN_RANGE(_a, MCU_SYSRAM_M_BASE, MCU_SYSRAM_M_BASE + MCU_SYSRAM_M_SIZE)

/* True if the address provided is within the Flash region (not cached). Otherwise, false. */
#define IS_QSPIF_ADDRESS(_a)  WITHIN_RANGE(_a, MCU_QSPIF_M_BASE, MCU_QSPIF_M_BASE + MCU_QSPIF_M_SIZE)

/* True if the address provided is within the Flash region (cached). Otherwise, false. */
#define IS_QSPIF_CACHED_ADDRESS(_a)  WITHIN_RANGE(_a, MCU_QSPIF_M_CACHED_BASE, MCU_QSPIF_M_CACHED_BASE + \
                                                                               MCU_QSPIF_M_CACHED_SIZE)

/* True if the address provided is within the PSRAM region size. Otherwise, false */
#define IS_QSPIR_ADDRESS(_a)   WITHIN_RANGE(_a, MCU_QSPIR_M_BASE, MCU_QSPIR_M_BASE + MCU_QSPIR_M_SIZE)

#define MCU_TRIMV_GROUP_ID_MAX		(18)

#define MCU_RCX_CAL_REF_CNT		(100)

#define DA1469X_IRQ_DISABLE()		irq_lock()
#define DA1469X_IRQ_ENABLE(_key)	irq_unlock(_key)

#ifdef __cplusplus
}
#endif

#endif /* __DA1469X_CONFIG_H_ */
