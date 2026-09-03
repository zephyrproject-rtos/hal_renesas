/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_COMA_REG_H
#define R_COMA_REG_H

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

/** @addtogroup Device_Peripheral_peripherals
 * @{
 */

/* =========================================================================================================================== */
/* ================                                          R_COMA                                           ================ */
/* =========================================================================================================================== */

/**
 * @brief Common Agent (R_COMA)
 */

typedef struct                         /*!< (@ 0x874C9000) R_COMA Structure                                           */
{
    union
    {
        __IOM uint32_t RIPV;           /*!< (@ 0x00000000) R-Switch IP Version Register (RIPV)                        */

        struct
        {
            __IOM uint32_t TIPV  : 4;  /*!< [3..0] TIPV                                                               */
            __IOM uint32_t GWIPV : 4;  /*!< [7..4] GWIPV                                                              */
            __IOM uint32_t FWIPV : 4;  /*!< [11..8] FWIPV                                                             */
            __IOM uint32_t EAIPV : 4;  /*!< [15..12] EAIPV                                                            */
            __IOM uint32_t FBIPV : 4;  /*!< [19..16] FBIPV                                                            */
            uint32_t             : 1;
            __IOM uint32_t CAIPV : 3;  /*!< [23..21] CAIPV                                                            */
            uint32_t             : 8;
        } RIPV_b;
    };

    union
    {
        __IOM uint32_t RRC;            /*!< (@ 0x00000004) R-Switch Reset Configuration Register (RRC)                */

        struct
        {
            __IOM uint32_t RR : 1;     /*!< [0..0] RR                                                                 */
            uint32_t          : 31;
        } RRC_b;
    };

    union
    {
        __IOM uint32_t RCEC;           /*!< (@ 0x00000008) R-Switch Clock Enable Configuration Register
                                        *                  (RCEC)                                                     */

        struct
        {
            __IOM uint32_t ACE0 : 1;   /*!< [0..0] ACE0                                                               */
            __IOM uint32_t ACE1 : 1;   /*!< [1..1] ACE1                                                               */
            __IOM uint32_t ACE2 : 1;   /*!< [2..2] ACE2                                                               */
            uint32_t            : 13;
            __IOM uint32_t RCE  : 1;   /*!< [16..16] RCE                                                              */
            uint32_t            : 15;
        } RCEC_b;
    };

    union
    {
        __IOM uint32_t RCDC;           /*!< (@ 0x0000000C) R-Switch Clock Disable Configuration Register
                                        *                  (RCDC)                                                     */

        struct
        {
            __IOM uint32_t ACD0 : 1;   /*!< [0..0] ACD0                                                               */
            __IOM uint32_t ACD1 : 1;   /*!< [1..1] ACD1                                                               */
            __IOM uint32_t ACD2 : 1;   /*!< [2..2] ACD2                                                               */
            uint32_t            : 13;
            __IOM uint32_t RCD  : 1;   /*!< [16..16] RCD                                                              */
            uint32_t            : 15;
        } RCDC_b;
    };
    __IM uint32_t RESERVED[4];

    union
    {
        __IOM uint32_t CABPIBWMC0;       /*!< (@ 0x00000020) Common Agent Buffer Pool IPV Based Watermark
                                          *                  Configuration Register (CABPIBWMCi) (i=0..7)               */

        struct
        {
            __IOM uint32_t IBUWMPN : 10; /*!< [9..0] IBUWMPN                                                            */
            uint32_t               : 6;
            __IOM uint32_t IBSWMPN : 10; /*!< [25..16] IBSWMPN                                                          */
            uint32_t               : 6;
        } CABPIBWMC0_b;
    };

    union
    {
        __IOM uint32_t CABPIBWMC1;       /*!< (@ 0x00000024) Common Agent Buffer Pool IPV Based Watermark
                                          *                  Configuration Register (CABPIBWMCi) (i=0..7)               */

        struct
        {
            __IOM uint32_t IBUWMPN : 10; /*!< [9..0] IBUWMPN                                                            */
            uint32_t               : 6;
            __IOM uint32_t IBSWMPN : 10; /*!< [25..16] IBSWMPN                                                          */
            uint32_t               : 6;
        } CABPIBWMC1_b;
    };

    union
    {
        __IOM uint32_t CABPIBWMC2;       /*!< (@ 0x00000028) Common Agent Buffer Pool IPV Based Watermark
                                          *                  Configuration Register (CABPIBWMCi) (i=0..7)               */

        struct
        {
            __IOM uint32_t IBUWMPN : 10; /*!< [9..0] IBUWMPN                                                            */
            uint32_t               : 6;
            __IOM uint32_t IBSWMPN : 10; /*!< [25..16] IBSWMPN                                                          */
            uint32_t               : 6;
        } CABPIBWMC2_b;
    };

    union
    {
        __IOM uint32_t CABPIBWMC3;       /*!< (@ 0x0000002C) Common Agent Buffer Pool IPV Based Watermark
                                          *                  Configuration Register (CABPIBWMCi) (i=0..7)               */

        struct
        {
            __IOM uint32_t IBUWMPN : 10; /*!< [9..0] IBUWMPN                                                            */
            uint32_t               : 6;
            __IOM uint32_t IBSWMPN : 10; /*!< [25..16] IBSWMPN                                                          */
            uint32_t               : 6;
        } CABPIBWMC3_b;
    };

    union
    {
        __IOM uint32_t CABPIBWMC4;       /*!< (@ 0x00000030) Common Agent Buffer Pool IPV Based Watermark
                                          *                  Configuration Register (CABPIBWMCi) (i=0..7)               */

        struct
        {
            __IOM uint32_t IBUWMPN : 10; /*!< [9..0] IBUWMPN                                                            */
            uint32_t               : 6;
            __IOM uint32_t IBSWMPN : 10; /*!< [25..16] IBSWMPN                                                          */
            uint32_t               : 6;
        } CABPIBWMC4_b;
    };

    union
    {
        __IOM uint32_t CABPIBWMC5;       /*!< (@ 0x00000034) Common Agent Buffer Pool IPV Based Watermark
                                          *                  Configuration Register (CABPIBWMCi) (i=0..7)               */

        struct
        {
            __IOM uint32_t IBUWMPN : 10; /*!< [9..0] IBUWMPN                                                            */
            uint32_t               : 6;
            __IOM uint32_t IBSWMPN : 10; /*!< [25..16] IBSWMPN                                                          */
            uint32_t               : 6;
        } CABPIBWMC5_b;
    };

    union
    {
        __IOM uint32_t CABPIBWMC6;       /*!< (@ 0x00000038) Common Agent Buffer Pool IPV Based Watermark
                                          *                  Configuration Register (CABPIBWMCi) (i=0..7)               */

        struct
        {
            __IOM uint32_t IBUWMPN : 10; /*!< [9..0] IBUWMPN                                                            */
            uint32_t               : 6;
            __IOM uint32_t IBSWMPN : 10; /*!< [25..16] IBSWMPN                                                          */
            uint32_t               : 6;
        } CABPIBWMC6_b;
    };

    union
    {
        __IOM uint32_t CABPIBWMC7;       /*!< (@ 0x0000003C) Common Agent Buffer Pool IPV Based Watermark
                                          *                  Configuration Register (CABPIBWMCi) (i=0..7)               */

        struct
        {
            __IOM uint32_t IBUWMPN : 10; /*!< [9..0] IBUWMPN                                                            */
            uint32_t               : 6;
            __IOM uint32_t IBSWMPN : 10; /*!< [25..16] IBSWMPN                                                          */
            uint32_t               : 6;
        } CABPIBWMC7_b;
    };

    union
    {
        __IOM uint32_t CABPWMLC;       /*!< (@ 0x00000040) Common Agent Buffer Pool Watermark Level Configuration
                                        *                  Register (CABPWMLC)                                        */

        struct
        {
            __IOM uint32_t WMFL : 10;  /*!< [9..0] WMFL                                                               */
            uint32_t            : 6;
            __IOM uint32_t WMCL : 10;  /*!< [25..16] WMCL                                                             */
            uint32_t            : 6;
        } CABPWMLC_b;
    };
    __IM uint32_t RESERVED1[3];

    union
    {
        __IOM uint32_t CABPPFLC0;      /*!< (@ 0x00000050) Common Agent Buffer Pointer Pause Frame Level
                                        *                  Configuration Register (CABPPFLCi) (i =
                                        *                  0, 1)                                                      */

        struct
        {
            __IOM uint32_t PDL : 10;   /*!< [9..0] PDL                                                                */
            uint32_t           : 6;
            __IOM uint32_t PAL : 10;   /*!< [25..16] PAL                                                              */
            uint32_t           : 6;
        } CABPPFLC0_b;
    };

    union
    {
        __IOM uint32_t CABPPFLC1;      /*!< (@ 0x00000054) Common Agent Buffer Pointer Pause Frame Level
                                        *                  Configuration Register (CABPPFLCi) (i =
                                        *                  0, 1)                                                      */

        struct
        {
            __IOM uint32_t PDL : 10;   /*!< [9..0] PDL                                                                */
            uint32_t           : 6;
            __IOM uint32_t PAL : 10;   /*!< [25..16] PAL                                                              */
            uint32_t           : 6;
        } CABPPFLC1_b;
    };
    __IM uint32_t RESERVED2[2];

    union
    {
        __IOM uint32_t CABPPWMLC0;     /*!< (@ 0x00000060) Common Agent Buffer Pool per Port Watermark Level
                                        *                  Configuration Register i (CABPPWMLCi) (i
                                        *                  = 0 to 2)                                                  */

        struct
        {
            __IOM uint32_t PWMFL : 10; /*!< [9..0] PWMFL                                                              */
            uint32_t             : 6;
            __IOM uint32_t PWMCL : 10; /*!< [25..16] PWMCL                                                            */
            uint32_t             : 6;
        } CABPPWMLC0_b;
    };

    union
    {
        __IOM uint32_t CABPPWMLC1;     /*!< (@ 0x00000064) Common Agent Buffer Pool per Port Watermark Level
                                        *                  Configuration Register i (CABPPWMLCi) (i
                                        *                  = 0 to 2)                                                  */

        struct
        {
            __IOM uint32_t PWMFL : 10; /*!< [9..0] PWMFL                                                              */
            uint32_t             : 6;
            __IOM uint32_t PWMCL : 10; /*!< [25..16] PWMCL                                                            */
            uint32_t             : 6;
        } CABPPWMLC1_b;
    };

    union
    {
        __IOM uint32_t CABPPWMLC2;     /*!< (@ 0x00000068) Common Agent Buffer Pool per Port Watermark Level
                                        *                  Configuration Register i (CABPPWMLCi) (i
                                        *                  = 0 to 2)                                                  */

        struct
        {
            __IOM uint32_t PWMFL : 10; /*!< [9..0] PWMFL                                                              */
            uint32_t             : 6;
            __IOM uint32_t PWMCL : 10; /*!< [25..16] PWMCL                                                            */
            uint32_t             : 6;
        } CABPPWMLC2_b;
    };
    __IM uint32_t RESERVED3[13];

    union
    {
        __IOM uint32_t CABPPPFLC00;    /*!< (@ 0x000000A0) Common Agent Buffer Pointer per Port Pause Frame
                                        *                  Level Configuration Register (CABPPPFLCij)
                                        *                  (i = 0 to 2) (j = 0, 1)                                    */

        struct
        {
            __IOM uint32_t PPDL : 10;  /*!< [9..0] PPDL                                                               */
            uint32_t            : 6;
            __IOM uint32_t PPAL : 10;  /*!< [25..16] PPAL                                                             */
            uint32_t            : 6;
        } CABPPPFLC00_b;
    };

    union
    {
        __IOM uint32_t CABPPPFLC01;    /*!< (@ 0x000000A4) Common Agent Buffer Pointer per Port Pause Frame
                                        *                  Level Configuration Register (CABPPPFLCij)
                                        *                  (i = 0 to 2) (j = 0, 1)                                    */

        struct
        {
            __IOM uint32_t PPDL : 10;  /*!< [9..0] PPDL                                                               */
            uint32_t            : 6;
            __IOM uint32_t PPAL : 10;  /*!< [25..16] PPAL                                                             */
            uint32_t            : 6;
        } CABPPPFLC01_b;
    };

    union
    {
        __IOM uint32_t CABPPPFLC10;    /*!< (@ 0x000000A8) Common Agent Buffer Pointer per Port Pause Frame
                                        *                  Level Configuration Register (CABPPPFLCij)
                                        *                  (i = 0 to 2) (j = 0, 1)                                    */

        struct
        {
            __IOM uint32_t PPDL : 10;  /*!< [9..0] PPDL                                                               */
            uint32_t            : 6;
            __IOM uint32_t PPAL : 10;  /*!< [25..16] PPAL                                                             */
            uint32_t            : 6;
        } CABPPPFLC10_b;
    };

    union
    {
        __IOM uint32_t CABPPPFLC11;    /*!< (@ 0x000000AC) Common Agent Buffer Pointer per Port Pause Frame
                                        *                  Level Configuration Register (CABPPPFLCij)
                                        *                  (i = 0 to 2) (j = 0, 1)                                    */

        struct
        {
            __IOM uint32_t PPDL : 10;  /*!< [9..0] PPDL                                                               */
            uint32_t            : 6;
            __IOM uint32_t PPAL : 10;  /*!< [25..16] PPAL                                                             */
            uint32_t            : 6;
        } CABPPPFLC11_b;
    };

    union
    {
        __IOM uint32_t CABPPPFLC20;    /*!< (@ 0x000000B0) Common Agent Buffer Pointer per Port Pause Frame
                                        *                  Level Configuration Register (CABPPPFLCij)
                                        *                  (i = 0 to 2) (j = 0, 1)                                    */

        struct
        {
            __IOM uint32_t PPDL : 10;  /*!< [9..0] PPDL                                                               */
            uint32_t            : 6;
            __IOM uint32_t PPAL : 10;  /*!< [25..16] PPAL                                                             */
            uint32_t            : 6;
        } CABPPPFLC20_b;
    };

    union
    {
        __IOM uint32_t CABPPPFLC21;    /*!< (@ 0x000000B4) Common Agent Buffer Pointer per Port Pause Frame
                                        *                  Level Configuration Register (CABPPPFLCij)
                                        *                  (i = 0 to 2) (j = 0, 1)                                    */

        struct
        {
            __IOM uint32_t PPDL : 10;  /*!< [9..0] PPDL                                                               */
            uint32_t            : 6;
            __IOM uint32_t PPAL : 10;  /*!< [25..16] PPAL                                                             */
            uint32_t            : 6;
        } CABPPPFLC21_b;
    };
    __IM uint32_t RESERVED4[18];

    union
    {
        __IOM uint32_t CABPULC0;       /*!< (@ 0x00000100) Common Agent Buffer Pointer Utilization Level
                                        *                  Configuration Register i (CABPULCi) (i =
                                        *                  0 to 2)                                                    */

        struct
        {
            __IOM uint32_t MXNPN : 10; /*!< [9..0] MXNPN                                                              */
            uint32_t             : 6;
            __IOM uint32_t MNNPN : 10; /*!< [25..16] MNNPN                                                            */
            uint32_t             : 6;
        } CABPULC0_b;
    };

    union
    {
        __IOM uint32_t CABPULC1;       /*!< (@ 0x00000104) Common Agent Buffer Pointer Utilization Level
                                        *                  Configuration Register i (CABPULCi) (i =
                                        *                  0 to 2)                                                    */

        struct
        {
            __IOM uint32_t MXNPN : 10; /*!< [9..0] MXNPN                                                              */
            uint32_t             : 6;
            __IOM uint32_t MNNPN : 10; /*!< [25..16] MNNPN                                                            */
            uint32_t             : 6;
        } CABPULC1_b;
    };

    union
    {
        __IOM uint32_t CABPULC2;       /*!< (@ 0x00000108) Common Agent Buffer Pointer Utilization Level
                                        *                  Configuration Register i (CABPULCi) (i =
                                        *                  0 to 2)                                                    */

        struct
        {
            __IOM uint32_t MXNPN : 10; /*!< [9..0] MXNPN                                                              */
            uint32_t             : 6;
            __IOM uint32_t MNNPN : 10; /*!< [25..16] MNNPN                                                            */
            uint32_t             : 6;
        } CABPULC2_b;
    };
    __IM uint32_t RESERVED5[13];

    union
    {
        __IOM uint32_t CABPIRM;        /*!< (@ 0x00000140) Common Agent Buffer Pool Initialization Register
                                        *                  Monitoring Register (CABPIRM)                              */

        struct
        {
            __IOM uint32_t BPIOG : 1;  /*!< [0..0] BPIOG                                                              */
            __IOM uint32_t BPR   : 1;  /*!< [1..1] BPR                                                                */
            uint32_t             : 30;
        } CABPIRM_b;
    };

    union
    {
        __IOM uint32_t CABPPCM;        /*!< (@ 0x00000144) Common Agent Buffer Pool Pointer Count Monitoring
                                        *                  Register (CABPPCM)                                         */

        struct
        {
            __IOM uint32_t RPC : 10;   /*!< [9..0] RPC                                                                */
            uint32_t           : 6;
            __IOM uint32_t TPC : 10;   /*!< [25..16] TPC                                                              */
            uint32_t           : 6;
        } CABPPCM_b;
    };

    union
    {
        __IOM uint32_t CABPLCM;        /*!< (@ 0x00000148) Common Agent Buffer Pool Pointer Least Count
                                        *                  Monitoring Register (CABPLCM)                              */

        struct
        {
            __IOM uint32_t LRC : 10;   /*!< [9..0] LRC                                                                */
            uint32_t           : 22;
        } CABPLCM_b;
    };
    __IM uint32_t RESERVED6[13];

    union
    {
        __IOM uint32_t CABPCPM0;       /*!< (@ 0x00000180) Common Agent Buffer Pointer Count per Port Monitoring
                                        *                  Register i (CABPCPMi) (i = 0 to 2)                         */

        struct
        {
            __IOM uint32_t RPCP : 10;  /*!< [9..0] RPCP                                                               */
            uint32_t            : 22;
        } CABPCPM0_b;
    };

    union
    {
        __IOM uint32_t CABPCPM1;       /*!< (@ 0x00000184) Common Agent Buffer Pointer Count per Port Monitoring
                                        *                  Register i (CABPCPMi) (i = 0 to 2)                         */

        struct
        {
            __IOM uint32_t RPCP : 10;  /*!< [9..0] RPCP                                                               */
            uint32_t            : 22;
        } CABPCPM1_b;
    };

    union
    {
        __IOM uint32_t CABPCPM2;       /*!< (@ 0x00000188) Common Agent Buffer Pointer Count per Port Monitoring
                                        *                  Register i (CABPCPMi) (i = 0 to 2)                         */

        struct
        {
            __IOM uint32_t RPCP : 10;  /*!< [9..0] RPCP                                                               */
            uint32_t            : 22;
        } CABPCPM2_b;
    };
    __IM uint32_t RESERVED7[29];

    union
    {
        __IOM uint32_t CABPMCPM0;      /*!< (@ 0x00000200) Common Agent Buffer Pointer Maximum Count per
                                        *                  Port Monitoring Register i (CABPMCPMi) (i
                                        *                  = 0 to 2)                                                  */

        struct
        {
            __IOM uint32_t RPMCP : 10; /*!< [9..0] RPMCP                                                              */
            uint32_t             : 22;
        } CABPMCPM0_b;
    };

    union
    {
        __IOM uint32_t CABPMCPM1;      /*!< (@ 0x00000204) Common Agent Buffer Pointer Maximum Count per
                                        *                  Port Monitoring Register i (CABPMCPMi) (i
                                        *                  = 0 to 2)                                                  */

        struct
        {
            __IOM uint32_t RPMCP : 10; /*!< [9..0] RPMCP                                                              */
            uint32_t             : 22;
        } CABPMCPM1_b;
    };

    union
    {
        __IOM uint32_t CABPMCPM2;      /*!< (@ 0x00000208) Common Agent Buffer Pointer Maximum Count per
                                        *                  Port Monitoring Register i (CABPMCPMi) (i
                                        *                  = 0 to 2)                                                  */

        struct
        {
            __IOM uint32_t RPMCP : 10; /*!< [9..0] RPMCP                                                              */
            uint32_t             : 22;
        } CABPMCPM2_b;
    };
    __IM uint32_t RESERVED8[61];

    union
    {
        __IOM uint32_t CARDNM;         /*!< (@ 0x00000300) Common Agent Rejected Descriptor Number Monitoring
                                        *                  Register (CARDNM)                                          */

        struct
        {
            __IOM uint32_t RDNRR : 10; /*!< [9..0] RDNRR                                                              */
            uint32_t             : 22;
        } CARDNM_b;
    };

    union
    {
        __IOM uint32_t CARDMNM;         /*!< (@ 0x00000304) Common Agent Rejected Descriptor Maximum Number
                                         *                  Monitoring Register (CARDMNM)                              */

        struct
        {
            __IOM uint32_t RDMNRR : 10; /*!< [9..0] RDMNRR                                                             */
            uint32_t              : 22;
        } CARDMNM_b;
    };
    __IM uint32_t RESERVED9[2];

    union
    {
        __IOM uint32_t CARDCN;         /*!< (@ 0x00000310) Common Agent Rejected Descriptor Counter Register
                                        *                  (CARDCN)                                                   */

        struct
        {
            __IOM uint32_t RDN : 32;   /*!< [31..0] RDN                                                               */
        } CARDCN_b;
    };
    __IM uint32_t RESERVED10[59];

    union
    {
        __IOM uint32_t CAEIS0;          /*!< (@ 0x00000400) Common Agent Error Interrupt Status Register
                                         *                  0 (CAEIS0)                                                 */

        struct
        {
            __IOM uint32_t PECCES  : 1; /*!< [0..0] PECCES                                                             */
            __IOM uint32_t DSECCES : 1; /*!< [1..1] DSECCES                                                            */
            __IOM uint32_t BPECCES : 1; /*!< [2..2] BPECCES                                                            */
            uint32_t               : 5;
            __IOM uint32_t BPOPS   : 1; /*!< [8..8] BPOPS                                                              */
            __IOM uint32_t WMCLOS  : 1; /*!< [9..9] WMCLOS                                                             */
            __IOM uint32_t WMFLOS  : 1; /*!< [10..10] WMFLOS                                                           */
            uint32_t               : 5;
            __IOM uint32_t EEIPLN  : 4; /*!< [19..16] EEIPLN                                                           */
            uint32_t               : 12;
        } CAEIS0_b;
    };

    union
    {
        __IOM uint32_t CAEIE0;          /*!< (@ 0x00000404) Common Agent Error Interrupt Enable0 Register
                                         *                  (CAEIE0)                                                   */

        struct
        {
            __IOM uint32_t PECCEE  : 1; /*!< [0..0] PECCEE                                                             */
            __IOM uint32_t DSECCEE : 1; /*!< [1..1] DSECCEE                                                            */
            __IOM uint32_t BPECCEE : 1; /*!< [2..2] BPECCEE                                                            */
            uint32_t               : 5;
            __IOM uint32_t BPOPE   : 1; /*!< [8..8] BPOPE                                                              */
            __IOM uint32_t WMCLOE  : 1; /*!< [9..9] WMCLOE                                                             */
            __IOM uint32_t WMFLOE  : 1; /*!< [10..10] WMFLOE                                                           */
            uint32_t               : 21;
        } CAEIE0_b;
    };

    union
    {
        __IOM uint32_t CAEID0;          /*!< (@ 0x00000408) Common Agent Error Interrupt Disable Register
                                         *                  0 (CAEID0)                                                 */

        struct
        {
            __IOM uint32_t PECCED  : 1; /*!< [0..0] PECCED                                                             */
            __IOM uint32_t DSECCED : 1; /*!< [1..1] DSECCED                                                            */
            __IOM uint32_t BPECCED : 1; /*!< [2..2] BPECCED                                                            */
            uint32_t               : 5;
            __IOM uint32_t BPOPD   : 1; /*!< [8..8] BPOPD                                                              */
            __IOM uint32_t WMCLOD  : 1; /*!< [9..9] WMCLOD                                                             */
            __IOM uint32_t WMFLOD  : 1; /*!< [10..10] WMFLOD                                                           */
            uint32_t               : 21;
        } CAEID0_b;
    };
    __IM uint32_t RESERVED11;

    union
    {
        __IOM uint32_t CAEIS1;           /*!< (@ 0x00000410) Common Agent Error Interrupt Status Register
                                          *                  1 (CAEIS1)                                                 */

        struct
        {
            __IOM uint32_t PWMCLOS0 : 1; /*!< [0..0] PWMCLOS0                                                           */
            __IOM uint32_t PWMCLOS1 : 1; /*!< [1..1] PWMCLOS1                                                           */
            __IOM uint32_t PWMCLOS2 : 1; /*!< [2..2] PWMCLOS2                                                           */
            uint32_t                : 13;
            __IOM uint32_t PWMFLOS0 : 1; /*!< [16..16] PWMFLOS0                                                         */
            __IOM uint32_t PWMFLOS1 : 1; /*!< [17..17] PWMFLOS1                                                         */
            __IOM uint32_t PWMFLOS2 : 1; /*!< [18..18] PWMFLOS2                                                         */
            uint32_t                : 13;
        } CAEIS1_b;
    };

    union
    {
        __IOM uint32_t CAEIE1;           /*!< (@ 0x00000414) Common Agent Error Interrupt Enable Register
                                          *                  1 (CAEIE1)                                                 */

        struct
        {
            __IOM uint32_t PWMCLOE0 : 1; /*!< [0..0] PWMCLOE0                                                           */
            __IOM uint32_t PWMCLOE1 : 1; /*!< [1..1] PWMCLOE1                                                           */
            __IOM uint32_t PWMCLOE2 : 1; /*!< [2..2] PWMCLOE2                                                           */
            uint32_t                : 13;
            __IOM uint32_t PWMFLOE0 : 1; /*!< [16..16] PWMFLOE0                                                         */
            __IOM uint32_t PWMFLOE1 : 1; /*!< [17..17] PWMFLOE1                                                         */
            __IOM uint32_t PWMFLOE2 : 1; /*!< [18..18] PWMFLOE2                                                         */
            uint32_t                : 13;
        } CAEIE1_b;
    };

    union
    {
        __IOM uint32_t CAEID1;           /*!< (@ 0x00000418) Common Agent Error Interrupt Disable Register
                                          *                  1 (CAEID1)                                                 */

        struct
        {
            __IOM uint32_t PWMCLOD0 : 1; /*!< [0..0] PWMCLOD0                                                           */
            __IOM uint32_t PWMCLOD1 : 1; /*!< [1..1] PWMCLOD1                                                           */
            __IOM uint32_t PWMCLOD2 : 1; /*!< [2..2] PWMCLOD2                                                           */
            uint32_t                : 13;
            __IOM uint32_t PWMFLOD0 : 1; /*!< [16..16] PWMFLOD0                                                         */
            __IOM uint32_t PWMFLOD1 : 1; /*!< [17..17] PWMFLOD1                                                         */
            __IOM uint32_t PWMFLOD2 : 1; /*!< [18..18] PWMFLOD2                                                         */
            uint32_t                : 13;
        } CAEID1_b;
    };
    __IM uint32_t RESERVED12[9];

    union
    {
        __IOM uint32_t CAMIS0;         /*!< (@ 0x00000440) Common Agent Monitoring Interrupt Status Register
                                        *                  0 (CAMIS0)                                                 */

        struct
        {
            __IOM uint32_t PFS0 : 1;   /*!< [0..0] PFS0                                                               */
            __IOM uint32_t PFS1 : 1;   /*!< [1..1] PFS1                                                               */
            uint32_t            : 30;
        } CAMIS0_b;
    };

    union
    {
        __IOM uint32_t CAMIE0;         /*!< (@ 0x00000444) Common Agent Monitoring Interrupt Enable Register
                                        *                  0 (CAMIE0)                                                 */

        struct
        {
            __IOM uint32_t PFE0 : 1;   /*!< [0..0] PFE0                                                               */
            __IOM uint32_t PFE1 : 1;   /*!< [1..1] PFE1                                                               */
            uint32_t            : 30;
        } CAMIE0_b;
    };

    union
    {
        __IOM uint32_t CAMID0;         /*!< (@ 0x00000448) Common Agent Monitoring Interrupt Disable Register
                                        *                  0 (CAMID0)                                                 */

        struct
        {
            __IOM uint32_t PFD0 : 1;   /*!< [0..0] PFD0                                                               */
            __IOM uint32_t PFD1 : 1;   /*!< [1..1] PFD1                                                               */
            uint32_t            : 30;
        } CAMID0_b;
    };
    __IM uint32_t RESERVED13;

    union
    {
        __IOM uint32_t CAMIS1;         /*!< (@ 0x00000450) Common Agent Monitoring Interrupt Status Register
                                        *                  1 (CAMIS1)                                                 */

        struct
        {
            __IOM uint32_t PPFS0 : 1;  /*!< [0..0] PPFS0                                                              */
            __IOM uint32_t PPFS1 : 1;  /*!< [1..1] PPFS1                                                              */
            __IOM uint32_t PPFS2 : 1;  /*!< [2..2] PPFS2                                                              */
            __IOM uint32_t PPFS3 : 1;  /*!< [3..3] PPFS3                                                              */
            __IOM uint32_t PPFS4 : 1;  /*!< [4..4] PPFS4                                                              */
            __IOM uint32_t PPFS5 : 1;  /*!< [5..5] PPFS5                                                              */
            uint32_t             : 26;
        } CAMIS1_b;
    };

    union
    {
        __IOM uint32_t CAMIE1;         /*!< (@ 0x00000454) Common Agent Monitoring Interrupt Enable Register
                                        *                  1 (CAMIE1)                                                 */

        struct
        {
            __IOM uint32_t PPFE0 : 1;  /*!< [0..0] PPFE0                                                              */
            __IOM uint32_t PPFE1 : 1;  /*!< [1..1] PPFE1                                                              */
            __IOM uint32_t PPFE2 : 1;  /*!< [2..2] PPFE2                                                              */
            __IOM uint32_t PPFE3 : 1;  /*!< [3..3] PPFE3                                                              */
            __IOM uint32_t PPFE4 : 1;  /*!< [4..4] PPFE4                                                              */
            __IOM uint32_t PPFE5 : 1;  /*!< [5..5] PPFE5                                                              */
            uint32_t             : 26;
        } CAMIE1_b;
    };

    union
    {
        __IOM uint32_t CAMID1;         /*!< (@ 0x00000458) Common Agent Monitoring Interrupt Disable Register
                                        *                  1 (CAMID1)                                                 */

        struct
        {
            __IOM uint32_t PPFD0 : 1;  /*!< [0..0] PPFD0                                                              */
            __IOM uint32_t PPFD1 : 1;  /*!< [1..1] PPFD1                                                              */
            __IOM uint32_t PPFD2 : 1;  /*!< [2..2] PPFD2                                                              */
            __IOM uint32_t PPFD3 : 1;  /*!< [3..3] PPFD3                                                              */
            __IOM uint32_t PPFD4 : 1;  /*!< [4..4] PPFD4                                                              */
            __IOM uint32_t PPFD5 : 1;  /*!< [5..5] PPFD5                                                              */
            uint32_t             : 26;
        } CAMID1_b;
    };
} R_COMA_Type;                         /*!< Size = 1116 (0x45c)                                                       */

#endif                                 /* R_COMA_REG_H */
