# SPDX-License-Identifier: Apache-2.0

set(include_dirs
	fsp/ra/fsp/inc
	fsp/ra/fsp/inc/api
	fsp/ra/fsp/inc/instances
	ra_cfg/fsp_cfg
	portable
)

set(srcs
	fsp/ra/fsp/src/bsp/mcu/all/bsp_rom_registers.c
	fsp/ra/fsp/src/bsp/mcu/all/bsp_clocks.c
	fsp/ra/fsp/src/bsp/mcu/all/bsp_delay.c
	fsp/ra/fsp/src/bsp/mcu/all/bsp_register_protection.c
	fsp/ra/fsp/src/bsp/mcu/all/bsp_irq.c
)

zephyr_include_directories(${include_dirs})
zephyr_library_sources(${srcs})

message(${CONFIG_SOC})
zephyr_include_directories(fsp/ra/fsp/src/bsp/mcu/${CONFIG_SOC})

# Optional build base on feature configuration
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SCI_B_UART
	fsp/ra/fsp/src/r_sci_b_uart/r_sci_b_uart.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_DTC
	fsp/ra/fsp/src/r_dtc/r_dtc.c)