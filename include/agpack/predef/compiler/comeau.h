/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_COMEAU_H
#define AGPACK_PREDEF_COMPILER_COMEAU_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

#define AGPACK_COMP_COMO AGPACK_VERSION_NUMBER_NOT_AVAILABLE

/*`
[heading `AGPACK_COMP_COMO`]

[@http://en.wikipedia.org/wiki/Comeau_C/C%2B%2B Comeau C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__COMO__`] [__predef_detection__]]

    [[`__COMO_VERSION__`] [V.R.P]]
    ]
 */

#if defined(__COMO__)
#   if !defined(AGPACK_COMP_COMO_DETECTION) && defined(__COMO_VERSION__)
#       define AGPACK_COMP_COMO_DETECTION AGPACK_PREDEF_MAKE_0X_VRP(__COMO_VERSION__)
#   endif
#   if !defined(AGPACK_COMP_COMO_DETECTION)
#       define AGPACK_COMP_COMO_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_COMP_COMO_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_COMO_EMULATED AGPACK_COMP_COMO_DETECTION
#   else
#       undef AGPACK_COMP_COMO
#       define AGPACK_COMP_COMO AGPACK_COMP_COMO_DETECTION
#   endif
#   define AGPACK_COMP_COMO_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_COMO_NAME "Comeau C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_COMO,AGPACK_COMP_COMO_NAME)

#ifdef AGPACK_COMP_COMO_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_COMO_EMULATED,AGPACK_COMP_COMO_NAME)
#endif
