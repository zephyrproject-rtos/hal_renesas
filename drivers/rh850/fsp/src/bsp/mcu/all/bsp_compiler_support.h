/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* PRQA S 0292 ++ # DP_MSR_D-1.1_UC1 */

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 * @{
 **********************************************************************************************************************/

/* PRQA S 0292 -- */
#ifndef BSP_COMPILER_SUPPORT_H_
#define BSP_COMPILER_SUPPORT_H_

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Stacks (and heap) must be sized and aligned to an integer multiple of this number. */
#define BSP_STACK_ALIGNMENT    (8)     /* PRQA S 1534 # Advisory R-2.5 */
#define BSP_DONT_REMOVE

/** Convert token into a string and pass it to _Pragma */
#ifndef   BSP_PRAGMA_HELPER
 #define BSP_PRAGMA_HELPER(x)        _Pragma(#x) /* PRQA S 0341 # Advisory R-20.10 */                                            ///< Helper macro: stringize token and pass to _Pragma
#endif

#define DI()                         __DI() /* PRQA S 1534, 1710 # Advisory R-2.5, Advisory D-4.5 */                             ///< Disable interrupts
#define EI()                         __EI() /* PRQA S 1534, 1710 # Advisory R-2.5, Advisory D-4.5 */                             ///< Enable interrupts
#define HALT()                       __HALT() /* PRQA S 1534, 1710 # Advisory R-2.5, Advisory D-4.5 */                           ///< Halt CPU execution
#define NOP()                        __NOP() /* PRQA S 1534, 1710, 3472 # Advisory R-2.5, Advisory D-4.5, Advisory D-4.9 */      ///< No-operation instruction
#define SYNCP()                      __SYNCP() /* PRQA S 1534, 1710, 3472 # Advisory R-2.5, Advisory D-4.5, Advisory D-4.9 */    ///< Synchronize pipeline
#define SCH1R(x)                     __SCH1R((x)) /* PRQA S 1534, 1710, 3472 # Advisory R-2.5, Advisory D-4.5, Advisory D-4.9 */ ///< Bit (1) search from LSB side
#define LDSR(regid, ret)             __LDSR((regid), (0), (ret)) /* PRQA S 1534, 1710 # Advisory R-2.5, Advisory D-4.5 */        ///< Load system register
#define STSR(regid)                  __STSR((regid), (0)) /* PRQA S 1534, 1710 # Advisory R-2.5, Advisory D-4.5 */               ///< Store system register
#define STSR_REGSEL(regID, selID)    __STSR((regID), (selID)) /* PRQA S 1534 # Advisory R-2.5 */                                 ///< Store system register with selector

#if defined(__CCRH__)

/* Create the pragma inline statement with the function name as argument */
 #define BSP_PRAGMA_SECTION_OPTION_BYTE           .OPBT_top                                                         ///< Section name: option bytes (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_DEFAULT               default                                                           ///< Default section name (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_TEXT        .CRUN_CODE /* PRQA S 1534 # Advisory R-2.5 */                     ///< CRUN text section tag (compiler-specific) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_DATA        .CRUN_CODE /* PRQA S 1534 # Advisory R-2.5 */                     ///< CRUN data section tag (compiler-specific) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_ROM_DATA    .CRUN_CODE /* PRQA S 1534 # Advisory R-2.5 */                     ///< CRUN ROM-data section tag (compiler-specific) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_BSS         .CRUN_CODE /* PRQA S 1534 # Advisory R-2.5 */                     ///< CRUN BSS section tag (compiler-specific) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_INTVECT_PE0      .CRUN_inttable_PE0 /* PRQA S 1534 # Advisory R-2.5 */             ///< CRUN interrupt table (PE0) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE0           .inttable_PE0                                                     ///< Interrupt table section (PE0) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE1           .inttable_PE1 /* PRQA S 1534 # Advisory R-2.5 */                  ///< Interrupt table section (PE1) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE2           .inttable_PE2 /* PRQA S 1534 # Advisory R-2.5 */                  ///< Interrupt table section (PE2) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE3           .inttable_PE3 /* PRQA S 1534 # Advisory R-2.5 */                  ///< Interrupt table section (PE3) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE4           .inttable_PE4 /* PRQA S 1534 # Advisory R-2.5 */                  ///< Interrupt table section (PE4) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE5           .inttable_PE5 /* PRQA S 1534 # Advisory R-2.5 */                  ///< Interrupt table section (PE5) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE6           .inttable_PE6 /* PRQA S 1534 # Advisory R-2.5 */                  ///< Interrupt table section (PE6) (used for BSP_PRAGMA_PLACE_IN_SECTION)

 #define BSP_PRAGMA_SECTION_CRUN_DATA             /* PRQA S 1534 # Advisory R-2.5 */                                ///< Placeholder: CRUN data section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_CRUN_ROM_DATA         /* PRQA S 1534 # Advisory R-2.5 */                                ///< Placeholder: CRUN ROM-data section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_CRUN_BSS              /* PRQA S 1534 # Advisory R-2.5 */                                ///< Placeholder: CRUN BSS section (empty on CCRH)

 #define BSP_PRAGMA_SECTION_DATA                  /* PRQA S 1534 # Advisory R-2.5 */                                ///< Placeholder: data section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_ROM_DATA              /* PRQA S 1534 # Advisory R-2.5 */                                ///< Placeholder: ROM data section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_BSS                   /* PRQA S 1534 # Advisory R-2.5 */                                ///< Placeholder: BSS section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_TEXT                  /* PRQA S 1534 # Advisory R-2.5 */                                ///< Placeholder: text/code section (empty on CCRH)
 #define BSP_PRAGMA_PLACE_IN_SECTION(sec, name)    BSP_PRAGMA_HELPER(section name)                                  ///< Apply section placement via pragma

 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_SMALL        /* PRQA S 1534 # Advisory R-2.5 */                                ///< Small  memory attribute
 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_MEDIUM       /* PRQA S 1534 # Advisory R-2.5 */                                ///< Medium memory attribute
 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_LARGE        /* PRQA S 1534 # Advisory R-2.5 */                                ///< Large  memory attribute
 #define BSP_PRAGMA_TYPE_ATTRIBUTE(name)           /* PRQA S 1534 # Advisory R-2.5 */                               ///< Apply type attribute via pragma

/* Compiler neutral macros. */
 #define BSP_PLACE_IN_SECTION(x)                   __attribute__((section(x)))                                      ///< Apply section attribute and keep symbol
 #define BSP_FORCE_INLINE                         __attribute__((always_inline)) /* PRQA S 1534 # Advisory R-2.5 */ ///< Force function to inline (CCRH-compatible attribute)
 #define BSP_NO_INLINE                            __attribute__((noinline)) /* PRQA S 1534 # Advisory R-2.5 */      ///< Prevent inlining (CCRH-compatible attribute)
 #define BSP_ALIGN_VARIABLE(x)                     __attribute__((aligned(x))) /* PRQA S 1534 # Advisory R-2.5 */   ///< Force variable alignment to x-byte boundary (CCRH-compatible attribute)

 #define BSP_SECTION_FENMI_TEXT                   "FENMI"                                                           ///< Section name for FENMI handler code
 #define BSP_SECTION_FEINT_TEXT                   "FEINT"                                                           ///< Section name for FEINT handler code

 #define BSP_SECTION_STACK_PE0_BSS                ".pe0_stack"                                                      ///< Section name for stack (PE0)
 #define BSP_SECTION_STACK_PE1_BSS                ".pe1_stack" /* PRQA S 1534 # Advisory R-2.5 */                   ///< Section name for stack (PE1)
 #define BSP_SECTION_STACK_PE2_BSS                ".pe2_stack" /* PRQA S 1534 # Advisory R-2.5 */                   ///< Section name for stack (PE2)
 #define BSP_SECTION_STACK_PE3_BSS                ".pe3_stack" /* PRQA S 1534 # Advisory R-2.5 */                   ///< Section name for stack (PE3)
 #define BSP_SECTION_STACK_PE4_BSS                ".pe4_stack" /* PRQA S 1534 # Advisory R-2.5 */                   ///< Section name for stack (PE4)
 #define BSP_SECTION_STACK_PE5_BSS                ".pe5_stack" /* PRQA S 1534 # Advisory R-2.5 */                   ///< Section name for stack (PE5)
 #define BSP_SECTION_STACK_PE6_BSS                ".pe6_stack" /* PRQA S 1534 # Advisory R-2.5 */                   ///< Section name for stack (PE6)

 #define BSP_SECTION_INTERRUPT_TABLE_PE0          ".inttable_PE0.const" /* PRQA S 1534 # Advisory R-2.5 */          ///< Section name for interrupt table (PE0)
 #define BSP_SECTION_INTERRUPT_TABLE_PE1          ".inttable_PE1.const" /* PRQA S 1534 # Advisory R-2.5 */          ///< Section name for interrupt table (PE1)
 #define BSP_SECTION_INTERRUPT_TABLE_PE2          ".inttable_PE2.const" /* PRQA S 1534 # Advisory R-2.5 */          ///< Section name for interrupt table (PE2)
 #define BSP_SECTION_INTERRUPT_TABLE_PE3          ".inttable_PE3.const" /* PRQA S 1534 # Advisory R-2.5 */          ///< Section name for interrupt table (PE3)
 #define BSP_SECTION_INTERRUPT_TABLE_PE4          ".inttable_PE4.const" /* PRQA S 1534 # Advisory R-2.5 */          ///< Section name for interrupt table (PE4)
 #define BSP_SECTION_INTERRUPT_TABLE_PE5          ".inttable_PE5.const" /* PRQA S 1534 # Advisory R-2.5 */          ///< Section name for interrupt table (PE5)
 #define BSP_SECTION_INTERRUPT_TABLE_PE6          ".inttable_PE6.const" /* PRQA S 1534 # Advisory R-2.5 */          ///< Section name for interrupt table (PE6)

 #define BSP_SECTION_OPTION_BYTE                  ".OPBT_top" /* PRQA S 1534 # Advisory R-2.5 */                    ///< Section name: option bytes (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_TEXT               ".CRUN_CODE.text" /* PRQA S 1534 # Advisory R-2.5 */              ///< CRUN text section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_DATA               ".CRUN_CODE.data" /* PRQA S 1534 # Advisory R-2.5 */              ///< CRUN data section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_ROM_DATA           ".CRUN_CODE.const" /* PRQA S 1534 # Advisory R-2.5 */             ///< CRUN ROM-data section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_BSS                ".CRUN_CODE.bss" /* PRQA S 1534 # Advisory R-2.5 */               ///< CRUN BSS section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_INTVECT_PE0             ".CRUN_inttable_PE0.const" /* PRQA S 1534 # Advisory R-2.5 */     ///< CRUN interrupt table (PE0) (used for BSP_PLACE_IN_SECTION)

 #define BSP_SECTION_NOINIT                       ".noinit" /* PRQA S 1534 # Advisory R-2.5 */                      ///< No initialization section

/* Heap section */
 #ifndef BSP_SECTION_HEAP
  #define BSP_SECTION_HEAP                        ".main_heap"                                                      ///< Section name for heap
 #endif

/* Stack section */
 #ifndef BSP_SECTION_STACK
  #define BSP_SECTION_STACK            ///< Placeholder: stack section tag (empty on CCRH)
 #endif

#elif defined(__ghs__)

 #define BSP_PRAGMA_OPEN(sec, name)                    BSP_PRAGMA_HELPER(ghs startdata) BSP_PRAGMA_HELPER( \
        ghs section sec = name)                                                                          ///< Open section
 #define BSP_PRAGMA_CLOSE(sec)                         BSP_PRAGMA_HELPER(ghs section sec = default) BSP_PRAGMA_HELPER( \
        ghs enddata)                                                                                     ///< Close block

