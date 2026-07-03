/*
 * Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_usb_host.h"
#include "r_usb_host_define.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define USBH_OPEN    (0x55534248)      /* USBH in ASCII */

/* USB util */
#define USB_SETBIT(n)      (1UL << (n))
#define USB_MIN(_x, _y)    (((_x) < (_y)) ? (_x) : (_y))
#define USB_MAX(_x, _y)    (((_x) > (_y)) ? (_x) : (_y))

#if defined(__GNUC__)
 #define CTZ(x)            (__builtin_ctz(x))
#else
 #error "Compiler not supported"
#endif

/* USB common value */
#define USB_EP_COUNT_MAX              (15U)
#define USB_DIR_COUNT_MAX             (2U)
#define USB_PIPE_COUNT_MAX            (10U)
#define USB_DEVICE_COUNT_MAX          (5U)
#define USB_HS_DEVADD_NUM_MAX         (10U)
#define USB_FS_DEVADD_NUM_MAX         (5U)
#define USB_PIPETR_INDEX_BEGIN        (1U)
#define USB_PIPETR_INDEX_END          (5U)

/* USB Bus status value*/
#define USB_STATUS_ATTACH             (1 << 0)
#define USB_STATUS_DETACH             (1 << 1)
#define USB_STATUS_EOFERR             (1 << 2)
#define USB_STATUS_OVRCR              (1 << 3)

/* USB DCPMAXP default value */
#define USB_DCPMAXP_DEVSEL_DEFAULT    (0U)     /* Device address default 0 */
#define USB_DCPMAXP_MXPS_DEFAULT      (0x40UL) /* Max packet size default is 64*/

/* INTSTS1 Clean mask */
#define USB_HS_INTSTS1_CLEAN_MASK     (0xDB71UL)
#define USB_FS_INTSTS1_CLEAN_MASK     (0xD870UL)

/* PHYSET REPSEL value */
#define USB_PHYSET_REPSEL_NONE        (0U) /* No cycle is set */
#define USB_PHYSET_REPSEL_16_SEC      (1U) /* Adjust terminating resistance at 16s */
#define USB_PHYSET_REPSEL_64_SEC      (2U) /* Adjust terminating resistance at 64s */
#define USB_PHYSET_REPSEL_128_SEC     (3U) /* Adjust terminating resistance at 128s */

/* PIPECFG TYPE value */
#define USB_PIPECFG_TYPE_BULK         (1U)
#define USB_PIPECFG_TYPE_INT          (2U)
#define USB_PIPECFG_TYPE_ISO          (3U)

/* PIPECTR PID value */
#define USB_PIPE_CTR_PID_NAK          (0U)
#define USB_PIPE_CTR_PID_BUF          (1U)
#define USB_PIPE_CTR_PID_STALL        (2U)
#define USB_PIPE_CTR_PID_STALL2       (3U)

/* PIPEMAXP MXPS value */
#define USB_HS_PIPEMAXP_MXPS_MASK     (0x7ffUL)
#define USB_FS_PIPEMAXP_MXPS_MASK     (0xffUL)

/* DVSTCTR0 RHST value */
#define USB_DVSTCTR0_RHST_LS          (1U) /* Low-speed connection */
#define USB_DVSTCTR0_RHST_FS          (2U) /* Full-speed connection */
#define USB_DVSTCTR0_RHST_HS          (3U) /* Full-speed connection */

/* DEVADD USBSPD value */
#define USB_DEVADD_USBSPD_NOT_USE     (0U) /* Do not use DEVADDn */
#define USB_DEVADD_USBSPD_LS          (1U) /* Target Device Low-speed */
#define USB_DEVADD_USBSPD_FS          (2U) /* Target Device Full-speed */
#define USB_DEVADD_USBSPD_HS          (3U) /* Target Device Full-speed */

/* FIFOSEL value */
#define USB_FIFOSEL_MBW_8_BIT         (0)  /* FIFO Port Access 8-bit width */
#define USB_FIFOSEL_MBW_16_BIT        (1)  /* FIFO Port Access 16-bit width */
#define USB_FIFOSEL_MBW_32_BIT        (2)  /* FIFO Port Access 32-bit width */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef __PACKED_STRUCT
{
    union
    {
        struct
        {
            uint16_t       : 8;
            uint16_t TRCLR : 1;
            uint16_t TRENB : 1;
            uint16_t       : 0;
        };

        uint16_t TRE;
    };

    uint16_t TRN;
} usb_reg_pipetre_t;

typedef __PACKED_STRUCT st_pipe_state
{
    void   * buf;                      /* the start address of a transfer data buffer */
    uint16_t length;                   /* the number of bytes in the buffer */
    uint16_t remaining;                /* the number of bytes remaining in the buffer */
    struct
    {
        uint32_t ep  : 8;              /* an assigned endpoint address */
        uint32_t dev : 8;              /* an assigned device address */
        uint32_t ff  : 1;              /* `buf` is USB_FUFO or POD */
        uint32_t     : 0;
    };
} pipe_state_t;

typedef struct st_uhc_data
{
    pipe_state_t pipe[USB_PIPE_COUNT_MAX];
    uint8_t      ep[USB_DEVICE_COUNT_MAX][USB_DIR_COUNT_MAX][USB_EP_COUNT_MAX];
    uint8_t      ctl_mps[USB_DEVICE_COUNT_MAX]; /* EP0 max packet size for each device */
} uhc_data_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/* Build an endpoint address (number + direction bit) from a number and direction. */
static inline uint8_t r_usbh_edpt_addr (uint8_t num, uint8_t dir)
{
    return (uint8_t) (num | (dir ? USB_DIR_IN_MASK : 0));
}

/* Extract the endpoint number (without the direction bit) from an endpoint address. */
static inline uint8_t r_usbh_edpt_number (uint8_t addr)
{
    return (uint8_t) (addr & (~USB_DIR_IN_MASK));
}

/* Extract the transfer direction (IN/OUT) from an endpoint address. */
static inline usb_dir_t r_usbh_edpt_dir (uint8_t addr)
{
    return (addr & USB_DIR_IN_MASK) ? USB_DIR_IN : USB_DIR_OUT;
}

/* Return the max packet size (in bytes) encoded in an endpoint descriptor. */
static inline uint16_t r_usbh_edpt_packet_size (usb_desc_endpoint_t const * desc_ep)
{
    return (desc_ep->wMaxPacketSize) & 0x7FF;
}

/* Set the FIFO access width (MBW: 8/16/32-bit) for the FIFO that @p p_fifo points at. */
static void fifo_set_mbw (volatile void * p_fifo, uint32_t mbw, uint8_t num)
{
    volatile uint16_t * p_fifosel;
    volatile uint16_t * p_fifoctr;

    switch ((uintptr_t) p_fifo)
    {
#ifdef USB_HIGH_SPEED_MODULE
        case ((uintptr_t) &R_USB_HS0->CFIFO):
        {
            p_fifosel = &R_USB_HS0->CFIFOSEL;
            p_fifoctr = &R_USB_HS0->CFIFOCTR;
            break;
        }

        case ((uintptr_t) &R_USB_HS0->D0FIFO):
        {
            p_fifosel = &R_USB_HS0->D0FIFOSEL;
            p_fifoctr = &R_USB_HS0->D0FIFOCTR;
            break;
        }

        case ((uintptr_t) &R_USB_HS0->D1FIFO):
        {
            p_fifosel = &R_USB_HS0->D1FIFOSEL;
            p_fifoctr = &R_USB_HS0->D1FIFOCTR;
            break;
        }
#endif /* USB_HIGH_SPEED_MODULE */
        case ((uintptr_t) &R_USB_FS0->CFIFO):
        {
            p_fifosel = &R_USB_FS0->CFIFOSEL;
            p_fifoctr = &R_USB_FS0->CFIFOCTR;
            break;
        }

        case ((uintptr_t) &R_USB_FS0->D0FIFO):
        {
            p_fifosel = &R_USB_FS0->D0FIFOSEL;
            p_fifoctr = &R_USB_FS0->D0FIFOCTR;
            break;
        }

        case ((uintptr_t) &R_USB_FS0->D1FIFO):
        {
            p_fifosel = &R_USB_FS0->D1FIFOSEL;
            p_fifoctr = &R_USB_FS0->D1FIFOCTR;
            break;
        }

        default:
        {
            return;
        }
    }

    /* Read current MBW setting */
    uint16_t current_mbw = (*p_fifosel & R_USB_CFIFOSEL_MBW_Msk) >> R_USB_CFIFOSEL_MBW_Pos;

    /* If MBW is already set correctly, no need to change */
    if (current_mbw == mbw)
    {
        return;
    }

    /* Step 1: Clear CURPIPE to release FIFO (only for DxFIFO) */
    if ((p_fifo != (volatile void *) &R_USB_FS0->CFIFO)
#ifdef USB_HIGH_SPEED_MODULE
        && (p_fifo != (volatile void *) &R_USB_HS0->CFIFO)
#endif
        )
    {
        uint16_t reg_val = *p_fifosel;
        reg_val   &= ~R_USB_CFIFOSEL_CURPIPE_Msk;
        *p_fifosel = reg_val;

        /* Step 2: Wait for CURPIPE to be cleared */
        FSP_HARDWARE_REGISTER_WAIT((*p_fifosel & R_USB_CFIFOSEL_CURPIPE_Msk), 0);
    }

    /* Step 3: Set new MBW value */
    uint16_t reg_val = *p_fifosel;
    reg_val   &= ~R_USB_CFIFOSEL_MBW_Msk;
    reg_val   |= (mbw << R_USB_CFIFOSEL_MBW_Pos);
    *p_fifosel = reg_val;

    /* Step 4: Wait for MBW to take effect - verify the register value */
    FSP_HARDWARE_REGISTER_WAIT((*p_fifosel & R_USB_CFIFOSEL_MBW_Msk) >> R_USB_CFIFOSEL_MBW_Pos, mbw);

    /* Step 5: Additional NOP delay for hardware data arrangement reconfiguration */
    for (volatile int i = 0; i < 10; i++)
    {
        __asm volatile ("nop");
    }

    /* Step 6: Restore CURPIPE if needed (only for DxFIFO) */
    if ((p_fifo != (volatile void *) &R_USB_FS0->CFIFO)
#ifdef USB_HIGH_SPEED_MODULE
        && (p_fifo != (volatile void *) &R_USB_HS0->CFIFO)
#endif
        )
    {
        if (num != 0)
        {
            reg_val    = *p_fifosel;
            reg_val   &= ~R_USB_CFIFOSEL_CURPIPE_Msk;
            reg_val   |= (num & R_USB_CFIFOSEL_CURPIPE_Msk);
            *p_fifosel = reg_val;

            /* Wait for CURPIPE to be set */
            FSP_HARDWARE_REGISTER_WAIT((*p_fifosel & R_USB_CFIFOSEL_CURPIPE_Msk), (num & R_USB_CFIFOSEL_CURPIPE_Msk));

            /* Wait for FIFO ready */
            FSP_HARDWARE_REGISTER_WAIT((*p_fifoctr & R_USB_CFIFOCTR_FRDY_Msk), R_USB_CFIFOCTR_FRDY_Msk);
        }
    }
}

