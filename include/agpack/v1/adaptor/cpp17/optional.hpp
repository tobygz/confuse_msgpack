//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2017 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_OPTIONAL_HPP
#define AGPACK_V1_TYPE_OPTIONAL_HPP

#if __cplusplus >= 201703

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <optional>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

#if !defined (AGPACK_USE_CPP03)

template <typename T>
struct as<std::optional<T>, typename std::enable_if<agpack::has_as<T>::value>::type> {
    std::optional<T> operator()(agpack::object const& o) const {
        if(o.is_nil()) return std::nullopt;
        return o.as<T>();
    }
};

#endif // !defined (AGPACK_USE_CPP03)

template <typename T>
struct convert<std::optional<T> > {
    agpack::object const& operator()(agpack::object const& o, std::optional<T>& v) const {
        if(o.is_nil()) v = std::nullopt;
        else {
            T t;
            agpack::adaptor::convert<T>()(o, t);
            v = t;
        }
        return o;
    }
};

template <typename T>
struct pack<std::optional<T> > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::optional<T>& v) const {
        if (v) o.pack(*v);
        else o.pack_nil();
        return o;
    }
};

template <typename T>
struct object<std::optional<T> > {
    void operator()(agpack::object& o, const std::optional<T>& v) const {
        if (v) agpack::adaptor::object<T>()(o, *v);
        else o.type = agpack::type::NIL;
    }
};

template <typename T>
struct object_with_zone<std::optional<T> > {
    void operator()(agpack::object::with_zone& o, const std::optional<T>& v) const {
        if (v) agpack::adaptor::object_with_zone<T>()(o, *v);
        else o.type = agpack::type::NIL;
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // __cplusplus >= 201703

#endif // AGPACK_V1_TYPE_OPTIONAL_HPP
