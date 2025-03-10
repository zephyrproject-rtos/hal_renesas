/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_address_convert.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_ADDRESS_TABLE_END    (0xFFFFFFFF)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef struct bsp_address_convert_table
{
    uint32_t original_address;         ///< Base address of CPU Address space
    uint32_t converted_address;        ///< Base address of Bus-master's Address space
    uint32_t size;                     ///< size of region (byte)
} r_bsp_address_convert_table_t;

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
r_bsp_address_convert_table_t g_address_convert_table_array[] =
{
    BSP_ADDRESS_CONVERT_TABLE_BODY,
    {BSP_PRV_ADDRESS_TABLE_END,    BSP_PRV_ADDRESS_TABLE_END,BSP_PRV_ADDRESS_TABLE_END}
};

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */

/*******************************************************************************************************************//**
 * Converts the cpu address specified in the argument to the bus address.
 * If an address that does not exist in the external-bus is specified, it will not be converted.
 *
 * @param[in]  original_address    Address that CPU access to slave.
 *
 * @retval     converted_address   Address that Bus-master device access to slave.
 **********************************************************************************************************************/
uint32_t R_BSP_SlaveAddressConversion (uint32_t original_address)
{
    uint32_t converted_address = original_address; // Set unconverted address as initial value.
    r_bsp_address_convert_table_t * p_convert_table = &g_address_convert_table_array[0];

    for ( ; BSP_PRV_ADDRESS_TABLE_END != p_convert_table->original_address; p_convert_table++)
    {
        uint32_t region_base = p_convert_table->original_address;
        if ((region_base <= original_address) && (original_address < (region_base + p_convert_table->size)))
        {
            /* find region: convert address */
            converted_address = (original_address & (p_convert_table->size - 1)) | p_convert_table->converted_address;

            /* exit loop */
            break;
        }
    }

    return converted_address;
}
