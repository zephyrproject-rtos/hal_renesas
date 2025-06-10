/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IRQ_H
#define BSP_IRQ_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include <zephyr/drivers/interrupt_controller/gic.h>
#include <zephyr/dt-bindings/interrupt-controller/arm-gic.h>

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_GIC_NONSHIFT_ACCESS    (0)

#define BSP_PRV_GIC_BITS2          (2U)
#define BSP_PRV_GIC_BITS8          (8U)

#define BSP_PRV_GIC_STRIDE04       (4U)
#define BSP_PRV_GIC_STRIDE16       (16U)
#define BSP_PRV_GIC_STRIDE32       (32U)

#define BSP_PRV_GIC_MASK_2BIT      (0x03U)
#define BSP_PRV_GIC_MASK_8BIT      (0xFFU)
#define BSP_PRV_GIC_MASK_32BIT     (0xFFFFFFFFU)

/* 1023 is special interrupt ID for GIC */
#define BSP_GIC_SPECIAL_ID         (1023)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern void * gp_renesas_isr_context[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES];
extern uint8_t g_gic_detect_type[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief      Sets the ISR context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ number (parameter checking must ensure the IRQ number is valid before calling this
 *                            function.
 * @param[in]  p_context      ISR context for IRQ.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_FSP_IsrContextSet (IRQn_Type const irq, void * p_context)
{
    /* This provides access to the ISR context array defined in bsp_irq.c. This is an inline function instead of
     * being part of bsp_irq.c for performance considerations because it is used in interrupt service routines. */
    gp_renesas_isr_context[irq] = p_context;
}

/*******************************************************************************************************************//**
 * @brief      Finds the ISR context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ number (parameter checking must ensure the IRQ number is valid before calling this
 *                            function.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 *
 * @return  ISR context for IRQ.
 **********************************************************************************************************************/
__STATIC_INLINE void * R_FSP_IsrContextGet (IRQn_Type const irq)
{
    /* This provides access to the ISR context array defined in bsp_irq.c. This is an inline function instead of
     * being part of bsp_irq.c for performance considerations because it is used in interrupt service routines. */
    return gp_renesas_isr_context[irq];
}

#if BSP_CFG_INLINE_IRQ_FUNCTIONS

/*******************************************************************************************************************//**
 * Sets the interrupt detect type.
 *
 * @param[in] irq             The IRQ number to configure.
 * @param[in] detect_type     GIC detect type of the interrupt
 *                            (BSP_GIC_SPI_DETECT_LEVEL : level-sensitive, BSP_GIC_SPI_DETECT_EDGE : edge-triggerd).
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqDetectTypeSet (IRQn_Type const irq, uint8_t detect_type)
{
    uint32_t idx;
    uint32_t shift;
    uint32_t val;
    uint8_t flags = detect_type ? IRQ_TYPE_EDGE : IRQ_TYPE_LEVEL;

    /* Interrupt type config */
    if (!GIC_IS_SGI(irq)) {
        idx = irq / GIC_NUM_CFG_PER_REG;
        shift = (irq & (GIC_NUM_CFG_PER_REG - 1)) * 2;

        val = sys_read32(GICD_ICFGRn + idx * 4);
        val &= ~(GICD_ICFGR_MASK << shift);
        if (flags & IRQ_TYPE_EDGE) {
            val |= (GICD_ICFGR_TYPE << shift);
        }
        sys_write32(val, GICD_ICFGRn + idx * 4);
    }
}

/*******************************************************************************************************************//**
 * Clear the interrupt status flag for a given interrupt.
 *
 * @note This function does not implement processing on this device.
 *
 * @param[in] irq            Not used
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqStatusClear (IRQn_Type irq)
{
    FSP_PARAMETER_NOT_USED(irq);

    /* Do nothing */
}

/*******************************************************************************************************************//**
 * Clear the GIC pending interrupt.
 *
 * @param[in] irq            Interrupt for which to clear the Pending bit. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exception when the IIRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqClearPending (IRQn_Type irq)
{
    /* Call GIC APIs provided by Zephyr */
    arm_gic_irq_clear_pending((unsigned int)irq);
}

/*******************************************************************************************************************//**
 * Get the GIC pending interrupt.
 *
 * @param[in] irq            Interrupt that gets a pending bit.. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 *
 * @return  Value indicating the status of the level interrupt.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_IrqPendingGet (IRQn_Type irq)
{
    return arm_gic_irq_is_pending((unsigned int)irq);
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context.
 *
 * @param[in] irq            The IRQ number to configure.
 * @param[in] priority       GIC priority of the interrupt
 * @param[in] p_context      The interrupt context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqCfg (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    /* Priority is already set with gic initialization, remove priority config in FSP to prevent override seting on Zephyr */
    FSP_PARAMETER_NOT_USED(priority);

    /* Store the context. The context is recovered in the ISR. */
    R_FSP_IsrContextSet(irq, p_context);
}

