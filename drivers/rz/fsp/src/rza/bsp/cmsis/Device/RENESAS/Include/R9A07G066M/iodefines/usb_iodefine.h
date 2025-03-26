/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : usb_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for usb.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef USB_IODEFINE_H
#define USB_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t RESET;
        struct
        {
            __IOM uint32_t phyrst_1     : 1;
            uint32_t                    : 3;
            __IOM uint32_t sel_p1reset  : 1;
            uint32_t                    : 3;
            __IOM uint32_t pllreset     : 1;
            uint32_t                    : 3;
            __IOM uint32_t sel_pllreset : 1;
            uint32_t                    : 19;
        } RESET_b;
    };
    __IM uint8_t RESERVED[20];
    union
    {
        __IOM uint32_t UCLKCTL;
        struct
        {
            uint32_t                    : 8;
            __IOM uint32_t suspend_1    : 1;
            uint32_t                    : 3;
            __IOM uint32_t sel_suspendm : 1;
            uint32_t                    : 11;
            __IOM uint32_t sleepm_1     : 1;
            uint32_t                    : 3;
            __IOM uint32_t sel_sleepm   : 1;
            uint32_t                    : 3;
        } UCLKCTL_b;
    };
    union
    {
        __IOM uint32_t UDIRPD;
        struct
        {
            __IOM uint32_t dirpd      : 1;
            uint32_t                  : 3;
            __IOM uint32_t sel_udirpd : 1;
            uint32_t                  : 27;
        } UDIRPD_b;
    };
    union
    {
        __IOM uint32_t CON_CTRL;
        struct
        {
            __IOM uint32_t connect_1   : 1;
            uint32_t                   : 3;
            __IOM uint32_t sel_connect : 1;
            uint32_t                   : 27;
        } CON_CTRL_b;
    };
    __IM uint8_t RESERVED1[224];
    union
    {
        __IM uint32_t CLK_STAT;
        struct
        {
            __IM uint32_t plllock_1    : 1;
            uint32_t                   : 3;
            __IM uint32_t phylock      : 1;
            __IM uint32_t frclk48_lock : 1;
            __IM uint32_t frclk60_lock : 1;
            uint32_t                   : 25;
        } CLK_STAT_b;
    };
} R_USB_Type;

