/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_SYS370_H
#define AGPACK_PREDEF_ARCHITECTURE_SYS370_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_SYS370`]

[@http://en.wikipedia.org/wiki/System/370 System/370] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__370__`] [__predef_detection__]]
    [[`__THW_370__`] [__predef_detection__]]
    ]
 */

#define AGPACK_ARCH_SYS370 AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__370__) || defined(__THW_370__)
#   undef AGPACK_ARCH_SYS370
#   define AGPACK_ARCH_SYS370 AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_ARCH_SYS370
#   define AGPACK_ARCH_SYS370_AVAILABLE
#endif

#define AGPACK_ARCH_SYS370_NAME "System/370"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_SYS370,AGPACK_ARCH_SYS370_NAME)
