/***********************************************************************************************************************
* Copyright (c) 2013 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : r_riic_rx_if.h
 * Description  : Functions for using RIIC on RX devices. 
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 01.07.2013 1.00     First Release
 *         : 30.09.2013 1.10     Change symbol of return value and status
 *         : 08.10.2013 1.20     Modified processing for the I/O register initialization and mode transition 
 *                                when a stop condition is detected while the slave is communicating.
 *                               Modified processing for mode transition when an API function is called
 *                                while the bus is busy.
 *                               Modified processing for mode transition
 *                                when an arbitration lost occurred and the addresses do not match.
 *                               Modified incorrect slave transmission after the master reception.
 *                               Modified processing for the I/O register initialization
 *                                when generating a start condition and receiving the slave address.
 *         : 17.07.2014 1.30     Added the parameters for the timeout detection.
 *         : 22.09.2014 1.40     The module is updated to measure the issue that slave communication 
 *                               is not available after an arbitration-lost occurs and the bus is locked. 
 *                                 The issue occurs when the following four conditions are all met.
 *                                    - RIIC FIT module rev. 1.30 or earlier is used.
 *                                    - RX device operates as both the master and the slave 
 *                                      in multi-master communication.
 *                                    - An arbitration-lost is detected when communicating as the master.
 *                                    - Communication other than master reception or slave reception is performed.
 *         : 14.11.2014 1.50     Added RX113 support.
 *         : 09.10.2014 1.60     Added RX71M support.
 *         : 20.10.2014 1.70     Added RX231 support.
 *         : 31.10.2015 1.80     Added RX130, RX230, RX23T support.
 *         : 04.03.2016 1.90     Added RX24T support.
 *         : 01.10.2016 2.00     Added RX65N support.
 *         : 02.06.2017 2.10     Changed minor version to '10' for RX24U support.
 *         : 31.08.2017 2.20     Changed minor version to '20' for RX65N-2MB and RX130-512KB support.
 *         : 30.10.2017 2.30     Changed minor version to '30' for RX66T support.
 *         : 03.12.2018 2.31     Changed minor version to '31' for update of xml file.
 *         : 15.10.2018 2.40     Changed minor version to '40' for RX72T support.
 *         : 20.05.2019 2.41     Added support for GNUC and ICCRX.
 *                               Fixed coding style.
 *         : 20.06.2019 2.42     Changed minor version to '42' for RX23W support. 
 *         : 30.07.2019 2.43     Changed minor version to '43' for RX72M support.
 *         : 10.10.2019 2.44     Changed minor version to '44' for RX13T support.
 *         : 22.11.2019 2.45     Changed minor version to '45' for RX66N and RX72N support.
 *         : 10.03.2020 2.46     Changed minor version to '46' for RX23E-A support.
 *         : 30.10.2020 2.47     Changed minor version to '47' for e2studio 2020-10 support.
 *         : 30.06.2021 2.48     Changed minor version to '48' for RX671 support.
 *         : 31.07.2021 2.49     Changed minor version to '49' for RX140 support.
 *         : 31.12.2021 2.50     Changed minor version to '50' for RX660 support.
 *         : 16.12.2022 2.60     Fixed processing error of riic_bps_calc.
 *         : 31.03.2023 2.70     Changed minor version to '70' for RX26T support.
 *                               Fixed to comply with GSCE Coding Standards Rev.6.5.0.
 *                               Added RX671 Demo, RX72N Demo.
 *                               Apply a digital noise filter circuit to the riic_bps_calc function.
 *                               Added new macros for SCL rise time and SCL fall time.
 *         : 29.05.2023 2.80     Changed minor version to '80' for RX23E-B support.
 *                               Fixed to comply with GSCE Coding Standards Rev.6.5.0
 *         : 10.10.2023 2.90     Changed EEI and TEI default interrupt priority levels
 *                                for devices with EEI and TEI assigned to group interrupts,
 *                                to be higher than TXI and RXI priority levels in MDF file.
 *                               Modified source code comments of RIIC_CFG_CHi_RXI_INT_PRIORITY,
 *                                RIIC_CFG_CHi_TXI_INT_PRIORITY, RIIC_CFG_CHi_EEI_INT_PRIORITY,
 *                                RIIC_CFG_CHi_TEI_INT_PRIORITY (i = 0 to 2) in r_riic_rx_config.h.
 *         : 01.08.2024 2.91     Fixed issues related to EEI and TEI interrupt priority levels for RX651 in MDF file.
 *         : 08.08.2024 3.00     Added RX260, RX261 support.
 *         : 15.03.2025 3.01     Updated disclaimer.
 **********************************************************************************************************************/
