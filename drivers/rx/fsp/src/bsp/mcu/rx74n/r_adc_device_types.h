/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RX74N
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RX74N) */

#ifndef R_ADC_DEVICE_TYPES
#define R_ADC_DEVICE_TYPES

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define ADC_B_CHANNEL_MASK_EXT_OFFSET    (36U)

/* Define overrides required for this MCU. */
#define BSP_OVERRIDE_ADC_CHANNEL_T
#define BSP_OVERRIDE_ADC_SCAN_GROUP

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** ADC Clock source selection */
typedef enum e_adc_b_clock_source
{
    ADC_B_CLOCK_SOURCE_ADC   = 0,      ///< ADC Clock Source ADCCLK
    ADC_B_CLOCK_SOURCE_GPT   = 1,      ///< ADC Clock Source GPT
    ADC_B_CLOCK_SOURCE_PCLKA = 2       ///< ADC Clock Source PCLKA
} adc_b_clock_source_t;

/** ADC channels */
typedef enum e_adc_b_virtual_channel
{
    ADC_B_VIRTUAL_CHANNEL_0  = 0,      ///< ADC B virtual channel 0
    ADC_B_VIRTUAL_CHANNEL_1  = 1,      ///< ADC B virtual channel 1
    ADC_B_VIRTUAL_CHANNEL_2  = 2,      ///< ADC B virtual channel 2
    ADC_B_VIRTUAL_CHANNEL_3  = 3,      ///< ADC B virtual channel 3
    ADC_B_VIRTUAL_CHANNEL_4  = 4,      ///< ADC B virtual channel 4
    ADC_B_VIRTUAL_CHANNEL_5  = 5,      ///< ADC B virtual channel 5
    ADC_B_VIRTUAL_CHANNEL_6  = 6,      ///< ADC B virtual channel 6
    ADC_B_VIRTUAL_CHANNEL_7  = 7,      ///< ADC B virtual channel 7
    ADC_B_VIRTUAL_CHANNEL_8  = 8,      ///< ADC B virtual channel 8
    ADC_B_VIRTUAL_CHANNEL_9  = 9,      ///< ADC B virtual channel 9
    ADC_B_VIRTUAL_CHANNEL_10 = 10,     ///< ADC B virtual channel 10
    ADC_B_VIRTUAL_CHANNEL_11 = 11,     ///< ADC B virtual channel 11
    ADC_B_VIRTUAL_CHANNEL_12 = 12,     ///< ADC B virtual channel 12
    ADC_B_VIRTUAL_CHANNEL_13 = 13,     ///< ADC B virtual channel 13
    ADC_B_VIRTUAL_CHANNEL_14 = 14,     ///< ADC B virtual channel 14
    ADC_B_VIRTUAL_CHANNEL_15 = 15,     ///< ADC B virtual channel 15
    ADC_B_VIRTUAL_CHANNEL_16 = 16,     ///< ADC B virtual channel 16
    ADC_B_VIRTUAL_CHANNEL_17 = 17,     ///< ADC B virtual channel 17
    ADC_B_VIRTUAL_CHANNEL_18 = 18,     ///< ADC B virtual channel 18
    ADC_B_VIRTUAL_CHANNEL_19 = 19,     ///< ADC B virtual channel 19
    ADC_B_VIRTUAL_CHANNEL_20 = 20,     ///< ADC B virtual channel 20
    ADC_B_VIRTUAL_CHANNEL_21 = 21,     ///< ADC B virtual channel 21
    ADC_B_VIRTUAL_CHANNEL_22 = 22,     ///< ADC B virtual channel 22
    ADC_B_VIRTUAL_CHANNEL_23 = 23,     ///< ADC B virtual channel 23
    ADC_B_VIRTUAL_CHANNEL_24 = 24,     ///< ADC B virtual channel 24
    ADC_B_VIRTUAL_CHANNEL_25 = 25,     ///< ADC B virtual channel 25
    ADC_B_VIRTUAL_CHANNEL_26 = 26,     ///< ADC B virtual channel 26
    ADC_B_VIRTUAL_CHANNEL_27 = 27,     ///< ADC B virtual channel 27
    ADC_B_VIRTUAL_CHANNEL_28 = 28,     ///< ADC B virtual channel 28
    ADC_B_VIRTUAL_CHANNEL_29 = 29,     ///< ADC B virtual channel 29
    ADC_B_VIRTUAL_CHANNEL_30 = 30,     ///< ADC B virtual channel 30
    ADC_B_VIRTUAL_CHANNEL_31 = 31,     ///< ADC B virtual channel 31
    ADC_B_VIRTUAL_CHANNEL_32 = 32,     ///< ADC B virtual channel 32
    ADC_B_VIRTUAL_CHANNEL_33 = 33,     ///< ADC B virtual channel 33
    ADC_B_VIRTUAL_CHANNEL_34 = 34,     ///< ADC B virtual channel 34
    ADC_B_VIRTUAL_CHANNEL_35 = 35,     ///< ADC B virtual channel 35
    ADC_B_VIRTUAL_CHANNEL_36 = 36,     ///< ADC B virtual channel 36
    ADC_B_VIRTUAL_CHANNEL_37 = 37,     ///< ADC B virtual channel 37
    ADC_B_VIRTUAL_CHANNEL_38 = 38,     ///< ADC B virtual channel 38
    ADC_B_VIRTUAL_CHANNEL_39 = 39,     ///< ADC B virtual channel 39
    ADC_B_VIRTUAL_CHANNEL_40 = 40,     ///< ADC B virtual channel 40
    ADC_B_VIRTUAL_CHANNEL_41 = 41,     ///< ADC B virtual channel 41
    ADC_B_VIRTUAL_CHANNEL_42 = 42,     ///< ADC B virtual channel 42
    ADC_B_VIRTUAL_CHANNEL_43 = 43,     ///< ADC B virtual channel 43
    ADC_B_VIRTUAL_CHANNEL_44 = 44,     ///< ADC B virtual channel 44
    ADC_B_VIRTUAL_CHANNEL_45 = 45,     ///< ADC B virtual channel 45
    ADC_B_VIRTUAL_CHANNEL_46 = 46,     ///< ADC B virtual channel 46
    ADC_B_VIRTUAL_CHANNEL_47 = 47,     ///< ADC B virtual channel 47
    ADC_B_VIRTUAL_CHANNEL_48 = 48,     ///< ADC B virtual channel 48
    ADC_B_VIRTUAL_CHANNEL_49 = 49,     ///< ADC B virtual channel 49
    ADC_B_VIRTUAL_CHANNEL_COUNT        // Number of available ADC B virtual channels
} adc_b_virtual_channel_t;

