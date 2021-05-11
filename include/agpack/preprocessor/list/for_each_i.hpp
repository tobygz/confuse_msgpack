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
# ifndef AGPACK_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
# define AGPACK_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
#
# include <agpack/preprocessor/arithmetic/inc.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/list/adt.hpp>
# include <agpack/preprocessor/repetition/for.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_LIST_FOR_EACH_I */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG() && ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_LIST_FOR_EACH_I(macro, data, list) AGPACK_PP_FOR((macro, data, list, 0), AGPACK_PP_LIST_FOR_EACH_I_P, AGPACK_PP_LIST_FOR_EACH_I_O, AGPACK_PP_LIST_FOR_EACH_I_M)
# else
#    define AGPACK_PP_LIST_FOR_EACH_I(macro, data, list) AGPACK_PP_LIST_FOR_EACH_I_I(macro, data, list)
#    define AGPACK_PP_LIST_FOR_EACH_I_I(macro, data, list) AGPACK_PP_FOR((macro, data, list, 0), AGPACK_PP_LIST_FOR_EACH_I_P, AGPACK_PP_LIST_FOR_EACH_I_O, AGPACK_PP_LIST_FOR_EACH_I_M)
# endif
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_STRICT()
#    define AGPACK_PP_LIST_FOR_EACH_I_P(r, x) AGPACK_PP_LIST_FOR_EACH_I_P_D x
#    define AGPACK_PP_LIST_FOR_EACH_I_P_D(m, d, l, i) AGPACK_PP_LIST_IS_CONS(l)
# else
#    define AGPACK_PP_LIST_FOR_EACH_I_P(r, x) AGPACK_PP_LIST_IS_CONS(AGPACK_PP_TUPLE_ELEM(4, 2, x))
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_LIST_FOR_EACH_I_O(r, x) AGPACK_PP_LIST_FOR_EACH_I_O_D x
#    define AGPACK_PP_LIST_FOR_EACH_I_O_D(m, d, l, i) (m, d, AGPACK_PP_LIST_REST(l), AGPACK_PP_INC(i))
# else
#    define AGPACK_PP_LIST_FOR_EACH_I_O(r, x) (AGPACK_PP_TUPLE_ELEM(4, 0, x), AGPACK_PP_TUPLE_ELEM(4, 1, x), AGPACK_PP_LIST_REST(AGPACK_PP_TUPLE_ELEM(4, 2, x)), AGPACK_PP_INC(AGPACK_PP_TUPLE_ELEM(4, 3, x)))
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FOR_EACH_I_M(r, x) AGPACK_PP_LIST_FOR_EACH_I_M_D(r, AGPACK_PP_TUPLE_ELEM(4, 0, x), AGPACK_PP_TUPLE_ELEM(4, 1, x), AGPACK_PP_TUPLE_ELEM(4, 2, x), AGPACK_PP_TUPLE_ELEM(4, 3, x))
# else
#    define AGPACK_PP_LIST_FOR_EACH_I_M(r, x) AGPACK_PP_LIST_FOR_EACH_I_M_I(r, AGPACK_PP_TUPLE_REM_4 x)
#    define AGPACK_PP_LIST_FOR_EACH_I_M_I(r, x_e) AGPACK_PP_LIST_FOR_EACH_I_M_D(r, x_e)
# endif
#
# define AGPACK_PP_LIST_FOR_EACH_I_M_D(r, m, d, l, i) m(r, d, i, AGPACK_PP_LIST_FIRST(l))
#
# /* AGPACK_PP_LIST_FOR_EACH_I_R */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FOR_EACH_I_R(r, macro, data, list) AGPACK_PP_FOR_ ## r((macro, data, list, 0), AGPACK_PP_LIST_FOR_EACH_I_P, AGPACK_PP_LIST_FOR_EACH_I_O, AGPACK_PP_LIST_FOR_EACH_I_M)
# else
#    define AGPACK_PP_LIST_FOR_EACH_I_R(r, macro, data, list) AGPACK_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list)
#    define AGPACK_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list) AGPACK_PP_FOR_ ## r((macro, data, list, 0), AGPACK_PP_LIST_FOR_EACH_I_P, AGPACK_PP_LIST_FOR_EACH_I_O, AGPACK_PP_LIST_FOR_EACH_I_M)
# endif
#
# endif
