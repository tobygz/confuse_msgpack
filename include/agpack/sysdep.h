/*
 * MessagePack system dependencies
 *
 * Copyright (C) 2008-2010 FURUHASHI Sadayuki
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_SYSDEP_H
#define AGPACK_SYSDEP_H

#include <stdlib.h>
#include <stddef.h>

#if defined(_MSC_VER) && _MSC_VER <= 1800
#   define snprintf(buf, len, format,...) _snprintf_s(buf, len, _TRUNCATE, format, __VA_ARGS__)
#endif

#if defined(_MSC_VER) && _MSC_VER < 1600
    typedef signed __int8 int8_t;
    typedef unsigned __int8 uint8_t;
    typedef signed __int16 int16_t;
    typedef unsigned __int16 uint16_t;
    typedef signed __int32 int32_t;
    typedef unsigned __int32 uint32_t;
    typedef signed __int64 int64_t;
    typedef unsigned __int64 uint64_t;
#elif defined(_MSC_VER)  // && _MSC_VER >= 1600
#   include <stdint.h>
#else
#   include <stdint.h>
#   include <stdbool.h>
#endif

#if !defined(AGPACK_DLLEXPORT)
#if defined(_MSC_VER)
#   define AGPACK_DLLEXPORT __declspec(dllexport)
#else  /* _MSC_VER */
#   define AGPACK_DLLEXPORT
#endif /* _MSC_VER */
#endif

#ifdef _WIN32
#   if defined(_KERNEL_MODE)
#       define _agpack_atomic_counter_header <ntddk.h>
#   else
#       define _agpack_atomic_counter_header <windows.h>
#       if !defined(WIN32_LEAN_AND_MEAN)
#           define WIN32_LEAN_AND_MEAN
#       endif /* WIN32_LEAN_AND_MEAN */
#   endif
    typedef long _agpack_atomic_counter_t;
#if defined(_AMD64_) || defined(_M_X64) || defined(_M_ARM64)
#    define _agpack_sync_decr_and_fetch(ptr) _InterlockedDecrement(ptr)
#    define _agpack_sync_incr_and_fetch(ptr) _InterlockedIncrement(ptr)
#else
#    define _agpack_sync_decr_and_fetch(ptr) InterlockedDecrement(ptr)
#    define _agpack_sync_incr_and_fetch(ptr) InterlockedIncrement(ptr)
#endif
#elif defined(__GNUC__) && ((__GNUC__*10 + __GNUC_MINOR__) < 41)

#   if defined(__cplusplus)
#       define _agpack_atomic_counter_header "agpack/gcc_atomic.hpp"
#   else
#       define _agpack_atomic_counter_header "agpack/gcc_atomic.h"
#   endif

#else
    typedef unsigned int _agpack_atomic_counter_t;
#   define _agpack_sync_decr_and_fetch(ptr) __sync_sub_and_fetch(ptr, 1)
#   define _agpack_sync_incr_and_fetch(ptr) __sync_add_and_fetch(ptr, 1)
#endif

#ifdef _WIN32

#   ifdef __cplusplus
    /* numeric_limits<T>::min,max */
#       ifdef max
#           undef max
#       endif
#       ifdef min
#           undef min
#       endif
#   endif

#elif defined(unix) || defined(__unix) || defined(__APPLE__) || defined(__OpenBSD__)

#include <arpa/inet.h>  /* __BYTE_ORDER */
#   if defined(linux)
#       include <byteswap.h>
#   endif

#endif

#if !defined(AGPACK_ENDIAN_LITTLE_BYTE) && !defined(AGPACK_ENDIAN_BIG_BYTE)
#include <agpack/predef/other/endian.h>
#endif // !defined(AGPACK_ENDIAN_LITTLE_BYTE) && !defined(AGPACK_ENDIAN_BIG_BYTE)

#if AGPACK_ENDIAN_LITTLE_BYTE

#   if defined(unix) || defined(__unix) || defined(__APPLE__) || defined(__OpenBSD__)
#       define _agpack_be16(x) ntohs((uint16_t)x)
#   else
#       if defined(ntohs)
#           define _agpack_be16(x) ntohs(x)
#       elif defined(_byteswap_ushort) || (defined(_MSC_VER) && _MSC_VER >= 1400)
#           define _agpack_be16(x) ((uint16_t)_byteswap_ushort((unsigned short)x))
#       else
#           define _agpack_be16(x) ( \
                ((((uint16_t)x) <<  8) ) | \
                ((((uint16_t)x) >>  8) ) )
