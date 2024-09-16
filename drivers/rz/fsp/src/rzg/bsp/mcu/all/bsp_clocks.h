/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_CLOCKS_H
#define BSP_CLOCKS_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_clock_cfg.h"
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Start clock supply
 *
 * @param      ip       fsp_ip_t enum value for the unit to which the clock is supplied.
 * @param      channel  The channel. Use ch 0 for units without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_CLKON(ip, channel)          {FSP_CRITICAL_SECTION_DEFINE;                                        \
                                                  FSP_CRITICAL_SECTION_ENTER;                                         \
                                                  BSP_CLKON_REG_ ## ip(channel) = 0x00000000U                         \
                                                                                  | (BSP_CLKON_BIT_ ## ip(channel) << \
                                                                                     16U)                             \
                                                                                  | (BSP_CLKON_BIT_ ## ip(channel));  \
                                                  while ((BSP_CLKMON_REG_ ## ip(channel) &                            \
                                                          BSP_CLKMON_BIT_ ## ip(channel)) == 0U)                      \
                                                  { /* wait */};                                                      \
                                                  FSP_CRITICAL_SECTION_EXIT;}

/***********************************************************************************************************************
 * Stop clock supply
 *
 * @param      ip       fsp_ip_t enum value for the unit to stop clock.
 * @param      channel  The channel. Use ch 0 for units without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_CLKOFF(ip, channel)         {FSP_CRITICAL_SECTION_DEFINE;                                        \
                                                  FSP_CRITICAL_SECTION_ENTER;                                         \
                                                  BSP_CLKON_REG_ ## ip(channel) = 0x00000000U                         \
                                                                                  | (BSP_CLKON_BIT_ ## ip(channel) << \
                                                                                     16U);                            \
                                                  while ((BSP_CLKMON_REG_ ## ip(channel) &                            \
                                                          BSP_CLKMON_BIT_ ## ip(channel)) != 0U)                      \
                                                  { /* wait */};                                                      \
                                                  FSP_CRITICAL_SECTION_EXIT;}

/***********************************************************************************************************************
 * Reset assertion
 *
 * @param      ip       fsp_ip_t enum value for the unit to be reset.
 * @param      channel  The channel. Use ch 0 for units without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_RSTON(ip, channel)          {FSP_CRITICAL_SECTION_DEFINE;                                          \
                                                  FSP_CRITICAL_SECTION_ENTER;                                           \
                                                  BSP_RST_REG_ ## ip(channel) = 0x00000000U                             \
                                                                                | (BSP_RST_BIT_ ## ip(channel) << 16U); \
                                                  FSP_CRITICAL_SECTION_EXIT;}

/***********************************************************************************************************************
 * Reset deassertion
 *
 * @param      ip       fsp_ip_t enum value for the unit to release from reset state.
 * @param      channel  The channel. Use ch 0 for units without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_RSTOFF(ip, channel)         {FSP_CRITICAL_SECTION_DEFINE;                                         \
                                                  FSP_CRITICAL_SECTION_ENTER;                                          \
                                                  BSP_RST_REG_ ## ip(channel) = 0x00000000U                            \
                                                                                | (BSP_RST_BIT_ ## ip(channel) << 16U) \
                                                                                | (BSP_RST_BIT_ ## ip(channel));       \
                                                  while ((BSP_RSTMON_REG_ ## ip(channel) &                             \
                                                          BSP_RSTMON_BIT_ ## ip(channel)) != 0U)                       \
                                                  { /* wait */};                                                       \
                                                  FSP_CRITICAL_SECTION_EXIT;}

