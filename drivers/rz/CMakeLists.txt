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

if(CONFIG_CPU_CORTEX_M)
	set(CPU cm)
elseif(CONFIG_CPU_AARCH32_CORTEX_R OR CONFIG_CPU_AARCH64_CORTEX_R)
	set(CPU cr)
elseif(CONFIG_CPU_CORTEX_A)
	set(CPU ca)
endif()

if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/fsp/src/${SOC_SERIES_PREFIX}/bsp/mcu/all/${CPU}")
	list(APPEND include_dirs "fsp/src/${SOC_SERIES_PREFIX}/bsp/mcu/all/${CPU}")
endif()

if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/fsp/src/${SOC_SERIES_PREFIX}/bsp/mcu/${CONFIG_SOC_SERIES}/${CPU}")
	list(APPEND include_dirs "fsp/src/${SOC_SERIES_PREFIX}/bsp/mcu/${CONFIG_SOC_SERIES}/${CPU}")
endif()

zephyr_include_directories(${include_dirs})

# Optional build base on feature configuration
zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_IOPORT
	fsp/src/${SOC_SERIES_PREFIX}/r_ioport/r_ioport.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_SCIF_UART
	fsp/src/${SOC_SERIES_PREFIX}/r_scif_uart/r_scif_uart.c)

if(CONFIG_DT_HAS_RENESAS_RZ_ADC_C_ENABLED)
	zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_ADC
		fsp/src/${SOC_SERIES_PREFIX}/r_adc_c/r_adc_c.c)
else()
	zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_ADC
		fsp/src/${SOC_SERIES_PREFIX}/r_adc/r_adc.c)
endif()

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_MHU
	fsp/src/${SOC_SERIES_PREFIX}/r_mhu_ns/r_mhu_ns.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_RIIC_MASTER
	fsp/src/${SOC_SERIES_PREFIX}/r_riic_master/r_riic_master.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_IIC_MASTER
	fsp/src/${SOC_SERIES_PREFIX}/r_iic_master/r_iic_master.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_GTM
	fsp/src/${SOC_SERIES_PREFIX}/r_gtm/r_gtm.c)

if(CONFIG_DT_HAS_RENESAS_RZ_INTC_ENABLED)
	zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_EXT_IRQ
		fsp/src/${SOC_SERIES_PREFIX}/r_intc_irq/r_intc_irq.c)
	zephyr_library_sources_ifdef(CONFIG_RENESAS_RZ_INTC_HAS_NMI
		fsp/src/${SOC_SERIES_PREFIX}/r_intc_nmi/r_intc_nmi.c)
endif()

if(CONFIG_DT_HAS_RENESAS_RZ_ICU_ENABLED)
	zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_EXT_IRQ
		fsp/src/${SOC_SERIES_PREFIX}/r_icu/r_icu.c)
endif()

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_GPT
	fsp/src/${SOC_SERIES_PREFIX}/r_gpt/r_gpt.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_CANFD
	fsp/src/${SOC_SERIES_PREFIX}/r_canfd/r_canfd.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_RSPI_SPI
	fsp/src/${SOC_SERIES_PREFIX}/r_rspi/r_rspi.c)

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_DMA
	fsp/src/${SOC_SERIES_PREFIX}/r_dmac_b/r_dmac_b.c)

if(CONFIG_DT_HAS_RENESAS_RZ_SCI_B_ENABLED)
	zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_SCI_UART
		fsp/src/${SOC_SERIES_PREFIX}/r_sci_b_uart/r_sci_b_uart.c)
else()
	zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_SCI_UART
		fsp/src/${SOC_SERIES_PREFIX}/r_sci_uart/r_sci_uart.c)
endif()

zephyr_library_sources_ifdef(CONFIG_USE_RZ_FSP_MTU
	fsp/src/${SOC_SERIES_PREFIX}/r_mtu3/r_mtu3.c)
