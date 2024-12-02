# SPDX-License-Identifier: Apache-2.0

set(srcs
	bsp/mcu/all/bsp_clocks.c
	bsp/mcu/all/bsp_delay.c
	bsp/mcu/all/bsp_irq.c
	bsp/mcu/all/bsp_io.c
)

zephyr_library_sources(${srcs})