/***********************************************************************************************************************
 * Definition of macros to control GTM clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_GTM
 #define BSP_CLKON_REG_FSP_IP_GTM(channel)       (R_CPG->CPG_CLKON_GTM)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_GTM
 #define BSP_CLKON_BIT_FSP_IP_GTM(channel)       (1U << (R_CPG_CPG_CLKON_GTM_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_GTM
 #define BSP_CLKMON_REG_FSP_IP_GTM(channel)      (R_CPG->CPG_CLKMON_GTM)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_GTM
 #define BSP_CLKMON_BIT_FSP_IP_GTM(channel)      (1U << (R_CPG_CPG_CLKMON_GTM_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_GTM
 #define BSP_RST_REG_FSP_IP_GTM(channel)         (R_CPG->CPG_RST_GTM)
#endif
#ifndef BSP_RST_BIT_FSP_IP_GTM
 #define BSP_RST_BIT_FSP_IP_GTM(channel)         (1U << (R_CPG_CPG_RST_GTM_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_GTM
 #define BSP_RSTMON_REG_FSP_IP_GTM(channel)      (R_CPG->CPG_RSTMON_GTM)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_GTM
 #define BSP_RSTMON_BIT_FSP_IP_GTM(channel)      (1U << (R_CPG_CPG_RSTMON_GTM_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control GPT clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_GPT(channel)        (R_CPG->CPG_CLKON_GPT)
#define BSP_CLKON_BIT_FSP_IP_GPT(channel)        (1U << (R_CPG_CPG_CLKON_GPT_CLK0_ON_Pos))

#define BSP_CLKMON_REG_FSP_IP_GPT(channel)       (R_CPG->CPG_CLKMON_GPT)
#define BSP_CLKMON_BIT_FSP_IP_GPT(channel)       (1U << (R_CPG_CPG_CLKMON_GPT_CLK0_MON_Pos))

#define BSP_RST_REG_FSP_IP_GPT(channel)          (R_CPG->CPG_RST_GPT)
#define BSP_RST_BIT_FSP_IP_GPT(channel)          (1U << (R_CPG_CPG_RST_GPT_UNIT0_RSTB_Pos))

#define BSP_RSTMON_REG_FSP_IP_GPT(channel)       (R_CPG->CPG_RSTMON_GPT)
#define BSP_RSTMON_BIT_FSP_IP_GPT(channel)       (1U << (R_CPG_CPG_RSTMON_GPT_RST0_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control POEG clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_POEG(channel)       (R_CPG->CPG_CLKON_POEG)
#define BSP_CLKON_BIT_FSP_IP_POEG(channel)       (1U << (R_CPG_CPG_CLKON_POEG_CLK0_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_POEG(channel)      (R_CPG->CPG_CLKMON_POEG)
#define BSP_CLKMON_BIT_FSP_IP_POEG(channel)      (1U << (R_CPG_CPG_CLKMON_POEG_CLK0_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_POEG(channel)         (R_CPG->CPG_RST_POEG)
#define BSP_RST_BIT_FSP_IP_POEG(channel)         (1U << (R_CPG_CPG_RST_POEG_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_POEG(channel)      (R_CPG->CPG_RSTMON_POEG)
#define BSP_RSTMON_BIT_FSP_IP_POEG(channel)      (1U << (R_CPG_CPG_RSTMON_POEG_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control IM33 clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_IM33(channel)       (R_CPG->CPG_CLKON_IM33)
#define BSP_CLKON_BIT_FSP_IP_IM33(channel)       (1U << (R_CPG_CPG_CLKON_IM33_CLK0_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_IM33(channel)      (R_CPG->CPG_CLKMON_IM33)
#define BSP_CLKMON_BIT_FSP_IP_IM33(channel)      (1U << (R_CPG_CPG_CLKMON_IM33_CLK0_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_IM33(channel)         (R_CPG->CPG_RST_IM33)
#define BSP_RST_BIT_FSP_IP_IM33(channel)         (1U << (R_CPG_CPG_RST_IM33_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_IM33(channel)      (R_CPG->CPG_RSTMON_IM33)
#define BSP_RSTMON_BIT_FSP_IP_IM33(channel)      (1U << (R_CPG_CPG_RSTMON_IM33_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control SCIF clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_SCIF(channel)       (R_CPG->CPG_CLKON_SCIF)
#define BSP_CLKON_BIT_FSP_IP_SCIF(channel)       (1U << (R_CPG_CPG_CLKON_SCIF_CLK0_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_SCIF(channel)      (R_CPG->CPG_CLKMON_SCIF)
#define BSP_CLKMON_BIT_FSP_IP_SCIF(channel)      (1U << (R_CPG_CPG_CLKMON_SCIF_CLK0_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_SCIF(channel)         (R_CPG->CPG_RST_SCIF)
#define BSP_RST_BIT_FSP_IP_SCIF(channel)         (1U << (R_CPG_CPG_RST_SCIF_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_SCIF(channel)      (R_CPG->CPG_RSTMON_SCIF)
#define BSP_RSTMON_BIT_FSP_IP_SCIF(channel)      (1U << (R_CPG_CPG_RSTMON_SCIF_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control RIIC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_RIIC(channel)       (R_CPG->CPG_CLKON_I2C)
#define BSP_CLKON_BIT_FSP_IP_RIIC(channel)       (1U << (R_CPG_CPG_CLKON_I2C_CLK0_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_RIIC(channel)      (R_CPG->CPG_CLKMON_I2C)
#define BSP_CLKMON_BIT_FSP_IP_RIIC(channel)      (1U << (R_CPG_CPG_CLKMON_I2C_CLK0_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_RIIC(channel)         (R_CPG->CPG_RST_I2C)
#define BSP_RST_BIT_FSP_IP_RIIC(channel)         (1U << (R_CPG_CPG_RST_I2C_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_RIIC(channel)      (R_CPG->CPG_RSTMON_I2C)
#define BSP_RSTMON_BIT_FSP_IP_RIIC(channel)      (1U << (R_CPG_CPG_RSTMON_I2C_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control RSPI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_RSPI(channel)       (R_CPG->CPG_CLKON_RSPI)
#define BSP_CLKON_BIT_FSP_IP_RSPI(channel)       (1U << (R_CPG_CPG_CLKON_RSPI_CLK0_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_RSPI(channel)      (R_CPG->CPG_CLKMON_RSPI)
#define BSP_CLKMON_BIT_FSP_IP_RSPI(channel)      (1U << (R_CPG_CPG_CLKMON_RSPI_CLK0_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_RSPI(channel)         (R_CPG->CPG_RST_RSPI)
#define BSP_RST_BIT_FSP_IP_RSPI(channel)         (1U << (R_CPG_CPG_RST_RSPI_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_RSPI(channel)      (R_CPG->CPG_RSTMON_RSPI)
#define BSP_RSTMON_BIT_FSP_IP_RSPI(channel)      (1U << (R_CPG_CPG_RSTMON_RSPI_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control MHU clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_MHU(channel)        (R_CPG->CPG_CLKON_MHU)
#define BSP_CLKON_BIT_FSP_IP_MHU(channel)        (1U << (R_CPG_CPG_CLKON_MHU_CLK0_ON_Pos))

#define BSP_CLKMON_REG_FSP_IP_MHU(channel)       (R_CPG->CPG_CLKMON_MHU)
#define BSP_CLKMON_BIT_FSP_IP_MHU(channel)       (1U << (R_CPG_CPG_CLKMON_MHU_CLK0_MON_Pos))

#define BSP_RST_REG_FSP_IP_MHU(channel)          (R_CPG->CPG_RST_MHU)
#define BSP_RST_BIT_FSP_IP_MHU(channel)          (1U << (R_CPG_CPG_RST_MHU_UNIT0_RSTB_Pos))

#define BSP_RSTMON_REG_FSP_IP_MHU(channel)       (R_CPG->CPG_RSTMON_MHU)
#define BSP_RSTMON_BIT_FSP_IP_MHU(channel)       (1U << (R_CPG_CPG_RSTMON_MHU_RST0_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control DMAC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_DMAC(channel)       (R_CPG->CPG_CLKON_DMAC_REG)
#define BSP_CLKON_BIT_FSP_IP_DMAC(channel)       (3U << (R_CPG_CPG_CLKON_DMAC_REG_CLK0_ON_Pos))

#define BSP_CLKMON_REG_FSP_IP_DMAC(channel)      (R_CPG->CPG_CLKMON_DMAC_REG)
#define BSP_CLKMON_BIT_FSP_IP_DMAC(channel)      (3U << (R_CPG_CPG_CLKMON_DMAC_REG_CLK0_MON_Pos))

#define BSP_RST_REG_FSP_IP_DMAC(channel)         (R_CPG->CPG_RST_DMAC)
#define BSP_RST_BIT_FSP_IP_DMAC(channel)         (3U << (R_CPG_CPG_RST_DMAC_UNIT0_RSTB_Pos))

#define BSP_RSTMON_REG_FSP_IP_DMAC(channel)      (R_CPG->CPG_RSTMON_DMAC)
#define BSP_RSTMON_BIT_FSP_IP_DMAC(channel)      (3U << (R_CPG_CPG_RSTMON_DMAC_RST0_MON_Pos))

#define BSP_CLKON_REG_FSP_IP_DMAC_s(channel)     BSP_CLKON_REG_FSP_IP_DMAC(channel)
#define BSP_CLKON_BIT_FSP_IP_DMAC_s(channel)     BSP_CLKON_BIT_FSP_IP_DMAC(channel)

#define BSP_CLKMON_REG_FSP_IP_DMAC_s(channel)    BSP_CLKMON_REG_FSP_IP_DMAC(channel)
#define BSP_CLKMON_BIT_FSP_IP_DMAC_s(channel)    BSP_CLKMON_BIT_FSP_IP_DMAC(channel)

#define BSP_RST_REG_FSP_IP_DMAC_s(channel)       BSP_RST_REG_FSP_IP_DMAC(channel)
#define BSP_RST_BIT_FSP_IP_DMAC_s(channel)       BSP_RST_BIT_FSP_IP_DMAC(channel)

#define BSP_RSTMON_REG_FSP_IP_DMAC_s(channel)    BSP_RSTMON_REG_FSP_IP_DMAC(channel)
#define BSP_RSTMON_BIT_FSP_IP_DMAC_s(channel)    BSP_RSTMON_BIT_FSP_IP_DMAC(channel)

/***********************************************************************************************************************
 * Definition of macros to control SSI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_SSI(channel)        (R_CPG->CPG_CLKON_SSI)
#define BSP_CLKON_BIT_FSP_IP_SSI(channel)        (1U << (R_CPG_CPG_CLKON_SSI_CLK0_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_SSI(channel)       (R_CPG->CPG_CLKMON_SSI)
#define BSP_CLKMON_BIT_FSP_IP_SSI(channel)       (1U << (R_CPG_CPG_CLKMON_SSI_CLK0_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_SSI(channel)          (R_CPG->CPG_RST_SSIF)
#define BSP_RST_BIT_FSP_IP_SSI(channel)          (1U << (R_CPG_CPG_RST_SSIF_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_SSI(channel)       (R_CPG->CPG_RSTMON_SSIF)
#define BSP_RSTMON_BIT_FSP_IP_SSI(channel)       (1U << (R_CPG_CPG_RSTMON_SSIF_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control CANFD clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_CANFD(channel)      (R_CPG->CPG_CLKON_CANFD)
#define BSP_CLKON_BIT_FSP_IP_CANFD(channel)      (1U << (R_CPG_CPG_CLKON_CANFD_CLK0_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_CANFD(channel)     (R_CPG->CPG_CLKMON_CANFD)
#define BSP_CLKMON_BIT_FSP_IP_CANFD(channel)     (1U << (R_CPG_CPG_CLKMON_CANFD_CLK0_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_CANFD(channel)        (R_CPG->CPG_RST_CANFD)
#define BSP_RST_BIT_FSP_IP_CANFD(channel)        (1U << (R_CPG_CPG_RST_CANFD_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_CANFD(channel)     (R_CPG->CPG_RSTMON_CANFD)
#define BSP_RSTMON_BIT_FSP_IP_CANFD(channel)     (1U << (R_CPG_CPG_RSTMON_CANFD_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control ADC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_ADC(channel)        (R_CPG->CPG_CLKON_ADC)
#define BSP_CLKON_BIT_FSP_IP_ADC(channel)        (3U << R_CPG_CPG_CLKON_ADC_CLK0_ON_Pos)

#define BSP_CLKMON_REG_FSP_IP_ADC(channel)       (R_CPG->CPG_CLKMON_ADC)
#define BSP_CLKMON_BIT_FSP_IP_ADC(channel)       (3U << R_CPG_CPG_CLKMON_ADC_CLK0_MON_Pos)

#define BSP_RST_REG_FSP_IP_ADC(channel)          (R_CPG->CPG_RST_ADC)
#define BSP_RST_BIT_FSP_IP_ADC(channel)          (3U << R_CPG_CPG_RST_ADC_UNIT0_RSTB_Pos)

#define BSP_RSTMON_REG_FSP_IP_ADC(channel)       (R_CPG->CPG_RSTMON_ADC)
#define BSP_RSTMON_BIT_FSP_IP_ADC(channel)       (3U << R_CPG_CPG_RSTMON_ADC_RST0_MON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control TSU clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_TSU(channel)        (R_CPG->CPG_CLKON_TSU)
#define BSP_CLKON_BIT_FSP_IP_TSU(channel)        (1U << (R_CPG_CPG_CLKON_TSU_CLK0_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_TSU(channel)       (R_CPG->CPG_CLKMON_TSU)
#define BSP_CLKMON_BIT_FSP_IP_TSU(channel)       (1U << (R_CPG_CPG_CLKMON_TSU_CLK0_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_TSU(channel)          (R_CPG->CPG_RST_TSU)
#define BSP_RST_BIT_FSP_IP_TSU(channel)          (1U << (R_CPG_CPG_RST_TSU_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_TSU(channel)       (R_CPG->CPG_RSTMON_TSU)
#define BSP_RSTMON_BIT_FSP_IP_TSU(channel)       (1U << (R_CPG_CPG_RSTMON_TSU_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control WDT clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_WDT(channel)        (R_CPG->CPG_CLKON_WDT)
#define BSP_CLKON_BIT_FSP_IP_WDT(channel)        (3U << (R_CPG_CPG_CLKON_WDT_CLK0_ON_Pos + 2U * (channel)))

#define BSP_CLKMON_REG_FSP_IP_WDT(channel)       (R_CPG->CPG_CLKMON_WDT)
#define BSP_CLKMON_BIT_FSP_IP_WDT(channel)       (3U << (R_CPG_CPG_CLKMON_WDT_CLK0_MON_Pos + 2U * (channel)))

#define BSP_RST_REG_FSP_IP_WDT(channel)          (R_CPG->CPG_RST_WDT)
#define BSP_RST_BIT_FSP_IP_WDT(channel)          (1U << (R_CPG_CPG_RST_WDT_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_WDT(channel)       (R_CPG->CPG_RSTMON_WDT)
#define BSP_RSTMON_BIT_FSP_IP_WDT(channel)       (1U << (R_CPG_CPG_RSTMON_WDT_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control SCI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_SCI(channel)        (R_CPG->CPG_CLKON_SCI)
#define BSP_CLKON_BIT_FSP_IP_SCI(channel)        (1U << (R_CPG_CPG_CLKON_SCI_CLK0_ON_Pos + (channel)))

#define BSP_CLKMON_REG_FSP_IP_SCI(channel)       (R_CPG->CPG_CLKMON_SCI)
#define BSP_CLKMON_BIT_FSP_IP_SCI(channel)       (1U << (R_CPG_CPG_CLKMON_SCI_CLK0_MON_Pos + (channel)))

#define BSP_RST_REG_FSP_IP_SCI(channel)          (R_CPG->CPG_RST_SCI)
#define BSP_RST_BIT_FSP_IP_SCI(channel)          (1U << (R_CPG_CPG_RST_SCI_UNIT0_RSTB_Pos + (channel)))

#define BSP_RSTMON_REG_FSP_IP_SCI(channel)       (R_CPG->CPG_RSTMON_SCI)
#define BSP_RSTMON_BIT_FSP_IP_SCI(channel)       (1U << (R_CPG_CPG_RSTMON_SCI_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control TSU clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_MTU3(channel)       (R_CPG->CPG_CLKON_MTU)
#define BSP_CLKON_BIT_FSP_IP_MTU3(channel)       (1U << (R_CPG_CPG_CLKON_MTU_CLK0_ON_Pos))

#define BSP_CLKMON_REG_FSP_IP_MTU3(channel)      (R_CPG->CPG_CLKMON_MTU)
#define BSP_CLKMON_BIT_FSP_IP_MTU3(channel)      (1U << (R_CPG_CPG_CLKMON_MTU_CLK0_MON_Pos))

#define BSP_RST_REG_FSP_IP_MTU3(channel)         (R_CPG->CPG_RST_MTU)
#define BSP_RST_BIT_FSP_IP_MTU3(channel)         (1U << (R_CPG_CPG_RST_MTU_UNIT0_RSTB_Pos))

#define BSP_RSTMON_REG_FSP_IP_MTU3(channel)      (R_CPG->CPG_RSTMON_MTU)
#define BSP_RSTMON_BIT_FSP_IP_MTU3(channel)      (1U << (R_CPG_CPG_RSTMON_MTU_RST0_MON_Pos))

/* CPG_PL1_DDIV.DIVPL1_SET options. */
#define BSP_CLOCKS_PL1_DIV_1                (0) // Divide ICLK source clock by 1
#define BSP_CLOCKS_PL1_DIV_2                (1) // Divide ICLK source clock by 2
#define BSP_CLOCKS_PL1_DIV_4                (2) // Divide ICLK source clock by 4
#define BSP_CLOCKS_PL1_DIV_8                (3) // Divide ICLK source clock by 8

