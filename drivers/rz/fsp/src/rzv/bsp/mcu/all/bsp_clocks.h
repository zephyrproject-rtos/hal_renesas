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
#define R_BSP_MODULE_CLKON(ip, channel)          {FSP_CRITICAL_SECTION_DEFINE;                                       \
                                                  FSP_CRITICAL_SECTION_ENTER;                                        \
                                                  BSP_CLKON_REG_ ## ip(channel) = 0x00000000U                        \
                                                                                  | (BSP_CLKON_BIT_ ## ip(channel)   \
                                                                                     <<                              \
                                                                                     16U)                            \
                                                                                  | (BSP_CLKON_BIT_ ## ip(channel)); \
                                                  while ((BSP_CLKMON_REG_ ## ip(channel) &                           \
                                                          BSP_CLKMON_BIT_ ## ip(channel)) == 0U)                     \
                                                  { /* wait */};                                                     \
                                                  FSP_CRITICAL_SECTION_EXIT;}

/***********************************************************************************************************************
 * Stop clock supply
 *
 * @param      ip       fsp_ip_t enum value for the unit to stop clock.
 * @param      channel  The channel. Use ch 0 for units without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_CLKOFF(ip, channel)         {FSP_CRITICAL_SECTION_DEFINE;                                     \
                                                  FSP_CRITICAL_SECTION_ENTER;                                      \
                                                  BSP_CLKON_REG_ ## ip(channel) = 0x00000000U                      \
                                                                                  | (BSP_CLKON_BIT_ ## ip(channel) \
                                                                                     <<                            \
                                                                                     16U);                         \
                                                  while ((BSP_CLKMON_REG_ ## ip(channel) &                         \
                                                          BSP_CLKMON_BIT_ ## ip(channel)) != 0U)                   \
                                                  { /* wait */};                                                   \
                                                  FSP_CRITICAL_SECTION_EXIT;}

/***********************************************************************************************************************
 * Reset assertion
 *
 * @param      ip       fsp_ip_t enum value for the unit to be reset.
 * @param      channel  The channel. Use ch 0 for units without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_RSTON(ip, channel)          {FSP_CRITICAL_SECTION_DEFINE;                                    \
                                                  FSP_CRITICAL_SECTION_ENTER;                                     \
                                                  BSP_RST_REG_ ## ip(channel) = 0x00000000U                       \
                                                                                | (BSP_RST_BIT_ ## ip(channel) << \
                                                                                   16U);                          \
                                                  FSP_CRITICAL_SECTION_EXIT;}

/***********************************************************************************************************************
 * Reset deassertion
 *
 * @param      ip       fsp_ip_t enum value for the unit to release from reset state.
 * @param      channel  The channel. Use ch 0 for units without channels. Only single bit can be set.
 **********************************************************************************************************************/
