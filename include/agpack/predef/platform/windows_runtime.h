/*
Copyright (c) Microsoft Corporation 2014
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_PLAT_WINDOWS_RUNTIME_H
#define AGPACK_PREDEF_PLAT_WINDOWS_RUNTIME_H

#include <agpack/predef/make.h>
#include <agpack/predef/os/windows.h>
#include <agpack/predef/platform/windows_phone.h>
#include <agpack/predef/platform/windows_store.h>
#include <agpack/predef/version_number.h>

/*`
[heading `AGPACK_PLAT_WINDOWS_RUNTIME`]

Deprecated.

[@https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide UWP]
for Windows Phone or Store development.  This does not align to the existing development model for
UWP and is deprecated.  Use one of the other `AGPACK_PLAT_WINDOWS_*`definitions instead.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`AGPACK_PLAT_WINDOWS_PHONE`] [__predef_detection__]]
    [[`AGPACK_PLAT_WINDOWS_STORE`] [__predef_detection__]]
    ]
 */

#define AGPACK_PLAT_WINDOWS_RUNTIME AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if AGPACK_OS_WINDOWS && \
    (AGPACK_PLAT_WINDOWS_STORE || AGPACK_PLAT_WINDOWS_PHONE)
#   undef AGPACK_PLAT_WINDOWS_RUNTIME
#   define AGPACK_PLAT_WINDOWS_RUNTIME AGPACK_VERSION_NUMBER_AVAILABLE
#endif
 
#if AGPACK_PLAT_WINDOWS_RUNTIME
#   define AGPACK_PLAT_WINDOWS_RUNTIME_AVAILABLE
#   include <agpack/predef/detail/platform_detected.h>
#endif

#define AGPACK_PLAT_WINDOWS_RUNTIME_NAME "Windows Runtime"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_WINDOWS_RUNTIME,AGPACK_PLAT_WINDOWS_RUNTIME_NAME)
