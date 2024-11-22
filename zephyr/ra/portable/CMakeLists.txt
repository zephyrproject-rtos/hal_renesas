# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(inc)
zephyr_library_sources_ifdef(CONFIG_MEMC_RENESAS_RA_SDRAM src/sdram.c)
