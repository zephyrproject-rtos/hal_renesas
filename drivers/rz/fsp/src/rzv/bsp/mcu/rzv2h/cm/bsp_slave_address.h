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
#define BSP_ADDRESS_OFFSET_MASK                    (0x0FFFFFFF)

#define BSP_ADDRESS_CM_SRAM_CODE_SECURE_BASE       (0x00000000)
#define BSP_ADDRESS_CM_SRAM_CODE_NONSECURE_BASE    (0x10000000)
#define BSP_ADDRESS_CM_SRAM_DATA_SECURE_BASE       (0x20000000)
#define BSP_ADDRESS_CM_SRAM_DATA_NONSECURE_BASE    (0x30000000)
#define BSP_ADDRESS_CA_SRAM_BASE                   (0x00000000)
#define BSP_ADDRESS_SRAM_SIZE                      (0x10000000)

#define BSP_ADDRESS_CM_IOREG_SECURE_BASE           (0x40000000)
#define BSP_ADDRESS_CM_IOREG_NONSECURE_BASE        (0x50000000)
#define BSP_ADDRESS_CA_IOREG_BASE                  (0x10000000)
#define BSP_ADDRESS_IOREG_SIZE                     (0x10000000)

#define BSP_ADDRESS_CM_SPI_SECURE_BASE             (0x60000000)
#define BSP_ADDRESS_CM_SPI_NONSECURE_BASE          (0x70000000)
#define BSP_ADDRESS_CA_SPI_BASE                    (0x20000000)
#define BSP_ADDRESS_SPI_SIZE                       (0x10000000)

#define BSP_ADDRESS_CM_DDR_SECURE_BASE             (0x80000000)
#define BSP_ADDRESS_CM_DDR_NONSECURE_BASE          (0x90000000)
#define BSP_ADDRESS_CA_DDR_BASE                    (0x40000000)
#define BSP_ADDRESS_DDR_SIZE                       (0x10000000)

#define BSP_ADDRESS_CM_PCIE_SECURE_BASE            (0xA0000000)
#define BSP_ADDRESS_CM_PCIE_NONSECURE_BASE         (0xB0000000)
#define BSP_ADDRESS_CA_PCIE_BASE                   (0x30000000)
#define BSP_ADDRESS_PCIE_SIZE                      (0x10000000)

#define BSP_ADDRESS_CONVERT_TABLE_BODY                                                          \
    {BSP_ADDRESS_CM_SRAM_CODE_SECURE_BASE, BSP_ADDRESS_CA_SRAM_BASE, BSP_ADDRESS_SRAM_SIZE},    \
    {BSP_ADDRESS_CM_SRAM_CODE_NONSECURE_BASE, BSP_ADDRESS_CA_SRAM_BASE, BSP_ADDRESS_SRAM_SIZE}, \
    {BSP_ADDRESS_CM_SRAM_DATA_SECURE_BASE, BSP_ADDRESS_CA_SRAM_BASE, BSP_ADDRESS_SRAM_SIZE},    \
    {BSP_ADDRESS_CM_SRAM_DATA_NONSECURE_BASE, BSP_ADDRESS_CA_SRAM_BASE, BSP_ADDRESS_SRAM_SIZE}, \
    {BSP_ADDRESS_CM_IOREG_SECURE_BASE, BSP_ADDRESS_CA_IOREG_BASE, BSP_ADDRESS_IOREG_SIZE},      \
    {BSP_ADDRESS_CM_IOREG_NONSECURE_BASE, BSP_ADDRESS_CA_IOREG_BASE, BSP_ADDRESS_IOREG_SIZE},   \
    {BSP_ADDRESS_CM_SPI_SECURE_BASE, BSP_ADDRESS_CA_SPI_BASE, BSP_ADDRESS_SPI_SIZE},            \
    {BSP_ADDRESS_CM_SPI_NONSECURE_BASE, BSP_ADDRESS_CA_SPI_BASE, BSP_ADDRESS_SPI_SIZE},         \
    {BSP_ADDRESS_CM_DDR_SECURE_BASE, BSP_ADDRESS_CA_DDR_BASE, BSP_ADDRESS_DDR_SIZE},            \
    {BSP_ADDRESS_CM_DDR_NONSECURE_BASE, BSP_ADDRESS_CA_DDR_BASE, BSP_ADDRESS_DDR_SIZE},         \
    {BSP_ADDRESS_CM_PCIE_SECURE_BASE, BSP_ADDRESS_CA_PCIE_BASE, BSP_ADDRESS_PCIE_SIZE},         \
    {BSP_ADDRESS_CM_PCIE_NONSECURE_BASE, BSP_ADDRESS_CA_PCIE_BASE, BSP_ADDRESS_PCIE_SIZE}

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
