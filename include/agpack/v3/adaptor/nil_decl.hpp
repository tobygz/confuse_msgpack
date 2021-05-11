//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_TYPE_NIL_DECL_HPP
#define AGPACK_V3_TYPE_NIL_DECL_HPP

#include "agpack/v2/adaptor/nil_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

namespace type {

using v2::type::nil_t;

#if defined(AGPACK_USE_LEGACY_NIL)

typedef nil_t nil;

#endif // defined(AGPACK_USE_LEGACY_NIL)

using v2::type::operator<;
using v2::type::operator==;

}  // namespace type

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V3_TYPE_NIL_DECL_HPP
