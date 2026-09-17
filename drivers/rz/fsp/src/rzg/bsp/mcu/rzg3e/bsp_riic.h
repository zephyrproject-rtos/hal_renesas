/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_riic.h
 * Version      : 1.00
 * Description  : bsp_riic header
 *********************************************************************************************************************/

#ifndef BSP_RIIC_H
#define BSP_RIIC_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/**********************************************************************************************************************
 * @addtogroup RZG_BSP_MPU_RZG3E
 * @{
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

#define R_BSP_RIIC_SET_SLAVE_ADDRESS(p_ctrl)                                               \
    /*7 bit mode selected, clear SAR. */                                                   \
    if (I2C_SLAVE_ADDR_MODE_7BIT == p_ctrl->p_cfg->addr_mode)                              \
    {                                                                                      \
        p_ctrl->p_reg->SARU0 = 0U;                                                         \
        p_ctrl->p_reg->SARL0 = (uint8_t) (p_ctrl->p_cfg->slave << 1U);                     \
    }                                                                                      \
    /* 10 bit mode selected, set SARx. */                                                  \
    else                                                                                   \
    {                                                                                      \
        p_ctrl->p_reg->SARU0 = (uint8_t) (((p_ctrl->p_cfg->slave >> 7U) | 0x01U) & 0x07U); \
        p_ctrl->p_reg->SARL0 = (uint8_t) (p_ctrl->p_cfg->slave);                           \
    }

#define R_BSP_RIIC_ENABLE_SLAVE_ADDRESS(p_ctrl)                                               \
    p_ctrl->p_reg->ICSER =                                                                    \
        (uint8_t) ((uint8_t) IIC_SLAVE_ICSER_SLAVE_ADDRESS_ENABLE_REGISTER_0 |                \
                   ((uint8_t) p_ctrl->p_cfg->general_call_enable << R_RIIC0_ICSER_GCAE_Pos)); \


/* Clock source mapping for each RIIC_MASTER channel */
static const fsp_priv_clock_t g_iic_master_clock_map[] =
{
    FSP_PRIV_CLOCK_P5CLK,              /* CH0 */
    FSP_PRIV_CLOCK_P5CLK,              /* CH1 */
    FSP_PRIV_CLOCK_P5CLK,              /* CH2 */
    FSP_PRIV_CLOCK_P5CLK,              /* CH3 */
    FSP_PRIV_CLOCK_P5CLK,              /* CH4 */
    FSP_PRIV_CLOCK_P5CLK,              /* CH5 */
    FSP_PRIV_CLOCK_P5CLK,              /* CH6 */
    FSP_PRIV_CLOCK_P5CLK,              /* CH7 */
    FSP_PRIV_CLOCK_P1CLK,              /* CH8 */
};

/** @} (end addtogroup BSP_MPU_RZG3E) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

#endif                                 /* BSP_RIIC_H */
