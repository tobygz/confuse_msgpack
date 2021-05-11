//
// MessagePack for C++ memory pool
//
// Copyright (C) 2008-2018 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V3_ZONE_DECL_HPP
#define AGPACK_V3_ZONE_DECL_HPP

#include "agpack/cpp_config.hpp"

#if defined(AGPACK_USE_CPP03)
#include "agpack/v3/detail/cpp03_zone_decl.hpp"
#else  // AGPACK_USE_CPP03
#include "agpack/v3/detail/cpp11_zone_decl.hpp"
#endif // AGPACK_USE_CPP03

#endif // AGPACK_V3_ZONE_DECL_HPP
