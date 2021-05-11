/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_STD_CXX_H
#define AGPACK_PREDEF_LIBRARY_STD_CXX_H

#include <agpack/predef/library/std/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_STD_CXX`]

[@http://libcxx.llvm.org/ libc++] C++ Standard Library.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_LIBCPP_VERSION`] [__predef_detection__]]

    [[`_LIBCPP_VERSION`] [V.0.P]]
    ]
 */

#define AGPACK_LIB_STD_CXX AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_LIBCPP_VERSION)
#   undef AGPACK_LIB_STD_CXX
#   define AGPACK_LIB_STD_CXX AGPACK_PREDEF_MAKE_10_VPPP(_LIBCPP_VERSION)
#endif

#if AGPACK_LIB_STD_CXX
#   define AGPACK_LIB_STD_CXX_AVAILABLE
#endif

#define AGPACK_LIB_STD_CXX_NAME "libc++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_STD_CXX,AGPACK_LIB_STD_CXX_NAME)
