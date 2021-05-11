/*
 * MessagePack packing routine template
 *
 * Copyright (C) 2008-2010 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */

#if AGPACK_ENDIAN_LITTLE_BYTE
#define TAKE8_8(d)  ((uint8_t*)&d)[0]
#define TAKE8_16(d) ((uint8_t*)&d)[0]
#define TAKE8_32(d) ((uint8_t*)&d)[0]
#define TAKE8_64(d) ((uint8_t*)&d)[0]
#elif AGPACK_ENDIAN_BIG_BYTE
#define TAKE8_8(d)  ((uint8_t*)&d)[0]
#define TAKE8_16(d) ((uint8_t*)&d)[1]
#define TAKE8_32(d) ((uint8_t*)&d)[3]
#define TAKE8_64(d) ((uint8_t*)&d)[7]
#else
#error agpack-c supports only big endian and little endian
#endif

#ifndef agpack_pack_inline_func
#error agpack_pack_inline_func template is not defined
#endif

#ifndef agpack_pack_user
#error agpack_pack_user type is not defined
#endif

#ifndef agpack_pack_append_buffer
#error agpack_pack_append_buffer callback is not defined
#endif

#if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable : 4204)   /* nonstandard extension used: non-constant aggregate initializer */
#endif

/*
 * Integer
 */

#define agpack_pack_real_uint8(x, d) \
do { \
    if(d < (1<<7)) { \
        /* fixnum */ \
        agpack_pack_append_buffer(x, &TAKE8_8(d), 1); \
    } else { \
        /* unsigned 8 */ \
        unsigned char buf[2] = {0xcc, TAKE8_8(d)}; \
        agpack_pack_append_buffer(x, buf, 2); \
    } \
} while(0)

#define agpack_pack_real_uint16(x, d) \
do { \
    if(d < (1<<7)) { \
        /* fixnum */ \
        agpack_pack_append_buffer(x, &TAKE8_16(d), 1); \
    } else if(d < (1<<8)) { \
        /* unsigned 8 */ \
        unsigned char buf[2] = {0xcc, TAKE8_16(d)}; \
        agpack_pack_append_buffer(x, buf, 2); \
    } else { \
        /* unsigned 16 */ \
        unsigned char buf[3]; \
        buf[0] = 0xcd; _agpack_store16(&buf[1], (uint16_t)d); \
        agpack_pack_append_buffer(x, buf, 3); \
    } \
} while(0)

#define agpack_pack_real_uint32(x, d) \
do { \
    if(d < (1<<8)) { \
        if(d < (1<<7)) { \
            /* fixnum */ \
            agpack_pack_append_buffer(x, &TAKE8_32(d), 1); \
        } else { \
            /* unsigned 8 */ \
            unsigned char buf[2] = {0xcc, TAKE8_32(d)}; \
            agpack_pack_append_buffer(x, buf, 2); \
        } \
    } else { \
        if(d < (1<<16)) { \
            /* unsigned 16 */ \
            unsigned char buf[3]; \
            buf[0] = 0xcd; _agpack_store16(&buf[1], (uint16_t)d); \
            agpack_pack_append_buffer(x, buf, 3); \
        } else { \
            /* unsigned 32 */ \
            unsigned char buf[5]; \
            buf[0] = 0xce; _agpack_store32(&buf[1], (uint32_t)d); \
            agpack_pack_append_buffer(x, buf, 5); \
        } \
    } \
} while(0)

