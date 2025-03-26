/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_dmac.h
 * Version      : 1.00
 * Description  : bsp_dmac header
 *********************************************************************************************************************/

#ifndef BSP_DMAC_H
#define BSP_DMAC_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * @addtogroup BSP_MPU_RZA3M
 * @{
 *********************************************************************************************************************/

typedef enum e_dmac_trigger_event
{
    DMAC_TRIGGER_EVENT_SOFTWARE_TRIGGER = 0,
    DMAC_TRIGGER_EVENT_GTM_OSTM0TINT    = 35,
    DMAC_TRIGGER_EVENT_GTM_OSTM1TINT    = 39,
    DMAC_TRIGGER_EVENT_GTM_OSTM2TINT    = 43,
    DMAC_TRIGGER_EVENT_MTU3_TGIA0       = 51,
    DMAC_TRIGGER_EVENT_MTU3_TGIB0       = 55,
    DMAC_TRIGGER_EVENT_MTU3_TGIC0       = 59,
    DMAC_TRIGGER_EVENT_MTU3_TGID0       = 63,
    DMAC_TRIGGER_EVENT_MTU3_TGIA1       = 67,
    DMAC_TRIGGER_EVENT_MTU3_TGIB1       = 71,
    DMAC_TRIGGER_EVENT_MTU3_TGIA2       = 75,
    DMAC_TRIGGER_EVENT_MTU3_TGIB2       = 79,
    DMAC_TRIGGER_EVENT_MTU3_TGIA3       = 83,
    DMAC_TRIGGER_EVENT_MTU3_TGIB3       = 87,
    DMAC_TRIGGER_EVENT_MTU3_TGIC3       = 91,
    DMAC_TRIGGER_EVENT_MTU3_TGID3       = 95,
    DMAC_TRIGGER_EVENT_MTU3_TGIA4       = 99,
    DMAC_TRIGGER_EVENT_MTU3_TGIB4       = 103,
    DMAC_TRIGGER_EVENT_MTU3_TGIC4       = 107,
    DMAC_TRIGGER_EVENT_MTU3_TGID4       = 111,
    DMAC_TRIGGER_EVENT_MTU3_TCIV4       = 115,
    DMAC_TRIGGER_EVENT_MTU3_TGIU5       = 119,
    DMAC_TRIGGER_EVENT_MTU3_TGIV5       = 123,
    DMAC_TRIGGER_EVENT_MTU3_TGIW5       = 127,
    DMAC_TRIGGER_EVENT_MTU3_TGIA6       = 131,
    DMAC_TRIGGER_EVENT_MTU3_TGIB6       = 135,
    DMAC_TRIGGER_EVENT_MTU3_TGIC6       = 139,
    DMAC_TRIGGER_EVENT_MTU3_TGID6       = 143,
    DMAC_TRIGGER_EVENT_MTU3_TGIA7       = 147,
    DMAC_TRIGGER_EVENT_MTU3_TGIB7       = 151,
    DMAC_TRIGGER_EVENT_MTU3_TGIC7       = 155,
    DMAC_TRIGGER_EVENT_MTU3_TGID7       = 159,
    DMAC_TRIGGER_EVENT_MTU3_TCIV7       = 163,
    DMAC_TRIGGER_EVENT_MTU3_TGIA8       = 167,
    DMAC_TRIGGER_EVENT_MTU3_TGIB8       = 171,
    DMAC_TRIGGER_EVENT_MTU3_TGIC8       = 175,
    DMAC_TRIGGER_EVENT_MTU3_TGID8       = 179,
    DMAC_TRIGGER_EVENT_SSIF_DMA_RX0     = 598,
    DMAC_TRIGGER_EVENT_SSIF_DMA_TX0     = 597,
    DMAC_TRIGGER_EVENT_SRC_IDEI         = 614,
    DMAC_TRIGGER_EVENT_SRC_ODFI         = 613,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI0  = 618,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI0  = 617,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI1  = 622,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI1  = 621,
    DMAC_TRIGGER_EVENT_SCIF_RXI0        = 634,
    DMAC_TRIGGER_EVENT_SCIF_TXI0        = 633,
    DMAC_TRIGGER_EVENT_SCIF_RXI1        = 638,
    DMAC_TRIGGER_EVENT_SCIF_TXI1        = 637,
    DMAC_TRIGGER_EVENT_SCIF_RXI2        = 642,
    DMAC_TRIGGER_EVENT_SCIF_TXI2        = 641,
    DMAC_TRIGGER_EVENT_SCIF_RXI3        = 646,
    DMAC_TRIGGER_EVENT_SCIF_TXI3        = 645,
    DMAC_TRIGGER_EVENT_SCIF_RXI4        = 650,
    DMAC_TRIGGER_EVENT_SCIF_TXI4        = 649,
    DMAC_TRIGGER_EVENT_SCIg_RXI0        = 654,
    DMAC_TRIGGER_EVENT_SCIg_TXI0        = 653,
    DMAC_TRIGGER_EVENT_SCIg_RXI1        = 658,
    DMAC_TRIGGER_EVENT_SCIg_TXI1        = 657,
    DMAC_TRIGGER_EVENT_RSPI_SPRI0       = 662,
    DMAC_TRIGGER_EVENT_RSPI_SPTI0       = 661,
    DMAC_TRIGGER_EVENT_RSPI_SPRI1       = 666,
    DMAC_TRIGGER_EVENT_RSPI_SPTI1       = 665,
} dmac_trigger_event_t;

/** @} (end addtogroup BSP_MPU_RZA3M) */

#endif                                 /* BSP_DMAC_H */
