//
// MessagePack for C++ deserializing routine
//
// Copyright (C) 2018 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_UNPACK_HPP
#define AGPACK_V3_UNPACK_HPP

#include "agpack/unpack_decl.hpp"
#include "agpack/parse.hpp"
#include "agpack/create_object_visitor.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

inline agpack::object_handle unpack(
    const char* data, std::size_t len, std::size_t& off, bool& referenced,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit
)
{
    agpack::object obj;
    agpack::unique_ptr<agpack::zone> z(new agpack::zone);
    referenced = false;
    parse_return ret = detail::unpack_imp(
        data, len, off, *z, obj, referenced, f, user_data, limit);

    switch(ret) {
    case PARSE_SUCCESS:
        return agpack::object_handle(obj, agpack::move(z));
    case PARSE_EXTRA_BYTES:
        return agpack::object_handle(obj, agpack::move(z));
    default:
        break;
    }
    return agpack::object_handle();
}

inline agpack::object_handle unpack(
    const char* data, std::size_t len, std::size_t& off,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    bool referenced;
    return agpack::v3::unpack(data, len, off, referenced, f, user_data, limit);
}

inline agpack::object_handle unpack(
    const char* data, std::size_t len, bool& referenced,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    std::size_t off = 0;
    return agpack::v3::unpack(data, len, off, referenced, f, user_data, limit);
}

inline agpack::object_handle unpack(
    const char* data, std::size_t len,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    bool referenced;
    std::size_t off = 0;
    return agpack::v3::unpack(data, len, off, referenced, f, user_data, limit);
}

inline void unpack(
    agpack::object_handle& result,
    const char* data, std::size_t len, std::size_t& off, bool& referenced,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    agpack::object obj;
    agpack::unique_ptr<agpack::zone> z(new agpack::zone);
    referenced = false;
    parse_return ret = detail::unpack_imp(
        data, len, off, *z, obj, referenced, f, user_data, limit);

    switch(ret) {
    case PARSE_SUCCESS:
        result.set(obj);
        result.zone() = agpack::move(z);
        return;
    case PARSE_EXTRA_BYTES:
        result.set(obj);
        result.zone() = agpack::move(z);
        return;
    default:
        return;
    }
}

inline void unpack(
    agpack::object_handle& result,
    const char* data, std::size_t len, std::size_t& off,
    agpack::v3::unpack_reference_func f, void* user_data,
            agpack::unpack_limit const& limit)
{
    bool referenced;
    agpack::v3::unpack(result, data, len, off, referenced, f, user_data, limit);
}

inline void unpack(
    agpack::object_handle& result,
    const char* data, std::size_t len, bool& referenced,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    std::size_t off = 0;
    agpack::v3::unpack(result, data, len, off, referenced, f, user_data, limit);
}

inline void unpack(
    agpack::object_handle& result,
    const char* data, std::size_t len,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    bool referenced;
    std::size_t off = 0;
    agpack::v3::unpack(result, data, len, off, referenced, f, user_data, limit);
}


inline agpack::object unpack(
    agpack::zone& z,
    const char* data, std::size_t len, std::size_t& off, bool& referenced,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    agpack::object obj;
    referenced = false;
    parse_return ret = detail::unpack_imp(
        data, len, off, z, obj, referenced, f, user_data, limit);

    switch(ret) {
    case PARSE_SUCCESS:
        return obj;
    case PARSE_EXTRA_BYTES:
        return obj;
    default:
        break;
    }
    return obj;
}

inline agpack::object unpack(
    agpack::zone& z,
    const char* data, std::size_t len, std::size_t& off,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    bool referenced;
    return agpack::v3::unpack(z, data, len, off, referenced, f, user_data, limit);
}

inline agpack::object unpack(
    agpack::zone& z,
    const char* data, std::size_t len, bool& referenced,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    std::size_t off = 0;
    return agpack::v3::unpack(z, data, len, off, referenced, f, user_data, limit);
}

inline agpack::object unpack(
    agpack::zone& z,
    const char* data, std::size_t len,
    agpack::unpack_reference_func f, void* user_data,
    agpack::unpack_limit const& limit)
{
    bool referenced;
    std::size_t off = 0;
    return agpack::v3::unpack(z, data, len, off, referenced, f, user_data, limit);
}

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

}  // namespace agpack


#endif // AGPACK_V3_UNPACK_HPP
