/*
* Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_MCU_FAMILY_CFG_H_
#define BSP_MCU_FAMILY_CFG_H_
#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_mcu_device_cfg.h"
#include "../../../rx/fsp/src/bsp/mcu/rx74m/bsp_override.h"
#include "../../../rx/fsp/src/bsp/mcu/rx74m/bsp_mcu_info.h"
#include "../../../rx/fsp/src/bsp/mcu/rx74m/r_adc_device_types.h"
#include "../../../rx/fsp/src/bsp/mcu/rx74m/r_lpm_device_types.h"
#include "bsp_clock_cfg.h"
#define BSP_MCU_GROUP_RX74M (1)

#define BSP_LOCO_HZ (DT_PROP_OR(DT_NODELABEL(loco), clock_frequency, 0))
#define BSP_MOCO_HZ (DT_PROP_OR(DT_NODELABEL(moco), clock_frequency, 0))
#define BSP_SUB_CLOCK_HZ (DT_PROP_OR(DT_NODELABEL(subclk), clock_frequency, 0))
#if   BSP_CFG_HOCO_FREQUENCY == 0
#define BSP_HOCO_HZ                 (16000000)
#elif BSP_CFG_HOCO_FREQUENCY == 1
            #define BSP_HOCO_HZ                 (18000000)
        #elif BSP_CFG_HOCO_FREQUENCY == 2
            #define BSP_HOCO_HZ                 (20000000)
        #elif BSP_CFG_HOCO_FREQUENCY == 4
            #define BSP_HOCO_HZ                 (32000000)
        #elif BSP_CFG_HOCO_FREQUENCY == 7
            #define BSP_HOCO_HZ                 (48000000)
        #else
            #error "Invalid HOCO frequency chosen (BSP_CFG_HOCO_FREQUENCY) in bsp_clock_cfg.h"
        #endif

#define BSP_CFG_FLL_ENABLE                   (0)

#define BSP_CFG_CLOCK_SETTLING_DELAY_ENABLE  (1)
#define BSP_CFG_SLEEP_MODE_DELAY_ENABLE      (1)
#define BSP_CFG_RTOS_SLEEP_MODE_DELAY_ENABLE (1)
#define BSP_CFG_CLOCK_SETTLING_DELAY_US      (150)
#define BSP_CFG_MAIN_OSC_MODRV0              (0xFFU)

#define BSP_CFG_INLINE_IRQ_FUNCTIONS         (1)

#define BSP_CFG_PREFETCH_BUFFER_ENABLE       (0)

#ifndef BSP_CLOCK_CFG_MAIN_OSC_WAIT
#define BSP_CLOCK_CFG_MAIN_OSC_WAIT (9)
#endif

#ifndef BSP_CFG_DCACHE_ENABLED
#define BSP_CFG_DCACHE_ENABLED (0)
#endif

#ifndef BSP_CFG_ICACHE_ENABLED
#define BSP_CFG_ICACHE_ENABLED (0)
#endif

/* Used to create IELS values for the interrupt initialization table g_interrupt_event_link_select. */
#define BSP_PRV_IELS_ENUM(vector)    (ICU_ ## vector)

#define BSP_MAX_CLOCK_CHANGE_THRESHOLD (300000000U)

#ifndef BSP_CFG_SDRAM_ENABLED
#define BSP_CFG_SDRAM_ENABLED  (0)
#endif

#ifndef BSP_CFG_SDRAM_TRAS
#define BSP_CFG_SDRAM_TRAS  (6)
#endif

#ifndef BSP_CFG_SDRAM_TRCD
#define BSP_CFG_SDRAM_TRCD  (2)
#endif

#ifndef BSP_CFG_SDRAM_TRP
#define BSP_CFG_SDRAM_TRP  (2)
#endif

#ifndef BSP_CFG_SDRAM_TWR
#define BSP_CFG_SDRAM_TWR  (2)
#endif

#ifndef BSP_CFG_SDRAM_TCL
#define BSP_CFG_SDRAM_TCL  (3)
#endif

#ifndef BSP_CFG_SDRAM_TRFC
#define BSP_CFG_SDRAM_TRFC  (1171)
#endif

#ifndef BSP_CFG_SDRAM_TREFW
#define BSP_CFG_SDRAM_TREFW  (5)
#endif

#ifndef BSP_CFG_SDRAM_INIT_ARFI
#define BSP_CFG_SDRAM_INIT_ARFI  (5)
#endif

#ifndef BSP_CFG_SDRAM_INIT_ARFC
#define BSP_CFG_SDRAM_INIT_ARFC  (2)
#endif

#ifndef BSP_CFG_SDRAM_INIT_PRC
#define BSP_CFG_SDRAM_INIT_PRC  (3)
#endif

#ifndef BSP_CFG_SDRAM_MULTIPLEX_ADDR_SHIFT
#define BSP_CFG_SDRAM_MULTIPLEX_ADDR_SHIFT  (0)
#endif

#ifndef BSP_CFG_SDRAM_ENDIAN_MODE
#define BSP_CFG_SDRAM_ENDIAN_MODE  (0)
#endif

#ifndef BSP_CFG_SDRAM_ACCESS_MODE
#define BSP_CFG_SDRAM_ACCESS_MODE  (1)
#endif

#ifndef BSP_CFG_SDRAM_BUS_WIDTH
#define BSP_CFG_SDRAM_BUS_WIDTH  (0)
#endif

#if defined(_RX_PZ_SECURE)
#define BSP_PZ_SECURE_BUILD (1)
#define BSP_PZ_NONSECURE_BUILD (0)
#elif defined(_RX_PZ_NONSECURE)
#define BSP_PZ_SECURE_BUILD (0)
#define BSP_PZ_NONSECURE_BUILD (1)
#else
#define BSP_PZ_SECURE_BUILD (0)
#define BSP_PZ_NONSECURE_BUILD (0)
#endif

