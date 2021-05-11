//
// MessagePack for C++ deserializing routine
//
// Copyright (C) 2017 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V2_CREATE_OBJECT_VISITOR_HPP
#define AGPACK_V2_CREATE_OBJECT_VISITOR_HPP

#include "agpack/unpack_decl.hpp"
#include "agpack/unpack_exception.hpp"
#include "agpack/v2/create_object_visitor_decl.hpp"
#include "agpack/v2/null_visitor.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

namespace detail {

class create_object_visitor : public agpack::v2::null_visitor {
public:
    create_object_visitor(unpack_reference_func f, void* user_data, unpack_limit const& limit)
        :m_func(f), m_user_data(user_data), m_limit(limit) {
        m_stack.reserve(AGPACK_EMBED_STACK_SIZE);
        m_stack.push_back(&m_obj);
    }

#if !defined(AGPACK_USE_CPP03)
    create_object_visitor(create_object_visitor&& other)
        :m_func(other.m_func),
         m_user_data(other.m_user_data),
         m_limit(std::move(other.m_limit)),
         m_stack(std::move(other.m_stack)),
         m_zone(other.m_zone),
         m_referenced(other.m_referenced) {
        other.m_zone = AGPACK_NULLPTR;
        m_stack[0] = &m_obj;
    }
    create_object_visitor& operator=(create_object_visitor&& other) {
        this->~create_object_visitor();
        new (this) create_object_visitor(std::move(other));
        return *this;
    }
#endif // !defined(AGPACK_USE_CPP03)

