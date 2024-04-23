# SPDX-License-Identifier: Apache-2.0

set(include_dirs
	fsp/inc
	fsp/inc/api
	fsp/inc/instances
	ra_cfg/fsp_cfg
	fsp/src/bsp/mcu/all
	fsp/src/bsp/cmsis/Device/RENESAS/Include
)

set(srcs
	fsp/src/bsp/mcu/all/bsp_rom_registers.c
	fsp/src/bsp/mcu/all/bsp_clocks.c
	fsp/src/bsp/mcu/all/bsp_delay.c
	fsp/src/bsp/mcu/all/bsp_register_protection.c
	fsp/src/bsp/mcu/all/bsp_irq.c
)

zephyr_include_directories(${include_dirs})
zephyr_library_sources(${srcs})

zephyr_include_directories(fsp/src/bsp/mcu/${CONFIG_SOC_SERIES})

# Optional build base on feature configuration
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SCI_UART
	fsp/src/r_sci_uart/r_sci_uart.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SCI_B_UART
	fsp/src/r_sci_b_uart/r_sci_b_uart.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_DTC
	fsp/src/r_dtc/r_dtc.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_ADC
	fsp/src/r_adc/r_adc.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_FLASH_HP
	fsp/src/r_flash_hp/r_flash_hp.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SPI_B
	fsp/src/r_spi_b/r_spi_b.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_TIMER_ULPT
	fsp/src/r_ulpt/r_ulpt.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_LPM
	fsp/src/r_lpm/r_lpm.c)
