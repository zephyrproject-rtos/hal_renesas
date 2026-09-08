/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

#ifndef BSP_COMPILER_SUPPORT_H
 #define BSP_COMPILER_SUPPORT_H

 #ifdef __cplusplus
extern "C" {
 #endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #if defined(__CCRX__)                 /* CCRX compiler */
  #define BSP_SECTION_HEAP                  ".bss._g_heap"
  #define BSP_SECTION_STACK                 ".bss._g_main_stack"
  #define BSP_UNINIT_SECTION_PREFIX
  #define BSP_DONT_REMOVE
  #define BSP_ATTRIBUTE_STACKLESS           __attribute__((naked))
  #define BSP_FORCE_INLINE                  __attribute__((always_inline))
 #elif defined(__GNUC__)               /* GCC compiler */
  #define BSP_SECTION_HEAP                  ".bss._g_heap"
  #define BSP_SECTION_STACK                 ".bss._g_main_stack"
  #define BSP_UNINIT_SECTION_PREFIX
  #define BSP_DONT_REMOVE                   __attribute__((used))
  #define BSP_ATTRIBUTE_STACKLESS           __attribute__((naked))
  #define BSP_FORCE_INLINE                  __attribute__((always_inline))
 #elif defined(__ICCRX__)              /* IAR compiler */
  #define BSP_SECTION_HEAP                  ".bss"
  #define BSP_SECTION_STACK                 ".bss"
  #define BSP_UNINIT_SECTION_PREFIX
  #define BSP_DONT_REMOVE                   __root
  #define BSP_ATTRIBUTE_STACKLESS
  #define BSP_FORCE_INLINE                  _Pragma("inline=forced")
 #endif

 #define BSP_SECTION_NOINIT                 BSP_UNINIT_SECTION_PREFIX ".noinit"
 #define BSP_SECTION_FIXED_VECTORS          ".fixed_vectors"
 #define BSP_SECTION_APPLICATION_VECTORS    ".application_vectors"
 #define BSP_SECTION_RESET_VECTOR           ".reset_vector"
 #define BSP_SECTION_ENTRY_POINT_APP        ".entry_point_app"

/* Compiler neutral macros. */
 #if defined(__CCRX__)                 /* CCRX compiler */
  #define BSP_PLACE_IN_SECTION(x)    __attribute__((section(x)))
  #define __PACKED_STRUCT                   struct
 #elif defined(__GNUC__)               /* GCC compiler */
  #define BSP_PLACE_IN_SECTION(x)    __attribute__((section(x))) __attribute__((__used__))
  #define __PACKED_STRUCT                   struct __attribute__((__packed__))
 #elif defined(__ICCRX__)              /* IAR compiler */
  #define BSP_PLACE_IN_SECTION(x)    __attribute__((section(x))) __attribute__((__used__))
  #define __PACKED_STRUCT                   __packed struct
 #endif

 #define BSP_ALIGN_VARIABLE(x)       __attribute__((aligned(x)))

 #define BSP_WEAK_REFERENCE                 __attribute__((weak))

/** Stacks (and heap) must be sized and aligned to an integer multiple of this number. */
 #define BSP_STACK_ALIGNMENT                (8)

 #if defined(__CCRX__)                 /* CCRX compiler */
  #define __STATIC_INLINE                   static inline
 #elif defined(__GNUC__)               /* GCC compiler */
  #define __STATIC_INLINE                   static __inline
 #elif defined(__ICCRX__)              /* IAR compiler */
  #define __STATIC_INLINE                   static __inline
 #endif

/* Inline assembler macros. */
 #if defined(__CCRX__)                 /* CCRX compiler */
  #define __BKPT(x)        __brk()
  #define __GET_ISP(x)     x = __get_isp()
  #define __SET_ISP(x)     __set_isp((void *) x)
  #define __SET_EXTB(x)    __set_extb(x)
  #define __SET_INTB(x)    __set_intb(x)
  #define __SETPSW_I()     __setpsw_i()
  #define __CLRPSW_I()     __clrpsw_i()
  #define __GET_PSW(x)     x = __get_psw()
  #define __SET_PSW(x)     __set_psw(x)
  #define __NOP()          __nop()
  #define __WAIT()         __wait()
  #define __WFI()          __wait()
  #define __DSB()
 #elif defined(__GNUC__)               /* GCC scompiler */
  #define __BKPT(x)        __asm volatile ("brk" : : :)
  #define __GET_ISP(x)     __asm volatile ("mvfc isp, %0" : "=r" (x))
  #define __SET_ISP(x)     __asm volatile ("mvtc %0, isp" : : "r" (x) :)
  #define __SET_EXTB(x)    __asm volatile ("mvtc %0, extb" : : "r" ((uint32_t) x) :)
  #define __SET_INTB(x)    __asm volatile ("mvtc %0, intb" : : "r" ((uint32_t) x) :)
  #define __SETPSW_I()     __asm volatile ("setpsw i" : : :)
  #define __CLRPSW_I()     __asm volatile ("clrpsw i" : : :)
  #define __GET_PSW(x)     __asm volatile ("mvfc psw,%0" : "=r" (x))
  #define __SET_PSW(x)     __asm volatile ("mvtc %0,psw" ::"r" (x))
  #define __NOP()          __asm volatile ("nop")
  #define __WAIT()         __asm volatile ("wait")
  #define __WFI()          __asm volatile ("wait")
  #define __DSB()          do { \
        __sync_synchronize();   \
        __asm__ __volatile__ ("nop\n\tnop\n\tnop" ::: "memory");                      \
} while (0)
 #elif defined(__ICCRX__)              /* IAR compiler */
  #define __BKPT(x)        __asm volatile ("brk" : : :)
  #define __GET_ISP(x)     __asm volatile ("mvfc isp, %0" : "=r" (x))
  #define __SET_ISP(x)     __asm volatile ("mvtc %0, isp" : : "r" (x) :)
  #define __SET_EXTB(x)    __asm volatile ("mvtc %0, extb" : : "r" ((uint32_t) x) :)
  #define __SET_INTB(x)    __asm volatile ("mvtc %0, intb" : : "r" ((uint32_t) x) :)
  #define __SETPSW_I()     __asm volatile ("setpsw i" : : :)
  #define __CLRPSW_I()     __asm volatile ("clrpsw i" : : :)
  #define __GET_PSW(x)     __asm volatile ("mvfc psw,%0" : "=r" (x))
  #define __SET_PSW(x)     __asm volatile ("mvtc %0,psw" ::"r" (x))
  #define __NOP()          __asm volatile ("nop")
  #define __WAIT()         __asm volatile ("wait")
  #define __WFI()          __asm volatile ("wait")
  #define __DSB()
 #endif

 #if defined(__CCRX__)                 /* CCRX compiler */
  #define BSP_ATTRIBUTE_ISR
  #define BSP_ATTRIBUTE_KEEP
 #elif defined(__GNUC__)               /* GCC compiler */
  #define BSP_ATTRIBUTE_ISR     __attribute__((naked, noinline))
  #define BSP_ATTRIBUTE_KEEP    static
 #elif defined(__ICCRX__)              /* IAR compiler */
  #define BSP_ATTRIBUTE_ISR     __attribute__((noinline))
  #define BSP_ATTRIBUTE_KEEP    static
 #endif

/**
 * Renesas v3 ISA does not support hardware-specific barrier instruction.
 * Using GCC "__sync_synchronize" built-in function to issues a full memory barrier.
 */
 #if defined(__CCRX__)                 /* CCRX compiler */
  #define __DMB(x)
 #elif defined(__GNUC__)               /* GCC compiler */
  #define __DMB(x)    __sync_synchronize()
 #elif defined(__ICCRX__)              /* IAR compiler */
  #define __DMB(x)
 #endif

/* Endian support. */
 #if defined(__CCRX__)                 /* CCRX compiler */

 #elif defined(__GNUC__)               /* GCC compiler */
  #if defined(__RX_LITTLE_ENDIAN__)
   #define __LIT    (1)
  #elif defined(__RX_BIG_ENDIAN__)
   #define __BIG    (1)
  #endif
 #elif defined(__ICCRX__)              /* IAR compiler */

 #endif

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** @} (end of addtogroup BSP_MCU) */

 #ifdef __cplusplus
}
 #endif

#endif
