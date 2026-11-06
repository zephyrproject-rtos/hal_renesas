/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_ccrh.h
 * @brief    RH850 compiler CCRH header file
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#ifndef __RH850_CCRH_H
#define __RH850_CCRH_H

/* RH850 compiler specific defines */
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
 #define __NO_RETURN
#endif
#ifndef   RH850_DEPRECATED
 #define RH850_DEPRECATED
#endif
#ifndef   RH850_UNSUPPORTED
 #define RH850_UNSUPPORTED    0
#endif
#ifndef   __USED
 #define __USED
#endif
#ifndef   __WEAK
 #define __WEAK
#endif
#ifndef   __PACKED
 #define __PACKED
#endif
#ifndef   __PACKED_STRUCT
 #define __PACKED_STRUCT
#endif
#ifndef   __PACKED_UNION
 #define __PACKED_UNION
#endif
#ifndef   __UNALIGNED_UINT16_WRITE
 #define __UNALIGNED_UINT16_WRITE(addr, val)
#endif
#ifndef   __UNALIGNED_UINT16_READ
 #define __UNALIGNED_UINT16_READ(addr)
#endif
#ifndef   __UNALIGNED_UINT32_WRITE
 #define __UNALIGNED_UINT32_WRITE(addr, val)
#endif
#ifndef   __UNALIGNED_UINT32_READ
 #define __UNALIGNED_UINT32_READ(addr)
#endif
#ifndef   __ALIGNED
 #define __ALIGNED(x)    __attribute__((aligned(x)))
#endif
#ifndef   __RESTRICT
 #define __RESTRICT
#endif
#ifndef   __COMPILER_BARRIER
 #define __COMPILER_BARRIER()
#endif
#ifndef __NO_INIT
 #define __NO_INIT    __attribute__((section(".noinit")))
#endif
#ifndef __ALIAS
 #define __ALIAS(x)
#endif

/* Convert token into a string and pass it to _Pragma */
#ifndef   __PRAGMA_HELPER
 #define __PRAGMA_HELPER(x)                      _Pragma(#x)
#endif

/* Create the pragma inline statement with the function name as argument */
#ifndef __PRAGMA_PLACE_IN_SECTION
 #define __PRAGMA_PLACE_IN_SECTION(sec, name)    __PRAGMA_HELPER(section name)
#endif
#ifndef   __FORCEINLINE
 #define __FORCEINLINE(Func_Name)                __PRAGMA_HELPER(inline Func_Name)
#endif
#ifndef   __FORCEINLINE_ASM
 #define __FORCEINLINE_ASM(Func_Name)            __PRAGMA_HELPER(inline_asm Func_Name)
#endif

/* ##########################################  Core Instruction Access  ############################################# */

/** @defgroup RH850_Core_InstructionInterface RH850-Core Instruction Interface
 * @brief Access to dedicated instructions
 * @{
 */

/** @ingroup  RH850_Core_InstructionInterface
 *  @defgroup CCRH_RH850_Core_InstructionInterface CCRH RH850-Core Instruction Interface
 *  @brief CCRH RH850-Core Instruction Interface
 * @{
 */

/********************************************* ARM INTRINSIC **********************************************************/

/**
 * @brief   Instruction Synchronization Barrier
 * @details Instruction Synchronization Barrier flushes the pipeline in the processor,
 *         so that all instructions following the ISB are fetched from cache or memory,
 *         after the instruction has been completed.
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __ISB()           __synci()

/**
 * @brief   Data Synchronization Barrier
 * @details Acts as a special kind of Data Memory Barrier.
 *         It completes when all explicit memory accesses before this instruction complete.
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __DSB()           __syncp()

/**
 * @brief   Data Memory Barrier
 * @details Ensures the apparent order of the explicit memory operations before
 *         and after the instruction, without ensuring their completion.
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __DMB()           __syncm()

/**
 * @brief   Reverse byte order (32 bit)
 * @details Reverses the byte order in unsigned integer value. For example, 0x12345678 becomes 0x78563412.
 * @param [in]    value  Value to reverse
 * @return               Reversed value
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __REV(value)      __bsw(value)

/**
 * @brief   Reverse byte order (16 bit)
 * @details Reverses the byte order within each halfword of a word. For example, 0x12345678 becomes 0x34127856.
 * @param [in]    value  Value to reverse
 * @return               Reversed value
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __REV16(value)    __bsh(value)

/**
 * @brief   Reverse byte order (16 bit)
 * @details Reverses the byte order in a 16-bit value and returns the signed 16-bit result. For example, 0x0080 becomes 0x8000.
 * @param [in]    value  Value to reverse
 * @return               Reversed value
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __REVSH(value)    ((int16_t) __bsh(value))

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
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
__STATIC_FORCEINLINE uint32_t __CLZ (uint32_t value)
{
    const int32_t pos = __sch1l((long) value);

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
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __CLREX
static void __CLREX (void)
{
    cll;                               // Clear Load Link
}

/**
 * @brief   LDR Exclusive (8 bit)
 * @details Executes a exclusive LDR instruction for 8 bit value.
 * @param [in]    addr  Pointer to data
 * @return             value of type uint8_t at (*ptr)
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __LDREXB(addr)           __ldlbu((unsigned char *) addr)

/**
 * @brief   STR Exclusive (8 bit)
 * @details Executes a exclusive STR instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __STREXB(value, addr)    (!__stcb((unsigned char *) addr, (unsigned char) value))

/**
 * @brief   LDR Exclusive (16 bit)
 * @details Executes a exclusive LDR instruction for 16 bit values.
 * @param [in]    addr  Pointer to data
 * @return        value of type uint16_t at (*ptr)
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __LDREXH(addr)           __ldlhu((unsigned short *) addr)

/**
 * @brief   STR Exclusive (16 bit)
 * @details Executes a exclusive STR instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __STREXH(value, addr)    (!__stch((unsigned short *) addr, (unsigned short) value))

/**
 * @brief   LDR Exclusive (32 bit)
 * @details Executes a exclusive LDR instruction for 32 bit values.
 * @param [in]    addr  Pointer to data
 * @return        value of type uint32_t at (*ptr)
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __LDREXW(addr)           __ldlw((long *) addr)

/**
 * @brief   STR Exclusive (32 bit)
 * @details Executes a exclusive STR instruction for 32 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#define __STREXW(value, addr)    (!__stcw((long *) addr, (long) value))

/**
 * @brief   Rotate Right with Extend (32 bit)
 * @details Moves each bit of a bitstring right by one bit.
 *         The carry input is shifted in at the left end of the bitstring.
 * @param [in]    value  Value to rotate
 * @return               Rotated value
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __RRX
static uint32_t __RRX (uint32_t value)
{
    ;                                  // rrx32: r10 = (CY << 31) | (r6 >> 1)
    ;                                  // - Input  : r6
    ;                                  // - Output : r10 = result
    ;                                  // Note: PSW is system register #5; CY is bit3 (PSW[3])

    ;                                  // Get current CY from PSW and expand it to MSB mask (CY<<31)
    stsr    5, r11, 0;                 // r11 <- PSW
    shr     3, r11;                    // r11.bit0 = CY
    andi    1, r11, r11;               // r11 = CY (0 or 1)
    shl     31, r11;                   // r11 = CY << 31

    ;                                  // Shift operand and inject CY into MSB
    mov r6, r10;
    shr     1, r10;                    // r10 = r6 >> 1
    or r11, r10;                       // r10 = (CY<<31) | (r6>>1)

    ;                                  // Compute new CY from old LSB of r6: newCY_mask = (r6 & 1) << 3
    mov r6, r12;
    andi    1, r12, r12;               // r12 = old LSB of r6 (0 or 1)
    shl     3, r12;                    // r12 = newCY_mask (0x0 or 0x8)

    ;                                  // Read PSW, clear CY bit, then set according to newCY_mask
    stsr    5, r13, 0;                 // r13 <- PSW

    ;                                  // Clear-mask (~0x8)
    movhi   0xFFFF, r0, r11;           // r11 = 0xFFFF0000
    ori     0xFFF7, r11, r11;          // r11 = 0xFFFF0000 + 0xFFF7 = 0xFFFFFFF7
    and r11, r13;                      // r13 &= ~0x8  (clear PSW.CY)
    or  r12, r13;                      // r13 |= newCY_mask

    ;                                  // Write PSW back
    ldsr r13, 5, 0;                    // PSW <- r13
}

/**
 * @brief   Load-Acquire (8 bit)
 * @details Executes a LDAB instruction for 8 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type uint8_t at (*ptr)
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __LDAB
static uint8_t __LDAB (volatile uint8_t * ptr)
{
    ld.bu   0[r6], r10
    synce
}

/**
 * @brief   Load-Acquire (16 bit)
 * @details Executes a LDAH instruction for 16 bit values.
 * @param [in]    ptr  Pointer to data
 * @return        value of type uint16_t at (*ptr)
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __LDAH
static uint16_t __LDAH (volatile uint16_t * ptr)
{
    ld.hu   0[r6], r10
    synce
}

/**
 * @brief   Load-Acquire (32 bit)
 * @details Executes a LDA instruction for 32 bit values.
 * @param [in]    ptr  Pointer to data
 * @return        value of type uint32_t at (*ptr)
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __LDA
static uint32_t __LDA (volatile uint32_t * ptr)
{
    ld.w    0[r6], r10
    synce
}

/**
 * @brief   Store-Release (8 bit)
 * @details Executes a STLB instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __STLB
static void __STLB (uint8_t value, volatile uint8_t * ptr)
{
    synce
    st.b r6, 0[r7]
}

/**
 * @brief   Store-Release (16 bit)
 * @details Executes a STLH instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __STLH
static void __STLH (uint16_t value, volatile uint16_t * ptr)
{
    synce
    st.h r6, 0[r7]
}

/**
 * @brief   Store-Release (32 bit)
 * @details Executes a STL instruction for 32 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __STL
static void __STL (uint32_t value, volatile uint32_t * ptr)
{
    synce
    st.w r6, 0[r7]
}

/**
 * @brief   Load-Acquire Exclusive (8 bit)
 * @details Executes a LDAB exclusive instruction for 8 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type uint8_t at (*ptr)
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __LDAEXB
static uint8_t __LDAEXB (volatile uint8_t * ptr)
{
    ldl.bu[r6], r10
    synce
}

/**
 * @brief   Load-Acquire Exclusive (16 bit)
 * @details Executes a LDAH exclusive instruction for 16 bit values.
 * @param [in]    ptr  Pointer to data
 * @return        value of type uint16_t at (*ptr)
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __LDAEXH
static uint16_t __LDAEXH (volatile uint16_t * ptr)
{
    ldl.hu[r6], r10
    synce
}

/**
 * @brief   Load-Acquire Exclusive (32 bit)
 * @details Executes a LDA exclusive instruction for 32 bit values.
 * @param [in]    ptr  Pointer to data
 * @return        value of type uint32_t at (*ptr)
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __LDAEX
static uint32_t __LDAEX (volatile uint32_t * ptr)
{
    ldl.w[r6], r10
    synce
}

/**
 * @brief   Store-Release Exclusive (8 bit)
 * @details Executes a STLB exclusive instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __STLEXB
static uint32_t __STLEXB (uint8_t value, volatile uint8_t * ptr)
{
    synce
    stc.b r6, [r7]
    mov 1, r10
    xor r6, r10
}

/**
 * @brief   Store-Release Exclusive (16 bit)
 * @details Executes a STLH exclusive instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __STLEXH
static uint32_t __STLEXH (uint16_t value, volatile uint16_t * ptr)
{
    synce
    stc.h r6, [r7]
    mov 1, r10
    xor r6, r10
}

/**
 * @brief   Store-Release Exclusive (32 bit)
 * @details Executes a STL exclusive instruction for 32 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 * @note    Keep CMSIS function name and ensure identical behavior on RH850.
 */
