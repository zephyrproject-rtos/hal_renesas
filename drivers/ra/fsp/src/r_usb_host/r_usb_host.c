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
    pipe_state_t pipe[USB_PIPE_COUNT_MAX];
    uint8_t      ep[USB_DEVICE_COUNT_MAX][USB_DIR_COUNT_MAX][USB_EP_COUNT_MAX];
    uint8_t      ctl_mps[USB_DEVICE_COUNT_MAX]; /* EP0 max packet size for each device */
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
static bool        r_usbh_pipe_xfer_out(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static bool        r_usbh_pipe0_xfer_out(usbh_instance_ctrl_t * const p_ctrl);
static bool        r_usbh_pipe_xfer_in(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static bool        r_usbh_pipe0_xfer_in(usbh_instance_ctrl_t * const p_ctrl);
static void        r_usbh_pipe_write_packet(void * p_buf, volatile void * p_fifo, uint32_t len);
static void        r_usbh_pipe_read_packet(void * p_buf, volatile void * p_fifo, uint32_t len);
static uint16_t    r_usbh_edpt_max_packet_size(usbh_instance_ctrl_t * const p_ctrl, uint32_t num);
static uint16_t    r_usbh_edpt0_max_packet_size(usbh_instance_ctrl_t * const p_ctrl);
static inline void r_usbh_interrupt_configure(usbh_instance_ctrl_t * p_ctrl);
static inline void r_usbh_interrupt_enable(usbh_instance_ctrl_t * p_ctrl);
static inline void r_usbh_interrupt_disable(usbh_instance_ctrl_t * p_ctrl);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
uhc_data_t g_uhc_data[USB_NUM_USBIP];

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
    r_usbh_interrupt_enable(p_ctrl);

    memset(&g_uhc_data[p_ctrl->module_number], 0, sizeof(uhc_data_t));

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
    R_BSP_SoftwareDelay(20, BSP_DELAY_UNITS_MILLISECONDS);

    /* Deassert USB bus reset signal */
    *p_reg_dvstctr0 &= ~R_USB_DVSTCTR0_USBRST_Msk;

    /* Enable the USB bus for host controller operation */
    *p_reg_dvstctr0 |= R_USB_DVSTCTR0_UACT_Msk;

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

    g_uhc_data[p_ctrl->module_number].dev0.usbh_dev0_info.speed = *p_speed;

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

#ifdef USB_HIGH_SPEED_MODULE
    uint16_t intsts1_mask = USB_IS_USBHS(p_ctrl->module_number) ?
                            USB_HS_INTSTS1_CLEAN_MASK :
                            USB_FS_INTSTS1_CLEAN_MASK;
#else
    uint16_t intsts1_mask = USB_FS_INTSTS1_CLEAN_MASK;
#endif
    *p_reg_intsts1  = (~(R_USB_INTSTS1_SIGN_Msk | R_USB_INTSTS1_SACK_Msk)) & intsts1_mask;
    *p_reg_intenb1 |= (R_USB_INTENB1_SIGNE_Msk | R_USB_INTENB1_SACKE_Msk);
    *p_reg_dcpctr  |= R_USB_DCPCTR_SUREQ_Msk;

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
fsp_err_t R_USBH_EdptOpen (usb_ctrl_t * const p_api_ctrl, uint8_t dev_addr, usb_desc_endpoint_t const * p_ep_desc)
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

    const uint8_t  ep_addr = p_ep_desc->bEndpointAddress;
    const uint8_t  epn     = r_usbh_edpt_number(ep_addr);
    const uint32_t mps     = r_usbh_edpt_packet_size(p_ep_desc);
    const uint8_t  dir     = r_usbh_edpt_dir(ep_addr);
    const uint8_t  xfer    = p_ep_desc->bmAttributes.xfer;

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
    }

    if (xfer == USB_XFER_ISOCHRONOUS)
    {
        /* USBa supports up to 256 bytes */
        FSP_ERROR_RETURN(mps <= 256, FSP_ERR_INVALID_ARGUMENT);
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

    /* PIPE Configuration */
    *p_reg_pipesel  = num;
    *p_reg_pipemaxp = ((dev_addr << R_USB_PIPEMAXP_DEVSEL_Pos) & R_USB_PIPEMAXP_DEVSEL_Msk) |
                      (mps & R_USB_PIPEMAXP_MXPS_Msk);
    *p_reg_pipecfg = pipe_cfg;
    *p_reg_brdysts = R_USB_BRDYSTS_PIPEBRDY_Msk ^ USB_SETBIT(num);
    *p_reg_pipectr = R_USB_PIPE_CTR_ACLRM_Msk | R_USB_PIPE_CTR_SQCLR_Msk;
    *p_reg_pipectr = (USB_DIR_OUT == dir) ?
                     (USB_PIPE_CTR_PID_BUF << R_USB_PIPE_CTR_PID_Pos) :
                     (USB_PIPE_CTR_PID_NAK << R_USB_PIPE_CTR_PID_Pos);

    /* PIPE interrupt enable */
    *p_reg_brdyenb |= USB_SETBIT(num);
    *p_reg_nrdyenb |= USB_SETBIT(num);
    *p_reg_bempenb |= USB_SETBIT(num);

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

    /* Default mps = 64 */
    *p_dcpmaxp = ((dev_addr << R_USB_DCPMAXP_DEVSEL_Pos) & R_USB_DCPMAXP_DEVSEL_Msk) | USB_DCPMAXP_MXPS_DEFAULT;

    switch (g_uhc_data[p_ctrl->module_number].dev0.usbh_dev0_info.speed)
    {
        case USB_SPEED_LS:
        {
            *p_devadd = USB_DEVADD_USBSPD_LS << R_USB_DEVADD_USBSPD_Pos;
            break;
        }

        case USB_SPEED_FS:
        {
            *p_devadd = USB_DEVADD_USBSPD_FS << R_USB_DEVADD_USBSPD_Pos;
            break;
        }

#ifdef USB_HIGH_SPEED_MODULE
        case USB_SPEED_HS:
        {
            *p_devadd = USB_IS_USBHS(p_ctrl->module_number) ?
                        (USB_DEVADD_USBSPD_HS << R_USB_DEVADD_USBSPD_Pos) :
                        (USB_DEVADD_USBSPD_NOT_USE << R_USB_DEVADD_USBSPD_Pos);
            break;
        }
#endif

        default:
        {
            *p_devadd = USB_DEVADD_USBSPD_NOT_USE << R_USB_DEVADD_USBSPD_Pos;
            break;
        }
    }

    g_uhc_data[p_ctrl->module_number].ctl_mps[dev_addr] = USB_DCPMAXP_MXPS_DEFAULT;

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
        R_USB_HS0->DVSTCTR0 |= R_USB_DVSTCTR0_UACT_Msk;
    }
    else
#endif
    {
        R_USB_FS0->DVSTCTR0 |= R_USB_DVSTCTR0_UACT_Msk;
    }

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
        R_USB_HS0->DVSTCTR0 &= ~R_USB_DVSTCTR0_UACT_Msk;
    }
    else
