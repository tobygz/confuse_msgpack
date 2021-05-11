/*
 * MessagePack for C unpacking routine
 *
 * Copyright (C) 2008-2009 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#include "agpack/unpack.h"
#include "agpack/unpack_define.h"
#include "agpack/util.h"
#include <stdlib.h>

#ifdef _agpack_atomic_counter_header
#include _agpack_atomic_counter_header
#endif


typedef struct {
    agpack_zone** z;
    bool referenced;
} unpack_user;


#define agpack_unpack_struct(name) \
    struct template ## name

#define agpack_unpack_func(ret, name) \
    ret template ## name

#define agpack_unpack_callback(name) \
    template_callback ## name

#define agpack_unpack_object agpack_object

#define agpack_unpack_user unpack_user


struct template_context;
typedef struct template_context template_context;

static void template_init(template_context* ctx);

static agpack_object template_data(template_context* ctx);

static int template_execute(
    template_context* ctx, const char* data, size_t len, size_t* off);


static inline agpack_object template_callback_root(unpack_user* u)
{
    agpack_object o;
    AGPACK_UNUSED(u);
    o.type = AGPACK_OBJECT_NIL;
    return o;
}

static inline int template_callback_uint8(unpack_user* u, uint8_t d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    o->type = AGPACK_OBJECT_POSITIVE_INTEGER;
    o->via.u64 = d;
    return 0;
}

static inline int template_callback_uint16(unpack_user* u, uint16_t d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    o->type = AGPACK_OBJECT_POSITIVE_INTEGER;
    o->via.u64 = d;
    return 0;
}

static inline int template_callback_uint32(unpack_user* u, uint32_t d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    o->type = AGPACK_OBJECT_POSITIVE_INTEGER;
    o->via.u64 = d;
    return 0;
}

static inline int template_callback_uint64(unpack_user* u, uint64_t d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    o->type = AGPACK_OBJECT_POSITIVE_INTEGER;
    o->via.u64 = d;
    return 0;
}

static inline int template_callback_int8(unpack_user* u, int8_t d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    if(d >= 0) {
        o->type = AGPACK_OBJECT_POSITIVE_INTEGER;
        o->via.u64 = (uint64_t)d;
        return 0;
    }
    else {
        o->type = AGPACK_OBJECT_NEGATIVE_INTEGER;
        o->via.i64 = d;
        return 0;
    }
}

static inline int template_callback_int16(unpack_user* u, int16_t d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    if(d >= 0) {
        o->type = AGPACK_OBJECT_POSITIVE_INTEGER;
        o->via.u64 = (uint64_t)d;
        return 0;
    }
    else {
        o->type = AGPACK_OBJECT_NEGATIVE_INTEGER;
        o->via.i64 = d;
        return 0;
    }
}

static inline int template_callback_int32(unpack_user* u, int32_t d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    if(d >= 0) {
        o->type = AGPACK_OBJECT_POSITIVE_INTEGER;
        o->via.u64 = (uint64_t)d;
        return 0;
    }
    else {
        o->type = AGPACK_OBJECT_NEGATIVE_INTEGER;
        o->via.i64 = d;
        return 0;
    }
}

static inline int template_callback_int64(unpack_user* u, int64_t d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    if(d >= 0) {
        o->type = AGPACK_OBJECT_POSITIVE_INTEGER;
        o->via.u64 = (uint64_t)d;
        return 0;
    }
    else {
        o->type = AGPACK_OBJECT_NEGATIVE_INTEGER;
        o->via.i64 = d;
        return 0;
    }
}

static inline int template_callback_float(unpack_user* u, float d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    o->type = AGPACK_OBJECT_FLOAT32;
    o->via.f64 = d;
    return 0;
}

static inline int template_callback_double(unpack_user* u, double d, agpack_object* o)
{
    AGPACK_UNUSED(u);
    o->type = AGPACK_OBJECT_FLOAT64;
    o->via.f64 = d;
    return 0;
}

static inline int template_callback_nil(unpack_user* u, agpack_object* o)
{
    AGPACK_UNUSED(u);
    o->type = AGPACK_OBJECT_NIL;
    return 0;
}

static inline int template_callback_true(unpack_user* u, agpack_object* o)
{
    AGPACK_UNUSED(u);
    o->type = AGPACK_OBJECT_BOOLEAN;
    o->via.boolean = true;
    return 0;
}

static inline int template_callback_false(unpack_user* u, agpack_object* o)
{
    AGPACK_UNUSED(u);
    o->type = AGPACK_OBJECT_BOOLEAN;
    o->via.boolean = false;
    return 0;
}

static inline int template_callback_array(unpack_user* u, unsigned int n, agpack_object* o)
{
    size_t size;
    // Let's leverage the fact that sizeof(agpack_object) is a compile time constant
    // to check for int overflows.
    // Note - while n is constrained to 32-bit, the product of n * sizeof(agpack_object)
    // might not be constrained to 4GB on 64-bit systems
#if SIZE_MAX == UINT_MAX
    if (n > SIZE_MAX/sizeof(agpack_object))
        return AGPACK_UNPACK_NOMEM_ERROR;
#endif

    o->type = AGPACK_OBJECT_ARRAY;
    o->via.array.size = 0;

    size = n * sizeof(agpack_object);

    if (*u->z == NULL) {
        *u->z = agpack_zone_new(AGPACK_ZONE_CHUNK_SIZE);
        if(*u->z == NULL) {
            return AGPACK_UNPACK_NOMEM_ERROR;
        }
    }

    // Unsure whether size = 0 should be an error, and if so, what to return
    o->via.array.ptr = (agpack_object*)agpack_zone_malloc(*u->z, size);
    if(o->via.array.ptr == NULL) { return AGPACK_UNPACK_NOMEM_ERROR; }
    return 0;
}

static inline int template_callback_array_item(unpack_user* u, agpack_object* c, agpack_object o)
{
    AGPACK_UNUSED(u);
#if defined(__GNUC__) && !defined(__clang__)
    memcpy(&c->via.array.ptr[c->via.array.size], &o, sizeof(agpack_object));
#else  /* __GNUC__ && !__clang__ */
    c->via.array.ptr[c->via.array.size] = o;
