/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_TRANSFER_ENDIAN_OVERRIDE_H
#define BSP_TRANSFER_ENDIAN_OVERRIDE_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Define overrides required for this MCU. */
#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_REPEAT_AREA_T
#define BSP_OVERRIDE_TRANSFER_CHAIN_MODE_T
#define BSP_OVERRIDE_TRANSFER_IRQ_T
#define BSP_OVERRIDE_TRANSFER_INFO_T

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Transfer mode describes what will happen when a transfer request occurs. */
typedef enum e_transfer_mode
{
    /** In normal mode, each transfer request causes a transfer of @ref transfer_size_t from the source pointer to
     *  the destination pointer.  The transfer length is decremented and the source and address pointers are
     *  updated according to @ref transfer_addr_mode_t.  After the transfer length reaches 0, transfer requests
     *  will not cause any further transfers. */
    TRANSFER_MODE_NORMAL = 0,

    /** Repeat mode is like normal mode, except that when the transfer length reaches 0, the pointer to the
     *  repeat area and the transfer length will be reset to their initial values.  If DMAC or EXDMAC is used, the
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
#if defined(__BIG) && defined(__GNUC__)

            /** Select mode from @ref transfer_mode_t. */
            transfer_mode_t mode : 2;

            /** Select number of bytes to transfer at once. @see transfer_info_t::length. */
            transfer_size_t size : 2;

            /** Select what happens to source pointer after each transfer. */
            transfer_addr_mode_t src_addr_mode : 2;

            uint32_t : 2;

            /** Select when the chain transfer ends. */
            transfer_chain_mode_t chain_mode : 2;

            /** Select if interrupts should occur after each individual transfer or after the completion of all planned
             *  transfers. */
            transfer_irq_t irq : 1;

            /** Select to repeat source or destination area, unused in @ref TRANSFER_MODE_NORMAL. */
            transfer_repeat_area_t repeat_area : 1;

            /** Select what happens to destination pointer after each transfer. */
            transfer_addr_mode_t dest_addr_mode : 2;

            uint32_t : 2;
            uint32_t : 16;
#else
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
#endif
        } transfer_settings_word_b;

        uint32_t transfer_settings_word;
    } transfer_settings_u;

    void const * volatile p_src;       ///< Source pointer
    void * volatile       p_dest;      ///< Destination pointer
#ifdef  __BIG

    /** Length of each transfer.  Range limited for @ref TRANSFER_MODE_BLOCK, @ref TRANSFER_MODE_REPEAT,
     *  and @ref TRANSFER_MODE_REPEAT_BLOCK
     *  see HAL driver for details. */
    volatile uint16_t length;

    /** Number of blocks to transfer when using @ref TRANSFER_MODE_BLOCK (DTC, DMAC or EXDMAC) or
     * @ref TRANSFER_MODE_REPEAT (DMAC and EXDMAC only) or
     * @ref TRANSFER_MODE_REPEAT_BLOCK (DMAC and EXDMAC only), unused in other modes. */
    volatile uint16_t num_blocks;
#else                                  // #ifdef __LIT (Little)

    /** Number of blocks to transfer when using @ref TRANSFER_MODE_BLOCK (DTC, DMAC or EXDMAC) or
     * @ref TRANSFER_MODE_REPEAT (DMAC and EXDMAC only) or
     * @ref TRANSFER_MODE_REPEAT_BLOCK (DMAC and EXDMAC only), unused in other modes. */
    volatile uint16_t num_blocks;

    /** Length of each transfer.  Range limited for @ref TRANSFER_MODE_BLOCK, @ref TRANSFER_MODE_REPEAT,
     *  and @ref TRANSFER_MODE_REPEAT_BLOCK
     *  see HAL driver for details. */
    volatile uint16_t length;
#endif
} transfer_info_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
