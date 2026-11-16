/*
 * Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************************************************//**
 * @file     rh850_g4_icache.h
 * @brief    Instruction Cache (ICACHE) control
 * @version  V0.0.2
 * @date     01 Aug 2026
 **********************************************************************************************************************/

#if defined(__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)

/** @defgroup RH850_CoreAccess_FunctionInterface RH850-Core Access Functions
 * @brief Access to the dedicated core access function.
 * @{
 */

/**
 * @defgroup RH850_ICACHE RH850 Instruction Cache (ICACHE)
 * @ingroup RH850_CoreAccess_FunctionInterface
 * @brief    ICACHE API and data types
 * @{
 */

#ifndef RH850_G4_ICACHE_H
 #define RH850_G4_ICACHE_H

 #include <stdint.h>

/* #####################################  ICACHE Types and Enumerations  ############################################ */

/**
 * @defgroup RH850_ICACHE_Types ICACHE Types and Enumerations
 * @brief ICACHE Types and Enumerations
 * @ingroup  RH850_ICACHE
 * @{
 */

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * @enum rh850_icache_size_t
 * @brief Instruction cache size options.
 * @details Represents the total capacity of the instruction cache in kilobytes. Values map directly to the
 *          ICCFG.ICHSIZE field mask used by hardware.
 */
typedef enum e_rh850_icache_size
{
    RH850_ICACHE_SIZE_8KB  = 0x0800,   /*!< ICache size 8KB */
    RH850_ICACHE_SIZE_16KB = 0x1000,   /*!< ICache size 16KB */
    RH850_ICACHE_SIZE_32KB = 0x2000    /*!< ICache size 32KB */
} rh850_icache_size_t;

/**
 * @enum rh850_icache_line_t
 * @brief Number of lines per way in the instruction cache.
 * @details Encodes the ICCFG.ICHLINE field. Each value expresses how many cache lines are provided per way.
 *          Typical configurations are 64, 128, or 256 lines per way.
 */
typedef enum e_rh850_icache_line
{
    RH850_ICACHE_LINE_64  = 0x20,      /*!< ICache line 64 */
    RH850_ICACHE_LINE_128 = 0x40,      /*!< ICache line 128 */
    RH850_ICACHE_LINE_256 = 0x80       /*!< ICache line 256 */
} rh850_icache_line_t;

/**
 * @enum rh850_icache_way_t
 * @brief Number of ways in the instruction cache.
 * @details Encodes the ICCFG.ICHWAY field. Use this to interpret or present associativity reported by hardware.
 */
typedef enum e_rh850_icache_way
{
    RH850_ICACHE_WAY_4 = 0x4           /*!< ICache way: 4 */
} rh850_icache_way_t;

/**
 * @enum rh850_icache_error_indx_t
 * @brief Cache error index values.
 * @details Mirrors the ICERR.ICHEIX field. Each value selects the cache index where an error occurred.
 */
