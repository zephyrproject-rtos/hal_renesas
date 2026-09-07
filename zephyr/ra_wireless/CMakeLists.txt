# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(fsp_cfg)
zephyr_include_directories(fsp_cfg/bsp)

zephyr_library_sources(
        portable/src/bsp_w/all/startup.c)

zephyr_include_directories(
	portable/inc
	portable/src/bsp_w/ra6b1
)
