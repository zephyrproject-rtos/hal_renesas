/*
 * Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @ingroup BSP_CONFIG_RA6B1
 * @defgroup BSP_CONFIG_RA6B1_GENERAL Build Time Configurations - General
 *
 * This file contains compile-time configuration options for general BSP settings.
 *
 * @{
 **********************************************************************************************************************/

#ifndef BSP_CFG_RA6B1_H
#define BSP_CFG_RA6B1_H

/***********************************************************************************************************************
 * Configuration Options
 **********************************************************************************************************************/

/* TODO */

/**
 * @name Part Number Information
 *
 * Enter the product part number for your MCU. This information will be used to obtain information about your MCU such
 * as package and memory size.
 * To help parse this information, the part number will be defined using multiple macros.
 *
 * <PRE>
 * R7FS 3 A 7 7 C 3 A01 C FB
 * |    | | | | | | |   | |  Macro Name                      Description
 * |    | | | | | | |   | |__BSP_CFG_MCU_PART_PACKAGE      = Package type, number of pins
 * |    | | | | | | |   |____not used                      = Quality ID
 * |    | | | | | | |________not used                      = Software ID
 * |    | | | | | |__________not used                      = Operating range
 * |    | | | | |____________BSP_CFG_MCU_PART_MEMORY_SIZE  = ROM, RAM, and Data Flash Capacity
 * |    | | | |______________BSP_CFG_MCU_PART_FEATURE_SET  = Superset, no encryption
 * |    | | |________________not used                      = Document index
 * |    | |__________________BSP_CFG_MCU_PART_CORE         = Core & frequency (CM4, 48MHz)
 * |    |____________________BSP_CFG_MCU_PART_SERIES       = Performance category (High-performance, Low power)
 * |_________________________not used                      = Renesas RA MCU
 * </PRE>
 */

#define BSP_MCU_GROUP_RA6B1    (1)

/* TODO */

/** Package type. Set the macro definition based on values below:
 * <PRE>
 * Character(s) = Value for macro = Package Type/Number of Pins/Other Info
 * BJ           = 0x0             = BGA/121
 * BG           = 0x1             = BGA/176
 * BD           = 0x2             = BGA/224
 * FL           = 0x3             = LQFP/48
 * FM           = 0x4             = LQFP/64
 * FP           = 0x5             = LQFP/100
 * FB           = 0x6             = LQFP/144
 * FC           = 0x7             = LQFP/176
 * LM           = 0x8             = LGA/36
 * LA           = 0x9             = LGA/100/5.5x5.5
 * LJ           = 0xA             = LGA/100/7x7
 * LK           = 0xB             = LGA/145
 * NF           = 0xC             = WQFN/40
 * NE           = 0xD             = WQFN/48
 * NB           = 0xE             = WQFN/64
 * </PRE>
 */
#ifndef BSP_CFG_MCU_PART_PACKAGE
 #define BSP_CFG_MCU_PART_PACKAGE    (0x6)
#endif

/* TODO */

/** ROM, RAM, and Data Flash Capacity.
 * <PRE>
 * Character(s) = Value for macro = ROM Size/Ram Size/Data Flash Size
 * 6            = 0x06             = 64KB
 * 7            = 0x07             = 128KB
 * 8            = 0x08             = 256KB
 * A            = 0x0A             = 512KB
 * C            = 0x0C             = 1MB
 * E            = 0x0E             = 2MB
 * G            = 0x10             = 3MB
 * H            = 0x11             = 4MB/640KB/64KB
 * </PRE>
 */
#ifndef BSP_CFG_MCU_PART_MEMORY_SIZE
 #define BSP_CFG_MCU_PART_MEMORY_SIZE    (0x07)
#endif

/** Core & Frequency.
 * <PRE>
 * Character(s) = Value for macro = Description
 * 33           = 0x21            = CM33
 * </PRE>
 */
#ifndef BSP_CFG_MCU_PART_CORE
 #define BSP_CFG_MCU_PART_CORE           (33)
#endif

/* TODO */

/** Series
 */
