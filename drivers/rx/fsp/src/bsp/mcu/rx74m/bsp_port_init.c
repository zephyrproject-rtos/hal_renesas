/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/* RX MCUs come in different packages and different pin counts.
 * Each bit of PORTm.PDR corresponds to each pin of port m; I/O direction can be specified in 1-bit units.
 * Each bit of PDR corresponding to port m that does not exist is reserved.
 * Also, each bits of PDR corresponding to P305, P308 and P309 pins are reserved, because such pins are input only.
 * Initialization of the Port Direction Register (PDR).
 * These values are then ORed into the direction registers to set non-existent pins as outputs or
 * inputs, which can help save power.
 */
#if BSP_PACKAGE_PINS == 320

 #define BSP_PRV_PORT0_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT1_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT2_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT3_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT4_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT5_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT6_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT7_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT8_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT9_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTA_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTB_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTC_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTD_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTE_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTF_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTG_NE_PIN_MASK    (0x0000)
#elif BSP_PACKAGE_PINS == 224

 #define BSP_PRV_PORT0_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT1_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT2_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT3_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT4_NE_PIN_MASK    (0x3F00)
 #define BSP_PRV_PORT5_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT6_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT7_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT8_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT9_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTA_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTB_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTC_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTD_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTE_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTF_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTG_NE_PIN_MASK    (0xFF00)
#elif BSP_PACKAGE_PINS == 176

 #define BSP_PRV_PORT0_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT1_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT2_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT3_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT4_NE_PIN_MASK    (0x3F00)
 #define BSP_PRV_PORT5_NE_PIN_MASK    (0xFFF0)
 #define BSP_PRV_PORT6_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT7_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT8_NE_PIN_MASK    (0x00C0)
 #define BSP_PRV_PORT9_NE_PIN_MASK    (0x00F0)
 #define BSP_PRV_PORTA_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTB_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTC_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTD_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTE_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTF_NE_PIN_MASK    (0x03FC)
 #define BSP_PRV_PORTG_NE_PIN_MASK    (0xFFF8)
#elif BSP_PACKAGE_PINS == 144

 #define BSP_PRV_PORT0_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT1_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT2_NE_PIN_MASK    (0xFF00)
 #define BSP_PRV_PORT3_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT4_NE_PIN_MASK    (0x3FC0)
 #define BSP_PRV_PORT5_NE_PIN_MASK    (0xFFFF)
 #define BSP_PRV_PORT6_NE_PIN_MASK    (0x00C0)
 #define BSP_PRV_PORT7_NE_PIN_MASK    (0xFFF8)
 #define BSP_PRV_PORT8_NE_PIN_MASK    (0x00F0)
 #define BSP_PRV_PORT9_NE_PIN_MASK    (0x00FC)
 #define BSP_PRV_PORTA_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTB_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTC_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTD_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTE_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTF_NE_PIN_MASK    (0x03FC)
 #define BSP_PRV_PORTG_NE_PIN_MASK    (0xFFFF)
#elif BSP_PACKAGE_PINS == 100

 #define BSP_PRV_PORT0_NE_PIN_MASK    (0xFF01)
 #define BSP_PRV_PORT1_NE_PIN_MASK    (0xFF01)
 #define BSP_PRV_PORT2_NE_PIN_MASK    (0xFFFC)
 #define BSP_PRV_PORT3_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORT4_NE_PIN_MASK    (0xBFEA)
 #define BSP_PRV_PORT5_NE_PIN_MASK    (0xFFFF)
 #define BSP_PRV_PORT6_NE_PIN_MASK    (0x00FC)
 #define BSP_PRV_PORT7_NE_PIN_MASK    (0xFFFF)
 #define BSP_PRV_PORT8_NE_PIN_MASK    (0x00FF)
 #define BSP_PRV_PORT9_NE_PIN_MASK    (0x00FF)
 #define BSP_PRV_PORTA_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTB_NE_PIN_MASK    (0x0080)
 #define BSP_PRV_PORTC_NE_PIN_MASK    (0x0080)
 #define BSP_PRV_PORTD_NE_PIN_MASK    (0x0000)
 #define BSP_PRV_PORTE_NE_PIN_MASK    (0x0080)
 #define BSP_PRV_PORTF_NE_PIN_MASK    (0x03FC)
 #define BSP_PRV_PORTG_NE_PIN_MASK    (0xFFFF)
#else
 #error "This package is not defined in mcu_init.c"
#endif

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Function Name: bsp_non_existent_port_init
 * Description  : For MCUs that do not have the maximum number of pins for their group (e.g. MCU with 176 pins when
 *                maximum is 224 pins) these 'non-existent' pins that are not bonded out need to be initialized to save
 *                power.
 * Arguments    : none
 * Return Value : none
 ***********************************************************************************************************************/
void bsp_non_existent_port_init (void)
{
    /* OR in missing pin masks from above. */

    /* Set PORT0.PDR */
    R_PORT0->PDR |= BSP_PRV_PORT0_NE_PIN_MASK;

    /* Set PORT1.PDR */
    R_PORT1->PDR |= BSP_PRV_PORT1_NE_PIN_MASK;

    /* Set PORT2.PDR */
    R_PORT2->PDR |= BSP_PRV_PORT2_NE_PIN_MASK;

    /* Set PORT3.PDR */
    R_PORT3->PDR |= BSP_PRV_PORT3_NE_PIN_MASK;

    /* Set PORT4.PDR */
    R_PORT4->PDR |= BSP_PRV_PORT4_NE_PIN_MASK;

    /* Set PORT5.PDR */
    R_PORT5->PDR |= BSP_PRV_PORT5_NE_PIN_MASK;

    /* Set PORT6.PDR */
    R_PORT6->PDR |= BSP_PRV_PORT6_NE_PIN_MASK;

    /* Set PORT7.PDR */
    R_PORT7->PDR |= BSP_PRV_PORT7_NE_PIN_MASK;

    /* Set PORT8.PDR */
    R_PORT8->PDR |= BSP_PRV_PORT8_NE_PIN_MASK;

    /* Set PORT9.PDR */
    R_PORT9->PDR |= BSP_PRV_PORT9_NE_PIN_MASK;

    /* Set PORTA.PDR */
    R_PORT10->PDR |= BSP_PRV_PORTA_NE_PIN_MASK;

    /* Set PORTB.PDR */
    R_PORT11->PDR |= BSP_PRV_PORTB_NE_PIN_MASK;

    /* Set PORTC.PDR */
    R_PORT12->PDR |= BSP_PRV_PORTC_NE_PIN_MASK;

    /* Set PORTD.PDR */
    R_PORT13->PDR |= BSP_PRV_PORTD_NE_PIN_MASK;

    /* Set PORTE.PDR */
    R_PORT14->PDR |= BSP_PRV_PORTE_NE_PIN_MASK;

    /* Set PORTF.PDR */
    R_PORT15->PDR |= BSP_PRV_PORTF_NE_PIN_MASK;

    /* Set PORTG.PDR */
    R_PORT16->PDR |= BSP_PRV_PORTG_NE_PIN_MASK;
}                                      /* End of function bsp_non_existent_port_init() */
