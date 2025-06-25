/*
 * Copyright (c) 2020, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __SYS_H__
#define __SYS_H__

#define MASK_BOOTM_DEVICE		(0x0F)
#define MASK_BOOTM_SECURE		(0x10)

#define BOOT_MODE_ESD           (0)
#define BOOT_MODE_EMMC_1_8      (1)
#define BOOT_MODE_EMMC_3_3      (2)
#define BOOT_MODE_SPI_1_8       (3)
#define BOOT_MODE_SPI_3_3       (4)
#define BOOT_MODE_SCIF          (5)
#define BOOT_MODE_NAND_SPI_1_8  (6)
#define BOOT_MODE_NAND_SPI_3_3  (7)

#endif	/* __SYS_H__ */
