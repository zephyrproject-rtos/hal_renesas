/*
 * Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_USB_HOST_API_H
#define R_USB_HOST_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Includes board and MCU related header files. */
#include "bsp_api.h"
#include "r_usb_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum e_usbh_event_id
{
    USBH_EVENT_DEVICE_ATTACH = 0,
    USBH_EVENT_DEVICE_REMOVE,
    USBH_EVENT_XFER_COMPLETE
} usbh_event_id_t;

typedef struct st_usbh_device_attach
{
    uint8_t hub_addr;
    uint8_t hub_port;
    uint8_t speed;
} usbh_device_attach_t;

typedef struct st_usbh_device_remove
{
    uint8_t hub_addr;
    uint8_t hub_port;
    uint8_t speed;
} usbh_device_remove_t;

typedef struct st_usbh_xfer_complete
{
    uint8_t  ep_addr;
    uint8_t  result;
    uint32_t len;
} usbh_xfer_complete_t;

typedef struct st_usbh_event
{
    usbh_event_id_t event_id;
    uint8_t         dev_addr;
    union
    {
        usbh_device_attach_t attach;
        usbh_device_remove_t remove;
        usbh_xfer_complete_t complete;
    };
} usbh_event_t;

typedef uint32_t usb_status_t;

typedef struct st_usbh_callback_arg
{
    uint32_t     module_number;
    usbh_event_t event;
    void const * p_context;
} usbh_callback_arg_t;

typedef struct st_usb_cfg
{
    /* USB generic configuration */
    uint32_t  module_number;
    IRQn_Type irq;
    IRQn_Type irq_r;
    IRQn_Type irq_d0;
    IRQn_Type irq_d1;
    IRQn_Type hs_irq;
    IRQn_Type hsirq_d0;
    IRQn_Type hsirq_d1;
    uint8_t   ipl;
    uint8_t   ipl_r;
    uint8_t   ipl_d0;
    uint8_t   ipl_d1;
    uint8_t   hsipl;
    uint8_t   hsipl_d0;
    uint8_t   hsipl_d1;

    /* Configuration for USB Event processing */
    void (* p_callback)(usbh_callback_arg_t * p_args);
    void const * p_context;
    bool         high_speed;
} usb_cfg_t;

typedef void usb_ctrl_t;

FSP_FOOTER

#endif /* R_USB_HOST_API_H */
