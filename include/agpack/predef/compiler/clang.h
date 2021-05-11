/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_CLANG_H
#define AGPACK_PREDEF_COMPILER_CLANG_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_CLANG`]

[@http://en.wikipedia.org/wiki/Clang Clang] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__clang__`] [__predef_detection__]]

    [[`__clang_major__`, `__clang_minor__`, `__clang_patchlevel__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_CLANG AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__clang__)
#   define AGPACK_COMP_CLANG_DETECTION AGPACK_VERSION_NUMBER(__clang_major__,__clang_minor__,__clang_patchlevel__)
#endif

#ifdef AGPACK_COMP_CLANG_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_CLANG_EMULATED AGPACK_COMP_CLANG_DETECTION
#   else
#       undef AGPACK_COMP_CLANG
#       define AGPACK_COMP_CLANG AGPACK_COMP_CLANG_DETECTION
#   endif
#   define AGPACK_COMP_CLANG_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_CLANG_NAME "Clang"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_CLANG,AGPACK_COMP_CLANG_NAME)

#ifdef AGPACK_COMP_CLANG_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_CLANG_EMULATED,AGPACK_COMP_CLANG_NAME)
#endif
