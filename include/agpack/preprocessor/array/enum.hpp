# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_ARRAY_ENUM_HPP
# define AGPACK_PREPROCESSOR_ARRAY_ENUM_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_ARRAY_ENUM */
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_ARRAY_ENUM(array) AGPACK_PP_ARRAY_ENUM_I(AGPACK_PP_TUPLE_REM_CTOR, array)
#    define AGPACK_PP_ARRAY_ENUM_I(m, args) AGPACK_PP_ARRAY_ENUM_II(m, args)
#    define AGPACK_PP_ARRAY_ENUM_II(m, args) AGPACK_PP_CAT(m ## args,)
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_ARRAY_ENUM(array) AGPACK_PP_ARRAY_ENUM_I(array)
#    define AGPACK_PP_ARRAY_ENUM_I(array) AGPACK_PP_TUPLE_REM_CTOR ## array
# else
#    define AGPACK_PP_ARRAY_ENUM(array) AGPACK_PP_TUPLE_REM_CTOR array
# endif
#
# endif
