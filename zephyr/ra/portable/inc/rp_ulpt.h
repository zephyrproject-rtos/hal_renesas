/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RP_ULPT_H_
#define RP_ULPT_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_ulpt_cfg.h"
#include "r_timer_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
fsp_err_t RP_ULPT_EventGet(timer_ctrl_t * const p_ctrl, uint8_t * event);
fsp_err_t RP_ULPT_CompareMatchSet(timer_ctrl_t * const        p_ctrl,
                                  uint32_t const              compare_match_value,
                                  timer_compare_match_t const match_channel);
fsp_err_t RP_ULPT_CompareMatchEnable(timer_ctrl_t * const        p_ctrl,
                                     timer_compare_match_t const match_channel);
fsp_err_t RP_ULPT_CompareMatchDisable(timer_ctrl_t * const        p_ctrl,
                                      timer_compare_match_t const match_channel);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */

FSP_FOOTER

#endif /* RP_ULPT_H_ */
