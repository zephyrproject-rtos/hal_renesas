/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_pz_hypervisor.h"
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#if BSP_PZ_SECURE_BUILD
 #if defined(__CCRX__)
  #define __SET_TRCTB(x)    bsp_set_trctb((uint32_t) (x))
  #define __SET_WINTB(x)    bsp_set_wintb((uint32_t) (x))
 #else
  #define __SET_TRCTB(x)    __asm volatile ("trmvtc %0, trctb" : : "r" (x) :)
  #define __SET_WINTB(x)    __asm volatile ("trmvtc %0, wintb" : : "r" (x) :)
 #endif

/* Error handlers are used as NS transition addresses since NS transitions are prohibited. */
 #define BSP_PZ_NS_INT_CALL_ADDRESS           r_bsp_pz_error_handler
 #define BSP_PZ_NS_SC_CALL_ADDRESS            r_bsp_pz_error_handler

 #define BSP_PZ_INTEGRITY_SIGNATURE_NS_INT    0x55555555
 #define BSP_PZ_INTEGRITY_SIGNATURE_NS_SC     0x77777777

 #define BSP_PZ_TRCALL_VECTOR_SIZE            (256U)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if BSP_PZ_SECURE_BUILD

typedef void (* bsp_pz_vector_func_t)(void);

/*
 *  WORLD Context Type
 */
typedef struct st_bsp_pz_world_context
{
    uint32_t psw;
    uint32_t pc;
    uint32_t usp;
} bsp_pz_world_context_t;

#endif

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

#if BSP_PZ_SECURE_BUILD
extern bsp_ssc_handler_t g_bsp_pz_ssc_table[BSP_PZ_CFG_SSC_NUM];
#endif

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
#if BSP_PZ_SECURE_BUILD
static void r_bsp_trcall_enter_ns(void)  BSP_ATTRIBUTE_STACKLESS;
static void r_bsp_trcall_call_ssc(void)  BSP_ATTRIBUTE_STACKLESS;
static void r_bsp_trcall_return_ssc(void)  BSP_ATTRIBUTE_STACKLESS;

 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS void r_bsp_trcall_call_nssc(void);
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS void r_bsp_trcall_return_nssc(void);

 #else
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS static void r_bsp_trcall_call_nssc(void);
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS static void r_bsp_trcall_return_nssc(void);

 #endif
BSP_ATTRIBUTE_STACKLESS static void r_bsp_trcall_return_sint(void);

 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS void r_bsp_trcall_return_nsint(void);

 #else
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS static void r_bsp_trcall_return_nsint(void);

 #endif
BSP_ATTRIBUTE_STACKLESS static void                 r_bsp_sint_from_ns(void);
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS static void r_bsp_nsint_from_s(void);
BSP_ATTRIBUTE_STACKLESS static void                 r_bsp_rint_handler(void);

 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS void r_bsp_ssc_adapter(void);
BSP_DONT_REMOVE bsp_ssc_err_t                r_bsp_call_ssc_handler(intptr_t par1,
                                                                    intptr_t par2,
                                                                    intptr_t par3,
                                                                    intptr_t par4,
                                                                    uint32_t ssc_id);
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS void r_bsp_call_sint_handler(void);
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS void r_bsp_pz_error_handler(void);

 #else
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS static void r_bsp_ssc_adapter(void);
BSP_DONT_REMOVE static bsp_ssc_err_t                r_bsp_call_ssc_handler(intptr_t par1,
                                                                           intptr_t par2,
                                                                           intptr_t par3,
                                                                           intptr_t par4,
                                                                           uint32_t ssc_id);
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS static void r_bsp_call_sint_handler(void);
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS static void r_bsp_pz_error_handler(void);

 #endif

BSP_ATTRIBUTE_STACKLESS static void r_bsp_pz_default_handler(void);

#endif

#if BSP_PZ_NONSECURE_BUILD
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS void r_bsp_call_nsint_handler(void);
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS void r_bsp_call_nssc_handler(void);

 #else
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS static void r_bsp_call_nsint_handler(void);
BSP_DONT_REMOVE BSP_ATTRIBUTE_STACKLESS static void r_bsp_call_nssc_handler(void);

 #endif

#endif

#if BSP_PZ_SECURE_BUILD
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "Symbol is undefined for reference the g_bsp_secure_context.". */
bsp_pz_world_context_t g_bsp_secure_context;

/* Deleted static declaration to fix build error "Symbol is undefined for reference the g_bsp_nonsecure_context.". */
bsp_pz_world_context_t g_bsp_nonsecure_context;
 #else

static bsp_pz_world_context_t g_bsp_secure_context __attribute__((used));
  #if defined(__ICCRX__)
static bsp_pz_world_context_t g_bsp_nonsecure_context __attribute__((used));
  #else
static bsp_pz_world_context_t g_bsp_nonsecure_context;
  #endif
 #endif

/* Secure TRCALL vector table.
 * Used entries are defined at declaration time using vector number macros.
 * Unused entries are filled with the error handler at runtime by R_BSP_SecureEnter(). */
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "Symbol is undefined for reference the g_bsp_trcall_table_s.". */
bsp_pz_vector_func_t g_bsp_trcall_table_s[BSP_PZ_TRCALL_VECTOR_SIZE] BSP_ALIGN_VARIABLE(4) =
 #else
static bsp_pz_vector_func_t g_bsp_trcall_table_s[BSP_PZ_TRCALL_VECTOR_SIZE] BSP_ALIGN_VARIABLE(4) =
 #endif
{
    [BSP_PZ_TRCALL_VECTOR_ENTER_NS]    = r_bsp_trcall_enter_ns,
    [BSP_PZ_TRCALL_VECTOR_RETURN_SINT] = r_bsp_trcall_return_sint,
    [BSP_PZ_TRCALL_VECTOR_RETURN_SSC]  = r_bsp_trcall_return_ssc,
    [BSP_PZ_TRCALL_VECTOR_CALL_NSSC]   = r_bsp_pz_error_handler, /* NSSC call is prohibited */
};

/* Non-Secure TRCALL vector table. */
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "Symbol is undefined for reference the g_bsp_trcall_table_ns.". */
bsp_pz_vector_func_t g_bsp_trcall_table_ns[BSP_PZ_TRCALL_VECTOR_SIZE] BSP_ALIGN_VARIABLE(4) =
 #else
static bsp_pz_vector_func_t g_bsp_trcall_table_ns[BSP_PZ_TRCALL_VECTOR_SIZE] BSP_ALIGN_VARIABLE(4) =
 #endif
{
    [BSP_PZ_TRCALL_VECTOR_CALL_SSC]      = r_bsp_trcall_call_ssc,
    [BSP_PZ_TRCALL_VECTOR_RETURN_NS_INT] = r_bsp_pz_error_handler, /* Non-Secure IRQ return is prohibited */
    [BSP_PZ_TRCALL_VECTOR_RETURN_NS_SC]  = r_bsp_pz_error_handler, /* NS_SC return is prohibited */
};

/* World transition interrupt vector table. */
static const bsp_pz_vector_func_t g_bsp_world_interrupts_table[] BSP_ALIGN_VARIABLE (4) =
{
    r_bsp_rint_handler,
    r_bsp_sint_from_ns,
    r_bsp_nsint_from_s                 /* Non-Secure IRQs during Secure execution are prohibited. */
};

