/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_DMAC_H
#define BSP_DMAC_H

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Channel request trigger */
typedef enum e_bsp_dmac_trig_ra6b1
{
    BSP_DMAC_TRIG_SPI1_RX   = 0x0,
    BSP_DMAC_TRIG_SPI1_TX   = 0x1,
    BSP_DMAC_TRIG_SPI2_RX   = 0x2,
    BSP_DMAC_TRIG_SPI2_TX   = 0x3,
    BSP_DMAC_TRIG_SPI3_RX   = 0x4,
    BSP_DMAC_TRIG_SPI3_TX   = 0x5,
    BSP_DMAC_TRIG_UART1_RX  = 0x6,
    BSP_DMAC_TRIG_UART1_TX  = 0x7,
    BSP_DMAC_TRIG_UART2_RX  = 0x8,
    BSP_DMAC_TRIG_UART2_TX  = 0x9,
    BSP_DMAC_TRIG_UART3_RX  = 0xA,
    BSP_DMAC_TRIG_UART3_TX  = 0xB,
    BSP_DMAC_TRIG_UART4_RX  = 0xC,
    BSP_DMAC_TRIG_UART4_TX  = 0xD,
    BSP_DMAC_TRIG_I2C1_RX   = 0xE,
    BSP_DMAC_TRIG_I2C1_TX   = 0xF,
    BSP_DMAC_TRIG_I2C2_RX   = 0x10,
    BSP_DMAC_TRIG_I2C2_TX   = 0x11,
    BSP_DMAC_TRIG_I2C3_RX   = 0x12,
    BSP_DMAC_TRIG_I2C3_TX   = 0x13,
    BSP_DMAC_TRIG_I3C_RX    = 0x14,
    BSP_DMAC_TRIG_I3C_TX    = 0x15,
    BSP_DMAC_TRIG_CANFD_RX  = 0x16,
    BSP_DMAC_TRIG_CANFD_TX  = 0x17,
    BSP_DMAC_TRIG_CANFD_COM = 0x18,
    BSP_DMAC_TRIG_NVMC      = 0x19,
    BSP_DMAC_TRIG_DAI_IN_R  = 0x1A,
    BSP_DMAC_TRIG_DAI_IN_L  = 0x1B,
    BSP_DMAC_TRIG_DAI_OUT_R = 0x1C,
    BSP_DMAC_TRIG_DAI_OUT_L = 0x1D,
    BSP_DMAC_TRIG_SWI_RX    = 0x1E,
    BSP_DMAC_TRIG_SWI_TX    = 0x1F,
    BSP_DMAC_TRIG_ADC       = 0x20,
    BSP_DMAC_TRIG_SRC_IN_R  = 0x21,
    BSP_DMAC_TRIG_SRC_IN_L  = 0x22,
    BSP_DMAC_TRIG_SRC_OUT_R = 0x23,
    BSP_DMAC_TRIG_SRC_OUT_L = 0x24,
    BSP_DMAC_TRIG_USB_RX    = 0x25,
    BSP_DMAC_TRIG_USB_TX    = 0x26,
    BSP_DMAC_TRIG_RSIP_TX   = 0x27,
    BSP_DMAC_TRIG_RSIP_RX   = 0x28,
    BSP_DMAC_TRIG_NONE      = 0x3F,
} bsp_dmac_trig_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************/ /**
 * Check whether specified DMA trigger is edge sensitive or not.
 *
 * @param[in] trigger        DMA trigger.
 *
 * @retval true              Trigger is (positive) edge-sensitive.
 * @retval false             Trigger is level-sensitive.
 **********************************************************************************************************************/
__STATIC_INLINE bool R_BSP_DMAC_IsEdgeSensitiveTrigger (bsp_dmac_trig_t trigger)
{
    return BSP_DMAC_TRIG_UART1_TX == trigger || BSP_DMAC_TRIG_UART2_TX == trigger ||
           BSP_DMAC_TRIG_UART3_TX == trigger || BSP_DMAC_TRIG_UART4_TX == trigger ||
           BSP_DMAC_TRIG_I2C1_TX == trigger || BSP_DMAC_TRIG_I2C2_TX == trigger ||
           BSP_DMAC_TRIG_I2C3_TX == trigger || BSP_DMAC_TRIG_USB_TX == trigger;
}

/*******************************************************************************************************************/ /**
 * Enable interrupt generation by specified DMA channel.
 *
 * @param[in] channel        DMA channel.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_DMAC_ChannelInterruptsEnable (uint8_t channel)
{
    DMA->DMA_SET_INT_MASK_REG = 1 << channel;
}

/*******************************************************************************************************************/ /**
 * Disable interrupt generation by specified DMA channel.
 *
 * @param[in] channel        DMA channel.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_DMAC_ChannelInterruptsDisable (uint8_t channel)
{
    DMA->DMA_RESET_INT_MASK_REG = 1 << channel;
}

/** @} (end addtogroup BSP_MCU) */

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
