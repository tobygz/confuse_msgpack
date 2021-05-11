/*
Copyright Rene Rivera 2008-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_INTEL_H
#define AGPACK_PREDEF_COMPILER_INTEL_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_INTEL`]

[@http://en.wikipedia.org/wiki/Intel_C%2B%2B Intel C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__INTEL_COMPILER`] [__predef_detection__]]
    [[`__ICL`] [__predef_detection__]]
    [[`__ICC`] [__predef_detection__]]
    [[`__ECC`] [__predef_detection__]]

    [[`__INTEL_COMPILER`] [V.R]]
    [[`__INTEL_COMPILER` and `__INTEL_COMPILER_UPDATE`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_INTEL AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || \
    defined(__ECC)
/*`
[note Because of an Intel mistake in the release version numbering when
`__INTEL_COMPILER` is `9999` it is detected as version 12.1.0.]
 */
#   if !defined(AGPACK_COMP_INTEL_DETECTION) && defined(__INTEL_COMPILER) && (__INTEL_COMPILER == 9999)
#       define AGPACK_COMP_INTEL_DETECTION AGPACK_VERSION_NUMBER(12,1,0)
#   endif
#   if !defined(AGPACK_COMP_INTEL_DETECTION) && defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE)
#       define AGPACK_COMP_INTEL_DETECTION AGPACK_VERSION_NUMBER( \
            AGPACK_VERSION_NUMBER_MAJOR(AGPACK_PREDEF_MAKE_10_VVRR(__INTEL_COMPILER)), \
            AGPACK_VERSION_NUMBER_MINOR(AGPACK_PREDEF_MAKE_10_VVRR(__INTEL_COMPILER)), \
            __INTEL_COMPILER_UPDATE)
#   endif
#   if !defined(AGPACK_COMP_INTEL_DETECTION) && defined(__INTEL_COMPILER)
#       define AGPACK_COMP_INTEL_DETECTION AGPACK_PREDEF_MAKE_10_VVRR(__INTEL_COMPILER)
#   endif
#   if !defined(AGPACK_COMP_INTEL_DETECTION)
#       define AGPACK_COMP_INTEL_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef AGPACK_COMP_INTEL_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_INTEL_EMULATED AGPACK_COMP_INTEL_DETECTION
#   else
#       undef AGPACK_COMP_INTEL
#       define AGPACK_COMP_INTEL AGPACK_COMP_INTEL_DETECTION
#   endif
#   define AGPACK_COMP_INTEL_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_INTEL_NAME "Intel C/C++"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_INTEL,AGPACK_COMP_INTEL_NAME)

#ifdef AGPACK_COMP_INTEL_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_INTEL_EMULATED,AGPACK_COMP_INTEL_NAME)
#endif
