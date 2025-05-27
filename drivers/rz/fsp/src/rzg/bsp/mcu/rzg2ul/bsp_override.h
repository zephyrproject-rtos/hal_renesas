/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RZG2UL
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RZG2UL) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Define overrides required for this MCU. */
#define BSP_OVERRIDE_ADC_INCLUDE
#define BSP_OVERRIDE_ADC_INFO_T
#define BSP_OVERRIDE_BSP_ACC_CONTROL_IP_T
#define BSP_OVERRIDE_BSP_ACCESS_CONTROL
#define BSP_OVERRIDE_BSP_PIN_T
#define BSP_OVERRIDE_BSP_PORT_T
#define BSP_OVERRIDE_DMAC_B_EXTERNAL_DETECTION_T
#define BSP_OVERRIDE_FSP_PRIV_CLOCK_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_INFO_T
#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T

/* Override definitions. */

/*==============================================
 * Access Control Level Configuration Macros Overrides
 *==============================================*/

#define BSP_ACCESS_CONTROL_REG_ACCCNT_SRAM0        (R_SYSC->SYS_SLVACCCTL0)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SRAM0        (R_SYSC_SYS_SLVACCCTL0_SRAM0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SRAM1        (R_SYSC->SYS_SLVACCCTL0)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SRAM1        (R_SYSC_SYS_SLVACCCTL0_SRAM1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC0         (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC0         (R_SYSC_SYS_SLVACCCTL1_TZC0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC1         (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC1         (R_SYSC_SYS_SLVACCCTL1_TZC1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC2         (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC2         (R_SYSC_SYS_SLVACCCTL1_TZC2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC3         (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC3         (R_SYSC_SYS_SLVACCCTL1_TZC3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CST          (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CST          (R_SYSC_SYS_SLVACCCTL1_CST_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CPG          (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CPG          (R_SYSC_SYS_SLVACCCTL1_CPG_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SYSC         (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SYSC         (R_SYSC_SYS_SLVACCCTL1_SYSC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SYC          (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SYC          (R_SYSC_SYS_SLVACCCTL1_SYS_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GIC          (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GIC          (R_SYSC_SYS_SLVACCCTL1_GIC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_IA55_IM33    (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_IA55_IM33    (R_SYSC_SYS_SLVACCCTL1_IA55_IM33_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPIO         (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPIO         (R_SYSC_SYS_SLVACCCTL1_GPIO_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MHU          (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MHU          (R_SYSC_SYS_SLVACCCTL1_MHU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DMAC0        (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DMAC0        (R_SYSC_SYS_SLVACCCTL1_DMAC0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DMAC1        (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DMAC1        (R_SYSC_SYS_SLVACCCTL1_DMAC1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM0        (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM0        (R_SYSC_SYS_SLVACCCTL2_OSTM0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM1        (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM1        (R_SYSC_SYS_SLVACCCTL2_OSTM1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM2        (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM2        (R_SYSC_SYS_SLVACCCTL2_OSTM2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT0         (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT0         (R_SYSC_SYS_SLVACCCTL2_WDT0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT2         (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT2         (R_SYSC_SYS_SLVACCCTL2_WDT2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MTU3A        (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MTU3A        (R_SYSC_SYS_SLVACCCTL2_MTU3A_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_POE3         (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_POE3         (R_SYSC_SYS_SLVACCCTL2_POE3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DDR          (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DDR          (R_SYSC_SYS_SLVACCCTL2_DDR_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CRU          (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CRU          (R_SYSC_SYS_SLVACCCTL3_CRU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ISU          (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ISU          (R_SYSC_SYS_SLVACCCTL3_ISU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_LCDC         (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_LCDC         (R_SYSC_SYS_SLVACCCTL3_LCDC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_USBT         (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_USBT         (R_SYSC_SYS_SLVACCCTL3_USBT_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_USB20        (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_USB20        (R_SYSC_SYS_SLVACCCTL3_USB20_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_USB21        (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_USB21        (R_SYSC_SYS_SLVACCCTL3_USB21_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI0        (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI0        (R_SYSC_SYS_SLVACCCTL3_SDHI0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI1        (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI1        (R_SYSC_SYS_SLVACCCTL3_SDHI1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ETH0         (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ETH0         (R_SYSC_SYS_SLVACCCTL3_ETH0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ETH1         (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ETH1         (R_SYSC_SYS_SLVACCCTL3_ETH1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C0         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C0         (R_SYSC_SYS_SLVACCCTL4_I2C0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C1         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C1         (R_SYSC_SYS_SLVACCCTL4_I2C1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C2         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C2         (R_SYSC_SYS_SLVACCCTL4_I2C2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C3         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C3         (R_SYSC_SYS_SLVACCCTL4_I2C3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CANFD        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CANFD        (R_SYSC_SYS_SLVACCCTL4_CANFD_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI         (R_SYSC_SYS_SLVACCCTL4_RSPI_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF0        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF0        (R_SYSC_SYS_SLVACCCTL4_SCIF0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF1        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF1        (R_SYSC_SYS_SLVACCCTL4_SCIF1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF2        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF2        (R_SYSC_SYS_SLVACCCTL4_SCIF2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF3        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF3        (R_SYSC_SYS_SLVACCCTL4_SCIF3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF4        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF4        (R_SYSC_SYS_SLVACCCTL4_SCIF4_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCI0         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCI0         (R_SYSC_SYS_SLVACCCTL4_SCI0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCI1         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCI1         (R_SYSC_SYS_SLVACCCTL4_SCI1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_IRDA         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_IRDA         (R_SYSC_SYS_SLVACCCTL4_IRDA_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF         (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF         (R_SYSC_SYS_SLVACCCTL5_SSIF_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SRC          (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SRC          (R_SYSC_SYS_SLVACCCTL5_SRC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ADC          (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ADC          (R_SYSC_SYS_SLVACCCTL6_ADC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TSU          (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TSU          (R_SYSC_SYS_SLVACCCTL6_TSU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OTP          (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OTP          (R_SYSC_SYS_SLVACCCTL7_OTP_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CM33         (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CM33         (R_SYSC_SYS_SLVACCCTL8_CM33_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CA55         (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CA55         (R_SYSC_SYS_SLVACCCTL8_CA55_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_LSI          (R_SYSC->SYS_SLVACCCTL10)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_LSI          (R_SYSC_SYS_SLVACCCTL10_LSI_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_AOF          (R_SYSC->SYS_SLVACCCTL12)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_AOF          (R_SYSC_SYS_SLVACCCTL12_AOF_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_LP           (R_SYSC->SYS_SLVACCCTL13)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_LP           (R_SYSC_SYS_SLVACCCTL13_LP_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPREG        (R_SYSC->SYS_SLVACCCTL14)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPREG        (R_SYSC_SYS_SLVACCCTL14_GPREG_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_IPCONT       (R_SYSC->SYS_SLVACCCTL16)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_IPCONT       (R_SYSC_SYS_SLVACCCTL16_IPCONT_SL_Pos)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/*==============================================
 * BSP-Related Definitions Overrides
 *==============================================*/

