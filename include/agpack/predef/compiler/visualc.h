/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_VISUALC_H
#define AGPACK_PREDEF_COMPILER_VISUALC_H

/* Other compilers that emulate this one need to be detected first. */

#include <agpack/predef/compiler/clang.h>

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_MSVC`]

[@http://en.wikipedia.org/wiki/Visual_studio Microsoft Visual C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_MSC_VER`] [__predef_detection__]]

    [[`_MSC_FULL_VER`] [V.R.P]]
    [[`_MSC_VER`] [V.R.0]]
    ]

[note Release of Visual Studio after 2015 will no longer be identified
by Boost Predef as the marketing version number. Instead we use the
compiler version number directly, i.e. the _MSC_VER number.]
 */

#define AGPACK_COMP_MSVC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_MSC_VER)
#   if !defined (_MSC_FULL_VER)
#       define AGPACK_COMP_MSVC_BUILD 0
#   else
        /* how many digits does the build number have? */
#       if _MSC_FULL_VER / 10000 == _MSC_VER
            /* four digits */
#           define AGPACK_COMP_MSVC_BUILD (_MSC_FULL_VER % 10000)
#       elif _MSC_FULL_VER / 100000 == _MSC_VER
            /* five digits */
#           define AGPACK_COMP_MSVC_BUILD (_MSC_FULL_VER % 100000)
#       else
#           error "Cannot determine build number from _MSC_FULL_VER"
#       endif
#   endif
    /*
    VS2014 was skipped in the release sequence for MS. Which
    means that the compiler and VS product versions are no longer
    in sync. Hence we need to use different formulas for
    mapping from MSC version to VS product version.

    VS2017 is a total nightmare when it comes to version numbers.
    Hence to avoid arguments relating to that both present and
    future.. Any version after VS2015 will use solely the compiler
    version, i.e. cl.exe, as the version number here.
    */
#   if (_MSC_VER > 1900)
#       define AGPACK_COMP_MSVC_DETECTION AGPACK_VERSION_NUMBER(\
            _MSC_VER/100,\
            _MSC_VER%100,\
            AGPACK_COMP_MSVC_BUILD)
#   elif (_MSC_VER >= 1900)
#       define AGPACK_COMP_MSVC_DETECTION AGPACK_VERSION_NUMBER(\
            _MSC_VER/100-5,\
            _MSC_VER%100,\
            AGPACK_COMP_MSVC_BUILD)
#   else
#       define AGPACK_COMP_MSVC_DETECTION AGPACK_VERSION_NUMBER(\
            _MSC_VER/100-6,\
            _MSC_VER%100,\
            AGPACK_COMP_MSVC_BUILD)
#   endif
#endif

#ifdef AGPACK_COMP_MSVC_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_MSVC_EMULATED AGPACK_COMP_MSVC_DETECTION
#   else
#       undef AGPACK_COMP_MSVC
#       define AGPACK_COMP_MSVC AGPACK_COMP_MSVC_DETECTION
#   endif
#   define AGPACK_COMP_MSVC_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_MSVC_NAME "Microsoft Visual C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_MSVC,AGPACK_COMP_MSVC_NAME)

#ifdef AGPACK_COMP_MSVC_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_MSVC_EMULATED,AGPACK_COMP_MSVC_NAME)
#endif