/* CPG_PL2_DDIV.DIVPL2B_SET options. */
#define BSP_CLOCKS_PL2B_DIV_1               (0) // Divide P0CLK source clock by 1
#define BSP_CLOCKS_PL2B_DIV_2               (1) // Divide P0CLK source clock by 2
#define BSP_CLOCKS_PL2B_DIV_4               (2) // Divide P0CLK source clock by 4
#define BSP_CLOCKS_PL2B_DIV_8               (3) // Divide P0CLK source clock by 8
#define BSP_CLOCKS_PL2B_DIV_32              (4) // Divide P0CLK source clock by 32

/* CPG_PL3_DDIV.DIVPL3C_SET options. */
#define BSP_CLOCKS_PL3C_DIV_1               (0) // Divide SPI0CLK source clock by 1
#define BSP_CLOCKS_PL3C_DIV_2               (1) // Divide SPI0CLK source clock by 2
#define BSP_CLOCKS_PL3C_DIV_4               (2) // Divide SPI0CLK source clock by 4
#define BSP_CLOCKS_PL3C_DIV_8               (3) // Divide SPI0CLK source clock by 8
#define BSP_CLOCKS_PL3C_DIV_32              (4) // Divide SPI0CLK source clock by 32

/* CPG_PL3_DDIV.DIVPL3B_SET options. */
#define BSP_CLOCKS_PL3B_DIV_1               (0) // Divide P1CLK source clock by 1
#define BSP_CLOCKS_PL3B_DIV_2               (1) // Divide P1CLK source clock by 2
#define BSP_CLOCKS_PL3B_DIV_4               (2) // Divide P1CLK source clock by 4
#define BSP_CLOCKS_PL3B_DIV_8               (3) // Divide P1CLK source clock by 8
#define BSP_CLOCKS_PL3B_DIV_32              (4) // Divide P1CLK source clock by 32