#ifndef BSP_CFG_MCU_PART_SERIES
 #define BSP_CFG_MCU_PART_SERIES    (0x2b)
#endif

/**(end of @name 'Part Number Information') */

/**
 * @name Stack & Heap Size Settings
 */

/* TODO */

/** The Main Stack size in bytes. This is the stack that is used out of reset and is required. Exceptions always use
 * the main stack.
 */
#ifndef BSP_CFG_STACK_MAIN_BYTES
 #define BSP_CFG_STACK_MAIN_BYTES    (CONFIG_MAIN_STACK_SIZE)
#endif

/* TODO */
/** Heap size in bytes. */
#ifndef BSP_CFG_HEAP_BYTES
 #define BSP_CFG_HEAP_BYTES    (CONFIG_HEAP_MEM_POOL_SIZE)
#endif

/* TODO */
/** NVM size in bytes. */
#define BSP_ROM_SIZE_BYTES     (0x180000) // 1536kB = 1.5MB

/** @} (end of @name 'Stack & Heap Size Settings')*/

/* XXX N/A for RRQ431 */
#if 0

/**
 * @name Option-Setting Memory (ROM registers) Settings
 *
 * Certain registers are stored in ROM and used to configure the MCU out of reset.
 *
 * @note To use the default values for a register, leave the macro as all 0xFF's.
 * @note ALL OPTIONS ARE DISABLED BY DEFAULT.
 */

/** Configure WDT and IWDT settings.
 * OFS0 - Option Function Select Register 0
 * - b31     Reserved (set to 1)
 * - b30     WDTSTPCTL - WDT Stop Control - (0=counting continues, 1=stop when entering sleep mode)
 * - b29     Reserved (set to 1)
 * - b28     WDTRSTIRQS - WDT Reset Interrupt Request - What to do on underflow (0=take interrupt, 1=reset MCU)
 * - b27:b26 WDTRPSS - WDT Window Start Position Select - (0=25%, 1=50%, 2=75%, 3=100%,don't use)
 * - b25:b24 WDTRPES - WDT Window End Position Select - (0=75%, 1=50%, 2=25%, 3=0%,don't use)
 * - b23:b20 WDTCKS - WDT Clock Frequency Division Ratio - (1=/4, 4=/64, 0xF=/128, 6=/512, 7=/2048, 8=/8192)
 * - b19:b18 WDTTOPS - WDT Timeout Period Select - (0=1024 cycles, 1=4096, 2=8192, 3=16384)
 * - b17     WDTSTRT - WDT Start Mode Select - (0=auto-start after reset, 1=halt after reset)
 * - b16:b15 Reserved (set to 1)
 * - b14     IWDTSTPCTL - IWDT Sleep Stop Control - (0=counting continues, 1=stop w/some low power modes)
 * - b13     Reserved (set to 1)
 * - b12     IWDTRSTIRQS - IWDT Reset Interrupt Request - What to do on underflow (0=take interrupt, 1=reset MCU)
 * - b11:b10 IWDTRPSS - IWDT Window Start Position Select - (0=25%, 1=50%, 2=75%, 3=100%,don't use)
 * - b9:b8   IWDTRPES - IWDT Window End Position Select - (0=75%, 1=50%, 2=25%, 3=0%,don't use)
 * - b7:b4   IWDTCKS - IWDT Clock Frequency Division Ratio - (0=none, 2=/16, 3 = /32, 4=/64, 0xF=/128, 5=/256)
 * - b3:b2   IWDTTOPS - IWDT Timeout Period Select - (0=128 cycles, 1=512, 2=1024, 3=2048)
 * - b1      IWDTSTRT - IWDT Start Mode Select - (0=auto-start after reset, 1=halt after reset)
 * - b0      Reserved (set to 1)
 *
 *  @note A value of 0xFFFFFFFF is the default and will disable all features
 */
 #ifndef BSP_CFG_ROM_REG_OFS0
  #define BSP_CFG_ROM_REG_OFS0    (0xFFFFFFFF)
 #endif