/** Superset list of all possible IO ports. */
typedef enum e_bsp_io_port
{
    BSP_IO_PORT_00 = 0x0000,           /* IO port 0 */
    BSP_IO_PORT_01 = 0x0100,           /* IO port 1 */
    BSP_IO_PORT_02 = 0x0200,           /* IO port 2 */
    BSP_IO_PORT_03 = 0x0300,           /* IO port 3 */
    BSP_IO_PORT_04 = 0x0400,           /* IO port 4 */
    BSP_IO_PORT_05 = 0x0500,           /* IO port 5 */
    BSP_IO_PORT_06 = 0x0600,           /* IO port 6 */
    BSP_IO_PORT_07 = 0x0700,           /* IO port 7 */
    BSP_IO_PORT_08 = 0x0800,           /* IO port 8 */
    BSP_IO_PORT_09 = 0x0900,           /* IO port 9 */
    BSP_IO_PORT_10 = 0x0A00,           /* IO port 10 */
    BSP_IO_PORT_11 = 0x0B00,           /* IO port 11 */
    BSP_IO_PORT_12 = 0x0C00,           /* IO port 12 */
    BSP_IO_PORT_13 = 0x0D00,           /* IO port 13 */
    BSP_IO_PORT_14 = 0x0E00,           /* IO port 14 */
    BSP_IO_PORT_15 = 0x0F00,           /* IO port 15 */
    BSP_IO_PORT_16 = 0x1000,           /* IO port 16 */
    BSP_IO_PORT_17 = 0x1100,           /* IO port 17 */
    BSP_IO_PORT_18 = 0x1200,           /* IO port 18 */
} bsp_io_port_t;

