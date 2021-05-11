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
# ifndef AGPACK_PREPROCESSOR_LIST_FIRST_N_HPP
# define AGPACK_PREPROCESSOR_LIST_FIRST_N_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/list/adt.hpp>
# include <agpack/preprocessor/list/reverse.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_LIST_FIRST_N */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FIRST_N(count, list) AGPACK_PP_LIST_REVERSE(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_WHILE(AGPACK_PP_LIST_FIRST_N_P, AGPACK_PP_LIST_FIRST_N_O, (count, list, AGPACK_PP_NIL))))
# else
#    define AGPACK_PP_LIST_FIRST_N(count, list) AGPACK_PP_LIST_FIRST_N_I(count, list)
#    define AGPACK_PP_LIST_FIRST_N_I(count, list) AGPACK_PP_LIST_REVERSE(AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_WHILE(AGPACK_PP_LIST_FIRST_N_P, AGPACK_PP_LIST_FIRST_N_O, (count, list, AGPACK_PP_NIL))))
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FIRST_N_P(d, data) AGPACK_PP_TUPLE_ELEM(3, 0, data)
# else
#    define AGPACK_PP_LIST_FIRST_N_P(d, data) AGPACK_PP_LIST_FIRST_N_P_I data
#    define AGPACK_PP_LIST_FIRST_N_P_I(c, l, nl) c
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_LIST_FIRST_N_O(d, data) AGPACK_PP_LIST_FIRST_N_O_D data
# else
#    define AGPACK_PP_LIST_FIRST_N_O(d, data) AGPACK_PP_LIST_FIRST_N_O_D(AGPACK_PP_TUPLE_ELEM(3, 0, data), AGPACK_PP_TUPLE_ELEM(3, 1, data), AGPACK_PP_TUPLE_ELEM(3, 2, data))
# endif
#
# define AGPACK_PP_LIST_FIRST_N_O_D(c, l, nl) (AGPACK_PP_DEC(c), AGPACK_PP_LIST_REST(l), (AGPACK_PP_LIST_FIRST(l), nl))
#
# /* AGPACK_PP_LIST_FIRST_N_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FIRST_N_D(d, count, list) AGPACK_PP_LIST_REVERSE_D(d, AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_WHILE_ ## d(AGPACK_PP_LIST_FIRST_N_P, AGPACK_PP_LIST_FIRST_N_O, (count, list, AGPACK_PP_NIL))))
# else
#    define AGPACK_PP_LIST_FIRST_N_D(d, count, list) AGPACK_PP_LIST_FIRST_N_D_I(d, count, list)
#    define AGPACK_PP_LIST_FIRST_N_D_I(d, count, list) AGPACK_PP_LIST_REVERSE_D(d, AGPACK_PP_TUPLE_ELEM(3, 2, AGPACK_PP_WHILE_ ## d(AGPACK_PP_LIST_FIRST_N_P, AGPACK_PP_LIST_FIRST_N_O, (count, list, AGPACK_PP_NIL))))
# endif
#
# endif
