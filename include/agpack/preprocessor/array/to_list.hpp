# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_ARRAY_TO_LIST_HPP
# define AGPACK_PREPROCESSOR_ARRAY_TO_LIST_HPP
#
# include <agpack/preprocessor/cat.hpp>
# include <agpack/preprocessor/config/config.hpp>
# include <agpack/preprocessor/array/size.hpp>
# include <agpack/preprocessor/control/if.hpp>
# include <agpack/preprocessor/tuple/to_list.hpp>
#
# /* AGPACK_PP_ARRAY_TO_LIST */
#
#    define AGPACK_PP_ARRAY_TO_LIST(array) \
		AGPACK_PP_IF \
			( \
			AGPACK_PP_ARRAY_SIZE(array), \
			AGPACK_PP_ARRAY_TO_LIST_DO, \
			AGPACK_PP_ARRAY_TO_LIST_EMPTY \
			) \
		(array) \
/**/
#
#    define AGPACK_PP_ARRAY_TO_LIST_EMPTY(array) AGPACK_PP_NIL
#
# if AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MSVC()
#    define AGPACK_PP_ARRAY_TO_LIST_DO(array) AGPACK_PP_ARRAY_TO_LIST_I(AGPACK_PP_TUPLE_TO_LIST, array)
#    define AGPACK_PP_ARRAY_TO_LIST_I(m, args) AGPACK_PP_ARRAY_TO_LIST_II(m, args)
#    define AGPACK_PP_ARRAY_TO_LIST_II(m, args) AGPACK_PP_CAT(m ## args,)
# elif AGPACK_PP_CONFIG_FLAGS() & AGPACK_PP_CONFIG_MWCC()
#    define AGPACK_PP_ARRAY_TO_LIST_DO(array) AGPACK_PP_ARRAY_TO_LIST_I(array)
#    define AGPACK_PP_ARRAY_TO_LIST_I(array) AGPACK_PP_TUPLE_TO_LIST ## array
# else
#    define AGPACK_PP_ARRAY_TO_LIST_DO(array) AGPACK_PP_TUPLE_TO_LIST array
# endif
#
# endif