static volatile uint16_t * r_usbh_get_pipectr(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static uint32_t            r_usbh_find_pipe(usbh_instance_ctrl_t * const p_ctrl, uint8_t xfer_type);
static fsp_err_t           r_usbh_hw_module_start(usbh_instance_ctrl_t * const p_ctrl);
static void                r_usbh_hw_init(usbh_instance_ctrl_t * const p_ctrl);
static fsp_err_t           r_usbh_module_register_clear(usbh_instance_ctrl_t * const p_ctrl);
static fsp_err_t           r_usbh_hw_module_stop(usbh_instance_ctrl_t * const p_ctrl);
static uint16_t            r_usbh_chk_dev_addr(usbh_instance_ctrl_t * p_ctrl, uint16_t addr);
static void                r_usbh_device_release(usbh_instance_ctrl_t * p_ctrl, uint8_t dev_addr);
static bool                r_usbh_process_edpt_xfer(usbh_instance_ctrl_t * const p_ctrl,
                                                    uint8_t                      dev_addr,
                                                    uint8_t                      ep_addr,
                                                    void                       * buffer,
                                                    uint16_t                     buflen);
static bool r_usbh_process_pipe_xfer(usbh_instance_ctrl_t * const p_ctrl,
                                     uint8_t                      dev_addr,
                                     uint8_t                      ep_addr,
                                     void                       * buffer,
                                     uint16_t                     buflen);
static bool r_usbh_process_pipe0_xfer(usbh_instance_ctrl_t * const p_ctrl,
                                      uint8_t                      dev_addr,
                                      uint8_t                      ep_addr,
                                      void                       * buffer,
                                      uint16_t                     buflen);
static bool r_usbh_pipe_xfer_out(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static bool r_usbh_pipe0_xfer_out(usbh_instance_ctrl_t * const p_ctrl);
static bool r_usbh_pipe_xfer_in(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static bool r_usbh_pipe0_xfer_in(usbh_instance_ctrl_t * const p_ctrl);
static void r_usbh_pipe_write_packet(usbh_instance_ctrl_t * const p_ctrl,
                                     void                       * p_buf,
                                     volatile void              * p_fifo,
                                     uint32_t                     len,
                                     uint32_t                     access_bytes,
                                     uint8_t                      num);
static void r_usbh_pipe_read_packet(usbh_instance_ctrl_t * const p_ctrl,
                                    void                       * p_buf,
                                    volatile void              * p_fifo,
                                    uint32_t                     len,
                                    uint32_t                     access_bytes,
                                    uint8_t                      num);
static uint16_t    r_usbh_edpt_max_packet_size(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static uint16_t    r_usbh_edpt0_max_packet_size(usbh_instance_ctrl_t * const p_ctrl);
static inline void r_usbh_interrupt_configure(usbh_instance_ctrl_t * p_ctrl);
static inline void r_usbh_interrupt_enable(usbh_instance_ctrl_t * p_ctrl);
static inline void r_usbh_interrupt_disable(usbh_instance_ctrl_t * p_ctrl);
static void        r_usbh_process_terminate_control_xfer(usbh_instance_ctrl_t * const p_ctrl);
static void        r_usbh_process_terminate_xfer(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
uhc_data_t g_uhc_data[USB_NUM_USBIP];

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/**
 * @brief Start the USB module, select the host operating mode and configure the default control pipe.
 *
 * Powers on the selected USB IP, performs the host-mode hardware initialization, configures and enables
 * the USB interrupts and clears the per-module host bookkeeping. The control block keeps a pointer to
 * @p p_cfg, so the configuration must remain valid for the lifetime of the instance.
 *
 * @param[in,out] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 * @param[in]     p_cfg         Pointer to the USB host configuration (::usb_cfg_t).
 *
 * @retval FSP_SUCCESS                    Module started successfully.
 * @retval FSP_ERR_ASSERTION             @p p_api_ctrl or @p p_cfg was NULL.
 * @retval FSP_ERR_ALREADY_OPEN          The control block has already been opened.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT The requested module number does not exist on this MCU.
 * @retval FSP_ERR_USB_BUSY              The USB module clock is already in use.
 */
fsp_err_t R_USBH_Open (usb_ctrl_t * const p_api_ctrl, usb_cfg_t const * const p_cfg)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ASSERT(p_cfg)
    FSP_ERROR_RETURN(0 == p_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Make sure this channel exists. */
    FSP_ERROR_RETURN(USB_NUM_USBIP > p_cfg->module_number, FSP_ERR_IP_CHANNEL_NOT_PRESENT);
#endif

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_cfg->module_number))
    {
        p_ctrl->p_reg     = (void *) R_USB_HS0_BASE;
        p_ctrl->max_speed = USB_SPEED_HS;
    }
    else
#endif
    {
        p_ctrl->p_reg     = (void *) R_USB_FS0_BASE;
        p_ctrl->max_speed = USB_SPEED_FS;
    }

    p_ctrl->module_number = p_cfg->module_number;

    p_ctrl->p_cfg             = p_cfg;
    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

    /* Start module */
    r_usbh_hw_module_start(p_ctrl);

    /* Initialize usb host hardware layer */
    r_usbh_hw_init(p_ctrl);

    /* Setting interrupt */
    r_usbh_interrupt_configure(p_ctrl);

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_BSP_IrqCfgEnable(p_ctrl->p_cfg->hs_irq, p_ctrl->p_cfg->hsipl, p_ctrl);
    }
    else
#endif
    {
        R_BSP_IrqCfgEnable(p_ctrl->p_cfg->irq, p_ctrl->p_cfg->ipl, p_ctrl);
        R_BSP_IrqCfgEnable(p_ctrl->p_cfg->irq_r, p_ctrl->p_cfg->ipl_r, p_ctrl);
    }

    memset(&g_uhc_data[p_ctrl->module_number], 0, sizeof(uhc_data_t));

    p_ctrl->open = USBH_OPEN;

    return FSP_SUCCESS;
}

/**
 * @brief Read the root-port/bus status flags.
 *
 * Samples the INTSTS1 register and maps the hardware bits to the driver status flags
 * (USB_STATUS_OVRCR, USB_STATUS_EOFERR, attach and USB_STATUS_DETACH).
 *
 * @param[in]  p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 * @param[out] p_status      Destination for the decoded status flags (::usb_status_t).
 *
 * @retval FSP_SUCCESS          Status read successfully.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl or @p p_status was NULL.
 * @retval FSP_ERR_NOT_OPEN     The driver has not been opened.
 */
fsp_err_t R_USBH_PortStatusGet (usb_ctrl_t * const p_api_ctrl, usb_status_t * p_status)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    uint16_t               status;

#if !defined(USB_HIGH_SPEED_MODULE) && !USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ASSERT(p_status)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        status = R_USB_HS0->INTSTS1;
    }
    else
#endif
    {
        status = R_USB_FS0->INTSTS1;
    }

    *p_status = 0;

    if (status & R_USB_INTSTS1_OVRCR_Msk)
    {
        *p_status |= USB_STATUS_OVRCR;
    }

    if (status & R_USB_INTSTS1_EOFERR_Msk)
    {
        *p_status |= USB_STATUS_EOFERR;
    }

    if (status & R_USB_INTSTS1_ATTCH_Msk)
    {
        *p_status |= R_USB_INTSTS1_ATTCH_Msk;
    }

    if (status & (R_USB_INTSTS1_DTCH_Msk | R_USB_INTSTS1_SACK_Msk))
    {
        *p_status |= USB_STATUS_DETACH;
    }

    return FSP_SUCCESS;
}

/**
 * @brief Drive a USB bus reset on the root port.
 *
 * Sets the default control pipe to NAK, asserts the bus reset signal for ~20 ms, then de-asserts it and
 * re-enables the bus (UACT). Module interrupts are briefly disabled while the bus configuration changes.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 *
 * @retval FSP_SUCCESS          Bus reset completed.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN     The driver has not been opened.
 */
fsp_err_t R_USBH_PortReset (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    volatile uint16_t * p_reg_dcpctr;
    volatile uint16_t * p_reg_dvstctr0;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_dcpctr   = &R_USB_HS0->DCPCTR;
        p_reg_dvstctr0 = &R_USB_HS0->DVSTCTR0;
    }
    else
#endif
    {
        p_reg_dcpctr   = &R_USB_FS0->DCPCTR;
        p_reg_dvstctr0 = &R_USB_FS0->DVSTCTR0;
    }

    *p_reg_dcpctr = USB_PIPE_CTR_PID_NAK << R_USB_PIPE_CTR_PID_Pos;
    FSP_HARDWARE_REGISTER_WAIT((*p_reg_dcpctr & R_USB_DCPCTR_PBUSY_Msk), 0);

    /* Disable the USB module interrupt before changing the USB bus configuration */
    r_usbh_interrupt_disable(p_ctrl);

    /* Enable high-speed operation */
    /* TODO: it should be only enable by checking CHIRP signal after reset */
    R_USB_HS0->SYSCFG |= R_USB_SYSCFG_HSE_Msk;

    /* Disable the USB Bus by clearing the UACT bit */
    *p_reg_dvstctr0 &= ~R_USB_DVSTCTR0_UACT_Msk;

    /* Disable transmit setup packet by clearing the SUREQ bit */
    if (*p_reg_dcpctr & R_USB_DCPCTR_SUREQ_Msk)
    {
        *p_reg_dcpctr |= R_USB_DCPCTR_SUREQCLR_Msk;
    }

    r_usbh_interrupt_enable(p_ctrl);

    /* Assert USB bus reset signal */
    *p_reg_dvstctr0 |= R_USB_DVSTCTR0_USBRST_Msk;
    R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);

    /* Deassert USB bus reset signal */
    *p_reg_dvstctr0 &= ~R_USB_DVSTCTR0_USBRST_Msk;

    /* Enable the USB bus for host controller operation */
    *p_reg_dvstctr0 |= R_USB_DVSTCTR0_UACT_Msk;

    return FSP_SUCCESS;
}

/**
 * @brief Get the speed of the device connected to the root port.
 *
 * Reads the RHST field of DVSTCTR0 and translates it to ::usb_speed_t. If no valid speed can be
 * determined (or HS is reported on a module that does not support it) ::USB_SPEED_INVALID is returned.
 *
 * @param[in]  p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 * @param[out] p_speed       Destination for the detected device speed (::usb_speed_t).
 *
 * @retval FSP_SUCCESS          Speed read successfully.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl or @p p_speed was NULL.
 * @retval FSP_ERR_NOT_OPEN     The driver has not been opened.
 */
fsp_err_t R_USBH_GetDeviceSpeed (usb_ctrl_t * const p_api_ctrl, usb_speed_t * p_speed)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    uint16_t               rhst;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ASSERT(p_speed)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        rhst = (R_USB_HS0->DVSTCTR0 & R_USB_DVSTCTR0_RHST_Msk) >> R_USB_DVSTCTR0_RHST_Pos;
    }
    else
#endif
    {
        rhst = (R_USB_FS0->DVSTCTR0 & R_USB_DVSTCTR0_RHST_Msk) >> R_USB_DVSTCTR0_RHST_Pos;
    }

    switch (rhst)
    {
        case USB_DVSTCTR0_RHST_LS:
        {
            *p_speed = USB_SPEED_LS;
            break;
        }

        case USB_DVSTCTR0_RHST_FS:
        {
            *p_speed = USB_SPEED_FS;
            break;
        }

#ifdef USB_HIGH_SPEED_MODULE
        case USB_DVSTCTR0_RHST_HS:
        {
            *p_speed = USB_IS_USBHS(p_ctrl->module_number) ?
                       USB_SPEED_HS :
                       USB_SPEED_INVALID;
            break;
        }
#endif
        default:
        {
            *p_speed = USB_SPEED_INVALID;
        }
    }

    return FSP_SUCCESS;
}

/**
 * @brief Release a device address and free all of its pipes.
 *
 * If @p dev_addr is currently registered, every pipe bound to it is closed, its endpoint map and control
 * max-packet-size entry are cleared and the device address slot is released. Call this when a device is
 * detached or its address is to be reused.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 * @param[in] dev_addr      Device address to release (1..USB_DEVICE_COUNT_MAX-1).
 *
 * @retval FSP_SUCCESS              Device released.
 * @retval FSP_ERR_ASSERTION       @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN        The driver has not been opened.
 * @retval FSP_ERR_INVALID_ARGUMENT @p dev_addr is out of range.
 * @retval FSP_ERR_ABORTED         @p dev_addr is not currently registered.
 */
fsp_err_t R_USBH_DeviceRelease (usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(USB_DEVICE_COUNT_MAX > dev_addr, FSP_ERR_INVALID_ARGUMENT);
#endif

    if (0 != r_usbh_chk_dev_addr(p_ctrl, dev_addr))
    {
        r_usbh_device_release(p_ctrl, dev_addr);

        return FSP_SUCCESS;
    }

    return FSP_ERR_ABORTED;
}

/**
 * @brief Send an 8-byte SETUP packet on the default control pipe.
 *
 * Programs the device address and control max packet size, sets the data-stage direction from the
 * bmRequestType byte, loads the setup packet into the USBREQ/USBVAL/USBINDX/USBLENG registers and issues
 * the setup request (SUREQ). Completion of the setup stage is reported through the user callback.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 * @param[in] dev_addr      Target device address (0..USB_DEVICE_COUNT_MAX-1).
 * @param[in] setup_packet  8-byte USB SETUP packet to transmit.
 *
 * @retval FSP_SUCCESS              Setup request issued.
 * @retval FSP_ERR_ASSERTION       @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN        The driver has not been opened.
 * @retval FSP_ERR_INVALID_ARGUMENT @p dev_addr is out of range.
 * @retval FSP_ERR_USB_FAILED      A previous setup request is still in progress.
 */
fsp_err_t R_USBH_SetupSend (usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr, uint8_t const setup_packet[8])
{
    usbh_instance_ctrl_t * p_ctrl        = (usbh_instance_ctrl_t *) p_api_ctrl;
    uint8_t const          bmRequesttype = setup_packet[0];
    uint16_t const       * p_packet      = (uint16_t const *) (uintptr_t) &setup_packet[0];

    volatile uint16_t * p_reg_dcpcfg;
    volatile uint16_t * p_reg_dcpctr;
    volatile uint16_t * p_reg_dcpmaxp;
    volatile uint16_t * p_reg_usbreq;
    volatile uint16_t * p_reg_usbval;
    volatile uint16_t * p_reg_usbindx;
    volatile uint16_t * p_reg_usbleng;
    volatile uint16_t * p_reg_intsts1;
    volatile uint16_t * p_reg_intenb1;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(USB_DEVICE_COUNT_MAX > dev_addr, FSP_ERR_INVALID_ARGUMENT);
#endif

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_dcpcfg  = &R_USB_HS0->DCPCFG;
        p_reg_dcpctr  = &R_USB_HS0->DCPCTR;
        p_reg_dcpmaxp = &R_USB_HS0->DCPMAXP;
        p_reg_usbreq  = &R_USB_HS0->USBREQ;
        p_reg_usbval  = &R_USB_HS0->USBVAL;
        p_reg_usbindx = &R_USB_HS0->USBINDX;
        p_reg_usbleng = &R_USB_HS0->USBLENG;
        p_reg_intsts1 = &R_USB_HS0->INTSTS1;
        p_reg_intenb1 = &R_USB_HS0->INTENB1;
    }
    else
#endif
    {
        p_reg_dcpcfg  = &R_USB_FS0->DCPCFG;
        p_reg_dcpctr  = &R_USB_FS0->DCPCTR;
        p_reg_dcpmaxp = &R_USB_FS0->DCPMAXP;
        p_reg_usbreq  = &R_USB_FS0->USBREQ;
        p_reg_usbval  = &R_USB_FS0->USBVAL;
        p_reg_usbindx = &R_USB_FS0->USBINDX;
        p_reg_usbleng = &R_USB_FS0->USBLENG;
        p_reg_intsts1 = &R_USB_FS0->INTSTS1;
        p_reg_intenb1 = &R_USB_FS0->INTENB1;
    }

    FSP_ERROR_RETURN(0 == (*p_reg_dcpctr & R_USB_DCPCTR_SUREQ_Msk), FSP_ERR_USB_FAILED);
    *p_reg_dcpctr = USB_PIPE_CTR_PID_NAK << R_USB_PIPE_CTR_PID_Pos;

    g_uhc_data[p_ctrl->module_number].pipe[0].buf       = NULL;
    g_uhc_data[p_ctrl->module_number].pipe[0].length    = 8;
    g_uhc_data[p_ctrl->module_number].pipe[0].remaining = 0;
    g_uhc_data[p_ctrl->module_number].pipe[0].dev       = dev_addr;

    FSP_HARDWARE_REGISTER_WAIT((*p_reg_dcpctr & R_USB_DCPCTR_PBUSY_Msk), 0);

    *p_reg_dcpmaxp = ((dev_addr << R_USB_DCPMAXP_DEVSEL_Pos) & R_USB_DCPMAXP_DEVSEL_Msk) |
                     (g_uhc_data[p_ctrl->module_number].ctl_mps[dev_addr] & R_USB_DCPMAXP_MXPS_Msk);

    /* Set direction in advance for DATA stage */
    *p_reg_dcpcfg = r_usbh_edpt_dir(bmRequesttype) ?
                    (*p_reg_dcpcfg & ~R_USB_DCPCFG_DIR_Msk) :
                    (*p_reg_dcpcfg | R_USB_DCPCFG_DIR_Msk);

    *p_reg_usbreq  = p_packet[0];
    *p_reg_usbval  = p_packet[1];
    *p_reg_usbindx = p_packet[2];
    *p_reg_usbleng = p_packet[3];

    *p_reg_intsts1 &= ~(R_USB_INTSTS1_SIGN_Msk | R_USB_INTSTS1_SACK_Msk);
    *p_reg_intenb1 |= (R_USB_INTENB1_SIGNE_Msk | R_USB_INTENB1_SACKE_Msk);
    *p_reg_dcpctr  |= R_USB_DCPCTR_SUREQ_Msk;

    return FSP_SUCCESS;
}

