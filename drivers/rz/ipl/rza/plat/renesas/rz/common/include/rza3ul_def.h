/*
 * Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __RZA3_DEF_H__
#define __RZA3_DEF_H__

#define RZA3_INTERNAL_MEMORY_BASE   (0x00000000)
#define RZA3_DEVICE_BASE            (0x10000000)
/* move to platform.mk */
/*#define RZA3_XSPI_MEMORY_BASE       (0x20000000) */
#define RZA3_DDR_MEMORY_BASE0       (0x40000000)
#define RZA3_DDR_MEMORY_BASE1       (0x50000000)
#define RZA3_DDR_MEMORY_BASE2       (0x60000000)
#define RZA3_DDR_MEMORY_BASE3       (0x70000000)

#define RZA3_INTERNAL_MEMORY_MMU_SIZE   (0x00200000)
#define RZA3_DEVICE_MMU_SIZE            (0x10000000)
#define RZA3_XSPI_MEMORY_MMU_SIZE       (0x10000000)
#define RZA3_DDR_MEMORY_MMU_SIZE        (0x10000000)

#endif /* __RZA3_DEF_H__ */
