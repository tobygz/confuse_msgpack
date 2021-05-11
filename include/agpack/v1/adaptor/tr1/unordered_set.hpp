//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2015 FURUHASHI Sadayuki
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_TYPE_TR1_UNORDERED_SET_HPP
#define AGPACK_TYPE_TR1_UNORDERED_SET_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#if defined(_LIBCPP_VERSION) || (_MSC_VER >= 1700)

#define AGPACK_HAS_STD_UNORDERED_SET
#include <unordered_set>
#define AGPACK_STD_TR1 std

#else   // defined(_LIBCPP_VERSION) || (_MSC_VER >= 1700)

#if __GNUC__ >= 4

#define AGPACK_HAS_STD_TR1_UNORDERED_SET

#include <tr1/unordered_set>
#define AGPACK_STD_TR1 std::tr1

#endif // __GNUC__ >= 4

#endif  // defined(_LIBCPP_VERSION) || (_MSC_VER >= 1700)

#if defined(AGPACK_STD_TR1)

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <typename T, typename Hash, typename Compare, typename Alloc>
struct convert<AGPACK_STD_TR1::unordered_set<T, Hash, Compare, Alloc> > {
    agpack::object const& operator()(agpack::object const& o, AGPACK_STD_TR1::unordered_set<T, Hash, Compare, Alloc>& v) const {
        if(o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        agpack::object* p = o.via.array.ptr + o.via.array.size;
        agpack::object* const pbegin = o.via.array.ptr;
        AGPACK_STD_TR1::unordered_set<T, Hash, Compare, Alloc> tmp;
        while(p > pbegin) {
            --p;
            tmp.insert(p->as<T>());
        }
        tmp.swap(v);
        return o;
    }
};

template <typename T, typename Hash, typename Compare, typename Alloc>
struct pack<AGPACK_STD_TR1::unordered_set<T, Hash, Compare, Alloc> > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const AGPACK_STD_TR1::unordered_set<T, Hash, Compare, Alloc>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_array(size);
        for(typename AGPACK_STD_TR1::unordered_set<T, Hash, Compare, Alloc>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(*it);
        }
        return o;
    }
};

template <typename T, typename Hash, typename Compare, typename Alloc>
struct object_with_zone<AGPACK_STD_TR1::unordered_set<T, Hash, Compare, Alloc> > {
    void operator()(agpack::object::with_zone& o, const AGPACK_STD_TR1::unordered_set<T, Hash, Compare, Alloc>& v) const {
        o.type = agpack::type::ARRAY;
        if(v.empty()) {
            o.via.array.ptr = AGPACK_NULLPTR;
            o.via.array.size = 0;
        } else {
            uint32_t size = checked_get_container_size(v.size());
            agpack::object* p = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object)*size, AGPACK_ZONE_ALIGNOF(agpack::object)));
            agpack::object* const pend = p + size;
            o.via.array.ptr = p;
            o.via.array.size = size;
            typename AGPACK_STD_TR1::unordered_set<T, Hash, Compare, Alloc>::const_iterator it(v.begin());
            do {
                *p = agpack::object(*it, o.zone);
                ++p;
                ++it;
            } while(p < pend);
        }
    }
};


template <typename T, typename Hash, typename Compare, typename Alloc>
struct convert<AGPACK_STD_TR1::unordered_multiset<T, Hash, Compare, Alloc> > {
    agpack::object const& operator()(agpack::object const& o, AGPACK_STD_TR1::unordered_multiset<T, Hash, Compare, Alloc>& v) const {
        if(o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        agpack::object* p = o.via.array.ptr + o.via.array.size;
        agpack::object* const pbegin = o.via.array.ptr;
        AGPACK_STD_TR1::unordered_multiset<T, Hash, Compare, Alloc> tmp;
        while(p > pbegin) {
            --p;
            tmp.insert(p->as<T>());
        }
        tmp.swap(v);
        return o;
    }
};

template <typename T, typename Hash, typename Compare, typename Alloc>
struct pack<AGPACK_STD_TR1::unordered_multiset<T, Hash, Compare, Alloc> > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const AGPACK_STD_TR1::unordered_multiset<T, Hash, Compare, Alloc>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_array(size);
        for(typename AGPACK_STD_TR1::unordered_multiset<T, Hash, Compare, Alloc>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(*it);
        }
        return o;
    }
};

template <typename T, typename Hash, typename Compare, typename Alloc>
struct object_with_zone<AGPACK_STD_TR1::unordered_multiset<T, Hash, Compare, Alloc> > {
    void operator()(agpack::object::with_zone& o, const AGPACK_STD_TR1::unordered_multiset<T, Hash, Compare, Alloc>& v) const {
        o.type = agpack::type::ARRAY;
        if(v.empty()) {
            o.via.array.ptr = AGPACK_NULLPTR;
            o.via.array.size = 0;
        } else {
            uint32_t size = checked_get_container_size(v.size());
            agpack::object* p = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object)*size, AGPACK_ZONE_ALIGNOF(agpack::object)));
            agpack::object* const pend = p + size;
            o.via.array.ptr = p;
            o.via.array.size = size;
            typename AGPACK_STD_TR1::unordered_multiset<T, Hash, Compare, Alloc>::const_iterator it(v.begin());
            do {
                *p = agpack::object(*it, o.zone);
                ++p;
                ++it;
            } while(p < pend);
        }
    }
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#undef AGPACK_STD_TR1

#endif // AGPACK_STD_TR1

#endif // AGPACK_TYPE_TR1_UNORDERED_SET_HPP
