/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_lcdc.h"
#include "bsp_api.h"
#include "r_lcdc_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define LCDC_DU_PBCR0                         (0x0000001F)
#define LCDC_VSPD_CLK_CTRL0                   (0x00000000)
#define LCDC_VSPD_CLK_CTRL1                   (0x00000000)
#define LCDC_VSPD_CLK_DCSWT                   (0x00000808)
#define LCDC_VSPD_CLK_DCSM0                   (0x00000000)
#define LCDC_VSPD_CLK_DCSM1                   (0x00000000)
#define LCDC_VSPD_DL_CTRL                     (0x0100)
#define LCDC_VSPD_LIF_CTRL_OBTH               (0x5DC)
#define LCDC_VSPD_LIF_CTRL_LBA1               (0x600)
#define LCDC_VSPD_DL_BODY_SIZE                (200)
#define LCDC_VSPD_DPR_RPF0_ROUTE_RT_RPF0      (0x26)
#define LCDC_VSPD_DPR_RPF0_ROUTE_RT_RPF1      (0x27)
#define LCDC_VSPD_DPR_WPF0_FPROCH             (0x05)
#define LCDC_VSPD_DPR_LUT_ROUTE               (0x3F)
#define LCDC_VSPD_DPR_ILV_BRS_ROUTE_BRSSEL    (1)
#define LCDC_VSPD_DPR_ILV_BRS_ROUTE_RT        (0x38)
#define LCDC_VSPD_BRSA_CTRL_RBC               (1)
#define LCDC_VSPD_BRSA_CTRL_DSTSEL            (1)
#define LCDC_VSPD_BRSB_CTRL_SRCSEL            (4)
#define LCDC_VSPD_BRSA_BLD_CCMDX              (0)
#define LCDC_VSPD_BRSA_BLD_CCMDY              (1)
#define LCDC_VSPD_BRSB_BLD_CCMDX              (1)
#define LCDC_VSPD_BRSB_BLD_CCMDY              (3)

#define LAYER_STATUS_INIT                     (0x02000000)
#define LAYER_ENABLE_1                        (0x02000001)
#define LAYER_ENABLE_2                        (0x02000004)
#define LAYER_ENABLE_ALL                      (0x02000005)
#define LAYER_DISABLE_1                       (0x02000004)
#define LAYER_DISABLE_2                       (0x02000001)
#define LAYER_DISABLE_ALL                     (0x02000000)
#define COLOR_FOTMAT_CONVERT                  (0x00000100)

#define TIMING_MAX_H                          (1920)
#define TIMING_MAX_V                          (1280)
#define LAYER_MAX_HSIZE                       (1280)
#define LAYER_MAX_VSIZE                       (1280)
#define LAYER_MAX_HCOOR                       (1280)
#define LAYER_MAX_VCOOR                       (1280)

#define CAST_TO_UINT32                        (0xFFFFFFFFU)
#define DL_NUM_CMD                            (25)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef struct
{
    uint32_t set_address;
    uint32_t set_data;
} set_address_data_t;

typedef struct
{
    set_address_data_t cmd[DL_NUM_CMD];
} display_list_data_type;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_lcdc_du_set(display_cfg_t const * const p_cfg);
static void r_lcdc_clock_set(void);
static void r_lcdc_dl_set(void);
static void r_lcdc_dl_address_set(display_cfg_t const * const p_cfg);
static void r_lcdc_layer1_set(display_cfg_t const * const p_cfg);
static void r_lcdc_layer2_set(display_cfg_t const * const p_cfg);
static void r_lcdc_output_set(display_cfg_t const * const p_cfg);
static void r_lcdc_dpr_set(void);
static void r_lcdc_brs_set(void);
static void r_lcdc_layer_change(display_runtime_cfg_t const * const p_cfg, display_frame_layer_t layer);
static void r_lcdc_ckey_set(display_colorkeying_layer_t ck_cfg, display_frame_layer_t layer);
static void r_lcdc_interrupt_enable(display_cfg_t const * const p_cfg, lcdc_instance_ctrl_t * const p_instance_ctrl);
void        lcdc_vspd_int(IRQn_Type const irq);

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
static fsp_err_t r_lcdc_open_param_check(display_cfg_t const * const p_cfg);
static fsp_err_t r_lcdc_open_param_check_sync_signal(display_cfg_t const * const p_cfg);
static fsp_err_t r_lcdc_open_param_check_display_cycle(display_cfg_t const * const p_cfg);
static fsp_err_t r_lcdc_open_param_check_layer_setting(display_cfg_t const * const p_cfg);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
const display_api_t g_display_on_lcdc =
{
    .open         = R_LCDC_Open,
    .close        = R_LCDC_Close,
    .start        = R_LCDC_Start,
    .stop         = R_LCDC_Stop,
    .layerChange  = R_LCDC_LayerChange,
    .bufferChange = R_LCDC_BufferChange,
    .clut         = R_LCDC_ClutUpdate,
    .clutEdit     = R_LCDC_ClutEdit,
    .correction   = R_LCDC_ColorCorrection,
    .colorKeySet  = R_LCDC_ColorKeySet,
    .statusGet    = R_LCDC_StatusGet,
};

static const uint32_t display_format_table[] =
{
    /* This table is used for Color Format setting
     * If you selected RGB565 as input format, 0x00000006 is written to the RDFMT bits in VI6_RPFn_INFMT */

    /* Common input format */
    0x00000013,                        /* ARGB8888,                       32 bits */
    0x00000000,                        /* RGB888,                         32 bits */
    0x00000006,                        /* RGB565,                         16 bits */
    0x00000000,                        /* ARGB1555                        16 bits */
    0x00000000,                        /* ARGB4444                        16 bits */
    0x00000000,                        /* CLUT8 */
    0x00000000,                        /* CLUT4 */
    0x00000000,                        /* CLUT1 */
    /* Extend input format */
    0x00000014,                        /* RGBA8888,                        24 bits */
    0x00000015,                        /* RGB888,                          24 bits */
    0x00000018,                        /* BGR888,                          24 bits */
    0x00000022,                        /* ABGR8888,                        24 bits */
    0x00000146,                        /* YCbCr444 interleaved,            24 bits */
    0x00000147,                        /* YCbCr422 interleaved type0 UYVY, 16 bits */
    0x00008147,                        /* YCbCr422 interleaved type0 YUY2, 16 bits */
    0x0000C147,                        /* YCbCr422 interleaved type0 YVYU, 16 bits */
    0x00000148,                        /* YCbCr420 interleaved type1,      16 bits */
    0x00000149,                        /* YCbCr420 interleaved,            16 bits */
    0x0000014C,                        /* YCbCr420 Planar                  16 bits */
};

static lcdc_ctrl_t r_lcdc_blk =
{
    .p_context = NULL,
};

