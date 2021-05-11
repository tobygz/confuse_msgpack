//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2014 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_OBJECT_HPP
#define AGPACK_V1_OBJECT_HPP

#include "agpack/object_decl.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <cstring>
#include <stdexcept>
#include <typeinfo>
#include <limits>
#include <ostream>
#include <typeinfo>
#include <iomanip>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

struct object_kv {
    agpack::object key;
    agpack::object val;
};

struct object::with_zone : agpack::object {
    with_zone(agpack::zone& z) : zone(z) { }
    agpack::zone& zone;
private:
    with_zone();
};


/// The class holds object and zone
class object_handle {
public:
    /// Constructor that creates nil object and null zone.
    object_handle() {}

    /// Constructor that creates an object_handle holding object `obj` and zone `z`.
    /**
     * @param obj object
     * @param z zone
     */
    object_handle(
        agpack::object const& obj,
#if defined(AGPACK_USE_CPP03)
        agpack::unique_ptr<agpack::zone> z
#else  // defined(AGPACK_USE_CPP03)
        agpack::unique_ptr<agpack::zone>&& z
#endif // defined(AGPACK_USE_CPP03)
    ) :
        m_obj(obj), m_zone(agpack::move(z)) { }

    void set(agpack::object const& obj)
        { m_obj = obj; }

    /// Get object reference
    /**
     * @return object
     */
    const agpack::object& get() const
        { return m_obj; }

    /**
     * @return object (to mimic smart pointers).
     */
    const agpack::object& operator*() const
        { return get(); }

    /**
     * @return the address of the object (to mimic smart pointers).
     */
    const agpack::object* operator->() const
        { return &get(); }

    /// Get unique_ptr reference of zone.
    /**
     * @return unique_ptr reference of zone
     */
    agpack::unique_ptr<agpack::zone>& zone()
        { return m_zone; }

    /// Get unique_ptr const reference of zone.
    /**
     * @return unique_ptr const reference of zone
     */
    const agpack::unique_ptr<agpack::zone>& zone() const
        { return m_zone; }

#if defined(AGPACK_USE_CPP03)
    struct object_handle_ref {
        object_handle_ref(object_handle* oh):m_oh(oh) {}
        object_handle* m_oh;
    };

    object_handle(object_handle& other):
        m_obj(other.m_obj),
        m_zone(agpack::move(other.m_zone)) {
    }

    object_handle(object_handle_ref ref):
        m_obj(ref.m_oh->m_obj),
        m_zone(agpack::move(ref.m_oh->m_zone)) {
    }

    object_handle& operator=(object_handle& other) {
        m_obj = other.m_obj;
        m_zone = agpack::move(other.m_zone);
        return *this;
    }

    object_handle& operator=(object_handle_ref ref) {
        m_obj = ref.m_oh->m_obj;
        m_zone = agpack::move(ref.m_oh->m_zone);
        return *this;
    }

    operator object_handle_ref() {
        return object_handle_ref(this);
    }
#endif // defined(AGPACK_USE_CPP03)

private:
    agpack::object m_obj;
    agpack::unique_ptr<agpack::zone> m_zone;
};

namespace detail {

template <std::size_t N>
inline std::size_t add_ext_type_size(std::size_t size) {
    return size + 1;
}

template <>
inline std::size_t add_ext_type_size<4>(std::size_t size) {
    return size == 0xffffffff ? size : size + 1;
}

} // namespace detail
class object_parser {
private:
    enum next_ret {
        cont,
        finish,
        abort
    };
    struct elem {
        elem(agpack::object const* p, std::size_t r)
            : rest(r), is_map(false), is_key(false) {
            as.obj_ptr = p;
        }

        elem(agpack::object_kv const* p, std::size_t r)
            : rest(r), is_map(true), is_key(true) {
            as.kv_ptr = p;
        }

        agpack::object const& get() const {
            if (is_map) {
                if (is_key) {
                    return as.kv_ptr->key;
                }
                else {
                    return as.kv_ptr->val;
                }
            }
            else {
                return *as.obj_ptr;
            }
        }

