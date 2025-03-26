/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MPU_RZA3M
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MPU_RZA3M) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
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

#define bool      _Bool
#define true      1
#define false     0

/* Define overrides required for this MCU. */
#define BSP_OVERRIDE_BSP_PORT_T
#define BSP_OVERRIDE_BSP_PIN_T
#define BSP_OVERRIDE_BSP_SD_CH_T
#define BSP_OVERRIDE_IOPORT_PERIPHERAL_T

#define BSP_OVERRIDE_TRANSFER_INFO_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_REPEAT_AREA_T
#define BSP_OVERRIDE_TRANSFER_IRQ_T
#define BSP_OVERRIDE_TRANSFER_CHAIN_MODE_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T
#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_DISPLAY_IN_FORMAT_T
#define BSP_OVERRIDE_DISPLAY_INPUT_CFG_T
#define BSP_OVERRIDE_DISPLAY_DATA_SWAP_T

/* Override definitions. */
#define OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET    (24)

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

/** Superset list of all possible IO ports. */
typedef enum e_bsp_io_port
{
    BSP_IO_PORT_00 = 0x0F00,           /* IO port 0 */
    BSP_IO_PORT_01 = 0x1000,           /* IO port 1 */
    BSP_IO_PORT_02 = 0x1100,           /* IO port 2 */
    BSP_IO_PORT_03 = 0x1200,           /* IO port 3 */
    BSP_IO_PORT_04 = 0x1300,           /* IO port 4 */
    BSP_IO_PORT_05 = 0x1400,           /* IO port 5 */
    BSP_IO_PORT_06 = 0x1500,           /* IO port 6 */
    BSP_IO_PORT_07 = 0x1600,           /* IO port 7 */
    BSP_IO_PORT_08 = 0x1700,           /* IO port 8 */
    BSP_IO_PORT_09 = 0x1800,           /* IO port 9 */
    BSP_IO_PORT_10 = 0x1900,           /* IO port 10 */
    BSP_IO_PORT_11 = 0x1A00,           /* IO port 11 */
    BSP_IO_PORT_12 = 0x1B00,           /* IO port 12 */
    BSP_IO_PORT_20 = 0x0000,           /* IO port 20 */
    BSP_IO_PORT_21 = 0x0100,           /* IO port 21 */
    BSP_IO_PORT_22 = 0x0300,           /* IO port 22 */
    BSP_IO_PORT_23 = 0x0400,           /* IO port 23 */
} bsp_io_port_t;

