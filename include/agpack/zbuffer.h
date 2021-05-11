/*
 * MessagePack for C deflate buffer implementation
 *
 * Copyright (C) 2010 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_ZBUFFER_H
#define AGPACK_ZBUFFER_H

#include "sysdep.h"
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup agpack_zbuffer Compressed buffer
 * @ingroup agpack_buffer
 * @{
 */

typedef struct agpack_zbuffer {
    z_stream stream;
    char* data;
    size_t init_size;
} agpack_zbuffer;

#ifndef AGPACK_ZBUFFER_INIT_SIZE
#define AGPACK_ZBUFFER_INIT_SIZE 8192
#endif

static inline bool agpack_zbuffer_init(
    agpack_zbuffer* zbuf, int level, size_t init_size);
static inline void agpack_zbuffer_destroy(agpack_zbuffer* zbuf);

static inline agpack_zbuffer* agpack_zbuffer_new(int level, size_t init_size);
static inline void agpack_zbuffer_free(agpack_zbuffer* zbuf);

static inline char* agpack_zbuffer_flush(agpack_zbuffer* zbuf);

static inline const char* agpack_zbuffer_data(const agpack_zbuffer* zbuf);
static inline size_t agpack_zbuffer_size(const agpack_zbuffer* zbuf);

static inline bool agpack_zbuffer_reset(agpack_zbuffer* zbuf);
static inline void agpack_zbuffer_reset_buffer(agpack_zbuffer* zbuf);
static inline char* agpack_zbuffer_release_buffer(agpack_zbuffer* zbuf);


#ifndef AGPACK_ZBUFFER_RESERVE_SIZE
#define AGPACK_ZBUFFER_RESERVE_SIZE 512
#endif

static inline int agpack_zbuffer_write(void* data, const char* buf, size_t len);

static inline bool agpack_zbuffer_expand(agpack_zbuffer* zbuf);


static inline bool agpack_zbuffer_init(agpack_zbuffer* zbuf,
        int level, size_t init_size)
{
    memset(zbuf, 0, sizeof(agpack_zbuffer));
    zbuf->init_size = init_size;
    if(deflateInit(&zbuf->stream, level) != Z_OK) {
        free(zbuf->data);
        return false;
    }
    return true;
}

static inline void agpack_zbuffer_destroy(agpack_zbuffer* zbuf)
{
    deflateEnd(&zbuf->stream);
    free(zbuf->data);
}

static inline agpack_zbuffer* agpack_zbuffer_new(int level, size_t init_size)
{
    agpack_zbuffer* zbuf = (agpack_zbuffer*)malloc(sizeof(agpack_zbuffer));
    if (zbuf == NULL) return NULL;
    if(!agpack_zbuffer_init(zbuf, level, init_size)) {
        free(zbuf);
        return NULL;
    }
    return zbuf;
}

static inline void agpack_zbuffer_free(agpack_zbuffer* zbuf)
{
    if(zbuf == NULL) { return; }
    agpack_zbuffer_destroy(zbuf);
    free(zbuf);
}

static inline bool agpack_zbuffer_expand(agpack_zbuffer* zbuf)
{
    size_t used = (size_t)((char *)(zbuf->stream.next_out) - zbuf->data);
    size_t csize = used + zbuf->stream.avail_out;

    size_t nsize = (csize == 0) ? zbuf->init_size : csize * 2;

    char* tmp = (char*)realloc(zbuf->data, nsize);
    if(tmp == NULL) {
        return false;
    }

    zbuf->data = tmp;
    zbuf->stream.next_out  = (Bytef*)(tmp + used);
    zbuf->stream.avail_out = (uInt)(nsize - used);

    return true;
}

static inline int agpack_zbuffer_write(void* data, const char* buf, size_t len)
{
    agpack_zbuffer* zbuf = (agpack_zbuffer*)data;

    zbuf->stream.next_in = (Bytef*)buf;
    zbuf->stream.avail_in = (uInt)len;

    while(zbuf->stream.avail_in > 0) {
        if(zbuf->stream.avail_out < AGPACK_ZBUFFER_RESERVE_SIZE) {
            if(!agpack_zbuffer_expand(zbuf)) {
                return -1;
            }
        }

        if(deflate(&zbuf->stream, Z_NO_FLUSH) != Z_OK) {
            return -1;
        }
    }

    return 0;
}

static inline char* agpack_zbuffer_flush(agpack_zbuffer* zbuf)
{
    while(true) {
        switch(deflate(&zbuf->stream, Z_FINISH)) {
        case Z_STREAM_END:
            return zbuf->data;
        case Z_OK:
        case Z_BUF_ERROR:
            if(!agpack_zbuffer_expand(zbuf)) {
                return NULL;
            }
            break;
        default:
            return NULL;
        }
    }
}

static inline const char* agpack_zbuffer_data(const agpack_zbuffer* zbuf)
{
    return zbuf->data;
}

static inline size_t agpack_zbuffer_size(const agpack_zbuffer* zbuf)
{
    return (size_t)((char *)(zbuf->stream.next_out) - zbuf->data);
}

static inline void agpack_zbuffer_reset_buffer(agpack_zbuffer* zbuf)
{
    zbuf->stream.avail_out += (uInt)((char*)zbuf->stream.next_out - zbuf->data);
    zbuf->stream.next_out = (Bytef*)zbuf->data;
}

static inline bool agpack_zbuffer_reset(agpack_zbuffer* zbuf)
{
    if(deflateReset(&zbuf->stream) != Z_OK) {
        return false;
    }
    agpack_zbuffer_reset_buffer(zbuf);
    return true;
}

static inline char* agpack_zbuffer_release_buffer(agpack_zbuffer* zbuf)
{
    char* tmp = zbuf->data;
    zbuf->data = NULL;
    zbuf->stream.next_out = NULL;
    zbuf->stream.avail_out = 0;
    return tmp;
}

/** @} */


#ifdef __cplusplus
}
#endif

#endif /* agpack/zbuffer.h */