#define agpack_pack_real_uint64(x, d) \
do { \
    if(d < (1ULL<<8)) { \
        if(d < (1ULL<<7)) { \
            /* fixnum */ \
            agpack_pack_append_buffer(x, &TAKE8_64(d), 1); \
        } else { \
            /* unsigned 8 */ \
            unsigned char buf[2] = {0xcc, TAKE8_64(d)}; \
            agpack_pack_append_buffer(x, buf, 2); \
        } \
    } else { \
        if(d < (1ULL<<16)) { \
            /* unsigned 16 */ \
            unsigned char buf[3]; \
            buf[0] = 0xcd; _agpack_store16(&buf[1], (uint16_t)d); \
            agpack_pack_append_buffer(x, buf, 3); \
        } else if(d < (1ULL<<32)) { \
            /* unsigned 32 */ \
            unsigned char buf[5]; \
            buf[0] = 0xce; _agpack_store32(&buf[1], (uint32_t)d); \
            agpack_pack_append_buffer(x, buf, 5); \
        } else { \
            /* unsigned 64 */ \
            unsigned char buf[9]; \
            buf[0] = 0xcf; _agpack_store64(&buf[1], d); \
            agpack_pack_append_buffer(x, buf, 9); \
        } \
    } \
} while(0)

#define agpack_pack_real_int8(x, d) \
do { \
    if(d < -(1<<5)) { \
        /* signed 8 */ \
        unsigned char buf[2] = {0xd0, TAKE8_8(d)}; \
        agpack_pack_append_buffer(x, buf, 2); \
    } else { \
        /* fixnum */ \
        agpack_pack_append_buffer(x, &TAKE8_8(d), 1); \
    } \
} while(0)

#define agpack_pack_real_int16(x, d) \
do { \
    if(d < -(1<<5)) { \
        if(d < -(1<<7)) { \
            /* signed 16 */ \
            unsigned char buf[3]; \
            buf[0] = 0xd1; _agpack_store16(&buf[1], (int16_t)d); \
            agpack_pack_append_buffer(x, buf, 3); \
        } else { \
            /* signed 8 */ \
            unsigned char buf[2] = {0xd0, TAKE8_16(d)}; \
            agpack_pack_append_buffer(x, buf, 2); \
        } \
    } else if(d < (1<<7)) { \
        /* fixnum */ \
        agpack_pack_append_buffer(x, &TAKE8_16(d), 1); \
    } else { \
        if(d < (1<<8)) { \
            /* unsigned 8 */ \
            unsigned char buf[2] = {0xcc, TAKE8_16(d)}; \
            agpack_pack_append_buffer(x, buf, 2); \
        } else { \
            /* unsigned 16 */ \
            unsigned char buf[3]; \
            buf[0] = 0xcd; _agpack_store16(&buf[1], (uint16_t)d); \
            agpack_pack_append_buffer(x, buf, 3); \
        } \
    } \
} while(0)

#define agpack_pack_real_int32(x, d) \
do { \
    if(d < -(1<<5)) { \
        if(d < -(1<<15)) { \
            /* signed 32 */ \
            unsigned char buf[5]; \
            buf[0] = 0xd2; _agpack_store32(&buf[1], (int32_t)d); \
            agpack_pack_append_buffer(x, buf, 5); \
        } else if(d < -(1<<7)) { \
            /* signed 16 */ \
            unsigned char buf[3]; \
            buf[0] = 0xd1; _agpack_store16(&buf[1], (int16_t)d); \
            agpack_pack_append_buffer(x, buf, 3); \
        } else { \
            /* signed 8 */ \
            unsigned char buf[2] = {0xd0, TAKE8_32(d)}; \
            agpack_pack_append_buffer(x, buf, 2); \
        } \
    } else if(d < (1<<7)) { \
        /* fixnum */ \
        agpack_pack_append_buffer(x, &TAKE8_32(d), 1); \
    } else { \
        if(d < (1<<8)) { \
            /* unsigned 8 */ \
            unsigned char buf[2] = {0xcc, TAKE8_32(d)}; \
            agpack_pack_append_buffer(x, buf, 2); \
        } else if(d < (1<<16)) { \
            /* unsigned 16 */ \
            unsigned char buf[3]; \
            buf[0] = 0xcd; _agpack_store16(&buf[1], (uint16_t)d); \
            agpack_pack_append_buffer(x, buf, 3); \
        } else { \
            /* unsigned 32 */ \
            unsigned char buf[5]; \
            buf[0] = 0xce; _agpack_store32(&buf[1], (uint32_t)d); \
            agpack_pack_append_buffer(x, buf, 5); \
        } \
    } \
} while(0)

