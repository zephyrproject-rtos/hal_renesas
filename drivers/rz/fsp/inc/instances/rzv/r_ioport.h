/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup IOPORT
 * @{
 **********************************************************************************************************************/

#ifndef R_IOPORT_H
#define R_IOPORT_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#include "r_ioport_api.h"
#if __has_include("r_ioport_cfg.h")
 #include "r_ioport_cfg.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Private definition to set enumeration values. */
#define IOPORT_PRV_PFS_PSEL_OFFSET    (24)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** IOPORT private control block. DO NOT MODIFY. Initialization occurs when R_IOPORT_Open() is called. */
typedef struct st_ioport_instance_ctrl
{
    uint32_t             open;
    void const         * p_context;
    ioport_cfg_t const * p_cfg;
} ioport_instance_ctrl_t;

#ifndef BSP_OVERRIDE_IOPORT_PERIPHERAL_T

/** Superset of all peripheral functions.  */
typedef enum e_ioport_peripheral
{
    /** Pin will function as a Mode0 peripheral pin */
    IOPORT_PERIPHERAL_MODE0 = (0x0UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode1 peripheral pin */
    IOPORT_PERIPHERAL_MODE1 = (0x1UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode2 peripheral pin */
    IOPORT_PERIPHERAL_MODE2 = (0x2UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode3 peripheral pin */
    IOPORT_PERIPHERAL_MODE3 = (0x3UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode4 peripheral pin */
    IOPORT_PERIPHERAL_MODE4 = (0x4UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode5 peripheral pin */
    IOPORT_PERIPHERAL_MODE5 = (0x5UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode6 peripheral pin */
    IOPORT_PERIPHERAL_MODE6 = (0x6UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode7 peripheral pin */
    IOPORT_PERIPHERAL_MODE7 = (0x7UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode8 peripheral pin */
    IOPORT_PERIPHERAL_MODE8 = (0x8UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode9 peripheral pin */
    IOPORT_PERIPHERAL_MODE9 = (0x9UL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode10 peripheral pin */
    IOPORT_PERIPHERAL_MODE10 = (0xAUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode11 peripheral pin */
    IOPORT_PERIPHERAL_MODE11 = (0xBUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode12 peripheral pin */
    IOPORT_PERIPHERAL_MODE12 = (0xCUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode13 peripheral pin */
    IOPORT_PERIPHERAL_MODE13 = (0xDUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode14 peripheral pin */
    IOPORT_PERIPHERAL_MODE14 = (0xEUL << IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode15 peripheral pin */
    IOPORT_PERIPHERAL_MODE15 = (0xFUL << IOPORT_PRV_PFS_PSEL_OFFSET),
} ioport_peripheral_t;

#endif

#ifndef BSP_OVERRIDE_IOPORT_CFG_OPTIONS_T

/** Options to configure pin functions  */
typedef enum e_ioport_cfg_options
{
    /* For PM Register */
    IOPORT_CFG_PORT_DIRECTION_HIZ          = 0x00000000,        ///< Sets the pin direction to Hi-Z (default)
    IOPORT_CFG_PORT_DIRECTION_INPUT        = 0x00000004,        ///< Sets the pin direction to input
    IOPORT_CFG_PORT_DIRECTION_OUTPUT       = 0x00000008,        ///< Sets the pin direction to output (input disable)
    IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT = 0x0000000C,        ///< Sets the pin direction to output (input enable)

    /* For P Register */
    IOPORT_CFG_PORT_OUTPUT_LOW  = 0x00000000,                   ///< Sets the pin level to low
    IOPORT_CFG_PORT_OUTPUT_HIGH = 0x00000001,                   ///< Sets the pin level to high

    /* For PUPD Register */
    IOPORT_CFG_PULLUP_PULLDOWN_DISABLE = 0x00000000,            ///< Disable the pin's internal pull-up and pull-down
    IOPORT_CFG_PULLUP_ENABLE           = 0x00000010,            ///< Enables the pin's internal pull-up
    IOPORT_CFG_PULLDOWN_ENABLE         = 0x00000020,            ///< Enables the pin's internal pull-down

    /* For NOD Register */
    IOPORT_CFG_NOD_DISABLE = 0x00000000,                        ///< Disable the pin's N-ch open-drain
    IOPORT_CFG_NOD_ENABLE  = 0x00000040,                        ///< Enables the pin's N-ch open-drain

    /* For SMT Register */
    IOPORT_CFG_SCHMITT_DISABLE = 0x00000000,                    ///< Disable the pin's Schmitt-trigger input
    IOPORT_CFG_SCHMITT_ENABLE  = 0x80000000,                    ///< Enables the pin's Schmitt-trigger input

    /* For IOLH Register */
    IOPORT_CFG_DRIVE_B00 = 0x00000000,                          ///< Sets the IOLH register value to b'00
    IOPORT_CFG_DRIVE_B01 = 0x00000400,                          ///< Sets the IOLH register value to b'01
    IOPORT_CFG_DRIVE_B10 = 0x00000800,                          ///< Sets the IOLH register value to b'10
    IOPORT_CFG_DRIVE_B11 = 0x00000C00,                          ///< Sets the IOLH register value to b'11

    /* For ISEL Register */
    IOPORT_CFG_TINT_DISABLE = 0x00000000,                       ///< Disable IRQ functionality for a pin
    IOPORT_CFG_TINT_ENABLE  = 0x00004000,                       ///< Sets pin as an IRQ pin

    /* For SR Register */
    IOPORT_CFG_SLEW_RATE_SLOW = 0x00000000,                     ///< Sets the pin slew-rate to slow
    IOPORT_CFG_SLEW_RATE_FAST = 0x00020000,                     ///< Sets the pin slew-rate to fast

    /* For IEN Register */
    IOPORT_CFG_SPECIAL_PURPOSE_PORT_INPUT_DISABLE = 0x00000000, ///< Disable input the pin of special purpose port
    IOPORT_CFG_SPECIAL_PURPOSE_PORT_INPUT_ENABLE  = 0x00040000, ///< Sets the pin of special purpose port to input

    /* For FILONOFF Register */
    IOPORT_CFG_NOISE_FILTER_OFF = 0x00000000,                   ///< Noise filter disable
    IOPORT_CFG_NOISE_FILTER_ON  = 0x00080000,                   ///< Noise filter enable

    /* For FILNUM Register */
    IOPORT_CFG_NOISE_FILTER_NUM_4STAGE  = 0x00000000,           ///< Sets the pin noise filter to 4-stage filter
    IOPORT_CFG_NOISE_FILTER_NUM_8STAGE  = 0x00100000,           ///< Sets the pin noise filter to 8-stage filter
    IOPORT_CFG_NOISE_FILTER_NUM_12STAGE = 0x00200000,           ///< Sets the pin noise filter to 12-stage filter
    IOPORT_CFG_NOISE_FILTER_NUM_16STAGE = 0x00300000,           ///< Sets the pin noise filter to 16-stage filter

    /* For FILCLKSEL Register */
    IOPORT_CFG_NOISE_FILTER_DIVIDED_B00 = 0x00000000,           ///< Sets the FILCLKSEL register value to b'00
    IOPORT_CFG_NOISE_FILTER_DIVIDED_B01 = 0x00400000,           ///< Sets the FILCLKSEL register value to b'01
    IOPORT_CFG_NOISE_FILTER_DIVIDED_B10 = 0x00800000,           ///< Sets the FILCLKSEL register value to b'10
    IOPORT_CFG_NOISE_FILTER_DIVIDED_B11 = 0x00C00000,           ///< Sets the FILCLKSEL register value to b'11

    /* For PMC Register */
    IOPORT_CFG_PERIPHERAL_PIN = 0x00010000                      ///< Enables pin to operate as a peripheral pin
} ioport_cfg_options_t;

#endif

/** Pin selection for port group
 *  @note Event link must be configured by the ELC
 */
typedef enum e_ioport_event_pin_selection
{
    IOPORT_EVENT_PIN_SELECTION_NONE  = 0x00, ///< No pin selection for port group
    IOPORT_EVENT_PIN_SELECTION_PIN_0 = 0x01, ///< Select pin 0 to port group
    IOPORT_EVENT_PIN_SELECTION_PIN_1 = 0x02, ///< Select pin 1 to port group
    IOPORT_EVENT_PIN_SELECTION_PIN_2 = 0x04, ///< Select pin 2 to port group
    IOPORT_EVENT_PIN_SELECTION_PIN_3 = 0x08, ///< Select pin 3 to port group
    IOPORT_EVENT_PIN_SELECTION_PIN_4 = 0x10, ///< Select pin 4 to port group
    IOPORT_EVENT_PIN_SELECTION_PIN_5 = 0x20, ///< Select pin 5 to port group
    IOPORT_EVENT_PIN_SELECTION_PIN_6 = 0x40, ///< Select pin 6 to port group
    IOPORT_EVENT_PIN_SELECTION_PIN_7 = 0x80, ///< Select pin 7 to port group
} ioport_event_pin_selection_t;

/** Port group operation
 *  @note Event link must be configured by the ELC
 */
typedef enum e_ioport_event_output_operation
{
    IOPORT_EVENT_OUTPUT_OPERATION_LOW    = 0x0, ///< Set Low output to output operation
    IOPORT_EVENT_OUTPUT_OPERATION_HIGH   = 0x1, ///< Set High output to output operation
    IOPORT_EVENT_OUTPUT_OPERATION_TOGGLE = 0x2, ///< Set toggle output to output operation
    IOPORT_EVENT_OUTPUT_OPERATION_BUFFER = 0x3, ///< Set buffer value output to output operation
} ioport_event_output_operation_t;

/** Input port group event control
 *  @note Event link must be configured by the ELC
 */
typedef enum e_ioport_event_control
{
    IOPORT_EVENT_CONTROL_DISABLE = 0x0, ///< Disable function related with event link
    IOPORT_EVENT_CONTROL_ENABLE  = 0x1, ///< Enable function related with event link
} ioport_event_control_t;

/** Single port event direction
 *  @note Event link must be configured by the ELC
 */
typedef enum e_ioport_event_direction
{
    IOPORT_EVENT_DIRECTION_OUTPUT = 0x0, ///< Set output direction to single port
    IOPORT_EVENT_DIRECTION_INPUT  = 0x1, ///< Set input direction to single port
} ioport_event_direction_t;

/** Input event edge detection
 *  @note Event link must be configured by the ELC
 */
typedef enum e_ioport_event_detection
{
    IOPORT_EVENT_DETECTION_RISING_EDGE  = 0x0, ///< Set rising edge to event detection for input event
    IOPORT_EVENT_DETECTION_FALLING_EDGE = 0x1, ///< Set falling edge to event detection for input event
    IOPORT_EVENT_DETECTION_BOTH_EGDE    = 0x2, ///< Set both edges to event detection for input event
} ioport_event_detection_t;

/** Initial value for buffer register
 *  @note Event link must be configured by the ELC
 */
typedef enum e_ioport_event_initial_buffer_value
{
    IOPORT_EVENT_INITIAL_BUFFER_VALUE_LOW  = 0U, ///< Set low to initial value of buffer register for input port group
    IOPORT_EVENT_INITIAL_BUFFER_VALUE_HIGH = 1U, ///< Set high to initial value of buffer register for input port group
} ioport_event_initial_buffer_value_t;

#ifndef BSP_OVERRIDE_IOPORT_NOISE_FILTER_IRQ_PORT_OFFSET_T

/** Superset of offset for all IRQ functions.  */
typedef enum e_ioport_noise_filter_irq_port_offset
{
    IOPORT_NOISE_FILTER_IRQ_P00_OFFSET = 0x00, /* IRQ0 */
    IOPORT_NOISE_FILTER_IRQ_P01_OFFSET = 0x02, /* IRQ1 */
    IOPORT_NOISE_FILTER_IRQ_P02_OFFSET = 0x04, /* IRQ2 */
    IOPORT_NOISE_FILTER_IRQ_P03_OFFSET = 0x06, /* IRQ3 */
    IOPORT_NOISE_FILTER_IRQ_P04_OFFSET = 0x10, /* IRQ8 */
    IOPORT_NOISE_FILTER_IRQ_P05_OFFSET = 0x12, /* IRQ9 */
    IOPORT_NOISE_FILTER_IRQ_P06_OFFSET = 0x18, /* IRQ12 */
    IOPORT_NOISE_FILTER_IRQ_P07_OFFSET = 0x1A, /* IRQ13 */

    IOPORT_NOISE_FILTER_IRQ_P10_OFFSET = 0x08, /* IRQ4 */
    IOPORT_NOISE_FILTER_IRQ_P11_OFFSET = 0x0A, /* IRQ5 */
    IOPORT_NOISE_FILTER_IRQ_P12_OFFSET = 0x0C, /* IRQ6 */
    IOPORT_NOISE_FILTER_IRQ_P13_OFFSET = 0x0E, /* IRQ7 */
    IOPORT_NOISE_FILTER_IRQ_P14_OFFSET = 0x14, /* IRQ10 */
    IOPORT_NOISE_FILTER_IRQ_P15_OFFSET = 0x16, /* IRQ11 */
    IOPORT_NOISE_FILTER_IRQ_P16_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_P17_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_P20_OFFSET = 0x1C, /* IRQ14 */
    IOPORT_NOISE_FILTER_IRQ_P21_OFFSET = 0x1E, /* IRQ15 */

    IOPORT_NOISE_FILTER_IRQ_P30_OFFSET = 0x00, /* IRQ0 */
    IOPORT_NOISE_FILTER_IRQ_P31_OFFSET = 0x02, /* IRQ1 */
    IOPORT_NOISE_FILTER_IRQ_P32_OFFSET = 0x04, /* IRQ2 */
    IOPORT_NOISE_FILTER_IRQ_P33_OFFSET = 0x06, /* IRQ3 */
    IOPORT_NOISE_FILTER_IRQ_P34_OFFSET = 0x08, /* IRQ4 */
    IOPORT_NOISE_FILTER_IRQ_P35_OFFSET = 0x0A, /* IRQ5 */
    IOPORT_NOISE_FILTER_IRQ_P36_OFFSET = 0x0C, /* IRQ6 */
    IOPORT_NOISE_FILTER_IRQ_P37_OFFSET = 0x0E, /* IRQ7 */

    IOPORT_NOISE_FILTER_IRQ_P40_OFFSET = 0x10, /* IRQ8 */
    IOPORT_NOISE_FILTER_IRQ_P41_OFFSET = 0x12, /* IRQ9 */
    IOPORT_NOISE_FILTER_IRQ_P42_OFFSET = 0x14, /* IRQ10 */
    IOPORT_NOISE_FILTER_IRQ_P43_OFFSET = 0x16, /* IRQ11 */
    IOPORT_NOISE_FILTER_IRQ_P44_OFFSET = 0x18, /* IRQ12 */
    IOPORT_NOISE_FILTER_IRQ_P45_OFFSET = 0x1A, /* IRQ13 */
    IOPORT_NOISE_FILTER_IRQ_P46_OFFSET = 0x1C, /* IRQ14 */
    IOPORT_NOISE_FILTER_IRQ_P47_OFFSET = 0x1E, /* IRQ15 */

    IOPORT_NOISE_FILTER_IRQ_P50_OFFSET = 0x00, /* IRQ0 */
    IOPORT_NOISE_FILTER_IRQ_P51_OFFSET = 0x02, /* IRQ1 */
    IOPORT_NOISE_FILTER_IRQ_P52_OFFSET = 0x08, /* IRQ4 */
    IOPORT_NOISE_FILTER_IRQ_P53_OFFSET = 0x0A, /* IRQ5 */
    IOPORT_NOISE_FILTER_IRQ_P54_OFFSET = 0x10, /* IRQ8 */
    IOPORT_NOISE_FILTER_IRQ_P55_OFFSET = 0x12, /* IRQ9 */
    IOPORT_NOISE_FILTER_IRQ_P56_OFFSET = 0x18, /* IRQ12 */
    IOPORT_NOISE_FILTER_IRQ_P57_OFFSET = 0x1A, /* IRQ13 */

    IOPORT_NOISE_FILTER_IRQ_P60_OFFSET = 0x04, /* IRQ2 */
    IOPORT_NOISE_FILTER_IRQ_P61_OFFSET = 0x06, /* IRQ3 */
    IOPORT_NOISE_FILTER_IRQ_P62_OFFSET = 0x0C, /* IRQ6 */
    IOPORT_NOISE_FILTER_IRQ_P63_OFFSET = 0x0E, /* IRQ7 */
    IOPORT_NOISE_FILTER_IRQ_P64_OFFSET = 0x14, /* IRQ10 */
    IOPORT_NOISE_FILTER_IRQ_P65_OFFSET = 0x16, /* IRQ11 */
    IOPORT_NOISE_FILTER_IRQ_P66_OFFSET = 0x1C, /* IRQ14 */
    IOPORT_NOISE_FILTER_IRQ_P67_OFFSET = 0x1E, /* IRQ15 */

    IOPORT_NOISE_FILTER_IRQ_P70_OFFSET = 0x00, /* IRQ0 */
    IOPORT_NOISE_FILTER_IRQ_P71_OFFSET = 0x02, /* IRQ1 */
    IOPORT_NOISE_FILTER_IRQ_P72_OFFSET = 0x08, /* IRQ4 */
    IOPORT_NOISE_FILTER_IRQ_P73_OFFSET = 0x0A, /* IRQ5 */
    IOPORT_NOISE_FILTER_IRQ_P74_OFFSET = 0x10, /* IRQ8 */
    IOPORT_NOISE_FILTER_IRQ_P75_OFFSET = 0x12, /* IRQ9 */
    IOPORT_NOISE_FILTER_IRQ_P76_OFFSET = 0x18, /* IRQ12 */
    IOPORT_NOISE_FILTER_IRQ_P77_OFFSET = 0x1A, /* IRQ13 */

    IOPORT_NOISE_FILTER_IRQ_P80_OFFSET = 0x04, /* IRQ2 */
    IOPORT_NOISE_FILTER_IRQ_P81_OFFSET = 0x06, /* IRQ3 */
    IOPORT_NOISE_FILTER_IRQ_P82_OFFSET = 0x0C, /* IRQ6 */
    IOPORT_NOISE_FILTER_IRQ_P83_OFFSET = 0x12, /* IRQ7 */
    IOPORT_NOISE_FILTER_IRQ_P84_OFFSET = 0x14, /* IRQ10 */
    IOPORT_NOISE_FILTER_IRQ_P85_OFFSET = 0x16, /* IRQ11 */
    IOPORT_NOISE_FILTER_IRQ_P86_OFFSET = 0x1C, /* IRQ14 */
    IOPORT_NOISE_FILTER_IRQ_P87_OFFSET = 0x1E, /* IRQ15 */

    IOPORT_NOISE_FILTER_IRQ_P90_OFFSET = 0x00, /* IRQ0 */
    IOPORT_NOISE_FILTER_IRQ_P91_OFFSET = 0x02, /* IRQ1 */
    IOPORT_NOISE_FILTER_IRQ_P92_OFFSET = 0x04, /* IRQ2 */
    IOPORT_NOISE_FILTER_IRQ_P93_OFFSET = 0x06, /* IRQ3 */
    IOPORT_NOISE_FILTER_IRQ_P94_OFFSET = 0x08, /* IRQ4 */
    IOPORT_NOISE_FILTER_IRQ_P95_OFFSET = 0x0A, /* IRQ5 */
    IOPORT_NOISE_FILTER_IRQ_P96_OFFSET = 0x0C, /* IRQ6 */
    IOPORT_NOISE_FILTER_IRQ_P97_OFFSET = 0x0E, /* IRQ7 */

    IOPORT_NOISE_FILTER_IRQ_PA0_OFFSET = 0x10, /* IRQ8 */
    IOPORT_NOISE_FILTER_IRQ_PA1_OFFSET = 0x12, /* IRQ9 */
    IOPORT_NOISE_FILTER_IRQ_PA2_OFFSET = 0x14, /* IRQ10 */
    IOPORT_NOISE_FILTER_IRQ_PA3_OFFSET = 0x16, /* IRQ11 */
    IOPORT_NOISE_FILTER_IRQ_PA4_OFFSET = 0x18, /* IRQ12 */
    IOPORT_NOISE_FILTER_IRQ_PA5_OFFSET = 0x1A, /* IRQ13 */
    IOPORT_NOISE_FILTER_IRQ_PA6_OFFSET = 0x1C, /* IRQ14 */
    IOPORT_NOISE_FILTER_IRQ_PA7_OFFSET = 0x1E, /* IRQ15 */

    IOPORT_NOISE_FILTER_IRQ_PB0_OFFSET = 0x00, /* IRQ0 */
    IOPORT_NOISE_FILTER_IRQ_PB1_OFFSET = 0x02, /* IRQ1 */
    IOPORT_NOISE_FILTER_IRQ_PB2_OFFSET = 0x04, /* IRQ2 */
    IOPORT_NOISE_FILTER_IRQ_PB3_OFFSET = 0x06, /* IRQ3 */
    IOPORT_NOISE_FILTER_IRQ_PB4_OFFSET = 0x08, /* IRQ4 */
    IOPORT_NOISE_FILTER_IRQ_PB5_OFFSET = 0x0A, /* IRQ5 */
    IOPORT_NOISE_FILTER_IRQ_PB6_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PB7_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PC0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PC1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PC2_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PD0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PD1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PD2_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PD3_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PD4_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PD5_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PD6_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PD7_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PE0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PE1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PE2_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PE3_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PE4_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PE5_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PE6_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PE7_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PF0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PF1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PF2_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PG0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PG1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PG2_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PG3_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PG4_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PG5_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PG6_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PG7_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PH0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PH1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PH2_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PH3_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PH4_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PH5_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PJ0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PJ1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PJ2_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PJ3_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PJ4_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PK0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PK1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PK2_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PK3_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PL0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PL1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PL2_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PL3_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PL4_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PL5_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PL6_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PL7_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PM0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PM1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PM2_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PM3_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PM4_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PM5_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PM6_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PM7_OFFSET = 0x00,

    IOPORT_NOISE_FILTER_IRQ_PS0_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PS1_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PS2_OFFSET = 0x00,
    IOPORT_NOISE_FILTER_IRQ_PS3_OFFSET = 0x00,
} ioport_noise_filter_irq_port_offset_t;

#endif

#ifndef BSP_OVERRIDE_IOPORT_NOISE_FILTER_DREQ_PORT_OFFSET_T

/** Superset of offset for all DREQ functions.  */
typedef enum e_ioport_noise_filter_dreq_port_offset
{
    IOPORT_NOISE_FILTER_DREQ_P02_OFFSET = 0x00, /* DREQ0 */
    IOPORT_NOISE_FILTER_DREQ_P03_OFFSET = 0x00, /* DREQ0 */
    IOPORT_NOISE_FILTER_DREQ_P06_OFFSET = 0xF0,

    IOPORT_NOISE_FILTER_DREQ_P11_OFFSET = 0xF0,
    IOPORT_NOISE_FILTER_DREQ_P14_OFFSET = 0xF0,
    IOPORT_NOISE_FILTER_DREQ_P15_OFFSET = 0x00, /* DREQ0 */

    IOPORT_NOISE_FILTER_DREQ_P20_OFFSET = 0x02, /* DREQ1 */
    IOPORT_NOISE_FILTER_DREQ_P21_OFFSET = 0x04, /* DREQ2 */

    IOPORT_NOISE_FILTER_DREQ_P40_OFFSET = 0x06, /* DREQ3 */
    IOPORT_NOISE_FILTER_DREQ_P41_OFFSET = 0x08, /* DREQ4 */
    IOPORT_NOISE_FILTER_DREQ_P44_OFFSET = 0x02, /* DREQ1 */
    IOPORT_NOISE_FILTER_DREQ_P45_OFFSET = 0x04, /* DREQ2 */
    IOPORT_NOISE_FILTER_DREQ_P46_OFFSET = 0x06, /* DREQ3 */
    IOPORT_NOISE_FILTER_DREQ_P47_OFFSET = 0x08, /* DREQ4 */

    IOPORT_NOISE_FILTER_DREQ_P74_OFFSET = 0x02, /* DREQ1 */
    IOPORT_NOISE_FILTER_DREQ_P75_OFFSET = 0x04, /* DREQ2 */
    IOPORT_NOISE_FILTER_DREQ_P76_OFFSET = 0x06, /* DREQ3 */
    IOPORT_NOISE_FILTER_DREQ_P77_OFFSET = 0x08, /* DREQ4 */

    IOPORT_NOISE_FILTER_DREQ_PB2_OFFSET = 0x04, /* DREQ2 */
    IOPORT_NOISE_FILTER_DREQ_PB3_OFFSET = 0x02, /* DREQ1 */
    IOPORT_NOISE_FILTER_DREQ_PB4_OFFSET = 0x06, /* DREQ3 */
    IOPORT_NOISE_FILTER_DREQ_PB5_OFFSET = 0x08, /* DREQ4 */

    IOPORT_NOISE_FILTER_DREQ_PC1_OFFSET = 0xF0,

    IOPORT_NOISE_FILTER_DREQ_PD1_OFFSET = 0xF0,
    IOPORT_NOISE_FILTER_DREQ_PD4_OFFSET = 0xF0,
    IOPORT_NOISE_FILTER_DREQ_PD7_OFFSET = 0xF0,

    IOPORT_NOISE_FILTER_DREQ_PE2_OFFSET = 0xF0,

    IOPORT_NOISE_FILTER_DREQ_PJ3_OFFSET = 0xF0,
} ioport_noise_filter_dreq_port_offset_t;

#endif

/** Single port configuration
 *  @note Event link must be configured by the ELC
 */
typedef struct st_ioport_event_single
{
    ioport_event_control_t          event_control;  ///< Event link control for single port
    ioport_event_direction_t        direction;      ///< Event direction for single port
    uint16_t                        port_num;       ///< Port number specified to single port
    ioport_event_output_operation_t operation;      ///< Single port operation select
    ioport_event_detection_t        edge_detection; ///< Edge detection select
} ioport_event_single_t;

/** Output port group configuration
 *  @note Event link must be configured by the ELC
 */
typedef struct st_ioport_event_group_output
{
    uint8_t pin_select;                        ///< Port number specified to output port group
    ioport_event_output_operation_t operation; ///< Port group operation select
} ioport_event_group_output_t;

/** Input port group configuration
 *  @note Event link must be configured by the ELC
 */
typedef struct st_ioport_event_group_input
{
    ioport_event_control_t   event_control;     ///< Event link control for input port group
    ioport_event_detection_t edge_detection;    ///< Edge detection select
    ioport_event_control_t   overwrite_control; ///< Buffer register overwrite control
    uint8_t pin_select;                         ///< Port number specified to input port group
    uint8_t buffer_init_value;                  ///< Buffer register initial value
} ioport_event_group_input_t;

/** IOPORT extended configuration for event link function
 *  @note Event link must be configured by the ELC
 */
typedef struct  st_ioport_extend_cfg
{
    ioport_event_group_output_t const * p_port_group_output_cfg; ///< Pointer to output port group configuration
    ioport_event_group_input_t const  * p_port_group_input_cfg;  ///< Pointer to input port group configuration
    ioport_event_single_t const       * p_single_port_cfg;       ///< Pointer to single input port configuration
} ioport_extend_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const ioport_api_t g_ioport_on_ioport;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

fsp_err_t R_IOPORT_Open(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);
fsp_err_t R_IOPORT_Close(ioport_ctrl_t * const p_ctrl);
fsp_err_t R_IOPORT_PinsCfg(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);
fsp_err_t R_IOPORT_PinCfg(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, uint32_t cfg);
fsp_err_t R_IOPORT_PinEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_event);
fsp_err_t R_IOPORT_PinEventOutputWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t pin_value);
fsp_err_t R_IOPORT_PinRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_value);
fsp_err_t R_IOPORT_PinWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t level);
fsp_err_t R_IOPORT_PortDirectionSet(ioport_ctrl_t * const p_ctrl,
                                    bsp_io_port_t         port,
                                    ioport_size_t         direction_values,
                                    ioport_size_t         mask);
fsp_err_t R_IOPORT_PortEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * event_data);
fsp_err_t R_IOPORT_PortEventOutputWrite(ioport_ctrl_t * const p_ctrl,
                                        bsp_io_port_t         port,
                                        ioport_size_t         event_data,
                                        ioport_size_t         mask_value);
fsp_err_t R_IOPORT_PortRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_port_value);
fsp_err_t R_IOPORT_PortWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t value, ioport_size_t mask);

/*******************************************************************************************************************//**
 * @} (end defgroup IOPORT)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_IOPORT_H
