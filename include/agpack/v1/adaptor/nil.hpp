//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_NIL_HPP
#define AGPACK_V1_TYPE_NIL_HPP

#include "agpack/v1/adaptor/nil_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

struct nil_t { };

inline bool operator<(nil_t const& lhs, nil_t const& rhs) {
    return &lhs < &rhs;
}

inline bool operator==(nil_t const& lhs, nil_t const& rhs) {
    return &lhs == &rhs;
}

}  // namespace type

namespace adaptor {

template <>
struct convert<type::nil_t> {
    agpack::object const& operator()(agpack::object const& o, type::nil_t&) const {
        if(o.type != agpack::type::NIL) { throw agpack::type_error(); }
        return o;
    }
};

template <>
struct pack<type::nil_t> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::nil_t&) const {
        o.pack_nil();
        return o;
    }
};

template <>
struct object<type::nil_t> {
    void operator()(agpack::object& o, type::nil_t) const {
        o.type = agpack::type::NIL;
    }
};

template <>
struct object_with_zone<type::nil_t> {
    void operator()(agpack::object::with_zone& o, type::nil_t v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

} // namespace adaptor

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_TYPE_NIL_HPP
