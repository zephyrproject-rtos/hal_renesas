/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IRQ_SENSE_H
#define BSP_IRQ_SENSE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

#include "hal_data.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * @addtogroup BSP_MPU_RZV2H
 * @{
 *********************************************************************************************************************/

/** @} (end addtogroup BSP_MPU_RZV2H) */

#if defined(BSP_TRIGGER_INTC_IRQ0_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ0_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ0_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ0_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ0_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ0_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ0_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ0_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ0_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ1_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ1_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ1_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ1_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ1_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ1_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ1_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ1_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ1_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ2_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ2_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ2_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ2_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ2_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ2_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ2_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ2_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ2_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ3_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ3_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ3_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ3_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ3_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ3_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ3_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ3_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ3_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ4_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ4_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ4_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ4_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ4_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ4_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ4_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ4_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ4_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ5_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ5_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ5_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ5_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ5_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ5_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ5_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ5_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ5_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ6_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ6_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ6_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ6_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ6_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ6_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ6_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ6_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ6_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ7_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ7_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ7_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ7_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ7_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ7_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ7_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ7_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ7_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ8_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ8_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ8_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ8_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ8_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ8_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ8_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ8_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ8_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ9_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ9_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ9_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ9_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ9_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ9_IRQn     BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ9_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ9_IRQn     BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ9_IRQn     BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ10_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ10_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ10_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ10_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ10_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ10_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ10_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ10_IRQn    BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ10_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ11_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ11_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ11_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ11_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ11_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ11_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ11_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ11_IRQn    BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ11_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ12_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ12_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ12_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ12_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ12_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ12_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ12_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ12_IRQn    BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ12_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ13_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ13_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ13_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ13_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ13_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ13_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ13_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ13_IRQn    BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ13_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ14_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ14_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ14_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ14_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ14_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ14_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ14_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ14_IRQn    BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ14_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#endif

#if defined(BSP_TRIGGER_INTC_IRQ15_EXTERNAL_IRQ_TRIG_LEVEL_LOW)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ15_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#elif defined(BSP_TRIGGER_INTC_IRQ15_EXTERNAL_IRQ_TRIG_RISING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ15_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ15_EXTERNAL_IRQ_TRIG_FALLING)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ15_IRQn    BSP_GIC_SPI_DETECT_EDGE
#elif defined(BSP_TRIGGER_INTC_IRQ15_EXTERNAL_IRQ_TRIG_BOTH_EDGE)
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ15_IRQn    BSP_GIC_SPI_DETECT_EDGE
#else
 #define BSP_GIC_SPI_DETECT_GPIO_IRQ15_IRQn    BSP_GIC_SPI_DETECT_LEVEL
#endif

#define BSP_IRQ_DETECT_TYPE_TABLE_BODY                                                    \
    BSP_GIC_DETECT_LEVEL,               /* SGI0: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI1: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI2: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI3: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI4: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI5: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI6: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI7: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI8: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI9: setting prohibit, dummy data  */         \
    BSP_GIC_DETECT_LEVEL,               /* SGI10: setting prohibit, dummy data  */        \
    BSP_GIC_DETECT_LEVEL,               /* SGI11: setting prohibit, dummy data  */        \
    BSP_GIC_DETECT_LEVEL,               /* SGI12: setting prohibit, dummy data  */        \
    BSP_GIC_DETECT_LEVEL,               /* SGI13: setting prohibit, dummy data  */        \
    BSP_GIC_DETECT_LEVEL,               /* SGI14: setting prohibit, dummy data  */        \
    BSP_GIC_DETECT_LEVEL,               /* SGI15: setting prohibit, dummy data  */        \
    BSP_GIC_DETECT_LEVEL,               /* PPI0: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI1: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI2: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI3: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI4: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI5: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI6: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI7: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI8: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI9: no interrupt allocation, dummy data  */  \
    BSP_GIC_DETECT_LEVEL,               /* PPI10: no interrupt allocation, dummy data  */ \
    BSP_GIC_PPI_DETECT_LEVEL,           /* PPI11: Global timer */                         \
    BSP_GIC_PPI_DETECT_LEVEL,           /* PPI12: Legacy FIQ */                           \
    BSP_GIC_PPI_DETECT_EDGE,            /* PPI13: Private timer */                        \
    BSP_GIC_PPI_DETECT_EDGE,            /* PPI14: Watch dog timer */                      \
    BSP_GIC_PPI_DETECT_LEVEL,           /* PPI15: Legacy IRQ */                           \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI0: NMI_IRQn */                              \
    BSP_GIC_SPI_DETECT_GPIO_IRQ0_IRQn,  /* SPI1: GPIO_IRQ0_IRQn */                        \
    BSP_GIC_SPI_DETECT_GPIO_IRQ1_IRQn,  /* SPI2: GPIO_IRQ1_IRQn */                        \
    BSP_GIC_SPI_DETECT_GPIO_IRQ2_IRQn,  /* SPI3: GPIO_IRQ2_IRQn */                        \
    BSP_GIC_SPI_DETECT_GPIO_IRQ3_IRQn,  /* SPI4: GPIO_IRQ3_IRQn */                        \
    BSP_GIC_SPI_DETECT_GPIO_IRQ4_IRQn,  /* SPI5: GPIO_IRQ4_IRQn */                        \
    BSP_GIC_SPI_DETECT_GPIO_IRQ5_IRQn,  /* SPI6: GPIO_IRQ5_IRQn */                        \
    BSP_GIC_SPI_DETECT_GPIO_IRQ6_IRQn,  /* SPI7: GPIO_IRQ6_IRQn */                        \
    BSP_GIC_SPI_DETECT_GPIO_IRQ7_IRQn,  /* SPI8: GPIO_IRQ7_IRQn */                        \
    BSP_GIC_SPI_DETECT_GPIO_IRQ8_IRQn,  /* SPI9: GPIO_IRQ8_IRQn */                        \
    BSP_GIC_SPI_DETECT_GPIO_IRQ9_IRQn,  /* SPI10: GPIO_IRQ9_IRQn */                       \
    BSP_GIC_SPI_DETECT_GPIO_IRQ10_IRQn, /* SPI11: GPIO_IRQ10_IRQn */                      \
    BSP_GIC_SPI_DETECT_GPIO_IRQ11_IRQn, /* SPI12: GPIO_IRQ11_IRQn */                      \
    BSP_GIC_SPI_DETECT_GPIO_IRQ12_IRQn, /* SPI13: GPIO_IRQ12_IRQn */                      \
    BSP_GIC_SPI_DETECT_GPIO_IRQ13_IRQn, /* SPI14: GPIO_IRQ13_IRQn */                      \
    BSP_GIC_SPI_DETECT_GPIO_IRQ14_IRQn, /* SPI15: GPIO_IRQ14_IRQn */                      \
    BSP_GIC_SPI_DETECT_GPIO_IRQ15_IRQn, /* SPI16: GPIO_IRQ15_IRQn */                      \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI17: GTM0_OSTM0INT_IRQn */                   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI18: GTM0_OSTM1INT_IRQn */                   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI19: GTM0_OSTM2INT_IRQn */                   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI20: GTM0_OSTM3INT_IRQn */                   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI21: GTM0_OSTM4INT_IRQn */                   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI22: GTM0_OSTM5INT_IRQn */                   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI23: GTM0_OSTM6INT_IRQn */                   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI24: GTM0_OSTM7INT_IRQn */                   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI25: DMAC_B1_DMAINT0_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI26: DMAC_B1_DMAINT1_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI27: DMAC_B1_DMAINT2_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI28: DMAC_B1_DMAINT3_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI29: DMAC_B1_DMAINT4_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI30: DMAC_B1_DMAINT5_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI31: DMAC_B1_DMAINT6_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI32: DMAC_B1_DMAINT7_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI33: DMAC_B1_DMAINT8_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI34: DMAC_B1_DMAINT9_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI35: DMAC_B1_DMAINT10_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI36: DMAC_B1_DMAINT11_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI37: DMAC_B1_DMAINT12_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI38: DMAC_B1_DMAINT13_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI39: DMAC_B1_DMAINT14_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI40: DMAC_B1_DMAINT15_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI41: DMAC_B2_DMAINT0_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI42: DMAC_B2_DMAINT1_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI43: DMAC_B2_DMAINT2_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI44: DMAC_B2_DMAINT3_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI45: DMAC_B2_DMAINT4_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI46: DMAC_B2_DMAINT5_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI47: DMAC_B2_DMAINT6_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI48: DMAC_B2_DMAINT7_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI49: DMAC_B2_DMAINT8_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI50: DMAC_B2_DMAINT9_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI51: DMAC_B2_DMAINT10_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI52: DMAC_B2_DMAINT11_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI53: DMAC_B2_DMAINT12_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI54: DMAC_B2_DMAINT13_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI55: DMAC_B2_DMAINT14_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI56: DMAC_B2_DMAINT15_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI57: DMAC_B3_DMAINT0_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI58: DMAC_B3_DMAINT1_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI59: DMAC_B3_DMAINT2_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI60: DMAC_B3_DMAINT3_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI61: DMAC_B3_DMAINT4_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI62: DMAC_B3_DMAINT5_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI63: DMAC_B3_DMAINT6_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI64: DMAC_B3_DMAINT7_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI65: DMAC_B3_DMAINT8_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI66: DMAC_B3_DMAINT9_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI67: DMAC_B3_DMAINT10_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI68: DMAC_B3_DMAINT11_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI69: DMAC_B3_DMAINT12_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI70: DMAC_B3_DMAINT13_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI71: DMAC_B3_DMAINT14_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI72: DMAC_B3_DMAINT15_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI73: DMAC_B4_DMAINT0_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI74: DMAC_B4_DMAINT1_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI75: DMAC_B4_DMAINT2_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI76: DMAC_B4_DMAINT3_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI77: DMAC_B4_DMAINT4_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI78: DMAC_B4_DMAINT5_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI79: DMAC_B4_DMAINT6_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI80: DMAC_B4_DMAINT7_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI81: DMAC_B4_DMAINT8_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI82: DMAC_B4_DMAINT9_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI83: DMAC_B4_DMAINT10_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI84: DMAC_B4_DMAINT11_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI85: DMAC_B4_DMAINT12_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI86: DMAC_B4_DMAINT13_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI87: DMAC_B4_DMAINT14_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI88: DMAC_B4_DMAINT15_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI89: DMAC_B5_DMAINT0_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI90: DMAC_B5_DMAINT1IRQn */                  \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI91: DMAC_B5_DMAINT2IRQn */                  \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI92: DMAC_B5_DMAINT3IRQn */                  \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI93: DMAC_B5_DMAINT4IRQn */                  \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI94: DMAC_B5_DMAINT5IRQn */                  \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI95: DMAC_B5_DMAINT6IRQn */                  \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI96: DMAC_B5_DMAINT7IRQn */                  \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI97: DMAC_B5_DMAINT8IRQn */                  \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI97: DMAC_B5_DMAINT9IRQn */                  \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI99: DMAC_B5_DMAINT10IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI100: DMAC_B5_DMAINT11IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI101: DMAC_B5_DMAINT12IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI102: DMAC_B5_DMAINT13IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI103: DMAC_B5_DMAINT14IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI104: DMAC_B5_DMAINT15IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI105: SPI0_IDLE_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI106: SPI0_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI107: SPI0_CE_IRQn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI108: SPI1_IDLE_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI109: SPI1_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI110: SPI1_CE_IRQn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI111: SPI2_IDLE_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI112: SPI2_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI113: SPI2_CE_IRQn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI114: SCI0_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI115: SCI0_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI116: SCI0_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI117: SCI0_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI118: SCI0_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI119: SCI0_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI120: SCI1_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI121: SCI1_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI122: SCI1_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI123: SCI1_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI124: SCI1_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI125: SCI1_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI126: SCI2_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI127: SCI2_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI128: SCI2_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI129: SCI2_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI130: SCI2_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI131: SCI2_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI132: SCI3_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI133: SCI3_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI134: SCI3_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI135: SCI3_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI136: SCI3_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI137: SCI3_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI138: SCI4_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI139: SCI4_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI140: SCI4_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI141: SCI4_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI142: SCI4_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI143: SCI4_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI144: SCI5_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI145: SCI5_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI146: SCI5_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI147: SCI5_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI148: SCI5_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI149: SCI5_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI150: SCI6_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI151: SCI6_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI152: SCI6_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI153: SCI6_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI154: SCI6_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI155: SCI6_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI156: SCI7_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI157: SCI7_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI158: SCI7_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI159: SCI7_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI160: SCI7_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI161: SCI7_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI162: SCI8_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI163: SCI8_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI164: SCI8_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI165: SCI8_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI166: SCI8_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI167: SCI8_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI168: SCI9_ERI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI169: SCI9_RXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI170: SCI9_TXI_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI171: SCI9_TEI_IRQn */                       \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI172: SCI9_AED_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI173: SCI9_BFD_IRQn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI174: RIIC0_TEI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI175: RIIC0_NAKI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI176: RIIC0_SPI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI177: RIIC0_STI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI178: RIIC0_ALI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI179: RIIC0_TMOI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI180: RIIC1_TEI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI181: RIIC1_NAKI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI182: RIIC1_SPI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI183: RIIC1_STI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI184: RIIC1_ALI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI185: RIIC1_TMOI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI186: RIIC2_TEI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI187: RIIC2_NAKI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI188: RIIC2_SPI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI189: RIIC2_STI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI190: RIIC2_ALI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI191: RIIC2_TMOI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI192: RIIC3_TEI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI193: RIIC3_NAKI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI194: RIIC3_SPI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI195: RIIC3_STI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI196: RIIC3_ALI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI197: RIIC3_TMOI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI198: RIIC4_TEI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI199: RIIC4_NAKI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI200: RIIC4_SPI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI201: RIIC4_STI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI202: RIIC4_ALI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI203: RIIC4_TMOI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI204: RIIC5_TEI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI205: RIIC5_NAKI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI206: RIIC5_SPI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI207: RIIC5_STI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI208: RIIC5_ALI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI209: RIIC5_TMOI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI210: RIIC6_TEI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI211: RIIC6_NAKI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI212: RIIC6_SPI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI213: RIIC6_STI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI214: RIIC6_ALI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI215: RIIC6_TMOI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI216: RIIC7_TEI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI217: RIIC7_NAKI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI218: RIIC7_SPI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI219: RIIC7_STI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI220: RIIC7_ALI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI221: RIIC7_TMOI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI222: RIIC8_TEI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI223: RIIC8_NAKI_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI224: RIIC8_SPI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI225: RIIC8_STI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI226: RIIC8_ALI_IRQn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI227: RIIC8_TMOI_IRQn */                     \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI228: XSPI_PULSE_IRQn */                     \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI229: XSPI_ERR_PULSE_IRQn */                 \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI230: Reserved */                            \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI231: Reserved */                            \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI232: PDM0_INT_DAT0_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI233: PDM0_INT_DAT1_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI234: PDM0_INT_DAT2_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI235: PDM0_INT_SDET_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI236: PDM0_INT_ERR0_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI237: PDM0_INT_ERR1_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI238: PDM0_INT_ERR2_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI239: PDM1_INT_DAT0_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI240: PDM1_INT_DAT1_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI241: PDM1_INT_DAT2_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI242: PDM1_INT_SDET_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI243: PDM1_INT_ERR0_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI244: PDM1_INT_ERR1_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI245: PDM1_INT_ERR2_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI246: ADC_ADA_COMPAI_N_IRQn */               \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI247: ADC_ADA_COMPBI_N_IRQn */               \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI248: TSU0_S12TSUADI_IRQn */                 \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI249: TSU0_S12TSUADCMPI_IRQn */              \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI250: TSU1_S12TSUADI_IRQn */                 \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI251: TSU1_S12TSUADCMPI_IRQn */              \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI252: ICU_SWINT_CR8_0_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI253: ICU_SWINT_CR8_1_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI254: ICU_SWINT_CR8_2_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI255: ICU_SWINT_CR8_3_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI256: CR8_PMUIRQ_0_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI257: CR8_PMUIRQ_1_IRQn */                   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI258: CR8_SCUEVABORT_IRQn */                 \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI259: CR8_FPUFLAGS0_0_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI260: CR8_FPUFLAGS0_1_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI261: CR8_FPUFLAGS0_2_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI262: CR8_FPUFLAGS0_3_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI263: CR8_FPUFLAGS0_4_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI264: CR8_FPUFLAGS0_5_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI265: CR8_FPUFLAGS1_0_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI266: CR8_FPUFLAGS1_1_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI267: CR8_FPUFLAGS1_2_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI268: CR8_FPUFLAGS1_3_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI269: CR8_FPUFLAGS0_4_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI270: CR8_FPUFLAGS0_5_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI271: CR8_RCPU_RAMERR_IRQn */                \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI272: CR8_RCPU_FATALRAMERR_0_IRQn */         \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI273: CR8_RCPU_FATALRAMERR_1_IRQn */         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI274: CR8_RCPU_FATALERRDET_IRQn */           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI275: CR8_RCPU_DCEBEMPTY_0_IRQn */           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI276: CR8_RCPU_DCEBEMPTY_1_IRQn */           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI277: CR8_RCPU_ICEBEMPTY_0_IRQn */           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI278: CR8_RCPU_ICEBEMPTY_1_IRQn */           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI279: CR8_RCPU_DTCMEBEMPTY0_IRQn */          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI280: CR8_RCPU_DTCMEBEMPTY1_IRQn */          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI281: CR8_RCPU_ITCMEBEMPTY0_IRQn */          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI282: CR8_RCPU_ITCMEBEMPTY1_IRQn */          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI283: CR8_RCPU_SCUEBEMPTY_IRQn */            \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI284: CR8_nCTIIRQ_0_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI285: CR8_nCTIIRQ_1_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI286: CR8_COMMTX_0_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI287: CR8_COMMTX_1_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI288: CR8_COMMRX_0_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI289: CR8_COMMRX_1_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI290: MHU_MSG3_S_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI291: MHU_MSG4_S_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI292: MHU_MSG9_S_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI293: MHU_MSG10_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI294: MHU_MSG15_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI295: MHU_MSG16_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI296: MHU_MSG21_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI297: MHU_MSG22_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI298: MHU_MSG28_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI299: MHU_MSG34_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI300: MHU_MSG40_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI301: MHU_MSG41_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI302: MHU_RSP3_S_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI303: MHU_RSP4_S_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI304: MHU_RSP9_S_IRQn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI305: MHU_RSP10_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI306: MHU_RSP15_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI307: MHU_RSP16_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI308: MHU_RSP21_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI309: MHU_RSP22_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI310: MHU_RSP28_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI311: MHU_RSP34_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI312: MHU_RSP40_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI313: MHU_RSP41_S_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI314: MHU_MSG3_NS_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI315: MHU_MSG4_NS_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI316: MHU_MSG9_NS_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI317: MHU_MSG10_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI318: MHU_MSG15_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI319: MHU_MSG16_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI320: MHU_MSG21_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI321: MHU_MSG22_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI322: MHU_MSG28_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI323: MHU_MSG34_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI324: MHU_MSG40_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI325: MHU_MSG41_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI326: MHU_RSP3_NS_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI327: MHU_RSP4_NS_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI328: MHU_RSP9_NS_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI329: MHU_RSP10_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI330: MHU_RSP15_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI331: MHU_RSP16_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI332: MHU_RSP21_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI333: MHU_RSP22_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI334: MHU_RSP28_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI335: MHU_RSP34_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI336: MHU_RSP40_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI337: MHU_RSP41_NS_IRQn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI338: MHU_SW_MHU_INT0_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI339: MHU_SW_MHU_INT1_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI340: MHU_SW_MHU_INT3_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI341: MHU_SW_MHU_INT4_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI342: MHU_SW_MHU_INT6_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI343: MHU_SW_MHU_INT7_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI344: MHU_SW_MHU_INT9_IRQn */                \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI345: MHU_SW_MHU_INT10_IRQn */               \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI346: MHU_SW_MHU_INT26_IRQn */               \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI347: MHU_SW_MHU_INT27_IRQn */               \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI348: WDT_WDT_CR8_0_iwdt_nmiundf_n_IRQn */   \
    BSP_GIC_SPI_DETECT_EDGE,            /* SPI349: WDT_WDT_CR8_1_iwdt_nmiundf_n_IRQn */   \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI350: GIC_FAULT_INT_IRQn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI351: GIC_ERR_INT_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI352: GIC_PMU_INT_IRQn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI353: SEL0_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI354: SEL1_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI355: SEL2_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI356: SEL3_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI357: SEL4_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI358: SEL5_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI359: SEL6_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI360: SEL7_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI361: SEL8_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI362: SEL9_IRQn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI363: SEL10_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI364: SEL11_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI365: SEL12_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI366: SEL13_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI367: SEL14_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI368: SEL15_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI369: SEL16_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI370: SEL17_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI371: SEL18_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI372: SEL19_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI373: SEL20_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI374: SEL21_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI375: SEL22_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI376: SEL23_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI377: SEL24_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI378: SEL25_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI379: SEL26_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI380: SEL27_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI381: SEL28_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI382: SEL29_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI383: SEL30_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI384: SEL31_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI385: SEL32_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI386: SEL33_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI387: SEL34_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI388: SEL35_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI389: SEL36_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI390: SEL37_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI391: SEL38_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI392: SEL39_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI393: SEL40_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI394: SEL41_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI395: SEL42_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI396: SEL43_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI397: SEL44_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI398: SEL45_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI399: SEL46_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI400: SEL47_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI401: SEL48_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI402: SEL49_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI403: SEL50_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI404: SEL51_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI405: SEL52_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI406: SEL53_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI407: SEL54_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI408: SEL55_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI409: SEL56_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI410: SEL57_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI411: SEL58_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI412: SEL59_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI413: SEL60_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI414: SEL61_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI415: SEL62_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI416: SEL63_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI417: SEL64_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI418: SEL65_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI419: SEL66_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI420: SEL67_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI421: SEL68_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI422: SEL69_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI423: SEL70_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI424: SEL71_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI425: SEL72_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI426: SEL73_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI427: SEL74_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI428: SEL75_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI429: SEL76_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI430: SEL77_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI431: SEL78_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI432: SEL79_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI433: SEL80_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI434: SEL81_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI435: SEL82_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI436: SEL83_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI437: SEL84_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI438: SEL85_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI439: SEL86_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI440: SEL87_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI441: SEL88_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI442: SEL89_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI443: SEL90_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI444: SEL91_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI445: SEL92_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI446: SEL93_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI447: SEL94_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI448: SEL95_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI449: SEL96_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI450: SEL97_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI451: SEL98_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI452: SEL99_IRQn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI453: SEL100_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI454: SEL101_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI455: SEL102_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI456: SEL103_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI457: SEL104_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI458: SEL105_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI459: SEL106_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI460: SEL107_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI461: SEL108_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI462: SEL109_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI453: SEL110_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI464: SEL111_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI465: SEL112_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI466: SEL113_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI467: SEL114_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI468: SEL115_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI469: SEL116_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI470: SEL117_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI471: SEL118_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI472: SEL119_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI473: SEL120_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI474: SEL121_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI475: SEL122_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI476: SEL123_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI477: SEL124_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,           /* SPI478: SEL125_IRQn */                         \
    BSP_GIC_SPI_DETECT_LEVEL            /* SPI479: SEL126_IRQn */                         \

#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)

 #if defined(BSP_TRIGGER_INTC_TINT0_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT0_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT0_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT0_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT0_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT0_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT0_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT0_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT0_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT1_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT1_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT1_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT1_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT1_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT1_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT1_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT1_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT1_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT2_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT2_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT2_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT2_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT2_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT2_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT2_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT2_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT2_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT3_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT3_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT3_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT3_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT3_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT3_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT3_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT3_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT3_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT4_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT4_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT4_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT4_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT4_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT4_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT4_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT4_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT4_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT5_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT5_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT5_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT5_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT5_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT5_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT5_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT5_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT5_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT6_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT6_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT6_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT6_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT6_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT6_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT6_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT6_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT6_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT7_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT7_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT7_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT7_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT7_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT7_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT7_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT7_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT7_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT8_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT8_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT8_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT8_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT8_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT8_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT8_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT8_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT8_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT9_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT9_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT9_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT9_IRQSELn     BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT9_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT9_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT9_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT9_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT9_IRQSELn     BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT10_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT10_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT10_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT10_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT10_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT10_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT10_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT10_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT10_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT11_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT11_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT11_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT11_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT11_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT11_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT11_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT11_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT11_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT12_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT12_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT12_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT12_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT12_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT12_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT12_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT12_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT12_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT13_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT13_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT13_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT13_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT13_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT13_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT13_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT13_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT13_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT14_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT14_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT14_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT14_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT14_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT14_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT14_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT14_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT14_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT15_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT15_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT15_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT15_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT15_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT15_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT15_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT15_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT15_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT16_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT16_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT16_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT16_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT16_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT16_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT16_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT16_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT16_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT17_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT17_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT17_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT17_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT17_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT17_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT17_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT17_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT17_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT18_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT18_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT18_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT18_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT18_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT18_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT18_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT18_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT18_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT19_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT19_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT19_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT19_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT19_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT19_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT19_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT19_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT19_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT20_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT20_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT20_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT20_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT20_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT20_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT20_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT20_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT20_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT21_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT21_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT21_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT21_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT21_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT21_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT21_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT21_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT21_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT22_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT22_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT22_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT22_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT22_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT22_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT22_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT22_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT22_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT23_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT23_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT23_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT23_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT23_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT23_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT23_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT23_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT23_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT24_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT24_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT24_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT24_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT24_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT24_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT24_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT24_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT24_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT25_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT25_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT25_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT25_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT25_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT25_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT25_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT25_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT25_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT26_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT26_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT26_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT26_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT26_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT26_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT26_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT26_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT26_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT27_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT27_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT27_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT27_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT27_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT27_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT27_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT27_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT27_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT28_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT28_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT28_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT28_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT28_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT28_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT28_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT28_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT28_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT29_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT29_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT29_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT29_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT29_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT29_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT29_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT29_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT29_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT30_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT30_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT30_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT30_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT30_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT30_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT30_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT30_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT30_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #if defined(BSP_TRIGGER_INTC_TINT31_INTC_TINT_TRIGGER_RISING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT31_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT31_INTC_TINT_TRIGGER_FALLING)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT31_IRQSELn    BSP_GIC_SPI_DETECT_EDGE
 #elif defined(BSP_TRIGGER_INTC_TINT31_INTC_TINT_TRIGGER_LEVEL_HIGH)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT31_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #elif defined(BSP_TRIGGER_INTC_TINT31_INTC_TINT_TRIGGER_LEVEL_LOW)
  #define BSP_GIC_SPI_DETECT_GPIO_TINT31_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #else
  #define BSP_GIC_SPI_DETECT_GPIO_TINT31_IRQSELn    BSP_GIC_SPI_DETECT_LEVEL
 #endif

 #define BSP_SELECT_IRQ_DETECT_TYPE_TABLE_BODY                                                             \
    BSP_GIC_SPI_DETECT_GPIO_TINT0_IRQSELn,  /* SEL0: GPIO_TINT0_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT1_IRQSELn,  /* SEL1: GPIO_TINT1_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT2_IRQSELn,  /* SEL2: GPIO_TINT2_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT3_IRQSELn,  /* SEL3: GPIO_TINT3_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT4_IRQSELn,  /* SEL4: GPIO_TINT4_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT5_IRQSELn,  /* SEL5: GPIO_TINT5_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT6_IRQSELn,  /* SEL6: GPIO_TINT6_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT7_IRQSELn,  /* SEL7: GPIO_TINT7_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT8_IRQSELn,  /* SEL8: GPIO_TINT8_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT9_IRQSELn,  /* SEL9: GPIO_TINT9_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_GPIO_TINT10_IRQSELn, /* SEL10 GPIO_TINT10_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_GPIO_TINT11_IRQSELn, /* SEL11: GPIO_TINT11_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT12_IRQSELn, /* SEL12: GPIO_TINT12_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT13_IRQSELn, /* SEL13: GPIO_TINT13_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT14_IRQSELn, /* SEL14: GPIO_TINT14_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT15_IRQSELn, /* SEL15: GPIO_TINT15_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT16_IRQSELn, /* SEL16: GPIO_TINT16_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT17_IRQSELn, /* SEL17: GPIO_TINT17_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT18_IRQSELn, /* SEL18: GPIO_TINT18_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT19_IRQSELn, /* SEL19: GPIO_TINT19_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT20_IRQSELn, /* SEL20: GPIO_TINT20_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT21_IRQSELn, /* SEL21: GPIO_TINT21_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT22_IRQSELn, /* SEL22: GPIO_TINT22_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT23_IRQSELn, /* SEL23: GPIO_TINT23_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT24_IRQSELn, /* SEL24: GPIO_TINT24_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT25_IRQSELn, /* SEL25: GPIO_TINT25_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT26_IRQSELn, /* SEL26: GPIO_TINT26_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT27_IRQSELn, /* SEL27: GPIO_TINT27_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT28_IRQSELn, /* SEL28: GPIO_TINT28_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT29_IRQSELn, /* SEL29: GPIO_TINT29_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT30_IRQSELn, /* SEL30: GPIO_TINT30_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_GPIO_TINT31_IRQSELn, /* SEL31: GPIO_TINT31_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL32: CMTW0_CMT2_CMP_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL33: CMTW1_CMT2_CMP_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL34: CMTW2_CMT2_CMP_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL35: CMTW3_CMT2_CMP_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL36: CMTW4_CMT2_CMP_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL37: CMTW5_CMT2_CMP_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL38: CMTW6_CMT2_CMP_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL39: CMTW7_CMT2_CMP_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL40: CMTW0_CMT2_IC0_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL41: CMTW1_CMT2_IC0_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL42: CMTW2_CMT2_IC0_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL43: CMTW3_CMT2_IC0_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL44: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL45: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL46: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL47: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL48: CMTW0_CMT2_IC1_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL49: CMTW1_CMT2_IC1_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL50: CMTW2_CMT2_IC1_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL51: CMTW3_CMT2_IC1_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL52: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL53: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL54: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL55: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL56: CMTW0_CMT2_OC0_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL57: CMTW1_CMT2_OC0_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL58: CMTW2_CMT2_OC0_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL59: CMTW3_CMT2_OC0_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL60: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL61: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL62: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL63: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL64: CMTW0_CMT2_OC1_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL65: CMTW1_CMT2_OC1_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL66: CMTW2_CMT2_OC1_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL67: CMTW3_CMT2_OC1_PLS_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL68: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL69: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL70: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL71: Reserved */                                          \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL72: DMAC_B1_DMAERR_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL73: DMAC_B2_DMAERR_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL74: DMAC_B3_DMAERR_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL75: DMAC_B4_DMAERR_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL76: DMAC_B5_DMAERR_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL77: SPI0_RXI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL78: SPI0_TXI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL79: SPI1_RXI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL80: SPI1_TXI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL81: SPI2_RXI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL82: SPI2_TXI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL83: RIIC0_TI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL84: RIIC0_RI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL85: RIIC1_TI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL86: RIIC1_RI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL87: RIIC2_TI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL88: RIIC2_RI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL89: RIIC3_TI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL90: RIIC3_RI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL91: RIIC4_TI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL92: RIIC4_RI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL93: RIIC5_TI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL94: RIIC5_RI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL95: RIIC6_TI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL96: RIIC6_RI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL97: RIIC7_TI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL98: RIIC7_RI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL99: RIIC8_TI_IRQSELn */                                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL100: RIIC8_RI_IRQSELn */                                 \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL101: RTC_INTREQ_RTC_ALMPLS_N_IRQSELn */                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL102: RTC_INTREQ_RTC_PRDPLS_N_IRQSELn */                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL103: RTC_INTREQ_RTC_CUPPLS_N_IRQSELn */                  \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL104: Reserved */                                         \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL105: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL106: SCIF0_RERR_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL107: SCIF0_BRK_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL108: SCIF0_TEI_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL109: SCIF0_RXI_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL110: SCIF0_TXI_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL111: SCIF0_DRI_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL112: SCIF0_TEI_DRI_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL113: SCIF0_RXI_EDGE_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL114: SCIF0_TXI_EDGE_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL115: GPT00_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL116: GPT01_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL117: GPT02_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL118: GPT03_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL119: GPT04_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL120: GPT05_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL121: GPT06_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL122: GPT07_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL123: GPT00_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL124: GPT01_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL125: GPT02_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL126: GPT03_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL127: GPT04_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL128: GPT05_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL129: GPT06_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL130: GPT07_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL131: GPT00_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL132: GPT01_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL133: GPT02_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL134: GPT03_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL135: GPT04_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL136: GPT05_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL137: GPT06_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL138: GPT07_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL139: GPT00_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL140: GPT01_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL141: GPT02_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL142: GPT03_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL143: GPT04_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL144: GPT05_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL145: GPT06_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL146: GPT07_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL147: GPT00_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL148: GPT01_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL149: GPT02_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL150: GPT03_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL151: GPT04_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL152: GPT05_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL153: GPT06_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL154: GPT07_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL155: GPT00_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL156: GPT01_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL157: GPT02_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL158: GPT03_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL159: GPT04_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL160: GPT05_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL161: GPT06_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL162: GPT07_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL163: GPT00_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL164: GPT01_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL165: GPT02_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL166: GPT03_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL167: GPT04_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL168: GPT05_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL169: GPT06_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL170: GPT07_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL171: GPT00_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL172: GPT01_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL173: GPT02_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL174: GPT03_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL175: GPT04_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL176: GPT05_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL177: GPT06_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL178: GPT07_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL179: GPT00_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL180: GPT01_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL181: GPT02_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL182: GPT03_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL183: GPT04_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL184: GPT05_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL185: GPT06_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL186: GPT07_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL187: GPT00_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL188: GPT01_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL189: GPT02_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL190: GPT03_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL191: GPT04_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL192: GPT05_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL193: GPT06_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL194: GPT07_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL195: GPT00_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL196: GPT01_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL197: GPT02_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL198: GPT03_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL199: GPT04_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL200: GPT05_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL201: GPT06_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL202: GPT07_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL203: GPT00_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL204: GPT01_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL205: GPT02_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL206: GPT03_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL207: GPT04_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL208: GPT05_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL209: GPT06_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL210: GPT07_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL211: GPT00_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL212: GPT01_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL213: GPT02_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL214: GPT03_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL215: GPT04_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL216: GPT05_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL217: GPT06_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL218: GPT07_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL219: GPT10_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL220: GPT11_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL221: GPT12_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL222: GPT13_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL223: GPT14_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL224: GPT15_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL225: GPT16_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL226: GPT17_CCMPA_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL227: GPT10_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL228: GPT11_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL229: GPT12_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL230: GPT13_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL231: GPT14_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL232: GPT15_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL233: GPT16_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL234: GPT17_CCMPB_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL235: GPT10_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL236: GPT11_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL237: GPT12_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL238: GPT13_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL239: GPT14_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL240: GPT15_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL241: GPT16_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL242: GPT17_CMPC_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL243: GPT10_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL244: GPT11_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL245: GPT12_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL246: GPT13_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL247: GPT14_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL248: GPT15_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL249: GPT16_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL250: GPT17_CMPD_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL251: GPT10_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL252: GPT11_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL253: GPT12_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL254: GPT13_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL255: GPT14_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL256: GPT15_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL257: GPT16_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL258: GPT17_CMPE_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL259: GPT10_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL260: GPT11_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL261: GPT12_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL262: GPT13_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL263: GPT14_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL264: GPT15_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL265: GPT16_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL266: GPT17_CMPF_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL267: GPT10_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL268: GPT11_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL269: GPT12_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL270: GPT13_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL271: GPT14_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL272: GPT15_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL273: GPT16_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL274: GPT17_ADTRGA_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL275: GPT10_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL276: GPT11_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL277: GPT12_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL278: GPT13_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL279: GPT14_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL280: GPT15_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL281: GPT16_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL282: GPT17_ADTRGB_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL283: GPT10_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL284: GPT11_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL285: GPT12_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL286: GPT13_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL287: GPT14_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL288: GPT15_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL289: GPT16_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL290: GPT17_OVF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL291: GPT10_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL292: GPT11_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL293: GPT12_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL294: GPT13_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL295: GPT14_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL296: GPT15_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL297: GPT16_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL298: GPT17_UNF_IRQSELn */                                \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL299: GPT10_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL300: GPT11_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL301: GPT12_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL302: GPT13_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL303: GPT14_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL304: GPT15_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL305: GPT16_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL306: GPT17_GTCIH_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL307: GPT10_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL308: GPT11_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL309: GPT12_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL310: GPT13_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL311: GPT14_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL312: GPT15_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL313: GPT16_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL314: GPT17_GTCIL_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL315: GPT10_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL316: GPT11_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL317: GPT12_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL318: GPT13_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL319: GPT14_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL320: GPT15_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL321: GPT16_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL322: GPT17_GTDEI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL323: POEG_GROUP0_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL324: POEG_GROUP1_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL325: POEG_GROUP2_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL326: POEG_GROUP3_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL327: POEG_GROUP4_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL328: POEG_GROUP5_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL329: POEG_GROUP6_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL330: POEG_GROUP7_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL331: I3C_INT_RI3C_IERR_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL332: I3C_INT_RI3C_TERR_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL333: I3C_INT_RI3C_ABORT_N_IRQSELn */                     \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL334: I3C_INT_RI3C_RESP_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL335: I3C_INT_RI3C_CMD_N_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL336: I3C_INT_RI3C_IBI_N_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL337: I3C_INT_RI3C_RX_N_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL338: I3C_INT_RI3C_TX_N_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL339: I3C_INT_RI3C_RCV_N_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL340: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL341: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL342: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL343: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL344: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL345: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL346: I3C_INT_RI3C_ST_N_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL347: I3C_INT_RI3C_SP_N_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL348: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL349: I3C_INT_RI3C_TEND_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL350: I3C_INT_RI3C_NACK_N_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL351: I3C_INT_RI3C_AL_N_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL352: I3C_INT_RI3C_TMO_N_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL353: I3C_INT_RI3C_WU_N_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL354: CANFD_CAN_CHERR_INT_0_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL355: CANFD_CAN_CHERR_INT_1_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL356: CANFD_CAN_CHERR_INT_2_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL357: CANFD_CAN_CHERR_INT_3_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL358: CANFD_CAN_CHERR_INT_4_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL359: CANFD_CAN_CHERR_INT_5_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL360: CANFD_CAN_COMFRX_INT_0_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL361: CANFD_CAN_COMFRX_INT_1_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL362: CANFD_CAN_COMFRX_INT_2_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL363: CANFD_CAN_COMFRX_INT_3_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL364: CANFD_CAN_COMFRX_INT_4_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL365: CANFD_CAN_COMFRX_INT_5_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL366: CANFD_CAN_GLERR_INT_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL367: CANFD_CAN_RXF_INT_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL368: CANFD_CAN_TX_INT_0_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL369: CANFD_CAN_TX_INT_1_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL370: CANFD_CAN_TX_INT_2_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL371: CANFD_CAN_TX_INT_3_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL372: CANFD_CAN_TX_INT_4_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL373: CANFD_CAN_TX_INT_5_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL374: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL375: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL376: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL377: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL378: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL379: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL380: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL381: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL382: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL383: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL384: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL385: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL386: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL387: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL388: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL389: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL390: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL391: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL392: SDHI_eMMC0_OXMN_IRQSELn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL393: SDHI_eMMC0_OXASIO_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL394: SDHI_eMMC1_OXMN_IRQSELn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL395: SDHI_eMMC1_OXASIO_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL396: SDHI_eMMC2_OXMN_IRQSELn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL397: SDHI_eMMC2_OXASIO_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL398: USB_U2H0_INT_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL399: USB_U2H0_OHCI_INT_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL400: USB_U2H0_EHCI_INT_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL401: USB_U2H0_WAKEON_INT_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL402: USB_U2H0_OBINT_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL403: USB_U2H0_INT_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL404: USB_U2H0_OHCI_INT_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL405: USB_U2H0_EHCI_INT_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL406: USB_U2H0_WAKEON_INT_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL407: USB_U2H0_OBINT_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL408: USB_U2P_IXL_INT_IRQSELn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL409: USB_U2P_INT_DMA0_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL410: USB_U2P_INT_DMA1_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL411: USB_U2P_INT_DMAERR_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL412: USB_U3H0_XHC_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL413: USB_U3H0_PME_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL414: USB_U3H0_HSE_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL415: USB_U3H0_SMI_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL416: USB_U3H0_ALL_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL417: USB_U3H1_XHC_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL418: USB_U3H1_PME_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL419: USB_U3H1_HSE_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL420: USB_U3H1_SMI_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL421: USB_U3H1_ALL_INT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL422: GBETH0_SBD_INTR_O_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL423: GBETH0_LPI_INTR_O_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL424: GBETH0_PMT_INTR_O_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL425: GBETH0_SBD_PERCH_TX_INTR_O_0_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL426: GBETH0_SBD_PERCH_TX_INTR_O_1_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL427: GBETH0_SBD_PERCH_TX_INTR_O_2_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL428: GBETH0_SBD_PERCH_TX_INTR_O_3_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL429: GBETH0_SBD_PERCH_RX_INTR_O_0_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL430: GBETH0_SBD_PERCH_RX_INTR_O_1_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL431: GBETH0_SBD_PERCH_RX_INTR_O_2_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL432: GBETH0_SBD_PERCH_RX_INTR_O_3_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL433: GBETH0_MCGR_DMA_REQ_O_0_IRQSELn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL434: GBETH0_MCGR_DMA_REQ_O_1_IRQSELn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL435: GBETH0_MCGR_DMA_REQ_O_2_IRQSELn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL436: GBETH0_MCGR_DMA_REQ_O_3_IRQSELn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL437: GBETH1_SBD_INTR_O_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL438: GBETH1_LPI_INTR_O_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL439: GBETH1_PMT_INTR_O_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL440: GBETH1_SBD_PERCH_TX_INTR_O_0_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL441: GBETH1_SBD_PERCH_TX_INTR_O_1_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL442: GBETH1_SBD_PERCH_TX_INTR_O_2_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL443: GBETH1_SBD_PERCH_TX_INTR_O_3_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL444: GBETH1_SBD_PERCH_RX_INTR_O_0_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL445: GBETH1_SBD_PERCH_RX_INTR_O_1_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL446: GBETH1_SBD_PERCH_RX_INTR_O_2_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL447: GBETH1_SBD_PERCH_RX_INTR_O_3_IRQSELn */             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL448: PCIE0_INT_ALL_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL449: PCIE0_INTA_RC_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL450: PCIE0_INTB_RC_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL451: PCIE0_INTC_RC_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL452: PCIE0_INTD_RC_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL453: PCIE0_INTMSI_RC_IRQSELn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL454: PCIE0_INT_LINK_BANDWIDTH_IRQSELn */                 \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL455: PCIE0_INT_LINK_EQUALIZATION_REQUEST_IRQSELn */      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL456: PCIE0_INT_PM_PME_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL457: PCIE0_INT_SERR_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL458: PCIE0_INT_SERR_COR_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL459: PCIE0_INT_SERR_NONFATAL_IRQSELn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL460: PCIE0_INT_SERR_FATAL_IRQSELn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL461: PCIE0_DMA_INT_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL462: PCIE0_PCIE_EVT_INT_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL463: PCIE0_AXI_ERR_INT_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL464: PCIE0_MSG_INT_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL465: PCIE0_TURN_OFF_EVENT_IRQSELn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL466: PCIE0_PMU_POWEROFF_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL467: PCIE0_D3_EVENT_F0_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL468: PCIE0_D3_EVENT_F1_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL469: PCIE0_CFG_PMCSR_PME_STATUS_WRITECLEAR_F0_IRQSELn */ \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL470: PCIE0_CFG_PMCSR_PME_STATUS_WRITECLEAR_F1_IRQSELn */ \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL471: PCIE1_INT_ALL_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL472: PCIE1_INTA_RC_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL473: PCIE1_INTB_RC_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL474: PCIE1_INTC_RC_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL475: PCIE1_INTD_RC_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL476: PCIE1_INTMSI_RC_IRQSELn */                          \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL477: PCIE1_INT_LINK_BANDWIDTH_IRQSELn */                 \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL478: PCIE1_INT_LINK_EQUALIZATION_REQUEST_IRQSELn */      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL478: PCIE1_INT_PM_PME_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL480: PCIE1_INT_SERR_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL481: PCIE1_INT_SERR_COR_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL482: PCIE1_INT_SERR_NONFATAL_IRQSELn */                  \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL483: PCIE1_INT_SERR_FATAL_IRQSELn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL484: PCIE1_DMA_INT_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL485: PCIE1_PCIE_EVT_INT_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL486: PCIE1_AXI_ERR_INT_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL487: PCIE1_MSG_INT_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL488: PCIE1_TURN_OFF_EVENT_IRQSELn */                     \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL489: PCIE1_PMU_POWEROFF_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL490: PCIE1_D3_EVENT_F0_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL491: PCIE1_D3_EVENT_F1_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL492: PCIE1_CFG_PMCSR_PME_STATUS_WRITECLEAR_F0_IRQSELn */ \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL493: PCIE1_CFG_PMCSR_PME_STATUS_WRITECLEAR_F1_IRQSELn */ \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL494: CRU0_CSI2_LINK_INT_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL495: CRU0_IMAGE_CONV_INT_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL496: CRU0_AXI_MST_ERR_INT_IRQSELn */                     \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL497: CRU0_CRU_VD_ADDR_WEND_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL498: CRU0_CRU_SD_ADDR_WEND_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL499: CRU0_CRU_VSD_ADDR_WEND_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL500: CRU1_CSI2_LINK_INT_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL501: CRU1_IMAGE_CONV_INT_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL502: CRU1_AXI_MST_ERR_INT_IRQSELn */                     \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL503: CRU1_CRU_VD_ADDR_WEND_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL504: CRU1_CRU_SD_ADDR_WEND_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL505: CRU1_CRU_VSD_ADDR_WEND_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL506: CRU2_CSI2_LINK_INT_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL507: CRU2_IMAGE_CONV_INT_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL508: CRU2_AXI_MST_ERR_INT_IRQSELn */                     \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL509: CRU2_CRU_VD_ADDR_WEND_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL510: CRU2_CRU_VSD_ADDR_WEND_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL511: CRU3_CSI2_LINK_INT_IRQSELn */                       \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL512: CRU3_IMAGE_CONV_INT_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL513: CRU3_AXI_MST_ERR_INT_IRQSELn */                     \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL514: CRU3_CRU_VD_ADDR_WEND_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL515: CRU3_CRU_VSD_ADDR_WEND_IRQSELn */                   \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL516: ISP_COREINT_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL517: ISP_VVALID_IRP_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL518: ISP_VVALID_IFP_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL519: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL520: Reserved */                                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL521: ISP_INT_FSTOP_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL522: ISP_FR_DMA_WRITER_LINETICK_OUT_IRQSELn */           \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL523: ISP_FR_UV_DMA_WRITER_LINETICK_OUT_IRQSELn */        \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL524: ISU_INT_FRE0_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL525: ISU_INT_FRE1_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL526: ISU_INT_FRE2_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_EDGE,                /* SEL527: ISU_INT_FRE3_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL528: ISU_INT_DESE_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL529: ISU_INT_STOPE_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL530: ISU_INT_ERR_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL531: DSI_INT_SEQ0_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL532: DSI_INT_SEQ1_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL533: DSI_INT_VIN1_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL534: DSI_INT_RCV_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL535: DSI_INT_FERR_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL536: DSI_INT_PPI_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL537: DSI_INT_DEBUG_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL538: LCDC_VSPD_INT_IRQSELn */                            \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL539: LCDC_DU_INT_IRQSELn */                              \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL540: MALIG31_IRQGPU_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL541: MALIG31_IRQJOB_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL542: MALIG31_IRQMMU_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL543: MALIG31_IRQEVENT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL544: VCD_VPO_VINTREQ_N_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL545: VCD_VPO_CINTREQ_N_IRQSELn */                        \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL546: SSIU_INTREQ_SSI0_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL547: SSIU_INTREQ_SSI1_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL548: SSIU_INTREQ_SSI2_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL549: SSIU_INTREQ_SSI3_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL550: SSIU_INTREQ_SSI4_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL551: SSIU_INTREQ_SSI5_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL552: SSIU_INTREQ_SSI6_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL553: SSIU_INTREQ_SSI7_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL554: SSIU_INTREQ_SSI8_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL555: SSIU_INTREQ_SSI9_MAIN_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL556: SPDIF0_INTREQ_SPDIF_N_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL557: SPDIF1_INTREQ_SPDIF_N_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL558: SPDIF2_INTREQ_SPDIF_N_IRQSELn */                    \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL559: SCU_INTREQ_SCU0_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL560: SCU_INTREQ_SCU1_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL561: SCU_INTREQ_SCU2_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL562: SCU_INTREQ_SCU3_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL563: SCU_INTREQ_SCU4_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL564: SCU_INTREQ_SCU5_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL565: SCU_INTREQ_SCU6_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL566: SCU_INTREQ_SCU7_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL567: SCU_INTREQ_SCU8_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL568: SCU_INTREQ_SCU9_ARM_IRQSELn */                      \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL569: DRP_NMLINT_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL570: DRP_ERRINT_IRQSELn */                               \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL571: DRPAI_NMLINT_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL572: DRPAI_ERRINT_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL573: DRPAI_MAC_NMLINT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL574: DRPAI_MAC_ERRINT_IRQSELn */                         \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL575: ADA_ADIREQ_N_IRQSELn */                             \
    BSP_GIC_SPI_DETECT_LEVEL,               /* SEL576: ADA_GBADIREQ_N_IRQSELn */                           \
    BSP_GIC_SPI_DETECT_LEVEL                /* SEL577: ADA_GCADIREQ_N_IRQSELn */                           \

#endif

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/
uint8_t g_gic_detect_type[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES] =
{
    BSP_IRQ_DETECT_TYPE_TABLE_BODY
};
uint8_t g_gic_sel_int_detect_type[BSP_FEATURE_SELECT_IRQSEL_MAX] = {BSP_SELECT_IRQ_DETECT_TYPE_TABLE_BODY};

#endif                                 /* BSP_IRQ_SENSE_H */
