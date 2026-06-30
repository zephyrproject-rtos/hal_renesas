/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_USB_HOST_H
#define R_USB_HOST_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_usb_host_api.h"
#include "r_usb_host_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** USB host instance control block. Allocate one per instance; managed internally by the driver,
 *  do not modify its fields directly. */
typedef struct st_usbh_instance_ctrl
{
    uint32_t          open;                            ///< Set to ::USBH_OPEN after R_USBH_Open(), cleared on close.
    void            * p_reg;                           ///< Base address of the USB peripheral registers in use.
    uint32_t          module_number;                   ///< USB IP/module number this instance drives.
    usb_speed_t       max_speed;                       ///< Maximum speed supported by the selected module.
    usb_cfg_t const * p_cfg;                           ///< Pointer to the configuration passed to R_USBH_Open().
    void (* p_callback)(usbh_callback_arg_t * p_args); ///< User event callback.
    usbh_callback_arg_t * p_callback_memory;           ///< Optional caller-provided storage for callback arguments.
    void const          * p_context;                   ///< User context forwarded to @ref p_callback.
} usbh_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global functions
 **********************************************************************************************************************/

/** Open the USB host driver: start the module, select the operating mode and configure the default pipe. */
fsp_err_t R_USBH_Open(usb_ctrl_t * const p_api_ctrl, usb_cfg_t const * const p_cfg);

/** Get the speed negotiated with the device currently connected to the root port. */
fsp_err_t R_USBH_GetDeviceSpeed(usb_ctrl_t * const p_api_ctrl, usb_speed_t * p_speed);

/** Register a device address and bind it to the default control pipe so transfers can be issued to it. */
fsp_err_t R_USBH_PortOpen(usb_ctrl_t * const p_api_ctrl,
                          uint8_t            dev_addr,
                          usb_speed_t        speed,
                          uint8_t            mxps0,
                          uint8_t            hub_addr,
                          uint8_t            hub_port);

/** Read the port/bus status flags (attach, detach, overcurrent, EOF error). */
fsp_err_t R_USBH_PortStatusGet(usb_ctrl_t * const p_api_ctrl, usb_status_t * p_status);

/** Drive a USB bus reset on the root port. */
fsp_err_t R_USBH_PortReset(usb_ctrl_t * const p_api_ctrl);

/** Release a device address and free every pipe associated with it. */
fsp_err_t R_USBH_DeviceRelease(usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr);

/** Send an 8-byte SETUP packet over the default control pipe. */
fsp_err_t R_USBH_SetupSend(usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr, uint8_t const setup_packet[8]);

/** Open (configure a pipe for) an endpoint described by a standard endpoint descriptor. */
fsp_err_t R_USBH_EdptOpen(usb_ctrl_t * const          p_api_ctrl,
                          uint8_t                     dev_addr,
                          usb_desc_endpoint_t const * p_ep_desc,
                          uint8_t                   * pipe_num);

/** Start a data transfer on a previously opened endpoint; completion is reported via the callback. */
fsp_err_t R_USBH_XferStart(usb_ctrl_t * const p_api_ctrl,
                           uint8_t            dev_addr,
                           uint8_t            ep_addr,
                           uint8_t          * buffer,
                           uint16_t           buflen);

/** Close the USB host driver and power down the module. */
fsp_err_t R_USBH_Close(usb_ctrl_t * const p_ctrl);

/** Resume the bus from suspend (drive resume signaling, then re-enable the bus). */
fsp_err_t R_USBH_BusResume(usb_ctrl_t * const p_api_ctrl);

/** Suspend the bus (stop bus activity). */
fsp_err_t R_USBH_BusSuspend(usb_ctrl_t * const p_api_ctrl);

/** Connect the controller to the data bus (enable D+/D- pull-downs and the module). */
fsp_err_t R_USBH_Enable(usb_ctrl_t * const p_api_ctrl);

/** Disconnect the controller from the data bus. */
fsp_err_t R_USBH_Disable(usb_ctrl_t * const p_api_ctrl);

/** Abort an in-progress transfer on the given endpoint and free its FIFO/transaction state. */
fsp_err_t R_USBH_XferAbort(usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr, uint8_t ep_addr);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
