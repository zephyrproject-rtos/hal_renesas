/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : gicv3.h
 * Version      : 1.00
 * Description  : Header for GICv3 (GIC-600).
 *********************************************************************************************************************/

#ifndef GICV3_H
#define GICV3_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#include <stdint.h>

#define GIC_NONMASK_ACCESS     (0xFFFFFFFFFFFFFFFFUL)
#define GIC_NONSHIFT_ACCESS    (0)

#define GIC_SGI_START_ID       (0)
#define GIC_PPI_START_ID       (16)
#define GIC_SPI_START_ID       (32)

/** GICD_CTRL bits. */
typedef enum
{
    GICD_CTLR_EnableGrp0   = (1UL << 0),
    GICD_CTLR_EnableGrp1NS = (1UL << 1),
    GICD_CTLR_EnableGrp1S  = (1UL << 2),
    GICD_CTLR_EnableAll    = (1UL << 2) | (1UL << 1) | (1UL << 0),
    GICD_CTLR_ARE_S        = (1UL << 4),
    GICD_CTLR_ARE_NS       = (1UL << 5),
    GICD_CTLR_DS           = (1UL << 6),
    GICD_CTLR_E1NWF        = (1UL << 7),
    GICD_CTLR_RWP          = (1UL << 31)
} e_gicd_ctlr_bit_t;

/** Routing mode setting. */
typedef enum
{
    GICD_IROUTER_ROUTE_AFF = (0UL << 31),
    GICD_IROUTER_ROUTE_FIX = (1UL << 31)
} e_gicd_irouter_route_t;

/** Interrupt types. */
typedef enum
{
    GICD_ICFGR_SENSE_LEVEL = 0UL,
    GICD_ICFGR_SENSE_EDGE  = (1UL << 1)
} e_gicd_icfgr_sense_t;

/** Secure group settings. */
typedef enum
{
    GICD_IGROUPR_G0S  = 0UL,
    GICD_IGROUPR_G1NS = (1UL << 0),
    GICD_IGROUPR_G1S  = (1UL << 1)
} e_gicd_igroupr_secure_t;

/** GICR powerup status. */
typedef enum
{
    GICR_WAKER_PROCESSOR_SLEEP = (1UL << 1),
    GICR_WAKER_CHILDREN_ASLEEP = (1UL << 2)
} e_gicr_waker_mode_t;

/**********************************************************************/

/**********************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Setting of GICD
 **********************************************************************************************************************/

void     R_BSP_GICD_SetCtlr(e_gicd_ctlr_bit_t bit);
uint32_t R_BSP_GICD_GetCtlr(void);
void     R_BSP_GICD_Enable(e_gicd_ctlr_bit_t bit);
void     R_BSP_GICD_Disable(e_gicd_ctlr_bit_t bit);
void     R_BSP_GICD_AffinityRouteEnable(e_gicd_ctlr_bit_t bit);
void     R_BSP_GICD_SpiEnable(uint32_t id);
void     R_BSP_GICD_SpiDisable(uint32_t id);
void     R_BSP_GICD_SetSpiPriority(uint32_t id, uint32_t priority);
uint32_t R_BSP_GICD_GetSpiPriority(uint32_t id);
void     R_BSP_GICD_SetSpiRoute(uint32_t id, uint64_t route, e_gicd_irouter_route_t mode);
uint64_t R_BSP_GICD_GetSpiRoute(uint32_t id);
void     R_BSP_GICD_SetSpiSense(uint32_t id, e_gicd_icfgr_sense_t sense);
uint32_t R_BSP_GICD_GetSpiSense(uint32_t id);
void     R_BSP_GICD_SetSpiPending(uint32_t id);
void     R_BSP_GICD_ClearSpiPending(uint32_t id);
uint32_t R_BSP_GICD_GetSpiPending(uint32_t id);
void     R_BSP_GICD_SetSpiSecurity(uint32_t id, e_gicd_igroupr_secure_t group);
void     R_BSP_GICD_SetSpiSecurityLine(uint32_t line, e_gicd_igroupr_secure_t group);
void     R_BSP_GICD_SetSpiSecurityAll(e_gicd_igroupr_secure_t group);
void     R_BSP_GICD_SetSpiClass(uint32_t id, uint32_t class_group);

/***********************************************************************************************************************
 * Setting of GICR
 **********************************************************************************************************************/

void     R_BSP_GICR_Enable(void);
void     R_BSP_GICR_SgiPpiEnable(uint32_t id);
void     R_BSP_GICR_SgiPpiDisable(uint32_t id);
void     R_BSP_GICR_SetSgiPpiPriority(uint32_t id, uint32_t priority);
uint32_t R_BSP_GICR_GetSgiPpiPriority(uint32_t id);
void     R_BSP_GICR_SetSgiPpiPending(uint32_t id);
void     R_BSP_GICR_ClearSgiPpiPending(uint32_t id);
uint32_t R_BSP_GICR_GetSgiPpiPending(uint32_t id);
void     R_BSP_GICR_SetSgiPpiSecurity(uint32_t id, e_gicd_igroupr_secure_t group);
void     R_BSP_GICR_SetSgiPpiSecurityLine(e_gicd_igroupr_secure_t group);
void     R_BSP_GICR_SetClass(uint32_t class_group);
uint32_t R_BSP_GICR_GetRoute(void);

/***********************************************************************************************************************
 * Setting of GICC
 **********************************************************************************************************************/

void     R_BSP_GICC_SetMaskLevel(uint64_t mask_level);
uint64_t R_BSP_GICC_GetMaskLevel(void);
void     R_BSP_GICC_SetEoiGrp0(uint32_t id);
void     R_BSP_GICC_SetEoiGrp1(uint32_t id);
uint32_t R_BSP_GICC_Get_IntIdGrp0(void);
uint32_t R_BSP_GICC_Get_IntIdGrp1(void);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
