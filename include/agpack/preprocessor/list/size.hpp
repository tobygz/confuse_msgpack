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
# ifndef AGPACK_PREPROCESSOR_LIST_SIZE_HPP
# define AGPACK_PREPROCESSOR_LIST_SIZE_HPP
#
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/control/while.hpp>
# include <agpack/preprocessor/list/adt.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_LIST_SIZE */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_SIZE(list) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE(AGPACK_PP_LIST_SIZE_P, AGPACK_PP_LIST_SIZE_O, (0, list)))
# else
#    define AGPACK_PP_LIST_SIZE(list) AGPACK_PP_LIST_SIZE_I(list)
#    define AGPACK_PP_LIST_SIZE_I(list) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE(AGPACK_PP_LIST_SIZE_P, AGPACK_PP_LIST_SIZE_O, (0, list)))
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_SIZE_P(d, rl) AGPACK_PP_LIST_IS_CONS(AGPACK_PP_TUPLE_ELEM(2, 1, rl))
# else
#    define AGPACK_PP_LIST_SIZE_P(d, rl) AGPACK_PP_LIST_SIZE_P_I(AGPACK_PP_TUPLE_REM_2 rl)
#    define AGPACK_PP_LIST_SIZE_P_I(im) AGPACK_PP_LIST_SIZE_P_II(im)
#    define AGPACK_PP_LIST_SIZE_P_II(r, l) AGPACK_PP_LIST_IS_CONS(l)
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_SIZE_O(d, rl) (AGPACK_PP_INC(AGPACK_PP_TUPLE_ELEM(2, 0, rl)), AGPACK_PP_LIST_REST(AGPACK_PP_TUPLE_ELEM(2, 1, rl)))
# else
#    define AGPACK_PP_LIST_SIZE_O(d, rl) AGPACK_PP_LIST_SIZE_O_I(AGPACK_PP_TUPLE_REM_2 rl)
#    define AGPACK_PP_LIST_SIZE_O_I(im) AGPACK_PP_LIST_SIZE_O_II(im)
#    define AGPACK_PP_LIST_SIZE_O_II(r, l) (AGPACK_PP_INC(r), AGPACK_PP_LIST_REST(l))
# endif
#
# /* AGPACK_PP_LIST_SIZE_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_SIZE_D(d, list) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE_ ## d(AGPACK_PP_LIST_SIZE_P, AGPACK_PP_LIST_SIZE_O, (0, list)))
# else
#    define AGPACK_PP_LIST_SIZE_D(d, list) AGPACK_PP_LIST_SIZE_D_I(d, list)
#    define AGPACK_PP_LIST_SIZE_D_I(d, list) AGPACK_PP_TUPLE_ELEM(2, 0, AGPACK_PP_WHILE_ ## d(AGPACK_PP_LIST_SIZE_P, AGPACK_PP_LIST_SIZE_O, (0, list)))
# endif
#
# endif
