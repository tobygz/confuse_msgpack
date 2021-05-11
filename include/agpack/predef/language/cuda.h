/*
Copyright Benjamin Worpitz 2018
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_LANGUAGE_CUDA_H
#define AGPACK_PREDEF_LANGUAGE_CUDA_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_LANG_CUDA`]

[@https://en.wikipedia.org/wiki/CUDA CUDA C/C++] language.
If available, the version is detected as VV.RR.P.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__CUDACC__`] [__predef_detection__]]
    [[`__CUDA__`] [__predef_detection__]]

    [[`CUDA_VERSION`] [VV.RR.P]]
    ]
 */

#define AGPACK_LANG_CUDA AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__CUDACC__) || defined(__CUDA__)
#   undef AGPACK_LANG_CUDA
#   include <cuda.h>
#   if defined(CUDA_VERSION)
#       define AGPACK_LANG_CUDA AGPACK_PREDEF_MAKE_10_VVRRP(CUDA_VERSION)
#   else
#       define AGPACK_LANG_CUDA AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if AGPACK_LANG_CUDA
#   define AGPACK_LANG_CUDA_AVAILABLE
#endif

#define AGPACK_LANG_CUDA_NAME "CUDA C/C++"


#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_LANG_CUDA,AGPACK_LANG_CUDA_NAME)