/* ProtectZone Settings */
#define BSP_PZ_CFG_EXCEPTION_RESPONSE (0)

/* Peripheral Security Attribution Register (PSAR) Settings */
#ifndef BSP_PZ_CFG_PSARB
#define BSP_PZ_CFG_PSARB (\
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 0) /* RSCI12, MSTPCRB.MSTPB0 bit */ | \
((((FSP_NOT_DEFINED > 0) || (FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 4) /* RI3C0, MSTPCRB.MSTPB4 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 7) /* RIICHS2, MSTPCRB.MSTPB7 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 8) /* RIICHS1, MSTPCRB.MSTPB8 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 11) /* USB0, MSTPCRB.MSTPB11 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 12) /* USBHS, MSTPCRB.MSTPB12 bit */ | \
(1U << 16) /* XSPI0(+DOTF0), MSTPCRB.MSTPB16 bit */ | \
(1U << 17) /* XSPI1(+DOTF1), MSTPCRB.MSTPB17 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 18) /* RSPIA1, MSTPCRB.MSTPB18 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 19) /* RSPIA0, MSTPCRB.MSTPB19 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 20) /* RSCI11, MSTPCRB.MSTPB20 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 21) /* RSCI10, MSTPCRB.MSTPB21 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 22) /* RSCI9, MSTPCRB.MSTPB22 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 23) /* RSCI8, MSTPCRB.MSTPB23 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 24) /* RSCI7, MSTPCRB.MSTPB24 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 25) /* RSCI6, MSTPCRB.MSTPB25 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 26) /* RSCI5, MSTPCRB.MSTPB26 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 27) /* RSCI4, MSTPCRB.MSTPB27 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 28) /* RSCI3, MSTPCRB.MSTPB28 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 29) /* RSCI2, MSTPCRB.MSTPB29 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 30) /* RSCI1, MSTPCRB.MSTPB30 bit */ | \
(((1 > 0) ? 0U : 1U) << 31) /* RSCI0, MSTPCRB.MSTPB31 bit */)
#endif

#ifndef BSP_PZ_CFG_PSARC
#define BSP_PZ_CFG_PSARC (\
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 0) /* CAC, MSTPCRC.MSTPC0 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 1) /* CRC, MSTPCRC.MSTPC1 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 2) /* PDC, MSTPCRC.MSTPC2 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 7) /* SSIE1, MSTPCRC.MSTPC7 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 8) /* SSIE0, MSTPCRC.MSTPC8 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 12) /* SDHI, MSTPCRC.MSTPC12 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 13) /* DOC, MSTPCRC.MSTPC13 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 23) /* RSPIA2, MSTPCRC.MSTPC23 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 24) /* PDMIF, MSTPCRC.MSTPC24 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 25) /* CANFDG0, MSTPCRC.MSTPC25 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 27) /* CANFD, MSTPCRC.MSTPC27 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 28) /* ETHPHY, MSTPCRC.MSTPC28 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 29) /* ESC, MSTPCRC.MSTPC29 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 30) /* ESWM, MSTPCRC.MSTPC30 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 31) /* RSIP-E50D, MSTPCRC.MSTPC31 bit */)
#endif

