/*
 * MessagePack for C memory pool implementation
 *
 * Copyright (C) 2008-2010 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_ZONE_H
#define AGPACK_ZONE_H

#include "sysdep.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup agpack_zone Memory zone
 * @ingroup agpack
 * @{
 */

typedef struct agpack_zone_finalizer {
    void (*func)(void* data);
    void* data;
} agpack_zone_finalizer;

typedef struct agpack_zone_finalizer_array {
    agpack_zone_finalizer* tail;
    agpack_zone_finalizer* end;
    agpack_zone_finalizer* array;
} agpack_zone_finalizer_array;

struct agpack_zone_chunk;
typedef struct agpack_zone_chunk agpack_zone_chunk;

typedef struct agpack_zone_chunk_list {
    size_t free;
    char* ptr;
    agpack_zone_chunk* head;
} agpack_zone_chunk_list;

typedef struct agpack_zone {
    agpack_zone_chunk_list chunk_list;
    agpack_zone_finalizer_array finalizer_array;
    size_t chunk_size;
} agpack_zone;

#ifndef AGPACK_ZONE_CHUNK_SIZE
#define AGPACK_ZONE_CHUNK_SIZE 8192
#endif

AGPACK_DLLEXPORT
bool agpack_zone_init(agpack_zone* zone, size_t chunk_size);
AGPACK_DLLEXPORT
void agpack_zone_destroy(agpack_zone* zone);

AGPACK_DLLEXPORT
agpack_zone* agpack_zone_new(size_t chunk_size);
AGPACK_DLLEXPORT
void agpack_zone_free(agpack_zone* zone);

static inline void* agpack_zone_malloc(agpack_zone* zone, size_t size);
static inline void* agpack_zone_malloc_no_align(agpack_zone* zone, size_t size);

static inline bool agpack_zone_push_finalizer(agpack_zone* zone,
        void (*func)(void* data), void* data);

static inline void agpack_zone_swap(agpack_zone* a, agpack_zone* b);

AGPACK_DLLEXPORT
bool agpack_zone_is_empty(agpack_zone* zone);

AGPACK_DLLEXPORT
void agpack_zone_clear(agpack_zone* zone);

/** @} */


#ifndef AGPACK_ZONE_ALIGN
#define AGPACK_ZONE_ALIGN sizeof(void*)
#endif

AGPACK_DLLEXPORT
void* agpack_zone_malloc_expand(agpack_zone* zone, size_t size);

static inline void* agpack_zone_malloc_no_align(agpack_zone* zone, size_t size)
{
    char* ptr;
    agpack_zone_chunk_list* cl = &zone->chunk_list;

    if(zone->chunk_list.free < size) {
        return agpack_zone_malloc_expand(zone, size);
    }

    ptr = cl->ptr;
    cl->free -= size;
    cl->ptr  += size;

    return ptr;
}

static inline void* agpack_zone_malloc(agpack_zone* zone, size_t size)
{
    char* aligned =
        (char*)(
            (size_t)(
                zone->chunk_list.ptr + (AGPACK_ZONE_ALIGN - 1)
            ) / AGPACK_ZONE_ALIGN * AGPACK_ZONE_ALIGN
        );
    size_t adjusted_size = size + (size_t)(aligned - zone->chunk_list.ptr);
    if(zone->chunk_list.free >= adjusted_size) {
        zone->chunk_list.free -= adjusted_size;
        zone->chunk_list.ptr  += adjusted_size;
        return aligned;
    }
    {
        void* ptr = agpack_zone_malloc_expand(zone, size + (AGPACK_ZONE_ALIGN - 1));
        if (ptr) {
            return (char*)((size_t)(ptr) / AGPACK_ZONE_ALIGN * AGPACK_ZONE_ALIGN);
        }
    }
    return NULL;
}


bool agpack_zone_push_finalizer_expand(agpack_zone* zone,
        void (*func)(void* data), void* data);

static inline bool agpack_zone_push_finalizer(agpack_zone* zone,
        void (*func)(void* data), void* data)
{
    agpack_zone_finalizer_array* const fa = &zone->finalizer_array;
    agpack_zone_finalizer* fin = fa->tail;

    if(fin == fa->end) {
        return agpack_zone_push_finalizer_expand(zone, func, data);
    }

    fin->func = func;
    fin->data = data;

    ++fa->tail;

    return true;
}

static inline void agpack_zone_swap(agpack_zone* a, agpack_zone* b)
{
    agpack_zone tmp = *a;
    *a = *b;
    *b = tmp;
}


#ifdef __cplusplus
}
#endif

#endif /* agpack/zone.h */
