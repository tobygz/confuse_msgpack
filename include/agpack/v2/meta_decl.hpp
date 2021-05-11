//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2015-2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AGPACK_V2_META_DECL_HPP
#define AGPACK_V2_META_DECL_HPP

#if !defined(AGPACK_USE_CPP03)

#include "agpack/v1/meta_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

namespace detail {

using v1::detail::bool_pack;

using v1::detail::all_of_imp;

using v1::detail::any_of_imp;

} // namespace detail

using v1::all_of;

using v1::any_of;

using v1::seq;

using v1::gen_seq;

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

} // namespace agpack

#endif // !defined(AGPACK_USE_CPP03)

#endif // AGPACK_V2_META_DECL_HPP
