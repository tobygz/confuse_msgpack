/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_STD_LIBCOMO_H
#define AGPACK_PREDEF_LIBRARY_STD_LIBCOMO_H

#include <agpack/predef/library/std/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_STD_COMO`]

[@http://www.comeaucomputing.com/libcomo/ Comeau Computing] Standard C++ Library.
Version number available as major.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__LIBCOMO__`] [__predef_detection__]]

    [[`__LIBCOMO_VERSION__`] [V.0.0]]
    ]
 */

#define AGPACK_LIB_STD_COMO AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__LIBCOMO__)
#   undef AGPACK_LIB_STD_COMO
#   define AGPACK_LIB_STD_COMO AGPACK_VERSION_NUMBER(__LIBCOMO_VERSION__,0,0)
#endif

#if AGPACK_LIB_STD_COMO
#   define AGPACK_LIB_STD_COMO_AVAILABLE
#endif

#define AGPACK_LIB_STD_COMO_NAME "Comeau Computing"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_STD_COMO,AGPACK_LIB_STD_COMO_NAME)