/** Configure whether voltage detection 0 circuit and HOCO are enabled after reset.
 * OFS1 - Option Function Select Register 1
 * - b31:b15 Reserved (set to 1)
 * - b14:b12 HOCOFRQ1 - HOCO frequency setting (Set using BSP_CFG_HOCO_FREQUENCY in bsp_clock_cfg.h)
 * - b11:b9  Reserved (set to 1)
 * - b8      HOCOEN - Enable/disable HOCO oscillation after a reset (0=enable, 1=disable)
 * - b7:b3   Reserved (set to 1)
 * - b2      LVDAS - Choose to enable/disable Voltage Detection 0 Circuit after a reset (0=enable, 1=disable)
 * - b1:b0   VDSEL - Voltage Detection 0 Level Select (1=2.94V, 2=2.87V, 3=2.80V)
 *
 * @note A value of 0xFFFFFFFF is the default and will disable all features
 */
 #ifndef BSP_CFG_ROM_REG_OFS1
  #define BSP_CFG_ROM_REG_OFS1    (0xFFFFFFFF)
 #endif

/** @} (end of @name 'Option-Setting Memory (ROM registers) Settings') */
#endif

/* TODO */

/**
 * @name Security MPU Options
 *
 * Each Security MPU region below has 3 macros.
 * - Enable/Disable option. Use 1 = disabled, 0 = enabled
 * - Start address - The start address of this MPU area.
 * - End address - The end address of this MPU area.
 *
 * @note Different areas have different restrictions on the addresses that can be set.
 * @note ALL REGIONS ARE DISABLED BY DEFAULT.
 */

/** Enable or disable PC Region 0
 * - 0 = Enabled
 * - 1 = Disabled
 */
#ifndef BSP_CFG_ROM_REG_MPU_PC0_ENABLE
 #define BSP_CFG_ROM_REG_MPU_PC0_ENABLE        (1)
#endif

/** Valid range: 0x00000000 - 0xFFFFFFFC */
#ifndef BSP_CFG_ROM_REG_MPU_PC0_START
 #define BSP_CFG_ROM_REG_MPU_PC0_START         (0xFFFFFFFF)
#endif

/** Valid range: 0x00000003 - 0xFFFFFFFF */
#ifndef BSP_CFG_ROM_REG_MPU_PC0_END
 #define BSP_CFG_ROM_REG_MPU_PC0_END           (0xFFFFFFFF)
#endif

/** Enable or disable PC Region 1
 * - 0 = Enabled
 * - 1 = Disabled
 */
#ifndef BSP_CFG_ROM_REG_MPU_PC1_ENABLE
 #define BSP_CFG_ROM_REG_MPU_PC1_ENABLE        (1)
#endif

/** Valid range: 0x00000000 - 0xFFFFFFFC */
#ifndef BSP_CFG_ROM_REG_MPU_PC1_START
 #define BSP_CFG_ROM_REG_MPU_PC1_START         (0xFFFFFFFF)
#endif

/** Valid range: 0x00000003 - 0xFFFFFFFF */
#ifndef BSP_CFG_ROM_REG_MPU_PC1_END
 #define BSP_CFG_ROM_REG_MPU_PC1_END           (0xFFFFFFFF)
#endif

/** Enable or disable Memory Region 0
 * - 0 = Enabled
 * - 1 = Disabled
 */
#ifndef BSP_CFG_ROM_REG_MPU_REGION0_ENABLE
 #define BSP_CFG_ROM_REG_MPU_REGION0_ENABLE    (1)
#endif

/** Valid range: 0x00000000 - 0x00FFFFFC */
#ifndef BSP_CFG_ROM_REG_MPU_REGION0_START
 #define BSP_CFG_ROM_REG_MPU_REGION0_START     (0xFFFFFFFF)
#endif

/** Valid range: 0x00000003 - 0x00FFFFFF */
#ifndef BSP_CFG_ROM_REG_MPU_REGION0_END
 #define BSP_CFG_ROM_REG_MPU_REGION0_END       (0xFFFFFFFF)
#endif

/** Enable or disable Memory Region 1
 * - 0 = Enabled
 * - 1 = Disabled
 */