#ifndef BSP_PZ_CFG_PSARD
#define BSP_PZ_CFG_PSARD (\
((((FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 6) /* HRPWM, MSTPCRD.MSTPD6 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 8) /* DSMIF1, MSTPCRD.MSTPD8 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 9) /* DSMIF0, MSTPCRD.MSTPD9 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 11) /* POEG GroupD, MSTPCRD.MSTPD11 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 12) /* POEG GroupC, MSTPCRD.MSTPD12 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 13) /* POEG GroupB, MSTPCRD.MSTPD13 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 14) /* POEG GroupA, MSTPCRD.MSTPD14 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 19) /* DAC1, MSTPCRD.MSTPD19 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 20) /* DAC0, MSTPCRD.MSTPD20 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 21) /* ADC16H, MSTPCRD.MSTPD21 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 22) /* TEMPS, MSTPCRD.MSTPD22 bit */)
#endif

#ifndef BSP_PZ_CFG_PSARE
#define BSP_PZ_CFG_PSARE (\
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 1) /* WDT */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 2) /* IWDT */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 3) /* RTC */ | \
((((FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 15) /* GPTW.GTCLKCR register */ | \
((((FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0) || \
(FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 31) /* GPTW15-0, GPT_OPS, MSTPCRE.MSTPE31 bit */)
#endif

#ifndef BSP_PZ_CFG_PSARF
#define BSP_PZ_CFG_PSARF (\
((((FSP_NOT_DEFINED > 0) || (FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 6) /* TMR3, TMR2, MSTPCRF.MSTPF6 bit */ | \
((((FSP_NOT_DEFINED > 0) || (FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 7) /* TMR1, TMR0, MSTPCRF.MSTPF7 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 12) /* CMTW1, MSTPCRF.MSTPF12 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 13) /* CMTW0, MSTPCRF.MSTPF13 bit */ | \
((((FSP_NOT_DEFINED > 0) || (FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 14) /* CMT3, CMT2, MSTPCRF.MSTPF14 bit */ | \
((((FSP_NOT_DEFINED > 0) || (FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 15) /* CMT1, CMT0, MSTPCRF.MSTPF15 bit */ | \
(1U << 16) /* PIO, MSTPCRF.MSTPF16 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 30) /* PCIF1, MSTPCRF.MSTPF30 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 31) /* PCIF0, MSTPCRF.MSTPF31 bit */)
#endif

#ifndef BSP_PZ_CFG_MSSAR
#define BSP_PZ_CFG_MSSAR (\
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 22) /* DMAC, DTC, MSTPCRA.MSTPA22 bit */ | \
((((FSP_NOT_DEFINED > 0) || (FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 29) /* EXDMAC, MSTPCRA.MSTPA29 bit */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 31) /* ELC, MSTPCRC.MSTPC14 bit */)
#endif

/* Security attribution for Cache registers. */
#ifndef BSP_PZ_CFG_CACHESAR
#define BSP_PZ_CFG_CACHESAR (0x00000005U)
#endif

#ifndef BSP_PZ_CFG_IFUSAR
#define BSP_PZ_CFG_IFUSAR (0x00000001U)
#endif

/* Security attribution for RSTSRn registers. */
#ifndef BSP_PZ_CFG_RSTSAR
#define BSP_PZ_CFG_RSTSAR (0x0000002FU)
#endif

/* Security attribution for registers of LVD channels. */
#ifndef BSP_PZ_CFG_PVDSAR
#define BSP_PZ_CFG_PVDSAR (\
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 0) | /* PVD Channel 1 */ \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 1) /* PVD Channel 2 */)
#endif

/* Security attribution for CGC registers. */
#ifndef BSP_PZ_CFG_CGFSAR
#if BSP_CFG_CLOCKS_SECURE
/* Protect all CGC registers from Non-secure write access. */
#define BSP_PZ_CFG_CGFSAR (0x00000000U)
#else
/* Allow Secure and Non-secure write access. */
#define BSP_PZ_CFG_CGFSAR (0x3B7F7FFDU)
#endif
#endif

/* Security attribution for LPM registers. */
#ifndef BSP_PZ_CFG_LPMSAR
#define BSP_PZ_CFG_LPMSAR ((FSP_NOT_DEFINED > 0) ? 0x00000000U : 0x002F0116U)
#endif

/* Deep Standby Interrupt Factor Security Attribution Register. */
#ifndef BSP_PZ_CFG_DPFSAR
#define BSP_PZ_CFG_DPFSAR ((FSP_NOT_DEFINED > 0) ? 0x00000000U : 0xE31FFFFFU)
#endif

/* Deep Standby Interrupt Factor Security Attribution Register1. */
#ifndef BSP_PZ_CFG_DPFSAR1
#define BSP_PZ_CFG_DPFSAR1 ((FSP_NOT_DEFINED > 0) ? 0x00000000U : 0x0000FFFFU)
#endif

/* RAM Standby Control Security Attribution Register. */
#ifndef BSP_PZ_CFG_RSCSAR
#define BSP_PZ_CFG_RSCSAR ((FSP_NOT_DEFINED > 0) ? 0x00000000U : 0x01000FFFU)
#endif

/* Power gating Security Attribution Register. */
#ifndef BSP_PZ_CFG_PGCSAR
#define BSP_PZ_CFG_PGCSAR (\
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 0U) /* NONSEC0 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 3U) /* NONSEC3 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 5U) /* NONSEC5 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 6U) /* NONSEC6 */)
#endif

/* Security attribution for Battery Backup registers. */
#ifndef BSP_PZ_CFG_VBSAR
#define BSP_PZ_CFG_VBSAR (0x0000007FU)
#endif

/* Backup register Security attribution Boundary address register (BKRSABR) */
#ifndef BSP_PZ_CFG_BKRSABR
#if 0x0000007FU
#define BSP_PZ_CFG_BKRSABR (0x9D00U)
#else
#define BSP_PZ_CFG_BKRSABR (0xFFE0U)
#endif
#endif

/* Security attribution for IRQCRi, PIXRk registers. */
#ifndef BSP_PZ_CFG_ICUSARA
#define BSP_PZ_CFG_ICUSARA (\
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 0U) /* IRQCR0 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 1U) /* IRQCR1 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 2U) /* IRQCR2 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 3U) /* IRQCR3 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 4U) /* IRQCR4 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 5U) /* IRQCR5 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 6U) /* IRQCR6 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 7U) /* IRQCR7 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 8U) /* IRQCR8 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 9U) /* IRQCR9 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 10U) /* IRQCR10 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 11U) /* IRQCR11 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 12U) /* IRQCR12 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 13U) /* IRQCR13 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 14U) /* IRQCR14 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 15U) /* IRQCR15 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 16U) /* IRQCR16, PIXR0.PIR0 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 17U) /* IRQCR17, PIXR0.PIR1 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 18U) /* IRQCR18, PIXR0.PIR2 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 19U) /* IRQCR19, PIXR0.PIR3 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 20U) /* IRQCR20, PIXR0.PIR4 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 21U) /* IRQCR21, PIXR0.PIR5 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 22U) /* IRQCR22, PIXR0.PIR6 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 23U) /* IRQCR23, PIXR0.PIR7 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 24U) /* IRQCR24, PIXR1.PIR0 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 25U) /* IRQCR25, PIXR1.PIR1 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 26U) /* IRQCR26, PIXR1.PIR2 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 27U) /* IRQCR27, PIXR1.PIR3 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 28U) /* IRQCR28, PIXR1.PIR4 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 29U) /* IRQCR29, PIXR1.PIR5 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 30U) /* IRQCR30, PIXR1.PIR6 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 31U) /* IRQCR31, PIXR1.PIR7 */)
#endif

/* Security attribution for NMI registers. */
#ifndef BSP_PZ_CFG_ICUSARB
#define BSP_PZ_CFG_ICUSARB (\
(((1 > 0) ? 1U : 0U) << 0U) /* NMICR */ | \
(((1 > 0) ? 1U : 0U) << 1U) /* NMISR, NMIER, NMICLR */)
#endif

/* Security attribution for CLPCR register */
#ifndef BSP_PZ_CFG_ICUSARC
#define BSP_PZ_CFG_ICUSARC (\
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 1U) /* SYSC.CLPCR */)
#endif

/* Security attribution for DMAC channel registers */
#ifndef BSP_PZ_CFG_DMACCHSAR
#define BSP_PZ_CFG_DMACCHSAR (\
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 0U) /* DMAC Channel 0 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 1U) /* DMAC Channel 1 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 2U) /* DMAC Channel 2 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 3U) /* DMAC Channel 3 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 4U) /* DMAC Channel 4 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 5U) /* DMAC Channel 5 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 6U) /* DMAC Channel 6 */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 7U) /* DMAC Channel 7 */)
#endif

#ifndef BSP_PZ_CFG_ICUSARD
#define BSP_PZ_CFG_ICUSARD (\
(((1 > 0) ? 1U : 0U) << 0U) /* Double-Precision Floating-Point Exceptions */ | \
(((1 > 0) ? 1U : 0U) << 1U) /* Local Memory Error Interrupt */ | \
(((1 > 0) ? 1U : 0U) << 2U) /* Common Memory Error Interrupt */ | \
(((1U > 0) ? 1U : 0U) << 3U) /* External Bus Hold Timeout Interrupt */ | \
(0U << 8U) /* Code MRAM ECC Error Interrupt */ | \
(0U << 9U) /* Extra MRAM ECC Error Interrupt */ | \
(0U << 10U) /* Code MRAM write error interrupt */ | \
(0U << 11U) /* Data MRAM write error interrupt */ | \
(0U << 12U) /* Extra MRAM write error interrupt */)
#endif

#ifndef BSP_PZ_CFG_ICU0SAR0
#define BSP_PZ_CFG_ICU0SAR0 (\
(1U << 0U) /* IPR0 */ | \
(0U << 1U) /* IPR1 */ | \
(1U << 2U) /* IPR2 */ | \
(1U << 3U) /* IPR3 */ | \
(1U << 4U) /* IPR4 */ | \
(1U << 5U) /* IPR5 */ | \
(1U << 6U) /* IPR6 */ | \
(1U << 7U) /* IPR7 */ | \
(1U << 8U) /* IPR8 */ | \
(1U << 16U) /* IR16, IER2.IEN0 bit */ | \
(0U << 17U) /* IR17, IER2.IEN1 bit */ | \
(1U << 18U) /* IR18, IER2.IEN2 bit */ | \
(0U << 19U) /* IR19, IER2.IEN3, IPR19 bit */ | \
(1U << 20U) /* IR20, IER2.IEN4, IPR20 bit */ | \
(1U << 26U) /* IR26, IER3.IEN2 bit, DTCER26, SWINT2R */ | \
(1U << 27U) /* IR27, IER3.IEN3 bit, DTCER27, SWINTR */ | \
(1U << 28U) /* IR28, IER3.IEN4 bit, DTCER28 */ | \
(1U << 29U) /* IR29, IER3.IEN5 bit, DTCER29 */ | \
(1U << 30U) /* IR30, IER3.IEN6 bit, DTCER30 */ | \
(1U << 31U) /* IR31, IER3.IEN7 bit, DTCER31 */)
#endif

#ifndef BSP_PZ_CFG_ICU0SAR1
#define BSP_PZ_CFG_ICU0SAR1 (\
(1U << 0U) /* IR32, IER4.IEN0 bit, IPR32 */ | \
(1U << 1U) /* IR33, IER4.IEN1 bit, IPR33, DTCER33 */)
#endif