        template <typename Visitor>
        next_ret next(Visitor& v) {
            if (rest == 0) {
                if (is_map) {
                    if (!v.end_map()) return abort;
                }
                else {
                    if (!v.end_array()) return abort;
                }
                return finish;
            }
            else {
                if (is_map) {
                    if (is_key) {
                        if (!v.end_map_key()) return abort;
                        if (!v.start_map_value()) return abort;
                        is_key = false;
                    }
                    else {
                        if (!v.end_map_value()) return abort;
                        --rest;
                        if (rest == 0) {
                            if (!v.end_map()) return abort;
                            return finish;
                        }
                        if (!v.start_map_key()) return abort;
                        ++as.kv_ptr;
                        is_key = true;
                    }
                }
                else {
                    if (!v.end_array_item()) return abort;
                    --rest;
                    if (rest == 0) {
                        if (!v.end_array()) return abort;
                        return finish;
                    }
                    if (!v.start_array_item()) return abort;
                    ++as.obj_ptr;
                }
                return cont;
            }
        }

        union {
            agpack::object const* obj_ptr;
            agpack::object_kv const* kv_ptr;
        } as;
        std::size_t rest;
        bool is_map;
        bool is_key;
    };
public:
    explicit object_parser(agpack::object const& obj):m_current(&obj) {}
    template <typename Visitor>
    void parse(Visitor& v) {
        while (true) {
            bool start_collection = false;
            switch(m_current->type) {
            case agpack::type::NIL:
                if (!v.visit_nil()) return;
                break;
            case agpack::type::BOOLEAN:
                if (!v.visit_boolean(m_current->via.boolean)) return;
                break;
            case agpack::type::POSITIVE_INTEGER:
                if (!v.visit_positive_integer(m_current->via.u64)) return;
                break;
            case agpack::type::NEGATIVE_INTEGER:
                if (!v.visit_negative_integer(m_current->via.i64)) return;
                break;
            case agpack::type::FLOAT32:
                if (!v.visit_float32(static_cast<float>(m_current->via.f64))) return;
                break;
            case agpack::type::FLOAT64:
                if (!v.visit_float64(m_current->via.f64)) return;
                break;
            case agpack::type::STR:
                if (!v.visit_str(m_current->via.str.ptr, m_current->via.str.size)) return;
                break;
            case agpack::type::BIN:
                if (!v.visit_bin(m_current->via.bin.ptr, m_current->via.bin.size)) return;
                break;
            case agpack::type::EXT:
                agpack::detail::check_container_size<sizeof(std::size_t)>(m_current->via.ext.size);
                if (!v.visit_ext(m_current->via.ext.ptr, m_current->via.ext.size + 1)) return;
                break;
            case agpack::type::ARRAY:
                if (!v.start_array(m_current->via.array.size)) return;
                m_ctx.push_back(elem(m_current->via.array.ptr, m_current->via.array.size));
                start_collection = m_current->via.array.size != 0;
                if (start_collection) {
                    if (!v.start_array_item()) return;
                }
                break;
            case agpack::type::MAP:
                if (!v.start_map(m_current->via.map.size)) return;
                m_ctx.push_back(elem(m_current->via.map.ptr, m_current->via.map.size));
                start_collection = m_current->via.map.size != 0;
                if (start_collection) {
                    if (!v.start_map_key()) return;
                }
                break;
            default:
                throw agpack::type_error();
                break;
            }
            if (m_ctx.empty()) return;
            if (!start_collection) {
                while (true) {
                    next_ret r = m_ctx.back().next(v);
                    if (r == finish) {
                        m_ctx.pop_back();
                        if (m_ctx.empty()) return;
                    }
                    else if (r == cont) {
                        break;
                    }
                    else {
                        // abort
                        return;
                    }
                }
            }
            m_current = &m_ctx.back().get();
        }
    }
private:
    agpack::object const* m_current;
    std::vector<elem> m_ctx;
};

