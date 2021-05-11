/*
Copyright Benjamin Worpitz 2018
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ARCHITECTURE_PTX_H
#define AGPACK_PREDEF_ARCHITECTURE_PTX_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>

/*`
[heading `AGPACK_ARCH_PTX`]

[@https://en.wikipedia.org/wiki/Parallel_Thread_Execution PTX] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__CUDA_ARCH__`] [__predef_detection__]]

    [[`__CUDA_ARCH__`] [V.R.0]]
    ]
 */

#define AGPACK_ARCH_PTX AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__CUDA_ARCH__)
#   undef AGPACK_ARCH_PTX
#   define AGPACK_ARCH_PTX AGPACK_PREDEF_MAKE_10_VR0(__CUDA_ARCH__)
#endif

#if AGPACK_ARCH_PTX
#   define AGPACK_ARCH_PTX_AVAILABLE
#endif

#define AGPACK_ARCH_PTX_NAME "PTX"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_PTX,AGPACK_ARCH_PTX_NAME)
