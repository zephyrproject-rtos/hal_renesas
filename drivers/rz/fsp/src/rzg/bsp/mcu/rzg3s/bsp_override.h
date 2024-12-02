/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RZG3S
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RZG3S) */

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
#define BSP_OVERRIDE_FSP_IP_T
#define BSP_OVERRIDE_FSP_PRIV_CLOCK_T
#define BSP_OVERRIDE_IOPORT_PERIPHERAL_T
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
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SRAM2        (R_SYSC->SYS_SLVACCCTL0)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SRAM2        (R_SYSC_SYS_SLVACCCTL0_SRAM2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SRAM3        (R_SYSC->SYS_SLVACCCTL0)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SRAM3        (R_SYSC_SYS_SLVACCCTL0_SRAM3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC0         (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC0         (R_SYSC_SYS_SLVACCCTL2_TZC0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC1         (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC1         (R_SYSC_SYS_SLVACCCTL2_TZC1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC2         (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC2         (R_SYSC_SYS_SLVACCCTL2_TZC2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC3         (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC3         (R_SYSC_SYS_SLVACCCTL2_TZC3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC5         (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC5         (R_SYSC_SYS_SLVACCCTL2_TZC5_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC6         (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC6         (R_SYSC_SYS_SLVACCCTL2_TZC6_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CST          (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CST          (R_SYSC_SYS_SLVACCCTL3_CST_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CPG          (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CPG          (R_SYSC_SYS_SLVACCCTL3_CPG_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SYSC         (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SYSC         (R_SYSC_SYS_SLVACCCTL3_SYSC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SYC          (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SYC          (R_SYSC_SYS_SLVACCCTL3_SYC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GIC          (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GIC          (R_SYSC_SYS_SLVACCCTL3_GIC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_IA55_IM33    (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_IA55_IM33    (R_SYSC_SYS_SLVACCCTL3_IA55_IM33_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPIO         (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPIO         (R_SYSC_SYS_SLVACCCTL3_GPIO_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MHU          (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MHU          (R_SYSC_SYS_SLVACCCTL3_MHU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DMAC0        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DMAC0        (R_SYSC_SYS_SLVACCCTL4_DMAC0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DMAC1        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DMAC1        (R_SYSC_SYS_SLVACCCTL4_DMAC1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM0        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM0        (R_SYSC_SYS_SLVACCCTL4_OSTM0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM1        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM1        (R_SYSC_SYS_SLVACCCTL4_OSTM1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM2        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM2        (R_SYSC_SYS_SLVACCCTL4_OSTM2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM3        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM3        (R_SYSC_SYS_SLVACCCTL4_OSTM3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM4        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM4        (R_SYSC_SYS_SLVACCCTL4_OSTM4_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM5        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM5        (R_SYSC_SYS_SLVACCCTL4_OSTM5_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM6        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM6        (R_SYSC_SYS_SLVACCCTL4_OSTM6_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM7        (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM7        (R_SYSC_SYS_SLVACCCTL4_OSTM7_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT0         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT0         (R_SYSC_SYS_SLVACCCTL4_WDT0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT1         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT1         (R_SYSC_SYS_SLVACCCTL4_WDT1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT2         (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT2         (R_SYSC_SYS_SLVACCCTL4_WDT2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_RTC          (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_RTC          (R_SYSC_SYS_SLVACCCTL4_RTC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MTU3A        (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MTU3A        (R_SYSC_SYS_SLVACCCTL5_MTU3A_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_POE3         (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_POE3         (R_SYSC_SYS_SLVACCCTL5_POE3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPT          (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPT          (R_SYSC_SYS_SLVACCCTL5_GPT_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_POEG         (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_POEG         (R_SYSC_SYS_SLVACCCTL5_POEG_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DDR          (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DDR          (R_SYSC_SYS_SLVACCCTL5_DDR_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_XSPI         (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_XSPI         (R_SYSC_SYS_SLVACCCTL5_XSPI_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OCTA         (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OCTA         (R_SYSC_SYS_SLVACCCTL5_OCTA_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_USBT         (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_USBT         (R_SYSC_SYS_SLVACCCTL6_USBT_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_USB20        (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_USB20        (R_SYSC_SYS_SLVACCCTL6_USB20_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_USB21        (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_USB21        (R_SYSC_SYS_SLVACCCTL6_USB21_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI0        (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI0        (R_SYSC_SYS_SLVACCCTL6_SDHI0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI1        (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI1        (R_SYSC_SYS_SLVACCCTL6_SDHI1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI2        (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI2        (R_SYSC_SYS_SLVACCCTL6_SDHI2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ETH0         (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ETH0         (R_SYSC_SYS_SLVACCCTL6_ETH0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ETH1         (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ETH1         (R_SYSC_SYS_SLVACCCTL6_ETH1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_PCIE         (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_PCIE         (R_SYSC_SYS_SLVACCCTL6_PCIE_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C0         (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C0         (R_SYSC_SYS_SLVACCCTL7_I2C0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C1         (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C1         (R_SYSC_SYS_SLVACCCTL7_I2C1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C2         (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C2         (R_SYSC_SYS_SLVACCCTL7_I2C2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C3         (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C3         (R_SYSC_SYS_SLVACCCTL7_I2C3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I3C          (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I3C          (R_SYSC_SYS_SLVACCCTL7_I3C_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CANFD        (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CANFD        (R_SYSC_SYS_SLVACCCTL7_CANFD_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI0        (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI0        (R_SYSC_SYS_SLVACCCTL7_RSPI0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI1        (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI1        (R_SYSC_SYS_SLVACCCTL7_RSPI1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI2        (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI2        (R_SYSC_SYS_SLVACCCTL7_RSPI2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI3        (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI3        (R_SYSC_SYS_SLVACCCTL7_RSPI3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI4        (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI4        (R_SYSC_SYS_SLVACCCTL7_RSPI4_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF0        (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF0        (R_SYSC_SYS_SLVACCCTL8_SCIF0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF1        (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF1        (R_SYSC_SYS_SLVACCCTL8_SCIF1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF2        (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF2        (R_SYSC_SYS_SLVACCCTL8_SCIF2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF3        (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF3        (R_SYSC_SYS_SLVACCCTL8_SCIF3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF4        (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF4        (R_SYSC_SYS_SLVACCCTL8_SCIF4_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF5        (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF5        (R_SYSC_SYS_SLVACCCTL8_SCIF5_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCI0         (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCI0         (R_SYSC_SYS_SLVACCCTL8_SCI0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCI1         (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCI1         (R_SYSC_SYS_SLVACCCTL8_SCI1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_IRDA         (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_IRDA         (R_SYSC_SYS_SLVACCCTL8_IRDA_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF0        (R_SYSC->SYS_SLVACCCTL9)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF0        (R_SYSC_SYS_SLVACCCTL9_SSIF0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF1        (R_SYSC->SYS_SLVACCCTL9)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF1        (R_SYSC_SYS_SLVACCCTL9_SSIF1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF2        (R_SYSC->SYS_SLVACCCTL9)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF2        (R_SYSC_SYS_SLVACCCTL9_SSIF2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF3        (R_SYSC->SYS_SLVACCCTL9)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF3        (R_SYSC_SYS_SLVACCCTL9_SSIF3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SRC          (R_SYSC->SYS_SLVACCCTL9)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SRC          (R_SYSC_SYS_SLVACCCTL9_SRC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SPDIF        (R_SYSC->SYS_SLVACCCTL9)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SPDIF        (R_SYSC_SYS_SLVACCCTL9_SPDIF_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_PDM          (R_SYSC->SYS_SLVACCCTL9)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_PDM          (R_SYSC_SYS_SLVACCCTL9_PDM_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ADC          (R_SYSC->SYS_SLVACCCTL10)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ADC          (R_SYSC_SYS_SLVACCCTL10_ADC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TSU          (R_SYSC->SYS_SLVACCCTL10)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TSU          (R_SYSC_SYS_SLVACCCTL10_TSU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OTP          (R_SYSC->SYS_SLVACCCTL11)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OTP          (R_SYSC_SYS_SLVACCCTL11_OTP_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_VBATT        (R_SYSC->SYS_SLVACCCTL11)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_VBATT        (R_SYSC_SYS_SLVACCCTL11_VBATT_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CA55         (R_SYSC->SYS_SLVACCCTL12)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CA55         (R_SYSC_SYS_SLVACCCTL12_CA55_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CM33         (R_SYSC->SYS_SLVACCCTL12)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CM33         (R_SYSC_SYS_SLVACCCTL12_CM33_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CM33FPU      (R_SYSC->SYS_SLVACCCTL12)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CM33FPU      (R_SYSC_SYS_SLVACCCTL12_CM33FPU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_LSI          (R_SYSC->SYS_SLVACCCTL14)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_LSI          (R_SYSC_SYS_SLVACCCTL14_LSI_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_AOF          (R_SYSC->SYS_SLVACCCTL16)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_AOF          (R_SYSC_SYS_SLVACCCTL16_AOF_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_LP           (R_SYSC->SYS_SLVACCCTL17)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_LP           (R_SYSC_SYS_SLVACCCTL17_LP_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPREG        (R_SYSC->SYS_SLVACCCTL18)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPREG        (R_SYSC_SYS_SLVACCCTL18_GPREG_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_IPCONT       (R_SYSC->SYS_SLVACCCTL20)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_IPCONT       (R_SYSC_SYS_SLVACCCTL20_IPCONT_SL_Pos)

/*==============================================
 * CPG control macros Overrides
 *==============================================*/

#define BSP_CLKON_REG_FSP_IP_GTM(channel)      (R_CPG->CPG_CLKON_GTM)
#define BSP_CLKON_BIT_FSP_IP_GTM(channel)      (1U << (R_CPG_CPG_CLKON_GTM_CLK0_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_GTM(channel)     (R_CPG->CPG_CLKMON_GTM)
#define BSP_CLKMON_BIT_FSP_IP_GTM(channel)     (1U << (R_CPG_CPG_CLKMON_GTM_CLK0_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_GTM(channel)        (R_CPG->CPG_RST_GTM)
#define BSP_RST_BIT_FSP_IP_GTM(channel)        (1U << (R_CPG_CPG_RST_GTM_UNIT0_RSTB_Pos + (channel)))
#define BSP_RSTMON_REG_FSP_IP_GTM(channel)     (R_CPG->CPG_RSTMON_GTM)
#define BSP_RSTMON_BIT_FSP_IP_GTM(channel)     (1U << (R_CPG_CPG_RSTMON_GTM_RST0_MON_Pos + (channel)))

#define BSP_CLKON_REG_FSP_IP_XSPI(channel)     (R_CPG->CPG_CLKON_SPI)
#define BSP_CLKON_BIT_FSP_IP_XSPI(channel)     (0xFU << (R_CPG_CPG_CLKON_SPI_CLK0_ON_Pos))
#define BSP_CLKMON_REG_FSP_IP_XSPI(channel)    (R_CPG->CPG_CLKMON_SPI)
#define BSP_CLKMON_BIT_FSP_IP_XSPI(channel)    (0xFU << (R_CPG_CPG_CLKMON_SPI_CLK0_MON_Pos))
#define BSP_RST_REG_FSP_IP_XSPI(channel)       (R_CPG->CPG_RST_SPI)
#define BSP_RST_BIT_FSP_IP_XSPI(channel)       (3U << (R_CPG_CPG_RST_SPI_UNIT0_RSTB_Pos))
#define BSP_RSTMON_REG_FSP_IP_XSPI(channel)    (R_CPG->CPG_RSTMON_SPI)
#define BSP_RSTMON_BIT_FSP_IP_XSPI(channel)    (3U << (R_CPG_CPG_RSTMON_SPI_RST0_MON_Pos))

#define BSP_DELAY_LOOP_CYCLES    (49)

#define BSP_MSTP_REG_FSP_IP_SCIF(channel)      *((4U >= \
                                                  channel) ? &R_CPG->CPG_BUS_MCPU2_MSTOP : &R_CPG->CPG_BUS_MCPU3_MSTOP)
#define BSP_MSTP_BIT_FSP_IP_SCIF(channel)      ((4U >=                                                                  \
                                                 channel) ? (1U << (R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP1_ON_Pos + channel)) \
                                                : (1U << R_CPG_CPG_BUS_MCPU3_MSTOP_MSTOP4_ON_Pos))

#define BSP_MSTP_REG_FSP_IP_XSPI(channel)      R_CPG->CPG_BUS_MCPU1_MSTOP
#define BSP_MSTP_BIT_FSP_IP_XSPI(channel)      (1U << R_CPG_CPG_BUS_MCPU1_MSTOP_MSTOP1_ON_Pos)

#define BSP_MSTP_REG_FSP_IP_RSPI(channel)      *((1U >= channel) ? &R_CPG->CPG_BUS_MCPU1_MSTOP    \
                                                 : ((2U == channel) ? &R_CPG->CPG_BUS_MCPU2_MSTOP \
                                                    : &R_CPG->CPG_BUS_MCPU3_MSTOP))
#define BSP_MSTP_BIT_FSP_IP_RSPI(channel)      ((1U >=                                                                   \
                                                 channel) ? (1U << (R_CPG_CPG_BUS_MCPU1_MSTOP_MSTOP14_ON_Pos + channel)) \
                                                : ((2U == channel) ? (1U << R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP0_ON_Pos)     \
                                                   : (1U <<                                                              \
                                                      (R_CPG_CPG_BUS_MCPU3_MSTOP_MSTOP2_ON_Pos +                         \
                                                       (uint32_t) (channel - 3)))))

/*==============================================
 * IOPORT-Related Macros Overrides
 *==============================================*/

#define OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET    (24)

/*==============================================
 * SYSC-Related Macros Overrides
 *==============================================*/

#if BSP_CURRENT_CORE == RZG3S_CORE_CM33
 #define R_BSP_IM33_DISABLE()       {R_SYSC->SYS_LP_CTL7 = R_SYSC->SYS_LP_CTL7 | \
                                                           R_SYSC_SYS_LP_CTL7_IM33_MASK_Msk;}
 #define R_BSP_IM33_ENABLE()        {R_SYSC->SYS_LP_CTL7 = R_SYSC->SYS_LP_CTL7 & \
                                                           ~R_SYSC_SYS_LP_CTL7_IM33_MASK_Msk;}
 #define R_BSP_WAIT_CM33_RESET()    {while ((R_SYSC->SYS_LP_CM33CTL0 &                      \
                                             R_SYSC_SYS_LP_CM33CTL0_SYSRESETREQ_Msk) == 0U) \
                                     { /* wait */};                                         \
}
#elif BSP_CURRENT_CORE == RZG3S_CORE_CM33_FPU
 #define R_BSP_IM33_DISABLE()       {R_SYSC->SYS_LP_CTL7 = R_SYSC->SYS_LP_CTL7 | \
                                                           R_SYSC_SYS_LP_CTL7_IM33FPU_MASK_Msk;}
 #define R_BSP_IM33_ENABLE()        {R_SYSC->SYS_LP_CTL7 = R_SYSC->SYS_LP_CTL7 & \
                                                           ~R_SYSC_SYS_LP_CTL7_IM33FPU_MASK_Msk;}
 #define R_BSP_WAIT_CM33_RESET()    {while ((R_SYSC->SYS_LP_CM33FPUCTL0 &                      \
                                             R_SYSC_SYS_LP_CM33FPUCTL0_SYSRESETREQ_Msk) == 0U) \
                                     { /* wait */};                                            \
}
#endif

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
    BSP_IO_PORT_01 = 0x1000,           /* IO port 1 */
    BSP_IO_PORT_02 = 0x1100,           /* IO port 2 */
    BSP_IO_PORT_03 = 0x1200,           /* IO port 3 */
    BSP_IO_PORT_04 = 0x1300,           /* IO port 4 */
    BSP_IO_PORT_05 = 0x0100,           /* IO port 5 */
    BSP_IO_PORT_06 = 0x0200,           /* IO port 6 */
    BSP_IO_PORT_07 = 0x1400,           /* IO port 7 */
    BSP_IO_PORT_08 = 0x1500,           /* IO port 8 */
    BSP_IO_PORT_09 = 0x1600,           /* IO port 9 */
    BSP_IO_PORT_10 = 0x1700,           /* IO port 10 */
    BSP_IO_PORT_11 = 0x0300,           /* IO port 11 */
    BSP_IO_PORT_12 = 0x0400,           /* IO port 12 */
    BSP_IO_PORT_13 = 0x0500,           /* IO port 13 */
    BSP_IO_PORT_14 = 0x0600,           /* IO port 14 */
    BSP_IO_PORT_15 = 0x0700,           /* IO port 15 */
    BSP_IO_PORT_16 = 0x0800,           /* IO port 16 */
    BSP_IO_PORT_17 = 0x0900,           /* IO port 17 */
    BSP_IO_PORT_18 = 0x0A00,           /* IO port 18 */
} bsp_io_port_t;

/** Superset list of all possible IO port pins. */
typedef enum e_bsp_io_port_pin_t
{
    BSP_IO_PORT_00_PIN_00 = 0x0000,     /* IO port 0 pin 0 */
    BSP_IO_PORT_00_PIN_01 = 0x0001,     /* IO port 0 pin 1 */
    BSP_IO_PORT_00_PIN_02 = 0x0002,     /* IO port 0 pin 2 */
    BSP_IO_PORT_00_PIN_03 = 0x0003,     /* IO port 0 pin 3 */

    BSP_IO_PORT_05_PIN_00 = 0x0100,     /* IO port 5 pin 0 */
    BSP_IO_PORT_05_PIN_01 = 0x0101,     /* IO port 5 pin 1 */
    BSP_IO_PORT_05_PIN_02 = 0x0102,     /* IO port 5 pin 2 */
    BSP_IO_PORT_05_PIN_03 = 0x0103,     /* IO port 5 pin 3 */
    BSP_IO_PORT_05_PIN_04 = 0x0104,     /* IO port 5 pin 4 */

    BSP_IO_PORT_06_PIN_00 = 0x0200,     /* IO port 6 pin 0 */
    BSP_IO_PORT_06_PIN_01 = 0x0201,     /* IO port 6 pin 1 */
    BSP_IO_PORT_06_PIN_02 = 0x0202,     /* IO port 6 pin 2 */
    BSP_IO_PORT_06_PIN_03 = 0x0203,     /* IO port 6 pin 3 */
    BSP_IO_PORT_06_PIN_04 = 0x0204,     /* IO port 6 pin 4 */

    BSP_IO_PORT_11_PIN_00 = 0x0300,     /* IO port 11 pin 0 */
    BSP_IO_PORT_11_PIN_01 = 0x0301,     /* IO port 11 pin 1 */
    BSP_IO_PORT_11_PIN_02 = 0x0302,     /* IO port 11 pin 2 */
    BSP_IO_PORT_11_PIN_03 = 0x0303,     /* IO port 11 pin 3 */

    BSP_IO_PORT_12_PIN_00 = 0x0400,     /* IO port 12 pin 0 */
    BSP_IO_PORT_12_PIN_01 = 0x0401,     /* IO port 12 pin 1 */

    BSP_IO_PORT_13_PIN_00 = 0x0500,     /* IO port 13 pin 0 */
    BSP_IO_PORT_13_PIN_01 = 0x0501,     /* IO port 13 pin 1 */
    BSP_IO_PORT_13_PIN_02 = 0x0502,     /* IO port 13 pin 2 */
    BSP_IO_PORT_13_PIN_03 = 0x0503,     /* IO port 13 pin 3 */
    BSP_IO_PORT_13_PIN_04 = 0x0504,     /* IO port 13 pin 4 */

    BSP_IO_PORT_14_PIN_00 = 0x0600,     /* IO port 14 pin 0 */
    BSP_IO_PORT_14_PIN_01 = 0x0601,     /* IO port 14 pin 1 */
    BSP_IO_PORT_14_PIN_02 = 0x0602,     /* IO port 14 pin 2 */

    BSP_IO_PORT_15_PIN_00 = 0x0700,     /* IO port 15 pin 0 */
    BSP_IO_PORT_15_PIN_01 = 0x0701,     /* IO port 15 pin 1 */
    BSP_IO_PORT_15_PIN_02 = 0x0702,     /* IO port 15 pin 2 */
    BSP_IO_PORT_15_PIN_03 = 0x0703,     /* IO port 15 pin 3 */

    BSP_IO_PORT_16_PIN_00 = 0x0800,     /* IO port 16 pin 0 */
    BSP_IO_PORT_16_PIN_01 = 0x0801,     /* IO port 16 pin 1 */

    BSP_IO_PORT_17_PIN_00 = 0x0900,     /* IO port 17 pin 0 */
    BSP_IO_PORT_17_PIN_01 = 0x0901,     /* IO port 17 pin 1 */
    BSP_IO_PORT_17_PIN_02 = 0x0902,     /* IO port 17 pin 2 */
    BSP_IO_PORT_17_PIN_03 = 0x0903,     /* IO port 17 pin 3 */

    BSP_IO_PORT_18_PIN_00 = 0x0A00,     /* IO port 18 pin 0 */
    BSP_IO_PORT_18_PIN_01 = 0x0A01,     /* IO port 18 pin 1 */
    BSP_IO_PORT_18_PIN_02 = 0x0A02,     /* IO port 18 pin 2 */
    BSP_IO_PORT_18_PIN_03 = 0x0A03,     /* IO port 18 pin 3 */
    BSP_IO_PORT_18_PIN_04 = 0x0A04,     /* IO port 18 pin 4 */
    BSP_IO_PORT_18_PIN_05 = 0x0A05,     /* IO port 18 pin 5 */

    BSP_IO_PORT_01_PIN_00 = 0x1000,     /* IO port 1 pin 0 */
    BSP_IO_PORT_01_PIN_01 = 0x1001,     /* IO port 1 pin 1 */
    BSP_IO_PORT_01_PIN_02 = 0x1002,     /* IO port 1 pin 2 */
    BSP_IO_PORT_01_PIN_03 = 0x1003,     /* IO port 1 pin 3 */
    BSP_IO_PORT_01_PIN_04 = 0x1004,     /* IO port 1 pin 4 */

    BSP_IO_PORT_02_PIN_00 = 0x1100,     /* IO port 2 pin 0 */
    BSP_IO_PORT_02_PIN_01 = 0x1101,     /* IO port 2 pin 1 */
    BSP_IO_PORT_02_PIN_02 = 0x1102,     /* IO port 2 pin 2 */
    BSP_IO_PORT_02_PIN_03 = 0x1103,     /* IO port 2 pin 3 */

    BSP_IO_PORT_03_PIN_00 = 0x1200,     /* IO port 3 pin 0 */
    BSP_IO_PORT_03_PIN_01 = 0x1201,     /* IO port 3 pin 1 */
    BSP_IO_PORT_03_PIN_02 = 0x1202,     /* IO port 3 pin 2 */
    BSP_IO_PORT_03_PIN_03 = 0x1203,     /* IO port 3 pin 3 */

    BSP_IO_PORT_04_PIN_00 = 0x1300,     /* IO port 4 pin 0 */
    BSP_IO_PORT_04_PIN_01 = 0x1301,     /* IO port 4 pin 1 */
    BSP_IO_PORT_04_PIN_02 = 0x1302,     /* IO port 4 pin 2 */
    BSP_IO_PORT_04_PIN_03 = 0x1303,     /* IO port 4 pin 3 */
    BSP_IO_PORT_04_PIN_04 = 0x1304,     /* IO port 4 pin 4 */
    BSP_IO_PORT_04_PIN_05 = 0x1305,     /* IO port 4 pin 5 */

    BSP_IO_PORT_07_PIN_00 = 0x1400,     /* IO port 7 pin 0 */
    BSP_IO_PORT_07_PIN_01 = 0x1401,     /* IO port 7 pin 1 */
    BSP_IO_PORT_07_PIN_02 = 0x1402,     /* IO port 7 pin 2 */
    BSP_IO_PORT_07_PIN_03 = 0x1403,     /* IO port 7 pin 3 */
    BSP_IO_PORT_07_PIN_04 = 0x1404,     /* IO port 7 pin 4 */

    BSP_IO_PORT_08_PIN_00 = 0x1500,     /* IO port 8 pin 0 */
    BSP_IO_PORT_08_PIN_01 = 0x1501,     /* IO port 8 pin 1 */
    BSP_IO_PORT_08_PIN_02 = 0x1502,     /* IO port 8 pin 2 */
    BSP_IO_PORT_08_PIN_03 = 0x1503,     /* IO port 8 pin 3 */
    BSP_IO_PORT_08_PIN_04 = 0x1504,     /* IO port 8 pin 4 */

    BSP_IO_PORT_09_PIN_00 = 0x1600,     /* IO port 9 pin 0 */
    BSP_IO_PORT_09_PIN_01 = 0x1601,     /* IO port 9 pin 1 */
    BSP_IO_PORT_09_PIN_02 = 0x1602,     /* IO port 9 pin 2 */
    BSP_IO_PORT_09_PIN_03 = 0x1603,     /* IO port 9 pin 3 */

    BSP_IO_PORT_10_PIN_00 = 0x1700,     /* IO port 10 pin 0 */
    BSP_IO_PORT_10_PIN_01 = 0x1701,     /* IO port 10 pin 1 */
    BSP_IO_PORT_10_PIN_02 = 0x1702,     /* IO port 10 pin 2 */
    BSP_IO_PORT_10_PIN_03 = 0x1703,     /* IO port 10 pin 3 */
    BSP_IO_PORT_10_PIN_04 = 0x1704,     /* IO port 10 pin 4 */

    /* Special purpose port */
    BSP_IO_NMI = 0xFFFF0000,            /* NMI */

    BSP_IO_TMS_SWDIO = 0xFFFF0100,      /* TMS_SWDIO */
    BSP_IO_TDO       = 0xFFFF0101,      /* TDO */

    BSP_IO_AUDIO_CLK1 = 0xFFFF0200,     /* AUDIO_CLK1 */
    BSP_IO_AUDIO_CLK2 = 0xFFFF0201,     /* AUDIO_CLK2 */

    BSP_IO_XSPI_SPCLK   = 0xFFFF0400,   /* XSPI_SPCLK */
    BSP_IO_XSPI_RESET_N = 0xFFFF0401,   /* XSPI_RESET_N */
    BSP_IO_XSPI_WP_N    = 0xFFFF0402,   /* XSPI_WP_N */
    BSP_IO_XSPI_DS      = 0xFFFF0403,   /* XSPI_DS */
    BSP_IO_XSPI_CS0_N   = 0xFFFF0404,   /* XSPI_CS0_N */
    BSP_IO_XSPI_CS1_N   = 0xFFFF0405,   /* XSPI_CS1_N */

    BSP_IO_XSPI_IO0 = 0xFFFF0500,       /* XSPI_IO0 */
    BSP_IO_XSPI_IO1 = 0xFFFF0501,       /* XSPI_IO1 */
    BSP_IO_XSPI_IO2 = 0xFFFF0502,       /* XSPI_IO2 */
    BSP_IO_XSPI_IO3 = 0xFFFF0503,       /* XSPI_IO3 */
    BSP_IO_XSPI_IO4 = 0xFFFF0504,       /* XSPI_IO4 */
    BSP_IO_XSPI_IO5 = 0xFFFF0505,       /* XSPI_IO5 */
    BSP_IO_XSPI_IO6 = 0xFFFF0506,       /* XSPI_IO6 */
    BSP_IO_XSPI_IO7 = 0xFFFF0507,       /* XSPI_IO7 */

    BSP_IO_WDTOVF_PERROUT = 0xFFFF0600, /* WDTOVF_PERROUT */

    BSP_IO_I3C_SDA = 0xFFFF0900,        /* I3C_SDA */
    BSP_IO_I3C_SCL = 0xFFFF0901,        /* I3C_SCL */

    BSP_IO_SD0_CLK   = 0xFFFF1000,      /* CD0_CLK */
    BSP_IO_SD0_CMD   = 0xFFFF1001,      /* CD0_CMD */
    BSP_IO_SD0_RST_N = 0xFFFF1002,      /* CD0_RST_N */

    BSP_IO_SD0_DATA0 = 0xFFFF1100,      /* SD0_DATA0 */
    BSP_IO_SD0_DATA1 = 0xFFFF1101,      /* SD0_DATA1 */
    BSP_IO_SD0_DATA2 = 0xFFFF1102,      /* SD0_DATA2 */
    BSP_IO_SD0_DATA3 = 0xFFFF1103,      /* SD0_DATA3 */
    BSP_IO_SD0_DATA4 = 0xFFFF1104,      /* SD0_DATA4 */
    BSP_IO_SD0_DATA5 = 0xFFFF1105,      /* SD0_DATA5 */
    BSP_IO_SD0_DATA6 = 0xFFFF1106,      /* SD0_DATA6 */
    BSP_IO_SD0_DATA7 = 0xFFFF1107,      /* SD0_DATA7 */

    BSP_IO_SD1_CLK = 0xFFFF1200,        /* SD1_CLK */
    BSP_IO_SD1_CMD = 0xFFFF1201,        /* SD1_CMD */

    BSP_IO_SD1_DATA0 = 0xFFFF1300,      /* SD1_DATA0 */
    BSP_IO_SD1_DATA1 = 0xFFFF1301,      /* SD1_DATA1 */
    BSP_IO_SD1_DATA2 = 0xFFFF1302,      /* SD1_DATA2 */
    BSP_IO_SD1_DATA3 = 0xFFFF1303,      /* SD1_DATA3 */
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
    ACCCNT_SRAM2,
    ACCCNT_SRAM3,
    ACCCNT_TZC0,
    ACCCNT_TZC1,
    ACCCNT_TZC2,
    ACCCNT_TZC3,
    ACCCNT_TZC5,
    ACCCNT_TZC6,
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
    ACCCNT_OSTM3,
    ACCCNT_OSTM4,
    ACCCNT_OSTM5,
    ACCCNT_OSTM6,
    ACCCNT_OSTM7,
    ACCCNT_WDT0,
    ACCCNT_WDT1,
    ACCCNT_WDT2,
    ACCCNT_RTC,
    ACCCNT_MTU3A,
    ACCCNT_POE3,
    ACCCNT_GPT,
    ACCCNT_POEG,
    ACCCNT_DDR,
    ACCCNT_XSPI,
    ACCCNT_OCTA,
    ACCCNT_USBT,
    ACCCNT_USB20,
    ACCCNT_USB21,
    ACCCNT_SDHI0,
    ACCCNT_SDHI1,
    ACCCNT_SDHI2,
    ACCCNT_ETH0,
    ACCCNT_ETH1,
    ACCCNT_PCIE,
    ACCCNT_I2C0,
    ACCCNT_I2C1,
    ACCCNT_I2C2,
    ACCCNT_I2C3,
    ACCCNT_I3C,
    ACCCNT_CANFD,
    ACCCNT_RSPI0,
    ACCCNT_RSPI1,
    ACCCNT_RSPI2,
    ACCCNT_RSPI3,
    ACCCNT_RSPI4,
    ACCCNT_SCIF0,
    ACCCNT_SCIF1,
    ACCCNT_SCIF2,
    ACCCNT_SCIF3,
    ACCCNT_SCIF4,
    ACCCNT_SCIF5,
    ACCCNT_SCI0,
    ACCCNT_SCI1,
    ACCCNT_IRDA,
    ACCCNT_SSIF0,
    ACCCNT_SSIF1,
    ACCCNT_SSIF2,
    ACCCNT_SSIF3,
    ACCCNT_SRC,
    ACCCNT_SPDIF,
    ACCCNT_PDM,
    ACCCNT_ADC,
    ACCCNT_TSU,
    ACCCNT_OTP,
    ACCCNT_VBATT,
    ACCCNT_CA55,
    ACCCNT_CM33,
    ACCCNT_CM33FPU,
    ACCCNT_LSI,
    ACCCNT_AOF,
    ACCCNT_LP,
    ACCCNT_GPREG,
    ACCCNT_IPCONT,
} fsp_acc_control_ip_t;

/** Available modules. */
typedef enum e_fsp_ip
{
    FSP_IP_GTM    = 0,                 ///< General Timer
    FSP_IP_GPT    = 1,                 ///< General PWM Timer
    FSP_IP_POEG   = 2,                 ///< Port Output Enable for GPT
    FSP_IP_PORT   = 3,                 ///< I/O Ports
    FSP_IP_IM33   = 4,                 ///< IM33 (Interrupt controller)
    FSP_IP_SCIF   = 5,                 ///< Serial Communications Interface with FIFO
    FSP_IP_RIIC   = 6,                 ///< I2C Bus Interface
    FSP_IP_RSPI   = 7,                 ///< Renesas Serial Peripheral Interface
    FSP_IP_MHU    = 8,                 ///< Message Handling Unit
    FSP_IP_DMAC   = 9,                 ///< Direct Memory Access Controller
    FSP_IP_DMAC_s = 9,                 ///< Direct Memory Access Controller
    FSP_IP_SSI    = 10,                ///< Serial Sound Interface
    FSP_IP_CANFD  = 11,                ///< CANFD Interface (RS-CANFD)
    FSP_IP_ADC    = 12,                ///< A/D Converter
    FSP_IP_TSU    = 13,                ///< Thermal Sensor Unit
    FSP_IP_WDT    = 14,                ///< Watchdog Timer
    FSP_IP_SCI    = 15,                ///< Serial Communications Interface
    FSP_IP_XSPI   = 16                 ///< Expanded Serial Peripheral Interface
} fsp_ip_t;

/* Private enum used in R_FSP_SystemClockHzGet. */
typedef enum e_fsp_priv_clock
{
    FSP_PRIV_CLOCK_ICLK = 0,           /* Cortex-A55 Clock */
    FSP_PRIV_CLOCK_I2CLK,              /* Cortex-M33 Clock */
    FSP_PRIV_CLOCK_I3CLK,              /* Cortex-M33 FPU Clock */
    FSP_PRIV_CLOCK_S0CLK,              /* DDR-PHY Clock */
    FSP_PRIV_CLOCK_OC0CLK,             /* OCTA0 Clock */
    FSP_PRIV_CLOCK_OC1CLK,             /* OCTA1 Clock */
    FSP_PRIV_CLOCK_SPI0CLK,            /* SPI0 Clock */
    FSP_PRIV_CLOCK_SPI1CLK,            /* SPI1 Clock */
    FSP_PRIV_CLOCK_SD0CLK,             /* SDH0 Clock */
    FSP_PRIV_CLOCK_SD1CLK,             /* SDH1 Clock */
    FSP_PRIV_CLOCK_SD2CLK,             /* SDH2 Clock */
    FSP_PRIV_CLOCK_M0CLK,              /* VCP, LCDC Clock */
    FSP_PRIV_CLOCK_HPCLK,              /* Ethernet Clock */
    FSP_PRIV_CLOCK_TSUCLK,             /* TSU Clock */
    FSP_PRIV_CLOCK_ZTCLK,              /* JAUTH Clock */
    FSP_PRIV_CLOCK_P0CLK,              /* APB-BUS Clock */
    FSP_PRIV_CLOCK_P1CLK,              /* AXI-BUS Clock */
    FSP_PRIV_CLOCK_P2CLK,              /* P2CLK */
    FSP_PRIV_CLOCK_P3CLK,              /* P3CLK */
    FSP_PRIV_CLOCK_P4CLK,              /* P4CLK */
    FSP_PRIV_CLOCK_P5CLK,              /* P5CLK */
    FSP_PRIV_CLOCK_ATCLK,              /* ATCLK */
    FSP_PRIV_CLOCK_OSCCLK,             /* OSC Clock */
    FSP_PRIV_CLOCK_OSCCLK2,            /* OSC2 Clock */
    FSP_PRIV_CLOCK_NUM,
} fsp_priv_clock_t;

/*==============================================
 * IOPORT Overrides
 *==============================================*/

/** Superset of all peripheral functions.  */
typedef enum e_ioport_peripheral
{
    /** Pin will function as a Mode1 peripheral pin */
    IOPORT_PERIPHERAL_MODE1 = (0x0UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode2 peripheral pin */
    IOPORT_PERIPHERAL_MODE2 = (0x1UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode3 peripheral pin */
    IOPORT_PERIPHERAL_MODE3 = (0x2UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode4 peripheral pin */
    IOPORT_PERIPHERAL_MODE4 = (0x3UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode5 peripheral pin */
    IOPORT_PERIPHERAL_MODE5 = (0x4UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode6 peripheral pin */
    IOPORT_PERIPHERAL_MODE6 = (0x5UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode7 peripheral pin */
    IOPORT_PERIPHERAL_MODE7 = (0x6UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode8 peripheral pin */
    IOPORT_PERIPHERAL_MODE8 = (0x7UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),
} ioport_peripheral_t;

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
