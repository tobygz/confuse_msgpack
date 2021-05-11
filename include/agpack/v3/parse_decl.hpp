//
// MessagePack for C++ deserializing routine
//
// Copyright (C) 2018-2017 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_PARSE_DECL_HPP
#define AGPACK_V3_PARSE_DECL_HPP

#include "agpack/v2/parse_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

namespace detail {

template <typename VisitorHolder>
class context;

} // detail

using v2::parser;
using v2::parse;

namespace detail {

template <typename Visitor>
struct parse_helper;

template <typename Visitor>
inline parse_return
parse_imp(const char* data, size_t len, size_t& off, Visitor& v);

} // detail

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

}  // namespace agpack


#endif // AGPACK_V3_PARSE_DECL_HPP
