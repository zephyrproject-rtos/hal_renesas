/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "../all/bsp_cmac.h"
#include "../all/bsp_clocks.h"
#include "bsp_tcs.h"

#if BSP_CFG_IPC_USED
 #include "shared_memory_ipc.h"
#endif
#if BSP_CFG_NMI_CONTEXT_USED
 #include "shared_memory_nmi_context.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define TCM_RAM_CELL_0_ADDR         0x33100000
#define TCM_SHARED_START_ADDR       0x33200000
#define CMAC_IVT_SIZE               0xC0
#define CMAC_NVM_BUILD_MASK         0x100000

#if defined(BSP_MCU_GROUP_RA6B1)           
 #define CRG_TOP_SYS_CTRL_REG_CMAC_DEBUGGER_ENABLE_Msk         (0x40UL)         
 #define CM_CTRL_SYS_REG                                       (*(volatile uint32_t *) 0x50001000UL) 
 #define CMAC_SYS_CM_CTRL_SYS_REG_CMAC_CONST_1_Msk             (0x80000000UL)                        
 #define CMAC_SYS_CM_CTRL_SYS_REG_CMAC_RST_BS_STATE_Msk        (0x10UL)                              
 #define CMAC_SYS_CM_CTRL_SYS_REG_CMAC_RST_MCPU_STATE_Msk      (0x20UL)                              
 #define CMAC_SYS_CM_CTRL_SYS_REG_CMAC_FW_ERROR_STATE_Msk      (0x80UL)                             
 #define CMAC_SYS_CM_CTRL_SYS_REG_CMAC_HWAC_ERROR_STATE_Msk    (0x100UL)                             
 #define CMAC_SYS_CM_CTRL_SYS_REG_CMAC_CPU_ERROR_STATE_Msk     (0x200UL)                            
#endif

#define CMAC_VALID_SYS_STAT_MASK    CMAC_SYS_CM_CTRL_SYS_REG_CMAC_CONST_1_Msk
#define CMAC_ACTIVE_MASK            (CMAC_SYS_CM_CTRL_SYS_REG_CMAC_RST_BS_STATE_Msk | \
                                     CMAC_SYS_CM_CTRL_SYS_REG_CMAC_RST_MCPU_STATE_Msk)

#define CMAC_ERROR_MASK             (CMAC_SYS_CM_CTRL_SYS_REG_CMAC_FW_ERROR_STATE_Msk |   \
                                     CMAC_SYS_CM_CTRL_SYS_REG_CMAC_HWAC_ERROR_STATE_Msk | \
                                     CMAC_SYS_CM_CTRL_SYS_REG_CMAC_CPU_ERROR_STATE_Msk)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Forward declaration for DMC Bluetooth configuration */
typedef struct dmc_config dmc_config_t;

typedef struct bsp_cmac_shared
{
    bsp_tcs_shared_t tcs_shared_conf;  ///< Shared TCS configuration properties
    uint32_t         cmac_clock_freq;  ///< Frequency of CMAC Clock
    uint32_t       * lp_clock_freq;    ///< Shared pointer to array of measured frequencies
    dmc_config_t   * dmc_config_ptr;   ///< Shared pointer to the DMC Bluetooth configuration
    uint32_t         rng_seed[4];      ///< Shared pointer to the 16-byte seed
#if BSP_CFG_IPC_USED
    uint8_t          * shared_data;    ///< Shared data buffer used by IPC. */
    shared_ram_ipc_t * shared_ram_ipc;
#endif
#if BSP_CFG_NMI_CONTEXT_USED
    shared_ram_nmi_context_t * shared_ram_nmi_context;
#endif
} bsp_cmac_shared_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static void bsp_prv_cmac_preinit(void);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
bsp_cmac_shared_t g_shared_data;

/**
 * @brief Pointer to the DMC Bluetooth configuration settings.
 *
 * When this pointer is NULL, DMC uses the default configuration.
 *
 * @note This symbol may be overridden by providing a strong definition in
 *       another translation unit. In such a case:
 *       - The pointer **must point to a RAM location**.
 *       - The configuration object it points to **must match exactly** the
 *         `dmc_config_t` definition used by the M0p core.
 *
 * Example:
 *
 * @code
 * typedef struct
 * {
 *     ...
 * } dmc_config_t;
 *
 * static dmc_config_t dmc_config =
 * {
 *     ...
 * };
 *
 * dmc_config_t *g_p_bsp_cmac_dmc_config = &dmc_config;
 * @endcode
 */