/* Guards against multiple inclusion */
#ifndef RIIC_IF_H
    #define RIIC_IF_H
/***********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
/* Includes board and MCU related header files. */
    #include "platform.h"
/* Used for configuring the RIIC code */
    #include "r_riic_rx_config.h"

R_BSP_PRAGMA_UNPACK
/***********************************************************************************************************************
 Macro definitions
 **********************************************************************************************************************/
#if R_BSP_VERSION_MAJOR < 5
    #error "This module must use BSP module of Rev.5.00 or higher. Please use the BSP module of Rev.5.00 or higher."
#endif

/* Version Number of API. */
    #define RIIC_VERSION_MAJOR      (3)
    #define RIIC_VERSION_MINOR      (01)

/*----------------------------------------------------------------------------*/
/*   Defines the argument of the R_RIIC_Control function.                     */
/*----------------------------------------------------------------------------*/
    #define RIIC_GEN_START_CON      ((uint8_t)(0x01))   /* Generate start condition */
    #define RIIC_GEN_STOP_CON       ((uint8_t)(0x02))   /* Generate stop condition */
    #define RIIC_GEN_RESTART_CON    ((uint8_t)(0x04))   /* Generate restart condition */
    #define RIIC_GEN_SDA_HI_Z       ((uint8_t)(0x08))   /* Generate nack output */
    #define RIIC_GEN_SCL_ONESHOT    ((uint8_t)(0x10))   /* Geenrate one-shot scl clock output */
    #define RIIC_GEN_RESET          ((uint8_t)(0x20))   /* Reset riic module */

/*----------------------------------------------------------------------------*/
/*   Define values of channel state flag.                                     */
/*----------------------------------------------------------------------------*/
    #define RIIC_NO_INIT        ((riic_ch_dev_status_t)(0)) /* Uninitialized state */
    #define RIIC_IDLE           ((riic_ch_dev_status_t)(1)) /* Successful operation */
    #define RIIC_FINISH         ((riic_ch_dev_status_t)(2)) /* Already idle state */
    #define RIIC_NACK           ((riic_ch_dev_status_t)(3)) /* Already idle state */
    #define RIIC_COMMUNICATION  ((riic_ch_dev_status_t)(4)) /* Successful operation */
    #define RIIC_AL             ((riic_ch_dev_status_t)(5)) /* Arbitration lost */
    #define RIIC_TMO            ((riic_ch_dev_status_t)(6)) /* Time Out */
    #define RIIC_ERROR          ((riic_ch_dev_status_t)(7)) /* error */

/***********************************************************************************************************************
 Typedef definitions
 **********************************************************************************************************************/
/*----------------------------------------------------------------------------*/
/*   Define return values and values of channel state flag.                   */
/*----------------------------------------------------------------------------*/
typedef uint8_t riic_ch_dev_status_t;

typedef enum
{
    RIIC_SUCCESS = 0U, /* Successful operation */
    RIIC_ERR_LOCK_FUNC, /* Lock has already been acquired by another task. */
    RIIC_ERR_INVALID_CHAN, /* None existent channel number */
    RIIC_ERR_INVALID_ARG, /* Parameter error */
    RIIC_ERR_NO_INIT, /* Uninitialized state */
    RIIC_ERR_BUS_BUSY, /* Channel is on communication. */
    RIIC_ERR_AL, /* Arbitration lost error */
    RIIC_ERR_TMO, /* Time Out error */
    RIIC_ERR_OTHER /* Other error */
} riic_return_t;

/*----------------------------------------------------------------------------*/
/*   Define iic information structure type.                                   */
/*----------------------------------------------------------------------------*/
/* ---- Callback function type. ---- */
/******************************************************************************
 * Function Name: riic_callback
 * Description  : .
 * Return Value : .
 *****************************************************************************/
typedef void (*riic_callback) (void); /* Callback function type */

/* ---- IIC Information structure type. ---- */
typedef volatile struct
{
    uint8_t              rsv2; /* reserved */
    uint8_t              rsv1; /* reserved */
    riic_ch_dev_status_t dev_sts; /* Device status flag */
    uint8_t              ch_no; /* Channel No. */
    riic_callback        callbackfunc; /* Callback function */
    uint32_t             cnt2nd; /* 2nd Data Counter */
    uint32_t             cnt1st; /* 1st Data Counter */
    uint8_t            * p_data2nd; /* Pointer for 2nd Data buffer */
    uint8_t            * p_data1st; /* Pointer for 1st Data buffer */
    uint8_t            * p_slv_adr; /* Pointer for Slave address buffer */
} riic_info_t;

