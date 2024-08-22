/*
 * Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_usb_host.h"
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define USBH_OPEN                     (0x55534248) /* USBH in ASCII */
#define USB_HS_MODULE_NUMBER_START    (1)
#define USB_MODULE_NUM                (2)

#define USB_SETBIT(n)    (1UL << (n))

#if defined(__GNUC__)
 #define CTZ(x)          (__builtin_ctz(x))
#else
 #error "Compiler not supported"
#endif

#define USB_DIRPD                   (0x0001U)                     /* b0: Power down control */
#define USB_PLLRESET                (0x0002U)                     /* b1: PLL reset control */
#define USB_CLKSEL                  (0x0030U)                     /* b5-4: System clock setting */
#define USB_REPSEL_16               (0x0100U)                     /* 16 sec */
#define USB_CLKSEL_20               (0x0020U)                     /* 20MHz */
#define USB_HSEB                    (0x8000U)                     /* b15: CL only mode bit */
#define USB_PLLLOCK                 (0x0001U)

#define USB_SIGN                    (0x0020U)                     /* b5: Setup ignore interrupt */
#define USB_SACK                    (0x0010U)                     /* b4: Setup ack interrupt */
#define USB_SIGNE                   (0x0020U)                     /* b5: SETUP IGNORE interrupt */
#define USB_SACKE                   (0x0010U)                     /* b4: SETUP ACK interrupt */
#define INTSTS1_MASK                (0xD870U)                     /* INTSTS1 Reserved bit mask */
#define USB_UACT                    (0x0010U)                     /* b4: USB bus enable */
#define USB_RESUME                  (0x0020U)                     /* b5: Resume enable */
#define USB_USBRST                  (0x0040U)                     /* b6: USB reset enable */
#define USB_HSPROC                  (0x0004U)                     /* HS handshake processing */
#define USB_RHST                    (0x0007U)                     /* b2-0: Reset handshake status */
#define USB_SUSPENDM                (0x4000U)                     /* b14: UTMI SuspendM control */
#define USB_SQSET                   (0x0080U)                     /* b7: Sequence bit set */

/* System Configuration Control Register */
#define USB_USBE                    (0x0001U)                     /* b0: USB module enable */
#define USB_DPRPU                   (0x0010U)                     /* b4: D+ pull up control */
#define USB_DRPD                    (0x0020U)                     /* b5: D+/D- pull down control */
#define USB_DCFM                    (0x0040U)                     /* b6: Function select */

/* PIPE_CTR */
#define USB_PIPE_CTR_ACLRM_Pos      (9UL)                         /* ACLRM (Bit 9) */
#define USB_PIPE_CTR_ACLRM_Msk      (0x200UL)                     /* ACLRM (Bitfield-Mask: 0x01) */
#define USB_PIPE_CTR_SQCLR_Pos      (8UL)                         /* SQCLR (Bit 8) */
#define USB_PIPE_CTR_SQCLR_Msk      (0x100UL)                     /* SQCLR (Bitfield-Mask: 0x01) */
#define USB_PIPE_CTR_PID_Pos        (0UL)                         /* PID (Bit 0) */
#define USB_PIPE_CTR_PID_Msk        (0x3UL)                       /* PID (Bitfield-Mask: 0x03) */

/* PIPECFG */
#define USB_PIPECFG_TYPE_Pos        (14UL)                        /* TYPE (Bit 14) */
#define USB_PIPECFG_TYPE_Msk        (0xc000UL)                    /* TYPE (Bitfield-Mask: 0x03) */
#define USB_PIPECFG_DBLB_Pos        (9UL)                         /* DBLB (Bit 9) */
#define USB_PIPECFG_DBLB_Msk        (0x200UL)                     /* DBLB (Bitfield-Mask: 0x01) */
#define USB_PIPECFG_SHTNAK_Pos      (7UL)                         /* SHTNAK (Bit 7) */
#define USB_PIPECFG_SHTNAK_Msk      (0x80UL)                      /* SHTNAK (Bitfield-Mask: 0x01) */

/* INTSTS0 */
#define USB_INTSTS0_BEMP_Pos        (10UL)                        /* BEMP (Bit 10) */
#define USB_INTSTS0_BEMP_Msk        (0x400UL)                     /* BEMP (Bitfield-Mask: 0x01) */
#define USB_INTSTS0_NRDY_Pos        (9UL)                         /* NRDY (Bit 9) */
#define USB_INTSTS0_NRDY_Msk        (0x200UL)                     /* NRDY (Bitfield-Mask: 0x01) */
#define USB_INTSTS0_BRDY_Pos        (8UL)                         /* BRDY (Bit 8) */
#define USB_INTSTS0_BRDY_Msk        (0x100UL)                     /* BRDY (Bitfield-Mask: 0x01) */

/* INTSTS1 */
#define USB_INTSTS1_OVRCR_Pos       (15UL)                        /* OVRCR (Bit 15) */
#define USB_INTSTS1_OVRCR_Msk       (0x8000UL)                    /* OVRCR (Bitfield-Mask: 0x01) */
#define USB_INTSTS1_BCHG_Pos        (14UL)                        /* BCHG (Bit 14) */
#define USB_INTSTS1_BCHG_Msk        (0x4000UL)                    /* BCHG (Bitfield-Mask: 0x01) */
#define USB_INTSTS1_DTCH_Pos        (12UL)                        /* DTCH (Bit 12) */
#define USB_INTSTS1_DTCH_Msk        (0x1000UL)                    /* DTCH (Bitfield-Mask: 0x01) */
#define USB_INTSTS1_ATTCH_Pos       (11UL)                        /* ATTCH (Bit 11) */
#define USB_INTSTS1_ATTCH_Msk       (0x800UL)                     /* ATTCH (Bitfield-Mask: 0x01) */
#define USB_INTSTS1_L1RSMEND_Pos    (9UL)                         /* L1RSMEND (Bit 9) */
#define USB_INTSTS1_L1RSMEND_Msk    (0x200UL)                     /* L1RSMEND (Bitfield-Mask: 0x01) \
                                                                   */
#define USB_INTSTS1_EOFERR_Pos      (6UL)                         /* EOFERR (Bit 6) */
#define USB_INTSTS1_EOFERR_Msk      (0x40UL)                      /* EOFERR (Bitfield-Mask: 0x01) */
#define USB_INTSTS1_SIGN_Pos        (5UL)                         /* SIGN (Bit 5) */
#define USB_INTSTS1_SIGN_Msk        (0x20UL)                      /* SIGN (Bitfield-Mask: 0x01) */
#define USB_INTSTS1_SACK_Pos        (4UL)                         /* SACK (Bit 4) */
#define USB_INTSTS1_SACK_Msk        (0x10UL)                      /* SACK (Bitfield-Mask: 0x01) */

#define USB_PIPE_CTR_PID_NAK        (0U << USB_PIPE_CTR_PID_Pos)  /* NAK response */
#define USB_PIPE_CTR_PID_BUF        (1U << USB_PIPE_CTR_PID_Pos)  /* BUF response (depends buffer state) */
#define USB_PIPE_CTR_PID_STALL      (2U << USB_PIPE_CTR_PID_Pos)  /* STALL response \
                                                                   */
#define USB_PIPE_CTR_PID_STALL2     (3U << USB_PIPE_CTR_PID_Pos)  /* Also STALL response */

#define USB_CFIFOSEL_ISEL_Pos       (5UL)                         /* ISEL (Bit 5) */

