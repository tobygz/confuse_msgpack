//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_ADAPTOR_BASE_DECL_HPP
#define AGPACK_V1_ADAPTOR_BASE_DECL_HPP

#include "agpack/versioning.hpp"
#include "agpack/object_fwd.hpp"
#include "agpack/pack.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

template <typename Stream>
class packer;

namespace adaptor {

// Adaptor functors

template <typename T, typename Enabler = void>
struct convert;

template <typename T, typename Enabler = void>
struct pack;

template <typename T, typename Enabler = void>
struct object;

template <typename T, typename Enabler = void>
struct object_with_zone;

} // namespace adaptor

// operators

template <typename T>
typename agpack::enable_if<
    !is_array<T>::value,
    agpack::object const&
>::type
operator>> (agpack::object const& o, T& v);
template <typename T, std::size_t N>
agpack::object const& operator>> (agpack::object const& o, T(&v)[N]);

template <typename Stream, typename T>
typename agpack::enable_if<
    !is_array<T>::value,
    agpack::packer<Stream>&
>::type
operator<< (agpack::packer<Stream>& o, T const& v);
template <typename Stream, typename T, std::size_t N>
agpack::packer<Stream>& operator<< (agpack::packer<Stream>& o, const T(&v)[N]);

template <typename T>
typename agpack::enable_if<
    !is_array<T>::value
>::type
operator<< (agpack::object& o, T const& v);
template <typename T, std::size_t N>
void operator<< (agpack::object& o, const T(&v)[N]);

template <typename T>
typename agpack::enable_if<
    !is_array<T>::value
>::type
operator<< (agpack::object::with_zone& o, T const& v);
template <typename T, std::size_t N>
void operator<< (agpack::object::with_zone& o, const T(&v)[N]);

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_ADAPTOR_BASE_DECL_HPP