#ifndef BSP_CFG_ROM_REG_MPU_REGION1_ENABLE
 #define BSP_CFG_ROM_REG_MPU_REGION1_ENABLE    (1)
#endif

/** Valid range: 0x00000000 - 0xFFFFFFFC */
#ifndef BSP_CFG_ROM_REG_MPU_REGION1_START
 #define BSP_CFG_ROM_REG_MPU_REGION1_START     (0xFFFFFFFF)
#endif

/** Valid range: 0x00000003 - 0xFFFFFFFF */
#ifndef BSP_CFG_ROM_REG_MPU_REGION1_END
 #define BSP_CFG_ROM_REG_MPU_REGION1_END       (0xFFFFFFFF)
#endif

/** Enable or disable Memory Region 2
 * - 0 = Enabled
 * - 1 = Disabled
 */
#ifndef BSP_CFG_ROM_REG_MPU_REGION2_ENABLE
 #define BSP_CFG_ROM_REG_MPU_REGION2_ENABLE    (1)
#endif

/** Valid range: 0x40000000 - 0x407FFFFC */
#ifndef BSP_CFG_ROM_REG_MPU_REGION2_START
 #define BSP_CFG_ROM_REG_MPU_REGION2_START     (0xFFFFFFFF)
#endif

/** Valid range: 0x40000003 - 0x407FFFFF */
#ifndef BSP_CFG_ROM_REG_MPU_REGION2_END
 #define BSP_CFG_ROM_REG_MPU_REGION2_END       (0xFFFFFFFF)
#endif

/** Enable or disable Memory Region 3
 * - 0 = Enabled
 * - 1 = Disabled
 */
#ifndef BSP_CFG_ROM_REG_MPU_REGION3_ENABLE
 #define BSP_CFG_ROM_REG_MPU_REGION3_ENABLE    (1)
#endif

/** Valid range: 0x40000000 - 0x407FFFFC */
#ifndef BSP_CFG_ROM_REG_MPU_REGION3_START
 #define BSP_CFG_ROM_REG_MPU_REGION3_START     (0xFFFFFFFF)
#endif

/** Valid range: 0x40000003 - 0x407FFFFF */
#ifndef BSP_CFG_ROM_REG_MPU_REGION3_END
 #define BSP_CFG_ROM_REG_MPU_REGION3_END       (0xFFFFFFFF)
#endif

/** @} (end of @name 'Security MPU Options') */

/* N/A for RA6B1 */
#if 0

/**
 * @name ID Code Protection
 *
 * Set your desired ID code. If you set this value and program it into the MCU then you will need to remember
 * the ID code because the debugger will ask for it when trying to connect. The ID Code is 16 bytes long.
 * The macro below define the ID Code in 4-byte sections.
 *
 * @note Leave at the default (all 0xFF's) if you do not wish to use an ID code (Protection Disabled).
 * @warning Please consult the hardware manual for your MCU on valid ID Code settings.
 */

/** Lowest 4-byte section, address 0x40120050. From MSB to LSB: ID Code 16, ID code 15, ID code 14, ID code 13. */
 #ifndef BSP_CFG_ID_CODE_LONG_1
  #define BSP_CFG_ID_CODE_LONG_1    (0xFFFFFFFF)
 #endif

/** 2nd ID Code section, address 0x40120054. From MSB to LSB: ID code 12, ID code 11, ID code 10, ID code 9. */
 #ifndef BSP_CFG_ID_CODE_LONG_2
  #define BSP_CFG_ID_CODE_LONG_2    (0xFFFFFFFF)
 #endif

/** 3rd ID Code section, address 0x40120058. From MSB to LSB: ID code 8, ID code 7, ID code 6, ID code 5. */
 #ifndef BSP_CFG_ID_CODE_LONG_3
  #define BSP_CFG_ID_CODE_LONG_3    (0xFFFFFFFF)
 #endif

