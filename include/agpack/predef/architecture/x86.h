/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#include <agpack/predef/architecture/x86/32.h>
#include <agpack/predef/architecture/x86/64.h>

#ifndef AGPACK_PREDEF_ARCHITECTURE_X86_H
#define AGPACK_PREDEF_ARCHITECTURE_X86_H

/*`
[heading `AGPACK_ARCH_X86`]

[@http://en.wikipedia.org/wiki/X86 Intel x86] architecture. This is
a category to indicate that either `AGPACK_ARCH_X86_32` or
`AGPACK_ARCH_X86_64` is detected.
 */

#define AGPACK_ARCH_X86 AGPACK_VERSION_NUMBER_NOT_AVAILABLE

#if AGPACK_ARCH_X86_32 || AGPACK_ARCH_X86_64
#   undef AGPACK_ARCH_X86
#   define AGPACK_ARCH_X86 AGPACK_VERSION_NUMBER_AVAILABLE
#endif

#if AGPACK_ARCH_X86
#   define AGPACK_ARCH_X86_AVAILABLE
#endif

#define AGPACK_ARCH_X86_NAME "Intel x86"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ARCH_X86,AGPACK_ARCH_X86_NAME)
