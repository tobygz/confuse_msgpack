//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V1_DEFINE_DECL_HPP
#define AGPACK_V1_DEFINE_DECL_HPP

#include "agpack/cpp_config.hpp"

#if defined(AGPACK_USE_CPP03)
#include "agpack/v1/adaptor/detail/cpp03_define_array_decl.hpp"
#include "agpack/v1/adaptor/detail/cpp03_define_map_decl.hpp"
#else  // AGPACK_USE_CPP03
#include "agpack/v1/adaptor/detail/cpp11_define_array_decl.hpp"
#include "agpack/v1/adaptor/detail/cpp11_define_map_decl.hpp"
#endif // AGPACK_USE_CPP03

#endif // AGPACK_V1_DEFINE_DECL_HPP