/** ADC channels */
typedef enum e_adc_channel
{
    /* These channels map to physical pins */
    ADC_CHANNEL_0  = 0,                                                                                 ///< ADC channel 0
    ADC_CHANNEL_1  = 1,                                                                                 ///< ADC channel 1
    ADC_CHANNEL_2  = 2,                                                                                 ///< ADC channel 2
    ADC_CHANNEL_3  = 3,                                                                                 ///< ADC channel 3
    ADC_CHANNEL_4  = 4,                                                                                 ///< ADC channel 4
    ADC_CHANNEL_5  = 5,                                                                                 ///< ADC channel 5
    ADC_CHANNEL_6  = 6,                                                                                 ///< ADC channel 6
    ADC_CHANNEL_7  = 7,                                                                                 ///< ADC channel 7
    ADC_CHANNEL_8  = 8,                                                                                 ///< ADC channel 8
    ADC_CHANNEL_9  = 9,                                                                                 ///< ADC channel 9
    ADC_CHANNEL_10 = 10,                                                                                ///< ADC channel 10
    ADC_CHANNEL_11 = 11,                                                                                ///< ADC channel 11
    ADC_CHANNEL_12 = 12,                                                                                ///< ADC channel 12
    ADC_CHANNEL_13 = 13,                                                                                ///< ADC channel 13
    ADC_CHANNEL_14 = 14,                                                                                ///< ADC channel 14
    ADC_CHANNEL_15 = 15,                                                                                ///< ADC channel 15
    ADC_CHANNEL_16 = 16,                                                                                ///< ADC channel 16
    ADC_CHANNEL_17 = 17,                                                                                ///< ADC channel 17
    ADC_CHANNEL_18 = 18,                                                                                ///< ADC channel 18
    ADC_CHANNEL_19 = 19,                                                                                ///< ADC channel 19
    ADC_CHANNEL_20 = 20,                                                                                ///< ADC channel 20
    ADC_CHANNEL_21 = 21,                                                                                ///< ADC channel 21
    ADC_CHANNEL_22 = 22,                                                                                ///< ADC channel 22
    ADC_CHANNEL_23 = 23,                                                                                ///< ADC channel 23
    ADC_CHANNEL_24 = 24,                                                                                ///< ADC channel 24
    ADC_CHANNEL_25 = 25,                                                                                ///< ADC channel 25
    ADC_CHANNEL_26 = 26,                                                                                ///< ADC channel 26
    ADC_CHANNEL_27 = 27,                                                                                ///< ADC channel 27
    ADC_CHANNEL_28 = 28,                                                                                ///< ADC channel 28
    ADC_CHANNEL_29 = 29,                                                                                ///< ADC channel 29
    ADC_CHANNEL_30 = 30,                                                                                ///< ADC channel 30
    ADC_CHANNEL_31 = 31,                                                                                ///< ADC channel 31
    ADC_CHANNEL_32 = 32,                                                                                ///< ADC channel 32
    ADC_CHANNEL_33 = 33,                                                                                ///< ADC channel 33
    ADC_CHANNEL_34 = 34,                                                                                ///< ADC channel 34
    ADC_CHANNEL_35 = 35,                                                                                ///< ADC channel 35

    /* Extended Channels, See implimentation for details */
    /* Implimentation specific extended channels */
    ADC_CHANNEL_SELF_DIAGNOSIS_ADC0 = 0x60,                                                             ///< Self-Diagnosis channel for ADC Unit 0
    ADC_CHANNEL_SELF_DIAGNOSIS_ADC1 = 0x61,                                                             ///< Self-Diagnosis channel for ADC Unit 1
    ADC_CHANNEL_SELF_DIAGNOSIS_ADC2 = 0x62,                                                             ///< Self-Diagnosis channel for ADC Unit 1
    ADC_CHANNEL_TEMPERATURE         = 0x64,                                                             ///< Temperature sensor output
    ADC_CHANNEL_VOLT                = 0x65,                                                             ///< Internal reference voltage
    ADC_CHANNEL_VBATT               = 0x66,                                                             ///< VBATT 1/3 voltage monitor
    ADC_CHANNEL_DA0                 = 0x68,                                                             ///< D/A converter channel 0
    ADC_CHANNEL_DA1                 = 0x69,                                                             ///< D/A converter channel 1

    ADC_CHANNEL_SELF_DIAGNOSIS_SH0 = 0x70,                                                              ///< Self-Diagnosis Sample-and-hold Circuit Unit 0
    ADC_CHANNEL_SELF_DIAGNOSIS_SH1 = 0x71,                                                              ///< Self-Diagnosis Sample-and-hold Circuit Unit 1
    ADC_CHANNEL_SELF_DIAGNOSIS_SH2 = 0x72,                                                              ///< Self-Diagnosis Sample-and-hold Circuit Unit 2

    ADC_CHANNEL_LAST_EXTERNAL  = ADC_CHANNEL_35,                                                        /// Highest physical channel
    ADC_CHANNEL_FIRST_INTERNAL = ADC_CHANNEL_SELF_DIAGNOSIS_ADC0,                                       /// First internal channel
    ADC_CHANNEL_LAST_INTERNAL  = ADC_CHANNEL_SELF_DIAGNOSIS_SH2,                                        /// Last internal channel

    ADC_CHANNEL_CAPTURE_A_MASK               = 0x10,                                                    ///< Capture A channel mask
    ADC_CHANNEL_CAPTURE_B_MASK               = 0x20,                                                    ///< Capture B channel mask
    ADC_CHANNEL_OVERCURRENT_MASK             = 0x30,                                                    ///< Overcurrent channel mask
    ADC_CHANNEL_OVERCURRENT0_CAPTURE_MASK    = 0x40,                                                    ///< Overcurrent0 capture channel mask
    ADC_CHANNEL_OVERCURRENT1_CAPTURE_MASK    = 0x50,                                                    ///< Overcurrent1 capture channel mask
    ADC_CHANNEL_OVERCURRENT2_CAPTURE_MASK    = 0x60,                                                    ///< Overcurrent2 capture channel mask
    ADC_CHANNEL_OVERCURRENT_SUM_CAPTURE_MASK = 0x70,                                                    ///< Overcurrent sum capture channel mask

    ADC_CHANNEL_0_CAPTURE_A               = (ADC_CHANNEL_0 | ADC_CHANNEL_CAPTURE_A_MASK),               ///< Channel 0 - Capture A channel
    ADC_CHANNEL_0_CAPTURE_B               = (ADC_CHANNEL_0 | ADC_CHANNEL_CAPTURE_B_MASK),               ///< Channel 0 - Capture B channel
    ADC_CHANNEL_0_OVERCURRENT             = (ADC_CHANNEL_0 | ADC_CHANNEL_OVERCURRENT_MASK),             ///< Channel 0 - Overcurrent channel
    ADC_CHANNEL_0_OVERCURRENT0_CAPTURE    = (ADC_CHANNEL_0 | ADC_CHANNEL_OVERCURRENT0_CAPTURE_MASK),    ///< Channel 0 - Overcurrent0 capture channel
    ADC_CHANNEL_0_OVERCURRENT1_CAPTURE    = (ADC_CHANNEL_0 | ADC_CHANNEL_OVERCURRENT1_CAPTURE_MASK),    ///< Channel 0 - Overcurrent1 capture channel
    ADC_CHANNEL_0_OVERCURRENT2_CAPTURE    = (ADC_CHANNEL_0 | ADC_CHANNEL_OVERCURRENT2_CAPTURE_MASK),    ///< Channel 0 - Overcurrent2 capture channel
    ADC_CHANNEL_0_OVERCURRENT_SUM_CAPTURE = (ADC_CHANNEL_0 | ADC_CHANNEL_OVERCURRENT_SUM_CAPTURE_MASK), ///< Channel 0 - Overcurrent sum capture channel
    ADC_CHANNEL_1_CAPTURE_A               = (ADC_CHANNEL_1 | ADC_CHANNEL_CAPTURE_A_MASK),               ///< Channel 1 - Capture A channel
    ADC_CHANNEL_1_CAPTURE_B               = (ADC_CHANNEL_1 | ADC_CHANNEL_CAPTURE_B_MASK),               ///< Channel 1 - Capture B channel
    ADC_CHANNEL_1_OVERCURRENT             = (ADC_CHANNEL_1 | ADC_CHANNEL_OVERCURRENT_MASK),             ///< Channel 1 - Overcurrent channel
    ADC_CHANNEL_1_OVERCURRENT0_CAPTURE    = (ADC_CHANNEL_1 | ADC_CHANNEL_OVERCURRENT0_CAPTURE_MASK),    ///< Channel 1 - Overcurrent0 capture channel
    ADC_CHANNEL_1_OVERCURRENT1_CAPTURE    = (ADC_CHANNEL_1 | ADC_CHANNEL_OVERCURRENT1_CAPTURE_MASK),    ///< Channel 1 - Overcurrent1 capture channel
    ADC_CHANNEL_1_OVERCURRENT2_CAPTURE    = (ADC_CHANNEL_1 | ADC_CHANNEL_OVERCURRENT2_CAPTURE_MASK),    ///< Channel 1 - Overcurrent2 capture channel
    ADC_CHANNEL_1_OVERCURRENT_SUM_CAPTURE = (ADC_CHANNEL_1 | ADC_CHANNEL_OVERCURRENT_SUM_CAPTURE_MASK), ///< Channel 1 - Overcurrent sum capture channel
    ADC_CHANNEL_2_CAPTURE_A               = (ADC_CHANNEL_2 | ADC_CHANNEL_CAPTURE_A_MASK),               ///< Channel 2 - Capture A channel
    ADC_CHANNEL_2_CAPTURE_B               = (ADC_CHANNEL_2 | ADC_CHANNEL_CAPTURE_B_MASK),               ///< Channel 2 - Capture B channel
    ADC_CHANNEL_2_OVERCURRENT             = (ADC_CHANNEL_2 | ADC_CHANNEL_OVERCURRENT_MASK),             ///< Channel 2 - Overcurrent channel
    ADC_CHANNEL_2_OVERCURRENT0_CAPTURE    = (ADC_CHANNEL_2 | ADC_CHANNEL_OVERCURRENT0_CAPTURE_MASK),    ///< Channel 2 - Overcurrent0 capture channel
    ADC_CHANNEL_2_OVERCURRENT1_CAPTURE    = (ADC_CHANNEL_2 | ADC_CHANNEL_OVERCURRENT1_CAPTURE_MASK),    ///< Channel 2 - Overcurrent1 capture channel
    ADC_CHANNEL_2_OVERCURRENT2_CAPTURE    = (ADC_CHANNEL_2 | ADC_CHANNEL_OVERCURRENT2_CAPTURE_MASK),    ///< Channel 2 - Overcurrent2 capture channel
    ADC_CHANNEL_2_OVERCURRENT_SUM_CAPTURE = (ADC_CHANNEL_2 | ADC_CHANNEL_OVERCURRENT_SUM_CAPTURE_MASK), ///< Channel 2 - Overcurrent sum capture channel
} adc_channel_t;