/**
 * @brief Open an endpoint and bind it to a hardware pipe.
 *
 * Allocates a free pipe suitable for the transfer type described by @p p_ep_desc (bulk, interrupt or
 * isochronous), configures its direction, endpoint number, max packet size and (for periodic endpoints)
 * polling interval, and enables its interrupts. The pipe is recorded in the device's endpoint map for
 * later transfers. High-bandwidth isochronous endpoints are not supported.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 * @param[in] dev_addr      Device address that owns the endpoint (1..USB_DEVICE_COUNT_MAX-1).
 * @param[in] p_ep_desc     Standard USB endpoint descriptor for the endpoint to open.
 *
 * @retval FSP_SUCCESS              Endpoint opened.
 * @retval FSP_ERR_ASSERTION       @p p_api_ctrl or @p p_ep_desc was NULL.
 * @retval FSP_ERR_NOT_OPEN        The driver has not been opened.
 * @retval FSP_ERR_INVALID_ARGUMENT @p dev_addr is out of range, or the descriptor requests an
 *                                  unsupported (e.g. high-bandwidth) isochronous configuration.
 * @retval FSP_ERR_USB_BUSY        No free pipe is available for this transfer type.
 */

#define R_USB_PIPEBUF_FIXED    (0x7C08) /* Fixed Pipe Buffer configurations */

fsp_err_t R_USBH_EdptOpen (usb_ctrl_t * const          p_api_ctrl,
                           uint8_t                     dev_addr,
                           usb_desc_endpoint_t const * p_ep_desc,
                           uint8_t                   * pipe_num)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ASSERT(p_ep_desc)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(USB_DEVICE_COUNT_MAX > dev_addr, FSP_ERR_INVALID_ARGUMENT);
#endif

    volatile uint16_t * p_reg_brdyenb;
    volatile uint16_t * p_reg_nrdyenb;
    volatile uint16_t * p_reg_bempenb;
    volatile uint16_t * p_reg_brdysts;
    volatile uint16_t * p_reg_pipesel;
    volatile uint16_t * p_reg_pipemaxp;
    volatile uint16_t * p_reg_pipecfg;
    volatile uint16_t * p_reg_pipeperi;

    const uint8_t  ep_addr  = p_ep_desc->bEndpointAddress;
    const uint8_t  epn      = r_usbh_edpt_number(ep_addr);
    const uint32_t mps      = r_usbh_edpt_packet_size(p_ep_desc);
    const uint8_t  dir      = r_usbh_edpt_dir(ep_addr);
    const uint8_t  xfer     = p_ep_desc->bmAttributes.xfer;
    const uint8_t  interval = p_ep_desc->bInterval;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_brdyenb  = &R_USB_HS0->BRDYENB;
        p_reg_nrdyenb  = &R_USB_HS0->NRDYENB;
        p_reg_bempenb  = &R_USB_HS0->BEMPENB;
        p_reg_brdysts  = &R_USB_HS0->BRDYSTS;
        p_reg_pipesel  = &R_USB_HS0->PIPESEL;
        p_reg_pipemaxp = &R_USB_HS0->PIPEMAXP;
        p_reg_pipecfg  = &R_USB_HS0->PIPECFG;
        p_reg_pipeperi = &R_USB_HS0->PIPEPERI;
    }
    else
#endif
    {
        p_reg_brdyenb  = &R_USB_FS0->BRDYENB;
        p_reg_nrdyenb  = &R_USB_FS0->NRDYENB;
        p_reg_bempenb  = &R_USB_FS0->BEMPENB;
        p_reg_brdysts  = &R_USB_FS0->BRDYSTS;
        p_reg_pipesel  = &R_USB_FS0->PIPESEL;
        p_reg_pipemaxp = &R_USB_FS0->PIPEMAXP;
        p_reg_pipecfg  = &R_USB_FS0->PIPECFG;
        p_reg_pipeperi = &R_USB_FS0->PIPEPERI;
    }

    if (xfer == USB_XFER_ISOCHRONOUS)
    {
        /* High-bandwidth isochronous endpoints is not supported */
        FSP_ERROR_RETURN((p_ep_desc->wMaxPacketSize & 0x1800) == 0x0, FSP_ERR_INVALID_ARGUMENT);

#ifdef USB_HIGH_SPEED_MODULE
        if (USB_IS_USBHS(p_ctrl->module_number))
        {
            FSP_ERROR_RETURN(mps <= 1024, FSP_ERR_INVALID_ARGUMENT);
        }
        else
#endif
        {
            FSP_ERROR_RETURN(mps <= 256, FSP_ERR_INVALID_ARGUMENT);
        }
    }

    /* Find a valid pipe */
    const uint32_t num = r_usbh_find_pipe(p_ctrl, xfer);

    /* There are no available pipes that can be configured for this endpoint. */
    FSP_ERROR_RETURN(0 != num, FSP_ERR_USB_BUSY);

    g_uhc_data[p_ctrl->module_number].pipe[num].dev = dev_addr;
    g_uhc_data[p_ctrl->module_number].pipe[num].ep  = ep_addr;
    g_uhc_data[p_ctrl->module_number].ep[dev_addr - 1][dir][epn - 1] = num;

    uint16_t pipe_cfg = ((1 ^ dir) << 4) | epn;
    if (xfer == USB_XFER_BULK)
    {
        pipe_cfg |= (USB_PIPECFG_TYPE_BULK << R_USB_PIPECFG_TYPE_Pos) |
                    R_USB_PIPECFG_SHTNAK_Msk |
                    R_USB_PIPECFG_DBLB_Msk;
    }
    else if (xfer == USB_XFER_INTERRUPT)
    {
        pipe_cfg |= (USB_PIPECFG_TYPE_INT << R_USB_PIPECFG_TYPE_Pos);
    }
    else
    {
        pipe_cfg |= (USB_PIPECFG_TYPE_ISO << R_USB_PIPECFG_TYPE_Pos) |
                    R_USB_PIPECFG_DBLB_Msk;
    }

    volatile uint16_t * p_reg_pipectr = r_usbh_get_pipectr(p_ctrl, num);

    /* PIPE interrupt disable */
    *p_reg_brdyenb &= ~USB_SETBIT(num);
    *p_reg_nrdyenb &= ~USB_SETBIT(num);
    *p_reg_bempenb &= ~USB_SETBIT(num);

    /* Set NAK */
    *p_reg_pipectr = USB_PIPE_CTR_PID_NAK << R_USB_PIPE_CTR_PID_Pos;

    /* Wait until the pipe not in use for the transaction */
    for (uint16_t i = 0; i < UINT16_MAX; ++i)
    {
        if (0 == (*p_reg_pipectr & R_USB_PIPE_CTR_PBUSY_Msk))
        {
            break;
        }
    }

    *p_reg_pipesel  = num;
    *p_reg_pipemaxp = (dev_addr << R_USB_PIPEMAXP_DEVSEL_Pos) | (mps);
    *p_reg_pipecfg  = pipe_cfg;

    /* PIPE Configuration */
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        if (dir == USB_DIR_IN)
        {
            R_USB_HS0->PIPEBUF = (0x1F << R_USB_HS0_PIPEBUF_BUFSIZE_Pos) | (0x04);
        }
        else
        {
            R_USB_HS0->PIPEBUF = (0x1F << R_USB_HS0_PIPEBUF_BUFSIZE_Pos) | (0x44);
        }
    }
#endif

    if ((xfer == USB_XFER_INTERRUPT) || (xfer == USB_XFER_ISOCHRONOUS))
    {
        *p_reg_pipeperi = (interval << R_USB_PIPEPERI_IITV_Pos);
    }

    *p_reg_brdysts = R_USB_BRDYSTS_PIPEBRDY_Msk ^ USB_SETBIT(num);
    *p_reg_pipectr = R_USB_PIPE_CTR_ACLRM_Msk | R_USB_PIPE_CTR_SQCLR_Msk;
    *p_reg_pipectr = (USB_DIR_OUT == dir) ?
                     (USB_PIPE_CTR_PID_BUF << R_USB_PIPE_CTR_PID_Pos) :
                     (USB_PIPE_CTR_PID_NAK << R_USB_PIPE_CTR_PID_Pos);

    /* PIPE interrupt enable */
    *p_reg_brdyenb |= USB_SETBIT(num);
    *p_reg_nrdyenb |= USB_SETBIT(num);
    *p_reg_bempenb |= USB_SETBIT(num);

    /* Return configured pipe */
    *pipe_num = num;

    return FSP_SUCCESS;
}

/**
 * @brief Register a device address and bind it to the default control pipe.
 *
 * Programs the device's address, control-endpoint max packet size and bus speed into the controller so
 * that control transfers can be addressed to it. On the high-speed module a Full-/Low-speed device located
 * behind a high-speed hub is additionally configured for split transactions using @p hub_addr / @p hub_port.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 * @param[in] dev_addr      Device address to register (0..USB_DEVICE_COUNT_MAX-1).
 * @param[in] speed         Speed of the target device (::usb_speed_t).
 * @param[in] mxps0         Max packet size of the default control pipe (endpoint 0).
 * @param[in] hub_addr      Device address of the upstream high-speed hub acting as the
 *                          transaction translator, or 0 if the device is on the root port.
 *                          Used to configure split transactions for FS/LS devices.
 * @param[in] hub_port      Port number on @p hub_addr the device is attached to (1-based),
 *                          or 0 if the device is on the root port.
 *
 * @retval FSP_SUCCESS              Device registered.
 * @retval FSP_ERR_ASSERTION       @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN        The driver has not been opened.
 * @retval FSP_ERR_INVALID_ARGUMENT @p dev_addr is out of range or @p speed is not supported by the module.
 */
fsp_err_t R_USBH_PortOpen (usb_ctrl_t * const p_api_ctrl,
                           uint8_t            dev_addr,
                           usb_speed_t        speed,
                           uint8_t            mxps0,
                           uint8_t            hub_addr,
                           uint8_t            hub_port)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(USB_DEVICE_COUNT_MAX > dev_addr, FSP_ERR_INVALID_ARGUMENT);
#endif

    volatile uint16_t * p_dcpctr;
    volatile uint16_t * p_dcpmaxp;
    volatile uint16_t * p_devadd;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_dcpctr  = &R_USB_HS0->DCPCTR;
        p_dcpmaxp = &R_USB_HS0->DCPMAXP;
        p_devadd  = &R_USB_HS0->DEVADD[dev_addr];
    }
    else
#endif
    {
        p_dcpctr  = &R_USB_FS0->DCPCTR;
        p_dcpmaxp = &R_USB_FS0->DCPMAXP;
        p_devadd  = &R_USB_FS0->DEVADD[dev_addr];
    }

    *p_dcpctr = USB_PIPE_CTR_PID_NAK << R_USB_PIPE_CTR_PID_Pos;
    FSP_HARDWARE_REGISTER_WAIT((*p_dcpctr & R_USB_DCPCTR_PBUSY_Msk), 0);

    /* Set MPS for DCP */
    *p_dcpmaxp = ((dev_addr << R_USB_DCPMAXP_DEVSEL_Pos) & R_USB_DCPMAXP_DEVSEL_Msk) |
                 ((mxps0 << R_USB_DCPMAXP_MXPS_Pos) & R_USB_DCPMAXP_MXPS_Msk);

    uint16_t usbspd;

    switch (speed)
    {
        case USB_SPEED_LS:
        {
            usbspd = USB_DEVADD_USBSPD_LS;
            break;
        }

        case USB_SPEED_FS:
        {
            usbspd = USB_DEVADD_USBSPD_FS;
            break;
        }

#ifdef USB_HIGH_SPEED_MODULE
        case USB_SPEED_HS:
        {
            if (USB_IS_USBHS(p_ctrl->module_number))
            {
                usbspd = USB_DEVADD_USBSPD_HS;
                break;
            }

            __fallthrough;
        }
#endif

        default:
        {
            *p_devadd = USB_DEVADD_USBSPD_NOT_USE << R_USB_DEVADD_USBSPD_Pos;

            return FSP_ERR_INVALID_ARGUMENT;
        }
    }

    uint16_t devadd_val = usbspd << R_USB_DEVADD_USBSPD_Pos;

#ifdef USB_HIGH_SPEED_MODULE
    /*
     * Split transaction: a Full-/Low-speed device located behind a high-speed hub must
     * have its upstream hub address (transaction translator) and hub port programmed so
     * the controller performs SSPLIT/CSPLIT automatically. The UPPHUB/HUBPORT fields only
     * exist on the high-speed module. A zero hub address means the device is on the root
     * port and no split transaction is required.
     */
    if (USB_IS_USBHS(p_ctrl->module_number) && (0 != hub_addr) &&
        ((USB_SPEED_FS == speed) || (USB_SPEED_LS == speed)))
    {
        devadd_val |= ((hub_addr << R_USB_DEVADD_UPPHUB_Pos) & R_USB_DEVADD_UPPHUB_Msk) |
                      ((hub_port << R_USB_DEVADD_HUBPORT_Pos) & R_USB_DEVADD_HUBPORT_Msk);
    }
#else
    FSP_PARAMETER_NOT_USED(hub_addr);
    FSP_PARAMETER_NOT_USED(hub_port);
#endif

    *p_devadd = devadd_val;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        if (speed != USB_SPEED_HS)
        {
            R_USB_HS0->SOFCFG |= R_USB_SOFCFG_TRNENSEL_Msk;
        }
    }
    else