/* Create the pragma inline statement with the function name as argument */
 #define BSP_PRAGMA_SECTION_OPTION_BYTE(sec)           BSP_PRAGMA_OPEN(sec, ".OPBT_top")                 ///< Section name: option bytes (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_DEFAULT(sec)               BSP_PRAGMA_CLOSE(sec)                             ///< Default section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_TEXT(sec)        BSP_PRAGMA_OPEN(sec, ".CRUN_CODE.text")           ///< CRUN text section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_DATA(sec)        BSP_PRAGMA_OPEN(sec, ".CRUN_CODE.data")           ///< CRUN small data section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_ROM_DATA(sec)    BSP_PRAGMA_OPEN(sec, ".CRUN_CODE.rodata")         ///< CRUN ROM small data section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_BSS(sec)         BSP_PRAGMA_OPEN(sec, ".CRUN_CODE.bss")            ///< CRUN small BSS section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_INTVECT_PE0(sec)      BSP_PRAGMA_OPEN(sec, ".CRUN_inttable_PE0")        ///< CRUN interrupt table (PE0) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE0(sec)           BSP_PRAGMA_OPEN(sec, ".inttable_PE0")             ///< Interrupt table section (PE0) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE1(sec)           BSP_PRAGMA_OPEN(sec, ".inttable_PE1")             ///< Interrupt table section (PE1) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE2(sec)           BSP_PRAGMA_OPEN(sec, ".inttable_PE2")             ///< Interrupt table section (PE2) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE3(sec)           BSP_PRAGMA_OPEN(sec, ".inttable_PE3")             ///< Interrupt table section (PE3) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE4(sec)           BSP_PRAGMA_OPEN(sec, ".inttable_PE4")             ///< Interrupt table section (PE4) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE5(sec)           BSP_PRAGMA_OPEN(sec, ".inttable_PE5")             ///< Interrupt table section (PE5) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE6(sec)           BSP_PRAGMA_OPEN(sec, ".inttable_PE6")             ///< Interrupt table section (PE6) (used for BSP_PRAGMA_PLACE_IN_SECTION)

 #define BSP_PRAGMA_SECTION_CRUN_DATA          data                                                      ///< Section tag: data
 #define BSP_PRAGMA_SECTION_CRUN_ROM_DATA      rodata                                                    ///< Section tag: read-only data
 #define BSP_PRAGMA_SECTION_CRUN_BSS           bss                                                       ///< Section tag: BSS

 #define BSP_PRAGMA_SECTION_DATA               data                                                      ///< Section tag: data
 #define BSP_PRAGMA_SECTION_ROM_DATA           rodata                                                    ///< Section tag: read-only data
 #define BSP_PRAGMA_SECTION_BSS                bss                                                       ///< Section tag: BSS
 #define BSP_PRAGMA_SECTION_TEXT               text                                                      ///< Section tag: text/code
 #define BSP_PRAGMA_PLACE_IN_SECTION(sec, name)    name(sec)                                             ///< Place symbol in section

 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_SMALL                                                               ///< Small  memory attribute
 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_MEDIUM                                                              ///< Medium memory attribute
 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_LARGE                                                               ///< Large  memory attribute
 #define BSP_PRAGMA_TYPE_ATTRIBUTE(name)                                                                 ///< Apply type attribute via pragma

