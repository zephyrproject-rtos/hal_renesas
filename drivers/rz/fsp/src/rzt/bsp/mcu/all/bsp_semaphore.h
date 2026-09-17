/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_SEMAPHORE_H
#define BSP_SEMAPHORE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#if BSP_FEATURE_SEM_SUPPORTED
 #define BSP_SEMAPHORE_INTERNAL_CPU_REGISTER(sem_num)     R_SEM->SYTSEMF[sem_num]
 #define BSP_SEMAPHORE_INTERNAL_CPU_RESOURCE_NOT_USED     (0x00000001U)

#elif BSP_FEATURE_MAILBOX_SEM_SUPPORTED
 #if BSP_FEATURE_MAILBOX_SEM_INTERNAL_CPU_SEM_SUPPORTED
  #define BSP_SEMAPHORE_INTERNAL_CPU_REGISTER(sem_num)    R_MBXSEM->SEMAR[sem_num]
  #define BSP_SEMAPHORE_INTERNAL_CPU_RESOURCE_NOT_USED    (0x00000001U)
 #endif
 #define BSP_SEMAPHORE_EXTERNAL_HOST_REGISTER(sem_num)    R_MBXSEM->SEM[sem_num]
 #define BSP_SEMAPHORE_EXTERNAL_HOST_RESOURCE_NOT_USED    (0x00000001U)

#endif

#if BSP_CFG_SEMAPHORE_ENABLE &&   \
    (BSP_FEATURE_SEM_SUPPORTED || \
     (BSP_FEATURE_MAILBOX_SEM_SUPPORTED && BSP_FEATURE_MAILBOX_SEM_INTERNAL_CPU_SEM_SUPPORTED))

 #define BSP_SEMAPHORE_INTERNAL_CPU_STATE_READ_FOR_PROTECTION    R_BSP_InternalCpuSemaphoreStateRead(BSP_RESOURCE_NUM_7)
 #define BSP_SEMAPHORE_INTERNAL_CPU_RELEASE_FOR_PROTECTION       R_BSP_InternalCpuSemaphoreRelease(BSP_RESOURCE_NUM_7)

#else

 #define BSP_SEMAPHORE_INTERNAL_CPU_STATE_READ_FOR_PROTECTION    BSP_RESOURCE_STATE_NOT_BEING_USED
 #define BSP_SEMAPHORE_INTERNAL_CPU_RELEASE_FOR_PROTECTION

#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZT
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSP_MCU
 * @{
 **********************************************************************************************************************/

/** The semaphore resource state shared by CPU0 and CPU1 */
typedef enum e_bsp_resource_state
{
    BSP_RESOURCE_STATE_BEING_USED     = 0, ///< Semaphore resource being used.
    BSP_RESOURCE_STATE_NOT_BEING_USED = 1, ///< Semaphore resource not being used.
} bsp_resource_state_t;

/** The semaphore resource number shared by CPU0 and CPU1 */
typedef enum e_bsp_resource_num
{
    BSP_RESOURCE_NUM_0 = 0,            ///< Semaphore resource number 0
    BSP_RESOURCE_NUM_1 = 1,            ///< Semaphore resource number 1
    BSP_RESOURCE_NUM_2 = 2,            ///< Semaphore resource number 2
    BSP_RESOURCE_NUM_3 = 3,            ///< Semaphore resource number 3
    BSP_RESOURCE_NUM_4 = 4,            ///< Semaphore resource number 4
    BSP_RESOURCE_NUM_5 = 5,            ///< Semaphore resource number 5
    BSP_RESOURCE_NUM_6 = 6,            ///< Semaphore resource number 6
    BSP_RESOURCE_NUM_7 = 7,            ///< Semaphore resource number 7
} bsp_resource_num_t;

#if BSP_FEATURE_BSP_SEMAPHORE_SUPPORTED

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Inline Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Read semaphore resource status. When SYTSEMFEN = 1, reading this status clear the resource status.
 *
 * @param[in]  sem_num Semaphore number to read resource status.
 *
 * @retval     Resource status.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_SemaphoreStateRead (bsp_resource_num_t sem_num) // DEPRECATED
{
 #if BSP_FEATURE_SEM_SUPPORTED
    uint32_t sem = R_SEM->SYTSEMF[sem_num];
 #elif BSP_FEATURE_MAILBOX_SEM_SUPPORTED
    uint32_t sem = R_MBXSEM->SEM[sem_num];
 #else
    uint32_t sem = 0;
    FSP_PARAMETER_NOT_USED(sem_num);
 #endif

    return sem;
}

 #if (BSP_FEATURE_SEM_SUPPORTED || \
      (BSP_FEATURE_MAILBOX_SEM_SUPPORTED && BSP_FEATURE_MAILBOX_SEM_INTERNAL_CPU_SEM_SUPPORTED))

/*******************************************************************************************************************//**
 * Read internal cpu semaphore resource status. When SYTSEMFEN = 1 or SEMRCENAR = 1,
 * reading this status clear the resource status.
 *
 * @param[in]  sem_num Semaphore number to read resource status.
 *
 * @retval     Resource status.
 **********************************************************************************************************************/
__STATIC_INLINE bsp_resource_state_t R_BSP_InternalCpuSemaphoreStateRead (bsp_resource_num_t sem_num)
{
    bsp_resource_state_t status = BSP_RESOURCE_STATE_BEING_USED;

    /* If the resource is not in use, a non-zero value will be returned. */
    if (BSP_SEMAPHORE_INTERNAL_CPU_REGISTER(sem_num))
    {
        status = BSP_RESOURCE_STATE_NOT_BEING_USED;
    }

    return status;
}

/*******************************************************************************************************************//**
 * Release the internal CPU semaphore.
 *
 * @param[in]  sem_num Semaphore number to read resource status.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_InternalCpuSemaphoreRelease (bsp_resource_num_t sem_num)
{
    __DMB();
    BSP_SEMAPHORE_INTERNAL_CPU_REGISTER(sem_num) = BSP_SEMAPHORE_INTERNAL_CPU_RESOURCE_NOT_USED;
}

 #endif

 #if BSP_FEATURE_MAILBOX_SEM_SUPPORTED

/*******************************************************************************************************************//**
 * Read external host semaphore resource status. When SEMRCEN = 1,
 * reading this status clear the resource status.
 *
 * @param[in]  sem_num Semaphore number to read resource status.
 *
 * @retval     Resource status.
 **********************************************************************************************************************/
__STATIC_INLINE bsp_resource_state_t R_BSP_ExternalHostSemaphoreStateRead (bsp_resource_num_t sem_num)
{
    bsp_resource_state_t status = BSP_RESOURCE_STATE_BEING_USED;

    /* If the resource is not in use, a non-zero value will be returned. */
    if (BSP_SEMAPHORE_EXTERNAL_HOST_REGISTER(sem_num))
    {
        status = BSP_RESOURCE_STATE_NOT_BEING_USED;
    }

    return status;
}

/*******************************************************************************************************************//**
 * Release the external host semaphore.
 *
 * @param[in]  sem_num Semaphore number to read resource status.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_ExternalHostSemaphoreRelease (bsp_resource_num_t sem_num)
{
    __DMB();
    BSP_SEMAPHORE_EXTERNAL_HOST_REGISTER(sem_num) = BSP_SEMAPHORE_EXTERNAL_HOST_RESOURCE_NOT_USED;
}

 #endif

#endif

/** @} (end addtogroup BSP_MCU) */
#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/* Public functions defined in bsp.h */
void bsp_semaphore_init(void);         // Used internally by BSP

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
