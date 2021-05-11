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
# ifndef AGPACK_PREPROCESSOR_LIST_REST_N_HPP
# define AGPACK_PREPROCESSOR_LIST_REST_N_HPP
#
# include <agpack/preprocessor/arithmetic/dec.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/list/adt.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
#
# /* AGPACK_PP_LIST_REST_N */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_REST_N(count, list) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE(AGPACK_PP_LIST_REST_N_P, AGPACK_PP_LIST_REST_N_O, (list, count)))
# else
#    define AGPACK_PP_LIST_REST_N(count, list) AGPACK_PP_LIST_REST_N_I(count, list)
#    define AGPACK_PP_LIST_REST_N_I(count, list) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE(AGPACK_PP_LIST_REST_N_P, AGPACK_PP_LIST_REST_N_O, (list, count)))
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_REST_N_P(d, lc) AGPACK_PP_TUPLE_ELEM(2, 1, lc)
# else
#    define AGPACK_PP_LIST_REST_N_P(d, lc) AGPACK_PP_LIST_REST_N_P_I lc
#    define AGPACK_PP_LIST_REST_N_P_I(list, count) count
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_REST_N_O(d, lc) (AGPACK_PP_LIST_REST(AGPACK_PP_TUPLE_ELEM(2, 0, lc)), AGPACK_PP_DEC(AGPACK_PP_TUPLE_ELEM(2, 1, lc)))
# else
#    define AGPACK_PP_LIST_REST_N_O(d, lc) AGPACK_PP_LIST_REST_N_O_I lc
#    define AGPACK_PP_LIST_REST_N_O_I(list, count) (AGPACK_PP_LIST_REST(list), AGPACK_PP_DEC(count))
# endif
#
# /* AGPACK_PP_LIST_REST_N_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_REST_N_D(d, count, list) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE_ ## d(AGPACK_PP_LIST_REST_N_P, AGPACK_PP_LIST_REST_N_O, (list, count)))
# else
#    define AGPACK_PP_LIST_REST_N_D(d, count, list) AGPACK_PP_LIST_REST_N_D_I(d, count, list)
#    define AGPACK_PP_LIST_REST_N_D_I(d, count, list) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE_ ## d(AGPACK_PP_LIST_REST_N_P, AGPACK_PP_LIST_REST_N_O, (list, count)))
# endif
#
# endif
