/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_X86_64_H
#define AGPACK_PREDEF_ARCHITECTURE_X86_64_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_X86_64`]

[@http://en.wikipedia.org/wiki/Ia64 Intel IA-64] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__x86_64`] [__predef_detection__]]
    [[`__x86_64__`] [__predef_detection__]]
    [[`__amd64__`] [__predef_detection__]]
    [[`__amd64`] [__predef_detection__]]
    [[`_M_X64`] [__predef_detection__]]
    ]
 */

#define AGPACK_ARCH_X86_64 AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__x86_64) || defined(__x86_64__) || \
    defined(__amd64__) || defined(__amd64) || \
    defined(_M_X64)
#   undef AGPACK_ARCH_X86_64
#   define AGPACK_ARCH_X86_64 AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_ARCH_X86_64
#   define AGPACK_ARCH_X86_64_AVAILABLE
#endif

#define AGPACK_ARCH_X86_64_NAME "Intel x86-64"

#include <agpack/predef/architecture/x86.h>

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_X86_64,AGPACK_ARCH_X86_64_NAME)
