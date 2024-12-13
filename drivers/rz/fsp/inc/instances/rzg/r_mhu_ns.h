/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup MHU_NS
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_mhu_api.h"
#include "r_mhu_ns_cfg.h"

#ifndef R_MHU_NS_H
 #define R_MHU_NS_H

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/*************************************************************************************************
 * Type defines
 *************************************************************************************************/

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when @ref mhu_api_t::open is called. */
typedef struct st_mhu_ns_instance_ctrl
{
    uint32_t          open;             ///< Indicates whether the open() API has been successfully called.
    mhu_cfg_t const * p_cfg;            ///< Pointer to instance configuration
    R_MHU0_Type     * p_regs;           ///< Base register for this channel

    uint32_t        channel;            ///< channel
    mhu_send_type_t send_type;          ///< Send Type: Message or Response
    uint32_t      * p_shared_memory_tx; ///< Pointer to send data area
    uint32_t      * p_shared_memory_rx; ///< Pointer to recv data area

 #if BSP_TZ_SECURE_BUILD
    bool callback_is_secure;            ///< p_callback is in secure memory
 #endif

    /* Pointer to callback and optional working memory */
    void (* p_callback)(mhu_callback_args_t *);

    /* Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory. */
    mhu_callback_args_t * p_callback_memory;

    /* Pointer to context to be passed into callback function */
    void const * p_context;
} mhu_ns_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const mhu_api_t g_mhu_ns_on_mhu_ns;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_MHU_NS_Open(mhu_ctrl_t * p_ctrl, mhu_cfg_t const * const p_cfg);

fsp_err_t R_MHU_NS_MsgSend(mhu_ctrl_t * const p_ctrl, uint32_t const msg);

fsp_err_t R_MHU_NS_Close(mhu_ctrl_t * const p_ctrl);

fsp_err_t R_MHU_NS_CallbackSet(mhu_ctrl_t * const          p_api_ctrl,
                               void (                    * p_callback ) (mhu_callback_args_t *),
                               void const * const          p_context,
                               mhu_callback_args_t * const p_callback_memory);

void R_MHU_NS_IsrSub(uint32_t irq);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* R_MHU_NS_H */

/*******************************************************************************************************************//**
 * @} (end defgroup MHU_NS)
 **********************************************************************************************************************/
