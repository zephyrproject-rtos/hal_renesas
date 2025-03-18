/*
 * Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "rp_crc.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "CRC" in ASCII, used to determine if channel is open. */
#define CRC_OPEN (0x00435243ULL)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

#if CRC_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_crc_open_cfg_check(crc_cfg_t const * const p_cfg);

#endif

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Reconfigure the CRC driver module
 *
 * Initialize the driver control block according to the passed-in
 * configuration structure.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       p_ctrl or p_cfg is NULL.
 * @retval FSP_ERR_ALREADY_OPEN    Module already open
 * @retval FSP_ERR_UNSUPPORTED     Hardware not support this feature.
 **********************************************************************************************************************/
fsp_err_t RP_CRC_Reconfigure (crc_ctrl_t * const p_ctrl, crc_cfg_t const * const p_cfg)
{
    crc_instance_ctrl_t * p_instance_ctrl = (crc_instance_ctrl_t *) p_ctrl;

#if CRC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);

    /* Verify the configuration parameters are valid */
    fsp_err_t err = r_crc_open_cfg_check(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Verify the control block has not already been initialized. */
    FSP_ERROR_RETURN(CRC_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    /* Save the configuration  */
    p_instance_ctrl->p_cfg = p_cfg;

    uint8_t crccr0 = 0;
#if BSP_FEATURE_CRC_HAS_CRCCR0_LMS

    /* Set bit order value */
    crccr0 = (uint8_t) (p_instance_ctrl->p_cfg->bit_order << R_CRC_CRCCR0_LMS_Pos);
#endif

    /* Set CRC polynomial */
    crccr0 |= (uint8_t) (p_instance_ctrl->p_cfg->polynomial << R_CRC_CRCCR0_GPS_Pos);

    /* Set DORCLR to clear CRCDOR */
    crccr0 |= (uint8_t) (1 << R_CRC_CRCCR0_DORCLR_Pos);

    R_CRC->CRCCR0 = crccr0;

#if BSP_FEATURE_CRC_HAS_SNOOP

    /* Disable snooping */
    R_CRC->CRCCR1 = 0;
#endif

    return FSP_SUCCESS;
}

#if CRC_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Validates the configuration arguments for illegal combinations or options.
 *
 * @param[in]  p_cfg                   Pointer to configuration structure
 *
 * @retval FSP_SUCCESS                     No configuration errors detected
 * @retval FSP_ERR_ASSERTION               An input argument is invalid.
 * @retval FSP_ERR_UNSUPPORTED             Hardware not support this feature.
 **********************************************************************************************************************/
static fsp_err_t r_crc_open_cfg_check (crc_cfg_t const * const p_cfg)
{
    FSP_ASSERT(NULL != p_cfg);

 #if !BSP_FEATURE_CRC_HAS_CRCCR0_LMS

    /* Verify the configuration bit order */
    FSP_ERROR_RETURN(CRC_BIT_ORDER_LMS_LSB == p_cfg->bit_order, FSP_ERR_UNSUPPORTED);
 #endif

    /* Verify the configuration polynomial */
    FSP_ERROR_RETURN((1 << p_cfg->polynomial) & BSP_FEATURE_CRC_POLYNOMIAL_MASK, FSP_ERR_UNSUPPORTED);

    return FSP_SUCCESS;
}

#endif