#define agpack_pack_real_int64(x, d) \
do { \
    if(d < -(1LL<<5)) { \
        if(d < -(1LL<<15)) { \
            if(d < -(1LL<<31)) { \
                /* signed 64 */ \
                unsigned char buf[9]; \
                buf[0] = 0xd3; _agpack_store64(&buf[1], d); \
                agpack_pack_append_buffer(x, buf, 9); \
            } else { \
                /* signed 32 */ \
                unsigned char buf[5]; \
                buf[0] = 0xd2; _agpack_store32(&buf[1], (int32_t)d); \
                agpack_pack_append_buffer(x, buf, 5); \
            } \
        } else { \
            if(d < -(1<<7)) { \
                /* signed 16 */ \
                unsigned char buf[3]; \
                buf[0] = 0xd1; _agpack_store16(&buf[1], (int16_t)d); \
                agpack_pack_append_buffer(x, buf, 3); \
            } else { \
                /* signed 8 */ \
                unsigned char buf[2] = {0xd0, TAKE8_64(d)}; \
                agpack_pack_append_buffer(x, buf, 2); \
            } \
        } \
    } else if(d < (1<<7)) { \
        /* fixnum */ \
        agpack_pack_append_buffer(x, &TAKE8_64(d), 1); \
    } else { \
        if(d < (1LL<<16)) { \
            if(d < (1<<8)) { \
                /* unsigned 8 */ \
                unsigned char buf[2] = {0xcc, TAKE8_64(d)}; \
                agpack_pack_append_buffer(x, buf, 2); \
            } else { \
                /* unsigned 16 */ \
                unsigned char buf[3]; \
                buf[0] = 0xcd; _agpack_store16(&buf[1], (uint16_t)d); \
                agpack_pack_append_buffer(x, buf, 3); \
            } \
        } else { \
            if(d < (1LL<<32)) { \
                /* unsigned 32 */ \
                unsigned char buf[5]; \
                buf[0] = 0xce; _agpack_store32(&buf[1], (uint32_t)d); \
                agpack_pack_append_buffer(x, buf, 5); \
            } else { \
                /* unsigned 64 */ \
                unsigned char buf[9]; \
                buf[0] = 0xcf; _agpack_store64(&buf[1], d); \
                agpack_pack_append_buffer(x, buf, 9); \
            } \
        } \
    } \
} while(0)


#ifdef agpack_pack_inline_func_fixint

agpack_pack_inline_func_fixint(_uint8)(agpack_pack_user x, uint8_t d)
{
    unsigned char buf[2] = {0xcc, TAKE8_8(d)};
    agpack_pack_append_buffer(x, buf, 2);
}

agpack_pack_inline_func_fixint(_uint16)(agpack_pack_user x, uint16_t d)
{
    unsigned char buf[3];
    buf[0] = 0xcd; _agpack_store16(&buf[1], d);
    agpack_pack_append_buffer(x, buf, 3);
}

agpack_pack_inline_func_fixint(_uint32)(agpack_pack_user x, uint32_t d)
{
    unsigned char buf[5];
    buf[0] = 0xce; _agpack_store32(&buf[1], d);
    agpack_pack_append_buffer(x, buf, 5);
}

agpack_pack_inline_func_fixint(_uint64)(agpack_pack_user x, uint64_t d)
{
    unsigned char buf[9];
    buf[0] = 0xcf; _agpack_store64(&buf[1], d);
    agpack_pack_append_buffer(x, buf, 9);
}

agpack_pack_inline_func_fixint(_int8)(agpack_pack_user x, int8_t d)
{
    unsigned char buf[2] = {0xd0, TAKE8_8(d)};
    agpack_pack_append_buffer(x, buf, 2);
}

agpack_pack_inline_func_fixint(_int16)(agpack_pack_user x, int16_t d)
{
    unsigned char buf[3];
    buf[0] = 0xd1; _agpack_store16(&buf[1], d);
    agpack_pack_append_buffer(x, buf, 3);
}

