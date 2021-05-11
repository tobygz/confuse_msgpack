/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_GCC_H
#define AGPACK_PREDEF_COMPILER_GCC_H

/* Other compilers that emulate this one need to be detected first. */

#include <agpack/predef/compiler/clang.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_GNUC`]

[@http://en.wikipedia.org/wiki/GNU_Compiler_Collection Gnu GCC C/C++] compiler.
Version number available as major, minor, and patch (if available).

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__GNUC__`] [__predef_detection__]]

    [[`__GNUC__`, `__GNUC_MINOR__`, `__GNUC_PATCHLEVEL__`] [V.R.P]]
    [[`__GNUC__`, `__GNUC_MINOR__`] [V.R.0]]
    ]
 */

#define AGPACK_COMP_GNUC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__GNUC__)
#   if !defined(AGPACK_COMP_GNUC_DETECTION) && defined(__GNUC_PATCHLEVEL__)
#       define AGPACK_COMP_GNUC_DETECTION \
            AGPACK_VERSION_NUMBER(__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__)
#   endif
#   if !defined(AGPACK_COMP_GNUC_DETECTION)
#       define AGPACK_COMP_GNUC_DETECTION \
            AGPACK_VERSION_NUMBER(__GNUC__,__GNUC_MINOR__,0)
#   endif
#endif

#ifdef AGPACK_COMP_GNUC_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_GNUC_EMULATED AGPACK_COMP_GNUC_DETECTION
#   else
#       undef AGPACK_COMP_GNUC
#       define AGPACK_COMP_GNUC AGPACK_COMP_GNUC_DETECTION
#   endif
#   define AGPACK_COMP_GNUC_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_GNUC_NAME "Gnu GCC C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_GNUC,AGPACK_COMP_GNUC_NAME)

#ifdef AGPACK_COMP_GNUC_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_GNUC_EMULATED,AGPACK_COMP_GNUC_NAME)
#endif