typedef enum e_rh850_icache_error_indx
{
    RH850_ICACHE_ERROR_INDX_0   = 0x000,  /*!< Cache error index: 0 */
    RH850_ICACHE_ERROR_INDX_1   = 0x020,  /*!< Cache error index: 1 */
    RH850_ICACHE_ERROR_INDX_2   = 0x040,  /*!< Cache error index: 2 */
    RH850_ICACHE_ERROR_INDX_3   = 0x060,  /*!< Cache error index: 3 */
    RH850_ICACHE_ERROR_INDX_4   = 0x080,  /*!< Cache error index: 4 */
    RH850_ICACHE_ERROR_INDX_5   = 0x0A0,  /*!< Cache error index: 5 */
    RH850_ICACHE_ERROR_INDX_6   = 0x0C0,  /*!< Cache error index: 6 */
    RH850_ICACHE_ERROR_INDX_7   = 0x0E0,  /*!< Cache error index: 7 */
    RH850_ICACHE_ERROR_INDX_8   = 0x100,  /*!< Cache error index: 8 */
    RH850_ICACHE_ERROR_INDX_9   = 0x120,  /*!< Cache error index: 9 */
    RH850_ICACHE_ERROR_INDX_10  = 0x140,  /*!< Cache error index: 10 */
    RH850_ICACHE_ERROR_INDX_11  = 0x160,  /*!< Cache error index: 11 */
    RH850_ICACHE_ERROR_INDX_12  = 0x180,  /*!< Cache error index: 12 */
    RH850_ICACHE_ERROR_INDX_13  = 0x1A0,  /*!< Cache error index: 13 */
    RH850_ICACHE_ERROR_INDX_14  = 0x1C0,  /*!< Cache error index: 14 */
    RH850_ICACHE_ERROR_INDX_15  = 0x1E0,  /*!< Cache error index: 15 */
    RH850_ICACHE_ERROR_INDX_16  = 0x200,  /*!< Cache error index: 16 */
    RH850_ICACHE_ERROR_INDX_17  = 0x220,  /*!< Cache error index: 17 */
    RH850_ICACHE_ERROR_INDX_18  = 0x240,  /*!< Cache error index: 18 */
    RH850_ICACHE_ERROR_INDX_19  = 0x260,  /*!< Cache error index: 19 */
    RH850_ICACHE_ERROR_INDX_20  = 0x280,  /*!< Cache error index: 20 */
    RH850_ICACHE_ERROR_INDX_21  = 0x2A0,  /*!< Cache error index: 21 */
    RH850_ICACHE_ERROR_INDX_22  = 0x2C0,  /*!< Cache error index: 22 */
    RH850_ICACHE_ERROR_INDX_23  = 0x2E0,  /*!< Cache error index: 23 */
    RH850_ICACHE_ERROR_INDX_24  = 0x300,  /*!< Cache error index: 24 */
    RH850_ICACHE_ERROR_INDX_25  = 0x320,  /*!< Cache error index: 25 */
    RH850_ICACHE_ERROR_INDX_26  = 0x340,  /*!< Cache error index: 26 */
    RH850_ICACHE_ERROR_INDX_27  = 0x360,  /*!< Cache error index: 27 */
    RH850_ICACHE_ERROR_INDX_28  = 0x380,  /*!< Cache error index: 28 */
    RH850_ICACHE_ERROR_INDX_29  = 0x3A0,  /*!< Cache error index: 29 */
    RH850_ICACHE_ERROR_INDX_30  = 0x3C0,  /*!< Cache error index: 30 */
    RH850_ICACHE_ERROR_INDX_31  = 0x3E0,  /*!< Cache error index: 31 */
    RH850_ICACHE_ERROR_INDX_32  = 0x400,  /*!< Cache error index: 32 */
    RH850_ICACHE_ERROR_INDX_33  = 0x420,  /*!< Cache error index: 33 */
    RH850_ICACHE_ERROR_INDX_34  = 0x440,  /*!< Cache error index: 34 */
    RH850_ICACHE_ERROR_INDX_35  = 0x460,  /*!< Cache error index: 35 */
    RH850_ICACHE_ERROR_INDX_36  = 0x480,  /*!< Cache error index: 36 */
    RH850_ICACHE_ERROR_INDX_37  = 0x4A0,  /*!< Cache error index: 37 */
    RH850_ICACHE_ERROR_INDX_38  = 0x4C0,  /*!< Cache error index: 38 */
    RH850_ICACHE_ERROR_INDX_39  = 0x4E0,  /*!< Cache error index: 39 */
    RH850_ICACHE_ERROR_INDX_40  = 0x500,  /*!< Cache error index: 40 */
    RH850_ICACHE_ERROR_INDX_41  = 0x520,  /*!< Cache error index: 41 */
    RH850_ICACHE_ERROR_INDX_42  = 0x540,  /*!< Cache error index: 42 */
    RH850_ICACHE_ERROR_INDX_43  = 0x560,  /*!< Cache error index: 43 */
    RH850_ICACHE_ERROR_INDX_44  = 0x580,  /*!< Cache error index: 44 */
    RH850_ICACHE_ERROR_INDX_45  = 0x5A0,  /*!< Cache error index: 45 */
    RH850_ICACHE_ERROR_INDX_46  = 0x5C0,  /*!< Cache error index: 46 */
    RH850_ICACHE_ERROR_INDX_47  = 0x5E0,  /*!< Cache error index: 47 */
    RH850_ICACHE_ERROR_INDX_48  = 0x600,  /*!< Cache error index: 48 */
    RH850_ICACHE_ERROR_INDX_49  = 0x620,  /*!< Cache error index: 49 */
    RH850_ICACHE_ERROR_INDX_50  = 0x640,  /*!< Cache error index: 50 */
    RH850_ICACHE_ERROR_INDX_51  = 0x660,  /*!< Cache error index: 51 */
    RH850_ICACHE_ERROR_INDX_52  = 0x680,  /*!< Cache error index: 52 */
    RH850_ICACHE_ERROR_INDX_53  = 0x6A0,  /*!< Cache error index: 53 */
    RH850_ICACHE_ERROR_INDX_54  = 0x6C0,  /*!< Cache error index: 54 */
    RH850_ICACHE_ERROR_INDX_55  = 0x6E0,  /*!< Cache error index: 55 */
    RH850_ICACHE_ERROR_INDX_56  = 0x700,  /*!< Cache error index: 56 */
    RH850_ICACHE_ERROR_INDX_57  = 0x720,  /*!< Cache error index: 57 */
    RH850_ICACHE_ERROR_INDX_58  = 0x740,  /*!< Cache error index: 58 */
    RH850_ICACHE_ERROR_INDX_59  = 0x760,  /*!< Cache error index: 59 */
    RH850_ICACHE_ERROR_INDX_60  = 0x780,  /*!< Cache error index: 60 */
    RH850_ICACHE_ERROR_INDX_61  = 0x7A0,  /*!< Cache error index: 61 */
    RH850_ICACHE_ERROR_INDX_62  = 0x7C0,  /*!< Cache error index: 62 */
    RH850_ICACHE_ERROR_INDX_63  = 0x7E0,  /*!< Cache error index: 63 */
    RH850_ICACHE_ERROR_INDX_64  = 0x800,  /*!< Cache error index: 64 */
    RH850_ICACHE_ERROR_INDX_65  = 0x820,  /*!< Cache error index: 65 */
    RH850_ICACHE_ERROR_INDX_66  = 0x840,  /*!< Cache error index: 66 */
    RH850_ICACHE_ERROR_INDX_67  = 0x860,  /*!< Cache error index: 67 */
    RH850_ICACHE_ERROR_INDX_68  = 0x880,  /*!< Cache error index: 68 */
    RH850_ICACHE_ERROR_INDX_69  = 0x8A0,  /*!< Cache error index: 69 */
    RH850_ICACHE_ERROR_INDX_70  = 0x8C0,  /*!< Cache error index: 70 */
    RH850_ICACHE_ERROR_INDX_71  = 0x8E0,  /*!< Cache error index: 71 */
    RH850_ICACHE_ERROR_INDX_72  = 0x900,  /*!< Cache error index: 72 */
    RH850_ICACHE_ERROR_INDX_73  = 0x920,  /*!< Cache error index: 73 */
    RH850_ICACHE_ERROR_INDX_74  = 0x940,  /*!< Cache error index: 74 */
    RH850_ICACHE_ERROR_INDX_75  = 0x960,  /*!< Cache error index: 75 */
    RH850_ICACHE_ERROR_INDX_76  = 0x980,  /*!< Cache error index: 76 */
    RH850_ICACHE_ERROR_INDX_77  = 0x9A0,  /*!< Cache error index: 77 */
    RH850_ICACHE_ERROR_INDX_78  = 0x9C0,  /*!< Cache error index: 78 */
    RH850_ICACHE_ERROR_INDX_79  = 0x9E0,  /*!< Cache error index: 79 */
    RH850_ICACHE_ERROR_INDX_80  = 0xA00,  /*!< Cache error index: 80 */
    RH850_ICACHE_ERROR_INDX_81  = 0xA20,  /*!< Cache error index: 81 */
    RH850_ICACHE_ERROR_INDX_82  = 0xA40,  /*!< Cache error index: 82 */
    RH850_ICACHE_ERROR_INDX_83  = 0xA60,  /*!< Cache error index: 83 */
    RH850_ICACHE_ERROR_INDX_84  = 0xA80,  /*!< Cache error index: 84 */
    RH850_ICACHE_ERROR_INDX_85  = 0xAA0,  /*!< Cache error index: 85 */
    RH850_ICACHE_ERROR_INDX_86  = 0xAC0,  /*!< Cache error index: 86 */
    RH850_ICACHE_ERROR_INDX_87  = 0xAE0,  /*!< Cache error index: 87 */
    RH850_ICACHE_ERROR_INDX_88  = 0xB00,  /*!< Cache error index: 88 */
    RH850_ICACHE_ERROR_INDX_89  = 0xB20,  /*!< Cache error index: 89 */
    RH850_ICACHE_ERROR_INDX_90  = 0xB40,  /*!< Cache error index: 90 */
    RH850_ICACHE_ERROR_INDX_91  = 0xB60,  /*!< Cache error index: 91 */
    RH850_ICACHE_ERROR_INDX_92  = 0xB80,  /*!< Cache error index: 92 */
    RH850_ICACHE_ERROR_INDX_93  = 0xBA0,  /*!< Cache error index: 93 */
    RH850_ICACHE_ERROR_INDX_94  = 0xBC0,  /*!< Cache error index: 94 */
    RH850_ICACHE_ERROR_INDX_95  = 0xBE0,  /*!< Cache error index: 95 */
    RH850_ICACHE_ERROR_INDX_96  = 0xC00,  /*!< Cache error index: 96 */
    RH850_ICACHE_ERROR_INDX_97  = 0xC20,  /*!< Cache error index: 97 */
    RH850_ICACHE_ERROR_INDX_98  = 0xC40,  /*!< Cache error index: 98 */
    RH850_ICACHE_ERROR_INDX_99  = 0xC60,  /*!< Cache error index: 99 */
    RH850_ICACHE_ERROR_INDX_100 = 0xC80,  /*!< Cache error index: 100 */
    RH850_ICACHE_ERROR_INDX_101 = 0xCA0,  /*!< Cache error index: 101 */
    RH850_ICACHE_ERROR_INDX_102 = 0xCC0,  /*!< Cache error index: 102 */
    RH850_ICACHE_ERROR_INDX_103 = 0xCE0,  /*!< Cache error index: 103 */
    RH850_ICACHE_ERROR_INDX_104 = 0xD00,  /*!< Cache error index: 104 */
    RH850_ICACHE_ERROR_INDX_105 = 0xD20,  /*!< Cache error index: 105 */
    RH850_ICACHE_ERROR_INDX_106 = 0xD40,  /*!< Cache error index: 106 */
    RH850_ICACHE_ERROR_INDX_107 = 0xD60,  /*!< Cache error index: 107 */
    RH850_ICACHE_ERROR_INDX_108 = 0xD80,  /*!< Cache error index: 108 */
    RH850_ICACHE_ERROR_INDX_109 = 0xDA0,  /*!< Cache error index: 109 */
    RH850_ICACHE_ERROR_INDX_110 = 0xDC0,  /*!< Cache error index: 110 */
    RH850_ICACHE_ERROR_INDX_111 = 0xDE0,  /*!< Cache error index: 111 */
    RH850_ICACHE_ERROR_INDX_112 = 0xE00,  /*!< Cache error index: 112 */
    RH850_ICACHE_ERROR_INDX_113 = 0xE20,  /*!< Cache error index: 113 */
    RH850_ICACHE_ERROR_INDX_114 = 0xE40,  /*!< Cache error index: 114 */
    RH850_ICACHE_ERROR_INDX_115 = 0xE60,  /*!< Cache error index: 115 */
    RH850_ICACHE_ERROR_INDX_116 = 0xE80,  /*!< Cache error index: 116 */
    RH850_ICACHE_ERROR_INDX_117 = 0xEA0,  /*!< Cache error index: 117 */
    RH850_ICACHE_ERROR_INDX_118 = 0xEC0,  /*!< Cache error index: 118 */
    RH850_ICACHE_ERROR_INDX_119 = 0xEE0,  /*!< Cache error index: 119 */
    RH850_ICACHE_ERROR_INDX_120 = 0xF00,  /*!< Cache error index: 120 */
    RH850_ICACHE_ERROR_INDX_121 = 0xF20,  /*!< Cache error index: 121 */
    RH850_ICACHE_ERROR_INDX_122 = 0xF40,  /*!< Cache error index: 122 */
    RH850_ICACHE_ERROR_INDX_123 = 0xF60,  /*!< Cache error index: 123 */
    RH850_ICACHE_ERROR_INDX_124 = 0xF80,  /*!< Cache error index: 124 */
    RH850_ICACHE_ERROR_INDX_125 = 0xFA0,  /*!< Cache error index: 125 */
    RH850_ICACHE_ERROR_INDX_126 = 0xFC0,  /*!< Cache error index: 126 */
    RH850_ICACHE_ERROR_INDX_127 = 0xFE0,  /*!< Cache error index: 127 */
    RH850_ICACHE_ERROR_INDX_128 = 0x1000, /*!< Cache error index: 128 */
    RH850_ICACHE_ERROR_INDX_129 = 0x1020, /*!< Cache error index: 129 */
    RH850_ICACHE_ERROR_INDX_130 = 0x1040, /*!< Cache error index: 130 */
    RH850_ICACHE_ERROR_INDX_131 = 0x1060, /*!< Cache error index: 131 */
    RH850_ICACHE_ERROR_INDX_132 = 0x1080, /*!< Cache error index: 132 */
    RH850_ICACHE_ERROR_INDX_133 = 0x10A0, /*!< Cache error index: 133 */
    RH850_ICACHE_ERROR_INDX_134 = 0x10C0, /*!< Cache error index: 134 */
    RH850_ICACHE_ERROR_INDX_135 = 0x10E0, /*!< Cache error index: 135 */
    RH850_ICACHE_ERROR_INDX_136 = 0x1100, /*!< Cache error index: 136 */
    RH850_ICACHE_ERROR_INDX_137 = 0x1120, /*!< Cache error index: 137 */
    RH850_ICACHE_ERROR_INDX_138 = 0x1140, /*!< Cache error index: 138 */
    RH850_ICACHE_ERROR_INDX_139 = 0x1160, /*!< Cache error index: 139 */
    RH850_ICACHE_ERROR_INDX_140 = 0x1180, /*!< Cache error index: 140 */
    RH850_ICACHE_ERROR_INDX_141 = 0x11A0, /*!< Cache error index: 141 */
    RH850_ICACHE_ERROR_INDX_142 = 0x11C0, /*!< Cache error index: 142 */
    RH850_ICACHE_ERROR_INDX_143 = 0x11E0, /*!< Cache error index: 143 */
    RH850_ICACHE_ERROR_INDX_144 = 0x1200, /*!< Cache error index: 144 */
    RH850_ICACHE_ERROR_INDX_145 = 0x1220, /*!< Cache error index: 145 */
    RH850_ICACHE_ERROR_INDX_146 = 0x1240, /*!< Cache error index: 146 */
    RH850_ICACHE_ERROR_INDX_147 = 0x1260, /*!< Cache error index: 147 */
    RH850_ICACHE_ERROR_INDX_148 = 0x1280, /*!< Cache error index: 148 */
    RH850_ICACHE_ERROR_INDX_149 = 0x12A0, /*!< Cache error index: 149 */
    RH850_ICACHE_ERROR_INDX_150 = 0x12C0, /*!< Cache error index: 150 */
    RH850_ICACHE_ERROR_INDX_151 = 0x12E0, /*!< Cache error index: 151 */
    RH850_ICACHE_ERROR_INDX_152 = 0x1300, /*!< Cache error index: 152 */
    RH850_ICACHE_ERROR_INDX_153 = 0x1320, /*!< Cache error index: 153 */
    RH850_ICACHE_ERROR_INDX_154 = 0x1340, /*!< Cache error index: 154 */
    RH850_ICACHE_ERROR_INDX_155 = 0x1360, /*!< Cache error index: 155 */
    RH850_ICACHE_ERROR_INDX_156 = 0x1380, /*!< Cache error index: 156 */
    RH850_ICACHE_ERROR_INDX_157 = 0x13A0, /*!< Cache error index: 157 */
    RH850_ICACHE_ERROR_INDX_158 = 0x13C0, /*!< Cache error index: 158 */
    RH850_ICACHE_ERROR_INDX_159 = 0x13E0, /*!< Cache error index: 159 */
    RH850_ICACHE_ERROR_INDX_160 = 0x1400, /*!< Cache error index: 160 */
    RH850_ICACHE_ERROR_INDX_161 = 0x1420, /*!< Cache error index: 161 */
    RH850_ICACHE_ERROR_INDX_162 = 0x1440, /*!< Cache error index: 162 */
    RH850_ICACHE_ERROR_INDX_163 = 0x1460, /*!< Cache error index: 163 */
    RH850_ICACHE_ERROR_INDX_164 = 0x1480, /*!< Cache error index: 164 */
    RH850_ICACHE_ERROR_INDX_165 = 0x14A0, /*!< Cache error index: 165 */
    RH850_ICACHE_ERROR_INDX_166 = 0x14C0, /*!< Cache error index: 166 */
    RH850_ICACHE_ERROR_INDX_167 = 0x14E0, /*!< Cache error index: 167 */
    RH850_ICACHE_ERROR_INDX_168 = 0x1500, /*!< Cache error index: 168 */
    RH850_ICACHE_ERROR_INDX_169 = 0x1520, /*!< Cache error index: 169 */
    RH850_ICACHE_ERROR_INDX_170 = 0x1540, /*!< Cache error index: 170 */
    RH850_ICACHE_ERROR_INDX_171 = 0x1560, /*!< Cache error index: 171 */
    RH850_ICACHE_ERROR_INDX_172 = 0x1580, /*!< Cache error index: 172 */
    RH850_ICACHE_ERROR_INDX_173 = 0x15A0, /*!< Cache error index: 173 */
    RH850_ICACHE_ERROR_INDX_174 = 0x15C0, /*!< Cache error index: 174 */
    RH850_ICACHE_ERROR_INDX_175 = 0x15E0, /*!< Cache error index: 175 */
    RH850_ICACHE_ERROR_INDX_176 = 0x1600, /*!< Cache error index: 176 */
    RH850_ICACHE_ERROR_INDX_177 = 0x1620, /*!< Cache error index: 177 */
    RH850_ICACHE_ERROR_INDX_178 = 0x1640, /*!< Cache error index: 178 */
    RH850_ICACHE_ERROR_INDX_179 = 0x1660, /*!< Cache error index: 179 */
    RH850_ICACHE_ERROR_INDX_180 = 0x1680, /*!< Cache error index: 180 */
    RH850_ICACHE_ERROR_INDX_181 = 0x16A0, /*!< Cache error index: 181 */
    RH850_ICACHE_ERROR_INDX_182 = 0x16C0, /*!< Cache error index: 182 */
    RH850_ICACHE_ERROR_INDX_183 = 0x16E0, /*!< Cache error index: 183 */
    RH850_ICACHE_ERROR_INDX_184 = 0x1700, /*!< Cache error index: 184 */
    RH850_ICACHE_ERROR_INDX_185 = 0x1720, /*!< Cache error index: 185 */
    RH850_ICACHE_ERROR_INDX_186 = 0x1740, /*!< Cache error index: 186 */
    RH850_ICACHE_ERROR_INDX_187 = 0x1760, /*!< Cache error index: 187 */
    RH850_ICACHE_ERROR_INDX_188 = 0x1780, /*!< Cache error index: 188 */
    RH850_ICACHE_ERROR_INDX_189 = 0x17A0, /*!< Cache error index: 189 */
    RH850_ICACHE_ERROR_INDX_190 = 0x17C0, /*!< Cache error index: 190 */
    RH850_ICACHE_ERROR_INDX_191 = 0x17E0, /*!< Cache error index: 191 */
    RH850_ICACHE_ERROR_INDX_192 = 0x1800, /*!< Cache error index: 192 */
    RH850_ICACHE_ERROR_INDX_193 = 0x1820, /*!< Cache error index: 193 */
    RH850_ICACHE_ERROR_INDX_194 = 0x1840, /*!< Cache error index: 194 */
    RH850_ICACHE_ERROR_INDX_195 = 0x1860, /*!< Cache error index: 195 */
    RH850_ICACHE_ERROR_INDX_196 = 0x1880, /*!< Cache error index: 196 */
    RH850_ICACHE_ERROR_INDX_197 = 0x18A0, /*!< Cache error index: 197 */
    RH850_ICACHE_ERROR_INDX_198 = 0x18C0, /*!< Cache error index: 198 */
    RH850_ICACHE_ERROR_INDX_199 = 0x18E0, /*!< Cache error index: 199 */
    RH850_ICACHE_ERROR_INDX_200 = 0x1900, /*!< Cache error index: 200 */
    RH850_ICACHE_ERROR_INDX_201 = 0x1920, /*!< Cache error index: 201 */
    RH850_ICACHE_ERROR_INDX_202 = 0x1940, /*!< Cache error index: 202 */
    RH850_ICACHE_ERROR_INDX_203 = 0x1960, /*!< Cache error index: 203 */
    RH850_ICACHE_ERROR_INDX_204 = 0x1980, /*!< Cache error index: 204 */
    RH850_ICACHE_ERROR_INDX_205 = 0x19A0, /*!< Cache error index: 205 */
    RH850_ICACHE_ERROR_INDX_206 = 0x19C0, /*!< Cache error index: 206 */
    RH850_ICACHE_ERROR_INDX_207 = 0x19E0, /*!< Cache error index: 207 */
    RH850_ICACHE_ERROR_INDX_208 = 0x1A00, /*!< Cache error index: 208 */
    RH850_ICACHE_ERROR_INDX_209 = 0x1A20, /*!< Cache error index: 209 */
    RH850_ICACHE_ERROR_INDX_210 = 0x1A40, /*!< Cache error index: 210 */
    RH850_ICACHE_ERROR_INDX_211 = 0x1A60, /*!< Cache error index: 211 */
    RH850_ICACHE_ERROR_INDX_212 = 0x1A80, /*!< Cache error index: 212 */
    RH850_ICACHE_ERROR_INDX_213 = 0x1AA0, /*!< Cache error index: 213 */
    RH850_ICACHE_ERROR_INDX_214 = 0x1AC0, /*!< Cache error index: 214 */
    RH850_ICACHE_ERROR_INDX_215 = 0x1AE0, /*!< Cache error index: 215 */
    RH850_ICACHE_ERROR_INDX_216 = 0x1B00, /*!< Cache error index: 216 */
    RH850_ICACHE_ERROR_INDX_217 = 0x1B20, /*!< Cache error index: 217 */
    RH850_ICACHE_ERROR_INDX_218 = 0x1B40, /*!< Cache error index: 218 */
    RH850_ICACHE_ERROR_INDX_219 = 0x1B60, /*!< Cache error index: 219 */
    RH850_ICACHE_ERROR_INDX_220 = 0x1B80, /*!< Cache error index: 220 */
    RH850_ICACHE_ERROR_INDX_221 = 0x1BA0, /*!< Cache error index: 221 */
    RH850_ICACHE_ERROR_INDX_222 = 0x1BC0, /*!< Cache error index: 222 */
    RH850_ICACHE_ERROR_INDX_223 = 0x1BE0, /*!< Cache error index: 223 */
    RH850_ICACHE_ERROR_INDX_224 = 0x1C00, /*!< Cache error index: 224 */
    RH850_ICACHE_ERROR_INDX_225 = 0x1C20, /*!< Cache error index: 225 */
    RH850_ICACHE_ERROR_INDX_226 = 0x1C40, /*!< Cache error index: 226 */
    RH850_ICACHE_ERROR_INDX_227 = 0x1C60, /*!< Cache error index: 227 */
    RH850_ICACHE_ERROR_INDX_228 = 0x1C80, /*!< Cache error index: 228 */
    RH850_ICACHE_ERROR_INDX_229 = 0x1CA0, /*!< Cache error index: 229 */
    RH850_ICACHE_ERROR_INDX_230 = 0x1CC0, /*!< Cache error index: 230 */
    RH850_ICACHE_ERROR_INDX_231 = 0x1CE0, /*!< Cache error index: 231 */
    RH850_ICACHE_ERROR_INDX_232 = 0x1D00, /*!< Cache error index: 232 */
    RH850_ICACHE_ERROR_INDX_233 = 0x1D20, /*!< Cache error index: 233 */
    RH850_ICACHE_ERROR_INDX_234 = 0x1D40, /*!< Cache error index: 234 */
    RH850_ICACHE_ERROR_INDX_235 = 0x1D60, /*!< Cache error index: 235 */
    RH850_ICACHE_ERROR_INDX_236 = 0x1D80, /*!< Cache error index: 236 */
    RH850_ICACHE_ERROR_INDX_237 = 0x1DA0, /*!< Cache error index: 237 */
    RH850_ICACHE_ERROR_INDX_238 = 0x1DC0, /*!< Cache error index: 238 */
    RH850_ICACHE_ERROR_INDX_239 = 0x1DE0, /*!< Cache error index: 239 */
    RH850_ICACHE_ERROR_INDX_240 = 0x1E00, /*!< Cache error index: 240 */
    RH850_ICACHE_ERROR_INDX_241 = 0x1E20, /*!< Cache error index: 241 */
    RH850_ICACHE_ERROR_INDX_242 = 0x1E40, /*!< Cache error index: 242 */
    RH850_ICACHE_ERROR_INDX_243 = 0x1E60, /*!< Cache error index: 243 */
    RH850_ICACHE_ERROR_INDX_244 = 0x1E80, /*!< Cache error index: 244 */
    RH850_ICACHE_ERROR_INDX_245 = 0x1EA0, /*!< Cache error index: 245 */
    RH850_ICACHE_ERROR_INDX_246 = 0x1EC0, /*!< Cache error index: 246 */
    RH850_ICACHE_ERROR_INDX_247 = 0x1EE0, /*!< Cache error index: 247 */
    RH850_ICACHE_ERROR_INDX_248 = 0x1F00, /*!< Cache error index: 248 */
    RH850_ICACHE_ERROR_INDX_249 = 0x1F20, /*!< Cache error index: 249 */
    RH850_ICACHE_ERROR_INDX_250 = 0x1F40, /*!< Cache error index: 250 */
    RH850_ICACHE_ERROR_INDX_251 = 0x1F60, /*!< Cache error index: 251 */
    RH850_ICACHE_ERROR_INDX_252 = 0x1F80, /*!< Cache error index: 252 */
    RH850_ICACHE_ERROR_INDX_253 = 0x1FA0, /*!< Cache error index: 253 */
    RH850_ICACHE_ERROR_INDX_254 = 0x1FC0, /*!< Cache error index: 254 */
    RH850_ICACHE_ERROR_INDX_255 = 0x1FE0  /*!< Cache error index: 255 */
} rh850_icache_error_indx_t;

