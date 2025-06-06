/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_elc.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "ELC" in ASCII, used to determine if the module is open */
#define ELC_OPEN                  (0x00454C43U)
#define ELC_CLOSED                (0x00000000U)

#define ELC_ELCR_ELCON_DISABLE    (0x00U)
#define ELC_ELCR_ELCON_ENABLE     (0x80U)

/* Steps necessary to unlock and write software event generation bits */
#define ELC_ELSEGRN_STEP1         (0x00U) /* WI = 0, WE = 0, SEG = 0 */
#define ELC_ELSEGRN_STEP2         (0x40U) /* WI = 0, WE = 1, SEG = 0 */
#define ELC_ELSEGRN_STEP3         (0x41U) /* WI = 0, WE = 1, SEG = 1 */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

#if ELC_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_elc_common_parameter_checking(elc_instance_ctrl_t * p_instance_ctrl);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** ELC API structure.  */
const elc_api_t g_elc_on_elc =
{
    .open                  = R_ELC_Open,
    .close                 = R_ELC_Close,
    .softwareEventGenerate = R_ELC_SoftwareEventGenerate,
    .linkSet               = R_ELC_LinkSet,
    .linkBreak             = R_ELC_LinkBreak,
    .enable                = R_ELC_Enable,
    .disable               = R_ELC_Disable,
};

/*******************************************************************************************************************//**
 * @addtogroup ELC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize all the links in the Event Link Controller. Implements @ref elc_api_t::open
 *
 * The configuration structure passed in to this function includes links for every event source included in the ELC
 * and sets them all at once. To set or clear an individual link use R_ELC_LinkSet and R_ELC_LinkBreak respectively.
 *
 * Example:
 * @snippet r_elc_example.c R_ELC_Open
 *
 * @retval FSP_SUCCESS             Initialization was successful
 * @retval FSP_ERR_ASSERTION       p_ctrl or p_cfg was NULL
 * @retval FSP_ERR_ALREADY_OPEN    The module is currently open
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Open (elc_ctrl_t * const p_ctrl, elc_cfg_t const * const p_cfg)
{
    uint32_t i;
    uint64_t i_shift = 1;

    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;

#if ELC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(ELC_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    /* Power on ELC */
    R_BSP_MODULE_START(FSP_IP_ELC, 0);

    /* Loop through all links and set or clear them in the ELC block */
    for (i = 0; i < ELC_PERIPHERAL_NUM; i++)
    {
        /* Check to ensure the MCU we are using actually has this event link option */
        if (BSP_ELC_PERIPHERAL_MASK & i_shift)
        {
            R_ELC->ELSR[i].HA = (uint16_t) p_cfg->link[i];
        }

        i_shift <<= 1;
    }

    /* Set driver status to open */
    p_instance_ctrl->open = ELC_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Globally disable ELC linking. Implements @ref elc_api_t::close
 *
 * @retval FSP_SUCCESS             The ELC was successfully disabled
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Close (elc_ctrl_t * const p_ctrl)
{
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;

#if ELC_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    /* Set state to closed */
    p_instance_ctrl->open = ELC_CLOSED;

    uint8_t volatile * p_elcr = &R_ELC->ELCR;

#if BSP_TZ_SECURE_BUILD && BSP_FEATURE_TZ_VERSION == 2
    if (1 == R_ELC->ELCSARA_b.ELCR)
    {
        /* Access ELCR using the non-secure alias. */
        p_elcr = (uint8_t volatile *) ((uint32_t) p_elcr | BSP_FEATURE_TZ_NS_OFFSET);
    }
#endif

    /* Globally disable the operation of the Event Link Controller */
    *p_elcr = ELC_ELCR_ELCON_DISABLE;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Generate a software event in the Event Link Controller. Implements @ref elc_api_t::softwareEventGenerate
 *
 * Example:
 * @snippet r_elc_example.c R_ELC_SoftwareEventGenerate
 *
 * @retval FSP_SUCCESS             Initialization was successful
 * @retval FSP_ERR_ASSERTION       Invalid event number or p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 **********************************************************************************************************************/
fsp_err_t R_ELC_SoftwareEventGenerate (elc_ctrl_t * const p_ctrl, elc_software_event_t event_number)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    FSP_PARAMETER_NOT_USED(p_ctrl);

    uint8_t volatile * p_elsegrn = &R_ELC->ELSEGR[event_number].BY;

#if BSP_TZ_SECURE_BUILD && BSP_FEATURE_TZ_VERSION == 2

    /* Access ELSEGR using the non-secure alias. */
    p_elsegrn = (uint8_t volatile *) ((uint32_t) p_elsegrn | BSP_FEATURE_TZ_NS_OFFSET);
#endif

    /* Set the ELSEGR bits in the correct order (see Section 19.2.2 "Event Link Software Event Generation Register n
     * (ELSEGRn) (n = 0, 1)" of the RA6M3 manual R01UH0886EJ0100) */

    /* Step 1. enable the ELSEGR0 register for writing */
    *p_elsegrn = ELC_ELSEGRN_STEP1;

    /* Step 2. Enable the SEG bit for writing */
    *p_elsegrn = ELC_ELSEGRN_STEP2;

    /* Step 3. Set the SEG bit which causes the software event generation */
    *p_elsegrn = ELC_ELSEGRN_STEP3;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Create a single event link. Implements @ref elc_api_t::linkSet
 *
 * Example:
 * @snippet r_elc_example.c R_ELC_LinkSet
 *
 * @retval FSP_SUCCESS             Initialization was successful
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_LinkSet (elc_ctrl_t * const p_ctrl, elc_peripheral_t peripheral, elc_event_t signal)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

#if BSP_TZ_SECURE_BUILD

    /* Disable write protection to SAR registers */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SAR);

    /* Configure security attribution for ELSRn */
    /* Devices that only have ELCSARB */
 #if BSP_FEATURE_ELC_VERSION == 2
    R_ELC->ELCSARB &= (uint32_t)  ~(1 << peripheral);

    /* Devices that have ELCSARB and ELCSARC */
 #elif BSP_FEATURE_ELC_VERSION == 1
    if (peripheral < 16)
    {
        R_ELC->ELCSARB &= (uint16_t) ~(1U << peripheral);
    }
    else
    {
        R_ELC->ELCSARC &= (uint16_t) ~(1U << (peripheral - 16U));
    }
 #endif

    /* Restore write protection to SAR registers */
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SAR);
#endif

    /* Set the event link register for the corresponding peripheral to the given signal */
    R_ELC->ELSR[(uint32_t) peripheral].HA = (uint16_t) signal;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Break an event link. Implements @ref elc_api_t::linkBreak
 *
 * @retval FSP_SUCCESS             Event link broken
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_LinkBreak (elc_ctrl_t * const p_ctrl, elc_peripheral_t peripheral)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Clear the corresponding peripheral event link register to break the link */
    R_ELC->ELSR[(uint32_t) peripheral].HA = ELC_EVENT_NONE;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable the operation of the Event Link Controller. Implements @ref elc_api_t::enable
 *
 * @retval FSP_SUCCESS           ELC enabled.
 * @retval FSP_ERR_ASSERTION     p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN      The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Enable (elc_ctrl_t * const p_ctrl)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    uint8_t volatile * p_elcr = &R_ELC->ELCR;

