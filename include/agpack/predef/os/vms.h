/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_VMS_H
#define AGPACK_PREDEF_OS_VMS_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_OS_VMS`]

[@http://en.wikipedia.org/wiki/Vms VMS] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`VMS`] [__predef_detection__]]
    [[`__VMS`] [__predef_detection__]]

    [[`__VMS_VER`] [V.R.P]]
    ]
 */

#define AGPACK_OS_VMS AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(VMS) || defined(__VMS) \
    )
#   undef AGPACK_OS_VMS
#   if defined(__VMS_VER)
#       define AGPACK_OS_VMS AGPACK_PREDEF_MAKE_10_VVRR00PP00(__VMS_VER)
#   else
#       define AGPACK_OS_VMS AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_OS_VMS
#   define AGPACK_OS_VMS_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_VMS_NAME "VMS"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_VMS,AGPACK_OS_VMS_NAME)
