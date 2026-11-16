/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_iar.h
 * @brief    RH850 compiler IAR header file
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#ifndef __RH850_IAR_H
#define __RH850_IAR_H

/* Fallback for __has_builtin */
#ifndef __has_builtin
 #define __has_builtin(x)    (0)
#endif

/* RH850 compiler specific defines */
#ifdef SPIDLIST
 #undef SPIDLIST
#endif
#ifdef   __ASM
 #undef __ASM
#endif
#ifndef   __ASM
 #define __ASM                   __asm
#endif
#ifndef   __INLINE
 #define __INLINE                inline
#endif
#ifndef   __STATIC_INLINE
 #define __STATIC_INLINE         static inline
#endif
#ifndef   __STATIC_FORCEINLINE
 #define __STATIC_FORCEINLINE    __attribute__((always_inline)) static inline
#endif
#ifndef   __NO_RETURN
 #define __NO_RETURN             __attribute__((noreturn))
#endif
#ifndef   RH850_DEPRECATED
 #define RH850_DEPRECATED        __attribute__((deprecated))
#endif
#ifndef   RH850_UNSUPPORTED
 #define RH850_UNSUPPORTED       0
#endif
#ifndef   __USED
 #define __USED                  __attribute__((used))
#endif
#ifndef   __WEAK
 #define __WEAK                  __attribute__((weak))
#endif
#ifndef   __PACKED
 #define __PACKED                __attribute__((packed, aligned(1)))
#endif
#ifndef   __PACKED_STRUCT
 #define __PACKED_STRUCT         struct __attribute__((packed, aligned(1)))
#endif
#ifndef   __PACKED_UNION
 #define __PACKED_UNION          union __attribute__((packed, aligned(1)))
#endif
#ifndef   __UNALIGNED_UINT16_WRITE
__PACKED_STRUCT T_UINT16_WRITE {
    uint16_t v;
};
 #define __UNALIGNED_UINT16_WRITE(addr, val)    (void) ((((struct T_UINT16_WRITE *) (void *) (addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT16_READ
__PACKED_STRUCT T_UINT16_READ {
    uint16_t v;
};
 #define __UNALIGNED_UINT16_READ(addr)    (((const struct T_UINT16_READ *) (const void *) (addr))->v)
#endif
#ifndef   __UNALIGNED_UINT32_WRITE
__PACKED_STRUCT T_UINT32_WRITE {
    uint32_t v;
};
 #define __UNALIGNED_UINT32_WRITE(addr, val)    (void) ((((struct T_UINT32_WRITE *) (void *) (addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT32_READ
__PACKED_STRUCT T_UINT32_READ {
    uint32_t v;
};
 #define __UNALIGNED_UINT32_READ(addr)    (((const struct T_UINT32_READ *) (const void *) (addr))->v)
#endif
#ifndef   __ALIGNED
 #define __ALIGNED(x)                     __attribute__((aligned(x)))
#endif
#ifndef   __RESTRICT
 #define __RESTRICT
#endif
#ifndef   __COMPILER_BARRIER
 #define __COMPILER_BARRIER()    __ASM volatile ("" ::: "memory")
#endif
#ifndef __NO_INIT
 #define __NO_INIT    __attribute__((section(".noinit")))
#endif
#ifndef __ALIAS
 #define __ALIAS(x)                              __attribute__((alias(x)))
#endif

/* Convert token into a string and pass it to _Pragma */
#ifndef   __PRAGMA_HELPER
 #define __PRAGMA_HELPER(x)                      _Pragma(#x)
#endif

/* Create the pragma inline statement with the function name as argument */
#ifndef __PRAGMA_PLACE_IN_SECTION
 #define __PRAGMA_PLACE_IN_SECTION(sec, name)    __PRAGMA_HELPER(sec = @ name)
#endif
#ifndef   __FORCEINLINE
 #define __FORCEINLINE(Func_Name)                __PRAGMA_HELPER(inline Func_Name)
#endif
#ifndef   __FORCEINLINE_ASM
 #define __FORCEINLINE_ASM(Func_Name)            __PRAGMA_HELPER(inline_asm Func_Name)
#endif

/* ###########################################  Core Instruction Access  ############################################ */

/** @defgroup RH850_Core_InstructionInterface RH850-Core Instruction Interface
 * @brief Access to dedicated instructions
 * @{
 */

/** @ingroup  RH850_Core_InstructionInterface
 *  @defgroup IAR_RH850_Core_InstructionInterface IAR RH850-Core Instruction Interface
 *  @brief RH850-Core Instruction Interface
 * @{
 */

/********************************************* ARM INTRINSIC **********************************************************/

/**
 * @brief   Instruction Synchronization Barrier
 * @details Instruction Synchronization Barrier flushes the pipeline in the processor,
 *         so that all instructions following the ISB are fetched from cache or memory,
 *         after the instruction has been completed.
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
#define __ISB()           __SYNCI()

/**
 * @brief   Data Synchronization Barrier
 * @details Acts as a special kind of Data Memory Barrier.
 *         It completes when all explicit memory accesses before this instruction complete.
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
#define __DSB()           __SYNCP()

/**
 * @brief   Data Memory Barrier
 * @details Ensures the apparent order of the explicit memory operations before
 *         and after the instruction, without ensuring their completion.
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
#define __DMB()           __SYNCM()

/**
 * @brief   Reverse byte order (32 bit)
 * @details Reverses the byte order in unsigned integer value. For example, 0x12345678 becomes 0x78563412.
 * @param [in]    value  Value to reverse
 * @return               Reversed value
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */

#define __REV(value)      __BSW(value)

/**
 * @brief   Reverse byte order (16 bit)
 * @details Reverses the byte order within each halfword of a word. For example, 0x12345678 becomes 0x34127856.
 * @param [in]    value  Value to reverse
 * @return               Reversed value
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
#define __REV16(value)    __BSH(value)

/**
 * @brief   Reverse byte order (16 bit)
 * @details Reverses the byte order in a 16-bit value and returns the signed 16-bit result. For example, 0x0080 becomes 0x8000.
 * @param [in]    value  Value to reverse
 * @return               Reversed value
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */

#define __REVSH(value)    ((int16_t) __BSH(value))

/**
 * @brief   Rotate Right in unsigned value (32 bit)
 * @details Rotate Right (immediate) provides the value of the contents of a register rotated by a variable number of bits.
 * @param [in]    op1  Value to rotate
 * @param [in]    op2  Number of Bits to rotate
 * @return               Rotated value
 */
__STATIC_FORCEINLINE uint32_t __ROR (uint32_t op1, uint32_t op2)
{
    op2 %= 32U;
    if (op2 == 0U)
    {
        return op1;
    }

    return (op1 >> op2) | (op1 << (32U - op2));
}

/**
 * @brief   Reverse bit order of value
 * @details Reverses the bit order of the given value.
 * @param [in]    value  Value to reverse
 * @return               Reversed value
 */
__STATIC_FORCEINLINE uint32_t __RBIT (uint32_t value)
{
    uint32_t result;

    uint32_t s = (4U /*sizeof(v)*/ * 8U) - 1U; /* extra shift needed at end */

    result = value;                            /* r will be reversed bits of v; first get LSB of v */
    for (value >>= 1U; value != 0U; value >>= 1U)
    {
        result <<= 1U;
        result  |= value & 1U;
        s--;
    }

    result <<= s;                      /* shift when v's highest bits are zero */

    return result;
}

/**
 * @brief   Count leading zeros
 * @details Counts the number of leading zeros of a data value.
 * @param [in]  value  Value to count the leading zeros
 * @return             number of leading zeros in value
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint32_t __CLZ (uint32_t value)
{
    const int32_t pos = __SCH1L((long) value);

    return (0 != pos) ? (uint32_t) (pos - 1) : 32U;
}

/**
 * @brief   Signed Saturate
 * @details Saturates a signed value.
 * @param [in]  val  Value to be saturated
 * @param [in]  sat  Bit position to saturate to (1..32)
 * @return             Saturated value
 */
__STATIC_FORCEINLINE int32_t __SSAT (int32_t val, uint32_t sat)
{
    if ((sat >= 1U) && (sat <= 32U))
    {
        const int32_t max = (int32_t) ((1U << (sat - 1U)) - 1U);
        const int32_t min = -1 - max;
        if (val > max)
        {
            return max;
        }
        else if (val < min)
        {
            return min;
        }
    }

    return val;
}

/**
 * @brief   Unsigned Saturate
 * @details Saturates an unsigned value.
 * @param [in]  val  Value to be saturated
 * @param [in]  sat  Bit position to saturate to (0..31)
 * @return             Saturated value
 */
__STATIC_FORCEINLINE uint32_t __USAT (int32_t val, uint32_t sat)
{
    if (sat <= 31U)
    {
        const uint32_t max = ((1U << sat) - 1U);
        if (val > (int32_t) max)
        {
            return max;
        }
        else if (val < 0)
        {
            return 0U;
        }
    }

    return (uint32_t) val;
}