template <typename Stream>
struct object_pack_visitor {
    explicit object_pack_visitor(agpack::packer<Stream>& pk)
        :m_packer(pk) {}
    bool visit_nil() {
        m_packer.pack_nil();
        return true;
    }
    bool visit_boolean(bool v) {
        if (v) m_packer.pack_true();
        else m_packer.pack_false();
        return true;
    }
    bool visit_positive_integer(uint64_t v) {
        m_packer.pack_uint64(v);
        return true;
    }
    bool visit_negative_integer(int64_t v) {
        m_packer.pack_int64(v);
        return true;
    }
    bool visit_float32(float v) {
        m_packer.pack_float(v);
        return true;
    }
    bool visit_float64(double v) {
        m_packer.pack_double(v);
        return true;
    }
    bool visit_str(const char* v, uint32_t size) {
        m_packer.pack_str(size);
        m_packer.pack_str_body(v, size);
        return true;
    }
    bool visit_bin(const char* v, uint32_t size) {
        m_packer.pack_bin(size);
        m_packer.pack_bin_body(v, size);
        return true;
    }
    bool visit_ext(const char* v, uint32_t size) {
        m_packer.pack_ext(size - 1, static_cast<int8_t>(*v));
        m_packer.pack_ext_body(v + 1, size - 1);
        return true;
    }
    bool start_array(uint32_t num_elements) {
        m_packer.pack_array(num_elements);
        return true;
    }
    bool start_array_item() {
        return true;
    }
    bool end_array_item() {
        return true;
    }
    bool end_array() {
        return true;
    }
    bool start_map(uint32_t num_kv_pairs) {
        m_packer.pack_map(num_kv_pairs);
        return true;
    }
    bool start_map_key() {
        return true;
    }
    bool end_map_key() {
        return true;
    }
    bool start_map_value() {
        return true;
    }
    bool end_map_value() {
        return true;
    }
    bool end_map() {
        return true;
    }
private:
    agpack::packer<Stream>& m_packer;
};


struct object_stringize_visitor {
    explicit object_stringize_visitor(std::ostream& os)
        :m_os(os) {}
    bool visit_nil() {
        m_os << "null";
        return true;
    }
    bool visit_boolean(bool v) {
        if (v) m_os << "true";
        else m_os << "false";
        return true;
    }
    bool visit_positive_integer(uint64_t v) {
        m_os << v;
        return true;
    }
    bool visit_negative_integer(int64_t v) {
        m_os << v;
        return true;
    }
    bool visit_float32(float v) {
        m_os << v;
        return true;
    }
    bool visit_float64(double v) {
        m_os << v;
        return true;
    }
    bool visit_str(const char* v, uint32_t size) {
        m_os << '"';
        for (uint32_t i = 0; i < size; ++i) {
            char c = v[i];
            switch (c) {
            case '\\':
                m_os << "\\\\";
                break;
            case '"':
                m_os << "\\\"";
                break;
            case '/':
                m_os << "\\/";
                break;
            case '\b':
                m_os << "\\b";
                break;
            case '\f':
                m_os << "\\f";
                break;
            case '\n':
                m_os << "\\n";
                break;
            case '\r':
                m_os << "\\r";
                break;
            case '\t':
                m_os << "\\t";
                break;
            default: {
                unsigned int code = static_cast<unsigned int>(c);
                if (code < 0x20 || code == 0x7f) {
                    std::ios::fmtflags flags(m_os.flags());
                    m_os << "\\u" << std::hex << std::setw(4) << std::setfill('0') << (code & 0xff);
                    m_os.flags(flags);
                }
                else {
                    m_os << c;
                }
            } break;
            }
        }
        m_os << '"';
        return true;
    }
    bool visit_bin(const char* v, uint32_t size) {
        (m_os << '"').write(v, static_cast<std::streamsize>(size)) << '"';
        return true;
    }
    bool visit_ext(const char* /*v*/, uint32_t /*size*/) {
        m_os << "EXT";
        return true;
    }
    bool start_array(uint32_t num_elements) {
        m_current_size.push_back(num_elements);
        m_os << "[";
        return true;
    }
    bool start_array_item() {
        return true;
    }
    bool end_array_item() {
        --m_current_size.back();
        if (m_current_size.back() != 0) {
            m_os << ",";
        }
        return true;
    }
    bool end_array() {
        m_current_size.pop_back();
        m_os << "]";
        return true;
    }
    bool start_map(uint32_t num_kv_pairs) {
        m_current_size.push_back(num_kv_pairs);
        m_os << "{";
        return true;
    }
    bool start_map_key() {
        return true;
    }
    bool end_map_key() {
        m_os << ":";
        return true;
    }
    bool start_map_value() {
        return true;
    }
    bool end_map_value() {
        --m_current_size.back();
        if (m_current_size.back() != 0) {
            m_os << ",";
        }
        return true;
    }
    bool end_map() {
        m_current_size.pop_back();
        m_os << "}";
        return true;
    }
private:
    std::ostream& m_os;
    std::vector<uint32_t> m_current_size;
};

