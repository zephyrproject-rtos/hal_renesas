/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"                   /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */
#include "bsp_module_standby.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_STANDBY_WAKEUP_MASK_REG_DEFAULT_VALUE    (0xFFFFFFFFU) /* PRQA S 1534 # Advisory R-2.5 */ ///< Default value of wake up factor mask register

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void bsp_stbc_set_channel(bsp_module_standby_t module, uint32_t channel, bool enable);
static void bsp_stbc_set_channels(bsp_module_standby_t module, bool enable);

static void bsp_stbc_module_operation_in_stop_mode(bsp_module_stopmode_t        module,
                                                   bsp_module_stopmode_config_t operation);
static void bsp_stbc_write_with_protection(volatile uint32_t * p_msr_address, uint32_t value);
static void bsp_halt(void);
static void bsp_stop_mode(void);

#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)
static void bsp_deep_stop_mode(void);

#endif

/** Array contains all registers' address of WakeUp factor 0 */
uint32_t r_bsp_run_mode_wakeup_reg[] = /* PRQA S 3408, 1504 # DP_MSR_R-8.4_UC1, Advisory R-8.7 */
{
    (uint32_t) &(R_WUF->WUFMSK0_A0),   /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFMSK0_A1),   /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFMSK0_A2),   /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFMSK0_I0),   /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFMSK0_I1),   /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 5U)
    (uint32_t) &(R_WUF->WUFMSK0_I2),   /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 6U)
    (uint32_t) &(R_WUF->WUFMSK0_I3),   /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #endif
#endif
    (uint32_t) &(R_WUF->WUFC0_A0),     /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFC0_A1),     /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFC0_A2),     /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFC0_I0),     /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFC0_I1),     /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 5U)
    (uint32_t) &(R_WUF->WUFC0_I2),     /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 6U)
    (uint32_t) &(R_WUF->WUFC0_I3),     /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #endif
#endif
    (uint32_t) &(R_WUF->WUF0_A0),      /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUF0_A1),      /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUF0_A2),      /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUF0_I0),      /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUF0_I1),      /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 5U)
    (uint32_t) &(R_WUF->WUF0_I2),      /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 6U)
    (uint32_t) &(R_WUF->WUF0_I3)       /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #endif
#endif
};

/** Array contains all registers' address of WakeUp factor 1 */
uint32_t r_bsp_cyclicrun_mode_wakeup_reg[] = /* PRQA S 3408, 1504 # DP_MSR_R-8.4_UC1, Advisory R-8.7 */
{
    (uint32_t) &(R_WUF->WUFMSK1_A0),         /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFMSK1_A1),         /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFMSK1_A2),         /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFMSK1_I0),         /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFMSK1_I1),         /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 5U)
    (uint32_t) &(R_WUF->WUFMSK1_I2),         /* PRQA S 0330, 0306, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 6U)
    (uint32_t) &(R_WUF->WUFMSK1_I3),         /* PRQA S 0330, 0306, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #endif
#endif
    (uint32_t) &(R_WUF->WUFC1_A0),           /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFC1_A1),           /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFC1_A2),           /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFC1_I0),           /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUFC1_I1),           /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 5U)
    (uint32_t) &(R_WUF->WUFC1_I2),           /* PRQA S 0330, 0306, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 6U)
    (uint32_t) &(R_WUF->WUFC1_I3),           /* PRQA S 0330, 0306, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #endif
#endif
    (uint32_t) &(R_WUF->WUF1_A0),            /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUF1_A1),            /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUF1_A2),            /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUF1_I0),            /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    (uint32_t) &(R_WUF->WUF1_I1),            /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 5U)
    (uint32_t) &(R_WUF->WUF1_I2),            /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE > 6U)
    (uint32_t) &(R_WUF->WUF1_I3)             /* PRQA S 0306, 0330, 0662 # Advisory R-11.4, Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #endif
#endif
};

/** Array contains all functions' pointer used in RUN Mode */
void (* r_bsp_mcu_standby_mode_funcs[BSP_MCU_STANDBY_MODE_INDEX_END])(void) = /* PRQA S 3408, 1514 # DP_MSR_R-8.4_UC1, Advisory R-8.7 & Advisory R-8.9 */
{
    [BSP_MCU_STANDBY_MODE_HALT] = &bsp_halt,                                  ///< Entry for HALT standby mode handler
    [BSP_MCU_STANDBY_MODE_STOP] = &bsp_stop_mode,                             ///< Entry for STOP standby mode handler
#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)
    [BSP_MCU_STANDBY_MODE_DEEPSTOP] = &bsp_deep_stop_mode                     ///< Entry for DEEPSTOP standby mode handler
#endif
};

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_MODULE_STANDBY
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/*******************************************************************************************************************//**
 * Enable supply clock of all configured Module standby that is enabled on BSP MDF.
 **********************************************************************************************************************/
