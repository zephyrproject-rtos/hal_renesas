/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     core_g4mh.h
 * @brief    RH850 G4MH Core Definitions
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#ifndef __CORE_RH850_G4MH_H_GENERIC
 #define __CORE_RH850_G4MH_H_GENERIC

 #include <stdint.h>
 #include <stdbool.h>

 #ifdef __cplusplus
extern "C" {
 #endif

/***********************************************************************************************************************
 *                 RH850 definitions
 **********************************************************************************************************************/

/**
 * @defgroup RH850_glob_defs RH850 Global Defines
 * @brief RH850 Global Defines
 * @{
 */

/**
 * @defgroup RH850_G4MH RH850 G4MH
 * @ingroup RH850_glob_defs
 * @brief RH850 G4MH
 * @{
 */

/**
 * @ingroup    RH850_G4MH
 * @defgroup   RH850_G4MH_Device_Capability_Def  RH850 Device capabilitiy defines
 * @brief RH850 Device capabilitiy defines
 * @{
 */

 #include "rh850_version.h"

/* RH850 RH850_G4MH definitions */

 #define __RH850_G4MH    (1)           /*!< RH850 G4MH Core */

 #if defined(__CCRH__)

/** __FPU_USED indicates whether an FPU is used or not.
 */
  #if defined(__FPU)
   #define __FPU_USED    1U
  #else
   #define __FPU_USED    0U
  #endif

/** __FXU_USED indicates whether an FXU is used or not.
 */
  #if defined(__FXU)
   #define __FXU_USED    1U
  #else
   #define __FXU_USED    0U
  #endif
 #endif

 #include "rh850_compiler.h"           /* RH850 compiler specific defines */

 #ifdef __cplusplus
}
 #endif

#endif                                 /* __CORE_RH850_G4MH_H_GENERIC */

#ifndef __RH850_GENERIC

 #ifndef __CORE_RH850_G4MH_H_DEPENDANT
  #define __CORE_RH850_G4MH_H_DEPENDANT

  #ifdef __cplusplus
