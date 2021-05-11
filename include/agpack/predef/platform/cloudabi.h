/*
  Copyright 2017 James E. King, III
  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_PLAT_CLOUDABI_H
#define AGPACK_PREDEF_PLAT_CLOUDABI_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_PLAT_CLOUDABI`]

[@https://github.com/NuxiNL/cloudabi CloudABI] platform.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__CloudABI__`] [__predef_detection__]]
    ]
 */

#define AGPACK_PLAT_CLOUDABI AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__CloudABI__)
#   undef AGPACK_PLAT_CLOUDABI
#   define AGPACK_PLAT_CLOUDABI AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_PLAT_CLOUDABI
#   define AGPACK_PLAT_CLOUDABI_AVAILABLE
#   include <agpack/predef/detail/platform_detected.h>
#endif

#define AGPACK_PLAT_CLOUDABI_NAME "CloudABI"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_CLOUDABI,AGPACK_PLAT_CLOUDABI_NAME)