#endif
    {
        R_USB_FS0->DVSTCTR0 &= ~R_USB_DVSTCTR0_UACT_Msk;
    }

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

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
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

static void r_usbh_hw_init (usbh_instance_ctrl_t * const p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_USB_HS0->SYSCFG = (USB_SPEED_HS == p_ctrl->max_speed) ?
                            (R_USB_HS0->SYSCFG | R_USB_SYSCFG_HSE_Msk) :
                            (R_USB_HS0->SYSCFG & ~R_USB_SYSCFG_HSE_Msk);
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

    p_args->module_number = p_ctrl->module_number;
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

    p_args->module_number = p_ctrl->module_number;
    p_args->p_context     = p_ctrl->p_context;
    memcpy(&p_args->event, &event, sizeof(usbh_event_t));

    if (p_ctrl->p_callback != NULL)
    {
        p_ctrl->p_callback(p_args);
    }
}

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

static uint16_t r_usbh_edpt_max_packet_size (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_USB_HS0->PIPESEL = num;

        return (uint16_t) ((R_USB_HS0->PIPEMAXP & R_USB_PIPEMAXP_MXPS_Msk) >>
                           R_USB_PIPEMAXP_MXPS_Pos);
    }
    else
#endif
    {
        R_USB_FS0->PIPESEL = num;

        return (uint16_t) ((R_USB_FS0->PIPEMAXP & R_USB_PIPEMAXP_MXPS_Msk) >>
                           R_USB_PIPEMAXP_MXPS_Pos);
    }
}

