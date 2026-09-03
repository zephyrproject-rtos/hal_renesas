/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MODULE_H
#define BSP_MODULE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

#include "bsp_register_protection.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

#define R_BSP_MSTPCRA    (R_MSTP->MSTPCRA)

/*******************************************************************************************************************//**
 * Cancels the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      channel  The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/
#define R_BSP_MODULE_START(ip, channel)        {FSP_CRITICAL_SECTION_DEFINE;                                   \
                                                FSP_CRITICAL_SECTION_ENTER;                                    \
                                                BSP_MSTP_REG_ ## ip(channel) &= ~BSP_MSTP_BIT_ ## ip(channel); \
                                                BSP_MSTP_REG_ ## ip(channel);                                  \
                                                FSP_CRITICAL_SECTION_EXIT;                                     \
                                                FSP_HARDWARE_REGISTER_WAIT((BSP_MSTP_REG_ ## ip(channel) & BSP_MSTP_BIT_ ## ip(channel)), 0U);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      channel  The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/
#define R_BSP_MODULE_STOP(ip, channel)         {FSP_CRITICAL_SECTION_DEFINE;                                  \
                                                FSP_CRITICAL_SECTION_ENTER;                                   \
                                                BSP_MSTP_REG_ ## ip(channel) |= BSP_MSTP_BIT_ ## ip(channel); \
                                                BSP_MSTP_REG_ ## ip(channel);                                 \
                                                FSP_CRITICAL_SECTION_EXIT;                                    \
                                                FSP_HARDWARE_REGISTER_WAIT((BSP_MSTP_REG_ ## ip(channel) & BSP_MSTP_BIT_ ## ip(channel)), BSP_MSTP_BIT_ ## ip(channel));}

/** @} (end addtogroup BSP_MCU) */

#define BSP_MSTP_REG_FSP_IP_SRAM(channel)      R_BSP_MSTPCRA
#define BSP_MSTP_BIT_FSP_IP_SRAM(channel)      (1U << (0U + channel))
#define BSP_MSTP_REG_FSP_IP_DMAC(channel)      R_BSP_MSTPCRA
#define BSP_MSTP_BIT_FSP_IP_DMAC(channel)      (1U << (22U))
#define BSP_MSTP_REG_FSP_IP_DTC(channel)       R_BSP_MSTPCRA
#define BSP_MSTP_BIT_FSP_IP_DTC(channel)       (1U << (22U))
#define BSP_MSTP_REG_FSP_IP_EXDMAC(channel)    R_BSP_MSTPCRA
#define BSP_MSTP_BIT_FSP_IP_EXDMAC(channel)    (1U << (29U))

#define BSP_MSTP_REG_FSP_IP_I3C(channel)       R_MSTP->MSTPCRB
#define BSP_MSTP_BIT_FSP_IP_I3C(channel)       (1U << (BSP_FEATURE_I3C_MSTP_OFFSET - channel))
#define BSP_MSTP_REG_FSP_IP_IIC(channel)       R_MSTP->MSTPCRB
#define BSP_MSTP_BIT_FSP_IP_IIC(channel)       (1U << (9U - channel))
#define BSP_MSTP_REG_FSP_IP_USBFS(channel)     R_MSTP->MSTPCRB
#define BSP_MSTP_BIT_FSP_IP_USBFS(channel)     (1U << (11U))
#define BSP_MSTP_REG_FSP_IP_USBHS(channel)     R_MSTP->MSTPCRB
#define BSP_MSTP_BIT_FSP_IP_USBHS(channel)     (1U << (12U))
#define BSP_MSTP_REG_FSP_IP_XSPI(channel)      R_MSTP->MSTPCRB
#define BSP_MSTP_BIT_FSP_IP_XSPI(channel)      (1U << (16U + channel))
#define BSP_MSTP_REG_FSP_IP_SPI(channel)       *((channel < 2U) ? &R_MSTP->MSTPCRB : &R_MSTP->MSTPCRC)
#define BSP_MSTP_BIT_FSP_IP_SPI(channel)       ((channel < 2U) ? (1U << (19U - channel)) : (1U << (23U)))
#define BSP_MSTP_REG_FSP_IP_SCI(channel)       R_MSTP->MSTPCRB
#define BSP_MSTP_BIT_FSP_IP_SCI(channel)       ((12U == channel) ? (1U << (0U)) : (1U << ((31U) - channel)))

