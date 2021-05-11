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
# ifndef AGPACK_PREPROCESSOR_COMPARISON_LESS_HPP
# define AGPACK_PREPROCESSOR_COMPARISON_LESS_HPP
#
# include <agpack/preprocessor/comparison/less_equal.hpp>
# include <agpack/preprocessor/comparison/not_equal.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/iif.hpp>
# include <agpack/preprocessor/logical/bitand.hpp>
# include <agpack/preprocessor/tuple/eat.hpp>
#
# /* AGPACK_PP_LESS */
#
# if AGPACK_PP_CONFIG_FLAGS() & (AGPACK_PP_CONFIG_MWCC() | AGPACK_PP_CONFIG_DMC())
#    define AGPACK_PP_LESS(x, y) AGPACK_PP_BITAND(AGPACK_PP_NOT_EQUAL(x, y), AGPACK_PP_LESS_EQUAL(x, y))
# elif ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LESS(x, y) AGPACK_PP_IIF(AGPACK_PP_NOT_EQUAL(x, y), AGPACK_PP_LESS_EQUAL, 0 AGPACK_PP_TUPLE_EAT_2)(x, y)
# else
#    define AGPACK_PP_LESS(x, y) AGPACK_PP_LESS_I(x, y)
#    define AGPACK_PP_LESS_I(x, y) AGPACK_PP_IIF(AGPACK_PP_NOT_EQUAL(x, y), AGPACK_PP_LESS_EQUAL, 0 AGPACK_PP_TUPLE_EAT_2)(x, y)
# endif
#
# /* AGPACK_PP_LESS_D */
#
# if AGPACK_PP_CONFIG_FLAGS() & (AGPACK_PP_CONFIG_MWCC() | AGPACK_PP_CONFIG_DMC())
#    define AGPACK_PP_LESS_D(d, x, y) AGPACK_PP_BITAND(AGPACK_PP_NOT_EQUAL(x, y), AGPACK_PP_LESS_EQUAL_D(d, x, y))
# elif ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LESS_D(d, x, y) AGPACK_PP_IIF(AGPACK_PP_NOT_EQUAL(x, y), AGPACK_PP_LESS_EQUAL_D, 0 AGPACK_PP_TUPLE_EAT_3)(d, x, y)
# else
#    define AGPACK_PP_LESS_D(d, x, y) AGPACK_PP_LESS_D_I(d, x, y)
#    define AGPACK_PP_LESS_D_I(d, x, y) AGPACK_PP_IIF(AGPACK_PP_NOT_EQUAL(x, y), AGPACK_PP_LESS_EQUAL_D, 0 AGPACK_PP_TUPLE_EAT_3)(d, x, y)
# endif
#
# endif