#define USB_DEVADD_USBSPD_Pos       (6UL)                         /* USBSPD (Bit 6) */
#define USB_DEVADD_USBSPD_Msk       (0xc0UL)                      /* USBSPD (Bitfield-Mask: 0x03) */
#define USB_DEVADD_USBSPD_LS        (1U << USB_DEVADD_USBSPD_Pos) /* Target Device Low-speed */
#define USB_DEVADD_USBSPD_FS        (2U << USB_DEVADD_USBSPD_Pos) /* Target Device Full-speed */
#define USB_DEVADD_USBSPD_HS        (3U << USB_DEVADD_USBSPD_Pos) /* Target Device Full-speed */

#define USB_PIPECFG_TYPE_BULK       (1U << USB_PIPECFG_TYPE_Pos)
#define USB_PIPECFG_TYPE_INT        (2U << USB_PIPECFG_TYPE_Pos)
#define USB_PIPECFG_TYPE_ISO        (3U << USB_PIPECFG_TYPE_Pos)

#define USB_CFIFOCTR_BVAL_Pos       (15UL)                        /* BVAL (Bit 15) */
#define USB_CFIFOCTR_BVAL_Msk       (0x8000UL)                    /* BVAL (Bitfield-Mask: 0x01) */

#define USB_CFIFOSEL_ISEL_WRITE     (1U << USB_CFIFOSEL_ISEL_Pos) /* FIFO write AKA TX*/

#define USB_CFIFOSEL_MBW_Pos        (10UL)                        /* MBW (Bit 10) */

#define USB_FIFOSEL_MBW_8BIT        (0U << USB_CFIFOSEL_MBW_Pos)  /* 8-bit width */
#define USB_FIFOSEL_MBW_16BIT       (1U << USB_CFIFOSEL_MBW_Pos)  /* 16-bit width */
#define USB_FIFOSEL_MBW_32BIT       (2U << USB_CFIFOSEL_MBW_Pos)  /* 32-bit width */

#define USB_D0FIFOCTR_BCLR_Msk      (0x4000UL)                    /* BCLR (Bitfield-Mask: 0x01) */
#define USB_CFIFOCTR_BCLR_Msk       (0x4000UL)                    /* BCLR (Bitfield-Mask: 0x01) */

#define USB_D0FIFOCTR_BVAL_Pos      (15UL)                        /* BVAL (Bit 15) */
#define USB_D0FIFOCTR_BVAL_Msk      (0x8000UL)                    /* BVAL (Bitfield-Mask: 0x01) */

#define USB_DEVADDRBIT              (12U)
#define USB_UPPHUB                  (0x7800U)                     /* b14-11: HUB register */
#define USB_HUBPORT                 (0x0700U)                     /* b10-8: HUB port */
#define USB_USBSPD                  (0x00C0U)                     /* b7-6: Device speed */
#define USB_DEVICE_0                (0x0000U)                     /* Device address 0 */
#define USB_DEFPACKET               (0x0040U)                     /* Default DCP Max packet size */

#define USB_STATUS_ATTACH           (1 << 0)
#define USB_STATUS_DETACH           (1 << 1)
#define USB_STATUS_EOFERR           (1 << 2)
#define USB_STATUS_OVRCR            (1 << 3)

#define USB_DVSTCTR0_RHST_LS        (1U) /*  Low-speed connection */
#define USB_DVSTCTR0_RHST_FS        (2U) /*  Full-speed connection */
#define USB_DVSTCTR0_RHST_HS        (3U) /*  Full-speed connection */

#define USB_HS_DEVADD_NUM           (0x0A)
#define USB_FS_DEVADD_NUM           (0x05)

#define USB_PIPE_COUNT              10
#define USB_DEVICE_NUM              4

#define USB_MIN(_x, _y)    (((_x) < (_y)) ? (_x) : (_y))
#define USB_MAX(_x, _y)    (((_x) > (_y)) ? (_x) : (_y))

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef __PACKED_UNION
{
    struct
    {
        volatile uint16_t u8       : 8;
        volatile          uint16_t : 0;
    };

    volatile uint16_t u16;
} hw_fifo_t;

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

typedef struct st_usbh_dev0
{
    uint8_t hub_addr;
    uint8_t hub_port;
    __PACKED_STRUCT
    {
        uint8_t          speed        : 4; /* packed speed to save footprint */
        volatile uint8_t enumerating  : 1; /* enumeration is in progress, false if not connected or all interfaces are configured */
        uint8_t          USB_RESERVED : 3;
    } usbh_dev0_info;
} usbh_dev0_t;

typedef struct st_uhc_data
{
    pipe_state_t pipe[10];
    uint8_t      ep[USB_DEVICE_NUM][2][USB_PIPE_COUNT]; /* a lookup table for a pipe index from an endpoint address */
    uint8_t      ctl_mps[USB_DEVICE_NUM];               /* EP0 max packet size for each device */
    usbh_dev0_t  dev0;
} uhc_data_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static inline uint8_t r_usbh_edpt_addr (uint8_t num, uint8_t dir)
{
    return (uint8_t) (num | (dir ? USB_DIR_IN_MASK : 0));
}

static inline uint8_t r_usbh_edpt_number (uint8_t addr)
{
    return (uint8_t) (addr & (~USB_DIR_IN_MASK));
}

static inline usb_dir_t r_usbh_edpt_dir (uint8_t addr)
{
    return (addr & USB_DIR_IN_MASK) ? USB_DIR_IN : USB_DIR_OUT;
}

static inline uint16_t r_usbh_edpt_packet_size (usb_desc_endpoint_t const * desc_ep)
{
    return (desc_ep->wMaxPacketSize) & 0x7FF;
}

