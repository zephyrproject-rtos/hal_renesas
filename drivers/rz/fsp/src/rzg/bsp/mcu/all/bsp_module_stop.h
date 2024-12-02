/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MODULE_H
#define BSP_MODULE_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 * Cancels the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be started.
 * @param      channel  The channel. Use ch 0 for modules without channels.
 *********************************************************************************************************************/
#define R_BSP_MSTP_START(ip, channel)          {FSP_CRITICAL_SECTION_DEFINE;                                            \
                                                FSP_CRITICAL_SECTION_ENTER;                                             \
                                                BSP_MSTP_REG_ ## ip(channel) = 0x00000000U                              \
                                                                               | (BSP_MSTP_BIT_ ## ip(channel) << 16U); \
                                                BSP_MSTP_REG_ ## ip(channel);                                           \
                                                FSP_CRITICAL_SECTION_EXIT;}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped.
 * @param      channel  The channel. Use ch 0 for modules without channels.
 *********************************************************************************************************************/
#define R_BSP_MSTP_STOP(ip, channel)           {FSP_CRITICAL_SECTION_DEFINE;                                            \
                                                FSP_CRITICAL_SECTION_ENTER;                                             \
                                                BSP_MSTP_REG_ ## ip(channel) = 0x0000FFFFU                              \
                                                                               | (BSP_MSTP_BIT_ ## ip(channel) << 16U); \
                                                BSP_MSTP_REG_ ## ip(channel);                                           \
                                                FSP_CRITICAL_SECTION_EXIT;}

/** @} (end addtogroup BSP_MCU) */
#define BSP_MSTP_REG_FSP_IP_GTM(channel)       R_CPG->CPG_BUS_REG0_MSTOP
#define BSP_MSTP_BIT_FSP_IP_GTM(channel)       (1U << (R_CPG_CPG_BUS_REG0_MSTOP_MSTOP4_ON_Pos + channel))

#define BSP_MSTP_REG_FSP_IP_GPT(channel)       R_CPG->CPG_BUS_MCPU1_MSTOP
#define BSP_MSTP_BIT_FSP_IP_GPT(channel)       (1U << R_CPG_CPG_BUS_MCPU1_MSTOP_MSTOP4_ON_Pos)

#define BSP_MSTP_REG_FSP_IP_POEG(channel)      R_CPG->CPG_BUS_MCPU1_MSTOP
#define BSP_MSTP_BIT_FSP_IP_POEG(channel)      (1U << (R_CPG_CPG_BUS_MCPU1_MSTOP_MSTOP5_ON_Pos + channel))

#define BSP_MSTP_REG_FSP_IP_PORT(channel)      R_CPG->CPG_BUS_PERI_CPU_MSTOP
#define BSP_MSTP_BIT_FSP_IP_PORT(channel)      (1U << R_CPG_CPG_BUS_PERI_CPU_MSTOP_MSTOP6_ON_Pos)

#define BSP_MSTP_REG_FSP_IP_IM33(channel)      R_CPG->CPG_BUS_PERI_CPU_MSTOP
#define BSP_MSTP_BIT_FSP_IP_IM33(channel)      (1U << R_CPG_CPG_BUS_PERI_CPU_MSTOP_MSTOP14_ON_Pos)

#ifndef BSP_MSTP_REG_FSP_IP_SCIF
 #define BSP_MSTP_REG_FSP_IP_SCIF(channel)     R_CPG->CPG_BUS_MCPU2_MSTOP
#endif
#ifndef BSP_MSTP_BIT_FSP_IP_SCIF
 #define BSP_MSTP_BIT_FSP_IP_SCIF(channel)     (1U << (R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP1_ON_Pos + channel))
#endif

#define BSP_MSTP_REG_FSP_IP_RIIC(channel)      R_CPG->CPG_BUS_MCPU2_MSTOP
#define BSP_MSTP_BIT_FSP_IP_RIIC(channel)      (1U << (R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP10_ON_Pos + channel))