void R_BSP_ModuleStandbyEnableAll (void) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint8_t msr_reg_count;
    uint8_t total_msr;

    /* Get total of g_msr_info_table elements */
    total_msr = (uint8_t) (sizeof(g_msr_info_table) / sizeof(g_msr_info_table[0]));

    /* Loop all configured Module standby for initialization. Skip the first element BSP_MODULE_STANDBY_START */
    for (msr_reg_count = 0U; msr_reg_count < total_msr; msr_reg_count++)
    {
        /* Get Module standby initial configured value of specific module */
        /* If enable Module standby, process to enable clock supply */
        bsp_stbc_set_channels((bsp_module_standby_t) msr_reg_count, true); /* PRQA S 4342 # Advisory R-10.5 */
    }
}

/*******************************************************************************************************************//**
 * Disable all Clock supply, preparation for standby
 *
 **********************************************************************************************************************/
void R_BSP_ModuleStandbyDisableAll (void) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint8_t msr_reg_count;
    uint8_t total_msr;

    /* Get total of g_msr_info_table elements */
    total_msr = (uint8_t) (sizeof(g_msr_info_table) / sizeof(g_msr_info_table[0]));

    /* Loop all configured Module standby for initialization. Skip the first element BSP_MODULE_STANDBY_START */
    for (msr_reg_count = 0U; msr_reg_count < total_msr; msr_reg_count++)
    {
        /* Disable clock supply to target module */
        bsp_stbc_set_channels((bsp_module_standby_t) msr_reg_count, false); /* PRQA S 4342 # Advisory R-10.5 */
    }
}

/*******************************************************************************************************************//**
 * Enable clock supply for input module. Module Standby Register for
 * target module MSR_<module name>.
 *
 * @param[in] module      Module to enable supply clock
 * @param[in] channel     The channel belongs to the target module
 **********************************************************************************************************************/
void R_BSP_ModuleStandbyEnable (bsp_module_standby_t module, uint32_t channel) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Enable clock supply to target module */
    bsp_stbc_set_channel(module, channel, true);
}

/*******************************************************************************************************************//**
 * Disable clock supply for input module. Module Standby Register for
 * target module MSR_<module name>.
 *
 * @param[in] module      Module to disable supply clock.
 * @param[in] channel     The channel belongs to the target module
 **********************************************************************************************************************/
void R_BSP_ModuleStandbyDisable (bsp_module_standby_t module, uint32_t channel) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Disable clock supply to target module */
    bsp_stbc_set_channel(module, channel, false);
}

/*******************************************************************************************************************//**
 * Clear and set wake up source for MCU. This function can only be used in RUN mode.
 *
 * @param[in] wake_src     Wake Up Factor.
 **********************************************************************************************************************/
