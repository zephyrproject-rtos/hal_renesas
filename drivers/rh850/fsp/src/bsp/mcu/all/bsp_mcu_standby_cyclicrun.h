/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MCU_STANDBY_CYCLICRUN_H
#define BSP_MCU_STANDBY_CYCLICRUN_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_STANDBY_CRUN BSP MCU Standby Mode - Cyclic RUN mode
 * @brief This section provides basic function that required in Cyclic Run Mode for the MCU to behave normally.
 *        They are Software Delay, Io Port, Interrupt, Clock controller, Standby controller, FPU/FXU initialize and
 *        Instruction cache.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

#if (BSP_CYCLICRUN_MODE_ENABLE) && (BSP_PE0_USED)
 #include "bsp_mcu_standby_cyclicrun_driver.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Available delay units for R_BSP_SoftwareDelay(). These are ultimately used to calculate a total # of microseconds */
typedef enum e_bsp_cyclicrun_delay_units          /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_CYCLIC_DELAY_UNITS_MICROSECONDS = 1,      ///< Requested delay amount is in microseconds
    BSP_CYCLIC_DELAY_UNITS_MILLISECONDS = 1000,   ///< Requested delay amount is in milliseconds
    BSP_CYCLIC_DELAY_UNITS_SECONDS      = 1000000 ///< Requested delay amount is in seconds
} bsp_cyclicrun_delay_units_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
BSP_PRAGMA_PLACE_IN_SECTION(BSP_PRAGMA_SECTION_CRUN_DATA,
                            BSP_PRAGMA_SECTION_CRUN_CODE_DATA BSP_PRAGMA_MEMORY_ATTRIBUTE_LARGE)

extern R_PORT_Type * R_BSP_CyclicRun_PORT_TYPE[]; /* PRQA S 3684 # Advisory R-8.11 */

BSP_PRAGMA_PLACE_IN_SECTION(BSP_PRAGMA_SECTION_CRUN_DATA, BSP_PRAGMA_SECTION_DEFAULT)

BSP_PRAGMA_PLACE_IN_SECTION(BSP_PRAGMA_SECTION_CRUN_BSS,
                            BSP_PRAGMA_SECTION_CRUN_CODE_BSS BSP_PRAGMA_MEMORY_ATTRIBUTE_LARGE)

extern void * gp_renesas_cyclicrun_isr_context[BSP_INT_VECTOR_MAX_ENTRIES];

BSP_PRAGMA_PLACE_IN_SECTION(BSP_PRAGMA_SECTION_CRUN_BSS, BSP_PRAGMA_SECTION_DEFAULT)

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* Software Delay */
void R_BSP_CyclicRunSoftwareDelay(uint32_t delay, bsp_cyclicrun_delay_units_t units);

/* Interrupt controller */
void    * R_FSP_CyclicRunIsrContextGet(IRQn_Type const irq);
void      R_FSP_CyclicRunIsrContextSet(IRQn_Type const irq, void * p_context);
void      R_BSP_CyclicRunIrqEnable(IRQn_Type const irq);
void      R_BSP_CyclicRunIrqDisable(IRQn_Type const irq);
void      R_BSP_CyclicRunIrqCfg(IRQn_Type const irq, uint32_t priority, void * p_context);
void      R_BSP_CyclicRunIrqCfgEnable(IRQn_Type const irq, uint16_t priority, void * p_context);
IRQn_Type R_FSP_CyclicRunCurrentIrqGet(void);
void      bsp_cyclicrun_irq_cfg(void);

BSP_INTERRUPT_ATTRIBUTE void DummyIsr_CyclicRun(void);

/* Clock controller */
void     R_BSP_CyclicRunInitClock(void);
uint32_t R_FSP_CyclicRunSystemClockHzGet(fsp_priv_clock_cyclicrun_t clock); /* PRQA S 4604 # DP_MSR_R-21.2_UC1 */

/* IO Port */
void     R_BSP_CyclicRunPortWriteEnable(bsp_io_port_t port);
void     R_BSP_CyclicRunPortWriteDisable(bsp_io_port_t port);
void     R_BSP_CyclicRunPinAccessEnable();  /* PRQA S 3001 # DP_MSR_R-8.2_UC1 & DP_MSR_R-1.5_UC1 */
void     R_BSP_CyclicRunPinAccessDisable(); /* PRQA S 3001 # DP_MSR_R-8.2_UC1 & DP_MSR_R-1.5_UC1 */
uint32_t R_BSP_CyclicRunPinRead(bsp_io_port_pin_t pin);
void     R_BSP_CyclicRunPinWrite(bsp_io_port_pin_t pin, bsp_io_level_t level);
void     R_BSP_CyclicRunPinToggle(bsp_io_port_pin_t pin);
void     R_BSP_CyclicRunPinCfg(bsp_io_port_pin_t pin, uint32_t cfg);

/* Standby controller */
void            R_BSP_CyclicRunModuleStandbyEnableAll(void);  /* PRQA S 1712 # DP_MSR_R-5.1_UC1 */
void            R_BSP_CyclicRunModuleStandbyDisableAll(void); /* PRQA S 1712 # DP_MSR_R-5.1_UC1 */
void            R_BSP_CyclicRunModuleStandbyEnable(bsp_module_standby_t module, uint32_t channel);
void            R_BSP_CyclicRunModuleStandbyDisable(bsp_module_standby_t module, uint32_t channel);
void            R_BSP_CyclicRunSetIOBufferHold(bsp_io_hold_t io_buffer);
bsp_wk_factor_t R_BSP_CyclicRunWakeUpFactorGetAndClear(void);
void            R_BSP_CyclicRunWakeupFactorClearAndSet(bsp_wk_factor_cfg_t wake_src);
void            R_BSP_CyclicRunMcuStandbyModeSet(bsp_mcu_standby_mode_t mode);

/* FPU/FXU */
void R_BSP_CyclicRunFPUInit(void);                   /* PRQA S 3449, 3451 # DP_MSR_R-8.5_UC1, DP_MSR_R-8.5_UC1 */
void R_BSP_CyclicRunFXUInit(void);                   /* PRQA S 3449, 3451 # DP_MSR_R-8.5_UC1, DP_MSR_R-8.5_UC1 */

/* Instruction cache */
void R_BSP_CyclicRunMPUInstructionCacheEnable(void); /* PRQA S 1712 # DP_MSR_R-5.1_UC1 */
void R_BSP_CyclicRunMPUInstructionCacheDisable(void);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_MCU_STANDBY_CYCLICRUN_H */
#endif /* #if (BSP_CYCLICRUN_MODE_ENABLE) && (BSP_PE0_USED) */ /* PRQA S 2053 # Advisory D-4.4 */

/** @} (end addtogroup BSP_STANDBY_CRUN) */
