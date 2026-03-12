/***********************************************************************************************************************
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_gpio_rx14t.h
* Description  : Specifics for the r_gpio_rx driver for the RX14T.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version Description
*         : 30.10.2025 1.00    First Release.
***********************************************************************************************************************/
#ifndef GPIO_RX14T
#define GPIO_RX14T

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* Includes board and MCU related header files. */
#include "platform.h"
#if defined(BSP_MCU_RX14T)  /* Prevents the compiler from finding multiple definitions of constant in this file. */

/* Configuration for this package. */
#include "r_gpio_rx_config.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* General information about number of ports and pins on this device. */
#define GPIO_INFO_NUM_PORTS                 (17)

#if (BSP_PACKAGE_PINS == 64)
    #define GPIO_INFO_NUM_PINS              (60)
#elif (BSP_PACKAGE_PINS == 52)
    #define GPIO_INFO_NUM_PINS              (48)
#elif (BSP_PACKAGE_PINS == 48)
    #define GPIO_INFO_NUM_PINS              (44)
#elif (BSP_PACKAGE_PINS == 44)
    #define GPIO_INFO_NUM_PINS              (40)
#elif (BSP_PACKAGE_PINS == 32)
    #define GPIO_INFO_NUM_PINS              (28)
#elif (BSP_PACKAGE_PINS == 24)
    #define GPIO_INFO_NUM_PINS              (20)
#else
    #error "r_gpio_rx does not have information about this RX13T package. Please update r_gpio_rx14t.h"
#endif

/* Base registers used for offsets on output data registers. */
#define     GPIO_PRV_BASE_ADDR_OUTPUT           ((uint8_t volatile *)&PORT0.PODR.BYTE)
/* Base registers used for offsets on input data registers. */
#define     GPIO_PRV_BASE_ADDR_INPUT            ((uint8_t volatile *)&PORT0.PIDR.BYTE)
/* Base registers used for offsets on direction registers. */
#define     GPIO_PRV_BASE_ADDR_DIRECTION        ((uint8_t volatile *)&PORT0.PDR.BYTE)
/* Base registers used for offsets on mode registers. */
#define     GPIO_PRV_BASE_ADDR_MODE             ((uint8_t volatile *)&PORT0.PMR.BYTE)
/* Base registers used for offsets on output type registers. */
#define     GPIO_PRV_BASE_ADDR_OUT_TYPE         ((uint8_t volatile *)&PORT0.ODR0.BYTE)
/* Base registers used for offsets on pull-up registers. */
#define     GPIO_PRV_BASE_ADDR_PULL_UP          ((uint8_t volatile *)&PORT0.PCR.BYTE)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
#if (BSP_PACKAGE_PINS == 64)
/* This enumerator has each available GPIO port on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_0 = 0x0000,
    GPIO_PORT_1 = 0x0100,
    GPIO_PORT_2 = 0x0200,
    GPIO_PORT_3 = 0x0300,
    GPIO_PORT_4 = 0x0400,
    GPIO_PORT_7 = 0x0700,
    GPIO_PORT_9 = 0x0900,
    GPIO_PORT_B = 0x0B00,
    GPIO_PORT_D = 0x0D00,
    GPIO_PORT_E = 0x0E00,
    GPIO_PORT_G = 0x1000
} gpio_port_t;

/* This enumerator has a bit mask for each available GPIO pin for the given port on this MCU. */
typedef enum
{
    GPIO_PORT0_PIN_MASK = 0x1F,    /* Available pins: P00 to P04               */
    GPIO_PORT1_PIN_MASK = 0x3F,    /* Available pins: P10 to P15               */
    GPIO_PORT2_PIN_MASK = 0x7C,    /* Available pins: P22 to P26               */
    GPIO_PORT3_PIN_MASK = 0xCF,    /* Available pins: P30 to P33, P36, P37     */
    GPIO_PORT4_PIN_MASK = 0xFF,    /* Available pins: P40 to P47               */
    GPIO_PORT7_PIN_MASK = 0x7F,    /* Available pins: P70 to P76               */
    GPIO_PORT9_PIN_MASK = 0xFF,    /* Available pins: P90 to P97               */
    GPIO_PORTB_PIN_MASK = 0xFF,    /* Available pins: PB0 to PB7               */
    GPIO_PORTD_PIN_MASK = 0xF8,    /* Available pins: PD3 to PD7               */
    GPIO_PORTE_PIN_MASK = 0x04,    /* Available pins: PE2                      */
    GPIO_PORTG_PIN_MASK = 0x80     /* Available pins: PG7                      */
} gpio_pin_bit_mask_t;

