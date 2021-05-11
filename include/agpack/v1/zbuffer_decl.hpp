//
// MessagePack for C++ deflate buffer implementation
//
// Copyright (C) 2010-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_ZBUFFER_DECL_HPP
#define AGPACK_V1_ZBUFFER_DECL_HPP

#include "agpack/versioning.hpp"

#ifndef AGPACK_ZBUFFER_RESERVE_SIZE
#define AGPACK_ZBUFFER_RESERVE_SIZE 512
#endif

#ifndef AGPACK_ZBUFFER_INIT_SIZE
#define AGPACK_ZBUFFER_INIT_SIZE 8192
#endif

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

class zbuffer;

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_ZBUFFER_DECL_HPP
