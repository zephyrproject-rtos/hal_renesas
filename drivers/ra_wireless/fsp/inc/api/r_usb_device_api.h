/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_USB_DEVICE_API_H
#define R_USB_DEVICE_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Includes board and MCU related header files. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** USB setup packet */
typedef __PACKED_STRUCT st_usbd_setup
{
    uint16_t request_type;
    uint16_t request_value;
    uint16_t request_index;
    uint16_t request_length;
} usbd_setup_t;

/** USB Endpoint Descriptor */
typedef __PACKED_STRUCT st_usbd_desc_endpoint
{
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    union
    {
        uint8_t bmAttributes;
        struct
        {
            uint8_t xfer  : 2;
            uint8_t sync  : 2;
            uint8_t usage : 2;
            uint8_t       : 2;
        } Attributes;
    };

    uint16_t wMaxPacketSize;
    uint8_t bInterval;
} usbd_desc_endpoint_t;

/** USB speed */
typedef enum e_usbd_speed
{
    USBD_SPEED_LS = 0,
    USBD_SPEED_FS,
    USBD_SPEED_HS,
    USBD_SPEED_INVALID,
} usbd_speed_t;

/** USB event code */
typedef enum e_usbd_event_id
{
    USBD_EVENT_ID_INVALID = 0,
    USBD_EVENT_ID_BUS_RESET,
    USBD_EVENT_ID_VBUS_RDY,
    USBD_EVENT_ID_VBUS_REMOVED,
    USBD_EVENT_ID_SOF,
    USBD_EVENT_ID_SUSPEND,
    USBD_EVENT_ID_RESUME,
    USBD_EVENT_ID_SETUP_RECEIVED,
    USBD_EVENT_ID_XFER_COMPLETE,
} usbd_event_id_t;

/** USB transfer result code */
typedef enum e_usbd_xfer_result
{
    USBD_XFER_RESULT_SUCCESS = 0,
    USBD_XFER_RESULT_FAILED,
    USBD_XFER_RESULT_STALLED,
    USBD_XFER_RESULT_TIMEOUT,
    USBD_XFER_RESULT_INVALID
} usbd_xfer_result_t;

/** USB bus reset event input argument */
typedef struct st_usbd_bus_reset_evt
{
    usbd_speed_t speed;
} usbd_bus_reset_evt_t;

/** USB SOF detection event input argument */
typedef struct st_usbd_sof_evt
{
    uint32_t frame_count;
} usbd_sof_evt_t;

/** USB transfer complete event input argument */
typedef struct st_usbd_xfer_complete
{
    usbd_xfer_result_t result;
    uint8_t            ep_addr;
    uint32_t           len;
} usbd_xfer_complete_t;

typedef struct st_usbd_event
{
    usbd_event_id_t event_id;
    union
    {
        usbd_bus_reset_evt_t bus_reset;
        usbd_sof_evt_t       sof;
        usbd_setup_t         setup_received;
        usbd_xfer_complete_t xfer_complete;
    };
} usbd_event_t;

typedef struct st_usbd_callback_args
{
    uint32_t     module_number;
    usbd_event_t event;
    void const * p_context;
} usbd_callback_args_t;

/** USB configuration */
typedef struct st_usbd_cfg
{
    uint32_t     module_number;
    usbd_speed_t usb_speed;
    IRQn_Type    irq;
    IRQn_Type    irq_r;
    IRQn_Type    irq_d0;
    IRQn_Type    irq_d1;
    IRQn_Type    hs_irq;
    IRQn_Type    hsirq_d0;
    IRQn_Type    hsirq_d1;
    uint8_t      ipl;
    uint8_t      ipl_r;
    uint8_t      ipl_d0;
    uint8_t      ipl_d1;
    uint8_t      hsipl;
    uint8_t      hsipl_d0;
    uint8_t      hsipl_d1;
    void (* p_callback)(usbd_callback_args_t * p_args);
    void const * p_context;
    void const * p_extend;
} usbd_cfg_t;

typedef void usbd_ctrl_t;

/** Shared Interface definition for USB Device */
typedef struct st_usb_api
{
    /**
     * @brief Start USB module, configure operate mode and control endpoint
     *
     * @param[in] p_api_ctrl
     * @param[in] p_cfg
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* open)(usbd_ctrl_t * const p_api_ctrl, usbd_cfg_t const * const p_cfg);

    /**
     * @brief Stop USB module and release resources
     *
     * @param[in] p_ctrl
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* close)(usbd_ctrl_t * const p_ctrl);

    /**
     * @brief Set address, called in response to SET_ADDRESS request
     *
     * @param[in] p_api_ctrl
     * @param[in] addr
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* setAddress)(usbd_ctrl_t * const p_api_ctrl, uint8_t addr);

    /**
     * @brief Connect USB D+/D- pin to the USB data bus
     *
     * @param[in] p_api_ctrl
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* connect)(usbd_ctrl_t * const p_api_ctrl);

    /**
     * @brief Disconnect pin D+/D- to USB data bus
     *
     * @param[in] p_api_ctrl
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* disconnect)(usbd_ctrl_t * const p_api_ctrl);

    /**
     * @brief Configure an endpoint to make it ready to transfer
     *
     * @param[in] p_api_ctrl
     * @param[in] p_ep_desc
     *
     * @retval FSP_SUCCESS          on success
     * @retval FSP_ERR_USB_BUSY     if these is no available pipe can be used with this endpoint
     */
    fsp_err_t (* edptOpen)(usbd_ctrl_t * const p_api_ctrl, usbd_desc_endpoint_t const * p_ep_desc);

    /**
     * @brief Remove configuration for an endpoint
     *
     * @param[in] p_api_ctrl
     * @param[in] ep_addr
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* edptClose)(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr);

    /**
     * @brief Set a endpoint to halt and send a stall packet
     *
     * @param[in] p_api_ctrl
     * @param[in] ep_addr
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* edptStall)(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr);

    /**
     * @brief Reset halt state of an endpoint
     *
     * @param[in] p_api_ctrl
     * @param[in] ep_addr
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* edptClearStall)(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr);

    /**
     * @brief Trigger an endpoint transfer
     *
     * @param[in] p_api_ctrl
     * @param[in] ep_addr
     * @param[in] buffer
     * @param[in] total_bytes
     *
     * @retval FSP_SUCCESS              on success
     * @retval FSP_ERR_USB_NOT_OPEN     if input endpoint has not opened yet
     */
    fsp_err_t (* xferStart)(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr, uint8_t * buffer, uint16_t total_bytes);

    /**
     * @brief Abort on-going transfer
     *
     * @param[in] p_api_ctrl
     * @param[in] ep_addr
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* xferAbort)(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr);

    /**
     * @brief Wake up host
     *
     * @param[in] p_api_ctrl
     *
     * @retval FSP_SUCCESS on success
     */
    fsp_err_t (* remoteWakeup)(usbd_ctrl_t * const p_api_ctrl);
} usbd_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_usbd_instance
{
    usbd_ctrl_t      * p_ctrl;         ///< Pointer to the control structure for this instance
    usbd_cfg_t const * p_cfg;          ///< Pointer to the configuration structure for this instance
    usbd_api_t const * p_api;          ///< Pointer to the API structure for this instance
} usbd_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif /* R_USB_DEVICE_API_H */
