//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_ADAPTOR_BASE_DECL_HPP
#define AGPACK_V3_ADAPTOR_BASE_DECL_HPP

#include "agpack/v2/adaptor/adaptor_base_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

using v2::packer;

namespace adaptor {

// Adaptor functors

template <typename T, typename Enabler = void>
struct convert;

template <typename T, typename Enabler = void>
struct pack;

template <typename T, typename Enabler = void, typename Enabler2 = void>
struct object;

template <typename T, typename Enabler = void>
struct object_with_zone;

} // namespace adaptor

// operators

using v2::operator>>;
using v2::operator<<;

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

} // namespace agpack

#endif // AGPACK_V3_ADAPTOR_BASE_DECL_HPP
