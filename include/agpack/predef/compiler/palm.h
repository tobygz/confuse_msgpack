/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_PALM_H
#define AGPACK_PREDEF_COMPILER_PALM_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_PALM`]

Palm C/C++ compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_PACC_VER`] [__predef_detection__]]

    [[`_PACC_VER`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_PALM AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_PACC_VER)
#   define AGPACK_COMP_PALM_DETECTION AGPACK_PREDEF_MAKE_0X_VRRPP000(_PACC_VER)
#endif

#ifdef AGPACK_COMP_PALM_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_PALM_EMULATED AGPACK_COMP_PALM_DETECTION
#   else
#       undef AGPACK_COMP_PALM
#       define AGPACK_COMP_PALM AGPACK_COMP_PALM_DETECTION
#   endif
#   define AGPACK_COMP_PALM_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_PALM_NAME "Palm C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_PALM,AGPACK_COMP_PALM_NAME)

#ifdef AGPACK_COMP_PALM_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_PALM_EMULATED,AGPACK_COMP_PALM_NAME)
#endif