/** ADC channel mask */
typedef uint64_t adc_b_channel_mask_t;

#define ADC_B_CHANNEL_MASK_NONE              0
#define ADC_B_CHANNEL_MASK_0                 (1ULL << 0)                                    ///< Channel 0
#define ADC_B_CHANNEL_MASK_1                 (1ULL << 1)                                    ///< Channel 1
#define ADC_B_CHANNEL_MASK_2                 (1ULL << 2)                                    ///< Channel 2
#define ADC_B_CHANNEL_MASK_3                 (1ULL << 3)                                    ///< Channel 3
#define ADC_B_CHANNEL_MASK_4                 (1ULL << 4)                                    ///< Channel 4
#define ADC_B_CHANNEL_MASK_5                 (1ULL << 5)                                    ///< Channel 5
#define ADC_B_CHANNEL_MASK_6                 (1ULL << 6)                                    ///< Channel 6
#define ADC_B_CHANNEL_MASK_7                 (1ULL << 7)                                    ///< Channel 7
#define ADC_B_CHANNEL_MASK_8                 (1ULL << 8)                                    ///< Channel 8
#define ADC_B_CHANNEL_MASK_9                 (1ULL << 9)                                    ///< Channel 9
#define ADC_B_CHANNEL_MASK_10                (1ULL << 10)                                   ///< Channel 10
#define ADC_B_CHANNEL_MASK_11                (1ULL << 11)                                   ///< Channel 11
#define ADC_B_CHANNEL_MASK_12                (1ULL << 12)                                   ///< Channel 12
#define ADC_B_CHANNEL_MASK_13                (1ULL << 13)                                   ///< Channel 13
#define ADC_B_CHANNEL_MASK_14                (1ULL << 14)                                   ///< Channel 14
#define ADC_B_CHANNEL_MASK_15                (1ULL << 15)                                   ///< Channel 15
#define ADC_B_CHANNEL_MASK_16                (1ULL << 16)                                   ///< Channel 16
#define ADC_B_CHANNEL_MASK_17                (1ULL << 17)                                   ///< Channel 17
#define ADC_B_CHANNEL_MASK_18                (1ULL << 18)                                   ///< Channel 18
#define ADC_B_CHANNEL_MASK_19                (1ULL << 19)                                   ///< Channel 19
#define ADC_B_CHANNEL_MASK_20                (1ULL << 20)                                   ///< Channel 20
#define ADC_B_CHANNEL_MASK_21                (1ULL << 21)                                   ///< Channel 21
#define ADC_B_CHANNEL_MASK_22                (1ULL << 22)                                   ///< Channel 22
#define ADC_B_CHANNEL_MASK_23                (1ULL << 23)                                   ///< Channel 23
#define ADC_B_CHANNEL_MASK_24                (1ULL << 24)                                   ///< Channel 24
#define ADC_B_CHANNEL_MASK_25                (1ULL << 25)                                   ///< Channel 25
#define ADC_B_CHANNEL_MASK_26                (1ULL << 26)                                   ///< Channel 26
#define ADC_B_CHANNEL_MASK_27                (1ULL << 27)                                   ///< Channel 27
#define ADC_B_CHANNEL_MASK_28                (1ULL << 28)                                   ///< Channel 28

