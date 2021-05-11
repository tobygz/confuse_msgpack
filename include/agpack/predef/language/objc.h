/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LANGUAGE_OBJC_H
#define AGPACK_PREDEF_LANGUAGE_OBJC_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LANG_OBJC`]

[@http://en.wikipedia.org/wiki/Objective-C Objective-C] language.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__OBJC__`] [__predef_detection__]]
    ]
 */

#define AGPACK_LANG_OBJC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__OBJC__)
#   undef AGPACK_LANG_OBJC
#   define AGPACK_LANG_OBJC AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_LANG_OBJC
#   define AGPACK_LANG_OBJC_AVAILABLE
#endif

#define AGPACK_LANG_OBJC_NAME "Objective-C"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LANG_OBJC,AGPACK_LANG_OBJC_NAME)
