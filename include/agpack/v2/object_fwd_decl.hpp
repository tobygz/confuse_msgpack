//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AGPACK_V2_OBJECT_FWD_DECL_HPP
#define AGPACK_V2_OBJECT_FWD_DECL_HPP

#include "agpack/v1/object_fwd_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

namespace type {
using v1::type::object_type;
using v1::type::NIL;
using v1::type::BOOLEAN;
using v1::type::POSITIVE_INTEGER;
using v1::type::NEGATIVE_INTEGER;
using v1::type::FLOAT32;
using v1::type::FLOAT64;
using v1::type::FLOAT;
#if defined(AGPACK_USE_LEGACY_NAME_AS_FLOAT)
using v1::type::DOUBLE;
#endif // AGPACK_USE_LEGACY_NAME_AS_FLOAT
using v1::type::STR;
using v1::type::BIN;
using v1::type::ARRAY;
using v1::type::MAP;
using v1::type::EXT;
} // namespace type

struct object;

using v1::object_kv;

using v1::object_array;
using v1::object_map;

using v1::object_str;
using v1::object_bin;
using v1::object_ext;

using v1::type_error;


#if !defined(AGPACK_USE_CPP03)

namespace adaptor {

template <typename T, typename Enabler = void>
struct as;

} // namespace adaptor

template <typename T>
struct has_as;

#endif // !defined(AGPACK_USE_CPP03)

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

} // namespace agpack

#endif // AGPACK_V2_OBJECT_FWD_DECL_HPP