/* This enumerator has each available GPIO pin on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_0_PIN_0 = 0x0000,
    GPIO_PORT_0_PIN_1 = 0x0001,
    GPIO_PORT_0_PIN_2 = 0x0002,
    GPIO_PORT_0_PIN_3 = 0x0003,
    GPIO_PORT_0_PIN_4 = 0x0004,
    GPIO_PORT_1_PIN_0 = 0x0100,
    GPIO_PORT_1_PIN_1 = 0x0101,
    GPIO_PORT_1_PIN_2 = 0x0102,
    GPIO_PORT_1_PIN_3 = 0x0103,
    GPIO_PORT_1_PIN_4 = 0x0104,
    GPIO_PORT_1_PIN_5 = 0x0105,
    GPIO_PORT_2_PIN_2 = 0x0202,
    GPIO_PORT_2_PIN_3 = 0x0203,
    GPIO_PORT_2_PIN_4 = 0x0204,
    GPIO_PORT_2_PIN_5 = 0x0205,
    GPIO_PORT_2_PIN_6 = 0x0206,
    GPIO_PORT_3_PIN_0 = 0x0300,
    GPIO_PORT_3_PIN_1 = 0x0301,
    GPIO_PORT_3_PIN_2 = 0x0302,
    GPIO_PORT_3_PIN_3 = 0x0303,
    GPIO_PORT_3_PIN_6 = 0x0306,
    GPIO_PORT_3_PIN_7 = 0x0307,
    GPIO_PORT_4_PIN_0 = 0x0400,
    GPIO_PORT_4_PIN_1 = 0x0401,
    GPIO_PORT_4_PIN_2 = 0x0402,
    GPIO_PORT_4_PIN_3 = 0x0403,
    GPIO_PORT_4_PIN_4 = 0x0404,
    GPIO_PORT_4_PIN_5 = 0x0405,
    GPIO_PORT_4_PIN_6 = 0x0406,
    GPIO_PORT_4_PIN_7 = 0x0407,
    GPIO_PORT_7_PIN_0 = 0x0700,
    GPIO_PORT_7_PIN_1 = 0x0701,
    GPIO_PORT_7_PIN_2 = 0x0702,
    GPIO_PORT_7_PIN_3 = 0x0703,
    GPIO_PORT_7_PIN_4 = 0x0704,
    GPIO_PORT_7_PIN_5 = 0x0705,
    GPIO_PORT_7_PIN_6 = 0x0706,
    GPIO_PORT_9_PIN_0 = 0x0900,
    GPIO_PORT_9_PIN_1 = 0x0901,
    GPIO_PORT_9_PIN_2 = 0x0902,
    GPIO_PORT_9_PIN_3 = 0x0903,
    GPIO_PORT_9_PIN_4 = 0x0904,
    GPIO_PORT_9_PIN_5 = 0x0905,
    GPIO_PORT_9_PIN_6 = 0x0906,
    GPIO_PORT_9_PIN_7 = 0x0907,
    GPIO_PORT_B_PIN_0 = 0x0B00,
    GPIO_PORT_B_PIN_1 = 0x0B01,
    GPIO_PORT_B_PIN_2 = 0x0B02,
    GPIO_PORT_B_PIN_3 = 0x0B03,
    GPIO_PORT_B_PIN_4 = 0x0B04,
    GPIO_PORT_B_PIN_5 = 0x0B05,
    GPIO_PORT_B_PIN_6 = 0x0B06,
    GPIO_PORT_B_PIN_7 = 0x0B07,
    GPIO_PORT_D_PIN_3 = 0x0D03,
    GPIO_PORT_D_PIN_4 = 0x0D04,
    GPIO_PORT_D_PIN_5 = 0x0D05,
    GPIO_PORT_D_PIN_6 = 0x0D06,
    GPIO_PORT_D_PIN_7 = 0x0D07,
    GPIO_PORT_E_PIN_2 = 0x0E02,
    GPIO_PORT_G_PIN_7 = 0x1007
} gpio_port_pin_t;

#elif (BSP_PACKAGE_PINS == 52)
/* This enumerator has each available GPIO port on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_0 = 0x0000,
    GPIO_PORT_1 = 0x0100,
    GPIO_PORT_2 = 0x0200,
    GPIO_PORT_3 = 0x0300,
    GPIO_PORT_4 = 0x0400,
    GPIO_PORT_7 = 0x0700,
    GPIO_PORT_9 = 0x0900,
    GPIO_PORT_B = 0x0B00,
    GPIO_PORT_D = 0x0D00,
    GPIO_PORT_E = 0x0E00,
    GPIO_PORT_G = 0x1000
} gpio_port_t;

/* This enumerator has a bit mask for each available GPIO pin for the given port on this MCU. */
typedef enum
{
    GPIO_PORT0_PIN_MASK = 0x14,    /* Available pins: P02, P04                 */
    GPIO_PORT1_PIN_MASK = 0x1B,    /* Available pins: P10, P11, P13, P14       */
    GPIO_PORT2_PIN_MASK = 0x5C,    /* Available pins: P22 to P24, P26          */
    GPIO_PORT3_PIN_MASK = 0xCA,    /* Available pins: P31, P33, P36, P37       */
    GPIO_PORT4_PIN_MASK = 0xFF,    /* Available pins: P40 to P47               */
    GPIO_PORT7_PIN_MASK = 0x7F,    /* Available pins: P70 to P76               */
    GPIO_PORT9_PIN_MASK = 0xFC,    /* Available pins: P92 to P97               */
    GPIO_PORTB_PIN_MASK = 0xFB,    /* Available pins: PB0, PB1, PB3 to PB7     */
    GPIO_PORTD_PIN_MASK = 0x78,    /* Available pins: PD3 to PD6               */
    GPIO_PORTE_PIN_MASK = 0x04,    /* Available pins: PE2                      */
    GPIO_PORTG_PIN_MASK = 0x80     /* Available pins: PG7                      */
} gpio_pin_bit_mask_t;

