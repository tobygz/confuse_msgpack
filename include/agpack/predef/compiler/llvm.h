/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_LLVM_H
#define AGPACK_PREDEF_COMPILER_LLVM_H

/* Other compilers that emulate this one need to be detected first. */

#include <agpack/predef/compiler/clang.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_LLVM`]

[@http://en.wikipedia.org/wiki/LLVM LLVM] compiler.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__llvm__`] [__predef_detection__]]
    ]
 */

#define AGPACK_COMP_LLVM AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__llvm__)
#   define AGPACK_COMP_LLVM_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#ifdef AGPACK_COMP_LLVM_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_LLVM_EMULATED AGPACK_COMP_LLVM_DETECTION
#   else
#       undef AGPACK_COMP_LLVM
#       define AGPACK_COMP_LLVM AGPACK_COMP_LLVM_DETECTION
#   endif
#   define AGPACK_COMP_LLVM_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_LLVM_NAME "LLVM"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_LLVM,AGPACK_COMP_LLVM_NAME)

#ifdef AGPACK_COMP_LLVM_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_LLVM_EMULATED,AGPACK_COMP_LLVM_NAME)
#endif
