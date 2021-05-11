/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_Z_H
#define AGPACK_PREDEF_ARCHITECTURE_Z_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_Z`]

[@http://en.wikipedia.org/wiki/Z/Architecture z/Architecture] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__SYSC_ZARCH__`] [__predef_detection__]]
    ]
 */

#define AGPACK_ARCH_Z AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SYSC_ZARCH__)
#   undef AGPACK_ARCH_Z
#   define AGPACK_ARCH_Z AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_ARCH_Z
#   define AGPACK_ARCH_Z_AVAILABLE
#endif

#define AGPACK_ARCH_Z_NAME "z/Architecture"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_Z,AGPACK_ARCH_Z_NAME)
