//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_NIL_DECL_HPP
#define AGPACK_V1_TYPE_NIL_DECL_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

struct nil_t;

#if !defined(AGPACK_DISABLE_LEGACY_NIL)

typedef nil_t nil;

#endif // !defined(AGPACK_DISABLE_LEGACY_NIL)

bool operator<(nil_t const& lhs, nil_t const& rhs);

bool operator==(nil_t const& lhs, nil_t const& rhs);

}  // namespace type

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_TYPE_NIL_DECL_HPP
