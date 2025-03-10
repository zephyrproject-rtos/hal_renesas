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

#define BSP_ACCESS_CONTROL_REG_ACCCNT_SRAM0        (R_ACCCTL_S->SYS_SLVACCCTL0)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SRAM0        (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SRAM1        (R_ACCCTL_S->SYS_SLVACCCTL0)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SRAM1        (2)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC0         (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC0         (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC1         (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC1         (2)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC2         (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC2         (4)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC3         (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC3         (6)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CST          (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CST          (10)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CPG          (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CPG          (12)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SYSC         (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SYSC         (14)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SYC          (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SYC          (16)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GIC          (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GIC          (18)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_IA55_IM33    (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_IA55_IM33    (20)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPIO         (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPIO         (22)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MHU          (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MHU          (24)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DMAC0        (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DMAC0        (26)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DMAC1        (R_ACCCTL_S->SYS_SLVACCCTL1)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DMAC1        (28)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM0        (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM0        (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM1        (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM1        (2)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM2        (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM2        (4)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT0         (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT0         (6)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT1         (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT1         (8)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT2         (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT2         (10)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_MTU3A        (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_MTU3A        (14)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_POE3         (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_POE3         (16)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPT          (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPT          (18)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_POEG         (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_POEG         (20)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DDR          (R_ACCCTL_S->SYS_SLVACCCTL2)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DDR          (22)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPU          (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPU          (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_H264         (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_H264         (2)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CRU          (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CRU          (4)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ISU          (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ISU          (6)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DSIPHY       (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DSIPHY       (8)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_DSILINK      (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_DSILINK      (10)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_LCDC         (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_LCDC         (12)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_USBT         (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_USBT         (16)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_USB20        (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_USB20        (18)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_USB21        (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_USB21        (20)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI0        (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI0        (22)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI1        (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI1        (24)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ETH0         (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ETH0         (26)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ETH1         (R_ACCCTL_S->SYS_SLVACCCTL3)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ETH1         (28)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C0         (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C0         (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C1         (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C1         (2)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C2         (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C2         (4)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C3         (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C3         (6)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CANFD        (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CANFD        (8)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI         (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI         (10)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF0        (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF0        (16)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF1        (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF1        (18)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF2        (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF2        (20)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF3        (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF3        (22)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF4        (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF4        (24)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCI0         (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCI0         (26)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SCI1         (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SCI1         (28)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_IRDA         (R_ACCCTL_S->SYS_SLVACCCTL4)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_IRDA         (30)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF         (R_ACCCTL_S->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF         (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_SRC          (R_ACCCTL_S->SYS_SLVACCCTL5)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_SRC          (4)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_ADC          (R_ACCCTL_S->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_ADC          (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_TSU          (R_ACCCTL_S->SYS_SLVACCCTL6)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_TSU          (2)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_OTP          (R_ACCCTL_S->SYS_SLVACCCTL7)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_OTP          (2)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CM33         (R_ACCCTL_S->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CM33         (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_CA55         (R_ACCCTL_S->SYS_SLVACCCTL8)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_CA55         (2)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_LSI          (R_ACCCTL_S->SYS_SLVACCCTL10)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_LSI          (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_AOF          (R_ACCCTL_S->SYS_SLVACCCTL12)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_AOF          (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_LP           (R_ACCCTL_S->SYS_SLVACCCTL13)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_LP           (0)
#define BSP_ACCESS_CONTROL_REG_ACCCNT_GPREG        (R_ACCCTL_S->SYS_SLVACCCTL14)
#define BSP_ACCESS_CONTROL_POS_ACCCNT_GPREG        (0)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

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

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void R_BSP_NonSecureEnter(void);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