agpack_pack_inline_func_fixint(_int32)(agpack_pack_user x, int32_t d)
{
    unsigned char buf[5];
    buf[0] = 0xd2; _agpack_store32(&buf[1], d);
    agpack_pack_append_buffer(x, buf, 5);
}

agpack_pack_inline_func_fixint(_int64)(agpack_pack_user x, int64_t d)
{
    unsigned char buf[9];
    buf[0] = 0xd3; _agpack_store64(&buf[1], d);
    agpack_pack_append_buffer(x, buf, 9);
}

#undef agpack_pack_inline_func_fixint
#endif


agpack_pack_inline_func(_uint8)(agpack_pack_user x, uint8_t d)
{
    agpack_pack_real_uint8(x, d);
}

agpack_pack_inline_func(_uint16)(agpack_pack_user x, uint16_t d)
{
    agpack_pack_real_uint16(x, d);
}

agpack_pack_inline_func(_uint32)(agpack_pack_user x, uint32_t d)
{
    agpack_pack_real_uint32(x, d);
}

agpack_pack_inline_func(_uint64)(agpack_pack_user x, uint64_t d)
{
    agpack_pack_real_uint64(x, d);
}

agpack_pack_inline_func(_int8)(agpack_pack_user x, int8_t d)
{
    agpack_pack_real_int8(x, d);
}

agpack_pack_inline_func(_int16)(agpack_pack_user x, int16_t d)
{
    agpack_pack_real_int16(x, d);
}

agpack_pack_inline_func(_int32)(agpack_pack_user x, int32_t d)
{
    agpack_pack_real_int32(x, d);
}

agpack_pack_inline_func(_int64)(agpack_pack_user x, int64_t d)
{
    agpack_pack_real_int64(x, d);
}

agpack_pack_inline_func(_char)(agpack_pack_user x, char d)
{
#if defined(CHAR_MIN)
#if CHAR_MIN < 0
        agpack_pack_real_int8(x, d);
#else
        agpack_pack_real_uint8(x, d);
#endif
#else
#error CHAR_MIN is not defined
#endif
}

agpack_pack_inline_func(_signed_char)(agpack_pack_user x, signed char d)
{
    agpack_pack_real_int8(x, d);
}

agpack_pack_inline_func(_unsigned_char)(agpack_pack_user x, unsigned char d)
{
    agpack_pack_real_uint8(x, d);
}

#ifdef agpack_pack_inline_func_cint

agpack_pack_inline_func_cint(_short)(agpack_pack_user x, short d)
{
#if defined(SIZEOF_SHORT)
#if SIZEOF_SHORT == 2
    agpack_pack_real_int16(x, d);
#elif SIZEOF_SHORT == 4
    agpack_pack_real_int32(x, d);
#else
    agpack_pack_real_int64(x, d);
#endif

#elif defined(SHRT_MAX)
#if SHRT_MAX == 0x7fff
    agpack_pack_real_int16(x, d);
#elif SHRT_MAX == 0x7fffffff
    agpack_pack_real_int32(x, d);
#else
    agpack_pack_real_int64(x, d);
#endif

#else
if(sizeof(short) == 2) {
    agpack_pack_real_int16(x, d);
} else if(sizeof(short) == 4) {
    agpack_pack_real_int32(x, d);
} else {
    agpack_pack_real_int64(x, d);
}
#endif
}

agpack_pack_inline_func_cint(_int)(agpack_pack_user x, int d)
{
#if defined(SIZEOF_INT)
#if SIZEOF_INT == 2
    agpack_pack_real_int16(x, d);
#elif SIZEOF_INT == 4
    agpack_pack_real_int32(x, d);
#else
    agpack_pack_real_int64(x, d);
#endif

#elif defined(INT_MAX)
#if INT_MAX == 0x7fff
    agpack_pack_real_int16(x, d);
#elif INT_MAX == 0x7fffffff
    agpack_pack_real_int32(x, d);
#else
    agpack_pack_real_int64(x, d);
#endif

#else
if(sizeof(int) == 2) {
    agpack_pack_real_int16(x, d);
} else if(sizeof(int) == 4) {
    agpack_pack_real_int32(x, d);
} else {
    agpack_pack_real_int64(x, d);
}
#endif
}