/* Compiler neutral macros. */
 #define BSP_PLACE_IN_SECTION(x)                   __attribute__((section(x))) __attribute__((__used__)) ///< Apply section attribute and keep symbol
 #define BSP_FORCE_INLINE                      __attribute__((always_inline))                            ///< Force inline for functions
 #define BSP_NO_INLINE                         __attribute__((noinline))                                 ///< Prevent function inlining
 #define BSP_ALIGN_VARIABLE(x)                     __attribute__((aligned(x)))                           ///< Force variable alignment to x-byte boundary

 #define BSP_SECTION_FENMI_TEXT                "FENMI.text"                                              ///< Section name for FENMI handler code
 #define BSP_SECTION_FEINT_TEXT                "FEINT.text"                                              ///< Section name for FEINT handler code

 #define BSP_SECTION_STACK_PE0_BSS             ".pe0_stack"                                              ///< Section name for stack (PE0)
 #define BSP_SECTION_STACK_PE1_BSS             ".pe1_stack"                                              ///< Section name for stack (PE1)
 #define BSP_SECTION_STACK_PE2_BSS             ".pe2_stack"                                              ///< Section name for stack (PE2)
 #define BSP_SECTION_STACK_PE3_BSS             ".pe3_stack"                                              ///< Section name for stack (PE3)
 #define BSP_SECTION_STACK_PE4_BSS             ".pe4_stack"                                              ///< Section name for stack (PE4)
 #define BSP_SECTION_STACK_PE5_BSS             ".pe5_stack"                                              ///< Section name for stack (PE5)
 #define BSP_SECTION_STACK_PE6_BSS             ".pe6_stack"                                              ///< Section name for stack (PE6)

 #define BSP_SECTION_INTERRUPT_TABLE_PE0       ".inttable_PE0"                                           ///< Section name for interrupt table (PE0)
 #define BSP_SECTION_INTERRUPT_TABLE_PE1       ".inttable_PE1"                                           ///< Section name for interrupt table (PE1)
 #define BSP_SECTION_INTERRUPT_TABLE_PE2       ".inttable_PE2"                                           ///< Section name for interrupt table (PE2)
 #define BSP_SECTION_INTERRUPT_TABLE_PE3       ".inttable_PE3"                                           ///< Section name for interrupt table (PE3)
 #define BSP_SECTION_INTERRUPT_TABLE_PE4       ".inttable_PE4"                                           ///< Section name for interrupt table (PE4)
 #define BSP_SECTION_INTERRUPT_TABLE_PE5       ".inttable_PE5"                                           ///< Section name for interrupt table (PE5)
 #define BSP_SECTION_INTERRUPT_TABLE_PE6       ".inttable_PE6"                                           ///< Section name for interrupt table (PE6)

 #define BSP_SECTION_OPTION_BYTE               ".OPBT_top"                                               ///< Section name: option bytes (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_TEXT            ".CRUN_CODE.text"                                         ///< CRUN text section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_DATA            ".CRUN_CODE.data"                                         ///< CRUN data section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_ROM_DATA        ".CRUN_CODE.rodata"                                       ///< CRUN ROM-data section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_BSS             ".CRUN_CODE.bss"                                          ///< CRUN BSS section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_INTVECT_PE0          ".CRUN_inttable_PE0.data"                                 ///< CRUN interrupt table (PE0) (used for BSP_PLACE_IN_SECTION)

 #define BSP_SECTION_NOINIT                    ".noinit"                                                 ///< No initialization section