static volatile uint16_t * r_usbh_get_pipectr(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static uint32_t            r_usbh_find_pipe(usbh_instance_ctrl_t * const p_ctrl, uint8_t xfer_type);
static fsp_err_t           r_usbh_hw_module_start(usbh_instance_ctrl_t * const p_ctrl);
static fsp_err_t           r_usbh_hw_init(usbh_instance_ctrl_t * const p_ctrl);
static fsp_err_t           r_usbh_module_register_clear(usbh_instance_ctrl_t * const p_ctrl);
static fsp_err_t           r_usbh_hw_module_stop(usbh_instance_ctrl_t * const p_ctrl);
static uint16_t            r_usb_chk_dev_addr(usbh_instance_ctrl_t * p_ctrl, uint16_t addr);
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
static bool     r_usbh_pipe_xfer_out(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static bool     r_usbh_pipe0_xfer_out(usbh_instance_ctrl_t * const p_ctrl);
static bool     r_usbh_pipe_xfer_in(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static bool     r_usbh_pipe0_xfer_in(usbh_instance_ctrl_t * const p_ctrl);
static void     r_usbh_pipe_write_packet(void * buf, volatile void * fifo, uint32_t len);
static void     r_usbh_pipe_read_packet(void * buf, volatile void * fifo, uint32_t len);
static uint16_t r_usbh_edpt_max_packet_size(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static uint16_t r_usbh_edpt0_max_packet_size(usbh_instance_ctrl_t * const p_ctrl);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
uhc_data_t g_uhc_data[USB_MODULE_NUM];

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/**
 * @brief Start USB module, configure correct operate mode and default pipe0
 *
 * @param p_api_ctrl    [in]
 * @param p_cfg         [in]
 *
 * @retval FSP_SUCCESS          on success
 * @retval FSP_ERR_UNSUPPORTED  if USB module just support FS only
 * @retval FSP_ERR_ALREADY_OPEN if USB module has opened
 */
fsp_err_t R_USBH_Open (usb_ctrl_t * const p_api_ctrl, usb_cfg_t const * const p_cfg)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ASSERT(p_cfg)
    FSP_ERROR_RETURN(0 == p_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* Make sure this channel exists. */
    FSP_ERROR_RETURN(USB_MODULE_NUM > p_cfg->module_number, FSP_ERR_IP_CHANNEL_NOT_PRESENT);
#endif

    p_ctrl->module_number = p_cfg->module_number;
    if (p_cfg->module_number < USB_HS_MODULE_NUMBER_START)
    {
        p_ctrl->p_reg = (void *) R_USB_FS0_BASE;
    }
    else
    {
        p_ctrl->p_reg = (void *) R_USB_HS0_BASE;
    }

    if (p_cfg->high_speed)
    {
        p_ctrl->max_speed = USB_SPEED_HS;
    }
    else
    {
        p_ctrl->max_speed = USB_SPEED_FS;
    }

#if USBD_CFG_PARAM_CHECKING_ENABLE
    if (USB_HS_MODULE_NUMBER_START != p_cfg->module_number)
    {
        return FSP_ERR_UNSUPPORTED;
    }
#endif

    p_ctrl->p_cfg             = p_cfg;
    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

    /* Start module */
    r_usbh_hw_module_start(p_ctrl);

    /* Initialize usb host hardware layer */
    r_usbh_hw_init(p_ctrl);

    if (p_cfg->hs_irq != BSP_IRQ_DISABLED)
    {
        R_BSP_IrqCfg(p_cfg->hs_irq, p_cfg->hsipl, p_ctrl);
    }

    memset(&g_uhc_data, 0, sizeof(uhc_data_t));

    p_ctrl->open = USBH_OPEN;

    return FSP_SUCCESS;
}

/**
 * @brief Get port status
 *
 * @param p_api_ctrl    [in]
 *
 * @retval status
 */
fsp_err_t R_USBH_PortStatusGet (usb_ctrl_t * const p_api_ctrl, usb_status_t * p_status)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ASSERT(p_status)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;
    *p_status = 0;

    uint16_t info = p_reg->INTSTS1;
    if ((info & USB_INTSTS1_OVRCR_Msk) != 0)
    {
        *p_status |= USB_STATUS_OVRCR;
    }

    if ((info & USB_INTSTS1_EOFERR_Msk) != 0)
    {
        *p_status |= USB_STATUS_EOFERR;
    }

    if ((info & USB_INTSTS1_ATTCH_Msk) != 0)
    {
        *p_status |= USB_STATUS_ATTACH;
    }

    if ((info & USB_INTSTS1_DTCH_Msk) != 0)
    {
        *p_status |= USB_STATUS_DETACH;
    }

    if ((info & USB_INTSTS1_SACK_Msk) != 0)
    {
        *p_status |= USB_STATUS_DETACH;
    }

    return FSP_SUCCESS;
}

/**
 * @brief Reset port
 *
 * @param p_api_ctrl    [in]
 *
 * @retval FSP_SUCCESS          on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_PortReset (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    R_USB_HS0_Type       * p_reg  = (R_USB_HS0_Type *) p_ctrl->p_reg;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg->DCPCTR = USB_PIPE_CTR_PID_NAK;

    FSP_HARDWARE_REGISTER_WAIT(p_reg->DCPCTR_b.PBUSY, 0);

    R_BSP_IrqDisable(p_ctrl->p_cfg->irq);

    p_reg->DVSTCTR0_b.UACT = 0;
    if (p_reg->DCPCTR_b.SUREQ)
    {
        p_reg->DCPCTR_b.SUREQCLR = 1;
    }

    R_BSP_IrqEnable(p_ctrl->p_cfg->irq);

    p_reg->DVSTCTR0_b.USBRST = 1;

    /* Reset should be asserted 10-20ms. */
    R_BSP_SoftwareDelay(20, BSP_DELAY_UNITS_MILLISECONDS);

    p_reg->DVSTCTR0_b.USBRST = 0;
    p_reg->DVSTCTR0_b.UACT   = 1;

    return FSP_SUCCESS;
}

/**
 * @brief Get usb device speed
 *
 * @param p_api_ctrl    [in]
 * @param p_speed       [out]
 *
 * @retval FSP_SUCCESS          on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_GetDeviceSpeed (usb_ctrl_t * const p_api_ctrl, usb_speed_t * p_speed)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ASSERT(p_speed)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    switch (p_reg->DVSTCTR0_b.RHST)
    {
        case USB_DVSTCTR0_RHST_HS:
        {
            *p_speed = USB_SPEED_HS;
            break;
        }

        case USB_DVSTCTR0_RHST_FS:
        {
            *p_speed = USB_SPEED_FS;
            break;
        }

        case USB_DVSTCTR0_RHST_LS:
        {
            *p_speed = USB_SPEED_LS;
            break;
        }

        default:
        {
            *p_speed = USB_SPEED_INVALID;
        }
    }

    g_uhc_data[p_ctrl->p_cfg->module_number].dev0.usbh_dev0_info.speed = *p_speed;

    return FSP_SUCCESS;
}

/**
 * @brief Release usb device
 *
 * @param p_api_ctrl    [in]
 *
 * @retval FSP_SUCCESS          on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_DeviceRelease (usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(dev_addr < USB_DEVICE_NUM);
#endif

    if (r_usb_chk_dev_addr(p_ctrl, dev_addr) != 0)
    {
        r_usbh_device_release(p_ctrl, dev_addr);

        return FSP_SUCCESS;
    }

    return FSP_ERR_ABORTED;
}

/**
 * @brief Setup send
 *
 * @param p_api_ctrl    [in]
 * @param dev_addr      [in]
 * @param setup_packet  [in]
 *
 * @retval FSP_SUCCESS          on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_SetupSend (usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr, uint8_t const setup_packet[8])
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(dev_addr < USB_DEVICE_NUM, FSP_ERR_INVALID_ARGUMENT);
#endif

    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    FSP_ERROR_RETURN(0 == p_reg->DCPCTR_b.SUREQ, FSP_ERR_USB_FAILED);

    p_reg->DCPCTR = USB_PIPE_CTR_PID_NAK;

    g_uhc_data[p_ctrl->p_cfg->module_number].pipe[0].buf       = NULL;
    g_uhc_data[p_ctrl->p_cfg->module_number].pipe[0].length    = 8;
    g_uhc_data[p_ctrl->p_cfg->module_number].pipe[0].remaining = 0;
    g_uhc_data[p_ctrl->p_cfg->module_number].pipe[0].dev       = dev_addr;

    FSP_HARDWARE_REGISTER_WAIT(p_reg->DCPCTR_b.PBUSY, 0);

    p_reg->DCPMAXP = (dev_addr << 12) | g_uhc_data[p_ctrl->p_cfg->module_number].ctl_mps[dev_addr];

    /* Set direction in advance for DATA stage */
    uint8_t const bmRequesttype = setup_packet[0];
    p_reg->DCPCFG_b.DIR = r_usbh_edpt_dir(bmRequesttype) ? 0 : 1;

    uint16_t const * p = (uint16_t const *) (uintptr_t) &setup_packet[0];
    p_reg->USBREQ  = p[0];
    p_reg->USBVAL  = p[1];
    p_reg->USBINDX = p[2];
    p_reg->USBLENG = p[3];

    p_reg->INTSTS1  = (uint16_t) ((~USB_SIGN) & INTSTS1_MASK);
    p_reg->INTSTS1  = (uint16_t) ((~USB_SACK) & INTSTS1_MASK);
    p_reg->INTENB1 |= USB_SIGNE;
    p_reg->INTENB1 |= USB_SACKE;

    p_reg->DCPCTR_b.SUREQ = 1;

    return FSP_SUCCESS;
}

/**
 * @brief Open an endpoint
 *
 * @param p_api_ctrl    [in]
 * @param dev_addr      [in]
 * @param ep_desc       [in]
 * @param p_api_ctrl    [in]
 *
 * @retval FSP_SUCCESS          on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_EdptOpen (usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr, usb_desc_endpoint_t const * ep_desc)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ASSERT(ep_desc)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(dev_addr < USB_DEVICE_NUM);

    FSP_ERROR_RETURN(dev_addr != 0, FSP_ERR_INVALID_ARGUMENT);
#endif

    R_USB_HS0_Type * p_reg   = (R_USB_HS0_Type *) p_ctrl->p_reg;
    const uint8_t    ep_addr = ep_desc->bEndpointAddress;
    const uint8_t    epn     = r_usbh_edpt_number(ep_addr);
    const uint32_t   mps     = r_usbh_edpt_packet_size(ep_desc);

    const uint8_t dir_in = r_usbh_edpt_dir(ep_addr);
    const uint8_t xfer   = ep_desc->bmAttributes.xfer;

    if (xfer == USB_XFER_ISOCHRONOUS)
    {
        /* USBa supports up to 256 bytes */
        FSP_ERROR_RETURN(mps <= 256, FSP_ERR_INVALID_ARGUMENT);
    }

    const uint32_t num = r_usbh_find_pipe(p_ctrl, xfer);

    /* There are no available pipes that can be configured for this endpoint. */
    FSP_ERROR_RETURN(0 != num, FSP_ERR_USB_BUSY);

    g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num].dev = dev_addr;
    g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num].ep  = ep_addr;
    g_uhc_data[p_ctrl->p_cfg->module_number].ep[dev_addr - 1][dir_in][epn - 1] = num;

    /* setup pipe */
    R_BSP_IrqDisable(p_ctrl->p_cfg->irq);

    p_reg->PIPESEL  = num;
    p_reg->PIPEMAXP = (dev_addr << 12) | mps;
    volatile uint16_t * ctr = r_usbh_get_pipectr(p_ctrl, num);
    *ctr = USB_PIPE_CTR_ACLRM_Msk | USB_PIPE_CTR_SQCLR_Msk;
    *ctr = 0;

    uint16_t cfg = ((1 ^ dir_in) << 4) | epn;
    if (xfer == USB_XFER_BULK)
    {
        cfg |= USB_PIPECFG_TYPE_BULK | USB_PIPECFG_SHTNAK_Msk | USB_PIPECFG_DBLB_Msk;
    }
    else if (xfer == USB_XFER_INTERRUPT)
    {
        cfg |= USB_PIPECFG_TYPE_INT;
    }
    else
    {
        cfg |= USB_PIPECFG_TYPE_ISO | USB_PIPECFG_DBLB_Msk;
    }

    p_reg->PIPECFG  = cfg;
    p_reg->BRDYSTS  = 0x3FFu ^ USB_SETBIT(num);
    p_reg->NRDYENB |= USB_SETBIT(num);
    p_reg->BRDYENB |= USB_SETBIT(num);

    if (dir_in == 0)
    {
        /* OUT */
        *ctr = USB_PIPE_CTR_PID_BUF;
    }

    R_BSP_IrqEnable(p_ctrl->p_cfg->irq);

    return FSP_SUCCESS;
}

