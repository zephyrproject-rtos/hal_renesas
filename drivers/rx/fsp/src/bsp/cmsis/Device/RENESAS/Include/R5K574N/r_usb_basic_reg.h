/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_USB_BASIC_REG_H
#define R_USB_BASIC_REG_H

/**
 * @brief R_USB_FS0_PIPE_TR [PIPE_TR] (Pipe Transaction Counter Registers)
 */
typedef struct
{
    union
    {
        __IOM uint16_t E;              /*!< (@ 0x00000000) Pipe Transaction Counter Enable Register                   */

        struct
        {
            uint16_t             : 8;
            __IOM uint16_t TRCLR : 1;  /*!< [8..8] Transaction Counter Clear                                          */
            __IOM uint16_t TRENB : 1;  /*!< [9..9] Transaction Counter Enable                                         */
            uint16_t             : 6;
        } E_b;
    };

    union
    {
        __IOM uint16_t N;               /*!< (@ 0x00000002) Pipe Transaction Counter Register                          */

        struct
        {
            __IOM uint16_t TRNCNT : 16; /*!< [15..0] Transaction Counter                                               */
        } N_b;
    };
} R_USB_FS0_PIPE_TR_Type;               /*!< Size = 4 (0x4)                                                            */

/**
 * @brief USB_HS0_PIPE_TR [PIPE_TR] (Pipe Transaction Counter Registers)
 */
typedef struct
{
    union
    {
        __IOM uint16_t E;              /*!< (@ 0x00000000) Pipe Transaction Counter Enable Register                   */

        struct
        {
            uint16_t             : 8;
            __IOM uint16_t TRCLR : 1;  /*!< [8..8] Transaction Counter Clear                                          */
            __IOM uint16_t TRENB : 1;  /*!< [9..9] Transaction Counter Enable                                         */
        } E_b;
    };

    union
    {
        __IOM uint16_t N;               /*!< (@ 0x00000002) Pipe Transaction Counter Register                          */

        struct
        {
            __IOM uint16_t TRNCNT : 16; /*!< [15..0] Transaction Counter                                               */
        } N_b;
    };
} R_USB_HS0_PIPE_TR_Type;               /*!< Size = 4 (0x4)                                                           */

/** @} */ /* End of group Device_Peripheral_clusters */

/* =========================================================================================================================== */
/* ================                                         R_USB_FS0                                         ================ */
/* =========================================================================================================================== */

/**
 * @brief USB 2.0 Module (R_USB_FS0)
 */