static display_list_data_type dl_body __attribute__((section(".nocache"), __aligned__(16)));
static uint32_t               layer_status;

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 *
 * @addtogroup LCDC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 *　Initializes the LCDC modules and enables interrupts
 *
 * @retval FSP_SUCCESS Initializes the LCDC modules.
 * @retval FSP_ERR_ALREADY_OPEN             LCDC module is open already.
 * @retval FSP_ERR_ASSERTION                Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_TIMING_SETTING   Invalid timing parameter.
 * @retval FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_Open (display_ctrl_t * const p_api_ctrl, display_cfg_t const * const p_cfg)
{
    fsp_err_t              err    = FSP_SUCCESS;
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;

    p_ctrl->p_cfg        = p_cfg;
    p_ctrl->p_context    = p_cfg->p_context;
    p_ctrl->p_callback   = p_cfg->p_callback;
    r_lcdc_blk.p_context = p_ctrl;

#if  (LCDC_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters */
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->state <= DISPLAY_STATE_CLOSED, FSP_ERR_ALREADY_OPEN);
    err = r_lcdc_open_param_check(p_cfg);
    if (FSP_SUCCESS != err)
    {
        return err;
    }
#endif
    R_BSP_MODULE_START(FSP_IP_LCDC, 0);

    /* FCPVD processing mode */
    R_LCDC->FCP_CFG0_b.FCPVSEL = 0;

    /* DU Initialization */
    r_lcdc_du_set(p_cfg);

    /* Clock Setting */
    r_lcdc_clock_set();

    /* Display IRQ Setting */
    /* Interrupt Enable for Display Start */
    R_LCDC->VI6_DISP0_IRQ_STA_b.MAE = 1;

    /* Interrupt Enable for Display Read Data End */
    R_LCDC->VI6_DISP0_IRQ_STA_b.DST = 1;

    /* Enable LCDC Interrupt */
    r_lcdc_interrupt_enable(p_cfg, p_api_ctrl);

    /* Initialize Layer Status */
    layer_status = LAYER_STATUS_INIT;

    /* Layer 1 Setting (RPF0) */
    r_lcdc_layer1_set(p_cfg);

    /* Layer 2 Setting (RPF1) */
    r_lcdc_layer2_set(p_cfg);

    /* Output Setting */
    r_lcdc_output_set(p_cfg);

    /* Display List Initialization */
    r_lcdc_dl_set();

    /* Display List Body Address Set */
    r_lcdc_dl_address_set(p_cfg);

    /* LIF Setting */
    /* Always specify 1500 */
    R_LCDC->VI6_LIF0_CTRL_b.OBTH = LCDC_VSPD_LIF_CTRL_OBTH;

    /* DU is selected as the destination external display module */
    R_LCDC->VI6_LIF0_CTRL_b.REQSEL = 1;

    /* Data output to the external display module is enabled */
    R_LCDC->VI6_LIF0_CTRL_b.LIF_EN = 1;

    /* Always specify 1 */
    R_LCDC->VI6_LIF0_LBA_b.LBA0 = 1;

    /* Always specify 1536 */
    R_LCDC->VI6_LIF0_LBA_b.LBA1 = LCDC_VSPD_LIF_CTRL_LBA1;

    /* DPR Setting */
    r_lcdc_dpr_set();

    /* BRS Setting */
    r_lcdc_brs_set();

    /* Start WPF */
    R_LCDC->VI6_CMD0_b.STRCMD = 1;
    while (R_LCDC->VI6_DISP0_IRQ_STA_b.DST == 0)
    {
        /*
         * No Operation
         */
    }

    R_LCDC->DU_MCR0_b.DI_EN = 1;

    p_ctrl->state = DISPLAY_STATE_OPENED;

    return err;
}

/*******************************************************************************************************************//**
 * Close the display while the LCDC module is operating
 *
 * @retval FSP_SUCCESS          Close the LCDC module
 * @retval FSP_ERR_ASSERTION    Pointer to the control block is NULL.
 * @retval FSP_ERR_NOT_OPEN     LCDC module is not open
 **********************************************************************************************************************/
fsp_err_t R_LCDC_Close (display_ctrl_t * const p_api_ctrl)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t              err    = FSP_SUCCESS;

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(DISPLAY_STATE_CLOSED != p_ctrl->state, FSP_ERR_NOT_OPEN);
#endif

    /* Display Disable */
    R_LCDC->DU_MCR0_b.DI_EN = 0;
    while (R_LCDC->DU_MSR0_b.ST_DI_BSY == 1)
    {
        /*
         * No Operation
         */
    }

    /* Software Reset */
    R_LCDC->VI6_SRESET_b.SRST0 = 1;
    while (R_LCDC->VI6_WPF0_IRQ_STA_b.FRE == 0)
    {
        /*
         * No Operation
         */
    }

    p_ctrl->state = DISPLAY_STATE_CLOSED;

    return err;
}

/*******************************************************************************************************************//**
 * Start displaying a layer image. It is possible when LCDC state is open
 *
 * @retval FSP_SUCCESS          Start display Normally
 * @retval FSP_ERR_ASSERTION    Pointer to the control block is NULL.
 * @retval FSP_ERR_NOT_OPEN     LCDC module is not open
 **********************************************************************************************************************/
fsp_err_t R_LCDC_Start (display_ctrl_t * const p_api_ctrl)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t              err    = FSP_SUCCESS;

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(DISPLAY_STATE_OPENED == p_ctrl->state, FSP_ERR_NOT_OPEN);
#endif

    /* Set Data to Display List Body */
    dl_body.cmd[0].set_data = layer_status;

    /* Display List Update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;

    p_ctrl->state = DISPLAY_STATE_DISPLAYING;

    return err;
}

/*******************************************************************************************************************//**
 * Start displaying a layer image. It is possible when LCDC state is displaying
 *
 * @retval FSP_SUCCESS              Stop the LCDC module
 * @retval FSP_ERR_ASSERTION        Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     LCDC module status is invalid for R_LCDC_Stop API
 **********************************************************************************************************************/
fsp_err_t R_LCDC_Stop (display_ctrl_t * const p_api_ctrl)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t              err    = FSP_SUCCESS;

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN((DISPLAY_STATE_DISPLAYING == p_ctrl->state), FSP_ERR_INVALID_MODE);
#endif

    /* Disable All Layers */
    layer_status &= LAYER_DISABLE_ALL;

    /* Set data to Display List body */
    dl_body.cmd[0].set_data = layer_status;

    /* Display List Update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;

    if (!(layer_status))
    {
        p_ctrl->state = DISPLAY_STATE_OPENED;
    }
    else
    {
        /* Do Nothing */
    }

    return err;
}

/*******************************************************************************************************************//**
 * Change layer configurations. It is possible when LCDC state is displaying
 *
 * @retval FSP_SUCCESS                      The LCDC layer is changed
 * @retval FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter
 * @retval FSP_ERR_ASSERTION                Pointer to the control block and configuration structure is NULL.
 * @retval FSP_ERR_INVALID_MODE             LCDC module status is invalid for R_LCDC_LayerChange API
 **********************************************************************************************************************/
fsp_err_t R_LCDC_LayerChange (display_ctrl_t const * const        p_api_ctrl,
                              display_runtime_cfg_t const * const p_cfg,
                              display_frame_layer_t               layer)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    FSP_PARAMETER_NOT_USED(p_ctrl);

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_cfg);
    FSP_ERROR_RETURN((DISPLAY_STATE_DISPLAYING == p_ctrl->state), FSP_ERR_INVALID_MODE);
