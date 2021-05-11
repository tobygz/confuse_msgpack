//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2014-2015 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AGPACK_V1_TYPE_CPP11_ARRAY_HPP
#define AGPACK_V1_TYPE_CPP11_ARRAY_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"
#include "agpack/meta.hpp"

#include <array>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

namespace detail {

namespace array {

template<typename T, std::size_t N1, std::size_t... I1, std::size_t N2, std::size_t... I2>
inline std::array<T, N1+N2> concat(
    std::array<T, N1>&& a1,
    std::array<T, N2>&& a2,
    agpack::seq<I1...>,
    agpack::seq<I2...>) {
    return {{ std::move(a1[I1])..., std::move(a2[I2])... }};
}

template<typename T, std::size_t N1, std::size_t N2>
inline std::array<T, N1+N2> concat(std::array<T, N1>&& a1, std::array<T, N2>&& a2) {
    return concat(std::move(a1), std::move(a2), agpack::gen_seq<N1>(), agpack::gen_seq<N2>());
}

template <typename T, std::size_t N>
struct as_impl {
    static std::array<T, N> as(agpack::object const& o) {
        agpack::object* p = o.via.array.ptr + N - 1;
        return concat(as_impl<T, N-1>::as(o), std::array<T, 1>{{p->as<T>()}});
    }
};

template <typename T>
struct as_impl<T, 1> {
    static std::array<T, 1> as(agpack::object const& o) {
        agpack::object* p = o.via.array.ptr;
        return std::array<T, 1>{{p->as<T>()}};
    }
};

template <typename T>
struct as_impl<T, 0> {
    static std::array<T, 0> as(agpack::object const&) {
        return std::array<T, 0>();
    }
};

} // namespace array

} // namespace detail

template <typename T, std::size_t N>
struct as<std::array<T, N>, typename std::enable_if<agpack::has_as<T>::value>::type> {
    std::array<T, N> operator()(agpack::object const& o) const {
        if(o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        if(o.via.array.size > N) { throw agpack::type_error(); }
        return detail::array::as_impl<T, N>::as(o);
    }
};

template <typename T, std::size_t N>
struct convert<std::array<T, N>> {
    agpack::object const& operator()(agpack::object const& o, std::array<T, N>& v) const {
        if(o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        if(o.via.array.size > N) { throw agpack::type_error(); }
        if(o.via.array.size > 0) {
            agpack::object* p = o.via.array.ptr;
            agpack::object* const pend = o.via.array.ptr + o.via.array.size;
            T* it = &v[0];
            do {
                p->convert(*it);
                ++p;
                ++it;
            } while(p < pend);
        }
        return o;
    }
};

template <typename T, std::size_t N>
struct pack<std::array<T, N>> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::array<T, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_array(size);
        for(auto const& e : v) o.pack(e);
        return o;
    }
};

template <typename T, std::size_t N>
struct object_with_zone<std::array<T, N>> {
    void operator()(agpack::object::with_zone& o, const std::array<T, N>& v) const {
        o.type = agpack::type::ARRAY;
        if(v.empty()) {
            o.via.array.ptr = AGPACK_NULLPTR;
            o.via.array.size = 0;
        } else {
            uint32_t size = checked_get_container_size(v.size());
            agpack::object* p = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object)*size, AGPACK_ZONE_ALIGNOF(agpack::object)));
            o.via.array.size = size;
            o.via.array.ptr = p;
            for (auto const& e : v) *p++ = agpack::object(e, o.zone);
        }
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_CPP11_ARRAY_HPP
