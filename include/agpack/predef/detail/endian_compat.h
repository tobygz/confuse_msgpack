/*
Copyright Rene Rivera 2013
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef AGPACK_PREDEF_DETAIL_ENDIAN_COMPAT_H
#define AGPACK_PREDEF_DETAIL_ENDIAN_COMPAT_H

#include <agpack/predef/other/endian.h>

#if AGPACK_ENDIAN_BIG_BYTE
#   define AGPACK_BIG_ENDIAN
#   define AGPACK_BYTE_ORDER 4321
#endif
#if AGPACK_ENDIAN_LITTLE_BYTE
#   define AGPACK_LITTLE_ENDIAN
#   define AGPACK_BYTE_ORDER 1234
#endif
#if AGPACK_ENDIAN_LITTLE_WORD
#   define AGPACK_PDP_ENDIAN
#   define AGPACK_BYTE_ORDER 2134
#endif

#endif
