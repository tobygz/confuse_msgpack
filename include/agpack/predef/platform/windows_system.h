/*
Copyright James E. King III, 2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_PLAT_WINDOWS_SYSTEM_H
#define AGPACK_PREDEF_PLAT_WINDOWS_SYSTEM_H

#include <agpack/predef/make.h>
#include <agpack/predef/os/windows.h>
#include <agpack/predef/platform/windows_uwp.h>
#include <agpack/predef/version_number.h>

/*`
[heading `AGPACK_PLAT_WINDOWS_SYSTEM`]

[@https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide UWP]
for Windows System development.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`WINAPI_FAMILY == WINAPI_FAMILY_SYSTEM`] [__predef_detection__]]
    ]
 */

#define AGPACK_PLAT_WINDOWS_SYSTEM AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if AGPACK_OS_WINDOWS && \
    defined(WINAPI_FAMILY_SYSTEM) && WINAPI_FAMILY == WINAPI_FAMILY_SYSTEM
#   undef AGPACK_PLAT_WINDOWS_SYSTEM
#   define AGPACK_PLAT_WINDOWS_SYSTEM AGPACK_VERSION_NUMBER_AVAILABLE
#endif
 
#if AGPACK_PLAT_WINDOWS_SYSTEM
#   define AGPACK_PLAT_WINDOWS_SYSTEM_AVAILABLE
#   include <agpack/predef/detail/platform_detected.h>
#endif

#define AGPACK_PLAT_WINDOWS_SYSTEM_NAME "Windows Drivers and Tools"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_WINDOWS_SYSTEM,AGPACK_PLAT_WINDOWS_SYSTEM_NAME)
