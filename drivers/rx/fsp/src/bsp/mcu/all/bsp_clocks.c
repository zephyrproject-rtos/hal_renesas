/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_clocks.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Key code for writing PRCR register. */
#define BSP_PRV_PRCR_KEY                        (0xA500U)
#define BSP_PRV_PRCR_UNLOCK                     ((BSP_PRV_PRCR_KEY) | 0x3U)
#define BSP_PRV_PRCR_LOCK                       ((BSP_PRV_PRCR_KEY) | 0x0U)

/* Wait state definitions for MCUS with SRAMWTSC. */
#define BSP_PRV_SRAMWTSC_WAIT_CYCLES_DISABLE    (0U)
#define BSP_PRV_SRAM_UNLOCK                     (((BSP_FEATURE_CGC_SRAMPRCR_KW_VALUE) << \
                                                  BSP_FEATURE_CGC_SRAMPRCR_KW_OFFSET) | 0x1U)
#define BSP_PRV_SRAM_LOCK                       (((BSP_FEATURE_CGC_SRAMPRCR_KW_VALUE) << \
                                                  BSP_FEATURE_CGC_SRAMPRCR_KW_OFFSET) | 0x0U)

/* Determine whether SRAM wait states should be enabled */
#if BSP_STARTUP_ICLK_HZ <= BSP_FEATURE_BSP_SYS_CLOCK_FREQ_NO_RAM_WAITS
 #define BSP_PRV_SRAM_WAIT_CYCLES               BSP_PRV_SRAMWTSC_WAIT_CYCLES_DISABLE
#else
 #define BSP_PRV_SRAM_WAIT_CYCLES               BSP_FEATURE_SRAM_SRAMWTSC_WAIT_CYCLE_ENABLE
#endif

/* Calculate value to write to MOMCR/CMC (MODRV controls main clock drive strength and MOSEL determines the source of the
 * main oscillator). */
#if defined(BSP_CFG_MAIN_OSC_MODRV0) && (BSP_CFG_MAIN_OSC_MODRV0 != 0xFFU)
 #define BSP_PRV_MODRV                          ((BSP_CFG_MAIN_OSC_MODRV0 << BSP_FEATURE_CGC_MODRV_SHIFT) & \
                                                 BSP_FEATURE_CGC_MODRV_MASK)
#else
 #if BSP_FEATURE_CGC_MODRV_MASK
  #define BSP_PRV_MODRV                         ((CGC_MAINCLOCK_DRIVE << BSP_FEATURE_CGC_MODRV_SHIFT) & \
                                                 BSP_FEATURE_CGC_MODRV_MASK)
 #endif
#endif

#define BSP_PRV_MOSEL                           (BSP_CLOCK_CFG_MAIN_OSC_CLOCK_SOURCE << R_SYSTEM_MOMCR_MOSEL_Pos)
#define BSP_PRV_MOMCR                           (BSP_PRV_MODRV | BSP_PRV_MOSEL)

/* Locations of bitfields used to configure CLKOUT. */
#define BSP_PRV_CKOCR_CKODIV_BIT                (4U)
#define BSP_PRV_CKOCR_CKOEN_BIT                 (7U)

/* Stop interval of at least 5 SOSC clock cycles between stop and restart of SOSC.
 * Calculated based on 8Mhz of MOCO clock. */
#define BSP_PRV_SUBCLOCK_STOP_INTERVAL_US       (200U)

/* Locations of bitfields used to configure Peripheral Clocks. */
#define BSP_PRV_PERIPHERAL_CLK_REQ_BIT_POS      (6U)
#define BSP_PRV_PERIPHERAL_CLK_REQ_BIT_MASK     (1U << BSP_PRV_PERIPHERAL_CLK_REQ_BIT_POS)
#define BSP_PRV_PERIPHERAL_CLK_RDY_BIT_POS      (7U)
#define BSP_PRV_PERIPHERAL_CLK_RDY_BIT_MASK     (1U << BSP_PRV_PERIPHERAL_CLK_RDY_BIT_POS)

#ifdef BSP_CFG_UCLK_DIV

/* If the MCU has SCKDIVCR2 for USBCK configuration. */
 #if !BSP_FEATURE_BSP_HAS_USBCKDIVCR

/* Location of bitfield used to configure USB clock divider. */
  #define BSP_PRV_SCKDIVCR2_UCLK_BIT    (4U)
  #define BSP_PRV_UCLK_DIV              (BSP_CFG_UCLK_DIV)

/* If the MCU has USBCKDIVCR. */
 #elif BSP_FEATURE_BSP_HAS_USBCKDIVCR
  #if BSP_CLOCKS_USB_CLOCK_DIV_1 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (0U)
  #elif BSP_CLOCKS_USB_CLOCK_DIV_2 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (1U)
  #elif BSP_CLOCKS_USB_CLOCK_DIV_3 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (5U)
  #elif BSP_CLOCKS_USB_CLOCK_DIV_4 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (2U)
  #elif BSP_CLOCKS_USB_CLOCK_DIV_5 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (6U)
  #elif BSP_CLOCKS_USB_CLOCK_DIV_6 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (3U)
  #elif BSP_CLOCKS_USB_CLOCK_DIV_8 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (4U)
  #elif BSP_CLOCKS_USB_CLOCK_DIV_10 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (7U)
  #elif BSP_CLOCKS_USB_CLOCK_DIV_16 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (8U)
  #elif BSP_CLOCKS_USB_CLOCK_DIV_32 == BSP_CFG_UCLK_DIV
   #define BSP_PRV_UCLK_DIV             (9U)
  #else

   #error "BSP_CFG_UCLK_DIV not supported."

  #endif
 #endif
#endif

/* Choose the value to write to FLLCR2 (if applicable). */
#if BSP_PRV_HOCO_USE_FLL
 #if 1U == BSP_CFG_HOCO_FREQUENCY
  #define BSP_PRV_FLL_FLLCR2                     (0x225U)
 #elif 2U == BSP_CFG_HOCO_FREQUENCY
  #define BSP_PRV_FLL_FLLCR2                     (0x262U)
 #else

/* When BSP_CFG_HOCO_FREQUENCY is 0, 4, 7 */
  #define BSP_PRV_FLL_FLLCR2                     (0x1E8U)
 #endif
#endif

/* Calculate the value to write to SCKDIVCR. */
#define BSP_PRV_STARTUP_SCKDIVCR_ICLK_BITS       ((BSP_CFG_ICLK_DIV & 0xFU) << 24U)
#define BSP_PRV_STARTUP_SCKDIVCR_PCLKE_BITS      ((BSP_CFG_PCLKE_DIV & 0xFU) << 20U)
#define BSP_PRV_STARTUP_SCKDIVCR_PCLKD_BITS      (BSP_CFG_PCLKD_DIV & 0xFU)
#define BSP_PRV_STARTUP_SCKDIVCR_PCLKC_BITS      ((BSP_CFG_PCLKC_DIV & 0xFU) << 4U)
#define BSP_PRV_STARTUP_SCKDIVCR_PCLKB_BITS      ((BSP_CFG_PCLKB_DIV & 0xFU) << 8U)
#define BSP_PRV_STARTUP_SCKDIVCR_PCLKA_BITS      ((BSP_CFG_PCLKA_DIV & 0xFU) << 12U)
#define BSP_PRV_STARTUP_SCKDIVCR_BCLK_BITS       ((BSP_CFG_BCLK_DIV & 0xFU) << 16U)
#define BSP_PRV_STARTUP_SCKDIVCR_MRPCLK_BITS     ((BSP_CFG_FCLK_DIV & 0xFU) << 28U)
#define BSP_PRV_STARTUP_SCKDIVCR                 (BSP_PRV_STARTUP_SCKDIVCR_ICLK_BITS |  \
                                                  BSP_PRV_STARTUP_SCKDIVCR_PCLKE_BITS | \
                                                  BSP_PRV_STARTUP_SCKDIVCR_PCLKD_BITS | \
                                                  BSP_PRV_STARTUP_SCKDIVCR_PCLKC_BITS | \
                                                  BSP_PRV_STARTUP_SCKDIVCR_PCLKB_BITS | \
                                                  BSP_PRV_STARTUP_SCKDIVCR_PCLKA_BITS | \
                                                  BSP_PRV_STARTUP_SCKDIVCR_BCLK_BITS |  \
                                                  BSP_PRV_STARTUP_SCKDIVCR_MRPCLK_BITS)

/* Key codes for MRAM registers. */
#define BSP_PRV_MRCFREQ_KEY                      (0x1E000000)
#define BSP_PRV_MREFREQ_KEY                      (0xE1000000)
#define BSP_PRV_MRFREQ_MIN_HZ                    (32768)

#define BSP_PRV_STARTUP_SCKDIVCR2_CPUCK_BITS     (BSP_CFG_CPUCLK_DIV & 0xFU)
#define BSP_PRV_STARTUP_SCKDIVCR2_MRICLK_BITS    ((BSP_CFG_MRICLK_DIV & 0xFU) << 12U)
#define BSP_PRV_STARTUP_SCKDIVCR2                (BSP_PRV_STARTUP_SCKDIVCR2_CPUCK_BITS | \
                                                  BSP_PRV_STARTUP_SCKDIVCR2_MRICLK_BITS)

/* The number of clocks is used to size the g_clock_freq array. */
#if BSP_PRV_PLL2_SUPPORTED
 #define BSP_PRV_NUM_CLOCKS                      ((uint8_t) BSP_CLOCKS_SOURCE_CLOCK_PLL2 +       \
                                                  (BSP_FEATURE_CGC_PLL1_NUM_OUTPUT_CLOCKS - 1) + \
                                                  BSP_FEATURE_CGC_PLL2_NUM_OUTPUT_CLOCKS)
#elif BSP_PRV_PLL_SUPPORTED
 #define BSP_PRV_NUM_CLOCKS                      ((uint8_t) BSP_CLOCKS_SOURCE_CLOCK_PLL + \
                                                  BSP_FEATURE_CGC_PLL1_NUM_OUTPUT_CLOCKS)
#else
 #define BSP_PRV_NUM_CLOCKS                      ((uint8_t) BSP_CLOCKS_SOURCE_CLOCK_SUBCLOCK + 1U)
#endif

/* Calculate PLLCCR value. */
#if BSP_PRV_PLL_SUPPORTED
 #if BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC == BSP_CFG_PLL_SOURCE
  #define BSP_PRV_PLSRCSEL                         (0)
  #define BSP_PRV_PLL_USED                         (1)
 #elif BSP_CLOCKS_SOURCE_CLOCK_HOCO == BSP_CFG_PLL_SOURCE
  #define BSP_PRV_PLSRCSEL                         (1)
  #define BSP_PRV_PLL_USED                         (1)
 #else
  #define BSP_PRV_PLL_USED                         (0)
 #endif

 #define BSP_PRV_PLL_MUL_CFG_MACRO_PLLMUL_MASK     (0x7FFU)
 #define BSP_PRV_PLLCCR_PLLMULNF_BIT               (6) // PLLMULNF in PLLCCR starts at bit 6
 #define BSP_PRV_PLLCCR_PLSRCSEL_BIT               (4) // PLSRCSEL in PLLCCR starts at bit 4
 #define BSP_PRV_PLLCCR                            ((((BSP_CFG_PLL_MUL & BSP_PRV_PLL_MUL_CFG_MACRO_PLLMUL_MASK) << \
                                                      BSP_PRV_PLLCCR_PLLMULNF_BIT) |                               \
                                                     (BSP_PRV_PLSRCSEL << BSP_PRV_PLLCCR_PLSRCSEL_BIT)) |          \
                                                    BSP_CFG_PLL_DIV)
 #define BSP_PRV_PLLCCR2_PLL_DIV_MASK              (0x0F) // PLL DIV in PLLCCR2/PLL2CCR2 is 4 bits wide
 #define BSP_PRV_PLLCCR2_PLL_DIV_Q_BIT             (4)    // PLL DIV Q in PLLCCR2/PLL2CCR2 starts at bit 4
 #define BSP_PRV_PLLCCR2_PLL_DIV_R_BIT             (8)    // PLL DIV R in PLLCCR2/PLL2CCR2 starts at bit 8
 #define BSP_PRV_PLLCCR2                           (((BSP_CFG_PLODIVR & BSP_PRV_PLLCCR2_PLL_DIV_MASK) << \
                                                     BSP_PRV_PLLCCR2_PLL_DIV_R_BIT) |                    \
                                                    ((BSP_CFG_PLODIVQ & BSP_PRV_PLLCCR2_PLL_DIV_MASK) << \
                                                     BSP_PRV_PLLCCR2_PLL_DIV_Q_BIT) |                    \
                                                    (BSP_CFG_PLODIVP & BSP_PRV_PLLCCR2_PLL_DIV_MASK))
