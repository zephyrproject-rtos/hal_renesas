/***********************************************************************************************************************
* Copyright (c) 2023 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_gpio_rx26t.c
* Description  : Data for r_gpio_rx driver specific to RX26T.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version Description
*         : 07.04.2023 1.00    First Release
*         : 15.03.2025 5.11    Updated disclaimer.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* Includes board and MCU related header files. */
#include "platform.h"

#if defined(BSP_MCU_RX26T)

/* Public interface header file for this package. */
#include "r_gpio_rx_if.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
/* These arrays hold which pins have extra functionality. For example, not all pins have the option of enabling
 * open-drain N-channel output instead of the default CMOS output. Each entry in the array corresponds to a port.
 * Each bit in each entry corresponds to a pin on that port. If bit 3 of array entry [4] was set to 1 then that would
 * mean that PORT 4 PIN 3 supported the feature that array represented.
 *
 * These arrays are only used when GPIO_CFG_PARAM_CHECKING_ENABLE is set to 1 (checking enabled). If you know that
 * your code does not need to check the pins then you can set this macro to 0 and save a little execution time
 * and ROM space.
 *
 * Note: These arrays are defined for the largest package part. For smaller packages where some pins do not exist,
 *       pin checking is filtered by the enumerated port_pin list for that package as defined in r_gpio_rx26t.h.
 */

#if (GPIO_CFG_PARAM_CHECKING_ENABLE == 1)
const uint8_t g_gpio_open_drain_n_support[GPIO_INFO_NUM_PORTS] =
{
    0x03,     //PORT0   P00, P01
    0x03,     //PORT1   P10, P11
    0x9F,     //PORT2   P20 to P24, P27
    0xCF,     //PORT3   P30 to P33, P36, P37
    0xFF,     //PORT4   P40 to P47
    0x3F,     //PORT5   P50 to P55
    0x3F,     //PORT6   P60 to P65
    0x7F,     //PORT7   P70 to P76
    0x07,     //PORT8   P80 to P82
    0x7F,     //PORT9   P90 to P96
    0x3F,     //PORTA   PA0 to PA5
    0xFF,     //PORTB   PB0 to PB7
    0x00,     //PORTC   None
    0xFF,     //PORTD   PD0 to PD7
    0x3B,     //PORTE   PE0, PE1, PE3 to PE5
    0x00,     //PORTF   None
    0x00,     //PORTG   None
    0x00,     //PORTH   None
    0x00,     //PORTJ   None
    0x00,     //PORTK   None
    0x00,     //PORTL   None
    0x00,     //PORTM   None
    0x40,     //PORTN   PN6
};

const uint8_t g_gpio_open_drain_p_support[GPIO_INFO_NUM_PORTS] =
{
    0x00,     //PORT0   None
    0x00,     //PORT1   None
    0x00,     //PORT2   None
    0x00,     //PORT3   None
    0x00,     //PORT4   None
    0x00,     //PORT5   None
    0x00,     //PORT6   None
    0x00,     //PORT7   None
    0x00,     //PORT8   None
    0x00,     //PORT9   None
    0x00,     //PORTA   None
    0x00,     //PORTB   None
    0x00,     //PORTC   None
    0x00,     //PORTD   None
    0x00,     //PORTE   None
    0x00,     //PORTF   None
    0x00,     //PORTG   None
    0x00,     //PORTH   None
    0x00,     //PORTJ   None
    0x00,     //PORTK   None
    0x00,     //PORTL   None
    0x00,     //PORTM   None
    0x00,     //PORTN   None
};

const uint8_t g_gpio_pull_up_support[GPIO_INFO_NUM_PORTS] =
{
    0x03,     //PORT0   P00, P01
    0x03,     //PORT1   P10, P11
    0x9F,     //PORT2   P20 to P24, P27
    0xCF,     //PORT3   P30 to P33, P36, P37
    0xFF,     //PORT4   P40 to P47
    0x3F,     //PORT5   P50 to P55
    0x3F,     //PORT6   P60 to P65
    0x7F,     //PORT7   P70 to P76
    0x07,     //PORT8   P80 to P82
    0x7F,     //PORT9   P90 to P96
    0x3F,     //PORTA   PA0 to PA5
    0xFF,     //PORTB   PB0 to PB7
    0x00,     //PORTC   None
    0xFF,     //PORTD   PD0 to PD7
    0x3B,     //PORTE   PE0, PE1, PE3 to PE5
    0x00,     //PORTF   None
    0x00,     //PORTG   None
    0x00,     //PORTH   None
    0x00,     //PORTJ   None
    0x00,     //PORTK   None
    0x00,     //PORTL   None
    0x00,     //PORTM   None
    0xC0,     //PORTN   PN6, PN7
};

const uint8_t g_gpio_dscr_support[GPIO_INFO_NUM_PORTS] =
{
    0x03,     //PORT0   P00, P01
    0x03,     //PORT1   P10, P11
    0x9F,     //PORT2   P20 to P24, P27
    0x0F,     //PORT3   P30 to P33
    0x00,     //PORT4   None
    0x00,     //PORT5   None
    0x00,     //PORT6   None
    0x7F,     //PORT7   P70 to P76
    0x07,     //PORT8   P80 to P82
    0x7F,     //PORT9   P90 to P96
    0x3F,     //PORTA   PA0 to PA5
    0xFF,     //PORTB   PB0 to PB7
    0x00,     //PORTC   None
    0xFF,     //PORTD   PD0 to PD7
    0x3B,     //PORTE   PE0, PE1, PE3 to PE5
    0x00,     //PORTF   None
    0x00,     //PORTG   None
    0x00,     //PORTH   None
    0x00,     //PORTJ   None
    0x00,     //PORTK   None
    0x00,     //PORTL   None
    0x00,     //PORTM   None
    0x40,     //PORTN   PN6
};

const uint8_t g_gpio_dscr2_support[GPIO_INFO_NUM_PORTS] =
{
    0x00,     //PORT0   None
    0x00,     //PORT1   None
    0x00,     //PORT2   None
    0x00,     //PORT3   None
    0x00,     //PORT4   None
    0x00,     //PORT5   None
    0x00,     //PORT6   None
    0x7E,     //PORT7   P71 to P76
    0x02,     //PORT8   P81
    0x3F,     //PORT9   P90 to P95
    0x00,     //PORTA   None
    0x20,     //PORTB   PB5
    0x00,     //PORTC   None
    0x08,     //PORTD   PD3
    0x00,     //PORTE   None
    0x00,     //PORTF   None
    0x00,     //PORTG   None
    0x00,     //PORTH   None
    0x00,     //PORTJ   None
    0x00,     //PORTK   None
    0x00,     //PORTL   None
    0x00,     //PORTM   None
    0x00,     //PORTN   None
};

#endif /* GPIO_CFG_PARAM_CHECKING_ENABLE */

#endif /* BSP_MCU_RX26T */