/**
 * @brief Open a USB port to start communicate with USB device
 *
 * @param p_api_ctrl    [in]
 * @param dev_addr      [in]
 *
 * @retval FSP_SUCCESS on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_PortOpen (usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Currently, USBH only support 1 USB device */
    FSP_ASSERT(dev_addr != 1);
#endif

    uint16_t volatile * devadd = &R_USB_HS0->DEVADD[dev_addr];

    R_USB_HS0->DCPCTR = USB_PIPE_CTR_PID_NAK;
    FSP_HARDWARE_REGISTER_WAIT(R_USB_HS0->DCPCTR_b.PBUSY, 0);

    R_USB_HS0->DCPMAXP = dev_addr << USB_DEVADDRBIT | 64; /* Default mps = 64 */

    switch (g_uhc_data[p_ctrl->p_cfg->module_number].dev0.usbh_dev0_info.speed)
    {
        case USB_SPEED_FS:
        {
            *devadd = USB_DEVADD_USBSPD_FS;
            break;
        }

        case USB_SPEED_LS:
        {
            *devadd = USB_DEVADD_USBSPD_LS;
            break;
        }

        case USB_SPEED_HS:
        {
            *devadd = USB_DEVADD_USBSPD_HS;
            break;
        }

        default:
        {
            *devadd = 0;
            break;
        }
    }

    g_uhc_data[p_ctrl->p_cfg->module_number].ctl_mps[dev_addr] = 64;

    return FSP_SUCCESS;
}

/**
 * @brief Start SOF generator
 *
 * @param p_api_ctrl    [in]
 *
 * @retval FSP_SUCCESS on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_SOFEnable (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    R_USB_HS0_Type       * p_reg  = (R_USB_HS0_Type *) p_ctrl->p_reg;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg->DVSTCTR0 |= USB_UACT;

    return FSP_SUCCESS;
}

/**
 * @brief Stop SOF generator
 *
 * @param p_api_ctrl        [in]
 *
 * @retval FSP_SUCCESS on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_SOFDisable (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    R_USB_HS0_Type       * p_reg  = (R_USB_HS0_Type *) p_ctrl->p_reg;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg->DVSTCTR0 = (uint16_t) (p_reg->DVSTCTR0 & (~USB_UACT));

    return FSP_SUCCESS;
}

/**
 * @brief Resume bus
 *
 * @param p_api_ctrl       [in]
 *
 * @retval FSP_SUCCESS on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_BusResume (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    R_USB_HS0_Type       * p_reg  = (R_USB_HS0_Type *) p_ctrl->p_reg;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg->DVSTCTR0 |= (USB_RESUME);
    R_BSP_SoftwareDelay(3, BSP_DELAY_UNITS_MILLISECONDS);
    p_reg->DVSTCTR0 &= ~(USB_RESUME);
    p_reg->DVSTCTR0 |= USB_UACT;
    R_BSP_SoftwareDelay(20, BSP_DELAY_UNITS_MILLISECONDS);

    return FSP_SUCCESS;
}

/**
 * @brief Suspend bus
 *
 * @param p_api_ctrl    [in]
 *
 * @retval FSP_SUCCESS on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_BusSuspend (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    R_USB_HS0_Type       * p_reg  = (R_USB_HS0_Type *) p_ctrl->p_reg;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg->DVSTCTR0 &= ~(USB_UACT | USB_RESUME);

    return FSP_SUCCESS;
}

/**
 * @brief Close usb host
 *
 * @param p_api_ctrl    [in]
 *
 * @retval FSP_SUCCESS on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
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
 * @brief Start a transfer
 *
 * @param p_api_ctrl    [in]
 * @param dev_addr      [in]
 * @param ep_addr       [in]
 * @param buffer        [in]
 * @param buflen        [in]
 *
 * @retval FSP_SUCCESS on success
 * @retval FSP_ERR_NOT_OPEN      if USB host has not been opened
 * @retval FSP_ERR_WRITE_FAILED  if failed
 */
fsp_err_t R_USBH_XferStart (usb_ctrl_t * const p_api_ctrl,
                            uint8_t            dev_addr,
                            uint8_t            ep_addr,
                            uint8_t          * buffer,
                            uint16_t           buflen)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    bool r;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ASSERT(buffer)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    R_BSP_IrqDisable(p_ctrl->p_cfg->irq);
    r = r_usbh_process_edpt_xfer(p_ctrl, dev_addr, ep_addr, buffer, buflen);
    R_BSP_IrqEnable(p_ctrl->p_cfg->irq);

    if (r == true)
    {
        return FSP_SUCCESS;
    }

    return FSP_ERR_WRITE_FAILED;
}