/** Superset list of all possible IO port pins. */
typedef enum e_bsp_io_port_pin_t
{
    BSP_IO_PORT_00_PIN_00 = 0x0000,     /* IO port 0 pin 0 */
    BSP_IO_PORT_00_PIN_01 = 0x0001,     /* IO port 0 pin 1 */
    BSP_IO_PORT_00_PIN_02 = 0x0002,     /* IO port 0 pin 2 */
    BSP_IO_PORT_00_PIN_03 = 0x0003,     /* IO port 0 pin 3 */

    BSP_IO_PORT_01_PIN_00 = 0x0100,     /* IO port 1 pin 0 */
    BSP_IO_PORT_01_PIN_01 = 0x0101,     /* IO port 1 pin 1 */
    BSP_IO_PORT_01_PIN_02 = 0x0102,     /* IO port 1 pin 2 */
    BSP_IO_PORT_01_PIN_03 = 0x0103,     /* IO port 1 pin 3 */
    BSP_IO_PORT_01_PIN_04 = 0x0104,     /* IO port 1 pin 4 */

    BSP_IO_PORT_02_PIN_00 = 0x0200,     /* IO port 2 pin 0 */
    BSP_IO_PORT_02_PIN_01 = 0x0201,     /* IO port 2 pin 1 */
    BSP_IO_PORT_02_PIN_02 = 0x0202,     /* IO port 2 pin 2 */
    BSP_IO_PORT_02_PIN_03 = 0x0203,     /* IO port 2 pin 3 */

    BSP_IO_PORT_03_PIN_00 = 0x0300,     /* IO port 3 pin 0 */
    BSP_IO_PORT_03_PIN_01 = 0x0301,     /* IO port 3 pin 1 */
    BSP_IO_PORT_03_PIN_02 = 0x0302,     /* IO port 3 pin 2 */
    BSP_IO_PORT_03_PIN_03 = 0x0303,     /* IO port 3 pin 3 */

    BSP_IO_PORT_04_PIN_00 = 0x0400,     /* IO port 4 pin 0 */
    BSP_IO_PORT_04_PIN_01 = 0x0401,     /* IO port 4 pin 1 */
    BSP_IO_PORT_04_PIN_02 = 0x0402,     /* IO port 4 pin 2 */
    BSP_IO_PORT_04_PIN_03 = 0x0403,     /* IO port 4 pin 3 */
    BSP_IO_PORT_04_PIN_04 = 0x0404,     /* IO port 4 pin 4 */
    BSP_IO_PORT_04_PIN_05 = 0x0405,     /* IO port 4 pin 5 */

    BSP_IO_PORT_05_PIN_00 = 0x0500,     /* IO port 5 pin 0 */
    BSP_IO_PORT_05_PIN_01 = 0x0501,     /* IO port 5 pin 1 */
    BSP_IO_PORT_05_PIN_02 = 0x0502,     /* IO port 5 pin 2 */
    BSP_IO_PORT_05_PIN_03 = 0x0503,     /* IO port 5 pin 3 */
    BSP_IO_PORT_05_PIN_04 = 0x0504,     /* IO port 5 pin 4 */

    BSP_IO_PORT_06_PIN_00 = 0x0600,     /* IO port 6 pin 0 */
    BSP_IO_PORT_06_PIN_01 = 0x0601,     /* IO port 6 pin 1 */
    BSP_IO_PORT_06_PIN_02 = 0x0602,     /* IO port 6 pin 2 */
    BSP_IO_PORT_06_PIN_03 = 0x0603,     /* IO port 6 pin 3 */
    BSP_IO_PORT_06_PIN_04 = 0x0604,     /* IO port 6 pin 4 */

    BSP_IO_PORT_07_PIN_00 = 0x0700,     /* IO port 7 pin 0 */
    BSP_IO_PORT_07_PIN_01 = 0x0701,     /* IO port 7 pin 1 */
    BSP_IO_PORT_07_PIN_02 = 0x0702,     /* IO port 7 pin 2 */
    BSP_IO_PORT_07_PIN_03 = 0x0703,     /* IO port 7 pin 3 */
    BSP_IO_PORT_07_PIN_04 = 0x0704,     /* IO port 7 pin 4 */

    BSP_IO_PORT_08_PIN_00 = 0x0800,     /* IO port 8 pin 0 */
    BSP_IO_PORT_08_PIN_01 = 0x0801,     /* IO port 8 pin 1 */
    BSP_IO_PORT_08_PIN_02 = 0x0802,     /* IO port 8 pin 2 */
    BSP_IO_PORT_08_PIN_03 = 0x0803,     /* IO port 8 pin 3 */
    BSP_IO_PORT_08_PIN_04 = 0x0804,     /* IO port 8 pin 4 */

    BSP_IO_PORT_09_PIN_00 = 0x0900,     /* IO port 9 pin 0 */
    BSP_IO_PORT_09_PIN_01 = 0x0901,     /* IO port 9 pin 1 */
    BSP_IO_PORT_09_PIN_02 = 0x0902,     /* IO port 9 pin 2 */
    BSP_IO_PORT_09_PIN_03 = 0x0903,     /* IO port 9 pin 3 */

    BSP_IO_PORT_10_PIN_00 = 0x0A00,     /* IO port 10 pin 0 */
    BSP_IO_PORT_10_PIN_01 = 0x0A01,     /* IO port 10 pin 1 */
    BSP_IO_PORT_10_PIN_02 = 0x0A02,     /* IO port 10 pin 2 */
    BSP_IO_PORT_10_PIN_03 = 0x0A03,     /* IO port 10 pin 3 */
    BSP_IO_PORT_10_PIN_04 = 0x0A04,     /* IO port 10 pin 4 */

    BSP_IO_PORT_11_PIN_00 = 0x0B00,     /* IO port 11 pin 0 */
    BSP_IO_PORT_11_PIN_01 = 0x0B01,     /* IO port 11 pin 1 */
    BSP_IO_PORT_11_PIN_02 = 0x0B02,     /* IO port 11 pin 2 */
    BSP_IO_PORT_11_PIN_03 = 0x0B03,     /* IO port 11 pin 3 */

    BSP_IO_PORT_12_PIN_00 = 0x0C00,     /* IO port 12 pin 0 */
    BSP_IO_PORT_12_PIN_01 = 0x0C01,     /* IO port 12 pin 1 */

    BSP_IO_PORT_13_PIN_00 = 0x0D00,     /* IO port 13 pin 0 */
    BSP_IO_PORT_13_PIN_01 = 0x0D01,     /* IO port 13 pin 1 */
    BSP_IO_PORT_13_PIN_02 = 0x0D02,     /* IO port 13 pin 2 */
    BSP_IO_PORT_13_PIN_03 = 0x0D03,     /* IO port 13 pin 3 */
    BSP_IO_PORT_13_PIN_04 = 0x0D04,     /* IO port 13 pin 4 */

    BSP_IO_PORT_14_PIN_00 = 0x0E00,     /* IO port 14 pin 0 */
    BSP_IO_PORT_14_PIN_01 = 0x0E01,     /* IO port 14 pin 1 */
    BSP_IO_PORT_14_PIN_02 = 0x0E02,     /* IO port 14 pin 2 */

    BSP_IO_PORT_15_PIN_00 = 0x0F00,     /* IO port 15 pin 0 */
    BSP_IO_PORT_15_PIN_01 = 0x0F01,     /* IO port 15 pin 1 */
    BSP_IO_PORT_15_PIN_02 = 0x0F02,     /* IO port 15 pin 2 */
    BSP_IO_PORT_15_PIN_03 = 0x0F03,     /* IO port 15 pin 3 */

    BSP_IO_PORT_16_PIN_00 = 0x1000,     /* IO port 16 pin 0 */
    BSP_IO_PORT_16_PIN_01 = 0x1001,     /* IO port 16 pin 1 */

    BSP_IO_PORT_17_PIN_00 = 0x1100,     /* IO port 17 pin 0 */
    BSP_IO_PORT_17_PIN_01 = 0x1101,     /* IO port 17 pin 1 */
    BSP_IO_PORT_17_PIN_02 = 0x1102,     /* IO port 17 pin 2 */
    BSP_IO_PORT_17_PIN_03 = 0x1103,     /* IO port 17 pin 3 */

    BSP_IO_PORT_18_PIN_00 = 0x1200,     /* IO port 18 pin 0 */
    BSP_IO_PORT_18_PIN_01 = 0x1201,     /* IO port 18 pin 1 */
    BSP_IO_PORT_18_PIN_02 = 0x1202,     /* IO port 18 pin 2 */
    BSP_IO_PORT_18_PIN_03 = 0x1203,     /* IO port 18 pin 3 */
    BSP_IO_PORT_18_PIN_04 = 0x1204,     /* IO port 18 pin 4 */
    BSP_IO_PORT_18_PIN_05 = 0x1205,     /* IO port 18 pin 5 */

    /* Special purpose port */
    BSP_IO_NMI = 0xFFFF0100,            /* NMI */

    BSP_IO_TMS_SWDIO = 0xFFFF0200,      /* TMS_SWDIO */

    BSP_IO_TDO_SWO = 0xFFFF0300,        /* TDO_SWO */

    BSP_IO_AUDIO_CLK1 = 0xFFFF0400,     /* AUDIO_CLK1 */
    BSP_IO_AUDIO_CLK2 = 0xFFFF0401,     /* AUDIO_CLK2 */

    BSP_IO_SD0_CLK   = 0xFFFF0600,      /* CD0_CLK */
    BSP_IO_SD0_CMD   = 0xFFFF0601,      /* CD0_CMD */
    BSP_IO_SD0_RST_N = 0xFFFF0602,      /* CD0_RST_N */

    BSP_IO_SD0_DATA0 = 0xFFFF0700,      /* SD0_DATA0 */
    BSP_IO_SD0_DATA1 = 0xFFFF0701,      /* SD0_DATA1 */
    BSP_IO_SD0_DATA2 = 0xFFFF0702,      /* SD0_DATA2 */
    BSP_IO_SD0_DATA3 = 0xFFFF0703,      /* SD0_DATA3 */
    BSP_IO_SD0_DATA4 = 0xFFFF0704,      /* SD0_DATA4 */
    BSP_IO_SD0_DATA5 = 0xFFFF0705,      /* SD0_DATA5 */
    BSP_IO_SD0_DATA6 = 0xFFFF0706,      /* SD0_DATA6 */
    BSP_IO_SD0_DATA7 = 0xFFFF0707,      /* SD0_DATA7 */

    BSP_IO_SD1_CLK = 0xFFFF0800,        /* SD1_CLK */
    BSP_IO_SD1_CMD = 0xFFFF0801,        /* SD1_CMD */

    BSP_IO_SD1_DATA0 = 0xFFFF0900,      /* SD1_DATA0 */
    BSP_IO_SD1_DATA1 = 0xFFFF0901,      /* SD1_DATA1 */
    BSP_IO_SD1_DATA2 = 0xFFFF0902,      /* SD1_DATA2 */
    BSP_IO_SD1_DATA3 = 0xFFFF0903,      /* SD1_DATA3 */

    BSP_IO_QSPI0_SPCLK = 0xFFFF0A00,    /* QSPI0_SPCLK */
    BSP_IO_QSPI0_IO0   = 0xFFFF0A01,    /* QSPI0_IO0 */
    BSP_IO_QSPI0_IO1   = 0xFFFF0A02,    /* QSPI0_IO1 */
    BSP_IO_QSPI0_IO2   = 0xFFFF0A03,    /* QSPI0_IO2 */
    BSP_IO_QSPI0_IO3   = 0xFFFF0A04,    /* QSPI0_IO3 */
    BSP_IO_QSPI0_SSL   = 0xFFFF0A05,    /* QSPI0_SSL */

    BSP_IO_QSPI_RESET_N = 0xFFFF0C00,   /* QSPI_RESET_N */
    BSP_IO_QSPI_WP_N    = 0xFFFF0C01,   /* QSPI_WP_N */

    BSP_IO_WDTOVF_PERROUT = 0xFFFF0D00, /* WDTOVF_PERROUT */

    BSP_IO_RIIC0_SDA = 0xFFFF0E00,      /* RIIC0_SDA */
    BSP_IO_RIIC0_SCL = 0xFFFF0E01,      /* RIIC0_SCL */
    BSP_IO_RIIC1_SDA = 0xFFFF0E02,      /* RIIC1_SDA */
    BSP_IO_RIIC1_SCL = 0xFFFF0E03,      /* RIIC1_SCL */
} bsp_io_port_pin_t;

