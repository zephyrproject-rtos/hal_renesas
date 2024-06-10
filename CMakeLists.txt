# SPDX-License-Identifier: Apache-2.0

add_subdirectory_ifdef(CONFIG_SOC_FAMILY_RENESAS_SMARTBOND smartbond)
add_subdirectory(zephyr)
add_subdirectory(drivers)
