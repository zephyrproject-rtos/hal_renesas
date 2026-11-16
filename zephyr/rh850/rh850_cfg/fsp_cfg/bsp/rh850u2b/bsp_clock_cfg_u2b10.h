/*
* Copyright (c) 2025 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_CLOCK_CFG_U2B10_BGA292_H_
#define BSP_CLOCK_CFG_U2B10_BGA292_H_
#ifndef BSP_CFG_CLOCKS_SECURE
 #define BSP_CFG_CLOCKS_SECURE                          (0)
#endif

#ifndef BSP_CFG_CLOCKS_OVERRIDE
 #define BSP_CFG_CLOCKS_OVERRIDE                        (0)
#endif

#ifndef BSP_CFG_CLK_MOSC_VALUE
 #define BSP_CFG_CLK_MOSC_VALUE                         (BSP_CLKCTL_CLK_MOSC_20MHZ) /* MainOSC: 20MHz */
#endif

#ifndef BSP_CFG_CLK_MOSC_SELECT_STANDBY_MODE
 #if defined(CONFIG_RH850_CLOCK_MOSC_CONTINUE_IN_STANDBY)
  #define BSP_CFG_CLK_MOSC_SELECT_STANDBY_MODE         (1)                         /* MainOSC-STPM: Continue */
 #else
  #define BSP_CFG_CLK_MOSC_SELECT_STANDBY_MODE         (0)                         /* MainOSC-STPM: Stop */
 #endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_PLL_HZ
 #define BSP_CFG_CLOCK_CLK_PLL_HZ                       (800000000)                 /* PLLO: 800MHz */
#endif

#ifndef BSP_CFG_CLK_PLL_SELECT_STANDBY_MODE
 #if defined(CONFIG_RH850_CLOCK_PLL_CONTINUE_IN_STANDBY)
  #define BSP_CFG_CLK_PLL_SELECT_STANDBY_MODE          (1)                         /* PLL-STPM: Continue */
 #else
  #define BSP_CFG_CLK_PLL_SELECT_STANDBY_MODE          (0)                         /* PLL-STPM: Stop */
 #endif
#endif

#ifndef BSP_CFG_CLK_HSOSC_SELECT_STANDBY_MODE
 #if defined(CONFIG_RH850_CLOCK_HSOSC_CONTINUE_IN_STANDBY)
  #define BSP_CFG_CLK_HSOSC_SELECT_STANDBY_MODE        (1)                         /* HSOSC-STPM: Continue */
 #else
  #define BSP_CFG_CLK_HSOSC_SELECT_STANDBY_MODE        (0)                         /* HSOSC-STPM: Stop */
 #endif
#endif

#ifndef BSP_CFG_CLOCK_CLK_CPU_VALUE
 #define BSP_CFG_CLOCK_CLK_CPU_VALUE                    (400000000)                 /* CPU: 400000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_SSCG_HZ
 #define BSP_CFG_CLOCK_CLK_SSCG_HZ                      (800000000)                 /* SSCG: 800000000Hz */
#endif

#ifndef BSP_CFG_CLK_SSCG_MODULATION_MODE
 #define BSP_CFG_CLK_SSCG_MODULATION_MODE               (0)                         /* SSCG modulation: Disable */
#endif

#ifndef BSP_CFG_CLK_SSCG_MODULATION_VALUE
 #define BSP_CFG_CLK_SSCG_MODULATION_VALUE              (30)                        /* SSCG0 modulation (20MHz): 20.0 KHz */
#endif

#ifndef BSP_CFG_CLK_SSCG_MODULATION_DITHERED_RANGE
 #define BSP_CFG_CLK_SSCG_MODULATION_DITHERED_RANGE     (0)                         /* SSCG modulation dithered range: -1% */
#endif

#ifndef BSP_CFG_CLOCK_CLK_SSCG1_HZ
 #define BSP_CFG_CLOCK_CLK_SSCG1_HZ                     (0)                         /* SSCG1: 0Hz */
#endif

#ifndef BSP_CFG_CLK_SSCG1_MODULATION_MODE
 #define BSP_CFG_CLK_SSCG1_MODULATION_MODE              (0)                         /* SSCG1 modulation: Disable */
#endif

#ifndef BSP_CFG_CLK_SSCG1_MODULATION_VALUE
 #define BSP_CFG_CLK_SSCG1_MODULATION_VALUE             (30)                        /* SSCG1 modulation (20MHz): 20.0 KHz */
#endif

#ifndef BSP_CFG_CLK_SSCG1_MODULATION_DITHERED_RANGE
 #define BSP_CFG_CLK_SSCG1_MODULATION_DITHERED_RANGE    (0)                         /* SSCG1 modulation dithered range: -1% */
#endif

