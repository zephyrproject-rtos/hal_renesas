/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_FEATURE_H
#define BSP_FEATURE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_feature_gen.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** The main oscillator drive value is based upon the oscillator frequency selected in the configuration */
#if (BSP_CFG_XTAL_HZ > (9999999))
 #define CGC_MAINCLOCK_DRIVE    (0x00U)
#else
 #define CGC_MAINCLOCK_DRIVE    (0x01U)
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

#define BSP_FEATURE_ACMPHS_MIN_WAIT_TIME_US                  (0) // Feature not available on this MCU
#define BSP_FEATURE_ACMPHS_VREF                              (0) // Feature not available on this MCU

#define BSP_FEATURE_ACMPLP_HAS_COMPSEL_REGISTERS             (1)
#define BSP_FEATURE_ACMPLP_MIN_WAIT_TIME_US                  (100U)

#define BSP_FEATURE_ADC_ADDITION_SUPPORTED                   (1U)
#define BSP_FEATURE_ADC_B_TSN_CALIBRATION32_MASK             (0U)
#define BSP_FEATURE_ADC_B_TSN_SLOPE                          (0U)
#define BSP_FEATURE_ADC_B_UNIT_0_CHANNELS                    (0U)
#define BSP_FEATURE_ADC_B_UNIT_1_CHANNELS                    (0U)
#define BSP_FEATURE_ADC_CALIBRATION_REG_AVAILABLE            (0U)
#define BSP_FEATURE_ADC_CLOCK_SOURCE                         (FSP_PRIV_CLOCK_PCLKC)
#define BSP_FEATURE_ADC_D_CHANNELS                           (0) // Feature not available on this MCU
#define BSP_FEATURE_ADC_D_SCAN_MODE_CHANNELS                 (0) // Feature not available on this MCU
#define BSP_FEATURE_ADC_GROUP_B_SENSORS_ALLOWED              (0U)
#define BSP_FEATURE_ADC_HAS_ADBUF                            (0U)
#define BSP_FEATURE_ADC_HAS_ADCER_ADPRC                      (1U)
#define BSP_FEATURE_ADC_HAS_ADCER_ADRFMT                     (1U)
#define BSP_FEATURE_ADC_HAS_ADHVREFCNT                       (1U)
#define BSP_FEATURE_ADC_HAS_PGA                              (0) // Feature not available on this MCU
#define BSP_FEATURE_ADC_HAS_SAMPLE_HOLD_REG                  (0U)
#define BSP_FEATURE_ADC_HAS_VREFAMPCNT                       (0U)
#define BSP_FEATURE_ADC_MAX_RESOLUTION_BITS                  (14U)
#define BSP_FEATURE_ADC_SENSORS_EXCLUSIVE                    (1U)
#define BSP_FEATURE_ADC_SENSOR_MIN_SAMPLING_TIME             (5000U)
#define BSP_FEATURE_ADC_TSN_CALIBRATION32_AVAILABLE          (0U)
#define BSP_FEATURE_ADC_TSN_CALIBRATION32_MASK               (0U)
#define BSP_FEATURE_ADC_TSN_CALIBRATION_AVAILABLE            (1U)
#define BSP_FEATURE_ADC_TSN_CONTROL_AVAILABLE                (0U)
#define BSP_FEATURE_ADC_TSN_SLOPE                            (-3650)
#define BSP_FEATURE_ADC_UNIT_0_CHANNELS                      (0x1A0670) // 4 to 6, 9, 10, 17, 19, 20 in unit 0
#define BSP_FEATURE_ADC_UNIT_1_CHANNELS                      (0)
#define BSP_FEATURE_ADC_VALID_UNIT_MASK                      (1U)

#define BSP_FEATURE_AGT_AGTW_CHANNEL_COUNT                   (0)
#define BSP_FEATURE_AGT_AGT_CHANNEL_COUNT                    (2)
#define BSP_FEATURE_AGT_USE_AGTIOSEL_ALT                     (0) // Indicates use of AGTIOSEL_ALT instead of AGTIOSEL
#define BSP_FEATURE_AGT_VALID_CHANNEL_MASK                   (0x03)