#pragma inline_asm __STLEX
static uint32_t __STLEX (uint32_t value, volatile uint32_t * ptr)
{
    synce
    stc.w r6, [r7]
    mov 1, r10
    xor r6, r10
}

/********************************************* RH850 INTRINSIC ********************************************************/

/* Load Instructions */

/**
 * @brief   Load byte
 * @details Executes a LD.B instruction for 8 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type int8_t at (*ptr)
 */
#pragma inline_asm __LDB
static int8_t __LDB (volatile int8_t * ptr)
{
    ld.b   0[r6], r10
}

/**
 * @brief   Load byte unsigned
 * @details Executes a LD.BU instruction for 8 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type uint8_t at (*ptr)
 */
#pragma inline_asm __LDBU
static uint8_t __LDBU (volatile uint8_t * ptr)
{
    ld.bu   0[r6], r10
}

/**
 * @brief   Load halfword
 * @details Executes a LD.H instruction for 16 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type int16_t at (*ptr)
 */
#pragma inline_asm __LDH
static int16_t __LDH (volatile int16_t * ptr)
{
    ld.h   0[r6], r10
}

/**
 * @brief   Load halfword unsigned
 * @details Executes a LD.HU instruction for 16 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type uint16_t at (*ptr)
 */
#pragma inline_asm __LDHU
static uint16_t __LDHU (volatile uint16_t * ptr)
{
    ld.hu   0[r6], r10
}

/**
 * @brief   Load word
 * @details Executes a LD.W instruction for 32 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type int32_t at (*ptr)
 */
#pragma inline_asm __LDW
static int32_t __LDW (volatile int32_t * ptr)
{
    ld.w   0[r6], r10
}

/**
 * @brief   Load double word
 * @details Executes a LD.DW instruction for 64 bit value.
 * @param [in]    ptr  Pointer to data
 * @return             value of type int32_t at (*ptr)
 */
#pragma inline_asm __LDDW
static int64_t __LDDW (volatile int64_t * ptr)
{
    ld.dw   0[r6], r10
}

/* Store Instructions */

/**
 * @brief   Store byte
 * @details Executes a ST.B instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 */
#pragma inline_asm __STB
static void __STB (int8_t value, volatile int8_t * ptr)
{
    st.b r6, 0[r7]
}

/**
 * @brief   Store halfword
 * @details Executes a ST.H instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 */
#pragma inline_asm __STH
static void __STH (int16_t value, volatile int16_t * ptr)
{
    st.h r6, 0[r7]
}

/**
 * @brief   Store word
 * @details Executes a ST.W instruction for 32 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 */
#pragma inline_asm __STW
static void __STW (int32_t value, volatile int32_t * ptr)
{
    st.w r6, 0[r7]
}

/**
 * @brief   Store double word
 * @details Executes a ST.DW instruction for 64 bit values.
 * @param [in]  value  Value to store
 * @param [in]    ptr  Pointer to location
 */
#pragma inline_asm __STDW
static void __STDW (int64_t value, volatile int64_t * ptr)
{
    st.dw r6, 0[r8]
}

/* Multiply Instructions */

/**
 * @brief   Multiplication of (signed) word data
 * @details Assigns higher 32 bits of signed 64-bit multiplication result.
 * @param [in]    a   First operand
 * @param [in]    b   Second operand
 * @return             High 32 bits of result
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __MUL(a, b)        __mul32((long) a, (long) b)

/**
 * @brief   Signed 64-bit multiplication high 32 bits
 * @details Assigns higher 32 bits of signed 64-bit multiplication result.
 * @param [in]    a   First operand
 * @param [in]    b   Second operand
 * @return             High 32 bits of result
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __MULU(a, b)       __mul32u((long) a, (long) b)

/**
 * @brief   Saturated addition
 * @details Performs saturated addition of two signed integers.
 * @param [in]    a   First operand
 * @param [in]    b   Second operand
 * @return             Result of saturated addition
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __SATADD(a, b)     __satadd((long) a, (long) b)

/**
 * @brief   Saturated subtraction
 * @details Performs saturated subtraction of two signed integers.
 * @param [in]    a   First operand
 * @param [in]    b   Second operand
 * @return             Result of saturated subtraction
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __SATSUB(a, b)     __satsub((long) a, (long) b)

/**
 * @brief   Halfword data byte swap
 * @details Swaps bytes within a 16-bit halfword.
 * @param [in]    value   Value to swap
 * @return                Swapped value
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __BSH(value)       __bsh((long) value)

/**
 * @brief   Word data byte swap
 * @details Swaps bytes within a 32-bit word.
 * @param [in]    value   Value to swap
 * @return                Swapped value
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __BSW(value)       __bsw((long) value)

/**
 * @brief   Signed data conversion from word to byte with saturation
 * @details Conversion of signed word data to byte data with saturation
 * @param [in]    value   Data conversion
 * @return             Data in byte with saturation
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __CLIPB(value)     __clipb((long) value)

/**
 * @brief   Unsigned data conversion from word to byte with saturation
 * @details Conversion of unsigned word data to byte data with saturation
 * @param [in]    value   Data conversion
 * @return             Data in byte with saturation
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __CLIPBU(value)    __clipbu((unsigned long) value)

/**
 * @brief   Signed data conversion from word to halfword with saturation
 * @details Conversion of unsigned word data to byte data with saturation
 * @param [in]    value   Data conversion
 * @return             Data in haflword with saturation
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __CLIPH(value)     __cliph((long) value)

/**
 * @brief   Unsigned data conversion from word to halfword with saturation
 * @details Conversion of unsigned word data to halfword data with saturation
 * @param [in]    value   Data conversion
 * @return             Data in haflword with saturation
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __CLIPHU(value)    __cliphu((unsigned long) value)

/**
 * @brief   Halfword swap halfword
 * @details Swaps halfwords within a 16-bit word.
 * @param [in]    value   Value to swap
 * @return                Swapped value
 */
#pragma inline_asm __HSH
static int16_t __HSH (int16_t value)
{
    hsh r6, r10
}