/* Heap section */
 #ifndef BSP_SECTION_HEAP
  #define BSP_SECTION_HEAP                     ".heap"                                                   ///< Section name for heap
 #endif

/* Stack section */
 #ifndef BSP_SECTION_STACK
  #define BSP_SECTION_STACK            ///< Placeholder: stack section tag
 #endif

#elif defined(__GNUC__)

/* Create the pragma inline statement with the function name as argument */
 #define BSP_PRAGMA_SECTION_OPTION_BYTE           OPBT_top                                               ///< Section name: option bytes (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_DEFAULT               default                                                ///< Default section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_TEXT        CRUN_CODE_text                                         ///< CRUN text section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_DATA        CRUN_CODE_data                                         ///< CRUN data section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_ROM_DATA    CRUN_CODE_rodata                                       ///< CRUN read-only data section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_BSS         CRUN_CODE_bss                                          ///< CRUN BSS section (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_INTVECT_PE0      CRUN_inttable_PE0_data                                 ///< CRUN interrupt table (PE0) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE0           inttable_PE0_data                                      ///< Interrupt table section (PE0) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE1           inttable_PE1_data                                      ///< Interrupt table section (PE1) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE2           inttable_PE2_data                                      ///< Interrupt table section (PE2) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE3           inttable_PE3_data                                      ///< Interrupt table section (PE3) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE4           inttable_PE4_data                                      ///< Interrupt table section (PE4) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE5           inttable_PE5_data                                      ///< Interrupt table section (PE5) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE6           inttable_PE6_data                                      ///< Interrupt table section (PE6) (used for BSP_PRAGMA_PLACE_IN_SECTION)

 #define BSP_PRAGMA_SECTION_CRUN_DATA             data                                                   ///< Generic data section tag
 #define BSP_PRAGMA_SECTION_CRUN_ROM_DATA         rodata                                                 ///< Generic read-only data section tag
 #define BSP_PRAGMA_SECTION_CRUN_BSS              bss                                                    ///< Generic BSS section tag

 #define BSP_PRAGMA_SECTION_DATA                  data                                                   ///< Data section
 #define BSP_PRAGMA_SECTION_ROM_DATA              rodata                                                 ///< Read-only data section
 #define BSP_PRAGMA_SECTION_BSS                   bss                                                    ///< BSS section
 #define BSP_PRAGMA_SECTION_TEXT                  text                                                   ///< Text/code section
 #define BSP_PRAGMA_PLACE_IN_SECTION(sec, name)   BSP_PRAGMA_HELPER(ghs section sec = name)             ///< Place symbol in section

 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_SMALL                                                               ///< Small  memory attribute
 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_MEDIUM                                                              ///< Medium memory attribute
 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_LARGE                                                               ///< Large  memory attribute
 #define BSP_PRAGMA_TYPE_ATTRIBUTE(name)                                                                 ///< Apply type attribute via pragma