/* CPG_PL3_DDIV.DIVPL3A_SET options. */
#define BSP_CLOCKS_PL3A_DIV_1               (0) // Divide P2CLK source clock by 1
#define BSP_CLOCKS_PL3A_DIV_2               (1) // Divide P2CLK source clock by 2
#define BSP_CLOCKS_PL3A_DIV_4               (2) // Divide P2CLK source clock by 4
#define BSP_CLOCKS_PL3A_DIV_8               (3) // Divide P2CLK source clock by 8
#define BSP_CLOCKS_PL3A_DIV_32              (4) // Divide P2CLK source clock by 32

/* CPG_PL6_DDIV.DIVPL6B_SET options. */
#define BSP_CLOCKS_PL6B_DIV_1               (0) // Divide I3CLK source clock by 1
#define BSP_CLOCKS_PL6B_DIV_2               (1) // Divide I3CLK source clock by 2
#define BSP_CLOCKS_PL6B_DIV_4               (2) // Divide I3CLK source clock by 4
#define BSP_CLOCKS_PL6B_DIV_8               (3) // Divide I3CLK source clock by 8
#define BSP_CLOCKS_PL6B_DIV_32              (4) // Divide I3CLK source clock by 32

/* CPG_PL6_DDIV.DIVPL6A_SET options. */
#define BSP_CLOCKS_PL6A_DIV_1               (0) // Divide I2CLK source clock by 1
#define BSP_CLOCKS_PL6A_DIV_2               (1) // Divide I2CLK source clock by 2
#define BSP_CLOCKS_PL6A_DIV_4               (2) // Divide I2CLK source clock by 4
#define BSP_CLOCKS_PL6A_DIV_8               (3) // Divide I2CLK source clock by 8
#define BSP_CLOCKS_PL6A_DIV_32              (4) // Divide I2CLK source clock by 32

