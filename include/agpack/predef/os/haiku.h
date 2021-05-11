/*
Copyright Jessica Hamilton 2014
Copyright Rene Rivera 2014-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_HAIKU_H
#define AGPACK_PREDEF_OS_HAIKU_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_OS_HAIKU`]

[@http://en.wikipedia.org/wiki/Haiku_(operating_system) Haiku] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__HAIKU__`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_HAIKU AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__HAIKU__) \
    )
#   undef AGPACK_OS_HAIKU
#   define AGPACK_OS_HAIKU AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_OS_HAIKU
#   define AGPACK_OS_HAIKU_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_HAIKU_NAME "Haiku"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_HAIKU,AGPACK_OS_HAIKU_NAME)
