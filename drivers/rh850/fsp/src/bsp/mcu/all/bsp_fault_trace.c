/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_fault_trace.h"                                                  /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_FT_SYSCALL_EXCEPTION_START_VALUE                        (0x8000U) ///< Start value of Syscall exception code
#define BSP_FT_USER_INTERRUPT_START_VALUE                           (0x1000U) ///< Start value of user interrupt number
#define BSP_FT_SV_UM_MDP_TABLE_REF_INTERRUPT_EXCEPTION_VALUE        (0x95U)   ///< Value of memory protection violation due to an interrupt using the table reference method exception (in SV/UM operating mode)
#define BSP_FT_HV_MDP_TABLE_REF_INTERRUPT_EXCEPTION_VALUE           (0x9DU)   ///< Value of memory protection violation due to an interrupt using the table reference method exception (in HV operating mode)
#define BSP_FT_SYSERR_SAVE_REG_BANK_EXCEPTION_VALUE                 (0x1CU)   ///< Value of error due to context saving to the register bank
#define BSP_FT_SV_UM_MIP_EXCEPTION_VALUE                            (0x90U)   ///< Value of memory protection violation due to instruction fetching exception (in SV/UM operating mode)
#define BSP_FT_HV_MIP_EXCEPTION_VALUE                               (0x98U)   ///< Value of memory protection violation due to instruction fetching exception (in HV operating mode)
#define BSP_FT_RIE_EXCEPTION_VALUE                                  (0x60U)   ///< Value of execution of a reserved instruction exception
#define BSP_FT_PIE_EXCEPTION_VALUE                                  (0xA0U)   ///< Value of execution of a privileged instruction/access permission violation exception
#define BSP_FT_SYSERR_CONTEXT_RESTORE_EXCEPTION_VALUE               (0x1DU)   ///< Value of error prior to context restoration from the register bank exception
#define BSP_FT_MAE_EXCEPTION_VALUE                                  (0xC0U)   ///< Value of misaligned access occurrence exception
#define BSP_FT_FPU_EXCEPTION_VALUE                                  (0x71U)   ///< Value of execution of an FPU instruction exception
#define BSP_FT_FXU_EXCEPTION_VALUE                                  (0x75U)   ///< Value of execution of an FXU instruction exception
#define BSP_FT_SV_UM_MDP_OPERAND_ACCESS_EXCEPTION_VALUE             (0x91U)   ///< Value of memory protection violation due to operand access exception (in SV/UM operating mode)
#define BSP_FT_HV_MDP_OPERAND_ACCESS_EXCEPTION_VALUE                (0x99U)   ///< Value of memory protection violation due to operand access exception (in HV operating mode)
#define BSP_FT_INSTRUCTION_SYSERR_FETCHING_EXCEPTION_START_VALUE    (0x10U)   ///< Start value of error due to instruction fetching exception
#define BSP_FT_INSTRUCTION_SYSERR_FETCHING_EXCEPTION_END_VALUE      (0x1FU)   ///< End value of error due to instruction fetching exception
#define BSP_FT_UCPOP_EXCEPTION_START_VALUE                          (0x80U)   ///< Start value of coprocessor instruction/access permission violation exception
#define BSP_FT_UCPOP_EXCEPTION_END_VALUE                            (0x82U)   ///< End value of coprocessor instruction/access permission violation exception
#define BSP_FT_FETRAP_EXCEPTION_START_VALUE                         (0x31U)   ///< Start value of execution of the FETRAP instruction exception
#define BSP_FT_FETRAP_EXCEPTION_END_VALUE                           (0x3FU)   ///< End value of execution of the FETRAP instruction exception
#define BSP_FT_TRAP0_EXCEPTION_START_VALUE                          (0x40U)   ///< Start value of execution of the TRAP0 instruction exception
#define BSP_FT_TRAP0_EXCEPTION_END_VALUE                            (0x4FU)   ///< End value of execution of the TRAP0 instruction exception
#define BSP_FT_TRAP1_EXCEPTION_START_VALUE                          (0x50U)   ///< Start value of execution of the TRAP1 instruction exception
#define BSP_FT_TRAP1_EXCEPTION_END_VALUE                            (0x5FU)   ///< End value of execution of the TRAP1 instruction exception

#if (BSP_FEATURE_FPU_IMPRECISE_EXCEPTION_IS_AVAILABLE)
 #define BSP_FT_FPU_IMPRECISE_EXCEPTION_VALUE                       (0x72U)   ///< Value of execution of an FPU instruction (imprecise) exception
