/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef FSP_FEATURES_H
#define FSP_FEATURES_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* C99 includes. */
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

/* Different compiler support. */
#include "fsp_common_api.h"
#include "bsp_compiler_support.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_COMMON
 * @addtogroup BSP_COMMON
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Available modules. */
typedef enum e_fsp_ip
{
    FSP_IP_NONE,
    FSP_IP_CANFD = 26,                 ///< Controller Area Network with Flexible Data Rate
} fsp_ip_t;

/** Signals that can be mapped to an interrupt. */
typedef enum e_fsp_signal
{
    FSP_SIGNAL_NONE
} fsp_signal_t;

typedef void (* fsp_vector_t)(void);

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_COMMON)
 **********************************************************************************************************************/

#endif                                 /* FSP_FEATURES_H */
