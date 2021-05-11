/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_OS400_H
#define AGPACK_PREDEF_OS_OS400_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_OS_OS400`]

[@http://en.wikipedia.org/wiki/IBM_i IBM OS/400] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__OS400__`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_OS400 AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__OS400__) \
    )
#   undef AGPACK_OS_OS400
#   define AGPACK_OS_OS400 AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_OS_OS400
#   define AGPACK_OS_OS400_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_OS400_NAME "IBM OS/400"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_OS400,AGPACK_OS_OS400_NAME)
