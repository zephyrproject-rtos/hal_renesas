/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <r_mipi_phy_b.h>

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define MIPI_PHY_OPEN    (0x4D504950)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

const mipi_phy_b_api_t g_mipi_phy =
{
    .open  = r_mipi_phy_b_open,
    .close = r_mipi_phy_b_close,
};

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Initialize the MIPI PHY peripheral.
 *
 * @retval FSP_SUCCESS                  The channel was successfully opened.
 * @retval FSP_ERR_ASSERTION            One or both of the parameters was NULL.
 * @retval FSP_ERR_ALREADY_OPEN         The instance is already opened.
 **********************************************************************************************************************/
fsp_err_t r_mipi_phy_b_open (mipi_phy_b_ctrl_t * const p_api_ctrl, mipi_phy_b_cfg_t const * const p_cfg)
{
    mipi_phy_b_ctrl_t * p_ctrl = p_api_ctrl;

#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(MIPI_PHY_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    R_MIPI_DSI->DSIDPHYCTRL0_b.EN_BGR = 0b1;

    R_BSP_SoftwareDelay(20, BSP_DELAY_UNITS_MICROSECONDS);
    R_MIPI_DSI->DSIDPHYCTRL0_b.EN_LDO1200 = 0b1;

    R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);

    /* Set D-PHY timing parameters */
    mipi_phy_b_timing_t const * p_timing = p_cfg->p_timing;
    R_MIPI_DSI->DSIDPHYTIM0 = (p_timing->t_init << R_MIPI_DSI_DSIDPHYTIM0_T_INIT_Pos) &
                              R_MIPI_DSI_DSIDPHYTIM0_T_INIT_Msk;
    R_MIPI_DSI->DSIDPHYTIM1 =
        (uint32_t) (((p_timing->t_hs_prep << R_MIPI_DSI_DSIDPHYTIM1_THS_PREPARE_Pos) &
                     R_MIPI_DSI_DSIDPHYTIM1_THS_PREPARE_Msk) |
                    ((p_timing->t_clk_prep << R_MIPI_DSI_DSIDPHYTIM1_TCLK_PREPARE_Pos) &
                     R_MIPI_DSI_DSIDPHYTIM1_TCLK_PREPARE_Msk));
    R_MIPI_DSI->DSIDPHYTIM2 =
        (uint32_t) (((p_timing->t_clk_trail << R_MIPI_DSI_DSIDPHYTIM2_TCLK_TRAIL_Pos) &
                     R_MIPI_DSI_DSIDPHYTIM2_TCLK_TRAIL_Msk) |
                    ((p_timing->t_clk_post << R_MIPI_DSI_DSIDPHYTIM2_TCLK_POST_Pos) &
                     R_MIPI_DSI_DSIDPHYTIM2_TCLK_POST_Msk) |
                    ((p_timing->t_clk_pre << R_MIPI_DSI_DSIDPHYTIM2_TCLK_PRE_Pos) &
                     R_MIPI_DSI_DSIDPHYTIM2_TCLK_POST_Msk) |
                    ((p_timing->t_clk_zero << R_MIPI_DSI_DSIDPHYTIM2_TCLK_ZERO_Pos) &
                     R_MIPI_DSI_DSIDPHYTIM2_TCLK_ZERO_Msk));
    R_MIPI_DSI->DSIDPHYTIM3 =
        (uint32_t) (((p_timing->t_lp_exit << R_MIPI_DSI_DSIDPHYTIM3_TLPX_Pos) & R_MIPI_DSI_DSIDPHYTIM3_TLPX_Msk) |
                    ((p_timing->t_hs_exit << R_MIPI_DSI_DSIDPHYTIM3_THS_EXIT_Pos) &
                     R_MIPI_DSI_DSIDPHYTIM3_THS_EXIT_Msk) |
                    ((p_timing->t_hs_trail << R_MIPI_DSI_DSIDPHYTIM3_THS_TRAIL_Pos) &
                     R_MIPI_DSI_DSIDPHYTIM3_THS_TRAIL_Msk) |
                    ((p_timing->t_hs_zero << R_MIPI_DSI_DSIDPHYTIM3_THS_ZERO_Pos) &
                     R_MIPI_DSI_DSIDPHYTIM3_THS_ZERO_Msk));

    /* Keep track of p_cfg struct */
    p_ctrl->p_cfg = p_cfg;

    /* Mark control block as opened */
    p_ctrl->open = MIPI_PHY_OPEN;

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Stop filter operations and close the channel instance.
 *
 * @retval FSP_SUCCESS           The channel is successfully closed.
 * @retval FSP_ERR_ASSERTION     p_api_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN      Instance is not open.
 **********************************************************************************************************************/
fsp_err_t r_mipi_phy_b_close (mipi_phy_b_ctrl_t * const p_api_ctrl)
{
    mipi_phy_b_ctrl_t * p_ctrl = p_api_ctrl;

#if MIPI_DSI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(MIPI_PHY_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    R_MIPI_DSI->DSIDPHYCTRL0_b.EN_BGR = 0U;

    R_MIPI_DSI->DSIDPHYCTRL0_b.EN_LDO1200 = 0U;

    /* Set control block to closed */
    p_ctrl->open = 0U;

    return FSP_SUCCESS;
}
