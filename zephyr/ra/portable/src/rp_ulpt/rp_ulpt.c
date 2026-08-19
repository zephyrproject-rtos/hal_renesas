/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_ulpt.h"
#include "rp_ulpt.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static fsp_err_t rp_ulpt_common_preamble (ulpt_instance_ctrl_t * p_instance_ctrl);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Retrieves the current ULPT event status flags (underflow, compare match A, compare match B) from the ULPTCR register.
 *
 * @param[in]  p_ctrl          Pointer to instance control structure.
 * @param[out] event           Pointer to store the event flags (TUNDF, TCMAF, TCMBF).
 *
 * @retval FSP_SUCCESS         Event flags successfully retrieved.
 * @retval FSP_ERR_ASSERTION   p_ctrl or event is NULL.
 * @retval FSP_ERR_NOT_OPEN    The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t RP_ULPT_EventGet (timer_ctrl_t * const p_ctrl, uint8_t * event)
{
    ulpt_instance_ctrl_t * p_instance_ctrl = (ulpt_instance_ctrl_t *) p_ctrl;

#if ULPT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != event);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(0 != p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif /* ULPT_CFG_PARAM_CHECKING_ENABLE */

    const uint8_t event_mask = (uint8_t) (R_ULPT0_ULPTCR_TUNDF_Msk | 
                                          R_ULPT0_ULPTCR_TCMAF_Msk |
                                          R_ULPT0_ULPTCR_TCMBF_Msk);
    
    const uint8_t ulptcr_val = (uint8_t)(p_instance_ctrl->p_reg->ULPTCR);

    *event = ulptcr_val & event_mask;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets the compare match value for channel A (ULPTCMA) or channel B (ULPTCMB). This extends R_ULPT_CompareMatchSet
 * which returns FSP_ERR_UNSUPPORTED in the original FSP driver.
 *
 * @param[in] p_ctrl                Pointer to instance control structure.
 * @param[in] compare_match_value   Value to set in the compare match register.
 * @param[in] match_channel         Select compare match channel A or B.
 *
 * @retval FSP_SUCCESS              Compare match value successfully set.
 * @retval FSP_ERR_ASSERTION        p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN         The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t RP_ULPT_CompareMatchSet (timer_ctrl_t * const        p_ctrl,
                                   uint32_t const              compare_match_value,
                                   timer_compare_match_t const match_channel)
{
    ulpt_instance_ctrl_t * p_instance_ctrl = (ulpt_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = rp_ulpt_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    
    if (TIMER_COMPARE_MATCH_A == match_channel)
    {
        p_instance_ctrl->p_reg->ULPTCMA = compare_match_value;
    }
    else
    {
        p_instance_ctrl->p_reg->ULPTCMB = compare_match_value;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enables compare match output for channel A or B by setting the corresponding bit (TCMEA/TCMEB) in the ULPTCMSR
 * register.
 *
 * @param[in] p_ctrl          Pointer to instance control structure.
 * @param[in] match_channel   Select compare match channel A or B.
 *
 * @retval FSP_SUCCESS        Compare match output successfully enabled.
 * @retval FSP_ERR_ASSERTION  p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN   The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t RP_ULPT_CompareMatchEnable(timer_ctrl_t * const        p_ctrl,
                                     timer_compare_match_t const match_channel)
{
    ulpt_instance_ctrl_t * p_instance_ctrl = (ulpt_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = rp_ulpt_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    const uint8_t ulptcmsr_mask = (TIMER_COMPARE_MATCH_A == match_channel) ? 
                                 (uint8_t)R_ULPT0_ULPTCMSR_TCMEA_Msk :
                                 (uint8_t)R_ULPT0_ULPTCMSR_TCMEB_Msk;

    p_instance_ctrl->p_reg->ULPTCMSR |= ulptcmsr_mask;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disables compare match output for channel A or B by clearing the corresponding bit (TCMEA/TCMEB) in the ULPTCMSR
 * register.
 *
 * @param[in] p_ctrl          Pointer to instance control structure.
 * @param[in] match_channel   Select compare match channel A or B.
 *
 * @retval FSP_SUCCESS        Compare match output successfully disabled.
 * @retval FSP_ERR_ASSERTION  p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN   The instance control structure is not opened.
 **********************************************************************************************************************/
fsp_err_t RP_ULPT_CompareMatchDisable(timer_ctrl_t * const        p_ctrl,
                                      timer_compare_match_t const match_channel)
{
    ulpt_instance_ctrl_t * p_instance_ctrl = (ulpt_instance_ctrl_t *) p_ctrl;

    fsp_err_t err = rp_ulpt_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    const uint8_t ulptcmsr_mask = (TIMER_COMPARE_MATCH_A == match_channel) ? 
                                 (uint8_t)R_ULPT0_ULPTCMSR_TCMEA_Msk :
                                 (uint8_t)R_ULPT0_ULPTCMSR_TCMEB_Msk;

    p_instance_ctrl->p_reg->ULPTCMSR &= ~ulptcmsr_mask;

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Common code at the beginning of all ULPT functions except open.
 *
 * @param[in] p_instance_ctrl          Pointer to instance control structure.
 *
 * @retval FSP_SUCCESS                 No invalid conditions detected, timer state matches expected state.
 * @retval FSP_ERR_ASSERTION           p_ctrl is null.
 * @retval FSP_ERR_NOT_OPEN            The instance control structure is not opened.
 **********************************************************************************************************************/
static fsp_err_t rp_ulpt_common_preamble (ulpt_instance_ctrl_t * p_instance_ctrl)
{
#if ULPT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(0 != p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Ensure timer state reflects expected status. */
    uint32_t ulptcr_tstart = p_instance_ctrl->p_reg->ULPTCR_b.TSTART;
    FSP_HARDWARE_REGISTER_WAIT(ulptcr_tstart, p_instance_ctrl->p_reg->ULPTCR_b.TCSTF);

    return FSP_SUCCESS;
}
