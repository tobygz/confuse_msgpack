//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_FIXINT_HPP
#define AGPACK_V1_TYPE_FIXINT_HPP

#include "agpack/v1/adaptor/fixint_decl.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

template <typename T>
struct fix_int {
    typedef T value_type;
    fix_int() : value(0) { }
    fix_int(T value) : value(value) { }

    operator T() const { return value; }

    T get() const { return value; }

private:
    T value;
};

}  // namespace type

namespace adaptor {

template <>
struct convert<type::fix_int8> {
    agpack::object const& operator()(agpack::object const& o, type::fix_int8& v) const
    { v = type::detail::convert_integer<int8_t>(o); return o; }
};

template <>
struct convert<type::fix_int16> {
    agpack::object const& operator()(agpack::object const& o, type::fix_int16& v) const
    { v = type::detail::convert_integer<int16_t>(o); return o; }
};

template <>
struct convert<type::fix_int32> {
    agpack::object const& operator()(agpack::object const& o, type::fix_int32& v) const
    { v = type::detail::convert_integer<int32_t>(o); return o; }
};

template <>
struct convert<type::fix_int64> {
    agpack::object const& operator()(agpack::object const& o, type::fix_int64& v) const
    { v = type::detail::convert_integer<int64_t>(o); return o; }
};


template <>
struct convert<type::fix_uint8> {
    agpack::object const& operator()(agpack::object const& o, type::fix_uint8& v) const
    { v = type::detail::convert_integer<uint8_t>(o); return o; }
};

template <>
struct convert<type::fix_uint16> {
    agpack::object const& operator()(agpack::object const& o, type::fix_uint16& v) const
    { v = type::detail::convert_integer<uint16_t>(o); return o; }
};

template <>
struct convert<type::fix_uint32> {
    agpack::object const& operator()(agpack::object const& o, type::fix_uint32& v) const
    { v = type::detail::convert_integer<uint32_t>(o); return o; }
};

template <>
struct convert<type::fix_uint64> {
    agpack::object const& operator()(agpack::object const& o, type::fix_uint64& v) const
    { v = type::detail::convert_integer<uint64_t>(o); return o; }
};

template <>
struct pack<type::fix_int8> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::fix_int8& v) const
    { o.pack_fix_int8(v); return o; }
};

template <>
struct pack<type::fix_int16> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::fix_int16& v) const
    { o.pack_fix_int16(v); return o; }
};

template <>
struct pack<type::fix_int32> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::fix_int32& v) const
    { o.pack_fix_int32(v); return o; }
};

template <>
struct pack<type::fix_int64> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::fix_int64& v) const
    { o.pack_fix_int64(v); return o; }
};


template <>
struct pack<type::fix_uint8> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::fix_uint8& v) const
    { o.pack_fix_uint8(v); return o; }
};

template <>
struct pack<type::fix_uint16> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::fix_uint16& v) const
    { o.pack_fix_uint16(v); return o; }
};

template <>
struct pack<type::fix_uint32> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::fix_uint32& v) const
    { o.pack_fix_uint32(v); return o; }
};

template <>
struct pack<type::fix_uint64> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const type::fix_uint64& v) const
    { o.pack_fix_uint64(v); return o; }
};

template <>
struct object<type::fix_int8> {
    void operator()(agpack::object& o, type::fix_int8 v) const {
        if (v.get() < 0) {
            o.type = agpack::type::NEGATIVE_INTEGER;
            o.via.i64 = v.get();
        }
        else {
            o.type = agpack::type::POSITIVE_INTEGER;
            o.via.u64 = static_cast<uint64_t>(v.get());
        }
    }
};

template <>
struct object<type::fix_int16> {
    void operator()(agpack::object& o, type::fix_int16 v) const {
        if(v.get() < 0) {
            o.type = agpack::type::NEGATIVE_INTEGER;
            o.via.i64 = v.get();
        }
        else {
            o.type = agpack::type::POSITIVE_INTEGER;
            o.via.u64 = static_cast<uint64_t>(v.get());
        }
    }
};

template <>
struct object<type::fix_int32> {
    void operator()(agpack::object& o, type::fix_int32 v) const {
        if (v.get() < 0) {
            o.type = agpack::type::NEGATIVE_INTEGER;
            o.via.i64 = v.get();
        }
        else {
            o.type = agpack::type::POSITIVE_INTEGER;
            o.via.u64 = static_cast<uint64_t>(v.get());
        }
    }
};

template <>
struct object<type::fix_int64> {
    void operator()(agpack::object& o, type::fix_int64 v) const {
        if (v.get() < 0) {
            o.type = agpack::type::NEGATIVE_INTEGER;
            o.via.i64 = v.get();
        }
        else {
            o.type = agpack::type::POSITIVE_INTEGER;
            o.via.u64 = static_cast<uint64_t>(v.get());
        }
    }
};

template <>
struct object<type::fix_uint8> {
    void operator()(agpack::object& o, type::fix_uint8 v) const {
        o.type = agpack::type::POSITIVE_INTEGER;
        o.via.u64 = v.get();
    }
};

template <>
struct object<type::fix_uint16> {
    void operator()(agpack::object& o, type::fix_uint16 v) const {
        o.type = agpack::type::POSITIVE_INTEGER;
        o.via.u64 = v.get();
    }
};

template <>
struct object<type::fix_uint32> {
    void operator()(agpack::object& o, type::fix_uint32 v) const {
        o.type = agpack::type::POSITIVE_INTEGER;
        o.via.u64 = v.get();
    }
};

template <>
struct object<type::fix_uint64> {
    void operator()(agpack::object& o, type::fix_uint64 v) const {
        o.type = agpack::type::POSITIVE_INTEGER;
        o.via.u64 = v.get();
    }
};

template <>
struct object_with_zone<type::fix_int8> {
    void operator()(agpack::object::with_zone& o, type::fix_int8 v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

template <>
struct object_with_zone<type::fix_int16> {
    void operator()(agpack::object::with_zone& o, type::fix_int16 v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

template <>
struct object_with_zone<type::fix_int32> {
    void operator()(agpack::object::with_zone& o, type::fix_int32 v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

template <>
struct object_with_zone<type::fix_int64> {
    void operator()(agpack::object::with_zone& o, type::fix_int64 v) const {
        static_cast<agpack::object&>(o) << v;
    }
};


template <>
struct object_with_zone<type::fix_uint8> {
    void operator()(agpack::object::with_zone& o, type::fix_uint8 v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

template <>
struct object_with_zone<type::fix_uint16> {
    void operator()(agpack::object::with_zone& o, type::fix_uint16 v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

template <>
struct object_with_zone<type::fix_uint32> {
    void operator()(agpack::object::with_zone& o, type::fix_uint32 v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

template <>
struct object_with_zone<type::fix_uint64> {
    void operator()(agpack::object::with_zone& o, type::fix_uint64 v) const {
        static_cast<agpack::object&>(o) << v;
    }
};

} // namespace adaptor

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_TYPE_FIXINT_HPP
