//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2009 FURUHASHI Sadayuki
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_FLOAT_HPP
#define AGPACK_V1_TYPE_FLOAT_HPP

#include "agpack/versioning.hpp"
#include "agpack/object_fwd.hpp"
#include <vector>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

// FIXME check overflow, underflow

namespace adaptor {

template <>
struct convert<float> {
    agpack::object const& operator()(agpack::object const& o, float& v) const {
        if(o.type == agpack::type::FLOAT32 || o.type == agpack::type::FLOAT64) {
            v = static_cast<float>(o.via.f64);
        }
        else if (o.type == agpack::type::POSITIVE_INTEGER) {
            v = static_cast<float>(o.via.u64);
        }
        else if (o.type == agpack::type::NEGATIVE_INTEGER) {
            v = static_cast<float>(o.via.i64);
        }
        else {
            throw agpack::type_error();
        }
        return o;
    }
};

template <>
struct pack<float> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const float& v) const {
        o.pack_float(v);
        return o;
    }
};


template <>
struct convert<double> {
    agpack::object const& operator()(agpack::object const& o, double& v) const {
        if(o.type == agpack::type::FLOAT32 || o.type == agpack::type::FLOAT64) {
            v = o.via.f64;
        }
        else if (o.type == agpack::type::POSITIVE_INTEGER) {
            v = static_cast<double>(o.via.u64);
        }
        else if (o.type == agpack::type::NEGATIVE_INTEGER) {
            v = static_cast<double>(o.via.i64);
        }
        else {
            throw agpack::type_error();
        }
        return o;
    }
};

template <>
struct pack<double> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const double& v) const {
        o.pack_double(v);
        return o;
    }
};


template <>
struct object<float> {
    void operator()(agpack::object& o, float v) const {
        o.type = agpack::type::FLOAT32;
        o.via.f64 = static_cast<double>(v);
    }
};

template <>
struct object<double> {
    void operator()(agpack::object& o, double v) const {
        o.type = agpack::type::FLOAT64;
        o.via.f64 = v;
    }
};

template <>
struct object_with_zone<float> {
    void operator()(agpack::object::with_zone& o, float v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

template <>
struct object_with_zone<double> {
    void operator()(agpack::object::with_zone& o, double v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

} // namespace adaptor

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_TYPE_FLOAT_HPP