/**
 * @brief   Remove the exclusive lock
 * @details Removes the exclusive lock which is created by LDREX.
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE void __CLREX (void)
{
    __ASM volatile ("cll" ::: "memory"); /* Clear Load Link */
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   LDR Exclusive (8 bit)
 * @details Executes a exclusive LDR instruction for 8 bit value.
 * @param [in]    addr  Pointer to data
 * @return             value of type uint8_t at (*addr)
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 *          This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint8_t __LDREXB (volatile uint8_t * addr)
{
    uint32_t result;

    /* Load to start atomic byte data manipulation */
    __ASM volatile ("ldl.bu [%1], %0" : "=&r" (result) : "r" (addr) : "memory");

    /* Add explicit type cast here */
    return (uint8_t) result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   LDR Exclusive (16 bit)
 * @details Executes a exclusive LDR instruction for 16 bit values.
 * @param [in]    addr  Pointer to data
 * @return        value of type uint16_t at (*addr)
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 *          This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint16_t __LDREXH (volatile uint16_t * addr)
{
    uint16_t result;

    /* Load to start atomic halfword data manipulation */
    __ASM volatile ("ldl.hu [%1], %0" : "=&r" (result) : "r" (addr) : "memory");

    /* Add explicit type cast here */
    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   STR Exclusive (16 bit)
 * @details Executes a exclusive STR instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 *          This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint32_t __STREXH (uint16_t value, volatile uint16_t * addr)
{
    uint32_t result;

    __ASM volatile (
        "stc.h %2, [%1]    \n"
        "mov   1, %0       \n"
        "xor   %2, %0      \n"
        : "=&r" (result) : "r" (addr), "r" (value) : "memory", "cc"
        );

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief   LDR Exclusive (32 bit)
 * @details Executes a exclusive LDR instruction for 32 bit values.
 * @param [in]    addr  Pointer to data
 * @return        value of type uint32_t at (*addr)
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint32_t __LDREXW (volatile uint32_t * addr)
{
    uint32_t result;

    /* Load to start atomic word data manipulation */
    __ASM volatile ("ldl.w [%1], %0" : "=&r" (result) : "r" (addr) : "memory");

    /* Add explicit type cast here */
    return result;
}

/**
 * @brief   STR Exclusive (32 bit)
 * @details Executes a exclusive STR instruction for 32 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint32_t __STREXW (uint32_t value, volatile uint32_t * addr)
{
    uint32_t result;

    __ASM volatile (
        "stc.w %2, [%1]    \n"
        "mov   1, %0       \n"
        "xor   %2, %0      \n"
        : "=&r" (result) : "r" (addr), "r" (value) : "memory", "cc"
        );

    return result;
}

/**
 * @brief   Rotate Right with Extend (32 bit)
 * @details Moves each bit of a bitstring right by one bit.
 *         The carry input is shifted in at the left end of the bitstring.
 * @param [in]    value  Value to rotate
 * @return               Rotated value
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint32_t __RRX (uint32_t value)
{
    uint32_t result;

    __ASM volatile (
        "stsr    5, r11, 0          \n"  /* r11 <- PSW */
        "shr     3, r11             \n"  /* r11.bit0 = CY */
        "andi    1, r11, r11        \n"  /* r11 = CY (0 or 1) */
        "shl     31, r11            \n"  /* r11 = CY << 31 */
        /* Shift operand and inject CY into MSB */
        "mov     %1, %0             \n"
        "shr     1, %0              \n"  /* r10 = value >> 1 */
        "or      r11, %0            \n"  /* r10 = (CY<<31) | (value>>1) */

        /* Compute new CY from old LSB of value: newCY_mask = (value & 1) << 3 */
        "mov     %1, r12            \n"
        "andi    1, r12, r12        \n"  /* r12 = old LSB of value (0 or 1) */
        "shl     3, r12             \n"  /* r12 = newCY_mask (0x0 or 0x8) */

        /* Read PSW, clear CY bit, then set according to newCY_mask */
        "stsr    5, r13, 0          \n"  /* r13 <- PSW */

        /* Clear-mask (~0x8) */
        "movhi   0xFFFF, r0, r11    \n"  /* r11 = 0xFFFF0000 */
        "ori     0xFFF7, r11, r11   \n"  /* r11 = 0xFFFF0000 + 0xFFF7 = 0xFFFFFFF7 */
        "and     r11, r13           \n"  /* r13 &= ~0x8  (clear PSW.CY) */
        "or      r12, r13           \n"  /* r13 |= newCY_mask */

        /* Write PSW back */
        "ldsr    r13, 5, 0           \n" /* PSW <- r13 */
        : "=&r" (result)
        : "r" (value)
        : "memory", "r11", "r12", "r13"
        );

    return result;
}

/**
 * @brief   Load-Acquire (8 bit)
 * @details Executes a LDAB instruction for 8 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type uint8_t at (*ptr)
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint8_t __LDAB (volatile uint8_t * ptr)
{
    uint8_t result;

    __ASM volatile (
        "ld.bu 0[%1], %0        \n"
        "synce                  \n"
        : "=&r" (result) : "r" (ptr) : "memory");

    /* Add explicit type cast here */
    return result;
}

/**
 * @brief   Load-Acquire (16 bit)
 * @details Executes a LDAH instruction for 16 bit values.
 * @param [in]    ptr  Pointer to data
 * @return        value of type uint16_t at (*ptr)
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint16_t __LDAH (volatile uint16_t * ptr)
{
    uint16_t result;

    __ASM volatile (
        "ld.hu 0[%1], %0        \n"
        "synce                  \n"
        : "=&r" (result) : "r" (ptr) : "memory");

    /* Add explicit type cast here */
    return result;
}

/**
 * @brief   Load-Acquire (32 bit)
 * @details Executes a LDA instruction for 32 bit values.
 * @param [in]    ptr  Pointer to data
 * @return        value of type uint32_t at (*ptr)
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint32_t __LDA (volatile uint32_t * ptr)
{
    uint32_t result;

    __ASM volatile (
        "ld.w 0[%1], %0         \n"
        "synce                  \n"
        : "=&r" (result) : "r" (ptr) : "memory");

    /* Add explicit type cast here */
    return result;
}

