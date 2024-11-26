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
 * @addtogroup BSP_MPU_RZG2UL
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

    NMI_IRQn                   = 0,     /* IRQ No:0,   NMI */
    GPIO_IRQ0_IRQn             = 1,     /* IRQ No:1,   IRQ0 */
    GPIO_IRQ1_IRQn             = 2,     /* IRQ No:2,   IRQ1 */
    GPIO_IRQ2_IRQn             = 3,     /* IRQ No:3,   IRQ2 */
    GPIO_IRQ3_IRQn             = 4,     /* IRQ No:4,   IRQ3 */
    GPIO_IRQ4_IRQn             = 5,     /* IRQ No:5,   IRQ4 */
    GPIO_IRQ5_IRQn             = 6,     /* IRQ No:6,   IRQ5 */
    GPIO_IRQ6_IRQn             = 7,     /* IRQ No:7,   IRQ6 */
    GPIO_IRQ7_IRQn             = 8,     /* IRQ No:8,   IRQ7 */
    CA55_ERRIRQ1_IRQn          = 9,     /* IRQ No:9,  nERRIRQ[1] */
    CA55_ERRIRQ0_IRQn          = 10,    /* IRQ No:10,  nERRIRQ[0] */
    CA55_FAULTIRQ1_IRQn        = 11,    /* IRQ No:11,  nFAULTIRQ[1] */
    CA55_FAULTIRQ0_IRQn        = 12,    /* IRQ No:12,  nFAULTIRQ[0] */
    CA55_COMMIRQ0_IRQn         = 13,    /* IRQ No:13,  nCOMMIRQ[0] */
    CA55_PMUIRQ0_IRQn          = 14,    /* IRQ No:14,  nPMUIRQ[0] */
    CA55_CLUSTERPMUIRQ_IRQn    = 15,    /* IRQ No:15,  nCLUSTERPMUIRQ */
    CM33_CTIIRQ1_IRQn          = 16,    /* IRQ No:16,  CTIIRQ[1] */
    CM33_CTIIRQ0_IRQn          = 17,    /* IRQ No:17,  CTIIRQ[0] */
    CM33FPU_CTIIRQ1_IRQn       = 18,    /* IRQ No:18,  CTIIRQ[1] */
    CM33FPU_CTIIRQ0_IRQn       = 19,    /* IRQ No:19,  CTIIRQ[0] */
    CM33FPU_FPIXC_IRQn         = 20,    /* IRQ No:20,  FPIXC */
    CM33FPU_FPIDC_IRQn         = 21,    /* IRQ No:21,  FPIDC */
    CM33FPU_FPOFC_IRQn         = 22,    /* IRQ No:22,  FPOFC */
    CM33FPU_FPUFC_IRQn         = 23,    /* IRQ No:23,  FPUFC */
    CM33FPU_FPDZC_IRQn         = 24,    /* IRQ No:24,  FPDZC */
    CM33FPU_FPIOC_IRQn         = 25,    /* IRQ No:25,  FPIOC */
    GIC_FAULT_INT_IRQn         = 26,    /* IRQ No:26,  fault_int */
    GIC_ERR_INT_IRQn           = 27,    /* IRQ No:27,  err_int */
    GIC_PMU_INT_IRQn           = 28,    /* IRQ No:28,  pmu_int */
    SYSTEMBUS_BUS_ERR_INT_IRQn = 29,    /* IRQ No:29,  BUS_ERR_INT */
                                        /* IRQ No:30,  Reserved */
    ECCRAM_EC7TIE1_IRQn         = 31,   /* IRQ No:31,  EC7TIE1_0 */
    ECCRAM_EC7TIE2_IRQn         = 32,   /* IRQ No:32,  EC7TIE2_0 */
    ECCRAM_EC7TIOVF_IRQn        = 33,   /* IRQ No:33,  EC7TIOVF_0 */
    DDR_CONTROLL_INT_IRQn       = 34,   /* IRQ No:34,  controller_int */
    DDR_DWC_DDRPHY_INT_IRQn     = 35,   /* IRQ No:35,  dwc_ddrphy_int_n */
    DDR_SREF_ERROR_INT_IRQn     = 36,   /* IRQ No:36,  sref_error */
    XSPI_SPI_LEVEL_INT_IRQn     = 37,   /* IRQ No:37,  int_spi_level */
    XSPI_SPI_ERR_LEVEL_INT_IRQn = 38,   /* IRQ No:38,  int_spi_err_level */
    SYSC_LPM_INT_IRQn           = 39,   /* IRQ No:39,  SYS_LPM_INT */
    SYSC_CA55STBYDONE_INT_IRQn  = 40,   /* IRQ No:40,  SYS_CA55STBYDONE_INT */
    SYSC_CM33STBYR_INT_IRQn     = 41,   /* IRQ No:41,  SYS_CM33STBYR_INT */
    SYSC_CA55_DENY_IRQn         = 42,   /* IRQ No:42,  SYS_CA55_DENY */
    VBATTB_TAMPDI_IRQn          = 43,   /* IRQ No:43,  TAMPDI */
    GTM0_OSTM0INT_IRQn          = 44,   /* IRQ No:44,  OSTM0TINT */
    GTM1_OSTM1INT_IRQn          = 45,   /* IRQ No:45,  OSTM1TINT */
    GTM2_OSTM2INT_IRQn          = 46,   /* IRQ No:46,  OSTM2TINT */
    GTM3_OSTM3INT_IRQn          = 47,   /* IRQ No:47,  OSTM3TINT */
    GTM4_OSTM4INT_IRQn          = 48,   /* IRQ No:48,  OSTM4TINT */
    GTM5_OSTM5INT_IRQn          = 49,   /* IRQ No:49,  OSTM5TINT */
    GTM6_OSTM6INT_IRQn          = 50,   /* IRQ No:50,  OSTM6TINT */
    GTM7_OSTM7INT_IRQn          = 51,   /* IRQ No:51,  OSTM7TINT */
                                        /* IRQ No:52,  PERROUT_A0 */
                                        /* IRQ No:53,  WDTINT_A0 */
    WDT1_PERROUT_IRQn = 54,             /* IRQ No:54,  PERROUT_M0 */
    WDT1_WDTINT_IRQn  = 55,             /* IRQ No:55,  WDTINT_M0 */
    WDT2_PERROUT_IRQn = 56,             /* IRQ No:56,  PERROUT_M1 */
    WDT2_WDTINT_IRQn  = 57,             /* IRQ No:57,  WDTINT_M1 */