#define BSP_FEATURE_BSP_FLASH_CACHE                          (1U)
#define BSP_FEATURE_BSP_FLASH_CACHE_DISABLE_OPM              (1U)
#define BSP_FEATURE_BSP_FLASH_PREFETCH_BUFFER                (0)
#define BSP_FEATURE_BSP_HAS_CANFD_CLOCK                      (0) // Feature not available on this MCU
#define BSP_FEATURE_BSP_HAS_CEC_CLOCK                        (0) // Feature not available on this MCU
#define BSP_FEATURE_BSP_HAS_CLOCK_SUPPLY_TYPEB               (0U)
#define BSP_FEATURE_BSP_HAS_CODE_SYSTEM_CACHE                (0)
#define BSP_FEATURE_BSP_HAS_DCDC_REGULATOR                   (0U)
#define BSP_FEATURE_BSP_HAS_DTCM                             (0) // Feature not available on this MCU
#define BSP_FEATURE_BSP_HAS_GPT_CLOCK                        (0) // Mutually exclusive with USB60 Clock
#define BSP_FEATURE_BSP_HAS_GRAPHICS_DOMAIN                  (0)
#define BSP_FEATURE_BSP_HAS_I3C_CLOCK                        (0)
#define BSP_FEATURE_BSP_HAS_IIC_CLOCK                        (0U)
#define BSP_FEATURE_BSP_HAS_ITCM                             (0) // Feature not available on this MCU
#define BSP_FEATURE_BSP_HAS_LCD_CLOCK                        (0)
#define BSP_FEATURE_BSP_HAS_OCTASPI_CLOCK                    (0U)
#define BSP_FEATURE_BSP_HAS_OFS2                             (0)
#define BSP_FEATURE_BSP_HAS_OFS3                             (0)
#define BSP_FEATURE_BSP_HAS_SCE5                             (1)
#define BSP_FEATURE_BSP_HAS_SCE_ON_RA2                       (0) // Feature not available on this MCU
#define BSP_FEATURE_BSP_HAS_SCISPI_CLOCK                     (0) // Feature not available on this MCU
#define BSP_FEATURE_BSP_HAS_SCI_CLOCK                        (0)
#define BSP_FEATURE_BSP_HAS_SDADC_CLOCK                      (0)
#define BSP_FEATURE_BSP_HAS_SECURITY_MPU                     (1U)
#define BSP_FEATURE_BSP_HAS_SPI_CLOCK                        (0)
#define BSP_FEATURE_BSP_HAS_SP_MON                           (1U)
#define BSP_FEATURE_BSP_HAS_SYRACCR                          (0U)
#define BSP_FEATURE_BSP_HAS_TZFSAR                           (0)
#define BSP_FEATURE_BSP_HAS_USB60_CLOCK_REQ                  (0U) // Feature not available on this MCU
#define BSP_FEATURE_BSP_HAS_USBCKDIVCR                       (0U)
#define BSP_FEATURE_BSP_HAS_USB_CLOCK_DIV                    (0U)
#define BSP_FEATURE_BSP_HAS_USB_CLOCK_REQ                    (0U) // On the RA6M4 there is a request bit that must be set before changing USB clock settings.
#define BSP_FEATURE_BSP_HAS_USB_CLOCK_SEL                    (1U)
#define BSP_FEATURE_BSP_HAS_USB_CLOCK_SEL_ALT                (1U)
#define BSP_FEATURE_BSP_MCU_INFO_POINTER_LOCATION            (0x407FB19C)
#define BSP_FEATURE_BSP_MPU_REGION0_MASK                     (0x00FFFFFFU)
#define BSP_FEATURE_BSP_MSTP_GPT_MSTPD5_MAX_CH               (3U) // Largest channel number associated with lower MSTP bit for GPT on this MCU.
#define BSP_FEATURE_BSP_MSTP_HAS_MSTPCRE                     (0U)
#define BSP_FEATURE_BSP_NUM_PMSAR                            (0U)
#define BSP_FEATURE_BSP_OFS1_HOCOFRQ_MASK                    (0xFFFF8FFFU)
#define BSP_FEATURE_BSP_OFS1_HOCOFRQ_OFFSET                  (12U)
#define BSP_FEATURE_BSP_OFS_HAS_SECURITY_ATTRIBUTION         (0U)
#define BSP_FEATURE_BSP_OSIS_PADDING                         (1)
#define BSP_FEATURE_BSP_POWER_CHANGE_MSTP_REQUIRED           (0U)
#define BSP_FEATURE_BSP_RESET_TRNG                           (1U)
#define BSP_FEATURE_BSP_SYS_CLOCK_FREQ_FIVE_ROM_WAITS        (0U) // The maximum frequency allowed without having five ROM wait cycles (Set to zero if this is not an option).
#define BSP_FEATURE_BSP_SYS_CLOCK_FREQ_FOUR_ROM_WAITS        (0U) // The maximum frequency allowed without having four ROM wait cycles (Set to zero if this is not an option).
#define BSP_FEATURE_BSP_SYS_CLOCK_FREQ_NO_RAM_WAITS          (0U) // The maximum frequency allowed without having RAM wait state enabled in SRAMWTSC.
#define BSP_FEATURE_BSP_SYS_CLOCK_FREQ_ONE_ROM_WAITS         (0U) // The maximum frequency allowed without having one ROM wait cycle.
#define BSP_FEATURE_BSP_SYS_CLOCK_FREQ_THREE_ROM_WAITS       (0U) // The maximum frequency allowed without having three ROM wait cycles (Set to zero if this is not an option).
#define BSP_FEATURE_BSP_SYS_CLOCK_FREQ_TWO_ROM_WAITS         (0U) // The maximum frequency allowed without having two ROM wait cycles.
#define BSP_FEATURE_BSP_UNIQUE_ID_OFFSET                     (0x14)
#define BSP_FEATURE_BSP_UNIQUE_ID_POINTER                    ((*(uint32_t *) BSP_FEATURE_BSP_MCU_INFO_POINTER_LOCATION) \
                                                              +                                                         \
                                                              BSP_FEATURE_BSP_UNIQUE_ID_OFFSET)