typedef struct                         /*!< (@ 0x40090000) R_USB_FS0 Structure                                        */
{
    union
    {
        __IOM uint16_t SYSCFG;         /*!< (@ 0x00000000) System Configuration Control Register                      */

        struct
        {
            __IOM uint16_t USBE  : 1;  /*!< [0..0] USB Operation Enable                                               */
            uint16_t             : 2;
            __IOM uint16_t DMRPU : 1;  /*!< [3..3] D- Line Resistor Control                                           */
            __IOM uint16_t DPRPU : 1;  /*!< [4..4] D+ Line Resistor Control                                           */
            __IOM uint16_t DRPD  : 1;  /*!< [5..5] D+/D- Line Resistor Control                                        */
            __IOM uint16_t DCFM  : 1;  /*!< [6..6] Controller Function Select                                         */
            uint16_t             : 1;
            __IOM uint16_t CNEN  : 1;  /*!< [8..8] CNEN Single End Receiver Enable                                    */
            uint16_t             : 1;
            __IOM uint16_t SCKE  : 1;  /*!< [10..10] USB Clock Enable                                                 */
            uint16_t             : 5;
        } SYSCFG_b;
    };

    union
    {
        __IOM uint16_t BUSWAIT;        /*!< (@ 0x00000002) CPU Bus Wait Register                                      */

        struct
        {
            __IOM uint16_t BWAIT : 4;  /*!< [3..0] CPU Bus Access Wait Specification BWAIT waits (BWAIT+2
                                        *   access cycles)                                                            */
            uint16_t : 12;
        } BUSWAIT_b;
    };

    union
    {
        __IM uint16_t SYSSTS0;         /*!< (@ 0x00000004) System Configuration Status Register 0                     */

        struct
        {
            __IM uint16_t LNST  : 2;   /*!< [1..0] USB Data Line Status Monitor                                       */
            __IM uint16_t IDMON : 1;   /*!< [2..2] External ID0 Input Pin Monitor                                     */
            uint16_t            : 2;
            __IM uint16_t SOFEA : 1;   /*!< [5..5] SOF Active Monitor While Host Controller Function is
                                        *   Selected.                                                                 */
            __IM uint16_t HTACT  : 1;  /*!< [6..6] USB Host Sequencer Status Monitor                                  */
            uint16_t             : 7;
            __IM uint16_t OVCMON : 2;  /*!< [15..14] External USB0_OVRCURA/ USB0_OVRCURB Input Pin MonitorThe
                                        *   OCVMON[1] bit indicates the status of the USBHS_OVRCURA
                                        *   pin. The OCVMON[0] bit indicates the status of the USBHS_OVRCURB
                                        *   pin.                                                                      */
        } SYSSTS0_b;
    };

    union
    {
        __IM uint16_t PLLSTA;          /*!< (@ 0x00000006) PLL Status Register                                        */

        struct
        {
            __IM uint16_t PLLLOCK : 1; /*!< [0..0] PLL Lock Flag                                                      */
            uint16_t              : 15;
        } PLLSTA_b;
    };

    union
    {
        __IOM uint16_t DVSTCTR0;        /*!< (@ 0x00000008) Device State Control Register 0                            */

        struct
        {
            __IM uint16_t RHST     : 3; /*!< [2..0] USB Bus Reset Status                                               */
            uint16_t               : 1;
            __IOM uint16_t UACT    : 1; /*!< [4..4] USB Bus Enable                                                     */
            __IOM uint16_t RESUME  : 1; /*!< [5..5] Resume Output                                                      */
            __IOM uint16_t USBRST  : 1; /*!< [6..6] USB Bus Reset Output                                               */
            __IOM uint16_t RWUPE   : 1; /*!< [7..7] Wakeup Detection Enable                                            */
            __IOM uint16_t WKUP    : 1; /*!< [8..8] Wakeup Output                                                      */
            __IOM uint16_t VBUSEN  : 1; /*!< [9..9] USB_VBUSEN Output Pin Control                                      */
            __IOM uint16_t EXICEN  : 1; /*!< [10..10] USB_EXICEN Output Pin Control                                    */
            __IOM uint16_t HNPBTOA : 1; /*!< [11..11] Host Negotiation Protocol (HNP) Control This bit is
                                         *   used when switching from device B to device A while in
                                         *   OTG mode. If the HNPBTOA bit is 1, the internal function
                                         *   control keeps the suspended state until the HNP processing
                                         *   ends even though SYSCFG.DPRPU = 0 or SYSCFG.DCFM = 1 is
                                         *   set.                                                                      */
            uint16_t : 4;
        } DVSTCTR0_b;
    };
    __IM uint16_t RESERVED;

    union
    {
        __IOM uint16_t TESTMODE;       /*!< (@ 0x0000000C) USB Test Mode Register                                     */

        struct
        {
            __IOM uint16_t UTST : 4;   /*!< [3..0] Test Mode                                                          */
            uint16_t            : 12;
        } TESTMODE_b;
    };
    __IM uint16_t RESERVED1;
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t CFIFO;          /*!< (@ 0x00000014) CFIFO Port Register                                        */

        struct
        {
            union
            {
                __IOM uint16_t CFIFOL;  /*!< (@ 0x00000014) CFIFO Port Register L                                      */
                __IOM uint8_t  CFIFOLL; /*!< (@ 0x00000014) CFIFO Port Register LL                                     */
            };

            union
            {
                __IOM uint16_t CFIFOH; /*!< (@ 0x00000016) CFIFO Port Register H                                      */

                struct
                {
                    __IM uint8_t  RESERVED3;
                    __IOM uint8_t CFIFOHH; /*!< (@ 0x00000017) CFIFO Port Register HH                                     */
                };
            };
        };
    };

    union
    {
        __IOM uint32_t D0FIFO;         /*!< (@ 0x00000018) D0FIFO Port Register                                       */

        struct
        {
            union
            {
                __IOM uint16_t D0FIFOL;  /*!< (@ 0x00000018) D0FIFO Port Register L                                     */
                __IOM uint8_t  D0FIFOLL; /*!< (@ 0x00000018) D0FIFO Port Register LL                                    */
            };

            union
            {
                __IOM uint16_t D0FIFOH; /*!< (@ 0x0000001A) D0FIFO Port Register H                                     */

                struct
                {
                    __IM uint8_t  RESERVED4;
                    __IOM uint8_t D0FIFOHH; /*!< (@ 0x0000001B) D0FIFO Port Register HH                                    */
                };
            };
        };
    };

    union
    {
        __IOM uint32_t D1FIFO;         /*!< (@ 0x0000001C) D1FIFO Port Register                                       */

        struct
        {
            union
            {
                __IOM uint16_t D1FIFOL;  /*!< (@ 0x0000001C) D1FIFO Port Register L                                     */
                __IOM uint8_t  D1FIFOLL; /*!< (@ 0x0000001C) D1FIFO Port Register LL                                    */
            };

            union
            {
                __IOM uint16_t D1FIFOH; /*!< (@ 0x0000001E) D1FIFO Port Register H                                     */

                struct
                {
                    __IM uint8_t  RESERVED5;
                    __IOM uint8_t D1FIFOHH; /*!< (@ 0x0000001F) D1FIFO Port Register HH                                    */
                };
            };
        };
    };

    union
    {
        __IOM uint16_t CFIFOSEL;        /*!< (@ 0x00000020) CFIFO Port Select Register                                 */

        struct
        {
            __IOM uint16_t CURPIPE : 4; /*!< [3..0] CFIFO Port Access Pipe Specification                               */
            uint16_t               : 1;
            __IOM uint16_t ISEL    : 1; /*!< [5..5] CFIFO Port Access Direction When DCP is Selected                   */
            uint16_t               : 2;
            __IOM uint16_t BIGEND  : 1; /*!< [8..8] CFIFO Port Endian Control                                          */
            uint16_t               : 1;
            __IOM uint16_t MBW     : 2; /*!< [11..10] CFIFO Port Access Bit Width                                      */
            uint16_t               : 2;
            __IOM uint16_t REW     : 1; /*!< [14..14] Buffer Pointer Rewind                                            */
            __IOM uint16_t RCNT    : 1; /*!< [15..15] Read Count Mode                                                  */
        } CFIFOSEL_b;
    };

    union
    {
        __IOM uint16_t CFIFOCTR;       /*!< (@ 0x00000022) CFIFO Port Control Register                                */

        struct
        {
            __IM uint16_t DTLN : 12;   /*!< [11..0] Receive Data LengthIndicates the length of the receive
                                        *   data.                                                                     */
            uint16_t            : 1;
            __IM uint16_t  FRDY : 1;   /*!< [13..13] FIFO Port Ready                                                  */
            __IOM uint16_t BCLR : 1;   /*!< [14..14] CPU Buffer ClearNote: Only 0 can be read.                        */
            __IOM uint16_t BVAL : 1;   /*!< [15..15] Buffer Memory Valid Flag                                         */
        } CFIFOCTR_b;
    };
    __IM uint32_t RESERVED6;

    union
    {
        __IOM uint16_t D0FIFOSEL;       /*!< (@ 0x00000028) D0FIFO Port Select Register                                */

        struct
        {
            __IOM uint16_t CURPIPE : 4; /*!< [3..0] FIFO Port Access Pipe Specification                                */
            uint16_t               : 4;
            __IOM uint16_t BIGEND  : 1; /*!< [8..8] FIFO Port Endian Control                                           */
            uint16_t               : 1;
            __IOM uint16_t MBW     : 2; /*!< [11..10] FIFO Port Access Bit Width                                       */
            __IOM uint16_t DREQE   : 1; /*!< [12..12] DMA/DTC Transfer Request Enable                                  */
            __IOM uint16_t DCLRM   : 1; /*!< [13..13] Auto Buffer Memory Clear Mode Accessed after Specified
                                         *   Pipe Data is Read                                                         */
            __IOM uint16_t REW  : 1;    /*!< [14..14] Buffer Pointer RewindNote: Only 0 can be read.                   */
            __IOM uint16_t RCNT : 1;    /*!< [15..15] Read Count Mode                                                  */
        } D0FIFOSEL_b;
    };

    union
    {
        __IOM uint16_t D0FIFOCTR;      /*!< (@ 0x0000002A) D0FIFO Port Control Register                               */

        struct
        {
            __IM uint16_t DTLN : 12;   /*!< [11..0] Receive Data LengthIndicates the length of the receive
                                        *   data.                                                                     */
            uint16_t            : 1;
            __IM uint16_t  FRDY : 1;   /*!< [13..13] FIFO Port Ready                                                  */
            __IOM uint16_t BCLR : 1;   /*!< [14..14] CPU Buffer ClearNote: Only 0 can be read.                        */
            __IOM uint16_t BVAL : 1;   /*!< [15..15] Buffer Memory Valid Flag                                         */
        } D0FIFOCTR_b;
    };

    union
    {
        __IOM uint16_t D1FIFOSEL;       /*!< (@ 0x0000002C) D1FIFO Port Select Register                                */

        struct
        {
            __IOM uint16_t CURPIPE : 4; /*!< [3..0] FIFO Port Access Pipe Specification                                */
            uint16_t               : 4;
            __IOM uint16_t BIGEND  : 1; /*!< [8..8] FIFO Port Endian Control                                           */
            uint16_t               : 1;
            __IOM uint16_t MBW     : 2; /*!< [11..10] FIFO Port Access Bit Width                                       */
            __IOM uint16_t DREQE   : 1; /*!< [12..12] DMA/DTC Transfer Request Enable                                  */
            __IOM uint16_t DCLRM   : 1; /*!< [13..13] Auto Buffer Memory Clear Mode Accessed after Specified
                                         *   Pipe Data is Read                                                         */
            __IOM uint16_t REW  : 1;    /*!< [14..14] Buffer Pointer Rewind                                            */
            __IOM uint16_t RCNT : 1;    /*!< [15..15] Read Count Mode                                                  */
        } D1FIFOSEL_b;
    };

    union
    {
        __IOM uint16_t D1FIFOCTR;      /*!< (@ 0x0000002E) D1FIFO Port Control Register                               */

        struct
        {
            __IM uint16_t DTLN : 12;   /*!< [11..0] Receive Data LengthIndicates the length of the receive
                                        *   data.                                                                     */
            uint16_t            : 1;
            __IM uint16_t  FRDY : 1;   /*!< [13..13] FIFO Port Ready                                                  */
            __IOM uint16_t BCLR : 1;   /*!< [14..14] CPU Buffer ClearNote: Only 0 can be read.                        */
            __IOM uint16_t BVAL : 1;   /*!< [15..15] Buffer Memory Valid Flag                                         */
        } D1FIFOCTR_b;
    };

    union
    {
        __IOM uint16_t INTENB0;        /*!< (@ 0x00000030) Interrupt Enable Register 0                                */

        struct
        {
            uint16_t             : 8;
            __IOM uint16_t BRDYE : 1;  /*!< [8..8] Buffer Ready Interrupt Enable                                      */
            __IOM uint16_t NRDYE : 1;  /*!< [9..9] Buffer Not Ready Response Interrupt Enable                         */
            __IOM uint16_t BEMPE : 1;  /*!< [10..10] Buffer Empty Interrupt Enable                                    */
            __IOM uint16_t CTRE  : 1;  /*!< [11..11] Control Transfer Stage Transition Interrupt Enable               */
            __IOM uint16_t DVSE  : 1;  /*!< [12..12] Device State Transition Interrupt Enable                         */
            __IOM uint16_t SOFE  : 1;  /*!< [13..13] Frame Number Update Interrupt Enable                             */
            __IOM uint16_t RSME  : 1;  /*!< [14..14] Resume Interrupt Enable                                          */
            __IOM uint16_t VBSE  : 1;  /*!< [15..15] VBUS Interrupt Enable                                            */
        } INTENB0_b;
    };

    union
    {
        __IOM uint16_t INTENB1;            /*!< (@ 0x00000032) Interrupt Enable Register 1                                */

        struct
        {
            __IOM uint16_t PDDETINTE0 : 1; /*!< [0..0] PDDETINT0 Detection Interrupt Enable                               */
            uint16_t                  : 3;
            __IOM uint16_t SACKE      : 1; /*!< [4..4] Setup Transaction Normal Response Interrupt Enable                 */
            __IOM uint16_t SIGNE      : 1; /*!< [5..5] Setup Transaction Error Interrupt Enable                           */
            __IOM uint16_t EOFERRE    : 1; /*!< [6..6] EOF Error Detection Interrupt Enable                               */
            uint16_t                  : 4;
            __IOM uint16_t ATTCHE     : 1; /*!< [11..11] Connection Detection Interrupt Enable                            */
            __IOM uint16_t DTCHE      : 1; /*!< [12..12] Disconnection Detection Interrupt Enable                         */
            uint16_t                  : 1;
            __IOM uint16_t BCHGE      : 1; /*!< [14..14] USB Bus Change Interrupt Enable                                  */
            __IOM uint16_t OVRCRE     : 1; /*!< [15..15] Overcurrent Input Change Interrupt Enable                        */
        } INTENB1_b;
    };
    __IM uint16_t RESERVED7;

    union
    {
        __IOM uint16_t BRDYENB;            /*!< (@ 0x00000036) BRDY Interrupt Enable Register                             */

        struct
        {
            __IOM uint16_t PIPE0BRDYE : 1; /*!< [0..0] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE1BRDYE : 1; /*!< [1..1] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE2BRDYE : 1; /*!< [2..2] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE3BRDYE : 1; /*!< [3..3] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE4BRDYE : 1; /*!< [4..4] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE5BRDYE : 1; /*!< [5..5] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE6BRDYE : 1; /*!< [6..6] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE7BRDYE : 1; /*!< [7..7] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE8BRDYE : 1; /*!< [8..8] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE9BRDYE : 1; /*!< [9..9] BRDY Interrupt Enable for PIPE                                     */
            uint16_t                  : 6;
        } BRDYENB_b;
    };

    union
    {
        __IOM uint16_t NRDYENB;            /*!< (@ 0x00000038) NRDY Interrupt Enable Register                             */

        struct
        {
            __IOM uint16_t PIPE0NRDYE : 1; /*!< [0..0] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE1NRDYE : 1; /*!< [1..1] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE2NRDYE : 1; /*!< [2..2] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE3NRDYE : 1; /*!< [3..3] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE4NRDYE : 1; /*!< [4..4] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE5NRDYE : 1; /*!< [5..5] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE6NRDYE : 1; /*!< [6..6] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE7NRDYE : 1; /*!< [7..7] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE8NRDYE : 1; /*!< [8..8] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE9NRDYE : 1; /*!< [9..9] NRDY Interrupt Enable for PIPE                                     */
            uint16_t                  : 6;
        } NRDYENB_b;
    };

    union
    {
        __IOM uint16_t BEMPENB;            /*!< (@ 0x0000003A) BEMP Interrupt Enable Register                             */

        struct
        {
            __IOM uint16_t PIPE0BEMPE : 1; /*!< [0..0] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE1BEMPE : 1; /*!< [1..1] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE2BEMPE : 1; /*!< [2..2] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE3BEMPE : 1; /*!< [3..3] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE4BEMPE : 1; /*!< [4..4] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE5BEMPE : 1; /*!< [5..5] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE6BEMPE : 1; /*!< [6..6] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE7BEMPE : 1; /*!< [7..7] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE8BEMPE : 1; /*!< [8..8] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE9BEMPE : 1; /*!< [9..9] BEMP Interrupt Enable for PIPE                                     */
            uint16_t                  : 6;
        } BEMPENB_b;
    };

    union
    {
        __IOM uint16_t SOFCFG;         /*!< (@ 0x0000003C) SOF Output Configuration Register                          */

        struct
        {
            uint16_t                : 4;
            __IM uint16_t  EDGESTS  : 1; /*!< [4..4] Edge Interrupt Output Status Monitor                               */
            __IOM uint16_t INTL     : 1; /*!< [5..5] Interrupt Output Sense Select                                      */
            __IOM uint16_t BRDYM    : 1; /*!< [6..6] BRDY Interrupt Status Clear Timing                                 */
            uint16_t                : 1;
            __IOM uint16_t TRNENSEL : 1; /*!< [8..8] Transaction-Enabled Time Select                                    */
            uint16_t                : 7;
        } SOFCFG_b;
    };

    union
    {
        __IOM uint16_t PHYSET;           /*!< (@ 0x0000003E) PHY Setting Register                                       */

        struct
        {
            __IOM uint16_t DIRPD    : 1; /*!< [0..0] Power-Down Control                                                 */
            __IOM uint16_t PLLRESET : 1; /*!< [1..1] PLL Reset Control                                                  */
            uint16_t                : 1;
            __IOM uint16_t CDPEN    : 1; /*!< [3..3] Charging Downstream Port Enable                                    */
            __IOM uint16_t CLKSEL   : 2; /*!< [5..4] Input System Clock Frequency                                       */
            uint16_t                : 2;
            __IOM uint16_t REPSEL   : 2; /*!< [9..8] Terminating Resistance Adjustment Cycle                            */
            uint16_t                : 1;
            __IOM uint16_t REPSTART : 1; /*!< [11..11] Forcibly Start Terminating Resistance Adjustment                 */
            uint16_t                : 3;
            __IOM uint16_t HSEB     : 1; /*!< [15..15] CL-Only Mode                                                     */
        } PHYSET_b;
    };

    union
    {
        __IOM uint16_t INTSTS0;        /*!< (@ 0x00000040) Interrupt Status Register 0                                */

        struct
        {
            __IM uint16_t  CTSQ  : 3;  /*!< [2..0] Control Transfer Stage                                             */
            __IOM uint16_t VALID : 1;  /*!< [3..3] USB Request Reception                                              */
            __IM uint16_t  DVSQ  : 3;  /*!< [6..4] Device State                                                       */
            __IM uint16_t  VBSTS : 1;  /*!< [7..7] VBUS Input Status                                                  */
            __IM uint16_t  BRDY  : 1;  /*!< [8..8] Buffer Ready Interrupt Status                                      */
            __IM uint16_t  NRDY  : 1;  /*!< [9..9] Buffer Not Ready Interrupt Status                                  */
            __IM uint16_t  BEMP  : 1;  /*!< [10..10] Buffer Empty Interrupt Status                                    */
            __IOM uint16_t CTRT  : 1;  /*!< [11..11] Control Transfer Stage Transition Interrupt Status               */
            __IOM uint16_t DVST  : 1;  /*!< [12..12] Device State Transition Interrupt Status                         */
            __IOM uint16_t SOFR  : 1;  /*!< [13..13] Frame Number Refresh Interrupt Status                            */
            __IOM uint16_t RESM  : 1;  /*!< [14..14] Resume Interrupt Status                                          */
            __IOM uint16_t VBINT : 1;  /*!< [15..15] VBUS Interrupt Status                                            */
        } INTSTS0_b;
    };

    union
    {
        __IOM uint16_t INTSTS1;           /*!< (@ 0x00000042) Interrupt Status Register 1                                */

        struct
        {
            __IOM uint16_t PDDETINT0 : 1; /*!< [0..0] PDDET0 Detection Interrupt Status                                  */
            uint16_t                 : 3;
            __IOM uint16_t SACK      : 1; /*!< [4..4] Setup Transaction Normal Response Interrupt Status                 */
            __IOM uint16_t SIGN      : 1; /*!< [5..5] Setup Transaction Error Interrupt Status                           */
            __IOM uint16_t EOFERR    : 1; /*!< [6..6] EOF Error Detection Interrupt Status                               */
            uint16_t                 : 1;
            __IOM uint16_t LPMEND    : 1; /*!< [8..8] LPM Transaction End Interrupt Status                               */
            __IOM uint16_t L1RSMEND  : 1; /*!< [9..9] L1 Resume End Interrupt Status                                     */
            uint16_t                 : 1;
            __IOM uint16_t ATTCH     : 1; /*!< [11..11] ATTCH Interrupt Status                                           */
            __IOM uint16_t DTCH      : 1; /*!< [12..12] USB Disconnection Detection Interrupt Status                     */
            uint16_t                 : 1;
            __IOM uint16_t BCHG      : 1; /*!< [14..14] USB Bus Change Interrupt Status                                  */
            __IOM uint16_t OVRCR     : 1; /*!< [15..15] Overcurrent Input Change Interrupt Status                        */
        } INTSTS1_b;
    };
    __IM uint16_t RESERVED8;

    union
    {
        __IOM uint16_t BRDYSTS;           /*!< (@ 0x00000046) BRDY Interrupt Status Register                             */

        struct
        {
            __IOM uint16_t PIPE0BRDY : 1; /*!< [0..0] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE1BRDY : 1; /*!< [1..1] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE2BRDY : 1; /*!< [2..2] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE3BRDY : 1; /*!< [3..3] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE4BRDY : 1; /*!< [4..4] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE5BRDY : 1; /*!< [5..5] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE6BRDY : 1; /*!< [6..6] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE7BRDY : 1; /*!< [7..7] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE8BRDY : 1; /*!< [8..8] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE9BRDY : 1; /*!< [9..9] BRDY Interrupt Status for PIPE                                     */
            uint16_t                 : 6;
        } BRDYSTS_b;
    };

    union
    {
        __IOM uint16_t NRDYSTS;           /*!< (@ 0x00000048) NRDY Interrupt Status Register                             */

        struct
        {
            __IOM uint16_t PIPE0NRDY : 1; /*!< [0..0] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE1NRDY : 1; /*!< [1..1] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE2NRDY : 1; /*!< [2..2] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE3NRDY : 1; /*!< [3..3] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE4NRDY : 1; /*!< [4..4] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE5NRDY : 1; /*!< [5..5] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE6NRDY : 1; /*!< [6..6] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE7NRDY : 1; /*!< [7..7] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE8NRDY : 1; /*!< [8..8] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE9NRDY : 1; /*!< [9..9] NRDY Interrupt Status for PIPE                                     */
            uint16_t                 : 6;
        } NRDYSTS_b;
    };

    union
    {
        __IOM uint16_t BEMPSTS;           /*!< (@ 0x0000004A) BEMP Interrupt Status Register                             */

        struct
        {
            __IOM uint16_t PIPE0BEMP : 1; /*!< [0..0] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE1BEMP : 1; /*!< [1..1] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE2BEMP : 1; /*!< [2..2] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE3BEMP : 1; /*!< [3..3] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE4BEMP : 1; /*!< [4..4] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE5BEMP : 1; /*!< [5..5] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE6BEMP : 1; /*!< [6..6] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE7BEMP : 1; /*!< [7..7] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE8BEMP : 1; /*!< [8..8] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE9BEMP : 1; /*!< [9..9] BEMP Interrupt Status for PIPE                                     */
            uint16_t                 : 6;
        } BEMPSTS_b;
    };

    union
    {
        __IOM uint16_t FRMNUM;         /*!< (@ 0x0000004C) Frame Number Register                                      */

        struct
        {
            __IM uint16_t FRNM  : 11;  /*!< [10..0] Frame NumberLatest frame number                                   */
            uint16_t            : 3;
            __IOM uint16_t CRCE : 1;   /*!< [14..14] Receive Data Error                                               */
            __IOM uint16_t OVRN : 1;   /*!< [15..15] Overrun/Underrun Detection Status                                */
        } FRMNUM_b;
    };

    union
    {
        __IOM uint16_t UFRMNUM;        /*!< (@ 0x0000004E) uFrame Number Register                                     */

        struct
        {
            __IM uint16_t UFRNM  : 3;  /*!< [2..0] MicroframeIndicate the microframe number.                          */
            uint16_t             : 12;
            __IOM uint16_t DVCHG : 1;  /*!< [15..15] Device State Change                                              */
        } UFRMNUM_b;
    };

    union
    {
        __IOM uint16_t USBADDR;           /*!< (@ 0x00000050) USB Address Register                                       */

        struct
        {
            __IM uint16_t USBADDR : 7;    /*!< [6..0] USB Address In device controller mode, these flags indicate
                                           *   the USB address assigned by the host when the USBHS processed
                                           *   the SET_ADDRESS request successfully.                                     */
            uint16_t                 : 1;
            __IOM uint16_t STSRECOV0 : 3; /*!< [10..8] Status Recovery                                                   */
            uint16_t                 : 5;
        } USBADDR_b;
    };
    __IM uint16_t RESERVED9;

    union
    {
        __IOM uint16_t USBREQ;                /*!< (@ 0x00000054) USB Request Type Register                                  */

        struct
        {
            __IOM uint16_t BMREQUESTTYPE : 8; /*!< [7..0] Request TypeThese bits store the USB request bmRequestType
                                               *   value.                                                                    */
            __IOM uint16_t BREQUEST : 8;      /*!< [15..8] RequestThese bits store the USB request bRequest value.           */
        } USBREQ_b;
    };

    union
    {
        __IOM uint16_t USBVAL;          /*!< (@ 0x00000056) USB Request Value Register                                 */

        struct
        {
            __IOM uint16_t WVALUE : 16; /*!< [15..0] ValueThese bits store the USB request Value value.                */
        } USBVAL_b;
    };

    union
    {
        __IOM uint16_t USBINDX;         /*!< (@ 0x00000058) USB Request Index Register                                 */

        struct
        {
            __IOM uint16_t WINDEX : 16; /*!< [15..0] IndexThese bits store the USB request wIndex value.               */
        } USBINDX_b;
    };

    union
    {
        __IOM uint16_t USBLENG;          /*!< (@ 0x0000005A) USB Request Length Register                                */

        struct
        {
            __IOM uint16_t WLENGTH : 16; /*!< [15..0] LengthThese bits store the USB request wLength value.             */
        } USBLENG_b;
    };

    union
    {
        __IOM uint16_t DCPCFG;         /*!< (@ 0x0000005C) DCP Configuration Register                                 */

        struct
        {
            uint16_t              : 4;
            __IOM uint16_t DIR    : 1; /*!< [4..4] Transfer Direction                                                 */
            uint16_t              : 2;
            __IOM uint16_t SHTNAK : 1; /*!< [7..7] Pipe Disabled at End of Transfer                                   */
            __IOM uint16_t CNTMD  : 1; /*!< [8..8] Continuous Transfer Mode                                           */
            uint16_t              : 7;
        } DCPCFG_b;
    };

    union
    {
        __IOM uint16_t DCPMAXP;        /*!< (@ 0x0000005E) DCP Maximum Packet Size Register                           */

        struct
        {
            __IOM uint16_t MXPS : 7;   /*!< [6..0] Maximum Packet SizeThese bits set the maximum amount
                                        *   of data (maximum packet size) in payloads for the DCP.                    */
            uint16_t              : 5;
            __IOM uint16_t DEVSEL : 4; /*!< [15..12] Device Select                                                    */
        } DCPMAXP_b;
    };

    union
    {
        __IOM uint16_t DCPCTR;           /*!< (@ 0x00000060) DCP Control Register                                       */

        struct
        {
            __IOM uint16_t PID      : 2; /*!< [1..0] Response PID                                                       */
            __IOM uint16_t CCPL     : 1; /*!< [2..2] Control Transfer End Enable                                        */
            uint16_t                : 2;
            __IM uint16_t  PBUSY    : 1; /*!< [5..5] Pipe Busy                                                          */
            __IM uint16_t  SQMON    : 1; /*!< [6..6] Sequence Toggle Bit Monitor                                        */
            __IOM uint16_t SQSET    : 1; /*!< [7..7] Sequence Toggle Bit Set                                            */
            __IOM uint16_t SQCLR    : 1; /*!< [8..8] Sequence Toggle Bit Clear                                          */
            uint16_t                : 2;
            __IOM uint16_t SUREQCLR : 1; /*!< [11..11] SUREQ Bit Clear                                                  */
            uint16_t                : 2;
            __IOM uint16_t SUREQ    : 1; /*!< [14..14] Setup Token Transmission                                         */
            __IM uint16_t  BSTS     : 1; /*!< [15..15] Buffer Status                                                    */
        } DCPCTR_b;
    };
    __IM uint16_t RESERVED10;

    union
    {
        __IOM uint16_t PIPESEL;         /*!< (@ 0x00000064) Pipe Window Select Register                                */

        struct
        {
            __IOM uint16_t PIPESEL : 4; /*!< [3..0] Pipe Window Select                                                 */
            uint16_t               : 12;
        } PIPESEL_b;
    };
    __IM uint16_t RESERVED11;

    union
    {
        __IOM uint16_t PIPECFG;        /*!< (@ 0x00000068) Pipe Configuration Register                                */

        struct
        {
            __IOM uint16_t EPNUM : 4;  /*!< [3..0] Endpoint NumberThese bits specify the endpoint number
                                        *   for the selected pipe.Setting 0000b means unused pipe.                    */
            __IOM uint16_t DIR    : 1; /*!< [4..4] Transfer Direction                                                 */
            uint16_t              : 2;
            __IOM uint16_t SHTNAK : 1; /*!< [7..7] Pipe Disabled at End of Transfer                                   */
            uint16_t              : 1;
            __IOM uint16_t DBLB   : 1; /*!< [9..9] Double Buffer Mode                                                 */
            __IOM uint16_t BFRE   : 1; /*!< [10..10] BRDY Interrupt Operation Specification                           */
            uint16_t              : 3;
            __IOM uint16_t TYPE   : 2; /*!< [15..14] Transfer Type                                                    */
        } PIPECFG_b;
    };
    __IM uint16_t RESERVED12;

    union
    {
        __IOM uint16_t PIPEMAXP;       /*!< (@ 0x0000006C) Pipe Maximum Packet Size Register                          */

        struct
        {
            __IOM uint16_t MXPS : 9;   /*!< [8..0] Maximum Packet SizePIPE1 and PIPE2: 1 byte (001h) to
                                        *   256 bytes (100h)PIPE3 to PIPE5: 8 bytes (008h), 16 bytes
                                        *   (010h), 32 bytes (020h), 64 bytes (040h) (Bits [8:7] and
                                        *   [2:0] are not provided.)PIPE6 to PIPE9: 1 byte (001h) to
                                        *   64 bytes (040h) (Bits [8:7] are not provided.)                            */
            uint16_t              : 3;
            __IOM uint16_t DEVSEL : 4; /*!< [15..12] Device Select                                                    */
        } PIPEMAXP_b;
    };

    union
    {
        __IOM uint16_t PIPEPERI;       /*!< (@ 0x0000006E) Pipe Cycle Control Register                                */

        struct
        {
            __IOM uint16_t IITV : 3;   /*!< [2..0] Interval Error Detection IntervalSpecifies the interval
                                        *   error detection timing for the selected pipe in terms of
                                        *   frames, which is expressed as nth power of 2.                             */
            uint16_t            : 9;
            __IOM uint16_t IFIS : 1;   /*!< [12..12] Isochronous IN Buffer Flush                                      */
            uint16_t            : 3;
        } PIPEPERI_b;
    };

    union
    {
        __IOM uint16_t PIPE_CTR[9];    /*!< (@ 0x00000070) Pipe [0..8] Control Register                               */

        struct
        {
            __IOM uint16_t PID    : 2; /*!< [1..0] Response PID                                                       */
            uint16_t              : 3;
            __IM uint16_t  PBUSY  : 1; /*!< [5..5] Pipe Busy                                                          */
            __IM uint16_t  SQMON  : 1; /*!< [6..6] Sequence Toggle Bit Confirmation                                   */
            __IOM uint16_t SQSET  : 1; /*!< [7..7] Sequence Toggle Bit Set                                            */
            __IOM uint16_t SQCLR  : 1; /*!< [8..8] Sequence Toggle Bit Clear                                          */
            __IOM uint16_t ACLRM  : 1; /*!< [9..9] Auto Buffer Clear Mode                                             */
            __IOM uint16_t ATREPM : 1; /*!< [10..10] Auto Response Mode                                               */
            uint16_t              : 1;
            __IM uint16_t CSSTS   : 1; /*!< [12..12] CSSTS StatusThis bit indicates the CSPLIT status of
                                        *   Split Transaction of the relevant pipe                                    */
            __IOM uint16_t CSCLR : 1;  /*!< [13..13] CSPLIT Status ClearSet this bit to 1 when clearing
                                        *   the CSSTS bit of the relevant pipe                                        */
            __IM uint16_t INBUFM : 1;  /*!< [14..14] Transmit Buffer Monitor                                          */
            __IM uint16_t BSTS   : 1;  /*!< [15..15] Buffer Status                                                    */
        } PIPE_CTR_b[9];
    };
    __IM uint16_t                RESERVED13;
    __IM uint32_t                RESERVED14[3];
    __IOM R_USB_FS0_PIPE_TR_Type PIPE_TR[5]; /*!< (@ 0x00000090) Pipe Transaction Counter Registers                         */
    __IM uint32_t                RESERVED15[3];

    union
    {
        __IOM uint16_t USBBCCTRL0;         /*!< (@ 0x000000B0) BC Control Register 0                                      */

        struct
        {
            __IOM uint16_t RPDME0     : 1; /*!< [0..0] D- Pin Pull-Down Control                                           */
            __IOM uint16_t IDPSRCE0   : 1; /*!< [1..1] D+ Pin IDPSRC Output Control                                       */
            __IOM uint16_t IDMSINKE0  : 1; /*!< [2..2] D- Pin 0.6 V Input Detection (Comparator and Sink) Control         */
            __IOM uint16_t VDPSRCE0   : 1; /*!< [3..3] D+ Pin VDPSRC (0.6 V) Output Control                               */
            __IOM uint16_t IDPSINKE0  : 1; /*!< [4..4] D+ Pin 0.6 V Input Detection (Comparator and Sink) Control         */
            __IOM uint16_t VDMSRCE0   : 1; /*!< [5..5] D- Pin VDMSRC (0.6 V) Output Control                               */
            uint16_t                  : 1;
            __IOM uint16_t BATCHGE0   : 1; /*!< [7..7] BC (Battery Charger) Function Ch0 General Enable Control           */
            __IM uint16_t  CHGDETSTS0 : 1; /*!< [8..8] D- Pin 0.6 V Input Detection Status                                */
            __IM uint16_t  PDDETSTS0  : 1; /*!< [9..9] D+ Pin 0.6 V Input Detection Status                                */
            uint16_t                  : 6;
        } USBBCCTRL0_b;
    };
    __IM uint16_t RESERVED16;
    __IM uint32_t RESERVED17[4];

    union
    {
        __IOM uint16_t UCKSEL;          /*!< (@ 0x000000C4) USB Clock Selection Register                               */

        struct
        {
            __IOM uint16_t UCKSELC : 1; /*!< [0..0] USB Clock Selection                                                */
            uint16_t               : 15;
        } UCKSEL_b;
    };
    __IM uint16_t RESERVED18;
    __IM uint32_t RESERVED19;

    union
    {
        __IOM uint16_t USBMC;           /*!< (@ 0x000000CC) USB Module Control Register                                */

        struct
        {
            __IOM uint16_t VDDUSBE : 1; /*!< [0..0] USB Reference Power Supply Circuit On/Off Control                  */
            uint16_t               : 6;
            __IOM uint16_t VDCEN   : 1; /*!< [7..7] USB Regulator On/Off Control                                       */
            uint16_t               : 8;
        } USBMC_b;
    };
    __IM uint16_t RESERVED20;

    union
    {
        __IOM uint16_t DEVADD[10];     /*!< (@ 0x000000D0) Device Address Configuration Register                      */

        struct
        {
            uint16_t               : 6;
            __IOM uint16_t USBSPD  : 2; /*!< [7..6] Transfer Speed of Communication Target Device                      */
            __IOM uint16_t HUBPORT : 3; /*!< [10..8] Communication Target Connecting Hub Port                          */
            __IOM uint16_t UPPHUB  : 4; /*!< [14..11] Communication Target Connecting Hub Register                     */
            uint16_t               : 1;
        } DEVADD_b[10];
    };
    __IM uint32_t RESERVED21[3];

    union
    {
        __IOM uint32_t PHYSLEW;         /*!< (@ 0x000000F0) PHY Cross Point Adjustment Register                        */

        struct
        {
            __IOM uint32_t SLEWR00 : 1; /*!< [0..0] Receiver Cross Point Adjustment 00                                 */
            __IOM uint32_t SLEWR01 : 1; /*!< [1..1] Receiver Cross Point Adjustment 01                                 */
            __IOM uint32_t SLEWF00 : 1; /*!< [2..2] Receiver Cross Point Adjustment 00                                 */
            __IOM uint32_t SLEWF01 : 1; /*!< [3..3] Receiver Cross Point Adjustment 01                                 */
            uint32_t               : 28;
        } PHYSLEW_b;
    };
    __IM uint32_t RESERVED22[3];

    union
    {
        __IOM uint16_t LPCTRL;         /*!< (@ 0x00000100) Low Power Control Register                                 */

        struct
        {
            uint16_t             : 7;
            __IOM uint16_t HWUPM : 1;  /*!< [7..7] Resume Return Mode Setting                                         */
            uint16_t             : 8;
        } LPCTRL_b;
    };

    union
    {
        __IOM uint16_t LPSTS;          /*!< (@ 0x00000102) Low Power Status Register                                  */

        struct
        {
            uint16_t                : 14;
            __IOM uint16_t SUSPENDM : 1; /*!< [14..14] UTMI SuspendM Control                                            */
            uint16_t                : 1;
        } LPSTS_b;
    };
    __IM uint32_t RESERVED23[15];

    union
    {
        __IOM uint16_t BCCTRL;           /*!< (@ 0x00000140) Battery Charging Control Register                          */

        struct
        {
            __IOM uint16_t IDPSRCE  : 1; /*!< [0..0] IDPSRC Control                                                     */
            __IOM uint16_t IDMSINKE : 1; /*!< [1..1] IDMSINK Control                                                    */
            __IOM uint16_t VDPSRCE  : 1; /*!< [2..2] VDPSRC Control                                                     */
            __IOM uint16_t IDPSINKE : 1; /*!< [3..3] IDPSINK Control                                                    */
            __IOM uint16_t VDMSRCE  : 1; /*!< [4..4] VDMSRC Control                                                     */
            __IOM uint16_t DCPMODE  : 1; /*!< [5..5] DCP Mode Control                                                   */
            uint16_t                : 2;
            __IM uint16_t CHGDETSTS : 1; /*!< [8..8] CHGDET Status                                                      */
            __IM uint16_t PDDETSTS  : 1; /*!< [9..9] PDDET Status                                                       */
            uint16_t                : 6;
        } BCCTRL_b;
    };
    __IM uint16_t RESERVED24;

    union
    {
        __IOM uint16_t PL1CTRL1;         /*!< (@ 0x00000144) Function L1 Control Register 1                             */

        struct
        {
            __IOM uint16_t L1RESPEN : 1; /*!< [0..0] L1 Response Enable                                                 */
            __IOM uint16_t L1RESPMD : 2; /*!< [2..1] L1 Response Mode                                                   */
            __IOM uint16_t L1NEGOMD : 1; /*!< [3..3] L1 Response Negotiation Control.NOTE: This bit is valid
                                          *   only when the L1RESPMD[1:0] value is 2'b11.                               */
            __IM uint16_t DVSQ : 4;      /*!< [7..4] DVSQ Extension.DVSQ[3] is Mirror of DVSQ[2:0] in INTSTS0.Indicates
                                          *   the L1 state together with the device state bits DVSQ[2:0].               */
            __IOM uint16_t HIRDTHR : 4;  /*!< [11..8] L1 Response Negotiation Threshold ValueHIRD threshold
                                          *   value used for L1NEGOMD.The format is the same as the HIRD
                                          *   field in HL1CTRL.                                                         */
            uint16_t               : 2;
            __IOM uint16_t L1EXTMD : 1;  /*!< [14..14] PHY Control Mode at L1 Return                                    */
            uint16_t               : 1;
        } PL1CTRL1_b;
    };

    union
    {
        __IOM uint16_t PL1CTRL2;       /*!< (@ 0x00000146) Function L1 Control Register 2                             */

        struct
        {
            uint16_t               : 8;
            __IOM uint16_t HIRDMON : 4; /*!< [11..8] HIRD Value Monitor                                                */
            __IOM uint16_t RWEMON  : 1; /*!< [12..12] RWE Value Monitor                                                */
            uint16_t               : 3;
        } PL1CTRL2_b;
    };

    union
    {
        __IOM uint16_t HL1CTRL1;         /*!< (@ 0x00000148) Host L1 Control Register 1                                 */

        struct
        {
            __IOM uint16_t L1REQ    : 1; /*!< [0..0] L1 Transition Request                                              */
            __IM uint16_t  L1STATUS : 2; /*!< [2..1] L1 Request Completion Status                                       */
            uint16_t                : 13;
        } HL1CTRL1_b;
    };

    union
    {
        __IOM uint16_t HL1CTRL2;       /*!< (@ 0x0000014A) Host L1 Control Register 2                                 */

        struct
        {
            __IOM uint16_t L1ADDR : 4; /*!< [3..0] LPM Token DeviceAddressThese bits specify the value to
                                        *   be set in the ADDR field of LPM token.                                    */
            uint16_t             : 4;
            __IOM uint16_t HIRD  : 4;  /*!< [11..8] LPM Token HIRD                                                    */
            __IOM uint16_t L1RWE : 1;  /*!< [12..12] LPM Token L1 RemoteWake EnableThese bits specify the
                                        *   value to be set in the RWE field of LPM token.                            */
            uint16_t            : 2;
            __IOM uint16_t BESL : 1;   /*!< [15..15] BESL & Alternate HIRDThis bit selects the K-State drive
                                        *   period at the time of L1 Resume.                                          */
        } HL1CTRL2_b;
    };
    __IM uint32_t RESERVED25[5];

    union
    {
        __IM uint32_t DPUSR0R;         /*!< (@ 0x00000160) Deep Standby USB Transceiver Control/Pin Monitor
                                        *                  Register                                                   */

        struct
        {
            uint32_t              : 20;
            __IM uint32_t DOVCAHM : 1;  /*!< [20..20] OVRCURA InputIndicates OVRCURA input signal on the
                                         *   HS side of USB port.                                                      */
            __IM uint32_t DOVCBHM : 1;  /*!< [21..21] OVRCURB InputIndicates OVRCURB input signal on the
                                         *   HS side of USB port.                                                      */
            uint32_t               : 1;
            __IM uint32_t DVBSTSHM : 1; /*!< [23..23] VBUS InputIndicates VBUS input signal on the HS side
                                         *   of USB port.                                                              */
            uint32_t : 8;
        } DPUSR0R_b;
    };

    union
    {
        __IOM uint32_t DPUSR1R;        /*!< (@ 0x00000164) Deep Standby USB Suspend/Resume Interrupt Register         */

        struct
        {
            uint32_t                : 4;
            __IOM uint32_t DOVCAHE  : 1; /*!< [4..4] OVRCURA Interrupt Enable Clear                                     */
            __IOM uint32_t DOVCBHE  : 1; /*!< [5..5] OVRCURB Interrupt Enable Clear                                     */
            uint32_t                : 1;
            __IOM uint32_t DVBSTSHE : 1; /*!< [7..7] VBUS Interrupt Enable/Clear                                        */
            uint32_t                : 12;
            __IM uint32_t DOVCAH    : 1; /*!< [20..20] Indication of Return from OVRCURA Interrupt Source               */
            __IM uint32_t DOVCBH    : 1; /*!< [21..21] Indication of Return from OVRCURB Interrupt Source               */
            uint32_t                : 1;
            __IM uint32_t DVBSTSH   : 1; /*!< [23..23] Indication of Return from VBUS Interrupt Source                  */
            uint32_t                : 8;
        } DPUSR1R_b;
    };

    union
    {
        __IOM uint16_t DPUSR2R;        /*!< (@ 0x00000168) Deep Standby USB Suspend/Resume Interrupt Register         */

        struct
        {
            __IM uint16_t DPINT : 1;   /*!< [0..0] Indication of Return from DP Interrupt Source                      */
            __IM uint16_t DMINT : 1;   /*!< [1..1] Indication of Return from DM Interrupt Source                      */
            uint16_t            : 2;
            __IM uint16_t DPVAL : 1;   /*!< [4..4] DP InputIndicates DP input signal on the HS side of USB
                                        *   port.                                                                     */
            __IM uint16_t DMVAL : 1;   /*!< [5..5] DM InputIndicates DM input signal on the HS side of USB
                                        *   port.                                                                     */
            uint16_t              : 2;
            __IOM uint16_t DPINTE : 1; /*!< [8..8] DP Interrupt Enable Clear                                          */
            __IOM uint16_t DMINTE : 1; /*!< [9..9] DM Interrupt Enable Clear                                          */
            uint16_t              : 6;
        } DPUSR2R_b;
    };

    union
    {
        __IOM uint16_t DPUSRCR;          /*!< (@ 0x0000016A) Deep Standby USB Suspend/Resume Command Register           */

        struct
        {
            __IOM uint16_t FIXPHY   : 1; /*!< [0..0] USB Transceiver Control Fix                                        */
            __IOM uint16_t FIXPHYPD : 1; /*!< [1..1] USB Transceiver Control Fix for PLL                                */
            uint16_t                : 14;
        } DPUSRCR_b;
    };
    __IM uint32_t RESERVED26[165];

    union
    {
        __IOM uint32_t DPUSR0R_FS;      /*!< (@ 0x00000400) Deep Software Standby USB Transceiver Control/Pin
                                         *                  Monitor Register                                           */

        struct
        {
            __IOM uint32_t SRPC0   : 1; /*!< [0..0] USB Single End Receiver Control                                    */
            __IOM uint32_t RPUE0   : 1; /*!< [1..1] DP Pull-Up Resistor Control                                        */
            uint32_t               : 1;
            __IOM uint32_t DRPD0   : 1; /*!< [3..3] D+/D- Pull-Down Resistor Control                                   */
            __IOM uint32_t FIXPHY0 : 1; /*!< [4..4] USB Transceiver Output Fix                                         */
            uint32_t               : 11;
            __IM uint32_t DP0      : 1; /*!< [16..16] USB0 D+ InputIndicates the D+ input signal of the USB.           */
            __IM uint32_t DM0      : 1; /*!< [17..17] USB D-InputIndicates the D- input signal of the USB.             */
            uint32_t               : 2;
            __IM uint32_t DOVCA0   : 1; /*!< [20..20] USB OVRCURA InputIndicates the OVRCURA input signal
                                         *   of the USB.                                                               */
            __IM uint32_t DOVCB0 : 1;   /*!< [21..21] USB OVRCURB InputIndicates the OVRCURB input signal
                                         *   of the USB.                                                               */
            uint32_t              : 1;
            __IM uint32_t DVBSTS0 : 1;  /*!< [23..23] USB VBUS InputIndicates the VBUS input signal of the
                                         *   USB.                                                                      */
            uint32_t : 8;
        } DPUSR0R_FS_b;
    };

    union
    {
        __IOM uint32_t DPUSR1R_FS;        /*!< (@ 0x00000404) Deep Software Standby USB Suspend/Resume Interrupt
                                           *                  Register                                                   */

        struct
        {
            __IOM uint32_t DPINTE0   : 1; /*!< [0..0] USB DP Interrupt Enable/Clear                                      */
            __IOM uint32_t DMINTE0   : 1; /*!< [1..1] USB DM Interrupt Enable/Clear                                      */
            uint32_t                 : 2;
            __IOM uint32_t DOVRCRAE0 : 1; /*!< [4..4] USB OVRCURA Interrupt Enable/Clear                                 */
            __IOM uint32_t DOVRCRBE0 : 1; /*!< [5..5] USB OVRCURB Interrupt Enable/Clear                                 */
            uint32_t                 : 1;
            __IOM uint32_t DVBSE0    : 1; /*!< [7..7] USB VBUS Interrupt Enable/Clear                                    */
            uint32_t                 : 8;
            __IM uint32_t DPINT0     : 1; /*!< [16..16] USB DP Interrupt Source Recovery                                 */
            __IM uint32_t DMINT0     : 1; /*!< [17..17] USB DM Interrupt Source Recovery                                 */
            uint32_t                 : 2;
            __IM uint32_t DOVRCRA0   : 1; /*!< [20..20] USB OVRCURA Interrupt Source Recovery                            */
            __IM uint32_t DOVRCRB0   : 1; /*!< [21..21] USB OVRCURB Interrupt Source Recovery                            */
            uint32_t                 : 1;
            __IM uint32_t DVBINT0    : 1; /*!< [23..23] USB VBUS Interrupt Source Recovery                               */
            uint32_t                 : 8;
        } DPUSR1R_FS_b;
    };
} R_USB_FS0_Type;                         /*!< Size = 1032 (0x408)                                                       */

