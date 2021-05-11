/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_OS_BSD_BSDI_H
#define AGPACK_PREDEF_OS_BSD_BSDI_H

#include <agpack/predef/os/bsd.h>

/*`
[heading `AGPACK_OS_BSD_BSDI`]

[@http://en.wikipedia.org/wiki/BSD/OS BSDi BSD/OS] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__bsdi__`] [__predef_detection__]]
    ]
 */

#define AGPACK_OS_BSD_BSDI AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(AGPACK_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__bsdi__) \
    )
#   ifndef AGPACK_OS_BSD_AVAILABLE
#       define AGPACK_OS_BSD AGPACK_VERSION_NUMBER_AVAILABLE
#       define AGPACK_OS_BSD_AVAILABLE
#   endif
#   undef AGPACK_OS_BSD_BSDI
#   define AGPACK_OS_BSD_BSDI AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_OS_BSD_BSDI
#   define AGPACK_OS_BSD_BSDI_AVAILABLE
#   include <agpack/predef/detail/os_detected.h>
#endif

#define AGPACK_OS_BSD_BSDI_NAME "BSDi BSD/OS"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_OS_BSD_BSDI,AGPACK_OS_BSD_BSDI_NAME)
