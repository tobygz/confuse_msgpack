//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2014 KONDO-2015 Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AGPACK_V1_TYPE_CPP11_FORWARD_LIST_HPP
#define AGPACK_V1_TYPE_CPP11_FORWARD_LIST_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <forward_list>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <typename T, typename Alloc>
    struct as<std::forward_list<T, Alloc>, typename std::enable_if<agpack::has_as<T>::value>::type> {
    std::forward_list<T, Alloc> operator()(agpack::object const& o) const {
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        std::forward_list<T, Alloc> v;
        agpack::object* p = o.via.array.ptr + o.via.array.size;
        agpack::object* const pend = o.via.array.ptr;
        while (p != pend) {
            --p;
            v.push_front(p->as<T>());
        }
        return v;
    }
};

template <typename T, typename Alloc>
struct convert<std::forward_list<T, Alloc>> {
    agpack::object const& operator()(agpack::object const& o, std::forward_list<T, Alloc>& v) const {
        if(o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        v.resize(o.via.array.size);
        agpack::object* p = o.via.array.ptr;
        for (auto &e : v) {
            p->convert(e);
            ++p;
        }
        return o;
    }
};

template <typename T, typename Alloc>
struct pack<std::forward_list<T, Alloc>> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::forward_list<T, Alloc>& v) const {
        uint32_t size = checked_get_container_size(std::distance(v.begin(), v.end()));
        o.pack_array(size);
        for(auto const& e : v) o.pack(e);
        return o;
    }
};

template <typename T, typename Alloc>
struct object_with_zone<std::forward_list<T, Alloc>> {
    void operator()(agpack::object::with_zone& o, const std::forward_list<T, Alloc>& v) const {
        o.type = agpack::type::ARRAY;
        if(v.empty()) {
            o.via.array.ptr = AGPACK_NULLPTR;
            o.via.array.size = 0;
        } else {
            uint32_t size = checked_get_container_size(std::distance(v.begin(), v.end()));
            o.via.array.size = size;
            agpack::object* p = static_cast<agpack::object*>(
                o.zone.allocate_align(sizeof(agpack::object)*size, AGPACK_ZONE_ALIGNOF(agpack::object)));
            o.via.array.ptr = p;
            for(auto const& e : v) *p++ = agpack::object(e, o.zone);
        }
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_CPP11_FORWARD_LIST_HPP
