/*
Copyright Rene Rivera 2013-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_BLACKFIN_H
#define AGPACK_PREDEF_ARCHITECTURE_BLACKFIN_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_BLACKFIN`]

Blackfin Processors from Analog Devices.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__bfin__`] [__predef_detection__]]
    [[`__BFIN__`] [__predef_detection__]]
    [[`bfin`] [__predef_detection__]]
    [[`BFIN`] [__predef_detection__]]
    ]
 */

#define AGPACK_ARCH_BLACKFIN AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__bfin__) || defined(__BFIN__) || \
    defined(bfin) || defined(BFIN)
#   undef AGPACK_ARCH_BLACKFIN
#   define AGPACK_ARCH_BLACKFIN AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_ARCH_BLACKFIN
#   define AGPACK_ARCH_BLACKFIN_AVAILABLE
#endif

#define AGPACK_ARCH_BLACKFIN_NAME "Blackfin"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_BLACKFIN,AGPACK_ARCH_BLACKFIN_NAME)