#define BSP_FEATURE_BSP_VBATT_HAS_VBTCR1_BPWSWSTP            (1U)

#define BSP_FEATURE_CANFD_FD_SUPPORT                         (0U)
#define BSP_FEATURE_CANFD_LITE                               (0U)
#define BSP_FEATURE_CANFD_NUM_CHANNELS                       (0U) // Feature not available on this MCU
#define BSP_FEATURE_CANFD_NUM_INSTANCES                      (0U)

#define BSP_FEATURE_CAN_CHECK_PCLKB_RATIO                    (1U)
#define BSP_FEATURE_CAN_CLOCK                                (FSP_PRIV_CLOCK_PCLKA)
#define BSP_FEATURE_CAN_MCLOCK_ONLY                          (0U)
#define BSP_FEATURE_CAN_NUM_CHANNELS                         (1U)

#define BSP_FEATURE_CGC_EXECUTE_FROM_LOCO                    (1)
#define BSP_FEATURE_CGC_HAS_BCLK                             (0U) // This MCU does not have a BCLK
#define BSP_FEATURE_CGC_HAS_CPUCLK                           (0U)
#define BSP_FEATURE_CGC_HAS_FCLK                             (1U)
#define BSP_FEATURE_CGC_HAS_FLDWAITR                         (0U)
#define BSP_FEATURE_CGC_HAS_FLL                              (0U)
#define BSP_FEATURE_CGC_HAS_FLWT                             (0U)
#define BSP_FEATURE_CGC_HAS_HOCOWTCR                         (1U)
#define BSP_FEATURE_CGC_HAS_MEMWAIT                          (1U)
#define BSP_FEATURE_CGC_HAS_PCLKA                            (1U)
#define BSP_FEATURE_CGC_HAS_PCLKB                            (1U)
#define BSP_FEATURE_CGC_HAS_PCLKC                            (1U)
#define BSP_FEATURE_CGC_HAS_PCLKD                            (1U)
#define BSP_FEATURE_CGC_HAS_PCLKE                            (0U)
#define BSP_FEATURE_CGC_HAS_PLL                              (1U)
#define BSP_FEATURE_CGC_HAS_PLL2                             (0U) // On the RA6M4 there is another PLL that can be used as a clock source for USB and OCTASPI.
#define BSP_FEATURE_CGC_HAS_SOPCCR                           (1U)
#define BSP_FEATURE_CGC_HAS_SOSC                             (1U)
#define BSP_FEATURE_CGC_HAS_SRAMPRCR2                        (0U) // On the RA6M4 there is another register to enable write access for SRAMWTSC.
#define BSP_FEATURE_CGC_HAS_SRAMWTSC                         (0U)
#define BSP_FEATURE_CGC_HOCOSF_BEFORE_OPCCR                  (1U)
#define BSP_FEATURE_CGC_HOCOWTCR_64MHZ_ONLY                  (1U)
#define BSP_FEATURE_CGC_HOCOWTCR_SCI_SNOOZE_VALUE            (0)
#define BSP_FEATURE_CGC_HOCOWTCR_VALUE                       (6U)
#define BSP_FEATURE_CGC_ICLK_DIV_RESET                       (BSP_CLOCKS_SYS_CLOCK_DIV_16)
#define BSP_FEATURE_CGC_LOCO_STABILIZATION_MAX_US            (100U)
#define BSP_FEATURE_CGC_LOW_SPEED_MAX_FREQ_HZ                (1000000U) // This MCU does have Low Speed Mode, up to 1MHz
#define BSP_FEATURE_CGC_LOW_VOLTAGE_MAX_FREQ_HZ              (4000000U) // This MCU does have Low Voltage Mode, up to 4MHz
#define BSP_FEATURE_CGC_MIDDLE_SPEED_MAX_FREQ_HZ             (8000000U) // This MCU does have Middle Speed Mode, up to 8MHz
#define BSP_FEATURE_CGC_MOCO_STABILIZATION_MAX_US            (1U)
#define BSP_FEATURE_CGC_MODRV_MASK                           (R_SYSTEM_MOMCR_MODRV1_Msk)
#define BSP_FEATURE_CGC_MODRV_SHIFT                          (R_SYSTEM_MOMCR_MODRV1_Pos)
#define BSP_FEATURE_CGC_PLL_HOCO_MAX_CPUCLK_HZ               (0U)
#define BSP_FEATURE_CGC_PLL1_NUM_OUTPUT_CLOCKS               (1U)
#define BSP_FEATURE_CGC_PLL2_NUM_OUTPUT_CLOCKS               (0U)
#define BSP_FEATURE_CGC_PLL_OUT_MAX_HZ                       (64000000U)
#define BSP_FEATURE_CGC_PLL_OUT_MIN_HZ                       (24000000U)
#define BSP_FEATURE_CGC_PLL_SRC_MAX_HZ                       (12500000U)
#define BSP_FEATURE_CGC_PLL_SRC_MIN_HZ                       (4000000U)
#define BSP_FEATURE_CGC_PLL2_OUT_MAX_HZ                      (0U) // Feature not available on this MCU
#define BSP_FEATURE_CGC_PLL2_OUT_MIN_HZ                      (0U) // Feature not available on this MCU
#define BSP_FEATURE_CGC_PLL2_SRC_MAX_HZ                      (0U) // Feature not available on this MCU
#define BSP_FEATURE_CGC_PLL2_SRC_MIN_HZ                      (0U) // Feature not available on this MCU
#define BSP_FEATURE_CGC_PLLCCR_TYPE                          (2U)
#define BSP_FEATURE_CGC_PLLCCR_VCO_MAX_HZ                    (0U) // This MCU does not use PLLCCR to set PLL frequency
#define BSP_FEATURE_CGC_PLLCCR_WAIT_US                       (1U) // 1 us wait between setting PLLCCR and clearing PLLSTP
#define BSP_FEATURE_CGC_REGISTER_SET_B                       (0)
#define BSP_FEATURE_CGC_SCKDIVCR_BCLK_MATCHES_PCLKB          (1U) // RA4W1 requires that bits 16-18 of SCKDIVCR be the same as the bits for PCKB
#define BSP_FEATURE_CGC_SODRV_MASK                           (0x03U)
#define BSP_FEATURE_CGC_SODRV_SHIFT                          (0x0U)
#define BSP_FEATURE_CGC_SRAMPRCR_KW_OFFSET                   (1)
#define BSP_FEATURE_CGC_SRAMPRCR_KW_VALUE                    (0x78)
#define BSP_FEATURE_CGC_STARTUP_OPCCR_MODE                   (2)
#define BSP_FEATURE_CGC_HAS_OSTDCSE                          (0) // Feature not available on this MCU
#define BSP_FEATURE_CGC_OSCILLATON_STOP_DETECT               (1)
#define BSP_FEATURE_CGC_STARTUP_SCKDIVCR                     (0x44044444)
#define BSP_FEATURE_CGC_STARTUP_SCKDIVCR2                    (0x00)
#define BSP_FEATURE_CGC_STARTUP_SCKSCR                       (0x01)

