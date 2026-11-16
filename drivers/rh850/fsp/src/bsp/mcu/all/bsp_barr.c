/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"                   /* PRQA S 0380 # DP_MSR_D-1.1-C99_UC1 & DP_MSR_D-1.1-C11_UC1 */
#include "bsp_barr.h"

/***********************************************************************************************************************
 * Variables and functions
 **********************************************************************************************************************/

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_BARR
 *
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */

/*******************************************************************************************************************//**
 * @brief Init a channel for synchronization process.
 *
 * @param channel    Barrier Synchronization channel.
 **********************************************************************************************************************/
void R_BSP_BarrChannelInit (bsp_barrier_sync_channel_t channel)                                    /* PRQA S 1505 # Advisory R-8.7 */
{
    BSP_REG_BRnINIT((uint32_t) channel) = BSP_BARRIER_SYNCHRONIZATION_INITIALIZE;                  /* PRQA S 0303 # Advisory R-11.4 */
}

/*******************************************************************************************************************//**
 * @brief Enable cores (PEs) to join the synchronization process on the specified channel.
 *
 * @param channel    Barrier Synchronization channel.
 * @param pe_bitmask Bitmask of PEs.
 **********************************************************************************************************************/
void R_BSP_BarrChannelEnableSet (bsp_barrier_sync_channel_t channel, uint32_t pe_bitmask)          /* PRQA S 1505 # Advisory R-8.7 */
{
    BSP_REG_BRnEN((uint32_t) channel) = (uint8_t) pe_bitmask;                                      /* PRQA S 0303 # Advisory R-11.4 */
}

/*******************************************************************************************************************//**
 * @brief Return all CPUs participating in barrier synchronization on the specified channel.
 *
 * @param channel Barrier Synchronization channel.
 *
 * @return Channels participating in barrier synchronization
 **********************************************************************************************************************/
uint8_t R_BSP_BarrChannelEnableGet (bsp_barrier_sync_channel_t channel)                            /* PRQA S 1505 # Advisory R-8.7 */
{
    /* Return value of BRnEN register */
    return BSP_REG_BRnEN((uint32_t) channel);                                                      /* PRQA S 0303 # Advisory R-11.4 */
}

/*******************************************************************************************************************//**
 * @brief Set the status of a specified core (PE).
 *
 * @param channel    Barrier Synchronization channel.
 * @param peid       Processing Element ID (0-n).
 * @param status     Status to be set.
 **********************************************************************************************************************/
void R_BSP_BarrChannelStatusSet (bsp_barrier_sync_channel_t channel, uint8_t peid, uint8_t status) /* PRQA S 1505, 1710 # Advisory R-8.7, Advisory D-4.5 */
{
    BSP_REG_BRnCHKm((uint32_t) channel, peid) = status;                                            /* PRQA S 0303 # Advisory R-11.4 */
}

/*******************************************************************************************************************//**
 * @brief Get the current status of a specified core (PE).
 *
 * @param channel    Barrier Synchronization channel.
 * @param peid       Processing Element ID (0-n).
 *
 * @return Status of specified Barrier Synchronization channel
 **********************************************************************************************************************/
uint8_t R_BSP_BarrChannelStatusGet (bsp_barrier_sync_channel_t channel, uint8_t peid)              /* PRQA S 1505 # Advisory R-8.7 */
{
    return BSP_REG_BRnSYNCm((uint32_t) channel, peid);                                             /* PRQA S 0303 # Advisory R-11.4 */
}

/*******************************************************************************************************************//**
 * @brief Clear the status of a specified core (PE).
 *
 * @param channel    Barrier Synchronization channel.
 * @param peid       Processing Element ID (0-n).
 **********************************************************************************************************************/
void R_BSP_BarrChannelStatusClear (bsp_barrier_sync_channel_t channel, uint8_t peid)               /* PRQA S 1505 # Advisory R-8.7 */
{
    BSP_REG_BRnSYNCm((uint32_t) channel, peid) = BSP_BARRIER_SYNCHRONIZATION_CLEAR;                /* PRQA S 0303 # Advisory R-11.4 */
}

/*******************************************************************************************************************//**
 * @brief Get the current core (PE) ID.
 *
 * Returns the ID of the core executing this function.
 *
 * @return Core ID (0-n).
 **********************************************************************************************************************/
uint8_t R_BSP_GetCoreID (void)
{
    /* Return the unique core identifier: regID: SR0; selID: 2 */
    return (uint8_t) __STSR(SR_PEID, SL_PEID);              /* PRQA S 3432 # DP_MSR_R-20.7_UC1 */
}

/*******************************************************************************************************************//**
 * @brief Check synchronization status of all PEs on the given Barrier Synchronization channel.
 *
 * Used by a PE to verify if other cores have completed sync.
 *
 * @param channel Barrier Synchronization channel.
 **********************************************************************************************************************/
void R_BSP_PESyncCheck (bsp_barrier_sync_channel_t channel) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Waiting until the barrier has been enabled */
    while (BSP_BARRIER_NOT_ENABLE_PE == R_BSP_BarrChannelEnableGet(channel))
    {
        __NOP();                       /* Wait. */ /* PRQA S 3469 # Advisory D-4.9 */
    }
}

/*******************************************************************************************************************//**
 * @brief Enable a PE to join the synchronization process.
 *
 * Sets the bit corresponding to the PE ID to signal readiness.
 *
 * @param channel    Barrier Synchronization channel.
 * @param pe_bitmask Bitmask of PEs.
 **********************************************************************************************************************/
void R_BSP_PESyncEnable (bsp_barrier_sync_channel_t channel, uint32_t pe_bitmask) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    R_BSP_BarrChannelEnableSet(channel, pe_bitmask);
    R_BSP_BarrChannelInit(channel);
}

/*******************************************************************************************************************//**
 * @brief Check if all specified PEs have completed synchronization.
 *
 * Compares current sync status with the expected PE bitmask.
 *
 * @param channel Barrier Synchronization channel.
 * @param peid    Processing Element ID (0-n).
 **********************************************************************************************************************/
void R_BSP_PESyncComplete (bsp_barrier_sync_channel_t channel, uint8_t peid) /* PRQA S 1503 # DP_MSR_R-2.1_UC1 */
{
    /* Signal barrier synchronization completion for the specified channel. */
    R_BSP_BarrChannelStatusSet(channel, peid, BSP_BARRIER_SYNCHRONIZATION_COMPLETION);

    /* Waiting for barrier synchronization completion */
    while (BSP_BARRIER_SYNCHRONIZATION_COMPLETION != R_BSP_BarrChannelStatusGet(channel, peid))
    {
        __NOP();                       /* PRQA S 3469 # Advisory D-4.9 */
    }

    /* Clear barrier synchronization completion flag */
    R_BSP_BarrChannelStatusClear(channel, peid);
}

/** @} (end addtogroup BSP_BARR) */

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
