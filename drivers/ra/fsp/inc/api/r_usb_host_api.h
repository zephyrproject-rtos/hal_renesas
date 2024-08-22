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
#include "r_usb_host_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Descriptor type  Define */
#define USB_DT_DEVICE              (0x01U) /* Device Descriptor */
#define USB_DT_CONFIGURATION       (0x02U) /* Configuration Descriptor */
#define USB_DT_STRING              (0x03U) /* String Descriptor */
#define USB_DT_INTERFACE           (0x04U) /* Interface Descriptor */
#define USB_DT_ENDPOINT            (0x05U) /* Endpoint Descriptor */
#define USB_DT_DEVICE_QUALIFIER    (0x06U) /* Device Qualifier Descriptor */
#define USB_DT_OTHER_SPEED_CONF    (0x07U) /* Other Speed Configuration Descriptor */
#define USB_DT_INTERFACE_POWER     (0x08U) /* Interface Power Descriptor */
#define USB_DT_OTGDESCRIPTOR       (0x09U) /* OTG Descriptor */
#define USB_DT_HUBDESCRIPTOR       (0x29U) /* HUB descriptor */

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum e_usb_eventid
{
    USB_EVENT_DEVICE_ATTACH,
    USB_EVENT_DEVICE_REMOVE,
    USB_EVENT_XFER_COMPLETE
} usb_eventid_t;

typedef enum e_usb_request_recipient
{
    USB_REQ_RCPT_DEVICE = 0,
    USB_REQ_RCPT_INTERFACE,
    USB_REQ_RCPT_ENDPOINT,
    USB_REQ_RCPT_OTHER
} usb_request_recipient_t;

typedef enum e_usb_request_type
{
    USB_REQ_TYPE_STANDARD = 0,
    USB_REQ_TYPE_CLASS,
    USB_REQ_TYPE_VENDOR,
    USB_REQ_TYPE_INVALID
} usb_request_type_t;

typedef uint32_t usb_status_t;

/** USB Endpoint Descriptor */
typedef __PACKED_STRUCT st_usb_desc_endpoint
{
    uint8_t bLength;                   /*  Size of this descriptor in bytes */
    uint8_t bDescriptorType;           /*  ENDPOINT Descriptor Type */
    uint8_t bEndpointAddress;          /*  The address of the endpoint */

    __PACKED_STRUCT
    {
        uint8_t xfer  : 2;             /*  Control, ISO, Bulk, Interrupt */
        uint8_t sync  : 2;             /*  None, Asynchronous, Adaptive, Synchronous */
        uint8_t usage : 2;             /*  Data, Feedback, Implicit feedback */
        uint8_t       : 2;
    } bmAttributes;

    uint16_t wMaxPacketSize;           /*  Bit 10..0 : max packet size, bit 12..11 additional transaction per highspeed micro-frame */
    uint8_t  bInterval;                /*  Polling interval, in frames or microframes depending on the operating speed */
} usb_desc_endpoint_t;

/** USB speed */
typedef enum e_usb_speed
{
    USB_SPEED_LS = 0,                  /* Low speed operation */
    USB_SPEED_FS,                      /* Full speed operation */
    USB_SPEED_HS,                      /* Hi speed operation */
    USB_SPEED_INVALID,
} usb_speed_t;

typedef enum e_usb_xfer_result
{
    USB_XFER_RESULT_SUCCESS = 0,
    USB_XFER_RESULT_FAILED,
    USB_XFER_RESULT_STALLED,
    USB_XFER_RESULT_TIMEOUT,
    USB_XFER_RESULT_INVALID
} usb_xfer_result_t;

typedef enum e_usb_xfer_type
{
    USB_XFER_CONTROL = 0,
    USB_XFER_ISOCHRONOUS,
    USB_XFER_BULK,
    USB_XFER_INTERRUPT
} usb_xfer_type_t;

typedef enum e_usb_dir
{
    USB_DIR_OUT     = 0,
    USB_DIR_IN      = 1,
    USB_DIR_IN_MASK = 0x80
} usb_dir_t;

typedef struct st_usb_event
{
    uint8_t event_id;
    uint8_t dev_addr;

    union
    {
        /*  Attach, Remove */
        struct
        {
            uint8_t hub_addr;
            uint8_t hub_port;
            uint8_t speed;
        };

        /*  XFER_COMPLETE */
        struct
        {
            uint8_t  ep_addr;
            uint8_t  result;
            uint32_t len;
        };
    };
} usb_event_t;

typedef struct st_usb_callback_arg
{
    uint32_t     module_number;        /* Device channel number */
    usb_event_t  event;                /* Event code */
    void const * p_context;            /* Context provided to user during callback */
} usb_callback_arg_t;

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
    void (* p_callback)(usb_callback_arg_t * p_args);
    void const * p_context;
    bool         high_speed;
} usb_cfg_t;

typedef void usb_ctrl_t;

FSP_FOOTER

#endif /* R_USB_HOST_API_H */
