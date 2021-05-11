/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_STD_MSL_H
#define AGPACK_PREDEF_LIBRARY_STD_MSL_H

#include <agpack/predef/library/std/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_STD_MSL`]

[@http://www.freescale.com/ Metrowerks] Standard C++ Library.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MSL_CPP__`] [__predef_detection__]]
    [[`__MSL__`] [__predef_detection__]]

    [[`__MSL_CPP__`] [V.R.P]]
    [[`__MSL__`] [V.R.P]]
    ]
 */

#define AGPACK_LIB_STD_MSL AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MSL_CPP__) || defined(__MSL__)
#   undef AGPACK_LIB_STD_MSL
#   if defined(__MSL_CPP__)
#       define AGPACK_LIB_STD_MSL AGPACK_PREDEF_MAKE_0X_VRPP(__MSL_CPP__)
#   else
#       define AGPACK_LIB_STD_MSL AGPACK_PREDEF_MAKE_0X_VRPP(__MSL__)
#   endif
#endif

#if AGPACK_LIB_STD_MSL
#   define AGPACK_LIB_STD_MSL_AVAILABLE
#endif

#define AGPACK_LIB_STD_MSL_NAME "Metrowerks"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_STD_MSL,AGPACK_LIB_STD_MSL_NAME)