struct aligned_zone_size_visitor {
    explicit aligned_zone_size_visitor(std::size_t& s)
        :m_size(s) {}
    bool visit_nil() {
        return true;
    }
    bool visit_boolean(bool) {
        return true;
    }
    bool visit_positive_integer(uint64_t) {
        return true;
    }
    bool visit_negative_integer(int64_t) {
        return true;
    }
    bool visit_float32(float) {
        return true;
    }
    bool visit_float64(double) {
        return true;
    }
    bool visit_str(const char*, uint32_t size) {
        m_size += agpack::aligned_size(size, AGPACK_ZONE_ALIGNOF(char));
        return true;
    }
    bool visit_bin(const char*, uint32_t size) {
        m_size += agpack::aligned_size(size, AGPACK_ZONE_ALIGNOF(char));
        return true;
    }
    bool visit_ext(const char*, uint32_t size) {
        m_size += agpack::aligned_size(size, AGPACK_ZONE_ALIGNOF(char));
        return true;
    }
    bool start_array(uint32_t num_elements) {
        m_size += agpack::aligned_size(
            sizeof(agpack::object) * num_elements,
            AGPACK_ZONE_ALIGNOF(agpack::object));
        return true;
    }
    bool start_array_item() {
        return true;
    }
    bool end_array_item() {
        return true;
    }
    bool end_array() {
        return true;
    }
    bool start_map(uint32_t num_kv_pairs) {
        m_size += agpack::aligned_size(
            sizeof(agpack::object_kv) * num_kv_pairs,
            AGPACK_ZONE_ALIGNOF(agpack::object_kv));
        return true;
    }
    bool start_map_key() {
        return true;
    }
    bool end_map_key() {
        return true;
    }
    bool start_map_value() {
        return true;
    }
    bool end_map_value() {
        return true;
    }
    bool end_map() {
        return true;
    }
private:
    std::size_t& m_size;
};

inline std::size_t aligned_zone_size(agpack::object const& obj) {
    std::size_t s = 0;
    aligned_zone_size_visitor vis(s);
    agpack::object_parser(obj).parse(vis);
    return s;
}

/// clone object
/**
 * Clone (deep copy) object.
 * The copied object is located on newly allocated zone.
 * @param obj copy source object
 *
 * @return object_handle that holds deep copied object and zone.
 */
inline object_handle clone(agpack::object const& obj) {
    std::size_t size = agpack::aligned_zone_size(obj);
    agpack::unique_ptr<agpack::zone> z(size == 0 ? AGPACK_NULLPTR : new agpack::zone(size));
    agpack::object newobj = z.get() ? agpack::object(obj, *z) : obj;
    return object_handle(newobj, agpack::move(z));
}

template <typename T>
inline object::implicit_type::operator T() { return obj.as<T>(); }

namespace detail {
template <typename Stream, typename T>
struct packer_serializer {
    static agpack::packer<Stream>& pack(agpack::packer<Stream>& o, const T& v) {
        v.agpack_pack(o);
        return o;
    }
};
} // namespace detail