/* CPG_SDHI_DDIV.DIVSDHI2_SET options. */
#define BSP_CLOCKS_SDHI2_DIV_1              (0) // Divide SD2CLK source clock by 1
#define BSP_CLOCKS_SDHI2_DIV_2              (1) // Divide SD2CLK source clock by 2

/* CPG_SDHI_DDIV.DIVSDHI1_SET options. */
#define BSP_CLOCKS_SDHI1_DIV_1              (0) // Divide SD1CLK source clock by 1
#define BSP_CLOCKS_SDHI1_DIV_2              (1) // Divide SD1CLK source clock by 2

/* CPG_SDHI_DDIV.DIVSDHI0_SET options. */
#define BSP_CLOCKS_SDHI0_DIV_1              (0) // Divide SD0CLK source clock by 1
#define BSP_CLOCKS_SDHI0_DIV_2              (1) // Divide SD0CLK source clock by 2

/* CPG_OCTA_DDIV.DIVOCTA_SET options. */
#define BSP_CLOCKS_OCTA_DIV_1               (0) // Divide OCCLK source clock by 1
#define BSP_CLOCKS_OCTA_DIV_2               (1) // Divide OCCLK source clock by 2
#define BSP_CLOCKS_OCTA_DIV_4               (2) // Divide OCCLK source clock by 4
#define BSP_CLOCKS_OCTA_DIV_8               (3) // Divide OCCLK source clock by 8
#define BSP_CLOCKS_OCTA_DIV_32              (4) // Divide OCCLK source clock by 32

