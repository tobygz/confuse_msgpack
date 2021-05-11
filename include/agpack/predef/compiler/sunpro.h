/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_SUNPRO_H
#define AGPACK_PREDEF_COMPILER_SUNPRO_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_SUNPRO`]

[@http://en.wikipedia.org/wiki/Oracle_Solaris_Studio Oracle Solaris Studio] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__SUNPRO_CC`] [__predef_detection__]]
    [[`__SUNPRO_C`] [__predef_detection__]]

    [[`__SUNPRO_CC`] [V.R.P]]
    [[`__SUNPRO_C`] [V.R.P]]
    [[`__SUNPRO_CC`] [VV.RR.P]]
    [[`__SUNPRO_C`] [VV.RR.P]]
    ]
 */

#define AGPACK_COMP_SUNPRO AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SUNPRO_CC) || defined(__SUNPRO_C)
#   if !defined(AGPACK_COMP_SUNPRO_DETECTION) && defined(__SUNPRO_CC)
#       if (__SUNPRO_CC < 0x5100)
#           define AGPACK_COMP_SUNPRO_DETECTION AGPACK_PREDEF_MAKE_0X_VRP(__SUNPRO_CC)
#       else
#           define AGPACK_COMP_SUNPRO_DETECTION AGPACK_PREDEF_MAKE_0X_VVRRP(__SUNPRO_CC)
#       endif
#   endif
#   if !defined(AGPACK_COMP_SUNPRO_DETECTION) && defined(__SUNPRO_C)
#       if (__SUNPRO_C < 0x5100)
#           define AGPACK_COMP_SUNPRO_DETECTION AGPACK_PREDEF_MAKE_0X_VRP(__SUNPRO_C)
#       else
#           define AGPACK_COMP_SUNPRO_DETECTION AGPACK_PREDEF_MAKE_0X_VVRRP(__SUNPRO_C)
#       endif
#   endif
#   if !defined(AGPACK_COMP_SUNPRO_DETECTION)
#       define AGPACK_COMP_SUNPRO_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_COMP_SUNPRO_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_SUNPRO_EMULATED AGPACK_COMP_SUNPRO_DETECTION
#   else
#       undef AGPACK_COMP_SUNPRO
#       define AGPACK_COMP_SUNPRO AGPACK_COMP_SUNPRO_DETECTION
#   endif
#   define AGPACK_COMP_SUNPRO_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_SUNPRO_NAME "Oracle Solaris Studio"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_SUNPRO,AGPACK_COMP_SUNPRO_NAME)

#ifdef AGPACK_COMP_SUNPRO_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_SUNPRO_EMULATED,AGPACK_COMP_SUNPRO_NAME)
#endif
