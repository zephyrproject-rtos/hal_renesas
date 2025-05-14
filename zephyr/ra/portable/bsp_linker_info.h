/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_LINKER_H
#define BSP_LINKER_H

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/******* Solution Definitions *************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
/* linker generated initialization table data structures types */
typedef enum e_bsp_init_mem
{
    INIT_MEM_ZERO,
    INIT_MEM_FLASH,
    INIT_MEM_DATA_FLASH,
    INIT_MEM_RAM,
    INIT_MEM_DTCM,
    INIT_MEM_ITCM,
    INIT_MEM_CTCM,
    INIT_MEM_STCM,
    INIT_MEM_OSPI0_CS0,
    INIT_MEM_OSPI0_CS1,
    INIT_MEM_OSPI1_CS0,
    INIT_MEM_OSPI1_CS1,
    INIT_MEM_QSPI_FLASH,
    INIT_MEM_SDRAM,
} bsp_init_mem_t;

typedef struct st_bsp_init_type
{
    uint32_t destination_type :8;
    uint32_t source_type :8;
    uint32_t destination_external :1; /* =1 if destination type is external, else internal  */
    uint32_t source_external :1; /* =1 if source type is external, else internal  */
    uint32_t external :1; /* =1 if either source or destination is external, else 0  */
    uint32_t copy_64 :1; /* if 1, must use 64 bit copy operation (to keep ecc happy) */
} bsp_init_type_t;

typedef struct st_bsp_init_zero_info
{
    uint32_t *const p_base;
    uint32_t *const p_limit;
    bsp_init_type_t type;
} bsp_init_zero_info_t;

typedef struct st_bsp_init_copy_info
{
    uint32_t *const p_base;
    uint32_t *const p_limit;
    uint32_t *const p_load;
    bsp_init_type_t type;
} bsp_init_copy_info_t;
typedef struct st_bsp_init_nocache_info
{
    uint32_t *const p_base;
    uint32_t *const p_limit;
} bsp_mpu_nocache_info_t;

typedef struct st_bsp_init_info
{
    uint32_t zero_count;
    bsp_init_zero_info_t const *const p_zero_list;
    uint32_t copy_count;
    bsp_init_copy_info_t const *const p_copy_list;
    uint32_t nocache_count;
    bsp_mpu_nocache_info_t const *const p_nocache_list;
} bsp_init_info_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

extern bsp_init_info_t const g_init_info;
/* These symbols are used for sau/idau configuration in a secure project */

#endif   // BSP_LINKER_C

/* UNCRUSTIFY-ON */
