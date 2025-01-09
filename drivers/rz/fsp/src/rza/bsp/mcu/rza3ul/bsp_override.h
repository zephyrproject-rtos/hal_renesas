/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MPU_RZA3UL
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MPU_RZA3UL) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <stdbool.h>
#include "bsp_feature.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifndef __IM                           /*!< Fallback for older CMSIS versions                                     */
 #define __IM     volatile const
#endif

#ifndef __IOM                          /*!< Fallback for older CMSIS versions                                     */
 #define __IOM    volatile
#endif

/* Define overrides required for this MCU. */
#define BSP_OVERRIDE_TRANSFER_INFO_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_REPEAT_AREA_T
#define BSP_OVERRIDE_TRANSFER_IRQ_T
#define BSP_OVERRIDE_TRANSFER_CHAIN_MODE_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T
#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_ETHER_PHY_LSI_TYPE_T
#define BSP_OVERRIDE_DISPLAY_IN_FORMAT_T
#define BSP_OVERRIDE_DISPLAY_INPUT_CFG_T
#define BSP_OVERRIDE_DISPLAY_DATA_SWAP_T
#define BSP_OVERRIDE_CANFD_TX_MB_T

/* Define register overrides required for this MCU. */

/* Override definitions. */

#define BSP_OVERRIDE_ADC_INCLUDE
#define BSP_OVERRIDE_ADC_INFO_T

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef struct mmu_pagetable_config
{
    uint64_t vaddress;
    uint64_t paddress;
    uint64_t size;
    uint64_t attribute;
} r_mmu_pgtbl_cfg_t;

/** Phy LSI */
typedef enum e_ether_phy_lsi_type
{
    ETHER_PHY_LSI_TYPE_DEFAULT     = 0,     ///< Select default configuration. This type dose not change Phy LSI default setting by strapping option.
    ETHER_PHY_LSI_TYPE_KSZ8091RNB  = 1,     ///< Select configuration for KSZ8091RNB.
    ETHER_PHY_LSI_TYPE_KSZ8041     = 2,     ///< Select configuration for KSZ8041.
    ETHER_PHY_LSI_TYPE_DP83620     = 3,     ///< Select configuration for DP83620.
    ETHER_PHY_LSI_TYPE_ICS1894     = 4,     ///< Select configuration for ICS1894.
    ETHER_PHY_LSI_TYPE_KSZ9131RNXI = 5,     ///< Select configuration for KSZ9131RNXI.
    ETHER_PHY_LSI_TYPE_CUSTOM      = 0xFFU, ///< Select configuration for User custom.
} ether_phy_lsi_type_t;

/** Address mode specifies whether to modify (increment or decrement) pointer after each transfer. */
typedef enum e_transfer_addr_mode
{
    /** Address pointer remains fixed after each transfer. */
    TRANSFER_ADDR_MODE_FIXED = 0,

    /** Offset is added to the address pointer after each transfer. */
    TRANSFER_ADDR_MODE_OFFSET = 1,

    /** Address pointer is incremented by associated @ref transfer_size_t after each transfer. */
    TRANSFER_ADDR_MODE_INCREMENTED = 2,

    /** Address pointer is decremented by associated @ref transfer_size_t after each transfer. */
    TRANSFER_ADDR_MODE_DECREMENTED = 3
} transfer_addr_mode_t;

/** Repeat area options (source or destination).  In @ref TRANSFER_MODE_REPEAT, the selected pointer returns to its
 *  original value after transfer_info_t::length transfers.  In @ref TRANSFER_MODE_BLOCK and @ref TRANSFER_MODE_REPEAT_BLOCK,
 *  the selected pointer returns to its original value after each transfer. */
typedef enum e_transfer_repeat_area
{
    /** Destination area repeated in @ref TRANSFER_MODE_REPEAT or @ref TRANSFER_MODE_BLOCK or @ref TRANSFER_MODE_REPEAT_BLOCK. */
    TRANSFER_REPEAT_AREA_DESTINATION = 0,

    /** Source area repeated in @ref TRANSFER_MODE_REPEAT or @ref TRANSFER_MODE_BLOCK or @ref TRANSFER_MODE_REPEAT_BLOCK. */
    TRANSFER_REPEAT_AREA_SOURCE = 1
} transfer_repeat_area_t;