BSP_WEAK_REFERENCE dmc_config_t * g_p_bsp_cmac_dmc_config = NULL;

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

static void bsp_prv_cmac_preinit (void)
{
    /* Enable all the XTAL32M buffers needed by CMAC: RF-ADC & ADPLL. */
    XTAL32M->XTAL32M_SET_ENABLE_REG = (0x6 << XTAL32M_XTAL32M_SET_ENABLE_REG_EN_XTAL_CLK_BUFFER_Pos);

    /* Set CMAC clock source according to the configuration. */
    CRG_TOP->CLK_RADIO_REG_b.RAD_CLK_SEL = BSP_CFG_CMACCLK_SOURCE;

#if (BSP_CFG_CMACCLK_MAX_SPEED_HZ == 32000000)
    CRG_TOP->CLK_RADIO_REG_b.CMAC_CLK_SPEED = 0; /* max 32MHz */
#elif (BSP_CFG_CMACCLK_MAX_SPEED_HZ == 64000000)
    CRG_TOP->CLK_RADIO_REG_b.CMAC_CLK_SPEED = 1; /* max 64MHz */
#elif (BSP_CFG_CMACCLK_MAX_SPEED_HZ == 128000000)
    CRG_TOP->CLK_RADIO_REG_b.CMAC_CLK_SPEED = 2; /* max 128MHz */
#endif

    /* Set clock relationship according to the configuration. */
#if BSP_CFG_SYS_CLK_RUNTIME_SWITCHING_SUPPORT
 #if ((BSP_CFG_CMACCLK_SOURCE == BSP_CMAC_RAD_CLK_XTAL64M) || \
    (BSP_CFG_CMACCLK_SOURCE == BSP_CMAC_RAD_CLK_XTAL32M))
    CRG_TOP->CLK_RADIO_REG_b.RAD_CLK_RELATIONSHIP = 1; /* asynchronous */
 #elif (BSP_CFG_CMACCLK_SOURCE == BSP_CMAC_RAD_CLK_SYS)
    CRG_TOP->CLK_RADIO_REG_b.RAD_CLK_RELATIONSHIP = 2; /* synchronous and not equal */
 #endif
#else
 #if ((BSP_CFG_CMACCLK_SOURCE == BSP_CMAC_RAD_CLK_XTAL32M) &&        \
    (BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_XTALM)) ||      \
    ((BSP_CFG_CMACCLK_SOURCE == BSP_CMAC_RAD_CLK_XTAL64M) &&         \
    (BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_XTALM_DBLR)) || \
    ((BSP_CFG_CMACCLK_SOURCE == BSP_CMAC_RAD_CLK_SYS) &&             \
    (((BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_PLL) &&       \
    (BSP_CFG_CMACCLK_MAX_SPEED_HZ == 128000000)) ||                  \
    ((BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_XTALM_DBLR) && \
    (BSP_CFG_CMACCLK_MAX_SPEED_HZ >= 64000000)) ||                   \
    (BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_XTALM)))
    CRG_TOP->CLK_RADIO_REG_b.RAD_CLK_RELATIONSHIP = 0; /* synchronous and equal (hclk & cmac_clk) */
 #elif ((BSP_CFG_CMACCLK_SOURCE == BSP_CMAC_RAD_CLK_SYS) &&          \
    (((BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_PLL) &&       \
    (BSP_CFG_CMACCLK_MAX_SPEED_HZ <= 64000000)) ||                   \
    ((BSP_CFG_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_XTALM_DBLR) && \
    (BSP_CFG_CMACCLK_MAX_SPEED_HZ == 32000000))))
    CRG_TOP->CLK_RADIO_REG_b.RAD_CLK_RELATIONSHIP = 2; /* synchronous and not equal */
 #else
    CRG_TOP->CLK_RADIO_REG_b.RAD_CLK_RELATIONSHIP = 1; /* asynchronous */
 #endif
