/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_WINDOWS_H
#define AGPACK_PREDEF_OS_WINDOWS_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_OS_WINDOWS`]

[@http://en.wikipedia.org/wiki/Category:Microsoft_Windows Microsoft Windows] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_WIN32`] [__predef_detection__]]
    [[`_WIN64`] [__predef_detection__]]
    [[`__WIN32__`] [__predef_detection__]]
    [[`__TOS_WIN__`] [__predef_detection__]]
    [[`__WINDOWS__`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_WINDOWS AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__TOS_WIN__) || \
    defined(__WINDOWS__) \
    )
#   undef AGPACK_OS_WINDOWS
#   define AGPACK_OS_WINDOWS AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_OS_WINDOWS
#   define AGPACK_OS_WINDOWS_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_WINDOWS_NAME "Microsoft Windows"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_WINDOWS,AGPACK_OS_WINDOWS_NAME)