/******************************************************************************
 * R_BSP_SecureEnter() is Root process for transitioning
 * from Root to Secure.
 *****************************************************************************/
void R_BSP_SecureEnter (uint32_t pc_adrs, uint32_t psw_data)
{
    /* Fill the unused TRCALL vector entries with the error handler. */
    for (uint32_t i = 0; i < BSP_PZ_TRCALL_VECTOR_SIZE; i++)
    {
        if (NULL == g_bsp_trcall_table_s[i])
        {
            g_bsp_trcall_table_s[i] = r_bsp_pz_default_handler;
        }

        if (NULL == g_bsp_trcall_table_ns[i])
        {
            g_bsp_trcall_table_ns[i] = r_bsp_pz_default_handler;
        }
    }

    /* Set the world transition interrupt vector table. */
    __SET_WINTB(g_bsp_world_interrupts_table);

    /* Set the TRCALL vector table. */
    __SET_TRCTB(g_bsp_trcall_table_s);

 #if defined(__CCRX__)
    R_BSP_SecureEnter_ASM(psw_data, pc_adrs, BSP_PZ_STACK_SEALING_VALUE);
 #else
    __asm volatile (
        "push.l %2                           \n"
        "mov.l  #00000100h, r5               \n" /* Set WID.BWID = 1(Secure) */
        "mvtc   r5, wid                      \n"
        "push.l %0                           \n" /* Push PSW to ISP_TR */
        "push.l %1                           \n" /* Push Secure Entry to ISP_TR */
        "trrte                               \n" /* Call *pc_adrs */

        "R_BSP_SecureEnter_end:              \n"
        "bra.b  R_BSP_SecureEnter_end        \n" /* Never reach here */
        : : "r" (psw_data), "r" (pc_adrs), "r" (BSP_PZ_STACK_SEALING_VALUE)
        );
 #endif
}

/******************************************************************************
 * [Secure TRCALL 0]
 *  r_bsp_trcall_enter_ns() is Root processing when transitioning
 *  from Secure to Non-Secure
 *****************************************************************************/
static void r_bsp_trcall_enter_ns (void)
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (

        /* Copy NS context from Secure registers. R1:PC R2:PSW */
 #if defined(__CCRX__) || defined(__ICCRX__)
        "mov.l #_g_bsp_nonsecure_context, r5            \n"
        "mov.l r1, 4[r5]                                \n"
        "mov.l r2, [r5]                                 \n"
 #else
        "mov r1, %0                                     \n"
        "mov r2, %1                                     \n"
 #endif

        /* Clear Secure Context  */
        "mov.l #0, r1                                   \n"
        "mov.l #0, r2                                   \n"
        "mov.l #0, r3                                   \n"
        "mov.l #0, r4                                   \n"
        "mov.l #0, r5                                   \n"
        "mov.l #0, r6                                   \n"
        "mov.l #0, r7                                   \n"
        "mov.l #0, r8                                   \n"
        "mov.l #0, r9                                   \n"
        "mov.l #0, r10                                  \n"
        "mov.l #0, r11                                  \n"
        "mov.l #0, r12                                  \n"
        "mov.l #0, r13                                  \n"
        "mov.l #0, r14                                  \n"
        "mov.l #0, r15                                  \n"
        "mvtc  #0, fpsw                                 \n"
        "mvtaclo r1, a0                                 \n"
        "mvtachi r1, a0                                 \n"
        "mvtacgu r1, a0                                 \n"
        "mvtaclo r1, a1                                 \n"
        "mvtachi r1, a1                                 \n"
        "mvtacgu r1, a1                                 \n"

        /* Remove PSW_S/PC_S on ISP_TR by trcall */
        "add   #8, r0                                   \n"

        /* Set NonSecure TRMVTC */
        "mov.l  #_g_bsp_trcall_table_ns, r1             \n"
        "trmvtc r1, trctb                               \n"

        /* Call NonSecure */
        "mov.l  #00000200h, r6                          \n" /* Set WID.BWID = 2 (NonSecure) */
        "mvtc   r6, wid                                 \n"

        "mov.l  #_g_bsp_nonsecure_context, r1           \n"
        "mov.l  [r1], r4                                \n" /* PSW */
        "mov.l  4[r1], r3                               \n" /* PC */
        "pushm  r3-r4                                   \n" /* R3:PC R4:PSW */

        "trrte                                          \n"

        /* Never reach here */
        "r_bsp_trcall_enter_ns_end:                     \n"
 #if defined(__GNUC__)
        "bra r_bsp_trcall_enter_ns_end                  \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_enter_ns_end                \n"
 #else
        "bra.b r_bsp_trcall_enter_ns_end                \n"
 #endif
 #if defined(__GNUC__)
        : : "m" (g_bsp_nonsecure_context.pc), "m" (g_bsp_nonsecure_context.psw)
 #endif
        );
}

/******************************************************************************
 * [NonSecure TRCALL 0]
 *  r_bsp_trcall_call_ssc() is Root processing for a secure service call.
 *  r1 - r4      : argument
 *  r5           : Function Code
 *  r1           : Return Value
 *  r14,r15      : scratch
 *  *(SP_TR + 0) : PC + 4 (Return Address)
 *  *(SP_TR + 4) : PSW
 *****************************************************************************/