#define R_BSP_MODULE_RSTOFF(ip, channel)         {FSP_CRITICAL_SECTION_DEFINE;                                    \
                                                  FSP_CRITICAL_SECTION_ENTER;                                     \
                                                  BSP_RST_REG_ ## ip(channel) = 0x00000000U                       \
                                                                                | (BSP_RST_BIT_ ## ip(channel) << \
                                                                                   16U)                           \
                                                                                | (BSP_RST_BIT_ ## ip(channel));  \
                                                  while ((BSP_RSTMON_REG_ ## ip(channel) &                        \
                                                          BSP_RSTMON_BIT_ ## ip(channel)) != 0U)                  \
                                                  { /* wait */};                                                  \
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
#ifndef BSP_CLKON_REG_FSP_IP_GPT
 #define BSP_CLKON_REG_FSP_IP_GPT(channel)       (R_CPG->CPG_CLKON_GPT)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_GPT
 #define BSP_CLKON_BIT_FSP_IP_GPT(channel)       (1U << (R_CPG_CPG_CLKON_GPT_CLK0_ON_Pos + (channel / 8)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_GPT
 #define BSP_CLKMON_REG_FSP_IP_GPT(channel)      (R_CPG->CPG_CLKMON_GPT)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_GPT
 #define BSP_CLKMON_BIT_FSP_IP_GPT(channel)      (1U << (R_CPG_CPG_CLKMON_GPT_CLK0_MON_Pos + (channel / 8)))
#endif

#ifndef BSP_RST_REG_FSP_IP_GPT
 #define BSP_RST_REG_FSP_IP_GPT(channel)         (R_CPG->CPG_RST_GPT)
#endif
#ifndef BSP_RST_BIT_FSP_IP_GPT
 #define BSP_RST_BIT_FSP_IP_GPT(channel)         (1U << (R_CPG_CPG_RST_GPT_UNIT0_RSTB_Pos + (channel / 8)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_GPT
 #define BSP_RSTMON_REG_FSP_IP_GPT(channel)      (R_CPG->CPG_RSTMON_GPT)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_GPT
 #define BSP_RSTMON_BIT_FSP_IP_GPT(channel)      (1U << (R_CPG_CPG_RSTMON_GPT_RST0_MON_Pos + (channel / 8)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control POEG clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_POEG
 #define BSP_CLKON_REG_FSP_IP_POEG(channel)      (R_CPG->CPG_CLKON_POEG)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_POEG
 #define BSP_CLKON_BIT_FSP_IP_POEG(channel)      (1U << (R_CPG_CPG_CLKON_POEG_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_POEG
 #define BSP_CLKMON_REG_FSP_IP_POEG(channel)     (R_CPG->CPG_CLKMON_POEG)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_POEG
 #define BSP_CLKMON_BIT_FSP_IP_POEG(channel)     (1U << (R_CPG_CPG_CLKMON_POEG_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_POEG
 #define BSP_RST_REG_FSP_IP_POEG(channel)        (R_CPG->CPG_RST_POEG)
#endif
#ifndef BSP_RST_BIT_FSP_IP_POEG
 #define BSP_RST_BIT_FSP_IP_POEG(channel)        (1U << (R_CPG_CPG_RST_POEG_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_POEG
 #define BSP_RSTMON_REG_FSP_IP_POEG(channel)     (R_CPG->CPG_RSTMON_POEG)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_POEG
 #define BSP_RSTMON_BIT_FSP_IP_POEG(channel)     (1U << (R_CPG_CPG_RSTMON_POEG_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control PORT clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_PORT
 #define BSP_CLKON_REG_FSP_IP_PORT(channel)      (R_CPG->CPG_CLKON_GPIO)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_PORT
 #define BSP_CLKON_BIT_FSP_IP_PORT(channel)      (1U << (R_CPG_CPG_CLKON_GPIO_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_PORT
 #define BSP_CLKMON_REG_FSP_IP_PORT(channel)     (R_CPG->CPG_CLKMON_GPIO)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_PORT
 #define BSP_CLKMON_BIT_FSP_IP_PORT(channel)     (1U << (R_CPG_CPG_CLKMON_GPIO_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_PORT
 #define BSP_RST_REG_FSP_IP_PORT(channel)        (R_CPG->CPG_RST_GPIO)
#endif
#ifndef BSP_RST_BIT_FSP_IP_PORT
 #define BSP_RST_BIT_FSP_IP_PORT(channel)        (1U << (R_CPG_CPG_RST_GPIO_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_PORT
 #define BSP_RSTMON_REG_FSP_IP_PORT(channel)     (R_CPG->CPG_RSTMON_GPIO)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_PORT
 #define BSP_RSTMON_BIT_FSP_IP_PORT(channel)     (1U << (R_CPG_CPG_RSTMON_GPIO_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control IM33 clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_IM33
 #define BSP_CLKON_REG_FSP_IP_IM33(channel)      (R_CPG->CPG_CLKON_IM33)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_IM33
 #define BSP_CLKON_BIT_FSP_IP_IM33(channel)      (1U << (R_CPG_CPG_CLKON_IM33_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_IM33
 #define BSP_CLKMON_REG_FSP_IP_IM33(channel)     (R_CPG->CPG_CLKMON_IM33)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_IM33
 #define BSP_CLKMON_BIT_FSP_IP_IM33(channel)     (1U << (R_CPG_CPG_CLKMON_IM33_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_IM33
 #define BSP_RST_REG_FSP_IP_IM33(channel)        (R_CPG->CPG_RST_IM33)
#endif
#ifndef BSP_RST_BIT_FSP_IP_IM33
 #define BSP_RST_BIT_FSP_IP_IM33(channel)        (1U << (R_CPG_CPG_RST_IM33_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_IM33
 #define BSP_RSTMON_REG_FSP_IP_IM33(channel)     (R_CPG->CPG_RSTMON_IM33)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_IM33
 #define BSP_RSTMON_BIT_FSP_IP_IM33(channel)     (1U << (R_CPG_CPG_RSTMON_IM33_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control SCIF clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_SCIF
 #define BSP_CLKON_REG_FSP_IP_SCIF(channel)      (R_CPG->CPG_CLKON_SCIF)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_SCIF
 #define BSP_CLKON_BIT_FSP_IP_SCIF(channel)      (1U << (R_CPG_CPG_CLKON_SCIF_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_SCIF
 #define BSP_CLKMON_REG_FSP_IP_SCIF(channel)     (R_CPG->CPG_CLKMON_SCIF)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_SCIF
 #define BSP_CLKMON_BIT_FSP_IP_SCIF(channel)     (1U << (R_CPG_CPG_CLKMON_SCIF_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_SCIF
 #define BSP_RST_REG_FSP_IP_SCIF(channel)        (R_CPG->CPG_RST_SCIF)
#endif
#ifndef BSP_RST_BIT_FSP_IP_SCIF
 #define BSP_RST_BIT_FSP_IP_SCIF(channel)        (1U << (R_CPG_CPG_RST_SCIF_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_SCIF
 #define BSP_RSTMON_REG_FSP_IP_SCIF(channel)     (R_CPG->CPG_RSTMON_SCIF)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_SCIF
 #define BSP_RSTMON_BIT_FSP_IP_SCIF(channel)     (1U << (R_CPG_CPG_RSTMON_SCIF_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control RIIC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_RIIC
 #define BSP_CLKON_REG_FSP_IP_RIIC(channel)      (R_CPG->CPG_CLKON_I2C)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_RIIC
 #define BSP_CLKON_BIT_FSP_IP_RIIC(channel)      (1U << (R_CPG_CPG_CLKON_I2C_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_RIIC
 #define BSP_CLKMON_REG_FSP_IP_RIIC(channel)     (R_CPG->CPG_CLKMON_I2C)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_RIIC
 #define BSP_CLKMON_BIT_FSP_IP_RIIC(channel)     (1U << (R_CPG_CPG_CLKMON_I2C_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_RIIC
 #define BSP_RST_REG_FSP_IP_RIIC(channel)        (R_CPG->CPG_RST_I2C)
#endif
#ifndef BSP_RST_BIT_FSP_IP_RIIC
 #define BSP_RST_BIT_FSP_IP_RIIC(channel)        (1U << (R_CPG_CPG_RST_I2C_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_RIIC
 #define BSP_RSTMON_REG_FSP_IP_RIIC(channel)     (R_CPG->CPG_RSTMON_I2C)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_RIIC
 #define BSP_RSTMON_BIT_FSP_IP_RIIC(channel)     (1U << (R_CPG_CPG_RSTMON_I2C_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control RSPI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_RSPI
 #define BSP_CLKON_REG_FSP_IP_RSPI(channel)      (R_CPG->CPG_CLKON_RSPI)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_RSPI
 #define BSP_CLKON_BIT_FSP_IP_RSPI(channel)      (1U << (R_CPG_CPG_CLKON_RSPI_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_RSPI
 #define BSP_CLKMON_REG_FSP_IP_RSPI(channel)     (R_CPG->CPG_CLKMON_RSPI)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_RSPI
 #define BSP_CLKMON_BIT_FSP_IP_RSPI(channel)     (1U << (R_CPG_CPG_CLKMON_RSPI_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_RSPI
 #define BSP_RST_REG_FSP_IP_RSPI(channel)        (R_CPG->CPG_RST_RSPI)
#endif
#ifndef BSP_RST_BIT_FSP_IP_RSPI
 #define BSP_RST_BIT_FSP_IP_RSPI(channel)        (1U << (R_CPG_CPG_RST_RSPI_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_RSPI
 #define BSP_RSTMON_REG_FSP_IP_RSPI(channel)     (R_CPG->CPG_RSTMON_RSPI)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_RSPI
 #define BSP_RSTMON_BIT_FSP_IP_RSPI(channel)     (1U << (R_CPG_CPG_RSTMON_RSPI_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control MHU clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_MHU
 #define BSP_CLKON_REG_FSP_IP_MHU(channel)       (R_CPG->CPG_CLKON_MHU)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_MHU
 #define BSP_CLKON_BIT_FSP_IP_MHU(channel)       (1U << (R_CPG_CPG_CLKON_MHU_CLK0_ON_Pos))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_MHU
 #define BSP_CLKMON_REG_FSP_IP_MHU(channel)      (R_CPG->CPG_CLKMON_MHU)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_MHU
 #define BSP_CLKMON_BIT_FSP_IP_MHU(channel)      (1U << (R_CPG_CPG_CLKMON_MHU_CLK0_MON_Pos))
#endif

#ifndef BSP_RST_REG_FSP_IP_MHU
 #define BSP_RST_REG_FSP_IP_MHU(channel)         (R_CPG->CPG_RST_MHU)
#endif
#ifndef BSP_RST_BIT_FSP_IP_MHU
 #define BSP_RST_BIT_FSP_IP_MHU(channel)         (1U << (R_CPG_CPG_RST_MHU_UNIT0_RSTB_Pos))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_MHU
 #define BSP_RSTMON_REG_FSP_IP_MHU(channel)      (R_CPG->CPG_RSTMON_MHU)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_MHU
 #define BSP_RSTMON_BIT_FSP_IP_MHU(channel)      (1U << (R_CPG_CPG_RSTMON_MHU_RST0_MON_Pos))
#endif

/***********************************************************************************************************************
 * Definition of macros to control DMAC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_DMAC
 #define BSP_CLKON_REG_FSP_IP_DMAC(channel)      (R_CPG->CPG_CLKON_DMAC_REG)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_DMAC
 #define BSP_CLKON_BIT_FSP_IP_DMAC(channel)      (3U << (R_CPG_CPG_CLKON_DMAC_REG_CLK0_ON_Pos))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_DMAC
 #define BSP_CLKMON_REG_FSP_IP_DMAC(channel)     (R_CPG->CPG_CLKMON_DMAC_REG)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_DMAC
 #define BSP_CLKMON_BIT_FSP_IP_DMAC(channel)     (3U << (R_CPG_CPG_CLKMON_DMAC_REG_CLK0_MON_Pos))
#endif

#ifndef BSP_RST_REG_FSP_IP_DMAC
 #define BSP_RST_REG_FSP_IP_DMAC(channel)        (R_CPG->CPG_RST_DMAC)
#endif
#ifndef BSP_RST_BIT_FSP_IP_DMAC
 #define BSP_RST_BIT_FSP_IP_DMAC(channel)        (3U << (R_CPG_CPG_RST_DMAC_UNIT0_RSTB_Pos))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_DMAC
 #define BSP_RSTMON_REG_FSP_IP_DMAC(channel)     (R_CPG->CPG_RSTMON_DMAC)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_DMAC
 #define BSP_RSTMON_BIT_FSP_IP_DMAC(channel)     (3U << (R_CPG_CPG_RSTMON_DMAC_RST0_MON_Pos))
#endif

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
#ifndef BSP_CLKON_REG_FSP_IP_SSI
 #define BSP_CLKON_REG_FSP_IP_SSI(channel)       (R_CPG->CPG_CLKON_SSIF)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_SSI
 #define BSP_CLKON_BIT_FSP_IP_SSI(channel)       (1U << (R_CPG_CPG_CLKON_SSIF_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_SSI
 #define BSP_CLKMON_REG_FSP_IP_SSI(channel)      (R_CPG->CPG_CLKMON_SSIF)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_SSI
 #define BSP_CLKMON_BIT_FSP_IP_SSI(channel)      (1U << (R_CPG_CPG_CLKMON_SSIF_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_SSI
 #define BSP_RST_REG_FSP_IP_SSI(channel)         (R_CPG->CPG_RST_SSIF)
#endif
#ifndef BSP_RST_BIT_FSP_IP_SSI
 #define BSP_RST_BIT_FSP_IP_SSI(channel)         (1U << (R_CPG_CPG_RST_SSIF_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_SSI
 #define BSP_RSTMON_REG_FSP_IP_SSI(channel)      (R_CPG->CPG_RSTMON_SSIF)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_SSI
 #define BSP_RSTMON_BIT_FSP_IP_SSI(channel)      (1U << (R_CPG_CPG_RSTMON_SSIF_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control CANFD clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_CANFD
 #define BSP_CLKON_REG_FSP_IP_CANFD(channel)     (R_CPG->CPG_CLKON_CANFD)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_CANFD
 #define BSP_CLKON_BIT_FSP_IP_CANFD(channel)     (1U << (R_CPG_CPG_CLKON_CANFD_CLK0_ON_Pos))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_CANFD
 #define BSP_CLKMON_REG_FSP_IP_CANFD(channel)    (R_CPG->CPG_CLKMON_CANFD)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_CANFD
 #define BSP_CLKMON_BIT_FSP_IP_CANFD(channel)    (1U << (R_CPG_CPG_CLKMON_CANFD_CLK0_MON_Pos))
#endif

#ifndef BSP_RST_REG_FSP_IP_CANFD
 #define BSP_RST_REG_FSP_IP_CANFD(channel)       (R_CPG->CPG_RST_CANFD)
#endif
#ifndef BSP_RST_BIT_FSP_IP_CANFD
 #define BSP_RST_BIT_FSP_IP_CANFD(channel)       (3U << (R_CPG_CPG_RST_CANFD_UNIT0_RSTB_Pos))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_CANFD
 #define BSP_RSTMON_REG_FSP_IP_CANFD(channel)    (R_CPG->CPG_RSTMON_CANFD)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_CANFD
 #define BSP_RSTMON_BIT_FSP_IP_CANFD(channel)    (3U << (R_CPG_CPG_RSTMON_CANFD_RST0_MON_Pos))
#endif

/***********************************************************************************************************************
 * Definition of macros to control ADC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_ADC
 #define BSP_CLKON_REG_FSP_IP_ADC(channel)       (R_CPG->CPG_CLKON_ADC)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_ADC
 #define BSP_CLKON_BIT_FSP_IP_ADC(channel)       (3U << R_CPG_CPG_CLKON_ADC_CLK0_ON_Pos)
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_ADC
 #define BSP_CLKMON_REG_FSP_IP_ADC(channel)      (R_CPG->CPG_CLKMON_ADC)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_ADC
 #define BSP_CLKMON_BIT_FSP_IP_ADC(channel)      (3U << R_CPG_CPG_CLKMON_ADC_CLK0_MON_Pos)
#endif

#ifndef BSP_RST_REG_FSP_IP_ADC
 #define BSP_RST_REG_FSP_IP_ADC(channel)         (R_CPG->CPG_RST_ADC)
#endif
#ifndef BSP_RST_BIT_FSP_IP_ADC
 #define BSP_RST_BIT_FSP_IP_ADC(channel)         (3U << R_CPG_CPG_RST_ADC_UNIT0_RSTB_Pos)
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_ADC
 #define BSP_RSTMON_REG_FSP_IP_ADC(channel)      (R_CPG->CPG_RSTMON_ADC)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_ADC
 #define BSP_RSTMON_BIT_FSP_IP_ADC(channel)      (3U << R_CPG_CPG_RSTMON_ADC_RST0_MON_Pos)
#endif

/***********************************************************************************************************************
 * Definition of macros to control TSU clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_TSU
 #define BSP_CLKON_REG_FSP_IP_TSU(channel)       (R_CPG->CPG_CLKON_TSU)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_TSU
 #define BSP_CLKON_BIT_FSP_IP_TSU(channel)       (1U << (R_CPG_CPG_CLKON_TSU_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_TSU
 #define BSP_CLKMON_REG_FSP_IP_TSU(channel)      (R_CPG->CPG_CLKMON_TSU)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_TSU
 #define BSP_CLKMON_BIT_FSP_IP_TSU(channel)      (1U << (R_CPG_CPG_CLKMON_TSU_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_TSU
 #define BSP_RST_REG_FSP_IP_TSU(channel)         (R_CPG->CPG_RST_TSU)
#endif
#ifndef BSP_RST_BIT_FSP_IP_TSU
 #define BSP_RST_BIT_FSP_IP_TSU(channel)         (1U << (R_CPG_CPG_RST_TSU_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_TSU
 #define BSP_RSTMON_REG_FSP_IP_TSU(channel)      (R_CPG->CPG_RSTMON_TSU)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_TSU
 #define BSP_RSTMON_BIT_FSP_IP_TSU(channel)      (1U << (R_CPG_CPG_RSTMON_TSU_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control WDT clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_WDT
 #define BSP_CLKON_REG_FSP_IP_WDT(channel)       (R_CPG->CPG_CLKON_WDT)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_WDT
 #define BSP_CLKON_BIT_FSP_IP_WDT(channel)       (3U << (R_CPG_CPG_CLKON_WDT_CLK0_ON_Pos + 2U * (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_WDT
 #define BSP_CLKMON_REG_FSP_IP_WDT(channel)      (R_CPG->CPG_CLKMON_WDT)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_WDT
 #define BSP_CLKMON_BIT_FSP_IP_WDT(channel)      (3U << (R_CPG_CPG_CLKMON_WDT_CLK0_MON_Pos + 2U * (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_WDT
 #define BSP_RST_REG_FSP_IP_WDT(channel)         (R_CPG->CPG_RST_WDT)
#endif
#ifndef BSP_RST_BIT_FSP_IP_WDT
 #define BSP_RST_BIT_FSP_IP_WDT(channel)         (1U << (R_CPG_CPG_RST_WDT_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_WDT
 #define BSP_RSTMON_REG_FSP_IP_WDT(channel)      (R_CPG->CPG_RSTMON_WDT)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_WDT
 #define BSP_RSTMON_BIT_FSP_IP_WDT(channel)      (1U << (R_CPG_CPG_RSTMON_WDT_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control SCI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#ifndef BSP_CLKON_REG_FSP_IP_SCI
 #define BSP_CLKON_REG_FSP_IP_SCI(channel)       (R_CPG->CPG_CLKON_SCI)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_SCI
 #define BSP_CLKON_BIT_FSP_IP_SCI(channel)       (1U << (R_CPG_CPG_CLKON_SCI_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_SCI
 #define BSP_CLKMON_REG_FSP_IP_SCI(channel)      (R_CPG->CPG_CLKMON_SCI)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_SCI
 #define BSP_CLKMON_BIT_FSP_IP_SCI(channel)      (1U << (R_CPG_CPG_CLKMON_SCI_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_SCI
 #define BSP_RST_REG_FSP_IP_SCI(channel)         (R_CPG->CPG_RST_SCI)
#endif
#ifndef BSP_RST_BIT_FSP_IP_SCI
 #define BSP_RST_BIT_FSP_IP_SCI(channel)         (1U << (R_CPG_CPG_RST_SCI_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_SCI
 #define BSP_RSTMON_REG_FSP_IP_SCI(channel)      (R_CPG->CPG_RSTMON_SCI)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_SCI
 #define BSP_RSTMON_BIT_FSP_IP_SCI(channel)      (1U << (R_CPG_CPG_RSTMON_SCI_RST0_MON_Pos + (channel)))
#endif

/***********************************************************************************************************************
 * Definition of macros to control MTU3 clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
#define BSP_CLKON_REG_FSP_IP_MTU3(channel)       (R_CPG->CPG_CLKON_MTU)
#define BSP_CLKON_BIT_FSP_IP_MTU3(channel)       (1U << (R_CPG_CPG_CLKON_MTU_CLK0_ON_Pos))

#define BSP_CLKMON_REG_FSP_IP_MTU3(channel)      (R_CPG->CPG_CLKMON_MTU)
#define BSP_CLKMON_BIT_FSP_IP_MTU3(channel)      (1U << (R_CPG_CPG_CLKMON_MTU_CLK0_MON_Pos))

#define BSP_RST_REG_FSP_IP_MTU3(channel)         (R_CPG->CPG_RST_MTU)
#define BSP_RST_BIT_FSP_IP_MTU3(channel)         (1U << (R_CPG_CPG_RST_MTU_UNIT0_RSTB_Pos))

#define BSP_RSTMON_REG_FSP_IP_MTU3(channel)      (R_CPG->CPG_RSTMON_MTU)
#define BSP_RSTMON_BIT_FSP_IP_MTU3(channel)      (1U << (R_CPG_CPG_RSTMON_MTU_RST0_MON_Pos))

/***********************************************************************************************************************
 *
 * @param      ch  Dummy parameter.
 **********************************************************************************************************************/
#define BSP_CLKON_REG_BSP_CLK_RTC(ch)            (R_CPG->CPG_CLKON_5)

/***********************************************************************************************************************
 *
 * @param      ch  Dummy parameter.
 **********************************************************************************************************************/
#define BSP_CLKON_BIT_BSP_CLK_RTC(ch)            (1U << 3)

/***********************************************************************************************************************
 *
 * @param      ch  Dummy parameter.
 **********************************************************************************************************************/
#define BSP_CLKMON_REG_BSP_CLK_RTC(ch)           (R_CPG->CPG_CLKMON_2)

/***********************************************************************************************************************
 *
 * @param      ch  Dummy parameter.
 **********************************************************************************************************************/
#define BSP_CLKMON_BIT_BSP_CLK_RTC(ch)           (1U << 19)

/***********************************************************************************************************************
 *
 * @param      ch  Dummy parameter.
 **********************************************************************************************************************/
#define BSP_RST_REG_BSP_CLK_RTC(ch)              (R_CPG->CPG_RST_7)

/***********************************************************************************************************************
 *
 * @param      ch  Dummy parameter.
 **********************************************************************************************************************/
#define BSP_RST_BIT_BSP_CLK_RTC(ch)              ((1U << 9) | (1U << 10))

/***********************************************************************************************************************
 *
 * @param      ch  Dummy parameter.
 **********************************************************************************************************************/
#define BSP_RSTMON_REG_BSP_CLK_RTC(ch)           (R_CPG->CPG_RSTMON_3)

/***********************************************************************************************************************
 *
 * @param      ch  Dummy parameter.
 **********************************************************************************************************************/
#define BSP_RSTMON_BIT_BSP_CLK_RTC(ch)           ((1U << 10) | (1U << 11))

/***********************************************************************************************************************
 * RZ/V2H Clock macros
 **********************************************************************************************************************/

/* CPG_CDDIV0.DIVCTL0(PLLCM33_CST400) SET options. */
#define BSP_CLOCKS_PLLCM33_CST400_DIV_2                                   (0)  // Divide PLLCM33_CST400 source clock by 2
#define BSP_CLOCKS_PLLCM33_CST400_DIV_4                                   (1)  // Divide PLLCM33_CST400 source clock by 4
#define BSP_CLOCKS_PLLCM33_CST400_DIV_8                                   (2)  // Divide PLLCM33_CST400 source clock by 8
#define BSP_CLOCKS_PLLCM33_CST400_DIV_16                                  (3)  // Divide PLLCM33_CST400 source clock by 16
#define BSP_CLOCKS_PLLCM33_CST400_DIV_64                                  (4)  // Divide PLLCM33_CST400 source clock by 64

/* CPG_CDDIV0.DIVCTL1(PLLCM33) SET options. */
#define BSP_CLOCKS_PLLCM33_DIV_2                                          (0)  // Divide PLLCM33 source clock by 2
#define BSP_CLOCKS_PLLCM33_DIV_4                                          (1)  // Divide PLLCM33 source clock by 4
#define BSP_CLOCKS_PLLCM33_DIV_8                                          (2)  // Divide PLLCM33 source clock by 8
#define BSP_CLOCKS_PLLCM33_DIV_16                                         (3)  // Divide PLLCM33 source clock by 16
#define BSP_CLOCKS_PLLCM33_DIV_64                                         (4)  // Divide PLLCM33 source clock by 64

/* CPG_CDDIV0.DIVCTL2(PLLDTY_ACPU) SET options. */
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_2                                      (0)  // Divide PLLDTY_ACPU source clock by 2
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_4                                      (1)  // Divide PLLDTY_ACPU source clock by 4
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_8                                      (2)  // Divide PLLDTY_ACPU source clock by 8
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_16                                     (3)  // Divide PLLDTY_ACPU source clock by 16
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_64                                     (4)  // Divide PLLDTY_ACPU source clock by 64

/* CPG_CDDIV0.DIVCTL3(PLLCA55_SCLK) SET options. */
#define BSP_CLOCKS_PLLCA55_SCLK_DIV_1                                     (0)  // Divide PLLCA55_SCLK source clock by 1
#define BSP_CLOCKS_PLLCA55_SCLK_DIV_2                                     (1)  // Divide PLLCA55_SCLK source clock by 2
#define BSP_CLOCKS_PLLCA55_SCLK_DIV_4                                     (2)  // Divide PLLCA55_SCLK source clock by 4
#define BSP_CLOCKS_PLLCA55_SCLK_DIV_8                                     (3)  // Divide PLLCA55_SCLK source clock by 8

/* CPG_CDDIV1.DIVCTL0(CLK1800_PLLCA55_CA55_0) SET options. */
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_0_DIV_1                           (0)  // Divide CLK1800_PLLCA55_CA55_0 source clock by 1
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_0_DIV_2                           (1)  // Divide CLK1800_PLLCA55_CA55_0 source clock by 2
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_0_DIV_4                           (2)  // Divide CLK1800_PLLCA55_CA55_0 source clock by 4
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_0_DIV_8                           (3)  // Divide CLK1800_PLLCA55_CA55_0 source clock by 8

/* CPG_CDDIV1.DIVCTL1(CLK1800_PLLCA55_CA55_1) SET options. */
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_1_DIV_1                           (0)  // Divide CLK1800_PLLCA55_CA55_1 source clock by 1
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_1_DIV_2                           (1)  // Divide CLK1800_PLLCA55_CA55_1 source clock by 2
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_1_DIV_4                           (2)  // Divide CLK1800_PLLCA55_CA55_1 source clock by 4
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_1_DIV_8                           (3)  // Divide CLK1800_PLLCA55_CA55_1 source clock by 8

/* CPG_CDDIV1.DIVCTL2(CLK1800_PLLCA55_CA55_2) SET options. */
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_2_DIV_1                           (0)  // Divide CLK1800_PLLCA55_CA55_2 source clock by 1
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_2_DIV_2                           (1)  // Divide CLK1800_PLLCA55_CA55_2 source clock by 2
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_2_DIV_4                           (2)  // Divide CLK1800_PLLCA55_CA55_2 source clock by 4
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_2_DIV_8                           (3)  // Divide CLK1800_PLLCA55_CA55_2 source clock by 8

/* CPG_CDDIV1.DIVCTL3(CLK1800_PLLCA55_CA55_3) SET options. */
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_3_DIV_1                           (0)  // Divide CLK1800_PLLCA55_CA55_3 source clock by 1
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_3_DIV_2                           (1)  // Divide CLK1800_PLLCA55_CA55_3 source clock by 2
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_3_DIV_4                           (2)  // Divide CLK1800_PLLCA55_CA55_3 source clock by 4
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_3_DIV_8                           (3)  // Divide CLK1800_PLLCA55_CA55_3 source clock by 8

/* CPG_CDDIV2.DIVCTL0(CA55PERI) SET options. */
#define BSP_CLOCKS_PLLCA55PERI_DIV_2                                      (0)  // Divide PLLCA55PERI source clock by 2
#define BSP_CLOCKS_PLLCA55PERI_DIV_4                                      (1)  // Divide PLLCA55PERI source clock by 4
#define BSP_CLOCKS_PLLCA55PERI_DIV_8                                      (2)  // Divide PLLCA55PERI source clock by 8
#define BSP_CLOCKS_PLLCA55PERI_DIV_16                                     (3)  // Divide PLLCA55PERI source clock by 16

/* CPG_CDDIV2.DIVCTL1(PLLDTY_CR8) SET options. */
#define BSP_CLOCKS_PLLDTY_CR8_DIV_2                                       (0)  // Divide PLLDTY_CR8 source clock by 2
#define BSP_CLOCKS_PLLDTY_CR8_DIV_4                                       (1)  // Divide PLLDTY_CR8 source clock by 4
#define BSP_CLOCKS_PLLDTY_CR8_DIV_8                                       (2)  // Divide PLLDTY_CR8 source clock by 8
#define BSP_CLOCKS_PLLDTY_CR8_DIV_16                                      (3)  // Divide PLLDTY_CR8 source clock by 16
#define BSP_CLOCKS_PLLDTY_CR8_DIV_64                                      (4)  // Divide PLLDTY_CR8 source clock by 64

/* CPG_CDDIV2.DIVCTL2(PLLDTY_DRP) SET options. */
#define BSP_CLOCKS_PLLDTY_DRP_DIV_2                                       (0)  // Divide PLLDTY_DRP source clock by 2
#define BSP_CLOCKS_PLLDTY_DRP_DIV_4                                       (1)  // Divide PLLDTY_DRP source clock by 4
#define BSP_CLOCKS_PLLDTY_DRP_DIV_8                                       (2)  // Divide PLLDTY_DRP source clock by 8
#define BSP_CLOCKS_PLLDTY_DRP_DIV_16                                      (3)  // Divide PLLDTY_DRP source clock by 16
#define BSP_CLOCKS_PLLDTY_DRP_DIV_64                                      (4)  // Divide PLLDTY_DRP source clock by 64

/* CPG_CDDIV2.DIVCTL3(PLLVDO_ISP) SET options. */
#define BSP_CLOCKS_PLLVDO_ISP_DIV_2                                       (0)  // Divide PLLVDO_ISP source clock by 2
#define BSP_CLOCKS_PLLVDO_ISP_DIV_4                                       (1)  // Divide PLLVDO_ISP source clock by 4
#define BSP_CLOCKS_PLLVDO_ISP_DIV_8                                       (2)  // Divide PLLVDO_ISP source clock by 8
#define BSP_CLOCKS_PLLVDO_ISP_DIV_16                                      (3)  // Divide PLLVDO_ISP source clock by 16
#define BSP_CLOCKS_PLLVDO_ISP_DIV_64                                      (4)  // Divide PLLVDO_ISP source clock by 64

/* CPG_CDDIV3.DIVCTL0(PLLVDO_ISU) SET options. */
#define BSP_CLOCKS_PLLVDO_ISU_DIV_2                                       (0)  // Divide PLLVDO_ISU source clock by 2
#define BSP_CLOCKS_PLLVDO_ISU_DIV_4                                       (1)  // Divide PLLVDO_ISU source clock by 4
#define BSP_CLOCKS_PLLVDO_ISU_DIV_8                                       (2)  // Divide PLLVDO_ISU source clock by 8
#define BSP_CLOCKS_PLLVDO_ISU_DIV_16                                      (3)  // Divide PLLVDO_ISU source clock by 16
#define BSP_CLOCKS_PLLVDO_ISU_DIV_64                                      (4)  // Divide PLLVDO_ISU source clock by 64

/* CPG_CDDIV3.DIVCTL1(PLLGPU) SET options. */
#define BSP_CLOCKS_PLLGPU_DIV_2                                           (0)  // Divide PLLGPU source clock by 2
#define BSP_CLOCKS_PLLGPU_DIV_4                                           (1)  // Divide PLLGPU source clock by 4
#define BSP_CLOCKS_PLLGPU_DIV_8                                           (2)  // Divide PLLGPU source clock by 8
#define BSP_CLOCKS_PLLGPU_DIV_16                                          (3)  // Divide PLLGPU source clock by 16
#define BSP_CLOCKS_PLLGPU_DIV_64                                          (4)  // Divide PLLGPU source clock by 64

/* CPG_CDDIV3.DIVCTL2(PLLDTY_RCPU) SET options. */
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_2                                      (0)  // Divide PLLDTY_RCPU source clock by 2
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_4                                      (1)  // Divide PLLDTY_RCPU source clock by 4
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_8                                      (2)  // Divide PLLDTY_RCPU source clock by 8
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_16                                     (3)  // Divide PLLDTY_RCPU source clock by 16
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_64                                     (4)  // Divide PLLDTY_RCPU source clock by 64

/* CPG_CDDIV3.DIVCTL3(PLLVDO_CRU0) SET options. */
#define BSP_CLOCKS_PLLVDO_CRU0_DIV_2                                      (0)  // Divide PLLVDO_CRU0 source clock by 2
#define BSP_CLOCKS_PLLVDO_CRU0_DIV_4                                      (1)  // Divide PLLVDO_CRU0 source clock by 4

/* CPG_CDDIV4.DIVCTL0(PLLVDO_CRU1) SET options. */
#define BSP_CLOCKS_PLLVDO_CRU1_DIV_2                                      (0)  // Divide PLLVDO_CRU1 source clock by 2
#define BSP_CLOCKS_PLLVDO_CRU1_DIV_4                                      (1)  // Divide PLLVDO_CRU1 source clock by 4

/* CPG_CDDIV4.DIVCTL1(PLLVDO_CRU2) SET options. */
#define BSP_CLOCKS_PLLVDO_CRU2_DIV_2                                      (0)  // Divide PLLVDO_CRU2 source clock by 2
#define BSP_CLOCKS_PLLVDO_CRU2_DIV_4                                      (1)  // Divide PLLVDO_CRU2 source clock by 4

/* CPG_CDDIV4.DIVCTL2(PLLVDO_CRU3) SET options. */
#define BSP_CLOCKS_PLLVDO_CRU3_DIV_2                                      (0)  // Divide PLLVDO_CRU3 source clock by 2
#define BSP_CLOCKS_PLLVDO_CRU3_DIV_4                                      (1)  // Divide PLLVDO_CRU3 source clock by 4

/* CPG_CSDIV0.DIVCTL0(PLLETH_GBE0) SET options. */
#define BSP_CLOCKS_PLLETH_GBE0_DIV_2                                      (0)  // Divide PLLETH_GBE0 source clock by 2
#define BSP_CLOCKS_PLLETH_GBE0_DIV_10                                     (1)  // Divide PLLETH_GBE0 source clock by 10
#define BSP_CLOCKS_PLLETH_GBE0_DIV_100                                    (2)  // Divide PLLETH_GBE0 source clock by 100

/* CPG_CSDIV0.DIVCTL1(PLLETH_GBE1) SET options. */
#define BSP_CLOCKS_PLLETH_GBE1_DIV_2                                      (0)  // Divide PLLETH_GBE1 source clock by 2
#define BSP_CLOCKS_PLLETH_GBE1_DIV_10                                     (1)  // Divide PLLETH_GBE1 source clock by 10
#define BSP_CLOCKS_PLLETH_GBE1_DIV_100                                    (2)  // Divide PLLETH_GBE1 source clock by 100

/* CPG_CSDIV0.DIVCTL2(PLLETH_LPCLK) SET options. */
#define BSP_CLOCKS_PLLETH_LPCLK_DIV_16                                    (0)  // Divide PLLETH_LPCLK source clock by 16
#define BSP_CLOCKS_PLLETH_LPCLK_DIV_32                                    (1)  // Divide PLLETH_LPCLK source clock by 32
#define BSP_CLOCKS_PLLETH_LPCLK_DIV_64                                    (2)  // Divide PLLETH_LPCLK source clock by 64
#define BSP_CLOCKS_PLLETH_LPCLK_DIV_128                                   (3)  // Divide PLLETH_LPCLK source clock by 128

/* CPG_CSDIV0.DIVCTL3(PLLCM33_XSPI) SET options. */
#define BSP_CLOCKS_PLLCM33_XSPI_DIV_2                                     (0)  // Divide PLLCM33_XSPI source clock by 2
#define BSP_CLOCKS_PLLCM33_XSPI_DIV_4                                     (1)  // Divide PLLCM33_XSPI source clock by 4
#define BSP_CLOCKS_PLLCM33_XSPI_DIV_8                                     (2)  // Divide PLLCM33_XSPI source clock by 8
#define BSP_CLOCKS_PLLCM33_XSPI_DIV_16                                    (3)  // Divide PLLCM33_XSPI source clock by 16

/* CPG_CSDIV1.DIVCTL0(PLLCM33_ADC_PCLK) SET options. */
#define BSP_CLOCKS_PLLCM33_ADC_PCLK_DIV_8                                 (0)  // Divide PLLCM33_ADC_PCLK source clock by 8
#define BSP_CLOCKS_PLLCM33_ADC_PCLK_DIV_10                                (1)  // Divide PLLCM33_ADC_PCLK source clock by 10

/* CPG_CSDIV1.DIVCTL1(PLLCM33_ADC_ADCLK) SET options. */
#define BSP_CLOCKS_PLLCM33_ADC_ADCLK_DIV_2                                (0)  // Divide PLLCM33_ADC_ADCLK source clock by 2
#define BSP_CLOCKS_PLLCM33_ADC_ADCLK_DIV_4                                (1)  // Divide PLLCM33_ADC_ADCLK source clock by 4
#define BSP_CLOCKS_PLLCM33_ADC_ADCLK_DIV_8                                (2)  // Divide PLLCM33_ADC_ADCLK source clock by 8
#define BSP_CLOCKS_PLLCM33_ADC_ADCLK_DIV_16                               (3)  // Divide PLLCM33_ADC_ADCLK source clock by 16

/* CPG_CSDIV1.DIVCTL2(PLLDSI) SET options. */
#define BSP_CLOCKS_PLLDSI_DIV_2                                           (0)  // Divide PLLDSI source clock by 2
#define BSP_CLOCKS_PLLDSI_DIV_4                                           (1)  // Divide PLLDSI source clock by 4
#define BSP_CLOCKS_PLLDSI_DIV_6                                           (2)  // Divide PLLDSI source clock by 6
#define BSP_CLOCKS_PLLDSI_DIV_8                                           (3)  // Divide PLLDSI source clock by 8
#define BSP_CLOCKS_PLLDSI_DIV_10                                          (4)  // Divide PLLDSI source clock by 10
#define BSP_CLOCKS_PLLDSI_DIV_12                                          (5)  // Divide PLLDSI source clock by 12
#define BSP_CLOCKS_PLLDSI_DIV_14                                          (6)  // Divide PLLDSI source clock by 14
#define BSP_CLOCKS_PLLDSI_DIV_16                                          (7)  // Divide PLLDSI source clock by 16
#define BSP_CLOCKS_PLLDSI_DIV_18                                          (8)  // Divide PLLDSI source clock by 18
#define BSP_CLOCKS_PLLDSI_DIV_20                                          (9)  // Divide PLLDSI source clock by 20
#define BSP_CLOCKS_PLLDSI_DIV_22                                          (10) // Divide PLLDSI source clock by 22
#define BSP_CLOCKS_PLLDSI_DIV_24                                          (11) // Divide PLLDSI source clock by 24
#define BSP_CLOCKS_PLLDSI_DIV_26                                          (12) // Divide PLLDSI source clock by 26
#define BSP_CLOCKS_PLLDSI_DIV_28                                          (13) // Divide PLLDSI source clock by 28
#define BSP_CLOCKS_PLLDSI_DIV_30                                          (14) // Divide PLLDSI source clock by 30
#define BSP_CLOCKS_PLLDSI_DIV_32                                          (15) // Divide PLLDSI source clock by 32

/* CPG_SSEL0.SELCTL0 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL0_SMUX2_CA55_SCLK0            (0)  // Select SMUX_CA55_SCLK0
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL0_PLLCA55                     (1)  // Select PLLCA55

/* CPG_SSEL0.SELCTL1 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLDRP                      (0)  // Select PLLDRP
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLDTY                      (1)  // Select PLLDTY

/* CPG_SSEL0.SELCTL2 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL2_CSDIV_PLLETH_GBE0           (0)  // Select CSDIV_PLLETH_GBE0
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL2_ET0_TXC_TX_CLK              (1)  // Select ET0_TXC_TX_CLK

/* CPG_SSEL0.SELCTL3 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL3_CSDIV_PLLETH_GBE0           (0)  // Select CSDIV_PLLETH_GBE0
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL3_ET0_RXC_RX_CLK              (1)  // Select ET0_RXC_RX_CLK

/* CPG_SSEL1.SELCTL0 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL0_CSDIV_PLLETH_GBE1           (0)  // Select CSDIV_PLLETH_GBE1
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL0_ET1_TXC_TX_CLK              (1)  // Select ET1_TXC_TX_CLK

/* CPG_SSEL1.SELCTL1 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL1_CSDIV_PLLETH_GBE1           (0)  // Select CSDIV_PLLETH_GBE1
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL1_ET1_RXC_RX_CLK              (1)  // Select ET1_RXC_RX_CLK

/* CPG_SSEL1.SELCTL2 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL2_CDIV3_CLK533_PLLCM33_FIX    (0)  // Select CDIV3_CLK533_PLLCM33_FIX
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL2_CDIV4_CLK400_PLLCM33_FIX    (1)  // Select CDIV4_CLK400_PLLCM33_FIX

/* CPG_SSEL1.SELCTL3 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL3_SMUX2_XSPI_CLK0             (0)  // Select SMUX2_XSPI_CLK0
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL3_CDIV5_CLK320_PLLCM33_FIX    (1)  // Select CDIV5_CLK320_PLLCM33_FIX

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
void bsp_clock_init(void);                                                               // Used internally by BSP
void bsp_clock_freq_init_cfg(void);                                                      // Used internally by BSP
void bsp_prv_clock_selector_set(fsp_priv_clock_selector_t selector, uint32_t clock_sel); // Used internally by BSP
void bsp_prv_clock_divider_set(fsp_priv_clock_divider_t divider, uint32_t clock_div);    // Used internally by BSP

#if BSP_TZ_CFG_INIT_SECURE_ONLY
void bsp_clock_freq_var_init(void);                                                      // Used internally by BSP

#endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_CLOCKS_H */