#define BSP_FEATURE_CRC_HAS_SNOOP                            (1U)
#define BSP_FEATURE_CRC_SNOOP_ADDRESS_TYPE_TDR               (0x3U)
#define BSP_FEATURE_CRC_HAS_CRCCR0_LMS                       (1)
#define BSP_FEATURE_CRC_POLYNOMIAL_MASK                      (0x3EU)

#define BSP_FEATURE_CRYPTO_HAS_AES                           (1)
#define BSP_FEATURE_CRYPTO_HAS_AES_WRAPPED                   (1)
#define BSP_FEATURE_CRYPTO_HAS_CTR_DRBG                      (1)
#define BSP_FEATURE_CRYPTO_HAS_ECC                           (0)
#define BSP_FEATURE_CRYPTO_HAS_ECC_WRAPPED                   (0)
#define BSP_FEATURE_CRYPTO_HAS_HASH                          (0)
#define BSP_FEATURE_CRYPTO_HAS_NEW_PROCS                     (0) // Feature not available on this MCU
#define BSP_FEATURE_CRYPTO_HAS_RSA                           (0)
#define BSP_FEATURE_CRYPTO_HAS_RSA_WRAPPED                   (0)
#define BSP_FEATURE_CRYPTO_AES_IP_VERSION                    (0)
#define BSP_FEATURE_CRYPTO_HAS_SCE5                          (1)
#define BSP_FEATURE_CRYPTO_HAS_SCE5B                         (0)
#define BSP_FEATURE_CRYPTO_HAS_SCE7                          (0)
#define BSP_FEATURE_CRYPTO_HAS_SCE9                          (0) // Feature not available on this MCU