#        endif
#   endif

#   if defined(unix) || defined(__unix) || defined(__APPLE__) || defined(__OpenBSD__)
#       define _agpack_be32(x) ntohl((uint32_t)x)
#   else
#       if defined(ntohl)
#           define _agpack_be32(x) ntohl(x)
#       elif defined(_byteswap_ulong) || (defined(_MSC_VER) && _MSC_VER >= 1400)
#           define _agpack_be32(x) ((uint32_t)_byteswap_ulong((unsigned long)x))
#       else
#           define _agpack_be32(x) \
                ( ((((uint32_t)x) << 24)               ) | \
                  ((((uint32_t)x) <<  8) & 0x00ff0000U ) | \
                  ((((uint32_t)x) >>  8) & 0x0000ff00U ) | \
                  ((((uint32_t)x) >> 24)               ) )
#       endif
#   endif

#   if defined(_byteswap_uint64) || (defined(_MSC_VER) && _MSC_VER >= 1400)
#        define _agpack_be64(x) (_byteswap_uint64(x))
#   elif defined(bswap_64)
#        define _agpack_be64(x) bswap_64(x)
#   elif defined(__DARWIN_OSSwapInt64)
#        define _agpack_be64(x) __DARWIN_OSSwapInt64(x)
#   else
#        define _agpack_be64(x) \
             ( ((((uint64_t)x) << 56)                         ) | \
               ((((uint64_t)x) << 40) & 0x00ff000000000000ULL ) | \
               ((((uint64_t)x) << 24) & 0x0000ff0000000000ULL ) | \
               ((((uint64_t)x) <<  8) & 0x000000ff00000000ULL ) | \
               ((((uint64_t)x) >>  8) & 0x00000000ff000000ULL ) | \
               ((((uint64_t)x) >> 24) & 0x0000000000ff0000ULL ) | \
               ((((uint64_t)x) >> 40) & 0x000000000000ff00ULL ) | \
               ((((uint64_t)x) >> 56)                         ) )
#   endif

#elif AGPACK_ENDIAN_BIG_BYTE

#   define _agpack_be16(x) (x)
#   define _agpack_be32(x) (x)
#   define _agpack_be64(x) (x)

#else
#   error agpack-c supports only big endian and little endian
#endif /* AGPACK_ENDIAN_LITTLE_BYTE */

#define _agpack_load16(cast, from, to) do {       \
        memcpy((cast*)(to), (from), sizeof(cast)); \
        *(to) = (cast)_agpack_be16(*(to));      \
    } while (0);

#define _agpack_load32(cast, from, to) do {       \
        memcpy((cast*)(to), (from), sizeof(cast)); \
        *(to) = (cast)_agpack_be32(*(to));        \
    } while (0);
#define _agpack_load64(cast, from, to) do {       \
        memcpy((cast*)(to), (from), sizeof(cast)); \
        *(to) = (cast)_agpack_be64(*(to));        \
    } while (0);

#define _agpack_store16(to, num) \
    do { uint16_t val = _agpack_be16(num); memcpy(to, &val, 2); } while(0)
#define _agpack_store32(to, num) \
    do { uint32_t val = _agpack_be32(num); memcpy(to, &val, 4); } while(0)
#define _agpack_store64(to, num) \
    do { uint64_t val = _agpack_be64(num); memcpy(to, &val, 8); } while(0)

/*
#define _agpack_load16(cast, from) \
    ({ cast val; memcpy(&val, (char*)from, 2); _agpack_be16(val); })
#define _agpack_load32(cast, from) \
    ({ cast val; memcpy(&val, (char*)from, 4); _agpack_be32(val); })
#define _agpack_load64(cast, from) \
    ({ cast val; memcpy(&val, (char*)from, 8); _agpack_be64(val); })
*/


#if !defined(__cplusplus) && defined(_MSC_VER)
#  if !defined(_KERNEL_MODE)
#    if !defined(FALSE)
#      define FALSE (0)
#    endif
#    if !defined(TRUE)
#      define TRUE (!FALSE)
#    endif
#  endif
#  if _MSC_VER >= 1800
#    include <stdbool.h>
#  else
#    define bool int
#    define true TRUE
#    define false FALSE
#  endif
#  define inline __inline
#endif

#ifdef __APPLE__
#  include <TargetConditionals.h>
#endif

#endif /* agpack/sysdep.h */
