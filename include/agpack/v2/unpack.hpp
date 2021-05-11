//
// MessagePack for C++ deserializing routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V2_UNPACK_HPP
#define AGPACK_V2_UNPACK_HPP

#if AGPACK_DEFAULT_API_VERSION >= 2

#include "agpack/unpack_decl.hpp"
#include "agpack/parse.hpp"
#include "agpack/create_object_visitor.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond


struct zone_push_finalizer {
    zone_push_finalizer(agpack::zone& z):m_z(&z) {}
    void set_zone(agpack::zone& z) { m_z = &z; }
    void operator()(char* buffer) {
        m_z->push_finalizer(&detail::decr_count, buffer);
    }
    agpack::zone* m_z;
};

class unpacker : public parser<unpacker, zone_push_finalizer>,
                 public detail::create_object_visitor {
    typedef parser<unpacker, zone_push_finalizer> parser_t;
public:
    unpacker(unpack_reference_func f = &unpacker::default_reference_func,
             void* user_data = AGPACK_NULLPTR,
             std::size_t initial_buffer_size = AGPACK_UNPACKER_INIT_BUFFER_SIZE,
             unpack_limit const& limit = unpack_limit())
        :parser_t(m_finalizer, initial_buffer_size),
         detail::create_object_visitor(f, user_data, limit),
         m_z(new agpack::zone),
         m_finalizer(*m_z) {
        set_zone(*m_z);
        set_referenced(false);
    }

    detail::create_object_visitor& visitor() { return *this; }
    /// Unpack one agpack::object.
    /**
     *
     * @param result The object that contains unpacked data.
     * @param referenced If the unpacked object contains reference of the buffer,
     *                   then set as true, otherwise false.
     *
     * @return If one agpack::object is unpacked, then return true, if agpack::object is incomplete
     *         and additional data is required, then return false. If data format is invalid, throw
     *         agpack::parse_error.
     *
     * See:
     * https://github.com/agpack/agpack-c/wiki/v1_1_cpp_unpacker#agpack-controls-a-buffer
     */
    bool next(agpack::object_handle& result, bool& referenced);

    /// Unpack one agpack::object.
    /**
     *
     * @param result The object that contains unpacked data.
     *
     * @return If one agpack::object is unpacked, then return true, if agpack::object is incomplete
     *         and additional data is required, then return false. If data format is invalid, throw
     *         agpack::parse_error.
     *
     * See:
     * https://github.com/agpack/agpack-c/wiki/v1_1_cpp_unpacker#agpack-controls-a-buffer
     */
    bool next(agpack::object_handle& result);
    agpack::zone* release_zone();
    void reset_zone();
    bool flush_zone();
private:
    static bool default_reference_func(agpack::type::object_type /*type*/, std::size_t /*len*/, void*) {
        return true;
    }
    agpack::unique_ptr<agpack::zone> m_z;
    zone_push_finalizer m_finalizer;
};

inline bool unpacker::next(agpack::object_handle& result, bool& referenced) {
    bool ret = parser_t::next();
    if (ret) {
        referenced = detail::create_object_visitor::referenced();
        result.zone().reset( release_zone() );
        result.set(data());
        reset();
    }
    else {
        result.zone().reset();
        result.set(agpack::object());
    }
    return ret;
}

inline bool unpacker::next(agpack::object_handle& result) {
    bool referenced;
    return next(result, referenced);
}

inline agpack::zone* unpacker::release_zone()
{
    if(!flush_zone()) {
        return AGPACK_NULLPTR;
    }

    agpack::zone* r =  new agpack::zone;
    agpack::zone* old = m_z.release();
    m_z.reset(r);
    set_zone(*m_z);
    m_finalizer.set_zone(*m_z);

    return old;
}

inline void unpacker::reset_zone()
{
    m_z->clear();
}

inline bool unpacker::flush_zone()
{
    if(referenced()) {
        try {
            m_z->push_finalizer(&detail::decr_count, get_raw_buffer());
        } catch (...) {
            return false;
        }
        set_referenced(false);

        detail::incr_count(get_raw_buffer());
    }

    return true;
}

