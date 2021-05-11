/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_HARDWARE_SIMD_PPC_H
#define AGPACK_PREDEF_HARDWARE_SIMD_PPC_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/hardware/simd/ppc/versions.h>

/*`
 [heading `AGPACK_HW_SIMD_PPC`]

 The SIMD extension for PowerPC (*if detected*).
 Version number depends on the most recent detected extension.

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__VECTOR4DOUBLE__`] [__predef_detection__]]

     [[`__ALTIVEC__`] [__predef_detection__]]
     [[`__VEC__`] [__predef_detection__]]

     [[`__VSX__`] [__predef_detection__]]
     ]

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__VECTOR4DOUBLE__`] [AGPACK_HW_SIMD_PPC_QPX_VERSION]]

     [[`__ALTIVEC__`] [AGPACK_HW_SIMD_PPC_VMX_VERSION]]
     [[`__VEC__`] [AGPACK_HW_SIMD_PPC_VMX_VERSION]]

     [[`__VSX__`] [AGPACK_HW_SIMD_PPC_VSX_VERSION]]
     ]

 */

#define AGPACK_HW_SIMD_PPC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#undef AGPACK_HW_SIMD_PPC
#if !defined(AGPACK_HW_SIMD_PPC) && defined(__VECTOR4DOUBLE__)
#   define AGPACK_HW_SIMD_PPC AGPACK_HW_SIMD_PPC_QPX_VERSION
#endif
#if !defined(AGPACK_HW_SIMD_PPC) && defined(__VSX__)
#   define AGPACK_HW_SIMD_PPC AGPACK_HW_SIMD_PPC_VSX_VERSION
#endif
#if !defined(AGPACK_HW_SIMD_PPC) && (defined(__ALTIVEC__) || defined(__VEC__))
#   define AGPACK_HW_SIMD_PPC AGPACK_HW_SIMD_PPC_VMX_VERSION
#endif

#if !defined(AGPACK_HW_SIMD_PPC)
#   define AGPACK_HW_SIMD_PPC AGPACK_VERSION_NUMBER_NOT_AVAILABLE
#else
#   define AGPACK_HW_SIMD_PPC_AVAILABLE
#endif

#define AGPACK_HW_SIMD_PPC_NAME "PPC SIMD"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_HW_SIMD_PPC, AGPACK_HW_SIMD_PPC_NAME)
