/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RA6B1
 * @{
 **********************************************************************************************************************/

#ifndef BSP_IO_RA6B1_H
#define BSP_IO_RA6B1_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/** bsp_io power source. */
typedef enum e_bsp_io_power_ra6b1
{
    BSP_IO_POWER_V33     = 0,          /**< V33 (3.3 V) power rail */
    BSP_IO_POWER_VDD1V8P = 1,          /**< VDD1V8P (1.8 V) power rail */
} bsp_io_power_t;

/** Clocks that can be mapped to dedicated BSP_IO */
typedef enum e_bsp_io_clk_output_ra6b1
{
    BSP_IO_CLK_XTAL32M_OUT = GPIO_GPIO_CLK_SEL_REG_XTAL32M_OUTPUT_EN_Msk, /**< Map clock XTAL32M to dedicated GPIO */
    BSP_IO_CLK_RCHS_OUT    = GPIO_GPIO_CLK_SEL_REG_RCHS_OUTPUT_EN_Msk,    /**< Map clock RCHS to dedicated GPIO */
    BSP_IO_CLK_DIVN_OUT    = GPIO_GPIO_CLK_SEL_REG_DIVN_OUTPUT_EN_Msk,    /**< Map clock DIVn to dedicated GPIO */
    BSP_IO_CLK_NONE_OUT    = 0,
} bsp_io_clk_output_t;

/** Clocks that can be mapped to GPIO function FUNC_CLOCK */
typedef enum e_bsp_io_clk_func_ra6b1
{
    BSP_IO_CLK_XTAL32K_FUNC      = 0,  /**< Map clock XTAL32K to GPIO function FUNC_CLOCK */
    BSP_IO_CLK_RCLP_FUNC         = 1,  /**< Map clock RCLP to GPIO function FUNC_CLOCK */
    BSP_IO_CLK_RCX_FUNC          = 2,  /**< Map clock RCX to GPIO function FUNC_CLOCK */
    BSP_IO_CLK_XTAL32M_FUNC      = 3,  /**< Map clock XTAL32M to GPIO function FUNC_CLOCK */
    BSP_IO_CLK_RCHS_FUNC         = 4,  /**< Map clock RCHS to GPIO function FUNC_CLOCK */
    BSP_IO_CLK_DIVN_FUNC         = 5,  /**< Map clock DIVN to GPIO function FUNC_CLOCK */
    BSP_IO_CLK_XTAL64M_DIV2_FUNC = 6,  /**< Map clock XTAL64M_DIV2 (XTAL64M divided by 2) to GPIO function FUNC_CLOCK */
    BSP_IO_CLK_PLL48M_DIV2_FUNC  = 7,  /**< Map clock PLL48M_DIV2 (PLLUSB divided by 2) to GPIO function FUNC_CLOCK */
} bsp_io_clk_func_t;

/* For use with E2studio, +1 offset needed to avoid overiding reserved BSP_CFG_CLKOUT_DISABLED = 0 used in gui clock tool */
#define BSP_IO_FUNC_CLK_XTAL32K         (BSP_IO_CLK_XTAL32K_FUNC + 1)
#define BSP_IO_FUNC_CLK_RCLP            (BSP_IO_CLK_RCLP_FUNC + 1)
#define BSP_IO_FUNC_CLK_RCX             (BSP_IO_CLK_RCX_FUNC + 1)
#define BSP_IO_FUNC_CLK_XTAL32M         (BSP_IO_CLK_XTAL32M_FUNC + 1)
#define BSP_IO_FUNC_CLK_RCHS            (BSP_IO_CLK_RCHS_FUNC + 1)
#define BSP_IO_FUNC_CLK_DIVN            (BSP_IO_CLK_DIVN_FUNC + 1)
#define BSP_IO_FUNC_CLK_XTAL64M_DIV2    (BSP_IO_CLK_XTAL64M_DIV2_FUNC + 1)
#define BSP_IO_FUNC_CLK_PLL48M_DIV2     (BSP_IO_CLK_PLL48M_DIV2_FUNC + 1)

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
