/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
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
                                                  while ((BSP_RSTMON_REG_ ## ip(channel) &                              \
                                                          BSP_RSTMON_BIT_ ## ip(channel)) == 0U)                        \
                                                  { /* wait */};                                                        \
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
#ifndef BSP_CLKON_REG_FSP_IP_GPT
 #define BSP_CLKON_REG_FSP_IP_GPT(channel)       (R_CPG->CPG_CLKON_GPT)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_GPT
 #define BSP_CLKON_BIT_FSP_IP_GPT(channel)       (1U << (R_CPG_CPG_CLKON_GPT_CLK0_ON_Pos))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_GPT
 #define BSP_CLKMON_REG_FSP_IP_GPT(channel)      (R_CPG->CPG_CLKMON_GPT)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_GPT
 #define BSP_CLKMON_BIT_FSP_IP_GPT(channel)      (1U << (R_CPG_CPG_CLKMON_GPT_CLK0_MON_Pos))
#endif

#ifndef BSP_RST_REG_FSP_IP_GPT
 #define BSP_RST_REG_FSP_IP_GPT(channel)         (R_CPG->CPG_RST_GPT)
#endif
#ifndef BSP_RST_BIT_FSP_IP_GPT
 #define BSP_RST_BIT_FSP_IP_GPT(channel)         (1U << (R_CPG_CPG_RST_GPT_UNIT0_RSTB_Pos))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_GPT
 #define BSP_RSTMON_REG_FSP_IP_GPT(channel)      (R_CPG->CPG_RSTMON_GPT)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_GPT
 #define BSP_RSTMON_BIT_FSP_IP_GPT(channel)      (1U << (R_CPG_CPG_RSTMON_GPT_RST0_MON_Pos))
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
 #define BSP_CLKON_REG_FSP_IP_SSI(channel)       (R_CPG->CPG_CLKON_SSI)
#endif
#ifndef BSP_CLKON_BIT_FSP_IP_SSI
 #define BSP_CLKON_BIT_FSP_IP_SSI(channel)       (1U << (R_CPG_CPG_CLKON_SSI_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_SSI
 #define BSP_CLKMON_REG_FSP_IP_SSI(channel)      (R_CPG->CPG_CLKMON_SSI)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_SSI
 #define BSP_CLKMON_BIT_FSP_IP_SSI(channel)      (1U << (R_CPG_CPG_CLKMON_SSI_CLK0_MON_Pos + (channel)))
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
 #define BSP_CLKON_BIT_FSP_IP_CANFD(channel)     (1U << (R_CPG_CPG_CLKON_CANFD_CLK0_ON_Pos + (channel)))
#endif

#ifndef BSP_CLKMON_REG_FSP_IP_CANFD
 #define BSP_CLKMON_REG_FSP_IP_CANFD(channel)    (R_CPG->CPG_CLKMON_CANFD)
#endif
#ifndef BSP_CLKMON_BIT_FSP_IP_CANFD
 #define BSP_CLKMON_BIT_FSP_IP_CANFD(channel)    (1U << (R_CPG_CPG_CLKMON_CANFD_CLK0_MON_Pos + (channel)))
#endif

#ifndef BSP_RST_REG_FSP_IP_CANFD
 #define BSP_RST_REG_FSP_IP_CANFD(channel)       (R_CPG->CPG_RST_CANFD)
#endif
#ifndef BSP_RST_BIT_FSP_IP_CANFD
 #define BSP_RST_BIT_FSP_IP_CANFD(channel)       (1U << (R_CPG_CPG_RST_CANFD_UNIT0_RSTB_Pos + (channel)))
#endif

#ifndef BSP_RSTMON_REG_FSP_IP_CANFD
 #define BSP_RSTMON_REG_FSP_IP_CANFD(channel)    (R_CPG->CPG_RSTMON_CANFD)
#endif
#ifndef BSP_RSTMON_BIT_FSP_IP_CANFD
 #define BSP_RSTMON_BIT_FSP_IP_CANFD(channel)    (1U << (R_CPG_CPG_RSTMON_CANFD_RST0_MON_Pos + (channel)))
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

/* CPG_PL1_DDIV.DIVPL1_SET options. */
#define BSP_CLOCKS_PL1_DIV_1                                              (0) // Divide ICLK source clock by 1
#define BSP_CLOCKS_PL1_DIV_2                                              (1) // Divide ICLK source clock by 2
#define BSP_CLOCKS_PL1_DIV_4                                              (2) // Divide ICLK source clock by 4
#define BSP_CLOCKS_PL1_DIV_8                                              (3) // Divide ICLK source clock by 8

/* CPG_PL1_DDIV.DIV_PLL1_A_SET options. */
#define BSP_CLOCKS_PLL1_DIV_1                                             (0)  // Divide ICLK source clock by 1
#define BSP_CLOCKS_PLL1_DIV_2                                             (1)  // Divide ICLK source clock by 2
#define BSP_CLOCKS_PLL1_DIV_4                                             (2)  // Divide ICLK source clock by 4
#define BSP_CLOCKS_PLL1_DIV_8                                             (3)  // Divide ICLK source clock by 8
#define BSP_CLOCKS_PLL1_DIV_16                                            (4)  // Divide ICLK source clock by 16
#define BSP_CLOCKS_PLL1_DIV_32                                            (5)  // Divide ICLK source clock by 32

/* CPG_PL2_DDIV.DIVPL2B_SET options. */
#define BSP_CLOCKS_PL2B_DIV_1                                             (0) // Divide P0CLK source clock by 1
#define BSP_CLOCKS_PL2B_DIV_2                                             (1) // Divide P0CLK source clock by 2
#define BSP_CLOCKS_PL2B_DIV_4                                             (2) // Divide P0CLK source clock by 4
#define BSP_CLOCKS_PL2B_DIV_8                                             (3) // Divide P0CLK source clock by 8
#define BSP_CLOCKS_PL2B_DIV_32                                            (4) // Divide P0CLK source clock by 32

/* CPG_PL2_DDIV.DIV_PLL2_A_SET options. */
#define BSP_CLOCKS_PLL2_200_DIV_4                                         (0)  // Divide P3CLK source clock by 4
#define BSP_CLOCKS_PLL2_200_DIV_8                                         (1)  // Divide P3CLK source clock by 8
#define BSP_CLOCKS_PLL2_200_DIV_16                                        (2)  // Divide P3CLK source clock by 16
#define BSP_CLOCKS_PLL2_200_DIV_128                                       (3)  // Divide P3CLK source clock by 128

/* CPG_PL2_DDIV.DIV_PLL2_B_SET options. */
#define BSP_CLOCKS_PLL2_100_DIV_8                                         (0)  // Divide P0CLK source clock by 8
#define BSP_CLOCKS_PLL2_100_DIV_16                                        (1)  // Divide P0CLK source clock by 16
#define BSP_CLOCKS_PLL2_100_DIV_32                                        (2)  // Divide P0CLK source clock by 32
#define BSP_CLOCKS_PLL2_100_DIV_256                                       (3)  // Divide P0CLK source clock by 256

/* CPG_PL2_DDIV.DIV_CLKQSPI_SET options. */
#define BSP_CLOCKS_PLL2_CLKQSPI_DIV_4                                     (0)  // Divide P7CLK source clock by 4
#define BSP_CLOCKS_PLL2_CLKQSPI_DIV_8                                     (1)  // Divide P7CLK source clock by 8
#define BSP_CLOCKS_PLL2_CLKQSPI_DIV_16                                    (2)  // Divide P7CLK source clock by 16
#define BSP_CLOCKS_PLL2_CLKQSPI_DIV_128                                   (3)  // Divide P7CLK source clock by 128

/* CPG_PL3_DDIV.DIVPL3C_SET options. */
#define BSP_CLOCKS_PL3C_DIV_1                                             (0) // Divide SPI0CLK source clock by 1
#define BSP_CLOCKS_PL3C_DIV_2                                             (1) // Divide SPI0CLK source clock by 2
#define BSP_CLOCKS_PL3C_DIV_4                                             (2) // Divide SPI0CLK source clock by 4
#define BSP_CLOCKS_PL3C_DIV_8                                             (3) // Divide SPI0CLK source clock by 8
#define BSP_CLOCKS_PL3C_DIV_32                                            (4) // Divide SPI0CLK source clock by 32

/* CPG_PL3_DDIV.DIVPL3B_SET options. */
#define BSP_CLOCKS_PL3B_DIV_1                                             (0) // Divide P1CLK source clock by 1
#define BSP_CLOCKS_PL3B_DIV_2                                             (1) // Divide P1CLK source clock by 2
#define BSP_CLOCKS_PL3B_DIV_4                                             (2) // Divide P1CLK source clock by 4
#define BSP_CLOCKS_PL3B_DIV_8                                             (3) // Divide P1CLK source clock by 8
#define BSP_CLOCKS_PL3B_DIV_32                                            (4) // Divide P1CLK source clock by 32

/* CPG_PL3_DDIV.DIVPL3A_SET options. */
#define BSP_CLOCKS_PL3A_DIV_1                                             (0) // Divide P2CLK source clock by 1
#define BSP_CLOCKS_PL3A_DIV_2                                             (1) // Divide P2CLK source clock by 2
#define BSP_CLOCKS_PL3A_DIV_4                                             (2) // Divide P2CLK source clock by 4
#define BSP_CLOCKS_PL3A_DIV_8                                             (3) // Divide P2CLK source clock by 8
#define BSP_CLOCKS_PL3A_DIV_32                                            (4) // Divide P2CLK source clock by 32

/* CPG_PL3_DDIV.DIV_PLL3_A_SET options. */
#define BSP_CLOCKS_PLL3_200_DIV_4                                         (0)  // Divide P1CLK source clock by 4
#define BSP_CLOCKS_PLL3_200_DIV_8                                         (1)  // Divide P1CLK source clock by 8
#define BSP_CLOCKS_PLL3_200_DIV_16                                        (2)  // Divide P1CLK source clock by 16
#define BSP_CLOCKS_PLL3_200_DIV_128                                       (3)  // Divide P1CLK source clock by 128

/* CPG_PL3_DDIV.DIV_PLL3_B_SET options. */
#define BSP_CLOCKS_PLL3_100_DIV_8                                         (0)  // Divide P2CLK source clock by 8
#define BSP_CLOCKS_PLL3_100_DIV_16                                        (1)  // Divide P2CLK source clock by 16
#define BSP_CLOCKS_PLL3_100_DIV_32                                        (2)  // Divide P2CLK source clock by 32
#define BSP_CLOCKS_PLL3_100_DIV_256                                       (3)  // Divide P2CLK source clock by 256

/* CPG_PL6_DDIV.DIVPL6B_SET options. */
#define BSP_CLOCKS_PL6B_DIV_1                                             (0) // Divide I3CLK source clock by 1
#define BSP_CLOCKS_PL6B_DIV_2                                             (1) // Divide I3CLK source clock by 2
#define BSP_CLOCKS_PL6B_DIV_4                                             (2) // Divide I3CLK source clock by 4
#define BSP_CLOCKS_PL6B_DIV_8                                             (3) // Divide I3CLK source clock by 8
#define BSP_CLOCKS_PL6B_DIV_32                                            (4) // Divide I3CLK source clock by 32

/* CPG_PL6_DDIV.DIVPL6A_SET options. */
#define BSP_CLOCKS_PL6A_DIV_1                                             (0) // Divide I2CLK source clock by 1
#define BSP_CLOCKS_PL6A_DIV_2                                             (1) // Divide I2CLK source clock by 2
#define BSP_CLOCKS_PL6A_DIV_4                                             (2) // Divide I2CLK source clock by 4
#define BSP_CLOCKS_PL6A_DIV_8                                             (3) // Divide I2CLK source clock by 8
#define BSP_CLOCKS_PL6A_DIV_32                                            (4) // Divide I2CLK source clock by 32

/* CPG_SDHI_DDIV.DIVSDHI2_SET options. */
#define BSP_CLOCKS_SDHI2_DIV_1                                            (0) // Divide SD2CLK source clock by 1
#define BSP_CLOCKS_SDHI2_DIV_2                                            (1) // Divide SD2CLK source clock by 2
#define BSP_CLOCKS_SDHI2_DIV_4                                            (2)  // Divide SD2CLK source clock by 4

/* CPG_SDHI_DDIV.DIVSDHI1_SET options. */
#define BSP_CLOCKS_SDHI1_DIV_1                                            (0) // Divide SD1CLK source clock by 1
#define BSP_CLOCKS_SDHI1_DIV_2                                            (1) // Divide SD1CLK source clock by 2
#define BSP_CLOCKS_SDHI1_DIV_4                                            (2)  // Divide SD1CLK source clock by 4

/* CPG_SDHI_DDIV.DIVSDHI0_SET options. */
#define BSP_CLOCKS_SDHI0_DIV_1                                            (0) // Divide SD0CLK source clock by 1
#define BSP_CLOCKS_SDHI0_DIV_2                                            (1) // Divide SD0CLK source clock by 2
#define BSP_CLOCKS_SDHI0_DIV_4                                            (2)  // Divide SD0CLK source clock by 4

/* CPG_XSPI_DDIV.DIV_XSPI_SET options. */
#define BSP_CLOCKS_XSPI_DIV_2                                             (0)  // Divide SPInCLK source clock by 2
#define BSP_CLOCKS_XSPI_DIV_4                                             (1)  // Divide SPInCLK source clock by 4
#define BSP_CLOCKS_XSPI_DIV_6                                             (2)  // Divide SPInCLK source clock by 6
#define BSP_CLOCKS_XSPI_DIV_8                                             (3)  // Divide SPInCLK source clock by 8
#define BSP_CLOCKS_XSPI_DIV_10                                            (4)  // Divide SPInCLK source clock by 10
#define BSP_CLOCKS_XSPI_DIV_12                                            (5)  // Divide SPInCLK source clock by 12
#define BSP_CLOCKS_XSPI_DIV_14                                            (6)  // Divide SPInCLK source clock by 14
#define BSP_CLOCKS_XSPI_DIV_16                                            (7)  // Divide SPInCLK source clock by 16

/* CPG_GE3D_DDIV.DIV_GE3D_SET options. */
#define BSP_CLOCKS_GE3D_DIV_1                                             (0)  // Divide GCLK source clock by 1
#define BSP_CLOCKS_GE3D_DIV_2                                             (1)  // Divide GCLK source clock by 2
#define BSP_CLOCKS_GE3D_DIV_4                                             (2)  // Divide GCLK source clock by 4
#define BSP_CLOCKS_GE3D_DIV_8                                             (3)  // Divide GCLK source clock by 8
#define BSP_CLOCKS_GE3D_DIV_32                                            (4)  // Divide GCLK source clock by 32

/* CPG_OCTA_DDIV.DIVOCTA_SET options. */
#define BSP_CLOCKS_OCTA_DIV_1                                             (0) // Divide OCCLK source clock by 1
#define BSP_CLOCKS_OCTA_DIV_2                                             (1) // Divide OCCLK source clock by 2
#define BSP_CLOCKS_OCTA_DIV_4                                             (2) // Divide OCCLK source clock by 4
#define BSP_CLOCKS_OCTA_DIV_8                                             (3) // Divide OCCLK source clock by 8
#define BSP_CLOCKS_OCTA_DIV_32                                            (4) // Divide OCCLK source clock by 32

/* CPG_SPI_DDIV.DIVSPI_SET options. */
#define BSP_CLOCKS_SPI_DIV_1                                              (0) // Divide SPICLK source clock by 1
#define BSP_CLOCKS_SPI_DIV_2                                              (1) // Divide SPICLK source clock by 2
#define BSP_CLOCKS_SPI_DIV_4                                              (2) // Divide SPICLK source clock by 4
#define BSP_CLOCKS_SPI_DIV_8                                              (3) // Divide SPICLK source clock by 8
#define BSP_CLOCKS_SPI_DIV_32                                             (4) // Divide SPICLK source clock by 32

/* CPG_DSI_DDIV.DIV_DSI_SET options. */
#define BSP_CLOCKS_CLK266FIXC_DIV16TO128_DIV_16                           (0)  // Divide M1CLK source clock by 16
#define BSP_CLOCKS_CLK266FIXC_DIV16TO128_DIV_32                           (1)  // Divide M1CLK source clock by 32
#define BSP_CLOCKS_CLK266FIXC_DIV16TO128_DIV_64                           (2)  // Divide M1CLK source clock by 64
#define BSP_CLOCKS_CLK266FIXC_DIV16TO128_DIV_128                          (3)  // Divide M1CLK source clock by 128

/* CPG_PDM_DDIV.DIV_PDM_SET options. */
#define BSP_CLOCKS_CLK24_SEL_3                                            (0)  // Divide OSCCLK source clock by 3
#define BSP_CLOCKS_CLK24_SEL_5                                            (1)  // Divide OSCCLK source clock by 5

/* CPG_BSC_DDIV.DIV_BSC_SET options. */
#define BSP_CLOCKS_BSC_DIV_2                                              (0)  // Divide BCLK source clock by 2
#define BSP_CLOCKS_BSC_DIV_4                                              (1)  // Divide BCLK source clock by 4
#define BSP_CLOCKS_BSC_DIV_8                                              (2)  // Divide BCLK source clock by 8
#define BSP_CLOCKS_BSC_DIV_16                                             (3)  // Divide BCLK source clock by 16

/* CPG_CA55CORE_DDIV.DIV_CORE0_SET options. */
#define BSP_CLOCKS_CA55_CORE0_DIV_1                                       (0)  // Divide IC0CLK source clock by 1
#define BSP_CLOCKS_CA55_CORE0_DIV_2                                       (1)  // Divide IC0CLK source clock by 2
#define BSP_CLOCKS_CA55_CORE0_DIV_4                                       (2)  // Divide IC0CLK source clock by 4
#define BSP_CLOCKS_CA55_CORE0_DIV_8                                       (3)  // Divide IC0CLK source clock by 8
#define BSP_CLOCKS_CA55_CORE0_DIV_16                                      (4)  // Divide IC0CLK source clock by 16
#define BSP_CLOCKS_CA55_CORE0_DIV_32                                      (5)  // Divide IC0CLK source clock by 32

/* CPG_CA55CORE_DDIV.DIV_CORE1_SET options. */
#define BSP_CLOCKS_CA55_CORE1_DIV_1                                       (0)  // Divide IC1CLK source clock by 1
#define BSP_CLOCKS_CA55_CORE1_DIV_2                                       (1)  // Divide IC1CLK source clock by 2
#define BSP_CLOCKS_CA55_CORE1_DIV_4                                       (2)  // Divide IC1CLK source clock by 4
#define BSP_CLOCKS_CA55_CORE1_DIV_8                                       (3)  // Divide IC1CLK source clock by 8
#define BSP_CLOCKS_CA55_CORE1_DIV_16                                      (4)  // Divide IC1CLK source clock by 16
#define BSP_CLOCKS_CA55_CORE1_DIV_32                                      (5)  // Divide IC1CLK source clock by 32

/* CPG_CA55CORE_DDIV.DIV_CORE2_SET options. */
#define BSP_CLOCKS_CA55_CORE2_DIV_1                                       (0)  // Divide IC2CLK source clock by 1
#define BSP_CLOCKS_CA55_CORE2_DIV_2                                       (1)  // Divide IC2CLK source clock by 2
#define BSP_CLOCKS_CA55_CORE2_DIV_4                                       (2)  // Divide IC2CLK source clock by 4
#define BSP_CLOCKS_CA55_CORE2_DIV_8                                       (3)  // Divide IC2CLK source clock by 8
#define BSP_CLOCKS_CA55_CORE2_DIV_16                                      (4)  // Divide IC2CLK source clock by 16
#define BSP_CLOCKS_CA55_CORE2_DIV_32                                      (5)  // Divide IC2CLK source clock by 32

/* CPG_CA55CORE_DDIV.DIV_CORE3_SET options. */
#define BSP_CLOCKS_CA55_CORE3_DIV_1                                       (0)  // Divide IC3CLK source clock by 1
#define BSP_CLOCKS_CA55_CORE3_DIV_2                                       (1)  // Divide IC3CLK source clock by 2
#define BSP_CLOCKS_CA55_CORE3_DIV_4                                       (2)  // Divide IC3CLK source clock by 4
#define BSP_CLOCKS_CA55_CORE3_DIV_8                                       (3)  // Divide IC3CLK source clock by 8
#define BSP_CLOCKS_CA55_CORE3_DIV_16                                      (4)  // Divide IC3CLK source clock by 16
#define BSP_CLOCKS_CA55_CORE3_DIV_32                                      (5)  // Divide IC3CLK source clock by 32

/* CPG_RSCI_DDIV.DIV_RSCI0_SET options. */
#define BSP_CLOCKS_RSCI0_DIV_2                                            (0)  // Divide P13CLK source clock by 2
#define BSP_CLOCKS_RSCI0_DIV_4                                            (1)  // Divide P13CLK source clock by 4
#define BSP_CLOCKS_RSCI0_DIV_8                                            (2)  // Divide P13CLK source clock by 8
#define BSP_CLOCKS_RSCI0_DIV_16                                           (3)  // Divide P13CLK source clock by 16

/* CPG_RSCI_DDIV.DIV_RSCI1_SET options. */
#define BSP_CLOCKS_RSCI1_DIV_2                                            (0)  // Divide P14CLK source clock by 2
#define BSP_CLOCKS_RSCI1_DIV_4                                            (1)  // Divide P14CLK source clock by 4
#define BSP_CLOCKS_RSCI1_DIV_8                                            (2)  // Divide P14CLK source clock by 8
#define BSP_CLOCKS_RSCI1_DIV_16                                           (3)  // Divide P14CLK source clock by 16

/* CPG_RSCI_DDIV.DIV_RSCI2_SET options. */
#define BSP_CLOCKS_RSCI2_DIV_2                                            (0)  // Divide P15CLK source clock by 2
#define BSP_CLOCKS_RSCI2_DIV_4                                            (1)  // Divide P15CLK source clock by 4
#define BSP_CLOCKS_RSCI2_DIV_8                                            (2)  // Divide P15CLK source clock by 8
#define BSP_CLOCKS_RSCI2_DIV_16                                           (3)  // Divide P15CLK source clock by 16

/* CPG_RSCI_DDIV.DIV_RSCI3_SET options. */
#define BSP_CLOCKS_RSCI3_DIV_2                                            (0)  // Divide P16CLK source clock by 2
#define BSP_CLOCKS_RSCI3_DIV_4                                            (1)  // Divide P16CLK source clock by 4
#define BSP_CLOCKS_RSCI3_DIV_8                                            (2)  // Divide P16CLK source clock by 8
#define BSP_CLOCKS_RSCI3_DIV_16                                           (3)  // Divide P16CLK source clock by 16

/* CPG_RSPI_DDIV.DIV_RSPI0_SET options. */
#define BSP_CLOCKS_RSPI0_DIV_1                                            (0)  // Divide P17CLK source clock by 1
#define BSP_CLOCKS_RSPI0_DIV_2                                            (1)  // Divide P17CLK source clock by 2
#define BSP_CLOCKS_RSPI0_DIV_4                                            (2)  // Divide P17CLK source clock by 4
#define BSP_CLOCKS_RSPI0_DIV_8                                            (3)  // Divide P17CLK source clock by 8

/* CPG_RSPI_DDIV.DIV_RSPI1_SET options. */
#define BSP_CLOCKS_RSPI1_DIV_1                                            (0)  // Divide P18CLK source clock by 1
#define BSP_CLOCKS_RSPI1_DIV_2                                            (1)  // Divide P18CLK source clock by 2
#define BSP_CLOCKS_RSPI1_DIV_4                                            (2)  // Divide P18CLK source clock by 4
#define BSP_CLOCKS_RSPI1_DIV_8                                            (3)  // Divide P18CLK source clock by 8

/* CPG_RSPI_DDIV.DIV_RSPI2_SET options. */
#define BSP_CLOCKS_RSPI2_DIV_1                                            (0)  // Divide P19CLK source clock by 1
#define BSP_CLOCKS_RSPI2_DIV_2                                            (1)  // Divide P19CLK source clock by 2
#define BSP_CLOCKS_RSPI2_DIV_4                                            (2)  // Divide P19CLK source clock by 4
#define BSP_CLOCKS_RSPI2_DIV_8                                            (3)  // Divide P19CLK source clock by 8

/* CPG_DSI_SDIV.DIV_DSI_A_SET options. */
#define BSP_CLOCKS_DSI_DIV1TO32_VCLK_DIV_1                                (0)  // Divide M3CLK source clock by 1
#define BSP_CLOCKS_DSI_DIV1TO32_VCLK_DIV_2                                (1)  // Divide M3CLK source clock by 2
#define BSP_CLOCKS_DSI_DIV1TO32_VCLK_DIV_4                                (2)  // Divide M3CLK source clock by 4
#define BSP_CLOCKS_DSI_DIV1TO32_VCLK_DIV_8                                (3)  // Divide M3CLK source clock by 8
#define BSP_CLOCKS_DSI_DIV1TO32_VCLK_DIV_16                               (4)  // Divide M3CLK source clock by 16
#define BSP_CLOCKS_DSI_DIV1TO32_VCLK_DIV_32                               (5)  // Divide M3CLK source clock by 32

/* CPG_DSI_SDIV.DIV_DSI_B_SET options. */
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_1                                (0)  // Divide M3CLK source clock by 1
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_2                                (1)  // Divide M3CLK source clock by 2
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_3                                (2)  // Divide M3CLK source clock by 3
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_4                                (3)  // Divide M3CLK source clock by 4
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_5                                (4)  // Divide M3CLK source clock by 5
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_6                                (5)  // Divide M3CLK source clock by 6
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_7                                (6)  // Divide M3CLK source clock by 7
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_8                                (7)  // Divide M3CLK source clock by 8
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_9                                (8)  // Divide M3CLK source clock by 9
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_10                               (9)  // Divide M3CLK source clock by 10
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_11                               (10) // Divide M3CLK source clock by 11
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_12                               (11) // Divide M3CLK source clock by 12
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_13                               (12) // Divide M3CLK source clock by 13
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_14                               (13) // Divide M3CLK source clock by 14
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_15                               (14) // Divide M3CLK source clock by 15
#define BSP_CLOCKS_DSI_DIV1TO16_VCLK_DIV_16                               (15) // Divide M3CLK source clock by 16

/* CPG_DSI_SDIV.DIV_DSI_C_SET options. */
#define BSP_CLOCKS_DSI_DIV1TO2_LVDS_DIV_1                                 (0)  // Divide M2CLK source clock by 1
#define BSP_CLOCKS_DSI_DIV1TO2_LVDS_DIV_2                                 (1)  // Divide M2CLK source clock by 2

/* CPG_ETH_SDIV.DIV_ETH_A_SET options. */
#define BSP_CLOCKS_ETH0_TR_DIV_4                                          (0)  // Divide ETH0_TR source clock by 4
#define BSP_CLOCKS_ETH0_TR_DIV_20                                         (1)  // Divide ETH0_TR source clock by 20
#define BSP_CLOCKS_ETH0_TR_DIV_200                                        (2)  // Divide ETH0_TR source clock by 200

/* CPG_ETH_SDIV.DIV_ETH_B_SET options. */
#define BSP_CLOCKS_ETH0_RM_DIV_2                                          (0)  // Divide ETH0_RM source clock by 2
#define BSP_CLOCKS_ETH0_RM_DIV_20                                         (1)  // Divide ETH0_RM source clock by 20

/* CPG_ETH_SDIV.DIV_ETH_C_SET options. */
#define BSP_CLOCKS_ETH1_TR_DIV_4                                          (0)  // Divide ETH1_TR source clock by 4
#define BSP_CLOCKS_ETH1_TR_DIV_20                                         (1)  // Divide ETH1_TR source clock by 20
#define BSP_CLOCKS_ETH1_TR_DIV_200                                        (2)  // Divide ETH1_TR source clock by 200

/* CPG_ETH_SDIV.DIV_ETH_D_SET options. */
#define BSP_CLOCKS_ETH1_RM_DIV_2                                          (0)  // Divide ETH1_RM source clock by 2
#define BSP_CLOCKS_ETH1_RM_DIV_20                                         (1)  // Divide ETH1_RM source clock by 20

/* CPG_CDDIV0.DIVCTL0(PLLCM33_CST400) SET options. */
#define BSP_CLOCKS_PLLCM33_CST400_DIV_2                                   (0) // Divide PLLCM33_CST400 source clock by 2
#define BSP_CLOCKS_PLLCM33_CST400_DIV_4                                   (1) // Divide PLLCM33_CST400 source clock by 4
#define BSP_CLOCKS_PLLCM33_CST400_DIV_8                                   (2) // Divide PLLCM33_CST400 source clock by 8
#define BSP_CLOCKS_PLLCM33_CST400_DIV_16                                  (3) // Divide PLLCM33_CST400 source clock by 16
#define BSP_CLOCKS_PLLCM33_CST400_DIV_64                                  (4) // Divide PLLCM33_CST400 source clock by 64

/* CPG_CDDIV0.DIVCTL1(PLLCM33) SET options. */
#define BSP_CLOCKS_PLLCM33_DIV_2                                          (0) // Divide PLLCM33 source clock by 2
#define BSP_CLOCKS_PLLCM33_DIV_4                                          (1) // Divide PLLCM33 source clock by 4
#define BSP_CLOCKS_PLLCM33_DIV_8                                          (2) // Divide PLLCM33 source clock by 8
#define BSP_CLOCKS_PLLCM33_DIV_16                                         (3) // Divide PLLCM33 source clock by 16
#define BSP_CLOCKS_PLLCM33_DIV_64                                         (4) // Divide PLLCM33 source clock by 64

/* CPG_CDDIV0.DIVCTL2(PLLDTY_ACPU) SET options. */
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_2                                      (0) // Divide PLLDTY_ACPU source clock by 2
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_4                                      (1) // Divide PLLDTY_ACPU source clock by 4
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_8                                      (2) // Divide PLLDTY_ACPU source clock by 8
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_16                                     (3) // Divide PLLDTY_ACPU source clock by 16
#define BSP_CLOCKS_PLLDTY_ACPU_DIV_64                                     (4) // Divide PLLDTY_ACPU source clock by 64

/* CPG_CDDIV0.DIVCTL3(PLLCA55_SCLK) SET options. */
#define BSP_CLOCKS_PLLCA55_SCLK_DIV_1                                     (0) // Divide PLLCA55_SCLK source clock by 1
#define BSP_CLOCKS_PLLCA55_SCLK_DIV_2                                     (1) // Divide PLLCA55_SCLK source clock by 2
#define BSP_CLOCKS_PLLCA55_SCLK_DIV_4                                     (2) // Divide PLLCA55_SCLK source clock by 4
#define BSP_CLOCKS_PLLCA55_SCLK_DIV_8                                     (3) // Divide PLLCA55_SCLK source clock by 8

/* CPG_CDDIV1.DIVCTL0(CLK1800_PLLCA55_CA55_0) SET options. */
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_0_DIV_1                           (0) // Divide CLK1800_PLLCA55_CA55_0 source clock by 1
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_0_DIV_2                           (1) // Divide CLK1800_PLLCA55_CA55_0 source clock by 2
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_0_DIV_4                           (2) // Divide CLK1800_PLLCA55_CA55_0 source clock by 4
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_0_DIV_8                           (3) // Divide CLK1800_PLLCA55_CA55_0 source clock by 8

/* CPG_CDDIV1.DIVCTL1(CLK1800_PLLCA55_CA55_1) SET options. */
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_1_DIV_1                           (0) // Divide CLK1800_PLLCA55_CA55_1 source clock by 1
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_1_DIV_2                           (1) // Divide CLK1800_PLLCA55_CA55_1 source clock by 2
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_1_DIV_4                           (2) // Divide CLK1800_PLLCA55_CA55_1 source clock by 4
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_1_DIV_8                           (3) // Divide CLK1800_PLLCA55_CA55_1 source clock by 8

/* CPG_CDDIV1.DIVCTL2(CLK1800_PLLCA55_CA55_2) SET options. */
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_2_DIV_1                           (0) // Divide CLK1800_PLLCA55_CA55_2 source clock by 1
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_2_DIV_2                           (1) // Divide CLK1800_PLLCA55_CA55_2 source clock by 2
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_2_DIV_4                           (2) // Divide CLK1800_PLLCA55_CA55_2 source clock by 4
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_2_DIV_8                           (3) // Divide CLK1800_PLLCA55_CA55_2 source clock by 8

/* CPG_CDDIV1.DIVCTL3(CLK1800_PLLCA55_CA55_3) SET options. */
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_3_DIV_1                           (0) // Divide CLK1800_PLLCA55_CA55_3 source clock by 1
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_3_DIV_2                           (1) // Divide CLK1800_PLLCA55_CA55_3 source clock by 2
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_3_DIV_4                           (2) // Divide CLK1800_PLLCA55_CA55_3 source clock by 4
#define BSP_CLOCKS_CLK1800_PLLCA55_CA55_3_DIV_8                           (3) // Divide CLK1800_PLLCA55_CA55_3 source clock by 8

/* CPG_CDDIV2.DIVCTL0(CA55PERI) SET options. */
#define BSP_CLOCKS_PLLCA55PERI_DIV_2                                      (0) // Divide PLLCA55PERI source clock by 2
#define BSP_CLOCKS_PLLCA55PERI_DIV_4                                      (1) // Divide PLLCA55PERI source clock by 4
#define BSP_CLOCKS_PLLCA55PERI_DIV_8                                      (2) // Divide PLLCA55PERI source clock by 8
#define BSP_CLOCKS_PLLCA55PERI_DIV_16                                     (3) // Divide PLLCA55PERI source clock by 16

/* CPG_CDDIV3.DIVCTL1(PLLVDO_GPU) SET options. */
#define BSP_CLOCKS_PLLVDO_GPU_DIV_2                                       (0) // Divide PLLVDO_GPU source clock by 2
#define BSP_CLOCKS_PLLVDO_GPU_DIV_4                                       (1) // Divide PLLVDO_GPU source clock by 4
#define BSP_CLOCKS_PLLVDO_GPU_DIV_8                                       (2) // Divide PLLVDO_GPU source clock by 8
#define BSP_CLOCKS_PLLVDO_GPU_DIV_16                                      (3) // Divide PLLVDO_GPU source clock by 16
#define BSP_CLOCKS_PLLVDO_GPU_DIV_64                                      (4) // Divide PLLVDO_GPU source clock by 64

/* CPG_CDDIV3.DIVCTL2(PLLDTY_RCPU) SET options. */
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_2                                      (0) // Divide PLLDTY_RCPU source clock by 2
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_4                                      (1) // Divide PLLDTY_RCPU source clock by 4
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_8                                      (2) // Divide PLLDTY_RCPU source clock by 8
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_16                                     (3) // Divide PLLDTY_RCPU source clock by 16
#define BSP_CLOCKS_PLLDTY_RCPU_DIV_64                                     (4) // Divide PLLDTY_RCPU source clock by 64

/* CPG_CDDIV3.DIVCTL3(PLLVDO_CRU0) SET options. */
#define BSP_CLOCKS_PLLVDO_CRU0_DIV_2                                      (0) // Divide PLLVDO_CRU0 source clock by 2
#define BSP_CLOCKS_PLLVDO_CRU0_DIV_4                                      (1) // Divide PLLVDO_CRU0 source clock by 4

/* CPG_CDDIV4.DIVCTL3(PLLETH_NPU) SET options. */
#define BSP_CLOCKS_PLLETH_NPU_DIV_1                                       (0) // Divide PLLETH_NPU source clock by 1
#define BSP_CLOCKS_PLLETH_NPU_DIV_2                                       (1) // Divide PLLETH_NPU source clock by 2
#define BSP_CLOCKS_PLLETH_NPU_DIV_4                                       (2) // Divide PLLETH_NPU source clock by 4

/* CPG_CDDIV5.DIVCTL0(PLLDTY_NPU) SET options. */
#define BSP_CLOCKS_PLLDTY_NPU_DIV_2                                       (0) // Divide PLLDTY_NPU source clock by 2
#define BSP_CLOCKS_PLLDTY_NPU_DIV_4                                       (1) // Divide PLLDTY_NPU source clock by 4
#define BSP_CLOCKS_PLLDTY_NPU_DIV_8                                       (2) // Divide PLLDTY_NPU source clock by 8
#define BSP_CLOCKS_PLLDTY_NPU_DIV_16                                      (3) // Divide PLLDTY_NPU source clock by 16
#define BSP_CLOCKS_PLLDTY_NPU_DIV_64                                      (4) // Divide PLLDTY_NPU source clock by 64

/* CPG_CSDIV0.DIVCTL0(PLLETH_GBE0) SET options. */
#define BSP_CLOCKS_PLLETH_GBE0_DIV_2                                      (0) // Divide PLLETH_GBE0 source clock by 2
#define BSP_CLOCKS_PLLETH_GBE0_DIV_10                                     (1) // Divide PLLETH_GBE0 source clock by 10
#define BSP_CLOCKS_PLLETH_GBE0_DIV_100                                    (2) // Divide PLLETH_GBE0 source clock by 100

/* CPG_CSDIV0.DIVCTL1(PLLETH_GBE1) SET options. */
#define BSP_CLOCKS_PLLETH_GBE1_DIV_2                                      (0) // Divide PLLETH_GBE1 source clock by 2
#define BSP_CLOCKS_PLLETH_GBE1_DIV_10                                     (1) // Divide PLLETH_GBE1 source clock by 10
#define BSP_CLOCKS_PLLETH_GBE1_DIV_100                                    (2) // Divide PLLETH_GBE1 source clock by 100

/* CPG_CSDIV0.DIVCTL2(PLLETH_LPCLK) SET options. */
#define BSP_CLOCKS_PLLETH_LPCLK_DIV_16                                    (0) // Divide PLLETH_LPCLK source clock by 16
#define BSP_CLOCKS_PLLETH_LPCLK_DIV_32                                    (1) // Divide PLLETH_LPCLK source clock by 32
#define BSP_CLOCKS_PLLETH_LPCLK_DIV_64                                    (2) // Divide PLLETH_LPCLK source clock by 64
#define BSP_CLOCKS_PLLETH_LPCLK_DIV_128                                   (3) // Divide PLLETH_LPCLK source clock by 128

/* CPG_CSDIV0.DIVCTL3(PLLCM33_XSPI) SET options. */
#define BSP_CLOCKS_PLLCM33_XSPI_DIV_2                                     (0) // Divide PLLCM33_XSPI source clock by 2
#define BSP_CLOCKS_PLLCM33_XSPI_DIV_4                                     (1) // Divide PLLCM33_XSPI source clock by 4
#define BSP_CLOCKS_PLLCM33_XSPI_DIV_8                                     (2) // Divide PLLCM33_XSPI source clock by 8
#define BSP_CLOCKS_PLLCM33_XSPI_DIV_16                                    (3) // Divide PLLCM33_XSPI source clock by 16

/* CPG_CSDIV1.DIVCTL0(PLLCM33_ADC_PCLK) SET options. */
#define BSP_CLOCKS_PLLCM33_ADC_PCLK_DIV_8                                 (0) // Divide PLLCM33_ADC_PCLK source clock by 8
#define BSP_CLOCKS_PLLCM33_ADC_PCLK_DIV_10                                (1) // Divide PLLCM33_ADC_PCLK source clock by 10

/* CPG_CSDIV1.DIVCTL1(PLLCM33_ADC_ADCLK) SET options. */
#define BSP_CLOCKS_PLLCM33_ADC_ADCLK_DIV_2                                (0) // Divide PLLCM33_ADC_ADCLK source clock by 2
#define BSP_CLOCKS_PLLCM33_ADC_ADCLK_DIV_4                                (1) // Divide PLLCM33_ADC_ADCLK source clock by 4
#define BSP_CLOCKS_PLLCM33_ADC_ADCLK_DIV_8                                (2) // Divide PLLCM33_ADC_ADCLK source clock by 8
#define BSP_CLOCKS_PLLCM33_ADC_ADCLK_DIV_16                               (3) // Divide PLLCM33_ADC_ADCLK source clock by 16

/* CPG_CSDIV1.DIVCTL2(PLLDSI0) SET options. */
#define BSP_CLOCKS_PLLDSI0_DIV_2                                          (0) // Divide PLLDSI0 source clock by 2
#define BSP_CLOCKS_PLLDSI0_DIV_4                                          (1) // Divide PLLDSI0 source clock by 4
#define BSP_CLOCKS_PLLDSI0_DIV_6                                          (2) // Divide PLLDSI0 source clock by 6
#define BSP_CLOCKS_PLLDSI0_DIV_8                                          (3) // Divide PLLDSI0 source clock by 8
#define BSP_CLOCKS_PLLDSI0_DIV_10                                         (4) // Divide PLLDSI0 source clock by 10
#define BSP_CLOCKS_PLLDSI0_DIV_12                                         (5) // Divide PLLDSI0 source clock by 12
#define BSP_CLOCKS_PLLDSI0_DIV_14                                         (6) // Divide PLLDSI0 source clock by 14
#define BSP_CLOCKS_PLLDSI0_DIV_16                                         (7) // Divide PLLDSI0 source clock by 16

/* CPG_CSDIV1.DIVCTL3(PLLDSI1) SET options. */
#define BSP_CLOCKS_PLLDSI1_DIV_2                                          (0) // Divide PLLDSI1 source clock by 2
#define BSP_CLOCKS_PLLDSI1_DIV_4                                          (1) // Divide PLLDSI1 source clock by 4
#define BSP_CLOCKS_PLLDSI1_DIV_6                                          (2) // Divide PLLDSI1 source clock by 6
#define BSP_CLOCKS_PLLDSI1_DIV_8                                          (3) // Divide PLLDSI1 source clock by 8
#define BSP_CLOCKS_PLLDSI1_DIV_10                                         (4) // Divide PLLDSI1 source clock by 10
#define BSP_CLOCKS_PLLDSI1_DIV_12                                         (5) // Divide PLLDSI1 source clock by 12
#define BSP_CLOCKS_PLLDSI1_DIV_14                                         (6) // Divide PLLDSI1 source clock by 14
#define BSP_CLOCKS_PLLDSI1_DIV_16                                         (7) // Divide PLLDSI1 source clock by 16

/* CPG_PLL_DSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_OSC_0024                                  (0) // Select OSC/1000 clock
#define BSP_CLOCKS_SOURCE_CLOCK_PLL4                                      (1) // Select PLL4 clock

/* CPG_BSC_DSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_BSC_320                                   (0)  // Select 320MHz
#define BSP_CLOCKS_SOURCE_CLOCK_BSC_266                                   (1)  // Select 266MHz
#define BSP_CLOCKS_SOURCE_CLOCK_BSC_228                                   (2)  // Select 228MHz
#define BSP_CLOCKS_SOURCE_CLOCK_BSC_200                                   (3)  // Select 200MHz

/* CPG_SDHI_DSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_PLL2_800                                  (0) // Select 800MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL1_600                                  (1)  // Select 600MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL6_500                                  (2) // Select 500MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL2_266                                  (3) // Select 266MHz

/* CPG_OCTA_SSEL and CPG_SPI_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_PLL3_400                                  (0) // Select 400MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL3_266                                  (2) // Select 266MHz
#define BSP_CLOCKS_SOURCE_CLOCK_PLL6_250                                  (3) // Select 250MHz

/* CPG_XSPI_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_XSPI_800                                  (0)  // Select 800MHz
#define BSP_CLOCKS_SOURCE_CLOCK_XSPI_600                                  (1)  // Select 600MHz
#define BSP_CLOCKS_SOURCE_CLOCK_XSPI_522                                  (2)  // Select 522MHz
#define BSP_CLOCKS_SOURCE_CLOCK_XSPI_500                                  (3)  // Select 500MHz

/* CPG_DSI_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_DIV_DSI_DIV1TO2_LVDS_DIV_7                (0)  // Select DIV_DSI_DIV1to2_LVDS/7
#define BSP_CLOCKS_SOURCE_CLOCK_DIV_DSI_DIV1TO16_VCLK                     (1)  // Select DIV_DSI_DIV1to16_VCLK

/* CPG_GE3D_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_GE3D_600                                  (0)  // Select 600MHz
#define BSP_CLOCKS_SOURCE_CLOCK_GE3D_533                                  (1)  // Select 533.33MHz
#define BSP_CLOCKS_SOURCE_CLOCK_GE3D_500                                  (2)  // Select 500MHz
#define BSP_CLOCKS_SOURCE_CLOCK_GE3D_400                                  (3)  // Select 400MHz

/* CPG_ETH_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH0_TR                               (0)  // Select DIV_ETH0_TR
#define BSP_CLOCKS_SOURCE_CLOCK_DIV_ETH1_TR                               (0)  // Select DIV_ETH1_TR
#define BSP_CLOCKS_SOURCE_CLOCK_PLL6_DIV_10                               (0)  // Select PLL6/10 (50MHz)
#define BSP_CLOCKS_SOURCE_CLOCK_ETH0_TXC_TX_CLK_IN                        (1)  // Select ETH0_TXC_TX_CLK_IN
#define BSP_CLOCKS_SOURCE_CLOCK_ETH0_RXC_RX_CLK_IN                        (1)  // Select ETH0_RXC_RX_CLK_IN
#define BSP_CLOCKS_SOURCE_CLOCK_NORMAL_MODE                               (0)  // Select Normal Mode
#define BSP_CLOCKS_SOURCE_CLOCK_RMII_MODE                                 (1)  // Select RMII Mode

/* CPG_RSCI_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_RSCI_320                                  (0)  // Select 320MHz
#define BSP_CLOCKS_SOURCE_CLOCK_RSCI_266                                  (1)  // Select 266MHz
#define BSP_CLOCKS_SOURCE_CLOCK_RSCI_228                                  (2)  // Select 228MHz
#define BSP_CLOCKS_SOURCE_CLOCK_RSCI_200                                  (3)  // Select 200MHz

/* CPG_RSPI_SSEL options. */
#define BSP_CLOCKS_SOURCE_CLOCK_RSPI_320                                  (0)  // Select 320MHz
#define BSP_CLOCKS_SOURCE_CLOCK_RSPI_266                                  (1)  // Select 266MHz
#define BSP_CLOCKS_SOURCE_CLOCK_RSPI_228                                  (2)  // Select 228MHz
#define BSP_CLOCKS_SOURCE_CLOCK_RSPI_200                                  (3)  // Select 200MHz

/* CPG_SSEL0.SELCTL0 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL0_SMUX2_CA55_SCLK0            (0) // Select SMUX_CA55_SCLK0
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL0_PLLCA55                     (1) // Select PLLCA55

/* CPG_SSEL0.SELCTL1 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLVDO                      (0) // Select PLLVDO
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL1_PLLDTY                      (1) // Select PLLDTY

/* CPG_SSEL0.SELCTL2 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL2_CSDIV_PLLETH_GBE0           (0) // Select CSDIV_PLLETH_GBE0
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL2_ET0_TXC_TX_CLK              (1) // Select ET0_TXC_TX_CLK

/* CPG_SSEL0.SELCTL3 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL3_CSDIV_PLLETH_GBE0           (0) // Select CSDIV_PLLETH_GBE0
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL0_SELCTL3_ET0_RXC_RX_CLK              (1) // Select ET0_RXC_RX_CLK

/* CPG_SSEL1.SELCTL0 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL0_CSDIV_PLLETH_GBE1           (0) // Select CSDIV_PLLETH_GBE1
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL0_ET1_TXC_TX_CLK              (1) // Select ET1_TXC_TX_CLK

/* CPG_SSEL1.SELCTL1 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL1_CSDIV_PLLETH_GBE1           (0) // Select CSDIV_PLLETH_GBE1
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL1_ET1_RXC_RX_CLK              (1) // Select ET1_RXC_RX_CLK

/* CPG_SSEL1.SELCTL2 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL2_CDIV3_CLK533_PLLCM33_FIX    (0) // Select CDIV3_CLK533_PLLCM33_FIX
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL2_CDIV4_CLK400_PLLCM33_FIX    (1) // Select CDIV4_CLK400_PLLCM33_FIX

/* CPG_SSEL1.SELCTL3 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL3_SMUX2_XSPI_CLK0             (0) // Select SMUX2_XSPI_CLK0
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL1_SELCTL3_CDIV5_CLK320_PLLCM33_FIX    (1) // Select CDIV5_CLK320_PLLCM33_FIX

/* CPG_SSEL3.SELCTL0 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL3_SELCTL0_CDIV7_DSI0_CLK              (0) // Select CDIV7_DSI0_CLK
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL3_SELCTL0_PLLDSI0_GEAR                (1) // Select PLLDSI0_GEAR

/* CPG_SSEL3.SELCTL1 options. */
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL3_SELCTL1_CDIV7_DSI1_CLK              (0) // Select CDIV7_DSI1_CLK
#define BSP_CLOCKS_SOURCE_CLOCK_SSEL3_SELCTL1_PLLDSI1_GEAR                (1) // Select PLLDSI1_GEAR

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