/**
 * @enum rh850_icache_error_way_t
 * @brief Cache error way values.
 * @details Mirrors the ICERR.ICHEWY field to indicate in which way an error occurred. Use this value along with
 *          the index to locate the failing cache line.
 */
typedef enum e_rh850_icache_error_way
{
    RH850_ICACHE_ERROR_WAY_0 = 0x0000, /*!< Cache error way: 0 */
    RH850_ICACHE_ERROR_WAY_1 = 0x2000, /*!< Cache error way: 1 */
    RH850_ICACHE_ERROR_WAY_2 = 0x4000, /*!< Cache error way: 2 */
    RH850_ICACHE_ERROR_WAY_3 = 0x6000  /*!< Cache error way: 3 */
} rh850_icache_error_way_t;

/**
 * @enum rh850_icache_enable_t
 * @brief Cache enable state.
 * @details Indicates whether the instruction cache is enabled (ON) or disabled (OFF) as reflected by ICCTRL.ICHEN.
 */
typedef enum e_rh850_icache_enable
{
    RH850_ICACHE_ENABLE_OFF = 0x0,     /*!< Cache enable: OFF */
    RH850_ICACHE_ENABLE_ON  = 0x1      /*!< Cache enable: ON */
} rh850_icache_enable_t;

/**
 * @enum rh850_icache_auto_invalidate_mode_t
 * @brief Auto-invalidate on error mode.
 * @details Controls automatic invalidation when a cache error occurs. When enabled, hardware clears ICHEN on error
 *          to prevent further fetches from corrupted lines.
 */
