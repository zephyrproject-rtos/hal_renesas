/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : bsp_irq_id.h
 * Version      : 1.00
 * Description  : bsp_irq_id header
 *********************************************************************************************************************/

#ifndef BSP_IRQ_ID_H
#define BSP_IRQ_ID_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/
#define DMAC_B0_DMAINT0_IRQn     DMAC_DMAINT0_S_IRQn
#define DMAC_B0_DMAINT1_IRQn     DMAC_DMAINT1_S_IRQn
#define DMAC_B0_DMAINT2_IRQn     DMAC_DMAINT2_S_IRQn
#define DMAC_B0_DMAINT3_IRQn     DMAC_DMAINT3_S_IRQn
#define DMAC_B0_DMAINT4_IRQn     DMAC_DMAINT4_S_IRQn
#define DMAC_B0_DMAINT5_IRQn     DMAC_DMAINT5_S_IRQn
#define DMAC_B0_DMAINT6_IRQn     DMAC_DMAINT6_S_IRQn
#define DMAC_B0_DMAINT7_IRQn     DMAC_DMAINT7_S_IRQn
#define DMAC_B0_DMAINT8_IRQn     DMAC_DMAINT8_S_IRQn
#define DMAC_B0_DMAINT9_IRQn     DMAC_DMAINT9_S_IRQn
#define DMAC_B0_DMAINT10_IRQn    DMAC_DMAINT10_S_IRQn
#define DMAC_B0_DMAINT11_IRQn    DMAC_DMAINT11_S_IRQn
#define DMAC_B0_DMAINT12_IRQn    DMAC_DMAINT12_S_IRQn
#define DMAC_B0_DMAINT13_IRQn    DMAC_DMAINT13_S_IRQn
#define DMAC_B0_DMAINT14_IRQn    DMAC_DMAINT14_S_IRQn
#define DMAC_B0_DMAINT15_IRQn    DMAC_DMAINT15_S_IRQn
#define DMAC_B1_DMAINT0_IRQn     DMAC_DMAINT0_NS_IRQn
#define DMAC_B1_DMAINT1_IRQn     DMAC_DMAINT1_NS_IRQn
#define DMAC_B1_DMAINT2_IRQn     DMAC_DMAINT2_NS_IRQn
#define DMAC_B1_DMAINT3_IRQn     DMAC_DMAINT3_NS_IRQn
#define DMAC_B1_DMAINT4_IRQn     DMAC_DMAINT4_NS_IRQn
#define DMAC_B1_DMAINT5_IRQn     DMAC_DMAINT5_NS_IRQn
#define DMAC_B1_DMAINT6_IRQn     DMAC_DMAINT6_NS_IRQn
#define DMAC_B1_DMAINT7_IRQn     DMAC_DMAINT7_NS_IRQn
#define DMAC_B1_DMAINT8_IRQn     DMAC_DMAINT8_NS_IRQn
#define DMAC_B1_DMAINT9_IRQn     DMAC_DMAINT9_NS_IRQn
#define DMAC_B1_DMAINT10_IRQn    DMAC_DMAINT10_NS_IRQn
#define DMAC_B1_DMAINT11_IRQn    DMAC_DMAINT11_NS_IRQn
#define DMAC_B1_DMAINT12_IRQn    DMAC_DMAINT12_NS_IRQn
#define DMAC_B1_DMAINT13_IRQn    DMAC_DMAINT13_NS_IRQn
#define DMAC_B1_DMAINT14_IRQn    DMAC_DMAINT14_NS_IRQn
#define DMAC_B1_DMAINT15_IRQn    DMAC_DMAINT15_NS_IRQn
#define DMAC_B0_DMAERR_IRQn      DMAC_DMAERR_S_IRQn
#define DMAC_B1_DMAERR_IRQn      DMAC_DMAERR_NS_IRQn

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * @addtogroup BSP_MPU_RZG2L
 * @{
 *********************************************************************************************************************/

typedef enum IRQn
{
    Reset_IRQn            = -15,
    NonMaskableInt_IRQn   = -14,
    HardFault_IRQn        = -13,
    MemoryManagement_IRQn = -12,
    BusFault_IRQn         = -11,
    UsageFault_IRQn       = -10,
    SecureFault_IRQn      = -9,
    SVCall_IRQn           = -5,
    DebugMonitor_IRQn     = -4,
    PendSV_IRQn           = -2,
    SysTick_IRQn          = -1,

    NMI_IRQn                   = 0,    /* IRQ No:0,   NMI */
    GPIO_IRQ0_IRQn             = 1,    /* IRQ No:1,   IRQ0 */
    GPIO_IRQ1_IRQn             = 2,    /* IRQ No:2,   IRQ1 */
    GPIO_IRQ2_IRQn             = 3,    /* IRQ No:3,   IRQ2 */
    GPIO_IRQ3_IRQn             = 4,    /* IRQ No:4,   IRQ3 */
    GPIO_IRQ4_IRQn             = 5,    /* IRQ No:5,   IRQ4 */
    GPIO_IRQ5_IRQn             = 6,    /* IRQ No:6,   IRQ5 */
    GPIO_IRQ6_IRQn             = 7,    /* IRQ No:7,   IRQ6 */
    GPIO_IRQ7_IRQn             = 8,    /* IRQ No:8,   IRQ7 */
    CA55_COMMIRQ1_IRQn         = 9,    /* IRQ No:9,   nCOMMIRQ[1] */
    CA55_COMMIRQ0_IRQn         = 10,   /* IRQ No:10,  nCOMMIRQ[0] */
    CA55_PMUIRQ1_IRQn          = 11,   /* IRQ No:11,  nPMUIRQ[1] */
    CA55_PMUIRQ0_IRQn          = 12,   /* IRQ No:12,  nPMUIRQ[0] */
    CA55_CLUSTERPMUIRQ_IRQn    = 13,   /* IRQ No:13,  nCLUSTERPMUIRQ */
    CA55_ERRIRQ2_IRQn          = 14,   /* IRQ No:14,  nERRIRQ[2] */
    CA55_ERRIRQ1_IRQn          = 15,   /* IRQ No:15,  nERRIRQ[1] */
    CA55_ERRIRQ0_IRQn          = 16,   /* IRQ No:16,  nERRIRQ[0] */
    CA55_FAULTIRQ2_IRQn        = 17,   /* IRQ No:17,  nFAULTIRQ[2] */
    CA55_FAULTIRQ1_IRQn        = 18,   /* IRQ No:18,  nFAULTIRQ[1] */
    CA55_FAULTIRQ0_IRQn        = 19,   /* IRQ No:19,  nFAULTIRQ[0] */
    CM33_CTIIRQ1_IRQn          = 20,   /* IRQ No:20,  CTIIRQ[1] */
    CM33_CTIIRQ0_IRQn          = 21,   /* IRQ No:21,  CTIIRQ[0] */
    GIC_FAULT_INT_IRQn         = 22,   /* IRQ No:22,  fault_int */
    GIC_ERR_INT_IRQn           = 23,   /* IRQ No:23,  err_int */
    GIC_PMU_INT_IRQn           = 24,   /* IRQ No:24,  pmu_int */
    SYSTEMBUS_BUS_ERR_INT_IRQn = 25,   /* IRQ No:25,  BUS_ERR_INT */
    SYSTEMBUS_TZC0INT_IRQn     = 26,   /* IRQ No:26,  TZC0INT */
    SYSTEMBUS_TZC1INT_IRQn     = 27,   /* IRQ No:27,  TZC1INT */
    SYSTEMBUS_TZC2INT_IRQn     = 28,   /* IRQ No:28,  TZC2INT */
    SYSTEMBUS_TZC3INT_IRQn     = 29,   /* IRQ No:29,  TZC3INT */
    SYSTEMBUS_ERRINT_S_IRQn    = 30,   /* IRQ No:30,  ERRINT_S */
    SYSTEMBUS_ERRINT_C_IRQn    = 31,   /* IRQ No:31,  ERRINT_C */
                                       /* IRQ No:32,  Reserved */
                                       /* IRQ No:33,  Reserved */
    ECCRAM0_EC7TIE1_IRQn       = 34,   /* IRQ No:34,  EC7TIE1_0 */
    ECCRAM0_EC7TIE2_IRQn       = 35,   /* IRQ No:35,  EC7TIE2_0 */
    ECCRAM0_EC7TIOVF_IRQn      = 36,   /* IRQ No:36,  EC7TIOVF_0 */
    ECCRAM1_EC7TIE1_IRQn       = 37,   /* IRQ No:37,  EC7TIE1_1 */
    ECCRAM1_EC7TIE2_IRQn       = 38,   /* IRQ No:38,  EC7TIE2_1 */
    ECCRAM1_EC7TIOVF_IRQn      = 39,   /* IRQ No:39,  EC7TIOVF_1 */
    DDR_CONTROLL_INT_IRQn      = 40,   /* IRQ No:40,  controller_int */
    SPI_SPIHF_IRQn             = 41,   /* IRQ No:41,  SPIHF */
    SYSC_LPM_INT_IRQn          = 42,   /* IRQ No:42,  SYS_LPM_INT */
    SYSC_CA55STBYDONE_INT_IRQn = 43,   /* IRQ No:43,  SYS_CA55STBYDONE_INT */
    SYSC_CM33STBYR_INT_IRQn    = 44,   /* IRQ No:44,  SYS_CM33STBYR_INT */
    SYSC_CA55_DENY_IRQn        = 45,   /* IRQ No:45,  SYS_CA55_DENY */
    GTM0_OSTM0INT_IRQn         = 46,   /* IRQ No:46,  OSTM0TINT */
    GTM1_OSTM1INT_IRQn         = 47,   /* IRQ No:47,  OSTM1TINT */
    GTM2_OSTM2INT_IRQn         = 48,   /* IRQ No:48,  OSTM2TINT */
    WDT0_WDTINT_A0_IRQn        = 49,   /* IRQ No:49,  WDTINT_A0 */
    WDT0_PERROUT_A0_IRQn       = 50,   /* IRQ No:50,  PERROUT_A0 */
    WDT1_WDTINT_A1_IRQn        = 51,   /* IRQ No:51,  WDTINT_A1 */
    WDT1_PERROUT_A1_IRQn       = 52,   /* IRQ No:52,  PERROUT_A1 */
    WDT2_WDTINT_M_IRQn         = 53,   /* IRQ No:53,  WDTINT_M */
    WDT2_PERROUT_M_IRQn        = 54,   /* IRQ No:54,  PERROUT_M */
                                       /* IRQ No:55,  Reserved */
                                       /* IRQ No:56,  msg_ch0_s */
    MHU1_S_IRQn = 57,                  /* IRQ No:57,  msg_ch1_s */
                                       /* IRQ No:58,  msg_ch2_s */
    MHU3_S_IRQn = 59,                  /* IRQ No:59,  msg_ch3_s */
                                       /* IRQ No:60,  msg_ch4_s */
                                       /* IRQ No:61,  msg_ch5_s */
                                       /* IRQ No:62,  rsp_ch0_s */
                                       /* IRQ No:63,  rsp_ch1_s */
                                       /* IRQ No:64,  rsp_ch2_s */
                                       /* IRQ No:65,  rsp_ch3_s */
    MHU4_S_IRQn = 66,                  /* IRQ No:66,  rsp_ch4_s */
    MHU5_S_IRQn = 67,                  /* IRQ No:67,  rsp_ch5_s */
                                       /* IRQ No:68,  msg_ch0_ns */
    MHU1_NS_IRQn = 69,                 /* IRQ No:69,  msg_ch1_ns */
                                       /* IRQ No:70,  msg_ch2_ns */
    MHU3_NS_IRQn = 71,                 /* IRQ No:71,  msg_ch3_ns */
                                       /* IRQ No:72,  msg_ch4_ns */
                                       /* IRQ No:73,  msg_ch5_ns */
                                       /* IRQ No:74,  rsp_ch0_ns */
                                       /* IRQ No:75,  rsp_ch1_ns */
                                       /* IRQ No:76,  rsp_ch2_ns */
                                       /* IRQ No:77,  rsp_ch3_ns */
    MHU4_NS_IRQn             = 78,     /* IRQ No:78,  rsp_ch4_ns */
    MHU5_NS_IRQn             = 79,     /* IRQ No:79,  rsp_ch5_ns */
    MHU_SW_MHU_INT0_IRQn     = 80,     /* IRQ No:80,  sw_mhu_int_0 */
    MHU_SW_MHU_INT1_IRQn     = 81,     /* IRQ No:81,  sw_mhu_int_1 */
    MHU_SW_MHU_INT2_IRQn     = 82,     /* IRQ No:82,  sw_mhu_int_2 */
    MHU_SW_MHU_INT3_IRQn     = 83,     /* IRQ No:83,  sw_mhu_int_3 */
    ETH0_PIF_INT_N_IRQn      = 84,     /* IRQ No:84,  pif_int_n_ch0 */
    ETH0_FIL_INT_N_IRQn      = 85,     /* IRQ No:85,  int_fil_n_ch0 */
    ETH0_ARP_NS_N_IRQn       = 86,     /* IRQ No:86,  int_arp_ns_n_ch0 */
    ETH1_PIF_INT_N_IRQn      = 87,     /* IRQ No:87,  pif_int_n_ch1 */
    ETH1_FIL_INT_N_IRQn      = 88,     /* IRQ No:88,  int_fil_n_ch1 */
    ETH1_ARP_NS_N_IRQn       = 89,     /* IRQ No:89,  int_arp_ns_n_ch1 */
    USB_U2H0_INT_IRQn        = 90,     /* IRQ No:90,  U2H0_INT */
    USB_U2H0_OHCI_INT_IRQn   = 91,     /* IRQ No:91,  U2H0_OHCI_INT */
    USB_U2H0_EHCI_INT_IRQn   = 92,     /* IRQ No:92,  U2H0_EHCI_INT */
    USB_U2H0_WAKEON_INT_IRQn = 93,     /* IRQ No:93,  U2H0_WAKEON_INT */
    USB_U2H0_OBINT_IRQn      = 94,     /* IRQ No:94,  U2H0_OBINT */
    USB_U2H1_INT_IRQn        = 95,     /* IRQ No:95,  U2H1_INT */
    USB_U2H1_OHCI_INT_IRQn   = 96,     /* IRQ No:96,  U2H1_OHCI_INT */
    USB_U2H1_EHCI_INT_IRQn   = 97,     /* IRQ No:97,  U2H1_EHCI_INT */
    USB_U2H1_WAKEON_INT_IRQn = 98,     /* IRQ No:98,  U2H1_WAKEON_INT */
    USB_U2H1_OBINT_IRQn      = 99,     /* IRQ No:99,  U2H1_OBINT */
    USB_U2P_IXL_INT_IRQn     = 100,    /* IRQ No:100, U2P_IXL_INT */
    USB_U2P_INT_DMA0_IRQn    = 101,    /* IRQ No:101, U2P_INT_DMA[0] */
    USB_U2P_INT_DMA1_IRQn    = 102,    /* IRQ No:102, U2P_INT_DMA[1] */
    USB_U2P_INT_DMAERR_IRQn  = 103,    /* IRQ No:103, U2P_INT_DMAERR */
    SDHI_eMMC0_OXMN_IRQn     = 104,    /* IRQ No:104, OXMNIRQ0 */
    SDHI_eMMC0_OXASIO_IRQn   = 105,    /* IRQ No:105, OXASIOIRQ0 */
    SDHI_eMMC1_OXMN_IRQn     = 106,    /* IRQ No:106, OXMNIRQ1 */
    SDHI_eMMC1_OXASIO_IRQn   = 107,    /* IRQ No:107, OXASIOIRQ1 */
    DMAC_DMAINT0_S_IRQn      = 108,    /* IRQ No:108, DMAINT0_S */
    DMAC_DMAINT1_S_IRQn      = 109,    /* IRQ No:109, DMAINT1_S */
    DMAC_DMAINT2_S_IRQn      = 110,    /* IRQ No:110, DMAINT2_S */
    DMAC_DMAINT3_S_IRQn      = 111,    /* IRQ No:111, DMAINT3_S */
    DMAC_DMAINT4_S_IRQn      = 112,    /* IRQ No:112, DMAINT4_S */
    DMAC_DMAINT5_S_IRQn      = 113,    /* IRQ No:113, DMAINT5_S */
    DMAC_DMAINT6_S_IRQn      = 114,    /* IRQ No:114, DMAINT6_S */
    DMAC_DMAINT7_S_IRQn      = 115,    /* IRQ No:115, DMAINT7_S */
    DMAC_DMAINT8_S_IRQn      = 116,    /* IRQ No:116, DMAINT8_S */
    DMAC_DMAINT9_S_IRQn      = 117,    /* IRQ No:117, DMAINT9_S */
    DMAC_DMAINT10_S_IRQn     = 118,    /* IRQ No:118, DMAINT10_S */
    DMAC_DMAINT11_S_IRQn     = 119,    /* IRQ No:119, DMAINT11_S */
    DMAC_DMAINT12_S_IRQn     = 120,    /* IRQ No:120, DMAINT12_S */
    DMAC_DMAINT13_S_IRQn     = 121,    /* IRQ No:121, DMAINT13_S */
    DMAC_DMAINT14_S_IRQn     = 122,    /* IRQ No:122, DMAINT14_S */
    DMAC_DMAINT15_S_IRQn     = 123,    /* IRQ No:123, DMAINT15_S */
    DMAC_DMAERR_S_IRQn       = 124,    /* IRQ No:124, DMAERR_S */
    DMAC_DMAINT0_NS_IRQn     = 125,    /* IRQ No:125, DMAINT0_NS */
    DMAC_DMAINT1_NS_IRQn     = 126,    /* IRQ No:126, DMAINT1_NS */
    DMAC_DMAINT2_NS_IRQn     = 127,    /* IRQ No:127, DMAINT2_NS */
    DMAC_DMAINT3_NS_IRQn     = 128,    /* IRQ No:128, DMAINT3_NS */
    DMAC_DMAINT4_NS_IRQn     = 129,    /* IRQ No:129, DMAINT4_NS */
    DMAC_DMAINT5_NS_IRQn     = 130,    /* IRQ No:130, DMAINT5_NS */
    DMAC_DMAINT6_NS_IRQn     = 131,    /* IRQ No:131, DMAINT6_NS */
    DMAC_DMAINT7_NS_IRQn     = 132,    /* IRQ No:132, DMAINT7_NS */
    DMAC_DMAINT8_NS_IRQn     = 133,    /* IRQ No:133, DMAINT8_NS */
    DMAC_DMAINT9_NS_IRQn     = 134,    /* IRQ No:134, DMAINT9_NS */
    DMAC_DMAINT10_NS_IRQn    = 135,    /* IRQ No:135, DMAINT10_NS */
    DMAC_DMAINT11_NS_IRQn    = 136,    /* IRQ No:136, DMAINT11_NS */
    DMAC_DMAINT12_NS_IRQn    = 137,    /* IRQ No:137, DMAINT12_NS */
    DMAC_DMAINT13_NS_IRQn    = 138,    /* IRQ No:138, DMAINT13_NS */
    DMAC_DMAINT14_NS_IRQn    = 139,    /* IRQ No:139, DMAINT14_NS */
    DMAC_DMAINT15_NS_IRQn    = 140,    /* IRQ No:140, DMAINT15_NS */
    DMAC_DMAERR_NS_IRQn      = 141,    /* IRQ No:141, DMAERR_NS */
    DSI_INT_SEQ0_IRQn        = 142,    /* IRQ No:142, dsi_int_seq0 */
    DSI_INT_SEQ1_IRQn        = 143,    /* IRQ No:143, dsi_int_seq1 */
    DSI_INT_VIN1_IRQn        = 144,    /* IRQ No:144, dsi_int_vin1 */
    DSI_INT_RCV_IRQn         = 145,    /* IRQ No:145, dsi_int_rcv */
    DSI_INT_FERR_IRQn        = 146,    /* IRQ No:146, dsi_int_ferr */
    DSI_INT_PPI_IRQn         = 147,    /* IRQ No:147, dsi_int_ppi */
    DSI_INT_DEBUG_IRQn       = 148,    /* IRQ No:148, dsi_int_debug */
    LCDC_VSPD_INT_IRQn       = 149,    /* IRQ No:149, VSPD_INT */
                                       /* IRQ No:150, Reserved */
                                       /* IRQ No:151, Reserved */
    LCDC_DU_INT_IRQn            = 152, /* IRQ No:152, DU_INT */
    MALIG31_IRQGPU_IRQn         = 153, /* IRQ No:153, IRQGPU */
    MALIG31_IRQJOB_IRQn         = 154, /* IRQ No:154, IRQJOB */
    MALIG31_IRQMMU_IRQn         = 155, /* IRQ No:155, IRQMMU */
    MALIG31_IRQEVENT_IRQn       = 156, /* IRQ No:156, IRQEVENT */
    ISU_INT_FRE_IRQn            = 157, /* IRQ No:157, ISU_INT_FRE */
    ISU_INT_DESE_IRQn           = 158, /* IRQ No:158, ISU_INT_DESE */
    ISU_INT_STOPE_IRQn          = 159, /* IRQ No:159, ISU_INT_STOPE */
    ISU_INT_ERR_IRQn            = 160, /* IRQ No:160, ISU_INT_ERR */
    VCPL4_VCP_VINT_IRQn         = 161, /* IRQ No:161, VCP.vcpl4.vint */
    VCPL4_VCP_CINT_IRQn         = 162, /* IRQ No:162, VCP.vcpl4.cint */
    VCPL4_VCP_VEDCINT_IRQn      = 163, /* IRQ No:163, VCP.vcpl4.vedcint */
    VCPL4_VCP_CEDCINT_IRQn      = 164, /* IRQ No:164, VCP.vcpl4.cedcint */
    VCPL4_VCP_EDCINT_IRQn       = 165, /* IRQ No:165, VCP.fcpcs.edcint */
    CRU_CSI2_LINK_INT_IRQn      = 166, /* IRQ No:166, csi2_link_int  */
    CRU_IMAGE_CONV_INT_IRQn     = 167, /* IRQ No:167, image_conv_int */
    CRU_IMAGE_CONV_ERR_INT_IRQn = 168, /* IRQ No:168, image_conv_err_int */
    CRU_AXI_MST_ERR_INT_IRQn    = 169, /* IRQ No:169, axi_mst_err_int */
    MTU0_TGIA_PLS_IRQn          = 170, /* IRQ No:170, TGIA0 */
    MTU0_TGIB_PLS_IRQn          = 171, /* IRQ No:171, TGIB0 */
    MTU0_TGIC_PLS_IRQn          = 172, /* IRQ No:172, TGIC0 */
    MTU0_TGID_PLS_IRQn          = 173, /* IRQ No:173, TGID0 */
    MTU0_TCIV_PLS_IRQn          = 174, /* IRQ No:174, TCIV0 */
    MTU0_TGIE_PLS_IRQn          = 175, /* IRQ No:175, TGIE0 */
    MTU0_TGIF_PLS_IRQn          = 176, /* IRQ No:176, TGIF0 */
    MTU1_TGIA_PLS_IRQn          = 177, /* IRQ No:177, TGIA1 */
    MTU1_TGIB_PLS_IRQn          = 178, /* IRQ No:178, TGIB1 */
    MTU1_TCIV_PLS_IRQn          = 179, /* IRQ No:179, TCIV1 */
    MTU1_TCIU_PLS_IRQn          = 180, /* IRQ No:180, TCIU1 */
    MTU2_TGIA_PLS_IRQn          = 181, /* IRQ No:181, TGIA2 */
    MTU2_TGIB_PLS_IRQn          = 182, /* IRQ No:182, TGIB2 */
    MTU2_TCIV_PLS_IRQn          = 183, /* IRQ No:183, TCIV2 */
    MTU2_TCIU_PLS_IRQn          = 184, /* IRQ No:184, TCIU2 */
    MTU3_TGIA_PLS_IRQn          = 185, /* IRQ No:185, TGIA3 */
    MTU3_TGIB_PLS_IRQn          = 186, /* IRQ No:186, TGIB3 */
    MTU3_TGIC_PLS_IRQn          = 187, /* IRQ No:187, TGIC3 */
    MTU3_TGID_PLS_IRQn          = 188, /* IRQ No:188, TGID3 */
    MTU3_TCIV_PLS_IRQn          = 189, /* IRQ No:189, TCIV3 */
    MTU4_TGIA_PLS_IRQn          = 190, /* IRQ No:190, TGIA4 */
    MTU4_TGIB_PLS_IRQn          = 191, /* IRQ No:191, TGIB4 */
    MTU4_TGIC_PLS_IRQn          = 192, /* IRQ No:192, TGIC4 */
    MTU4_TGID_PLS_IRQn          = 193, /* IRQ No:193, TGID4 */
    MTU4_TCIV_PLS_IRQn          = 194, /* IRQ No:194, TCIV4 */
    MTU5_TGIU_PLS_IRQn          = 195, /* IRQ No:195, TGIU5 */
    MTU5_TGIV_PLS_IRQn          = 196, /* IRQ No:196, TGIV5 */
    MTU5_TGIW_PLS_IRQn          = 197, /* IRQ No:197, TGIW5 */
    MTU6_TGIA_PLS_IRQn          = 198, /* IRQ No:198, TGIA6 */
    MTU6_TGIB_PLS_IRQn          = 199, /* IRQ No:199, TGIB6 */
    MTU6_TGIC_PLS_IRQn          = 200, /* IRQ No:200, TGIC6 */
    MTU6_TGID_PLS_IRQn          = 201, /* IRQ No:201, TGID6 */
    MTU6_TCIV_PLS_IRQn          = 202, /* IRQ No:202, TCIV6 */
    MTU7_TGIA_PLS_IRQn          = 203, /* IRQ No:203, TGIA7 */
    MTU7_TGIB_PLS_IRQn          = 204, /* IRQ No:204, TGIB7 */
    MTU7_TGIC_PLS_IRQn          = 205, /* IRQ No:205, TGIC7 */
    MTU7_TGID_PLS_IRQn          = 206, /* IRQ No:206, TGID7 */
    MTU7_TCIV_PLS_IRQn          = 207, /* IRQ No:207, TCIV7 */
    MTU8_TGIA_PLS_IRQn          = 208, /* IRQ No:208, TGIA8 */
    MTU8_TGIB_PLS_IRQn          = 209, /* IRQ No:209, TGIB8 */
    MTU8_TGIC_PLS_IRQn          = 210, /* IRQ No:210, TGIC8 */
    MTU8_TGID_PLS_IRQn          = 211, /* IRQ No:211, TGID8 */
    MTU8_TCIV_PLS_IRQn          = 212, /* IRQ No:212, TCIV8 */
    MTU8_TCIU_PLS_IRQn          = 213, /* IRQ No:213, TCIU8 */
    POE3_OEI1_IRQn              = 214, /* IRQ No:214, OEI1 */
    POE3_OEI2_IRQn              = 215, /* IRQ No:215, OEI2 */
    POE3_OEI3_IRQn              = 216, /* IRQ No:216, OEI3 */
    POE3_OEI4_IRQn              = 217, /* IRQ No:217, OEI4 */
    GPT0_CCMPA_IRQn             = 218, /* IRQ No:218, CCMPA0 */
    GPT0_CCMPB_IRQn             = 219, /* IRQ No:219, CCMPB0 */
    GPT0_CMPC_IRQn              = 220, /* IRQ No:220, CMPC0 */
    GPT0_CMPD_IRQn              = 221, /* IRQ No:221, CMPD0 */
    GPT0_CMPE_IRQn              = 222, /* IRQ No:222, CMPE0 */
    GPT0_CMPF_IRQn              = 223, /* IRQ No:223, CMPF0 */
    GPT0_ADTRGA_IRQn            = 224, /* IRQ No:224, ADTRGA0 */
    GPT0_ADTRGB_IRQn            = 225, /* IRQ No:225, ADTRGB0 */
    GPT0_OVF_IRQn               = 226, /* IRQ No:226, OVF0 */
    GPT0_UNF_IRQn               = 227, /* IRQ No:227, UNF0 */
                                       /* IRQ No:228, Reserved */
                                       /* IRQ No:229, Reserved */
                                       /* IRQ No:230, Reserved */
    GPT1_CCMPA_IRQn  = 231,            /* IRQ No:231, CCMPA1 */
    GPT1_CCMPB_IRQn  = 232,            /* IRQ No:232, CCMPB1 */
    GPT1_CMPC_IRQn   = 233,            /* IRQ No:233, CMPC1 */
    GPT1_CMPD_IRQn   = 234,            /* IRQ No:234, CMPD1 */
    GPT1_CMPE_IRQn   = 235,            /* IRQ No:235, CMPE1 */
    GPT1_CMPF_IRQn   = 236,            /* IRQ No:236, CMPF1 */
    GPT1_ADTRGA_IRQn = 237,            /* IRQ No:237, ADTRGA1 */
    GPT1_ADTRGB_IRQn = 238,            /* IRQ No:238, ADTRGB1 */
    GPT1_OVF_IRQn    = 239,            /* IRQ No:239, OVF1 */
    GPT1_UNF_IRQn    = 240,            /* IRQ No:240, UNF1 */
                                       /* IRQ No:241, Reserved */
                                       /* IRQ No:242, Reserved */
                                       /* IRQ No:243, Reserved */
    GPT2_CCMPA_IRQn  = 244,            /* IRQ No:244, CCMPA2 */
    GPT2_CCMPB_IRQn  = 245,            /* IRQ No:245, CCMPB2 */
    GPT2_CMPC_IRQn   = 246,            /* IRQ No:246, CMPC2 */
    GPT2_CMPD_IRQn   = 247,            /* IRQ No:247, CMPD2 */
    GPT2_CMPE_IRQn   = 248,            /* IRQ No:248, CMPE2 */
    GPT2_CMPF_IRQn   = 249,            /* IRQ No:249, CMPF2 */
    GPT2_ADTRGA_IRQn = 250,            /* IRQ No:250, ADTRGA2 */
    GPT2_ADTRGB_IRQn = 251,            /* IRQ No:251, ADTRGB2 */
    GPT2_OVF_IRQn    = 252,            /* IRQ No:252, OVF2 */
    GPT2_UNF_IRQn    = 253,            /* IRQ No:253, UNF2 */
                                       /* IRQ No:254, Reserved */
                                       /* IRQ No:255, Reserved */
                                       /* IRQ No:256, Reserved */
    GPT3_CCMPA_IRQn  = 257,            /* IRQ No:257, CCMPA3 */
    GPT3_CCMPB_IRQn  = 258,            /* IRQ No:258, CCMPB3 */
    GPT3_CMPC_IRQn   = 259,            /* IRQ No:259, CMPC3 */
    GPT3_CMPD_IRQn   = 260,            /* IRQ No:260, CMPD3 */
    GPT3_CMPE_IRQn   = 261,            /* IRQ No:261, CMPE3 */
    GPT3_CMPF_IRQn   = 262,            /* IRQ No:262, CMPF3 */
    GPT3_ADTRGA_IRQn = 263,            /* IRQ No:263, ADTRGA3 */
    GPT3_ADTRGB_IRQn = 264,            /* IRQ No:264, ADTRGB3 */
    GPT3_OVF_IRQn    = 265,            /* IRQ No:265, OVF3 */
    GPT3_UNF_IRQn    = 266,            /* IRQ No:266, UNF3 */
                                       /* IRQ No:267, Reserved */
                                       /* IRQ No:268, Reserved */
                                       /* IRQ No:269, Reserved */
    GPT4_CCMPA_IRQn  = 270,            /* IRQ No:270, CCMPA4 */
    GPT4_CCMPB_IRQn  = 271,            /* IRQ No:271, CCMPB4 */
    GPT4_CMPC_IRQn   = 272,            /* IRQ No:272, CMPC4 */
    GPT4_CMPD_IRQn   = 273,            /* IRQ No:273, CMPD4 */
    GPT4_CMPE_IRQn   = 274,            /* IRQ No:274, CMPE4 */
    GPT4_CMPF_IRQn   = 275,            /* IRQ No:275, CMPF4 */
    GPT4_ADTRGA_IRQn = 276,            /* IRQ No:276, ADTRGA4 */
    GPT4_ADTRGB_IRQn = 277,            /* IRQ No:277, ADTRGB4 */
    GPT4_OVF_IRQn    = 278,            /* IRQ No:278, OVF4 */
    GPT4_UNF_IRQn    = 279,            /* IRQ No:279, UNF4 */
                                       /* IRQ No:280, Reserved */
                                       /* IRQ No:281, Reserved */
                                       /* IRQ No:282, Reserved */
    GPT5_CCMPA_IRQn  = 283,            /* IRQ No:283, CCMPA5 */
    GPT5_CCMPB_IRQn  = 284,            /* IRQ No:284, CCMPB5 */
    GPT5_CMPC_IRQn   = 285,            /* IRQ No:285, CMPC5 */
    GPT5_CMPD_IRQn   = 286,            /* IRQ No:286, CMPD5 */
    GPT5_CMPE_IRQn   = 287,            /* IRQ No:287, CMPE5 */
    GPT5_CMPF_IRQn   = 288,            /* IRQ No:288, CMPF5 */
    GPT5_ADTRGA_IRQn = 289,            /* IRQ No:289, ADTRGA5 */
    GPT5_ADTRGB_IRQn = 290,            /* IRQ No:290, ADTRGB5 */
    GPT5_OVF_IRQn    = 291,            /* IRQ No:291, OVF5 */
    GPT5_UNF_IRQn    = 292,            /* IRQ No:292, UNF5 */
                                       /* IRQ No:293, Reserved */
                                       /* IRQ No:294, Reserved */
                                       /* IRQ No:295, Reserved */
    GPT6_CCMPA_IRQn  = 296,            /* IRQ No:296, CCMPA6 */
    GPT6_CCMPB_IRQn  = 297,            /* IRQ No:297, CCMPB6 */
    GPT6_CMPC_IRQn   = 298,            /* IRQ No:298, CMPC6 */
    GPT6_CMPD_IRQn   = 299,            /* IRQ No:299, CMPD6 */
    GPT6_CMPE_IRQn   = 300,            /* IRQ No:300, CMPE6 */
    GPT6_CMPF_IRQn   = 301,            /* IRQ No:301, CMPF6 */
    GPT6_ADTRGA_IRQn = 302,            /* IRQ No:302, ADTRGA6 */
    GPT6_ADTRGB_IRQn = 303,            /* IRQ No:303, ADTRGB6 */
    GPT6_OVF_IRQn    = 304,            /* IRQ No:304, OVF6 */
    GPT6_UNF_IRQn    = 305,            /* IRQ No:305, UNF6 */
                                       /* IRQ No:306, Reserved */
                                       /* IRQ No:307, Reserved */
                                       /* IRQ No:308, Reserved */
    GPT7_CCMPA_IRQn  = 309,            /* IRQ No:309, CCMPA7 */
    GPT7_CCMPB_IRQn  = 310,            /* IRQ No:310, CCMPB7 */
    GPT7_CMPC_IRQn   = 311,            /* IRQ No:311, CMPC7 */
    GPT7_CMPD_IRQn   = 312,            /* IRQ No:312, CMPD7 */
    GPT7_CMPE_IRQn   = 313,            /* IRQ No:313, CMPE7 */
    GPT7_CMPF_IRQn   = 314,            /* IRQ No:314, CMPF7 */
    GPT7_ADTRGA_IRQn = 315,            /* IRQ No:315, ADTRGA7 */
    GPT7_ADTRGB_IRQn = 316,            /* IRQ No:316, ADTRGB7 */
    GPT7_OVF_IRQn    = 317,            /* IRQ No:317, OVF7 */
    GPT7_UNF_IRQn    = 318,            /* IRQ No:318, UNF7 */
                                       /* IRQ No:319, Reserved */
                                       /* IRQ No:320, Reserved */
                                       /* IRQ No:321, Reserved */
    POEG_GROUP0_IRQn  = 322,           /* IRQ No:322, GROUP0 */
    POEG_GROUP1_IRQn  = 323,           /* IRQ No:323, GROUP1 */
    POEG_GROUP2_IRQn  = 324,           /* IRQ No:324, GROUP2 */
    POEG_GROUP3_IRQn  = 325,           /* IRQ No:325, GROUP3 */
    I2S0_INT_REQ_IRQn = 326,           /* IRQ No:326, INT_ssif_int_req_0 */
    I2S0_DMA_RX_IRQn  = 327,           /* IRQ No:327, INT_ssif_dma_rx_0 */
    I2S0_DMA_TX_IRQn  = 328,           /* IRQ No:328, INT_ssif_dma_tx_0 */
                                       /* IRQ No:329, Reserved */
    I2S1_INT_REQ_IRQn = 330,           /* IRQ No:330, INT_ssif_int_req_1 */
    I2S1_DMA_RX_IRQn  = 331,           /* IRQ No:331, INT_ssif_dma_rx_1 */
    I2S1_DMA_TX_IRQn  = 332,           /* IRQ No:332, INT_ssif_dma_tx_1 */
                                       /* IRQ No:333, Reserved */
    I2S2_INT_REQ_IRQn = 334,           /* IRQ No:334, INT_ssif_int_req_2 */
                                       /* IRQ No:335, Reserved */
                                       /* IRQ No:336, Reserved */
    I2S2_DMA_RT_IRQn  = 337,           /* IRQ No:337, INT_ssif_dma_rt_2 */
    I2S3_INT_REQ_IRQn = 338,           /* IRQ No:338, INT_ssif_int_req_3 */
    I2S3_DMA_RX_IRQn  = 339,           /* IRQ No:339, INT_ssif_dma_rx_3 */
    I2S3_DMA_TX_IRQn  = 340,           /* IRQ No:340, INT_ssif_dma_tx_3 */
                                       /* IRQ No:341, Reserved */
    SRC_IDEI_IRQn           = 342,     /* IRQ No:342, SRC_IDEI */
    SRC_ODFI_IRQn           = 343,     /* IRQ No:343, SRC_ODFI */
    SRC_CEF_IRQn            = 344,     /* IRQ No:344, SRC_CEF */
    SRC_UDF_IRQn            = 345,     /* IRQ No:345, SRC_UDF */
    SRC_OVF_IRQn            = 346,     /* IRQ No:346, SRC_OVF */
    ADC_INTAD_IRQn          = 347,     /* IRQ No:347, INTAD */
    RIIC0_RI_IRQn           = 348,     /* IRQ No:348, INTRIICRI0 */
    RIIC0_TI_IRQn           = 349,     /* IRQ No:349, INTRIICTI0 */
    RIIC0_TEI_IRQn          = 350,     /* IRQ No:350, INTRIICTEI0 */
    RIIC0_NAKI_IRQn         = 351,     /* IRQ No:351, INTRIICNAKI0 */
    RIIC0_SPI_IRQn          = 352,     /* IRQ No:352, INTRIICSPI0 */
    RIIC0_STI_IRQn          = 353,     /* IRQ No:353, INTRIICSTI0 */
    RIIC0_ALI_IRQn          = 354,     /* IRQ No:354, INTRIICALI0 */
    RIIC0_TMOI_IRQn         = 355,     /* IRQ No:355, INTRIICTMOI0 */
    RIIC1_RI_IRQn           = 356,     /* IRQ No:356, INTRIICRI1 */
    RIIC1_TI_IRQn           = 357,     /* IRQ No:357, INTRIICTI1 */
    RIIC1_TEI_IRQn          = 358,     /* IRQ No:358, INTRIICTEI1 */
    RIIC1_NAKI_IRQn         = 359,     /* IRQ No:359, INTRIICNAKI1 */
    RIIC1_SPI_IRQn          = 360,     /* IRQ No:360, INTRIICSPI1 */
    RIIC1_STI_IRQn          = 361,     /* IRQ No:361, INTRIICSTI1 */
    RIIC1_ALI_IRQn          = 362,     /* IRQ No:362, INTRIICALI1 */
    RIIC1_TMOI_IRQn         = 363,     /* IRQ No:363, INTRIICTMOI1 */
    RIIC2_RI_IRQn           = 364,     /* IRQ No:364, INTRIICRI2 */
    RIIC2_TI_IRQn           = 365,     /* IRQ No:365, INTRIICTI2 */
    RIIC2_TEI_IRQn          = 366,     /* IRQ No:366, INTRIICTEI2 */
    RIIC2_NAKI_IRQn         = 367,     /* IRQ No:367, INTRIICNAKI2 */
    RIIC2_SPI_IRQn          = 368,     /* IRQ No:368, INTRIICSPI2 */
    RIIC2_STI_IRQn          = 369,     /* IRQ No:369, INTRIICSTI2 */
    RIIC2_ALI_IRQn          = 370,     /* IRQ No:370, INTRIICALI2 */
    RIIC2_TMOI_IRQn         = 371,     /* IRQ No:371, INTRIICTMOI2 */
    RIIC3_RI_IRQn           = 372,     /* IRQ No:372, INTRIICRI3 */
    RIIC3_TI_IRQn           = 373,     /* IRQ No:373, INTRIICTI3 */
    RIIC3_TEI_IRQn          = 374,     /* IRQ No:374, INTRIICTEI3 */
    RIIC3_NAKI_IRQn         = 375,     /* IRQ No:375, INTRIICNAKI3 */
    RIIC3_SPI_IRQn          = 376,     /* IRQ No:376, INTRIICSPI3 */
    RIIC3_STI_IRQn          = 377,     /* IRQ No:377, INTRIICSTI3 */
    RIIC3_ALI_IRQn          = 378,     /* IRQ No:378, INTRIICALI3 */
    RIIC3_TMOI_IRQn         = 379,     /* IRQ No:379, INTRIICTMOI3 */
    SCIF0_RERR_IRQn         = 380,     /* IRQ No:380, ERI0 */
    SCIF0_BRK_IRQn          = 381,     /* IRQ No:381, BRI0 */
    SCIF0_RXI_IRQn          = 382,     /* IRQ No:382, RXI0 */
    SCIF0_TXI_IRQn          = 383,     /* IRQ No:383, TXI0 */
    SCIF0_TEI_DRI_IRQn      = 384,     /* IRQ No:384, TEI0_DRI0 */
    SCIF1_RERR_IRQn         = 385,     /* IRQ No:385, ERI1 */
    SCIF1_BRK_IRQn          = 386,     /* IRQ No:386, BRI1 */
    SCIF1_RXI_IRQn          = 387,     /* IRQ No:387, RXI1 */
    SCIF1_TXI_IRQn          = 388,     /* IRQ No:388, TXI1 */
    SCIF1_TEI_DRI_IRQn      = 389,     /* IRQ No:389, TEI1_DRI1 */
    SCIF2_RERR_IRQn         = 390,     /* IRQ No:390, ERI2 */
    SCIF2_BRK_IRQn          = 391,     /* IRQ No:391, BRI2 */
    SCIF2_RXI_IRQn          = 392,     /* IRQ No:392, RXI2 */
    SCIF2_TXI_IRQn          = 393,     /* IRQ No:393, TXI2 */
    SCIF2_TEI_DRI_IRQn      = 394,     /* IRQ No:394, TEI2_DRI2 */
    SCIF3_RERR_IRQn         = 395,     /* IRQ No:395, ERI3 */
    SCIF3_BRK_IRQn          = 396,     /* IRQ No:396, BRI3 */
    SCIF3_RXI_IRQn          = 397,     /* IRQ No:397, RXI3 */
    SCIF3_TXI_IRQn          = 398,     /* IRQ No:398, TXI3 */
    SCIF3_TEI_DRI_IRQn      = 399,     /* IRQ No:399, TEI3_DRI3 */
    SCIF4_RERR_IRQn         = 400,     /* IRQ No:400, ERI4 */
    SCIF4_BRK_IRQn          = 401,     /* IRQ No:401, BRI4 */
    SCIF4_RXI_IRQn          = 402,     /* IRQ No:402, RXI4 */
    SCIF4_TXI_IRQn          = 403,     /* IRQ No:403, TXI4 */
    SCIF4_TEI_DRI_IRQn      = 404,     /* IRQ No:404, TEI4_DRI4 */
    SCI0_ERI_IRQn           = 405,     /* IRQ No:405, ERI0 */
    SCI0_RXI_IRQn           = 406,     /* IRQ No:406, RXI0 */
    SCI0_TXI_IRQn           = 407,     /* IRQ No:407, TXI0 */
    SCI0_TEI_IRQn           = 408,     /* IRQ No:408, TEI0 */
    SCI1_ERI_IRQn           = 409,     /* IRQ No:409, ERI1 */
    SCI1_RXI_IRQn           = 410,     /* IRQ No:410, RXI1 */
    SCI1_TXI_IRQn           = 411,     /* IRQ No:411, TXI1 */
    SCI1_TEI_IRQn           = 412,     /* IRQ No:412, TEI1 */
    RSPI0_RX_IRQn           = 413,     /* IRQ No:413, SPRI0 */
    RSPI0_TX_IRQn           = 414,     /* IRQ No:414, SPTI0 */
    RSPI0_ERR_IRQn          = 415,     /* IRQ No:415, SPEI0 */
    RSPI1_RX_IRQn           = 416,     /* IRQ No:416, SPRI1 */
    RSPI1_TX_IRQn           = 417,     /* IRQ No:417, SPTI1 */
    RSPI1_ERR_IRQn          = 418,     /* IRQ No:418, SPEI1 */
    RSPI2_RX_IRQn           = 419,     /* IRQ No:419, SPRI2 */
    RSPI2_TX_IRQn           = 420,     /* IRQ No:420, SPTI2 */
    RSPI2_ERR_IRQn          = 421,     /* IRQ No:421, SPEI2 */
    CANFD_INTRCAN0ERR_IRQn  = 422,     /* IRQ No:422, INTRCAN0ERR */
    CANFD_INTRCAN1ERR_IRQn  = 423,     /* IRQ No:423, INTRCAN1ERR */
    CANFD_INTRCAN0REC_IRQn  = 424,     /* IRQ No:424, INTRCAN0REC */
    CANFD_INTRCAN1REC_IRQn  = 425,     /* IRQ No:425, INTRCAN1REC */
    CANFD_INTRCANGERR_IRQn  = 426,     /* IRQ No:426, INTRCANGERR */
    CANFD_INTRCANGRECC_IRQn = 427,     /* IRQ No:427, INTRCANGRECC */
    CANFD_INTRCAN0TRX_IRQn  = 428,     /* IRQ No:428, INTRCAN0TRX */
    CANFD_INTRCAN1TRX_IRQn  = 429,     /* IRQ No:429, INTRCAN1TRX */
    TSIP_WRRDY1_IRQn        = 430,     /* IRQ No:430, WRRDY1 */
    TSIP_WRRDY0_IRQn        = 431,     /* IRQ No:431, WRRDY0 */
    TSIP_WRRDY4_IRQn        = 432,     /* IRQ No:432, WRRDY4 */
    TSIP_RDRDY1_IRQn        = 433,     /* IRQ No:433, RDRDY1 */
    TSIP_RDRDY0_IRQn        = 434,     /* IRQ No:434, RDRDY0 */
    TSIP_ROMOK_IRQn         = 435,     /* IRQ No:435, ROMOK */
    TSIP_LONG_PLG_IRQn      = 436,     /* IRQ No:436, LONG_PLG */
    TSIP_PROC_BUSY_IRQn     = 437,     /* IRQ No:437, PROC_BUSY */
    TSIP_IRDRDY_IRQn        = 438,     /* IRQ No:438, IRDRDY */
    TSIP_IWRRDY_IRQn        = 439,     /* IRQ No:439, IWRRDY */
                                       /* IRQ No:440, Reserved */
                                       /* IRQ No:441, Reserved */
                                       /* IRQ No:442, Reserved */
                                       /* IRQ No:443, Reserved */
    GPIO_TINT0_IRQn  = 444,            /* IRQ No:444, TINT0 */
    GPIO_TINT1_IRQn  = 445,            /* IRQ No:445, TINT1 */
    GPIO_TINT2_IRQn  = 446,            /* IRQ No:446, TINT2 */
    GPIO_TINT3_IRQn  = 447,            /* IRQ No:447, TINT3 */
    GPIO_TINT4_IRQn  = 448,            /* IRQ No:448, TINT4 */
    GPIO_TINT5_IRQn  = 449,            /* IRQ No:449, TINT5 */
    GPIO_TINT6_IRQn  = 450,            /* IRQ No:450, TINT6 */
    GPIO_TINT7_IRQn  = 451,            /* IRQ No:451, TINT7 */
    GPIO_TINT8_IRQn  = 452,            /* IRQ No:452, TINT8 */
    GPIO_TINT9_IRQn  = 453,            /* IRQ No:453, TINT9 */
    GPIO_TINT10_IRQn = 454,            /* IRQ No:454, TINT10 */
    GPIO_TINT11_IRQn = 455,            /* IRQ No:455, TINT11 */
    GPIO_TINT12_IRQn = 456,            /* IRQ No:456, TINT12 */
    GPIO_TINT13_IRQn = 457,            /* IRQ No:457, TINT13 */
    GPIO_TINT14_IRQn = 458,            /* IRQ No:458, TINT14 */
    GPIO_TINT15_IRQn = 459,            /* IRQ No:459, TINT15 */
    GPIO_TINT16_IRQn = 460,            /* IRQ No:460, TINT16 */
    GPIO_TINT17_IRQn = 461,            /* IRQ No:461, TINT17 */
    GPIO_TINT18_IRQn = 462,            /* IRQ No:462, TINT18 */
    GPIO_TINT19_IRQn = 463,            /* IRQ No:463, TINT19 */
    GPIO_TINT20_IRQn = 464,            /* IRQ No:464, TINT20 */
    GPIO_TINT21_IRQn = 465,            /* IRQ No:465, TINT21 */
    GPIO_TINT22_IRQn = 466,            /* IRQ No:466, TINT22 */
    GPIO_TINT23_IRQn = 467,            /* IRQ No:467, TINT23 */
    GPIO_TINT24_IRQn = 468,            /* IRQ No:468, TINT24 */
    GPIO_TINT25_IRQn = 469,            /* IRQ No:469, TINT25 */
    GPIO_TINT26_IRQn = 470,            /* IRQ No:470, TINT26 */
    GPIO_TINT27_IRQn = 471,            /* IRQ No:471, TINT27 */
    GPIO_TINT28_IRQn = 472,            /* IRQ No:472, TINT28 */
    GPIO_TINT29_IRQn = 473,            /* IRQ No:473, TINT29 */
    GPIO_TINT30_IRQn = 474,            /* IRQ No:474, TINT30 */
    GPIO_TINT31_IRQn = 475,            /* IRQ No:475, TINT31 */
                                       /* IRQ No:476, Reserved */
                                       /* IRQ No:477, Reserved */
                                       /* IRQ No:478, Reserved */
                                       /* IRQ No:479, Reserved */
} IRQn_Type;

/** @} (end addtogroup BSP_MPU_RZG2L) */

#endif                                 /* BSP_IRQ_ID_H */