#endif /* BSP_FEATURE_FPU_IMPRECISE_EXCEPTION_IS_AVAILABLE */

#define BSP_FT_USER_INTERRUPT_MASK                                  (0xFFFU)  ///< Value used to extract user interrupt number from EIIC register value
#define BSP_FT_16BIT_LOWER_MASK                                     (0xFFFFU) ///< Value used to mask 16-bit lower

/***********************************************************************************************************************
 * Variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Fault Trace variable captures the state of the system registers at the time of the device enter the DummyIsr function
 **********************************************************************************************************************/
volatile bsp_ft_capture_t         g_fault_trace;
volatile bsp_ft_exception_cause_t g_exception_cause_lookup_table[BSP_FT_EXCEPTION_CAUSE_LOOKUP_TABLE_SIZE]; /* PRQA S 1504 # Advisory R-8.7 */

/*******************************************************************************************************************//**
 * Initializes variable to store exception cause code.
 **********************************************************************************************************************/
void bsp_ft_init (void)
{
    uint16_t index;

    /* Assign Memory protection exception (access privilege) to lookup table */
    g_exception_cause_lookup_table[BSP_FT_SV_UM_MDP_TABLE_REF_INTERRUPT_EXCEPTION_VALUE] =
        BSP_FT_EXCEPTION_CAUSE_MDP_TABLE_REF_INTERRUPT;
    g_exception_cause_lookup_table[BSP_FT_HV_MDP_TABLE_REF_INTERRUPT_EXCEPTION_VALUE] =
        BSP_FT_EXCEPTION_CAUSE_MDP_TABLE_REF_INTERRUPT;

    /* Assign Memory protection exception (execution privilege) to lookup table */
    g_exception_cause_lookup_table[BSP_FT_SV_UM_MIP_EXCEPTION_VALUE] = BSP_FT_EXCEPTION_CAUSE_MIP;
    g_exception_cause_lookup_table[BSP_FT_HV_MIP_EXCEPTION_VALUE]    = BSP_FT_EXCEPTION_CAUSE_MIP;

    /* Assign Reserved instruction exception to lookup table */
    g_exception_cause_lookup_table[BSP_FT_RIE_EXCEPTION_VALUE] = BSP_FT_EXCEPTION_CAUSE_RIE;

    /* Assign Privilege instruction exception to lookup table */
    g_exception_cause_lookup_table[BSP_FT_PIE_EXCEPTION_VALUE] = BSP_FT_EXCEPTION_CAUSE_PIE;

    /* Assign Misalignment exception to lookup table */
    g_exception_cause_lookup_table[BSP_FT_MAE_EXCEPTION_VALUE] = BSP_FT_EXCEPTION_CAUSE_MAE;

    /* Assign FPU exception (precise) to lookup table */
    g_exception_cause_lookup_table[BSP_FT_FPU_EXCEPTION_VALUE] = BSP_FT_EXCEPTION_CAUSE_FPE;

    /* Assign FXU exception (precise) to lookup table */
    g_exception_cause_lookup_table[BSP_FT_FXU_EXCEPTION_VALUE] = BSP_FT_EXCEPTION_CAUSE_FXE;

    /* Assign Memory protection exception (access privilege) to lookup table */
    g_exception_cause_lookup_table[BSP_FT_SV_UM_MDP_OPERAND_ACCESS_EXCEPTION_VALUE] =
        BSP_FT_EXCEPTION_CAUSE_MDP_OPERAND_ACCESS;
    g_exception_cause_lookup_table[BSP_FT_HV_MDP_OPERAND_ACCESS_EXCEPTION_VALUE] =
        BSP_FT_EXCEPTION_CAUSE_MDP_OPERAND_ACCESS;

#if (BSP_FEATURE_FPU_IMPRECISE_EXCEPTION_IS_AVAILABLE)

    /* Assign FPU exception (imprecise) to lookup table */
    g_exception_cause_lookup_table[BSP_FT_FPU_IMPRECISE_EXCEPTION_VALUE] = BSP_FT_EXCEPTION_CAUSE_FPI;
#endif                                 /* BSP_FEATURE_FPU_IMPRECISE_EXCEPTION_IS_AVAILABLE */

    /* Assign Error due to instruction fetching exception to lookup table */
    for (index = BSP_FT_INSTRUCTION_SYSERR_FETCHING_EXCEPTION_START_VALUE;
         index <= BSP_FT_INSTRUCTION_SYSERR_FETCHING_EXCEPTION_END_VALUE;
         index++)
    {
        g_exception_cause_lookup_table[index] = BSP_FT_EXCEPTION_CAUSE_SYSERR_INSTRUCTION_FETCHING;
    }

    /* Assign error due to context saving to the register bank exception to lookup table */
    g_exception_cause_lookup_table[BSP_FT_SYSERR_SAVE_REG_BANK_EXCEPTION_VALUE] =
        BSP_FT_EXCEPTION_CAUSE_SYSERR_SAVE_REG_BANK;

    /* Assign Error prior to context restoration from the register bank to lookup table */
    g_exception_cause_lookup_table[BSP_FT_SYSERR_CONTEXT_RESTORE_EXCEPTION_VALUE] =
        BSP_FT_EXCEPTION_CAUSE_SYSERR_CONTEXT_RESTORE;

    /* Assign Coprocessor unusable exception to lookup table */
    for (index = BSP_FT_UCPOP_EXCEPTION_START_VALUE; index <= BSP_FT_UCPOP_EXCEPTION_END_VALUE; index++)
    {
        g_exception_cause_lookup_table[index] = BSP_FT_EXCEPTION_CAUSE_UCPOP;
    }

    /* Assign FE level trap exception to lookup table */
    for (index = BSP_FT_FETRAP_EXCEPTION_START_VALUE; index <= BSP_FT_FETRAP_EXCEPTION_END_VALUE; index++)
    {
        g_exception_cause_lookup_table[index] = BSP_FT_EXCEPTION_CAUSE_FETRAP;
    }

    /* Assign EI level trap 0 exception to lookup table */
    for (index = BSP_FT_TRAP0_EXCEPTION_START_VALUE; index <= BSP_FT_TRAP0_EXCEPTION_END_VALUE; index++)
    {
        g_exception_cause_lookup_table[index] = BSP_FT_EXCEPTION_CAUSE_TRAP0;
    }

    /* Assign EI level trap 1 exception to lookup table */
    for (index = BSP_FT_TRAP1_EXCEPTION_START_VALUE; index <= BSP_FT_TRAP1_EXCEPTION_END_VALUE; index++)
    {
        g_exception_cause_lookup_table[index] = BSP_FT_EXCEPTION_CAUSE_TRAP1;
    }

    g_fault_trace.capture    = BSP_FT_NOT_CAPTURED;
    g_fault_trace.count      = 0U;
    g_fault_trace.isr_active = BSP_FT_NON_ISR_TRIGGERED;
    g_fault_trace.exception  = BSP_FT_EXCEPTION_CAUSE_NONE;
}

