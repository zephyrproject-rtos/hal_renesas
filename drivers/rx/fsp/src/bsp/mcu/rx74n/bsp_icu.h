/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_ICU_H
#define BSP_ICU_H

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RX74N
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Events to be used with the IELSR register to link interrupt events to the NVIC
 * @note This list is device specific.
 * */
typedef enum e_icu_event_rx74n
{
    ICU_EVENT_NONE = (0x00),

    /* Interrupt sources for software configurable interrupt */

    ICU_EVENT_CMT2_CMI                = (0x80),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CMT3_CMI                = (0x81),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR0_COMPARE_A          = (0x82),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR0_COMPARE_B          = (0x83),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR0_OVERFLOW           = (0x84),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR1_COMPARE_A          = (0x85),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR1_COMPARE_B          = (0x86),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR1_OVERFLOW           = (0x87),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR2_COMPARE_A          = (0x88),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR2_COMPARE_B          = (0x89),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR2_OVERFLOW           = (0x8A),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR3_COMPARE_A          = (0x8B),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR3_COMPARE_B          = (0x8C),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_TMR3_OVERFLOW           = (0x8D),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CMTW0_CAPTURE_CMWICR0   = (0x8E),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CMTW0_CAPTURE_CMWICR1   = (0x8F),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CMTW0_COMPARE_CMWOCR0   = (0x90),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CMTW0_COMPARE_CMWOCR1   = (0x91),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CMTW1_CAPTURE_CMWICR0   = (0x92),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CMTW1_CAPTURE_CMWICR1   = (0x93),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CMTW1_COMPARE_CMWOCR0   = (0x94),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CMTW1_COMPARE_CMWOCR1   = (0x95),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RTC_CARRY               = (0x96),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_USB0_STATUS             = (0x97),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_USB0_D0FIFO             = (0x98),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_USB0_D1FIFO             = (0x99),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ELC_ELSR88I             = (0x9A),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ELC_ELSR89I             = (0x9B),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ELC_ELSR90I             = (0x9C),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ELC_ELSR91I             = (0x9D),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_IOPORT_EVENT_B          = (0x9E),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_IOPORT_EVENT_C          = (0x9F),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_IOPORT_EVENT_D          = (0xA0),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_IOPORT_EVENT_E          = (0xA1),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_PDMIF_DAT0              = (0xA2),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_SDHI_SBFAI              = (0xA5),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_SSIE0_SSITXI            = (0xA7),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_SSIE0_SSIRXI            = (0xA8),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_SSIE1_SSITXI            = (0xA9),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_SSIE1_SSIRXI            = (0xAA),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_PDC_PCDFI               = (0xAB),      // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_CAPTURE_COMPARE_A  = (0x100),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_CAPTURE_COMPARE_B  = (0x101),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_COMPARE_C          = (0x102),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_COMPARE_D          = (0x103),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_DEAD_TIME_ERROR    = (0x104),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_COMPARE_E          = (0x105),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_COMPARE_F          = (0x106),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_COUNTER_OVERFLOW   = (0x107),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_COUNTER_UNDERFLOW  = (0x108),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT0_GTCEI0             = (0x109),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_CAPTURE_COMPARE_A  = (0x10B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_CAPTURE_COMPARE_B  = (0x10C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_COMPARE_C          = (0x10D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_COMPARE_D          = (0x10E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_DEAD_TIME_ERROR    = (0x10F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_COMPARE_E          = (0x110),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_COMPARE_F          = (0x111),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_COUNTER_OVERFLOW   = (0x112),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_COUNTER_UNDERFLOW  = (0x113),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT1_GTCEI1             = (0x114),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_CAPTURE_COMPARE_A  = (0x116),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_CAPTURE_COMPARE_B  = (0x117),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_COMPARE_C          = (0x118),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_COMPARE_D          = (0x119),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_DEAD_TIME_ERROR    = (0x11A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_COMPARE_E          = (0x11B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_COMPARE_F          = (0x11C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_COUNTER_OVERFLOW   = (0x11D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_COUNTER_UNDERFLOW  = (0x11E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT2_GTCEI2             = (0x11F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_CAPTURE_COMPARE_A  = (0x121),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_CAPTURE_COMPARE_B  = (0x122),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_COMPARE_C          = (0x123),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_COMPARE_D          = (0x124),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_DEAD_TIME_ERROR    = (0x125),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_COMPARE_E          = (0x126),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_COMPARE_F          = (0x127),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_COUNTER_OVERFLOW   = (0x128),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_COUNTER_UNDERFLOW  = (0x129),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT3_GTCEI3             = (0x12A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_CAPTURE_COMPARE_A  = (0x12C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_CAPTURE_COMPARE_B  = (0x12D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_COMPARE_C          = (0x12E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_COMPARE_D          = (0x12F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_DEAD_TIME_ERROR    = (0x130),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_COMPARE_E          = (0x131),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_COMPARE_F          = (0x132),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_COUNTER_OVERFLOW   = (0x133),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_COUNTER_UNDERFLOW  = (0x134),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT4_GTCEI4             = (0x135),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_CAPTURE_COMPARE_A  = (0x137),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_CAPTURE_COMPARE_B  = (0x138),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_COMPARE_C          = (0x139),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_COMPARE_D          = (0x13A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_DEAD_TIME_ERROR    = (0x13B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_COMPARE_E          = (0x13C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_COMPARE_F          = (0x13D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_COUNTER_OVERFLOW   = (0x13E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_COUNTER_UNDERFLOW  = (0x13F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT5_GTCEI5             = (0x140),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_CAPTURE_COMPARE_A  = (0x142),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_CAPTURE_COMPARE_B  = (0x143),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_COMPARE_C          = (0x144),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_COMPARE_D          = (0x145),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_DEAD_TIME_ERROR    = (0x146),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_COMPARE_E          = (0x147),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_COMPARE_F          = (0x148),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_COUNTER_OVERFLOW   = (0x149),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_COUNTER_UNDERFLOW  = (0x14A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT6_GTCEI6             = (0x14B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_CAPTURE_COMPARE_A  = (0x14D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_CAPTURE_COMPARE_B  = (0x14E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_COMPARE_C          = (0x14F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_COMPARE_D          = (0x150),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_DEAD_TIME_ERROR    = (0x151),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_COMPARE_E          = (0x152),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_COMPARE_F          = (0x153),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_COUNTER_OVERFLOW   = (0x154),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_COUNTER_UNDERFLOW  = (0x155),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT7_GTCEI7             = (0x156),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_CAPTURE_COMPARE_A  = (0x158),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_CAPTURE_COMPARE_B  = (0x159),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_COMPARE_C          = (0x15A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_COMPARE_D          = (0x15B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_DEAD_TIME_ERROR    = (0x15C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_COMPARE_E          = (0x15D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_COMPARE_F          = (0x15E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_COUNTER_OVERFLOW   = (0x15F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_COUNTER_UNDERFLOW  = (0x160),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT8_GTCEI8             = (0x161),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_CAPTURE_COMPARE_A  = (0x163),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_CAPTURE_COMPARE_B  = (0x164),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_COMPARE_C          = (0x165),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_COMPARE_D          = (0x166),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_DEAD_TIME_ERROR    = (0x167),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_COMPARE_E          = (0x168),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_COMPARE_F          = (0x169),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_COUNTER_OVERFLOW   = (0x16A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_COUNTER_UNDERFLOW  = (0x16B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT9_GTCEI9             = (0x16C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_CAPTURE_COMPARE_A = (0x16E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_CAPTURE_COMPARE_B = (0x16F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_COMPARE_C         = (0x170),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_COMPARE_D         = (0x171),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_DEAD_TIME_ERROR   = (0x172),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_COMPARE_E         = (0x173),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_COMPARE_F         = (0x174),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_COUNTER_OVERFLOW  = (0x175),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_COUNTER_UNDERFLOW = (0x176),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT10_GTCEI10           = (0x177),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_CAPTURE_COMPARE_A = (0x179),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_CAPTURE_COMPARE_B = (0x17A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_COMPARE_C         = (0x17B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_COMPARE_D         = (0x17C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_DEAD_TIME_ERROR   = (0x17D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_COMPARE_E         = (0x17E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_COMPARE_F         = (0x17F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_COUNTER_OVERFLOW  = (0x180),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_COUNTER_UNDERFLOW = (0x181),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT11_GTCEI11           = (0x182),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_CAPTURE_COMPARE_A = (0x184),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_CAPTURE_COMPARE_B = (0x185),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_COMPARE_C         = (0x186),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_COMPARE_D         = (0x187),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_DEAD_TIME_ERROR   = (0x188),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_COMPARE_E         = (0x189),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_COMPARE_F         = (0x18A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_COUNTER_OVERFLOW  = (0x18B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_COUNTER_UNDERFLOW = (0x18C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT12_GTCEI12           = (0x18D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_CAPTURE_COMPARE_A = (0x18F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_CAPTURE_COMPARE_B = (0x190),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_COMPARE_C         = (0x191),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_COMPARE_D         = (0x192),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_DEAD_TIME_ERROR   = (0x193),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_COMPARE_E         = (0x194),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_COMPARE_F         = (0x195),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_COUNTER_OVERFLOW  = (0x196),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_COUNTER_UNDERFLOW = (0x197),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT13_GTCEI13           = (0x198),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_CAPTURE_COMPARE_A = (0x19A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_CAPTURE_COMPARE_B = (0x19B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_COMPARE_C         = (0x19C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_COMPARE_D         = (0x19D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_DEAD_TIME_ERROR   = (0x19E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_COMPARE_E         = (0x19F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_COMPARE_F         = (0x1A0),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_COUNTER_OVERFLOW  = (0x1A1),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_COUNTER_UNDERFLOW = (0x1A2),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT14_GTCEI14           = (0x1A3),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_CAPTURE_COMPARE_A = (0x1A5),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_CAPTURE_COMPARE_B = (0x1A6),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_COMPARE_C         = (0x1A7),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_COMPARE_D         = (0x1A8),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_DEAD_TIME_ERROR   = (0x1A9),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_COMPARE_E         = (0x1AA),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_COMPARE_F         = (0x1AB),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_COUNTER_OVERFLOW  = (0x1AC),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_COUNTER_UNDERFLOW = (0x1AD),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPT15_GTCEI15           = (0x1AE),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPTP_PTPOUT0            = (0x278),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPTP_PTPOUT1            = (0x279),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPTP0_MATCH             = (0x27C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_GPTP1_MATCH             = (0x27D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_USBHS_D0FIFO            = (0x286),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_USBHS_D1FIFO            = (0x287),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI0_RXI               = (0x288),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI0_TXI               = (0x289),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI0_AED               = (0x28A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI1_RXI               = (0x28B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI1_TXI               = (0x28C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI1_AED               = (0x28D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI2_RXI               = (0x28E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI2_TXI               = (0x28F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI2_AED               = (0x290),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI3_RXI               = (0x291),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI3_TXI               = (0x292),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI3_AED               = (0x293),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI4_RXI               = (0x294),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI4_TXI               = (0x295),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI4_AED               = (0x296),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI5_RXI               = (0x297),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI5_TXI               = (0x298),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI5_AED               = (0x299),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI6_RXI               = (0x29A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI6_TXI               = (0x29B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI6_AED               = (0x29C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI7_RXI               = (0x29D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI7_TXI               = (0x29E),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI7_AED               = (0x29F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI8_RXI               = (0x2A0),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI8_TXI               = (0x2A1),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI8_AED               = (0x2A2),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI9_RXI               = (0x2A3),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI9_TXI               = (0x2A4),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI9_AED               = (0x2A5),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI10_RXI              = (0x2A6),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI10_TXI              = (0x2A7),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI10_AED              = (0x2A8),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI11_RXI              = (0x2A9),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI11_TXI              = (0x2AA),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI11_AED              = (0x2AB),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI12_RXI              = (0x2AC),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI12_TXI              = (0x2AD),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSCI12_AED              = (0x2AE),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RIIC0_RXI               = (0x2B8),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RIIC0_TXI               = (0x2B9),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RIIC1_RXI               = (0x2B1),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RIIC1_TXI               = (0x2B2),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RIIC2_RXI               = (0x2B3),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RIIC2_TXI               = (0x2B4),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_RESPI             = (0x2B5),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_CMDI              = (0x2B6),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_IBII              = (0x2B7),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_RXI               = (0x2B8),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_TXI               = (0x2B9),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_RCVI              = (0x2BA),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_HRESPI            = (0x2BB),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_HCMDI             = (0x2BC),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_HRXI              = (0x2BD),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RI3C0_HTXI              = (0x2BE),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSPI0_SPRI              = (0x2D3),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSPI0_SPTI              = (0x2D4),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSPI0_SPCI              = (0x2D5),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSPI1_SPRI              = (0x2D6),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSPI1_SPTI              = (0x2D7),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSPI1_SPCI              = (0x2D8),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSPI2_SPRI              = (0x2D9),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSPI2_SPTI              = (0x2DA),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSPI2_SPCI              = (0x2DB),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_RFDREQ0         = (0x2DC),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_RFDREQ1         = (0x2DD),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_RFDREQ2         = (0x2DE),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_RFDREQ3         = (0x2DF),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_RFDREQ4         = (0x2E0),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_RFDREQ5         = (0x2E1),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_RFDREQ6         = (0x2E2),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_RFDREQ7         = (0x2E3),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFD0_CFDREQ           = (0x2E4),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFD1_CFDREQ           = (0x2E5),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_AFLRAM0EI       = (0x2F0),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_AFLRAM1EI       = (0x2F1),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFDG0_MBRMAEI         = (0x2F2),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFD_RFDREQ0           = (0x2F6),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFD_RFDREQ1           = (0x2F7),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFD2_CFDREQ           = (0x2F8),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_CANFD_MBRMAEI           = (0x2FF),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI0                = (0x302),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI1                = (0x303),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI2                = (0x304),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI3                = (0x305),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI4                = (0x306),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI5                = (0x307),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI6                = (0x308),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI7                = (0x309),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI8                = (0x30A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI9                = (0x30B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI10               = (0x30C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_ADI11               = (0x30D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ0            = (0x312),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ1            = (0x313),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ2            = (0x314),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ3            = (0x315),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ4            = (0x316),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ5            = (0x317),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ6            = (0x318),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ7            = (0x319),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ8            = (0x31A),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ9            = (0x31B),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ10           = (0x31C),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_FIFOREQ11           = (0x31D),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPM0              = (0x322),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPM1              = (0x323),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPM2              = (0x324),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPM3              = (0x325),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPM4              = (0x326),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPM5              = (0x327),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPM6              = (0x328),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPM7              = (0x329),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPUM0             = (0x332),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPUM1             = (0x333),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPUM2             = (0x334),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPUM3             = (0x335),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPUM4             = (0x336),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPUM5             = (0x337),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPUM6             = (0x338),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ADC_CCMPUM7             = (0x339),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_RSIP_TADI               = (0x34F),     // Selectable interrupt (SLIXR128-143 or SLIR144-255)
    ICU_EVENT_ICU_IRQ16               = (0x3FF),     // Selectable interrupt (SLIXR128)
    ICU_EVENT_ICU_IRQ17               = (0x3FF),     // Selectable interrupt (SLIXR129)
    ICU_EVENT_ICU_IRQ18               = (0x3FF),     // Selectable interrupt (SLIXR130)
    ICU_EVENT_ICU_IRQ19               = (0x3FF),     // Selectable interrupt (SLIXR131)
    ICU_EVENT_ICU_IRQ20               = (0x3FF),     // Selectable interrupt (SLIXR132)
    ICU_EVENT_ICU_IRQ21               = (0x3FF),     // Selectable interrupt (SLIXR133)
    ICU_EVENT_ICU_IRQ22               = (0x3FF),     // Selectable interrupt (SLIXR134)
    ICU_EVENT_ICU_IRQ23               = (0x3FF),     // Selectable interrupt (SLIXR135)
    ICU_EVENT_ICU_IRQ24               = (0x3FF),     // Selectable interrupt (SLIXR136)
    ICU_EVENT_ICU_IRQ25               = (0x3FF),     // Selectable interrupt (SLIXR137)
    ICU_EVENT_ICU_IRQ26               = (0x3FF),     // Selectable interrupt (SLIXR138)
    ICU_EVENT_ICU_IRQ27               = (0x3FF),     // Selectable interrupt (SLIXR139)
    ICU_EVENT_ICU_IRQ28               = (0x3FF),     // Selectable interrupt (SLIXR140)
    ICU_EVENT_ICU_IRQ29               = (0x3FF),     // Selectable interrupt (SLIXR141)
    ICU_EVENT_ICU_IRQ30               = (0x3FF),     // Selectable interrupt (SLIXR142)
    ICU_EVENT_ICU_IRQ31               = (0x3FF),     // Selectable interrupt (SLIXR143)

    /* Start of non-shared IELSR.
     * These events are directly mapped to the ICU and are treated as if they are the sole event elements of a group.
     */
    ICU_EVENT_FIXED_BSC_BUSERR      = (0x10),        // IELSR16
    ICU_EVENT_FIXED_ICU_GROUPIL0    = (0x11),        // IELSR17
    ICU_EVENT_FIXED_ICU_GROUPIL0_NS = (0x12),        // IELSR18
    ICU_EVENT_FIXED_ICU_SWINT2      = (0x1A),        // IELSR26
    ICU_EVENT_FIXED_ICU_SWINT       = (0x1B),        // IELSR27
    ICU_EVENT_FIXED_CMT0_CMI        = (0x1C),        // IELSR28
    ICU_EVENT_FIXED_CMT1_CMI        = (0x1D),        // IELSR29
    ICU_EVENT_FIXED_CMTW0_CMWI      = (0x1E),        // IELSR30
    ICU_EVENT_FIXED_CMTW1_CMWI      = (0x1F),        // IELSR31
    ICU_EVENT_FIXED_MRAM_MRDYI      = (0x20),        // IELSR32
    ICU_EVENT_FIXED_MRAM_MRPRRI     = (0x21),        // IELSR33
    ICU_EVENT_FIXED_ICU_IRQ0        = (0x40),        // IELSR64
    ICU_EVENT_FIXED_ICU_IRQ1        = (0x41),        // IELSR65
    ICU_EVENT_FIXED_ICU_IRQ2        = (0x42),        // IELSR66
    ICU_EVENT_FIXED_ICU_IRQ3        = (0x43),        // IELSR67
    ICU_EVENT_FIXED_ICU_IRQ4        = (0x44),        // IELSR68
    ICU_EVENT_FIXED_ICU_IRQ5        = (0x45),        // IELSR69
    ICU_EVENT_FIXED_ICU_IRQ6        = (0x46),        // IELSR70
    ICU_EVENT_FIXED_ICU_IRQ7        = (0x47),        // IELSR71
    ICU_EVENT_FIXED_ICU_IRQ8        = (0x48),        // IELSR72
    ICU_EVENT_FIXED_ICU_IRQ9        = (0x49),        // IELSR73
    ICU_EVENT_FIXED_ICU_IRQ10       = (0x4A),        // IELSR74
    ICU_EVENT_FIXED_ICU_IRQ11       = (0x4B),        // IELSR75
    ICU_EVENT_FIXED_ICU_IRQ12       = (0x4C),        // IELSR76
    ICU_EVENT_FIXED_ICU_IRQ13       = (0x4D),        // IELSR77
    ICU_EVENT_FIXED_ICU_IRQ14       = (0x4E),        // IELSR78
    ICU_EVENT_FIXED_ICU_IRQ15       = (0x4F),        // IELSR79
    ICU_EVENT_FIXED_RI3C0_WUI       = (0x50),        // IELSR80
    ICU_EVENT_FIXED_RIIC1_WUI       = (0x51),        // IELSR81
    ICU_EVENT_FIXED_RIIC2_WUI       = (0x52),        // IELSR82
    ICU_EVENT_FIXED_VBATT_TAMPDI    = (0x53),        // IELSR83
    ICU_EVENT_FIXED_PDM_SDET        = (0x54),        // IELSR84
    ICU_EVENT_FIXED_SOST_SOSTDI     = (0x55),        // IELSR85
    ICU_EVENT_FIXED_PVD_PVD1        = (0x58),        // IELSR88
    ICU_EVENT_FIXED_PVD_PVD2        = (0x59),        // IELSR89
    ICU_EVENT_FIXED_USB0_USBR       = (0x5A),        // IELSR90
    ICU_EVENT_FIXED_RTC_ALARM       = (0x5C),        // IELSR92
    ICU_EVENT_FIXED_RTC_PERIOD      = (0x5D),        // IELSR93
    ICU_EVENT_FIXED_USBHS_USBHSR    = (0x5E),        // IELSR94
    ICU_EVENT_FIXED_IWDT_IWUNI      = (0x5F),        // IELSR95
    ICU_EVENT_FIXED_WDT_WUNI        = (0x60),        // IELSR96
    ICU_EVENT_FIXED_ICU_GROUPBL0    = (0x66),        // IELSR102
    ICU_EVENT_FIXED_ICU_GROUPBL1    = (0x67),        // IELSR103
    ICU_EVENT_FIXED_ICU_GROUPAL0    = (0x68),        // IELSR104
    ICU_EVENT_FIXED_ICU_GROUPAL1    = (0x69),        // IELSR105
    ICU_EVENT_FIXED_ICU_GROUPAL2    = (0x6A),        // IELSR106
    ICU_EVENT_FIXED_ICU_GROUPAL3    = (0x6B),        // IELSR107
    ICU_EVENT_FIXED_ICU_GROUPAL4    = (0x6C),        // IELSR108
    ICU_EVENT_FIXED_ICU_GROUPAL5    = (0x6D),        // IELSR109
    ICU_EVENT_FIXED_ICU_GROUPAL6    = (0x6E),        // IELSR110
    ICU_EVENT_FIXED_ICU_GROUPBL0_NS = (0x6F),        // IELSR111
    ICU_EVENT_FIXED_ICU_GROUPBL1_NS = (0x70),        // IELSR112
    ICU_EVENT_FIXED_ICU_GROUPAL0_NS = (0x71),        // IELSR113
    ICU_EVENT_FIXED_ICU_GROUPAL1_NS = (0x72),        // IELSR114
    ICU_EVENT_FIXED_ICU_GROUPAL2_NS = (0x73),        // IELSR115
    ICU_EVENT_FIXED_ICU_GROUPAL3_NS = (0x74),        // IELSR116
    ICU_EVENT_FIXED_ICU_GROUPAL4_NS = (0x75),        // IELSR117
    ICU_EVENT_FIXED_ICU_GROUPAL5_NS = (0x76),        // IELSR118
    ICU_EVENT_FIXED_ICU_GROUPAL6_NS = (0x77),        // IELSR119
    ICU_EVENT_FIXED_DMAC0_INT       = (0x78),        // IELSR120
    ICU_EVENT_FIXED_DMAC1_INT       = (0x79),        // IELSR121
    ICU_EVENT_FIXED_DMAC2_INT       = (0x7A),        // IELSR122
    ICU_EVENT_FIXED_DMAC3_INT       = (0x7B),        // IELSR123
    ICU_EVENT_FIXED_DMAC74_INT      = (0x7C),        // IELSR124
    ICU_EVENT_FIXED_OST_OSTDI       = (0x7D),        // IELSR125
    ICU_EVENT_FIXED_EXDMAC_EXDMAC0I = (0x7E),        // IELSR126
    ICU_EVENT_FIXED_EXDMAC_EXDMAC1I = (0x7F),        // IELSR127
    ICU_EVENT_FIXED_ICU_IRQ16       = (0x80),        // IELSR128
    ICU_EVENT_FIXED_PERIX_SLIX128   = (0x80),        // IELSR128
    ICU_EVENT_FIXED_ICU_IRQ17       = (0x81),        // IELSR129
    ICU_EVENT_FIXED_PERIX_SLIX129   = (0x81),        // IELSR129
    ICU_EVENT_FIXED_ICU_IRQ18       = (0x82),        // IELSR130
    ICU_EVENT_FIXED_PERIX_SLIX130   = (0x82),        // IELSR130
    ICU_EVENT_FIXED_ICU_IRQ19       = (0x83),        // IELSR131
    ICU_EVENT_FIXED_PERIX_SLIX131   = (0x83),        // IELSR131
    ICU_EVENT_FIXED_ICU_IRQ20       = (0x84),        // IELSR132
    ICU_EVENT_FIXED_PERIX_SLIX132   = (0x84),        // IELSR132
    ICU_EVENT_FIXED_ICU_IRQ21       = (0x85),        // IELSR133
    ICU_EVENT_FIXED_PERIX_SLIX133   = (0x85),        // IELSR133
    ICU_EVENT_FIXED_ICU_IRQ22       = (0x86),        // IELSR134
    ICU_EVENT_FIXED_PERIX_SLIX134   = (0x86),        // IELSR134
    ICU_EVENT_FIXED_ICU_IRQ23       = (0x87),        // IELSR135
    ICU_EVENT_FIXED_PERIX_SLIX135   = (0x87),        // IELSR135
    ICU_EVENT_FIXED_ICU_IRQ24       = (0x88),        // IELSR136
    ICU_EVENT_FIXED_PERIX_SLIX136   = (0x88),        // IELSR136
    ICU_EVENT_FIXED_ICU_IRQ25       = (0x89),        // IELSR137
    ICU_EVENT_FIXED_PERIX_SLIX137   = (0x89),        // IELSR137
    ICU_EVENT_FIXED_ICU_IRQ26       = (0x8A),        // IELSR138
    ICU_EVENT_FIXED_PERIX_SLIX138   = (0x8A),        // IELSR138
    ICU_EVENT_FIXED_ICU_IRQ27       = (0x8B),        // IELSR139
    ICU_EVENT_FIXED_PERIX_SLIX139   = (0x8B),        // IELSR139
    ICU_EVENT_FIXED_ICU_IRQ28       = (0x8C),        // IELSR140
    ICU_EVENT_FIXED_PERIX_SLIX140   = (0x8C),        // IELSR140
    ICU_EVENT_FIXED_ICU_IRQ29       = (0x8D),        // IELSR141
    ICU_EVENT_FIXED_PERIX_SLIX141   = (0x8D),        // IELSR141
    ICU_EVENT_FIXED_ICU_IRQ30       = (0x8E),        // IELSR142
    ICU_EVENT_FIXED_PERIX_SLIX142   = (0x8E),        // IELSR142
    ICU_EVENT_FIXED_ICU_IRQ31       = (0x8F),        // IELSR143
    ICU_EVENT_FIXED_PERIX_SLIX143   = (0x8F),        // IELSR143
    ICU_EVENT_FIXED_PERI_SLI144     = (0x90),        // IELSR144
    ICU_EVENT_FIXED_PERI_SLI145     = (0x91),        // IELSR145
    ICU_EVENT_FIXED_PERI_SLI146     = (0x92),        // IELSR146
    ICU_EVENT_FIXED_PERI_SLI147     = (0x93),        // IELSR147
    ICU_EVENT_FIXED_PERI_SLI148     = (0x94),        // IELSR148
    ICU_EVENT_FIXED_PERI_SLI149     = (0x95),        // IELSR149
    ICU_EVENT_FIXED_PERI_SLI150     = (0x96),        // IELSR150
    ICU_EVENT_FIXED_PERI_SLI151     = (0x97),        // IELSR151
    ICU_EVENT_FIXED_PERI_SLI152     = (0x98),        // IELSR152
    ICU_EVENT_FIXED_PERI_SLI153     = (0x99),        // IELSR153
    ICU_EVENT_FIXED_PERI_SLI154     = (0x9A),        // IELSR154
    ICU_EVENT_FIXED_PERI_SLI155     = (0x9B),        // IELSR155
    ICU_EVENT_FIXED_PERI_SLI156     = (0x9C),        // IELSR156
    ICU_EVENT_FIXED_PERI_SLI157     = (0x9D),        // IELSR157
    ICU_EVENT_FIXED_PERI_SLI158     = (0x9E),        // IELSR158
    ICU_EVENT_FIXED_PERI_SLI159     = (0x9F),        // IELSR159
    ICU_EVENT_FIXED_PERI_SLI160     = (0xA0),        // IELSR160
    ICU_EVENT_FIXED_PERI_SLI161     = (0xA1),        // IELSR161
    ICU_EVENT_FIXED_PERI_SLI162     = (0xA2),        // IELSR162
    ICU_EVENT_FIXED_PERI_SLI163     = (0xA3),        // IELSR163
    ICU_EVENT_FIXED_PERI_SLI164     = (0xA4),        // IELSR164
    ICU_EVENT_FIXED_PERI_SLI165     = (0xA5),        // IELSR165
    ICU_EVENT_FIXED_PERI_SLI166     = (0xA6),        // IELSR166
    ICU_EVENT_FIXED_PERI_SLI167     = (0xA7),        // IELSR167
    ICU_EVENT_FIXED_PERI_SLI168     = (0xA8),        // IELSR168
    ICU_EVENT_FIXED_PERI_SLI169     = (0xA9),        // IELSR169
    ICU_EVENT_FIXED_PERI_SLI170     = (0xAA),        // IELSR170
    ICU_EVENT_FIXED_PERI_SLI171     = (0xAB),        // IELSR171
    ICU_EVENT_FIXED_PERI_SLI172     = (0xAC),        // IELSR172
    ICU_EVENT_FIXED_PERI_SLI173     = (0xAD),        // IELSR173
    ICU_EVENT_FIXED_PERI_SLI174     = (0xAE),        // IELSR174
    ICU_EVENT_FIXED_PERI_SLI175     = (0xAF),        // IELSR175
    ICU_EVENT_FIXED_PERI_SLI176     = (0xB0),        // IELSR176
    ICU_EVENT_FIXED_PERI_SLI177     = (0xB1),        // IELSR177
    ICU_EVENT_FIXED_PERI_SLI178     = (0xB2),        // IELSR178
    ICU_EVENT_FIXED_PERI_SLI179     = (0xB3),        // IELSR179
    ICU_EVENT_FIXED_PERI_SLI180     = (0xB4),        // IELSR180
    ICU_EVENT_FIXED_PERI_SLI181     = (0xB5),        // IELSR181
    ICU_EVENT_FIXED_PERI_SLI182     = (0xB6),        // IELSR182
    ICU_EVENT_FIXED_PERI_SLI183     = (0xB7),        // IELSR183
    ICU_EVENT_FIXED_PERI_SLI184     = (0xB8),        // IELSR184
    ICU_EVENT_FIXED_PERI_SLI185     = (0xB9),        // IELSR185
    ICU_EVENT_FIXED_PERI_SLI186     = (0xBA),        // IELSR186
    ICU_EVENT_FIXED_PERI_SLI187     = (0xBB),        // IELSR187
    ICU_EVENT_FIXED_PERI_SLI188     = (0xBC),        // IELSR188
    ICU_EVENT_FIXED_PERI_SLI189     = (0xBD),        // IELSR189
    ICU_EVENT_FIXED_PERI_SLI190     = (0xBE),        // IELSR190
    ICU_EVENT_FIXED_PERI_SLI191     = (0xBF),        // IELSR191
    ICU_EVENT_FIXED_PERI_SLI192     = (0xC0),        // IELSR192
    ICU_EVENT_FIXED_PERI_SLI193     = (0xC1),        // IELSR193
    ICU_EVENT_FIXED_PERI_SLI194     = (0xC2),        // IELSR194
    ICU_EVENT_FIXED_PERI_SLI195     = (0xC3),        // IELSR195
    ICU_EVENT_FIXED_PERI_SLI196     = (0xC4),        // IELSR196
    ICU_EVENT_FIXED_PERI_SLI197     = (0xC5),        // IELSR197
    ICU_EVENT_FIXED_PERI_SLI198     = (0xC6),        // IELSR198
    ICU_EVENT_FIXED_PERI_SLI199     = (0xC7),        // IELSR199
    ICU_EVENT_FIXED_PERI_SLI200     = (0xC8),        // IELSR200
    ICU_EVENT_FIXED_PERI_SLI201     = (0xC9),        // IELSR201
    ICU_EVENT_FIXED_PERI_SLI202     = (0xCA),        // IELSR202
    ICU_EVENT_FIXED_PERI_SLI203     = (0xCB),        // IELSR203
    ICU_EVENT_FIXED_PERI_SLI204     = (0xCC),        // IELSR204
    ICU_EVENT_FIXED_PERI_SLI205     = (0xCD),        // IELSR205
    ICU_EVENT_FIXED_PERI_SLI206     = (0xCE),        // IELSR206
    ICU_EVENT_FIXED_PERI_SLI207     = (0xCF),        // IELSR207
    ICU_EVENT_FIXED_PERI_SLI208     = (0xD0),        // IELSR208
    ICU_EVENT_FIXED_PERI_SLI209     = (0xD1),        // IELSR209
    ICU_EVENT_FIXED_PERI_SLI210     = (0xD2),        // IELSR210
    ICU_EVENT_FIXED_PERI_SLI211     = (0xD3),        // IELSR211
    ICU_EVENT_FIXED_PERI_SLI212     = (0xD4),        // IELSR212
    ICU_EVENT_FIXED_PERI_SLI213     = (0xD5),        // IELSR213
    ICU_EVENT_FIXED_PERI_SLI214     = (0xD6),        // IELSR214
    ICU_EVENT_FIXED_PERI_SLI215     = (0xD7),        // IELSR215
    ICU_EVENT_FIXED_PERI_SLI216     = (0xD8),        // IELSR216
    ICU_EVENT_FIXED_PERI_SLI217     = (0xD9),        // IELSR217
    ICU_EVENT_FIXED_PERI_SLI218     = (0xDA),        // IELSR218
    ICU_EVENT_FIXED_PERI_SLI219     = (0xDB),        // IELSR219
    ICU_EVENT_FIXED_PERI_SLI220     = (0xDC),        // IELSR220
    ICU_EVENT_FIXED_PERI_SLI221     = (0xDD),        // IELSR221
    ICU_EVENT_FIXED_PERI_SLI222     = (0xDE),        // IELSR222
    ICU_EVENT_FIXED_PERI_SLI223     = (0xDF),        // IELSR223
    ICU_EVENT_FIXED_PERI_SLI224     = (0xE0),        // IELSR224
    ICU_EVENT_FIXED_PERI_SLI225     = (0xE1),        // IELSR225
    ICU_EVENT_FIXED_PERI_SLI226     = (0xE2),        // IELSR226
    ICU_EVENT_FIXED_PERI_SLI227     = (0xE3),        // IELSR227
    ICU_EVENT_FIXED_PERI_SLI228     = (0xE4),        // IELSR228
    ICU_EVENT_FIXED_PERI_SLI229     = (0xE5),        // IELSR229
    ICU_EVENT_FIXED_PERI_SLI230     = (0xE6),        // IELSR230
    ICU_EVENT_FIXED_PERI_SLI231     = (0xE7),        // IELSR231
    ICU_EVENT_FIXED_PERI_SLI232     = (0xE8),        // IELSR232
    ICU_EVENT_FIXED_PERI_SLI233     = (0xE9),        // IELSR233
    ICU_EVENT_FIXED_PERI_SLI234     = (0xEA),        // IELSR234
    ICU_EVENT_FIXED_PERI_SLI235     = (0xEB),        // IELSR235
    ICU_EVENT_FIXED_PERI_SLI236     = (0xEC),        // IELSR236
    ICU_EVENT_FIXED_PERI_SLI237     = (0xED),        // IELSR237
    ICU_EVENT_FIXED_PERI_SLI238     = (0xEE),        // IELSR238
    ICU_EVENT_FIXED_PERI_SLI239     = (0xEF),        // IELSR239
    ICU_EVENT_FIXED_PERI_SLI240     = (0xF0),        // IELSR240
    ICU_EVENT_FIXED_PERI_SLI241     = (0xF1),        // IELSR241
    ICU_EVENT_FIXED_PERI_SLI242     = (0xF2),        // IELSR242
    ICU_EVENT_FIXED_PERI_SLI243     = (0xF3),        // IELSR243
    ICU_EVENT_FIXED_PERI_SLI244     = (0xF4),        // IELSR244
    ICU_EVENT_FIXED_PERI_SLI245     = (0xF5),        // IELSR245
    ICU_EVENT_FIXED_PERI_SLI246     = (0xF6),        // IELSR246
    ICU_EVENT_FIXED_PERI_SLI247     = (0xF7),        // IELSR247
    ICU_EVENT_FIXED_PERI_SLI248     = (0xF8),        // IELSR248
    ICU_EVENT_FIXED_PERI_SLI249     = (0xF9),        // IELSR249
    ICU_EVENT_FIXED_PERI_SLI250     = (0xFA),        // IELSR250
    ICU_EVENT_FIXED_PERI_SLI251     = (0xFB),        // IELSR251
    ICU_EVENT_FIXED_PERI_SLI252     = (0xFC),        // IELSR252
    ICU_EVENT_FIXED_PERI_SLI253     = (0xFD),        // IELSR253
    ICU_EVENT_FIXED_PERI_SLI254     = (0xFE),        // IELSR254
    ICU_EVENT_FIXED_PERI_SLI255     = (0xFF),        // IELSR255

    /* Interrupt factors assigned to group interrupts. */
    ICU_EVENT_GROUP_DPFPU_DPFPUEX        = (0x0011), // Double-precision floating-point exception
    ICU_EVENT_GROUP_LM0_ERR              = (0x0111), // Local memory error
    ICU_EVENT_GROUP_CM_ERR               = (0x0211), // Common memory error
    ICU_EVENT_GROUP_BUS_HLDTO            = (0x0311), // External bus hold timeout
    ICU_EVENT_GROUP_MRAM_MRCRDI          = (0x0811), // Code MRAM ECC error
    ICU_EVENT_GROUP_MRAM_MRERDI          = (0x0911), // Extra MRAM ECC error
    ICU_EVENT_GROUP_MRAM_MRCPRI          = (0x0A11), // Code MRAM access error
    ICU_EVENT_GROUP_MRAM_MRDPRI          = (0x0B11), // Data MRAM access error
    ICU_EVENT_GROUP_MRAM_MREPRI          = (0x0C11), // Extra MRAM access error
    ICU_EVENT_GROUP_SDHI_CARD            = (0x0066), // Card detection interrupt
    ICU_EVENT_GROUP_SDHI_ACCS            = (0x0166), // Card access interrupt
    ICU_EVENT_GROUP_SDHI_SDIO            = (0x0266), // SDIO access interrupt
    ICU_EVENT_GROUP_XSPI0_CMP            = (0x0366), // xSPI0 completion interrupt
    ICU_EVENT_GROUP_XSPI0_ERR            = (0x0466), // xSPI0 error interrupt
    ICU_EVENT_GROUP_XSPI1_CMP            = (0x0566), // xSPI1 completion interrupt
    ICU_EVENT_GROUP_XSPI1_ERR            = (0x0666), // xSPI1 error interrupt
    ICU_EVENT_GROUP_SSIE0_INT            = (0x0766), // Status interrupt
    ICU_EVENT_GROUP_SSIE1_INT            = (0x0866), // Status interrupt
    ICU_EVENT_GROUP_PDC_PCFEI            = (0x0966), // Frame end interrupt
    ICU_EVENT_GROUP_PDC_PCERI            = (0x0A66), // Error interrupt
    ICU_EVENT_GROUP_PDMIF_ERR0           = (0x0B66), // Error interrupt
    ICU_EVENT_GROUP_CAC0_FREQUENCY_ERROR = (0x0067), // Frequency error
    ICU_EVENT_GROUP_CAC0_MEASUREMENT_END = (0x0167), // Measurement end
    ICU_EVENT_GROUP_CAC0_OVERFLOW        = (0x0267), // Overflow interrupt
    ICU_EVENT_GROUP_CAC1_FREQUENCY_ERROR = (0x0367), // Frequency error
    ICU_EVENT_GROUP_CAC1_MEASUREMENT_END = (0x0467), // Measurement end
    ICU_EVENT_GROUP_CAC1_OVERFLOW        = (0x0567), // Overflow interrupt
    ICU_EVENT_GROUP_CAC2_FREQUENCY_ERROR = (0x0667), // Frequency error
    ICU_EVENT_GROUP_CAC2_MEASUREMENT_END = (0x0767), // Measurement end
    ICU_EVENT_GROUP_CAC2_OVERFLOW        = (0x0867), // Overflow interrupt
    ICU_EVENT_GROUP_RSCI0_TEI            = (0x0068), // Transmit end
    ICU_EVENT_GROUP_RSCI0_ERI            = (0x0168), // Receive error
    ICU_EVENT_GROUP_RSCI0_BFD            = (0x0268), // Break field detection
    ICU_EVENT_GROUP_RSCI1_TEI            = (0x0368), // Transmit end
    ICU_EVENT_GROUP_RSCI1_ERI            = (0x0468), // Receive error
    ICU_EVENT_GROUP_RSCI1_BFD            = (0x0568), // Break field detection
    ICU_EVENT_GROUP_RSCI2_TEI            = (0x0668), // Transmit end
    ICU_EVENT_GROUP_RSCI2_ERI            = (0x0768), // Receive error
    ICU_EVENT_GROUP_RSCI2_BFD            = (0x0868), // Break field detection
    ICU_EVENT_GROUP_RSCI3_TEI            = (0x0968), // Transmit end
    ICU_EVENT_GROUP_RSCI3_ERI            = (0x0A68), // Receive error
    ICU_EVENT_GROUP_RSCI3_BFD            = (0x0B68), // Break field detection
    ICU_EVENT_GROUP_RSCI4_TEI            = (0x0C68), // Transmit end
    ICU_EVENT_GROUP_RSCI4_ERI            = (0x0D68), // Receive error
    ICU_EVENT_GROUP_RSCI4_BFD            = (0x0E68), // Break field detection
    ICU_EVENT_GROUP_RSCI5_TEI            = (0x0F68), // Transmit end
    ICU_EVENT_GROUP_RSCI5_ERI            = (0x1068), // Receive error
    ICU_EVENT_GROUP_RSCI5_BFD            = (0x1168), // Break field detection
    ICU_EVENT_GROUP_RSCI6_TEI            = (0x1268), // Transmit end
    ICU_EVENT_GROUP_RSCI6_ERI            = (0x1368), // Receive error
    ICU_EVENT_GROUP_RSCI6_BFD            = (0x1468), // Break field detection
    ICU_EVENT_GROUP_RSCI7_TEI            = (0x1568), // Transmit end
    ICU_EVENT_GROUP_RSCI7_ERI            = (0x1668), // Receive error
    ICU_EVENT_GROUP_RSCI7_BFD            = (0x1768), // Break field detection
    ICU_EVENT_GROUP_RSCI8_TEI            = (0x1868), // Transmit end
    ICU_EVENT_GROUP_RSCI8_ERI            = (0x1968), // Receive error
    ICU_EVENT_GROUP_RSCI8_BFD            = (0x1A68), // Break field detection
    ICU_EVENT_GROUP_RSCI9_TEI            = (0x1B68), // Transmit end
    ICU_EVENT_GROUP_RSCI9_ERI            = (0x1C68), // Receive error
    ICU_EVENT_GROUP_RSCI9_BFD            = (0x1D68), // Break field detection
    ICU_EVENT_GROUP_RSCI10_TEI           = (0x0069), // Transmit end
    ICU_EVENT_GROUP_RSCI10_ERI           = (0x0169), // Receive error
    ICU_EVENT_GROUP_RSCI10_BFD           = (0x0269), // Break field detection
    ICU_EVENT_GROUP_RSCI11_TEI           = (0x0369), // Transmit end
    ICU_EVENT_GROUP_RSCI11_ERI           = (0x0469), // Receive error
    ICU_EVENT_GROUP_RSCI11_BFD           = (0x0569), // Break field detection
    ICU_EVENT_GROUP_RSCI12_TEI           = (0x0669), // Transmit end
    ICU_EVENT_GROUP_RSCI12_ERI           = (0x0769), // Receive error
    ICU_EVENT_GROUP_RSCI12_BFD           = (0x0869), // Break field detection
    ICU_EVENT_GROUP_RIIC1_TEI            = (0x0B69), // Transmit end
    ICU_EVENT_GROUP_RIIC1_EEI            = (0x0C69), // Transmission error/transmission event
    ICU_EVENT_GROUP_RIIC2_TEI            = (0x0D69), // Transmit end
    ICU_EVENT_GROUP_RIIC2_EEI            = (0x0E69), // Transmission error/transmission event
    ICU_EVENT_GROUP_RIIC0_TEI            = (0x0F69), // Transmit end
    ICU_EVENT_GROUP_RIIC0_EEI            = (0x1069), // Transmission error/transmission event
    ICU_EVENT_GROUP_RI3C0_TEI            = (0x0F69), // Transmit end
    ICU_EVENT_GROUP_RI3C0_EEI            = (0x1069), // Transmission error/transmission event
    ICU_EVENT_GROUP_RSPI0_IDLE           = (0x1769), // Idle interrupt
    ICU_EVENT_GROUP_RSPI0_ERI            = (0x1869), // Error interrupt
    ICU_EVENT_GROUP_RSPI1_IDLE           = (0x1969), // Idle interrupt
    ICU_EVENT_GROUP_RSPI1_ERI            = (0x1A69), // Error interrupt
    ICU_EVENT_GROUP_RSPI2_IDLE           = (0x1B69), // Idle interrupt
    ICU_EVENT_GROUP_RSPI2_ERI            = (0x1C69), // Error interrupt
    ICU_EVENT_GROUP_DOC_INT              = (0x1E69), // Data operation circuit interrupt
    ICU_EVENT_GROUP_CANFDG0_RFRI         = (0x006A), // Receive FIFO interrupt
    ICU_EVENT_GROUP_CANFDG0_GLEI         = (0x016A), // Global error interrupt
    ICU_EVENT_GROUP_CANFD0_CHTI          = (0x026A), // Channel transmit interrupt
    ICU_EVENT_GROUP_CANFD0_CHEI          = (0x036A), // Channel error interrupt
    ICU_EVENT_GROUP_CANFD0_CHRI          = (0x046A), // Channel receive interrupt
    ICU_EVENT_GROUP_CANFD1_CHTI          = (0x056A), // Channel transmit interrupt
    ICU_EVENT_GROUP_CANFD1_CHEI          = (0x066A), // Channel error interrupt
    ICU_EVENT_GROUP_CANFD1_CHRI          = (0x076A), // Channel receive interrupt
    ICU_EVENT_GROUP_CANFD2_CHEI          = (0x106A), // Channel error interrupt
    ICU_EVENT_GROUP_CANFD2_CFRI          = (0x116A), // Common FIFO receive interrupt
    ICU_EVENT_GROUP_CANFD_GLEI           = (0x126A), // Global error interrupt
    ICU_EVENT_GROUP_CANFD_RFRI           = (0x136A), // Receive FIFO interrupt
    ICU_EVENT_GROUP_CANFD2_CHTI          = (0x146A), // Channel transmit interrupt
    ICU_EVENT_GROUP_CANFD_RMRI           = (0x156A), // Reception message buffer interrupt
    ICU_EVENT_GROUP_POEG0_EVENT          = (0x106B), // Group A interrupt
    ICU_EVENT_GROUP_POEG1_EVENT          = (0x116B), // Group B interrupt
    ICU_EVENT_GROUP_POEG2_EVENT          = (0x126B), // Group C interrupt
    ICU_EVENT_GROUP_POEG3_EVENT          = (0x136B), // Group D interrupt
    ICU_EVENT_GROUP_ETHER_FWEI           = (0x006C), // MFWD error interrupt
    ICU_EVENT_GROUP_ETHER_CAEI           = (0x016C), // COMA error interrupt
    ICU_EVENT_GROUP_ETHER_GWEI0          = (0x026C), // GWCA0 error interrupt
    ICU_EVENT_GROUP_ETHER_EAEI0          = (0x036C), // ETHA0 error interrupt
    ICU_EVENT_GROUP_ETHER_PTPSI0         = (0x056C), // gPTP Status Interrupt 0
    ICU_EVENT_GROUP_ETHER_PTPSI1         = (0x066C), // gPTP Status Interrupt 1
    ICU_EVENT_GROUP_ETHER_FWSI           = (0x076C), // MFWD status interrupt
    ICU_EVENT_GROUP_ETHER_SWSI           = (0x086C), // ESWM status interrupt
    ICU_EVENT_GROUP_ETHER_CAMI           = (0x096C), // COMA status interrupt
    ICU_EVENT_GROUP_ETHER_EASI0          = (0x0A6C), // ETHA0 status interrupt
    ICU_EVENT_GROUP_ETHER_GWDI0          = (0x0C6C), // GWCA0 data interrupt 0
    ICU_EVENT_GROUP_ETHER_GWDI1          = (0x0D6C), // GWCA0 data interrupt 1
    ICU_EVENT_GROUP_ETHER_GWDI2          = (0x0E6C), // GWCA0 data interrupt 2
    ICU_EVENT_GROUP_ETHER_GWDI3          = (0x0F6C), // GWCA0 data interrupt 3
    ICU_EVENT_GROUP_ETHER_GWDI4          = (0x106C), // GWCA0 data interrupt 4
    ICU_EVENT_GROUP_ETHER_GWDI5          = (0x116C), // GWCA0 data interrupt 5
    ICU_EVENT_GROUP_ETHER_GWDI6          = (0x126C), // GWCA0 data interrupt 6
    ICU_EVENT_GROUP_ETHER_GWDI7          = (0x136C), // GWCA0 data interrupt 7
    ICU_EVENT_GROUP_ETHER_TSDI0          = (0x146C), // GWCA0 time stamp interrupt 0
    ICU_EVENT_GROUP_ETHER_TSDI1          = (0x156C), // GWCA0 time stamp interrupt 1
    ICU_EVENT_GROUP_ETHER_MDIO0          = (0x166C), // ETHA0 MDIO interrupt
    ICU_EVENT_GROUP_ETHER_RMPI0          = (0x186C), // RMAC0 PHY interrupt
    ICU_EVENT_GROUP_ADC_LIMCLPI          = (0x006D), // Limiter clip
    ICU_EVENT_GROUP_ADC_FIFOOVF          = (0x016D), // FIFO overflow
    ICU_EVENT_GROUP_ADC_CMPI0            = (0x026D), // Compare match 0
    ICU_EVENT_GROUP_ADC_CMPI1            = (0x036D), // Compare match 1
    ICU_EVENT_GROUP_ADC_ERR0             = (0x046D), // ADC0 error
    ICU_EVENT_GROUP_ADC_RESOVF0          = (0x056D), // ADC0 conversion result overflow
    ICU_EVENT_GROUP_ADC_CALEND0          = (0x076D), // ADC0 calibration end interrupt
    ICU_EVENT_GROUP_ADC_CMPI2            = (0x086D), // Compare match 2
    ICU_EVENT_GROUP_ADC_CMPI3            = (0x096D), // Compare match 3
    ICU_EVENT_GROUP_ADC_ERR1             = (0x0A6D), // ADC1 error
    ICU_EVENT_GROUP_ADC_RESOVF1          = (0x0B6D), // ADC1 conversion result overflow
    ICU_EVENT_GROUP_ADC_CALEND1          = (0x0D6D), // ADC1 calibration end interrupt
    ICU_EVENT_GROUP_ADC_CMPI4            = (0x0E6D), // Compare match 4
    ICU_EVENT_GROUP_ADC_CMPI5            = (0x0F6D), // Compare match 5
    ICU_EVENT_GROUP_ADC_ERR2             = (0x106D), // ADC2 error
    ICU_EVENT_GROUP_ADC_RESOVF2          = (0x116D), // ADC2 conversion result overflow
    ICU_EVENT_GROUP_ADC_CALEND2          = (0x136D), // ADC2 calibration end interrupt
    ICU_EVENT_GROUP_ADC_CMPI6            = (0x146D), // Compare match 6
    ICU_EVENT_GROUP_ADC_CMPI7            = (0x156D), // Compare match 7
} icu_event_t;

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Which interrupts can have callbacks registered. */
typedef enum e_bsp_grp_irq_rx74n
{
    BSP_GRP_IRQ_IL0 = ICU_EVENT_FIXED_ICU_GROUPIL0,
    BSP_GRP_IRQ_BL0 = ICU_EVENT_FIXED_ICU_GROUPBL0,
    BSP_GRP_IRQ_BL1 = ICU_EVENT_FIXED_ICU_GROUPBL1,
    BSP_GRP_IRQ_AL0 = ICU_EVENT_FIXED_ICU_GROUPAL0,
    BSP_GRP_IRQ_AL1 = ICU_EVENT_FIXED_ICU_GROUPAL1,
    BSP_GRP_IRQ_AL2 = ICU_EVENT_FIXED_ICU_GROUPAL2,
    BSP_GRP_IRQ_AL3 = ICU_EVENT_FIXED_ICU_GROUPAL3,
    BSP_GRP_IRQ_AL4 = ICU_EVENT_FIXED_ICU_GROUPAL4,
    BSP_GRP_IRQ_AL5 = ICU_EVENT_FIXED_ICU_GROUPAL5,
    BSP_GRP_IRQ_AL6 = ICU_EVENT_FIXED_ICU_GROUPAL6,
} bsp_grp_irq_t;

