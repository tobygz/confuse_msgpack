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
# ifndef AGPACK_PREPROCESSOR_LIST_AT_HPP
# define AGPACK_PREPROCESSOR_LIST_AT_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/list/adt.hpp>
# include <agpack/preprocessor/list/rest_n.hpp>
#
# /* AGPACK_PP_LIST_AT */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_AT(list, index) AGPACK_PP_LIST_FIRST(AGPACK_PP_LIST_REST_N(index, list))
# else
#    define AGPACK_PP_LIST_AT(list, index) AGPACK_PP_LIST_AT_I(list, index)
#    define AGPACK_PP_LIST_AT_I(list, index) AGPACK_PP_LIST_FIRST(AGPACK_PP_LIST_REST_N(index, list))
# endif
#
# /* AGPACK_PP_LIST_AT_D */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_AT_D(d, list, index) AGPACK_PP_LIST_FIRST(AGPACK_PP_LIST_REST_N_D(d, index, list))
# else
#    define AGPACK_PP_LIST_AT_D(d, list, index) AGPACK_PP_LIST_AT_D_I(d, list, index)
#    define AGPACK_PP_LIST_AT_D_I(d, list, index) AGPACK_PP_LIST_FIRST(AGPACK_PP_LIST_REST_N_D(d, index, list))
# endif
#
# endif
