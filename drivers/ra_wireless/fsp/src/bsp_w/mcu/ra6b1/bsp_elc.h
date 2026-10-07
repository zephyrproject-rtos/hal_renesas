/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_ELC_H
#define BSP_ELC_H

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RA6B1
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* UNCRUSTIFY-OFF */

/** Sources of event signals to be linked to other peripherals or the CPU
 * @note This list is device specific.
 * */
typedef enum e_elc_event_ra6b1
{
    ELC_EVENT_NONE                          = (0x0),   // Link disabled
    ELC_EVENT_WKUPCW_GPIO0_IRQ              = (0x001), // External pin interrupt
    ELC_EVENT_WKUPCW_GPIO1_IRQ              = (0x002), // External pin interrupt
    ELC_EVENT_WKUPCW_GPIO2_IRQ              = (0x003), // External pin interrupt
    ELC_EVENT_WKUPCW_GPIO3_IRQ              = (0x004), // External pin interrupt
    ELC_EVENT_WKUPCW_GPIO4_IRQ              = (0x005), // External pin interrupt
    ELC_EVENT_WKUPCW_GPIO5_IRQ              = (0x006), // External pin interrupt
    ELC_EVENT_WKUPCW_GPIO6_IRQ              = (0x007), // External pin interrupt
    ELC_EVENT_WKUPCW_GPIO7_IRQ              = (0x008), // External pin interrupt
    ELC_EVENT_DMACWB0_IRQ                   = (0x009), // DMAC transfer end 0
    ELC_EVENT_DMACWB1_IRQ                   = (0x00A), // DMAC transfer end 1
    ELC_EVENT_DMACWB2_IRQ                   = (0x00B), // DMAC transfer end 2
    ELC_EVENT_DMACWB3_IRQ                   = (0x00C), // DMAC transfer end 3
    ELC_EVENT_DMACWB4_IRQ                   = (0x00D), // DMAC transfer end 4
    ELC_EVENT_DMACWB5_IRQ                   = (0x00E), // DMAC transfer end 5
    ELC_EVENT_DMACWB6_IRQ                   = (0x00F), // DMAC transfer end 6
    ELC_EVENT_DMACWB7_IRQ                   = (0x010), // DMAC transfer end 7
    ELC_EVENT_DTCW_DTCEND                   = (0x011), // DTC transfer end
    ELC_EVENT_DOCW_DOPCI                    = (0x012), // Data operation circuit interrupt
    ELC_EVENT_WDTSYSW_IRQ                   = (0x013), // WDTSYS IRQ on underflow
    ELC_EVENT_RTCWB_ALARM_IRQ               = (0x014), // Alarm event interrupt
    ELC_EVENT_RTCWB_MNTH_IRQ                = (0x015), // Month interrupt
    ELC_EVENT_RTCWB_DATE_IRQ                = (0x016), // Date interrupt
    ELC_EVENT_RTCWB_HOUR_IRQ                = (0x017), // Hour interrupt
    ELC_EVENT_RTCWB_MIN_IRQ                 = (0x018), // Minute interrupt
    ELC_EVENT_RTCWB_SEC_IRQ                 = (0x019), // Second interrupt
    ELC_EVENT_RTCWB_HOS_IRQ                 = (0x01A), // Hundredths of second interrupt
    ELC_EVENT_RTCWB_RO_IRQ                  = (0x01B), // RTC rollover interrupt
    ELC_EVENT_RTCWB_CAP_IRQ                 = (0x01C), // RTC Timer capture interrupt
    ELC_EVENT_UARTWB1_RX_IRQ                = (0x01D), // Receive fifo full
    ELC_EVENT_UARTWB1_TXE_IRQ               = (0x01E), // Transmit data empty
    ELC_EVENT_UARTWB1_TXR_IRQ               = (0x01F), // Transmit end
    ELC_EVENT_UARTWB1_IRQ                   = (0x020), // Generic interrupt
    ELC_EVENT_UARTWB2_RX_IRQ                = (0x021), // Receive fifo full
    ELC_EVENT_UARTWB2_TXE_IRQ               = (0x022), // Transmit data empty
    ELC_EVENT_UARTWB2_TXR_IRQ               = (0x023), // Transmit end
    ELC_EVENT_UARTWB2_IRQ                   = (0x024), // Generic interrupt
    ELC_EVENT_UARTWB3_RX_IRQ                = (0x025), // Receive fifo full
    ELC_EVENT_UARTWB3_TXE_IRQ               = (0x026), // Transmit data empty
    ELC_EVENT_UARTWB3_TXR_IRQ               = (0x027), // Transmit end
    ELC_EVENT_UARTWB3_IRQ                   = (0x028), // Generic interrupt
    ELC_EVENT_UARTWB4_RX_IRQ                = (0x029), // Receive fifo full
    ELC_EVENT_UARTWB4_TXE_IRQ               = (0x02A), // Transmit data empty
    ELC_EVENT_UARTWB4_TXR_IRQ               = (0x02B), // Transmit end
    ELC_EVENT_UARTWB4_IRQ                   = (0x02C), // Generic interrupt
    ELC_EVENT_SPIW1_RX_IRQ                  = (0x02D), // Receive fifo full - Receive fifo not full (data ready)
    ELC_EVENT_SPIW1_TX_IRQ                  = (0x02E), // Transmit fifo empty
    ELC_EVENT_SPIW1_EI_IRQ                  = (0x02F), // Error Interrupt (mode fault error - under run error - over run error - parity error - receive data ready)
    ELC_EVENT_SPIW1_II_IRQ                  = (0x030), // Idle interrupt
    ELC_EVENT_SPIW1_IRQ                     = (0x031), // Generic interrupt
    ELC_EVENT_SPIW2_RX_IRQ                  = (0x032), // Receive fifo full - Receive fifo not full (data ready)
    ELC_EVENT_SPIW2_TX_IRQ                  = (0x033), // Transmit fifo empty
    ELC_EVENT_SPIW2_EI_IRQ                  = (0x034), // Error Interrupt (mode fault error - under run error - over run error - parity error - receive data ready)
    ELC_EVENT_SPIW2_II_IRQ                  = (0x035), // Idle interrupt
    ELC_EVENT_SPIW2_IRQ                     = (0x036), // Generic interrupt
    ELC_EVENT_SPIW3_RX_IRQ                  = (0x037), // Receive fifo full - Receive fifo not full (data ready)
    ELC_EVENT_SPIW3_TX_IRQ                  = (0x038), // Transmit fifo empty
    ELC_EVENT_SPIW3_EI_IRQ                  = (0x039), // Error Interrupt (mode fault error - under run error - over run error - parity error - receive data ready)
    ELC_EVENT_SPIW3_II_IRQ                  = (0x03A), // Idle interrupt
    ELC_EVENT_SPIW3_IRQ                     = (0x03B), // Generic interrupt
    ELC_EVENT_I2CW1_RX_IRQ                  = (0x03C), // Receive fifo full
    ELC_EVENT_I2CW1_TXE_IRQ                 = (0x03D), // Transmit data empty
    ELC_EVENT_I2CW1_TXR_IRQ                 = (0x03E), // Transmit end
    ELC_EVENT_I2CW1_IRQ                     = (0x03F), // Generic interrupt
    ELC_EVENT_I2CW2_RX_IRQ                  = (0x040), // Receive fifo full
    ELC_EVENT_I2CW2_TXE_IRQ                 = (0x041), // Transmit data empty
    ELC_EVENT_I2CW2_TXR_IRQ                 = (0x042), // Transmit end
    ELC_EVENT_I2CW2_IRQ                     = (0x043), // Generic interrupt
    ELC_EVENT_I2CW3_RX_IRQ                  = (0x044), // Receive fifo full
    ELC_EVENT_I2CW3_TXE_IRQ                 = (0x045), // Transmit data empty
    ELC_EVENT_I2CW3_TXR_IRQ                 = (0x046), // Transmit end
    ELC_EVENT_I2CW3_IRQ                     = (0x047), // Generic interrupt
    ELC_EVENT_I3CW_RX_IRQ                   = (0x048), // Receive buffer full
    ELC_EVENT_I3CW_TXE_IRQ                  = (0x049), // Transmit buffer empty
    ELC_EVENT_I3CW_TXR_IRQ                  = (0x04A), // Transmit end
    ELC_EVENT_I3CW_IRQ                      = (0x04B), // Generic interrupt
    ELC_EVENT_I3CW_IB_IRQ                   = (0x04C), // Inband interrupt
    ELC_EVENT_TIMW1_IRQ                     = (0x04D), // Generic interrupt
    ELC_EVENT_TIMW1_CCMA_IRQ                = (0x04E), // Capture or Compare match channel A
    ELC_EVENT_TIMW1_CCMB_IRQ                = (0x04F), // Capture or Compare match channel B
    ELC_EVENT_TIMW1_CCMC_IRQ                = (0x050), // Capture or Compare match channel C
    ELC_EVENT_TIMW1_CCMD_IRQ                = (0x051), // Capture or Compare match channel D
    ELC_EVENT_TIMW1_CCME_IRQ                = (0x052), // Capture or Compare match channel E
    ELC_EVENT_TIMW1_CCMF_IRQ                = (0x053), // Capture or Compare match channel F
    ELC_EVENT_TIMW1_CCMG_IRQ                = (0x054), // Capture or Compare match channel G
    ELC_EVENT_TIMW1_CCMH_IRQ                = (0x055), // Capture or Compare match channel H
    ELC_EVENT_TIMW1_OVF_IRQ                 = (0x056), // Overflow
    ELC_EVENT_TIMW1_UNF_IRQ                 = (0x057), // Underflow
    ELC_EVENT_TIMW2_IRQ                     = (0x058), // Generic interrupt
    ELC_EVENT_TIMW2_CCMA_IRQ                = (0x059), // Capture or Compare match channel A
    ELC_EVENT_TIMW2_CCMB_IRQ                = (0x05A), // Capture or Compare match channel B
    ELC_EVENT_TIMW2_CCMC_IRQ                = (0x05B), // Capture or Compare match channel C
    ELC_EVENT_TIMW2_CCMD_IRQ                = (0x05C), // Capture or Compare match channel D
    ELC_EVENT_TIMW2_CCME_IRQ                = (0x05D), // Capture or Compare match channel E
    ELC_EVENT_TIMW2_CCMF_IRQ                = (0x05E), // Capture or Compare match channel F
    ELC_EVENT_TIMW2_CCMG_IRQ                = (0x05F), // Capture or Compare match channel G
    ELC_EVENT_TIMW2_CCMH_IRQ                = (0x060), // Capture or Compare match channel H
    ELC_EVENT_TIMW2_OVF_IRQ                 = (0x061), // Overflow
    ELC_EVENT_TIMW2_UNF_IRQ                 = (0x062), // Underflow
    ELC_EVENT_TIMW3_IRQ                     = (0x063), // Generic interrupt
    ELC_EVENT_TIMW3_CCMA_IRQ                = (0x064), // Capture or Compare match channel A
    ELC_EVENT_TIMW3_CCMB_IRQ                = (0x065), // Capture or Compare match channel B
    ELC_EVENT_TIMW3_CCMC_IRQ                = (0x066), // Capture or Compare match channel C
    ELC_EVENT_TIMW3_CCMD_IRQ                = (0x067), // Capture or Compare match channel D
    ELC_EVENT_TIMW3_CCME_IRQ                = (0x068), // Capture or Compare match channel E
    ELC_EVENT_TIMW3_CCMF_IRQ                = (0x069), // Capture or Compare match channel F
    ELC_EVENT_TIMW3_CCMG_IRQ                = (0x06A), // Capture or Compare match channel G
    ELC_EVENT_TIMW3_CCMH_IRQ                = (0x06B), // Capture or Compare match channel H
    ELC_EVENT_TIMW3_OVF_IRQ                 = (0x06C), // Overflow
    ELC_EVENT_TIMW3_UNF_IRQ                 = (0x06D), // Underflow
    ELC_EVENT_TIMW4_IRQ                     = (0x06E), // Generic interrupt
    ELC_EVENT_TIMW4_CCMA_IRQ                = (0x06F), // Capture or Compare match channel A
    ELC_EVENT_TIMW4_CCMB_IRQ                = (0x070), // Capture or Compare match channel B
    ELC_EVENT_TIMW4_CCMC_IRQ                = (0x071), // Capture or Compare match channel C
    ELC_EVENT_TIMW4_CCMD_IRQ                = (0x072), // Capture or Compare match channel D
    ELC_EVENT_TIMW4_CCME_IRQ                = (0x073), // Capture or Compare match channel E
    ELC_EVENT_TIMW4_CCMF_IRQ                = (0x074), // Capture or Compare match channel F
    ELC_EVENT_TIMW4_CCMG_IRQ                = (0x075), // Capture or Compare match channel G
    ELC_EVENT_TIMW4_CCMH_IRQ                = (0x076), // Capture or Compare match channel H
    ELC_EVENT_TIMW4_OVF_IRQ                 = (0x077), // Overflow
    ELC_EVENT_TIMW4_UNF_IRQ                 = (0x078), // Underflow
    ELC_EVENT_TIMW5_IRQ                     = (0x079), // Generic interrupt
    ELC_EVENT_TIMW5_CCMA_IRQ                = (0x07A), // Capture or Compare match channel A
    ELC_EVENT_TIMW5_CCMB_IRQ                = (0x07B), // Capture or Compare match channel B
    ELC_EVENT_TIMW5_CCMC_IRQ                = (0x07C), // Capture or Compare match channel C
    ELC_EVENT_TIMW5_CCMD_IRQ                = (0x07D), // Capture or Compare match channel D
    ELC_EVENT_TIMW5_CCME_IRQ                = (0x07E), // Capture or Compare match channel E
    ELC_EVENT_TIMW5_CCMF_IRQ                = (0x07F), // Capture or Compare match channel F
    ELC_EVENT_TIMW5_CCMG_IRQ                = (0x080), // Capture or Compare match channel G
    ELC_EVENT_TIMW5_CCMH_IRQ                = (0x081), // Capture or Compare match channel H
    ELC_EVENT_TIMW5_OVF_IRQ                 = (0x082), // Overflow
    ELC_EVENT_TIMW5_UNF_IRQ                 = (0x083), // Underflow
    ELC_EVENT_TIMW6_IRQ                     = (0x084), // Generic interrupt
    ELC_EVENT_TIMW6_CCMA_IRQ                = (0x085), // Capture or Compare match channel A
    ELC_EVENT_TIMW6_CCMB_IRQ                = (0x086), // Capture or Compare match channel B
    ELC_EVENT_TIMW6_CCMC_IRQ                = (0x087), // Capture or Compare match channel C
    ELC_EVENT_TIMW6_CCMD_IRQ                = (0x088), // Capture or Compare match channel D
    ELC_EVENT_TIMW6_CCME_IRQ                = (0x089), // Capture or Compare match channel E
    ELC_EVENT_TIMW6_CCMF_IRQ                = (0x08A), // Capture or Compare match channel F
    ELC_EVENT_TIMW6_CCMG_IRQ                = (0x08B), // Capture or Compare match channel G
    ELC_EVENT_TIMW6_CCMH_IRQ                = (0x08C), // Capture or Compare match channel H
    ELC_EVENT_TIMW6_OVF_IRQ                 = (0x08D), // Overflow
    ELC_EVENT_TIMW6_UNF_IRQ                 = (0x08E), // Underflow
    ELC_EVENT_TIMW7_IRQ                     = (0x08F), // Generic interrupt
    ELC_EVENT_TIMW7_CCMA_IRQ                = (0x090), // Capture or Compare match channel A
    ELC_EVENT_TIMW7_CCMB_IRQ                = (0x091), // Capture or Compare match channel B
    ELC_EVENT_TIMW7_CCMC_IRQ                = (0x092), // Capture or Compare match channel C
    ELC_EVENT_TIMW7_CCMD_IRQ                = (0x093), // Capture or Compare match channel D
    ELC_EVENT_TIMW7_CCME_IRQ                = (0x094), // Capture or Compare match channel E
    ELC_EVENT_TIMW7_CCMF_IRQ                = (0x095), // Capture or Compare match channel F
    ELC_EVENT_TIMW7_CCMG_IRQ                = (0x096), // Capture or Compare match channel G
    ELC_EVENT_TIMW7_CCMH_IRQ                = (0x097), // Capture or Compare match channel H
    ELC_EVENT_TIMW7_OVF_IRQ                 = (0x098), // Overflow
    ELC_EVENT_TIMW7_UNF_IRQ                 = (0x099), // Underflow
    ELC_EVENT_TIMW8_IRQ                     = (0x09A), // Generic interrupt
    ELC_EVENT_TIMW8_CCMA_IRQ                = (0x09B), // Capture or Compare match channel A
    ELC_EVENT_TIMW8_CCMB_IRQ                = (0x09C), // Capture or Compare match channel B
    ELC_EVENT_TIMW8_CCMC_IRQ                = (0x09D), // Capture or Compare match channel C
    ELC_EVENT_TIMW8_CCMD_IRQ                = (0x09E), // Capture or Compare match channel D
    ELC_EVENT_TIMW8_CCME_IRQ                = (0x09F), // Capture or Compare match channel E
    ELC_EVENT_TIMW8_CCMF_IRQ                = (0x0A0), // Capture or Compare match channel F
    ELC_EVENT_TIMW8_CCMG_IRQ                = (0x0A1), // Capture or Compare match channel G
    ELC_EVENT_TIMW8_CCMH_IRQ                = (0x0A2), // Capture or Compare match channel H
    ELC_EVENT_TIMW8_OVF_IRQ                 = (0x0A3), // Overflow
    ELC_EVENT_TIMW8_UNF_IRQ                 = (0x0A4), // Underflow
    ELC_EVENT_TIMW9_IRQ                     = (0x0A5), // Generic interrupt
    ELC_EVENT_TIMW9_CCMA_IRQ                = (0x0A6), // Capture or Compare match channel A
    ELC_EVENT_TIMW9_CCMB_IRQ                = (0x0A7), // Capture or Compare match channel B
    ELC_EVENT_TIMW9_CCMC_IRQ                = (0x0A8), // Capture or Compare match channel C
    ELC_EVENT_TIMW9_CCMD_IRQ                = (0x0A9), // Capture or Compare match channel D
    ELC_EVENT_TIMW9_CCME_IRQ                = (0x0AA), // Capture or Compare match channel E
    ELC_EVENT_TIMW9_CCMF_IRQ                = (0x0AB), // Capture or Compare match channel F
    ELC_EVENT_TIMW9_CCMG_IRQ                = (0x0AC), // Capture or Compare match channel G
    ELC_EVENT_TIMW9_CCMH_IRQ                = (0x0AD), // Capture or Compare match channel H
    ELC_EVENT_TIMW9_OVF_IRQ                 = (0x0AE), // Overflow
    ELC_EVENT_TIMW9_UNF_IRQ                 = (0x0AF), // Underflow
    ELC_EVENT_TIMW10_IRQ                    = (0x0B0), // Generic interrupt
    ELC_EVENT_TIMW10_CCMA_IRQ               = (0x0B1), // Capture or Compare match channel A
    ELC_EVENT_TIMW10_CCMB_IRQ               = (0x0B2), // Capture or Compare match channel B
    ELC_EVENT_TIMW10_CCMC_IRQ               = (0x0B3), // Capture or Compare match channel C
    ELC_EVENT_TIMW10_CCMD_IRQ               = (0x0B4), // Capture or Compare match channel D
    ELC_EVENT_TIMW10_CCME_IRQ               = (0x0B5), // Capture or Compare match channel E
    ELC_EVENT_TIMW10_CCMF_IRQ               = (0x0B6), // Capture or Compare match channel F
    ELC_EVENT_TIMW10_CCMG_IRQ               = (0x0B7), // Capture or Compare match channel G
    ELC_EVENT_TIMW10_CCMH_IRQ               = (0x0B8), // Capture or Compare match channel H
    ELC_EVENT_TIMW10_OVF_IRQ                = (0x0B9), // Overflow
    ELC_EVENT_TIMW10_UNF_IRQ                = (0x0BA), // Underflow
    ELC_EVENT_IRGEN_IRQ                     = (0x0BB), // Transmit end
    ELC_EVENT_ADCWB_IRQ                     = (0x0BC), // ADC conversion completed
    ELC_EVENT_ADCWB_CC0U_IRQ                = (0x0BD), // ADC Compare Channel 0 Upper threshold exceed
    ELC_EVENT_ADCWB_CC0L_IRQ                = (0x0BE), // ADC Compare Channel 0 Lower threshold exceed
    ELC_EVENT_ADCWB_CC0W_IRQ                = (0x0BF), // ADC Compare Channel 0 Within threshold limits
    ELC_EVENT_ADCWB_CC1U_IRQ                = (0x0C0), // ADC Compare Channel 1 Upper threshold exceed
    ELC_EVENT_ADCWB_CC1L_IRQ                = (0x0C1), // ADC Compare Channel 1 Lower threshold exceed
    ELC_EVENT_ADCWB_CC1W_IRQ                = (0x0C2), // ADC Compare Channel 1 Within threshold limits
    ELC_EVENT_ADCWB_CC2U_IRQ                = (0x0C3), // ADC Compare Channel 2 Upper threshold exceed
    ELC_EVENT_ADCWB_CC2L_IRQ                = (0x0C4), // ADC Compare Channel 2 Lower threshold exceed
    ELC_EVENT_ADCWB_CC2W_IRQ                = (0x0C5), // ADC Compare Channel 2 Within threshold limits
    ELC_EVENT_ADCWB_CC3U_IRQ                = (0x0C6), // ADC Compare Channel 3 Upper threshold exceed
    ELC_EVENT_ADCWB_CC3L_IRQ                = (0x0C7), // ADC Compare Channel 3 Lower threshold exceed
    ELC_EVENT_ADCWB_CC3W_IRQ                = (0x0C8), // ADC Compare Channel 3 Within threshold limits
    ELC_EVENT_ADCWB_CC4U_IRQ                = (0x0C9), // ADC Compare Channel 4 Upper threshold exceed
    ELC_EVENT_ADCWB_CC4L_IRQ                = (0x0CA), // ADC Compare Channel 4 Lower threshold exceed
    ELC_EVENT_ADCWB_CC4W_IRQ                = (0x0CB), // ADC Compare Channel 4 Within threshold limits
    ELC_EVENT_ADCWB_CC5U_IRQ                = (0x0CC), // ADC Compare Channel 5 Upper threshold exceed
    ELC_EVENT_ADCWB_CC5L_IRQ                = (0x0CD), // ADC Compare Channel 5 Lower threshold exceed
    ELC_EVENT_ADCWB_CC5W_IRQ                = (0x0CE), // ADC Compare Channel 5 Within threshold limits
    ELC_EVENT_ADCWB_CC6U_IRQ                = (0x0CF), // ADC Compare Channel 6 Upper threshold exceed
    ELC_EVENT_ADCWB_CC6L_IRQ                = (0x0D0), // ADC Compare Channel 6 Lower threshold exceed
    ELC_EVENT_ADCWB_CC6W_IRQ                = (0x0D1), // ADC Compare Channel 6 Within threshold limits
    ELC_EVENT_ADCWB_CC7U_IRQ                = (0x0D2), // ADC Compare Channel 7 Upper threshold exceed
    ELC_EVENT_ADCWB_CC7L_IRQ                = (0x0D3), // ADC Compare Channel 7 Lower threshold exceed
    ELC_EVENT_ADCWB_CC7W_IRQ                = (0x0D4), // ADC Compare Channel 7 Within threshold limits
    ELC_EVENT_ACOMPW_IRQ                    = (0x0D5), // Analog comparator interrupt
    ELC_EVENT_TEMPSEN_END_IRQ               = (0x0D6), // End of temperature sensor measurement interrupt
    ELC_EVENT_TEMPSEN_THR_IRQ               = (0x0D7), // Threshold matched interrupt
    ELC_EVENT_VBATMON_THR_IRQ               = (0x0D9), // Threshold matched interrupt
    ELC_EVENT_ELCW_SWEVT0                   = (0x0DA), // Software event 0
    ELC_EVENT_ELCW_SWEVT1                   = (0x0DB), // Software event 1
    ELC_EVENT_QDECW1_IRQ                    = (0x0DC), // Quadrature Decoder 1 interrupt
    ELC_EVENT_QDECW2_IRQ                    = (0x0DD), // Quadrature Decoder 2 interrupt
    ELC_EVENT_KBSCNW_IRQ                    = (0x0DE), // KBDSCN IRQ for timestamping through Timer capture channel
    ELC_EVENT_CMAC_SLPTIM_IRQ               = (0x0DF), // CMAC Sleep Timer IRQ
    ELC_EVENT_CMAC_DIAG12_IRQ               = (0x0E0), // Selectable IRQ from RF diagnostic ports
    ELC_EVENT_CMAC_DIAG13_IRQ               = (0x0E1), // Selectable IRQ from RF diagnostic ports
    ELC_EVENT_CMAC_DIAG14_IRQ               = (0x0E2), // Selectable IRQ from RF diagnostic ports
    ELC_EVENT_CMAC_DIAG15_IRQ               = (0x0E3), // Selectable IRQ from RF diagnostic ports
    ELC_EVENT_ELCW_GROUP1                   = (0x136), // Group 1 event
    ELC_EVENT_ELCW_GROUP2                   = (0x137), // Group 2 event
    ELC_EVENT_ELCW_GROUP3                   = (0x138), // Group 3 event
    ELC_EVENT_ELCW_GROUP4                   = (0x139), // Group 4 event
    ELC_EVENT_ELCW_GROUP5                   = (0x13A)  // Group 5 event
} elc_event_t;

/* UNCRUSTIFY-ON */
/** @} (end addtogroup BSP_MCU_RA6B1) */

#endif
