/*
Copyright Rene Rivera 2013-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_ENDIAN_H
#define AGPACK_PREDEF_ENDIAN_H

#include <agpack/predef/version_number.h>
#include <agpack/predef/make.h>
#include <agpack/predef/library/c/gnu.h>
#include <agpack/predef/os/macos.h>
#include <agpack/predef/os/bsd.h>
#include <agpack/predef/os/android.h>

/*`
[heading `AGPACK_ENDIAN_*`]

Detection of endian memory ordering. There are four defined macros
in this header that define the various generally possible endian
memory orderings:

* `AGPACK_ENDIAN_BIG_BYTE`, byte-swapped big-endian.
* `AGPACK_ENDIAN_BIG_WORD`, word-swapped big-endian.
* `AGPACK_ENDIAN_LITTLE_BYTE`, byte-swapped little-endian.
* `AGPACK_ENDIAN_LITTLE_WORD`, word-swapped little-endian.

The detection is conservative in that it only identifies endianness
that it knows for certain. In particular bi-endianness is not
indicated as is it not practically possible to determine the
endianness from anything but an operating system provided
header. And the currently known headers do not define that
programatic bi-endianness is available.

This implementation is a compilation of various publicly available
information and acquired knowledge:

# The indispensable documentation of "Pre-defined Compiler Macros"
  [@http://sourceforge.net/p/predef/wiki/Endianness Endianness].
# The various endian specifications available in the
  [@http://wikipedia.org/ Wikipedia] computer architecture pages.
# Generally available searches for headers that define endianness.
 */

#define AGPACK_ENDIAN_BIG_BYTE AGPACK_VERSION_NUMBER_NOT_AVAILABLE
#define AGPACK_ENDIAN_BIG_WORD AGPACK_VERSION_NUMBER_NOT_AVAILABLE
#define AGPACK_ENDIAN_LITTLE_BYTE AGPACK_VERSION_NUMBER_NOT_AVAILABLE
#define AGPACK_ENDIAN_LITTLE_WORD AGPACK_VERSION_NUMBER_NOT_AVAILABLE

/* GNU libc provides a header defining __BYTE_ORDER, or _BYTE_ORDER.
 * And some OSs provide some for of endian header also.
 */
#if !AGPACK_ENDIAN_BIG_BYTE && !AGPACK_ENDIAN_BIG_WORD && \
    !AGPACK_ENDIAN_LITTLE_BYTE && !AGPACK_ENDIAN_LITTLE_WORD
#   if AGPACK_LIB_C_GNU || AGPACK_OS_ANDROID
#       include <endian.h>
#   else
#       if AGPACK_OS_MACOS
#           include <machine/endian.h>
#       else
#           if AGPACK_OS_BSD
#               if AGPACK_OS_BSD_OPEN
#                   include <machine/endian.h>
#               else
#                   include <sys/endian.h>
#               endif
#           endif
#       endif
#   endif
#   if defined(__BYTE_ORDER)
#       if defined(__BIG_ENDIAN) && (__BYTE_ORDER == __BIG_ENDIAN)
#           undef AGPACK_ENDIAN_BIG_BYTE
#           define AGPACK_ENDIAN_BIG_BYTE AGPACK_VERSION_NUMBER_AVAILABLE
#       endif
#       if defined(__LITTLE_ENDIAN) && (__BYTE_ORDER == __LITTLE_ENDIAN)
#           undef AGPACK_ENDIAN_LITTLE_BYTE
#           define AGPACK_ENDIAN_LITTLE_BYTE AGPACK_VERSION_NUMBER_AVAILABLE
#       endif
#       if defined(__PDP_ENDIAN) && (__BYTE_ORDER == __PDP_ENDIAN)
#           undef AGPACK_ENDIAN_LITTLE_WORD
#           define AGPACK_ENDIAN_LITTLE_WORD AGPACK_VERSION_NUMBER_AVAILABLE
#       endif
#   endif
#   if !defined(__BYTE_ORDER) && defined(_BYTE_ORDER)
#       if defined(_BIG_ENDIAN) && (_BYTE_ORDER == _BIG_ENDIAN)
#           undef AGPACK_ENDIAN_BIG_BYTE
#           define AGPACK_ENDIAN_BIG_BYTE AGPACK_VERSION_NUMBER_AVAILABLE
#       endif
#       if defined(_LITTLE_ENDIAN) && (_BYTE_ORDER == _LITTLE_ENDIAN)
#           undef AGPACK_ENDIAN_LITTLE_BYTE
#           define AGPACK_ENDIAN_LITTLE_BYTE AGPACK_VERSION_NUMBER_AVAILABLE
#       endif
#       if defined(_PDP_ENDIAN) && (_BYTE_ORDER == _PDP_ENDIAN)
#           undef AGPACK_ENDIAN_LITTLE_WORD
#           define AGPACK_ENDIAN_LITTLE_WORD AGPACK_VERSION_NUMBER_AVAILABLE
#       endif
#   endif
#endif

/* Built-in byte-swpped big-endian macros.
 */
