//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2017 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_STRING_VIEW_HPP
#define AGPACK_V1_TYPE_STRING_VIEW_HPP

#if __cplusplus >= 201703

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <string_view>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <>
struct convert<std::string_view> {
    agpack::object const& operator()(agpack::object const& o, std::string_view& v) const {
        switch (o.type) {
        case agpack::type::BIN:
            v = std::string_view(o.via.bin.ptr, o.via.bin.size);
            break;
        case agpack::type::STR:
            v = std::string_view(o.via.str.ptr, o.via.str.size);
            break;
        default:
            throw agpack::type_error();
            break;
        }
        return o;
    }
};

template <>
struct pack<std::string_view> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::string_view& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_str(size);
        o.pack_str_body(v.data(), size);
        return o;
    }
};

template <>
struct object<std::string_view> {
    void operator()(agpack::object& o, const std::string_view& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.type = agpack::type::STR;
        o.via.str.ptr = v.data();
        o.via.str.size = size;
    }
};

template <>
struct object_with_zone<std::string_view> {
    void operator()(agpack::object::with_zone& o, const std::string_view& v) const {
        static_cast<agpack::object&>(o) << v;
    }
};


} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // __cplusplus >= 201703

#endif // AGPACK_V1_TYPE_STRING_VIEW_HPP