#if BSP_CURRENT_CORE == RZG3S_CORE_CM33
    MHU1_NS_IRQn         = 58,          /* IRQ No:58,  msg_ch1_ns */
    MHU3_NS_IRQn         = 59,          /* IRQ No:59,  msg_ch3_ns */
    MHU4_NS_IRQn         = 60,          /* IRQ No:60,  rsp_ch4_ns */
    MHU5_NS_IRQn         = 61,          /* IRQ No:61,  rsp_ch5_ns */
    MHU1_S_IRQn          = 62,          /* IRQ No:62,  msg_ch1_s */
    MHU3_S_IRQn          = 63,          /* IRQ No:63,  msg_ch3_s */
    MHU4_S_IRQn          = 64,          /* IRQ No:64,  rsp_ch4_s */
    MHU5_S_IRQn          = 65,          /* IRQ No:65,  rsp_ch5_s */
    MHU_SW_MHU_INT0_IRQn = 66,          /* IRQ No:66,  swint_ch0_ns */
    MHU_SW_MHU_INT1_IRQn = 67,          /* IRQ No:67,  swint_ch1_ns */
#elif BSP_CURRENT_CORE == RZG3S_CORE_CM33_FPU
    MHU0_NS_IRQn         = 58,          /* IRQ No:58,  msg_ch0_ns */
    MHU2_NS_IRQn         = 59,          /* IRQ No:59,  rsp_ch2_ns */
    MHU3_NS_IRQn         = 60,          /* IRQ No:60,  rsp_ch3_ns */
    MHU5_NS_IRQn         = 61,          /* IRQ No:61,  msg_ch5_ns */
    MHU0_S_IRQn          = 62,          /* IRQ No:62,  msg_ch0_s */
    MHU2_S_IRQn          = 63,          /* IRQ No:63,  rsp_ch2_s */
    MHU3_S_IRQn          = 64,          /* IRQ No:64,  rsp_ch3_s */
    MHU5_S_IRQn          = 65,          /* IRQ No:65,  msg_ch5_s */
    MHU_SW_MHU_INT3_IRQn = 66,          /* IRQ No:66,  swint_ch3_ns */
    MHU_SW_MHU_INT5_IRQn = 67,          /* IRQ No:67,  swint_ch5_ns */
