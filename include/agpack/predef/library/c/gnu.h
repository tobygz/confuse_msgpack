/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_C_GNU_H
#define AGPACK_PREDEF_LIBRARY_C_GNU_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

#include <agpack/predef/library/c/_prefix.h>

#if defined(__STDC__)
#include <stddef.h>
#elif defined(__cplusplus)
#include <cstddef>
#endif

/*`
[heading `AGPACK_LIB_C_GNU`]

[@http://en.wikipedia.org/wiki/Glibc GNU glibc] Standard C library.
Version number available as major, and minor.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__GLIBC__`] [__predef_detection__]]
    [[`__GNU_LIBRARY__`] [__predef_detection__]]

    [[`__GLIBC__`, `__GLIBC_MINOR__`] [V.R.0]]
    [[`__GNU_LIBRARY__`, `__GNU_LIBRARY_MINOR__`] [V.R.0]]
    ]
 */

#define AGPACK_LIB_C_GNU AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__GLIBC__) || defined(__GNU_LIBRARY__)
#   undef AGPACK_LIB_C_GNU
#   if defined(__GLIBC__)
#       define AGPACK_LIB_C_GNU \
            AGPACK_VERSION_NUMBER(__GLIBC__,__GLIBC_MINOR__,0)
#   else
#       define AGPACK_LIB_C_GNU \
            AGPACK_VERSION_NUMBER(__GNU_LIBRARY__,__GNU_LIBRARY_MINOR__,0)
#   endif
#endif

#if AGPACK_LIB_C_GNU
#   define AGPACK_LIB_C_GNU_AVAILABLE
#endif

#define AGPACK_LIB_C_GNU_NAME "GNU"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_C_GNU,AGPACK_LIB_C_GNU_NAME)