typedef struct
{
    union
    {
        __IM uint32_t HCREVISION;
        struct
        {
            __IM uint32_t RevisionA : 8;
            uint32_t                : 24;
        } HCREVISION_b;
    };
    union
    {
        __IOM uint32_t HCCONTROL;
        struct
        {
            __IOM uint32_t CBSR : 2;
            __IOM uint32_t PLE  : 1;
            __IOM uint32_t IE   : 1;
            __IOM uint32_t CLE  : 1;
            __IOM uint32_t BLE  : 1;
            __IOM uint32_t HCFS : 2;
            uint32_t            : 1;
            __IOM uint32_t RWC  : 1;
            uint32_t            : 22;
        } HCCONTROL_b;
    };
    union
    {
        __IOM uint32_t HCCOMMANDSTATUS;
        struct
        {
            __IOM uint32_t HCR : 1;
            __IOM uint32_t CLF : 1;
            __IOM uint32_t BLF : 1;
            uint32_t           : 13;
            __IM uint32_t SOC  : 2;
            uint32_t           : 14;
        } HCCOMMANDSTATUS_b;
    };
    union
    {
        __IOM uint32_t HCINTERRUPTSTATUS;
        struct
        {
            __IOM uint32_t SO   : 1;
            __IOM uint32_t WDH  : 1;
            __IOM uint32_t SF   : 1;
            __IOM uint32_t RD   : 1;
            __IOM uint32_t UE   : 1;
            __IOM uint32_t FNO  : 1;
            __IOM uint32_t RHSC : 1;
            uint32_t            : 25;
        } HCINTERRUPTSTATUS_b;
    };
    union
    {
        __IOM uint32_t HCINTERRUPTENABLE;
        struct
        {
            __IOM uint32_t SOE   : 1;
            __IOM uint32_t WDHE  : 1;
            __IOM uint32_t SFE   : 1;
            __IOM uint32_t RDE   : 1;
            __IOM uint32_t UEE   : 1;
            __IOM uint32_t FNOE  : 1;
            __IOM uint32_t RHSCE : 1;
            uint32_t             : 23;
            __IOM uint32_t OCE   : 1;
            __IOM uint32_t MIE   : 1;
        } HCINTERRUPTENABLE_b;
    };
    union
    {
        __IOM uint32_t HCINTERRUPTDISABLE;
        struct
        {
            __IOM uint32_t SOD   : 1;
            __IOM uint32_t WDHD  : 1;
            __IOM uint32_t SFD   : 1;
            __IOM uint32_t RDD   : 1;
            __IOM uint32_t UED   : 1;
            __IOM uint32_t FNOD  : 1;
            __IOM uint32_t RHSCD : 1;
            uint32_t             : 23;
            __IOM uint32_t OCD   : 1;
            __IOM uint32_t MID   : 1;
        } HCINTERRUPTDISABLE_b;
    };
    union
    {
        __IOM uint32_t HCHCCA;
        struct
        {
            uint32_t              : 8;
            __IOM uint32_t HcHCCA : 24;
        } HCHCCA_b;
    };
    union
    {
        __IM uint32_t HCPERIODCURRENTED;
        struct
        {
            uint32_t           : 4;
            __IM uint32_t PECD : 28;
        } HCPERIODCURRENTED_b;
    };
    union
    {
        __IOM uint32_t HCCONTROLHEADED;
        struct
        {
            uint32_t            : 4;
            __IOM uint32_t CHED : 28;
        } HCCONTROLHEADED_b;
    };
    union
    {
        __IOM uint32_t HCCONTROLCURRENTED;
        struct
        {
            uint32_t            : 4;
            __IOM uint32_t CCED : 28;
        } HCCONTROLCURRENTED_b;
    };
    union
    {
        __IOM uint32_t HCBULKHEADED;
        struct
        {
            uint32_t            : 4;
            __IOM uint32_t BHED : 28;
        } HCBULKHEADED_b;
    };
    union
    {
        __IOM uint32_t HCBULKCURRENTED;
        struct
        {
            uint32_t            : 4;
            __IOM uint32_t BCED : 28;
        } HCBULKCURRENTED_b;
    };
    union
    {
        __IM uint32_t HCDONEHEAD;
        struct
        {
            uint32_t         : 4;
            __IM uint32_t DH : 28;
        } HCDONEHEAD_b;
    };
    union
    {
        __IOM uint32_t HCFMINTERVAL;
        struct
        {
            __IOM uint32_t FI    : 14;
            uint32_t             : 2;
            __IOM uint32_t FSMPS : 15;
            __IOM uint32_t FIT   : 1;
        } HCFMINTERVAL_b;
    };
    union
    {
        __IM uint32_t HCFMREMAINING;
        struct
        {
            __IM uint32_t FR  : 14;
            uint32_t          : 17;
            __IM uint32_t FRT : 1;
        } HCFMREMAINING_b;
    };
    union
    {
        __IM uint32_t HCFMNUMBER;
        struct
        {
            __IM uint32_t FN : 16;
            uint32_t         : 16;
        } HCFMNUMBER_b;
    };
    union
    {
        __IOM uint32_t HCPERIODICSTART;
        struct
        {
            __IOM uint32_t PS : 14;
            uint32_t          : 18;
        } HCPERIODICSTART_b;
    };
    union
    {
        __IOM uint32_t HCLSTHRESHOLD;
        struct
        {
            __IOM uint32_t LST : 12;
            uint32_t           : 20;
        } HCLSTHRESHOLD_b;
    };
    union
    {
        __IOM uint32_t HCRHDESCRIPTORA;
        struct
        {
            __IOM uint32_t NDP    : 8;
            __IOM uint32_t PSM    : 1;
            __IOM uint32_t NPS    : 1;
            __IOM uint32_t DT     : 1;
            __IOM uint32_t OCPM   : 1;
            __IOM uint32_t NOCP   : 1;
            uint32_t              : 11;
            __IOM uint32_t POTPGT : 8;
        } HCRHDESCRIPTORA_b;
    };
    union
    {
        __IOM uint32_t HCRHDESCRIPTORB;
        struct
        {
            uint32_t            : 1;
            __IOM uint32_t DR   : 1;
            uint32_t            : 15;
            __IOM uint32_t PPCM : 1;
            uint32_t            : 14;
        } HCRHDESCRIPTORB_b;
    };
    union
    {
        __IOM uint32_t HCRHSTATUS;
        struct
        {
            __IOM uint32_t LPS  : 1;
            __IOM uint32_t OCI  : 1;
            uint32_t            : 13;
            __IOM uint32_t DRWE : 1;
            __IOM uint32_t LPSC : 1;
            __IOM uint32_t OCIC : 1;
            uint32_t            : 13;
            __IOM uint32_t CRWE : 1;
        } HCRHSTATUS_b;
    };
    union
    {
        __IOM uint32_t HCRHPORTSTATUS1;
        struct
        {
            __IOM uint32_t CCS  : 1;
            __IOM uint32_t PES  : 1;
            __IOM uint32_t PSS  : 1;
            __IOM uint32_t POCI : 1;
            __IOM uint32_t PRS  : 1;
            uint32_t            : 3;
            __IOM uint32_t PPS  : 1;
            __IOM uint32_t LSDA : 1;
            uint32_t            : 6;
            __IOM uint32_t CSC  : 1;
            __IOM uint32_t PESC : 1;
            __IOM uint32_t PSSC : 1;
            __IOM uint32_t OCIC : 1;
            __IOM uint32_t PRSC : 1;
            uint32_t            : 11;
        } HCRHPORTSTATUS1_b;
    };
    __IM uint8_t RESERVED[168];
    union
    {
        __IM uint32_t CAPL_VERSION;
        struct
        {
            __IM uint32_t CapabilityRegistersLength : 8;
            uint32_t                                : 8;
            __IM uint32_t InterfaceVersionNumber    : 16;
        } CAPL_VERSION_b;
    };
    union
    {
        __IM uint32_t HCSPARAMS;
        struct
        {
            __IM uint32_t N_PORTS          : 4;
            __IM uint32_t PPC              : 1;
            uint32_t                       : 2;
            __IM uint32_t PortRoutingRules : 1;
            __IM uint32_t N_PCC            : 4;
            __IM uint32_t N_CC             : 4;
            __IM uint32_t P_INDICATOR      : 1;
            uint32_t                       : 3;
            __IM uint32_t DebugPortNumber  : 4;
            uint32_t                       : 8;
        } HCSPARAMS_b;
    };
    union
    {
        __IM uint32_t HCCPARAMS;
        struct
        {
            __IM uint32_t AddressingCapability               : 1;
            __IM uint32_t ProgramableFrameListFlag           : 1;
            __IM uint32_t AsynchronousScheduleParkCapability : 1;
            uint32_t                                         : 1;
            __IM uint32_t IsochronousSchedulingThreshold     : 4;
            __IM uint32_t EECP                               : 8;
            __IM uint32_t HardwarePrefetch                   : 1;
            __IM uint32_t LinkPowerManagementCapability      : 1;
            __IM uint32_t PerPortChangeEventCapability       : 1;
            __IM uint32_t FramePeriodicListCapability        : 1;
            uint32_t                                         : 12;
        } HCCPARAMS_b;
    };
    union
    {
        __IM uint32_t HCSP_PORTROUTE;
        struct
        {
            __IM uint32_t CompanionPortRoute : 32;
        } HCSP_PORTROUTE_b;
    };
    __IM uint8_t RESERVED1[16];
    union
    {
        __IOM uint32_t USBCMD;
        struct
        {
            __IOM uint32_t RS                                 : 1;
            __IOM uint32_t HCRESET                            : 1;
            __IOM uint32_t FrameListSize                      : 2;
            __IOM uint32_t PeriodicScheduleEnable             : 1;
            __IOM uint32_t AsynchronousScheduleEnable         : 1;
            __IOM uint32_t InterruptonAsyncAdvanceDoorbell    : 1;
            uint32_t                                          : 1;
            __IOM uint32_t AsynchronousScheduleParkModeCount  : 2;
            uint32_t                                          : 1;
            __IOM uint32_t AsynchronousScheduleParkModeEnable : 1;
            uint32_t                                          : 3;
            __IOM uint32_t PerPortChangeEventsEnable          : 1;
            __IOM uint32_t InterruptThresholdControl          : 8;
            __IOM uint32_t HostInitiatedResumeDuration        : 4;
            uint32_t                                          : 4;
        } USBCMD_b;
    };
    union
    {
        __IOM uint32_t USBSTS;
        struct
        {
            __IOM uint32_t USBINT                     : 1;
            __IOM uint32_t USBERRINT                  : 1;
            __IOM uint32_t PortChangeDetect           : 1;
            __IOM uint32_t FrameListRollover          : 1;
            __IOM uint32_t HostSystemError            : 1;
            __IM uint32_t  InterruptonAsyncAdvance    : 1;
            uint32_t                                  : 6;
            __IM uint32_t  HCHalted                   : 1;
            __IM uint32_t  Reclamation                : 1;
            __IM uint32_t  PeriodicScheduleStatus     : 1;
            __IM uint32_t  AsynchronousScheduleStatus : 1;
            __IOM uint32_t Port1ChangeDetect          : 1;
            uint32_t                                  : 15;
        } USBSTS_b;
    };
    union
    {
        __IOM uint32_t USBINTR;
        struct
        {
            __IOM uint32_t USBInterruptEnable            : 1;
            __IOM uint32_t USBErrorInterruptEnable       : 1;
            __IOM uint32_t PortChangeDetectEnable        : 1;
            __IOM uint32_t FrameListRolloverEnable       : 1;
            __IOM uint32_t HostSystemErrorEnable         : 1;
            __IOM uint32_t InterruptonAsyncAdvanceEnable : 1;
            uint32_t                                     : 10;
            __IOM uint32_t Port1ChangeEventEnable        : 1;
            uint32_t                                     : 15;
        } USBINTR_b;
    };
    union
    {
        __IOM uint32_t FRINDEX;
        struct
        {
            __IOM uint32_t FrameIndex : 14;
            uint32_t                  : 18;
        } FRINDEX_b;
    };
    union
    {
        __IM uint32_t CTRLDSSEGMENT;
        struct
        {
            __IM uint32_t CTRLDSSEGMENT : 32;
        } CTRLDSSEGMENT_b;
    };
    union
    {
        __IOM uint32_t PERIODICLISTBASE;
        struct
        {
            uint32_t                   : 12;
            __IOM uint32_t BaseAddress : 20;
        } PERIODICLISTBASE_b;
    };
    union
    {
        __IOM uint32_t ASYNCLISTADDR;
        struct
        {
            uint32_t           : 5;
            __IOM uint32_t LPL : 27;
        } ASYNCLISTADDR_b;
    };
    __IM uint8_t RESERVED2[36];
    union
    {
        __IOM uint32_t CONFIGFLAG;
        struct
        {
            __IOM uint32_t CF : 1;
            uint32_t          : 31;
        } CONFIGFLAG_b;
    };
    union
    {
        __IOM uint32_t PORTSC1;
        struct
        {
            __IM uint32_t  CurrentConnectStatus     : 1;
            __IOM uint32_t ConnectStatusChange      : 1;
            __IOM uint32_t PortEnabled_Disabled     : 1;
            __IOM uint32_t PortEnable_DisableChange : 1;
            __IM uint32_t  OvercurrentActive        : 1;
            __IOM uint32_t OvercurrentChange        : 1;
            __IOM uint32_t ForcePortResume          : 1;
            __IOM uint32_t Suspend                  : 1;
            __IOM uint32_t PortReset                : 1;
            __IOM uint32_t SuspendusingL1           : 1;
            __IM uint32_t  LineStatus               : 2;
            __IOM uint32_t PP                       : 1;
            __IOM uint32_t PortOwner                : 1;
            uint32_t                                : 2;
            __IOM uint32_t PortTestControl          : 4;
            __IOM uint32_t WKCNNT_E                 : 1;
            __IOM uint32_t WKDSCNNT_E               : 1;
            __IOM uint32_t WKOC_E                   : 1;
            __IM uint32_t  SuspendStatus            : 2;
            __IOM uint32_t DeviceAddress            : 7;
        } PORTSC1_b;
    };
    __IM uint8_t RESERVED3[152];
    union
    {
        __IOM uint32_t INT_ENABLE;
        struct
        {
            __IOM uint32_t AHB_INTEN    : 1;
            __IOM uint32_t USBH_INTAEN  : 1;
            __IOM uint32_t USBH_INTBEN  : 1;
            __IOM uint32_t UCOM_INTEN   : 1;
            __IOM uint32_t WAKEON_INTEN : 1;
            uint32_t                    : 27;
        } INT_ENABLE_b;
    };
    union
    {
        __IOM uint32_t INT_STATUS;
        struct
        {
            __IOM uint32_t AHB_INT    : 1;
            __IM uint32_t  USBH_INTA  : 1;
            __IM uint32_t  USBH_INTB  : 1;
            __IM uint32_t  UCOM_INT   : 1;
            __IOM uint32_t WAKEON_INT : 1;
            uint32_t                  : 27;
        } INT_STATUS_b;
    };
    union
    {
        __IOM uint32_t AHB_BUS_CTR;
        struct
        {
            __IOM uint32_t MAX_BURST_LEN : 2;
            uint32_t                     : 2;
            __IOM uint32_t ALIGN_ADDRESS : 2;
            uint32_t                     : 2;
            __IOM uint32_t PROT_MODE     : 1;
            uint32_t                     : 3;
            __IOM uint32_t PROT_TYPE     : 4;
            uint32_t                     : 16;
        } AHB_BUS_CTR_b;
    };
    union
    {
        __IOM uint32_t USBCTR;
        struct
        {
            __IOM uint32_t USBH_RST : 1;
            __IOM uint32_t PLL_RST  : 1;
            __IOM uint32_t DIRPD    : 1;
            uint32_t                : 29;
        } USBCTR_b;
    };
    __IM uint8_t RESERVED4[244];
    union
    {
        __IOM uint32_t REGEN_CG_CTRL;
        struct
        {
            uint32_t                      : 28;
            __IOM uint32_t PERI_CLK_MSK   : 1;
            __IOM uint32_t HOST_CLK_MSK   : 1;
            uint32_t                      : 1;
            __IOM uint32_t NONUSE_CLK_MSK : 1;
        } REGEN_CG_CTRL_b;
    };
    union
    {
        __IOM uint32_t SPD_CTRL;
        struct
        {
            __IOM uint32_t GLOBAL_SUSPENDM_P1 : 1;
            uint32_t                          : 22;
            __IOM uint32_t WKCNNT_ENABLE      : 1;
            uint32_t                          : 6;
            __IOM uint32_t SLEEPM_ENABLE      : 1;
            __IOM uint32_t SUSPENDM_ENABLE    : 1;
        } SPD_CTRL_b;
    };
    union
    {
        __IOM uint32_t SPD_RSM_TIMSET;
        struct
        {
            __IOM uint32_t TIMER_RESUME  : 16;
            __IOM uint32_t TIMER_CONNECT : 16;
        } SPD_RSM_TIMSET_b;
    };
    union
    {
        __IOM uint32_t OC_SLP_TIMSET;
        struct
        {
            __IOM uint32_t TIMER_OC    : 20;
            __IOM uint32_t TIMER_SLEEP : 9;
            uint32_t                   : 3;
        } OC_SLP_TIMSET_b;
    };
    union
    {
        __IOM uint32_t SBRN_FLADJ_PW;
        struct
        {
            __IM uint32_t  SBRN        : 8;
            __IOM uint32_t FLADJ       : 8;
            __IOM uint32_t PORTWAKECAP : 16;
        } SBRN_FLADJ_PW_b;
    };
    __IM uint8_t RESERVED5[8];
    union
    {
        __IOM uint32_t PORT_LPM_CTRL1;
        struct
        {
            __IOM uint32_t HIRD_SEL_P1          : 1;
            __IOM uint32_t RETRY_ENABLE_NYET_P1 : 1;
            __IOM uint32_t SLEEP_INT_EN_P1      : 1;
            __IOM uint32_t REMOTEWAKE_EN_P1     : 1;
            __IOM uint32_t NYET_RETRY_CNT_P1    : 4;
            uint32_t                            : 24;
        } PORT_LPM_CTRL1_b;
    };
    __IM uint8_t RESERVED6[1244];
    union
    {
        __IOM uint32_t COMMCTRL;
        struct
        {
            uint32_t                : 31;
            __IOM uint32_t OTG_PERI : 1;
        } COMMCTRL_b;
    };
    union
    {
        __IOM uint32_t OBINTSTA;
        struct
        {
            __IOM uint32_t IDCHG_STA      : 1;
            __IOM uint32_t OCINT_STA      : 1;
            uint32_t                      : 2;
            __IOM uint32_t PDDETCHG1_STA  : 1;
            uint32_t                      : 1;
            __IOM uint32_t CHGDETCHG1_STA : 1;
            uint32_t                      : 9;
            __IOM uint32_t DMMONCHG_STA   : 1;
            __IOM uint32_t DPMONCHG_STA   : 1;
            uint32_t                      : 14;
        } OBINTSTA_b;
    };
    union
    {
        __IOM uint32_t OBINTEN;
        struct
        {
            __IOM uint32_t IDCHG_EN      : 1;
            __IOM uint32_t OCINT_EN      : 1;
            uint32_t                     : 2;
            __IOM uint32_t PDDETCHG1_EN  : 1;
            uint32_t                     : 1;
            __IOM uint32_t CHGDETCHG1_EN : 1;
            uint32_t                     : 9;
            __IOM uint32_t DMMONCHG_EN   : 1;
            __IOM uint32_t DPMONCHG_EN   : 1;
            uint32_t                     : 14;
        } OBINTEN_b;
    };
    union
    {
        __IOM uint32_t VBCTRL;
        struct
        {
            __IOM uint32_t VBOUT : 1;
            uint32_t             : 3;
            __IOM uint32_t VGPUO : 1;
            uint32_t             : 27;
        } VBCTRL_b;
    };
    union
    {
        __IOM uint32_t LINECTRL1;
        struct
        {
            __IM uint32_t IDMON     : 1;
            uint32_t                : 1;
            __IM uint32_t DMMON     : 1;
            __IM uint32_t DPMON     : 1;
            uint32_t                : 12;
            __IOM uint32_t DM_RPD   : 1;
            __IOM uint32_t DMRPD_EN : 1;
            __IOM uint32_t DP_RPD   : 1;
            __IOM uint32_t DPRPD_EN : 1;
            __IOM uint32_t DP_RPU   : 1;
            __IOM uint32_t DPRPU_EN : 1;
            uint32_t                : 2;
            __IM uint32_t DPMLVL    : 2;
            uint32_t                : 6;
        } LINECTRL1_b;
    };
    __IM uint8_t RESERVED7[12];
    union
    {
        __IOM uint32_t BCCTRL1;
        struct
        {
            __IOM uint32_t IDPSRCE  : 1;
            __IOM uint32_t IDMSINKE : 1;
            __IOM uint32_t VDPSRCE  : 1;
            __IOM uint32_t IDPSINKE : 1;
            __IOM uint32_t VDMSRCE  : 1;
            __IOM uint32_t DCPMODE  : 1;
            uint32_t                : 2;
            __IM uint32_t CHGDETSTS : 1;
            __IM uint32_t PDDETSTS  : 1;
            uint32_t                : 22;
        } BCCTRL1_b;
    };
} R_USB00_Type;

