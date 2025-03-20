/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_agt.h"
#include "rp_agt.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BIT_SET(val, pos)                    (val | (1 << pos))
#define BIT_CLEAR(val, pos)                  (val & ~(1 << pos))

#define AGT_PRV_IS_AGTW(p_instance_ctrl)     ((p_instance_ctrl)->is_agtw)

#define AGT_PRV_CTRL_PTR(p_instance_ctrl)    ((agt_prv_reg_ctrl_ptr_t) (AGT_PRV_IS_AGTW((p_instance_ctrl))      \
                                                                        ? &(p_instance_ctrl)->p_reg->AGT32.CTRL \
                                                                        : &(p_instance_ctrl)->p_reg->AGT16.CTRL))

#define AGT_PRV_AGTCR_STATUS_FLAGS    (0xF0U)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef volatile R_AGTX0_AGT16_CTRL_Type * const agt_prv_reg_ctrl_ptr_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static fsp_err_t r_agt_common_preamble(agt_instance_ctrl_t * p_instance_ctrl);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/
fsp_err_t RP_AGT_EventSet (timer_ctrl_t * const p_ctrl, agt_event_t event, bool enable)
{
    agt_instance_ctrl_t * p_instance_ctrl = (agt_instance_ctrl_t *) p_ctrl;

#if AGT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(0 != p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif /* AGT_CFG_PARAM_CHECKING_ENABLE */

    fsp_err_t err = r_agt_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    agt_prv_reg_ctrl_ptr_t p_reg_ctrl = AGT_PRV_CTRL_PTR(p_instance_ctrl);

    if (true == enable)
    {
        p_reg_ctrl->AGTCMSR = (uint8_t) BIT_SET(p_reg_ctrl->AGTCMSR, event);
    }
    else
    {
        p_reg_ctrl->AGTCMSR = (uint8_t) BIT_CLEAR(p_reg_ctrl->AGTCMSR, event);
    }

    return FSP_SUCCESS;
}

fsp_err_t RP_AGT_EventGet (timer_ctrl_t * const p_ctrl, uint8_t * event)
{
    agt_instance_ctrl_t * p_instance_ctrl = (agt_instance_ctrl_t *) p_ctrl;

#if AGT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != event);
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(0 != p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif /* AGT_CFG_PARAM_CHECKING_ENABLE */

    agt_prv_reg_ctrl_ptr_t p_reg_ctrl = AGT_PRV_CTRL_PTR(p_instance_ctrl);

    *event = p_reg_ctrl->AGTCR &
             (R_AGTX0_AGT16_CTRL_AGTCR_TUNDF_Msk | R_AGTX0_AGT16_CTRL_AGTCR_TCMAF_Msk |
              R_AGTX0_AGT16_CTRL_AGTCR_TCMBF_Msk);

    return FSP_SUCCESS;
}

fsp_err_t RP_AGT_CompareMatchSet (timer_ctrl_t * const        p_ctrl,
                                  uint32_t const              compare_match_value,
                                  timer_compare_match_t const match_channel)
{
    agt_instance_ctrl_t * p_instance_ctrl = (agt_instance_ctrl_t *) p_ctrl;

#if AGT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(0 != p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif /* AGT_CFG_PARAM_CHECKING_ENABLE */

    fsp_err_t err = r_agt_common_preamble(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    if (AGT_PRV_IS_AGTW(p_instance_ctrl))
    {
        if (TIMER_COMPARE_MATCH_A == match_channel)
        {
            p_instance_ctrl->p_reg->AGT32.AGTCMA = compare_match_value;
        }
        else
        {
            p_instance_ctrl->p_reg->AGT32.AGTCMB = compare_match_value;
        }
    }
    else
    {
        if (TIMER_COMPARE_MATCH_A == match_channel)
        {
            p_instance_ctrl->p_reg->AGT16.AGTCMA = compare_match_value;
        }
        else
        {
            p_instance_ctrl->p_reg->AGT16.AGTCMB = compare_match_value;
        }
    }

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
static fsp_err_t r_agt_common_preamble (agt_instance_ctrl_t * p_instance_ctrl)
{
#if AGT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(AGT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    agt_prv_reg_ctrl_ptr_t p_reg_ctrl = AGT_PRV_CTRL_PTR(p_instance_ctrl);

    /* Ensure timer state reflects expected status. Reference section 25.4.1 "Count Operation Start and Stop Control"
     * in the RA6M3 manual R01UH0886EJ0100. */
    uint32_t agtcr_tstart = p_reg_ctrl->AGTCR_b.TSTART;
    FSP_HARDWARE_REGISTER_WAIT(agtcr_tstart, p_reg_ctrl->AGTCR_b.TCSTF);

    return FSP_SUCCESS;
}

void agtcmai_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    agt_instance_ctrl_t  * p_instance_ctrl = (agt_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    agt_prv_reg_ctrl_ptr_t p_reg_ctrl      = AGT_PRV_CTRL_PTR(p_instance_ctrl);

    /* Clear flags in AGTCR. */
    p_reg_ctrl->AGTCR &= ~AGT_PRV_AGTCR_STATUS_FLAGS;

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

void agtcmbi_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Recover ISR context saved in open. */
    agt_instance_ctrl_t  * p_instance_ctrl = (agt_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    agt_prv_reg_ctrl_ptr_t p_reg_ctrl      = AGT_PRV_CTRL_PTR(p_instance_ctrl);

    /* Clear flags in AGTCR. */
    p_reg_ctrl->AGTCR &= ~AGT_PRV_AGTCR_STATUS_FLAGS;

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