/*==============================================
 * DMAC_B External Detection Overrides
 *==============================================*/

 /** Detection method of the external DMA request signal. See RZ/T2M hardware manual Table 14.19 DMA Transfer Request Detection Operation Setting Table. */
typedef enum e_dmac_b_external_detection
{
    DMAC_B_EXTERNAL_DETECTION_NO_DETECTION = 0,   ///< Not using hardware detection.
} dmac_b_external_detection_t;

/** access control. */
typedef enum e_acc_control_ip
{
    ACCCNT_SRAM0 = 0,
    ACCCNT_SRAM1,
    ACCCNT_TZC0,
    ACCCNT_TZC1,
    ACCCNT_TZC2,
    ACCCNT_TZC3,
    ACCCNT_CST,
    ACCCNT_CPG,
    ACCCNT_SYSC,
    ACCCNT_SYC,
    ACCCNT_GIC,
    ACCCNT_IA55_IM33,
    ACCCNT_GPIO,
    ACCCNT_MHU,
    ACCCNT_DMAC0,
    ACCCNT_DMAC1,
    ACCCNT_OSTM0,
    ACCCNT_OSTM1,
    ACCCNT_OSTM2,
    ACCCNT_WDT0,
    ACCCNT_WDT2,
    ACCCNT_MTU3A,
    ACCCNT_POE3,
    ACCCNT_DDR,
    ACCCNT_CRU,
    ACCCNT_ISU,
    ACCCNT_LCDC,
    ACCCNT_USBT,
    ACCCNT_USB20,
    ACCCNT_USB21,
    ACCCNT_SDHI0,
    ACCCNT_SDHI1,
    ACCCNT_ETH0,
    ACCCNT_ETH1,
    ACCCNT_I2C0,
    ACCCNT_I2C1,
    ACCCNT_I2C2,
    ACCCNT_I2C3,
    ACCCNT_CANFD,
    ACCCNT_RSPI,
    ACCCNT_SCIF0,
    ACCCNT_SCIF1,
    ACCCNT_SCIF2,
    ACCCNT_SCIF3,
    ACCCNT_SCIF4,
    ACCCNT_SCI0,
    ACCCNT_SCI1,
    ACCCNT_IRDA,
    ACCCNT_SSIF,
    ACCCNT_SRC,
    ACCCNT_ADC,
    ACCCNT_TSU,
    ACCCNT_OTP,
    ACCCNT_CM33,
    ACCCNT_CA55,
    ACCCNT_LSI,
    ACCCNT_AOF,
    ACCCNT_LP,
    ACCCNT_GPREG,
    ACCCNT_IPCONT,
} fsp_acc_control_ip_t;