/**
 * @brief   Word data halfword swap
 * @details Swaps halfwords within a 32-bit word.
 * @param [in]    value   Value to swap
 * @return                Swapped value
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __HSW(value)    __hsw((long) value)

/**
 * @brief   Rotate left
 * @param [in]    value   Value to rotate
 * @param [in]    bit     The specified shift amount
 * @return                Swapped value
 */
#pragma inline_asm __ROTL
static int32_t __ROTL (int32_t value, uint8_t bit)
{
    rotl r7, r6, r10
}

/**
 * @brief   Bit (0) search from MSB side
 * @details Searches for first 0 bit starting from MSB.
 * @param [in]    value   Value to search
 * @return             Bit position
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __SCH0L(value)    __sch0l((long) value)

/**
 * @brief   Bit (0) search from LSB side
 * @details Searches for first 0 bit starting from LSB.
 * @param [in]    value   Value to search
 * @return             Bit position
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __SCH0R(value)    __sch0r((long) value)

/**
 * @brief   Bit (1) search from MSB side
 * @details Searches for first 1 bit starting from MSB.
 * @param [in]    value   Value to search
 * @return                Bit position
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __SCH1L(value)    __sch1l((long) value)

/**
 * @brief   Bit (1) search from LSB side
 * @details Searches for first 1 bit starting from LSB.
 * @param [in]    value   Value to search
 * @return             Bit position
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __SCH1R(value)    __sch1r((long) value)

/**
 * @brief   Divide word
 * @param [in]  num1  Dividend number
 * @param [in]  num2  Divisor number
 * @return             The remainder of quotient = num1/num2
 */
#pragma inline_asm __DIV
static int32_t __DIV (int32_t num1, int32_t num2)
{
    div r7, r6, r10
}

/**
 * @brief   Divide word unsigned
 * @param [in]  num1  Dividend number
 * @param [in]  num2  Divisor number
 * @return             The remainder of quotient = num1/num2
 */
#pragma inline_asm __DIVU
static uint32_t __DIVU (uint32_t num1, uint32_t num2)
{
    divu r7, r6, r10
}

/**
 * @brief   Bit clear
 * @details Clear bit a specific bit in a value.
 * @param [in]    addr    Address
 * @param [in]    bit  Bit position
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __CLR1(addr, bit)     __clr1((unsigned char *) addr, (long) bit)

/**
 * @brief   Bit set
 * @details Sets a specific bit in a value.
 * @param [in]    addr    Address
 * @param [in]    bit  Bit position
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __SET1(addr, bit)     __set1((unsigned char *) addr, (long) bit)

/**
 * @brief   Bit not
 * @details Toggles a specific bit in a value.
 * @param [in]    addr    Address
 * @param [in]    bit  Bit position
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __NOT1(addr, bit)     __not1((unsigned char *) addr, (long) bit)

/**
 * @brief   Compare and Exchange
 * @details Atomic compare and exchange operation.
 * @param [in]    addr   Address
 * @param [in]    b   Compare value
 * @param [in]    c   Exchange value
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __CAXI(addr, b, c)    __caxi((long *) addr, (long) b, (long) c)

/**
 * @brief   Clear Load Link
 * @details Clear Load Link which is created by LDL.
 */
#pragma inline_asm __CLL
static void __CLL (void)
{
    cll;                               // Clear Load Link
}

/**
 * @brief   Disable Interrupts
 * @details Executes the DI instruction to disable maskable interrupts.
 */
#define __DI()    __DI()

/**
 * @brief   Enable Interrupts
 * @details Executes the EI instruction to enable maskable interrupts.
 */
#define __EI()    __EI()

/**
 * @brief   Return from EI-level trap or interrupt
 */
#pragma inline_asm __EIRET
static void __EIRET (void)
{
    eiret
}

/**
 * @brief   Return from FE-level trap or interrupt
 */
#pragma inline_asm __FERET
static void __FERET (void)
{
    feret
}

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
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __LDSR(regID, selID, value)    __ldsr_rh((long) regID, (long) selID, (unsigned long) value)

/**
 * @brief   LDR Exclusive (8 bit)
 * @details Executes a exclusive LDR instruction for 8 bit value.
 * @param [in]    addr  Pointer to data
 * @return             value of type uint8_t at (*ptr)
 */
#define __LDLBU(addr)                  __ldlbu((unsigned char *) addr)

/**
 * @brief   LDR Exclusive (16 bit)
 * @details Executes a exclusive LDR instruction for 16 bit values.
 * @param [in]    addr  Pointer to data
 * @return        value of type uint16_t at (*ptr)
 */
#define __LDLHU(addr)                  __ldlhu((unsigned short *) addr)

/**
 * @brief   Atomic load to system register
 * @details Loads a value into a system register atomically.
 * @param [in]    value   Value to load
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __LDLW(value)                  __ldlw((long *) value)

/**
 * @brief   No Operation
 * @details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
#define __NOP()                        __nop()

/**
 * @brief   Restore contexts from register bank
 */
#pragma inline_asm __RESBANK
static void __RESBANK (void)
{
    resbank
}

/**
 * @brief   Snooze
 */
#pragma inline_asm __SNOOZE
static void __SNOOZE (void)
{
    snooze
}

/**
 * @brief   Store contents of system register (with selector)
 * @details Stores contents of system register with selector ID.
 * @param [in]    regID  Register ID
 * @param [in]    selID  Selector ID
 * @return               Register value
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __STSR(regID, selID)        __stsr_rh((long) regID, (long) selID)

/**
 * @brief   STR Exclusive (8 bit)
 * @details Executes a exclusive STR instruction for 8 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 */
#define __STCB(addr, value)         __stcb((unsigned char *) addr, (unsigned char) value)

/**
 * @brief   STR Exclusive (16 bit)
 * @details Executes a exclusive STR instruction for 16 bit values.
 * @param [in]  value  Value to store
 * @param [in]    addr  Pointer to location
 * @return          0  Function succeeded
 * @return          1  Function failed
 */
#define __STCH(addr, value)         __stch((unsigned short *) addr, (unsigned short) value)

/**
 * @brief   Store word
 * @details Stores a word to memory.
 * @param [in]    addr    Address
 * @param [in]    value    Value
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __STCW(addr, value)         __stcw((long *) addr, (long) value)

/**
 * @brief   Exception synchronization
 * @details Synchronizes exception handling.
 */
#define __SYNCE()                   __synce()

/**
 * @brief   Instruction pipeline synchronization
 * @details Synchronizes instruction pipeline.
 */
#define __SYNCI()                   __synci()

/**
 * @brief   Memory synchronization
 * @details Synchronizes memory operations.
 */
#define __SYNCM()                   __syncm()

/**
 * @brief   Pipeline synchronization
 * @details Synchronizes pipeline operations.
 */
#define __SYNCP()                   __syncp()

/**
 * @brief   Trap
 */
#define __TRAP(vector)              __ASM volatile ("trap " #vector)

/**
 * @brief   Halt CPU
 * @details HALT instruction stops CPU execution until an interrupt or reset occurs.
 */
#define __HALT()                    __halt()

/**
 * @brief   Debug checkpoint
 * @details Inserts a debug checkpoint instruction.
 */
#define __DBCP()                    __dbcp()

/**
 * @brief   Debug push
 * @details Pushes debug registers.
 * @param [in]    regID1  First register ID
 * @param [in]    regID2  Second register ID
 * @note    Default casts are applied to avoid cross-compiler warnings and errors
 */
#define __DBPUSH(regID1, regID2)    __dbpush((long) regID1, (long) regID2)

/**
 * @brief   Debug tag
 * @details Inserts a debug tag instruction.
 * @param [in]    a   Tag value
 */
#define __DBTAG(a)                  __dbtag(a)

/** @}*/ /* end of group CCRH_RH850_Core_InstructionInterface */
/** @}*/ /* end of group RH850_Core_InstructionInterface */

/* ##########################################  Core Function Access  ################################################ */

/** @defgroup RH850_Core_FunctionInterface RH850-Core Register Access Functions
 * @brief Access to the dedicated core register access function instructions
 * @{
 */

/** @ingroup  RH850_Core_FunctionInterface
 *  @defgroup CCRH_RH850_Core_RegAccFunctions CCRH RH850-Core Register Access Functions
 *  @brief CC-RH RH850-Core Register Access Functions
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
#pragma inline_asm __set_EIPC
static void __set_EIPC (uint32_t value)
{
    ldsr r6, 0, 0
}

/**
 * @brief Get EIPC (Status save registers when acknowledging EI level exception).
 * @details Reads the current value of the EIPC system register.
 * @return uint32_t register value.
 */
#pragma inline_asm  __get_EIPC
static uint32_t __get_EIPC (void)
{
    stsr 0, r10, 0
}

