# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(sdk/bsp/include)
zephyr_include_directories(da1469x_hal)
add_subdirectory(da1469x_hal)

zephyr_include_directories_ifdef(CONFIG_BT cmac)
add_subdirectory_ifdef(CONFIG_BT cmac)
