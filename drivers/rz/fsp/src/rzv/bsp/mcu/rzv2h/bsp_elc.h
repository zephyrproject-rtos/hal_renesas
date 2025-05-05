/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_ELC_H
#define BSP_ELC_H

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RZV2H
 * @{
 **********************************************************************************************************************/

/** Sources of event signals to be linked to other peripherals or the CPU
 * @note This list may change based on based on the device.
 * */
typedef enum e_elc_event_rzv2h
{
    ELC_EVENT_IRQ0                    = (0),   // External pin interrupt 0
    ELC_EVENT_IRQ1                    = (1),   // External pin interrupt 1
    ELC_EVENT_IRQ2                    = (2),   // External pin interrupt 2
    ELC_EVENT_IRQ3                    = (3),   // External pin interrupt 3
    ELC_EVENT_IRQ4                    = (4),   // External pin interrupt 4
    ELC_EVENT_IRQ5                    = (5),   // External pin interrupt 5
    ELC_EVENT_IRQ6                    = (6),   // External pin interrupt 6
    ELC_EVENT_IRQ7                    = (7),   // External pin interrupt 7
    ELC_EVENT_IRQ8                    = (8),   // External pin interrupt 8
    ELC_EVENT_IRQ9                    = (9),   // External pin interrupt 9
    ELC_EVENT_IRQ10                   = (10),  // External pin interrupt 10
    ELC_EVENT_IRQ11                   = (11),  // External pin interrupt 11
    ELC_EVENT_IRQ12                   = (12),  // External pin interrupt 12
    ELC_EVENT_IRQ13                   = (13),  // External pin interrupt 13
    ELC_EVENT_IRQ14                   = (14),  // External pin interrupt 14
    ELC_EVENT_IRQ15                   = (15),  // External pin interrupt 15
    ELC_EVENT_IOPORT_GROUP0           = (16),  // Input edge detection of input port group 1
    ELC_EVENT_IOPORT_GROUP1           = (17),  // Input edge detection of input port group 2
    ELC_EVENT_IOPORT_SINGLE0          = (18),  // Input edge detection of single input port group 0
    ELC_EVENT_IOPORT_SINGLE1          = (19),  // Input edge detection of single input port group 1
    ELC_EVENT_IOPORT_SINGLE2          = (20),  // Input edge detection of single input port group 2
    ELC_EVENT_IOPORT_SINGLE3          = (21),  // Input edge detection of single input port group 3
    ELC_EVENT_SW_EVENT_0              = (22),  // Software interrupt 0
    ELC_EVENT_SW_EVENT_1              = (23),  // Software interrupt 1
    ELC_EVENT_SW_EVENT_2              = (24),  // Software interrupt 2
    ELC_EVENT_SW_EVENT_3              = (25),  // Software interrupt 3
    ELC_EVENT_SW_EVENT_4              = (26),  // Software interrupt 4
    ELC_EVENT_SW_EVENT_5              = (27),  // Software interrupt 5
    ELC_EVENT_SW_EVENT_6              = (28),  // Software interrupt 6
    ELC_EVENT_CMTW_CH0_CMT2_ELCCMP    = (29),  // CMTW0 compare match event
    ELC_EVENT_CMTW_CH1_CMT2_ELCCMP    = (30),  // CMTW1 compare match event
    ELC_EVENT_CMTW_CH2_CMT2_ELCCMP    = (31),  // CMTW2 compare match event
    ELC_EVENT_CMTW_CH3_CMT2_ELCCMP    = (32),  // CMTW3 compare match event
    ELC_EVENT_CMTW_CH4_CMT2_ELCCMP    = (33),  // CMTW4 compare match event
    ELC_EVENT_CMTW_CH5_CMT2_ELCCMP    = (34),  // CMTW5 compare match event
    ELC_EVENT_CMTW_CH6_CMT2_ELCCMP    = (35),  // CMTW6 compare match event
    ELC_EVENT_CMTW_CH7_CMT2_ELCCMP    = (36),  // CMTW7 compare match event
    ELC_EVENT_CMTW_CH0_CMT2_ELCOCP0   = (37),  // CMTW0 Output compare 0 event
    ELC_EVENT_CMTW_CH1_CMT2_ELCOCP0   = (38),  // CMTW1 Output compare 0 event
    ELC_EVENT_CMTW_CH2_CMT2_ELCOCP0   = (39),  // CMTW2 Output compare 0 event
    ELC_EVENT_CMTW_CH3_CMT2_ELCOCP0   = (40),  // CMTW3 Output compare 0 event
    ELC_EVENT_CMTW_CH4_CMT2_ELCOCP0   = (41),  // CMTW4 Output compare 0 event
    ELC_EVENT_CMTW_CH5_CMT2_ELCOCP0   = (42),  // CMTW5 Output compare 0 event
    ELC_EVENT_CMTW_CH6_CMT2_ELCOCP0   = (43),  // CMTW6 Output compare 0 event
    ELC_EVENT_CMTW_CH7_CMT2_ELCOCP0   = (44),  // CMTW7 Output compare 0 event
    ELC_EVENT_CMTW_CH0_CMT2_ELCOCP1   = (45),  // CMTW0 Output compare 1 event
    ELC_EVENT_CMTW_CH1_CMT2_ELCOCP1   = (46),  // CMTW1 Output compare 1 event
    ELC_EVENT_CMTW_CH2_CMT2_ELCOCP1   = (47),  // CMTW2 Output compare 1 event
    ELC_EVENT_CMTW_CH3_CMT2_ELCOCP1   = (48),  // CMTW3 Output compare 1 event
    ELC_EVENT_CMTW_CH4_CMT2_ELCOCP1   = (49),  // CMTW4 Output compare 1 event
    ELC_EVENT_CMTW_CH5_CMT2_ELCOCP1   = (50),  // CMTW5 Output compare 1 event
    ELC_EVENT_CMTW_CH6_CMT2_ELCOCP1   = (51),  // CMTW6 Output compare 1 event
    ELC_EVENT_CMTW_CH7_CMT2_ELCOCP1   = (52),  // CMTW7 Output compare 1 event
    ELC_EVENT_GTM0_GTMTINT            = (53),  // GTM0 interrupt output signal
    ELC_EVENT_GTM1_GTMTINT            = (54),  // GTM1 interrupt output signal
    ELC_EVENT_GTM2_GTMTINT            = (55),  // GTM2 interrupt output signal
    ELC_EVENT_GTM3_GTMTINT            = (56),  // GTM3 interrupt output signal
    ELC_EVENT_GTM4_GTMTINT            = (57),  // GTM4 interrupt output signal
    ELC_EVENT_GTM5_GTMTINT            = (58),  // GTM5 interrupt output signal
    ELC_EVENT_GTM6_GTMTINT            = (59),  // GTM6 interrupt output signal
    ELC_EVENT_GTM7_GTMTINT            = (60),  // GTM7 interrupt output signal
    ELC_EVENT_DMAC1_DMAEND_0          = (61),  // DMAC1 transfer completion 0
    ELC_EVENT_DMAC1_DMAEND_1          = (62),  // DMAC1 transfer completion 1
    ELC_EVENT_DMAC1_DMAEND_2          = (63),  // DMAC1 transfer completion 2
    ELC_EVENT_DMAC1_DMAEND_3          = (64),  // DMAC1 transfer completion 3
    ELC_EVENT_DMAC1_DMAEND_4          = (65),  // DMAC1 transfer completion 4
    ELC_EVENT_DMAC1_DMAEND_5          = (66),  // DMAC1 transfer completion 5
    ELC_EVENT_DMAC1_DMAEND_6          = (67),  // DMAC1 transfer completion 6
    ELC_EVENT_DMAC1_DMAEND_7          = (68),  // DMAC1 transfer completion 7
    ELC_EVENT_DMAC1_DMAEND_8          = (69),  // DMAC1 transfer completion 8
    ELC_EVENT_DMAC1_DMAEND_9          = (70),  // DMAC1 transfer completion 9
    ELC_EVENT_DMAC1_DMAEND_10         = (71),  // DMAC1 transfer completion 10
    ELC_EVENT_DMAC1_DMAEND_11         = (72),  // DMAC1 transfer completion 11
    ELC_EVENT_DMAC1_DMAEND_12         = (73),  // DMAC1 transfer completion 12
    ELC_EVENT_DMAC1_DMAEND_13         = (74),  // DMAC1 transfer completion 13
    ELC_EVENT_DMAC1_DMAEND_14         = (75),  // DMAC1 transfer completion 14
    ELC_EVENT_DMAC1_DMAEND_15         = (76),  // DMAC1 transfer completion 15
    ELC_EVENT_DMAC2_DMAEND_0          = (77),  // DMAC2 transfer completion 0
    ELC_EVENT_DMAC2_DMAEND_1          = (78),  // DMAC2 transfer completion 1
    ELC_EVENT_DMAC2_DMAEND_2          = (79),  // DMAC2 transfer completion 2
    ELC_EVENT_DMAC2_DMAEND_3          = (80),  // DMAC2 transfer completion 3
    ELC_EVENT_DMAC2_DMAEND_4          = (81),  // DMAC2 transfer completion 4
    ELC_EVENT_DMAC2_DMAEND_5          = (82),  // DMAC2 transfer completion 5
    ELC_EVENT_DMAC2_DMAEND_6          = (83),  // DMAC2 transfer completion 6
    ELC_EVENT_DMAC2_DMAEND_7          = (84),  // DMAC2 transfer completion 7
    ELC_EVENT_DMAC2_DMAEND_8          = (85),  // DMAC2 transfer completion 8
    ELC_EVENT_DMAC2_DMAEND_9          = (86),  // DMAC2 transfer completion 9
    ELC_EVENT_DMAC2_DMAEND_10         = (87),  // DMAC2 transfer completion 10
    ELC_EVENT_DMAC2_DMAEND_11         = (88),  // DMAC2 transfer completion 11
    ELC_EVENT_DMAC2_DMAEND_12         = (89),  // DMAC2 transfer completion 12
    ELC_EVENT_DMAC2_DMAEND_13         = (90),  // DMAC2 transfer completion 13
    ELC_EVENT_DMAC2_DMAEND_14         = (91),  // DMAC2 transfer completion 14
    ELC_EVENT_DMAC2_DMAEND_15         = (92),  // DMAC2 transfer completion 15
    ELC_EVENT_DMAC3_DMAEND_0          = (93),  // DMAC3 transfer completion 0
    ELC_EVENT_DMAC3_DMAEND_1          = (94),  // DMAC3 transfer completion 1
    ELC_EVENT_DMAC3_DMAEND_2          = (95),  // DMAC3 transfer completion 2
    ELC_EVENT_DMAC3_DMAEND_3          = (96),  // DMAC3 transfer completion 3
    ELC_EVENT_DMAC3_DMAEND_4          = (97),  // DMAC3 transfer completion 4
    ELC_EVENT_DMAC3_DMAEND_5          = (98),  // DMAC3 transfer completion 5
    ELC_EVENT_DMAC3_DMAEND_6          = (99),  // DMAC3 transfer completion 6
    ELC_EVENT_DMAC3_DMAEND_7          = (100), // DMAC3 transfer completion 7
    ELC_EVENT_DMAC3_DMAEND_8          = (101), // DMAC3 transfer completion 8
    ELC_EVENT_DMAC3_DMAEND_9          = (102), // DMAC3 transfer completion 9
    ELC_EVENT_DMAC3_DMAEND_10         = (103), // DMAC3 transfer completion 10
    ELC_EVENT_DMAC3_DMAEND_11         = (104), // DMAC3 transfer completion 11
    ELC_EVENT_DMAC3_DMAEND_12         = (105), // DMAC3 transfer completion 12
    ELC_EVENT_DMAC3_DMAEND_13         = (106), // DMAC3 transfer completion 13
    ELC_EVENT_DMAC3_DMAEND_14         = (107), // DMAC3 transfer completion 14
    ELC_EVENT_DMAC3_DMAEND_15         = (108), // DMAC3 transfer completion 15
    ELC_EVENT_DMAC4_DMAEND_0          = (109), // DMAC4 transfer completion 0
    ELC_EVENT_DMAC4_DMAEND_1          = (110), // DMAC4 transfer completion 1
    ELC_EVENT_DMAC4_DMAEND_2          = (111), // DMAC4 transfer completion 2
    ELC_EVENT_DMAC4_DMAEND_3          = (112), // DMAC4 transfer completion 3
    ELC_EVENT_DMAC4_DMAEND_4          = (113), // DMAC4 transfer completion 4
    ELC_EVENT_DMAC4_DMAEND_5          = (114), // DMAC4 transfer completion 5
    ELC_EVENT_DMAC4_DMAEND_6          = (115), // DMAC4 transfer completion 6
    ELC_EVENT_DMAC4_DMAEND_7          = (116), // DMAC4 transfer completion 7
    ELC_EVENT_DMAC4_DMAEND_8          = (117), // DMAC4 transfer completion 8
    ELC_EVENT_DMAC4_DMAEND_9          = (118), // DMAC4 transfer completion 9
    ELC_EVENT_DMAC4_DMAEND_10         = (119), // DMAC4 transfer completion 10
    ELC_EVENT_DMAC4_DMAEND_11         = (120), // DMAC4 transfer completion 11
    ELC_EVENT_DMAC4_DMAEND_12         = (121), // DMAC4 transfer completion 12
    ELC_EVENT_DMAC4_DMAEND_13         = (122), // DMAC4 transfer completion 13
    ELC_EVENT_DMAC4_DMAEND_14         = (123), // DMAC4 transfer completion 14
    ELC_EVENT_DMAC4_DMAEND_15         = (124), // DMAC4 transfer completion 15
    ELC_EVENT_DMAC0_DMAEND_0          = (125), // DMAC0 transfer completion 0
    ELC_EVENT_DMAC0_DMAEND_1          = (126), // DMAC0 transfer completion 1
    ELC_EVENT_DMAC0_DMAEND_2          = (127), // DMAC0 transfer completion 2
    ELC_EVENT_DMAC0_DMAEND_3          = (128), // DMAC0 transfer completion 3
    ELC_EVENT_DMAC0_DMAEND_4          = (129), // DMAC0 transfer completion 4
    ELC_EVENT_DMAC0_DMAEND_5          = (130), // DMAC0 transfer completion 5
    ELC_EVENT_DMAC0_DMAEND_6          = (131), // DMAC0 transfer completion 6
    ELC_EVENT_DMAC0_DMAEND_7          = (132), // DMAC0 transfer completion 7
    ELC_EVENT_DMAC0_DMAEND_8          = (133), // DMAC0 transfer completion 8
    ELC_EVENT_DMAC0_DMAEND_9          = (134), // DMAC0 transfer completion 9
    ELC_EVENT_DMAC0_DMAEND_10         = (135), // DMAC0 transfer completion 10
    ELC_EVENT_DMAC0_DMAEND_11         = (136), // DMAC0 transfer completion 11
    ELC_EVENT_DMAC0_DMAEND_12         = (137), // DMAC0 transfer completion 12
    ELC_EVENT_DMAC0_DMAEND_13         = (138), // DMAC0 transfer completion 13
    ELC_EVENT_DMAC0_DMAEND_14         = (139), // DMAC0 transfer completion 14
    ELC_EVENT_DMAC0_DMAEND_15         = (140), // DMAC0 transfer completion 15
    ELC_EVENT_IWDT_ELCWUN_CA55        = (141), // WDT CA55 underflow or refresh error event
    ELC_EVENT_IWDT_ELCWUN_CM33        = (142), // WDT CM33 underflow or refresh error event
    ELC_EVENT_IWDT_ELCWUN_CR8_0       = (143), // WDT CR8_0 underflow or refresh error event
    ELC_EVENT_IWDT_ELCWUN_CR8_1       = (144), // WDT CR8_1 underflow or refresh error event
    ELC_EVENT_SP_ELCRDRF_0            = (145), // RSPI0 Receive buffer full event
    ELC_EVENT_SP_ELCTDRE_0            = (146), // RSPI0 Transmit buffer empty event
    ELC_EVENT_SP_ELCERR_0             = (147), // RSPI0 Error event
    ELC_EVENT_SP_ELCID_0              = (148), // RSPI0 Idle event
    ELC_EVENT_SP_ELCCEND_0            = (149), // RSPI0 Communications end event
    ELC_EVENT_SP_ELCRDRF_1            = (150), // RSPI1 Receive buffer full event
    ELC_EVENT_SP_ELCTDRE_1            = (151), // RSPI1 Transmit buffer empty event
    ELC_EVENT_SP_ELCERR_1             = (152), // RSPI1 Error event
    ELC_EVENT_SP_ELCID_1              = (153), // RSPI1 Idle event
    ELC_EVENT_SP_ELCCEND_1            = (154), // RSPI1 Communications end event
    ELC_EVENT_SP_ELCRDRF_2            = (155), // RSPI2 Receive buffer full event
    ELC_EVENT_SP_ELCTDRE_2            = (156), // RSPI2 Transmit buffer empty event
    ELC_EVENT_SP_ELCERR_2             = (157), // RSPI2 Error event
    ELC_EVENT_SP_ELCID_2              = (158), // RSPI2 Idle event
    ELC_EVENT_SP_ELCCEND_2            = (159), // RSPI2 Communications end event
    ELC_EVENT_SC_ELCER_0              = (160), // RSCI0 Receive error event
    ELC_EVENT_SC_ELCRDRF_0            = (161), // RSCI0 Receive data full event
    ELC_EVENT_SC_ELCDCMF_0            = (162), // RSCI0 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_0            = (163), // RSCI0 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_0            = (164), // RSCI0 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_0            = (165), // RSCI0 Receive data compare unmatch event
    ELC_EVENT_SC_ELCER_1              = (166), // RSCI1 Receive error event
    ELC_EVENT_SC_ELCRDRF_1            = (167), // RSCI1 Receive data full event
    ELC_EVENT_SC_ELCDCMF_1            = (168), // RSCI1 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_1            = (169), // RSCI1 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_1            = (170), // RSCI1 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_1            = (171), // RSCI1 Receive data compare unmatch event
    ELC_EVENT_SC_ELCER_2              = (172), // RSCI2 Receive error event
    ELC_EVENT_SC_ELCRDRF_2            = (173), // RSCI2 Receive data full event
    ELC_EVENT_SC_ELCDCMF_2            = (174), // RSCI2 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_2            = (175), // RSCI2 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_2            = (176), // RSCI2 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_2            = (177), // RSCI2 Receive data compare unmatch event
    ELC_EVENT_SC_ELCER_3              = (178), // RSCI3 Receive error event
    ELC_EVENT_SC_ELCRDRF_3            = (179), // RSCI3 Receive data full event
    ELC_EVENT_SC_ELCDCMF_3            = (180), // RSCI3 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_3            = (181), // RSCI3 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_3            = (182), // RSCI3 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_3            = (183), // RSCI3 Receive data compare unmatch event
    ELC_EVENT_SC_ELCER_4              = (184), // RSCI4 Receive error event
    ELC_EVENT_SC_ELCRDRF_4            = (185), // RSCI4 Receive data full event
    ELC_EVENT_SC_ELCDCMF_4            = (186), // RSCI4 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_4            = (187), // RSCI4 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_4            = (188), // RSCI4 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_4            = (189), // RSCI4 Receive data compare unmatch event
    ELC_EVENT_SC_ELCER_5              = (190), // RSCI5 Receive error event
    ELC_EVENT_SC_ELCRDRF_5            = (191), // RSCI5 Receive data full event
    ELC_EVENT_SC_ELCDCMF_5            = (192), // RSCI5 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_5            = (193), // RSCI5 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_5            = (194), // RSCI5 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_5            = (195), // RSCI5 Receive data compare unmatch event
    ELC_EVENT_SC_ELCER_6              = (196), // RSCI6 Receive error event
    ELC_EVENT_SC_ELCRDRF_6            = (197), // RSCI6 Receive data full event
    ELC_EVENT_SC_ELCDCMF_6            = (198), // RSCI6 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_6            = (199), // RSCI6 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_6            = (200), // RSCI6 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_6            = (201), // RSCI6 Receive data compare unmatch event
    ELC_EVENT_SC_ELCER_7              = (202), // RSCI7 Receive error event
    ELC_EVENT_SC_ELCRDRF_7            = (203), // RSCI7 Receive data full event
    ELC_EVENT_SC_ELCDCMF_7            = (204), // RSCI7 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_7            = (205), // RSCI7 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_7            = (206), // RSCI7 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_7            = (207), // RSCI7 Receive data compare unmatch event
    ELC_EVENT_SC_ELCER_8              = (208), // RSCI8 Receive error event
    ELC_EVENT_SC_ELCRDRF_8            = (209), // RSCI8 Receive data full event
    ELC_EVENT_SC_ELCDCMF_8            = (210), // RSCI8 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_8            = (211), // RSCI8 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_8            = (212), // RSCI8 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_8            = (213), // RSCI8 Receive data compare unmatch event
    ELC_EVENT_SC_ELCER_9              = (214), // RSCI9 Receive error event
    ELC_EVENT_SC_ELCRDRF_9            = (215), // RSCI9 Receive data full event
    ELC_EVENT_SC_ELCDCMF_9            = (216), // RSCI9 Receive data compare match event
    ELC_EVENT_SC_ELCTDRE_9            = (217), // RSCI9 Transmit data empty event
    ELC_EVENT_SC_ELCTEND_9            = (218), // RSCI9 Rransmit end event
    ELC_EVENT_SC_ELCDCUF_9            = (219), // RSCI9 Receive data compare unmatch event
    ELC_EVENT_RIIC_CH0_IIC_ELCERRP    = (220), // RIIC0 ERRP ELC signal
    ELC_EVENT_RIIC_CH0_IIC_ELCTDREP   = (221), // RIIC0 TDREP ELC signal
    ELC_EVENT_RIIC_CH0_IIC_ELCRDRFP   = (222), // RIIC0 RDRF ELC signal
    ELC_EVENT_RIIC_CH0_IIC_ELCTENDP   = (223), // RIIC0 TEND ELC signal
    ELC_EVENT_RIIC_CH1_IIC_ELCERRP    = (224), // RIIC1 ERRP ELC signal
    ELC_EVENT_RIIC_CH1_IIC_ELCTDREP   = (225), // RIIC1 TDREP ELC signal
    ELC_EVENT_RIIC_CH1_IIC_ELCRDRFP   = (226), // RIIC1 RDRF ELC signal
    ELC_EVENT_RIIC_CH1_IIC_ELCTENDP   = (227), // RIIC1 TEND ELC signal
    ELC_EVENT_RIIC_CH2_IIC_ELCERRP    = (228), // RIIC2 ERRP ELC signal
    ELC_EVENT_RIIC_CH2_IIC_ELCTDREP   = (229), // RIIC2 TDREP ELC signal
    ELC_EVENT_RIIC_CH2_IIC_ELCRDRFP   = (230), // RIIC2 RDRF ELC signal
    ELC_EVENT_RIIC_CH2_IIC_ELCTENDP   = (231), // RIIC2 TEND ELC signal
    ELC_EVENT_RIIC_CH3_IIC_ELCERRP    = (232), // RIIC3 ERRP ELC signal
    ELC_EVENT_RIIC_CH3_IIC_ELCTDREP   = (233), // RIIC3 TDREP ELC signal
    ELC_EVENT_RIIC_CH3_IIC_ELCRDRFP   = (234), // RIIC3 RDRF ELC signal
    ELC_EVENT_RIIC_CH3_IIC_ELCTENDP   = (235), // RIIC3 TEND ELC signal
    ELC_EVENT_RIIC_CH4_IIC_ELCERRP    = (236), // RIIC4 ERRP ELC signal
    ELC_EVENT_RIIC_CH4_IIC_ELCTDREP   = (237), // RIIC4 TDREP ELC signal
    ELC_EVENT_RIIC_CH4_IIC_ELCRDRFP   = (238), // RIIC4 RDRF ELC signal
    ELC_EVENT_RIIC_CH4_IIC_ELCTENDP   = (239), // RIIC4 TEND ELC signal
    ELC_EVENT_RIIC_CH5_IIC_ELCERRP    = (240), // RIIC5 ERRP ELC signal
    ELC_EVENT_RIIC_CH5_IIC_ELCTDREP   = (241), // RIIC5 TDREP ELC signal
    ELC_EVENT_RIIC_CH5_IIC_ELCRDRFP   = (242), // RIIC5 RDRF ELC signal
    ELC_EVENT_RIIC_CH5_IIC_ELCTENDP   = (243), // RIIC5 TEND ELC signal
    ELC_EVENT_RIIC_CH6_IIC_ELCERRP    = (244), // RIIC6 ERRP ELC signal
    ELC_EVENT_RIIC_CH6_IIC_ELCTDREP   = (245), // RIIC6 TDREP ELC signal
    ELC_EVENT_RIIC_CH6_IIC_ELCRDRFP   = (246), // RIIC6 RDRF ELC signal
    ELC_EVENT_RIIC_CH6_IIC_ELCTENDP   = (247), // RIIC6 TEND ELC signal
    ELC_EVENT_RIIC_CH7_IIC_ELCERRP    = (248), // RIIC7 ERRP ELC signal
    ELC_EVENT_RIIC_CH7_IIC_ELCTDREP   = (249), // RIIC7 TDREP ELC signal
    ELC_EVENT_RIIC_CH7_IIC_ELCRDRFP   = (250), // RIIC7 RDRF ELC signal
    ELC_EVENT_RIIC_CH7_IIC_ELCTENDP   = (251), // RIIC7 TEND ELC signal
    ELC_EVENT_RIIC_CH8_IIC_ELCERRP    = (252), // RIIC8 ERRP ELC signal
    ELC_EVENT_RIIC_CH8_IIC_ELCTDREP   = (253), // RIIC8 TDREP ELC signal
    ELC_EVENT_RIIC_CH8_IIC_ELCRDRFP   = (254), // RIIC8 RDRF ELC signal
    ELC_EVENT_RIIC_CH8_IIC_ELCTENDP   = (255), // RIIC8 TEND ELC signal
    ELC_EVENT_ADC0_ADA_ADELCREQ       = (256), // ADC0 Scan end event
    ELC_EVENT_ADC0_ADA_ELCCONDMTCH    = (257), // ADC0 Compare match
    ELC_EVENT_ADC0_ADA_ELCCONDUNMTCH  = (258), // ADC0 Compare mis-match
    ELC_EVENT_RTC_ELCALM              = (259), // RTC Alarm out signal for event link controller
    ELC_EVENT_RTC_ELCCUP              = (260), // RTC Carry signal for event link controller
    ELC_EVENT_RTC_ELCPRD              = (261), // RTC Periodically generated signal for event link controller
    ELC_EVENT_UB1_TEI_N               = (262), // SCIF transmission end interrupt signal
    ELC_EVENT_UB1_RXI_EDGE_N          = (263), // SCIF reception data full interrupt signal
    ELC_EVENT_UB1_TXI_EDGE_N          = (264), // SCIF transmission data empty interrupt signal
    ELC_EVENT_GPT_U0_GPT_GTCIH_N_0    = (265), // GPT0 A and B both high interrupt 0
    ELC_EVENT_GPT_U0_GPT_GTCIH_N_1    = (266), // GPT0 A and B both high interrupt 1
    ELC_EVENT_GPT_U0_GPT_GTCIH_N_2    = (267), // GPT0 A and B both high interrupt 2
    ELC_EVENT_GPT_U0_GPT_GTCIH_N_3    = (268), // GPT0 A and B both high interrupt 3
    ELC_EVENT_GPT_U0_GPT_GTCIH_N_4    = (269), // GPT0 A and B both high interrupt 4
    ELC_EVENT_GPT_U0_GPT_GTCIH_N_5    = (270), // GPT0 A and B both high interrupt 5
    ELC_EVENT_GPT_U0_GPT_GTCIH_N_6    = (271), // GPT0 A and B both high interrupt 6
    ELC_EVENT_GPT_U0_GPT_GTCIH_N_7    = (272), // GPT0 A and B both high interrupt 7
    ELC_EVENT_GPT_U0_GPT_GTCIL_N_0    = (273), // GPT0 A and B both low interrupt 0
    ELC_EVENT_GPT_U0_GPT_GTCIL_N_1    = (274), // GPT0 A and B both low interrupt 1
    ELC_EVENT_GPT_U0_GPT_GTCIL_N_2    = (275), // GPT0 A and B both low interrupt 2
    ELC_EVENT_GPT_U0_GPT_GTCIL_N_3    = (276), // GPT0 A and B both low interrupt 3
    ELC_EVENT_GPT_U0_GPT_GTCIL_N_4    = (277), // GPT0 A and B both low interrupt 4
    ELC_EVENT_GPT_U0_GPT_GTCIL_N_5    = (278), // GPT0 A and B both low interrupt 5
    ELC_EVENT_GPT_U0_GPT_GTCIL_N_6    = (279), // GPT0 A and B both low interrupt 6
    ELC_EVENT_GPT_U0_GPT_GTCIL_N_7    = (280), // GPT0 A and B both low interrupt 7
    ELC_EVENT_GPT_U0_GPT_ELCCMPA_0    = (281), // GPT0 Input capture/compare match 0 of the GTCCRA register
    ELC_EVENT_GPT_U0_GPT_ELCCMPA_1    = (282), // GPT0 Input capture/compare match 1 of the GTCCRA register
    ELC_EVENT_GPT_U0_GPT_ELCCMPA_2    = (283), // GPT0 Input capture/compare match 2 of the GTCCRA register
    ELC_EVENT_GPT_U0_GPT_ELCCMPA_3    = (284), // GPT0 Input capture/compare match 3 of the GTCCRA register
    ELC_EVENT_GPT_U0_GPT_ELCCMPA_4    = (285), // GPT0 Input capture/compare match 4 of the GTCCRA register
    ELC_EVENT_GPT_U0_GPT_ELCCMPA_5    = (286), // GPT0 Input capture/compare match 5 of the GTCCRA register
    ELC_EVENT_GPT_U0_GPT_ELCCMPA_6    = (287), // GPT0 Input capture/compare match 6 of the GTCCRA register
    ELC_EVENT_GPT_U0_GPT_ELCCMPA_7    = (288), // GPT0 Input capture/compare match 7 of the GTCCRA register
    ELC_EVENT_GPT_U0_GPT_ELCCMPB_0    = (289), // GPT0 Input capture/compare match 0 of the GTCCRB register
    ELC_EVENT_GPT_U0_GPT_ELCCMPB_1    = (290), // GPT0 Input capture/compare match 1 of the GTCCRB register
    ELC_EVENT_GPT_U0_GPT_ELCCMPB_2    = (291), // GPT0 Input capture/compare match 2 of the GTCCRB register
    ELC_EVENT_GPT_U0_GPT_ELCCMPB_3    = (292), // GPT0 Input capture/compare match 3 of the GTCCRB register
    ELC_EVENT_GPT_U0_GPT_ELCCMPB_4    = (293), // GPT0 Input capture/compare match 4 of the GTCCRB register
    ELC_EVENT_GPT_U0_GPT_ELCCMPB_5    = (294), // GPT0 Input capture/compare match 5 of the GTCCRB register
    ELC_EVENT_GPT_U0_GPT_ELCCMPB_6    = (295), // GPT0 Input capture/compare match 6 of the GTCCRB register
    ELC_EVENT_GPT_U0_GPT_ELCCMPB_7    = (296), // GPT0 Input capture/compare match 7 of the GTCCRB register
    ELC_EVENT_GPT_U0_GPT_ELCCMPC_0    = (297), // GPT0 Input capture/compare match 0 of the GTCCRC register
    ELC_EVENT_GPT_U0_GPT_ELCCMPC_1    = (298), // GPT0 Input capture/compare match 1 of the GTCCRC register
    ELC_EVENT_GPT_U0_GPT_ELCCMPC_2    = (299), // GPT0 Input capture/compare match 2 of the GTCCRC register
    ELC_EVENT_GPT_U0_GPT_ELCCMPC_3    = (300), // GPT0 Input capture/compare match 3 of the GTCCRC register
    ELC_EVENT_GPT_U0_GPT_ELCCMPC_4    = (301), // GPT0 Input capture/compare match 4 of the GTCCRC register
    ELC_EVENT_GPT_U0_GPT_ELCCMPC_5    = (302), // GPT0 Input capture/compare match 5 of the GTCCRC register
    ELC_EVENT_GPT_U0_GPT_ELCCMPC_6    = (303), // GPT0 Input capture/compare match 6 of the GTCCRC register
    ELC_EVENT_GPT_U0_GPT_ELCCMPC_7    = (304), // GPT0 Input capture/compare match 7 of the GTCCRC register
    ELC_EVENT_GPT_U0_GPT_ELCCMPD_0    = (305), // GPT0 Input capture/compare match 0 of the GTCCRD register
    ELC_EVENT_GPT_U0_GPT_ELCCMPD_1    = (306), // GPT0 Input capture/compare match 1 of the GTCCRD register
    ELC_EVENT_GPT_U0_GPT_ELCCMPD_2    = (307), // GPT0 Input capture/compare match 2 of the GTCCRD register
    ELC_EVENT_GPT_U0_GPT_ELCCMPD_3    = (308), // GPT0 Input capture/compare match 3 of the GTCCRD register
    ELC_EVENT_GPT_U0_GPT_ELCCMPD_4    = (309), // GPT0 Input capture/compare match 4 of the GTCCRD register
    ELC_EVENT_GPT_U0_GPT_ELCCMPD_5    = (310), // GPT0 Input capture/compare match 5 of the GTCCRD register
    ELC_EVENT_GPT_U0_GPT_ELCCMPD_6    = (311), // GPT0 Input capture/compare match 6 of the GTCCRD register
    ELC_EVENT_GPT_U0_GPT_ELCCMPD_7    = (312), // GPT0 Input capture/compare match 7 of the GTCCRD register
    ELC_EVENT_GPT_U0_GPT_ELCCMPE_0    = (313), // GPT0 Input capture/compare match 0 of the GTCCRE register
    ELC_EVENT_GPT_U0_GPT_ELCCMPE_1    = (314), // GPT0 Input capture/compare match 1 of the GTCCRE register
    ELC_EVENT_GPT_U0_GPT_ELCCMPE_2    = (315), // GPT0 Input capture/compare match 2 of the GTCCRE register
    ELC_EVENT_GPT_U0_GPT_ELCCMPE_3    = (316), // GPT0 Input capture/compare match 3 of the GTCCRE register
    ELC_EVENT_GPT_U0_GPT_ELCCMPE_4    = (317), // GPT0 Input capture/compare match 4 of the GTCCRE register
    ELC_EVENT_GPT_U0_GPT_ELCCMPE_5    = (318), // GPT0 Input capture/compare match 5 of the GTCCRE register
    ELC_EVENT_GPT_U0_GPT_ELCCMPE_6    = (319), // GPT0 Input capture/compare match 6 of the GTCCRE register
    ELC_EVENT_GPT_U0_GPT_ELCCMPE_7    = (320), // GPT0 Input capture/compare match 7 of the GTCCRE register
    ELC_EVENT_GPT_U0_GPT_ELCCMPF_0    = (321), // GPT0 Input capture/compare match 0 of the GTCCRF register
    ELC_EVENT_GPT_U0_GPT_ELCCMPF_1    = (322), // GPT0 Input capture/compare match 1 of the GTCCRF register
    ELC_EVENT_GPT_U0_GPT_ELCCMPF_2    = (323), // GPT0 Input capture/compare match 2 of the GTCCRF register
    ELC_EVENT_GPT_U0_GPT_ELCCMPF_3    = (324), // GPT0 Input capture/compare match 3 of the GTCCRF register
    ELC_EVENT_GPT_U0_GPT_ELCCMPF_4    = (325), // GPT0 Input capture/compare match 4 of the GTCCRF register
    ELC_EVENT_GPT_U0_GPT_ELCCMPF_5    = (326), // GPT0 Input capture/compare match 5 of the GTCCRF register
    ELC_EVENT_GPT_U0_GPT_ELCCMPF_6    = (327), // GPT0 Input capture/compare match 6 of the GTCCRF register
    ELC_EVENT_GPT_U0_GPT_ELCCMPF_7    = (328), // GPT0 Input capture/compare match 7 of the GTCCRF register
    ELC_EVENT_GPT_U0_GPT_ELCOVF_0     = (329), // GPT0 Overflow 0 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCOVF_1     = (330), // GPT0 Overflow 1 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCOVF_2     = (331), // GPT0 Overflow 2 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCOVF_3     = (332), // GPT0 Overflow 3 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCOVF_4     = (333), // GPT0 Overflow 4 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCOVF_5     = (334), // GPT0 Overflow 5 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCOVF_6     = (335), // GPT0 Overflow 6 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCOVF_7     = (336), // GPT0 Overflow 7 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCUDF_0     = (337), // GPT0 Underflow 0 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCUDF_1     = (338), // GPT0 Underflow 1 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCUDF_2     = (339), // GPT0 Underflow 2 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCUDF_3     = (340), // GPT0 Underflow 3 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCUDF_4     = (341), // GPT0 Underflow 4 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCUDF_5     = (342), // GPT0 Underflow 5 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCUDF_6     = (343), // GPT0 Underflow 6 of the GTCNT counter
    ELC_EVENT_GPT_U0_GPT_ELCUDF_7     = (344), // GPT0 Underflow 7 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_GTCIH_N_0    = (345), // GPT1 A and B both high interrupt 0
    ELC_EVENT_GPT_U1_GPT_GTCIH_N_1    = (346), // GPT1 A and B both high interrupt 1
    ELC_EVENT_GPT_U1_GPT_GTCIH_N_2    = (347), // GPT1 A and B both high interrupt 2
    ELC_EVENT_GPT_U1_GPT_GTCIH_N_3    = (348), // GPT1 A and B both high interrupt 3
    ELC_EVENT_GPT_U1_GPT_GTCIH_N_4    = (349), // GPT1 A and B both high interrupt 4
    ELC_EVENT_GPT_U1_GPT_GTCIH_N_5    = (350), // GPT1 A and B both high interrupt 5
    ELC_EVENT_GPT_U1_GPT_GTCIH_N_6    = (351), // GPT1 A and B both high interrupt 6
    ELC_EVENT_GPT_U1_GPT_GTCIH_N_7    = (352), // GPT1 A and B both high interrupt 7
    ELC_EVENT_GPT_U1_GPT_GTCIL_N_0    = (353), // GPT1 A and B both low interrupt 0
    ELC_EVENT_GPT_U1_GPT_GTCIL_N_1    = (354), // GPT1 A and B both low interrupt 1
    ELC_EVENT_GPT_U1_GPT_GTCIL_N_2    = (355), // GPT1 A and B both low interrupt 2
    ELC_EVENT_GPT_U1_GPT_GTCIL_N_3    = (356), // GPT1 A and B both low interrupt 3
    ELC_EVENT_GPT_U1_GPT_GTCIL_N_4    = (357), // GPT1 A and B both low interrupt 4
    ELC_EVENT_GPT_U1_GPT_GTCIL_N_5    = (358), // GPT1 A and B both low interrupt 5
    ELC_EVENT_GPT_U1_GPT_GTCIL_N_6    = (359), // GPT1 A and B both low interrupt 6
    ELC_EVENT_GPT_U1_GPT_GTCIL_N_7    = (360), // GPT1 A and B both low interrupt 7
    ELC_EVENT_GPT_U1_GPT_ELCCMPA_0    = (361), // GPT1 Input capture/compare match 0 of the GTCCRA register
    ELC_EVENT_GPT_U1_GPT_ELCCMPA_1    = (362), // GPT1 Input capture/compare match 1 of the GTCCRA register
    ELC_EVENT_GPT_U1_GPT_ELCCMPA_2    = (363), // GPT1 Input capture/compare match 2 of the GTCCRA register
    ELC_EVENT_GPT_U1_GPT_ELCCMPA_3    = (364), // GPT1 Input capture/compare match 3 of the GTCCRA register
    ELC_EVENT_GPT_U1_GPT_ELCCMPA_4    = (365), // GPT1 Input capture/compare match 4 of the GTCCRA register
    ELC_EVENT_GPT_U1_GPT_ELCCMPA_5    = (366), // GPT1 Input capture/compare match 5 of the GTCCRA register
    ELC_EVENT_GPT_U1_GPT_ELCCMPA_6    = (367), // GPT1 Input capture/compare match 6 of the GTCCRA register
    ELC_EVENT_GPT_U1_GPT_ELCCMPA_7    = (368), // GPT1 Input capture/compare match 7 of the GTCCRA register
    ELC_EVENT_GPT_U1_GPT_ELCCMPB_0    = (369), // GPT1 Input capture/compare match 0 of the GTCCRB register
    ELC_EVENT_GPT_U1_GPT_ELCCMPB_1    = (370), // GPT1 Input capture/compare match 1 of the GTCCRB register
    ELC_EVENT_GPT_U1_GPT_ELCCMPB_2    = (371), // GPT1 Input capture/compare match 2 of the GTCCRB register
    ELC_EVENT_GPT_U1_GPT_ELCCMPB_3    = (372), // GPT1 Input capture/compare match 3 of the GTCCRB register
    ELC_EVENT_GPT_U1_GPT_ELCCMPB_4    = (373), // GPT1 Input capture/compare match 4 of the GTCCRB register
    ELC_EVENT_GPT_U1_GPT_ELCCMPB_5    = (374), // GPT1 Input capture/compare match 5 of the GTCCRB register
    ELC_EVENT_GPT_U1_GPT_ELCCMPB_6    = (375), // GPT1 Input capture/compare match 6 of the GTCCRB register
    ELC_EVENT_GPT_U1_GPT_ELCCMPB_7    = (376), // GPT1 Input capture/compare match 7 of the GTCCRB register
    ELC_EVENT_GPT_U1_GPT_ELCCMPC_0    = (377), // GPT1 Compare match 0 with the GTCCRC register
    ELC_EVENT_GPT_U1_GPT_ELCCMPC_1    = (378), // GPT1 Compare match 1 with the GTCCRC register
    ELC_EVENT_GPT_U1_GPT_ELCCMPC_2    = (379), // GPT1 Compare match 2 with the GTCCRC register
    ELC_EVENT_GPT_U1_GPT_ELCCMPC_3    = (380), // GPT1 Compare match 3 with the GTCCRC register
    ELC_EVENT_GPT_U1_GPT_ELCCMPC_4    = (381), // GPT1 Compare match 4 with the GTCCRC register
    ELC_EVENT_GPT_U1_GPT_ELCCMPC_5    = (382), // GPT1 Compare match 5 with the GTCCRC register
    ELC_EVENT_GPT_U1_GPT_ELCCMPC_6    = (383), // GPT1 Compare match 6 with the GTCCRC register
    ELC_EVENT_GPT_U1_GPT_ELCCMPC_7    = (384), // GPT1 Compare match 7 with the GTCCRC register
    ELC_EVENT_GPT_U1_GPT_ELCCMPD_0    = (385), // GPT1 Compare match 0 with the GTCCRD register
    ELC_EVENT_GPT_U1_GPT_ELCCMPD_1    = (386), // GPT1 Compare match 1 with the GTCCRD register
    ELC_EVENT_GPT_U1_GPT_ELCCMPD_2    = (387), // GPT1 Compare match 2 with the GTCCRD register
    ELC_EVENT_GPT_U1_GPT_ELCCMPD_3    = (388), // GPT1 Compare match 3 with the GTCCRD register
    ELC_EVENT_GPT_U1_GPT_ELCCMPD_4    = (389), // GPT1 Compare match 4 with the GTCCRD register
    ELC_EVENT_GPT_U1_GPT_ELCCMPD_5    = (390), // GPT1 Compare match 5 with the GTCCRD register
    ELC_EVENT_GPT_U1_GPT_ELCCMPD_6    = (391), // GPT1 Compare match 6 with the GTCCRD register
    ELC_EVENT_GPT_U1_GPT_ELCCMPD_7    = (392), // GPT1 Compare match 7 with the GTCCRD register
    ELC_EVENT_GPT_U1_GPT_ELCCMPE_0    = (393), // GPT1 Compare match 0 with the GTCCRE register
    ELC_EVENT_GPT_U1_GPT_ELCCMPE_1    = (394), // GPT1 Compare match 1 with the GTCCRE register
    ELC_EVENT_GPT_U1_GPT_ELCCMPE_2    = (395), // GPT1 Compare match 2 with the GTCCRE register
    ELC_EVENT_GPT_U1_GPT_ELCCMPE_3    = (396), // GPT1 Compare match 3 with the GTCCRE register
    ELC_EVENT_GPT_U1_GPT_ELCCMPE_4    = (397), // GPT1 Compare match 4 with the GTCCRE register
    ELC_EVENT_GPT_U1_GPT_ELCCMPE_5    = (398), // GPT1 Compare match 5 with the GTCCRE register
    ELC_EVENT_GPT_U1_GPT_ELCCMPE_6    = (399), // GPT1 Compare match 6 with the GTCCRE register
    ELC_EVENT_GPT_U1_GPT_ELCCMPE_7    = (400), // GPT1 Compare match 7 with the GTCCRE register
    ELC_EVENT_GPT_U1_GPT_ELCCMPF_0    = (401), // GPT1 Compare match 0 with the GTCCRF register
    ELC_EVENT_GPT_U1_GPT_ELCCMPF_1    = (402), // GPT1 Compare match 1 with the GTCCRF register
    ELC_EVENT_GPT_U1_GPT_ELCCMPF_2    = (403), // GPT1 Compare match 2 with the GTCCRF register
    ELC_EVENT_GPT_U1_GPT_ELCCMPF_3    = (404), // GPT1 Compare match 3 with the GTCCRF register
    ELC_EVENT_GPT_U1_GPT_ELCCMPF_4    = (405), // GPT1 Compare match 4 with the GTCCRF register
    ELC_EVENT_GPT_U1_GPT_ELCCMPF_5    = (406), // GPT1 Compare match 5 with the GTCCRF register
    ELC_EVENT_GPT_U1_GPT_ELCCMPF_6    = (407), // GPT1 Compare match 6 with the GTCCRF register
    ELC_EVENT_GPT_U1_GPT_ELCCMPF_7    = (408), // GPT1 Compare match 7 with the GTCCRF register
    ELC_EVENT_GPT_U1_GPT_ELCOVF_0     = (409), // GPT1 Overflow 0 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCOVF_1     = (410), // GPT1 Overflow 1 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCOVF_2     = (411), // GPT1 Overflow 2 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCOVF_3     = (412), // GPT1 Overflow 3 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCOVF_4     = (413), // GPT1 Overflow 4 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCOVF_5     = (414), // GPT1 Overflow 5 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCOVF_6     = (415), // GPT1 Overflow 6 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCOVF_7     = (416), // GPT1 Overflow 7 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCUDF_0     = (417), // GPT1 Underflow 0 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCUDF_1     = (418), // GPT1 Underflow 1 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCUDF_2     = (419), // GPT1 Underflow 2 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCUDF_3     = (420), // GPT1 Underflow 3 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCUDF_4     = (421), // GPT1 Underflow 4 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCUDF_5     = (422), // GPT1 Underflow 5 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCUDF_6     = (423), // GPT1 Underflow 6 of the GTCNT counter
    ELC_EVENT_GPT_U1_GPT_ELCUDF_7     = (424), // GPT1 Underflow 7 of the GTCNT counter
    ELC_EVENT_RI3C_ELCCOMMU           = (425), // I3C Communication event
    ELC_EVENT_RI3C_ELCRESP            = (426), // I3C Response buffer full event
    ELC_EVENT_RI3C_ELCCMD             = (427), // I3C Command buffer empty event
    ELC_EVENT_RI3C_ELCIBI             = (428), // I3C IBI status buffer full event
    ELC_EVENT_RI3C_ELCRX              = (429), // I3C Rx data buffer full event
    ELC_EVENT_RI3C_ELCTX              = (430), // I3C Tx data buffer empty event
    ELC_EVENT_RI3C_ELCRCV             = (431), // I3C Receive status buffer full event
    ELC_EVENT_RI3C_ELCTEND            = (436), // I3C Transmit end event
    ELC_EVENT_RI3C_ELCSTEV            = (437), // I3C Synchronous Timing Event
    ELC_EVENT_RI3C_MREFOVF            = (438), // I3C MREF Counter Overflow
    ELC_EVENT_RI3C_MREFCPT            = (439), // I3C MREF Capture Event
    ELC_EVENT_RI3C_ELCAMEV            = (440), // I3C Additional Masterinitiated bus Event
    ELC_EVENT_GBETH_PORT1_PTP_PPS_O_0 = (441), // GBETH PORT1 Event (INPUT) 0
    ELC_EVENT_GBETH_PORT1_PTP_PPS_O_1 = (442), // GBETH PORT1 Event (INPUT) 1
    ELC_EVENT_GBETH_PORT1_PTP_PPS_O_2 = (443), // GBETH PORT1 Event (INPUT) 2
    ELC_EVENT_GBETH_PORT1_PTP_PPS_O_3 = (444), // GBETH PORT1 Event (INPUT) 3
    ELC_EVENT_GBETH_PORT0_PTP_PPS_O_0 = (445), // GBETH PORT0 Event (INPUT) 0
    ELC_EVENT_GBETH_PORT0_PTP_PPS_O_1 = (446), // GBETH PORT0 Event (INPUT) 1
    ELC_EVENT_GBETH_PORT0_PTP_PPS_O_2 = (447), // GBETH PORT0 Event (INPUT) 2
    ELC_EVENT_GBETH_PORT0_PTP_PPS_O_3 = (448), // GBETH PORT0 Event (INPUT) 3
    ELC_EVENT_ISU_INT_FRE0            = (449), // ISU Frame end interrupt 0
    ELC_EVENT_ISU_INT_FRE1            = (450), // ISU Frame end interrupt 1
    ELC_EVENT_ISU_INT_FRE2            = (451), // ISU Frame end interrupt 2
    ELC_EVENT_ISU_INT_FRE3            = (452), // ISU Frame end interrupt 3
    ELC_EVENT_DRP1_ELCO               = (453), // DRP1 Interrupt signal for ELC
    ELC_EVENT_DRP_AI_ELCO             = (454), // DRP-AI Interrupt signal for ELC
    ELC_EVENT_DRP_AI_MAC_ELCO         = (455), // DRP-AI Interrupt signal for ELC
    ELC_EVENT_NONE
} elc_event_t;

/* ELC-Related Definitions */
#define BSP_ELC_ELC_SSEL_NUM              (15)
#define BSP_ELC_EVENT_MASK_NUM            (4U)
#define BSP_ELC_EVENT_SELECT0_MASK        (R_INTC_EVTSEL0_EC_SEL0_Msk)
#define BSP_ELC_EVENT_SELECT1_MASK        (R_INTC_EVTSEL0_EC_SEL1_Msk)
#define BSP_ELC_EVENT_SELECT2_MASK        (R_INTC_EVTSEL0_EC_SEL2_Msk)
#define BSP_ELC_EVENT_SELECT0_POSITION    (R_INTC_EVTSEL0_EC_SEL0_Pos)
#define BSP_ELC_EVENT_SELECT1_POSITION    (R_INTC_EVTSEL0_EC_SEL1_Pos)
#define BSP_ELC_EVENT_SELECT2_POSITION    (R_INTC_EVTSEL0_EC_SEL2_Pos)
#define BSP_ELC_EVENT_SELECT_REG          (&R_INTC->EVTSEL0)
#define BSP_ELC_PERIPHERAL_0_MASK         (0xFFFFFFFFU) // ELC event source no.0 to 31 available on this MPU
#define BSP_ELC_PERIPHERAL_1_MASK         (0x000007FFU) // ELC event source no.32 to 63 available on this MPU.
#define BSP_ELC_PERIPHERAL_2_MASK         (0x00000000U) // ELC event source no.64 to 95 available on this MPU.
#define BSP_ELC_PERIPHERAL_3_MASK         (0x00000000U) // ELC event source no.96 to 127 available on this MPU.
#define BSP_ELC_SOFTWARE_EVENT_MASK       (R_INTC_SWEVT_SWE0_Msk)
#define BSP_ELC_SOFTWARE_EVENT_REG        (&R_INTC->SWEVT)

/** @} (end addtogroup BSP_MCU_RZV2H) */

#endif
