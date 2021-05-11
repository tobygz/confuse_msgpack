/*
 * MessagePack for C packing routine
 *
 * Copyright (C) 2008-2009 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_PACK_H
#define AGPACK_PACK_H

#include "pack_define.h"
#include "object.h"
#include "timestamp.h"
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup agpack_buffer Buffers
 * @ingroup agpack
 * @{
 * @}
 */

/**
 * @defgroup agpack_pack Serializer
 * @ingroup agpack
 * @{
 */

typedef int (*agpack_packer_write)(void* data, const char* buf, size_t len);

typedef struct agpack_packer {
    void* data;
    agpack_packer_write callback;
} agpack_packer;

static void agpack_packer_init(agpack_packer* pk, void* data, agpack_packer_write callback);

static agpack_packer* agpack_packer_new(void* data, agpack_packer_write callback);
static void agpack_packer_free(agpack_packer* pk);

static int agpack_pack_char(agpack_packer* pk, char d);

static int agpack_pack_signed_char(agpack_packer* pk, signed char d);
static int agpack_pack_short(agpack_packer* pk, short d);
static int agpack_pack_int(agpack_packer* pk, int d);
static int agpack_pack_long(agpack_packer* pk, long d);
static int agpack_pack_long_long(agpack_packer* pk, long long d);
static int agpack_pack_unsigned_char(agpack_packer* pk, unsigned char d);
static int agpack_pack_unsigned_short(agpack_packer* pk, unsigned short d);
static int agpack_pack_unsigned_int(agpack_packer* pk, unsigned int d);
static int agpack_pack_unsigned_long(agpack_packer* pk, unsigned long d);
static int agpack_pack_unsigned_long_long(agpack_packer* pk, unsigned long long d);

static int agpack_pack_uint8(agpack_packer* pk, uint8_t d);
static int agpack_pack_uint16(agpack_packer* pk, uint16_t d);
static int agpack_pack_uint32(agpack_packer* pk, uint32_t d);
static int agpack_pack_uint64(agpack_packer* pk, uint64_t d);
static int agpack_pack_int8(agpack_packer* pk, int8_t d);
static int agpack_pack_int16(agpack_packer* pk, int16_t d);
static int agpack_pack_int32(agpack_packer* pk, int32_t d);
static int agpack_pack_int64(agpack_packer* pk, int64_t d);

static int agpack_pack_fix_uint8(agpack_packer* pk, uint8_t d);
static int agpack_pack_fix_uint16(agpack_packer* pk, uint16_t d);
static int agpack_pack_fix_uint32(agpack_packer* pk, uint32_t d);
static int agpack_pack_fix_uint64(agpack_packer* pk, uint64_t d);
static int agpack_pack_fix_int8(agpack_packer* pk, int8_t d);
static int agpack_pack_fix_int16(agpack_packer* pk, int16_t d);
static int agpack_pack_fix_int32(agpack_packer* pk, int32_t d);
static int agpack_pack_fix_int64(agpack_packer* pk, int64_t d);

static int agpack_pack_float(agpack_packer* pk, float d);
static int agpack_pack_double(agpack_packer* pk, double d);

static int agpack_pack_nil(agpack_packer* pk);
static int agpack_pack_true(agpack_packer* pk);
static int agpack_pack_false(agpack_packer* pk);

static int agpack_pack_array(agpack_packer* pk, size_t n);

static int agpack_pack_map(agpack_packer* pk, size_t n);

static int agpack_pack_str(agpack_packer* pk, size_t l);
static int agpack_pack_str_body(agpack_packer* pk, const void* b, size_t l);
static int agpack_pack_str_with_body(agpack_packer* pk, const void* b, size_t l);

static int agpack_pack_v4raw(agpack_packer* pk, size_t l);
static int agpack_pack_v4raw_body(agpack_packer* pk, const void* b, size_t l);

static int agpack_pack_bin(agpack_packer* pk, size_t l);
static int agpack_pack_bin_body(agpack_packer* pk, const void* b, size_t l);
static int agpack_pack_bin_with_body(agpack_packer* pk, const void* b, size_t l);

static int agpack_pack_ext(agpack_packer* pk, size_t l, int8_t type);
static int agpack_pack_ext_body(agpack_packer* pk, const void* b, size_t l);
static int agpack_pack_ext_with_body(agpack_packer* pk, const void* b, size_t l, int8_t type);

static int agpack_pack_timestamp(agpack_packer* pk, const agpack_timestamp* d);

AGPACK_DLLEXPORT
int agpack_pack_object(agpack_packer* pk, agpack_object d);


/** @} */


#define agpack_pack_inline_func(name) \
    inline int agpack_pack ## name

#define agpack_pack_inline_func_cint(name) \
    inline int agpack_pack ## name

#define agpack_pack_inline_func_fixint(name) \
    inline int agpack_pack_fix ## name

#define agpack_pack_user agpack_packer*

#define agpack_pack_append_buffer(user, buf, len) \
    return (*(user)->callback)((user)->data, (const char*)buf, len)

#include "pack_template.h"

inline void agpack_packer_init(agpack_packer* pk, void* data, agpack_packer_write callback)
{
    pk->data = data;
    pk->callback = callback;
}

inline agpack_packer* agpack_packer_new(void* data, agpack_packer_write callback)
{
    agpack_packer* pk = (agpack_packer*)calloc(1, sizeof(agpack_packer));
    if(!pk) { return NULL; }
    agpack_packer_init(pk, data, callback);
    return pk;
}

inline void agpack_packer_free(agpack_packer* pk)
{
    free(pk);
}

inline int agpack_pack_str_with_body(agpack_packer* pk, const void* b, size_t l)
 {
     int ret = agpack_pack_str(pk, l);
     if (ret != 0) { return ret; }
     return agpack_pack_str_body(pk, b, l);
 }

 inline int agpack_pack_bin_with_body(agpack_packer* pk, const void* b, size_t l)
 {
     int ret = agpack_pack_bin(pk, l);
     if (ret != 0) { return ret; }
     return agpack_pack_bin_body(pk, b, l);
 }

 inline int agpack_pack_ext_with_body(agpack_packer* pk, const void* b, size_t l, int8_t type)
 {
     int ret = agpack_pack_ext(pk, l, type);
     if (ret != 0) { return ret; }
     return agpack_pack_ext_body(pk, b, l);
 }
 
#ifdef __cplusplus
}
#endif

#endif /* agpack/pack.h */
