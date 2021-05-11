//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2018 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_CARRAY_BYTE_HPP
#define AGPACK_V1_TYPE_CARRAY_BYTE_HPP

#if __cplusplus >= 201703

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <cstring>
#include <cstddef>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <std::size_t N>
struct convert<std::byte[N]> {
    agpack::object const& operator()(agpack::object const& o, std::byte(&v)[N]) const {
        switch (o.type) {
        case agpack::type::BIN:
            if (o.via.bin.size > N) { throw agpack::type_error(); }
            std::memcpy(v, o.via.bin.ptr, o.via.bin.size);
            break;
        case agpack::type::STR:
            if (o.via.str.size > N) { throw agpack::type_error(); }
            std::memcpy(v, o.via.str.ptr, o.via.str.size);
            if (o.via.str.size < N) v[o.via.str.size] = std::byte{'\0'};
            break;
        default:
            throw agpack::type_error();
            break;
        }
        return o;
    }
};

template <std::size_t N>
struct pack<std::byte[N]> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::byte(&v)[N]) const {
        std::byte const* p = v;
        uint32_t size = checked_get_container_size(N);
        o.pack_bin(size);
        o.pack_bin_body(reinterpret_cast<char const*>(p), size);
        return o;
    }
};

template <std::size_t N>
struct pack<const std::byte[N]> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::byte(&v)[N]) const {
        std::byte const* p = v;
        uint32_t size = checked_get_container_size(N);
        o.pack_bin(size);
        o.pack_bin_body(reinterpret_cast<char const*>(p), size);
        return o;
    }
};

template <std::size_t N>
struct object_with_zone<std::byte[N]> {
    void operator()(agpack::object::with_zone& o, const std::byte(&v)[N]) const {
        uint32_t size = checked_get_container_size(N);
        o.type = agpack::type::BIN;
        char* ptr = static_cast<char*>(o.zone.allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
        o.via.bin.ptr = ptr;
        o.via.bin.size = size;
        std::memcpy(ptr, v, size);
    }
};

template <std::size_t N>
struct object_with_zone<const std::byte[N]> {
    void operator()(agpack::object::with_zone& o, const std::byte(&v)[N]) const {
        uint32_t size = checked_get_container_size(N);
        o.type = agpack::type::BIN;
        char* ptr = static_cast<char*>(o.zone.allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
        o.via.bin.ptr = ptr;
        o.via.bin.size = size;
        std::memcpy(ptr, v, size);
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // __cplusplus >= 201703

#endif // AGPACK_V1_TYPE_CARRAY_BYTE_HPP
