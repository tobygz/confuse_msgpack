//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_V2_AGPACK_TUPLE_DECL_HPP
#define AGPACK_V2_AGPACK_TUPLE_DECL_HPP

#include "agpack/cpp_config.hpp"

#if defined(AGPACK_USE_CPP03)
#include "agpack/v2/adaptor/detail/cpp03_agpack_tuple_decl.hpp"
#else  // AGPACK_USE_CPP03
#include "agpack/v2/adaptor/detail/cpp11_agpack_tuple_decl.hpp"
#endif // AGPACK_USE_CPP03

#endif // AGPACK_V2_AGPACK_TUPLE_DECL_HPP
