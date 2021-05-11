/*
 * MessagePack unpacking routine template
 *
 * Copyright (C) 2008-2010 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_UNPACK_DEFINE_H
#define AGPACK_UNPACK_DEFINE_H

#include "agpack/sysdep.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef AGPACK_EMBED_STACK_SIZE
#define AGPACK_EMBED_STACK_SIZE 32
#endif


typedef enum {
    AGPACK_CS_HEADER            = 0x00,  // nil

    //AGPACK_CS_                = 0x01,
    //AGPACK_CS_                = 0x02,  // false
    //AGPACK_CS_                = 0x03,  // true

    AGPACK_CS_BIN_8             = 0x04,
    AGPACK_CS_BIN_16            = 0x05,
    AGPACK_CS_BIN_32            = 0x06,

    AGPACK_CS_EXT_8             = 0x07,
    AGPACK_CS_EXT_16            = 0x08,
    AGPACK_CS_EXT_32            = 0x09,

    AGPACK_CS_FLOAT             = 0x0a,
    AGPACK_CS_DOUBLE            = 0x0b,
    AGPACK_CS_UINT_8            = 0x0c,
    AGPACK_CS_UINT_16           = 0x0d,
    AGPACK_CS_UINT_32           = 0x0e,
    AGPACK_CS_UINT_64           = 0x0f,
    AGPACK_CS_INT_8             = 0x10,
    AGPACK_CS_INT_16            = 0x11,
    AGPACK_CS_INT_32            = 0x12,
    AGPACK_CS_INT_64            = 0x13,

    AGPACK_CS_FIXEXT_1          = 0x14,
    AGPACK_CS_FIXEXT_2          = 0x15,
    AGPACK_CS_FIXEXT_4          = 0x16,
    AGPACK_CS_FIXEXT_8          = 0x17,
    AGPACK_CS_FIXEXT_16         = 0x18,

    AGPACK_CS_STR_8             = 0x19, // str8
    AGPACK_CS_STR_16            = 0x1a, // str16
    AGPACK_CS_STR_32            = 0x1b, // str32
    AGPACK_CS_ARRAY_16          = 0x1c,
    AGPACK_CS_ARRAY_32          = 0x1d,
    AGPACK_CS_MAP_16            = 0x1e,
    AGPACK_CS_MAP_32            = 0x1f,

    //AGPACK_ACS_BIG_INT_VALUE,
    //AGPACK_ACS_BIG_FLOAT_VALUE,
    AGPACK_ACS_STR_VALUE,
    AGPACK_ACS_BIN_VALUE,
    AGPACK_ACS_EXT_VALUE
} agpack_unpack_state;


typedef enum {
    AGPACK_CT_ARRAY_ITEM,
    AGPACK_CT_MAP_KEY,
    AGPACK_CT_MAP_VALUE
} agpack_container_type;


#ifdef __cplusplus
}
#endif

#endif /* agpack/unpack_define.h */

