# SPDX-License-Identifier: Apache-2.0

# Extract the RZ family name from CONFIG_SOC_SERIES
string(SUBSTRING ${CONFIG_SOC_SERIES} 0 3 SOC_SERIES_PREFIX)

zephyr_include_directories(fsp_cfg/${SOC_SERIES_PREFIX})
zephyr_include_directories(fsp_cfg/bsp/${CONFIG_SOC_SERIES})