#endif

    /* Check Layer runtime parameter */
    FSP_ERROR_RETURN((p_cfg->input.hsize <= LAYER_MAX_HSIZE), FSP_ERR_INVALID_LAYER_SETTING);
    FSP_ERROR_RETURN((p_cfg->input.vsize <= LAYER_MAX_VSIZE), FSP_ERR_INVALID_LAYER_SETTING);
    FSP_ERROR_RETURN((p_cfg->input.coordinate_x <= LAYER_MAX_HCOOR), FSP_ERR_INVALID_LAYER_SETTING);
    FSP_ERROR_RETURN((p_cfg->input.coordinate_y <= LAYER_MAX_VCOOR), FSP_ERR_INVALID_LAYER_SETTING);

    /* Check layer number */
    FSP_ERROR_RETURN((layer == 0 || layer == 1), FSP_ERR_INVALID_LAYER_SETTING);

    /* Change Layer Parameters */
    r_lcdc_layer_change(p_cfg, layer);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Change Buffer configuration. It is possible when LCDC state is displaying
 *
 * @retval FSP_SUCCESS              The Buffer read by LCDC is changed
 * @retval FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter
 * @retval FSP_ERR_ASSERTION                Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     LCDC module status is invalid for R_LCDC_BufferChange API
 **********************************************************************************************************************/
fsp_err_t R_LCDC_BufferChange (display_ctrl_t const * const p_api_ctrl,
                               uint8_t * const              framebuffer,
                               display_frame_layer_t        layer)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    FSP_PARAMETER_NOT_USED(p_ctrl);

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN((DISPLAY_STATE_DISPLAYING == p_ctrl->state), FSP_ERR_INVALID_MODE);
#endif

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    /* Check layer number */
    FSP_ERROR_RETURN((layer == 0 || layer == 1), FSP_ERR_INVALID_LAYER_SETTING);

    /* Display List Setting */
    /* Set data to Display List Body */
    if (layer == DISPLAY_FRAME_LAYER_1)
    {
        if (framebuffer == NULL)
        {
            /* Disable Layer1 (RPF0) */
            layer_status &= LAYER_DISABLE_1;
        }
        else
        {
            /* Enable Layer1 (RPF0) */
            layer_status |= LAYER_ENABLE_1;
        }

        /* Set layer1's buffer address to Display List Body */
        /* Set physical address of buffer to descriptor */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        va = (uint64_t) framebuffer & CAST_TO_UINT32;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        dl_body.cmd[1].set_data = pa & CAST_TO_UINT32;
#else
        dl_body.cmd[1].set_data = (uint64_t) framebuffer & CAST_TO_UINT32;
#endif
    }
    else if (layer == DISPLAY_FRAME_LAYER_2)
    {
        if (framebuffer == NULL)
        {
            /* Disable Layer1 (RPF0) */
            layer_status &= LAYER_DISABLE_2;
        }
        else
        {
            /* Enable Layer1 (RPF0) */
            layer_status |= LAYER_ENABLE_2;
        }

        /* Set layer2's buffer address to Display List Body */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        va = (uint64_t) framebuffer & CAST_TO_UINT32;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        dl_body.cmd[11].set_data = pa & CAST_TO_UINT32;
#else
        dl_body.cmd[11].set_data = (uint64_t) framebuffer & CAST_TO_UINT32;
#endif

        // dl_body.cmd[11].set_data = (uint64_t) framebuffer & CAST_TO_UINT32;
    }
    else
    {
        /* Do Nothing */
    }

    /* Set Data to Display List Body */
    dl_body.cmd[0].set_data = layer_status;

    /* Display List Update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Placeholder for unsupported color correction function. Implements display_api_t::correction.
 *
 * @retval FSP_ERR_UNSUPPORTED      Color correction is not supported.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_ColorCorrection (display_ctrl_t const * const       p_api_ctrl,
                                  display_correction_t const * const p_correction)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_correction);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Placeholder for unsupported CLUT update function. Implements display_api_t::clut.
 *
 * @retval FSP_ERR_UNSUPPORTED      CLUT update is not supported.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_ClutUpdate (display_ctrl_t const * const     p_api_ctrl,
                             display_clut_cfg_t const * const p_clut_cfg,
                             display_frame_layer_t            layer)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_clut_cfg);
    FSP_PARAMETER_NOT_USED(layer);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Placeholder for unsupported CLUT edit function. Implements display_api_t::clutEdit.
 *
 * @retval FSP_ERR_UNSUPPORTED      CLUT edit is not supported.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_ClutEdit (display_ctrl_t const * const p_api_ctrl,
                           display_frame_layer_t        layer,
                           uint8_t                      index,
                           uint32_t                     color)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(layer);
    FSP_PARAMETER_NOT_USED(index);
    FSP_PARAMETER_NOT_USED(color);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Set the Color Keying Configuration. It is possible when LCDC state is displaying.
 *
 * @retval FSP_SUCCESS                      The source color is changed to destination color
 * @retval FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter
 * @retval FSP_ERR_ASSERTION                Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE             LCDC module status is invalid for R_LCDC_ColorKeying API
 **********************************************************************************************************************/
fsp_err_t R_LCDC_ColorKeySet (display_ctrl_t const * const p_api_ctrl,
                              display_colorkeying_layer_t  ck_cfg,
                              display_frame_layer_t        layer)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    FSP_PARAMETER_NOT_USED(p_ctrl);

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN((DISPLAY_STATE_DISPLAYING == p_ctrl->state), FSP_ERR_INVALID_MODE);
#endif

    /* Check layer number */
    FSP_ERROR_RETURN((layer == 0 || layer == 1), FSP_ERR_INVALID_LAYER_SETTING);

    /* Color Keying */
    r_lcdc_ckey_set(ck_cfg, layer);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the current status of LCDC module. (close or open or displaying)
 *
 * @retval FSP_SUCCESS      Get status of LCDC module
 * @retval FSP_ERR_ASSERTION    Pointer to the control block and status structure is NULL.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_StatusGet (display_ctrl_t const * const p_api_ctrl, display_status_t * const p_status)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    FSP_PARAMETER_NOT_USED(p_ctrl);

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_status);
#endif

    p_status->state = p_ctrl->state;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup IOPORT)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Display Unit setting function. This function can set signal timing setting.
 *
 * @param[in]       p_cfg       LCDC configuration parameters.
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_du_set (display_cfg_t const * const p_cfg)
{
    static uint32_t h_fp;
    static uint32_t h_bp;
    static uint32_t h_active;
    static uint32_t h_sa;
    static uint32_t v_fp;
    static uint32_t v_bp;
    static uint32_t v_active;
    static uint32_t v_sa;

    if (p_cfg->output.data_enable_polarity == DISPLAY_SIGNAL_POLARITY_LOACTIVE)
    {
        /* DE output mode */
        R_LCDC->DU_DITR0_b.DEMD = 0;
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->output.htiming.sync_polarity == DISPLAY_SIGNAL_POLARITY_LOACTIVE)
    {
        /* hsync polarity */
        R_LCDC->DU_DITR0_b.HSPOL = 0;
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->output.vtiming.sync_polarity == DISPLAY_SIGNAL_POLARITY_LOACTIVE)
    {
        /* vsync polarity */
        R_LCDC->DU_DITR0_b.VSPOL = 0;
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->output.sync_edge == DISPLAY_SIGNAL_SYNC_EDGE_FALLING)
    {
        /* Display parallel interface clock mode */
        R_LCDC->DU_DITR0_b.DPI_CLKMD = 1;
    }
    else
    {
        /* Do Nothing */
    }

    h_active = (p_cfg->output.htiming.display_cyc);
    h_sa     = (p_cfg->output.htiming.sync_width);
    h_bp     = (uint32_t) (p_cfg->output.htiming.back_porch - p_cfg->output.htiming.sync_width);
    h_fp     =
        (uint32_t) (p_cfg->output.htiming.total_cyc - p_cfg->output.htiming.back_porch -
                    p_cfg->output.htiming.display_cyc);
    v_active = p_cfg->output.vtiming.display_cyc;
    v_sa     = p_cfg->output.vtiming.sync_width;
    v_bp     = (uint32_t) (p_cfg->output.vtiming.back_porch - p_cfg->output.vtiming.sync_width);
    v_fp     =
        (uint32_t) (p_cfg->output.vtiming.total_cyc - p_cfg->output.vtiming.back_porch -
                    p_cfg->output.vtiming.display_cyc);

    R_LCDC->DU_DITR3 = h_active << 16 | h_sa;
    R_LCDC->DU_DITR4 = h_fp << 16 | h_bp;
    R_LCDC->DU_DITR1 = v_active << 16 | v_sa;
    R_LCDC->DU_DITR2 = v_fp << 16 | v_bp;

    /* Fixed value */
    R_LCDC->DU_PBCR0 = LCDC_DU_PBCR0;
}