extern "C" {
  #endif

/* check device defines and use defaults */
  #if defined __CHECK_DEVICE_DEFINES
   #ifndef __RH850_G4MH_REV
    #define __RH850_G4MH_REV    0x07U  /*!< RH850 G4MH Core revision */
    #warning "__RH850_G4MH_REV not defined in device header file; using default!"
   #endif

   #ifndef __FPU_PRESENT
    #define __FPU_PRESENT       1U     /*!< FPU present or not */
    #warning "__FPU_PRESENT not defined in device header file; using default!"
   #endif

   #ifndef __FXU_PRESENT
    #define __FXU_PRESENT       0U     /*!< FXU present or not */
    #warning "__FXU_PRESENT not defined in device header file; using default!"
   #endif

   #ifndef __ICACHE_PRESENT
    #define __ICACHE_PRESENT    1U     /*!< ICACHE present or not */
    #warning "__ICACHE_PRESENT not defined in device header file; using default!"
   #endif

   #ifndef __IRQ_PRESENT
    #define __IRQ_PRESENT       1U     /*!< IRQ present or not */
    #warning "__IRQ_PRESENT not defined in device header file; using default!"
   #endif

   #ifndef __MPU_PRESENT
    #define __MPU_PRESENT       1U     /*!< MPU present or not */
    #warning "__MPU_PRESENT not defined in device header file; using default!"
   #endif

   #ifndef __PMU_PRESENT
    #define __PMU_PRESENT       1U     /*!< PMU present or not */
    #warning "__PMU_PRESENT not defined in device header file; using default!"
   #endif

   #ifndef __TSC_PRESENT
    #define __TSC_PRESENT       1U     /*!< TSC present or not */
    #warning "__TSC_PRESENT not defined in device header file; using default!"
   #endif
  #endif

/** @} */ /* end of RH850_Device_Capability_Def */

/* IO definitions (access restrictions to peripheral registers) */

/**
 * @ingroup    RH850_G4MH
 * @defgroup   RH850_G4MH_IO_Type_Qualifiers  RH850 IO Type Qualifiers
 * @brief RH850 IO Type Qualifiers
 * @{
 */

  #ifdef __cplusplus
   #define   __I       volatile        /*!< Defines 'read only' permissions */
  #else
   #define   __I       volatile const  /*!< Defines 'read only' permissions */
  #endif
  #define     __O      volatile        /*!< Defines 'write only' permissions */
  #define     __IO     volatile        /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
  #define     __IM     volatile const  /*!< Defines 'read only' structure member permissions */
  #define     __OM     volatile        /*!< Defines 'write only' structure member permissions */
  #define     __IOM    volatile        /*!< Defines 'read / write' structure member permissions */

/** @} */ /* end of RH850_IO_Type_Qualifiers */
/** @} */ /* end of RH850_G4MH */
/** @} */ /* end of RH850_glob_defs */

/***********************************************************************************************************************
 *                 Register Abstraction
 * Core Register contain:
 * - Core Register
 * - Core Debug Register
 * - Core MPU Register
 **********************************************************************************************************************/

/**
 * @defgroup RH850_G4MH_core_register Defines and Type Definitions
 * @ingroup  RH850_G4MH_Core_register
 *
 * @brief Type definitions and defines for RH850 G4MH processor based devices.
 */

/**
 * @ingroup    RH850_G4MH_core_register
 * @defgroup   RH850_G4MH_CORE  Status and Control Registers
 * @brief      Core Register type definitions. Basic System Register Definitions for RH850 G4
 *             This file provides symbolic names and documentation for system registers.
 * @note    Based on Table Basic System Registers (Renesas RH850 G4).
 * @{
 */

/***********************************************************************************************************************
 *                 EI/FE Exception Registers
 **********************************************************************************************************************/

  #define SR_EIPC         0            /*!< RegID: Status save register for EI level exception (EIPC) (SR0, 0) */
  #define SL_EIPC         0            /*!< SelID: Status save register for EI level exception (EIPC) (SR0, 0) */
  #define SR_EIPSW        1            /*!< RegID: Status save register for EI level exception PSW (EIPSW) (SR1, 0) */
  #define SL_EIPSW        0            /*!< SelID: Status save register for EI level exception PSW (EIPSW) (SR1, 0) */
  #define SR_FEPC         2            /*!< RegID: Status save register for FE level exception (FEPC) (SR2, 0) */
  #define SL_FEPC         0            /*!< SelID: Status save register for FE level exception (FEPC) (SR2, 0) */
  #define SR_FEPSW        3            /*!< RegID: Status save register for FE level exception PSW (FEPSW) (SR3, 0) */
  #define SL_FEPSW        0            /*!< SelID: Status save register for FE level exception PSW (FEPSW) (SR3, 0) */
  #define SR_PSW          5            /*!< RegID: Program Status Word (PSW) (SR5, 0) */
  #define SL_PSW          0            /*!< SelID: Program Status Word (PSW) (SR5, 0) */

/***********************************************************************************************************************
 *                 FPU Registers
 **********************************************************************************************************************/

  #define SR_FPSR         6            /*!< RegID: Floating Point Status Register (FPSR) (SR6, 0) */
  #define SL_FPSR         0            /*!< SelID: Floating Point Status Register (FPSR) (SR6, 0) */
  #define SR_FPEPC        7            /*!< RegID: Floating Point Exception PC (FPEPC) (SR7, 0) */
  #define SL_FPEPC        0            /*!< SelID: Floating Point Exception PC (FPEPC) (SR7, 0) */
  #define SR_FPST         8            /*!< RegID: Floating Point Status (FPST) (SR8, 0) */
  #define SL_FPST         0            /*!< SelID: Floating Point Status (FPST) (SR8, 0) */
  #define SR_FPCC         9            /*!< RegID: Floating Point Condition Code (FPCC) (SR9, 0) */
  #define SL_FPCC         0            /*!< SelID: Floating Point Condition Code (FPCC) (SR9, 0) */
  #define SR_FPCFG        10           /*!< RegID: Floating Point Config (FPCFG) (SR10, 0) */
  #define SL_FPCFG        0            /*!< SelID: Floating Point Config (FPCFG) (SR10, 0) */

/***********************************************************************************************************************
 *                 Exception Cause Registers
 **********************************************************************************************************************/

  #define SR_EIIC         13           /*!< RegID: EI level exception cause (EIIC) (SR13, 0) */
  #define SL_EIIC         0            /*!< SelID: EI level exception cause (EIIC) (SR13, 0) */
  #define SR_FEIC         14           /*!< RegID: FE level exception cause (FEIC) (SR14, 0) */
  #define SL_FEIC         0            /*!< SelID: FE level exception cause (FEIC) (SR14, 0) */

/***********************************************************************************************************************
 *                 CALLT Registers
 **********************************************************************************************************************/

  #define SR_CTPC         16           /*!< RegID: CALLT execution status save register (CTPC) (SR16, 0) */
  #define SL_CTPC         0            /*!< SelID: CALLT execution status save register (CTPC) (SR16, 0) */
  #define SR_CTPSW        17           /*!< RegID: CALLT execution status save register (CTPSW) (SR17, 0) */
  #define SL_CTPSW        0            /*!< SelID: CALLT execution status save register (CTPSW) (SR17, 0) */
  #define SR_CTBP         20           /*!< RegID: CALLT base pointer (CTBP) (SR20, 0) */
  #define SL_CTBP         0            /*!< SelID: CALLT base pointer (CTBP) (SR20, 0) */

/***********************************************************************************************************************
 *                 SNOOZE Control
 **********************************************************************************************************************/

  #define SR_SNZCFG       21           /*!< RegID: SNOOZE control register (SNZCFG) (SR21, 0) */
  #define SL_SNZCFG       0            /*!< SelID: SNOOZE control register (SNZCFG) (SR21, 0) */

/***********************************************************************************************************************
 *                 Exception Registers
 **********************************************************************************************************************/
  #define SR_EIWR         28           /*!< RegID: EI level exception working register (SR28, 0) */
  #define SL_EIWR         0            /*!< SelID: EI level exception working register (SR28, 0) */
  #define SR_FEWR         29           /*!< RegID: FE level exception working register (SR29, 0) */
  #define SL_FEWR         0            /*!< SelID: FE level exception working register (SR29, 0) */

/***********************************************************************************************************************
 *                 System Protection Registers
 **********************************************************************************************************************/

  #define SR_SPID         0            /*!< RegID: System protection identifier (SR0, 1) */
  #define SL_SPID         1            /*!< SelID: System protection identifier (SR0, 1) */
  #define SR_SPIDLIST     1            /*!< RegID: List of system protection identifiers (SR1, 1) */
  #define SL_SPIDLIST     1            /*!< SelID: List of system protection identifiers (SR1, 1) */
  #define SR_RBASE        2            /*!< RegID: Reset vector base address (SR2, 1) */
  #define SL_RBASE        1            /*!< SelID: Reset vector base address (SR2, 1) */
  #define SR_EBASE        3            /*!< RegID: Exception handler vector address (SR3, 1) */
  #define SL_EBASE        1            /*!< SelID: Exception handler vector address (SR3, 1) */
  #define SR_INTBP        4            /*!< RegID: Base address of interrupt handler table (SR4, 1) */
  #define SL_INTBP        1            /*!< SelID: Base address of interrupt handler table (SR4, 1) */
  #define SR_MCTL         5            /*!< RegID: CPU control (SR5, 1) */
  #define SL_MCTL         1            /*!< SelID: CPU control (SR5, 1) */
  #define SR_PID          6            /*!< RegID: Processor ID (SR6, 1) */
  #define SL_PID          1            /*!< SelID: Processor ID (SR6, 1) */
  #define SR_SVLOCK       8            /*!< RegID: Supervisor lock (SR8, 1) */
  #define SL_SVLOCK       1            /*!< SelID: Supervisor lock (SR8, 1) */
  #define SR_SCCFG        11           /*!< RegID: SYSCALL operation setting (SR11, 1) */
  #define SL_SCCFG        1            /*!< SelID: SYSCALL operation setting (SR11, 1) */
  #define SR_SCBP         12           /*!< RegID: SYSCALL base pointer (SR12, 1) */
  #define SL_SCBP         1            /*!< SelID: SYSCALL base pointer (SR12, 1) */

/***********************************************************************************************************************
 *                 Processor Element Registers
 **********************************************************************************************************************/
  #define SR_PEID         0            /*!< RegID: Processor element identifier (SR0, 2) */
  #define SL_PEID         2            /*!< SelID: Processor element identifier (SR0, 2) */
  #define SR_BMID         1            /*!< RegID: Bus master identifier (SR1, 2) */
  #define SL_BMID         2            /*!< SelID: Bus master identifier (SR1, 2) */
  #define SR_MEA          6            /*!< RegID: Memory error address (SR6, 2) */
  #define SL_MEA          2            /*!< SelID: Memory error address (SR6, 2) */
  #define SR_MEI          8            /*!< RegID: Memory error information (SR8, 2) */
  #define SL_MEI          2            /*!< SelID: Memory error information (SR8, 2) */
  #define SR_RBCR0        15           /*!< RegID: Register bank control 0 (SR15, 2) */
  #define SL_RBCR0        2            /*!< SelID: Register bank control 0 (SR15, 2) */
  #define SR_RBCR1        16           /*!< RegID: Register bank control 1 (SR16, 2) */
  #define SL_RBCR1        2            /*!< SelID: Register bank control 1 (SR16, 2) */
  #define SR_RBNR         17           /*!< RegID: Register bank number (SR17, 2) */
  #define SL_RBNR         2            /*!< SelID: Register bank number (SR17, 2) */
  #define SR_RBIP         18           /*!< RegID: Register bank initial pointer (SR18, 2) */
  #define SL_RBIP         2            /*!< SelID: Register bank initial pointer (SR18, 2) */

/***********************************************************************************************************************
 *                 Interrupt Registers
 **********************************************************************************************************************/
  #define SR_ISPR         10           /*!< RegID: Priority of interrupt being serviced (SR10, 2) */
  #define SL_ISPR         2            /*!< SelID: Priority of interrupt being serviced (SR10, 2) */
  #define SR_IMSR         11           /*!< RegID: Interrupt mask status (SR11, 2) */
  #define SL_IMSR         2            /*!< SelID: Interrupt mask status (SR11, 2) */
  #define SR_ICSR         12           /*!< RegID: Interrupt control status (SR12, 2) */
  #define SL_ICSR         2            /*!< SelID: Interrupt control status (SR12, 2) */
  #define SR_INTCFG       13           /*!< RegID: Interrupt function setting (SR13, 2) */
  #define SL_INTCFG       2            /*!< SelID: Interrupt function setting (SR13, 2) */
  #define SR_PLMR         14           /*!< RegID: Interrupt priority masking (SR14, 2) */
  #define SL_PLMR         2            /*!< SelID: Interrupt priority masking (SR14, 2) */

/***********************************************************************************************************************
 *                 FXU Registers
 **********************************************************************************************************************/
  #define SR_FXSR         6            /*!< RegID: Extended floating-point operation configuration/status (SR6, 10) */
  #define SL_FXSR         10           /*!< SelID: Extended floating-point operation configuration/status (SR6, 10) */
  #define SR_FXST         8            /*!< RegID: Extended floating-point operation status (SR8, 10) */
  #define SL_FXST         10           /*!< SelID: Extended floating-point operation status (SR8, 10) */
  #define SR_FXINFO       9            /*!< RegID: FXU configuration information (SR9, 10) */
  #define SL_FXINFO       10           /*!< SelID: FXU configuration information (SR9, 10) */
  #define SR_FXCFG        10           /*!< RegID: Extended floating-point operation configuration (SR10, 10) */
  #define SL_FXCFG        10           /*!< SelID: Extended floating-point operation configuration (SR10, 10) */
  #define SR_FXXC         12           /*!< RegID: XC (cause) bits for each operation way (SR12, 10) */
  #define SL_FXXC         10           /*!< SelID: XC (cause) bits for each operation way (SR12, 10) */
  #define SR_FXXP         13           /*!< RegID: XP (preservation) bits for each operation way (SR13, 10) */
  #define SL_FXXP         10           /*!< SelID: XP (preservation) bits for each operation way (SR13, 10) */

/***********************************************************************************************************************
 *                 MPU Registers
 **********************************************************************************************************************/
  #define SR_MPM          0            /*!< RegID: Memory protection operation mode setting (SR0, 5) */
  #define SL_MPM          5            /*!< SelID: Memory protection operation mode setting (SR0, 5) */
  #define SR_MPCFG        2            /*!< RegID: MPU configuration (SR2, 5) */
  #define SL_MPCFG        5            /*!< SelID: MPU configuration (SR2, 5) */
  #define SR_MCA          8            /*!< RegID: Memory protection setting check address (SR8, 5) */
  #define SL_MCA          5            /*!< SelID: Memory protection setting check address (SR8, 5) */
  #define SR_MCS          9            /*!< RegID: Memory protection setting check size (SR9, 5) */
  #define SL_MCS          5            /*!< SelID: Memory protection setting check size (SR9, 5) */
  #define SR_MCC          10           /*!< RegID: Memory protection setting check command (SR10, 5) */
  #define SL_MCC          5            /*!< SelID: Memory protection setting check command (SR10, 5) */
  #define SR_MCR          11           /*!< RegID: Memory protection setting check result (SR11, 5) */
  #define SL_MCR          5            /*!< SelID: Memory protection setting check result (SR11, 5) */
  #define SR_MCI          12           /*!< RegID: Memory protection setting check SPID (SR12, 5) */
  #define SL_MCI          5            /*!< SelID: Memory protection setting check SPID (SR12, 5) */
  #define SR_MPIDX        16           /*!< RegID: Index of memory protection setting registers to be accessed (SR16, 5) */
  #define SL_MPIDX        5            /*!< SelID: Index of memory protection setting registers to be accessed (SR16, 5) */
  #define SR_MPBK         17           /*!< RegID: MPU Bank Setting (SR17, 5) */
  #define SL_MPBK         5            /*!< SelID: MPU Bank Setting (SR17, 5) */
  #define SR_MPLA         20           /*!< RegID: Protection area minimum address (SR20, 5) */
  #define SL_MPLA         5            /*!< SelID: Protection area minimum address (SR20, 5) */
  #define SR_MPUA         21           /*!< RegID: Protection area maximum address (SR21, 5) */
  #define SL_MPUA         5            /*!< SelID: Protection area maximum address (SR21, 5) */
  #define SR_MPAT         22           /*!< RegID: Protection area attribute (SR22, 5) */
  #define SL_MPAT         5            /*!< SelID: Protection area attribute (SR22, 5) */
  #define SR_MPID0        24           /*!< RegID: SPID which can access protection area (SR24, 5) */
  #define SL_MPID0        5            /*!< SelID: SPID which can access protection area (SR24, 5) */
  #define SR_MPID1        25           /*!< RegID: SPID which can access protection area (SR25, 5) */
  #define SL_MPID1        5            /*!< SelID: SPID which can access protection area (SR25, 5) */
  #define SR_MPID2        26           /*!< RegID: SPID which can access protection area (SR26, 5) */
  #define SL_MPID2        5            /*!< SelID: SPID which can access protection area (SR26, 5) */
  #define SR_MPID3        27           /*!< RegID: SPID which can access protection area (SR27, 5) */
  #define SL_MPID3        5            /*!< SelID: SPID which can access protection area (SR27, 5) */
  #define SR_MPID4        28           /*!< RegID: SPID which can access protection area (SR28, 5) */
  #define SL_MPID4        5            /*!< SelID: SPID which can access protection area (SR28, 5) */
  #define SR_MPID5        29           /*!< RegID: SPID which can access protection area (SR29, 5) */
  #define SL_MPID5        5            /*!< SelID: SPID which can access protection area (SR29, 5) */
  #define SR_MPID6        30           /*!< RegID: SPID which can access protection area (SR30, 5) */
  #define SL_MPID6        5            /*!< SelID: SPID which can access protection area (SR30, 5) */
  #define SR_MPID7        31           /*!< RegID: SPID which can access protection area (SR31, 5) */
  #define SL_MPID7        5            /*!< SelID: SPID which can access protection area (SR31, 5) */

/***********************************************************************************************************************
 *                 ICACHE Registers
 **********************************************************************************************************************/
  #define SR_ICTAGL       16           /*!< RegID: Instruction cache tag Lo access (SR16, 4) */
  #define SL_ICTAGL       4            /*!< SelID: Instruction cache tag Lo access (SR16, 4) */
  #define SR_ICTAGH       17           /*!< RegID: Instruction cache tag Hi access (SR17, 4) */
  #define SL_ICTAGH       4            /*!< SelID: Instruction cache tag Hi access (SR17, 4) */
  #define SR_ICDATL       18           /*!< RegID: Instruction cache data Lo access (SR18, 4) */
  #define SL_ICDATL       4            /*!< SelID: Instruction cache data Lo access (SR18, 4) */
  #define SR_ICDATH       19           /*!< RegID: Instruction cache data Hi access (SR19, 4) */
  #define SL_ICDATH       4            /*!< SelID: Instruction cache data Hi access (SR19, 4) */
  #define SR_ICCTRL       24           /*!< RegID: Instruction cache control (SR24, 4) */
  #define SL_ICCTRL       4            /*!< SelID: Instruction cache control (SR24, 4) */
  #define SR_ICCFG        26           /*!< RegID: Instruction cache configuration (SR26, 4) */
  #define SL_ICCFG        4            /*!< SelID: Instruction cache configuration (SR26, 4) */
  #define SR_ICERR        28           /*!< RegID: Instruction cache error (SR28, 4) */
  #define SL_ICERR        4            /*!< SelID: Instruction cache error (SR28, 4) */

/***********************************************************************************************************************
 *                 Count Registers
 **********************************************************************************************************************/
  #define SR_TSCOUNTL     0            /*!< RegID: Timestamp count L register (SR0, 11) */
  #define SL_TSCOUNTL     11           /*!< SelID: Timestamp count L register (SR0, 11) */
  #define SR_TSCOUNTH     1            /*!< RegID: Timestamp count H register (SR1, 11) */
  #define SL_TSCOUNTH     11           /*!< SelID: Timestamp count H register (SR1, 11) */
  #define SR_TSCTRL       2            /*!< RegID: Timestamp count control register (SR2, 11) */
  #define SL_TSCTRL       11           /*!< SelID: Timestamp count control register (SR2, 11) */
  #define SR_PMUMCTRL     8            /*!< RegID: Performance counter User mode control register (SR8, 11) */
  #define SL_PMUMCTRL     11           /*!< SelID: Performance counter User mode control register (SR8, 11) */
  #define SR_PMCTRL0      0            /*!< RegID: Performance count control 0 register (SR0, 14) */
  #define SL_PMCTRL0      14           /*!< SelID: Performance count control 0 register (SR0, 14) */
  #define SR_PMCTRL1      1            /*!< RegID: Performance count control 1 register (SR1, 14) */
  #define SL_PMCTRL1      14           /*!< SelID: Performance count control 1 register (SR1, 14) */
  #define SR_PMCTRL2      2            /*!< RegID: Performance count control 2 register (SR2, 14) */
  #define SL_PMCTRL2      14           /*!< SelID: Performance count control 2 register (SR2, 14) */
  #define SR_PMCTRL3      3            /*!< RegID: Performance count control 3 register (SR3, 14) */
  #define SL_PMCTRL3      14           /*!< SelID: Performance count control 3 register (SR3, 14) */
  #define SR_PMCTRL4      4            /*!< RegID: Performance count control 4 register (SR4, 14) */
  #define SL_PMCTRL4      14           /*!< SelID: Performance count control 4 register (SR4, 14) */
  #define SR_PMCTRL5      5            /*!< RegID: Performance count control 5 register (SR5, 14) */
  #define SL_PMCTRL5      14           /*!< SelID: Performance count control 5 register (SR5, 14) */
  #define SR_PMCTRL6      6            /*!< RegID: Performance count control 6 register (SR6, 14) */
  #define SL_PMCTRL6      14           /*!< SelID: Performance count control 6 register (SR6, 14) */
  #define SR_PMCTRL7      7            /*!< RegID: Performance count control 7 register (SR7, 14) */
  #define SL_PMCTRL7      14           /*!< SelID: Performance count control 7 register (SR7, 14) */
  #define SR_PMCOUNT0     16           /*!< RegID: Performance count 0 register (SR16, 14) */
  #define SL_PMCOUNT0     14           /*!< SelID: Performance count 0 register (SR16, 14) */
  #define SR_PMCOUNT1     17           /*!< RegID: Performance count 1 register (SR17, 14) */
  #define SL_PMCOUNT1     14           /*!< SelID: Performance count 1 register (SR17, 14) */
  #define SR_PMCOUNT2     18           /*!< RegID: Performance count 2 register (SR18, 14) */
  #define SL_PMCOUNT2     14           /*!< SelID: Performance count 2 register (SR18, 14) */
  #define SR_PMCOUNT3     19           /*!< RegID: Performance count 3 register (SR19, 14) */
  #define SL_PMCOUNT3     14           /*!< SelID: Performance count 3 register (SR19, 14) */
  #define SR_PMCOUNT4     20           /*!< RegID: Performance count 4 register (SR20, 14) */
  #define SL_PMCOUNT4     14           /*!< SelID: Performance count 4 register (SR20, 14) */
  #define SR_PMCOUNT5     21           /*!< RegID: Performance count 5 register (SR21, 14) */
  #define SL_PMCOUNT5     14           /*!< SelID: Performance count 5 register (SR21, 14) */
  #define SR_PMCOUNT6     22           /*!< RegID: Performance count 6 register (SR22, 14) */
  #define SL_PMCOUNT6     14           /*!< SelID: Performance count 6 register (SR22, 14) */
  #define SR_PMCOUNT7     23           /*!< RegID: Performance count 7 register (SR23, 14) */
  #define SL_PMCOUNT7     14           /*!< SelID: Performance count 7 register (SR23, 14) */
  #define SR_PMSUBCND0    0            /*!< RegID: Performance count subcondition 0 register (SR0, 15) */
  #define SL_PMSUBCND0    15           /*!< SelID: Performance count subcondition 0 register (SR0, 15) */
  #define SR_PMSUBCND1    1            /*!< RegID: Performance count subcondition 1 register (SR1, 15) */
  #define SL_PMSUBCND1    15           /*!< SelID: Performance count subcondition 1 register (SR1, 15) */
  #define SR_PMSUBCND2    2            /*!< RegID: Performance count subcondition 2 register (SR2, 15) */
  #define SL_PMSUBCND2    15           /*!< SelID: Performance count subcondition 2 register (SR2, 15) */
  #define SR_PMSUBCND3    3            /*!< RegID: Performance count subcondition 3 register (SR3, 15) */
  #define SL_PMSUBCND3    15           /*!< SelID: Performance count subcondition 3 register (SR3, 15) */
  #define SR_PMSUBCND4    4            /*!< RegID: Performance count subcondition 4 register (SR4, 15) */
  #define SL_PMSUBCND4    15           /*!< SelID: Performance count subcondition 4 register (SR4, 15) */
  #define SR_PMSUBCND5    5            /*!< RegID: Performance count subcondition 5 register (SR5, 15) */
  #define SL_PMSUBCND5    15           /*!< SelID: Performance count subcondition 5 register (SR5, 15) */
  #define SR_PMSUBCND6    6            /*!< RegID: Performance count subcondition 6 register (SR6, 15) */
  #define SL_PMSUBCND6    15           /*!< SelID: Performance count subcondition 6 register (SR6, 15) */
  #define SR_PMSUBCND7    7            /*!< RegID: Performance count subcondition 7 register (SR7, 15) */
  #define SL_PMSUBCND7    15           /*!< SelID: Performance count subcondition 7 register (SR7, 15) */

/***********************************************************************************************************************
 *                 Hardware Registers
 **********************************************************************************************************************/
  #define SR_LSTEST0      0            /*!< RegID: Lock-step function self-diagnosis register 0 (SR0, 12) */
  #define SL_LSTEST0      12           /*!< SelID: Lock-step function self-diagnosis register 0 (SR0, 12) */
  #define SR_LSTEST1      1            /*!< RegID: Lock-step function self-diagnosis register 1 (SR1, 12) */
  #define SL_LSTEST1      12           /*!< SelID: Lock-step function self-diagnosis register 1 (SR1, 12) */
  #define SR_LSCFG        2            /*!< RegID: Lock-step function configuration (SR2, 12) */
  #define SL_LSCFG        12           /*!< SelID: Lock-step function configuration (SR2, 12) */
  #define SR_IFCR         5            /*!< RegID: Instruction fetch control register (SR5, 12) */
  #define SL_IFCR         12           /*!< SelID: Instruction fetch control register (SR5, 12) */
  #define SR_BRPCTRL0     8            /*!< RegID: Branch prediction function control register (SR8, 12) */
  #define SL_BRPCTRL0     12           /*!< SelID: Branch prediction function control register (SR8, 12) */
  #define SR_L1RCFG       12           /*!< RegID: L1RAM configuration (SR12, 13) */
  #define SL_L1RCFG       13           /*!< SelID: L1RAM configuration (SR12, 13) */
  #define SR_RDBCR        24           /*!< RegID: ROM data buffer control register (SR24, 13) */
  #define SL_RDBCR        13           /*!< SelID: ROM data buffer control register (SR24, 13) */
  #define SR_HVCFG        16           /*!< RegID: Setting virtualization support function (SR16, 1) */
  #define SL_HVCFG        1            /*!< SelID: Setting virtualization support function (SR16, 1) */

/*@} end of group RH850_CORE */

/**
 * @ingroup    RH850_G4MH_core_register
 * @defgroup   RH850_G4MH_core_bitfield     Core register bit field macros
 * @brief      Macros for use with bit field definitions (xxx_Pos, xxx_Msk).
 * @{
 */

/**
 * @brief   Mask and shift a bit field value for use in a register bit range.
 * @param[in] field  Name of the register bit field.
 * @param[in] value  Value of the bit field. This parameter is interpreted as an uint32_t type.
 * @return           Masked and shifted value.
 */
  #define _VAL2FLD(field, value)    (((uint32_t) (value) << field ## _Pos) & field ## _Msk)

/**
 * @brief     Mask and shift a register value to extract a bit field value.
 * @param[in] field  Name of the register bit field.
 * @param[in] value  Value of register. This parameter is interpreted as an uint32_t type.
 * @return           Masked and shifted bit field value.
 */
  #define _FLD2VAL(field, value)    (((uint32_t) (value) & field ## _Msk) >> field ## _Pos)

/*@} end of group RH850_core_bitfield */

/***********************************************************************************************************************
 *                 RH850 definitions
 **********************************************************************************************************************/

/**
 * @defgroup  RH850_Core_register RH850-Core Register
 * @brief RH850-Core Register
 * @{
 */

/**
 * @defgroup  RH850_G4MH_Core_register RH850 G4MH Core Register
 * @brief RH850 G4MH Core Register
 * @ingroup   RH850_Core_register
 * @{
 */

/**
 * @ingroup  RH850_G4MH_Core_register
 * @defgroup RH850_G4MH_SYS     Basic System Register (SYS)
 * @brief    Type definitions for the basic system register (SYS)
 * @{
 */

/**
 * @brief  Structure type to access the basic system register (SYS).
 */

typedef union
{
    __IOM uint32_t EIPC;               /*!< (@ 0x00000000) Status Save Register when Acknowledging EI Level
                                        *                  Exception                                                  */

    struct
    {
        __IOM uint32_t EIPC : 32;      /*!< [31..0] These bits indicate the PC saved when an EI level exception
                                        *    isacknowledged.EIPC0:This bit indicates the PC saved when
                                        *    an EI level exception is acknowledged.Always set this bit
                                        *    to 0. Even if it is set to 1, the value transferred to
                                        *    the PCwhen the EIRET instruction is executed is 0.                       */
    } EIPC_b;
} RH850_SYS_EIPC_Type;

typedef union
{
    __IOM uint32_t EIPSW;              /*!< (@ 0x00000000) Status Save Register when Acknowledging EI Level
                                        *                  Exception                                                  */

    struct
    {
        __IOM uint32_t Z : 1;          /*!< [0..0] This bit stores the PSW.Z bit setting when an EI level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t S : 1;          /*!< [1..1] This bit stores the PSW.S bit setting when an EI level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t OV : 1;         /*!< [2..2] This bit stores the PSW.OV bit setting when an EI level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t CY : 1;         /*!< [3..3] This bit stores the PSW.CY bit setting when an EI level
                                        *    exception isacknowledged.                                                */
        __IOM uint32_t SAT : 1;        /*!< [4..4] This bit stores the PSW.SAT bit setting when an EI level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t ID : 1;         /*!< [5..5] This bit stores the PSW.ID bit setting when an EI level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t EP : 1;         /*!< [6..6] This bit stores the PSW.EP bit setting when an EI level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t NP : 1;         /*!< [7..7] This bit stores the PSW.NP bit setting when an EI level
                                        *    exception isacknowledged                                                 */
        uint32_t           : 7;
        __IOM uint32_t EBV : 1;        /*!< [15..15] This bit stores the PSW.EBV bit setting when an EI
                                        *    level exception isacknowledged                                           */
        __IOM uint32_t CU0 : 1;        /*!< [16..16] These bits store the PSW.CU2-0 field setting when an
                                        *    EI level exception isacknowledged                                        */
        __IOM uint32_t CU1 : 1;        /*!< [17..17] These bits store the PSW.CU2-0 field setting when an
                                        *    EI level exception isacknowledged                                        */
        __IOM uint32_t CU2 : 1;        /*!< [18..18] These bits store the PSW.CU2-0 field setting when an
                                        *    EI level exception isacknowledged                                        */
        uint32_t              : 1;
        __IOM uint32_t EIMASK : 6;     /*!< [25..20] This bit stores the PSW.EIMASK bit setting when an
                                        *    EI level exception isacknowledged                                        */
        uint32_t          : 4;
        __IOM uint32_t UM : 1;         /*!< [30..30] This bit stores the PSW.UM bit setting when an EI level
                                        *    exception isacknowledged.                                                */
        uint32_t : 1;
    } EIPSW_b;
} RH850_SYS_EIPSW_Type;

typedef union
{
    __IOM uint32_t FEPC;               /*!< (@ 0x00000000) Status Save Register when Acknowledging FE Level
                                        *                  Exception                                                  */

    struct
    {
        __IOM uint32_t FEPC : 32;      /*!< [31..0] This bit indicates the PC saved when an FE level exception
                                        *    isacknowledged.FEPC0: Always set this bit to 0. Even if
                                        *    it is set to 1, the value transferred to the PCwhen the
                                        *    FERET instruction is executed is 0.                                      */
    } FEPC_b;
} RH850_SYS_FEPC_Type;

typedef union
{
    __IOM uint32_t FEPSW;              /*!< (@ 0x00000000) Status Save Register when Acknowledging FE Level
                                        *                  Exception                                                  */

    struct
    {
        __IOM uint32_t Z : 1;          /*!< [0..0] This bit stores the PSW.Z bit setting when an FE level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t S : 1;          /*!< [1..1] This bit stores the PSW.S bit setting when an FE level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t OV : 1;         /*!< [2..2] This bit stores the PSW.OV bit setting when an FE level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t CY : 1;         /*!< [3..3] This bit stores the PSW.CY bit setting when an FE level
                                        *    exception isacknowledged.                                                */
        __IOM uint32_t SAT : 1;        /*!< [4..4] This bit stores the PSW.SAT bit setting when an FE level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t ID : 1;         /*!< [5..5] This bit stores the PSW.ID bit setting when an FE level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t EP : 1;         /*!< [6..6] This bit stores the PSW.EP bit setting when an FE level
                                        *    exception isacknowledged                                                 */
        __IOM uint32_t NP : 1;         /*!< [7..7] This bit stores the PSW.NP bit setting when an FE level
                                        *    exception isacknowledged                                                 */
        uint32_t           : 7;
        __IOM uint32_t EBV : 1;        /*!< [15..15] This bit stores the PSW.EBV bit setting when an FE
                                        *    level exception isacknowledged                                           */
        __IOM uint32_t CU0 : 1;        /*!< [16..16] These bits store the PSW.CU2-0 field setting when an
                                        *    FE level exception isacknowledged                                        */
        __IOM uint32_t CU1 : 1;        /*!< [17..17] These bits store the PSW.CU2-0 field setting when an
                                        *    FE level exception isacknowledged                                        */
        __IOM uint32_t CU2 : 1;        /*!< [18..18] These bits store the PSW.CU2-0 field setting when an
                                        *    FE level exception isacknowledged                                        */
        uint32_t              : 1;
        __IOM uint32_t EIMASK : 6;     /*!< [25..20] This bit stores the PSW.EIMASK bit setting when an
                                        *    FE level exception isacknowledged                                        */
        uint32_t          : 4;
        __IOM uint32_t UM : 1;         /*!< [30..30] This bit stores the PSW.UM bit setting when an FE level
                                        *    exception isacknowledged.                                                */
        uint32_t : 1;
    } FEPSW_b;
} RH850_SYS_FEPSW_Type;

typedef union
{
    __IOM uint32_t PSW;                /*!< (@ 0x00000000) Program Status Word                                        */

    struct
    {
        __IOM uint32_t Z : 1;          /*!< [0..0] This bit indicates whether or not the result of an operation
                                        *    is 0.0: Result of operation is not 0.1: Result of operation
                                        *    is 0.                                                                    */
        __IOM uint32_t S : 1;          /*!< [1..1] This bit indicates whether or not the result of an operation
                                        *    is negative.0: Result of operation is positive or 0.1:
                                        *    Result of operation is negative                                          */
        __IOM uint32_t OV : 1;         /*!< [2..2] This bit indicates whether or not an overflow has occurred
                                        *    during anoperation.0: Overflow has not occurred.1: Overflow
                                        *    has occurred.                                                            */
        __IOM uint32_t CY : 1;         /*!< [3..3] This bit indicates whether a carry or borrow has occurred
                                        *    in the operationresult.0: Carry and borrow have not occurred.1:
                                        *    Carry or borrow has occurred.                                            */
        __IOM uint32_t SAT : 1;        /*!< [4..4] This bit indicates that a saturation arithmetic operation
                                        *    instruction resulted inoverflow and saturation processing
                                        *    is applied to the result. This is acumulative flag, that
                                        *    is, it is set (1) once a saturation occurs and not cleared(0)
                                        *    by subsequent instructions with unsaturated results. This
                                        *    bit is cleared bythe LDSR instruction. Note that execution
                                        *    of an arithmetic operationinstruction neither set nor clear
                                        *    this flag.0: The result was not saturated1: The result
                                        *    was saturated                                                            */
        __IOM uint32_t ID : 1;         /*!< [5..5] This bit disables the acknowledgement of EI level exception.
                                        *    When an EIlevel or FE level exception is acknowledged,
                                        *    this bit is set to 1 to disable theacknowledgement of EI
                                        *    level exception. As for the exceptions which the IDbit
                                        *    disables the acknowledgment, see Table 3.103, Exception
                                        *    Cause ListThis bit is also used to disable EI level exceptions
                                        *    from being acknowledgedas a critical section while an ordinary
                                        *    program or interrupt is being serviced.It is set to 1 when
                                        *    the DI instruction is executed                                           */
        __IOM uint32_t EP : 1;         /*!< [6..6] This bit indicates that an exception other than an interrupt
                                        *    is being serviced.It is set to 1 when the corresponding
                                        *    exception occurs. This bit does notaffect acknowledging
                                        *    an exception request even when it is set to 1.0: An exception
                                        *    other than an interrupt is not being serviced.1: An exception
                                        *    other than an interrupt is being serviced                                */
        __IOM uint32_t NP : 1;         /*!< [7..7] This bit disables the acknowledgement of FE level exception.
                                        *    When an FElevel exception is acknowledged, this bit is
                                        *    set to 1 to disable theacknowledgement of EI level and
                                        *    FE level exceptions. As for the exceptionswhich the NP
                                        *    bit disables the acknowledgment, see Table 3.103, ExceptionCause
                                        *    List.0: The acknowledgement of FE level exception is enabled.1:
                                        *    The acknowledgement of FE level exception is disabled.                   */
        uint32_t           : 7;
        __IOM uint32_t EBV : 1;        /*!< [15..15] This bit indicates the reset vector and exception vector
                                        *    operation. SeeSection 3.2.3.2(16), RBASE — Reset Vector
                                        *    Base Address and Section3.2.3.2(17), EBASE — Exception
                                        *    Handler Vector Address                                                   */
        __IOM uint32_t CU0 : 1;        /*!< [16..16] These bits indicate the coprocessor use permissions.
                                        *    When the bitcorresponding to the coprocessor is 0, a coprocessor
                                        *    unusable exceptionoccurs if an instruction for the coprocessor
                                        *    is executed or a coprocessorresource (system register)
                                        *    is accessed.Bit 18 (CU2): Fixed to 0*2.Bit 17 (CU1): FXUBit
                                        *    16 (CU0): FPUCU2 to CU0 are fixed to 0 in the devices that
                                        *    do not have correspondingcoprocessors.                                   */
        __IOM uint32_t CU1 : 1;        /*!< [17..17] These bits indicate the coprocessor use permissions.
                                        *    When the bitcorresponding to the coprocessor is 0, a coprocessor
                                        *    unusable exceptionoccurs if an instruction for the coprocessor
                                        *    is executed or a coprocessorresource (system register)
                                        *    is accessed.Bit 18 (CU2): Fixed to 0*2.Bit 17 (CU1): FXUBit
                                        *    16 (CU0): FPUCU2 to CU0 are fixed to 0 in the devices that
                                        *    do not have correspondingcoprocessors.                                   */
        __IOM uint32_t CU2 : 1;        /*!< [18..18] These bits indicate the coprocessor use permissions.
                                        *    When the bitcorresponding to the coprocessor is 0, a coprocessor
                                        *    unusable exceptionoccurs if an instruction for the coprocessor
                                        *    is executed or a coprocessorresource (system register)
                                        *    is accessed.Bit 18 (CU2): Fixed to 0*2.Bit 17 (CU1): FXUBit
                                        *    16 (CU0): FPUCU2 to CU0 are fixed to 0 in the devices that
                                        *    do not have correspondingcoprocessors.                                   */
        uint32_t              : 1;
        __IOM uint32_t EIMASK : 6;     /*!< [25..20] This field indicates the interrupt priority boundary
                                        *    between enabling anddisabling an acknowlegement of an interrupt
                                        *    (EIINTn). For an interrupt(EIINTn) with higher priority
                                        *    than the value set in this field, theacknowlegement is
                                        *    enabled. For an interrupt (EIINTn) with priority less thanor
                                        *    equal to the value set in this field, the acknowlegement
                                        *    is disabled.0: All priorities are not acceptable.1: Acceptable
                                        *    priority is 02: Acceptable priority is 0 to 1...62: Acceptable
                                        *    priority is 0 to 61                                                      */
        uint32_t          : 4;
        __IOM uint32_t UM : 1;         /*!< [30..30] This bit indicates that the CPU is in user mode (in
                                        *    UM mode).0: Supervisor mode1: User mode                                  */
        uint32_t : 1;
    } PSW_b;
} RH850_SYS_PSW_Type;

typedef union
{
    __IOM uint32_t EIIC;               /*!< (@ 0x00000000) EI Level Exception Cause                                   */

    struct
    {
        __IOM uint32_t EIIC : 32;      /*!< [31..0] These bits store the exception cause code when an EI
                                        *    level exceptionoccurs. The EIIC15-0 field stores the exception
                                        *    cause codes shown in Table3.103, Exception Cause List.
                                        *    The EIIC31-16 field stores detailed exceptioncause codes
                                        *    defined individually for each exception. If there is no
                                        *    particulardefinition, these bits are set to 0.                           */
    } EIIC_b;
} RH850_SYS_EIIC_Type;

typedef union
{
    __IOM uint32_t FEIC;               /*!< (@ 0x00000000) FE Level Exception Cause                                   */

    struct
    {
        __IOM uint32_t FEIC : 32;      /*!< [31..0] These bits store the exception cause code when an FE
                                        *    level exceptionoccurs. The FEIC15-0 field stores the exception
                                        *    cause codes shown inTable 3.103, Exception Cause List.
                                        *    The FEIC31-16 field stores detailedexception cause codes
                                        *    defined individually for each exception. If there is noparticular
                                        *    definition, these bits are set to 0.                                     */
    } FEIC_b;
} RH850_SYS_FEIC_Type;

typedef union
{
    __IOM uint32_t CTPC;               /*!< (@ 0x00000000) Status Save Register when Executing CALLT                  */

    struct
    {
        __IOM uint32_t CTPC : 32;      /*!< [31..0] This bit indicates the PC of the instruction after the
                                        *    CALLT instruction.Always set this bit to 0. Even if it
                                        *    is set to 1, the value transferred to the PCwhen the CTRET
                                        *    instruction is executed is 0.                                            */
    } CTPC_b;
} RH850_SYS_CTPC_Type;

typedef union
{
    __IOM uint32_t CTPSW;              /*!< (@ 0x00000000) Status Save Register when Executing CALLT                  */

    struct
    {
        __IOM uint32_t Z : 1;          /*!< [0..0] This bit indicates whether or not the result of an operation
                                        *    is 0.0: Result of operation is not 0.1: Result of operation
                                        *    is 0.                                                                    */
        __IOM uint32_t S : 1;          /*!< [1..1] This bit indicates whether or not the result of an operation
                                        *    is negative.0: Result of operation is positive or 0.1:
                                        *    Result of operation is negative                                          */
        __IOM uint32_t OV : 1;         /*!< [2..2] This bit indicates whether or not an overflow has occurred
                                        *    during anoperation.0: Overflow has not occurred.1: Overflow
                                        *    has occurred.                                                            */
        __IOM uint32_t CY : 1;         /*!< [3..3] This bit indicates whether a carry or borrow has occurred
                                        *    in the operationresult.0: Carry and borrow have not occurred.1:
                                        *    Carry or borrow has occurred.                                            */
        __IOM uint32_t SAT : 1;        /*!< [4..4] This bit indicates that a saturation arithmetic operation
                                        *    instruction resulted inoverflow and saturation processing
                                        *    is applied to the result. This is acumulative flag, that
                                        *    is, it is set (1) once a saturation occurs and not cleared(0)
                                        *    by subsequent instructions with unsaturated results. This
                                        *    bit is cleared bythe LDSR instruction. Note that execution
                                        *    of an arithmetic operationinstruction neither set nor clear
                                        *    this flag.0: The result was not saturated1: The result
                                        *    was saturated                                                            */
        uint32_t : 27;
    } CTPSW_b;
} RH850_SYS_CTPSW_Type;

typedef union
{
    __IOM uint32_t CTBP;               /*!< (@ 0x00000000) CALLT Base Pointer                                         */

    struct
    {
        __IM uint32_t CTBP0 : 1;       /*!< [0..0] This bit indicates the base pointer address of the CALLT
                                        *    instruction.This bit indicates the start address of the
                                        *    table used by the CALLTinstruction. Always set this bit
                                        *    to 0.                                                                    */
        __IOM uint32_t CTBP : 31;      /*!< [31..1] This bit indicates the base pointer address of the CALLT
                                        *    instruction.This bit indicates the start address of the
                                        *    table used by the CALLTinstruction.CTBP0: Always set this
                                        *    bit to 0.                                                                */
    } CTBP_b;
} RH850_SYS_CTBP_Type;

typedef union
{
    __IOM uint32_t SNZCFG;             /*!< (@ 0x00000000) SNOOZE Configuration                                       */

    struct
    {
        __IOM uint32_t SNZCNT : 8;     /*!< [7..0] These bits specify the number of clock cycles in which
                                        *    execution is to betemporarily halted by the SNOOZE instruction           */
        uint32_t : 24;
    } SNZCFG_b;
} RH850_SYS_SNZCFG_Type;

typedef union
{
    __IOM uint32_t EIWR;               /*!< (@ 0x00000000) EI Level Exception Working Register                        */

    struct
    {
        __IOM uint32_t EIWR : 32;      /*!< [31..0] These bits constitute a working register that can be
                                        *    used for any purposeduring the processing of an EI level
                                        *    exception. Use this register for purposessuch as storing
                                        *    the values of general-purpose registers                                  */
    } EIWR_b;
} RH850_SYS_EIWR_Type;

typedef union
{
    __IOM uint32_t FEWR;               /*!< (@ 0x00000000) FE Level Exception Working Register                        */

    struct
    {
        __IOM uint32_t FEWR : 32;      /*!< [31..0] These bits constitute a working register that can be
                                        *    used for any purposeduring the processing of an FE level
                                        *    exception. Use this register forpurposes such as storing
                                        *    the values of general-purpose registers.                                 */
    } FEWR_b;
} RH850_SYS_FEWR_Type;

typedef union
{
    __IOM uint32_t SPID;               /*!< (@ 0x00000000) System Protection Identifier                               */

    struct
    {
        __IOM uint32_t SPID : 5;       /*!< [4..0] These bits indicate the system protection identifier.The
                                        *    system protection identifier is a variable ID that is used
                                        *    for accessprotection in a product which consists of two
                                        *    or more bus masters includingthis CPU. For its uses and
                                        *    constraints on its value, see Section 3.10.7,Product information
                                        *    of initial value for G4MH register.Within this CPU, the
                                        *    SPID is used to check for area matching by the MPU. Itallows
                                        *    the system specifications defined for the product to be
                                        *    reflected in theMPU's protecti                                           */
        uint32_t : 27;
    } SPID_b;
} RH850_SYS_SPID_Type;

typedef union
{
    __IOM uint32_t SPIDLIST;           /*!< (@ 0x00000000) Legitimate System Protection Identifier List               */

    struct
    {
        __IM uint32_t SL : 32;         /*!< [31..0] This bit indicates whether or not bit can be set as
                                        *    a system protection identifier                                           */
    } SPIDLIST_b;
} RH850_SYS_SPIDLIST_Type;

typedef union
{
    __IOM uint32_t RBASE;              /*!< (@ 0x00000000) Reset Vector Base Address                                  */

    struct
    {
        __IM uint32_t RINT : 1;        /*!< [0..0] When the RINT bit is set, the exception handler address
                                        *    for interruptprocessing is reduced. See Section 3.2.4.4(1)(a),
                                        *    Direct Vector Method.This bit is valid when PSW.EBV = 0.                 */
        __IM uint32_t DV : 1;          /*!< [1..1] When the DV bit is set, the exception handler address
                                        *    for interrupt isdetermined by using the direct vector method.
                                        *    For details, see Section3.2.4.4(1)(b), Table Reference
                                        *    Method. This bit is valid when PSW.EBV =0.                               */
        uint32_t            : 7;
        __IM uint32_t RBASE : 23;      /*!< [31..9] These bits indicate the reset vector when there is a
                                        *    reset. When PSW.EBV =0, this address is also used as the
                                        *    exception vector.The RBASE8 to RBASE0 bits are not assigned
                                        *    as names because these bitsare always 0.                                 */
    } RBASE_b;
} RH850_SYS_RBASE_Type;

typedef union
{
    __IOM uint32_t EBASE;              /*!< (@ 0x00000000) Exception Handler Vector Address                           */

    struct
    {
        __IOM uint32_t RINT : 1;       /*!< [0..0] When the RINT bit is set, the exception handler address
                                        *    for interruptprocessing is reduced. See Section 3.2.4.4(1)(a),
                                        *    Direct Vector Method.                                                    */
        __IOM uint32_t DV : 1;         /*!< [1..1] When the DV bit is set, the exception handler address
                                        *    for interrupt isdetermined by using the direct vector method.
                                        *    For details, see Section3.2.4.4(1)(b), Table Reference
                                        *    Method                                                                   */
        uint32_t             : 7;
        __IOM uint32_t EBASE : 23;     /*!< [31..9] The exception handler routine address is changed to
                                        *    the address resultingfrom adding the offset address of
                                        *    each exception to the base addressspecified for this register.The
                                        *    EBASE8 to EBASE0 bits are not assigned as names because
                                        *    these bitsare always 0.                                                  */
    } EBASE_b;
} RH850_SYS_EBASE_Type;

typedef union
{
    __IOM uint32_t INTBP;              /*!< (@ 0x00000000) Base Address of the Interrupt Handler Address
                                        *                  Table                                                      */

    struct
    {
        uint32_t             : 9;
        __IOM uint32_t INTBP : 23;     /*!< [31..9] These bits indicate the base pointer address for an
                                        *    interrupt when the tablereference method is used.The value
                                        *    indicated by these bits is the first address in the table
                                        *    used todetermine the exception handler when the interrupt
                                        *    specified by the tablereference method (EIINTn) is acknowledged.The
                                        *    INTBP8 to INTBP0 bits are not assigned as names because
                                        *    these bitsare always 0.                                                  */
    } INTBP_b;
} RH850_SYS_INTBP_Type;

typedef union
{
    __IOM uint32_t MCTL;               /*!< (@ 0x00000000) Machine Control                                            */

    struct
    {
        __IOM uint32_t UIC : 1;        /*!< [0..0] This bit is used to control the interrupt enable/disable
                                        *    operation in usermode. When this bit is set to 1, executing
                                        *    the EI/DI instruction in user modebecome possible                        */
        uint32_t : 31;
    } MCTL_b;
} RH850_SYS_MCTL_Type;

typedef union
{
    __IOM uint32_t SVLOCK;             /*!< (@ 0x00000000) Supervisor Lock                                            */

    struct
    {
        __IOM uint32_t SVL : 1;        /*!< [0..0] This bit specifies whether to restrict the CPU operation
                                        *    in supervisor mode.0: Does not restrict the CPU operation
                                        *    in supervisor mode.1: Restrict the CPU operation in supervisor
                                        *    mode.If the SVL bit is set to 1, the following system registers*1cannot
                                        *    be updated even when the CPU is in supervisor mode:SPID,
                                        *    MPM, MPLA, MPUA, MPAT, MPIDn, MPBK                                       */
        uint32_t : 31;
    } SVLOCK_b;
} RH850_SYS_SVLOCK_Type;

typedef union
{
    __IOM uint32_t SCCFG;              /*!< (@ 0x00000000) SYSCALL Operation Setting                                  */

    struct
    {
        __IOM uint32_t SIZE : 8;       /*!< [7..0] These bits specify the maximum number of entries of a
                                        *    table that theSYSCALL instruction references. The maximum
                                        *    number of entries theSYSCALL instruction references is
                                        *    1 if SIZE is 0, and 256 if SIZE is 255. Bysetting the maximum
                                        *    number of entries appropriately in accordance with thenumber
                                        *    of functions branched by the SYSCALL instruction, the memory
                                        *    areacan be effectively used.If a vector exceeding the maximum
                                        *    number of entries is specified for theSYSCALL instruction,
                                        *    the first entry is select                                                */
        uint32_t : 24;
    } SCCFG_b;
} RH850_SYS_SCCFG_Type;

typedef union
{
    __IOM uint32_t SCBP;               /*!< (@ 0x00000000) SYSCALL Base Pointer                                       */

    struct
    {
        __IOM uint32_t SCBP : 32;      /*!< [31..0] These bits indicate the base pointer address of the
                                        *    SYSCALL instruction.These bits indicate the start address
                                        *    of the table used by the SYSCALLinstruction.SCBP[0:1]:
                                        *    Always set these bits to 0.                                              */
    } SCBP_b;
} RH850_SYS_SCBP_Type;

typedef union
{
    __IOM uint32_t PEID;               /*!< (@ 0x00000000) Processor Element Identifier                               */

    struct
    {
        __IM uint32_t PEID : 5;        /*!< [4..0] These bits indicate the processor element identifier.              */
        uint32_t           : 27;
    } PEID_b;
} RH850_SYS_PEID_Type;

typedef union
{
    __IOM uint32_t BMID;               /*!< (@ 0x00000000) Bus Master Identifier                                      */

    struct
    {
        __IM uint32_t BMID : 5;        /*!< [4..0] These bits indicate the bus master identifier                      */
        uint32_t           : 27;
    } BMID_b;
} RH850_SYS_BMID_Type;

typedef union
{
    __IOM uint32_t MEA;                /*!< (@ 0x00000000) Memory Error Address                                       */

    struct
    {
        __IOM uint32_t MEA : 32;       /*!< [31..0] These bits holds the address in which an MAE (misalignment)
                                        *    or MPUviolation occurred.                                                */
    } MEA_b;
} RH850_SYS_MEA_Type;

typedef union
{
    __IOM uint32_t MEI;                /*!< (@ 0x00000000) Memory Error Information                                   */

    struct
    {
        __IOM uint32_t RW : 1;         /*!< [0..0] This bit indicates whether the operation performed by
                                        *    the instruction thatcaused the exception is a read (Load-memory)
                                        *    or a write (Store-memory).0: Read (Load-memory)1: Write
                                        *    (Store-memory)                                                           */
        __IOM uint32_t ITYPE : 5;      /*!< [5..1] These bits indicate the instruction that caused the exception      */
        uint32_t             : 2;
        __IOM uint32_t U     : 1;      /*!< [8..8] This bit indicates the sign extension method of the instruction
                                        *    that causedthe exception.0: Signed1: Unsigned                            */
        __IOM uint32_t DS : 3;         /*!< [11..9] These bits indicate the data type of the instruction
                                        *    that caused theexception*1.0: Byte (8 bits)1: Halfword
                                        *    (16 bits)2: Word (32 bits)3: Double-word (64 bits)4: Quad-word
                                        *    (128 bits)                                                               */
        uint32_t           : 4;
        __IOM uint32_t REG : 5;        /*!< [20..16] These bits indicate the source register number or destination
                                        *    registernumber of the instruction that caused the exception              */
        uint32_t           : 7;
        __IOM uint32_t LEN : 4;        /*!< [31..28] These bits indicate the code size of the instruction
                                        *    that causes the exception.0: Non-instruction factor2: 16
                                        *    bits4: 32 bits6: 48 bits8 :64 bits                                       */
    } MEI_b;
} RH850_SYS_MEI_Type;

typedef union
{
    __IOM uint32_t RBCR0;              /*!< (@ 0x00000000) Register Bank Control 0                                    */

    struct
    {
        __IOM uint32_t BE : 15;        /*!< [14..0] These bits specify the priority level of the interrupt
                                        *    on which the register bankis to be used.0: Do not use the
                                        *    register bank on an interrupt of the level corresponding
                                        *    tothis bit.1: Use the register bank on an interrupt of
                                        *    the level corresponding to thisbit.                                      */
        __IOM uint32_t BE15 : 1;       /*!< [15..15] This bit specifies whether to use a register bank on
                                        *    an interrupt (EIINTn) withpriority 15 to 630: Do not use
                                        *    the register bank on an interrupt with the priority 15
                                        *    to 631: Use the register bank on an interrupt with the
                                        *    priority 15 to 63While this bit is set to 1, if EI level
                                        *    interrupt (EIINTn) with priority 15 to 63 isacknowledged,
                                        *    the register bank function can be used.                                  */
        __IOM uint32_t MD : 1;         /*!< [16..16] This bit specifies the save mode of the register bank.0:
                                        *    Save mode 01: Save mode 1                                                */
        uint32_t : 15;
    } RBCR0_b;
} RH850_SYS_RBCR0_Type;

typedef union
{
    __IOM uint32_t RBCR1;              /*!< (@ 0x00000000) Register Bank Control 1                                    */

    struct
    {
        __IOM uint32_t NC : 15;        /*!< [14..0] These bits specify the priority level of the interrupt
                                        *    on which the register bankis to be used.0: Do not use the
                                        *    register bank on an interrupt of the level corresponding
                                        *    tothis bit.1: Use the register bank on an interrupt of
                                        *    the level corresponding to thisbit.                                      */
        __IOM uint32_t NC15 : 1;       /*!< [15..15] This bit specifies whether to use a register bank on
                                        *    an interrupt (EIINTn) withpriority 15 to 630: Do not use
                                        *    the register bank on an interrupt with the priority 15
                                        *    to 631: Use the register bank on an interrupt with the
                                        *    priority 15 to 63While this bit is set to 1, if EI level
                                        *    interrupt (EIINTn) with priority 15 to 63 isacknowledged,
                                        *    the register bank function can be used.                                  */
        uint32_t : 16;
    } RBCR1_b;
} RH850_SYS_RBCR1_Type;

typedef union
{
    __IOM uint32_t RBNR;               /*!< (@ 0x00000000) Register Bank Number                                       */

    struct
    {
        __IOM uint32_t BN : 6;         /*!< [5..0] These bits indicate the number of the register bank to
                                        *    be used next.The value in these bits is incremented by
                                        *    1 when an interrupt (EIINTn) thatuses a register bank is
                                        *    accepted. If the value of BN is larger thanINTCFG.ULNR,
                                        *    or if the value of BN is 63, if an interrupt (EIINTn) using
                                        *    theregister bank occurs, a SYSERR exception is generated.
                                        *    That interrupt is notaccepted, and it is put on hold.The
                                        *    value of BN is decremented by 1 when a RESBANK instruction
                                        *    isexecuted. If the RESBANK instruction i                                 */
        uint32_t : 26;
    } RBNR_b;
} RH850_SYS_RBNR_Type;

typedef union
{
    __IOM uint32_t RBIP;               /*!< (@ 0x00000000) Register Bank Initial Pointer                              */

    struct
    {
        uint32_t            : 4;
        __IOM uint32_t RBIP : 28;      /*!< [31..4] These bits indicate the initial pointer to the register
                                        *    bank.The values of RBCR0.MD and RBNR.BN together with this
                                        *    value determinethe memory address to which the next register
                                        *    bank to be used is allocatedas follows.• Save mode 0
                                        *    (RBCR0.MD = 0): RBIP - RBNR.BN × 60H• Save mode 1
                                        *    (RBCR0.MD = 1): RBIP - RBNR.BN × 90H                                     */
    } RBIP_b;
} RH850_SYS_RBIP_Type;

/** @brief Basic system register macro Definitions */

/* ================================================================================================================== */
/* ================                                           R_SYS                                  ================ */
/* ================================================================================================================== */

/* =========================================================  EIPC  ================================================= */
  #define R_SYS_EIPC_EIPC_Pos        (0UL)          /*!< EIPC (Bit 0)                                                 */
  #define R_SYS_EIPC_EIPC_Msk        (0xffffffffUL) /*!< EIPC (Bitfield-Mask: 0xffffffff)                             */
/* =========================================================  EIPSW  ================================================ */
  #define R_SYS_EIPSW_UM_Pos         (30UL)         /*!< UM (Bit 30)                                                  */
  #define R_SYS_EIPSW_UM_Msk         (0x40000000UL) /*!< UM (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_EIPSW_EIMASK_Pos     (20UL)         /*!< EIMASK (Bit 20)                                              */
  #define R_SYS_EIPSW_EIMASK_Msk     (0x3f00000UL)  /*!< EIMASK (Bitfield-Mask: 0x3f)                                 */
  #define R_SYS_EIPSW_CU2_Pos        (18UL)         /*!< CU2 (Bit 18)                                                 */
  #define R_SYS_EIPSW_CU2_Msk        (0x40000UL)    /*!< CU2 (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_EIPSW_CU1_Pos        (17UL)         /*!< CU1 (Bit 17)                                                 */
  #define R_SYS_EIPSW_CU1_Msk        (0x20000UL)    /*!< CU1 (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_EIPSW_CU0_Pos        (16UL)         /*!< CU0 (Bit 16)                                                 */
  #define R_SYS_EIPSW_CU0_Msk        (0x10000UL)    /*!< CU0 (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_EIPSW_EBV_Pos        (15UL)         /*!< EBV (Bit 15)                                                 */
  #define R_SYS_EIPSW_EBV_Msk        (0x8000UL)     /*!< EBV (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_EIPSW_NP_Pos         (7UL)          /*!< NP (Bit 7)                                                   */
  #define R_SYS_EIPSW_NP_Msk         (0x80UL)       /*!< NP (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_EIPSW_EP_Pos         (6UL)          /*!< EP (Bit 6)                                                   */
  #define R_SYS_EIPSW_EP_Msk         (0x40UL)       /*!< EP (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_EIPSW_ID_Pos         (5UL)          /*!< ID (Bit 5)                                                   */
  #define R_SYS_EIPSW_ID_Msk         (0x20UL)       /*!< ID (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_EIPSW_SAT_Pos        (4UL)          /*!< SAT (Bit 4)                                                  */
  #define R_SYS_EIPSW_SAT_Msk        (0x10UL)       /*!< SAT (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_EIPSW_CY_Pos         (3UL)          /*!< CY (Bit 3)                                                   */
  #define R_SYS_EIPSW_CY_Msk         (0x8UL)        /*!< CY (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_EIPSW_OV_Pos         (2UL)          /*!< OV (Bit 2)                                                   */
  #define R_SYS_EIPSW_OV_Msk         (0x4UL)        /*!< OV (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_EIPSW_S_Pos          (1UL)          /*!< S (Bit 1)                                                    */
  #define R_SYS_EIPSW_S_Msk          (0x2UL)        /*!< S (Bitfield-Mask: 0x01)                                      */
  #define R_SYS_EIPSW_Z_Pos          (0UL)          /*!< Z (Bit 0)                                                    */
  #define R_SYS_EIPSW_Z_Msk          (0x1UL)        /*!< Z (Bitfield-Mask: 0x01)                                      */
/* =========================================================  FEPC  ================================================= */
  #define R_SYS_FEPC_FEPC_Pos        (0UL)          /*!< FEPC (Bit 0)                                                 */
  #define R_SYS_FEPC_FEPC_Msk        (0xffffffffUL) /*!< FEPC (Bitfield-Mask: 0xffffffff)                             */
/* =========================================================  FEPSW  ================================================ */
  #define R_SYS_FEPSW_UM_Pos         (30UL)         /*!< UM (Bit 30)                                                  */
  #define R_SYS_FEPSW_UM_Msk         (0x40000000UL) /*!< UM (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_FEPSW_EIMASK_Pos     (20UL)         /*!< EIMASK (Bit 20)                                              */
  #define R_SYS_FEPSW_EIMASK_Msk     (0x3f00000UL)  /*!< EIMASK (Bitfield-Mask: 0x3f)                                 */
  #define R_SYS_FEPSW_CU2_Pos        (18UL)         /*!< CU2 (Bit 18)                                                 */
  #define R_SYS_FEPSW_CU2_Msk        (0x40000UL)    /*!< CU2 (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_FEPSW_CU1_Pos        (17UL)         /*!< CU1 (Bit 17)                                                 */
  #define R_SYS_FEPSW_CU1_Msk        (0x20000UL)    /*!< CU1 (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_FEPSW_CU0_Pos        (16UL)         /*!< CU0 (Bit 16)                                                 */
  #define R_SYS_FEPSW_CU0_Msk        (0x10000UL)    /*!< CU0 (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_FEPSW_EBV_Pos        (15UL)         /*!< EBV (Bit 15)                                                 */
  #define R_SYS_FEPSW_EBV_Msk        (0x8000UL)     /*!< EBV (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_FEPSW_NP_Pos         (7UL)          /*!< NP (Bit 7)                                                   */
  #define R_SYS_FEPSW_NP_Msk         (0x80UL)       /*!< NP (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_FEPSW_EP_Pos         (6UL)          /*!< EP (Bit 6)                                                   */
  #define R_SYS_FEPSW_EP_Msk         (0x40UL)       /*!< EP (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_FEPSW_ID_Pos         (5UL)          /*!< ID (Bit 5)                                                   */
  #define R_SYS_FEPSW_ID_Msk         (0x20UL)       /*!< ID (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_FEPSW_SAT_Pos        (4UL)          /*!< SAT (Bit 4)                                                  */
  #define R_SYS_FEPSW_SAT_Msk        (0x10UL)       /*!< SAT (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_FEPSW_CY_Pos         (3UL)          /*!< CY (Bit 3)                                                   */
  #define R_SYS_FEPSW_CY_Msk         (0x8UL)        /*!< CY (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_FEPSW_OV_Pos         (2UL)          /*!< OV (Bit 2)                                                   */
  #define R_SYS_FEPSW_OV_Msk         (0x4UL)        /*!< OV (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_FEPSW_S_Pos          (1UL)          /*!< S (Bit 1)                                                    */
  #define R_SYS_FEPSW_S_Msk          (0x2UL)        /*!< S (Bitfield-Mask: 0x01)                                      */
  #define R_SYS_FEPSW_Z_Pos          (0UL)          /*!< Z (Bit 0)                                                    */
  #define R_SYS_FEPSW_Z_Msk          (0x1UL)        /*!< Z (Bitfield-Mask: 0x01)                                      */
/* ==========================================================  PSW  ================================================= */
  #define R_SYS_PSW_UM_Pos           (30UL)         /*!< UM (Bit 30)                                                  */
  #define R_SYS_PSW_UM_Msk           (0x40000000UL) /*!< UM (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_PSW_EIMASK_Pos       (20UL)         /*!< EIMASK (Bit 20)                                              */
  #define R_SYS_PSW_EIMASK_Msk       (0x3f00000UL)  /*!< EIMASK (Bitfield-Mask: 0x3f)                                 */
  #define R_SYS_PSW_CU2_Pos          (18UL)         /*!< CU2 (Bit 18)                                                 */
  #define R_SYS_PSW_CU2_Msk          (0x40000UL)    /*!< CU2 (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_PSW_CU1_Pos          (17UL)         /*!< CU1 (Bit 17)                                                 */
  #define R_SYS_PSW_CU1_Msk          (0x20000UL)    /*!< CU1 (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_PSW_CU0_Pos          (16UL)         /*!< CU0 (Bit 16)                                                 */
  #define R_SYS_PSW_CU0_Msk          (0x10000UL)    /*!< CU0 (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_PSW_EBV_Pos          (15UL)         /*!< EBV (Bit 15)                                                 */
  #define R_SYS_PSW_EBV_Msk          (0x8000UL)     /*!< EBV (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_PSW_NP_Pos           (7UL)          /*!< NP (Bit 7)                                                   */
  #define R_SYS_PSW_NP_Msk           (0x80UL)       /*!< NP (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_PSW_EP_Pos           (6UL)          /*!< EP (Bit 6)                                                   */
  #define R_SYS_PSW_EP_Msk           (0x40UL)       /*!< EP (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_PSW_ID_Pos           (5UL)          /*!< ID (Bit 5)                                                   */
  #define R_SYS_PSW_ID_Msk           (0x20UL)       /*!< ID (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_PSW_SAT_Pos          (4UL)          /*!< SAT (Bit 4)                                                  */
  #define R_SYS_PSW_SAT_Msk          (0x10UL)       /*!< SAT (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_PSW_CY_Pos           (3UL)          /*!< CY (Bit 3)                                                   */
  #define R_SYS_PSW_CY_Msk           (0x8UL)        /*!< CY (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_PSW_OV_Pos           (2UL)          /*!< OV (Bit 2)                                                   */
  #define R_SYS_PSW_OV_Msk           (0x4UL)        /*!< OV (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_PSW_S_Pos            (1UL)          /*!< S (Bit 1)                                                    */
  #define R_SYS_PSW_S_Msk            (0x2UL)        /*!< S (Bitfield-Mask: 0x01)                                      */
  #define R_SYS_PSW_Z_Pos            (0UL)          /*!< Z (Bit 0)                                                    */
  #define R_SYS_PSW_Z_Msk            (0x1UL)        /*!< Z (Bitfield-Mask: 0x01)                                      */
/* =========================================================  EIIC  ================================================= */
  #define R_SYS_EIIC_EIIC_Pos        (0UL)          /*!< EIIC (Bit 0)                                                 */
  #define R_SYS_EIIC_EIIC_Msk        (0xffffffffUL) /*!< EIIC (Bitfield-Mask: 0xffffffff)                             */
/* =========================================================  FEIC  ================================================= */
  #define R_SYS_FEIC_FEIC_Pos        (0UL)          /*!< FEIC (Bit 0)                                                 */
  #define R_SYS_FEIC_FEIC_Msk        (0xffffffffUL) /*!< FEIC (Bitfield-Mask: 0xffffffff)                             */
/* =========================================================  CTPC  ================================================= */
  #define R_SYS_CTPC_CTPC_Pos        (0UL)          /*!< CTPC (Bit 0)                                                 */
  #define R_SYS_CTPC_CTPC_Msk        (0xffffffffUL) /*!< CTPC (Bitfield-Mask: 0xffffffff)                             */
/* =========================================================  CTPSW  ================================================ */
  #define R_SYS_CTPSW_SAT_Pos        (4UL)          /*!< SAT (Bit 4)                                                  */
  #define R_SYS_CTPSW_SAT_Msk        (0x10UL)       /*!< SAT (Bitfield-Mask: 0x01)                                    */
  #define R_SYS_CTPSW_CY_Pos         (3UL)          /*!< CY (Bit 3)                                                   */
  #define R_SYS_CTPSW_CY_Msk         (0x8UL)        /*!< CY (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_CTPSW_OV_Pos         (2UL)          /*!< OV (Bit 2)                                                   */
  #define R_SYS_CTPSW_OV_Msk         (0x4UL)        /*!< OV (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_CTPSW_S_Pos          (1UL)          /*!< S (Bit 1)                                                    */
  #define R_SYS_CTPSW_S_Msk          (0x2UL)        /*!< S (Bitfield-Mask: 0x01)                                      */
  #define R_SYS_CTPSW_Z_Pos          (0UL)          /*!< Z (Bit 0)                                                    */
  #define R_SYS_CTPSW_Z_Msk          (0x1UL)        /*!< Z (Bitfield-Mask: 0x01)                                      */
/* =========================================================  CTBP  ================================================= */
  #define R_SYS_CTBP_CTBP_Pos        (1UL)          /*!< CTBP (Bit 1)                                                 */
  #define R_SYS_CTBP_CTBP_Msk        (0xfffffffeUL) /*!< CTBP (Bitfield-Mask: 0x7fffffff)                             */
  #define R_SYS_CTBP_CTBP0_Pos       (0UL)          /*!< CTBP0 (Bit 0)                                                */
  #define R_SYS_CTBP_CTBP0_Msk       (0x1UL)        /*!< CTBP0 (Bitfield-Mask: 0x01)                                  */
/* ========================================================  SNZCFG  ================================================ */
  #define R_SYS_SNZCFG_SNZCNT_Pos    (0UL)          /*!< SNZCNT (Bit 0)                                               */
  #define R_SYS_SNZCFG_SNZCNT_Msk    (0xffUL)       /*!< SNZCNT (Bitfield-Mask: 0xff)                                 */
/* =========================================================  EIWR  ================================================= */
  #define R_SYS_EIWR_EIWR_Pos        (0UL)          /*!< EIWR (Bit 0)                                                 */
  #define R_SYS_EIWR_EIWR_Msk        (0xffffffffUL) /*!< EIWR (Bitfield-Mask: 0xffffffff)                             */
/* =========================================================  FEWR  ================================================= */
  #define R_SYS_FEWR_FEWR_Pos        (0UL)          /*!< FEWR (Bit 0)                                                 */
  #define R_SYS_FEWR_FEWR_Msk        (0xffffffffUL) /*!< FEWR (Bitfield-Mask: 0xffffffff)                             */
/* =========================================================  SPID  ================================================= */
  #define R_SYS_SPID_SPID_Pos        (0UL)          /*!< SPID (Bit 0)                                                 */
  #define R_SYS_SPID_SPID_Msk        (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                   */
/* =======================================================  SPIDLIST  =============================================== */
  #define R_SYS_SPIDLIST_SL_Pos      (0UL)          /*!< SL (Bit 0)                                                   */
  #define R_SYS_SPIDLIST_SL_Msk      (0xffffffffUL) /*!< SL (Bitfield-Mask: 0xffffffff)                               */
/* =========================================================  RBASE  ================================================ */
  #define R_SYS_RBASE_RBASE_Pos      (9UL)          /*!< RBASE (Bit 9)                                                */
  #define R_SYS_RBASE_RBASE_Msk      (0xfffffe00UL) /*!< RBASE (Bitfield-Mask: 0x7fffff)                              */
  #define R_SYS_RBASE_DV_Pos         (1UL)          /*!< DV (Bit 1)                                                   */
  #define R_SYS_RBASE_DV_Msk         (0x2UL)        /*!< DV (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_RBASE_RINT_Pos       (0UL)          /*!< RINT (Bit 0)                                                 */
  #define R_SYS_RBASE_RINT_Msk       (0x1UL)        /*!< RINT (Bitfield-Mask: 0x01)                                   */
/* =========================================================  EBASE  ================================================ */
  #define R_SYS_EBASE_EBASE_Pos      (9UL)          /*!< EBASE (Bit 9)                                                */
  #define R_SYS_EBASE_EBASE_Msk      (0xfffffe00UL) /*!< EBASE (Bitfield-Mask: 0x7fffff)                              */
  #define R_SYS_EBASE_DV_Pos         (1UL)          /*!< DV (Bit 1)                                                   */
  #define R_SYS_EBASE_DV_Msk         (0x2UL)        /*!< DV (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_EBASE_RINT_Pos       (0UL)          /*!< RINT (Bit 0)                                                 */
  #define R_SYS_EBASE_RINT_Msk       (0x1UL)        /*!< RINT (Bitfield-Mask: 0x01)                                   */
/* =========================================================  INTBP  ================================================ */
  #define R_SYS_INTBP_INTBP_Pos      (9UL)          /*!< INTBP (Bit 9)                                                */
  #define R_SYS_INTBP_INTBP_Msk      (0xfffffe00UL) /*!< INTBP (Bitfield-Mask: 0x7fffff)                              */
/* =========================================================  MCTL  ================================================= */
  #define R_SYS_MCTL_UIC_Pos         (0UL)          /*!< UIC (Bit 0)                                                  */
  #define R_SYS_MCTL_UIC_Msk         (0x1UL)        /*!< UIC (Bitfield-Mask: 0x01)                                    */
/* ========================================================  SVLOCK  ================================================ */
  #define R_SYS_SVLOCK_SVL_Pos       (0UL)          /*!< SVL (Bit 0)                                                  */
  #define R_SYS_SVLOCK_SVL_Msk       (0x1UL)        /*!< SVL (Bitfield-Mask: 0x01)                                    */
/* =========================================================  SCCFG  ================================================ */
  #define R_SYS_SCCFG_SIZE_Pos       (0UL)          /*!< SIZE (Bit 0)                                                 */
  #define R_SYS_SCCFG_SIZE_Msk       (0xffUL)       /*!< SIZE (Bitfield-Mask: 0xff)                                   */
/* =========================================================  SCBP  ================================================= */
  #define R_SYS_SCBP_SCBP_Pos        (0UL)          /*!< SCBP (Bit 0)                                                 */
  #define R_SYS_SCBP_SCBP_Msk        (0xffffffffUL) /*!< SCBP (Bitfield-Mask: 0xffffffff)                             */
/* =========================================================  PEID  ================================================= */
  #define R_SYS_PEID_PEID_Pos        (0UL)          /*!< PEID (Bit 0)                                                 */
  #define R_SYS_PEID_PEID_Msk        (0x1fUL)       /*!< PEID (Bitfield-Mask: 0x1f)                                   */
/* =========================================================  BMID  ================================================= */
  #define R_SYS_BMID_BMID_Pos        (0UL)          /*!< BMID (Bit 0)                                                 */
  #define R_SYS_BMID_BMID_Msk        (0x1fUL)       /*!< BMID (Bitfield-Mask: 0x1f)                                   */
/* ==========================================================  MEA  ================================================= */
  #define R_SYS_MEA_MEA_Pos          (0UL)          /*!< MEA (Bit 0)                                                  */
  #define R_SYS_MEA_MEA_Msk          (0xffffffffUL) /*!< MEA (Bitfield-Mask: 0xffffffff)                              */
/* ==========================================================  MEI  ================================================= */
  #define R_SYS_MEI_LEN_Pos          (28UL)         /*!< LEN (Bit 28)                                                 */
  #define R_SYS_MEI_LEN_Msk          (0xf0000000UL) /*!< LEN (Bitfield-Mask: 0x0f)                                    */
  #define R_SYS_MEI_REG_Pos          (16UL)         /*!< REG (Bit 16)                                                 */
  #define R_SYS_MEI_REG_Msk          (0x1f0000UL)   /*!< REG (Bitfield-Mask: 0x1f)                                    */
  #define R_SYS_MEI_DS_Pos           (9UL)          /*!< DS (Bit 9)                                                   */
  #define R_SYS_MEI_DS_Msk           (0xe00UL)      /*!< DS (Bitfield-Mask: 0x07)                                     */
  #define R_SYS_MEI_U_Pos            (8UL)          /*!< U (Bit 8)                                                    */
  #define R_SYS_MEI_U_Msk            (0x100UL)      /*!< U (Bitfield-Mask: 0x01)                                      */
  #define R_SYS_MEI_ITYPE_Pos        (1UL)          /*!< ITYPE (Bit 1)                                                */
  #define R_SYS_MEI_ITYPE_Msk        (0x3eUL)       /*!< ITYPE (Bitfield-Mask: 0x1f)                                  */
  #define R_SYS_MEI_RW_Pos           (0UL)          /*!< RW (Bit 0)                                                   */
  #define R_SYS_MEI_RW_Msk           (0x1UL)        /*!< RW (Bitfield-Mask: 0x01)                                     */
/* =========================================================  RBCR0  ================================================ */
  #define R_SYS_RBCR0_MD_Pos         (16UL)         /*!< MD (Bit 16)                                                  */
  #define R_SYS_RBCR0_MD_Msk         (0x10000UL)    /*!< MD (Bitfield-Mask: 0x01)                                     */
  #define R_SYS_RBCR0_BE15_Pos       (15UL)         /*!< BE15 (Bit 15)                                                */
  #define R_SYS_RBCR0_BE15_Msk       (0x8000UL)     /*!< BE15 (Bitfield-Mask: 0x01)                                   */
  #define R_SYS_RBCR0_BE_Pos         (0UL)          /*!< BE (Bit 0)                                                   */
  #define R_SYS_RBCR0_BE_Msk         (0x7fffUL)     /*!< BE (Bitfield-Mask: 0x7fff)                                   */
/* =========================================================  RBCR1  ================================================ */
  #define R_SYS_RBCR1_NC15_Pos       (15UL)         /*!< NC15 (Bit 15)                                                */
  #define R_SYS_RBCR1_NC15_Msk       (0x8000UL)     /*!< NC15 (Bitfield-Mask: 0x01)                                   */
  #define R_SYS_RBCR1_NC_Pos         (0UL)          /*!< NC (Bit 0)                                                   */
  #define R_SYS_RBCR1_NC_Msk         (0x7fffUL)     /*!< NC (Bitfield-Mask: 0x7fff)                                   */
/* =========================================================  RBNR  ================================================= */
  #define R_SYS_RBNR_BN_Pos          (0UL)          /*!< BN (Bit 0)                                                   */
  #define R_SYS_RBNR_BN_Msk          (0x3fUL)       /*!< BN (Bitfield-Mask: 0x3f)                                     */
/* =========================================================  RBIP  ================================================= */
  #define R_SYS_RBIP_RBIP_Pos        (4UL)          /*!< RBIP (Bit 4)                                                 */
  #define R_SYS_RBIP_RBIP_Msk        (0xfffffff0UL) /*!< RBIP (Bitfield-Mask: 0xfffffff)                              */
/* =========================================================  PID  ================================================== */
  #define R_MPU_PID_MPU_Pos          (8UL)          /*!< MPU (Bit 8)                                                  */
  #define R_MPU_PID_MPU_Msk          (0x100UL)      /*!< MPU (Bitfield-Mask: 0x7f)                                    */

/*@}*/ /* end of group RH850_G4MH_SYS */

/**
 * @ingroup  RH850_G4MH_Core_register
 * @defgroup RH850_G4MH_IRQ     Interrupt Function Registers (IRQ)
 * @brief    Type definitions for the Interrupt Function Registers (IRQ)
 * @{
 */

/**
 * @brief  Structure type to access the Interrupt Function Registers (SYS).
 */

typedef union
{
    __IOM uint32_t ISPR;               /*!< (@ 0x00000000) Priority of Interrupt being Serviced                       */

    struct
    {
        __IM uint32_t ISP : 16;        /*!< [15..0] These bits indicate the acknowledgment status of an
                                        *    EIINTn interrupt with apriority*1 that corresponds to the
                                        *    relevant bit position.0: An interrupt request for an interrupt
                                        *    whose priority corresponds to therelevant bit position
                                        *    has not been acknowledged.1: An interrupt request for an
                                        *    interrupt whose priority corresponds to therelevant position
                                        *    is being serviced by the CPU core.                                       */
        uint32_t : 16;
    } ISPR_b;
} RH850_IRQ_ISPR_Type;

typedef union
{
    __IOM uint32_t IMSR;               /*!< (@ 0x00000000) Interrupt Mask Status                                      */

    struct
    {
        __IOM uint32_t EEIM : 1;       /*!< [0..0] This bit specifies the existence of EIINT whose acceptance
                                        *    is masked byISPR.ISP when INTCFG.EPL is cleared to 0 or
                                        *    PSW.EIMASK whenINTCFG.EPL is set to 1.0: EIINT masked by
                                        *    ISPR.ISP or PSW.EIMASK does not exist1: EIINT masked by
                                        *    ISPR.ISP or PSW.EIMASK exists                                            */
        __IOM uint32_t EPLM : 1;       /*!< [1..1] This bit specifies the existence of EIINT whose acceptance
                                        *    is masked byPLMR.PLM.0: EIINT masked by PLMR.PLM does not
                                        *    exist1: EIINT masked by PLMR.PLM exists                                  */
        __IOM uint32_t EID : 1;        /*!< [2..2] This bit specifies the existence of EIINT whose acceptance
                                        *    is masked byPSW.ID.0: EIINT masked by PSW.ID does not exist1:
                                        *    EIINT masked by PSW.ID exists                                            */
        __IOM uint32_t ENP : 1;        /*!< [3..3] This bit specifies the existence of EIINT whose acceptance
                                        *    is masked byPSW.NP.0: EIINT masked by PSW.NP does not exist1:
                                        *    EIINT masked by PSW.NP does exists                                       */
        __IOM uint32_t FNP : 1;        /*!< [4..4] This bit specifies the existence of FEINT whose acceptance
                                        *    is masked byPSW.NP.0: FEINT masked by PSW.NP does not exist1:
                                        *    FEINT masked by PSW.NP does exists                                       */
        uint32_t : 27;
    } IMSR_b;
} RH850_IRQ_IMSR_Type;

typedef union
{
    __IOM uint32_t ICSR;               /*!< (@ 0x00000000) Interrupt Control Status                                   */

    struct
    {
        __IM uint32_t PMEI : 1;        /*!< [0..0] This bit specifies the existence of EIINT whose acceptance
                                        *    is masked byISPR.ISP when INTCFG.EPL is cleared to 0 or
                                        *    PSW.EIMASK whenINTCFG.EPL is set to 1.0: EIINT masked by
                                        *    ISPR.ISP or PSW.EIMASK does not exist1: EIINT masked by
                                        *    ISPR.ISP or PSW.EIMASK exists                                            */
        uint32_t : 31;
    } ICSR_b;
} RH850_IRQ_ICSR_Type;

typedef union
{
    __IOM uint32_t INTCFG;             /*!< (@ 0x00000000) Interrupt Function Setting                                 */

    struct
    {
        __IOM uint32_t ISPC : 1;       /*!< [0..0] This bit changes how the ISPR register is written.0:
                                        *    The ISPR register is automatically updated. Updates triggered
                                        *    by theprogram (via execution of LDSR instruction) are ignored.1:
                                        *    The ISPR register is not automatically updated. Updates
                                        *    triggered by theprogram (via execution of LDSR instruction)
                                        *    are performed.                                                           */
        __IOM uint32_t EPL : 1;        /*!< [1..1] For the interrupt (EIINTn), specify whether to enable
                                        *    interrupt priority levelextension function.0: Interrupt
                                        *    priority level extension function is disabled1: Interrupt
                                        *    priority level extension function is enabled                             */
        uint32_t            : 14;
        __IOM uint32_t ULNR : 6;       /*!< [21..16] Specifying the maximum value of available register
                                        *    bank numbers.If the value of the RBNR.BN is bigger than
                                        *    the ULNR, or the value of theRBNR.BN is 63; and the interrupt
                                        *    (EIINTn) whose register bank function isenable occurs,
                                        *    the SYSERR exception will occur. Note that the interrupt(EIINTn)
                                        *    is not accepted and is held.                                             */
        uint32_t : 10;
    } INTCFG_b;
} RH850_IRQ_INTCFG_Type;

typedef union
{
    __IOM uint32_t PLMR;               /*!< (@ 0x00000000) Interrupt Priority Level Mask                              */

    struct
    {
        __IOM uint32_t PLM : 6;        /*!< [5..0] These bits are used to mask the interrupts (EIINTn) whose
                                        *    priority level is nothigher than the level specified by
                                        *    these bits.When an interrupt (EIINTn) is masked by this
                                        *    register, it is not accepted.                                            */
        uint32_t : 26;
    } PLMR_b;
} RH850_IRQ_PLMR_Type;

typedef union
{
    __IOM uint32_t EEIC;               /*!< (@ 0x00000200) Extended EI Level Interrupt Control Register
                                        *                  [0..31]                                                        */

    struct
    {
        __IOM uint32_t EIP : 6;        /*!< [5..0] These bits specify 64 interrupt priority levels (0: highest
                                        *   priority, 63: lowestpriority).If two or more EI level interrupt
                                        *   requests are generated simultaneously, a sourcewith higher
                                        *   priority specified by these bits is selected and is sent
                                        *   to the CPUcore. If the priority specified by these bits
                                        *   is equal, a source of less-numberchannel is selected as
                                        *   fixed priority. Please note that the interrupt (EIINTn)
                                        *   withpriority level 63 is not acknowledged in any case.
                                        *   For details, see Section3.2.4.1(5), Interrupt Ex                              */
        uint32_t            : 9;
        __IOM uint32_t EIOV : 1;       /*!< [15..15] Interrupt Overflow0: No interrupt overflow1: EIINTn
                                        *   rose in edge-detection mode (mode_Eict[n] = 0) when EEICn.EIRF=
                                        *   1.This bit is independent of write access to EEICn.EIRF.
                                        *   If EEICn.EIRF=1,EEICn.EIOVn=0, and 1 is written to EEICn.EIRF
                                        *   by 8-bit access, EEICn.EIOV isNOT set.                                        */
        uint32_t            : 6;
        __IOM uint32_t EITB : 1;       /*!< [22..22] Interrupt Vector Method Select0: Direct branching method
                                        *   based on priority1: Table referencing method                                  */
        __IOM uint32_t EIMK : 1;       /*!< [23..23] Interrupt MaskIf this bit is set to 1, interrupt requests
                                        *   set in the interrupt request flag (EIRFn)are masked to
                                        *   inhibit interrupt requests from the channel to the CPU
                                        *   core.Notification of presence of unprocessed interrupts
                                        *   is not made and the PMEI bitin ICSR is not set from channels
                                        *   for which this bit is set to 1.Even when the interrupt
                                        *   request from the channel is masked with EIMKn = 1,the EIRFn
                                        *   still reflects the interrupt request for the channel and
                                        *   can be polled insoftware. When the EIMKn bit is cleare                        */
        uint32_t            : 4;
        __IOM uint32_t EIRF : 1;       /*!< [28..28] Interrupt Request FlagOperation varies with the interrupt
                                        *   input interface.0: No interrupt request (Initial value)1:
                                        *   Interrupt request present• Edge detectionThis flag is
                                        *   automatically cleared to 0 when an interrupt request of
                                        *   thechannel is accepted by the CPU core.• Level detectionThis
                                        *   bit cannot be set or cleared by the software. This is a
                                        *   read-only bit.                                                                */
        uint32_t           : 2;
        __IM uint32_t EICT : 1;        /*!< [31..31] This bit indicates the type of an interrupt detection.
                                        *   This bit is read only.0: Detection with an edge1: Detection
                                        *   of the levelWritten value to this bit must be the value
                                        *   after reset.                                                                  */
    } EEIC_b;
} RH850_IRQ_EEIC_Type;

typedef union
{
    __IOM uint32_t EIBD;               /*!< (@ 0x00000100) EI Level Interrupt Bind Register [0..31]These
                                        *                  registers are provided for each EI level
                                        *                  interrupt source to define binding between
                                        *                  interruptsources and PEs. For details on
                                        *                  each of the interrupt sources, see the Interrupt
                                        *                  table.                                                     */

    struct
    {
        __IM uint32_t PEID : 3;        /*!< [2..0] These bits specify the interrupt bind (request) destination.These
                                        *   bits are fixed in EIBD0 to EIBD31 and cannot be modified.000:
                                        *   Interrupt is bound to PE0.001: Interrupt is bound to PE1.010:
                                        *   Interrupt is bound to PE2.011: Interrupt is bound to PE3.100:
                                        *   Interrupt is bound to PE4.101: Interrupt is bound to PE5.                 */
        uint32_t : 29;
    } EIBD_b;
} RH850_IRQ_EIBD_INTC1_Type;

typedef union
{
    __IOM uint32_t EIBD;               /*!< (@ 0x00002000) EI Level Interrupt Bind Register [32..1023]These
                                        *                  registers are provided for each EI level
                                        *                  interrupt source to define binding between
                                        *                  interruptsources and PEs. For details on
                                        *                  each of the interrupt sources, see the Interrupt
                                        *                  table.                                                     */

    struct
    {
        __IOM uint32_t PEID : 3;       /*!< [2..0] These bits specify the interrupt bind (request) destination.These
                                        *   bits are fixed in EIBD0 to EIBD31 and cannot be modified.000:
                                        *   Interrupt is bound to PE0.001: Interrupt is bound to PE1.010:
                                        *   Interrupt is bound to PE2.011: Interrupt is bound to PE3.100:
                                        *   Interrupt is bound to PE4.101: Interrupt is bound to PE5.                 */
        uint32_t : 29;
    } EIBD_b;
} RH850_IRQ_EIBD_INTC2_Type;

/** @brief Interrupt Function Registers macro Definitions */
/* ================================================================================================================== */
/* ================                                           R_IRQ                                  ================ */
/* ================================================================================================================== */

/* =========================================================  ISPR  ================================================= */
  #define R_IRQ_ISPR_ISP_Pos           (0UL)          /*!< ISP (Bit 0)                                                */
  #define R_IRQ_ISPR_ISP_Msk           (0xffffUL)     /*!< ISP (Bitfield-Mask: 0xffff)                                */
/* =========================================================  IMSR  ================================================= */
  #define R_IRQ_IMSR_FNP_Pos           (4UL)          /*!< FNP (Bit 4)                                                */
  #define R_IRQ_IMSR_FNP_Msk           (0x10UL)       /*!< FNP (Bitfield-Mask: 0x01)                                  */
  #define R_IRQ_IMSR_ENP_Pos           (3UL)          /*!< ENP (Bit 3)                                                */
  #define R_IRQ_IMSR_ENP_Msk           (0x8UL)        /*!< ENP (Bitfield-Mask: 0x01)                                  */
  #define R_IRQ_IMSR_EID_Pos           (2UL)          /*!< EID (Bit 2)                                                */
  #define R_IRQ_IMSR_EID_Msk           (0x4UL)        /*!< EID (Bitfield-Mask: 0x01)                                  */
  #define R_IRQ_IMSR_EPLM_Pos          (1UL)          /*!< EPLM (Bit 1)                                               */
  #define R_IRQ_IMSR_EPLM_Msk          (0x2UL)        /*!< EPLM (Bitfield-Mask: 0x01)                                 */
  #define R_IRQ_IMSR_EEIM_Pos          (0UL)          /*!< EEIM (Bit 0)                                               */
  #define R_IRQ_IMSR_EEIM_Msk          (0x1UL)        /*!< EEIM (Bitfield-Mask: 0x01)                                 */
/* =========================================================  ICSR  ================================================= */
  #define R_IRQ_ICSR_PMEI_Pos          (0UL)          /*!< PMEI (Bit 0)                                               */
  #define R_IRQ_ICSR_PMEI_Msk          (0x1UL)        /*!< PMEI (Bitfield-Mask: 0x01)                                 */
/* ========================================================  INTCFG  ================================================ */
  #define R_IRQ_INTCFG_ULNR_Pos        (16UL)         /*!< ULNR (Bit 16)                                              */
  #define R_IRQ_INTCFG_ULNR_Msk        (0x3f0000UL)   /*!< ULNR (Bitfield-Mask: 0x3f)                                 */
  #define R_IRQ_INTCFG_EPL_Pos         (1UL)          /*!< EPL (Bit 1)                                                */
  #define R_IRQ_INTCFG_EPL_Msk         (0x2UL)        /*!< EPL (Bitfield-Mask: 0x01)                                  */
  #define R_IRQ_INTCFG_ISPC_Pos        (0UL)          /*!< ISPC (Bit 0)                                               */
  #define R_IRQ_INTCFG_ISPC_Msk        (0x1UL)        /*!< ISPC (Bitfield-Mask: 0x01)                                 */
/* =========================================================  PLMR  ================================================= */
  #define R_IRQ_PLMR_PLM_Pos           (0UL)          /*!< PLM (Bit 0)                                                */
  #define R_IRQ_PLMR_PLM_Msk           (0x3fUL)       /*!< PLM (Bitfield-Mask: 0x3f)                                  */
/* =========================================================  EEIC  ================================================= */
  #define R_IRQ_EEIC_EICT_Pos          (31UL)         /*!< EICT (Bit 31)                                              */
  #define R_IRQ_EEIC_EICT_Msk          (0x80000000UL) /*!< EICT (Bitfield-Mask: 0x01)                                 */
  #define R_IRQ_EEIC_EIRF_Pos          (28UL)         /*!< EIRF (Bit 28)                                              */
  #define R_IRQ_EEIC_EIRF_Msk          (0x10000000UL) /*!< EIRF (Bitfield-Mask: 0x01)                                 */
  #define R_IRQ_EEIC_EIMK_Pos          (23UL)         /*!< EIMK (Bit 23)                                              */
  #define R_IRQ_EEIC_EIMK_Msk          (0x800000UL)   /*!< EIMK (Bitfield-Mask: 0x01)                                 */
  #define R_IRQ_EEIC_EITB_Pos          (22UL)         /*!< EITB (Bit 22)                                              */
  #define R_IRQ_EEIC_EITB_Msk          (0x400000UL)   /*!< EITB (Bitfield-Mask: 0x01)                                 */
  #define R_IRQ_EEIC_EIOV_Pos          (15UL)         /*!< EIOV (Bit 15)                                              */
  #define R_IRQ_EEIC_EIOV_Msk          (0x8000UL)     /*!< EIOV (Bitfield-Mask: 0x01)                                 */
  #define R_IRQ_EEIC_EIP_Pos           (0UL)          /*!< EIP (Bit 0)                                                */
  #define R_IRQ_EEIC_EIP_Msk           (0x3fUL)       /*!< EIP (Bitfield-Mask: 0x3f)                                  */
/* =========================================================  EIBD  ================================================= */
  #define R_IRQ_INTC1_EIBD_PEID_Pos    (0UL)          /*!< PEID (Bit 0)                                               */
  #define R_IRQ_INTC1_EIBD_PEID_Msk    (0x7UL)        /*!< PEID (Bitfield-Mask: 0x07)                                 */

/*@}*/ /* end of group RH850_G4MH_IRQ */

/**
 * @ingroup  RH850_G4MH_Core_register
 * @defgroup RH850_G4MH_FPU     FPU Function Registers (FPU)
 * @brief    Type definitions for the FPU Function Registers (FPU)
 * @{
 */

/**
 * @brief  Structure type to access the FPU Function Registers (SYS).
 */

typedef union
{
    __IOM uint32_t FPSR;               /*!< (@ 0x00000000) Floating-point Configuration/Status                        */

    struct
    {
        __IOM uint32_t XP : 5;         /*!< [4..0] These are the preservation bits.                                   */
        __IOM uint32_t XE : 5;         /*!< [9..5] These are the enable bits.                                         */
        __IOM uint32_t XC : 6;         /*!< [15..10] These are the cause bits.                                        */
        uint32_t          : 1;
        __IOM uint32_t FS : 1;         /*!< [17..17] This bit enables values that could not be normalized
                                        *    (subnormal numbers) tobe flushed. If the FS bit is set,
                                        *    input operands and operation results that aresubnormal
                                        *    numbers are flushed without causing an unimplemented operationexception
                                        *    (E). An input operand that is a subnormal number is flushed
                                        *    to 0with the same sign. Operation results that are subnormal
                                        *    numbers eitherbecome 0 or the minimum normalized number,
                                        *    depending on the roundingmode.                                           */
        __IOM uint32_t RM : 2;         /*!< [19..18] These are the rounding mode control bits. The RM bits
                                        *    define the roundingmode that the FPU uses for all floating-point
                                        *    instructions.                                                            */
        uint32_t           : 1;
        __IOM uint32_t PEM : 1;        /*!< [21..21] This bit specifies whether to handle an exception as
                                        *    a precise exception. If thePEM bit is 1, exceptions that
                                        *    are caused by the execution of a floating-pointoperation
                                        *    instruction are handled as precise exceptions.                           */
        __IOM uint32_t IF : 1;         /*!< [22..22] This bit accumulates and indicates information about
                                        *    the flushing of inputoperands. For details about flushing
                                        *    subnormal numbers, see Section 3.2.6.1(8), Flushing Subnormal
                                        *    Numbers.                                                                 */
        __IOM uint32_t FN : 1;         /*!< [23..23] This bit enables flush-to-nearest mode. When the FN
                                        *    bit is set to 1, if therounding mode is RN and the operation
                                        *    result is a subnormal number, thenumber is flushed to the
                                        *    nearest number. For details, see Section 3.2.6.1 (9),Flush
                                        *    to Nearest.                                                              */
        __IOM uint32_t CC : 8;         /*!< [31..24] These are the CC (condition) bits. They store the results
                                        *    of floating-pointcomparison instructions. The CC7 to CC0
                                        *    bits are not affected by anyinstructions except the comparison
                                        *    instruction and LDSR instruction.0: Comparison result is
                                        *    false1: Comparison result is true                                        */
    } FPSR_b;
} RH850_FPU_FPSR_Type;

typedef union
{
    __IOM uint32_t FPEPC;              /*!< (@ 0x00000000) Floating-point Exception Program Counter                   */

    struct
    {
        __IM uint32_t FPEPC0 : 1;      /*!< [0..0] This bit stores the program counter (PC) of the floating-point
                                        *    instruction thatcaused the exception when a floating-point
                                        *    operation exception that isenabled by an enable bit occurs.              */
        uint32_t             : 30;
        __IOM uint32_t FPEPC : 1;      /*!< [31..31] These bits store the program counter (PC) of the floating-point
                                        *    instruction thatcaused the exception when a floating-point
                                        *    operation exception that isenabled by an enable bit occurs.              */
    } FPEPC_b;
} RH850_FPU_FPEPC_Type;

typedef union
{
    __IOM uint32_t FPST;               /*!< (@ 0x00000000) Floating-point Operation Status                            */

    struct
    {
        __IOM uint32_t XP : 5;         /*!< [4..0] These are preservation bits. For details, see Section
                                        *    3.2.3.4(1),Preservation Bits (XP). Values written to these
                                        *    bits are reflected inFPSR.XP bits.                                       */
        __IOM uint32_t IF : 1;         /*!< [5..5] This bit accumulates and indicates information about
                                        *    the flushing of inputoperands. For details about flushing
                                        *    subnormal numbers, see Section3.2.6.1 (8), Flushing Subnormal
                                        *    Numbers. Value written to this bit isreflected in FPSR.IF
                                        *    bit.                                                                     */
        uint32_t          : 2;
        __IOM uint32_t XC : 6;         /*!< [13..8] These are cause bits. For details, see Section 3.2.3.4(1),
                                        *    Cause Bits (XC).Values written to these bits are reflected
                                        *    in FPSR.XC bits.                                                         */
        uint32_t : 18;
    } FPST_b;
} RH850_FPU_FPST_Type;

typedef union
{
    __IOM uint32_t FPCC;               /*!< (@ 0x00000000) Floating-point Operation Comparison Result                 */

    struct
    {
        __IOM uint32_t CC : 8;         /*!< [7..0] These are CC (condition) bits. They store the result
                                        *    of a floating-pointcomparison instruction. The CC7 to CC0
                                        *    bits are not affected by anyinstructions except the comparison
                                        *    instruction and LDSR instruction. Valueswritten to these
                                        *    bits are reflected in the CC7 to CC0 bits of FPSR.0: Comparison
                                        *    result is false1: Comparison result is true                              */
        uint32_t : 24;
    } FPCC_b;
} RH850_FPU_FPCC_Type;

typedef union
{
    __IOM uint32_t FPCFG;              /*!< (@ 0x00000000) Floating-point Operation Configuration                     */

    struct
    {
        __IOM uint32_t XE : 5;         /*!< [4..0] These are the enable bits. For details, see Section 3.2.3.4(1),
                                        *    Enable Bits(XE). Values written to these bits are reflected
                                        *    in the FPSR.XE bits                                                      */
        uint32_t          : 3;
        __IOM uint32_t RM : 2;         /*!< [9..8] These are rounding mode control bits. The RM bits define
                                        *    the rounding modethat the FPU uses for all floating-point
                                        *    instructions. Values written to these bitsare reflected
                                        *    in RM bits of FPSR.                                                      */
        uint32_t : 22;
    } FPCFG_b;
} RH850_FPU_FPCFG_Type;

/** @brief FPU Function Registers macro Definitions */

/* ================================================================================================================== */
/* ================                                           R_FPU                                  ================ */
/* ================================================================================================================== */

/* =========================================================  FPSR  ================================================= */
  #define R_FPU_FPSR_CC_Pos         (24UL)         /*!< CC (Bit 24)                                                   */
  #define R_FPU_FPSR_CC_Msk         (0xff000000UL) /*!< CC (Bitfield-Mask: 0xff)                                      */
  #define R_FPU_FPSR_FN_Pos         (23UL)         /*!< FN (Bit 23)                                                   */
  #define R_FPU_FPSR_FN_Msk         (0x800000UL)   /*!< FN (Bitfield-Mask: 0x01)                                      */
  #define R_FPU_FPSR_IF_Pos         (22UL)         /*!< IF (Bit 22)                                                   */
  #define R_FPU_FPSR_IF_Msk         (0x400000UL)   /*!< IF (Bitfield-Mask: 0x01)                                      */
  #define R_FPU_FPSR_PEM_Pos        (21UL)         /*!< PEM (Bit 21)                                                  */
  #define R_FPU_FPSR_PEM_Msk        (0x200000UL)   /*!< PEM (Bitfield-Mask: 0x01)                                     */
  #define R_FPU_FPSR_RM_Pos         (18UL)         /*!< RM (Bit 18)                                                   */
  #define R_FPU_FPSR_RM_Msk         (0xc0000UL)    /*!< RM (Bitfield-Mask: 0x03)                                      */
  #define R_FPU_FPSR_FS_Pos         (17UL)         /*!< FS (Bit 17)                                                   */
  #define R_FPU_FPSR_FS_Msk         (0x20000UL)    /*!< FS (Bitfield-Mask: 0x01)                                      */
  #define R_FPU_FPSR_XC_Pos         (10UL)         /*!< XC (Bit 10)                                                   */
  #define R_FPU_FPSR_XC_Msk         (0xfc00UL)     /*!< XC (Bitfield-Mask: 0x3f)                                      */
  #define R_FPU_FPSR_XE_Pos         (5UL)          /*!< XE (Bit 5)                                                    */
  #define R_FPU_FPSR_XE_Msk         (0x3e0UL)      /*!< XE (Bitfield-Mask: 0x1f)                                      */
  #define R_FPU_FPSR_XP_Pos         (0UL)          /*!< XP (Bit 0)                                                    */
  #define R_FPU_FPSR_XP_Msk         (0x1fUL)       /*!< XP (Bitfield-Mask: 0x1f)                                      */
/* =========================================================  FPEPC  ================================================ */
  #define R_FPU_FPEPC_FPEPC_Pos     (31UL)         /*!< FPEPC (Bit 31)                                                */
  #define R_FPU_FPEPC_FPEPC_Msk     (0x80000000UL) /*!< FPEPC (Bitfield-Mask: 0x01)                                   */
  #define R_FPU_FPEPC_FPEPC0_Pos    (0UL)          /*!< FPEPC0 (Bit 0)                                                */
  #define R_FPU_FPEPC_FPEPC0_Msk    (0x1UL)        /*!< FPEPC0 (Bitfield-Mask: 0x01)                                  */
/* =========================================================  FPST  ================================================= */
  #define R_FPU_FPST_XC_Pos         (8UL)          /*!< XC (Bit 8)                                                    */
  #define R_FPU_FPST_XC_Msk         (0x3f00UL)     /*!< XC (Bitfield-Mask: 0x3f)                                      */
  #define R_FPU_FPST_IF_Pos         (5UL)          /*!< IF (Bit 5)                                                    */
  #define R_FPU_FPST_IF_Msk         (0x20UL)       /*!< IF (Bitfield-Mask: 0x01)                                      */
  #define R_FPU_FPST_XP_Pos         (0UL)          /*!< XP (Bit 0)                                                    */
  #define R_FPU_FPST_XP_Msk         (0x1fUL)       /*!< XP (Bitfield-Mask: 0x1f)                                      */
/* =========================================================  FPCC  ================================================= */
  #define R_FPU_FPCC_CC_Pos         (0UL)          /*!< CC (Bit 0)                                                    */
  #define R_FPU_FPCC_CC_Msk         (0xffUL)       /*!< CC (Bitfield-Mask: 0xff)                                      */
/* =========================================================  FPCFG  ================================================ */
  #define R_FPU_FPCFG_RM_Pos        (8UL)          /*!< RM (Bit 8)                                                    */
  #define R_FPU_FPCFG_RM_Msk        (0x300UL)      /*!< RM (Bitfield-Mask: 0x03)                                      */
  #define R_FPU_FPCFG_XE_Pos        (0UL)          /*!< XE (Bit 0)                                                    */
  #define R_FPU_FPCFG_XE_Msk        (0x1fUL)       /*!< XE (Bitfield-Mask: 0x1f)                                      */

/*@}*/ /* end of group RH850_G4MH_FPU */

/**
 * @ingroup  RH850_G4MH_Core_register
 * @defgroup RH850_G4MH_FXU     FXU Function Registers (FXU)
 * @brief    Type definitions for the FXU Function Registers (FXU)
 * @{
 */

/**
 * @brief  Structure type to access the FXU Function Registers (FXU).
 */

typedef union
{
    __IOM uint32_t FXSR;               /*!< (@ 0x00000000) Extended Floating-point Operation Configuration/Status     */

    struct
    {
        __IOM uint32_t XP : 5;         /*!< [4..0] These are the preservation bits                                    */
        __IOM uint32_t XE : 5;         /*!< [9..5] These are the enable bits                                          */
        __IOM uint32_t XC : 6;         /*!< [15..10] These are the cause bits                                         */
        uint32_t          : 1;
        __IOM uint32_t FS : 1;         /*!< [17..17] This bit enables values that could not be normalized
                                        *    (subnormal numbers) tobe flushed. If the FS bit is set,
                                        *    input operands and operation results that aresubnormal
                                        *    numbers are flushed without causing an unimplemented operationexception
                                        *    (E). An input operand that is a subnormal number is flushed
                                        *    to 0with the same sign. Operation results that are subnormal
                                        *    numbers eitherbecome 0 or the minimum normalized number,
                                        *    depending on the roundingmode.                                           */
        __IOM uint32_t RM : 2;         /*!< [19..18] These are the rounding mode control bits. The RM bits
                                        *    define the roundingmode that the FXU uses for all extended
                                        *    floating-point instructions                                              */
        uint32_t          : 2;
        __IOM uint32_t IF : 1;         /*!< [22..22] This bit accumulates and indicates information about
                                        *    the flushing of inputoperands. For details about flushing
                                        *    subnormal numbers, see Section 3.2.6.2Section 3.2.6.1 (8),
                                        *    Flushing Subnormal Numbers.                                              */
        __IOM uint32_t FN : 1;         /*!< [23..23] This bit enables flush-to-nearest mode. When the FN
                                        *    bit is set to 1, if therounding mode is RN and the operation
                                        *    result is a subnormal number, thenumber is flushed to the
                                        *    nearest number. For details, see Section 3.2.6.1 (9),Flush
                                        *    to Nearest.                                                              */
        uint32_t : 8;
    } FXSR_b;
} RH850_FXU_FXSR_Type;

typedef union
{
    __IOM uint32_t FXST;               /*!< (@ 0x00000000) Extended Floating-point Operation Status                   */

    struct
    {
        __IOM uint32_t XP : 5;         /*!< [4..0] These are preservation bits. For details, see Section
                                        *    3.2.3.4(1), PreservationBits (XP). Values written to these
                                        *    bits are reflected in FXSR.XP bits.                                      */
        __IOM uint32_t IF : 1;         /*!< [5..5] This bit accumulates and indicates information about
                                        *    the flushing of inputoperands. For details about flushing
                                        *    subnormal numbers, see Section 3.2.6.1(8), Flushing Subnormal
                                        *    Numbers. Value written to this bit is reflected inFXSR.IF
                                        *    bit.                                                                     */
        uint32_t          : 2;
        __IOM uint32_t XC : 6;         /*!< [13..8] These are cause bits. For details, see Section 3.2.3.4(1),
                                        *    Cause Bits (XC).Values written to these bits are reflected
                                        *    in FXSR.XC bits.                                                         */
        uint32_t : 18;
    } FXST_b;
} RH850_FXU_FXST_Type;

typedef union
{
    __IOM uint32_t FXINFO;             /*!< (@ 0x00000000) FXU Configuration Information                              */

    struct
    {
        __IM uint32_t RSIZE : 1;       /*!< [0..0] This bit indicates that 32 128-bit vector registers are
                                        *    provided.                                                                */
        __IM uint32_t NFPU : 1;        /*!< [1..1] This bit indicates that 4-way SIMD arithmetic unit is
                                        *    provided.                                                                */
        uint32_t : 30;
    } FXINFO_b;
} RH850_FXU_FXINFO_Type;

typedef union
{
    __IOM uint32_t FXCFG;              /*!< (@ 0x00000000) Extended Floating-point Operation Configuration            */

    struct
    {
        __IOM uint32_t XE : 5;         /*!< [4..0] These are the enable bits. For details, see Section 3.2.3.4(1),
                                        *    Enable Bits(XE).Values written to these bits are reflected
                                        *    in FXSR.XE bits.                                                         */
        uint32_t          : 3;
        __IOM uint32_t RM : 2;         /*!< [9..8] These are the rounding mode control bits. The RM bits
                                        *    define the roundingmode that the FXU uses for all extended
                                        *    floating-point instructions. Valueswritten to these bits
                                        *    are reflected in FXSR.RM bits.                                           */
        uint32_t : 22;
    } FXCFG_b;
} RH850_FXU_FXCFG_Type;

typedef union
{
    __IOM uint32_t FXXC;               /*!< (@ 0x00000000) XC (Cause) Bits for Each operation way                     */

    struct
    {
        __IOM uint32_t XC0 : 6;        /*!< [5..0] These bits hold the cause bits associated with operation
                                        *    way 0.                                                                   */
        uint32_t           : 2;
        __IOM uint32_t XC1 : 6;        /*!< [13..8] These bits hold the cause bits associated with operation
                                        *    way 1.                                                                   */
        uint32_t           : 2;
        __IOM uint32_t XC2 : 6;        /*!< [21..16] These bits hold the cause bits associated with operation
                                        *    way 2.                                                                   */
        uint32_t           : 2;
        __IOM uint32_t XC3 : 6;        /*!< [29..24] These bits hold the cause bits associated with operation
                                        *    way 3.                                                                   */
        uint32_t : 2;
    } FXXC_b;
} RH850_FXU_FXXC_Type;

typedef union
{
    __IOM uint32_t FXXP;               /*!< (@ 0x00000000) XP (Preservation) Bits for Each operation way              */

    struct
    {
        __IOM uint32_t XP0 : 6;        /*!< [5..0] These bits hold the preservation bits associated with
                                        *    operation way 0.                                                         */
        uint32_t           : 2;
        __IOM uint32_t XP1 : 6;        /*!< [13..8] These bits hold the preservation bits associated with
                                        *    operation way 1.                                                         */
        uint32_t           : 2;
        __IOM uint32_t XP2 : 6;        /*!< [21..16] These bits hold the preservation bits associated with
                                        *    operation way 2.                                                         */
        uint32_t           : 2;
        __IOM uint32_t XP3 : 6;        /*!< [29..24] These bits hold the preservation bits associated with
                                        *    operation way 3.                                                         */
        uint32_t : 2;
    } FXXP_b;
} RH850_FXU_FXXP_Type;

/** @brief FXU Function Registers macro Definitions */

/* ================================================================================================================== */
/* ================                                           R_FXU                                  ================ */
/* ================================================================================================================== */

/* =========================================================  FXSR  ================================================= */
  #define R_FXU_FXSR_FN_Pos         (23UL)         /*!< FN (Bit 23)                                                   */
  #define R_FXU_FXSR_FN_Msk         (0x800000UL)   /*!< FN (Bitfield-Mask: 0x01)                                      */
  #define R_FXU_FXSR_IF_Pos         (22UL)         /*!< IF (Bit 22)                                                   */
  #define R_FXU_FXSR_IF_Msk         (0x400000UL)   /*!< IF (Bitfield-Mask: 0x01)                                      */
  #define R_FXU_FXSR_RM_Pos         (18UL)         /*!< RM (Bit 18)                                                   */
  #define R_FXU_FXSR_RM_Msk         (0xc0000UL)    /*!< RM (Bitfield-Mask: 0x03)                                      */
  #define R_FXU_FXSR_FS_Pos         (17UL)         /*!< FS (Bit 17)                                                   */
  #define R_FXU_FXSR_FS_Msk         (0x20000UL)    /*!< FS (Bitfield-Mask: 0x01)                                      */
  #define R_FXU_FXSR_XC_Pos         (10UL)         /*!< XC (Bit 10)                                                   */
  #define R_FXU_FXSR_XC_Msk         (0xfc00UL)     /*!< XC (Bitfield-Mask: 0x3f)                                      */
  #define R_FXU_FXSR_XE_Pos         (5UL)          /*!< XE (Bit 5)                                                    */
  #define R_FXU_FXSR_XE_Msk         (0x3e0UL)      /*!< XE (Bitfield-Mask: 0x1f)                                      */
  #define R_FXU_FXSR_XP_Pos         (0UL)          /*!< XP (Bit 0)                                                    */
  #define R_FXU_FXSR_XP_Msk         (0x1fUL)       /*!< XP (Bitfield-Mask: 0x1f)                                      */
/* =========================================================  FXST  ================================================= */
  #define R_FXU_FXST_XC_Pos         (8UL)          /*!< XC (Bit 8)                                                    */
  #define R_FXU_FXST_XC_Msk         (0x3f00UL)     /*!< XC (Bitfield-Mask: 0x3f)                                      */
  #define R_FXU_FXST_IF_Pos         (5UL)          /*!< IF (Bit 5)                                                    */
  #define R_FXU_FXST_IF_Msk         (0x20UL)       /*!< IF (Bitfield-Mask: 0x01)                                      */
  #define R_FXU_FXST_XP_Pos         (0UL)          /*!< XP (Bit 0)                                                    */
  #define R_FXU_FXST_XP_Msk         (0x1fUL)       /*!< XP (Bitfield-Mask: 0x1f)                                      */
/* ========================================================  FXINFO  ================================================ */
  #define R_FXU_FXINFO_NFPU_Pos     (1UL)          /*!< NFPU (Bit 1)                                                  */
  #define R_FXU_FXINFO_NFPU_Msk     (0x2UL)        /*!< NFPU (Bitfield-Mask: 0x01)                                    */
  #define R_FXU_FXINFO_RSIZE_Pos    (0UL)          /*!< RSIZE (Bit 0)                                                 */
  #define R_FXU_FXINFO_RSIZE_Msk    (0x1UL)        /*!< RSIZE (Bitfield-Mask: 0x01)                                   */
/* =========================================================  FXCFG  ================================================ */
  #define R_FXU_FXCFG_RM_Pos        (8UL)          /*!< RM (Bit 8)                                                    */
  #define R_FXU_FXCFG_RM_Msk        (0x300UL)      /*!< RM (Bitfield-Mask: 0x03)                                      */
  #define R_FXU_FXCFG_XE_Pos        (0UL)          /*!< XE (Bit 0)                                                    */
  #define R_FXU_FXCFG_XE_Msk        (0x1fUL)       /*!< XE (Bitfield-Mask: 0x1f)                                      */
/* =========================================================  FXXC  ================================================= */
  #define R_FXU_FXXC_XC3_Pos        (24UL)         /*!< XC3 (Bit 24)                                                  */
  #define R_FXU_FXXC_XC3_Msk        (0x3f000000UL) /*!< XC3 (Bitfield-Mask: 0x3f)                                     */
  #define R_FXU_FXXC_XC2_Pos        (16UL)         /*!< XC2 (Bit 16)                                                  */
  #define R_FXU_FXXC_XC2_Msk        (0x3f0000UL)   /*!< XC2 (Bitfield-Mask: 0x3f)                                     */
  #define R_FXU_FXXC_XC1_Pos        (8UL)          /*!< XC1 (Bit 8)                                                   */
  #define R_FXU_FXXC_XC1_Msk        (0x3f00UL)     /*!< XC1 (Bitfield-Mask: 0x3f)                                     */
  #define R_FXU_FXXC_XC0_Pos        (0UL)          /*!< XC0 (Bit 0)                                                   */
  #define R_FXU_FXXC_XC0_Msk        (0x3fUL)       /*!< XC0 (Bitfield-Mask: 0x3f)                                     */
/* =========================================================  FXXP  ================================================= */
  #define R_FXU_FXXP_XP3_Pos        (24UL)         /*!< XP3 (Bit 24)                                                  */
  #define R_FXU_FXXP_XP3_Msk        (0x3f000000UL) /*!< XP3 (Bitfield-Mask: 0x3f)                                     */
  #define R_FXU_FXXP_XP2_Pos        (16UL)         /*!< XP2 (Bit 16)                                                  */
  #define R_FXU_FXXP_XP2_Msk        (0x3f0000UL)   /*!< XP2 (Bitfield-Mask: 0x3f)                                     */
  #define R_FXU_FXXP_XP1_Pos        (8UL)          /*!< XP1 (Bit 8)                                                   */
  #define R_FXU_FXXP_XP1_Msk        (0x3f00UL)     /*!< XP1 (Bitfield-Mask: 0x3f)                                     */
  #define R_FXU_FXXP_XP0_Pos        (0UL)          /*!< XP0 (Bit 0)                                                   */
  #define R_FXU_FXXP_XP0_Msk        (0x3fUL)       /*!< XP0 (Bitfield-Mask: 0x3f)                                     */

/*@}*/ /* end of group RH850_G4MH_FXU */

/**
 * @ingroup  RH850_G4MH_Core_register
 * @defgroup RH850_G4MH_MPU     MPU Function Registers (MPU)
 * @brief    Type definitions for the MPU Function Registers (MPU)
 * @{
 */

/**
 * @brief  Structure type to access the MPU Function Registers (MPU).
 */

typedef union
{
    __IOM uint32_t MPM;                /*!< (@ 0x00000000) Memory Protection Operation Mode                           */

    struct
    {
        __IOM uint32_t MPE : 1;        /*!< [0..0] Memory protection enable
                                        *    0: MPU is disabled. 1: MPU is enabled.                                   */
        __IOM uint32_t SVP : 1;        /*!< [1..1] Supervisor-mode access permission control
                                        *    0: All accesses enabled in SV mode. 1: Restrict per SX/SW/SR.            */
        uint32_t : 30;
    } MPM_b;
} RH850_MPU_MPM_Type;

typedef union
{
    __IOM uint32_t MPCFG;              /*!< (@ 0x00000000) MPU Configuration                                          */

    struct
    {
        __IM uint32_t NMPUE : 5;       /*!< [4..0] These bits indicate the number of MPU entries implemented
                                        *    in this CPUminus 1. A value of 31 is read since this CPU
                                        *    incorporates 32 MPUentries.                                              */
        uint32_t           : 11;
        __IM uint32_t ARCH : 4;        /*!< [19..16] These bits indicate the MPU architecture specification
                                        *    version implemented by this CPU.                                         */
        __IM uint32_t NBK : 2;         /*!< [21..20] Indicates the "number of banks - 1" of the MPU bank
                                        * 2 equipped in thisCPU.Since the MPU bank of this CPU is
                                        *    equipped with one bank, 0 is read.                                       */
        uint32_t : 10;
    } MPCFG_b;
} RH850_MPU_MPCFG_Type;

typedef union
{
    __IOM uint32_t MCA;                /*!< (@ 0x00000000) Memory Protection Setting Check Address                    */

    struct
    {
        __IOM uint32_t MCA : 32;       /*!< [31..0] These bits are used to specify the starting address
                                        *    of the memory areawhich subjects to a memory protection
                                        *    setting check in bytes.                                                  */
    } MCA_b;
} RH850_MPU_MCA_Type;

typedef union
{
    __IOM uint32_t MCS;                /*!< (@ 0x00000000) Memory Protection Setting Check Size                       */

    struct
    {
        __IOM uint32_t MCS : 32;       /*!< [31..0] These bits are used to specify the size of the memory
                                        *    area in bytes whichsubjects to a memory protection setting
                                        *    check. Because the specified sizeis assumed to represent
                                        *    an unsigned integer, it is not possible to check anarea
                                        *    in the direction in which the address value decreases relative
                                        *    to theMCA register value.                                                */
    } MCS_b;
} RH850_MPU_MCS_Type;

typedef union
{
    __IOM uint32_t MCC;                /*!< (@ 0x00000000) Memory Protection Setting Check Command                    */

    struct
    {
        __IOM uint32_t MCC : 32;       /*!< [31..0] When any value is written to the MCC register, a memory
                                        *    protection settingcheck starts. By setting up the MCA /
                                        *    MCS register and then writing to theMCC register, results
                                        *    are stored in MCR. Because the check is started by anywritten
                                        *    value, a check can be started by using r0 as the source
                                        *    register withoutusing any unnecessary registers.Note that,
                                        *    for the check, the results are applied according to each
                                        *    area settingregardless of the state of the PSW.UM bit.This
                                        *    checking applies for memory protec                                       */
    } MCC_b;
} RH850_MPU_MCC_Type;

typedef union
{
    __IOM uint32_t MCR;                /*!< (@ 0x00000000) Memory Protection Setting Check Result                     */

    struct
    {
        __IOM uint32_t URE : 1;        /*!< [0..0] If the specified area is contained within one protection
                                        *    area and reading fromthat area is permitted in user mode,
                                        *    1 is stored in this bit. In other cases, 0 isstored in
                                        *    this bit.                                                                */
        __IOM uint32_t UWE : 1;        /*!< [1..1] If the specified area is contained within one protection
                                        *    area and writing fromthat area is permitted in user mode,
                                        *    1 is stored in this bit. In other cases, 0 isstored in
                                        *    this bit.                                                                */
        __IOM uint32_t UXE : 1;        /*!< [2..2] If the specified area is contained within one protection
                                        *    area and execution ispermitted for that area in user mode,
                                        *    1 is stored in this bit. In other cases, 0 isstored in
                                        *    this bit.                                                                */
        __IOM uint32_t SRE : 1;        /*!< [3..3] If the specified area is contained within one protection
                                        *    area and reading fromthat area is permitted in supervisor
                                        *    mode, 1 is stored in this bit. In other cases,0 is stored
                                        *    in this bit.                                                             */
        __IOM uint32_t SWE : 1;        /*!< [4..4] If the specified area is contained within one protection
                                        *    area and writing to thatarea is permitted in supervisor
                                        *    mode, 1 is stored in this bit. In other cases, 0 isstored
                                        *    in this bit.                                                             */
        __IOM uint32_t SXE : 1;        /*!< [5..5] If the specified area is contained within one protection
                                        *    area and execution ispermitted for that area in supervisor
                                        *    mode, 1 is stored in this bit. In othercases, 0 is stored
                                        *    in this bit.                                                             */
        uint32_t          : 2;
        __IOM uint32_t OV : 1;         /*!< [8..8] If the specified area includes 0000 0000H or 7FFF FFFFH,
                                        *    1 is stored in thisbit. In other cases, 0 is stored in
                                        *    this bit.                                                                */
        uint32_t : 23;
    } MCR_b;
} RH850_MPU_MCR_Type;

typedef union
{
    __IOM uint32_t MCI;                /*!< (@ 0x00000000) Memory Protection Setting Check SPID                       */

    struct
    {
        __IOM uint32_t SPID : 5;       /*!< [4..0] These bits specify the SPID for which a memory protection
                                        *    settings check is tobe performed.                                        */
        uint32_t : 27;
    } MCI_b;
} RH850_MPU_MCI_Type;

typedef union
{
    __IOM uint32_t MPIDX;              /*!< (@ 0x00000000) Index of Memory Protection Setting Registers
                                        *                  to be Accessed                                             */

    struct
    {
        __IOM uint32_t IDX : 5;        /*!< [4..0] These bits specify the SPID for which a memory protection
                                        *    settings check is tobe performed.                                        */
        uint32_t : 27;
    } MPIDX_b;
} RH850_MPU_MPIDX_Type;

typedef union
{
    __IOM uint32_t MPBK;               /*!< (@ 0x00000000) MPU Bank Setting                                           */

    struct
    {
        __IOM uint32_t BK : 2;         /*!< [1..0] These bits specify the SPID for which a memory protection
                                        *    settings check is tobe performed.                                        */
        uint32_t : 30;
    } MPBK_b;
} RH850_MPU_MPBK_Type;

typedef union
{
    __IOM uint32_t MPLA;               /*!< (@ 0x00000000) Base Address of the Interrupt Handler Address
                                        *                  Table                                                      */

    struct
    {
        uint32_t            : 2;
        __IOM uint32_t MPLA : 30;      /*!< [31..2] These bits specify the minimum address of area n (n
                                        *    = 0 to MPCFG.NMPUE)specified by the MPIDX register.The
                                        *    specified minimum address is included in the range of area
                                        *    matching.                                                                */
    } MPLA_b;
} RH850_MPU_MPLA_Type;

typedef union
{
    __IOM uint32_t MPUA;               /*!< (@ 0x00000000) Protection Area Maximum Address                            */

    struct
    {
        uint32_t            : 2;
        __IOM uint32_t MPUA : 30;      /*!< [31..2] These bits specify the maximum address of area n (n
                                        *    = 0 to MPCFG.NMPUE)specified by the MPIDX register.The
                                        *    specified maximum address is included in the range of area
                                        *    matching.Bits 1 and 0 of the maximum address are handled
                                        *    as 1.                                                                    */
    } MPUA_b;
} RH850_MPU_MPUA_Type;

typedef union
{
    __IOM uint32_t MPAT;               /*!< (@ 0x00000000) Protection Area Attribute                                  */

    struct
    {
        __IOM uint32_t UR : 1;         /*!< [0..0] This bit indicates the read permission in the user mode
                                        *    for area n (n = 0 toMPCFG.NMPUE) specified by the MPIDX
                                        *    register.*20: Reading is disabled.1: Reading is enabled.                 */
        __IOM uint32_t UW : 1;         /*!< [1..1] This bit indicates the write permission in the user mode
                                        *    for area n (n = 0 toMPCFG.NMPUE) specified by the MPIDX
                                        *    register.0: Writing is disabled.1: Writing is enabled.                   */
        __IOM uint32_t UX : 1;         /*!< [2..2] This bit indicates the execution permission in the user
                                        *    mode for area n (n = 0to MPCFG.NMPUE) specified by the
                                        *    MPIDX register.0: Execution is disabled.1: Execution is
                                        *    enabled.                                                                 */
        __IOM uint32_t SR : 1;         /*!< [3..3] This bit indicates the read permission in the supervisor
                                        *    mode for area n (n = 0to MPCFG.NMPUE) specified by the
                                        *    MPIDX register.*1, *20: Reading is disabled.1: Reading
                                        *    is enabled.                                                              */
        __IOM uint32_t SW : 1;         /*!< [4..4] This bit indicates the write permission in the supervisor
                                        *    mode for area n (n = 0to MPCFG.NMPUE) specified by the
                                        *    MPIDX register.*10: Writing is disabled.1: Writing is enabled.           */
        __IOM uint32_t SX : 1;         /*!< [5..5] This bit indicates the execution permission in the supervisor
                                        *    mode for area n(n = 0 to MPCFG.NMPUE) specified by the
                                        *    MPIDX register.*10: Execution is disabled.1: Execution
                                        *    is enabled.                                                              */
        uint32_t         : 1;
        __IOM uint32_t E : 1;          /*!< [7..7] This bit indicates whether area n (n = 0 to MPCFG.NMPUE)
                                        *    specified by theMPIDX register is enabled or disabled.0:
                                        *    Area n is disabled.1: Area n is enabled.                                 */
        uint32_t          : 6;
        __IOM uint32_t RG : 1;         /*!< [14..14] This bit indicates the execution and read permissions
                                        *    for any SPID.0: Execution and reading is enabled by the
                                        *    settings of the MPIDn registerand RMPIDn bit (n = 0 to
                                        *    7).1: Execution and reading by any SPID is enabled regardless
                                        *    of the settingsof the MPIDn register and RMPIDn bit (n
                                        *    = 0 to 7).                                                               */
        __IOM uint32_t WG : 1;         /*!< [15..15] This bit indicates the write permission for any SPID.0:
                                        *    Writing is enabled by the settings of the MPIDn register
                                        *    and WMPIDn bit(n = 0 to 7).1: Writing by any SPID is enabled
                                        *    regardless of the settings of the MPIDnregister and WMPIDn
                                        *    bit (n = 0 to 7).                                                        */
        __IOM uint32_t RMPID : 8;      /*!< [23..16] This bit indicates the execution and read permissions
                                        *    for the SPID specified inthe MPIDn (n = 0 to 7) register.0:
                                        *    Execution and reading by the SPID specified by the MPIDn
                                        *    register isdisabled.1: Execution and reading by the SPID
                                        *    specified by the MPIDn register isenabled.                               */
        __IOM uint32_t WMPID : 8;      /*!< [31..24] This bit indicates the write permission for the SPID
                                        *    specified in the MPIDn (n =0 to 7) register.0: Writing
                                        *    by the SPID specified by the MPIDn register is disabled.1:
                                        *    Writing by the SPID specified by the MPIDn register is
                                        *    enabled.                                                                 */
    } MPAT_b;
} RH850_MPU_MPAT_Type;

typedef union
{
    __IOM uint32_t MPID;               /*!< (@ 0x00000000) SPID which can Access Protection Area                      */

    struct
    {
        __IOM uint32_t SPID : 5;       /*!< [4..0] These bits specify the SPID which can access protection
                                        *    area.                                                                    */
        uint32_t : 27;
    } MPID_b;
} RH850_MPU_MPID_Type;

/** @brief MPU Function Registers macro Definitions */

/* ================================================================================================================== */
/* ================                                           R_MPU                                  ================ */
/* ================================================================================================================== */

/* ==========================================================  MPM  ================================================= */
  #define R_MPU_MPM_SVP_Pos        (1UL)          /*!< SVP (Bit 1)                                                    */
  #define R_MPU_MPM_SVP_Msk        (0x2UL)        /*!< SVP (Bitfield-Mask: 0x01)                                      */
  #define R_MPU_MPM_MPE_Pos        (0UL)          /*!< MPE (Bit 0)                                                    */
  #define R_MPU_MPM_MPE_Msk        (0x1UL)        /*!< MPE (Bitfield-Mask: 0x01)                                      */
/* =========================================================  MPCFG  ================================================ */
  #define R_MPU_MPCFG_NBK_Pos      (20UL)         /*!< NBK (Bit 20)                                                   */
  #define R_MPU_MPCFG_NBK_Msk      (0x300000UL)   /*!< NBK (Bitfield-Mask: 0x03)                                      */
  #define R_MPU_MPCFG_ARCH_Pos     (16UL)         /*!< ARCH (Bit 16)                                                  */
  #define R_MPU_MPCFG_ARCH_Msk     (0xf0000UL)    /*!< ARCH (Bitfield-Mask: 0x0f)                                     */
  #define R_MPU_MPCFG_NMPUE_Pos    (0UL)          /*!< NMPUE (Bit 0)                                                  */
  #define R_MPU_MPCFG_NMPUE_Msk    (0x1fUL)       /*!< NMPUE (Bitfield-Mask: 0x1f)                                    */
/* ==========================================================  MCA  ================================================= */
  #define R_MPU_MCA_MCA_Pos        (0UL)          /*!< MCA (Bit 0)                                                    */
  #define R_MPU_MCA_MCA_Msk        (0xffffffffUL) /*!< MCA (Bitfield-Mask: 0xffffffff)                                */
/* ==========================================================  MCS  ================================================= */
  #define R_MPU_MCS_MCS_Pos        (0UL)          /*!< MCS (Bit 0)                                                    */
  #define R_MPU_MCS_MCS_Msk        (0xffffffffUL) /*!< MCS (Bitfield-Mask: 0xffffffff)                                */
/* ==========================================================  MCC  ================================================= */
  #define R_MPU_MCC_MCC_Pos        (0UL)          /*!< MCC (Bit 0)                                                    */
  #define R_MPU_MCC_MCC_Msk        (0xffffffffUL) /*!< MCC (Bitfield-Mask: 0xffffffff)                                */
/* ==========================================================  MCR  ================================================= */
  #define R_MPU_MCR_OV_Pos         (8UL)          /*!< OV (Bit 8)                                                     */
  #define R_MPU_MCR_OV_Msk         (0x100UL)      /*!< OV (Bitfield-Mask: 0x01)                                       */
  #define R_MPU_MCR_SXE_Pos        (5UL)          /*!< SXE (Bit 5)                                                    */
  #define R_MPU_MCR_SXE_Msk        (0x20UL)       /*!< SXE (Bitfield-Mask: 0x01)                                      */
  #define R_MPU_MCR_SWE_Pos        (4UL)          /*!< SWE (Bit 4)                                                    */
  #define R_MPU_MCR_SWE_Msk        (0x10UL)       /*!< SWE (Bitfield-Mask: 0x01)                                      */
  #define R_MPU_MCR_SRE_Pos        (3UL)          /*!< SRE (Bit 3)                                                    */
  #define R_MPU_MCR_SRE_Msk        (0x8UL)        /*!< SRE (Bitfield-Mask: 0x01)                                      */
  #define R_MPU_MCR_UXE_Pos        (2UL)          /*!< UXE (Bit 2)                                                    */
  #define R_MPU_MCR_UXE_Msk        (0x4UL)        /*!< UXE (Bitfield-Mask: 0x01)                                      */
  #define R_MPU_MCR_UWE_Pos        (1UL)          /*!< UWE (Bit 1)                                                    */
  #define R_MPU_MCR_UWE_Msk        (0x2UL)        /*!< UWE (Bitfield-Mask: 0x01)                                      */
  #define R_MPU_MCR_URE_Pos        (0UL)          /*!< URE (Bit 0)                                                    */
  #define R_MPU_MCR_URE_Msk        (0x1UL)        /*!< URE (Bitfield-Mask: 0x01)                                      */
/* ==========================================================  MCI  ================================================= */
  #define R_MPU_MCI_SPID_Pos       (0UL)          /*!< SPID (Bit 0)                                                   */
  #define R_MPU_MCI_SPID_Msk       (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                     */
/* =========================================================  MPIDX  ================================================ */
  #define R_MPU_MPIDX_IDX_Pos      (0UL)          /*!< IDX (Bit 0)                                                    */
  #define R_MPU_MPIDX_IDX_Msk      (0x1fUL)       /*!< IDX (Bitfield-Mask: 0x1f)                                      */
/* =========================================================  MPBK  ================================================= */
  #define R_MPU_MPBK_BK_Pos        (0UL)          /*!< BK (Bit 0)                                                     */
  #define R_MPU_MPBK_BK_Msk        (0x3UL)        /*!< BK (Bitfield-Mask: 0x03)                                       */
/* =========================================================  MPLA  ================================================= */
  #define R_MPU_MPLA_MPLA_Pos      (2UL)          /*!< MPLA (Bit 2)                                                   */
  #define R_MPU_MPLA_MPLA_Msk      (0xfffffffcUL) /*!< MPLA (Bitfield-Mask: 0x3fffffff)                               */
/* =========================================================  MPUA  ==================== ============================ */
  #define R_MPU_MPUA_MPUA_Pos      (2UL)          /*!< MPUA (Bit 2)                                                   */
  #define R_MPU_MPUA_MPUA_Msk      (0xfffffffcUL) /*!< MPUA (Bitfield-Mask: 0x3fffffff)                               */
/* =========================================================  MPAT  ================================================= */
  #define R_MPU_MPAT_WMPID_Pos     (24UL)         /*!< WMPID (Bit 24)                                                 */
  #define R_MPU_MPAT_WMPID_Msk     (0xff000000UL) /*!< WMPID (Bitfield-Mask: 0xff)                                    */
  #define R_MPU_MPAT_RMPID_Pos     (16UL)         /*!< RMPID (Bit 16)                                                 */
  #define R_MPU_MPAT_RMPID_Msk     (0xff0000UL)   /*!< RMPID (Bitfield-Mask: 0xff)                                    */
  #define R_MPU_MPAT_WG_Pos        (15UL)         /*!< WG (Bit 15)                                                    */
  #define R_MPU_MPAT_WG_Msk        (0x8000UL)     /*!< WG (Bitfield-Mask: 0x01)                                       */
  #define R_MPU_MPAT_RG_Pos        (14UL)         /*!< RG (Bit 14)                                                    */
  #define R_MPU_MPAT_RG_Msk        (0x4000UL)     /*!< RG (Bitfield-Mask: 0x01)                                       */
  #define R_MPU_MPAT_E_Pos         (7UL)          /*!< E (Bit 7)                                                      */
  #define R_MPU_MPAT_E_Msk         (0x80UL)       /*!< E (Bitfield-Mask: 0x01)                                        */
  #define R_MPU_MPAT_SX_Pos        (5UL)          /*!< SX (Bit 5)                                                     */
  #define R_MPU_MPAT_SX_Msk        (0x20UL)       /*!< SX (Bitfield-Mask: 0x01)                                       */
  #define R_MPU_MPAT_SW_Pos        (4UL)          /*!< SW (Bit 4)                                                     */
  #define R_MPU_MPAT_SW_Msk        (0x10UL)       /*!< SW (Bitfield-Mask: 0x01)                                       */
  #define R_MPU_MPAT_SR_Pos        (3UL)          /*!< SR (Bit 3)                                                     */
  #define R_MPU_MPAT_SR_Msk        (0x8UL)        /*!< SR (Bitfield-Mask: 0x01)                                       */
  #define R_MPU_MPAT_UX_Pos        (2UL)          /*!< UX (Bit 2)                                                     */
  #define R_MPU_MPAT_UX_Msk        (0x4UL)        /*!< UX (Bitfield-Mask: 0x01)                                       */
  #define R_MPU_MPAT_UW_Pos        (1UL)          /*!< UW (Bit 1)                                                     */
  #define R_MPU_MPAT_UW_Msk        (0x2UL)        /*!< UW (Bitfield-Mask: 0x01)                                       */
  #define R_MPU_MPAT_UR_Pos        (0UL)          /*!< UR (Bit 0)                                                     */
  #define R_MPU_MPAT_UR_Msk        (0x1UL)        /*!< UR (Bitfield-Mask: 0x01)                                       */
/* =========================================================  MPID0  ================================================ */
  #define R_MPU_MPID0_SPID_Pos     (0UL)          /*!< SPID (Bit 0)                                                   */
  #define R_MPU_MPID0_SPID_Msk     (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                     */
/* =========================================================  MPID1  ================================================ */
  #define R_MPU_MPID1_SPID_Pos     (0UL)          /*!< SPID (Bit 0)                                                   */
  #define R_MPU_MPID1_SPID_Msk     (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                     */
/* =========================================================  MPID2  ================================================ */
  #define R_MPU_MPID2_SPID_Pos     (0UL)          /*!< SPID (Bit 0)                                                   */
  #define R_MPU_MPID2_SPID_Msk     (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                     */
/* =========================================================  MPID3  ================================================ */
  #define R_MPU_MPID3_SPID_Pos     (0UL)          /*!< SPID (Bit 0)                                                   */
  #define R_MPU_MPID3_SPID_Msk     (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                     */
/* =========================================================  MPID4  ================================================ */
  #define R_MPU_MPID4_SPID_Pos     (0UL)          /*!< SPID (Bit 0)                                                   */
  #define R_MPU_MPID4_SPID_Msk     (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                     */
/* =========================================================  MPID5  ================================================ */
  #define R_MPU_MPID5_SPID_Pos     (0UL)          /*!< SPID (Bit 0)                                                   */
  #define R_MPU_MPID5_SPID_Msk     (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                     */
/* =========================================================  MPID6  ================================================ */
  #define R_MPU_MPID6_SPID_Pos     (0UL)          /*!< SPID (Bit 0)                                                   */
  #define R_MPU_MPID6_SPID_Msk     (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                     */
/* =========================================================  MPID7  ================================================ */
  #define R_MPU_MPID7_SPID_Pos     (0UL)          /*!< SPID (Bit 0)                                                   */
  #define R_MPU_MPID7_SPID_Msk     (0x1fUL)       /*!< SPID (Bitfield-Mask: 0x1f)                                     */

/*@}*/ /* end of group RH850_G4MH_MPU */

/**
 * @ingroup  RH850_G4MH_Core_register
 * @defgroup RH850_G4MH_ICACHE     Cache Operation Function Registers (ICACHE)
 * @brief    Type definitions for the Cache Operation Function Registers (ICACHE)
 * @{
 */

/**
 * @brief  Structure type to access the Cache Operation Function Registers (ICACHE).
 */

typedef union
{
    __IOM uint32_t ICTAGL;             /*!< (@ 0x00000000) Instruction Cache Tag Lo Access                            */

    struct
    {
        __IOM uint32_t V : 1;          /*!< [0..0] This bit holds valid/invalid information of specified
                                        *    cache line.*30: The cache line is disabled.1: The cache
                                        *    line is enabled.                                                         */
        uint32_t         : 1;
        __IOM uint32_t L : 1;          /*!< [2..2] This bit holds the lock information.*30: The cache line
                                        *    is not locked.1: The cache line is locked.                               */
        uint32_t           : 1;
        __IOM uint32_t LRU : 2;        /*!< [5..4] These bits indicate LRU information of specified cache
                                        *    line. LRU informationcannot be freely changed to any value
                                        *    by the CIST instruction                                                  */
        uint32_t           : 5;
        __IOM uint32_t LPN : 21;       /*!< [31..11] These bits hold address bits 27 to 11. Bits 31 to 28
                                        *    must always be set to 0.Bits 27 to 11 are held if the cache
                                        *    size is 8 Kbytes.Bits 27 to 12 are held and bit 11 is always
                                        *    set to 0 if the cache size is 16Kbytes.*1Bits 27 to 13
                                        *    are held and bit 12 and 11 are always set to 0 if the cache
                                        *    size is32 KBytes.*2                                                      */
    } ICTAGL_b;
} RH850_ICACHE_ICTAGL_Type;

typedef union
{
    __IOM uint32_t ICTAGH;             /*!< (@ 0x00000000) Instruction Cache Tag Hi Access                            */

    struct
    {
        uint32_t              : 8;
        __IOM uint32_t TAGECC : 8;     /*!< [15..8] These bits hold ECC for tag RAM. Bit 15 is fixed to
                                        *    0                                                                        */
        __IOM uint32_t DATAECC : 8;    /*!< [23..16] These bits hold ECC for data RAM.                                */
        uint32_t               : 4;
        __IOM uint32_t PT      : 1;    /*!< [28..28] This bit specifies the data to be written to the ECC
                                        *    of the tag RAM when theWT bit is set to 1 and the CIST
                                        *    instruction is executed.0: ECC automatically generated
                                        *    from the write data is written to the ECC ofthe tag RAM.1:
                                        *    Values in the TAGECC field are written to the ECC of the
                                        *    tag RAM.                                                                 */
        __IOM uint32_t WT : 1;         /*!< [29..29] This bit specifies whether the tag RAM of the cache
                                        *    is updated duringexecution of the CIST instruction. When
                                        *    this bit is set to 1, the V bit and L bit ofthe cache line
                                        *    are also updated.0: Tag RAM of the cache is not updated.1:
                                        *    Tag RAM of the cache is updated.                                         */
        __IOM uint32_t PD : 1;         /*!< [30..30] This bit specifies the data to be written to the ECC
                                        *    of the data RAM when theWD bit is set to 1 and the CIST
                                        *    instruction is executed.0: ECC automatically generated
                                        *    from the write data is written to the ECC ofthe data RAM.1:
                                        *    Values in the DATAECC field are written to the ECC of the
                                        *    data RAM.                                                                */
        __IOM uint32_t WD : 1;         /*!< [31..31] This bit specifies whether the data RAM of the cache
                                        *    is updated duringexecution of the CIST instruction.0: Data
                                        *    RAM of the cache is not updated.1: Data RAM of the cache
                                        *    is updated.                                                              */
    } ICTAGH_b;
} RH850_ICACHE_ICTAGH_Type;

typedef union
{
    __IOM uint32_t ICDATL;             /*!< (@ 0x00000000) Instruction Cache Data Lo Access                           */

    struct
    {
        __IOM uint32_t DATAL : 32;     /*!< [31..0] These bits hold the lower-order 32 bits of the 64-bit
                                        *    instruction data*1 in theblock in the specified cache line.
                                        *    The bits to be held is specified by offset of theindex.*2Offset
                                        *    of index = 00: Bits 31 to 0*3Offset of index = 01: Bits
                                        *    95 to 64*3Offset of index = 10: Bits 159 to 128*3Offset
                                        *    of index = 11: Bits 223 to 192*3                                         */
    } ICDATL_b;
} RH850_ICACHE_ICDATL_Type;

typedef union
{
    __IOM uint32_t ICDATH;             /*!< (@ 0x00000000) Instruction Cache Data Hi Access                           */

    struct
    {
        __IOM uint32_t DATAH : 32;     /*!< [31..0] These bits hold the upper-order 32 bits of the 64-bit
                                        *    instruction data*1 in theblock in the specified cache line.
                                        *    The bits to be held is specified by offset of theindex.*2Offset
                                        *    of index = 00: Bits 63 to 32*3Offset of index = 01: Bits
                                        *    127 to 96*3Offset of index = 10: Bits 191 to 160*3Offset
                                        *    of index = 11: Bits 255 to 224*3                                         */
    } ICDATH_b;
} RH850_ICACHE_ICDATH_Type;

typedef union
{
    __IOM uint32_t ICCTRL;             /*!< (@ 0x00000000) Instruction Cache Control                                  */

    struct
    {
        __IOM uint32_t ICHEN : 1;      /*!< [0..0] This bit indicates valid/invalid status of instruction
                                        *    cache.0: Instruction cache is invalid1: Instruction cache
                                        *    is valid                                                                 */
        __IOM uint32_t ICHEMK : 1;     /*!< [1..1] When this bit is set to 1, it masks notification of cache
                                        *    error exceptions forthe CPU after a cache error*2 has occurred.          */
        __IOM uint32_t ICHEIV : 1;     /*!< [2..2] When this bit is set to 1, the instruction cache is automatically
                                        *    set asinvalid (the ICHEN bit is cleared to 0) whenever
                                        *    a cache error*2 occurs.                                                  */
        uint32_t              : 5;
        __IOM uint32_t ICHCLR : 1;     /*!< [8..8] When this bit is set to 1, the entire instruction cache
                                        *    is cleared. This clearsthe V and L bits (to 0) and initializes
                                        *    the LRU information. This bit isalways read as 0.                        */
        uint32_t : 23;
    } ICCTRL_b;
} RH850_ICACHE_ICCTRL_Type;

typedef union
{
    __IOM uint32_t ICCFG;              /*!< (@ 0x00000000) Instruction Cache Configuration                            */

    struct
    {
        __IM uint32_t ICHWAY : 4;      /*!< [3..0] These bits indicate the number of ways in the instruction
                                        *    cache.0100: 4 waysOther than above: Setting prohibited                   */
        __IM uint32_t ICHLINE : 4;     /*!< [7..4] These bits indicate the number of lines for each way
                                        *    in the instruction cache.0010: 64 lines0100: 128 lines1000:
                                        *    256 linesOther than above: Setting prohibited                            */
        __IM uint32_t ICHSIZE : 7;     /*!< [14..8] These bits indicate the size (in Kbytes) of the instruction
                                        *    cache.000 1000: 8 Kbytes001 0000: 16 Kbytes010 0000: 32
                                        *    KbytesOther than above: Setting prohibited                               */
        uint32_t : 17;
    } ICCFG_b;
} RH850_ICACHE_ICCFG_Type;

typedef union
{
    __IOM uint32_t ICERR;              /*!< (@ 0x00000000) Instruction Cache Error                                    */

    struct
    {
        __IOM uint32_t ICHERR : 1;     /*!< [0..0] This bit is set to 1 when a cache error has occurred.              */
        uint32_t              : 1;
        __IOM uint32_t ICHET  : 1;     /*!< [2..2] This bit indicates that an error has occurred in tag
                                        *    RAM.                                                                     */
        __IOM uint32_t ICHED : 1;      /*!< [3..3] This bit indicates that an error has occurred in data
                                        *    RAM.                                                                     */
        __IOM uint32_t ICHERQ : 1;     /*!< [4..4] When this bit is set to 1, this bit indicates that cache
                                        *    error exceptionnotification is in progress. However, if
                                        *    cache error exception notification hasbeen masked, the
                                        *    CPU is not notified even when 1 has been set to this bit.                */
        __IOM uint32_t ICHEIX : 8;     /*!< [12..5] These bits hold the cache index where a cache error
                                        *    occurred.Bits 10 to 5 are held and bits 12 and 11 are fixed
                                        *    to 0 for a cache size of 8Kbytes.*1Bits 11 to 5 are held
                                        *    and bit 12 is fixed to 0 for a cache size of 16 Kbytes.*2Bits
                                        *    12 to 5 are held for cache size of 32 Kbytes.                            */
        __IOM uint32_t ICHEWY : 3;     /*!< [15..13] These bits hold the way number where a cache error
                                        *    occurred. Bit 15 isalways set to 0.                                      */
        __IOM uint32_t ERMDE : 1;      /*!< [16..16] Error exception notification mask: Data RAM 2-bits
                                        *    error*3                                                                  */
        __IOM uint32_t ERMDC   : 1;    /*!< [17..17] Error exception notification mask: Data RAM 1-bit error*3        */
        __IOM uint32_t ERMTE2  : 1;    /*!< [18..18] Error exception notification mask: Tag RAM 2-bits error*3        */
        __IOM uint32_t ERMTE1  : 1;    /*!< [19..19] Error exception notification mask: Tag RAM 1-bit error*3         */
        __IOM uint32_t ERMPBSE : 1;    /*!< [20..20] Error exception notification mask: WAY error*3                   */
        __IOM uint32_t ERMMH   : 1;    /*!< [21..21] Error exception notification mask: Multi hit*3                   */
        __IOM uint32_t ERMAFE  : 1;    /*!< [22..22] Error exception notification mask: Address feedback
                                        *    error*3                                                                  */
        uint32_t              : 1;
        __IOM uint32_t ESDE   : 1;     /*!< [24..24] Error status: Data RAM 2-bits error                              */
        __IOM uint32_t ESDC   : 1;     /*!< [25..25] Error status: Data RAM 1-bit error                               */
        __IOM uint32_t ESTE2  : 1;     /*!< [26..26] Error status: Tag RAM 2-bits error                               */
        __IOM uint32_t ESTE1  : 1;     /*!< [27..27] Error status: Tag RAM 1-bit error                                */
        __IOM uint32_t ESPBSE : 1;     /*!< [28..28] Error status: WAY error                                          */
        __IOM uint32_t ESMH   : 1;     /*!< [29..29] Error status: Multi hit                                          */
        __IOM uint32_t ESAFE  : 1;     /*!< [30..30] Error status: Address feedback error                             */
        __IOM uint32_t CISTW  : 1;     /*!< [31..31] This bit is set to indicate that the destination way
                                        *    specified for a CISTIinstruction was in error. Although
                                        *    the entry information is overwritten so thatwriting is
                                        *    completed, the V bit will be cleared the next time the
                                        *    cache line isread (i.e. reading will be judged to have
                                        *    missed the cache). However, settingof this bit is not accompanied
                                        *    by an exception for the CPU.                                             */
    } ICERR_b;
} RH850_ICACHE_ICERR_Type;

/** @brief Cache Operation Function Registers macro Definitions */

/* ================================================================================================================== */
/* ================                                         R_ICACHE                                 ================ */
/* ================================================================================================================== */

/* ========================================================  ICTAGL  ================================================ */
  #define R_ICACHE_ICTAGL_LPN_Pos        (11UL)         /*!< LPN (Bit 11)                                             */
  #define R_ICACHE_ICTAGL_LPN_Msk        (0xfffff800UL) /*!< LPN (Bitfield-Mask: 0x1fffff)                            */
  #define R_ICACHE_ICTAGL_LRU_Pos        (4UL)          /*!< LRU (Bit 4)                                              */
  #define R_ICACHE_ICTAGL_LRU_Msk        (0x30UL)       /*!< LRU (Bitfield-Mask: 0x03)                                */
  #define R_ICACHE_ICTAGL_L_Pos          (2UL)          /*!< L (Bit 2)                                                */
  #define R_ICACHE_ICTAGL_L_Msk          (0x4UL)        /*!< L (Bitfield-Mask: 0x01)                                  */
  #define R_ICACHE_ICTAGL_V_Pos          (0UL)          /*!< V (Bit 0)                                                */
  #define R_ICACHE_ICTAGL_V_Msk          (0x1UL)        /*!< V (Bitfield-Mask: 0x01)                                  */
/* ========================================================  ICTAGH  ================================================ */
  #define R_ICACHE_ICTAGH_WD_Pos         (31UL)         /*!< WD (Bit 31)                                              */
  #define R_ICACHE_ICTAGH_WD_Msk         (0x80000000UL) /*!< WD (Bitfield-Mask: 0x01)                                 */
  #define R_ICACHE_ICTAGH_PD_Pos         (30UL)         /*!< PD (Bit 30)                                              */
  #define R_ICACHE_ICTAGH_PD_Msk         (0x40000000UL) /*!< PD (Bitfield-Mask: 0x01)                                 */
  #define R_ICACHE_ICTAGH_WT_Pos         (29UL)         /*!< WT (Bit 29)                                              */
  #define R_ICACHE_ICTAGH_WT_Msk         (0x20000000UL) /*!< WT (Bitfield-Mask: 0x01)                                 */
  #define R_ICACHE_ICTAGH_PT_Pos         (28UL)         /*!< PT (Bit 28)                                              */
  #define R_ICACHE_ICTAGH_PT_Msk         (0x10000000UL) /*!< PT (Bitfield-Mask: 0x01)                                 */
  #define R_ICACHE_ICTAGH_DATAECC_Pos    (16UL)         /*!< DATAECC (Bit 16)                                         */
  #define R_ICACHE_ICTAGH_DATAECC_Msk    (0xff0000UL)   /*!< DATAECC (Bitfield-Mask: 0xff)                            */
  #define R_ICACHE_ICTAGH_TAGECC_Pos     (8UL)          /*!< TAGECC (Bit 8)                                           */
  #define R_ICACHE_ICTAGH_TAGECC_Msk     (0xff00UL)     /*!< TAGECC (Bitfield-Mask: 0xff)                             */
/* ========================================================  ICDATL  ================================================ */
  #define R_ICACHE_ICDATL_DATAL_Pos      (0UL)          /*!< DATAL (Bit 0)                                            */
  #define R_ICACHE_ICDATL_DATAL_Msk      (0xffffffffUL) /*!< DATAL (Bitfield-Mask: 0xffffffff)                        */
/* ========================================================  ICDATH  ================================================ */
  #define R_ICACHE_ICDATH_DATAH_Pos      (0UL)          /*!< DATAH (Bit 0)                                            */
  #define R_ICACHE_ICDATH_DATAH_Msk      (0xffffffffUL) /*!< DATAH (Bitfield-Mask: 0xffffffff)                        */
/* ========================================================  ICCTRL  ================================================ */
  #define R_ICACHE_ICCTRL_ICHCLR_Pos     (8UL)          /*!< ICHCLR (Bit 8)                                           */
  #define R_ICACHE_ICCTRL_ICHCLR_Msk     (0x100UL)      /*!< ICHCLR (Bitfield-Mask: 0x01)                             */
  #define R_ICACHE_ICCTRL_ICHEIV_Pos     (2UL)          /*!< ICHEIV (Bit 2)                                           */
  #define R_ICACHE_ICCTRL_ICHEIV_Msk     (0x4UL)        /*!< ICHEIV (Bitfield-Mask: 0x01)                             */
  #define R_ICACHE_ICCTRL_ICHEMK_Pos     (1UL)          /*!< ICHEMK (Bit 1)                                           */
  #define R_ICACHE_ICCTRL_ICHEMK_Msk     (0x2UL)        /*!< ICHEMK (Bitfield-Mask: 0x01)                             */
  #define R_ICACHE_ICCTRL_ICHEN_Pos      (0UL)          /*!< ICHEN (Bit 0)                                            */
  #define R_ICACHE_ICCTRL_ICHEN_Msk      (0x1UL)        /*!< ICHEN (Bitfield-Mask: 0x01)                              */
/* =========================================================  ICCFG  ================================================ */
  #define R_ICACHE_ICCFG_ICHSIZE_Pos     (8UL)          /*!< ICHSIZE (Bit 8)                                          */
  #define R_ICACHE_ICCFG_ICHSIZE_Msk     (0x7f00UL)     /*!< ICHSIZE (Bitfield-Mask: 0x7f)                            */
  #define R_ICACHE_ICCFG_ICHLINE_Pos     (4UL)          /*!< ICHLINE (Bit 4)                                          */
  #define R_ICACHE_ICCFG_ICHLINE_Msk     (0xf0UL)       /*!< ICHLINE (Bitfield-Mask: 0x0f)                            */
  #define R_ICACHE_ICCFG_ICHWAY_Pos      (0UL)          /*!< ICHWAY (Bit 0)                                           */
  #define R_ICACHE_ICCFG_ICHWAY_Msk      (0xfUL)        /*!< ICHWAY (Bitfield-Mask: 0x0f)                             */
/* =========================================================  ICERR  ================================================ */
  #define R_ICACHE_ICERR_CISTW_Pos       (31UL)         /*!< CISTW (Bit 31)                                           */
  #define R_ICACHE_ICERR_CISTW_Msk       (0x80000000UL) /*!< CISTW (Bitfield-Mask: 0x01)                              */
  #define R_ICACHE_ICERR_ESAFE_Pos       (30UL)         /*!< ESAFE (Bit 30)                                           */
  #define R_ICACHE_ICERR_ESAFE_Msk       (0x40000000UL) /*!< ESAFE (Bitfield-Mask: 0x01)                              */
  #define R_ICACHE_ICERR_ESMH_Pos        (29UL)         /*!< ESMH (Bit 29)                                            */
  #define R_ICACHE_ICERR_ESMH_Msk        (0x20000000UL) /*!< ESMH (Bitfield-Mask: 0x01)                               */
  #define R_ICACHE_ICERR_ESPBSE_Pos      (28UL)         /*!< ESPBSE (Bit 28)                                          */
  #define R_ICACHE_ICERR_ESPBSE_Msk      (0x10000000UL) /*!< ESPBSE (Bitfield-Mask: 0x01)                             */
  #define R_ICACHE_ICERR_ESTE1_Pos       (27UL)         /*!< ESTE1 (Bit 27)                                           */
  #define R_ICACHE_ICERR_ESTE1_Msk       (0x8000000UL)  /*!< ESTE1 (Bitfield-Mask: 0x01)                              */
  #define R_ICACHE_ICERR_ESTE2_Pos       (26UL)         /*!< ESTE2 (Bit 26)                                           */
  #define R_ICACHE_ICERR_ESTE2_Msk       (0x4000000UL)  /*!< ESTE2 (Bitfield-Mask: 0x01)                              */
  #define R_ICACHE_ICERR_ESDC_Pos        (25UL)         /*!< ESDC (Bit 25)                                            */
  #define R_ICACHE_ICERR_ESDC_Msk        (0x2000000UL)  /*!< ESDC (Bitfield-Mask: 0x01)                               */
  #define R_ICACHE_ICERR_ESDE_Pos        (24UL)         /*!< ESDE (Bit 24)                                            */
  #define R_ICACHE_ICERR_ESDE_Msk        (0x1000000UL)  /*!< ESDE (Bitfield-Mask: 0x01)                               */
  #define R_ICACHE_ICERR_ERMAFE_Pos      (22UL)         /*!< ERMAFE (Bit 22)                                          */
  #define R_ICACHE_ICERR_ERMAFE_Msk      (0x400000UL)   /*!< ERMAFE (Bitfield-Mask: 0x01)                             */
  #define R_ICACHE_ICERR_ERMMH_Pos       (21UL)         /*!< ERMMH (Bit 21)                                           */
  #define R_ICACHE_ICERR_ERMMH_Msk       (0x200000UL)   /*!< ERMMH (Bitfield-Mask: 0x01)                              */
  #define R_ICACHE_ICERR_ERMPBSE_Pos     (20UL)         /*!< ERMPBSE (Bit 20)                                         */
  #define R_ICACHE_ICERR_ERMPBSE_Msk     (0x100000UL)   /*!< ERMPBSE (Bitfield-Mask: 0x01)                            */
  #define R_ICACHE_ICERR_ERMTE1_Pos      (19UL)         /*!< ERMTE1 (Bit 19)                                          */
  #define R_ICACHE_ICERR_ERMTE1_Msk      (0x80000UL)    /*!< ERMTE1 (Bitfield-Mask: 0x01)                             */
  #define R_ICACHE_ICERR_ERMTE2_Pos      (18UL)         /*!< ERMTE2 (Bit 18)                                          */
  #define R_ICACHE_ICERR_ERMTE2_Msk      (0x40000UL)    /*!< ERMTE2 (Bitfield-Mask: 0x01)                             */
  #define R_ICACHE_ICERR_ERMDC_Pos       (17UL)         /*!< ERMDC (Bit 17)                                           */
  #define R_ICACHE_ICERR_ERMDC_Msk       (0x20000UL)    /*!< ERMDC (Bitfield-Mask: 0x01)                              */
  #define R_ICACHE_ICERR_ERMDE_Pos       (16UL)         /*!< ERMDE (Bit 16)                                           */
  #define R_ICACHE_ICERR_ERMDE_Msk       (0x10000UL)    /*!< ERMDE (Bitfield-Mask: 0x01)                              */
  #define R_ICACHE_ICERR_ICHEWY_Pos      (13UL)         /*!< ICHEWY (Bit 13)                                          */
  #define R_ICACHE_ICERR_ICHEWY_Msk      (0xe000UL)     /*!< ICHEWY (Bitfield-Mask: 0x07)                             */
  #define R_ICACHE_ICERR_ICHEIX_Pos      (5UL)          /*!< ICHEIX (Bit 5)                                           */
  #define R_ICACHE_ICERR_ICHEIX_Msk      (0x1fe0UL)     /*!< ICHEIX (Bitfield-Mask: 0xff)                             */
  #define R_ICACHE_ICERR_ICHERQ_Pos      (4UL)          /*!< ICHERQ (Bit 4)                                           */
  #define R_ICACHE_ICERR_ICHERQ_Msk      (0x10UL)       /*!< ICHERQ (Bitfield-Mask: 0x01)                             */
  #define R_ICACHE_ICERR_ICHED_Pos       (3UL)          /*!< ICHED (Bit 3)                                            */
  #define R_ICACHE_ICERR_ICHED_Msk       (0x8UL)        /*!< ICHED (Bitfield-Mask: 0x01)                              */
  #define R_ICACHE_ICERR_ICHET_Pos       (2UL)          /*!< ICHET (Bit 2)                                            */
  #define R_ICACHE_ICERR_ICHET_Msk       (0x4UL)        /*!< ICHET (Bitfield-Mask: 0x01)                              */
  #define R_ICACHE_ICERR_ICHERR_Pos      (0UL)          /*!< ICHERR (Bit 0)                                           */
  #define R_ICACHE_ICERR_ICHERR_Msk      (0x1UL)        /*!< ICHERR (Bitfield-Mask: 0x01)                             */

/*@}*/ /* end of group RH850_G4MH_ICACHE */

/**
 * @ingroup  RH850_G4MH_Core_register
 * @defgroup RH850_G4MH_PMU     Count Function Registers (PMU)
 * @brief    Type definitions for the Count Function Registers (PMU)
 * @{
 */

/**
 * @brief  Structure type to access the Count Function Registers (PMU).
 */

typedef union
{
    __IOM uint32_t PMUMCTRL;           /*!< (@ 0x00000000) Performance Counter User Mode Control                      */

    struct
    {
        __IOM uint32_t PMUE0 : 1;      /*!< [0..0] This bit specifies the accessibility of the PMCTRL0,
                                        *    PMCOUNT0 and PMSUBCND0 registers in user mode.0: Disables
                                        *    accesses to PMCTRL0/PMCOUNT0/PMSUBCND0 in user mode.1:
                                        *    Enables accesses to PMCTRL0/PMCOUNT0/PMSUBCND0 in user
                                        *    mode.                                                                    */
        __IOM uint32_t PMUE1 : 1;      /*!< [1..1] This bit specifies the accessibility of the PMCTRL1,
                                        *    PMCOUNT1 and PMSUBCND1 registers in user mode.0: Disables
                                        *    accesses to PMCTRL1/PMCOUNT1/PMSUBCND1 in user mode.1:
                                        *    Enables accesses to PMCTRL1/PMCOUNT1/PMSUBCND1 in user
                                        *    mode.                                                                    */
        __IOM uint32_t PMUE2 : 1;      /*!< [2..2] This bit specifies the accessibility of the PMCTRL2,
                                        *    PMCOUNT2 and PMSUBCND2 registers in user mode.0: Disables
                                        *    accesses to PMCTRL2/PMCOUNT2/PMSUBCND2 in user mode.1:
                                        *    Enables accesses to PMCTRL2/PMCOUNT2/PMSUBCND2 in user
                                        *    mode.                                                                    */
        __IOM uint32_t PMUE3 : 1;      /*!< [3..3] This bit specifies the accessibility of the PMCTRL3,
                                        *    PMCOUNT3 and PMSUBCND3 registers in user mode.0: Disables
                                        *    accesses to PMCTRL3/PMCOUNT3/PMSUBCND3 in user mode.1:
                                        *    Enables accesses to PMCTRL3/PMCOUNT3/PMSUBCND3 in user
                                        *    mode.                                                                    */
        __IOM uint32_t PMUE4 : 1;      /*!< [4..4] This bit specifies the accessibility of the PMCTRL4,
                                        *    PMCOUNT4 and PMSUBCND4 registers in user mode.0: Disables
                                        *    accesses to PMCTRL4/PMCOUNT4/PMSUBCND4 in user mode.1:
                                        *    Enables accesses to PMCTRL4/PMCOUNT4/PMSUBCND4 in user
                                        *    mode.                                                                    */
        __IOM uint32_t PMUE5 : 1;      /*!< [5..5] This bit specifies the accessibility of the PMCTRL5,
                                        *    PMCOUNT5 and PMSUBCND5 registers in user mode.0: Disables
                                        *    accesses to PMCTRL5/PMCOUNT5/PMSUBCND5 in user mode.1:
                                        *    Enables accesses to PMCTRL5/PMCOUNT5/PMSUBCND5 in user
                                        *    mode.                                                                    */
        __IOM uint32_t PMUE6 : 1;      /*!< [6..6] This bit specifies the accessibility of the PMCTRL6,
                                        *    PMCOUNT6 and PMSUBCND6 registers in user mode.0: Disables
                                        *    accesses to PMCTRL6/PMCOUNT6/PMSUBCND6 in user mode.1:
                                        *    Enables accesses to PMCTRL6/PMCOUNT6/PMSUBCND6 in user
                                        *    mode.                                                                    */
        __IOM uint32_t PMUE7 : 1;      /*!< [7..7] This bit specifies the accessibility of the PMCTRL7,
                                        *    PMCOUNT7 and PMSUBCND7 registers in user mode.0: Disables
                                        *    accesses to PMCTRL7/PMCOUNT7/PMSUBCND7 in user mode.1:
                                        *    Enables accesses to PMCTRL7/PMCOUNT7/PMSUBCND7 in user
                                        *    mode.                                                                    */
        uint32_t : 24;
    } PMUMCTRL_b;
} RH850_PMU_PMUMCTRL_Type;

typedef union
{
    __IOM uint32_t PMCTRL;             /*!< (@ 0x00000000) Performance Counter User Mode Control                      */

    struct
    {
        __IOM uint32_t CEN : 1;        /*!< [0..0] This bit enables or disables the count operation of the
                                        *    PMCOUNTn register.0: Disables count operation.1: Enables
                                        *    count operation.If this bit is written with a 1 when it
                                        *    is set to 0, the counter starts countingimmediately. If
                                        *    this bit is written with a 0 when it is set to 1, the counter
                                        *    stopscounting immediately. If this bit is 0, the values
                                        *    of the PMCOUNTn register ispreserved. There is no factor
                                        *    that will automatically change the value of thisbit.                     */
        __IOM uint32_t OVF : 1;        /*!< [1..1] This bit serves as the overflow flag. This bit is set
                                        *    to 1 when an overflowoccurs in the PMCOUNTn register as
                                        *    the result of its count operation.This bit is not automatically
                                        *    cleared to 0. To reset the overflow state, write a 0into
                                        *    this bit.Since this bit can be written with a 1, it can
                                        *    be an overflow condition regardlessof the count operation.
                                        *    Although it does not affect the counter operation, caremust
                                        *    be taken not to take that condition for an overflow.                     */
        uint32_t           : 6;
        __IOM uint32_t CND : 8;        /*!< [15..8] When read, the value after reset is returned.                     */
        uint32_t           : 16;
    } PMCTRL_b;
} RH850_PMU_PMCTRL_Type;

typedef union
{
    __IOM uint32_t PMCOUNT;            /*!< (@ 0x00000000) Performance Count                                          */

    struct
    {
        __IOM uint32_t PMCNT : 32;     /*!< [31..0] These bits form a 32-bit counter register.The counter
                                        *    counts the number of occurrences of the event that is specified
                                        *    bythe PMCTRLn.CND bit.When this register counts up from
                                        *    FFFF FFFFH, the PMCTRLn.OVF bit is setto 1 and the register
                                        *    wraps around to 0000 0000H.This register is accessible
                                        *    at an arbitrary timing regardless of whethercounting is
                                        *    enabled or disabled. In addition, it is possible to start
                                        *    counting at anarbitrary count by loading that value in
                                        *    this register before starting to count.                                  */
    } PMCOUNT_b;
} RH850_PMU_PMCOUNT_Type;

typedef union
{
    __IOM uint32_t PMSUBCND;           /*!< (@ 0x00000000) Performance Count                                          */

    struct
    {
        __IOM uint32_t SUBCND : 13;    /*!< [12..0] How the value of the SUBCND field is used depends on
                                        *    the setting of thePMCTRLn.CND. If the value of the PMCTRLn.CND
                                        *    is other than the following,the value of the SUBCND field
                                        *    does not affect the operation of theperformance counter.R/W
                                        *    0Value of thePMCTRLn.CND Operation of the performance counter20H
                                        *    The channel number of the interrupt (EIINTn) for which
                                        *    theacceptance count is counted can be limited. The operation
                                        *    isspecified by the value of bit 12.0: The channel number
                                        *    to be counted is no                                                      */
        uint32_t : 19;
    } PMSUBCND_b;
} RH850_PMU_PMSUBCND_Type;

/** @brief Count Function Registers macro Definitions */

/* ================================================================================================================== */
/* ================                                           R_PMU                                  ================ */
/* ================================================================================================================== */

/* =======================================================  PMUMCTRL  =============================================== */
  #define R_PMU_PMUMCTRL_PMUE7_Pos      (7UL)          /*!< PMUE7 (Bit 7)                                             */
  #define R_PMU_PMUMCTRL_PMUE7_Msk      (0x80UL)       /*!< PMUE7 (Bitfield-Mask: 0x01)                               */
  #define R_PMU_PMUMCTRL_PMUE6_Pos      (6UL)          /*!< PMUE6 (Bit 6)                                             */
  #define R_PMU_PMUMCTRL_PMUE6_Msk      (0x40UL)       /*!< PMUE6 (Bitfield-Mask: 0x01)                               */
  #define R_PMU_PMUMCTRL_PMUE5_Pos      (5UL)          /*!< PMUE5 (Bit 5)                                             */
  #define R_PMU_PMUMCTRL_PMUE5_Msk      (0x20UL)       /*!< PMUE5 (Bitfield-Mask: 0x01)                               */
  #define R_PMU_PMUMCTRL_PMUE4_Pos      (4UL)          /*!< PMUE4 (Bit 4)                                             */
  #define R_PMU_PMUMCTRL_PMUE4_Msk      (0x10UL)       /*!< PMUE4 (Bitfield-Mask: 0x01)                               */
  #define R_PMU_PMUMCTRL_PMUE3_Pos      (3UL)          /*!< PMUE3 (Bit 3)                                             */
  #define R_PMU_PMUMCTRL_PMUE3_Msk      (0x8UL)        /*!< PMUE3 (Bitfield-Mask: 0x01)                               */
  #define R_PMU_PMUMCTRL_PMUE2_Pos      (2UL)          /*!< PMUE2 (Bit 2)                                             */
  #define R_PMU_PMUMCTRL_PMUE2_Msk      (0x4UL)        /*!< PMUE2 (Bitfield-Mask: 0x01)                               */
  #define R_PMU_PMUMCTRL_PMUE1_Pos      (1UL)          /*!< PMUE1 (Bit 1)                                             */
  #define R_PMU_PMUMCTRL_PMUE1_Msk      (0x2UL)        /*!< PMUE1 (Bitfield-Mask: 0x01)                               */
  #define R_PMU_PMUMCTRL_PMUE0_Pos      (0UL)          /*!< PMUE0 (Bit 0)                                             */
  #define R_PMU_PMUMCTRL_PMUE0_Msk      (0x1UL)        /*!< PMUE0 (Bitfield-Mask: 0x01)                               */
  #define R_PMU_PMUMCTRL_PMUE_Msk       (0xFFUL)       /*!< PMUE0 (Bitfield-Mask: 0xff)                               */
/* ========================================================  PMCTRL0  =============================================== */
  #define R_PMU_PMCTRL0_CND_Pos         (8UL)          /*!< CND (Bit 8)                                               */
  #define R_PMU_PMCTRL0_CND_Msk         (0xff00UL)     /*!< CND (Bitfield-Mask: 0xff)                                 */
  #define R_PMU_PMCTRL0_OVF_Pos         (1UL)          /*!< OVF (Bit 1)                                               */
  #define R_PMU_PMCTRL0_OVF_Msk         (0x2UL)        /*!< OVF (Bitfield-Mask: 0x01)                                 */
  #define R_PMU_PMCTRL0_CEN_Pos         (0UL)          /*!< CEN (Bit 0)                                               */
  #define R_PMU_PMCTRL0_CEN_Msk         (0x1UL)        /*!< CEN (Bitfield-Mask: 0x01)                                 */
/* ========================================================  PMCTRL1  =============================================== */
  #define R_PMU_PMCTRL1_CND_Pos         (8UL)          /*!< CND (Bit 8)                                               */
  #define R_PMU_PMCTRL1_CND_Msk         (0xff00UL)     /*!< CND (Bitfield-Mask: 0xff)                                 */
  #define R_PMU_PMCTRL1_OVF_Pos         (1UL)          /*!< OVF (Bit 1)                                               */
  #define R_PMU_PMCTRL1_OVF_Msk         (0x2UL)        /*!< OVF (Bitfield-Mask: 0x01)                                 */
  #define R_PMU_PMCTRL1_CEN_Pos         (0UL)          /*!< CEN (Bit 0)                                               */
  #define R_PMU_PMCTRL1_CEN_Msk         (0x1UL)        /*!< CEN (Bitfield-Mask: 0x01)                                 */
/* ========================================================  PMCTRL2  =============================================== */
  #define R_PMU_PMCTRL2_CND_Pos         (8UL)          /*!< CND (Bit 8)                                               */
  #define R_PMU_PMCTRL2_CND_Msk         (0xff00UL)     /*!< CND (Bitfield-Mask: 0xff)                                 */
  #define R_PMU_PMCTRL2_OVF_Pos         (1UL)          /*!< OVF (Bit 1)                                               */
  #define R_PMU_PMCTRL2_OVF_Msk         (0x2UL)        /*!< OVF (Bitfield-Mask: 0x01)                                 */
  #define R_PMU_PMCTRL2_CEN_Pos         (0UL)          /*!< CEN (Bit 0)                                               */
  #define R_PMU_PMCTRL2_CEN_Msk         (0x1UL)        /*!< CEN (Bitfield-Mask: 0x01)                                 */
/* ========================================================  PMCTRL3  =============================================== */
  #define R_PMU_PMCTRL3_CND_Pos         (8UL)          /*!< CND (Bit 8)                                               */
  #define R_PMU_PMCTRL3_CND_Msk         (0xff00UL)     /*!< CND (Bitfield-Mask: 0xff)                                 */
  #define R_PMU_PMCTRL3_OVF_Pos         (1UL)          /*!< OVF (Bit 1)                                               */
  #define R_PMU_PMCTRL3_OVF_Msk         (0x2UL)        /*!< OVF (Bitfield-Mask: 0x01)                                 */
  #define R_PMU_PMCTRL3_CEN_Pos         (0UL)          /*!< CEN (Bit 0)                                               */
  #define R_PMU_PMCTRL3_CEN_Msk         (0x1UL)        /*!< CEN (Bitfield-Mask: 0x01)                                 */
/* ========================================================  PMCTRL4  =============================================== */
  #define R_PMU_PMCTRL4_CND_Pos         (8UL)          /*!< CND (Bit 8)                                               */
  #define R_PMU_PMCTRL4_CND_Msk         (0xff00UL)     /*!< CND (Bitfield-Mask: 0xff)                                 */
  #define R_PMU_PMCTRL4_OVF_Pos         (1UL)          /*!< OVF (Bit 1)                                               */
  #define R_PMU_PMCTRL4_OVF_Msk         (0x2UL)        /*!< OVF (Bitfield-Mask: 0x01)                                 */
  #define R_PMU_PMCTRL4_CEN_Pos         (0UL)          /*!< CEN (Bit 0)                                               */
  #define R_PMU_PMCTRL4_CEN_Msk         (0x1UL)        /*!< CEN (Bitfield-Mask: 0x01)                                 */
/* ========================================================  PMCTRL5  =============================================== */
  #define R_PMU_PMCTRL5_CND_Pos         (8UL)          /*!< CND (Bit 8)                                               */
  #define R_PMU_PMCTRL5_CND_Msk         (0xff00UL)     /*!< CND (Bitfield-Mask: 0xff)                                 */
  #define R_PMU_PMCTRL5_OVF_Pos         (1UL)          /*!< OVF (Bit 1)                                               */
  #define R_PMU_PMCTRL5_OVF_Msk         (0x2UL)        /*!< OVF (Bitfield-Mask: 0x01)                                 */
  #define R_PMU_PMCTRL5_CEN_Pos         (0UL)          /*!< CEN (Bit 0)                                               */
  #define R_PMU_PMCTRL5_CEN_Msk         (0x1UL)        /*!< CEN (Bitfield-Mask: 0x01)                                 */
/* ========================================================  PMCTRL6  =============================================== */
  #define R_PMU_PMCTRL6_CND_Pos         (8UL)          /*!< CND (Bit 8)                                               */
  #define R_PMU_PMCTRL6_CND_Msk         (0xff00UL)     /*!< CND (Bitfield-Mask: 0xff)                                 */
  #define R_PMU_PMCTRL6_OVF_Pos         (1UL)          /*!< OVF (Bit 1)                                               */
  #define R_PMU_PMCTRL6_OVF_Msk         (0x2UL)        /*!< OVF (Bitfield-Mask: 0x01)                                 */
  #define R_PMU_PMCTRL6_CEN_Pos         (0UL)          /*!< CEN (Bit 0)                                               */
  #define R_PMU_PMCTRL6_CEN_Msk         (0x1UL)        /*!< CEN (Bitfield-Mask: 0x01)                                 */
/* ========================================================  PMCTRL7  =============================================== */
  #define R_PMU_PMCTRL7_CND_Pos         (8UL)          /*!< CND (Bit 8)                                               */
  #define R_PMU_PMCTRL7_CND_Msk         (0xff00UL)     /*!< CND (Bitfield-Mask: 0xff)                                 */
  #define R_PMU_PMCTRL7_OVF_Pos         (1UL)          /*!< OVF (Bit 1)                                               */
  #define R_PMU_PMCTRL7_OVF_Msk         (0x2UL)        /*!< OVF (Bitfield-Mask: 0x01)                                 */
  #define R_PMU_PMCTRL7_CEN_Pos         (0UL)          /*!< CEN (Bit 0)                                               */
  #define R_PMU_PMCTRL7_CEN_Msk         (0x1UL)        /*!< CEN (Bitfield-Mask: 0x01)                                 */
/* =======================================================  PMCOUNT0  =============================================== */
  #define R_PMU_PMCOUNT0_PMCNT_Pos      (0UL)          /*!< PMCNT (Bit 0)                                             */
  #define R_PMU_PMCOUNT0_PMCNT_Msk      (0xffffffffUL) /*!< PMCNT (Bitfield-Mask: 0xffffffff)                         */
/* =======================================================  PMCOUNT1  =============================================== */
  #define R_PMU_PMCOUNT1_PMCNT_Pos      (0UL)          /*!< PMCNT (Bit 0)                                             */
  #define R_PMU_PMCOUNT1_PMCNT_Msk      (0xffffffffUL) /*!< PMCNT (Bitfield-Mask: 0xffffffff)                         */
/* =======================================================  PMCOUNT2  =============================================== */
  #define R_PMU_PMCOUNT2_PMCNT_Pos      (0UL)          /*!< PMCNT (Bit 0)                                             */
  #define R_PMU_PMCOUNT2_PMCNT_Msk      (0xffffffffUL) /*!< PMCNT (Bitfield-Mask: 0xffffffff)                         */
/* =======================================================  PMCOUNT3  =============================================== */
  #define R_PMU_PMCOUNT3_PMCNT_Pos      (0UL)          /*!< PMCNT (Bit 0)                                             */
  #define R_PMU_PMCOUNT3_PMCNT_Msk      (0xffffffffUL) /*!< PMCNT (Bitfield-Mask: 0xffffffff)                         */
/* =======================================================  PMCOUNT4  =============================================== */
  #define R_PMU_PMCOUNT4_PMCNT_Pos      (0UL)          /*!< PMCNT (Bit 0)                                             */
  #define R_PMU_PMCOUNT4_PMCNT_Msk      (0xffffffffUL) /*!< PMCNT (Bitfield-Mask: 0xffffffff)                         */
/* =======================================================  PMCOUNT5  =============================================== */
  #define R_PMU_PMCOUNT5_PMCNT_Pos      (0UL)          /*!< PMCNT (Bit 0)                                             */
  #define R_PMU_PMCOUNT5_PMCNT_Msk      (0xffffffffUL) /*!< PMCNT (Bitfield-Mask: 0xffffffff)                         */
/* =======================================================  PMCOUNT6  =============================================== */
  #define R_PMU_PMCOUNT6_PMCNT_Pos      (0UL)          /*!< PMCNT (Bit 0)                                             */
  #define R_PMU_PMCOUNT6_PMCNT_Msk      (0xffffffffUL) /*!< PMCNT (Bitfield-Mask: 0xffffffff)                         */
/* =======================================================  PMCOUNT7  =============================================== */
  #define R_PMU_PMCOUNT7_PMCNT_Pos      (0UL)          /*!< PMCNT (Bit 0)                                             */
  #define R_PMU_PMCOUNT7_PMCNT_Msk      (0xffffffffUL) /*!< PMCNT (Bitfield-Mask: 0xffffffff)                         */
/* =======================================================  PMSUBCND0  ============================================== */
  #define R_PMU_PMSUBCND0_SUBCND_Pos    (0UL)          /*!< SUBCND (Bit 0)                                            */
  #define R_PMU_PMSUBCND0_SUBCND_Msk    (0x1fffUL)     /*!< SUBCND (Bitfield-Mask: 0x1fff)                            */
/* =======================================================  PMSUBCND1  ============================================== */
  #define R_PMU_PMSUBCND1_SUBCND_Pos    (0UL)          /*!< SUBCND (Bit 0)                                            */
  #define R_PMU_PMSUBCND1_SUBCND_Msk    (0x1fffUL)     /*!< SUBCND (Bitfield-Mask: 0x1fff)                            */
/* =======================================================  PMSUBCND2  ==================================== ========= */
  #define R_PMU_PMSUBCND2_SUBCND_Pos    (0UL)          /*!< SUBCND (Bit 0)                                            */
  #define R_PMU_PMSUBCND2_SUBCND_Msk    (0x1fffUL)     /*!< SUBCND (Bitfield-Mask: 0x1fff)                            */
/* =======================================================  PMSUBCND3  ============================================== */
  #define R_PMU_PMSUBCND3_SUBCND_Pos    (0UL)          /*!< SUBCND (Bit 0)                                            */
  #define R_PMU_PMSUBCND3_SUBCND_Msk    (0x1fffUL)     /*!< SUBCND (Bitfield-Mask: 0x1fff)                            */
/* =======================================================  PMSUBCND4  ============================================== */
  #define R_PMU_PMSUBCND4_SUBCND_Pos    (0UL)          /*!< SUBCND (Bit 0)                                            */
  #define R_PMU_PMSUBCND4_SUBCND_Msk    (0x1fffUL)     /*!< SUBCND (Bitfield-Mask: 0x1fff)                            */
/* =======================================================  PMSUBCND5  ============================================== */
  #define R_PMU_PMSUBCND5_SUBCND_Pos    (0UL)          /*!< SUBCND (Bit 0)                                            */
  #define R_PMU_PMSUBCND5_SUBCND_Msk    (0x1fffUL)     /*!< SUBCND (Bitfield-Mask: 0x1fff)                            */
/* =======================================================  PMSUBCND6  ============================================== */
  #define R_PMU_PMSUBCND6_SUBCND_Pos    (0UL)          /*!< SUBCND (Bit 0)                                            */
  #define R_PMU_PMSUBCND6_SUBCND_Msk    (0x1fffUL)     /*!< SUBCND (Bitfield-Mask: 0x1fff)                            */
/* =======================================================  PMSUBCND7  ============================================== */
  #define R_PMU_PMSUBCND7_SUBCND_Pos    (0UL)          /*!< SUBCND (Bit 0)                                            */
  #define R_PMU_PMSUBCND7_SUBCND_Msk    (0x1fffUL)     /*!< SUBCND (Bitfield-Mask: 0x1fff)                            */

/*@}*/ /* end of group RH850_G4MH_PMU */

/**
 * @ingroup  RH850_G4MH_Core_register
 * @defgroup RH850_G4MH_HWF     Hardware Function Registers (HWF)
 * @brief    Type definitions for the Hardware Function Registers (HWF)
 * @{
 */

/**
 * @brief  Structure type to access the Hardware Function Registers (HWF).
 */

typedef union
{
    __IOM uint32_t LSTEST0;            /*!< (@ 0x00000000) Lock-step Function Self-diagnosis Register 0               */

    struct
    {
        __IOM uint32_t LSTEST0 : 32;   /*!< [31..0] [Write]Write any value to bits of the LSTEST0 register.[Read]Value
                                        *    in LSTEST0 is read by the master CPU of the lock-stepped
                                        *    CPU.Value in LSTEST1 is read by the checker CPU of the
                                        *    lock-stepped CPU.                                                        */
    } LSTEST0_b;
} RH850_HWF_LSTEST0_Type;

typedef union
{
    __IOM uint32_t LSTEST1;            /*!< (@ 0x00000000) Lock-step Function Self-diagnosis Register 1               */

    struct
    {
        __IOM uint32_t LSTEST1 : 32;   /*!< [31..0] [Write]Write any value to bits of the LSTEST1 register.[Read]Value
                                        *    in LSTEST1 is read by the master CPU of the lock-stepped
                                        *    CPU.Value in LSTEST0 is read by the checker CPU of the
                                        *    lock-stepped CPU.                                                        */
    } LSTEST1_b;
} RH850_HWF_LSTEST1_Type;

typedef union
{
    __IOM uint32_t LSCFG;              /*!< (@ 0x00000000) Configuration of Lock Step function                        */

    struct
    {
        __IOM uint32_t LSE : 1;        /*!< [0..0] This bit indicates the availability of the Lock Step
                                        *    function.0: The Lock Step function is not available.1:
                                        *    The Lock Step function is available.                                     */
        uint32_t : 31;
    } LSCFG_b;
} RH850_HWF_LSCFG_Type;

typedef union
{
    __IOM uint32_t IFCR;               /*!< (@ 0x00000000) Instruction Fetch Control Register                         */

    struct
    {
        __IOM uint32_t PLEN : 1;       /*!< [0..0] This bit specifies whether the instruction fetch preload
                                        *    function is enabled ordisabled.0: Disabled1: Enabled                     */
        uint32_t : 31;
    } IFCR_b;
} RH850_HWF_IFCR_Type;

typedef union
{
    __IOM uint32_t BRPCTRL0;           /*!< (@ 0x00000000) Branch Prediction Function Control Register                */

    struct
    {
        __IOM uint32_t BRPEN : 1;      /*!< [0..0] This bit specifies whether the branch prediction function*1
                                        *    is enabled ordisabled.0: Disabled1: Enabled                              */
        __IOM uint32_t BRPCLR : 1;     /*!< [1..1] Setting this bit to 1 clears the buffers related to branch
                                        *    prediction function. Thisbit is always read as 0.                        */
        uint32_t : 30;
    } BRPCTRL0_b;
} RH850_HWF_BRPCTRL0_Type;

typedef union
{
    __IOM uint32_t L1RCFG;             /*!< (@ 0x00000000) Configuration of L1RAM                                     */

    struct
    {
        __IM uint32_t L1RLNKE : 4;     /*!< [3..0] This field indicates the number of entries of links available
                                        *    in L1RAM.(For example: 0010B: 2 entries)                                 */
        uint32_t              : 4;
        __IM uint32_t L1RSIZE : 22;    /*!< [29..8] This field indicates the L1RAM capacity (Kbytes).(For
                                        *    example: 000020H: 32 Kbytes)                                             */
        uint32_t : 2;
    } L1RCFG_b;
} RH850_HWF_L1RCFG_Type;

typedef union
{
    __IOM uint32_t RDBCR;              /*!< (@ 0x00000000) ROM Data Buffer Control Register                           */

    struct
    {
        __IOM uint32_t RDBEN : 1;      /*!< [0..0] This bit specifies whether the ROM data buffer is enabled
                                        *    or disabled.0: ROM data buffer is disabled.1: ROM data
                                        *    buffer is enabled.                                                       */
        __IOM uint32_t RDBCLR : 1;     /*!< [1..1] Setting this bit (to 1) clears the ROM data buffer and
                                        *    initializes the LRUinformation in the ROM data buffer.If
                                        *    this bit is set (to 1) during load processing or when a
                                        *    bus request issued bythe prefetch function is present,
                                        *    the load data is not registered in the ROMdata buffer.This
                                        *    bit is always read as 0.                                                 */
        uint32_t : 30;
    } RDBCR_b;
} RH850_HWF_RDBCR_Type;

/** @brief Hardware Function Registers macro Definitions */

/* ================================================================================================================== */
/* ================                                           R_HWF                                  ================ */
/* ================================================================================================================== */

/* ========================================================  LSTEST0  =============================================== */
  #define R_HWF_LSTEST0_LSTEST0_Pos    (0UL)          /*!< LSTEST0 (Bit 0)                                            */
  #define R_HWF_LSTEST0_LSTEST0_Msk    (0xffffffffUL) /*!< LSTEST0 (Bitfield-Mask: 0xffffffff)                        */
/* ========================================================  LSTEST1  =============================================== */
  #define R_HWF_LSTEST1_LSTEST1_Pos    (0UL)          /*!< LSTEST1 (Bit 0)                                            */
  #define R_HWF_LSTEST1_LSTEST1_Msk    (0xffffffffUL) /*!< LSTEST1 (Bitfield-Mask: 0xffffffff)                        */
/* =========================================================  LSCFG  ================================================ */
  #define R_HWF_LSCFG_LSE_Pos          (0UL)          /*!< LSE (Bit 0)                                                */
  #define R_HWF_LSCFG_LSE_Msk          (0x1UL)        /*!< LSE (Bitfield-Mask: 0x01)                                  */
/* =========================================================  IFCR  ================================================= */
  #define R_HWF_IFCR_PLEN_Pos          (0UL)          /*!< PLEN (Bit 0)                                               */
  #define R_HWF_IFCR_PLEN_Msk          (0x1UL)        /*!< PLEN (Bitfield-Mask: 0x01)                                 */
/* =======================================================  BRPCTRL0  =============================================== */
  #define R_HWF_BRPCTRL0_BRPCLR_Pos    (1UL)          /*!< BRPCLR (Bit 1)                                             */
  #define R_HWF_BRPCTRL0_BRPCLR_Msk    (0x2UL)        /*!< BRPCLR (Bitfield-Mask: 0x01)                               */
  #define R_HWF_BRPCTRL0_BRPEN_Pos     (0UL)          /*!< BRPEN (Bit 0)                                              */
  #define R_HWF_BRPCTRL0_BRPEN_Msk     (0x1UL)        /*!< BRPEN (Bitfield-Mask: 0x01)                                */
/* ========================================================  L1RCFG  ================================================ */
  #define R_HWF_L1RCFG_L1RSIZE_Pos     (8UL)          /*!< L1RSIZE (Bit 8)                                            */
  #define R_HWF_L1RCFG_L1RSIZE_Msk     (0x3fffff00UL) /*!< L1RSIZE (Bitfield-Mask: 0x3fffff)                          */
  #define R_HWF_L1RCFG_L1RLNKE_Pos     (0UL)          /*!< L1RLNKE (Bit 0)                                            */
  #define R_HWF_L1RCFG_L1RLNKE_Msk     (0xfUL)        /*!< L1RLNKE (Bitfield-Mask: 0x0f)                              */
/* =========================================================  RDBCR  ================================================ */
  #define R_HWF_RDBCR_RDBCLR_Pos       (1UL)          /*!< RDBCLR (Bit 1)                                             */
  #define R_HWF_RDBCR_RDBCLR_Msk       (0x2UL)        /*!< RDBCLR (Bitfield-Mask: 0x01)                               */
  #define R_HWF_RDBCR_RDBEN_Pos        (0UL)          /*!< RDBEN (Bit 0)                                              */
  #define R_HWF_RDBCR_RDBEN_Msk        (0x1UL)        /*!< RDBEN (Bitfield-Mask: 0x01)                                */

/*@}*/ /* end of group RH850_G4MH_HWF */

/**
 * @ingroup  RH850_G4MH_Core_register
 * @defgroup RH850_G4MH_TSC     Timestamp counter (TSC)
 * @brief    Type definitions for the Timestamp counter (TSC)
 * @{
 */

/**
 * @brief  Structure type to access the Timestamp counter (TSC).
 */

typedef union
{
    __IOM uint32_t TSCOUNTL;           /*!< (@ 0x00000000) Timestamp Count L                                          */

    struct
    {
        __IOM uint32_t TSCNTL : 32;    /*!< [31..0] These bits account for the lower-order 32 bits of the
                                        *    64-bit counter.If counting is enabled by the TSCTRL register,
                                        *    the value of this register isincremented by 1 on every
                                        *    clock cycle.When this register counts up from FFFF FFFFH,
                                        *    the TSCOUNTH register isincremented by 1 as a carryover
                                        *    and this register wraps around to0000 0000H.This register
                                        *    is accessible at an arbitrary timing regardless of whethercounting
                                        *    is enabled or disabled. In addition, it is possible to
                                        *    start counting at anarbitrary                                            */
    } TSCOUNTL_b;
} RH850_TSC_TSCOUNTL_Type;

typedef union
{
    __IOM uint32_t TSCOUNTH;           /*!< (@ 0x00000000) Timestamp Count H                                          */

    struct
    {
        __IOM uint32_t TSCNTH : 32;    /*!< [31..0] These bits account for the higher-order 32 bits of the
                                        *    64-bit counter.If counting is enabled by the TSCTRL register,
                                        *    the value of this register isincremented by 1 when the
                                        *    TSCOUNTL register counts up and generates acarryover.If
                                        *    a carryover occurs in the TSCOUNTL register when this register
                                        *    holds avalue of FFFF FFFFH, the TSCTRL.OVF bit is set to
                                        *    1 and this register wrapsaround to 0000 0000H.This register
                                        *    is accessible at an arbitrary timing regardless of whethercounting
                                        *    is enabled or disabl                                                     */
    } TSCOUNTH_b;
} RH850_TSC_TSCOUNTH_Type;

typedef union
{
    __IOM uint32_t TSCTRL;             /*!< (@ 0x00000000) Timestamp Count Control                                    */

    struct
    {
        __IOM uint32_t CEN : 1;        /*!< [0..0] This bit enables or disables the count operation of the
                                        *    64-bit timestampcounter which is implemented by combining
                                        *    the TSCOUNTH and TSCOUNTLregisters.0: Disables count operation.1:
                                        *    Enables count operation.If this bit is written with a 1
                                        *    when it is set to 0, the counter starts countingimmediately.
                                        *    If this bit is written with a 0 when it is set to 1, the
                                        *    counter stopscounting immediately. If this bit is 0, the
                                        *    values of the TSCOUNTH andTSCOUNTL registers are preserved.
                                        *    There is no factor that                                                  */
        __IOM uint32_t OVF : 1;        /*!< [1..1] This bit serves as the overflow flag. This bit is set
                                        *    to 1 when an overflowoccurs in the TSCOUNTH register as
                                        *    the result of its count operation.This bit is not automatically
                                        *    cleared to 0. To reset the overflow state, write a 0into
                                        *    this bit.Since this bit can be written with a 1, it can
                                        *    be an overflow condition regardlessof the count operation.
                                        *    Although it does not affect the counter operation, caremust
                                        *    be taken not to take that condition for an overflow.                     */
        uint32_t : 30;
    } TSCTRL_b;
} RH850_TSC_TSCTRL_Type;

/** @brief Timestamp counter macro Definitions */

/* ================================================================================================================== */
/* ================                                           R_TSC                                  ================ */
/* ================================================================================================================== */

/* =======================================================  TSCOUNTL  =============================================== */
  #define R_TSC_TSCOUNTL_TSCNTL_Pos    (0UL)          /*!< TSCNTL (Bit 0)                                             */
  #define R_TSC_TSCOUNTL_TSCNTL_Msk    (0xffffffffUL) /*!< TSCNTL (Bitfield-Mask: 0xffffffff)                         */
/* =======================================================  TSCOUNTH  =============================================== */
  #define R_TSC_TSCOUNTH_TSCNTH_Pos    (0UL)          /*!< TSCNTH (Bit 0)                                             */
  #define R_TSC_TSCOUNTH_TSCNTH_Msk    (0xffffffffUL) /*!< TSCNTH (Bitfield-Mask: 0xffffffff)                         */
/* ========================================================  TSCTRL  ================================================ */
  #define R_TSC_TSCTRL_OVF_Pos         (1UL)          /*!< OVF (Bit 1)                                                */
  #define R_TSC_TSCTRL_OVF_Msk         (0x2UL)        /*!< OVF (Bitfield-Mask: 0x01)                                  */
  #define R_TSC_TSCTRL_CEN_Pos         (0UL)          /*!< CEN (Bit 0)                                                */
  #define R_TSC_TSCTRL_CEN_Msk         (0x1UL)        /*!< CEN (Bitfield-Mask: 0x01)                                  */

/*@}*/ /* end of group RH850_G4MH_TSC */

/*@}*/ /* end of group RH850_G4MH_Core_register */
/*@}*/ /* end of group G4MH_Core_register */

/***********************************************************************************************************************
 *                Hardware Abstraction Layer
 **********************************************************************************************************************/

/**
 * @defgroup RH850_API_Funcs RH850 Macro Wrapper API Functions
 * @brief RH850 API Functions
 * @defgroup RH850_G4MH_API_Funcs RH850 G4MH Macro Wrapper API Functions
 * @brief RH850 G4MH Macro Wrapper API Functions
 * @ingroup RH850_API_Funcs
 * @{
 */

/* #############################################  FPU functions  #################################################### */
  #if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1U)

/**
 * @defgroup RH850_G4MH_FPU_API FPU API Functions
 * @brief FPU API Functions
 * @ingroup RH850_G4MH_API_Funcs
 * @{
 */
   #include "G4-profile/rh850_g4_fpu.h"

   #ifndef RH850_FPU_Enable
    #define RH850_FPU_Enable                __RH850_FPU_Enable             /*!< Wrapper macro that calls the @ref __RH850_FPU_Enable */
   #endif /* #ifndef RH850_FPU_Enable */

   #ifndef RH850_FPU_Disable
    #define RH850_FPU_Disable               __RH850_FPU_Disable            /*!< Wrapper macro that calls the @ref __RH850_FPU_Disable */
   #endif /* #ifndef RH850_FPU_Disable */

   #ifndef RH850_FPU_EnableGet
    #define RH850_FPU_EnableGet             __RH850_FPU_EnableGet          /*!< Wrapper macro that calls the @ref __RH850_FPU_EnableGet */
   #endif /* #ifndef RH850_FPU_EnableGet */

   #ifndef RH850_FPU_StatusGet
    #define RH850_FPU_StatusGet             __RH850_FPU_StatusGet          /*!< Wrapper macro that calls the @ref __RH850_FPU_StatusGet */
   #endif /* #ifndef RH850_FPU_StatusGet */

   #ifndef RH850_FPU_StatusClear
    #define RH850_FPU_StatusClear           __RH850_FPU_StatusClear        /*!< Wrapper macro that calls the @ref __RH850_FPU_StatusClear */
   #endif /* #ifndef RH850_FPU_StatusClear */

   #ifndef RH850_FPU_FpsrCcBitGet
    #define RH850_FPU_FpsrCcBitGet          __RH850_FPU_FpsrCcBitGet       /*!< Wrapper macro that calls the @ref __RH850_FPU_FpsrCcBitGet */
   #endif /* #ifndef RH850_FPU_FpsrCcBitGet */

   #ifndef RH850_FPU_FpsrCcBitSet
    #define RH850_FPU_FpsrCcBitSet          __RH850_FPU_FpsrCcBitSet       /*!< Wrapper macro that calls the @ref __RH850_FPU_FpsrCcBitSet */
   #endif /* #ifndef RH850_FPU_FpsrCcBitSet */

   #ifndef RH850_FPU_FpsrIfBitGet
    #define RH850_FPU_FpsrIfBitGet          __RH850_FPU_FpsrIfBitGet       /*!< Wrapper macro that calls the @ref __RH850_FPU_FpsrIfBitGet */
   #endif /* #ifndef RH850_FPU_FpsrIfBitGet */

   #ifndef RH850_FPU_ModeFlushSet
    #define RH850_FPU_ModeFlushSet          __RH850_FPU_ModeFlushSet       /*!< Wrapper macro that calls the @ref __RH850_FPU_ModeFlushSet */
   #endif /* #ifndef RH850_FPU_ModeFlushSet */

   #ifndef RH850_FPU_ModeFlushGet
    #define RH850_FPU_ModeFlushGet          __RH850_FPU_ModeFlushGet       /*!< Wrapper macro that calls the @ref __RH850_FPU_ModeFlushGet */
   #endif /* #ifndef RH850_FPU_ModeFlushGet */

   #ifndef RH850_FPU_ModeRoundingSet
    #define RH850_FPU_ModeRoundingSet       __RH850_FPU_ModeRoundingSet    /*!< Wrapper macro that calls the @ref __RH850_FPU_ModeRoundingSet */
   #endif /* #ifndef RH850_FPU_ModeRoundingSet */

   #ifndef RH850_FPU_ModeRoundingGet
    #define RH850_FPU_ModeRoundingGet       __RH850_FPU_ModeRoundingGet    /*!< Wrapper macro that calls the @ref __RH850_FPU_ModeRoundingGet */
   #endif /* #ifndef RH850_FPU_ModeRoundingGet */

   #ifndef RH850_FPU_ExceptionEnableSet
    #define RH850_FPU_ExceptionEnableSet    __RH850_FPU_ExceptionEnableSet /*!< Wrapper macro that calls the @ref __RH850_FPU_ExceptionEnableSet */
   #endif /* #ifndef RH850_FPU_ExceptionEnableSet */

   #ifndef RH850_FPU_ExceptionEnableGet
    #define RH850_FPU_ExceptionEnableGet    __RH850_FPU_ExceptionEnableGet /*!< Wrapper macro that calls the @ref __RH850_FPU_ExceptionEnableGet*/
   #endif /* #ifndef RH850_FPU_ExceptionEnableGet */

   #ifndef RH850_FPU_FpepcGet
    #define RH850_FPU_FpepcGet              __RH850_FPU_FpepcGet           /*!< Wrapper macro that calls the @ref __RH850_FPU_FpepcGet*/
   #endif /* #ifndef RH850_FPU_FpepcGet */
/** @} */ /* end of RH850_FPU */
  #endif

/* #############################################  FXU functions  #################################################### */
  #if defined(__FXU_PRESENT) && (__FXU_PRESENT == 1U)

/**
 * @defgroup RH850_G4MH_FXU_API FXU API Functions
 * @brief FXU API Functions
 * @ingroup RH850_G4MH_API_Funcs
 * @{
 */

   #include "G4-profile/rh850_g4_fxu.h"

   #ifndef RH850_FXU_Enable
    #define RH850_FXU_Enable                 __RH850_FXU_Enable              /*!< Wrapper macro that calls the @ref __RH850_FXU_Enable */
   #endif /* #ifndef RH850_FXU_Enable */

   #ifndef RH850_FXU_Disable
    #define RH850_FXU_Disable                __RH850_FXU_Disable             /*!< Wrapper macro that calls the @ref __RH850_FXU_Disable */
   #endif /* #ifndef RH850_FXU_Disable */

   #ifndef RH850_FXU_FxsrIfBitGet
    #define RH850_FXU_FxsrIfBitGet           __RH850_FXU_FxsrIfBitGet        /*!< Wrapper macro that calls the @ref __RH850_FXU_FxsrIfBitGet */
   #endif /* #ifndef RH850_FXU_FxsrIfBitGet */

   #ifndef RH850_FXU_ModeFlushSet
    #define RH850_FXU_ModeFlushSet           __RH850_FXU_ModeFlushSet        /*!< Wrapper macro that calls the @ref __RH850_FXU_ModeFlushSet */
   #endif /* #ifndef RH850_FXU_ModeFlushSet */

   #ifndef RH850_FXU_SimdUnitCheck
    #define RH850_FXU_SimdUnitCheck          __RH850_FXU_SimdUnitCheck       /*!< Wrapper macro that calls the @ref __RH850_FXU_SimdUnitCheck */
   #endif /* #ifndef RH850_FXU_SimdUnitCheck */

   #ifndef RH850_FXU_VectorRegisterCheck
    #define RH850_FXU_VectorRegisterCheck    __RH850_FXU_VectorRegisterCheck /*!< Wrapper macro that calls the @ref __RH850_FXU_VectorRegisterCheck */
   #endif /* #ifndef RH850_FXU_VectorRegisterCheck */

   #ifndef RH850_FXU_ModeRoundingSet
    #define RH850_FXU_ModeRoundingSet        __RH850_FXU_ModeRoundingSet     /*!< Wrapper macro that calls the @ref __RH850_FXU_ModeRoundingSet */
   #endif /* #ifndef RH850_FXU_ModeRoundingSet */

   #ifndef RH850_FXU_ExceptionEnableSet
    #define RH850_FXU_ExceptionEnableSet     __RH850_FXU_ExceptionEnableSet  /*!< Wrapper macro that calls the @ref __RH850_FXU_ExceptionEnableSet */
   #endif /* #ifndef RH850_FXU_ExceptionEnableSet */

   #ifndef RH850_FXU_CauseBitsGet
    #define RH850_FXU_CauseBitsGet           __RH850_FXU_CauseBitsGet        /*!< Wrapper macro that calls the @ref __RH850_FXU_CauseBitsGet */
   #endif /* #ifndef RH850_FXU_CauseBitsGet */

   #ifndef RH850_FXU_PreservationBitsGet
    #define RH850_FXU_PreservationBitsGet    __RH850_FXU_PreservationBitsGet /*!< Wrapper macro that calls the @ref __RH850_FXU_PreservationBitsGet */
   #endif /* #ifndef RH850_FXU_PreservationBitsGet */

   #ifndef RH850_FXU_StatusGet
    #define RH850_FXU_StatusGet              __RH850_FXU_StatusGet           /*!< Wrapper macro that calls the @ref __RH850_FXU_StatusGet */
   #endif /* #ifndef RH850_FXU_StatusGet */

   #ifndef RH850_FXU_StatusClear
    #define RH850_FXU_StatusClear            __RH850_FXU_StatusClear         /*!< Wrapper macro that calls the @ref __RH850_FXU_StatusClear */
   #endif /* #ifndef RH850_FXU_StatusClear */
/** @} */ /* end of RH850_FXU */
  #endif

/* ##########################  ICACHE functions  ################################## */
  #if defined(__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)

/**
 * @defgroup RH850_G4MH_ICACHE_API ICACHE API Functions
 * @brief ICACHE API Functions
 * @ingroup RH850_G4MH_API_Funcs
 * @{
 */

   #include "G4-profile/rh850_g4_icache.h"

   #ifndef RH850_ICache_Enable
    #define RH850_ICache_Enable                      __RH850_ICache_Enable                   /*!< Wrapper macro that calls the @ref __RH850_ICache_Enable */
   #endif /* #ifndef RH850_ICache_Enable */

   #ifndef RH850_ICache_Disable
    #define RH850_ICache_Disable                     __RH850_ICache_Disable                  /*!< Wrapper macro that calls the @ref __RH850_ICache_Disable */
   #endif /* #ifndef RH850_ICache_Disable */

   #ifndef RH850_ICache_EnableGet
    #define RH850_ICache_EnableGet                   __RH850_ICache_EnableGet                /*!< Wrapper macro that calls the @ref __RH850_ICache_EnableGet */
   #endif /* #ifndef RH850_ICache_EnableGet */

   #ifndef RH850_ICache_CacheSizeGet
    #define RH850_ICache_CacheSizeGet                __RH850_ICache_CacheSizeGet             /*!< Wrapper macro that calls the @ref __RH850_ICache_CacheSizeGet */
   #endif /* #ifndef RH850_ICache_CacheSizeGet */

   #ifndef RH850_ICache_LinesPerWayGet
    #define RH850_ICache_LinesPerWayGet              __RH850_ICache_LinesPerWayGet           /*!< Wrapper macro that calls the @ref __RH850_ICache_LinesPerWayGet */
   #endif /* #ifndef RH850_ICache_LinesPerWayGet */

   #ifndef RH850_ICache_NumberOfWaysGet
    #define RH850_ICache_NumberOfWaysGet             __RH850_ICache_NumberOfWaysGet          /*!< Wrapper macro that calls the @ref __RH850_ICache_NumberOfWaysGet */
   #endif /* #ifndef RH850_ICache_NumberOfWaysGet */

   #ifndef RH850_ICache_ErrorStatusGet
    #define RH850_ICache_ErrorStatusGet              __RH850_ICache_ErrorStatusGet           /*!< Wrapper macro that calls the @ref __RH850_ICache_ErrorStatusGet */
   #endif /* #ifndef RH850_ICache_ErrorStatusGet */

   #ifndef RH850_ICache_ErrorIndexGet
    #define RH850_ICache_ErrorIndexGet               __RH850_ICache_ErrorIndexGet            /*!< Wrapper macro that calls the @ref __RH850_ICache_ErrorIndexGet */
   #endif /* #ifndef RH850_ICache_ErrorIndexGet */

   #ifndef RH850_ICache_ErrorWayGet
    #define RH850_ICache_ErrorWayGet                 __RH850_ICache_ErrorWayGet              /*!< Wrapper macro that calls the @ref __RH850_ICache_ErrorWayGet */
   #endif /* #ifndef RH850_ICache_ErrorWayGet */

   #ifndef RH850_ICache_Clear
    #define RH850_ICache_Clear                       __RH850_ICache_Clear                    /*!< Wrapper macro that calls the @ref __RH850_ICache_Clear */
   #endif /* #ifndef RH850_ICache_Clear */

   #ifndef RH850_ICache_AutoInvalidateOnErrorSet
    #define RH850_ICache_AutoInvalidateOnErrorSet    __RH850_ICache_AutoInvalidateOnErrorSet /*!< Wrapper macro that calls the @ref __RH850_ICache_AutoInvalidateOnErrorSet */
   #endif /* #ifndef RH850_ICache_AutoInvalidateOnErrorSet */

   #ifndef RH850_ICache_ErrorNotifyMaskSet
    #define RH850_ICache_ErrorNotifyMaskSet          __RH850_ICache_ErrorNotifyMaskSet       /*!< Wrapper macro that calls the @ref __RH850_ICache_ErrorNotifyMaskSet */
   #endif /* #ifndef RH850_ICache_ErrorNotifyMaskSet */

   #ifndef RH850_ICache_TagLoGet
    #define RH850_ICache_TagLoGet                    __RH850_ICache_TagLoGet                 /*!< Wrapper macro that calls the @ref __RH850_ICache_TagLoGet */
   #endif /* #ifndef RH850_ICache_TagLoGet */

   #ifndef RH850_ICache_TagLoSet
    #define RH850_ICache_TagLoSet                    __RH850_ICache_TagLoSet                 /*!< Wrapper macro that calls the @ref __RH850_ICache_TagLoSet */
   #endif /* #ifndef RH850_ICache_TagLoSet */

   #ifndef RH850_ICache_TagHiGet
    #define RH850_ICache_TagHiGet                    __RH850_ICache_TagHiGet                 /*!< Wrapper macro that calls the @ref __RH850_ICache_TagHiGet */
   #endif /* #ifndef RH850_ICache_TagHiGet */

   #ifndef RH850_ICache_TagHiSet
    #define RH850_ICache_TagHiSet                    __RH850_ICache_TagHiSet                 /*!< Wrapper macro that calls the @ref __RH850_ICache_TagHiSet */
   #endif /* #ifndef RH850_ICache_TagHiSet */

   #ifndef RH850_ICache_DataLoGet
    #define RH850_ICache_DataLoGet                   __RH850_ICache_DataLoGet                /*!< Wrapper macro that calls the @ref __RH850_ICache_DataLoGet */
   #endif /* #ifndef RH850_ICache_DataLoGet */

   #ifndef RH850_ICache_DataLoSet
    #define RH850_ICache_DataLoSet                   __RH850_ICache_DataLoSet                /*!< Wrapper macro that calls the @ref __RH850_ICache_DataLoSet */
   #endif /* #ifndef RH850_ICache_DataLoSet */

   #ifndef RH850_ICache_DataHiGet
    #define RH850_ICache_DataHiGet                   __RH850_ICache_DataHiGet                /*!< Wrapper macro that calls the @ref __RH850_ICache_DataHiGet */
   #endif /* #ifndef RH850_ICache_DataHiGet */

   #ifndef RH850_ICache_DataHiSet
    #define RH850_ICache_DataHiSet                   __RH850_ICache_DataHiSet                /*!< Wrapper macro that calls the @ref __RH850_ICache_DataHiSet */
   #endif /* #ifndef RH850_ICache_DataHiSet */
/** @} */ /* end of RH850_ICACHE */
  #endif

/* #############################################  IRQ functions  #################################################### */
  #if defined(__IRQ_PRESENT) && (__IRQ_PRESENT == 1U)

/**
 * @defgroup RH850_G4MH_IRQ_API IRQ API Functions
 * @brief IRQ API Functions
 * @ingroup RH850_G4MH_API_Funcs
 * @{
 */

   #define RH850_INTC1_BASE                        0xFFFC4000UL
   #define RH850_INTC2_BASE                        0xFFF80000UL
   #define RH850_INTC1_OFFSET                      0x4000U
   #define RH850_INTC1_EIBD_OFFSET                 0x0100U
   #define RH850_INTC2_EIBD_OFFSET                 0x2000U
   #define RH850_INTC1_EEIC_OFFSET                 0x0200U
   #define RH850_INTC2_EEIC_OFFSET                 0x4000U

   #include "G4-profile/rh850_g4_irq.h"

   #ifndef RH850_IRQ_InterruptPriorityGet
    #define RH850_IRQ_InterruptPriorityGet         __RH850_IRQ_InterruptPriorityGet      /*!< Wrapper macro that calls the @ref __RH850_IRQ_InterruptPriorityGet */
   #endif /* #ifndef RH850_IRQ_InterruptPriorityGet */

   #ifndef RH850_IRQ_InterruptMaskStatusGet
    #define RH850_IRQ_InterruptMaskStatusGet       __RH850_IRQ_InterruptMaskStatusGet    /*!< Wrapper macro that calls the @ref __RH850_IRQ_InterruptMaskStatusGet */
   #endif /* #ifndef RH850_IRQ_InterruptMaskStatusGet */

   #ifndef RH850_IRQ_InterruptControlStatusGet
    #define RH850_IRQ_InterruptControlStatusGet    __RH850_IRQ_InterruptControlStatusGet /*!< Wrapper macro that calls the @ref __RH850_IRQ_InterruptControlStatusGet */
   #endif /* #ifndef RH850_IRQ_InterruptControlStatusGet */

   #ifndef RH850_IRQ_PriorityExtensionGet
    #define RH850_IRQ_PriorityExtensionGet         __RH850_IRQ_PriorityExtensionGet      /*!< Wrapper macro that calls the @ref __RH850_IRQ_PriorityExtensionGet */
   #endif /* #ifndef RH850_IRQ_PriorityExtensionGet */

   #ifndef RH850_IRQ_PriorityExtensionSet
    #define RH850_IRQ_PriorityExtensionSet         __RH850_IRQ_PriorityExtensionSet      /*!< Wrapper macro that calls the @ref __RH850_IRQ_PriorityExtensionSet */
   #endif /* #ifndef RH850_IRQ_PriorityExtensionSet */

   #ifndef RH850_IRQ_IsprUpdateModeGet
    #define RH850_IRQ_IsprUpdateModeGet            __RH850_IRQ_IsprUpdateModeGet         /*!< Wrapper macro that calls the @ref __RH850_IRQ_IsprUpdateModeGet */
   #endif /* #ifndef RH850_IRQ_IsprUpdateModeGet */

   #ifndef RH850_IRQ_IsprUpdateModeSet
    #define RH850_IRQ_IsprUpdateModeSet            __RH850_IRQ_IsprUpdateModeSet         /*!< Wrapper macro that calls the @ref __RH850_IRQ_IsprUpdateModeSet */
   #endif /* #ifndef RH850_IRQ_IsprUpdateModeSet */

   #ifndef RH850_IRQ_RegisterBankLimitGet
    #define RH850_IRQ_RegisterBankLimitGet         __RH850_IRQ_RegisterBankLimitGet      /*!< Wrapper macro that calls the @ref __RH850_IRQ_RegisterBankLimitGet */
   #endif /* #ifndef RH850_IRQ_RegisterBankLimitGet */

   #ifndef RH850_IRQ_RegisterBankLimitSet
    #define RH850_IRQ_RegisterBankLimitSet         __RH850_IRQ_RegisterBankLimitSet      /*!< Wrapper macro that calls the @ref __RH850_IRQ_RegisterBankLimitSet */
   #endif /* #ifndef RH850_IRQ_RegisterBankLimitSet */

   #ifndef RH850_IRQ_PriorityMaskLevelGet
    #define RH850_IRQ_PriorityMaskLevelGet         __RH850_IRQ_PriorityMaskLevelGet      /*!< Wrapper macro that calls the @ref __RH850_IRQ_PriorityMaskLevelGet */
   #endif /* #ifndef RH850_IRQ_PriorityMaskLevelGet */

   #ifndef RH850_IRQ_PriorityMaskLevelSet
    #define RH850_IRQ_PriorityMaskLevelSet         __RH850_IRQ_PriorityMaskLevelSet      /*!< Wrapper macro that calls the @ref __RH850_IRQ_PriorityMaskLevelSet */
   #endif /* #ifndef RH850_IRQ_PriorityMaskLevelSet */

   #ifndef RH850_IRQ_IntMaskGet
    #define RH850_IRQ_IntMaskGet                   __RH850_IRQ_IntMaskGet                /*!< Wrapper macro that calls the @ref __RH850_IRQ_IntMaskGet */
   #endif /* #ifndef RH850_IRQ_IntMaskGet */

   #ifndef RH850_IRQ_IntMaskSet
    #define RH850_IRQ_IntMaskSet                   __RH850_IRQ_IntMaskSet                /*!< Wrapper macro that calls the @ref __RH850_IRQ_IntMaskSet */
   #endif /* #ifndef RH850_IRQ_IntMaskSet */

   #ifndef RH850_IRQ_EnableIRQ
    #define RH850_IRQ_EnableIRQ                    __RH850_IRQ_EnableIRQ                 /*!< Wrapper macro that calls the @ref __RH850_IRQ_EnableIRQ */
   #endif /* #ifndef RH850_IRQ_EnableIRQ */

   #ifndef RH850_IRQ_EnableIRQByPE
    #define RH850_IRQ_EnableIRQByPE                __RH850_IRQ_EnableIRQByPE             /*!< Wrapper macro that calls the @ref __RH850_IRQ_EnableIRQ */
   #endif /* #ifndef RH850_IRQ_EnableIRQByPE */

   #ifndef RH850_IRQ_GetEnableIRQ
    #define RH850_IRQ_GetEnableIRQ                 __RH850_IRQ_GetEnableIRQ              /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetEnableIRQ */
   #endif /* #ifndef RH850_IRQ_GetEnableIRQ */

   #ifndef RH850_IRQ_GetEnableIRQByPE
    #define RH850_IRQ_GetEnableIRQByPE             __RH850_IRQ_GetEnableIRQByPE          /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetEnableIRQ */
   #endif /* #ifndef RH850_IRQ_GetEnableIRQByPE */

   #ifndef RH850_IRQ_DisableIRQ
    #define RH850_IRQ_DisableIRQ                   __RH850_IRQ_DisableIRQ                /*!< Wrapper macro that calls the @ref __RH850_IRQ_DisableIRQ */
   #endif /* #ifndef RH850_IRQ_DisableIRQ */

   #ifndef RH850_IRQ_DisableIRQByPE
    #define RH850_IRQ_DisableIRQByPE               __RH850_IRQ_DisableIRQByPE            /*!< Wrapper macro that calls the @ref __RH850_IRQ_DisableIRQ */
   #endif /* #ifndef RH850_IRQ_DisableIRQByPE */

   #ifndef RH850_IRQ_GetPendingIRQ
    #define RH850_IRQ_GetPendingIRQ                __RH850_IRQ_GetPendingIRQ             /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetPendingIRQ */
   #endif /* #ifndef RH850_IRQ_GetPendingIRQ */

   #ifndef RH850_IRQ_GetPendingIRQByPE
    #define RH850_IRQ_GetPendingIRQByPE            __RH850_IRQ_GetPendingIRQByPE         /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetPendingIRQ */
   #endif /* #ifndef RH850_IRQ_GetPendingIRQByPE */

   #ifndef RH850_IRQ_ClearPendingIRQ
    #define RH850_IRQ_ClearPendingIRQ              __RH850_IRQ_ClearPendingIRQ           /*!< Wrapper macro that calls the @ref __RH850_IRQ_ClearPendingIRQ */
   #endif /* #ifndef RH850_IRQ_ClearPendingIRQ */

   #ifndef RH850_IRQ_ClearPendingIRQByPE
    #define RH850_IRQ_ClearPendingIRQByPE          __RH850_IRQ_ClearPendingIRQByPE       /*!< Wrapper macro that calls the @ref __RH850_IRQ_ClearPendingIRQ */
   #endif /* #ifndef RH850_IRQ_ClearPendingIRQByPE */

   #ifndef RH850_IRQ_GetActive
    #define RH850_IRQ_GetActive                    __RH850_IRQ_GetActive                 /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetActive */
   #endif /* #ifndef RH850_IRQ_GetActive */

   #ifndef RH850_IRQ_GetActiveByPE
    #define RH850_IRQ_GetActiveByPE                __RH850_IRQ_GetActiveByPE             /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetActive */
   #endif /* #ifndef RH850_IRQ_GetActiveByPE */

   #ifndef RH850_IRQ_SetPriority
    #define RH850_IRQ_SetPriority                  __RH850_IRQ_SetPriority               /*!< Wrapper macro that calls the @ref __RH850_IRQ_SetPriority */
   #endif /* #ifndef RH850_IRQ_SetPriority */

   #ifndef RH850_IRQ_SetPriorityByPE
    #define RH850_IRQ_SetPriorityByPE              __RH850_IRQ_SetPriorityByPE           /*!< Wrapper macro that calls the @ref __RH850_IRQ_SetPriority */
   #endif /* #ifndef RH850_IRQ_SetPriorityByPE */

   #ifndef RH850_IRQ_GetPriority
    #define RH850_IRQ_GetPriority                  __RH850_IRQ_GetPriority               /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetPriority */
   #endif /* #ifndef RH850_IRQ_GetPriority */

   #ifndef RH850_IRQ_GetPriorityByPE
    #define RH850_IRQ_GetPriorityByPE              __RH850_IRQ_GetPriorityByPE           /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetPriority */
   #endif /* #ifndef RH850_IRQ_GetPriorityByPE */

   #ifndef RH850_IRQ_SetIRQMethod
    #define RH850_IRQ_SetIRQMethod                 __RH850_IRQ_SetIRQMethod              /*!< Wrapper macro that calls the @ref __RH850_IRQ_SetIRQMethod */
   #endif /* #ifndef RH850_IRQ_SetIRQMethod */

   #ifndef RH850_IRQ_SetIRQMethodByPE
    #define RH850_IRQ_SetIRQMethodByPE             __RH850_IRQ_SetIRQMethodByPE          /*!< Wrapper macro that calls the @ref __RH850_IRQ_SetIRQMethod */
   #endif /* #ifndef RH850_IRQ_SetIRQMethodByPE */

   #ifndef RH850_IRQ_GetIRQMethod
    #define RH850_IRQ_GetIRQMethod                 __RH850_IRQ_GetIRQMethod              /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetIRQMethod */
   #endif /* #ifndef RH850_IRQ_GetIRQMethod */

   #ifndef RH850_IRQ_GetIRQMethodByPE
    #define RH850_IRQ_GetIRQMethodByPE             __RH850_IRQ_GetIRQMethodByPE          /*!< Wrapper macro that calls the @ref __RH850_IRQ_GetIRQMethod */
   #endif /* #ifndef RH850_IRQ_GetIRQMethodByPE */

   #ifndef RH850_IRQ_SetIRQBoundToPE
    #define RH850_IRQ_SetIRQBoundToPE              __RH850_IRQ_SetIRQBoundToPE           /*!< Wrapper macro that calls the @ref __RH850_IRQ_IntMaskSet */
   #endif /* #ifndef RH850_IRQ_SetIRQBoundToPE */

   #ifndef RH850_IRQ_GetIRQBoundToPE
    #define RH850_IRQ_GetIRQBoundToPE              __RH850_IRQ_GetIRQBoundToPE           /*!< Wrapper macro that calls the @ref __RH850_IRQ_IntMaskSet */
   #endif /* #ifndef RH850_IRQ_GetIRQBoundToPE */
/** @} */ /* end of RH850_IRQ */
  #endif

/* #############################################  MPU functions  #################################################### */
  #if defined(__MPU_PRESENT) && (__MPU_PRESENT == 1U)

/**
 * @defgroup RH850_G4MH_MPU_API MPU API Functions
 * @brief MPU API Functions
 * @ingroup RH850_G4MH_API_Funcs
 * @{
 */

   #include "G4-profile/rh850_g4_mpu.h"

   #ifndef RH850_MPU_Enable
    #define RH850_MPU_Enable                    __RH850_MPU_Enable                 /*!< Wrapper macro that calls the @ref __RH850_MPU_Enable */
   #endif /* #ifndef RH850_MPU_Enable */

   #ifndef RH850_MPU_Disable
    #define RH850_MPU_Disable                   __RH850_MPU_Disable                /*!< Wrapper macro that calls the @ref __RH850_MPU_Disable */
   #endif /* #ifndef RH850_MPU_Disable */

   #ifndef RH850_MPU_MpidSet
    #define RH850_MPU_MpidSet                   __RH850_MPU_MpidSet                /*!< Wrapper macro that calls the @ref __RH850_MPU_MpidSet */
   #endif /* #ifndef RH850_MPU_MpidSet */

   #ifndef RH850_MPU_StateGet
    #define RH850_MPU_StateGet                  __RH850_MPU_StateGet               /*!< Wrapper macro that calls the @ref __RH850_MPU_StateGet */
   #endif /* #ifndef RH850_MPU_StateGet */

   #ifndef RH850_MPU_SvStateGet
    #define RH850_MPU_SvStateGet                __RH850_MPU_SvStateGet             /*!< Wrapper macro that calls the @ref __RH850_MPU_SvStateGet */
   #endif /* #ifndef RH850_MPU_SvStateGet */

   #ifndef RH850_MPU_NumberofRegionsGet
    #define RH850_MPU_NumberofRegionsGet        __RH850_MPU_NumberofRegionsGet     /*!< Wrapper macro that calls the @ref __RH850_MPU_NumberofRegionsGet */
   #endif /* #ifndef RH850_MPU_NumberofRegionsGet */

   #ifndef RH850_MPU_NumberOfBanksGet
    #define RH850_MPU_NumberOfBanksGet          __RH850_MPU_NumberOfBanksGet       /*!< Wrapper macro that calls the @ref __RH850_MPU_NumberOfBanksGet */
   #endif /* #ifndef RH850_MPU_NumberOfBanksGet */

   #ifndef RH850_MPU_ArchitectureVersionGet
    #define RH850_MPU_ArchitectureVersionGet    __RH850_MPU_ArchitectureVersionGet /*!< Wrapper macro that calls the @ref __RH850_MPU_ArchitectureVersionGet */
   #endif /* #ifndef RH850_MPU_ArchitectureVersionGet */

   #ifndef RH850_MPU_ExecMemProtectCheck
    #define RH850_MPU_ExecMemProtectCheck       __RH850_MPU_ExecMemProtectCheck    /*!< Wrapper macro that calls the @ref __RH850_MPU_ExecMemProtectCheck */
   #endif /* #ifndef RH850_MPU_ExecMemProtectCheck */

   #ifndef RH850_MPU_MpuIdSet
    #define RH850_MPU_MpuIdSet                  __RH850_MPU_MpuIdSet               /*!< Wrapper macro that calls the @ref __RH850_MPU_MpuIdSet */
   #endif /* #ifndef RH850_MPU_MpuIdSet */

   #ifndef RH850_MPU_BankGet
    #define RH850_MPU_BankGet                   __RH850_MPU_BankGet                /*!< Wrapper macro that calls the @ref __RH850_MPU_BankGet */
   #endif /* #ifndef RH850_MPU_BankGet */

   #ifndef RH850_MPU_AttrSet
    #define RH850_MPU_AttrSet                   __RH850_MPU_AttrSet                /*!< Wrapper macro that calls the @ref __RH850_MPU_AttrSet */
   #endif /* #ifndef RH850_MPU_AttrSet */

   #ifndef RH850_MPU_AttrGet
    #define RH850_MPU_AttrGet                   __RH850_MPU_AttrGet                /*!< Wrapper macro that calls the @ref __RH850_MPU_AttrGet */
   #endif /* #ifndef RH850_MPU_AttrGet */

   #ifndef RH850_MPU_RegionClear
    #define RH850_MPU_RegionClear               __RH850_MPU_RegionClear            /*!< Wrapper macro that calls the @ref __RH850_MPU_RegionClear */
   #endif /* #ifndef RH850_MPU_RegionClear */

   #ifndef RH850_MPU_RegionSet
    #define RH850_MPU_RegionSet                 __RH850_MPU_RegionSet              /*!< Wrapper macro that calls the @ref __RH850_MPU_RegionSet */
   #endif /* #ifndef RH850_MPU_RegionSet */

   #ifndef RH850_MPU_LowerAddressGet
    #define RH850_MPU_LowerAddressGet           __RH850_MPU_LowerAddressGet        /*!< Wrapper macro that calls the @ref __RH850_MPU_LowerAddressGet */
   #endif /* #ifndef RH850_MPU_LowerAddressGet */

   #ifndef RH850_MPU_UpperAddressGet
    #define RH850_MPU_UpperAddressGet           __RH850_MPU_UpperAddressGet        /*!< Wrapper macro that calls the @ref __RH850_MPU_UpperAddressGet */
   #endif /* #ifndef RH850_MPU_UpperAddressGet */
/** @} */ /* end of RH850_MPU */
  #endif

/* #############################################  PMU functions  #################################################### */
  #if defined(__PMU_PRESENT) && (__PMU_PRESENT == 1U)

/**
 * @defgroup RH850_G4MH_PMU_API PMU API Functions
 * @brief PMU API Functions
 * @ingroup RH850_G4MH_API_Funcs
 * @{
 */

   #include "G4-profile/rh850_g4_pmu.h"

   #ifndef RH850_PMU_ChannelEnable
    #define RH850_PMU_ChannelEnable     __RH850_PMU_ChannelEnable  /*!< Wrapper macro that calls the @ref __RH850_PMU_ChannelEnable */
   #endif /* #ifndef RH850_PMU_ChannelEnable */

   #ifndef RH850_PMU_ChannelDisable
    #define RH850_PMU_ChannelDisable    __RH850_PMU_ChannelDisable /*!< Wrapper macro that calls the @ref __RH850_PMU_ChannelDisable */
   #endif /* #ifndef RH850_PMU_ChannelDisable */

   #ifndef RH850_PMU_StatusGet
    #define RH850_PMU_StatusGet         __RH850_PMU_StatusGet      /*!< Wrapper macro that calls the @ref __RH850_PMU_StatusGet */
   #endif /* #ifndef RH850_PMU_StatusGet */

   #ifndef RH850_PMU_ModeSet
    #define RH850_PMU_ModeSet           __RH850_PMU_ModeSet        /*!< Wrapper macro that calls the @ref __RH850_PMU_ModeSet */
   #endif /* #ifndef RH850_PMU_ModeSet */

   #ifndef RH850_PMU_ControlSet
    #define RH850_PMU_ControlSet        __RH850_PMU_ControlSet     /*!< Wrapper macro that calls the @ref __RH850_PMU_ControlSet */
   #endif /* #ifndef RH850_PMU_ControlSet */

   #ifndef RH850_PMU_OvfGet
    #define RH850_PMU_OvfGet            __RH850_PMU_OverflowGet    /*!< Wrapper macro that calls the @ref __RH850_PMU_OverflowGet */
   #endif /* #ifndef RH850_PMU_OvfGet */

   #ifndef RH850_PMU_OvfClear
    #define RH850_PMU_OvfClear          __RH850_PMU_OverflowClear  /*!< Wrapper macro that calls the @ref __RH850_PMU_OverflowClear */
   #endif /* #ifndef RH850_PMU_OvfClear */

   #ifndef RH850_PMU_CountSet
    #define RH850_PMU_CountSet          __RH850_PMU_CounterSet     /*!< Wrapper macro that calls the @ref __RH850_PMU_CounterSet */
   #endif /* #ifndef RH850_PMU_CountSet */

   #ifndef RH850_PMU_CountGet
    #define RH850_PMU_CountGet          __RH850_PMU_CounterGet     /*!< Wrapper macro that calls the @ref __RH850_PMU_CounterGet */
   #endif /* #ifndef RH850_PMU_CountGet */

   #ifndef RH850_PMU_SubCountSet
    #define RH850_PMU_SubCountSet       __RH850_PMU_SubCountSet    /*!< Wrapper macro that calls the @ref __RH850_PMU_SubCountSet */
   #endif /* #ifndef RH850_PMU_SubCountSet */

   #ifndef RH850_PMU_SubCountGet
    #define RH850_PMU_SubCountGet       __RH850_PMU_SubCountGet    /*!< Wrapper macro that calls the @ref __RH850_PMU_SubCountGet */
   #endif /* #ifndef RH850_PMU_SubCountGet */
/** @} */ /* end of RH850_PMU */
  #endif

/* #############################################  TSC functions  #################################################### */
  #if defined(__TSC_PRESENT) && (__TSC_PRESENT == 1U)

/**
 * @defgroup RH850_G4MH_TSC_API TSC API Functions
 * @brief TSC API Functions
 * @ingroup RH850_G4MH_API_Funcs
 * @{
 */

   #include "G4-profile/rh850_g4_tsc.h"

   #ifndef RH850_TSC_Enable
    #define RH850_TSC_Enable            __RH850_TSC_Enable         /*!< Wrapper macro that calls the @ref __RH850_TSC_Enable */
   #endif /* #ifndef RH850_TSC_Enable */

   #ifndef RH850_TSC_Disable
    #define RH850_TSC_Disable           __RH850_TSC_Disable        /*!< Wrapper macro that calls the @ref __RH850_TSC_Disable */
   #endif /* #ifndef RH850_TSC_Disable */

   #ifndef RH850_TSC_EnableGet
    #define RH850_TSC_EnableGet         __RH850_TSC_EnableGet      /*!< Wrapper macro that calls the @ref __RH850_TSC_EnableGet */
   #endif /* #ifndef RH850_TSC_EnableGet */

   #ifndef RH850_TSC_ControlRead
    #define RH850_TSC_ControlRead       __RH850_TSC_ControlRead    /*!< Wrapper macro that calls the @ref __RH850_TSC_ControlRead */
   #endif /* #ifndef RH850_TSC_ControlRead */

   #ifndef RH850_TSC_ControlSet
    #define RH850_TSC_ControlSet        __RH850_TSC_ControlSet     /*!< Wrapper macro that calls the @ref __RH850_TSC_ControlSet */
   #endif /* #ifndef RH850_TSC_ControlSet */

   #ifndef RH850_TSC_OverflowGet
    #define RH850_TSC_OverflowGet       __RH850_TSC_OverflowGet    /*!< Wrapper macro that calls the @ref __RH850_TSC_OverflowGet */
   #endif /* #ifndef RH850_TSC_OverflowGet */

   #ifndef RH850_TSC_OverflowClear
    #define RH850_TSC_OverflowClear     __RH850_TSC_OverflowClear  /*!< Wrapper macro that calls the @ref __RH850_TSC_OverflowClear */
   #endif /* #ifndef RH850_TSC_OverflowClear */

   #ifndef RH850_TSC_CounterHighGet
    #define RH850_TSC_CounterHighGet    __RH850_TSC_CounterHighGet /*!< Wrapper macro that calls the @ref __RH850_TSC_CounterHighGet */
   #endif /* #ifndef RH850_TSC_CounterHighGet */

   #ifndef RH850_TSC_CounterHighSet
    #define RH850_TSC_CounterHighSet    __RH850_TSC_CounterHighSet /*!< Wrapper macro that calls the @ref __RH850_TSC_CounterHighSet */
   #endif /* #ifndef RH850_TSC_CounterHighSet */

   #ifndef RH850_TSC_CounterLowGet
    #define RH850_TSC_CounterLowGet     __RH850_TSC_CounterLowGet  /*!< Wrapper macro that calls the @ref __RH850_TSC_CounterLowGet */
   #endif /* #ifndef RH850_TSC_CounterLowGet */

   #ifndef RH850_TSC_CounterLowSet
    #define RH850_TSC_CounterLowSet     __RH850_TSC_CounterLowSet  /*!< Wrapper macro that calls the @ref __RH850_TSC_CounterLowSet */
   #endif /* #ifndef RH850_TSC_CounterLowSet */

   #ifndef RH850_TSC_CounterFullGet
    #define RH850_TSC_CounterFullGet    __RH850_TSC_CounterFullGet /*!< Wrapper macro that calls the @ref __RH850_TSC_CounterFullGet */
   #endif /* #ifndef RH850_TSC_CounterFullGet */
/** @} */ /* end of RH850_TSC */
  #endif

/** @} */ /* end of RH850_G4MH_API_Funcs */

  #ifdef __cplusplus
}
  #endif

 #endif                                /* __CORE_RH850_G4MH_H_DEPENDANT */

#endif                                 /* __RH850_GENERIC */
