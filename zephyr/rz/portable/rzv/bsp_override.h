/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RZV2L
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RZV2L) */

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
#define BSP_OVERRIDE_CANFD_TX_BUFFER_T
#define BSP_OVERRIDE_CANFD_TX_MB_T
#define BSP_OVERRIDE_DMAC_B_EXTERNAL_DETECTION_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_CALLBACK_ARGS_T
#define BSP_OVERRIDE_TRANSFER_INFO_T
#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T

/* Override definitions. */
#define BSP_API_OVERRIDE    "bsp_api_override.h"

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/*==============================================
 * DMAC_B External Detection Overrides
 *==============================================*/

/** Detection method of the external DMA request signal. */
typedef enum e_dmac_b_external_detection
{
    DMAC_B_EXTERNAL_DETECTION_NO_DETECTION = 0, ///< Not using hardware detection.
} dmac_b_external_detection_t;

/*==============================================
 * CANFD Overrides
 *==============================================*/

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

/*==============================================
 * Transfer API Overrides
 *==============================================*/

/** Events that can trigger a callback function. */
typedef enum e_transfer_event
{
    TRANSFER_EVENT_TRANSFER_END   = 0, ///< Transfer has completed.
    TRANSFER_EVENT_TRANSFER_ERROR = 1, ///< Transfer error has occurred.
} transfer_event_t;

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

/** Callback function parameter data. */
typedef struct st_transfer_callback_args_t
{
    transfer_event_t event;            ///< Event code
    void const     * p_context;        ///< Placeholder for user data. Set in transfer_api_t::open function in ::transfer_cfg_t.
} transfer_callback_args_t;

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
 * Definition of macros to clear state flag of INTC IRQ
 **********************************************************************************************************************/
#define BSP_INTC_IRQ_CLR_STATE_FLAG(channel)                                    \
    do                                                                          \
    {                                                                           \
        /* Dummy read the ISCR before clearing the ISTAT bit. */                \
        volatile uint32_t iscr = BSP_FEATURE_INTC_BASE_ADDR->ISCR;              \
        FSP_PARAMETER_NOT_USED(iscr);                                           \
        /* Clear the ISTAT bit. */                                              \
        BSP_FEATURE_INTC_BASE_ADDR->ISCR = ~(INTC_IRQ_CLR_REG_MASK << channel); \
        /* Dummy read the ISCR to prevent the interrupt cause that have been cleared from being accidentally accepted. \
         * Reference section "Clear Timing of Interrupt Cause" of the user's manual. */ \
        iscr = BSP_FEATURE_INTC_BASE_ADDR->ISCR;                                        \
        FSP_PARAMETER_NOT_USED(iscr);                                                   \
    } while (0);

/***********************************************************************************************************************
 * Definition of macros to clear state flag of INTC NMI
 **********************************************************************************************************************/
#define BSP_INTC_NMI_CLR_STATE_FLAG()                              \
    do                                                             \
    {                                                              \
        /* Dummy read the NSCR before clearing the NSTAT bit. */   \
        volatile uint32_t nscr = BSP_FEATURE_INTC_BASE_ADDR->NSCR; \
        FSP_PARAMETER_NOT_USED(nscr);                              \
        /* Clear the NSTAT bit. */                                 \
        BSP_FEATURE_INTC_BASE_ADDR->NSCR_b.NSTAT = 0;              \
        /* Dummy read the NSCR to prevent the interrupt cause that have been cleared from being accidentally accepted. \
         * Reference section "Clear Timing of Interrupt Cause" of the user's manual. */ \
        nscr = BSP_FEATURE_INTC_BASE_ADDR->NSCR;                                        \
        FSP_PARAMETER_NOT_USED(nscr);                                                   \
    } while (0);

/***********************************************************************************************************************
 * Definition of macros to clear state flag of INTC TINT
 **********************************************************************************************************************/
#define BSP_INTC_TINT_CLR_STATE_FLAG(channel)                                    \
    do                                                                           \
    {                                                                            \
        /* Dummy read the TSCR before clearing the TSTAT bit. */                 \
        volatile uint32_t tscr = BSP_FEATURE_INTC_BASE_ADDR->TSCR;               \
        FSP_PARAMETER_NOT_USED(tscr);                                            \
        /* Clear the TSTAT bit. */                                               \
        BSP_FEATURE_INTC_BASE_ADDR->TSCR = ~(INTC_TINT_CLR_REG_MASK << channel); \
        /* Dummy read the TSCR to prevent the interrupt cause that should have been cleared from being accidentally \
         * accepted again. Reference section "Clear Timing of Interrupt Cause" of the user's manual. */ \
        tscr = BSP_FEATURE_INTC_BASE_ADDR->TSCR;                                                        \
        FSP_PARAMETER_NOT_USED(tscr);                                                                   \
    } while (0);

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
