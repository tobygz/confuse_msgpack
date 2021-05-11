//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2009 FURUHASHI Sadayuki
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_RAW_HPP
#define AGPACK_V1_TYPE_RAW_HPP

#include "agpack/v1/adaptor/raw_decl.hpp"

#include <cstring>
#include <string>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

struct raw_ref {
    raw_ref() : size(0), ptr(AGPACK_NULLPTR) {}
    raw_ref(const char* p, uint32_t s) : size(s), ptr(p) {}

    uint32_t size;
    const char* ptr;

    std::string str() const { return std::string(ptr, size); }

    bool operator== (const raw_ref& x) const
    {
        return size == x.size && std::memcmp(ptr, x.ptr, size) == 0;
    }

    bool operator!= (const raw_ref& x) const
    {
        return !(*this == x);
    }

    bool operator< (const raw_ref& x) const
    {
        if(size == x.size) { return std::memcmp(ptr, x.ptr, size) < 0; }
        else { return size < x.size; }
    }

    bool operator> (const raw_ref& x) const
    {
        if(size == x.size) { return std::memcmp(ptr, x.ptr, size) > 0; }
        else { return size > x.size; }
    }
};

} // namespace type

namespace adaptor {

template <>
struct convert<type::raw_ref> {
    agpack::object const& operator()(agpack::object const& o, type::raw_ref& v) const {
        if(o.type != agpack::type::BIN) { throw agpack::type_error(); }
        v.ptr  = o.via.bin.ptr;
        v.size = o.via.bin.size;
        return o;
    }
};

template <>
struct pack<type::raw_ref> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::raw_ref& v) const {
        o.pack_bin(v.size);
        o.pack_bin_body(v.ptr, v.size);
        return o;
    }
};

template <>
struct object<type::raw_ref> {
    void operator()(agpack::object& o, const type::raw_ref& v) const {
        o.type = agpack::type::BIN;
        o.via.bin.ptr = v.ptr;
        o.via.bin.size = v.size;
    }
};

template <>
struct object_with_zone<type::raw_ref> {
    void operator()(agpack::object::with_zone& o, const type::raw_ref& v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_RAW_HPP