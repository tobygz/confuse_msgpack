/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_EDG_H
#define AGPACK_PREDEF_COMPILER_EDG_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_EDG`]

[@http://en.wikipedia.org/wiki/Edison_Design_Group EDG C++ Frontend] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__EDG__`] [__predef_detection__]]

    [[`__EDG_VERSION__`] [V.R.0]]
    ]
 */

#define AGPACK_COMP_EDG AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__EDG__)
#   define AGPACK_COMP_EDG_DETECTION AGPACK_PREDEF_MAKE_10_VRR(__EDG_VERSION__)
#endif

#ifdef AGPACK_COMP_EDG_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_EDG_EMULATED AGPACK_COMP_EDG_DETECTION
#   else
#       undef AGPACK_COMP_EDG
#       define AGPACK_COMP_EDG AGPACK_COMP_EDG_DETECTION
#   endif
#   define AGPACK_COMP_EDG_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_EDG_NAME "EDG C++ Frontend"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_EDG,AGPACK_COMP_EDG_NAME)

#ifdef AGPACK_COMP_EDG_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_EDG_EMULATED,AGPACK_COMP_EDG_NAME)
#endif