static inline void r_usbh_pipe_wait_for_ready (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        FSP_HARDWARE_REGISTER_WAIT((R_USB_HS0->D0FIFOSEL & R_USB_D0FIFOSEL_CURPIPE_Msk) >>
                                   R_USB_D0FIFOSEL_CURPIPE_Pos,
                                   num);
        FSP_HARDWARE_REGISTER_WAIT((R_USB_HS0->D0FIFOCTR & R_USB_D0FIFOCTR_FRDY_Msk),
                                   R_USB_D0FIFOCTR_FRDY_Msk);
    }
    else
#endif
    {
        FSP_HARDWARE_REGISTER_WAIT((R_USB_FS0->D0FIFOSEL & R_USB_D0FIFOSEL_CURPIPE_Msk) >>
                                   R_USB_D0FIFOSEL_CURPIPE_Pos,
                                   num);
        FSP_HARDWARE_REGISTER_WAIT((R_USB_FS0->D0FIFOCTR & R_USB_D0FIFOCTR_FRDY_Msk),
                                   R_USB_D0FIFOCTR_FRDY_Msk);
    }
}

static void r_usbh_pipe_write_packet (void * p_buf, volatile void * p_fifo, uint32_t len)
{
    volatile hw_fifo_t * p_reg  = p_fifo;
    uint8_t            * p_addr = p_buf;

    while (len >= 2)
    {
        p_reg->u16 = *(const uint16_t *) p_addr;
        p_addr    += 2;
        len       -= 2;
    }

    if (len)
    {
        p_reg->u8 = *(const uint8_t *) p_addr;
        ++p_addr;
    }
}

static void r_usbh_pipe_read_packet (void * p_buf, volatile void * p_fifo, uint32_t len)
{
    uint8_t          * p_data = (uint8_t *) p_buf;
    volatile uint8_t * p_reg  = (volatile uint8_t *) p_fifo;

    /* byte access is always at base register address */
    while (len--)
    {
        *p_data++ = *p_reg;
    }
}

static bool r_usbh_pipe0_xfer_in (usbh_instance_ctrl_t * const p_ctrl)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[0];
    void         * p_buf  = p_pipe->buf;
    const uint32_t rem    = p_pipe->remaining;

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
        r_usbh_pipe_read_packet(p_buf, p_cfifo, len);
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

static bool r_usbh_pipe0_xfer_out (usbh_instance_ctrl_t * const p_ctrl)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[0];
    const uint32_t rem    = p_pipe->remaining;

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
    }
    else
#endif
    {
        p_cfifoctr = &R_USB_FS0->CFIFOCTR;
        p_cfifo    = (volatile void *) &R_USB_FS0->CFIFO;
    }

    if (len)
    {
        r_usbh_pipe_write_packet(p_buf, p_cfifo, len);
        p_pipe->buf = (uint8_t *) p_buf + len;
    }

    if (len < mps)
    {
        *p_cfifoctr = R_USB_CFIFOCTR_BVAL_Msk;
    }

    p_pipe->remaining = rem - len;

    return false;
}

static bool r_usbh_pipe_xfer_in (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[num];
    void         * p_buf  = p_pipe->buf;
    const uint32_t rem    = p_pipe->remaining;
    const uint32_t mps    = r_usbh_edpt_max_packet_size(p_ctrl, num);

    r_usbh_pipe_wait_for_ready(p_ctrl, num);

    volatile uint16_t * p_reg_d0fifosel;
    volatile uint16_t * p_reg_d0fifoctr;
    volatile void     * p_reg_d0fifo;
    uint16_t            vld;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_d0fifosel = &R_USB_HS0->D0FIFOSEL;
        p_reg_d0fifoctr = &R_USB_HS0->D0FIFOCTR;
        p_reg_d0fifo    = (volatile void *) &R_USB_HS0->D0FIFO;
        vld             = (uint32_t) (R_USB_HS0->CFIFOCTR & R_USB_CFIFOCTR_DTLN_Msk);
    }
    else
