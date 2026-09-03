/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_CACHE_H
#define BSP_CACHE_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_DCACHE_INV          (0ul)
#define BSP_PRV_DCACHE_CLEAN        (1ul)
#define BSP_PRV_DCACHE_CLEAN_INV    (2ul)

/* Function-like macro used to wait for a condition to be met, most often used to wait for hardware register updates.
 * This macro can be redefined to add a timeout if necessary. */
#ifndef FSP_HARDWARE_REGISTER_WAIT
 #define FSP_HARDWARE_REGISTER_WAIT(reg, required_value)    while (reg != required_value) { /* Wait. */}
#endif

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
void R_BSP_CacheClean(void);
void R_BSP_CacheInvalidate(void);
void R_BSP_CacheCleanInvalidate(void);

/*******************************************************************************************************************//**
 * Cache operation to all area.
 *
 * @param[in] operate        Cache operation.
 *                           BSP_PRV_DCACHE_INV(0)       - Cache invalidate.
 *                           BSP_PRV_DCACHE_CLEAN(1)     - Cache clean.
 *                           BSP_PRV_DCACHE_CLEAN_INV(2) - Cache clean and invalidate.
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_cache_operate_all (uint8_t operate)
{
    switch (operate)
    {
        case BSP_PRV_DCACHE_INV:
        {
            /* Flush the cache. */
            R_CACHE->OACACTL =
                (uint32_t) ((R_CACHE->OACACTL & ~R_CACHE_OACACTL_FL_Msk) | (1U << R_CACHE_OACACTL_FL_Pos));

            /* Wait for the cache to flush. */
            FSP_HARDWARE_REGISTER_WAIT(R_CACHE->OACAFCT_b.FL, 0U);
            break;
        }

        case BSP_PRV_DCACHE_CLEAN:
        {
            /* Clean the cache. */
            R_CACHE->OACACTL =
                (uint32_t) ((R_CACHE->OACACTL & ~R_CACHE_OACACTL_WB_Msk) | (1U << R_CACHE_OACACTL_WB_Pos));

            /* Wait for the cache to clean. */
            FSP_HARDWARE_REGISTER_WAIT(R_CACHE->OACAFCT_b.WB, 0U);
            break;
        }

        case BSP_PRV_DCACHE_CLEAN_INV:
        {
            /* Clean and flush the cache. */
            R_CACHE->OACACTL = (uint32_t) ((R_CACHE->OACACTL & ~(R_CACHE_OACACTL_WB_Msk | R_CACHE_OACACTL_FL_Msk)) |
                                           (1U << R_CACHE_OACACTL_WB_Pos) | (1U << R_CACHE_OACACTL_FL_Pos));

            /* Wait for the cache to clean and flush. */
            FSP_HARDWARE_REGISTER_WAIT(R_CACHE->OACAFCT, 0U);
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * Enable Data cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheEnableData (void)
{
    /* Enable the cache. */
    R_CACHE->OACACTL = (uint32_t) ((R_CACHE->OACACTL & ~R_CACHE_OACACTL_EN_Msk) | (1U << R_CACHE_OACACTL_EN_Pos));
}

/*******************************************************************************************************************//**
 * Disable Data cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheDisableData (void)
{
    /* Disable the cache. */
    R_CACHE->OACACTL = (uint32_t) ((R_CACHE->OACACTL & ~R_CACHE_OACACTL_EN_Msk) | (0U << R_CACHE_OACACTL_EN_Pos));
}

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
 *  Clean and invalidate the whole of data cache.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_CacheCleanInvalidateAllData (void)
{
    bsp_cache_operate_all(BSP_PRV_DCACHE_CLEAN_INV);
}

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