/** Interrupt options. */
typedef enum e_transfer_irq
{
    /** Interrupt occurs only after last transfer. If this transfer is chained to a subsequent transfer,
     *  the interrupt will occur only after subsequent chained transfer(s) are complete.
     *  @warning  DTC triggers the interrupt of the activation source.  Choosing TRANSFER_IRQ_END with DTC will
     *            prevent activation source interrupts until the transfer is complete. */
    TRANSFER_IRQ_END = 0,

    /** Interrupt occurs after each transfer.
     *  @note     Not available in all HAL drivers.  See HAL driver for details. */
    TRANSFER_IRQ_EACH = 1
} transfer_irq_t;

/** Chain transfer mode options.
 *  @note Only applies for DTC. */
typedef enum e_transfer_chain_mode
{
    /** Chain mode not used. */
    TRANSFER_CHAIN_MODE_DISABLED = 0,

    /** Switch to next transfer after a single transfer from this @ref transfer_info_t. */
    TRANSFER_CHAIN_MODE_EACH = 2,

    /** Complete the entire transfer defined in this @ref transfer_info_t before chaining to next transfer. */
    TRANSFER_CHAIN_MODE_END = 3
} transfer_chain_mode_t;

/** Transfer mode describes what will happen when a transfer request occurs. */
typedef enum e_transfer_mode
{
    /** In normal mode, each transfer request causes a transfer of @ref transfer_size_t from the source pointer to
     *  the destination pointer.  The transfer length is decremented and the source and address pointers are
     *  updated according to @ref transfer_addr_mode_t.  After the transfer length reaches 0, transfer requests
     *  will not cause any further transfers. */
    TRANSFER_MODE_NORMAL = 0,

    /** Repeat mode is like normal mode, except that when the transfer length reaches 0, the pointer to the
     *  repeat area and the transfer length will be reset to their initial values.  If DMAC is used, the
     *  transfer repeats only transfer_info_t::num_blocks times.  After the transfer repeats
     *  transfer_info_t::num_blocks times, transfer requests will not cause any further transfers.  If DTC is
     *  used, the transfer repeats continuously (no limit to the number of repeat transfers). */
    TRANSFER_MODE_REPEAT = 1,

    /** In block mode, each transfer request causes transfer_info_t::length transfers of @ref transfer_size_t.
     *  After each individual transfer, the source and destination pointers are updated according to
     *  @ref transfer_addr_mode_t.  After the block transfer is complete, transfer_info_t::num_blocks is
     *  decremented.  After the transfer_info_t::num_blocks reaches 0, transfer requests will not cause any
     *  further transfers. */
    TRANSFER_MODE_BLOCK = 2,

    /** In addition to block mode features, repeat-block mode supports a ring buffer of blocks and offsets
     *  within a block (to split blocks into arrays of their first data, second data, etc.) */
    TRANSFER_MODE_REPEAT_BLOCK = 3
} transfer_mode_t;

/** Transfer size specifies the size of each individual transfer.
 *  Total transfer length = transfer_size_t * transfer_length_t
 */
typedef enum e_transfer_size
{
    TRANSFER_SIZE_1_BYTE = 0,          ///< Each transfer transfers a 8-bit value
    TRANSFER_SIZE_2_BYTE = 1,          ///< Each transfer transfers a 16-bit value
    TRANSFER_SIZE_4_BYTE = 2,          ///< Each transfer transfers a 32-bit value
    TRANSFER_SIZE_8_BYTE = 3           ///< Each transfer transfers a 64-bit value
} transfer_size_t;

/** This structure specifies the properties of the transfer.
 *  @warning  When using DTC, this structure corresponds to the descriptor block registers required by the DTC.
 *            The following components may be modified by the driver: p_src, p_dest, num_blocks, and length.
 *  @warning  When using DTC, do NOT reuse this structure to configure multiple transfers.  Each transfer must
 *            have a unique transfer_info_t.
 *  @warning  When using DTC, this structure must not be allocated in a temporary location.  Any instance of this
 *            structure must remain in scope until the transfer it is used for is closed.
 *  @note     When using DTC, consider placing instances of this structure in a protected section of memory. */
