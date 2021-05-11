# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_REPETITION_ENUM_TRAILING_PARAMS_HPP
# define AGPACK_PREPROCESSOR_REPETITION_ENUM_TRAILING_PARAMS_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/repetition/repeat.hpp>
#
# /* AGPACK_PP_ENUM_TRAILING_PARAMS */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ENUM_TRAILING_PARAMS(count, param) AGPACK_PP_REPEAT(count, AGPACK_PP_ENUM_TRAILING_PARAMS_M, param)
# else
#    define AGPACK_PP_ENUM_TRAILING_PARAMS(count, param) AGPACK_PP_ENUM_TRAILING_PARAMS_I(count, param)
#    define AGPACK_PP_ENUM_TRAILING_PARAMS_I(count, param) AGPACK_PP_REPEAT(count, AGPACK_PP_ENUM_TRAILING_PARAMS_M, param)
# endif
#
# define AGPACK_PP_ENUM_TRAILING_PARAMS_M(z, n, param) , param ## n
#
# /* AGPACK_PP_ENUM_TRAILING_PARAMS_Z */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ENUM_TRAILING_PARAMS_Z(z, count, param) AGPACK_PP_REPEAT_ ## z(count, AGPACK_PP_ENUM_TRAILING_PARAMS_M, param)
# else
#    define AGPACK_PP_ENUM_TRAILING_PARAMS_Z(z, count, param) AGPACK_PP_ENUM_TRAILING_PARAMS_Z_I(z, count, param)
#    define AGPACK_PP_ENUM_TRAILING_PARAMS_Z_I(z, count, param) AGPACK_PP_REPEAT_ ## z(count, AGPACK_PP_ENUM_TRAILING_PARAMS_M, param)
# endif
#
# endif
