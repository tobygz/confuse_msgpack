//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_MAP_DECL_HPP
#define AGPACK_V1_TYPE_MAP_DECL_HPP

#include "agpack/versioning.hpp"

#include <algorithm>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

template <typename K, typename V, typename Compare = std::less<K>, typename Alloc = std::allocator<std::pair<K, V> > >
class assoc_vector;

}  //namespace type

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_TYPE_MAP_DECL_HPP
