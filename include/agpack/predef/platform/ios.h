/*
Copyright Ruslan Baratov 2017
Copyright Rene Rivera 2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_PLAT_IOS_H
#define AGPACK_PREDEF_PLAT_IOS_H

#include <agpack/predef/os/ios.h> // AGPACK_OS_IOS
#include <agpack/predef/version_number.h> // AGPACK_VERSION_NUMBER_NOT_AVAILABLE

/*`
[heading `AGPACK_PLAT_IOS_DEVICE`]
[heading `AGPACK_PLAT_IOS_SIMULATOR`]

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`TARGET_IPHONE_SIMULATOR`] [__predef_detection__]]
    ]
 */

#define AGPACK_PLAT_IOS_DEVICE AGPACK_VERSION_NUMBER_NOT_AVAILABLE
#define AGPACK_PLAT_IOS_SIMULATOR AGPACK_VERSION_NUMBER_NOT_AVAILABLE

// https://opensource.apple.com/source/CarbonHeaders/CarbonHeaders-18.1/TargetConditionals.h
#if AGPACK_OS_IOS
#    include <TargetConditionals.h>
#    if TARGET_IPHONE_SIMULATOR == 1
#        undef AGPACK_PLAT_IOS_SIMULATOR
#        define AGPACK_PLAT_IOS_SIMULATOR AGPACK_VERSION_NUMBER_AVAILABLE
#    else
#        undef AGPACK_PLAT_IOS_DEVICE
#        define AGPACK_PLAT_IOS_DEVICE AGPACK_VERSION_NUMBER_AVAILABLE
#    endif
#endif

#if AGPACK_PLAT_IOS_SIMULATOR
#    define AGPACK_PLAT_IOS_SIMULATOR_AVAILABLE
#    include <agpack/predef/detail/platform_detected.h>
#endif

#if AGPACK_PLAT_IOS_DEVICE
#    define AGPACK_PLAT_IOS_DEVICE_AVAILABLE
#    include <agpack/predef/detail/platform_detected.h>
#endif

#define AGPACK_PLAT_IOS_SIMULATOR_NAME "iOS Simulator"
#define AGPACK_PLAT_IOS_DEVICE_NAME "iOS Device"

#endif // AGPACK_PREDEF_PLAT_IOS_H

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_IOS_SIMULATOR,AGPACK_PLAT_IOS_SIMULATOR_NAME)
AGPACK_PREDEF_DECLARE_TEST(AGPACK_PLAT_IOS_DEVICE,AGPACK_PLAT_IOS_DEVICE_NAME)
