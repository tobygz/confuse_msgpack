//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2014 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_OBJECT_DECL_HPP
#define AGPACK_V1_OBJECT_DECL_HPP

#include "agpack/versioning.hpp"
#include "agpack/pack.hpp"
#include "agpack/zone.hpp"
#include "agpack/adaptor/adaptor_base.hpp"

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

/// The class holds object and zone
class object_handle;

namespace detail {

template <std::size_t N>
std::size_t add_ext_type_size(std::size_t size);

template <>
std::size_t add_ext_type_size<4>(std::size_t size);

} // namespace detail

std::size_t aligned_zone_size(agpack::object const& obj);

/// clone object
/**
 * Clone (deep copy) object.
 * The copied object is located on newly allocated zone.
 * @param obj copy source object
 *
 * @return object_handle that holds deep copied object and zone.
 */
object_handle clone(agpack::object const& obj);

namespace detail {

template <typename Stream, typename T>
struct packer_serializer;

} // namespace detail

// obsolete
template <typename Type>
class define;

bool operator==(const agpack::object& x, const agpack::object& y);

template <typename T>
bool operator==(const agpack::object& x, const T& y);

bool operator!=(const agpack::object& x, const agpack::object& y);

template <typename T>
bool operator==(const T& y, const agpack::object& x);

template <typename T>
bool operator!=(const agpack::object& x, const T& y);

template <typename T>
bool operator!=(const T& y, const agpack::object& x);

void operator<< (agpack::object& o, const agpack_object& v);

class object_parser;

template <typename Stream>
struct object_pack_visitor;

struct object_stringize_visitor;

// obsolete
template <typename T>
AGPACK_DEPRECATED("please use member function version of object::convert(T&)")
void convert(T& v, agpack::object const& o);

// obsolete
template <typename Stream, typename T>
AGPACK_DEPRECATED("please use member function version of packer::pack(const T&)")
void pack(agpack::packer<Stream>& o, const T& v);

// obsolete
template <typename Stream, typename T>
AGPACK_DEPRECATED("please use member function version of packer::pack(const T&)")
void pack_copy(agpack::packer<Stream>& o, T v);

template <typename Stream>
agpack::packer<Stream>& operator<< (agpack::packer<Stream>& o, const agpack::object& v);

template <typename Stream>
agpack::packer<Stream>& operator<< (agpack::packer<Stream>& o, const agpack::object::with_zone& v);

std::ostream& operator<< (std::ostream& s, const agpack::object& v);

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_OBJECT_DECL_HPP
