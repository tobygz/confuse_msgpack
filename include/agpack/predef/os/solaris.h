/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_SOLARIS_H
#define AGPACK_PREDEF_OS_SOLARIS_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_OS_SOLARIS`]

[@http://en.wikipedia.org/wiki/Solaris_Operating_Environment Solaris] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`sun`] [__predef_detection__]]
    [[`__sun`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_SOLARIS AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(sun) || defined(__sun) \
    )
#   undef AGPACK_OS_SOLARIS
#   define AGPACK_OS_SOLARIS AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_OS_SOLARIS
#   define AGPACK_OS_SOLARIS_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_SOLARIS_NAME "Solaris"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_SOLARIS,AGPACK_OS_SOLARIS_NAME)