agpack_pack_inline_func_cint(_long)(agpack_pack_user x, long d)
{
#if defined(SIZEOF_LONG)
#if SIZEOF_LONG == 2
    agpack_pack_real_int16(x, d);
#elif SIZEOF_LONG == 4
    agpack_pack_real_int32(x, d);
#else
    agpack_pack_real_int64(x, d);
#endif

#elif defined(LONG_MAX)
#if LONG_MAX == 0x7fffL
    agpack_pack_real_int16(x, d);
#elif LONG_MAX == 0x7fffffffL
    agpack_pack_real_int32(x, d);
#else
    agpack_pack_real_int64(x, d);
#endif

#else
if(sizeof(long) == 2) {
    agpack_pack_real_int16(x, d);
} else if(sizeof(long) == 4) {
    agpack_pack_real_int32(x, d);
} else {
    agpack_pack_real_int64(x, d);
}
#endif
}

agpack_pack_inline_func_cint(_long_long)(agpack_pack_user x, long long d)
{
#if defined(SIZEOF_LONG_LONG)
#if SIZEOF_LONG_LONG == 2
    agpack_pack_real_int16(x, d);
#elif SIZEOF_LONG_LONG == 4
    agpack_pack_real_int32(x, d);
#else
    agpack_pack_real_int64(x, d);
#endif

#elif defined(LLONG_MAX)
#if LLONG_MAX == 0x7fffL
    agpack_pack_real_int16(x, d);
#elif LLONG_MAX == 0x7fffffffL
    agpack_pack_real_int32(x, d);
#else
    agpack_pack_real_int64(x, d);
#endif

#else
if(sizeof(long long) == 2) {
    agpack_pack_real_int16(x, d);
} else if(sizeof(long long) == 4) {
    agpack_pack_real_int32(x, d);
} else {
    agpack_pack_real_int64(x, d);
}
#endif
}

agpack_pack_inline_func_cint(_unsigned_short)(agpack_pack_user x, unsigned short d)
{
#if defined(SIZEOF_SHORT)
#if SIZEOF_SHORT == 2
    agpack_pack_real_uint16(x, d);
#elif SIZEOF_SHORT == 4
    agpack_pack_real_uint32(x, d);
#else
    agpack_pack_real_uint64(x, d);
#endif

#elif defined(USHRT_MAX)
#if USHRT_MAX == 0xffffU
    agpack_pack_real_uint16(x, d);
#elif USHRT_MAX == 0xffffffffU
    agpack_pack_real_uint32(x, d);
#else
    agpack_pack_real_uint64(x, d);
#endif

#else
if(sizeof(unsigned short) == 2) {
    agpack_pack_real_uint16(x, d);
} else if(sizeof(unsigned short) == 4) {
    agpack_pack_real_uint32(x, d);
} else {
    agpack_pack_real_uint64(x, d);
}
#endif
}

agpack_pack_inline_func_cint(_unsigned_int)(agpack_pack_user x, unsigned int d)
{
#if defined(SIZEOF_INT)
#if SIZEOF_INT == 2
    agpack_pack_real_uint16(x, d);
#elif SIZEOF_INT == 4
    agpack_pack_real_uint32(x, d);
#else
    agpack_pack_real_uint64(x, d);
#endif

#elif defined(UINT_MAX)
#if UINT_MAX == 0xffffU
    agpack_pack_real_uint16(x, d);
#elif UINT_MAX == 0xffffffffU
    agpack_pack_real_uint32(x, d);
#else
    agpack_pack_real_uint64(x, d);
#endif

#else
if(sizeof(unsigned int) == 2) {
    agpack_pack_real_uint16(x, d);
} else if(sizeof(unsigned int) == 4) {
    agpack_pack_real_uint32(x, d);
} else {
    agpack_pack_real_uint64(x, d);
}
#endif
}

