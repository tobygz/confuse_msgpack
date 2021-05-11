//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_CPP03_AGPACK_TUPLE_DECL_HPP
#define AGPACK_V3_CPP03_AGPACK_TUPLE_DECL_HPP

#include "agpack/v2/adaptor/detail/cpp03_agpack_tuple_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

namespace type {

using v2::type::tuple;

using v2::type::tuple_element;

using v2::type::const_tuple_element;

using v2::type::tuple_type;

using v2::type::get;

using v2::type::make_tuple;

}  // namespace type

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V3_CPP03_AGPACK_TUPLE_DECL_HPP
