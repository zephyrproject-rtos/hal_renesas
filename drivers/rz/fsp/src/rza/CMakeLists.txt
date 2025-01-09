# SPDX-License-Identifier: Apache-2.0

set(srcs
	bsp/mcu/all/bsp_clocks.c
	bsp/mcu/all/bsp_delay.c
	bsp/mcu/all/bsp_irq.c
	bsp/mcu/all/bsp_io.c
	bsp/mcu/all/bsp_gicv3.c
	bsp/mcu/${CONFIG_SOC_SERIES}/bsp_clocks_setup.c
)

zephyr_library_sources(${srcs})
