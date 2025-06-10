/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_CACHE_H
#define BSP_CACHE_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_SCTLR_I_BIT         (1ul << 12)
#define BSP_PRV_SCTLR_Z_BIT         (1ul << 11)
#define BSP_PRV_SCTLR_C_BIT         (1ul << 2)
#define BSP_PRV_ACTLR_SMP_BIT       (1ul << 6)

#define BSP_PRV_DCACHE_INV          (0ul)
#define BSP_PRV_DCACHE_CLEAN        (1ul)
#define BSP_PRV_DCACHE_CLEAN_INV    (2ul)

#define BSP_PRV_CACHE_LINE_SIZE     (32ul)
#define BSP_PRV_CACHE_LINE_MASK     (0xFFFFFFE0ul)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

void R_BSP_CacheEnable(void);
void R_BSP_CacheDisable(void);
void R_BSP_CacheInvalidate(void);

/*******************************************************************************************************************//**
 * Cache operation to all area.
 *
 * @param[in] operate        Cache operation.
 *                           BSP_PRV_DCACHE_INV(0) - Cache invalidate.
 *                           BSP_PRV_DCACHE_CLEAN(1) - Cache clean.
 *                           BSP_PRV_DCACHE_CLEAN_INV(2) - Cache clean & invalidate.
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_cache_operate_all (uint8_t operate)
{
    __asm volatile (
        "MOV  r0, %0                               \n"
        "MRC  p15, 1, r6, c0, c0, 1                \n" /* Read CLIDR */
        "ANDS r3, r6, #0x07000000                  \n" /* Extract coherency level */
        "MOV  r3, r3, LSR #23                      \n" /* Total cache levels << 1 */
        "BEQ  Complete                             \n" /* If 0, no need to clean */

        "MOV  r10, #0                              \n" /* R10 holds current cache level << 1 */
        "Cache_Loop:                               \n"
        "ADD  r2, r10, r10, LSR #1                 \n" /* R2 holds cache "Set" position */
        "MOV  r1, r6, LSR r2                       \n" /* Bottom 3 bits are the Cache-type for this level */
        "AND  r1, r1, #7                           \n" /* Isolate those lower 3 bits */
        "CMP  r1, #2                               \n"
        "BLT  Skip                                 \n" /* No cache or only instruction cache at this level */

        "MCR  p15, 2, r10, c0, c0, 0               \n" /* Write the Cache Size selection register (CSSELR) */
        "ISB                                       \n" /* ISB to sync the change to the CacheSizeID reg */
        "MRC  p15, 1, r1, c0, c0, 0                \n" /* Reads current Cache Size ID register (CCSIDR) */
        "AND  r2, r1, #7                           \n" /* Extract the line length field */
        "ADD  r2, r2, #4                           \n" /* Add 4 for the line length offset (log2 16 bytes) */
        "LDR  r4, =0x3FF                           \n"
        "ANDS r4, r4, r1, LSR #3                   \n" /* R4 is the max number on the way size (right aligned) */
        "CLZ  r5, r4                               \n" /* R5 is the bit position of the way size increment */
        "LDR  r7, =0x7FFF                          \n"
        "ANDS r7, r7, r1, LSR #13                  \n" /* R7 is the max number of the index size (right aligned) */
        "Way_Loop:                                 \n"
        "MOV  r9, r4                               \n" /* R9 working copy of the max way size (right aligned) */

        "Set_Loop:                                 \n"
        "LSL  r12, r9, r5                          \n"
        "ORR  r11, r10, r12                        \n" /* Factor in the Way number and cache number into R11 */
        "LSL  r12, r7, r2                          \n"
        "ORR  r11, r11, r12                        \n" /* Factor in the Set number */
        "CMP  r0, #0                               \n"
        "BNE  Dccsw                                \n"
        "MCR  p15, 0, r11, c7, c6, 2               \n" /* Invalidate by Set/Way (DCISW) */
        "B    Count                                \n"
        "Dccsw:                                    \n"
        "CMP  r0, #1                               \n"
        "BNE  Dccisw                               \n"
        "MCR  p15, 0, r11, c7, c10, 2              \n" /* Clean by set/way (DCCSW) */
        "B    Count                                \n"
        "Dccisw:                                   \n"
        "MCR  p15, 0, r11, c7, c14, 2              \n" /* Clean and Invalidate by set/way (DCCISW) */
        "Count:                                    \n"
        "SUBS r9, r9, #1                           \n" /* Decrement the Way number */
        "BGE  Set_Loop                             \n"
        "SUBS r7, r7, #1                           \n" /* Decrement the Set number */
        "BGE  Way_Loop                             \n"
        "Skip:                                     \n"
        "ADD  r10, r10, #2                         \n" /* increment the cache number */
        "CMP  r3, r10                              \n"
        "BGT  Cache_Loop                           \n"

        "Complete:                                 \n"
        "DSB                                       \n"
        ::"r" (operate) : "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12");
}

