/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_SECURITY_H
#define BSP_SECURITY_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/******************************************************************************************************************//**
 * set access control level
 *
 * @param      ip       enum value to set access control level.
 * @param      level    access control level(0, 1, 2, 3).
 *            The processes that can be performed at each access control level are as follows.
 *            RD: Read is allowed, WR: Write is allowed, None: Both RD and WR are not allowed.
 *            ********************************************************
 *            *level *  non secure           * secure                *
 *            *      *  user  * privileged   * user    * privileged  *
 *            ********************************************************
 *            *    0 *  RD+WR * RD+WR        * RD+WR   * RD+WR       *
 *            *    1 *  None  * RD+WR        * RD+WR   * RD+WR       *
 *            *    2 *  None  * None         * RD+WR   * RD+WR       *
 *            *    3 *  None  * None         * None    * RD+WR       *
 *********************************************************************************************************************/
#define R_BSP_ACCESS_CONTROL_SET(ip, level)    {BSP_ACCESS_CONTROL_REG_ ## ip = (BSP_ACCESS_CONTROL_REG_ ## ip       \
                                                                                 & ~((uint32_t) 0x3 <<               \
                                                                                     BSP_ACCESS_CONTROL_POS_ ## ip)) \
                                                                                | ((level) <<                        \
                                                                                   BSP_ACCESS_CONTROL_POS_ ## ip);   \
}

#ifndef BSP_OVERRIDE_BSP_ACCESS_CONTROL

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
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT1         (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT1         (R_SYSC_SYS_SLVACCCTL2_WDT1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT2         (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT2         (R_SYSC_SYS_SLVACCCTL2_WDT2_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_MTU3A        (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_MTU3A        (R_SYSC_SYS_SLVACCCTL2_MTU3A_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_POE3         (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_POE3         (R_SYSC_SYS_SLVACCCTL2_POE3_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_GPT          (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_GPT          (R_SYSC_SYS_SLVACCCTL2_GPT_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_POEG         (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_POEG         (R_SYSC_SYS_SLVACCCTL2_POEG_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_DDR          (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_DDR          (R_SYSC_SYS_SLVACCCTL2_DDR_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_GPU          (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_GPU          (R_SYSC_SYS_SLVACCCTL3_GPU_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_H264         (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_H264         (R_SYSC_SYS_SLVACCCTL3_H264_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_CRU          (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_CRU          (R_SYSC_SYS_SLVACCCTL3_CRU_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_ISU          (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_ISU          (R_SYSC_SYS_SLVACCCTL3_ISU_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_DSIPHY       (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_DSIPHY       (R_SYSC_SYS_SLVACCCTL3_DSIPHY_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_DSILINK      (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_DSILINK      (R_SYSC_SYS_SLVACCCTL3_DSILINK_SL_Pos)
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

#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#ifndef BSP_OVERRIDE_BSP_ACC_CONTROL_IP_T

/** access control. */
typedef enum e_acc_control_ip
{
    ACCCNT_SRAM0 = 0,                  ///<
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
    ACCCNT_WDT1,
    ACCCNT_WDT2,
    ACCCNT_MTU3A,
    ACCCNT_POE3,
    ACCCNT_GPT,
    ACCCNT_POEG,
    ACCCNT_DDR,
    ACCCNT_GPU,
    ACCCNT_H264,
    ACCCNT_CRU,
    ACCCNT_ISU,
    ACCCNT_DSIPHY,
    ACCCNT_DSILINK,
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
} fsp_acc_control_ip_t;

#endif

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void R_BSP_NonSecureEnter(void);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_SECURITY_H */
