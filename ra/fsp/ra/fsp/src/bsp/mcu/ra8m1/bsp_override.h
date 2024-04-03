/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RA8M1
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RA8M1) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Define overrides required for this MCU. */

#define BSP_OVERRIDE_ELC_PERIPHERAL_T
#define BSP_OVERRIDE_GROUP_IRQ_T

/* Override definitions. */

#define ELC_PERIPHERAL_NUM    (30U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef enum e_elc_peripheral
{
    ELC_PERIPHERAL_GPT_A   = (0),
    ELC_PERIPHERAL_GPT_B   = (1),
    ELC_PERIPHERAL_GPT_C   = (2),
    ELC_PERIPHERAL_GPT_D   = (3),
    ELC_PERIPHERAL_GPT_E   = (4),
    ELC_PERIPHERAL_GPT_F   = (5),
    ELC_PERIPHERAL_GPT_G   = (6),
    ELC_PERIPHERAL_GPT_H   = (7),
    ELC_PERIPHERAL_ADC0    = (8),
    ELC_PERIPHERAL_ADC0_B  = (9),
    ELC_PERIPHERAL_ADC1    = (10),
    ELC_PERIPHERAL_ADC1_B  = (11),
    ELC_PERIPHERAL_DAC0    = (12),
    ELC_PERIPHERAL_DAC1    = (13),
    ELC_PERIPHERAL_IOPORT1 = (14),
    ELC_PERIPHERAL_IOPORT2 = (15),
    ELC_PERIPHERAL_IOPORT3 = (16),
    ELC_PERIPHERAL_IOPORT4 = (17),
    ELC_PERIPHERAL_I3C     = (30),
} elc_peripheral_t;

/* Which interrupts can have callbacks registered. */
typedef enum e_bsp_grp_irq
{
    BSP_GRP_IRQ_IWDT_ERROR      = 0,   ///< IWDT underflow/refresh error has occurred
    BSP_GRP_IRQ_WDT_ERROR       = 1,   ///< WDT underflow/refresh error has occurred
    BSP_GRP_IRQ_LVD1            = 2,   ///< Voltage monitoring 1 interrupt
    BSP_GRP_IRQ_LVD2            = 3,   ///< Voltage monitoring 2 interrupt
    BSP_GRP_IRQ_OSC_STOP_DETECT = 6,   ///< Oscillation stop is detected
    BSP_GRP_IRQ_NMI_PIN         = 7,   ///< NMI Pin interrupt
    BSP_GRP_IRQ_MPU_BUS_TZF     = 12,  ///< MPU Bus or TrustZone Filter Error
    BSP_GRP_IRQ_COMMON_MEMORY   = 13,  ///< SRAM ECC or SRAM Parity Error
    BSP_GRP_IRQ_LOCKUP          = 15,  ///< LockUp Error
} bsp_grp_irq_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