/*******************************************************************************************************************//**
 * Enable the IRQ in the GIC (Without clearing the pending bit).
 *
 * @param[in] irq            The IRQ number to enable. Note that the enums listed for IRQn_Type are only those for the
 *                           Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqEnableNoClear (IRQn_Type const irq)
{
    /* Call GIC APIs provided by Zephyr */
    arm_gic_irq_enable((unsigned int)irq);
}

/*******************************************************************************************************************//**
 * Enable the IRQ in the GIC (With clearing the pending bit).
 *
 * @param[in] irq            The IRQ number to enable. Note that the enums listed for IRQn_Type are only those for the
 *                           Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqEnable (IRQn_Type const irq)
{
    /* Clear pending interrupts in the GIC. */

    R_BSP_IrqClearPending(irq);

    /* Enable the interrupt in the GIC. */
    R_BSP_IrqEnableNoClear(irq);
}

/*******************************************************************************************************************//**
 * Disables interrupts in the GIC.
 *
 * @param[in] irq            The IRQ number to disable in the GIC. Note that the enums listed for IRQn_Type are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqDisable (IRQn_Type const irq)
{
    arm_gic_irq_disable((unsigned int)irq);
    __DSB();
    __ISB();
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority and context, clears pending interrupts, then enables the interrupt.
 *
 * @param[in] irq            Interrupt number.
 * @param[in] priority       GIC priority of the interrupt
 * @param[in] p_context      The interrupt context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqCfgEnable (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    R_BSP_IrqCfg(irq, priority, p_context);
    R_BSP_IrqEnable(irq);
}

/*******************************************************************************************************************//**
 * Sets the interrupt Group.
 *
 * @param[in] irq               The IRQ number to configure.
 * @param[in] interrupt_group   GIC interrupt group number ( 0 : FIQ, 1 : IRQ ).
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqGroupSet (IRQn_Type const irq, uint32_t interrupt_group)
{
    /* this function is not yet supported */
    FSP_PARAMETER_NOT_USED(irq);
    FSP_PARAMETER_NOT_USED(interrupt_group);
}

/*******************************************************************************************************************//**
 * Sets the interrupt priority mask level.
 *
 * @param[in] mask_level          The interrupt mask level
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqMaskLevelSet (uint32_t mask_level)
{
    FSP_CRITICAL_SECTION_SET_STATE((mask_level << BSP_FEATURE_INTC_IRQ_PRIORITY_POS_BIT) &
                                   BSP_FEATURE_INTC_IRQ_PRIORITY_MASK);
}

/*******************************************************************************************************************//**
 * Gets the interruptpriority  mask level.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 *
 * @return  Value indicating the interrupt mask level.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_IrqMaskLevelGet (void)
{
    return (uint32_t) ((FSP_CRITICAL_SECTION_GET_CURRENT_STATE() & BSP_FEATURE_INTC_IRQ_PRIORITY_MASK) >>
                       BSP_FEATURE_INTC_IRQ_PRIORITY_POS_BIT);
}

#else
void     R_BSP_IrqDetectTypeSet(IRQn_Type const irq, uint8_t detect_type);
void     R_BSP_IrqStatusClear(IRQn_Type irq);
void     R_BSP_IrqClearPending(IRQn_Type irq);
uint32_t R_BSP_IrqPendingGet(IRQn_Type irq);
void     R_BSP_IrqCfg(IRQn_Type const irq, uint32_t priority, void * p_context);
void     R_BSP_IrqEnableNoClear(IRQn_Type const irq);
void     R_BSP_IrqEnable(IRQn_Type const irq);
void     R_BSP_IrqDisable(IRQn_Type const irq);
void     R_BSP_IrqCfgEnable(IRQn_Type const irq, uint32_t priority, void * p_context);
void     R_BSP_IrqGroupSet(IRQn_Type const irq, uint32_t interrupt_group);
void     R_BSP_IrqMaskLevelSet(uint32_t mask_level);
uint32_t R_BSP_IrqMaskLevelGet(void);

#endif

/*******************************************************************************************************************//**
 * @internal
 * @addtogroup BSP_MCU_PRV Internal BSP Documentation
 * @ingroup RENESAS_INTERNAL
 * @{
 **********************************************************************************************************************/

/* Public functions defined in bsp.h */
void        bsp_irq_cfg(void);         // Used internally by BSP
void        bsp_common_interrupt_handler(uint32_t id);
__WEAK void IRQ_Handler(void);

/** @} (end addtogroup BSP_MCU_PRV) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
