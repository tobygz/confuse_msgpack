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
# ifndef AGPACK_PREPROCESSOR_LIST_TO_TUPLE_HPP
# define AGPACK_PREPROCESSOR_LIST_TO_TUPLE_HPP
#
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/list/enum.hpp>
# include <agpack/preprocessor/control/iif.hpp>
#
# /* AGPACK_PP_LIST_TO_TUPLE */
#
# define AGPACK_PP_LIST_TO_TUPLE(list) \
	AGPACK_PP_IIF \
		( \
		AGPACK_PP_LIST_IS_NIL(list), \
		AGPACK_PP_LIST_TO_TUPLE_EMPTY, \
		AGPACK_PP_LIST_TO_TUPLE_DO \
		) \
	(list) \
/**/
# define AGPACK_PP_LIST_TO_TUPLE_EMPTY(list)
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_TO_TUPLE_DO(list) (AGPACK_PP_LIST_ENUM(list))
# else
#    define AGPACK_PP_LIST_TO_TUPLE_DO(list) AGPACK_PP_LIST_TO_TUPLE_I(list)
#    define AGPACK_PP_LIST_TO_TUPLE_I(list) (AGPACK_PP_LIST_ENUM(list))
# endif
#
# /* AGPACK_PP_LIST_TO_TUPLE_R */
#
# define AGPACK_PP_LIST_TO_TUPLE_R(r, list) \
	AGPACK_PP_IIF \
		( \
		AGPACK_PP_LIST_IS_NIL(list), \
		AGPACK_PP_LIST_TO_TUPLE_R_EMPTY, \
		AGPACK_PP_LIST_TO_TUPLE_R_DO \
		) \
	(r, list) \
/**/
# define AGPACK_PP_LIST_TO_TUPLE_R_EMPTY(r,list)
#
# if ~AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_EDG()
#    define AGPACK_PP_LIST_TO_TUPLE_R_DO(r, list) (AGPACK_PP_LIST_ENUM_R(r, list))
# else
#    define AGPACK_PP_LIST_TO_TUPLE_R_DO(r, list) AGPACK_PP_LIST_TO_TUPLE_R_I(r, list)
#    define AGPACK_PP_LIST_TO_TUPLE_R_I(r, list) (AGPACK_PP_LIST_ENUM_R(r, list))
# endif
#
# endif
