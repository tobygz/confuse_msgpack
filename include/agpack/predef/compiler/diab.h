/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_DIAB_H
#define AGPACK_PREDEF_COMPILER_DIAB_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_DIAB`]

[@http://www.windriver.com/products/development_suite/wind_river_compiler/ Diab C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__DCC__`] [__predef_detection__]]

    [[`__VERSION_NUMBER__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_DIAB AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DCC__)
#   define AGPACK_COMP_DIAB_DETECTION AGPACK_PREDEF_MAKE_10_VRPP(__VERSION_NUMBER__)
#endif

#ifdef AGPACK_COMP_DIAB_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_DIAB_EMULATED AGPACK_COMP_DIAB_DETECTION
#   else
#       undef AGPACK_COMP_DIAB
#       define AGPACK_COMP_DIAB AGPACK_COMP_DIAB_DETECTION
#   endif
#   define AGPACK_COMP_DIAB_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_DIAB_NAME "Diab C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_DIAB,AGPACK_COMP_DIAB_NAME)

#ifdef AGPACK_COMP_DIAB_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_DIAB_EMULATED,AGPACK_COMP_DIAB_NAME)
#endif
