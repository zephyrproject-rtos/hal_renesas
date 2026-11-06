/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_BARR_H
#define BSP_BARR_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_BARR BSP Barrier-Synchronization
 * @brief This section provides barrier and synchronization support.
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Barrier Synchronization control values */
#define BSP_BARRIER_SYNCHRONIZATION_INITIALIZE    0x01U                                                   ///< Barrier initialize value
#define BSP_BARRIER_SYNCHRONIZATION_COMPLETION    0x01U                                                   ///< Barrier completion value
#define BSP_BARRIER_SYNCHRONIZATION_CLEAR         0x00U                                                   ///< Barrier clear value
#define BSP_BARRIER_NOT_ENABLE_PE                 0x00U                                                   ///< Barrier not enabled for PE

/** Barrier register base address */
#define R_BARR_BASE                               0xFFFB8000UL                                            ///< Base address of barrier registers

/** Barrier register access macros */
#define BSP_REG_BRnINIT(n)     *(volatile uint8_t *) (R_BARR_BASE + (uint32_t) 0x000U + ((uint32_t) 0x010U * \
                                                                                         (uint32_t) (n))) ///< BRnINIT register for channel n
#define BSP_REG_BRnEN(n)       *(volatile uint8_t *) (R_BARR_BASE + (uint32_t) 0x004U + ((uint32_t) 0x010U * \
                                                                                         (uint32_t) (n))) ///< BRnEN register for channel n

/* PRQA S 1534 ++ # Advisory R-2.5 */
#define BSP_REG_BRnCHKS(n)     *(volatile uint8_t *) (R_BARR_BASE + (uint32_t) 0x100U + ((uint32_t) 0x010U * \
                                                                                         (uint32_t) (n))) ///< BRnCHKS register for channel n
#define BSP_REG_BRnSYNCS(n)    *(volatile uint8_t *) (R_BARR_BASE + (uint32_t) 0x104U + ((uint32_t) 0x010U * \
                                                                                         (uint32_t) (n))) ///< BRnSYNCS register for channel n

/* PRQA S 1534 -- */
#define BSP_REG_BRnCHKm(n,                                                                                   \
                        m)     *(volatile uint8_t *) (R_BARR_BASE + (uint32_t) 0x800U + ((uint32_t) 0x010U * \
                                                                                         (uint32_t) (n)) +   \
                                                      ((uint32_t) 0x100U * (uint32_t) (m))) ///< BRnCHKm register for channel n and PE m
#define BSP_REG_BRnSYNCm(n,                                                                                  \
                         m)    *(volatile uint8_t *) (R_BARR_BASE + (uint32_t) 0x804U + ((uint32_t) 0x010U * \
                                                                                         (uint32_t) (n)) +   \
                                                      ((uint32_t) 0x100U * (uint32_t) (m))) ///< BRnSYNCm register for channel n and PE m

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Barrier Synchronization channel */
typedef enum e_bsp_barrier_sync_channel  /* PRQA S 1536 # Advisory R-2.4 */
{
    BSP_BARRIER_SYNC_CHANNEL_0  = (0U),  ///< Barrier sync channel 0
    BSP_BARRIER_SYNC_CHANNEL_1  = (1U),  ///< Barrier sync channel 1
    BSP_BARRIER_SYNC_CHANNEL_2  = (2U),  ///< Barrier sync channel 2
    BSP_BARRIER_SYNC_CHANNEL_3  = (3U),  ///< Barrier sync channel 3
    BSP_BARRIER_SYNC_CHANNEL_4  = (4U),  ///< Barrier sync channel 4
    BSP_BARRIER_SYNC_CHANNEL_5  = (5U),  ///< Barrier sync channel 5
    BSP_BARRIER_SYNC_CHANNEL_6  = (6U),  ///< Barrier sync channel 6
    BSP_BARRIER_SYNC_CHANNEL_7  = (7U),  ///< Barrier sync channel 7
    BSP_BARRIER_SYNC_CHANNEL_8  = (8U),  ///< Barrier sync channel 8
    BSP_BARRIER_SYNC_CHANNEL_9  = (9U),  ///< Barrier sync channel 9
    BSP_BARRIER_SYNC_CHANNEL_10 = (10U), ///< Barrier sync channel 10
    BSP_BARRIER_SYNC_CHANNEL_11 = (11U), ///< Barrier sync channel 11
    BSP_BARRIER_SYNC_CHANNEL_12 = (12U), ///< Barrier sync channel 12
    BSP_BARRIER_SYNC_CHANNEL_13 = (13U), ///< Barrier sync channel 13
    BSP_BARRIER_SYNC_CHANNEL_14 = (14U), ///< Barrier sync channel 14
    BSP_BARRIER_SYNC_CHANNEL_15 = (15U)  ///< Barrier sync channel 15
} bsp_barrier_sync_channel_t;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

uint8_t R_BSP_GetCoreID(void);
void    R_BSP_PESyncCheck(bsp_barrier_sync_channel_t channel);
void    R_BSP_PESyncEnable(bsp_barrier_sync_channel_t channel, uint32_t pe_bitmask);
void    R_BSP_PESyncComplete(bsp_barrier_sync_channel_t channel, uint8_t peid);

void    R_BSP_BarrChannelInit(bsp_barrier_sync_channel_t channel);
void    R_BSP_BarrChannelEnableSet(bsp_barrier_sync_channel_t channel, uint32_t pe_bitmask);
uint8_t R_BSP_BarrChannelEnableGet(bsp_barrier_sync_channel_t channel);
void    R_BSP_BarrChannelStatusSet(bsp_barrier_sync_channel_t channel, uint8_t peid, uint8_t status);
uint8_t R_BSP_BarrChannelStatusGet(bsp_barrier_sync_channel_t channel, uint8_t peid);
void    R_BSP_BarrChannelStatusClear(bsp_barrier_sync_channel_t channel, uint8_t peid);

/** @} (end addtogroup BSP_BARR) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif
