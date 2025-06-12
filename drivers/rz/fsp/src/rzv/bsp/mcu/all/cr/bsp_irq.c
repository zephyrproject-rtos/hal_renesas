/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_irq_sense.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_CLEAR_REG_MAX          (13U)
#define BSP_PRV_ALL_BIT_CLEAR          (0xFFFFFFFFU)

#define BSP_PRV_ID_MASK                (0x000003FFU)
#define BSP_PRV_INTERRUPTABLE_NUM      (32U)

#define BSP_PRV_DISABLE_SPI_SEL        (0x3FF)
#define BSP_PRV_SPI_SEL_ALL_DISABLE    (0x3FFFFFFFU)
#define BSP_PRV_SPI_SEL_SETTING_NUM    (3)
#define BSP_PRV_SPI_SEL_LENGTH         (10UL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
extern fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES];

/* This table is used to store the context in the ISR. */
void * gp_renesas_isr_context[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES];

extern uint32_t g_gicd_icdicfr_init_array[BSP_GIC_ICFGR_MAX];
extern uint8_t  g_detect_type_sel_int[BSP_FEATURE_SELECT_IRQSEL_MAX];

/* GIC current interrpt ID and variable. */
uint16_t g_current_interrupt_num[BSP_PRV_INTERRUPTABLE_NUM];
uint8_t  g_current_interrupt_pointer = 0;

extern uint8_t g_gic_detect_type[BSP_ICU_VECTOR_MAX_ENTRIES + BSP_CORTEX_VECTOR_TABLE_ENTRIES];
extern uint8_t g_gic_sel_int_detect_type[BSP_FEATURE_SELECT_IRQSEL_MAX];

/***********************************************************************************************************************
 * External symbols
 **********************************************************************************************************************/
#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)
const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES -
                                                          BSP_FEATURE_ICU_FIXED_INTSEL_COUNT]  BSP_WEAK_REFERENCE =
{
    (bsp_interrupt_event_t) IRQSEL_NONE
};
#endif

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

#if 0 == BSP_CFG_INLINE_IRQ_FUNCTIONS

/*******************************************************************************************************************//**
 * Sets the interrupt detect type.
 *
 * @param[in] irq             The IRQ number to configure.
 * @param[in] detect_type     GIC detect type of the interrupt
 *                            (BSP_GIC_SPI_DETECT_LEVEL : level-sensitive, BSP_GIC_SPI_DETECT_EDGE : edge-triggerd).
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
void R_BSP_IrqDetectTypeSet (IRQn_Type const irq, uint8_t detect_type)
{
    volatile uint32_t * p_reg_addr;
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    /* GICD_ICDICFRn has 16 sources in the 32 bits                    */
    /* The n can be calculated by irq div 16                          */
    /* The bit field width is 2 bit, and low bit is reserved          */
    /* The target bit can be calculated by irq mod 16, and multiply 2 */
    p_reg_addr = &R_INTC_GIC->GICD_ICDICFRn;
    shift      = (irq_no % BSP_PRV_GIC_STRIDE16) * BSP_PRV_GIC_BITS2;
    mask       = (uint32_t) (BSP_PRV_GIC_MASK_2BIT << shift);

    R_BSP_IoRegWrite32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE16)), (uint32_t) detect_type, shift, mask);
}

/*******************************************************************************************************************//**
 * Clear the interrupt status flag for a given interrupt.
 *
 * @note This function does not implement processing on this device.
 *
 * @param[in] irq            Not used
 **********************************************************************************************************************/