/**
 * @brief Set EIPSW (Status save registers when acknowledging EI level exception).
 * @details Writes a value to the EIPSW system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_EIPSW
static void __set_EIPSW (uint32_t value)
{
    ldsr r6, 1, 0
}

/**
 * @brief Get EIPSW (Status save registers when acknowledging EI level exception).
 * @details Reads the current value of the EIPSW system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_EIPSW
static uint32_t __get_EIPSW (void)
{
    stsr 1, r10, 0
}

/**
 * @brief Set FEPC (Status save registers when acknowledging FE level exception).
 * @details Writes a value to the FEPC system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FEPC
static void __set_FEPC (uint32_t value)
{
    ldsr r6, 2, 0
}

/**
 * @brief Get FEPC (Status save registers when acknowledging FE level exception).
 * @details Reads the current value of the FEPC system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FEPC
static uint32_t __get_FEPC (void)
{
    stsr 2, r10, 0
}

/**
 * @brief Set FEPSW (Status save registers when acknowledging FE level exception).
 * @details Writes a value to the FEPSW system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FEPSW
static void __set_FEPSW (uint32_t value)
{
    ldsr r6, 3, 0
}

/**
 * @brief Get FEPSW (Status save registers when acknowledging FE level exception).
 * @details Reads the current value of the FEPSW system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FEPSW
static uint32_t __get_FEPSW (void)
{
    stsr 3, r10, 0
}

/**
 * @brief Set PSW (Program status word).
 * @details Writes a value to the PSW system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PSW
static void __set_PSW (uint32_t value)
{
    ldsr r6, 5, 0
}

/**
 * @brief Get PSW (Program status word).
 * @details Reads the current value of the PSW system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PSW
static uint32_t __get_PSW (void)
{
    stsr 5, r10, 0
}

/**
 * @brief Set EIIC (EI level exception cause).
 * @details Writes a value to the EIIC system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_EIIC
static void __set_EIIC (uint32_t value)
{
    ldsr r6, 13, 0
}

/**
 * @brief Get EIIC (EI level exception cause).
 * @details Reads the current value of the EIIC system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_EIIC
static uint32_t __get_EIIC (void)
{
    stsr 13, r10, 0
}

/**
 * @brief Set FEIC (FE level exception cause).
 * @details Writes a value to the FEIC system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FEIC
static void __set_FEIC (uint32_t value)
{
    ldsr r6, 14, 0
}

/**
 * @brief Get FEIC (FE level exception cause).
 * @details Reads the current value of the FEIC system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FEIC
static uint32_t __get_FEIC (void)
{
    stsr 14, r10, 0
}

/**
 * @brief Set CTPC (CALLT execution status save register).
 * @details Writes a value to the CTPC system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_CTPC
static void __set_CTPC (uint32_t value)
{
    ldsr r6, 16, 0
}

/**
 * @brief Get CTPC (CALLT execution status save register).
 * @details Reads the current value of the CTPC system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_CTPC
static uint32_t __get_CTPC (void)
{
    stsr 16, r10, 0
}

/**
 * @brief Set CTPSW (CALLT execution status save register).
 * @details Writes a value to the CTPSW system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_CTPSW
static void __set_CTPSW (uint32_t value)
{
    ldsr r6, 17, 0
}

/**
 * @brief Get CTPSW (CALLT execution status save register).
 * @details Reads the current value of the CTPSW system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_CTPSW
static uint32_t __get_CTPSW (void)
{
    stsr 17, r10, 0
}

/* CALLT base pointer */

