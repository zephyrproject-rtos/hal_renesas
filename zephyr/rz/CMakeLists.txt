# SPDX-License-Identifier: Apache-2.0
string(SUBSTRING ${CONFIG_SOC_SERIES} 0 3 SOC_SERIES_PREFIX)

zephyr_include_directories(portable/${SOC_SERIES_PREFIX})
zephyr_include_directories(rz_cfg/fsp_cfg/${SOC_SERIES_PREFIX})
zephyr_include_directories(rz_cfg/fsp_cfg/bsp/${CONFIG_SOC_SERIES})

if("${CONFIG_SOC_SERIES}" MATCHES "rza.*")
	zephyr_library_sources(portable/${SOC_SERIES_PREFIX}/bsp_delay_asm.asm)
endif()

if(CONFIG_SOC_SERIES_RZV2H)
	zephyr_include_directories_ifdef(CONFIG_CPU_CORTEX_M
		rz_cfg/fsp_cfg/bsp/${CONFIG_SOC_SERIES}/cm)
endif()
