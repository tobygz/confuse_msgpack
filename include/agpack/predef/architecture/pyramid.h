/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_PYRAMID_H
#define AGPACK_PREDEF_ARCHITECTURE_PYRAMID_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_PYRAMID`]

Pyramid 9810 architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`pyr`] [__predef_detection__]]
    ]
 */

#define AGPACK_ARCH_PYRAMID AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(pyr)
#   undef AGPACK_ARCH_PYRAMID
#   define AGPACK_ARCH_PYRAMID AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_ARCH_PYRAMID
#   define AGPACK_ARCH_PYRAMID_AVAILABLE
#endif

#define AGPACK_ARCH_PYRAMID_NAME "Pyramid 9810"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_PYRAMID,AGPACK_ARCH_PYRAMID_NAME)
