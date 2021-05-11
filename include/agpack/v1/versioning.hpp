/*
 * MessagePack for C++ version switcher
 *
 * Copyright (C) 2014 KONDO Takatoshi
 *
 *    Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *    http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef AGPACK_VERSIONING_HPP
#define AGPACK_VERSIONING_HPP

#if !defined(AGPACK_DEFAULT_API_VERSION)
#define AGPACK_DEFAULT_API_VERSION 1
#endif

#define AGPACK_DEFAULT_API_NS AGPACK_DETAIL_PP_CAT(v, AGPACK_DEFAULT_API_VERSION)

#if   AGPACK_DEFAULT_API_VERSION == 1
#define AGPACK_DETAIL_PP_ENABLE_NS_v1 ()
//#elif AGPACK_DEFAULT_API_VERSION == 2
//#define AGPACK_DETAIL_PP_ENABLE_NS_v2 ()
#else
#error
#endif

#define AGPACK_DETAIL_PP_CAT(a, ...) AGPACK_DETAIL_PP_PRIMITIVE_CAT(a, __VA_ARGS__)
#define AGPACK_DETAIL_PP_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define AGPACK_DETAIL_PP_IIF(c) AGPACK_DETAIL_PP_PRIMITIVE_CAT(AGPACK_DETAIL_PP_IIF_, c)
#define AGPACK_DETAIL_PP_IIF_0(t, ...) __VA_ARGS__
#define AGPACK_DETAIL_PP_IIF_1(t, ...) t

#define AGPACK_DETAIL_PP_PROBE(x) x, 1

#if defined(_MSC_VER)

#define AGPACK_DETAIL_PP_MSVC_VA_ARGS_WORKAROUND(define, args) define args
#define AGPACK_DETAIL_PP_CHECK(...) AGPACK_DETAIL_PP_MSVC_VA_ARGS_WORKAROUND(AGPACK_DETAIL_PP_CHECK_N, (__VA_ARGS__, 0))
#define AGPACK_DETAIL_PP_CHECK_N(x, n, ...) n

#else  // defined(__MSC_VER)

#define AGPACK_DETAIL_PP_CHECK(...) AGPACK_DETAIL_PP_CHECK_N(__VA_ARGS__, 0)
#define AGPACK_DETAIL_PP_CHECK_N(x, n, ...) n

#endif // defined(__MSC_VER)


#define AGPACK_DETAIL_PP_NS_ENABLED_PROBE(ns)            AGPACK_DETAIL_PP_NS_ENABLED_PROBE_PROXY( AGPACK_DETAIL_PP_ENABLE_NS_##ns )
#define AGPACK_DETAIL_PP_NS_ENABLED_PROBE_PROXY(...)     AGPACK_DETAIL_PP_NS_ENABLED_PROBE_PRIMIVIE(__VA_ARGS__)
#define AGPACK_DETAIL_PP_NS_ENABLED_PROBE_PRIMIVIE(x)    AGPACK_DETAIL_PP_NS_ENABLED_PROBE_COMBINE_ x
#define AGPACK_DETAIL_PP_NS_ENABLED_PROBE_COMBINE_(...)  AGPACK_DETAIL_PP_PROBE(~)

#define AGPACK_DETAIL_PP_IS_NS_ENABLED(ns) AGPACK_DETAIL_PP_CHECK(AGPACK_DETAIL_PP_NS_ENABLED_PROBE(ns))

#if __cplusplus < 201103L
#define AGPACK_API_VERSION_NAMESPACE(ns) AGPACK_DETAIL_PP_IIF(AGPACK_DETAIL_PP_IS_NS_ENABLED(ns)) \
    (namespace ns{}; using namespace ns; namespace ns, \
     namespace ns)

#else  // __cplusplus < 201103L

#define AGPACK_API_VERSION_NAMESPACE(ns) AGPACK_DETAIL_PP_IIF(AGPACK_DETAIL_PP_IS_NS_ENABLED(ns)) \
    (inline namespace ns, namespace ns)

#endif // __cplusplus < 201103L

#endif // AGPACK_VERSIONING_HPP