/*----------------------------------------------------------------------------*/
/*   Define riic status structure type.                                       */
/*----------------------------------------------------------------------------*/
typedef union
{
    uint32_t LONG;
    R_BSP_ATTRIB_STRUCT_BIT_ORDER_LEFT_21
    (
        uint32_t rsv :12, /* reserve */
        uint32_t AAS2 :1, /* Slave2 address detection flag */
        uint32_t AAS1 :1, /* Slave1 address detection flag */
        uint32_t AAS0 :1, /* Slave0 address detection flag */
        uint32_t GCA :1, /* Generalcall address detection flag */
        uint32_t DID :1, /* DeviceID address detection flag */
        uint32_t HOA :1, /* Host address detection flag */
        uint32_t MST :1, /* Master mode / Slave mode flag */
        uint32_t TMO :1, /* Time out flag */
        uint32_t AL :1, /* Arbitration lost detection flag */
        uint32_t SP :1, /* Stop condition detection flag */
        uint32_t ST :1, /* Start condition detection flag */
        uint32_t RBUF :1, /* Receive buffer status flag */
        uint32_t SBUF :1, /* Send buffer status flag */
        uint32_t SCLO :1, /* SCL pin output control status */
        uint32_t SDAO :1, /* SDA pin output control status */
        uint32_t SCLI :1, /* SCL pin level */
        uint32_t SDAI :1, /* SDA pin level */
        uint32_t NACK :1, /* NACK detection flag */
        uint32_t TRS :1, /* Send mode / Receive mode flag */
        uint32_t BSY :1 /* Bus status flag */
    ) BIT;
} riic_mcu_status_t;

/***********************************************************************************************************************
 Exported global variables
 **********************************************************************************************************************/
/* ---- Channel status ---- */
extern riic_ch_dev_status_t g_riic_ChStatus[];

/***********************************************************************************************************************
 Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
/* ---- RIIC Driver API functions ---- */
/******************************************************************************
 * Function Name: R_RIIC_Open
 * Description  : .
 * Argument     : riic_return_t
 * Return Value : .
 *****************************************************************************/
riic_return_t R_RIIC_Open (riic_info_t *);

/******************************************************************************
 * Function Name: R_RIIC_MasterSend
 * Description  : .
 * Argument     : riic_info_t
 * Return Value : .
 *****************************************************************************/
riic_return_t R_RIIC_MasterSend (riic_info_t *);

/******************************************************************************
 * Function Name: R_RIIC_MasterReceive
 * Description  : .
 * Argument     : riic_info_t
 * Return Value : .
 *****************************************************************************/
riic_return_t R_RIIC_MasterReceive (riic_info_t *);

/******************************************************************************
 * Function Name: R_RIIC_SlaveTransfer
 * Description  : .
 * Argument     : riic_info_t
 * Return Value : .
 *****************************************************************************/
riic_return_t R_RIIC_SlaveTransfer (riic_info_t *);

/******************************************************************************
 * Function Name: R_RIIC_GetStatus
 * Description  : .
 * Arguments    : riic_info_t
 *              : riic_mcu_status_t
 * Return Value : .
 *****************************************************************************/
riic_return_t R_RIIC_GetStatus (riic_info_t *, riic_mcu_status_t *);

/******************************************************************************
 * Function Name: R_RIIC_Control
 * Description  : .
 * Arguments    : riic_info_t
 *              : ctrl_ptn
 * Return Value : .
 *****************************************************************************/
riic_return_t R_RIIC_Control (riic_info_t *, uint8_t ctrl_ptn);

/******************************************************************************
 * Function Name: R_RIIC_Close
 * Description  : .
 * Argument     : riic_return_t
 * Return Value : .
 *****************************************************************************/
riic_return_t R_RIIC_Close (riic_info_t *);

/******************************************************************************
 * Function Name: R_RIIC_GetVersion
 * Description  : .
 * Return Value : .
 *****************************************************************************/
uint32_t      R_RIIC_GetVersion (void);

riic_return_t riic_bps_calc (riic_info_t *, uint16_t kbps);
R_BSP_PRAGMA_PACKOPTION
#endif /* RIIC_IF_H */