#endif /* __GNUC__ && !__clang__ */
    ++c->via.array.size;
    return 0;
}

static inline int template_callback_map(unpack_user* u, unsigned int n, agpack_object* o)
{
    size_t size;
    // Let's leverage the fact that sizeof(agpack_object_kv) is a compile time constant
    // to check for int overflows
    // Note - while n is constrained to 32-bit, the product of n * sizeof(agpack_object)
    // might not be constrained to 4GB on 64-bit systems

    // Note - this will always be false on 64-bit systems
#if SIZE_MAX == UINT_MAX
    if (n > SIZE_MAX/sizeof(agpack_object_kv))
        return AGPACK_UNPACK_NOMEM_ERROR;
#endif

    o->type = AGPACK_OBJECT_MAP;
    o->via.map.size = 0;

    size = n * sizeof(agpack_object_kv);

    if (*u->z == NULL) {
        *u->z = agpack_zone_new(AGPACK_ZONE_CHUNK_SIZE);
        if(*u->z == NULL) {
            return AGPACK_UNPACK_NOMEM_ERROR;
        }
    }

    // Should size = 0 be an error? If so, what error to return?
    o->via.map.ptr = (agpack_object_kv*)agpack_zone_malloc(*u->z, size);
    if(o->via.map.ptr == NULL) { return AGPACK_UNPACK_NOMEM_ERROR; }
    return 0;
}

static inline int template_callback_map_item(unpack_user* u, agpack_object* c, agpack_object k, agpack_object v)
{
    AGPACK_UNUSED(u);
#if defined(__GNUC__) && !defined(__clang__)
    memcpy(&c->via.map.ptr[c->via.map.size].key, &k, sizeof(agpack_object));
    memcpy(&c->via.map.ptr[c->via.map.size].val, &v, sizeof(agpack_object));
#else  /* __GNUC__ && !__clang__ */
    c->via.map.ptr[c->via.map.size].key = k;
    c->via.map.ptr[c->via.map.size].val = v;
#endif /* __GNUC__ && !__clang__ */
    ++c->via.map.size;
    return 0;
}