#endif
    {
        p_reg_d0fifosel = &R_USB_FS0->D0FIFOSEL;
        p_reg_d0fifoctr = &R_USB_FS0->D0FIFOCTR;
        p_reg_d0fifo    = (volatile void *) &R_USB_FS0->D0FIFO;
        vld             = (uint32_t) (R_USB_FS0->CFIFOCTR & R_USB_CFIFOCTR_DTLN_Msk);
    }

    *p_reg_d0fifosel = (num << R_USB_D0FIFOSEL_CURPIPE_Pos) |
                       (USB_FIFOSEL_MBW_8_BIT << R_USB_D0FIFOSEL_MBW_Pos);

    const uint32_t len = USB_MIN(USB_MIN(rem, mps), vld);

    if (len)
    {
        r_usbh_pipe_read_packet(p_buf, p_reg_d0fifo, len);
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

static bool r_usbh_pipe_xfer_out (usbh_instance_ctrl_t * const p_ctrl, uint32_t num)
{
    pipe_state_t * p_pipe = &g_uhc_data[p_ctrl->module_number].pipe[num];
    void         * p_buf  = p_pipe->buf;
    const uint32_t rem    = p_pipe->remaining;
    const uint32_t mps    = r_usbh_edpt_max_packet_size(p_ctrl, num);
    const uint32_t len    = USB_MIN(rem, mps);

    r_usbh_pipe_wait_for_ready(p_ctrl, num);

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

    if (!rem)
    {
        p_pipe->buf = NULL;

        return true;
    }

    *p_reg_d0fifosel = (num << R_USB_D0FIFOSEL_CURPIPE_Pos) |
                       (USB_FIFOSEL_MBW_16_BIT << R_USB_D0FIFOSEL_MBW_Pos);

    if (len)
    {
        r_usbh_pipe_write_packet(p_buf, p_reg_d0fifo, len);
        p_pipe->buf = (uint8_t *) p_buf + len;
    }

    if (len < mps)
    {
        *p_reg_d0fifoctr = R_USB_D0FIFOCTR_BVAL_Msk;
    }

    *p_reg_d0fifosel = 0;
    FSP_HARDWARE_REGISTER_WAIT((*p_reg_d0fifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), 0);
    p_pipe->remaining = rem - len;

    return false;
}

static bool r_usbh_process_pipe0_xfer (usbh_instance_ctrl_t * const p_ctrl,
                                       uint8_t                      dev_addr,
                                       uint8_t                      ep_addr,
                                       void                       * p_buffer,
                                       uint16_t                     buflen)
{
    FSP_PARAMETER_NOT_USED(dev_addr);

    const uint32_t dir = r_usbh_edpt_dir(ep_addr);

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

    /* configure fifo direction and access unit settings */
    if (USB_DIR_IN == dir)
    {
        /* IN, a byte */
        *p_reg_cfifosel = USB_FIFOSEL_MBW_8_BIT << R_USB_CFIFOSEL_MBW_Pos;
        FSP_HARDWARE_REGISTER_WAIT((*p_reg_cfifosel & R_USB_CFIFOSEL_ISEL_Msk), 0);
    }
    else
    {
        /* OUT, 2 bytes */
        *p_reg_cfifosel = R_USB_CFIFOSEL_ISEL_Msk |
                          (USB_FIFOSEL_MBW_16_BIT << R_USB_CFIFOSEL_MBW_Pos);
        FSP_HARDWARE_REGISTER_WAIT((*p_reg_cfifosel & R_USB_CFIFOSEL_ISEL_Msk),
                                   R_USB_CFIFOSEL_ISEL_Msk);
    }

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
            FSP_ASSERT((*p_reg_dcpctr & R_USB_DCPCTR_BSTS_Msk) && (*p_reg_usbreq & USB_SETBIT(7)));
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

        if (dir == ((*p_reg_dcpcfg & R_USB_DCPCFG_DIR_Msk) >> R_USB_DCPCFG_DIR_Pos))
        {
            FSP_ASSERT((USB_PIPE_CTR_PID_NAK << R_USB_PIPE_CTR_PID_Pos) == (*p_reg_dcpctr & R_USB_DCPCTR_PID_Msk));
            *p_reg_dcpctr |= R_USB_DCPCTR_SQSET_Msk;
            *p_reg_dcpcfg  = (dir) ?
                             (*p_reg_dcpcfg & (~R_USB_DCPCFG_DIR_Msk)) :
                             (*p_reg_dcpcfg | R_USB_DCPCFG_DIR_Msk);
        }
    }

    *p_reg_dcpctr = USB_PIPE_CTR_PID_BUF << R_USB_PIPE_CTR_PID_Pos;

    return true;
}

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

    volatile uint16_t * p_reg_d0fifosel;
    volatile uint16_t * p_reg_d0fifoctr;