// Adaptor functors' member functions definitions.
template <typename T, typename Enabler>
inline
agpack::object const&
adaptor::convert<T, Enabler>::operator()(agpack::object const& o, T& v) const {
    v.agpack_unpack(o.convert());
    return o;
}

template <typename T, typename Enabler>
template <typename Stream>
inline
agpack::packer<Stream>&
adaptor::pack<T, Enabler>::operator()(agpack::packer<Stream>& o, T const& v) const {
    return agpack::detail::packer_serializer<Stream, T>::pack(o, v);
}

template <typename T, typename Enabler>
inline
void
adaptor::object_with_zone<T, Enabler>::operator()(agpack::object::with_zone& o, T const& v) const {
    v.agpack_object(static_cast<agpack::object*>(&o), o.zone);
}

// Adaptor functor specialization to object
namespace adaptor {

template <>
struct convert<agpack::object> {
    agpack::object const& operator()(agpack::object const& o, agpack::object& v) const {
        v = o;
        return o;
    }
};

template <>
struct pack<agpack::object> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, agpack::object const& v) const {
        object_pack_visitor<Stream> vis(o);
        agpack::object_parser(v).parse(vis);
        return o;
    }
};

template <>
struct object_with_zone<agpack::object> {
    void operator()(agpack::object::with_zone& o, agpack::object const& v) const {
        object_with_zone_visitor vis(o);
        agpack::object_parser(v).parse(vis);
    }
private:
    struct object_with_zone_visitor {
        explicit object_with_zone_visitor(agpack::object::with_zone& owz)
            :m_zone(owz.zone), m_ptr(&owz) {
            m_objs.push_back(&owz);
        }
        bool visit_nil() {
            m_ptr->type = agpack::type::NIL;
            return true;
        }
        bool visit_boolean(bool v) {
            m_ptr->type = agpack::type::BOOLEAN;
            m_ptr->via.boolean = v;
            return true;
        }
        bool visit_positive_integer(uint64_t v) {
            m_ptr->type = agpack::type::POSITIVE_INTEGER;
            m_ptr->via.u64 = v;
            return true;
        }
        bool visit_negative_integer(int64_t v) {
            m_ptr->type = agpack::type::NEGATIVE_INTEGER;
            m_ptr->via.i64 = v;
            return true;
        }
        bool visit_float32(float v) {
            m_ptr->type = agpack::type::FLOAT32;
            m_ptr->via.f64 = v;
            return true;
        }
        bool visit_float64(double v) {
            m_ptr->type = agpack::type::FLOAT64;
            m_ptr->via.f64 = v;
            return true;
        }
        bool visit_str(const char* v, uint32_t size) {
            m_ptr->type = agpack::type::STR;
            m_ptr->via.str.size = size;
            char* ptr = static_cast<char*>(m_zone.allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
            m_ptr->via.str.ptr = ptr;
            std::memcpy(ptr, v, size);
            return true;
        }
        bool visit_bin(const char* v, uint32_t size) {
            m_ptr->type = agpack::type::BIN;
            m_ptr->via.bin.size = size;
            char* ptr = static_cast<char*>(m_zone.allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
            m_ptr->via.bin.ptr = ptr;
            std::memcpy(ptr, v, size);
            return true;
        }
        bool visit_ext(const char* v, uint32_t size) {
            m_ptr->type = agpack::type::EXT;

            // v contains type but length(size) doesn't count the type byte.
            // See https://github.com/agpack/agpack/blob/master/spec.md#ext-format-family
            m_ptr->via.ext.size = size - 1;

            char* ptr = static_cast<char*>(m_zone.allocate_align(size, AGPACK_ZONE_ALIGNOF(char)));
            m_ptr->via.ext.ptr = ptr;
            std::memcpy(ptr, v, size);
            return true;
        }
        bool start_array(uint32_t num_elements) {
            m_ptr->type = agpack::type::ARRAY;
            m_ptr->via.array.ptr = static_cast<agpack::object*>(
                m_zone.allocate_align(
                    sizeof(agpack::object) * num_elements, AGPACK_ZONE_ALIGNOF(agpack::object)));
            m_ptr->via.array.size = num_elements;
            m_objs.push_back(elem(m_ptr->via.array.ptr));
            return true;
        }
        bool start_array_item() {
            m_ptr = m_objs.back().get_item();
            return true;
        }
        bool end_array_item() {
            ++m_objs.back().as.obj;
            return true;
        }
        bool end_array() {
            m_objs.pop_back();
            return true;
        }
        bool start_map(uint32_t num_kv_pairs) {
            m_ptr->type = agpack::type::MAP;
            m_ptr->via.map.ptr = (agpack::object_kv*)m_zone.allocate_align(
                sizeof(agpack::object_kv) * num_kv_pairs, AGPACK_ZONE_ALIGNOF(agpack::object_kv));
            m_ptr->via.map.size = num_kv_pairs;
            m_objs.push_back(elem(m_ptr->via.map.ptr));
            return true;
        }
        bool start_map_key() {
            m_ptr = m_objs.back().get_key();
            return true;
        }
        bool end_map_key() {
            return true;
        }
        bool start_map_value() {
            m_ptr = m_objs.back().get_val();
            return true;
        }
        bool end_map_value() {
            ++m_objs.back().as.kv;
            return true;
        }
        bool end_map() {
            m_objs.pop_back();
            return true;
        }
    private:
        struct elem {
            elem(agpack::object* obj)
                :is_obj(true) {
                as.obj = obj;
            }
            elem(agpack::object_kv* kv)
                :is_obj(false) {
                as.kv = kv;
            }
            agpack::object* get_item() {
                return as.obj;
            }
            agpack::object* get_key() {
                return &as.kv->key;
            }
            agpack::object* get_val() {
                return &as.kv->val;
            }
            union {
                agpack::object* obj;
                agpack::object_kv* kv;
            } as;
            bool is_obj;
        };
        std::vector<elem> m_objs;
        agpack::zone& m_zone;
        agpack::object* m_ptr;
    };
};

// Adaptor functor specialization to object::with_zone

template <>
struct object_with_zone<agpack::object::with_zone> {
    void operator()(
        agpack::object::with_zone& o,
        agpack::object::with_zone const& v) const {
        o << static_cast<agpack::object const&>(v);
    }
};


} // namespace adaptor


// obsolete
template <typename Type>
class define : public Type {
public:
    typedef Type agpack_type;
    typedef define<Type> define_type;
    define() {}
    define(const agpack_type& v) : agpack_type(v) {}