static inline int template_callback_str(unpack_user* u, const char* b, const char* p, unsigned int l, agpack_object* o)
{
    AGPACK_UNUSED(b);
    if (*u->z == NULL) {
        *u->z = agpack_zone_new(AGPACK_ZONE_CHUNK_SIZE);
        if(*u->z == NULL) {
            return AGPACK_UNPACK_NOMEM_ERROR;
        }
    }
    o->type = AGPACK_OBJECT_STR;
    o->via.str.ptr = p;
    o->via.str.size = l;
    u->referenced = true;
    return 0;
}

static inline int template_callback_bin(unpack_user* u, const char* b, const char* p, unsigned int l, agpack_object* o)
{
    AGPACK_UNUSED(b);
    if (*u->z == NULL) {
        *u->z = agpack_zone_new(AGPACK_ZONE_CHUNK_SIZE);
        if(*u->z == NULL) {
            return AGPACK_UNPACK_NOMEM_ERROR;
        }
    }
    o->type = AGPACK_OBJECT_BIN;
    o->via.bin.ptr = p;
    o->via.bin.size = l;
    u->referenced = true;
    return 0;
}

static inline int template_callback_ext(unpack_user* u, const char* b, const char* p, unsigned int l, agpack_object* o)
{
    AGPACK_UNUSED(b);
    if (l == 0) {
        return AGPACK_UNPACK_PARSE_ERROR;
    }
    if (*u->z == NULL) {
        *u->z = agpack_zone_new(AGPACK_ZONE_CHUNK_SIZE);
        if(*u->z == NULL) {
            return AGPACK_UNPACK_NOMEM_ERROR;
        }
    }
    o->type = AGPACK_OBJECT_EXT;
    o->via.ext.type = *p;
    o->via.ext.ptr = p + 1;
    o->via.ext.size = l - 1;
    u->referenced = true;
    return 0;
}

#include "agpack/unpack_template.h"


#define CTX_CAST(m) ((template_context*)(m))
#define CTX_REFERENCED(mpac) CTX_CAST((mpac)->ctx)->user.referenced

#define COUNTER_SIZE (sizeof(_agpack_atomic_counter_t))


static inline void init_count(void* buffer)
{
    *(volatile _agpack_atomic_counter_t*)buffer = 1;
}

static inline void decr_count(void* buffer)
{
    // atomic if(--*(_agpack_atomic_counter_t*)buffer == 0) { free(buffer); }
    if(_agpack_sync_decr_and_fetch((volatile _agpack_atomic_counter_t*)buffer) == 0) {
        free(buffer);
    }
}

static inline void incr_count(void* buffer)
{
    // atomic ++*(_agpack_atomic_counter_t*)buffer;
    _agpack_sync_incr_and_fetch((volatile _agpack_atomic_counter_t*)buffer);
}

static inline _agpack_atomic_counter_t get_count(void* buffer)
{
    return *(volatile _agpack_atomic_counter_t*)buffer;
}

bool agpack_unpacker_init(agpack_unpacker* mpac, size_t initial_buffer_size)
{
    char* buffer;
    void* ctx;

    if(initial_buffer_size < COUNTER_SIZE) {
        initial_buffer_size = COUNTER_SIZE;
    }

    buffer = (char*)malloc(initial_buffer_size);
    if(buffer == NULL) {
        return false;
    }

    ctx = malloc(sizeof(template_context));
    if(ctx == NULL) {
        free(buffer);
        return false;
    }

    mpac->buffer = buffer;
    mpac->used = COUNTER_SIZE;
    mpac->free = initial_buffer_size - mpac->used;
    mpac->off = COUNTER_SIZE;
    mpac->parsed = 0;
    mpac->initial_buffer_size = initial_buffer_size;
    mpac->z = NULL;
    mpac->ctx = ctx;

    init_count(mpac->buffer);

    template_init(CTX_CAST(mpac->ctx));
    CTX_CAST(mpac->ctx)->user.z = &mpac->z;
    CTX_CAST(mpac->ctx)->user.referenced = false;

    return true;
}