#endif /* BSP_CURRENT_CORE */
    ETH0_PIF_INT_N_IRQn      = 68,      /* IRQ No:68,  pif_int_n_ch0 */
    ETH0_FIL_INT_N_IRQn      = 69,      /* IRQ No:69,  int_fil_n_ch0 */
    ETH0_ARP_NS_N_IRQn       = 70,      /* IRQ No:70,  int_arp_ns_n_ch0 */
    ETH1_PIF_INT_N_IRQn      = 71,      /* IRQ No:71,  pif_int_n_ch1 */
    ETH1_FIL_INT_N_IRQn      = 72,      /* IRQ No:72,  int_fil_n_ch1 */
    ETH1_ARP_NS_N_IRQn       = 73,      /* IRQ No:73,  int_arp_ns_n_ch1 */
    USB_U2H0_INT_IRQn        = 74,      /* IRQ No:74,  U2H0_INT */
    USB_U2H0_OHCI_INT_IRQn   = 75,      /* IRQ No:75,  U2H0_OHCI_INT */
    USB_U2H0_EHCI_INT_IRQn   = 76,      /* IRQ No:76,  U2H0_EHCI_INT */
    USB_U2H0_WAKEON_INT_IRQn = 77,      /* IRQ No:77,  U2H0_WAKEON_INT */
    USB_U2H0_OBINT_IRQn      = 78,      /* IRQ No:78,  U2H0_OBINT */
    USB_U2H1_INT_IRQn        = 79,      /* IRQ No:79,  U2H1_INT */
    USB_U2H1_OHCI_INT_IRQn   = 80,      /* IRQ No:80,  U2H1_OHCI_INT */
    USB_U2H1_EHCI_INT_IRQn   = 81,      /* IRQ No:81,  U2H1_EHCI_INT */
    USB_U2H1_WAKEON_INT_IRQn = 82,      /* IRQ No:82,  U2H1_WAKEON_INT */
    USB_U2H1_OBINT_IRQn      = 83,      /* IRQ No:83,  U2H1_OBINT */
    USB_U2P_INT_DMAERR_IRQn  = 84,      /* IRQ No:84,  U2P_INT_DMAERR */
    USB_U2P_IXL_INT_IRQn     = 85,      /* IRQ No:85,  U2P_IXL_INT */
    USB_U2P_INT_DMA0_IRQn    = 86,      /* IRQ No:86,  U2P_INT_DMA[0] */
    USB_U2P_INT_DMA1_IRQn    = 87,      /* IRQ No:87,  U2P_INT_DMA[1] */
    SDHI_eMMC0_OXMN_IRQn     = 88,      /* IRQ No:88,  OXMNIRQ0 */
    SDHI_eMMC0_OXASIO_IRQn   = 89,      /* IRQ No:89,  OXASIOIRQ0 */
    SDHI_eMMC1_OXMN_IRQn     = 90,      /* IRQ No:90,  OXMNIRQ1 */
    SDHI_eMMC1_OXASIO_IRQn   = 91,      /* IRQ No:91,  OXASIOIRQ1 */
    SDHI_eMMC2_OXMN_IRQn     = 92,      /* IRQ No:92,  OXMNIRQ1 */
    SDHI_eMMC2_OXASIO_IRQn   = 93,      /* IRQ No:93,  OXASIOIRQ1 */
    DMAC_DMAERR_S_IRQn       = 94,      /* IRQ No:94,  DMAERR_S */
    DMAC_DMAINT0_S_IRQn      = 95,      /* IRQ No:95,  DMAINT0_S */
    DMAC_DMAINT1_S_IRQn      = 96,      /* IRQ No:96,  DMAINT1_S */
    DMAC_DMAINT2_S_IRQn      = 97,      /* IRQ No:97,  DMAINT2_S */
    DMAC_DMAINT3_S_IRQn      = 98,      /* IRQ No:98,  DMAINT3_S */
    DMAC_DMAINT4_S_IRQn      = 99,      /* IRQ No:99,  DMAINT4_S */
    DMAC_DMAINT5_S_IRQn      = 100,     /* IRQ No:100, DMAINT5_S */
    DMAC_DMAINT6_S_IRQn      = 101,     /* IRQ No:101, DMAINT6_S */
    DMAC_DMAINT7_S_IRQn      = 102,     /* IRQ No:102, DMAINT7_S */
    DMAC_DMAINT8_S_IRQn      = 103,     /* IRQ No:103, DMAINT8_S */
    DMAC_DMAINT9_S_IRQn      = 104,     /* IRQ No:104, DMAINT9_S */
    DMAC_DMAINT10_S_IRQn     = 105,     /* IRQ No:105, DMAINT10_S */
    DMAC_DMAINT11_S_IRQn     = 106,     /* IRQ No:106, DMAINT11_S */
    DMAC_DMAINT12_S_IRQn     = 107,     /* IRQ No:107, DMAINT12_S */
    DMAC_DMAINT13_S_IRQn     = 108,     /* IRQ No:108, DMAINT13_S */
    DMAC_DMAINT14_S_IRQn     = 109,     /* IRQ No:109, DMAINT14_S */
    DMAC_DMAINT15_S_IRQn     = 110,     /* IRQ No:110, DMAINT15_S */
    DMAC_DMAERR_NS_IRQn      = 111,     /* IRQ No:111, DMAERR_NS */
    DMAC_DMAINT0_NS_IRQn     = 112,     /* IRQ No:112, DMAINT0_NS */
    DMAC_DMAINT1_NS_IRQn     = 113,     /* IRQ No:113, DMAINT1_NS */
    DMAC_DMAINT2_NS_IRQn     = 114,     /* IRQ No:114, DMAINT2_NS */
    DMAC_DMAINT3_NS_IRQn     = 115,     /* IRQ No:115, DMAINT3_NS */
    DMAC_DMAINT4_NS_IRQn     = 116,     /* IRQ No:116, DMAINT4_NS */
    DMAC_DMAINT5_NS_IRQn     = 117,     /* IRQ No:117, DMAINT5_NS */
    DMAC_DMAINT6_NS_IRQn     = 118,     /* IRQ No:118, DMAINT6_NS */
    DMAC_DMAINT7_NS_IRQn     = 119,     /* IRQ No:119, DMAINT7_NS */
    DMAC_DMAINT8_NS_IRQn     = 120,     /* IRQ No:120, DMAINT8_NS */
    DMAC_DMAINT9_NS_IRQn     = 121,     /* IRQ No:121, DMAINT9_NS */
    DMAC_DMAINT10_NS_IRQn    = 122,     /* IRQ No:122, DMAINT10_NS */
    DMAC_DMAINT11_NS_IRQn    = 123,     /* IRQ No:123, DMAINT11_NS */
    DMAC_DMAINT12_NS_IRQn    = 124,     /* IRQ No:124, DMAINT12_NS */
    DMAC_DMAINT13_NS_IRQn    = 125,     /* IRQ No:125, DMAINT13_NS */
    DMAC_DMAINT14_NS_IRQn    = 126,     /* IRQ No:126, DMAINT14_NS */
    DMAC_DMAINT15_NS_IRQn    = 127,     /* IRQ No:127, DMAINT15_NS */
    GPT0_CCMPA_IRQn          = 128,     /* IRQ No:128, CCMPA0 */
    GPT0_CCMPB_IRQn          = 129,     /* IRQ No:129, CCMPB0 */
    GPT0_CMPC_IRQn           = 130,     /* IRQ No:130, CMPC0 */
    GPT0_CMPD_IRQn           = 131,     /* IRQ No:131, CMPD0 */
    GPT0_CMPE_IRQn           = 132,     /* IRQ No:132, CMPE0 */
    GPT0_CMPF_IRQn           = 133,     /* IRQ No:133, CMPF0 */
    GPT0_ADTRGA_IRQn         = 134,     /* IRQ No:134, ADTRGA0 */
    GPT0_ADTRGB_IRQn         = 135,     /* IRQ No:135, ADTRGB0 */
    GPT0_OVF_IRQn            = 136,     /* IRQ No:136, OVF0 */
    GPT0_UNF_IRQn            = 137,     /* IRQ No:137, UNF0 */
                                        /* IRQ No:138, Reserved */
                                        /* IRQ No:139, Reserved */
                                        /* IRQ No:140, Reserved */
    GPT1_CCMPA_IRQn  = 141,             /* IRQ No:141, CCMPA1 */
    GPT1_CCMPB_IRQn  = 142,             /* IRQ No:142, CCMPB1 */
    GPT1_CMPC_IRQn   = 143,             /* IRQ No:143, CMPC1 */
    GPT1_CMPD_IRQn   = 144,             /* IRQ No:144, CMPD1 */
    GPT1_CMPE_IRQn   = 145,             /* IRQ No:145, CMPE1 */
    GPT1_CMPF_IRQn   = 146,             /* IRQ No:146, CMPF1 */
    GPT1_ADTRGA_IRQn = 147,             /* IRQ No:147, ADTRGA1 */
    GPT1_ADTRGB_IRQn = 148,             /* IRQ No:148, ADTRGB1 */
    GPT1_OVF_IRQn    = 149,             /* IRQ No:149, OVF1 */
    GPT1_UNF_IRQn    = 150,             /* IRQ No:150, UNF1 */
                                        /* IRQ No:151, Reserved */
                                        /* IRQ No:152, Reserved */
                                        /* IRQ No:153, Reserved */
    GPT2_CCMPA_IRQn  = 154,             /* IRQ No:154, CCMPA2 */
    GPT2_CCMPB_IRQn  = 155,             /* IRQ No:155, CCMPB2 */
    GPT2_CMPC_IRQn   = 156,             /* IRQ No:156, CMPC2 */
    GPT2_CMPD_IRQn   = 157,             /* IRQ No:157, CMPD2 */
    GPT2_CMPE_IRQn   = 158,             /* IRQ No:158, CMPE2 */
    GPT2_CMPF_IRQn   = 159,             /* IRQ No:159, CMPF2 */
    GPT2_ADTRGA_IRQn = 160,             /* IRQ No:160, ADTRGA2 */
    GPT2_ADTRGB_IRQn = 161,             /* IRQ No:161, ADTRGB2 */
    GPT2_OVF_IRQn    = 162,             /* IRQ No:162, OVF2 */
    GPT2_UNF_IRQn    = 163,             /* IRQ No:163, UNF2 */
                                        /* IRQ No:164, Reserved */
                                        /* IRQ No:165, Reserved */
                                        /* IRQ No:166, Reserved */
    GPT3_CCMPA_IRQn  = 167,             /* IRQ No:167, CCMPA3 */
    GPT3_CCMPB_IRQn  = 168,             /* IRQ No:168, CCMPB3 */
    GPT3_CMPC_IRQn   = 169,             /* IRQ No:169, CMPC3 */
    GPT3_CMPD_IRQn   = 170,             /* IRQ No:170, CMPD3 */
    GPT3_CMPE_IRQn   = 171,             /* IRQ No:171, CMPE3 */
    GPT3_CMPF_IRQn   = 172,             /* IRQ No:172, CMPF3 */
    GPT3_ADTRGA_IRQn = 173,             /* IRQ No:173, ADTRGA3 */
    GPT3_ADTRGB_IRQn = 174,             /* IRQ No:174, ADTRGB3 */
    GPT3_OVF_IRQn    = 175,             /* IRQ No:175, OVF3 */
    GPT3_UNF_IRQn    = 176,             /* IRQ No:176, UNF3 */
                                        /* IRQ No:177, Reserved */
                                        /* IRQ No:178, Reserved */
                                        /* IRQ No:179, Reserved */
    GPT4_CCMPA_IRQn  = 180,             /* IRQ No:180, CCMPA4 */
    GPT4_CCMPB_IRQn  = 181,             /* IRQ No:181, CCMPB4 */
    GPT4_CMPC_IRQn   = 182,             /* IRQ No:182, CMPC4 */
    GPT4_CMPD_IRQn   = 183,             /* IRQ No:183, CMPD4 */
    GPT4_CMPE_IRQn   = 184,             /* IRQ No:184, CMPE4 */
    GPT4_CMPF_IRQn   = 185,             /* IRQ No:185, CMPF4 */
    GPT4_ADTRGA_IRQn = 186,             /* IRQ No:186, ADTRGA4 */
    GPT4_ADTRGB_IRQn = 187,             /* IRQ No:187, ADTRGB4 */
    GPT4_OVF_IRQn    = 188,             /* IRQ No:188, OVF4 */
    GPT4_UNF_IRQn    = 189,             /* IRQ No:189, UNF4 */
                                        /* IRQ No:190, Reserved */
                                        /* IRQ No:191, Reserved */
                                        /* IRQ No:192, Reserved */
    GPT5_CCMPA_IRQn  = 193,             /* IRQ No:193, CCMPA5 */
    GPT5_CCMPB_IRQn  = 194,             /* IRQ No:194, CCMPB5 */
    GPT5_CMPC_IRQn   = 195,             /* IRQ No:195, CMPC5 */
    GPT5_CMPD_IRQn   = 196,             /* IRQ No:196, CMPD5 */
    GPT5_CMPE_IRQn   = 197,             /* IRQ No:197, CMPE5 */
    GPT5_CMPF_IRQn   = 198,             /* IRQ No:198, CMPF5 */
    GPT5_ADTRGA_IRQn = 199,             /* IRQ No:199, ADTRGA5 */
    GPT5_ADTRGB_IRQn = 200,             /* IRQ No:200, ADTRGB5 */
    GPT5_OVF_IRQn    = 201,             /* IRQ No:201, OVF5 */
    GPT5_UNF_IRQn    = 202,             /* IRQ No:202, UNF5 */
                                        /* IRQ No:203, Reserved */
                                        /* IRQ No:204, Reserved */
                                        /* IRQ No:205, Reserved */
    GPT6_CCMPA_IRQn  = 206,             /* IRQ No:206, CCMPA6 */
    GPT6_CCMPB_IRQn  = 207,             /* IRQ No:207, CCMPB6 */
    GPT6_CMPC_IRQn   = 208,             /* IRQ No:208, CMPC6 */
    GPT6_CMPD_IRQn   = 209,             /* IRQ No:209, CMPD6 */
    GPT6_CMPE_IRQn   = 210,             /* IRQ No:210, CMPE6 */
    GPT6_CMPF_IRQn   = 211,             /* IRQ No:211, CMPF6 */
    GPT6_ADTRGA_IRQn = 212,             /* IRQ No:212, ADTRGA6 */
    GPT6_ADTRGB_IRQn = 213,             /* IRQ No:213, ADTRGB6 */
    GPT6_OVF_IRQn    = 214,             /* IRQ No:214, OVF6 */
    GPT6_UNF_IRQn    = 215,             /* IRQ No:215, UNF6 */
                                        /* IRQ No:216, Reserved */
                                        /* IRQ No:217, Reserved */
                                        /* IRQ No:218, Reserved */
    GPT7_CCMPA_IRQn  = 219,             /* IRQ No:219, CCMPA7 */
    GPT7_CCMPB_IRQn  = 220,             /* IRQ No:220, CCMPB7 */
    GPT7_CMPC_IRQn   = 221,             /* IRQ No:221, CMPC7 */
    GPT7_CMPD_IRQn   = 222,             /* IRQ No:222, CMPD7 */
    GPT7_CMPE_IRQn   = 223,             /* IRQ No:223, CMPE7 */
    GPT7_CMPF_IRQn   = 226,             /* IRQ No:226, CMPF7 */
    GPT7_ADTRGA_IRQn = 225,             /* IRQ No:225, ADTRGA7 */
    GPT7_ADTRGB_IRQn = 226,             /* IRQ No:226, ADTRGB7 */
    GPT7_OVF_IRQn    = 227,             /* IRQ No:227, OVF7 */
    GPT7_UNF_IRQn    = 228,             /* IRQ No:228, UNF7 */
                                        /* IRQ No:229, Reserved */
                                        /* IRQ No:230, Reserved */
                                        /* IRQ No:231, Reserved */
    POE3_OEI1_IRQn    = 232,            /* IRQ No:232, OEI1 */
    POE3_OEI2_IRQn    = 233,            /* IRQ No:233, OEI2 */
    POE3_OEI3_IRQn    = 234,            /* IRQ No:234, OEI3 */
    POE3_OEI4_IRQn    = 235,            /* IRQ No:235, OEI4 */
    POEG_GROUP0_IRQn  = 236,            /* IRQ No:236, POEGA_GROUP0 */
    POEG_GROUP1_IRQn  = 237,            /* IRQ No:237, POEGB_GROUP1 */
    POEG_GROUP2_IRQn  = 238,            /* IRQ No:238, POEGC_GROUP2 */
    POEG_GROUP3_IRQn  = 239,            /* IRQ No:239, POEGD_GROUP3 */
    I2S0_INT_REQ_IRQn = 240,            /* IRQ No:240, INT_ssif_int_req_0 */
    I2S0_DMA_RX_IRQn  = 241,            /* IRQ No:241, INT_ssif_dma_rx_0 */
    I2S0_DMA_TX_IRQn  = 242,            /* IRQ No:242, INT_ssif_dma_tx_0 */
    I2S1_INT_REQ_IRQn = 243,            /* IRQ No:243, INT_ssif_int_req_1 */
    I2S1_DMA_RX_IRQn  = 244,            /* IRQ No:244, INT_ssif_dma_rx_1 */
    I2S1_DMA_TX_IRQn  = 245,            /* IRQ No:245, INT_ssif_dma_tx_1 */
    I2S2_INT_REQ_IRQn = 246,            /* IRQ No:246, INT_ssif_int_req_2 */
    I2S2_DMA_RX_IRQn  = 247,            /* IRQ No:247, INT_ssif_dma_rx_1 */
    I2S2_DMA_TX_IRQn  = 248,            /* IRQ No:248, INT_ssif_dma_tx_1 */
    I2S3_INT_REQ_IRQn = 249,            /* IRQ No:249, INT_ssif_int_req_3 */
    I2S3_DMA_RX_IRQn  = 250,            /* IRQ No:250, INT_ssif_dma_rx_3 */
    I2S3_DMA_TX_IRQn  = 251,            /* IRQ No:251, INT_ssif_dma_tx_3 */
    SRC_IDEI_IRQn     = 252,            /* IRQ No:252, SRC_IDEI */
    SRC_ODFI_IRQn     = 253,            /* IRQ No:253, SRC_ODFI */
    SRC_CEF_IRQn      = 254,            /* IRQ No:254, SRC_CEF */
    SRC_UDF_IRQn      = 255,            /* IRQ No:255, SRC_UDF */
    SRC_OVF_IRQn      = 256,            /* IRQ No:256, SRC_OVF */
    RIIC0_TEI_IRQn    = 257,            /* IRQ No:257, INTRIICTEI0 */
    RIIC0_NAKI_IRQn   = 258,            /* IRQ No:258, INTRIICNAKI0 */
    RIIC0_SPI_IRQn    = 259,            /* IRQ No:259, INTRIICSPI0 */
    RIIC0_STI_IRQn    = 260,            /* IRQ No:260, INTRIICSTI0 */
    RIIC0_ALI_IRQn    = 261,            /* IRQ No:261, INTRIICALI0 */
    RIIC0_TMOI_IRQn   = 262,            /* IRQ No:262, INTRIICTMOI0 */
    RIIC0_RI_IRQn     = 263,            /* IRQ No:263, INTRIICRI0 */
    RIIC0_TI_IRQn     = 264,            /* IRQ No:264, INTRIICTI0 */
    RIIC1_TEI_IRQn    = 265,            /* IRQ No:265, INTRIICTEI0 */
    RIIC1_NAKI_IRQn   = 266,            /* IRQ No:266, INTRIICNAKI0 */
    RIIC1_SPI_IRQn    = 267,            /* IRQ No:267, INTRIICSPI0 */
    RIIC1_STI_IRQn    = 268,            /* IRQ No:268, INTRIICSTI0 */
    RIIC1_ALI_IRQn    = 269,            /* IRQ No:269, INTRIICALI0 */
    RIIC1_TMOI_IRQn   = 270,            /* IRQ No:270, INTRIICTMOI0 */
    RIIC1_RI_IRQn     = 271,            /* IRQ No:271, INTRIICRI0 */
    RIIC1_TI_IRQn     = 272,            /* IRQ No:272, INTRIICTI0 */
    RIIC2_TEI_IRQn    = 273,            /* IRQ No:273, INTRIICTEI0 */
    RIIC2_NAKI_IRQn   = 274,            /* IRQ No:274, INTRIICNAKI0 */
    RIIC2_SPI_IRQn    = 275,            /* IRQ No:275, INTRIICSPI0 */
    RIIC2_STI_IRQn    = 276,            /* IRQ No:276, INTRIICSTI0 */
    RIIC2_ALI_IRQn    = 277,            /* IRQ No:277, INTRIICALI0 */
    RIIC2_TMOI_IRQn   = 278,            /* IRQ No:278, INTRIICTMOI0 */
    RIIC2_RI_IRQn     = 279,            /* IRQ No:279, INTRIICRI0 */
    RIIC2_TI_IRQn     = 280,            /* IRQ No:280, INTRIICTI0 */
    RIIC3_TEI_IRQn    = 281,            /* IRQ No:281, INTRIICTEI0 */
    RIIC3_NAKI_IRQn   = 282,            /* IRQ No:282, INTRIICNAKI0 */
    RIIC3_SPI_IRQn    = 283,            /* IRQ No:283, INTRIICSPI0 */
    RIIC3_STI_IRQn    = 284,            /* IRQ No:284, INTRIICSTI0 */
    RIIC3_ALI_IRQn    = 285,            /* IRQ No:285, INTRIICALI0 */
    RIIC3_TMOI_IRQn   = 286,            /* IRQ No:286, INTRIICTMOI0 */
    RIIC3_RI_IRQn     = 287,            /* IRQ No:287, INTRIICRI0 */
    RIIC3_TI_IRQn     = 288,            /* IRQ No:288, INTRIICTI0 */
    RI3C_IERR_IRQn    = 289,            /* IRQ No:289, INT_ri3c_ierr_n */
    RI3C_TERR_IRQn    = 290,            /* IRQ No:290, INT_ri3c_terr_n */
                                        /* IRQ No:291, Reserved */
                                        /* IRQ No:292, Reserved */
    RI3C_ABORT_IRQn = 293,              /* IRQ No:293, INT_ri3c_abort_n */
    RI3C_RESP_IRQn  = 294,              /* IRQ No:294, INT_ri3c_resp_n */
    RI3C_CMD_IRQn   = 295,              /* IRQ No:295, INT_ri3c_cmd_n */
    RI3C_IBI_IRQn   = 296,              /* IRQ No:296, INT_ri3c_ibi_n */
    RI3C_RX_IRQn    = 297,              /* IRQ No:297, INT_ri3c_rx_n */
    RI3C_TX_IRQn    = 298,              /* IRQ No:298, INT_ri3c_tx_n */
    RI3C_RCV_IRQn   = 299,              /* IRQ No:299, INT_ri3c_rcv_n */
                                        /* IRQ No:300, Reserved */
                                        /* IRQ No:301, Reserved */
                                        /* IRQ No:302, Reserved */
                                        /* IRQ No:303, Reserved */
    RI3C_ST_IRQn   = 304,               /* IRQ No:304, INT_ri3c_st_n */
    RI3C_SP_IRQn   = 305,               /* IRQ No:305, INT_ri3c_sp_n */
    RI3C_EXIT_IRQn = 306,               /* IRQ No:306, INT_ri3c_exit_n */
    RI3C_TEND_IRQn = 307,               /* IRQ No:307, INT_ri3c_tend_n */
    RI3C_NACK_IRQn = 308,               /* IRQ No:308, INT_ri3c_nack_n */
    RI3C_AL_IRQn   = 309,               /* IRQ No:309, INT_ri3c_al_n */
    RI3C_TMO_IRQn  = 310,               /* IRQ No:310, INT_ri3c_tmo_n */
    RI3C_WU_IRQn   = 311,               /* IRQ No:311, INT_ri3c_wu_n */
    ADC_INTAD_IRQn = 312,               /* IRQ No:312, INTAD */
                                        /* IRQ No:313, Reserved */
                                        /* IRQ No:314, Reserved */
    RTC_ALM_IRQn = 315,                 /* IRQ No:315, INT_intreq_rtc_alm_n */
    RTC_PRD_IRQn = 316,                 /* IRQ No:316, INT_intreq_rtc_prd_n */
    RTC_CUP_IRQn = 317,                 /* IRQ No:317, INT_intreq_rtc_cup_n */
                                        /* IRQ No:318, Reserved */
                                        /* IRQ No:319, Reserved */
    SCIF0_RERR_IRQn         = 320,      /* IRQ No:320, ERI0 */
    SCIF0_BRK_IRQn          = 321,      /* IRQ No:321, BRI0 */
    SCIF0_RXI_IRQn          = 322,      /* IRQ No:322, RXI0 */
    SCIF0_TXI_IRQn          = 323,      /* IRQ No:323, TXI0 */
    SCIF0_TEI_DRI_IRQn      = 324,      /* IRQ No:324, TEI0_DRI0 */
    SCIF1_RERR_IRQn         = 325,      /* IRQ No:325, ERI1 */
    SCIF1_BRK_IRQn          = 326,      /* IRQ No:326, BRI1 */
    SCIF1_RXI_IRQn          = 327,      /* IRQ No:327, RXI1 */
    SCIF1_TXI_IRQn          = 328,      /* IRQ No:328, TXI1 */
    SCIF1_TEI_DRI_IRQn      = 329,      /* IRQ No:329, TEI1_DRI1 */
    SCIF2_RERR_IRQn         = 330,      /* IRQ No:330, ERI2 */
    SCIF2_BRK_IRQn          = 331,      /* IRQ No:331, BRI2 */
    SCIF2_RXI_IRQn          = 332,      /* IRQ No:332, RXI2 */
    SCIF2_TXI_IRQn          = 333,      /* IRQ No:333, TXI2 */
    SCIF2_TEI_DRI_IRQn      = 334,      /* IRQ No:334, TEI2_DRI2 */
    SCIF3_RERR_IRQn         = 335,      /* IRQ No:335, ERI3 */
    SCIF3_BRK_IRQn          = 336,      /* IRQ No:336, BRI3 */
    SCIF3_RXI_IRQn          = 337,      /* IRQ No:337, RXI3 */
    SCIF3_TXI_IRQn          = 338,      /* IRQ No:338, TXI3 */
    SCIF3_TEI_DRI_IRQn      = 339,      /* IRQ No:339, TEI3_DRI3 */
    SCIF4_RERR_IRQn         = 340,      /* IRQ No:340, ERI4 */
    SCIF4_BRK_IRQn          = 341,      /* IRQ No:341, BRI4 */
    SCIF4_RXI_IRQn          = 342,      /* IRQ No:342, RXI4 */
    SCIF4_TXI_IRQn          = 343,      /* IRQ No:343, TXI4 */
    SCIF4_TEI_DRI_IRQn      = 344,      /* IRQ No:344, TEI4_DRI4 */
    SCIF5_RERR_IRQn         = 345,      /* IRQ No:345, ERI5 */
    SCIF5_BRK_IRQn          = 346,      /* IRQ No:346, BRI5 */
    SCIF5_RXI_IRQn          = 347,      /* IRQ No:347, RXI5 */
    SCIF5_TXI_IRQn          = 348,      /* IRQ No:348, TXI5 */
    SCIF5_TEI_DRI_IRQn      = 349,      /* IRQ No:349, TEI5_DRI5 */
    SCI0_ERI_IRQn           = 350,      /* IRQ No:350, ERI0 */
    SCI0_RXI_IRQn           = 351,      /* IRQ No:351, RXI0 */
    SCI0_TXI_IRQn           = 352,      /* IRQ No:352, TXI0 */
    SCI0_TEI_IRQn           = 353,      /* IRQ No:353, TEI0 */
    SCI1_ERI_IRQn           = 354,      /* IRQ No:354, ERI1 */
    SCI1_RXI_IRQn           = 355,      /* IRQ No:355, RXI1 */
    SCI1_TXI_IRQn           = 356,      /* IRQ No:356, TXI1 */
    SCI1_TEI_IRQn           = 357,      /* IRQ No:357, TEI1 */
    RSPI0_ERR_IRQn          = 358,      /* IRQ No:358, SPEI0 */
    RSPI0_RX_IRQn           = 359,      /* IRQ No:359, SPRI0 */
    RSPI0_TX_IRQn           = 360,      /* IRQ No:360, SPTI0 */
    RSPI1_ERR_IRQn          = 361,      /* IRQ No:361, SPEI1 */
    RSPI1_RX_IRQn           = 362,      /* IRQ No:362, SPRI1 */
    RSPI1_TX_IRQn           = 363,      /* IRQ No:363, SPTI1 */
    RSPI2_ERR_IRQn          = 364,      /* IRQ No:364, SPEI2 */
    RSPI2_RX_IRQn           = 365,      /* IRQ No:365, SPRI2 */
    RSPI2_TX_IRQn           = 366,      /* IRQ No:366, SPTI2 */
    RSPI3_ERR_IRQn          = 367,      /* IRQ No:367, SPEI3 */
    RSPI3_RX_IRQn           = 368,      /* IRQ No:368, SPRI3 */
    RSPI3_TX_IRQn           = 369,      /* IRQ No:369, SPTI3 */
    RSPI4_ERR_IRQn          = 370,      /* IRQ No:370, SPEI4 */
    RSPI4_RX_IRQn           = 371,      /* IRQ No:371, SPRI4 */
    RSPI4_TX_IRQn           = 372,      /* IRQ No:372, SPTI4 */
    CANFD_INTRCANGERR_IRQn  = 373,      /* IRQ No:373, INTRCANGERR */
    CANFD_INTRCANGRECC_IRQn = 374,      /* IRQ No:374, INTRCANGRECC */
    CANFD_INTRCAN0REC_IRQn  = 375,      /* IRQ No:375, INTRCAN0REC */
    CANFD_INTRCAN1REC_IRQn  = 376,      /* IRQ No:376, INTRCAN1REC */
    CANFD_INTRCAN0ERR_IRQn  = 377,      /* IRQ No:377, INTRCAN0ERR */
    CANFD_INTRCAN1ERR_IRQn  = 378,      /* IRQ No:378, INTRCAN1ERR */
    CANFD_INTRCAN0TRX_IRQn  = 379,      /* IRQ No:379, INTRCAN0TRX */
    CANFD_INTRCAN1TRX_IRQn  = 380,      /* IRQ No:380, INTRCAN1TRX */
                                        /* IRQ No:381, Reserved */
                                        /* IRQ No:382, Reserved */
                                        /* IRQ No:383, Reserved */
                                        /* IRQ No:384, Reserved */
                                        /* IRQ No:385, Reserved */
                                        /* IRQ No:386, Reserved */
    SPDIF_SPDIF_IRQn             = 387, /* IRQ No:387, intreq_spdif */
    PDM_ERR0_IRQn                = 388, /* IRQ No:388, INT_PDM_ERR0 */
    PDM_ERR1_IRQn                = 389, /* IRQ No:389, INT_PDM_ERR1 */
    PDM_ERR2_IRQn                = 390, /* IRQ No:390, INT_PDM_ERR2 */
    PDM_DAT0_IRQn                = 391, /* IRQ No:391, INT_PDM_DAT0 */
    PDM_DAT1_IRQn                = 392, /* IRQ No:392, INT_PDM_DAT1 */
    PDM_DAT2_IRQn                = 393, /* IRQ No:393, INT_PDM_DAT2 */
    PDM_SDET_IRQn                = 394, /* IRQ No:394, INT_PDM_SDET */
    PCIE_INT_SERR_IRQn           = 395, /* IRQ No:395, INT_SERR */
    PCIE_INT_SERR_COR_IRQn       = 396, /* IRQ No:396, INT_SERR_COR */
    PCIE_INT_SERR_NONFATAL_IRQn  = 397, /* IRQ No:397, INT_SERR_NONFATAL */
    PCIE_INT_SERR_FATAL_IRQn     = 398, /* IRQ No:398, INT_SERR_FATAL */
    PCIE_AXI_ERR_INTIRQn         = 399, /* IRQ No:399, AXI_ERR_INT */
    PCIE_INTA_RC_IRQn            = 400, /* IRQ No:400, INTA_RC */
    PCIE_INTB_RC_IRQn            = 401, /* IRQ No:401, INTB_RC */
    PCIE_INTC_RC_IRQn            = 402, /* IRQ No:402, INTC_RC */
    PCIE_INTD_RC_IRQn            = 403, /* IRQ No:403, INTD_RC */
    PCIE_INTMSI_RC_IRQn          = 404, /* IRQ No:404, INTMSI_RC */
    PCIE_INT_LINK_BANDWIDTH_IRQn = 405, /* IRQ No:405, INT_LINK_BANDWIDTH */
    PCIE_INT_PM_PME_IRQn         = 406, /* IRQ No:406, INT_PM_PME */
    PCIE_DMA_INT_IRQn            = 407, /* IRQ No:407, DMA_IN */
    PCIE_PCIE_EVT_INT_IRQn       = 408, /* IRQ No:408, PCIE_EVT_IN */
    PCIE_MSG_INT_IRQn            = 409, /* IRQ No:409, MSG_INT */
    PCIE_INT_ALL_IRQn            = 410, /* IRQ No:410, INT_ALL */
                                        /* IRQ No:411, Reserved */
                                        /* IRQ No:412, Reserved */
                                        /* IRQ No:413, Reserved */
                                        /* IRQ No:414, Reserved */
                                        /* IRQ No:415, Reserved */
                                        /* IRQ No:416, Reserved */
                                        /* IRQ No:417, Reserved */
                                        /* IRQ No:418, Reserved */
                                        /* IRQ No:419, Reserved */
                                        /* IRQ No:420, Reserved */
                                        /* IRQ No:421, Reserved */
                                        /* IRQ No:422, Reserved */
                                        /* IRQ No:423, Reserved */
                                        /* IRQ No:424, Reserved */
                                        /* IRQ No:425, Reserved */
                                        /* IRQ No:426, Reserved */
                                        /* IRQ No:427, Reserved */
                                        /* IRQ No:428, Reserved */
    GPIO_TINT0_IRQn  = 429,             /* IRQ No:429, TINT0 */
    GPIO_TINT1_IRQn  = 430,             /* IRQ No:430, TINT1 */
    GPIO_TINT2_IRQn  = 431,             /* IRQ No:431, TINT2 */
    GPIO_TINT3_IRQn  = 432,             /* IRQ No:432, TINT3 */
    GPIO_TINT4_IRQn  = 433,             /* IRQ No:433, TINT4 */
    GPIO_TINT5_IRQn  = 434,             /* IRQ No:434, TINT5 */
    GPIO_TINT6_IRQn  = 435,             /* IRQ No:435, TINT6 */
    GPIO_TINT7_IRQn  = 436,             /* IRQ No:436, TINT7 */
    GPIO_TINT8_IRQn  = 437,             /* IRQ No:437, TINT8 */
    GPIO_TINT9_IRQn  = 438,             /* IRQ No:438, TINT9 */
    GPIO_TINT10_IRQn = 439,             /* IRQ No:439, TINT10 */
    GPIO_TINT11_IRQn = 440,             /* IRQ No:440, TINT11 */
    GPIO_TINT12_IRQn = 441,             /* IRQ No:441, TINT12 */
    GPIO_TINT13_IRQn = 442,             /* IRQ No:442, TINT13 */
    GPIO_TINT14_IRQn = 443,             /* IRQ No:443, TINT14 */
    GPIO_TINT15_IRQn = 444,             /* IRQ No:444, TINT15 */
    GPIO_TINT16_IRQn = 445,             /* IRQ No:445, TINT16 */
    GPIO_TINT17_IRQn = 446,             /* IRQ No:446, TINT17 */
    GPIO_TINT18_IRQn = 447,             /* IRQ No:447, TINT18 */
    GPIO_TINT19_IRQn = 448,             /* IRQ No:448, TINT19 */
    GPIO_TINT20_IRQn = 449,             /* IRQ No:449, TINT20 */
    GPIO_TINT21_IRQn = 450,             /* IRQ No:450, TINT21 */
    GPIO_TINT22_IRQn = 451,             /* IRQ No:451, TINT22 */
    GPIO_TINT23_IRQn = 452,             /* IRQ No:452, TINT23 */
    GPIO_TINT24_IRQn = 453,             /* IRQ No:453, TINT24 */
    GPIO_TINT25_IRQn = 454,             /* IRQ No:454, TINT25 */
    GPIO_TINT26_IRQn = 455,             /* IRQ No:455, TINT26 */
    GPIO_TINT27_IRQn = 456,             /* IRQ No:456, TINT27 */
    GPIO_TINT28_IRQn = 457,             /* IRQ No:457, TINT28 */
    GPIO_TINT29_IRQn = 458,             /* IRQ No:458, TINT29 */
    GPIO_TINT30_IRQn = 459,             /* IRQ No:459, TINT30 */
    GPIO_TINT31_IRQn = 460,             /* IRQ No:460, TINT31 */
                                        /* IRQ No:461, Reserved */
                                        /* IRQ No:462, Reserved */
                                        /* IRQ No:463, Reserved */
                                        /* IRQ No:464, Reserved */
                                        /* IRQ No:465, Reserved */
                                        /* IRQ No:466, Reserved */
                                        /* IRQ No:467, Reserved */
                                        /* IRQ No:468, Reserved */
                                        /* IRQ No:469, Reserved */
                                        /* IRQ No:470, Reserved */
                                        /* IRQ No:471, Reserved */
                                        /* IRQ No:472, Reserved */
                                        /* IRQ No:473, Reserved */
                                        /* IRQ No:474, Reserved */
                                        /* IRQ No:475, Reserved */
                                        /* IRQ No:476, Reserved */
                                        /* IRQ No:477, Reserved */
                                        /* IRQ No:478, Reserved */
                                        /* IRQ No:479, Reserved */
} IRQn_Type;

/** @} (end addtogroup BSP_MPU_RZG2UL) */

#endif                                 /* BSP_IRQ_ID_H */