#ifndef BSP_CFG_CLOCK_CLK_HVIOSC_HZ
 #define BSP_CFG_CLOCK_CLK_HVIOSC_HZ                    (16000000)                  /* CLK_HVIOSC: 16000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_LSIOSC_HZ
 #define BSP_CFG_CLOCK_CLK_LSIOSC_HZ                    (240000)                    /* CLK_LSIOSC: 240000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_HSIOSC_HZ
 #define BSP_CFG_CLOCK_CLK_HSIOSC_HZ                    (200000000)                 /* CLK_HSIOSC: 200000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_MOSC_HZ
 #define BSP_CFG_CLOCK_CLK_MOSC_HZ                      (20000000)                  /* CLK_MOSC: 20000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_EMG_SRC
 #define BSP_CFG_CLOCK_CLK_EMG_SRC                      (1)                         /* CLK_EMG: CLK_HSIOSC/20 */
#endif

#ifndef BSP_CFG_CLOCK_CLK_EMG_HZ
 #define BSP_CFG_CLOCK_CLK_EMG_HZ                       (10000000)                  /* CLK_EMG: 10000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_ECMCNT_HZ
 #define BSP_CFG_CLOCK_CLK_ECMCNT_HZ                    (10000000)                  /* CLK_ECMCNT: 10000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_IOSC_SRC
 #define BSP_CFG_CLOCK_CLK_IOSC_SRC                     (1)                         /* CLK_IOSC: CLK_HSIOSC */
#endif

#ifndef BSP_CFG_CLOCK_CLK_IOSC_HZ
 #define BSP_CFG_CLOCK_CLK_IOSC_HZ                      (200000000)                 /* CLK_IOSC: 200000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK0O_SRC
 #define BSP_CFG_CLOCK_EXTCLK0O_SRC                     (4)                         /* EXTCLK0O: CLK_HSB */
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK0O_DIV
 #define BSP_CFG_CLOCK_EXTCLK0O_DIV                     0                           /* EXTCLK0 Div: Disabled */
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK0O_HZ
 #define BSP_CFG_CLOCK_EXTCLK0O_HZ                      (0)                         /* EXTCLK0O: 0Hz */
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK1O_SRC
 #define BSP_CFG_CLOCK_EXTCLK1O_SRC                     (4)                         /* EXTCLK1O: CLK_HSB */
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK1O_DIV
 #define BSP_CFG_CLOCK_EXTCLK1O_DIV                     0                           /* EXTCLK1 Div: Disabled */
#endif

#ifndef BSP_CFG_CLOCK_EXTCLK1O_HZ
 #define BSP_CFG_CLOCK_EXTCLK1O_HZ                      (0)                         /* EXTCLK1O: 0Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_MSPI_SRC
 #define BSP_CFG_CLOCK_CLK_MSPI_SRC                     (2)                         /* CLK_MSPI: CLKC_HSB */
#endif

#ifndef BSP_CFG_CLOCK_CLK_MSPI_HZ
 #define BSP_CFG_CLOCK_CLK_MSPI_HZ                      (80000000)                  /* CLK_MSPI: 80000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_RLIN3_SRC
 #define BSP_CFG_CLOCK_CLK_RLIN3_SRC                    (1)                         /* CLK_RLIN3: CLKC_HSB */
#endif

#ifndef BSP_CFG_CLOCK_CLK_RLIN3_HZ
 #define BSP_CFG_CLOCK_CLK_RLIN3_HZ                     (80000000)                  /* CLK_RLIN3: 80000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_CH23_RLIN3_SRC
 #define BSP_CFG_CLOCK_CLK_CH23_RLIN3_SRC               (1)                         /* CLK_CH23_RLIN3: CLKC_HBUS */
#endif

#ifndef BSP_CFG_CLOCK_CLK_CH23_RLIN3_HZ
 #define BSP_CFG_CLOCK_CLK_CH23_RLIN3_HZ                (100000000)                 /* CLK_CH23_RLIN3: 100000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_GTM_SRC
 #define BSP_CFG_CLOCK_CLK_GTM_SRC                      (0)                         /* CLK_GTM: CLKC_SBUS */
#endif

#ifndef BSP_CFG_CLOCK_CLK_GTM_HZ
 #define BSP_CFG_CLOCK_CLK_GTM_HZ                       (200000000)                 /* CLK_GTM: 200000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_WDTB_SRC
 #define BSP_CFG_CLOCK_CLK_WDTB_SRC                     (1)                         /* CLK_WDTB: CLK_HSIOSC_DIV_640 */
#endif

#ifndef BSP_CFG_CLOCK_CLK_WDTB_HZ
 #define BSP_CFG_CLOCK_CLK_WDTB_HZ                      (312500)                    /* CLK_WDTB: 312500Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_CANFD_C_SRC
 #define BSP_CFG_CLOCK_CLK_CANFD_C_SRC                  (1)                         /* CLK_CANFD_C: CLKC_HSB */
#endif

