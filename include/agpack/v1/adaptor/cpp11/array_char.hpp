//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2014-2015 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_CPP11_ARRAY_CHAR_HPP
#define AGPACK_V1_TYPE_CPP11_ARRAY_CHAR_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <array>
#include <cstring>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <std::size_t N>
struct convert<std::array<char, N>> {
    agpack::object const& operator()(agpack::object const& o, std::array<char, N>& v) const {
        switch (o.type) {
        case agpack::type::BIN:
            if(o.via.bin.size > N) { throw agpack::type_error(); }
            std::memcpy(v.data(), o.via.bin.ptr, o.via.bin.size);
            break;
        case agpack::type::STR:
            if(o.via.str.size > N) { throw agpack::type_error(); }
            std::memcpy(v.data(), o.via.str.ptr, N);
            break;
        default:
            throw agpack::type_error();
            break;
        }
        return o;
    }
};

template <>
struct convert<std::array<char, 0>> {
    agpack::object const& operator()(agpack::object const& o, std::array<char, 0>&) const {
        return o;
    }
};

template <std::size_t N>
struct pack<std::array<char, N>> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::array<char, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_bin(size);
        o.pack_bin_body(v.data(), size);

        return o;
    }
};

template <std::size_t N>
struct object<std::array<char, N>> {
    void operator()(agpack::object& o, const std::array<char, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.type = agpack::type::BIN;
        o.via.bin.ptr = v.data();
        o.via.bin.size = size;
    }
};

template <std::size_t N>
struct object_with_zone<std::array<char, N>> {
    void operator()(agpack::object::with_zone& o, const std::array<char, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.type = agpack::type::BIN;
        char* ptr = static_cast<char*>(o.zone.allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
        o.via.bin.ptr = ptr;
        o.via.bin.size = size;
        std::memcpy(ptr, v.data(), size);
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_CPP11_ARRAY_CHAR_HPP