void R_BSP_IrqStatusClear (IRQn_Type irq)
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
void R_BSP_IrqClearPending (IRQn_Type irq)
{
    volatile uint32_t * p_reg_addr;
    uint32_t            mask;
    uint32_t            shift;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    /* GICD_ICDICPRn has 32 sources in the 32 bits           */
    /* The n can be calculated by irq div 32                 */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by irq mod 32        */
    p_reg_addr = &R_INTC_GIC->GICD_ICDICPRn;
    shift      = (irq_no % BSP_PRV_GIC_STRIDE32);           /* 1bits per unit */
    mask       = (uint32_t) (0x00000001UL << shift);        /* 1bits per unit */

    *(p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE32)) = mask; /* Write GICD_ICDICPRn */
    R_BSP_IoRegWrite32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE32)), 1, shift, mask);
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
uint32_t R_BSP_IrqPendingGet (IRQn_Type irq)
{
    uint32_t            shift;
    uint32_t            mask;
    uint32_t            pending;
    volatile uint32_t * p_reg_addr;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    p_reg_addr = &R_INTC_GIC->GICD_ICDISPRn;

    shift   = (irq_no % BSP_PRV_GIC_STRIDE32);    /* 1bits per unit */
    mask    = (uint32_t) (0x00000001UL << shift); /* 1bits per unit */
    pending = R_BSP_IoRegRead32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE32)), shift, mask);

    return pending;
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
void R_BSP_IrqCfg (IRQn_Type const irq, uint32_t priority, void * p_context)
{
    volatile uint8_t * p_reg_byte_addr;
    uint8_t            cpu_id;
    uint8_t            cpu_interface_bit;
    uint32_t           irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;

    /* Initialize SPI interrupt detection type */
    R_BSP_IrqDetectTypeSet(irq, g_gic_detect_type[irq_no]);

    /* According the GICv1 Architecture Specification:
     * DIV and MOD are the integer division and modulo operations:
     * - the corresponding ICDIPR number, M, is given by irq_no DIV 4
     * - the offset of the required register is (Multiply 4)
     * - the byte offset of the required Priority field in this register is irq_no MOD 4
     */
    uint32_t M           = irq_no / BSP_PRV_GIC_STRIDE04;
    uint32_t reg_offset  = BSP_PRV_GIC_STRIDE04 * M;
    uint32_t byte_offset = irq_no % 4;

    p_reg_byte_addr = ((volatile uint8_t *) &R_INTC_GIC->GICD_ICDIPRn) + reg_offset + byte_offset;

    uint8_t set_priority = (priority << 4) & BSP_FEATURE_INTC_IRQ_PRIORITY_MASK;

    R_BSP_IoRegWrite8(p_reg_byte_addr, set_priority, 0, BSP_IO_NONMASK_ACCESS_8);

    /* set interrupt target CPU */
    p_reg_byte_addr = ((volatile uint8_t *) &R_INTC_GIC->GICD_ICDIPTRn) + reg_offset + byte_offset;

    cpu_id            = BSP_CR8_CORE_NUM;
    cpu_interface_bit = 1 << cpu_id;
    R_BSP_IoRegWrite8(p_reg_byte_addr, cpu_interface_bit, 0, BSP_IO_NONMASK_ACCESS_8);

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
void R_BSP_IrqEnableNoClear (IRQn_Type const irq)
{
    volatile uint32_t * p_reg_addr;
    volatile uint32_t   shift;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;
    volatile uint32_t   tmp;

    /* GICD_ICDISERn has 32 sources in the 32 bits           */
    /* The n can be calculated by irq div 32                 */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (irq mod 32) 1    */
    /* GICD_ICDISERn does not effect on writing "0"          */
    /* The bits except for the target write "0"              */
    p_reg_addr = &R_INTC_GIC->GICD_ICDISERn;
    shift      = (irq_no % BSP_PRV_GIC_STRIDE32); /* Create mask data */
    tmp        = shift;
    tmp        = 1UL << shift;

    R_BSP_IoRegWrite32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE32)), tmp, 0, BSP_IO_NONMASK_ACCESS_32);
}

/*******************************************************************************************************************//**
 * Enable the IRQ in the GIC (With clearing the pending bit).
 *
 * @param[in] irq            The IRQ number to enable. Note that the enums listed for IRQn_Type are only those for the
 *                           Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the IRQn_Type value is less than 0.
 **********************************************************************************************************************/
