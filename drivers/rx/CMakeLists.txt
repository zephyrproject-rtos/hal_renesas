# SPDX-License-Identifier: Apache-2.0

set(include_dirs
	rdp/src/r_bsp
	rdp/src/r_bsp/mcu
	rdp/src/r_bsp/mcu/all
	rdp/src/r_bsp/mcu/${CONFIG_SOC_SERIES}
	rdp/src/r_bsp/mcu/${CONFIG_SOC_SERIES}/register_access/gnuc
)

set(srcs
	rdp/src/r_bsp/mcu/all/r_bsp_common.c
	rdp/src/r_bsp/mcu/${CONFIG_SOC_SERIES}/mcu_clocks.c
	rdp/src/r_bsp/mcu/${CONFIG_SOC_SERIES}/mcu_init.c
)

zephyr_include_directories(${include_dirs})
zephyr_library_sources(${srcs})
