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
# ifndef AGPACK_PREPROCESSOR_ARITHMETIC_SUB_HPP
# define AGPACK_PREPROCESSOR_ARITHMETIC_SUB_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_SUB */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SUB(x, y) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE(AGPACK_PP_SUB_P, AGPACK_PP_SUB_O, (x, y)))
# else
#    define AGPACK_PP_SUB(x, y) AGPACK_PP_SUB_I(x, y)
#    define AGPACK_PP_SUB_I(x, y) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE(AGPACK_PP_SUB_P, AGPACK_PP_SUB_O, (x, y)))
# endif
#
# define AGPACK_PP_SUB_P(d, xy) AGPACK_PP_TUPLE_ELEM(2, 1, xy)
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_SUB_O(d, xy) AGPACK_PP_SUB_O_I xy
# else
#    define AGPACK_PP_SUB_O(d, xy) AGPACK_PP_SUB_O_I(AGPACK_PP_TUPLE_ELEM(2, 0, xy), AGPACK_PP_TUPLE_ELEM(2, 1, xy))
# endif
#
# define AGPACK_PP_SUB_O_I(x, y) (AGPACK_PP_DEC(x), AGPACK_PP_DEC(y))
#
# /* AGPACK_PP_SUB_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_SUB_D(d, x, y) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE_ ## d(AGPACK_PP_SUB_P, AGPACK_PP_SUB_O, (x, y)))
# else
#    define AGPACK_PP_SUB_D(d, x, y) AGPACK_PP_SUB_D_I(d, x, y)
#    define AGPACK_PP_SUB_D_I(d, x, y) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE_ ## d(AGPACK_PP_SUB_P, AGPACK_PP_SUB_O, (x, y)))
# endif
#
# endif
