/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LIBRARY_C_UC_H
#define AGPACK_PREDEF_LIBRARY_C_UC_H

#include <agpack/predef/library/c/_prefix.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LIB_C_UC`]

[@http://en.wikipedia.org/wiki/Uclibc uClibc] Standard C library.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__UCLIBC__`] [__predef_detection__]]

    [[`__UCLIBC_MAJOR__`, `__UCLIBC_MINOR__`, `__UCLIBC_SUBLEVEL__`] [V.R.P]]
    ]
 */

#define AGPACK_LIB_C_UC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__UCLIBC__)
#   undef AGPACK_LIB_C_UC
#   define AGPACK_LIB_C_UC AGPACK_VERSION_NUMBER(\
        __UCLIBC_MAJOR__,__UCLIBC_MINOR__,__UCLIBC_SUBLEVEL__)
#endif

#if AGPACK_LIB_C_UC
#   define AGPACK_LIB_C_UC_AVAILABLE
#endif

#define AGPACK_LIB_C_UC_NAME "uClibc"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_C_UC,AGPACK_LIB_C_UC_NAME)
