/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_crc_snoop.h
 * Version      : 1.00
 * Description  : bsp_crc_snoop header
 *********************************************************************************************************************/

#ifndef BSP_CRC_SNOOP_H
#define BSP_CRC_SNOOP_H

/**********************************************************************************************************************
 * Macro definitions
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

/**********************************************************************************************************************
 * @addtogroup BSP_MPU_RZV2N
 * @{
 *********************************************************************************************************************/

/* Snoop Address */
#define CRC_SNOOP_ADDRESS_NONE                (0xFFFF)
#define CRC_SNOOP_ADDRESS_SPI_B0_SPDR_TX      (0x0000)
#define CRC_SNOOP_ADDRESS_SPI_B0_SPDR_RX      (0x0000)
#define CRC_SNOOP_ADDRESS_SPI_B1_SPDR_TX      (0x0400)
#define CRC_SNOOP_ADDRESS_SPI_B1_SPDR_RX      (0x0400)
#define CRC_SNOOP_ADDRESS_SPI_B2_SPDR_TX      (0x0800)
#define CRC_SNOOP_ADDRESS_SPI_B2_SPDR_RX      (0x0800)
#define CRC_SNOOP_ADDRESS_SCI_B0_TDR          (0x0C04)
#define CRC_SNOOP_ADDRESS_SCI_B1_TDR          (0x1004)
#define CRC_SNOOP_ADDRESS_SCI_B2_TDR          (0x1404)
#define CRC_SNOOP_ADDRESS_SCI_B3_TDR          (0x1804)
#define CRC_SNOOP_ADDRESS_SCI_B4_TDR          (0x1C04)
#define CRC_SNOOP_ADDRESS_SCI_B5_TDR          (0x2004)
#define CRC_SNOOP_ADDRESS_SCI_B6_TDR          (0x2404)
#define CRC_SNOOP_ADDRESS_SCI_B7_TDR          (0x2804)
#define CRC_SNOOP_ADDRESS_SCI_B8_TDR          (0x2C04)
#define CRC_SNOOP_ADDRESS_SCI_B9_TDR          (0x3004)
#define CRC_SNOOP_ADDRESS_SCI_B0_RDR          (0x0C00)
#define CRC_SNOOP_ADDRESS_SCI_B1_RDR          (0x1000)
#define CRC_SNOOP_ADDRESS_SCI_B2_RDR          (0x1400)
#define CRC_SNOOP_ADDRESS_SCI_B3_RDR          (0x1800)
#define CRC_SNOOP_ADDRESS_SCI_B4_RDR          (0x1C00)
#define CRC_SNOOP_ADDRESS_SCI_B5_RDR          (0x2000)
#define CRC_SNOOP_ADDRESS_SCI_B6_RDR          (0x2400)
#define CRC_SNOOP_ADDRESS_SCI_B7_RDR          (0x2800)
#define CRC_SNOOP_ADDRESS_SCI_B8_RDR          (0x2C00)
#define CRC_SNOOP_ADDRESS_SCI_B9_RDR          (0x3000)

/* Snoop Direction */
#define CRC_SNOOP_DIRECTION_SPI_B0_SPDR_TX    (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SPI_B0_SPDR_RX    (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SPI_B1_SPDR_TX    (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SPI_B1_SPDR_RX    (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SPI_B2_SPDR_TX    (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SPI_B2_SPDR_RX    (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B0_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B1_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B2_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B3_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B4_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B5_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B6_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B7_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B8_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B9_TDR        (CRC_SNOOP_DIRECTION_TRANSMIT)
#define CRC_SNOOP_DIRECTION_SCI_B0_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B1_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B2_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B3_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B4_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B5_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B6_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B7_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B8_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)
#define CRC_SNOOP_DIRECTION_SCI_B9_RDR        (CRC_SNOOP_DIRECTION_RECEIVE)

/** @} (end addtogroup BSP_MPU_RZV2N) */

#endif                                 /* BSP_CRC_SNOOP_H */
