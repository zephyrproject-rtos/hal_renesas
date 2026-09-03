/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_STACK_LIMIT    ((uint32_t) &g_main_stack[0])
#define BSP_PRV_STACK_TOP      ((uint32_t) (&g_main_stack[0] + BSP_CFG_STACK_MAIN_BYTES))

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Defines function pointers to be used with vector table. */
typedef void (* exc_ptr_t)(void);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
extern void * g_vector_table[];

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
void    Reset_Handler(void);
void    Default_Handler(void);
int32_t main(void);

/* Main stack */
uint8_t g_main_stack[BSP_CFG_STACK_MAIN_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_STACK);

/* Heap */
#if (BSP_CFG_HEAP_BYTES > 0)
BSP_DONT_REMOVE uint8_t g_heap[BSP_CFG_HEAP_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT) \
    BSP_PLACE_IN_SECTION(BSP_SECTION_HEAP);
#endif

const exc_ptr_t __Vectors[];

/*******************************************************************************************************************//**
 * MCU starts executing here out of reset. Main stack pointer is set up already.
 **********************************************************************************************************************/
void Reset_Handler (void)
{
    /* Initialize stack. */
    __SET_ISP(BSP_PRV_STACK_TOP);

    /* Initialize table. */
    __SET_EXTB(&__Vectors);
    __SET_INTB(&g_vector_table);

    /* Initialize system using BSP. */
    SystemInit();

    /* Call user application. */
    main();

    while (1)
    {
        /* Infinite Loop. */
    }
}

/*******************************************************************************************************************//**
 * Default exception handler.
 **********************************************************************************************************************/
void Default_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

#if defined(__CCRX__)
void PrivilegedInstructionException_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

void AccessException_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

void UndefinedInstruction_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

void AddressException_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

void SinglePrecisionFloatingPointException_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

void SecureFault_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

void World_NonMaskableInt_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

#endif

/* All system exceptions in the vector table are weak references to Default_Handler. If the user wishes to handle
 * these exceptions in their code they should define their own function with the same name.
 */

#if defined(__GNUC__) || defined(__ICCRX__)
 #define WEAK_REF_ATTRIBUTE    __attribute__((weak, alias("Default_Handler")))
#elif defined(__CCRX__)
 #define WEAK_REF_ATTRIBUTE    __attribute__((weak))
#endif

#if defined(__GNUC__) || defined(__ICCRX__)
extern BSP_ATTRIBUTE_STACKLESS void NMI_Handler(void); // NMI has many sources and is handled by BSP

#elif defined(__CCRX__)

extern void NMI_Handler(void);                         // NMI has many sources and is handled by BSP

#endif
void PrivilegedInstructionException_Handler(void) WEAK_REF_ATTRIBUTE;
void AccessException_Handler(void) WEAK_REF_ATTRIBUTE;
void UndefinedInstruction_Handler(void) WEAK_REF_ATTRIBUTE;
void AddressException_Handler(void) WEAK_REF_ATTRIBUTE;
void SinglePrecisionFloatingPointException_Handler(void) WEAK_REF_ATTRIBUTE;
void SecureFault_Handler(void) WEAK_REF_ATTRIBUTE;
void World_NonMaskableInt_Handler(void) WEAK_REF_ATTRIBUTE;

/* Vector table. */
BSP_DONT_REMOVE const exc_ptr_t __Vectors[] BSP_PLACE_IN_SECTION (BSP_SECTION_FIXED_VECTORS) =
{
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    SecureFault_Handler,                           /*  Secure exception                           */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    World_NonMaskableInt_Handler,                  /*  World Non-maskable interrupt               */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    PrivilegedInstructionException_Handler,        /*  Privileged instruction exception           */
    AccessException_Handler,                       /*  Access exception                           */
    0,                                             /*  Reserved                                   */
    UndefinedInstruction_Handler,                  /*  Undefined instruction exception            */
    AddressException_Handler,                      /*  Address exception                          */
    SinglePrecisionFloatingPointException_Handler, /*  Single-precision floating-point exception  */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    0,                                             /*  Reserved                                   */
    NMI_Handler,                                   /*  Non-maskable interrupt                     */
};

#ifndef BSP_BOOTLOADED_APPLICATION
/* Reset vector table. */
BSP_DONT_REMOVE const exc_ptr_t __Reset_Vector[] BSP_PLACE_IN_SECTION (BSP_SECTION_RESET_VECTOR) =
{
    Reset_Handler,                     /*  Reset Handler                              */
};
#else

/* Reset vector table for application image. */
BSP_DONT_REMOVE const exc_ptr_t __Reset_Vector[] BSP_PLACE_IN_SECTION (BSP_SECTION_ENTRY_POINT_APP) =
{
    Reset_Handler,                     /*  Reset Handler                              */
};
#endif

/** @} (end addtogroup BSP_MCU) */