/* Private enum used in R_FSP_SystemClockHzGet. */
typedef enum e_fsp_priv_clock
{
    FSP_PRIV_CLOCK_ICLK = 0,           /* Cortex-A55 Clock */
    FSP_PRIV_CLOCK_I2CLK,              /* Cortex-M33 Clock */
    FSP_PRIV_CLOCK_S0CLK,              /* DDR-PHY Clock */
    FSP_PRIV_CLOCK_SPI0CLK,            /* SPI0 Clock */
    FSP_PRIV_CLOCK_SPI1CLK,            /* SPI1 Clock */
    FSP_PRIV_CLOCK_SD0CLK,             /* SDH0 Clock */
    FSP_PRIV_CLOCK_SD1CLK,             /* SDH1 Clock */
    FSP_PRIV_CLOCK_M0CLK,              /* VCP, LCDC Clock */
    FSP_PRIV_CLOCK_M2CLK,              /* CRU, MIPI-DSI Clock */
    FSP_PRIV_CLOCK_M3CLK,              /* MIPI-DSI, LCDC Clock */
    FSP_PRIV_CLOCK_HPCLK,              /* Ethernet Clock */
    FSP_PRIV_CLOCK_TSUCLK,             /* TSU Clock */
    FSP_PRIV_CLOCK_ZTCLK,              /* JAUTH Clock */
    FSP_PRIV_CLOCK_P0CLK,              /* APB-BUS Clock */
    FSP_PRIV_CLOCK_P1CLK,              /* AXI-BUS Clock */
    FSP_PRIV_CLOCK_P2CLK,              /* P2CLK */
    FSP_PRIV_CLOCK_ATCLK,              /* ATCLK */
    FSP_PRIV_CLOCK_OSCCLK,             /* OSC Clock */
    FSP_PRIV_CLOCK_NUM,
} fsp_priv_clock_t;

