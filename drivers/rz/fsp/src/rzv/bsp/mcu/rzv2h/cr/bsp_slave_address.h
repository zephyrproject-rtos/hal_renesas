/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_slave_address.h
 * Version      : 1.00
 * Description  : bsp_slave_address header
 *********************************************************************************************************************/

#ifndef BSP_SLAVE_ADDRESS_H
#define BSP_SLAVE_ADDRESS_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/
#define BSP_ADDRESS_CR_CORE0_ITCM_CORE_BASE    (0x00000000)
#define BSP_ADDRESS_CR_CORE0_ITCM_AXI_BASE     (0x12040000)
#define BSP_ADDRESS_CR_CORE0_ITCM_SIZE         (0x00020000)

#define BSP_ADDRESS_CR_CORE0_DTCM_CORE_BASE    (0x00020000)
#define BSP_ADDRESS_CR_CORE0_DTCM_AXI_BASE     (0x12060000)
#define BSP_ADDRESS_CR_CORE0_DTCM_SIZE         (0x00020000)

#define BSP_ADDRESS_CR_CORE1_ITCM_CORE_BASE    (0x00000000)
#define BSP_ADDRESS_CR_CORE1_ITCM_AXI_BASE     (0x12080000)
#define BSP_ADDRESS_CR_CORE1_ITCM_SIZE         (0x00020000)

#define BSP_ADDRESS_CR_CORE1_DTCM_CORE_BASE    (0x00020000)
#define BSP_ADDRESS_CR_CORE1_DTCM_AXI_BASE     (0x120A0000)
#define BSP_ADDRESS_CR_CORE1_DTCM_SIZE         (0x00020000)

#if (0 == BSP_CR8_CORE_NUM)
 #define BSP_ADDRESS_CONVERT_TABLE_BODY                                                                        \
    {BSP_ADDRESS_CR_CORE0_ITCM_CORE_BASE, BSP_ADDRESS_CR_CORE0_ITCM_AXI_BASE, BSP_ADDRESS_CR_CORE0_ITCM_SIZE}, \
    {BSP_ADDRESS_CR_CORE0_DTCM_CORE_BASE, BSP_ADDRESS_CR_CORE0_DTCM_AXI_BASE, BSP_ADDRESS_CR_CORE0_DTCM_SIZE}
#elif (1 == BSP_CR8_CORE_NUM)
 #define BSP_ADDRESS_CONVERT_TABLE_BODY                                                                        \
    {BSP_ADDRESS_CR_CORE1_ITCM_CORE_BASE, BSP_ADDRESS_CR_CORE1_ITCM_AXI_BASE, BSP_ADDRESS_CR_CORE1_ITCM_SIZE}, \
    {BSP_ADDRESS_CR_CORE1_DTCM_CORE_BASE, BSP_ADDRESS_CR_CORE1_DTCM_AXI_BASE, BSP_ADDRESS_CR_CORE1_DTCM_SIZE}
#else
 #define BSP_ADDRESS_CONVERT_TABLE_BODY \
    {BSP_PRV_ADDRESS_TABLE_END, BSP_PRV_ADDRESS_TABLE_END, BSP_PRV_ADDRESS_TABLE_END}
#endif

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * @addtogroup BSP_MPU_RZV2H
 * @{
 *********************************************************************************************************************/

/** @} (end addtogroup BSP_MPU_RZV2H) */

#endif                                 /* BSP_SLAVE_ADDRESS_H */
