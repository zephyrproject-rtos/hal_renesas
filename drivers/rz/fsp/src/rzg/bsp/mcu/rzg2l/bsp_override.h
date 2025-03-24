/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RZG2L
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RZG2L) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Define overrides required for this MCU. */
#define BSP_OVERRIDE_ADC_INCLUDE
#define BSP_OVERRIDE_ADC_INFO_T
#define BSP_OVERRIDE_DMAC_B_EXTERNAL_DETECTION_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_INFO_T
#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/*==============================================
 * DMAC_B External Detection Overrides
 *==============================================*/

 /** Detection method of the external DMA request signal. See RZ/T2M hardware manual Table 14.19 DMA Transfer Request Detection Operation Setting Table. */
typedef enum e_dmac_b_external_detection
{
    DMAC_B_EXTERNAL_DETECTION_NO_DETECTION = 0,   ///< Not using hardware detection.
} dmac_b_external_detection_t;

/*==============================================
 * Transfer API Overrides
 *==============================================*/

/** Transfer mode describes what will happen when a transfer request occurs. */
typedef enum e_transfer_mode
{
    /** Normal mode. */
    TRANSFER_MODE_NORMAL = 0,

    /** Block mode. */
    TRANSFER_MODE_BLOCK = 1
} transfer_mode_t;

/** Transfer size specifies the size of each individual transfer. */
typedef enum e_transfer_size
{
    TRANSFER_SIZE_1_BYTE   = 0,        ///< Each transfer transfers a 8-bit value
    TRANSFER_SIZE_2_BYTE   = 1,        ///< Each transfer transfers a 16-bit value
    TRANSFER_SIZE_4_BYTE   = 2,        ///< Each transfer transfers a 32-bit value
    TRANSFER_SIZE_8_BYTE   = 3,        ///< Each transfer transfers a 64-bit value
    TRANSFER_SIZE_16_BYTE  = 4,        ///< Each transfer transfers a 128-bit value
    TRANSFER_SIZE_32_BYTE  = 5,        ///< Each transfer transfers a 256-bit value
    TRANSFER_SIZE_64_BYTE  = 6,        ///< Each transfer transfers a 512-bit value
    TRANSFER_SIZE_128_BYTE = 7         ///< Each transfer transfers a 1024-bit value
} transfer_size_t;

/** Address mode specifies whether to modify (increment or decrement) pointer after each transfer. */
typedef enum e_transfer_addr_mode
{
    /** Address pointer is incremented by associated @ref transfer_size_t after each transfer. */
    TRANSFER_ADDR_MODE_INCREMENTED = 0,

    /** Address pointer remains fixed after each transfer. */
    TRANSFER_ADDR_MODE_FIXED = 1
} transfer_addr_mode_t;

typedef struct st_transfer_info
{
    /** Select what happens to destination address after each transfer. */
    transfer_addr_mode_t dest_addr_mode;

    /** Select what happens to source address after each transfer. */
    transfer_addr_mode_t src_addr_mode;

    /** Select mode from @ref transfer_mode_t. */
    transfer_mode_t mode;

    /** Source address. */
    void const * volatile p_src;

    /** Destination address. */
    void * volatile p_dest;

    /** The total number of transfer bytes. */
    volatile uint32_t length;

    /** Select source data size to transfer at once. */
    transfer_size_t src_size;

    /** Select destination data size to transfer at once. */
    transfer_size_t dest_size;

    /** Next1 Register set settings */
    void const * p_next1_src;
    void       * p_next1_dest;
    uint32_t     next1_length;
} transfer_info_t;

/*==============================================
 * ADC API Overrides
 *==============================================*/

/** ADC Information Structure for Transfer Interface */
typedef struct st_adc_info
{
    volatile const void * p_address;         ///< The address to start reading the data from
    uint32_t              length;            ///< The total number of transfers to read
    transfer_size_t       transfer_size;     ///< The size of each transfer
    uint32_t              calibration_data1; ///< Temperature sensor calibration data1
    uint32_t              calibration_data2; ///< Temperature sensor calibration data2
} adc_info_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
