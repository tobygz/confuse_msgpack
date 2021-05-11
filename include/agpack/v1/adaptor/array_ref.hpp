//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_ARRAY_REF_HPP
#define AGPACK_V1_TYPE_ARRAY_REF_HPP

#include "agpack/adaptor/check_container_size.hpp"
#include "agpack/cpp_config.hpp"
#include <cstring>
#include <string>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

template <typename T>
struct array_ref {
    array_ref() : data(AGPACK_NULLPTR) {}
    array_ref(T& t) : data(&t) {}

    T* data;

    std::size_t size() const {
        return data->size();
    }

    template <typename U>
    bool operator==(array_ref<U> const& t) const {
        return *data == *t.data;
    }
    template <typename U>
    bool operator!=(array_ref<U> const& t) const {
        return !(*data == *t.data);
    }
    template <typename U>
    bool operator< (array_ref<U> const& t) const
    {
        return *data < *t.data;
    }
    template <typename U>
    bool operator> (array_ref<U> const& t) const
    {
        return *t.data < *data;
    }
    template <typename U>
    bool operator<= (array_ref<U> const& t) const
    {
        return !(*t.data < *data);
    }
    template <typename U>
    bool operator>= (array_ref<U> const& t) const
    {
        return !(*data < *t.data);
    }
};

template <typename T, std::size_t N>
struct array_ref<T[N]> {
    array_ref() : data(AGPACK_NULLPTR) {}
    array_ref(T(&t)[N]) : data(t) {}

    T* data;

    std::size_t size() const {
        return N;
    }

    template <typename U>
    bool operator==(array_ref<U> const& t) const {
        if (N != t.size()) return false;
        T const* pself = data;
        U const* pother = t.data;
        for (; pself != &data[N]; ++pself, ++pother) {
            if (*pself != *pother) return false;
        }
        return true;
    }
    template <typename U>
    bool operator!=(array_ref<U> const& t) const {
        return !(*this == t);
    }
    template <typename U>
    bool operator< (array_ref<U> const& t) const
    {
        T const* pself = data;
        U const* pother = t.data;
        for (; pself != &data[N] && pother != t.data[t.size()]; ++pself, ++pother) {
            if (*pself < *pother) return true;
        }
        if (N < t.size()) return true;
        return false;
    }
    template <typename U>
    bool operator> (array_ref<U> const& t) const
    {
        return t.data < data;
    }
    template <typename U>
    bool operator<= (array_ref<U> const& t) const
    {
        return !(t.data < data);
    }
    template <typename U>
    bool operator>= (array_ref<U> const& t) const
    {
        return !(data < t.data);
    }
};

template <typename T>
inline
typename agpack::enable_if<
    !agpack::is_array<T const>::value,
    array_ref<T const>
>::type
make_array_ref(const T& t) {
    return array_ref<T const>(t);
}

template <typename T>
inline
typename agpack::enable_if<
    !agpack::is_array<T>::value,
    array_ref<T>
>::type
make_array_ref(T& t) {
    return array_ref<T>(t);
}

template <typename T, std::size_t N>
inline array_ref<const T[N]> make_array_ref(const T(&t)[N]) {
    return array_ref<const T[N]>(t);
}

template <typename T, std::size_t N>
inline array_ref<T[N]> make_array_ref(T(&t)[N]) {
    return array_ref<T[N]>(t);
}

} // namespace type

namespace adaptor {

template <typename T>
struct convert<agpack::type::array_ref<T> > {
    agpack::object const& operator()(agpack::object const& o, agpack::type::array_ref<T>& v) const {
        if (!v.data) { throw agpack::type_error(); }
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        if (v.size() < o.via.bin.size) { throw agpack::type_error(); }
        if (o.via.array.size > 0) {
            agpack::object* p = o.via.array.ptr;
            agpack::object* const pend = o.via.array.ptr + o.via.array.size;
            typename T::iterator it = v.data->begin();
            do {
                p->convert(*it);
                ++p;
                ++it;
            } while(p < pend);
        }
        return o;
    }
};

template <typename T, std::size_t N>
struct convert<agpack::type::array_ref<T[N]> > {
    agpack::object const& operator()(agpack::object const& o, agpack::type::array_ref<T[N]>& v) const {
        if (!v.data) { throw agpack::type_error(); }
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        if (v.size() < o.via.bin.size) { throw agpack::type_error(); }
        if (o.via.array.size > 0) {
            agpack::object* p = o.via.array.ptr;
            agpack::object* const pend = o.via.array.ptr + o.via.array.size;
            T* it = v.data;
            do {
                p->convert(*it);
                ++p;
                ++it;
            } while(p < pend);
        }
        return o;
    }
};

template <typename T>
struct convert<agpack::type::array_ref<std::vector<T> > > {
    agpack::object const& operator()(agpack::object const& o, agpack::type::array_ref<std::vector<T> >& v) const {
        if (!v.data) { throw agpack::type_error(); }
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        v.data->resize(o.via.bin.size);
        if (o.via.array.size > 0) {
            agpack::object* p = o.via.array.ptr;
            agpack::object* const pend = o.via.array.ptr + o.via.array.size;
            typename std::vector<T>::iterator it = v.data->begin();
            do {
                p->convert(*it);
                ++p;
                ++it;
            } while(p < pend);
        }
        return o;
    }
};

template <typename T>
struct pack<agpack::type::array_ref<T> > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const agpack::type::array_ref<T>& v) const {
        if (!v.data) { throw agpack::type_error(); }
        uint32_t size = checked_get_container_size(v.size());
        o.pack_array(size);
        for (typename T::const_iterator it(v.data->begin()), it_end(v.data->end());
            it != it_end; ++it) {
            o.pack(*it);
        }
        return o;
    }
};

template <typename T, std::size_t N>
struct pack<agpack::type::array_ref<T[N]> > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const agpack::type::array_ref<T[N]>& v) const {
        if (!v.data) { throw agpack::type_error(); }
        uint32_t size = checked_get_container_size(v.size());
        o.pack_array(size);
        for (T const* it = v.data;
             it != &v.data[v.size()]; ++it) {
            o.pack(*it);
        }
        return o;
    }
};

template <typename T>
struct object_with_zone<agpack::type::array_ref<T> > {
    void operator()(agpack::object::with_zone& o, const agpack::type::array_ref<T>& v) const {
        if (!v.data) { throw agpack::type_error(); }
        o.type = agpack::type::ARRAY;
        if (v.data->empty()) {
            o.via.array.ptr = AGPACK_NULLPTR;
            o.via.array.size = 0;
        }
        else {
            uint32_t size = checked_get_container_size(v.size());
            agpack::object* p = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object)*size, AGPACK_ZONE_ALIGNOF(agpack::object)));
            agpack::object* const pend = p + size;
            o.via.array.ptr = p;
            o.via.array.size = size;
            typename T::const_iterator it(v.data->begin());
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

template <typename T, std::size_t N>
struct object_with_zone<agpack::type::array_ref<T[N]> > {
    void operator()(agpack::object::with_zone& o, const agpack::type::array_ref<T[N]>& v) const {
        if (!v.data) { throw agpack::type_error(); }
        o.type = agpack::type::ARRAY;
        uint32_t size = checked_get_container_size(v.size());
        agpack::object* p = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object)*size, AGPACK_ZONE_ALIGNOF(agpack::object)));
        agpack::object* const pend = p + size;
        o.via.array.ptr = p;
        o.via.array.size = size;
        T const* it = v.data;
        do {
            *p = agpack::object(*it, o.zone);
            ++p;
            ++it;
        } while(p < pend);
    }
};


} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_ARRAY_REF_HPP