#define BSP_FEATURE_CTSU_CTSUCHAC_REGISTER_COUNT             (5U)
#define BSP_FEATURE_CTSU_CTSUCHTRC_REGISTER_COUNT            (5U)
#define BSP_FEATURE_CTSU_HAS_TXVSEL                          (0)
#define BSP_FEATURE_CTSU_VERSION                             (1)

#define BSP_FEATURE_DAC8_HAS_CHARGEPUMP                      (0U)
#define BSP_FEATURE_DAC8_HAS_DA_AD_SYNCHRONIZE               (0U)
#define BSP_FEATURE_DAC8_HAS_REALTIME_MODE                   (0U)
#define BSP_FEATURE_DAC8_MAX_CHANNELS                        (2U)

#define BSP_FEATURE_DAC_AD_SYNC_UNIT_MASK                    (0U)
#define BSP_FEATURE_DAC_HAS_CHARGEPUMP                       (0U)
#define BSP_FEATURE_DAC_HAS_DAVREFCR                         (1U)
#define BSP_FEATURE_DAC_HAS_DA_AD_SYNCHRONIZE                (1U)
#define BSP_FEATURE_DAC_HAS_INTERNAL_OUTPUT                  (0U)
#define BSP_FEATURE_DAC_HAS_OUTPUT_AMPLIFIER                 (0U)
#define BSP_FEATURE_DAC_MAX_CHANNELS                         (1U)

#define BSP_FEATURE_DMAC_HAS_DELSR                           (0U)
#define BSP_FEATURE_DMAC_HAS_REPEAT_BLOCK_MODE               (0U)
#define BSP_FEATURE_DMAC_MAX_CHANNEL                         (4U)

#define BSP_FEATURE_DOC_VERSION                              (1U)

#define BSP_FEATURE_DWT_CYCCNT                               (1U)          // RA4W1 has Data Watchpoint Cycle Count Register

#define BSP_FEATURE_ELC_PERIPHERAL_MASK                      (0x0007D3FFU) // Deprecated (Removing in FSP v6.0)
#define BSP_FEATURE_ELC_VERSION                              (1U)

#define BSP_FEATURE_ETHER_FIFO_DEPTH                         (0)           // Feature not available on this MCU
#define BSP_FEATURE_ETHER_MAX_CHANNELS                       (0)           // Feature not available on this MCU
#define BSP_FEATURE_ETHER_SUPPORTS_TZ_SECURE                 (0)           // Feature not available on this MCU

#define BSP_FEATURE_FLASH_CODE_FLASH_START                   (0x0U)
#define BSP_FEATURE_FLASH_DATA_FLASH_START                   (0x40100000U)
#define BSP_FEATURE_FLASH_HP_CF_DUAL_BANK_START              (0)           // Feature not available on this MCU
#define BSP_FEATURE_FLASH_HP_CF_REGION0_BLOCK_SIZE           (0)           // Feature not available on this MCU
#define BSP_FEATURE_FLASH_HP_CF_REGION0_SIZE                 (0)           // Feature not available on this MCU
#define BSP_FEATURE_FLASH_HP_CF_REGION1_BLOCK_SIZE           (0)           // Feature not available on this MCU
#define BSP_FEATURE_FLASH_HP_CF_WRITE_SIZE                   (0)           // Feature not available on this MCU
#define BSP_FEATURE_FLASH_HP_DF_BLOCK_SIZE                   (0)           // Feature not available on this MCU
#define BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE                   (0)           // Feature not available on this MCU
#define BSP_FEATURE_FLASH_HP_HAS_FMEPROT                     (0)           // Feature not available on this MCU
#define BSP_FEATURE_FLASH_HP_SUPPORTS_DUAL_BANK              (0)
#define BSP_FEATURE_FLASH_HP_VERSION                         (0)           // Feature not available on this MCU
#define BSP_FEATURE_FLASH_LP_AWS_FAW_MASK                    (0xFFFU)
#define BSP_FEATURE_FLASH_LP_AWS_FAW_SHIFT                   (10)
#define BSP_FEATURE_FLASH_LP_CF_BLOCK_SIZE                   (0x800U)
#define BSP_FEATURE_FLASH_LP_CF_WRITE_SIZE                   (8)
#define BSP_FEATURE_FLASH_LP_DF_BLOCK_SIZE                   (0x400U)
#define BSP_FEATURE_FLASH_LP_DF_WRITE_SIZE                   (1)
#define BSP_FEATURE_FLASH_LP_FLASH_CLOCK_SRC                 ((fsp_priv_clock_t) FSP_PRIV_CLOCK_FCLK) // RA4W1 FlashIF uses FCLK
#define BSP_FEATURE_FLASH_LP_SUPPORTS_DUAL_BANK              (0)                                      // Feature not available on this MCU
#define BSP_FEATURE_FLASH_LP_VERSION                         (3)
#define BSP_FEATURE_FLASH_SUPPORTS_ACCESS_WINDOW             (1)
#define BSP_FEATURE_FLASH_SUPPORTS_ID_CODE                   (1)

