/*
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup LVD-PVD
 * @{
 **********************************************************************************************************************/

#ifndef RP_LVD_H
#define RP_LVD_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_lvd.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t RP_LVD_Enable(lvd_ctrl_t * const p_api_ctrl, bool enable);
fsp_err_t RP_LVD_IsEnable(lvd_ctrl_t * const p_api_ctrl, bool * is_enabled);
fsp_err_t RP_LVD_TriggerSet(lvd_ctrl_t * const p_api_ctrl, bool reset_action, lvd_voltage_slope_t voltage_slope);

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup LVD-PVD)
 **********************************************************************************************************************/
