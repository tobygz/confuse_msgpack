/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_BORLAND_H
#define AGPACK_PREDEF_COMPILER_BORLAND_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_BORLAND`]

[@http://en.wikipedia.org/wiki/C_plus_plus_builder Borland C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__BORLANDC__`] [__predef_detection__]]
    [[`__CODEGEARC__`] [__predef_detection__]]

    [[`__BORLANDC__`] [V.R.P]]
    [[`__CODEGEARC__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_BORLAND AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__BORLANDC__) || defined(__CODEGEARC__)
#   if !defined(AGPACK_COMP_BORLAND_DETECTION) && (defined(__CODEGEARC__))
#       define AGPACK_COMP_BORLAND_DETECTION AGPACK_PREDEF_MAKE_0X_VVRP(__CODEGEARC__)
#   endif
#   if !defined(AGPACK_COMP_BORLAND_DETECTION)
#       define AGPACK_COMP_BORLAND_DETECTION AGPACK_PREDEF_MAKE_0X_VVRP(__BORLANDC__)
#   endif
#endif

#ifdef AGPACK_COMP_BORLAND_DETECTION
#   define AGPACK_COMP_BORLAND_AVAILABLE
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_BORLAND_EMULATED AGPACK_COMP_BORLAND_DETECTION
#   else
#       undef AGPACK_COMP_BORLAND
#       define AGPACK_COMP_BORLAND AGPACK_COMP_BORLAND_DETECTION
#   endif
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_BORLAND_NAME "Borland C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_BORLAND,AGPACK_COMP_BORLAND_NAME)

#ifdef AGPACK_COMP_BORLAND_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_BORLAND_EMULATED,AGPACK_COMP_BORLAND_NAME)
#endif
