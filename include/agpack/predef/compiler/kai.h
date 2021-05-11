/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_KAI_H
#define AGPACK_PREDEF_COMPILER_KAI_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_KCC`]

Kai C++ compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__KCC`] [__predef_detection__]]

    [[`__KCC_VERSION`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_KCC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__KCC)
#   define AGPACK_COMP_KCC_DETECTION AGPACK_PREDEF_MAKE_0X_VRPP(__KCC_VERSION)
#endif

#ifdef AGPACK_COMP_KCC_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_KCC_EMULATED AGPACK_COMP_KCC_DETECTION
#   else
#       undef AGPACK_COMP_KCC
#       define AGPACK_COMP_KCC AGPACK_COMP_KCC_DETECTION
#   endif
#   define AGPACK_COMP_KCC_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_KCC_NAME "Kai C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_KCC,AGPACK_COMP_KCC_NAME)

#ifdef AGPACK_COMP_KCC_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_KCC_EMULATED,AGPACK_COMP_KCC_NAME)
#endif
