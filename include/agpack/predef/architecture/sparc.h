/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_SPARC_H
#define AGPACK_PREDEF_ARCHITECTURE_SPARC_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_SPARC`]

[@http://en.wikipedia.org/wiki/SPARC SPARC] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__sparc__`] [__predef_detection__]]
    [[`__sparc`] [__predef_detection__]]

    [[`__sparcv9`] [9.0.0]]
    [[`__sparcv8`] [8.0.0]]
    ]
 */

#define AGPACK_ARCH_SPARC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__sparc__) || defined(__sparc)
#   undef AGPACK_ARCH_SPARC
#   if !defined(AGPACK_ARCH_SPARC) && defined(__sparcv9)
#       define AGPACK_ARCH_SPARC AGPACK_VERSION_NUMBER(9,0,0)
#   endif
#   if !defined(AGPACK_ARCH_SPARC) && defined(__sparcv8)
#       define AGPACK_ARCH_SPARC AGPACK_VERSION_NUMBER(8,0,0)
#   endif
#   if !defined(AGPACK_ARCH_SPARC)
#       define AGPACK_ARCH_SPARC AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_ARCH_SPARC
#   define AGPACK_ARCH_SPARC_AVAILABLE
#endif

#define AGPACK_ARCH_SPARC_NAME "SPARC"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_SPARC,AGPACK_ARCH_SPARC_NAME)