/**
 * @brief Connect to the USB data bus
 *
 * @param p_api_ctrl        [in]
 *
 * @retval FSP_SUCCESS on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_Enable (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    R_USB_HS0_Type       * p_reg  = (R_USB_HS0_Type *) p_ctrl->p_reg;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg->SYSCFG_b.DRPD  = 1;
    p_reg->SYSCFG_b.DPRPU = 0;
    p_reg->SYSCFG_b.CNEN  = 1;
    p_reg->BUSWAIT        = USBH_CFG_BUS_WAIT_CYCLES;
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
    p_reg->SYSCFG_b.USBE = 1;

    return FSP_SUCCESS;
}

/**
 * @brief Disconnect to the USB data bus
 *
 * @param p_api_ctrl        [in]
 *
 * @retval FSP_SUCCESS on success
 * @retval FSP_ERR_NOT_OPEN     if USB host has not been opened
 */
fsp_err_t R_USBH_Disable (usb_ctrl_t * const p_api_ctrl)
{
    usbh_instance_ctrl_t * p_ctrl = (usbh_instance_ctrl_t *) p_api_ctrl;
    R_USB_HS0_Type       * p_reg  = (R_USB_HS0_Type *) p_ctrl->p_reg;

#if USBH_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_api_ctrl)
    FSP_ERROR_RETURN(0 != p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_reg->SYSCFG_b.DRPD  = 0;
    p_reg->SYSCFG_b.DPRPU = 0;
    p_reg->SYSCFG_b.CNEN  = 0;
    p_reg->SYSCFG_b.USBE  = 0;

    return FSP_SUCCESS;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
static fsp_err_t r_usbh_hw_module_start (usbh_instance_ctrl_t * const p_ctrl)
{
    if (p_ctrl->module_number == USB_HS_MODULE_NUMBER_START)
    {
        FSP_ERROR_RETURN(0 != R_MSTP->MSTPCRB_b.MSTPB12, FSP_ERR_USB_BUSY)

        /* Enable power for USBA */
        R_BSP_MODULE_START(FSP_IP_USBHS, 0);
    }
    else
    {
        FSP_ERROR_RETURN(0 != R_MSTP->MSTPCRB_b.MSTPB12, FSP_ERR_USB_BUSY)

        /* Enable power for USBA */
        R_BSP_MODULE_START(FSP_IP_USBFS, 0);
    }

    return FSP_SUCCESS;
}

static fsp_err_t r_usbh_module_register_clear (usbh_instance_ctrl_t * const p_ctrl)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    p_reg->DVSTCTR0    = 0;
    p_reg->DCPCTR      = USB_SQSET;
    p_reg->PIPE_CTR[0] = 0;
    p_reg->PIPE_CTR[1] = 0;
    p_reg->PIPE_CTR[2] = 0;
    p_reg->PIPE_CTR[3] = 0;
    p_reg->PIPE_CTR[4] = 0;
    p_reg->PIPE_CTR[5] = 0;
    p_reg->PIPE_CTR[6] = 0;
    p_reg->PIPE_CTR[7] = 0;
    p_reg->PIPE_CTR[8] = 0;
    p_reg->BRDYENB     = 0;
    p_reg->NRDYENB     = 0;
    p_reg->BEMPENB     = 0;
    p_reg->INTENB0     = 0;
    p_reg->INTENB1     = 0;
    p_reg->BRDYSTS     = 0;
    p_reg->NRDYSTS     = 0;
    p_reg->BEMPSTS     = 0;
    p_reg->SYSCFG      = (uint16_t) (p_reg->SYSCFG & (~USB_DPRPU));
    p_reg->SYSCFG      = (uint16_t) (p_reg->SYSCFG & (~USB_DRPD));
    p_reg->SYSCFG      = (uint16_t) (p_reg->SYSCFG & (~USB_DCFM));
    p_reg->CFIFOCTR    = 0;

    if (p_ctrl->module_number == USB_HS_MODULE_NUMBER_START)
    {
        for (uint32_t i = 0; i < USB_HS_DEVADD_NUM; i++)
        {
            p_reg->DEVADD[i] = 0;
        }

        p_reg->SYSCFG = (uint16_t) (p_reg->SYSCFG & (~USB_USBE));
        p_reg->LPSTS  = 0;
    }
    else
    {
        for (uint32_t i = 0; i < USB_FS_DEVADD_NUM; i++)
        {
            p_reg->DEVADD[i] = 0;
        }
    }

    return FSP_SUCCESS;
}

static fsp_err_t r_usbh_hw_module_stop (usbh_instance_ctrl_t * const p_ctrl)
{
    r_usbh_module_register_clear(p_ctrl);

    if (p_ctrl->module_number == USB_HS_MODULE_NUMBER_START)
    {
        FSP_ERROR_RETURN(0 == R_MSTP->MSTPCRB_b.MSTPB12, FSP_ERR_USB_NOT_OPEN)

        /* Enable power for USBA */
        R_BSP_MODULE_STOP(FSP_IP_USBHS, 0);
    }
    else
    {
        FSP_ERROR_RETURN(0 == R_MSTP->MSTPCRB_b.MSTPB11, FSP_ERR_USB_NOT_OPEN)

        /* Disable power for USB0 */
        R_BSP_MODULE_STOP(FSP_IP_USBFS, 0);
    }

    return FSP_SUCCESS;
}

static fsp_err_t r_usbh_hw_init (usbh_instance_ctrl_t * const p_ctrl)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    if (p_ctrl->module_number == USB_HS_MODULE_NUMBER_START)
    {
        if (p_ctrl->max_speed == USB_SPEED_HS)
        {
            p_reg->SYSCFG_b.HSE = 1;
        }

        p_reg->PHYSET  = (USB_DIRPD | USB_PLLRESET | USB_CLKSEL);
        p_reg->PHYSET &= (uint16_t) ~USB_CLKSEL;

#if !USBHS_PHY_CLOCK_SOURCE_IS_XTAL
        p_reg->PHYSET |= USB_HSEB;
#else
        p_reg->PHYSET_b.CLKSEL = USBH_CFG_PHYSET_CLKSEL;
        p_reg->PHYSET         |= USB_REPSEL_16;
#endif

        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
        p_reg->PHYSET = (uint16_t) (p_reg->PHYSET & (~USB_DIRPD));
        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
        p_reg->PHYSET = (uint16_t) (p_reg->PHYSET & (~USB_PLLRESET));

        p_reg->LPSTS_b.SUSPENDM = 1;

        /* Wait for PLL Lock */
        FSP_HARDWARE_REGISTER_WAIT((p_reg->PLLSTA & USB_PLLLOCK), USB_PLLLOCK);

        p_reg->SYSCFG_b.DCFM = 1;
        p_reg->SOFCFG_b.INTL = 1;

        p_reg->DVSTCTR0_b.VBUSEN = 1;
        p_reg->CFIFOSEL_b.MBW    = 1;
        p_reg->D0FIFOSEL_b.MBW   = 1;
        p_reg->D1FIFOSEL_b.MBW   = 1;
        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);

        p_reg->SYSCFG_b.USBE = 1;
    }
    else
    {
        R_USB_FS0_Type * p_fs_reg = (R_USB_FS0_Type *) p_ctrl->p_reg;
        p_fs_reg->SYSCFG_b.SCKE = 1;

        FSP_HARDWARE_REGISTER_WAIT(p_fs_reg->SYSCFG_b.SCKE, 1);

        p_fs_reg->SYSCFG_b.DCFM  = 1;  /* Host function */
        p_fs_reg->SYSCFG_b.DPRPU = 0;  /* Disable D+ pull up */
        p_fs_reg->SYSCFG_b.DRPD  = 1;  /* Enable D+/D- pull down */

        p_fs_reg->DVSTCTR0_b.VBUSEN = 1;
        R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);
        p_fs_reg->SYSCFG_b.USBE = 1;

        p_fs_reg->PHYSLEW              = 0x5;
        p_fs_reg->DPUSR0R_FS_b.FIXPHY0 = 0u; /* Transceiver Output fixed */
    }

    /* Setup default control pipe */
    p_reg->DCPCFG  = USB_PIPECFG_SHTNAK_Msk;
    p_reg->DCPMAXP = 64;
    p_reg->INTENB0 =
        USB_INTSTS0_BRDY_Msk | USB_INTSTS0_NRDY_Msk | USB_INTSTS0_BEMP_Msk;
    p_reg->INTENB1 = USB_INTSTS1_SACK_Msk | USB_INTSTS1_SIGN_Msk |
                     USB_INTSTS1_ATTCH_Msk | USB_INTSTS1_DTCH_Msk;
    p_reg->BEMPENB = 1;
    p_reg->NRDYENB = 1;
    p_reg->BRDYENB = 1;
    p_reg->INTSTS0 = 0;
    p_reg->INTSTS1 = 0;

    return true;
}

