/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_RS6K_H
#define AGPACK_PREDEF_ARCHITECTURE_RS6K_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_RS6000`]

[@http://en.wikipedia.org/wiki/RS/6000 RS/6000] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__THW_RS6000`] [__predef_detection__]]
    [[`_IBMR2`] [__predef_detection__]]
    [[`_POWER`] [__predef_detection__]]
    [[`_ARCH_PWR`] [__predef_detection__]]
    [[`_ARCH_PWR2`] [__predef_detection__]]
    ]
 */

#define AGPACK_ARCH_RS6000 AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__THW_RS6000) || defined(_IBMR2) || \
    defined(_POWER) || defined(_ARCH_PWR) || \
    defined(_ARCH_PWR2)
#   undef AGPACK_ARCH_RS6000
#   define AGPACK_ARCH_RS6000 AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_ARCH_RS6000
#   define AGPACK_ARCH_RS6000_AVAILABLE
#endif

#define AGPACK_ARCH_RS6000_NAME "RS/6000"

#define AGPACK_ARCH_PWR AGPACK_ARCH_RS6000

#if AGPACK_ARCH_PWR
#   define AGPACK_ARCH_PWR_AVAILABLE
#endif

#define AGPACK_ARCH_PWR_NAME AGPACK_ARCH_RS6000_NAME

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_RS6000,AGPACK_ARCH_RS6000_NAME)
