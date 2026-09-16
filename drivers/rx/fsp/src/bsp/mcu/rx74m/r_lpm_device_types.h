/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RX74M
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RX74M) */

#ifndef R_LPM_DEVICE_TYPES_H
#define R_LPM_DEVICE_TYPES_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_OVERRIDE_LPM_STANDBY_WAKE_SOURCE_T
#define BSP_OVERRIDE_LPM_DEEP_STANDBY_WAKE_SOURCE_T
#define BSP_OVERRIDE_LPM_DEEP_STANDBY_CANCEL_EDGE_T
#define BSP_OVERRIDE_LPM_SNOOZE_CANCEL_T
#define BSP_OVERRIDE_LPM_SNOOZE_REQUEST_T
#define BSP_OVERRIDE_LPM_POWER_SUPPLY_T

/** Deep Standby Interrupt Edge */
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_EDGE_NONE        (0)          ///< No options for a deep standby cancel source
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ0_RISING      (1ULL << 0)  ///< IRQ0-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ1_RISING      (1ULL << 1)  ///< IRQ1-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ2_RISING      (1ULL << 2)  ///< IRQ2-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ3_RISING      (1ULL << 3)  ///< IRQ3-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ4_RISING      (1ULL << 4)  ///< IRQ4-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ5_RISING      (1ULL << 5)  ///< IRQ5-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ6_RISING      (1ULL << 6)  ///< IRQ6-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ7_RISING      (1ULL << 7)  ///< IRQ7-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ8_RISING      (1ULL << 8)  ///< IRQ8-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ9_RISING      (1ULL << 9)  ///< IRQ9-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ10_RISING     (1ULL << 10) ///< IRQ10-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ11_RISING     (1ULL << 11) ///< IRQ11-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ12_RISING     (1ULL << 12) ///< IRQ12-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ13_RISING     (1ULL << 13) ///< IRQ13-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ14_RISING     (1ULL << 14) ///< IRQ14-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ15_RISING     (1ULL << 15) ///< IRQ14-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_PVD1_RISING      (1ULL << 16) ///< PVD1 Rising Slope
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_PVD2_RISING      (1ULL << 17) ///< PVD2 Rising Slope
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_NMI_RISING       (1ULL << 20) ///< NMI Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ16_RISING     (1ULL << 24) ///< IRQ16-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ17_RISING     (1ULL << 25) ///< IRQ17-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ18_RISING     (1ULL << 26) ///< IRQ18-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ19_RISING     (1ULL << 27) ///< IRQ19-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ20_RISING     (1ULL << 28) ///< IRQ20-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ21_RISING     (1ULL << 29) ///< IRQ21-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ22_RISING     (1ULL << 30) ///< IRQ22-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ23_RISING     (1ULL << 31) ///< IRQ23-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ24_RISING     (1ULL << 32) ///< IRQ24-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ25_RISING     (1ULL << 33) ///< IRQ25-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ26_RISING     (1ULL << 34) ///< IRQ26-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ27_RISING     (1ULL << 35) ///< IRQ27-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ28_RISING     (1ULL << 36) ///< IRQ28-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ29_RISING     (1ULL << 37) ///< IRQ29-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ30_RISING     (1ULL << 38) ///< IRQ30-DS Pin Rising Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ31_RISING     (1ULL << 39) ///< IRQ31-DS Pin Rising Edge

