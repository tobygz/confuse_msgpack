//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AGPACK_V1_OBJECT_FWD_DECL_HPP
#define AGPACK_V1_OBJECT_FWD_DECL_HPP

#include "agpack/versioning.hpp"
#include "agpack/zone.hpp"
#include "agpack/object.h"

#include <typeinfo>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond


namespace type {
    enum object_type {
        NIL                 = AGPACK_OBJECT_NIL,
        BOOLEAN             = AGPACK_OBJECT_BOOLEAN,
        POSITIVE_INTEGER    = AGPACK_OBJECT_POSITIVE_INTEGER,
        NEGATIVE_INTEGER    = AGPACK_OBJECT_NEGATIVE_INTEGER,
        FLOAT32             = AGPACK_OBJECT_FLOAT32,
        FLOAT64             = AGPACK_OBJECT_FLOAT64,
        FLOAT               = AGPACK_OBJECT_FLOAT,
#if defined(AGPACK_USE_LEGACY_NAME_AS_FLOAT)
        DOUBLE              = AGPACK_DEPRECATED("please use FLOAT64 instead") AGPACK_OBJECT_DOUBLE, // obsolete
#endif // AGPACK_USE_LEGACY_NAME_AS_FLOAT
        STR                 = AGPACK_OBJECT_STR,
        BIN                 = AGPACK_OBJECT_BIN,
        ARRAY               = AGPACK_OBJECT_ARRAY,
        MAP                 = AGPACK_OBJECT_MAP,
        EXT                 = AGPACK_OBJECT_EXT
    };
}


struct object;
struct object_kv;

struct object_array;
struct object_map;
struct object_str;
struct object_bin;
struct object_ext;


#if !defined(AGPACK_USE_CPP03)

namespace adaptor {
template <typename T, typename Enabler = void>
struct as;
} // namespace adaptor

template <typename T>
struct has_as;

#endif // !defined(AGPACK_USE_CPP03)

class type_error;

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_OBJECT_FWD_DECL_HPP
