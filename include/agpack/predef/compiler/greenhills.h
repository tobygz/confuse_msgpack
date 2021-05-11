/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_GREENHILLS_H
#define AGPACK_PREDEF_COMPILER_GREENHILLS_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_GHS`]

[@http://en.wikipedia.org/wiki/Green_Hills_Software Green Hills C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__ghs`] [__predef_detection__]]
    [[`__ghs__`] [__predef_detection__]]

    [[`__GHS_VERSION_NUMBER__`] [V.R.P]]
    [[`__ghs`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_GHS AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__ghs) || defined(__ghs__)
#   if !defined(AGPACK_COMP_GHS_DETECTION) && defined(__GHS_VERSION_NUMBER__)
#       define AGPACK_COMP_GHS_DETECTION AGPACK_PREDEF_MAKE_10_VRP(__GHS_VERSION_NUMBER__)
#   endif
#   if !defined(AGPACK_COMP_GHS_DETECTION) && defined(__ghs)
#       define AGPACK_COMP_GHS_DETECTION AGPACK_PREDEF_MAKE_10_VRP(__ghs)
#   endif
#   if !defined(AGPACK_COMP_GHS_DETECTION)
#       define AGPACK_COMP_GHS_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_COMP_GHS_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_GHS_EMULATED AGPACK_COMP_GHS_DETECTION
#   else
#       undef AGPACK_COMP_GHS
#       define AGPACK_COMP_GHS AGPACK_COMP_GHS_DETECTION
#   endif
#   define AGPACK_COMP_GHS_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_GHS_NAME "Green Hills C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_GHS,AGPACK_COMP_GHS_NAME)

#ifdef AGPACK_COMP_GHS_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_GHS_EMULATED,AGPACK_COMP_GHS_NAME)
#endif
