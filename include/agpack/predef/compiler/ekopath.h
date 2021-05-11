/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_EKOPATH_H
#define AGPACK_PREDEF_COMPILER_EKOPATH_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_PATH`]

[@http://en.wikipedia.org/wiki/PathScale EKOpath] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__PATHCC__`] [__predef_detection__]]

    [[`__PATHCC__`, `__PATHCC_MINOR__`, `__PATHCC_PATCHLEVEL__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_PATH AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__PATHCC__)
#   define AGPACK_COMP_PATH_DETECTION \
        AGPACK_VERSION_NUMBER(__PATHCC__,__PATHCC_MINOR__,__PATHCC_PATCHLEVEL__)
#endif

#ifdef AGPACK_COMP_PATH_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_PATH_EMULATED AGPACK_COMP_PATH_DETECTION
#   else
#       undef AGPACK_COMP_PATH
#       define AGPACK_COMP_PATH AGPACK_COMP_PATH_DETECTION
#   endif
#   define AGPACK_COMP_PATH_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_PATH_NAME "EKOpath"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_PATH,AGPACK_COMP_PATH_NAME)

#ifdef AGPACK_COMP_PATH_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_PATH_EMULATED,AGPACK_COMP_PATH_NAME)
#endif
