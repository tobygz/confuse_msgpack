//
// MessagePack for C++ deserializing routine
//
// Copyright (C) 2018 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V2_X3_UNPACK_DECL_HPP
#define AGPACK_V2_X3_UNPACK_DECL_HPP

#if defined(AGPACK_USE_X3_PARSE)

#include "agpack/versioning.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

namespace detail {

template <typename Iterator>
void
unpack_imp(Iterator&& begin, Iterator&& end,
           agpack::zone& result_zone, agpack::object& result, bool& referenced,
           unpack_reference_func f = AGPACK_NULLPTR, void* user_data = AGPACK_NULLPTR,
           unpack_limit const& limit = unpack_limit());

} // namespace detail

template <typename Iterator>
agpack::object_handle unpack(
    Iterator&& begin, Iterator&& end,
    bool& referenced,
    unpack_reference_func f = AGPACK_NULLPTR, void* user_data = AGPACK_NULLPTR,
    unpack_limit const& limit = unpack_limit());

template <typename Iterator>
agpack::object_handle unpack(
    Iterator&& begin, Iterator&& end,
    unpack_reference_func f = AGPACK_NULLPTR, void* user_data = AGPACK_NULLPTR,
    unpack_limit const& limit = unpack_limit());

template <typename Iterator>
agpack::object unpack(
    agpack::zone& z,
    Iterator&& begin, Iterator&& end,
    bool& referenced,
    unpack_reference_func f = AGPACK_NULLPTR, void* user_data = AGPACK_NULLPTR,
    unpack_limit const& limit = unpack_limit());

template <typename Iterator>
agpack::object unpack(
    agpack::zone& z,
    Iterator&& begin, Iterator&& end,
    unpack_reference_func f = AGPACK_NULLPTR, void* user_data = AGPACK_NULLPTR,
    unpack_limit const& limit = unpack_limit());

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

}  // namespace agpack


#endif // defined(AGPACK_USE_X3_PARSE)

#endif // AGPACK_V2_X3_UNPACK_DECL_HPP
