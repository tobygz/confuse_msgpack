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
# ifndef AGPACK_PREPROCESSOR_LIST_ENUM_HPP
# define AGPACK_PREPROCESSOR_LIST_ENUM_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/list/for_each_i.hpp>
# include <agpack/preprocessor/punctuation/comma_if.hpp>
#
# /* AGPACK_PP_LIST_ENUM */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_ENUM(list) AGPACK_PP_LIST_FOR_EACH_I(AGPACK_PP_LIST_ENUM_O, AGPACK_PP_NIL, list)
# else
#    define AGPACK_PP_LIST_ENUM(list) AGPACK_PP_LIST_ENUM_I(list)
#    define AGPACK_PP_LIST_ENUM_I(list) AGPACK_PP_LIST_FOR_EACH_I(AGPACK_PP_LIST_ENUM_O, AGPACK_PP_NIL, list)
# endif
#
# define AGPACK_PP_LIST_ENUM_O(r, _, i, elem) AGPACK_PP_COMMA_IF(i) elem
#
# /* AGPACK_PP_LIST_ENUM_R */
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_ENUM_R(r, list) AGPACK_PP_LIST_FOR_EACH_I_R(r, AGPACK_PP_LIST_ENUM_O, AGPACK_PP_NIL, list)
# else
#    define AGPACK_PP_LIST_ENUM_R(r, list) AGPACK_PP_LIST_ENUM_R_I(r, list)
#    define AGPACK_PP_LIST_ENUM_R_I(r, list) AGPACK_PP_LIST_FOR_EACH_I_R(r, AGPACK_PP_LIST_ENUM_O, AGPACK_PP_NIL, list)
# endif
#
# endif
