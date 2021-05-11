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
# ifndef AGPACK_PREPROCESSOR_ARRAY_TO_TUPLE_HPP
# define AGPACK_PREPROCESSOR_ARRAY_TO_TUPLE_HPP
#
# include <agpack/preprocessor/array/data.hpp>
# include <agpack/preprocessor/array/size.hpp>
# include <agpack/preprocessor/control/if.hpp>
#
# /* AGPACK_PP_ARRAY_TO_TUPLE */
#
#    define AGPACK_PP_ARRAY_TO_TUPLE(array) \
		AGPACK_PP_IF \
			( \
			AGPACK_PP_ARRAY_SIZE(array), \
			AGPACK_PP_ARRAY_DATA, \
			AGPACK_PP_ARRAY_TO_TUPLE_EMPTY \
			) \
		(array) \
/**/
#    define AGPACK_PP_ARRAY_TO_TUPLE_EMPTY(array)
#
# endif
