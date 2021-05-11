//
// MessagePack for C++ memory pool
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_CPP11_ZONE_DECL_HPP
#define AGPACK_V1_CPP11_ZONE_DECL_HPP

#include "agpack/versioning.hpp"

#include <cstdlib>
#include <memory>
#include <vector>

#include "agpack/cpp_config.hpp"

#ifndef AGPACK_ZONE_CHUNK_SIZE
#define AGPACK_ZONE_CHUNK_SIZE 8192
#endif

#ifndef AGPACK_ZONE_ALIGN
#define AGPACK_ZONE_ALIGN sizeof(void*)
#endif

#if defined(_MSC_VER)
#define AGPACK_ZONE_ALIGNOF(type) __alignof(type)
#else
#define AGPACK_ZONE_ALIGNOF(type) __alignof__(type)
#endif
// For a compiler that doesn't support __alignof__:
// #define AGPACK_ZONE_ALIGNOF(type) AGPACK_ZONE_ALIGN

namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

class zone;

std::size_t aligned_size(
    std::size_t size,
    std::size_t align = AGPACK_ZONE_ALIGN);

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V1_CPP11_ZONE_DECL_HPP
