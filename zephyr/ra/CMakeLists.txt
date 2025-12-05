# SPDX-License-Identifier: Apache-2.0

add_subdirectory(ra_cfg)
zephyr_include_directories(
    portable
    portable/inc
    ra_gen)

# Optional build base on feature configuration
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_AGT
    portable/src/rp_agt/rp_agt.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_CRC
    portable/src/rp_crc/rp_crc.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SSI
    portable/src/rp_ssi/rp_ssi.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_I3C
    portable/src/rp_i3c/rp_i3c.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SCI_B_SPI
    portable/src/rp_sci_b_spi/rp_sci_b_spi.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_ADC
    portable/src/rp_adc/rp_adc.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_LVD
    portable/src/rp_lvd/rp_lvd.c)
zephyr_library_sources_ifdef(CONFIG_USE_RA_FSP_SCI_SPI
    portable/src/rp_sci_spi/rp_sci_spi.c)
