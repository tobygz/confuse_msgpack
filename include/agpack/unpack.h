/*
 * MessagePack for C unpacking routine
 *
 * Copyright (C) 2008-2009 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_UNPACKER_H
#define AGPACK_UNPACKER_H

#include "zone.h"
#include "object.h"
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup agpack_unpack Deserializer
 * @ingroup agpack
 * @{
 */

typedef struct agpack_unpacked {
    agpack_zone* zone;
    agpack_object data;
} agpack_unpacked;

typedef enum {
    AGPACK_UNPACK_SUCCESS              =  2,
    AGPACK_UNPACK_EXTRA_BYTES          =  1,
    AGPACK_UNPACK_CONTINUE             =  0,
    AGPACK_UNPACK_PARSE_ERROR          = -1,
    AGPACK_UNPACK_NOMEM_ERROR          = -2
} agpack_unpack_return;


AGPACK_DLLEXPORT
agpack_unpack_return
agpack_unpack_next(agpack_unpacked* result,
        const char* data, size_t len, size_t* off);

/** @} */


/**
 * @defgroup agpack_unpacker Streaming deserializer
 * @ingroup agpack
 * @{
 */

typedef struct agpack_unpacker {
    char* buffer;
    size_t used;
    size_t free;
    size_t off;
    size_t parsed;
    agpack_zone* z;
    size_t initial_buffer_size;
    void* ctx;
} agpack_unpacker;


#ifndef AGPACK_UNPACKER_INIT_BUFFER_SIZE
#define AGPACK_UNPACKER_INIT_BUFFER_SIZE (64*1024)
#endif

/**
 * Initializes a streaming deserializer.
 * The initialized deserializer must be destroyed by agpack_unpacker_destroy(agpack_unpacker*).
 */
AGPACK_DLLEXPORT
bool agpack_unpacker_init(agpack_unpacker* mpac, size_t initial_buffer_size);

/**
 * Destroys a streaming deserializer initialized by agpack_unpacker_init(agpack_unpacker*, size_t).
 */
AGPACK_DLLEXPORT
void agpack_unpacker_destroy(agpack_unpacker* mpac);


/**
 * Creates a streaming deserializer.
 * The created deserializer must be destroyed by agpack_unpacker_free(agpack_unpacker*).
 */
AGPACK_DLLEXPORT
agpack_unpacker* agpack_unpacker_new(size_t initial_buffer_size);

/**
 * Frees a streaming deserializer created by agpack_unpacker_new(size_t).
 */
AGPACK_DLLEXPORT
void agpack_unpacker_free(agpack_unpacker* mpac);


#ifndef AGPACK_UNPACKER_RESERVE_SIZE
#define AGPACK_UNPACKER_RESERVE_SIZE (32*1024)
#endif

/**
 * Reserves free space of the internal buffer.
 * Use this function to fill the internal buffer with
 * agpack_unpacker_buffer(agpack_unpacker*),
 * agpack_unpacker_buffer_capacity(const agpack_unpacker*) and
 * agpack_unpacker_buffer_consumed(agpack_unpacker*).
 */
static inline bool   agpack_unpacker_reserve_buffer(agpack_unpacker* mpac, size_t size);

/**
 * Gets pointer to the free space of the internal buffer.
 * Use this function to fill the internal buffer with
 * agpack_unpacker_reserve_buffer(agpack_unpacker*, size_t),
 * agpack_unpacker_buffer_capacity(const agpack_unpacker*) and
 * agpack_unpacker_buffer_consumed(agpack_unpacker*).
 */
static inline char*  agpack_unpacker_buffer(agpack_unpacker* mpac);

/**
 * Gets size of the free space of the internal buffer.
 * Use this function to fill the internal buffer with
 * agpack_unpacker_reserve_buffer(agpack_unpacker*, size_t),
 * agpack_unpacker_buffer(const agpack_unpacker*) and
 * agpack_unpacker_buffer_consumed(agpack_unpacker*).
 */
static inline size_t agpack_unpacker_buffer_capacity(const agpack_unpacker* mpac);

/**
 * Notifies the deserializer that the internal buffer filled.
 * Use this function to fill the internal buffer with
 * agpack_unpacker_reserve_buffer(agpack_unpacker*, size_t),
 * agpack_unpacker_buffer(agpack_unpacker*) and
 * agpack_unpacker_buffer_capacity(const agpack_unpacker*).
 */
static inline void   agpack_unpacker_buffer_consumed(agpack_unpacker* mpac, size_t size);