#ifndef BSP_PZ_CFG_ICU0SAR2
#define BSP_PZ_CFG_ICU0SAR2 (\
(1U << 0U) /* IR64, IER8.IEN0 bit, IPR64, DTCER64 */ | \
(1U << 1U) /* IR65, IER8.IEN1 bit, IPR65, DTCER65 */ | \
(1U << 2U) /* IR66, IER8.IEN2 bit, IPR66, DTCER66 */ | \
(1U << 3U) /* IR67, IER8.IEN3 bit, IPR67, DTCER67 */ | \
(1U << 4U) /* IR68, IER8.IEN4 bit, IPR68, DTCER68 */ | \
(1U << 5U) /* IR69, IER8.IEN5 bit, IPR69, DTCER69 */ | \
(1U << 6U) /* IR70, IER8.IEN6 bit, IPR70, DTCER70 */ | \
(1U << 7U) /* IR71, IER8.IEN7 bit, IPR71, DTCER71 */ | \
(1U << 8U) /* IR72, IER9.IEN0 bit, IPR72, DTCER72 */ | \
(1U << 9U) /* IR73, IER9.IEN1 bit, IPR73, DTCER73 */ | \
(1U << 10U) /* IR74, IER9.IEN2 bit, IPR74, DTCER74 */ | \
(1U << 11U) /* IR75, IER9.IEN3 bit, IPR75, DTCER75 */ | \
(1U << 12U) /* IR76, IER9.IEN4 bit, IPR76, DTCER76 */ | \
(1U << 13U) /* IR77, IER9.IEN5 bit, IPR77, DTCER77 */ | \
(1U << 14U) /* IR78, IER9.IEN6 bit, IPR78, DTCER78 */ | \
(1U << 15U) /* IR79, IER9.IEN7 bit, IPR79, DTCER79 */ | \
(1U << 16U) /* IR80, IER10.IEN0 bit, IPR80 */ | \
(1U << 17U) /* IR81, IER10.IEN1 bit, IPR81 */ | \
(1U << 18U) /* IR82, IER10.IEN2 bit, IPR82 */ | \
(1U << 19U) /* IR83, IER10.IEN3 bit, IPR83 */ | \
(1U << 20U) /* IR84, IER10.IEN4 bit, IPR84 */ | \
(1U << 21U) /* IR85, IER10.IEN5 bit, IPR85 */ | \
(1U << 24U) /* IR88, IER11.IEN0 bit, IPR88 */ | \
(1U << 25U) /* IR89, IER11.IEN1 bit, IPR89 */ | \
(1U << 26U) /* IR90, IER11.IEN2 bit, IPR90 */ | \
(1U << 28U) /* IR92, IER11.IEN4 bit, IPR92 */ | \
(1U << 29U) /* IR93, IER11.IEN5 bit, IPR93 */ | \
(1U << 30U) /* IR94, IER11.IEN6 bit, IPR94 */ | \
(1U << 31U) /* IR95, IER11.IEN7 bit, IPR95 */)
#endif