static void r_bsp_trcall_call_ssc (void)
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (

        /* Save USP_NS */
        "mov.l #_g_bsp_nonsecure_context, r14           \n"
        "mvfc  usp, r15                                 \n"
        "mov.l r15, (2*4)[r14]                          \n" /* Save USP_NS to g_bsp_nonsecure_context.usp */

        /* Restore the USP-S. */
        "mov.l #_g_bsp_secure_context, r15              \n"
        "mov.l (2*4)[r15], r14                          \n" /* Restore USP_S from g_bsp_secure_context.usp */
        "mvtc  r14, usp                                 \n"

        /*
         * Error Check
         */

        /* Determine the caller's context. */
        "mov.l (1*4)[r0], r15                           \n" /* Acquisition of PSW_NS */
        "btst  #17, r15                                 \n" /* The Z flag is set if U is 0. */
 #if defined(__ICCRX__)
        "bz.w  r_bsp_trcall_call_ssc_1                  \n" /* If in a non-task context (using ISP), proceed to common processing. */
 #else
        "bz    r_bsp_trcall_call_ssc_1                  \n" /* If in a non-task context (using ISP), proceed to common processing. */
 #endif

        /* When called from a task context */

        /* Error if SSCC is not loaded (USP_S==0). */
        "cmp    #0, r14                                 \n"
 #if defined(__ICCRX__)
        "bz.w   r_bsp_trcall_call_ssc_error             \n"
 #else
        "bz     r_bsp_trcall_call_ssc_error             \n"
 #endif

        /* Error SSC already called (*USP_S != Stack sealing) */
        "mov.l [r14], r15                               \n"
 #if defined(__CCRX__)
        "cmp   #-17437275, r15                          \n" /* BSP_PZ_STACK_SEALING_VALUE */
 #else
        "cmp   %0, r15                                  \n"
 #endif
 #if defined(__ICCRX__)
        "bne.w   r_bsp_trcall_call_ssc_error             \n"
 #else
        "bne   r_bsp_trcall_call_ssc_error              \n"
 #endif

        /* An error occurs if interrupts are nested (i.e., ISP_TR != Stack sealing prior to TRCALL). */
        "mov.l (2*4)[r0], r15                           \n" /* Load ISP_TR top value prior to TRCALL */
 #if defined(__CCRX__)
        "cmp   #-17437275, r15                          \n" /* BSP_PZ_STACK_SEALING_VALUE */
 #else
        "cmp   %0, r15                                  \n"
 #endif
 #if defined(__ICCRX__)
        "bne.w   r_bsp_trcall_call_ssc_error            \n"
 #else
        "bne   r_bsp_trcall_call_ssc_error              \n"
 #endif

        /* Reload PC_NS and PSW_NS from ISP_TR to USP_S. */
        "popm   r14-r15                                 \n" /* r14:PC_NS, r15:PSW_NS */
        "setpsw u                                       \n"
        "pushm  r14-r15                                 \n"

        /*
         * overhead processing
         *  r15 : PSW_NS
         */
        "r_bsp_trcall_call_ssc_1:                       \n"

        /* Set Secure TRMVTC */
        "mov.l  #_g_bsp_trcall_table_s, r14             \n"
        "trmvtc r14, trctb                              \n"

        /* Preparing for a Secure call */
        "mov.l #00000100h, r14                          \n" /* Set WID.BWID = 1 (Secure) */
        "mvtc  r14, wid                                 \n"

        /* Disable Non-Secure IRQ by setting PSW_NS.IPL = 15. */
 #if defined(__CCRX__)
        "and   #0F0FFFFFFh, r15                         \n"
        "or    #0F000000h, r15                          \n"
 #else
        "and   #0xF0FFFFFF, r15                         \n"
        "or    #0x0F000000, r15                         \n"
 #endif

        /* Prepare Root stack to call _ssn_n_call by TRRTE */
        "mov.l #_r_bsp_ssc_adapter, r14                 \n" /* PC */
        "pushm r14-r15                                  \n" /* R14:PC R15:PSW */

        "trrte                                          \n"

        "r_bsp_trcall_call_ssc_error:                   \n"

        /* Restore USP_NS. */
        "mov.l  #_g_bsp_nonsecure_context, r15          \n"
        "mov.l  (2*4)[r15], r14                         \n" /* Restore USP_NS from g_bsp_nonsecure_context.usp */
        "mvtc   r14, usp                                \n"
 #if defined(__CCRX__)
        "mov.l #-2, r1                                  \n" /* BSP_SSC_ERR_PZ_INVALID_STATE */
 #else
        "mov %1, r1                                     \n" /* E_ID */
 #endif
        "trrte                                          \n"

        /* Never reach here */
        "r_bsp_trcall_call_ssc_end:                     \n"
 #if defined(__GNUC__)
        "bra r_bsp_trcall_call_ssc_end                  \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_call_ssc_end                \n"
 #else
        "bra.b r_bsp_trcall_call_ssc_end                \n"
 #endif
 #if defined(__GNUC__) || defined(__ICCRX__)
        : : "i" (BSP_PZ_STACK_SEALING_VALUE),
        "i" (BSP_SSC_ERR_PZ_INVALID_STATE)
 #endif
        );
}

/******************************************************************************
 * Trampolining function to call r_bsp_call_ssc_handler with nest support
 *****************************************************************************/
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
void r_bsp_ssc_adapter (void)
 #else
static void r_bsp_ssc_adapter (void)
 #endif
{
    __asm volatile (
        "push.l r5                            \n" /* Push SSC ID. */
        "mov.l  #_r_bsp_call_ssc_handler, r14 \n" /* Call r_bsp_call_ssc_handler. */
        "jsr    r14                           \n"
        "add    #4, r0                        \n" /* Pop SSC ID from stack. */
 #if defined(__CCRX__)
        "trcall #2                            \n" /* BSP_PZ_TRCALL_VECTOR_RETURN_SSC */
 #else
        "trcall %0                            \n" /* Call r_bsp_trcall_return_ssc. */
        : : "i" (BSP_PZ_TRCALL_VECTOR_RETURN_SSC)
 #endif
        );
}

/******************************************************************************
 * [Secure TRCALL 2]
 * r_bsp_trcall_return_ssc() is Root processing is a root process to return
 * from Secure to Non-Secure after executing a secure service call.
 *
 *  r1 : Return value
 *  r2 - r5 : scratch
 *  r14 - r15 : scratch
 *****************************************************************************/
static void r_bsp_trcall_return_ssc (void)
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (

        /* Set NonSecure TRMVTC */
        "mov.l  #_g_bsp_trcall_table_ns, r14      \n"
        "trmvtc r14, trctb                        \n"

        /* Determine the SSC caller's context.  */
        "mov.l 4[r0], r15                         \n" /* Acquisition of PSW_S (since it follows PNS_NS.U) */
        "add   #8, r0                             \n" /* Remove PSW_S/PC_S from ISP_TR */
        "and   #00020000h, r15                    \n" /* The Z flag is set if U is 0. */
 #if defined(__ICCRX__)
        "bz.w  ssc_return_trcall_1                \n"
 #else
        "bz    ssc_return_trcall_1                \n"
 #endif

        /*
         * In the case of task context
         */

        /* Reload PC_NS/PSW_NS from USP_S to ISP_TR. */
        "setpsw u                                 \n"
        "popm   r14-r15                           \n"
        "clrpsw u                                 \n"
        "pushm  r14-r15                           \n"

        /*
         * overhead processing
         */
        "ssc_return_trcall_1:                     \n"

        /* Saving the USP_S */
        "mvfc   usp, r15                          \n"
        "mov.l  #_g_bsp_secure_context, r14       \n"
        "mov.l  r15, (2*4)[r14]                   \n" /* Save USP_S to g_bsp_secure_context.usp */

        /* Restoration of USP_NS */
        "mov.l  #_g_bsp_nonsecure_context, r15    \n"
        "mov.l  (2*4)[r15], r14                   \n" /* Restore USP_NS from g_bsp_nonsecure_context.usp */
        "mvtc   r14, usp                          \n"

        /* Return to NonSecure  */
        "mov.l  #00000200h, r14                   \n" /* Set WID.BWID = 2 (NonSecure) */
        "mvtc   r14, wid                          \n"

        /*
         *  Clear Caller-saved Register
         *   r1 : return value
         */
        "mov.l   [r0], r2                         \n" /* r2 == return address */
 #if defined(__CCRX__)
        "mov.l   r2, r3                           \n"
        "mov.l   r2, r4                           \n"
        "mov.l   r2, r5                           \n"
        "mov.l   r2, r14                          \n"
        "mov.l   r2, r15                          \n"
 #else
        "mov     r2, r3                           \n"
        "mov     r2, r4                           \n"
        "mov     r2, r5                           \n"
        "mov     r2, r14                          \n"
        "mov     r2, r15                          \n"
 #endif
        "mvtaclo r2, a1                           \n" /* ACC1 */
        "mvtachi r2, a1                           \n"
        "mvtacgu r2, a1                           \n"
        "mvtaclo r2, a0                           \n" /* ACC0 */
        "mvtachi r2, a0                           \n"
        "mvtacgu r2, a0                           \n"
        "mvtc    #0, fpsw                         \n" /* FPSW */

        /* Clearing FPU registers is not supported. */

        /* PSW.OSZC will be overwrite with PSW_NS */
        "trrte                                    \n"

        /* Never reach here */
        "r_bsp_trcall_return_ssc_end:             \n"
 #if defined(__GNUC__)
        "bra r_bsp_trcall_return_ssc_end          \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_return_ssc_end        \n"
 #else
        "bra.b r_bsp_trcall_return_ssc_end        \n"
 #endif
        );
}