#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ0_FALLING     (0ULL)       ///< IRQ0-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ1_FALLING     (0ULL)       ///< IRQ1-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ2_FALLING     (0ULL)       ///< IRQ2-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ3_FALLING     (0ULL)       ///< IRQ3-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ4_FALLING     (0ULL)       ///< IRQ4-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ5_FALLING     (0ULL)       ///< IRQ5-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ6_FALLING     (0ULL)       ///< IRQ6-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ7_FALLING     (0ULL)       ///< IRQ7-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ8_FALLING     (0ULL)       ///< IRQ8-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ9_FALLING     (0ULL)       ///< IRQ9-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ10_FALLING    (0ULL)       ///< IRQ10-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ11_FALLING    (0ULL)       ///< IRQ11-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ12_FALLING    (0ULL)       ///< IRQ12-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ13_FALLING    (0ULL)       ///< IRQ13-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ14_FALLING    (0ULL)       ///< IRQ14-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ15_FALLING    (0ULL)       ///< IRQ14-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_PVD1_FALLING     (0ULL)       ///< LVD1 Falling Slope
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_PVD2_FALLING     (0ULL)       ///< LVD2 Falling Slope
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_NMI_FALLING      (0ULL)       ///< NMI Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ16_FALLING    (0ULL)       ///< IRQ16-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ17_FALLING    (0ULL)       ///< IRQ17-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ18_FALLING    (0ULL)       ///< IRQ18-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ19_FALLING    (0ULL)       ///< IRQ19-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ20_FALLING    (0ULL)       ///< IRQ20-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ21_FALLING    (0ULL)       ///< IRQ21-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ22_FALLING    (0ULL)       ///< IRQ22-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ23_FALLING    (0ULL)       ///< IRQ23-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ24_FALLING    (0ULL)       ///< IRQ24-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ25_FALLING    (0ULL)       ///< IRQ25-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ26_FALLING    (0ULL)       ///< IRQ26-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ27_FALLING    (0ULL)       ///< IRQ27-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ28_FALLING    (0ULL)       ///< IRQ28-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ29_FALLING    (0ULL)       ///< IRQ29-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ30_FALLING    (0ULL)       ///< IRQ30-DS Pin Falling Edge
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ31_FALLING    (0ULL)       ///< IRQ31-DS Pin Falling Edge

/** Deep Standby cancel sources */
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_RESET_ONLY       0ULL         ///< Cancel deep standby only by reset
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ0             (1ULL << 0)  ///< IRQ0
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ1             (1ULL << 1)  ///< IRQ1
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ2             (1ULL << 2)  ///< IRQ2
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ3             (1ULL << 3)  ///< IRQ3
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ4             (1ULL << 4)  ///< IRQ4
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ5             (1ULL << 5)  ///< IRQ5
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ6             (1ULL << 6)  ///< IRQ6
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ7             (1ULL << 7)  ///< IRQ7
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ8             (1ULL << 8)  ///< IRQ8
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ9             (1ULL << 9)  ///< IRQ9
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ10            (1ULL << 10) ///< IRQ10
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ11            (1ULL << 11) ///< IRQ11
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ12            (1ULL << 12) ///< IRQ12
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ13            (1ULL << 13) ///< IRQ13
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ14            (1ULL << 14) ///< IRQ14
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ15            (1ULL << 15) ///< IRQ15
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_PVD1             (1ULL << 16) ///< PVD1
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_PVD2             (1ULL << 17) ///< PVD2
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_RTC_INTERVAL     (1ULL << 18) ///< RTC Interval Interrupt
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_RTC_ALARM        (1ULL << 19) ///< RTC Alarm Interrupt
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_NMI              (1ULL << 20) ///< NMI
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_USB0             (1ULL << 24) ///< USBFS Suspend/Resume
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_USBHS            (1ULL << 25) ///< USBHS Suspend/Resume
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IWDT             (1ULL << 29) ///< IWDT Underflow
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_VBATT            (1ULL << 31) ///< VBATT Tamper Detection
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ16            (1ULL << 32) ///< IRQ16
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ17            (1ULL << 33) ///< IRQ17
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ18            (1ULL << 34) ///< IRQ18
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ19            (1ULL << 35) ///< IRQ19
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ20            (1ULL << 36) ///< IRQ20
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ21            (1ULL << 37) ///< IRQ21
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ22            (1ULL << 38) ///< IRQ22
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ23            (1ULL << 39) ///< IRQ23
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ24            (1ULL << 40) ///< IRQ24
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ25            (1ULL << 41) ///< IRQ25
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ26            (1ULL << 42) ///< IRQ26
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ27            (1ULL << 43) ///< IRQ27
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ28            (1ULL << 44) ///< IRQ28
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ29            (1ULL << 45) ///< IRQ29
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ30            (1ULL << 46) ///< IRQ30
#define LPM_DEEP_STANDBY_CANCEL_SOURCE_IRQ31            (1ULL << 47) ///< IRQ31

