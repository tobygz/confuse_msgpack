/*
Copyright (c) Microsoft Corporation 2014
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_PLAT_WINDOWS_PHONE_H
#define AGPACK_PREDEF_PLAT_WINDOWS_PHONE_H

#include <agpack/predef/make.h>
#include <agpack/predef/os/windows.h>
#include <agpack/predef/platform/windows_uwp.h>
#include <agpack/predef/version_number.h>

/*`
[heading `AGPACK_PLAT_WINDOWS_PHONE`]

[@https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide UWP]
for Windows Phone development.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP`] [__predef_detection__]]
    ]
 */

#define AGPACK_PLAT_WINDOWS_PHONE AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if AGPACK_OS_WINDOWS && \
    defined(WINAPI_FAMILY_PHONE_APP) && WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#   undef AGPACK_PLAT_WINDOWS_PHONE
#   define AGPACK_PLAT_WINDOWS_PHONE AGPACK_VERSION_NUMBER_AVAILABLE
#endif
 
#if AGPACK_PLAT_WINDOWS_PHONE
#   define AGPACK_PLAT_WINDOWS_PHONE_AVAILABLE
#   include <agpack/predef/detail/platform_detected.h>
#endif

#define AGPACK_PLAT_WINDOWS_PHONE_NAME "Windows Phone"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_WINDOWS_PHONE,AGPACK_PLAT_WINDOWS_PHONE_NAME)