agpack_pack_inline_func_cint(_unsigned_long)(agpack_pack_user x, unsigned long d)
{
#if defined(SIZEOF_LONG)
#if SIZEOF_LONG == 2
    agpack_pack_real_uint16(x, d);
#elif SIZEOF_LONG == 4
    agpack_pack_real_uint32(x, d);
#else
    agpack_pack_real_uint64(x, d);
#endif

#elif defined(ULONG_MAX)
#if ULONG_MAX == 0xffffUL
    agpack_pack_real_uint16(x, d);
#elif ULONG_MAX == 0xffffffffUL
    agpack_pack_real_uint32(x, d);
#else
    agpack_pack_real_uint64(x, d);
#endif

#else
if(sizeof(unsigned long) == 2) {
    agpack_pack_real_uint16(x, d);
} else if(sizeof(unsigned long) == 4) {
    agpack_pack_real_uint32(x, d);
} else {
    agpack_pack_real_uint64(x, d);
}
#endif
}

agpack_pack_inline_func_cint(_unsigned_long_long)(agpack_pack_user x, unsigned long long d)
{
#if defined(SIZEOF_LONG_LONG)
#if SIZEOF_LONG_LONG == 2
    agpack_pack_real_uint16(x, d);
#elif SIZEOF_LONG_LONG == 4
    agpack_pack_real_uint32(x, d);
#else
    agpack_pack_real_uint64(x, d);
#endif

#elif defined(ULLONG_MAX)
#if ULLONG_MAX == 0xffffUL
    agpack_pack_real_uint16(x, d);
#elif ULLONG_MAX == 0xffffffffUL
    agpack_pack_real_uint32(x, d);
#else
    agpack_pack_real_uint64(x, d);
#endif

#else
if(sizeof(unsigned long long) == 2) {
    agpack_pack_real_uint16(x, d);
} else if(sizeof(unsigned long long) == 4) {
    agpack_pack_real_uint32(x, d);
} else {
    agpack_pack_real_uint64(x, d);
}
#endif
}

#undef agpack_pack_inline_func_cint
#endif



/*
 * Float
 */

agpack_pack_inline_func(_float)(agpack_pack_user x, float d)
{
    unsigned char buf[5];
    union { float f; uint32_t i; } mem;
    mem.f = d;
    buf[0] = 0xca; _agpack_store32(&buf[1], mem.i);
    agpack_pack_append_buffer(x, buf, 5);
}

agpack_pack_inline_func(_double)(agpack_pack_user x, double d)
{
    unsigned char buf[9];
    union { double f; uint64_t i; } mem;
    mem.f = d;
    buf[0] = 0xcb;
#if defined(TARGET_OS_IPHONE)
    // ok
#elif defined(__arm__) && !(__ARM_EABI__) // arm-oabi
    // https://github.com/agpack/agpack-perl/pull/1
    mem.i = (mem.i & 0xFFFFFFFFUL) << 32UL | (mem.i >> 32UL);
#endif
    _agpack_store64(&buf[1], mem.i);
    agpack_pack_append_buffer(x, buf, 9);
}


/*
 * Nil
 */

agpack_pack_inline_func(_nil)(agpack_pack_user x)
{
    static const unsigned char d = 0xc0;
    agpack_pack_append_buffer(x, &d, 1);
}


/*
 * Boolean
 */

agpack_pack_inline_func(_true)(agpack_pack_user x)
{
    static const unsigned char d = 0xc3;
    agpack_pack_append_buffer(x, &d, 1);
}

agpack_pack_inline_func(_false)(agpack_pack_user x)
{
    static const unsigned char d = 0xc2;
    agpack_pack_append_buffer(x, &d, 1);
}


/*
 * Array
 */