/* This enumerator has each available GPIO pin on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_0_PIN_2 = 0x0002,
    GPIO_PORT_0_PIN_4 = 0x0004,
    GPIO_PORT_1_PIN_0 = 0x0100,
    GPIO_PORT_1_PIN_1 = 0x0101,
    GPIO_PORT_1_PIN_3 = 0x0103,
    GPIO_PORT_1_PIN_4 = 0x0104,
    GPIO_PORT_2_PIN_2 = 0x0202,
    GPIO_PORT_2_PIN_3 = 0x0203,
    GPIO_PORT_2_PIN_4 = 0x0204,
    GPIO_PORT_2_PIN_6 = 0x0206,
    GPIO_PORT_3_PIN_1 = 0x0301,
    GPIO_PORT_3_PIN_3 = 0x0303,
    GPIO_PORT_3_PIN_6 = 0x0306,
    GPIO_PORT_3_PIN_7 = 0x0307,
    GPIO_PORT_4_PIN_0 = 0x0400,
    GPIO_PORT_4_PIN_1 = 0x0401,
    GPIO_PORT_4_PIN_2 = 0x0402,
    GPIO_PORT_4_PIN_3 = 0x0403,
    GPIO_PORT_4_PIN_4 = 0x0404,
    GPIO_PORT_4_PIN_5 = 0x0405,
    GPIO_PORT_4_PIN_6 = 0x0406,
    GPIO_PORT_4_PIN_7 = 0x0407,
    GPIO_PORT_7_PIN_0 = 0x0700,
    GPIO_PORT_7_PIN_1 = 0x0701,
    GPIO_PORT_7_PIN_2 = 0x0702,
    GPIO_PORT_7_PIN_3 = 0x0703,
    GPIO_PORT_7_PIN_4 = 0x0704,
    GPIO_PORT_7_PIN_5 = 0x0705,
    GPIO_PORT_7_PIN_6 = 0x0706,
    GPIO_PORT_9_PIN_2 = 0x0902,
    GPIO_PORT_9_PIN_3 = 0x0903,
    GPIO_PORT_9_PIN_4 = 0x0904,
    GPIO_PORT_9_PIN_5 = 0x0905,
    GPIO_PORT_9_PIN_6 = 0x0906,
    GPIO_PORT_9_PIN_7 = 0x0907,
    GPIO_PORT_B_PIN_0 = 0x0B00,
    GPIO_PORT_B_PIN_1 = 0x0B01,
    GPIO_PORT_B_PIN_3 = 0x0B03,
    GPIO_PORT_B_PIN_4 = 0x0B04,
    GPIO_PORT_B_PIN_5 = 0x0B05,
    GPIO_PORT_B_PIN_6 = 0x0B06,
    GPIO_PORT_B_PIN_7 = 0x0B07,
    GPIO_PORT_D_PIN_3 = 0x0D03,
    GPIO_PORT_D_PIN_4 = 0x0D04,
    GPIO_PORT_D_PIN_5 = 0x0D05,
    GPIO_PORT_D_PIN_6 = 0x0D06,
    GPIO_PORT_E_PIN_2 = 0x0E02,
    GPIO_PORT_G_PIN_7 = 0x1007
} gpio_port_pin_t;

#elif (BSP_PACKAGE_PINS == 48)
/* This enumerator has each available GPIO port on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_1 = 0x0100,
    GPIO_PORT_2 = 0x0200,
    GPIO_PORT_3 = 0x0300,
    GPIO_PORT_4 = 0x0400,
    GPIO_PORT_7 = 0x0700,
    GPIO_PORT_9 = 0x0900,
    GPIO_PORT_B = 0x0B00,
    GPIO_PORT_D = 0x0D00,
    GPIO_PORT_E = 0x0E00,
    GPIO_PORT_G = 0x1000
} gpio_port_t;

/* This enumerator has a bit mask for each available GPIO pin for the given port on this MCU. */
typedef enum
{
    GPIO_PORT1_PIN_MASK = 0x1B,    /* Available pins: P10, P11, P13, P14       */
    GPIO_PORT2_PIN_MASK = 0x5C,    /* Available pins: P22 to P24, P26          */
    GPIO_PORT3_PIN_MASK = 0xC2,    /* Available pins: P31, P36, P37            */
    GPIO_PORT4_PIN_MASK = 0xFF,    /* Available pins: P40 to P47               */
    GPIO_PORT7_PIN_MASK = 0x7F,    /* Available pins: P70 to P76               */
    GPIO_PORT9_PIN_MASK = 0xFC,    /* Available pins: P92 to P97               */
    GPIO_PORTB_PIN_MASK = 0x7B,    /* Available pins: PB0, PB1, PB3 to PB6     */
    GPIO_PORTD_PIN_MASK = 0x78,    /* Available pins: PD3 to PD6               */
    GPIO_PORTE_PIN_MASK = 0x04,    /* Available pins: PE2                      */
    GPIO_PORTG_PIN_MASK = 0x80     /* Available pins: PG7                      */
} gpio_pin_bit_mask_t;