/** Superset list of all possible IO port pins. */
typedef enum e_bsp_io_port_pin_t
{
    BSP_IO_PORT_00_PIN_00 = 0x0F00,     /* IO port 0 pin 0 */
    BSP_IO_PORT_00_PIN_01 = 0x0F01,     /* IO port 0 pin 1 */
    BSP_IO_PORT_00_PIN_02 = 0x0F02,     /* IO port 0 pin 2 */
    BSP_IO_PORT_00_PIN_03 = 0x0F03,     /* IO port 0 pin 3 */

    BSP_IO_PORT_01_PIN_00 = 0x1000,     /* IO port 1 pin 0 */
    BSP_IO_PORT_01_PIN_01 = 0x1001,     /* IO port 1 pin 1 */
    BSP_IO_PORT_01_PIN_02 = 0x1002,     /* IO port 1 pin 2 */
    BSP_IO_PORT_01_PIN_03 = 0x1003,     /* IO port 1 pin 3 */
    BSP_IO_PORT_01_PIN_04 = 0x1004,     /* IO port 1 pin 4 */

    BSP_IO_PORT_02_PIN_00 = 0x1100,     /* IO port 2 pin 0 */
    BSP_IO_PORT_02_PIN_01 = 0x1101,     /* IO port 2 pin 1 */
    BSP_IO_PORT_02_PIN_02 = 0x1102,     /* IO port 2 pin 2 */
    BSP_IO_PORT_02_PIN_03 = 0x1103,     /* IO port 2 pin 3 */

    BSP_IO_PORT_03_PIN_00 = 0x1200,     /* IO port 3 pin 0 */
    BSP_IO_PORT_03_PIN_01 = 0x1201,     /* IO port 3 pin 1 */
    BSP_IO_PORT_03_PIN_02 = 0x1202,     /* IO port 3 pin 2 */
    BSP_IO_PORT_03_PIN_03 = 0x1203,     /* IO port 3 pin 3 */

    BSP_IO_PORT_04_PIN_00 = 0x1300,     /* IO port 4 pin 0 */
    BSP_IO_PORT_04_PIN_01 = 0x1301,     /* IO port 4 pin 1 */
    BSP_IO_PORT_04_PIN_02 = 0x1302,     /* IO port 4 pin 2 */
    BSP_IO_PORT_04_PIN_03 = 0x1303,     /* IO port 4 pin 3 */
    BSP_IO_PORT_04_PIN_04 = 0x1304,     /* IO port 4 pin 4 */
    BSP_IO_PORT_04_PIN_05 = 0x1305,     /* IO port 4 pin 5 */

    BSP_IO_PORT_05_PIN_00 = 0x1400,     /* IO port 5 pin 0 */
    BSP_IO_PORT_05_PIN_01 = 0x1401,     /* IO port 5 pin 1 */
    BSP_IO_PORT_05_PIN_02 = 0x1402,     /* IO port 5 pin 2 */
    BSP_IO_PORT_05_PIN_03 = 0x1403,     /* IO port 5 pin 3 */
    BSP_IO_PORT_05_PIN_04 = 0x1404,     /* IO port 5 pin 4 */

    BSP_IO_PORT_06_PIN_00 = 0x1500,     /* IO port 6 pin 0 */
    BSP_IO_PORT_06_PIN_01 = 0x1501,     /* IO port 6 pin 1 */
    BSP_IO_PORT_06_PIN_02 = 0x1502,     /* IO port 6 pin 2 */
    BSP_IO_PORT_06_PIN_03 = 0x1503,     /* IO port 6 pin 3 */
    BSP_IO_PORT_06_PIN_04 = 0x1504,     /* IO port 6 pin 4 */

    BSP_IO_PORT_07_PIN_00 = 0x1600,     /* IO port 7 pin 0 */
    BSP_IO_PORT_07_PIN_01 = 0x1601,     /* IO port 7 pin 1 */

    BSP_IO_PORT_08_PIN_00 = 0x1700,     /* IO port 8 pin 0 */
    BSP_IO_PORT_08_PIN_01 = 0x1701,     /* IO port 8 pin 1 */
    BSP_IO_PORT_08_PIN_02 = 0x1702,     /* IO port 8 pin 2 */
    BSP_IO_PORT_08_PIN_03 = 0x1703,     /* IO port 8 pin 3 */

    BSP_IO_PORT_09_PIN_00 = 0x1800,     /* IO port 9 pin 0 */
    BSP_IO_PORT_09_PIN_01 = 0x1801,     /* IO port 9 pin 1 */
    BSP_IO_PORT_09_PIN_02 = 0x1802,     /* IO port 9 pin 2 */
    BSP_IO_PORT_09_PIN_03 = 0x1803,     /* IO port 9 pin 3 */
    BSP_IO_PORT_09_PIN_04 = 0x1804,     /* IO port 9 pin 4 */

    BSP_IO_PORT_10_PIN_00 = 0x1900,     /* IO port 10 pin 0 */
    BSP_IO_PORT_10_PIN_01 = 0x1901,     /* IO port 10 pin 1 */
    BSP_IO_PORT_10_PIN_02 = 0x1902,     /* IO port 10 pin 2 */
    BSP_IO_PORT_10_PIN_03 = 0x1903,     /* IO port 10 pin 3 */

    BSP_IO_PORT_11_PIN_00 = 0x1A00,     /* IO port 11 pin 0 */
    BSP_IO_PORT_11_PIN_01 = 0x1A01,     /* IO port 11 pin 1 */
    BSP_IO_PORT_11_PIN_02 = 0x1A02,     /* IO port 11 pin 2 */
    BSP_IO_PORT_11_PIN_03 = 0x1A03,     /* IO port 11 pin 3 */

    BSP_IO_PORT_12_PIN_00 = 0x1B00,     /* IO port 12 pin 0 */
    BSP_IO_PORT_12_PIN_01 = 0x1B01,     /* IO port 12 pin 1 */

    BSP_IO_PORT_20_PIN_00 = 0x0000,     /* IO port 20 pin 0 */
    BSP_IO_PORT_20_PIN_01 = 0x0001,     /* IO port 20 pin 1 */
    BSP_IO_PORT_20_PIN_02 = 0x0002,     /* IO port 20 pin 2 */
    BSP_IO_PORT_20_PIN_03 = 0x0003,     /* IO port 20 pin 3 */
    BSP_IO_PORT_20_PIN_04 = 0x0004,     /* IO port 20 pin 4 */
    BSP_IO_PORT_20_PIN_05 = 0x0005,     /* IO port 20 pin 5 */

    BSP_IO_PORT_21_PIN_00 = 0x0101,     /* IO port 21 pin 0 */
    BSP_IO_PORT_21_PIN_01 = 0x0102,     /* IO port 21 pin 1 */
    BSP_IO_PORT_21_PIN_02 = 0x0103,     /* IO port 21 pin 2 */

    BSP_IO_PORT_22_PIN_00 = 0x0301,     /* IO port 22 pin 0 */
    BSP_IO_PORT_22_PIN_01 = 0x0302,     /* IO port 22 pin 1 */
    BSP_IO_PORT_22_PIN_02 = 0x0303,     /* IO port 22 pin 2 */
    BSP_IO_PORT_22_PIN_03 = 0x0304,     /* IO port 22 pin 3 */
    BSP_IO_PORT_22_PIN_04 = 0x0305,     /* IO port 22 pin 4 */

    BSP_IO_PORT_23_PIN_00 = 0x0403,     /* IO port 23 pin 0 */
    BSP_IO_PORT_23_PIN_01 = 0x0404,     /* IO port 23 pin 1 */

    /* Special purpose port */
    BSP_IO_NMI = 0xFFFF0001,            /* NMI */

    BSP_IO_TMS_SWDIO = 0xFFFF0200,      /* TMS_SWDIO */

    BSP_IO_SD0_CLK = 0xFFFF0400,        /* SD0_CLK */

    BSP_IO_QSPI0_SPCLK = 0xFFFF0500,    /* QSPI0_SPCLK */
    BSP_IO_QSPI0_IO0   = 0xFFFF0501,    /* QSPI0_IO0 */
    BSP_IO_QSPI0_IO1   = 0xFFFF0502,    /* QSPI0_IO1 */
    BSP_IO_QSPI0_SSL   = 0xFFFF0505,    /* QSPI0_SSL */

    BSP_IO_WDTOVF_PERROUT = 0xFFFF0600, /* WDTOVF_PERROUT */

    BSP_IO_RIIC0_SDA = 0xFFFF0700,      /* RIIC0_SDA */
    BSP_IO_RIIC0_SCL = 0xFFFF0701,      /* RIIC0_SCL */
} bsp_io_port_pin_t;