void R_BSP_WakeupFactorClearAndSet (bsp_wk_factor_cfg_t wake_src) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    uint8_t num_of_factors;
    uint8_t wakeup_reg;
    uint8_t wakeup_reg_count;

    /* Clear Wake up Flag */
    for (wakeup_reg_count = 0U;
         wakeup_reg_count < BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE;
         wakeup_reg_count++)
    {
        *((volatile uint32_t *) r_bsp_run_mode_wakeup_reg[wakeup_reg_count +       /* PRQA S 0303 # Advisory R-11.4 */
                                                          (uint8_t) BSP_WK_REG_WUFC_A0]) = BSP_WAKEUP_FACTOR_MASK;
        *((volatile uint32_t *) r_bsp_cyclicrun_mode_wakeup_reg[wakeup_reg_count + /* PRQA S 0303 # Advisory R-11.4 */
                                                                (uint8_t) BSP_WK_REG_WUFC_A0]) = BSP_WAKEUP_FACTOR_MASK;
    }

    /* Mask all wake-up factor in RUN mode */
    for (num_of_factors = 0U; num_of_factors < BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE; num_of_factors++)
    {
        *((volatile uint32_t *) r_bsp_run_mode_wakeup_reg[num_of_factors + /* PRQA S 0303 # Advisory R-11.4 */
                                                          (uint8_t) BSP_WK_REG_WUFMSK_A0]) = BSP_WAKEUP_FACTOR_MASK;
    }

    /* Mask all wake-up factor in CYCLIC mode */
    for (num_of_factors = 0U; num_of_factors < BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE; num_of_factors++)
    {
        *((volatile uint32_t *) r_bsp_cyclicrun_mode_wakeup_reg[num_of_factors + /* PRQA S 0303 # Advisory R-11.4 */
                                                                (uint8_t) BSP_WK_REG_WUFMSK_A0]) =
            BSP_WAKEUP_FACTOR_MASK;
    }

    /* When a Wake-Up Factor is assigned to both Wake-Up Factor 0 registers and Wake-Up
     * Factor 1 registers, it can be used only in one of them. */

    /* Set wake up source for RUN mode */
    for (num_of_factors = 0U; num_of_factors < wake_src.num_of_wk_run_factor; num_of_factors++)
    {
        wakeup_reg = (uint8_t) wake_src.wk_run[num_of_factors] / BSP_WAKEUP_FACTOR_WORD;
        *((volatile uint32_t *) r_bsp_run_mode_wakeup_reg[wakeup_reg +                                              /* PRQA S 0303 # Advisory R-11.4 */
                                                          (uint8_t) BSP_WK_REG_WUFMSK_A0]) &=
            ~((uint32_t) BSP_WAKEUP_FACTOR_BIT_MASK << (wake_src.wk_run[num_of_factors] % BSP_WAKEUP_FACTOR_WORD)); /* PRQA S 4521 # DP_MSR_R-10.1_UC1 */
    }

    /* Set wake up source for CYCLIC mode */
    for (num_of_factors = 0U; num_of_factors < wake_src.num_of_wk_cyclicrun_factor; num_of_factors++)
    {
        wakeup_reg = (uint8_t) wake_src.wk_cyclicrun[num_of_factors] / BSP_WAKEUP_FACTOR_WORD;
        *((volatile uint32_t *) r_bsp_cyclicrun_mode_wakeup_reg[wakeup_reg +     /* PRQA S 0303 # Advisory R-11.4 */
                                                                (uint8_t) BSP_WK_REG_WUFMSK_A0]) &=
            ~((uint32_t) BSP_WAKEUP_FACTOR_BIT_MASK <<
              (wake_src.wk_cyclicrun[num_of_factors] % BSP_WAKEUP_FACTOR_WORD)); /* PRQA S 4521 # DP_MSR_R-10.1_UC1 */
    }
}

/*******************************************************************************************************************//**
 * Perform a MCU standby mode. This function can only be used in RUN mode.
 *
 * @param[in] mode      Standby Mode to be performed
 **********************************************************************************************************************/
void R_BSP_McuStandbyModeSet (bsp_mcu_standby_mode_t mode) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Call function via function pointer */
    r_bsp_mcu_standby_mode_funcs[mode]();

    __SYNCP();                                       /* PRQA S 3469 # Advisory D-4.9 */
}

/*******************************************************************************************************************//**
 * Get Wake Up Factor in DeepStop Mode and Stop Mode. This function can only be used in RUN Mode.
 *
 * @return     Wake Up Factor.
 **********************************************************************************************************************/