#endif

#if BSP_FEATURE_CGC_HAS_PLL2
 #if BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC == BSP_CFG_PLL2_SOURCE
  #define BSP_PRV_PL2SRCSEL                        (0)
  #define BSP_PRV_PLL2_USED                        (1)
 #elif BSP_CLOCKS_SOURCE_CLOCK_HOCO == BSP_CFG_PLL2_SOURCE
  #define BSP_PRV_PL2SRCSEL                        (1)
  #define BSP_PRV_PLL2_USED                        (1)
 #else
  #define BSP_PRV_PLL2_USED                        (0)
 #endif

 #define BSP_PRV_PLL2_MUL_CFG_MACRO_PLLMUL_MASK    (0x7FF)
 #define BSP_PRV_PLL2CCR_PLLMULNF_BIT              (6) // PLLMULNF in PLLCCR starts at bit 6
 #define BSP_PRV_PLL2CCR_PLSRCSEL_BIT              (4) // PLSRCSEL in PLLCCR starts at bit 4
 #define BSP_PRV_PLL2CCR                           ((((BSP_CFG_PLL2_MUL & BSP_PRV_PLL2_MUL_CFG_MACRO_PLLMUL_MASK) << \
                                                      BSP_PRV_PLL2CCR_PLLMULNF_BIT) |                                \
                                                     (BSP_PRV_PL2SRCSEL << BSP_PRV_PLL2CCR_PLSRCSEL_BIT)) |          \
                                                    BSP_CFG_PLL2_DIV)
 #define BSP_PRV_PLL2CCR2_PLL_DIV_MASK             (0x0F) // PLL DIV in PLL2CCR2 is 4 bits wide
 #define BSP_PRV_PLL2CCR2_PLL_DIV_Q_BIT            (4)    // PLL DIV Q in PLL2CCR2 starts at bit 4
 #define BSP_PRV_PLL2CCR2_PLL_DIV_R_BIT            (8)    // PLL DIV R in PLL2CCR2 starts at bit 8
 #define BSP_PRV_PLL2CCR2                          (((BSP_CFG_PL2ODIVR & BSP_PRV_PLL2CCR2_PLL_DIV_MASK) << \
                                                     BSP_PRV_PLL2CCR2_PLL_DIV_R_BIT) |                     \
                                                    ((BSP_CFG_PL2ODIVQ & BSP_PRV_PLL2CCR2_PLL_DIV_MASK) << \
                                                     BSP_PRV_PLL2CCR2_PLL_DIV_Q_BIT) |                     \
                                                    (BSP_CFG_PL2ODIVP & BSP_PRV_PLL2CCR2_PLL_DIV_MASK))
#endif

/* All clocks with configurable source except PLL and CLKOUT can use PLL. */
#if (BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_PLL)
 #define BSP_PRV_STABILIZE_PLL                     (1)
#endif

/* All clocks with configurable source can use the main oscillator. */
#if (BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
 #define BSP_PRV_STABILIZE_MAIN_OSC                (1)
#elif defined(BSP_CFG_UCLK_SOURCE) && BSP_FEATURE_BSP_HAS_USB_CLOCK_REQ && \
    (BSP_CFG_UCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_PLL_SOURCE) && (BSP_CFG_PLL_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC) && BSP_PRV_PLL_USED
 #define BSP_PRV_MAIN_OSC_USED                     (1)
 #define BSP_PRV_STABILIZE_MAIN_OSC                (1)
#elif defined(BSP_CFG_PLL2_SOURCE) && (BSP_CFG_PLL2_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC) && BSP_PRV_PLL2_USED
 #define BSP_PRV_MAIN_OSC_USED                     (1)
 #define BSP_PRV_STABILIZE_MAIN_OSC                (1)
#elif defined(BSP_CFG_CLKOUT_SOURCE) && (BSP_CFG_CLKOUT_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_SPICLK_SOURCE) && (BSP_CFG_SPICLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_SCICLK_SOURCE) && (BSP_CFG_SCICLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_CANFDCLK_SOURCE) && (BSP_CFG_CANFDCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_GPTCLK_SOURCE) && (BSP_CFG_GPTCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_USB60CLK_SOURCE) && (BSP_CFG_USB60CLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_OCTA_SOURCE) && (BSP_CFG_OCTA_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_ADCCLK_SOURCE) && (BSP_CFG_ADCCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_ESWCLK_SOURCE) && (BSP_CFG_ESWCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_ESWPHYCLK_SOURCE) && (BSP_CFG_ESWPHYCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_ESCCLK_SOURCE) && (BSP_CFG_ESCCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_ETHPHYCLK_SOURCE) && (BSP_CFG_ETHPHYCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_DSMIFCLK_SOURCE) && (BSP_CFG_DSMIFCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#elif defined(BSP_CFG_BCLKA_SOURCE) && (BSP_CFG_BCLKA_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
 #define BSP_PRV_MAIN_OSC_USED                     (1)
#else
 #define BSP_PRV_MAIN_OSC_USED                     (0)
#endif

/* All clocks with configurable source can use HOCO except the I3CCLK. */
#if (BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
 #define BSP_PRV_STABILIZE_HOCO                    (1)
#elif defined(BSP_CFG_PLL_SOURCE) && (BSP_CFG_PLL_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO) && BSP_PRV_PLL_USED
 #define BSP_PRV_HOCO_USED                         (1)
 #define BSP_PRV_STABILIZE_HOCO                    (1)
#elif defined(BSP_CFG_PLL2_SOURCE) && (BSP_CFG_PLL2_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO) && BSP_PRV_PLL2_USED
 #define BSP_PRV_HOCO_USED                         (1)
 #define BSP_PRV_STABILIZE_HOCO                    (1)