static uint16_t r_usb_chk_dev_addr (usbh_instance_ctrl_t * p_ctrl, uint16_t addr)
{
    /* Get device address configuration register from device address */
    R_USB_HS0_Type    * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;
    volatile uint16_t * preg;
    uint16_t            value;

    preg  = (uint16_t *) &(p_reg->DEVADD[0]) + addr;
    value = ((*preg) & ((USB_UPPHUB | USB_HUBPORT) | USB_USBSPD));

    return (uint16_t) (value & USB_USBSPD);
}

void r_usbh_set_dev_addr (usbh_instance_ctrl_t * p_ctrl, uint16_t addr, uint16_t speed)
{
    R_USB_HS0_Type    * p_reg  = (R_USB_HS0_Type *) p_ctrl->p_reg;
    volatile uint16_t * devadd = &p_reg->DEVADD[addr];

    if (USB_DEVICE_0 == addr)
    {
        p_reg->DCPMAXP = (uint16_t) (USB_DEFPACKET + USB_DEVICE_0);
    }

    *devadd &= (uint16_t) (~USB_USBSPD);
    *devadd |= (uint16_t) (speed);
}

static void r_usbh_device_release (usbh_instance_ctrl_t * p_ctrl, uint8_t dev_addr)
{
    R_USB_HS0_Type    * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;
    uint16_t volatile * ctr;

    g_uhc_data[p_ctrl->p_cfg->module_number].ctl_mps[dev_addr] = 0;
    uint8_t * ep = &g_uhc_data[p_ctrl->p_cfg->module_number].ep[dev_addr - 1][0][0];

    for (int i = 0; i < 2 * USB_PIPE_COUNT; ++i, ++ep)
    {
        uint32_t num = *ep;
        if (!num || (dev_addr != g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num].dev))
        {
            continue;
        }

        ctr             = (uint16_t volatile *) &p_reg->PIPE_CTR[num - 1];
        *ctr            = 0;
        p_reg->NRDYENB &= ~USB_SETBIT(num);
        p_reg->BRDYENB &= ~USB_SETBIT(num);
        p_reg->PIPESEL  = num;
        p_reg->PIPECFG  = 0;
        p_reg->PIPEMAXP = 0;

        g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num].ep  = 0;
        g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num].dev = 0;
        *ep = 0;
    }

    r_usbh_set_dev_addr(p_ctrl, dev_addr, 0);
}

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
        if (0 == g_uhc_data[p_ctrl->p_cfg->module_number].pipe[i].ep)
        {
            return i;
        }
    }

    return 0;
}

static volatile uint16_t * r_usbh_get_pipectr (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    if (num != 0)
    {
        return (volatile uint16_t *) &(p_reg->PIPE_CTR[num - 1]);
    }
    else
    {
        return (volatile uint16_t *) &(p_reg->DCPCTR);
    }
}

/* Helper to send USB transfer event */
static inline void r_usbh_event_xfer_complete_notify (usbh_instance_ctrl_t * const p_ctrl,
                                                      uint8_t                      dev_addr,
                                                      uint8_t                      ep_addr,
                                                      uint32_t                     xferred_bytes,
                                                      usb_xfer_result_t            result)
{
    usbh_event_t event =
    {
        .event_id = USBH_EVENT_XFER_COMPLETE,
        .dev_addr = dev_addr,
    };
    event.complete.ep_addr = ep_addr;
    event.complete.result  = result;
    event.complete.len     = xferred_bytes;

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

    p_args->module_number = p_ctrl->p_cfg->module_number;
    p_args->p_context     = p_ctrl->p_context;
    memcpy(&p_args->event, &event, sizeof(usbh_event_t));

    if (p_ctrl->p_callback != NULL)
    {
        p_ctrl->p_callback(p_args);
    }
}

static inline void r_usbh_event_device_attach_notify (usbh_instance_ctrl_t * const p_ctrl)
{
    usbh_event_t event;
    event.event_id        = USBH_EVENT_DEVICE_ATTACH;
    event.attach.hub_addr = 0;
    event.attach.hub_port = 0;

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

    p_args->module_number = p_ctrl->p_cfg->module_number;
    p_args->p_context     = p_ctrl->p_context;
    memcpy(&p_args->event, &event, sizeof(usbh_event_t));

    if (p_ctrl->p_callback != NULL)
    {
        p_ctrl->p_callback(p_args);
    }
}

static volatile usb_reg_pipetre_t * r_usbh_get_pipetre (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    R_USB_HS0_Type             * p_reg = p_ctrl->p_reg;
    volatile usb_reg_pipetre_t * tre   = NULL;

    if ((1 <= num) && (num <= 5))
    {
        tre = (volatile usb_reg_pipetre_t *) &(p_reg->PIPE_TR[num - 1].E);
    }

    return tre;
}

static uint16_t r_usbh_edpt0_max_packet_size (usbh_instance_ctrl_t * const p_ctrl)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    return p_reg->DCPMAXP_b.MXPS;
}

static uint16_t r_usbh_edpt_max_packet_size (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    p_reg->PIPESEL = num;

    return p_reg->PIPEMAXP_b.MXPS;
}

static inline void r_usbh_pipe_wait_for_ready (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    FSP_HARDWARE_REGISTER_WAIT(p_reg->D0FIFOSEL_b.CURPIPE, num);

    FSP_HARDWARE_REGISTER_WAIT(p_reg->D0FIFOCTR_b.FRDY, 1);
}

static void r_usbh_pipe_write_packet (void * buf, volatile void * fifo, uint32_t len)
{
    volatile hw_fifo_t * reg  = fifo;
    uint8_t            * addr = buf;

    while (len >= 2)
    {
        reg->u16 = *(const uint16_t *) addr;
        addr    += 2;
        len     -= 2;
    }

    if (len)
    {
        reg->u8 = *(const uint8_t *) addr;
        ++addr;
    }
}

static void r_usbh_pipe_read_packet (void * buf, volatile void * fifo, uint32_t len)
{
    uint8_t * p = (uint8_t *) buf;

    /* byte access is always at base register address */
    volatile uint8_t * reg = (volatile uint8_t *) fifo;
    while (len--)
    {
        *p++ = *reg;
    }
}

static bool r_usbh_pipe0_xfer_in (usbh_instance_ctrl_t * const p_ctrl)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;
    pipe_state_t   * pipe  = &g_uhc_data[p_ctrl->p_cfg->module_number].pipe[0];
    const uint32_t   rem   = pipe->remaining;

    const uint32_t mps = r_usbh_edpt0_max_packet_size(p_ctrl);
    const uint32_t vld = p_reg->CFIFOCTR_b.DTLN;
    const uint32_t len = USB_MIN(USB_MIN(rem, mps), vld);
    void         * buf = pipe->buf;
    if (len)
    {
        p_reg->DCPCTR = USB_PIPE_CTR_PID_NAK;
        r_usbh_pipe_read_packet(buf, (volatile void *) &p_reg->CFIFO, len);
        pipe->buf = (uint8_t *) buf + len;
    }

    if (len < mps)
    {
        p_reg->CFIFOCTR = USB_CFIFOCTR_BCLR_Msk;
    }

    pipe->remaining = rem - len;
    if ((len < mps) || (rem == len))
    {
        pipe->buf = NULL;

        return true;
    }

    p_reg->DCPCTR = USB_PIPE_CTR_PID_BUF;

    return false;
}