/* =========================================================================================================================== */
/* ================                                          R_USB_HS0                                          ================ */
/* =========================================================================================================================== */

/**
 * @brief USB 2.0 Module (R_USB_HS0)
 */

typedef struct                         /*!< (@ 0x40090000) R_USB_HS0 Structure                                          */
{
    union
    {
        __IOM uint16_t SYSCFG;         /*!< (@ 0x00000000) System Configuration Control Register                      */

        struct
        {
            __IOM uint16_t USBE  : 1;  /*!< [0..0] USB Operation Enable                                               */
            uint16_t             : 3;
            __IOM uint16_t DPRPU : 1;  /*!< [4..4] D+ Line Resistor Control                                           */
            __IOM uint16_t DRPD  : 1;  /*!< [5..5] D+/D- Line Resistor Control                                        */
            __IOM uint16_t DCFM  : 1;  /*!< [6..6] Controller Function Select                                         */
            __IOM uint16_t HSE   : 1;  /*!< [7..7] High-Speed Operation Enable                                          */
            __IOM uint16_t CNEN  : 1;  /*!< [8..8] CNEN Single End Receiver Enable                                    */
            uint16_t             : 1;
            __IOM uint16_t SCKE  : 1;  /*!< [10..10] USB Clock Enable                                                 */
        } SYSCFG_b;
    };

    union
    {
        __IOM uint16_t BUSWAIT;        /*!< (@ 0x00000002) CPU Bus Wait Register                                      */

        struct
        {
            __IOM uint16_t BWAIT : 4;  /*!< [3..0] CPU Bus Access Wait Specification BWAIT waits (BWAIT+2
                                        *   access cycles)                                                            */
        } BUSWAIT_b;
    };

    union
    {
        __IM uint16_t SYSSTS0;         /*!< (@ 0x00000004) System Configuration Status Register 0                     */

        struct
        {
            __IM uint16_t LNST  : 2;   /*!< [1..0] USB Data Line Status Monitor                                       */
            __IM uint16_t IDMON : 1;   /*!< [2..2] External ID0 Input Pin Monitor                                     */
            uint16_t            : 2;
            __IM uint16_t SOFEA : 1;   /*!< [5..5] SOF Active Monitor While Host Controller Function is
                                        *   Selected.                                                                 */
            __IM uint16_t HTACT  : 1;  /*!< [6..6] USB Host Sequencer Status Monitor                                  */
            uint16_t             : 7;
            __IM uint16_t OVCMON : 2;  /*!< [15..14] External USB0_OVRCURA/ USB0_OVRCURB Input Pin MonitorThe
                                        *   OCVMON[1] bit indicates the status of the USBHS_OVRCURA
                                        *   pin. The OCVMON[0] bit indicates the status of the USBHS_OVRCURB
                                        *   pin.                                                                      */
        } SYSSTS0_b;
    };

    union
    {
        __IM uint16_t PLLSTA;          /*!< (@ 0x00000006) PLL Status Register                                        */

        struct
        {
            __IM uint16_t PLLLOCK : 1; /*!< [0..0] PLL Lock Flag                                                      */
        } PLLSTA_b;
    };

    union
    {
        __IOM uint16_t DVSTCTR0;        /*!< (@ 0x00000008) Device State Control Register 0                            */

        struct
        {
            __IM uint16_t RHST     : 3; /*!< [2..0] USB Bus Reset Status                                               */
            uint16_t               : 1;
            __IOM uint16_t UACT    : 1; /*!< [4..4] USB Bus Enable                                                     */
            __IOM uint16_t RESUME  : 1; /*!< [5..5] Resume Output                                                      */
            __IOM uint16_t USBRST  : 1; /*!< [6..6] USB Bus Reset Output                                               */
            __IOM uint16_t RWUPE   : 1; /*!< [7..7] Wakeup Detection Enable                                            */
            __IOM uint16_t WKUP    : 1; /*!< [8..8] Wakeup Output                                                      */
            __IOM uint16_t VBUSEN  : 1; /*!< [9..9] USB_VBUSEN Output Pin Control                                      */
            __IOM uint16_t EXICEN  : 1; /*!< [10..10] USB_EXICEN Output Pin Control                                    */
            __IOM uint16_t HNPBTOA : 1; /*!< [11..11] Host Negotiation Protocol (HNP) Control This bit is
                                         *   used when switching from device B to device A while in
                                         *   OTG mode. If the HNPBTOA bit is 1, the internal function
                                         *   control keeps the suspended state until the HNP processing
                                         *   ends even though SYSCFG.DPRPU = 0 or SYSCFG.DCFM = 1 is
                                         *   set.                                                                      */
        } DVSTCTR0_b;
    };
    __IM uint16_t RESERVED;

    union
    {
        __IOM uint16_t TESTMODE;       /*!< (@ 0x0000000C) USB Test Mode Register                                     */

        struct
        {
            __IOM uint16_t UTST : 4;   /*!< [3..0] Test Mode                                                          */
        } TESTMODE_b;
    };
    __IM uint16_t RESERVED1;
    __IM uint32_t RESERVED2;

    union
    {
        __IOM uint32_t CFIFO;          /*!< (@ 0x00000014) CFIFO Port Register                                        */

        struct
        {
            union
            {
                __IOM uint16_t CFIFOL;  /*!< (@ 0x00000014) CFIFO Port Register L                                      */
                __IOM uint8_t  CFIFOLL; /*!< (@ 0x00000014) CFIFO Port Register LL                                     */
            };

            union
            {
                __IOM uint16_t CFIFOH; /*!< (@ 0x00000016) CFIFO Port Register H                                      */

                struct
                {
                    __IM uint8_t  RESERVED3;
                    __IOM uint8_t CFIFOHH; /*!< (@ 0x00000017) CFIFO Port Register HH                                     */
                };
            };
        };
    };

    union
    {
        __IOM uint32_t D0FIFO;         /*!< (@ 0x00000018) D0FIFO Port Register                                       */

        struct
        {
            union
            {
                __IOM uint16_t D0FIFOL;  /*!< (@ 0x00000018) D0FIFO Port Register L                                     */
                __IOM uint8_t  D0FIFOLL; /*!< (@ 0x00000018) D0FIFO Port Register LL                                    */
            };

            union
            {
                __IOM uint16_t D0FIFOH; /*!< (@ 0x0000001A) D0FIFO Port Register H                                     */

                struct
                {
                    __IM uint8_t  RESERVED4;
                    __IOM uint8_t D0FIFOHH; /*!< (@ 0x0000001B) D0FIFO Port Register HH                                    */
                };
            };
        };
    };

    union
    {
        __IOM uint32_t D1FIFO;         /*!< (@ 0x0000001C) D1FIFO Port Register                                       */

        struct
        {
            union
            {
                __IOM uint16_t D1FIFOL;  /*!< (@ 0x0000001C) D1FIFO Port Register L                                     */
                __IOM uint8_t  D1FIFOLL; /*!< (@ 0x0000001C) D1FIFO Port Register LL                                    */
            };

            union
            {
                __IOM uint16_t D1FIFOH; /*!< (@ 0x0000001E) D1FIFO Port Register H                                     */

                struct
                {
                    __IM uint8_t  RESERVED5;
                    __IOM uint8_t D1FIFOHH; /*!< (@ 0x0000001F) D1FIFO Port Register HH                                    */
                };
            };
        };
    };

    union
    {
        __IOM uint16_t CFIFOSEL;        /*!< (@ 0x00000020) CFIFO Port Select Register                                 */

        struct
        {
            __IOM uint16_t CURPIPE : 4; /*!< [3..0] CFIFO Port Access Pipe Specification                               */
            uint16_t               : 1;
            __IOM uint16_t ISEL    : 1; /*!< [5..5] CFIFO Port Access Direction When DCP is Selected                   */
            uint16_t               : 2;
            __IOM uint16_t BIGEND  : 1; /*!< [8..8] CFIFO Port Endian Control                                          */
            uint16_t               : 1;
            __IOM uint16_t MBW     : 2; /*!< [11..10] CFIFO Port Access Bit Width                                      */
            uint16_t               : 2;
            __IOM uint16_t REW     : 1; /*!< [14..14] Buffer Pointer Rewind                                            */
            __IOM uint16_t RCNT    : 1; /*!< [15..15] Read Count Mode                                                  */
        } CFIFOSEL_b;
    };

    union
    {
        __IOM uint16_t CFIFOCTR;       /*!< (@ 0x00000022) CFIFO Port Control Register                                */

        struct
        {
            __IM uint16_t DTLN : 12;   /*!< [11..0] Receive Data LengthIndicates the length of the receive
                                        *   data.                                                                     */
            uint16_t            : 1;
            __IM uint16_t  FRDY : 1;   /*!< [13..13] FIFO Port Ready                                                  */
            __IOM uint16_t BCLR : 1;   /*!< [14..14] CPU Buffer ClearNote: Only 0 can be read.                        */
            __IOM uint16_t BVAL : 1;   /*!< [15..15] Buffer Memory Valid Flag                                         */
        } CFIFOCTR_b;
    };
    __IM uint32_t RESERVED6;

    union
    {
        __IOM uint16_t D0FIFOSEL;       /*!< (@ 0x00000028) D0FIFO Port Select Register                                */

        struct
        {
            __IOM uint16_t CURPIPE : 4; /*!< [3..0] FIFO Port Access Pipe Specification                                */
            uint16_t               : 4;
            __IOM uint16_t BIGEND  : 1; /*!< [8..8] FIFO Port Endian Control                                           */
            uint16_t               : 1;
            __IOM uint16_t MBW     : 2; /*!< [11..10] FIFO Port Access Bit Width                                       */
            __IOM uint16_t DREQE   : 1; /*!< [12..12] DMA/DTC Transfer Request Enable                                  */
            __IOM uint16_t DCLRM   : 1; /*!< [13..13] Auto Buffer Memory Clear Mode Accessed after Specified
                                         *   Pipe Data is Read                                                         */
            __IOM uint16_t REW  : 1;    /*!< [14..14] Buffer Pointer RewindNote: Only 0 can be read.                   */
            __IOM uint16_t RCNT : 1;    /*!< [15..15] Read Count Mode                                                  */
        } D0FIFOSEL_b;
    };

    union
    {
        __IOM uint16_t D0FIFOCTR;      /*!< (@ 0x0000002A) D0FIFO Port Control Register                               */

        struct
        {
            __IM uint16_t DTLN : 12;   /*!< [11..0] Receive Data LengthIndicates the length of the receive
                                        *   data.                                                                     */
            uint16_t            : 1;
            __IM uint16_t  FRDY : 1;   /*!< [13..13] FIFO Port Ready                                                  */
            __IOM uint16_t BCLR : 1;   /*!< [14..14] CPU Buffer ClearNote: Only 0 can be read.                        */
            __IOM uint16_t BVAL : 1;   /*!< [15..15] Buffer Memory Valid Flag                                         */
        } D0FIFOCTR_b;
    };

    union
    {
        __IOM uint16_t D1FIFOSEL;       /*!< (@ 0x0000002C) D1FIFO Port Select Register                                */

        struct
        {
            __IOM uint16_t CURPIPE : 4; /*!< [3..0] FIFO Port Access Pipe Specification                                */
            uint16_t               : 4;
            __IOM uint16_t BIGEND  : 1; /*!< [8..8] FIFO Port Endian Control                                           */
            uint16_t               : 1;
            __IOM uint16_t MBW     : 2; /*!< [11..10] FIFO Port Access Bit Width                                       */
            __IOM uint16_t DREQE   : 1; /*!< [12..12] DMA/DTC Transfer Request Enable                                  */
            __IOM uint16_t DCLRM   : 1; /*!< [13..13] Auto Buffer Memory Clear Mode Accessed after Specified
                                         *   Pipe Data is Read                                                         */
            __IOM uint16_t REW  : 1;    /*!< [14..14] Buffer Pointer Rewind                                            */
            __IOM uint16_t RCNT : 1;    /*!< [15..15] Read Count Mode                                                  */
        } D1FIFOSEL_b;
    };

    union
    {
        __IOM uint16_t D1FIFOCTR;      /*!< (@ 0x0000002E) D1FIFO Port Control Register                               */

        struct
        {
            __IM uint16_t DTLN : 12;   /*!< [11..0] Receive Data LengthIndicates the length of the receive
                                        *   data.                                                                     */
            uint16_t            : 1;
            __IM uint16_t  FRDY : 1;   /*!< [13..13] FIFO Port Ready                                                  */
            __IOM uint16_t BCLR : 1;   /*!< [14..14] CPU Buffer ClearNote: Only 0 can be read.                        */
            __IOM uint16_t BVAL : 1;   /*!< [15..15] Buffer Memory Valid Flag                                         */
        } D1FIFOCTR_b;
    };

    union
    {
        __IOM uint16_t INTENB0;        /*!< (@ 0x00000030) Interrupt Enable Register 0                                  */

        struct
        {
            uint16_t             : 8;
            __IOM uint16_t BRDYE : 1;  /*!< [8..8] Buffer Ready Interrupt Enable                                      */
            __IOM uint16_t NRDYE : 1;  /*!< [9..9] Buffer Not Ready Response Interrupt Enable                         */
            __IOM uint16_t BEMPE : 1;  /*!< [10..10] Buffer Empty Interrupt Enable                                    */
            __IOM uint16_t CTRE  : 1;  /*!< [11..11] Control Transfer Stage Transition Interrupt Enable               */
            __IOM uint16_t DVSE  : 1;  /*!< [12..12] Device State Transition Interrupt Enable                         */
            __IOM uint16_t SOFE  : 1;  /*!< [13..13] Frame Number Update Interrupt Enable                             */
            __IOM uint16_t RSME  : 1;  /*!< [14..14] Resume Interrupt Enable                                          */
            __IOM uint16_t VBSE  : 1;  /*!< [15..15] VBUS Interrupt Enable                                            */
        } INTENB0_b;
    };

    union
    {
        __IOM uint16_t INTENB1;            /*!< (@ 0x00000032) Interrupt Enable Register 1                                */

        struct
        {
            __IOM uint16_t PDDETINTE0 : 1; /*!< [0..0] PDDETINT0 Detection Interrupt Enable                               */
            uint16_t                  : 3;
            __IOM uint16_t SACKE      : 1; /*!< [4..4] Setup Transaction Normal Response Interrupt Enable                 */
            __IOM uint16_t SIGNE      : 1; /*!< [5..5] Setup Transaction Error Interrupt Enable                           */
            __IOM uint16_t EOFERRE    : 1; /*!< [6..6] EOF Error Detection Interrupt Enable                               */
            uint16_t                  : 1;
            __IOM uint16_t LPMENDE    : 1; /*!< [8..8] LPM Transaction End Interrupt Enable                               */
            __IOM uint16_t L1RSMENDE  : 1; /*!< [9..9] L1 Resume End Interrupt Enable                                     */
            uint16_t                  : 1;
            __IOM uint16_t ATTCHE     : 1; /*!< [11..11] Connection Detection Interrupt Enable                            */
            __IOM uint16_t DTCHE      : 1; /*!< [12..12] Disconnection Detection Interrupt Enable                         */
            uint16_t                  : 1;
            __IOM uint16_t BCHGE      : 1; /*!< [14..14] USB Bus Change Interrupt Enable                                  */
            __IOM uint16_t OVRCRE     : 1; /*!< [15..15] Overcurrent Input Change Interrupt Enable                        */
        } INTENB1_b;
    };
    __IM uint16_t RESERVED7;

    union
    {
        __IOM uint16_t BRDYENB;            /*!< (@ 0x00000036) BRDY Interrupt Enable Register                             */

        struct
        {
            __IOM uint16_t PIPE0BRDYE : 1; /*!< [0..0] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE1BRDYE : 1; /*!< [1..1] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE2BRDYE : 1; /*!< [2..2] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE3BRDYE : 1; /*!< [3..3] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE4BRDYE : 1; /*!< [4..4] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE5BRDYE : 1; /*!< [5..5] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE6BRDYE : 1; /*!< [6..6] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE7BRDYE : 1; /*!< [7..7] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE8BRDYE : 1; /*!< [8..8] BRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE9BRDYE : 1; /*!< [9..9] BRDY Interrupt Enable for PIPE                                     */
        } BRDYENB_b;
    };

    union
    {
        __IOM uint16_t NRDYENB;            /*!< (@ 0x00000038) NRDY Interrupt Enable Register                             */

        struct
        {
            __IOM uint16_t PIPE0NRDYE : 1; /*!< [0..0] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE1NRDYE : 1; /*!< [1..1] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE2NRDYE : 1; /*!< [2..2] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE3NRDYE : 1; /*!< [3..3] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE4NRDYE : 1; /*!< [4..4] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE5NRDYE : 1; /*!< [5..5] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE6NRDYE : 1; /*!< [6..6] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE7NRDYE : 1; /*!< [7..7] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE8NRDYE : 1; /*!< [8..8] NRDY Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE9NRDYE : 1; /*!< [9..9] NRDY Interrupt Enable for PIPE                                     */
        } NRDYENB_b;
    };

    union
    {
        __IOM uint16_t BEMPENB;            /*!< (@ 0x0000003A) BEMP Interrupt Enable Register                             */

        struct
        {
            __IOM uint16_t PIPE0BEMPE : 1; /*!< [0..0] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE1BEMPE : 1; /*!< [1..1] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE2BEMPE : 1; /*!< [2..2] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE3BEMPE : 1; /*!< [3..3] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE4BEMPE : 1; /*!< [4..4] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE5BEMPE : 1; /*!< [5..5] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE6BEMPE : 1; /*!< [6..6] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE7BEMPE : 1; /*!< [7..7] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE8BEMPE : 1; /*!< [8..8] BEMP Interrupt Enable for PIPE                                     */
            __IOM uint16_t PIPE9BEMPE : 1; /*!< [9..9] BEMP Interrupt Enable for PIPE                                     */
        } BEMPENB_b;
    };

    union
    {
        __IOM uint16_t SOFCFG;         /*!< (@ 0x0000003C) SOF Output Configuration Register                          */

        struct
        {
            uint16_t                : 4;
            __IM uint16_t  EDGESTS  : 1; /*!< [4..4] Edge Interrupt Output Status Monitor                               */
            __IOM uint16_t INTL     : 1; /*!< [5..5] Interrupt Output Sense Select                                      */
            __IOM uint16_t BRDYM    : 1; /*!< [6..6] BRDY Interrupt Status Clear Timing                                 */
            uint16_t                : 1;
            __IOM uint16_t TRNENSEL : 1; /*!< [8..8] Transaction-Enabled Time Select                                    */
        } SOFCFG_b;
    };

    union
    {
        __IOM uint16_t PHYSET;           /*!< (@ 0x0000003E) PHY Setting Register                                       */

        struct
        {
            __IOM uint16_t DIRPD    : 1; /*!< [0..0] Power-Down Control                                                 */
            __IOM uint16_t PLLRESET : 1; /*!< [1..1] PLL Reset Control                                                  */
            uint16_t                : 1;
            __IOM uint16_t CDPEN    : 1; /*!< [3..3] Charging Downstream Port Enable                                    */
            __IOM uint16_t CLKSEL   : 2; /*!< [5..4] Input System Clock Frequency                                       */
            uint16_t                : 2;
            __IOM uint16_t REPSEL   : 2; /*!< [9..8] Terminating Resistance Adjustment Cycle                            */
            uint16_t                : 1;
            __IOM uint16_t REPSTART : 1; /*!< [11..11] Forcibly Start Terminating Resistance Adjustment                 */
            uint16_t                : 3;
            __IOM uint16_t HSEB     : 1; /*!< [15..15] CL-Only Mode                                                     */
        } PHYSET_b;
    };

    union
    {
        __IOM uint16_t INTSTS0;        /*!< (@ 0x00000040) Interrupt Status Register 0                                */

        struct
        {
            __IM uint16_t  CTSQ  : 3;  /*!< [2..0] Control Transfer Stage                                             */
            __IOM uint16_t VALID : 1;  /*!< [3..3] USB Request Reception                                              */
            __IM uint16_t  DVSQ  : 3;  /*!< [6..4] Device State                                                       */
            __IM uint16_t  VBSTS : 1;  /*!< [7..7] VBUS Input Status                                                  */
            __IM uint16_t  BRDY  : 1;  /*!< [8..8] Buffer Ready Interrupt Status                                      */
            __IM uint16_t  NRDY  : 1;  /*!< [9..9] Buffer Not Ready Interrupt Status                                  */
            __IM uint16_t  BEMP  : 1;  /*!< [10..10] Buffer Empty Interrupt Status                                    */
            __IOM uint16_t CTRT  : 1;  /*!< [11..11] Control Transfer Stage Transition Interrupt Status               */
            __IOM uint16_t DVST  : 1;  /*!< [12..12] Device State Transition Interrupt Status                         */
            __IOM uint16_t SOFR  : 1;  /*!< [13..13] Frame Number Refresh Interrupt Status                            */
            __IOM uint16_t RESM  : 1;  /*!< [14..14] Resume Interrupt Status                                          */
            __IOM uint16_t VBINT : 1;  /*!< [15..15] VBUS Interrupt Status                                            */
        } INTSTS0_b;
    };

    union
    {
        __IOM uint16_t INTSTS1;           /*!< (@ 0x00000042) Interrupt Status Register 1                                */

        struct
        {
            __IOM uint16_t PDDETINT0 : 1; /*!< [0..0] PDDET0 Detection Interrupt Status                                  */
            uint16_t                 : 3;
            __IOM uint16_t SACK      : 1; /*!< [4..4] Setup Transaction Normal Response Interrupt Status                 */
            __IOM uint16_t SIGN      : 1; /*!< [5..5] Setup Transaction Error Interrupt Status                           */
            __IOM uint16_t EOFERR    : 1; /*!< [6..6] EOF Error Detection Interrupt Status                               */
            uint16_t                 : 1;
            __IOM uint16_t LPMEND    : 1; /*!< [8..8] LPM Transaction End Interrupt Status                               */
            __IOM uint16_t L1RSMEND  : 1; /*!< [9..9] L1 Resume End Interrupt Status                                     */
            uint16_t                 : 1;
            __IOM uint16_t ATTCH     : 1; /*!< [11..11] ATTCH Interrupt Status                                           */
            __IOM uint16_t DTCH      : 1; /*!< [12..12] USB Disconnection Detection Interrupt Status                     */
            uint16_t                 : 1;
            __IOM uint16_t BCHG      : 1; /*!< [14..14] USB Bus Change Interrupt Status                                  */
            __IOM uint16_t OVRCR     : 1; /*!< [15..15] Overcurrent Input Change Interrupt Status                        */
        } INTSTS1_b;
    };
    __IM uint16_t RESERVED8;

    union
    {
        __IOM uint16_t BRDYSTS;           /*!< (@ 0x00000046) BRDY Interrupt Status Register                             */

        struct
        {
            __IOM uint16_t PIPE0BRDY : 1; /*!< [0..0] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE1BRDY : 1; /*!< [1..1] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE2BRDY : 1; /*!< [2..2] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE3BRDY : 1; /*!< [3..3] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE4BRDY : 1; /*!< [4..4] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE5BRDY : 1; /*!< [5..5] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE6BRDY : 1; /*!< [6..6] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE7BRDY : 1; /*!< [7..7] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE8BRDY : 1; /*!< [8..8] BRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE9BRDY : 1; /*!< [9..9] BRDY Interrupt Status for PIPE                                     */
        } BRDYSTS_b;
    };

    union
    {
        __IOM uint16_t NRDYSTS;           /*!< (@ 0x00000048) NRDY Interrupt Status Register                             */

        struct
        {
            __IOM uint16_t PIPE0NRDY : 1; /*!< [0..0] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE1NRDY : 1; /*!< [1..1] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE2NRDY : 1; /*!< [2..2] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE3NRDY : 1; /*!< [3..3] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE4NRDY : 1; /*!< [4..4] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE5NRDY : 1; /*!< [5..5] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE6NRDY : 1; /*!< [6..6] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE7NRDY : 1; /*!< [7..7] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE8NRDY : 1; /*!< [8..8] NRDY Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE9NRDY : 1; /*!< [9..9] NRDY Interrupt Status for PIPE                                     */
        } NRDYSTS_b;
    };

    union
    {
        __IOM uint16_t BEMPSTS;           /*!< (@ 0x0000004A) BEMP Interrupt Status Register                             */

        struct
        {
            __IOM uint16_t PIPE0BEMP : 1; /*!< [0..0] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE1BEMP : 1; /*!< [1..1] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE2BEMP : 1; /*!< [2..2] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE3BEMP : 1; /*!< [3..3] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE4BEMP : 1; /*!< [4..4] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE5BEMP : 1; /*!< [5..5] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE6BEMP : 1; /*!< [6..6] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE7BEMP : 1; /*!< [7..7] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE8BEMP : 1; /*!< [8..8] BEMP Interrupt Status for PIPE                                     */
            __IOM uint16_t PIPE9BEMP : 1; /*!< [9..9] BEMP Interrupt Status for PIPE                                     */
        } BEMPSTS_b;
    };

    union
    {
        __IOM uint16_t FRMNUM;         /*!< (@ 0x0000004C) Frame Number Register                                      */

        struct
        {
            __IM uint16_t FRNM  : 11;  /*!< [10..0] Frame NumberLatest frame number                                   */
            uint16_t            : 3;
            __IOM uint16_t CRCE : 1;   /*!< [14..14] Receive Data Error                                               */
            __IOM uint16_t OVRN : 1;   /*!< [15..15] Overrun/Underrun Detection Status                                */
        } FRMNUM_b;
    };

    union
    {
        __IOM uint16_t UFRMNUM;        /*!< (@ 0x0000004E) uFrame Number Register                                     */

        struct
        {
            __IM uint16_t UFRNM  : 3;  /*!< [2..0] MicroframeIndicate the microframe number.                          */
            uint16_t             : 12;
            __IOM uint16_t DVCHG : 1;  /*!< [15..15] Device State Change                                              */
        } UFRMNUM_b;
    };

    union
    {
        __IOM uint16_t USBADDR;           /*!< (@ 0x00000050) USB Address Register                                       */

        struct
        {
            __IM uint16_t USBADDR : 7;    /*!< [6..0] USB Address In device controller mode, these flags indicate
                                           *   the USB address assigned by the host when the USBHS processed
                                           *   the SET_ADDRESS request successfully.                                     */
            uint16_t                 : 1;
            __IOM uint16_t STSRECOV0 : 3; /*!< [10..8] Status Recovery                                                   */
        } USBADDR_b;
    };
    __IM uint16_t RESERVED9;

    union
    {
        __IOM uint16_t USBREQ;                /*!< (@ 0x00000054) USB Request Type Register                                  */

        struct
        {
            __IOM uint16_t BMREQUESTTYPE : 8; /*!< [7..0] Request TypeThese bits store the USB request bmRequestType
                                               *   value.                                                                    */
            __IOM uint16_t BREQUEST : 8;      /*!< [15..8] RequestThese bits store the USB request bRequest value.           */
        } USBREQ_b;
    };

    union
    {
        __IOM uint16_t USBVAL;          /*!< (@ 0x00000056) USB Request Value Register                                 */

        struct
        {
            __IOM uint16_t WVALUE : 16; /*!< [15..0] ValueThese bits store the USB request Value value.                */
        } USBVAL_b;
    };

    union
    {
        __IOM uint16_t USBINDX;         /*!< (@ 0x00000058) USB Request Index Register                                 */

        struct
        {
            __IOM uint16_t WINDEX : 16; /*!< [15..0] IndexThese bits store the USB request wIndex value.               */
        } USBINDX_b;
    };

    union
    {
        __IOM uint16_t USBLENG;          /*!< (@ 0x0000005A) USB Request Length Register                                */

        struct
        {
            __IOM uint16_t WLENGTH : 16; /*!< [15..0] LengthThese bits store the USB request wLength value.             */
        } USBLENG_b;
    };

    union
    {
        __IOM uint16_t DCPCFG;         /*!< (@ 0x0000005C) DCP Configuration Register                                 */

        struct
        {
            uint16_t              : 4;
            __IOM uint16_t DIR    : 1; /*!< [4..4] Transfer Direction                                                 */
            uint16_t              : 2;
            __IOM uint16_t SHTNAK : 1; /*!< [7..7] Pipe Disabled at End of Transfer                                   */
            __IOM uint16_t CNTMD  : 1; /*!< [8..8] Continuous Transfer Mode                                           */
        } DCPCFG_b;
    };

    union
    {
        __IOM uint16_t DCPMAXP;        /*!< (@ 0x0000005E) DCP Maximum Packet Size Register                           */

        struct
        {
            __IOM uint16_t MXPS : 7;   /*!< [6..0] Maximum Packet SizeThese bits set the maximum amount
                                        *   of data (maximum packet size) in payloads for the DCP.                    */
            uint16_t              : 5;
            __IOM uint16_t DEVSEL : 4; /*!< [15..12] Device Select                                                    */
        } DCPMAXP_b;
    };

    union
    {
        __IOM uint16_t DCPCTR;           /*!< (@ 0x00000060) DCP Control Register                                       */

        struct
        {
            __IOM uint16_t PID      : 2; /*!< [1..0] Response PID                                                       */
            __IOM uint16_t CCPL     : 1; /*!< [2..2] Control Transfer End Enable                                        */
            uint16_t                : 1;
            __IOM uint16_t PINGE    : 1; /*!< [4..4] PING Token Issue Enable                                            */
            __IM uint16_t  PBUSY    : 1; /*!< [5..5] Pipe Busy                                                          */
            __IM uint16_t  SQMON    : 1; /*!< [6..6] Sequence Toggle Bit Monitor                                        */
            __IOM uint16_t SQSET    : 1; /*!< [7..7] Sequence Toggle Bit Set                                            */
            __IOM uint16_t SQCLR    : 1; /*!< [8..8] Sequence Toggle Bit Clear                                          */
            uint16_t                : 2;
            __IOM uint16_t SUREQCLR : 1; /*!< [11..11] SUREQ Bit Clear                                                  */
            __IM uint16_t  CSSTS    : 1; /*!< [12..12] Split Transaction COMPLETE SPLIT(CSPLIT) Status                                                  */
            __IOM uint16_t CSCLR    : 1; /*!< [13..13] Split Transaction CSPLIT Status Clear                                                  */
            __IOM uint16_t SUREQ    : 1; /*!< [14..14] Setup Token Transmission                                         */
            __IM uint16_t  BSTS     : 1; /*!< [15..15] Buffer Status                                                    */
        } DCPCTR_b;
    };
    __IM uint16_t RESERVED10;

    union
    {
        __IOM uint16_t PIPESEL;         /*!< (@ 0x00000064) Pipe Window Select Register                                */

        struct
        {
            __IOM uint16_t PIPESEL : 4; /*!< [3..0] Pipe Window Select                                                 */
        } PIPESEL_b;
    };
    __IM uint16_t RESERVED11;

    union
    {
        __IOM uint16_t PIPECFG;        /*!< (@ 0x00000068) Pipe Configuration Register                                */

        struct
        {
            __IOM uint16_t EPNUM : 4;  /*!< [3..0] Endpoint NumberThese bits specify the endpoint number
                                        *   for the selected pipe.Setting 0000b means unused pipe.                    */
            __IOM uint16_t DIR    : 1; /*!< [4..4] Transfer Direction                                                 */
            uint16_t              : 2;
            __IOM uint16_t SHTNAK : 1; /*!< [7..7] Pipe Disabled at End of Transfer                                   */
            __IOM uint16_t CNTMD  : 1; /*!< [8..8] Continuous Transfer Mode                                   */
            __IOM uint16_t DBLB   : 1; /*!< [9..9] Double Buffer Mode                                                 */
            __IOM uint16_t BFRE   : 1; /*!< [10..10] BRDY Interrupt Operation Specification                           */
            uint16_t              : 3;
            __IOM uint16_t TYPE   : 2; /*!< [15..14] Transfer Type                                                    */
        } PIPECFG_b;
    };

    union
    {
        __IOM uint16_t PIPEBUF;          /*!< (@ 0x0000006A)Pipe Buffer Register                                         */

        struct
        {
            __IOM uint16_t BUFNMB :  8;  /*!< [7..0] Buffer NumberThese bits specify the FIFO buffer number of the
                                          *   selected pipe (04h to 87h).                                         */
            uint16_t               :  2;
            __IOM uint16_t BUFSIZE :  5; /*!< [14..10] Buffer Size 00h: 64 bytes 01h: 128 bytes : 1Fh: 2 Kbytes   */
        } PIPEBUF_b;                     /*!< BitSize                                                             */
    };

    union
    {
        __IOM uint16_t PIPEMAXP;       /*!< (@ 0x0000006C) Pipe Maximum Packet Size Register                          */

        struct
        {
            __IOM uint16_t MXPS : 11;  /*!< [10..0] Maximum Packet SizePIPE1 and PIPE2: 1 byte (001h) to
                                        *   1024 bytes (400h)PIPE3 to PIPE5: 8 bytes (008h), 16 bytes
                                        *   (010h), 32 bytes (020h), 64 bytes (040h),512bytes(200h) ([2:0] are not
                                        *   provided.)PIPE6 to PIPE9: 1 byte (001h) to
                                        *   64 bytes (040h) (Bits [10:7] are not provided.)                      */
            uint16_t              : 1;
            __IOM uint16_t DEVSEL : 4; /*!< [15..12] Device Select                                                    */
        } PIPEMAXP_b;
    };

    union
    {
        __IOM uint16_t PIPEPERI;       /*!< (@ 0x0000006E) Pipe Cycle Control Register                                */

        struct
        {
            __IOM uint16_t IITV : 3;   /*!< [2..0] Interval Error Detection IntervalSpecifies the interval
                                        *   error detection timing for the selected pipe in terms of
                                        *   frames, which is expressed as nth power of 2.                             */
            uint16_t            : 9;
            __IOM uint16_t IFIS : 1;   /*!< [12..12] Isochronous IN Buffer Flush                                      */
        } PIPEPERI_b;
    };

    union
    {
        __IOM uint16_t PIPE_CTR[9];    /*!< (@ 0x00000070) Pipe [0..8] Control Register                               */

        struct
        {
            __IOM uint16_t PID    : 2; /*!< [1..0] Response PID                                                       */
            uint16_t              : 3;
            __IM uint16_t  PBUSY  : 1; /*!< [5..5] Pipe Busy                                                          */
            __IM uint16_t  SQMON  : 1; /*!< [6..6] Sequence Toggle Bit Confirmation                                   */
            __IOM uint16_t SQSET  : 1; /*!< [7..7] Sequence Toggle Bit Set                                            */
            __IOM uint16_t SQCLR  : 1; /*!< [8..8] Sequence Toggle Bit Clear                                          */
            __IOM uint16_t ACLRM  : 1; /*!< [9..9] Auto Buffer Clear Mode                                             */
            __IOM uint16_t ATREPM : 1; /*!< [10..10] Auto Response Mode                                               */
            uint16_t              : 1;
            __IM uint16_t CSSTS   : 1; /*!< [12..12] CSSTS StatusThis bit indicates the CSPLIT status of
                                        *   Split Transaction of the relevant pipe                                    */
            __IOM uint16_t CSCLR : 1;  /*!< [13..13] CSPLIT Status ClearSet this bit to 1 when clearing
                                        *   the CSSTS bit of the relevant pipe                                        */
            __IM uint16_t INBUFM : 1;  /*!< [14..14] Transmit Buffer Monitor                                          */
            __IM uint16_t BSTS   : 1;  /*!< [15..15] Buffer Status                                                    */
        } PIPE_CTR_b[9];
    };
    __IM uint16_t                RESERVED13;
    __IM uint32_t                RESERVED14[3];
    __IOM R_USB_HS0_PIPE_TR_Type PIPE_TR[5]; /*!< (@ 0x00000090) Pipe Transaction Counter Registers                         */
    __IM uint32_t                RESERVED15[11];

    union
    {
        __IOM uint16_t DEVADD[10];     /*!< (@ 0x000000D0) Device Address Configuration Register                      */

        struct
        {
            uint16_t               : 6;
            __IOM uint16_t USBSPD  : 2; /*!< [7..6] Transfer Speed of Communication Target Device                      */
            __IOM uint16_t HUBPORT : 3; /*!< [10..8] Communication Target Connecting Hub Port                          */
            __IOM uint16_t UPPHUB  : 4; /*!< [14..11] Communication Target Connecting Hub Register                     */
        } DEVADD_b[10];
    };
    __IM uint16_t RESERVED16;
    __IM uint32_t RESERVED17[6];

    union
    {
        __IOM uint16_t LPCTRL;         /*!< (@ 0x00000100) Low Power Control Register                                 */

        struct
        {
            uint16_t             : 7;
            __IOM uint16_t HWUPM : 1;  /*!< [7..7] Resume Return Mode Setting                                         */
        } LPCTRL_b;
    };

    union
    {
        __IOM uint16_t LPSTS;          /*!< (@ 0x00000102) Low Power Status Register                                  */

        struct
        {
            uint16_t                : 14;
            __IOM uint16_t SUSPENDM : 1; /*!< [14..14] UTMI SuspendM Control                                            */
        } LPSTS_b;
    };
    __IM uint32_t RESERVED18[15];

    union
    {
        __IOM uint16_t BCCTRL;           /*!< (@ 0x00000140) Battery Charging Control Register                          */

        struct
        {
            __IOM uint16_t IDPSRCE  : 1; /*!< [0..0] IDPSRC Control                                                     */
            __IOM uint16_t IDMSINKE : 1; /*!< [1..1] IDMSINK Control                                                    */
            __IOM uint16_t VDPSRCE  : 1; /*!< [2..2] VDPSRC Control                                                     */
            __IOM uint16_t IDPSINKE : 1; /*!< [3..3] IDPSINK Control                                                    */
            __IOM uint16_t VDMSRCE  : 1; /*!< [4..4] VDMSRC Control                                                     */
            __IOM uint16_t DCPMODE  : 1; /*!< [5..5] DCP Mode Control                                                   */
            uint16_t                : 2;
            __IM uint16_t CHGDETSTS : 1; /*!< [8..8] CHGDET Status                                                      */
            __IM uint16_t PDDETSTS  : 1; /*!< [9..9] PDDET Status                                                       */
        } BCCTRL_b;
    };
    __IM uint16_t RESERVED19;

    union
    {
        __IOM uint16_t PL1CTRL1;         /*!< (@ 0x00000144) Function L1 Control Register 1                             */

        struct
        {
            __IOM uint16_t L1RESPEN : 1; /*!< [0..0] L1 Response Enable                                                 */
            __IOM uint16_t L1RESPMD : 2; /*!< [2..1] L1 Response Mode                                                   */
            __IOM uint16_t L1NEGOMD : 1; /*!< [3..3] L1 Response Negotiation Control.NOTE: This bit is valid
                                          *   only when the L1RESPMD[1:0] value is 2'b11.                               */
            __IM uint16_t DVSQ : 4;      /*!< [7..4] DVSQ Extension.DVSQ[3] is Mirror of DVSQ[2:0] in INTSTS0.Indicates
                                          *   the L1 state together with the device state bits DVSQ[2:0].               */
            __IOM uint16_t HIRDTHR : 4;  /*!< [11..8] L1 Response Negotiation Threshold ValueHIRD threshold
                                          *   value used for L1NEGOMD.The format is the same as the HIRD
                                          *   field in HL1CTRL.                                                         */
            uint16_t               : 2;
            __IOM uint16_t L1EXTMD : 1;  /*!< [14..14] PHY Control Mode at L1 Return                                    */
        } PL1CTRL1_b;
    };

    union
    {
        __IOM uint16_t PL1CTRL2;       /*!< (@ 0x00000146) Function L1 Control Register 2                             */

        struct
        {
            uint16_t               : 8;
            __IOM uint16_t HIRDMON : 4; /*!< [11..8] HIRD Value Monitor                                                */
            __IOM uint16_t RWEMON  : 1; /*!< [12..12] RWE Value Monitor                                                */
        } PL1CTRL2_b;
    };

    union
    {
        __IOM uint16_t HL1CTRL1;         /*!< (@ 0x00000148) Host L1 Control Register 1                                 */

        struct
        {
            __IOM uint16_t L1REQ    : 1; /*!< [0..0] L1 Transition Request                                              */
            __IM uint16_t  L1STATUS : 2; /*!< [2..1] L1 Request Completion Status                                       */
        } HL1CTRL1_b;
    };

    union
    {
        __IOM uint16_t HL1CTRL2;       /*!< (@ 0x0000014A) Host L1 Control Register 2                                 */

        struct
        {
            __IOM uint16_t L1ADDR : 4; /*!< [3..0] LPM Token DeviceAddressThese bits specify the value to
                                        *   be set in the ADDR field of LPM token.                                    */
            uint16_t             : 4;
            __IOM uint16_t HIRD  : 4;  /*!< [11..8] LPM Token HIRD                                                    */
            __IOM uint16_t L1RWE : 1;  /*!< [12..12] LPM Token L1 RemoteWake EnableThese bits specify the
                                        *   value to be set in the RWE field of LPM token.                            */
            uint16_t            : 2;
            __IOM uint16_t BESL : 1;   /*!< [15..15] BESL & Alternate HIRDThis bit selects the K-State drive
                                        *   period at the time of L1 Resume.                                          */
        } HL1CTRL2_b;
    };
    __IM uint32_t RESERVED20;

    union
    {
        __IOM uint16_t PHYTRIM1;           /*!< (@ 0x00000150)PHY Timing Register 1                                                 */

        struct
        {
            __IOM uint16_t DRISE     :  2; /*!< [1..0]FS/LS Rising-Edge Output Waveform Adjustment Function                 */
            __IOM uint16_t DFALL     :  2; /*!< [3..2]FS/LS Falling-Edge Output Waveform Adjustment Function                */
            uint16_t                 :  3;
            __IOM uint16_t PCOMPENB  :  1; /*!< [7..7]PVDD Start-up Detection                                               */
            __IOM uint16_t HSIUP     :  4; /*!< [11..8]HS Output Level Setting                                               */
            __IOM uint16_t IMPOFFSET :  3; /*!< [14..12]terminating resistance offset value setting.Offset value for
                                            * adjusting the terminating resistance.                                 */
        } PHYTRIM1_b;                      /*!< BitSize                                                               */
    };

    union
    {
        __IOM uint16_t PHYTRIM2;          /*!< (@ 0x00000152)PHY Timing Register 2                                                 */

        struct
        {
            __IOM uint16_t SQU      :  4; /*!< [3..0]Squelch Detection Level                                               */
            uint16_t                :  3;
            __IOM uint16_t HSRXENMO :  1; /*!< [7..7]HS Receive Enable Control Mode                                        */
            __IOM uint16_t PDR      :  2; /*!< [9..8]HS Output Adjustment Function                                         */
            uint16_t                :  2;
            __IOM uint16_t DIS      :  3; /*!< [14..12]Disconnect Detection Level                                            */
        } PHYTRIM2_b;                     /*!< BitSize                                                               */
    };
    __IM uint32_t RESERVED21[3];

    union
    {
        __IM uint32_t DPUSR0R;         /*!< (@ 0x00000160) Deep Standby USB Transceiver Control/Pin Monitor
                                        *                  Register                                                   */

        struct
        {
            uint32_t              : 20;
            __IM uint32_t DOVCAHM : 1;  /*!< [20..20] OVRCURA InputIndicates OVRCURA input signal on the
                                         *   HS side of USB port.                                                      */
            __IM uint32_t DOVCBHM : 1;  /*!< [21..21] OVRCURB InputIndicates OVRCURB input signal on the
                                         *   HS side of USB port.                                                      */
            uint32_t               : 1;
            __IM uint32_t DVBSTSHM : 1; /*!< [23..23] VBUS InputIndicates VBUS input signal on the HS side
                                         *   of USB port.                                                              */
        } DPUSR0R_b;
    };

    union
    {
        __IOM uint32_t DPUSR1R;        /*!< (@ 0x00000164) Deep Standby USB Suspend/Resume Interrupt Register         */

        struct
        {
            uint32_t                : 4;
            __IOM uint32_t DOVCAHE  : 1; /*!< [4..4] OVRCURA Interrupt Enable Clear                                     */
            __IOM uint32_t DOVCBHE  : 1; /*!< [5..5] OVRCURB Interrupt Enable Clear                                     */
            uint32_t                : 1;
            __IOM uint32_t DVBSTSHE : 1; /*!< [7..7] VBUS Interrupt Enable/Clear                                        */
            uint32_t                : 12;
            __IM uint32_t DOVCAH    : 1; /*!< [20..20] Indication of Return from OVRCURA Interrupt Source               */
            __IM uint32_t DOVCBH    : 1; /*!< [21..21] Indication of Return from OVRCURB Interrupt Source               */
            uint32_t                : 1;
            __IM uint32_t DVBSTSH   : 1; /*!< [23..23] Indication of Return from VBUS Interrupt Source                  */
        } DPUSR1R_b;
    };

    union
    {
        __IOM uint16_t DPUSR2R;        /*!< (@ 0x00000168) Deep Standby USB Suspend/Resume Interrupt Register         */

        struct
        {
            __IM uint16_t DPINT : 1;   /*!< [0..0] Indication of Return from DP Interrupt Source                      */
            __IM uint16_t DMINT : 1;   /*!< [1..1] Indication of Return from DM Interrupt Source                      */
            uint16_t            : 2;
            __IM uint16_t DPVAL : 1;   /*!< [4..4] DP InputIndicates DP input signal on the HS side of USB
                                        *   port.                                                                     */
            __IM uint16_t DMVAL : 1;   /*!< [5..5] DM InputIndicates DM input signal on the HS side of USB
                                        *   port.                                                                     */
            uint16_t              : 2;
            __IOM uint16_t DPINTE : 1; /*!< [8..8] DP Interrupt Enable Clear                                          */
            __IOM uint16_t DMINTE : 1; /*!< [9..9] DM Interrupt Enable Clear                                          */
        } DPUSR2R_b;
    };

    union
    {
        __IOM uint16_t DPUSRCR;          /*!< (@ 0x0000016A) Deep Standby USB Suspend/Resume Command Register           */

        struct
        {
            __IOM uint16_t FIXPHY   : 1; /*!< [0..0] USB Transceiver Control Fix                                        */
            __IOM uint16_t FIXPHYPD : 1; /*!< [1..1] USB Transceiver Control Fix for PLL                                */
        } DPUSRCR_b;
    };
} R_USB_HS0_Type;                        /*!< Size = 1032 (0x408)                                                       */

#endif /* R_USB_BASIC_REG_H */