#endif
    {
        if (speed != USB_SPEED_FS)
        {
            R_USB_FS0->SOFCFG |= R_USB_SOFCFG_TRNENSEL_Msk;
        }
    }

    g_uhc_data[p_ctrl->module_number].ctl_mps[dev_addr] = mxps0;

    return FSP_SUCCESS;
}

/**
 * @brief Resume the bus from the suspended state.
 *
 * Drives resume signaling for ~3 ms, then clears it and re-enables bus activity (UACT), allowing
 * settling time before returning.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 *
 * @retval FSP_SUCCESS          Bus resumed.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN     The driver has not been opened.
 */
fsp_err_t R_USBH_BusResume (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    volatile uint16_t    * p_dvstctr0;

#if !defined(USB_HIGH_SPEED_MODULE) && !USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_dvstctr0 = &R_USB_HS0->DVSTCTR0;
    }
    else
#endif
    {
        p_dvstctr0 = &R_USB_FS0->DVSTCTR0;
    }

    *p_dvstctr0 |= R_USB_DVSTCTR0_RESUME_Msk;
    R_BSP_SoftwareDelay(3, BSP_DELAY_UNITS_MILLISECONDS);
    *p_dvstctr0 &= ~R_USB_DVSTCTR0_RESUME_Msk;
    *p_dvstctr0 |= R_USB_DVSTCTR0_UACT_Msk;
    R_BSP_SoftwareDelay(20, BSP_DELAY_UNITS_MILLISECONDS);

    return FSP_SUCCESS;
}

/**
 * @brief Suspend the bus.
 *
 * Stops bus activity by clearing the UACT and RESUME bits in DVSTCTR0.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 *
 * @retval FSP_SUCCESS          Bus suspended.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN     The driver has not been opened.
 */
fsp_err_t R_USBH_BusSuspend (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if !defined(USB_HIGH_SPEED_MODULE) && !USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_USB_HS0->DVSTCTR0 &= ~(R_USB_DVSTCTR0_UACT_Msk | R_USB_DVSTCTR0_RESUME_Msk);
    }
    else
#endif
    {
        R_USB_FS0->DVSTCTR0 &= ~(R_USB_DVSTCTR0_UACT_Msk | R_USB_DVSTCTR0_RESUME_Msk);
    }

    return FSP_SUCCESS;
}

/**
 * @brief Close the USB host driver.
 *
 * Clears the module registers and stops (powers down) the USB IP. After this call the control block
 * must be re-opened with R_USBH_Open() before it can be used again.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 *
 * @retval FSP_SUCCESS          Driver closed.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN     The driver has not been opened.
 */
fsp_err_t R_USBH_Close (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_usbh_hw_module_stop(p_ctrl);

    return FSP_SUCCESS;
}

/**
 * @brief Start a data transfer on a previously opened endpoint.
 *
 * Queues a transfer on the pipe bound to @p ep_addr. Endpoint 0 uses the default control pipe; all other
 * endpoints must have been opened with R_USBH_EdptOpen(). The call returns once the transfer has been
 * started; the actual completion (or error) is delivered later through the user callback as a
 * ::USBH_EVENT_XFER_COMPLETE event. Module interrupts are masked while the transfer is being set up.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 * @param[in] dev_addr      Target device address (0..USB_DEVICE_COUNT_MAX-1).
 * @param[in] ep_addr       Endpoint address, including the direction bit (bit 7).
 * @param[in] p_buffer      Data buffer to transmit (OUT) or receive into (IN). May be NULL for a ZLP.
 * @param[in] buflen        Number of bytes to transfer; 0 sends/receives a zero-length packet.
 *
 * @retval FSP_SUCCESS              Transfer started.
 * @retval FSP_ERR_ASSERTION       @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN        The driver has not been opened.
 * @retval FSP_ERR_INVALID_ARGUMENT @p dev_addr is out of range.
 * @retval FSP_ERR_WRITE_FAILED    The transfer could not be started.
 */
fsp_err_t R_USBH_XferStart (usb_ctrl_t * const p_api_ctrl,
                            uint8_t            dev_addr,
                            uint8_t            ep_addr,
                            uint8_t          * p_buffer,
                            uint16_t           buflen)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    bool ret;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(USB_DEVICE_COUNT_MAX > dev_addr, FSP_ERR_INVALID_ARGUMENT);
#endif

    r_usbh_interrupt_disable(p_ctrl);
    ret = r_usbh_process_edpt_xfer(p_ctrl, dev_addr, ep_addr, p_buffer, buflen);
    r_usbh_interrupt_enable(p_ctrl);
    if (ret == true)
    {
        return FSP_SUCCESS;
    }

    return FSP_ERR_WRITE_FAILED;
}

/**
 * @brief Connect the controller to the USB data bus.
 *
 * Enables the host D+/D- pull-down resistors (DRPD), disables the device pull-up (DPRPU), programs the
 * bus-wait cycles and finally enables the USB operation (USBE), allowing devices to be detected.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 *
 * @retval FSP_SUCCESS          Controller connected to the bus.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN     The driver has not been opened.
 */
fsp_err_t R_USBH_Enable (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if !defined(USB_HIGH_SPEED_MODULE) && !USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    volatile uint16_t * p_reg_syscfg;
    volatile uint16_t * p_reg_buswait;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_syscfg  = &R_USB_HS0->SYSCFG;
        p_reg_buswait = &R_USB_HS0->BUSWAIT;
    }
    else
#endif
    {
        p_reg_syscfg  = &R_USB_FS0->SYSCFG;
        p_reg_buswait = &R_USB_FS0->BUSWAIT;
    }

    *p_reg_syscfg |= R_USB_SYSCFG_DRPD_Msk;
    *p_reg_syscfg &= ~R_USB_SYSCFG_DPRPU_Msk;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        *p_reg_syscfg |= R_USB_SYSCFG_CNEN_Msk;
    }
#endif

    *p_reg_buswait = USBH_CFG_BUS_WAIT_CYCLES;
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
    *p_reg_syscfg |= R_USB_SYSCFG_USBE_Msk;

    return FSP_SUCCESS;
}

/**
 * @brief Disconnect the controller from the USB data bus.
 *
 * Clears the pull-down/pull-up control bits and disables USB operation (USBE), electrically
 * removing the controller from the bus.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 *
 * @retval FSP_SUCCESS          Controller disconnected from the bus.
 * @retval FSP_ERR_ASSERTION    @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN     The driver has not been opened.
 */
fsp_err_t R_USBH_Disable (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if !defined(USB_HIGH_SPEED_MODULE) && !USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_USB_HS0->SYSCFG &= ~(R_USB_SYSCFG_DRPD_Msk | R_USB_SYSCFG_DPRPU_Msk |
                               R_USB_SYSCFG_CNEN_Msk | R_USB_SYSCFG_USBE_Msk);
    }
    else
#endif
    {
        R_USB_FS0->SYSCFG &= ~(R_USB_SYSCFG_DRPD_Msk | R_USB_SYSCFG_DPRPU_Msk | R_USB_SYSCFG_USBE_Msk);
    }

    return FSP_SUCCESS;
}

/**
 * @brief Abort an in-progress transfer on an endpoint.
 *
 * Stops any transfer pending on @p ep_addr. For endpoint 0 the control transfer is terminated and the
 * control FIFO is cleared; for other endpoints the bound pipe is set to NAK, its interrupts are disabled,
 * the FIFO port is released and the transaction counter is cleared. No completion event is generated for
 * the aborted transfer. Module interrupts are masked for the duration of the operation.
 *
 * @param[in] p_api_ctrl    Pointer to the USB host control block (::usbh_instance_ctrl_t).
 * @param[in] dev_addr      Device address that owns the endpoint (1..USB_DEVICE_COUNT_MAX-1).
 * @param[in] ep_addr       Endpoint address, including the direction bit (bit 7).
 *
 * @retval FSP_SUCCESS              Transfer aborted.
 * @retval FSP_ERR_ASSERTION       @p p_api_ctrl was NULL.
 * @retval FSP_ERR_NOT_OPEN        The driver has not been opened.
 * @retval FSP_ERR_INVALID_ARGUMENT @p dev_addr / @p ep_addr is out of range, or no pipe is bound to it.
 */
fsp_err_t R_USBH_XferAbort (usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr, uint8_t ep_addr)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    const uint32_t         epn    = r_usbh_edpt_number(ep_addr);

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(USB_DEVICE_COUNT_MAX > dev_addr, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(USB_EP_COUNT_MAX > epn, FSP_ERR_INVALID_ARGUMENT);
#endif

    r_usbh_interrupt_disable(p_ctrl);

    if (0 == epn)
    {
        r_usbh_process_terminate_control_xfer(p_ctrl);
    }
    else
    {
        const uint32_t dir = r_usbh_edpt_dir(ep_addr);
        const uint32_t num = g_uhc_data[p_ctrl->module_number].ep[dev_addr - 1][dir][epn - 1];

        if (num == 0)
        {
            r_usbh_interrupt_enable(p_ctrl);

            return FSP_ERR_INVALID_ARGUMENT;
        }

        r_usbh_process_terminate_xfer(p_ctrl, num);
    }

    r_usbh_interrupt_enable(p_ctrl);

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/* Release the selected USB IP from the module-stop (low-power) state and supply it clock/power. */
static fsp_err_t r_usbh_hw_module_start (usbh_instance_ctrl_t * const p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        FSP_ERROR_RETURN(0 != R_MSTP->MSTPCRB_b.MSTPB12, FSP_ERR_USB_BUSY)

        /* Enable power for USBA */
        R_BSP_MODULE_START(FSP_IP_USBHS, 0);
    }
    else
#endif
    {
        FSP_ERROR_RETURN(0 != R_MSTP->MSTPCRB_b.MSTPB11, FSP_ERR_USB_BUSY)

        /* Enable power for USBA */
        R_BSP_MODULE_START(FSP_IP_USBFS, 0);
    }

    return FSP_SUCCESS;
}

/* Reset all host registers (control, interrupt enables/status, pipes and device addresses) to a known
 * idle state and remove the controller from the bus. */
static fsp_err_t r_usbh_module_register_clear (usbh_instance_ctrl_t * const p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_USB_HS0->DVSTCTR0 = 0;
        R_USB_HS0->DCPCTR   = R_USB_DCPCTR_SQSET_Msk;
        R_USB_HS0->BRDYENB  = 0;
        R_USB_HS0->NRDYENB  = 0;
        R_USB_HS0->BEMPENB  = 0;
        R_USB_HS0->INTENB0  = 0;
        R_USB_HS0->INTENB1  = 0;
        R_USB_HS0->BRDYSTS  = 0;
        R_USB_HS0->NRDYSTS  = 0;
        R_USB_HS0->BEMPSTS  = 0;
        R_USB_HS0->CFIFOCTR = 0;

        for (uint32_t i = 0; i < USB_PIPE_COUNT_MAX - 1; ++i)
        {
            R_USB_HS0->PIPE_CTR[0] = 0;
        }

        for (uint32_t i = 0; i < USB_HS_DEVADD_NUM_MAX; ++i)
        {
            R_USB_HS0->DEVADD[i] = 0;
        }

        R_USB_HS0->SYSCFG &= ~(R_USB_SYSCFG_DPRPU_Msk | R_USB_SYSCFG_DRPD_Msk |
                               R_USB_SYSCFG_DCFM_Msk | R_USB_SYSCFG_USBE_Msk);
        R_USB_HS0->LPSTS = 0;
    }
    else
#endif
    {
        R_USB_FS0->DVSTCTR0 = 0;
        R_USB_FS0->DCPCTR   = R_USB_DCPCTR_SQSET_Msk;
        R_USB_FS0->BRDYENB  = 0;
        R_USB_FS0->NRDYENB  = 0;
        R_USB_FS0->BEMPENB  = 0;
        R_USB_FS0->INTENB0  = 0;
        R_USB_FS0->INTENB1  = 0;
        R_USB_FS0->BRDYSTS  = 0;
        R_USB_FS0->NRDYSTS  = 0;
        R_USB_FS0->BEMPSTS  = 0;
        R_USB_FS0->CFIFOCTR = 0;

        for (uint32_t i = 0; i < USB_PIPE_COUNT_MAX - 1; ++i)
        {
            R_USB_FS0->PIPE_CTR[0] = 0;
        }

        for (uint32_t i = 0; i < USB_FS_DEVADD_NUM_MAX; ++i)
        {
            R_USB_FS0->DEVADD[i] = 0;
        }

        R_USB_FS0->SYSCFG &= ~(R_USB_SYSCFG_DPRPU_Msk | R_USB_SYSCFG_DRPD_Msk |
                               R_USB_SYSCFG_DCFM_Msk | R_USB_SYSCFG_USBE_Msk);
        R_USB_FS0->LPSTS = 0;
    }

    return FSP_SUCCESS;
}

/* Clear the host registers and put the selected USB IP back into the module-stop (low-power) state. */
static fsp_err_t r_usbh_hw_module_stop (usbh_instance_ctrl_t * const p_ctrl)
{
    r_usbh_module_register_clear(p_ctrl);

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        FSP_ERROR_RETURN(0 == R_MSTP->MSTPCRB_b.MSTPB12, FSP_ERR_USB_NOT_OPEN)

        /* Enable power for USBA */
        R_BSP_MODULE_STOP(FSP_IP_USBHS, 0);
    }
    else
#endif
    {
        FSP_ERROR_RETURN(0 == R_MSTP->MSTPCRB_b.MSTPB11, FSP_ERR_USB_NOT_OPEN)

        /* Disable power for USB0 */
        R_BSP_MODULE_STOP(FSP_IP_USBFS, 0);
    }

    return FSP_SUCCESS;
}

/* Bring the USB IP up in host mode: configure the PHY/PLL (HS) or clock (FS), enable VBUS, switch to
 * host controller mode (DCFM) and set up the default control pipe. */