#elif defined(BSP_CFG_UCLK_SOURCE) && BSP_FEATURE_BSP_HAS_USB_CLOCK_REQ && \
    (BSP_CFG_UCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_CLKOUT_SOURCE) && (BSP_CFG_CLKOUT_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_SPICLK_SOURCE) && (BSP_CFG_SPICLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_SCICLK_SOURCE) && (BSP_CFG_SCICLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_CANFDCLK_SOURCE) && (BSP_CFG_CANFDCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_GPTCLK_SOURCE) && (BSP_CFG_GPTCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_USB60CLK_SOURCE) && (BSP_CFG_USB60CLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_OCTA_SOURCE) && (BSP_CFG_OCTA_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_ADCCLK_SOURCE) && (BSP_CFG_ADCCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_ESWCLK_SOURCE) && (BSP_CFG_ESWCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_ESWPHYCLK_SOURCE) && (BSP_CFG_ESWPHYCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_ESCCLK_SOURCE) && (BSP_CFG_ESCCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_ETHPHYCLK_SOURCE) && (BSP_CFG_ETHPHYCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_DSMIFCLK_SOURCE) && (BSP_CFG_DSMIFCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#elif defined(BSP_CFG_BCLKA_SOURCE) && (BSP_CFG_BCLKA_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_HOCO)
 #define BSP_PRV_HOCO_USED                         (1)
#else
 #define BSP_PRV_HOCO_USED                         (0)
#endif

/* All clocks with configurable source except PLL can use MOCO. */
#if (BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
 #define BSP_PRV_STABILIZE_MOCO                    (1)
#elif defined(BSP_CFG_CLKOUT_SOURCE) && (BSP_CFG_CLKOUT_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_UCLK_SOURCE) && BSP_FEATURE_BSP_HAS_USB_CLOCK_REQ && \
    (BSP_CFG_UCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_SPICLK_SOURCE) && (BSP_CFG_SPICLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_SCICLK_SOURCE) && (BSP_CFG_SCICLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_CANFDCLK_SOURCE) && (BSP_CFG_CANFDCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_GPTCLK_SOURCE) && (BSP_CFG_GPTCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_I3CCLK_SOURCE) && (BSP_CFG_I3CCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_USB60CLK_SOURCE) && (BSP_CFG_USB60CLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_OCTA_SOURCE) && (BSP_CFG_OCTA_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_ADCCLK_SOURCE) && (BSP_CFG_ADCCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_ESWCLK_SOURCE) && (BSP_CFG_ESWCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_ESWPHYCLK_SOURCE) && (BSP_CFG_ESWPHYCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_ESCCLK_SOURCE) && (BSP_CFG_ESCCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_ETHPHYCLK_SOURCE) && (BSP_CFG_ETHPHYCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_DSMIFCLK_SOURCE) && (BSP_CFG_DSMIFCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#elif defined(BSP_CFG_BCLKA_SOURCE) && (BSP_CFG_BCLKA_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_MOCO)
 #define BSP_PRV_MOCO_USED                         (1)
#else
 #define BSP_PRV_MOCO_USED                         (0)
#endif

/* All clocks with configurable source except USBCLK, CANFD, LCDCLK, USBHSCLK, I3CCLK and PLL can use LOCO. */
#if (BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_LOCO)
 #define BSP_PRV_LOCO_USED                         (1)
 #define BSP_PRV_STABILIZE_LOCO                    (1)
#elif defined(BSP_CFG_CLKOUT_SOURCE) && (BSP_CFG_CLKOUT_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_LOCO)
 #define BSP_PRV_LOCO_USED                         (1)
#elif defined(BSP_CFG_SPICLK_SOURCE) && (BSP_CFG_SPICLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_LOCO)
 #define BSP_PRV_LOCO_USED                         (1)
#elif defined(BSP_CFG_SCICLK_SOURCE) && (BSP_CFG_SCICLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_LOCO)
 #define BSP_PRV_LOCO_USED                         (1)
#elif defined(BSP_CFG_CANFDCLK_SOURCE) && (BSP_CFG_CANFDCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_LOCO)
 #define BSP_PRV_LOCO_USED                         (1)
#elif defined(BSP_CFG_GPTCLK_SOURCE) && (BSP_CFG_GPTCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_LOCO)
 #define BSP_PRV_LOCO_USED                         (1)
#elif defined(BSP_CFG_OCTA_SOURCE) && (BSP_CFG_OCTA_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_LOCO)
 #define BSP_PRV_LOCO_USED                         (1)
#elif defined(BSP_CFG_ADCCLK_SOURCE) && (BSP_CFG_ADCCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_LOCO)
 #define BSP_PRV_LOCO_USED                         (1)
#elif ((defined(BSP_CFG_RTCSCLK_ENABLE) && (BSP_CFG_RTCSCLK_ENABLE == 0)) ||                   \
    (defined(BSP_CLOCK_CFG_SUBCLOCK_POPULATED) && (BSP_CLOCK_CFG_SUBCLOCK_POPULATED == 0))) && \
    (BSP_FEATURE_CGC_HAS_SOSC == 1U)
 #define BSP_PRV_LOCO_USED                         (1)
#else
 #define BSP_PRV_LOCO_USED                         (0)
#endif

/* Determine the optimal operating speed mode to apply after clock configuration based on the startup clock
 * frequency. */
#if BSP_STARTUP_ICLK_HZ <= BSP_FEATURE_CGC_LOW_SPEED_MAX_FREQ_HZ && \
    !BSP_PRV_PLL_USED && !BSP_PRV_PLL2_USED
 #define BSP_PRV_STARTUP_OPERATING_MODE            (BSP_PRV_OPERATING_MODE_LOW_SPEED)
#else
 #define BSP_PRV_STARTUP_OPERATING_MODE            (BSP_PRV_OPERATING_MODE_HIGH_SPEED)
#endif

#if BSP_FEATURE_BSP_HAS_CLOCK_SUPPLY_TYPEB
 #define BSP_PRV_CLOCK_SUPPLY_TYPE_B               (0 == BSP_CFG_ROM_REG_OFS1_ICSATS)
#else
 #define BSP_PRV_CLOCK_SUPPLY_TYPE_B               (0)
#endif

#if (BSP_FEATURE_BSP_HAS_CANFD_CLOCK && (BSP_CFG_CANFDCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED) &&    \
    (BSP_CFG_CANFDCLK_SOURCE != BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)) ||                                \
    (BSP_FEATURE_BSP_HAS_SCI_CLOCK && (BSP_CFG_SCICLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) ||       \
    (BSP_FEATURE_BSP_HAS_SPI_CLOCK && (BSP_CFG_SPICLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) ||       \
    (BSP_PERIPHERAL_GPT_GTCLK_PRESENT && (BSP_CFG_GPTCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) ||    \
    (BSP_FEATURE_BSP_HAS_I3C_CLOCK && (BSP_CFG_I3CCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) ||       \
    (BSP_FEATURE_BSP_HAS_USB60_CLOCK && (BSP_CFG_USB60CLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) ||   \
    (BSP_FEATURE_BSP_HAS_ADC_CLOCK && (BSP_CFG_ADCCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) ||       \
    (BSP_FEATURE_BSP_HAS_ESW_CLOCK && (BSP_CFG_ESWCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) ||       \
    (BSP_FEATURE_BSP_HAS_ESWPHY_CLOCK && (BSP_CFG_ESWPHYCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) || \
    (BSP_FEATURE_BSP_HAS_ESC_CLOCK && (BSP_CFG_ESCCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) ||       \
    (BSP_FEATURE_BSP_HAS_ETHPHY_CLOCK && (BSP_CFG_ETHPHYCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) || \
    (BSP_FEATURE_BSP_HAS_DSMIF_CLOCK && (BSP_CFG_DSMIFCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)) ||   \
    (defined(BSP_CFG_BCLKA_SOURCE) && (BSP_CFG_BCLKA_SOURCE != BSP_CLOCKS_CLOCK_DISABLED))

 #define BSP_PRV_HAS_ENABLED_PERIPHERAL_CLOCKS     (1U)
#else
 #define BSP_PRV_HAS_ENABLED_PERIPHERAL_CLOCKS     (0U)
#endif

#define BSP_PRV_HZ_PER_MHZ                         (1000000)

#if BSP_FEATURE_RTC_IS_AVAILABLE || BSP_FEATURE_RTC_HAS_TCEN || BSP_FEATURE_SYSC_HAS_TAMPICR1
 #define BSP_PRV_RTC_ALM_IRQ                       ((IRQn_Type) ICU_EVENT_FIXED_RTC_ALARM)
 #define BSP_PRV_RTC_PRD_IRQ                       ((IRQn_Type) ICU_EVENT_FIXED_RTC_PERIOD)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

static uint8_t bsp_clock_set_prechange(uint32_t requested_freq_hz);
static void    bsp_clock_set_postchange(uint32_t updated_freq_hz, uint8_t new_rom_wait_state);

#if !BSP_CFG_USE_LOW_VOLTAGE_MODE && BSP_FEATURE_CGC_HAS_OPCCR
static void bsp_prv_operating_mode_opccr_set(uint8_t operating_mode);

#endif
void prv_clock_dividers_set(uint32_t sckdivcr, uint16_t sckdivcr2);

static void bsp_prv_sosc_init(void);

#if BSP_CLOCK_CFG_SUBCLOCK_POPULATED
 #if defined(__ICCRX__)

void R_BSP_SubClockStabilizeWait(uint32_t delay_ms);
void R_BSP_SubClockStabilizeWaitAfterReset(uint32_t delay_ms);

  #pragma weak R_BSP_SubClockStabilizeWait
  #pragma weak R_BSP_SubClockStabilizeWaitAfterReset

 #elif defined(__GNUC__) || defined(__CCRX__)

void R_BSP_SubClockStabilizeWait(uint32_t delay_ms) __attribute__((weak));
void R_BSP_SubClockStabilizeWaitAfterReset(uint32_t delay_ms) __attribute__((weak));

 #endif
#endif

#if (BSP_PRV_HAS_ENABLED_PERIPHERAL_CLOCKS == 1U)
static void bsp_peripheral_clock_set(volatile uint8_t * p_clk_ctrl_reg,
                                     volatile uint8_t * p_clk_div_reg,
                                     uint8_t            peripheral_clk_div,
                                     uint8_t            peripheral_clk_source);

#endif

#if !BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET
static void bsp_prv_clock_set_hard_reset(void);

#else
void bsp_soft_reset_prepare(void);

#endif

#if (BSP_FEATURE_RTC_IS_AVAILABLE || BSP_FEATURE_RTC_HAS_TCEN || BSP_FEATURE_SYSC_HAS_TAMPICR1)
static void bsp_prv_init_rtc(void);

#endif

/* This array stores the clock frequency of each system clock. This section of RAM should not be initialized by the C
 * runtime environment. This is initialized and used in bsp_clock_init, which is called before the C runtime
 * environment is initialized. */
static uint32_t g_clock_freq[BSP_PRV_NUM_CLOCKS]  BSP_PLACE_IN_SECTION(BSP_SECTION_NOINIT);

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

#if !BSP_CFG_USE_LOW_VOLTAGE_MODE && BSP_FEATURE_CGC_HAS_OPCCR

/***********************************************************************************************************************
 * Changes the operating speed in OPCCR.  Assumes the LPM registers are unlocked in PRCR and cache is off.
 *
 * @param[in]  operating_mode  Desired operating mode, must be one of the BSP_PRV_OPERATING_MODE_* macros, cannot be
 *                             BSP_PRV_OPERATING_MODE_SUBOSC_SPEED
 **********************************************************************************************************************/
static void bsp_prv_operating_mode_opccr_set (uint8_t operating_mode)
{
    /* Wait for transition to complete. */
    FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OPCCR_b.OPCMTSF, 0U);

    /* Apply requested operating speed mode. */
    R_SYSTEM->OPCCR = operating_mode;

    /* Wait for transition to complete. */
    FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OPCCR_b.OPCMTSF, 0U);
}

#endif

#if !BSP_CFG_USE_LOW_VOLTAGE_MODE

/***********************************************************************************************************************
 * Changes the operating speed mode.  Assumes the LPM registers are unlocked in PRCR and cache is off.
 *
 * @param[in]  operating_mode  Desired operating mode, must be one of the BSP_PRV_OPERATING_MODE_* macros
 **********************************************************************************************************************/
void bsp_prv_operating_mode_set (uint8_t operating_mode)
{
 #if BSP_FEATURE_CGC_HAS_OPCCR
    bsp_prv_operating_mode_opccr_set(operating_mode);
 #else
    FSP_PARAMETER_NOT_USED(operating_mode);
 #endif
}

#endif

#if BSP_PRV_PLL_SUPPORTED

/***********************************************************************************************************************
 * Updates the operating frequency of the specified PLL and all its output channels.
 *
 * @param[in] clock                    PLL being configured
 * @param[in] p_pll_hz                 Array of values of the new PLL output clock frequencies
 **********************************************************************************************************************/
void bsp_prv_prepare_pll (uint32_t clock, uint32_t const * const p_pll_hz)
{
    if (BSP_CLOCKS_SOURCE_CLOCK_PLL == clock)
    {
        g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL] = p_pll_hz[0];
 #if 3 == BSP_FEATURE_CGC_PLL1_NUM_OUTPUT_CLOCKS
        g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL1Q] = p_pll_hz[1];
        g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL1R] = p_pll_hz[2];
 #endif
    }

 #if BSP_PRV_PLL2_SUPPORTED
    else
    {
        g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL2] = p_pll_hz[0];
  #if 3 == BSP_FEATURE_CGC_PLL2_NUM_OUTPUT_CLOCKS
        g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL2Q] = p_pll_hz[1];
        g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL2R] = p_pll_hz[2];
  #endif
    }
 #endif
}

#endif

/*******************************************************************************************************************//**
 * Update SystemCoreClock variable based on current clock settings.
 **********************************************************************************************************************/
void SystemCoreClockUpdate (void)
{
    uint32_t clock_index = R_SYSTEM->SCKSCR;

    uint8_t cpuclk_div = (uint8_t) ((R_SYSTEM->SCKDIVCR2 & R_SYSTEM_SCKDIVCR2_CPUCK0_Msk) >>
                                    R_SYSTEM_SCKDIVCR2_CPUCK0_Pos);

    if (8U == cpuclk_div)
    {
        SystemCoreClock = g_clock_freq[clock_index] / 3U;
    }
    else if (9U == cpuclk_div)
    {
        SystemCoreClock = g_clock_freq[clock_index] / 6U;
    }
    else if (10U == cpuclk_div)
    {
        SystemCoreClock = g_clock_freq[clock_index] / 12U;
    }
    else if (11U == cpuclk_div)
    {
        SystemCoreClock = g_clock_freq[clock_index] / 24U;
    }
    else
    {
        SystemCoreClock = g_clock_freq[clock_index] >> cpuclk_div;
    }
}

/*******************************************************************************************************************//**
 * Write SCKDIVCR and SCKDIVCR2 in the correct order to ensure that CPUCLK frequency is greater than ICLK frequency.
 *
 * @param[in] sckdivcr                 The new SCKDIVCR setting.
 * @param[in] sckdivcr2                The new SCKDIVCR2 setting.
 **********************************************************************************************************************/
void prv_clock_dividers_set (uint32_t sckdivcr, uint16_t sckdivcr2)
{
    uint32_t requested_iclk_div = BSP_PRV_SCKDIVCR_DIV_VALUE(
        (sckdivcr >> FSP_PRIV_CLOCK_ICLK) & FSP_PRV_SCKDIVCR_DIV_MASK);
    uint32_t current_iclk_div = BSP_PRV_SCKDIVCR_DIV_VALUE(R_SYSTEM->SCKDIVCR_b.ICK);

    uint16_t temp_sckdivcr2 = sckdivcr2;

    if (requested_iclk_div >= current_iclk_div)
    {
        /* If the requested ICLK divider is greater than or equal to the current ICLK divider, then writing to
         * SCKDIVCR first will always satisfy the constraint: CPUCLK frequency >= ICLK frequency. */
        R_SYSTEM->SCKDIVCR  = sckdivcr;
        R_SYSTEM->SCKDIVCR2 = temp_sckdivcr2;
    }
    else
    {
        /* If the requested ICLK divider is less than the current ICLK divider, then writing to SCKDIVCR2 first
         * will always satisfy the constraint: CPUCLK frequency >= ICLK frequency. */
        R_SYSTEM->SCKDIVCR2 = temp_sckdivcr2;
        R_SYSTEM->SCKDIVCR  = sckdivcr;
    }
}

#if BSP_FEATURE_CGC_SCKDIVCR2_HAS_EXTRA_CLOCKS

/*******************************************************************************************************************//**
 * Disable the PFB for MRAM.
 **********************************************************************************************************************/
void bsp_prv_clear_pfb (void)
{
    /* Disable MRAM pre-fetch buffer */
    R_MRAM->MRCPFB = 0x00;
}

/*******************************************************************************************************************//**
 * Enable the PFB for MRAM.
 **********************************************************************************************************************/
void bsp_prv_set_pfb (void)
{
    /* Enable MRAM pre-fetch buffer */
    R_MRAM->MRCPFB = 0x01;
}

/*******************************************************************************************************************//**
 * Sets the wait states for MRAM.
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_prv_set_wait_state_frequency (uint32_t mriclk_frequency_hz, uint32_t mrpclk_frequency_hz)
{
    uint32_t freq_mhz;

    /* Set Code MRAM wait states */
    if (mriclk_frequency_hz <= BSP_PRV_MRFREQ_MIN_HZ)
    {
        freq_mhz = 0;
    }
    else
    {
        /* Round up the result when converting to MHz */
        freq_mhz = (mriclk_frequency_hz + BSP_PRV_HZ_PER_MHZ - 1) / BSP_PRV_HZ_PER_MHZ;
    }

    /* Write MRCFREQ */
    while (freq_mhz != R_MRAM->MRCFREQ)
    {
        R_MRAM->MRCFREQ = BSP_PRV_MRCFREQ_KEY | freq_mhz;
    }

    /* Set Extra MRAM wait states */
    if (mrpclk_frequency_hz <= BSP_PRV_MRFREQ_MIN_HZ)
    {
        /* When under the minimum set MREFREQ to 0 */
        freq_mhz = 0;
    }
    else
    {
        /* Round up the result when converting to MHz */
        freq_mhz = (mrpclk_frequency_hz + BSP_PRV_HZ_PER_MHZ - 1) / BSP_PRV_HZ_PER_MHZ;
    }

    /* Write MREFREQ */
    while (freq_mhz != R_MRAM->MREFREQ)
    {
        R_MRAM->MREFREQ = BSP_PRV_MREFREQ_KEY | freq_mhz;
    }
}

#endif

/*******************************************************************************************************************//**
 * Applies system core clock source and divider changes.  The MCU is expected to be in high speed mode during this
 * configuration and the CGC registers are expected to be unlocked in PRCR.
 *
 * @param[in] clock                    Desired system clock
 * @param[in] sckdivcr                 Value to set in SCKDIVCR register
 * @param[in] sckdivcr2                Value to set in SCKDIVCR2 register
 **********************************************************************************************************************/
void bsp_prv_clock_set (uint32_t clock, uint32_t sckdivcr, uint16_t sckdivcr2)
{
    uint32_t cpuclk_div                = sckdivcr2 & R_SYSTEM_SCKDIVCR2_CPUCK0_Msk;
    uint32_t clock_freq_hz_post_change = g_clock_freq[clock] / BSP_PRV_SCKDIVCR_DIV_VALUE(cpuclk_div);

    /* Adjust the MCU specific wait state right before the system clock is set, if the system clock frequency to be
     * set is higher than before. */

    uint32_t mriclk_div = (sckdivcr2 & R_SYSTEM_SCKDIVCR2_MRICK_Msk) >> R_SYSTEM_SCKDIVCR2_MRICK_Pos;

    uint32_t mriclk_freq_post_change = g_clock_freq[clock] / BSP_PRV_SCKDIVCR_DIV_VALUE(mriclk_div);

    uint32_t mrpclk_div = (sckdivcr & R_SYSTEM_SCKDIVCR_MRPCK_Msk) >> R_SYSTEM_SCKDIVCR_MRPCK_Pos;

    uint32_t mrpclk_freq_post_change = g_clock_freq[clock] / BSP_PRV_SCKDIVCR_DIV_VALUE(mrpclk_div);

#if BSP_FEATURE_CGC_SCKDIVCR2_HAS_EXTRA_CLOCKS && BSP_CFG_PREFETCH_BUFFER_ENABLE

    /* Clear the PFB before doing any clock changes according to Frequency Change Procedure. */

    bsp_prv_clear_pfb();
#endif

    /* Switching to a faster source clock. */
    if (g_clock_freq[clock] >= g_clock_freq[R_SYSTEM->SCKSCR])
    {
        /* New source clock will be faster so set wait state frequency according to Frequency Change Procedure. */
        bsp_prv_set_wait_state_frequency(mriclk_freq_post_change, mrpclk_freq_post_change);

        bsp_clock_set_prechange(clock_freq_hz_post_change);

        /* Set the clock dividers before switching to the new clock source. */
        prv_clock_dividers_set(sckdivcr, sckdivcr2);

        /* Switch to the new clock source. */
        R_SYSTEM->SCKSCR = (uint8_t) clock;

        SystemCoreClockUpdate();

        /* Wait for settling delay. */
        R_BSP_SoftwareDelay(BSP_CFG_CLOCK_SETTLING_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);
    }
    /* Switching to a slower source clock. */
    else
    {
        /* ICLK and CPUCLK down 1 notch. */
        uint32_t current_sckdivcr = R_SYSTEM->SCKDIVCR;
        uint32_t current_iclk_div = (current_sckdivcr >> R_SYSTEM_SCKDIVCR_ICK_Pos) & 0xF;
        uint32_t new_div          = current_iclk_div + 1;
        if (current_iclk_div == 0)
        {
            /* Align with already selected divider for PCLKA because it must have one > 1 already. */
            new_div =
                (current_sckdivcr &
                 (0x8 << R_SYSTEM_SCKDIVCR_PCKA_Pos)) ? BSP_CLOCKS_SYS_CLOCK_DIV_3 : BSP_CLOCKS_SYS_CLOCK_DIV_2;
        }

        R_BSP_SoftwareDelay(BSP_CFG_CLOCK_SETTLING_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);
        R_SYSTEM->SCKDIVCR = (current_sckdivcr & ~(R_SYSTEM_SCKDIVCR_ICK_Msk)) |
                             (new_div << R_SYSTEM_SCKDIVCR_ICK_Pos);

        /* Bump down dividers to new_div for other sckdivcr2 dividers if needed. */
        uint32_t new_mriclk_div = (mriclk_div < new_div) ? new_div : mriclk_div;

        R_SYSTEM->SCKDIVCR2 =
            (uint16_t) (new_div | (new_mriclk_div << R_SYSTEM_SCKDIVCR2_MRICK_Pos));

        SystemCoreClockUpdate();

        R_BSP_SoftwareDelay(BSP_CFG_CLOCK_SETTLING_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);

        R_SYSTEM->SCKSCR = (uint8_t) clock;

        /* Set the clock dividers after switching to the new clock source. */
        prv_clock_dividers_set(sckdivcr, sckdivcr2);

        /* New source clock will be slower so set wait state frequency after changing clock frequency according to Frequency Change Procedure. */
        bsp_prv_set_wait_state_frequency(mriclk_freq_post_change, mrpclk_freq_post_change);

        /* Adjust the MCU specific wait state soon after the system clock is set, if the system clock frequency to be
         * set is lower than previous. */
        bsp_clock_set_postchange(clock_freq_hz_post_change, 0);
    }

#if BSP_FEATURE_CGC_SCKDIVCR2_HAS_EXTRA_CLOCKS && BSP_CFG_PREFETCH_BUFFER_ENABLE
    bsp_prv_set_pfb();
#endif

    /* Clock is now at requested frequency. */

    /* Update the CMSIS core clock variable so that it reflects the new ICLK frequency. */
    SystemCoreClock = clock_freq_hz_post_change;
}

#if BSP_CFG_SLEEP_MODE_DELAY_ENABLE || BSP_CFG_RTOS_SLEEP_MODE_DELAY_ENABLE

bool bsp_prv_clock_prepare_pre_sleep (void)
{
    /* Must wait before entering or exiting sleep modes.
     * See "Notes on transitioning to or canceling low power state" in the LPM section of the relevant hardware manual */
    R_BSP_SoftwareDelay(BSP_CFG_CLOCK_SETTLING_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);

    /* Need to slow CPUCLK down before sleeping if it is above 300MHz. */
    bool cpuclk_slowed = false;
    if (SystemCoreClock > BSP_MAX_CLOCK_CHANGE_THRESHOLD)
    {
        /* Reduce speed of CPUCLK to /3 or /4 of current, select which ones based on what ICLK divider is. */
        R_SYSTEM->SCKDIVCR2 =
            (uint16_t) (((0x8 << R_SYSTEM_SCKDIVCR_ICK_Pos) &
                         R_SYSTEM->SCKDIVCR) ? BSP_CLOCKS_SYS_CLOCK_DIV_3 : BSP_CLOCKS_SYS_CLOCK_DIV_4);

        cpuclk_slowed = true;
        SystemCoreClockUpdate();
        R_BSP_SoftwareDelay(BSP_CFG_CLOCK_SETTLING_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);
    }

    return cpuclk_slowed;
}

void bsp_prv_clock_prepare_post_sleep (bool cpuclk_slowed)
{
    /* Set CPUCLK back to original speed here if it was slowed down before sleeping (dropped to below 300MHz)
     * Add delays as described in Section 10.7.10 of the relevant hardware manual */
    R_BSP_SoftwareDelay(BSP_CFG_CLOCK_SETTLING_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);
    if (cpuclk_slowed)
    {
        /* Set divider of CPUCLK back to /2. This is the only possible value for it to have been over 300MHz before sleeping. */
        R_SYSTEM->SCKDIVCR2 = BSP_CLOCKS_SYS_CLOCK_DIV_2;
        SystemCoreClockUpdate();
        R_BSP_SoftwareDelay(BSP_CFG_CLOCK_SETTLING_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);
    }
}

#endif

#if !BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET

static void bsp_prv_clock_set_hard_reset (void)
{
    /* Wait states in SRAMWTSC are set after hard reset. No change required here. */

 #if BSP_FEATURE_CGC_SCKDIVCR2_HAS_EXTRA_CLOCKS && BSP_CFG_PREFETCH_BUFFER_ENABLE

    /* Clear the PFB before doing any clock changes according to Frequency Change Procedure. */

    bsp_prv_clear_pfb();
 #endif

    /* New source clock will be faster so set wait state frequency before changing clock frequency
     * according to Frequency Change Procedure. */
    bsp_prv_set_wait_state_frequency(BSP_STARTUP_MRICLK_HZ, BSP_STARTUP_MRPCLK_HZ);

 #if BSP_FEATURE_CGC_HAS_SRAMWTSC
    R_SRAM->SRAMPRCR_S = BSP_PRV_SRAM_UNLOCK;
    R_SRAM->SRAMWTSC   = BSP_PRV_SRAM_WAIT_CYCLES;
    R_SRAM->SRAMPRCR_S = BSP_PRV_SRAM_LOCK;
 #endif

 #if BSP_PRV_ICLK_DIV_VALUE >= BSP_PRV_SCKDIVCR_DIV_VALUE(BSP_FEATURE_CGC_ICLK_DIV_RESET)

    /* If the requested ICLK divider is greater than or equal to the current ICLK divider, then writing to
     * SCKDIVCR first will always satisfy the constraint: CPUCLK frequency >= ICLK frequency. */
    R_SYSTEM->SCKDIVCR  = BSP_PRV_STARTUP_SCKDIVCR;
    R_SYSTEM->SCKDIVCR2 = BSP_PRV_STARTUP_SCKDIVCR2;
 #else

    /* If the requested ICLK divider is less than the current ICLK divider, then writing to SCKDIVCR2 first
     * will always satisfy the constraint: CPUCLK frequency >= ICLK frequency. */
    R_SYSTEM->SCKDIVCR2 = BSP_PRV_STARTUP_SCKDIVCR2;
    R_SYSTEM->SCKDIVCR  = BSP_PRV_STARTUP_SCKDIVCR;
 #endif

    /* Set the system source clock */
    R_SYSTEM->SCKSCR = BSP_CFG_CLOCK_SOURCE;

    /* Update the CMSIS core clock variable so that it reflects the new ICLK frequency. */
    SystemCoreClockUpdate();
    R_BSP_SoftwareDelay(BSP_CFG_CLOCK_SETTLING_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);

 #if BSP_FEATURE_CGC_SCKDIVCR2_HAS_EXTRA_CLOCKS && BSP_CFG_PREFETCH_BUFFER_ENABLE
    bsp_prv_set_pfb();
 #endif

    /* Clocks are now at requested frequencies. */
}

#endif

/*******************************************************************************************************************//**
 * Initializes variable to store system clock frequencies.
 **********************************************************************************************************************/
static void bsp_clock_freq_var_init (void)
{
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_HOCO] = BSP_HOCO_HZ;
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_MOCO] = BSP_MOCO_FREQ_HZ;
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_LOCO] = BSP_LOCO_FREQ_HZ;
#if BSP_CLOCK_CFG_MAIN_OSC_POPULATED
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC] = BSP_CFG_XTAL_HZ;
#else
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC] = 0U;
#endif
#if BSP_CLOCK_CFG_SUBCLOCK_POPULATED
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_SUBCLOCK] = BSP_SUBCLOCK_FREQ_HZ;
#else
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_SUBCLOCK] = 0U;
#endif
#if BSP_PRV_PLL_SUPPORTED
 #if BSP_CLOCKS_SOURCE_CLOCK_PLL == BSP_CFG_CLOCK_SOURCE

    /* The PLL Is the startup clock. */
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL]   = BSP_CFG_PLL1P_FREQUENCY_HZ;
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL1Q] = BSP_CFG_PLL1Q_FREQUENCY_HZ;
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL1R] = BSP_CFG_PLL1R_FREQUENCY_HZ;
 #endif
