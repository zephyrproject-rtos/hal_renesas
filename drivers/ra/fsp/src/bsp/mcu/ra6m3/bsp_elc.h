/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_ELC_H
#define BSP_ELC_H

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RA6M3
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
typedef enum e_elc_event_ra6m3
{
    ELC_EVENT_NONE                          = (0x0),   // Link disabled
    ELC_EVENT_ICU_IRQ0                      = (0x001), // External pin interrupt 0
    ELC_EVENT_ICU_IRQ1                      = (0x002), // External pin interrupt 1
    ELC_EVENT_ICU_IRQ2                      = (0x003), // External pin interrupt 2
    ELC_EVENT_ICU_IRQ3                      = (0x004), // External pin interrupt 3
    ELC_EVENT_ICU_IRQ4                      = (0x005), // External pin interrupt 4
    ELC_EVENT_ICU_IRQ5                      = (0x006), // External pin interrupt 5
    ELC_EVENT_ICU_IRQ6                      = (0x007), // External pin interrupt 6
    ELC_EVENT_ICU_IRQ7                      = (0x008), // External pin interrupt 7
    ELC_EVENT_ICU_IRQ8                      = (0x009), // External pin interrupt 8
    ELC_EVENT_ICU_IRQ9                      = (0x00A), // External pin interrupt 9
    ELC_EVENT_ICU_IRQ10                     = (0x00B), // External pin interrupt 10
    ELC_EVENT_ICU_IRQ11                     = (0x00C), // External pin interrupt 11
    ELC_EVENT_ICU_IRQ12                     = (0x00D), // External pin interrupt 12
    ELC_EVENT_ICU_IRQ13                     = (0x00E), // External pin interrupt 13
    ELC_EVENT_ICU_IRQ14                     = (0x00F), // External pin interrupt 14
    ELC_EVENT_ICU_IRQ15                     = (0x010), // External pin interrupt 15
    ELC_EVENT_DMAC0_INT                     = (0x020), // DMAC0 transfer end
    ELC_EVENT_DMAC1_INT                     = (0x021), // DMAC1 transfer end
    ELC_EVENT_DMAC2_INT                     = (0x022), // DMAC2 transfer end
    ELC_EVENT_DMAC3_INT                     = (0x023), // DMAC3 transfer end
    ELC_EVENT_DMAC4_INT                     = (0x024), // DMAC4 transfer end
    ELC_EVENT_DMAC5_INT                     = (0x025), // DMAC5 transfer end
    ELC_EVENT_DMAC6_INT                     = (0x026), // DMAC6 transfer end
    ELC_EVENT_DMAC7_INT                     = (0x027), // DMAC7 transfer end
    ELC_EVENT_DTC_COMPLETE                  = (0x029), // DTC transfer complete
    ELC_EVENT_DTC_END                       = (0x02A), // DTC transfer end
    ELC_EVENT_ICU_SNOOZE_CANCEL             = (0x02D), // Canceling from Snooze mode
    ELC_EVENT_FCU_FIFERR                    = (0x030), // Flash access error interrupt
    ELC_EVENT_FCU_FRDYI                     = (0x031), // Flash ready interrupt
    ELC_EVENT_LVD_LVD1                      = (0x038), // Voltage monitor 1 interrupt
    ELC_EVENT_LVD_LVD2                      = (0x039), // Voltage monitor 2 interrupt
    ELC_EVENT_CGC_MOSC_STOP                 = (0x03B), // Main Clock oscillation stop
    ELC_EVENT_LPM_SNOOZE_REQUEST            = (0x03C), // Snooze entry
    ELC_EVENT_AGT0_INT                      = (0x040), // AGT interrupt
    ELC_EVENT_AGT0_COMPARE_A                = (0x041), // Compare match A
    ELC_EVENT_AGT0_COMPARE_B                = (0x042), // Compare match B
    ELC_EVENT_AGT1_INT                      = (0x043), // AGT interrupt
    ELC_EVENT_AGT1_COMPARE_A                = (0x044), // Compare match A
    ELC_EVENT_AGT1_COMPARE_B                = (0x045), // Compare match B
    ELC_EVENT_IWDT_UNDERFLOW                = (0x046), // IWDT underflow
    ELC_EVENT_WDT_UNDERFLOW                 = (0x047), // WDT underflow
    ELC_EVENT_RTC_ALARM                     = (0x048), // Alarm interrupt
    ELC_EVENT_RTC_PERIOD                    = (0x049), // Periodic interrupt
    ELC_EVENT_RTC_CARRY                     = (0x04A), // Carry interrupt
    ELC_EVENT_ADC0_SCAN_END                 = (0x04B), // End of A/D scanning operation
    ELC_EVENT_ADC0_SCAN_END_B               = (0x04C), // A/D scan end interrupt for group B
    ELC_EVENT_ADC0_WINDOW_A                 = (0x04D), // Window A Compare match interrupt
    ELC_EVENT_ADC0_WINDOW_B                 = (0x04E), // Window B Compare match interrupt
    ELC_EVENT_ADC0_COMPARE_MATCH            = (0x04F), // Compare match
    ELC_EVENT_ADC0_COMPARE_MISMATCH         = (0x050), // Compare mismatch
    ELC_EVENT_ADC1_SCAN_END                 = (0x051), // End of A/D scanning operation
    ELC_EVENT_ADC1_SCAN_END_B               = (0x052), // A/D scan end interrupt for group B
    ELC_EVENT_ADC1_WINDOW_A                 = (0x053), // Window A Compare match interrupt
    ELC_EVENT_ADC1_WINDOW_B                 = (0x054), // Window B Compare match interrupt
    ELC_EVENT_ADC1_COMPARE_MATCH            = (0x055), // Compare match
    ELC_EVENT_ADC1_COMPARE_MISMATCH         = (0x056), // Compare mismatch
    ELC_EVENT_ACMPHS0_INT                   = (0x057), // High Speed Comparator channel 0 interrupt
    ELC_EVENT_ACMPHS1_INT                   = (0x058), // High Speed Comparator channel 1 interrupt
    ELC_EVENT_ACMPHS2_INT                   = (0x059), // High Speed Comparator channel 2 interrupt
    ELC_EVENT_ACMPHS3_INT                   = (0x05A), // High Speed Comparator channel 3 interrupt
    ELC_EVENT_ACMPHS4_INT                   = (0x05B), // High Speed Comparator channel 4 interrupt
    ELC_EVENT_ACMPHS5_INT                   = (0x05C), // High Speed Comparator channel 5 interrupt
    ELC_EVENT_USBFS_FIFO_0                  = (0x05F), // DMA/DTC transfer request 0
    ELC_EVENT_USBFS_FIFO_1                  = (0x060), // DMA/DTC transfer request 1
    ELC_EVENT_USBFS_INT                     = (0x061), // USBFS interrupt
    ELC_EVENT_USBFS_RESUME                  = (0x062), // USBFS resume interrupt
    ELC_EVENT_IIC0_RXI                      = (0x063), // Receive data full
    ELC_EVENT_IIC0_TXI                      = (0x064), // Transmit data empty
    ELC_EVENT_IIC0_TEI                      = (0x065), // Transmit end
    ELC_EVENT_IIC0_ERI                      = (0x066), // Transfer error
    ELC_EVENT_IIC0_WUI                      = (0x067), // Wakeup interrupt
    ELC_EVENT_IIC1_RXI                      = (0x068), // Receive data full
    ELC_EVENT_IIC1_TXI                      = (0x069), // Transmit data empty
    ELC_EVENT_IIC1_TEI                      = (0x06A), // Transmit end
    ELC_EVENT_IIC1_ERI                      = (0x06B), // Transfer error
    ELC_EVENT_IIC2_RXI                      = (0x06D), // Receive data full
    ELC_EVENT_IIC2_TXI                      = (0x06E), // Transmit data empty
    ELC_EVENT_IIC2_TEI                      = (0x06F), // Transmit end
    ELC_EVENT_IIC2_ERI                      = (0x070), // Transfer error
    ELC_EVENT_SSI0_TXI                      = (0x072), // Transmit data empty
    ELC_EVENT_SSI0_RXI                      = (0x073), // Receive data full
    ELC_EVENT_SSI0_INT                      = (0x075), // Error interrupt
    ELC_EVENT_SSI1_TXI_RXI                  = (0x078), // DEPRECATED, do not use
    ELC_EVENT_SSI1_TXI                      = (0x078), // Receive data full/Transmit data empty
    ELC_EVENT_SSI1_RXI                      = (0x078), // Receive data full/Transmit data empty
    ELC_EVENT_SSI1_INT                      = (0x079), // Error interrupt
    ELC_EVENT_SRC_INPUT_FIFO_EMPTY          = (0x07A), // Input FIFO empty
    ELC_EVENT_SRC_OUTPUT_FIFO_FULL          = (0x07B), // Output FIFO full
    ELC_EVENT_SRC_OUTPUT_FIFO_OVERFLOW      = (0x07C), // Output FIFO overflow
    ELC_EVENT_SRC_OUTPUT_FIFO_UNDERFLOW     = (0x07D), // Output FIFO underflow
    ELC_EVENT_SRC_CONVERSION_END            = (0x07E), // Conversion end
    ELC_EVENT_PDC_RECEIVE_DATA_READY        = (0x07F), // Receive data ready interrupt
    ELC_EVENT_PDC_FRAME_END                 = (0x080), // Frame end interrupt
    ELC_EVENT_PDC_INT                       = (0x081), // Error interrupt
    ELC_EVENT_CTSU_WRITE                    = (0x082), // Write request interrupt
    ELC_EVENT_CTSU_READ                     = (0x083), // Measurement data transfer request interrupt
    ELC_EVENT_CTSU_END                      = (0x084), // Measurement end interrupt
    ELC_EVENT_KEY_INT                       = (0x085), // Key interrupt
    ELC_EVENT_DOC_INT                       = (0x086), // Data operation circuit interrupt
    ELC_EVENT_CAC_FREQUENCY_ERROR           = (0x087), // Frequency error interrupt
    ELC_EVENT_CAC_MEASUREMENT_END           = (0x088), // Measurement end interrupt
    ELC_EVENT_CAC_OVERFLOW                  = (0x089), // Overflow interrupt
    ELC_EVENT_CAN0_ERROR                    = (0x08A), // Error interrupt
    ELC_EVENT_CAN0_FIFO_RX                  = (0x08B), // Receive FIFO interrupt
    ELC_EVENT_CAN0_FIFO_TX                  = (0x08C), // Transmit FIFO interrupt
    ELC_EVENT_CAN0_MAILBOX_RX               = (0x08D), // Reception complete interrupt
    ELC_EVENT_CAN0_MAILBOX_TX               = (0x08E), // Transmission complete interrupt
    ELC_EVENT_CAN1_ERROR                    = (0x08F), // Error interrupt
    ELC_EVENT_CAN1_FIFO_RX                  = (0x090), // Receive FIFO interrupt
    ELC_EVENT_CAN1_FIFO_TX                  = (0x091), // Transmit FIFO interrupt
    ELC_EVENT_CAN1_MAILBOX_RX               = (0x092), // Reception complete interrupt
    ELC_EVENT_CAN1_MAILBOX_TX               = (0x093), // Transmission complete interrupt
    ELC_EVENT_IOPORT_EVENT_1                = (0x094), // Port 1 event
    ELC_EVENT_IOPORT_EVENT_2                = (0x095), // Port 2 event
    ELC_EVENT_IOPORT_EVENT_3                = (0x096), // Port 3 event
    ELC_EVENT_IOPORT_EVENT_4                = (0x097), // Port 4 event
    ELC_EVENT_ELC_SOFTWARE_EVENT_0          = (0x098), // Software event 0
    ELC_EVENT_ELC_SOFTWARE_EVENT_1          = (0x099), // Software event 1
    ELC_EVENT_POEG0_EVENT                   = (0x09A), // Port Output disable 0 interrupt
    ELC_EVENT_POEG1_EVENT                   = (0x09B), // Port Output disable 1 interrupt
    ELC_EVENT_POEG2_EVENT                   = (0x09C), // Port Output disable 2 interrupt
    ELC_EVENT_POEG3_EVENT                   = (0x09D), // Port Output disable 3 interrupt
    ELC_EVENT_GPT0_CAPTURE_COMPARE_A        = (0x0B0), // Capture/Compare match A
    ELC_EVENT_GPT0_CAPTURE_COMPARE_B        = (0x0B1), // Capture/Compare match B
    ELC_EVENT_GPT0_COMPARE_C                = (0x0B2), // Compare match C
    ELC_EVENT_GPT0_COMPARE_D                = (0x0B3), // Compare match D
    ELC_EVENT_GPT0_COMPARE_E                = (0x0B4), // Compare match E
    ELC_EVENT_GPT0_COMPARE_F                = (0x0B5), // Compare match F
    ELC_EVENT_GPT0_COUNTER_OVERFLOW         = (0x0B6), // Overflow
    ELC_EVENT_GPT0_COUNTER_UNDERFLOW        = (0x0B7), // Underflow
    ELC_EVENT_GPT0_AD_TRIG_A                = (0x0B8), // A/D converter start request A
    ELC_EVENT_GPT0_AD_TRIG_B                = (0x0B9), // A/D converter start request B
    ELC_EVENT_GPT1_CAPTURE_COMPARE_A        = (0x0BA), // Capture/Compare match A
    ELC_EVENT_GPT1_CAPTURE_COMPARE_B        = (0x0BB), // Capture/Compare match B
    ELC_EVENT_GPT1_COMPARE_C                = (0x0BC), // Compare match C
    ELC_EVENT_GPT1_COMPARE_D                = (0x0BD), // Compare match D
    ELC_EVENT_GPT1_COMPARE_E                = (0x0BE), // Compare match E
    ELC_EVENT_GPT1_COMPARE_F                = (0x0BF), // Compare match F
    ELC_EVENT_GPT1_COUNTER_OVERFLOW         = (0x0C0), // Overflow
    ELC_EVENT_GPT1_COUNTER_UNDERFLOW        = (0x0C1), // Underflow
    ELC_EVENT_GPT1_AD_TRIG_A                = (0x0C2), // A/D converter start request A
    ELC_EVENT_GPT1_AD_TRIG_B                = (0x0C3), // A/D converter start request B
    ELC_EVENT_GPT2_CAPTURE_COMPARE_A        = (0x0C4), // Capture/Compare match A
    ELC_EVENT_GPT2_CAPTURE_COMPARE_B        = (0x0C5), // Capture/Compare match B
    ELC_EVENT_GPT2_COMPARE_C                = (0x0C6), // Compare match C
    ELC_EVENT_GPT2_COMPARE_D                = (0x0C7), // Compare match D
    ELC_EVENT_GPT2_COMPARE_E                = (0x0C8), // Compare match E
    ELC_EVENT_GPT2_COMPARE_F                = (0x0C9), // Compare match F
    ELC_EVENT_GPT2_COUNTER_OVERFLOW         = (0x0CA), // Overflow
    ELC_EVENT_GPT2_COUNTER_UNDERFLOW        = (0x0CB), // Underflow
    ELC_EVENT_GPT2_AD_TRIG_A                = (0x0CC), // A/D converter start request A
    ELC_EVENT_GPT2_AD_TRIG_B                = (0x0CD), // A/D converter start request B
    ELC_EVENT_GPT3_CAPTURE_COMPARE_A        = (0x0CE), // Capture/Compare match A
    ELC_EVENT_GPT3_CAPTURE_COMPARE_B        = (0x0CF), // Capture/Compare match B
    ELC_EVENT_GPT3_COMPARE_C                = (0x0D0), // Compare match C
    ELC_EVENT_GPT3_COMPARE_D                = (0x0D1), // Compare match D
    ELC_EVENT_GPT3_COMPARE_E                = (0x0D2), // Compare match E
    ELC_EVENT_GPT3_COMPARE_F                = (0x0D3), // Compare match F
    ELC_EVENT_GPT3_COUNTER_OVERFLOW         = (0x0D4), // Overflow
    ELC_EVENT_GPT3_COUNTER_UNDERFLOW        = (0x0D5), // Underflow
    ELC_EVENT_GPT3_AD_TRIG_A                = (0x0D6), // A/D converter start request A
    ELC_EVENT_GPT3_AD_TRIG_B                = (0x0D7), // A/D converter start request B
    ELC_EVENT_GPT4_CAPTURE_COMPARE_A        = (0x0D8), // Capture/Compare match A
    ELC_EVENT_GPT4_CAPTURE_COMPARE_B        = (0x0D9), // Capture/Compare match B
    ELC_EVENT_GPT4_COMPARE_C                = (0x0DA), // Compare match C
    ELC_EVENT_GPT4_COMPARE_D                = (0x0DB), // Compare match D
    ELC_EVENT_GPT4_COMPARE_E                = (0x0DC), // Compare match E
    ELC_EVENT_GPT4_COMPARE_F                = (0x0DD), // Compare match F
    ELC_EVENT_GPT4_COUNTER_OVERFLOW         = (0x0DE), // Overflow
    ELC_EVENT_GPT4_COUNTER_UNDERFLOW        = (0x0DF), // Underflow
    ELC_EVENT_GPT4_AD_TRIG_A                = (0x0E0), // A/D converter start request A
    ELC_EVENT_GPT4_AD_TRIG_B                = (0x0E1), // A/D converter start request B
    ELC_EVENT_GPT5_CAPTURE_COMPARE_A        = (0x0E2), // Capture/Compare match A
    ELC_EVENT_GPT5_CAPTURE_COMPARE_B        = (0x0E3), // Capture/Compare match B
    ELC_EVENT_GPT5_COMPARE_C                = (0x0E4), // Compare match C
    ELC_EVENT_GPT5_COMPARE_D                = (0x0E5), // Compare match D
    ELC_EVENT_GPT5_COMPARE_E                = (0x0E6), // Compare match E
    ELC_EVENT_GPT5_COMPARE_F                = (0x0E7), // Compare match F
    ELC_EVENT_GPT5_COUNTER_OVERFLOW         = (0x0E8), // Overflow
    ELC_EVENT_GPT5_COUNTER_UNDERFLOW        = (0x0E9), // Underflow
    ELC_EVENT_GPT5_AD_TRIG_A                = (0x0EA), // A/D converter start request A
    ELC_EVENT_GPT5_AD_TRIG_B                = (0x0EB), // A/D converter start request B
    ELC_EVENT_GPT6_CAPTURE_COMPARE_A        = (0x0EC), // Capture/Compare match A
    ELC_EVENT_GPT6_CAPTURE_COMPARE_B        = (0x0ED), // Capture/Compare match B
    ELC_EVENT_GPT6_COMPARE_C                = (0x0EE), // Compare match C
    ELC_EVENT_GPT6_COMPARE_D                = (0x0EF), // Compare match D
    ELC_EVENT_GPT6_COMPARE_E                = (0x0F0), // Compare match E
    ELC_EVENT_GPT6_COMPARE_F                = (0x0F1), // Compare match F
    ELC_EVENT_GPT6_COUNTER_OVERFLOW         = (0x0F2), // Overflow
    ELC_EVENT_GPT6_COUNTER_UNDERFLOW        = (0x0F3), // Underflow
    ELC_EVENT_GPT6_AD_TRIG_A                = (0x0F4), // A/D converter start request A
    ELC_EVENT_GPT6_AD_TRIG_B                = (0x0F5), // A/D converter start request B
    ELC_EVENT_GPT7_CAPTURE_COMPARE_A        = (0x0F6), // Capture/Compare match A
    ELC_EVENT_GPT7_CAPTURE_COMPARE_B        = (0x0F7), // Capture/Compare match B
    ELC_EVENT_GPT7_COMPARE_C                = (0x0F8), // Compare match C
    ELC_EVENT_GPT7_COMPARE_D                = (0x0F9), // Compare match D
    ELC_EVENT_GPT7_COMPARE_E                = (0x0FA), // Compare match E
    ELC_EVENT_GPT7_COMPARE_F                = (0x0FB), // Compare match F
    ELC_EVENT_GPT7_COUNTER_OVERFLOW         = (0x0FC), // Overflow
    ELC_EVENT_GPT7_COUNTER_UNDERFLOW        = (0x0FD), // Underflow
    ELC_EVENT_GPT7_AD_TRIG_A                = (0x0FE), // A/D converter start request A
    ELC_EVENT_GPT7_AD_TRIG_B                = (0x0FF), // A/D converter start request B
    ELC_EVENT_GPT8_CAPTURE_COMPARE_A        = (0x100), // Capture/Compare match A
    ELC_EVENT_GPT8_CAPTURE_COMPARE_B        = (0x101), // Capture/Compare match B
    ELC_EVENT_GPT8_COMPARE_C                = (0x102), // Compare match C
    ELC_EVENT_GPT8_COMPARE_D                = (0x103), // Compare match D
    ELC_EVENT_GPT8_COMPARE_E                = (0x104), // Compare match E
    ELC_EVENT_GPT8_COMPARE_F                = (0x105), // Compare match F
    ELC_EVENT_GPT8_COUNTER_OVERFLOW         = (0x106), // Overflow
    ELC_EVENT_GPT8_COUNTER_UNDERFLOW        = (0x107), // Underflow
    ELC_EVENT_GPT9_CAPTURE_COMPARE_A        = (0x10A), // Capture/Compare match A
    ELC_EVENT_GPT9_CAPTURE_COMPARE_B        = (0x10B), // Capture/Compare match B
    ELC_EVENT_GPT9_COMPARE_C                = (0x10C), // Compare match C
    ELC_EVENT_GPT9_COMPARE_D                = (0x10D), // Compare match D
    ELC_EVENT_GPT9_COMPARE_E                = (0x10E), // Compare match E
    ELC_EVENT_GPT9_COMPARE_F                = (0x10F), // Compare match F
    ELC_EVENT_GPT9_COUNTER_OVERFLOW         = (0x110), // Overflow
    ELC_EVENT_GPT9_COUNTER_UNDERFLOW        = (0x111), // Underflow
    ELC_EVENT_GPT10_CAPTURE_COMPARE_A       = (0x114), // Capture/Compare match A
    ELC_EVENT_GPT10_CAPTURE_COMPARE_B       = (0x115), // Capture/Compare match B
    ELC_EVENT_GPT10_COMPARE_C               = (0x116), // Compare match C
    ELC_EVENT_GPT10_COMPARE_D               = (0x117), // Compare match D
    ELC_EVENT_GPT10_COMPARE_E               = (0x118), // Compare match E
    ELC_EVENT_GPT10_COMPARE_F               = (0x119), // Compare match F
    ELC_EVENT_GPT10_COUNTER_OVERFLOW        = (0x11A), // Overflow
    ELC_EVENT_GPT10_COUNTER_UNDERFLOW       = (0x11B), // Underflow
    ELC_EVENT_GPT11_CAPTURE_COMPARE_A       = (0x11E), // Capture/Compare match A
    ELC_EVENT_GPT11_CAPTURE_COMPARE_B       = (0x11F), // Capture/Compare match B
    ELC_EVENT_GPT11_COMPARE_C               = (0x120), // Compare match C
    ELC_EVENT_GPT11_COMPARE_D               = (0x121), // Compare match D
    ELC_EVENT_GPT11_COMPARE_E               = (0x122), // Compare match E
    ELC_EVENT_GPT11_COMPARE_F               = (0x123), // Compare match F
    ELC_EVENT_GPT11_COUNTER_OVERFLOW        = (0x124), // Overflow
    ELC_EVENT_GPT11_COUNTER_UNDERFLOW       = (0x125), // Underflow
    ELC_EVENT_GPT12_CAPTURE_COMPARE_A       = (0x128), // Capture/Compare match A
    ELC_EVENT_GPT12_CAPTURE_COMPARE_B       = (0x129), // Capture/Compare match B
    ELC_EVENT_GPT12_COMPARE_C               = (0x12A), // Compare match C
    ELC_EVENT_GPT12_COMPARE_D               = (0x12B), // Compare match D
    ELC_EVENT_GPT12_COMPARE_E               = (0x12C), // Compare match E
    ELC_EVENT_GPT12_COMPARE_F               = (0x12D), // Compare match F
    ELC_EVENT_GPT12_COUNTER_OVERFLOW        = (0x12E), // Overflow
    ELC_EVENT_GPT12_COUNTER_UNDERFLOW       = (0x12F), // Underflow
    ELC_EVENT_GPT13_CAPTURE_COMPARE_A       = (0x132), // Capture/Compare match A
    ELC_EVENT_GPT13_CAPTURE_COMPARE_B       = (0x133), // Capture/Compare match B
    ELC_EVENT_GPT13_COMPARE_C               = (0x134), // Compare match C
    ELC_EVENT_GPT13_COMPARE_D               = (0x135), // Compare match D
    ELC_EVENT_GPT13_COMPARE_E               = (0x136), // Compare match E
    ELC_EVENT_GPT13_COMPARE_F               = (0x137), // Compare match F
    ELC_EVENT_GPT13_COUNTER_OVERFLOW        = (0x138), // Overflow
    ELC_EVENT_GPT13_COUNTER_UNDERFLOW       = (0x139), // Underflow
    ELC_EVENT_OPS_UVW_EDGE                  = (0x150), // UVW edge event
    ELC_EVENT_EPTPC_IPLS                    = (0x160), // STCA interrupt
    ELC_EVENT_EPTPC_MINT                    = (0x161), // SYNFP0/1 interrupt
    ELC_EVENT_EPTPC_PINT                    = (0x162), // PTPEDMAC interrupt
    ELC_EVENT_EDMAC0_EINT                   = (0x163), // EDMAC 0 interrupt
    ELC_EVENT_EPTPC_TIMER0_RISE             = (0x165), // Pulse output timer 0 rising edge detection
    ELC_EVENT_EPTPC_TIMER1_RISE             = (0x166), // Pulse output timer 1 rising edge detection
    ELC_EVENT_EPTPC_TIMER2_RISE             = (0x167), // Pulse output timer 2 rising edge detection
    ELC_EVENT_EPTPC_TIMER3_RISE             = (0x168), // Pulse output timer 3 rising edge detection
    ELC_EVENT_EPTPC_TIMER4_RISE             = (0x169), // Pulse output timer 4 rising edge detection
    ELC_EVENT_EPTPC_TIMER5_RISE             = (0x16A), // Pulse output timer 5 rising edge detection
    ELC_EVENT_EPTPC_TIMER0_FALL             = (0x16B), // Pulse output timer 0 falling edge detection
    ELC_EVENT_EPTPC_TIMER1_FALL             = (0x16C), // Pulse output timer 1 falling edge detection
    ELC_EVENT_EPTPC_TIMER2_FALL             = (0x16D), // Pulse output timer 2 falling edge detection
    ELC_EVENT_EPTPC_TIMER3_FALL             = (0x16E), // Pulse output timer 3 falling edge detection
    ELC_EVENT_EPTPC_TIMER4_FALL             = (0x16F), // Pulse output timer 4 falling edge detection
    ELC_EVENT_EPTPC_TIMER5_FALL             = (0x170), // Pulse output timer 5 falling edge detection
    ELC_EVENT_USBHS_FIFO_0                  = (0x171), // DMA transfer request 0
    ELC_EVENT_USBHS_FIFO_1                  = (0x172), // DMA transfer request 1
    ELC_EVENT_USBHS_USB_INT_RESUME          = (0x173), // USBHS interrupt
    ELC_EVENT_SCI0_RXI                      = (0x174), // Receive data full
    ELC_EVENT_SCI0_TXI                      = (0x175), // Transmit data empty
    ELC_EVENT_SCI0_TEI                      = (0x176), // Transmit end
    ELC_EVENT_SCI0_ERI                      = (0x177), // Receive error
    ELC_EVENT_SCI0_AM                       = (0x178), // Address match event
    ELC_EVENT_SCI0_RXI_OR_ERI               = (0x179), // Receive data full/Receive error
    ELC_EVENT_SCI1_RXI                      = (0x17A), // Receive data full
    ELC_EVENT_SCI1_TXI                      = (0x17B), // Transmit data empty
    ELC_EVENT_SCI1_TEI                      = (0x17C), // Transmit end
    ELC_EVENT_SCI1_ERI                      = (0x17D), // Receive error
    ELC_EVENT_SCI1_AM                       = (0x17E), // Address match event
    ELC_EVENT_SCI2_RXI                      = (0x180), // Receive data full
    ELC_EVENT_SCI2_TXI                      = (0x181), // Transmit data empty
    ELC_EVENT_SCI2_TEI                      = (0x182), // Transmit end
    ELC_EVENT_SCI2_ERI                      = (0x183), // Receive error
    ELC_EVENT_SCI2_AM                       = (0x184), // Address match event
    ELC_EVENT_SCI3_RXI                      = (0x186), // Receive data full
    ELC_EVENT_SCI3_TXI                      = (0x187), // Transmit data empty
    ELC_EVENT_SCI3_TEI                      = (0x188), // Transmit end
    ELC_EVENT_SCI3_ERI                      = (0x189), // Receive error
    ELC_EVENT_SCI3_AM                       = (0x18A), // Address match event
    ELC_EVENT_SCI4_RXI                      = (0x18C), // Receive data full
    ELC_EVENT_SCI4_TXI                      = (0x18D), // Transmit data empty
    ELC_EVENT_SCI4_TEI                      = (0x18E), // Transmit end
    ELC_EVENT_SCI4_ERI                      = (0x18F), // Receive error
    ELC_EVENT_SCI4_AM                       = (0x190), // Address match event
    ELC_EVENT_SCI5_RXI                      = (0x192), // Receive data full
    ELC_EVENT_SCI5_TXI                      = (0x193), // Transmit data empty
    ELC_EVENT_SCI5_TEI                      = (0x194), // Transmit end
    ELC_EVENT_SCI5_ERI                      = (0x195), // Receive error
    ELC_EVENT_SCI5_AM                       = (0x196), // Address match event
    ELC_EVENT_SCI6_RXI                      = (0x198), // Receive data full
    ELC_EVENT_SCI6_TXI                      = (0x199), // Transmit data empty
    ELC_EVENT_SCI6_TEI                      = (0x19A), // Transmit end
    ELC_EVENT_SCI6_ERI                      = (0x19B), // Receive error
    ELC_EVENT_SCI6_AM                       = (0x19C), // Address match event
    ELC_EVENT_SCI7_RXI                      = (0x19E), // Receive data full
    ELC_EVENT_SCI7_TXI                      = (0x19F), // Transmit data empty
    ELC_EVENT_SCI7_TEI                      = (0x1A0), // Transmit end
    ELC_EVENT_SCI7_ERI                      = (0x1A1), // Receive error
    ELC_EVENT_SCI7_AM                       = (0x1A2), // Address match event
    ELC_EVENT_SCI8_RXI                      = (0x1A4), // Receive data full
    ELC_EVENT_SCI8_TXI                      = (0x1A5), // Transmit data empty
    ELC_EVENT_SCI8_TEI                      = (0x1A6), // Transmit end
    ELC_EVENT_SCI8_ERI                      = (0x1A7), // Receive error
    ELC_EVENT_SCI8_AM                       = (0x1A8), // Address match event
    ELC_EVENT_SCI9_RXI                      = (0x1AA), // Receive data full
    ELC_EVENT_SCI9_TXI                      = (0x1AB), // Transmit data empty
    ELC_EVENT_SCI9_TEI                      = (0x1AC), // Transmit end
    ELC_EVENT_SCI9_ERI                      = (0x1AD), // Receive error
    ELC_EVENT_SCI9_AM                       = (0x1AE), // Address match event
    ELC_EVENT_SPI0_RXI                      = (0x1BC), // Receive buffer full
    ELC_EVENT_SPI0_TXI                      = (0x1BD), // Transmit buffer empty
    ELC_EVENT_SPI0_IDLE                     = (0x1BE), // Idle
    ELC_EVENT_SPI0_ERI                      = (0x1BF), // Error
    ELC_EVENT_SPI0_TEI                      = (0x1C0), // Transmission complete event
    ELC_EVENT_SPI1_RXI                      = (0x1C1), // Receive buffer full
    ELC_EVENT_SPI1_TXI                      = (0x1C2), // Transmit buffer empty
    ELC_EVENT_SPI1_IDLE                     = (0x1C3), // Idle
    ELC_EVENT_SPI1_ERI                      = (0x1C4), // Error
    ELC_EVENT_SPI1_TEI                      = (0x1C5), // Transmission complete event
    ELC_EVENT_QSPI_INT                      = (0x1C6), // QSPI interrupt
    ELC_EVENT_SDHIMMC0_ACCS                 = (0x1C7), // Card access
    ELC_EVENT_SDHIMMC0_SDIO                 = (0x1C8), // SDIO access
    ELC_EVENT_SDHIMMC0_CARD                 = (0x1C9), // Card detect
    ELC_EVENT_SDHIMMC0_DMA_REQ              = (0x1CA), // DMA transfer request
    ELC_EVENT_SDHIMMC1_ACCS                 = (0x1CB), // Card access
    ELC_EVENT_SDHIMMC1_SDIO                 = (0x1CC), // SDIO access
    ELC_EVENT_SDHIMMC1_CARD                 = (0x1CD), // Card detect
    ELC_EVENT_SDHIMMC1_DMA_REQ              = (0x1CE), // DMA transfer request
    ELC_EVENT_GLCDC_LINE_DETECT             = (0x1FA), // Specified line
    ELC_EVENT_GLCDC_UNDERFLOW_1             = (0x1FB), // Graphic 1 underflow
    ELC_EVENT_GLCDC_UNDERFLOW_2             = (0x1FC), // Graphic 2 underflow
    ELC_EVENT_DRW_INT                       = (0x1FD), // DRW interrupt
    ELC_EVENT_JPEG_JEDI                     = (0x1FE), // Compression/decompression process interrupt
    ELC_EVENT_JPEG_JDTI                     = (0x1FF)  // Data transfer interrupt
} elc_event_t;

