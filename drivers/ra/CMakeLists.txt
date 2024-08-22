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
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SPI
	fsp/src/r_spi/r_spi.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_TIMER_ULPT
	fsp/src/r_ulpt/r_ulpt.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_LPM
	fsp/src/r_lpm/r_lpm.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_I2C_IIC
	fsp/src/r_iic_master/r_iic_master.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_GPT
	fsp/src/r_gpt/r_gpt.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_AGT
	fsp/src/r_agt/r_agt.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_CANFD
	fsp/src/r_canfd/r_canfd.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_QSPI_NOR_FLASH
	fsp/src/r_qspi/r_qspi.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_USB_DEVICE
	fsp/src/r_usb_device/r_usb_device.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SDHI
	fsp/src/r_sdhi/r_sdhi.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_OSPI_B_NOR_FLASH
	fsp/src/r_ospi_b/r_ospi_b.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SDRAM
	fsp/src/bsp/mcu/all/bsp_sdram.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_DISPLAY
	fsp/src/r_glcdc/r_glcdc.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_MIPI_DSI
	fsp/src/r_mipi_dsi/r_mipi_dsi.c
	fsp/src/r_mipi_phy/r_mipi_phy.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_DAC
	fsp/src/r_dac/r_dac.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_USB_HOST
	fsp/src/r_usb_host/r_usb_host.c)

if(CONFIG_USE_RA_FSP_SCE)
	zephyr_include_directories(
		fsp/src/r_sce
		fsp/src/r_sce/common
	)

	if(CONFIG_HAS_RENESAS_RA_RSIP_E51A)
		zephyr_include_directories(
			fsp/src/r_sce/crypto_procedures/src/rsip7/plainkey/public/inc
			fsp/src/r_sce/crypto_procedures/src/rsip7/plainkey/private/inc)
		file(GLOB rsip7_srcs
			"fsp/src/r_sce/crypto_procedures/src/rsip7/plainkey/adaptors/*.c"
			"fsp/src/r_sce/crypto_procedures/src/rsip7/plainkey/primitive/*.c")
		zephyr_library_sources(${rsip7_srcs})
	endif()

	if (CONFIG_HAS_RENESAS_RA_SCE5)
		zephyr_include_directories(
			fsp/src/r_sce/crypto_procedures/src/sce5/plainkey/public/inc
			fsp/src/r_sce/crypto_procedures/src/sce5/plainkey/private/inc)
		file(GLOB sce5_srcs
			"fsp/src/r_sce/crypto_procedures/src/sce5/plainkey/adaptors/*.c"
			"fsp/src/r_sce/crypto_procedures/src/sce5/plainkey/primitive/*.c")
		zephyr_library_sources(${sce5_srcs})
	endif()

	if (CONFIG_HAS_RENESAS_RA_SCE7)
		zephyr_include_directories(
			fsp/src/r_sce/crypto_procedures/src/sce7/plainkey/public/inc
			fsp/src/r_sce/crypto_procedures/src/sce7/plainkey/private/inc)
		file(GLOB sce7_srcs
			"fsp/src/r_sce/crypto_procedures/src/sce7/plainkey/adaptors/*.c"
			"fsp/src/r_sce/crypto_procedures/src/sce7/plainkey/primitive/*.c")
		zephyr_library_sources(${sce7_srcs})
	endif()

	if (CONFIG_HAS_RENESAS_RA_SCE9)
		zephyr_include_directories(
			fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/public/inc
			fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/private/inc)
		file(GLOB sce9_srcs
			"fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/adaptors/*.c"
			"fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive/*.c")
		zephyr_library_sources(${sce9_srcs})
	endif()

	if (CONFIG_HAS_RENESAS_RA_TRNG)
		zephyr_include_directories(
			fsp/src/r_sce/trng)
		file(GLOB trng_srcs
			"fsp/src/r_sce/trng/*.c")
		zephyr_library_sources(${trng_srcs})
	endif()

endif()

if(CONFIG_USE_RA_FSP_SDHI)
	zephyr_include_directories(
		fsp/src/r_sdhi
	)
endif()

zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_ETHER_PHY
	fsp/src/r_ether_phy/r_ether_phy.c)

zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_ETHER
	fsp/src/r_ether/r_ether.c)