/******************************************************************************
 * [Secure TRCALL 3]
 * r_bsp_trcall_call_nssc() is Root processing is a root process to call
 * Non-Secure Call Back Function from Secure.
 *
 *  r1 - r4   : argment
 *  r5        : NS_SC address
 *  r14 - r15 : scratch
 *****************************************************************************/
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
void r_bsp_trcall_call_nssc (void)
 #else
static void r_bsp_trcall_call_nssc (void)
 #endif
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (

        /* Determining the caller's context */
        "mov.l (1*4)[r0], r15                         \n" /* Acquisition of PSW_S */
        "and   #00020000h, r15                        \n" /* The Z flag is set if PSW.U is 0. */
 #if defined(__ICCRX__)
        "bz.w  r_bsp_trcall_call_nssc_1               \n"
 #else
        "bz    r_bsp_trcall_call_nssc_1               \n"
 #endif

        /*
         * In the case of a task context (during SSC execution)
         *  Save to USP_S
         * Reload the contents of ISP_TR into USP_S. */
        "mvfc  usp, r15                               \n"
        "add   #-(2*4), r15                           \n" /* Reserve stack space on USP_S for pc and psw */
        "mov.l 0[r0], 0[r15]                          \n" /* pc */
        "mov.l 4[r0], 4[r15]                          \n" /* psw */

        "add   #(2*4), r0                             \n" /* Discard the content entered into ISP_TR. */

        "mvtc  r15, usp                               \n" /* Writeback of USP_S */

        "setpsw u                                     \n" /* Specify USP_S */

        /* overhead processing */
        "r_bsp_trcall_call_nssc_1:                    \n"

        /*
         * Saving the S-context
         *  When called from an SSC: USP_S
         *  When called from an interrupt handler: ISP_TR
         */
        "pushm r6-r13                                 \n"
        "pushc FPSW                                   \n"
        "mvfaclo #0, a0, r8                           \n"
        "mvfachi #0, a0, r7                           \n"
        "mvfacgu #0, a0, r6                           \n"
        "pushm r6-r8                                  \n" /* ACC0 Backup */
        "mvfaclo #0, a1, r8                           \n"
        "mvfachi #0, a1, r7                           \n"
        "mvfacgu #0, a1, r6                           \n"
        "pushm r6-r8                                  \n" /* ACC1 Backup */
 #ifdef USE_WPRI
        "pushc cr14                                   \n" /* Push WPRI*/
 #endif /* USE_WPRI */
 #if defined(__CCRX__)
        "mov.l #77777777h, r6                         \n" /* BSP_PZ_INTEGRITY_SIGNATURE_NS_SC */
 #else
        "mov.l %1, r6                                 \n" /* Place `integrity signature` at the beginning of the context frame. */
 #endif
        "push.l r6                                    \n"

        "mov.l #_g_bsp_secure_context, r14            \n" /* Saving the USP_S */
        "mvfc  usp, r15                               \n"
        "mov.l r15, (2*4)[r14]                        \n" /* Save USP_S to g_bsp_secure_context.usp */

        "clrpsw o                                     \n"
        "clrpsw s                                     \n"
        "clrpsw z                                     \n"
        "clrpsw c                                     \n"
        "mvfc  psw, r7                                \n" /* The PSW.U settings will be carried over. */

        "clrpsw u                                     \n" /* Enable ISP_TR */

        /* Set PSW for prepare to call interrupt handler */
 #if defined(__CCRX__)
        "mov.l   #_r_bsp_pz_error_handler, r6         \n" /* BSP_PZ_NS_SC_CALL_ADDRESS */
 #else
        "mov   %0, r6                                 \n" /* R6:BSP_PZ_NS_SC_CALL_ADDRESS */
 #endif
        "pushm r6-r7                                  \n" /* R6:PC_NS/R7:PSW_NS */

 #ifdef USE_WPRI
        "and   #1f000000h, r7                         \n"
        "mvtc r7, cr14                                \n" /* WPRI = PSW.IPL */
 #endif /* USE_WPRI */

        /* Set NonSecure TRMVTC */
        "mov.l  #_g_bsp_trcall_table_ns, r6           \n"
        "trmvtc r6, trctb                             \n"

        "mov.l #00000200h,r6                          \n" /* WID.BWID = Non-Secure */
        "mvtc  r6,wid                                 \n" /* set WID */

        /*
         * Restoration of USP_NS
         * PUSH to ISP_TR
         */
        "mov.l  #_g_bsp_nonsecure_context, r15        \n"
        "mov.l  (2*4)[r15], r14                       \n" /* Restore USP_NS from g_bsp_nonsecure_context.usp */
        "push.l r14                                   \n"

        /* Clear Secure Context  */
 #if defined(__CCRX__)
        "mov.l r5, r6                                 \n"
        "mov.l r5, r7                                 \n"
        "mov.l r5, r8                                 \n"
        "mov.l r5, r9                                 \n"
        "mov.l r5, r10                                \n"
        "mov.l r5, r11                                \n"
        "mov.l r5, r12                                \n"
        "mov.l r5, r13                                \n"
        "mov.l r5, r14                                \n"
        "mov.l r5, r15                                \n"
 #else
        "mov   r5, r6                                 \n"
        "mov   r5, r7                                 \n"
        "mov   r5, r8                                 \n"
        "mov   r5, r9                                 \n"
        "mov   r5, r10                                \n"
        "mov   r5, r11                                \n"
        "mov   r5, r12                                \n"
        "mov   r5, r13                                \n"
        "mov   r5, r14                                \n"
        "mov   r5, r15                                \n"
 #endif
        "mvtc  #0, fpsw                               \n"
        "mvtaclo r5, a0                               \n"
        "mvtachi r5, a0                               \n"
        "mvtacgu r5, a0                               \n"
        "mvtaclo r5, a1                               \n"
        "mvtachi r5, a1                               \n"
        "mvtacgu r5, a1                               \n"

        /* Clearing FPU registers is not supported. */

        /* Pop USP_NS from ISP_TR */
        "popc usp                                     \n"

        "trrte                                        \n"

        "r_bsp_trcall_call_nssc_error:                \n"
 #if defined(__GNUC__)
        "bra r_bsp_trcall_call_nssc_error             \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_call_nssc_error           \n"
 #else
        "bra.b r_bsp_trcall_call_nssc_error           \n"
 #endif

        /* Never reach here */
        "r_bsp_trcall_call_nssc_end:                  \n"
 #if defined(__GNUC__)
        "bra r_bsp_trcall_call_nssc_end               \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_call_nssc_end             \n"
 #else
        "bra.b r_bsp_trcall_call_nssc_end             \n"
 #endif
 #if defined(__GNUC__) || defined(__ICCRX__)
        : : "i" (BSP_PZ_NS_SC_CALL_ADDRESS), "i" (BSP_PZ_INTEGRITY_SIGNATURE_NS_SC)
 #endif
        );
}

