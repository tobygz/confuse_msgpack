//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_CPP11_AGPACK_TUPLE_HPP
#define AGPACK_V1_CPP11_AGPACK_TUPLE_HPP

#include "agpack/v1/adaptor/detail/cpp11_agpack_tuple_decl.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/pack.hpp"

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

template <class... Args>
inline tuple<Args...> make_tuple(Args&&... args) {
    return tuple<Args...>(std::forward<Args>(args)...);
}

template<class... Args>
inline tuple<Args&&...> forward_as_tuple (Args&&... args) noexcept {
    return tuple<Args&&...>(std::forward<Args>(args)...);
}

template <class... Tuples>
inline auto tuple_cat(Tuples&&... args) ->
    decltype(
        std::tuple_cat(std::forward<typename std::remove_reference<Tuples>::type::base>(args)...)
    ) {
    return std::tuple_cat(std::forward<typename std::remove_reference<Tuples>::type::base>(args)...);
}

template <class... Args>
inline tuple<Args&...> tie(Args&... args) {
    return tuple<Args&...>(args...);
}
} // namespace type

// --- Pack from tuple to packer stream ---
template <typename Stream, typename Tuple, std::size_t N>
struct MsgpackTuplePacker {
    static void pack(
        agpack::packer<Stream>& o,
        const Tuple& v) {
        MsgpackTuplePacker<Stream, Tuple, N-1>::pack(o, v);
        o.pack(v.template get<N-1>());
    }
};

template <typename Stream, typename Tuple>
struct MsgpackTuplePacker<Stream, Tuple, 1> {
    static void pack (
        agpack::packer<Stream>& o,
        const Tuple& v) {
        o.pack(v.template get<0>());
    }
};

template <typename Stream, typename Tuple>
struct MsgpackTuplePacker<Stream, Tuple, 0> {
    static void pack (
        agpack::packer<Stream>&,
        const Tuple&) {
    }
};

namespace adaptor {

template <typename... Args>
struct pack<agpack::type::tuple<Args...>> {
    template <typename Stream>
    agpack::packer<Stream>& operator()(
        agpack::packer<Stream>& o,
        const agpack::type::tuple<Args...>& v) const {
        o.pack_array(sizeof...(Args));
        MsgpackTuplePacker<Stream, decltype(v), sizeof...(Args)>::pack(o, v);
        return o;
    }
};

} // namespace adaptor

// --- Convert from tuple to object ---

template <typename T, typename... Args>
struct MsgpackTupleAsImpl {
    static agpack::type::tuple<T, Args...> as(agpack::object const& o) {
        return agpack::type::tuple_cat(
            agpack::type::make_tuple(o.via.array.ptr[o.via.array.size - sizeof...(Args) - 1].as<T>()),
            MsgpackTupleAs<Args...>::as(o));
    }
};

template <typename... Args>
struct MsgpackTupleAs {
    static agpack::type::tuple<Args...> as(agpack::object const& o) {
        return MsgpackTupleAsImpl<Args...>::as(o);
    }
};

template <>
struct MsgpackTupleAs<> {
    static agpack::type::tuple<> as (agpack::object const&) {
        return agpack::type::tuple<>();
    }
};

template <typename Tuple, std::size_t N>
struct MsgpackTupleConverter {
    static void convert(
        agpack::object const& o,
        Tuple& v) {
        MsgpackTupleConverter<Tuple, N-1>::convert(o, v);
        if (o.via.array.size >= N)
            o.via.array.ptr[N-1].convert<typename std::remove_reference<decltype(v.template get<N-1>())>::type>(v.template get<N-1>());
    }
};

template <typename Tuple>
struct MsgpackTupleConverter<Tuple, 1> {
    static void convert (
        agpack::object const& o,
        Tuple& v) {
        o.via.array.ptr[0].convert<typename std::remove_reference<decltype(v.template get<0>())>::type>(v.template get<0>());
    }
};

template <typename Tuple>
struct MsgpackTupleConverter<Tuple, 0> {
    static void convert (
        agpack::object const&,
        Tuple&) {
    }
};

namespace adaptor {

template <typename... Args>
struct as<agpack::type::tuple<Args...>, typename std::enable_if<agpack::any_of<agpack::has_as, Args...>::value>::type>  {
    agpack::type::tuple<Args...> operator()(
        agpack::object const& o) const {
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        return MsgpackTupleAs<Args...>::as(o);
    }
};

template <typename... Args>
struct convert<agpack::type::tuple<Args...>> {
    agpack::object const& operator()(
        agpack::object const& o,
        agpack::type::tuple<Args...>& v) const {
        if(o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        MsgpackTupleConverter<decltype(v), sizeof...(Args)>::convert(o, v);
        return o;
    }
};

} // namespace adaptor

// --- Convert from tuple to object with zone ---
template <typename Tuple, std::size_t N>
struct MsgpackTupleToObjectWithZone {
    static void convert(
        agpack::object::with_zone& o,
        const Tuple& v) {
        MsgpackTupleToObjectWithZone<Tuple, N-1>::convert(o, v);
        o.via.array.ptr[N-1] = agpack::object(v.template get<N-1>(), o.zone);
    }
};

template <typename Tuple>
struct MsgpackTupleToObjectWithZone<Tuple, 1> {
    static void convert (
        agpack::object::with_zone& o,
        const Tuple& v) {
        o.via.array.ptr[0] = agpack::object(v.template get<0>(), o.zone);
    }
};

template <typename Tuple>
struct MsgpackTupleToObjectWithZone<Tuple, 0> {
    static void convert (
        agpack::object::with_zone&,
        const Tuple&) {
    }
};

namespace adaptor {

template <typename... Args>
    struct object_with_zone<agpack::type::tuple<Args...>> {
    void operator()(
        agpack::object::with_zone& o,
        agpack::type::tuple<Args...> const& v) const {
        o.type = agpack::type::ARRAY;
        o.via.array.ptr = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object)*sizeof...(Args), AGPACK_ZONE_ALIGNOF(agpack::object)));
        o.via.array.size = sizeof...(Args);
        MsgpackTupleToObjectWithZone<decltype(v), sizeof...(Args)>::convert(o, v);
    }
};

}  // namespace adaptor

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
///@endcond

}  // namespace agpack

#endif // AGPACK_CPP11_AGPACK_TUPLE_HPP