/** Superset of SD channels. */
typedef enum e_bsp_sd_ch
{
    BSP_SD_CHANNEL_0 = 0x00,           ///< Used to select SD channel 0
} bsp_sd_channel_t;

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
    TRANSFER_SIZE_4_BYTE = 2           ///< Each transfer transfers a 32-bit value
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

/*==============================================
 * IOPORT Overrides
 *==============================================*/

/** Superset of all peripheral functions.  */
typedef enum e_ioport_peripheral
{
    /** Pin will function as a Mode1 peripheral pin */
    IOPORT_PERIPHERAL_MODE1 = (0x0UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode2 peripheral pin */
    IOPORT_PERIPHERAL_MODE2 = (0x1UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode3 peripheral pin */
    IOPORT_PERIPHERAL_MODE3 = (0x2UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode4 peripheral pin */
    IOPORT_PERIPHERAL_MODE4 = (0x3UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode5 peripheral pin */
    IOPORT_PERIPHERAL_MODE5 = (0x4UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode6 peripheral pin */
    IOPORT_PERIPHERAL_MODE6 = (0x5UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode7 peripheral pin */
    IOPORT_PERIPHERAL_MODE7 = (0x6UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Pin will function as a Mode8 peripheral pin */
    IOPORT_PERIPHERAL_MODE8 = (0x7UL << OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET),

    /** Marks end of enum - used by parameter checking */
    IOPORT_PERIPHERAL_END
} ioport_peripheral_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
