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
# ifndef AGPACK_PREPROCESSOR_REPETITION_ENUM_BINARY_PARAMS_HPP
# define AGPACK_PREPROCESSOR_REPETITION_ENUM_BINARY_PARAMS_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/punctuation/comma_if.hpp>
# include <agpack/preprocessor/repetition/repeat.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_ENUM_BINARY_PARAMS */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ENUM_BINARY_PARAMS(count, p1, p2) AGPACK_PP_REPEAT(count, AGPACK_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# else
#    define AGPACK_PP_ENUM_BINARY_PARAMS(count, p1, p2) AGPACK_PP_ENUM_BINARY_PARAMS_I(count, p1, p2)
#    define AGPACK_PP_ENUM_BINARY_PARAMS_I(count, p1, p2) AGPACK_PP_REPEAT(count, AGPACK_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# endif
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_ENUM_BINARY_PARAMS_M(z, n, pp) AGPACK_PP_ENUM_BINARY_PARAMS_M_IM(z, n, AGPACK_PP_TUPLE_REM_2 pp)
#    define AGPACK_PP_ENUM_BINARY_PARAMS_M_IM(z, n, im) AGPACK_PP_ENUM_BINARY_PARAMS_M_I(z, n, im)
# else
#    define AGPACK_PP_ENUM_BINARY_PARAMS_M(z, n, pp) AGPACK_PP_ENUM_BINARY_PARAMS_M_I(z, n, AGPACK_PP_TUPLE_ELEM(2, 0, pp), AGPACK_PP_TUPLE_ELEM(2, 1, pp))
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_ENUM_BINARY_PARAMS_M_I(z, n, p1, p2) AGPACK_PP_ENUM_BINARY_PARAMS_M_II(z, n, p1, p2)
#    define AGPACK_PP_ENUM_BINARY_PARAMS_M_II(z, n, p1, p2) AGPACK_PP_COMMA_IF(n) p1 ## n p2 ## n
# else
#    define AGPACK_PP_ENUM_BINARY_PARAMS_M_I(z, n, p1, p2) AGPACK_PP_COMMA_IF(n) AGPACK_PP_CAT(p1, n) AGPACK_PP_CAT(p2, n)
# endif
#
# /* AGPACK_PP_ENUM_BINARY_PARAMS_Z */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_ENUM_BINARY_PARAMS_Z(z, count, p1, p2) AGPACK_PP_REPEAT_ ## z(count, AGPACK_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# else
#    define AGPACK_PP_ENUM_BINARY_PARAMS_Z(z, count, p1, p2) AGPACK_PP_ENUM_BINARY_PARAMS_Z_I(z, count, p1, p2)
#    define AGPACK_PP_ENUM_BINARY_PARAMS_Z_I(z, count, p1, p2) AGPACK_PP_REPEAT_ ## z(count, AGPACK_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# endif
#
# endif