#ifndef BSP_PZ_CFG_ICU0SAR3
#define BSP_PZ_CFG_ICU0SAR3 (\
(1U << 0U) /* IR96, IER12.IEN0 bit, IPR96 */ | \
(0U << 6U) /* IR102, IER12.IEN6 bit, IPR102 */ | \
(0U << 7U) /* IR103, IER12.IEN7 bit, IPR103 */ | \
(0U << 8U) /* IR104, IER13.IEN0 bit, IPR104 */ | \
(0U << 9U) /* IR105, IER13.IEN1 bit, IPR105 */ | \
(0U << 10U) /* IR106, IER13.IEN2 bit, IPR106 */ | \
(0U << 11U) /* IR107, IER13.IEN3 bit, IPR107 */ | \
(0U << 12U) /* IR108, IER13.IEN4 bit, IPR108 */ | \
(0U << 13U) /* IR109, IER13.IEN5 bit, IPR109 */ | \
(0U << 14U) /* IR110, IER13.IEN6 bit, IPR110 */ | \
(1U << 15U) /* IR111, IER13.IEN7 bit, IPR111 */ | \
(1U << 16U) /* IR112, IER14.IEN0 bit, IPR112 */ | \
(1U << 17U) /* IR113, IER14.IEN1 bit, IPR113 */ | \
(1U << 18U) /* IR114, IER14.IEN2 bit, IPR114 */ | \
(1U << 19U) /* IR115, IER14.IEN3 bit, IPR115 */ | \
(1U << 20U) /* IR116, IER14.IEN4 bit, IPR116 */ | \
(1U << 21U) /* IR117, IER14.IEN5 bit, IPR117 */ | \
(1U << 22U) /* IR118, IER14.IEN6 bit, IPR118 */ | \
(1U << 23U) /* IR119, IER14.IEN7 bit, IPR119 */ | \
(1U << 24U) /* IR120, IER15.IEN0 bit, IPR120, DTCER120 */ | \
(1U << 25U) /* IR121, IER15.IEN1 bit, IPR121, DTCER121 */ | \
(1U << 26U) /* IR122, IER15.IEN2 bit, IPR122, DTCER122 */ | \
(1U << 27U) /* IR123, IER15.IEN3 bit, IPR123, DTCER123 */ | \
(1U << 28U) /* IR124, IER15.IEN4 bit, IPR124 */ | \
(1U << 29U) /* IR125, IER15.IEN5 bit, IPR125 */ | \
(1U << 30U) /* IR126, IER15.IEN6 bit, IPR126, DTCER126 */ | \
(1U << 31U) /* IR127, IER15.IEN7 bit, IPR127, DTCER127 */)
#endif

#ifndef BSP_PZ_CFG_ICU0SAR4
#define BSP_PZ_CFG_ICU0SAR4 (\
(1U << 0U) /* IR128, IER16.IEN0 bit, IPR128, DTCER128, SLIXR128 */ | \
(1U << 1U) /* IR129, IER16.IEN1 bit, IPR129, DTCER129, SLIXR129 */ | \
(1U << 2U) /* IR130, IER16.IEN2 bit, IPR130, DTCER130, SLIXR130 */ | \
(1U << 3U) /* IR131, IER16.IEN3 bit, IPR,131 DTCER131, SLIXR131 */ | \
(1U << 4U) /* IR132, IER16.IEN4 bit, IPR132, DTCER132, SLIXR132 */ | \
(1U << 5U) /* IR133, IER16.IEN5 bit, IPR133, DTCER133, SLIXR133 */ | \
(1U << 6U) /* IR134, IER16.IEN6 bit, IPR134, DTCER134, SLIXR134 */ | \
(1U << 7U) /* IR135, IER16.IEN7 bit, IPR135, DTCER135, SLIXR135 */ | \
(1U << 8U) /* IR136, IER17.IEN0 bit, IPR136, DTCER136, SLIXR136 */ | \
(1U << 9U) /* IR137, IER17.IEN1 bit, IPR137, DTCER137, SLIXR137 */ | \
(1U << 10U) /* IR138, IER17.IEN2 bit, IPR138, DTCER138, SLIXR138 */ | \
(1U << 11U) /* IR139, IER17.IEN3 bit, IPR139, DTCER139, SLIXR139 */ | \
(1U << 12U) /* IR140, IER17.IEN4 bit, IPR140, DTCER140, SLIXR140 */ | \
(1U << 13U) /* IR141, IER17.IEN5 bit, IPR141, DTCER141, SLIXR141 */ | \
(1U << 14U) /* IR142, IER17.IEN6 bit, IPR142, DTCER142, SLIXR142 */ | \
(1U << 15U) /* IR143, IER17.IEN7 bit, IPR143, DTCER143, SLIXR143 */ | \
(1U << 16U) /* IR144, IER18.IEN0 bit, IPR144, DTCER144, SLIR144 */ | \
(1U << 17U) /* IR145, IER18.IEN1 bit, IPR145, DTCER145, SLIR145 */ | \
(1U << 18U) /* IR146, IER18.IEN2 bit, IPR146, DTCER146, SLIR146 */ | \
(1U << 19U) /* IR147, IER18.IEN3 bit, IPR147, DTCER147, SLIR147 */ | \
(1U << 20U) /* IR148, IER18.IEN4 bit, IPR148, DTCER148, SLIR148 */ | \
(1U << 21U) /* IR149, IER18.IEN6 bit, IPR149, DTCER149, SLIR149 */ | \
(1U << 22U) /* IR150, IER18.IEN6 bit, IPR150, DTCER150, SLIR150 */ | \
(1U << 23U) /* IR151, IER18.IEN7 bit, IPR151, DTCER151, SLIR151 */ | \
(1U << 24U) /* IR152, IER19.IEN0 bit, IPR152, DTCER152, SLIR152 */ | \
(1U << 25U) /* IR153, IER19.IEN1 bit, IPR153, DTCER153, SLIR153 */ | \
(1U << 26U) /* IR154, IER19.IEN2 bit, IPR154, DTCER154, SLIR154 */ | \
(1U << 27U) /* IR155, IER19.IEN3 bit, IPR155, DTCER155, SLIR155 */ | \
(1U << 28U) /* IR156, IER19.IEN4 bit, IPR156, DTCER156, SLIR156 */ | \
(1U << 29U) /* IR157, IER19.IEN5 bit, IPR157, DTCER157, SLIR157 */ | \
(1U << 30U) /* IR158, IER19.IEN6 bit, IPR158, DTCER158, SLIR158 */ | \
(1U << 31U) /* IR159, IER19.IEN7 bit, IPR158, DTCER159, SLIR159 */)
#endif

