//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2009 FURUHASHI Sadayuki
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_PAIR_HPP
#define AGPACK_V1_TYPE_PAIR_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/meta.hpp"

#include <utility>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

#if !defined(AGPACK_USE_CPP03)

template <typename T1, typename T2>
struct as<std::pair<T1, T2>,
          typename std::enable_if<agpack::any_of<agpack::has_as, T1, T2>::value>::type> {
    std::pair<T1, T2> operator()(agpack::object const& o) const {
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        if (o.via.array.size != 2) { throw agpack::type_error(); }
        return std::make_pair(o.via.array.ptr[0].as<T1>(), o.via.array.ptr[1].as<T2>());
    }
};

#endif // !defined(AGPACK_USE_CPP03)

template <typename T1, typename T2>
struct convert<std::pair<T1, T2> > {
    agpack::object const& operator()(agpack::object const& o, std::pair<T1, T2>& v) const {
        if(o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        if(o.via.array.size != 2) { throw agpack::type_error(); }
        o.via.array.ptr[0].convert(v.first);
        o.via.array.ptr[1].convert(v.second);
        return o;
    }
};

template <typename T1, typename T2>
struct pack<std::pair<T1, T2> > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::pair<T1, T2>& v) const {
        o.pack_array(2);
        o.pack(v.first);
        o.pack(v.second);
        return o;
    }
};

template <typename T1, typename T2>
struct object_with_zone<std::pair<T1, T2> > {
    void operator()(agpack::object::with_zone& o, const std::pair<T1, T2>& v) const {
        o.type = agpack::type::ARRAY;
        agpack::object* p = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object)*2, AGPACK_ZONE_ALIGNOF(agpack::object)));
        o.via.array.ptr = p;
        o.via.array.size = 2;
        p[0] = agpack::object(v.first, o.zone);
        p[1] = agpack::object(v.second, o.zone);
    }
};

} // namespace adaptor

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_TYPE_PAIR_HPP
