/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_LCDC_H_
#define R_LCDC_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_display_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZA
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_LCDC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** LCDC hardware specific configuration */
struct st_lcdc_extended_cfg
{
    uint8_t   frame_end_ipl;           ///< Frame end interrupt priority
    uint8_t   underrun_ipl;            ///< Under run interrupt priority
    IRQn_Type frame_end_irq;           ///< Frame end interrupt vector
    IRQn_Type underrun_irq;            ///< Under run interrupt vector
};

/** LCDC hardware specific configuration. Please refer to the struct st_lcdc_extended_cfg. */
typedef struct st_lcdc_extended_cfg lcdc_extended_cfg_t;

/** CRU context struct for callback function */
struct st_display_ctrl
{
    void * p_context;
};

/** CRU context struct for callback function. Please refer to the struct st_display_ctrl. */
typedef struct st_display_ctrl lcdc_ctrl_t;

/** Display control block.  DO NOT INITIALIZE. */
struct st_lcdc_instance_ctrl
{
    display_state_t state;                                 // Status of LCDC module

    /* Parameters to Event processing for display devices */
    void (* p_callback)(display_callback_args_t * p_args); // Pointer to callback function
    void                * p_context;                       // Pointer to the higher level device context
    const display_cfg_t * p_cfg;                           // Pointer to initial configurations
};

/** Display control block.  DO NOT INITIALIZE. Please refer to the struct st_lcdc_instance_ctrl. */
typedef struct st_lcdc_instance_ctrl lcdc_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern const display_api_t g_display_on_lcdc;

/** @cond INC_HEADER_DEFS_SEC */

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_LCDC_Open(display_ctrl_t * const p_api_ctrl, display_cfg_t const * const p_cfg);
fsp_err_t R_LCDC_Close(display_ctrl_t * const p_api_ctrl);
fsp_err_t R_LCDC_Start(display_ctrl_t * const p_api_ctrl);
fsp_err_t R_LCDC_Stop(display_ctrl_t * const p_api_ctrl);
fsp_err_t R_LCDC_LayerChange(display_ctrl_t const * const        p_api_ctrl,
                             display_runtime_cfg_t const * const p_cfg,
                             display_frame_layer_t               layer);
fsp_err_t R_LCDC_BufferChange(display_ctrl_t const * const p_api_ctrl,
                              uint8_t * const              framebuffer,
                              display_frame_layer_t        layer);
fsp_err_t R_LCDC_ColorCorrection(display_ctrl_t const * const       p_api_ctrl,
                                 display_correction_t const * const p_correction);
fsp_err_t R_LCDC_ClutUpdate(display_ctrl_t const * const     p_api_ctrl,
                            display_clut_cfg_t const * const p_clut_cfg,
                            display_frame_layer_t            layer);
fsp_err_t R_LCDC_ClutEdit(display_ctrl_t const * const p_api_ctrl,
                          display_frame_layer_t        layer,
                          uint8_t                      index,
                          uint32_t                     color);
fsp_err_t R_LCDC_ColorKeySet(display_ctrl_t const * const p_api_ctrl,
                             display_colorkeying_layer_t  ck_cfg,
                             display_frame_layer_t        layer);
fsp_err_t R_LCDC_StatusGet(display_ctrl_t const * const p_api_ctrl, display_status_t * const p_status);

/*******************************************************************************************************************//**
 * @} (end defgroup LCDC)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

#endif                                 /* R_LCDC_H_ */