    void init() {
        m_stack.resize(1);
        m_obj = agpack::object();
        m_stack[0] = &m_obj;
    }
    agpack::object const& data() const
    {
        return m_obj;
    }
    agpack::zone const& zone() const { return *m_zone; }
    agpack::zone& zone() { return *m_zone; }
    void set_zone(agpack::zone& zone) { m_zone = &zone; }
    bool referenced() const { return m_referenced; }
    void set_referenced(bool referenced) { m_referenced = referenced; }
    // visit functions
    bool visit_nil() {
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::NIL;
        return true;
    }
    bool visit_boolean(bool v) {
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::BOOLEAN;
        obj->via.boolean = v;
        return true;
    }
    bool visit_positive_integer(uint64_t v) {
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::POSITIVE_INTEGER;
        obj->via.u64 = v;
        return true;
    }
    bool visit_negative_integer(int64_t v) {
        agpack::object* obj = m_stack.back();
        if(v >= 0) {
            obj->type = agpack::type::POSITIVE_INTEGER;
            obj->via.u64 = static_cast<uint64_t>(v);
        }
        else {
            obj->type = agpack::type::NEGATIVE_INTEGER;
            obj->via.i64 = v;
        }
        return true;
    }
    bool visit_float32(float v) {
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::FLOAT32;
        obj->via.f64 = v;
        return true;
    }
    bool visit_float64(double v) {
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::FLOAT64;
        obj->via.f64 = v;
        return true;
    }
    bool visit_str(const char* v, uint32_t size) {
        if (size > m_limit.str()) throw agpack::str_size_overflow("str size overflow");
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::STR;
        if (m_func && m_func(obj->type, size, m_user_data)) {
            obj->via.str.ptr = v;
            set_referenced(true);
        }
        else {
            char* tmp = static_cast<char*>(zone().allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
            std::memcpy(tmp, v, size);
            obj->via.str.ptr = tmp;
        }
        obj->via.str.size = size;
        return true;
    }
    bool visit_bin(const char* v, uint32_t size) {
        if (size > m_limit.bin()) throw agpack::bin_size_overflow("bin size overflow");
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::BIN;
        if (m_func && m_func(obj->type, size, m_user_data)) {
            obj->via.bin.ptr = v;
            set_referenced(true);
        }
        else {
            char* tmp = static_cast<char*>(zone().allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
            std::memcpy(tmp, v, size);
            obj->via.bin.ptr = tmp;
        }
        obj->via.bin.size = size;
        return true;
    }
    bool visit_ext(const char* v, uint32_t size) {
        if (size > m_limit.ext()) throw agpack::ext_size_overflow("ext size overflow");
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::EXT;
        if (m_func && m_func(obj->type, size, m_user_data)) {
            obj->via.ext.ptr = v;
            set_referenced(true);
        }
        else {
            char* tmp = static_cast<char*>(zone().allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
            std::memcpy(tmp, v, size);
            obj->via.ext.ptr = tmp;
        }
        obj->via.ext.size = static_cast<uint32_t>(size - 1);
        return true;
    }
    bool start_array(uint32_t num_elements) {
        if (num_elements > m_limit.array()) throw agpack::array_size_overflow("array size overflow");
        if (m_stack.size() > m_limit.depth()) throw agpack::depth_size_overflow("depth size overflow");
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::ARRAY;
        obj->via.array.size = num_elements;
        if (num_elements == 0) {
            obj->via.array.ptr = AGPACK_NULLPTR;
        }
        else {

#if SIZE_MAX == UINT_MAX
            if (num_elements > SIZE_MAX/sizeof(agpack::object))
                throw agpack::array_size_overflow("array size overflow");
#endif // SIZE_MAX == UINT_MAX

            size_t size = num_elements*sizeof(agpack::object);
            obj->via.array.ptr =
                static_cast<agpack::object*>(m_zone->allocate_align(size, AGPACK_ZONE_ALIGNOF(agpack::object)));
        }
        m_stack.push_back(obj->via.array.ptr);
        return true;
    }
    bool start_array_item() {
        return true;
    }
    bool end_array_item() {
        ++m_stack.back();
        return true;
    }
    bool end_array() {
        m_stack.pop_back();
        return true;
    }
    bool start_map(uint32_t num_kv_pairs) {
        if (num_kv_pairs > m_limit.map()) throw agpack::map_size_overflow("map size overflow");
        if (m_stack.size() > m_limit.depth()) throw agpack::depth_size_overflow("depth size overflow");
        agpack::object* obj = m_stack.back();
        obj->type = agpack::type::MAP;
        obj->via.map.size = num_kv_pairs;
        if (num_kv_pairs == 0) {
            obj->via.map.ptr = AGPACK_NULLPTR;
        }
        else {

#if SIZE_MAX == UINT_MAX
            if (num_kv_pairs > SIZE_MAX/sizeof(agpack::object_kv))
                throw agpack::map_size_overflow("map size overflow");
#endif // SIZE_MAX == UINT_MAX
            size_t size = num_kv_pairs*sizeof(agpack::object_kv);
            obj->via.map.ptr =
                static_cast<agpack::object_kv*>(m_zone->allocate_align(size, AGPACK_ZONE_ALIGNOF(agpack::object_kv)));
        }
        m_stack.push_back(reinterpret_cast<agpack::object*>(obj->via.map.ptr));
        return true;
    }
    bool start_map_key() {
        return true;
    }
    bool end_map_key() {
        ++m_stack.back();
        return true;
    }
    bool start_map_value() {
        return true;
    }
    bool end_map_value() {
        ++m_stack.back();
        return true;
    }
    bool end_map() {
        m_stack.pop_back();
        return true;
    }
    void parse_error(size_t /*parsed_offset*/, size_t /*error_offset*/) {
        throw agpack::parse_error("parse error");
    }
    void insufficient_bytes(size_t /*parsed_offset*/, size_t /*error_offset*/) {
        throw agpack::insufficient_bytes("insufficient bytes");
    }
private:
public:
    unpack_reference_func m_func;
    void* m_user_data;
    unpack_limit m_limit;
    agpack::object m_obj;
    std::vector<agpack::object*> m_stack;
    agpack::zone* m_zone;
    bool m_referenced;
};

} // detail

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V2_CREATE_OBJECT_VISITOR_HPP
