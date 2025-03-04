# SPDX-License-Identifier: Apache-2.0

set(include_dirs
	rdp_cfg
	rdp/src/r_bsp
	rdp_cfg/r_config
	rdp/src/r_bsp/mcu
	rdp/src/r_bsp/mcu/all
	rdp/src/r_bsp/mcu/${CONFIG_SOC_SERIES}
	rdp/src/r_bsp/mcu/${CONFIG_SOC_SERIES}/register_access/gnuc
)

set(srcs
	rdp/src/r_bsp/mcu/all/r_bsp_common.c
	rdp/src/r_bsp/mcu/all/r_bsp_cpu.c
	rdp/src/r_bsp/mcu/all/r_bsp_interrupts.c
	rdp/src/r_bsp/mcu/all/r_bsp_software_interrupt.c
	rdp/src/r_bsp/mcu/all/r_rx_intrinsic_functions.c
	rdp/src/r_bsp/mcu/${CONFIG_SOC_SERIES}/mcu_clocks.c
	rdp/src/r_bsp/mcu/${CONFIG_SOC_SERIES}/mcu_init.c
	rdp/src/r_bsp/mcu/${CONFIG_SOC_SERIES}/mcu_interrupts.c
)

zephyr_include_directories(${include_dirs})
zephyr_library_sources(${srcs})

# Optional build base on feature configuration
if(CONFIG_USE_RX_RDP_GPIO)
	zephyr_library_sources(
		rdp/src/r_gpio_rx/src/r_gpio_rx.c
		rdp/src/r_gpio_rx/src/targets/${CONFIG_SOC_SERIES}/r_gpio_${CONFIG_SOC_SERIES}.c
	)
	zephyr_include_directories(rdp/src/r_gpio_rx)
endif()

if(CONFIG_USE_RX_RDP_MPC)
	zephyr_library_sources(
		rdp/src/r_mpc_rx/src/r_mpc_rx.c
	)
	zephyr_include_directories(rdp/src/r_mpc_rx)
endif()
