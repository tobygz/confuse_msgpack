//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_CARRAY_HPP
#define AGPACK_V1_TYPE_CARRAY_HPP

#include "agpack/versioning.hpp"
#include "agpack/object_fwd.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <typename T, std::size_t N>
struct convert<T[N]> {
    agpack::object const& operator()(agpack::object const& o, T* v) const {
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        if (o.via.array.size > N) { throw agpack::type_error(); }
        agpack::object* p = o.via.array.ptr;
        agpack::object* const pend = o.via.array.ptr + o.via.array.size;
        do {
            p->convert(*v);
            ++p;
            ++v;
        } while(p < pend);
        return o;
    }
};

template <std::size_t N>
struct convert<char[N]> {
    agpack::object const& operator()(agpack::object const& o, char(&v)[N]) const {
        switch (o.type) {
        case agpack::type::BIN:
            if (o.via.bin.size > N) { throw agpack::type_error(); }
            std::memcpy(v, o.via.bin.ptr, o.via.bin.size);
            break;
        case agpack::type::STR:
            if (o.via.str.size > N) { throw agpack::type_error(); }
            std::memcpy(v, o.via.str.ptr, o.via.str.size);
            if (o.via.str.size < N) v[o.via.str.size] = '\0';
            break;
        default:
            throw agpack::type_error();
            break;
        }
        return o;
    }
};

template <std::size_t N>
struct convert<unsigned char[N]> {
    agpack::object const& operator()(agpack::object const& o, unsigned char(&v)[N]) const {
        switch (o.type) {
        case agpack::type::BIN:
            if (o.via.bin.size > N) { throw agpack::type_error(); }
            std::memcpy(v, o.via.bin.ptr, o.via.bin.size);
            break;
        case agpack::type::STR:
            if (o.via.str.size > N) { throw agpack::type_error(); }
            std::memcpy(v, o.via.str.ptr, o.via.str.size);
            if (o.via.str.size < N) v[o.via.str.size] = '\0';
            break;
        default:
            throw agpack::type_error();
            break;
        }
        return o;
    }
};


template <typename T, std::size_t N>
struct pack<T[N]> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const T(&v)[N]) const {
        uint32_t size = checked_get_container_size(N);
        o.pack_array(size);
        const T* ptr = v;
        for (; ptr != &v[N]; ++ptr) o.pack(*ptr);
        return o;
    }
};

template <std::size_t N>
struct pack<char[N]> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const char(&v)[N]) const {
        char const* p = v;
        uint32_t size = checked_get_container_size(N);
        char const* p2 = static_cast<char const*>(std::memchr(p, '\0', size));
        uint32_t adjusted_size = p2 ? static_cast<uint32_t>(p2 - p) : size;
        o.pack_str(adjusted_size);
        o.pack_str_body(p, adjusted_size);
        return o;
    }
};

template <std::size_t N>
struct pack<const char[N]> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const char(&v)[N]) const {
        uint32_t size = checked_get_container_size(N);
        char const* p = v;
        char const* p2 = static_cast<char const*>(std::memchr(p, '\0', size));
        uint32_t adjusted_size = p2 ? static_cast<uint32_t>(p2 - p) : size;
        o.pack_str(adjusted_size);
        o.pack_str_body(p, adjusted_size);
        return o;
    }
};

template <std::size_t N>
struct pack<unsigned char[N]> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const unsigned char(&v)[N]) const {
        unsigned char const* p = v;
        uint32_t size = checked_get_container_size(N);
        o.pack_bin(size);
        o.pack_bin_body(reinterpret_cast<char const*>(p), size);
        return o;
    }
};

template <std::size_t N>
struct pack<const unsigned char[N]> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const unsigned char(&v)[N]) const {
        unsigned char const* p = v;
        uint32_t size = checked_get_container_size(N);
        o.pack_bin(size);
        o.pack_bin_body(reinterpret_cast<char const*>(p), size);
        return o;
    }
};