#endif

    /* Update PLL Clock Frequency based on BSP Configuration. */
#if BSP_PRV_PLL_SUPPORTED && BSP_CLOCKS_SOURCE_CLOCK_PLL != BSP_CFG_CLOCK_SOURCE && BSP_PRV_PLL_USED
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL]   = BSP_CFG_PLL1P_FREQUENCY_HZ;
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL1Q] = BSP_CFG_PLL1Q_FREQUENCY_HZ;
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL1R] = BSP_CFG_PLL1R_FREQUENCY_HZ;
#endif

    /* Update PLL2 Clock Frequency based on BSP Configuration. */
#if BSP_PRV_PLL2_SUPPORTED && BSP_PRV_PLL2_USED
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL2]  = BSP_CFG_PLL2P_FREQUENCY_HZ;
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL2Q] = BSP_CFG_PLL2Q_FREQUENCY_HZ;
    g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_PLL2R] = BSP_CFG_PLL2R_FREQUENCY_HZ;
#endif

    /* The SystemCoreClock needs to be updated before calling R_BSP_SoftwareDelay. */
    SystemCoreClockUpdate();
}

#if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET

/*
 * If the clock registers are not guaranteed to be set to their value after reset (Ie. the application is executing after a bootloader),
 * then the current state of the registers must be taken into consideration before writing the clock configuration.
 *
 * The HOCO must be stopped in the following situations:
 *  - The application configures the HOCO to be stopped.
 *  - The application enables the FLL, but the HOCO is already running. In order to enable the FLL, the HOCO must be stopped.
 * The PLL must be stopped in the following situations:
 *  - The application configures the PLL to be stopped.
 *  - The application configures settings that are different than the current settings, but the PLL is already running. In order to
 *    write new PLL settings, the PLL must be stopped.
 *  - The HOCO is the PLL source clock and the HOCO is being stopped.
 * The PLL2 must be stopped in the following situations:
 *  - The application configures the PLL2 to be stopped.
 *  - The application configures settings that are different than the current settings, but the PLL2 is already running. In order to
 *    write new PLL2 settings, the PLL2 must be stopped.
 *  - The HOCO is the PLL2 source clock and the HOCO is being stopped.
 *
 * If the HOCO or PLL are being used as the system clock source and they need to be stopped, then the system clock source needs to be switched
 * to the default system clock source before the current system clock source is disabled.
 */
