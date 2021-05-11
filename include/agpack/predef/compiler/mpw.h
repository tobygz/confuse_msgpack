/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_MPW_H
#define AGPACK_PREDEF_COMPILER_MPW_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_MPW`]

[@http://en.wikipedia.org/wiki/Macintosh_Programmer%27s_Workshop MPW C++] compiler.
Version number available as major, and minor.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MRC__`] [__predef_detection__]]
    [[`MPW_C`] [__predef_detection__]]
    [[`MPW_CPLUS`] [__predef_detection__]]

    [[`__MRC__`] [V.R.0]]
    ]
 */

#define AGPACK_COMP_MPW AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#   if !defined(AGPACK_COMP_MPW_DETECTION) && defined(__MRC__)
#       define AGPACK_COMP_MPW_DETECTION AGPACK_PREDEF_MAKE_0X_VVRR(__MRC__)
#   endif
#   if !defined(AGPACK_COMP_MPW_DETECTION)
#       define AGPACK_COMP_MPW_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_COMP_MPW_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_MPW_EMULATED AGPACK_COMP_MPW_DETECTION
#   else
#       undef AGPACK_COMP_MPW
#       define AGPACK_COMP_MPW AGPACK_COMP_MPW_DETECTION
#   endif
#   define AGPACK_COMP_MPW_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_MPW_NAME "MPW C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_MPW,AGPACK_COMP_MPW_NAME)

#ifdef AGPACK_COMP_MPW_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_MPW_EMULATED,AGPACK_COMP_MPW_NAME)
#endif
