//
// MessagePack for C++ zero-copy buffer implementation
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_VREFBUFFER_DECL_HPP
#define AGPACK_V1_VREFBUFFER_DECL_HPP

#include "agpack/versioning.hpp"

#include <cstdlib>

#ifndef AGPACK_VREFBUFFER_REF_SIZE
#define AGPACK_VREFBUFFER_REF_SIZE 32
#endif

#ifndef AGPACK_VREFBUFFER_CHUNK_SIZE
#define AGPACK_VREFBUFFER_CHUNK_SIZE 8192
#endif

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

class vrefbuffer;

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_VREFBUFFER_DECL_HPP
