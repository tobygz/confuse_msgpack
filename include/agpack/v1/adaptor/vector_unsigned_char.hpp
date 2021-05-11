//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2014-2015 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_VECTOR_UNSIGNED_CHAR_HPP
#define AGPACK_V1_TYPE_VECTOR_UNSIGNED_CHAR_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <vector>
#include <cstring>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <typename Alloc>
struct convert<std::vector<unsigned char, Alloc> > {
    agpack::object const& operator()(agpack::object const& o, std::vector<unsigned char, Alloc>& v) const {
        switch (o.type) {
        case agpack::type::BIN:
            v.resize(o.via.bin.size);
            if (o.via.bin.size != 0) {
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
                std::memcpy(&v.front(), o.via.bin.ptr, o.via.bin.size);
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
            }
            break;
        case agpack::type::STR:
            v.resize(o.via.str.size);
            if (o.via.str.size != 0) {
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
                std::memcpy(&v.front(), o.via.str.ptr, o.via.str.size);
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
            }
            break;
        default:
            throw agpack::type_error();
            break;
        }
        return o;
    }
};

template <typename Alloc>
struct pack<std::vector<unsigned char, Alloc> > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::vector<unsigned char, Alloc>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_bin(size);
        if (size != 0) {
            o.pack_bin_body(reinterpret_cast<char const*>(&v.front()), size);
        }

        return o;
    }
};

template <typename Alloc>
struct object<std::vector<unsigned char, Alloc> > {
    void operator()(agpack::object& o, const std::vector<unsigned char, Alloc>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.type = agpack::type::BIN;
        if (size != 0) {
            o.via.bin.ptr = reinterpret_cast<char const*>(&v.front());
        }
        o.via.bin.size = size;
    }
};

template <typename Alloc>
struct object_with_zone<std::vector<unsigned char, Alloc> > {
    void operator()(agpack::object::with_zone& o, const std::vector<unsigned char, Alloc>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.type = agpack::type::BIN;
        o.via.bin.size = size;
        if (size != 0) {
            char* ptr = static_cast<char*>(o.zone.allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
            o.via.bin.ptr = ptr;
            std::memcpy(ptr, &v.front(), size);
        }
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_VECTOR_UNSIGNED_CHAR_HPP