/* Compiler neutral macros. */
 #define BSP_PLACE_IN_SECTION(x)                   __attribute__((section(x))) __attribute__((__used__)) ///< Apply section attribute and keep symbol
 #define BSP_FORCE_INLINE                         __attribute__((always_inline))                         ///< Force inline for functions
 #define BSP_NO_INLINE                            __attribute__((noinline))                              ///< Prevent function inlining
 #define BSP_ALIGN_VARIABLE(x)                     __attribute__((aligned(x)))                           ///< Force variable alignment to x-byte boundary

 #define BSP_SECTION_FENMI_TEXT                   "FENMI.text"                                           ///< Section name for FENMI handler code
 #define BSP_SECTION_FEINT_TEXT                   "FEINT.text"                                           ///< Section name for FEINT handler code

 #define BSP_SECTION_STACK_PE0_BSS                ".pe0_stack.bss"                                       ///< Section name for stack (PE0)
 #define BSP_SECTION_STACK_PE1_BSS                ".pe1_stack.bss"                                       ///< Section name for stack (PE1)
 #define BSP_SECTION_STACK_PE2_BSS                ".pe2_stack.bss"                                       ///< Section name for stack (PE2)
 #define BSP_SECTION_STACK_PE3_BSS                ".pe3_stack.bss"                                       ///< Section name for stack (PE3)
 #define BSP_SECTION_STACK_PE4_BSS                ".pe4_stack.bss"                                       ///< Section name for stack (PE4)
 #define BSP_SECTION_STACK_PE5_BSS                ".pe5_stack.bss"                                       ///< Section name for stack (PE5)
 #define BSP_SECTION_STACK_PE6_BSS                ".pe6_stack.bss"                                       ///< Section name for stack (PE6)

 #define BSP_SECTION_INTERRUPT_TABLE_PE0          ".inttable_PE0.data"                                   ///< Section name for interrupt table (PE0)
 #define BSP_SECTION_INTERRUPT_TABLE_PE1          ".inttable_PE1.data"                                   ///< Section name for interrupt table (PE1)
 #define BSP_SECTION_INTERRUPT_TABLE_PE2          ".inttable_PE2.data"                                   ///< Section name for interrupt table (PE2)
 #define BSP_SECTION_INTERRUPT_TABLE_PE3          ".inttable_PE3.data"                                   ///< Section name for interrupt table (PE3)
 #define BSP_SECTION_INTERRUPT_TABLE_PE4          ".inttable_PE4.data"                                   ///< Section name for interrupt table (PE4)
 #define BSP_SECTION_INTERRUPT_TABLE_PE5          ".inttable_PE5.data"                                   ///< Section name for interrupt table (PE5)
 #define BSP_SECTION_INTERRUPT_TABLE_PE6          ".inttable_PE6.data"                                   ///< Section name for interrupt table (PE6)

 #define BSP_SECTION_OPTION_BYTE                  ".OPBT_top"                                            ///< Section name: option bytes (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_TEXT               ".CRUN_CODE.text"                                      ///< CRUN text section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_DATA               ".CRUN_CODE.data"                                      ///< CRUN data section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_ROM_DATA           ".CRUN_CODE.const"                                     ///< CRUN ROM-data section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_BSS                ".CRUN_CODE.bss"                                       ///< CRUN BSS section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_INTVECT_PE0             ".CRUN_inttable_PE0.data"                              ///< CRUN interrupt table (PE0) (used for BSP_PLACE_IN_SECTION)

 #define BSP_SECTION_NOINIT                       ".noinit"                                              ///< No initialization section