typedef struct
{
    union
    {
        __IOM uint16_t SYSCFG0;
        struct
        {
            __IOM uint16_t USBE  : 1;
            uint16_t             : 3;
            __IOM uint16_t DPRPU : 1;
            __IOM uint16_t DRPD  : 1;
            uint16_t             : 1;
            __IOM uint16_t HSE   : 1;
            __IOM uint16_t CNEN  : 1;
            uint16_t             : 7;
        } SYSCFG0_b;
    };
    union
    {
        __IOM uint16_t SYSCFG1;
        struct
        {
            __IOM uint16_t BWAIT : 6;
            uint16_t             : 10;
        } SYSCFG1_b;
    };
    union
    {
        __IM uint16_t SYSSTS0;
        struct
        {
            __IM uint16_t LNST : 2;
            uint16_t           : 14;
        } SYSSTS0_b;
    };
    __IM uint8_t RESERVED[2];
    union
    {
        __IOM uint16_t DVSTCTR0;
        struct
        {
            __IM uint16_t RHST  : 3;
            uint16_t            : 5;
            __IOM uint16_t WKUP : 1;
            uint16_t            : 7;
        } DVSTCTR0_b;
    };
    __IM uint8_t RESERVED1[2];
    union
    {
        __IOM uint16_t TESTMODE;
        struct
        {
            __IOM uint16_t UTST : 4;
            uint16_t            : 12;
        } TESTMODE_b;
    };
    __IM uint8_t RESERVED2[6];
    union
    {
        __IOM uint32_t CFIFO;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } CFIFO_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } CFIFO_byte;
        struct
        {
            __IOM uint32_t FIFOPORT : 32;
        } CFIFO_b;
    };
    __IM uint8_t RESERVED3[8];
    union
    {
        __IOM uint16_t CFIFOSEL;
        struct
        {
            __IOM uint16_t CURPIPE : 4;
            uint16_t               : 1;
            __IOM uint16_t ISEL    : 1;
            uint16_t               : 2;
            __IOM uint16_t BIGEND  : 1;
            uint16_t               : 1;
            __IOM uint16_t MBW     : 2;
            uint16_t               : 2;
            __IOM uint16_t REW     : 1;
            __IOM uint16_t RCNT    : 1;
        } CFIFOSEL_b;
    };
    union
    {
        __IOM uint16_t CFIFOCTR;
        struct
        {
            __IM uint16_t DTLN  : 12;
            uint16_t            : 1;
            __IM uint16_t  FRDY : 1;
            __IOM uint16_t BCLR : 1;
            __IOM uint16_t BVAL : 1;
        } CFIFOCTR_b;
    };
    __IM uint8_t RESERVED4[4];
    union
    {
        __IOM uint16_t D0FIFOSEL;
        struct
        {
            __IOM uint16_t CURPIPE : 4;
            uint16_t               : 6;
            __IOM uint16_t MBW     : 2;
            __IOM uint16_t DREQE   : 1;
            __IOM uint16_t DCLRM   : 1;
            __IOM uint16_t REW     : 1;
            __IOM uint16_t RCNT    : 1;
        } D0FIFOSEL_b;
    };
    union
    {
        __IOM uint16_t D0FIFOCTR;
        struct
        {
            __IM uint16_t DTLN  : 12;
            uint16_t            : 1;
            __IM uint16_t  FRDY : 1;
            __IOM uint16_t BCLR : 1;
            __IOM uint16_t BVAL : 1;
        } D0FIFOCTR_b;
    };
    union
    {
        __IOM uint16_t D1FIFOSEL;
        struct
        {
            __IOM uint16_t CURPIPE : 4;
            uint16_t               : 6;
            __IOM uint16_t MBW     : 2;
            __IOM uint16_t DREQE   : 1;
            __IOM uint16_t DCLRM   : 1;
            __IOM uint16_t REW     : 1;
            __IOM uint16_t RCNT    : 1;
        } D1FIFOSEL_b;
    };
    union
    {
        __IOM uint16_t D1FIFOCTR;
        struct
        {
            __IM uint16_t DTLN  : 12;
            uint16_t            : 1;
            __IM uint16_t  FRDY : 1;
            __IOM uint16_t BCLR : 1;
            __IOM uint16_t BVAL : 1;
        } D1FIFOCTR_b;
    };
    union
    {
        __IOM uint16_t INTENB0;
        struct
        {
            uint16_t             : 8;
            __IOM uint16_t BRDYE : 1;
            __IOM uint16_t NRDYE : 1;
            __IOM uint16_t BEMPE : 1;
            __IOM uint16_t CTRE  : 1;
            __IOM uint16_t DVSE  : 1;
            __IOM uint16_t SOFE  : 1;
            __IOM uint16_t RSME  : 1;
            __IOM uint16_t VBSE  : 1;
        } INTENB0_b;
    };
    __IM uint8_t RESERVED5[4];
    union
    {
        __IOM uint16_t BRDYENB;
        struct
        {
            __IOM uint16_t PIPEBRDYE : 10;
            uint16_t                 : 6;
        } BRDYENB_b;
    };
    union
    {
        __IOM uint16_t NRDYENB;
        struct
        {
            __IOM uint16_t PIPENRDYE : 10;
            uint16_t                 : 6;
        } NRDYENB_b;
    };
    union
    {
        __IOM uint16_t BEMPENB;
        struct
        {
            __IOM uint16_t PIPEBEMPE : 10;
            uint16_t                 : 6;
        } BEMPENB_b;
    };
    union
    {
        __IOM uint16_t SOFCFG;
        struct
        {
            uint16_t             : 2;
            __IOM uint16_t SOFM  : 2;
            uint16_t             : 2;
            __IOM uint16_t BRDYM : 1;
            uint16_t             : 9;
        } SOFCFG_b;
    };
    __IM uint8_t RESERVED6[2];
    union
    {
        __IOM uint16_t INTSTS0;
        struct
        {
            __IM uint16_t  CTSQ  : 3;
            __IOM uint16_t VALID : 1;
            __IM uint16_t  DVSQ  : 3;
            __IM uint16_t  VBSTS : 1;
            __IM uint16_t  BRDY  : 1;
            __IM uint16_t  NRDY  : 1;
            __IOM uint16_t BEMP  : 1;
            __IOM uint16_t CTRT  : 1;
            __IOM uint16_t DVST  : 1;
            __IOM uint16_t SOFR  : 1;
            __IOM uint16_t RESM  : 1;
            __IOM uint16_t VBINT : 1;
        } INTSTS0_b;
    };
    __IM uint8_t RESERVED7[4];
    union
    {
        __IOM uint16_t BRDYSTS;
        struct
        {
            __IOM uint16_t PIPEBRDY : 10;
            uint16_t                : 6;
        } BRDYSTS_b;
    };
    union
    {
        __IOM uint16_t NRDYSTS;
        struct
        {
            __IOM uint16_t PIPENRDY : 10;
            uint16_t                : 6;
        } NRDYSTS_b;
    };
    union
    {
        __IOM uint16_t BEMPSTS;
        struct
        {
            __IOM uint16_t PIPEBEMP : 10;
            uint16_t                : 6;
        } BEMPSTS_b;
    };
    union
    {
        __IOM uint16_t FRMNUM;
        struct
        {
            __IM uint16_t FRNM  : 11;
            uint16_t            : 3;
            __IOM uint16_t CRCE : 1;
            __IOM uint16_t OVRN : 1;
        } FRMNUM_b;
    };
    union
    {
        __IM uint16_t UFRMNUM;
        struct
        {
            __IM uint16_t UFRNM : 3;
            uint16_t            : 13;
        } UFRMNUM_b;
    };
    union
    {
        __IM uint16_t USBADDR;
        struct
        {
            __IM uint16_t USBADDR : 7;
            uint16_t              : 9;
        } USBADDR_b;
    };
    __IM uint8_t RESERVED8[2];
    union
    {
        __IM uint16_t USBREQ;
        struct
        {
            __IM uint16_t bmRequestType : 8;
            __IM uint16_t bRequest      : 8;
        } USBREQ_b;
    };
    union
    {
        __IM uint16_t USBVAL;
        struct
        {
            __IM uint16_t wValue : 16;
        } USBVAL_b;
    };
    union
    {
        __IM uint16_t USBINDX;
        struct
        {
            __IM uint16_t wIndex : 16;
        } USBINDX_b;
    };
    union
    {
        __IM uint16_t USBLENG;
        struct
        {
            __IM uint16_t wLength : 16;
        } USBLENG_b;
    };
    union
    {
        __IOM uint16_t DCPCFG;
        struct
        {
            uint16_t              : 7;
            __IOM uint16_t SHTNAK : 1;
            __IOM uint16_t CNTMD  : 1;
            uint16_t              : 7;
        } DCPCFG_b;
    };
    union
    {
        __IOM uint16_t DCPMAXP;
        struct
        {
            __IOM uint16_t MXPS : 7;
            uint16_t            : 9;
        } DCPMAXP_b;
    };
    union
    {
        __IOM uint16_t DCPCTR;
        struct
        {
            __IOM uint16_t PID   : 2;
            __IOM uint16_t CCPL  : 1;
            uint16_t             : 2;
            __IM uint16_t  PBUSY : 1;
            __IM uint16_t  SQMON : 1;
            __IOM uint16_t SQSET : 1;
            __IOM uint16_t SQCLR : 1;
            uint16_t             : 6;
            __IM uint16_t BSTS   : 1;
        } DCPCTR_b;
    };
    __IM uint8_t RESERVED9[2];
    union
    {
        __IOM uint16_t PIPESEL;
        struct
        {
            __IOM uint16_t PIPESEL : 4;
            uint16_t               : 12;
        } PIPESEL_b;
    };
    __IM uint8_t RESERVED10[2];
    union
    {
        __IOM uint16_t PIPECFG;
        struct
        {
            __IOM uint16_t EPNUM  : 4;
            __IOM uint16_t DIR    : 1;
            uint16_t              : 2;
            __IOM uint16_t SHTNAK : 1;
            __IOM uint16_t CNTMD  : 1;
            __IOM uint16_t DBLB   : 1;
            __IOM uint16_t BFRE   : 1;
            uint16_t              : 3;
            __IOM uint16_t TYPE   : 2;
        } PIPECFG_b;
    };
    union
    {
        __IOM uint16_t PIPEBUF;
        struct
        {
            __IOM uint16_t BUFNMB  : 8;
            uint16_t               : 2;
            __IOM uint16_t BUFSIZE : 5;
            uint16_t               : 1;
        } PIPEBUF_b;
    };
    union
    {
        __IOM uint16_t PIPEMAXP;
        struct
        {
            __IOM uint16_t MXPS : 11;
            uint16_t            : 5;
        } PIPEMAXP_b;
    };
    union
    {
        __IOM uint16_t PIPEPERI;
        struct
        {
            __IOM uint16_t IITV : 3;
            uint16_t            : 9;
            __IOM uint16_t IFIS : 1;
            uint16_t            : 3;
        } PIPEPERI_b;
    };
    union
    {
        __IOM uint16_t PIPE1CTR;
        struct
        {
            __IOM uint16_t PID    : 2;
            uint16_t              : 3;
            __IM uint16_t  PBUSY  : 1;
            __IM uint16_t  SQMON  : 1;
            __IOM uint16_t SQSET  : 1;
            __IOM uint16_t SQCLR  : 1;
            __IOM uint16_t ACLRM  : 1;
            __IOM uint16_t ATREPM : 1;
            uint16_t              : 3;
            __IM uint16_t INBUFM  : 1;
            __IM uint16_t BSTS    : 1;
        } PIPE1CTR_b;
    };
    union
    {
        __IOM uint16_t PIPE2CTR;
        struct
        {
            __IOM uint16_t PID    : 2;
            uint16_t              : 3;
            __IM uint16_t  PBUSY  : 1;
            __IM uint16_t  SQMON  : 1;
            __IOM uint16_t SQSET  : 1;
            __IOM uint16_t SQCLR  : 1;
            __IOM uint16_t ACLRM  : 1;
            __IOM uint16_t ATREPM : 1;
            uint16_t              : 3;
            __IM uint16_t INBUFM  : 1;
            __IM uint16_t BSTS    : 1;
        } PIPE2CTR_b;
    };
    union
    {
        __IOM uint16_t PIPE3CTR;
        struct
        {
            __IOM uint16_t PID    : 2;
            uint16_t              : 3;
            __IM uint16_t  PBUSY  : 1;
            __IM uint16_t  SQMON  : 1;
            __IOM uint16_t SQSET  : 1;
            __IOM uint16_t SQCLR  : 1;
            __IOM uint16_t ACLRM  : 1;
            __IOM uint16_t ATREPM : 1;
            uint16_t              : 3;
            __IM uint16_t INBUFM  : 1;
            __IM uint16_t BSTS    : 1;
        } PIPE3CTR_b;
    };
    union
    {
        __IOM uint16_t PIPE4CTR;
        struct
        {
            __IOM uint16_t PID    : 2;
            uint16_t              : 3;
            __IM uint16_t  PBUSY  : 1;
            __IM uint16_t  SQMON  : 1;
            __IOM uint16_t SQSET  : 1;
            __IOM uint16_t SQCLR  : 1;
            __IOM uint16_t ACLRM  : 1;
            __IOM uint16_t ATREPM : 1;
            uint16_t              : 3;
            __IM uint16_t INBUFM  : 1;
            __IM uint16_t BSTS    : 1;
        } PIPE4CTR_b;
    };
    union
    {
        __IOM uint16_t PIPE5CTR;
        struct
        {
            __IOM uint16_t PID    : 2;
            uint16_t              : 3;
            __IM uint16_t  PBUSY  : 1;
            __IM uint16_t  SQMON  : 1;
            __IOM uint16_t SQSET  : 1;
            __IOM uint16_t SQCLR  : 1;
            __IOM uint16_t ACLRM  : 1;
            __IOM uint16_t ATREPM : 1;
            uint16_t              : 3;
            __IM uint16_t INBUFM  : 1;
            __IM uint16_t BSTS    : 1;
        } PIPE5CTR_b;
    };
    union
    {
        __IOM uint16_t PIPE6CTR;
        struct
        {
            __IOM uint16_t PID   : 2;
            uint16_t             : 3;
            __IM uint16_t  PBUSY : 1;
            __IM uint16_t  SQMON : 1;
            __IOM uint16_t SQSET : 1;
            __IOM uint16_t SQCLR : 1;
            __IOM uint16_t ACLRM : 1;
            uint16_t             : 5;
            __IM uint16_t BSTS   : 1;
        } PIPE6CTR_b;
    };
    union
    {
        __IOM uint16_t PIPE7CTR;
        struct
        {
            __IOM uint16_t PID   : 2;
            uint16_t             : 3;
            __IM uint16_t  PBUSY : 1;
            __IM uint16_t  SQMON : 1;
            __IOM uint16_t SQSET : 1;
            __IOM uint16_t SQCLR : 1;
            __IOM uint16_t ACLRM : 1;
            uint16_t             : 5;
            __IM uint16_t BSTS   : 1;
        } PIPE7CTR_b;
    };
    union
    {
        __IOM uint16_t PIPE8CTR;
        struct
        {
            __IOM uint16_t PID   : 2;
            uint16_t             : 3;
            __IM uint16_t  PBUSY : 1;
            __IM uint16_t  SQMON : 1;
            __IOM uint16_t SQSET : 1;
            __IOM uint16_t SQCLR : 1;
            __IOM uint16_t ACLRM : 1;
            uint16_t             : 5;
            __IM uint16_t BSTS   : 1;
        } PIPE8CTR_b;
    };
    union
    {
        __IOM uint16_t PIPE9CTR;
        struct
        {
            __IOM uint16_t PID   : 2;
            uint16_t             : 3;
            __IM uint16_t  PBUSY : 1;
            __IM uint16_t  SQMON : 1;
            __IOM uint16_t SQSET : 1;
            __IOM uint16_t SQCLR : 1;
            __IOM uint16_t ACLRM : 1;
            uint16_t             : 5;
            __IM uint16_t BSTS   : 1;
        } PIPE9CTR_b;
    };
    __IM uint8_t RESERVED11[14];
    union
    {
        __IOM uint16_t PIPE1TRE;
        struct
        {
            uint16_t             : 8;
            __IOM uint16_t TRCLR : 1;
            __IOM uint16_t TRENB : 1;
            uint16_t             : 6;
        } PIPE1TRE_b;
    };
    union
    {
        __IOM uint16_t PIPE1TRN;
        struct
        {
            __IOM uint16_t TRNCNT : 16;
        } PIPE1TRN_b;
    };
    union
    {
        __IOM uint16_t PIPE2TRE;
        struct
        {
            uint16_t             : 8;
            __IOM uint16_t TRCLR : 1;
            __IOM uint16_t TRENB : 1;
            uint16_t             : 6;
        } PIPE2TRE_b;
    };
    union
    {
        __IOM uint16_t PIPE2TRN;
        struct
        {
            __IOM uint16_t TRNCNT : 16;
        } PIPE2TRN_b;
    };
    union
    {
        __IOM uint16_t PIPE3TRE;
        struct
        {
            uint16_t             : 8;
            __IOM uint16_t TRCLR : 1;
            __IOM uint16_t TRENB : 1;
            uint16_t             : 6;
        } PIPE3TRE_b;
    };
    union
    {
        __IOM uint16_t PIPE3TRN;
        struct
        {
            __IOM uint16_t TRNCNT : 16;
        } PIPE3TRN_b;
    };
    union
    {
        __IOM uint16_t PIPE4TRE;
        struct
        {
            uint16_t             : 8;
            __IOM uint16_t TRCLR : 1;
            __IOM uint16_t TRENB : 1;
            uint16_t             : 6;
        } PIPE4TRE_b;
    };
    union
    {
        __IOM uint16_t PIPE4TRN;
        struct
        {
            __IOM uint16_t TRNCNT : 16;
        } PIPE4TRN_b;
    };
    union
    {
        __IOM uint16_t PIPE5TRE;
        struct
        {
            uint16_t             : 8;
            __IOM uint16_t TRCLR : 1;
            __IOM uint16_t TRENB : 1;
            uint16_t             : 6;
        } PIPE5TRE_b;
    };
    union
    {
        __IOM uint16_t PIPE5TRN;
        struct
        {
            __IOM uint16_t TRNCNT : 16;
        } PIPE5TRN_b;
    };
    __IM uint8_t  RESERVED12[44];
    __IM uint16_t DEVADD0;
    __IM uint16_t DEVADD1;
    __IM uint16_t DEVADD2;
    __IM uint16_t DEVADD3;
    __IM uint16_t DEVADD4;
    __IM uint16_t DEVADD5;
    __IM uint16_t DEVADD6;
    __IM uint16_t DEVADD7;
    __IM uint16_t DEVADD8;
    __IM uint16_t DEVADD9;
    __IM uint16_t DEVADDA;
    __IM uint8_t  RESERVED13[26];
    union
    {
        __IOM uint16_t LPCTRL;
        struct
        {
            uint16_t             : 7;
            __IOM uint16_t HWUPM : 1;
            uint16_t             : 8;
        } LPCTRL_b;
    };
    union
    {
        __IOM uint16_t LPSTS;
        struct
        {
            uint16_t             : 14;
            __IOM uint16_t SUSPM : 1;
            uint16_t             : 1;
        } LPSTS_b;
    };
    union
    {
        __IM uint16_t PHYFUNCTR;
        struct
        {
            uint16_t             : 14;
            __IM uint16_t SusMon : 1;
            uint16_t             : 1;
        } PHYFUNCTR_b;
    };
    __IM uint8_t RESERVED14[4];
    union
    {
        __IM uint16_t PHYOTGCTR;
        struct
        {
            uint16_t              : 9;
            __IM uint16_t DpPuDwn : 1;
            __IM uint16_t DmPuDwn : 1;
            uint16_t              : 5;
        } PHYOTGCTR_b;
    };
    __IM uint8_t RESERVED15[56];
    union
    {
        __IOM uint16_t PL1CTRL1;
        struct
        {
            __IOM uint16_t L1RESPEN : 1;
            __IOM uint16_t L1RESPMD : 2;
            __IOM uint16_t L1NEGOMD : 1;
            __IM uint16_t  DVSQ     : 4;
            __IOM uint16_t HIRDTHR  : 4;
            uint16_t                : 2;
            __IM uint16_t L1EXTMD   : 1;
            uint16_t                : 1;
        } PL1CTRL1_b;
    };
    union
    {
        __IOM uint16_t PL1CTRL2;
        struct
        {
            uint16_t               : 8;
            __IOM uint16_t HIRDMON : 4;
            __IOM uint16_t RWEMON  : 1;
            uint16_t               : 3;
        } PL1CTRL2_b;
    };
    __IM uint8_t RESERVED16[696];
    union
    {
        __IOM uint32_t N0SA_0;
        struct
        {
            __IOM uint32_t SA_WD : 32;
        } N0SA_0_b;
    };
    union
    {
        __IOM uint32_t N0DA_0;
        struct
        {
            __IOM uint32_t DA : 32;
        } N0DA_0_b;
    };
    union
    {
        __IOM uint32_t N0TB_0;
        struct
        {
            __IOM uint32_t TB : 32;
        } N0TB_0_b;
    };
    union
    {
        __IOM uint32_t N1SA_0;
        struct
        {
            __IOM uint32_t SA_WD : 32;
        } N1SA_0_b;
    };
    union
    {
        __IOM uint32_t N1DA_0;
        struct
        {
            __IOM uint32_t DA : 32;
        } N1DA_0_b;
    };
    union
    {
        __IOM uint32_t N1TB_0;
        struct
        {
            __IOM uint32_t TB : 32;
        } N1TB_0_b;
    };
    union
    {
        __IM uint32_t CRSA_0;
        struct
        {
            __IM uint32_t CRSA : 32;
        } CRSA_0_b;
    };
    union
    {
        __IM uint32_t CRDA_0;
        struct
        {
            __IM uint32_t CRDA : 32;
        } CRDA_0_b;
    };
    union
    {
        __IM uint32_t CRTB_0;
        struct
        {
            __IM uint32_t CRTB : 32;
        } CRTB_0_b;
    };
    union
    {
        __IM uint32_t CHSTAT_0;
        struct
        {
            __IM uint32_t EN     : 1;
            __IM uint32_t RQST   : 1;
            __IM uint32_t TACT   : 1;
            __IM uint32_t SUS    : 1;
            __IM uint32_t ER     : 1;
            __IM uint32_t END    : 1;
            __IM uint32_t TC     : 1;
            __IM uint32_t SR     : 1;
            __IM uint32_t DL     : 1;
            __IM uint32_t DW     : 1;
            __IM uint32_t DER    : 1;
            __IM uint32_t MODE   : 1;
            uint32_t             : 4;
            __IM uint32_t INTM   : 1;
            __IM uint32_t DMARQM : 1;
            __IM uint32_t SWPRQ  : 1;
            uint32_t             : 5;
            __IM uint32_t DNUM   : 8;
        } CHSTAT_0_b;
    };
    union
    {
        __IOM uint32_t CHCTRL_0;
        struct
        {
            __IOM uint32_t SETEN     : 1;
            __IOM uint32_t CLREN     : 1;
            __IOM uint32_t STG       : 1;
            __IOM uint32_t SWRST     : 1;
            __IOM uint32_t CLRRQ     : 1;
            __IOM uint32_t CLREND    : 1;
            __IOM uint32_t CLRTC     : 1;
            __IOM uint32_t CLRDER    : 1;
            __IOM uint32_t SETSUS    : 1;
            __IOM uint32_t CLRSUS    : 1;
            uint32_t                 : 2;
            __IOM uint32_t SETREN    : 1;
            uint32_t                 : 1;
            __IOM uint32_t SETSSWPRQ : 1;
            uint32_t                 : 1;
            __IOM uint32_t SETINTM   : 1;
            __IOM uint32_t CLRINTM   : 1;
            __IOM uint32_t SETDMARQM : 1;
            __IOM uint32_t CLRDMARQM : 1;
            uint32_t                 : 12;
        } CHCTRL_0_b;
    };
    union
    {
        __IOM uint32_t CHCFG_0;
        struct
        {
            __IOM uint32_t SEL   : 1;
            uint32_t             : 2;
            __IOM uint32_t REQD  : 1;
            uint32_t             : 7;
            __IOM uint32_t DRRP  : 1;
            __IOM uint32_t SDS   : 4;
            __IOM uint32_t DDS   : 4;
            __IOM uint32_t SAD   : 1;
            __IOM uint32_t DAD   : 1;
            uint32_t             : 1;
            __IOM uint32_t WONLY : 1;
            __IOM uint32_t DEM   : 1;
            __IOM uint32_t TCM   : 1;
            __IOM uint32_t DIM   : 1;
            __IOM uint32_t SBE   : 1;
            __IOM uint32_t RSEL  : 1;
            __IOM uint32_t RSW   : 1;
            __IOM uint32_t REN   : 1;
            __IOM uint32_t DMS   : 1;
        } CHCFG_0_b;
    };
    union
    {
        __IOM uint32_t CHITVL_0;
        struct
        {
            __IOM uint32_t ITVL : 16;
            uint32_t            : 16;
        } CHITVL_0_b;
    };
    union
    {
        __IOM uint32_t CHEXT_0;
        struct
        {
            __IOM uint32_t SPR : 4;
            uint32_t           : 4;
            __IOM uint32_t DPR : 4;
            uint32_t           : 20;
        } CHEXT_0_b;
    };
    union
    {
        __IOM uint32_t NXLA_0;
        struct
        {
            __IOM uint32_t NXLA : 32;
        } NXLA_0_b;
    };
    union
    {
        __IM uint32_t CRLA_0;
        struct
        {
            __IM uint32_t CRLA : 32;
        } CRLA_0_b;
    };
    union
    {
        __IOM uint32_t N0SA_1;
        struct
        {
            __IOM uint32_t SA_WD : 32;
        } N0SA_1_b;
    };
    union
    {
        __IOM uint32_t N0DA_1;
        struct
        {
            __IOM uint32_t DA : 32;
        } N0DA_1_b;
    };
    union
    {
        __IOM uint32_t N0TB_1;
        struct
        {
            __IOM uint32_t TB : 32;
        } N0TB_1_b;
    };
    union
    {
        __IOM uint32_t N1SA_1;
        struct
        {
            __IOM uint32_t SA_WD : 32;
        } N1SA_1_b;
    };
    union
    {
        __IOM uint32_t N1DA_1;
        struct
        {
            __IOM uint32_t DA : 32;
        } N1DA_1_b;
    };
    union
    {
        __IOM uint32_t N1TB_1;
        struct
        {
            __IOM uint32_t TB : 32;
        } N1TB_1_b;
    };
    union
    {
        __IM uint32_t CRSA_1;
        struct
        {
            __IM uint32_t CRSA : 32;
        } CRSA_1_b;
    };
    union
    {
        __IM uint32_t CRDA_1;
        struct
        {
            __IM uint32_t CRDA : 32;
        } CRDA_1_b;
    };
    union
    {
        __IM uint32_t CRTB_1;
        struct
        {
            __IM uint32_t CRTB : 32;
        } CRTB_1_b;
    };
    union
    {
        __IM uint32_t CHSTAT_1;
        struct
        {
            __IM uint32_t EN     : 1;
            __IM uint32_t RQST   : 1;
            __IM uint32_t TACT   : 1;
            __IM uint32_t SUS    : 1;
            __IM uint32_t ER     : 1;
            __IM uint32_t END    : 1;
            __IM uint32_t TC     : 1;
            __IM uint32_t SR     : 1;
            __IM uint32_t DL     : 1;
            __IM uint32_t DW     : 1;
            __IM uint32_t DER    : 1;
            __IM uint32_t MODE   : 1;
            uint32_t             : 4;
            __IM uint32_t INTM   : 1;
            __IM uint32_t DMARQM : 1;
            __IM uint32_t SWPRQ  : 1;
            uint32_t             : 5;
            __IM uint32_t DNUM   : 8;
        } CHSTAT_1_b;
    };
    union
    {
        __IOM uint32_t CHCTRL_1;
        struct
        {
            __IOM uint32_t SETEN     : 1;
            __IOM uint32_t CLREN     : 1;
            __IOM uint32_t STG       : 1;
            __IOM uint32_t SWRST     : 1;
            __IOM uint32_t CLRRQ     : 1;
            __IOM uint32_t CLREND    : 1;
            __IOM uint32_t CLRTC     : 1;
            __IOM uint32_t CLRDER    : 1;
            __IOM uint32_t SETSUS    : 1;
            __IOM uint32_t CLRSUS    : 1;
            uint32_t                 : 2;
            __IOM uint32_t SETREN    : 1;
            uint32_t                 : 1;
            __IOM uint32_t SETSSWPRQ : 1;
            uint32_t                 : 1;
            __IOM uint32_t SETINTM   : 1;
            __IOM uint32_t CLRINTM   : 1;
            __IOM uint32_t SETDMARQM : 1;
            __IOM uint32_t CLRDMARQM : 1;
            uint32_t                 : 12;
        } CHCTRL_1_b;
    };
    union
    {
        __IOM uint32_t CHCFG_1;
        struct
        {
            __IOM uint32_t SEL   : 1;
            uint32_t             : 2;
            __IOM uint32_t REQD  : 1;
            uint32_t             : 7;
            __IOM uint32_t DRRP  : 1;
            __IOM uint32_t SDS   : 4;
            __IOM uint32_t DDS   : 4;
            __IOM uint32_t SAD   : 1;
            __IOM uint32_t DAD   : 1;
            uint32_t             : 1;
            __IOM uint32_t WONLY : 1;
            __IOM uint32_t DEM   : 1;
            __IOM uint32_t TCM   : 1;
            __IOM uint32_t DIM   : 1;
            __IOM uint32_t SBE   : 1;
            __IOM uint32_t RSEL  : 1;
            __IOM uint32_t RSW   : 1;
            __IOM uint32_t REN   : 1;
            __IOM uint32_t DMS   : 1;
        } CHCFG_1_b;
    };
    union
    {
        __IOM uint32_t CHITVL_1;
        struct
        {
            __IOM uint32_t ITVL : 16;
            uint32_t            : 16;
        } CHITVL_1_b;
    };
    union
    {
        __IOM uint32_t CHEXT_1;
        struct
        {
            __IOM uint32_t SPR : 4;
            uint32_t           : 4;
            __IOM uint32_t DPR : 4;
            uint32_t           : 20;
        } CHEXT_1_b;
    };
    union
    {
        __IOM uint32_t NXLA_1;
        struct
        {
            __IOM uint32_t NXLA : 32;
        } NXLA_1_b;
    };
    union
    {
        __IM uint32_t CRLA_1;
        struct
        {
            __IM uint32_t CRLA : 32;
        } CRLA_1_b;
    };
    __IM uint8_t RESERVED17[384];
    union
    {
        __IOM uint32_t SCNT_0;
        struct
        {
            __IOM uint32_t SCNT : 32;
        } SCNT_0_b;
    };
    union
    {
        __IOM uint32_t SSKP_0;
        struct
        {
            __IOM uint32_t SSKP : 32;
        } SSKP_0_b;
    };
    union
    {
        __IOM uint32_t DCNT_0;
        struct
        {
            __IOM uint32_t DCNT : 32;
        } DCNT_0_b;
    };
    union
    {
        __IOM uint32_t DSKP_0;
        struct
        {
            __IOM uint32_t DSKP : 32;
        } DSKP_0_b;
    };
    __IM uint8_t RESERVED18[16];
    union
    {
        __IOM uint32_t SCNT_1;
        struct
        {
            __IOM uint32_t SCNT : 32;
        } SCNT_1_b;
    };
    union
    {
        __IOM uint32_t SSKP_1;
        struct
        {
            __IOM uint32_t SSKP : 32;
        } SSKP_1_b;
    };
    union
    {
        __IOM uint32_t DCNT_1;
        struct
        {
            __IOM uint32_t DCNT : 32;
        } DCNT_1_b;
    };
    union
    {
        __IOM uint32_t DSKP_1;
        struct
        {
            __IOM uint32_t DSKP : 32;
        } DSKP_1_b;
    };
    __IM uint8_t RESERVED19[208];
    union
    {
        __IOM uint32_t DCTRL;
        struct
        {
            __IOM uint32_t PR    : 1;
            __IOM uint32_t LVINT : 1;
            uint32_t             : 14;
            __IOM uint32_t LDPR  : 4;
            uint32_t             : 4;
            __IOM uint32_t LWPR  : 4;
            uint32_t             : 4;
        } DCTRL_b;
    };
    union
    {
        __IOM uint32_t DSCITVL;
        struct
        {
            uint32_t             : 8;
            __IOM uint32_t DITVL : 8;
            uint32_t             : 16;
        } DSCITVL_b;
    };
    __IM uint8_t RESERVED20[8];
    union
    {
        __IOM uint32_t DST_EN;
        struct
        {
            __IOM uint32_t EN0 : 1;
            __IOM uint32_t EN1 : 1;
            uint32_t           : 30;
        } DST_EN_b;
    };
    union
    {
        __IOM uint32_t DST_ER;
        struct
        {
            __IOM uint32_t ER0 : 1;
            __IOM uint32_t ER1 : 1;
            uint32_t           : 30;
        } DST_ER_b;
    };
    union
    {
        __IOM uint32_t DST_END;
        struct
        {
            __IOM uint32_t END0 : 1;
            __IOM uint32_t END1 : 1;
            uint32_t            : 30;
        } DST_END_b;
    };
    union
    {
        __IM uint32_t DST_TC;
        struct
        {
            __IM uint32_t TC0 : 1;
            __IM uint32_t TC1 : 1;
            uint32_t          : 30;
        } DST_TC_b;
    };
    union
    {
        __IM uint32_t DST_SUS;
        struct
        {
            __IM uint32_t SUS0 : 1;
            __IM uint32_t SUS1 : 1;
            uint32_t           : 30;
        } DST_SUS_b;
    };
} R_USB01_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_USB_BASE      0x11C40000
#define R_USB00_BASE    0x11C50000
#define R_USB01_BASE    0x11C60000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_USB      ((R_USB_Type *) R_USB_BASE)
#define R_USB00    ((R_USB00_Type *) R_USB00_BASE)
#define R_USB01    ((R_USB01_Type *) R_USB01_BASE)

#endif