/**
 * @brief Set CTBP (CALLT base pointer).
 * @details Writes a value to the CTBP system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_CTBP
static void __set_CTBP (uint32_t value)
{
    ldsr r6, 20, 0
}

/**
 * @brief Get CTBP (CALLT base pointer).
 * @details Reads the current value of the CTBP system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_CTBP
static uint32_t __get_CTBP (void)
{
    stsr 20, r10, 0
}

/**
 * @brief Set SNZCFG (SNOOZE control register).
 * @details Writes a value to the SNZCFG system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_SNZCFG
static void __set_SNZCFG (uint32_t value)
{
    ldsr r6, 21, 0
}

/**
 * @brief Get SNZCFG (SNOOZE control register).
 * @details Reads the current value of the SNZCFG system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_SNZCFG
static uint32_t __get_SNZCFG (void)
{
    stsr 21, r10, 0
}

/**
 * @brief Set EIWR (EI level exception working register).
 * @details Writes a value to the EIWR system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_EIWR
static void __set_EIWR (uint32_t value)
{
    ldsr r6, 28, 0
}

/**
 * @brief Get EIWR (EI level exception working register).
 * @details Reads the current value of the EIWR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_EIWR
static uint32_t __get_EIWR (void)
{
    stsr 28, r10, 0
}

/**
 * @brief Set FEWR (FE level exception working register).
 * @details Writes a value to the FEWR system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FEWR
static void __set_FEWR (uint32_t value)
{
    ldsr r6, 29, 0
}

/**
 * @brief Get FEWR (FE level exception working register).
 * @details Reads the current value of the FEWR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FEWR
static uint32_t __get_FEWR (void)
{
    stsr 29, r10, 0
}

/**
 * @brief Set SPID (System protection identifier).
 * @details Writes a value to the SPID system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_SPID
static void __set_SPID (uint32_t value)
{
    ldsr r6, 0, 1
}

/**
 * @brief Get SPID (System protection identifier).
 * @details Reads the current value of the SPID system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_SPID
static uint32_t __get_SPID (void)
{
    stsr 0, r10, 1
}

/**
 * @brief Get SPIDLIST (List of system protection identifiers that can be specified in SPID).
 * @details Reads the current value of the SPIDLIST system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_SPIDLIST
static uint32_t __get_SPIDLIST (void)
{
    stsr 1, r10, 1
}

/**
 * @brief Get RBASE (Reset vector base address).
 * @details Reads the current value of the RBASE system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_RBASE
static uint32_t __get_RBASE (void)
{
    stsr 2, r10, 1
}

/**
 * @brief Set EBASE (Exception handler vector address).
 * @details Writes a value to the EBASE system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_EBASE
static void __set_EBASE (uint32_t value)
{
    ldsr r6, 3, 1
}

/**
 * @brief Get EBASE (Exception handler vector address).
 * @details Reads the current value of the EBASE system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_EBASE
static uint32_t __get_EBASE (void)
{
    stsr 3, r10, 1
}

/**
 * @brief Set INTBP (Base address of the interrupt handler "address" table).
 * @details Writes a value to the INTBP system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_INTBP
static void __set_INTBP (uint32_t value)
{
    ldsr r6, 4, 1
}

/**
 * @brief Get INTBP (Base address of the interrupt handler "address" table).
 * @details Reads the current value of the INTBP system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_INTBP
static uint32_t __get_INTBP (void)
{
    stsr 4, r10, 1
}

/**
 * @brief Set MCTL (CPU control).
 * @details Writes a value to the MCTL system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MCTL
static void __set_MCTL (uint32_t value)
{
    ldsr r6, 5, 1
}

/**
 * @brief Get MCTL (CPU control).
 * @details Reads the current value of the MCTL system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MCTL
static uint32_t __get_MCTL (void)
{
    stsr 5, r10, 1
}

/**
 * @brief Get PID (Processor ID).
 * @details Reads the current value of the PID system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PID
static uint32_t __get_PID (void)
{
    stsr 6, r10, 1
}

/**
 * @brief Set SVLOCK (Supervisor lock).
 * @details Writes a value to the SVLOCK system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_SVLOCK
static void __set_SVLOCK (uint32_t value)
{
    ldsr r6, 8, 1
}

/**
 * @brief Get SVLOCK (Supervisor lock).
 * @details Reads the current value of the SVLOCK system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_SVLOCK
static uint32_t __get_SVLOCK (void)
{
    stsr 8, r10, 1
}

/**
 * @brief Set SCCFG (SYSCALL operation setting).
 * @details Writes a value to the SCCFG system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_SCCFG
static void __set_SCCFG (uint32_t value)
{
    ldsr r6, 11, 1
}

/**
 * @brief Get SCCFG (SYSCALL operation setting).
 * @details Reads the current value of the SCCFG system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_SCCFG
static uint32_t __get_SCCFG (void)
{
    stsr 11, r10, 1
}

/**
 * @brief Set SCBP (SYSCALL base pointer).
 * @details Writes a value to the SCBP system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_SCBP
static void __set_SCBP (uint32_t value)
{
    ldsr r6, 12, 1
}

/**
 * @brief Get SCBP (SYSCALL base pointer).
 * @details Reads the current value of the SCBP system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_SCBP
static uint32_t __get_SCBP (void)
{
    stsr 12, r10, 1
}

/**
 * @brief Get PEID (Processor element identifier).
 * @details Reads the current value of the PEID system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PEID
static uint32_t __get_PEID (void)
{
    stsr 0, r10, 2
}

/**
 * @brief Get BMID (Bus master identifier).
 * @details Reads the current value of the BMID system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_BMID
static uint32_t __get_BMID (void)
{
    stsr 1, r10, 2
}

/**
 * @brief Set MEA (Memory error address).
 * @details Writes a value to the MEA system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MEA
static void __set_MEA (uint32_t value)
{
    ldsr r6, 6, 2
}

/**
 * @brief Get MEA (Memory error address).
 * @details Reads the current value of the MEA system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MEA
static uint32_t __get_MEA (void)
{
    stsr 6, r10, 2
}

/**
 * @brief Set MEI (Memory error information).
 * @details Writes a value to the MEI system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MEI
static void __set_MEI (uint32_t value)
{
    ldsr r6, 8, 2
}

/**
 * @brief Get MEI (Memory error information).
 * @details Reads the current value of the MEI system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MEI
static uint32_t __get_MEI (void)
{
    stsr 8, r10, 2
}

/**
 * @brief Set RBCR0 (Register bank control 0).
 * @details Writes a value to the RBCR0 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_RBCR0
static void __set_RBCR0 (uint32_t value)
{
    ldsr r6, 15, 2
}

/**
 * @brief Get RBCR0 (Register bank control 0).
 * @details Reads the current value of the RBCR0 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_RBCR0
static uint32_t __get_RBCR0 (void)
{
    stsr 15, r10, 2
}

/**
 * @brief Set RBCR1 (Register bank control 1).
 * @details Writes a value to the RBCR1 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_RBCR1
static void __set_RBCR1 (uint32_t value)
{
    ldsr r6, 16, 2
}

/**
 * @brief Get RBCR1 (Register bank control 1).
 * @details Reads the current value of the RBCR1 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_RBCR1
static uint32_t __get_RBCR1 (void)
{
    stsr 16, r10, 2
}

/**
 * @brief Set RBNR (Register bank number).
 * @details Writes a value to the RBNR system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_RBNR
static void __set_RBNR (uint32_t value)
{
    ldsr r6, 17, 2
}

/**
 * @brief Get RBNR (Register bank number).
 * @details Reads the current value of the RBNR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_RBNR
static uint32_t __get_RBNR (void)
{
    stsr 17, r10, 2
}

/**
 * @brief Set RBIP (Register bank initial pointer).
 * @details Writes a value to the RBIP system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_RBIP
static void __set_RBIP (uint32_t value)
{
    ldsr r6, 18, 2
}

/**
 * @brief Get RBIP (Register bank initial pointer).
 * @details Reads the current value of the RBIP system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_RBIP
static uint32_t __get_RBIP (void)
{
    stsr 18, r10, 2
}

/***********************************************************************************************************************
 *                 Interrupt Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set ISPR (Priority of interrupt being serviced).
 * @details Writes a value to the ISPR system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_ISPR
static void __set_ISPR (uint32_t value)
{
    ldsr r6, 10, 2
}

/**
 * @brief Get ISPR (Priority of interrupt being serviced).
 * @details Reads the current value of the ISPR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_ISPR
static uint32_t __get_ISPR (void)
{
    stsr 10, r10, 2
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get IMSR (Interrupt mask status).
 * @details Reads the current value of the IMSR system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_IMSR
static uint32_t __get_IMSR (void)
{
    stsr 11, r10, 2
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief Get ICSR (Interrupt control status).
 * @details Reads the current value of the ICSR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_ICSR
static uint32_t __get_ICSR (void)
{
    stsr 12, r10, 2
}

/**
 * @brief Set INTCFG (Interrupt function setting).
 * @details Writes a value to the INTCFG system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_INTCFG
static void __set_INTCFG (uint32_t value)
{
    ldsr r6, 13, 2
}

/**
 * @brief Get INTCFG (Interrupt function setting).
 * @details Reads the current value of the INTCFG system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_INTCFG
static uint32_t __get_INTCFG (void)
{
    stsr 13, r10, 2
}

/**
 * @brief Set PLMR (Interrupt priority masking).
 * @details Writes a value to the PLMR system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PLMR
static void __set_PLMR (uint32_t value)
{
    ldsr r6, 14, 2
}

/**
 * @brief Get PLMR (Interrupt priority masking).
 * @details Reads the current value of the PLMR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PLMR
static uint32_t __get_PLMR (void)
{
    stsr 14, r10, 2
}

/***********************************************************************************************************************
 *                 FPU Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set FPSR (Floating-point operation configuration/status).
 * @details Writes a value to the FPSR system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FPSR
static void __set_FPSR (uint32_t value)
{
    ldsr r6, 6, 0
}

/**
 * @brief Get FPSR (Floating-point operation configuration/status).
 * @details Reads the current value of the FPSR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FPSR
static uint32_t __get_FPSR (void)
{
    stsr 6, r10, 0
}

/**
 * @brief Set FPEPC (Floating-point operation exception program counter).
 * @details Writes a value to the FPEPC system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FPEPC
static void __set_FPEPC (uint32_t value)
{
    ldsr r6, 7, 0
}

/**
 * @brief Get FPEPC (Floating-point operation exception program counter).
 * @details Reads the current value of the FPEPC system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FPEPC
static uint32_t __get_FPEPC (void)
{
    stsr 7, r10, 0
}

/**
 * @brief Set FPST (Floating point operation status).
 * @details Writes a value to the FPST system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FPST
static void __set_FPST (uint32_t value)
{
    ldsr r6, 8, 0
}

/**
 * @brief Get FPST (Floating point operation status).
 * @details Reads the current value of the FPST system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FPST
static uint32_t __get_FPST (void)
{
    stsr 8, r10, 0
}

/**
 * @brief Set FPCC (Floating-point operation comparison result).
 * @details Writes a value to the FPCC system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FPCC
static void __set_FPCC (uint32_t value)
{
    ldsr r6, 9, 0
}

/**
 * @brief Get FPCC (Floating-point operation comparison result).
 * @details Reads the current value of the FPCC system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FPCC
static uint32_t __get_FPCC (void)
{
    stsr 9, r10, 0
}

/**
 * @brief Set FPCFG (Floating-point operation configuration).
 * @details Writes a value to the FPCFG system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FPCFG
static void __set_FPCFG (uint32_t value)
{
    ldsr r6, 10, 0
}

/**
 * @brief Get FPCFG (Floating-point operation configuration).
 * @details Reads the current value of the FPCFG system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FPCFG
static uint32_t __get_FPCFG (void)
{
    stsr 10, r10, 0
}

#if defined(__RH850_G4KH) && (__RH850_G4KH == 1)

/**
 * @brief Set FPEC (Floating-point exception control).
 * @details Writes a value to the FPEC system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_FPEC
static void __set_FPEC (uint32_t value)
{
    ldsr r6, 11, 0
}

/**
 * @brief Get FPEC (Floating-point exception control).
 * @details Reads the current value of the FPEC system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_FPEC
static uint32_t __get_FPEC (void)
{
    stsr 11, r10, 0
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
#pragma inline_asm __set_FXSR
static void __set_FXSR (uint32_t value)
{
    ldsr r6, 6, 10
}

/**
 * @brief Get FXSR (Extended floating-point operation configuration/status).
 * @details Reads the current value of the FXSR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FXSR
static uint32_t __get_FXSR (void)
{
    stsr 6, r10, 10
}

/**
 * @brief Set FXST (Extended floating-point operation status).
 * @details Writes a value to the FXST system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FXST
static void __set_FXST (uint32_t value)
{
    ldsr r6, 8, 10
}

/**
 * @brief Get FXST (Extended floating-point operation status).
 * @details Reads the current value of the FXST system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FXST
static uint32_t __get_FXST (void)
{
    stsr 8, r10, 10
}

/**
 * @brief Get FXINFO (FXU configuration information).
 * @details Reads the current value of the FXINFO system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FXINFO
static uint32_t __get_FXINFO (void)
{
    stsr 9, r10, 10
}

/* Extended floating-point operation configuration */

/**
 * @brief Set FXCFG (Extended floating-point operation configuration).
 * @details Writes a value to the FXCFG system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FXCFG
static void __set_FXCFG (uint32_t value)
{
    ldsr r6, 10, 10
}

/**
 * @brief Get FXCFG (Extended floating-point operation configuration).
 * @details Reads the current value of the FXCFG system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FXCFG
static uint32_t __get_FXCFG (void)
{
    stsr 10, r10, 10
}

/* XC (cause) bits for each operation way */