/** Wake from deep sleep or standby mode sources, does not apply to sleep or deep standby modes */
#define LPM_STANDBY_WAKE_SOURCE_REST                    (0ULL)       ///< Cancel Wake from deep sleep or standby mode sources only by reset
#define LPM_STANDBY_WAKE_SOURCE_IRQ0                    (1ULL << 0)  ///< IRQ0
#define LPM_STANDBY_WAKE_SOURCE_IRQ1                    (1ULL << 1)  ///< IRQ1
#define LPM_STANDBY_WAKE_SOURCE_IRQ2                    (1ULL << 2)  ///< IRQ2
#define LPM_STANDBY_WAKE_SOURCE_IRQ3                    (1ULL << 3)  ///< IRQ3
#define LPM_STANDBY_WAKE_SOURCE_IRQ4                    (1ULL << 4)  ///< IRQ4
#define LPM_STANDBY_WAKE_SOURCE_IRQ5                    (1ULL << 5)  ///< IRQ5
#define LPM_STANDBY_WAKE_SOURCE_IRQ6                    (1ULL << 6)  ///< IRQ6
#define LPM_STANDBY_WAKE_SOURCE_IRQ7                    (1ULL << 7)  ///< IRQ7
#define LPM_STANDBY_WAKE_SOURCE_IRQ8                    (1ULL << 8)  ///< IRQ8
#define LPM_STANDBY_WAKE_SOURCE_IRQ9                    (1ULL << 9)  ///< IRQ9
#define LPM_STANDBY_WAKE_SOURCE_IRQ10                   (1ULL << 10) ///< IRQ10
#define LPM_STANDBY_WAKE_SOURCE_IRQ11                   (1ULL << 11) ///< IRQ11
#define LPM_STANDBY_WAKE_SOURCE_IRQ12                   (1ULL << 12) ///< IRQ12
#define LPM_STANDBY_WAKE_SOURCE_IRQ13                   (1ULL << 13) ///< IRQ13
#define LPM_STANDBY_WAKE_SOURCE_IRQ14                   (1ULL << 14) ///< IRQ14
#define LPM_STANDBY_WAKE_SOURCE_IRQ15                   (1ULL << 15) ///< IRQ15
#define LPM_STANDBY_WAKE_SOURCE_I3C0                    (1ULL << 16) ///< I3C0 address match interrupt
#define LPM_STANDBY_WAKE_SOURCE_RIICHS1                 (1ULL << 17) ///< RIICHS1 address match interrupt
#define LPM_STANDBY_WAKE_SOURCE_RIICHS2                 (1ULL << 18) ///< RIICHS2 address match interrupt
#define LPM_STANDBY_WAKE_SOURCE_VBATT                   (1ULL << 19) ///< VBATT Monitor interrupt
#define LPM_STANDBY_WAKE_SOURCE_PDM                     (1ULL << 20) ///< PDM Sound Detection
#define LPM_STANDBY_WAKE_SOURCE_SOST                    (1ULL << 21) ///< SOSTD interrupt
#define LPM_STANDBY_WAKE_SOURCE_PVD1                    (1ULL << 24) ///< Low Voltage Detection 1 interrupt
#define LPM_STANDBY_WAKE_SOURCE_PVD2                    (1ULL << 25) ///< Low Voltage Detection 2 interrupt
#define LPM_STANDBY_WAKE_SOURCE_USB0                    (1ULL << 26) ///< USB High-speed interrupt
#define LPM_STANDBY_WAKE_SOURCE_RTCALM                  (1ULL << 28) ///< RTC Alarm interrupt
#define LPM_STANDBY_WAKE_SOURCE_RTCPRD                  (1ULL << 29) ///< RTC Period interrupt
#define LPM_STANDBY_WAKE_SOURCE_USBHS                   (1ULL << 30) ///< USB High-speed interrupt
#define LPM_STANDBY_WAKE_SOURCE_IWDT                    (1ULL << 31) ///< Independent watchdog interrupt
#define LPM_STANDBY_WAKE_SOURCE_IRQ16                   (1ULL << 32) ///< IRQ16
#define LPM_STANDBY_WAKE_SOURCE_IRQ17                   (1ULL << 33) ///< IRQ17
#define LPM_STANDBY_WAKE_SOURCE_IRQ18                   (1ULL << 34) ///< IRQ18
#define LPM_STANDBY_WAKE_SOURCE_IRQ19                   (1ULL << 35) ///< IRQ19
#define LPM_STANDBY_WAKE_SOURCE_IRQ20                   (1ULL << 36) ///< IRQ20
#define LPM_STANDBY_WAKE_SOURCE_IRQ21                   (1ULL << 37) ///< IRQ21
#define LPM_STANDBY_WAKE_SOURCE_IRQ22                   (1ULL << 38) ///< IRQ22
#define LPM_STANDBY_WAKE_SOURCE_IRQ23                   (1ULL << 39) ///< IRQ23
#define LPM_STANDBY_WAKE_SOURCE_IRQ24                   (1ULL << 40) ///< IRQ24
#define LPM_STANDBY_WAKE_SOURCE_IRQ25                   (1ULL << 41) ///< IRQ25
#define LPM_STANDBY_WAKE_SOURCE_IRQ26                   (1ULL << 42) ///< IRQ26
#define LPM_STANDBY_WAKE_SOURCE_IRQ27                   (1ULL << 43) ///< IRQ27
#define LPM_STANDBY_WAKE_SOURCE_IRQ28                   (1ULL << 44) ///< IRQ28
#define LPM_STANDBY_WAKE_SOURCE_IRQ29                   (1ULL << 45) ///< IRQ29
#define LPM_STANDBY_WAKE_SOURCE_IRQ30                   (1ULL << 46) ///< IRQ30
#define LPM_STANDBY_WAKE_SOURCE_IRQ31                   (1ULL << 47) ///< IRQ31

