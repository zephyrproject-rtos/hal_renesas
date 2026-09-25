# SPDX-License-Identifier: Apache-2.0

set(hal_dir             ${ZEPHYR_HAL_RENESAS_MODULE_DIR})
set(hal_blobs_dir       ${hal_dir}/zephyr/blobs)

set(_bsp_w_mcu_all
	fsp/src/bsp_w/mcu/all/bsp_assert.c
	fsp/src/bsp_w/mcu/all/bsp_clocks.c
	fsp/src/bsp_w/mcu/all/bsp_common.c
	fsp/src/bsp_w/mcu/all/bsp_delay.c
	fsp/src/bsp_w/mcu/all/bsp_group_irq.c
	fsp/src/bsp_w/mcu/all/bsp_guard.c
	fsp/src/bsp_w/mcu/all/bsp_irq.c
	fsp/src/bsp_w/mcu/all/bsp_pd_ctrl.c
	fsp/src/bsp_w/mcu/all/bsp_pd.c
	fsp/src/bsp_w/mcu/all/bsp_security.c
	fsp/src/bsp_w/mcu/all/fast_memcpy.S
	fsp/src/bsp_w/mcu/all/fast_memset.S
)

set(_bsp_w_mcu_ra6b1
	fsp/src/bsp_w/mcu/ra6b1/bsp_clocks.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_device_info.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_headers.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_init.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_linker.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_pd.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_preferred_reg_values.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_rsip.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_tcs.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_bod.c
	fsp/src/bsp_w/mcu/ra6b1/bsp_entropy.c
)

set(include_dirs
	fsp/inc
	fsp/inc/api
	fsp/inc/instances
	fsp/src/bsp_w/mcu/all
	fsp/src/bsp_w/cmsis/Device/RENESAS/Include
	fsp/src/bsp_w/mcu/ra6b1
)

set(srcs
	${_bsp_w_mcu_all}
	${_bsp_w_mcu_ra6b1}
	fsp/src/bsp_w/cmsis/Device/RENESAS/Source/system.c
	fsp/src/bsp_w/cmsis/Device/RENESAS/Source/GCC/deepsleep.S
)

zephyr_blobs_verify(FILES ${hal_blobs_dir}/ra6b1/libentropy.a REQUIRED)
zephyr_library_link_libraries(${hal_blobs_dir}/ra6b1/libentropy.a)

# Optional build base on feature configuration
zephyr_library_sources_ifdef(CONFIG_UART_RA6B1 fsp/src/r_uart_w_b/r_uart_w_b.c)

zephyr_include_directories(${include_dirs})
zephyr_library_sources(${srcs})
