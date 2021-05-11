//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2014-2015 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_CPP11_UNORDERED_MAP_HPP
#define AGPACK_V1_TYPE_CPP11_UNORDERED_MAP_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"

#include <unordered_map>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <typename K, typename V, typename Hash, typename Compare, typename Alloc>
struct as<
    std::unordered_map<K, V, Hash, Compare, Alloc>,
    typename std::enable_if<agpack::has_as<K>::value || agpack::has_as<V>::value>::type> {
    std::unordered_map<K, V, Hash, Compare, Alloc> operator()(agpack::object const& o) const {
        if (o.type != agpack::type::MAP) { throw agpack::type_error(); }
        agpack::object_kv* p(o.via.map.ptr);
        agpack::object_kv* const pend(o.via.map.ptr + o.via.map.size);
        std::unordered_map<K, V, Hash, Compare, Alloc> v;
        for (; p != pend; ++p) {
            v.emplace(p->key.as<K>(), p->val.as<V>());
        }
        return v;
    }
};

template <typename K, typename V, typename Hash, typename Compare, typename Alloc>
struct convert<std::unordered_map<K, V, Hash, Compare, Alloc>> {
    agpack::object const& operator()(agpack::object const& o, std::unordered_map<K, V, Hash, Compare, Alloc>& v) const {
        if(o.type != agpack::type::MAP) { throw agpack::type_error(); }
        agpack::object_kv* p(o.via.map.ptr);
        agpack::object_kv* const pend(o.via.map.ptr + o.via.map.size);
        std::unordered_map<K, V, Hash, Compare, Alloc> tmp;
        for(; p != pend; ++p) {
            K key;
            p->key.convert(key);
            p->val.convert(tmp[std::move(key)]);
        }
        v = std::move(tmp);
        return o;
    }
};

template <typename K, typename V, typename Hash, typename Compare, typename Alloc>
struct pack<std::unordered_map<K, V, Hash, Compare, Alloc>> {
    template <typename Stream>
        agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::unordered_map<K, V, Hash, Compare, Alloc>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_map(size);
        for(typename std::unordered_map<K, V, Hash, Compare, Alloc>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(it->first);
            o.pack(it->second);
        }
        return o;
    }
};

template <typename K, typename V, typename Hash, typename Compare, typename Alloc>
struct object_with_zone<std::unordered_map<K, V, Hash, Compare, Alloc>> {
    void operator()(agpack::object::with_zone& o, const std::unordered_map<K, V, Hash, Compare, Alloc>& v) const {
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
            typename std::unordered_map<K, V, Hash, Compare, Alloc>::const_iterator it(v.begin());
            do {
                p->key = agpack::object(it->first, o.zone);
                p->val = agpack::object(it->second, o.zone);
                ++p;
                ++it;
            } while(p < pend);
        }
    }
};


template <typename K, typename V, typename Hash, typename Compare, typename Alloc>
struct as<
    std::unordered_multimap<K, V, Hash, Compare, Alloc>,
    typename std::enable_if<agpack::has_as<K>::value || agpack::has_as<V>::value>::type> {
    std::unordered_multimap<K, V, Hash, Compare, Alloc> operator()(agpack::object const& o) const {
        if (o.type != agpack::type::MAP) { throw agpack::type_error(); }
        agpack::object_kv* p(o.via.map.ptr);
        agpack::object_kv* const pend(o.via.map.ptr + o.via.map.size);
        std::unordered_multimap<K, V, Hash, Compare, Alloc> v;
        for (; p != pend; ++p) {
            v.emplace(p->key.as<K>(), p->val.as<V>());
        }
        return v;
    }
};

template <typename K, typename V, typename Hash, typename Compare, typename Alloc>
struct convert<std::unordered_multimap<K, V, Hash, Compare, Alloc>> {
    agpack::object const& operator()(agpack::object const& o, std::unordered_multimap<K, V, Hash, Compare, Alloc>& v) const {
        if(o.type != agpack::type::MAP) { throw agpack::type_error(); }
        agpack::object_kv* p(o.via.map.ptr);
        agpack::object_kv* const pend(o.via.map.ptr + o.via.map.size);
        std::unordered_multimap<K, V, Hash, Compare, Alloc> tmp;
        for(; p != pend; ++p) {
            std::pair<K, V> value;
            p->key.convert(value.first);
            p->val.convert(value.second);
            tmp.insert(std::move(value));
        }
        v = std::move(tmp);
        return o;
    }
};

template <typename K, typename V, typename Hash, typename Compare, typename Alloc>
struct pack<std::unordered_multimap<K, V, Hash, Compare, Alloc>> {
    template <typename Stream>
        agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const std::unordered_multimap<K, V, Hash, Compare, Alloc>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_map(size);
        for(typename std::unordered_multimap<K, V, Hash, Compare, Alloc>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(it->first);
            o.pack(it->second);
        }
        return o;
    }
};

template <typename K, typename V, typename Hash, typename Compare, typename Alloc>
struct object_with_zone<std::unordered_multimap<K, V, Hash, Compare, Alloc>> {
    void operator()(agpack::object::with_zone& o, const std::unordered_multimap<K, V, Hash, Compare, Alloc>& v) const {
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
            typename std::unordered_multimap<K, V, Hash, Compare, Alloc>::const_iterator it(v.begin());
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


#endif // AGPACK_V1_TYPE_CPP11_UNORDERED_MAP_HPP