#define BSP_FEATURE_GPT_32BIT_CHANNEL_MASK                   (0xF)
#define BSP_FEATURE_GPT_CLOCK_DIVIDER_STEP_SIZE              (4U)
#define BSP_FEATURE_GPT_CLOCK_DIVIDER_VALUE_7_9_VALID        (0U)
#define BSP_FEATURE_GPT_EVENT_COUNT_CHANNEL_MASK             (BSP_FEATURE_GPT_VALID_CHANNEL_MASK)
#define BSP_FEATURE_GPT_ODC_FRANGE_FREQ_MIN                  (0U) // Feature not available on this MCU
#define BSP_FEATURE_GPT_ODC_FREQ_MAX                         (0U) // Feature not available on this MCU
#define BSP_FEATURE_GPT_ODC_FREQ_MIN                         (0U) // Feature not available on this MCU
#define BSP_FEATURE_GPT_ODC_VALID_CHANNEL_MASK               (0U) // Feature not available on this MCU
#define BSP_FEATURE_GPT_TPCS_SHIFT                           (1U)
#define BSP_FEATURE_GPT_VALID_CHANNEL_MASK                   (0x13F)

#define BSP_FEATURE_I3C_MAX_DEV_COUNT                        (0U) // Feature not available on this MCU
#define BSP_FEATURE_I3C_NTDTBP0_DEPTH                        (0U) // Feature not available on this MCU
#define BSP_FEATURE_I3C_NUM_CHANNELS                         (0U) // Feature not available on this MCU
#define BSP_FEATURE_I3C_MSTP_OFFSET                          (0U) // Feature not available on this MCU

#define BSP_FEATURE_ICU_HAS_FILTER                           (1U)
#define BSP_FEATURE_ICU_HAS_IELSR                            (1U)
#define BSP_FEATURE_ICU_HAS_INTERRUPT_GROUPS                 (0U)
#define BSP_FEATURE_ICU_HAS_WUPEN1                           (0U)
#define BSP_FEATURE_ICU_SBYEDCR_MASK                         (0U) // Feature not available on this MCU
#define BSP_FEATURE_ICU_IRQ_CHANNELS_MASK                    (0xCBDFU)
#define BSP_FEATURE_ICU_WUPEN_MASK                           (0xFB97CADFU)
#define BSP_FEATURE_ICU_FIXED_IELSR_COUNT                    (0U)

#define BSP_FEATURE_IIC_BUS_FREE_TIME_MULTIPLIER             (0U)
#define BSP_FEATURE_IIC_B_FAST_MODE_PLUS                     (0) // Feature not available on this MCU
#define BSP_FEATURE_IIC_B_VALID_CHANNEL_MASK                 (0) // Feature not available on this MCU
#define BSP_FEATURE_IIC_FAST_MODE_PLUS                       (0U)
#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK                   (0x03)
#define BSP_FEATURE_IIC_VERSION                              (0) // Feature not available on this MCU

#define BSP_FEATURE_IOPORT_ELC_PORTS                         (0x001EU)
#define BSP_FEATURE_IOPORT_HAS_ETHERNET                      (0U)
#define BSP_FEATURE_IOPORT_VERSION                           (1U)

#define BSP_FEATURE_IWDT_CLOCK_FREQUENCY                     (15000UL)
#define BSP_FEATURE_IWDT_SUPPORTS_REGISTER_START_MODE        (0U) // Feature not available on this MCU

#define BSP_FEATURE_KINT_HAS_MSTP                            (0U)