typedef enum e_rh850_icache_auto_invalidate_mode
{
    RH850_ICACHE_AUTO_INVALIDATE_MODE_DISABLE = 0, /*!< Auto invalidate mode: DISABLE */
    RH850_ICACHE_AUTO_INVALIDATE_MODE_ENABLE  = 1  /*!< Auto invalidate mode: ENABLE */
} rh850_icache_auto_invalidate_mode_t;

/**
 * @enum rh850_icache_notify_t
 * @brief Error notification mask mode.
 * @details Controls ICHEMK (mask/unmask cache error notification).
 */
typedef enum e_rh850_icache_notify
{
    RH850_ICACHE_NOTIFY_UNMASK = 0,    /*!< Cache notify: UNMASK */
    RH850_ICACHE_NOTIFY_MASK   = 1     /*!< Cache notify: MASK */
} rh850_icache_notify_t;

/** @} */ /* end of RH850_ICACHE_Types */

/* ##########################################  ICACHE API Functions  ################################################ */

/**
 * @defgroup RH850_ICACHE_API ICACHE API Functions
 * @brief ICACHE API Functions
 * @ingroup  RH850_ICACHE
 * @{
 */

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/**
 * @brief   Enable the instruction cache.
 * @details Reads ICCTRL, sets ICHEN, writes back. Other bits are preserved.
 */
