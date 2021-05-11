/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_BSD_FREE_H
#define AGPACK_PREDEF_OS_BSD_FREE_H

#include <agpack/predef/os/bsd.h>

/*`
[heading `AGPACK_OS_BSD_FREE`]

[@http://en.wikipedia.org/wiki/Freebsd FreeBSD] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__FreeBSD__`] [__predef_detection__]]

    [[`__FreeBSD_version`] [V.R.P]]
    ]
 */

#define AGPACK_OS_BSD_FREE AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__FreeBSD__) \
    )
#   ifndef AGPACK_OS_BSD_AVAILABLE
#       define AGPACK_OS_BSD AGPACK_VERSION_NUMBER_AVAILABLE
#       define AGPACK_OS_BSD_AVAILABLE
#   endif
#   undef AGPACK_OS_BSD_FREE
#   include <sys/param.h>
#   if defined(__FreeBSD_version)
#       if __FreeBSD_version == 491000
#           define AGPACK_OS_BSD_FREE \
                AGPACK_VERSION_NUMBER(4, 10, 0)
#       elif __FreeBSD_version == 492000
#           define AGPACK_OS_BSD_FREE \
                AGPACK_VERSION_NUMBER(4, 11, 0)
#       elif __FreeBSD_version < 500000
#           define AGPACK_OS_BSD_FREE \
                AGPACK_PREDEF_MAKE_10_VRPPPP(__FreeBSD_version)
#       else
#           define AGPACK_OS_BSD_FREE \
                AGPACK_PREDEF_MAKE_10_VVRRPPP(__FreeBSD_version)
#       endif
#   else
#       define AGPACK_OS_BSD_FREE AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_OS_BSD_FREE
#   define AGPACK_OS_BSD_FREE_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_BSD_FREE_NAME "Free BSD"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_BSD_FREE,AGPACK_OS_BSD_FREE_NAME)