#define BSP_FEATURE_LPM_CHANGE_MSTP_ARRAY                    (0)  // Feature not available on this MCU
#define BSP_FEATURE_LPM_CHANGE_MSTP_REQUIRED                 (0U)
#define BSP_FEATURE_LPM_DPSIEGR_MASK                         (0)  // Feature not available on this MCU
#define BSP_FEATURE_LPM_DPSIER_MASK                          (0)  // Feature not available on this MCU
#define BSP_FEATURE_LPM_HAS_DEEP_SLEEP                       (0U)
#define BSP_FEATURE_LPM_HAS_DEEP_STANDBY                     (0U)
#define BSP_FEATURE_LPM_HAS_DPSBYCR_DEEPCUT                  (0U)
#define BSP_FEATURE_LPM_HAS_DPSBYCR_DPSBY                    (0U)
#define BSP_FEATURE_LPM_HAS_DPSBYCR_SRKEEP                   (0U)
#define BSP_FEATURE_LPM_HAS_LDO_CONTROL                      (0U)
#define BSP_FEATURE_LPM_HAS_LPSCR                            (0U)
#define BSP_FEATURE_LPM_HAS_PDRAMSCR                         (0U)
#define BSP_FEATURE_LPM_HAS_SBYCR_OPE                        (1U)
#define BSP_FEATURE_LPM_HAS_SBYCR_SSBY                       (1U)
#define BSP_FEATURE_LPM_HAS_SNOOZE                           (1U)
#define BSP_FEATURE_LPM_HAS_SNZEDCR1                         (0U)
#define BSP_FEATURE_LPM_HAS_SNZREQCR1                        (0U)
#define BSP_FEATURE_LPM_HAS_STCONR                           (0U)
#define BSP_FEATURE_LPM_HAS_HOCO_STARTUP_SPEED_MODE          (0U) // Feature not available on this MCU
#define BSP_FEATURE_LPM_HAS_STANDBY_SOSC_SELECT              (0U) // Feature not available on this MCU
#define BSP_FEATURE_LPM_HAS_FLASH_MODE_SELECT                (0U) // Feature not available on this MCU
#define BSP_FEATURE_LPM_SNOOZE_REQUEST_DTCST_DTCST           (0U) // Feature not available on this MCU
#define BSP_FEATURE_LPM_SBYCR_WRITE1_B14                     (0)
#define BSP_FEATURE_LPM_SNZEDCR_MASK                         (0x0000009FU)
#define BSP_FEATURE_LPM_SNZREQCR_MASK                        (0x7382CADFU)
#define BSP_FEATURE_LPM_STANDBY_MOCO_REQUIRED                (0U)

#define BSP_FEATURE_LVD_HAS_DIGITAL_FILTER                   (0U)
#define BSP_FEATURE_LVD_HAS_EXT_MONITOR                      (0U)
#define BSP_FEATURE_LVD_HAS_LVDLVLR                          (1U)
#define BSP_FEATURE_LVD_MONITOR_1_HI_THRESHOLD               (LVD_THRESHOLD_MONITOR_1_LEVEL_4_29V) // 4.29V
#define BSP_FEATURE_LVD_MONITOR_1_LOW_THRESHOLD              (LVD_THRESHOLD_MONITOR_1_LEVEL_1_65V) // 1.65V
#define BSP_FEATURE_LVD_MONITOR_2_HI_THRESHOLD               (LVD_THRESHOLD_MONITOR_2_LEVEL_4_29V) // 4.29V
#define BSP_FEATURE_LVD_MONITOR_2_LOW_THRESHOLD              (LVD_THRESHOLD_MONITOR_2_LEVEL_3_84V) // 3.84V
#define BSP_FEATURE_LVD_MONITOR_1_STABILIZATION_TIME_US      (300U)                                // LVD1 operation stabilization time after LVD1 is enabled
#define BSP_FEATURE_LVD_MONITOR_2_STABILIZATION_TIME_US      (300U)                                // LVD2 operation stabilization time after LVD2 is enabled
#define BSP_FEATURE_LVD_SUPPORT_RESET_ON_RISING_EDGE         (0U)
#define BSP_FEATURE_LVD_VERSION                              (1U)

#define BSP_FEATURE_MACL_SUPPORTED                           (0U)

#define BSP_FEATURE_OPAMP_BASE_ADDRESS                       (1U)
#define BSP_FEATURE_OPAMP_HAS_MIDDLE_SPEED                   (0U)
#define BSP_FEATURE_OPAMP_HAS_SWITCHES                       (0U)
#define BSP_FEATURE_OPAMP_HAS_THIRD_CHANNEL                  (1U)
#define BSP_FEATURE_OPAMP_MIN_WAIT_TIME_HS_US                (13U)
#define BSP_FEATURE_OPAMP_MIN_WAIT_TIME_LP_US                (650U)    // This information comes from the Electrical Characteristics chapter of the hardware manual.
#define BSP_FEATURE_OPAMP_MIN_WAIT_TIME_MS_US                (0xFFFFU) // Middle speed mode not supported
#define BSP_FEATURE_OPAMP_TRIM_CAPABLE                       (0U)
#define BSP_FEATURE_OPAMP_VARIANT_CHANNEL_MASK               (0xFU)

#define BSP_FEATURE_OSPI_DEVICE_0_START_ADDRESS              (0x0U)
#define BSP_FEATURE_OSPI_DEVICE_1_START_ADDRESS              (0x0U)

#define BSP_FEATURE_POEG_CHANNEL_MASK                        (0x3U)

#define BSP_FEATURE_QSPI_DEVICE_START_ADDRESS                (0x0U)