/* Heap section */
 #ifndef BSP_SECTION_HEAP
  #define BSP_SECTION_HEAP                        ".heap"                                                ///< Section name for heap
 #endif

/* Stack section */
 #ifndef BSP_SECTION_STACK
  #define BSP_SECTION_STACK                       ".stack" ///< Section name for stack
 #endif

#elif defined(__ICCRH850__)

/* Create the pragma inline statement with the function name as argument */
 #define BSP_PRAGMA_SECTION_OPTION_BYTE           @".OPBT_top"                                           ///< Section name: option bytes (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_DEFAULT                                                                      ///< Default section name (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_TEXT        @".CRUN_CODE.text"                                     ///< CRUN text section tag (compiler-specific) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_DATA        @".CRUN_CODE.data"                                     ///< CRUN data section tag (compiler-specific) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_ROM_DATA    @".CRUN_CODE.rodata"                                   ///< CRUN ROM-data section tag (compiler-specific) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_CODE_BSS         @".CRUN_CODE.bss"                                      ///< CRUN BSS section tag (compiler-specific) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_CRUN_INTVECT_PE0      @".CRUN_inttable_PE0.data"                             ///< CRUN interrupt table (PE0) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE0           @".inttable_PE0.data"                                  ///< Interrupt table section (PE0) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE1           @".inttable_PE1.data"                                  ///< Interrupt table section (PE1) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE2           @".inttable_PE2.data"                                  ///< Interrupt table section (PE2) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE3           @".inttable_PE3.data"                                  ///< Interrupt table section (PE3) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE4           @".inttable_PE4.data"                                  ///< Interrupt table section (PE4) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE5           @".inttable_PE5.data"                                  ///< Interrupt table section (PE5) (used for BSP_PRAGMA_PLACE_IN_SECTION)
 #define BSP_PRAGMA_SECTION_INTVECT_PE6           @".inttable_PE6.data"                                  ///< Interrupt table section (PE6) (used for BSP_PRAGMA_PLACE_IN_SECTION)

 #define BSP_PRAGMA_SECTION_CRUN_DATA             default_variable_attributes                            ///< Placeholder: CRUN data section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_CRUN_ROM_DATA         default_variable_attributes                            ///< Placeholder: CRUN ROM-data section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_CRUN_BSS              default_variable_attributes                            ///< Placeholder: CRUN BSS section (empty on CCRH)

 #define BSP_PRAGMA_SECTION_DATA                  default_variable_attributes                            ///< Placeholder: data section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_ROM_DATA              default_variable_attributes                            ///< Placeholder: ROM data section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_BSS                   default_variable_attributes                            ///< Placeholder: BSS section (empty on CCRH)
 #define BSP_PRAGMA_SECTION_TEXT                  default_function_attributes                            ///< Placeholder: text/code section (empty on CCRH)
 #define BSP_PRAGMA_PLACE_IN_SECTION(sec, name)    BSP_PRAGMA_HELPER(sec = name)                         ///< Apply section placement via pragma

 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_SMALL        __brel                                                 ///< Small  memory attribute
 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_MEDIUM       __brel23                                               ///< Medium memory attribute
 #define BSP_PRAGMA_MEMORY_ATTRIBUTE_LARGE        __huge                                                 ///< Large  memory attribute
 #define BSP_PRAGMA_TYPE_ATTRIBUTE(name)           BSP_PRAGMA_HELPER(type_attribute = name)              ///< Apply type attribute via pragma