#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        p_reg_d0fifosel = &R_USB_HS0->D0FIFOSEL;
        p_reg_d0fifoctr = &R_USB_HS0->D0FIFOCTR;
    }
    else
#endif
    {
        p_reg_d0fifosel = &R_USB_FS0->D0FIFOSEL;
        p_reg_d0fifoctr = &R_USB_FS0->D0FIFOCTR;
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
            *p_reg_d0fifosel = num;
            r_usbh_pipe_wait_for_ready(p_ctrl, num);
            *p_reg_d0fifoctr = R_USB_D0FIFOCTR_BVAL_Msk;
            *p_reg_d0fifosel = 0;

            FSP_HARDWARE_REGISTER_WAIT((*p_reg_d0fifosel & R_USB_D0FIFOSEL_CURPIPE_Msk), 0);
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

    p_args->module_number = p_ctrl->module_number;
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
        pipe_state_t * pipe = &g_uhc_data[p_ctrl->module_number].pipe[0];
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

static inline void r_usbh_interrupt_configure (usbh_instance_ctrl_t * p_ctrl)
{
#ifdef USB_HIGH_SPEED_MODULE
    if (USB_IS_USBHS(p_ctrl->module_number))
    {
        R_USB_HS0->INTENB0 = R_USB_INTSTS0_BRDY_Msk | R_USB_INTSTS0_NRDY_Msk |
                             R_USB_INTSTS0_BEMP_Msk;
        R_USB_HS0->INTENB1 = R_USB_INTSTS1_SACK_Msk | R_USB_INTSTS1_SIGN_Msk |
                             R_USB_INTSTS1_ATTCH_Msk | R_USB_INTSTS1_DTCH_Msk;
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

static inline void r_usbh_interrupt_enable (usbh_instance_ctrl_t * p_ctrl)
{
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
}

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
void r_usbh_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Clear pending IRQ to make sure it doesn't fire again after exiting */
    R_BSP_IrqStatusClear(irq);

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

    uint16_t status0 = *p_reg_intsts0;
    uint16_t status1 = *p_reg_intsts1;

    /* clear active bits except VALID (don't write 0 to already cleared bits
     * according to the HW manual) */
    *p_reg_intsts1 &= ~(R_USB_INTSTS1_SACK_Msk | R_USB_INTSTS1_SIGN_Msk |
                        R_USB_INTSTS1_ATTCH_Msk | R_USB_INTSTS1_DTCH_Msk);

    *p_reg_intsts0 &= ~(R_USB_INTSTS0_BRDY_Msk | R_USB_INTSTS0_NRDY_Msk |
                        R_USB_INTSTS0_BEMP_Msk);

    status0 &= *p_reg_intenb0;
    status1 &= *p_reg_intenb1;

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
        *p_reg_dvstctr0 |= R_USB_DVSTCTR0_UACT_Msk;
        *p_reg_intenb1  &= ~R_USB_INTSTS1_ATTCH_Msk;
        *p_reg_intenb1  |= R_USB_INTSTS1_DTCH_Msk;

        r_usbh_event_device_attach_notify(p_ctrl);
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
