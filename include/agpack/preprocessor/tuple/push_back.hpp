# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2013.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef AGPACK_PREPROCESSOR_TUPLE_PUSH_BACK_HPP
# define AGPACK_PREPROCESSOR_TUPLE_PUSH_BACK_HPP
#
# include <agpack/preprocessor/config/config.hpp>
#
# if AGPACK_PP_VARIADICS
#
# include <agpack/preprocessor/array/push_back.hpp>
# include <agpack/preprocessor/array/to_tuple.hpp>
# include <agpack/preprocessor/tuple/to_array.hpp>
#
# /* AGPACK_PP_TUPLE_PUSH_BACK */
#
# define AGPACK_PP_TUPLE_PUSH_BACK(tuple, elem) \
	AGPACK_PP_ARRAY_TO_TUPLE(AGPACK_PP_ARRAY_PUSH_BACK(AGPACK_PP_TUPLE_TO_ARRAY(tuple), elem)) \
/**/
#
# endif // AGPACK_PP_VARIADICS
#
# endif // AGPACK_PREPROCESSOR_TUPLE_PUSH_BACK_HPP