/******************************************************************************
 * r_bsp_rint_handler() is executed when a Root world interrupt occurs
 * while executing in the Non-Secure or Secure world.
 *****************************************************************************/
static void r_bsp_rint_handler (void)
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (
        "r_bsp_rint_handler_1:                  \n"
 #if defined(__GNUC__)
        "bra r_bsp_rint_handler_1               \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_rint_handler_1             \n"
 #else
        "bra.b r_bsp_rint_handler_1             \n"
 #endif
        );
}

/******************************************************************************
 * r_bsp_sint_from_ns() is executed when a Secure world interrupt occurs
 * while executing in the Non-Secure world.
 *****************************************************************************/
static void r_bsp_sint_from_ns (void)
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (

        /* Save Work Register */
        "pushm  r4-r5                                  \n"

        /* Set Secure TRMVTC */
        "mov.l  #_g_bsp_trcall_table_s, r4             \n"
        "trmvtc r4, trctb                              \n"

        /* Saving USP_NS */
        "mov.l  #_g_bsp_nonsecure_context, r5          \n"
        "mvfc   usp, r4                                \n"
        "mov.l  r4, (2*4)[r5]                          \n" /* Save USP_NS to g_bsp_nonsecure_context.usp */

        /* Call r_bsp_call_sint_handler in Secure */
        "mov.l #00000100h, r4                          \n" /* Set WID.BWID = 1 (Secure) */
        "mvtc  r4, wid                                 \n"

        /* Set USP_S */
        "mov.l  #_g_bsp_secure_context, r5             \n"
        "mov.l  (2*4)[r5], r4                          \n" /* Restore USP_S from g_bsp_secure_context.usp */
        "mvtc   r4, usp                                \n"

        "mov.l #_r_bsp_call_sint_handler, r4           \n" /* PC_S */
        "mvfc  psw, r5                                 \n" /* PSW_S */
        "pushm r4-r5                                   \n" /* R4:PC_S R5:PSW_S */

        "trrte                                         \n"

        /* Never reach here */
        "r_bsp_sint_from_ns_end:                       \n"
 #if defined(__GNUC__)
        "bra r_bsp_sint_from_ns_end                    \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_sint_from_ns_end                  \n"
 #else
        "bra.b r_bsp_sint_from_ns_end                  \n"
 #endif
        );
}

/******************************************************************************
 * r_bsp_call_sint_handlerl() is call Secure Interrupt and return code
 *****************************************************************************/
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
void r_bsp_call_sint_handler (void)
 #else
static void r_bsp_call_sint_handler (void)
 #endif
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (

        /*
         *  Restore registers that need to be restored upon transition from Non-Secure state.
         *  Save Non-Secure-side registers during this process.
         */
        "push.l r1                                      \n"
        "mvfc   ivc, r1                                 \n"
        "and    #000000FFh, r1                          \n"
        "int    r1                                      \n"
        "pop    r1                                      \n"
 #if defined(__CCRX__)
        "trcall #1                                      \n" /* BSP_PZ_TRCALL_VECTOR_RETURN_SINT */
 #else
        "trcall %0                                      \n" /* Call r_bsp_trcall_return_sint. */
 #endif

        /* Never reach here */
        "r_bsp_call_sint_handlerl_end:                  \n"
 #if defined(__GNUC__)
        "bra r_bsp_call_sint_handlerl_end               \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_call_sint_handlerl_end             \n"
 #else
        "bra.b r_bsp_call_sint_handlerl_end             \n"
 #endif
 #if defined(__GNUC__) || defined(__ICCRX__)
        : : "i" (BSP_PZ_TRCALL_VECTOR_RETURN_SINT)
 #endif
        );
}

/******************************************************************************
 * [Secure TRCALL 1]
 *  r_bsp_trcall_return_sint() is Root process that returns to Non-Secure from Secure
 *  interrupt processing involving a world transition.
 *  r13 - r15 : scratch
 *****************************************************************************/
static void r_bsp_trcall_return_sint (void)
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (

        /* Set NonSecure TRMVTC */
        "mov.l  #_g_bsp_trcall_table_ns, r4            \n"
        "trmvtc r4, trctb                              \n"

        /* Saving the USP_S */
        "mov.l  #_g_bsp_secure_context, r4             \n"
        "mvfc   usp, r5                                \n"
        "mov.l  r5, (2*4)[r4]                          \n" /* Save USP_S to g_bsp_secure_context.usp */

        /* Restore USP_NS */
        "mov.l  #_g_bsp_nonsecure_context, r4          \n"
        "mov.l  (2*4)[r4], r5                          \n" /* Restore USP_NS from g_bsp_nonsecure_context.usp */
        "mvtc   r5, usp                                \n"

        "add #8, r0                                    \n" /* Remove PSW/PC on ISP_TR by trcall */

        /* Preparing for a Non-Secure call */
        "mov.l  #00000200h, r4                         \n" /* Set WID.BWID = 2 (NonSecure) */
        "mvtc   r4, wid                                \n"

        /* Restore Work Register */
        "popm   r4-r5                                  \n"

        "trrte                                         \n"

        /* Never reach here */
        "r_bsp_trcall_return_sint_end:                 \n"
 #if defined(__GNUC__)
        "bra r_bsp_trcall_return_sint_end              \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_return_sint_end            \n"
 #else
        "bra.b r_bsp_trcall_return_sint_end            \n"
 #endif
        );
}

/******************************************************************************
 * r_bsp_nsint_from_s() is executed when a Non-Secure world interrupt occurs
 * while executing in the Secure world.
 *****************************************************************************/
