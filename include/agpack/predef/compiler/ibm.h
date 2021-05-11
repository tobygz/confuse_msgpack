/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_IBM_H
#define AGPACK_PREDEF_COMPILER_IBM_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_IBM`]

[@http://en.wikipedia.org/wiki/VisualAge IBM XL C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__IBMCPP__`] [__predef_detection__]]
    [[`__xlC__`] [__predef_detection__]]
    [[`__xlc__`] [__predef_detection__]]

    [[`__COMPILER_VER__`] [V.R.P]]
    [[`__xlC__`] [V.R.P]]
    [[`__xlc__`] [V.R.P]]
    [[`__IBMCPP__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_IBM AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__IBMCPP__) || defined(__xlC__) || defined(__xlc__)
#   if !defined(AGPACK_COMP_IBM_DETECTION) && defined(__COMPILER_VER__)
#       define AGPACK_COMP_IBM_DETECTION AGPACK_PREDEF_MAKE_0X_VRRPPPP(__COMPILER_VER__)
#   endif
#   if !defined(AGPACK_COMP_IBM_DETECTION) && defined(__xlC__)
#       define AGPACK_COMP_IBM_DETECTION AGPACK_PREDEF_MAKE_0X_VVRR(__xlC__)
#   endif
#   if !defined(AGPACK_COMP_IBM_DETECTION) && defined(__xlc__)
#       define AGPACK_COMP_IBM_DETECTION AGPACK_PREDEF_MAKE_0X_VVRR(__xlc__)
#   endif
#   if !defined(AGPACK_COMP_IBM_DETECTION)
#       define AGPACK_COMP_IBM_DETECTION AGPACK_PREDEF_MAKE_10_VRP(__IBMCPP__)
#   endif
#endif

#ifdef AGPACK_COMP_IBM_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_IBM_EMULATED AGPACK_COMP_IBM_DETECTION
#   else
#       undef AGPACK_COMP_IBM
#       define AGPACK_COMP_IBM AGPACK_COMP_IBM_DETECTION
#   endif
#   define AGPACK_COMP_IBM_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_IBM_NAME "IBM XL C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_IBM,AGPACK_COMP_IBM_NAME)

#ifdef AGPACK_COMP_IBM_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_IBM_EMULATED,AGPACK_COMP_IBM_NAME)
#endif