#ifndef BSP_PZ_CFG_ICU0SAR5
#define BSP_PZ_CFG_ICU0SAR5 (\
(1U << 0U) /* IR160, IER20.IEN0 bit, IPR160, DTCER160, SLIR160 */ | \
(1U << 1U) /* IR161, IER20.IEN1 bit, IPR161, DTCER161, SLIR161 */ | \
(1U << 2U) /* IR162, IER20.IEN2 bit, IPR162, DTCER162, SLIR162 */ | \
(1U << 3U) /* IR163, IER20.IEN3 bit, IPR163, DTCER163, SLIR163 */ | \
(1U << 4U) /* IR164, IER20.IEN4 bit, IPR164, DTCER164, SLIR164 */ | \
(1U << 5U) /* IR165, IER20.IEN5 bit, IPR165, DTCER165, SLIR165 */ | \
(1U << 6U) /* IR166, IER20.IEN6 bit, IPR166, DTCER166, SLIR166 */ | \
(1U << 7U) /* IR167, IER20.IEN7 bit, IPR167, DTCER167, SLIR167 */ | \
(1U << 8U) /* IR168, IER21.IEN0 bit, IPR168, DTCER168, SLIR168 */ | \
(1U << 9U) /* IR169, IER21.IEN1 bit, IPR169, DTCER169, SLIR169 */ | \
(1U << 10U) /* IR170, IER21.IEN2 bit, IPR170, DTCER170, SLIR170 */ | \
(1U << 11U) /* IR171, IER21.IEN3 bit, IPR171, DTCER171, SLIR171 */ | \
(1U << 12U) /* IR172, IER21.IEN4 bit, IPR172, DTCER172, SLIR172 */ | \
(1U << 13U) /* IR173, IER21.IEN5 bit, IPR173, DTCER173, SLIR173 */ | \
(1U << 14U) /* IR174, IER21.IEN6 bit, IPR174, DTCER174, SLIR174 */ | \
(1U << 15U) /* IR175, IER21.IEN7 bit, IPR175, DTCER175, SLIR175 */ | \
(1U << 16U) /* IR176, IER22.IEN0 bit, IPR176, DTCER176, SLIR176 */ | \
(1U << 17U) /* IR177, IER22.IEN1 bit, IPR177, DTCER177, SLIR177 */ | \
(1U << 18U) /* IR178, IER22.IEN2 bit, IPR178, DTCER178, SLIR178 */ | \
(1U << 19U) /* IR179, IER22.IEN3 bit, IPR179, DTCER179, SLIR179 */ | \
(1U << 20U) /* IR180, IER22.IEN4 bit, IPR180, DTCER180, SLIR180 */ | \
(1U << 21U) /* IR181, IER22.IEN5 bit, IPR181, DTCER181, SLIR181 */ | \
(1U << 22U) /* IR182, IER22.IEN6 bit, IPR182, DTCER182, SLIR182 */ | \
(1U << 23U) /* IR183, IER22.IEN7 bit, IPR183, DTCER183, SLIR183 */ | \
(1U << 24U) /* IR184, IER23.IEN0 bit, IPR184, DTCER184, SLIR184 */ | \
(1U << 25U) /* IR185, IER23.IEN1 bit, IPR185, DTCER185, SLIR185 */ | \
(1U << 26U) /* IR186, IER23.IEN2 bit, IPR186, DTCER186, SLIR186 */ | \
(1U << 27U) /* IR187, IER23.IEN3 bit, IPR187, DTCER187, SLIR187 */ | \
(1U << 28U) /* IR188, IER23.IEN4 bit, IPR188, DTCER188, SLIR188 */ | \
(1U << 29U) /* IR189, IER23.IEN5 bit, IPR189, DTCER189, SLIR189 */ | \
(1U << 30U) /* IR190, IER23.IEN6 bit, IPR190, DTCER190, SLIR190 */ | \
(1U << 31U) /* IR191, IER23.IEN7 bit, IPR191, DTCER191, SLIR191 */)
#endif