/*******************************************************************************************************************//**
 * Using the global variable g_fault_trace to capture the state of the system registers at the time of the device enter the
 * DummyIsr function. Only capture the first exception or unregistered ISRs.
 **********************************************************************************************************************/
void bsp_ft_capture (void)
{
    uint16_t eiic_code;
    uint16_t feic_code;

    /* PRQA S 0288 ++ # DP_MSR_D-1.1_UC1 */

    /* Always increment the count (saturate at UINT32_MAX); retain the FIRST snapshot - it is closest to the root cause.
     * A later cascading fault must not overwrite the original evidence. */

    /* PRQA S 0288 -- */
    g_fault_trace.count = (g_fault_trace.count != UINT32_MAX) ? (g_fault_trace.count + 1U) : UINT32_MAX; /* PRQA S 1281 # DP_MSR_R-7.2_UC1 */

    if (BSP_FT_CAPTURE != g_fault_trace.capture)
    {
        g_fault_trace.eipc  = __get_EIPC();                                                              /* EIPC - interrupted foreground PC */
        g_fault_trace.eipsw = __get_EIPSW();                                                             /* EIPSW */
        g_fault_trace.fepc  = __get_FEPC();                                                              /* FEPC - faulting instruction PC */
        g_fault_trace.fepsw = __get_FEPSW();                                                             /* FEPSW */
        g_fault_trace.psw   = __get_PSW();                                                               /* PSW - current (NP/EP/ID) */
        g_fault_trace.fpsr  = __get_FPSR();                                                              /* FPSR - FPU in use if non-zero */
        g_fault_trace.fpepc = __get_FPEPC();                                                             /* FPEPC */
#if (BSP_FEATURE_FPEC_REGISTER_IS_AVAILABLE)
        g_fault_trace.fpec = __get_FPEC();                                                               /* FPEC */
#endif                                                                                                   /* BSP_FEATURE_FPEC_REGISTER_IS_AVAILABLE */
        g_fault_trace.eiic     = __get_EIIC();                                                           /* EIIC - (& 0xFFF) = last EI channel */
        g_fault_trace.feic     = __get_FEIC();                                                           /* FEIC - FE cause code */
        g_fault_trace.ctpc     = __get_CTPC();                                                           /* CTPC - The address of the next instruction after the CALLT instruction */
        g_fault_trace.ctpsw    = __get_CTPSW();                                                          /* CTPSW - The PSW settings when executing CALLT instruction */
        g_fault_trace.ctbp     = __get_CTBP();                                                           /* CTBP - CALLT base pointer */
        g_fault_trace.eiwr     = __get_EIWR();                                                           /* EIWR - EI working register */
        g_fault_trace.fewr     = __get_FEWR();                                                           /* FEWR - FE working register */
        g_fault_trace.spid     = __get_SPID();                                                           /* SPID - System protection identifier */
        g_fault_trace.spidlist = __get_SPIDLIST();                                                       /* SPIDLIST - List of system protection identifiers that can be specified in SPID */
        g_fault_trace.rbase    = __get_RBASE();                                                          /* RBASE - Reset vector base address */
        g_fault_trace.ebase    = __get_EBASE();                                                          /* EBASE - Exception handler vector address */
        g_fault_trace.intbp    = __get_INTBP();                                                          /* INTBP - Base address of the interrupt handler "address" table */
        g_fault_trace.pid      = __get_PID();                                                            /* PID - Processor ID */
        g_fault_trace.sccfg    = __get_SCCFG();                                                          /* SCCFG - SYSCALL operation setting */
        g_fault_trace.scbp     = __get_SCBP();                                                           /* SCBP - SYSCALL base pointer */
        g_fault_trace.peid     = __get_PEID();                                                           /* PEID - Processor element identifier */
        g_fault_trace.bmid     = __get_BMID();                                                           /* BMID - Bus master identifier */
        g_fault_trace.mea      = __get_MEA();                                                            /* MEA - memory error address */
        g_fault_trace.mei      = __get_MEI();                                                            /* MEI - memory error info */
        g_fault_trace.rbcr0    = __get_RBCR0();                                                          /* RBCR0 - register bank control 0 */
        g_fault_trace.rbcr1    = __get_RBCR1();                                                          /* RBCR1 - register bank control 1 */
        g_fault_trace.rbnr     = __get_RBNR();                                                           /* RBNR - current bank number */
        g_fault_trace.rbip     = __get_RBIP();                                                           /* RBIP - register bank initial pointer */

        /* Extract exception cause */
        eiic_code = (uint16_t) (g_fault_trace.eiic & BSP_FT_16BIT_LOWER_MASK);
        feic_code = (uint16_t) (g_fault_trace.feic & BSP_FT_16BIT_LOWER_MASK);

        if ((0U != feic_code) && (BSP_FT_EXCEPTION_CAUSE_LOOKUP_TABLE_SIZE > feic_code))
        {
            g_fault_trace.exception = g_exception_cause_lookup_table[feic_code];
        }

        if (BSP_FT_EXCEPTION_CAUSE_NONE == g_fault_trace.exception)
        {
            if (BSP_FT_SYSCALL_EXCEPTION_START_VALUE <= eiic_code)
            {
                g_fault_trace.exception = BSP_FT_EXCEPTION_CAUSE_SYSCALL;
            }
            else if (BSP_FT_USER_INTERRUPT_START_VALUE <= eiic_code)
            {
                g_fault_trace.isr_active = g_fault_trace.eiic & BSP_FT_USER_INTERRUPT_MASK;
                g_fault_trace.exception  = BSP_FT_EXCEPTION_CAUSE_UNREGISTERED_USER_IRQ;
            }
            else if ((0x00U < eiic_code) && (BSP_FT_EXCEPTION_CAUSE_LOOKUP_TABLE_SIZE > eiic_code))
            {
                g_fault_trace.exception = g_exception_cause_lookup_table[eiic_code];
            }
            else
            {
                /* Do nothing */
            }
        }

        g_fault_trace.capture = BSP_FT_CAPTURE;
    }
}
