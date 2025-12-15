/*
 * Copyright (c) 2025 Vincent Jardin, Free Mobile
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef R_IICA_SLAVE_CFG_H
#define R_IICA_SLAVE_CFG_H

#include "bsp_api.h"
#include "r_i2c_slave_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/** Specifies whether to include code for DTC support */
#define IICA_SLAVE_CFG_DTC_ENABLE (0)

/** Filled in Interface API structure for this Instance. */
extern i2c_slave_api_t const g_i2c_slave_on_iica;

/** Common macro for FSP header files. */
FSP_FOOTER

#endif /* R_IICA_SLAVE_CFG_H */