#ifndef BSP_PZ_CFG_ICU0SAR6
#define BSP_PZ_CFG_ICU0SAR6 (\
(1U << 0U) /* IR192, IER24.IEN0 bit, IPR192, DTCER192, SLIR192 */ | \
(1U << 1U) /* IR193, IER24.IEN1 bit, IPR193, DTCER193, SLIR193 */ | \
(1U << 2U) /* IR194, IER24.IEN2 bit, IPR194, DTCER194, SLIR194 */ | \
(1U << 3U) /* IR195, IER24.IEN3 bit, IPR195, DTCER195, SLIR195 */ | \
(1U << 4U) /* IR196, IER24.IEN4 bit, IPR196, DTCER196, SLIR196 */ | \
(1U << 5U) /* IR197, IER24.IEN5 bit, IPR197, DTCER197, SLIR197 */ | \
(1U << 6U) /* IR198, IER24.IEN6 bit, IPR198, DTCER198, SLIR198 */ | \
(1U << 7U) /* IR199, IER24.IEN7 bit, IPR199, DTCER199, SLIR199 */ | \
(1U << 8U) /* IR200, IER25.IEN0 bit, IPR200, DTCER200, SLIR200 */ | \
(1U << 9U) /* IR201, IER25.IEN1 bit, IPR201, DTCER201, SLIR201 */ | \
(1U << 10U) /* IR202, IER25.IEN2 bit, IPR202, DTCER202, SLIR202 */ | \
(1U << 11U) /* IR203, IER25.IEN3 bit, IPR203, DTCER203, SLIR203 */ | \
(1U << 12U) /* IR204, IER25.IEN4 bit, IPR204, DTCER204, SLIR204 */ | \
(1U << 13U) /* IR205, IER25.IEN5 bit, IPR205, DTCER205, SLIR205 */ | \
(1U << 14U) /* IR206, IER25.IEN6 bit, IPR206, DTCER206, SLIR206 */ | \
(1U << 15U) /* IR207, IER25.IEN7 bit, IPR207, DTCER207, SLIR207 */ | \
(1U << 16U) /* IR208, IER26.IEN0 bit, IPR208, DTCER208, SLIR208 */ | \
(1U << 17U) /* IR209, IER26.IEN1 bit, IPR209, DTCER209, SLIR209 */ | \
(1U << 18U) /* IR210, IER26.IEN2 bit, IPR210, DTCER210, SLIR210 */ | \
(1U << 19U) /* IR211, IER26.IEN3 bit, IPR211, DTCER211, SLIR211 */ | \
(1U << 20U) /* IR212, IER26.IEN4 bit, IPR212, DTCER212, SLIR212 */ | \
(1U << 21U) /* IR213, IER26.IEN5 bit, IPR213, DTCER213, SLIR213 */ | \
(1U << 22U) /* IR214, IER26.IEN6 bit, IPR214, DTCER214, SLIR214 */ | \
(1U << 23U) /* IR215, IER26.IEN7 bit, IPR215, DTCER215, SLIR215 */ | \
(1U << 24U) /* IR216, IER27.IEN0 bit, IPR216, DTCER216, SLIR216 */ | \
(1U << 25U) /* IR217, IER27.IEN1 bit, IPR217, DTCER217, SLIR217 */ | \
(1U << 26U) /* IR218, IER27.IEN2 bit, IPR218, DTCER218, SLIR218 */ | \
(1U << 27U) /* IR219, IER27.IEN3 bit, IPR219, DTCER219, SLIR219 */ | \
(1U << 28U) /* IR220, IER27.IEN4 bit, IPR220, DTCER220, SLIR220 */ | \
(1U << 29U) /* IR221, IER27.IEN5 bit, IPR221, DTCER221, SLIR221 */ | \
(1U << 30U) /* IR222, IER27.IEN6 bit, IPR222, DTCER222, SLIR222 */ | \
(1U << 31U) /* IR223, IER27.IEN7 bit, IPR223, DTCER223, SLIR223 */)
#endif

#ifndef BSP_PZ_CFG_ICU0SAR7
#define BSP_PZ_CFG_ICU0SAR7 (\
(1U << 0U) /* IR224, IER28.IEN0 bit, IPR224, DTCER224, SLIR224 */ | \
(1U << 1U) /* IR225, IER28.IEN1 bit, IPR225, DTCER225, SLIR225 */ | \
(1U << 2U) /* IR226, IER28.IEN2 bit, IPR226, DTCER226, SLIR226 */ | \
(1U << 3U) /* IR227, IER28.IEN3 bit, IPR227, DTCER227, SLIR227 */ | \
(1U << 4U) /* IR228, IER28.IEN4 bit, IPR228, DTCER228, SLIR228 */ | \
(1U << 5U) /* IR229, IER28.IEN5 bit, IPR229, DTCER229, SLIR229 */ | \
(1U << 6U) /* IR230, IER28.IEN6 bit, IPR230, DTCER230, SLIR230 */ | \
(1U << 7U) /* IR231, IER28.IEN7 bit, IPR231, DTCER231, SLIR231 */ | \
(1U << 8U) /* IR232, IER29.IEN0 bit, IPR232, DTCER232, SLIR232 */ | \
(1U << 9U) /* IR233, IER29.IEN1 bit, IPR233, DTCER233, SLIR233 */ | \
(1U << 10U) /* IR234, IER29.IEN2 bit, IPR234, DTCER234, SLIR234 */ | \
(1U << 11U) /* IR235, IER29.IEN3 bit, IPR235, DTCER235, SLIR235 */ | \
(1U << 12U) /* IR236, IER29.IEN4 bit, IPR236, DTCER236, SLIR236 */ | \
(1U << 13U) /* IR237, IER29.IEN5 bit, IPR237, DTCER237, SLIR237 */ | \
(1U << 14U) /* IR238, IER29.IEN6 bit, IPR238, DTCER238, SLIR238 */ | \
(1U << 15U) /* IR239, IER29.IEN7 bit, IPR239, DTCER239, SLIR239 */ | \
(1U << 16U) /* IR240, IER30.IEN0 bit, IPR240, DTCER240, SLIR240 */ | \
(1U << 17U) /* IR241, IER30.IEN1 bit, IPR241, DTCER241, SLIR241 */ | \
(1U << 18U) /* IR242, IER30.IEN2 bit, IPR242, DTCER242, SLIR242 */ | \
(1U << 19U) /* IR243, IER30.IEN3 bit, IPR243, DTCER243, SLIR243 */ | \
(1U << 20U) /* IR244, IER30.IEN4 bit, IPR244, DTCER244, SLIR244 */ | \
(1U << 21U) /* IR245, IER30.IEN5 bit, IPR245, DTCER245, SLIR245 */ | \
(1U << 22U) /* IR246, IER30.IEN6 bit, IPR246, DTCER246, SLIR246 */ | \
(1U << 23U) /* IR247, IER30.IEN7 bit, IPR247, DTCER247, SLIR247 */ | \
(1U << 24U) /* IR248, IER31.IEN0 bit, IPR248, DTCER248, SLIR248 */ | \
(1U << 25U) /* IR249, IER31.IEN1 bit, IPR249, DTCER249, SLIR249 */ | \
(1U << 26U) /* IR250, IER31.IEN2 bit, IPR250, DTCER250, SLIR250 */ | \
(1U << 27U) /* IR251, IER31.IEN3 bit, IPR251, DTCER251, SLIR251 */ | \
(1U << 28U) /* IR252, IER31.IEN4 bit, IPR252, DTCER252, SLIR252 */ | \
(1U << 29U) /* IR253, IER31.IEN5 bit, IPR253, DTCER253, SLIR253 */ | \
(1U << 30U) /* IR254, IER31.IEN6 bit, IPR254, DTCER254, SLIR254 */ | \
(1U << 31U) /* IR255, IER31.IEN7 bit, IPR255, DTCER255, SLIR255 */)
#endif