bsp_wk_factor_t R_BSP_WakeUpFactorGetAndClear (void) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    bsp_wk_factor_t factor = BSP_WK_FACTOR_NONE;
    uint8_t         wakeup_reg_count;

    /* Check whether it was waked up or not */
    if (0U != ((R_WUF->WUFMON) & BSP_WAKEUP_FACTOR_0_MONITOR_MASK))                                              /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    {
        uint8_t bit_one_pos    = ((uint8_t) __SCH1R(((R_WUF->WUFMON) & BSP_WAKEUP_FACTOR_0_MONITOR_MASK)) - 1U); /* PRQA S 0306, 0662, 4394 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.8_UC1 */
        uint8_t wakeup_bit_pos = ((uint8_t)
                                  __SCH1R(*((volatile uint32_t *) r_bsp_run_mode_wakeup_reg[bit_one_pos +        /* PRQA S 0303 # Advisory R-11.4 */
                                                                                            (uint8_t) BSP_WK_REG_WUF_A0]))
                                  -
                                  1U);
        factor =
            (bsp_wk_factor_t) (wakeup_bit_pos + (bit_one_pos * BSP_WAKEUP_FACTOR_WORD) + /* PRQA S 4342, 4394 # Advisory R-10.5, DP_MSR_R-10.8_UC1 */
                               BSP_STANDBY_WAKE_UP_FACTOR_A0_START);
    }

    /* Clear Wake up Flag */
    for (wakeup_reg_count = 0U;
         wakeup_reg_count < BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE;
         wakeup_reg_count++)
    {
        *((volatile uint32_t *) r_bsp_run_mode_wakeup_reg[wakeup_reg_count +       /* PRQA S 0303 # Advisory R-11.4 */
                                                          (uint8_t) BSP_WK_REG_WUFC_A0]) = BSP_WAKEUP_FACTOR_MASK;
        *((volatile uint32_t *) r_bsp_cyclicrun_mode_wakeup_reg[wakeup_reg_count + /* PRQA S 0303 # Advisory R-11.4 */
                                                                (uint8_t) BSP_WK_REG_WUFC_A0]) = BSP_WAKEUP_FACTOR_MASK;
    }

    return factor;
}

#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)

/*******************************************************************************************************************//**
 * Hold I/O Port State before enter DeepStop. This function can only be used in RUN Mode.
 *
 * @param[in] io_buffer      I/0 Port.
 **********************************************************************************************************************/
void R_BSP_SetIOBufferHold (bsp_io_hold_t io_buffer)   /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    R_SYS0_STBC->STBCKCPROT = BSP_PRV_KEYCODE_ENABLE;  /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    if (BSP_IO_HOLD_CLEAR_ALL == io_buffer)
    {
        R_SYS0_A_STBC->IOHOLD0 = BSP_IOHOLD_CLEAR_ALL; /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #if (1U == BSP_FEATURE_CHIP_STANDBY_IOHOLD_REG_NAME)
        R_SYS0_A_STBC->IOHOLD1 = BSP_IOHOLD_CLEAR_ALL; /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #elif (2U == BSP_FEATURE_CHIP_STANDBY_IOHOLD_REG_NAME)
        R_SYS0_A_STBC->IOHOLD2 = BSP_IOHOLD_CLEAR_ALL; /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
 #endif
    }
    else
    {
        if ((uint8_t) io_buffer >= BSP_WAKEUP_FACTOR_WORD)
        {
 #if (1U == BSP_FEATURE_CHIP_STANDBY_IOHOLD_REG_NAME)
            R_SYS0_A_STBC->IOHOLD1 |=                                                          /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                      ((uint32_t) 1U << (io_buffer % BSP_WAKEUP_FACTOR_WORD)); /* PRQA S 4521 # DP_MSR_R-10.1_UC1 */
 #elif (2U == BSP_FEATURE_CHIP_STANDBY_IOHOLD_REG_NAME)
            R_SYS0_A_STBC->IOHOLD2 |=                                                          /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                      ((uint32_t) 1U << (io_buffer % BSP_WAKEUP_FACTOR_WORD)); /* PRQA S 4521 # DP_MSR_R-10.1_UC1 */
 #endif
        }
        else
        {
            R_SYS0_A_STBC->IOHOLD0 |=                                                          /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
                                      ((uint32_t) 1U << (io_buffer % BSP_WAKEUP_FACTOR_WORD)); /* PRQA S 4521 # DP_MSR_R-10.1_UC1 */
        }
    }

    R_SYS0_STBC->STBCKCPROT = BSP_PRV_KEYCODE_DISABLE;                                         /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

#endif

/*******************************************************************************************************************//**
 * Enable/Disable the operation of target module clock in STOP, Deep STOP and Cyclic STOP mode
 * target module MSR_<module name>.
 *
 * @param[in] module      Target module clock in STOP, Deep STOP and Cyclic STOP mode for operation
 * @param[in] operation   Enable/Disable the operation of target module clock in STOP, Deep STOP and Cyclic STOP mode
 **********************************************************************************************************************/