/*******************************************************************************************************************//**
 * Subroutine to configure dot clock setting
 *
 * @retval      none
 **********************************************************************************************************************/
static void r_lcdc_clock_set (void)
{
    /* Fixed value */
    R_LCDC->VI6_CLK_CTRL0 = LCDC_VSPD_CLK_CTRL0;
    R_LCDC->VI6_CLK_CTRL1 = LCDC_VSPD_CLK_CTRL1;
    R_LCDC->VI6_CLK_DCSWT = LCDC_VSPD_CLK_DCSWT;
    R_LCDC->VI6_CLK_DCSM0 = LCDC_VSPD_CLK_DCSM0;
    R_LCDC->VI6_CLK_DCSM1 = LCDC_VSPD_CLK_DCSM1;
}

/*******************************************************************************************************************//**
 * Display list setting.
 *
 * @retval      none
 **********************************************************************************************************************/
static void r_lcdc_dl_set (void)
{
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    /* Fixed Value */
    R_LCDC->VI6_DL_CTRL_b.AR_WAIT = LCDC_VSPD_DL_CTRL;

    /* These bits doesn’t affect anything to VSPD */
    R_LCDC->VI6_DL_CTRL_b.DC2  = 1;
    R_LCDC->VI6_DL_CTRL_b.DC1  = 1;
    R_LCDC->VI6_DL_CTRL_b.DLE1 = 1;

    /* The next frame is automatically started */
    R_LCDC->VI6_DL_CTRL_b.CFM0 = 1;

    /* Don’t use Display List Header (Header-less Mode) */
    R_LCDC->VI6_DL_CTRL_b.NH0 = 1;

    /* The display list function is enabled */
    R_LCDC->VI6_DL_CTRL_b.DLE0 = 1;

    /* Display lsit body size setting */
    R_LCDC->VI6_DL_BODY_SIZE0_b.BS0 = LCDC_VSPD_DL_BODY_SIZE;

    /* Always specify 2 */
    R_LCDC->VI6_DL_EXT_CTRL0_b.POLINT = 0x02;

    /* Always specify 1. */
    R_LCDC->VI6_DL_EXT_CTRL0_b.DLPRI = 1;

    /* Display List Header Address */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) (&dl_body) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    R_LCDC->VI6_DL_HDR_ADDR0 = pa & CAST_TO_UINT32;
#else
    R_LCDC->VI6_DL_HDR_ADDR0 = (uint64_t) (&dl_body) & CAST_TO_UINT32;
#endif

    /* Data swapping in long word (32-bit) units is enabled */
    R_LCDC->VI6_DL_SWAP0_b.LWS = 1;
}

/*******************************************************************************************************************//**
 * Display List address setting.
 *
 * @param[in]       p_cfg       LCDC configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_dl_address_set (display_cfg_t const * const p_cfg)
{
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    /* set Display List Body address */
    dl_body.cmd[0].set_address  = (uint64_t) (&(R_LCDC->VI6_WPF0_SRCRPF)) & CAST_TO_UINT32;
    dl_body.cmd[1].set_address  = (uint64_t) (&(R_LCDC->VI6_RPF0_SRCM_ADDR_Y)) & CAST_TO_UINT32;
    dl_body.cmd[2].set_address  = (uint64_t) (&(R_LCDC->VI6_RPF0_INFMT)) & CAST_TO_UINT32;
    dl_body.cmd[3].set_address  = (uint64_t) (&(R_LCDC->VI6_RPF0_SRC_BSIZE)) & CAST_TO_UINT32;
    dl_body.cmd[4].set_address  = (uint64_t) (&(R_LCDC->VI6_RPF0_SRC_ESIZE)) & CAST_TO_UINT32;
    dl_body.cmd[5].set_address  = (uint64_t) (&(R_LCDC->VI6_RPF0_SRCM_PSTRIDE)) & CAST_TO_UINT32;
    dl_body.cmd[6].set_address  = (uint64_t) (&(R_LCDC->VI6_RPF0_LOC)) & CAST_TO_UINT32;
    dl_body.cmd[7].set_address  = (uint64_t) (&(R_LCDC->VI6_RPF0_DSWAP)) & CAST_TO_UINT32;
    dl_body.cmd[8].set_address  = (uint64_t) (&(R_LCDC->VI6_RPF0_CKEY_CTRL)) & CAST_TO_UINT32;
    dl_body.cmd[9].set_address  = (uint64_t) (&(R_LCDC->VI6_RPF0_CKEY_SET0)) & CAST_TO_UINT32;
    dl_body.cmd[10].set_address = (uint64_t) (&(R_LCDC->VI6_RPF0_CKEY_SET1)) & CAST_TO_UINT32;
    dl_body.cmd[11].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_SRCM_ADDR_Y)) & CAST_TO_UINT32;
    dl_body.cmd[12].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_INFMT)) & CAST_TO_UINT32;
    dl_body.cmd[13].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_SRC_BSIZE)) & CAST_TO_UINT32;
    dl_body.cmd[14].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_SRC_ESIZE)) & CAST_TO_UINT32;
    dl_body.cmd[15].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_SRCM_PSTRIDE)) & CAST_TO_UINT32;
    dl_body.cmd[16].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_LOC)) & CAST_TO_UINT32;
    dl_body.cmd[17].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_DSWAP)) & CAST_TO_UINT32;
    dl_body.cmd[18].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_CKEY_CTRL)) & CAST_TO_UINT32;
    dl_body.cmd[19].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_CKEY_SET0)) & CAST_TO_UINT32;
    dl_body.cmd[20].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_CKEY_SET1)) & CAST_TO_UINT32;
    dl_body.cmd[21].set_address = (uint64_t) (&(R_LCDC->VI6_RPF0_SRCM_ADDR_C0)) & CAST_TO_UINT32;
    dl_body.cmd[22].set_address = (uint64_t) (&(R_LCDC->VI6_RPF0_SRCM_ADDR_C1)) & CAST_TO_UINT32;
    dl_body.cmd[23].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_SRCM_ADDR_C0)) & CAST_TO_UINT32;
    dl_body.cmd[24].set_address = (uint64_t) (&(R_LCDC->VI6_RPF1_SRCM_ADDR_C1)) & CAST_TO_UINT32;

    /* set Display List Body data */
    dl_body.cmd[0].set_data = LAYER_STATUS_INIT;

    /* Set physical address of buffer to descriptor */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) (p_cfg->input[0].p_base) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    dl_body.cmd[1].set_data = pa & CAST_TO_UINT32;