/** 4th ID Code section, address 0x4012005C. From MSB to LSB: ID code 4, ID code 3, ID code 2, ID code 1. */
 #ifndef BSP_CFG_ID_CODE_LONG_4
  #define BSP_CFG_ID_CODE_LONG_4    (0xFFFFFFFF)
 #endif

/** @} (end of 'ID Code Protection') */
#endif

/**
 * @name Image Header
 *
 * Set your desired image version. Version is in Little Endian format so version 01.02.03.04 should be
 * set as 0x04030201. Default value is 00.00.00.00.
 */

#ifndef BSP_CFG_IMAGE_HEADER_VERSION
 #define BSP_CFG_IMAGE_HEADER_VERSION    (0x00000000)
#endif

/** @} (end of 'Image Header') */

/**
 * @name Other Hardware Options
 */

/** This macro is used to define the voltage that is supplied to the MCU (Vcc). This macro is defined in millivolts.
 * This macro does not actually change anything on the MCU. Some AMS modules need this information so it is
 * defined here.
 */
#ifndef BSP_CFG_MCU_VCC_MV
 #define BSP_CFG_MCU_VCC_MV    (3300)
#endif

/** @} (end of 'Other Hardware Options') */

/**
 *  @name Project-Wide Software Options
 */

/** By default AMS modules will check input parameters to be valid. This is helpful during development but some users
 * will want to disable this for production code. The reason for this would be to save execution time and code space.
 * This macro is a global setting for enabling or disabling parameter checking. Each AMS module will also have its
 * own local macro for this same purpose. By default the local macros will take the global value from here though
 * they can be overridden. Therefore, the local setting has priority over this global setting. Disabling parameter
 * checking should only used when inputs are known to be good and the increase in speed or decrease in code space is
 * needed.
 * - 0 = Global setting for parameter checking is disabled.
 * - 1 = Global setting for parameter checking is enabled (Default).
 */
#ifndef BSP_CFG_PARAM_CHECKING_ENABLE
 #define BSP_CFG_PARAM_CHECKING_ENABLE    (1)
#endif

/** Specify which RTOS is being used
 * - 0 = No RTOS
 * - 1 = ThreadX
 * - 2 = FreeRTOS
 * - 3 = Zephyr
 */
#ifndef BSP_CFG_RTOS
 #define BSP_CFG_RTOS                     (3)
#endif

/** Specify what to do if FSP_ASSERT fails
 * - 0 = Return FSP_ERR_ASSERTION.
 * - 1 = Call fsp_error_log, then return FSP_ERR_ASSERTION.  Note that fsp_error_log is a weak function and should be
 *       overridden in user code based on the prototype in fsp/src/bsp/mcu/all/bsp_common.h.
 * - 2 = Use standard assert library to halt execution.
 */
#ifndef BSP_CFG_ASSERT
 #define BSP_CFG_ASSERT                   (0U)
#endif

/** Specify what to do when error codes are returned from FSP functions
 * - 0 = Return error code.
 * - 1 = Call fsp_error_log, then return error code.  Note that fsp_error_log is a weak function and should be
 *       overridden in user code based on the prototype in fsp/src/bsp/mcu/all/bsp_common.h.
 */
#ifndef BSP_CFG_ERROR_LOG
 #ifdef TEST_BSP_CFG_ERROR_LOG
  #define BSP_CFG_ERROR_LOG                     (TEST_BSP_CFG_ERROR_LOG)
 #else
  #define BSP_CFG_ERROR_LOG                     (0U)
 #endif
#endif

#if defined(_RRQ_TZ_SECURE)
 #define BSP_TZ_SECURE_BUILD                    (1)
 #define BSP_TZ_NONSECURE_BUILD                 (0)
#elif defined(_RRQ_TZ_NONSECURE)
 #define BSP_TZ_SECURE_BUILD                    (0)
 #define BSP_TZ_NONSECURE_BUILD                 (1)
#else
 #define BSP_TZ_SECURE_BUILD                    (0)
 #define BSP_TZ_NONSECURE_BUILD                 (0)
#endif
#ifndef BSP_TZ_CFG_INIT_SECURE_ONLY
 #define BSP_TZ_CFG_INIT_SECURE_ONLY            (1U)