void bsp_soft_reset_prepare (void)
{
    bool stop_hoco = false;
 #if BSP_PRV_PLL_SUPPORTED
    bool stop_pll = false;
 #endif
 #if BSP_PRV_PLL2_SUPPORTED
    bool stop_pll2 = false;
 #endif

 #if BSP_PRV_HOCO_USE_FLL || !BSP_PRV_HOCO_USED
  #if BSP_PRV_HOCO_USE_FLL

    /* Determine if the FLL needs to be enabled. */
    bool enable_fll = (0 == R_SYSTEM->FLLCR1 && BSP_PRV_HOCO_USE_FLL);
  #else
    bool enable_fll = false;
  #endif

    /* If the HOCO is already enabled and either the FLL needs to be enabled or the HOCO is not used, then stop the HOCO. */
    if ((0 == R_SYSTEM->HOCOCR) && (enable_fll || !BSP_PRV_HOCO_USED))
    {
        stop_hoco = true;
    }
 #endif

 #if BSP_PRV_PLL_SUPPORTED
    if (0 == R_SYSTEM->PLLCR)
    {
        /*
         * If any of the following conditions are true, then the PLL needs to be stopped:
         * - The PLL is not used
         * - The PLL settings need to be changed
         * - The HOCO is selected as the PLL clock source and the HOCO needs to be stopped
         *   - Note that PLL type 2 does not support running off of the HOCO
         */
  #if BSP_PRV_PLL_USED
        if ((BSP_PRV_PLLCCR != R_SYSTEM->PLLCCR) || (BSP_PRV_PLLCCR2 != R_SYSTEM->PLLCCR2) ||
            (stop_hoco && (1 == R_SYSTEM->PLLCCR_b.PLSRCSEL)))
  #endif
        {
            stop_pll = true;
        }
    }
 #endif

 #if BSP_PRV_PLL2_SUPPORTED
    if (0 == R_SYSTEM->PLL2CR)
    {
        /*
         * If any of the following conditions are true, then the PLL2 needs to be stopped:
         * - The PLL2 is not used
         * - The PLL2 settings need to be changed
         * - The HOCO is selected as the PLL2 clock source and the HOCO needs to be stopped
         *   - Note that PLL type 2 does not support running off of the HOCO
         */
  #if BSP_PRV_PLL2_USED
        if ((BSP_PRV_PLL2CCR != R_SYSTEM->PLL2CCR) || (BSP_PRV_PLL2CCR2 != R_SYSTEM->PLL2CCR2) ||
            (stop_hoco && (1 == R_SYSTEM->PLL2CCR_b.PL2SRCSEL)))
  #endif
        {
            stop_pll2 = true;
        }
    }
 #endif

    uint8_t sckscr = R_SYSTEM->SCKSCR;

    /* If the System Clock source needs to be stopped, then switch to the MOCO. */
 #if BSP_PRV_PLL_SUPPORTED
    if ((stop_hoco && (BSP_CLOCKS_SOURCE_CLOCK_HOCO == sckscr)) ||
        (stop_pll && (BSP_CLOCKS_SOURCE_CLOCK_PLL == sckscr)))
 #else
    if (stop_hoco && (BSP_CLOCKS_SOURCE_CLOCK_HOCO == sckscr))
 #endif
    {
        bsp_prv_clock_set(BSP_FEATURE_CGC_STARTUP_SCKSCR,
                          BSP_FEATURE_CGC_STARTUP_SCKDIVCR,
                          BSP_FEATURE_CGC_STARTUP_SCKDIVCR2);
    }

    /* Disable the oscillators so that the application can write the new clock configuration. */

 #if BSP_PRV_PLL_SUPPORTED
    if (stop_pll)
    {
        R_SYSTEM->PLLCR = 1;
        FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OSCSF_b.PLLSF, 0);
    }
 #endif

 #if BSP_PRV_PLL2_SUPPORTED
    if (stop_pll2)
    {
        R_SYSTEM->PLL2CR = 1;
        FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OSCSF_b.PLL2SF, 0);
    }
 #endif

    if (stop_hoco)
    {
        R_SYSTEM->HOCOCR = 1;
        FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OSCSF_b.HOCOSF, 0);
    }
}

#endif

/*******************************************************************************************************************//**
 * Initializes system clocks.  Makes no assumptions about current register settings.
 **********************************************************************************************************************/
void bsp_clock_init (void)
{
    /* Unlock CGC and LPM protection registers. */
    R_SYSTEM->PRCR = (uint16_t) BSP_PRV_PRCR_UNLOCK;

    bsp_clock_freq_var_init();

#if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET

    /* Transition to an intermediate clock configuration in order to prepare for writing the new clock configuraiton. */
    bsp_soft_reset_prepare();
#endif

#if BSP_CLOCK_CFG_MAIN_OSC_POPULATED
 #if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET

    /* Update the main oscillator drive, source, and wait states if the main oscillator is stopped.  If the main
     * oscillator is running, the drive, source, and wait states are assumed to be already set appropriately. */
    if (R_SYSTEM->MOSCCR)
    {
        /* Don't write to MOSCWTCR unless MOSTP is 1 and MOSCSF = 0. */
        FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OSCSF_b.MOSCSF, 0U);

        /* Configure main oscillator drive. */
        R_SYSTEM->MOMCR = BSP_PRV_MOMCR;

        /* Set the main oscillator wait time. */
        R_SYSTEM->MOSCWTCR = (uint8_t) BSP_CLOCK_CFG_MAIN_OSC_WAIT;
    }

 #else

    /* Configure main oscillator drive. */
    R_SYSTEM->MOMCR = BSP_PRV_MOMCR;

    /* Set the stabilization time for XTAL. */
    R_SYSTEM->MOSCWTCR = (uint8_t) BSP_CLOCK_CFG_MAIN_OSC_WAIT;
 #endif
#endif

    /* Initialize the sub-clock according to the BSP configuration. */
    bsp_prv_sosc_init();

#if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET

    /* Switch to high-speed to prevent any issues with the subsequent clock configurations. */
    bsp_prv_operating_mode_set(BSP_PRV_OPERATING_MODE_HIGH_SPEED);
#endif

    /* The FLL function can only be used when the subclock is running. */
#if BSP_PRV_HOCO_USE_FLL

    /* If FLL is to be used configure FLLCR1 and FLLCR2 before starting HOCO. */
    R_SYSTEM->FLLCR2 = BSP_PRV_FLL_FLLCR2;
    R_SYSTEM->FLLCR1 = 1U;
#endif

    /* Start all clocks used by other clocks first. */