#else
    dl_body.cmd[1].set_data = (uint64_t) (p_cfg->input[0].p_base) & CAST_TO_UINT32;
#endif
    dl_body.cmd[2].set_data = display_format_table[p_cfg->input[0].format];

    /* input format : RGB - output format : YCbCr */
    if ((p_cfg->input[0].format <= 5) && ((p_cfg->output.format) >= 6))
    {
        dl_body.cmd[2].set_data |= COLOR_FOTMAT_CONVERT;
    }
    /* input format : YCbCr - output format : RGB */
    else if ((p_cfg->output.format <= 5) && ((p_cfg->input[0].format) >= 6))
    {
        dl_body.cmd[2].set_data |= COLOR_FOTMAT_CONVERT;
    }
    else
    {
        /* Do Nothing */
    }

    dl_body.cmd[3].set_data  = (uint32_t) ((p_cfg->input[0].hsize << 16) + p_cfg->input[0].vsize);
    dl_body.cmd[4].set_data  = (uint32_t) ((p_cfg->input[0].hsize << 16) + p_cfg->input[0].vsize);
    dl_body.cmd[5].set_data  = (uint32_t) ((p_cfg->input[0].hstride) << 16 | (p_cfg->input[0].hstride_cbcr));
    dl_body.cmd[6].set_data  = (uint32_t) ((p_cfg->input[0].coordinate_x << 16) + p_cfg->input[0].coordinate_y);
    dl_body.cmd[7].set_data  = (uint32_t) (p_cfg->input[0].data_swap);
    dl_body.cmd[8].set_data  = 0;
    dl_body.cmd[9].set_data  = 0;
    dl_body.cmd[10].set_data = 0;

    /* Set physical address of buffer to descriptor */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) (p_cfg->input[1].p_base) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    dl_body.cmd[11].set_data = pa & CAST_TO_UINT32;
#else
    dl_body.cmd[11].set_data = (uint64_t) (p_cfg->input[1].p_base) & CAST_TO_UINT32;
#endif

    dl_body.cmd[12].set_data = display_format_table[p_cfg->input[1].format];

    /* input format : RGB - output format : YCbCr */
    if ((p_cfg->input[1].format <= 5) && ((p_cfg->output.format) >= 6))
    {
        dl_body.cmd[12].set_data |= COLOR_FOTMAT_CONVERT;
    }
    /* input format : YCbCr - output format : RGB */
    else if ((p_cfg->output.format <= 5) && ((p_cfg->input[1].format) >= 6))
    {
        dl_body.cmd[12].set_data |= COLOR_FOTMAT_CONVERT;
    }
    else
    {
        /* Do Nothing */
    }

    dl_body.cmd[13].set_data = (uint32_t) ((p_cfg->input[1].hsize << 16) + p_cfg->input[1].vsize);
    dl_body.cmd[14].set_data = (uint32_t) ((p_cfg->input[1].hsize << 16) + p_cfg->input[1].vsize);
    dl_body.cmd[15].set_data = (uint32_t) ((p_cfg->input[1].hstride) << 16 | (p_cfg->input[1].hstride));
    dl_body.cmd[16].set_data = (uint32_t) ((p_cfg->input[1].coordinate_x << 16) + p_cfg->input[1].coordinate_y);
    dl_body.cmd[17].set_data = (uint32_t) (p_cfg->input[1].data_swap);
    dl_body.cmd[18].set_data = 0;
    dl_body.cmd[19].set_data = 0;
    dl_body.cmd[20].set_data = 0;

    /* Set physical address of buffer to descriptor */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) (p_cfg->input[0].p_base_cb) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    dl_body.cmd[21].set_data = pa & CAST_TO_UINT32;

    va = (uint64_t) (p_cfg->input[0].p_base_cr) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    dl_body.cmd[22].set_data = pa & CAST_TO_UINT32;

    va = (uint64_t) (p_cfg->input[1].p_base_cb) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    dl_body.cmd[23].set_data = pa & CAST_TO_UINT32;

    va = (uint64_t) (p_cfg->input[1].p_base_cr) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    dl_body.cmd[24].set_data = pa & CAST_TO_UINT32;
#else
    dl_body.cmd[21].set_data = (uint64_t) (p_cfg->input[0].p_base_cb) & CAST_TO_UINT32;
    dl_body.cmd[22].set_data = (uint64_t) (p_cfg->input[0].p_base_cr) & CAST_TO_UINT32;
    dl_body.cmd[23].set_data = (uint64_t) (p_cfg->input[1].p_base_cb) & CAST_TO_UINT32;
    dl_body.cmd[24].set_data = (uint64_t) (p_cfg->input[1].p_base_cr) & CAST_TO_UINT32;
#endif
}

/*******************************************************************************************************************//**
 * Display for Layer1 settings.
 *
 * @param[in]       p_cfg       LCDC configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_layer1_set (display_cfg_t const * const p_cfg)
{
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif
    static uint32_t hsize;
    static uint32_t vsize;
    static uint32_t coor_x;
    static uint32_t coor_y;

    /* Format Setting */
    R_LCDC->VI6_RPF0_INFMT = display_format_table[p_cfg->input[0].format];

    /* Size Setting */
    hsize = (uint32_t) p_cfg->input[0].hsize;
    vsize = (uint32_t) p_cfg->input[0].vsize;
    R_LCDC->VI6_RPF0_SRC_BSIZE = hsize << 16 | vsize;
    R_LCDC->VI6_RPF0_SRC_ESIZE = hsize << 16 | vsize;

    /* Stride Setting */
    R_LCDC->VI6_RPF0_SRCM_PSTRIDE_b.PICT_STRD_Y = p_cfg->input[0].hstride;
    R_LCDC->VI6_RPF0_SRCM_PSTRIDE_b.PICT_STRD_C = p_cfg->input[0].hstride_cbcr;

    /* Location Setting */
    coor_x               = (uint32_t) p_cfg->input[0].coordinate_x;
    coor_y               = (uint32_t) p_cfg->input[0].coordinate_y;
    R_LCDC->VI6_RPF0_LOC = coor_x << 16 | coor_y;

    /* Buffer address Setting */
    /* Set physical address of buffer to descriptor */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) p_cfg->input[0].p_base & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    R_LCDC->VI6_RPF0_SRCM_ADDR_Y = pa & CAST_TO_UINT32;

    va = (uint64_t) p_cfg->input[0].p_base_cb & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    R_LCDC->VI6_RPF0_SRCM_ADDR_C0 = pa & CAST_TO_UINT32;

    va = (uint64_t) p_cfg->input[0].p_base_cr & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    R_LCDC->VI6_RPF0_SRCM_ADDR_C1 = pa & CAST_TO_UINT32;
