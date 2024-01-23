/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <da1469x_qspic.h>
#include <assert.h>

/*
 * JEDEC commands that should be supported by all NOR and PSRAM
 * vendors in single bus mode.
 */
#define MEMORY_JEDEC_RESET_ENABLE  0x66
#define MEMORY_JEDEC_RESET_CMD     0x99
#define MEMORY_JEDEC_READ_ID_CMD   0x9F

#define QSPIC_BURSTCMDB_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(QSPIC_QSPIC_BURSTCMDB_REG_ ## _field ## _Msk)) | 	\
	(((_val) << QSPIC_QSPIC_BURSTCMDB_REG_ ## _field ## _Pos) & 	\
	QSPIC_QSPIC_BURSTCMDB_REG_ ## _field ## _Msk)

#define QSPIC_CTRLMODE_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(QSPIC_QSPIC_CTRLMODE_REG_ ## _field ## _Msk)) | 	\
	(((_val) << QSPIC_QSPIC_CTRLMODE_REG_ ## _field ## _Pos) & 	\
	QSPIC_QSPIC_CTRLMODE_REG_ ## _field ## _Msk)

#define QSPIC_ERASECMDB_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(QSPIC_QSPIC_ERASECMDB_REG_ ## _field ## _Msk)) | 	\
	(((_val) << QSPIC_QSPIC_ERASECMDB_REG_ ## _field ## _Pos) & 	\
	QSPIC_QSPIC_ERASECMDB_REG_ ## _field ## _Msk)

#define QSPIC_MEMBLEN_REG_SET_FIELD(_field, _var, _val)	\
	((_var)) =	\
	((_var) & ~(QSPIC2_QSPIC2_MEMBLEN_REG_ ## _field ## _Msk)) | 	\
	(((_val) << QSPIC2_QSPIC2_MEMBLEN_REG_ ## _field ## _Pos) & 	\
	QSPIC2_QSPIC2_MEMBLEN_REG_ ## _field ## _Msk)

static inline void
qspi_set_cs_state(QSPIC_TYPE qspi_id, bool state)
{
    if (state) {
        qspi_id->QSPIC_CTRLBUS_REG = QSPIC_QSPIC_CTRLBUS_REG_QSPIC_EN_CS_Msk;
    } else {
        qspi_id->QSPIC_CTRLBUS_REG = QSPIC_QSPIC_CTRLBUS_REG_QSPIC_DIS_CS_Msk;
    }
}

static inline void
qspi_write8_data(QSPIC_TYPE qspi_id, int8_t data)
{
    volatile uint8_t *reg8 = (uint8_t *)&qspi_id->QSPIC_WRITEDATA_REG;

    *reg8 = data;
}

static inline uint8_t
qspi_read8_data(QSPIC_TYPE qspi_id)
{
    volatile uint8_t *reg8 = (uint8_t *)&qspi_id->QSPIC_READDATA_REG;

    return *reg8;
}

static void
qspi_write(QSPIC_TYPE qspi_id, const uint8_t *wbuf, size_t wlen)
{
	assert((qspi_id->QSPIC_CTRLMODE_REG & QSPIC_QSPIC_CTRLMODE_REG_QSPIC_AUTO_MD_Msk) == 0);

    qspi_set_cs_state(qspi_id, true);

    for (int i = 0; i < wlen; i++) {
        qspi_write8_data(qspi_id, wbuf[i]);
    }

    qspi_set_cs_state(qspi_id, false);
}

static void
qspi_transact(QSPIC_TYPE qspi_id, const uint8_t *wbuf, size_t wlen, uint8_t *rbuf, size_t rlen)
{
	assert((qspi_id->QSPIC_CTRLMODE_REG & QSPIC_QSPIC_CTRLMODE_REG_QSPIC_AUTO_MD_Msk) == 0);

    qspi_set_cs_state(qspi_id, true);

    for (int i = 0; i < wlen; i++) {
        qspi_write8_data(qspi_id, wbuf[i]);
    }

    for (int i = 0; i < rlen; i++) {
        rbuf[i] = qspi_read8_data(qspi_id);
    }

    qspi_set_cs_state(qspi_id, false);
}

void
da1469x_qspi_set_bus_mode(QSPIC_TYPE qspi_id, qspi_bus_mode_t mode)
{
	assert((qspi_id->QSPIC_CTRLMODE_REG & QSPIC_QSPIC_CTRLMODE_REG_QSPIC_AUTO_MD_Msk) == 0);

    qspi_id->QSPIC_CTRLBUS_REG = mode;

    switch (mode) {
    case QSPI_BUS_MODE_SINGLE:
    case QSPI_BUS_MODE_DUAL:
        qspi_id->QSPIC_CTRLMODE_REG |= (QSPIC_QSPIC_CTRLMODE_REG_QSPIC_IO2_OEN_Msk |
            QSPIC_QSPIC_CTRLMODE_REG_QSPIC_IO3_OEN_Msk |
            QSPIC_QSPIC_CTRLMODE_REG_QSPIC_IO2_DAT_Msk |
            QSPIC_QSPIC_CTRLMODE_REG_QSPIC_IO3_DAT_Msk);
        break;
    case QSPI_BUS_MODE_QUAD:
        qspi_id->QSPIC_CTRLMODE_REG &= ~(QSPIC_QSPIC_CTRLMODE_REG_QSPIC_IO2_OEN_Msk |
            QSPIC_QSPIC_CTRLMODE_REG_QSPIC_IO3_OEN_Msk);
        break;
    }
}

void
da1469x_qspi_memory_jedec_reset(QSPIC_TYPE qspi_id)
{
	assert((qspi_id->QSPIC_CTRLMODE_REG & QSPIC_QSPIC_CTRLMODE_REG_QSPIC_AUTO_MD_Msk) == 0);

    uint8_t cmd;
    da1469x_qspi_set_bus_mode(qspi_id, QSPI_BUS_MODE_SINGLE);

    /* Commands should be sent in separate CS assertion cycles. */
    cmd = MEMORY_JEDEC_RESET_ENABLE;
    qspi_write(qspi_id, (const uint8_t *)&cmd, 1);
    cmd = MEMORY_JEDEC_RESET_CMD;
    qspi_write(qspi_id, (const uint8_t *)&cmd, 1);

    /*
     * It might happen that PSRAM/NOR device is already in QPI mode and so
     * the previous commands should be sent in quad bus mode.
     */
    da1469x_qspi_set_bus_mode(qspi_id, QSPI_BUS_MODE_QUAD);
    cmd = MEMORY_JEDEC_RESET_ENABLE;
    qspi_write(qspi_id, (const uint8_t *)&cmd, 1);
    cmd = MEMORY_JEDEC_RESET_CMD;
    qspi_write(qspi_id, (const uint8_t *)&cmd, 1);
}

void
da1469x_qspi_memory_jedec_read_id(QSPIC_TYPE qspi_id, qspi_memory_id_t *id)
{
	assert((qspi_id->QSPIC_CTRLMODE_REG & QSPIC_QSPIC_CTRLMODE_REG_QSPIC_AUTO_MD_Msk) == 0);

    uint8_t cmd[4] = { 0 };
	uint8_t *response = (uint8_t *)id;

    da1469x_qspi_set_bus_mode(qspi_id, QSPI_BUS_MODE_SINGLE);

    cmd[0] = MEMORY_JEDEC_READ_ID_CMD;
    qspi_transact(qspi_id, (const uint8_t *)cmd, sizeof(cmd), response, sizeof(*id));
}

void
da1469x_qspi_enter_exit_qpi_mode(QSPIC_TYPE qspi_id, bool enter, uint8_t cmd)
{
	assert((qspi_id->QSPIC_CTRLMODE_REG & QSPIC_QSPIC_CTRLMODE_REG_QSPIC_AUTO_MD_Msk) == 0);

	da1469x_qspi_set_bus_mode(qspi_id, enter ? QSPI_BUS_MODE_SINGLE : QSPI_BUS_MODE_QUAD);
    qspi_write(qspi_id, (const uint8_t *)&cmd, 1);
}

void
da1469x_qspi_set_read_pipe_delay(QSPIC_TYPE qspi_id, uint8_t delay)
{
    uint32_t qspic_ctrlmode_reg = qspi_id->QSPIC_CTRLMODE_REG;
    QSPIC_CTRLMODE_REG_SET_FIELD(QSPIC_RPIPE_EN, qspic_ctrlmode_reg, 1);
    QSPIC_CTRLMODE_REG_SET_FIELD(QSPIC_PCLK_MD, qspic_ctrlmode_reg, delay);
    qspi_id->QSPIC_CTRLMODE_REG = qspic_ctrlmode_reg;
}

void
da1469x_qspi_set_cs_delay(QSPIC_TYPE qspi_id, uint32_t sys_clock_freq,
                                    uint32_t read_delay_ns, uint32_t erase_delay_ns)
{
	sys_clock_freq /= 100000;
	uint32_t read_delay_cyc =
		((read_delay_ns * sys_clock_freq) + 9999) / 10000;
	uint32_t erase_delay_cyc =
		((erase_delay_ns * sys_clock_freq) + 9999) / 10000;

    uint32_t reg = qspi_id->QSPIC_BURSTCMDB_REG;
    QSPIC_BURSTCMDB_REG_SET_FIELD(QSPIC_CS_HIGH_MIN, reg, read_delay_cyc);
    qspi_id->QSPIC_BURSTCMDB_REG = reg;

    reg = qspi_id->QSPIC_ERASECMDB_REG;
    QSPIC_ERASECMDB_REG_SET_FIELD(QSPIC_ERS_CS_HI, reg, erase_delay_cyc);
    qspi_id->QSPIC_ERASECMDB_REG = reg;
}

void
da1469x_qspi_set_tcem(uint32_t sys_clock_freq, uint32_t tcem_us)
{
	uint32_t cs_active_max_cyc =
		tcem_us * (sys_clock_freq / 1000000);

    uint32_t qspic_mmemblen_reg = QSPIC2->QSPIC2_MEMBLEN_REG;
    QSPIC_MEMBLEN_REG_SET_FIELD(QSPIC_T_CEM_EN, qspic_mmemblen_reg, 1);
    QSPIC_MEMBLEN_REG_SET_FIELD(QSPIC_T_CEM_CC, qspic_mmemblen_reg, cs_active_max_cyc);
    QSPIC2->QSPIC2_MEMBLEN_REG = qspic_mmemblen_reg;
}
