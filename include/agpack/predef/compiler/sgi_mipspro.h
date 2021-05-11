/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_SGI_MIPSPRO_H
#define AGPACK_PREDEF_COMPILER_SGI_MIPSPRO_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_SGI`]

[@http://en.wikipedia.org/wiki/MIPSpro SGI MIPSpro] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__sgi`] [__predef_detection__]]
    [[`sgi`] [__predef_detection__]]

    [[`_SGI_COMPILER_VERSION`] [V.R.P]]
    [[`_COMPILER_VERSION`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_SGI AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__sgi) || defined(sgi)
#   if !defined(AGPACK_COMP_SGI_DETECTION) && defined(_SGI_COMPILER_VERSION)
#       define AGPACK_COMP_SGI_DETECTION AGPACK_PREDEF_MAKE_10_VRP(_SGI_COMPILER_VERSION)
#   endif
#   if !defined(AGPACK_COMP_SGI_DETECTION) && defined(_COMPILER_VERSION)
#       define AGPACK_COMP_SGI_DETECTION AGPACK_PREDEF_MAKE_10_VRP(_COMPILER_VERSION)
#   endif
#   if !defined(AGPACK_COMP_SGI_DETECTION)
#       define AGPACK_COMP_SGI_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_COMP_SGI_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_SGI_EMULATED AGPACK_COMP_SGI_DETECTION
#   else
#       undef AGPACK_COMP_SGI
#       define AGPACK_COMP_SGI AGPACK_COMP_SGI_DETECTION
#   endif
#   define AGPACK_COMP_SGI_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_SGI_NAME "SGI MIPSpro"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_SGI,AGPACK_COMP_SGI_NAME)

#ifdef AGPACK_COMP_SGI_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_SGI_EMULATED,AGPACK_COMP_SGI_NAME)
#endif
