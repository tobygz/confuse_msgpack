//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_CPP11_DEFINE_ARRAY_DECL_HPP
#define AGPACK_V3_CPP11_DEFINE_ARRAY_DECL_HPP

#include "agpack/v2/adaptor/detail/cpp11_define_array_decl.hpp"

namespace agpack {
/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond
namespace type {

using v2::type::define_array_imp;
using v2::type::define_array;

using v2::type::make_define_array;

}  // namespace type
/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond
}  // namespace agpack

#endif // AGPACK_V3_CPP11_DEFINE_ARRAY_DECL_HPP
