//
// MessagePack for C++ deserializing routine
//
// Copyright (C) 2018 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_CREATE_OBJECT_VISITOR_DECL_HPP
#define AGPACK_V3_CREATE_OBJECT_VISITOR_DECL_HPP

#include "agpack/v2/create_object_visitor_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

namespace detail {

using v2::detail::create_object_visitor;

} // detail

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V3_CREATE_OBJECT_VISITOR_DECL_HPP