#define BSP_FEATURE_RTC_IS_AVAILABLE                         (1U)
#define BSP_FEATURE_RTC_IS_IRTC                              (0U)
#define BSP_FEATURE_RTC_HAS_ROPSEL                           (0U)
#define BSP_FEATURE_RTC_HAS_TCEN                             (1U)
#define BSP_FEATURE_RTC_RTCCR_CHANNELS                       (1U)
#define BSP_FEATURE_SYSC_HAS_VBTICTLR                        (1U)

#define BSP_FEATURE_SAU_UART_VALID_CHANNEL_MASK              (0U) // Feature not available on this MCU

#define BSP_FEATURE_SCI_ADDRESS_MATCH_CHANNELS               (BSP_FEATURE_SCI_CHANNELS)
#define BSP_FEATURE_SCI_CHANNELS                             (0x213U)
#define BSP_FEATURE_SCI_CLOCK                                (FSP_PRIV_CLOCK_PCLKA)
#define BSP_FEATURE_SCI_SPI_SCKSEL_VALUE                     (0U) // Feature not available on this MCU
#define BSP_FEATURE_SCI_UART_CSTPEN_CHANNELS                 (0x0U)
#define BSP_FEATURE_SCI_UART_FIFO_CHANNELS                   (0x3U)
#define BSP_FEATURE_SCI_UART_FIFO_DEPTH                      (16U)
#define BSP_FEATURE_SCI_VERSION                              (1U)
#define BSP_FEATURE_SCI_LIN_CHANNELS                         (0U) // Feature not available on this MCU

#define BSP_FEATURE_SDHI_CLOCK                               (FSP_PRIV_CLOCK_PCLKA)
#define BSP_FEATURE_SDHI_HAS_CARD_DETECTION                  (0)  // Feature not available on this MCU
#define BSP_FEATURE_SDHI_MIN_CLOCK_DIVISION_SHIFT            (0)  // Feature not available on this MCU
#define BSP_FEATURE_SDHI_SUPPORTS_8_BIT_MMC                  (0)  // Feature not available on this MCU
#define BSP_FEATURE_SDHI_VALID_CHANNEL_MASK                  (0)  // Feature not available on this MCU

#define BSP_FEATURE_SDRAM_START_ADDRESS                      (0x0U)

#define BSP_FEATURE_SLCDC_HAS_8_TIME_SLICE                   (0U)
#define BSP_FEATURE_SLCDC_HAS_INTERNAL_VOLT_GEN              (0U)
#define BSP_FEATURE_SLCDC_MAX_NUM_SEG                        (54U)
#define BSP_FEATURE_SLCDC_HAS_VL1SEL                         (0)
#define BSP_FEATURE_SLCDC_CONTRAST_MAX_4BIAS                 (0)
#define BSP_FEATURE_SLCDC_CONTRAST_MAX                       (0)

#define BSP_FEATURE_SPI_CLK                                  (FSP_PRIV_CLOCK_PCLKA)
#define BSP_FEATURE_SPI_HAS_SPCR3                            (0U)
#define BSP_FEATURE_SPI_HAS_SSL_LEVEL_KEEP                   (1U)
#define BSP_FEATURE_SPI_MAX_CHANNEL                          (2U)
#define BSP_FEATURE_SPI_SSL_LEVEL_KEEP_VALID_CHANNEL_MASK    (0x1U)

#define BSP_FEATURE_SRAM_SRAMWTSC_WAIT_CYCLE_ENABLE          (0)    // Feature not available on this MCU

#define BSP_FEATURE_SSI_FIFO_NUM_STAGES                      (0U)
#define BSP_FEATURE_SSI_VALID_CHANNEL_MASK                   (0)    // Feature not available on this MCU

#define BSP_FEATURE_TAU_CLOCK_SOURCE                         (NULL) // Feature not available on this MCU
#define BSP_FEATURE_TAU_VALID_CHANNEL_MASK                   (0)    // Feature not available on this MCU

#define BSP_FEATURE_TML_MAX_CLOCK_DIVIDER                    (0U)   // Feature not available on this MCU
#define BSP_FEATURE_TML_NUM_CHANNELS                         (0)    // Feature not available on this MCU
#define BSP_FEATURE_TML_VALID_CHANNEL_MASK                   (0U)   // Feature not available on this MCU

#define BSP_FEATURE_TFU_SUPPORTED                            (0U)   // Trigonometric Function Unit (TFU) not available on this MCU

#define BSP_FEATURE_TRNG_HAS_MODULE_STOP                     (0U)
#define BSP_FEATURE_TZ_NS_OFFSET                             (0U)
#define BSP_FEATURE_TZ_HAS_TRUSTZONE                         (0U)
#define BSP_FEATURE_TZ_HAS_DLM                               (0U)
#define BSP_FEATURE_TZ_VERSION                               (0U)

#define BSP_FEATURE_ULPT_MAX_CHANNEL_NUM                     (0)
#define BSP_FEATURE_ULPT_VALID_CHANNEL_MASK                  (0U)

#endif