#if !AGPACK_ENDIAN_BIG_BYTE && !AGPACK_ENDIAN_BIG_WORD && \
    !AGPACK_ENDIAN_LITTLE_BYTE && !AGPACK_ENDIAN_LITTLE_WORD
#   if (defined(__BIG_ENDIAN__) && !defined(__LITTLE_ENDIAN__)) || \
       (defined(_BIG_ENDIAN) && !defined(_LITTLE_ENDIAN)) || \
        defined(__ARMEB__) || \
        defined(__THUMBEB__) || \
        defined(__AARCH64EB__) || \
        defined(_MIPSEB) || \
        defined(__MIPSEB) || \
        defined(__MIPSEB__)
#       undef AGPACK_ENDIAN_BIG_BYTE
#       define AGPACK_ENDIAN_BIG_BYTE AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

/* Built-in byte-swpped little-endian macros.
 */
#if !AGPACK_ENDIAN_BIG_BYTE && !AGPACK_ENDIAN_BIG_WORD && \
    !AGPACK_ENDIAN_LITTLE_BYTE && !AGPACK_ENDIAN_LITTLE_WORD
#   if (defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)) || \
       (defined(_LITTLE_ENDIAN) && !defined(_BIG_ENDIAN)) || \
        defined(__ARMEL__) || \
        defined(__THUMBEL__) || \
        defined(__AARCH64EL__) || \
        defined(_MIPSEL) || \
        defined(__MIPSEL) || \
        defined(__MIPSEL__)
#       undef AGPACK_ENDIAN_LITTLE_BYTE
#       define AGPACK_ENDIAN_LITTLE_BYTE AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

/* Some architectures are strictly one endianess (as opposed
 * the current common bi-endianess).
 */
#if !AGPACK_ENDIAN_BIG_BYTE && !AGPACK_ENDIAN_BIG_WORD && \
    !AGPACK_ENDIAN_LITTLE_BYTE && !AGPACK_ENDIAN_LITTLE_WORD
#   include <agpack/predef/architecture.h>
#   if AGPACK_ARCH_M68K || \
        AGPACK_ARCH_PARISC || \
        AGPACK_ARCH_SPARC || \
        AGPACK_ARCH_SYS370 || \
        AGPACK_ARCH_SYS390 || \
        AGPACK_ARCH_Z
#       undef AGPACK_ENDIAN_BIG_BYTE
#       define AGPACK_ENDIAN_BIG_BYTE AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#   if AGPACK_ARCH_IA64 || \
        AGPACK_ARCH_X86 || \
        AGPACK_ARCH_BLACKFIN
#       undef AGPACK_ENDIAN_LITTLE_BYTE
#       define AGPACK_ENDIAN_LITTLE_BYTE AGPACK_VERSION_NUMBER_AVAILABLE
#   endif
#endif

/* Windows on ARM, if not otherwise detected/specified, is always
 * byte-swaped little-endian.
 */
#if !AGPACK_ENDIAN_BIG_BYTE && !AGPACK_ENDIAN_BIG_WORD && \
    !AGPACK_ENDIAN_LITTLE_BYTE && !AGPACK_ENDIAN_LITTLE_WORD
#   if AGPACK_ARCH_ARM
#       include <agpack/predef/os/windows.h>
#       if AGPACK_OS_WINDOWS
#           undef AGPACK_ENDIAN_LITTLE_BYTE
#           define AGPACK_ENDIAN_LITTLE_BYTE AGPACK_VERSION_NUMBER_AVAILABLE
#       endif
#   endif
#endif

#if AGPACK_ENDIAN_BIG_BYTE
#   define AGPACK_ENDIAN_BIG_BYTE_AVAILABLE
#endif
#if AGPACK_ENDIAN_BIG_WORD
#   define AGPACK_ENDIAN_BIG_WORD_BYTE_AVAILABLE
#endif
#if AGPACK_ENDIAN_LITTLE_BYTE
#   define AGPACK_ENDIAN_LITTLE_BYTE_AVAILABLE
#endif
#if AGPACK_ENDIAN_LITTLE_WORD
#   define AGPACK_ENDIAN_LITTLE_WORD_BYTE_AVAILABLE
#endif

#define AGPACK_ENDIAN_BIG_BYTE_NAME "Byte-Swapped Big-Endian"
#define AGPACK_ENDIAN_BIG_WORD_NAME "Word-Swapped Big-Endian"
#define AGPACK_ENDIAN_LITTLE_BYTE_NAME "Byte-Swapped Little-Endian"
#define AGPACK_ENDIAN_LITTLE_WORD_NAME "Word-Swapped Little-Endian"

#endif

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ENDIAN_BIG_BYTE,AGPACK_ENDIAN_BIG_BYTE_NAME)

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ENDIAN_BIG_WORD,AGPACK_ENDIAN_BIG_WORD_NAME)

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ENDIAN_LITTLE_BYTE,AGPACK_ENDIAN_LITTLE_BYTE_NAME)

#include <agpack/predef/detail/test.h>
AGPACK_PREDEF_DECLARE_TEST(AGPACK_ENDIAN_LITTLE_WORD,AGPACK_ENDIAN_LITTLE_WORD_NAME)
