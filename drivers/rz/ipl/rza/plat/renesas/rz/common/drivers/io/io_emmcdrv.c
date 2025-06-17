/*
 * Copyright (c) 2015-2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <string.h>

#include <common/debug.h>
#include <drivers/io/io_driver.h>
#include <drivers/io/io_storage.h>

#include "emmc_config.h"
#include "emmc_def.h"
#include "emmc_hal.h"
#include "emmc_std.h"
#include "io_common.h"
#include "io_emmcdrv.h"
#include "io_private.h"

static int32_t emmcdrv_dev_open(const uintptr_t spec __attribute__ ((unused)),
				io_dev_info_t **dev_info);
static int32_t emmcdrv_dev_close(io_dev_info_t *dev_info);

typedef struct {
	uint32_t in_use;
	uintptr_t base;
	signed long long file_pos;
	EMMC_PARTITION_ID partition;
} file_state_t;

static file_state_t current_file = { 0 };

static io_type_t device_type_emmcdrv(void)
{
	return IO_TYPE_MEMMAP;
}

static int32_t emmcdrv_block_seek(io_entity_t *entity, int32_t mode,
				  signed long long offset)
{
	if (mode != IO_SEEK_SET) {
		return IO_FAIL;
	}

	((file_state_t *) entity->info)->file_pos = offset;

	return IO_SUCCESS;
}

static int32_t emmcdrv_block_read(io_entity_t *entity, uintptr_t buffer,
				  size_t length, size_t *length_read)
{
	file_state_t *fp = (file_state_t *) entity->info;
	uint32_t first_sector, last_sector, sector_count, emmc_dma = 0;
	uint8_t sector_buf[EMMC_SECTOR_SIZE];
	size_t buffer_offset = 0;
	int32_t result = IO_SUCCESS;

	first_sector = (fp->base + fp->file_pos) >> EMMC_SECTOR_SIZE_SHIFT;
	last_sector = (fp->base + fp->file_pos + length -1 ) >> EMMC_SECTOR_SIZE_SHIFT;
	sector_count = last_sector - first_sector + 1;

	NOTICE("BL2: Load dst=0x%lx src=(p:%d)0x%llx(%d) len=0x%lx(%d)\n",
			buffer,
			fp->partition, (fp->base + fp->file_pos),
			first_sector, length, sector_count);

//	Temporarily disable DMA.
//	if ((buffer + length - 1U) <= (uintptr_t)UINT32_MAX) {
//		emmc_dma = LOADIMAGE_FLAGS_DMA_ENABLE;
//	}

    // first sector
	uint32_t first_offset = (fp->base + fp->file_pos) % EMMC_SECTOR_SIZE;
	if( 0 < first_offset ) {
		memset(sector_buf, 0x00, EMMC_SECTOR_SIZE);
		if(emmc_read_sector((uint32_t*)sector_buf,
			first_sector, 1, emmc_dma) != EMMC_SUCCESS) {
			result = IO_FAIL;
			goto block_read_done;
		}
		else {
			buffer_offset = EMMC_SECTOR_SIZE - first_offset;
			buffer_offset = (length < buffer_offset) ? length : buffer_offset;

			memcpy((uint8_t *)buffer, &sector_buf[first_offset], buffer_offset);

			first_sector++;
			sector_count--;
		}
	}

	// last sector
	uint32_t last_offset = (fp->base + fp->file_pos + length) % EMMC_SECTOR_SIZE;
	if(0 < sector_count && 0 < last_offset) {
		memset(sector_buf, 0x00, EMMC_SECTOR_SIZE);
		if (emmc_read_sector((uint32_t*)sector_buf,
				last_sector, 1, emmc_dma) != EMMC_SUCCESS) {
			result = IO_FAIL;
			goto block_read_done;
		}
		else {
			memcpy((uint8_t *) buffer + (length - last_offset), &sector_buf[0], last_offset);
			sector_count--;
		}
	}

	// middle sector
	if(0 < sector_count) {
		if (emmc_read_sector((uint32_t *)(buffer + buffer_offset),
				first_sector, sector_count, emmc_dma) != EMMC_SUCCESS) {
			result = IO_FAIL;
			goto block_read_done;
		}
	}

	*length_read = length;
	fp->file_pos += (signed long long)length;
block_read_done:
	return result;
}

static int32_t emmcdrv_block_open(io_dev_info_t *dev_info,
				const uintptr_t spec, io_entity_t *entity)
{
	const io_drv_spec_t *block_spec = (io_drv_spec_t *) spec;

	if (current_file.in_use != 0U) {
		WARN("mmc_block: Only one open spec at a time\n");
		return IO_RESOURCES_EXHAUSTED;
	}

	current_file.base = block_spec->offset;
	current_file.file_pos = 0;
	current_file.in_use = 1;

	current_file.partition = mmc_drv_obj.boot_partition_en;
	NOTICE("BL2: eMMC boot from partition %d\n", current_file.partition);

	if (emmc_select_partition(current_file.partition) != EMMC_SUCCESS) {
		return IO_FAIL;
	}

	entity->info = (uintptr_t) &current_file;

	return IO_SUCCESS;
}

static int32_t emmcdrv_block_close(io_entity_t *entity)
{
	memset((void *)&current_file, 0, sizeof(current_file));
	entity->info = 0U;

	return IO_SUCCESS;
}

static const io_dev_funcs_t emmcdrv_dev_funcs = {
	.type = &device_type_emmcdrv,
	.open = &emmcdrv_block_open,
	.seek = &emmcdrv_block_seek,
	.size = NULL,
	.read = &emmcdrv_block_read,
	.write = NULL,
	.close = &emmcdrv_block_close,
	.dev_init = NULL,
	.dev_close = &emmcdrv_dev_close
};

static const io_dev_info_t emmcdrv_dev_info = {
	.funcs = &emmcdrv_dev_funcs,
	.info = (uintptr_t) 0
};

static const io_dev_connector_t emmcdrv_dev_connector = {
	&emmcdrv_dev_open,
};

static int32_t emmcdrv_dev_open(const uintptr_t spec __attribute__ ((unused)),
				io_dev_info_t **dev_info)
{
	*dev_info = (io_dev_info_t *) &emmcdrv_dev_info;

	return IO_SUCCESS;
}

static int32_t emmcdrv_dev_close(io_dev_info_t *dev_info)
{
	return IO_SUCCESS;
}

int32_t register_io_dev_emmcdrv(const io_dev_connector_t **dev_con)
{
	int32_t rc;

	rc = io_register_device(&emmcdrv_dev_info);
	if (rc == IO_SUCCESS) {
		*dev_con = &emmcdrv_dev_connector;
	}

	return rc;
}
