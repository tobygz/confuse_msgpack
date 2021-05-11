/*
Copyright Benjamin Worpitz 2018
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_COMPILER_NVCC_H
#define AGPACK_PREDEF_COMPILER_NVCC_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_COMP_NVCC`]

[@https://en.wikipedia.org/wiki/NVIDIA_CUDA_Compiler NVCC] compiler.
Version number available as major, minor, and patch beginning with version 7.5.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__NVCC__`] [__predef_detection__]]

    [[`__CUDACC_VER_MAJOR__`, `__CUDACC_VER_MINOR__`, `__CUDACC_VER_BUILD__`] [V.R.P]]
    ]
 */

#define AGPACK_COMP_NVCC AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__NVCC__)
#   if !defined(__CUDACC_VER_MAJOR__) || !defined(__CUDACC_VER_MINOR__) || !defined(__CUDACC_VER_BUILD__)
#       define AGPACK_COMP_NVCC_DETECTION AGPACK_VERSION_NUMBER_AVAILABLE
#   else
#       define AGPACK_COMP_NVCC_DETECTION AGPACK_VERSION_NUMBER(__CUDACC_VER_MAJOR__, __CUDACC_VER_MINOR__, __CUDACC_VER_BUILD__)
#   endif
#endif

#ifdef AGPACK_COMP_NVCC_DETECTION
#   if defined(AGPACK_PREDEF_DETAIL_COMP_DETECTED)
#       define AGPACK_COMP_NVCC_EMULATED AGPACK_COMP_NVCC_DETECTION
#   else
#       undef AGPACK_COMP_NVCC
#       define AGPACK_COMP_NVCC AGPACK_COMP_NVCC_DETECTION
#   endif
#   define AGPACK_COMP_NVCC_AVAILABLE
#   include <agpack/predef/detail/comp_detected.h>
#endif

#define AGPACK_COMP_NVCC_NAME "NVCC"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_NVCC,AGPACK_COMP_NVCC_NAME)

#ifdef AGPACK_COMP_NVCC_EMULATED
#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_COMP_NVCC_EMULATED,AGPACK_COMP_NVCC_NAME)
#endif