static bool r_usbh_pipe0_xfer_out (usbh_instance_ctrl_t * const p_ctrl)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;
    pipe_state_t   * pipe  = &g_uhc_data[p_ctrl->p_cfg->module_number].pipe[0];
    const uint32_t   rem   = pipe->remaining;
    if (!rem)
    {
        pipe->buf = NULL;

        return true;
    }

    const uint32_t mps = r_usbh_edpt0_max_packet_size(p_ctrl);
    const uint32_t len = USB_MIN(mps, rem);
    void         * buf = pipe->buf;
    if (len)
    {
        r_usbh_pipe_write_packet(buf, (volatile void *) &p_reg->CFIFO, len);
        pipe->buf = (uint8_t *) buf + len;
    }

    if (len < mps)
    {
        p_reg->CFIFOCTR = USB_CFIFOCTR_BVAL_Msk;
    }

    pipe->remaining = rem - len;

    return false;
}

static bool r_usbh_pipe_xfer_in (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;
    pipe_state_t   * pipe  = &g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num];
    const uint32_t   rem   = pipe->remaining;

    p_reg->D0FIFOSEL = num | USB_FIFOSEL_MBW_8BIT;
    const uint32_t mps = r_usbh_edpt_max_packet_size(p_ctrl, num);
    r_usbh_pipe_wait_for_ready(p_ctrl, num);
    const uint32_t vld = p_reg->D0FIFOCTR_b.DTLN;
    const uint32_t len = USB_MIN(USB_MIN(rem, mps), vld);
    void         * buf = pipe->buf;

    if (len)
    {
        r_usbh_pipe_read_packet(buf, (volatile void *) &p_reg->D0FIFO, len);
        pipe->buf = (uint8_t *) buf + len;
    }

    if (len < mps)
    {
        p_reg->D0FIFOCTR = USB_D0FIFOCTR_BCLR_Msk;
    }

    p_reg->D0FIFOSEL = 0;
    FSP_HARDWARE_REGISTER_WAIT(p_reg->D0FIFOSEL_b.CURPIPE, 0); /* if CURPIPE bits changes, check written value */

    pipe->remaining = rem - len;
    if ((len < mps) || (rem == len))
    {
        pipe->buf = NULL;

        return NULL != buf;
    }

    return false;
}

static bool r_usbh_pipe_xfer_out (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;
    pipe_state_t   * pipe  = &g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num];
    const uint32_t   rem   = pipe->remaining;

    if (!rem)
    {
        pipe->buf = NULL;

        return true;
    }

    p_reg->D0FIFOSEL =
        num | USB_FIFOSEL_MBW_16BIT;
    const uint32_t mps = r_usbh_edpt_max_packet_size(p_ctrl, num);
    r_usbh_pipe_wait_for_ready(p_ctrl, num);
    const uint32_t len = USB_MIN(rem, mps);
    void         * buf = pipe->buf;
    if (len)
    {
        r_usbh_pipe_write_packet(buf, (volatile void *) &p_reg->D0FIFO, len);
        pipe->buf = (uint8_t *) buf + len;
    }

    if (len < mps)
    {
        p_reg->D0FIFOCTR = USB_D0FIFOCTR_BVAL_Msk;
    }

    p_reg->D0FIFOSEL = 0;
    FSP_HARDWARE_REGISTER_WAIT(p_reg->D0FIFOSEL_b.CURPIPE, 0); /* if CURPIPE bits changes, check written value */
    pipe->remaining = rem - len;

    return false;
}

static bool r_usbh_process_pipe0_xfer (usbh_instance_ctrl_t * const p_ctrl,
                                       uint8_t                      dev_addr,
                                       uint8_t                      ep_addr,
                                       void                       * buffer,
                                       uint16_t                     buflen)
{
    FSP_PARAMETER_NOT_USED(dev_addr);

    R_USB_HS0_Type * p_reg  = (R_USB_HS0_Type *) p_ctrl->p_reg;
    const uint32_t   dir_in = r_usbh_edpt_dir(ep_addr);

    /* configure fifo direction and access unit settings */
    if (dir_in)
    {
        /* IN, a byte */
        p_reg->CFIFOSEL = USB_FIFOSEL_MBW_8BIT;
        FSP_HARDWARE_REGISTER_WAIT((p_reg->CFIFOSEL & USB_CFIFOSEL_ISEL_WRITE), 0)
    }
    else
    {
        /* OUT, 2 bytes */
        p_reg->CFIFOSEL =
            USB_CFIFOSEL_ISEL_WRITE |
            USB_FIFOSEL_MBW_16BIT;
        FSP_HARDWARE_REGISTER_WAIT((p_reg->CFIFOSEL & USB_CFIFOSEL_ISEL_WRITE), USB_CFIFOSEL_ISEL_WRITE);
    }

    pipe_state_t * pipe = &g_uhc_data[p_ctrl->p_cfg->module_number].pipe[0];
    pipe->ep        = ep_addr;
    pipe->length    = buflen;
    pipe->remaining = buflen;
    if (buflen)
    {
        pipe->buf = buffer;
        if (!dir_in)
        {
            /* OUT */
            FSP_ASSERT(p_reg->DCPCTR_b.BSTS && (p_reg->USBREQ & 0x80));
            r_usbh_pipe0_xfer_out(p_ctrl);
        }
    }
    else
    {
        /* ZLP */
        pipe->buf = NULL;
        if (!dir_in)
        {
            /* OUT */
            p_reg->CFIFOCTR = USB_CFIFOCTR_BVAL_Msk;
        }

        if (dir_in == p_reg->DCPCFG_b.DIR)
        {
            FSP_ASSERT(USB_PIPE_CTR_PID_NAK == p_reg->DCPCTR_b.PID);
            p_reg->DCPCTR_b.SQSET = 1;
            p_reg->DCPCFG_b.DIR   = dir_in ^ 1;
        }
    }

    p_reg->DCPCTR = USB_PIPE_CTR_PID_BUF;

    return true;
}

static bool r_usbh_process_pipe_xfer (usbh_instance_ctrl_t * const p_ctrl,
                                      uint8_t                      dev_addr,
                                      uint8_t                      ep_addr,
                                      void                       * buffer,
                                      uint16_t                     buflen)
{
    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    const uint32_t epn    = r_usbh_edpt_number(ep_addr);
    const uint32_t dir_in = r_usbh_edpt_dir(ep_addr);
    const uint32_t num    = g_uhc_data[p_ctrl->p_cfg->module_number].ep[dev_addr - 1][dir_in][epn - 1];

    FSP_ASSERT(num);

    pipe_state_t * pipe = &g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num];
    pipe->buf       = buffer;
    pipe->length    = buflen;
    pipe->remaining = buflen;
    if (!dir_in)
    {
        /* OUT */
        if (buflen)
        {
            r_usbh_pipe_xfer_out(p_ctrl, num);
        }
        else
        {
            /* ZLP */
            p_reg->D0FIFOSEL = num;
            r_usbh_pipe_wait_for_ready(p_ctrl, num);
            p_reg->D0FIFOCTR = USB_D0FIFOCTR_BVAL_Msk;
            p_reg->D0FIFOSEL = 0;
            FSP_HARDWARE_REGISTER_WAIT(p_reg->D0FIFOSEL_b.CURPIPE, 0); /* if CURPIPE bits changes, check written value */
        }
    }
    else
    {
        volatile uint16_t          * ctr = r_usbh_get_pipectr(p_ctrl, num);
        volatile usb_reg_pipetre_t * pt  = r_usbh_get_pipetre(p_ctrl, num);
        if (pt)
        {
            const uint32_t mps = r_usbh_edpt_max_packet_size(p_ctrl, num);
            if (*ctr & 0x3)
            {
                *ctr = USB_PIPE_CTR_PID_NAK;
            }

            pt->TRE   = USB_SETBIT(8);
            pt->TRN   = (buflen + mps - 1) / mps;
            pt->TRENB = 1;
        }

        *ctr = USB_PIPE_CTR_PID_BUF;
    }

    return true;
}