#if BSP_PRV_HOCO_USED
    R_SYSTEM->HOCOCR = 0U;

 #if BSP_PRV_HOCO_USE_FLL && (BSP_CLOCKS_SOURCE_CLOCK_HOCO != BSP_CFG_PLL_SOURCE)

    /* If FLL is enabled, wait for the FLL stabilization delay (1.8 ms) */
    R_BSP_SoftwareDelay(BSP_PRV_FLL_STABILIZATION_TIME_US, BSP_DELAY_UNITS_MICROSECONDS);
 #endif

 #if BSP_PRV_STABILIZE_HOCO

    /* Wait for HOCO to stabilize. */
    FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OSCSF_b.HOCOSF, 1U);
 #endif
#endif
#if BSP_PRV_MOCO_USED
 #if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET

    /* If the MOCO is not running, start it and wait for it to stabilize using a software delay. */
    if (0U != R_SYSTEM->MOCOCR)
    {
        R_SYSTEM->MOCOCR = 0U;
  #if BSP_PRV_STABILIZE_MOCO
        R_BSP_SoftwareDelay(BSP_FEATURE_CGC_MOCO_STABILIZATION_MAX_US, BSP_DELAY_UNITS_MICROSECONDS);
  #endif
    }
 #endif
#endif
#if BSP_PRV_LOCO_USED
 #if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET

    /* If the LOCO is not running, start it and wait for it to stabilize using a software delay. */
    if (0U != R_SYSTEM->LOCOCR)
    {
        R_SYSTEM->LOCOCR = 0U;
  #if BSP_PRV_STABILIZE_LOCO
        R_BSP_SoftwareDelay(BSP_FEATURE_CGC_LOCO_STABILIZATION_MAX_US, BSP_DELAY_UNITS_MICROSECONDS);
  #endif
    }

 #else
    R_SYSTEM->LOCOCR = 0U;
  #if BSP_PRV_STABILIZE_LOCO
    R_BSP_SoftwareDelay(BSP_FEATURE_CGC_LOCO_STABILIZATION_MAX_US, BSP_DELAY_UNITS_MICROSECONDS);
  #endif
 #endif
#endif
#if BSP_PRV_MAIN_OSC_USED
 #if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET
    if (R_SYSTEM->MOSCCR)
 #endif
    {
        R_SYSTEM->MOSCCR = 0U;

 #if BSP_PRV_STABILIZE_MAIN_OSC

        /* Wait for main oscillator to stabilize. */
        FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OSCSF_b.MOSCSF, 1U);
 #endif
    }
#endif

    /* Start clocks that require other clocks. At this point, all dependent clocks are running and stable if needed. */

#if BSP_PRV_STARTUP_OPERATING_MODE != BSP_PRV_OPERATING_MODE_LOW_SPEED
 #if BSP_FEATURE_CGC_HAS_PLL2 && BSP_CFG_PLL2_SOURCE != BSP_CLOCKS_CLOCK_DISABLED
  #if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET
    if (R_SYSTEM->PLL2CR)
  #endif
    {
        R_SYSTEM->PLL2CCR  = BSP_PRV_PLL2CCR;
        R_SYSTEM->PLL2CCR2 = (uint16_t) BSP_PRV_PLL2CCR2;

        /* Start PLL2. */
        R_SYSTEM->PLL2CR = 0U;

  #if BSP_PRV_STABILIZE_PLL

        /* Wait for PLL to stabilize. */
        FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OSCSF_b.PLL2SF, 1U);
  #endif
    }
 #endif                                /* BSP_FEATURE_CGC_HAS_PLL2 && BSP_CFG_PLL2_ENABLE */
#endif

#if BSP_PRV_PLL_SUPPORTED && BSP_PRV_PLL_USED
 #if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET
    if (R_SYSTEM->PLLCR)
 #endif
    {
        R_SYSTEM->PLLCCR  = BSP_PRV_PLLCCR;
        R_SYSTEM->PLLCCR2 = (uint16_t) BSP_PRV_PLLCCR2;

        /* Start PLL1. */
        R_SYSTEM->PLLCR = 0U;

 #if BSP_PRV_STABILIZE_PLL

        /* Wait for PLL to stabilize. */
        FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->OSCSF_b.PLLSF, 1U);
 #endif
    }
#endif                                 /* BSP_PRV_PLL_SUPPORTED && BSP_PRV_PLL_USED */

    /* Set source clock and dividers. */
#if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET
    bsp_prv_clock_set(BSP_CFG_CLOCK_SOURCE, BSP_PRV_STARTUP_SCKDIVCR, BSP_PRV_STARTUP_SCKDIVCR2);
#else
    bsp_prv_clock_set_hard_reset();
#endif

    /* If the MCU can run in a lower power mode, apply the optimal operating speed mode. */
#if !BSP_CFG_USE_LOW_VOLTAGE_MODE
 #if BSP_PRV_STARTUP_OPERATING_MODE != BSP_PRV_OPERATING_MODE_HIGH_SPEED
    bsp_prv_operating_mode_set(BSP_PRV_STARTUP_OPERATING_MODE);
 #endif
#endif

    /* Need to start BCLKA before selecting which BCLK will be used. */
#if defined(BSP_CFG_BCLKA_SOURCE) && (BSP_CFG_BCLKA_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->BCKACR, &R_SYSTEM->BCKADIVCR, BSP_CFG_BCLKA_DIV, BSP_CFG_BCLKA_SOURCE);
#endif

    /* Configure source clock of BCLK and SDCLK if it exists on the MCU. */
#if defined(BSP_CFG_BCLK_OUTPUT) || defined(BSP_CFG_SDCLK_OUTPUT)
 #if BSP_CFG_SDCLK_OUTPUT || (BSP_CFG_BCLK_OUTPUT > 0)
    R_SYSTEM->BCKCR = (uint8_t) (BSP_CFG_PINOUT_SOURCE << R_SYSTEM_BCKCR_EBCKASEL_Pos);
 #endif
#endif

    /* Configure division of BCLK if it exists on the MCU. */
#ifdef BSP_CFG_BCLK_OUTPUT
 #if BSP_CFG_BCLK_OUTPUT > 0U
    R_SYSTEM->BCKCR  |= (uint8_t) (BSP_CFG_BCLK_OUTPUT - 1U);
    R_SYSTEM->EBCKOCR = 1U;
 #else
  #if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET
    R_SYSTEM->EBCKOCR = 0U;
  #endif
 #endif
#endif

    /* Configure SDRAM clock if it exists on the MCU. */
#ifdef BSP_CFG_SDCLK_OUTPUT
    R_SYSTEM->SDCKOCR = BSP_CFG_SDCLK_OUTPUT;
#endif

    /* Configure CLKOUT. */
#if BSP_CFG_CLKOUT_SOURCE == BSP_CLOCKS_CLOCK_DISABLED
 #if BSP_CFG_STARTUP_CLOCK_REG_NOT_RESET
    R_SYSTEM->CKOCR = 0U;
 #endif
#else
    uint8_t ckocr = BSP_CFG_CLKOUT_SOURCE | (BSP_CFG_CLKOUT_DIV << BSP_PRV_CKOCR_CKODIV_BIT);
    R_SYSTEM->CKOCR = ckocr;
    ckocr          |= (1U << BSP_PRV_CKOCR_CKOEN_BIT);
    R_SYSTEM->CKOCR = ckocr;
#endif

#if BSP_PRV_STARTUP_OPERATING_MODE != BSP_PRV_OPERATING_MODE_LOW_SPEED
 #if BSP_CFG_UCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED

    /* If there is a REQ bit in USBCKCR, then follow sequence from section 9.2.43 in RX74M hardware manual R01UH1055JJ. */
  #if BSP_FEATURE_BSP_HAS_USB_CLOCK_REQ

    /* Request to change the USB Clock. */
    R_SYSTEM->USBCKCR_b.USBCKSREQ = 1;

    /* Wait for the clock to be stopped. */
    FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->USBCKCR_b.USBCKSRDY, 1U);

    /* Write the settings. */
    R_SYSTEM->USBCKDIVCR = BSP_PRV_UCLK_DIV;

    /* Select the USB Clock without enabling it. */
    R_SYSTEM->USBCKCR = BSP_CFG_UCLK_SOURCE | R_SYSTEM_USBCKCR_USBCKSREQ_Msk;
  #endif                               /* BSP_FEATURE_BSP_HAS_USB_CLOCK_REQ */

  #if BSP_FEATURE_BSP_HAS_USB_CLOCK_SEL

    /* Select the USB Clock. */
    R_SYSTEM->USBCKCR = BSP_CFG_UCLK_SOURCE;
  #endif                               /* BSP_FEATURE_BSP_HAS_USB_CLOCK_REQ */

  #if BSP_FEATURE_BSP_HAS_USB_CLOCK_REQ

    /* Wait for the USB Clock to be started. */
    FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->USBCKCR_b.USBCKSRDY, 0U);
  #endif                               /* BSP_FEATURE_BSP_HAS_USB_CLOCK_REQ */
 #endif                                /* BSP_CFG_USB_ENABLE */
#endif                                 /* BSP_PRV_STARTUP_OPERATING_MODE != BSP_PRV_OPERATING_MODE_LOW_SPEED */

    /* Set the XSPI clock if it exists on the MCU (See section 9.2.44 of the RX74M hardware manual R01UH1055JJ). */
#if BSP_FEATURE_BSP_HAS_OCTASPI_CLOCK && BSP_CFG_OCTA_SOURCE != BSP_CLOCKS_CLOCK_DISABLED
    bsp_octaclk_settings_t octaclk_settings =
    {
        .source_clock = (bsp_clocks_source_t) BSP_CFG_OCTA_SOURCE,
        .divider      = (bsp_clocks_octaclk_div_t) BSP_CFG_OCTA_DIV
    };
    R_BSP_OctaclkUpdate(&octaclk_settings);
#endif                                 /* BSP_FEATURE_BSP_HAS_OCTASPI_CLOCK && BSP_CFG_OCTASPI_CLOCK_ENABLE */

    /* Set the CANFD clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_CANFD_CLOCK && (BSP_CFG_CANFDCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED) && \
    (BSP_CFG_CANFDCLK_SOURCE != BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
    bsp_peripheral_clock_set(&R_SYSTEM->CANFDCKCR,
                             &R_SYSTEM->CANFDCKDIVCR,
                             BSP_CFG_CANFDCLK_DIV,
                             BSP_CFG_CANFDCLK_SOURCE);
#endif

    /* Set the SCI clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_SCI_CLOCK && (BSP_CFG_SCICLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->SCICKCR, &R_SYSTEM->SCICKDIVCR, BSP_CFG_SCICLK_DIV, BSP_CFG_SCICLK_SOURCE);
#endif

    /* Set the SPI clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_SPI_CLOCK && (BSP_CFG_SPICLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->SPICKCR, &R_SYSTEM->SPICKDIVCR, BSP_CFG_SPICLK_DIV, BSP_CFG_SPICLK_SOURCE);
#endif

    /* Set the GPT clock if it exists on the MCU */
