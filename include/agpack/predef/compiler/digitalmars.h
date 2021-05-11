/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_DIGITALMARS_H
#define AGPACK_PREDEF_COMPILER_DIGITALMARS_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_DMC`]

[@http://en.wikipedia.org/wiki/Digital_Mars Digital Mars] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__DMC__`] [__predef_detection__]]

    [[`__DMC__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_DMC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DMC__)
#   define AGPACK_COMP_DMC_DETECTION AGPACK_PREDEF_MAKE_0X_VRP(__DMC__)
#endif

#ifdef AGPACK_COMP_DMC_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_DMC_EMULATED AGPACK_COMP_DMC_DETECTION
#   else
#       undef AGPACK_COMP_DMC
#       define AGPACK_COMP_DMC AGPACK_COMP_DMC_DETECTION
#   endif
#   define AGPACK_COMP_DMC_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_DMC_NAME "Digital Mars"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_DMC,AGPACK_COMP_DMC_NAME)

#ifdef AGPACK_COMP_DMC_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_DMC_EMULATED,AGPACK_COMP_DMC_NAME)
#endif
