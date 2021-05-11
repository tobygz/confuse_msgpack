/*
 * MessagePack for C zero-copy buffer implementation
 *
 * Copyright (C) 2008-2009 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#include "agpack/vrefbuffer.h"
#include <stdlib.h>
#include <string.h>

#define AGPACK_PACKER_MAX_BUFFER_SIZE 9

struct agpack_vrefbuffer_chunk {
    struct agpack_vrefbuffer_chunk* next;
    /* data ... */
};

bool agpack_vrefbuffer_init(agpack_vrefbuffer* vbuf,
        size_t ref_size, size_t chunk_size)
{
    size_t nfirst;
    struct iovec* array;
    agpack_vrefbuffer_chunk* chunk;

    if (ref_size == 0) {
        ref_size = AGPACK_VREFBUFFER_REF_SIZE;
    }
    if(chunk_size == 0) {
        chunk_size = AGPACK_VREFBUFFER_CHUNK_SIZE;
    }
    vbuf->chunk_size = chunk_size;
    vbuf->ref_size =
        ref_size > AGPACK_PACKER_MAX_BUFFER_SIZE + 1 ?
        ref_size : AGPACK_PACKER_MAX_BUFFER_SIZE + 1 ;

    if((sizeof(agpack_vrefbuffer_chunk) + chunk_size) < chunk_size) {
        return false;
    }

    nfirst = (sizeof(struct iovec) < 72/2) ?
            72 / sizeof(struct iovec) : 8;

    array = (struct iovec*)malloc(
            sizeof(struct iovec) * nfirst);
    if(array == NULL) {
        return false;
    }

    vbuf->tail  = array;
    vbuf->end   = array + nfirst;
    vbuf->array = array;

    chunk = (agpack_vrefbuffer_chunk*)malloc(
            sizeof(agpack_vrefbuffer_chunk) + chunk_size);
    if(chunk == NULL) {
        free(array);
        return false;
    }
    else {
        agpack_vrefbuffer_inner_buffer* const ib = &vbuf->inner_buffer;

        ib->free = chunk_size;
        ib->ptr  = ((char*)chunk) + sizeof(agpack_vrefbuffer_chunk);
        ib->head = chunk;
        chunk->next = NULL;

        return true;
    }
}

void agpack_vrefbuffer_destroy(agpack_vrefbuffer* vbuf)
{
    agpack_vrefbuffer_chunk* c = vbuf->inner_buffer.head;
    while(true) {
        agpack_vrefbuffer_chunk* n = c->next;
        free(c);
        if(n != NULL) {
            c = n;
        } else {
            break;
        }
    }
    free(vbuf->array);
}

void agpack_vrefbuffer_clear(agpack_vrefbuffer* vbuf)
{
    agpack_vrefbuffer_chunk* c = vbuf->inner_buffer.head->next;
    agpack_vrefbuffer_chunk* n;
    while(c != NULL) {
        n = c->next;
        free(c);
        c = n;
    }

    {
        agpack_vrefbuffer_inner_buffer* const ib = &vbuf->inner_buffer;
        agpack_vrefbuffer_chunk* chunk = ib->head;
        chunk->next = NULL;
        ib->free = vbuf->chunk_size;
        ib->ptr  = ((char*)chunk) + sizeof(agpack_vrefbuffer_chunk);

        vbuf->tail = vbuf->array;
    }
}

int agpack_vrefbuffer_append_ref(agpack_vrefbuffer* vbuf,
        const char* buf, size_t len)
{
    if(vbuf->tail == vbuf->end) {
        const size_t nused = (size_t)(vbuf->tail - vbuf->array);
        const size_t nnext = nused * 2;

        struct iovec* nvec = (struct iovec*)realloc(
                vbuf->array, sizeof(struct iovec)*nnext);
        if(nvec == NULL) {
            return -1;
        }

        vbuf->array = nvec;
        vbuf->end   = nvec + nnext;
        vbuf->tail  = nvec + nused;
    }

    vbuf->tail->iov_base = (char*)buf;
    vbuf->tail->iov_len  = len;
    ++vbuf->tail;

    return 0;
}

int agpack_vrefbuffer_append_copy(agpack_vrefbuffer* vbuf,
        const char* buf, size_t len)
{
    agpack_vrefbuffer_inner_buffer* const ib = &vbuf->inner_buffer;
    char* m;

    if(ib->free < len) {
        agpack_vrefbuffer_chunk* chunk;
        size_t sz = vbuf->chunk_size;
        if(sz < len) {
            sz = len;
        }

        if((sizeof(agpack_vrefbuffer_chunk) + sz) < sz){
            return -1;
        }
        chunk = (agpack_vrefbuffer_chunk*)malloc(
                sizeof(agpack_vrefbuffer_chunk) + sz);
        if(chunk == NULL) {
            return -1;
        }

        chunk->next = ib->head;
        ib->head = chunk;
        ib->free = sz;
        ib->ptr  = ((char*)chunk) + sizeof(agpack_vrefbuffer_chunk);
    }

    m = ib->ptr;
    memcpy(m, buf, len);
    ib->free -= len;
    ib->ptr  += len;

    if(vbuf->tail != vbuf->array && m ==
            (const char*)((vbuf->tail-1)->iov_base) + (vbuf->tail-1)->iov_len) {
        (vbuf->tail-1)->iov_len += len;
        return 0;
    } else {
        return agpack_vrefbuffer_append_ref(vbuf, m, len);
    }
}

int agpack_vrefbuffer_migrate(agpack_vrefbuffer* vbuf, agpack_vrefbuffer* to)
{
    size_t sz = vbuf->chunk_size;
    agpack_vrefbuffer_chunk* empty;

    if((sizeof(agpack_vrefbuffer_chunk) + sz) < sz){
        return -1;
    }

    empty = (agpack_vrefbuffer_chunk*)malloc(
            sizeof(agpack_vrefbuffer_chunk) + sz);
    if(empty == NULL) {
        return -1;
    }

    empty->next = NULL;

    {
        const size_t nused = (size_t)(vbuf->tail - vbuf->array);
        if(to->tail + nused < vbuf->end) {
            struct iovec* nvec;
            const size_t tosize = (size_t)(to->tail - to->array);
            const size_t reqsize = nused + tosize;
            size_t nnext = (size_t)(to->end - to->array) * 2;
            while(nnext < reqsize) {
                size_t tmp_nnext = nnext * 2;
                if (tmp_nnext <= nnext) {
                    nnext = reqsize;
                    break;
                }
                nnext = tmp_nnext;
            }

            nvec = (struct iovec*)realloc(
                    to->array, sizeof(struct iovec)*nnext);
            if(nvec == NULL) {
                free(empty);
                return -1;
            }

            to->array = nvec;
            to->end   = nvec + nnext;
            to->tail  = nvec + tosize;
        }

        memcpy(to->tail, vbuf->array, sizeof(struct iovec)*nused);

        to->tail += nused;
        vbuf->tail = vbuf->array;

        {
            agpack_vrefbuffer_inner_buffer* const ib = &vbuf->inner_buffer;
            agpack_vrefbuffer_inner_buffer* const toib = &to->inner_buffer;

            agpack_vrefbuffer_chunk* last = ib->head;
            while(last->next != NULL) {
                last = last->next;
            }
            last->next = toib->head;
            toib->head = ib->head;

            if(toib->free < ib->free) {
                toib->free = ib->free;
                toib->ptr  = ib->ptr;
            }

            ib->head = empty;
            ib->free = sz;
            ib->ptr  = ((char*)empty) + sizeof(agpack_vrefbuffer_chunk);
        }
    }

    return 0;
}
