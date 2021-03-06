/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_SYS390_H
#define AGPACK_PREDEF_ARCHITECTURE_SYS390_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_SYS390`]

[@http://en.wikipedia.org/wiki/System/390 System/390] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__s390__`] [__predef_detection__]]
    [[`__s390x__`] [__predef_detection__]]
    ]
 */

#define AGPACK_ARCH_SYS390 AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__s390__) || defined(__s390x__)
#   undef AGPACK_ARCH_SYS390
#   define AGPACK_ARCH_SYS390 AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_ARCH_SYS390
#   define AGPACK_ARCH_SYS390_AVAILABLE
#endif

#define AGPACK_ARCH_SYS390_NAME "System/390"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_SYS390,AGPACK_ARCH_SYS390_NAME)