void agpack_unpacker_destroy(agpack_unpacker* mpac)
{
    agpack_zone_free(mpac->z);
    free(mpac->ctx);
    decr_count(mpac->buffer);
}

agpack_unpacker* agpack_unpacker_new(size_t initial_buffer_size)
{
    agpack_unpacker* mpac = (agpack_unpacker*)malloc(sizeof(agpack_unpacker));
    if(mpac == NULL) {
        return NULL;
    }

    if(!agpack_unpacker_init(mpac, initial_buffer_size)) {
        free(mpac);
        return NULL;
    }

    return mpac;
}

void agpack_unpacker_free(agpack_unpacker* mpac)
{
    agpack_unpacker_destroy(mpac);
    free(mpac);
}

bool agpack_unpacker_expand_buffer(agpack_unpacker* mpac, size_t size)
{
    if(mpac->used == mpac->off && get_count(mpac->buffer) == 1
            && !CTX_REFERENCED(mpac)) {
        // rewind buffer
        mpac->free += mpac->used - COUNTER_SIZE;
        mpac->used = COUNTER_SIZE;
        mpac->off = COUNTER_SIZE;

        if(mpac->free >= size) {
            return true;
        }
    }

    if(mpac->off == COUNTER_SIZE) {
        char* tmp;
        size_t next_size = (mpac->used + mpac->free) * 2;  // include COUNTER_SIZE
        while(next_size < size + mpac->used) {
            size_t tmp_next_size = next_size * 2;
            if (tmp_next_size <= next_size) {
                next_size = size + mpac->used;
                break;
            }
            next_size = tmp_next_size;
        }

        tmp = (char*)realloc(mpac->buffer, next_size);
        if(tmp == NULL) {
            return false;
        }

        mpac->buffer = tmp;
        mpac->free = next_size - mpac->used;

    } else {
        char* tmp;
        size_t next_size = mpac->initial_buffer_size;  // include COUNTER_SIZE
        size_t not_parsed = mpac->used - mpac->off;
        while(next_size < size + not_parsed + COUNTER_SIZE) {
            size_t tmp_next_size = next_size * 2;
            if (tmp_next_size <= next_size) {
                next_size = size + not_parsed + COUNTER_SIZE;
                break;
            }
            next_size = tmp_next_size;
        }

        tmp = (char*)malloc(next_size);
        if(tmp == NULL) {
            return false;
        }

        init_count(tmp);

        memcpy(tmp+COUNTER_SIZE, mpac->buffer+mpac->off, not_parsed);

        if(CTX_REFERENCED(mpac)) {
            if(!agpack_zone_push_finalizer(mpac->z, decr_count, mpac->buffer)) {
                free(tmp);
                return false;
            }
            CTX_REFERENCED(mpac) = false;
        } else {
            decr_count(mpac->buffer);
        }

        mpac->buffer = tmp;
        mpac->used = not_parsed + COUNTER_SIZE;
        mpac->free = next_size - mpac->used;
        mpac->off = COUNTER_SIZE;
    }

    return true;
}

int agpack_unpacker_execute(agpack_unpacker* mpac)
{
    size_t off = mpac->off;
    int ret = template_execute(CTX_CAST(mpac->ctx),
            mpac->buffer, mpac->used, &mpac->off);
    if(mpac->off > off) {
        mpac->parsed += mpac->off - off;
    }
    return ret;
}

agpack_object agpack_unpacker_data(agpack_unpacker* mpac)
{
    return template_data(CTX_CAST(mpac->ctx));
}

agpack_zone* agpack_unpacker_release_zone(agpack_unpacker* mpac)
{
    agpack_zone* old = mpac->z;

    if (old == NULL) return NULL;
    if(!agpack_unpacker_flush_zone(mpac)) {
        return NULL;
    }

    mpac->z = NULL;
    CTX_CAST(mpac->ctx)->user.z = &mpac->z;

    return old;
}

void agpack_unpacker_reset_zone(agpack_unpacker* mpac)
{
    agpack_zone_clear(mpac->z);
}

