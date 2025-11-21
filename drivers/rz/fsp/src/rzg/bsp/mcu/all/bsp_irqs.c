/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_irqs.c
 * Version      : 1.00
 * Description  : bsp_irq (secure) source code
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_irq.h"
#include "bsp_irqs.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_BITS_PER_WORD          (32)
#define BSP_PRV_DISABLE_SPI_SEL        (0x3FF)
#define BSP_PRV_SPI_SEL_ALL_DISABLE    (0x3FFFFFFFU)
#define BSP_PRV_SPI_SEL_SETTING_NUM    (3)
#define BSP_PRV_SPI_SEL_LENGTH         (10UL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * External symbols
 **********************************************************************************************************************/
#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)
const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES -
                                                          BSP_FEATURE_ICU_FIXED_INTSEL_COUNT]  BSP_WEAK_REFERENCE =
{
    (bsp_interrupt_event_t) IRQSEL_NONE
};
#endif

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */

/*******************************************************************************************************************//**
 * This function provides clock to DMA Controller (see section 'Precaution when use the peripheral modules
 * which can initiate DMA Controller.' in the user's manual for detail) and enables IM33.
 * It also enables any interrupt in a non-secure state.
 **********************************************************************************************************************/
void bsp_irq_cfg_s (void)
{
#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)
    volatile uint32_t * intm33selx_addr = &R_INTC->INTM33SEL0;

    for (uint32_t sel_register_num = 0U; sel_register_num < BSP_FEATURE_ICU_INTSEL_NUM; sel_register_num++)
    {
        uint32_t spi_sel = BSP_PRV_SPI_SEL_ALL_DISABLE;

        /* Loop through all SPIk_SELn bits. */
        for (uint32_t sel_bit_num = 0; sel_bit_num < BSP_PRV_SPI_SEL_SETTING_NUM; sel_bit_num++)
        {
            uint32_t sel_num = (sel_register_num * BSP_PRV_SPI_SEL_SETTING_NUM) + sel_bit_num;

            spi_sel &= ~(R_INTC_INTM33SEL0_M33SPI0_SEL0_Msk << (BSP_PRV_SPI_SEL_LENGTH * sel_bit_num));
            spi_sel |=
                (uint32_t) ((g_interrupt_event_link_select[sel_num] == IRQSEL_NONE) ?
                            BSP_PRV_DISABLE_SPI_SEL :
                            g_interrupt_event_link_select[sel_num]) << (BSP_PRV_SPI_SEL_LENGTH * sel_bit_num);
        }

        intm33selx_addr[sel_register_num] = spi_sel;
    }
#endif

#if BSP_FEATURE_BSP_INT_SIGNAL_VIA_DMAC
    R_BSP_MODULE_CLKON(FSP_IP_DMAC, 0);
    R_BSP_MODULE_RSTOFF(FSP_IP_DMAC, 0);
    R_BSP_MODULE_CLKON(FSP_IP_DMAC, 1);
    R_BSP_MODULE_RSTOFF(FSP_IP_DMAC, 1);
#endif
    R_BSP_IM33_ENABLE();

#if BSP_NONSECURE_TRANSITION
 #if FSP_PRIV_TZ_USE_SECURE_REGS

    /* Place all vectors in non-secure state. */
    for (uint32_t i = 0U; i < (BSP_ICU_VECTOR_MAX_ENTRIES / BSP_PRV_BITS_PER_WORD); i++)
    {
        NVIC->ITNS[i] = UINT32_MAX;
    }
 #endif
#endif
}