agpack_pack_inline_func(_array)(agpack_pack_user x, size_t n)
{
    if(n < 16) {
        unsigned char d = 0x90 | (uint8_t)n;
        agpack_pack_append_buffer(x, &d, 1);
    } else if(n < 65536) {
        unsigned char buf[3];
        buf[0] = 0xdc; _agpack_store16(&buf[1], (uint16_t)n);
        agpack_pack_append_buffer(x, buf, 3);
    } else {
        unsigned char buf[5];
        buf[0] = 0xdd; _agpack_store32(&buf[1], (uint32_t)n);
        agpack_pack_append_buffer(x, buf, 5);
    }
}


/*
 * Map
 */

agpack_pack_inline_func(_map)(agpack_pack_user x, size_t n)
{
    if(n < 16) {
        unsigned char d = 0x80 | (uint8_t)n;
        agpack_pack_append_buffer(x, &TAKE8_8(d), 1);
    } else if(n < 65536) {
        unsigned char buf[3];
        buf[0] = 0xde; _agpack_store16(&buf[1], (uint16_t)n);
        agpack_pack_append_buffer(x, buf, 3);
    } else {
        unsigned char buf[5];
        buf[0] = 0xdf; _agpack_store32(&buf[1], (uint32_t)n);
        agpack_pack_append_buffer(x, buf, 5);
    }
}


/*
 * Str
 */

agpack_pack_inline_func(_str)(agpack_pack_user x, size_t l)
{
    if(l < 32) {
        unsigned char d = 0xa0 | (uint8_t)l;
        agpack_pack_append_buffer(x, &TAKE8_8(d), 1);
    } else if(l < 256) {
        unsigned char buf[2];
        buf[0] = 0xd9; buf[1] = (uint8_t)l;
        agpack_pack_append_buffer(x, buf, 2);
    } else if(l < 65536) {
        unsigned char buf[3];
        buf[0] = 0xda; _agpack_store16(&buf[1], (uint16_t)l);
        agpack_pack_append_buffer(x, buf, 3);
    } else {
        unsigned char buf[5];
        buf[0] = 0xdb; _agpack_store32(&buf[1], (uint32_t)l);
        agpack_pack_append_buffer(x, buf, 5);
    }
}

agpack_pack_inline_func(_str_body)(agpack_pack_user x, const void* b, size_t l)
{
    agpack_pack_append_buffer(x, (const unsigned char*)b, l);
}

/*
 * Raw (V4)
 */

agpack_pack_inline_func(_v4raw)(agpack_pack_user x, size_t l)
{
    if(l < 32) {
        unsigned char d = 0xa0 | (uint8_t)l;
        agpack_pack_append_buffer(x, &TAKE8_8(d), 1);
    } else if(l < 65536) {
        unsigned char buf[3];
        buf[0] = 0xda; _agpack_store16(&buf[1], (uint16_t)l);
        agpack_pack_append_buffer(x, buf, 3);
    } else {
        unsigned char buf[5];
        buf[0] = 0xdb; _agpack_store32(&buf[1], (uint32_t)l);
        agpack_pack_append_buffer(x, buf, 5);
    }
}

agpack_pack_inline_func(_v4raw_body)(agpack_pack_user x, const void* b, size_t l)
{
    agpack_pack_append_buffer(x, (const unsigned char*)b, l);
}

/*
 * Bin
 */

agpack_pack_inline_func(_bin)(agpack_pack_user x, size_t l)
{
    if(l < 256) {
        unsigned char buf[2];
        buf[0] = 0xc4; buf[1] = (uint8_t)l;
        agpack_pack_append_buffer(x, buf, 2);
    } else if(l < 65536) {
        unsigned char buf[3];
        buf[0] = 0xc5; _agpack_store16(&buf[1], (uint16_t)l);
        agpack_pack_append_buffer(x, buf, 3);
    } else {
        unsigned char buf[5];
        buf[0] = 0xc6; _agpack_store32(&buf[1], (uint32_t)l);
        agpack_pack_append_buffer(x, buf, 5);
    }
}

