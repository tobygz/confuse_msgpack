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
# ifndef AGPACK_PREPROCESSOR_LIST_APPEND_HPP
# define AGPACK_PREPROCESSOR_LIST_APPEND_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/list/fold_right.hpp>
#
# /* AGPACK_PP_LIST_APPEND */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_APPEND(a, b) AGPACK_PP_LIST_FOLD_RIGHT(AGPACK_PP_LIST_APPEND_O, b, a)
# else
#    define AGPACK_PP_LIST_APPEND(a, b) AGPACK_PP_LIST_APPEND_I(a, b)
#    define AGPACK_PP_LIST_APPEND_I(a, b) AGPACK_PP_LIST_FOLD_RIGHT(AGPACK_PP_LIST_APPEND_O, b, a)
# endif
#
# define AGPACK_PP_LIST_APPEND_O(d, s, x) (x, s)
#
# /* AGPACK_PP_LIST_APPEND_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_APPEND_D(d, a, b) AGPACK_PP_LIST_FOLD_RIGHT_ ## d(AGPACK_PP_LIST_APPEND_O, b, a)
# else
#    define AGPACK_PP_LIST_APPEND_D(d, a, b) AGPACK_PP_LIST_APPEND_D_I(d, a, b)
#    define AGPACK_PP_LIST_APPEND_D_I(d, a, b) AGPACK_PP_LIST_FOLD_RIGHT_ ## d(AGPACK_PP_LIST_APPEND_O, b, a)
# endif
#
# endif
