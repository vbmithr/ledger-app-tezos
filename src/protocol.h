#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "baking_auth.h"

#define MAGIC_BYTE_BLOCK 0x01
#define MAGIC_BYTE_BAKING_OP 0x02
#define MAGIC_BYTE_UNSAFE_OP 0x03
#define MAGIC_BYTE_UNSAFE_OP2 0x04
#define MAGIC_BYTE_UNSAFE_OP3 0x05

static inline uint8_t get_magic_byte(const uint8_t *data, size_t length) {
    if (length == 0) return 0x00;
    else return *data;
}

bool is_block_valid(const void *data, size_t length);

level_t get_block_level(const void *data, size_t length); // Precondition: is_block_valid returns true

#define READ_UNALIGNED_BIG_ENDIAN(type, in) \
    ({ \
        const uint8_t *bytes = (uint8_t*)in; \
        uint8_t out_bytes[sizeof(type)]; \
        type res; \
\
        for (size_t i = 0; i < sizeof(type); i++) { \
            out_bytes[i] = bytes[sizeof(type) - i - 1]; \
        } \
        memcpy(&res, out_bytes, sizeof(type)); \
\
        res; \
    })
