/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_PLAT_MINGW_H
#define AGPACK_PREDEF_PLAT_MINGW_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_PLAT_MINGW`]

[@http://en.wikipedia.org/wiki/MinGW MinGW] platform, either variety.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MINGW32__`] [__predef_detection__]]
    [[`__MINGW64__`] [__predef_detection__]]

    [[`__MINGW64_VERSION_MAJOR`, `__MINGW64_VERSION_MINOR`] [V.R.0]]
    [[`__MINGW32_VERSION_MAJOR`, `__MINGW32_VERSION_MINOR`] [V.R.0]]
    ]
 */

#define AGPACK_PLAT_MINGW AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MINGW32__) || defined(__MINGW64__)
#   include <_mingw.h>
#   if !defined(AGPACK_PLAT_MINGW_DETECTION) && (defined(__MINGW64_VERSION_MAJOR) && defined(__MINGW64_VERSION_MINOR))
#       define AGPACK_PLAT_MINGW_DETECTION \
            AGPACK_VERSION_NUMBER(__MINGW64_VERSION_MAJOR,__MINGW64_VERSION_MINOR,0)
#   endif
#   if !defined(AGPACK_PLAT_MINGW_DETECTION) && (defined(__MINGW32_VERSION_MAJOR) && defined(__MINGW32_VERSION_MINOR))
#       define AGPACK_PLAT_MINGW_DETECTION \
            AGPACK_VERSION_NUMBER(__MINGW32_MAJOR_VERSION,__MINGW32_MINOR_VERSION,0)
#   endif
#   if !defined(AGPACK_PLAT_MINGW_DETECTION)
#       define AGPACK_PLAT_MINGW_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_PLAT_MINGW_DETECTION
#   define AGPACK_PLAT_MINGW_AVAILABLE
#   if defined(AGPACK_PREDEF_DETAIL_PLAT_DETECTED)
#       define AGPACK_PLAT_MINGW_EMULATED AGPACK_PLAT_MINGW_DETECTION
#   else
#       undef AGPACK_PLAT_MINGW
#       define AGPACK_PLAT_MINGW AGPACK_PLAT_MINGW_DETECTION
#   endif
#   include <agpack/predef/detail/platform_detected.h>
#endif

#define AGPACK_PLAT_MINGW_NAME "MinGW (any variety)"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_MINGW,AGPACK_PLAT_MINGW_NAME)

#ifdef AGPACK_PLAT_MINGW_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_MINGW_EMULATED,AGPACK_PLAT_MINGW_NAME)
#endif
