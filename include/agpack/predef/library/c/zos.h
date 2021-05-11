/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_C_ZOS_H
#define AGPACK_PREDEF_LIBRARY_C_ZOS_H

#include <agpack/predef/library/c/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_C_ZOS`]

z/OS libc Standard C library.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__LIBREL__`] [__predef_detection__]]

    [[`__LIBREL__`] [V.R.P]]
    [[`__TARGET_LIB__`] [V.R.P]]
    ]
 */

#define AGPACK_LIB_C_ZOS AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__LIBREL__)
#   undef AGPACK_LIB_C_ZOS
#   if !defined(AGPACK_LIB_C_ZOS) && defined(__LIBREL__)
#       define AGPACK_LIB_C_ZOS AGPACK_PREDEF_MAKE_0X_VRRPPPP(__LIBREL__)
#   endif
#   if !defined(AGPACK_LIB_C_ZOS) && defined(__TARGET_LIB__)
#       define AGPACK_LIB_C_ZOS AGPACK_PREDEF_MAKE_0X_VRRPPPP(__TARGET_LIB__)
#   endif
#   if !defined(AGPACK_LIB_C_ZOS)
#       define AGPACK_LIB_C_ZOS AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_LIB_C_ZOS
#   define AGPACK_LIB_C_ZOS_AVAILABLE
#endif

#define AGPACK_LIB_C_ZOS_NAME "z/OS"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_C_ZOS,AGPACK_LIB_C_ZOS_NAME)
