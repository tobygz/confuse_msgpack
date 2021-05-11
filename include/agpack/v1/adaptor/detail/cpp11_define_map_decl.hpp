//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_CPP11_DEFINE_MAP_DECL_HPP
#define AGPACK_V1_CPP11_DEFINE_MAP_DECL_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"

namespace agpack {
/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond
namespace type {

template <typename Tuple, std::size_t N>
struct define_map_imp;

template <typename... Args>
struct define_map;

template <typename... Args>
define_map<Args...> make_define_map(Args&... args);

}  // namespace type
/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond
}  // namespace agpack

#endif // AGPACK_V1_CPP11_DEFINE_MAP_DECL_HPP
