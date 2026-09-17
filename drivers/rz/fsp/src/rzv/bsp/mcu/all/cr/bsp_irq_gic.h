/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IRQ_GIC_H
#define BSP_IRQ_GIC_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_BSP_MCU
 * @{
 **********************************************************************************************************************/

/** @} (end defgroup RZV_BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_ICU_VECTOR_MAX_ENTRIES    (BSP_VECTOR_TABLE_MAX_ENTRIES)

#define BSP_GIC_SGI_START_ID          (0)
#define BSP_GIC_PPI_START_ID          (16)
#define BSP_GIC_SPI_START_ID          (32)

#define BSP_GIC_MODEL_N_N             (0x00U << 0)
#define BSP_GIC_MODEL_1_N             (0x01U << 0)
#define BSP_GIC_DETECT_LEVEL          (0x00U << 1)
#define BSP_GIC_DETECT_EDGE           (0x01U << 1)

/* Interrupt detect type for PPI (support only 1-N model) */
#define BSP_GIC_PPI_DETECT_LEVEL      (BSP_GIC_MODEL_1_N | BSP_GIC_DETECT_LEVEL)
#define BSP_GIC_PPI_DETECT_EDGE       (BSP_GIC_MODEL_1_N | BSP_GIC_DETECT_EDGE)

/* Interrupt detect type for SPI (support only 1-N model) */
#define BSP_GIC_SPI_DETECT_LEVEL      (BSP_GIC_MODEL_1_N | BSP_GIC_DETECT_LEVEL)
#define BSP_GIC_SPI_DETECT_EDGE       (BSP_GIC_MODEL_1_N | BSP_GIC_DETECT_EDGE)

#define BSP_MASK_CPU_NUM              (0x03)

#define BSP_GIC_MPIDR_AFF_MASK        (0xFFU)

#define BSP_GIC_ICFGR_MAX             (32U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif                                 /* BSP_IRQ_GIC_H */
