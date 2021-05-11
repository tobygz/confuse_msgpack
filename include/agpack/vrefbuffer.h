/*
 * MessagePack for C zero-copy buffer implementation
 *
 * Copyright (C) 2008-2009 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_VREFBUFFER_H
#define AGPACK_VREFBUFFER_H

#include "zone.h"
#include <stdlib.h>

#if defined(unix) || defined(__unix) || defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__QNX__) || defined(__QNXTO__) || defined(__HAIKU__)
#include <sys/uio.h>
#else
struct iovec {
    void  *iov_base;
    size_t iov_len;
};
#endif

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup agpack_vrefbuffer Vectored Referencing buffer
 * @ingroup agpack_buffer
 * @{
 */

struct agpack_vrefbuffer_chunk;
typedef struct agpack_vrefbuffer_chunk agpack_vrefbuffer_chunk;

typedef struct agpack_vrefbuffer_inner_buffer {
    size_t free;
    char*  ptr;
    agpack_vrefbuffer_chunk* head;
} agpack_vrefbuffer_inner_buffer;

typedef struct agpack_vrefbuffer {
    struct iovec* tail;
    struct iovec* end;
    struct iovec* array;

    size_t chunk_size;
    size_t ref_size;

    agpack_vrefbuffer_inner_buffer inner_buffer;
} agpack_vrefbuffer;


#ifndef AGPACK_VREFBUFFER_REF_SIZE
#define AGPACK_VREFBUFFER_REF_SIZE 32
#endif

#ifndef AGPACK_VREFBUFFER_CHUNK_SIZE
#define AGPACK_VREFBUFFER_CHUNK_SIZE 8192
#endif

AGPACK_DLLEXPORT
bool agpack_vrefbuffer_init(agpack_vrefbuffer* vbuf,
        size_t ref_size, size_t chunk_size);
AGPACK_DLLEXPORT
void agpack_vrefbuffer_destroy(agpack_vrefbuffer* vbuf);

static inline agpack_vrefbuffer* agpack_vrefbuffer_new(size_t ref_size, size_t chunk_size);
static inline void agpack_vrefbuffer_free(agpack_vrefbuffer* vbuf);

static inline int agpack_vrefbuffer_write(void* data, const char* buf, size_t len);

static inline const struct iovec* agpack_vrefbuffer_vec(const agpack_vrefbuffer* vref);
static inline size_t agpack_vrefbuffer_veclen(const agpack_vrefbuffer* vref);

AGPACK_DLLEXPORT
int agpack_vrefbuffer_append_copy(agpack_vrefbuffer* vbuf,
        const char* buf, size_t len);

AGPACK_DLLEXPORT
int agpack_vrefbuffer_append_ref(agpack_vrefbuffer* vbuf,
        const char* buf, size_t len);

AGPACK_DLLEXPORT
int agpack_vrefbuffer_migrate(agpack_vrefbuffer* vbuf, agpack_vrefbuffer* to);

AGPACK_DLLEXPORT
void agpack_vrefbuffer_clear(agpack_vrefbuffer* vref);

/** @} */


static inline agpack_vrefbuffer* agpack_vrefbuffer_new(size_t ref_size, size_t chunk_size)
{
    agpack_vrefbuffer* vbuf = (agpack_vrefbuffer*)malloc(sizeof(agpack_vrefbuffer));
    if (vbuf == NULL) return NULL;
    if(!agpack_vrefbuffer_init(vbuf, ref_size, chunk_size)) {
        free(vbuf);
        return NULL;
    }
    return vbuf;
}

static inline void agpack_vrefbuffer_free(agpack_vrefbuffer* vbuf)
{
    if(vbuf == NULL) { return; }
    agpack_vrefbuffer_destroy(vbuf);
    free(vbuf);
}

static inline int agpack_vrefbuffer_write(void* data, const char* buf, size_t len)
{
    agpack_vrefbuffer* vbuf = (agpack_vrefbuffer*)data;

    if(len < vbuf->ref_size) {
        return agpack_vrefbuffer_append_copy(vbuf, buf, len);
    } else {
        return agpack_vrefbuffer_append_ref(vbuf, buf, len);
    }
}

static inline const struct iovec* agpack_vrefbuffer_vec(const agpack_vrefbuffer* vref)
{
    return vref->array;
}

static inline size_t agpack_vrefbuffer_veclen(const agpack_vrefbuffer* vref)
{
    return (size_t)(vref->tail - vref->array);
}


#ifdef __cplusplus
}
#endif

#endif /* agpack/vrefbuffer.h */
