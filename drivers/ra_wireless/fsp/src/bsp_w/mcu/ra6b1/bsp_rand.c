/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "bsp_api.h"
#include "bsp_entropy.h"
#include "bsp_rand.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* ASCII of "expand 16-byte k" */
#define CHACHA_CONST_0    (0x61707865U)
#define CHACHA_CONST_1    (0x3120646EU)
#define CHACHA_CONST_2    (0x79622D36U)
#define CHACHA_CONST_3    (0x6B206574U)

#define CHACHA_ROUNDS     (10U)

/* Use optimized memcpy/memset for ARM Cortex-M33 */
#if defined(__GNUC__)
#define memcpy            fast_memcpy
#define memset            fast_memset
#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const uint32_t chacha_constants[4] =
{
    CHACHA_CONST_0, CHACHA_CONST_1, CHACHA_CONST_2, CHACHA_CONST_3
};

static const uint8_t chacha_order[8][4] =
{
    {0, 4, 8,  12},
    {1, 5, 9,  13},
    {2, 6, 10, 14},
    {3, 7, 11, 15},
    {0, 5, 10, 15},
    {1, 6, 11, 12},
    {2, 7, 8,  13},
    {3, 4, 9,  14}
};

static uint32_t chacha_key[4];
static uint64_t chacha_counter;
static uint32_t chacha_random_output[16];
static uint8_t  chacha_random_output_left;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static void chacha_quarterround(const uint8_t indices[4]);
static void chacha_run(void);

/***********************************************************************************************************************
 * Private functions
 **********************************************************************************************************************/

static void chacha_quarterround (const uint8_t indices[4])
{
    uint32_t * s = chacha_random_output;
    int        a = indices[0];
    int        b = indices[1];
    int        c = indices[2];
    int        d = indices[3];

    s[a] += s[b]; s[d] ^= s[a]; s[d] = (s[d] << 16) | (s[d] >> 16);
    s[c] += s[d]; s[b] ^= s[c]; s[b] = (s[b] << 12) | (s[b] >> 20);
    s[a] += s[b]; s[d] ^= s[a]; s[d] = (s[d] <<  8) | (s[d] >> 24);
    s[c] += s[d]; s[b] ^= s[c]; s[b] = (s[b] <<  7) | (s[b] >> 25);
}

static void chacha_run (void)
{
    uint32_t state[16];

    memcpy(state, chacha_constants, sizeof(chacha_constants));
    memcpy(state + 4, chacha_key, sizeof(chacha_key));
    memcpy(state + 8, chacha_key, sizeof(chacha_key));
    memset(state + 12, 0, 2U * sizeof(uint32_t));

    ++chacha_counter;
    memcpy(state + 14, &chacha_counter, sizeof(chacha_counter));

    memcpy(chacha_random_output, state, sizeof(state));

    for (uint32_t i = 0; i < CHACHA_ROUNDS; i++)
    {
        for (uint32_t j = 0; j < 8U; j++)
        {
            chacha_quarterround(chacha_order[j]);
        }
    }

    for (uint32_t i = 0; i < 16U; i++)
    {
        chacha_random_output[i] += state[i];
    }
}

/***********************************************************************************************************************
 * Public functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Seed the ChaCha20-based CSPRNG with a 16-byte key.
 *
 * @param[in] key    Pointer to a 16-byte seed value.
 **********************************************************************************************************************/
void bsp_csprng_seed (const uint8_t key[16])
{
    memcpy(chacha_key, key, sizeof(chacha_key));
    chacha_counter             = 0;
    chacha_random_output_left  = 0;
}

/*******************************************************************************************************************//**
 * Get the next pseudo-random 32-bit value from the ChaCha20-based CSPRNG.
 *
 * @retval A pseudo-random 32-bit unsigned integer.
 **********************************************************************************************************************/
uint32_t bsp_csprng_get_next_uint32 (void)
{
    if (chacha_random_output_left == 0U)
    {
        chacha_run();
        chacha_random_output_left = 16U;
    }

    return chacha_random_output[--chacha_random_output_left];
}

/*******************************************************************************************************************//**
 * Implementation of srand() function from standard C library.
 *
 * Overrides the standard srand() to seed the ChaCha20-based CSPRNG using a 16-byte seed
 * obtained from the M33 intrinsic library (bsp_entropy_get_seed).
 *
 * @param[in] seed    Ignored. The 16-byte hardware seed is used instead.
 **********************************************************************************************************************/
void srand (unsigned seed)
{
    (void) seed;

    uint8_t * p_seed = bsp_entropy_get_seed();

    if (p_seed != NULL)
    {
        bsp_csprng_seed(p_seed);
    }
}

/*******************************************************************************************************************//**
 * Implementation of rand() function from standard C library.
 *
 * Overrides the standard rand() and produces random values via the ChaCha20-based CSPRNG.
 *
 * @retval A pseudo-random integer in the range 0 to RAND_MAX inclusive.
 **********************************************************************************************************************/
int rand (void)
{
    return (int) (bsp_csprng_get_next_uint32() % (((uint32_t) RAND_MAX) + 1U));
}