/**
 * Deserializes one object.
 * Returns true if it successes. Otherwise false is returned.
 * @param pac  pointer to an initialized agpack_unpacked object.
 */
AGPACK_DLLEXPORT
agpack_unpack_return agpack_unpacker_next(agpack_unpacker* mpac, agpack_unpacked* pac);

/**
 * Deserializes one object and set the number of parsed bytes involved.
 * Returns true if it successes. Otherwise false is returned.
 * @param mpac    pointer to an initialized agpack_unpacker object.
 * @param result  pointer to an initialized agpack_unpacked object.
 * @param p_bytes pointer to variable that will be set with the number of parsed bytes.
 */
AGPACK_DLLEXPORT
agpack_unpack_return agpack_unpacker_next_with_size(agpack_unpacker* mpac,
                                                      agpack_unpacked* result,
                                                      size_t *p_bytes);

/**
 * Initializes a agpack_unpacked object.
 * The initialized object must be destroyed by agpack_unpacked_destroy(agpack_unpacker*).
 * Use the object with agpack_unpacker_next(agpack_unpacker*, agpack_unpacked*) or
 * agpack_unpack_next(agpack_unpacked*, const char*, size_t, size_t*).
 */
static inline void agpack_unpacked_init(agpack_unpacked* result);

/**
 * Destroys a streaming deserializer initialized by agpack_unpacked().
 */
static inline void agpack_unpacked_destroy(agpack_unpacked* result);

/**
 * Releases the memory zone from agpack_unpacked object.
 * The released zone must be freed by agpack_zone_free(agpack_zone*).
 */
static inline agpack_zone* agpack_unpacked_release_zone(agpack_unpacked* result);


AGPACK_DLLEXPORT
int agpack_unpacker_execute(agpack_unpacker* mpac);

AGPACK_DLLEXPORT
agpack_object agpack_unpacker_data(agpack_unpacker* mpac);

AGPACK_DLLEXPORT
agpack_zone* agpack_unpacker_release_zone(agpack_unpacker* mpac);

AGPACK_DLLEXPORT
void agpack_unpacker_reset_zone(agpack_unpacker* mpac);

AGPACK_DLLEXPORT
void agpack_unpacker_reset(agpack_unpacker* mpac);

static inline size_t agpack_unpacker_message_size(const agpack_unpacker* mpac);


/** @} */


// obsolete
AGPACK_DLLEXPORT
agpack_unpack_return
agpack_unpack(const char* data, size_t len, size_t* off,
        agpack_zone* result_zone, agpack_object* result);




static inline size_t agpack_unpacker_parsed_size(const agpack_unpacker* mpac);

AGPACK_DLLEXPORT
bool agpack_unpacker_flush_zone(agpack_unpacker* mpac);

AGPACK_DLLEXPORT
bool agpack_unpacker_expand_buffer(agpack_unpacker* mpac, size_t size);

static inline bool agpack_unpacker_reserve_buffer(agpack_unpacker* mpac, size_t size)
{
    if(mpac->free >= size) { return true; }
    return agpack_unpacker_expand_buffer(mpac, size);
}

static inline char* agpack_unpacker_buffer(agpack_unpacker* mpac)
{
    return mpac->buffer + mpac->used;
}

static inline size_t agpack_unpacker_buffer_capacity(const agpack_unpacker* mpac)
{
    return mpac->free;
}

static inline void agpack_unpacker_buffer_consumed(agpack_unpacker* mpac, size_t size)
{
    mpac->used += size;
    mpac->free -= size;
}

static inline size_t agpack_unpacker_message_size(const agpack_unpacker* mpac)
{
    return mpac->parsed - mpac->off + mpac->used;
}

static inline size_t agpack_unpacker_parsed_size(const agpack_unpacker* mpac)
{
    return mpac->parsed;
}


static inline void agpack_unpacked_init(agpack_unpacked* result)
{
    memset(result, 0, sizeof(agpack_unpacked));
}

static inline void agpack_unpacked_destroy(agpack_unpacked* result)
{
    if(result->zone != NULL) {
        agpack_zone_free(result->zone);
        result->zone = NULL;
        memset(&result->data, 0, sizeof(agpack_object));
    }
}

static inline agpack_zone* agpack_unpacked_release_zone(agpack_unpacked* result)
{
    if(result->zone != NULL) {
        agpack_zone* z = result->zone;
        result->zone = NULL;
        return z;
    }
    return NULL;
}


#ifdef __cplusplus
}
#endif

#endif /* agpack/unpack.h */
