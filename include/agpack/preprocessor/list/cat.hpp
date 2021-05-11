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
# ifndef AGPACK_PREPROCESSOR_LIST_CAT_HPP
# define AGPACK_PREPROCESSOR_LIST_CAT_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/list/adt.hpp>
# include <agpack/preprocessor/list/fold_left.hpp>
#
# /* AGPACK_PP_LIST_CAT */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_CAT(list) AGPACK_PP_LIST_FOLD_LEFT(AGPACK_PP_LIST_CAT_O, AGPACK_PP_LIST_FIRST(list), AGPACK_PP_LIST_REST(list))
# else
#    define AGPACK_PP_LIST_CAT(list) AGPACK_PP_LIST_CAT_I(list)
#    define AGPACK_PP_LIST_CAT_I(list) AGPACK_PP_LIST_FOLD_LEFT(AGPACK_PP_LIST_CAT_O, AGPACK_PP_LIST_FIRST(list), AGPACK_PP_LIST_REST(list))
# endif
#
# define AGPACK_PP_LIST_CAT_O(d, s, x) AGPACK_PP_CAT(s, x)
#
# /* AGPACK_PP_LIST_CAT_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_CAT_D(d, list) AGPACK_PP_LIST_FOLD_LEFT_ ## d(AGPACK_PP_LIST_CAT_O, AGPACK_PP_LIST_FIRST(list), AGPACK_PP_LIST_REST(list))
# else
#    define AGPACK_PP_LIST_CAT_D(d, list) AGPACK_PP_LIST_CAT_D_I(d, list)
#    define AGPACK_PP_LIST_CAT_D_I(d, list) AGPACK_PP_LIST_FOLD_LEFT_ ## d(AGPACK_PP_LIST_CAT_O, AGPACK_PP_LIST_FIRST(list), AGPACK_PP_LIST_REST(list))
# endif
#
# endif
