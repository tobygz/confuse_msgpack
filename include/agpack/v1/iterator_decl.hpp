//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2015-2016 MIZUKI Hirata
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef AGPACK_V1_ITERATOR_DECL_HPP
#define AGPACK_V1_ITERATOR_DECL_HPP
#if !defined(AGPACK_USE_CPP03)

#include <agpack/object_fwd.hpp>

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

agpack::object_kv* begin(agpack::object_map &map);
const agpack::object_kv* begin(const agpack::object_map &map);
agpack::object_kv* end(agpack::object_map &map);
const agpack::object_kv* end(const agpack::object_map &map);

agpack::object* begin(agpack::object_array &array);
const agpack::object* begin(const agpack::object_array &array);
agpack::object* end(agpack::object_array &array);
const agpack::object* end(const agpack::object_array &array);

/// @cond
}
/// @endcond

}

#endif // !defined(AGPACK_USE_CPP03)
#endif // AGPACK_V1_ITERATOR_DECL_HPP
