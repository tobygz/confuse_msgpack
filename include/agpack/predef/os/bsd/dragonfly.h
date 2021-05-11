/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_BSD_DRAGONFLY_H
#define AGPACK_PREDEF_OS_BSD_DRAGONFLY_H

#include <agpack/predef/os/bsd.h>

/*`
[heading `AGPACK_OS_BSD_DRAGONFLY`]

[@http://en.wikipedia.org/wiki/DragonFly_BSD DragonFly BSD] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__DragonFly__`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_BSD_DRAGONFLY AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__DragonFly__) \
    )
#   ifndef AGPACK_OS_BSD_AVAILABLE
#       define AGPACK_OS_BSD AGPACK_VERSION_NUMBER_AVAILABLE
#       define AGPACK_OS_BSD_AVAILABLE
#   endif
#   undef AGPACK_OS_BSD_DRAGONFLY
#   if defined(__DragonFly__)
#       define AGPACK_OS_DRAGONFLY_BSD AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_OS_BSD_DRAGONFLY
#   define AGPACK_OS_BSD_DRAGONFLY_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_BSD_DRAGONFLY_NAME "DragonFly BSD"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_BSD_DRAGONFLY,AGPACK_OS_BSD_DRAGONFLY_NAME)