__STATIC_INLINE void __RH850_ICache_Enable (void)
{
    uint32_t LulIcctrlRegValue;

    /* Read current control */
    LulIcctrlRegValue = __get_ICCTRL();

    /* Enable cache */
    LulIcctrlRegValue |= R_ICACHE_ICCTRL_ICHEN_Msk;

    /* Write back */
    __set_ICCTRL(LulIcctrlRegValue);

    /* Synchronizes instruction pipeline */
    __SYNCI();
}

/**
 * @brief   Disable the instruction cache.
 * @details Clears ICHEN via read-modify-write. Other bits preserved.
 */
__STATIC_INLINE void __RH850_ICache_Disable (void)
{
    uint32_t LulIcctrlRegValue;

    /* Read current control */
    LulIcctrlRegValue  = __get_ICCTRL();
    LulIcctrlRegValue &= (~R_ICACHE_ICCTRL_ICHEN_Msk);

    /* Write back */
    __set_ICCTRL(LulIcctrlRegValue);

    /* Synchronizes instruction pipeline */
    __SYNCI();
}

/**
 * @brief   Get the instruction cache size.
 * @details Masks ICCFG.ICHSIZE and returns a rh850_icache_size_t.
 * @return  Cache size enumeration.
 */
__STATIC_INLINE rh850_icache_size_t __RH850_ICache_CacheSizeGet (void)
{
    /* Mask size field */
    return (rh850_icache_size_t) (__get_ICCFG() & R_ICACHE_ICCFG_ICHSIZE_Msk);
}

