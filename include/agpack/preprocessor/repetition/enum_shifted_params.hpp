# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_REPETITION_ENUM_SHIFTED_PARAMS_HPP
# define AGPACK_PREPROCESSOR_REPETITION_ENUM_SHIFTED_PARAMS_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/punctuation/comma_if.hpp>
# include <agpack/preprocessor/repetition/repeat.hpp>
#
# /* AGPACK_PP_ENUM_SHIFTED_PARAMS */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ENUM_SHIFTED_PARAMS(count, param) AGPACK_PP_REPEAT(AGPACK_PP_DEC(count), AGPACK_PP_ENUM_SHIFTED_PARAMS_M, param)
# else
#    define AGPACK_PP_ENUM_SHIFTED_PARAMS(count, param) AGPACK_PP_ENUM_SHIFTED_PARAMS_I(count, param)
#    define AGPACK_PP_ENUM_SHIFTED_PARAMS_I(count, param) AGPACK_PP_REPEAT(AGPACK_PP_DEC(count), AGPACK_PP_ENUM_SHIFTED_PARAMS_M, param)
# endif
#
# define AGPACK_PP_ENUM_SHIFTED_PARAMS_M(z, n, param) AGPACK_PP_COMMA_IF(n) AGPACK_PP_CAT(param, AGPACK_PP_INC(n))
#
# /* AGPACK_PP_ENUM_SHIFTED_PARAMS_Z */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ENUM_SHIFTED_PARAMS_Z(z, count, param) AGPACK_PP_REPEAT_ ## z(AGPACK_PP_DEC(count), AGPACK_PP_ENUM_SHIFTED_PARAMS_M, param)
# else
#    define AGPACK_PP_ENUM_SHIFTED_PARAMS_Z(z, count, param) AGPACK_PP_ENUM_SHIFTED_PARAMS_Z_I(z, count, param)
#    define AGPACK_PP_ENUM_SHIFTED_PARAMS_Z_I(z, count, param) AGPACK_PP_REPEAT_ ## z(AGPACK_PP_DEC(count), AGPACK_PP_ENUM_SHIFTED_PARAMS_M, param)
# endif
#
# endif
