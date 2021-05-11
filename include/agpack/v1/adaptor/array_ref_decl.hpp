//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_ARRAY_REF_DECL_HPP
#define AGPACK_V1_TYPE_ARRAY_REF_DECL_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

template <typename T>
struct array_ref;

template <typename T>
typename agpack::enable_if<
    !agpack::is_array<T const>::value,
    array_ref<T const>
>::type
make_array_ref(T const& t);

template <typename T>
typename agpack::enable_if<
    !agpack::is_array<T>::value,
    array_ref<T>
>::type
make_array_ref(T& t);

template <typename T, std::size_t N>
array_ref<const T[N]> make_array_ref(const T(&t)[N]);

template <typename T, std::size_t N>
array_ref<T[N]> make_array_ref(T(&t)[N]);

} // namespace type

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_ARRAY_REF_DECL_HPP
