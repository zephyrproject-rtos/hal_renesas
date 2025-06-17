/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __RZG2L_DEF_H__
#define __RZG2L_DEF_H__

#define RZG2L_BOOT_ROM_BASE         (0x00000000)
#define RZG2L_MSRAM_BASE            (0x00010000)
#define RZG2L_ASRAM_BASE            (0x00020000)
#define RZG2L_DEVICE_BASE           (0x10000000)
#define RZG2L_SCIF0_BASE            (0x1004B800)
#define RZG2L_SPIMULT_BASE          (0x10060000)
#define RZG2L_SPIMULT_WBUF_BASE     (0x10070000)
#define RZG2L_SYC_BASE              (0x11000000)
#define RZG2L_CPG_BASE              (0x11010000)
#define RZG2L_SYSC_BASE             (0x11020000)
#define RZG2L_GPIO_BASE             (0x11030000)
#define RZG2L_TZC_ASRAM_BASE        (0x11040000)
#define RZG2L_TZC_MSRAM_BASE        (0x11050000)
#define RZG2L_TZC_SPI_BASE          (0x11060000)
#define RZG2L_TZC_DDR_BASE          (0x11070000)
#define RZG2L_DDR_PHY_BASE          (0x11400000)
#define RZG2L_DDR_MEMC_BASE         (0x11410000)
#define RZG2L_OTP_BASE              (0x11860000)
#define RZG2L_GIC_BASE              (0x11900000)
#define RZG2L_SD0_BASE              (0x11C00000)
#define RZG2L_SPIROM_BASE           (0x20000000)
#define RZG2L_DDR1_BASE             (0x40000000)
#define RZG2L_DDR2_BASE             (0x80000000)
#define RZG2L_DDR3_BASE             (0x100000000)

#define RZG2L_GICD_BASE             (RZG2L_GIC_BASE)
#define RZG2L_GICR_BASE             (RZG2L_GIC_BASE + 0x00040000)

#define RZG2L_SRAM_BASE             (RZG2L_MSRAM_BASE)

#define RZG2L_BOOT_ROM_SIZE         (0x00010000 - RZG2L_BOOT_ROM_BASE)
#define RZG2L_MSRAM_SIZE            (0x00020000 - RZG2L_MSRAM_BASE)
#define RZG2L_ASRAM_SIZE            (0x00030000 - RZG2L_ASRAM_BASE)
#define RZG2L_SRAM_SIZE             (RZG2L_MSRAM_SIZE + RZG2L_ASRAM_SIZE)
#define RZG2L_DEVICE_SIZE           (0x15000000 - RZG2L_DEVICE_BASE)
#define RZG2L_SPIROM_SIZE           (0x30000000 - RZG2L_SPIROM_BASE)
#define RZG2L_DDR1_SIZE             (RZG2L_DDR2_BASE - RZG2L_DDR1_BASE)
#define RZG2L_DDR2_SIZE             (RZG2L_DDR3_BASE - RZG2L_DDR2_BASE)

#define RZG2L_SPIROM_FIP_BASE       (RZG2L_SPIROM_BASE + 0x0001D200)
#define RZG2L_SPIROM_FIP_SIZE       (0x30000000 - RZG2L_SPIROM_FIP_BASE)

#define RZG2L_OTP_DEVICE_INFO       (RZG2L_OTP_BASE + 0x1178)

#define RZG2L_EMMC_FIP_BASE         (0x00020000)
#define RZG2L_EMMC_FIP_SIZE         (0x001DFFFF)

#define RZG2L_SYC_INCK_HZ           (24000000)
#define RZG2L_UART_INCK_HZ          (100000000)
#define RZG2L_UART_BARDRATE         (115200)

/* Boot Info base address */
#define RZG2L_BOOTINFO_BASE         (RZG2L_SRAM_BASE)

/* Base address where parameters to BL31 are stored */
#define PARAMS_BASE                 (RZG2L_SRAM_BASE + 0x0001F000)
#define PARAMS_SIZE                 (0x1000)

#endif /* __RZG2L_DEF_H__ */
