/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_C_VMS_H
#define AGPACK_PREDEF_LIBRARY_C_VMS_H

#include <agpack/predef/library/c/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_C_VMS`]

VMS libc Standard C library.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__CRTL_VER`] [__predef_detection__]]

    [[`__CRTL_VER`] [V.R.P]]
    ]
 */

#define AGPACK_LIB_C_VMS AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__CRTL_VER)
#   undef AGPACK_LIB_C_VMS
#   define AGPACK_LIB_C_VMS AGPACK_PREDEF_MAKE_10_VVRR0PP00(__CRTL_VER)
#endif

#if AGPACK_LIB_C_VMS
#   define AGPACK_LIB_C_VMS_AVAILABLE
#endif

#define AGPACK_LIB_C_VMS_NAME "VMS"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_C_VMS,AGPACK_LIB_C_VMS_NAME)
