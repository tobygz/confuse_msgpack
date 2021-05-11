//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_BOOL_HPP
#define AGPACK_V1_TYPE_BOOL_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <>
struct convert<bool> {
    agpack::object const& operator()(agpack::object const& o, bool& v) const {
        if(o.type != agpack::type::BOOLEAN) { throw agpack::type_error(); }
        v = o.via.boolean;
        return o;
    }
};

template <>
struct pack<bool> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const bool& v) const {
        if(v) { o.pack_true(); }
        else { o.pack_false(); }
        return o;
    }
};

template <>
struct object<bool> {
    void operator()(agpack::object& o, bool v) const {
        o.type = agpack::type::BOOLEAN;
        o.via.boolean = v;
    }
};

template <>
struct object_with_zone<bool> {
    void operator()(agpack::object::with_zone& o, bool v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

} // namespace adaptor

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_TYPE_BOOL_HPP
