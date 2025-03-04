/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_DEVICE_CFG_H_
#define BSP_MCU_DEVICE_CFG_H_
#define BSP_CFG_STACK_FIQ_BYTES (0x1000)
#define BSP_CFG_STACK_IRQ_BYTES (0x1000)
#define BSP_CFG_STACK_ABT_BYTES (0x1000)
#define BSP_CFG_STACK_UND_BYTES (0x1000)
#define BSP_CFG_STACK_SYS_BYTES (0x1000)
#define BSP_CFG_STACK_SVC_BYTES (0x1000)
#define BSP_CFG_HEAP_BYTES (0x8000)

#define BSP_CFG_C_RUNTIME_INIT (1)
#define BSP_CFG_USE_TFU_MATHLIB ((1))
#endif /* BSP_MCU_DEVICE_CFG_H_ */
