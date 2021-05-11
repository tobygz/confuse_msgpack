//
// MessagePack for C++ simple buffer implementation
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V2_SBUFFER_DECL_HPP
#define AGPACK_V2_SBUFFER_DECL_HPP

#include "agpack/versioning.hpp"

#ifndef AGPACK_SBUFFER_INIT_SIZE
#define AGPACK_SBUFFER_INIT_SIZE 8192
#endif

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

using v1::sbuffer;

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V2_SBUFFER_DECL_HPP