/* This enumerator has each available GPIO pin on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{ 
    GPIO_PORT_1_PIN_0 = 0x0100,
    GPIO_PORT_1_PIN_1 = 0x0101,
    GPIO_PORT_1_PIN_3 = 0x0103,
    GPIO_PORT_1_PIN_4 = 0x0104,
    GPIO_PORT_2_PIN_2 = 0x0202,
    GPIO_PORT_2_PIN_3 = 0x0203,
    GPIO_PORT_2_PIN_4 = 0x0204,
    GPIO_PORT_2_PIN_6 = 0x0206,
    GPIO_PORT_3_PIN_1 = 0x0301,
    GPIO_PORT_3_PIN_6 = 0x0306,
    GPIO_PORT_3_PIN_7 = 0x0307,
    GPIO_PORT_4_PIN_0 = 0x0400,
    GPIO_PORT_4_PIN_1 = 0x0401,
    GPIO_PORT_4_PIN_2 = 0x0402,
    GPIO_PORT_4_PIN_3 = 0x0403,
    GPIO_PORT_4_PIN_4 = 0x0404,
    GPIO_PORT_4_PIN_5 = 0x0405,
    GPIO_PORT_4_PIN_6 = 0x0406,
    GPIO_PORT_4_PIN_7 = 0x0407,
    GPIO_PORT_7_PIN_0 = 0x0700,
    GPIO_PORT_7_PIN_1 = 0x0701,
    GPIO_PORT_7_PIN_2 = 0x0702,
    GPIO_PORT_7_PIN_3 = 0x0703,
    GPIO_PORT_7_PIN_4 = 0x0704,
    GPIO_PORT_7_PIN_5 = 0x0705,
    GPIO_PORT_7_PIN_6 = 0x0706,
    GPIO_PORT_9_PIN_2 = 0x0902,
    GPIO_PORT_9_PIN_3 = 0x0903,
    GPIO_PORT_9_PIN_4 = 0x0904,
    GPIO_PORT_9_PIN_5 = 0x0905,
    GPIO_PORT_9_PIN_6 = 0x0906,
    GPIO_PORT_9_PIN_7 = 0x0907,
    GPIO_PORT_B_PIN_0 = 0x0B00,
    GPIO_PORT_B_PIN_1 = 0x0B01,
    GPIO_PORT_B_PIN_3 = 0x0B03,
    GPIO_PORT_B_PIN_4 = 0x0B04,
    GPIO_PORT_B_PIN_5 = 0x0B05,
    GPIO_PORT_B_PIN_6 = 0x0B06,
    GPIO_PORT_D_PIN_3 = 0x0D03,
    GPIO_PORT_D_PIN_4 = 0x0D04,
    GPIO_PORT_D_PIN_5 = 0x0D05,
    GPIO_PORT_D_PIN_6 = 0x0D06,
    GPIO_PORT_E_PIN_2 = 0x0E02,
    GPIO_PORT_G_PIN_7 = 0x1007
} gpio_port_pin_t;

#elif (BSP_PACKAGE_PINS == 44)
/* This enumerator has each available GPIO port on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_1 = 0x0100,
    GPIO_PORT_2 = 0x0200,
    GPIO_PORT_3 = 0x0300,
    GPIO_PORT_4 = 0x0400,
    GPIO_PORT_7 = 0x0700,
    GPIO_PORT_9 = 0x0900,
    GPIO_PORT_B = 0x0B00,
    GPIO_PORT_D = 0x0D00,
    GPIO_PORT_E = 0x0E00,
    GPIO_PORT_G = 0x1000
} gpio_port_t;

/* This enumerator has a bit mask for each available GPIO pin for the given port on this MCU. */
typedef enum
{
    GPIO_PORT1_PIN_MASK = 0x1B,    /* Available pins: P10, P11, P13, P14       */
    GPIO_PORT2_PIN_MASK = 0x5C,    /* Available pins: P22 to P24, P26          */
    GPIO_PORT3_PIN_MASK = 0x42,    /* Available pins: P31, P36                 */
    GPIO_PORT4_PIN_MASK = 0xDF,    /* Available pins: P40 to P44, P46, P47     */
    GPIO_PORT7_PIN_MASK = 0x7E,    /* Available pins: P71 to P76               */
    GPIO_PORT9_PIN_MASK = 0xFC,    /* Available pins: P92 to P97               */
    GPIO_PORTB_PIN_MASK = 0x6B,    /* Available pins: PB0, PB1, PB3, PB5, PB6  */
    GPIO_PORTD_PIN_MASK = 0x78,    /* Available pins: PD3 to PD6               */
    GPIO_PORTE_PIN_MASK = 0x04,    /* Available pins: PE2                      */
    GPIO_PORTG_PIN_MASK = 0x80     /* Available pins: PG7                      */
} gpio_pin_bit_mask_t;

