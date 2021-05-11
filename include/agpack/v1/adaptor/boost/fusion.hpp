//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2015-2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_TYPE_BOOST_FUSION_HPP
#define AGPACK_V1_TYPE_BOOST_FUSION_HPP

#include "agpack/versioning.hpp"
#include "agpack/adaptor/adaptor_base.hpp"
#include "agpack/adaptor/check_container_size.hpp"
#include "agpack/meta.hpp"

#include "agpack/adaptor/pair.hpp"

#if !defined (AGPACK_USE_CPP03)
#include "agpack/adaptor/cpp11/tuple.hpp"
#endif // #if !defined (AGPACK_USE_CPP03)

#include <boost/fusion/support/is_sequence.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/mpl/size.hpp>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

namespace detail {

template <typename T>
struct is_std_pair {
    static bool const value = false;
};

template <typename T, typename U>
struct is_std_pair<std::pair<T, U> > {
    static bool const value = true;
};

#if !defined(AGPACK_USE_CPP03)

template <typename T>
struct is_std_tuple {
    static bool const value = false;
};

template <typename... Args>
struct is_std_tuple<std::tuple<Args...>> {
    static bool const value = true;
};

#endif // !defined(AGPACK_USE_CPP03)

template <typename T>
struct is_seq_no_pair_no_tuple {
    static bool const value =
        boost::fusion::traits::is_sequence<T>::value
        &&
        !is_std_pair<T>::value
#if !defined (AGPACK_USE_CPP03)
        &&
        !is_std_tuple<T>::value
#endif // !defined (AGPACK_USE_CPP03)
        ;
};

} // namespace detail

#if !defined (AGPACK_USE_CPP03)

template <typename T>
struct as<
    T,
    typename agpack::enable_if<
        detail::is_seq_no_pair_no_tuple<T>::value &&
        boost::mpl::fold<
            T,
            boost::mpl::bool_<true>,
            boost::mpl::if_ <
                boost::mpl::or_<
                    boost::mpl::_1,
                    agpack::has_as<boost::mpl::_2>
                >,
                boost::mpl::bool_<true>,
                boost::mpl::bool_<false>
            >
        >::type::value
    >::type
> {
    T operator()(agpack::object const& o) const {
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        if (o.via.array.size != checked_get_container_size(boost::mpl::size<T>::value)) {
            throw agpack::type_error();
        }
        using tuple_t = decltype(to_tuple(std::declval<T>(), gen_seq<boost::mpl::size<T>::value>()));
        return to_t(
            o.as<tuple_t>(),
            agpack::gen_seq<boost::mpl::size<T>::value>());
    }
    template<std::size_t... Is, typename U>
    static std::tuple<
        typename std::remove_reference<
            typename boost::fusion::result_of::at_c<T, Is>::type
        >::type...>
    to_tuple(U const& u, seq<Is...>) {
        return std::make_tuple(boost::fusion::at_c<Is>(u)...);
    }
    template<std::size_t... Is, typename U>
    static T to_t(U const& u, seq<Is...>) {
        return T(std::get<Is>(u)...);
    }
};

#endif // !defined (AGPACK_USE_CPP03)

template <typename T>
struct convert<T, typename agpack::enable_if<detail::is_seq_no_pair_no_tuple<T>::value>::type > {
    agpack::object const& operator()(agpack::object const& o, T& v) const {
        if (o.type != agpack::type::ARRAY) { throw agpack::type_error(); }
        if (o.via.array.size != checked_get_container_size(boost::fusion::size(v))) {
            throw agpack::type_error();
        }
        uint32_t index = 0;
        boost::fusion::for_each(v, convert_imp(o, index));
        return o;
    }
private:
    struct convert_imp {
        convert_imp(agpack::object const& obj, uint32_t& index):obj_(obj), index_(index) {}
        template <typename U>
        void operator()(U& v) const {
            agpack::adaptor::convert<U>()(obj_.via.array.ptr[index_++], v);
        }
    private:
        agpack::object const& obj_;
        uint32_t& index_;
    };
};

template <typename T>
struct pack<T, typename agpack::enable_if<detail::is_seq_no_pair_no_tuple<T>::value>::type > {
    template <typename Stream>
    agpack::packer<Stream>& operator()(agpack::packer<Stream>& o, const T& v) const {
        uint32_t size = checked_get_container_size(boost::fusion::size(v));
        o.pack_array(size);
        boost::fusion::for_each(v, pack_imp<Stream>(o));
        return o;
    }
private:
    template <typename Stream>
    struct pack_imp {
        pack_imp(agpack::packer<Stream>& stream):stream_(stream) {}
        template <typename U>
        void operator()(U const& v) const {
            stream_.pack(v);
        }
    private:
        agpack::packer<Stream>& stream_;
    };
};

template <typename T>
struct object_with_zone<T, typename agpack::enable_if<detail::is_seq_no_pair_no_tuple<T>::value>::type > {
    void operator()(agpack::object::with_zone& o, const T& v) const {
        uint32_t size = checked_get_container_size(boost::fusion::size(v));
        o.type = agpack::type::ARRAY;
        o.via.array.ptr = static_cast<agpack::object*>(o.zone.allocate_align(sizeof(agpack::object)*size, AGPACK_ZONE_ALIGNOF(agpack::object)));
        o.via.array.size = size;
        uint32_t count = 0;
        boost::fusion::for_each(v, with_zone_imp(o, count));
    }
private:
    struct with_zone_imp {
        with_zone_imp(agpack::object::with_zone const& obj, uint32_t& count):obj_(obj), count_(count) {}
        template <typename U>
        void operator()(U const& v) const {
            obj_.via.array.ptr[count_++] = agpack::object(v, obj_.zone);
        }
        agpack::object::with_zone const& obj_;
        uint32_t& count_;
    };
};

} // namespace adaptor

/// @cond
} // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace agpack

#endif // AGPACK_V1_TYPE_BOOST_FUSION_HPP
