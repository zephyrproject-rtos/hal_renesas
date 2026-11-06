/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_FAULT_TRACE_H
#define BSP_FAULT_TRACE_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_FAULT_TRACE BSP Fault Trace
 * @brief This section provides Fault Tracing support.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_FT_CAPTURE                              (0x4654U) /* PRQA S 1710 # Advisory D-4.5 */ ///< FT (Fault Trace) in ASCII - set once g_fault_trace holds a snapshot
#define BSP_FT_NOT_CAPTURED                         (0x00U)                                      ///< Value states that g_fault_trace has not captured any exception
#define BSP_FT_EXCEPTION_CAUSE_LOOKUP_TABLE_SIZE    (0x100U)                                     ///< Size of exception cause lookup table
#define BSP_FT_NON_ISR_TRIGGERED                    (0xFFFFFFFFU)                                ///< No interrupt triggered value for Fault Trace

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Exception cause */
typedef enum e_bsp_ft_exception_cause                   /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_FT_EXCEPTION_CAUSE_NONE,                        ///< Non exception occur
    BSP_FT_EXCEPTION_CAUSE_MDP_TABLE_REF_INTERRUPT,     ///< Memory protection violation due to an interrupt using the table reference method
    BSP_FT_EXCEPTION_CAUSE_SYSERR_SAVE_REG_BANK,        ///< Error due to context saving to the register bank
    BSP_FT_EXCEPTION_CAUSE_UNREGISTERED_USER_IRQ,       ///< Unregistered user IRQ
    BSP_FT_EXCEPTION_CAUSE_MIP,                         ///< Memory protection violation due to instruction fetching
    BSP_FT_EXCEPTION_CAUSE_SYSERR_INSTRUCTION_FETCHING, ///< Error due to instruction fetching
    BSP_FT_EXCEPTION_CAUSE_UCPOP,                       ///< Execution of a coprocessor instruction/access permission violation
    BSP_FT_EXCEPTION_CAUSE_RIE,                         ///< Execution of a reserved instruction
    BSP_FT_EXCEPTION_CAUSE_PIE,                         ///< Execution of a privileged instruction/access permission violation
    BSP_FT_EXCEPTION_CAUSE_SYSERR_CONTEXT_RESTORE,      ///< Error prior to context restoration from the register bank
    BSP_FT_EXCEPTION_CAUSE_MAE,                         ///< Misaligned access occurrence
    BSP_FT_EXCEPTION_CAUSE_FPE,                         ///< Execution of an FPU instruction
    BSP_FT_EXCEPTION_CAUSE_FXE,                         ///< Execution of an FXU instruction
    BSP_FT_EXCEPTION_CAUSE_MDP_OPERAND_ACCESS,          ///< Memory protection violation due to operand access
    BSP_FT_EXCEPTION_CAUSE_SYSCALL,                     ///< Execution of the SYSCALL instruction
    BSP_FT_EXCEPTION_CAUSE_FETRAP,                      ///< Execution of the FETRAP instruction
    BSP_FT_EXCEPTION_CAUSE_TRAP0,                       ///< Execution of the TRAP0 instruction
    BSP_FT_EXCEPTION_CAUSE_TRAP1,                       ///< Execution of the TRAP1 instruction
#if (BSP_FEATURE_FPU_IMPRECISE_EXCEPTION_IS_AVAILABLE)
    BSP_FT_EXCEPTION_CAUSE_FPI,                         ///< Execution of an FPU (imprecise) instruction
#endif /* BSP_FEATURE_FPU_IMPRECISE_EXCEPTION_IS_AVAILABLE */
} bsp_ft_exception_cause_t;