/**
 * @brief Set FXXC (XC (cause) bits for each operation way).
 * @details Writes a value to the FXXC system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FXXC
static void __set_FXXC (uint32_t value)
{
    ldsr r6, 12, 10
}

/**
 * @brief Get FXXC (XC (cause) bits for each operation way).
 * @details Reads the current value of the FXXC system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FXXC
static uint32_t __get_FXXC (void)
{
    stsr 12, r10, 10
}

/**
 * @brief Set FXXP (XP (preservation) bits for each operation way).
 * @details Writes a value to the FXXP system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_FXXP
static void __set_FXXP (uint32_t value)
{
    ldsr r6, 13, 10
}

/**
 * @brief Get FXXP (XP (preservation) bits for each operation way).
 * @details Reads the current value of the FXXP system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_FXXP
static uint32_t __get_FXXP (void)
{
    stsr 13, r10, 10
}

/***********************************************************************************************************************
 *                 MPU Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set MPM (Memory protection operation mode setting).
 * @details Writes a value to the MPM system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPM
static void __set_MPM (uint32_t value)
{
    ldsr r6, 0, 5
}

/**
 * @brief Get MPM (Memory protection operation mode setting).
 * @details Reads the current value of the MPM system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPM
static uint32_t __get_MPM (void)
{
    stsr 0, r10, 5
}

/**
 * @brief Get MPCFG (MPU configuration).
 * @details Reads the current value of the MPCFG system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPCFG
static uint32_t __get_MPCFG (void)
{
    stsr 2, r10, 5
}

/**
 * @brief Set MCA (Memory protection setting check address).
 * @details Writes a value to the MCA system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MCA
static void __set_MCA (uint32_t value)
{
    ldsr r6, 8, 5
}

/**
 * @brief Get MCA (Memory protection setting check address).
 * @details Reads the current value of the MCA system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MCA
static uint32_t __get_MCA (void)
{
    stsr 8, r10, 5
}

/**
 * @brief Set MCS (Memory protection setting check size).
 * @details Writes a value to the MCS system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MCS
static void __set_MCS (uint32_t value)
{
    ldsr r6, 9, 5
}

/**
 * @brief Get MCS (Memory protection setting check size).
 * @details Reads the current value of the MCS system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MCS
static uint32_t __get_MCS (void)
{
    stsr 9, r10, 5
}

/**
 * @brief Set MCC (Memory protection setting check command).
 * @details Writes a value to the MCC system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MCC
static void __set_MCC (uint32_t value)
{
    ldsr r6, 10, 5
}

/**
 * @brief Get MCC (Memory protection setting check command).
 * @details Reads the current value of the MCC system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MCC
static uint32_t __get_MCC (void)
{
    stsr 10, r10, 5
}

/**
 * @brief Set MCR (Memory protection setting check result).
 * @details Writes a value to the MCR system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MCR
static void __set_MCR (uint32_t value)
{
    ldsr r6, 11, 5
}

/**
 * @brief Get MCR (Memory protection setting check result).
 * @details Reads the current value of the MCR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MCR
static uint32_t __get_MCR (void)
{
    stsr 11, r10, 5
}

/**
 * @brief Set MCI (Memory protection setting check SPID).
 * @details Writes a value to the MCI system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MCI
static void __set_MCI (uint32_t value)
{
    ldsr r6, 12, 5
}

/**
 * @brief Get MCI (Memory protection setting check SPID).
 * @details Reads the current value of the MCI system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MCI
static uint32_t __get_MCI (void)
{
    stsr 12, r10, 5
}

/**
 * @brief Set MPIDX (Index of memory protection setting registers to be accessed).
 * @details Writes a value to the MPIDX system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPIDX
static void __set_MPIDX (uint32_t value)
{
    ldsr r6, 16, 5
}

/**
 * @brief Get MPIDX (Index of memory protection setting registers to be accessed).
 * @details Reads the current value of the MPIDX system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPIDX
static uint32_t __get_MPIDX (void)
{
    stsr 16, r10, 5
}

/**
 * @brief Set MPBK (MPU Bank Setting).
 * @details Writes a value to the MPBK system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPBK
static void __set_MPBK (uint32_t value)
{
    ldsr r6, 17, 5
}

/**
 * @brief Get MPBK (MPU Bank Setting).
 * @details Reads the current value of the MPBK system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPBK
static uint32_t __get_MPBK (void)
{
    stsr 17, r10, 5
}

/**
 * @brief Set MPLA (Protection area minimum address).
 * @details Writes a value to the MPLA system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPLA
static void __set_MPLA (uint32_t value)
{
    ldsr r6, 20, 5
}

/**
 * @brief Get MPLA (Protection area minimum address).
 * @details Reads the current value of the MPLA system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPLA
static uint32_t __get_MPLA (void)
{
    stsr 20, r10, 5
}

/**
 * @brief Set MPUA (Protection area maximum address).
 * @details Writes a value to the MPUA system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPUA
static void __set_MPUA (uint32_t value)
{
    ldsr r6, 21, 5
}

/**
 * @brief Get MPUA (Protection area maximum address).
 * @details Reads the current value of the MPUA system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPUA
static uint32_t __get_MPUA (void)
{
    stsr 21, r10, 5
}

/**
 * @brief Set MPAT (Protection area attribute).
 * @details Writes a value to the MPAT system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPAT
static void __set_MPAT (uint32_t value)
{
    ldsr r6, 22, 5
}

/**
 * @brief Get MPAT (Protection area attribute).
 * @details Reads the current value of the MPAT system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPAT
static uint32_t __get_MPAT (void)
{
    stsr 22, r10, 5
}

/**
 * @brief Set MPID0 (SPID which can access protection area).
 * @details Writes a value to the MPID0 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPID0
static void __set_MPID0 (uint32_t value)
{
    ldsr r6, 24, 5
}

/**
 * @brief Get MPID0 (SPID which can access protection area).
 * @details Reads the current value of the MPID0 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPID0
static uint32_t __get_MPID0 (void)
{
    stsr 24, r10, 5
}

/**
 * @brief Set MPID1 (SPID which can access protection area).
 * @details Writes a value to the MPID1 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPID1
static void __set_MPID1 (uint32_t value)
{
    ldsr r6, 25, 5
}

/**
 * @brief Get MPID1 (SPID which can access protection area).
 * @details Reads the current value of the MPID1 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPID1
static uint32_t __get_MPID1 (void)
{
    stsr 25, r10, 5
}

/**
 * @brief Set MPID2 (SPID which can access protection area).
 * @details Writes a value to the MPID2 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPID2
static void __set_MPID2 (uint32_t value)
{
    ldsr r6, 26, 5
}

/**
 * @brief Get MPID2 (SPID which can access protection area).
 * @details Reads the current value of the MPID2 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPID2
static uint32_t __get_MPID2 (void)
{
    stsr 26, r10, 5
}

/**
 * @brief Set MPID3 (SPID which can access protection area).
 * @details Writes a value to the MPID3 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPID3
static void __set_MPID3 (uint32_t value)
{
    ldsr r6, 27, 5
}

/**
 * @brief Get MPID3 (SPID which can access protection area).
 * @details Reads the current value of the MPID3 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPID3
static uint32_t __get_MPID3 (void)
{
    stsr 27, r10, 5
}

/**
 * @brief Set MPID4 (SPID which can access protection area).
 * @details Writes a value to the MPID4 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPID4
static void __set_MPID4 (uint32_t value)
{
    ldsr r6, 28, 5
}

/**
 * @brief Get MPID4 (SPID which can access protection area).
 * @details Reads the current value of the MPID4 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPID4
static uint32_t __get_MPID4 (void)
{
    stsr 28, r10, 5
}

/**
 * @brief Set MPID5 (SPID which can access protection area).
 * @details Writes a value to the MPID5 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPID5
static void __set_MPID5 (uint32_t value)
{
    ldsr r6, 29, 5
}

/**
 * @brief Get MPID5 (SPID which can access protection area).
 * @details Reads the current value of the MPID5 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPID5
static uint32_t __get_MPID5 (void)
{
    stsr 29, r10, 5
}

/**
 * @brief Set MPID6 (SPID which can access protection area).
 * @details Writes a value to the MPID6 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPID6
static void __set_MPID6 (uint32_t value)
{
    ldsr r6, 30, 5
}

/**
 * @brief Get MPID6 (SPID which can access protection area).
 * @details Reads the current value of the MPID6 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPID6
static uint32_t __get_MPID6 (void)
{
    stsr 30, r10, 5
}

/**
 * @brief Set MPID7 (SPID which can access protection area).
 * @details Writes a value to the MPID7 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_MPID7
static void __set_MPID7 (uint32_t value)
{
    ldsr r6, 31, 5
}

/**
 * @brief Get MPID7 (SPID which can access protection area).
 * @details Reads the current value of the MPID7 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_MPID7
static uint32_t __get_MPID7 (void)
{
    stsr 31, r10, 5
}

/***********************************************************************************************************************
 *                 Cache Operation Function Registers
 **********************************************************************************************************************/

