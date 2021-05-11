/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LANGUAGE_STDCPP_H
#define AGPACK_PREDEF_LANGUAGE_STDCPP_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LANG_STDCPP`]

[@http://en.wikipedia.org/wiki/C%2B%2B Standard C++] language.
If available, the year of the standard is detected as YYYY.MM.1 from the Epoc date.
Because of the way the C++ standardization process works the
defined version year will not be the commonly known year of the standard.
Specifically the defined versions are:

[table Detected Version Number vs. C++ Standard Year
  [[Detected Version Number] [Standard Year] [C++ Standard]]
  [[27.11.1] [1998] [ISO/IEC 14882:1998]]
  [[41.12.1] [2011] [ISO/IEC 14882:2011]]
]

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__cplusplus`] [__predef_detection__]]

    [[`__cplusplus`] [YYYY.MM.1]]
    ]
 */

#define AGPACK_LANG_STDCPP AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__cplusplus)
#   undef AGPACK_LANG_STDCPP
#   if (__cplusplus > 100)
#       define AGPACK_LANG_STDCPP AGPACK_PREDEF_MAKE_YYYYMM(__cplusplus)
#   else
#       define AGPACK_LANG_STDCPP AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_LANG_STDCPP
#   define AGPACK_LANG_STDCPP_AVAILABLE
#endif

#define AGPACK_LANG_STDCPP_NAME "Standard C++"

/*`
[heading `AGPACK_LANG_STDCPPCLI`]

[@http://en.wikipedia.org/wiki/C%2B%2B/CLI Standard C++/CLI] language.
If available, the year of the standard is detected as YYYY.MM.1 from the Epoc date.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__cplusplus_cli`] [__predef_detection__]]

    [[`__cplusplus_cli`] [YYYY.MM.1]]
    ]
 */

#define AGPACK_LANG_STDCPPCLI AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__cplusplus_cli)
#   undef AGPACK_LANG_STDCPPCLI
#   if (__cplusplus_cli > 100)
#       define AGPACK_LANG_STDCPPCLI AGPACK_PREDEF_MAKE_YYYYMM(__cplusplus_cli)
#   else
#       define AGPACK_LANG_STDCPPCLI AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_LANG_STDCPPCLI
#   define AGPACK_LANG_STDCPPCLI_AVAILABLE
#endif

#define AGPACK_LANG_STDCPPCLI_NAME "Standard C++/CLI"

/*`
[heading `AGPACK_LANG_STDECPP`]

[@http://en.wikipedia.org/wiki/Embedded_C%2B%2B Standard Embedded C++] language.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__embedded_cplusplus`] [__predef_detection__]]
    ]
 */

#define AGPACK_LANG_STDECPP AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__embedded_cplusplus)
#   undef AGPACK_LANG_STDECPP
#   define AGPACK_LANG_STDECPP AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_LANG_STDECPP
#   define AGPACK_LANG_STDECPP_AVAILABLE
#endif

#define AGPACK_LANG_STDECPP_NAME "Standard Embedded C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LANG_STDCPP,AGPACK_LANG_STDCPP_NAME)

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LANG_STDCPPCLI,AGPACK_LANG_STDCPPCLI_NAME)

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LANG_STDECPP,AGPACK_LANG_STDECPP_NAME)