#else
    R_LCDC->VI6_RPF0_SRCM_ADDR_Y  = (uint64_t) p_cfg->input[0].p_base & CAST_TO_UINT32;
    R_LCDC->VI6_RPF0_SRCM_ADDR_C0 = (uint64_t) p_cfg->input[0].p_base_cb & CAST_TO_UINT32;
    R_LCDC->VI6_RPF0_SRCM_ADDR_C1 = (uint64_t) p_cfg->input[0].p_base_cr & CAST_TO_UINT32;
#endif

    /* Alpha Setting (RPF0 Alpha data is 0x00) */
    R_LCDC->VI6_RPF0_ALPH_SEL_b.ASEL = 0;

    /* Swap Setting */
    R_LCDC->VI6_RPF0_DSWAP = p_cfg->input[0].data_swap;

    if (p_cfg->input[0].p_base == NULL)
    {
        /* Disable Layer1 (RPF0) */
        layer_status &= LAYER_DISABLE_1;
    }
    else
    {
        /* Enable layer1 (RPF0) */
        layer_status |= LAYER_ENABLE_1;
    }
}

/*******************************************************************************************************************//**
 * Display for Layer2 settings.
 *
 * @param[in]       p_cfg       LCDC configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_layer2_set (display_cfg_t const * const p_cfg)
{
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif
    static uint32_t hsize;
    static uint32_t vsize;
    static uint32_t coor_x;
    static uint32_t coor_y;

    /* Format Setting */
    R_LCDC->VI6_RPF1_INFMT = display_format_table[p_cfg->input[1].format];

    /* Size Setting */
    hsize = (uint32_t) p_cfg->input[1].hsize;
    vsize = (uint32_t) p_cfg->input[1].vsize;
    R_LCDC->VI6_RPF1_SRC_BSIZE = hsize << 16 | vsize;
    R_LCDC->VI6_RPF1_SRC_ESIZE = hsize << 16 | vsize;

    /* Stride Setting */
    R_LCDC->VI6_RPF1_SRCM_PSTRIDE_b.PICT_STRD_Y = p_cfg->input[1].hstride;
    R_LCDC->VI6_RPF1_SRCM_PSTRIDE_b.PICT_STRD_C = p_cfg->input[1].hstride_cbcr;

    /* Location Setting */
    coor_x               = (uint32_t) p_cfg->input[1].coordinate_x;
    coor_y               = (uint32_t) p_cfg->input[1].coordinate_y;
    R_LCDC->VI6_RPF1_LOC = coor_x << 16 | coor_y;

    /* Buffer address Setting */
    /* Set physical address of buffer to descriptor */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) p_cfg->input[1].p_base & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    R_LCDC->VI6_RPF1_SRCM_ADDR_Y = pa & CAST_TO_UINT32;

    va = (uint64_t) p_cfg->input[1].p_base_cb & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    R_LCDC->VI6_RPF1_SRCM_ADDR_C0 = pa & CAST_TO_UINT32;

    va = (uint64_t) p_cfg->input[1].p_base_cr & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    R_LCDC->VI6_RPF1_SRCM_ADDR_C1 = pa & CAST_TO_UINT32;
#else
    R_LCDC->VI6_RPF1_SRCM_ADDR_Y  = (uint64_t) p_cfg->input[1].p_base & CAST_TO_UINT32;
    R_LCDC->VI6_RPF1_SRCM_ADDR_C0 = (uint64_t) p_cfg->input[1].p_base_cb & CAST_TO_UINT32;
    R_LCDC->VI6_RPF1_SRCM_ADDR_C1 = (uint64_t) p_cfg->input[1].p_base_cr & CAST_TO_UINT32;
#endif

    /* Alpha Setting */
    R_LCDC->VI6_RPF1_ALPH_SEL_b.ASEL = 0;

    /* Swap Setting */
    R_LCDC->VI6_RPF1_DSWAP = p_cfg->input[1].data_swap;

    if (p_cfg->input[1].p_base == NULL)
    {
        /* Disable Layer1 (RPF0) */
        layer_status &= LAYER_DISABLE_2;
    }
    else
    {
        /* Enable layer1 (RPF0) */
        layer_status |= LAYER_ENABLE_2;
    }
}

/*******************************************************************************************************************//**
 * LCDC output settings
 *
 * @param[in]       p_cfg       LCDC configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_output_set (display_cfg_t const * const p_cfg)
{
    static uint32_t hsize;
    static uint32_t vsize;

    /* WPF IRQ Setting */
    R_LCDC->VI6_WPF0_IRQ_ENB_b.DFEE = 0;
    R_LCDC->VI6_WPF0_IRQ_ENB_b.FREE = 1;

    /*Background layer Setting */
    R_LCDC->VI6_WPF0_SRCRPF = LAYER_DISABLE_ALL;

    /* Format Setting */
    R_LCDC->VI6_WPF0_OUTFMT = display_format_table[p_cfg->output.format];

    /* Dithering Setting */
    R_LCDC->VI6_WPF0_OUTFMT |=
        (uint32_t) ((((p_cfg->output.dithering_on) << 13) | ((p_cfg->output.dithering_on) << 12)));

    /* Background Color Setting */
    hsize = (uint32_t) p_cfg->output.htiming.display_cyc;
    vsize = (uint32_t) p_cfg->output.vtiming.display_cyc;
    R_LCDC->VI6_BRS_VIRRPF_SIZE = hsize << 16 | vsize;

    /* Set Background Layer Location */
    R_LCDC->VI6_BRS_VIRRPF_LOC = 0x00000000;
    R_LCDC->VI6_BRS_VIRRPF_COL = p_cfg->output.bg_color.argb;

    /* Write Back setting */
    R_LCDC->VI6_WPF0_WRBCK_CTRL_b.WBMD = 0;
}

/*******************************************************************************************************************//**
 * Data Path Router settings. Select using modules.
 *
 * @retval      none
 **********************************************************************************************************************/
static void r_lcdc_dpr_set (void)
{
    /* RPF0 -> BRSin0 */
    R_LCDC->VI6_DPR_RPF0_ROUTE_b.RT_RPF0 = LCDC_VSPD_DPR_RPF0_ROUTE_RT_RPF0;

    /* RPF1 -> BRSin1 */
    R_LCDC->VI6_DPR_RPF1_ROUTE_b.RT_RPF1 = LCDC_VSPD_DPR_RPF0_ROUTE_RT_RPF1;

    /* Fixed Value */
    R_LCDC->VI6_DPR_WPF0_FPORCH_b.FP_WPF0 = LCDC_VSPD_DPR_WPF0_FPROCH;

    /* Not Use LUT */
    R_LCDC->VI6_DPR_LUT_ROUTE_b.RT = LCDC_VSPD_DPR_LUT_ROUTE;

    /* Fixed Value */
    R_LCDC->VI6_DPR_ILV_BRS_ROUTE_b.BRSSEL = LCDC_VSPD_DPR_ILV_BRS_ROUTE_BRSSEL;

    /* BRS -> WPF0 */
    R_LCDC->VI6_DPR_ILV_BRS_ROUTE_b.RT = LCDC_VSPD_DPR_ILV_BRS_ROUTE_RT;
}

/*******************************************************************************************************************//**
 * Blend ROP Sub unit settings. Select ROP or alpha blending.
 *
 * @retval      none
 **********************************************************************************************************************/
