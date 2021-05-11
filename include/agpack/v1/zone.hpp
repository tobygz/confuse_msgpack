//
// MessagePack for C++ memory pool
//
// Copyright (C) 2008-2014 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_ZONE_HPP
#define AGPACK_V1_ZONE_HPP

#include "agpack/cpp_config.hpp"

#if defined(AGPACK_USE_CPP03)
#include "agpack/v1/detail/cpp03_zone.hpp"
#else  // AGPACK_USE_CPP03
#include "agpack/v1/detail/cpp11_zone.hpp"
#endif // AGPACK_USE_CPP03

#endif // AGPACK_V1_ZONE_HPP