static bool r_usbh_process_edpt_xfer (usbh_instance_ctrl_t * const p_ctrl,
                                      uint8_t                      dev_addr,
                                      uint8_t                      ep_addr,
                                      void                       * buffer,
                                      uint16_t                     buflen)
{
    const uint32_t epn = r_usbh_edpt_number(ep_addr);
    if (0 == epn)
    {
        return r_usbh_process_pipe0_xfer(p_ctrl, dev_addr, ep_addr, buffer, buflen);
    }
    else
    {
        return r_usbh_process_pipe_xfer(p_ctrl, dev_addr, ep_addr, buffer, buflen);
    }
}

static inline void r_usbh_event_device_remove_notify (usbh_instance_ctrl_t * const p_ctrl)
{
    usbh_event_t event;
    event.event_id        = USBH_EVENT_DEVICE_REMOVE;
    event.remove.hub_addr = 0;
    event.remove.hub_port = 0;

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

    p_args->module_number = p_ctrl->p_cfg->module_number;
    p_args->p_context     = p_ctrl->p_context;
    memcpy(&p_args->event, &event, sizeof(usbh_event_t));

    if (p_ctrl->p_callback != NULL)
    {
        p_ctrl->p_callback(p_args);
    }
}

static void r_usbh_process_pipe0_bemp (usbh_instance_ctrl_t * const p_ctrl)
{
    bool completed = r_usbh_pipe0_xfer_out(p_ctrl);
    if (completed)
    {
        pipe_state_t * pipe = &g_uhc_data[p_ctrl->p_cfg->module_number].pipe[0];
        r_usbh_event_xfer_complete_notify(
            p_ctrl,
            pipe->dev,
            r_usbh_edpt_addr(0, USB_DIR_OUT),
            pipe->length - pipe->remaining,
            USB_XFER_RESULT_SUCCESS);
    }
}

static void r_usbh_process_pipe_nrdy (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    usb_xfer_result_t   result;
    uint16_t volatile * ctr = r_usbh_get_pipectr(p_ctrl, num);

    switch (*ctr & USB_PIPE_CTR_PID_Msk)
    {
        default:
        {
            return;
        }

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
    }

    pipe_state_t * pipe = &g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num];
    r_usbh_event_xfer_complete_notify(p_ctrl,
                                      pipe->dev,
                                      pipe->ep,
                                      pipe->length - pipe->remaining,
                                      result);
}

static void r_usbh_process_pipe_brdy (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    pipe_state_t * pipe   = &g_uhc_data[p_ctrl->p_cfg->module_number].pipe[num];
    const uint32_t dir_in = r_usbh_edpt_dir(pipe->ep);
    bool           completed;

    if (dir_in)
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
                                          pipe->dev,
                                          pipe->ep,
                                          pipe->length - pipe->remaining,
                                          USB_XFER_RESULT_SUCCESS);
    }
}

/***********************************************************************************************************************
 * Interrupt handler                                                                                                  *
 **********************************************************************************************************************/
void r_usbh_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    usbh_instance_ctrl_t * p_ctrl = R_FSP_IsrContextGet(irq);

    R_USB_HS0_Type * p_reg = (R_USB_HS0_Type *) p_ctrl->p_reg;

    uint32_t is0 = p_reg->INTSTS0;
    uint32_t is1 = p_reg->INTSTS1;

    /* clear active bits except VALID (don't write 0 to already cleared bits
     * according to the HW manual) */
    p_reg->INTSTS1 = ~((USB_INTSTS1_SACK_Msk | USB_INTSTS1_SIGN_Msk |
                        USB_INTSTS1_ATTCH_Msk | USB_INTSTS1_DTCH_Msk) &
                       is1);
    p_reg->INTSTS0 =
        ~((USB_INTSTS0_BRDY_Msk | USB_INTSTS0_NRDY_Msk | USB_INTSTS0_BEMP_Msk) &
          is0);

    is1 &= p_reg->INTENB1;
    is0 &= p_reg->INTENB0;

    if (is1 & USB_INTSTS1_SACK_Msk)
    {
        /* Set DATA1 in advance for the next transfer. */
        p_reg->DCPCTR_b.SQSET = 1;
        r_usbh_event_xfer_complete_notify(p_ctrl,
                                          p_reg->DCPMAXP_b.DEVSEL,
                                          r_usbh_edpt_addr(0, USB_DIR_OUT),
                                          8,
                                          USB_XFER_RESULT_SUCCESS);
    }

    if (is1 & USB_INTSTS1_SIGN_Msk)
    {
        r_usbh_event_xfer_complete_notify(p_ctrl,
                                          p_reg->DCPMAXP_b.DEVSEL,
                                          r_usbh_edpt_addr(0, USB_DIR_OUT),
                                          8,
                                          USB_XFER_RESULT_FAILED);
    }

    if (is1 & USB_INTSTS1_ATTCH_Msk)
    {
        p_reg->DVSTCTR0_b.UACT = 1;
        p_reg->INTENB1         =
            (p_reg->INTENB1 & ~USB_INTSTS1_ATTCH_Msk) | USB_INTSTS1_DTCH_Msk;

        r_usbh_event_device_attach_notify(p_ctrl);
    }
    else if (is1 & USB_INTSTS1_DTCH_Msk)
    {
        p_reg->DVSTCTR0_b.UACT = 0;
        if (p_reg->DCPCTR_b.SUREQ)
        {
            p_reg->DCPCTR_b.SUREQCLR = 1;
        }

        p_reg->INTENB1 =
            (p_reg->INTENB1 & ~USB_INTSTS1_DTCH_Msk) | USB_INTSTS1_ATTCH_Msk;

        r_usbh_event_device_remove_notify(p_ctrl);
    }

    if (is0 & USB_INTSTS0_BEMP_Msk)
    {
        const uint32_t s = p_reg->BEMPSTS;
        p_reg->BEMPSTS = 0;
        if (s & 1)
        {
            r_usbh_process_pipe0_bemp(p_ctrl);
        }
    }

    if (is0 & USB_INTSTS0_NRDY_Msk)
    {
        const uint32_t m = p_reg->NRDYENB;
        uint32_t       s = p_reg->NRDYSTS & m;
        p_reg->NRDYSTS = ~s;
        while (s)
        {
            const uint32_t num = CTZ(s);
            r_usbh_process_pipe_nrdy(p_ctrl, num);
            s &= ~USB_SETBIT(num);
        }
    }

    if (is0 & USB_INTSTS0_BRDY_Msk)
    {
        const uint32_t m = p_reg->BRDYENB;
        uint32_t       s = p_reg->BRDYSTS & m;

        /* clear active bits (don't write 0 to already cleared bits according to the
         * HW manual) */
        p_reg->BRDYSTS = ~s;
        while (s)
        {
            const uint32_t num = CTZ(s);
            r_usbh_process_pipe_brdy(p_ctrl, num);
            s &= ~USB_SETBIT(num);
        }
    }

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}