/**
 * @brief   Get lines per way.
 * @details Masks ICCFG.ICHLINE and returns a rh850_icache_line_t.
 * @return  Lines-per-way enumeration.
 */
__STATIC_INLINE rh850_icache_line_t __RH850_ICache_LinesPerWayGet (void)
{
    return (rh850_icache_line_t) (__get_ICCFG() & R_ICACHE_ICCFG_ICHLINE_Msk);
}

/**
 * @brief   Get number of ways.
 * @details Masks ICCFG.ICHWAY and returns a rh850_icache_way_t.
 * @return  Ways enumeration.
 */
__STATIC_INLINE rh850_icache_way_t __RH850_ICache_NumberOfWaysGet (void)
{
    return (rh850_icache_way_t) (__get_ICCFG() & R_ICACHE_ICCFG_ICHWAY_Msk);
}

/**
 * @brief   Get raw error register snapshot.
 * @details Returns the ICERR typed value for bitfield inspection.
 * @return  uint32_t snapshot.
 */
__STATIC_INLINE uint32_t __RH850_ICache_ErrorStatusGet (void)
{
    return (uint32_t) __get_ICERR();
}

/**
 * @brief   Get the error index from ICERR.
 * @details Extracts ICERR.ICHEIX into rh850_icache_error_indx_t.
 * @return  Error index enumeration.
 */
