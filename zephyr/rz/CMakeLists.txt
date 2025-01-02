# SPDX-License-Identifier: Apache-2.0
string(SUBSTRING ${CONFIG_SOC_SERIES} 0 3 SOC_SERIES_PREFIX)

zephyr_include_directories(portable/${SOC_SERIES_PREFIX})
zephyr_include_directories(rz_cfg/fsp_cfg/${SOC_SERIES_PREFIX})
zephyr_include_directories(rz_cfg/fsp_cfg/bsp/${CONFIG_SOC_SERIES})
