/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RP_AGT_H_
#define RP_AGT_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_agt_cfg.h"
#include "r_timer_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum e_agt_event
{
    TIMER_AGT_AGTCMAI = R_AGTX0_AGT16_CTRL_AGTCMSR_TCMEA_Pos,
    TIMER_AGT_AGTCMBI = R_AGTX0_AGT16_CTRL_AGTCMSR_TCMEB_Pos,
} agt_event_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

fsp_err_t RP_AGT_EventSet(timer_ctrl_t * const p_ctrl, agt_event_t event, bool enable);
fsp_err_t RP_AGT_EventGet(timer_ctrl_t * const p_ctrl, uint8_t * event);
fsp_err_t RP_AGT_CompareMatchSet(timer_ctrl_t * const        p_ctrl,
                                 uint32_t const              compare_match_value,
                                 timer_compare_match_t const match_channel);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */

FSP_FOOTER

#endif /* RP_AGT_H_ */