/**
 * @brief   Store-Release (8 bit)
 * @details Executes a STLB instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE void __STLB (uint8_t value, volatile uint8_t * ptr)
{
    __ASM volatile (
        "synce              \n"
        "st.b %0, 0[%1]     \n"
        : : "r" (value), "r" (ptr) : "memory"
        );
}

/**
 * @brief   Store-Release (16 bit)
 * @details Executes a STLH instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE void __STLH (uint16_t value, volatile uint16_t * ptr)
{
    __ASM volatile (
        "synce              \n"
        "st.h %0, 0[%1]     \n"
        : : "r" (value), "r" (ptr) : "memory"
        );
}

/**
 * @brief   Store-Release (32 bit)
 * @details Executes a STL instruction for 32 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE void __STL (uint32_t value, volatile uint32_t * ptr)
{
    __ASM volatile (
        "synce              \n"
        "st.w %0, 0[%1]     \n"
        : : "r" (value), "r" (ptr) : "memory"
        );
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   Load-Acquire Exclusive (8 bit)
 * @details Executes a LDAB exclusive instruction for 8 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type uint8_t at (*ptr)
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 *          This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint8_t __LDAEXB (volatile uint8_t * ptr)
{
    uint32_t result;

    /* Load to start atomic byte data manipulation */
    __ASM volatile (
        "ldl.bu [%1], %0    \n"
        "synce              \n"
        : "=&r" (result) : "r" (ptr) : "memory");

    /* Add explicit type cast here */
    return (uint8_t) result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   Load-Acquire Exclusive (16 bit)
 * @details Executes a LDAH exclusive instruction for 16 bit values.
 * @param [in]    ptr  Pointer to data
 * @return        value of type uint16_t at (*ptr)
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 *          This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint16_t __LDAEXH (volatile uint16_t * ptr)
{
    uint32_t result;

    /* Load to start atomic byte data manipulation */
    __ASM volatile (
        "ldl.hu [%1], %0    \n"
        "synce              \n"
        : "=&r" (result) : "r" (ptr) : "memory");

    /* Add explicit type cast here */
    return (uint16_t) result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief   Load-Acquire Exclusive (32 bit)
 * @details Executes a LDA exclusive instruction for 32 bit values.
 * @param [in]    ptr  Pointer to data
 * @return        value of type uint32_t at (*ptr)
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint32_t __LDAEX (volatile uint32_t * ptr)
{
    uint32_t result;

    /* Load to start atomic byte data manipulation */
    __ASM volatile (
        "ldl.w [%1], %0     \n"
        "synce              \n"
        : "=&r" (result) : "r" (ptr) : "memory");

    /* Add explicit type cast here */
    return result;
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   Store-Release Exclusive (8 bit)
 * @details Executes a STLB exclusive instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 *          This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint32_t __STLEXB (uint8_t value, volatile uint8_t * ptr)
{
    uint32_t result;

    __ASM volatile (
        "synce            \n"
        "stc.b %2, [%1]   \n"
        "mov   1, %0      \n"
        "xor   %2, %0     \n"
        : "=&r" (result) : "r" (ptr), "r" (value) : "memory", "cc"
        );

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   Store-Release Exclusive (16 bit)
 * @details Executes a STLH exclusive instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 *          This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint32_t __STLEXH (uint16_t value, volatile uint16_t * ptr)
{
    uint32_t result;

    __ASM volatile (
        "synce            \n"
        "stc.h %2, [%1]   \n"
        "mov   1, %0      \n"
        "xor   %2, %0     \n"
        : "=&r" (result) : "r" (ptr), "r" (value) : "memory", "cc"
        );

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief   Store-Release Exclusive (32 bit)
 * @details Executes a STL exclusive instruction for 32 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint32_t __STLEX (uint32_t value, volatile uint32_t * ptr)
{
    uint32_t result;

    __ASM volatile (
        "synce            \n"
        "stc.w %1, [%2]   \n"
        "mov   1, %0      \n"
        "xor   %1, %0     \n"
        : "=&r" (result), "+r" (value) : "r" (ptr) : "memory", "cc"
        );

    return result;
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   STR Exclusive (8 bit)
 * @details Executes a exclusive STR instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep RH850 function name and ensure identical behavior on RH850.
 *          This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint32_t __STREXB (uint8_t value, volatile uint8_t * addr)
{
    uint32_t result;

    __ASM volatile (
        "stc.b %2, [%1]    \n"
        "mov   1, %0       \n"
        "xor   %2, %0      \n"
        : "=&r" (result) : "r" (addr), "r" (value) : "memory", "cc"
        );

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/********************************************* RH850 INTRINSIC ********************************************************/

/* Load Instructions */

/**
 * @brief   Load byte
 * @details Executes a LD.B instruction for 8 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type int8_t at (*ptr)
 */
__STATIC_FORCEINLINE int8_t __LDB (volatile int8_t * ptr)
{
    int8_t result;
    __ASM volatile ("ld.b 0[%1], %0" : "=&r" (result) : "r" (ptr) : "memory");

    return result;
}

/**
 * @brief   Load byte unsigned
 * @details Executes a LD.BU instruction for 8 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type uint8_t at (*ptr)
 */
__STATIC_FORCEINLINE uint8_t __LDBU (volatile uint8_t * ptr)
{
    uint8_t result;
    __ASM volatile ("ld.bu 0[%1], %0" : "=&r" (result) : "r" (ptr) : "memory");

    return result;
}

/**
 * @brief   Load halfword
 * @details Executes a LD.H instruction for 16 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type int16_t at (*ptr)
 */
__STATIC_FORCEINLINE int16_t __LDH (volatile int16_t * ptr)
{
    int16_t result;
    __ASM volatile ("ld.h 0[%1], %0" : "=&r" (result) : "r" (ptr) : "memory");

    return result;
}

/**
 * @brief   Load halfword unsigned
 * @details Executes a LD.HU instruction for 16 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type int16_t at (*ptr)
 */
__STATIC_FORCEINLINE uint16_t __LDHU (volatile uint16_t * ptr)
{
    uint16_t result;
    __ASM volatile ("ld.hu 0[%1], %0" : "=&r" (result) : "r" (ptr) : "memory");

    return result;
}

/**
 * @brief   Load word
 * @details Executes a LD.W instruction for 32 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type int32_t at (*ptr)
 */
__STATIC_FORCEINLINE int32_t __LDW (volatile int32_t * ptr)
{
    int32_t result;
    __ASM volatile ("ld.w 0[%1], %0" : "=&r" (result) : "r" (ptr) : "memory");

    return result;
}

/**
 * @brief   Load double word
 * @details Executes a LD.DW instruction for 64 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type int64_t at (*ptr)
 */
__STATIC_FORCEINLINE int64_t __LDDW (volatile int64_t * ptr)
{
    int64_t result;
    __ASM volatile ("ld.dw 0[%1], %0" : "=&r" (result) : "r" (ptr) : "memory");

    return result;
}

/* Store Instructions */

/**
 * @brief   Store byte
 * @details Executes a ST.B instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 */
__STATIC_FORCEINLINE void __STB (int8_t value, volatile int8_t * ptr)
{
    __ASM volatile ("st.b %0, 0[%1]" : : "r" (value), "r" (ptr) : "memory");
}

/**
 * @brief   Store halfword
 * @details Executes a ST.H instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 */
__STATIC_FORCEINLINE void __STH (int16_t value, volatile int16_t * ptr)
{
    __ASM volatile ("st.h %0, 0[%1]" : : "r" (value), "r" (ptr) : "memory");
}

/**
 * @brief   Store word
 * @details Executes a ST.W instruction for 32 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 */
__STATIC_FORCEINLINE void __STW (int32_t value, volatile int32_t * ptr)
{
    __ASM volatile ("st.w %0, 0[%1]" : : "r" (value), "r" (ptr) : "memory");
}

/**
 * @brief   Store double word
 * @details Executes a ST.DW instruction for 64 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 */
__STATIC_FORCEINLINE void __STDW (int64_t value, volatile int64_t * ptr)
{
    __ASM volatile ("st.dw %0, 0[%1]" : : "r" (value), "r" (ptr) : "memory");
}

/* Multiply Instructions */

/**
 * @brief   Signed 64-bit multiplication high 32 bits
 * @details Assigns higher 32 bits of signed 64-bit multiplication result.
 * @param [in]    a   Multiplicand
 * @param [in]    b   Multiplier
 * @return             High 32 bits of result
 */
__STATIC_FORCEINLINE int32_t __MUL (int32_t a, int32_t b)
{
    int32_t result;
    int32_t reg1 = a;
    int32_t reg2 = b;
    __ASM volatile ("mul %2, %1, %0" : "=r" (result), "+r" (reg2) : "r" (reg1) : "memory");

    return result;
}

/**
 * @brief   Unsigned 64-bit multiplication high 32 bits
 * @details Assigns higher 32 bits of unsigned 64-bit multiplication result.
 * @param [in]    a   Multiplicand
 * @param [in]    b   Multiplier
 * @return             High 32 bits of result
 */
__STATIC_FORCEINLINE long __MULU (long a, long b)
{
    long result;
    long reg1 = a;
    long reg2 = b;

    __ASM volatile ("mulu %2, %1, %0" : "=r" (result), "+r" (reg2) : "r" (reg1) : "memory");

    return result;
}

/**
 * @brief   Saturated addition
 * @details Performs saturated addition of two signed integers.
 * @param [in]    a   First operand
 * @param [in]    b   Second operand
 * @return             Result of saturated addition
 */
#ifndef __SATADD
 #define __SATADD(a, b)    __saturated_add((long) a, (long) b)
#endif

/**
 * @brief   Saturated subtraction
 * @details Performs saturated subtraction of two signed integers.
 * @param [in]    a   First operand
 * @param [in]    b   Second operand
 * @return             Result of saturated subtraction
 */
#ifndef __SATSUB
 #define __SATSUB(a, b)    __saturated_sub((long) a, (long) b)
#endif

/**
 * @brief   Halfword data byte swap
 * @details Swaps bytes within a 16-bit halfword.
 * @param [in]    value   Value to swap
 * @return                Swapped value
 */
#define __BSH(value)       __BSH((long) value)

/**
 * @brief   Word data byte swap
 * @details Swaps bytes within a 32-bit word.
 * @param [in]    value   Value to swap
 * @return                Swapped value
 */
#define __BSW(value)       __BSW((long) value)

#if (RH850_UNSUPPORTED)

/**
 * @brief   Signed data conversion from word to byte with saturation
 * @details Conversion of signed word data to byte data with saturation
 * @param [in]    value   Data conversion
 * @return             Data in byte with saturation
 */
RH850_UNSUPPORTED __STATIC_FORCEINLINE int8_t __CLIPB (int32_t value)
{
    int8_t result;
    __ASM volatile ("clip.b  %1, %0" : "=&r" (result) : "r" (value) : "memory");

    return result;
}

/**
 * @brief   Unsigned data conversion from word to byte with saturation
 * @details Conversion of unsigned word data to byte data with saturation
 * @param [in]    value   Data conversion
 * @return             Data in byte with saturation
 */
__STATIC_FORCEINLINE RH850_UNSUPPORTED uint8_t __CLIPBU (uint32_t value)
{
    uint8_t result;
    __ASM volatile ("clip.bu  %1, %0" : "=&r" (result) : "r" (value) : "memory");

    return result;
}

/**
 * @brief   Signed data conversion from word to halfword with saturation
 * @details Conversion of unsigned word data to byte data with saturation
 * @param [in]    value   Data conversion
 * @return             Data in haflword with saturation
 */
__STATIC_FORCEINLINE RH850_UNSUPPORTED int16_t __CLIPH (int32_t value)
{
    int16_t result;
    __ASM volatile ("clip.h  %1, %0" : "=&r" (result) : "r" (value) : "memory");

    return result;
}

/**
 * @brief   Unsigned data conversion from word to halfword with saturation
 * @details Conversion of unsigned word data to halfword data with saturation
 * @param [in]    value   Data conversion
 * @return             Data in haflword with saturation
 */
__STATIC_FORCEINLINE RH850_UNSUPPORTED uint16_t __CLIPHU (uint32_t value)
{
    uint16_t result;
    __ASM volatile ("clip.hu  %1, %0" : "=&r" (result) : "r" (value) : "memory");

    return result;
}

#endif                                 /* RH850_UNSUPPORTED */

/**
 * @brief   Halfword swap halfword
 * @details Swaps halfwords within a 16-bit word.
 * @param [in]    value   Value to swap
 * @return                Swapped value
 */
__STATIC_FORCEINLINE int16_t __HSH (int16_t value)
{
    int16_t result;
    __ASM volatile ("hsh  %1, %0" : "=&r" (result) : "r" (value) : "memory");

    return result;
}

/**
 * @brief   Word data halfword swap
 * @details Swaps halfwords within a 32-bit word.
 * @param [in]    value   Value to swap
 * @return                Swapped value
 */
#define __HSW(value)    __HSW((long) value)

/**
 * @brief   Rotate left
 * @param [in]    value   Value to rotate
 * @param [in]    bit     The specified shift amount
 * @return                Swapped value
 */
__STATIC_FORCEINLINE int32_t __ROTL (int32_t value, uint8_t bit)
{
    int32_t result;
    __ASM volatile ("rotl  %1, %2, %0" : "=&r" (result) : "r" (bit), "r" (value) : "memory");

    return result;
}

/**
 * @brief   Bit (0) search from MSB side
 * @details Searches for first 0 bit starting from MSB.
 * @param [in]    value   Value to search
 * @return             Bit position
 */
#define __SCH0L(value)    __SCH0L((long) value)

/**
 * @brief   Bit (0) search from LSB side
 * @details Searches for first 0 bit starting from LSB.
 * @param [in]    value   Value to search
 * @return             Bit position
 */
#define __SCH0R(value)    __SCH0R((long) value)

/**
 * @brief   Bit (1) search from MSB side
 * @details Searches for first 1 bit starting from MSB.
 * @param [in]    value   Value to search
 * @return                Bit position
 */
#define __SCH1L(value)    __SCH1L((long) value)

/**
 * @brief   Bit (1) search from LSB side
 * @details Searches for first 1 bit starting from LSB.
 * @param [in]    value   Value to search
 * @return             Bit position
 */
#define __SCH1R(value)    __SCH1R((long) value)

/**
 * @brief   Divide word
 * @param [in]  num1  Dividend number
 * @param [in]  num2  Divisor number
 * @return             Quotient = num1/num2
 */
__STATIC_FORCEINLINE int32_t __DIV (int32_t num1, int32_t num2)
{
    int32_t result;
    __ASM volatile ("div  %2, %1, %0" : "=&r" (result), "+r" (num1) : "r" (num2) : "memory");

    return result;
}

/**
 * @brief   Divide word unsigned
 * @param [in]  num1  Dividend number
 * @param [in]  num2  Divisor number
 * @return             Quotient = num1/num2
 */
__STATIC_FORCEINLINE uint32_t __DIVU (uint32_t num1, uint32_t num2)
{
    uint32_t result;
    __ASM volatile ("divu  %2, %1, %0" : "=&r" (result) : "r" (num1), "r" (num2) : "memory");

    return result;
}

/**
 * @brief   Bit clear
 * @details Clear bit a specific bit in a value.
 * @param [in]    addr    Address
 * @param [in]    bit  Bit position
 */
__STATIC_FORCEINLINE void __CLR1 (volatile uint8_t * addr, uint8_t bit)
{
    __ASM volatile (
        "mov   %0, r15              \n"
        "clr1  %0, [%1]             \n"
        : : "r" (bit), "r" (addr) : "memory", "r15");
}

/**
 * @brief   Bit set
 * @details Sets a specific bit in a value.
 * @param [in]    addr    Address
 * @param [in]    bit  Bit position
 */
__STATIC_FORCEINLINE void __SET1 (volatile uint8_t * addr, uint8_t bit)
{
    __ASM volatile (
        "mov   %0, r15              \n"
        "set1  %0, [%1]             \n"
        : : "r" (bit), "r" (addr) : "memory", "r15");
}

/**
 * @brief   Bit not
 * @details Toggles a specific bit in a value.
 * @param [in]    addr    Address
 * @param [in]    bit  Bit position
 */
__STATIC_FORCEINLINE void __NOT1 (volatile uint8_t * addr, uint8_t bit)
{
    __ASM volatile (
        "mov   %0, r15              \n"
        "not1  %0, [%1]             \n"
        : : "r" (bit), "r" (addr) : "memory", "r15");
}

/**
 * @brief   Compare and Exchange
 * @details Atomic compare and exchange operation.
 * @param [in]    addr   Address
 * @param [in]    b   Compare value
 * @param [in]    c   Exchange value
 */
#define __CAXI(addr, b, c)    __CAXI((int *) addr, (int) b, (int) c)

/**
 * @brief   Clear Load Link
 * @details Clear Load Link which is created by LDL.
 */
__STATIC_FORCEINLINE void __CLL (void)
{
    __ASM volatile ("cll" ::: "memory"); /* Clear Load Link */
}

/**
 * @brief   Disable Interrupts
 * @details Executes the DI instruction to disable maskable interrupts.
 */
#define __DI()                         __disable_interrupt()

/**
 * @brief   Enable Interrupts
 * @details Executes the EI instruction to enable maskable interrupts.
 */
#define __EI()                         __enable_interrupt()

/**
 * @brief   Return from EI-level trap or interrupt
 */
#define __EIRET()                      __ASM volatile ("eiret")

/**
 * @brief   Return from FE-level trap or interrupt
 */
#define __FERET()                      __ASM volatile ("feret")

/**
 * @brief   FE-level trap
 */
#define __FETRAP(vector)               __ASM volatile ("fetrap " #vector)

/**
 * @brief   Load to system register (with selector)
 * @details Loads value into system register with selector ID.
 * @param [in]    regID  Register ID
 * @param [in]    selID  Selector ID
 * @param [in]    value      Value to load
 */
#define __LDSR(regID, selID, value)    __LDSR((int) regID, (int) selID, (long) value)

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   LDR Exclusive (8 bit)
 * @details Executes a exclusive LDR instruction for 8 bit value.
 * @param [in]    addr  Pointer to data
 * @return             value of type uint8_t at (*addr)
 * @note    This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint8_t __LDLBU (volatile uint8_t * addr)
{
    uint32_t result;

    /* Load to start atomic byte data manipulation */
    __ASM volatile ("ldl.bu [%1], %0" : "=&r" (result) : "r" (addr) : "memory");

    /* Add explicit type cast here */
    return (uint8_t) result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   LDR Exclusive (16 bit)
 * @details Executes a exclusive LDR instruction for 16 bit values.
 * @param [in]    addr  Pointer to data
 * @return        value of type uint16_t at (*ptr)
 * @note    This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint16_t __LDLHU (volatile uint16_t * addr)
{
    uint32_t result;

    /* Load to start atomic byte data manipulation */
    __ASM volatile ("ldl.hu [%1], %0" : "=&r" (result) : "r" (addr) : "memory");

    /* Add explicit type cast here */
    return (uint16_t) result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief   Atomic load to system register
 * @details Loads a value into a system register atomically.
 * @param [in]    value   Value to load
 */
__STATIC_FORCEINLINE uint32_t __LDLW (volatile uint32_t * value)
{
    uint32_t result;

    /* Load to start atomic byte data manipulation */
    __ASM volatile ("ldl.w [%1], %0" : "=&r" (result) : "r" (value) : "memory");

    /* Add explicit type cast here */
    return result;
}

/**
 * @brief   No Operation
 * @details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
#define __NOP()                 __no_operation()

/**
 * @brief   Restore contexts from register bank
 */
#define __RESBANK()             __ASM volatile ("resbank")

/**
 * @brief   Snooze
 */
#define __SNOOZE()              __snooze()

/**
 * @brief   Store contents of system register (with selector)
 * @details Stores contents of system register with selector ID.
 * @param [in]    regID  Register ID
 * @param [in]    selID  Selector ID
 * @return               Register value
 */
#define __STSR(regID, selID)    __STSR((int) regID, (int) selID)

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   STR Exclusive (8 bit)
 * @details Executes a exclusive STR instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint8_t __STCB (volatile uint8_t * addr, uint8_t value)
{
    uint32_t result;

    __ASM volatile (
        "stc.b %1, [%2]    \n"
        "mov   %1, %0      \n"
        : "=&r" (result), "+r" (value) : "r" (addr) : "memory", "cc"
        );

    return (uint8_t) result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief   STR Exclusive (16 bit)
 * @details Executes a exclusive STR instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    This instruction is not supported by IAR for the G4KH core.
 */
__STATIC_FORCEINLINE uint16_t __STCH (volatile uint16_t * addr, uint16_t value)
{
    uint32_t result;

    __ASM volatile (
        "stc.h %1, [%2]    \n"
        "mov   %1, %0      \n"
        : "=&r" (result), "+r" (value) : "r" (addr) : "memory", "cc"
        );

    return (uint16_t) result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief   Store word
 * @details Stores a word to memory.
 * @param [in]    addr    Address
 * @param [in]    value    Value
 */
#define __STCW(addr, value)         __STC((long *) addr, (long) value)

/**
 * @brief   Exception synchronization
 * @details Synchronizes exception handling.
 */
#define __SYNCE()                   __SYNCE()

/**
 * @brief   Instruction pipeline synchronization
 * @details Synchronizes instruction pipeline.
 */
#define __SYNCI()                   __SYNCI()

/**
 * @brief   Memory synchronization
 * @details Synchronizes memory operations.
 */
#define __SYNCM()                   __SYNCM()

/**
 * @brief   Pipeline synchronization
 * @details Synchronizes pipeline operations.
 */
#define __SYNCP()                   __SYNCP()

/**
 * @brief   Trap
 */
#define __TRAP(vector)              __ASM volatile ("trap " #vector::: "memory")

/**
 * @brief   Halt CPU
 * @details HALT instruction stops CPU execution until an interrupt or reset occurs.
 */
#define __HALT()                    __halt()

/**
 * @brief   Debug checkpoint
 * @details Inserts a debug checkpoint instruction.
 */
#define __DBCP()                    __DBCP()

/**
 * @brief   Debug push
 * @details Pushes debug registers.
 * @param [in]    regID1  First register ID
 * @param [in]    regID2  Second register ID
 */
#define __DBPUSH(regID1, regID2)    __DBPUSH((long) regID1, (long) regID2)

/**
 * @brief   Debug tag
 * @details Inserts a debug tag instruction.
 * @param [in]    a   Tag value
 */
#define __DBTAG(a)                  __DBTAG(a)

/** @}*/ /* end of group IAR_RH850_Core_InstructionInterface */

/** @}*/ /* end of group RH850_Core_InstructionInterface */

/* ##########################################  Core Function Access  ################################################ */

/** @defgroup RH850_Core_FunctionInterface RH850-Core Register Access Functions
 * @brief Access to the dedicated core register access function instructions
 * @{
 */

/** @ingroup  RH850_Core_FunctionInterface
 *  @defgroup IAR_RH850_Core_RegAccFunctions IAR RH850-Core Register Access Functions
 *  @brief IAR RH850-Core Register Access Functions
 * @{
 */

/**
 * @brief   Enable IRQ Interrupts
 * @details Enables IRQ interrupts by clearing special-purpose register PRIMASK.
 *         Can only be executed in Privileged modes.
 */
#define  __enable_irq()    __EI()

/**
 * @brief   Disable IRQ Interrupts
 * @details Disables IRQ interrupts by setting special-purpose register PRIMASK.
 *         Can only be executed in Privileged modes.
 */
#define __disable_irq()    __DI()

/***********************************************************************************************************************
 *                 Basic System Registers
 **********************************************************************************************************************/

/**
 * @brief Set EIPC (Status save registers when acknowledging EI level exception).
 * @details Writes a value to the EIPC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_EIPC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 0, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get EIPC (Status save registers when acknowledging EI level exception).
 * @details Reads the current value of the EIPC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_EIPC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 0, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set EIPSW (Status save registers when acknowledging EI level exception).
 * @details Writes a value to the EIPSW system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_EIPSW (uint32_t value)
{
    __ASM volatile ("ldsr %0, 1, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get EIPSW (Status save registers when acknowledging EI level exception).
 * @details Reads the current value of the EIPSW system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_EIPSW (void)
{
    uint32_t result;

    __ASM volatile ("stsr 1, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set FEPC (Status save registers when acknowledging FE level exception).
 * @details Writes a value to the FEPC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FEPC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 2, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FEPC (Status save registers when acknowledging FE level exception).
 * @details Reads the current value of the FEPC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FEPC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 2, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set FEPSW (Status save registers when acknowledging FE level exception).
 * @details Writes a value to the FEPSW system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FEPSW (uint32_t value)
{
    __ASM volatile ("ldsr %0, 3, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FEPSW (Status save registers when acknowledging FE level exception).
 * @details Reads the current value of the FEPSW system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FEPSW (void)
{
    uint32_t result;

    __ASM volatile ("stsr 3, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set PSW (Program status word).
 * @details Writes a value to the PSW system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PSW (uint32_t value)
{
    __ASM volatile ("ldsr %0, 5, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get PSW (Program status word).
 * @details Reads the current value of the PSW system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PSW (void)
{
    uint32_t result;

    __ASM volatile ("stsr 5, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set EIIC (EI level exception cause).
 * @details Writes a value to the EIIC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_EIIC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 13, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get EIIC (EI level exception cause).
 * @details Reads the current value of the EIIC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_EIIC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 13, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set FEIC (FE level exception cause).
 * @details Writes a value to the FEIC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FEIC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 14, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FEIC (FE level exception cause).
 * @details Reads the current value of the FEIC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FEIC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 14, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set CTPC (CALLT execution status save register).
 * @details Writes a value to the CTPC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_CTPC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 16, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get CTPC (CALLT execution status save register).
 * @details Reads the current value of the CTPC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_CTPC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 16, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set CTPSW (CALLT execution status save register).
 * @details Writes a value to the CTPSW system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_CTPSW (uint32_t value)
{
    __ASM volatile ("ldsr %0, 17, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get CTPSW (CALLT execution status save register).
 * @details Reads the current value of the CTPSW system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_CTPSW (void)
{
    uint32_t result;

    __ASM volatile ("stsr 17, %0, 0" : "=r" (result));

    return result;
}

/* CALLT base pointer */

/**
 * @brief Set CTBP (CALLT base pointer).
 * @details Writes a value to the CTBP system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_CTBP (uint32_t value)
{
    __ASM volatile ("ldsr %0, 20, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get CTBP (CALLT base pointer).
 * @details Reads the current value of the CTBP system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_CTBP (void)
{
    uint32_t result;

    __ASM volatile ("stsr 20, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set SNZCFG (SNOOZE control register).
 * @details Writes a value to the SNZCFG system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_SNZCFG (uint32_t value)
{
    __ASM volatile ("ldsr %0, 21, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get SNZCFG (SNOOZE control register).
 * @details Reads the current value of the SNZCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_SNZCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 21, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set EIWR (EI level exception working register).
 * @details Writes a value to the EIWR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_EIWR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 28, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get EIWR (EI level exception working register).
 * @details Reads the current value of the EIWR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_EIWR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 28, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set FEWR (FE level exception working register).
 * @details Writes a value to the FEWR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FEWR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 29, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FEWR (FE level exception working register).
 * @details Reads the current value of the FEWR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FEWR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 29, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set SPID (System protection identifier).
 * @details Writes a value to the SPID system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_SPID (uint32_t value)
{
    __ASM volatile ("ldsr %0, 0, 1" : : "r" (value) : "memory");
}

/**
 * @brief Get SPID (System protection identifier).
 * @details Reads the current value of the SPID system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_SPID (void)
{
    uint32_t result;

    __ASM volatile ("stsr 0, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Get SPIDLIST (List of system protection identifiers that can be specified in SPID).
 * @details Reads the current value of the SPIDLIST system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_SPIDLIST (void)
{
    uint32_t result;

    __ASM volatile ("stsr 1, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Get RBASE (Reset vector base address).
 * @details Reads the current value of the RBASE system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_RBASE (void)
{
    uint32_t result;

    __ASM volatile ("stsr 2, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Set EBASE (Exception handler vector address).
 * @details Writes a value to the EBASE system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_EBASE (uint32_t value)
{
    __ASM volatile ("ldsr %0, 3, 1" : : "r" (value) : "memory");
}

/**
 * @brief Get EBASE (Exception handler vector address).
 * @details Reads the current value of the EBASE system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_EBASE (void)
{
    uint32_t result;

    __ASM volatile ("stsr 3, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Set INTBP (Base address of the interrupt handler "address" table).
 * @details Writes a value to the INTBP system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_INTBP (uint32_t value)
{
    __ASM volatile ("ldsr %0, 4, 1" : : "r" (value) : "memory");
}

/**
 * @brief Get INTBP (Base address of the interrupt handler "address" table).
 * @details Reads the current value of the INTBP system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_INTBP (void)
{
    uint32_t result;

    __ASM volatile ("stsr 4, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Set MCTL (CPU control).
 * @details Writes a value to the MCTL system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MCTL (uint32_t value)
{
    __ASM volatile ("ldsr %0, 5, 1" : : "r" (value) : "memory");
}

/**
 * @brief Get MCTL (CPU control).
 * @details Reads the current value of the MCTL system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MCTL (void)
{
    uint32_t result;

    __ASM volatile ("stsr 5, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Get PID (Processor ID).
 * @details Reads the current value of the PID system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PID (void)
{
    uint32_t result;

    __ASM volatile ("stsr 6, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Set SVLOCK (Supervisor lock).
 * @details Writes a value to the SVLOCK system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_SVLOCK (uint32_t value)
{
    __ASM volatile ("ldsr %0, 8, 1" : : "r" (value) : "memory");
}

/**
 * @brief Get SVLOCK (Supervisor lock).
 * @details Reads the current value of the SVLOCK system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_SVLOCK (void)
{
    uint32_t result;

    __ASM volatile ("stsr 8, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Set SCCFG (SYSCALL operation setting).
 * @details Writes a value to the SCCFG system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_SCCFG (uint32_t value)
{
    __ASM volatile ("ldsr %0, 11, 1" : : "r" (value) : "memory");
}

/**
 * @brief Get SCCFG (SYSCALL operation setting).
 * @details Reads the current value of the SCCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_SCCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 11, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Set SCBP (SYSCALL base pointer).
 * @details Writes a value to the SCBP system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_SCBP (uint32_t value)
{
    __ASM volatile ("ldsr %0, 12, 1" : : "r" (value) : "memory");
}

/**
 * @brief Get SCBP (SYSCALL base pointer).
 * @details Reads the current value of the SCBP system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_SCBP (void)
{
    uint32_t result;

    __ASM volatile ("stsr 12, %0, 1" : "=r" (result));

    return result;
}

/**
 * @brief Get PEID (Processor element identifier).
 * @details Reads the current value of the PEID system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PEID (void)
{
    uint32_t result;

    __ASM volatile ("stsr 0, %0, 2" : "=r" (result));

    return result;
}

/**
 * @brief Get BMID (Bus master identifier).
 * @details Reads the current value of the BMID system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_BMID (void)
{
    uint32_t result;

    __ASM volatile ("stsr 1, %0, 2" : "=r" (result));

    return result;
}

/**
 * @brief Set MEA (Memory error address).
 * @details Writes a value to the MEA system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MEA (uint32_t value)
{
    __ASM volatile ("ldsr %0, 6, 2" : : "r" (value) : "memory");
}

/**
 * @brief Get MEA (Memory error address).
 * @details Reads the current value of the MEA system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MEA (void)
{
    uint32_t result;

    __ASM volatile ("stsr 6, %0, 2" : "=r" (result));

    return result;
}

/**
 * @brief Set MEI (Memory error information).
 * @details Writes a value to the MEI system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MEI (uint32_t value)
{
    __ASM volatile ("ldsr %0, 8, 2" : : "r" (value) : "memory");
}

/**
 * @brief Get MEI (Memory error information).
 * @details Reads the current value of the MEI system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MEI (void)
{
    uint32_t result;

    __ASM volatile ("stsr 8, %0, 2" : "=r" (result));

    return result;
}

/**
 * @brief Set RBCR0 (Register bank control 0).
 * @details Writes a value to the RBCR0 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_RBCR0 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 15, 2" : : "r" (value) : "memory");
}

/**
 * @brief Get RBCR0 (Register bank control 0).
 * @details Reads the current value of the RBCR0 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_RBCR0 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 15, %0, 2" : "=r" (result));

    return result;
}

/**
 * @brief Set RBCR1 (Register bank control 1).
 * @details Writes a value to the RBCR1 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_RBCR1 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 16, 2" : : "r" (value) : "memory");
}

/**
 * @brief Get RBCR1 (Register bank control 1).
 * @details Reads the current value of the RBCR1 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_RBCR1 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 16, %0, 2" : "=r" (result));

    return result;
}

/**
 * @brief Set RBNR (Register bank number).
 * @details Writes a value to the RBNR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_RBNR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 17, 2" : : "r" (value) : "memory");
}

/**
 * @brief Get RBNR (Register bank number).
 * @details Reads the current value of the RBNR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_RBNR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 17, %0, 2" : "=r" (result));

    return result;
}

/**
 * @brief Set RBIP (Register bank initial pointer).
 * @details Writes a value to the RBIP system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_RBIP (uint32_t value)
{
    __ASM volatile ("ldsr %0, 18, 2" : : "r" (value) : "memory");
}

/**
 * @brief Get RBIP (Register bank initial pointer).
 * @details Reads the current value of the RBIP system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_RBIP (void)
{
    uint32_t result;

    __ASM volatile ("stsr 18, %0, 2" : "=r" (result));

    return result;
}

/***********************************************************************************************************************
 *                 Interrupt Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set ISPR (Priority of interrupt being serviced).
 * @details Writes a value to the ISPR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_ISPR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 10, 2" : : "r" (value) : "memory");
}

/**
 * @brief Get ISPR (Priority of interrupt being serviced).
 * @details Reads the current value of the ISPR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_ISPR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 10, %0, 2" : "=r" (result));

    return result;
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get IMSR (Interrupt mask status).
 * @details Reads the current value of the IMSR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_IMSR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 11, %0, 2" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief Get ICSR (Interrupt control status).
 * @details Reads the current value of the ICSR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_ICSR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 12, %0, 2" : "=r" (result));

    return result;
}

/**
 * @brief Set INTCFG (Interrupt function setting).
 * @details Writes a value to the INTCFG system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_INTCFG (uint32_t value)
{
    __ASM volatile ("ldsr %0, 13, 2" : : "r" (value) : "memory");
}

/**
 * @brief Get INTCFG (Interrupt function setting).
 * @details Reads the current value of the INTCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_INTCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 13, %0, 2" : "=r" (result));

    return result;
}

/**
 * @brief Set PLMR (Interrupt priority masking).
 * @details Writes a value to the PLMR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PLMR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 14, 2" : : "r" (value) : "memory");
}

/**
 * @brief Get PLMR (Interrupt priority masking).
 * @details Reads the current value of the PLMR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PLMR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 14, %0, 2" : "=r" (result));

    return result;
}

/***********************************************************************************************************************
 *                 FPU Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set FPSR (Floating-point operation configuration/status).
 * @details Writes a value to the FPSR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FPSR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 6, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FPSR (Floating-point operation configuration/status).
 * @details Reads the current value of the FPSR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FPSR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 6, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set FPEPC (Floating-point operation exception program counter).
 * @details Writes a value to the FPEPC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FPEPC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 7, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FPEPC (Floating-point operation exception program counter).
 * @details Reads the current value of the FPEPC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FPEPC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 7, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set FPST (Floating point operation status).
 * @details Writes a value to the FPST system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FPST (uint32_t value)
{
    __ASM volatile ("ldsr %0, 8, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FPST (Floating point operation status).
 * @details Reads the current value of the FPST system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FPST (void)
{
    uint32_t result;

    __ASM volatile ("stsr 8, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set FPCC (Floating-point operation comparison result).
 * @details Writes a value to the FPCC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FPCC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 9, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FPCC (Floating-point operation comparison result).
 * @details Reads the current value of the FPCC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FPCC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 9, %0, 0" : "=r" (result));

    return result;
}

/**
 * @brief Set FPCFG (Floating-point operation configuration).
 * @details Writes a value to the FPCFG system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FPCFG (uint32_t value)
{
    __ASM volatile ("ldsr %0, 10, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FPCFG (Floating-point operation configuration).
 * @details Reads the current value of the FPCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FPCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 10, %0, 0" : "=r" (result));

    return result;
}

#if defined(__RH850_G4KH) && (__RH850_G4KH == 1)

/**
 * @brief Set FPEC (Floating-point exception control).
 * @details Writes a value to the FPEC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FPEC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 11, 0" : : "r" (value) : "memory");
}

/**
 * @brief Get FPEC (Floating-point exception control).
 * @details Reads the current value of the FPEC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FPEC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 11, %0, 0" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4KH) && (__RH850_G4KH == 1) */

/***********************************************************************************************************************
 *                 FXU Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set FXSR (Extended floating-point operation configuration/status).
 * @details Writes a value to the FXSR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FXSR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 6, 10" : : "r" (value) : "memory");
}

/**
 * @brief Get FXSR (Extended floating-point operation configuration/status).
 * @details Reads the current value of the FXSR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FXSR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 6, %0, 10" : "=r" (result));

    return result;
}

/**
 * @brief Set FXST (Extended floating-point operation status).
 * @details Writes a value to the FXST system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FXST (uint32_t value)
{
    __ASM volatile ("ldsr %0, 8, 10" : : "r" (value) : "memory");
}

/**
 * @brief Get FXST (Extended floating-point operation status).
 * @details Reads the current value of the FXST system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FXST (void)
{
    uint32_t result;

    __ASM volatile ("stsr 8, %0, 10" : "=r" (result));

    return result;
}

/**
 * @brief Get FXINFO (FXU configuration information).
 * @details Reads the current value of the FXINFO system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FXINFO (void)
{
    uint32_t result;

    __ASM volatile ("stsr 9, %0, 10" : "=r" (result));

    return result;
}

/* Extended floating-point operation configuration */

/**
 * @brief Set FXCFG (Extended floating-point operation configuration).
 * @details Writes a value to the FXCFG system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FXCFG (uint32_t value)
{
    __ASM volatile ("ldsr %0, 10, 10" : : "r" (value) : "memory");
}

/**
 * @brief Get FXCFG (Extended floating-point operation configuration).
 * @details Reads the current value of the FXCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FXCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 10, %0, 10" : "=r" (result));

    return result;
}

/* XC (cause) bits for each operation way */

/**
 * @brief Set FXXC (XC (cause) bits for each operation way).
 * @details Writes a value to the FXXC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FXXC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 12, 10" : : "r" (value) : "memory");
}

/**
 * @brief Get FXXC (XC (cause) bits for each operation way).
 * @details Reads the current value of the FXXC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FXXC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 12, %0, 10" : "=r" (result));

    return result;
}

/**
 * @brief Set FXXP (XP (preservation) bits for each operation way).
 * @details Writes a value to the FXXP system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_FXXP (uint32_t value)
{
    __ASM volatile ("ldsr %0, 13, 10" : : "r" (value) : "memory");
}

/**
 * @brief Get FXXP (XP (preservation) bits for each operation way).
 * @details Reads the current value of the FXXP system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_FXXP (void)
{
    uint32_t result;

    __ASM volatile ("stsr 13, %0, 10" : "=r" (result));

    return result;
}

/***********************************************************************************************************************
 *                 MPU Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set MPM (Memory protection operation mode setting).
 * @details Writes a value to the MPM system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPM (uint32_t value)
{
    __ASM volatile ("ldsr %0, 0, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPM (Memory protection operation mode setting).
 * @details Reads the current value of the MPM system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPM (void)
{
    uint32_t result;

    __ASM volatile ("stsr 0, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Get MPCFG (MPU configuration).
 * @details Reads the current value of the MPCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 2, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MCA (Memory protection setting check address).
 * @details Writes a value to the MCA system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MCA (uint32_t value)
{
    __ASM volatile ("ldsr %0, 8, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MCA (Memory protection setting check address).
 * @details Reads the current value of the MCA system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MCA (void)
{
    uint32_t result;

    __ASM volatile ("stsr 8, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MCS (Memory protection setting check size).
 * @details Writes a value to the MCS system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MCS (uint32_t value)
{
    __ASM volatile ("ldsr %0, 9, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MCS (Memory protection setting check size).
 * @details Reads the current value of the MCS system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MCS (void)
{
    uint32_t result;

    __ASM volatile ("stsr 9, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MCC (Memory protection setting check command).
 * @details Writes a value to the MCC system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MCC (uint32_t value)
{
    __ASM volatile ("ldsr %0, 10, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MCC (Memory protection setting check command).
 * @details Reads the current value of the MCC system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MCC (void)
{
    uint32_t result;

    __ASM volatile ("stsr 10, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MCR (Memory protection setting check result).
 * @details Writes a value to the MCR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MCR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 11, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MCR (Memory protection setting check result).
 * @details Reads the current value of the MCR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MCR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 11, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MCI (Memory protection setting check SPID).
 * @details Writes a value to the MCI system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MCI (uint32_t value)
{
    __ASM volatile ("ldsr %0, 12, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MCI (Memory protection setting check SPID).
 * @details Reads the current value of the MCI system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MCI (void)
{
    uint32_t result;

    __ASM volatile ("stsr 12, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPIDX (Index of memory protection setting registers to be accessed).
 * @details Writes a value to the MPIDX system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPIDX (uint32_t value)
{
    __ASM volatile ("ldsr %0, 16, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPIDX (Index of memory protection setting registers to be accessed).
 * @details Reads the current value of the MPIDX system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPIDX (void)
{
    uint32_t result;

    __ASM volatile ("stsr 16, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPBK (MPU Bank Setting).
 * @details Writes a value to the MPBK system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPBK (uint32_t value)
{
    __ASM volatile ("ldsr %0, 17, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPBK (MPU Bank Setting).
 * @details Reads the current value of the MPBK system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPBK (void)
{
    uint32_t result;

    __ASM volatile ("stsr 17, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPLA (Protection area minimum address).
 * @details Writes a value to the MPLA system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPLA (uint32_t value)
{
    __ASM volatile ("ldsr %0, 20, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPLA (Protection area minimum address).
 * @details Reads the current value of the MPLA system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPLA (void)
{
    uint32_t result;

    __ASM volatile ("stsr 20, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPUA (Protection area maximum address).
 * @details Writes a value to the MPUA system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPUA (uint32_t value)
{
    __ASM volatile ("ldsr %0, 21, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPUA (Protection area maximum address).
 * @details Reads the current value of the MPUA system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPUA (void)
{
    uint32_t result;

    __ASM volatile ("stsr 21, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPAT (Protection area attribute).
 * @details Writes a value to the MPAT system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPAT (uint32_t value)
{
    __ASM volatile ("ldsr %0, 22, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPAT (Protection area attribute).
 * @details Reads the current value of the MPAT system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPAT (void)
{
    uint32_t result;

    __ASM volatile ("stsr 22, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPID0 (SPID which can access protection area).
 * @details Writes a value to the MPID0 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPID0 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 24, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPID0 (SPID which can access protection area).
 * @details Reads the current value of the MPID0 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPID0 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 24, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPID1 (SPID which can access protection area).
 * @details Writes a value to the MPID1 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPID1 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 25, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPID1 (SPID which can access protection area).
 * @details Reads the current value of the MPID1 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPID1 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 25, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPID2 (SPID which can access protection area).
 * @details Writes a value to the MPID2 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPID2 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 26, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPID2 (SPID which can access protection area).
 * @details Reads the current value of the MPID2 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPID2 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 26, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPID3 (SPID which can access protection area).
 * @details Writes a value to the MPID3 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPID3 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 27, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPID3 (SPID which can access protection area).
 * @details Reads the current value of the MPID3 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPID3 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 27, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPID4 (SPID which can access protection area).
 * @details Writes a value to the MPID4 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPID4 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 28, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPID4 (SPID which can access protection area).
 * @details Reads the current value of the MPID4 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPID4 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 28, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPID5 (SPID which can access protection area).
 * @details Writes a value to the MPID5 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPID5 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 29, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPID5 (SPID which can access protection area).
 * @details Reads the current value of the MPID5 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPID5 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 29, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPID6 (SPID which can access protection area).
 * @details Writes a value to the MPID6 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPID6 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 30, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPID6 (SPID which can access protection area).
 * @details Reads the current value of the MPID6 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPID6 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 30, %0, 5" : "=r" (result));

    return result;
}

/**
 * @brief Set MPID7 (SPID which can access protection area).
 * @details Writes a value to the MPID7 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_MPID7 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 31, 5" : : "r" (value) : "memory");
}

/**
 * @brief Get MPID7 (SPID which can access protection area).
 * @details Reads the current value of the MPID7 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_MPID7 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 31, %0, 5" : "=r" (result));

    return result;
}

/***********************************************************************************************************************
 *                 Cache Operation Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set ICTAGL (Instruction cache tag Lo access).
 * @details Writes a value to the ICTAGL system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_ICTAGL (uint32_t value)
{
    __ASM volatile ("ldsr %0, 16, 4" : : "r" (value) : "memory");
}

/**
 * @brief Get ICTAGL (Instruction cache tag Lo access).
 * @details Reads the current value of the ICTAGL system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_ICTAGL (void)
{
    uint32_t result;

    __ASM volatile ("stsr 16, %0, 4" : "=r" (result));

    return result;
}

/**
 * @brief Set ICTAGH (Instruction cache tag Hi access).
 * @details Writes a value to the ICTAGH system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_ICTAGH (uint32_t value)
{
    __ASM volatile ("ldsr %0, 17, 4" : : "r" (value) : "memory");
}

/**
 * @brief Get ICTAGH (Instruction cache tag Hi access).
 * @details Reads the current value of the ICTAGH system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_ICTAGH (void)
{
    uint32_t result;

    __ASM volatile ("stsr 17, %0, 4" : "=r" (result));

    return result;
}

/**
 * @brief Set ICDATL (Instruction cache data Lo access).
 * @details Writes a value to the ICDATL system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_ICDATL (uint32_t value)
{
    __ASM volatile ("ldsr %0, 18, 4" : : "r" (value) : "memory");
}

/**
 * @brief Get ICDATL (Instruction cache data Lo access).
 * @details Reads the current value of the ICDATL system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_ICDATL (void)
{
    uint32_t result;

    __ASM volatile ("stsr 18, %0, 4" : "=r" (result));

    return result;
}

/**
 * @brief Set ICDATH (Instruction cache data Hi access).
 * @details Writes a value to the ICDATH system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_ICDATH (uint32_t value)
{
    __ASM volatile ("ldsr %0, 19, 4" : : "r" (value) : "memory");
}

/**
 * @brief Get ICDATH (Instruction cache data Hi access).
 * @details Reads the current value of the ICDATH system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_ICDATH (void)
{
    uint32_t result;

    __ASM volatile ("stsr 19, %0, 4" : "=r" (result));

    return result;
}

/**
 * @brief Set ICCTRL (Instruction cache control).
 * @details Writes a value to the ICCTRL system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_ICCTRL (uint32_t value)
{
    __ASM volatile ("ldsr %0, 24, 4" : : "r" (value) : "memory");
}

/**
 * @brief Get ICCTRL (Instruction cache control).
 * @details Reads the current value of the ICCTRL system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_ICCTRL (void)
{
    uint32_t result;

    __ASM volatile ("stsr 24, %0, 4" : "=r" (result));

    return result;
}

/**
 * @brief Get ICCFG (Instruction cache configuration).
 * @details Reads the current value of the ICCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_ICCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 26, %0, 4" : "=r" (result));

    return result;
}

/**
 * @brief Set ICERR (Instruction cache error).
 * @details Writes a value to the ICERR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_ICERR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 28, 4" : : "r" (value) : "memory");
}

/**
 * @brief Get ICERR (Instruction cache error).
 * @details Reads the current value of the ICERR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_ICERR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 28, %0, 4" : "=r" (result));

    return result;
}

/***********************************************************************************************************************
 *                 Basic System Registers
 **********************************************************************************************************************/

/**
 * @brief Set TSCOUNTL (Timestamp count L register).
 * @details Writes a value to the TSCOUNTL system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_TSCOUNTL (uint32_t value)
{
    __ASM volatile ("ldsr %0, 0, 11" : : "r" (value) : "memory");
}

/**
 * @brief Get TSCOUNTL (Timestamp count L register).
 * @details Reads the current value of the TSCOUNTL system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_TSCOUNTL (void)
{
    uint32_t result;

    __ASM volatile ("stsr 0, %0, 11" : "=r" (result));

    return result;
}

/**
 * @brief Set TSCOUNTH (Timestamp count H register).
 * @details Writes a value to the TSCOUNTH system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_TSCOUNTH (uint32_t value)
{
    __ASM volatile ("ldsr %0, 1, 11" : : "r" (value) : "memory");
}

/**
 * @brief Get TSCOUNTH (Timestamp count H register).
 * @details Reads the current value of the TSCOUNTH system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_TSCOUNTH (void)
{
    uint32_t result;

    __ASM volatile ("stsr 1, %0, 11" : "=r" (result));

    return result;
}

/**
 * @brief Set TSCTRL (Timestamp count control register).
 * @details Writes a value to the TSCTRL system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_TSCTRL (uint32_t value)
{
    __ASM volatile ("ldsr %0, 2, 11" : : "r" (value) : "memory");
}

/**
 * @brief Get TSCTRL (Timestamp count control register).
 * @details Reads the current value of the TSCTRL system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_TSCTRL (void)
{
    uint32_t result;

    __ASM volatile ("stsr 2, %0, 11" : "=r" (result));

    return result;
}

/**
 * @brief Set PMUMCTRL (Performance counter User mode control register).
 * @details Writes a value to the PMUMCTRL system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMUMCTRL (uint32_t value)
{
    __ASM volatile ("ldsr %0, 8, 11" : : "r" (value) : "memory");
}

/**
 * @brief Get PMUMCTRL (Performance counter User mode control register).
 * @details Reads the current value of the PMUMCTRL system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMUMCTRL (void)
{
    uint32_t result;

    __ASM volatile ("stsr 8, %0, 11" : "=r" (result));

    return result;
}

/**
 * @brief Set PMCTRL0 (Performance count control 0 register).
 * @details Writes a value to the PMCTRL0 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCTRL0 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("ldsr %0, 0, 14" : : "r" (value) : "memory");
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("ldsr %0, 17, 11" : : "r" (value) : "memory");
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCTRL0 (Performance count control 0 register).
 * @details Reads the current value of the PMCTRL0 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCTRL0 (void)
{
    uint32_t result;

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("stsr 0, %0, 14" : "=r" (result));
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("stsr 17, %0, 11" : "=r" (result));
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
    return result;
}

/**
 * @brief Set PMCTRL1 (Performance count control 1 register).
 * @details Writes a value to the PMCTRL1 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCTRL1 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("ldsr %0, 1, 14" : : "r" (value) : "memory");
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("ldsr %0, 19, 11" : : "r" (value) : "memory");
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCTRL1 (Performance count control 1 register).
 * @details Reads the current value of the PMCTRL1 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCTRL1 (void)
{
    uint32_t result;

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("stsr 1, %0, 14" : "=r" (result));
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("stsr 19, %0, 11" : "=r" (result));
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
    return result;
}

/**
 * @brief Set PMCTRL2 (Performance count control 2 register).
 * @details Writes a value to the PMCTRL2 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCTRL2 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("ldsr %0, 2, 14" : : "r" (value) : "memory");
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("ldsr %0, 21, 11" : : "r" (value) : "memory");
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCTRL2 (Performance count control 2 register).
 * @details Reads the current value of the PMCTRL2 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCTRL2 (void)
{
    uint32_t result;

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("stsr 2, %0, 14" : "=r" (result));
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("stsr 21, %0, 11" : "=r" (result));
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
    return result;
}

/**
 * @brief Set PMCTRL3 (Performance count control 3 register).
 * @details Writes a value to the PMCTRL3 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCTRL3 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("ldsr %0, 3, 14" : : "r" (value) : "memory");
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("ldsr %0, 23, 11" : : "r" (value) : "memory");
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCTRL3 (Performance count control 3 register).
 * @details Reads the current value of the PMCTRL3 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCTRL3 (void)
{
    uint32_t result;

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("stsr 3, %0, 14" : "=r" (result));
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("stsr 23, %0, 11" : "=r" (result));
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
    return result;
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCTRL4 (Performance count control 4 register).
 * @details Writes a value to the PMCTRL4 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCTRL4 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 4, 14" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCTRL4 (Performance count control 4 register).
 * @details Reads the current value of the PMCTRL4 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCTRL4 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 4, %0, 14" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCTRL5 (Performance count control 5 register).
 * @details Writes a value to the PMCTRL5 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCTRL5 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 5, 14" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCTRL5 (Performance count control 5 register).
 * @details Reads the current value of the PMCTRL5 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCTRL5 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 5, %0, 14" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCTRL6 (Performance count control 6 register).
 * @details Writes a value to the PMCTRL6 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCTRL6 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 6, 14" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCTRL6 (Performance count control 6 register).
 * @details Reads the current value of the PMCTRL6 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCTRL6 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 6, %0, 14" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCTRL7 (Performance count control 7 register).
 * @details Writes a value to the PMCTRL7 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCTRL7 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 7, 14" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCTRL7 (Performance count control 7 register).
 * @details Reads the current value of the PMCTRL7 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCTRL7 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 7, %0, 14" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief Set PMCOUNT0 (Performance count 0 register).
 * @details Writes a value to the PMCOUNT0 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCOUNT0 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("ldsr %0, 16, 14" : : "r" (value) : "memory");
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("ldsr %0, 16, 11" : : "r" (value) : "memory");
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCOUNT0 (Performance count 0 register).
 * @details Reads the current value of the PMCOUNT0 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCOUNT0 (void)
{
    uint32_t result;

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("stsr 16, %0, 14" : "=r" (result));
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("stsr 16, %0, 11" : "=r" (result));
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
    return result;
}

/**
 * @brief Set PMCOUNT1 (Performance count 1 register).
 * @details Writes a value to the PMCOUNT1 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCOUNT1 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("ldsr %0, 17, 14" : : "r" (value) : "memory");
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("ldsr %0, 18, 11" : : "r" (value) : "memory");
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCOUNT1 (Performance count 1 register).
 * @details Reads the current value of the PMCOUNT1 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCOUNT1 (void)
{
    uint32_t result;

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("stsr 17, %0, 14" : "=r" (result));
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("stsr 18, %0, 11" : "=r" (result));
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
    return result;
}

/**
 * @brief Set PMCOUNT2 (Performance count 2 register).
 * @details Writes a value to the PMCOUNT2 system register.
 * @param[in] value uint32_t input.
 */

/* Performance count 2 register */
__STATIC_FORCEINLINE void __set_PMCOUNT2 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("ldsr %0, 18, 14" : : "r" (value) : "memory");
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("ldsr %0, 20, 11" : : "r" (value) : "memory");
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCOUNT2 (Performance count 2 register).
 * @details Reads the current value of the PMCOUNT2 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCOUNT2 (void)
{
    uint32_t result;

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("stsr 18, %0, 14" : "=r" (result));
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("stsr 20, %0, 11" : "=r" (result));
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
    return result;
}

/**
 * @brief Set PMCOUNT3 (Performance count 3 register).
 * @details Writes a value to the PMCOUNT3 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCOUNT3 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("ldsr %0, 19, 14" : : "r" (value) : "memory");
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("ldsr %0, 22, 11" : : "r" (value) : "memory");
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCOUNT3 (Performance count 3 register).
 * @details Reads the current value of the PMCOUNT3 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCOUNT3 (void)
{
    uint32_t result;

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    __ASM volatile ("stsr 19, %0, 14" : "=r" (result));
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    __ASM volatile ("stsr 22, %0, 11" : "=r" (result));
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
    return result;
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCOUNT4 (Performance count 4 register).
 * @details Writes a value to the PMCOUNT4 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCOUNT4 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 20, 14" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCOUNT4 (Performance count 4 register).
 * @details Reads the current value of the PMCOUNT4 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCOUNT4 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 20, %0, 14" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCOUNT5 (Performance count 5 register).
 * @details Writes a value to the PMCOUNT5 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCOUNT5 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 21, 14" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCOUNT5 (Performance count 5 register).
 * @details Reads the current value of the PMCOUNT5 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCOUNT5 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 21, %0, 14" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCOUNT6 (Performance count 6 register).
 * @details Writes a value to the PMCOUNT6 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCOUNT6 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 22, 14" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCOUNT6 (Performance count 6 register).
 * @details Reads the current value of the PMCOUNT6 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCOUNT6 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 22, %0, 14" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCOUNT7 (Performance count 7 register).
 * @details Writes a value to the PMCOUNT7 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMCOUNT7 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 23, 14" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCOUNT7 (Performance count 7 register).
 * @details Reads the current value of the PMCOUNT7 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMCOUNT7 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 23, %0, 14" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND0 (Performance count subcondition 0 register).
 * @details Writes a value to the PMSUBCND0 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMSUBCND0 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 0, 15" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND0 (Performance count subcondition 0 register).
 * @details Reads the current value of the PMSUBCND0 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMSUBCND0 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 0, %0, 15" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND1 (Performance count subcondition 1 register).
 * @details Writes a value to the PMSUBCND1 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMSUBCND1 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 1, 15" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND1 (Performance count subcondition 1 register).
 * @details Reads the current value of the PMSUBCND1 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMSUBCND1 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 1, %0, 15" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND2 (Performance count subcondition 2 register).
 * @details Writes a value to the PMSUBCND2 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMSUBCND2 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 2, 15" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND2 (Performance count subcondition 2 register).
 * @details Reads the current value of the PMSUBCND2 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMSUBCND2 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 2, %0, 15" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND3 (Performance count subcondition 3 register).
 * @details Writes a value to the PMSUBCND3 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMSUBCND3 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 3, 15" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND3 (Performance count subcondition 3 register).
 * @details Reads the current value of the PMSUBCND3 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMSUBCND3 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 3, %0, 15" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND4 (Performance count subcondition 4 register).
 * @details Writes a value to the PMSUBCND4 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMSUBCND4 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 4, 15" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND4 (Performance count subcondition 4 register).
 * @details Reads the current value of the PMSUBCND4 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMSUBCND4 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 4, %0, 15" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND5 (Performance count subcondition 5 register).
 * @details Writes a value to the PMSUBCND5 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMSUBCND5 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 5, 15" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND5 (Performance count subcondition 5 register).
 * @details Reads the current value of the PMSUBCND5 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMSUBCND5 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 5, %0, 15" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND6 (Performance count subcondition 6 register).
 * @details Writes a value to the PMSUBCND6 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMSUBCND6 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 6, 15 \n" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND6 (Performance count subcondition 6 register).
 * @details Reads the current value of the PMSUBCND6 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMSUBCND6 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 6, %0, 15 \n" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND7 (Performance count subcondition 7 register).
 * @details Writes a value to the PMSUBCND7 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_PMSUBCND7 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 7, 15 \n" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND7 (Performance count subcondition 7 register).
 * @details Reads the current value of the PMSUBCND7 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_PMSUBCND7 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 7, %0, 15 \n" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/***********************************************************************************************************************
 *                 Hardware Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set LSTEST0 (Lock-step function self-diagnosis register 0).
 * @details Writes a value to the LSTEST0 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_LSTEST0 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 0, 12 \n" : : "r" (value) : "memory");
}

/**
 * @brief Get LSTEST0 (Lock-step function self-diagnosis register 0).
 * @details Reads the current value of the LSTEST0 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_LSTEST0 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 0, %0, 12 \n" : "=r" (result));

    return result;
}

/**
 * @brief Set LSTEST1 (Lock-step function self-diagnosis register 1).
 * @details Writes a value to the LSTEST1 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_LSTEST1 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 1, 12 \n" : : "r" (value) : "memory");
}

/**
 * @brief Get LSTEST1 (Lock-step function self-diagnosis register 1).
 * @details Reads the current value of the LSTEST1 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_LSTEST1 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 1, %0, 12 \n" : "=r" (result));

    return result;
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get LSCFG (Lock-step function configuration).
 * @details Reads the current value of the LSCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_LSCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 2, %0, 12 \n" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set IFCR (Instruction fetch control register).
 * @details Writes a value to the IFCR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_IFCR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 5, 12 \n" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get IFCR (Instruction fetch control register).
 * @details Reads the current value of the IFCR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_IFCR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 5, %0, 12 \n" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set BRPCTRL0 (Branch prediction function control register).
 * @details Writes a value to the BRPCTRL0 system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_BRPCTRL0 (uint32_t value)
{
    __ASM volatile ("ldsr %0, 8, 12 \n" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get BRPCTRL0 (Branch prediction function control register).
 * @details Reads the current value of the BRPCTRL0 system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_BRPCTRL0 (void)
{
    uint32_t result;

    __ASM volatile ("stsr 8, %0, 12 \n" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get L1RCFG (L1RAM configuration).
 * @details Reads the current value of the L1RCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_L1RCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 12, %0, 13 \n" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set RDBCR (ROM data buffer control register).
 * @details Writes a value to the RDBCR system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_RDBCR (uint32_t value)
{
    __ASM volatile ("ldsr %0, 24, 13 \n" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get RDBCR (ROM data buffer control register).
 * @details Reads the current value of the RDBCR system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_RDBCR (void)
{
    uint32_t result;

    __ASM volatile ("stsr 24, %0, 13 \n" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/***********************************************************************************************************************
 *                 Virtualization Support Function System Registers
 **********************************************************************************************************************/

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set HVCFG (Setting virtualization support function).
 * @details Writes a value to the HVCFG system register.
 * @param[in] value uint32_t input.
 */
__STATIC_FORCEINLINE void __set_HVCFG (uint32_t value)
{
    __ASM volatile ("ldsr %0, 16, 1 \n" : : "r" (value) : "memory");
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get HVCFG (Setting virtualization support function).
 * @details Reads the current value of the HVCFG system register.
 * @return uint32_t register value.
 *
 */
__STATIC_FORCEINLINE uint32_t __get_HVCFG (void)
{
    uint32_t result;

    __ASM volatile ("stsr 16, %0, 1 \n" : "=r" (result));

    return result;
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/** @} end of group IAR_RH850_Core_RegAccFunctions */

/** @} end of group RH850_Core_FunctionInterface */

/* Include the profile specific settings: */
#include "G4-profile/rh850_iar_g4.h"

#endif                                 /* __RH850_IAR_H */
