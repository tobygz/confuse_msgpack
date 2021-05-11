/*
 * MessagePack for C simple buffer implementation
 *
 * Copyright (C) 2008-2009 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_SBUFFER_H
#define AGPACK_SBUFFER_H

#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @defgroup agpack_sbuffer Simple buffer
 * @ingroup agpack_buffer
 * @{
 */

typedef struct agpack_sbuffer {
    size_t size;
    char* data;
    size_t alloc;
} agpack_sbuffer;

static inline void agpack_sbuffer_init(agpack_sbuffer* sbuf)
{
    memset(sbuf, 0, sizeof(agpack_sbuffer));
}

static inline void agpack_sbuffer_destroy(agpack_sbuffer* sbuf)
{
    free(sbuf->data);
}

static inline agpack_sbuffer* agpack_sbuffer_new(void)
{
    return (agpack_sbuffer*)calloc(1, sizeof(agpack_sbuffer));
}

static inline void agpack_sbuffer_free(agpack_sbuffer* sbuf)
{
    if(sbuf == NULL) { return; }
    agpack_sbuffer_destroy(sbuf);
    free(sbuf);
}

#ifndef AGPACK_SBUFFER_INIT_SIZE
#define AGPACK_SBUFFER_INIT_SIZE 8192
#endif

static inline int agpack_sbuffer_write(void* data, const char* buf, size_t len)
{
    agpack_sbuffer* sbuf = (agpack_sbuffer*)data;

    if(sbuf->alloc - sbuf->size < len) {
        void* tmp;
        size_t nsize = (sbuf->alloc) ?
                sbuf->alloc * 2 : AGPACK_SBUFFER_INIT_SIZE;

        while(nsize < sbuf->size + len) {
            size_t tmp_nsize = nsize * 2;
            if (tmp_nsize <= nsize) {
                nsize = sbuf->size + len;
                break;
            }
            nsize = tmp_nsize;
        }

        tmp = realloc(sbuf->data, nsize);
        if(!tmp) { return -1; }

        sbuf->data = (char*)tmp;
        sbuf->alloc = nsize;
    }

    memcpy(sbuf->data + sbuf->size, buf, len);
    sbuf->size += len;
    return 0;
}

static inline char* agpack_sbuffer_release(agpack_sbuffer* sbuf)
{
    char* tmp = sbuf->data;
    sbuf->size = 0;
    sbuf->data = NULL;
    sbuf->alloc = 0;
    return tmp;
}

static inline void agpack_sbuffer_clear(agpack_sbuffer* sbuf)
{
    sbuf->size = 0;
}

/** @} */


#ifdef __cplusplus
}
#endif

#endif /* agpack/sbuffer.h */