typedef struct st_transfer_info
{
    union
    {
        struct
        {
            uint32_t : 16;
            uint32_t : 2;

            /** Select what happens to destination pointer after each transfer. */
            transfer_addr_mode_t dest_addr_mode : 2;

            /** Select to repeat source or destination area, unused in @ref TRANSFER_MODE_NORMAL. */
            transfer_repeat_area_t repeat_area : 1;

            /** Select if interrupts should occur after each individual transfer or after the completion of all planned
             *  transfers. */
            transfer_irq_t irq : 1;

            /** Select when the chain transfer ends. */
            transfer_chain_mode_t chain_mode : 2;

            uint32_t : 2;

            /** Select what happens to source pointer after each transfer. */
            transfer_addr_mode_t src_addr_mode : 2;

            /** Select number of bytes to transfer at once. @see transfer_info_t::length. */
            transfer_size_t size : 2;

            /** Select mode from @ref transfer_mode_t. */
            transfer_mode_t mode : 2;
        }        transfer_settings_word_b;
        uint32_t transfer_settings_word;
    };

    void const * volatile p_src;       ///< Source pointer
    void * volatile       p_dest;      ///< Destination pointer

    /** Number of blocks to transfer when using @ref TRANSFER_MODE_BLOCK (both DTC an DMAC) and
     * @ref TRANSFER_MODE_REPEAT (DMAC only), unused in other modes. */
    volatile uint16_t num_blocks;

    /** Length of each transfer.  Range limited for @ref TRANSFER_MODE_BLOCK and @ref TRANSFER_MODE_REPEAT,
     *  see HAL driver for details. */
    volatile uint16_t length;

    void const * p_extend_info;        ///< Extension parameter for hardware specific settings.
} transfer_info_t;

/** ADC Information Structure for Transfer Interface */
typedef struct st_adc_info
{
    __IM void * p_address;                                                  ///< The address to start reading the data from
    uint32_t    length;                                                     ///< The total number of transfers to read

    transfer_size_t transfer_size;                                          ///< The size of each transfer
    uint32_t        calibration_data[BSP_FEATURE_ADC_NUM_CALIBRATION_DATA]; ///< Temperature sensor calibration data (0xFFFFFFFF if unsupported) for reference voltage
    int16_t         slope_microvolts;                                       ///< Temperature sensor slope in microvolts/degrees C
    bool            calibration_ongoing;                                    ///< Calibration is in progress.
} adc_info_t;

typedef enum e_display_in_format
{
    DISPLAY_IN_FORMAT_32BITS_ARGB8888 = 0,                         ///< ARGB8888, 32 bits
    DISPLAY_IN_FORMAT_32BITS_RGB888   = 1,                         ///< RGB888,   32 bits
    DISPLAY_IN_FORMAT_16BITS_RGB565   = 2,                         ///< RGB565,   16 bits
    DISPLAY_IN_FORMAT_16BITS_ARGB1555 = 3,                         ///< ARGB1555, 16 bits
    DISPLAY_IN_FORMAT_16BITS_ARGB4444 = 4,                         ///< ARGB4444, 16 bits

    DISPLAY_IN_FORMAT_CLUT8 = 5,                                   ///< CLUT8
    DISPLAY_IN_FORMAT_CLUT4 = 6,                                   ///< CLUT4
    DISPLAY_IN_FORMAT_CLUT1 = 7,                                   ///< CLUT1

    DISPLAY_IN_FORMAT_32BITS_RGBA8888                        = 8,  ///< RGBA8888,                        32 bits
    DISPLAY_IN_FORMAT_24BITS_BGR888                          = 9,  ///< BGR888,                          24 bits
    DISPLAY_IN_FORMAT_24BITS_RGB888                          = 10, ///< RGB888,                          24 bits
    DISPLAY_IN_FORMAT_32BITS_ABGR8888                        = 11, ///< ABGR8888,                        32 bits
    DISPLAY_IN_FORMAT_24BITS_YCBCR444_INTERLEAVED            = 12, ///< YCbCr444 interleaved,             24 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR422_INTERLEAVED_TYPE0_UYVY = 13, ///< YCbCr422 interleaved type0 UYVY,  16 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR422_INTERLEAVED_TYPE0_YUY2 = 14, ///< YCbCr422 interleaved type0 YUY2,  16 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR422_INTERLEAVED_TYPE0_YVYU = 15, ///< YCbCr422 interleaved type0 YVYU,  16 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR422_INTERLEAVED_TYPE1      = 16, ///< YCbCr420 interleaved type1,       16 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR420_INTERLEAVED            = 17, ///< YCbCr420 interleaved,             12 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR420_PLANAR                 = 18, ///< YCbCr420 planar,                  16bits

    /** All other options start at this value. */
    DISPLAY_IN_FORMAT_CUSTOM = 0x80,
} display_in_format_t;