__STATIC_INLINE rh850_icache_error_indx_t __RH850_ICache_ErrorIndexGet (void)
{
    return (rh850_icache_error_indx_t) (__get_ICERR() & R_ICACHE_ICERR_ICHEIX_Msk);
}

/**
 * @brief   Get the error way from ICERR.
 * @details Extracts ICERR.ICHEWY into rh850_icache_error_way_t.
 * @return  Error way enumeration.
 */
__STATIC_INLINE rh850_icache_error_way_t __RH850_ICache_ErrorWayGet (void)
{
    return (rh850_icache_error_way_t) (__get_ICERR() & R_ICACHE_ICERR_ICHEWY_Msk);
}

/**
 * @brief   Get current cache enable state.
 * @details Reads ICCTRL.ICHEN and returns ON/OFF state.
 * @return  rh850_icache_enable_t state.
 */
__STATIC_INLINE rh850_icache_enable_t __RH850_ICache_EnableGet (void)
{
    return (0U != (__get_ICCTRL() & R_ICACHE_ICCTRL_ICHEN_Msk)) ? RH850_ICACHE_ENABLE_ON : RH850_ICACHE_ENABLE_OFF;
}

/**
 * @brief   Clear the entire instruction cache.
 * @details Sets ICCTRL.ICHCLR (write-only) to clear all lines and reset V/L & LRU info.
 */
