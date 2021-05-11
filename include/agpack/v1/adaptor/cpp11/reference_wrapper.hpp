//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2015 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AGPACK_V1_TYPE_CPP11_REFERENCE_WRAPPER_HPP
#define AGPACK_V1_TYPE_CPP11_REFERENCE_WRAPPER_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <memory>
#include <type_traits>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <typename T>
struct convert<std::reference_wrapper<T>> {
    agpack::object const& operator()(agpack::object const& o, std::reference_wrapper<T>& v) const {
        agpack::adaptor::convert<T>()(o, v.get());
        return o;
    }
};

template <typename T>
struct pack<std::reference_wrapper<T>> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::reference_wrapper<T>& v) const {
        o.pack(v.get());
        return o;
    }
};

template <typename T>
struct object<std::reference_wrapper<T> > {
    void operator()(agpack::object& o, const std::reference_wrapper<T>& v) const {
        agpack::adaptor::object<typename std::remove_const<T>::type>()(o, v.get());
    }
};

template <typename T>
struct object_with_zone<std::reference_wrapper<T>> {
    void operator()(agpack::object::with_zone& o, const std::reference_wrapper<T>& v) const {
        agpack::adaptor::object_with_zone<typename std::remove_const<T>::type>()(o, v.get());
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_CPP11_REFERENCE_WRAPPER_HPP