/*==============================================
 * Transfer API Overrides
 *==============================================*/

/** Transfer mode describes what will happen when a transfer request occurs. */
typedef enum e_transfer_mode
{
    /** Normal mode. */
    TRANSFER_MODE_NORMAL = 0,

    /** Block mode. */
    TRANSFER_MODE_BLOCK = 1
} transfer_mode_t;

/** Transfer size specifies the size of each individual transfer. */
typedef enum e_transfer_size
{
    TRANSFER_SIZE_1_BYTE   = 0,        ///< Each transfer transfers a 8-bit value
    TRANSFER_SIZE_2_BYTE   = 1,        ///< Each transfer transfers a 16-bit value
    TRANSFER_SIZE_4_BYTE   = 2,        ///< Each transfer transfers a 32-bit value
    TRANSFER_SIZE_8_BYTE   = 3,        ///< Each transfer transfers a 64-bit value
    TRANSFER_SIZE_16_BYTE  = 4,        ///< Each transfer transfers a 128-bit value
    TRANSFER_SIZE_32_BYTE  = 5,        ///< Each transfer transfers a 256-bit value
    TRANSFER_SIZE_64_BYTE  = 6,        ///< Each transfer transfers a 512-bit value
    TRANSFER_SIZE_128_BYTE = 7         ///< Each transfer transfers a 1024-bit value
} transfer_size_t;