/*******************************************************************************************************************//**
 * Enable Instruction cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheEnableInst (void)
{
    __asm volatile (
        "MOV     r1, %[sctlr_i_bit]               \n"
        "MRC     p15, 0, r0, c1, c0, 0            \n" /* Read System Control Register */
        "ORR     r0, r0, r1                       \n" /* Enable I Cache */
        "MCR     p15, 0, r0, c1, c0, 0            \n" /* Write System Control Register */
        ::[sctlr_i_bit] "i" (BSP_PRV_SCTLR_I_BIT) : "r0", "r1");
}

/*******************************************************************************************************************//**
 * Enable Data cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheEnableData (void)
{
    __asm volatile (
        "MOV     r1, %[sctlr_c_bit]               \n"
        "MRC     p15, 0, r0, c1, c0, 0            \n" /* Read System Control Register */
        "ORR     r0, r0, r1                       \n" /* Enable D Cache */
        "MCR     p15, 0, r0, c1, c0, 0            \n" /* Write System Control Register */
        ::[sctlr_c_bit] "i" (BSP_PRV_SCTLR_C_BIT) : "r0", "r1");
}

/*******************************************************************************************************************//**
 * Disable Instruction cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheDisableInst (void)
{
    __asm volatile (
        "MOV     r1, %[sctlr_i_bit]               \n"
        "MRC     p15, 0, r0, c1, c0, 0            \n" /* Read System Control Register */
        "BIC     r0, r0, r1                       \n" /* Enable I Cache */
        "MCR     p15, 0, r0, c1, c0, 0            \n" /* Write System Control Register */
        ::[sctlr_i_bit] "i" (BSP_PRV_SCTLR_I_BIT) : "r0", "r1");
}

/*******************************************************************************************************************//**
 * Disable Data cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheDisableData (void)
{
    __asm volatile (
        "MOV     r1, %[sctlr_c_bit]               \n"
        "MRC     p15, 0, r0, c1, c0, 0            \n" /* Read System Control Register */
        "BIC     r0, r0, r1                       \n" /* Enable D Cache */
        "MCR     p15, 0, r0, c1, c0, 0            \n" /* Write System Control Register */
        ::[sctlr_c_bit] "i" (BSP_PRV_SCTLR_C_BIT) : "r0", "r1");
}

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Clean whole of the data cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheCleanAllData (void)
{
    bsp_cache_operate_all(BSP_PRV_DCACHE_CLEAN);
}

/*******************************************************************************************************************//**
 * Invalidate whole of the data cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheInvalidateAllData (void)
{
    bsp_cache_operate_all(BSP_PRV_DCACHE_INV);
}

/*******************************************************************************************************************//**
 * Invalidate whole of the instruction cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheInvalidateAllInst (void)
{
    __asm volatile (
        "MOV     r0, #0                           \n"
        "MCR     p15, 0, r0, c7, c5, 0            \n" /* ICIALLU */
        "DSB                                      \n"
        "ISB                                      \n"
        ::: "r0");
}

/*******************************************************************************************************************//**
 *  Clean and invalidate the whole of data cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheCleanInvalidateAllData (void)
{
    bsp_cache_operate_all(BSP_PRV_DCACHE_CLEAN_INV);
}

/*******************************************************************************************************************//**
 * Clean the cache for the specified area.
 *
 * @param[in] addr           Base address of area to clean.
 * @param[in] length         Length of area to clean.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheCleanRangeData (void * addr, uint32_t length)
{
    uint32_t line_addr;
    uint32_t end_addr;

    line_addr = (((uint32_t) addr) & BSP_PRV_CACHE_LINE_MASK);
    end_addr  = (line_addr + length);

    /* over flow check */
    if (end_addr > line_addr)
    {
        for ( ; line_addr < end_addr; line_addr += BSP_PRV_CACHE_LINE_SIZE)
        {
            __asm volatile (
                "MCR  p15, 0, %0, c7, c10, 1               \n" /* DCCMVAC */
                ::"r" (line_addr) :);
        }

        __asm volatile ("DMB");
    }
}

