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
# ifndef AGPACK_PREPROCESSOR_LIST_FOR_EACH_HPP
# define AGPACK_PREPROCESSOR_LIST_FOR_EACH_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/list/for_each_i.hpp>
# include <agpack/preprocessor/tuple/elem.hpp>
# include <agpack/preprocessor/tuple/rem.hpp>
#
# /* AGPACK_PP_LIST_FOR_EACH */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FOR_EACH(macro, data, list) AGPACK_PP_LIST_FOR_EACH_I(AGPACK_PP_LIST_FOR_EACH_O, (macro, data), list)
# else
#    define AGPACK_PP_LIST_FOR_EACH(macro, data, list) AGPACK_PP_LIST_FOR_EACH_X(macro, data, list)
#    define AGPACK_PP_LIST_FOR_EACH_X(macro, data, list) AGPACK_PP_LIST_FOR_EACH_I(AGPACK_PP_LIST_FOR_EACH_O, (macro, data), list)
# endif
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FOR_EACH_O(r, md, i, elem) AGPACK_PP_LIST_FOR_EACH_O_D(r, AGPACK_PP_TUPLE_ELEM(2, 0, md), AGPACK_PP_TUPLE_ELEM(2, 1, md), elem)
# else
#    define AGPACK_PP_LIST_FOR_EACH_O(r, md, i, elem) AGPACK_PP_LIST_FOR_EACH_O_I(r, AGPACK_PP_TUPLE_REM_2 md, elem)
#    define AGPACK_PP_LIST_FOR_EACH_O_I(r, im, elem) AGPACK_PP_LIST_FOR_EACH_O_D(r, im, elem)
# endif
#
# define AGPACK_PP_LIST_FOR_EACH_O_D(r, m, d, elem) m(r, d, elem)
#
# /* AGPACK_PP_LIST_FOR_EACH_R */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_FOR_EACH_R(r, macro, data, list) AGPACK_PP_LIST_FOR_EACH_I_R(r, AGPACK_PP_LIST_FOR_EACH_O, (macro, data), list)
# else
#    define AGPACK_PP_LIST_FOR_EACH_R(r, macro, data, list) AGPACK_PP_LIST_FOR_EACH_R_X(r, macro, data, list)
#    define AGPACK_PP_LIST_FOR_EACH_R_X(r, macro, data, list) AGPACK_PP_LIST_FOR_EACH_I_R(r, AGPACK_PP_LIST_FOR_EACH_O, (macro, data), list)
# endif
#
# endif
