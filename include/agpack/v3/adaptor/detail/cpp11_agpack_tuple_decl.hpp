//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_CPP11_AGPACK_TUPLE_DECL_HPP
#define AGPACK_V3_CPP11_AGPACK_TUPLE_DECL_HPP

#include "agpack/v2/adaptor/detail/cpp11_agpack_tuple_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

namespace type {

using v2::type::get;
using v2::type::tuple_size;
using v2::type::tuple_element;
using v2::type::uses_allocator;
using v2::type::ignore;
using v2::type::swap;

using v2::type::tuple;

using v2::type::make_tuple;
using v2::type::forward_as_tuple;
using v2::type::tuple_cat;
using v2::type::tie;

} // namespace type

// --- Pack from tuple to packer stream ---

using v2::MsgpackTuplePacker;

// --- Convert from tuple to object ---
using v2::MsgpackTupleAs;

using v2::MsgpackTupleAsImpl;

using v2::MsgpackTupleConverter;

// --- Convert from tuple to object with zone ---
using v2::MsgpackTupleToObjectWithZone;

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v3)
///@endcond

}  // namespace agpack

#endif // AGPACK_V3_CPP11_AGPACK_TUPLE_DECL_HPP