#endif

    CRG_TOP->CLK_RADIO_REG_b.CMAC_SYNCH_RESET =
        (CRG_TOP_CLK_RADIO_REG_CMAC_SYNCH_RESET_Msk >> CRG_TOP_CLK_RADIO_REG_CMAC_SYNCH_RESET_Pos);

    BSP_CHECK_FATAL(bsp_pd_is_up_check(BSP_PD_RAD));

    /* Retain the cmac cache block configuration when the associated domain is off. */
    /* HW limitation: cmac cache retention bit must be enabled only when the corresponding domain is on. */
    CRG_TOP->PMU_CTRL_REG_b.RETAIN_CMAC_CACHE = 1;

    /* Enable CMAC debugger (optional) */
    CRG_TOP->SYS_CTRL_REG |= CRG_TOP_SYS_CTRL_REG_CMAC_DEBUGGER_ENABLE_Msk;
}

void bsp_cmac_start (void)
{
    static bool g_cmac_started = false;

    FSP_CRITICAL_SECTION_DEFINE;

    FSP_CRITICAL_SECTION_ENTER;
    if (g_cmac_started)
    {
        FSP_CRITICAL_SECTION_EXIT;

        return;
    }

    g_cmac_started = true;

    FSP_CRITICAL_SECTION_EXIT;

    extern uint32_t _binary_cmac_bin_start;

    g_shared_data.tcs_shared_conf.tcs_data_ptr        = bsp_tcs_get_tcs_data_ptr();
    g_shared_data.tcs_shared_conf.tcs_attributes_ptr  = bsp_tcs_get_tcs_attributes_ptr();
    g_shared_data.tcs_shared_conf.tcs_data_size       = ((CS_MAX_SIZE + CS_CUSTOMER_MAX_SIZE) / 4 + 1);
    g_shared_data.tcs_shared_conf.tcs_attributes_size = BSP_TCS_GID_COUNT;
    g_shared_data.cmac_clock_freq = BSP_CFG_CMACCLK_HZ;
    g_shared_data.lp_clock_freq   = &g_clock_freq[BSP_CLOCKS_SOURCE_CLOCK_RCLP];

    /* DMC Bluetooth configuration */
    g_shared_data.dmc_config_ptr = g_p_bsp_cmac_dmc_config;

    /* 16-byte seed */
    uint32_t * entropy_and_nonce;
    entropy_and_nonce         = (uint32_t *) bsp_entropy_get_seed();
    g_shared_data.rng_seed[0] = entropy_and_nonce[0];
    g_shared_data.rng_seed[1] = entropy_and_nonce[1];
    g_shared_data.rng_seed[2] = entropy_and_nonce[2];
    g_shared_data.rng_seed[3] = entropy_and_nonce[3];

#if BSP_CFG_IPC_USED
    g_shared_data.shared_data    = shared_data_ptr;
    g_shared_data.shared_ram_ipc = shared_ram_ipc_ptr;
#endif
#if BSP_CFG_NMI_CONTEXT_USED
    g_shared_data.shared_ram_nmi_context = gp_shared_ram_nmi_context_ptr;
#endif

    struct cmac_fw
    {
        uint32_t ivt[CMAC_IVT_SIZE / sizeof(uint32_t)];
        uint32_t shared_data_ptr;
    };

    struct cmac_fw * cmac_fw_start = (struct cmac_fw *) &_binary_cmac_bin_start;

    /* Initialize and keep CMAC under reset */
    bsp_prv_cmac_preinit();

    /* CMAC is kept under reset, configure memory controller */

    /* No need to program CMI_CODE_BASE_REG is fixed */

    /* No need to program CMI_DATA_BASE_REG will be programmed by CMAC */
    /* No need to program CMI_SHARED_BASE_REG for now is fixed to zero */
    MEMCTRL_CMAC->CMI_SHARED_BASE_REG = 0;

#if defined(__GNUC__) && (__GNUC__ > 10)

    // Clear any previous state just in case
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Warray-bounds"
#endif

    /*
     * The second address of CMAC binary is the Reset_Handler.
     * Check Reset_Handler's address to identify SRAM or NVM builds.
     */
    if (cmac_fw_start->ivt[1] & CMAC_NVM_BUILD_MASK)
    {
        /* Copy M0+ IVT from NVRAM to CMAC RAM */

        // TODO find a way to avoid volatile here
        volatile size_t cmac_ivt_size = CMAC_IVT_SIZE;
        memcpy((uint8_t *) TCM_RAM_CELL_0_ADDR, (uint8_t *) cmac_fw_start, cmac_ivt_size);

        MEMCTRL_CMAC->CMI_CODE2_BASE_REG = (uint32_t) cmac_fw_start;
    }
    else
    {
        /* Copy the whole M0+ binary from NVRAM to CMAC RAM */
        extern uint32_t _binary_cmac_bin_end;
        uint32_t      * cmac_fw_end = (uint32_t *) &_binary_cmac_bin_end;
        memcpy((uint8_t *) TCM_RAM_CELL_0_ADDR, (uint8_t *) cmac_fw_start,
               (size_t) ((uint32_t) cmac_fw_end - (uint32_t) cmac_fw_start));
    }

    /* after IVT there is a preallocated 4bytes space to store the shared tcs pointer*/
    struct cmac_fw * cmac_rw_fw = (struct cmac_fw *) TCM_RAM_CELL_0_ADDR;
    cmac_rw_fw->shared_data_ptr = (uint32_t) &g_shared_data;

#if defined(__GNUC__) && (__GNUC__ > 10)
 #pragma GCC diagnostic pop
#endif

    /* Start CMAC. Release CMAC Synchronous Reset */
    CRG_TOP->CLK_RADIO_REG_b.CMAC_SYNCH_RESET = 0;
}

