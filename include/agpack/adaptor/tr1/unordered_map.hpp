//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2015 FURUHASHI Sadayuki
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_TYPE_TR1_UNORDERED_MAP_HPP
#define AGPACK_TYPE_TR1_UNORDERED_MAP_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#if defined(_LIBCPP_VERSION) || (_MSC_VER >= 1700)

#define AGPACK_HAS_STD_UNORDERED_MAP
#include <unordered_map>
#define AGPACK_STD_TR1 std

#else   // defined(_LIBCPP_VERSION) || (_MSC_VER >= 1700)

#if __GNUC__ >= 4

#define AGPACK_HAS_STD_TR1_UNORDERED_MAP

#include <tr1/unordered_map>
#define AGPACK_STD_TR1 std::tr1

#endif // __GNUC__ >= 4

#endif  // defined(_LIBCPP_VERSION) || (_MSC_VER >= 1700)

#if defined(AGPACK_STD_TR1)

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <typename K, typename V, typename Hash, typename Pred, typename Alloc>
struct convert<AGPACK_STD_TR1::unordered_map<K, V, Hash, Pred, Alloc> > {
    agpack::object const& operator()(agpack::object const& o, AGPACK_STD_TR1::unordered_map<K, V, Hash, Pred, Alloc>& v) const {
        if(o.type != agpack::type::MAP) { throw agpack::type_error(); }
        agpack::object_kv* p(o.via.map.ptr);
        agpack::object_kv* const pend(o.via.map.ptr + o.via.map.size);
        AGPACK_STD_TR1::unordered_map<K, V, Hash, Pred, Alloc> tmp;
        for(; p != pend; ++p) {
            K key;
            p->key.convert(key);
            p->val.convert(tmp[key]);
        }
        tmp.swap(v);
        return o;
    }
};

template <typename K, typename V, typename Hash, typename Pred, typename Alloc>
struct pack<AGPACK_STD_TR1::unordered_map<K, V, Hash, Pred, Alloc> > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const AGPACK_STD_TR1::unordered_map<K, V, Hash, Pred, Alloc>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_map(size);
        for(typename AGPACK_STD_TR1::unordered_map<K, V, Hash, Pred, Alloc>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(it->first);
            o.pack(it->second);
        }
        return o;
    }
};

template <typename K, typename V, typename Hash, typename Pred, typename Alloc>
struct object_with_zone<AGPACK_STD_TR1::unordered_map<K, V, Hash, Pred, Alloc> > {
    void operator()(agpack::object::with_zone& o, const AGPACK_STD_TR1::unordered_map<K, V, Hash, Pred, Alloc>& v) const {
        o.type = agpack::type::MAP;
        if(v.empty()) {
            o.via.map.ptr  = AGPACK_NULLPTR;
            o.via.map.size = 0;
        } else {
            uint32_t size = checked_get_container_size(v.size());
            agpack::object_kv* p = static_cast<agpack::object_kv*>(o.zone.allocate_align(sizeof(agpack::object_kv)*size, AGPACK_ZONE_ALIGNOF(agpack::object_kv)));
            agpack::object_kv* const pend = p + size;
            o.via.map.ptr  = p;
            o.via.map.size = size;
            typename AGPACK_STD_TR1::unordered_map<K, V, Hash, Pred, Alloc>::const_iterator it(v.begin());
            do {
                p->key = agpack::object(it->first, o.zone);
                p->val = agpack::object(it->second, o.zone);
                ++p;
                ++it;
            } while(p < pend);
        }
    }
};

template <typename K, typename V, typename Hash, typename Pred, typename Alloc>
struct convert<AGPACK_STD_TR1::unordered_multimap<K, V, Hash, Pred, Alloc> > {
    agpack::object const& operator()(agpack::object const& o, AGPACK_STD_TR1::unordered_multimap<K, V, Hash, Pred, Alloc>& v) const {
        if(o.type != agpack::type::MAP) { throw agpack::type_error(); }
        agpack::object_kv* p(o.via.map.ptr);
        agpack::object_kv* const pend(o.via.map.ptr + o.via.map.size);
        AGPACK_STD_TR1::unordered_multimap<K, V, Hash, Pred, Alloc> tmp;
        for(; p != pend; ++p) {
            std::pair<K, V> value;
            p->key.convert(value.first);
            p->val.convert(value.second);
            tmp.insert(value);
        }
        tmp.swap(v);
        return o;
    }
};

template <typename K, typename V, typename Hash, typename Pred, typename Alloc>
struct pack<AGPACK_STD_TR1::unordered_multimap<K, V, Hash, Pred, Alloc> > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const AGPACK_STD_TR1::unordered_multimap<K, V, Hash, Pred, Alloc>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_map(size);
        for(typename AGPACK_STD_TR1::unordered_multimap<K, V, Hash, Pred, Alloc>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(it->first);
            o.pack(it->second);
        }
        return o;
    }
};

template <typename K, typename V, typename Hash, typename Pred, typename Alloc>
struct object_with_zone<AGPACK_STD_TR1::unordered_multimap<K, V, Hash, Pred, Alloc> > {
    void operator()(agpack::object::with_zone& o, const AGPACK_STD_TR1::unordered_multimap<K, V, Hash, Pred, Alloc>& v) const {
        o.type = agpack::type::MAP;
        if(v.empty()) {
            o.via.map.ptr  = AGPACK_NULLPTR;
            o.via.map.size = 0;
        } else {
            uint32_t size = checked_get_container_size(v.size());
            agpack::object_kv* p = static_cast<agpack::object_kv*>(o.zone.allocate_align(sizeof(agpack::object_kv)*size, AGPACK_ZONE_ALIGNOF(agpack::object_kv)));
            agpack::object_kv* const pend = p + size;
            o.via.map.ptr  = p;
            o.via.map.size = size;
            typename AGPACK_STD_TR1::unordered_multimap<K, V, Hash, Pred, Alloc>::const_iterator it(v.begin());
            do {
                p->key = agpack::object(it->first, o.zone);
                p->val = agpack::object(it->second, o.zone);
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

#endif // AGPACK_TYPE_TR1_UNORDERED_MAP_HPP
