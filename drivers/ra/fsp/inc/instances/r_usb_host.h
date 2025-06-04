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

typedef struct st_usbh_instance_ctrl
{
    uint32_t          open;
    void            * p_reg;
    uint32_t          module_number;
    usb_speed_t       max_speed;
    usb_cfg_t const * p_cfg;
    void (* p_callback)(usbh_callback_arg_t * p_args);
    usbh_callback_arg_t * p_callback_memory;
    void const          * p_context;
} usbh_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global functions
 **********************************************************************************************************************/
fsp_err_t R_USBH_Open(usb_ctrl_t * const p_api_ctrl, usb_cfg_t const * const p_cfg);
fsp_err_t R_USBH_GetDeviceSpeed(usb_ctrl_t * const p_api_ctrl, usb_speed_t * p_speed);
fsp_err_t R_USBH_PortOpen(usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr);
fsp_err_t R_USBH_PortStatusGet(usb_ctrl_t * const p_api_ctrl, usb_status_t * p_status);
fsp_err_t R_USBH_PortReset(usb_ctrl_t * const p_api_ctrl);
fsp_err_t R_USBH_DeviceRelease(usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr);
fsp_err_t R_USBH_SetupSend(usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr, uint8_t const setup_packet[8]);
fsp_err_t R_USBH_EdptOpen(usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr, usb_desc_endpoint_t const * ep_desc);
fsp_err_t R_USBH_XferStart(usb_ctrl_t * const p_api_ctrl,
                           uint8_t            dev_addr,
                           uint8_t            ep_addr,
                           uint8_t          * buffer,
                           uint16_t           buflen);
fsp_err_t R_USBH_Close(usb_ctrl_t * const p_ctrl);
fsp_err_t R_USBH_SOFEnable(usb_ctrl_t * const p_api_ctrl);
fsp_err_t R_USBH_SOFDisable(usb_ctrl_t * const p_api_ctrl);
fsp_err_t R_USBH_BusResume(usb_ctrl_t * const p_api_ctrl);
fsp_err_t R_USBH_BusSuspend(usb_ctrl_t * const p_api_ctrl);
fsp_err_t R_USBH_Enable(usb_ctrl_t * const p_api_ctrl);
fsp_err_t R_USBH_Disable(usb_ctrl_t * const p_api_ctrl);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
