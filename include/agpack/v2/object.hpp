//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V2_OBJECT_HPP
#define AGPACK_V2_OBJECT_HPP

#include "agpack/object_fwd.hpp"


namespace agpack {

/// @cond
AGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

inline object::implicit_type object::convert() const
{
    return v1::object::convert();
}

/// @cond
}  // AGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

}  // namespace agpack

#endif // AGPACK_V2_OBJECT_HPP