void R_BSP_ModuleOperationStopMode (bsp_module_stopmode_t module, bsp_module_stopmode_config_t operation) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    bsp_stbc_module_operation_in_stop_mode(module, operation);
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief Configures the channel setting for a specific STBC module.
 *
 * Enables or disables the specified channel for the given STBC module.
 *
 * @param[in] module   Target STBC module to configure.
 * @param[in] channel  Channel index to be set.
 * @param[in] enable   Enable (true) or disable (false) the specified channel.
 **********************************************************************************************************************/
static void bsp_stbc_set_channel (bsp_module_standby_t module, uint32_t channel, bool enable)
{
    volatile uint32_t * p_msr_address;
    uint32_t            setting_value;

    /* Get the MSR module register address */
    p_msr_address = (volatile uint32_t *) (g_msr_info_table[module].msr_reg_address);

    /* Enable/Disable clock supply to target module */
    if (enable)
    {
        setting_value = (*p_msr_address & ~((uint32_t) 1U << channel));
    }
    else
    {
        setting_value = (*p_msr_address | ((uint32_t) 1U << channel));
    }

    /* Write the setting value */
    bsp_stbc_write_with_protection(p_msr_address, setting_value);
}

/*******************************************************************************************************************//**
 * Configures the STBC module with the specified module.
 *
 * @param[in] module       Module to enable supply clock.
 * @param[in] enable       Enable/Disable supply clock for the target.
 **********************************************************************************************************************/
static void bsp_stbc_set_channels (bsp_module_standby_t module, bool enable)
{
    volatile uint32_t * p_msr_address;
    uint32_t            setting_value;
    uint32_t            default_value;

    p_msr_address = (volatile uint32_t *) (g_msr_info_table[module].msr_reg_address);

    if (enable)
    {
        /* If enabled, retrieve the initial value from the configuration. */
        setting_value = g_msr_info_table[module].initial_cfg_value;
    }
    else
    {
        /* If disabled, retrieve the default value for each module. */
        default_value = (uint32_t) (g_msr_info_table[module].default_value | \
                                    ((uint32_t) 1U << BSP_MODULE_MSR_STPMSK_Pos));
        setting_value = (uint32_t) (*p_msr_address | default_value);
    }

    /* Write the setting value */
    bsp_stbc_write_with_protection(p_msr_address, setting_value);
}

/*******************************************************************************************************************//**
 * @brief Configures the operation mode of an STBC module during stop mode.
 *
 * Sets the behavior of the specified STBC module when the system enters stop mode,
 * based on the provided operation configuration.
 *
 * @param[in] module     Target STBC module to configure.
 * @param[in] operation   Operation mode to apply during stop mode.
 **********************************************************************************************************************/
static void bsp_stbc_module_operation_in_stop_mode (bsp_module_stopmode_t        module,
                                                    bsp_module_stopmode_config_t operation)
{
    volatile uint32_t * p_msr_address;
    uint32_t            setting_value;

    /* Get the MSR module register address */
    p_msr_address = (volatile uint32_t *) (g_msr_info_table[module].msr_reg_address);

    /* Setting the operation of target module clock in STOP mode */
    if (BSP_MODULE_CLOCK_SUPPLIED != operation)
    {
        setting_value = *p_msr_address & ~((uint32_t) 1U << BSP_MODULE_MSR_STPMSK_Pos);
    }
    else
    {
        setting_value = *p_msr_address | ((uint32_t) 1U << BSP_MODULE_MSR_STPMSK_Pos);
    }

    /* Write the setting value */
    bsp_stbc_write_with_protection(p_msr_address, setting_value);
}

/*******************************************************************************************************************//**
 * @brief Writes a value to a protected STBC register.
 *
 * Enables write access to the specified STBC register, writes the given value,
 * and then disables write access to ensure register protection.
 *
 * @param[in] p_msr_address  Pointer to the target STBC register address.
 * @param[in] value          Value to be written to the register.
 **********************************************************************************************************************/
static void bsp_stbc_write_with_protection (volatile uint32_t * p_msr_address, uint32_t value)
{
    /* Enable write access to protected registers */
    R_SYS0_STBC->MSRKCPROT = (uint32_t) BSP_PRV_KEYCODE_ENABLE; /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    *p_msr_address = value;

    /* Disable write access to protected registers */
    R_SYS0_STBC->MSRKCPROT = (uint32_t) BSP_PRV_KEYCODE_DISABLE; /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    __SYNCP();                                                   /* PRQA S 3469 # Advisory D-4.9 */
}

