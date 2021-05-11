/*
 * MessagePack for C dynamic typing routine
 *
 * Copyright (C) 2008-2009 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_OBJECT_H
#define AGPACK_OBJECT_H

#include "zone.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup agpack_object Dynamically typed object
 * @ingroup agpack
 * @{
 */

typedef enum {
    AGPACK_OBJECT_NIL                  = 0x00,
    AGPACK_OBJECT_BOOLEAN              = 0x01,
    AGPACK_OBJECT_POSITIVE_INTEGER     = 0x02,
    AGPACK_OBJECT_NEGATIVE_INTEGER     = 0x03,
    AGPACK_OBJECT_FLOAT32              = 0x0a,
    AGPACK_OBJECT_FLOAT64              = 0x04,
    AGPACK_OBJECT_FLOAT                = 0x04,
#if defined(AGPACK_USE_LEGACY_NAME_AS_FLOAT)
    AGPACK_OBJECT_DOUBLE               = AGPACK_OBJECT_FLOAT, /* obsolete */
#endif /* AGPACK_USE_LEGACY_NAME_AS_FLOAT */
    AGPACK_OBJECT_STR                  = 0x05,
    AGPACK_OBJECT_ARRAY                = 0x06,
    AGPACK_OBJECT_MAP                  = 0x07,
    AGPACK_OBJECT_BIN                  = 0x08,
    AGPACK_OBJECT_EXT                  = 0x09
} agpack_object_type;


struct agpack_object;
struct agpack_object_kv;

typedef struct {
    uint32_t size;
    struct agpack_object* ptr;
} agpack_object_array;

typedef struct {
    uint32_t size;
    struct agpack_object_kv* ptr;
} agpack_object_map;

typedef struct {
    uint32_t size;
    const char* ptr;
} agpack_object_str;

typedef struct {
    uint32_t size;
    const char* ptr;
} agpack_object_bin;

typedef struct {
    int8_t type;
    uint32_t size;
    const char* ptr;
} agpack_object_ext;

typedef union {
    bool boolean;
    uint64_t u64;
    int64_t  i64;
#if defined(AGPACK_USE_LEGACY_NAME_AS_FLOAT)
    double   dec; /* obsolete*/
#endif /* AGPACK_USE_LEGACY_NAME_AS_FLOAT */
    double   f64;
    agpack_object_array array;
    agpack_object_map map;
    agpack_object_str str;
    agpack_object_bin bin;
    agpack_object_ext ext;
} agpack_object_union;

typedef struct agpack_object {
    agpack_object_type type;
    agpack_object_union via;
} agpack_object;

typedef struct agpack_object_kv {
    agpack_object key;
    agpack_object val;
} agpack_object_kv;

#if !defined(_KERNEL_MODE)
AGPACK_DLLEXPORT
void agpack_object_print(FILE* out, agpack_object o);
#endif

AGPACK_DLLEXPORT
int agpack_object_print_buffer(char *buffer, size_t buffer_size, agpack_object o);

AGPACK_DLLEXPORT
bool agpack_object_equal(const agpack_object x, const agpack_object y);

/** @} */


#ifdef __cplusplus
}
#endif

#endif /* agpack/object.h */
