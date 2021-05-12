//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V2_TYPE_BOOST_AGPACK_VARIANT_DECL_HPP
#define AGPACK_V2_TYPE_BOOST_AGPACK_VARIANT_DECL_HPP

#if defined(AGPACK_USE_BOOST)

#include "agpack/v1/adaptor/boost/agpack_variant_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

namespace type {

using v1::type::basic_variant;
using v1::type::variant;
using v1::type::variant_ref;

using v1::type::operator<;

using v1::type::operator==;

} // namespace type

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

} // namespace agpack

#endif // AGPACK_USE_BOOST
#endif // AGPACK_V2_TYPE_BOOST_AGPACK_VARIANT_DECL_HPP