#ifndef BSP_CFG_CLOCK_CLK_CANFD_C_HZ
 #define BSP_CFG_CLOCK_CLK_CANFD_C_HZ                   (80000000)                  /* CLK_CANFD_C: 80000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_CANFD_XIN_SRC
 #define BSP_CFG_CLOCK_CLK_CANFD_XIN_SRC                (1)                         /* CLK_CANFD_XIN: CLK_MOSC */
#endif

#ifndef BSP_CFG_CLOCK_CLK_CANFD_XIN_HZ
 #define BSP_CFG_CLOCK_CLK_CANFD_XIN_HZ                 (20000000)                  /* CLK_CANFD_XIN: 20000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CKS_CLEANC_SRC
 #define BSP_CFG_CLOCK_CKS_CLEANC_SRC                   (0)                         /* CKS_CLEANC: CLK_PLLO */
#endif

#ifndef BSP_CFG_CLOCK_CLKC_CPU_HZ
 #define BSP_CFG_CLOCK_CLKC_CPU_HZ                      (400000000)                 /* CLKC_CPU: 400000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLKC_SBUS_HZ
 #define BSP_CFG_CLOCK_CLKC_SBUS_HZ                     (200000000)                 /* CLKC_SBUS: 200000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLKC_HBUS_HZ
 #define BSP_CFG_CLOCK_CLKC_HBUS_HZ                     (100000000)                 /* CLKC_HBUS: 100000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLKC_UHSB_HZ
 #define BSP_CFG_CLOCK_CLKC_UHSB_HZ                     (160000000)                 /* CLKC_UHSB: 160000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLKC_SHSB_HZ
 #define BSP_CFG_CLOCK_CLKC_SHSB_HZ                     (133333333)                 /* CLKC_SHSB: 133333333Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLKC_HSB_HZ
 #define BSP_CFG_CLOCK_CLKC_HSB_HZ                      (80000000)                  /* CLKC_HSB: 80000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLKC_LSB_HZ
 #define BSP_CFG_CLOCK_CLKC_LSB_HZ                      (40000000)                  /* CLKC_LSB: 40000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CKS_SSCGC_SRC
 #define BSP_CFG_CLOCK_CKS_SSCGC_SRC                    (0)                         /* CKS_SSCGC: CLK_SSCGO */
#endif

#ifndef BSP_CFG_CLOCK_CLK_SYS_SSCG_HZ
 #define BSP_CFG_CLOCK_CLK_SYS_SSCG_HZ                  (800000000)                 /* CLK_SYS_SSCG: 800000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_CPU_HZ
 #define BSP_CFG_CLOCK_CLK_CPU_HZ                       (400000000)                 /* CLK_CPU: 400000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_SBUS_HZ
 #define BSP_CFG_CLOCK_CLK_SBUS_HZ                      (200000000)                 /* CLK_SBUS: 200000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_HBUS_HZ
 #define BSP_CFG_CLOCK_CLK_HBUS_HZ                      (100000000)                 /* CLK_HBUS: 100000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_UHSB_HZ
 #define BSP_CFG_CLOCK_CLK_UHSB_HZ                      (160000000)                 /* CLK_UHSB: 160000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_HSB_HZ
 #define BSP_CFG_CLOCK_CLK_HSB_HZ                       (80000000)                  /* CLK_HSB: 80000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_LSB_HZ
 #define BSP_CFG_CLOCK_CLK_LSB_HZ                       (40000000)                  /* CLK_LSB: 40000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLKC_SWDT_SRC
 #define BSP_CFG_CLOCK_CLKC_SWDT_SRC                    (0)                         /* CLKC_SWDT: CLK_HSIOSC / 20 */
#endif

#ifndef BSP_CFG_CLOCK_CLKC_SWDT_HZ
 #define BSP_CFG_CLOCK_CLKC_SWDT_HZ                     (10000000)                  /* CLKC_SWDT: 10000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CKS_SSCG1C_SRC
 #define BSP_CFG_CLOCK_CKS_SSCG1C_SRC                   (1)                         /* CKS_SSCG1C: CLK_IOSC */
#endif

#ifndef BSP_CFG_CLOCK_CLK_SYS_SSCG1_HZ
 #define BSP_CFG_CLOCK_CLK_SYS_SSCG1_HZ                 (200000000)                 /* CLK_SYS_SSCG1: 200000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_DFP_HZ
 #define BSP_CFG_CLOCK_CLK_DFP_HZ                       (400000000)                 /* CLK_DFP: 400000000Hz */
#endif

#ifndef BSP_CFG_CLOCK_CLK_DFP_DIV_2_HZ
 #define BSP_CFG_CLOCK_CLK_DFP_DIV_2_HZ                 (200000000)                 /* CLK_DFP/2: 200000000Hz */
#endif

#endif /* BSP_CLOCK_CFG_H_ */