    template <typename Packer>
    void agpack_pack(Packer& o) const
    {
        agpack::operator<<(o, static_cast<const agpack_type&>(*this));
    }

    void agpack_unpack(object const& o)
    {
        agpack::operator>>(o, static_cast<agpack_type&>(*this));
    }
};

// deconvert operator

template <typename Stream>
template <typename T>
inline agpack::packer<Stream>& packer<Stream>::pack(const T& v)
{
    agpack::operator<<(*this, v);
    return *this;
}

struct object_equal_visitor {
    object_equal_visitor(agpack::object const& obj, bool& result)
        :m_ptr(&obj), m_result(result) {}
    bool visit_nil() {
        if (m_ptr->type != agpack::type::NIL) {
            m_result = false;
            return false;
        }
        return true;
    }
    bool visit_boolean(bool v) {
        if (m_ptr->type != agpack::type::BOOLEAN || m_ptr->via.boolean != v) {
            m_result = false;
            return false;
        }
        return true;
    }
    bool visit_positive_integer(uint64_t v) {
        if (m_ptr->type != agpack::type::POSITIVE_INTEGER || m_ptr->via.u64 != v) {
            m_result = false;
            return false;
        }
        return true;
    }
    bool visit_negative_integer(int64_t v) {
        if (m_ptr->type != agpack::type::NEGATIVE_INTEGER || m_ptr->via.i64 != v) {
            m_result = false;
            return false;
        }
        return true;
    }
    bool visit_float32(float v) {
        if (m_ptr->type != agpack::type::FLOAT32 || m_ptr->via.f64 != v) {
            m_result = false;
            return false;
        }
        return true;
    }
    bool visit_float64(double v) {
        if (m_ptr->type != agpack::type::FLOAT64 || m_ptr->via.f64 != v) {
            m_result = false;
            return false;
        }
        return true;
    }
    bool visit_str(const char* v, uint32_t size) {
        if (m_ptr->type != agpack::type::STR ||
            m_ptr->via.str.size != size ||
            std::memcmp(m_ptr->via.str.ptr, v, size) != 0) {
            m_result = false;
            return false;
        }
        return true;
    }
    bool visit_bin(const char* v, uint32_t size) {
        if (m_ptr->type != agpack::type::BIN ||
            m_ptr->via.bin.size != size ||
            std::memcmp(m_ptr->via.bin.ptr, v, size) != 0) {
            m_result = false;
            return false;
        }
        return true;
    }
    bool visit_ext(const char* v, uint32_t size) {
        if (m_ptr->type != agpack::type::EXT ||
            m_ptr->via.ext.size != size - 1 ||
            std::memcmp(m_ptr->via.ext.ptr, v, size) != 0) {
            m_result = false;
            return false;
        }
        return true;
    }
    bool start_array(uint32_t num_elements) {
        if (m_ptr->type != agpack::type::ARRAY ||
            m_ptr->via.array.size != num_elements) {
            m_result = false;
            return false;
        }
        m_objs.push_back(elem(m_ptr->via.array.ptr));
        return true;
    }
    bool start_array_item() {
        m_ptr = m_objs.back().get_item();
        return true;
    }
    bool end_array_item() {
        ++m_objs.back().as.obj;
        return true;
    }
    bool end_array() {
        m_objs.pop_back();
        return true;
    }
    bool start_map(uint32_t num_kv_pairs) {
        if (m_ptr->type != agpack::type::MAP ||
            m_ptr->via.array.size != num_kv_pairs) {
            m_result = false;
            return false;
        }
        m_objs.push_back(elem(m_ptr->via.map.ptr));
        return true;
    }
    bool start_map_key() {
        m_ptr = m_objs.back().get_key();
        return true;
    }
    bool end_map_key() {
        return true;
    }
    bool start_map_value() {
        m_ptr = m_objs.back().get_val();
        return true;
    }
    bool end_map_value() {
        ++m_objs.back().as.kv;
        return true;
    }
    bool end_map() {
        m_objs.pop_back();
        return true;
    }
private:
    struct elem {
        elem(agpack::object const* obj)
            :is_obj(true) {
            as.obj = obj;
        }
        elem(agpack::object_kv const* kv)
            :is_obj(false) {
            as.kv = kv;
        }
        agpack::object const* get_item() {
            return as.obj;
        }
        agpack::object const* get_key() {
            return &as.kv->key;
        }
        agpack::object const* get_val() {
            return &as.kv->val;
        }
        union {
            agpack::object const* obj;
            agpack::object_kv const* kv;
        } as;
        bool is_obj;
    };
    std::vector<elem> m_objs;
    agpack::object const* m_ptr;
    bool& m_result;
};

inline bool operator==(const agpack::object& x, const agpack::object& y)
{
    if(x.type != y.type) { return false; }
    bool b = true;
    object_equal_visitor vis(y, b);
    agpack::object_parser(x).parse(vis);
    return b;
}

template <typename T>
inline bool operator==(const agpack::object& x, const T& y)
try {
    return x == agpack::object(y);
} catch (agpack::type_error&) {
    return false;
}

inline bool operator!=(const agpack::object& x, const agpack::object& y)
{ return !(x == y); }

template <typename T>
inline bool operator==(const T& y, const agpack::object& x)
{ return x == y; }

template <typename T>
inline bool operator!=(const agpack::object& x, const T& y)
{ return !(x == y); }

template <typename T>
inline bool operator!=(const T& y, const agpack::object& x)
{ return x != y; }


inline object::implicit_type object::convert() const
{
    return object::implicit_type(*this);
}

template <typename T>
inline
typename agpack::enable_if<
    !agpack::is_array<T>::value && !agpack::is_pointer<T>::value,
    T&
>::type
object::convert(T& v) const
{
    agpack::operator>>(*this, v);
    return v;
}

template <typename T, std::size_t N>
inline T(&object::convert(T(&v)[N]) const)[N]
{
    agpack::operator>>(*this, v);
    return v;
}

#if !defined(AGPACK_DISABLE_LEGACY_CONVERT)
template <typename T>
inline
typename agpack::enable_if<
    agpack::is_pointer<T>::value,
    T
>::type
object::convert(T v) const
{
    convert(*v);
    return v;
}
#endif // !defined(AGPACK_DISABLE_LEGACY_CONVERT)

template <typename T>
inline bool object::convert_if_not_nil(T& v) const
{
    if (is_nil()) {
        return false;
    }
    convert(v);
    return true;
}

#if defined(AGPACK_USE_CPP03)

template <typename T>
inline T object::as() const
{
    T v;
    convert(v);
    return v;
}

#else  // defined(AGPACK_USE_CPP03)

template <typename T>
inline typename std::enable_if<agpack::has_as<T>::value, T>::type object::as() const {
    return agpack::adaptor::as<T>()(*this);
}

template <typename T>
inline typename std::enable_if<!agpack::has_as<T>::value, T>::type object::as() const {
    T v;
    convert(v);
    return v;
}

#endif // defined(AGPACK_USE_CPP03)

inline object::object()
{
    type = agpack::type::NIL;
}

template <typename T>
inline object::object(const T& v)
{
    *this << v;
}

template <typename T>
inline object& object::operator=(const T& v)
{
    *this = object(v);
    return *this;
}

template <typename T>
inline object::object(const T& v, agpack::zone& z)
{
    with_zone oz(z);
    agpack::operator<<(oz, v);
    type = oz.type;
    via = oz.via;
}

template <typename T>
inline object::object(const T& v, agpack::zone* z)
{
    with_zone oz(*z);
    agpack::operator<<(oz, v);
    type = oz.type;
    via = oz.via;
}


inline object::object(const agpack_object& o)
{
    // FIXME beter way?
    std::memcpy(this, &o, sizeof(o));
}

inline void operator<< (agpack::object& o, const agpack_object& v)
{
    // FIXME beter way?
    std::memcpy(static_cast<void*>(&o), &v, sizeof(v));
}

inline object::operator agpack_object() const
{
    // FIXME beter way?
    agpack_object obj;
    std::memcpy(&obj, this, sizeof(obj));
    return obj;
}


// obsolete
template <typename T>
inline void convert(T& v, agpack::object const& o)
{
    o.convert(v);
}

// obsolete
template <typename Stream, typename T>
inline void pack(agpack::packer<Stream>& o, const T& v)
{
    o.pack(v);
}

// obsolete
template <typename Stream, typename T>
inline void pack_copy(agpack::packer<Stream>& o, T v)
{
    pack(o, v);
}

template <typename Stream>
inline agpack::packer<Stream>& operator<< (agpack::packer<Stream>& o, const agpack::object& v)
{
    object_pack_visitor<Stream> vis(o);
    agpack::object_parser(v).parse(vis);
    return o;
}

template <typename Stream>
inline agpack::packer<Stream>& operator<< (agpack::packer<Stream>& o, const agpack::object::with_zone& v)
{
    return o << static_cast<agpack::object>(v);
}

inline std::ostream& operator<< (std::ostream& s, const agpack::object& v)
{
    object_stringize_visitor vis(s);
    agpack::object_parser(v).parse(vis);
    return s;
}

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_OBJECT_HPP