/* This enumerator has each available GPIO pin on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_1_PIN_0 = 0x0100,
    GPIO_PORT_1_PIN_1 = 0x0101,
    GPIO_PORT_1_PIN_3 = 0x0103,
    GPIO_PORT_1_PIN_4 = 0x0104,
    GPIO_PORT_2_PIN_2 = 0x0202,
    GPIO_PORT_2_PIN_3 = 0x0203,
    GPIO_PORT_2_PIN_4 = 0x0204,
    GPIO_PORT_2_PIN_6 = 0x0206,
    GPIO_PORT_3_PIN_1 = 0x0301,
    GPIO_PORT_3_PIN_6 = 0x0306,
    GPIO_PORT_4_PIN_0 = 0x0400,
    GPIO_PORT_4_PIN_1 = 0x0401,
    GPIO_PORT_4_PIN_2 = 0x0402,
    GPIO_PORT_4_PIN_3 = 0x0403,
    GPIO_PORT_4_PIN_4 = 0x0404,
    GPIO_PORT_4_PIN_6 = 0x0406,
    GPIO_PORT_4_PIN_7 = 0x0407,
    GPIO_PORT_7_PIN_1 = 0x0701,
    GPIO_PORT_7_PIN_2 = 0x0702,
    GPIO_PORT_7_PIN_3 = 0x0703,
    GPIO_PORT_7_PIN_4 = 0x0704,
    GPIO_PORT_7_PIN_5 = 0x0705,
    GPIO_PORT_7_PIN_6 = 0x0706,
    GPIO_PORT_9_PIN_2 = 0x0902,
    GPIO_PORT_9_PIN_3 = 0x0903,
    GPIO_PORT_9_PIN_4 = 0x0904,
    GPIO_PORT_9_PIN_5 = 0x0905,
    GPIO_PORT_9_PIN_6 = 0x0906,
    GPIO_PORT_9_PIN_7 = 0x0907,
    GPIO_PORT_B_PIN_0 = 0x0B00,
    GPIO_PORT_B_PIN_1 = 0x0B01,
    GPIO_PORT_B_PIN_3 = 0x0B03,
    GPIO_PORT_B_PIN_5 = 0x0B05,
    GPIO_PORT_B_PIN_6 = 0x0B06,
    GPIO_PORT_D_PIN_3 = 0x0D03,
    GPIO_PORT_D_PIN_4 = 0x0D04,
    GPIO_PORT_D_PIN_5 = 0x0D05,
    GPIO_PORT_D_PIN_6 = 0x0D06,
    GPIO_PORT_E_PIN_2 = 0x0E02,
    GPIO_PORT_G_PIN_7 = 0x1007
} gpio_port_pin_t;

#elif (BSP_PACKAGE_PINS == 32)
/* This enumerator has each available GPIO port on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_1 = 0x0100,
    GPIO_PORT_2 = 0x0200,
    GPIO_PORT_3 = 0x0300,
    GPIO_PORT_4 = 0x0400,
    GPIO_PORT_7 = 0x0700,
    GPIO_PORT_9 = 0x0900,
    GPIO_PORT_B = 0x0B00,
    GPIO_PORT_E = 0x0E00,
    GPIO_PORT_G = 0x1000
} gpio_port_t;

/* This enumerator has a bit mask for each available GPIO pin for the given port on this MCU. */
typedef enum
{
    GPIO_PORT1_PIN_MASK = 0x1A,    /* Available pins: P11, P13, P14            */
    GPIO_PORT2_PIN_MASK = 0x40,    /* Available pins: P26                      */
    GPIO_PORT3_PIN_MASK = 0xC2,    /* Available pins: P31, P36, P37            */
    GPIO_PORT4_PIN_MASK = 0x57,    /* Available pins: P40 to P42, P44, P46     */
    GPIO_PORT7_PIN_MASK = 0x7E,    /* Available pins: P71 to P76               */
    GPIO_PORT9_PIN_MASK = 0xCC,    /* Available pins: P92, P93, P96, P97       */
    GPIO_PORTB_PIN_MASK = 0x63,    /* Available pins: PB0, PB1, PB5, PB6       */
    GPIO_PORTE_PIN_MASK = 0x04,    /* Available pins: PE2                      */
    GPIO_PORTG_PIN_MASK = 0x80     /* Available pins: PG7                      */
} gpio_pin_bit_mask_t;

