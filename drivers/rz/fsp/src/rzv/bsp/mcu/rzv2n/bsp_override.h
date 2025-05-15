/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RZV2N
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RZV2N) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Define overrides required for this MPU. */
#define BSP_OVERRIDE_ADC_INCLUDE
#define BSP_OVERRIDE_ADC_INFO_T
#define BSP_OVERRIDE_BSP_MST_ACC_CONTROL_IP_T
#define BSP_OVERRIDE_BSP_ACC_CONTROL_IP_T
#define BSP_OVERRIDE_BSP_MST_ACCESS_CONTROL
#define BSP_OVERRIDE_BSP_ACCESS_CONTROL
#define BSP_OVERRIDE_BSP_PIN_T
#define BSP_OVERRIDE_BSP_PORT_T
#define BSP_OVERRIDE_CAN_INFO_T
#define BSP_OVERRIDE_CANFD_ERROR_T
#define BSP_OVERRIDE_CANFD_RX_BUFFER_T
#define BSP_OVERRIDE_CANFD_RX_FIFO_T
#define BSP_OVERRIDE_CANFD_RX_MB_T
#define BSP_OVERRIDE_CANFD_TX_BUFFER_T
#define BSP_OVERRIDE_CANFD_TX_MB_T
#define BSP_OVERRIDE_ELC_PERIPHERAL_T
#define BSP_OVERRIDE_ELC_SOFTWARE_EVENT_T
#define BSP_OVERRIDE_FSP_IP_T
#define BSP_OVERRIDE_FSP_PRIV_CLOCK_T
#define BSP_OVERRIDE_FSP_PRIV_CLOCK_DIVIDER_T
#define BSP_OVERRIDE_FSP_PRIV_CLOCK_SELECTOR_T
#define BSP_OVERRIDE_GPT_POEG_LINK_T
#define BSP_OVERRIDE_GPT_SOURCE_T
#define BSP_OVERRIDE_IOPORT_CFG_OPTIONS_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_CALLBACK_ARGS_T
#define BSP_OVERRIDE_TRANSFER_INFO_T
#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T

/* Override definitions. */
#define BSP_API_OVERRIDE                           "bsp_api_override.h"

/*==============================================
 * Access Control Level Configuration Macros Overrides
 *==============================================*/

#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPCPG        (R_SYSC->SYS_SLVACCCTL0)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPCPG        (R_SYSC_SYS_SLVACCCTL0_MPCPG_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPSYS        (R_SYSC->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPSYS        (R_SYSC_SYS_SLVACCCTL1_MPSYS_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPICU0       (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPICU0       (R_SYSC_SYS_SLVACCCTL2_MPICU0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPICU1       (R_SYSC->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPICU1       (R_SYSC_SYS_SLVACCCTL2_MPICU1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXMDMC       (R_SYSC->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXMDMC       (R_SYSC_SYS_SLVACCCTL3_MXMDMC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPMSRM0      (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPMSRM0      (R_SYSC_SYS_SLVACCCTL4_MPMSRM0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPMSRM1      (R_SYSC->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPMSRM1      (R_SYSC_SYS_SLVACCCTL4_MPMSRM1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPCST        (R_SYSC->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPCST        (R_SYSC_SYS_SLVACCCTL5_MPCST_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPMHU        (R_SYSC->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPMHU        (R_SYSC_SYS_SLVACCCTL6_MPMHU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOMCMT0      (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOMCMT0      (R_SYSC_SYS_SLVACCCTL7_MOMCMT0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOMCMT1      (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOMCMT1      (R_SYSC_SYS_SLVACCCTL7_MOMCMT1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOMCMT2      (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOMCMT2      (R_SYSC_SYS_SLVACCCTL7_MOMCMT2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOMCMT3      (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOMCMT3      (R_SYSC_SYS_SLVACCCTL7_MOMCMT3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPMOST0      (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPMOST0      (R_SYSC_SYS_SLVACCCTL7_MPMOST0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPMOST1      (R_SYSC->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPMOST1      (R_SYSC_SYS_SLVACCCTL7_MPMOST1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOMWDT       (R_SYSC->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOMWDT       (R_SYSC_SYS_SLVACCCTL8_MOMWDT_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MORTC        (R_SYSC->SYS_SLVACCCTL9)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MORTC        (R_SYSC_SYS_SLVACCCTL9_MORTC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MORTR        (R_SYSC->SYS_SLVACCCTL10)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MORTR        (R_SYSC_SYS_SLVACCCTL10_MORTR_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SPI_REG      (R_SYSC->SYS_SLVACCCTL11)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SPI_REG      (R_SYSC_SYS_SLVACCCTL11_SPI_REG_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MHGPO        (R_SYSC->SYS_SLVACCCTL12)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MHGPO        (R_SYSC_SYS_SLVACCCTL12_MHGPO_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPPDM0       (R_SYSC->SYS_SLVACCCTL13)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPPDM0       (R_SYSC_SYS_SLVACCCTL13_MPPDM0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPPDM1       (R_SYSC->SYS_SLVACCCTL13)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPPDM1       (R_SYSC_SYS_SLVACCCTL13_MPPDM1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOADC        (R_SYSC->SYS_SLVACCCTL14)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOADC        (R_SYSC_SYS_SLVACCCTL14_MOADC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPMTSU0      (R_SYSC->SYS_SLVACCCTL15)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPMTSU0      (R_SYSC_SYS_SLVACCCTL15_MPMTSU0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOSCF        (R_SYSC->SYS_SLVACCCTL19)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOSCF        (R_SYSC_SYS_SLVACCCTL19_MOSCF_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOMI2C       (R_SYSC->SYS_SLVACCCTL20)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOMI2C       (R_SYSC_SYS_SLVACCCTL20_MOMI2C_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPTSPI       (R_SYSC->SYS_SLVACCCTL21)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPTSPI       (R_SYSC_SYS_SLVACCCTL21_MPTSPI_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPTM33       (R_SYSC->SYS_SLVACCCTL21)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPTM33       (R_SYSC_SYS_SLVACCCTL21_MPTM33_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXADMC0      (R_SYSC->SYS_SLVACCCTL32)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXADMC0      (R_SYSC_SYS_SLVACCCTL32_MXADMC0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXADMC1      (R_SYSC->SYS_SLVACCCTL32)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXADMC1      (R_SYSC_SYS_SLVACCCTL32_MXADMC1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPASRM       (R_SYSC->SYS_SLVACCCTL33)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPASRM       (R_SYSC_SYS_SLVACCCTL33_MPASRM_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPSYC        (R_SYSC->SYS_SLVACCCTL35)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPSYC        (R_SYSC_SYS_SLVACCCTL35_MPSYC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPAOST0      (R_SYSC->SYS_SLVACCCTL36)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPAOST0      (R_SYSC_SYS_SLVACCCTL36_MPAOST0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPAOST1      (R_SYSC->SYS_SLVACCCTL36)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPAOST1      (R_SYSC_SYS_SLVACCCTL36_MPAOST1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOAWDT       (R_SYSC->SYS_SLVACCCTL37)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOAWDT       (R_SYSC_SYS_SLVACCCTL37_MOAWDT_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOAI2C0      (R_SYSC->SYS_SLVACCCTL38)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOAI2C0      (R_SYSC_SYS_SLVACCCTL38_MOAI2C0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOAI2C1      (R_SYSC->SYS_SLVACCCTL38)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOAI2C1      (R_SYSC_SYS_SLVACCCTL38_MOAI2C1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOAI2C2      (R_SYSC->SYS_SLVACCCTL38)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOAI2C2      (R_SYSC_SYS_SLVACCCTL38_MOAI2C2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOAI2C3      (R_SYSC->SYS_SLVACCCTL38)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOAI2C3      (R_SYSC_SYS_SLVACCCTL38_MOAI2C3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOAI2C4      (R_SYSC->SYS_SLVACCCTL38)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOAI2C4      (R_SYSC_SYS_SLVACCCTL38_MOAI2C4_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOAI2C5      (R_SYSC->SYS_SLVACCCTL38)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOAI2C5      (R_SYSC_SYS_SLVACCCTL38_MOAI2C5_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOAI2C6      (R_SYSC->SYS_SLVACCCTL38)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOAI2C6      (R_SYSC_SYS_SLVACCCTL38_MOAI2C6_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOAI2C7      (R_SYSC->SYS_SLVACCCTL38)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOAI2C7      (R_SYSC_SYS_SLVACCCTL38_MOAI2C7_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXSD0        (R_SYSC->SYS_SLVACCCTL39)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXSD0        (R_SYSC_SYS_SLVACCCTL39_MXSD0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXSD1        (R_SYSC->SYS_SLVACCCTL39)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXSD1        (R_SYSC_SYS_SLVACCCTL39_MXSD1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXSD2        (R_SYSC->SYS_SLVACCCTL39)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXSD2        (R_SYSC_SYS_SLVACCCTL39_MXSD2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPU3P0       (R_SYSC->SYS_SLVACCCTL40)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPU3P0       (R_SYSC_SYS_SLVACCCTL40_MPU3P0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXU3H0       (R_SYSC->SYS_SLVACCCTL40)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXU3H0       (R_SYSC_SYS_SLVACCCTL40_MXU3H0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MHU2H0       (R_SYSC->SYS_SLVACCCTL40)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MHU2H0       (R_SYSC_SYS_SLVACCCTL40_MHU2H0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPU2P0       (R_SYSC->SYS_SLVACCCTL40)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPU2P0       (R_SYSC_SYS_SLVACCCTL40_MPU2P0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXGBE0       (R_SYSC->SYS_SLVACCCTL41)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXGBE0       (R_SYSC_SYS_SLVACCCTL41_MXGBE0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXGBE1       (R_SYSC->SYS_SLVACCCTL41)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXGBE1       (R_SYSC_SYS_SLVACCCTL41_MXGBE1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPDDM0       (R_SYSC->SYS_SLVACCCTL43)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPDDM0       (R_SYSC_SYS_SLVACCCTL43_MPDDM0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPDDP0       (R_SYSC->SYS_SLVACCCTL43)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPDDP0       (R_SYSC_SYS_SLVACCCTL43_MPDDP0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPCRU0       (R_SYSC->SYS_SLVACCCTL44)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPCRU0       (R_SYSC_SYS_SLVACCCTL44_MPCRU0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPCRU1       (R_SYSC->SYS_SLVACCCTL44)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPCRU1       (R_SYSC_SYS_SLVACCCTL44_MPCRU1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPISP        (R_SYSC->SYS_SLVACCCTL45)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPISP        (R_SYSC_SYS_SLVACCCTL45_MPISP_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXISP        (R_SYSC->SYS_SLVACCCTL45)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXISP        (R_SYSC_SYS_SLVACCCTL45_MXISP_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPISU        (R_SYSC->SYS_SLVACCCTL46)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPISU        (R_SYSC_SYS_SLVACCCTL46_MPISU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPDSD        (R_SYSC->SYS_SLVACCCTL47)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPDSD        (R_SYSC_SYS_SLVACCCTL47_MPDSD_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPDSL        (R_SYSC->SYS_SLVACCCTL47)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPDSL        (R_SYSC_SYS_SLVACCCTL47_MPDSL_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPLCD        (R_SYSC->SYS_SLVACCCTL48)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPLCD        (R_SYSC_SYS_SLVACCCTL48_MPLCD_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXGE3D       (R_SYSC->SYS_SLVACCCTL49)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXGE3D       (R_SYSC_SYS_SLVACCCTL49_MXGE3D_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPVCC        (R_SYSC->SYS_SLVACCCTL50)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPVCC        (R_SYSC_SYS_SLVACCCTL50_MPVCC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPSSIU       (R_SYSC->SYS_SLVACCCTL51)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPSSIU       (R_SYSC_SYS_SLVACCCTL51_MPSSIU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPSSIUDMC    (R_SYSC->SYS_SLVACCCTL51)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPSSIUDMC    (R_SYSC_SYS_SLVACCCTL51_MPSSIUDMC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPADMC       (R_SYSC->SYS_SLVACCCTL51)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPADMC       (R_SYSC_SYS_SLVACCCTL51_MPADMC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOSPD0       (R_SYSC->SYS_SLVACCCTL52)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOSPD0       (R_SYSC_SYS_SLVACCCTL52_MOSPD0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOSPD1       (R_SYSC->SYS_SLVACCCTL52)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOSPD1       (R_SYSC_SYS_SLVACCCTL52_MOSPD1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOSPD2       (R_SYSC->SYS_SLVACCCTL52)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOSPD2       (R_SYSC_SYS_SLVACCCTL52_MOSPD2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPSCU        (R_SYSC->SYS_SLVACCCTL53)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPSCU        (R_SYSC_SYS_SLVACCCTL53_MPSCU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPSCUDMC     (R_SYSC->SYS_SLVACCCTL53)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPSCUDMC     (R_SYSC_SYS_SLVACCCTL53_MPSCUDMC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPADG        (R_SYSC->SYS_SLVACCCTL53)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPADG        (R_SYSC_SYS_SLVACCCTL53_MPADG_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXDRA        (R_SYSC->SYS_SLVACCCTL54)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXDRA        (R_SYSC_SYS_SLVACCCTL54_MXDRA_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXDRS        (R_SYSC->SYS_SLVACCCTL54)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXDRS        (R_SYSC_SYS_SLVACCCTL54_MXDRS_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MXGIC        (R_SYSC->SYS_SLVACCCTL55)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MXGIC        (R_SYSC_SYS_SLVACCCTL55_MXGIC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPMTSU1      (R_SYSC->SYS_SLVACCCTL56)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPMTSU1      (R_SYSC_SYS_SLVACCCTL56_MPMTSU1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPTA55       (R_SYSC->SYS_SLVACCCTL57)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPTA55       (R_SYSC_SYS_SLVACCCTL57_MPTA55_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPTR8        (R_SYSC->SYS_SLVACCCTL57)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPTR8        (R_SYSC_SYS_SLVACCCTL57_MPTR8_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPTDD01      (R_SYSC->SYS_SLVACCCTL57)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPTDD01      (R_SYSC_SYS_SLVACCCTL57_MPTDD01_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPTDD00      (R_SYSC->SYS_SLVACCCTL57)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPTDD00      (R_SYSC_SYS_SLVACCCTL57_MPTDD00_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MPTPCI       (R_SYSC->SYS_SLVACCCTL57)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MPTPCI       (R_SYSC_SYS_SLVACCCTL57_MPTPCI_SL_Pos)

#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOCRC        (R_SYSC->SYS_SLVACCCTL64)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOCRC        (R_SYSC_SYS_SLVACCCTL64_MOCRC_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOGPT0       (R_SYSC->SYS_SLVACCCTL65)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOGPT0       (R_SYSC_SYS_SLVACCCTL65_MOGPT0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOGPT1       (R_SYSC->SYS_SLVACCCTL65)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOGPT1       (R_SYSC_SYS_SLVACCCTL65_MOGPT1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOPOE0       (R_SYSC->SYS_SLVACCCTL66)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOPOE0       (R_SYSC_SYS_SLVACCCTL66_MOPOE0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOPOE1       (R_SYSC->SYS_SLVACCCTL66)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOPOE1       (R_SYSC_SYS_SLVACCCTL66_MOPOE1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOPOE2       (R_SYSC->SYS_SLVACCCTL66)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOPOE2       (R_SYSC_SYS_SLVACCCTL66_MOPOE2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOPOE3       (R_SYSC->SYS_SLVACCCTL66)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOPOE3       (R_SYSC_SYS_SLVACCCTL66_MOPOE3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOPOE4       (R_SYSC->SYS_SLVACCCTL66)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOPOE4       (R_SYSC_SYS_SLVACCCTL66_MOPOE4_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOPOE5       (R_SYSC->SYS_SLVACCCTL66)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOPOE5       (R_SYSC_SYS_SLVACCCTL66_MOPOE5_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOPOE6       (R_SYSC->SYS_SLVACCCTL66)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOPOE6       (R_SYSC_SYS_SLVACCCTL66_MOPOE6_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MOPOE7       (R_SYSC->SYS_SLVACCCTL66)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MOPOE7       (R_SYSC_SYS_SLVACCCTL66_MOPOE7_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MORCMT0      (R_SYSC->SYS_SLVACCCTL67)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MORCMT0      (R_SYSC_SYS_SLVACCCTL67_MORCMT0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MORCMT1      (R_SYSC->SYS_SLVACCCTL67)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MORCMT1      (R_SYSC_SYS_SLVACCCTL67_MORCMT1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MORCMT2      (R_SYSC->SYS_SLVACCCTL67)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MORCMT2      (R_SYSC_SYS_SLVACCCTL67_MORCMT2_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MORCMT3      (R_SYSC->SYS_SLVACCCTL67)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MORCMT3      (R_SYSC_SYS_SLVACCCTL67_MORCMT3_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MORWDT0      (R_SYSC->SYS_SLVACCCTL68)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MORWDT0      (R_SYSC_SYS_SLVACCCTL68_MORWDT0_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MORWDT1      (R_SYSC->SYS_SLVACCCTL68)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MORWDT1      (R_SYSC_SYS_SLVACCCTL68_MORWDT1_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I3C          (R_SYSC->SYS_SLVACCCTL80)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I3C          (R_SYSC_SYS_SLVACCCTL80_I3C_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CANFD        (R_SYSC->SYS_SLVACCCTL81)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CANFD        (R_SYSC_SYS_SLVACCCTL81_CANFD_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ACPU         (R_SYSC->SYS_SLVACCCTL87)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ACPU         (R_SYSC_SYS_SLVACCCTL87_ACPU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MCPU         (R_SYSC->SYS_SLVACCCTL89)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MCPU         (R_SYSC_SYS_SLVACCCTL89_MCPU_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_LSI          (R_SYSC->SYS_SLVACCCTL91)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_LSI          (R_SYSC_SYS_SLVACCCTL91_LSI_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_AOF          (R_SYSC->SYS_SLVACCCTL92)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_AOF          (R_SYSC_SYS_SLVACCCTL92_AOF_SL_Pos)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPREG        (R_SYSC->SYS_SLVACCCTL93)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPREG        (R_SYSC_SYS_SLVACCCTL93_GPREG_SL_Pos)

/***********************************************************************************************************************
 * Definition of macros to set value to Master Access Control Registers
 **********************************************************************************************************************/