static void r_bsp_nsint_from_s (void)
{
    /* Non-Secure interrupt from Secure world has not been supported. */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);

    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (
        "pushm r14-r15                                \n" /* Save the work register */

        /* Determining the context of the interrupt source */
        "mov.l (3*4)[r0], r15                         \n" /* Acquisition of PSW_S */
        "and   #00020000h, r15                        \n" /* The Z flag is set if PSW.U is 0. */
 #if defined(__ICCRX__)
        "bz.w  r_bsp_nsint_from_s_1                   \n"
 #else
        "bz    r_bsp_nsint_from_s_1                   \n"
 #endif

        /*
         * In the case of a task context (during SSC execution)
         *  Save to USP_S
         * Reload the contents of ISP_TR into USP_S. */
        "mvfc  usp, r15                               \n"
        "add   #-(4*4), r15                           \n"
        "mov.l [r0], [r15]                            \n" /* r14 */
        "mov.l 4[r0], 4[r15]                          \n" /* r15 */
        "mov.l 8[r0], 8[r15]                          \n" /* pc */
        "mov.l 12[r0], 12[r15]                        \n" /* psw */

        "add   #16, r0                                \n" /* Discard the content entered into ISP_TR. */

        "mvtc  r15, usp                               \n" /* Writeback of USP_S */

        "setpsw u                                     \n" /* Specify USP_S */

        /* overhead processing */
        "r_bsp_nsint_from_s_1:                        \n"

        /*
         * Saving S-context
         *  In the case of an interrupt to the SSC              : USP_S
         *  In the case of an interrupt to the interrupt handler : ISP_TR
         */
        "pushm r1-r13                                 \n"
        "pushc FPSW                                   \n"
        "mvfaclo #0, a0, r5                           \n"
        "mvfachi #0, a0, r4                           \n"
        "mvfacgu #0, a0, r3                           \n"
        "pushm r3-r5                                  \n" /* ACC0 Backup */
        "mvfaclo #0, a1, r5                           \n"
        "mvfachi #0, a1, r4                           \n"
        "mvfacgu #0, a1, r3                           \n"
        "pushm r3-r5                                  \n" /* ACC1 Backup */
 #ifdef USE_WPRI
        "pushc cr14                                   \n" /* Push WPRI*/
 #endif /* USE_WPRI */

 #if defined(__CCRX__)
        "mov.l #55555555h, r1                         \n" /* BSP_PZ_INTEGRITY_SIGNATURE_NS_INT */
 #else
        "mov.l %1, r1                                 \n" /* Place `integrity signature` at the beginning of the context frame. */
 #endif
        "push.l r1                                    \n"

        "mov.l #_g_bsp_secure_context, r14            \n" /* Saving the USP_S */
        "mvfc  usp, r15                               \n"
        "mov.l r15, (2*4)[r14]                        \n" /* Save USP_S to g_bsp_secure_context.usp */

        "clrpsw o                                     \n"
        "clrpsw s                                     \n"
        "clrpsw z                                     \n"
        "clrpsw c                                     \n"
        "mvfc  psw, r2                                \n" /* The PSW.U settings will be carried over. */

        "clrpsw u                                     \n" /* Enable ISP_TR */

        /* Set PSW for prepare to call interrupt handler */
 #if defined(__CCRX__)
        "mov.l #_r_bsp_pz_error_handler, r1           \n" /* BSP_PZ_NS_INT_CALL_ADDRESS */
 #else
        "mov.l %0, r1                                 \n" /* R1:BSP_PZ_NS_INT_CALL_ADDRESS */
 #endif
        "pushm r1-r2                                  \n" /* R1:PC_NS/R2:PSW_NS */

 #ifdef USE_WPRI

        /* In case of dispatcher interrupts (IPL=1), do not set WPRI */
        "and  #1f000000h, r2                          \n"
        "cmp  #01000000h, r2                          \n"
  #if defined(__ICCRX__)
        "beq.w  r_bsp_nsint_from_s_wpri               \n"
  #else
        "beq  r_bsp_nsint_from_s_wpri                 \n"
  #endif
        "mvtc r2, cr14                                \n" /* WPRI = PSW.IPL */
        "r_bsp_nsint_from_s_wpri:                     \n"
 #endif /* USE_WPRI */

        /* Set NonSecure TRMVTC */
        "mov.l  #_g_bsp_trcall_table_ns, r4           \n"
        "trmvtc r4, trctb                             \n"

        "mov.l #00000200h,r6                          \n" /* WID.BWID = Non-Secure */
        "mvtc  r6,wid                                 \n" /* set WID */

        /*
         * Restoration of USP_NS.
         */
        "mov.l  #_g_bsp_nonsecure_context, r15        \n"
        "mov.l  (2*4)[r15], r14                       \n" /* Restore USP_NS from g_bsp_nonsecure_context.usp */
        "push.l r14                                   \n"

        /* Clear Secure Context  */
        "mov.l #0, r1                                 \n"
        "mov.l #0, r2                                 \n"
        "mov.l #0, r3                                 \n"
        "mov.l #0, r4                                 \n"
        "mov.l #0, r5                                 \n"
        "mov.l #0, r6                                 \n"
        "mov.l #0, r7                                 \n"
        "mov.l #0, r8                                 \n"
        "mov.l #0, r9                                 \n"
        "mov.l #0, r10                                \n"
        "mov.l #0, r11                                \n"
        "mov.l #0, r12                                \n"
        "mov.l #0, r13                                \n"
        "mov.l #0, r14                                \n"
        "mov.l #0, r15                                \n"
        "mvtc  #0, fpsw                               \n"
        "mvtaclo r1, a0                               \n"
        "mvtachi r1, a0                               \n"
        "mvtacgu r1, a0                               \n"
        "mvtaclo r1, a1                               \n"
        "mvtachi r1, a1                               \n"
        "mvtacgu r1, a1                               \n"

        /* Clearing FPU registers is not supported. */

        /* Pop USP_NS from ISP_TR */
        "popc usp                                     \n"

        "trrte                                        \n"

        "r_bsp_nsint_from_s_error:                    \n"
 #if defined(__GNUC__)
        "bra r_bsp_nsint_from_s_error                 \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_nsint_from_s_error               \n"
 #else
        "bra.b r_bsp_nsint_from_s_error               \n"
 #endif

        /* Never reach here */
        "r_bsp_nsint_from_s_end:                      \n"
 #if defined(__GNUC__)
        "bra r_bsp_nsint_from_s_end                   \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_nsint_from_s_end                 \n"
 #else
        "bra.b r_bsp_nsint_from_s_end                 \n"
 #endif
 #if defined(__GNUC__) || defined(__ICCRX__)
        : : "i" (BSP_PZ_NS_INT_CALL_ADDRESS), "i" (BSP_PZ_INTEGRITY_SIGNATURE_NS_INT)
 #endif
        );
}

/******************************************************************************
 * [NonSecure TRCALL 1]
 *  r_bsp_trcall_return_nsint() is Root process that returns to Secure from Non-Secure
 *  interrupt processing involving a world transition.
 *****************************************************************************/
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
void r_bsp_trcall_return_nsint (void)
 #else