#if BSP_TZ_SECURE_BUILD && BSP_FEATURE_TZ_VERSION == 2
    if (1 == R_ELC->ELCSARA_b.ELCR)
    {
        /* Access ELCR using the non-secure alias. */
        p_elcr = (uint8_t volatile *) ((uint32_t) p_elcr | BSP_FEATURE_TZ_NS_OFFSET);
    }
#endif

    /* Globally enable ELC function */
    *p_elcr = ELC_ELCR_ELCON_ENABLE;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disable the operation of the Event Link Controller. Implements @ref elc_api_t::disable
 *
 * @retval FSP_SUCCESS           ELC disabled.
 * @retval FSP_ERR_ASSERTION     p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN      The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Disable (elc_ctrl_t * const p_ctrl)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    uint8_t volatile * p_elcr = &R_ELC->ELCR;

#if BSP_TZ_SECURE_BUILD && BSP_FEATURE_TZ_VERSION == 2
    if (1 == R_ELC->ELCSARA_b.ELCR)
    {
        /* Access ELCR using the non-secure alias. */
        p_elcr = (uint8_t volatile *) ((uint32_t) p_elcr | BSP_FEATURE_TZ_NS_OFFSET);
    }
#endif

    /* Globally disable ELC function */
    *p_elcr = ELC_ELCR_ELCON_DISABLE;

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @} (end addtogroup ELC)
 **********************************************************************************************************************/

#if ELC_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Verifies the control structure is not NULL and the module is open. This reduces code size when the error logger is
 * used.
 *
 * @param[in]  p_instance_ctrl          Pointer to instance control structure.
 *
 * @retval FSP_SUCCESS                  No error detected.
 * @retval FSP_ERR_ASSERTION            Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN             Module is not open.
 **********************************************************************************************************************/
static fsp_err_t r_elc_common_parameter_checking (elc_instance_ctrl_t * p_instance_ctrl)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ELC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    return FSP_SUCCESS;
}

#endif
