/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LANGUAGE_STDC_H
#define AGPACK_PREDEF_LANGUAGE_STDC_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LANG_STDC`]

[@http://en.wikipedia.org/wiki/C_(programming_language) Standard C] language.
If available, the year of the standard is detected as YYYY.MM.1 from the Epoc date.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__STDC__`] [__predef_detection__]]

    [[`__STDC_VERSION__`] [V.R.P]]
    ]
 */

#define AGPACK_LANG_STDC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__STDC__)
#   undef AGPACK_LANG_STDC
#   if defined(__STDC_VERSION__)
#       if (__STDC_VERSION__ > 100)
#           define AGPACK_LANG_STDC AGPACK_PREDEF_MAKE_YYYYMM(__STDC_VERSION__)
#       else
#           define AGPACK_LANG_STDC AGPACK_VERSION_NUMBER_AVAILABLE
#       endif
#   else
#       define AGPACK_LANG_STDC AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_LANG_STDC
#   define AGPACK_LANG_STDC_AVAILABLE
#endif

#define AGPACK_LANG_STDC_NAME "Standard C"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LANG_STDC,AGPACK_LANG_STDC_NAME)
