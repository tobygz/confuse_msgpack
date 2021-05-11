//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef AGPACK_DEFINE_DECL_HPP
#define AGPACK_DEFINE_DECL_HPP

// BOOST_PP_VARIADICS is defined in boost/preprocessor/config/config.hpp
// http://www.boost.org/libs/preprocessor/doc/ref/variadics.html
// However, supporting compiler detection is not complete. agpack-c requires
// variadic macro arguments support. So BOOST_PP_VARIADICS is defined here explicitly.
#if !defined(AGPACK_PP_VARIADICS)
#define AGPACK_PP_VARIADICS
#endif

#include <agpack/preprocessor.hpp>

#include "agpack/versioning.hpp"

// for AGPACK_ADD_ENUM
#include "agpack/adaptor/int.hpp"

#define AGPACK_DEFINE_ARRAY(...) \
    template <typename Packer> \
    void agpack_pack(Packer& agpack_pk) const \
    { \
        agpack::type::make_define_array(__VA_ARGS__).agpack_pack(agpack_pk); \
    } \
    void agpack_unpack(agpack::object const& agpack_o) \
    { \
        agpack::type::make_define_array(__VA_ARGS__).agpack_unpack(agpack_o); \
    }\
    template <typename AGPACK_OBJECT> \
    void agpack_object(AGPACK_OBJECT* agpack_o, agpack::zone& agpack_z) const \
    { \
        agpack::type::make_define_array(__VA_ARGS__).agpack_object(agpack_o, agpack_z); \
    }

#define AGPACK_BASE_ARRAY(base) (*const_cast<base *>(static_cast<base const*>(this)))
#define AGPACK_NVP(name, value) (name) (value)

#define AGPACK_DEFINE_MAP_EACH_PROC(r, data, elem) \
    AGPACK_PP_IF( \
        AGPACK_PP_IS_BEGIN_PARENS(elem), \
        elem, \
        (AGPACK_PP_STRINGIZE(elem))(elem) \
    )

#define AGPACK_DEFINE_MAP_IMPL(...) \
    AGPACK_PP_SEQ_TO_TUPLE( \
        AGPACK_PP_SEQ_FOR_EACH( \
            AGPACK_DEFINE_MAP_EACH_PROC, \
            0, \
            AGPACK_PP_VARIADIC_TO_SEQ(__VA_ARGS__) \
        ) \
    )

#define AGPACK_DEFINE_MAP(...) \
    template <typename Packer> \
    void agpack_pack(Packer& agpack_pk) const \
    { \
        agpack::type::make_define_map \
            AGPACK_DEFINE_MAP_IMPL(__VA_ARGS__) \
            .agpack_pack(agpack_pk); \
    } \
    void agpack_unpack(agpack::object const& agpack_o) \
    { \
        agpack::type::make_define_map \
            AGPACK_DEFINE_MAP_IMPL(__VA_ARGS__) \
            .agpack_unpack(agpack_o); \
    }\
    template <typename AGPACK_OBJECT> \
    void agpack_object(AGPACK_OBJECT* agpack_o, agpack::zone& agpack_z) const \
    { \
        agpack::type::make_define_map \
            AGPACK_DEFINE_MAP_IMPL(__VA_ARGS__) \
            .agpack_object(agpack_o, agpack_z); \
    }

#define AGPACK_BASE_MAP(base) \
    (AGPACK_PP_STRINGIZE(base))(*const_cast<base *>(static_cast<base const*>(this)))

// AGPACK_ADD_ENUM must be used in the global namespace.
#define AGPACK_ADD_ENUM(enum_name) \
  namespace agpack { \
  /** @cond */ \
  AGPACK_API_VERSION_NAMESPACE(AGPACK_DEFAULT_API_NS) { \
  /** @endcond */ \
  namespace adaptor { \
    template<> \
    struct convert<enum_name> { \
      agpack::object const& operator()(agpack::object const& agpack_o, enum_name& agpack_v) const { \
        agpack::underlying_type<enum_name>::type tmp; \
        agpack::operator>>(agpack_o, tmp);                   \
        agpack_v = static_cast<enum_name>(tmp);   \
        return agpack_o; \
      } \
    }; \
    template<> \
    struct object<enum_name> { \
      void operator()(agpack::object& agpack_o, const enum_name& agpack_v) const { \
        agpack::underlying_type<enum_name>::type tmp = static_cast<agpack::underlying_type<enum_name>::type>(agpack_v); \
        agpack::operator<<(agpack_o, tmp);                                    \
      } \
    }; \
    template<> \
    struct object_with_zone<enum_name> { \
      void operator()(agpack::object::with_zone& agpack_o, const enum_name& agpack_v) const {  \
        agpack::underlying_type<enum_name>::type tmp = static_cast<agpack::underlying_type<enum_name>::type>(agpack_v); \
        agpack::operator<<(agpack_o, tmp);                                    \
      } \
    }; \
    template <> \
    struct pack<enum_name> { \
      template <typename Stream> \
      agpack::packer<Stream>& operator()(agpack::packer<Stream>& agpack_o, const enum_name& agpack_v) const { \
          return agpack::operator<<(agpack_o, static_cast<agpack::underlying_type<enum_name>::type>(agpack_v)); \
      } \
    }; \
  } \
  /** @cond */ \
  } \
  /** @endcond */ \
  }

#if defined(AGPACK_USE_DEFINE_MAP)
#define AGPACK_DEFINE AGPACK_DEFINE_MAP
#define AGPACK_BASE AGPACK_BASE_MAP
#else  // defined(AGPACK_USE_DEFINE_MAP)
#define AGPACK_DEFINE AGPACK_DEFINE_ARRAY
#define AGPACK_BASE AGPACK_BASE_ARRAY
#endif // defined(AGPACK_USE_DEFINE_MAP)


#include "agpack/v1/adaptor/define_decl.hpp"
#include "agpack/v2/adaptor/define_decl.hpp"
#include "agpack/v3/adaptor/define_decl.hpp"

#endif // AGPACK_DEFINE_DECL_HPP
