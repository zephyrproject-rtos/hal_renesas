# SPDX-License-Identifier: Apache-2.0

if(CONFIG_CPU_CORTEX_M)
	set(CPU cm)
elseif(CONFIG_CPU_AARCH32_CORTEX_R OR CONFIG_CPU_AARCH64_CORTEX_R)
	set(CPU cr)
elseif(CONFIG_CPU_CORTEX_A)
	set(CPU ca)
endif()

set(srcs
	bsp/mcu/all/bsp_address_convert.c
	bsp/mcu/all/bsp_clocks.c
	bsp/mcu/all/bsp_delay.c
	bsp/mcu/all/bsp_io.c
	bsp/mcu/all/${CPU}/bsp_irq.c
)

zephyr_library_sources(${srcs})
