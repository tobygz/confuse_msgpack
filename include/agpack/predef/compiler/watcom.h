/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_WATCOM_H
#define AGPACK_PREDEF_COMPILER_WATCOM_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_WATCOM`]

[@http://en.wikipedia.org/wiki/Watcom Watcom C++] compiler.
Version number available as major, and minor.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__WATCOMC__`] [__predef_detection__]]

    [[`__WATCOMC__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_WATCOM AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__WATCOMC__)
#   define AGPACK_COMP_WATCOM_DETECTION AGPACK_PREDEF_MAKE_10_VVRR(__WATCOMC__)
#endif

#ifdef AGPACK_COMP_WATCOM_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_WATCOM_EMULATED AGPACK_COMP_WATCOM_DETECTION
#   else
#       undef AGPACK_COMP_WATCOM
#       define AGPACK_COMP_WATCOM AGPACK_COMP_WATCOM_DETECTION
#   endif
#   define AGPACK_COMP_WATCOM_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_WATCOM_NAME "Watcom C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_WATCOM,AGPACK_COMP_WATCOM_NAME)

#ifdef AGPACK_COMP_WATCOM_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_WATCOM_EMULATED,AGPACK_COMP_WATCOM_NAME)
#endif