/*******************************************************************************************************************//**
 * Invalidate the cache for the specified area.
 *
 * @param[in] addr           Base address of area to invalidate.
 * @param[in] length         Length of area to invalidate.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheInvalidateRangeData (void * addr, uint32_t length)
{
    uint32_t line_addr;
    uint32_t end_addr;

    line_addr = (((uint32_t) addr) & BSP_PRV_CACHE_LINE_MASK);
    end_addr  = (line_addr + length);

    /* over flow check */
    if (end_addr > line_addr)
    {
        for ( ; line_addr < end_addr; line_addr += BSP_PRV_CACHE_LINE_SIZE)
        {
            __asm volatile (
                "MCR  p15, 0, %0, c7, c6, 1                \n" /* DCIMVAC */
                ::"r" (line_addr) :);
        }

        __asm volatile ("DMB");
    }
}

/*******************************************************************************************************************//**
 * Invalidate the instruction cache for the specified area.
 *
 * @param[in] addr           Base address of area to invalidate.
 * @param[in] length         Length of area to invalidate.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheInvalidateRangeInst (void * addr, uint32_t length)
{
    uint32_t line_addr;
    uint32_t end_addr;

    line_addr = (((uint32_t) addr) & BSP_PRV_CACHE_LINE_MASK);
    end_addr  = (line_addr + length);

    /* over flow check */
    if (end_addr > line_addr)
    {
        for ( ; line_addr < end_addr; line_addr += BSP_PRV_CACHE_LINE_SIZE)
        {
            __asm volatile (
                "MCR     p15, 0, %0, c7, c5, 1            \n" /* ICIMVAU */
                ::"r" (line_addr) :);
        }

        __asm volatile (
            "DMB                                     \n"
            "ISB                                     \n"
            );
    }
}

/*******************************************************************************************************************//**
 * Clean and invalidate the cache for the specified area.
 *
 * @param[in] addr           Base address of area to clean and invalidate.
 * @param[in] length         Length of area to clean and invalidate.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheCleanInvalidateRangeData (void * addr, uint32_t length)
{
    uint32_t line_addr;
    uint32_t end_addr;

    line_addr = (((uint32_t) addr) & BSP_PRV_CACHE_LINE_MASK);
    end_addr  = (line_addr + length);

    /* over flow check */
    if (end_addr > line_addr)
    {
        for ( ; line_addr < end_addr; line_addr += BSP_PRV_CACHE_LINE_SIZE)
        {
            __asm volatile (
                "MCR  p15, 0, %0, c7, c14, 1               \n" /* DCCIMVAC */
                ::"r" (line_addr) :);
        }

        __asm volatile ("DMB");
    }
}

/** @} (end addtogroup BSP_MCU) */

/*******************************************************************************************************************//**
 * Enable branch predictor.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheEnablePrediction (void)
{
    __asm volatile (
        "MOV     r1, %[sctlr_z_bit]               \n"
        "MRC     p15, 0, r0, c1, c0, 0            \n" /* Read System Control Register */
        "ORR     r0, r0, r1                       \n" /* Enable branch predictor */
        "MCR     p15, 0, r0, c1, c0, 0            \n" /* Write System Control Register */
        ::[sctlr_z_bit] "i" (BSP_PRV_SCTLR_Z_BIT) : "r0", "r1");
}

/*******************************************************************************************************************//**
 * Disable branch predictor.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheDisablePrediction (void)
{
    __asm volatile (
        "MOV     r1, %[sctlr_z_bit]               \n"
        "MRC     p15, 0, r0, c1, c0, 0            \n" /* Read System Control Register */
        "BIC     r0, r0, r1                       \n" /* Disable branch predictor */
        "MCR     p15, 0, r0, c1, c0, 0            \n" /* Write System Control Register */
        ::[sctlr_z_bit] "i" (BSP_PRV_SCTLR_Z_BIT) : "r0", "r1");
}

/*******************************************************************************************************************//**
 * Invalidate whole of the branch prediction table.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheInvalidateBtac (void)
{
    __asm volatile (
        "MOV     r0, #0                           \n"
        "MCR     p15, 0, r0, c7, c5, 6            \n" /* BPIALL */
        "DSB                                      \n"
        "ISB                                      \n"
        ::: "r0");
}

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