static void r_usbh_hw_init (usbh_instance_ctrl_t * const p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_USB_HS0->PHYSET  = R_USB_PHYSET_DIRPD_Msk | R_USB_PHYSET_PLLRESET_Msk;
        R_USB_HS0->PHYSET |= USB_PHYSET_REPSEL_16_SEC << R_USB_PHYSET_REPSEL_Pos;

 #if USBHS_PHY_CLOCK_SOURCE_IS_XTAL
        R_USB_HS0->PHYSET |= USBH_CFG_PHYSET_CLKSEL << R_USB_PHYSET_CLKSEL_Pos;
 #else
        R_USB_HS0->PHYSET |= R_USB_PHYSET_HSEB_Msk;
 #endif
        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
        R_USB_HS0->PHYSET &= ~R_USB_PHYSET_DIRPD_Msk;
        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
        R_USB_HS0->PHYSET &= ~R_USB_PHYSET_PLLRESET_Msk;

        R_USB_HS0->LPSTS |= R_USB_LPSTS_SUSPENDM_Msk;

        /* Wait for PLL Lock */
        FSP_HARDWARE_REGISTER_WAIT((R_USB_HS0->PLLSTA & R_USB_PLLSTA_PLLLOCK_Msk),
                                   R_USB_PLLSTA_PLLLOCK_Msk);

        R_USB_HS0->SYSCFG |= R_USB_SYSCFG_DCFM_Msk;
        R_USB_HS0->SOFCFG |= R_USB_SOFCFG_INTL_Msk;

        R_USB_HS0->DVSTCTR0 |= R_USB_DVSTCTR0_VBUSEN_Msk;
        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);

        R_USB_HS0->SYSCFG |= R_USB_SYSCFG_USBE_Msk;

        /* Setup default control pipe */
        R_USB_HS0->DCPCFG  = R_USB_DCPCFG_SHTNAK_Msk;
        R_USB_HS0->DCPMAXP = USB_DCPMAXP_MXPS_DEFAULT;
    }
    else
#endif
    {
        R_USB_FS0->SYSCFG |= R_USB_SYSCFG_SCKE_Msk;
        FSP_HARDWARE_REGISTER_WAIT((R_USB_FS0->SYSCFG & R_USB_SYSCFG_SCKE_Msk),
                                   R_USB_SYSCFG_SCKE_Msk);

        R_USB_FS0->SYSCFG |= R_USB_SYSCFG_DCFM_Msk;

        R_USB_FS0->DVSTCTR0 |= R_USB_DVSTCTR0_VBUSEN_Msk;
        R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);

        R_USB_FS0->SYSCFG |= R_USB_SYSCFG_USBE_Msk;

        /* Setup default control pipe */
        R_USB_FS0->DCPCFG  = R_USB_DCPCFG_SHTNAK_Msk;
        R_USB_FS0->DCPMAXP = USB_DCPMAXP_MXPS_DEFAULT;
    }
}

/* Return the non-zero DEVADD speed/hub bits for @p addr, or 0 if the address is not currently registered. */
static uint16_t r_usbh_chk_dev_addr (usbh_instance_ctrl_t * p_ctrl, uint16_t addr)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        return R_USB_HS0->DEVADD[addr] & (R_USB_DEVADD_USBSPD_Msk |
                                          R_USB_DEVADD_HUBPORT_Msk |
                                          R_USB_DEVADD_UPPHUB_Msk);
    }
    else
#endif
    {
        return R_USB_FS0->DEVADD[addr] & R_USB_DEVADD_USBSPD_Msk;
    }
}

/* Program the bus speed for device address @p addr in the DEVADD register (and reset the default control
 * pipe max packet size when addr 0 is configured). */
void r_usbh_set_dev_addr (usbh_instance_ctrl_t * p_ctrl, uint16_t addr, uint16_t speed)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        if (USB_DCPMAXP_DEVSEL_DEFAULT == addr)
        {
            R_USB_HS0->DCPMAXP = USB_DCPMAXP_MXPS_DEFAULT + USB_DCPMAXP_DEVSEL_DEFAULT;
        }

        R_USB_HS0->DEVADD[addr] &= ~R_USB_DEVADD_USBSPD_Msk;
        R_USB_HS0->DEVADD[addr] |= speed << R_USB_DEVADD_USBSPD_Pos;
    }
    else
#endif
    {
        if (USB_DCPMAXP_DEVSEL_DEFAULT == addr)
        {
            R_USB_FS0->DCPMAXP = USB_DCPMAXP_MXPS_DEFAULT + USB_DCPMAXP_DEVSEL_DEFAULT;
        }

        R_USB_FS0->DEVADD[addr] &= ~R_USB_DEVADD_USBSPD_Msk;
        R_USB_FS0->DEVADD[addr] |= speed << R_USB_DEVADD_USBSPD_Pos;
    }
}

/* Tear down every pipe owned by @p dev_addr: stop it, disable its interrupts, clear its configuration and
 * the endpoint map entry, then release the device address. */
static void r_usbh_device_release (usbh_instance_ctrl_t * p_ctrl, uint8_t dev_addr)
{
    volatile uint16_t * p_nrdyend;
    volatile uint16_t * p_brdyend;
    volatile uint16_t * p_pipesel;
    volatile uint16_t * p_pipecfg;
    volatile uint16_t * p_pipemaxp;
    volatile uint16_t * p_pipectr;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_nrdyend  = &R_USB_HS0->NRDYENB;
        p_brdyend  = &R_USB_HS0->BRDYENB;
        p_pipesel  = &R_USB_HS0->PIPESEL;
        p_pipecfg  = &R_USB_HS0->PIPECFG;
        p_pipemaxp = &R_USB_HS0->PIPEMAXP;
        p_pipectr  = &R_USB_HS0->PIPE_CTR[0];
    }
    else
#endif
    {
        p_nrdyend  = &R_USB_FS0->NRDYENB;
        p_brdyend  = &R_USB_FS0->BRDYENB;
        p_pipesel  = &R_USB_FS0->PIPESEL;
        p_pipecfg  = &R_USB_FS0->PIPECFG;
        p_pipemaxp = &R_USB_FS0->PIPEMAXP;
        p_pipectr  = &R_USB_FS0->PIPE_CTR[0];
    }

    g_uhc_data[p_ctrl->module_number].ctl_mps[dev_addr] = 0;
    uint8_t * p_ep = &g_uhc_data[p_ctrl->module_number].ep[dev_addr - 1][0][0];

    for (uint32_t i = 0; i < 2 * USB_EP_COUNT_MAX; ++i, ++p_ep)
    {
        uint32_t num = *p_ep;
        if (!num || (dev_addr != g_uhc_data[p_ctrl->module_number].pipe[num].dev))
        {
            continue;
        }

        p_pipectr[num - 1] = 0;
        *p_nrdyend        &= ~USB_SETBIT(num);
        *p_brdyend        &= ~USB_SETBIT(num);
        *p_pipesel         = num;
        *p_pipecfg         = 0;
        *p_pipemaxp        = 0;

        g_uhc_data[p_ctrl->module_number].pipe[num].ep  = 0;
        g_uhc_data[p_ctrl->module_number].pipe[num].dev = 0;
        *p_ep = 0;
    }

    r_usbh_set_dev_addr(p_ctrl, dev_addr, 0);
}

/* Find a free hardware pipe within the index range reserved for @p xfer_type. Returns the pipe number,
 * or 0 if none is available. */
static uint32_t r_usbh_find_pipe (usbh_instance_ctrl_t * const p_ctrl, uint8_t xfer_type)
{
    const uint8_t pipe_idx_arr[4][2] =
    {
        {0, 0},                        /* Control */
        {1, 2},                        /* Isochronous */
        {1, 5},                        /* Bulk */
        {6, 9},                        /* Interrupt */
    };

    const uint8_t idx_first = pipe_idx_arr[xfer_type][0];
    const uint8_t idx_last  = pipe_idx_arr[xfer_type][1];

    for (int i = idx_last; i >= idx_first; i--)
    {
        if (0 == g_uhc_data[p_ctrl->module_number].pipe[i].ep)
        {
            return i;
        }
    }

    return 0;
}

/* Return a pointer to the PIPECTR register for pipe @p num (DCPCTR for pipe 0). */
static volatile uint16_t * r_usbh_get_pipectr (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        return (0 != num) ? &(R_USB_HS0->PIPE_CTR[num - 1]) : &(R_USB_HS0->DCPCTR);
    }
    else
#endif
    {
        return (0 != num) ? &(R_USB_FS0->PIPE_CTR[num - 1]) : &(R_USB_FS0->DCPCTR);
    }
}

/* Invoke the user callback with a ::USBH_EVENT_XFER_COMPLETE event describing the finished transfer. */
static inline void r_usbh_event_xfer_complete_notify (usbh_instance_ctrl_t * const p_ctrl,
                                                      uint8_t                      dev_addr,
                                                      uint8_t                      ep_addr,
                                                      uint32_t                     xferred_bytes,
                                                      usb_xfer_result_t            result)
{
    usbh_callback_arg_t   args;
    usbh_callback_arg_t * p_args = p_ctrl->p_callback_memory;

    if (NULL == p_ctrl->p_callback)
    {
        return;
    }

    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt.
         */
        args = *p_args;
    }

    p_args->module_number = p_ctrl->module_number;
    p_args->p_context     = p_ctrl->p_context;
    p_args->event         = (usbh_event_t) {
        .event_id = USBH_EVENT_XFER_COMPLETE,
        .dev_addr = dev_addr,
        .complete =
        {
            .ep_addr = ep_addr,
            .result  = result,
            .len     = xferred_bytes
        }
    };

    if (p_ctrl->p_callback != NULL)
    {
        p_ctrl->p_callback(p_args);
    }
}

/* Invoke the user callback with a ::USBH_EVENT_DEVICE_ATTACH event. */
static inline void r_usbh_event_device_attach_notify (usbh_instance_ctrl_t * const p_ctrl, usb_speed_t speed)
{
    usbh_callback_arg_t   args;
    usbh_callback_arg_t * p_args = p_ctrl->p_callback_memory;

    if (NULL == p_ctrl->p_callback)
    {
        return;
    }

    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->module_number = p_ctrl->module_number;
    p_args->p_context     = p_ctrl->p_context;
    p_args->event         = (usbh_event_t) {
        .event_id = USBH_EVENT_DEVICE_ATTACH,
        .attach   =
        {
            .hub_addr = 0,
            .hub_port = 0,
            .speed    = speed
        }
    };

    if (p_ctrl->p_callback != NULL)
    {
        p_ctrl->p_callback(p_args);
    }
}

/* Return a pointer to the transaction-counter (PIPETRE) register for pipe @p num, or NULL if the pipe
 * does not have one. */
static volatile usb_reg_pipetre_t * r_usbh_get_pipetre (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    if ((USB_PIPETR_INDEX_BEGIN <= num) && (num <= USB_PIPETR_INDEX_END))
    {
#ifdef USB_HIGH_SPEED_MODULE
        if (USB_IS_USBHS(p_ctrl->module_number))
        {
            return (volatile usb_reg_pipetre_t *) &(R_USB_HS0->PIPE_TR[num - USB_PIPETR_INDEX_BEGIN].E);
        }
        else
#endif
        {
            return (volatile usb_reg_pipetre_t *) &(R_USB_FS0->PIPE_TR[num - USB_PIPETR_INDEX_BEGIN].E);
        }
    }

    return NULL;
}

/* Return the max packet size currently programmed for the default control pipe (endpoint 0). */
static uint16_t r_usbh_edpt0_max_packet_size (usbh_instance_ctrl_t * const p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        return (uint16_t) ((R_USB_HS0->DCPMAXP & R_USB_DCPMAXP_MXPS_Msk) >>
                           R_USB_DCPMAXP_MXPS_Pos);
    }
    else
#endif
    {
        return (uint16_t) ((R_USB_FS0->DCPMAXP & R_USB_DCPMAXP_MXPS_Msk) >>
                           R_USB_DCPMAXP_MXPS_Pos);
    }
}

/* Return the max packet size programmed for pipe @p num (selects the pipe via PIPESEL). */
static uint16_t r_usbh_edpt_max_packet_size (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_USB_HS0->PIPESEL = num;

        return (uint16_t) (R_USB_HS0->PIPEMAXP & 0x3FF);
    }
    else
#endif
    {
        R_USB_FS0->PIPESEL = num;

        return (uint16_t) ((R_USB_FS0->PIPEMAXP & R_USB_FS0_PIPEMAXP_MXPS_Msk) >> R_USB_FS0_PIPEMAXP_MXPS_Pos);
    }
}

/* Block until the D0FIFO is selected for pipe @p num and reports ready (FRDY) for access. */
static inline void r_usbh_pipe_wait_for_ready (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[num];
    const uint32_t dir    = r_usbh_edpt_dir(p_pipe->ep);

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        if (dir == USB_DIR_IN)
        {
            FSP_HARDWARE_REGISTER_WAIT((R_USB_HS0->D0FIFOSEL & R_USB_D0FIFOSEL_CURPIPE_Msk) >>
                                       R_USB_D0FIFOSEL_CURPIPE_Pos,
                                       num);
            FSP_HARDWARE_REGISTER_WAIT((R_USB_HS0->D0FIFOCTR & R_USB_D0FIFOCTR_FRDY_Msk),
                                       R_USB_D0FIFOCTR_FRDY_Msk);
        }
        else
        {
            FSP_HARDWARE_REGISTER_WAIT((R_USB_HS0->D1FIFOSEL & R_USB_D1FIFOSEL_CURPIPE_Msk) >>
                                       R_USB_D1FIFOSEL_CURPIPE_Pos,
                                       num);
            FSP_HARDWARE_REGISTER_WAIT((R_USB_HS0->D1FIFOCTR & R_USB_D1FIFOCTR_FRDY_Msk),
                                       R_USB_D1FIFOCTR_FRDY_Msk);
        }
    }
    else
#endif
    {
        if (dir == USB_DIR_IN)
        {
            FSP_HARDWARE_REGISTER_WAIT((R_USB_FS0->D0FIFOSEL & R_USB_D0FIFOSEL_CURPIPE_Msk) >>
                                       R_USB_D0FIFOSEL_CURPIPE_Pos,
                                       num);
            FSP_HARDWARE_REGISTER_WAIT((R_USB_FS0->D0FIFOCTR & R_USB_D0FIFOCTR_FRDY_Msk),
                                       R_USB_D0FIFOCTR_FRDY_Msk);
        }
        else
        {
            FSP_HARDWARE_REGISTER_WAIT((R_USB_FS0->D1FIFOSEL & R_USB_D1FIFOSEL_CURPIPE_Msk) >>
                                       R_USB_D1FIFOSEL_CURPIPE_Pos,
                                       num);
            FSP_HARDWARE_REGISTER_WAIT((R_USB_FS0->D1FIFOCTR & R_USB_D1FIFOCTR_FRDY_Msk),
                                       R_USB_D1FIFOCTR_FRDY_Msk);
        }
    }
}

