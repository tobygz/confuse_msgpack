//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2018 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_OBJECT_DECL_HPP
#define AGPACK_V3_OBJECT_DECL_HPP

#include "agpack/v2/object_decl.hpp"
#include "agpack/adaptor/adaptor_base.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

using v2::object_handle;

namespace detail {

using v2::detail::add_ext_type_size;

} // namespace detail

using v2::aligned_zone_size;

using v2::clone;

namespace detail {

using v2::detail::packer_serializer;

} // namespace detail

using v2::object_parser;
using v2::object_pack_visitor;
using v2::object_stringize_visitor;

using v2::operator==;
using v2::operator!=;

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V3_OBJECT_DECL_HPP