void R_BSP_IrqEnable (IRQn_Type const irq)
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
void R_BSP_IrqDisable (IRQn_Type const irq)
{
    volatile uint32_t * p_reg_addr;
    uint32_t            shift;
    uint32_t            irq_no = (uint32_t) irq + BSP_CORTEX_VECTOR_TABLE_ENTRIES;
    volatile uint32_t   tmp;

    /* GICD_ICDICERn has 32 sources in the 32 bits           */
    /* The n can be calculated by irq div 32                 */
    /* The bit field width is 1 bit                          */
    /* The target bit can be calculated by (irq mod 32)      */
    /* GICD_ICDICERn does not effect on writing "0"          */
    /* The bits except for the target write "0"              */
    p_reg_addr = &R_INTC_GIC->GICD_ICDICERn;
    shift      = (irq_no % BSP_PRV_GIC_STRIDE32);
    tmp        = 1UL << shift;

    R_BSP_IoRegWrite32((p_reg_addr + (irq_no / BSP_PRV_GIC_STRIDE32)), tmp, 0, BSP_IO_NONMASK_ACCESS_32);

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
void R_BSP_IrqCfgEnable (IRQn_Type const irq, uint32_t priority, void * p_context)
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
void R_BSP_IrqGroupSet (IRQn_Type const irq, uint32_t interrupt_group)
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
void R_BSP_IrqMaskLevelSet (uint32_t mask_level)
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
uint32_t R_BSP_IrqMaskLevelGet (void)
{
    return (uint32_t) ((FSP_CRITICAL_SECTION_GET_CURRENT_STATE() & BSP_FEATURE_INTC_IRQ_PRIORITY_MASK) >>
                       BSP_FEATURE_INTC_IRQ_PRIORITY_POS_BIT);
}

#endif                                 // 0 == BSP_CFG_INLINE_IRQ_FUNCTIONS

/** @} (end addtogroup BSP_MCU) */

/*******************************************************************************************************************//**
 *        Using the vector table information section that has been built by the linker and placed into ROM in the
 * .vector_info. section, this function will initialize the ICU so that configured ELC events will trigger interrupts
 * in the NVIC.
 *
 **********************************************************************************************************************/
void bsp_irq_cfg (void)
{
    uint32_t            gicd_reg_num;
    uint32_t            irq_num;
    uint32_t            select_num;
    uint32_t            cnt;
    volatile uint32_t * p_reg_addr;

    R_INTC_GIC->GICC_ICCICR_b.EN = 0;

    R_INTC_GIC->GICC_ICCPMR_b.P = BSP_FEATURE_INTC_IRQ_PRIORITY_MASK;

    R_INTC_GIC->GICC_ICCBPR_b.BP = BSP_FEATURE_INTC_BINARY_POINT;

    R_INTC_GIC->GICC_ICCICR_b.EN = 1;

    R_INTC_GIC->GICD_ICDDCR_b.EN = 0;

#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)

    /* Rewrite interrupt detection type table for Select interrupt */
    /* irq number of start select interrupt */
    irq_num    = BSP_FEATURE_ICU_FIXED_INTSEL_COUNT + BSP_SELECT_INT_START_ELEMENT + BSP_CORTEX_VECTOR_TABLE_ENTRIES;
    select_num = BSP_SELECT_INT_START_ELEMENT;
    for (cnt = 0;
         ((cnt < BSP_SELECT_INT_NUM) && (IRQSEL_NONE != g_interrupt_event_link_select[select_num]));
         cnt++)
    {
        g_gic_detect_type[irq_num] = g_gic_sel_int_detect_type[g_interrupt_event_link_select[select_num]];
        irq_num++;
        select_num++;
    }
#endif

    /* Clear the Pending bit for the all interrupts. */
    p_reg_addr = &R_INTC_GIC->GICD_ICDICPRn;
    for (gicd_reg_num = 0; gicd_reg_num < BSP_PRV_CLEAR_REG_MAX; gicd_reg_num++)
    {
        R_BSP_IoRegWrite32((p_reg_addr + gicd_reg_num), BSP_PRV_ALL_BIT_CLEAR, 0, BSP_IO_NONMASK_ACCESS_32);
    }

    /* Clear the Active bit for the all interrupts. */
    p_reg_addr = (volatile uint32_t *) &R_INTC_GIC->GICD_ICDABRn;
    for (gicd_reg_num = 0; gicd_reg_num < BSP_PRV_CLEAR_REG_MAX; gicd_reg_num++)
    {
        R_BSP_IoRegWrite32((p_reg_addr + gicd_reg_num), BSP_PRV_ALL_BIT_CLEAR, 0, BSP_IO_NONMASK_ACCESS_32);
    }

    R_INTC_GIC->GICD_ICDDCR_b.EN = 1;

#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)
    {
        uint32_t            sel_num;
        volatile uint32_t * intr8selx_addr = &R_INTC->INTR8SEL0;

        sel_num = BSP_SELECT_INT_START_ELEMENT;
        for (cnt = 0; cnt < BSP_SELECT_INT_NUM; cnt++)
        {
            if (g_interrupt_event_link_select[sel_num] != IRQSEL_NONE)
            {
                uint32_t sel_register_num = sel_num / BSP_PRV_SPI_SEL_SETTING_NUM;
                uint32_t sel_bit_num      = sel_num % BSP_PRV_SPI_SEL_SETTING_NUM;
                uint32_t spi_sel;

                spi_sel  = intr8selx_addr[sel_register_num];
                spi_sel &= ~(R_INTC_INTR8SEL0_R8SPI0_SEL0_Msk << (BSP_PRV_SPI_SEL_LENGTH * sel_bit_num));
                spi_sel |= g_interrupt_event_link_select[sel_num] << (BSP_PRV_SPI_SEL_LENGTH * sel_bit_num);
                intr8selx_addr[sel_register_num] = spi_sel;
                sel_num++;
            }
            else
            {
                break;
            }
        }
    }
#endif
}

/*******************************************************************************************************************//**
 * This function is called first when an interrupt is generated and branches to each interrupt isr function.
 *
 * @param[in]  id    GIC INTID used to identify the interrupt.
 **********************************************************************************************************************/
void bsp_common_interrupt_handler (uint32_t id)
{
    uint16_t gic_intid;

    /* Get interruot ID (GIC INTID). */
    gic_intid = (uint16_t) (id & BSP_PRV_ID_MASK);

    if (BSP_GIC_SPECIAL_ID != gic_intid)
    {
        /* Remain the interrupt number */
        g_current_interrupt_num[g_current_interrupt_pointer++] =
            (uint16_t) (gic_intid - BSP_CORTEX_VECTOR_TABLE_ENTRIES);

        __asm volatile ("dmb");

        __enable_irq();

        /* Branch to an interrupt handler. */
        g_vector_table[gic_intid]();
        __disable_irq();
        g_current_interrupt_pointer--;
    }
}