/* Write @p len bytes from @p p_buf into the FIFO at @p p_fifo, using the widest access (32/16/8-bit)
 * allowed by buffer alignment, remaining length and @p access_bytes. */
static void r_usbh_pipe_write_packet (usbh_instance_ctrl_t * const p_ctrl,
                                      void                       * p_buf,
                                      volatile void              * p_fifo,
                                      uint32_t                     len,
                                      uint32_t                     access_bytes,
                                      uint8_t                      num)
{
#ifdef USB_HIGH_SPEED_MODULE
    volatile uint32_t * p_fifo32 = (volatile uint32_t *) p_fifo;
    volatile uint16_t * p_fifo16 = (volatile uint16_t *) (access_bytes ==
                                                          4 ? ((uintptr_t) p_fifo + 2) : (uintptr_t) p_fifo);
    volatile uint8_t * p_fifo8 = (volatile uint8_t *) (access_bytes ==
                                                       4 ? ((uintptr_t) p_fifo + 3) : (uintptr_t) p_fifo);
#else
    volatile uint16_t * p_fifo16 = (volatile uint16_t *) (p_fifo);
    volatile uint8_t  * p_fifo8  = (volatile uint8_t *) (p_fifo);
#endif
    uint8_t * p_addr = p_buf;

#ifdef USB_HIGH_SPEED_MODULE
    if ((access_bytes == 4) && ((uintptr_t) p_addr % 4 == 0))
    {
        while (len >= 4)
        {
            *p_fifo32 = *(uint32_t *) p_addr;
            p_addr   += 4;
            len      -= 4;
        }
    }
#endif

    while (len >= 2 && (uintptr_t) p_addr % 2 == 0)
    {
        if (access_bytes != 2)
        {
            fifo_set_mbw(p_fifo, USB_FIFOSEL_MBW_16_BIT, num);
        }

        *p_fifo16 = *(uint16_t *) p_addr;
        p_addr   += 2;
        len      -= 2;
    }

    if (len)
    {
        fifo_set_mbw(p_fifo, USB_FIFOSEL_MBW_8_BIT, num);
    }

    while (len--)
    {
        *p_fifo8 = *p_addr;
        ++p_addr;
    }
}

/* Read @p len bytes from the FIFO at @p p_fifo into @p p_buf, using the widest access (32/16/8-bit)
 * allowed by buffer alignment, remaining length and @p access_bytes. */
static void r_usbh_pipe_read_packet (usbh_instance_ctrl_t * const p_ctrl,
                                     void                       * p_buf,
                                     volatile void              * p_fifo,
                                     uint32_t                     len,
                                     uint32_t                     access_bytes,
                                     uint8_t                      num)
{
#ifdef USB_HIGH_SPEED_MODULE
    volatile uint32_t * p_fifo32 = (volatile uint32_t *) p_fifo;
    volatile uint16_t * p_fifo16 = (volatile uint16_t *) (access_bytes ==
                                                          4 ? ((uintptr_t) p_fifo + 2) : (uintptr_t) p_fifo);
    volatile uint8_t * p_fifo8 = (volatile uint8_t *) (access_bytes ==
                                                       4 ? ((uintptr_t) p_fifo + 3) : (uintptr_t) p_fifo);
#else
    volatile uint16_t * p_fifo16 = (volatile uint16_t *) (p_fifo);
    volatile uint8_t  * p_fifo8  = (volatile uint8_t *) (p_fifo);
#endif
    uint8_t * p_data = (uint8_t *) p_buf;

#ifdef USB_HIGH_SPEED_MODULE
    if ((access_bytes == 4) && ((uintptr_t) p_data % 4 == 0))
    {
        while (len >= 4)
        {
            *(uint32_t *) p_data = *p_fifo32;
            p_data              += 4;
            len -= 4;
        }
    }
#endif

    while (len >= 2 && (uintptr_t) p_data % 2 == 0)
    {
        if (access_bytes != 2)
        {
            fifo_set_mbw(p_fifo, USB_FIFOSEL_MBW_16_BIT, num);
        }

        *(uint16_t *) p_data = *p_fifo16;
        p_data              += 2;
        len -= 2;
    }

    if (len)
    {
        fifo_set_mbw(p_fifo, USB_FIFOSEL_MBW_8_BIT, num);
    }

    while (len--)
    {
        *p_data = *p_fifo8;
        ++p_data;
    }
}

/* Read one IN packet of the control data stage from the CFIFO. Returns true when the whole transfer is
 * complete (short packet received or all bytes read), false when more packets are expected. */
static bool r_usbh_pipe0_xfer_in (usbh_instance_ctrl_t * const p_ctrl)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[0];
    void         * p_buf  = p_pipe->buf;
    const uint32_t rem    = p_pipe->remaining;
#ifdef USB_HIGH_SPEED_MODULE
    const uint32_t access_bytes = USB_IS_USBHS(p_ctrl->module_number) ? 4 : 2;
#else
    const uint32_t access_bytes = 2;
#endif

    volatile uint16_t * p_dcpctr;
    volatile uint16_t * p_cfifoctr;
    volatile void     * p_cfifo;
    uint32_t            vld;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_dcpctr   = &R_USB_HS0->DCPCTR;
        p_cfifoctr = &R_USB_HS0->CFIFOCTR;
        p_cfifo    = (volatile void *) &R_USB_HS0->CFIFO;
        vld        = (uint32_t) (R_USB_HS0->CFIFOCTR & R_USB_CFIFOCTR_DTLN_Msk);
    }
    else
#endif
    {
        p_dcpctr   = &R_USB_FS0->DCPCTR;
        p_cfifoctr = &R_USB_FS0->CFIFOCTR;
        p_cfifo    = (volatile void *) &R_USB_FS0->CFIFO;
        vld        = (uint32_t) (R_USB_FS0->CFIFOCTR & R_USB_CFIFOCTR_DTLN_Msk);
    }

    const uint32_t mps = r_usbh_edpt0_max_packet_size(p_ctrl);
    const uint32_t len = USB_MIN(USB_MIN(rem, mps), vld);

    if (len)
    {
        *p_dcpctr = USB_PIPE_CTR_PID_NAK << R_USB_PIPE_CTR_PID_Pos;

        /* Wait for pipe to be idle before reading */
        FSP_HARDWARE_REGISTER_WAIT((*p_dcpctr & R_USB_DCPCTR_PBUSY_Msk), 0);

        r_usbh_pipe_read_packet(p_ctrl, p_buf, p_cfifo, len, access_bytes, 0);
        p_pipe->buf = (uint8_t *) p_buf + len;
    }

    if (len < mps)
    {
        *p_cfifoctr = R_USB_CFIFOCTR_BCLR_Msk;
    }

    p_pipe->remaining = rem - len;
    if ((len < mps) || (rem == len))
    {
        p_pipe->buf = NULL;

        return true;
    }

    *p_dcpctr = USB_PIPE_CTR_PID_BUF << R_USB_PIPE_CTR_PID_Pos;

    return false;
}

/* Write one OUT packet of the control data stage into the CFIFO. Returns true when nothing remains to be
 * sent, false when more packets are still pending. */
static bool r_usbh_pipe0_xfer_out (usbh_instance_ctrl_t * const p_ctrl)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[0];
    const uint32_t rem    = p_pipe->remaining;
#ifdef USB_HIGH_SPEED_MODULE
    const uint32_t access_bytes = USB_IS_USBHS(p_ctrl->module_number) ? 4 : 2;
#else
    const uint32_t access_bytes = 2;
#endif

    if (!rem)
    {
        p_pipe->buf = NULL;

        return true;
    }

    const uint32_t mps   = r_usbh_edpt0_max_packet_size(p_ctrl);
    const uint32_t len   = USB_MIN(mps, rem);
    void         * p_buf = p_pipe->buf;

    volatile uint16_t * p_cfifoctr;
    volatile void     * p_cfifo;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_cfifoctr = &R_USB_HS0->CFIFOCTR;
        p_cfifo    = (volatile void *) &R_USB_HS0->CFIFO;

        /* Wait for FIFO ready before writing */
        FSP_HARDWARE_REGISTER_WAIT((R_USB_HS0->CFIFOCTR & R_USB_CFIFOCTR_FRDY_Msk), R_USB_CFIFOCTR_FRDY_Msk);
    }
    else
#endif
    {
        p_cfifoctr = &R_USB_FS0->CFIFOCTR;
        p_cfifo    = (volatile void *) &R_USB_FS0->CFIFO;

        /* Wait for FIFO ready before writing */
        FSP_HARDWARE_REGISTER_WAIT((R_USB_FS0->CFIFOCTR & R_USB_CFIFOCTR_FRDY_Msk), R_USB_CFIFOCTR_FRDY_Msk);
    }

    if (len)
    {
        r_usbh_pipe_write_packet(p_ctrl, p_buf, p_cfifo, len, access_bytes, 0);
        p_pipe->buf = (uint8_t *) p_buf + len;
    }

    if (len < mps)
    {
        *p_cfifoctr = R_USB_CFIFOCTR_BVAL_Msk;

        if (len == 0)
        {
            /* Clear FIFO for ZLP */
            *p_cfifoctr |= R_USB_CFIFOCTR_BCLR_Msk;
        }
    }

    p_pipe->remaining = rem - len;

    return false;
}

/* Read one IN packet for pipe @p num from the D0FIFO. Returns true when the transfer is complete (short
 * packet or all bytes received), false when more data is expected. */
static bool r_usbh_pipe_xfer_in (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[num];
    void         * p_buf  = p_pipe->buf;
    const uint32_t rem    = p_pipe->remaining;
    const uint32_t mps    = r_usbh_edpt_max_packet_size(p_ctrl, num);
#ifdef USB_HIGH_SPEED_MODULE
    const uint32_t access_bytes = USB_IS_USBHS(p_ctrl->module_number) ? 4 : 2;
#else
    const uint32_t access_bytes = 2;
#endif

    volatile uint16_t * p_reg_d0fifosel;
    volatile uint16_t * p_reg_d0fifoctr;
    volatile void     * p_reg_d0fifo;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_d0fifosel = &R_USB_HS0->D0FIFOSEL;
        p_reg_d0fifoctr = &R_USB_HS0->D0FIFOCTR;
        p_reg_d0fifo    = (volatile void *) &R_USB_HS0->D0FIFO;
    }
    else
#endif
    {
        p_reg_d0fifosel = &R_USB_FS0->D0FIFOSEL;
        p_reg_d0fifoctr = &R_USB_FS0->D0FIFOCTR;
        p_reg_d0fifo    = (volatile void *) &R_USB_FS0->D0FIFO;
    }

    /* Clear CURPIPE first */
    *p_reg_d0fifosel = 0;
    FSP_HARDWARE_REGISTER_WAIT((*p_reg_d0fifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), 0);

    /* Set new pipe with optimal MBW based on access_bytes */
    uint16_t fifosel_val = (num << R_USB_D0FIFOSEL_CURPIPE_Pos);

#ifdef USB_HIGH_SPEED_MODULE
    if (access_bytes == 4)
    {
        fifosel_val |= (USB_FIFOSEL_MBW_32_BIT << R_USB_D0FIFOSEL_MBW_Pos);
    }
    else
#endif
    {
        fifosel_val |= (USB_FIFOSEL_MBW_16_BIT << R_USB_D0FIFOSEL_MBW_Pos);
    }

    *p_reg_d0fifosel = fifosel_val;

    r_usbh_pipe_wait_for_ready(p_ctrl, num);

    const uint16_t vld = (*p_reg_d0fifoctr & R_USB_CFIFOCTR_DTLN_Msk);
    const uint32_t len = USB_MIN(USB_MIN(rem, mps), vld);

    if (len)
    {
        r_usbh_pipe_read_packet(p_ctrl, p_buf, p_reg_d0fifo, len, access_bytes, num);
        p_pipe->buf = (uint8_t *) p_buf + len;
    }

    if (len < mps)
    {
        *p_reg_d0fifoctr = R_USB_D0FIFOCTR_BCLR_Msk;
    }

    *p_reg_d0fifosel = 0;
    FSP_HARDWARE_REGISTER_WAIT((*p_reg_d0fifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), 0);

    p_pipe->remaining = rem - len;
    if ((len < mps) || (rem == len))
    {
        p_pipe->buf = NULL;

        return NULL != p_buf;
    }

    return false;
}

/* Write one OUT packet for pipe @p num into the D0FIFO. Returns true when nothing remains to be sent,
 * false when more packets are still pending. */
static bool r_usbh_pipe_xfer_out (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[num];
    void         * p_buf  = p_pipe->buf;
    const uint32_t rem    = p_pipe->remaining;
    const uint32_t mps    = r_usbh_edpt_max_packet_size(p_ctrl, num);
    const uint32_t len    = USB_MIN(rem, mps);
#ifdef USB_HIGH_SPEED_MODULE
    const uint32_t access_bytes = USB_IS_USBHS(p_ctrl->module_number) ? 4 : 2;
#else
    const uint32_t access_bytes = 2;
#endif

    volatile uint16_t * p_reg_dxfifosel;
    volatile uint16_t * p_reg_dxfifoctr;
    volatile void     * p_reg_dxfifo;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_dxfifosel = &R_USB_HS0->D1FIFOSEL;
        p_reg_dxfifoctr = &R_USB_HS0->D1FIFOCTR;
        p_reg_dxfifo    = (volatile void *) &R_USB_HS0->D1FIFO;
    }
    else
#endif
    {
        p_reg_dxfifosel = &R_USB_FS0->D0FIFOSEL;
        p_reg_dxfifoctr = &R_USB_FS0->D0FIFOCTR;
        p_reg_dxfifo    = (volatile void *) &R_USB_FS0->D0FIFO;
    }

    if (!rem)
    {
        p_pipe->buf = NULL;

        return true;
    }

    /* Clear CURPIPE first */
    *p_reg_dxfifosel = 0;
    FSP_HARDWARE_REGISTER_WAIT((*p_reg_dxfifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), 0);

    /* Set new pipe with optimal MBW and ISEL for write direction */
    uint16_t fifosel_val = (num << R_USB_D0FIFOSEL_CURPIPE_Pos) | R_USB_CFIFOSEL_ISEL_Msk;

