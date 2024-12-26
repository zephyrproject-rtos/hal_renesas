# SPDX-License-Identifier: Apache-2.0
zephyr_compile_definitions(_RZT_ORDINAL=1)
zephyr_compile_definitions(BSP_CFG_RAM_EXECUTION=1)

set(srcs
	bsp/cmsis/Device/RENESAS/Source/system.c
	bsp/mcu/all/bsp_clocks.c
	bsp/mcu/all/bsp_common.c
	bsp/mcu/all/bsp_delay.c
	bsp/mcu/all/bsp_io.c
	bsp/mcu/all/bsp_irq.c
	bsp/mcu/all/bsp_register_protection.c
	bsp/mcu/all/cr/bsp_delay_core.c
)

zephyr_library_sources(${srcs})
