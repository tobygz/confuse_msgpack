/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_IA64_H
#define AGPACK_PREDEF_ARCHITECTURE_IA64_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_IA64`]

[@http://en.wikipedia.org/wiki/Ia64 Intel Itanium 64] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__ia64__`] [__predef_detection__]]
    [[`_IA64`] [__predef_detection__]]
    [[`__IA64__`] [__predef_detection__]]
    [[`__ia64`] [__predef_detection__]]
    [[`_M_IA64`] [__predef_detection__]]
    [[`__itanium__`] [__predef_detection__]]
    ]
 */

#define AGPACK_ARCH_IA64 AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__ia64__) || defined(_IA64) || \
    defined(__IA64__) || defined(__ia64) || \
    defined(_M_IA64) || defined(__itanium__)
#   undef AGPACK_ARCH_IA64
#   define AGPACK_ARCH_IA64 AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_ARCH_IA64
#   define AGPACK_ARCH_IA64_AVAILABLE
#endif

#define AGPACK_ARCH_IA64_NAME "Intel Itanium 64"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_IA64,AGPACK_ARCH_IA64_NAME)