/** Fault trace capture structure */
typedef struct st_bsp_ft_capture                                                               /* PRQA S 1536 # Advisory R-2.4 */
{
    uint32_t capture;                                                                          ///< BSP_FT_CAPTURE once a fault has been latched
    uint32_t count;                                                                            ///< Total faults seen (FIRST snapshot is retained)
    uint32_t eipc; /* PRQA S 1710 # Advisory D-4.5 */                                          ///< EI return PC (interrupted foreground/ISR)
    uint32_t eipsw; /* PRQA S 1710 # Advisory D-4.5 */                                         ///< PSW at the moment the EI was taken
    uint32_t fepc; /* PRQA S 1710 # Advisory D-4.5 */                                          ///< FE return PC == faulting instr (MIP/MDP/SYSERR)
    uint32_t fepsw; /* PRQA S 1710 # Advisory D-4.5 */                                         ///< PSW at the moment the FE exception was taken
    uint32_t psw; /* PRQA S 1710 # Advisory D-4.5 */                                           ///< Current PSW inside the trap (NP/EP/ID)
    uint32_t fpsr; /* PRQA S 1710 # Advisory D-4.5 */                                          ///< FPU configuration/status - non-zero => FPU was in use
    uint32_t fpepc; /* PRQA S 1710 # Advisory D-4.5 */                                         ///< FPU exception return PC
#if (BSP_FEATURE_FPEC_REGISTER_IS_AVAILABLE)
    uint32_t fpec; /* PRQA S 1710 # Advisory D-4.5 */                                          ///< FPU exception control
#endif                                                                                         /* BSP_FEATURE_FPEC_REGISTER_IS_AVAILABLE */
    uint32_t                 eiic; /* PRQA S 1710 # Advisory D-4.5 */                          ///< EI cause (val & 0xFFF) == last EI number
    uint32_t                 feic; /* PRQA S 1710 # Advisory D-4.5 */                          ///< FE cause code
    uint32_t                 ctpc; /* PRQA S 1710 # Advisory D-4.5 */                          ///< SR16,0 - The address of the next instruction after the CALLT instruction
    uint32_t                 ctpsw; /* PRQA S 1710 # Advisory D-4.5 */                         ///< SR17,0 - The PSW settings when executing CALLT instruction
    uint32_t                 ctbp; /* PRQA S 1710 # Advisory D-4.5 */                          ///< SR20,0 - CALLT base pointer
    uint32_t                 eiwr; /* PRQA S 1710 # Advisory D-4.5 */                          ///< SR28,0 - EI working register (nested EIIC preserve)
    uint32_t                 fewr; /* PRQA S 1710 # Advisory D-4.5 */                          ///< SR29,0 - FE working register
    uint32_t                 spid; /* PRQA S 1710 # Advisory D-4.5 */                          ///< System protection identifier
    uint32_t                 spidlist; /* PRQA S 1710 # Advisory D-4.5 */                      ///< List of system protection identifiers that can be specified in SPID
    uint32_t                 rbase; /* PRQA S 1710 # Advisory D-4.5 */                         ///< Reset vector base address
    uint32_t                 ebase; /* PRQA S 1710 # Advisory D-4.5 */                         ///< Exception handler vector address
    uint32_t                 intbp; /* PRQA S 1710, 0288 # Advisory D-4.5, DP_MSR_D-1.1_UC1 */ ///< Base address of the interrupt handler “address” table
    uint32_t                 pid;                                                              ///< Processor ID
    uint32_t                 sccfg; /* PRQA S 1710 # Advisory D-4.5 */                         ///< SYSCALL operation setting
    uint32_t                 scbp; /* PRQA S 1710 # Advisory D-4.5 */                          ///< SYSCALL base pointer
    uint32_t                 peid;                                                             ///< Processor element identifier
    uint32_t                 bmid; /* PRQA S 1710 # Advisory D-4.5 */                          ///< Bus master identifier
    uint32_t                 mea; /* PRQA S 1710 # Advisory D-4.5 */                           ///< Memory error address (MPU exception)
    uint32_t                 mei; /* PRQA S 1710 # Advisory D-4.5 */                           ///< Memory error information (MPU exception)
    uint32_t                 rbcr0; /* PRQA S 1710 # Advisory D-4.5 */                         ///< SR15,2 - register bank control 0
    uint32_t                 rbcr1; /* PRQA S 1710 # Advisory D-4.5 */                         ///< SR16,2 - register bank control 1
    uint32_t                 rbnr; /* PRQA S 1710 # Advisory D-4.5 */                          ///< SR17,2 - register bank number
    uint32_t                 rbip; /* PRQA S 1710 # Advisory D-4.5 */                          ///< SR18,2 - register bank initial pointer
    uint32_t                 isr_active;                                                       ///< Channel number of the unregistered ISR that triggered the fault
    bsp_ft_exception_cause_t exception;                                                        ///< Exception type
} bsp_ft_capture_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern volatile bsp_ft_capture_t         g_fault_trace;
extern volatile bsp_ft_exception_cause_t g_exception_cause_lookup_table[BSP_FT_EXCEPTION_CAUSE_LOOKUP_TABLE_SIZE];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* Latch exception state into g_fault_trace. Call from the BSP DummyIsr,
 * then spin so the debugger can inspect g_fault_trace. */
void bsp_ft_capture(void);
void bsp_ft_init(void);

/** @} (end addtogroup BSP_FAULT_TRACE) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_FAULT_TRACE_H */
