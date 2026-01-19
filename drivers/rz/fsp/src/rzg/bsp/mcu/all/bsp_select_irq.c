/*
* Copyright (c) 2020 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_select_irq.c
 * Version      : 1.00
 * Description  : bsp_select_irq source code
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "bsp_api.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private global variables and functions
 *********************************************************************************************************************/

#define BSP_PRV_SELECT_IRQ_MIN              (353)
#define BSP_PRV_SELECT_IRQ_MAX              (BSP_PRV_SELECT_IRQ_MIN + 127)

#define BSP_PRV_SELECT_IRQ_PER_REG          (3U)
#define BSP_PRV_SELECT_IRQ_PER_BIT          (10U)

#define BSP_PRV_SELECT_IRQSEL_MASK          (0x3FFU)
#define BSP_PRV_SELECT_IRQSEL_CLEAR         (0x3FFU)

#if defined(BSP_FEATURE_ICU_HAS_INTPMSEL_REG)

 #define BSP_PRV_INTPMSEL_REG_LENGTH        (32)
 #define BSP_PRV_INTPMSEL_SET_VALUE_GPT     (0)
 #define BSP_PRV_INTPMSEL_SET_VALUE_MTU3    (1)

// *UNCRUSTIFY-OFF*

static int32_t mtu3_intpmsel_offset_table[BSP_FEATURE_MTU3_MAX_CHANNELS][MTU3_CAUSE_NUM] =
{
/* TGIA, TGIB, TGIC, TGID, TGIE, TGIF, TGIU, TGIV, TGIW, TCIU, TCIV */
    { 0,    1,    2,    3,    5,    6,   -1,   -1,   -1,   -1,    4}, /* MTU Ch 0 */
    { 7,    8,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   10,    9}, /* MTU Ch 1 */
    {11,   12,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   14,   13}, /* MTU Ch 2 */
    {15,   16,   17,   18,   -1,   -1,   -1,   -1,   -1,   -1,   19}, /* MTU Ch 3 */
    {20,   21,   22,   23,   -1,   -1,   -1,   -1,   -1,   -1,   24}, /* MTU Ch 4 */
    {-1,   -1,   -1,   -1,   -1,   -1,   25,   26,   27,   -1,   -1}, /* MTU Ch 5 */
    {28,   29,   30,   31,   -1,   -1,   -1,   -1,   -1,   -1,   32}, /* MTU Ch 6 */
    {33,   34,   35,   36,   -1,   -1,   -1,   -1,   -1,   -1,   37}, /* MTU Ch 7 */
    {38,   39,   40,   41,   -1,   -1,   -1,   -1,   -1,   43,   42}, /* MTU Ch 8 */
};

// *UNCRUSTIFY-ON*

#endif

/******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 *********************************************************************************************************************/

#if defined(BSP_FEATURE_ICU_HAS_SELECT_INT)

/******************************************************************************************************************//**
 * Set SELECT Interrupt for Cortex-M33.
 *
 * @param[in]  irq          The target SPI number
 * @param[in]  irqsel       The source of the event signal
 *
 * @retval     FSP_SUCCESS          SELECT interrupt settings was successful.
 * @retval     FSP_ERR_NOT_ENABLED  The specified interrupt cannot be used as a SELECT interrupt.
 *********************************************************************************************************************/
fsp_err_t R_BSP_CM33SelectIrqSet (IRQn_Type irq, IRQSELn_Type irqsel)
{
    fsp_err_t err = FSP_SUCCESS;

    if ((BSP_PRV_SELECT_IRQ_MIN <= irq) && (BSP_PRV_SELECT_IRQ_MAX > irq))
    {
        volatile uint32_t * intm33selx_addr = &R_INTC->INTM33SEL0;
        uint32_t            intm33selx_value;
        uint32_t            nregs;
        uint32_t            shift;

        FSP_CRITICAL_SECTION_DEFINE;

        nregs = ((uint32_t) (irq - BSP_PRV_SELECT_IRQ_MIN)) / BSP_PRV_SELECT_IRQ_PER_REG;
        shift = (((uint32_t) (irq - BSP_PRV_SELECT_IRQ_MIN)) % BSP_PRV_SELECT_IRQ_PER_REG) * BSP_PRV_SELECT_IRQ_PER_BIT;

        intm33selx_addr += nregs;

        FSP_CRITICAL_SECTION_ENTER;

        /* Read original value */
        intm33selx_value = *intm33selx_addr;

        /* Clear specified field */
        intm33selx_value &= ~(BSP_PRV_SELECT_IRQSEL_MASK << shift);

        /* Set specified numnber */
        intm33selx_value |= (irqsel << shift);

        /* Write modified value */
        *intm33selx_addr = intm33selx_value;

        FSP_CRITICAL_SECTION_EXIT;
    }
    else
    {
        err = FSP_ERR_NOT_ENABLED;
    }

    return err;
}

