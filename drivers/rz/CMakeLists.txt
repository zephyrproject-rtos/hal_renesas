# SPDX-License-Identifier: Apache-2.0

# Extract the RZ family name from CONFIG_SOC_SERIES
string(SUBSTRING ${CONFIG_SOC_SERIES} 0 3 SOC_SERIES_PREFIX)

add_subdirectory(fsp/src/${SOC_SERIES_PREFIX})

set(include_dirs
	fsp/inc
	fsp/inc/api
	fsp/inc/instances/${SOC_SERIES_PREFIX}
	fsp/src/${SOC_SERIES_PREFIX}/bsp/mcu/all
	fsp/src/${SOC_SERIES_PREFIX}/bsp/cmsis/Device/RENESAS/Include
	fsp/src/${SOC_SERIES_PREFIX}/bsp/mcu/${CONFIG_SOC_SERIES}
)

zephyr_include_directories(${include_dirs})

# Optional build base on feature configuration
zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_IOPORT
	fsp/src/${SOC_SERIES_PREFIX}/r_ioport/r_ioport.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_SCIF_UART
	fsp/src/${SOC_SERIES_PREFIX}/r_scif_uart/r_scif_uart.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_ADC
	fsp/src/${SOC_SERIES_PREFIX}/r_adc_c/r_adc_c.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_MHU
	fsp/src/${SOC_SERIES_PREFIX}/r_mhu_ns/r_mhu_ns.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_RIIC_MASTER
	fsp/src/${SOC_SERIES_PREFIX}/r_riic_master/r_riic_master.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_GTM
	fsp/src/${SOC_SERIES_PREFIX}/r_gtm/r_gtm.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_EXT_IRQ
	fsp/src/${SOC_SERIES_PREFIX}/r_intc_irq/r_intc_irq.c
	fsp/src/${SOC_SERIES_PREFIX}/r_intc_nmi/r_intc_nmi.c)