agpack_pack_inline_func(_bin_body)(agpack_pack_user x, const void* b, size_t l)
{
    agpack_pack_append_buffer(x, (const unsigned char*)b, l);
}

/*
 * Ext
 */

agpack_pack_inline_func(_ext)(agpack_pack_user x, size_t l, int8_t type)
{
    switch(l) {
    case 1: {
        unsigned char buf[2];
        buf[0] = 0xd4;
        buf[1] = (unsigned char)type;
        agpack_pack_append_buffer(x, buf, 2);
    } break;
    case 2: {
        unsigned char buf[2];
        buf[0] = 0xd5;
        buf[1] = (unsigned char)type;
        agpack_pack_append_buffer(x, buf, 2);
    } break;
    case 4: {
        unsigned char buf[2];
        buf[0] = 0xd6;
        buf[1] = (unsigned char)type;
        agpack_pack_append_buffer(x, buf, 2);
    } break;
    case 8: {
        unsigned char buf[2];
        buf[0] = 0xd7;
        buf[1] = (unsigned char)type;
        agpack_pack_append_buffer(x, buf, 2);
    } break;
    case 16: {
        unsigned char buf[2];
        buf[0] = 0xd8;
        buf[1] = (unsigned char)type;
        agpack_pack_append_buffer(x, buf, 2);
    } break;
    default:
        if(l < 256) {
            unsigned char buf[3];
            buf[0] = 0xc7;
            buf[1] = (unsigned char)l;
            buf[2] = (unsigned char)type;
            agpack_pack_append_buffer(x, buf, 3);
        } else if(l < 65536) {
            unsigned char buf[4];
            buf[0] = 0xc8;
            _agpack_store16(&buf[1], l);
            buf[3] = (unsigned char)type;
            agpack_pack_append_buffer(x, buf, 4);
        } else {
            unsigned char buf[6];
            buf[0] = 0xc9;
            _agpack_store32(&buf[1], l);
            buf[5] = (unsigned char)type;
            agpack_pack_append_buffer(x, buf, 6);
        }
        break;
    }
}

agpack_pack_inline_func(_ext_body)(agpack_pack_user x, const void* b, size_t l)
{
    agpack_pack_append_buffer(x, (const unsigned char*)b, l);
}

agpack_pack_inline_func(_timestamp)(agpack_pack_user x, const agpack_timestamp* d)
{
    if ((((int64_t)d->tv_sec) >> 34) == 0) {
        uint64_t data64 = ((uint64_t) d->tv_nsec << 34) | (uint64_t)d->tv_sec;
        if ((data64 & 0xffffffff00000000L) == 0)   {
            // timestamp 32
            char buf[4];
            uint32_t data32 = (uint32_t)data64;
            agpack_pack_ext(x, 4, -1);
            _agpack_store32(buf, data32);
            agpack_pack_append_buffer(x, buf, 4);
        } else {
            // timestamp 64
            char buf[8];
            agpack_pack_ext(x, 8, -1);
            _agpack_store64(buf, data64);
            agpack_pack_append_buffer(x, buf, 8);
        }
    } else  {
        // timestamp 96
        char buf[12];
        _agpack_store32(&buf[0], d->tv_nsec);
        _agpack_store64(&buf[4], d->tv_sec);
        agpack_pack_ext(x, 12, -1);
        agpack_pack_append_buffer(x, buf, 12);
    }
}

#undef agpack_pack_inline_func
#undef agpack_pack_user
#undef agpack_pack_append_buffer

#undef TAKE8_8
#undef TAKE8_16
#undef TAKE8_32
#undef TAKE8_64

#undef agpack_pack_real_uint8
#undef agpack_pack_real_uint16
#undef agpack_pack_real_uint32
#undef agpack_pack_real_uint64
#undef agpack_pack_real_int8
#undef agpack_pack_real_int16
#undef agpack_pack_real_int32
#undef agpack_pack_real_int64

#if defined(_MSC_VER)
#   pragma warning(pop)
#endif