__STATIC_INLINE void __RH850_ICache_Clear (void)
{
    uint32_t LulIcctrlRegValue;

    /* Set clear bit (write-only, reads as 0) */
    LulIcctrlRegValue  = __get_ICCTRL();
    LulIcctrlRegValue |= R_ICACHE_ICCTRL_ICHCLR_Msk;

    /* Write back */
    __set_ICCTRL(LulIcctrlRegValue);
}

/**
 * @brief   Configure auto-invalidate on cache error.
 * @details Sets or clears ICCTRL.ICHEIV according to @p LenMode.
 * @param   LenMode See rh850_icache_auto_invalidate_mode_t.
 */
__STATIC_INLINE void __RH850_ICache_AutoInvalidateOnErrorSet (rh850_icache_auto_invalidate_mode_t LenMode)
{
    uint32_t LulIcctrlRegValue;

    /* Clear bit, then apply mode */
    LulIcctrlRegValue  = __get_ICCTRL();
    LulIcctrlRegValue &= ~R_ICACHE_ICCTRL_ICHEIV_Msk;
    if (RH850_ICACHE_AUTO_INVALIDATE_MODE_ENABLE == LenMode)
    {
        LulIcctrlRegValue |= R_ICACHE_ICCTRL_ICHEIV_Msk;
    }

    __set_ICCTRL(LulIcctrlRegValue);
}

/**
 * @brief   Configure error notification masking.
 * @details Sets or clears ICCTRL.ICHEMK according to @p LenMode.
 * @param   LenMode See rh850_icache_notify_t.
 */
__STATIC_INLINE void __RH850_ICache_ErrorNotifyMaskSet (rh850_icache_notify_t LenMode)
{
    uint32_t LulIcctrlRegValue;

    /* Clear bit, then apply mode */
    LulIcctrlRegValue  = __get_ICCTRL();
    LulIcctrlRegValue &= ~R_ICACHE_ICCTRL_ICHEMK_Msk;
    if (RH850_ICACHE_NOTIFY_MASK == LenMode)
    {
        LulIcctrlRegValue |= R_ICACHE_ICCTRL_ICHEMK_Msk;
    }

    __set_ICCTRL(LulIcctrlRegValue);
}

/**
 * @brief   Read the Tag Low register snapshot.
 * @details Returns uint32_t for V/L bits, LRU info, and LPN inspection.
 * @return  uint32_t value.
 */
__STATIC_INLINE uint32_t __RH850_ICache_TagLoGet (void)
{
    return (uint32_t) __get_ICTAGL();
}

/**
 * @brief   Write the Tag Low register.
 * @details Writes uint32_t to ICTAGL; use correct WT semantics.
 * @param   LulValue Tag Low typed value to write.
 */
__STATIC_INLINE void __RH850_ICache_TagLoSet (uint32_t LulValue)
{
    __set_ICTAGL(LulValue);
}

/**
 * @brief   Read the Tag High register snapshot.
 * @details Returns uint32_t for ECC control and related flags.
 * @return  uint32_t value.
 */
__STATIC_INLINE uint32_t __RH850_ICache_TagHiGet (void)
{
    return (uint32_t) __get_ICTAGH();
}

/**
 * @brief Write the Tag High register.
 * @details Writes an uint32_t value to the ICTAGH register to update ECC data or control flags.
 * @param LulValue Tag High typed value to write.
 */
__STATIC_INLINE void __RH850_ICache_TagHiSet (uint32_t LulValue)
{
    __set_ICTAGH(LulValue);
}

/**
 * @brief Read lower 32 bits of the cache data block.
 * @details Returns the ICDATL register value which corresponds to lower half of a 64-bit instruction data word.
 * @return Lower 32 bits of cache data.
 */
__STATIC_INLINE uint32_t __RH850_ICache_DataLoGet (void)
{
    return (uint32_t) __get_ICDATL();
}

/**
 * @brief Write lower 32 bits of the cache data block.
 * @details Writes to ICDATL the lower half of a 64-bit instruction data word. Ensure correct index/way selection and
 *          ECC handling according to ICTAGH settings.
 * @param LulData Lower 32-bit payload to write.
 */
__STATIC_INLINE void __RH850_ICache_DataLoSet (uint32_t LulData)
{
    __set_ICDATL(LulData);
}

/**
 * @brief Read upper 32 bits of the cache data block.
 * @details Returns the ICDATH register value which corresponds to upper half of a 64-bit instruction data word.
 * @return Upper 32 bits of cache data.
 */
__STATIC_INLINE uint32_t __RH850_ICache_DataHiGet (void)
{
    return (uint32_t) __get_ICDATH();
}

/**
 * @brief Write upper 32 bits of the cache data block.
 * @details Writes to ICDATH the upper half of a 64-bit instruction data word. Ensure correct index/way selection and
 *          ECC handling according to ICTAGH settings.
 * @param LulData Upper 32-bit payload to write.
 */
__STATIC_INLINE void __RH850_ICache_DataHiSet (uint32_t LulData)
{
    __set_ICDATH(LulData);
}

/** @} */ /* end of RH850_ICACHE_API */

#endif                                 /* RH850_G4_ICACHE_H */

/** @} */ /* end of RH850_ICACHE */
/** @} */ /* end of RH850_CoreAccess_FunctionInterface */

#endif                                 /* #if defined(__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U) */