/* CPG_SPI_DDIV.DIVSPI_SET options. */
#define BSP_CLOCKS_SPI_DIV_1                (0) // Divide SPICLK source clock by 1
#define BSP_CLOCKS_SPI_DIV_2                (1) // Divide SPICLK source clock by 2
#define BSP_CLOCKS_SPI_DIV_4                (2) // Divide SPICLK source clock by 4
#define BSP_CLOCKS_SPI_DIV_8                (3) // Divide SPICLK source clock by 8
#define BSP_CLOCKS_SPI_DIV_32               (4) // Divide SPICLK source clock by 32

/* CPG_PLL_DSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_OSC_0024    (0) // Select OSC/1000 clock
#define BSP_CLOCKS_SOURCE_CLOCK_PLL4        (1) // Select PLL4 clock

/* CPG_SDHI_DSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_PLL2_800    (0) // Select 800MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL6_500    (2) // Select 500MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL2_266    (3) // Select 266MHz

/* CPG_OCTA_SSEL and CPG_SPI_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_PLL3_400    (0) // Select 400MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL3_266    (2) // Select 266MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL6_250    (3) // Select 250MHz

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* Public functions defined in bsp_clocks.c */
void bsp_clock_init(void);             // Used internally by BSP
void bsp_clock_freq_init_cfg(void);    // Used internally by BSP

#if BSP_TZ_CFG_INIT_SECURE_ONLY
void bsp_clock_freq_var_init(void);    // Used internally by BSP

#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