#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DMAC0(level)              {R_SYSC->SYS_MSTACCCTL0 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL0                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXMDMC_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXMDMC_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL0_SXMDMC_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL0_SXMDMC_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DMAC0(level)               {R_SYSC->SYS_MSTACCCTL0 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL0                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXMDMC_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXMDMC_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL0_SXMDMC_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL0_SXMDMC_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DMAC1(level)              {R_SYSC->SYS_MSTACCCTL0 =                           \
                                                                           (R_SYSC->SYS_MSTACCCTL0                        \
                                                                            & ~(uint32_t) (                               \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXADMC00_AWPU_Msk   \
                                                                                |                                         \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXADMC00_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL0_SXADMC00_AWSEL_Msk     \
                                                                           | (level <<                                    \
                                                                               R_SYSC_SYS_MSTACCCTL0_SXADMC00_AWPU_Pos);  \
}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DMAC1(level)               {R_SYSC->SYS_MSTACCCTL0 =                           \
                                                                           (R_SYSC->SYS_MSTACCCTL0                        \
                                                                            & ~(uint32_t) (                               \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXADMC00_ARPU_Msk   \
                                                                                |                                         \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXADMC00_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL0_SXADMC00_ARSEL_Msk     \
                                                                           | (level <<                                    \
                                                                               R_SYSC_SYS_MSTACCCTL0_SXADMC00_ARPU_Pos);  \
}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DMAC2(level)              {R_SYSC->SYS_MSTACCCTL0 =                          \
                                                                           (R_SYSC->SYS_MSTACCCTL0                       \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXADMC1_AWPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXADMC1_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL0_SXADMC1_AWSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL0_SXADMC1_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DMAC2(level)               {R_SYSC->SYS_MSTACCCTL0 =                          \
                                                                           (R_SYSC->SYS_MSTACCCTL0                       \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXADMC1_ARPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXADMC1_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL0_SXADMC1_ARSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL0_SXADMC1_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DMAC3(level)              {R_SYSC->SYS_MSTACCCTL0 =                          \
                                                                           (R_SYSC->SYS_MSTACCCTL0                       \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXRDMC0_AWPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXRDMC0_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL0_SXRDMC0_AWSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL0_SXRDMC0_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DMAC3(level)               {R_SYSC->SYS_MSTACCCTL0 =                          \
                                                                           (R_SYSC->SYS_MSTACCCTL0                       \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXRDMC0_ARPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL0_SXRDMC0_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL0_SXRDMC0_ARSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL0_SXRDMC0_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DMAC4(level)              {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                           (R_SYSC->SYS_MSTACCCTL1                       \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL1_SXMDMC1_AWPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL1_SXMDMC1_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL1_SXMDMC1_AWSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL1_SXMDMC1_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DMAC4(level)               {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                           (R_SYSC->SYS_MSTACCCTL1                       \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL1_SXMDMC1_ARPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL1_SXMDMC1_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL1_SXMDMC1_ARSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL1_SXMDMC1_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_SD0(level)                {R_SYSC->SYS_MSTACCCTL3 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL3                     \
                                                                            & ~(uint32_t) (                            \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD0_AWPU_Msk   \
                                                                                |                                      \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD0_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL3_SXSD0_AWSEL_Msk     \
                                                                           | (level <<                                 \
                                                                               R_SYSC_SYS_MSTACCCTL3_SXSD0_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_SD0(level)                 {R_SYSC->SYS_MSTACCCTL3 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL3                     \
                                                                            & ~(uint32_t) (                            \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD0_ARPU_Msk   \
                                                                                |                                      \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD0_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL3_SXSD0_ARSEL_Msk     \
                                                                           | (level <<                                 \
                                                                               R_SYSC_SYS_MSTACCCTL3_SXSD0_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_SD1(level)                {R_SYSC->SYS_MSTACCCTL3 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL3                     \
                                                                            & ~(uint32_t) (                            \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD1_AWPU_Msk   \
                                                                                |                                      \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD1_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL3_SXSD1_AWSEL_Msk     \
                                                                           | (level <<                                 \
                                                                               R_SYSC_SYS_MSTACCCTL3_SXSD1_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_SD1(level)                 {R_SYSC->SYS_MSTACCCTL3 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL3                     \
                                                                            & ~(uint32_t) (                            \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD1_ARPU_Msk   \
                                                                                |                                      \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD1_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL3_SXSD1_ARSEL_Msk     \
                                                                           | (level <<                                 \
                                                                               R_SYSC_SYS_MSTACCCTL3_SXSD1_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_SD2(level)                {R_SYSC->SYS_MSTACCCTL3 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL3                     \
                                                                            & ~(uint32_t) (                            \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD2_AWPU_Msk   \
                                                                                |                                      \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD2_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL3_SXSD2_AWSEL_Msk     \
                                                                           | (level <<                                 \
                                                                               R_SYSC_SYS_MSTACCCTL3_SXSD2_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_SD2(level)                 {R_SYSC->SYS_MSTACCCTL3 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL3                     \
                                                                            & ~(uint32_t) (                            \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD2_ARPU_Msk   \
                                                                                |                                      \
                                                                                R_SYSC_SYS_MSTACCCTL3_SXSD2_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL3_SXSD2_ARSEL_Msk     \
                                                                           | (level <<                                 \
                                                                               R_SYSC_SYS_MSTACCCTL3_SXSD2_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB30_HOST(level)         {R_SYSC->SYS_MSTACCCTL4 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL4                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL4_SXU3H0_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL4_SXU3H0_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL4_SXU3H0_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL4_SXU3H0_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB30_HOST(level)          {R_SYSC->SYS_MSTACCCTL4 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL4                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL4_SXU3H0_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL4_SXU3H0_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL4_SXU3H0_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL4_SXU3H0_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB20_HOST(level)         {R_SYSC->SYS_MSTACCCTL5 =                             \
                                                                           (R_SYSC->SYS_MSTACCCTL5                          \
                                                                            & ~(uint32_t) (                                 \
                                                                                R_SYSC_SYS_MSTACCCTL5_SHU2H0_P0_AWPU_Msk    \
                                                                                |                                           \
                                                                                R_SYSC_SYS_MSTACCCTL5_SXHU2H0_P0_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL5_SXHU2H0_P0_AWSEL_Msk     \
                                                                           | (level <<                                      \
                                                                               R_SYSC_SYS_MSTACCCTL5_SHU2H0_P0_AWPU_Pos);   \
}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB20_HOST(level)          {R_SYSC->SYS_MSTACCCTL5 =                             \
                                                                           (R_SYSC->SYS_MSTACCCTL5                          \
                                                                            & ~(uint32_t) (                                 \
                                                                                R_SYSC_SYS_MSTACCCTL5_SXHU2H0_P0_ARPU_Msk   \
                                                                                |                                           \
                                                                                R_SYSC_SYS_MSTACCCTL5_SXHU2H0_P0_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL5_SXHU2H0_P0_ARSEL_Msk     \
                                                                           | (level <<                                      \
                                                                               R_SYSC_SYS_MSTACCCTL5_SXHU2H0_P0_ARPU_Pos);  \
}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB20_FUNC(level)         {R_SYSC->SYS_MSTACCCTL5 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL5                     \
                                                                            & ~(uint32_t) (                            \
                                                                                R_SYSC_SYS_MSTACCCTL5_SHU2F_AWPU_Msk   \
                                                                                |                                      \
                                                                                R_SYSC_SYS_MSTACCCTL5_SHU2F_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL5_SHU2F_AWSEL_Msk     \
                                                                           | (level <<                                 \
                                                                               R_SYSC_SYS_MSTACCCTL5_SHU2F_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB20_FUNC(level)          {R_SYSC->SYS_MSTACCCTL5 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL5                     \
                                                                            & ~(uint32_t) (                            \
                                                                                R_SYSC_SYS_MSTACCCTL5_SHU2F_ARPU_Msk   \
                                                                                |                                      \
                                                                                R_SYSC_SYS_MSTACCCTL5_SHU2F_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL5_SHU2F_ARSEL_Msk     \
                                                                           | (level <<                                 \
                                                                               R_SYSC_SYS_MSTACCCTL5_SHU2F_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_GBETH0(level)             {R_SYSC->SYS_MSTACCCTL6 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL6                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL6_SXGBE0_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL6_SXGBE0_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL6_SXGBE0_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL6_SXGBE0_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_GBETH0(level)              {R_SYSC->SYS_MSTACCCTL6 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL6                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL6_SXGBE0_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL6_SXGBE0_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL6_SXGBE0_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL6_SXGBE0_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_GBETH1(level)             {R_SYSC->SYS_MSTACCCTL6 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL6                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL6_SXGBE1_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL6_SXGBE1_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL6_SXGBE1_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL6_SXGBE1_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_GBETH1(level)              {R_SYSC->SYS_MSTACCCTL6 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL6                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL6_SXGBE1_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL6_SXGBE1_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL6_SXGBE1_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL6_SXGBE1_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_PCIE0(level)              {R_SYSC->SYS_MSTACCCTL7 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL7                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL7_SXPCI0_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL7_SXPCI0_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL7_SXPCI0_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL7_SXPCI0_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_PCIE0(level)               {R_SYSC->SYS_MSTACCCTL7 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL7                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL7_SXPCI0_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL7_SXPCI0_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL7_SXPCI0_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL7_SXPCI0_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_CRU0_VIDEO(level)         {R_SYSC->SYS_MSTACCCTL8 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL8                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL8_SXCRV0_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL8_SXCRV0_AWNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL8_SXCRV0_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_CRU0_VIDEO(level)

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_CRU0_STATIC(level)        {R_SYSC->SYS_MSTACCCTL8 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL8                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL8_SXCRS0_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL8_SXCRS0_AWNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL8_SXCRS0_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_CRU0_STATIC(level)

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_CRU1_VIDEO(level)         {R_SYSC->SYS_MSTACCCTL8 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL8                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL8_SXCRV1_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL8_SXCRV1_AWNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL8_SXCRV1_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_CRU1_VIDEO(level)

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_CRU1_STATIC(level)        {R_SYSC->SYS_MSTACCCTL8 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL8                      \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL8_SXCRS1_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL8_SXCRS1_AWNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL8_SXCRS1_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_CRU1_STATIC(level)

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_FR_VIDEO_OUT(level)       {R_SYSC->SYS_MSTACCCTL10 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL10                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL10_SXISF_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL10_SXISF_AWNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL10_SXISF_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_FR_VIDEO_OUT(level)

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_ISP_TEMPER(level)         {R_SYSC->SYS_MSTACCCTL10 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL10                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL10_SXIST_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL10_SXIST_AWNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL10_SXIST_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_ISP_TEMPER(level)          {R_SYSC->SYS_MSTACCCTL10 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL10                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL10_SXIST_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL10_SXIST_ARNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL10_SXIST_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_ISP_VIDEO_IN(level)

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_ISP_VIDEO_IN(level)        {R_SYSC->SYS_MSTACCCTL10 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL10                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL10_SXISV_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL10_SXISV_ARNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL10_SXISV_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_ISU(level)                {R_SYSC->SYS_MSTACCCTL11 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL11                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL11_SXISU_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL11_SXISU_AWNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL11_SXISU_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_ISU(level)                 {R_SYSC->SYS_MSTACCCTL11 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL11                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL11_SXISU_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL11_SXISU_ARNS_Msk)) \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL11_SXISU_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DSI(level)                {R_SYSC->SYS_MSTACCCTL12 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL12                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL12_SXDSI_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL12_SXDSI_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL12_SXDSI_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL12_SXDSI_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DSI(level)                 {R_SYSC->SYS_MSTACCCTL12 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL12                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL12_SXDSI_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL12_SXDSI_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL12_SXDSI_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL12_SXDSI_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_LCDC0(level)              {R_SYSC->SYS_MSTACCCTL13 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL13                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL13_SXLCD_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL13_SXLCD_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL13_SXLCD_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL13_SXLCD_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_LCDC0(level)               {R_SYSC->SYS_MSTACCCTL13 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL13                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL13_SXLCD_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL13_SXLCD_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL13_SXLCD_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL13_SXLCD_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_GE3D(level)               {R_SYSC->SYS_MSTACCCTL14 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL14                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL14_SXGPU_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL14_SXGPU_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL14_SXGPU_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL14_SXGPU_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_GE3D(level)                {R_SYSC->SYS_MSTACCCTL14 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL14                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL14_SXGPU_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL14_SXGPU_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL14_SXGPU_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL14_SXGPU_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_VCD(level)                {R_SYSC->SYS_MSTACCCTL15 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL15                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL15_SXVCP_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL15_SXVCP_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL15_SXVCP_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL15_SXVCP_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_VCD(level)                 {R_SYSC->SYS_MSTACCCTL15 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL15                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL15_SXVCP_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL15_SXVCP_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL15_SXVCP_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL15_SXVCP_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DRP_AI_MASTER(level)      {R_SYSC->SYS_MSTACCCTL17 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL17                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL17_SXDRA_AWPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL17_SXDRA_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL17_SXDRA_AWSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL17_SXDRA_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DRP_AI_MASTER(level)       {R_SYSC->SYS_MSTACCCTL17 =                        \
                                                                           (R_SYSC->SYS_MSTACCCTL17                     \
                                                                            & ~(uint32_t) (                             \
                                                                                R_SYSC_SYS_MSTACCCTL17_SXDRA_ARPU_Msk   \
                                                                                |                                       \
                                                                                R_SYSC_SYS_MSTACCCTL17_SXDRA_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL17_SXDRA_ARSEL_Msk     \
                                                                           | (level <<                                  \
                                                                               R_SYSC_SYS_MSTACCCTL17_SXDRA_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DRP_AI_FEATURE0(level)    {R_SYSC->SYS_MSTACCCTL18 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL18                      \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRM0_AWPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRM0_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL18_SXDRM0_AWSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL18_SXDRM0_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DRP_AI_FEATURE0(level)     {R_SYSC->SYS_MSTACCCTL18 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL18                      \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRM0_ARPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRM0_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL18_SXDRM0_ARSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL18_SXDRM0_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DRP_AI_FEATURE1(level)    {R_SYSC->SYS_MSTACCCTL18 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL18                      \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRM1_AWPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRM1_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL18_SXDRM1_AWSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL18_SXDRM1_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DRP_AI_FEATURE1(level)     {R_SYSC->SYS_MSTACCCTL18 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL18                      \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRM1_ARPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRM1_ARNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL18_SXDRM1_ARSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL18_SXDRM1_ARPU_Pos);}

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DRP_AI_WEIGHT0(level)     {R_SYSC->SYS_MSTACCCTL18 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL18                      \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRW0_AWPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRW0_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL18_SXDRW0_AWSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL18_SXDRW0_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DRP_AI_WEIGHT0(level)

#define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DRP_AI_WEIGHT1(level)     {R_SYSC->SYS_MSTACCCTL18 =                         \
                                                                           (R_SYSC->SYS_MSTACCCTL18                      \
                                                                            & ~(uint32_t) (                              \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRW1_AWPU_Msk   \
                                                                                |                                        \
                                                                                R_SYSC_SYS_MSTACCCTL18_SXDRW1_AWNS_Msk)) \
                                                                           | R_SYSC_SYS_MSTACCCTL18_SXDRW1_AWSEL_Msk     \
                                                                           | (level <<                                   \
                                                                               R_SYSC_SYS_MSTACCCTL18_SXDRW1_AWPU_Pos);}

#define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DRP_AI_WEIGHT1(level)

#define R_BSP_IM33_ENABLE()                                           {R_CPG->CPG_LP_CTL2 = 0x00000000;}

/*==============================================
 * CPG control macros Overrides
 *==============================================*/

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_GTM(ip, ch)      {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTON(ip, ch); \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_GTM(ip, ch)       {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_GPT(ip, ch)      {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_GPT(ip, ch)       {NULL;}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_CANFD(ip, ch)    {R_BSP_MSTP_START(ip, 0U);   \
                                                    R_BSP_MODULE_CLKON(ip, 0U); \
                                                    R_BSP_MODULE_RSTOFF(ip, 0U);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_CANFD(ip, ch)     {NULL;}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/
#define R_BSP_MODULE_START_FSP_IP_ADC(ip, ch)      {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_ADC(ip, ch)       {NULL;}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_MHU(ip, ch)      {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_MHU(ip, ch)       {NULL;}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_POEG(ip, ch)     {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_POEG(ip, ch)      {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_RIIC(ip, ch)     {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_RIIC(ip, ch)      {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_SCI(ip, ch)      {R_BSP_MODULE_CLKON(FSP_IP_SCIP, (ch));   \
                                                    R_BSP_MODULE_CLKON(FSP_IP_SCIT, (ch));   \
                                                    R_BSP_MODULE_CLKON(FSP_IP_SCIPS3, (ch)); \
                                                    R_BSP_MODULE_CLKON(FSP_IP_SCIPS2, (ch)); \
                                                    R_BSP_MODULE_CLKON(FSP_IP_SCIPS1, (ch)); \
                                                    R_BSP_MSTP_START(ip, ch);                \
                                                    R_BSP_MODULE_RSTOFF(FSP_IP_SCIP, ch);    \
                                                    R_BSP_MODULE_RSTOFF(FSP_IP_SCIT, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_SCI(ip, ch)       {R_BSP_MSTP_STOP(ip, ch);                  \
                                                    R_BSP_MODULE_CLKOFF(FSP_IP_SCIP, (ch));   \
                                                    R_BSP_MODULE_CLKOFF(FSP_IP_SCIT, (ch));   \
                                                    R_BSP_MODULE_CLKOFF(FSP_IP_SCIPS3, (ch)); \
                                                    R_BSP_MODULE_CLKOFF(FSP_IP_SCIPS2, (ch)); \
                                                    R_BSP_MODULE_CLKOFF(FSP_IP_SCIPS1, (ch));}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_RSPI(ip, ch)     {R_BSP_MODULE_CLKON(ip, ch);              \
                                                    R_BSP_MSTP_START(ip, ch);                \
                                                    R_BSP_MODULE_RSTOFF(FSP_IP_RSPIP, (ch)); \
                                                    R_BSP_MODULE_RSTOFF(FSP_IP_RSPIT, (ch));}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_RSPI(ip, ch)      {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_TSU(ip, ch)      {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_TSU(ip, ch)       {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_SCIF(ip, ch)     {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_SCIF(ip, ch)      {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_XSPI(ip, ch)     {R_BSP_MODULE_CLKON(FSP_IP_XSPI_H, (ch));     \
                                                    R_BSP_MODULE_CLKON(FSP_IP_XSPI_OTHER, (ch)); \
                                                    R_BSP_MSTP_START(FSP_IP_XSPI, ch);           \
                                                    R_BSP_MSTP_START(FSP_IP_XSPI_REG, ch);       \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_XSPI(ip, ch)      {NULL;}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_CMTW(ip, ch)     {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_CMTW(ip, ch)      {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_DMAC(ip, ch)     {R_BSP_MODULE_CLKON(ip, ch);         \
                                                    R_BSP_MSTP_START(FSP_IP_DMAC0, ch); \
                                                    R_BSP_MSTP_START(FSP_IP_DMAC1, ch); \
                                                    R_BSP_MSTP_START(FSP_IP_DMAC2, ch); \
                                                    R_BSP_MSTP_START(FSP_IP_DMAC3, ch); \
                                                    R_BSP_MSTP_START(FSP_IP_DMAC4, ch); \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_DMAC(ip, ch)      {NULL;}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_WDT(ip, ch)      {R_BSP_MODULE_CLKON(FSP_IP_WDT_CLKP, (ch)); \
                                                    R_BSP_MODULE_CLKON(FSP_IP_WDT_LOCO, (ch)); \
                                                    R_BSP_MSTP_START(ip, ch);                  \
                                                    R_BSP_MODULE_RSTOFF(ip, (ch));}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_WDT(ip, ch)       {NULL;}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_CRC(ip, ch)      {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_CRC(ip, ch)       {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_I3C(ip, ch)      {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_I3C(ip, ch)       {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_RTC(ip, ch)      {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch);   \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_RTC(ip, ch)       {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_START_FSP_IP_PDM(ip, ch)      {R_BSP_MODULE_CLKON(ip, ch); \
                                                    R_BSP_MSTP_START(ip, ch)    \
                                                    R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

#define R_BSP_MODULE_STOP_FSP_IP_PDM(ip, ch)       {R_BSP_MSTP_STOP(ip, ch); \
                                                    R_BSP_MODULE_CLKOFF(ip, ch);}

/***********************************************************************************************************************
 * Definition of macros to control GTM clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_GTM(channel)          (R_CPG->CPG_CLKON_4)
#define BSP_CLKON_BIT_FSP_IP_GTM(channel)          (1U << (R_CPG_CPG_CLKON_4_CLK3_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_GTM(channel)         (R_CPG->CPG_CLKMON_2)
#define BSP_CLKMON_BIT_FSP_IP_GTM(channel)         (1U << (R_CPG_CPG_CLKMON_2_CLK3_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_GTM(channel)            *((channel < 3) ? &R_CPG->CPG_RST_6 : &R_CPG->CPG_RST_7)
#define BSP_RST_BIT_FSP_IP_GTM(channel)            ((channel <                                                                              \
                                                     3) ? (1U << (R_CPG_CPG_RST_6_RSTB13_Pos + (channel))) : (1U <<                         \
                                                                                                              (                             \
                                                                                                                  R_CPG_CPG_RST_7_RSTB0_Pos \
                                                                                                                  + (                       \
                                                                                                                      channel               \
                                                                                                                      -                     \
                                                                                                                      3))))

#define BSP_RSTMON_REG_FSP_IP_GTM(channel)         *((channel < 2) ? &R_CPG->CPG_RSTMON_2 : &R_CPG->CPG_RSTMON_3)
#define BSP_RSTMON_BIT_FSP_IP_GTM(channel)         ((channel <                                                                                    \
                                                     2) ? (1U <<                                                                                  \
                                                           (R_CPG_CPG_RSTMON_2_RST30_MON_Pos + (channel))) : (1U <<                               \
                                                                                                              (                                   \
                                                                                                                  R_CPG_CPG_RSTMON_3_RST0_MON_Pos \
                                                                                                                  + (                             \
                                                                                                                      channel                     \
                                                                                                                      -                           \
                                                                                                                      2))))

/***********************************************************************************************************************
 * Definition of macros to control GPT clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_GPT(channel)          (R_CPG->CPG_CLKON_3)
#define BSP_CLKON_BIT_FSP_IP_GPT(channel)          (1U << (R_CPG_CPG_CLKON_3_CLK1_ON_Pos + (channel / 8)))

#define BSP_CLKMON_REG_FSP_IP_GPT(channel)         (R_CPG->CPG_CLKMON_1)
#define BSP_CLKMON_BIT_FSP_IP_GPT(channel)         (1U << (R_CPG_CPG_CLKMON_1_CLK17_MON_Pos + (channel / 8)))

#define BSP_RST_REG_FSP_IP_GPT(channel)            (R_CPG->CPG_RST_5)
#define BSP_RST_BIT_FSP_IP_GPT(channel)            (3U << (R_CPG_CPG_RST_5_RSTB9_Pos + ((channel / 8) * 2)))

#define BSP_RSTMON_REG_FSP_IP_GPT(channel)         (R_CPG->CPG_RSTMON_2)
#define BSP_RSTMON_BIT_FSP_IP_GPT(channel)         (3U << (R_CPG_CPG_RSTMON_2_RST10_MON_Pos + ((channel / 8) * 2)))

/***********************************************************************************************************************
 * Definition of macros to control POEG clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_POEG(channel)         (R_CPG->CPG_CLKON_3)
#define BSP_CLKON_BIT_FSP_IP_POEG(channel)         (1U << (R_CPG_CPG_CLKON_3_CLK3_ON_Pos + (channel)))
#define BSP_CLKMON_REG_FSP_IP_POEG(channel)        (R_CPG->CPG_CLKMON_1)
#define BSP_CLKMON_BIT_FSP_IP_POEG(channel)        (1U << (R_CPG_CPG_CLKMON_1_CLK19_MON_Pos + (channel)))
#define BSP_RST_REG_FSP_IP_POEG(channel)           *((channel < 3) ? &R_CPG->CPG_RST_5 : &R_CPG->CPG_RST_6)
#define BSP_RST_BIT_FSP_IP_POEG(channel)           ((channel < 3) ? (1U << (R_CPG_CPG_RST_5_RSTB13_Pos + (channel))) \
                                                    : (1U << (R_CPG_CPG_RST_6_RSTB0_Pos + (channel) - 3)))
#define BSP_RSTMON_REG_FSP_IP_POEG(channel)        (R_CPG->CPG_RSTMON_2)
#define BSP_RSTMON_BIT_FSP_IP_POEG(channel)        (1U << (R_CPG_CPG_RSTMON_2_RST14_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control PORT clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/

/* RZ/V2N does not have GPIO clock ON/OFF and reset ON/OFF functions. */
#define BSP_CLKON_REG_FSP_IP_PORT
#define BSP_CLKON_BIT_FSP_IP_PORT
#define BSP_CLKMON_REG_FSP_IP_PORT
#define BSP_CLKMON_BIT_FSP_IP_PORT
#define BSP_RST_REG_FSP_IP_PORT
#define BSP_RST_BIT_FSP_IP_PORT
#define BSP_RSTMON_REG_FSP_IP_PORT
#define BSP_RSTMON_BIT_FSP_IP_PORT

/***********************************************************************************************************************
 * Definition of macros to control IM33 clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/

/* RZ/V2N does not have IM33 clock ON/OFF and reset ON/OFF functions. */
#define BSP_CLKON_REG_FSP_IP_IM33
#define BSP_CLKON_BIT_FSP_IP_IM33
#define BSP_CLKMON_REG_FSP_IP_IM33
#define BSP_CLKMON_BIT_FSP_IP_IM33
#define BSP_RST_REG_FSP_IP_IM33
#define BSP_RST_BIT_FSP_IP_IM33
#define BSP_RSTMON_REG_FSP_IP_IM33
#define BSP_RSTMON_BIT_FSP_IP_IM33

/***********************************************************************************************************************
 * Definition of macros to control SCIF clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_SCIF(channel)     (R_CPG->CPG_CLKON_8)
#define BSP_CLKON_BIT_FSP_IP_SCIF(channel)     (1U << R_CPG_CPG_CLKON_8_CLK15_ON_Pos)

#define BSP_CLKMON_REG_FSP_IP_SCIF(channel)    (R_CPG->CPG_CLKMON_4)
#define BSP_CLKMON_BIT_FSP_IP_SCIF(channel)    (1U << R_CPG_CPG_CLKMON_4_CLK15_MON_Pos)

#define BSP_RST_REG_FSP_IP_SCIF(channel)       (R_CPG->CPG_RST_9)
#define BSP_RST_BIT_FSP_IP_SCIF(channel)       (1U << R_CPG_CPG_RST_9_RSTB5_Pos)

#define BSP_RSTMON_REG_FSP_IP_SCIF(channel)    (R_CPG->CPG_RSTMON_4)
#define BSP_RSTMON_BIT_FSP_IP_SCIF(channel)    (1U << R_CPG_CPG_RSTMON_4_RST6_MON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control RIIC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_RIIC(channel)     (R_CPG->CPG_CLKON_9)
#define BSP_CLKON_BIT_FSP_IP_RIIC(channel)     ((channel ==                                                                      \
                                                 8) ? (1U << R_CPG_CPG_CLKON_9_CLK3_ON_Pos) : (1U <<                             \
                                                                                               (                                 \
                                                                                                   R_CPG_CPG_CLKON_9_CLK4_ON_Pos \
                                                                                                   + (channel))))

#define BSP_CLKMON_REG_FSP_IP_RIIC(channel)    (R_CPG->CPG_CLKMON_4)
#define BSP_CLKMON_BIT_FSP_IP_RIIC(channel)    ((channel ==                                                                            \
                                                 8) ? (1U << R_CPG_CPG_CLKMON_4_CLK19_MON_Pos) : (1U <<                                \
                                                                                                  (                                    \
                                                                                                      R_CPG_CPG_CLKMON_4_CLK20_MON_Pos \
                                                                                                      + (channel))))

#define BSP_RST_REG_FSP_IP_RIIC(channel)       *((channel == 8) ? &R_CPG->CPG_RST_10 : &R_CPG->CPG_RST_9)
#define BSP_RST_BIT_FSP_IP_RIIC(channel)       ((channel ==                                                              \
                                                 8) ? (1U << R_CPG_CPG_RST_10_RSTB0_Pos) : (1U <<                        \
                                                                                            (R_CPG_CPG_RST_9_RSTB8_Pos + \
                                                                                             (channel))))

#define BSP_RSTMON_REG_FSP_IP_RIIC(channel)    (R_CPG->CPG_RSTMON_4)
#define BSP_RSTMON_BIT_FSP_IP_RIIC(channel)    (1U << (R_CPG_CPG_RSTMON_4_RST9_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control RSPI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_RST_REG_FSP_IP_RSPI
#define BSP_RST_BIT_FSP_IP_RSPI
#define BSP_RSTMON_REG_FSP_IP_RSPI
#define BSP_RSTMON_BIT_FSP_IP_RSPI

#define FSP_IP_RSPIP
#define FSP_IP_RSPIT

#define BSP_CLKON_REG_FSP_IP_RSPI(channel)           (R_CPG->CPG_CLKON_5)
#define BSP_CLKON_BIT_FSP_IP_RSPI(channel)           (7U << (R_CPG_CPG_CLKON_5_CLK4_ON_Pos + (3 * (channel))))

#define BSP_CLKMON_REG_FSP_IP_RSPI(channel)          (R_CPG->CPG_CLKMON_2)
#define BSP_CLKMON_BIT_FSP_IP_RSPI(channel)          (7U << (R_CPG_CPG_CLKMON_2_CLK20_MON_Pos + (3 * (channel))))

#define BSP_RST_REG_FSP_IP_RSPIP(channel)            (R_CPG->CPG_RST_7)
#define BSP_RST_REG_FSP_IP_RSPIT(channel)            *((channel == 2) ? &R_CPG->CPG_RST_8 : &R_CPG->CPG_RST_7)
#define BSP_RST_BIT_FSP_IP_RSPIP(channel)            (1U << (R_CPG_CPG_RST_7_RSTB11_Pos + (2 * (channel))))
#define BSP_RST_BIT_FSP_IP_RSPIT(channel)            ((channel ==                                                               \
                                                       2) ? (1U << R_CPG_CPG_RST_8_RSTB0_Pos) : (1U <<                          \
                                                                                                 (                              \
                                                                                                     R_CPG_CPG_RST_7_RSTB12_Pos \
                                                                                                     + 2 * (channel))))

#define BSP_RSTMON_REG_FSP_IP_RSPIP(channel)         (R_CPG->CPG_RSTMON_3)
#define BSP_RSTMON_REG_FSP_IP_RSPIT(channel)         (R_CPG->CPG_RSTMON_3)
#define BSP_RSTMON_BIT_FSP_IP_RSPIP(channel)         (1U << (R_CPG_CPG_RSTMON_3_RST12_MON_Pos + (2 * (channel))))
#define BSP_RSTMON_BIT_FSP_IP_RSPIT(channel)         (1U << (R_CPG_CPG_RSTMON_3_RST13_MON_Pos + (2 * (channel))))

/***********************************************************************************************************************
 * Definition of macros to control MHU clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_MHU(channel)            (R_CPG->CPG_CLKON_3)
#define BSP_CLKON_BIT_FSP_IP_MHU(channel)            (1U << R_CPG_CPG_CLKON_3_CLK0_ON_Pos)

#define BSP_CLKMON_REG_FSP_IP_MHU(channel)           (R_CPG->CPG_CLKMON_1)
#define BSP_CLKMON_BIT_FSP_IP_MHU(channel)           (1U << R_CPG_CPG_CLKMON_1_CLK16_MON_Pos)

#define BSP_RST_REG_FSP_IP_MHU(channel)              (R_CPG->CPG_RST_5)
#define BSP_RST_BIT_FSP_IP_MHU(channel)              (1U << R_CPG_CPG_RST_5_RSTB8_Pos)

#define BSP_RSTMON_REG_FSP_IP_MHU(channel)           (R_CPG->CPG_RSTMON_2)
#define BSP_RSTMON_BIT_FSP_IP_MHU(channel)           (1U << R_CPG_CPG_RSTMON_2_RST9_MON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control DMAC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_DMAC(channel)           (R_CPG->CPG_CLKON_0)
#define BSP_CLKON_BIT_FSP_IP_DMAC(channel)           (0x1FU << R_CPG_CPG_CLKON_0_CLK0_ON_Pos)

#define BSP_CLKMON_REG_FSP_IP_DMAC(channel)          (R_CPG->CPG_CLKMON_0)
#define BSP_CLKMON_BIT_FSP_IP_DMAC(channel)          (0x1FU << R_CPG_CPG_CLKMON_0_CLK0_MON_Pos)

#define BSP_RST_REG_FSP_IP_DMAC(channel)             (R_CPG->CPG_RST_3)
#define BSP_RST_BIT_FSP_IP_DMAC(channel)             (0x1FU << R_CPG_CPG_RST_3_RSTB1_Pos)

#define BSP_RSTMON_REG_FSP_IP_DMAC(channel)          (R_CPG->CPG_RSTMON_1)
#define BSP_RSTMON_BIT_FSP_IP_DMAC(channel)          (0x1FU << R_CPG_CPG_RSTMON_1_RST2_MON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control SSI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define FSP_IP_SSI_COMMON

#define BSP_CLKON_REG_FSP_IP_SSI(channel)            (R_CPG->CPG_CLKON_15)
#define BSP_CLKON_BIT_FSP_IP_SSI(channel)            (1U << R_CPG_CPG_CLKON_15_CLK5_ON_Pos)

#define BSP_CLKMON_REG_FSP_IP_SSI(channel)           (R_CPG->CPG_CLKMON_7)
#define BSP_CLKMON_BIT_FSP_IP_SSI(channel)           (1U << R_CPG_CPG_CLKMON_7_CLK21_MON_Pos)

#define BSP_RST_REG_FSP_IP_SSI(channel)              (R_CPG->CPG_RST_14)
#define BSP_RST_REG_FSP_IP_SSI_COMMON(channel)       (R_CPG->CPG_RST_14)
#define BSP_RST_BIT_FSP_IP_SSI(channel)              (1U << (R_CPG_CPG_RST_14_RSTB2_Pos + (channel)))
#define BSP_RST_BIT_FSP_IP_SSI_COMMON(channel)       (1U << R_CPG_CPG_RST_14_RSTB1_Pos)

#define BSP_RSTMON_REG_FSP_IP_SSI(channel)           (R_CPG->CPG_RSTMON_6)
#define BSP_RSTMON_REG_FSP_IP_SSI_COMMON(channel)    (R_CPG->CPG_RSTMON_6)
#define BSP_RSTMON_BIT_FSP_IP_SSI(channel)           (1U << (R_CPG_CPG_RSTMON_6_RST19_MON_Pos + (channel)))
#define BSP_RSTMON_BIT_FSP_IP_SSI_COMMON(channel)    (1U << R_CPG_CPG_RSTMON_6_RST18_MON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control CANFD clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_CANFD(channel)          (R_CPG->CPG_CLKON_9)
#define BSP_CLKON_BIT_FSP_IP_CANFD(channel)          (7U << R_CPG_CPG_CLKON_9_CLK12_ON_Pos)

#define BSP_CLKMON_REG_FSP_IP_CANFD(channel)         (R_CPG->CPG_CLKMON_4)
#define BSP_CLKMON_BIT_FSP_IP_CANFD(channel)         (7U << R_CPG_CPG_CLKMON_4_CLK28_MON_Pos)

#define BSP_RST_REG_FSP_IP_CANFD(channel)            (R_CPG->CPG_RST_10)
#define BSP_RST_BIT_FSP_IP_CANFD(channel)            (3U << R_CPG_CPG_RST_10_RSTB1_Pos)

#define BSP_RSTMON_REG_FSP_IP_CANFD(channel)         (R_CPG->CPG_RSTMON_4)
#define BSP_RSTMON_BIT_FSP_IP_CANFD(channel)         (3U << R_CPG_CPG_RSTMON_4_RST18_MON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control ADC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_ADC(channel)            (R_CPG->CPG_CLKON_16)
#define BSP_CLKON_BIT_FSP_IP_ADC(channel)            (3U << R_CPG_CPG_CLKON_16_CLK7_ON_Pos)

#define BSP_CLKMON_REG_FSP_IP_ADC(channel)           (R_CPG->CPG_CLKMON_8)
#define BSP_CLKMON_BIT_FSP_IP_ADC(channel)           (3U << R_CPG_CPG_CLKMON_8_CLK7_MON_Pos)

#define BSP_RST_REG_FSP_IP_ADC(channel)              (R_CPG->CPG_RST_15)
#define BSP_RST_BIT_FSP_IP_ADC(channel)              (1U << R_CPG_CPG_RST_15_RSTB6_Pos)

#define BSP_RSTMON_REG_FSP_IP_ADC(channel)           (R_CPG->CPG_RSTMON_7)
#define BSP_RSTMON_BIT_FSP_IP_ADC(channel)           (1U << R_CPG_CPG_RSTMON_7_RST7_MON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control TSU clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_TSU(channel)            (R_CPG->CPG_CLKON_16)
#define BSP_CLKON_BIT_FSP_IP_TSU(channel)            (1U << (R_CPG_CPG_CLKON_16_CLK9_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_TSU(channel)           (R_CPG->CPG_CLKMON_8)
#define BSP_CLKMON_BIT_FSP_IP_TSU(channel)           (1U << (R_CPG_CPG_CLKMON_8_CLK9_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_TSU(channel)              (R_CPG->CPG_RST_15)
#define BSP_RST_BIT_FSP_IP_TSU(channel)              (1U << (R_CPG_CPG_RST_15_RSTB7_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_TSU(channel)           (R_CPG->CPG_RSTMON_7)
#define BSP_RSTMON_BIT_FSP_IP_TSU(channel)           (1U << (R_CPG_CPG_RSTMON_7_RST8_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control WDT clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_WDT
#define BSP_CLKON_BIT_FSP_IP_WDT
#define BSP_CLKMON_REG_FSP_IP_WDT
#define BSP_CLKMON_BIT_FSP_IP_WDT

#define FSP_IP_WDT_CLKP
#define FSP_IP_WDT_LOCO

#define BSP_CLKON_REG_FSP_IP_WDT_CLKP(channel)     *((channel < 3) ? &R_CPG->CPG_CLKON_4 : &R_CPG->CPG_CLKON_5)
#define BSP_CLKON_REG_FSP_IP_WDT_LOCO(channel)     *((channel < 2) ? &R_CPG->CPG_CLKON_4 : &R_CPG->CPG_CLKON_5)
#define BSP_CLKON_BIT_FSP_IP_WDT_CLKP(channel)     ((channel <                                                         \
                                                     3) ? (1U <<                                                       \
                                                           (R_CPG_CPG_CLKON_4_CLK11_ON_Pos + 2U * (channel))) : (1U << \
                                                                                                                 R_CPG_CPG_CLKON_5_CLK1_ON_Pos))
#define BSP_CLKON_BIT_FSP_IP_WDT_LOCO(channel)     ((channel <                                                                                     \
                                                     2) ? (1U <<                                                                                   \
                                                           (R_CPG_CPG_CLKON_4_CLK12_ON_Pos + 2U * (channel))) : (1U <<                             \
                                                                                                                 (                                 \
                                                                                                                     R_CPG_CPG_CLKON_5_CLK0_ON_Pos \
                                                                                                                     +                             \
                                                                                                                     2U                            \
                                                                                                                     * (                           \
                                                                                                                         channel                   \
                                                                                                                         -                         \
                                                                                                                         2))))

#define BSP_CLKMON_REG_FSP_IP_WDT_CLKP(channel)    (R_CPG->CPG_CLKMON_2)
#define BSP_CLKMON_REG_FSP_IP_WDT_LOCO(channel)    (R_CPG->CPG_CLKMON_2)
#define BSP_CLKMON_BIT_FSP_IP_WDT_CLKP(channel)    (1U << (R_CPG_CPG_CLKMON_2_CLK11_MON_Pos + 2U * (channel)))
#define BSP_CLKMON_BIT_FSP_IP_WDT_LOCO(channel)    (1U << (R_CPG_CPG_CLKMON_2_CLK12_MON_Pos + 2U * (channel)))

#define BSP_RST_REG_FSP_IP_WDT(channel)            (R_CPG->CPG_RST_7)
#define BSP_RST_BIT_FSP_IP_WDT(channel)            (1U << (R_CPG_CPG_RST_7_RSTB5_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_WDT(channel)         (R_CPG->CPG_RSTMON_3)
#define BSP_RSTMON_BIT_FSP_IP_WDT(channel)         (1U << (R_CPG_CPG_RSTMON_3_RST6_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control SCI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_SCI
#define BSP_CLKON_BIT_FSP_IP_SCI
#define BSP_CLKMON_REG_FSP_IP_SCI
#define BSP_CLKMON_BIT_FSP_IP_SCI
#define BSP_RST_REG_FSP_IP_SCI
#define BSP_RST_BIT_FSP_IP_SCI
#define BSP_RSTMON_REG_FSP_IP_SCI
#define BSP_RSTMON_BIT_FSP_IP_SCI

#define FSP_IP_SCIP
#define FSP_IP_SCIT
#define FSP_IP_SCIPS3
#define FSP_IP_SCIPS2
#define FSP_IP_SCIPS1

#define BSP_CLKON_REG_FSP_IP_SCIP(channel)       *((channel ==                                                           \
                                                    0) ? &R_CPG->CPG_CLKON_5 : ((channel <                               \
                                                                                 4) ? &R_CPG->CPG_CLKON_6 : ((channel <  \
                                                                                                              7) ?       \
                                                                                                             &R_CPG      \
                                                                                                             ->          \
                                                                                                             CPG_CLKON_7 \
                                                                                                             : &         \
                                                                                                             R_CPG       \
                                                                                                             ->          \
                                                                                                             CPG_CLKON_8)))
#define BSP_CLKON_REG_FSP_IP_SCIT(channel)       *((channel ==                                                           \
                                                    0) ? &R_CPG->CPG_CLKON_5 : ((channel <                               \
                                                                                 4) ? &R_CPG->CPG_CLKON_6 : ((channel <  \
                                                                                                              7) ?       \
                                                                                                             &R_CPG      \
                                                                                                             ->          \
                                                                                                             CPG_CLKON_7 \
                                                                                                             : &         \
                                                                                                             R_CPG       \
                                                                                                             ->          \
                                                                                                             CPG_CLKON_8)))
#define BSP_CLKON_REG_FSP_IP_SCIPS3(channel)     *((channel ==                                                           \
                                                    0) ? &R_CPG->CPG_CLKON_5 : ((channel <                               \
                                                                                 4) ? &R_CPG->CPG_CLKON_6 : ((channel <  \
                                                                                                              7) ?       \
                                                                                                             &R_CPG      \
                                                                                                             ->          \
                                                                                                             CPG_CLKON_7 \
                                                                                                             : &         \
                                                                                                             R_CPG       \
                                                                                                             ->          \
                                                                                                             CPG_CLKON_8)))
#define BSP_CLKON_REG_FSP_IP_SCIPS2(channel)     *(((channel <                                                      \
                                                     4) ? &R_CPG->CPG_CLKON_6 : ((channel <                         \
                                                                                  7) ? &R_CPG->CPG_CLKON_7 : &R_CPG \
                                                                                 ->CPG_CLKON_8)))
#define BSP_CLKON_REG_FSP_IP_SCIPS1(channel)     *(((channel <                                                      \
                                                     3) ? &R_CPG->CPG_CLKON_6 : ((channel <                         \
                                                                                  7) ? &R_CPG->CPG_CLKON_7 : &R_CPG \
                                                                                 ->CPG_CLKON_8)))

#define BSP_CLKON_BIT_FSP_IP_SCIP(channel)       ((channel ==                                                                                           \
                                                   0) ? (1U <<                                                                                          \
                                                         R_CPG_CPG_CLKON_5_CLK13_ON_Pos) : ((channel <                                                  \
                                                                                             4) ? (1U <<                                                \
                                                                                                   (                                                    \
                                                                                                       R_CPG_CPG_CLKON_6_CLK2_ON_Pos                    \
                                                                                                       + ((uint32_t) (                                  \
                                                                                                              channel -                                 \
                                                                                                              1)                                        \
                                                                                                          *                                             \
                                                                                                          5))) : ((                                     \
                                                                                                                      channel                           \
                                                                                                                      <                                 \
                                                                                                                      7)                                \
                                                                                                                  ? (                                   \
                                                                                                                      1U                                \
                                                                                                                          <<                            \
                                                                                                                      (                                 \
                                                                                                                          R_CPG_CPG_CLKON_7_CLK1_ON_Pos \
                                                                                                                          +                             \
                                                                                                                          ((                            \
                                                                                                                               uint32_t) (              \
                                                                                                                               channel                  \
                                                                                                                               -                        \
                                                                                                                               4)                       \
                                                                                                                           *                            \
                                                                                                                           5)))                         \
                                                                                                                  : (                                   \
                                                                                                                      1U                                \
                                                                                                                          <<                            \
                                                                                                                      (                                 \
                                                                                                                          R_CPG_CPG_CLKON_8_CLK0_ON_Pos \
                                                                                                                          +                             \
                                                                                                                          ((                            \
                                                                                                                               uint32_t) (              \
                                                                                                                               channel                  \
                                                                                                                               -                        \
                                                                                                                               7)                       \
                                                                                                                           *                            \
                                                                                                                           5))))))
#define BSP_CLKON_BIT_FSP_IP_SCIT(channel)       ((channel ==                                                                        \
                                                   0) ? (1U <<                                                                       \
                                                         R_CPG_CPG_CLKON_5_CLK14_ON_Pos) : ((channel <                               \
                                                                                             4) ? (1U <<                             \
                                                                                                   (                                 \
                                                                                                       R_CPG_CPG_CLKON_6_CLK3_ON_Pos \
                                                                                                       + ((uint32_t) ((              \
                                                                                                                          channel    \
                                                                                                                          -          \
                                                                                                                          1)         \
                                                                                                                      *              \
                                                                                                                      5))))          \
                                                                                            : ((channel <                            \
                                                                                                7)                                   \
                                                                                               ? (                                   \
                                                                                                   1U                                \
                                                                                                       <<                            \
                                                                                                   (                                 \
                                                                                                       R_CPG_CPG_CLKON_7_CLK2_ON_Pos \
                                                                                                       +                             \
                                                                                                       ((                            \
                                                                                                            uint32_t) ((             \
                                                                                                                           channel   \
                                                                                                                           -         \
                                                                                                                           4)        \
                                                                                                                       *             \
                                                                                                                       5))))         \
                                                                                               : (                                   \
                                                                                                   1U                                \
                                                                                                       <<                            \
                                                                                                   (                                 \
                                                                                                       R_CPG_CPG_CLKON_8_CLK1_ON_Pos \
                                                                                                       +                             \
                                                                                                       ((                            \
                                                                                                            uint32_t) ((             \
                                                                                                                           channel   \
                                                                                                                           -         \
                                                                                                                           7)        \
                                                                                                                       *             \
                                                                                                                       5)))))))
#define BSP_CLKON_BIT_FSP_IP_SCIPS3(channel)     ((channel ==                                                                                           \
                                                   0) ? (1U <<                                                                                          \
                                                         R_CPG_CPG_CLKON_5_CLK15_ON_Pos) : ((channel <                                                  \
                                                                                             4) ? (1U <<                                                \
                                                                                                   (                                                    \
                                                                                                       R_CPG_CPG_CLKON_6_CLK4_ON_Pos                    \
                                                                                                       + ((uint32_t) (                                  \
                                                                                                              channel -                                 \
                                                                                                              1) *                                      \
                                                                                                          5))) : ((                                     \
                                                                                                                      channel                           \
                                                                                                                      <                                 \
                                                                                                                      7)                                \
                                                                                                                  ? (                                   \
                                                                                                                      1U                                \
                                                                                                                          <<                            \
                                                                                                                      (                                 \
                                                                                                                          R_CPG_CPG_CLKON_7_CLK3_ON_Pos \
                                                                                                                          +                             \
                                                                                                                          ((                            \
                                                                                                                               uint32_t) (              \
                                                                                                                               channel                  \
                                                                                                                               -                        \
                                                                                                                               4)                       \
                                                                                                                           *                            \
                                                                                                                           5)))                         \
                                                                                                                  : (                                   \
                                                                                                                      1U                                \
                                                                                                                          <<                            \
                                                                                                                      (                                 \
                                                                                                                          R_CPG_CPG_CLKON_8_CLK2_ON_Pos \
                                                                                                                          +                             \
                                                                                                                          ((                            \
                                                                                                                               uint32_t) (              \
                                                                                                                               channel                  \
                                                                                                                               -                        \
                                                                                                                               7)                       \
                                                                                                                           *                            \
                                                                                                                           5))))))
#define BSP_CLKON_BIT_FSP_IP_SCIPS2(channel)     (((channel <                                                                                          \
                                                    4) ? (1U <<                                                                                        \
                                                          (R_CPG_CPG_CLKON_6_CLK0_ON_Pos + (channel) * 5)) : ((channel <                               \
                                                                                                               7) ? (1U                                \
                                                                                                                     <<                                \
                                                                                                                     (                                 \
                                                                                                                         R_CPG_CPG_CLKON_7_CLK4_ON_Pos \
                                                                                                                         + ((                          \
                                                                                                                                uint32_t) (            \
                                                                                                                                channel                \
                                                                                                                                -                      \
                                                                                                                                4)                     \
                                                                                                                            *                          \
                                                                                                                            5)))                       \
                                                                                                              : (1U <<                                 \
                                                                                                                 (                                     \
                                                                                                                     R_CPG_CPG_CLKON_8_CLK3_ON_Pos     \
                                                                                                                     +                                 \
                                                                                                                     ((                                \
                                                                                                                          uint32_t) (                  \
                                                                                                                          channel                      \
                                                                                                                          -                            \
                                                                                                                          7)                           \
                                                                                                                      *                                \
                                                                                                                      5))))))
#define BSP_CLKON_BIT_FSP_IP_SCIPS1(channel)     (((channel <                                                                                          \
                                                    3) ? (1U <<                                                                                        \
                                                          (R_CPG_CPG_CLKON_6_CLK1_ON_Pos + (channel) * 5)) : ((channel <                               \
                                                                                                               7) ? (1U                                \
                                                                                                                     <<                                \
                                                                                                                     (                                 \
                                                                                                                         R_CPG_CPG_CLKON_7_CLK0_ON_Pos \
                                                                                                                         + ((                          \
                                                                                                                                uint32_t) (            \
                                                                                                                                channel                \
                                                                                                                                -                      \
                                                                                                                                3)                     \
                                                                                                                            *                          \
                                                                                                                            5)))                       \
                                                                                                              : (1U <<                                 \
                                                                                                                 (                                     \
                                                                                                                     R_CPG_CPG_CLKON_8_CLK4_ON_Pos     \
                                                                                                                     +                                 \
                                                                                                                     ((                                \
                                                                                                                          uint32_t) (                  \
                                                                                                                          channel                      \
                                                                                                                          -                            \
                                                                                                                          7)                           \
                                                                                                                      *                                \
                                                                                                                      5))))))

#define BSP_CLKMON_REG_FSP_IP_SCIP(channel)      *((channel ==                                                  \
                                                    0) ? &R_CPG->CPG_CLKMON_2 : ((channel <                     \
                                                                                  7) ? &R_CPG->CPG_CLKMON_3 : & \
                                                                                 R_CPG->CPG_CLKMON_4))
#define BSP_CLKMON_REG_FSP_IP_SCIT(channel)      *((channel ==                                                  \
                                                    0) ? &R_CPG->CPG_CLKMON_2 : ((channel <                     \
                                                                                  7) ? &R_CPG->CPG_CLKMON_3 : & \
                                                                                 R_CPG->CPG_CLKMON_4))
#define BSP_CLKMON_REG_FSP_IP_SCIPS3(channel)    *((channel ==                                                  \
                                                    0) ? &R_CPG->CPG_CLKMON_2 : ((channel <                     \
                                                                                  7) ? &R_CPG->CPG_CLKMON_3 : & \
                                                                                 R_CPG->CPG_CLKMON_4))
#define BSP_CLKMON_REG_FSP_IP_SCIPS2(channel)    *((channel < 7) ? &R_CPG->CPG_CLKMON_3 : &R_CPG->CPG_CLKMON_4)
#define BSP_CLKMON_REG_FSP_IP_SCIPS1(channel)    *((channel < 7) ? &R_CPG->CPG_CLKMON_3 : &R_CPG->CPG_CLKMON_4)
#define BSP_CLKMON_BIT_FSP_IP_SCIP(channel)      ((channel ==                                                                                           \
                                                   0) ? (1U <<                                                                                          \
                                                         R_CPG_CPG_CLKMON_2_CLK29_MON_Pos) : ((channel <                                                \
                                                                                               7) ? (1U <<                                              \
                                                                                                     (                                                  \
                                                                                                         R_CPG_CPG_CLKMON_3_CLK2_MON_Pos                \
                                                                                                         + ((uint32_t) (                                \
                                                                                                                channel                                 \
                                                                                                                -                                       \
                                                                                                                1)                                      \
                                                                                                            *                                           \
                                                                                                            5))) : (1U                                  \
                                                                                                                    <<                                  \
                                                                                                                    (                                   \
                                                                                                                        R_CPG_CPG_CLKMON_4_CLK0_MON_Pos \
                                                                                                                        +                               \
                                                                                                                        ((                              \
                                                                                                                             uint32_t) (                \
                                                                                                                             channel                    \
                                                                                                                             -                          \
                                                                                                                             7)                         \
                                                                                                                         *                              \
                                                                                                                         5)))))
#define BSP_CLKMON_BIT_FSP_IP_SCIT(channel)      ((channel ==                                                                            \
                                                   0) ? (1U <<                                                                           \
                                                         R_CPG_CPG_CLKMON_2_CLK30_MON_Pos) : ((channel <                                 \
                                                                                               7) ? (1U <<                               \
                                                                                                     (                                   \
                                                                                                         R_CPG_CPG_CLKMON_3_CLK3_MON_Pos \
                                                                                                         + ((uint32_t) ((                \
                                                                                                                            channel      \
                                                                                                                            -            \
                                                                                                                            1)           \
                                                                                                                        *                \
                                                                                                                        5))))            \
                                                                                              : (1U <<                                   \
                                                                                                 (                                       \
                                                                                                     R_CPG_CPG_CLKMON_4_CLK1_MON_Pos     \
                                                                                                     +                                   \
                                                                                                     ((                                  \
                                                                                                          uint32_t) ((                   \
                                                                                                                         channel         \
                                                                                                                         -               \
                                                                                                                         7)              \
                                                                                                                     *                   \
                                                                                                                     5))))))
#define BSP_CLKMON_BIT_FSP_IP_SCIPS3(channel)    ((channel ==                                                                            \
                                                   0) ? (1U <<                                                                           \
                                                         R_CPG_CPG_CLKMON_2_CLK31_MON_Pos) : ((channel <                                 \
                                                                                               7) ? (1U <<                               \
                                                                                                     (                                   \
                                                                                                         R_CPG_CPG_CLKMON_3_CLK4_MON_Pos \
                                                                                                         + ((uint32_t) ((                \
                                                                                                                            channel      \
                                                                                                                            -            \
                                                                                                                            1)           \
                                                                                                                        *                \
                                                                                                                        5))))            \
                                                                                              : (1U <<                                   \
                                                                                                 (                                       \
                                                                                                     R_CPG_CPG_CLKMON_4_CLK2_MON_Pos     \
                                                                                                     +                                   \
                                                                                                     ((                                  \
                                                                                                          uint32_t) ((                   \
                                                                                                                         channel         \
                                                                                                                         -               \
                                                                                                                         7)              \
                                                                                                                     *                   \
                                                                                                                     5))))))
#define BSP_CLKMON_BIT_FSP_IP_SCIPS2(channel)    ((channel <                                                                                         \
                                                   7) ? (1U <<                                                                                       \
                                                         (R_CPG_CPG_CLKMON_3_CLK0_MON_Pos + ((channel) * 5))) : (1U <<                               \
                                                                                                                 (                                   \
                                                                                                                     R_CPG_CPG_CLKMON_4_CLK3_MON_Pos \
                                                                                                                     +                               \
                                                                                                                     ((                              \
                                                                                                                          uint32_t) ((               \
                                                                                                                                         channel     \
                                                                                                                                         -           \
                                                                                                                                         7)          \
                                                                                                                                     *               \
                                                                                                                                     5)))))
#define BSP_CLKMON_BIT_FSP_IP_SCIPS1(channel)    ((channel <                                                                                         \
                                                   7) ? (1U <<                                                                                       \
                                                         (R_CPG_CPG_CLKMON_3_CLK1_MON_Pos + ((channel) * 5))) : (1U <<                               \
                                                                                                                 (                                   \
                                                                                                                     R_CPG_CPG_CLKMON_4_CLK4_MON_Pos \
                                                                                                                     +                               \
                                                                                                                     ((                              \
                                                                                                                          uint32_t) ((               \
                                                                                                                                         channel     \
                                                                                                                                         -           \
                                                                                                                                         7)          \
                                                                                                                                     *               \
                                                                                                                                     5)))))

#define BSP_RST_REG_FSP_IP_SCIP(channel)         *((channel < 8) ? &R_CPG->CPG_RST_8 : &R_CPG->CPG_RST_9)
#define BSP_RST_REG_FSP_IP_SCIT(channel)         *((channel < 7) ? &R_CPG->CPG_RST_8 : &R_CPG->CPG_RST_9)
#define BSP_RST_BIT_FSP_IP_SCIP(channel)         ((channel <                                                                                 \
                                                   8) ? (1U << (R_CPG_CPG_RST_8_RSTB1_Pos + (2 * channel))) : (1U <<                         \
                                                                                                               (                             \
                                                                                                                   R_CPG_CPG_RST_9_RSTB1_Pos \
                                                                                                                   + ((                      \
                                                                                                                          uint32_t) (        \
                                                                                                                          2                  \
                                                                                                                          *                  \
                                                                                                                          (                  \
                                                                                                                              channel        \
                                                                                                                              -              \
                                                                                                                              8))))))
#define BSP_RST_BIT_FSP_IP_SCIT(channel)         ((channel <                                                                    \
                                                   7) ? (1U << (R_CPG_CPG_RST_8_RSTB2_Pos + (2 * channel))) : (1U <<            \
                                                                                                               ((               \
                                                                                                                    uint32_t) ( \
                                                                                                                    2 *         \
                                                                                                                    (           \
                                                                                                                        channel \
                                                                                                                        -       \
                                                                                                                        7)))))

#define BSP_RSTMON_REG_FSP_IP_SCIP(channel)      *((channel < 7) ? &R_CPG->CPG_RSTMON_3 : &R_CPG->CPG_RSTMON_4)
#define BSP_RSTMON_REG_FSP_IP_SCIT(channel)      *((channel < 7) ? &R_CPG->CPG_RSTMON_3 : &R_CPG->CPG_RSTMON_4)

#define BSP_RSTMON_BIT_FSP_IP_SCIP(channel)      ((channel <                                                                       \
                                                   7) ? (1U <<                                                                     \
                                                         (R_CPG_CPG_RSTMON_3_RST18_MON_Pos + (2 * (channel)))) : (1U <<            \
                                                                                                                  ((               \
                                                                                                                       uint32_t) ( \
                                                                                                                       2           \
                                                                                                                       * (         \
                                                                                                                           channel \
                                                                                                                           -       \
                                                                                                                           7)))))
#define BSP_RSTMON_BIT_FSP_IP_SCIT(channel)      ((channel <                                                                                          \
                                                   7) ? (1U <<                                                                                        \
                                                         (R_CPG_CPG_RSTMON_3_RST19_MON_Pos + (2 * (channel)))) : (1U <<                               \
                                                                                                                  (                                   \
                                                                                                                      R_CPG_CPG_RSTMON_4_RST1_MON_Pos \
                                                                                                                      +                               \
                                                                                                                      ((                              \
                                                                                                                           uint32_t) (                \
                                                                                                                           2                          \
                                                                                                                           * (                        \
                                                                                                                               channel                \
                                                                                                                               -                      \
                                                                                                                               7))))))

/***********************************************************************************************************************
 * Definition of macros to control CMTW clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_CMTW(channel)       *((channel < 5) ? &R_CPG->CPG_CLKON_3 : &R_CPG->CPG_CLKON_4)
#define BSP_CLKON_BIT_FSP_IP_CMTW(channel)       ((channel <                                                         \
                                                   5) ? (1U << (R_CPG_CPG_CLKON_3_CLK11_ON_Pos + (channel))) : 1U << \
                                                  (R_CPG_CPG_CLKON_4_CLK0_ON_Pos + ((channel) - 5)))

#define BSP_CLKMON_REG_FSP_IP_CMTW(channel)      *((channel < 5) ? &R_CPG->CPG_CLKMON_1 : &R_CPG->CPG_CLKMON_2)
#define BSP_CLKMON_BIT_FSP_IP_CMTW(channel)      ((channel <                                                           \
                                                   5) ? (1U << (R_CPG_CPG_CLKMON_1_CLK27_MON_Pos + (channel))) : 1U << \
                                                  (R_CPG_CPG_CLKMON_2_CLK0_MON_Pos + ((channel) - 5)))

#define BSP_RST_REG_FSP_IP_CMTW(channel)         *(&R_CPG->CPG_RST_6)
#define BSP_RST_BIT_FSP_IP_CMTW(channel)         (1U << (R_CPG_CPG_RST_6_RSTB5_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_CMTW(channel)      *(&R_CPG->CPG_RSTMON_2)
#define BSP_RSTMON_BIT_FSP_IP_CMTW(channel)      (1U << (R_CPG_CPG_RSTMON_2_RST22_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control xSPI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define FSP_IP_XSPI_H
#define FSP_IP_XSPI_OTHER

#define BSP_CLKON_REG_FSP_IP_XSPI_H(channel)         (R_CPG->CPG_CLKON_9)
#define BSP_CLKON_REG_FSP_IP_XSPI_OTHER(channel)     (R_CPG->CPG_CLKON_10)
#define BSP_CLKON_BIT_FSP_IP_XSPI_H(channel)         (1U << R_CPG_CPG_CLKON_9_CLK15_ON_Pos)
#define BSP_CLKON_BIT_FSP_IP_XSPI_OTHER(channel)     (3U << R_CPG_CPG_CLKON_10_CLK0_ON_Pos)

#define BSP_CLKMON_REG_FSP_IP_XSPI_H(channel)        (R_CPG->CPG_CLKMON_4)
#define BSP_CLKMON_REG_FSP_IP_XSPI_OTHER(channel)    (R_CPG->CPG_CLKMON_5)
#define BSP_CLKMON_BIT_FSP_IP_XSPI_H(channel)        (1U << R_CPG_CPG_CLKMON_4_CLK31_MON_Pos)
#define BSP_CLKMON_BIT_FSP_IP_XSPI_OTHER(channel)    (7U << R_CPG_CPG_CLKMON_5_CLK0_MON_Pos)

#define BSP_RST_REG_FSP_IP_XSPI(channel)             (R_CPG->CPG_RST_10)
#define BSP_RST_BIT_FSP_IP_XSPI(channel)             (3U << R_CPG_CPG_RST_10_RSTB3_Pos)

#define BSP_RSTMON_REG_FSP_IP_XSPI(channel)          (R_CPG->CPG_RSTMON_4)
#define BSP_RSTMON_BIT_FSP_IP_XSPI(channel)          (3U << R_CPG_CPG_RSTMON_4_RST20_MON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control CRC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_CRC(channel)            (R_CPG->CPG_CLKON_0)
#define BSP_CLKON_BIT_FSP_IP_CRC(channel)            (1U << (R_CPG_CPG_CLKON_0_CLK6_ON_Pos))

#define BSP_CLKMON_REG_FSP_IP_CRC(channel)           (R_CPG->CPG_CLKMON_0)
#define BSP_CLKMON_BIT_FSP_IP_CRC(channel)           (1U << (R_CPG_CPG_CLKMON_0_CLK6_MON_Pos))

#define BSP_RST_REG_FSP_IP_CRC(channel)              (R_CPG->CPG_RST_3)
#define BSP_RST_BIT_FSP_IP_CRC(channel)              (1U << (R_CPG_CPG_RST_7_RSTB7_Pos))

#define BSP_RSTMON_REG_FSP_IP_CRC(channel)           (R_CPG->CPG_RSTMON_1)
#define BSP_RSTMON_BIT_FSP_IP_CRC(channel)           (1U << (R_CPG_CPG_RSTMON_1_RST8_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control I3C clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_I3C(channel)            (R_CPG->CPG_CLKON_9)
#define BSP_CLKON_BIT_FSP_IP_I3C(channel)            (7U << (R_CPG_CPG_CLKON_9_CLK0_ON_Pos))

#define BSP_CLKMON_REG_FSP_IP_I3C(channel)           (R_CPG->CPG_CLKMON_4)
#define BSP_CLKMON_BIT_FSP_IP_I3C(channel)           (7U << (R_CPG_CPG_CLKMON_4_CLK16_MON_Pos))

#define BSP_RST_REG_FSP_IP_I3C(channel)              (R_CPG->CPG_RST_9)
#define BSP_RST_BIT_FSP_IP_I3C(channel)              (3U << (R_CPG_CPG_RST_9_RSTB6_Pos))

#define BSP_RSTMON_REG_FSP_IP_I3C(channel)           (R_CPG->CPG_RSTMON_4)
#define BSP_RSTMON_BIT_FSP_IP_I3C(channel)           (3U << (R_CPG_CPG_RSTMON_4_RST7_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control RTC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_RTC(channel)            (R_CPG->CPG_CLKON_5)
#define BSP_CLKON_BIT_FSP_IP_RTC(channel)            (1U << (R_CPG_CPG_CLKON_5_CLK3_ON_Pos))

#define BSP_CLKMON_REG_FSP_IP_RTC(channel)           (R_CPG->CPG_CLKMON_2)
#define BSP_CLKMON_BIT_FSP_IP_RTC(channel)           (1U << (R_CPG_CPG_CLKMON_2_CLK19_MON_Pos))

#define BSP_RST_REG_FSP_IP_RTC(channel)              (R_CPG->CPG_RST_7)
#define BSP_RST_BIT_FSP_IP_RTC(channel)              (3U << (R_CPG_CPG_RST_7_RSTB9_Pos))

#define BSP_RSTMON_REG_FSP_IP_RTC(channel)           (R_CPG->CPG_RSTMON_3)
#define BSP_RSTMON_BIT_FSP_IP_RTC(channel)           (3U << (R_CPG_CPG_RSTMON_3_RST10_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control PDM clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_PDM(channel)            (R_CPG->CPG_CLKON_16)
#define BSP_CLKON_BIT_FSP_IP_PDM(channel)            (7U << ((R_CPG_CPG_CLKON_16_CLK1_ON_Pos) + (channel * 3)))

#define BSP_CLKMON_REG_FSP_IP_PDM(channel)           (R_CPG->CPG_CLKMON_8)
#define BSP_CLKMON_BIT_FSP_IP_PDM(channel)           (7U << ((R_CPG_CPG_CLKMON_8_CLK1_MON_Pos) + (channel * 3)))

#define BSP_RST_REG_FSP_IP_PDM(channel)              (R_CPG->CPG_RST_15)
#define BSP_RST_BIT_FSP_IP_PDM(channel)              (3U << ((R_CPG_CPG_RST_15_RSTB2_Pos) + (channel * 2)))

#define BSP_RSTMON_REG_FSP_IP_PDM(channel)           (R_CPG->CPG_RSTMON_7)
#define BSP_RSTMON_BIT_FSP_IP_PDM(channel)           (3U << ((R_CPG_CPG_RSTMON_7_RST3_MON_Pos) + (channel * 2)))

/***********************************************************************************************************************
 * Definition of macros to control SYC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_SYC(channel)            (R_CPG->CPG_CLKON_2)
#define BSP_CLKON_BIT_FSP_IP_SYC(channel)            (1U << (R_CPG_CPG_CLKON_2_CLK15_ON_Pos))

#define BSP_CLKMON_REG_FSP_IP_SYC(channel)           (R_CPG->CPG_CLKMON_1)
#define BSP_CLKMON_BIT_FSP_IP_SYC(channel)           (1U << (R_CPG_CPG_CLKMON_1_CLK15_MON_Pos))

#define BSP_RST_REG_FSP_IP_SYC(channel)              (R_CPG->CPG_RST_5)
#define BSP_RST_BIT_FSP_IP_SYC(channel)              (1U << (R_CPG_CPG_RST_5_RSTB7_Pos))

#define BSP_RSTMON_REG_FSP_IP_SYC(channel)           (R_CPG->CPG_RSTMON_2)
#define BSP_RSTMON_BIT_FSP_IP_SYC(channel)           (1U << (R_CPG_CPG_RSTMON_2_RST8_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control GTM module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_GTM(channel)             *((channel <                                                     \
                                                        2) ? &R_CPG->CPG_BUS_5_MSTOP : ((channel <                    \
                                                                                         4) ? &R_CPG->CPG_BUS_2_MSTOP \
                                                                                        : ((                          \
                                                                                               channel                \
                                                                                               <                      \
                                                                                               7)                     \
                                                                                           ?                          \
                                                                                           &                          \
                                                                                           R_CPG                      \
                                                                                           ->                         \
                                                                                           CPG_BUS_11_MSTOP           \
                                                                                           :                          \
                                                                                           &                          \
                                                                                           R_CPG                      \
                                                                                           ->                         \
                                                                                           CPG_BUS_12_MSTOP)))
#define BSP_MSTP_BIT_FSP_IP_GTM(channel)             ((channel <                                                                                      \
                                                       2) ? (1U <<                                                                                    \
                                                             (R_CPG_CPG_BUS_5_MSTOP_MSTOP10_ON_Pos +                                                  \
                                                              channel)) : ((channel <                                                                 \
                                                                            4) ? (1U <<                                                               \
                                                                                  ((R_CPG_CPG_BUS_2_MSTOP_MSTOP13_ON_Pos                              \
                                                                                    - 2) + channel)) : ((channel <                                    \
                                                                                                         7)                                           \
                                                                                                        ? (1U                                         \
                                                                                                           <<                                         \
                                                                                                           ((                                         \
                                                                                                                R_CPG_CPG_BUS_11_MSTOP_MSTOP13_ON_Pos \
                                                                                                                -                                     \
                                                                                                                4)                                    \
                                                                                                            +                                         \
                                                                                                            channel))                                 \
                                                                                                        : (                                           \
                                                                                                            1U <<                                     \
                                                                                                            ((                                        \
                                                                                                                 R_CPG_CPG_BUS_12_MSTOP_MSTOP0_ON_Pos \
                                                                                                                 - 7) +                               \
                                                                                                             channel)))))

/***********************************************************************************************************************
 * Definition of macros to control GPT module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_GPT(channel)             R_CPG->CPG_BUS_6_MSTOP
#define BSP_MSTP_BIT_FSP_IP_GPT(channel)             (1U << (R_CPG_CPG_BUS_6_MSTOP_MSTOP11_ON_Pos + (channel / 8)))

/***********************************************************************************************************************
 * Definition of macros to control POEG module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_POEG(channel)            (R_CPG->CPG_BUS_6_MSTOP)
#define BSP_MSTP_BIT_FSP_IP_POEG(channel)            (1U << (R_CPG_CPG_BUS_6_MSTOP_MSTOP3_ON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control PORT module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_PORT(channel)            R_CPG->CPG_BUS_4_MSTOP
#define BSP_MSTP_BIT_FSP_IP_PORT(channel)            (1U << R_CPG_CPG_BUS_4_MSTOP_MSTOP7_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control IM33 module START/STOP
 **********************************************************************************************************************/

/* RZ/V2N does not have IM33 module START/STOP functions. */
#define BSP_MSTP_REG_FSP_IP_IM33
#define BSP_MSTP_BIT_FSP_IP_IM33

/***********************************************************************************************************************
 * Definition of macros to control SCIF module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_SCIF(channel)    R_CPG->CPG_BUS_3_MSTOP
#define BSP_MSTP_BIT_FSP_IP_SCIF(channel)    (1U << R_CPG_CPG_BUS_3_MSTOP_MSTOP14_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control RIIC module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_RIIC(channel)    *((channel == \
                                                8) ? &R_CPG->CPG_BUS_3_MSTOP : &R_CPG->CPG_BUS_1_MSTOP)
#define BSP_MSTP_BIT_FSP_IP_RIIC(channel)    ((channel ==                                                                                   \
                                               8) ? (1U << R_CPG_CPG_BUS_3_MSTOP_MSTOP13_ON_Pos) : (1U <<                                   \
                                                                                                    (                                       \
                                                                                                        R_CPG_CPG_BUS_1_MSTOP_MSTOP1_ON_Pos \
                                                                                                        + (channel))))

/***********************************************************************************************************************
 * Definition of macros to control RSPI module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_RSPI(channel)    R_CPG->CPG_BUS_11_MSTOP
#define BSP_MSTP_BIT_FSP_IP_RSPI(channel)    (1U << (R_CPG_CPG_BUS_11_MSTOP_MSTOP0_ON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control MHU module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_MHU(channel)     R_CPG->CPG_BUS_4_MSTOP
#define BSP_MSTP_BIT_FSP_IP_MHU(channel)     (1U << R_CPG_CPG_BUS_4_MSTOP_MSTOP14_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control DMAC module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_DMAC
#define BSP_MSTP_BIT_FSP_IP_DMAC
#define BSP_MSTP_REG_FSP_IP_DMAC_s
#define BSP_MSTP_BIT_FSP_IP_DMAC_s

#define FSP_IP_DMAC0
#define FSP_IP_DMAC1
#define FSP_IP_DMAC2
#define FSP_IP_DMAC3
#define FSP_IP_DMAC4

#define BSP_MSTP_REG_FSP_IP_DMAC0(channel)       R_CPG->CPG_BUS_5_MSTOP
#define BSP_MSTP_BIT_FSP_IP_DMAC0(channel)       (1U << R_CPG_CPG_BUS_5_MSTOP_MSTOP9_ON_Pos)
#define BSP_MSTP_REG_FSP_IP_DMAC1(channel)       R_CPG->CPG_BUS_3_MSTOP
#define BSP_MSTP_BIT_FSP_IP_DMAC1(channel)       (1U << R_CPG_CPG_BUS_3_MSTOP_MSTOP2_ON_Pos)
#define BSP_MSTP_REG_FSP_IP_DMAC2(channel)       R_CPG->CPG_BUS_3_MSTOP
#define BSP_MSTP_BIT_FSP_IP_DMAC2(channel)       (1U << R_CPG_CPG_BUS_3_MSTOP_MSTOP3_ON_Pos)
#define BSP_MSTP_REG_FSP_IP_DMAC3(channel)       R_CPG->CPG_BUS_10_MSTOP
#define BSP_MSTP_BIT_FSP_IP_DMAC3(channel)       (1U << R_CPG_CPG_BUS_10_MSTOP_MSTOP11_ON_Pos)
#define BSP_MSTP_REG_FSP_IP_DMAC4(channel)       R_CPG->CPG_BUS_10_MSTOP
#define BSP_MSTP_BIT_FSP_IP_DMAC4(channel)       (1U << R_CPG_CPG_BUS_10_MSTOP_MSTOP12_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control SSI module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_SSI(channel)         R_CPG->CPG_BUS_2_MSTOP
#define BSP_MSTP_BIT_FSP_IP_SSI(channel)         (3U << R_CPG_CPG_BUS_2_MSTOP_MSTOP3_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control CANFD module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_CANFD(channel)       R_CPG->CPG_BUS_10_MSTOP
#define BSP_MSTP_BIT_FSP_IP_CANFD(channel)       (1U << R_CPG_CPG_BUS_10_MSTOP_MSTOP14_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control ADC module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_ADC(channel)         R_CPG->CPG_BUS_3_MSTOP
#define BSP_MSTP_BIT_FSP_IP_ADC(channel)         (1U << R_CPG_CPG_BUS_3_MSTOP_MSTOP9_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control TSU module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_TSU(channel)         *((channel == \
                                                    0) ? &R_CPG->CPG_BUS_5_MSTOP : &R_CPG->CPG_BUS_2_MSTOP)
#define BSP_MSTP_BIT_FSP_IP_TSU(channel)         ((channel ==                                                \
                                                   0) ? (1U << R_CPG_CPG_BUS_5_MSTOP_MSTOP2_ON_Pos) : (1U << \
                                                                                                       R_CPG_CPG_BUS_2_MSTOP_MSTOP15_ON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control WDT module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_WDT(channel)         *((channel <                                                         \
                                                    1) ? (&R_CPG->CPG_BUS_3_MSTOP) : ((channel <                      \
                                                                                       2) ? (&R_CPG->CPG_BUS_1_MSTOP) \
                                                                                      : &R_CPG->CPG_BUS_5_MSTOP))
#define BSP_MSTP_BIT_FSP_IP_WDT(channel)         ((channel <                                                                                                 \
                                                   1) ? (1U <<                                                                                               \
                                                         (channel + R_CPG_CPG_BUS_3_MSTOP_MSTOP10_ON_Pos)) : ((channel <                                     \
                                                                                                               2) ? (1U                                      \
                                                                                                                     << (                                    \
                                                                                                                         R_CPG_CPG_BUS_1_MSTOP_MSTOP0_ON_Pos \
                                                                                                                         + (                                 \
                                                                                                                             channel                         \
                                                                                                                             -                               \
                                                                                                                             1)))                            \
                                                                                                              : (1U <<                                       \
                                                                                                                 ((                                          \
                                                                                                                      channel                                \
                                                                                                                      -                                      \
                                                                                                                      2)                                     \
                                                                                                                  +                                          \
                                                                                                                  R_CPG_CPG_BUS_5_MSTOP_MSTOP12_ON_Pos))))

/***********************************************************************************************************************
 * Definition of macros to control SCI module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_SCI(channel)         R_CPG->CPG_BUS_11_MSTOP
#define BSP_MSTP_BIT_FSP_IP_SCI(channel)         (1U << (R_CPG_CPG_BUS_11_MSTOP_MSTOP3_ON_Pos + channel))

/***********************************************************************************************************************
 * Definition of macros to control CMTW module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_CMTW(channel)        *((channel < 1) ?                                                       \
                                                   &R_CPG->CPG_BUS_3_MSTOP : ((channel < 4) ?                            \
                                                                              &R_CPG->CPG_BUS_4_MSTOP : ((channel <      \
                                                                                                          5) ?           \
                                                                                                         &R_CPG->        \
                                                                                                         CPG_BUS_5_MSTOP \
                                                                                                         : &R_CPG->      \
                                                                                                         CPG_BUS_6_MSTOP)))
#define BSP_MSTP_BIT_FSP_IP_CMTW(channel)        ((channel < 1) ?                                                                                                     \
                                                  (1U <<                                                                                                              \
                                                   (R_CPG_CPG_BUS_3_MSTOP_MSTOP15_ON_Pos + channel)) : ((channel < 4) ?                                               \
                                                                                                        (1U <<                                                        \
                                                                                                         (                                                            \
                                                                                                             R_CPG_CPG_BUS_4_MSTOP_MSTOP0_ON_Pos                      \
                                                                                                             + ((channel)                                             \
                                                                                                                - 1))) : ((                                           \
                                                                                                                              channel                                 \
                                                                                                                              <                                       \
                                                                                                                              5)                                      \
                                                                                                                          ?                                           \
                                                                                                                          (                                           \
                                                                                                                              1U                                      \
                                                                                                                                  <<                                  \
                                                                                                                              ((                                      \
                                                                                                                                   channel                            \
                                                                                                                                   -                                  \
                                                                                                                                   4)                                 \
                                                                                                                               +                                      \
                                                                                                                               R_CPG_CPG_BUS_5_MSTOP_MSTOP15_ON_Pos)) \
                                                                                                                          : (                                         \
                                                                                                                              1U                                      \
                                                                                                                                  <<                                  \
                                                                                                                              (((                                     \
                                                                                                                                    channel)                          \
                                                                                                                                -                                     \
                                                                                                                                5)                                    \
                                                                                                                               +                                      \
                                                                                                                               R_CPG_CPG_BUS_6_MSTOP_MSTOP0_ON_Pos)))))

/***********************************************************************************************************************
 * Definition of macros to control xSPI module START/STOP
 **********************************************************************************************************************/
#define FSP_IP_XSPI_REG

#define BSP_MSTP_REG_FSP_IP_XSPI(channel)        R_CPG->CPG_BUS_4_MSTOP
#define BSP_MSTP_BIT_FSP_IP_XSPI(channel)        (1U << R_CPG_CPG_BUS_4_MSTOP_MSTOP5_ON_Pos)
#define BSP_MSTP_REG_FSP_IP_XSPI_REG(channel)    R_CPG->CPG_BUS_5_MSTOP
#define BSP_MSTP_BIT_FSP_IP_XSPI_REG(channel)    (1U << R_CPG_CPG_BUS_5_MSTOP_MSTOP5_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control CRC module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_CRC(channel)         R_CPG->CPG_BUS_5_MSTOP
#define BSP_MSTP_BIT_FSP_IP_CRC(channel)         (1U << (R_CPG_CPG_BUS_5_MSTOP_MSTOP14_ON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control I3C module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_I3C(channel)         R_CPG->CPG_BUS_10_MSTOP
#define BSP_MSTP_BIT_FSP_IP_I3C(channel)         (1U << (R_CPG_CPG_BUS_10_MSTOP_MSTOP15_ON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control RTC module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_RTC(channel)         R_CPG->CPG_BUS_3_MSTOP
#define BSP_MSTP_BIT_FSP_IP_RTC(channel)         (3U << (R_CPG_CPG_BUS_3_MSTOP_MSTOP11_ON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control PDM module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_PDM(channel)         R_CPG->CPG_BUS_5_MSTOP
#define BSP_MSTP_BIT_FSP_IP_PDM(channel)         (1U << ((R_CPG_CPG_BUS_5_MSTOP_MSTOP6_ON_Pos) + channel))

/***********************************************************************************************************************
 * Definition of macros to control SCI module START/STOP
 **********************************************************************************************************************/
#define BSP_MSTP_REG_FSP_IP_SYC(channel)         R_CPG->CPG_BUS_3_MSTOP
#define BSP_MSTP_BIT_FSP_IP_SYC(channel)         (1U << (R_CPG_CPG_BUS_3_MSTOP_MSTOP0_ON_Pos))

/***********************************************************************************************************************
 * Definition of macros to clear state flag of INTC IRQ
 **********************************************************************************************************************/
#define BSP_INTC_IRQ_CLR_STATE_FLAG(channel)                                    \
    do                                                                          \
    {                                                                           \
        /* Clear the ICLR bit. */                                               \
        BSP_FEATURE_INTC_BASE_ADDR->ISCLR = (INTC_IRQ_CLR_REG_MASK << channel); \
    } while (0);

/***********************************************************************************************************************
 * Definition of macros to clear state flag of INTC NMI
 **********************************************************************************************************************/
#define BSP_INTC_NMI_CLR_STATE_FLAG()                                \
    do                                                               \
    {                                                                \
        /* Dummy read the NSCNT before clearing the NCLR bit. */     \
        volatile uint32_t nscnt = BSP_FEATURE_INTC_BASE_ADDR->NSCNT; \
        FSP_PARAMETER_NOT_USED(nscnt);                               \
        /* Clear the NCLR bit. */                                    \
        BSP_FEATURE_INTC_BASE_ADDR->NSCLR_b.NCLR = 1;                \
        /* Dummy read the NSCNT to prevent the interrupt cause that have been cleared from being accidentally \
         * accepted again. */                      \
        nscnt = BSP_FEATURE_INTC_BASE_ADDR->NSCNT; \
        FSP_PARAMETER_NOT_USED(nscnt);             \
    } while (0);

/***********************************************************************************************************************
 * Definition of macros to clear state flag of INTC TINT
 **********************************************************************************************************************/
#define BSP_INTC_TINT_CLR_STATE_FLAG(channel)                                          \
    do                                                                                 \
    {                                                                                  \
        /* Dummy read the TSCTR before clearing the TCLR bit of the TSCLR register. */ \
        volatile uint32_t tsctr = BSP_FEATURE_INTC_BASE_ADDR->TSCTR;                   \
        FSP_PARAMETER_NOT_USED(tsctr);                                                 \
        /* Clear the TCLR bit. */                                                      \
        BSP_FEATURE_INTC_BASE_ADDR->TSCLR = (INTC_TINT_CLR_REG_MASK << channel);       \
        /* Dummy read the TSCTR to prevent the interrupt cause that should have been cleared from being accidentally \
         * accepted again. */                      \
        tsctr = BSP_FEATURE_INTC_BASE_ADDR->TSCTR; \
        FSP_PARAMETER_NOT_USED(tsctr);             \
    } while (0);

/*==============================================
 * ELC-Related Macros Overrides
 *==============================================*/

#define ELC_PERIPHERAL_NUM                     (45U)

/*==============================================
 * IOPORT-Related Macros Overrides
 *==============================================*/

#define OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET    (24)

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
} bsp_io_port_t;

/** Superset list of all possible IO port pins. */
typedef enum e_bsp_io_port_pin_t
{
    BSP_IO_PORT_00_PIN_00 = 0x0000,     /* IO port 0 pin 0 */
    BSP_IO_PORT_00_PIN_01 = 0x0001,     /* IO port 0 pin 1 */
    BSP_IO_PORT_00_PIN_02 = 0x0002,     /* IO port 0 pin 2 */
    BSP_IO_PORT_00_PIN_03 = 0x0003,     /* IO port 0 pin 3 */
    BSP_IO_PORT_00_PIN_04 = 0x0004,     /* IO port 0 pin 4 */
    BSP_IO_PORT_00_PIN_05 = 0x0005,     /* IO port 0 pin 5 */
    BSP_IO_PORT_00_PIN_06 = 0x0006,     /* IO port 0 pin 6 */
    BSP_IO_PORT_00_PIN_07 = 0x0007,     /* IO port 0 pin 7 */

    BSP_IO_PORT_01_PIN_00 = 0x0100,     /* IO port 1 pin 0 */
    BSP_IO_PORT_01_PIN_01 = 0x0101,     /* IO port 1 pin 1 */
    BSP_IO_PORT_01_PIN_02 = 0x0102,     /* IO port 1 pin 2 */
    BSP_IO_PORT_01_PIN_03 = 0x0103,     /* IO port 1 pin 3 */
    BSP_IO_PORT_01_PIN_04 = 0x0104,     /* IO port 1 pin 4 */
    BSP_IO_PORT_01_PIN_05 = 0x0105,     /* IO port 1 pin 5 */

    BSP_IO_PORT_02_PIN_00 = 0x0200,     /* IO port 2 pin 0 */
    BSP_IO_PORT_02_PIN_01 = 0x0201,     /* IO port 2 pin 1 */

    BSP_IO_PORT_03_PIN_00 = 0x0300,     /* IO port 3 pin 0 */
    BSP_IO_PORT_03_PIN_01 = 0x0301,     /* IO port 3 pin 1 */
    BSP_IO_PORT_03_PIN_02 = 0x0302,     /* IO port 3 pin 2 */
    BSP_IO_PORT_03_PIN_03 = 0x0303,     /* IO port 3 pin 3 */
    BSP_IO_PORT_03_PIN_04 = 0x0304,     /* IO port 3 pin 4 */
    BSP_IO_PORT_03_PIN_05 = 0x0305,     /* IO port 3 pin 5 */
    BSP_IO_PORT_03_PIN_06 = 0x0306,     /* IO port 3 pin 6 */
    BSP_IO_PORT_03_PIN_07 = 0x0307,     /* IO port 3 pin 7 */

    BSP_IO_PORT_04_PIN_00 = 0x0400,     /* IO port 4 pin 0 */
    BSP_IO_PORT_04_PIN_01 = 0x0401,     /* IO port 4 pin 1 */
    BSP_IO_PORT_04_PIN_02 = 0x0402,     /* IO port 4 pin 2 */
    BSP_IO_PORT_04_PIN_03 = 0x0403,     /* IO port 4 pin 3 */
    BSP_IO_PORT_04_PIN_04 = 0x0404,     /* IO port 4 pin 4 */
    BSP_IO_PORT_04_PIN_05 = 0x0405,     /* IO port 4 pin 5 */
    BSP_IO_PORT_04_PIN_06 = 0x0406,     /* IO port 4 pin 6 */
    BSP_IO_PORT_04_PIN_07 = 0x0407,     /* IO port 4 pin 7 */

    BSP_IO_PORT_05_PIN_00 = 0x0500,     /* IO port 5 pin 0 */
    BSP_IO_PORT_05_PIN_01 = 0x0501,     /* IO port 5 pin 1 */
    BSP_IO_PORT_05_PIN_02 = 0x0502,     /* IO port 5 pin 2 */
    BSP_IO_PORT_05_PIN_03 = 0x0503,     /* IO port 5 pin 3 */
    BSP_IO_PORT_05_PIN_04 = 0x0504,     /* IO port 5 pin 4 */
    BSP_IO_PORT_05_PIN_05 = 0x0505,     /* IO port 5 pin 5 */
    BSP_IO_PORT_05_PIN_06 = 0x0506,     /* IO port 5 pin 6 */
    BSP_IO_PORT_05_PIN_07 = 0x0507,     /* IO port 5 pin 7 */

    BSP_IO_PORT_06_PIN_00 = 0x0600,     /* IO port 6 pin 0 */
    BSP_IO_PORT_06_PIN_01 = 0x0601,     /* IO port 6 pin 1 */
    BSP_IO_PORT_06_PIN_02 = 0x0602,     /* IO port 6 pin 2 */
    BSP_IO_PORT_06_PIN_03 = 0x0603,     /* IO port 6 pin 3 */
    BSP_IO_PORT_06_PIN_04 = 0x0604,     /* IO port 6 pin 4 */
    BSP_IO_PORT_06_PIN_05 = 0x0605,     /* IO port 6 pin 5 */
    BSP_IO_PORT_06_PIN_06 = 0x0606,     /* IO port 6 pin 6 */
    BSP_IO_PORT_06_PIN_07 = 0x0607,     /* IO port 6 pin 7 */

    BSP_IO_PORT_07_PIN_00 = 0x0700,     /* IO port 7 pin 0 */
    BSP_IO_PORT_07_PIN_01 = 0x0701,     /* IO port 7 pin 1 */
    BSP_IO_PORT_07_PIN_02 = 0x0702,     /* IO port 7 pin 2 */
    BSP_IO_PORT_07_PIN_03 = 0x0703,     /* IO port 7 pin 3 */
    BSP_IO_PORT_07_PIN_04 = 0x0704,     /* IO port 7 pin 4 */
    BSP_IO_PORT_07_PIN_05 = 0x0705,     /* IO port 7 pin 5 */
    BSP_IO_PORT_07_PIN_06 = 0x0706,     /* IO port 7 pin 6 */
    BSP_IO_PORT_07_PIN_07 = 0x0707,     /* IO port 7 pin 7 */

    BSP_IO_PORT_08_PIN_00 = 0x0800,     /* IO port 8 pin 0 */
    BSP_IO_PORT_08_PIN_01 = 0x0801,     /* IO port 8 pin 1 */
    BSP_IO_PORT_08_PIN_02 = 0x0802,     /* IO port 8 pin 2 */
    BSP_IO_PORT_08_PIN_03 = 0x0803,     /* IO port 8 pin 3 */
    BSP_IO_PORT_08_PIN_04 = 0x0804,     /* IO port 8 pin 4 */
    BSP_IO_PORT_08_PIN_05 = 0x0805,     /* IO port 8 pin 5 */
    BSP_IO_PORT_08_PIN_06 = 0x0806,     /* IO port 8 pin 6 */
    BSP_IO_PORT_08_PIN_07 = 0x0807,     /* IO port 8 pin 7 */

    BSP_IO_PORT_09_PIN_00 = 0x0900,     /* IO port 9 pin 0 */
    BSP_IO_PORT_09_PIN_01 = 0x0901,     /* IO port 9 pin 1 */
    BSP_IO_PORT_09_PIN_02 = 0x0902,     /* IO port 9 pin 2 */
    BSP_IO_PORT_09_PIN_03 = 0x0903,     /* IO port 9 pin 3 */
    BSP_IO_PORT_09_PIN_04 = 0x0904,     /* IO port 9 pin 4 */
    BSP_IO_PORT_09_PIN_05 = 0x0905,     /* IO port 9 pin 5 */
    BSP_IO_PORT_09_PIN_06 = 0x0906,     /* IO port 9 pin 6 */
    BSP_IO_PORT_09_PIN_07 = 0x0907,     /* IO port 9 pin 7 */

    BSP_IO_PORT_10_PIN_00 = 0x0A00,     /* IO port 10 pin 0 */
    BSP_IO_PORT_10_PIN_01 = 0x0A01,     /* IO port 10 pin 1 */
    BSP_IO_PORT_10_PIN_02 = 0x0A02,     /* IO port 10 pin 2 */
    BSP_IO_PORT_10_PIN_03 = 0x0A03,     /* IO port 10 pin 3 */
    BSP_IO_PORT_10_PIN_04 = 0x0A04,     /* IO port 10 pin 4 */
    BSP_IO_PORT_10_PIN_05 = 0x0A05,     /* IO port 10 pin 5 */
    BSP_IO_PORT_10_PIN_06 = 0x0A06,     /* IO port 10 pin 6 */
    BSP_IO_PORT_10_PIN_07 = 0x0A07,     /* IO port 10 pin 7 */

    BSP_IO_PORT_11_PIN_00 = 0x0B00,     /* IO port 11 pin 0 */
    BSP_IO_PORT_11_PIN_01 = 0x0B01,     /* IO port 11 pin 1 */
    BSP_IO_PORT_11_PIN_02 = 0x0B02,     /* IO port 11 pin 2 */
    BSP_IO_PORT_11_PIN_03 = 0x0B03,     /* IO port 11 pin 3 */
    BSP_IO_PORT_11_PIN_04 = 0x0B04,     /* IO port 11 pin 4 */
    BSP_IO_PORT_11_PIN_05 = 0x0B05,     /* IO port 11 pin 5 */

    /* Special purpose port */
    BSP_IO_NMI = 0xFFFF0100,            /* NMI */

    BSP_IO_TMS_SWDIO = 0xFFFF0300,      /* TMS_SWDIO */
    BSP_IO_TDO       = 0xFFFF0302,      /* TDO */

    BSP_IO_WDTUDFCA = 0xFFFF0500,       /* WDTUDFCA */
    BSP_IO_WDTUDFCM = 0xFFFF0501,       /* WDTUDFCM */

    BSP_IO_SCIF_RXD = 0xFFFF0600,       /* SCIF_RXD */
    BSP_IO_SCIF_TXD = 0xFFFF0601,       /* SCIF_TXD */

    BSP_IO_XSPI0_CKP     = 0xFFFF0700,  /* XSPI0_CKP */
    BSP_IO_XSPI0_CKN     = 0xFFFF0701,  /* XSPI0_CKN */
    BSP_IO_XSPI0_CS0N    = 0xFFFF0702,  /* XSPI0_CS0N */
    BSP_IO_XSPI0_DS      = 0xFFFF0703,  /* XSPI0_DS */
    BSP_IO_XSPI0_RESET0N = 0xFFFF0704,  /* XSPI0_RESET0N */
    BSP_IO_XSPI0_RSTO0N  = 0xFFFF0705,  /* XSPI0_RSTO0N */
    BSP_IO_XSPI0_INT0N   = 0xFFFF0706,  /* XSPI0_INT0N */
    BSP_IO_XSPI0_ECS0N   = 0xFFFF0707,  /* XSPI0_ECS0N */

    BSP_IO_XSPI0_IO0 = 0xFFFF0800,      /* XSPI0_IO0 */
    BSP_IO_XSPI0_IO1 = 0xFFFF0801,      /* XSPI0_IO1 */
    BSP_IO_XSPI0_IO2 = 0xFFFF0802,      /* XSPI0_IO2 */
    BSP_IO_XSPI0_IO3 = 0xFFFF0803,      /* XSPI0_IO3 */
    BSP_IO_XSPI0_IO4 = 0xFFFF0804,      /* XSPI0_IO4 */
    BSP_IO_XSPI0_IO5 = 0xFFFF0805,      /* XSPI0_IO5 */
    BSP_IO_XSPI0_IO6 = 0xFFFF0806,      /* XSPI0_IO6 */
    BSP_IO_XSPI0_IO7 = 0xFFFF0807,      /* XSPI0_IO7 */

    BSP_IO_SD0CLK  = 0xFFFF0900,        /* SD0CLK */
    BSP_IO_SD0CMD  = 0xFFFF0901,        /* SD0CMD */
    BSP_IO_SD0RSTN = 0xFFFF0902,        /* SD0RSTN */

    BSP_IO_SD0DAT0 = 0xFFFF0A00,        /* SD0DAT0 */
    BSP_IO_SD0DAT1 = 0xFFFF0A01,        /* SD0DAT1 */
    BSP_IO_SD0DAT2 = 0xFFFF0A02,        /* SD0DAT2 */
    BSP_IO_SD0DAT3 = 0xFFFF0A03,        /* SD0DAT3 */
    BSP_IO_SD0DAT4 = 0xFFFF0A04,        /* SD0DAT4 */
    BSP_IO_SD0DAT5 = 0xFFFF0A05,        /* SD0DAT5 */
    BSP_IO_SD0DAT6 = 0xFFFF0A06,        /* SD0DAT6 */
    BSP_IO_SD0DAT7 = 0xFFFF0A07,        /* SD0DAT7 */

    BSP_IO_SD1CLK = 0xFFFF0B00,         /* SD1CLK */
    BSP_IO_SD1CMD = 0xFFFF0B01,         /* SD1CMD */

    BSP_IO_SD1DAT0 = 0xFFFF0C00,        /* SD1DAT0 */
    BSP_IO_SD1DAT1 = 0xFFFF0C01,        /* SD1DAT1 */
    BSP_IO_SD1DAT2 = 0xFFFF0C02,        /* SD1DAT2 */
    BSP_IO_SD1DAT3 = 0xFFFF0C03,        /* SD1DAT3 */

    BSP_IO_PCIE0_RSTOUTB = 0xFFFF0E00,  /* PCIE0_RSTOUTB */

    BSP_IO_ET0_MDIO = 0xFFFF0F00,       /* ET0_MDIO */
    BSP_IO_ET0_MDC  = 0xFFFF0F01,       /* ET0_MDC */

    BSP_IO_ET0_RXCTL_RXDV = 0xFFFF1000, /* ET0_RXCTL_RXDV */
    BSP_IO_ET0_TXCTL_TXEN = 0xFFFF1001, /* ET0_TXCTL_TXEN */
    BSP_IO_ET0_TXER       = 0xFFFF1002, /* ET0_TXER */
    BSP_IO_ET0_RXER       = 0xFFFF1003, /* ET0_RXER */
    BSP_IO_ET0_RXC_RXCLK  = 0xFFFF1004, /* ET0_RXC_RXCLK */
    BSP_IO_ET0_TXC_TXCLK  = 0xFFFF1005, /* ET0_TXC_TXCLK */
    BSP_IO_ET0_CRS        = 0xFFFF1006, /* ET0_CRS */
    BSP_IO_ET0_COL        = 0xFFFF1007, /* ET0_COL */

    BSP_IO_ET0_TXD0 = 0xFFFF1100,       /* ET0_TXD0 */
    BSP_IO_ET0_TXD1 = 0xFFFF1101,       /* ET0_TXD1 */
    BSP_IO_ET0_TXD2 = 0xFFFF1102,       /* ET0_TXD2 */
    BSP_IO_ET0_TXD3 = 0xFFFF1103,       /* ET0_TXD3 */
    BSP_IO_ET0_RXD0 = 0xFFFF1104,       /* ET0_RXD0 */
    BSP_IO_ET0_RXD1 = 0xFFFF1105,       /* ET0_RXD1 */
    BSP_IO_ET0_RXD2 = 0xFFFF1106,       /* ET0_RXD2 */
    BSP_IO_ET0_RXD3 = 0xFFFF1107,       /* ET0_RXD3 */

    BSP_IO_ET1_MDIO = 0xFFFF1200,       /* ET1_MDIO */
    BSP_IO_ET1_MDC  = 0xFFFF1201,       /* ET1_MDC */

    BSP_IO_ET1_RXCTL_RXDV = 0xFFFF1300, /* ET1_RXCTL_RXDV */
    BSP_IO_ET1_TXCTL_TXEN = 0xFFFF1301, /* ET1_TXCTL_TXEN */
    BSP_IO_ET1_TXER       = 0xFFFF1302, /* ET1_TXER */
    BSP_IO_ET1_RXER       = 0xFFFF1303, /* ET1_RXER */
    BSP_IO_ET1_RXC_RXCLK  = 0xFFFF1304, /* ET1_RXC_RXCLK */
    BSP_IO_ET1_TXC_TXCLK  = 0xFFFF1305, /* ET1_TXC_TXCLK */
    BSP_IO_ET1_CRS        = 0xFFFF1306, /* ET1_CRS */
    BSP_IO_ET1_COL        = 0xFFFF1307, /* ET1_COL */

    BSP_IO_ET1_TXD0 = 0xFFFF1400,       /* ET1_TXD0 */
    BSP_IO_ET1_TXD1 = 0xFFFF1401,       /* ET1_TXD1 */
    BSP_IO_ET1_TXD2 = 0xFFFF1402,       /* ET1_TXD2 */
    BSP_IO_ET1_TXD3 = 0xFFFF1403,       /* ET1_TXD3 */
    BSP_IO_ET1_RXD0 = 0xFFFF1404,       /* ET1_RXD0 */
    BSP_IO_ET1_RXD1 = 0xFFFF1405,       /* ET1_RXD1 */
    BSP_IO_ET1_RXD2 = 0xFFFF1406,       /* ET1_RXD2 */
    BSP_IO_ET1_RXD3 = 0xFFFF1407,       /* ET1_RXD3 */
} bsp_io_port_pin_t;

/*==============================================
 * CAN API Overrides
 *==============================================*/

/** CAN status info */
typedef struct st_can_info
{
    uint32_t status;                   ///< Useful information from the CAN status register.
    uint32_t rx_mb_status[3];          ///< RX Message Buffer New Data flags.
    uint32_t rx_fifo_status;           ///< RX FIFO Empty flags.
    uint8_t  error_count_transmit;     ///< Transmit error count.
    uint8_t  error_count_receive;      ///< Receive error count.
    uint32_t error_code;               ///< Error code, cleared after reading.
} can_info_t;

/*==============================================
 * CANFD Overrides
 *==============================================*/

/** CANFD Error Code */
typedef enum e_canfd_error
{
    CANFD_ERROR_CHANNEL_BUS              = 0x00000001, ///< Bus Error
    CANFD_ERROR_CHANNEL_WARNING          = 0x00000002, ///< Error Warning (TX/RX error count over 0x5F)
    CANFD_ERROR_CHANNEL_PASSIVE          = 0x00000004, ///< Error Passive (TX/RX error count over 0x7F)
    CANFD_ERROR_CHANNEL_BUS_OFF_ENTRY    = 0x00000008, ///< Bus-Off State Entry
    CANFD_ERROR_CHANNEL_BUS_OFF_RECOVERY = 0x00000010, ///< Recovery from Bus-Off State
    CANFD_ERROR_CHANNEL_OVERLOAD         = 0x00000020, ///< Overload
    CANFD_ERROR_CHANNEL_BUS_LOCK         = 0x00000040, ///< Bus Locked
    CANFD_ERROR_CHANNEL_ARBITRATION_LOSS = 0x00000080, ///< Arbitration Lost
    CANFD_ERROR_CHANNEL_STUFF            = 0x00000100, ///< Stuff Error
    CANFD_ERROR_CHANNEL_FORM             = 0x00000200, ///< Form Error
    CANFD_ERROR_CHANNEL_ACK              = 0x00000400, ///< ACK Error
    CANFD_ERROR_CHANNEL_CRC              = 0x00000800, ///< CRC Error
    CANFD_ERROR_CHANNEL_BIT_RECESSIVE    = 0x00001000, ///< Bit Error (recessive) Error
    CANFD_ERROR_CHANNEL_BIT_DOMINANT     = 0x00002000, ///< Bit Error (dominant) Error
    CANFD_ERROR_CHANNEL_ACK_DELIMITER    = 0x00004000, ///< ACK Delimiter Error
    CANFD_ERROR_GLOBAL_DLC               = 0x00010000, ///< DLC Error
    CANFD_ERROR_GLOBAL_MESSAGE_LOST      = 0x00020000, ///< Message Lost
    CANFD_ERROR_GLOBAL_PAYLOAD_OVERFLOW  = 0x00080000, ///< FD Payload Overflow
    CANFD_ERROR_GLOBAL_TXQ_OVERWRITE     = 0x00100000, ///< TX Queue Message Overwrite
    CANFD_ERROR_GLOBAL_TXQ_MESSAGE_LOST  = 0x00400000, ///< TX Queue Message Lost
    CANFD_ERROR_GLOBAL_CH0_ECC           = 0x04000000, ///< Channel 0 ECC Error
    CANFD_ERROR_GLOBAL_CH1_ECC           = 0x08000000, ///< Channel 1 ECC Error
    CANFD_ERROR_GLOBAL_CH2_ECC           = 0x10000000, ///< Channel 2 ECC Error
    CANFD_ERROR_GLOBAL_CH3_ECC           = 0x20000000, ///< Channel 3 ECC Error
    CANFD_ERROR_GLOBAL_CH4_ECC           = 0x40000000, ///< Channel 4 ECC Error
    CANFD_ERROR_GLOBAL_CH5_ECC           = 0x80000000, ///< Channel 5 ECC Error
} canfd_error_t;

/** CANFD Receive Buffer (MB + FIFO) */
typedef enum e_canfd_rx_buffer
{
    CANFD_RX_BUFFER_MB_0   = 0,
    CANFD_RX_BUFFER_MB_1   = 1,
    CANFD_RX_BUFFER_MB_2   = 2,
    CANFD_RX_BUFFER_MB_3   = 3,
    CANFD_RX_BUFFER_MB_4   = 4,
    CANFD_RX_BUFFER_MB_5   = 5,
    CANFD_RX_BUFFER_MB_6   = 6,
    CANFD_RX_BUFFER_MB_7   = 7,
    CANFD_RX_BUFFER_MB_8   = 8,
    CANFD_RX_BUFFER_MB_9   = 9,
    CANFD_RX_BUFFER_MB_10  = 10,
    CANFD_RX_BUFFER_MB_11  = 11,
    CANFD_RX_BUFFER_MB_12  = 12,
    CANFD_RX_BUFFER_MB_13  = 13,
    CANFD_RX_BUFFER_MB_14  = 14,
    CANFD_RX_BUFFER_MB_15  = 15,
    CANFD_RX_BUFFER_MB_16  = 16,
    CANFD_RX_BUFFER_MB_17  = 17,
    CANFD_RX_BUFFER_MB_18  = 18,
    CANFD_RX_BUFFER_MB_19  = 19,
    CANFD_RX_BUFFER_MB_20  = 20,
    CANFD_RX_BUFFER_MB_21  = 21,
    CANFD_RX_BUFFER_MB_22  = 22,
    CANFD_RX_BUFFER_MB_23  = 23,
    CANFD_RX_BUFFER_MB_24  = 24,
    CANFD_RX_BUFFER_MB_25  = 25,
    CANFD_RX_BUFFER_MB_26  = 26,
    CANFD_RX_BUFFER_MB_27  = 27,
    CANFD_RX_BUFFER_MB_28  = 28,
    CANFD_RX_BUFFER_MB_29  = 29,
    CANFD_RX_BUFFER_MB_30  = 30,
    CANFD_RX_BUFFER_MB_31  = 31,
    CANFD_RX_BUFFER_MB_32  = 32,
    CANFD_RX_BUFFER_MB_33  = 33,
    CANFD_RX_BUFFER_MB_34  = 34,
    CANFD_RX_BUFFER_MB_35  = 35,
    CANFD_RX_BUFFER_MB_36  = 36,
    CANFD_RX_BUFFER_MB_37  = 37,
    CANFD_RX_BUFFER_MB_38  = 38,
    CANFD_RX_BUFFER_MB_39  = 39,
    CANFD_RX_BUFFER_MB_40  = 40,
    CANFD_RX_BUFFER_MB_41  = 41,
    CANFD_RX_BUFFER_MB_42  = 42,
    CANFD_RX_BUFFER_MB_43  = 43,
    CANFD_RX_BUFFER_MB_44  = 44,
    CANFD_RX_BUFFER_MB_45  = 45,
    CANFD_RX_BUFFER_MB_46  = 46,
    CANFD_RX_BUFFER_MB_47  = 47,
    CANFD_RX_BUFFER_MB_48  = 48,
    CANFD_RX_BUFFER_MB_49  = 49,
    CANFD_RX_BUFFER_MB_50  = 50,
    CANFD_RX_BUFFER_MB_51  = 51,
    CANFD_RX_BUFFER_MB_52  = 52,
    CANFD_RX_BUFFER_MB_53  = 53,
    CANFD_RX_BUFFER_MB_54  = 54,
    CANFD_RX_BUFFER_MB_55  = 55,
    CANFD_RX_BUFFER_MB_56  = 56,
    CANFD_RX_BUFFER_MB_57  = 57,
    CANFD_RX_BUFFER_MB_58  = 58,
    CANFD_RX_BUFFER_MB_59  = 59,
    CANFD_RX_BUFFER_MB_60  = 60,
    CANFD_RX_BUFFER_MB_61  = 61,
    CANFD_RX_BUFFER_MB_62  = 62,
    CANFD_RX_BUFFER_MB_63  = 63,
    CANFD_RX_BUFFER_MB_64  = 64,
    CANFD_RX_BUFFER_MB_65  = 65,
    CANFD_RX_BUFFER_MB_66  = 66,
    CANFD_RX_BUFFER_MB_67  = 67,
    CANFD_RX_BUFFER_MB_68  = 68,
    CANFD_RX_BUFFER_MB_69  = 69,
    CANFD_RX_BUFFER_MB_70  = 70,
    CANFD_RX_BUFFER_MB_71  = 71,
    CANFD_RX_BUFFER_MB_72  = 72,
    CANFD_RX_BUFFER_MB_73  = 73,
    CANFD_RX_BUFFER_MB_74  = 74,
    CANFD_RX_BUFFER_MB_75  = 75,
    CANFD_RX_BUFFER_MB_76  = 76,
    CANFD_RX_BUFFER_MB_77  = 77,
    CANFD_RX_BUFFER_MB_78  = 78,
    CANFD_RX_BUFFER_MB_79  = 79,
    CANFD_RX_BUFFER_MB_80  = 80,
    CANFD_RX_BUFFER_MB_81  = 81,
    CANFD_RX_BUFFER_MB_82  = 82,
    CANFD_RX_BUFFER_MB_83  = 83,
    CANFD_RX_BUFFER_MB_84  = 84,
    CANFD_RX_BUFFER_MB_85  = 85,
    CANFD_RX_BUFFER_MB_86  = 86,
    CANFD_RX_BUFFER_MB_87  = 87,
    CANFD_RX_BUFFER_MB_88  = 88,
    CANFD_RX_BUFFER_MB_89  = 89,
    CANFD_RX_BUFFER_MB_90  = 90,
    CANFD_RX_BUFFER_MB_91  = 91,
    CANFD_RX_BUFFER_MB_92  = 92,
    CANFD_RX_BUFFER_MB_93  = 93,
    CANFD_RX_BUFFER_MB_94  = 94,
    CANFD_RX_BUFFER_MB_95  = 95,
    CANFD_RX_BUFFER_FIFO_0 = 96,
    CANFD_RX_BUFFER_FIFO_1 = 97,
#if !BSP_FEATURE_CANFD_LITE
    CANFD_RX_BUFFER_FIFO_2 = 98,
    CANFD_RX_BUFFER_FIFO_3 = 99,
    CANFD_RX_BUFFER_FIFO_4 = 100,
    CANFD_RX_BUFFER_FIFO_5 = 101,
    CANFD_RX_BUFFER_FIFO_6 = 102,
    CANFD_RX_BUFFER_FIFO_7 = 103,
#endif
    CANFD_RX_BUFFER_FIFO_COMMON_0 = 104,
#if !BSP_FEATURE_CANFD_LITE
    CANFD_RX_BUFFER_FIFO_COMMON_1 = 105,
    CANFD_RX_BUFFER_FIFO_COMMON_2 = 106,
#endif
} canfd_rx_buffer_t;

/** CANFD Receive FIFO (RX FIFO) */
typedef enum e_canfd_rx_fifo
{
    CANFD_RX_FIFO_0 = (1U),
    CANFD_RX_FIFO_1 = (1U << 1),
#if !BSP_FEATURE_CANFD_LITE
    CANFD_RX_FIFO_2 = (1U << 2),
    CANFD_RX_FIFO_3 = (1U << 3),
    CANFD_RX_FIFO_4 = (1U << 4),
    CANFD_RX_FIFO_5 = (1U << 5),
    CANFD_RX_FIFO_6 = (1U << 6),
    CANFD_RX_FIFO_7 = (1U << 7),
#endif
    CANFD_RX_FIFO_COMMON_0 = (1U << 8),
#if !BSP_FEATURE_CANFD_LITE
    CANFD_RX_FIFO_COMMON_1  = (1U << 9),
    CANFD_RX_FIFO_COMMON_2  = (1U << 10),
    CANFD_RX_FIFO_COMMON_3  = (1U << 11),
    CANFD_RX_FIFO_COMMON_4  = (1U << 12),
    CANFD_RX_FIFO_COMMON_5  = (1U << 13),
    CANFD_RX_FIFO_COMMON_6  = (1U << 14),
    CANFD_RX_FIFO_COMMON_7  = (1U << 15),
    CANFD_RX_FIFO_COMMON_8  = (1U << 16),
    CANFD_RX_FIFO_COMMON_9  = (1U << 17),
    CANFD_RX_FIFO_COMMON_10 = (1U << 18),
    CANFD_RX_FIFO_COMMON_11 = (1U << 19),
    CANFD_RX_FIFO_COMMON_12 = (1U << 20),
    CANFD_RX_FIFO_COMMON_13 = (1U << 21),
    CANFD_RX_FIFO_COMMON_14 = (1U << 22),
    CANFD_RX_FIFO_COMMON_15 = (1U << 23),
    CANFD_RX_FIFO_COMMON_16 = (1U << 24),
    CANFD_RX_FIFO_COMMON_17 = (1U << 25),
#endif
} canfd_rx_fifo_t;

/** CANFD Receive Message Buffer (RX MB) */
typedef enum e_canfd_rx_mb
{
    CANFD_RX_MB_NONE = 0,
    CANFD_RX_MB_0    = 0x80,
    CANFD_RX_MB_1    = 0x80 + 1,
    CANFD_RX_MB_2    = 0x80 + 2,
    CANFD_RX_MB_3    = 0x80 + 3,
    CANFD_RX_MB_4    = 0x80 + 4,
    CANFD_RX_MB_5    = 0x80 + 5,
    CANFD_RX_MB_6    = 0x80 + 6,
    CANFD_RX_MB_7    = 0x80 + 7,
    CANFD_RX_MB_8    = 0x80 + 8,
    CANFD_RX_MB_9    = 0x80 + 9,
    CANFD_RX_MB_10   = 0x80 + 10,
    CANFD_RX_MB_11   = 0x80 + 11,
    CANFD_RX_MB_12   = 0x80 + 12,
    CANFD_RX_MB_13   = 0x80 + 13,
    CANFD_RX_MB_14   = 0x80 + 14,
    CANFD_RX_MB_15   = 0x80 + 15,
    CANFD_RX_MB_16   = 0x80 + 16,
    CANFD_RX_MB_17   = 0x80 + 17,
    CANFD_RX_MB_18   = 0x80 + 18,
    CANFD_RX_MB_19   = 0x80 + 19,
    CANFD_RX_MB_20   = 0x80 + 20,
    CANFD_RX_MB_21   = 0x80 + 21,
    CANFD_RX_MB_22   = 0x80 + 22,
    CANFD_RX_MB_23   = 0x80 + 23,
    CANFD_RX_MB_24   = 0x80 + 24,
    CANFD_RX_MB_25   = 0x80 + 25,
    CANFD_RX_MB_26   = 0x80 + 26,
    CANFD_RX_MB_27   = 0x80 + 27,
    CANFD_RX_MB_28   = 0x80 + 28,
    CANFD_RX_MB_29   = 0x80 + 29,
    CANFD_RX_MB_30   = 0x80 + 30,
    CANFD_RX_MB_31   = 0x80 + 31,
    CANFD_RX_MB_32   = 0x80 + 32,
    CANFD_RX_MB_33   = 0x80 + 33,
    CANFD_RX_MB_34   = 0x80 + 34,
    CANFD_RX_MB_35   = 0x80 + 35,
    CANFD_RX_MB_36   = 0x80 + 36,
    CANFD_RX_MB_37   = 0x80 + 37,
    CANFD_RX_MB_38   = 0x80 + 38,
    CANFD_RX_MB_39   = 0x80 + 39,
    CANFD_RX_MB_40   = 0x80 + 40,
    CANFD_RX_MB_41   = 0x80 + 41,
    CANFD_RX_MB_42   = 0x80 + 42,
    CANFD_RX_MB_43   = 0x80 + 43,
    CANFD_RX_MB_44   = 0x80 + 44,
    CANFD_RX_MB_45   = 0x80 + 45,
    CANFD_RX_MB_46   = 0x80 + 46,
    CANFD_RX_MB_47   = 0x80 + 47,
    CANFD_RX_MB_48   = 0x80 + 48,
    CANFD_RX_MB_49   = 0x80 + 49,
    CANFD_RX_MB_50   = 0x80 + 50,
    CANFD_RX_MB_51   = 0x80 + 51,
    CANFD_RX_MB_52   = 0x80 + 52,
    CANFD_RX_MB_53   = 0x80 + 53,
    CANFD_RX_MB_54   = 0x80 + 54,
    CANFD_RX_MB_55   = 0x80 + 55,
    CANFD_RX_MB_56   = 0x80 + 56,
    CANFD_RX_MB_57   = 0x80 + 57,
    CANFD_RX_MB_58   = 0x80 + 58,
    CANFD_RX_MB_59   = 0x80 + 59,
    CANFD_RX_MB_60   = 0x80 + 60,
    CANFD_RX_MB_61   = 0x80 + 61,
    CANFD_RX_MB_62   = 0x80 + 62,
    CANFD_RX_MB_63   = 0x80 + 63,
    CANFD_RX_MB_64   = 0x80 + 64,
    CANFD_RX_MB_65   = 0x80 + 65,
    CANFD_RX_MB_66   = 0x80 + 66,
    CANFD_RX_MB_67   = 0x80 + 67,
    CANFD_RX_MB_68   = 0x80 + 68,
    CANFD_RX_MB_69   = 0x80 + 69,
    CANFD_RX_MB_70   = 0x80 + 70,
    CANFD_RX_MB_71   = 0x80 + 71,
    CANFD_RX_MB_72   = 0x80 + 72,
    CANFD_RX_MB_73   = 0x80 + 73,
    CANFD_RX_MB_74   = 0x80 + 74,
    CANFD_RX_MB_75   = 0x80 + 75,
    CANFD_RX_MB_76   = 0x80 + 76,
    CANFD_RX_MB_77   = 0x80 + 77,
    CANFD_RX_MB_78   = 0x80 + 78,
    CANFD_RX_MB_79   = 0x80 + 79,
    CANFD_RX_MB_80   = 0x80 + 80,
    CANFD_RX_MB_81   = 0x80 + 81,
    CANFD_RX_MB_82   = 0x80 + 82,
    CANFD_RX_MB_83   = 0x80 + 83,
    CANFD_RX_MB_84   = 0x80 + 84,
    CANFD_RX_MB_85   = 0x80 + 85,
    CANFD_RX_MB_86   = 0x80 + 86,
    CANFD_RX_MB_87   = 0x80 + 87,
    CANFD_RX_MB_88   = 0x80 + 88,
    CANFD_RX_MB_89   = 0x80 + 89,
    CANFD_RX_MB_90   = 0x80 + 90,
    CANFD_RX_MB_91   = 0x80 + 91,
    CANFD_RX_MB_92   = 0x80 + 92,
    CANFD_RX_MB_93   = 0x80 + 93,
    CANFD_RX_MB_94   = 0x80 + 94,
    CANFD_RX_MB_95   = 0x80 + 95
} canfd_rx_mb_t;

/** CANFD Transmit Buffer (MB + CFIFO) */
typedef enum e_canfd_tx_buffer
{
    CANFD_TX_BUFFER_0 = 0,
    CANFD_TX_BUFFER_1 = 1,
    CANFD_TX_BUFFER_2 = 2,
    CANFD_TX_BUFFER_3 = 3,
#if !BSP_FEATURE_CANFD_LITE
    CANFD_TX_BUFFER_4  = 4,
    CANFD_TX_BUFFER_5  = 5,
    CANFD_TX_BUFFER_6  = 6,
    CANFD_TX_BUFFER_7  = 7,
    CANFD_TX_BUFFER_8  = 8,
    CANFD_TX_BUFFER_9  = 9,
    CANFD_TX_BUFFER_10 = 10,
    CANFD_TX_BUFFER_11 = 11,
    CANFD_TX_BUFFER_12 = 12,
    CANFD_TX_BUFFER_13 = 13,
    CANFD_TX_BUFFER_14 = 14,
    CANFD_TX_BUFFER_15 = 15,
    CANFD_TX_BUFFER_32 = 32,
    CANFD_TX_BUFFER_33 = 33,
    CANFD_TX_BUFFER_34 = 34,
    CANFD_TX_BUFFER_35 = 35,
    CANFD_TX_BUFFER_36 = 36,
    CANFD_TX_BUFFER_37 = 37,
    CANFD_TX_BUFFER_38 = 38,
    CANFD_TX_BUFFER_39 = 39,
    CANFD_TX_BUFFER_40 = 40,
    CANFD_TX_BUFFER_41 = 41,
    CANFD_TX_BUFFER_42 = 42,
    CANFD_TX_BUFFER_43 = 43,
    CANFD_TX_BUFFER_44 = 44,
    CANFD_TX_BUFFER_45 = 45,
    CANFD_TX_BUFFER_46 = 46,
    CANFD_TX_BUFFER_47 = 47,
#endif
    CANFD_TX_BUFFER_FIFO_COMMON_0 = 48,
#if !BSP_FEATURE_CANFD_LITE
    CANFD_TX_BUFFER_FIFO_COMMON_1 = 49,
    CANFD_TX_BUFFER_FIFO_COMMON_2 = 50,
#endif
} canfd_tx_buffer_t;

/** CANFD Transmit Message Buffer (TX MB) */
typedef enum e_canfd_tx_mb
{
    CANFD_TX_MB_0 = 0,
    CANFD_TX_MB_1 = 1,
    CANFD_TX_MB_2 = 2,
    CANFD_TX_MB_3 = 3,
#if !BSP_FEATURE_CANFD_LITE
    CANFD_TX_MB_4  = 4,
    CANFD_TX_MB_5  = 5,
    CANFD_TX_MB_6  = 6,
    CANFD_TX_MB_7  = 7,
    CANFD_TX_MB_8  = 8,
    CANFD_TX_MB_9  = 9,
    CANFD_TX_MB_10 = 10,
    CANFD_TX_MB_11 = 11,
    CANFD_TX_MB_12 = 12,
    CANFD_TX_MB_13 = 13,
    CANFD_TX_MB_14 = 14,
    CANFD_TX_MB_15 = 15,
    CANFD_TX_MB_32 = 32,
    CANFD_TX_MB_33 = 33,
    CANFD_TX_MB_34 = 34,
    CANFD_TX_MB_35 = 35,
    CANFD_TX_MB_36 = 36,
    CANFD_TX_MB_37 = 37,
    CANFD_TX_MB_38 = 38,
    CANFD_TX_MB_39 = 39,
    CANFD_TX_MB_40 = 40,
    CANFD_TX_MB_41 = 41,
    CANFD_TX_MB_42 = 42,
    CANFD_TX_MB_43 = 43,
    CANFD_TX_MB_44 = 44,
    CANFD_TX_MB_45 = 45,
    CANFD_TX_MB_46 = 46,
    CANFD_TX_MB_47 = 47,
#endif
} canfd_tx_mb_t;

/** access control. */
typedef enum e_acc_control_ip
{
    ACCCNT_MPCPG,
    ACCCNT_MPSYS,
    ACCCNT_MPICU0,
    ACCCNT_MPICU1,
    ACCCNT_MXMDMC,
    ACCCNT_MPMSRM0,
    ACCCNT_MPMSRM1,
    ACCCNT_MPCST,
    ACCCNT_MPMHU,
    ACCCNT_MOMCMT0,
    ACCCNT_MOMCMT1,
    ACCCNT_MOMCMT2,
    ACCCNT_MOMCMT3,
    ACCCNT_MPMOST0,
    ACCCNT_MPMOST1,
    ACCCNT_MOMWDT,
    ACCCNT_MORTC,
    ACCCNT_MORTR,
    ACCCNT_SPI_REG,
    ACCCNT_MHGPO,
    ACCCNT_MPPDM0,
    ACCCNT_MPPDM1,
    ACCCNT_MOADC,
    ACCCNT_MPMTSU0,
    ACCCNT_MOSCF,
    ACCCNT_MOMI2C,
    ACCCNT_MPTSPI,
    ACCCNT_MPTM33,
    ACCCNT_MXADMC0,
    ACCCNT_MXADMC1,
    ACCCNT_MPASRM,
    ACCCNT_MPSYC,
    ACCCNT_MPAOST0,
    ACCCNT_MPAOST1,
    ACCCNT_MOAWDT,
    ACCCNT_MOAI2C0,
    ACCCNT_MOAI2C1,
    ACCCNT_MOAI2C2,
    ACCCNT_MOAI2C3,
    ACCCNT_MOAI2C4,
    ACCCNT_MOAI2C5,
    ACCCNT_MOAI2C6,
    ACCCNT_MOAI2C7,
    ACCCNT_MXSD0,
    ACCCNT_MXSD1,
    ACCCNT_MXSD2,
    ACCCNT_MPU3P0,
    ACCCNT_MXU3H0,
    ACCCNT_MHU2H0,
    ACCCNT_MPU2P0,
    ACCCNT_MXGBE0,
    ACCCNT_MXGBE1,
    ACCCNT_MPDDM0,
    ACCCNT_MPDDP0,
    ACCCNT_MPCRU0,
    ACCCNT_MPCRU1,
    ACCCNT_MPISP,
    ACCCNT_MXISP,
    ACCCNT_MPISU,
    ACCCNT_MPDSD,
    ACCCNT_MPDSL,
    ACCCNT_MPLCD,
    ACCCNT_MXGE3D,
    ACCCNT_MPVCC,
    ACCCNT_MPSSIU,
    ACCCNT_MPSSIUDMC,
    ACCCNT_MPADMC,
    ACCCNT_MOSPD0,
    ACCCNT_MOSPD1,
    ACCCNT_MOSPD2,
    ACCCNT_MPSCU,
    ACCCNT_MPSCUDMC,
    ACCCNT_MPADG,
    ACCCNT_MXDRA,
    ACCCNT_MXDRS,
    ACCCNT_MXGIC,
    ACCCNT_MPMTSU1,
    ACCCNT_MPTA55,
    ACCCNT_MPTR8,
    ACCCNT_MPTDD01,
    ACCCNT_MPTDD00,
    ACCCNT_MPTPCI,
    ACCCNT_MOCRC,
    ACCCNT_MOGPT0,
    ACCCNT_MOGPT1,
    ACCCNT_MOPOE0,
    ACCCNT_MOPOE1,
    ACCCNT_MOPOE2,
    ACCCNT_MOPOE3,
    ACCCNT_MOPOE4,
    ACCCNT_MOPOE5,
    ACCCNT_MOPOE6,
    ACCCNT_MOPOE7,
    ACCCNT_MORCMT0,
    ACCCNT_MORCMT1,
    ACCCNT_MORCMT2,
    ACCCNT_MORCMT3,
    ACCCNT_MORWDT0,
    ACCCNT_MORWDT1,
    ACCCNT_I3C,
    ACCCNT_CANFD,
    ACCCNT_ACPU,
    ACCCNT_MCPU,
    ACCCNT_LSI,
    ACCCNT_AOF,
    ACCCNT_GPREG,
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
    FSP_IP_CMTW   = 16,                ///< Compare Match Timer W
    FSP_IP_XSPI   = 17,                ///< Expanded Serial Peripheral Interface
    FSP_IP_CRC    = 18,                ///< Cyclic redundancy check (CRC) operation units
    FSP_IP_I3C    = 19,                ///< I3C Bus Interface
    FSP_IP_RTC    = 20,                ///< Realtime Clock
    FSP_IP_SYC    = 21                 ///< System counter
} fsp_ip_t;

/** master access control. */
typedef enum e_mst_acc_control_ip
{
    MST_ACCCNT_DMAC0,
    MST_ACCCNT_DMAC1,
    MST_ACCCNT_DMAC2,
    MST_ACCCNT_DMAC3,
    MST_ACCCNT_DMAC4,
    MST_ACCCNT_SD0,
    MST_ACCCNT_SD1,
    MST_ACCCNT_SD2,
    MST_ACCCNT_USB30_HOST,
    MST_ACCCNT_USB20_HOST,
    MST_ACCCNT_USB20_FUNC,
    MST_ACCCNT_GBETH0,
    MST_ACCCNT_GBETH1,
    MST_ACCCNT_PCIE0,
    MST_ACCCNT_CRU0_VIDEO,
    MST_ACCCNT_CRU0_STATIC,
    MST_ACCCNT_CRU1_VIDEO,
    MST_ACCCNT_CRU1_STATIC,
    MST_ACCCNT_FR_VIDEO_OUT,
    MST_ACCCNT_ISP_TEMPER,
    MST_ACCCNT_ISP_VIDEO_IN,
    MST_ACCCNT_ISU,
    MST_ACCCNT_DSI,
    MST_ACCCNT_LCDC0,
    MST_ACCCNT_GE3D,
    MST_ACCCNT_VCD,
    MST_ACCCNT_DRP_AI_MASTER,
    MST_ACCCNT_DRP_AI_FEATURE0,
    MST_ACCCNT_DRP_AI_FEATURE1,
    MST_ACCCNT_DRP_AI_WEIGHT0,
    MST_ACCCNT_DRP_AI_WEIGHT1
} fsp_mst_acc_control_ip_t;

/* Private enum used in R_FSP_SystemClockHzGet. */
typedef enum e_fsp_priv_clock
{
    FSP_PRIV_CLOCK_I0CLK = 0,          /* Cortex-A55 Clock */
    FSP_PRIV_CLOCK_I1CLK,              /* Cortex-A55 Clock */
    FSP_PRIV_CLOCK_I2CLK,              /* Cortex-A55 Clock */
    FSP_PRIV_CLOCK_I3CLK,              /* Cortex-A55 Clock */
    FSP_PRIV_CLOCK_I4CLK,              /* Miscellaneous logic clock for Cortex-A55 */
    FSP_PRIV_CLOCK_I5CLK,              /* DSU clock for Cortex-A55 */
    FSP_PRIV_CLOCK_I7CLK,              /* Cortex-M33 Clock */
    FSP_PRIV_CLOCK_P0CLK,              /* P0CLK */
    FSP_PRIV_CLOCK_P1CLK,              /* P1CLK */
    FSP_PRIV_CLOCK_P2CLK,              /* P2CLK */
    FSP_PRIV_CLOCK_P3CLK,              /* P3CLK */
    FSP_PRIV_CLOCK_P4CLK,              /* P4CLK */
    FSP_PRIV_CLOCK_P5CLK,              /* P5CLK */
    FSP_PRIV_CLOCK_P6CLK,              /* P6CLK */
    FSP_PRIV_CLOCK_P7CLK,              /* P7CLK */
    FSP_PRIV_CLOCK_P8CLK,              /* P8CLK */
    FSP_PRIV_CLOCK_P9CLK,              /* P9CLK */
    FSP_PRIV_CLOCK_P10CLK,             /* P10CLK */
    FSP_PRIV_CLOCK_P11CLK,             /* P11CLK */
    FSP_PRIV_CLOCK_P12CLK,             /* P12CLK */
    FSP_PRIV_CLOCK_ADCCLK,             /* ADC Clock */
    FSP_PRIV_CLOCK_ATCLK,              /* ATCLK */
    FSP_PRIV_CLOCK_CANCLK,             /* CANCLK */
    FSP_PRIV_CLOCK_ETHTX0CLK,          /* Transmission clock for GBETH0 */
    FSP_PRIV_CLOCK_ETHTX1CLK,          /* Transmission clock for GBETH1 */
    FSP_PRIV_CLOCK_ETHRX0CLK,          /* Reception clock for GBETH0 */
    FSP_PRIV_CLOCK_ETHRX1CLK,          /* Reception clock for GBETH1 */
    FSP_PRIV_CLOCK_GPUCLK,             /* GPU Clock */
    FSP_PRIV_CLOCK_HPCLK,              /* ptp reference Clock for GBETH */
    FSP_PRIV_CLOCK_ISPCLK,             /* ISP Clock */
    FSP_PRIV_CLOCK_ISUCLK,             /* ISU Clock */
    FSP_PRIV_CLOCK_LPCLK,              /* DSI LP transmit Clock */
    FSP_PRIV_CLOCK_M0CLK,              /* CRU0 Video Clock */
    FSP_PRIV_CLOCK_M1CLK,              /* CRU1 Video Clock */
    FSP_PRIV_CLOCK_M2CLK,              /* CRU2 Video Clock */
    FSP_PRIV_CLOCK_M3CLK,              /* CRU3 Video Clock */
    FSP_PRIV_CLOCK_M4CLK,              /* Video Clock for DSI and LCDC */
    FSP_PRIV_CLOCK_SDCLK,              /* High Speed Clock for SD */
    FSP_PRIV_CLOCK_SPI0CLK,            /* SPI0 Clock */
    FSP_PRIV_CLOCK_SPI1CLK,            /* SPI1 Clock */
    FSP_PRIV_CLOCK_ZTCLK,              /* ZTCLK */
    FSP_PRIV_CLOCK_OSCCLK,             /* OSC Clock */
    FSP_PRIV_CLOCK_OSC2CLK,            /* OSC2 Clock */
    FSP_PRIV_CLOCK_NUM,
} fsp_priv_clock_t;

/* Private enum used in R_BSP_ClockDividerSet. */
typedef enum e_fsp_priv_clock_divider
{
    FSP_PRIV_CLOCK_DIVIDER_PLLCM33_CST400 = 0,
    FSP_PRIV_CLOCK_DIVIDER_PLLCM33,
    FSP_PRIV_CLOCK_DIVIDER_PLLDTY_ACPU,
    FSP_PRIV_CLOCK_DIVIDER_PLLCA55_SCLK,
    FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_0,
    FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_1,
    FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_2,
    FSP_PRIV_CLOCK_DIVIDER_CLK1800_PLLCA55_CA55_3,
    FSP_PRIV_CLOCK_DIVIDER_CA55PERI,
    FSP_PRIV_CLOCK_DIVIDER_PLLDTY_DRP,
    FSP_PRIV_CLOCK_DIVIDER_PLLVDO_ISP,
    FSP_PRIV_CLOCK_DIVIDER_PLLVDO_ISU,
    FSP_PRIV_CLOCK_DIVIDER_PLLGPU,
    FSP_PRIV_CLOCK_DIVIDER_PLLDTY_RCPU,
    FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU0,
    FSP_PRIV_CLOCK_DIVIDER_PLLVDO_CRU1,
    FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE0,
    FSP_PRIV_CLOCK_DIVIDER_PLLETH_GBE1,
    FSP_PRIV_CLOCK_DIVIDER_PLLETH_LPCLK,
    FSP_PRIV_CLOCK_DIVIDER_PLLCM33_XSPI,
    FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_PCLK,
    FSP_PRIV_CLOCK_DIVIDER_PLLCM33_ADC_ADCLK,
    FSP_PRIV_CLOCK_DIVIDER_PLLDSI,
    FSP_PRIV_CLOCK_DIVIDER_NUM,
} fsp_priv_clock_divider_t;

/* Private enum used in R_BSP_ClockSelectorSet. */
typedef enum e_fsp_priv_clock_selector
{
    FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK1 = 0,
    FSP_PRIV_CLOCK_SELECTOR_SMUX2_CA55_SCLK0,
    FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_TXCLK,
    FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE0_RXCLK,
    FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_TXCLK,
    FSP_PRIV_CLOCK_SELECTOR_SMUX2_GBE1_RXCLK,
    FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK0,
    FSP_PRIV_CLOCK_SELECTOR_SMUX2_XSPI_CLK1,
    FSP_PRIV_CLOCK_SELECTOR_NUM,
} fsp_priv_clock_selector_t;

/*==============================================
 * ELC-Related Definitions Overrides
 *==============================================*/

/** Possible peripherals to be linked to event signals (not all available on all MPUs) */
typedef enum e_elc_peripheral
{
    ELC_PERIPHERAL_GPT0_ACT0   = (0),
    ELC_PERIPHERAL_GPT0_ACT1   = (1),
    ELC_PERIPHERAL_GPT0_ACT2   = (2),
    ELC_PERIPHERAL_GPT0_ACT3   = (3),
    ELC_PERIPHERAL_GPT0_ACT4   = (4),
    ELC_PERIPHERAL_GPT0_ACT5   = (5),
    ELC_PERIPHERAL_GPT0_ACT6   = (6),
    ELC_PERIPHERAL_GPT0_ACT7   = (7),
    ELC_PERIPHERAL_GPT1_ACT0   = (8),
    ELC_PERIPHERAL_GPT1_ACT1   = (9),
    ELC_PERIPHERAL_GPT1_ACT2   = (10),
    ELC_PERIPHERAL_GPT1_ACT3   = (11),
    ELC_PERIPHERAL_GPT1_ACT4   = (12),
    ELC_PERIPHERAL_GPT1_ACT5   = (13),
    ELC_PERIPHERAL_GPT1_ACT6   = (14),
    ELC_PERIPHERAL_GPT1_ACT7   = (15),
    ELC_PERIPHERAL_ADC0        = (16),
    ELC_PERIPHERAL_TSU0        = (17),
    ELC_PERIPHERAL_TSU1        = (18),
    ELC_PERIPHERAL_INPORTGR1   = (19),
    ELC_PERIPHERAL_INPORTGR0   = (20),
    ELC_PERIPHERAL_SINGLEPORT0 = (21),
    ELC_PERIPHERAL_SINGLEPORT1 = (22),
    ELC_PERIPHERAL_SINGLEPORT2 = (23),
    ELC_PERIPHERAL_SINGLEPORT3 = (24),
    ELC_PERIPHERAL_OUTPORTGR0  = (25),
    ELC_PERIPHERAL_OUTPORTGR1  = (26),
    ELC_PERIPHERAL_GBETH0_TGR0 = (27),
    ELC_PERIPHERAL_GBETH0_TGR1 = (28),
    ELC_PERIPHERAL_GBETH0_TGR2 = (29),
    ELC_PERIPHERAL_GBETH0_TGR3 = (30),
    ELC_PERIPHERAL_GBETH1_TGR0 = (31),
    ELC_PERIPHERAL_GBETH1_TGR1 = (32),
    ELC_PERIPHERAL_GBETH1_TGR2 = (33),
    ELC_PERIPHERAL_GBETH1_TGR3 = (34),
    ELC_PERIPHERAL_ICU_DMAC0   = (35),
    ELC_PERIPHERAL_ICU_DMAC1   = (36),
    ELC_PERIPHERAL_ICU_DMAC2   = (37),
    ELC_PERIPHERAL_ICU_DMAC3   = (38),
    ELC_PERIPHERAL_ICU_DMAC4   = (39),
    ELC_PERIPHERAL_ICU_DMAC5   = (40),
    ELC_PERIPHERAL_ICU_DMAC6   = (41),
    ELC_PERIPHERAL_ICU_DMAC7   = (42),
    ELC_PERIPHERAL_ADC1        = (43),
    ELC_PERIPHERAL_ADC2        = (44),
} elc_peripheral_t;

/** Software event number */
typedef enum e_elc_software_event
{
    ELC_SOFTWARE_EVENT_0,              /* Software event 0 */
    ELC_SOFTWARE_EVENT_1,              /* Software event 1 */
    ELC_SOFTWARE_EVENT_2,              /* Software event 2 */
    ELC_SOFTWARE_EVENT_3,              /* Software event 3 */
    ELC_SOFTWARE_EVENT_4,              /* Software event 4 */
    ELC_SOFTWARE_EVENT_5,              /* Software event 5 */
    ELC_SOFTWARE_EVENT_6,              /* Software event 6 */
} elc_software_event_t;

/*==============================================
 * GPT Overrides
 *==============================================*/

/** POEG channel to link to this channel. */
typedef enum e_gpt_poeg_link
{
    GPT_POEG_LINK_POEG0 = 0U,          ///< Link this GPT channel to POEG channel 0 (GTETRGA)
    GPT_POEG_LINK_POEG1 = 1U,          ///< Link this GPT channel to POEG channel 1 (GTETRGB)
    GPT_POEG_LINK_POEG2 = 2U,          ///< Link this GPT channel to POEG channel 2 (GTETRGC)
    GPT_POEG_LINK_POEG3 = 3U,          ///< Link this GPT channel to POEG channel 3 (GTETRGD)
    GPT_POEG_LINK_POEG4 = 0U,          ///< Link this GPT channel to POEG channel 4 (GTETRGE)
    GPT_POEG_LINK_POEG5 = 1U,          ///< Link this GPT channel to POEG channel 5 (GTETRGF)
    GPT_POEG_LINK_POEG6 = 2U,          ///< Link this GPT channel to POEG channel 6 (GTETRGG)
    GPT_POEG_LINK_POEG7 = 3U,          ///< Link this GPT channel to POEG channel 7 (GTETRGH)
} gpt_poeg_link_t;

/** Sources can be used to start the timer, stop the timer, count up, or count down. These enumerations represent
 * a bitmask. Multiple sources can be ORed together. */
typedef enum e_gpt_source
{
    /** No active event sources. */
    GPT_SOURCE_NONE = 0U,

    /** Action performed on GTETRGA rising edge. **/
    GPT_SOURCE_GTETRGA_RISING = (1U << 0),

    /** Action performed on GTETRGA falling edge. **/
    GPT_SOURCE_GTETRGA_FALLING = (1U << 1),

    /** Action performed on GTETRGB rising edge. **/
    GPT_SOURCE_GTETRGB_RISING = (1U << 2),

    /** Action performed on GTETRGB falling edge. **/
    GPT_SOURCE_GTETRGB_FALLING = (1U << 3),

    /** Action performed on GTETRGC rising edge. **/
    GPT_SOURCE_GTETRGC_RISING = (1U << 4),

    /** Action performed on GTETRGC falling edge. **/
    GPT_SOURCE_GTETRGC_FALLING = (1U << 5),

    /** Action performed on GTETRGB rising edge. **/
    GPT_SOURCE_GTETRGD_RISING = (1U << 6),

    /** Action performed on GTETRGB falling edge. **/
    GPT_SOURCE_GTETRGD_FALLING = (1U << 7),

    /** Action performed when GTIOCA input rises while GTIOCB is low. **/
    GPT_SOURCE_GTIOCA_RISING_WHILE_GTIOCB_LOW = (1U << 8),

    /** Action performed when GTIOCA input rises while GTIOCB is high. **/
    GPT_SOURCE_GTIOCA_RISING_WHILE_GTIOCB_HIGH = (1U << 9),

    /** Action performed when GTIOCA input falls while GTIOCB is low. **/
    GPT_SOURCE_GTIOCA_FALLING_WHILE_GTIOCB_LOW = (1U << 10),

    /** Action performed when GTIOCA input falls while GTIOCB is high. **/
    GPT_SOURCE_GTIOCA_FALLING_WHILE_GTIOCB_HIGH = (1U << 11),

    /** Action performed when GTIOCB input rises while GTIOCA is low. **/
    GPT_SOURCE_GTIOCB_RISING_WHILE_GTIOCA_LOW = (1U << 12),

    /** Action performed when GTIOCB input rises while GTIOCA is high. **/
    GPT_SOURCE_GTIOCB_RISING_WHILE_GTIOCA_HIGH = (1U << 13),

    /** Action performed when GTIOCB input falls while GTIOCA is low. **/
    GPT_SOURCE_GTIOCB_FALLING_WHILE_GTIOCA_LOW = (1U << 14),

    /** Action performed when GTIOCB input falls while GTIOCA is high. **/
    GPT_SOURCE_GTIOCB_FALLING_WHILE_GTIOCA_HIGH = (1U << 15),

    /** Action performed on ELC GPT0 (A) event. **/
    GPT_SOURCE_GPT0_ACT0 = (1U << 16),

    /** Action performed on ELC GPT0 (B) event. **/
    GPT_SOURCE_GPT0_ACT1 = (1U << 17),

    /** Action performed on ELC GPT0 (C) event. **/
    GPT_SOURCE_GPT0_ACT2 = (1U << 18),

    /** Action performed on ELC GPT0 (D) event. **/
    GPT_SOURCE_GPT0_ACT3 = (1U << 19),

    /** Action performed on ELC GPT0 (E) event. **/
    GPT_SOURCE_GPT0_ACT4 = (1U << 20),

    /** Action performed on ELC GPT0 (F) event. **/
    GPT_SOURCE_GPT0_ACT5 = (1U << 21),

    /** Action performed on ELC GPT0 (G) event. **/
    GPT_SOURCE_GPT0_ACT6 = (1U << 22),

    /** Action performed on ELC GPT0 (H) event. **/
    GPT_SOURCE_GPT0_ACT7 = (1U << 23),

    /** Action performed on ELC GPT1 (A) event. **/
    GPT_SOURCE_GPT1_ACT0 = (1U << 16),

    /** Action performed on ELC GPT1 (B) event. **/
    GPT_SOURCE_GPT1_ACT1 = (1U << 17),

    /** Action performed on ELC GPT1 (C) event. **/
    GPT_SOURCE_GPT1_ACT2 = (1U << 18),

    /** Action performed on ELC GPT1 (D) event. **/
    GPT_SOURCE_GPT1_ACT3 = (1U << 19),

    /** Action performed on ELC GPT1 (E) event. **/
    GPT_SOURCE_GPT1_ACT4 = (1U << 20),

    /** Action performed on ELC GPT1 (F) event. **/
    GPT_SOURCE_GPT1_ACT5 = (1U << 21),

    /** Action performed on ELC GPT1 (G) event. **/
    GPT_SOURCE_GPT1_ACT6 = (1U << 22),

    /** Action performed on ELC GPT1 (H) event. **/
    GPT_SOURCE_GPT1_ACT7 = (1U << 23),
} gpt_source_t;

/*==============================================
 * IOPORT Overrides
 *==============================================*/

/** Options to configure pin functions  */
typedef enum e_ioport_cfg_options
{
    /* For PM Register */
    IOPORT_CFG_PORT_DIRECTION_HIZ          = 0x00000000,        ///< Sets the pin direction to Hi-Z (default)
    IOPORT_CFG_PORT_DIRECTION_INPUT        = 0x00000004,        ///< Sets the pin direction to input
    IOPORT_CFG_PORT_DIRECTION_OUTPUT       = 0x00000008,        ///< Sets the pin direction to output (input disable)
    IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT = 0x0000000C,        ///< Sets the pin direction to output (input enable)

    /* For P Register */
    IOPORT_CFG_PORT_OUTPUT_LOW  = 0x00000000,                   ///< Sets the pin level to low
    IOPORT_CFG_PORT_OUTPUT_HIGH = 0x00000001,                   ///< Sets the pin level to high

    /* For PUPD Register */
    IOPORT_CFG_PULLUP_PULLDOWN_DISABLE = 0x00000000,            ///< Disable the pin's internal pull-up and pull-down
    IOPORT_CFG_PULLUP_ENABLE           = 0x00000030,            ///< Enables the pin's internal pull-up
    IOPORT_CFG_PULLDOWN_ENABLE         = 0x00000020,            ///< Enables the pin's internal pull-down

    /* For NOD Register */
    IOPORT_CFG_NOD_DISABLE = 0x00000000,                        ///< Disable the pin's N-ch open-drain
    IOPORT_CFG_NOD_ENABLE  = 0x00000040,                        ///< Enables the pin's N-ch open-drain

    /* For SMT Register */
    IOPORT_CFG_SCHMITT_DISABLE = 0x00000000,                    ///< Disable the pin's Schmitt-trigger input
    IOPORT_CFG_SCHMITT_ENABLE  = 0x80000000,                    ///< Enables the pin's Schmitt-trigger input

    /* For IOLH Register */
    IOPORT_CFG_DRIVE_B00 = 0x00000000,                          ///< Sets the IOLH register value to b'00
    IOPORT_CFG_DRIVE_B01 = 0x00000400,                          ///< Sets the IOLH register value to b'01
    IOPORT_CFG_DRIVE_B10 = 0x00000800,                          ///< Sets the IOLH register value to b'10
    IOPORT_CFG_DRIVE_B11 = 0x00000C00,                          ///< Sets the IOLH register value to b'11

    /* For ISEL Register */
    IOPORT_CFG_TINT_DISABLE = 0x00000000,                       ///< Disable IRQ functionality for a pin
    IOPORT_CFG_TINT_ENABLE  = 0x00004000,                       ///< Sets pin as an IRQ pin

    /* For SR Register */
    IOPORT_CFG_SLEW_RATE_SLOW = 0x00020000,                     ///< Sets the pin slew-rate to slow
    IOPORT_CFG_SLEW_RATE_FAST = 0x00000000,                     ///< Sets the pin slew-rate to fast

    /* For IEN Register */
    IOPORT_CFG_SPECIAL_PURPOSE_PORT_INPUT_DISABLE = 0x00000000, ///< Disable input the pin of special purpose port
    IOPORT_CFG_SPECIAL_PURPOSE_PORT_INPUT_ENABLE  = 0x00040000, ///< Sets the pin of special purpose port to input

    /* For FILONOFF Register */
    IOPORT_CFG_NOISE_FILTER_OFF = 0x00000000,                   ///< Noise filter disable
    IOPORT_CFG_NOISE_FILTER_ON  = 0x00080000,                   ///< Noise filter enable

    /* For FILNUM Register */
    IOPORT_CFG_NOISE_FILTER_NUM_4STAGE  = 0x00000000,           ///< Sets the pin noise filter to 4-stage filter
    IOPORT_CFG_NOISE_FILTER_NUM_8STAGE  = 0x00100000,           ///< Sets the pin noise filter to 8-stage filter
    IOPORT_CFG_NOISE_FILTER_NUM_16STAGE = 0x00300000,           ///< Sets the pin noise filter to 16-stage filter

    /* For FILCLKSEL Register */
    IOPORT_CFG_NOISE_FILTER_DIVIDED_B00 = 0x00000000,           ///< Sets the FILCLKSEL register value to b'00
    IOPORT_CFG_NOISE_FILTER_DIVIDED_B01 = 0x00400000,           ///< Sets the FILCLKSEL register value to b'01
    IOPORT_CFG_NOISE_FILTER_DIVIDED_B10 = 0x00800000,           ///< Sets the FILCLKSEL register value to b'10
    IOPORT_CFG_NOISE_FILTER_DIVIDED_B11 = 0x00C00000,           ///< Sets the FILCLKSEL register value to b'11

    /* For PMC Register */
    IOPORT_CFG_PERIPHERAL_PIN = 0x00010000                      ///< Enables pin to operate as a peripheral pin
} ioport_cfg_options_t;

/*==============================================
 * Transfer API Overrides
 *==============================================*/

/** Events that can trigger a callback function. */
typedef enum e_transfer_event
{
    TRANSFER_EVENT_TRANSFER_END   = 0, ///< Transfer has completed.
    TRANSFER_EVENT_TRANSFER_ERROR = 1, ///< Transfer error has occurred.
} transfer_event_t;

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

/** Callback function parameter data. */
typedef struct st_transfer_callback_args_t
{
    transfer_event_t event;            ///< Event code
    void const     * p_context;        ///< Placeholder for user data. Set in transfer_api_t::open function in ::transfer_cfg_t.
} transfer_callback_args_t;

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