static void r_bsp_trcall_return_nsint (void)
 #endif
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */

    __asm volatile (

        /* Saving USP_NS */
        "mov.l #_g_bsp_nonsecure_context, r14      \n"
        "mvfc  usp, r15                            \n"
        "mov.l r15, (2*4)[r14]                     \n" /* Save USP_NS to g_bsp_nonsecure_context.usp */

        /* Restore the USP-S */
        "mov.l #_g_bsp_secure_context, r4          \n"
        "mov.l (2*4)[r4], r1                       \n" /* Restore USP_S from g_bsp_secure_context.usp */
        "mvtc  r1, usp                             \n"

        /* Set Secure TRMVTC */
        "mov.l  #_g_bsp_trcall_table_s, r14        \n"
        "trmvtc r14, trctb                         \n"

        /* Determining the return context */
        "mov.l (1*4)[r0], r15                      \n" /* Acquisition of PSW_NS */
        "add   #8, r0                              \n" /* Remove PSW/PC on ISP_TR by trcall */
        "and   #00020000h, r15                     \n" /* The Z flag is set if U is 0. */
 #if defined(__ICCRX__)
        "bz.w  r_bsp_trcall_return_nsint_1         \n"
 #else
        "bz    r_bsp_trcall_return_nsint_1         \n"
 #endif

        /*
         * The return destination is the SSC called from TASK_NS.
         */

        /* Error check */

        /* ISP_TR[0] == IS : error */
        "mov.l [r0], r1                            \n"
 #if defined(__CCRX__)
        "cmp  #55555555h, r1                       \n" /* BSP_PZ_INTEGRITY_SIGNATURE_NS_INT */
 #else
        "cmp  %0, r1                               \n" /* INTEGRITY_SIGNATURE */
 #endif

 #if defined(__ICCRX__)
        "beq.w  r_bsp_trcall_return_nsint_task1    \n"
 #else
        "beq  r_bsp_trcall_return_nsint_task1      \n"
 #endif

        /* USP_S == 0 : error */
        "setpsw u                                  \n" /* Enable USP */
        "cmp  #0, r0                               \n"
 #if defined(__ICCRX__)
        "beq.w  r_bsp_trcall_return_nsint_task2    \n"
 #else
        "beq  r_bsp_trcall_return_nsint_task2      \n"
 #endif

        /* USP_S[0] != IS(==SS) : error */
        "pop  r1                                   \n"
 #if defined(__CCRX__)
        "cmp  #55555555h, r1                       \n" /* BSP_PZ_INTEGRITY_SIGNATURE_NS_INT */
 #else
        "cmp  %0, r1                               \n" /* INTEGRITY_SIGNATURE */
 #endif

 #if defined(__ICCRX__)
        "bne.w  r_bsp_trcall_return_nsint_task3    \n"
 #else
        "bne  r_bsp_trcall_return_nsint_task3      \n"
 #endif

 #if defined(__GNUC__)
        "bra r_bsp_trcall_return_nsint_2           \n" /* go to overhead processing */
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_return_nsint_2         \n" /* go to overhead processing */
 #else
        "bra.b r_bsp_trcall_return_nsint_2         \n" /* go to overhead processing */
 #endif

        /*
         * The return destination is an SSC called from INT_NS, or INT_S
         */
        "r_bsp_trcall_return_nsint_1:              \n"

        /* Error check */
        /* ISP_TR[0] != IS(==SS) : error */
        "pop  r1                                   \n" /* r1:integrity signature */
 #if defined(__CCRX__)
        "cmp  #55555555h, r1                       \n" /* BSP_PZ_INTEGRITY_SIGNATURE_NS_INT */
 #else
        "cmp  %0, r1                               \n"
 #endif

 #if defined(__ICCRX__)
        "bne.w  r_bsp_trcall_return_nsint_int      \n"
 #else
        "bne  r_bsp_trcall_return_nsint_int        \n"
 #endif

        /*
         *  overhead processing
         */
        "r_bsp_trcall_return_nsint_2:              \n"

        "mov.l  #00000100h, r2                     \n" /* WID.BWID = Secure */
        "mvtc   r2, wid                            \n" /* Set WID */

        /*
         * Restore Secure Context
         */
 #ifdef USE_WPRI
        "popc cr14                                 \n" /* Pop WPRI*/
 #endif /* USE_WPRI */
        "popm r3-r5                                \n" /* Restore ACC1 */
        "mvtaclo r5, a1                            \n"
        "mvtachi r4, a1                            \n"
        "mvtacgu r3, a1                            \n"
        "popm r3-r5                                \n" /* Restore ACC0 */
        "mvtaclo r5, a0                            \n"
        "mvtachi r4, a0                            \n"
        "mvtacgu r3, a0                            \n"
        "popc FPSW                                 \n"
        "popm r1-r15                               \n"

        /* FPU register restoration is not supported. */

        "trrte                                     \n"

        /* Never reach here */
        "r_bsp_trcall_return_nsint_end:            \n"
 #if defined(__GNUC__)
        "bra r_bsp_trcall_return_nsint_end         \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_return_nsint_end       \n"
 #else
        "bra.b r_bsp_trcall_return_nsint_end       \n"
 #endif

        "r_bsp_trcall_return_nsint_task1:          \n"

        /* ISP_TR[0] == IS : error (interrupt context during transition) */
 #if defined(__GNUC__)
        "bra _r_bsp_pz_error_handler               \n"
 #else
        "bra.w _r_bsp_pz_error_handler             \n"
 #endif

        "r_bsp_trcall_return_nsint_task2:          \n"

        /* USP_S == 0 : error (Secure context not loaded) */
 #if defined(__GNUC__)
        "bra _r_bsp_pz_error_handler               \n"
 #else
        "bra.w _r_bsp_pz_error_handler             \n"
 #endif

        "r_bsp_trcall_return_nsint_task3:          \n"

        /* USP_S[0] != IS : error (Invalid signature) */
 #if defined(__GNUC__)
        "bra _r_bsp_pz_error_handler               \n"
 #else
        "bra.w _r_bsp_pz_error_handler             \n"
 #endif

        "r_bsp_trcall_return_nsint_int:            \n"

        /* ISP_TR[0] != IS : error (Invalid signature in interrupt context) */
 #if defined(__GNUC__)
        "bra _r_bsp_pz_error_handler               \n"
 #elif defined(__ICCRX__)
        "bra.w _r_bsp_pz_error_handler             \n"
 #else
        "bra.w _r_bsp_pz_error_handler             \n"
 #endif
 #if defined(__GNUC__) || defined(__ICCRX__)
        : : "i" (BSP_PZ_INTEGRITY_SIGNATURE_NS_INT)
 #endif
        );
}

/******************************************************************************
 * [NonSecure TRCALL 2]
 *  r_bsp_trcall_return_nssc() is Root process that returns to Secure from Non-Secure
 *  Call Back Function.
 *  r1 : return value
 *****************************************************************************/
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
void r_bsp_trcall_return_nssc (void)
 #else
