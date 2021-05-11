/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_STD_SGI_H
#define AGPACK_PREDEF_LIBRARY_STD_SGI_H

#include <agpack/predef/library/std/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_STD_SGI`]

[@http://www.sgi.com/tech/stl/ SGI] Standard C++ library.
If available version number as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__STL_CONFIG_H`] [__predef_detection__]]

    [[`__SGI_STL`] [V.R.P]]
    ]
 */

#define AGPACK_LIB_STD_SGI AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__STL_CONFIG_H)
#   undef AGPACK_LIB_STD_SGI
#   if defined(__SGI_STL)
#       define AGPACK_LIB_STD_SGI AGPACK_PREDEF_MAKE_0X_VRP(__SGI_STL)
#   else
#       define AGPACK_LIB_STD_SGI AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_LIB_STD_SGI
#   define AGPACK_LIB_STD_SGI_AVAILABLE
#endif

#define AGPACK_LIB_STD_SGI_NAME "SGI"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_STD_SGI,AGPACK_LIB_STD_SGI_NAME)