#endif

#if defined(BSP_FEATURE_ICU_HAS_INTPMSEL_REG)

/******************************************************************************************************************//**
 * Function selection of interrupts with specific factors bundled
 *
 * @param[in]  ip           Specifies which module to act as an interrupt.
 * @param[in]  channel      Specifies the channel number to be controlled.
 * @param[in]  cause        Specify the cause of the interrupt to be controlled. It does not include the channel number.
 *
 * @retval     FSP_SUCCESS                     GPT/MTU3a Interrupt Selection was successful.
 * @retval     FSP_ERR_INVALID_MODE            A module other than GPT or MTU3a was specified.
 * @retval     FSP_ERR_INVALID_ARGUMENT        An invalid cause of interrupt was specified.
 * @retval     FSP_ERR_IP_CHANNEL_NOT_PRESENT  Requested channel number is not available.
 *********************************************************************************************************************/
fsp_err_t R_BSP_IntCauseSelectionSet (fsp_ip_t ip, uint8_t channel, intsel_cause_t cause)
{
    uint32_t  pos_calc;
    uint32_t  set_value;
    fsp_err_t err = FSP_SUCCESS;

    switch (ip)
    {
        case FSP_IP_GPT:
        {
            if (0 == ((1U << channel) & BSP_FEATURE_GPT_VALID_CHANNEL_MASK))
            {
                err = FSP_ERR_IP_CHANNEL_NOT_PRESENT;
            }
            else if (GPT_CAUSE_NUM <= cause)
            {
                err = FSP_ERR_INVALID_ARGUMENT;
            }
            else
            {
                set_value = BSP_PRV_INTPMSEL_SET_VALUE_GPT;
                pos_calc  = (uint32_t) (channel * GPT_CAUSE_NUM + cause);
            }

            break;
        }

        case FSP_IP_MTU3:
        {
            if (0 == ((1U << channel) & BSP_FEATURE_MTU3_VALID_CHANNEL_MASK))
            {
                err = FSP_ERR_IP_CHANNEL_NOT_PRESENT;
            }
            else if (MTU3_CAUSE_NUM <= cause)
            {
                err = FSP_ERR_INVALID_ARGUMENT;
            }
            else if (-1 == mtu3_intpmsel_offset_table[channel][cause])
            {
                err = FSP_ERR_INVALID_ARGUMENT;
            }
            else
            {
                set_value = BSP_PRV_INTPMSEL_SET_VALUE_MTU3;
                pos_calc  = (uint32_t) mtu3_intpmsel_offset_table[channel][cause];
            }

            break;
        }

        default:
        {
            FSP_PARAMETER_NOT_USED(pos_calc);
            FSP_PARAMETER_NOT_USED(set_value);

            err = FSP_ERR_INVALID_MODE;

            break;
        }
    }

    if (FSP_SUCCESS == err)
    {
        volatile uint32_t * reg_addr = &R_INTC_IM33->INTPMSEL0;
        uint32_t            reg_value;
        uint32_t            nregs;
        uint32_t            shift;

        FSP_CRITICAL_SECTION_DEFINE;

        shift = pos_calc % BSP_PRV_INTPMSEL_REG_LENGTH;
        nregs = pos_calc / BSP_PRV_INTPMSEL_REG_LENGTH;

        reg_addr += nregs;

        FSP_CRITICAL_SECTION_ENTER;

        /* Read original value */
        reg_value = *reg_addr;

        /* Clear specified field */
        reg_value &= ~((uint32_t) 1 << shift);

        /* Set specified numnber */
        reg_value |= (set_value << shift);

        /* Write modified value */
        *reg_addr = reg_value;

        FSP_CRITICAL_SECTION_EXIT;
    }

    return err;
}

#endif

/** @} (end addtogroup BSP_MCU) */