void bsp_cmac_stop (void)
{
    /* Disable CMAC */
    CRG_TOP->CLK_RADIO_REG_b.CMAC_SYNCH_RESET = 1;
    bsp_pd_disable(BSP_PD_RAD);
}

bool bsp_cmac_is_active (void)
{
#if defined(BSP_MCU_GROUP_RA6B1)
    uint32_t val = CM_CTRL_SYS_REG;
#else
    uint32_t val = CMAC_SYS->CM_CTRL_SYS_REG;
#endif
    uint32_t msk = CMAC_VALID_SYS_STAT_MASK | CMAC_ACTIVE_MASK;

    /* CMAC firmware resets Bitstream state (BS_STATE) so its expected value is 0 */
    if ((val & msk) == CMAC_VALID_SYS_STAT_MASK)
    {
        return true;
    }

    return false;
}

void bsp_cmac_cmac2sys_enable (cmac_irq_ctx_t * const ctx)
{
    R_BSP_IrqCfgEnable(ctx->irq, ctx->ipl, ctx);
}

void bsp_cmac_cmac2sys_disable (cmac_irq_ctx_t * const ctx)
{
    R_BSP_IrqDisable(ctx->irq);
    R_FSP_IsrContextSet(ctx->irq, NULL);
}

BSP_WEAK_REFERENCE void bsp_cmac_error (uint32_t status)
{
    FSP_PARAMETER_NOT_USED(status);

    BSP_CHECK_FATAL(0);
}

void cmac2sys_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Ack CMAC interrupt. */
    MEMCTRL->RESET_SYS_IRQ_CTRL_REG = MEMCTRL_RESET_SYS_IRQ_CTRL_REG_CMAC2SYS_IRQ_BIT_Msk;

#if BSP_FEATURE_BSP_HAS_ICU
    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Clear IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);
#endif

    /* Handle interrupt for a channel associated with received IRQn */
    cmac_irq_ctx_t * ctx = R_FSP_IsrContextGet(irq);

    /* Check for potential CMACCPU errors. */
#if defined(BSP_MCU_GROUP_RA6B1)
    uint32_t cmac_error_status = CM_CTRL_SYS_REG;
#else
    uint32_t cmac_error_status = CMAC_SYS->CM_CTRL_SYS_REG;
#endif

    if (cmac_error_status & CMAC_ERROR_MASK)
    {
        bsp_cmac_error(cmac_error_status);
    }

    /* Call user callback */
    if (ctx->callback)
    {
        cmac_callback_args_t args;
        args.err_code = (cmac_error_status & CMAC_ERROR_MASK);
        ctx->callback(&args);
    }

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;
}

/** @} (end addtogroup BSP_MCU_PRV) */
