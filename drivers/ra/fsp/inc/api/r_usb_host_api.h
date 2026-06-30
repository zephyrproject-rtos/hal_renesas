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

/** Events that the USB host driver reports to the application through the user callback. */
typedef enum e_usbh_event_id
{
    USBH_EVENT_DEVICE_ATTACH = 0,      ///< A device has been attached to the bus.
    USBH_EVENT_DEVICE_REMOVE,          ///< A device has been detached from the bus.
    USBH_EVENT_XFER_COMPLETE           ///< A data/control transfer has finished (see @ref usbh_xfer_complete_t).
} usbh_event_id_t;

/** Payload reported with a ::USBH_EVENT_DEVICE_ATTACH event. */
typedef struct st_usbh_device_attach
{
    uint8_t hub_addr;                  ///< Address of the upstream hub, or 0 when attached to the root port.
    uint8_t hub_port;                  ///< Hub port the device is attached to (1-based), or 0 for the root port.
    uint8_t speed;                     ///< Detected speed of the attached device (see ::usb_speed_t).
} usbh_device_attach_t;

/** Payload reported with a ::USBH_EVENT_DEVICE_REMOVE event. */
typedef struct st_usbh_device_remove
{
    uint8_t hub_addr;                  ///< Address of the upstream hub, or 0 when attached to the root port.
    uint8_t hub_port;                  ///< Hub port the device was attached to (1-based), or 0 for the root port.
    uint8_t speed;                     ///< Speed of the removed device (see ::usb_speed_t).
} usbh_device_remove_t;

/** Payload reported with a ::USBH_EVENT_XFER_COMPLETE event. */
typedef struct st_usbh_xfer_complete
{
    uint8_t  ep_addr;                  ///< Endpoint address (bit 7 = direction) the transfer ran on.
    uint8_t  result;                   ///< Transfer result code (see ::usb_xfer_result_t).
    uint32_t len;                      ///< Number of bytes actually transferred.
} usbh_xfer_complete_t;

/** USB host event passed to the user callback. The active union member is selected by @ref event_id. */
typedef struct st_usbh_event
{
    usbh_event_id_t event_id;          ///< Identifies which event occurred and which union member is valid.
    uint8_t         dev_addr;          ///< Device address associated with the event.
    union
    {
        usbh_device_attach_t attach;   ///< Valid when @ref event_id == ::USBH_EVENT_DEVICE_ATTACH.
        usbh_device_remove_t remove;   ///< Valid when @ref event_id == ::USBH_EVENT_DEVICE_REMOVE.
        usbh_xfer_complete_t complete; ///< Valid when @ref event_id == ::USBH_EVENT_XFER_COMPLETE.
    };
} usbh_event_t;

/** Bit-field of port status flags returned by R_USBH_PortStatusGet(). */
typedef uint32_t usb_status_t;

/** Argument passed to the user callback registered in @ref usb_cfg_t::p_callback. */
typedef struct st_usbh_callback_arg
{
    uint32_t     module_number;        ///< USB IP/module number that generated the event.
    usbh_event_t event;                ///< Event that occurred.
    void const * p_context;            ///< User context pointer supplied in @ref usb_cfg_t::p_context.
} usbh_callback_arg_t;

/** USB host configuration. Passed to R_USBH_Open() and retained for the lifetime of the instance. */
typedef struct st_usb_cfg
{
    /* USB generic configuration */
    uint32_t  module_number;                           ///< USB IP/module number to open (0: USBFS, 1: USBHS when present).
    IRQn_Type irq;                                     ///< USBFS interrupt number (USBI0).
    IRQn_Type irq_r;                                   ///< USBFS resume interrupt number (USBR0).
    IRQn_Type irq_d0;                                  ///< USBFS DMA/DTC channel 0 interrupt number.
    IRQn_Type irq_d1;                                  ///< USBFS DMA/DTC channel 1 interrupt number.
    IRQn_Type hs_irq;                                  ///< USBHS interrupt number.
    IRQn_Type hsirq_d0;                                ///< USBHS DMA/DTC channel 0 interrupt number.
    IRQn_Type hsirq_d1;                                ///< USBHS DMA/DTC channel 1 interrupt number.
    uint8_t   ipl;                                     ///< USBFS interrupt priority level.
    uint8_t   ipl_r;                                   ///< USBFS resume interrupt priority level.
    uint8_t   ipl_d0;                                  ///< USBFS DMA/DTC channel 0 interrupt priority level.
    uint8_t   ipl_d1;                                  ///< USBFS DMA/DTC channel 1 interrupt priority level.
    uint8_t   hsipl;                                   ///< USBHS interrupt priority level.
    uint8_t   hsipl_d0;                                ///< USBHS DMA/DTC channel 0 interrupt priority level.
    uint8_t   hsipl_d1;                                ///< USBHS DMA/DTC channel 1 interrupt priority level.

    /* Configuration for USB Event processing */
    void (* p_callback)(usbh_callback_arg_t * p_args); ///< Callback invoked from interrupt context on USB events.
    void const * p_context;                            ///< User context pointer forwarded to @ref p_callback.
    bool         high_speed;                           ///< Enable High-Speed operation (USBHS module only).
} usb_cfg_t;

/** USB host control block. Opaque to the application; declare one per instance and pass to every API call. */
typedef void usb_ctrl_t;

FSP_FOOTER

#endif /* R_USB_HOST_API_H */