#endif
#ifndef BSP_TZ_CFG_SKIP_INIT
 #define BSP_TZ_CFG_SKIP_INIT                   (BSP_TZ_NONSECURE_BUILD && BSP_TZ_CFG_INIT_SECURE_ONLY)
#endif
#ifndef BSP_TZ_CFG_EXCEPTION_RESPONSE
 #define BSP_TZ_CFG_EXCEPTION_RESPONSE          (1U)
#endif

// TODO: The Security Arbitration of the CGC is fixed by HW. Consider dropping this macro.
#ifndef BSP_CFG_CLOCKS_SECURE
 #define BSP_CFG_CLOCKS_SECURE                  (1U)
#endif

/* CMSIS TrustZone Settings */
#ifndef SCB_CSR_AIRCR_INIT
 #define SCB_CSR_AIRCR_INIT                     (1)
#endif
#ifndef SCB_AIRCR_BFHFNMINS_VAL
 #define SCB_AIRCR_BFHFNMINS_VAL                (0)
#endif
#ifndef SCB_AIRCR_SYSRESETREQS_VAL
 #define SCB_AIRCR_SYSRESETREQS_VAL             (0)
#endif
#ifndef SCB_AIRCR_PRIS_VAL
 #define SCB_AIRCR_PRIS_VAL                     (0)
#endif
#define TZ_FPU_NS_USAGE                         (1)
#ifndef SCB_NSACR_CP10_11_VAL
 #define SCB_NSACR_CP10_11_VAL                  (3)
#endif
#ifndef FPU_FPCCR_TS_VAL
 #define FPU_FPCCR_TS_VAL                       (1)
#endif
#define FPU_FPCCR_CLRONRETS_VAL                 (1)
#ifndef FPU_FPCCR_CLRONRET_VAL
 #define FPU_FPCCR_CLRONRET_VAL                 (0)
#endif

#ifndef BSP_TZ_CFG_SSA_REG
 #define BSP_TZ_CFG_SSA_REG                     (0x00000000)
#endif

#ifndef BSP_TZ_CFG_SSA2_REG
 #define BSP_TZ_CFG_SSA2_REG                    (0x00000000)
#endif

/** Specify whether SYSCPU toggles P1_01 after wakeup */
#ifndef BSP_CFG_SLEEP_TRACE_VIA_GPIO
 #define BSP_CFG_SLEEP_TRACE_VIA_GPIO           (0U)
#endif

#ifndef BSP_CFG_STARTUP_MAGIC_CHECK
 #define BSP_CFG_STARTUP_MAGIC_CHECK            (1U)
#endif

/** Specify if freertos uses system timer as a tick source. */
#ifndef BSP_CFG_USE_SYS_TIMER
 #define BSP_CFG_USE_SYS_TIMER                  (1U)
#endif

#ifndef BSP_CFG_MTB_ENABLE
 #define BSP_CFG_MTB_ENABLE                     (1U)
#endif

/** IPC support. */
#ifndef BSP_CFG_IPC_USED
 #define BSP_CFG_IPC_USED                       (0x0)
#endif

#ifndef BSP_CFG_IVT_COPY_ENABLE
 #define BSP_CFG_IVT_COPY_ENABLE                (1)
#endif

#ifndef BSP_CFG_WAKEUP_RESET_HANDLER_ENABLE
 #define BSP_CFG_WAKEUP_RESET_HANDLER_ENABLE    (1)
#endif

#if (BSP_CFG_WAKEUP_RESET_HANDLER_ENABLE) && !(BSP_CFG_IVT_COPY_ENABLE)
 #error "Copy of IVT must be enabled when the Wakeup_Reset_Handler is used."
#endif

#ifndef BSP_CFG_PRODUCTION_HEADER_CRC
 #define BSP_CFG_PRODUCTION_HEADER_CRC    0xFDA8
#endif

/** @} (end of 'Project-Wide Software Options') */

#endif

/** @} (end of defgroup BSP_CONFIG_RA6B1_GENERAL) */