static void r_lcdc_brs_set (void)
{
    /*Blending operation in RPF0 and RPF1 */
    R_LCDC->VI6_BRSA_CTRL_b.RBC = LCDC_VSPD_BRSA_CTRL_RBC;

    /* BRS input 1 (BRSin1) is input to DST */
    R_LCDC->VI6_BRSA_CTRL_b.DSTSEL = LCDC_VSPD_BRSA_CTRL_DSTSEL;

    /* BRS input 0 (BRSin0) is input to SRC */
    R_LCDC->VI6_BRSA_CTRL_b.SRCSEL = 0x0;

    /* ROP (raster operation) */
    R_LCDC->VI6_BRSB_CTRL_b.RBC = 0;

    /* BRS input 0 (BRSin0) is input to DST */
    R_LCDC->VI6_BRSB_CTRL_b.DSTSEL = 0x1;

    /* Virtual RPF is input to SRC */
    R_LCDC->VI6_BRSB_CTRL_b.SRCSEL = LCDC_VSPD_BRSB_CTRL_SRCSEL;

    /* Blending Expression :  */
    R_LCDC->VI6_BRSA_BLD_b.CBES = 0;

    /* (blending coefficient X) = (DST α data) */
    R_LCDC->VI6_BRSA_BLD_b.CCMDX = LCDC_VSPD_BRSA_BLD_CCMDX;

    /* (blending coefficient Y) = 255 - (DST α data) */
    R_LCDC->VI6_BRSA_BLD_b.CCMDY = LCDC_VSPD_BRSA_BLD_CCMDY;

    /* Blending α Creation Expression : X * (DST α data) + Y * (SRC α data) */
    R_LCDC->VI6_BRSA_BLD_b.ABES = 0;

    /* (α creation coefficient X) = 255 - (DST α data) */
    R_LCDC->VI6_BRSA_BLD_b.ACMDX = LCDC_VSPD_BRSB_BLD_CCMDX;

    /* (α creation coefficient Y) = 255 - (SRC α data) */
    R_LCDC->VI6_BRSA_BLD_b.ACMDY = LCDC_VSPD_BRSB_BLD_CCMDY;
}

/*******************************************************************************************************************//**
 * Change selected layer configuration
 *
 * @param[in]       p_cfg       LCDC configuration parameters
 * @param[in]       layer       selected layer number
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_layer_change (display_runtime_cfg_t const * const p_cfg, display_frame_layer_t layer)
{
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    /* Display List Body Setting */
    /* Change Layer Setting */
    if (layer == DISPLAY_FRAME_LAYER_1)
    {
        if (p_cfg->input.p_base == NULL)
        {
            /* Disable Layer1 (RPF0) */
            layer_status &= LAYER_DISABLE_1;
        }
        else
        {
            /* Enable Layer1 (RPF0) */
            layer_status |= LAYER_ENABLE_1;
        }

        /* Set physical address of buffer to descriptor */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        va = (uint64_t) (p_cfg->input.p_base) & CAST_TO_UINT32;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        dl_body.cmd[1].set_data = pa & CAST_TO_UINT32;
#else
        dl_body.cmd[1].set_data = (uint64_t) (p_cfg->input.p_base) & CAST_TO_UINT32;
#endif
        dl_body.cmd[2].set_data = display_format_table[p_cfg->input.format];
        dl_body.cmd[3].set_data = (uint32_t) ((p_cfg->input.hsize << 16) + p_cfg->input.vsize);
        dl_body.cmd[4].set_data = (uint32_t) ((p_cfg->input.hsize << 16) + p_cfg->input.vsize);
        dl_body.cmd[5].set_data = (uint32_t) (((p_cfg->input.hstride) << 16) | (p_cfg->input.hstride_cbcr));
        dl_body.cmd[6].set_data = (uint32_t) ((p_cfg->input.coordinate_x << 16) + p_cfg->input.coordinate_y);
        dl_body.cmd[7].set_data = (uint32_t) (p_cfg->input.data_swap);
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        va = (uint64_t) (p_cfg->input.p_base_cb) & CAST_TO_UINT32;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        dl_body.cmd[21].set_data = pa & CAST_TO_UINT32;

        va = (uint64_t) (p_cfg->input.p_base_cr) & CAST_TO_UINT32;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        dl_body.cmd[22].set_data = pa & CAST_TO_UINT32;
#else
        dl_body.cmd[21].set_data = (uint64_t) (p_cfg->input.p_base_cb) & CAST_TO_UINT32;
        dl_body.cmd[22].set_data = (uint64_t) (p_cfg->input.p_base_cr) & CAST_TO_UINT32;
#endif
    }
    else if (layer == DISPLAY_FRAME_LAYER_2)
    {
        if (p_cfg->input.p_base == NULL)
        {
            /* Disable Layer1 (RPF0) */
            layer_status &= LAYER_DISABLE_2;
        }
        else
        {
            /* Enable Layer1 (RPF0) */
            layer_status |= LAYER_ENABLE_2;
        }

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        va = (uint64_t) (p_cfg->input.p_base) & CAST_TO_UINT32;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        dl_body.cmd[11].set_data = pa & CAST_TO_UINT32;
#else
        dl_body.cmd[11].set_data = (uint64_t) (p_cfg->input.p_base) & CAST_TO_UINT32;
#endif
        dl_body.cmd[12].set_data = display_format_table[p_cfg->input.format];
        dl_body.cmd[13].set_data = (uint32_t) ((p_cfg->input.hsize << 16) + p_cfg->input.vsize);
        dl_body.cmd[14].set_data = (uint32_t) ((p_cfg->input.hsize << 16) + p_cfg->input.vsize);
        dl_body.cmd[15].set_data = (uint32_t) (((p_cfg->input.hstride) << 16) | (p_cfg->input.hstride_cbcr));
        dl_body.cmd[16].set_data = (uint32_t) ((p_cfg->input.coordinate_x << 16) + p_cfg->input.coordinate_y);
        dl_body.cmd[17].set_data = (uint32_t) (p_cfg->input.data_swap);
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        va = (uint64_t) (p_cfg->input.p_base_cb) & CAST_TO_UINT32;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        dl_body.cmd[23].set_data = pa & CAST_TO_UINT32;

        va = (uint64_t) (p_cfg->input.p_base_cr) & CAST_TO_UINT32;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        dl_body.cmd[24].set_data = pa & CAST_TO_UINT32;
#else
        dl_body.cmd[23].set_data = (uint64_t) (p_cfg->input.p_base_cb) & CAST_TO_UINT32;
        dl_body.cmd[24].set_data = (uint64_t) (p_cfg->input.p_base_cr) & CAST_TO_UINT32;
#endif
    }
    else
    {
        /* Do Nothing */
    }

    dl_body.cmd[0].set_data = layer_status;

    /* Display List update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;
}

/*******************************************************************************************************************//**
 * Color Keying setting for selected layer
 *
 * @param[in]       ck_cfg      LCDC configuration parameters for color keying
 * @param[in]       layer       selected layer number
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_ckey_set (display_colorkeying_layer_t ck_cfg, display_frame_layer_t layer)
{
    /* Display List Body Setting */
    /* Change color keying setting */
    if (layer == DISPLAY_FRAME_LAYER_1)
    {
        dl_body.cmd[8].set_data  = (uint32_t) (ck_cfg.layer[layer].enable_ckey << 4);
        dl_body.cmd[9].set_data  = ck_cfg.layer[layer].src_color.argb;
        dl_body.cmd[10].set_data = ck_cfg.layer[layer].dst_color.argb;
    }
    else
    {
        /* Do Nothing */
    }

    if (layer == DISPLAY_FRAME_LAYER_2)
    {
        dl_body.cmd[18].set_data = (uint32_t) (ck_cfg.layer[layer].enable_ckey << 4);
        dl_body.cmd[19].set_data = ck_cfg.layer[layer].src_color.argb;
        dl_body.cmd[20].set_data = ck_cfg.layer[layer].dst_color.argb;
    }
    else
    {
        /* Do Nothing */
    }

    /* Display List update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;
}

/*******************************************************************************************************************//**
 *  Set the interrupt setting for LCDC module
 *
 * @param[in]       p_cfg       LCDC configuration parameters
 * @param[in]       p_instance_ctrl     instance pointer of LCDC control
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_interrupt_enable (display_cfg_t const * const p_cfg, lcdc_instance_ctrl_t * const p_instance_ctrl)
{
    lcdc_extended_cfg_t * pextend = (lcdc_extended_cfg_t *) p_cfg->p_extend;

    /* LCDC Interrupt Setting */
    /* Interrupt Enable (or disable) for Frame End */
    R_LCDC->VI6_WPF0_IRQ_ENB_b.FREE = 1;

    /* Interrupt Enable (or disable) for DU Connection UnderRun Error */
    R_LCDC->VI6_WPF0_IRQ_ENB_b.UNDE = 1;

    if (pextend->frame_end_irq >= 0)
    {
        R_BSP_IrqCfgEnable(pextend->frame_end_irq, pextend->frame_end_ipl, p_instance_ctrl);
    }
    else
    {
        /* Do Nothing */
    }
}

