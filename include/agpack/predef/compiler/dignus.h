/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_DIGNUS_H
#define AGPACK_PREDEF_COMPILER_DIGNUS_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_SYSC`]

[@http://www.dignus.com/dcxx/ Dignus Systems/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__SYSC__`] [__predef_detection__]]

    [[`__SYSC_VER__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_SYSC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SYSC__)
#   define AGPACK_COMP_SYSC_DETECTION AGPACK_PREDEF_MAKE_10_VRRPP(__SYSC_VER__)
#endif

#ifdef AGPACK_COMP_SYSC_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_SYSC_EMULATED AGPACK_COMP_SYSC_DETECTION
#   else
#       undef AGPACK_COMP_SYSC
#       define AGPACK_COMP_SYSC AGPACK_COMP_SYSC_DETECTION
#   endif
#   define AGPACK_COMP_SYSC_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_SYSC_NAME "Dignus Systems/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_SYSC,AGPACK_COMP_SYSC_NAME)

#ifdef AGPACK_COMP_SYSC_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_SYSC_EMULATED,AGPACK_COMP_SYSC_NAME)
#endif
