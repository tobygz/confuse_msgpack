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
# ifndef AGPACK_PREPROCESSOR_ARITHMETIC_DETAIL_DIV_BASE_HPP
# define AGPACK_PREPROCESSOR_ARITHMETIC_DETAIL_DIV_BASE_HPP
#
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/arithmetic/sub.hpp>
# include <agpack/preprocessor/comparison/less_equal.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_DIV_BASE */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_DIV_BASE(x, y) AGPACK_PP_WHILE(AGPACK_PP_DIV_BASE_P, AGPACK_PP_DIV_BASE_O, (0, x, y))
# else
#    define AGPACK_PP_DIV_BASE(x, y) AGPACK_PP_DIV_BASE_I(x, y)
#    define AGPACK_PP_DIV_BASE_I(x, y) AGPACK_PP_WHILE(AGPACK_PP_DIV_BASE_P, AGPACK_PP_DIV_BASE_O, (0, x, y))
# endif
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_DIV_BASE_P(d, rxy) AGPACK_PP_DIV_BASE_P_IM(d, AGPACK_PP_TUPLE_REM_3 rxy)
#    define AGPACK_PP_DIV_BASE_P_IM(d, im) AGPACK_PP_DIV_BASE_P_I(d, im)
# else
#    define AGPACK_PP_DIV_BASE_P(d, rxy) AGPACK_PP_DIV_BASE_P_I(d, AGPACK_PP_TUPLE_ELEM(3, 0, rxy), AGPACK_PP_TUPLE_ELEM(3, 1, rxy), AGPACK_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define AGPACK_PP_DIV_BASE_P_I(d, r, x, y) AGPACK_PP_LESS_EQUAL_D(d, y, x)
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_DIV_BASE_O(d, rxy) AGPACK_PP_DIV_BASE_O_IM(d, AGPACK_PP_TUPLE_REM_3 rxy)
#    define AGPACK_PP_DIV_BASE_O_IM(d, im) AGPACK_PP_DIV_BASE_O_I(d, im)
# else
#    define AGPACK_PP_DIV_BASE_O(d, rxy) AGPACK_PP_DIV_BASE_O_I(d, AGPACK_PP_TUPLE_ELEM(3, 0, rxy), AGPACK_PP_TUPLE_ELEM(3, 1, rxy), AGPACK_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define AGPACK_PP_DIV_BASE_O_I(d, r, x, y) (AGPACK_PP_INC(r), AGPACK_PP_SUB_D(d, x, y), y)
#
# /* AGPACK_PP_DIV_BASE_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_DIV_BASE_D(d, x, y) AGPACK_PP_WHILE_ ## d(AGPACK_PP_DIV_BASE_P, AGPACK_PP_DIV_BASE_O, (0, x, y))
# else
#    define AGPACK_PP_DIV_BASE_D(d, x, y) AGPACK_PP_DIV_BASE_D_I(d, x, y)
#    define AGPACK_PP_DIV_BASE_D_I(d, x, y) AGPACK_PP_WHILE_ ## d(AGPACK_PP_DIV_BASE_P, AGPACK_PP_DIV_BASE_O, (0, x, y))
# endif
#
# endif