#ifdef USB_HIGH_SPEED_MODULE
    if (access_bytes == 4)
    {
        fifosel_val |= (USB_FIFOSEL_MBW_32_BIT << R_USB_D0FIFOSEL_MBW_Pos);
    }
    else
#endif
    {
        fifosel_val |= (USB_FIFOSEL_MBW_16_BIT << R_USB_D0FIFOSEL_MBW_Pos);
    }

    *p_reg_dxfifosel = fifosel_val;

    /* Wait for FRDY */
    /* TODO: move this out of ISR, to avoid a dead-lock */
    r_usbh_pipe_wait_for_ready(p_ctrl, num);

    if (len)
    {
        r_usbh_pipe_write_packet(p_ctrl, p_buf, p_reg_dxfifo, len, access_bytes, num);
        p_pipe->buf = (uint8_t *) p_buf + len;
    }

    if (len < mps)
    {
        *p_reg_dxfifoctr = R_USB_D0FIFOCTR_BVAL_Msk;
    }

    *p_reg_dxfifosel = 0;
    FSP_HARDWARE_REGISTER_WAIT((*p_reg_dxfifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), 0);
    p_pipe->remaining = rem - len;

    return false;
}

/* Start a transfer (data stage or status stage / ZLP) on the default control pipe: configure the CFIFO
 * direction and kick off the first OUT packet, leaving IN data to be drained by the BRDY interrupt. */
static bool r_usbh_process_pipe0_xfer (usbh_instance_ctrl_t * const p_ctrl,
                                       uint8_t                      dev_addr,
                                       uint8_t                      ep_addr,
                                       void                       * p_buffer,
                                       uint16_t                     buflen)
{
    FSP_PARAMETER_NOT_USED(dev_addr);

    const uint32_t dir = r_usbh_edpt_dir(ep_addr);
#ifdef USB_HIGH_SPEED_MODULE
    const uint32_t access_bytes = USB_IS_USBHS(p_ctrl->module_number) ? 4 : 2;
#else
    const uint32_t access_bytes = 2;
#endif

    volatile uint16_t * p_reg_cfifosel;
    volatile uint16_t * p_reg_cfifoctr;
    volatile void     * p_reg_cfifo;
    volatile uint16_t * p_reg_dcpctr;
    volatile uint16_t * p_reg_dcpcfg;
    volatile uint16_t * p_reg_usbreq;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_cfifosel = &R_USB_HS0->CFIFOSEL;
        p_reg_cfifoctr = &R_USB_HS0->CFIFOCTR;
        p_reg_cfifo    = (volatile void *) &R_USB_HS0->CFIFO;
        p_reg_dcpctr   = &R_USB_HS0->DCPCTR;
        p_reg_dcpcfg   = &R_USB_HS0->DCPCFG;
        p_reg_usbreq   = &R_USB_HS0->USBREQ;
    }
    else
#endif
    {
        p_reg_cfifosel = &R_USB_FS0->CFIFOSEL;
        p_reg_cfifoctr = &R_USB_FS0->CFIFOCTR;
        p_reg_cfifo    = (volatile void *) &R_USB_FS0->CFIFO;
        p_reg_dcpctr   = &R_USB_FS0->DCPCTR;
        p_reg_dcpcfg   = &R_USB_FS0->DCPCFG;
        p_reg_usbreq   = &R_USB_FS0->USBREQ;
    }

    /* Configure FIFO with optimal MBW based on module type */
    uint16_t fifosel = 0;

#ifdef USB_HIGH_SPEED_MODULE
    if (access_bytes == 4)
    {
        fifosel = (USB_FIFOSEL_MBW_32_BIT << R_USB_CFIFOSEL_MBW_Pos);
    }
    else
#endif
    {
        fifosel = (USB_FIFOSEL_MBW_16_BIT << R_USB_CFIFOSEL_MBW_Pos);
    }

    /* configure fifo direction and access unit settings */
    if (USB_DIR_OUT == dir)
    {
        fifosel |= R_USB_CFIFOSEL_ISEL_Msk;
    }

    *p_reg_cfifosel = fifosel;
    FSP_HARDWARE_REGISTER_WAIT(*p_reg_cfifosel, fifosel);

    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[0];
    p_pipe->ep        = ep_addr;
    p_pipe->length    = buflen;
    p_pipe->remaining = buflen;

    if (buflen)
    {
        p_pipe->buf = p_buffer;
        if (USB_DIR_OUT == dir)
        {
            /* OUT */
            r_usbh_pipe0_xfer_out(p_ctrl);
        }
    }
    else
    {
        /* ZLP */
        p_pipe->buf = NULL;
        if (USB_DIR_OUT == dir)
        {
            /* OUT */
            *p_reg_cfifoctr = R_USB_CFIFOCTR_BVAL_Msk;
        }

        /*
         * TODO: Problem: SQSET (sequence toggle bit initialization) is only set for zero-length packets,
         * not for regular data stage transfers.
         *
         * Hardware Manual Reference (Page 100, Section 39.2.6.2):
         *      "Set SQSET to 1 before starting a new control transfer to initialize the DATA toggle to DATA1."
         * Recommended Fix:
         *  if (dir != ((*p_reg_dcpcfg & R_USB_DCPCFG_DIR_Msk) >> R_USB_DCPCFG_DIR_Pos))
         *  {
         *      *p_reg_dcpctr |= R_USB_DCPCTR_SQSET_Msk;
         *      *p_reg_dcpcfg  = (dir) ?
         *                       (*p_reg_dcpcfg & (~R_USB_DCPCFG_DIR_Msk)) :
         *                       (*p_reg_dcpcfg | R_USB_DCPCFG_DIR_Msk);
         *  }
         */

        if (dir == ((*p_reg_dcpcfg & R_USB_DCPCFG_DIR_Msk) >> R_USB_DCPCFG_DIR_Pos))
        {
            *p_reg_dcpctr |= R_USB_DCPCTR_SQSET_Msk;
            *p_reg_dcpcfg  = (dir) ?
                             (*p_reg_dcpcfg & (~R_USB_DCPCFG_DIR_Msk)) :
                             (*p_reg_dcpcfg | R_USB_DCPCFG_DIR_Msk);
        }
    }

    *p_reg_dcpctr = USB_PIPE_CTR_PID_BUF << R_USB_PIPE_CTR_PID_Pos;

    return true;
}

/* Start a transfer on a non-control pipe. For OUT, write the first packet (or a ZLP); for IN, arm the
 * transaction counter and set the pipe to BUF so the controller fetches data. */
static bool r_usbh_process_pipe_xfer (usbh_instance_ctrl_t * const p_ctrl,
                                      uint8_t                      dev_addr,
                                      uint8_t                      ep_addr,
                                      void                       * p_buffer,
                                      uint16_t                     buflen)
{
    const uint32_t epn = r_usbh_edpt_number(ep_addr);
    const uint32_t dir = r_usbh_edpt_dir(ep_addr);
    const uint32_t num = g_uhc_data[p_ctrl->module_number].ep[dev_addr - 1][dir][epn - 1];

    FSP_ASSERT(num);

    volatile uint16_t * p_reg_dxfifosel;
    volatile uint16_t * p_reg_dxfifoctr;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        if (dir == USB_DIR_IN)
        {
            p_reg_dxfifosel = &R_USB_HS0->D0FIFOSEL;
            p_reg_dxfifoctr = &R_USB_HS0->D0FIFOCTR;
        }
        else
        {
            /* OUT */
            p_reg_dxfifosel = &R_USB_HS0->D1FIFOSEL;
            p_reg_dxfifoctr = &R_USB_HS0->D1FIFOCTR;
        }
    }
    else
#endif
    {
        if (dir == USB_DIR_IN)
        {
            p_reg_dxfifosel = &R_USB_FS0->D0FIFOSEL;
            p_reg_dxfifoctr = &R_USB_FS0->D0FIFOCTR;
        }
        else
        {
            p_reg_dxfifosel = &R_USB_FS0->D1FIFOSEL;
            p_reg_dxfifoctr = &R_USB_FS0->D1FIFOCTR;
        }
    }

    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[num];
    p_pipe->buf       = p_buffer;
    p_pipe->length    = buflen;
    p_pipe->remaining = buflen;

    if (USB_DIR_OUT == dir)
    {
        /* OUT */
        if (buflen)
        {
            r_usbh_pipe_xfer_out(p_ctrl, num);
        }
        else
        {
            /* ZLP */
            *p_reg_dxfifosel = num;
            r_usbh_pipe_wait_for_ready(p_ctrl, num);
            *p_reg_dxfifoctr = R_USB_D0FIFOCTR_BVAL_Msk | R_USB_CFIFOCTR_BCLR_Msk;
            *p_reg_dxfifosel = 0;

            FSP_HARDWARE_REGISTER_WAIT((*p_reg_dxfifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), 0);
        }
    }
    else
    {
        volatile uint16_t          * p_reg_pipectr = r_usbh_get_pipectr(p_ctrl, num);
        volatile usb_reg_pipetre_t * p_reg_pipetr  = r_usbh_get_pipetre(p_ctrl, num);
        if (p_reg_pipetr)
        {
            const uint32_t mps = r_usbh_edpt_max_packet_size(p_ctrl, num);
            if (*p_reg_pipectr & R_USB_PIPE_CTR_PID_Msk)
            {
                *p_reg_pipectr = USB_PIPE_CTR_PID_NAK << R_USB_PIPE_CTR_PID_Pos;
            }

            p_reg_pipetr->TRE  = R_USB_PIPE_TR_E_TRCLR_Msk;
            p_reg_pipetr->TRN  = (buflen + mps - 1) / mps;
            p_reg_pipetr->TRE |= R_USB_PIPE_TR_E_TRENB_Msk;
        }

        *p_reg_pipectr = USB_PIPE_CTR_PID_BUF << R_USB_PIPE_CTR_PID_Pos;
    }

    return true;
}

/* Dispatch a transfer to the control-pipe or generic-pipe handler based on the endpoint number. */
static bool r_usbh_process_edpt_xfer (usbh_instance_ctrl_t * const p_ctrl,
                                      uint8_t                      dev_addr,
                                      uint8_t                      ep_addr,
                                      void                       * p_buffer,
                                      uint16_t                     buflen)
{
    const uint32_t epn = r_usbh_edpt_number(ep_addr);
    if (0 == epn)
    {
        return r_usbh_process_pipe0_xfer(p_ctrl, dev_addr, ep_addr, p_buffer, buflen);
    }
    else
    {
        return r_usbh_process_pipe_xfer(p_ctrl, dev_addr, ep_addr, p_buffer, buflen);
    }
}

/* Invoke the user callback with a ::USBH_EVENT_DEVICE_REMOVE event. */
static inline void r_usbh_event_device_remove_notify (usbh_instance_ctrl_t * const p_ctrl)
{
    usbh_callback_arg_t   args;
    usbh_callback_arg_t * p_args = p_ctrl->p_callback_memory;

    if (NULL == p_ctrl->p_callback)
    {
        return;
    }

    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->module_number = p_ctrl->module_number;
    p_args->p_context     = p_ctrl->p_context;
    p_args->event         = (usbh_event_t) {
        .event_id = USBH_EVENT_DEVICE_REMOVE,
        .remove   =
        {
            .hub_addr = 0,
            .hub_port = 0
        }
    };

    if (p_ctrl->p_callback != NULL)
    {
        p_ctrl->p_callback(p_args);
    }
}

/* Handle the buffer-empty (BEMP) interrupt for the control pipe: push the next OUT packet and, once the
 * data stage is done, notify the application. */
static void r_usbh_process_pipe0_bemp (usbh_instance_ctrl_t * const p_ctrl)
{
    bool completed = r_usbh_pipe0_xfer_out(p_ctrl);
    if (completed)
    {
        pipe_state_t * pipe = &g_uhc_data[p_ctrl->module_number].pipe[0];
        r_usbh_event_xfer_complete_notify(
            p_ctrl,
            pipe->dev,
            r_usbh_edpt_addr(0, USB_DIR_OUT),
            pipe->length - pipe->remaining,
            USB_XFER_RESULT_SUCCESS);
    }
}

/* Handle the not-ready (NRDY) interrupt for pipe @p num: map the pipe PID (STALL/NAK) to a transfer
 * result and report it to the application. */
static void r_usbh_process_pipe_nrdy (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    usb_xfer_result_t   result;
    uint16_t volatile * p_reg_pipectr = r_usbh_get_pipectr(p_ctrl, num);

    switch ((*p_reg_pipectr & R_USB_PIPE_CTR_PID_Msk) >> R_USB_PIPE_CTR_PID_Pos)
    {
        case USB_PIPE_CTR_PID_STALL:
        {
            result = USB_XFER_RESULT_STALLED;
            break;
        }

        case USB_PIPE_CTR_PID_STALL2:
        {
            result = USB_XFER_RESULT_STALLED;
            break;
        }

        case USB_PIPE_CTR_PID_NAK:
        {
            result = USB_XFER_RESULT_FAILED;
            break;
        }

        default:
        {
            return;
        }
    }

    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[num];
    r_usbh_event_xfer_complete_notify(p_ctrl,
                                      p_pipe->dev,
                                      p_pipe->ep,
                                      p_pipe->length - p_pipe->remaining,
                                      result);
}

/* Handle the buffer-ready (BRDY) interrupt for pipe @p num: transfer the next IN/OUT packet and, when the
 * transfer is complete, report it to the application. */
static void r_usbh_process_pipe_brdy (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[num];
    const uint32_t dir    = r_usbh_edpt_dir(p_pipe->ep);
    bool           completed;

    if (USB_DIR_IN == dir)
    {
        /* IN */
        if (num)
        {
            completed = r_usbh_pipe_xfer_in(p_ctrl, num);
        }
        else
        {
            completed = r_usbh_pipe0_xfer_in(p_ctrl);
        }
    }
    else
    {
        completed = r_usbh_pipe_xfer_out(p_ctrl, num);
    }

    if (completed)
    {
        r_usbh_event_xfer_complete_notify(p_ctrl,
                                          p_pipe->dev,
                                          p_pipe->ep,
                                          p_pipe->length - p_pipe->remaining,
                                          USB_XFER_RESULT_SUCCESS);
    }
}