#define BSP_PRV_VECT_ENUM(event,group)  (ELC_ ## event)

#define ELC_PERIPHERAL_NUM    (19U)
#define BSP_OVERRIDE_ELC_PERIPHERAL_T
/** Possible peripherals to be linked to event signals
 * @note This list is device specific.
 * */
typedef enum e_elc_peripheral
{
    ELC_PERIPHERAL_GPT_A         = (0),
    ELC_PERIPHERAL_GPT_B         = (1),
    ELC_PERIPHERAL_GPT_C         = (2),
    ELC_PERIPHERAL_GPT_D         = (3),
    ELC_PERIPHERAL_GPT_E         = (4),
    ELC_PERIPHERAL_GPT_F         = (5),
    ELC_PERIPHERAL_GPT_G         = (6),
    ELC_PERIPHERAL_GPT_H         = (7),
    ELC_PERIPHERAL_ADC0          = (8),
    ELC_PERIPHERAL_ADC0_B        = (9),
    ELC_PERIPHERAL_ADC1          = (10),
    ELC_PERIPHERAL_ADC1_B        = (11),
    ELC_PERIPHERAL_DAC0          = (12),
    ELC_PERIPHERAL_DAC1          = (13),
    ELC_PERIPHERAL_IOPORT1       = (14),
    ELC_PERIPHERAL_IOPORT2       = (15),
    ELC_PERIPHERAL_IOPORT3       = (16),
    ELC_PERIPHERAL_IOPORT4       = (17),
    ELC_PERIPHERAL_CTSU          = (18)
} elc_peripheral_t;

/** Positions of event link set registers (ELSRs) available on this MCU */
#define BSP_ELC_PERIPHERAL_MASK  (0x0007FFFFU)

/* UNCRUSTIFY-ON */
/** @} (end addtogroup BSP_MCU_RA6M3) */

#endif
