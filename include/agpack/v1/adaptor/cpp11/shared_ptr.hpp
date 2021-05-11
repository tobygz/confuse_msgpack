//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2015 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AGPACK_V1_TYPE_CPP11_SHARED_PTR_HPP
#define AGPACK_V1_TYPE_CPP11_SHARED_PTR_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <memory>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <typename T>
struct as<std::shared_ptr<T>, typename std::enable_if<agpack::has_as<T>::value>::type> {
    std::shared_ptr<T> operator()(agpack::object const& o) const {
        if(o.is_nil()) return AGPACK_NULLPTR;
        return std::make_shared<T>(o.as<T>());
    }
};

template <typename T>
struct convert<std::shared_ptr<T>> {
    agpack::object const& operator()(agpack::object const& o, std::shared_ptr<T>& v) const {
        if(o.is_nil()) v.reset();
        else {
            v = std::make_shared<T>();
            agpack::adaptor::convert<T>()(o, *v);
        }
        return o;
    }
};

template <typename T>
struct pack<std::shared_ptr<T>> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::shared_ptr<T>& v) const {
        if (v) o.pack(*v);
        else o.pack_nil();
        return o;
    }
};

template <typename T>
struct object<std::shared_ptr<T> > {
    void operator()(agpack::object& o, const std::shared_ptr<T>& v) const {
        if (v) agpack::adaptor::object<T>()(o, *v);
        else o.type = agpack::type::NIL;
    }
};

template <typename T>
struct object_with_zone<std::shared_ptr<T>> {
    void operator()(agpack::object::with_zone& o, const std::shared_ptr<T>& v) const {
        if (v) agpack::adaptor::object_with_zone<T>()(o, *v);
        else o.type = agpack::type::NIL;
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_CPP11_SHARED_PTR_HPP
