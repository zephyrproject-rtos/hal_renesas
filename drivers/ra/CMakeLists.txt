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
	fsp/src/bsp/mcu/all/bsp_clocks.c
	fsp/src/bsp/mcu/all/bsp_delay.c
	fsp/src/bsp/mcu/all/bsp_register_protection.c
	fsp/src/bsp/mcu/all/bsp_irq.c
	fsp/src/bsp/mcu/all/bsp_group_irq.c
)

zephyr_include_directories(${include_dirs})
zephyr_library_sources(${srcs})

zephyr_include_directories(fsp/src/bsp/mcu/${CONFIG_SOC_SERIES})
zephyr_library_sources(fsp/src/bsp/mcu/${CONFIG_SOC_SERIES}/bsp_linker.c)

# Optional build base on feature configuration
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SCI_UART
	fsp/src/r_sci_uart/r_sci_uart.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SCI_B_UART
	fsp/src/r_sci_b_uart/r_sci_b_uart.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_DMA
	fsp/src/r_dmac/r_dmac.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_DTC
	fsp/src/r_dtc/r_dtc.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_ADC
	fsp/src/r_adc/r_adc.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_FLASH_HP
	fsp/src/r_flash_hp/r_flash_hp.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_FLASH_LP
	fsp/src/r_flash_lp/r_flash_lp.c)
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
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SCI_I2C
	fsp/src/r_sci_i2c/r_sci_i2c.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SCI_B_I2C
	fsp/src/r_sci_b_i2c/r_sci_b_i2c.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SSI
	fsp/src/r_ssi/r_ssi.c)
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
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_WDT
	fsp/src/r_wdt/r_wdt.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_ACMPHS
	fsp/src/r_acmphs/r_acmphs.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_ELC
	fsp/src/r_elc/r_elc.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_I3C
	fsp/src/r_i3c/r_i3c.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_IOPORT
	fsp/src/r_ioport/r_ioport.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_CTSU
	fsp/src/r_ctsu/r_ctsu.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_TOUCH
	fsp/src/rm_touch/rm_touch.c
)

if(CONFIG_USE_RA_FSP_SCE)
	zephyr_include_directories(
		fsp/src/r_sce
		fsp/src/r_sce/common
	)

	if(CONFIG_HAS_RENESAS_RA_RSIP_E51A)
		zephyr_include_directories(
			fsp/src/r_sce/crypto_procedures/src/rsip_e51a/plainkey/public/inc
			fsp/src/r_sce/crypto_procedures/src/rsip_e51a/plainkey/private/inc)
		file(GLOB rsip_e51a_srcs
			"fsp/src/r_sce/crypto_procedures/src/rsip_e51a/plainkey/adaptors/*.c"
			"fsp/src/r_sce/crypto_procedures/src/rsip_e51a/plainkey/primitive/*.c")
		zephyr_library_sources(${rsip_e51a_srcs})
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

zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_CRC
	fsp/src/r_crc/r_crc.c)

zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_CEU
	fsp/src/r_ceu/r_ceu.c)

zephyr_compile_definitions_ifdef(CONFIG_INPUT_RENESAS_RA_QE_TOUCH_CFG QE_TOUCH_CONFIGURATION)
