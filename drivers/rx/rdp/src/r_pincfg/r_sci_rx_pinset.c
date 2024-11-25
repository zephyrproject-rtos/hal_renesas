/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_sci_rx_pinset.c
* Version      : 1.0.2
* Device(s)    : R5F51308AxFP
* Tool-Chain   : RXC toolchain
* Description  : Setting of port and mpc registers
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_sci_rx_pinset.h"
#include "platform.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_SCI_PinSet_SCI0
* Description  : This function initializes pins for r_sci_rx module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SCI_PinSet_SCI0()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set RXD0/SMISO0/SSCL0 pin */
    MPC.P21PFS.BYTE = 0x0AU;
    PORT2.PMR.BIT.B1 = 1U;

    /* Set TXD0/SMOSI0/SSDA0 pin */
    MPC.P20PFS.BYTE = 0x0AU;
    PORT2.PMR.BIT.B0 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

/***********************************************************************************************************************
* Function Name: R_SCI_PinSet_SCI1
* Description  : This function initializes pins for r_sci_rx module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SCI_PinSet_SCI1()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set RXD1/SMISO1/SSCL1 pin */
    MPC.P30PFS.BYTE = 0x0AU;
    PORT3.PMR.BIT.B0 = 1U;

    /* Set TXD1/SMOSI1/SSDA1 pin */
    MPC.P26PFS.BYTE = 0x0AU;
    PORT2.PMR.BIT.B6 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

/***********************************************************************************************************************
* Function Name: R_SCI_PinSet_SCI5
* Description  : This function initializes pins for r_sci_rx module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SCI_PinSet_SCI5()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set RXD5/SMISO5/SSCL5 pin */
    MPC.PA3PFS.BYTE = 0x0AU;
    PORTA.PMR.BIT.B3 = 1U;

    /* Set TXD5/SMOSI5/SSDA5 pin */
    MPC.PA4PFS.BYTE = 0x0AU;
    PORTA.PMR.BIT.B4 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

/***********************************************************************************************************************
* Function Name: R_SCI_PinSet_SCI6
* Description  : This function initializes pins for r_sci_rx module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SCI_PinSet_SCI6()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set RXD6/SMISO6/SSCL6 pin */
    MPC.PB0PFS.BYTE = 0x0BU;
    PORTB.PMR.BIT.B0 = 1U;

    /* Set TXD6/SMOSI6/SSDA6 pin */
    MPC.PB1PFS.BYTE = 0x0BU;
    PORTB.PMR.BIT.B1 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

/***********************************************************************************************************************
* Function Name: R_SCI_PinSet_SCI8
* Description  : This function initializes pins for r_sci_rx module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SCI_PinSet_SCI8()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set RXD8/SMISO8/SSCL8 pin */
    MPC.PC6PFS.BYTE = 0x0AU;
    PORTC.PMR.BIT.B6 = 1U;

    /* Set TXD8/SMOSI8/SSDA8 pin */
    MPC.PC7PFS.BYTE = 0x0AU;
    PORTC.PMR.BIT.B7 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

/***********************************************************************************************************************
* Function Name: R_SCI_PinSet_SCI9
* Description  : This function initializes pins for r_sci_rx module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SCI_PinSet_SCI9()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set RXD9/SMISO9/SSCL9 pin */
    MPC.PB6PFS.BYTE = 0x0AU;
    PORTB.PMR.BIT.B6 = 1U;

    /* Set TXD9/SMOSI9/SSDA9 pin */
    MPC.PB7PFS.BYTE = 0x0AU;
    PORTB.PMR.BIT.B7 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

/***********************************************************************************************************************
* Function Name: R_SCI_PinSet_SCI12
* Description  : This function initializes pins for r_sci_rx module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_SCI_PinSet_SCI12()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set RXD12/SMISO12/SSCL12 pin */
    MPC.PE2PFS.BYTE = 0x0CU;
    PORTE.PMR.BIT.B2 = 1U;

    /* Set TXD12/SMOSI12/SSDA12 pin */
    MPC.PE1PFS.BYTE = 0x0CU;
    PORTE.PMR.BIT.B1 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