#define LPM_WAKE_UP_IRQ_PRIORITY_ENABLE                 (31U)
#define LPM_WAKE_UP_IRQ_PRIORITY_DISABLE                (0U)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef uint64_t lpm_standby_wake_source_bits_t;

/** Power supply control */
typedef enum e_lpm_power_supply
{
    /**
     * Power to the standby RAM, Low-speed on-chip oscillator, AGTn, and USBFS/HS resume
     * detecting unit is supplied in deep software standby mode
     */
    LPM_POWER_SUPPLY_DEEPCUT0 = 0U,

    /**
     * Power to the standby RAM, Low-speed on-chip oscillator, AGTn, and USBFS/HS resume
     * detecting unit is not supplied in deep software standby mode
     */
    LPM_POWER_SUPPLY_DEEPCUT1 = 1U,

    /**
     * Power to the standby RAM, Low-speed on-chip oscillator, AGTn, and USBFS/HS resume
     * detecting unit is not supplied in deep software standby mode. In addition, LVD is
     * disabled and the low power function in a poweron reset circuit is enabled
     */
    LPM_POWER_SUPPLY_DEEPCUT3 = 3UL,

    /**
     * Power to standby ESWM, EtherCAT slave controller ESC, PDC, CANFDG, CANFD, SDHIA is supplied in deep software standby mode.
     */
    LPM_POWER_SUPPLY_STANDBY_MODE1 = 0U,

    /**
     * Power to standby ESWM, EtherCAT slave controller ESC, PDC, CANFDG, CANFD, SDHIA is disabled in software standby mode.
     */
    LPM_POWER_SUPPLY_STANDBY_MODE2 = 1U,

    /**
     * Power to the standby RAM, Low-speed on-chip oscillator, Programmable Voltage Detection Unit 0,
     * and USBFS/HS resume detecting unit is supplied in deep software standby mode.
     */
    LPM_POWER_SUPPLY_DEEP_STANDBY_MODE1 = 0U,

    /**
     * Power to standby RAM, USBFS/HS resume detecting unit, Low-speed on-chip oscillator, and IWDT is
     * disabled in deep software standby mode. Power to the Programmable Voltage Detection Unit 0 is
     * supplied in deep software standby mode.
     */
    LPM_POWER_SUPPLY_DEEP_STANDBY_MODE2 = 1U,

    /**
     * Power to standby RAM, Programmable Voltage Detection Unit 0, USBFS/HS resume detecting unit,
     * Low-speed on-chip oscillator, and IWDT is disabled in deep software standby mode.
     */
    LPM_POWER_SUPPLY_DEEP_STANDBY_MODE3 = 2U,
} lpm_power_supply_t;

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