#if BSP_PERIPHERAL_GPT_GTCLK_PRESENT && (BSP_CFG_GPTCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->GPTCKCR, &R_SYSTEM->GPTCKDIVCR, BSP_CFG_GPTCLK_DIV, BSP_CFG_GPTCLK_SOURCE);
#endif

    /* Set the I3C clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_I3C_CLOCK && (BSP_CFG_I3CCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->I3CCKCR, &R_SYSTEM->I3CCKDIVCR, BSP_CFG_I3CCLK_DIV, BSP_CFG_I3CCLK_SOURCE);
#endif

    /* Set the USB-HS clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_USB60_CLOCK && (BSP_CFG_USB60CLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->USB60CKCR,
                             &R_SYSTEM->USB60CKDIVCR,
                             BSP_CFG_USB60CLK_DIV,
                             BSP_CFG_USB60CLK_SOURCE);
#endif

    /* Set the ADC clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_ADC_CLOCK && (BSP_CFG_ADCCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->ADCCKCR, &R_SYSTEM->ADCCKDIVCR, BSP_CFG_ADCCLK_DIV, BSP_CFG_ADCCLK_SOURCE);
#endif

    /* Set the ESWCLK clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_ESW_CLOCK && (BSP_CFG_ESWCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->ESWCKCR, &R_SYSTEM->ESWCKDIVCR, BSP_CFG_ESWCLK_DIV, BSP_CFG_ESWCLK_SOURCE);
#endif

    /* Set the ESWPHYCLK clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_ESWPHY_CLOCK && (BSP_CFG_ESWPHYCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->ESWPCKCR,
                             &R_SYSTEM->ESWPCKDIVCR,
                             BSP_CFG_ESWPHYCLK_DIV,
                             BSP_CFG_ESWPHYCLK_SOURCE);
#endif

    /* Set the ESCCLK clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_ESC_CLOCK && (BSP_CFG_ESCCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->ESCCKCR, &R_SYSTEM->ESCCKDIVCR, BSP_CFG_ESCCLK_DIV, BSP_CFG_ESCCLK_SOURCE);
#endif

    /* Set the ETHPHYCLK clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_ETHPHY_CLOCK && (BSP_CFG_ETHPHYCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->ETHPCKCR,
                             &R_SYSTEM->ETHPCKDIVCR,
                             BSP_CFG_ETHPHYCLK_DIV,
                             BSP_CFG_ETHPHYCLK_SOURCE);
#endif

    /* Set the DSMIFCLK clock if it exists on the MCU */
#if BSP_FEATURE_BSP_HAS_DSMIF_CLOCK && (BSP_CFG_DSMIFCLK_SOURCE != BSP_CLOCKS_CLOCK_DISABLED)
    bsp_peripheral_clock_set(&R_SYSTEM->DSMIFCKCR,
                             &R_SYSTEM->DSMIFCKDIVCR,
                             BSP_CFG_DSMIFCLK_DIV,
                             BSP_CFG_DSMIFCLK_SOURCE);
#endif

    /* Lock CGC and LPM protection registers. */
    R_SYSTEM->PRCR = (uint16_t) BSP_PRV_PRCR_LOCK;
}

#if BSP_CLOCK_CFG_SUBCLOCK_POPULATED

/*******************************************************************************************************************//**
 * This function is called during SOSC stabilization when Sub-Clock oscillator is populated.
 * This function is declared as a weak symbol higher up in this file because it is meant to be overridden by a user
 * implemented version. One of the main uses for this function is to update the IWDT/WDT Refresh Register if an
 * application starts IWDT/WDT automatically after reset. To use this function just copy this function into your own
 * code and modify it to meet your needs.
 *
 * @param[in]  delay_ms    Stabilization Time for the clock.
 **********************************************************************************************************************/
void R_BSP_SubClockStabilizeWait (uint32_t delay_ms)
{
    /* Wait for clock to stabilize. */
    R_BSP_SoftwareDelay(delay_ms, BSP_DELAY_UNITS_MILLISECONDS);
}

/*******************************************************************************************************************//**
 * This function is called during SOSC registers initialization when Sub-Clock oscillator is populated.
 * This function is declared as a weak symbol higher up in this file because it is meant to be overridden by a user
 * implemented version. One of the main uses for this function is to skip waiting for stabilization time after reset.
 * To use this function just copy this function into your own code and modify it to meet your needs.
 *
 * @param[in]  delay_ms    Stabilization Time for the clock.
 **********************************************************************************************************************/
void R_BSP_SubClockStabilizeWaitAfterReset (uint32_t delay_ms)
{
 #if (BSP_CLOCKS_SOURCE_CLOCK_SUBCLOCK == BSP_CFG_CLOCK_SOURCE) || (BSP_PRV_HOCO_USE_FLL)

    /* Wait for clock to stabilize after reset. */
    R_BSP_SoftwareDelay(delay_ms, BSP_DELAY_UNITS_MILLISECONDS);
 #else
    FSP_PARAMETER_NOT_USED(delay_ms);
 #endif
}

#endif

#if (BSP_PRV_HAS_ENABLED_PERIPHERAL_CLOCKS == 1U)

/*******************************************************************************************************************//**
 * Set the peripheral clock on the MCU
 *
 * @param[in] p_clk_ctrl_reg            Pointer to peripheral clock control register
 * @param[in] p_clk_div_reg             Pointer to peripheral clock division control register
 * @param[in] peripheral_clk_div        Peripheral clock division
 * @param[in] peripheral_clk_source     Peripheral clock source
 *
 * @return The wait states for FLWT required after the clock change (or 0 if FLWT does not exist).
 **********************************************************************************************************************/
static void bsp_peripheral_clock_set (volatile uint8_t * p_clk_ctrl_reg,
                                      volatile uint8_t * p_clk_div_reg,
                                      uint8_t            peripheral_clk_div,
                                      uint8_t            peripheral_clk_source)
{
    /* Request to stop the peripheral clock. */
    *p_clk_ctrl_reg |= (uint8_t) BSP_PRV_PERIPHERAL_CLK_REQ_BIT_MASK;

    /* Wait for the peripheral clock to stop. */
    FSP_HARDWARE_REGISTER_WAIT((uint8_t) ((*p_clk_ctrl_reg & BSP_PRV_PERIPHERAL_CLK_RDY_BIT_MASK) >>
                                          BSP_PRV_PERIPHERAL_CLK_RDY_BIT_POS),
                               1U);

    /* Select the peripheral clock divisor and source. */
    *p_clk_div_reg  = peripheral_clk_div;
    *p_clk_ctrl_reg = (uint8_t) (peripheral_clk_source | BSP_PRV_PERIPHERAL_CLK_REQ_BIT_MASK |
                                 BSP_PRV_PERIPHERAL_CLK_RDY_BIT_MASK);

    /* Request to start the peripheral clock. */
    *p_clk_ctrl_reg &= (uint8_t) ~BSP_PRV_PERIPHERAL_CLK_REQ_BIT_MASK;

    /* Wait for the peripheral clock to start. */
    FSP_HARDWARE_REGISTER_WAIT((uint8_t) ((*p_clk_ctrl_reg & BSP_PRV_PERIPHERAL_CLK_RDY_BIT_MASK) >>
                                          BSP_PRV_PERIPHERAL_CLK_RDY_BIT_POS),
                               0U);
}

#endif

/*******************************************************************************************************************//**
 * Increases the ROM and RAM wait state settings to the minimum required based on the requested clock change.
 *
 * @param[in] requested_freq_hz        New core clock frequency after the clock change.
 *
 * @return The wait states for FLWT required after the clock change (or 0 if FLWT does not exist).
 **********************************************************************************************************************/
static uint8_t bsp_clock_set_prechange (uint32_t requested_freq_hz)
{
#if BSP_FEATURE_CGC_HAS_SRAMWTSC

    /* Wait states for SRAM (SRAM0, SRAM1 and SRAM0 (DED)). */
    if (requested_freq_hz > BSP_FEATURE_BSP_SYS_CLOCK_FREQ_NO_RAM_WAITS)
    {
        /* Unlock SRAM protecti control register. */
        R_SRAM->SRAMPRCR_S = BSP_PRV_SRAM_UNLOCK;

        /* Set SRAM Wait Control register */
        R_SRAM->SRAMWTSC = BSP_FEATURE_SRAM_SRAMWTSC_WAIT_CYCLE_ENABLE;

        /* Lock SRAM protecti control register. */
        R_SRAM->SRAMPRCR_S = BSP_PRV_SRAM_LOCK;
    }
#endif

    return 0;
}

/*******************************************************************************************************************//**
 * Decreases the ROM and RAM wait state settings to the minimum supported based on the applied clock change.
 *
 * @param[in] updated_freq_hz          New clock frequency after clock change
 * @param[in] new_rom_wait_state       Optimal value for FLWT if it exists, 0 if FLWT does not exist on the MCU
 **********************************************************************************************************************/
static void bsp_clock_set_postchange (uint32_t updated_freq_hz, uint8_t new_rom_wait_state)
{
    FSP_PARAMETER_NOT_USED(new_rom_wait_state);

#if BSP_FEATURE_CGC_HAS_SRAMWTSC

    /* Wait states for SRAM (SRAM0, SRAM1 and SRAM0 (DED)). */
    if (updated_freq_hz <= BSP_FEATURE_BSP_SYS_CLOCK_FREQ_NO_RAM_WAITS)
    {
        /* Unlock SRAM protecti control register. */
        R_SRAM->SRAMPRCR_S = BSP_PRV_SRAM_UNLOCK;

        /* Set SRAM Wait Control register */
        R_SRAM->SRAMWTSC = BSP_PRV_SRAMWTSC_WAIT_CYCLES_DISABLE;

        /* Lock SRAM protecti control register. */
        R_SRAM->SRAMPRCR_S = BSP_PRV_SRAM_LOCK;
    }
#endif
}

/*******************************************************************************************************************//**
 * Initializes sub-clock according to the BSP configuration.
 **********************************************************************************************************************/