static void r_bsp_trcall_return_nssc (void)
 #endif
{
    /* This is a naked/stackless function. Do not pass arguments to the inline assembly when the GCC compiler is
     * used. */
    __asm volatile (

        /* Saving USP_NS */
        "mov.l #_g_bsp_nonsecure_context, r14      \n"
        "mvfc  usp, r15                            \n"
        "mov.l r15, (2*4)[r14]                     \n" /* Save USP_NS to g_bsp_nonsecure_context.usp */

        /* Restore the USP-S */
        "mov.l #_g_bsp_secure_context, r4          \n"
        "mov.l (2*4)[r4], r2                       \n" /* Restore USP_S from g_bsp_secure_context.usp */
        "mvtc  r2, usp                             \n"

        /* Set Secure TRMVTC */
        "mov.l  #_g_bsp_trcall_table_s, r14        \n"
        "trmvtc r14, trctb                         \n"

        /* Determining the return context */
        "mov.l (1*4)[r0], r15                      \n" /* Acquisition of PSW_NS */
        "add   #8, r0                              \n" /* Remove PSW/PC on ISP_TR by trcall */
        "and   #00020000h, r15                     \n" /* The Z flag is set if U is 0. */
 #if defined(__ICCRX__)
        "bz.w  r_bsp_trcall_return_nssc_1          \n"
 #else
        "bz    r_bsp_trcall_return_nssc_1          \n"
 #endif

        /*
         *  The NS_SC from which the return destination was called (originating from TASK_NS)
         */

        /* Error check */

        /* ISP_TR[0] == IS : error */
        "mov.l [r0], r2                            \n"
 #if defined(__CCRX__)
        "cmp  #77777777h, r2                       \n" /* BSP_PZ_INTEGRITY_SIGNATURE_NS_SC */
 #else
        "cmp  %0, r2                               \n" /* INTEGRITY_SIGNATURE */
 #endif

 #if defined(__ICCRX__)
        "beq.w  r_bsp_trcall_return_nssc_task1     \n"
 #else
        "beq  r_bsp_trcall_return_nssc_task1       \n"
 #endif

        /* USP_S == 0 : error */
        "setpsw u                                  \n" /* Enable USP */
        "cmp  #0, r0                               \n"
 #if defined(__ICCRX__)
        "beq.w  r_bsp_trcall_return_nssc_task2     \n"
 #else
        "beq  r_bsp_trcall_return_nssc_task2       \n"
 #endif

        /* USP_S[0] != IS(==SS) : error */
        "pop  r2                                   \n"
 #if defined(__CCRX__)
        "cmp  #77777777h, r2                       \n" /* BSP_PZ_INTEGRITY_SIGNATURE_NS_SC */
 #else
        "cmp  %0, r2                               \n" /* INTEGRITY_SIGNATURE */
 #endif

 #if defined(__ICCRX__)
        "bne.w  r_bsp_trcall_return_nssc_task3     \n"
 #else
        "bne  r_bsp_trcall_return_nssc_task3       \n"
 #endif

 #if defined(__GNUC__)
        "bra r_bsp_trcall_return_nssc_2            \n" /* go to overhead processing */
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_return_nssc_2          \n" /* go to overhead processing */
 #else
        "bra.b r_bsp_trcall_return_nssc_2          \n" /* go to overhead processing */
 #endif

        /*
         * The return destination is an SSC called from INT_NS, or INT_S
         */
        "r_bsp_trcall_return_nssc_1:               \n"

        /* Error check */
        /* ISP_TR[0] != IS(==SS) : error */
        "pop  r2                                   \n" /* r1:integrity signature */
 #if defined(__CCRX__)
        "cmp  #77777777h, r2                       \n" /* BSP_PZ_INTEGRITY_SIGNATURE_NS_SC */
 #else
        "cmp  %0, r2                               \n"
 #endif

 #if defined(__ICCRX__)
        "bne.w  r_bsp_trcall_return_nssc_int       \n"
 #else
        "bne  r_bsp_trcall_return_nssc_int         \n"
 #endif

        /*
         *  overhead processing
         */
        "r_bsp_trcall_return_nssc_2:               \n"

        "mov.l  #00000100h, r2                     \n" /* WID.BWID = Secure */
        "mvtc   r2, wid                            \n" /* Set WID */

        /*
         * Restore Secure Context
         */
 #ifdef USE_WPRI
        "popc cr14                                 \n" /* Pop WPRI*/
 #endif /* USE_WPRI */
        "popm r3-r5                                \n" /* Restore ACC1 */
        "mvtaclo r5, a1                            \n"
        "mvtachi r4, a1                            \n"
        "mvtacgu r3, a1                            \n"
        "popm r3-r5                                \n" /* Restore ACC0 */
        "mvtaclo r5, a0                            \n"
        "mvtachi r4, a0                            \n"
        "mvtacgu r3, a0                            \n"
        "popc FPSW                                 \n"
        "popm r6-r13                               \n"

        "trrte                                     \n"

        /* Never reach here */
        "r_bsp_trcall_return_nssc_end:             \n"
 #if defined(__GNUC__)
        "bra r_bsp_trcall_return_nssc_end          \n"
 #elif defined(__ICCRX__)
        "bra.w r_bsp_trcall_return_nssc_end        \n"
 #else
        "bra.b r_bsp_trcall_return_nssc_end        \n"
 #endif

        "r_bsp_trcall_return_nssc_task1:           \n"

        /* ISP_TR[0] == IS : error (interrupt context during transition) */
 #if defined(__GNUC__)
        "bra _r_bsp_pz_error_handler               \n"
 #else
        "bra.w _r_bsp_pz_error_handler             \n"
 #endif

        "r_bsp_trcall_return_nssc_task2:           \n"

        /* USP_S == 0 : error (Secure context not loaded) */
 #if defined(__GNUC__)
        "bra _r_bsp_pz_error_handler               \n"
 #else
        "bra.w _r_bsp_pz_error_handler             \n"
 #endif

        "r_bsp_trcall_return_nssc_task3:           \n"

        /* USP_S[0] != IS : error (Invalid signature) */
 #if defined(__GNUC__)
        "bra _r_bsp_pz_error_handler               \n"
 #else
        "bra.w _r_bsp_pz_error_handler             \n"
 #endif

        "r_bsp_trcall_return_nssc_int:             \n"

        /* ISP_TR[0] != IS : error (Invalid signature in interrupt context) */
 #if defined(__GNUC__)
        "bra _r_bsp_pz_error_handler               \n"
 #else
        "bra.w _r_bsp_pz_error_handler             \n"
 #endif
 #if defined(__GNUC__) || defined(__ICCRX__)
        : : "i" (BSP_PZ_INTEGRITY_SIGNATURE_NS_SC)
 #endif
        );
}

/******************************************************************************
 * Execute SSC handler.
 *****************************************************************************/
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
bsp_ssc_err_t r_bsp_call_ssc_handler (intptr_t par1, intptr_t par2, intptr_t par3, intptr_t par4, uint32_t ssc_id)
 #else
static bsp_ssc_err_t r_bsp_call_ssc_handler (intptr_t par1, intptr_t par2, intptr_t par3, intptr_t par4,
                                             uint32_t ssc_id)
 #endif
{
    bsp_ssc_handler_t p_ssc_fp;

    if (BSP_PZ_CFG_SSC_NUM <= ssc_id)
    {
        return BSP_SSC_ERR_PZ_INVALID_ID;
    }

    p_ssc_fp = g_bsp_pz_ssc_table[ssc_id];

    if (p_ssc_fp == NULL)
    {
        return BSP_SSC_ERR_PZ_UNREGISTERED_HANDLER;
    }

    return (*p_ssc_fp)(par1, par2, par3, par4);
}

/******************************************************************************
 * Handles unrecoverable errors using the BSP error handler.
 *****************************************************************************/
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "Symbol is undefined for call the r_bsp_pz_error_handler.". */
void r_bsp_pz_error_handler (void)
 #else
static void r_bsp_pz_error_handler (void)
 #endif
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

/******************************************************************************
 * Handles unrecoverable errors using the BSP error handler.
 *****************************************************************************/
static void r_bsp_pz_default_handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

#endif

#if BSP_PZ_NONSECURE_BUILD

/******************************************************************************
 * Execute SSC handler.
 *****************************************************************************/
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
void r_bsp_call_nsint_handler (void)
 #else
static void r_bsp_call_nsint_handler (void)
 #endif
{
    __asm volatile (

        /*
         *  Restore registers that need to be restored upon transition from Secure state
         */
        "mvfc ivc, r1       \n"
        "and #000000ffh, r1 \n"
        "int r1             \n"
        "trcall #1          \n"
        );
}

/******************************************************************************
 * Execute SSC handler.
 *****************************************************************************/
 #if defined(__CCRX__)

/* Deleted static declaration to fix build error "* was declared but never referenced.". */
void r_bsp_call_nssc_handler (void)
 #else
static void r_bsp_call_nssc_handler (void)
 #endif
{
    __asm volatile (

        /*
         *  Restore registers that need to be restored upon transition from Secure state
         */
        "jsr r5    \n"
        "trcall #2 \n"
        );
}

#endif