/* Security attribution register for ELCR、ELSEGR0 to ELSEGR3、ELOPA to ELOPD Security Attribution. */
#ifndef BSP_PZ_CFG_ELCSARA
#define BSP_PZ_CFG_ELCSARA (\
 (0x0000001FU) | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 16) /* ELOPA Security Attribution */ | \
(((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 17) /* ELOPB Security Attribution */ | \
((((FSP_NOT_DEFINED > 0) || (FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 18)  /* ELOPC Security Attribution */ | \
((((FSP_NOT_DEFINED > 0) || (FSP_NOT_DEFINED > 0)) ? 0U : 1U) << 19)  /* ELOPD Security Attribution */)
#endif

/* Security attribute settings for MRAM registers. */
#ifndef BSP_PZ_CFG_MSAR
#define BSP_PZ_CFG_MSAR (\
((BSP_CFG_CLOCKS_SECURE == 0) ? (1U << 1) : 0U) | /* MREFREQ */\
((BSP_CFG_CLOCKS_SECURE == 0) ? (1U << 3) : 0U) /* MRCFREQ */)
#endif

/* Security attribution for SRAM registers. */
#ifndef BSP_PZ_CFG_SRAMSAR
/* If the CGC registers are only accessible in Secure mode, than there is no reason for Non Secure applications to access
 * SRAMWTSC and therefore there is no reason to access SRAMPRCR. */
#define BSP_PZ_CFG_SRAMSAR (\
((1U) << 0U) | /* SRAMSA0 */\
((1U) << 1U) | /* SRAMSA1 */\
((BSP_CFG_CLOCKS_SECURE == 0) ? (1U << 8U) : 0U) /* SRAMWTSA */)
#endif

/* Security attribution for LRAM registers. */
#ifndef BSP_PZ_CFG_LRMSAR
#define BSP_PZ_CFG_LRMSAR (1U)
#endif

/* Security attribution for MMPUOAD and MMPUOADPT registers */
#ifndef BSP_PZ_CFG_MMPUSARB
#define BSP_PZ_CFG_MMPUSARB (0x00000000U)
#endif

/* Security Attribution Register A for BUS Control registers. */
#ifndef BSP_PZ_CFG_BUSSARA
#define BSP_PZ_CFG_BUSSARA (1U)
#endif

/* Security Attribution Register B for BUS Control registers. */
#ifndef BSP_PZ_CFG_BUSSARB
#define BSP_PZ_CFG_BUSSARB (1U)
#endif

/* Security Attribution Register C for BUS Control registers. */
#ifndef BSP_PZ_CFG_BUSSARC
#define BSP_PZ_CFG_BUSSARC (1U)
#endif

/* Set DTCSAR if the Secure program uses the DTC. */
#if FSP_NOT_DEFINED == FSP_NOT_DEFINED
#define BSP_PZ_CFG_DTC_USED (0U)
#else
#define BSP_PZ_CFG_DTC_USED (1U)
#endif

/* Trust Event Route Control Registers for SLIXRn, SLIRn, DMRSRm, and ELC.ELSRn. */
#ifndef BSP_PZ_CFG_TEVTRCR
#define BSP_PZ_CFG_TEVTRCR (0)
#endif

/* Security attribution for EXDMAC channel regisgers */
#ifndef BSP_PZ_CFG_EXDMACCHSAR
#define BSP_PZ_CFG_EXDMACCHSAR (\
            (((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 0U) /* EXDMAC Channel 0 */ | \
            (((FSP_NOT_DEFINED > 0) ? 0U : 1U) << 1U) /* EXDMAC Channel 1 */)

#endif

/* Enable Uninitialized Non-Secure Application Fallback. */
#ifndef BSP_PZ_CFG_NON_SECURE_APPLICATION_FALLBACK
#define BSP_PZ_CFG_NON_SECURE_APPLICATION_FALLBACK (1U)
#endif
#endif /* BSP_MCU_FAMILY_CFG_H_ */