/**
 * @brief Set ICTAGL (Instruction cache tag Lo access).
 * @details Writes a value to the ICTAGL system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_ICTAGL
static void __set_ICTAGL (uint32_t value)
{
    ldsr r6, 16, 4
}

/**
 * @brief Get ICTAGL (Instruction cache tag Lo access).
 * @details Reads the current value of the ICTAGL system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_ICTAGL
static uint32_t __get_ICTAGL (void)
{
    stsr 16, r10, 4
}

/**
 * @brief Set ICTAGH (Instruction cache tag Hi access).
 * @details Writes a value to the ICTAGH system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_ICTAGH
static void __set_ICTAGH (uint32_t value)
{
    ldsr r6, 17, 4
}

/**
 * @brief Get ICTAGH (Instruction cache tag Hi access).
 * @details Reads the current value of the ICTAGH system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_ICTAGH
static uint32_t __get_ICTAGH (void)
{
    stsr 17, r10, 4
}

/**
 * @brief Set ICDATL (Instruction cache data Lo access).
 * @details Writes a value to the ICDATL system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_ICDATL
static void __set_ICDATL (uint32_t value)
{
    ldsr r6, 18, 4
}

/**
 * @brief Get ICDATL (Instruction cache data Lo access).
 * @details Reads the current value of the ICDATL system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_ICDATL
static uint32_t __get_ICDATL (void)
{
    stsr 18, r10, 4
}

/**
 * @brief Set ICDATH (Instruction cache data Hi access).
 * @details Writes a value to the ICDATH system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_ICDATH
static void __set_ICDATH (uint32_t value)
{
    ldsr r6, 19, 4
}

/**
 * @brief Get ICDATH (Instruction cache data Hi access).
 * @details Reads the current value of the ICDATH system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_ICDATH
static uint32_t __get_ICDATH (void)
{
    stsr 19, r10, 4
}

/**
 * @brief Set ICCTRL (Instruction cache control).
 * @details Writes a value to the ICCTRL system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_ICCTRL
static void __set_ICCTRL (uint32_t value)
{
    ldsr r6, 24, 4
}

/**
 * @brief Get ICCTRL (Instruction cache control).
 * @details Reads the current value of the ICCTRL system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_ICCTRL
static uint32_t __get_ICCTRL (void)
{
    stsr 24, r10, 4
}

/**
 * @brief Get ICCFG (Instruction cache configuration).
 * @details Reads the current value of the ICCFG system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_ICCFG
static uint32_t __get_ICCFG (void)
{
    stsr 26, r10, 4
}

/**
 * @brief Set ICERR (Instruction cache error).
 * @details Writes a value to the ICERR system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_ICERR
static void __set_ICERR (uint32_t value)
{
    ldsr r6, 28, 4
}

/**
 * @brief Get ICERR (Instruction cache error).
 * @details Reads the current value of the ICERR system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_ICERR
static uint32_t __get_ICERR (void)
{
    stsr 28, r10, 4
}

/***********************************************************************************************************************
 *                 Basic System Registers
 **********************************************************************************************************************/

/**
 * @brief Set TSCOUNTL (Timestamp count L register).
 * @details Writes a value to the TSCOUNTL system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_TSCOUNTL
static void __set_TSCOUNTL (uint32_t value)
{
    ldsr r6, 0, 11
}

/**
 * @brief Get TSCOUNTL (Timestamp count L register).
 * @details Reads the current value of the TSCOUNTL system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_TSCOUNTL
static uint32_t __get_TSCOUNTL (void)
{
    stsr 0, r10, 11
}

/**
 * @brief Set TSCOUNTH (Timestamp count H register).
 * @details Writes a value to the TSCOUNTH system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_TSCOUNTH
static void __set_TSCOUNTH (uint32_t value)
{
    ldsr r6, 1, 11
}

/**
 * @brief Get TSCOUNTH (Timestamp count H register).
 * @details Reads the current value of the TSCOUNTH system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_TSCOUNTH
static uint32_t __get_TSCOUNTH (void)
{
    stsr 1, r10, 11
}

/**
 * @brief Set TSCTRL (Timestamp count control register).
 * @details Writes a value to the TSCTRL system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_TSCTRL
static void __set_TSCTRL (uint32_t value)
{
    ldsr r6, 2, 11
}

/**
 * @brief Get TSCTRL (Timestamp count control register).
 * @details Reads the current value of the TSCTRL system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_TSCTRL
static uint32_t __get_TSCTRL (void)
{
    stsr 2, r10, 11
}

/**
 * @brief Set PMUMCTRL (Performance counter User mode control register).
 * @details Writes a value to the PMUMCTRL system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PMUMCTRL
static void __set_PMUMCTRL (uint32_t value)
{
    ldsr r6, 8, 11
}

/**
 * @brief Get PMUMCTRL (Performance counter User mode control register).
 * @details Reads the current value of the PMUMCTRL system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PMUMCTRL
static uint32_t __get_PMUMCTRL (void)
{
    stsr 8, r10, 11
}

/**
 * @brief Set PMCTRL0 (Performance count control 0 register).
 * @details Writes a value to the PMCTRL0 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PMCTRL0
static void __set_PMCTRL0 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    ldsr r6, 0, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    ldsr r6, 17, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCTRL0 (Performance count control 0 register).
 * @details Reads the current value of the PMCTRL0 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PMCTRL0
static uint32_t __get_PMCTRL0 (void)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    stsr 0, r10, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    stsr 17, r10, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Set PMCTRL1 (Performance count control 1 register).
 * @details Writes a value to the PMCTRL1 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PMCTRL1
static void __set_PMCTRL1 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    ldsr r6, 1, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    ldsr r6, 19, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCTRL1 (Performance count control 1 register).
 * @details Reads the current value of the PMCTRL1 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PMCTRL1
static uint32_t __get_PMCTRL1 (void)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    stsr 1, r10, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    stsr 19, r10, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Set PMCTRL2 (Performance count control 2 register).
 * @details Writes a value to the PMCTRL2 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PMCTRL2
static void __set_PMCTRL2 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    ldsr r6, 2, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    ldsr r6, 21, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCTRL2 (Performance count control 2 register).
 * @details Reads the current value of the PMCTRL2 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PMCTRL2
static uint32_t __get_PMCTRL2 (void)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    stsr 2, r10, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    stsr 21, r10, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Set PMCTRL3 (Performance count control 3 register).
 * @details Writes a value to the PMCTRL3 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PMCTRL3
static void __set_PMCTRL3 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    ldsr r6, 3, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    ldsr r6, 23, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCTRL3 (Performance count control 3 register).
 * @details Reads the current value of the PMCTRL3 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PMCTRL3
static uint32_t __get_PMCTRL3 (void)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    stsr 3, r10, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    stsr 23, r10, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCTRL4 (Performance count control 4 register).
 * @details Writes a value to the PMCTRL4 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMCTRL4
static void __set_PMCTRL4 (uint32_t value)
{
    ldsr r6, 4, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCTRL4 (Performance count control 4 register).
 * @details Reads the current value of the PMCTRL4 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMCTRL4
static uint32_t __get_PMCTRL4 (void)
{
    stsr 4, r10, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCTRL5 (Performance count control 5 register).
 * @details Writes a value to the PMCTRL5 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMCTRL5
static void __set_PMCTRL5 (uint32_t value)
{
    ldsr r6, 5, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCTRL5 (Performance count control 5 register).
 * @details Reads the current value of the PMCTRL5 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMCTRL5
static uint32_t __get_PMCTRL5 (void)
{
    stsr 5, r10, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCTRL6 (Performance count control 6 register).
 * @details Writes a value to the PMCTRL6 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMCTRL6
static void __set_PMCTRL6 (uint32_t value)
{
    ldsr r6, 6, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCTRL6 (Performance count control 6 register).
 * @details Reads the current value of the PMCTRL6 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMCTRL6
static uint32_t __get_PMCTRL6 (void)
{
    stsr 6, r10, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCTRL7 (Performance count control 7 register).
 * @details Writes a value to the PMCTRL7 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMCTRL7
static void __set_PMCTRL7 (uint32_t value)
{
    ldsr r6, 7, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCTRL7 (Performance count control 7 register).
 * @details Reads the current value of the PMCTRL7 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMCTRL7
static uint32_t __get_PMCTRL7 (void)
{
    stsr 7, r10, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/**
 * @brief Set PMCOUNT0 (Performance count 0 register).
 * @details Writes a value to the PMCOUNT0 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PMCOUNT0
static void __set_PMCOUNT0 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    ldsr r6, 16, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    ldsr r6, 16, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCOUNT0 (Performance count 0 register).
 * @details Reads the current value of the PMCOUNT0 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PMCOUNT0
static uint32_t __get_PMCOUNT0 (void)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    stsr 16, r10, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    stsr 16, r10, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Set PMCOUNT1 (Performance count 1 register).
 * @details Writes a value to the PMCOUNT1 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PMCOUNT1
static void __set_PMCOUNT1 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    ldsr r6, 17, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    ldsr r6, 18, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCOUNT1 (Performance count 1 register).
 * @details Reads the current value of the PMCOUNT1 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PMCOUNT1
static uint32_t __get_PMCOUNT1 (void)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    stsr 17, r10, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    stsr 18, r10, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Set PMCOUNT2 (Performance count 2 register).
 * @details Writes a value to the PMCOUNT2 system register.
 * @param[in] value uint32_t input.
 */

/* Performance count 2 register */
#pragma inline_asm __set_PMCOUNT2
static void __set_PMCOUNT2 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    ldsr r6, 18, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    ldsr r6, 20, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCOUNT2 (Performance count 2 register).
 * @details Reads the current value of the PMCOUNT2 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PMCOUNT2
static uint32_t __get_PMCOUNT2 (void)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    stsr 18, r10, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    stsr 20, r10, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Set PMCOUNT3 (Performance count 3 register).
 * @details Writes a value to the PMCOUNT3 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_PMCOUNT3
static void __set_PMCOUNT3 (uint32_t value)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    ldsr r6, 19, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    ldsr r6, 22, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

