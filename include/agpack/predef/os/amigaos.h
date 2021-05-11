/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_AMIGAOS_H
#define AGPACK_PREDEF_OS_AMIGAOS_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_OS_AMIGAOS`]

[@http://en.wikipedia.org/wiki/AmigaOS AmigaOS] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`AMIGA`] [__predef_detection__]]
    [[`__amigaos__`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_AMIGAOS AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(AMIGA) || defined(__amigaos__) \
    )
#   undef AGPACK_OS_AMIGAOS
#   define AGPACK_OS_AMIGAOS AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_OS_AMIGAOS
#   define AGPACK_OS_AMIGAOS_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_AMIGAOS_NAME "AmigaOS"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_AMIGAOS,AGPACK_OS_AMIGAOS_NAME)