typedef enum e_display_data_swap
{
    DISPLAY_DATA_SWAP_8BIT  = 1,
    DISPLAY_DATA_SWAP_16BIT = 2,
    DISPLAY_DATA_SWAP_32BIT = 4,
    DISPLAY_DATA_SWAP_64BIT = 8,
} display_data_swap_t;

/** Graphics plane input configuration structure */
typedef struct st_display_input_cfg
{
    uint32_t          * p_base;        ///< Base address to the frame buffer
    uint32_t          * p_base_cb;     ///< Base address to the frame buffer for Cb plane
    uint32_t          * p_base_cr;     ///< Base address to the frame buffer for Cr plane
    uint16_t            hsize;         ///< Horizontal pixels in a line
    uint16_t            vsize;         ///< Vertical pixels in a frame
    uint16_t            coordinate_x;  ///< Coordinate X
    uint16_t            coordinate_y;  ///< Coordinate Y
    uint16_t            hstride;       ///< Memory stride (bytes) in a line
    uint16_t            hstride_cbcr;  ///< Memory stride (bytes) in a line for Cb and Cr plane
    display_in_format_t format;        ///< Input format setting
    display_data_swap_t data_swap;     ///< Input data swap_Setting
} display_input_cfg_t;

/** CANFD Transmit Message Buffer (TX MB) */
typedef enum e_canfd_tx_mb
{
    CANFD_TX_MB_0 = 0,
    CANFD_TX_MB_1 = 1,
    CANFD_TX_MB_2 = 2,
    CANFD_TX_MB_3 = 3,
#if !BSP_FEATURE_CANFD_LITE
    CANFD_TX_MB_4  = 4,
    CANFD_TX_MB_5  = 5,
    CANFD_TX_MB_6  = 6,
    CANFD_TX_MB_7  = 7,
    CANFD_TX_MB_8  = 8,
    CANFD_TX_MB_9  = 9,
    CANFD_TX_MB_10 = 10,
    CANFD_TX_MB_11 = 11,
    CANFD_TX_MB_12 = 12,
    CANFD_TX_MB_13 = 13,
    CANFD_TX_MB_14 = 14,
    CANFD_TX_MB_15 = 15,
#endif
} canfd_tx_mb_t;

/** CANFD Transmit Buffer (MB + CFIFO) */
typedef enum e_canfd_tx_buffer
{
    CANFD_TX_BUFFER_0 = 0,
    CANFD_TX_BUFFER_1 = 1,
    CANFD_TX_BUFFER_2 = 2,
    CANFD_TX_BUFFER_3 = 3,
#if !BSP_FEATURE_CANFD_LITE
    CANFD_TX_BUFFER_4  = 4,
    CANFD_TX_BUFFER_5  = 5,
    CANFD_TX_BUFFER_6  = 6,
    CANFD_TX_BUFFER_7  = 7,
    CANFD_TX_BUFFER_8  = 8,
    CANFD_TX_BUFFER_9  = 9,
    CANFD_TX_BUFFER_10 = 10,
    CANFD_TX_BUFFER_11 = 11,
    CANFD_TX_BUFFER_12 = 12,
    CANFD_TX_BUFFER_13 = 13,
    CANFD_TX_BUFFER_14 = 14,
    CANFD_TX_BUFFER_15 = 15,
#endif
    CANFD_TX_BUFFER_FIFO_COMMON_0 = 16,
#if !BSP_FEATURE_CANFD_LITE
    CANFD_TX_BUFFER_FIFO_COMMON_1 = 17,
    CANFD_TX_BUFFER_FIFO_COMMON_2 = 18,
#endif
} canfd_tx_buffer_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
