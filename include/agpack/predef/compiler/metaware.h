/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_METAWARE_H
#define AGPACK_PREDEF_COMPILER_METAWARE_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_HIGHC`]

MetaWare High C/C++ compiler.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__HIGHC__`] [__predef_detection__]]
    ]
 */

#define AGPACK_COMP_HIGHC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__HIGHC__)
#   define AGPACK_COMP_HIGHC_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#ifdef AGPACK_COMP_HIGHC_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_HIGHC_EMULATED AGPACK_COMP_HIGHC_DETECTION
#   else
#       undef AGPACK_COMP_HIGHC
#       define AGPACK_COMP_HIGHC AGPACK_COMP_HIGHC_DETECTION
#   endif
#   define AGPACK_COMP_HIGHC_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_HIGHC_NAME "MetaWare High C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_HIGHC,AGPACK_COMP_HIGHC_NAME)

#ifdef AGPACK_COMP_HIGHC_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_HIGHC_EMULATED,AGPACK_COMP_HIGHC_NAME)
#endif
