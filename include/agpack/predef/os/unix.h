/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_UNIX_H
#define AGPACK_PREDEF_OS_UNIX_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_OS_UNIX`]

[@http://en.wikipedia.org/wiki/Unix Unix Environment] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`unix`] [__predef_detection__]]
    [[`__unix`] [__predef_detection__]]
    [[`_XOPEN_SOURCE`] [__predef_detection__]]
    [[`_POSIX_SOURCE`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_UNIX AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(unix) || defined(__unix) || \
    defined(_XOPEN_SOURCE) || defined(_POSIX_SOURCE)
#   undef AGPACK_OS_UNIX
#   define AGPACK_OS_UNIX AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_OS_UNIX
#   define AGPACK_OS_UNIX_AVAILABLE
#endif

#define AGPACK_OS_UNIX_NAME "Unix Environment"

/*`
[heading `AGPACK_OS_SVR4`]

[@http://en.wikipedia.org/wiki/UNIX_System_V SVR4 Environment] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__sysv__`] [__predef_detection__]]
    [[`__SVR4`] [__predef_detection__]]
    [[`__svr4__`] [__predef_detection__]]
    [[`_SYSTYPE_SVR4`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_SVR4 AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__sysv__) || defined(__SVR4) || \
    defined(__svr4__) || defined(_SYSTYPE_SVR4)
#   undef AGPACK_OS_SVR4
#   define AGPACK_OS_SVR4 AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_OS_SVR4
#   define AGPACK_OS_SVR4_AVAILABLE
#endif

#define AGPACK_OS_SVR4_NAME "SVR4 Environment"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_UNIX,AGPACK_OS_UNIX_NAME)
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_SVR4,AGPACK_OS_SVR4_NAME)