template <typename T, std::size_t N>
struct object_with_zone<T[N]> {
    void operator()(agpack::object::with_zone& o, const T(&v)[N]) const {
        uint32_t size = checked_get_container_size(N);
        o.type = agpack::type::ARRAY;
        agpack::object* ptr = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object) * size, AGPACK_ZONE_ALIGNOF(agpack::object)));
        o.via.array.ptr = ptr;
        o.via.array.size = size;
        const T* pv = v;
        for (; pv != &v[size]; ++pv) {
            *ptr++ = agpack::object(*pv, o.zone);
        }
    }
};

template <std::size_t N>
struct object_with_zone<char[N]> {
    void operator()(agpack::object::with_zone& o, const char(&v)[N]) const {
        char const* p = v;
        uint32_t size = checked_get_container_size(N);
        char const* p2 = static_cast<char const*>(std::memchr(p, '\0', size));
        uint32_t adjusted_size = p2 ? static_cast<uint32_t>(p2 - p) : size;
        o.type = agpack::type::STR;
        char* ptr = static_cast<char*>(o.zone.allocate_align(adjusted_size, AGPACK_ZONE_ALIGNOF(char)));
        o.via.str.ptr = ptr;
        o.via.str.size = adjusted_size;
        std::memcpy(ptr, p, adjusted_size);
    }
};

template <std::size_t N>
struct object_with_zone<const char[N]> {
    void operator()(agpack::object::with_zone& o, const char(&v)[N]) const {
        char const* p = v;
        uint32_t size = checked_get_container_size(N);
        char const* p2 = static_cast<char const*>(std::memchr(p, '\0', size));
        uint32_t adjusted_size = p2 ? static_cast<uint32_t>(p2 - p) : size;
        o.type = agpack::type::STR;
        char* ptr = static_cast<char*>(o.zone.allocate_align(adjusted_size, AGPACK_ZONE_ALIGNOF(char)));
        o.via.str.ptr = ptr;
        o.via.str.size = adjusted_size;
        std::memcpy(ptr, p, adjusted_size);
    }
};

template <std::size_t N>
struct object_with_zone<unsigned char[N]> {
    void operator()(agpack::object::with_zone& o, const unsigned char(&v)[N]) const {
        uint32_t size = checked_get_container_size(N);
        o.type = agpack::type::BIN;
        char* ptr = static_cast<char*>(o.zone.allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
        o.via.bin.ptr = ptr;
        o.via.bin.size = size;
        std::memcpy(ptr, v, size);
    }
};

template <std::size_t N>
struct object_with_zone<const unsigned char[N]> {
    void operator()(agpack::object::with_zone& o, const unsigned char(&v)[N]) const {
        uint32_t size = checked_get_container_size(N);
        o.type = agpack::type::BIN;
        char* ptr = static_cast<char*>(o.zone.allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
        o.via.bin.ptr = ptr;
        o.via.bin.size = size;
        std::memcpy(ptr, v, size);
    }
};

template <std::size_t N>
struct object<char[N]> {
    void operator()(agpack::object& o, const char(&v)[N]) const {
        char const* p = v;
        uint32_t size = checked_get_container_size(N);
        char const* p2 = static_cast<char const*>(std::memchr(p, '\0', size));
        uint32_t adjusted_size = p2 ? static_cast<uint32_t>(p2 - p) : size;
        o.type = agpack::type::STR;
        o.via.str.ptr = p;
        o.via.str.size = adjusted_size;
    }
};

template <std::size_t N>
struct object<const char[N]> {
    void operator()(agpack::object& o, const char(&v)[N]) const {
        char const* p = v;
        uint32_t size = checked_get_container_size(N);
        char const* p2 = static_cast<char const*>(std::memchr(p, '\0', size));
        uint32_t adjusted_size = p2 ? static_cast<uint32_t>(p2 - p) : size;
        o.type = agpack::type::STR;
        o.via.str.ptr = p;
        o.via.str.size = adjusted_size;
    }
};


} // namespace adaptor

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_TYPE_CARRAY_HPP
