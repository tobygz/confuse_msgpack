/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_HARDWARE_SIMD_X86_AMD_H
#define AGPACK_PREDEF_HARDWARE_SIMD_X86_AMD_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/hardware/simd/x86_amd/versions.h>

/*`
 [heading `AGPACK_HW_SIMD_X86_AMD`]

 The SIMD extension for x86 (AMD) (*if detected*).
 Version number depends on the most recent detected extension.

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__SSE4A__`] [__predef_detection__]]

     [[`__FMA4__`] [__predef_detection__]]

     [[`__XOP__`] [__predef_detection__]]

     [[`AGPACK_HW_SIMD_X86`] [__predef_detection__]]
     ]

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__SSE4A__`] [AGPACK_HW_SIMD_X86_SSE4A_VERSION]]

     [[`__FMA4__`] [AGPACK_HW_SIMD_X86_FMA4_VERSION]]

     [[`__XOP__`] [AGPACK_HW_SIMD_X86_XOP_VERSION]]

     [[`AGPACK_HW_SIMD_X86`] [AGPACK_HW_SIMD_X86]]
     ]

 [note This predef includes every other x86 SIMD extensions and also has other
 more specific extensions (FMA4, XOP, SSE4a). You should use this predef
 instead of `AGPACK_HW_SIMD_X86` to test if those specific extensions have
 been detected.]

 */

#define AGPACK_HW_SIMD_X86_AMD AGPACK_VERSION_NUMBER_NOT_AVAILABLE

// AMD CPUs also use x86 architecture. We first try to detect if any AMD
// specific extension are detected, if yes, then try to detect more recent x86
// common extensions.

#undef AGPACK_HW_SIMD_X86_AMD
#if !defined(AGPACK_HW_SIMD_X86_AMD) && defined(__XOP__)
#   define AGPACK_HW_SIMD_X86_AMD AGPACK_HW_SIMD_X86_AMD_XOP_VERSION
#endif
#if !defined(AGPACK_HW_SIMD_X86_AMD) && defined(__FMA4__)
#   define AGPACK_HW_SIMD_X86_AMD AGPACK_HW_SIMD_X86_AMD_FMA4_VERSION
#endif
#if !defined(AGPACK_HW_SIMD_X86_AMD) && defined(__SSE4A__)
#   define AGPACK_HW_SIMD_X86_AMD AGPACK_HW_SIMD_X86_AMD_SSE4A_VERSION
#endif

#if !defined(AGPACK_HW_SIMD_X86_AMD)
#   define AGPACK_HW_SIMD_X86_AMD AGPACK_VERSION_NUMBER_NOT_AVAILABLE
#else
    // At this point, we know that we have an AMD CPU, we do need to check for
    // other x86 extensions to determine the final version number.
#   include <agpack/predef/hardware/simd/x86.h>
#   if AGPACK_HW_SIMD_X86 > AGPACK_HW_SIMD_X86_AMD
#      undef AGPACK_HW_SIMD_X86_AMD
#      define AGPACK_HW_SIMD_X86_AMD AGPACK_HW_SIMD_X86
#   endif
#   define AGPACK_HW_SIMD_X86_AMD_AVAILABLE
#endif

#define AGPACK_HW_SIMD_X86_AMD_NAME "x86 (AMD) SIMD"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_HW_SIMD_X86_AMD, AGPACK_HW_SIMD_X86_AMD_NAME)
