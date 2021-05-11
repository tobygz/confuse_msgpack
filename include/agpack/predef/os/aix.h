/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_AIX_H
#define AGPACK_PREDEF_OS_AIX_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_OS_AIX`]

[@http://en.wikipedia.org/wiki/AIX_operating_system IBM AIX] operating system.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_AIX`] [__predef_detection__]]
    [[`__TOS_AIX__`] [__predef_detection__]]

    [[`_AIX43`] [4.3.0]]
    [[`_AIX41`] [4.1.0]]
    [[`_AIX32`] [3.2.0]]
    [[`_AIX3`] [3.0.0]]
    ]
 */

#define AGPACK_OS_AIX AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(_AIX) || defined(__TOS_AIX__) \
    )
#   undef AGPACK_OS_AIX
#   if !defined(AGPACK_OS_AIX) && defined(_AIX43)
#       define AGPACK_OS_AIX AGPACK_VERSION_NUMBER(4,3,0)
#   endif
#   if !defined(AGPACK_OS_AIX) && defined(_AIX41)
#       define AGPACK_OS_AIX AGPACK_VERSION_NUMBER(4,1,0)
#   endif
#   if !defined(AGPACK_OS_AIX) && defined(_AIX32)
#       define AGPACK_OS_AIX AGPACK_VERSION_NUMBER(3,2,0)
#   endif
#   if !defined(AGPACK_OS_AIX) && defined(_AIX3)
#       define AGPACK_OS_AIX AGPACK_VERSION_NUMBER(3,0,0)
#   endif
#   if !defined(AGPACK_OS_AIX)
#       define AGPACK_OS_AIX AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_OS_AIX
#   define AGPACK_OS_AIX_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_AIX_NAME "IBM AIX"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_AIX,AGPACK_OS_AIX_NAME)
