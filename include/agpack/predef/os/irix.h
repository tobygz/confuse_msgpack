/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_IRIX_H
#define AGPACK_PREDEF_OS_IRIX_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_OS_IRIX`]

[@http://en.wikipedia.org/wiki/Irix IRIX] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`sgi`] [__predef_detection__]]
    [[`__sgi`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_IRIX AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(sgi) || defined(__sgi) \
    )
#   undef AGPACK_OS_IRIX
#   define AGPACK_OS_IRIX AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_OS_IRIX
#   define AGPACK_OS_IRIX_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_IRIX_NAME "IRIX"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_IRIX,AGPACK_OS_IRIX_NAME)
