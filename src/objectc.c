/*
 * MessagePack for C dynamic typing routine
 *
 * Copyright (C) 2008-2009 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#if defined(_KERNEL_MODE)
#  undef  _NO_CRT_STDIO_INLINE
#  define _NO_CRT_STDIO_INLINE
#endif

#include "agpack/object.h"
#include "agpack/pack.h"
#include <ctype.h>

#include <stdio.h>
#include <string.h>

#if defined(_MSC_VER)
#if _MSC_VER >= 1800
#include <inttypes.h>
#else
#define PRIu64 "I64u"
#define PRIi64 "I64i"
#define PRIi8 "i"
#endif
#else
#include <inttypes.h>
#endif

#if defined(_KERNEL_MODE)
#  undef  snprintf
#  define snprintf _snprintf
#endif

int agpack_pack_object(agpack_packer* pk, agpack_object d)
{
    switch(d.type) {
    case AGPACK_OBJECT_NIL:
        return agpack_pack_nil(pk);

    case AGPACK_OBJECT_BOOLEAN:
        if(d.via.boolean) {
            return agpack_pack_true(pk);
        } else {
            return agpack_pack_false(pk);
        }

    case AGPACK_OBJECT_POSITIVE_INTEGER:
        return agpack_pack_uint64(pk, d.via.u64);

    case AGPACK_OBJECT_NEGATIVE_INTEGER:
        return agpack_pack_int64(pk, d.via.i64);

    case AGPACK_OBJECT_FLOAT32:
        return agpack_pack_float(pk, (float)d.via.f64);

    case AGPACK_OBJECT_FLOAT64:
        return agpack_pack_double(pk, d.via.f64);

    case AGPACK_OBJECT_STR:
        {
            int ret = agpack_pack_str(pk, d.via.str.size);
            if(ret < 0) { return ret; }
            return agpack_pack_str_body(pk, d.via.str.ptr, d.via.str.size);
        }

    case AGPACK_OBJECT_BIN:
        {
            int ret = agpack_pack_bin(pk, d.via.bin.size);
            if(ret < 0) { return ret; }
            return agpack_pack_bin_body(pk, d.via.bin.ptr, d.via.bin.size);
        }

    case AGPACK_OBJECT_EXT:
        {
            int ret = agpack_pack_ext(pk, d.via.ext.size, d.via.ext.type);
            if(ret < 0) { return ret; }
            return agpack_pack_ext_body(pk, d.via.ext.ptr, d.via.ext.size);
        }

    case AGPACK_OBJECT_ARRAY:
        {
            int ret = agpack_pack_array(pk, d.via.array.size);
            if(ret < 0) {
                return ret;
            }
            else {
                agpack_object* o = d.via.array.ptr;
                agpack_object* const oend = d.via.array.ptr + d.via.array.size;
                for(; o != oend; ++o) {
                    ret = agpack_pack_object(pk, *o);
                    if(ret < 0) { return ret; }
                }

                return 0;
            }
        }

    case AGPACK_OBJECT_MAP:
        {
            int ret = agpack_pack_map(pk, d.via.map.size);
            if(ret < 0) {
                return ret;
            }
            else {
                agpack_object_kv* kv = d.via.map.ptr;
                agpack_object_kv* const kvend = d.via.map.ptr + d.via.map.size;
                for(; kv != kvend; ++kv) {
                    ret = agpack_pack_object(pk, kv->key);
                    if(ret < 0) { return ret; }
                    ret = agpack_pack_object(pk, kv->val);
                    if(ret < 0) { return ret; }
                }

                return 0;
            }
        }

    default:
        return -1;
    }
}

#if !defined(_KERNEL_MODE)

static void agpack_object_bin_print(FILE* out, const char *ptr, size_t size)
{
    size_t i;
    for (i = 0; i < size; ++i) {
        if (ptr[i] == '"') {
            fputs("\\\"", out);
        } else if (isprint((unsigned char)ptr[i])) {
            fputc(ptr[i], out);
        } else {
            fprintf(out, "\\x%02x", (unsigned char)ptr[i]);
        }
    }
}

void agpack_object_print(FILE* out, agpack_object o)
{
    switch(o.type) {
    case AGPACK_OBJECT_NIL:
        fprintf(out, "nil");
        break;

    case AGPACK_OBJECT_BOOLEAN:
        fprintf(out, (o.via.boolean ? "true" : "false"));
        break;

    case AGPACK_OBJECT_POSITIVE_INTEGER:
#if defined(PRIu64)
        fprintf(out, "%" PRIu64, o.via.u64);
#else
        if (o.via.u64 > ULONG_MAX)
            fprintf(out, "over 4294967295");
        else
            fprintf(out, "%lu", (unsigned long)o.via.u64);
#endif
        break;

    case AGPACK_OBJECT_NEGATIVE_INTEGER:
#if defined(PRIi64)
        fprintf(out, "%" PRIi64, o.via.i64);
#else
        if (o.via.i64 > LONG_MAX)
            fprintf(out, "over +2147483647");
        else if (o.via.i64 < LONG_MIN)
            fprintf(out, "under -2147483648");
        else
            fprintf(out, "%ld", (signed long)o.via.i64);
#endif
        break;

    case AGPACK_OBJECT_FLOAT32:
    case AGPACK_OBJECT_FLOAT64:
        fprintf(out, "%f", o.via.f64);
        break;

    case AGPACK_OBJECT_STR:
        fprintf(out, "\"");
        fwrite(o.via.str.ptr, o.via.str.size, 1, out);
        fprintf(out, "\"");
        break;

    case AGPACK_OBJECT_BIN:
        fprintf(out, "\"");
        agpack_object_bin_print(out, o.via.bin.ptr, o.via.bin.size);
        fprintf(out, "\"");
        break;

    case AGPACK_OBJECT_EXT:
#if defined(PRIi8)
        fprintf(out, "(ext: %" PRIi8 ")", o.via.ext.type);
#else
        fprintf(out, "(ext: %d)", (int)o.via.ext.type);
#endif
        fprintf(out, "\"");
        agpack_object_bin_print(out, o.via.ext.ptr, o.via.ext.size);
        fprintf(out, "\"");
        break;

    case AGPACK_OBJECT_ARRAY:
        fprintf(out, "[");
        if(o.via.array.size != 0) {
            agpack_object* p = o.via.array.ptr;
            agpack_object* const pend = o.via.array.ptr + o.via.array.size;
            agpack_object_print(out, *p);
            ++p;
            for(; p < pend; ++p) {
                fprintf(out, ", ");
                agpack_object_print(out, *p);
            }
        }
        fprintf(out, "]");
        break;

    case AGPACK_OBJECT_MAP:
        fprintf(out, "{");
        if(o.via.map.size != 0) {
            agpack_object_kv* p = o.via.map.ptr;
            agpack_object_kv* const pend = o.via.map.ptr + o.via.map.size;
            agpack_object_print(out, p->key);
            fprintf(out, "=>");
            agpack_object_print(out, p->val);
            ++p;
            for(; p < pend; ++p) {
                fprintf(out, ", ");
                agpack_object_print(out, p->key);
                fprintf(out, "=>");
                agpack_object_print(out, p->val);
            }
        }
        fprintf(out, "}");
        break;

    default:
        // FIXME
#if defined(PRIu64)
        fprintf(out, "#<UNKNOWN %i %" PRIu64 ">", o.type, o.via.u64);
#else
        if (o.via.u64 > ULONG_MAX)
            fprintf(out, "#<UNKNOWN %i over 4294967295>", o.type);
        else
            fprintf(out, "#<UNKNOWN %i %lu>", o.type, (unsigned long)o.via.u64);
#endif

    }
}

#endif

#define AGPACK_CHECKED_CALL(ret, func, aux_buffer, aux_buffer_size, ...) \
    ret = func(aux_buffer, aux_buffer_size, __VA_ARGS__);                 \
    if (ret <= 0 || ret >= (int)aux_buffer_size) return 0;                \
    aux_buffer = aux_buffer + ret;                                        \
    aux_buffer_size = aux_buffer_size - ret                               \

static int agpack_object_bin_print_buffer(char *buffer, size_t buffer_size, const char *ptr, size_t size)
{
    size_t i;
    char *aux_buffer = buffer;
    size_t aux_buffer_size = buffer_size;
    int ret;

    for (i = 0; i < size; ++i) {
        if (ptr[i] == '"') {
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "\\\"");
        } else if (isprint((unsigned char)ptr[i])) {
            if (aux_buffer_size > 0) {
                memcpy(aux_buffer, ptr + i, 1);
                aux_buffer = aux_buffer + 1;
                aux_buffer_size = aux_buffer_size - 1;
            }
        } else {
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "\\x%02x", (unsigned char)ptr[i]);
        }
    }

    return (int)(buffer_size - aux_buffer_size);
}

int agpack_object_print_buffer(char *buffer, size_t buffer_size, agpack_object o)
{
    char *aux_buffer = buffer;
    size_t aux_buffer_size = buffer_size;
    int ret;
    switch(o.type) {
    case AGPACK_OBJECT_NIL:
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "nil");
        break;

    case AGPACK_OBJECT_BOOLEAN:
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, (o.via.boolean ? "true" : "false"));
        break;

    case AGPACK_OBJECT_POSITIVE_INTEGER:
#if defined(PRIu64)
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "%" PRIu64, o.via.u64);
#else
        if (o.via.u64 > ULONG_MAX) {
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "over 4294967295");
        } else {
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "%lu", (unsigned long)o.via.u64);
        }
#endif
        break;

    case AGPACK_OBJECT_NEGATIVE_INTEGER:
#if defined(PRIi64)
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "%" PRIi64, o.via.i64);
#else
        if (o.via.i64 > LONG_MAX) {
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "over +2147483647");
        } else if (o.via.i64 < LONG_MIN) {
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "under -2147483648");
        } else {
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "%ld", (signed long)o.via.i64);
        }
#endif
        break;

    case AGPACK_OBJECT_FLOAT32:
    case AGPACK_OBJECT_FLOAT64:
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "%f", o.via.f64);
        break;

    case AGPACK_OBJECT_STR:
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "\"");
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "%.*s", (int)o.via.str.size, o.via.str.ptr);
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "\"");
        break;

    case AGPACK_OBJECT_BIN:
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "\"");
        AGPACK_CHECKED_CALL(ret, agpack_object_bin_print_buffer, aux_buffer, aux_buffer_size, o.via.bin.ptr, o.via.bin.size);
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "\"");
        break;

    case AGPACK_OBJECT_EXT:
#if defined(PRIi8)
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "(ext: %" PRIi8 ")", o.via.ext.type);
#else
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "(ext: %d)", (int)o.via.ext.type);
#endif
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "\"");
        AGPACK_CHECKED_CALL(ret, agpack_object_bin_print_buffer, aux_buffer, aux_buffer_size, o.via.ext.ptr, o.via.ext.size);
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "\"");
        break;

    case AGPACK_OBJECT_ARRAY:
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "[");
        if(o.via.array.size != 0) {
            agpack_object* p = o.via.array.ptr;
            agpack_object* const pend = o.via.array.ptr + o.via.array.size;
            AGPACK_CHECKED_CALL(ret, agpack_object_print_buffer, aux_buffer, aux_buffer_size, *p);
            ++p;
            for(; p < pend; ++p) {
                AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, ", ");
                AGPACK_CHECKED_CALL(ret, agpack_object_print_buffer, aux_buffer, aux_buffer_size, *p);
            }
        }
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "]");
        break;

    case AGPACK_OBJECT_MAP:
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "{");
        if(o.via.map.size != 0) {
            agpack_object_kv* p = o.via.map.ptr;
            agpack_object_kv* const pend = o.via.map.ptr + o.via.map.size;
            AGPACK_CHECKED_CALL(ret, agpack_object_print_buffer, aux_buffer, aux_buffer_size, p->key);
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "=>");
            AGPACK_CHECKED_CALL(ret, agpack_object_print_buffer, aux_buffer, aux_buffer_size, p->val);
            ++p;
            for(; p < pend; ++p) {
                AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, ", ");
                AGPACK_CHECKED_CALL(ret, agpack_object_print_buffer, aux_buffer, aux_buffer_size, p->key);
                AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "=>");
                AGPACK_CHECKED_CALL(ret, agpack_object_print_buffer, aux_buffer, aux_buffer_size, p->val);
            }
        }
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "}");
        break;

    default:
    // FIXME
#if defined(PRIu64)
        AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "#<UNKNOWN %i %" PRIu64 ">", o.type, o.via.u64);
#else
        if (o.via.u64 > ULONG_MAX) {
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "#<UNKNOWN %i over 4294967295>", o.type);
        } else {
            AGPACK_CHECKED_CALL(ret, snprintf, aux_buffer, aux_buffer_size, "#<UNKNOWN %i %lu>", o.type, (unsigned long)o.via.u64);
        }
#endif
    }

    return (int)(buffer_size - aux_buffer_size);
}

#undef AGPACK_CHECKED_CALL

bool agpack_object_equal(const agpack_object x, const agpack_object y)
{
    if(x.type != y.type) { return false; }

    switch(x.type) {
    case AGPACK_OBJECT_NIL:
        return true;

    case AGPACK_OBJECT_BOOLEAN:
        return x.via.boolean == y.via.boolean;

    case AGPACK_OBJECT_POSITIVE_INTEGER:
        return x.via.u64 == y.via.u64;

    case AGPACK_OBJECT_NEGATIVE_INTEGER:
        return x.via.i64 == y.via.i64;

    case AGPACK_OBJECT_FLOAT32:
    case AGPACK_OBJECT_FLOAT64:
        return x.via.f64 == y.via.f64;

    case AGPACK_OBJECT_STR:
        return x.via.str.size == y.via.str.size &&
            memcmp(x.via.str.ptr, y.via.str.ptr, x.via.str.size) == 0;

    case AGPACK_OBJECT_BIN:
        return x.via.bin.size == y.via.bin.size &&
            memcmp(x.via.bin.ptr, y.via.bin.ptr, x.via.bin.size) == 0;

    case AGPACK_OBJECT_EXT:
        return x.via.ext.size == y.via.ext.size &&
            x.via.ext.type == y.via.ext.type &&
            memcmp(x.via.ext.ptr, y.via.ext.ptr, x.via.ext.size) == 0;

    case AGPACK_OBJECT_ARRAY:
        if(x.via.array.size != y.via.array.size) {
            return false;
        } else if(x.via.array.size == 0) {
            return true;
        } else {
            agpack_object* px = x.via.array.ptr;
            agpack_object* const pxend = x.via.array.ptr + x.via.array.size;
            agpack_object* py = y.via.array.ptr;
            do {
                if(!agpack_object_equal(*px, *py)) {
                    return false;
                }
                ++px;
                ++py;
            } while(px < pxend);
            return true;
        }

    case AGPACK_OBJECT_MAP:
        if(x.via.map.size != y.via.map.size) {
            return false;
        } else if(x.via.map.size == 0) {
            return true;
        } else {
            agpack_object_kv* px = x.via.map.ptr;
            agpack_object_kv* const pxend = x.via.map.ptr + x.via.map.size;
            agpack_object_kv* py = y.via.map.ptr;
            do {
                if(!agpack_object_equal(px->key, py->key) || !agpack_object_equal(px->val, py->val)) {
                    return false;
                }
                ++px;
                ++py;
            } while(px < pxend);
            return true;
        }

    default:
        return false;
    }
}
