/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_IAR_H
#define AGPACK_PREDEF_COMPILER_IAR_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_IAR`]

IAR C/C++ compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__IAR_SYSTEMS_ICC__`] [__predef_detection__]]

    [[`__VER__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_IAR AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__IAR_SYSTEMS_ICC__)
#   define AGPACK_COMP_IAR_DETECTION AGPACK_PREDEF_MAKE_10_VVRR(__VER__)
#endif

#ifdef AGPACK_COMP_IAR_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_IAR_EMULATED AGPACK_COMP_IAR_DETECTION
#   else
#       undef AGPACK_COMP_IAR
#       define AGPACK_COMP_IAR AGPACK_COMP_IAR_DETECTION
#   endif
#   define AGPACK_COMP_IAR_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_IAR_NAME "IAR C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_IAR,AGPACK_COMP_IAR_NAME)

#ifdef AGPACK_COMP_IAR_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_IAR_EMULATED,AGPACK_COMP_IAR_NAME)
#endif