/* Callback type. */
typedef void (* bsp_grp_irq_cb_t)(void);

typedef icu_event_t bsp_interrupt_event_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

void bsp_selectable_irq_cfg(void);

/*******************************************************************************************************************//**
 * Set selectable irq table value that user setting to selectable irq register.
 *
 * @param[out] p_base_addr              The p_base_addr is write base address of selectable irq register.
 * @param[in]  p_selectable_irq_table   The p_selectable_irq_table is uesr setting selectable irq table.
 * @param[in]  size                     The size is read range of p_selectable_irq_table array.
 *
 * @warning Do not call this function with values where size over p_selectable_irq_table allowd range.
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_set_selectable_irq_cfg (uint16_t * const                    p_base_addr,
                                                 bsp_interrupt_event_t const * const p_selectable_irq_table,
                                                 uint32_t                            size)
{
    for (uint32_t i = 0; i < size; i++)
    {
        p_base_addr[i] = (uint16_t) p_selectable_irq_table[i];
    }
}

/***********************************************************************************************************************
 * Inline Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief      Get the interrupt priority register number from the IRQ.
 *
 * @param[in]  irq The IRQ to get the the interrupt priority register number
 *
 * @return     interrupt priority register number
 **********************************************************************************************************************/
__STATIC_INLINE uint8_t bsp_get_interrupt_priority (uint8_t irq)
{
    /* Mappings interrupt priority register number. */
    switch (irq)
    {
        /* For BSC_BUSERR */
        case ICU_EVENT_FIXED_BSC_BUSERR:
        {
            irq = 0x00;
            break;
        }

        /* For ICU_GROUPSIL0 */
        case ICU_EVENT_FIXED_ICU_GROUPIL0:
        {
            irq = 0x01;
            break;
        }

        /* For ICU_GROUPIL0 */
        case ICU_EVENT_FIXED_ICU_GROUPIL0_NS:
        {
            irq = 0x02;
            break;
        }

        /* For ICU_SWINT2 */
        case ICU_EVENT_FIXED_ICU_SWINT2:
        {
            irq = 0x08;
            break;
        }

        /* For ICU_SWINT */
        case ICU_EVENT_FIXED_ICU_SWINT:
        {
            irq = 0x03;
            break;
        }

        /* For CMT0_CMI */
        case ICU_EVENT_FIXED_CMT0_CMI:
        {
            irq = 0x04;
            break;
        }

        /* For CMT1_CMI */
        case ICU_EVENT_FIXED_CMT1_CMI:
        {
            irq = 0x05;
            break;
        }

        /* For CMTW0_CMI  */
        case ICU_EVENT_FIXED_CMTW0_CMWI:
        {
            irq = 0x06;
            break;
        }

        /* For CMTW1_CMI  */
        case ICU_EVENT_FIXED_CMTW1_CMWI:
        {
            irq = 0x07;
            break;
        }

        default:
        {
            break;
        }
    }

    return irq;
}

/** @} (end addtogroup BSP_MCU_RX74N) */

#endif
