/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_STD_ROGUEWAVE_H
#define AGPACK_PREDEF_LIBRARY_STD_ROGUEWAVE_H

#include <agpack/predef/library/std/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_STD_RW`]

[@http://stdcxx.apache.org/ Roguewave] Standard C++ library.
If available version number as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__STD_RWCOMPILER_H__`] [__predef_detection__]]
    [[`_RWSTD_VER`] [__predef_detection__]]

    [[`_RWSTD_VER`] [V.R.P]]
    ]
 */

#define AGPACK_LIB_STD_RW AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)
#   undef AGPACK_LIB_STD_RW
#   if defined(_RWSTD_VER)
#       if _RWSTD_VER < 0x010000
#           define AGPACK_LIB_STD_RW AGPACK_PREDEF_MAKE_0X_VVRRP(_RWSTD_VER)
#       else
#           define AGPACK_LIB_STD_RW AGPACK_PREDEF_MAKE_0X_VVRRPP(_RWSTD_VER)
#       endif
#   else
#       define AGPACK_LIB_STD_RW AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_LIB_STD_RW
#   define AGPACK_LIB_STD_RW_AVAILABLE
#endif

#define AGPACK_LIB_STD_RW_NAME "Roguewave"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_STD_RW,AGPACK_LIB_STD_RW_NAME)