inline agpack::object_handle unpack(
    const char* data, std::size_t len, std::size_t& off, bool& referenced,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit
)
{
    agpack::object obj;
    agpack::unique_ptr<agpack::zone> z(new agpack::zone);
    referenced = false;
    std::size_t noff = off;
    parse_return ret = detail::unpack_imp(
        data, len, noff, *z, obj, referenced, f, user_data, limit);

    switch(ret) {
    case PARSE_SUCCESS:
        off = noff;
        return agpack::object_handle(obj, agpack::move(z));
    case PARSE_EXTRA_BYTES:
        off = noff;
        return agpack::object_handle(obj, agpack::move(z));
    default:
        break;
    }
    return agpack::object_handle();
}

inline agpack::object_handle unpack(
    const char* data, std::size_t len, std::size_t& off,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    bool referenced;
    return agpack::v2::unpack(data, len, off, referenced, f, user_data, limit);
}

inline agpack::object_handle unpack(
    const char* data, std::size_t len, bool& referenced,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    std::size_t off = 0;
    return agpack::v2::unpack(data, len, off, referenced, f, user_data, limit);
}

inline agpack::object_handle unpack(
    const char* data, std::size_t len,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    bool referenced;
    std::size_t off = 0;
    return agpack::v2::unpack(data, len, off, referenced, f, user_data, limit);
}

inline void unpack(
    agpack::object_handle& result,
    const char* data, std::size_t len, std::size_t& off, bool& referenced,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    agpack::object obj;
    agpack::unique_ptr<agpack::zone> z(new agpack::zone);
    referenced = false;
    std::size_t noff = off;
    parse_return ret = detail::unpack_imp(
        data, len, noff, *z, obj, referenced, f, user_data, limit);

    switch(ret) {
    case PARSE_SUCCESS:
        off = noff;
        result.set(obj);
        result.zone() = agpack::move(z);
        return;
    case PARSE_EXTRA_BYTES:
        off = noff;
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
    unpack_reference_func f, void* user_data,
            unpack_limit const& limit)
{
    bool referenced;
    agpack::v2::unpack(result, data, len, off, referenced, f, user_data, limit);
}

inline void unpack(
    agpack::object_handle& result,
    const char* data, std::size_t len, bool& referenced,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    std::size_t off = 0;
    agpack::v2::unpack(result, data, len, off, referenced, f, user_data, limit);
}

inline void unpack(
    agpack::object_handle& result,
    const char* data, std::size_t len,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    bool referenced;
    std::size_t off = 0;
    agpack::v2::unpack(result, data, len, off, referenced, f, user_data, limit);
}


inline agpack::object unpack(
    agpack::zone& z,
    const char* data, std::size_t len, std::size_t& off, bool& referenced,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    agpack::object obj;
    std::size_t noff = off;
    referenced = false;
    parse_return ret = detail::unpack_imp(
        data, len, noff, z, obj, referenced, f, user_data, limit);

    switch(ret) {
    case PARSE_SUCCESS:
        off = noff;
        return obj;
    case PARSE_EXTRA_BYTES:
        off = noff;
        return obj;
    default:
        break;
    }
    return obj;
}

inline agpack::object unpack(
    agpack::zone& z,
    const char* data, std::size_t len, std::size_t& off,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    bool referenced;
    return agpack::v2::unpack(z, data, len, off, referenced, f, user_data, limit);
}

inline agpack::object unpack(
    agpack::zone& z,
    const char* data, std::size_t len, bool& referenced,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    std::size_t off = 0;
    return agpack::v2::unpack(z, data, len, off, referenced, f, user_data, limit);
}

inline agpack::object unpack(
    agpack::zone& z,
    const char* data, std::size_t len,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    bool referenced;
    std::size_t off = 0;
    return agpack::v2::unpack(z, data, len, off, referenced, f, user_data, limit);
}

namespace detail {

inline parse_return
unpack_imp(const char* data, std::size_t len, std::size_t& off,
           agpack::zone& result_zone, agpack::object& result, bool& referenced,
           unpack_reference_func f = AGPACK_NULLPTR, void* user_data = AGPACK_NULLPTR,
           unpack_limit const& limit = unpack_limit())
{
    create_object_visitor v(f, user_data, limit);
    v.set_zone(result_zone);
    referenced = false;
    v.set_referenced(referenced);
    parse_return ret = parse_imp(data, len, off, v);
    referenced = v.referenced();
    result = v.data();
    return ret;
}

} // namespace detail


/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

}  // namespace agpack

#endif // AGPACK_DEFAULT_API_VERSION >= 2

#endif // AGPACK_V2_UNPACK_HPP
