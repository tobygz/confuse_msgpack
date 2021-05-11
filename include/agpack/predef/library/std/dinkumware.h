/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_STD_DINKUMWARE_H
#define AGPACK_PREDEF_LIBRARY_STD_DINKUMWARE_H

#include <agpack/predef/library/std/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_STD_DINKUMWARE`]

[@http://en.wikipedia.org/wiki/Dinkumware Dinkumware] Standard C++ Library.
If available version number as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_YVALS`, `__IBMCPP__`] [__predef_detection__]]
    [[`_CPPLIB_VER`] [__predef_detection__]]

    [[`_CPPLIB_VER`] [V.R.0]]
    ]
 */

#define AGPACK_LIB_STD_DINKUMWARE AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)
#   undef AGPACK_LIB_STD_DINKUMWARE
#   if defined(_CPPLIB_VER)
#       define AGPACK_LIB_STD_DINKUMWARE AGPACK_PREDEF_MAKE_10_VVRR(_CPPLIB_VER)
#   else
#       define AGPACK_LIB_STD_DINKUMWARE AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_LIB_STD_DINKUMWARE
#   define AGPACK_LIB_STD_DINKUMWARE_AVAILABLE
#endif

#define AGPACK_LIB_STD_DINKUMWARE_NAME "Dinkumware"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_STD_DINKUMWARE,AGPACK_LIB_STD_DINKUMWARE_NAME)