/* This enumerator has each available GPIO pin on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_1_PIN_1 = 0x0101,
    GPIO_PORT_1_PIN_3 = 0x0103,
    GPIO_PORT_1_PIN_4 = 0x0104,
    GPIO_PORT_2_PIN_6 = 0x0206,
    GPIO_PORT_3_PIN_1 = 0x0301,
    GPIO_PORT_3_PIN_6 = 0x0306,
    GPIO_PORT_3_PIN_7 = 0x0307,
    GPIO_PORT_4_PIN_0 = 0x0400,
    GPIO_PORT_4_PIN_1 = 0x0401,
    GPIO_PORT_4_PIN_2 = 0x0402,
    GPIO_PORT_4_PIN_4 = 0x0404,
    GPIO_PORT_4_PIN_6 = 0x0406,
    GPIO_PORT_7_PIN_1 = 0x0701,
    GPIO_PORT_7_PIN_2 = 0x0702,
    GPIO_PORT_7_PIN_3 = 0x0703,
    GPIO_PORT_7_PIN_4 = 0x0704,
    GPIO_PORT_7_PIN_5 = 0x0705,
    GPIO_PORT_7_PIN_6 = 0x0706,
    GPIO_PORT_9_PIN_2 = 0x0902,
    GPIO_PORT_9_PIN_3 = 0x0903,
    GPIO_PORT_9_PIN_6 = 0x0906,
    GPIO_PORT_9_PIN_7 = 0x0907,
    GPIO_PORT_B_PIN_0 = 0x0B00,
    GPIO_PORT_B_PIN_1 = 0x0B01,
    GPIO_PORT_B_PIN_5 = 0x0B05,
    GPIO_PORT_B_PIN_6 = 0x0B06,
    GPIO_PORT_E_PIN_2 = 0x0E02,
    GPIO_PORT_G_PIN_7 = 0x1007
} gpio_port_pin_t;

#elif (BSP_PACKAGE_PINS == 24)
/* This enumerator has each available GPIO port on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_1 = 0x0100,
    GPIO_PORT_2 = 0x0200,
    GPIO_PORT_3 = 0x0300,
    GPIO_PORT_4 = 0x0400,
    GPIO_PORT_7 = 0x0700,
    GPIO_PORT_9 = 0x0900,
    GPIO_PORT_B = 0x0B00,
    GPIO_PORT_E = 0x0E00,
    GPIO_PORT_G = 0x1000
} gpio_port_t;

/* This enumerator has a bit mask for each available GPIO pin for the given port on this MCU. */
typedef enum
{
    GPIO_PORT1_PIN_MASK = 0x1A,    /* Available pins: P11, P13, P14            */
    GPIO_PORT2_PIN_MASK = 0x40,    /* Available pins: P26                      */
    GPIO_PORT3_PIN_MASK = 0x42,    /* Available pins: P31, P36                 */
    GPIO_PORT4_PIN_MASK = 0x07,    /* Available pins: P40 to P42               */
    GPIO_PORT7_PIN_MASK = 0x78,    /* Available pins: P73 to P76               */
    GPIO_PORT9_PIN_MASK = 0xC0,    /* Available pins: P96, P97                 */
    GPIO_PORTB_PIN_MASK = 0x61,    /* Available pins: PB0, PB5, PB6            */
    GPIO_PORTE_PIN_MASK = 0x04,    /* Available pins: PE2                      */
    GPIO_PORTG_PIN_MASK = 0x80     /* Available pins: PG7                      */
} gpio_pin_bit_mask_t;

