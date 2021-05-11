/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_PLAT_MINGW64_H
#define AGPACK_PREDEF_PLAT_MINGW64_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_PLAT_MINGW64`]

[@https://mingw-w64.org/ MinGW-w64] platform.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MINGW64__`] [__predef_detection__]]

    [[`__MINGW64_VERSION_MAJOR`, `__MINGW64_VERSION_MINOR`] [V.R.0]]
    ]
 */

#define AGPACK_PLAT_MINGW64 AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MINGW64__)
#   include <_mingw.h>
#   if !defined(AGPACK_PLAT_MINGW64_DETECTION) && (defined(__MINGW64_VERSION_MAJOR) && defined(__MINGW64_VERSION_MINOR))
#       define AGPACK_PLAT_MINGW64_DETECTION \
            AGPACK_VERSION_NUMBER(__MINGW64_VERSION_MAJOR,__MINGW64_VERSION_MINOR,0)
#   endif
#   if !defined(AGPACK_PLAT_MINGW64_DETECTION)
#       define AGPACK_PLAT_MINGW64_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_PLAT_MINGW64_DETECTION
#   define AGPACK_PLAT_MINGW64_AVAILABLE
#   if defined(AGPACK_PREDEF_DETAIL_PLAT_DETECTED)
#       define AGPACK_PLAT_MINGW64_EMULATED AGPACK_PLAT_MINGW64_DETECTION
#   else
#       undef AGPACK_PLAT_MINGW64
#       define AGPACK_PLAT_MINGW64 AGPACK_PLAT_MINGW64_DETECTION
#   endif
#   include <agpack/predef/detail/platform_detected.h>
#endif

#define AGPACK_PLAT_MINGW64_NAME "MinGW-w64"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_MINGW64,AGPACK_PLAT_MINGW64_NAME)

#ifdef AGPACK_PLAT_MINGW64_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_MINGW64_EMULATED,AGPACK_PLAT_MINGW64_NAME)
#endif
