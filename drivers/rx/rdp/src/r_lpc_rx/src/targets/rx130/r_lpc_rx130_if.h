/***********************************************************************************************************************
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : r_lpc_rx130_if.h
 * Description  : Definitions used by the r_lpc_rx130.c module.
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version Description           
 *         : 01.10.2016 1.00    First Release
 *         : 15.03.2025 2.51    Updated disclaimer.
 ***********************************************************************************************************************/

#ifndef R_LPC_RX130_IF_H
    #define R_LPC_RX130_IF_H

/***********************************************************************************************************************
 Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 Typedef definitions
 ***********************************************************************************************************************/
typedef enum lpc_low_power_mode
{
    LPC_LP_SLEEP,
    LPC_LP_DEEP_SLEEP,
    LPC_LP_SW_STANDBY,
    LPC_LP_INVALID_MODE
}lpc_low_power_mode_t;

typedef enum lpc_operating_mode
{
    LPC_OP_HIGH_SPEED = 0x00,
    LPC_OP_MIDDLE_SPEED = 0x02,
    LPC_OP_LOW_SPEED = 0x06,
    LPC_OP_INVALID_MODE
}lpc_operating_mode_t;

/* LPC Sleep Mode Return Clock Switching Sources*/
typedef enum lpc_clock_switch
{
    LPC_LOCO = 0x00,
    LPC_HOCO = 0x01,
    LPC_MAIN_OSC = 0x02,
}lpc_clock_switch_t;

/* Available system clock sources. Maps to CKSEL[2:0] */
typedef enum lpc_clocks
{
    LPC_CKSEL_LOCO = 0x00,
    LPC_CKSEL_HOCO = 0x01,
    LPC_CKSEL_MAIN_OSC = 0x02,
    LPC_CKSEL_SUBCLOCK = 0x03,
    LPC_CKSEL_PLL = 0x04,
    LPC_CKSEL_IWDT,                    // cannot be used as a system clock source
    LPC_END_OF_CLOCKLIST
}lpc_clocks_t;

/* System Clocks. Don't change the order of this list. */
typedef enum lpc_system_clocks
{
    LPC_ICLK,
    LPC_FCLK,
    LPC_PCLKB,
    LPC_PCLKD,
}lpc_system_clocks_t;

/* PLL Dividers */
typedef enum lpc_pll_divider
{
    LPC_PLL_DIV_1 = 0x00,
    LPC_PLL_DIV_2 = 0x01,
    LPC_PLL_DIV_4 = 0x02
}lpc_pll_divider_t;

/***********************************************************************************************************************
 Exported global variables
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/
#endif /* R_LPC_RX130_IF_H */