/**
 * @brief Get PMCOUNT3 (Performance count 3 register).
 * @details Reads the current value of the PMCOUNT3 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_PMCOUNT3
static uint32_t __get_PMCOUNT3 (void)
{
#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)
    stsr 19, r10, 14
#elif defined(__RH850_G4KH) && (__RH850_G4KH == 1)
    stsr 22, r10, 11
#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCOUNT4 (Performance count 4 register).
 * @details Writes a value to the PMCOUNT4 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMCOUNT4
static void __set_PMCOUNT4 (uint32_t value)
{
    ldsr r6, 20, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCOUNT4 (Performance count 4 register).
 * @details Reads the current value of the PMCOUNT4 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMCOUNT4
static uint32_t __get_PMCOUNT4 (void)
{
    stsr 20, r10, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCOUNT5 (Performance count 5 register).
 * @details Writes a value to the PMCOUNT5 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMCOUNT5
static void __set_PMCOUNT5 (uint32_t value)
{
    ldsr r6, 21, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCOUNT5 (Performance count 5 register).
 * @details Reads the current value of the PMCOUNT5 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMCOUNT5
static uint32_t __get_PMCOUNT5 (void)
{
    stsr 21, r10, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCOUNT6 (Performance count 6 register).
 * @details Writes a value to the PMCOUNT6 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMCOUNT6
static void __set_PMCOUNT6 (uint32_t value)
{
    ldsr r6, 22, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCOUNT6 (Performance count 6 register).
 * @details Reads the current value of the PMCOUNT6 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMCOUNT6
static uint32_t __get_PMCOUNT6 (void)
{
    stsr 22, r10, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMCOUNT7 (Performance count 7 register).
 * @details Writes a value to the PMCOUNT7 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMCOUNT7
static void __set_PMCOUNT7 (uint32_t value)
{
    ldsr r6, 23, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMCOUNT7 (Performance count 7 register).
 * @details Reads the current value of the PMCOUNT7 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMCOUNT7
static uint32_t __get_PMCOUNT7 (void)
{
    stsr 23, r10, 14
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND0 (Performance count subcondition 0 register).
 * @details Writes a value to the PMSUBCND0 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMSUBCND0
static void __set_PMSUBCND0 (uint32_t value)
{
    ldsr r6, 0, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND0 (Performance count subcondition 0 register).
 * @details Reads the current value of the PMSUBCND0 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMSUBCND0
static uint32_t __get_PMSUBCND0 (void)
{
    stsr 0, r10, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND1 (Performance count subcondition 1 register).
 * @details Writes a value to the PMSUBCND1 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMSUBCND1
static void __set_PMSUBCND1 (uint32_t value)
{
    ldsr r6, 1, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND1 (Performance count subcondition 1 register).
 * @details Reads the current value of the PMSUBCND1 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMSUBCND1
static uint32_t __get_PMSUBCND1 (void)
{
    stsr 1, r10, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND2 (Performance count subcondition 2 register).
 * @details Writes a value to the PMSUBCND2 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMSUBCND2
static void __set_PMSUBCND2 (uint32_t value)
{
    ldsr r6, 2, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND2 (Performance count subcondition 2 register).
 * @details Reads the current value of the PMSUBCND2 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMSUBCND2
static uint32_t __get_PMSUBCND2 (void)
{
    stsr 2, r10, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND3 (Performance count subcondition 3 register).
 * @details Writes a value to the PMSUBCND3 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMSUBCND3
static void __set_PMSUBCND3 (uint32_t value)
{
    ldsr r6, 3, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND3 (Performance count subcondition 3 register).
 * @details Reads the current value of the PMSUBCND3 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMSUBCND3
static uint32_t __get_PMSUBCND3 (void)
{
    stsr 3, r10, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND4 (Performance count subcondition 4 register).
 * @details Writes a value to the PMSUBCND4 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMSUBCND4
static void __set_PMSUBCND4 (uint32_t value)
{
    ldsr r6, 4, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND4 (Performance count subcondition 4 register).
 * @details Reads the current value of the PMSUBCND4 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMSUBCND4
static uint32_t __get_PMSUBCND4 (void)
{
    stsr 4, r10, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND5 (Performance count subcondition 5 register).
 * @details Writes a value to the PMSUBCND5 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMSUBCND5
static void __set_PMSUBCND5 (uint32_t value)
{
    ldsr r6, 5, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND5 (Performance count subcondition 5 register).
 * @details Reads the current value of the PMSUBCND5 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMSUBCND5
static uint32_t __get_PMSUBCND5 (void)
{
    stsr 5, r10, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND6 (Performance count subcondition 6 register).
 * @details Writes a value to the PMSUBCND6 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMSUBCND6
static void __set_PMSUBCND6 (uint32_t value)
{
    ldsr r6, 6, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND6 (Performance count subcondition 6 register).
 * @details Reads the current value of the PMSUBCND6 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMSUBCND6
static uint32_t __get_PMSUBCND6 (void)
{
    stsr 6, r10, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set PMSUBCND7 (Performance count subcondition 7 register).
 * @details Writes a value to the PMSUBCND7 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_PMSUBCND7
static void __set_PMSUBCND7 (uint32_t value)
{
    ldsr r6, 7, 15
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get PMSUBCND7 (Performance count subcondition 7 register).
 * @details Reads the current value of the PMSUBCND7 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_PMSUBCND7
static uint32_t __get_PMSUBCND7 (void)
{
    stsr 7, r10, 15
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
#pragma inline_asm __set_LSTEST0
static void __set_LSTEST0 (uint32_t value)
{
    ldsr r6, 0, 12
}

/**
 * @brief Get LSTEST0 (Lock-step function self-diagnosis register 0).
 * @details Reads the current value of the LSTEST0 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_LSTEST0
static uint32_t __get_LSTEST0 (void)
{
    stsr 0, r10, 12
}

/**
 * @brief Set LSTEST1 (Lock-step function self-diagnosis register 1).
 * @details Writes a value to the LSTEST1 system register.
 * @param[in] value uint32_t input.
 */
#pragma inline_asm __set_LSTEST1
static void __set_LSTEST1 (uint32_t value)
{
    ldsr r6, 1, 12
}

/**
 * @brief Get LSTEST1 (Lock-step function self-diagnosis register 1).
 * @details Reads the current value of the LSTEST1 system register.
 * @return uint32_t register value.
 *
 */
#pragma inline_asm  __get_LSTEST1
static uint32_t __get_LSTEST1 (void)
{
    stsr 1, r10, 12
}

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get LSCFG (Lock-step function configuration).
 * @details Reads the current value of the LSCFG system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_LSCFG
static uint32_t __get_LSCFG (void)
{
    stsr 2, r10, 12
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set IFCR (Instruction fetch control register).
 * @details Writes a value to the IFCR system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_IFCR
static void __set_IFCR (uint32_t value)
{
    ldsr r6, 5, 12
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get IFCR (Instruction fetch control register).
 * @details Reads the current value of the IFCR system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_IFCR
static uint32_t __get_IFCR (void)
{
    stsr 5, r10, 12
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set BRPCTRL0 (Branch prediction function control register).
 * @details Writes a value to the BRPCTRL0 system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_BRPCTRL0
static void __set_BRPCTRL0 (uint32_t value)
{
    ldsr r6, 8, 12
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get BRPCTRL0 (Branch prediction function control register).
 * @details Reads the current value of the BRPCTRL0 system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_BRPCTRL0
static uint32_t __get_BRPCTRL0 (void)
{
    stsr 8, r10, 12
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get L1RCFG (L1RAM configuration).
 * @details Reads the current value of the L1RCFG system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_L1RCFG
static uint32_t __get_L1RCFG (void)
{
    stsr 12, r10, 13
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Set RDBCR (ROM data buffer control register).
 * @details Writes a value to the RDBCR system register.
 * @param[in] value uint32_t input.
 */
 #pragma inline_asm __set_RDBCR
static void __set_RDBCR (uint32_t value)
{
    ldsr r6, 24, 13
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get RDBCR (ROM data buffer control register).
 * @details Reads the current value of the RDBCR system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_RDBCR
static uint32_t __get_RDBCR (void)
{
    stsr 24, r10, 13
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
 #pragma inline_asm __set_HVCFG
static void __set_HVCFG (uint32_t value)
{
    ldsr r6, 16, 1
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

#if defined(__RH850_G4MH) && (__RH850_G4MH == 1)

/**
 * @brief Get HVCFG (Setting virtualization support function).
 * @details Reads the current value of the HVCFG system register.
 * @return uint32_t register value.
 *
 */
 #pragma inline_asm  __get_HVCFG
static uint32_t __get_HVCFG (void)
{
    stsr 16, r10, 1
}

#endif                                 /* #if defined(__RH850_G4MH) && (__RH850_G4MH == 1) */

/** @} end of group CCRH_RH850_Core_RegAccFunctions */

/** @} end of group RH850_Core_FunctionInterface */

/* Include the profile specific settings: */
#include "G4-profile/rh850_ccrh_g4.h"

#endif                                 /* __RH850_CCRH_H */
