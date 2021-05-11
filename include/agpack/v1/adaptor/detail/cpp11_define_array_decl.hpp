//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_CPP11_DEFINE_ARRAY_DECL_HPP
#define AGPACK_V1_CPP11_DEFINE_ARRAY_DECL_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"

namespace agpack {
/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond
namespace type {

template <typename Tuple, std::size_t N>
struct define_array_imp;

template <typename... Args>
struct define_array;

define_array<> make_define_array();

template <typename... Args>
inline define_array<Args...> make_define_array(Args&... args);

}  // namespace type
/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond
}  // namespace agpack

#endif // AGPACK_V1_CPP11_DEFINE_ARRAY_DECL_HPP
