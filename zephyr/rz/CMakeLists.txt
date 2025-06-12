# SPDX-License-Identifier: Apache-2.0
string(SUBSTRING ${CONFIG_SOC_SERIES} 0 3 SOC_SERIES_PREFIX)

zephyr_include_directories(portable/${SOC_SERIES_PREFIX})
zephyr_include_directories(rz_cfg/fsp_cfg/${SOC_SERIES_PREFIX})
zephyr_include_directories(rz_cfg/fsp_cfg/bsp/${CONFIG_SOC_SERIES})

if("${CONFIG_SOC_SERIES}" MATCHES "rza.*")
	zephyr_library_sources(portable/${SOC_SERIES_PREFIX}/bsp_delay_asm.asm)
endif()

if(CONFIG_CPU_CORTEX_M)
	set(CPU cm)
elseif(CONFIG_CPU_AARCH32_CORTEX_R OR CONFIG_CPU_AARCH64_CORTEX_R)
	set(CPU cr)
elseif(CONFIG_CPU_CORTEX_A)
	set(CPU ca)
endif()

if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/portable/${SOC_SERIES_PREFIX}/${CPU}")
	zephyr_include_directories(portable/${SOC_SERIES_PREFIX}/${CPU})
endif()

if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/rz_cfg/fsp_cfg/bsp/${CONFIG_SOC_SERIES}/${CPU}")
	zephyr_include_directories(rz_cfg/fsp_cfg/bsp/${CONFIG_SOC_SERIES}/${CPU})
endif()