bool agpack_unpacker_flush_zone(agpack_unpacker* mpac)
{
    if(CTX_REFERENCED(mpac)) {
        if(!agpack_zone_push_finalizer(mpac->z, decr_count, mpac->buffer)) {
            return false;
        }
        CTX_REFERENCED(mpac) = false;

        incr_count(mpac->buffer);
    }

    return true;
}

void agpack_unpacker_reset(agpack_unpacker* mpac)
{
    template_init(CTX_CAST(mpac->ctx));
    // don't reset referenced flag
    mpac->parsed = 0;
}

static inline agpack_unpack_return unpacker_next(agpack_unpacker* mpac,
                                                  agpack_unpacked* result)
{
    int ret;

    agpack_unpacked_destroy(result);

    ret = agpack_unpacker_execute(mpac);

    if(ret < 0) {
        result->zone = NULL;
        memset(&result->data, 0, sizeof(agpack_object));
        return (agpack_unpack_return)ret;
    }

    if(ret == 0) {
        return AGPACK_UNPACK_CONTINUE;
    }
    result->zone = agpack_unpacker_release_zone(mpac);
    result->data = agpack_unpacker_data(mpac);

    return AGPACK_UNPACK_SUCCESS;
}

agpack_unpack_return agpack_unpacker_next(agpack_unpacker* mpac,
                                            agpack_unpacked* result)
{
    agpack_unpack_return ret;

    ret = unpacker_next(mpac, result);
    if (ret == AGPACK_UNPACK_SUCCESS) {
        agpack_unpacker_reset(mpac);
    }

    return ret;
}

agpack_unpack_return
agpack_unpacker_next_with_size(agpack_unpacker* mpac,
                                agpack_unpacked* result, size_t *p_bytes)
{
    agpack_unpack_return ret;

    ret = unpacker_next(mpac, result);
    if (ret == AGPACK_UNPACK_SUCCESS || ret == AGPACK_UNPACK_CONTINUE) {
        *p_bytes = mpac->parsed;
    }

    if (ret == AGPACK_UNPACK_SUCCESS) {
        agpack_unpacker_reset(mpac);
    }

    return ret;
}

agpack_unpack_return
agpack_unpack(const char* data, size_t len, size_t* off,
        agpack_zone* result_zone, agpack_object* result)
{
    size_t noff = 0;
    if(off != NULL) { noff = *off; }

    if(len <= noff) {
        // FIXME
        return AGPACK_UNPACK_CONTINUE;
    }
    else {
        int e;
        template_context ctx;
        template_init(&ctx);

        ctx.user.z = &result_zone;
        ctx.user.referenced = false;

        e = template_execute(&ctx, data, len, &noff);
        if(e < 0) {
            return (agpack_unpack_return)e;
        }

        if(off != NULL) { *off = noff; }

        if(e == 0) {
            return AGPACK_UNPACK_CONTINUE;
        }

        *result = template_data(&ctx);

        if(noff < len) {
            return AGPACK_UNPACK_EXTRA_BYTES;
        }

        return AGPACK_UNPACK_SUCCESS;
    }
}

agpack_unpack_return
agpack_unpack_next(agpack_unpacked* result,
        const char* data, size_t len, size_t* off)
{
    size_t noff = 0;
    agpack_unpacked_destroy(result);

    if(off != NULL) { noff = *off; }

    if(len <= noff) {
        return AGPACK_UNPACK_CONTINUE;
    }

    {
        int e;
        template_context ctx;
        template_init(&ctx);

        ctx.user.z = &result->zone;
        ctx.user.referenced = false;

        e = template_execute(&ctx, data, len, &noff);

        if(off != NULL) { *off = noff; }

        if(e < 0) {
            agpack_zone_free(result->zone);
            result->zone = NULL;
            return (agpack_unpack_return)e;
        }

        if(e == 0) {
            return AGPACK_UNPACK_CONTINUE;
        }

        result->data = template_data(&ctx);

        return AGPACK_UNPACK_SUCCESS;
    }
}

#if defined(AGPACK_OLD_COMPILER_BUS_ERROR_WORKAROUND)
// FIXME: Dirty hack to avoid a bus error caused by OS X's old gcc.
static void dummy_function_to_avoid_bus_error()
{
}
#endif
