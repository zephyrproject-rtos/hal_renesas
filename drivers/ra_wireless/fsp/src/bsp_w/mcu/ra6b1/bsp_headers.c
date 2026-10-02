/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_PRV_PRODUCTION_HEADER_IDENTIFIER       0x646F7270 // "prod" in Little Endian
#define BSP_PRV_PRODUCTION_HEADER_PADDING_BYTES    18
#define BSP_PRV_IMAGE_HEADER_OFFSET                0x1A4
#define BSP_PRV_IMAGE_HEADER_IDENTIFIER            0x67616D69 // "imag" in Little Endian
#define BSP_PRV_IMAGE_HEADER_PADDING_BYTES         16
#define BSP_PRV_IMAGE_HEADER_IVT_OFFSET            0x0000001C

/* Reusable byte patterns for explicit 0xFF header padding in standard C. */
#define BSP_PRV_FF_1                               0xFFU
#define BSP_PRV_FF_2                               BSP_PRV_FF_1, BSP_PRV_FF_1
#define BSP_PRV_FF_4                               BSP_PRV_FF_2, BSP_PRV_FF_2
#define BSP_PRV_FF_8                               BSP_PRV_FF_4, BSP_PRV_FF_4
#define BSP_PRV_FF_16                              BSP_PRV_FF_8, BSP_PRV_FF_8
#define BSP_PRV_FF_32                              BSP_PRV_FF_16, BSP_PRV_FF_16
#define BSP_PRV_FF_64                              BSP_PRV_FF_32, BSP_PRV_FF_32
#define BSP_PRV_FF_128                             BSP_PRV_FF_64, BSP_PRV_FF_64
#define BSP_PRV_FF_256                             BSP_PRV_FF_128, BSP_PRV_FF_128

#define BSP_PLACE_IN_FLASH_GAP                     BSP_READ_ONLY BSP_PLACE_IN_SECTION(".flash_gap")

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef struct st_bsp_image_header
{
    uint32_t id;
    uint32_t version;
    uint8_t  padding[BSP_PRV_IMAGE_HEADER_PADDING_BYTES];
    uint32_t ivt_offset;
} bsp_image_header_t;

typedef struct st_bsp_product_header
{
    uint32_t id;
    volatile const bsp_image_header_t * p_active_img;
    volatile const bsp_image_header_t * p_update_img;
    uint16_t crc;
    uint8_t  pad[BSP_PRV_PRODUCTION_HEADER_PADDING_BYTES];
} bsp_product_header_t;

typedef struct st_bsp_headers
{
    bsp_product_header_t prod_hdr;
    bsp_product_header_t prod_hdr_backup;
    uint8_t              pad[BSP_PRV_IMAGE_HEADER_OFFSET];
    bsp_image_header_t   img_hdr;
} bsp_headers_t;

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
#if !(BSP_CFG_BOOT_IMAGE)

BSP_DONT_REMOVE BSP_PLACE_IN_FLASH_GAP volatile const bsp_headers_t bsp_prv_headers =
{
    .prod_hdr         =
    {
        .id           = BSP_PRV_PRODUCTION_HEADER_IDENTIFIER,
        .p_active_img = &bsp_prv_headers.img_hdr,
        .p_update_img = &bsp_prv_headers.img_hdr,
        .crc          = BSP_CFG_PRODUCTION_HEADER_CRC,
        .pad          = {BSP_PRV_FF_16, BSP_PRV_FF_2},
    },
    .prod_hdr_backup  =
    {
        .id           = BSP_PRV_PRODUCTION_HEADER_IDENTIFIER,
        .p_active_img = &bsp_prv_headers.img_hdr,
        .p_update_img = &bsp_prv_headers.img_hdr,
        .crc          = BSP_CFG_PRODUCTION_HEADER_CRC,
        .pad          = {BSP_PRV_FF_16, BSP_PRV_FF_2},
    },
    .pad              = {BSP_PRV_FF_256, BSP_PRV_FF_128, BSP_PRV_FF_32, BSP_PRV_FF_4},
    .img_hdr          =
    {
        .id         = BSP_PRV_IMAGE_HEADER_IDENTIFIER,
        .version    = BSP_CFG_IMAGE_HEADER_VERSION,
        .padding    = {BSP_PRV_FF_16},
        .ivt_offset = BSP_PRV_IMAGE_HEADER_IVT_OFFSET,
    }
};

#endif

/** @} (end addtogroup BSP_MCU) */
