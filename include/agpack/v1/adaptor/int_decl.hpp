//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_INT_DECL_HPP
#define AGPACK_V1_TYPE_INT_DECL_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include <limits>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1){
/// @endcond

namespace type {
namespace detail {

template <typename T, bool Signed>
struct convert_integer_sign;

template <typename T>
struct is_signed;

template <typename T>
T convert_integer(agpack::object const& o);

template <bool Signed>
struct object_sign;

template <typename T>
void object_char(agpack::object& o, T v);

}  // namespace detail
}  // namespace type

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_TYPE_INT_DECL_HPP