static void bsp_prv_sosc_init (void)
{
#if BSP_FEATURE_CGC_HAS_SOSC
 #if BSP_CLOCK_CFG_SUBCLOCK_POPULATED
    {
        /* Refer to "Initialization procedure" in the RTC section of the relevant hardware manual */

        /* RCKSEL bit is not initialized after reset.
         * Initialize RCKSEL bit When sub-clock is set as the RTC count source.
         */
  #if BSP_FEATURE_RTC_IS_AVAILABLE || BSP_FEATURE_RTC_HAS_TCEN || BSP_FEATURE_SYSC_HAS_TAMPICR1
   #if BSP_CFG_RTCSCLK_ENABLE
        if (0 == R_SYSTEM->RSTSR2_b.CWSF)
        {
            volatile uint8_t dummy_read;

            /* Sses SOSC as clock source, or there is no clock source. */
            R_RTC->RCR4 = 0;

            /* When four read operations are performed after writing, the register is reflected.
             * (see "Notes on Writing to and Reading from Registers" description in RTC section of the relevant hardware manual). */
            for (uint32_t i = 0; i < 4; i++)
            {
                dummy_read = R_RTC->RCR4;
                FSP_PARAMETER_NOT_USED(dummy_read);
            }
        }
   #endif
  #endif
        if (R_SYSTEM->SOSCCR || (BSP_CLOCK_CFG_SUBCLOCK_DRIVE != R_SYSTEM->SOMCR_b.SODRV))
        {
            /* If Sub-Clock Oscillator is started at reset, stop it before configuring the subclock drive. */
            if (0U == R_SYSTEM->SOSCCR)
            {
                /* Stop the Sub-Clock Oscillator to update the SOMCR register. */
                R_SYSTEM->SOSCCR = 1U;

                /* Allow a stop interval of at least 5 SOSC clock cycles before configuring the drive capacity
                 * and restarting Sub-Clock Oscillator. */
                R_BSP_SoftwareDelay(BSP_PRV_SUBCLOCK_STOP_INTERVAL_US, BSP_DELAY_UNITS_MICROSECONDS);

                /*
                 * r01uh1055-rx74m 9.2.14 SOSCCR : Sub-Clock Oscillator Control Register:
                 * When changing the value of the SOSTP bit, execute subsequent instructions
                 * only after reading the bit to check that the value is updated.
                 */
                FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->SOSCCR, 1U);
            }

            /* Configure the subclock drive as subclock is not running. */
            R_SYSTEM->SOMCR =
                ((BSP_CLOCK_CFG_SUBCLOCK_DRIVE << BSP_FEATURE_CGC_SODRV_SHIFT) & BSP_FEATURE_CGC_SODRV_MASK);

            R_SYSTEM->SOSCCR = 0U;

            /*
             * r01uh1055-rx74m 9.2.14 SOSCCR : Sub-Clock Oscillator Control Register:
             * When changing the value of the SOSTP bit, execute subsequent instructions
             * only after reading the bit to check that the value is updated.
             */
            FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->SOSCCR, 0U);

            /* r01uh1055-rx74m 9.2.14 SOSCCR : Sub-Clock Oscillator Control Register:
             * After setting the SOSTP bit to 0, use the sub-clock only after the sub-clock
             * oscillation stabilization time has elapsed.
             */
  #if (BSP_CLOCKS_SOURCE_CLOCK_SUBCLOCK == BSP_CFG_CLOCK_SOURCE) || \
            (BSP_CFG_RTCSCLK_ENABLE) || (BSP_PRV_HOCO_USE_FLL)
            R_BSP_SubClockStabilizeWait(BSP_CLOCK_CFG_SUBCLOCK_STABILIZATION_MS);
  #endif

            /* Initialize RTC when RTC Count Source is set to Sub-clock and RTC is not used. */
  #if BSP_FEATURE_RTC_IS_AVAILABLE || BSP_FEATURE_RTC_HAS_TCEN || BSP_FEATURE_SYSC_HAS_TAMPICR1
   #if BSP_CFG_RTCSCLK_ENABLE
            if (0 == R_SYSTEM->RSTSR2_b.CWSF)
            {
                bsp_prv_init_rtc();
            }
   #endif
  #endif
        }
    }
 #else
    R_SYSTEM->SOSCCR = 1U;

    /*
     * r01uh1055-rx74m 9.2.14 SOSCCR : Sub-Clock Oscillator Control Register:
     * When changing the value of the SOSTP bit, execute subsequent instructions
     * only after reading the bit to check that the value is updated.
     */
    FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->SOSCCR, 1U);
 #endif
#endif
}

/*******************************************************************************************************************//**
 * XSPI clock update.
 * @param[in]   p_octaclk_setting   Pointer to xspiclk setting structure which provides information regarding
 *                                  xspiclk source and divider settings to be applied.
 * @note The requested xspiclk source must be started before calling this function.
 **********************************************************************************************************************/
void R_BSP_OctaclkUpdate (bsp_octaclk_settings_t * p_octaclk_setting)
{
#if BSP_FEATURE_BSP_HAS_OCTASPI_CLOCK
 #if BSP_FEATURE_OSPI_B_IS_AVAILABLE
  #define OSPI_UNIT_COUNT    BSP_FEATURE_OSPI_B_UNIT_COUNT
 #else
  #define OSPI_UNIT_COUNT    (1U)
 #endif

    /* Store initial value of CGC and LPM protection registers. */
    uint16_t bsp_prv_prcr_orig = R_SYSTEM->PRCR;

    /* Unlock CGC and LPM protection registers. */
    R_SYSTEM->PRCR = (uint16_t) BSP_PRV_PRCR_UNLOCK;

    /* Request to change the XSPI Clock. */

    /* All XSPI peripherals need to be stopped before the clock change. */
    uint32_t started_modules = 0;
    for (uint32_t i = 0; i < OSPI_UNIT_COUNT; i++)
    {
        /* BSP_MSTP_BIT_FSP_IP_XSPI has a semi-colon at the end of the macro which messes up using
         * it in an expression. Save the flag then if it is zero the IP is stopped. */
        const uint32_t ip_stopped = BSP_MSTP_REG_FSP_IP_XSPI(i) & BSP_MSTP_BIT_FSP_IP_XSPI(i);
        if (0 == ip_stopped)
        {
            /* Save the module index as a flag then stop it. */
            started_modules |= (1U << i);
            R_BSP_MODULE_STOP(FSP_IP_XSPI, i);
        }
    }

    /* Must wait 2 OCTACLK cycles after the module has been stopped before changing the clock. */
    const uint32_t octaclk_freq_hz = R_BSP_SourceClockHzGet((fsp_priv_source_clock_t) R_SYSTEM->XSPICKCR_b.XSPICKSEL) /
                                     R_FSP_ClockDividerGet((uint32_t) R_SYSTEM->XSPICKDIVCR_b.XSPICKDIV);
    const uint32_t octaclk_period_us = octaclk_freq_hz / BSP_PRV_HZ_PER_MHZ;

    R_BSP_SoftwareDelay(2U * octaclk_period_us, BSP_DELAY_UNITS_MICROSECONDS);
    R_SYSTEM->XSPICKCR_b.XSPICKSREQ = 1;

    /* Wait for the clock to be stopped. */
    FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->XSPICKCR_b.XSPICKSRDY, 1U);

    /* Write the settings. */
    R_SYSTEM->XSPICKDIVCR = (uint8_t) p_octaclk_setting->divider;
    R_SYSTEM->XSPICKCR    = (uint8_t) (p_octaclk_setting->source_clock | R_SYSTEM_XSPICKCR_XSPICKSREQ_Msk);

    /* Start the XSPI Clock by setting XSPICKSREQ to zero. */
    R_SYSTEM->XSPICKCR = (uint8_t) p_octaclk_setting->source_clock;

    /* Wait for the XSPI Clock to be started. */
    FSP_HARDWARE_REGISTER_WAIT(R_SYSTEM->XSPICKCR_b.XSPICKSRDY, 0U);

    /* Restore any XSPI peripherals that were stopped. */
    for (uint32_t i = 0; i < OSPI_UNIT_COUNT; i++)
    {
        if (started_modules & (1U << i))
        {
            R_BSP_MODULE_START(FSP_IP_XSPI, i);
        }
    }

    /* Restore CGC and LPM protection registers. */
    R_SYSTEM->PRCR = (uint16_t) (BSP_PRV_PRCR_KEY | bsp_prv_prcr_orig);
#else
    FSP_PARAMETER_NOT_USED(p_octaclk_setting);
#endif
}

/*******************************************************************************************************************//**
 * Gets the frequency of a source clock.
 * @param[in]   clock   Element of clock souce enum which provides clock source.
 * @return     Frequency of requested clock in Hertz.
 **********************************************************************************************************************/
uint32_t R_BSP_SourceClockHzGet (fsp_priv_source_clock_t clock)
{
    uint32_t source_clock = g_clock_freq[clock];

    return source_clock;
}

#if BSP_FEATURE_RTC_IS_AVAILABLE || BSP_FEATURE_RTC_HAS_TCEN || BSP_FEATURE_SYSC_HAS_TAMPICR1

/*******************************************************************************************************************//**
 * Reset RTC settings when the RTC is not to be used.
 **********************************************************************************************************************/
static void bsp_prv_init_rtc (void)
{
 #if !BSP_CFG_RTC_USED
    uint8_t dummy_read = 0;

    /* Wait for 6 RTC count source clcok cycle.
     * 6 count of 32kHz : (1000000/32768)*6=183.105us
     * In the case of MOCO frequency is 8.8MHz : 183.105/(1000000/8800000)=1611.843cycle
     * (1611.843+2)*(1000000/8000000)=201.749us("+2" is overhead cycle)
     */
    R_BSP_SoftwareDelay(BSP_PRV_RTC_RESET_DELAY_US, BSP_DELAY_UNITS_MICROSECONDS);

    /* Clear the RCR2 register */
    R_RTC->RCR2 = 0;

    /* When four read operations are performed after writing, the register is reflected.
     * (see "Notes on Writing to and Reading from Registers" description in RTC section of the relevant hardware manual). */
    for (uint32_t i = 0; i < 4; i++)
    {
        dummy_read = R_RTC->RCR2;
        FSP_PARAMETER_NOT_USED(dummy_read);
    }

    FSP_HARDWARE_REGISTER_WAIT(R_RTC->RCR2, 0);

    /* Reset RTC module */
    R_RTC->RCR2_b.RESET = 1;
    FSP_HARDWARE_REGISTER_WAIT(R_RTC->RCR2_b.RESET, 0);

    /* Disable RTC interrupts */
    R_RTC->RCR1 = 0;

    /* When the RCR1 register is modified, check that all the bits are updated before proceeding
     * (see "RTC Control Register 1 (RCR1)" description in the RTC section of the relevant hardware manual)*/

    FSP_HARDWARE_REGISTER_WAIT(R_RTC->RCR1, 0);

  #if BSP_FEATURE_RTC_HAS_TCEN
    for (uint8_t index = 0U; index < BSP_FEATURE_RTC_RTCCR_CHANNELS; index++)
    {
        /* RTCCRn.TCEN must be cleared after reset. */
        R_RTC->RTCCR[index].RTCCR_b.TCEN = 0U;
        FSP_HARDWARE_REGISTER_WAIT(R_RTC->RTCCR[index].RTCCR_b.TCEN, 0);
    }
  #endif
 #endif

    /* Clear RTC ALARM and Periodic Interrupt Status Flag. */
    R_BSP_IrqStatusClear(BSP_PRV_RTC_ALM_IRQ);
    R_BSP_IrqStatusClear(BSP_PRV_RTC_PRD_IRQ);

    /* Clear RTC Carry Interrupt status flag.*/
    R_ICU->PIR[18].PIR_b.PIR6 = 1;
}

/*******************************************************************************************************************//**
 * RTC Initialization
 *
 * Some RTC registers must be initialized after reset to ensure correct operation.
 * This reset is not performed automatically if the RTC is used in a project as it will
 * be handled by the RTC driver if needed.
 **********************************************************************************************************************/
void R_BSP_Init_RTC (void)
{
    /* Refer to "Initialization procedure" in the RTC section of the relevant hardware manual */

    /* RCKSEL bit is not initialized after reset.
     * Initialize RTC When LOCO is set as the RTC count source and RTC is not used
     */
 #if !BSP_CFG_RTCSCLK_ENABLE || !((BSP_FEATURE_CGC_HAS_SOSC == 1) && (BSP_CLOCK_CFG_SUBCLOCK_POPULATED == 1))
    if (0 == R_SYSTEM->RSTSR2_b.CWSF)
    {
  #if !BSP_CFG_RTC_USED
        volatile uint8_t dummy_read;

        R_RTC->RCR4 = 1 << R_RTC_RCR4_RCKSEL_Pos;

        /* When four read operations are performed after writing, the register is reflected.
         * (see "Notes on Writing to and Reading from Registers" description in RTC section of the relevant hardware manual). */
        for (uint32_t i = 0; i < 4; i++)
        {
            dummy_read = R_RTC->RCR4;
            FSP_PARAMETER_NOT_USED(dummy_read);
        }
  #endif
        bsp_prv_init_rtc();
    }
 #endif

 #if BSP_FEATURE_SYSC_HAS_TAMPICR1

    /* TAMPICR1.CHnEN must be cleared after reset. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_OM_LPC_BATT_SWR);
    R_SYSTEM->TAMPICR1 = 0U;
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_OM_LPC_BATT_SWR);
 #endif
}

#endif

/** @} (end addtogroup BSP_MCU_PRV) */
