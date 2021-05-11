/*
 * Copyright (C) 2017 James E. King III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef AGPACK_PREDEF_LIBRARY_C_CLOUDABI_H
#define AGPACK_PREDEF_LIBRARY_C_CLOUDABI_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

#include <agpack/predef/library/c/_prefix.h>

#if defined(__CloudABI__)
#include <stddef.h>
#endif

/*`
[heading `AGPACK_LIB_C_CLOUDABI`]

[@https://github.com/NuxiNL/cloudlibc cloudlibc] - CloudABI's standard C library.
Version number available as major, and minor.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__cloudlibc__`] [__predef_detection__]]

    [[`__cloudlibc_major__`, `__cloudlibc_minor__`] [V.R.0]]
    ]
 */

#define AGPACK_LIB_C_CLOUDABI AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__cloudlibc__)
#   undef AGPACK_LIB_C_CLOUDABI
#   define AGPACK_LIB_C_CLOUDABI \
            AGPACK_VERSION_NUMBER(__cloudlibc_major__,__cloudlibc_minor__,0)
#endif

#if AGPACK_LIB_C_CLOUDABI
#   define AGPACK_LIB_C_CLOUDABI_AVAILABLE
#endif

#define AGPACK_LIB_C_CLOUDABI_NAME "cloudlibc"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LIB_C_CLOUDABI,AGPACK_LIB_C_CLOUDABI_NAME)