#define ADC_B_CHANNEL_MASK_29                (1ULL << 29)                                   ///< Channel 29
#define ADC_B_CHANNEL_MASK_30                (1ULL << 30)                                   ///< Channel 30
#define ADC_B_CHANNEL_MASK_31                (1ULL << 31)                                   ///< Channel 31
#define ADC_B_CHANNEL_MASK_32                (1ULL << 32)                                   ///< Channel 32
#define ADC_B_CHANNEL_MASK_33                (1ULL << 33)                                   ///< Channel 33
#define ADC_B_CHANNEL_MASK_34                (1ULL << 34)                                   ///< Channel 34
#define ADC_B_CHANNEL_MASK_35                (1ULL << 35)                                   ///< Channel 35

#define ADC_B_CHANNEL_MASK_DIAGNOSIS_ADC0    (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 0))  ///< Converter 0 Self-Diagnosis Channel
#define ADC_B_CHANNEL_MASK_DIAGNOSIS_ADC1    (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 1))  ///< Converter 1 Self-Diagnosis Channel]
#define ADC_B_CHANNEL_MASK_DIAGNOSIS_ADC2    (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 2))  ///< Converter 1 Self-Diagnosis Channel
#define ADC_B_CHANNEL_MASK_TEMPERATURE       (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 4))  ///< Temperature sensor channel
#define ADC_B_CHANNEL_MASK_VOLT              (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 5))  ///< Voltage Reference channel
#define ADC_B_CHANNEL_MASK_VBATT             (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 6))  ///< VBATT 1/3 voltage monitor
#define ADC_B_CHANNEL_MASK_DAC0              (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 8))  ///< DAC 1 Channel
#define ADC_B_CHANNEL_MASK_DAC1              (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 9))  ///< DAC 2 Channel
#define ADC_B_CHANNEL_MASK_DIAGNOSIS_SH0     (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 16)) ///< Sample-and-hold 0 Self-Diagnosis
#define ADC_B_CHANNEL_MASK_DIAGNOSIS_SH1     (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 17)) ///< Sample-and-hold 1 Self-Diagnosis
#define ADC_B_CHANNEL_MASK_DIAGNOSIS_SH2     (1ULL << (ADC_B_CHANNEL_MASK_EXT_OFFSET + 18)) ///< Sample-and-hold 2 Self-Diagnosis

