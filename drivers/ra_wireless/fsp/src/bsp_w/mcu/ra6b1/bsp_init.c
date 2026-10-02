/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_ADDR_ALIGN_8K_MASK      (0xFFFFE000)
#define BSP_PRV_ADDR_ALIGN_8K_OFFSET    (0x00002000)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef void (* bsp_init_func_ptr)(void);

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
void ra6b1_SystemInitPostC(void);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
extern uint32_t __ddsc_FLASH_END;      // NOLINT

extern void R_BSP_WarmStart(bsp_warm_start_event_t event);

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

BSP_PLACE_CODE_IN_RAM static void configure_cache (void)
{
    uint32_t nvm_haddr;

    nvm_haddr = ((uint32_t) &__ddsc_FLASH_END) & BSP_PRV_ADDR_ALIGN_8K_MASK;

    if (((uint32_t) &__ddsc_FLASH_END) & ~BSP_PRV_ADDR_ALIGN_8K_MASK)
    {
        nvm_haddr += BSP_PRV_ADDR_ALIGN_8K_OFFSET;
    }

    CACHE->CACHE_NVM_MAX_CACHEABLE_ADDR  = nvm_haddr;
    CRG_TOP->SYS_CTRL_REG_b.CACHERAM_MUX = 1;

    /* Retain the system cache block configuration when the associated domain is off. */
    CRG_TOP->PMU_CTRL_REG_b.RETAIN_CACHE = 1;
}

__STATIC_FORCEINLINE void bsp_aon_core_pad_enable (void)
{
    /* Enable the input buffers that drive P0_16/P0_21 towards the
     * AON core modules, i.e. the RTC and the Wakeup-from-Hibernation Controller.
     */
    CRG_AON->HIBERN_CTRL_REG_b.WKUP_P0_16_IE = 1;
    CRG_AON->HIBERN_CTRL_REG_b.WKUP_P0_21_IE = 1;
}

void ra6b1_SystemInitPostC (void)
{
    /* FIXME: Freeze SYS WDOG */
    GPREG->SET_FREEZE_REG = GPREG_SET_FREEZE_REG_FRZ_SYS_WDOG_Msk;

    bsp_prv_halt_implementation_normal_set();

    bsp_aon_core_pad_enable();

#if !BSP_TZ_NONSECURE_BUILD
    configure_cache();
#endif

    /* Update SystemCoreClock and g_bsp_lp_clock variables. */
    SystemCoreClockUpdate();
    R_BSP_LPClockUpdate();

    /* Call Post C runtime initialization hook. */
    R_BSP_WarmStart(BSP_WARM_START_POST_C);

    // TODO: We must call SystemRuntimeInit for external memories here, however atm this function is internal in system.c.
    // SystemRuntimeInit(1);
}

/*
 * Add pointer to ra6b1_SystemInitPostC() in an array that will go in the .init_array section.
 * __libc_init_array() (which is called by _start()) calls all function pointers in .init_array.
 */
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
BSP_PLACE_IN_SECTION(BSP_SECTION_INIT) BSP_ALIGN_VARIABLE(__alignof__(bsp_init_func_ptr))
static bsp_init_func_ptr ra6b1_init_array_entry[] =
{
    ra6b1_SystemInitPostC,
};
#elif defined(__ICCARM__) || defined(__IAR_SYSTEMS_ICC)
BSP_DONT_REMOVE int __low_level_init (void)
{
    ra6b1_SystemInitPostC();

    /* Return 1 to initialize the data sections */
    return 1;
}

#endif

/** @} (end addtogroup BSP_MCU_PRV) */