/** Address mode specifies whether to modify (increment or decrement) pointer after each transfer. */
typedef enum e_transfer_addr_mode
{
    /** Address pointer is incremented by associated @ref transfer_size_t after each transfer. */
    TRANSFER_ADDR_MODE_INCREMENTED = 0,

    /** Address pointer remains fixed after each transfer. */
    TRANSFER_ADDR_MODE_FIXED = 1
} transfer_addr_mode_t;

typedef struct st_transfer_info
{
    /** Select what happens to destination address after each transfer. */
    transfer_addr_mode_t dest_addr_mode;

    /** Select what happens to source address after each transfer. */
    transfer_addr_mode_t src_addr_mode;

    /** Select mode from @ref transfer_mode_t. */
    transfer_mode_t mode;

    /** Source address. */
    void const * volatile p_src;

    /** Destination address. */
    void * volatile p_dest;

    /** The total number of transfer bytes. */
    volatile uint32_t length;

    /** Select source data size to transfer at once. */
    transfer_size_t src_size;

    /** Select destination data size to transfer at once. */
    transfer_size_t dest_size;

    /** Next1 Register set settings */
    void const * p_next1_src;
    void       * p_next1_dest;
    uint32_t     next1_length;
} transfer_info_t;

/*==============================================
 * ADC API Overrides
 *==============================================*/

/** ADC Information Structure for Transfer Interface */
typedef struct st_adc_info
{
    volatile const void * p_address;         ///< The address to start reading the data from
    uint32_t              length;            ///< The total number of transfers to read
    transfer_size_t       transfer_size;     ///< The size of each transfer
    uint32_t              calibration_data1; ///< Temperature sensor calibration data1
    uint32_t              calibration_data2; ///< Temperature sensor calibration data2
} adc_info_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
