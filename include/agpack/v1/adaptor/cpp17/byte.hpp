//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2018 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_BYTE_HPP
#define AGPACK_V1_TYPE_BYTE_HPP

#if __cplusplus >= 201703

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/int_decl.hpp"
#include "agpack/object.hpp"

#include <cstddef>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <>
struct convert<std::byte> {
    agpack::object const& operator()(agpack::object const& o, std::byte& v) const {
        v = static_cast<std::byte>(type::detail::convert_integer<unsigned char>(o));
        return o;
    }
};

template <>
struct pack<std::byte> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, std::byte v) const {
        o.pack_unsigned_char(static_cast<unsigned char>(v));
        return o;
    }
};

template <>
struct object<std::byte> {
    void operator()(agpack::object& o, std::byte v) const {
        o.type = agpack::type::POSITIVE_INTEGER;
        o.via.u64 = static_cast<unsigned char>(v);
    }
};

template <>
struct object_with_zone<std::byte> {
    void operator()(agpack::object::with_zone& o, const std::byte& v) const {
        static_cast<agpack::object&>(o) << v;
    }
};


} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // __cplusplus >= 201703

#endif // AGPACK_V1_TYPE_BYTE_HPP
