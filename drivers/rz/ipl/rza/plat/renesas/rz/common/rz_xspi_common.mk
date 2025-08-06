#
# Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

RZ_BUILD_PLAT_TMP:=$(BUILD_PLAT)
RZ_XSPI_DEF:=$(RZ_BUILD_PLAT_TMP)/rz_bl2_xspi_def.c
RZ_XSPI_ENV:=$(RZ_BUILD_PLAT_TMP)/rz_bl2_xspi.env
RZ_XSPI_HEADERS:=xspi_api.h xspidevice_api.h $(RZ_XSPI_HEADERS)
RZ_USE_XSPI:=0

RZ_XSPIFLASH_DISABLE_WRITE:=1
RZ_XSPI_FORCE_VOLTAGE_SETTING:=0
$(eval $(call add_define,RZ_XSPIFLASH_DISABLE_WRITE))
$(eval $(call add_define,RZ_XSPI_FORCE_VOLTAGE_SETTING))

rz_uniq = $(if $1,$(firstword $1) $(call rz_uniq,$(filter-out $(firstword $1),$1)))

define RZ_XSPI_ADD_IFDRIVER
  $(eval RZ_XSPI_SOURCES:=$(RZ_XSPI_SOURCES) $(RZ_XSPI_DRIVER_PATH)/$(1).c)
  $(eval RZ_XSPI_HEADERS:=$(RZ_XSPI_HEADERS) $(1).h)
endef

define RZ_XSPI_INCLUDE_MAKEFILE
  $(if $(filter-out __,_$(strip $($(1)_DEVICE))_),$(call RZ_XSPI_ADD_IFDRIVER,$(RZ_$(1)_IF)))
  $(if $(filter-out __,_$(strip $($(1)_DEVICE))_),$(eval include plat/renesas/rz/common/drivers/xspidevice/$($(1)_DEVICE)/rz_xspidevice.mk))
  $(if $(filter-out __,_$(strip $($(1)_DEVICE))_),$(eval RZ_USE_XSPI:=1))
endef

# export environment to shell
define RZ_ADD_ENV
	@echo $(1)=\"$(strip $($(1)))\" >> $@

endef

define RZ_XSPI_ADD_ENV
  $(call RZ_ADD_ENV,RZ_$(1)_IF)
  $(call RZ_ADD_ENV,RZ_$(1)_IF_CONFIG)
  $(call RZ_ADD_ENV,$(1)_DEVICE)
  $(call RZ_ADD_ENV,$(1)_OPTION)
  $(call RZ_ADD_ENV,$(1)_IF_OPTION)
endef

# include makefile for xspidevice driver
$(foreach element,$(RZ_XSPI_CONFIGS),$(call RZ_XSPI_INCLUDE_MAKEFILE,$(element)))

# eliminate duplicated entries in sources and headers
RZ_XSPI_SOURCES:=$(call rz_uniq,$(RZ_XSPI_SOURCES))
RZ_XSPI_HEADERS:=$(call rz_uniq,$(RZ_XSPI_HEADERS))

# add sources
ifneq ($(RZ_USE_XSPI),0)
  XSPI_SOURCES+=$(RZ_XSPI_SOURCES)
  XSPI_SOURCES+=$(RZ_XSPI_DEF)
# Outs env file
$(RZ_XSPI_ENV): $(RZ_BUILD_PLAT_TMP)
	@echo -n "" > $@
	$(foreach element,$(RZ_XSPI_CONFIGS),$(call RZ_XSPI_ADD_ENV,$(element)))
	$(call RZ_ADD_ENV,RZ_XSPI_CONFIGS)
	$(call RZ_ADD_ENV,RZ_XSPI_HEADERS)
	$(call RZ_ADD_ENV,PLAT)
	$(call RZ_ADD_ENV,BOARD)

$(RZ_XSPI_DEF): $(RZ_XSPI_ENV)
	$(Q)$(SHELL) plat/renesas/rz/common/rz_bl2_xspi_config.sh "$(RZ_XSPI_ENV)" "$(RZ_XSPI_DEF)"
endif
