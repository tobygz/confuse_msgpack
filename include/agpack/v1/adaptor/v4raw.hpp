//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_V4RAW_HPP
#define AGPACK_V1_TYPE_V4RAW_HPP

#include "agpack/v1/adaptor/v4raw_decl.hpp"
#include <cstring>
#include <string>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

struct v4raw_ref {
    v4raw_ref() : size(0), ptr(AGPACK_NULLPTR) {}
    v4raw_ref(const char* p, uint32_t s) : size(s), ptr(p) {}

    uint32_t size;
    const char* ptr;

    std::string str() const { return std::string(ptr, size); }

    bool operator== (const v4raw_ref& x) const
    {
        return size == x.size && std::memcmp(ptr, x.ptr, size) == 0;
    }

    bool operator!= (const v4raw_ref& x) const
    {
        return !(*this == x);
    }

    bool operator< (const v4raw_ref& x) const
    {
        if(size == x.size) { return std::memcmp(ptr, x.ptr, size) < 0; }
        else { return size < x.size; }
    }

    bool operator> (const v4raw_ref& x) const
    {
        if(size == x.size) { return std::memcmp(ptr, x.ptr, size) > 0; }
        else { return size > x.size; }
    }
};

} // namespace type

namespace adaptor {

template <>
struct convert<type::v4raw_ref> {
    agpack::object const& operator()(agpack::object const& o, type::v4raw_ref& v) const {
        if(o.type != agpack::type::STR) { throw agpack::type_error(); }
        v.ptr  = o.via.str.ptr;
        v.size = o.via.str.size;
        return o;
    }
};

template <>
struct pack<type::v4raw_ref> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::v4raw_ref& v) const {
        o.pack_v4raw(v.size);
        o.pack_v4raw_body(v.ptr, v.size);
        return o;
    }
};

template <>
struct object<type::v4raw_ref> {
    void operator()(agpack::object& o, const type::v4raw_ref& v) const {
        o.type = agpack::type::STR;
        o.via.str.ptr = v.ptr;
        o.via.str.size = v.size;
    }
};

template <>
struct object_with_zone<type::v4raw_ref> {
    void operator()(agpack::object::with_zone& o, const type::v4raw_ref& v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_V4RAW_HPP
