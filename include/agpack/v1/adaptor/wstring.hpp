//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2018 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_WSTRING_HPP
#define AGPACK_V1_TYPE_WSTRING_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <vector>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

#if !defined(AGPACK_USE_CPP03)

template <>
struct as<std::wstring> {
    std::wstring operator()(const agpack::object& o) const {
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        std::wstring v;
        v.reserve(o.via.array.size);
        if (o.via.array.size > 0) {
            agpack::object* p = o.via.array.ptr;
            agpack::object* const pend = o.via.array.ptr + o.via.array.size;
            do {
                v.push_back(p->as<wchar_t>());
                ++p;
            } while (p < pend);
        }
        return v;
    }
};

#endif // !defined(AGPACK_USE_CPP03)

template <>
struct convert<std::wstring> {
    agpack::object const& operator()(agpack::object const& o, std::wstring& v) const {
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        v.resize(o.via.array.size);
        if (o.via.array.size > 0) {
            agpack::object* p = o.via.array.ptr;
            agpack::object* const pend = o.via.array.ptr + o.via.array.size;
            std::wstring::iterator it = v.begin();
            do {
                p->convert(*it);
                ++p;
                ++it;
            } while(p < pend);
        }
        return o;
    }
};

template <>
struct pack<std::wstring> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::wstring& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_array(size);
        for (std::wstring::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(*it);
        }
        return o;
    }
};

template <>
struct object_with_zone<std::wstring> {
    void operator()(agpack::object::with_zone& o, const std::wstring& v) const {
        o.type = agpack::type::ARRAY;
        if (v.empty()) {
            o.via.array.ptr = AGPACK_NULLPTR;
            o.via.array.size = 0;
        }
        else {
            uint32_t size = checked_get_container_size(v.size());
            agpack::object* p = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object)*size, AGPACK_ZONE_ALIGNOF(agpack::object)));
            agpack::object* const pend = p + size;
            o.via.array.ptr = p;
            o.via.array.size = size;
            std::wstring::const_iterator it(v.begin());
            do {
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
                *p = agpack::object(*it, o.zone);
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
                ++p;
                ++it;
            } while(p < pend);
        }
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_WSTRING_HPP
