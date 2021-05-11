//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2015-2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_ADAPTOR_BASE_HPP
#define AGPACK_V1_ADAPTOR_BASE_HPP

#include "agpack/v1/adaptor/adaptor_base_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond


namespace adaptor {

// Adaptor functors

template <typename T, typename Enabler>
struct convert {
    agpack::object const& operator()(agpack::object const& o, T& v) const;
};

template <typename T, typename Enabler>
struct pack {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, T const& v) const;
};

template <typename T, typename Enabler>
struct object {
    void operator()(agpack::object& o, T const& v) const;
};

template <typename T, typename Enabler>
struct object_with_zone {
    void operator()(agpack::object::with_zone& o, T const& v) const;
};

} // namespace adaptor

// operators

template <typename T>
inline
typename agpack::enable_if<
    !is_array<T>::value,
    agpack::object const&
>::type
operator>> (agpack::object const& o, T& v) {
    return agpack::adaptor::convert<T>()(o, v);
}
template <typename T, std::size_t N>
inline
agpack::object const& operator>> (agpack::object const& o, T(&v)[N]) {
    return agpack::adaptor::convert<T[N]>()(o, v);
}

template <typename Stream, typename T>
inline
typename agpack::enable_if<
    !is_array<T>::value,
    agpack::packer<Stream>&
>::type
operator<< (agpack::packer<Stream>& o, T const& v) {
    return agpack::adaptor::pack<T>()(o, v);
}
template <typename Stream, typename T, std::size_t N>
inline
agpack::packer<Stream>& operator<< (agpack::packer<Stream>& o, const T(&v)[N]) {
    return agpack::adaptor::pack<T[N]>()(o, v);
}

template <typename T>
inline
typename agpack::enable_if<
    !is_array<T>::value
>::type
operator<< (agpack::object& o, T const& v) {
    agpack::adaptor::object<T>()(o, v);
}
template <typename T, std::size_t N>
inline
void operator<< (agpack::v1::object& o, const T(&v)[N]) {
    agpack::v1::adaptor::object<T[N]>()(o, v);
}

template <typename T>
inline
typename agpack::enable_if<
    !is_array<T>::value
>::type
operator<< (agpack::object::with_zone& o, T const& v) {
    agpack::adaptor::object_with_zone<T>()(o, v);
}
template <typename T, std::size_t N>
inline
void operator<< (agpack::object::with_zone& o, const T(&v)[N]) {
    agpack::adaptor::object_with_zone<T[N]>()(o, v);
}

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack


#endif // AGPACK_V1_ADAPTOR_BASE_HPP