/** ADC Scan Group */
typedef enum e_adc_group_id
{
    ADC_GROUP_ID_0  = 0,               ///< Group ID 0
    ADC_GROUP_ID_1  = 1,               ///< Group ID 1
    ADC_GROUP_ID_2  = 2,               ///< Group ID 2
    ADC_GROUP_ID_3  = 3,               ///< Group ID 3
    ADC_GROUP_ID_4  = 4,               ///< Group ID 4
    ADC_GROUP_ID_5  = 5,               ///< Group ID 5
    ADC_GROUP_ID_6  = 6,               ///< Group ID 6
    ADC_GROUP_ID_7  = 7,               ///< Group ID 7
    ADC_GROUP_ID_8  = 8,               ///< Group ID 8
    ADC_GROUP_ID_9  = 9,               ///< Group ID 9
    ADC_GROUP_ID_10 = 10,              ///< Group ID 10
    ADC_GROUP_ID_11 = 11,              ///< Group ID 11
} adc_group_id_t;

/** ADC Scan Group Mask*/
typedef enum e_adc_group_mask
{
    ADC_GROUP_MASK_NONE = 0x000,       ///< Group Mask Unknown or None
    ADC_GROUP_MASK_0    = 0x001,       ///< Group Mask 0
    ADC_GROUP_MASK_1    = 0x002,       ///< Group Mask 1
    ADC_GROUP_MASK_2    = 0x004,       ///< Group Mask 2
    ADC_GROUP_MASK_3    = 0x008,       ///< Group Mask 3
    ADC_GROUP_MASK_4    = 0x010,       ///< Group Mask 4
    ADC_GROUP_MASK_5    = 0x020,       ///< Group Mask 5
    ADC_GROUP_MASK_6    = 0x040,       ///< Group Mask 6
    ADC_GROUP_MASK_7    = 0x080,       ///< Group Mask 7
    ADC_GROUP_MASK_8    = 0x100,       ///< Group Mask 8
    ADC_GROUP_MASK_9    = 0x200,       ///< Group Mask 9
    ADC_GROUP_MASK_10   = 0x400,       ///< Group Mask 10
    ADC_GROUP_MASK_11   = 0x800,       ///< Group Mask 11
    ADC_GROUP_MASK_ALL  = 0xFFF,       ///< All Groups
} adc_group_mask_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