/* Forcibly stop the transfer on pipe @p num: set NAK, disable its interrupts, release the FIFO port and
 * clear the transaction counter. */
static void r_usbh_process_terminate_xfer (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    volatile usb_reg_pipetre_t * p_reg_pipetr  = r_usbh_get_pipetre(p_ctrl, num);
    volatile uint16_t          * p_reg_pipectr = r_usbh_get_pipectr(p_ctrl, num);
    volatile uint16_t          * p_reg_dxfifosel;
    volatile uint16_t          * p_reg_dxfifoctr;
    pipe_state_t               * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[num];
    const uint32_t               dir    = r_usbh_edpt_dir(p_pipe->ep);

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        if (dir == USB_DIR_IN)
        {
            p_reg_dxfifosel = &R_USB_HS0->D0FIFOSEL;
            p_reg_dxfifoctr = &R_USB_HS0->D0FIFOCTR;
        }
        else
        {
            p_reg_dxfifosel = &R_USB_HS0->D1FIFOSEL;
            p_reg_dxfifoctr = &R_USB_HS0->D1FIFOCTR;
        }
    }
    else
#endif
    {
        if (dir == USB_DIR_IN)
        {
            p_reg_dxfifosel = &R_USB_FS0->D0FIFOSEL;
            p_reg_dxfifoctr = &R_USB_FS0->D0FIFOCTR;
        }
        else
        {
            p_reg_dxfifosel = &R_USB_FS0->D1FIFOSEL;
            p_reg_dxfifoctr = &R_USB_FS0->D1FIFOCTR;
        }
    }

    /* Set this PIPE to NAK */
    *p_reg_pipectr &= ~R_USB_PIPE_CTR_PID_Msk;

    /* Clear CURPIPE first */
    *p_reg_dxfifosel &= ~R_USB_D0FIFOSEL_CURPIPE_Msk;
    FSP_HARDWARE_REGISTER_WAIT((*p_reg_dxfifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), 0);

    /* Switch to the pipe that need to terminate xfer */
    *p_reg_dxfifosel |= (num << R_USB_D0FIFOSEL_CURPIPE_Pos);
    FSP_HARDWARE_REGISTER_WAIT((*p_reg_dxfifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), num);

    /* Clear buffer and change it to NAK */
    *p_reg_dxfifoctr = R_USB_CFIFOCTR_BCLR_Msk;

    /* Clear transaction counter */
    p_reg_pipetr->TRE &= ~R_USB_PIPE_TR_E_TRENB_Msk;
    p_reg_pipetr->TRE |= R_USB_PIPE_TR_E_TRCLR_Msk;

    *p_reg_dxfifosel &= ~R_USB_D0FIFOSEL_CURPIPE_Msk;
    FSP_HARDWARE_REGISTER_WAIT((*p_reg_dxfifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), 0);
}

/* Forcibly stop the current control transfer: set the default control pipe to NAK and clear the CFIFO. */
static void r_usbh_process_terminate_control_xfer (usbh_instance_ctrl_t * const p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        /* Set NAK */
        R_USB_HS0->DCPCTR = USB_PIPE_CTR_PID_NAK << R_USB_DCPCTR_PID_Pos;

        /* Clear FIFO port */
        R_USB_HS0->CFIFOCTR = R_USB_CFIFOCTR_BCLR_Msk;
    }
    else
#endif
    {
        /* Set NAK */
        R_USB_FS0->DCPCTR = USB_PIPE_CTR_PID_NAK << R_USB_DCPCTR_PID_Pos;

        /* Clear FIFO port */
        R_USB_FS0->CFIFOCTR = R_USB_CFIFOCTR_BCLR_Msk;
    }
}

/* Enable the host interrupt sources (BRDY/NRDY/BEMP, SACK/SIGN, attach/detach) and clear pending status. */
static inline void r_usbh_interrupt_configure (usbh_instance_ctrl_t * p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_USB_HS0->INTENB0 = R_USB_INTSTS0_BRDY_Msk | R_USB_INTSTS0_NRDY_Msk |
                             R_USB_INTSTS0_BEMP_Msk;
        R_USB_HS0->INTENB1 = R_USB_INTENB1_SACKE_Msk | R_USB_INTENB1_SIGNE_Msk |
                             R_USB_INTSTS1_ATTCH_Msk;
        R_USB_HS0->BEMPENB = 1;
        R_USB_HS0->NRDYENB = 1;
        R_USB_HS0->BRDYENB = 1;
        R_USB_HS0->INTSTS0 = 0;
        R_USB_HS0->INTSTS1 = 0;
    }
    else
#endif
    {
        R_USB_FS0->INTENB0 = R_USB_INTSTS0_BRDY_Msk | R_USB_INTSTS0_NRDY_Msk |
                             R_USB_INTSTS0_BEMP_Msk;
        R_USB_FS0->INTENB1 = R_USB_INTSTS1_SACK_Msk | R_USB_INTSTS1_SIGN_Msk |
                             R_USB_INTSTS1_ATTCH_Msk | R_USB_INTSTS1_DTCH_Msk;
        R_USB_FS0->BEMPENB = 1;
        R_USB_FS0->NRDYENB = 1;
        R_USB_FS0->BRDYENB = 1;
        R_USB_FS0->INTSTS0 = 0;
        R_USB_FS0->INTSTS1 = 0;
    }
}

/* Enable and configure the NVIC interrupt(s) for the selected USB module. */
static inline void r_usbh_interrupt_enable (usbh_instance_ctrl_t * p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_BSP_IrqEnable(p_ctrl->p_cfg->hs_irq);
    }
    else
#endif
    {
        R_BSP_IrqEnable(p_ctrl->p_cfg->irq);
        R_BSP_IrqEnable(p_ctrl->p_cfg->irq_r);
    }
}

/* Disable the NVIC interrupt(s) for the selected USB module. */
static inline void r_usbh_interrupt_disable (usbh_instance_ctrl_t * p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_BSP_IrqDisable(p_ctrl->p_cfg->hs_irq);
    }
    else
#endif
    {
        R_BSP_IrqDisable(p_ctrl->p_cfg->irq);
        R_BSP_IrqDisable(p_ctrl->p_cfg->irq_r);
    }
}

/***********************************************************************************************************************
 * Interrupt handler                                                                                                  *
 **********************************************************************************************************************/

/**
 * @brief USB host interrupt service routine.
 *
 * Shared entry point for the USB host interrupts. Reads and clears the INTSTS0/INTSTS1 status, then
 * dispatches the active sources: setup ACK/error (SACK/SIGN), device attach/detach (ATTCH/DTCH) and the
 * per-pipe buffer-empty, not-ready and buffer-ready events (BEMP/NRDY/BRDY). Transfer completions and
 * attach/detach are forwarded to the application through the user callback.
 */
void r_usbh_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    usbh_instance_ctrl_t * p_ctrl = R_FSP_IsrContextGet(irq);

    volatile uint16_t * p_reg_intsts0;
    volatile uint16_t * p_reg_intsts1;
    volatile uint16_t * p_reg_intenb0;
    volatile uint16_t * p_reg_intenb1;
    volatile uint16_t * p_reg_dcpctr;
    volatile uint16_t * p_reg_dcpmaxp;
    volatile uint16_t * p_reg_dvstctr0;
    volatile uint16_t * p_reg_bempsts;
    volatile uint16_t * p_reg_nrdyenb;
    volatile uint16_t * p_reg_nrdysts;
    volatile uint16_t * p_reg_brdyenb;
    volatile uint16_t * p_reg_brdysts;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_intsts0  = &R_USB_HS0->INTSTS0;
        p_reg_intsts1  = &R_USB_HS0->INTSTS1;
        p_reg_intenb0  = &R_USB_HS0->INTENB0;
        p_reg_intenb1  = &R_USB_HS0->INTENB1;
        p_reg_dcpctr   = &R_USB_HS0->DCPCTR;
        p_reg_dcpmaxp  = &R_USB_HS0->DCPMAXP;
        p_reg_dvstctr0 = &R_USB_HS0->DVSTCTR0;
        p_reg_bempsts  = &R_USB_HS0->BEMPSTS;
        p_reg_nrdyenb  = &R_USB_HS0->NRDYENB;
        p_reg_nrdysts  = &R_USB_HS0->NRDYSTS;
        p_reg_brdyenb  = &R_USB_HS0->BRDYENB;
        p_reg_brdysts  = &R_USB_HS0->BRDYSTS;
    }
    else
#endif
    {
        p_reg_intsts0  = &R_USB_FS0->INTSTS0;
        p_reg_intsts1  = &R_USB_FS0->INTSTS1;
        p_reg_intenb0  = &R_USB_FS0->INTENB0;
        p_reg_intenb1  = &R_USB_FS0->INTENB1;
        p_reg_dcpctr   = &R_USB_FS0->DCPCTR;
        p_reg_dcpmaxp  = &R_USB_FS0->DCPMAXP;
        p_reg_dvstctr0 = &R_USB_FS0->DVSTCTR0;
        p_reg_bempsts  = &R_USB_FS0->BEMPSTS;
        p_reg_nrdyenb  = &R_USB_FS0->NRDYENB;
        p_reg_nrdysts  = &R_USB_FS0->NRDYSTS;
        p_reg_brdyenb  = &R_USB_FS0->BRDYENB;
        p_reg_brdysts  = &R_USB_FS0->BRDYSTS;
    }

    const uint16_t status0 = *p_reg_intsts0 & *p_reg_intenb0;
    const uint16_t status1 = *p_reg_intsts1 & *p_reg_intenb1;

    /* clear active bits except VALID (don't write 0 to already cleared bits
     * according to the HW manual) */
    *p_reg_intsts1 &= ~(R_USB_INTSTS1_SACK_Msk | R_USB_INTSTS1_SIGN_Msk |
                        R_USB_INTSTS1_ATTCH_Msk | R_USB_INTSTS1_DTCH_Msk);

    *p_reg_intsts0 &= ~(R_USB_INTSTS0_BRDY_Msk | R_USB_INTSTS0_NRDY_Msk |
                        R_USB_INTSTS0_BEMP_Msk);

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    if (status1 & R_USB_INTSTS1_SACK_Msk)
    {
        /* Set DATA1 in advance for the next transfer. */
        *p_reg_dcpctr |= USB_SETBIT(R_USB_DCPCTR_SQSET_Pos);
        r_usbh_event_xfer_complete_notify(p_ctrl,
                                          (*p_reg_dcpmaxp & R_USB_DCPMAXP_DEVSEL_Msk) >> R_USB_DCPMAXP_DEVSEL_Pos,
                                          r_usbh_edpt_addr(0, USB_DIR_OUT),
                                          8,
                                          USB_XFER_RESULT_SUCCESS);
    }

    if (status1 & R_USB_INTSTS1_SIGN_Msk)
    {
        r_usbh_event_xfer_complete_notify(p_ctrl,
                                          (*p_reg_dcpmaxp & R_USB_DCPMAXP_DEVSEL_Msk) >> R_USB_DCPMAXP_DEVSEL_Pos,
                                          r_usbh_edpt_addr(0, USB_DIR_OUT),
                                          8,
                                          USB_XFER_RESULT_FAILED);
    }

    if (status1 & R_USB_INTSTS1_ATTCH_Msk)
    {
        usb_speed_t speed;

        /* Enable USB bus */
        *p_reg_dvstctr0 |= R_USB_DVSTCTR0_UACT_Msk;

        /* Disable ATTCH interrupt */
        *p_reg_intenb1 &= ~R_USB_INTSTS1_ATTCH_Msk;

        uint16_t lnst = R_USB_HS0->SYSSTS0_b.LNST;

        switch (lnst)
        {
            case USB_FS_JSTS:
            {
                speed = USB_SPEED_FS;
                break;
            }

            case USB_LS_JSTS:
            {
                speed = USB_SPEED_LS;
                break;
            }

            case USB_SE1:
            case USB_SE0:
            default:
            {
                speed = USB_SPEED_INVALID;
                break;
            }
        }

        /* Enable DTCH interrupt */
        *p_reg_intenb1 |= R_USB_INTSTS1_DTCH_Msk;

        r_usbh_event_device_attach_notify(p_ctrl, speed);
    }
    else if (status1 & R_USB_INTSTS1_DTCH_Msk)
    {
        *p_reg_dvstctr0 &= ~R_USB_DVSTCTR0_UACT_Msk;

        if (*p_reg_dcpctr & R_USB_DCPCTR_SUREQ_Msk)
        {
            *p_reg_dcpctr |= R_USB_DCPCTR_SUREQCLR_Msk;
        }

        *p_reg_intenb1 &= ~R_USB_INTSTS1_DTCH_Msk;
        *p_reg_intenb1 |= R_USB_INTSTS1_ATTCH_Msk;

        r_usbh_event_device_remove_notify(p_ctrl);
    }
    else
    {
        /* Do nothing */
    }

    if (status0 & R_USB_INTSTS0_BEMP_Msk)
    {
        const uint16_t status = *p_reg_bempsts;
        *p_reg_bempsts = 0;
        if (status & USB_SETBIT(0))
        {
            r_usbh_process_pipe0_bemp(p_ctrl);
        }
    }

    if (status0 & R_USB_INTSTS0_NRDY_Msk)
    {
        const uint16_t enable = *p_reg_nrdyenb;
        uint16_t       status = *p_reg_nrdysts & enable;

        *p_reg_nrdysts = ~status;

        while (status)
        {
            const uint32_t num = CTZ(status);
            r_usbh_process_pipe_nrdy(p_ctrl, num);
            status &= ~USB_SETBIT(num);
        }
    }

    if (status0 & R_USB_INTSTS0_BRDY_Msk)
    {
        const uint16_t enable = *p_reg_brdyenb;
        uint16_t       status = *p_reg_brdysts & enable;

        *p_reg_brdysts = ~status;

        while (status)
        {
            const uint32_t num = CTZ(status);
            r_usbh_process_pipe_brdy(p_ctrl, num);
            status &= ~USB_SETBIT(num);
        }
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