#define BSP_MSTP_REG_FSP_IP_CAC(channel)       R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_CAC(channel)       (1U << (0U))
#define BSP_MSTP_REG_FSP_IP_CRC(channel)       R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_CRC(channel)       (1U << (1U))
#define BSP_MSTP_REG_FSP_IP_PDC(channel)       R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_PDC(channel)       (1U << (2U))
#define BSP_MSTP_REG_FSP_IP_SSI(channel)       R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_SSI(channel)       (1U << (8U - channel))
#define BSP_MSTP_REG_FSP_IP_SDHI(channel)      R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_SDHI(channel)      (1U << (12U - channel))
#define BSP_MSTP_REG_FSP_IP_DOC(channel)       R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_DOC(channel)       (1U << (13U))
#define BSP_MSTP_REG_FSP_IP_ELC(channel)       R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_ELC(channel)       (1U << (14U))
#define BSP_MSTP_REG_FSP_IP_PDMIF(channel)     R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_PDMIF(channel)     (1U << (24U))
#define BSP_MSTP_REG_FSP_IP_CANFDG(channel)    R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_CANFDG(channel)    (1U << (25U))
#define BSP_MSTP_REG_FSP_IP_CANFD(channel)     R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_CANFD(channel)     (1U << (27U))
#define BSP_MSTP_REG_FSP_IP_ETHPHY(channel)    R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_ETHPHY(channel)    (1U << (28U))
#define BSP_MSTP_REG_FSP_IP_ESC(channel)       R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_ESC(channel)       (1U << (29U))
#define BSP_MSTP_REG_FSP_IP_ESWM(channel)      R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_ESWM(channel)      (1U << (30U))
#define BSP_MSTP_REG_FSP_IP_RSIP(channel)      R_MSTP->MSTPCRC
#define BSP_MSTP_BIT_FSP_IP_RSIP(channel)      (1U << (31U))

#define BSP_MSTP_REG_FSP_IP_HRPWM(channel)     R_MSTP->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_HRPWM(channel)     (1U << (6U))
#define BSP_MSTP_REG_FSP_IP_DSMIF(channel)     R_MSTP->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_DSMIF(channel)     (1U << (9U - channel))
#define BSP_MSTP_REG_FSP_IP_POEG(channel)      R_MSTP->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_POEG(channel)      (1U << (14U - channel))
#define BSP_MSTP_REG_FSP_IP_DAC(channel)       R_MSTP->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_DAC(channel)       (1U << (20U - channel))
#define BSP_MSTP_REG_FSP_IP_ADC(channel)       R_MSTP->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_ADC(channel)       (1U << (21U))
#define BSP_MSTP_REG_FSP_IP_TSN(channel)       R_MSTP->MSTPCRD
#define BSP_MSTP_BIT_FSP_IP_TSN(channel)       (1U << (22U))

#define BSP_MSTP_REG_FSP_IP_GPT(channel)       R_MSTP->MSTPCRE
#define BSP_MSTP_BIT_FSP_IP_GPT(channel)       (1U << (31))

#define BSP_MSTP_REG_FSP_IP_TMR(channel)       R_MSTP->MSTPCRF
#define BSP_MSTP_BIT_FSP_IP_TMR(channel)       ((BSP_FEATURE_BSP_MSTP_TMR_MSTPF7_MAX_CH >= channel) ? \
                                                (1U << (7U)) : (1U << (6U)))
#define BSP_MSTP_REG_FSP_IP_MTU(channel)       R_MSTP->MSTPCRF
#define BSP_MSTP_BIT_FSP_IP_MTU(channel)       (1U << (8U))
#define BSP_MSTP_REG_FSP_IP_CMTW(channel)      R_MSTP->MSTPCRF
#define BSP_MSTP_BIT_FSP_IP_CMTW(channel)      (1U << (13U - channel))
#define BSP_MSTP_REG_FSP_IP_CMT(channel)       R_MSTP->MSTPCRF
#define BSP_MSTP_BIT_FSP_IP_CMT(channel)       ((BSP_FEATURE_BSP_MSTP_CMT_MSTPF15_MAX_CH >= channel) ? \
                                                (1U << (15U)) : (1U << (14U)))
#define BSP_MSTP_REG_FSP_IP_PIO(channel)       R_MSTP->MSTPCRF
#define BSP_MSTP_BIT_FSP_IP_PIO(channel)       (1U << (16U - channel))
#define BSP_MSTP_REG_FSP_IP_PCIF(channel)      R_MSTP->MSTPCRF
#define BSP_MSTP_BIT_FSP_IP_PCIF(channel)      (1U << (31U - channel))

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