/* Compiler neutral macros. */
 #define BSP_PLACE_IN_SECTION(x)                   __attribute__((section(x))) __attribute__((__used__)) ///< Apply section attribute and keep symbol
 #define BSP_FORCE_INLINE                         __attribute__((always_inline)) static __inline         ///< Force inline for functions
 #define BSP_NO_INLINE                            __attribute__((noinline))                              ///< Prevent function inlining
 #define BSP_ALIGN_VARIABLE(x)                     __attribute__((aligned(x)))                           ///< Force variable alignment to x-byte boundary

 #define BSP_SECTION_FENMI_TEXT                   "FENMI.text"                                           ///< Section name for FENMI handler code
 #define BSP_SECTION_FEINT_TEXT                   "FEINT.text"                                           ///< Section name for FEINT handler code

 #define BSP_SECTION_STACK_PE0_BSS                ".pe0_stack.bss"                                       ///< Section name for stack (PE0)
 #define BSP_SECTION_STACK_PE1_BSS                ".pe1_stack.bss"                                       ///< Section name for stack (PE1)
 #define BSP_SECTION_STACK_PE2_BSS                ".pe2_stack.bss"                                       ///< Section name for stack (PE2)
 #define BSP_SECTION_STACK_PE3_BSS                ".pe3_stack.bss"                                       ///< Section name for stack (PE3)
 #define BSP_SECTION_STACK_PE4_BSS                ".pe4_stack.bss"                                       ///< Section name for stack (PE4)
 #define BSP_SECTION_STACK_PE5_BSS                ".pe5_stack.bss"                                       ///< Section name for stack (PE5)
 #define BSP_SECTION_STACK_PE6_BSS                ".pe6_stack.bss"                                       ///< Section name for stack (PE6)

 #define BSP_SECTION_INTERRUPT_TABLE_PE0          ".inttable_PE0.data"                                   ///< Section name for interrupt table (PE0)
 #define BSP_SECTION_INTERRUPT_TABLE_PE1          ".inttable_PE1.data"                                   ///< Section name for interrupt table (PE1)
 #define BSP_SECTION_INTERRUPT_TABLE_PE2          ".inttable_PE2.data"                                   ///< Section name for interrupt table (PE2)
 #define BSP_SECTION_INTERRUPT_TABLE_PE3          ".inttable_PE3.data"                                   ///< Section name for interrupt table (PE3)
 #define BSP_SECTION_INTERRUPT_TABLE_PE4          ".inttable_PE4.data"                                   ///< Section name for interrupt table (PE4)
 #define BSP_SECTION_INTERRUPT_TABLE_PE5          ".inttable_PE5.data"                                   ///< Section name for interrupt table (PE5)
 #define BSP_SECTION_INTERRUPT_TABLE_PE6          ".inttable_PE6.data"                                   ///< Section name for interrupt table (PE6)

 #define BSP_SECTION_OPTION_BYTE                  ".OPBT_top"                                            ///< Section name: option bytes (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_TEXT               ".CRUN_CODE.text"                                      ///< CRUN text section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_DATA               ".CRUN_CODE.data"                                      ///< CRUN data section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_ROM_DATA           ".CRUN_CODE.rodata"                                    ///< CRUN ROM-data section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_CODE_BSS                ".CRUN_CODE.bss"                                       ///< CRUN BSS section tag (compiler-specific) (used for BSP_PLACE_IN_SECTION)
 #define BSP_SECTION_CRUN_INTVECT_PE0             ".CRUN_inttable_PE0.data"                              ///< CRUN interrupt table (PE0) (used for BSP_PLACE_IN_SECTION)

 #define BSP_SECTION_NOINIT                       ".noinit"                                              ///< No initialization section

/* Heap section */
 #ifndef BSP_SECTION_HEAP
  #define BSP_SECTION_HEAP                        ".heap"                                                ///< Section name for heap
 #endif

/* Stack section */
 #ifndef BSP_SECTION_STACK
  #define BSP_SECTION_STACK                       ".stack" ///< Section name for stack
 #endif
#endif

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_COMMON)
 **********************************************************************************************************************/

#endif                                 /* BSP_COMPILER_SUPPORT_H_ */
