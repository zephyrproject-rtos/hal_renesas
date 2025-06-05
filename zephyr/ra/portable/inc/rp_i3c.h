/*
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup I3C
 * @{
 **********************************************************************************************************************/

#ifndef RP_I3C_H
#define RP_I3C_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_i3c.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

fsp_err_t R_I3C_MasterDeviceTableGet(i3c_ctrl_t * const             p_api_ctrl,
                                     uint32_t                       device_index,
                                     i3c_device_table_cfg_t * const p_device_table_cfg);
fsp_err_t R_I3C_MasterDeviceTableReset(i3c_ctrl_t * const p_api_ctrl, uint32_t device_index);

/*******************************************************************************************************************//**
 * @} (end defgroup I3C)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
