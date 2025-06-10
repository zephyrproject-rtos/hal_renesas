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

#if BSP_FEATURE_BSP_ACCESS_CONTROL_SET_SUPPORT

 #define R_BSP_MASTER_ACCESS_CONTROL_SET(ip, level, direction)           {FSP_CRITICAL_SECTION_DEFINE;                 \
                                                                          FSP_CRITICAL_SECTION_ENTER;                  \
                                                                          BSP_ACCESS_CONTROL_ ## direction(ip, level); \
                                                                          FSP_CRITICAL_SECTION_EXIT;}

 #define BSP_ACCESS_CONTROL_BSP_MST_ACCCNT_WRITE_DIRECTION(ip, level)    BSP_ACCESS_CONTROL_WRITE_ ## ip(level)

 #define BSP_ACCESS_CONTROL_BSP_MST_ACCCNT_READ_DIRECTION(ip, level)     BSP_ACCESS_CONTROL_READ_ ## ip(level)

 #define R_BSP_SLAVE_ACCESS_CONTROL_SET(ip, level, direction)            {FSP_CRITICAL_SECTION_DEFINE;                     \
                                                                          FSP_CRITICAL_SECTION_ENTER;                      \
                                                                          BSP_SLV_ACCCNT_REG_ ## ip =                      \
                                                                              (BSP_SLV_ACCCNT_REG_ ## ip                   \
                                                                               & ~(((uint32_t) (                           \
                                                                                        R_TZC_REGION_ID_ACCESS_0_NRE_Msk)) \
                                                                                   <<                                      \
                                                                                   (direction))                            \
                                                                               | (level <<                                 \
                                                                                  (direction)));                           \
                                                                          FSP_CRITICAL_SECTION_EXIT;}

 #define BSP_MST_ACCCNT_LEVEL_NONPRIVILEGED_NONSECURE    (2U)
 #define BSP_MST_ACCCNT_LEVEL_PRIVILEGED_NONSECURE       (3U)
 #define BSP_MST_ACCCNT_LEVEL_NONPRIVILEGED_SECURE       (0U)
 #define BSP_MST_ACCCNT_LEVEL_PRIVILEGED_SECURE          (1U)

 #define BSP_MST_ACCCNT_WRITE_DIRECTION                  (0U)
 #define BSP_MST_ACCCNT_READ_DIRECTION                   (4U)

 #define BSP_SLV_ACCCNT_LEVEL_NONPRIVILEGED_NONSECURE    (0xF)
 #define BSP_SLV_ACCCNT_LEVEL_PRIVILEGED_NONSECURE       (0xB)
 #define BSP_SLV_ACCCNT_LEVEL_NONPRIVILEGED_SECURE       (0x3)
 #define BSP_SLV_ACCCNT_LEVEL_PRIVILEGED_SECURE          (0x2)

 #define BSP_SLV_ACCCNT_WRITE_DIRECTION                  (16U)
 #define BSP_SLV_ACCCNT_READ_DIRECTION                   (0U)

 #define BSP_SLV_ACCCNT_REG_BSP_SLV_ACCCNT_SRAMM         (R_TZC_SRAMM->REGION_ID_ACCESS_0)
 #define BSP_SLV_ACCCNT_REG_BSP_SLV_ACCCNT_SRAMA         (R_TZC_SRAMA->REGION_ID_ACCESS_0)
 #define BSP_SLV_ACCCNT_REG_BSP_SLV_ACCCNT_DDR01         (R_TZC_DDR01->REGION_ID_ACCESS_0)
 #define BSP_SLV_ACCCNT_REG_BSP_SLV_ACCCNT_DDR11         (R_TZC_DDR11->REGION_ID_ACCESS_0)

 #ifndef BSP_OVERRIDE_BSP_MST_ACCESS_CONTROL

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DMAC0(level)         {R_SYSC->SYS_MSTACCCTL0 =                        \
                                                                        (R_SYSC->SYS_MSTACCCTL0                     \
                                                                         & ~(uint32_t) (                            \
                                                                             R_SYSC_SYS_MSTACCCTL0_DMAC0_AWPU_Msk   \
                                                                             |                                      \
                                                                             R_SYSC_SYS_MSTACCCTL0_DMAC0_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL0_DMAC0_AWSEL_Msk     \
                                                                        | (level <<                                 \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC0_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DMAC0(level)          {R_SYSC->SYS_MSTACCCTL0 =                        \
                                                                        (R_SYSC->SYS_MSTACCCTL0                     \
                                                                         & ~(uint32_t) (                            \
                                                                             R_SYSC_SYS_MSTACCCTL0_DMAC0_ARPU_Msk   \
                                                                             |                                      \
                                                                             R_SYSC_SYS_MSTACCCTL0_DMAC0_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL0_DMAC0_ARSEL_Msk     \
                                                                        | (level <<                                 \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC0_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DMAC1(level)         {R_SYSC->SYS_MSTACCCTL0 =                        \
                                                                        (R_SYSC->SYS_MSTACCCTL0                     \
                                                                         & ~(uint32_t) (                            \
                                                                             R_SYSC_SYS_MSTACCCTL0_DMAC1_AWPU_Msk   \
                                                                             |                                      \
                                                                             R_SYSC_SYS_MSTACCCTL0_DMAC1_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL0_DMAC1_AWSEL_Msk     \
                                                                        | (level <<                                 \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC1_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DMAC1(level)          {R_SYSC->SYS_MSTACCCTL0 =                        \
                                                                        (R_SYSC->SYS_MSTACCCTL0                     \
                                                                         & ~(uint32_t) (                            \
                                                                             R_SYSC_SYS_MSTACCCTL0_DMAC1_ARPU_Msk   \
                                                                             |                                      \
                                                                             R_SYSC_SYS_MSTACCCTL0_DMAC1_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL0_DMAC1_ARSEL_Msk     \
                                                                        | (level <<                                 \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC1_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_3DGE(level)          {R_SYSC->SYS_MSTACCCTL0 =                             \
                                                                        (R_SYSC->SYS_MSTACCCTL0                          \
                                                                         & ~(uint32_t) (                                 \
                                                                             R_SYSC_SYS_MSTACCCTL0_GPU_AWPU_Msk          \
                                                                             |                                           \
                                                                             R_SYSC_SYS_MSTACCCTL0_GPU_AWNS_Msk))        \
                                                                        | R_SYSC_SYS_MSTACCCTL0_GPU_AWSEL_Msk            \
                                                                        | (level << R_SYSC_SYS_MSTACCCTL0_GPU_AWPU_Pos); \
}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_3DGE(level)           {R_SYSC->SYS_MSTACCCTL0 =                             \
                                                                        (R_SYSC->SYS_MSTACCCTL0                          \
                                                                         & ~(uint32_t) (                                 \
                                                                             R_SYSC_SYS_MSTACCCTL0_GPU_ARPU_Msk          \
                                                                             |                                           \
                                                                             R_SYSC_SYS_MSTACCCTL0_GPU_ARNS_Msk))        \
                                                                        | R_SYSC_SYS_MSTACCCTL0_GPU_ARSEL_Msk            \
                                                                        | (level << R_SYSC_SYS_MSTACCCTL0_GPU_ARPU_Pos); \
}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_SDHI0(level)         {R_SYSC->SYS_MSTACCCTL1 =                        \
                                                                        (R_SYSC->SYS_MSTACCCTL1                     \
                                                                         & ~(uint32_t) (                            \
                                                                             R_SYSC_SYS_MSTACCCTL1_SDHI0_AWPU_Msk   \
                                                                             |                                      \
                                                                             R_SYSC_SYS_MSTACCCTL1_SDHI0_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL1_SDHI0_AWSEL_Msk     \
                                                                        | (level <<                                 \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI0_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_SDHI0(level)          {R_SYSC->SYS_MSTACCCTL1 =                        \
                                                                        (R_SYSC->SYS_MSTACCCTL1                     \
                                                                         & ~(uint32_t) (                            \
                                                                             R_SYSC_SYS_MSTACCCTL1_SDHI0_ARPU_Msk   \
                                                                             |                                      \
                                                                             R_SYSC_SYS_MSTACCCTL1_SDHI0_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL1_SDHI0_ARSEL_Msk     \
                                                                        | (level <<                                 \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI0_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_SDHI1(level)         {R_SYSC->SYS_MSTACCCTL1 =                        \
                                                                        (R_SYSC->SYS_MSTACCCTL1                     \
                                                                         & ~(uint32_t) (                            \
                                                                             R_SYSC_SYS_MSTACCCTL1_SDHI1_AWPU_Msk   \
                                                                             |                                      \
                                                                             R_SYSC_SYS_MSTACCCTL1_SDHI1_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL1_SDHI1_AWSEL_Msk     \
                                                                        | (level <<                                 \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI1_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_SDHI1(level)          {R_SYSC->SYS_MSTACCCTL1 =                        \
                                                                        (R_SYSC->SYS_MSTACCCTL1                     \
                                                                         & ~(uint32_t) (                            \
                                                                             R_SYSC_SYS_MSTACCCTL1_SDHI1_ARPU_Msk   \
                                                                             |                                      \
                                                                             R_SYSC_SYS_MSTACCCTL1_SDHI1_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL1_SDHI1_ARSEL_Msk     \
                                                                        | (level <<                                 \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI1_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_GBETHER0(level)      {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                        (R_SYSC->SYS_MSTACCCTL1                       \
                                                                         & ~(uint32_t) (                              \
                                                                             R_SYSC_SYS_MSTACCCTL1_GEther0_AWPU_Msk   \
                                                                             |                                        \
                                                                             R_SYSC_SYS_MSTACCCTL1_GEther0_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL1_GEther0_AWSEL_Msk     \
                                                                        | (level <<                                   \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther0_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_GBETHER0(level)       {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                        (R_SYSC->SYS_MSTACCCTL1                       \
                                                                         & ~(uint32_t) (                              \
                                                                             R_SYSC_SYS_MSTACCCTL1_GEther0_ARPU_Msk   \
                                                                             |                                        \
                                                                             R_SYSC_SYS_MSTACCCTL1_GEther0_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL1_GEther0_ARSEL_Msk     \
                                                                        | (level <<                                   \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther0_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_GBETHER1(level)      {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                        (R_SYSC->SYS_MSTACCCTL1                       \
                                                                         & ~(uint32_t) (                              \
                                                                             R_SYSC_SYS_MSTACCCTL1_GEther1_AWPU_Msk   \
                                                                             |                                        \
                                                                             R_SYSC_SYS_MSTACCCTL1_GEther1_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL1_GEther1_AWSEL_Msk     \
                                                                        | (level <<                                   \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther1_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_GBETHER1(level)       {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                        (R_SYSC->SYS_MSTACCCTL1                       \
                                                                         & ~(uint32_t) (                              \
                                                                             R_SYSC_SYS_MSTACCCTL1_GEther1_ARPU_Msk   \
                                                                             |                                        \
                                                                             R_SYSC_SYS_MSTACCCTL1_GEther1_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL1_GEther1_ARSEL_Msk     \
                                                                        | (level <<                                   \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther1_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB20_HOST(level)    {R_SYSC->SYS_MSTACCCTL2 =                         \
                                                                        (R_SYSC->SYS_MSTACCCTL2                      \
                                                                         & ~(uint32_t) (                             \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB20H_AWPU_Msk   \
                                                                             |                                       \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB20H_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL2_USB20H_AWSEL_Msk     \
                                                                        | (level <<                                  \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB20H_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB20_HOST(level)     {R_SYSC->SYS_MSTACCCTL2 =                         \
                                                                        (R_SYSC->SYS_MSTACCCTL2                      \
                                                                         & ~(uint32_t) (                             \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB20H_ARPU_Msk   \
                                                                             |                                       \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB20H_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL2_USB20H_ARSEL_Msk     \
                                                                        | (level <<                                  \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB20H_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB21_HOST(level)    {R_SYSC->SYS_MSTACCCTL2 =                         \
                                                                        (R_SYSC->SYS_MSTACCCTL2                      \
                                                                         & ~(uint32_t) (                             \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB21H_AWPU_Msk   \
                                                                             |                                       \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB21H_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL2_USB21H_AWSEL_Msk     \
                                                                        | (level <<                                  \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB21H_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB21_HOST(level)     {R_SYSC->SYS_MSTACCCTL2 =                         \
                                                                        (R_SYSC->SYS_MSTACCCTL2                      \
                                                                         & ~(uint32_t) (                             \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB21H_ARPU_Msk   \
                                                                             |                                       \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB21H_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL2_USB21H_ARSEL_Msk     \
                                                                        | (level <<                                  \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB21H_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB20_FUNC(level)    {R_SYSC->SYS_MSTACCCTL2 =                         \
                                                                        (R_SYSC->SYS_MSTACCCTL2                      \
                                                                         & ~(uint32_t) (                             \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB20D_AWPU_Msk   \
                                                                             |                                       \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB20D_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL2_USB20D_AWSEL_Msk     \
                                                                        | (level <<                                  \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB20D_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB20_FUNC(level)     {R_SYSC->SYS_MSTACCCTL2 =                         \
                                                                        (R_SYSC->SYS_MSTACCCTL2                      \
                                                                         & ~(uint32_t) (                             \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB20D_ARPU_Msk   \
                                                                             |                                       \
                                                                             R_SYSC_SYS_MSTACCCTL2_USB20D_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL2_USB20D_ARSEL_Msk     \
                                                                        | (level <<                                  \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB20D_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_VCPL(level)          {R_SYSC->SYS_MSTACCCTL3 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL3                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL3_H264_AWPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL3_H264_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL3_H264_AWSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL3_H264_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_VCPL(level)           {R_SYSC->SYS_MSTACCCTL3 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL3                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL3_H264_ARPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL3_H264_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL3_H264_ARSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL3_H264_ARPU_Pos);} \

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_MIPI_DSI(level)      {R_SYSC->SYS_MSTACCCTL3 =                             \
                                                                        (R_SYSC->SYS_MSTACCCTL3                          \
                                                                         & ~(uint32_t) (                                 \
                                                                             R_SYSC_SYS_MSTACCCTL3_DSI_AWPU_Msk          \
                                                                             |                                           \
                                                                             R_SYSC_SYS_MSTACCCTL3_DSI_AWNS_Msk))        \
                                                                        | R_SYSC_SYS_MSTACCCTL3_DSI_AWSEL_Msk            \
                                                                        | (level << R_SYSC_SYS_MSTACCCTL3_DSI_AWPU_Pos); \
}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_MIPI_DSI(level)       {R_SYSC->SYS_MSTACCCTL3 =                             \
                                                                        (R_SYSC->SYS_MSTACCCTL3                          \
                                                                         & ~(uint32_t) (                                 \
                                                                             R_SYSC_SYS_MSTACCCTL3_DSI_ARPU_Msk          \
                                                                             |                                           \
                                                                             R_SYSC_SYS_MSTACCCTL3_DSI_ARNS_Msk))        \
                                                                        | R_SYSC_SYS_MSTACCCTL3_DSI_ARSEL_Msk            \
                                                                        | (level << R_SYSC_SYS_MSTACCCTL3_DSI_ARPU_Pos); \
}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_ISU(level)           {R_SYSC->SYS_MSTACCCTL4 =                             \
                                                                        (R_SYSC->SYS_MSTACCCTL4                          \
                                                                         & ~(uint32_t) (                                 \
                                                                             R_SYSC_SYS_MSTACCCTL4_ISU_AWPU_Msk          \
                                                                             |                                           \
                                                                             R_SYSC_SYS_MSTACCCTL4_ISU_AWNS_Msk))        \
                                                                        | R_SYSC_SYS_MSTACCCTL4_ISU_AWSEL_Msk            \
                                                                        | (level << R_SYSC_SYS_MSTACCCTL4_ISU_AWPU_Pos); \
}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_ISU(level)            {R_SYSC->SYS_MSTACCCTL4 =                             \
                                                                        (R_SYSC->SYS_MSTACCCTL4                          \
                                                                         & ~(uint32_t) (                                 \
                                                                             R_SYSC_SYS_MSTACCCTL4_ISU_ARPU_Msk          \
                                                                             |                                           \
                                                                             R_SYSC_SYS_MSTACCCTL4_ISU_ARNS_Msk))        \
                                                                        | R_SYSC_SYS_MSTACCCTL4_ISU_ARSEL_Msk            \
                                                                        | (level << R_SYSC_SYS_MSTACCCTL4_ISU_ARPU_Pos); \
}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_CRU_VIDEO(level)     {R_SYSC->SYS_MSTACCCTL4 =                        \
                                                                        (R_SYSC->SYS_MSTACCCTL4                     \
                                                                         & ~(uint32_t) (                            \
                                                                             R_SYSC_SYS_MSTACCCTL4_CRUVD_AWPU_Msk   \
                                                                             |                                      \
                                                                             R_SYSC_SYS_MSTACCCTL4_CRUVD_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL4_CRUVD_AWSEL_Msk     \
                                                                        | (level <<                                 \
                                                                            R_SYSC_SYS_MSTACCCTL4_CRUVD_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_CRU_VIDEO(level)

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_CRU_STATIC(level)    {R_SYSC->SYS_MSTACCCTL4 =                         \
                                                                        (R_SYSC->SYS_MSTACCCTL4                      \
                                                                         & ~(uint32_t) (                             \
                                                                             R_SYSC_SYS_MSTACCCTL4_CRU_ST_AWPU_Msk   \
                                                                             |                                       \
                                                                             R_SYSC_SYS_MSTACCCTL4_CRU_ST_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL4_CRU_ST_AWSEL_Msk     \
                                                                        | (level <<                                  \
                                                                            R_SYSC_SYS_MSTACCCTL4_CRU_ST_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_CRU_STATIC(level)

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DRP0(level)          {R_SYSC->SYS_MSTACCCTL5 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL5                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP0_AWPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP0_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL5_DRP0_AWSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL5_DRP0_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DRP0(level)           {R_SYSC->SYS_MSTACCCTL5 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL5                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP0_ARPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP0_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL5_DRP0_ARSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL5_DRP0_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DRP1(level)          {R_SYSC->SYS_MSTACCCTL5 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL5                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP1_AWPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP1_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL5_DRP1_AWSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL5_DRP1_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DRP1(level)           {R_SYSC->SYS_MSTACCCTL5 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL5                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP1_ARPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP1_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL5_DRP1_ARSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL5_DRP1_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DRP2(level)          {R_SYSC->SYS_MSTACCCTL5 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL5                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP2_AWPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP2_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL5_DRP2_AWSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL5_DRP2_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DRP2(level)           {R_SYSC->SYS_MSTACCCTL5 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL5                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP2_ARPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP2_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL5_DRP2_ARSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL5_DRP2_ARPU_Pos);}

  #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DRP3(level)          {R_SYSC->SYS_MSTACCCTL5 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL5                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP3_AWPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP3_AWNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL5_DRP3_AWSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL5_DRP3_AWPU_Pos);}

  #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DRP3(level)           {R_SYSC->SYS_MSTACCCTL5 =                       \
                                                                        (R_SYSC->SYS_MSTACCCTL5                    \
                                                                         & ~(uint32_t) (                           \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP3_ARPU_Msk   \
                                                                             |                                     \
                                                                             R_SYSC_SYS_MSTACCCTL5_DRP3_ARNS_Msk)) \
                                                                        | R_SYSC_SYS_MSTACCCTL5_DRP3_ARSEL_Msk     \
                                                                        | (level <<                                \
                                                                            R_SYSC_SYS_MSTACCCTL5_DRP3_ARPU_Pos);}

 #endif

#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#ifndef BSP_OVERRIDE_BSP_MST_ACC_CONTROL_IP_T

typedef enum e_mst_acc_control_ip
{
    MST_ACCCNT_DMAC0,
    MST_ACCCNT_DMAC1,
    MST_ACCCNT_3DGE,
    MST_ACCCNT_SDHI0,
    MST_ACCCNT_SDHI1,
    MST_ACCCNT_GBETHER0,
    MST_ACCCNT_GBETHER1,
    MST_ACCCNT_USB20_HOST,
    MST_ACCCNT_USB21_HOST,
    MST_ACCCNT_USB20_FUNC,
    MST_ACCCNT_VCPL,
    MST_ACCCNT_LCDC,
    MST_ACCCNT_MIPI_DSI,
    MST_ACCCNT_ISU,
    MST_ACCCNT_CRU_VIDEO,
    MST_ACCCNT_CRU_STATIC,
    MST_ACCCNT_DRP0,
    MST_ACCCNT_DRP1,
    MST_ACCCNT_DRP2,
    MST_ACCCNT_DRP3
} fsp_mst_acc_control_ip_t;

#endif

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

#if BSP_FEATURE_BSP_ACCESS_CONTROL_SET_SUPPORT

 #ifndef BSP_OVERRIDE_BSP_SLV_ACC_CONTROL_IP_T

typedef enum e_bsp_slv_acccnt
{
    BSP_SLV_ACCCNT_SRAMM,
    BSP_SLV_ACCCNT_SRAMA,
    BSP_SLV_ACCCNT_DDR01,
    BSP_SLV_ACCCNT_DDR11
} bsp_slv_acccnt_t;

 #endif

#endif

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
void R_BSP_SecurityInit(void);

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_SECURITY_H */
