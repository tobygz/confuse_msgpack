//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V2_CPP03_AGPACK_TUPLE_DECL_HPP
#define AGPACK_V2_CPP03_AGPACK_TUPLE_DECL_HPP

#include "agpack/v1/adaptor/detail/cpp03_agpack_tuple_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

namespace type {

using v1::type::tuple;

using v1::type::tuple_element;

using v1::type::const_tuple_element;

using v1::type::tuple_type;

using v1::type::get;

using v1::type::make_tuple;

}  // namespace type

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V2_CPP03_AGPACK_TUPLE_DECL_HPP
