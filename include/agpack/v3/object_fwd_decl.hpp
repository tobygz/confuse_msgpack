//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2018 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AGPACK_V3_OBJECT_FWD_DECL_HPP
#define AGPACK_V3_OBJECT_FWD_DECL_HPP

#include "agpack/v2/object_fwd_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

namespace type {
using v2::type::object_type;
using v2::type::NIL;
using v2::type::BOOLEAN;
using v2::type::POSITIVE_INTEGER;
using v2::type::NEGATIVE_INTEGER;
using v2::type::FLOAT32;
using v2::type::FLOAT64;
using v2::type::FLOAT;
#if defined(AGPACK_USE_LEGACY_NAME_AS_FLOAT)
using v2::type::DOUBLE;
#endif // AGPACK_USE_LEGACY_NAME_AS_FLOAT
using v2::type::STR;
using v2::type::BIN;
using v2::type::ARRAY;
using v2::type::MAP;
using v2::type::EXT;
} // namespace type

using v2::object;

using v2::object_kv;

using v2::object_array;
using v2::object_map;

using v2::object_str;
using v2::object_bin;
using v2::object_ext;

using v2::type_error;


#if !defined(AGPACK_USE_CPP03)

namespace adaptor {

template <typename T, typename Enabler = void>
struct as;

} // namespace adaptor

template <typename T>
struct has_as;

#endif // !defined(AGPACK_USE_CPP03)

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

} // namespace agpack

#endif // AGPACK_V3_OBJECT_FWD_DECL_HPP
