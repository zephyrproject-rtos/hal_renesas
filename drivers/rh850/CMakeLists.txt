# SPDX-License-Identifier: Apache-2.0

set(include_dirs
	fsp/inc
	fsp/inc/api
	fsp/inc/instances
	fsp/src/bsp/mcu/all
	fsp/src/bsp/mcu/${CONFIG_SOC_SERIES}
	fsp/src/bsp/rh850/Device/RENESAS/Include
)

set(srcs
	fsp/src/bsp/mcu/all/bsp_barr.c
	fsp/src/bsp/mcu/all/bsp_clocks.c
	fsp/src/bsp/mcu/all/bsp_delay.c
	fsp/src/bsp/mcu/all/bsp_guard.c
	fsp/src/bsp/mcu/all/bsp_io.c
	fsp/src/bsp/mcu/all/bsp_irq.c
	fsp/src/bsp/mcu/all/bsp_mcu_reset.c
	fsp/src/bsp/mcu/all/bsp_mcu_standby_cyclicrun.c
	fsp/src/bsp/mcu/all/bsp_module_standby.c
	fsp/src/bsp/mcu/all/bsp_mpu.c
	fsp/src/bsp/mcu/all/bsp_common.c
	fsp/src/bsp/mcu/all/bsp_fault_trace.c
	fsp/src/bsp/mcu/all/bsp_sbrk.c
	fsp/src/bsp/mcu/${CONFIG_SOC_SERIES}/bsp_clocks_driver.c
	fsp/src/bsp/mcu/${CONFIG_SOC_SERIES}/bsp_guard_driver.c
	fsp/src/bsp/mcu/${CONFIG_SOC_SERIES}/bsp_module_standby_driver.c
	fsp/src/bsp/mcu/${CONFIG_SOC_SERIES}/bsp_opbt_driver.c
)

zephyr_library_sources(${srcs})
zephyr_include_directories(${include_dirs})

if(CONFIG_SOC_R7F70255XFABB_C
	OR CONFIG_SOC_R7F70255XAFABB_C
	OR CONFIG_SOC_R7F70255XBFABB_C)

	zephyr_include_directories(fsp/src/bsp/mcu/${CONFIG_SOC_SERIES}/rh850u2b6)

elseif(CONFIG_SOC_R7F70254XFABG_C
	OR CONFIG_SOC_R7F70254XFABA_C
	OR CONFIG_SOC_R7F70254XFABB_C
	OR CONFIG_SOC_R7F70254XAFABG_C
	OR CONFIG_SOC_R7F70254XAFABA_C
	OR CONFIG_SOC_R7F70254XAFABB_C)

	zephyr_include_directories(fsp/src/bsp/mcu/${CONFIG_SOC_SERIES}/rh850u2b10)

endif()

# Optional build base on feature configuration

# ICU
zephyr_library_sources_ifdef(CONFIG_USE_RH850_FSP_EXT_IRQ
	fsp/src/r_icu/r_icu.c)

# IOPORT
zephyr_library_sources_ifdef(CONFIG_USE_RH850_FSP_IOPORT
	fsp/src/r_ioport/r_ioport.c)

# OSTM
zephyr_library_sources_ifdef(CONFIG_USE_RH850_FSP_OSTM
	fsp/src/r_ostm/r_ostm.c)

# RLIN3_UART
zephyr_library_sources_ifdef(CONFIG_USE_RH850_FSP_RLIN3_UART
	fsp/src/r_rlin3_uart/r_rlin3_uart.c)
