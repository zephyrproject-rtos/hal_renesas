/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_PD_CTRL_RA6B1_H
#define BSP_PD_CTRL_RA6B1_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @brief Available peripheral triggers to the PDC.
 **********************************************************************************************************************/
typedef enum e_bsp_pd_ctrl_periph_trig
{
    BSP_PD_CTRL_PERIPH_TRIG_TIM          = 0x0,  ///< Timer IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TIM2         = 0x1,  ///< Timer2 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TIM3         = 0x2,  ///< Timer3 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TIM4         = 0x3,  ///< Timer4 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TIM5         = 0x4,  ///< Timer5 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TIM6         = 0x5,  ///< Timer6 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TIM7         = 0x6,  ///< Timer7 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TIM8         = 0x7,  ///< Timer8 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TIM9         = 0x8,  ///< Timer9 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TIM10        = 0x9,  ///< Timer10 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_RTC_ALARM    = 0xA,  ///< RTC Alarm Event
    BSP_PD_CTRL_PERIPH_TRIG_RTC_RO       = 0xB,  ///< RTC Rollover
    BSP_PD_CTRL_PERIPH_TRIG_CMAC_SLPTIM  = 0xC,  ///< CMAC Sleep Timer
    BSP_PD_CTRL_PERIPH_TRIG_SYS2CMAC     = 0xD,  ///< SYSCPU to CMAC IRQ
    BSP_PD_CTRL_PERIPH_TRIG_XTALRDY      = 0xE,  ///< XTAL32M Clock Ready IRQ
    BSP_PD_CTRL_PERIPH_TRIG_WKUP_KEY     = 0xF,  ///< Debounced Button Press IRQ
    BSP_PD_CTRL_PERIPH_TRIG_DBG          = 0x10, ///< Debugger Present IRQ
    BSP_PD_CTRL_PERIPH_TRIG_CMAC2SYS     = 0x11, ///< CMAC to SYSCPU IRQ
    BSP_PD_CTRL_PERIPH_TRIG_NVMC         = 0x12, ///< NVM Controller IRQ
    BSP_PD_CTRL_PERIPH_TRIG_PDC_PEND_SW  = 0x13, ///< Software Trigger Only
    BSP_PD_CTRL_PERIPH_TRIG_QDEC         = 0x14, ///< Quadrature decoder IRQ
    BSP_PD_CTRL_PERIPH_TRIG_QDEC2        = 0x15, ///< Quadrature decoder 2 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_KBSCN        = 0x16, ///< Keyboard Scanner IRQ
    BSP_PD_CTRL_PERIPH_TRIG_DTC_COMPLETE = 0x17, ///< Triggers per DTC transaction end, not DTC descriptor end
    BSP_PD_CTRL_PERIPH_TRIG_ELC_PDC      = 0x18, ///< ELC output
    BSP_PD_CTRL_PERIPH_TRIG_GPIO_P0      = 0x19, ///< GPIO Port 0 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_GPIO_P1      = 0x1A, ///< GPIO Port 1 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_GPIO_P2      = 0x1B, ///< GPIO Port 2 IRQ
    BSP_PD_CTRL_PERIPH_TRIG_I3C_IB       = 0x1C, ///< I3C Inbound IRQ received
    BSP_PD_CTRL_PERIPH_TRIG_ACOMP        = 0x1D, ///< Analog Comparator IRQ
    BSP_PD_CTRL_PERIPH_TRIG_TEMPSEN_THR  = 0x1E, ///< Temperature Sensor Threshold Matched IRQ
    BSP_PD_CTRL_PERIPH_TRIG_VUSB         = 0x1F, ///< VUSB Presence
} bsp_pd_ctrl_periph_trig_t;

/*******************************************************************************************************************//**
 * @brief Available enable flags for the PDC look-up table entries.
 **********************************************************************************************************************/
typedef enum e_bsp_pd_ctrl_options
{
    BSP_PD_CTRL_OPTIONS_DISABLED    = 0x0,                          ///< No extra wakeup options declared.
    BSP_PD_CTRL_OPTIONS_ENABLE_XTAL = PDC_PDC_CTRL_REG_EN_XTAL_Msk, ///< If set, XTAL32M will be started on wakeup.
    BSP_PD_CTRL_OPTIONS_ENABLE_TIM  = PDC_PDC_CTRL_REG_EN_TMR_Msk,  ///< If set, enables PD_TIM on wakeup.
    BSP_PD_CTRL_OPTIONS_ENABLE_PER  = PDC_PDC_CTRL_REG_EN_PER_Msk,  ///< If set, enables PD_PER on wakeup.
    BSP_PD_CTRL_OPTIONS_ENABLE_COM  = PDC_PDC_CTRL_REG_EN_COM_Msk,  ///< If set, enables PD_COM on wakeup.
} bsp_pd_ctrl_options_t;

/*******************************************************************************************************************//**
 * @brief Available masters for the PDC look-up table entries.
 **********************************************************************************************************************/
typedef enum e_bsp_pd_ctrl_master
{
    BSP_PD_CTRL_MASTER_NONE    = 0x0,  ///< No Master, indicates empty entry
    BSP_PD_CTRL_MASTER_SYSCPU  = 0x1,  ///< SYSCPU
    BSP_PD_CTRL_MASTER_CMACCPU = 0x2,  ///< CMACCPU
    BSP_PD_CTRL_MASTER_INVALID = 0x3,  ///< Invalid Master
} bsp_pd_ctrl_master_t;

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