/* This enumerator has each available GPIO pin on this MCU. This list will change depending on the MCU chosen. */
typedef enum
{
    GPIO_PORT_1_PIN_1 = 0x0101,
    GPIO_PORT_1_PIN_3 = 0x0103,
    GPIO_PORT_1_PIN_4 = 0x0104,
    GPIO_PORT_2_PIN_6 = 0x0206,
    GPIO_PORT_3_PIN_1 = 0x0301,
    GPIO_PORT_3_PIN_6 = 0x0306,
    GPIO_PORT_4_PIN_0 = 0x0400,
    GPIO_PORT_4_PIN_1 = 0x0401,
    GPIO_PORT_4_PIN_2 = 0x0402,
    GPIO_PORT_7_PIN_3 = 0x0703,
    GPIO_PORT_7_PIN_4 = 0x0704,
    GPIO_PORT_7_PIN_5 = 0x0705,
    GPIO_PORT_7_PIN_6 = 0x0706,
    GPIO_PORT_9_PIN_6 = 0x0906,
    GPIO_PORT_9_PIN_7 = 0x0907,
    GPIO_PORT_B_PIN_0 = 0x0B00,
    GPIO_PORT_B_PIN_5 = 0x0B05,
    GPIO_PORT_B_PIN_6 = 0x0B06,
    GPIO_PORT_E_PIN_2 = 0x0E02,
    GPIO_PORT_G_PIN_7 = 0x1007
} gpio_port_pin_t;
#endif

/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/

#endif /* BSP_MCU_RX14T */
#endif /* GPIO_RX14T */