/*******************************************************************************************************************//**
 *  Interrupt function for LCDC VSPD interrupt
 *
 * @param[in]       irq       FSP error type
 * @retval          none
 **********************************************************************************************************************/
void lcdc_vspd_int (IRQn_Type const irq)
{
    FSP_CONTEXT_SAVE FSP_PARAMETER_NOT_USED(irq);

    display_callback_args_t args;
    lcdc_instance_ctrl_t  * p_ctrl = (lcdc_instance_ctrl_t *) r_lcdc_blk.p_context;
    uint8_t                 event_flag;

    event_flag = 0;

    /* Check which interrupt is generated */
    if (1 == R_LCDC->VI6_WPF0_IRQ_STA_b.FRE)
    {
        event_flag = DISPLAY_EVENT_FRAME_END;
    }
    else
    {
        /* Do Nothing */
    }

    if (1 == R_LCDC->VI6_WPF0_IRQ_STA_b.UND)
    {
        event_flag = DISPLAY_EVENT_GR1_UNDERFLOW;
    }
    else
    {
        /* Do Nothing */
    }

    /* Call back callback function if it is registered */
    if (NULL != p_ctrl->p_callback)
    {
        args.event     = event_flag;
        args.p_context = p_ctrl->p_context;
        p_ctrl->p_callback(&args);
    }
    else
    {
        /* Do Nothing */
    }

    /* Clear interrupt flag */
    R_LCDC->VI6_WPF0_IRQ_STA_b.FRE = 0;
    R_LCDC->VI6_WPF0_IRQ_STA_b.UND = 0;

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)

/*******************************************************************************************************************//**
 * The parameter checking subroutine for R_LCDC_Open API.
 *
 * @param[in] p_cfg   Pointer to the configuration structure for display interface
 * @retval  FSP_SUCCESS                      No parameter error found
 * @retval  FSP_ERR_ASSERTION                Pointer to the control block is NULL.
 * @retval  FSP_ERR_INVALID_TIMING_SETTING   Invalid timing parameter.
 * @retval  FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter
 **********************************************************************************************************************/
static fsp_err_t r_lcdc_open_param_check (display_cfg_t const * const p_cfg)
{
    fsp_err_t error;

    FSP_ASSERT(p_cfg);
    FSP_ASSERT(p_cfg->p_extend);

    /* Sync signal parameter check */
    error = r_lcdc_open_param_check_sync_signal(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == error, error);

    error = r_lcdc_open_param_check_layer_setting(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == error, error);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * The parameter checking subroutine for R_LCDC_Open API.
 *
 * @param[in]   p_cfg   Pointer to the configuration structure for display interface
 * @retval      FSP_SUCCESS                         No parameter error found
 * @retval      FSP_ERR_INVALID_TIMING_SETTING      Invalid timing parameter.
 * @retval      FSP_ERR_INVALID_LAYER_SETTING       Invalid layer parameter
 **********************************************************************************************************************/
static fsp_err_t r_lcdc_open_param_check_sync_signal (display_cfg_t const * const p_cfg)
{
    fsp_err_t error;

    error = r_lcdc_open_param_check_display_cycle(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == error, error);

    error = r_lcdc_open_param_check_layer_setting(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == error, error);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * The parameter checking for display cycle.
 *
 * @param[in]   p_cfg   Pointer to the configuration structure for display interface
 * @retval      FSP_SUCCESS                         No parameter error found
 * @retval      FSP_ERR_INVALID_TIMING_SETTING      Invalid timing parameter.
 **********************************************************************************************************************/
static fsp_err_t r_lcdc_open_param_check_display_cycle (display_cfg_t const * const p_cfg)
{
    static uint32_t h_active;
    static uint32_t v_active;

    h_active = (p_cfg->output.htiming.display_cyc);
    v_active = p_cfg->output.vtiming.display_cyc;

    FSP_ERROR_RETURN((h_active <= TIMING_MAX_H), FSP_ERR_INVALID_TIMING_SETTING);
    FSP_ERROR_RETURN((v_active <= TIMING_MAX_V), FSP_ERR_INVALID_TIMING_SETTING);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * The parameter checking for layer setting.
 *
 * @param[in]   p_cfg   Pointer to the configuration structure for display interface
 * @retval      FSP_SUCCESS                         No parameter error found
 * @retval      FSP_ERR_INVALID_LAYER_SETTING       Invalid layer parameter
 **********************************************************************************************************************/
static fsp_err_t r_lcdc_open_param_check_layer_setting (display_cfg_t const * const p_cfg)
{
    uint32_t layer_num;
    for (layer_num = 0; layer_num <= DISPLAY_FRAME_LAYER_2; layer_num++)
    {
        if (p_cfg->input[layer_num].p_base)
        {
            FSP_ERROR_RETURN((p_cfg->input[layer_num].hsize <= LAYER_MAX_HSIZE), FSP_ERR_INVALID_LAYER_SETTING);
            FSP_ERROR_RETURN((p_cfg->input[layer_num].vsize <= LAYER_MAX_VSIZE), FSP_ERR_INVALID_LAYER_SETTING);
            FSP_ERROR_RETURN((p_cfg->input[layer_num].coordinate_x <= LAYER_MAX_HCOOR), FSP_ERR_INVALID_LAYER_SETTING);
            FSP_ERROR_RETURN((p_cfg->input[layer_num].coordinate_y <= LAYER_MAX_VCOOR), FSP_ERR_INVALID_LAYER_SETTING);
        }
        else
        {
            /* Do Nothing */
        }
    }

    return FSP_SUCCESS;
}

#endif
