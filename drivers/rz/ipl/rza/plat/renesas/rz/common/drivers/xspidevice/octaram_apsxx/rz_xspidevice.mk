#
# Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
_XSPI_DEVICE:=octaram_apsxx
RZ_XSPI_SOURCES:=$(RZ_XSPI_SOURCES) plat/renesas/rz/common/drivers/xspidevice/$(_XSPI_DEVICE)/$(_XSPI_DEVICE).c
PLAT_INCLUDES+=-Iplat/renesas/rz/common/drivers/xspidevice/$(_XSPI_DEVICE)
RZ_XSPI_HEADERS:=$(RZ_XSPI_HEADERS) $(_XSPI_DEVICE)_api.h