/*******************************************************************************************************************//**
 * Stop Mode feature. Depending on operation parameter, this function will set wakeup factor or perform Stop operation
 * This function can only be used in RUN Mode
 **********************************************************************************************************************/
static void bsp_stop_mode (void)
{
    /* Disable Interrupt */
    __DI();                            /* PRQA S 3469 # Advisory D-4.9 */

    /* Gear down clock */
    bsp_clock_gear_down();

    /* Reset Wake Up Factor Flag */
    R_BSP_McuResetClearFlags();

    R_SYS0_A_STBC->PWRGD_CNT = BSP_WAIT_TIME_FOR_VDD_STABLE;            /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Transition to Stop */
    R_SYS0_STBC->STBCKCPROT  = BSP_PRV_KEYCODE_ENABLE;                  /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    R_SYS0_A_STBC->STBC0STPT = R_SYS0_A_STBC_STBC0STPT_STBC0STPTRG_Msk; /* PRQA S 0306, 0662, 1257 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */
    R_SYS0_STBC->STBCKCPROT  = BSP_PRV_KEYCODE_DISABLE;                 /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

/*******************************************************************************************************************//**
 * Enter Halt state. This function can only be used in RUN Mode.
 **********************************************************************************************************************/
static void bsp_halt (void)
{
    __HALT();                          /* PRQA S 3469 # Advisory D-4.9 */
}

#if (BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_IS_AVAILABLE)

/*******************************************************************************************************************//**
 * Enter DeepStop Mode. Depending on operation parameter, this function will set wakeup factor or perform DeepStop
 * operation
 * This function can only be used in RUN Mode.
 **********************************************************************************************************************/
static void bsp_deep_stop_mode (void)
{
 #if (BSP_CYCLICRUN_MODE_ENABLE) && (BSP_PE0_USED)

    /* PRQA S 1513 ++ # DP_MSR_R-8.5_UC1 */
    extern uint32_t g_cyclicrun_opbt_value[BSP_OPBT_NUMBER_OF_OPBT_REGS];

    /* PRQA S 1513 -- */

    /* If there is wake up source for Cyclic RUN mode. Prepare the OPBT value before entering the Cyclic RUN mode
     * since the data flash memory is not available in this mode. */
    for (uint8_t reg_index = 0U; reg_index < BSP_FEATURE_CHIP_STANDBY_DEEPSTOP_NUM_OF_WAKEUP_SOURCE; reg_index++)
    {
        uint32_t reg_value = *((volatile uint32_t *) r_bsp_cyclicrun_mode_wakeup_reg[reg_index]); /* PRQA S 0303 # Advisory R-11.4 */
        if (BSP_STANDBY_WAKEUP_MASK_REG_DEFAULT_VALUE != (reg_value & BSP_STANDBY_WAKEUP_MASK_REG_DEFAULT_VALUE))
        {
            R_BSP_OPBTRead(g_cyclicrun_opbt_value, BSP_OPBT_NUMBER_OF_OPBT_REGS);
            break;
        }
    }
 #endif                                /* #if (BSP_CYCLICRUN_MODE_ENABLE) && (BSP_PE0_USED) */ /* PRQA S 2053 # Advisory D-4.4 */

    /* Disable Interrupt */
    __DI();                            /* PRQA S 3469 # Advisory D-4.9 */

    /* Gear down clock */
    bsp_clock_gear_down();

    /* Reset Wake Up Factor Flag */
    R_BSP_McuResetClearFlags();

    R_SYS0_A_STBC->PWRGD_CNT = BSP_WAIT_TIME_FOR_VDD_STABLE;          /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */

    /* Transition to DeepStop */
    R_SYS0_STBC->STBCKCPROT = BSP_PRV_KEYCODE_ENABLE;                 /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
    R_SYS0_A_STBC->STBC0PSC = R_SYS0_A_STBC_STBC0PSC_STBC0DISTRG_Msk; /* PRQA S 0306, 0662, 1257 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1, DP_MSR_R-10.3_UC1 */
    R_SYS0_STBC->STBCKCPROT = BSP_PRV_KEYCODE_DISABLE;                /* PRQA S 0306, 0662 # Advisory R-11.4, DP_MSR_D-1.1_UC1 & DP_MSR_R-1.2_UC1 */
}

#endif

/** @} (end addtogroup BSP_MODULE_STANDBY) */
