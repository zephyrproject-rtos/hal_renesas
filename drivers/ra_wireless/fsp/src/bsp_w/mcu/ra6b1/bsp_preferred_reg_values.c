/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_preferred_reg_values.h"
#include "bsp_pd.h"

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/
void bsp_set_preferred_reg_values (bsp_power_domain_t power_domain)
{
    switch (power_domain)
    {
        case BSP_PD_MEM:
        {
            FSP_REG_SET_MASKED(XTAL32M, XTAL32M_CFG_REG, 0x0007C000UL, 0x00205803);
            FSP_REG_SET_MASKED(XTAL32M, XTAL32M_OSC_REG, 0xF0000000UL, 0xF5272028);
            break;
        }

        case BSP_PD_SLP:
        {
            FSP_REG_SET_MASKED(PMU_ANA, BIAS_VREF_SEL_REG, 0x000000F0UL, 0x0000009A);
            FSP_REG_SET_MASKED(PMU_ANA, TEMPSENSE_CTRL2_REG, 0x002003C0UL, 0x001F10C4);
            break;
        }

        case BSP_PD_PER:
        {
            FSP_REG_SET_MASKED(ADC, ADC_CTRL_REG, 0x0001FE00UL, 0x0021FF00);
            FSP_MEM_SET_MASKED(0x40400264UL, 0x00003801UL, 0x00003801);
            break;
        }

        case BSP_PD_AON:
        {
            FSP_REG_SET_MASKED(CRG_AON, CLK_XTAL32K_REG, 0x000000FEUL, 0x00014042);
            break;
        }

        default:
        {
            break;
        }
    }
}

/** @} (end addtogroup BSP_MCU) */