#ifndef BSP_MSTP_REG_FSP_IP_RSPI
 #define BSP_MSTP_REG_FSP_IP_RSPI(channel)     *((1U >= \
                                                  channel) ? &R_CPG->CPG_BUS_MCPU1_MSTOP : &R_CPG->CPG_BUS_MCPU2_MSTOP)
#endif
#ifndef BSP_MSTP_BIT_FSP_IP_RSPI
 #define BSP_MSTP_BIT_FSP_IP_RSPI(channel)     ((1U >=                                                                   \
                                                 channel) ? (1U << (R_CPG_CPG_BUS_MCPU1_MSTOP_MSTOP14_ON_Pos + channel)) \
                                                : (1U << R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP0_ON_Pos))
#endif

#define BSP_MSTP_REG_FSP_IP_MHU(channel)       R_CPG->CPG_MHU_MSTOP
#define BSP_MSTP_BIT_FSP_IP_MHU(channel)       (1U << R_CPG_CPG_MHU_MSTOP_MSTOP0_ON_Pos)

#define BSP_MSTP_REG_FSP_IP_DMAC(channel)      R_CPG->CPG_BUS_REG1_MSTOP
#define BSP_MSTP_BIT_FSP_IP_DMAC(channel)      (3U <<                                     \
                                                (R_CPG_CPG_BUS_REG1_MSTOP_MSTOP0_ON_Pos + \
                                                 (channel * R_CPG_CPG_BUS_REG1_MSTOP_MSTOP2_ON_Pos)))
#define BSP_MSTP_REG_FSP_IP_DMAC_s(channel)    BSP_MSTP_REG_FSP_IP_DMAC(channel)
#define BSP_MSTP_BIT_FSP_IP_DMAC_s(channel)    BSP_MSTP_BIT_FSP_IP_DMAC(channel)

#define BSP_MSTP_REG_FSP_IP_SSI(channel)       R_CPG->CPG_BUS_MCPU1_MSTOP
#define BSP_MSTP_BIT_FSP_IP_SSI(channel)       (1U << (R_CPG_CPG_BUS_MCPU1_MSTOP_MSTOP10_ON_Pos + channel))

#define BSP_MSTP_REG_FSP_IP_CANFD(channel)     R_CPG->CPG_BUS_MCPU2_MSTOP
#define BSP_MSTP_BIT_FSP_IP_CANFD(channel)     (1U << R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP9_ON_Pos)

#define BSP_MSTP_REG_FSP_IP_ADC(channel)       R_CPG->CPG_BUS_MCPU2_MSTOP
#define BSP_MSTP_BIT_FSP_IP_ADC(channel)       (1U << R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP14_ON_Pos)

#define BSP_MSTP_REG_FSP_IP_TSU(channel)       R_CPG->CPG_BUS_MCPU2_MSTOP
#define BSP_MSTP_BIT_FSP_IP_TSU(channel)       (1U << R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP15_ON_Pos)

#define BSP_MSTP_REG_FSP_IP_WDT(channel)       R_CPG->CPG_BUS_REG0_MSTOP
#define BSP_MSTP_BIT_FSP_IP_WDT(channel)       ((2U == (channel)) ? (1U << R_CPG_CPG_BUS_REG0_MSTOP_MSTOP1_ON_Pos) \
                                                : (1U << (R_CPG_CPG_BUS_REG0_MSTOP_MSTOP2_ON_Pos + channel)))

#define BSP_MSTP_REG_FSP_IP_SCI(channel)       R_CPG->CPG_BUS_MCPU2_MSTOP
#define BSP_MSTP_BIT_FSP_IP_SCI(channel)       (1U << (R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP7_ON_Pos + channel))

#define BSP_MSTP_REG_FSP_IP_MTU3(channel)      R_CPG->CPG_BUS_MCPU1_MSTOP
#define BSP_MSTP_BIT_FSP_IP_MTU3(channel)      (1U << (R_CPG_CPG_BUS_MCPU1_MSTOP_MSTOP2_ON_Pos))

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif                                 /* BSP_MODULE_H */
