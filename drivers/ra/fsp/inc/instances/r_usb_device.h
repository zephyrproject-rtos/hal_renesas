/*
 * Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_USB_DEVICE_H
#define R_USB_DEVICE_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_usb_device_api.h"
#include "r_usb_device_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef struct st_usbd_instance_ctrl
{
    uint32_t           open;
    void             * p_reg;
    usbd_cfg_t const * p_cfg;
    void (* p_callback)(usbd_callback_arg_t * p_args);
    usbd_callback_arg_t * p_callback_memory;
    void const          * p_context;
} usbd_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

fsp_err_t R_USBD_Open(usbd_ctrl_t * const p_api_ctrl, usbd_cfg_t const * const p_cfg);
fsp_err_t R_USBD_RemoteWakeup(usbd_ctrl_t * const p_api_ctrl);
fsp_err_t R_USBD_Connect(usbd_ctrl_t * const p_api_ctrl);
fsp_err_t R_USBD_Disconnect(usbd_ctrl_t * const p_api_ctrl);
fsp_err_t R_USBD_EdptOpen(usbd_ctrl_t * const p_api_ctrl, usbd_desc_endpoint_t const * p_ep_desc);
fsp_err_t R_USBD_EdptClose(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr);
fsp_err_t R_USBD_XferStart(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr, uint8_t * buffer, uint16_t total_bytes);
fsp_err_t R_USBD_XferAbort(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr);
fsp_err_t R_USBD_EdptStall(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr);
fsp_err_t R_USBD_EdptClearStall(usbd_ctrl_t * const p_api_ctrl, uint8_t ep_addr);
fsp_err_t R_USBD_Close(usbd_ctrl_t * const p_api_ctrl);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif /* R_USB_DEVICE_H */
